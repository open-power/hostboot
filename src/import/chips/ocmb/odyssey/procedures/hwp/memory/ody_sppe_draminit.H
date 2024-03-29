/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_sppe_draminit.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2023                        */
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
/// @file ody_sppe_draminit.H
/// @brief Runs the dram initialization on the SPPE
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 1
// *HWP Consumed by: FSP:HB

#ifndef _ODY_SPPE_DRAMINIT_
#define _ODY_SPPE_DRAMINIT_

#include <fapi2.H>
#include <hwp_data_stream.H>

// Required for Cronus
typedef fapi2::ReturnCode (*ody_sppe_draminit_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        fapi2::hwp_data_ostream&);

typedef fapi2::ReturnCode (*ody_sppe_draminit_single_port_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>&,
        fapi2::hwp_data_ostream&);

extern "C"
{

///
/// @brief Runs the dram initialization on the SPPE
/// @param[in] i_target the controller
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_sppe_draminit(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                        fapi2::hwp_data_ostream& o_log_data);

///
/// @brief Runs the dram initialization on the SPPE on a single port
/// @param[in] i_target the controller
/// @param[out] o_log_data hwp_data_ostream of streaming log
/// @return FAPI2_RC_SUCCESS iff ok
///
    fapi2::ReturnCode ody_sppe_draminit_single_port(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_port,
            fapi2::hwp_data_ostream& o_log_data);
}// extern C
#endif
