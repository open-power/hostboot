/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_get_poundv_bucket.C $        */
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
/// @file p9_pm_get_poundv_bucket.C
/// @brief Grab PM data from attribute
///

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <p9_pm_get_poundv_bucket.H>
#include <attribute_ids.H>

fapi2::ReturnCode p9_pm_get_poundv_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    fapi2::voltageBucketData_t& o_data)
{
    FAPI_IMP("Entering p9_pm_get_poundv_bucket ....");


    //Create a pointer version of the out param o_data so that
    // we can access bytes individually
    uint8_t* l_tempBuffer = reinterpret_cast<uint8_t*>(malloc(sizeof(o_data)));

    //Set up a char array to hold the bucket data from an attr read
    fapi2::ATTR_POUNDV_BUCKET_DATA_Type l_bucketAttr;

    //Perform an ATTR_GET for POUNDV_BUCKET data on the EQ target
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_POUNDV_BUCKET_DATA,
                           i_target,
                           l_bucketAttr));


#ifndef _BIG_ENDIAN
    //The first byte is simply a uint8 that describes the bucket ID
    l_tempBuffer[0] = l_bucketAttr[0];

    //Skipping the first byte (which has already been taken of) start reading
    //the voltage data 2 bytes at a time.
    for(uint8_t offset = 1; offset < sizeof(o_data); offset += 2)
    {
        //Switch from Big Endian to Little Endian
        l_tempBuffer[offset] = l_bucketAttr[offset + 1];
        l_tempBuffer[offset + 1] = l_bucketAttr[offset];
    }

    memcpy(&o_data,
           l_tempBuffer,
           sizeof(o_data));

#else
    memcpy(&o_data,
           l_bucketAttr,
           sizeof(o_data));
#endif


fapi_try_exit:
    free(l_tempBuffer);
    FAPI_IMP("Exiting p9_pm_get_poundv_bucket ....");

    return fapi2::current_err;
}
