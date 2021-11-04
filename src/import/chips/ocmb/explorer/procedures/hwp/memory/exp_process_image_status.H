/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_process_image_status.H $ */
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
/// EKB-Mirror-To: hostboot

///
/// @file exp_process_image_status.H
/// @brief Procedure to run explorer fw_adapter_properties_get in order to gather information about
/// the explorer firmware images (i.e. version, authentication status). This will save some
/// information into attributes as well as perform checks for image failures.
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef __MSS_EXP_PROCESS_IMAGE_STATUS__
#define __MSS_EXP_PROCESS_IMAGE_STATUS__

#include <fapi2.H>

// Required for Cronus
typedef fapi2::ReturnCode (*exp_process_image_status_FP_t) (const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&,
        const uint8_t*);

extern "C"
{

///
/// @brief Run explorer fw_adapter_properties_get
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS if ok
/// @note This procedure must be called before running exp_flash_read_test and mss_draminit
///
    fapi2::ReturnCode exp_process_image_status(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target);

}// extern C

#endif
