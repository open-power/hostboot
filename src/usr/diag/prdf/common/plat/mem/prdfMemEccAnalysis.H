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
 * @brief  Adds the memory CE to the callout list and CE table. Will also issue
 *         dynamic memory deallocation when appropriate. Returns true if TPS is
 *         required.
 * @param  i_chip   MCA or MBA.
 * @param  i_addr   Failed address.
 * @param  i_symbol Failed symbol.
 * @param  o_doTps  True if TPS is required. False otherwise.
 * @param  io_sc    The step code data struct.
 * @param  i_isHard True if this is a hard CE. Default is false.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T, typename D>
uint32_t handleMemCe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                      const MemSymbol & i_symbol, bool & o_doTps,
                      STEP_CODE_DATA_STRUCT & io_sc, bool i_isHard = false );

/**
 * @brief  Adds the memory UE to the callout list and UE table. Makes the error
 *         log predictive. Will also issue dynamic memory deallocation when
 *         appropriate.
 *
 * For UEs on Nimbus chips, it is possible that this UE is a side-effect of
 * DDRPHY attentions. If so, the MCA will be added to the callout list instead
 * of the DIMMs, the UE table will not be updated and no dynamic memory
 * deallocation.
 *
 * @param  i_chip   MCA or MBA.
 * @param  i_addr   Failed address.
 * @param  i_type   The type of UE.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMemUe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                      UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc );

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

