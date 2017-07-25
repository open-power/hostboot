/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/runtime/sbeio_attr_override.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#ifndef __SBE_MSG_SBEIO_ATTR_OVERRIDE_H
#define __SBE_MSG_SBEIO_ATTR_OVERRIDE_H

#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace SBE_MSG
{

/**
 * @brief SBE pass-through command for applying attribute overrides at runtime.
 *        This command acts as a bridge between sbe pass-through and the
 *        runtime apply_attr_override function.
 *
 * @param[in]  i_targetHandle - The target of the request.
 * @param[in]  i_reqDataSize - Size of the attribute overrides blob.
 * @param[in]  i_reqData - Attribute overrides binary.
 * @param[out] o_rspStatus - The return value from the apply_attr_overrides
 * @param[out] o_rspDataSize - Set to 0 on return.
 * @param[out] o_rspData - Not Used.
 *
 * @return nullptr upon success, pointer to ErrlEntry if an error occurred.
 *
 */
errlHndl_t sbeApplyAttrOverrides(
                                 TARGETING::TargetHandle_t i_targetHandle,
                                 uint32_t   i_reqDataSize,
                                 uint8_t  * i_reqData,
                                 uint32_t * o_rspStatus,
                                 uint32_t * o_rspDataSize,
                                 uint8_t  * o_rspData
                                );

}

#endif
