/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_get_poundv_bucket_attr.H $ */
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
/// @file p10_pm_get_poundv_bucket_attr.H
/// @brief Provide structure for voltageBucketData so that info from #V keyword
/// can be stored inside of this struct.
/// Also define prototype for p10_pm_get_poundv_bucket_attr
///
/// *HWP HW Owner    : N/A (This is a FW delivered function)
/// *HWP FW Owner    :
/// *HWP Team        : PM - Calling this function.
/// *HWP Consumed by : FSP
/// *HWP Level       : 3
///

#ifndef _P10_PM_GET_POUND_V_BUCKET_ATTR_H_
#define _P10_PM_GET_POUND_V_BUCKET_ATTR_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

enum bucketParms
{
    POUNDV_VERSION_1      = 0x1,
    POUNDV_VERSION_2      = 0x2,
    POUNDV_VERSION_3      = 0x3,//theoretical backward-compatible new version
    POUNDV_VERSION_OFFSET = 0x0,
    POUNDV_BUCKET_OFFSET  = 0x1,
    NUM_BUCKETS           = 0x2,
    VERSION_2_BUCKET_SIZE = 350,
};


// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p10_pm_get_poundv_bucket_attr_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    uint8_t* o_data);

extern "C" {

///
/// @brief Read #V bucket data from CRP0 record based upon
///        bucket ID read off of parent proc chip. This function
///        will pass out array of bytes as they are read from the VPD
///        NOTE: This might be incorrect endianness
/// @param[in] i_target Proc chiplet target
/// @param[out] o_data bytes read from #V keyword of an CRP0 record
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p10_pm_get_poundv_bucket_attr(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        uint8_t* o_data);

} // extern "C"

#endif // _P10_PM_GET_POUND_V_BUCKET_ATTR_H_
