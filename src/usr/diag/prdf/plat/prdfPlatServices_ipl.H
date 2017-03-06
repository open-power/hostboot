/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_ipl.H $               */
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

#ifndef __prdfPlatServices_ipl_H
#define __prdfPlatServices_ipl_H

/**
 * @file  prdfPlatServices_ipl.H
 * @brief Wrapper code for external interfaces used by PRD (IPL only).
 *
 * This file contains code that is strictly specific to Hostboot. All code that
 * is common between FSP and Hostboot should be in the respective common file.
 */

#include <diag/mdia/mdia.H>

//------------------------------------------------------------------------------

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief  Checks if we are running in MDIA mode.
 * @return TRUE if in MDIA mode, FALSE otherwise.
 */
bool isInMdiaMode();

/**
 * @brief  Sends a MCBIST/maintenance event message to MDIA.
 * @param  i_trgt      An MCBIST or MBA target.
 * @param  i_eventType MDIA event type
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t mdiaSendEventMsg( TARGETING::TargetHandle_t i_trgt,
                          MDIA::MaintCommandEventType i_eventType );

/**
 * @brief  Initiates a reconfig loop due to an RCD parity error.
 * @return True if the number of allowed reconfig loops has been exceeded.
 *         False otherwise.
 */
bool rcdParityErrorReconfigLoop();

/**
 * @brief  Invokes the restore DRAM repairs hardware procedure.
 * @param  i_mbaTarget
 * @param  o_repairedRankMask An encoded bitmask of repaired ranks.
 * @param  o_badDimm An encoded bitmask of bad DIMMs.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
/* TODO RTC 136126
int32_t mssRestoreDramRepairs( TARGETING::TargetHandle_t i_mbaTarget,
                               uint8_t & o_repairedRankMask,
                               uint8_t & o_badDimmMask );
*/

/**
 * @brief  Invokes the mss_IPL_UE_isolation hardware procedure.
 *         This function will identify the bits that caused the UE.
 * @param  i_mba    Target MBA.
 * @param  i_rank   Target rank.
 * @param  o_bitmap DQ bitmap container.
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
/* TODO RTC 136126
int32_t mssIplUeIsolation( TARGETING::TargetHandle_t i_mba,
                           const CenRank & i_rank,
                           CenDqBitmap & o_bitmap );
*/

//##############################################################################
//##                  Nimbus/Centaur Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Starts a super fast read command from the first address of the given
 *         rank to the end of memory.
 * @param  i_chip MCA or MBA chip.
 * @param  i_rank Will start the command on the first address of this slave
 *         rank. To ensure the command is started on a master rank boundary,
 *         make sure the slave rank value is 0.
 * @return Non-SUCCESS if an internal function fails, otherwise SUCCESS.
 */
template<TARGETING::TYPE T>
uint32_t startSfRead( ExtensibleChip * i_chip, const MemRank & i_rank );

} // end namespace PlatServices

} // end namespace PRDF

#endif // __prdfPlatServices_ipl_H

