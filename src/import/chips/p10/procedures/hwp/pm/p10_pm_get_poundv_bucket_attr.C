/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_get_poundv_bucket_attr.C $ */
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
/// @file p10_pm_get_poundv_bucket_attr.C
/// @brief Grab PM data from certain bucket in #V keyword in CRPX record
///
/// *HWP HW Owner    :
/// *HWP FW Owner    :
/// *HWP Team        : PM - Calling this function.
/// *HWP Consumed by : FSP
/// *HWP Level       : 2
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p10_pm_get_poundv_bucket_attr.H>
#include <p10_pm_get_poundv_bucket.H>
#include <mvpd_access_defs.H>
#include <attribute_ids.H>

fapi2::ReturnCode p10_pm_get_poundv_bucket_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t* o_data)
{
    FAPI_DBG("Entering p10_pm_get_poundv_bucket_attr ....");
    uint8_t* l_prDataPtr = NULL;
    uint8_t* l_fullVpdData = NULL;
    uint8_t l_overridePresent = 0;
    uint32_t l_tempVpdSize = 0;
    uint32_t l_vpdSize = 0;
    //Default is going to bucket 1 always.To switch to other bucket,need to use
    //the system level attribute
    uint8_t l_bucketId = 1;
    uint16_t l_bucketSize = 0;
    *o_data = 0;
    uint8_t l_vpdVersion = 0;

    //check if bucket num has been overriden
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_NUM_OVERRIDE,
                           i_target,
                           l_overridePresent));

    if(l_overridePresent != 0)
    {
        //If it has been overriden then get the override
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_NUM,
                               i_target,
                               l_bucketId));
    }

    //First read is to get size of vpd record, note the o_buffer is NULL
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_PDV,
                           i_target,
                           NULL,
                           l_tempVpdSize) );


    //save off the actual vpd size
    l_vpdSize = l_tempVpdSize;
    //Allocate memory for vpd data
    l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_tempVpdSize));


    //Second read is to get data of vpd record
    FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_CRP0,
                           fapi2::MVPD_KEYWORD_PDV,
                           i_target,
                           l_fullVpdData,
                           l_tempVpdSize) );

    l_bucketSize = VERSION_2_BUCKET_SIZE;

    //Version 2:
    //#V record is laid out as follows:
    //Name:     0x2 byte
    //Length:   0x2 byte
    //Version:  0x1 byte **buffer starts here
    //bucket 1: 0x15E byte
    //bucket 2: 0x15E byte

    // Make sure we are using the supported version or barely newer
    //   The assumption we are making here is that the next
    //   version will always be backward compatible in order
    //   to allow a line-breakin of new parts.  If it is not
    //   compatible we will require an increment of 2 versions.
    l_vpdVersion = l_fullVpdData[POUNDV_VERSION_OFFSET];
    FAPI_ASSERT(((l_vpdVersion == POUNDV_VERSION_2)
                 || (l_vpdVersion == POUNDV_VERSION_3)),
                fapi2::INVALID_POUNDV_VERSION()
                .set_CHIP_TARGET(i_target)
                .set_POUNDV_VERSION(l_vpdVersion)
                .set_SUPPORTED_VERSION(POUNDV_VERSION_2),
                "#V has unsupported version!" );

    l_vpdSize = l_vpdSize - POUNDV_BUCKET_OFFSET - ((l_bucketId - 1) *
                l_bucketSize);
    // This assert ensures the size of the calculated data is correct
    FAPI_ASSERT(l_vpdSize >= l_bucketSize,
                fapi2::BAD_VPD_READ()
                .set_CHIP_TARGET(i_target)
                .set_EXPECTED_SIZE(sizeof(l_bucketSize))
                .set_ACTUAL_SIZE(l_vpdSize),
                "data read was too small!" );

    // Ensure we got a valid bucket id
    // NOTE: Bucket IDs range from 1-6
    FAPI_ASSERT( (l_bucketId <= NUM_BUCKETS) && (l_bucketId != 0),
                 fapi2::INVALID_BUCKET_ID()
                 .set_CHIP_TARGET(i_target)
                 .set_NUM_BUCKETS(NUM_BUCKETS)
                 .set_BUCKET_ID(l_bucketId),
                 "Invalid Bucket Id = %d",
                 l_bucketId );


    // Use the selected bucket id to populate the output data
    memcpy(o_data,
           l_fullVpdData + POUNDV_BUCKET_OFFSET + ((l_bucketId - 1) * l_bucketSize),
           l_bucketSize);

fapi_try_exit:

    if(l_fullVpdData != NULL)
    {
        free(l_fullVpdData);
        l_fullVpdData = NULL;
    }

    if(l_prDataPtr != NULL)
    {
        free(l_prDataPtr);
        l_prDataPtr = NULL;
    }

    FAPI_DBG("Exiting p10_pm_get_poundv_bucket_attr ....");

    return fapi2::current_err;
}
