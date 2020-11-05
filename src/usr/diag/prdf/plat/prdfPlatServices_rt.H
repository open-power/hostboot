/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/plat/prdfPlatServices_rt.H $                */
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

#ifndef __prdfPlatServices_rt_H
#define __prdfPlatServices_rt_H

/* TODO RTC 256733
#include <p9_l3err_extract.H>
#include <p9_l2err_extract.H>
*/
#include <p10_pm_callout.H>
#include <prdfMemAddress.H>

namespace PRDF
{

namespace PlatServices
{

//##############################################################################
//##                        Memory specific functions
//##############################################################################

/**
 * @brief Sends a page gard request to the hypervisor.
 * @param i_addr Any address in the target page.
 */
void sendPageGardRequest( uint64_t i_addr );

/**
 * @brief Sends a dynamic memory deallocation message to the hypervisor. This
 *        message is intended for memory UEs, channel/port failures, etc.
 * @param i_saddr The first address in the range.
 * @param i_eaddr The last address in the range.
 */
void sendDynMemDeallocRequest( uint64_t i_saddr, uint64_t i_eaddr );

/**
 * @brief Sends a predictive dynamic memory deallocation message to the
 *        hypervisor. This message is intended to be send whenever there is a
 *        predictive callout of any part in the memory subsystem.
 * @param i_saddr The first address in the range.
 * @param i_eaddr The last address in the range.
 */
void sendPredDeallocRequest( uint64_t i_saddr, uint64_t i_eaddr );

//##############################################################################
//##                   Maintenance Command wrappers
//##############################################################################

/**
 * @brief  Stops Background Scrubbing.
 * @param  i_chip OCMB chip.
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
 * @param  i_chip OCMB chip.
 * @param  io_sc  The step code data struct.
 * @return Non-SUCCESS if an internal function fails, SUCCESS otherwise.
 */
template<TARGETING::TYPE T>
uint32_t resumeBgScrub( ExtensibleChip * i_chip,
                        STEP_CODE_DATA_STRUCT & io_sc );

//##############################################################################
//##                       Line delete functions
//##############################################################################

/**
 * @brief Extracts address of an error from L3 Trace arrays
 * @param i_exTgt EX target
 * @param o_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
/* TODO RTC 256733
int32_t extractL3Err( TARGETING::TargetHandle_t i_exTgt,
                      p9_l3err_extract_err_data &o_errorAddr);
*/

/**
 * @brief Calls HWP to execute a line delete. Saves Line delete command in
          HCODE image.
 * @param i_exTgt EX target
 * @param i_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
/* TODO RTC 256733
int32_t l3LineDelete(TARGETING::TargetHandle_t i_exTgt,
                     const p9_l3err_extract_err_data& i_l3_err_data);
*/

/**
 * @brief Extracts address of an error from L2 Trace arrays
 * @param i_exTgt EX target
 * @param i_ce Type of error we're looking for: CE or UE
 * @param o_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
/* TODO RTC 256733
int32_t extractL2Err( TARGETING::TargetHandle_t i_exTgt, bool i_ce,
                      p9_l2err_extract_err_data &o_errorAddr);
*/

/**
 * @brief Calls HWP to execute a line delete. Saves Line delete command in
          HCODE image.
 * @param i_exTgt EX target
 * @param i_errorAddr struct containing address of the CE
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
/* TODO RTC 256733
int32_t l2LineDelete(TARGETING::TargetHandle_t i_exTgt,
                     const p9_l2err_extract_err_data& i_l2_err_data);
*/


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
                   uint32_t &o_deadCores,
                   std::vector < StopErrLogSectn >& o_ffdcList );


/**
 * @brief   Requests HWSV to create a new back up topology due to TOD errors
 * @param   i_oscPos        Position of failing OSC. 0xFFFFFFFF if not used.
 * @param   i_procOscTgt    Proc chip target associated with failing OSC
 * @param   i_badChipList   list of bad chips to be avoided for MDMT
 * @param   i_informPhyp    Inform PHYP to disable back up topology.
 */
void requestNewTODTopology( uint32_t i_oscPos,
                            const TARGETING::TargetHandle_t& i_procOscTgt,
                            const TARGETING::TargetHandleList& i_badChipList,
                            bool i_informPhyp);

/**
 * @brief   Retrieves a saved version of a TOD config register from HWSV.
 *          We use the saved value rather than the live version because this
 *          could have changed in response to the TOD fault we're currently
 *          analyzing.
 * @param   i_procTgt  Proc chip target
 * @param   i_slvPath0 Whether we need the register for slave path 0 or 1
 * @param   o_regValue Returns contents of the register
 * @return non-SUCCESS for failure, SUCCESS otherwise
 */
int32_t getTodPortControlReg ( const TARGETING::TargetHandle_t& i_procTgt,
                               bool i_slvPath0,  uint32_t &o_regValue );
} // end namespace PlatServices

} // end namespace PRDF

#endif // __prdfPlatServices_rt_H

