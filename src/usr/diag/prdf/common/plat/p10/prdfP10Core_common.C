/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p10/prdfP10Core_common.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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
 * @brief  EQ_CORE_FIR[56] - analyzes recoverable attentions on the neighbor
 *         core in the core pair.
 * @param  i_chip A core chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on error. Otherwise, SUCCESS.
 */
int32_t analyzeNeighborCore_RE(ExtensibleChip* i_chip,
                               STEP_CODE_DATA_STRUCT& io_sc)
{
    // First, check if there is a neighbor core.
    ExtensibleChip* neighbor = getNeighborCore(i_chip);
    if (nullptr == neighbor)
    {
        // There is no neighbor core. This would be a bug because this FIR bit
        // should only be unmasked if there is a neighbor core. Return saying
        // nothing was found and the rule code will callout level 2 support.
        PRDF_ERR("analyzeNeighborCore_RE(0x%08x) no neighbor core",
                 i_chip->getHuid());
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }

    // Then, check if there are any recoverable attentions on the other core.
    SCAN_COMM_REGISTER_CLASS* wof  = neighbor->getRegister("EQ_CORE_FIR_WOF");
    SCAN_COMM_REGISTER_CLASS* mask = neighbor->getRegister("EQ_CORE_FIR_MASK");
    SCAN_COMM_REGISTER_CLASS* act0 = neighbor->getRegister("EQ_CORE_FIR_ACT0");
    SCAN_COMM_REGISTER_CLASS* act1 = neighbor->getRegister("EQ_CORE_FIR_ACT1");

    if (SUCCESS != (wof->Read() | mask->Read() | act0->Read() | act1->Read()))
    {
        PRDF_ERR("analyzeNeighborCore_RE(0x%08x) read failure",
                 i_chip->getHuid());
        return PRD_SCANCOM_FAILURE;
    }

    // Ignore bit 56 because it says there are recoverable attentions on this
    // core and it could send us in an infinite loop.
    if (0 == ( wof->GetBitFieldJustified( 0, 64) &
              ~mask->GetBitFieldJustified(0, 64) & // not masked
              ~act0->GetBitFieldJustified(0, 64) & // act0=0
               act1->GetBitFieldJustified(0, 64) & // act1=1
              ~0x0000000000000080ll))              // bit 56 is not set
    {
        // There are no active recoverable attentions on the peer core.
        // Typically, this would be a bug. Unfortunately, we don't have a
        // reliable way to clear this attention after the rule code clears the
        // recoverable attention on the peer core. Therefore, we'll have to
        // surpress this log.
        PRDF_INF("analyzeNeighborCore_RE(0x%08x) no attn on neighbor, deleting "
                 "error log", i_chip->getHuid());
        io_sc.service_data->setDontCommitErrl();
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }

    // There are active recoverable attentions on the neighbor core. Analyze it.
    return neighbor->Analyze(io_sc, io_sc.service_data->getSecondaryAttnType());
}
PRDF_PLUGIN_DEFINE(p10_core, analyzeNeighborCore_RE);

/**
 * @brief  EQ_CORE_FIR[57] - analyzes unit checkstop attentions on the neighbor
 *         core in the core pair.
 * @param  i_chip A core chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS on error. Otherwise, SUCCESS.
 */
