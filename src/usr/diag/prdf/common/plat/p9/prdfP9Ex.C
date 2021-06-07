/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/p9/prdfP9Ex.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <prdfPluginMap.H>

#include <prdfP9ExDataBundle.H>
#include <prdfP9ExExtraSig.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfMfgThreshold.H>
#include <UtilHash.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

namespace Ex
{

/**
 * @brief  Plugin that initializes the EX data bundle.
 * @param  i_exChip An ex chip.
 * @return SUCCESS
 */
int32_t Initialize( ExtensibleChip * i_exChip )
{
    i_exChip->getDataBundle() = new P9ExDataBundle( i_exChip );
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, Initialize );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, Initialize );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, Initialize );

/**
 * @brief  Plugin function called after analysis is complete but before PRD
 *         exits.
 * @param  i_exChip An EX chip.
 * @param  io_sc     The step code data struct.
 * @note   This is especially useful for any analysis that still needs to be
 *         done after the framework clears the FIR bits that were at attention.
 * @return SUCCESS.
 */
int32_t PostAnalysis( ExtensibleChip * i_exChip,
                      STEP_CODE_DATA_STRUCT & io_sc )
{
    #define PRDF_FUNC "[Ex::PostAnalysis] "

    int32_t l_rc = SUCCESS;

    //##########################################################################
    // Start Nimbus DD1.0 core recovery workaround
    //##########################################################################

    do
    {
        if ( CHECK_STOP   == io_sc.service_data->getPrimaryAttnType() ||
             MODEL_NIMBUS != getChipModel(i_exChip->getTrgt()) ||
             0x10         != getChipLevel(i_exChip->getTrgt()) )
        {
            break; // nothing to do
        }

        // If there was an attention from L2FIR[39], the rule code would have
        // then analyzed one of the two attached cores. There is no mechanism in
        // the rule code to come back to this bit and clear it. So we must do
        // that here.

        // Only need to clear the FIR if it is currently set.
        SCAN_COMM_REGISTER_CLASS * l2fir = i_exChip->getRegister("L2FIR");
        l_rc = l2fir->Read();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Read() failed on L2FIR" );
            break;
        }

        if ( !l2fir->IsBitSet(39) ) break; // nothing to do

        // Clear the FIR bit.
        SCAN_COMM_REGISTER_CLASS * l2fir_and =
            i_exChip->getRegister("L2FIR_AND");
        l2fir_and->setAllBits();
        l2fir_and->ClearBit(39);
        l_rc = l2fir_and->Write();
        if ( SUCCESS != l_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on L2FIR_AND" );
            break;
        }

        // The workaround is not level driven. So we need to check the
        // current value of the COREFIR WOFs to determine if there is a new
        // attention.

        ExtensibleChipList ecChipList = getConnected( i_exChip, TYPE_CORE );
        for ( auto & ecChip : ecChipList )
        {
            SCAN_COMM_REGISTER_CLASS * corefir_wof =
                ecChip->getRegister("COREFIR_WOF");
            SCAN_COMM_REGISTER_CLASS * corefir_mask =
                ecChip->getRegister("COREFIR_MASK");

            // A ForceRead() is required because a new attention may have
            // occured after the initial analysis.
            l_rc  = corefir_wof->ForceRead();
            l_rc |= corefir_mask->ForceRead();
            if ( SUCCESS != l_rc )
            {
                PRDF_ERR( PRDF_FUNC "ForceRead() failed on "
                          "COREFIR_WOF/COREFIR_MASK" );
                continue; // Try the other core.
            }

            // If there are attentions in the COREFIR_WOF, set L2FIR[39].
            if (  corefir_wof->GetBitFieldJustified(0,64) &
                 ~corefir_mask->GetBitFieldJustified(0,64) )
            {
                SCAN_COMM_REGISTER_CLASS * l2fir_or =
                    i_exChip->getRegister("L2FIR_OR");
                l2fir_or->clearAllBits();
                l2fir_or->SetBit(39);
                l_rc = l2fir_or->Write();
                if ( SUCCESS != l_rc )
                {
                    PRDF_ERR( PRDF_FUNC "Write() failed on L2FIR_OR" );
                    continue; // Try the other core.
                }

                // At this point there is no need to check the other core
                // since we only need to know if there is at least one
                // attention on any core.
                break;
            }
        }

    } while(0);

    //##########################################################################
    // End Nimbus DD1.0 core recovery workaround
    //##########################################################################

    return SUCCESS; // Always return SUCCESS for this plugin.

    #undef PRDF_FUNC
}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, PostAnalysis );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, PostAnalysis );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, PostAnalysis );

