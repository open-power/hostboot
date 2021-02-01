/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/runtime/sbeio_vpd_override.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
*  @file sbeio_vpd_override.H
*
*  @brief prototype for sbeApplyVpdOverrides(), formated as a processCmdFunction_t
*         Interface for feature that allows an external client (i.e. CFT) to
*         selectively override the VPD cache (but not VPD HW) at runtime when in
*         non-secure mode only.
*/
#ifndef __SBE_MSG_SBEIO_VPD_OVERRIDE_H
#define __SBE_MSG_SBEIO_VPD_OVERRIDE_H

#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace SBE_MSG
{

/**
 * @brief SBE pass-through command for modifying the MVPD, SPD, or WOF data at runtime.
 *
 * @param[in]  i_procTgt      - The processor target making the request. This target
 *                              will be used for MVPD writes.
 * @param[in]  i_reqDataSize  - Size of the i_reqData data blob in bytes.
 * @param[in]  i_reqData      - data blob containing data to write to VPD, SPD, WOF
 *                              during hbrt using either keyword-record or
 *                              offset-#number of bytes to write, in the format of
 *                              a vpdOverwriteCmd struct. SPD and WOF will use the
 *                              ecmdTargetString in vpdOverwriteCmd to determine
 *                              which target to write to.
 * @param[out] o_rspStatus    - The return value from the apply_vpd_overrides,
 *                              0 if successful.
 * @param[out] o_rspDataSize  - Set to 0 on return.
 * @param[out] o_rspData      - Not Used.
 *
 * @return nullptr upon success, pointer to ErrlEntry if an error occurred.
 *
 */
errlHndl_t sbeApplyVpdOverrides(
                                 TARGETING::TargetHandle_t i_procTgt,
                                 uint32_t   i_reqDataSize,
                                 uint8_t  * i_reqData,
                                 uint32_t * o_rspStatus,
                                 uint32_t * o_rspDataSize,
                                 uint8_t  * o_rspData
                                );

}

#endif
