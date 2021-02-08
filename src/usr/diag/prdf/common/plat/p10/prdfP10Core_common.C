/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Core_common.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// Framework includes
#include <prdfPluginDef.H>
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>
#include <prdfP10CoreDataBundle.H>
#include <prdfP10CoreExtraSig.H>
#include <prdfPluginMap.H>
#include <prdfErrlUtil.H>
#include <UtilHash.H> // for Util::hashString
#ifdef __HOSTBOOT_RUNTIME
  #include <hwas/common/hwas.H>
  #include <hwas/common/deconfigGard.H>
#endif

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace p10_core
{

/**
 * @brief  Plugin that initializes the Core data bundle.
 * @param  i_coreChip A core chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_coreChip )
{
    i_coreChip->getDataBundle() = new P10CoreDataBundle( i_coreChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_core, Initialize );

void checkCoreRePresent( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc )
{
    int32_t l_rc = SUCCESS;
    SCAN_COMM_REGISTER_CLASS *coreWOF =
             i_chip->getRegister("EQ_CORE_FIR_WOF");
    SCAN_COMM_REGISTER_CLASS * coreMask =
             i_chip->getRegister("EQ_CORE_FIR_MASK");
    SCAN_COMM_REGISTER_CLASS * coreAct0 =
             i_chip->getRegister("EQ_CORE_FIR_ACT0");
    SCAN_COMM_REGISTER_CLASS * coreAct1 =
             i_chip->getRegister("EQ_CORE_FIR_ACT1");

    l_rc  = coreWOF->Read();
    l_rc |= coreMask->Read();
    l_rc |= coreAct0->Read();
    l_rc |= coreAct1->Read();
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[EC::checkCoreRePresent] HUID: 0x%08x failed to read"
                  "CORE FIR", i_chip->GetId());
        return;
    }

    uint64_t coreWOFbits  =  coreWOF->GetBitFieldJustified(0, 64);
    uint64_t coreMaskbits = coreMask->GetBitFieldJustified(0, 64);
    uint64_t coreAct0bits = coreAct0->GetBitFieldJustified(0, 64);
    uint64_t coreAct1bits = coreAct1->GetBitFieldJustified(0, 64);

    // If do not have a valid recoverable bit in COREFIR_WOF, we need to
    // switch analysis to look at core checkstop bits
    if ( !( coreWOFbits  & ~coreMaskbits & ~coreAct0bits & coreAct1bits) )
    {
        io_sc.service_data->setSecondaryAttnType(UNIT_CS);
    }
}


/**
 * @brief Determine if there is a core unit checkstop and perform appropriate
 * action.
 *
 * 1) Set error to predictive / at threshold.
 * 2) Wait for PHYP to evacuate core.
 * 3) Terminate if PHYP doesn't evacuate.
 * 4) If we have UCS without RE, switch attn type to analyze UCS
 * @param i_chip Core chip.
 * @param io_sc Step Code data struct
 * @return PRD return code
 */
int32_t CheckCoreCheckstop( ExtensibleChip * i_chip,
                            STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Ec::CheckCoreCheckstop] "
    int32_t l_rc = SUCCESS;
    static const uint32_t CORECS_SECONDS_TO_SLEEP = 10;

    do
    {
        // Skip if we're already at core checkstop in SDC.
        if (io_sc.service_data->isProcCoreCS()) break;

        // Read core checkstop bit in chiplet RER.
        // Check EQ_CHIPLET_UCS_FIR to see if we have a Core UNIT_CS
        ExtensibleChip * eq = getConnectedParent( i_chip, TYPE_EQ );

        SCAN_COMM_REGISTER_CLASS * fir = eq->getRegister("EQ_CHIPLET_UCS_FIR");
        l_rc = fir->ForceRead();
        if ( SUCCESS != l_rc ) break;

        SCAN_COMM_REGISTER_CLASS * mask =
            eq->getRegister( "EQ_CHIPLET_UCS_FIR_MASK" );
        l_rc = mask->Read();
        if ( SUCCESS != l_rc ) break;

        // Just check the bit for the core we are on.
        uint8_t corePos = i_chip->getPos() % MAX_EC_PER_EQ; // 0-3

        // Break if the bit isn't set in the FIR or if it's masked.
        if ( !fir->IsBitSet(5+corePos) || mask->IsBitSet(5+corePos) ) break;

        // We must be at core checkstop.
        io_sc.service_data->setProcCoreCS();
        io_sc.service_data->SetThresholdMaskId(0);

        // Check if we need to switch attn type to analyze Unit checkstop
        checkCoreRePresent(i_chip, io_sc);

        if( CHECK_STOP == io_sc.service_data->getPrimaryAttnType() )
        {
            // if both Unit CS and Platform CS occur together, PHYP will not
            // respond to the core evacuation hand-shaking. Don't wait for them
            // and don't collect SH dump. This specifically targets a case
            //  where COREFIR bit 54 and 55 assert together.
            break;
        }

        SCAN_COMM_REGISTER_CLASS *coreHMEER
            = i_chip->getRegister("HOMER_ENABLE");
        l_rc = coreHMEER->Read();
        if (SUCCESS != l_rc) break;

        // Check if PHYP has enabled core checkstop (HMEER[0]).
        if (!coreHMEER->IsBitSet(0))
        {
            // Core checkstop not enabled, terminate.
            io_sc.service_data->setFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, be sure to get SW content.
            io_sc.service_data->SetDump(CONTENT_SW, i_chip->getTrgt());
            break;
        }

        // Wait for PHYP evacuation by checking SPATTN register.
        SCAN_COMM_REGISTER_CLASS * coreSPAttn
            = i_chip->getRegister("SPEC_ATTN_REASON");

        bool spAttnCleared = false;
        uint32_t secondsToSleep = CORECS_SECONDS_TO_SLEEP;

        do
        {
            // Don't sleep on first time through.
            if (secondsToSleep != CORECS_SECONDS_TO_SLEEP)
            {
                PlatServices::milliSleep(1,0); // 1 second
            }
            secondsToSleep--;

            l_rc = coreSPAttn->ForceRead();
            if (SUCCESS == l_rc)
            {
                if (!coreSPAttn->IsBitSet(2))
                {
                    spAttnCleared = true;
                }
            }
        } while ((secondsToSleep != 0) && (!spAttnCleared));

        if (SUCCESS == l_rc && !spAttnCleared)
        {
            // If we waited and never cleared, terminate machine.
            io_sc.service_data->setFlag( ServiceDataCollector::TERMINATE );

            // PHYP was unresponsive, so get SW content.
            io_sc.service_data->SetDump(CONTENT_SW, i_chip->getTrgt());
        }
    } while(0);
    return SUCCESS;
    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE( p10_core, CheckCoreCheckstop );

/**
 * @brief  This is a special plugin where we intentionally want to return
 *         PRD_SCAN_COMM_REGISTER_ZERO back to the rule code.
 * @param  i_chip A core chip.
 * @param  io_sc  The step code data struct.
 * @return PRD_SCAN_COMM_REGISTER_ZERO always.
 */
int32_t returnScomRegisterZero(ExtensibleChip*, STEP_CODE_DATA_STRUCT&)
{
    return PRD_SCAN_COMM_REGISTER_ZERO;
}
PRDF_PLUGIN_DEFINE(p10_core, returnScomRegisterZero);

//##############################################################################
//##                       Line Delete Functions
//##############################################################################

/**
 * @brief Adds L2 Line Delete/Column Repair FFDC to an SDC.
 * @param i_coreChip A core chip.
 * @param io_sc      Step code data struct.
 */
void addL2LdCrFfdc( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc,
                    LD_CR_FFDC::L2LdCrFfdc & i_LdCrFfdc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and
    // adjust the size for endianness.
    static const size_t sz_maxData =
        ((sizeof(LD_CR_FFDC::L2LdCrFfdc) + sz_word-1) / sz_word) * sz_word;

    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );
    memcpy( &data, &i_LdCrFfdc, sz_maxData);

    // Fix endianness issues with non PPC machines.
#if( __BYTE_ORDER == __LITTLE_ENDIAN )

    for ( uint32_t i = 0; i < (sz_maxData/sz_word); i++ )
        ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

#endif

    // Add data to capture data.
    BitString  bs( sz_maxData*8, (CPU_WORD *) &data );
    cd.Add( i_coreChip->getTrgt(),
            Util::hashString(LD_CR_FFDC::L2TITLE), bs );
}

