/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/tod/runtime/rt_todintf.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2017                        */
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
#ifndef __RUNTIME__TOD_INTERFACE_H
#define __RUNTIME__TOD_INTERFACE_H

#include <errl/errlentry.H>           // errlHndl_t
#include <targeting/common/target.H>  // TARGETING::TargetHandleList
#include <isteps/tod/TodTypes.H>      // TodChipDataContainer

/**
 *  @file rt_todintf.H
 *
 *  @brief TOD FSP interfaces
 *
 *
 */

namespace TOD
{

/**
 *  @brief This interface creates a new backup TOD topology.  This request
 *         is sent to the FSP for resetting the backup topology.
 *
 *  @param[in] i_oscPos the ordinal ID of the failing OSC.  Value of
 *             0xFFFFFFFF means no OSC to avoid.
 *  @param[in] i_procOscTgt target of the processor with which the failing OSC
 *             is associated with. If ordinal ID is 0xFFFFFFFF then this should
 *             be NULL, otherwise provide a valid target. If ordinal ID is
 *             0xFFFFFFFF, i_procOscTgt is ignored regardless of it's validity.
 *  @param[in] i_badChipList input list of targets.
 *  @param[in] i_informPhyp flag to inform the PHYP that it won't have a
 *             backup available for fail over while we are re-configuring it.
 *
 *  @return Error log handle indicating the status of the request
 */
errlHndl_t resetBackupTopology(
                              uint32_t i_oscPos,
                              const TARGETING::TargetHandle_t& i_procOscTgt,
                              const TARGETING::TargetHandleList& i_badChipList,
                              bool i_informPhyp);

/**
 *  @brief This interface returns the TOD topology data for analysis
 *
 *  @param[out] o_todChipData container that holds the processor data
 *
 *  @return Error log handle indicating the status of the request
 */
errlHndl_t readTodProcDataFromFile(TodChipDataContainer& o_todChipData);

}  // end namespace TOD

#endif   // end __RUNTIME__TOD_INTERFACE_H

