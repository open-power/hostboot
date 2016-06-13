/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/fapi2/plat_chip_ec_feature.H $                */
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

#ifndef PLATCHIPECFEATURE_H_
#define PLATCHIPECFEATURE_H_

#include <plat_attr_override_sync.H>

#define PLAT_GET_CHIP_EC_FEATURE_OVERRIDE(ID, PTARGET, VAL) \
        AttrOverrideSync::getAttrOverrideFunc(ID, PTARGET, &VAL)

#endif // PLATCHIPECFEATURE_H_
