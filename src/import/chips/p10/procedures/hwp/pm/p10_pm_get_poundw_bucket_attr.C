/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_get_poundw_bucket_attr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_pm_get_poundw_bucket_attr.C
/// @brief Grab PM data from certain bucket in #W keyword in CRP0 record
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
#include <p10_pm_get_poundw_bucket_attr.H>
#include <p10_pm_get_poundw_bucket.H>
#include <p10_pm_get_poundv_bucket.H>
#include <mvpd_access_defs.H>
#include <attribute_ids.H>

// See doxygen in header file
fapi2::ReturnCode p10_pm_get_poundw_bucket_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t* o_data)
{
    FAPI_DBG("Entering p10_pm_get_poundw_bucket_attr ....");
    uint8_t* l_fullVpdData = nullptr;
    uint32_t l_vpdSize = 0;
    uint8_t l_bucketId;
    uint16_t l_bucketSize = 0;
    *o_data = 0;

    //Get the #V bucket associated with proc target
    fapi2::voltageBucketData_t l_voltageBucket;

    FAPI_TRY( p10_pm_get_poundv_bucket(i_target,
                                       l_voltageBucket) );

    //Use the bucket ID from the #V bucket
    l_bucketId = l_voltageBucket.bucketId;

    //First read is to get size of vpd record, note the o_buffer is NULL
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_PDW,
                           i_target,
                           NULL,
                           l_vpdSize) );

    //Allocate memory for vpd data
    l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));

    //Second read is to get data of vpd record
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_PDW,
                           i_target,
                           l_fullVpdData,
                           l_vpdSize) );

    //#W record is laid out as follows:
    //Name:                  0x2 byte
    //Length:                0x2 byte
    //Version:               0x1 byte **buffer starts here
    //#W Bucket ID #1:       0x1 byte
    //DDSC Data for bucket 1: varies by version
    //#W Bucket ID #2:       0x1 byte
    //DDSC Data for bucket 2: varies by version

    if( *l_fullVpdData <= POUNDW_VERSION_2)
    {
        //Set the size of the bucket
        l_bucketSize = POUNDW_BUCKETID_SIZE + PW_VER_2_DDSCDATA_SIZE;
    }
    else
    {
        FAPI_ASSERT( false,
                     fapi2::INVALID_POUNDW_VERSION()
                     .set_CHIP_TARGET(i_target)
                     .set_POUNDW_VERSION(*l_fullVpdData),
                     "p10_pm_get_poundw_bucket_attr::Invalid #W record "
                     "version: 0x%x",
                     *l_fullVpdData);
    }

    //Copy version into output data
    *o_data = *l_fullVpdData;

    l_vpdSize = l_vpdSize - POUNDW_VERSION_SIZE - ((l_bucketId - 1) *
                l_bucketSize);
    // This assert ensures the size of the calculated data is correct
    FAPI_ASSERT(l_vpdSize >= l_bucketSize,
                fapi2::BAD_POUNDW_VPD_READ()
                .set_CHIP_TARGET(i_target)
                .set_EXPECTED_SIZE(l_bucketSize)
                .set_ACTUAL_SIZE(l_vpdSize),
                "#W data read was too small!" );

    // Use the selected bucket id to populate the output data
    memcpy(o_data + POUNDW_VERSION_SIZE,
           l_fullVpdData + POUNDW_VERSION_SIZE +
           ((l_bucketId - 1) * l_bucketSize),
           l_bucketSize);

    // This assert ensures the output data bucket ID matches what we looked for
    FAPI_ASSERT( (l_bucketId == ((fapi2::ddscData_t*)o_data)->bucketId),
                 fapi2::INCORRECT_POUNDW_BUCKET_ID()
                 .set_CHIP_TARGET(i_target)
                 .set_BUCKET_ID(((fapi2::ddscData_t*)o_data)->bucketId)
                 .set_EXP_BUCKET_ID(l_bucketId),
                 "Incorrect Bucket Id = %d, expected %d",
                 ((fapi2::ddscData_t*)o_data)->bucketId,
                 l_bucketId );

fapi_try_exit:

    if(l_fullVpdData != NULL)
    {
        free(l_fullVpdData);
        l_fullVpdData = NULL;
    }

    FAPI_DBG("Exiting p10_pm_get_poundw_bucket_attr ....");

    return fapi2::current_err;
}
