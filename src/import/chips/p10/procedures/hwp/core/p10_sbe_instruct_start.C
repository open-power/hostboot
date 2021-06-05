/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/core/p10_sbe_instruct_start.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @brief Start instructions via p10_thread control
///        Use to start thread instruction execution as part of
//         istep proc_sbe_instruct_start / proc_exit_cache_contained
///
/// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by  : SBE
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_instruct_start.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


fapi2::ReturnCode p10_sbe_instruct_start(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const ThreadSpecifier i_thread_mask)
{
    fapi2::buffer<uint64_t> l_ras_status;
    uint64_t l_thread_state;
    fapi2::ATTR_ECO_MODE_Type l_eco_mode;

    FAPI_DBG("Entering ...");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, i_target, l_eco_mode));
    FAPI_ASSERT(l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_DISABLED,
                fapi2::P10_SBE_INSTRUCT_START_MASTER_CORE_ECO_MODE()
                .set_TARGET(i_target),
                "Master core target not expected to be in ECO mode!");

    FAPI_INF("Starting instruction using thread mask: 0x%X",
             static_cast<uint8_t>(i_thread_mask));

    FAPI_TRY(p10_thread_control(i_target,
                                i_thread_mask,
                                PTC_CMD_START,
                                false,
                                l_ras_status,
                                l_thread_state),
             "Error from p10_thread_control");

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
