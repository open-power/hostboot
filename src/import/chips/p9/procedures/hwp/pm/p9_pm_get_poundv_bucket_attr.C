/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket_attr.C $   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_get_poundv_bucket_attr.C
/// @brief Grab PM data from certain bucket in #V keyword in LRPX record
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_get_poundv_bucket_attr.H>
#include <p9_pm_get_poundv_bucket.H>
#include <mvpd_access_defs.H>
#include <attribute_ids.H>

fapi2::ReturnCode p9_pm_get_poundv_bucket_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    uint8_t* o_data)
{
    FAPI_DBG("Entering p9_pm_get_poundv_bucket_attr ....");
    uint8_t* l_prDataPtr = NULL;
    uint8_t* l_fullVpdData = NULL;
    uint8_t l_overridePresent = 0;
    uint32_t l_tempVpdSize = 0;
    uint32_t l_vpdSize = 0;
    uint8_t l_eqChipUnitPos = 0;
    uint8_t l_bucketId;
    uint8_t l_bucketSize = 0;
    uint32_t l_sysNestFreq = 0;
    fapi2::voltageBucketData_t* l_currentBucket = NULL;
    uint8_t l_numMatches = 0;

    fapi2::MvpdRecord lrpRecord = fapi2::MVPD_RECORD_LAST;
    //To read MVPD we will need the proc parent of the inputted EQ target
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procParent =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();


    //Need to determine which LRP record to read from depending on which
    //bucket we are getting the power management data from. FapiPos will
    //tell us which LRP record to use.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                           i_target,
                           l_eqChipUnitPos));

    FAPI_ASSERT( l_eqChipUnitPos < NUM_BUCKETS ,
                 fapi2::INVALID_EQ_CHIP_POS().
                 set_EQ_POSITION( l_eqChipUnitPos ),
                 "Invalid EQ chip unit position = 0x%X",
                 l_eqChipUnitPos);

    //The enumeration for the LRPx records are just 3 more
    //than the EQ chip unit pos. See mvpd_access_defs.H
    lrpRecord = static_cast<fapi2::MvpdRecord>(l_eqChipUnitPos +
                fapi2::MVPD_RECORD_LRP0 );


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
    else
    {
        //First read is to get size of vpd record, note the o_buffer is NULL
        FAPI_TRY( getMvpdField(lrpRecord,
                               fapi2::MVPD_KEYWORD_PDV,
                               l_procParent,
                               NULL,
                               l_tempVpdSize) );


        //save off the actual vpd size
        l_vpdSize = l_tempVpdSize;
        //Allocate memory for vpd data
        l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_tempVpdSize));


        //Second read is to get data of vpd record
        FAPI_TRY( getMvpdField(lrpRecord,
                               fapi2::MVPD_KEYWORD_PDV,
                               l_procParent,
                               l_fullVpdData,
                               l_tempVpdSize) );

        //Version 2:
        //#V record is laid out as follows:
        //Name:     0x2 byte
        //Length:   0x2 byte
        //Version:  0x1 byte **buffer starts here
        //PNP:      0x3 byte
        //bucket a: 0x33 byte
        //bucket b: 0x33 byte
        //bucket c: 0x33 byte
        //bucket d: 0x33 byte
        //bucket e: 0x33 byte
        //bucket f: 0x33 byte
        if( *l_fullVpdData == POUNDV_VERSION_2)
        {
            //Set the size of the bucket
            l_bucketSize = VERSION_2_BUCKET_SIZE;

            //Reset VPD size because we want to find size of another VPD record
            l_tempVpdSize = 0;

            //First read is to get size of vpd record, note the o_buffer is NULL
            FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_VINI,
                                   fapi2::MVPD_KEYWORD_PR,
                                   l_procParent,
                                   NULL,
                                   l_tempVpdSize) );

            l_prDataPtr = reinterpret_cast<uint8_t*>(malloc(l_tempVpdSize));

            //Second read is to get data of vpd record
            FAPI_TRY( getMvpdField(fapi2::MVPD_RECORD_VINI,
                                   fapi2::MVPD_KEYWORD_PR,
                                   l_procParent,
                                   l_prDataPtr,
                                   l_tempVpdSize) );

            //Bucket ID is byte[4] of the PR keyword
            memcpy(&l_bucketId, (l_prDataPtr + 4), sizeof(uint8_t));

        }
        //Version 3:
        //#V record is laid out as follows:
        //Name:     0x2 byte
        //Length:   0x2 byte
        //Version:  0x1 byte **buffer starts here
        //PNP:      0x3 byte
        //bucket a: 0x3D byte
        //bucket b: 0x3D byte
        //bucket c: 0x3D byte
        //bucket d: 0x3D byte
        //bucket e: 0x3D byte
        //bucket f: 0x3D byte
        else if( *l_fullVpdData == POUNDV_VERSION_3 )
        {
            // Set the size of the bucket
            l_bucketSize = VERSION_3_BUCKET_SIZE;

            // Version 3 uses the nest frequency to choose the bucket Id
            // get the system target to find the NEST_FREQ_MHZ
            fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> l_sysParent;


            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB_MHZ,
                                   l_sysParent,
                                   l_sysNestFreq));
            //cast the voltage data into an array of buckets
            fapi2::voltageBucketData_t* l_buckets = reinterpret_cast
                                                    <fapi2::voltageBucketData_t*>
                                                    (l_fullVpdData + POUNDV_BUCKET_OFFSET);

            for(int i = 0; i < NUM_BUCKETS; i++)
            {
                if(l_buckets[i].pbFreq == l_sysNestFreq)
                {
                    l_numMatches++;

                    /*
                     * TODO RTC: 157341
                     * Modify function to fail if multiple buckets have same nest
                     */
                    if(l_numMatches > 1)
                    {
                        FAPI_ERR("p9_pm_get_poundv_bucket_attr::"
                                 " Multiple buckets (%d) reporting the same nest frequency",
                                 l_numMatches);
                    }

                    /*
                    else
                    {
                        l_currentBucket = &l_buckets[i];
                    }
                    */
                    l_currentBucket = &l_buckets[i];
                }
            }

            /*
             * TODO RTC: 157341
             * Modify function to fail if multiple buckets have same nest
             if(l_numMatches == 1)
             {
                 l_bucketId = l_currentBucket->bucketId;
             }
             else
             {

                 FAPI_ERR("p9_pm_get_poundv_bucket_attr::Invalid number of matching nest freqs found. Matches found = %d",
                          l_numMatches );
                 FAPI_ASSERT(0,
                             fapi2::INVALID_MATCHING_FREQ_NUMBER().
                             set_MATCHES_FOUND(l_numMatches),
                             "Matches found is NOT 1" );
             }
             */
            l_bucketId = l_currentBucket->bucketId;
        }
        else
        {
            FAPI_ASSERT( false,
                         fapi2::INVALID_POUNDV_VERSION()
                         .set_POUNDV_VERSION(*l_fullVpdData),
                         "p9_pm_get_poundv_bucket_attr::Invalid #V record version: 0x%x",
                         *l_fullVpdData);
        }

        // This assert ensures the size of the calculated data is correct
        FAPI_ASSERT(l_vpdSize - POUNDV_BUCKET_OFFSET - ((l_bucketId - 1) *
                    l_bucketSize) >= l_bucketSize,
                    fapi2::BAD_VPD_READ().set_EXPECTED_SIZE(sizeof(l_bucketSize))
                    .set_ACTUAL_SIZE(l_vpdSize - POUNDV_BUCKET_OFFSET -
                                     ((l_bucketId - 1) * l_bucketSize)),
                    "#V data read was too small!" );

    }// else no override

    // Ensure we got a valid bucket id
    // NOTE: Bucket IDs range from 1-6
    FAPI_ASSERT( (l_bucketId <= NUM_BUCKETS) && (l_bucketId != 0),
                 fapi2::INVALID_BUCKET_ID()
                 .set_TARGET(i_target)
                 .set_BUCKET_ID(l_bucketId),
                 "Invalid Bucket Id = %d",
                 l_bucketId );


    // Use the selected bucket id to populate the output data
    memcpy(o_data,
           l_fullVpdData + POUNDV_BUCKET_OFFSET + (l_bucketId - 1) * l_bucketSize,
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

    FAPI_DBG("Exiting p9_pm_get_poundv_bucket_attr ....");

    return fapi2::current_err;
}


