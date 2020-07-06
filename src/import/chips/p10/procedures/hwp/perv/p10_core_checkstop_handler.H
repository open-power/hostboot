/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_core_checkstop_handler.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
//-------------------------------------------------------------------------
/// @file p10_core_checkstop_handler.H
/// @brief Depending on input flag, trun local xstops into system xstops.
///
/// *HWP HW Maintainer: Manish Chowdhary  <manichow@in.ibm.com>
/// *HWP FW Maintainer: Dan Crowell <dcrowell@us.ibm.com>
/// *HWP Consumed by: HB
///

#ifndef _P10_CORE_CHECKSTOP_HANDLER_H_
#define _P10_CORE_CHECKSTOP_HANDLER_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_core_checkstop_handler_FP_t)(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>&, bool);

constexpr bool CORE_XSTOP_HNDLR__SAVE_AND_ESCALATE = true;
constexpr bool CORE_XSTOP_HNDLR__RESTORE_ORIG = false;


// @brief Handles core checkstops for P10 when we want to switch between
//        unit and system checkstops.
//
// @param[in] i_target_core         Reference to TARGET_TYPE_CORE target
// @param[in] i_override_restore    Boolean to switch between override and restore modes.
//                                  If true, we save off the original register and turn
//                                  local xstops into system xstops.
//                                  If false, we restore the original register.
// @return  FAPI2_RC_SUCCESS if success, else error code.
//
extern "C"
{
    fapi2::ReturnCode p10_core_checkstop_handler(
        const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target_core,
        bool i_override_restore);
}

#endif