/**
 * @brief Adds L3 Line Delete/Column Repair FFDC to an SDC.
 * @param i_coreChip A core chip.
 * @param io_sc      Step code data struct.
 */
void addL3LdCrFfdc( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc,
                    LD_CR_FFDC::L3LdCrFfdc & i_LdCrFfdc )
{
    CaptureData & cd = io_sc.service_data->GetCaptureData();

    static const size_t sz_word = sizeof(CPU_WORD);

    // Get the maximum capture data size and
    // adjust the size for endianness.
    static const size_t sz_maxData =
        ((sizeof(LD_CR_FFDC::L3LdCrFfdc) + sz_word-1) / sz_word) * sz_word;

    uint8_t data[sz_maxData];
    memset( data, 0x00, sz_maxData );
    memcpy( &data, &i_LdCrFfdc, sz_maxData);

    // Fix endianness issues with non PPC machines.
#if( __BYTE_ORDER == __LITTLE_ENDIAN )

    for ( uint32_t i = 0; i < (sz_maxData/sz_word); i++ )
        ((CPU_WORD*)data)[i] = htonl(((CPU_WORD*)data)[i]);

#endif

    // Add data to capture data.
    BitString bs( sz_maxData*8, (CPU_WORD *) &data );
    cd.Add( i_coreChip->getTrgt(),
            Util::hashString(LD_CR_FFDC::L3TITLE), bs );
}


