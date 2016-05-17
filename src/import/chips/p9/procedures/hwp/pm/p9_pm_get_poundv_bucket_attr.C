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
#include <mvpd_access_defs.H>
#include <attribute_ids.H>

fapi2::ReturnCode p9_pm_get_poundv_bucket_attr(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
    uint8_t* o_data)
{
    FAPI_IMP("Entering p9_pm_get_poundv_bucket_attr ....");
    uint8_t* l_prDataPtr = NULL;
    uint8_t* l_fullVpdData = NULL;
    uint8_t l_overridePresent = 0;
    uint32_t l_vpdSize = 0;
    uint8_t l_eqChipUnitPos = 0;
    uint8_t l_bucketId;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    do
    {
        //To read MVPD we will need the proc parent of the inputted EQ target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procParent =
            i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

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
            //Otherwise get the bucket num from MVPD data
            //First read is to get size of vpd record, note the o_buffer is NULL
            l_rc = getMvpdField(fapi2::MVPD_RECORD_VINI,
                                fapi2::MVPD_KEYWORD_PR,
                                l_procParent,
                                NULL,
                                l_vpdSize);

            if(l_rc)
            {
                FAPI_ERR("p9_pm_get_poundv_bucket_attr:: Error reading PR keyword size from VINI record");
                break;
            }

            l_prDataPtr = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));

            //Second read is to get data of vpd record
            l_rc = getMvpdField(fapi2::MVPD_RECORD_VINI,
                                fapi2::MVPD_KEYWORD_PR,
                                l_procParent,
                                l_prDataPtr,
                                l_vpdSize);

            if(l_rc)
            {
                FAPI_ERR("p9_pm_get_poundv_bucket_attr:: Error reading PR keyword from VINI record");
                break;
            }

            //Bucket ID is byte[4] of the PR keyword
            memcpy(&l_bucketId, (l_prDataPtr + 4), sizeof(uint8_t));
        }


        //Need to determine which LRP record to read from depending on which
        //bucket we are getting the power management data from. FapiPos will
        //tell us which LRP record to use.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               i_target,
                               l_eqChipUnitPos));
        fapi2::MvpdRecord lprRecord;

        switch(l_eqChipUnitPos)
        {
            case 0:
                lprRecord = fapi2::MVPD_RECORD_LRP0;
                break;

            case 1:
                lprRecord = fapi2::MVPD_RECORD_LRP1;
                break;

            case 2:
                lprRecord = fapi2::MVPD_RECORD_LRP2;
                break;

            case 3:
                lprRecord = fapi2::MVPD_RECORD_LRP3;
                break;

            case 4:
                lprRecord = fapi2::MVPD_RECORD_LRP4;
                break;

            case 5:
                lprRecord = fapi2::MVPD_RECORD_LRP5;
                break;

            default:
                FAPI_ERR("No LRP record found for EQ with fapi pos = %d", l_eqChipUnitPos);
                assert(0);
                break;
        }

        //Reset VPD size because we want to find size of another VPD record
        l_vpdSize = 0;

        //First read is to get size of vpd record, note the o_buffer is NULL
        l_rc = getMvpdField(lprRecord,
                            fapi2::MVPD_KEYWORD_PDV,
                            l_procParent,
                            NULL,
                            l_vpdSize);

        if(l_rc)
        {
            FAPI_ERR("p9_pm_get_poundv_bucket_attr:: Error reading PDV keyword size from LRP%d record", l_eqChipUnitPos);
            break;
        }

        //Allocate memory for vpd data
        l_fullVpdData = reinterpret_cast<uint8_t*>(malloc(l_vpdSize));

        FAPI_ASSERT(l_vpdSize - 4 - ((l_bucketId - 1) * 0x33) >= sizeof(fapi2::ATTR_POUNDV_BUCKET_DATA_Type),
                    fapi2::BAD_VPD_READ()
                    .set_EXPECTED_SIZE(sizeof(fapi2::ATTR_POUNDV_BUCKET_DATA_Type))
                    .set_ACTUAL_SIZE(l_vpdSize - 4 - ((l_bucketId - 1) * 0x33)),
                    "#V data read was too small!" );

        //Second read is to get data of vpd record
        l_rc = getMvpdField(lprRecord,
                            fapi2::MVPD_KEYWORD_PDV,
                            l_procParent,
                            l_fullVpdData,
                            l_vpdSize);

        if(l_rc)
        {
            FAPI_ERR("p9_pm_get_poundv_bucket_attr:: Error reading PDV keyword from LRP%d record", l_eqChipUnitPos);
            break;
        }

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
        if( *l_fullVpdData == 0x2)
        {
            memcpy(o_data,
                   l_fullVpdData + 4 + (l_bucketId - 1) * 0x33,
                   sizeof(fapi2::ATTR_POUNDV_BUCKET_DATA_Type));
        }
        else
        {
            FAPI_ERR("p9_pm_get_poundv_bucket_attr::Invalid #V record version: 0x%x", *l_fullVpdData);
            FAPI_ASSERT(0,
                        fapi2::INVALID_POUNDV_VERSION()
                        .set_POUNDV_VERSION(*l_fullVpdData),
                        "#V is of an invalid version!" );
        }


    }
    while(0);

fapi_try_exit:

    if(l_fullVpdData != NULL)
    {
        free(l_fullVpdData);
    }

    if(l_prDataPtr != NULL)
    {
        free(l_prDataPtr);
    }

    FAPI_IMP("Exiting p9_pm_get_poundv_bucket_attr ....");

    //If there is no issue in the current err, check
    //the local rc to see if the mvpd access methods caught anything
    if((fapi2::current_err == fapi2::FAPI2_RC_SUCCESS) &&
       (l_rc != fapi2::FAPI2_RC_SUCCESS))
    {
        fapi2::current_err = l_rc;
    }

    return fapi2::current_err;
}


