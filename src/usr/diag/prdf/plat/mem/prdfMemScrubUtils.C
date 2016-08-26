/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemScrubUtils.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

/** @file  prdfMemScrubUtils.C
 *  @brief Define the functionality necessary to start initial background scrub
 */

// Framework includes
#include <prdfMemScrubUtils.H>
#include <prdfExtensibleChip.H>
#include <prdfGlobal.H>
#include <prdfPlatServices.H>
#include <prdfTrace.H>
#include <fapi2.H>
#include <prdfTargetServices.H>
#include <prdfRegisterCache.H>
#include <lib/mcbist/memdiags.H>

using namespace TARGETING;

namespace PRDF
{
using namespace PlatServices;

template<>
int32_t clearCmdCompleteAttn<TYPE_MCBIST>(ExtensibleChip* i_mcbChip)
{
    #define PRDF_FUNC "[PRDF::clearCmdCompleteAttn<TYPE_MCBIST>] "

    int32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * mcbFirAnd =
        i_mcbChip->getRegister("MCBISTFIR_AND");
    mcbFirAnd->setAllBits();

    mcbFirAnd->ClearBit(10); // Maint cmd complete
    mcbFirAnd->ClearBit(12); // Maint cmd WAT workaround for sf commands

    if ( SUCCESS != mcbFirAnd->Write() )
    {
        PRDF_ERR ( PRDF_FUNC "Write() failed on MCBISTFIR_AND" );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
int32_t clearCmdCompleteAttn<TYPE_MBA>(ExtensibleChip* i_mbaChip)
{
    #define PRDF_FUNC "[PRDF::clearCmdCompleteAttn<TYPE_MBA>] "

    int32_t o_rc = SUCCESS;

    SCAN_COMM_REGISTER_CLASS * mbaSpaAnd = i_mbaChip->getRegister("MBASPA_AND");
    mbaSpaAnd->setAllBits();

    mbaSpaAnd->ClearBit(0); // Maint cmd complete
    mbaSpaAnd->ClearBit(8); // Maint cmd complete (DD1.0 workaround)

    if ( SUCCESS != mbaSpaAnd->Write() )
    {
        PRDF_ERR( PRDF_FUNC "Write() failed on MBASPA_AND" );
        o_rc = FAIL;
    }

    return o_rc;

    #undef PRDF_FUNC
}

template<>
int32_t clearEccCounters<TYPE_MCBIST>(ExtensibleChip* i_mcbChip)
{
    #define PRDF_FUNC "[PRDF::clearEccCounters<TYPE_MCBIST>] "
    int32_t o_rc = SUCCESS;

    do
    {
        SCAN_COMM_REGISTER_CLASS * mcbcntl =
            i_mcbChip->getRegister( "MCB_CNTL" );

        o_rc = mcbcntl->ForceRead();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "ForceRead() failed on MCB_CNTL" );
            break;
        }

        mcbcntl->SetBit(7); // Setting this bit clears all counters.

        o_rc = mcbcntl->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCB_CNTL" );
            break;
        }

        // Hardware automatically clears bit 7, so flush this register out
        // of the register cache to avoid clearing the counters again with
        // a write from the out-of-date cached copy.
        RegDataCache & cache = RegDataCache::getCachedRegisters();
        cache.flush( i_mcbChip, mcbcntl );

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
int32_t clearEccCounters<TYPE_MBA>(ExtensibleChip* i_mbaChip)
{
    #define PRDF_FUNC "[PRDF::clearEccCounters<TYPE_MBA>] "
    int32_t o_rc = SUCCESS;
    const char* reg_str = nullptr;

    TARGETING::TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {

        uint32_t mbaPos = getTargetPosition(mbaTrgt);
        reg_str = (0 == mbaPos) ? "MBA0_MBSTR" : "MBA1_MBSTR";
        SCAN_COMM_REGISTER_CLASS * mbstr = i_mbaChip->getRegister( reg_str );

        // MBSTR's content could be modified from cleanupCmd()
        // so we need to refresh
        o_rc = mbstr->ForceRead();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "ForceRead() failed on %s", reg_str );
            break;
        }

        mbstr->SetBit(53); // Setting this bit clears all counters.

        o_rc = mbstr->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

        // Hardware automatically clears bit 53, so flush this register out
        // of the register cache to avoid clearing the counters again with
        // a write from the out-of-date cached copy.
        RegDataCache & cache = RegDataCache::getCachedRegisters();
        cache.flush( i_mbaChip, mbstr );

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
int32_t clearEccFirs<TYPE_MCBIST>(ExtensibleChip* i_mcbChip)
{
    #define PRDF_FUNC "[PRDF::clearEccFirs<TYPE_MCBIST>] "

    int32_t o_rc = SUCCESS;

    TARGETING::TargetHandle_t mcbTrgt = i_mcbChip->GetChipHandle();

    do
    {
        //clear MCBISTFIR - bits 5-9
        SCAN_COMM_REGISTER_CLASS * mcbFirAnd =
            i_mcbChip->getRegister("MCBISTFIR_AND");
        mcbFirAnd->setAllBits();

        mcbFirAnd->SetBitFieldJustified( 5, 5, 0 );

        o_rc = mcbFirAnd->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MCBISTFIR_AND" );
            break;
        }

        //clear MCAECCFIR - bits 20-34, 36-37, and 39
        //iterate through all MCAs
        for ( uint32_t mcaPos = 0; mcaPos < MAX_PORT_PER_MCBIST ; mcaPos++ )
        {
            TargetHandle_t mcaTrgt =
                getConnectedChild( mcbTrgt, TYPE_MCA, mcaPos );
            if ( nullptr == mcaTrgt )
            {
                PRDF_ERR ( PRDF_FUNC "Failed to get mcaTrgt" );
                continue;
            }
            ExtensibleChip * mcaChip =
                (ExtensibleChip*)systemPtr->GetChip(mcaTrgt);

            SCAN_COMM_REGISTER_CLASS * mcaEccFirAnd =
                mcaChip->getRegister("MCAECCFIR_AND");
            mcaEccFirAnd->setAllBits();

            mcaEccFirAnd->SetBitFieldJustified( 20, 15, 0 );
            mcaEccFirAnd->SetBitFieldJustified( 36, 2, 0 );
            mcaEccFirAnd->ClearBit(39);

            o_rc = mcaEccFirAnd->Write();
            if ( SUCCESS != o_rc )
            {
                PRDF_ERR( PRDF_FUNC "Write() failed on MCAECCFIR_AND" );
                break;
            }
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

template<>
int32_t clearEccFirs<TYPE_MBA>(ExtensibleChip* i_mbaChip)
{
    #define PRDF_FUNC "[PRDF::clearEccFirs<TYPE_MBA>] "

    int32_t o_rc = SUCCESS;
    const char* reg_str = nullptr;

    TARGETING::TargetHandle_t mbaTrgt = i_mbaChip->GetChipHandle();

    do
    {
        uint32_t mbaPos = getTargetPosition(mbaTrgt);
        reg_str = (0 == mbaPos) ? "MBA0_MBSECCFIR_AND"
            : "MBA1_MBSECCFIR_AND";

        TargetHandle_t membTrgt = getConnectedParent(mbaTrgt, TYPE_MEMBUF);
        if (nullptr == membTrgt)
        {
            PRDF_ERR ( PRDF_FUNC "Failed to get membTrgt" );
            o_rc = FAIL;
            break;
        }
        ExtensibleChip * membChip =
            (ExtensibleChip*)systemPtr->GetChip(membTrgt);
        SCAN_COMM_REGISTER_CLASS * firand = membChip->getRegister(reg_str);
        firand->setAllBits();

        // Clear all scrub MPE bits.
        // This will need to be done when starting a TD procedure or bg
        // scrubbing. rank may not be set when starting background scrubbing
        // and technically there should only be one of the MPE bits on at a
        // time so we should not have to worry about losing an attention by
        // clearing them all.
        firand->SetBitFieldJustified( 20, 8, 0 );

        // Clear scrub NCE, SCE, MCE, RCE, SUE, UE bits (36-41)
        firand->SetBitFieldJustified( 36, 6, 0 );

        o_rc = firand->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on %s", reg_str );
            break;
        }

        SCAN_COMM_REGISTER_CLASS * spaAnd =
            i_mbaChip->getRegister("MBASPA_AND");
        spaAnd->setAllBits();

        // Clear threshold exceeded attentions
        spaAnd->SetBitFieldJustified( 1, 4, 0 );

        o_rc = spaAnd->Write();
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "Write() failed on MBASPA_AND" );
            break;
        }

    } while(0);

    return o_rc;

    #undef PRDF_FUNC
}

} //end namespace PRDF
