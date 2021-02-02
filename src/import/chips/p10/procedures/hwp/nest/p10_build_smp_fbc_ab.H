/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_fbc_ab.H $ */
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
///
/// @file p10_build_smp_fbc_ab.H
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

#ifndef _P10_BUILD_SMP_FBC_AB_H_
#define _P10_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp.H>

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C"
{

///
/// @brief Program fabric configuration registers (hotplug, A/B set)
///        prior to issuing hotplug switch command
///
/// @param[in] i_smp    Structure encapsulating SMP topology
/// @param[in] i_op     Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp_pre_fbc_ab(
        p10_build_smp_system& i_smp,
        const p10_build_smp_operation i_op);

///
/// @brief Issue hotplug switch command (switch_ab)
///
/// @param[in] i_smp    Structure encapsulating SMP topology
/// @param[in] i_op     Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp_switch_fbc_ab(
        p10_build_smp_system& i_smp,
        const p10_build_smp_operation i_op);

///
/// @brief Program fabric configuration registers (hotplug, A/B set)
///        after issuing hotplug switch command
///
/// @param[in] i_smp    Structure encapsulating SMP topology
/// @param[in] i_op     Enumerated type representing SMP build phase
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp_post_fbc_ab(
        p10_build_smp_system& i_smp,
        const p10_build_smp_operation i_op);

} // extern "C"

#endif // _P10_BUILD_SMP_FBC_AB_H_
