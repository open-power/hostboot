/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemEccAnalysis.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#ifndef __prdfMemEccAnalysis_H
#define __prdfMemEccAnalysis_H

// Framework includes
#include <iipServiceDataCollector.h>
#include <prdfExtensibleChip.H>

// Platform includes
#include <prdfMemRank.H>
#include <prdfPlatServices.H>
#include <prdfMemMark.H>

#ifdef __HOSTBOOT_MODULE
  #include <prdfMemTps.H>
  #include <prdfMemVcm.H>
  #include <prdfP9McbistDataBundle.H>
#endif

namespace PRDF
{

namespace MemEcc
{

/**
 * @brief  Will check if the UE is a side-effect attention and make a callout
 *         appropriately.
 * @param  i_chip   MCA or MBA.
 * @param  i_rank   Target rank.
 * @param  io_sc    The step code data struct.
 */
template<TARGETING::TYPE T>
void calloutMemUe( ExtensibleChip * i_chip, const MemRank & i_rank,
                   STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch MPE attention.
 * @param  i_chip   MCA or MBA.
 * @param  i_rank   Target rank.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchMpe( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch NCE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchNce( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch TCE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchTce( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch UE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeFetchUe( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch mainline IUE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeMainlineIue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc );


/**
 * @brief  Analyzes a fetch maint IUE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeMaintIue( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a maint or mainline IMPE attention.
 * @param  i_chip   MCA or MBA.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t analyzeImpe( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc );

#ifdef __HOSTBOOT_RUNTIME

/**
 * @brief  Will trigger a port fail if the number of IUEs is over threshold
 * @param  i_chip   MCA chip
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
 */
uint32_t iuePortFail(ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc);

#endif // __HOSTBOOT_RUNTIME

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Will mask off the entire mem port
 * @param  i_chip   MCA chip
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
 */
uint32_t maskMemPort( ExtensibleChip * i_chip );

template<TARGETING::TYPE T, typename D>
uint32_t addVcmEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                      const MemMark & i_mark, STEP_CODE_DATA_STRUCT & io_sc );

template<TARGETING::TYPE T, typename D>
uint32_t addTpsEvent( ExtensibleChip * i_chip, const MemRank & i_rank,
                      STEP_CODE_DATA_STRUCT & io_sc, bool i_banTps = false );

#endif

} // end namespace MemEcc

} // end namespace PRDF

#endif // __prdfMemEccAnalysis_H

