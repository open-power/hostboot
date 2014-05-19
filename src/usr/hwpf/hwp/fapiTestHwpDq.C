/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwpDq.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: fapiTestHwpDq.C,v 1.3 2013/08/13 20:37:24 mjjones Exp $
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
 *
 *  HWP_IGNORE_VERSION_CHECK
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

        // Use the last DIMM
        fapi::Target & l_dimmTarg = l_dimms.back();

        // Get the DIMM's port and dimm number
        uint8_t l_port = 0;
        uint8_t l_dimm = 0;

        l_rc = FAPI_ATTR_GET(ATTR_MBA_PORT, &l_dimmTarg, l_port);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error getting ATTR_MBA_PORT");
            break;
        }

        l_rc = FAPI_ATTR_GET(ATTR_MBA_DIMM, &l_dimmTarg, l_dimm);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error getting ATTR_MBA_DIMM");
            break;
        }

        FAPI_INF("fapiTestHwpDq: Using dimm with MBA port:%d, dimm:%d",
                 l_port, l_dimm);

        // Get the bad DQ Bitmap for all ranks and print any non-zero data
        const uint8_t NUM_RANKS = 4;
        uint8_t l_rank = 0;
        for (l_rank = 0; l_rank < NUM_RANKS; l_rank++)
        {
            // Get the bad DQ Bitmap for the rank
            l_rc = dimmGetBadDqBitmap(i_mba, l_port, l_dimm, l_rank,
                                      l_dqBitmap);

            if (l_rc)
            {
                FAPI_ERR("fapiTestHwpDq: Error from dimmGetBadDqBitmap");
                break;
            }

            // Trace any bad DQs
            for (uint8_t i = 0; i < DIMM_DQ_RANK_BITMAP_SIZE; i++)
            {
                if (l_dqBitmap[i] != 0)
                {
                    FAPI_INF("fapiTestHwpDq: Non-zero DQ data. Rank:%d, Byte:%d, Val:0x%02x",
                             l_rank, i, l_dqBitmap[i]);
                }
            }
        }

        if (l_rc)
        {
            break;
        }

        // Record the two bytes of the bad DQ bitmap that this function
        // will change so that it can be restored
        uint8_t l_origDq2 = l_dqBitmap[2];
        uint8_t l_origDq6 = l_dqBitmap[6];

        // Set 2 bad DQ bits
        l_dqBitmap[2] = 0x40;
        l_dqBitmap[6] = 0x20;

        // Set the bad DQ Bitmap for the last rank
        l_rc = dimmSetBadDqBitmap(i_mba, l_port, l_dimm, l_rank - 1, l_dqBitmap);

        if (l_rc)
        {
            FAPI_ERR("fapiTestHwpDq: Error from dimmSetBadDqBitmap");
            break;
        }

        // Check that the data can be read back
        l_dqBitmap[2] = 0;
        l_dqBitmap[6] = 0;

        l_rc = dimmGetBadDqBitmap(i_mba, l_port, l_dimm, l_rank - 1, l_dqBitmap);

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

        // Write the original data back
        l_dqBitmap[2] = l_origDq2;
        l_dqBitmap[6] = l_origDq6;

        l_rc = dimmSetBadDqBitmap(i_mba, l_port, l_dimm, l_rank - 1, l_dqBitmap);

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
