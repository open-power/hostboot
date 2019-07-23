/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/runtime/sbeio_nvdimm_operation.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
#ifndef __SBE_MSG_SBEIO_NVDIMM_OPERATION_H
#define __SBE_MSG_SBEIO_NVDIMM_OPERATION_H

#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace SBE_MSG
{

/**
 * @brief SBE pass-through command for executing nvdimm operations at runtime.
 *        This command acts as a bridge between sbe pass-through and the
 *        runtime doNvDimmOperation function.
 *
 * @param[in]  i_targetHandle - The target of the request.
 * @param[in]  i_reqDataSize - Size of the nvdimm operation blob.
 * @param[in]  i_reqData - NVDIMM operation data.
 * @param[out] o_rspStatus - The return value from doNvDimmOperation
 * @param[out] o_rspDataSize - Set to 0 on return.
 * @param[out] o_rspData - Not Used.
 *
 * @return nullptr upon success, pointer to ErrlEntry if an error occurred.
 *
 */
errlHndl_t sbeNvdimmOperation( TARGETING::TargetHandle_t i_targetHandle,
                               uint32_t   i_reqDataSize,
                               uint8_t  * i_reqData,
                               uint32_t * o_rspStatus,
                               uint32_t * o_rspDataSize,
                               uint8_t  * o_rspData );

}

#endif
