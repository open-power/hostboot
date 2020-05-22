/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundw_bucket.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
/// @file p9_pm_get_poundw_bucket.C
/// @brief Grab PM data from attribute
///
/// @file p9_pm_get_poundw_bucket.H
/// @brief Provide structure for vdmData so that info from #W keyword can be
/// stored inside of this struct.
/// Also define prototype for p9_pm_get_poundw_bucket
///
/// *HWP HW Owner    : N/A (This is a FW delivered function)
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : PM - Calling this function.
/// *HWP Consumed by : FSP
/// *HWP Level       : 3
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_get_poundw_bucket.H>
#include <attribute_ids.H>

#ifdef __VDM_TEST

uint8_t dummy_attr[] =
{
    0x30, 0x05,
    0x2F, 0x6A, 0x04, 0x68, 0x05, 0xC0, 0x23, 0x12, 0x41, 0x42,
    0x42, 0x42, 0x42, 0x43, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73,
    0x02, 0x53, 0xA1, 0x04, 0x6A, 0x00, 0x00,

    0x1B, 0xF0, 0x07, 0x95, 0x07, 0x40, 0x23, 0x12, 0x23, 0x24,
    0x24, 0x24, 0x24, 0x25, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73,
    0x02, 0x53, 0xA1, 0x04, 0x6A, 0x00, 0x00,

    0x40, 0x42, 0x04, 0x2C, 0x04, 0xD0, 0x23, 0x12, 0x5A, 0x5A,
    0x5A, 0x5B, 0x5B, 0x5B, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73,
    0x02, 0x53, 0xA1, 0x04, 0x6A, 0x00, 0x00,

    0x60, 0x85, 0x0E, 0xD1, 0x0C, 0xF0, 0x23, 0x12, 0x80, 0x80,
    0x80, 0x80, 0x81, 0x81, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73,
    0x02, 0x53, 0xA1, 0x04, 0x6A, 0x00, 0x00,

    0x9C, 0x40, 0x14, 0xEE, 0x09, 0x98, 0x4E, 0x20, 0x27, 0x10,
    0x01, 0x02, 0x03, 0xFF, 0x03, 0x7F, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

#endif

// See doxygen in header file
fapi2::ReturnCode p9_pm_get_poundw_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    fapi2::vdmData_t& o_data)
{
    FAPI_DBG("Entering p9_pm_get_poundw_bucket ....");

    //Set up a char array to hold the bucket data from an attr read
    fapi2::ATTR_POUNDW_BUCKET_DATA_Type l_bucketAttr;

    //Perform an ATTR_GET for POUNDW_BUCKET data on the EQ target
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUNDW_BUCKET_DATA,
                           i_target,
                           l_bucketAttr));

    memcpy(&o_data,  l_bucketAttr, sizeof(l_bucketAttr));

#ifdef    __VDM_TEST

    memcpy( &o_data, dummy_attr, sizeof(dummy_attr) );

#endif

    FAPI_INF( "COPYING from ATTR_POUNDW_BUCKET_DATA" );

fapi_try_exit:
    FAPI_DBG("Exiting p9_pm_get_poundw_bucket ....");
    return fapi2::current_err;
}
