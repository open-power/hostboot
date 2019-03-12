/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/core/p10_sbe_instruct_start.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
///----------------------------------------------------------------------------
///
/// @file p10_sbe_instruct_start.C
///
/// @brief Issue start instruction to thread0 of master processor
///        See detailed description in header file.
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by  : SBE
///----------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_instruct_start.H>

extern "C"
{
    fapi2::ReturnCode p10_sbe_instruct_start(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
    {
        fapi2::buffer<uint64_t> l_rasStatusReg(0);
        uint64_t l_state = 0;
        FAPI_DBG("Entering ...");

        FAPI_INF("Starting instruction on thread 0");
        FAPI_TRY(p10_thread_control(i_target, THREAD0, PTC_CMD_START, false,
                                    l_rasStatusReg, l_state),
                 "p10_thread_control() returns an error");

    fapi_try_exit:
        FAPI_DBG("Exiting ...");
        return fapi2::current_err;
    }

} // extern "C"
