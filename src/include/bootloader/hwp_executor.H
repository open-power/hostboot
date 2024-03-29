/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/hwp_executor.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
///
/// @file plat_hwp_executor.H
///
/// @brief Defines the platform Executor Macro.
///
/// The PLAT HWP Executor macro is called by the FAPI HWP Executor macro when a
/// PLAT invoker function or a HWP wants to execute a HWP. Each platform can
/// modify the macro to do any platform specific work to execute the HWP (e.g.
/// dlopening a shared library)
///

#ifndef HWPEXECUTOR_H_
#define HWPEXECUTOR_H_

#include <plat_hwp_executor.H>
#include <fapi2_hwp_executor.H>

/**
 * @brief HWP Executor macro
 *
 * Call the HWP directly.
 */
#define FAPI_PLAT_EXEC_HWP(RC, FUNC, _args_...) \
    RC = FUNC(_args_)

#endif // HWPEXECUTOR_H_