/**
 * @brief  Handle an L2 UE
 * @param  i_coreChip Core chip.
 * @param  io_sc      Step code data struct.
 * @return SUCCESS always
 */
int32_t L2UE( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc )
{

#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p10_l2err_extract_err_data errorAddr =
        { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL2Err( i_coreChip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L2UE] HUID: 0x%08x extractL2Err failed",
                  i_coreChip->getHuid());
        return SUCCESS;
    }

    PRDF_TRAC( "[L2UE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d back_of_2to1_nextcycle=%d syndrome_col=%x "
               "addr=%x",
               i_coreChip->getHuid(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.back_of_2to1_nextcycle,
               errorAddr.syndrome_col, errorAddr.real_address_47_56 );

    // Add L2 FFDC
    P10CoreDataBundle * l_bundle = getCoreDataBundle(i_coreChip);
    l_bundle->iv_L2LDCount++;

    LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
    ldcrffdc.L2LDcnt        = l_bundle->iv_L2LDCount;
    ldcrffdc.L2errMember    = errorAddr.member;
    ldcrffdc.L2errDW        = errorAddr.dw;
    ldcrffdc.L2errBank      = errorAddr.bank;
    ldcrffdc.L2errBack2to1  = errorAddr.back_of_2to1_nextcycle;
    ldcrffdc.L2errSynCol    = errorAddr.syndrome_col;
    ldcrffdc.L2errAddress   = errorAddr.real_address_47_56;
    addL2LdCrFfdc( i_coreChip, io_sc, ldcrffdc );

#endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_core, L2UE );

/**
 * @brief  Handle an L3 UE
 * @param  i_coreChip Core chip.
 * @param  io_sc      Step code data struct.
 * @return SUCCESS always
 */
int32_t L3UE( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc )
{

#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p10_l3err_extract_err_data errorAddr = { L3ERR_CE_UE, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL3Err( i_coreChip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L3UE] HUID: 0x%08x extractL3Err failed",
                  i_coreChip->getHuid());
        return SUCCESS;
    }

    PRDF_TRAC( "[L3UE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d syndrome_col=%x addr=%x",
               i_coreChip->getHuid(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.syndrome_col,
               errorAddr.real_address_46_57 );

    // Add L3 FFDC
    P10CoreDataBundle * l_bundle = getCoreDataBundle(i_coreChip);
    l_bundle->iv_L3LDCount++;

    LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
    ldcrffdc.L3LDcnt      = l_bundle->iv_L3LDCount;
    ldcrffdc.L3errMember  = errorAddr.member;
    ldcrffdc.L3errDW      = errorAddr.dw;
    ldcrffdc.L3errBank    = errorAddr.bank;
    ldcrffdc.L3errSynCol  = errorAddr.syndrome_col;
    ldcrffdc.L3errAddress = errorAddr.real_address_46_57;
    addL3LdCrFfdc( i_coreChip, io_sc, ldcrffdc );

#endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_core, L3UE );

/**
 * @brief  Handle an L2 CE
 * @param  i_coreChip Core chip.
 * @param  io_sc      Step code data struct.
 * @return SUCCESS always
 */
int32_t L2CE( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc )
{
#if defined(__HOSTBOOT_RUNTIME) || defined(ESW_SIM_COMPILE)

    do {
        P10CoreDataBundle * l_bundle = getCoreDataBundle(i_coreChip);
        uint16_t l_maxLineDelAllowed = 0;
        int32_t l_rc = SUCCESS;

#ifdef __HOSTBOOT_RUNTIME
        p10_l2err_extract_err_data errorAddr =
            { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        l_rc = extractL2Err( i_coreChip->getTrgt(), true, errorAddr );
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L2CE] HUID: 0x%08x extractL2Err failed",
                      i_coreChip->getHuid());
            break;
        }

        PRDF_TRAC( "[L2CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d back_of_2to1_nextcycle=%d syndrome_col=%x "
                   "addr=%x",
                   i_coreChip->getHuid(), errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.back_of_2to1_nextcycle,
                   errorAddr.syndrome_col, errorAddr.real_address_47_56 );

        LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
        ldcrffdc.L2LDcnt       = l_bundle->iv_L2LDCount;
        ldcrffdc.L2errMember   = errorAddr.member;
        ldcrffdc.L2errDW       = errorAddr.dw;
        ldcrffdc.L2errBank     = errorAddr.bank;
        ldcrffdc.L2errBack2to1 = errorAddr.back_of_2to1_nextcycle;
        ldcrffdc.L2errSynCol   = errorAddr.syndrome_col;
        ldcrffdc.L2errAddress  = errorAddr.real_address_47_56;
        addL2LdCrFfdc( i_coreChip, io_sc, ldcrffdc );
#endif
        if (mfgMode())
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_MNFG_TH_L2_LINE_DELETES>();
        else
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_FIELD_TH_L2_LINE_DELETES>();

        // Ensure we're still allowed to issue repairs
        if (l_bundle->iv_L2LDCount >= l_maxLineDelAllowed)
        {
            PRDF_TRAC( "[L2CE] HUID: 0x%08x No more repairs allowed",
                       i_coreChip->getHuid());

            // MFG wants to be able to ignore these errors
            // If they have LD  allowed set to 0, wait for
            // predictive threshold
            if (!mfgMode() ||
                l_maxLineDelAllowed != 0 )
            {
                io_sc.service_data->SetThresholdMaskId(0);
            }
            break;
        }

        // Add to CE table and Check if we need to issue a repair on this CE
        if (l_bundle->iv_L2CETable->addAddress(l_bundle->iv_L2LDCount,
                                               io_sc) == false)
        {
            // No action required on this CE, we're waiting for additional
            // errors before applying a line delete
            break;
        }

        // Execute the line delete
        PRDF_TRAC( "[L2CE] HUID: 0x%08x apply directed line delete",
                        i_coreChip->getHuid());
#ifdef __HOSTBOOT_RUNTIME
        l_rc = l2LineDelete(i_coreChip->getTrgt(), errorAddr);
#endif
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L2CE] HUID: 0x%08x l2LineDelete failed",
                      i_coreChip->getHuid());
            // Set signature to indicate L2 Line Delete failed
            io_sc.service_data->SetErrorSig(
                            PRDFSIG_P10CORE_L2CE_LD_FAILURE);
        }
        else
        {
            l_bundle->iv_L2LDCount++;

            // Set signature to indicate L2 Line Delete issued
            io_sc.service_data->SetErrorSig(
                                PRDFSIG_P10CORE_L2CE_LD_ISSUED);
        }

    } while(0);