int32_t analyzeNeighborCore_UCS(ExtensibleChip* i_chip,
                                STEP_CODE_DATA_STRUCT& io_sc)
{
    // First, check if there is a neighbor core.
    ExtensibleChip* neighbor = getNeighborCore(i_chip);
    if (nullptr == neighbor)
    {
        // There is no neighbor core. This would be a bug because this FIR bit
        // should only be unmasked if there is a neighbor core. Return saying
        // nothing was found and the rule code will callout level 2 support.
        PRDF_ERR("analyzeNeighborCore_UCS(0x%08x) no neighbor core",
                 i_chip->getHuid());
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }

    // Then, check if there are any unit checkstop attentions on the other core.
    SCAN_COMM_REGISTER_CLASS* fir  = neighbor->getRegister("EQ_CORE_FIR");
    SCAN_COMM_REGISTER_CLASS* wof  = neighbor->getRegister("EQ_CORE_FIR_WOF");
    SCAN_COMM_REGISTER_CLASS* mask = neighbor->getRegister("EQ_CORE_FIR_MASK");
    SCAN_COMM_REGISTER_CLASS* act0 = neighbor->getRegister("EQ_CORE_FIR_ACT0");
    SCAN_COMM_REGISTER_CLASS* act1 = neighbor->getRegister("EQ_CORE_FIR_ACT1");

    if (SUCCESS != (fir->Read() | wof->Read() | mask->Read() |
                    act0->Read() | act1->Read()))
    {
        PRDF_ERR("analyzeNeighborCore_UCS(0x%08x) read failure",
                 i_chip->getHuid());
        return PRD_SCANCOM_FAILURE;
    }

    // - We have seen in the field that unit checkstop attentions may only
    //   report via the WOF if there is a system checkstop attention present. So
    //   check both the FIR and WOF.
    // - Ignore bit 57 because it says there is a unit CS attention on this core
    //   and it could send us in an infinite loop.
    // - Ignore bit 60 because it says there is a unit CS attentions on the
    //   neighbor core and is redundant.
    if (0 == ((fir->GetBitFieldJustified( 0, 64) |
               wof->GetBitFieldJustified( 0, 64)) & // FIR or WOF
              ~mask->GetBitFieldJustified(0, 64)  & // not masked
               act0->GetBitFieldJustified(0, 64)  & // act0=1
               act1->GetBitFieldJustified(0, 64)  & // act1=1
              ~0x0000000000000048ll))               // bit 57 or 60 are not set
    {
        // There are no active unit CS attentions. This would be a bug because
        // this FIR should only fire if there was an attention. Return saying
        // nothing was found and the rule code will callout level 2 support.
        PRDF_ERR("analyzeNeighborCore_UCS(0x%08x) no attn on neighbor",
                 i_chip->getHuid());
        return PRD_SCAN_COMM_REGISTER_ZERO;
    }

    // There are active unit CS attentions on the neighbor core. Analyze it.
    return neighbor->Analyze(io_sc, io_sc.service_data->getSecondaryAttnType());
}
PRDF_PLUGIN_DEFINE(p10_core, analyzeNeighborCore_UCS);

//##############################################################################
//##                       Line Delete Functions
//##############################################################################

// IMPORTANT NOTE ABOUT APPLYING LINE DELETES:
// In legacy iterations of the line delete design, thresholding would be done
// on a per address basis. The fundamental problem is that the address captured
// for a CE is not locked and could change any number of times before PRD has
// had a chance to analyze the first CE. In order to be accurate, the design
// ended being very complicated and hard to test. Since at least P9, we have
// changed the design to be a "poor man's" line delete where a line delete is
// issued when the CE theshold is reached regardless of the addresses that are
// reported. It has been observed in the field that single bit fails are almost
// all on the same address, which is what allows us to get away with this
// simpler design.

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

    // Add data to capture data.
    BitString bs( sz_maxData*8, (CPU_WORD *) &data );
    cd.Add( i_coreChip->getTrgt(),
            Util::hashString(LD_CR_FFDC::L3TITLE), bs );
}

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief Adds L2 Line Delete FFDC to an SDC.
 * @param i_chip  A core chip.
 * @param io_sc   Step code data struct.
 * @param i_count The current line delete count.
 * @param i_addr  The error address struct returned from the trace arrays.
 */
void addL2LineDeleteFfdc(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                   uint16_t i_count, const p10_l2err_extract_err_data& i_addr)
{
    PRDF_TRAC("L2 cache error: HUID=0x%08x ce_ue=0x%x member=0x%x dw=0x%x "
              "bank=0x%x back_of_2to1_nextcycle=0x%x syndrome_col=0x%x "
              "addr=0x%x", i_chip->getHuid(), i_addr.ce_ue, i_addr.member,
              i_addr.dw, i_addr.bank, i_addr.back_of_2to1_nextcycle,
              i_addr.syndrome_col, i_addr.real_address_47_56);

    // Allocate memory space for the FFDC. See data below for buffer size.
    auto ffdc = std::make_shared<FfdcBuffer>(ErrlL2LineDeleteFfdc,
                                             ErrlVer1, 15);

    // Try to avoid using HUID in PEL parser so get target positions.
    auto core = i_chip->getTrgt();
    uint8_t nodePos = getTargetPosition(getConnectedParent(core, TYPE_NODE));
    uint8_t procPos = getTargetPosition(getConnectedParent(core, TYPE_PROC));
    uint8_t corePos = getTargetPosition(core);

    // Will need the maximum number of allowed line deletes.
    uint16_t maxLineDeleteAllowed = mfgMode()
        ? getSystemTarget()->getAttr<ATTR_MNFG_TH_L2_LINE_DELETES>()
        : getSystemTarget()->getAttr<ATTR_FIELD_TH_L2_LINE_DELETES>();

    // Stream everything into the FFDC data buffer.
    (*ffdc) << nodePos                                              // 1 byte
            << procPos                                              // 1 byte
            << corePos                                              // 1 byte
            << i_count                                              // 2 bytes
            << maxLineDeleteAllowed                                 // 2 bytes
            << static_cast<uint8_t>(i_addr.ce_ue)                   // 1 byte
            << i_addr.member                                        // 1 byte
            << i_addr.dw                                            // 1 byte
            << i_addr.bank                                          // 1 byte
            << static_cast<uint8_t>(i_addr.back_of_2to1_nextcycle)  // 1 byte
            << i_addr.syndrome_col                                  // 1 byte
            << i_addr.real_address_47_56;                           // 2 bytes
                                                            // total: 15 bytes

    if (!ffdc->good())
    {
        PRDF_ERR("[addL2LineDeleteFfdc] Buffer state bad. Data may be "
                 "incomplete.");
    }

    // Add the data to the SDC regardless if the buffer state is bad so that we
    // have something to use for debug.
    io_sc.service_data->getFfdc().push_back(ffdc);
}
#endif

