/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_build_smp_adu.H $ */
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
/// @file p10_build_smp_adu.H
/// @brief Interface for ADU operations required to support fabric
///        configuration actions (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, FSP
///

#ifndef _P10_BUILD_SMP_ADU_H_
#define _P10_BUILD_SMP_ADU_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_build_smp.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

enum p10_build_smp_adu_action
{
    PRE_SWITCH_AB   = 1,
    PRE_SWITCH_CD   = 2,
    SWITCH_AB       = 3,
    SWITCH_CD       = 4,
    QUIESCE         = 5,
    RESET_SWITCH    = 6
};

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C" {

///
/// @brief Perform fabric quiesce/switch operation via ADU
///
/// @param[in] i_smp       Fully specified structure encapsulating SMP
/// @param[in] i_op        Enumerated type representing SMP build phase (HB or FSP)
/// @param[in] i_action    Enumerated type representing fabric operation
///
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_build_smp_sequence_adu(p10_build_smp_system& i_smp,
            const p10_build_smp_operation i_op,
            const p10_build_smp_adu_action i_action);

} // extern "C"

#endif // _P10_BUILD_SMP_ADU_H_
