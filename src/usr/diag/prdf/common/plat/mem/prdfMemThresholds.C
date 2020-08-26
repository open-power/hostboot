/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemThresholds.C $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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

/** @file  prdfMemThresholds.C
 *  @brief Utility functions used to get specific memory thresholds.
 */

// Framework includes
#include <prdfExtensibleChip.H>
#include <prdfMfgThresholdMgr.H>
#include <prdfPlatServices.H>

// Platform includes
#include <prdfMemThresholds.H>
#include <prdfMemUtils.H>

using namespace TARGETING;

namespace PRDF
{

using namespace PlatServices;

enum DefaultThresholds
{
    RCD_PARITY_NON_MNFG_TH     = 32, ///< Non-MNFG RCD parity error TH
    IMPE_NON_MNFG_TH           = 32, ///< Non-MNFG IMPE TH
    IUE_NON_MNFG_TH            = 8,  ///< Non-MNFG IUE TH
    MBA_RCE_NON_MNFG_TH        = 8,  ///< Non-MNFG RCE TH
};

//------------------------------------------------------------------------------

/**
 * @brief  Returns the manufacturing memory CE thresholds Per 2GB ( base ).
 */
uint8_t getMnfgCeTh()
{
    #ifndef __HOSTBOOT_RUNTIME

    return MfgThresholdMgr::getInstance()->
            getThreshold( TARGETING::ATTR_MNFG_TH_MEMORY_IPL_SOFT_CE_TH_ALGO );

    #else

    return MfgThresholdMgr::getInstance()->
            getThreshold( TARGETING::ATTR_MNFG_TH_MEMORY_RT_SOFT_CE_TH_ALGO );

    #endif

}

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

ThresholdResolution::ThresholdPolicy getRcdParityTh()
{
    uint32_t th = RCD_PARITY_NON_MNFG_TH;

    if ( mfgMode() )
    {
        th = MfgThresholdMgr::getInstance()->
                            getThreshold(ATTR_MNFG_TH_MEMORY_RCD_PARITY_ERRORS);
    }

    return ThresholdResolution::ThresholdPolicy( th,
                                                 ThresholdResolution::ONE_DAY );
}

#endif

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

ThresholdResolution::ThresholdPolicy getIueTh()
{
    uint32_t th = IUE_NON_MNFG_TH;

    if ( mfgMode() )
    {
        th = MfgThresholdMgr::getInstance()->
                                         getThreshold(ATTR_MNFG_TH_MEMORY_IUES);
    }

    return ThresholdResolution::ThresholdPolicy( th,
                                                 ThresholdResolution::ONE_DAY );
}

#endif

//------------------------------------------------------------------------------

#ifdef __HOSTBOOT_MODULE

ThresholdResolution::ThresholdPolicy getImpeTh()
{
    uint32_t th = IMPE_NON_MNFG_TH;

    // NOTE: We will only use the MNFG threshold if DRAM repairs is disabled.
    if ( areDramRepairsDisabled() )
    {
        th = MfgThresholdMgr::getInstance()->
                           getThreshold( ATTR_MNFG_TH_MEMORY_IMPES );
    }

    return ThresholdResolution::ThresholdPolicy( th,
                                                 ThresholdResolution::ONE_DAY );
}

#endif

//------------------------------------------------------------------------------

ThresholdResolution::ThresholdPolicy getRceThreshold()
{
    uint32_t th = MBA_RCE_NON_MNFG_TH;

    if ( mfgMode() )
    {
        th = MfgThresholdMgr::getInstance()->
                           getThreshold( ATTR_MNFG_TH_MEMORY_RT_RCE_PER_RANK );

        if( th > MBA_RCE_NON_MNFG_TH ) th = MBA_RCE_NON_MNFG_TH;
    }

    return ThresholdResolution::ThresholdPolicy( th,
                                                 ThresholdResolution::ONE_DAY );
}

//------------------------------------------------------------------------------

template <TYPE T>
void getMnfgMemCeTh( ExtensibleChip * i_chip, const MemRank & i_rank,
                     uint32_t & o_cePerDram, uint32_t & o_cePerRank,
                     uint32_t & o_cePerDimm )
{
    // Get base threshold ( 2GB ).
    uint8_t baseTh = getMnfgCeTh();

    // A base threhold of 0 indicates there should be no thresholding.
    if ( 0 == baseTh )
    {
        o_cePerDram = o_cePerRank = o_cePerDimm =
            MfgThreshold::INFINITE_LIMIT_THR;
    }
    else
    {
        // Note: Support for larger DRAM sizes has caused a re-evaluation of
        // the MNFG memory CE thresholds. It has been determined that there
        // isn't actually a need to adjust the threshold based on DRAM size.
        // As such we will just use the same threshold for all DRAM densities,
        // using the baseline thresholds of a 4Gb DRAM. The calculations below
        // have been left intact in case we need to reinstate the adjustments
        // based on DRAM size and because the per DIMM threshold still needs
        // to be calculated based on the number of ranks per dimm.
        uint8_t size = 4;

        // Get number of ranks per DIMM select.
        uint8_t rankCount = getNumRanksPerDimm<T>( i_chip->getTrgt(),
                                                   i_rank.getDimmSlct() );
        PRDF_ASSERT( 0 != rankCount ); // Code bug.

        // Get number of allowed CEs.
        uint8_t baseAllowed = baseTh - 1;

        // Calculate CEs per DRAM.
        //      (base * dram size) * (9/16)
        uint32_t computeBase = baseAllowed * size * 9;
        o_cePerDram = (computeBase + 8) / 16;

        // Calculate CEs per DIMM.
        //      (base * dram size) * (2 + rank count) * (9/16)
        o_cePerDimm = ((computeBase * (2 + rankCount)) + 8) / 16;

        // Calculate CEs per rank per DIMM.
        //      Same as per DIMM where rank count is 1
        o_cePerRank = ((computeBase * (2 + 1)) + 8) / 16;
    }
}

// need these templates to avoid linker errors
template
void getMnfgMemCeTh<TYPE_OCMB_CHIP>( ExtensibleChip * i_chip,
    const MemRank & i_rank, uint32_t & o_cePerDram, uint32_t & o_cePerRank,
    uint32_t & o_cePerDimm );

} // end namespace PRDF

