/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/runtime/prdfCenMbaDynMemDealloc_rt.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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

#ifndef __prdfCenMbaDynMemDealloc_rt_H
#define __prdfCenMbaDynMemDealloc_rt_H

/** @file  prdfCenMbaDynMemDealloc_rt.H
 *  @brief Support functions for Dynamic Memory Deallocation
 */

namespace PRDF
{

class ExtensibleChip;
class CenAddr;

namespace DEALLOC
{

/**
 * @return True, if Dynamic Memory Deallocation is enabled. False, otherwise.
 */
bool isEnabled();

/**
 * @brief  Sends a page gard message to PHYP.
 * @param  i_mbaChip MBA chip
 * @param  i_addr   The address to page gard.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t pageGard( ExtensibleChip * i_mbaChip, CenAddr i_addr );

/**
 * @brief  Sends a LMB gard message to PHYP.
 * @param  i_mbaChip MBA chip
 * @param  i_addr    The address to lmb gard.
 * @param  i_isFetch TRUE if we are calling this because of FETCH UE,
 *                   FALSE otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t lmbGard( ExtensibleChip * i_mbaChip, CenAddr i_addr,
                 bool i_isFetch = true);

/**
 * @brief  Sends a message to PHYP to gard all memory behind MBA.
 * @param  i_mbaChip MBA chip
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t mbaGard( ExtensibleChip * i_mbaChip );

/**
 * @brief  Sends a message to PHYP to gard all memory behind dimm List.
 * @param  i_dimmList DIMM list
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t dimmListGard( TARGETING::TargetHandleList & i_dimmList );

/**
 * @brief  Sends a message to PHYP to gard all memory behind dimm slct.
 * @param  i_dimm Memory DIMM.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t dimmSlctGard( TARGETING::TargetHandle_t  i_dimm );

} //namespace DEALLOC
} // namespace PRDF
//------------------------------------------------------------------------------


#endif /* __prdfCenMbaDynMemDealloc_rt_H */

