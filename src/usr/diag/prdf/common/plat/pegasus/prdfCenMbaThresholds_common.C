/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaThresholds_common.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
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

/** @file  prdfCenMbaThresholds_common.C
 *  @brief Utility functions used to get specific Centaur thresholds.
 */

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfMfgThresholds.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfPlatServices.H>

// Pegasus includes
#include <prdfCenMbaThresholds.H>
#include <prdfCenMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

// Non MNFG RCE threshold
static uint32_t MBA_RCE_NON_MNFG_TH = 8;

// Non MNFG Scrub soft/intermittent CE threshold
static uint32_t MBA_SCRUB_CE_NON_MNFG_TH = 80;

//------------------------------------------------------------------------------

ThresholdResolution::ThresholdPolicy getRceThreshold()
{
    uint32_t th = MBA_RCE_NON_MNFG_TH;

    if ( mfgMode() )
    {
        th = MfgThresholdMgr::getInstance()->
                                getThreshold( PRDF_CEN_MBA_RT_RCE_PER_RANK );

        if( th > MBA_RCE_NON_MNFG_TH ) th = MBA_RCE_NON_MNFG_TH;
    }

    return ThresholdResolution::ThresholdPolicy( th,
                                                 ThresholdResolution::ONE_DAY );
}

//------------------------------------------------------------------------------

int32_t getMnfgMemCeTh( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                        uint16_t & o_cePerDram, uint16_t & o_cePerHalfRank,
                        uint16_t & o_cePerDimm )
{
    #define PRDF_FUNC "[getMnfgMemCeTh] "

    int32_t o_rc = SUCCESS;

    do
    {
        // Get base threshold ( 2GB ).
        uint8_t baseTh = getMnfgCeTh();

        // A base threhold of 0 indicates there should be no thresholding.
        if ( 0 == baseTh )
        {
            o_cePerDram = o_cePerHalfRank = o_cePerDimm =
                                    MfgThresholdFileCommon::INFINITE_LIMIT_THR;
            break;
        }

        // Get DRAM size
        uint8_t size = 0;
        o_rc = MemUtils::getDramSize( i_mbaChip, size );
        if ( SUCCESS != o_rc )
        {
            PRDF_ERR( PRDF_FUNC "MemUtils::getDramSize() failed" );
            break;
        }

        // Get number of ranks per DIMM select.
        uint8_t rankCount = getRanksPerDimm( i_mbaChip->GetChipHandle(),
                                             i_rank.getDimmSlct() );
        if ( 0 == rankCount )
        {
            PRDF_ERR( PRDF_FUNC "PlatServices::getRanksPerDimm() failed" );
            o_rc = FAIL; break;
        }

        // Get number of allowed CEs.
        uint8_t baseAllowed = baseTh - 1;

        // Calculate CEs per DRAM.
        //   The DRAM size is in MBAXCR[6:7], where 0 = 2Gb, 1 = 4Gb, 2 = 8Gb,
        //   and 3 = 16 Gb. So the allowed CEs per DRAM can be calculated with
        //   the following:
        //         perDram = base * 2^(MBAXCR[6:7]+1) * (9/16)
        //     or, perDram = (base << MBAXCR[6:7]+1)  * (9/16)
        uint32_t computeBase = (baseAllowed << (size+1)) * 9;
        o_cePerDram = (computeBase + 8) / 16;

        // Calculate CEs per DIMM.
        o_cePerDimm = ((computeBase * (2 + rankCount)) + 8) / 16;

        // Calculate CEs per half-rank.
        // Same as perDimm where rankCount is 1;
        o_cePerHalfRank = ((computeBase * (2 + 1)) + 8) / 16;

    } while (0);

    return o_rc;

    #undef PRDF_FUNC
}

//------------------------------------------------------------------------------

int32_t getScrubCeThreshold( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                             uint16_t & o_thr )
{
    #define PRDF_FUNC "[getScrubCeThreshold] "

    int32_t o_rc = SUCCESS;

    o_thr = MBA_SCRUB_CE_NON_MNFG_TH;

    if ( mfgMode() )
    {
        uint16_t junk1 = 0;
        uint16_t junk2 = 0;

        o_rc = getMnfgMemCeTh( i_mbaChip, i_rank, o_thr, junk1, junk2 );
        if ( SUCCESS != o_rc )
            PRDF_ERR( PRDF_FUNC"getMnfgMemCeTh() failed" );

        // getMnfgMemCeTh() returns the number of CEs allowed. Will need to add
        // one to get the real threshold.
        o_thr++;
    }

    return o_rc;

    #undef PRDF_FUNC
}

} // end namespace PRDF

