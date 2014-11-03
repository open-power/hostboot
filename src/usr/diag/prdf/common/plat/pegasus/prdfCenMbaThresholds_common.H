/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCenMbaThresholds_common.H $ */
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

#ifndef __PRDF_CEN_MBA_COMMON_THRESHOLDS_H
#define __PRDF_CEN_MBA_COMMON_THRESHOLDS_H

/** @file  prdfCenMbaThresholds_common.H
 *  @brief Utility functions used to get specific Centaur thresholds.
 */

#include <prdfThresholdResolutions.H>
#include <prdfCenAddress.H>

namespace PRDF
{

class ExtensibleChip;

/**
 * @brief  Returns number of allowed CEs for MNFG IPLs.
 * @pre    Must check if in manufacturing mode before calling this function.
 * @post   Must callout if the count is greater than the returned values.
 * @param  i_mbaChip       MBA chip.
 * @param  i_rank          The rank for which the threshold is needed.
 * @param  o_cePerDram     CEs allowed per DRAM.
 * @param  o_cePerHalfRank CEs allowed per logical DIMM rank.
 * @param  o_cePerDimm     CEs allowed per logical DIMM.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getMnfgMemCeTh( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                        uint16_t & o_cePerDram, uint16_t & o_cePerHalfRank,
                        uint16_t & o_cePerDimm );

/**
 * @brief  Returns RCE threshold policy.
 */
ThresholdResolution::ThresholdPolicy getRceThreshold();

/**
 * @brief  Returns scrub soft/intermittent CEs threshold during runtime.
 * @param  i_mbaChip MBA chip.
 * @param  i_rank    The rank for which the threshold is needed.
 * @param  o_thr     Scrub soft/intermittent CE threshold.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t getScrubCeThreshold( ExtensibleChip * i_mbaChip, const CenRank & i_rank,
                             uint16_t & o_thr );

} // end namespace PRDF

#endif /* __PRDF_CEN_MBA_COMMON_THRESHOLDS_H */

