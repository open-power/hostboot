/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/plat/pegasus/prdfCalloutUtil.H $     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef prdfCalloutUtil_H
#define prdfCalloutUtil_H

/** @file  prdfCalloutUtil.H
 *  @brief Utility functions for common, non-trivial callouts.
 */

#include <prdfPlatServices.H>

#include <prdfCallouts.H>

namespace PRDF
{

class CenMark;
class CenRank;
struct STEP_CODE_DATA_STRUCT;

namespace CalloutUtil
{

/**
 * @brief In many cases, an internal logic error may occur in which 2nd level
 *        support and FSP code need to be called out. This function is intented
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

} // end namespace CalloutUtil

} // end namespace PRDF

#endif // prdfCalloutUtil_H