#endif

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE( p10_core, L2CE );

/**
 * @brief Handle an L3 CE
 * @param i_coreChip Core chip.
 * @param io_sc      Step Code data struct
 * @return PRD return code
 */
int32_t L3CE( ExtensibleChip * i_coreChip, STEP_CODE_DATA_STRUCT & io_sc )
{

#if defined(__HOSTBOOT_RUNTIME) || defined(ESW_SIM_COMPILE)

    do {
        P10CoreDataBundle * l_bundle = getCoreDataBundle(i_coreChip);
        uint16_t l_maxLineDelAllowed = 0;
        uint16_t curMem = 0xFFFF;
        int32_t l_rc = SUCCESS;

#ifdef __HOSTBOOT_RUNTIME
        p10_l3err_extract_err_data errorAddr =
            { L3ERR_CE_UE, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        l_rc = extractL3Err( i_coreChip->getTrgt(), true, errorAddr );
        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L3CE] HUID: 0x%08x extractL3Err failed",
                      i_coreChip->getHuid());
            break;
        }

        PRDF_TRAC( "[L3CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d syndrome_col=%x addr=%x",
                   i_coreChip->getHuid(), errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.syndrome_col,
                   errorAddr.real_address_46_57 );


        LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
        ldcrffdc.L3LDcnt      = l_bundle->iv_L3LDCount;
        ldcrffdc.L3errMember  = errorAddr.member;
        ldcrffdc.L3errDW      = errorAddr.dw;
        ldcrffdc.L3errBank    = errorAddr.bank;
        ldcrffdc.L3errSynCol  = errorAddr.syndrome_col;
        ldcrffdc.L3errAddress = errorAddr.real_address_46_57;
        addL3LdCrFfdc( i_coreChip, io_sc, ldcrffdc );

        curMem = errorAddr.member;
