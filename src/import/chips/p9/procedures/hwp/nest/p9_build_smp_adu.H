/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_build_smp_adu.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
/// @file p9_build_smp_adu.H
/// @brief Interface for ADU operations required to support fabric
///        configuration actions (FAPI2)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 3
/// *HWP Consumed by: HB,FSP
///

#ifndef _P9_BUILD_SMP_ADU_H_
#define _P9_BUILD_SMP_ADU_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

enum p9_build_smp_adu_action
{
    SWITCH_AB = 1,
    SWITCH_CD = 2,
    QUIESCE   = 4,
    RESET_SWITCH = 8
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
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_sequence_adu(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op,
            const p9_build_smp_adu_action i_action);

} // extern "C"

#endif // _P9_BUILD_SMP_ADU_H_