#ifdef __HOSTBOOT_RUNTIME
/**
 * @brief Adds L3 Line Delete FFDC to an SDC.
 * @param i_chip  A core chip.
 * @param io_sc   Step code data struct.
 * @param i_count The current line delete count.
 * @param i_addr  The error address struct returned from the trace arrays.
 */
void addL3LineDeleteFfdc(ExtensibleChip* i_chip, STEP_CODE_DATA_STRUCT& io_sc,
                   uint16_t i_count, const p10_l3err_extract_err_data& i_addr)
{
    PRDF_TRAC("L3 cache error: HUID=0x%08x ce_ue=0x%x member=0x%x dw=0x%x "
              "bank=0x%x cl_half=0x%x syndrome_col=0x%x addr=0x%x",
              i_chip->getHuid(), i_addr.ce_ue, i_addr.member, i_addr.dw,
              i_addr.bank, i_addr.cl_half, i_addr.syndrome_col,
              i_addr.real_address_46_57);

    // Allocate memory space for the FFDC. See data below for buffer size.
    auto ffdc = std::make_shared<FfdcBuffer>(ErrlL3LineDeleteFfdc,
                                             ErrlVer1, 15);

    // Try to avoid using HUID in PEL parser so get target positions.
    auto core = i_chip->getTrgt();
    uint8_t nodePos = getTargetPosition(getConnectedParent(core, TYPE_NODE));
    uint8_t procPos = getTargetPosition(getConnectedParent(core, TYPE_PROC));
    uint8_t corePos = getTargetPosition(core);

    // Will need the maximum number of allowed line deletes.
    uint16_t maxLineDeleteAllowed = mfgMode()
        ? getSystemTarget()->getAttr<ATTR_MNFG_TH_L3_LINE_DELETES>()
        : getSystemTarget()->getAttr<ATTR_FIELD_TH_L3_LINE_DELETES>();

    // Stream everything into the FFDC data buffer.
    (*ffdc) << nodePos                              // 1 byte
            << procPos                              // 1 byte
            << corePos                              // 1 byte
            << i_count                              // 2 bytes
            << maxLineDeleteAllowed                 // 2 bytes
            << static_cast<uint8_t>(i_addr.ce_ue)   // 1 byte
            << i_addr.member                        // 1 byte
            << i_addr.dw                            // 1 byte
            << i_addr.bank                          // 1 byte
            << i_addr.cl_half                       // 1 byte
            << i_addr.syndrome_col                  // 1 byte
            << i_addr.real_address_46_57;           // 2 bytes
                                            // total: 15 bytes

    if (!ffdc->good())
    {
        PRDF_ERR("[addL3LineDeleteFfdc] Buffer state bad. Data may be "
                 "incomplete.");
    }

    // Add the data to the SDC regardless if the buffer state is bad so that we
    // have something to use for debug.
    io_sc.service_data->getFfdc().push_back(ffdc);
}
#endif

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
    p10_l2err_extract_err_data errorAddr{};

    // Get failing location from trace array
    l_rc = extractL2Err( i_coreChip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L2UE] HUID: 0x%08x extractL2Err failed",
                  i_coreChip->getHuid());
        return SUCCESS;
    }

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

    // Finally, add the FFDC to the SDC.
    addL2LineDeleteFfdc(i_coreChip, io_sc, l_bundle->iv_L2LDCount, errorAddr);

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
    p10_l3err_extract_err_data errorAddr{};

    // Get failing location from trace array
    l_rc = extractL3Err( i_coreChip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L3UE] HUID: 0x%08x extractL3Err failed",
                  i_coreChip->getHuid());
        return SUCCESS;
    }

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

    // Finally, add the FFDC to the SDC.
    addL3LineDeleteFfdc(i_coreChip, io_sc, l_bundle->iv_L3LDCount, errorAddr);

    #endif

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE( p10_core, L3UE );

