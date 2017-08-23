/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/mem/prdfMemDynDealloc.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#ifndef __prdfMemDynDealloc_H
#define __prdfMemDynDealloc_H

/** @file prdfMemDynDealloc.H
 *  @brief Support functions for Dynamic Memory Deallocation
 */

namespace PRDF
{

class ExtensibleChip;
class MemAddr;

namespace MemDealloc
{

/**
 * @return True, if Dynamic Memory Deallocation is enabled. False, otherwise.
 */
bool isEnabled();

/**
 * @brief  Sends message to hypervisor for page dealloc
 * @param  i_chip MBA/MCA chip
 * @param  i_addr   The address to page dealloc.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t page( ExtensibleChip * i_chip, MemAddr i_addr );

/**
 * @brief  Sends message to hypervisor to dealloc all memory on a rank
 * @param  i_chip MBA/MCA chip
 * @param  i_addr   The address to page dealloc.
 * @param  i_isFetch TRUE if we are calling this because of FETCH UE,
 *                   FALSE otherwise.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t rank( ExtensibleChip * i_chip, MemRank i_rank );

/**
 * @brief  Sends a message to hypervisor to dealloc all memory behind a port
 * @param  i_chip MBA/MCA chip
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t port( ExtensibleChip * i_chip );

/**
 * @brief  Sends a message to hypervisor to dealloc all memory behind dimm List.
 * @param  i_dimmList DIMM list
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
int32_t dimmList( TARGETING::TargetHandleList & i_dimmList );

/**
 * @brief  Sends a message to PHYP to dealloc all memory behind dimm slct.
 * @param  i_dimm Memory DIMM.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
int32_t dimmSlct( TARGETING::TargetHandle_t  i_dimm );

} //namespace MemDealloc
} // namespace PRDF
//------------------------------------------------------------------------------


#endif /* __prdfMemDynDealloc_H */

