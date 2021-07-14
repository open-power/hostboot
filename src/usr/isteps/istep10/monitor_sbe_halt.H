/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/monitor_sbe_halt.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/**
 * @file monitor_sbe_halt.H
 *
 *  Accessors to thread that monitors SBEs are staying in halt state.
 *  This is for security reasons since the FSP/BMC could hreset the SBE
 *  while in the halt state.
 *
 *  If an SBE is detected as coming out of halt state, the thread will
 *  commit an unrecoverable error with a deconfig of the offending HW.
 *  Also, Selfboot Control/Status register's SECURE_DEBUG_MODE bit will
 *  be continuously set to prevent this SBE from further use.
 */
#ifndef __MONITOR_SBE_HALT_H
#define __MONITOR_SBE_HALT_H

//  targeting support
#include   <targeting/common/commontargeting.H>
#include   <targeting/common/utilFilter.H>
#include   <targeting/common/target.H>

namespace MONITOR_SBE_HALT
{
/**
 * @brief Add SBE processor to halt monitor list
 *        If this is the first one added, it will also start the monitoring thread
 *        Call this after SBE is in halted state.
 * @param[in] processor target to add
 */
void addSbeProc(TARGETING::TargetHandle_t i_sbe_proc);

/**
 * @brief Remove SBE processor from halt monitor list
 *        Call this before waking up the SBE with hreset.
 * @param[in] processor target to remove
 */
void removeSbeProc(TARGETING::TargetHandle_t i_sbe_proc);

/**
 * @brief Stop monitoring any SBE processors for resumed activity
 *        This clears the halt monitoring list, thus
 *        allowing the monitoring thread to exit cleanly
 */
void stopSbeHaltMonitor();

}; // end namespace MONITOR_SBE_HALT

#endif