/**
 * @brief  Handle an L2 CE
 * @param  i_chip Core chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L2CE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_RUNTIME

    P10CoreDataBundle* l_bundle = getCoreDataBundle(i_chip);
    auto trgt = i_chip->getTrgt();
    auto huid = i_chip->getHuid();

    p10_l2err_extract_err_data errorAddr{};

    // FFDC will be collected throughout function and added to SDC at the end.
    LD_CR_FFDC::L2LdCrFfdc ldcrffdc;

    // Get the maximum number of line deletes allowed and add to FFDC.
    uint16_t l_maxLineDelAllowed = mfgMode()
                ? getSystemTarget()->getAttr<ATTR_MNFG_TH_L2_LINE_DELETES>()
                : getSystemTarget()->getAttr<ATTR_FIELD_TH_L2_LINE_DELETES>();

    ldcrffdc.L2LDMaxAllowed = l_maxLineDelAllowed;

    do
    {
        // Get failing location from trace array
        if (SUCCESS != extractL2Err(trgt, true, errorAddr))
        {
            PRDF_ERR("[L2CE] HUID: 0x%08x extractL2Err failed", huid);
            break;
        }

        ldcrffdc.L2errMember   = errorAddr.member;
        ldcrffdc.L2errDW       = errorAddr.dw;
        ldcrffdc.L2errBank     = errorAddr.bank;
        ldcrffdc.L2errBack2to1 = errorAddr.back_of_2to1_nextcycle;
        ldcrffdc.L2errSynCol   = errorAddr.syndrome_col;
        ldcrffdc.L2errAddress  = errorAddr.real_address_47_56;

        // Increment the CE count and determine if a line delete is needed.
        // IMPORTANT: Yes, we are actually passing the line delete count as the
        // "address" parameter of this function. See the notice above regarding
        // the thesholding for the "poor man's" line delete design.
        if (!l_bundle->iv_L2CETable->addAddress(l_bundle->iv_L2LDCount, io_sc))
        {
            break; // no line delete on this CE, nothing more to do
        }

        // A line delete is required. Before continuing, there is a special case
        // for manufacturing where we don't want to check the line delete
        // threshold if the max allowed is 0. Instead, report this as a CE and
        // let the rule code threholding kick in.
        if (mfgMode() && (0 == l_maxLineDelAllowed))
        {
            break; // nothing more to do
        }

        PRDF_INF("[L2CE] HUID: 0x%08x applying line delete", huid);

        if (SUCCESS != l2LineDelete(trgt, errorAddr))
        {
            PRDF_ERR("[L2CE] HUID: 0x%08x l2LineDelete failed", huid);
            io_sc.service_data->SetErrorSig(PRDFSIG_P10CORE_L2CE_LD_FAILURE);
            io_sc.service_data->setPredictive();
            break; // nothing more to do
        }

        // The line delete was successful applied.
        l_bundle->iv_L2LDCount++;
        io_sc.service_data->SetErrorSig(PRDFSIG_P10CORE_L2CE_LD_ISSUED);

        // Check if the line delete threshold has been reached.
        if (l_maxLineDelAllowed <= l_bundle->iv_L2LDCount)
        {
            PRDF_INF("[L2CE] HUID: 0x%08x line delete threshold reached", huid);
            io_sc.service_data->setPredictive();
            break; // nothing more to do
        }

    } while(0);

    // The line delete count may, or may not, have been updated. Regardless, add
    // the latest value to the FFDC.
    ldcrffdc.L2LDcnt = l_bundle->iv_L2LDCount;

    // Finally, add the FFDC to the SDC.
    addL2LineDeleteFfdc(i_chip, io_sc, l_bundle->iv_L2LDCount, errorAddr);

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE( p10_core, L2CE );

/**
 * @brief Handle an L3 CE
 * @param  i_chip Core chip.
 * @param  io_sc  Step code data struct.
 * @return PRD return code
 */