#endif

        if (mfgMode())
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_MNFG_TH_L3_LINE_DELETES>();
        else
            l_maxLineDelAllowed =
              getSystemTarget()->getAttr<ATTR_FIELD_TH_L3_LINE_DELETES>();

        // Ensure we're still allowed to issue repairs
        if (l_bundle->iv_L3LDCount >= l_maxLineDelAllowed)
        {
            PRDF_TRAC( "[L3CE] HUID: 0x%08x No more repairs allowed",
                       i_coreChip->getHuid());

            // MFG wants to be able to ignore these errors
            // If they have LD  allowed set to 0, wait for
            // predictive threshold
            if (!mfgMode() ||
                l_maxLineDelAllowed != 0 )
            {
                io_sc.service_data->SetThresholdMaskId(0);
            }
            break;
        }

        // Add to CE table and Check if we need to issue a repair on this CE
        if (l_bundle->iv_L3CETable->addAddress(l_bundle->iv_L3LDCount,
                                               io_sc) == false)
        {
            // No action required on this CE, we're waiting for additional
            // errors before applying a line delete
            break;
        }

        // Check for multi-bitline fail
        Timer curTime = io_sc.service_data->GetTOE();
        uint16_t prvMem = l_bundle->iv_prevMember;

        if ( prvMem != 0xFFFF && // we have data saved from a previous LD
             l_bundle->iv_blfTimeout > curTime && // the timer has not expired
             prvMem != curMem ) // the current fail is on a different bitline
        {
            // We have multiple bit lines failing within a 24 hour period
            // Make this predictive
            PRDF_TRAC( "[L3CE] HUID: 0x%08x Multi-bitline fail detected",
                       i_coreChip->getHuid() );
            io_sc.service_data->SetThresholdMaskId(0);
            io_sc.service_data->SetErrorSig( PRDFSIG_P10CORE_L3CE_MBF_FAIL );
            break;
        }

        // Update saved bitline data
        l_bundle->iv_prevMember = curMem;
        l_bundle->iv_blfTimeout = curTime + Timer::SEC_IN_DAY;


        PRDF_TRAC( "[L3CE] HUID: 0x%08x apply directed line delete",
                i_coreChip->getHuid());
        #ifdef __HOSTBOOT_RUNTIME
        l_rc = l3LineDelete(i_coreChip->getTrgt(), errorAddr);
        #endif


        if (SUCCESS != l_rc)
        {
            PRDF_ERR( "[L3CE] HUID: 0x%08x l3LineDelete failed",
                      i_coreChip->getHuid());
            // Set signature to indicate L3 Line Delete failed
            io_sc.service_data->SetErrorSig(
                            PRDFSIG_P10CORE_L3CE_LD_FAILURE);
        }
        else
        {
            l_bundle->iv_L3LDCount++;

            // Set signature to indicate L3 Line Delete issued
            io_sc.service_data->SetErrorSig(
                                PRDFSIG_P10CORE_L3CE_LD_ISSUED);
        }

    } while(0);

#endif

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE( p10_core, L3CE );

/**
 * @brief  For P10 DD1.0, generate information log and mask attention.
 * @param  i_chip A core chip.
 * @param  io_sc  The step code data struct
 * @return SUCCESS for P10 DD1.0, PRD_SCAN_COMM_REGISTER_ZERO for P10 DD2.0+.
 */
int32_t ignoreDD10(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc)
{
    if (0x10 == getChipLevel(i_chip->getTrgt()))
    {
        // Add level 2 support and this core to the callout list (just in case).
        io_sc.service_data->SetCallout(LEVEL2_SUPPORT, MRU_MED);
        io_sc.service_data->SetCallout(i_chip->getTrgt(), MRU_LOW, NO_GARD);

        // Set the threshold flag so that rule code will mask this attention.
        io_sc.service_data->setFlag(ServiceDataCollector::AT_THRESHOLD);

        // Clear the service call flag (informational only).
        if (CHECK_STOP != io_sc.service_data->getPrimaryAttnType())
        {
            io_sc.service_data->clearServiceCall();
        }

        return SUCCESS;
    }

    return PRD_SCAN_COMM_REGISTER_ZERO; // So try statement will continue.
}
PRDF_PLUGIN_DEFINE(p10_core, ignoreDD10);

} // end namespace p10_core
} // end namespace PRDF
