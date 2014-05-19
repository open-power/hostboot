/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/framework/service/prdfPlatServices.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

// Inline function definitions for Hostboot compiler optimization. See
// prdfPlatServices_common.H for the function declarations.

inline bool isMasterFSP() { return true; }
inline int32_t syncFile( const char * i_fileName ) { return SUCCESS; }
inline bool atRuntime() { return false; }

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