int32_t L3CE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_RUNTIME

    P10CoreDataBundle* l_bundle = getCoreDataBundle(i_chip);
    auto trgt = i_chip->getTrgt();
    auto huid = i_chip->getHuid();

    p10_l3err_extract_err_data errorAddr{};

    // FFDC will be collected throughout function and added to SDC at the end.
    LD_CR_FFDC::L3LdCrFfdc ldcrffdc;

    // Get the maximum number of line deletes allowed and add to FFDC.
    uint16_t l_maxLineDelAllowed = mfgMode()
                ? getSystemTarget()->getAttr<ATTR_MNFG_TH_L3_LINE_DELETES>()
                : getSystemTarget()->getAttr<ATTR_FIELD_TH_L3_LINE_DELETES>();

    ldcrffdc.L3LDMaxAllowed = l_maxLineDelAllowed;

    do
    {
        // Get failing location from trace array
        if (SUCCESS != extractL3Err(trgt, true, errorAddr))
        {
            PRDF_ERR("[L3CE] HUID: 0x%08x extractL3Err failed", huid);
            break;
        }

        ldcrffdc.L3errMember  = errorAddr.member;
        ldcrffdc.L3errDW      = errorAddr.dw;
        ldcrffdc.L3errBank    = errorAddr.bank;
        ldcrffdc.L3errSynCol  = errorAddr.syndrome_col;
        ldcrffdc.L3errAddress = errorAddr.real_address_46_57;

        // Increment the CE count and determine if a line delete is needed.
        // IMPORTANT: Yes, we are actually passing the line delete count as the
        // "address" parameter of this function. See the notice above regarding
        // the thesholding for the "poor man's" line delete design.
        if (!l_bundle->iv_L3CETable->addAddress(l_bundle->iv_L3LDCount, io_sc))
        {
            break; // no line delete on this CE, nothing more to do
        }

        // A line delete is required. Before continuing, there is a special case
        // for manufacturing where we don't want to check the line delete
        // threshold if the max allowed is 0. Instead, report this as a CE and
        // let the rule code threholding kick in.
        if (mfgMode() && (0 == l_maxLineDelAllowed))
        {
            break; // nothing more to do
        }

        PRDF_INF("[L3CE] HUID: 0x%08x applying line delete", huid);

        if (SUCCESS != l3LineDelete(trgt, errorAddr))
        {
            PRDF_ERR("[L3CE] HUID: 0x%08x l3LineDelete failed", huid);
            io_sc.service_data->SetErrorSig(PRDFSIG_P10CORE_L3CE_LD_FAILURE);
            io_sc.service_data->setPredictive();
            break; // nothing more to do
        }

        // The line delete was successful applied.
        l_bundle->iv_L3LDCount++;
        io_sc.service_data->SetErrorSig(PRDFSIG_P10CORE_L3CE_LD_ISSUED);

        // Check if the line delete threshold has been reached.
        if (l_maxLineDelAllowed <= l_bundle->iv_L3LDCount)
        {
            PRDF_INF("[L3CE] HUID: 0x%08x line delete threshold reached", huid);
            io_sc.service_data->setPredictive();
            break; // nothing more to do
        }

    } while(0);

    // The line delete count may, or may not, have been updated. Regardless, add
    // the latest value to the FFDC.
    ldcrffdc.L3LDcnt = l_bundle->iv_L3LDCount;

    // Finally, add the FFDC to the SDC.
    addL3LineDeleteFfdc(i_chip, io_sc, l_bundle->iv_L2LDCount, errorAddr);

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE( p10_core, L3CE );

/**
 * @brief  The PowerBus token manager has died. Callout the chip that was
 *         responsible for generating the token.
 * @param  i_chip A core chip.
 * @param  io_sc  The step code data struct
 * @return SUCCESS always.
 */
int32_t calloutPbTokenManager(ExtensibleChip* i_chip,
                              STEP_CODE_DATA_STRUCT& io_sc)
{
    for (const auto& trgt : getFunctionalTargetList(TYPE_PROC))
    {
        auto chip = (ExtensibleChip*)systemPtr->GetChip(trgt);

        chip->CaptureErrorData(io_sc.service_data->GetCaptureData(),
                               Util::hashString("PbTokenManager"));

        auto reg = chip->getRegister("PB_STATION_HP_MODE1_CURR");

        if ((SUCCESS == reg->Read()) && reg->IsBitSet(1))
        {
            io_sc.service_data->SetCallout(trgt, MRU_HIGH);

            // There should only be one. However, will continue to all of the
            // processors to collect the FFDC, just in case.
        }
    }

    return SUCCESS;
}
PRDF_PLUGIN_DEFINE(p10_core, calloutPbTokenManager);

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