/**
 * @brief  For L2/L3 Cache CEs, L3 Directory CEs, and L3 LRU Parity Errors.
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t cacheCeWorkaround( ExtensibleChip * i_chip,
                           STEP_CODE_DATA_STRUCT & io_sc )
{
    // WORKAROUND: Nimbus DD1.x only.
    if ( TARGETING::MODEL_NIMBUS == getChipModel(i_chip->getTrgt()) &&
         0x20                    >  getChipLevel(i_chip->getTrgt()) )
    {
        // If we are unable to issue any more line deletes, mask the attention
        // and do not make the error log predictive.
        if ( io_sc.service_data->IsAtThreshold() )
            io_sc.service_data->clearServiceCall();
    }
    // END WORKAROUND

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, cacheCeWorkaround );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, cacheCeWorkaround );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, cacheCeWorkaround );

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
 * @param i_exChip An ex chip.
 * @param io_sc     Step code data struct.
 */
void addL2LdCrFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
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
    cd.Add( i_chip->GetChipHandle(),
            Util::hashString(LD_CR_FFDC::L2TITLE), bs );
}

/**
 * @brief Adds L3 Line Delete/Column Repair FFDC to an SDC.
 * @param i_exChip An ex chip.
 * @param io_sc     Step code data struct.
 */
void addL3LdCrFfdc( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc,
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
    cd.Add( i_chip->GetChipHandle(),
            Util::hashString(LD_CR_FFDC::L3TITLE), bs );
}


/**
 * @brief  Handle an L2 UE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L2UE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p9_l2err_extract_err_data errorAddr =
        { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL2Err( i_chip->getTrgt(), false, errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L2UE] HUID: 0x%08x extractL2Err failed",
                  i_chip->GetId());
        return SUCCESS;
    }

    PRDF_TRAC( "[L2UE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d macro=%d ow_select=%x bitline=%x is_top_sa=%x "
               "is_left_sa=%x addr=%x",
               i_chip->GetId(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.macro, errorAddr.ow_select,
               errorAddr.bitline, errorAddr.is_top_sa,
               errorAddr.is_left_sa, errorAddr.address );

    // Add L2 FFDC
    P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
    l_bundle->iv_L2LDCount++;

    LD_CR_FFDC::L2LdCrFfdc ldcrffdc;
    ldcrffdc.L2LDcnt        = l_bundle->iv_L2LDCount;
    ldcrffdc.L2errMember    = errorAddr.member;
    ldcrffdc.L2errDW        = errorAddr.dw;
    ldcrffdc.L2errMacro     = errorAddr.macro;
    ldcrffdc.L2errBank      = errorAddr.bank;
    ldcrffdc.L2errOWSelect  = errorAddr.ow_select;
    ldcrffdc.L2errBitLine   = errorAddr.bitline;
    ldcrffdc.L2errIsTopSA   = errorAddr.is_top_sa;
    ldcrffdc.L2errIsLeftSA  = errorAddr.is_left_sa;
    ldcrffdc.L2errAddress   = errorAddr.address;
    addL2LdCrFfdc( i_chip, io_sc, ldcrffdc );

#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, L2UE );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, L2UE );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L2UE );

/**
 * @brief  Handle an L3 UE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L3UE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
#ifdef __HOSTBOOT_RUNTIME
    int32_t l_rc = SUCCESS;
    p9_l3err_extract_err_data errorAddr = { L3ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

    // Get failing location from trace array
    l_rc = extractL3Err( i_chip->getTrgt(), errorAddr );
    if (SUCCESS != l_rc)
    {
        PRDF_ERR( "[L3CE] HUID: 0x%08x extractL3Err failed",
                  i_chip->GetId());
        return SUCCESS;
    }

    PRDF_TRAC( "[L3CE] HUID: 0x%08x Error data: member=%d dw=%d "
               "bank=%d dataout=%d hashed addr=%x cache addr=%x",
               i_chip->GetId(), errorAddr.member, errorAddr.dw,
               errorAddr.bank, errorAddr.dataout,
               errorAddr.hashed_real_address_45_56,
               errorAddr.cache_read_address );

    // Add L3 FFDC
    P9ExDataBundle * l_bundle = getExDataBundle(i_chip);
    l_bundle->iv_L3LDCount++;

    LD_CR_FFDC::L3LdCrFfdc ldcrffdc;
    ldcrffdc.L3LDcnt           = l_bundle->iv_L3LDCount;
    ldcrffdc.L3errMember       = errorAddr.member;
    ldcrffdc.L3errDW           = errorAddr.dw;
    ldcrffdc.L3errBank         = errorAddr.bank;
    ldcrffdc.L3errDataOut      = errorAddr.dataout;
    ldcrffdc.L3errHshAddress   = errorAddr.hashed_real_address_45_56;
    ldcrffdc.L3errCacheAddress = errorAddr.cache_read_address;
    addL3LdCrFfdc( i_chip, io_sc, ldcrffdc );

#endif
    return SUCCESS;
}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, L3UE );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, L3UE );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L3UE );

/**
 * @brief  Handle an L2 CE
 * @param  i_chip EX chip.
 * @param  io_sc  Step code data struct.
 * @return SUCCESS always
 */
