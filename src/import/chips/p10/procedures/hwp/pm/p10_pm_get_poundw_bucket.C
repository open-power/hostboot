/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_get_poundw_bucket.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_pm_get_poundw_bucket.C
/// @brief Grab PM data from attribute
///
/// @brief Provide structure for DDSCdata so that info from #W keyword can be
/// stored inside of this struct.
/// Also define prototype for p10_pm_get_poundw_bucket
///
/// *HWP HW Owner    : Greg Stills(stillgs@us.ibm.com)
/// *HWP FW Owner    : Prasad Bg Ranganath(prasadbgr@in.ibm.com)
/// *HWP Team        : PM - Calling this function.
/// *HWP Consumed by : HB
/// *HWP Level       : 2
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_get_poundw_bucket.H>
#include <attribute_ids.H>

// See doxygen in header file
fapi2::ReturnCode p10_pm_get_poundw_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    fapi2::ddscData_t* o_data)
{
    FAPI_DBG("Entering p10_pm_get_poundw_bucket ....");

    //clear the output variable
    memset (o_data, 0, sizeof(fapi2::ddscData_t));
    //Set up a char array to hold the bucket data from an attr read
    fapi2::ATTR_POUNDW_BUCKET_DATA_Type l_bucketAttr;

    //Perform an ATTR_GET for POUNDW_BUCKET data on the proc target
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUNDW_BUCKET_DATA,
                           i_target,
                           l_bucketAttr));

    memcpy(o_data, l_bucketAttr, sizeof(l_bucketAttr));

fapi_try_exit:
    FAPI_DBG("Exiting p10_pm_get_poundw_bucket ....");
    return fapi2::current_err;
}
