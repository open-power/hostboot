/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef prdfCalloutUtil_H
#define prdfCalloutUtil_H

/** @file  prdfCalloutUtil.H
 *  @brief Utility functions for common, non-trivial callouts.
 */

#include <prdfPlatServices.H>

#include <prdfCallouts.H>
#include <prdfCenMemUtils.H>

namespace PRDF
{

class CenMark;
class CenRank;
struct STEP_CODE_DATA_STRUCT;

namespace CalloutUtil
{

/**
 * @brief In many cases, an internal logic error may occur in which 2nd level
 *        support and FSP code need to be called out. This function is intended
 *        to help eliminate the need to constantly repeat the list of callouts.
 * @param i_sc The step code data struct.
 */
void defaultError( STEP_CODE_DATA_STRUCT & i_sc );

/**
 * @brief Will add a MemoryMru to the callout list for the chip mark and symbol
 *        mark, if they exist.
 * @param i_mba      Target MBA.
 * @param i_rank     Target rank.
 * @param i_mark     Target mark.
 * @param io_sc      The step code data struct.
 * @param i_priority Callout priority (default MRU_MED).
 */
void calloutMark( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                  const CenMark & i_mark, STEP_CODE_DATA_STRUCT & io_sc,
                  PRDpriority i_priority = MRU_MED );

/**
 * @brief Will add all DIMMs with symbols that exist in the given list to the
 *        callout list.
 * @note  We cannot just callout a MemoryMru for each symbol because there could
 *        be a lot more symbols in the list than we have room for in the PFA
 *        data section in the error log.
 * @param i_mba      Target MBA.
 * @param i_rank     Target rank.
 * @param i_symData  The list of symbols.
 * @param io_sc      The step code data struct.
 * @param i_priority Callout priority (default MRU_MED).
 */
void calloutSymbolData( TARGETING::TargetHandle_t i_mba, const CenRank & i_rank,
                        const MemUtils::MaintSymbols & i_symData,
                        STEP_CODE_DATA_STRUCT & io_sc,
                        PRDpriority i_priority = MRU_MED );

/**
 * @param  i_mba  The target MBA.
 * @param  i_rank The target rank.
 * @return A list of DIMMs connected to the MBA and rank.
 */
TARGETING::TargetHandleList getConnectedDimms( TARGETING::TargetHandle_t i_mba,
                                               const CenRank & i_rank );

/**
 * @param  i_mba The target MBA.
 * @return A list of DIMMs connected to the MBA.
 */
TARGETING::TargetHandleList getConnectedDimms(TARGETING::TargetHandle_t i_mba);

/**
 * @param  i_mba  The target MBA.
 * @param  i_rank The target rank.
 * @param  i_port MBA port.
 * @return A list of DIMMs connected to the MBA and rank on a port.
 */
TARGETING::TargetHandleList getConnectedDimms( TARGETING::TargetHandle_t i_mba,
                                               const CenRank & i_rank,
                                               uint8_t i_port );

/**
 * @param  i_mba  The target MBA.
 * @param  i_port MBA port.
 * @return A list of DIMMs connected to the MBA on given port.
 */
TARGETING::TargetHandleList getConnectedDimms( TARGETING::TargetHandle_t i_mba,
                                               uint8_t i_port );

/**
 * @brief Will return the bus endpoint targets based in the given information.
 *
 *   Supported configurations:
 *     i_chip     i_busType       i_busPos      o_rxTrgt        o_txTrgt
 *     ------     -----------     --------      -------------   -------------
 *     PROC       TYPE_ABUS       0-2           ABUS target     ABUS target
 *     PROC       TYPE_XBUS       0-3           XBUS target     XBUS target
 *     PROC       TYPE_MCS        0-7           MCS target      MEMBUF target
 *     MCS        n/a             n/a           MCS target      MEMBUF target
 *     MEMBUF     n/a             n/a           MEMBUF target   MCS target
 *
 * @param i_chip     Chip or unit on the RX side of the bus.
 * @param o_rxTrgt   The RX target, NULL on failure.
 * @param o_txTrgt   The TX target, NULL on failure.
 * @param i_busType  Bus type.
 * @param i_busPos   Bus position.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 *
 */
int32_t getBusEndpoints( ExtensibleChip * i_chip,
                         TARGETING::TargetHandle_t o_rxTrgt,
                         TARGETING::TargetHandle_t o_txTrgt,
                         TARGETING::TYPE i_busType = TARGETING::TYPE_NA,
                         uint32_t i_busPos = 0 );

/**
 * @brief  Will add target bus interface endpoints and all parts in between the
 *         endpoints to the global error log in RasServices.
 * @param  i_rxTrgt   The RX target.
 * @param  i_txTrgt   The TX target.
 * @param  i_priority Callout priority (default MRU_LOW).
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
int32_t calloutBusInterface( TARGETING::TargetHandle_t i_rxTrgt,
                             TARGETING::TargetHandle_t i_txTrgt,
                             PRDpriority i_priority = MRU_LOW );

/**
 * @brief  Will add target bus interface endpoints and all parts in between the
 *         endpoints to the global error log in RasServices.
 * @note   See function getBusEndpoints() for parameter rules.
 * @param  i_chip     Chip or unit on the RX side of the bus.
 * @param  i_priority Callout priority (default MRU_LOW).
 * @param  i_busType  Bus type.
 * @param  i_busPos   Bus position.
 * @return Non-SUCCESS if an internal function fails. SUCCESS otherwise.
 */
int32_t calloutBusInterface( ExtensibleChip * i_chip,
                             PRDpriority i_priority = MRU_LOW,
                             TARGETING::TYPE i_busType = TARGETING::TYPE_NA,
                             uint32_t i_busPos = 0 );

} // end namespace CalloutUtil

} // end namespace PRDF

#endif // prdfCalloutUtil_H