int32_t L2CE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_RUNTIME

    P9ExDataBundle* l_bundle = getExDataBundle(i_chip);
    auto trgt = i_chip->getTrgt();
    auto huid = i_chip->getHuid();

    // FFDC will be collected throughout function and added to SDC at the end.
    LD_CR_FFDC::L2LdCrFfdc ldcrffdc;

    // Get the maximum number of line deletes allowed and add to FFDC.
    uint16_t l_maxLineDelAllowed = mfgMode()
            ? getSystemTarget()->getAttr<ATTR_MNFG_TH_P8EX_L2_LINE_DELETES>()
            : getSystemTarget()->getAttr<ATTR_FIELD_TH_P8EX_L2_LINE_DELETES>();

    ldcrffdc.L2LDMaxAllowed = l_maxLineDelAllowed;

    do
    {
        p9_l2err_extract_err_data errorAddr =
            { L2ERR_CE_UE, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        if (SUCCESS != extractL2Err(trgt, true, errorAddr))
        {
            PRDF_ERR("[L2CE] HUID: 0x%08x extractL2Err failed", huid);
            break;
        }

        PRDF_TRAC( "[L2CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d macro=%d ow_select=%x bitline=%x is_top_sa=%x "
                   "is_left_sa=%x addr=%x",
                   huid, errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.macro, errorAddr.ow_select,
                   errorAddr.bitline, errorAddr.is_top_sa,
                   errorAddr.is_left_sa, errorAddr.address );

        ldcrffdc.L2errMember    = errorAddr.member;
        ldcrffdc.L2errDW        = errorAddr.dw;
        ldcrffdc.L2errMacro     = errorAddr.macro;
        ldcrffdc.L2errBank      = errorAddr.bank;
        ldcrffdc.L2errOWSelect  = errorAddr.ow_select;
        ldcrffdc.L2errBitLine   = errorAddr.bitline;
        ldcrffdc.L2errIsTopSA   = errorAddr.is_top_sa;
        ldcrffdc.L2errIsLeftSA  = errorAddr.is_left_sa;
        ldcrffdc.L2errAddress   = errorAddr.address;

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
            io_sc.service_data->SetErrorSig(PRDFSIG_P9EX_L2CE_LD_FAILURE);
            io_sc.service_data->SetThresholdMaskId(0);
            break; // nothing more to do
        }

        // The line delete was successful applied.
        l_bundle->iv_L2LDCount++;
        io_sc.service_data->SetErrorSig(PRDFSIG_P9EX_L2CE_LD_ISSUED);

        // Check if the line delete threshold has been reached.
        if (l_maxLineDelAllowed <= l_bundle->iv_L2LDCount)
        {
            PRDF_INF("[L2CE] HUID: 0x%08x line delete threshold reached", huid);
            io_sc.service_data->SetThresholdMaskId(0);
            break; // nothing more to do
        }

    } while(0);

    // The line delete count may, or may not, have been updated. Regardless, add
    // the latest value to the FFDC.
    ldcrffdc.L2LDcnt = l_bundle->iv_L2LDCount;

    // Finally, add the FFDC to the SDC.
    addL2LdCrFfdc(i_chip, io_sc, ldcrffdc);

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, L2CE );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, L2CE );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L2CE );

/**
 * @brief Handle an L3 CE
 * @param i_chip Ex chip.
 * @param io_sc Step Code data struct
 * @return PRD return code
 */
