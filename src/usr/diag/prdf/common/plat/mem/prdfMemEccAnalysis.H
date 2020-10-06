/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/mem/prdfMemEccAnalysis.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#endif

namespace PRDF
{

namespace MemEcc
{

/**
 * @brief  Adds the memory CE to the callout list and CE table. Will also issue
 *         dynamic memory deallocation when appropriate. Returns true if TPS is
 *         required.
 * @param  i_chip   OCMB.
 * @param  i_addr   Failed address.
 * @param  i_symbol Failed symbol.
 * @param  o_doTps  True if TPS is required. False otherwise.
 * @param  io_sc    The step code data struct.
 * @param  i_isHard True if this is a hard CE. Default is false.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMemCe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                      const MemSymbol & i_symbol, bool & o_doTps,
                      STEP_CODE_DATA_STRUCT & io_sc, bool i_isHard = false );

/**
 * @brief  Adds the memory UE to the callout list and UE table. Makes the error
 *         log predictive. Will also issue dynamic memory deallocation when
 *         appropriate.
 *
 * @param  i_chip   OCMB.
 * @param  i_addr   Failed address.
 * @param  i_type   The type of UE.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMemUe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                      UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief Does mainline and maintenance IUE handling.
 *
 * Adds the memory IUE to the callout list. At threshold, will make the error
 * log predictive. When threshold is reached at runtime there is a good chance
 * these IUEs are going to lead to a data integrity issue. Therefore, the port
 * will be forced to fail, the entire port will be masked off, and dynamic
 * memory deallocation will be applied. Note that this function will not issue
 * the port failure because it is possible that it may crash the host. Instead,
 * the port failure is issued in the PostAnalysis plugin after the error log has
 * been committed.
 *
 * @param  i_chip OCMB chip.
 * @param  i_rank Rank containing the IUE.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMemIue( ExtensibleChip * i_chip, const MemRank & i_rank,
                       STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Handles a MPE attention.
 * @param  i_chip OCMB.
 * @param  i_addr Failed address.
 * @param  i_type The type of UE.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMpe( ExtensibleChip * i_chip, const MemAddr & i_addr,
                    UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Handles a MPE attention.
 * @param  i_chip    OCMB.
 * @param  i_rank    Target rank.
 * @param  i_type    The type of UE.
 * @param  io_sc     The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t handleMpe( ExtensibleChip * i_chip, const MemRank & i_rank,
                    UE_TABLE::Type i_type, STEP_CODE_DATA_STRUCT & io_sc )
{
    MemAddr addr { i_rank, 0, 0, 0 };
    return handleMpe<T>( i_chip, addr, i_type, io_sc );
}

/**
 * @brief  Analyzes a fetch MPE attention.
 * @param  i_chip   OCMB.
 * @param  i_rank   Target rank.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeFetchMpe( ExtensibleChip * i_chip, const MemRank & i_rank,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch NCE/TCE attention.
 * @param  i_chip   OCMB.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeFetchNceTce( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch UE attention.
 * @param  i_chip   OCMB.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeFetchUe( ExtensibleChip * i_chip,
                         STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a fetch mainline IUE attention.
 * @param  i_chip   OCMB.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeMainlineIue( ExtensibleChip * i_chip,
                             STEP_CODE_DATA_STRUCT & io_sc );


/**
 * @brief  Analyzes a fetch maint IUE attention.
 * @param  i_chip   OCMB.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an interal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeMaintIue( ExtensibleChip * i_chip,
                          STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Analyzes a maint or mainline IMPE attention.
 * @param  i_chip   OCMB.
 * @param  io_sc    The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t analyzeImpe( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc );

#ifdef __HOSTBOOT_RUNTIME

/**
 * @brief  Will trigger a channel fail.
 * @param  i_chip OCMB chip
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
 */
template<TARGETING::TYPE T>
uint32_t triggerChnlFail( ExtensibleChip * i_chip );


#endif // __HOSTBOOT_RUNTIME

#ifdef __HOSTBOOT_MODULE

/**
 * @brief  Will query the data bundle and return if the IUE threshold has been
 *         reached.
 * @param  i_chip OCMB chip
 * @param  io_sc  The step code data struct.
 * @return True if IUE threshold is reached, false if not.
 */
template<TARGETING::TYPE T>
bool queryIueTh( ExtensibleChip * i_chip, STEP_CODE_DATA_STRUCT & io_sc );

/**
 * @brief  Will mask off an entire memory port. At runtime will issue dynamic
 *         memory deallocation of the port.
 * @param  i_chip OCMB chip
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise
 */
template<TARGETING::TYPE T>
uint32_t maskMemPort( ExtensibleChip * i_chip );

#endif

} // end namespace MemEcc

} // end namespace PRDF

#endif // __prdfMemEccAnalysis_H

