/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_hwp_executor.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
///
/// @file plat_hwp_executor.H
///
/// @brief Defines the specialized platform HWP Executor Macro.
///
/// The PLAT HWP Executor macro is called by the FAPI HWP Executor macro when a
/// PLAT invoker function or a HWP wants to execute a HWP. Each platform can
/// modify the macro to do any platform specific work to execute the HWP (e.g.
/// dlopening a shared library)
///

// plat_hwp_executor.H     (platform owned file) - Platform specialization
//                                                 of functions.
//
// fapi2_hwp_executor.H    (common file)         - contains the templates
//                                                 and calls a required macro
//                                                 for non-specialized methods.
//
// hw_executor.H           (platform owned file) - Platform implementation of
//                                                 functions defined in
//                                                 fapi2_hwp_executor.H above.
// -- Include order --
//     procedure.C
//        #include <hwp_executor.H>
//     target.H
//        #include plat_hwp_executor.H
//        #include fapi2_hwp_executor.H

#ifndef PLATHWPEXECUTOR_H_
#define PLATHWPEXECUTOR_H_

// Currently empty because no specialzation for Hostboot

#endif // PLATHWPEXECUTOR_H_
