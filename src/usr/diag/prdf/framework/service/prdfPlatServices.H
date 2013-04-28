/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: ./framework/service/prdfPlatServices.H $                      */
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

#ifndef PRDFPLATSERVICES_H
#define PRDFPLATSERVICES_H

/**
 * @file  prdfPlatServices.H
 * @brief Wrapper code for external interfaces used by PRD.
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <diag/mdia/mdia.H>
#include <utility_procedures/mss_maint_cmds.H>

// This must be included after all other includes. This will take care of cases
// where a file must be included in the common code, but the include paths are
// different between FSP and Hostboot.
#include <prdfPlatServices_common.H>

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                      System Level Utility functions
//##############################################################################

//##############################################################################
//##                       Processor specific functions
//##############################################################################

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Checks if we are running in MDIA mode.
 * @return TRUE if in MDIA mode, FALSE otherwise.
 */
bool isInMdiaMode();

/**
 * @brief  Sends a maintenance command message to MDIA.
 * @param  i_mbaTarget An MBA target.
 * @param  i_eventType MDIA event type
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mdiaSendEventMsg( TARGETING::TargetHandle_t i_mbaTarget,
                          MDIA::MaintCommandEventType i_eventType );

/**
 * @brief  Invokes the restore DRAM repairs hardware procedure.
 * @param  i_mbaTarget
 * @param  o_repairedRankMask An encoded bitmask of repaired ranks.
 * @param  o_badDimm An encoded bitmask of bad DIMMs.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssRestoreDramRepairs( TARGETING::TargetHandle_t i_mbaTarget,
                               uint8_t & o_repairedRankMask,
                               uint8_t & o_badDimmMask );

/**
 * @brief  Invokes the mss_IPL_UE_isolation hardware procedure.
 *         This function will identify the bits that caused the UE.
 * @param  i_mba    Target MBA.
 * @param  i_rank   Target rank.
 * @param  o_bitmap DQ bitmap container.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mssIplUeIsolation( TARGETING::TargetHandle_t i_mba,
                           const CenRank & i_rank,
                           CenDqBitmap & o_bitmap );

} // end namespace PlatServices

} // end namespace PRDF

#endif // PRDFPLATSERVICES_H

