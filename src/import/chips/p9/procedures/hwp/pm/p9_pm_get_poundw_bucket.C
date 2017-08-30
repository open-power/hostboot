/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_get_poundw_bucket.C $ */
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

    memcpy(&o_data, l_bucketAttr, sizeof(o_data));

fapi_try_exit:
    FAPI_DBG("Exiting p9_pm_get_poundw_bucket ....");
    return fapi2::current_err;
}
