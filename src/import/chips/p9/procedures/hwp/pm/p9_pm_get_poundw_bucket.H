/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundw_bucket.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9_pm_get_poundw_bucket.H
/// @brief Provide structure for vdmData so that info from #W keyword can be
/// stored inside of this struct.
/// Also define prototype for p9_pm_get_poundw_bucket
///

#ifndef _P9_PM_GET_POUND_W_BUCKET_H_
#define _P9_PM_GET_POUND_W_BUCKET_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm_get_poundw_bucket_attr.H>

namespace fapi2
{

//Represents the data contained within a single #W bucket
//Note: This structure should not be assumed to be binary identical
//to the contents of the VPD itself.
//Pack the struct so that we can get a consistent size with no
//extra padding between fields.
typedef struct __attribute__((__packed__))  vdmData
{
    // version
    uint8_t version;
    // bucket Id
    uint8_t bucketId;
    // VDM data
    uint8_t vdmData[PW_VER_2_VDMDATA_SIZE];
} vdmData_t;

}

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------
///
/// @brief Read #W bucket data from CRP0 record based upon
///        bucket ID read off of parent proc chip. This function
///        will pass out a structured format of the #W data of correct
///        endianness.
/// @param[in] i_target EQ chiplet target
/// @param[in] o_data structured data describing the #w bucket used
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_pm_get_poundw_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    fapi2::vdmData_t& o_data);


#endif // _P9_PM_GET_POUND_W_BUCKET_H_
