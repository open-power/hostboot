/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/sbe/p10_get_sbe_msg_register.H $ */
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
//------------------------------------------------------------------------------
/// @file  p10_get_sbe_msg_register.H
///
/// @brief Fetch the SBE messaging register
//------------------------------------------------------------------------------
// *HWP HW Owner        : RAJA DAS <rajadas2@in.ibm.com>
// *HWP FW Owner        : RAJA DAS <rajadas2@in.ibm.com>
// *HWP Team            : SBE
// *HWP Level           : 3
// *HWP Consumed by     : SE, Hostboot, Cronus
//------------------------------------------------------------------------------


#ifndef _P10_GET_SBE_MSG_REGISTER_H_
#define _P10_GET_SBE_MSG_REGISTER_H_

#include <fapi2.H>
#include "p10_sbe_ext_defs.H"

typedef fapi2::ReturnCode (*p10_get_sbe_msg_register_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
        sbeMsgReg_t&);

///
/// @brief Returns the SBE messaging register
///
/// @param i_chip [in] Target to the proc chip
/// @param o_sbeReg [out] The SBE messaging register. Caller can interpret as sbeReg_t
///
/// @return FAPI2_RC_SUCCESS on success, else a FAPI2 RC indicating the failure
///
extern "C"
{
    fapi2::ReturnCode p10_get_sbe_msg_register(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip,
            sbeMsgReg_t& o_sbeReg);
}
#endif // _P10_GET_SBE_MSG_REGISTER_H_
