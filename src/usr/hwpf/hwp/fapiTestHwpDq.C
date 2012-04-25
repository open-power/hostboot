/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/hwpf/hwp/fapiTestHwpDq.C $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file fapiTestHwpDq.C
 *
 *  @brief Implements a Test Hardware Procedure that exercises the bad DQ data
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/21/2012  Created
 *                          mjjones     06/14/2012  Test functional DIMM
 */

#include <fapiTestHwpDq.H>
#include <dimmBadDqBitmapFuncs.H>

extern "C"
{

fapi::ReturnCode fapiTestHwpDq(const fapi::Target & i_mba)
{
    FAPI_INF(">>fapiTestHwpDq: %s", i_mba.toEcmdString());

    fapi::ReturnCode l_rc;
    uint8_t l_dqBitmap[DIMM_DQ_RANK_BITMAP_SIZE];

    do
    {
        // Get the bad DQ Bitmap with an incorrect port
        l_rc = dimmGetBadDqBitmap(i_mba, 5, 0, 0, l_dqBitmap);

        if (!l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Did not get expected error from dimmGetBadDqBitmap");
            FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DQ_NO_ERR_ON_BAD_PARAMS);
            break;
        }

        // Do not log error to avoid adding an expected error to the log
        FAPI_INF("fapiTestHwpDq: Got expected error from dimmGetBadDqBitmap");
        l_rc = fapi::FAPI_RC_SUCCESS;

        // Get associated functional DIMMs
        std::vector<fapi::Target> l_dimms;
        l_rc = fapiGetAssociatedDimms(i_mba, l_dimms);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from fapiGetAssociatedDimms");
            break;
        }

        if (l_dimms.size() == 0)
        {
            FAPI_ERR("fapiTestHwpDq: Did not find any functional DIMMs, skipping");
            break;
        }

        // Get the first DIMM's port and dimm number
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;

        l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &(l_dimms[0]), l_port);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error getting ATTR_MBA_PORT");
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &(l_dimms[0]), l_dimm);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error getting ATTR_MBA_DIMM");
            break;
        }

        // Get the bad DQ Bitmap for the DIMM, rank 3
        l_rc = dimmGetBadDqBitmap(i_mba, l_port, l_dimm, 3, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from dimmGetBadDqBitmap");
            break;
        }

        // If the data is not all zeroes then skip the rest of the test, do not
        // want to modify any real Bad DQ records
        bool l_nonZeroData = false;

        for (uint8_t i = 0; i < DIMM_DQ_RANK_BITMAP_SIZE; i++)
        {
            if (l_dqBitmap[i] != 0)
            {
                FAPI_INF("fapiTestHwpDq: Non-zero DQ data, skipping test");
                l_nonZeroData = true;
                break;
            }
        }

        if (l_nonZeroData)
        {
            break;
        }

        // Set 2 bad DQ bits
        l_dqBitmap[2] = 0x40;
        l_dqBitmap[6] = 0x20;

        // Set the bad DQ Bitmap
        l_rc = dimmSetBadDqBitmap(i_mba, 1, 0, 3, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from dimmSetBadDqBitmap");

            // TODO
            FAPI_ERR("fapiTestHwpDq: Waiting for SPD DD support for writes (story 35766)");
            l_rc = fapi::FAPI_RC_SUCCESS;
            break;
        }

        // Check that the data can be read back
        l_dqBitmap[2] = 0;
        l_dqBitmap[6] = 0;

        l_rc = dimmGetBadDqBitmap(i_mba, 1, 0, 3, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from dimmGetBadDqBitmap (2)");
            break;
        }

        if ((l_dqBitmap[2] != 0x40) || (l_dqBitmap[6] != 0x20))
        {
            FAPI_ERR("fapiTestHwpDq: Got bad data 0x%x:0x%x",
                     l_dqBitmap[2], l_dqBitmap[6]);
            uint8_t & FFDC_DATA1 = l_dqBitmap[2];
            uint8_t & FFDC_DATA2 = l_dqBitmap[6];
            FAPI_SET_HWP_ERROR(l_rc, RC_TEST_DQ_BAD_DATA);
            break;
        }

        // Write the data back to zero
        l_dqBitmap[2] = 0;
        l_dqBitmap[6] = 0;

        l_rc = dimmSetBadDqBitmap(i_mba, 1, 0, 3, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from dimmSetBadDqBitmap (2)");
            break;
        }

    } while (0);

    FAPI_INF("<<fapiTestHwpDq");
    return l_rc;
}


} // extern "C"
