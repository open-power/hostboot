/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/terminate.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
/** @file terminate.H
 *  @brief Defines kernel information about the TI data area
 */
#ifndef __KERNEL_TERMINATE_H
#define __KERNEL_TERMINATE_H

#include <kernel/types.h>
#include <kernel/hbterminatetypes.H>

/** @fn terminateExecuteTI
 *  @brief Sequence to execute a TI attn
 */
void terminateExecuteTI();

/** @fn initKernelMutex
 *  @brief initialize the internal kernel mutex used to lock
 *         the HB TI area.
 */
void initKernelTIMutex();

/** @fn termWriteEid
 *  Update TI data area with an EID.
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_eid:     eid to be stored
 *  @param[out] NONE:
 */
void termWriteEid(hb_terminate_source i_source, uint32_t i_eid);

/** @fn termWriteSRC
 *  Create an SRC and Update the TI data area with the src created
 *  @param[in] i_source:  indicates what type of fail forced the TI
 *  @param[in] i_reasoncode: reasoncode for the failure(assert or shutdown)
 *  @param[in] i_failAddr: i_linkRegister() value (address of failure)
 *  @param[in] i_error_info: addt'l error info to add to TI data
 *  @param[in] i_forceWrite: force the HB TI area to be overwritten with
 *             the passed parameters.
 *  @param[out] NONE:
 */
void termWriteSRC(hb_terminate_source i_source,
                  uint16_t i_reasoncode,
                  uint64_t i_failAddr = 0,
                  uint32_t i_error_info = 0,
                  bool i_forceWrite = false);

/** @fn termWriteStatus
 *  A generic function that writes the given status to the HB TI area.
 *  The function checks whether the given status is an EID (in which case
 *  it will execute termWriteEid) or SRC (calls termWriteSRC) by looking
 *  at the EID mask of the status.
 *  @param[in] i_source: indicates what type of fail forced the TI
 *  @param[in] i_status: the status with which we want to TI (could be EID
 *                       of SRC)
 *  @param[in] i_failAddr: i_linkRegister() value (address of failure)
 *  @param[in] i_error_info: addt'l error info to add to TI data
 *  @param[in] i_forceWrite: force the HB TI area to be overwritten with
 *             the passed parameters.
 */
void termWriteStatus(hb_terminate_source i_source,
                     uint64_t i_status,
                     uint64_t i_failAddr = 0,
                     uint32_t i_error_info = 0,
                     bool i_forceWrite = false);

/** @fn termModifySRC
 *  Modify an SRC and the TI data area for Bootloader
 *  @param[in] i_moduleID: moduleID for the failure (used by Bootloader)
 *  @param[in] i_word7: data to set SRC word 7 / @userdata2[0:31] (optional)
 *  @param[in] i_word8: data to set SRC word 8 / @userdata2[32:63] (optional)
 *  @param[out] NONE:
 */
void termModifySRC(uint8_t i_moduleID,
                   uint32_t i_word7 = 0,
                   uint32_t i_word8 = 0);

/** @fn termSetHbDump
 *
 *  @brief Set flag for system to get an HB dump during processing of the TI.
 *
 *  @param[in] NONE
 *  @param[out] NONE:
 *
 *  @return Nothing
 */
void termSetHbDump(void);

/** @fn termSetIstep
 *
 *  @brief Set istep into progress code word of the SRC.
 *
 *  @param[in] i_istep: Encoded istep value
 *  @param[out] NONE:
 *
 *  @return Nothing
 */
void termSetIstep(uint32_t i_istep);

/** @fn setTiAreaScratchReg
 *
 * @brief Updates Core Scratch Reg 0 with the address of the TI Area Structure
 *
 */
void setTiAreaScratchReg();

#endif