int32_t L3CE( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc )
{
    #ifdef __HOSTBOOT_RUNTIME

    P9ExDataBundle* l_bundle = getExDataBundle(i_chip);
    auto trgt = i_chip->getTrgt();
    auto huid = i_chip->getHuid();

    // FFDC will be collected throughout function and added to SDC at the end.
    LD_CR_FFDC::L3LdCrFfdc ldcrffdc;

    // Get the maximum number of line deletes allowed and add to FFDC.
    uint16_t l_maxLineDelAllowed = mfgMode()
            ? getSystemTarget()->getAttr<ATTR_MNFG_TH_P8EX_L3_LINE_DELETES>()
            : getSystemTarget()->getAttr<ATTR_FIELD_TH_P8EX_L3_LINE_DELETES>();

    ldcrffdc.L3LDMaxAllowed = l_maxLineDelAllowed;

    do
    {
        uint16_t curMem = 0xFFFF;

        p9_l3err_extract_err_data errorAddr =
            { L3ERR_CE_UE, 0, 0, 0, 0, 0, 0 };

        // Get failing location from trace array
        if (SUCCESS != extractL3Err(trgt, errorAddr))
        {
            PRDF_ERR("[L3CE] HUID: 0x%08x extractL3Err failed", huid);
            break;
        }

        PRDF_TRAC( "[L3CE] HUID: 0x%08x Error data: member=%d dw=%d "
                   "bank=%d dataout=%d hashed addr=%x cache addr=%x",
                   huid, errorAddr.member, errorAddr.dw,
                   errorAddr.bank, errorAddr.dataout,
                   errorAddr.hashed_real_address_45_56,
                   errorAddr.cache_read_address );

        ldcrffdc.L3errMember       = errorAddr.member;
        ldcrffdc.L3errDW           = errorAddr.dw;
        ldcrffdc.L3errBank         = errorAddr.bank;
        ldcrffdc.L3errDataOut      = errorAddr.dataout;
        ldcrffdc.L3errHshAddress   = errorAddr.hashed_real_address_45_56;
        ldcrffdc.L3errCacheAddress = errorAddr.cache_read_address;

        curMem = errorAddr.member;

        // Check for multi-bitline fail
        Timer curTime = io_sc.service_data->GetTOE();
        uint16_t prvMem = l_bundle->iv_prevMember;

        if ( prvMem != 0xFFFF && // we have data saved from a previous LD
             l_bundle->iv_blfTimeout > curTime && // the timer has not expired
             prvMem != curMem ) // the current fail is on a different bitline
        {
            // We have multiple bit lines failing within a 24 hour period
            // Make this predictive
            PRDF_INF("[L3CE] HUID: 0x%08x Multi-bitline fail detected", huid);
            io_sc.service_data->SetErrorSig(PRDFSIG_P9EX_L3CE_MBF_FAIL);
            io_sc.service_data->SetThresholdMaskId(0);
            break; // nothing more to do
        }

        // Update saved bitline data
        l_bundle->iv_prevMember = curMem;
        l_bundle->iv_blfTimeout = curTime + Timer::SEC_IN_DAY;

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

        // Execute the line delete
        int32_t l_rc = SUCCESS;
        if ( MODEL_NIMBUS != getChipModel(i_chip->getTrgt()) ||
             0x10         != getChipLevel(i_chip->getTrgt()) )
        {
            PRDF_INF("[L3CE] HUID: 0x%08x applying line delete", huid);
            l_rc = l3LineDelete(trgt, errorAddr);
        }
        else
        {
            // HW bug affecting directed line delete on NIMBUS 1.0
            // So set delete-on-next-ce instead

            SCAN_COMM_REGISTER_CLASS * prgReg =
                               i_chip->getRegister("L3_PURGE_REG");

            prgReg->clearAllBits();
            prgReg->SetBit(5);

            l_rc = prgReg->Write();
        }

        if (SUCCESS != l_rc)
        {
            PRDF_ERR("[L3CE] HUID: 0x%08x l3LineDelete failed", huid);
            io_sc.service_data->SetErrorSig(PRDFSIG_P9EX_L3CE_LD_FAILURE);
            io_sc.service_data->SetThresholdMaskId(0);
            break; // nothing more to do
        }

        // The line delete was successful applied.
        l_bundle->iv_L3LDCount++;
        io_sc.service_data->SetErrorSig(PRDFSIG_P9EX_L3CE_LD_ISSUED);

        // Check if the line delete threshold has been reached.
        if (l_maxLineDelAllowed <= l_bundle->iv_L3LDCount)
        {
            PRDF_INF("[L3CE] HUID: 0x%08x line delete threshold reached", huid);
            io_sc.service_data->SetThresholdMaskId(0);
            break; // nothing more to do
        }

    } while(0);

    // The line delete count may, or may not, have been updated. Regardless, add
    // the latest value to the FFDC.
    ldcrffdc.L3LDcnt = l_bundle->iv_L3LDCount;

    // Finally, add the FFDC to the SDC.
    addL3LdCrFfdc(i_chip, io_sc, ldcrffdc);

    #endif // __HOSTBOOT_RUNTIME

    return SUCCESS;

}
PRDF_PLUGIN_DEFINE_NS( nimbus_ex,  Ex, L3CE );
PRDF_PLUGIN_DEFINE_NS( cumulus_ex, Ex, L3CE );
PRDF_PLUGIN_DEFINE_NS( axone_ex,   Ex, L3CE );

}
}
