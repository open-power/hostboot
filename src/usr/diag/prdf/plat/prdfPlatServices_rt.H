/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

#ifndef __prdfPlatServices_rt_H
#define __prdfPlatServices_rt_H

#include <p9_l3err_extract.H>
#include <p9_l2err_extract.H>
#include <p9_pm_callout.H>
#include <prdfMemAddress.H>

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief Communicates a page gard request to the hypervisor.
 * @param i_systemAddress Any address in the target page.
 */
void sendPageGardRequest( uint64_t i_systemAddress );

/**
 * @brief Communicates to the hypervisor a range of address to remove from the
 *        available memory space.
 * @param i_startAddr First address in the range.
 * @param i_endAddr   Last address in the range.
 */
void sendDynMemDeallocRequest( uint64_t i_startAddr, uint64_t i_endAddr );

/**
 * @brief  Returns the start and end maintenance address of the given rank. By
 *         default, will return the address range of the master rank.
 * @param  i_tgt       Target MBA/MCA.
 * @param  i_rank      Target rank.
 * @param  i_dimmSlct  Target dimm select.
 * @param  o_startAddr The return start address.
 * @param  o_endAddr   The return end address.
 * @param  i_slaveOnly true = slave rank only, false = master rank (default).
 * @return Non-SUCCESS in internal function fails, SUCCESS otherwise.
 */
int32_t getMemAddrRange( TARGETING::TargetHandle_t i_tgt, uint8_t i_mrank,
                         uint8_t i_dimmSlct, MemAddr & o_startAddr,
                         MemAddr & o_endAddr, uint8_t i_srank = 0,
                         bool i_slaveOnly = false );

//##############################################################################
//##                  Nimbus/Centaur Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Stops Background Scrubbing.
 * @param  i_chip MCBIST, MCA, or MBA chip.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t stopBgScrub( ExtensibleChip * i_chip );

/**
 * @brief  Resumes background scrubbing after it has paused on error.
 *
 * There are use cases where we want background scrubbing to pause on error in
 * order to collect FFDC (specifically address information), in which case we
 * will not start a Targeted Diagnostics procedure. Instead, this command will
 * resume the background scrubbing procedure already set up in hardware,
 * starting on the next configured address.
 *
 * @note This function should only be called after pausing background scrubbing
 *       due to an error. It should not be called after executing a Targeted
 *       Diagnotics procedure.
 *
 * @param  i_chip MCBIST, MCA, or MBA chip.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t resumeBgScrub( ExtensibleChip * i_chip );

//##############################################################################
//##                       Line delete functions
//##############################################################################

/**
 * @brief Extracts address of an error from L3 Trace arrays
 * @param i_exTgt EX target
 * @param o_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t extractL3Err( TARGETING::TargetHandle_t i_exTgt,
                      p9_l3err_extract_err_data &o_errorAddr);

/**
 * @brief Calls HWP to execute a line delete. Saves Line delete command in
          HCODE image.
 * @param i_exTgt EX target
 * @param i_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t l3LineDelete(TARGETING::TargetHandle_t i_exTgt,
                     const p9_l3err_extract_err_data& i_l3_err_data);

/**
 * @brief Extracts address of an error from L2 Trace arrays
 * @param i_exTgt EX target
 * @param i_ce Type of error we're looking for: CE or UE
 * @param o_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t extractL2Err( TARGETING::TargetHandle_t i_exTgt, bool i_ce,
                      p9_l2err_extract_err_data &o_errorAddr);

/**
 * @brief Calls HWP to execute a line delete. Saves Line delete command in
          HCODE image.
 * @param i_exTgt EX target
 * @param i_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t l2LineDelete(TARGETING::TargetHandle_t i_exTgt,
                     const p9_l2err_extract_err_data& i_l2_err_data);


/**
 * @brief Calls p9_pm_callout HWP to collect FFDC and determine appropriate
 *        callouts for a STOP recovery malfunction alert.
 * @param i_tgt P9 chip target
 * @param o_ra enum indicating which type of callout should be made
 * @param o_deadCores bit vector of dead cores
 * @param o_ffdcList points to a list of STOP FFDC summary sub-sections
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t pmCallout( TARGETING::TargetHandle_t i_tgt,
                   RasAction& o_ra,
                   uint32_t o_deadCores,
                   std::vector < StopErrLogSectn >& o_ffdcList );


} // end namespace PlatServices

} // end namespace PRDF

#endif // __prdfPlatServices_rt_H

