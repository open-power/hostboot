/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemThresholds.H $       */
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

#ifndef __PRDF_MEM_THRESHOLDS_H
#define __PRDF_MEM_THRESHOLDS_H

/** @file  prdfMemThresholds.H
 *  @brief Utility functions used to get specific memory thresholds.
 */

#include <prdfThresholdResolutions.H>
#include <prdfMemAddress.H>

namespace PRDF
{

class ExtensibleChip;

/**
 * @brief  Returns number of allowed CEs for MNFG IPLs.
 * @pre    Must check if in manufacturing mode before calling this function.
 * @post   Must callout if the count is greater than the returned values.
 * @param  i_chip      OCMB chip.
 * @param  i_rank      The rank for which the threshold is needed.
 * @param  o_cePerDram CEs allowed per DRAM.
 * @param  o_cePerRank CEs allowed per rank per logical DIMM.
 * @param  o_cePerDimm CEs allowed per logical DIMM.
 */
template <TARGETING::TYPE T>
void getMnfgMemCeTh( ExtensibleChip * i_chip, const MemRank & i_rank,
                     uint32_t & o_cePerDram, uint32_t & o_cePerRank,
                     uint32_t & o_cePerDimm );

#ifdef __HOSTBOOT_MODULE

/**
 * @brief Returns IUE threshold policy.
 */
ThresholdResolution::ThresholdPolicy getIueTh();

/**
 * @brief Returns IMPE threshold policy.
 */
ThresholdResolution::ThresholdPolicy getImpeTh();

#endif

} // end namespace PRDF

#endif /* __PRDF_MEM_THRESHOLDS_H */

