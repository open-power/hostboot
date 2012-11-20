/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/fapiTestHwpAttr.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 *  @file fapiTestHwpAttr.C
 *
 *  @brief Implements the test Hardware Procedure that exercises the scratch
 *         attributes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/30/2011  Created.
 *                          mjjones     09/07/2011  Update to test scratch attrs
 *                          mjjones     10/06/2011  Updates traces
 *                          mjjones     10/07/2011  Removed target param
 *                          mjjones     10/15/2011  Test scratch attributes
 *                          mjjones     10/17/2011  Update scratch test
 *                          camvanng    10/26/2011  Update scratch test
 *                          mjjones     10/28/2011  Fix error generation
 *                          camvanng    11/09/2011  Update attr enum test
 *                          mjjones     11/17/2011  Removed some initfile attr tests
 *                          mjjones     11/22/2011  Demonstrate use of heap based array
 *                          mjjones     10/19/2012  Update AttributeTank tests
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

#include <fapiTestHwpAttr.H>

extern "C"
{

//******************************************************************************
// hwpTestAttributes function
//******************************************************************************
fapi::ReturnCode hwpTestAttributes(fapi::Target & i_mbaTarget,
                                   fapi::Target & i_procTarget)
{
    FAPI_INF("hwpTestAttributes: Start HWP");
    fapi::ReturnCode l_rc;

    do
    {
        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_1
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8 = 7;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. Error from SET");
            break;
        }

        // Test get
        l_uint8 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint8 != 7)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. GET returned %d",
                     l_uint8);
            break;
        }

        // Set to zero
        l_uint8 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_2
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8 = 6;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. Error from SET");
            break;
        }

        // Test get
        l_uint8 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint8 != 6)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. GET returned %d",
                     l_uint8);
            break;
        }

        // Set to zero
        l_uint8 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT32_1
        //----------------------------------------------------------------------
        {
        uint32_t l_uint32 = 5;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. Error from SET");
            break;
        }

        // Test get
        l_uint32 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint32 != 5)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. GET returned %d",
                     l_uint32);
            break;
        }

        // Set to zero
        l_uint32 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT32_2
        //----------------------------------------------------------------------
        {
        uint32_t l_uint32 = 4;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_2, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. Error from SET");
            break;
        }

        // Test get
        l_uint32 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_2, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint32 != 4)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. GET returned %d",
                     l_uint32);
            break;
        }

        // Set to zero
        l_uint32 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_2, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_1
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = 3;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. Error from SET");
            break;
        }

        // Test get
        l_uint64 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint64 != 3)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. GET returned %d",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Set to zero
        l_uint64 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_2
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = 2;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from SET");
            break;
        }

        // Test get
        l_uint64 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint64 != 2)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. GET returned %d",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Set to zero
        l_uint64 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_ARRAY_1
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8array1[32];

        // Test set
        for (uint32_t i = 0; i < 32; i++)
        {
            l_uint8array1[i] = i + 1;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 32; i++)
        {
            l_uint8array1[i] = 0;
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 32; i++)
        {
            if (l_uint8array1[i] != (i + 1))
            {
                FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. GET [%d] returned %d",
                          i, l_uint8array1[i]);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 32; i++)
        {
            l_uint8array1[i] = 0;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_ARRAY_2
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8 = 1;
        uint8_t l_uint8array2[2][3][4];

        // Test set
        l_uint8 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    l_uint8array2[i][j][k] = l_uint8++;
                }
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_2, NULL, l_uint8array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    l_uint8array2[i][j][k] = 0;
                }
            }
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_ARRAY_2, NULL, l_uint8array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        l_uint8 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    if (l_uint8array2[i][j][k] != l_uint8++)
                    {
                        FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                        FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. GET [%d:%d:%d] returned %d",
                                 i, j, k, l_uint8array2[i][j][k]);
                        break;
                    }
                }
                if (l_rc)
                {
                    break;
                }
            }
            if (l_rc)
            {
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    l_uint8array2[i][j][k] = 0;
                }
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_2, NULL, l_uint8array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT32_ARRAY_1
        //----------------------------------------------------------------------
        {
        uint32_t l_uint32array1[8];

        // Test set
        for (uint32_t i = 0; i < 8; i++)
        {
            l_uint32array1[i] = i + 1;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_ARRAY_1, NULL, l_uint32array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 8; i++)
        {
            l_uint32array1[i] = 0;
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_ARRAY_1, NULL, l_uint32array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 8; i++)
        {
            if (l_uint32array1[i] != (i + 1))
            {
                FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. GET [%d] returned %d",
                          i, l_uint32array1[i]);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 8; i++)
        {
            l_uint32array1[i] = 0;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_ARRAY_1, NULL, l_uint32array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT32_ARRAY_2
        //----------------------------------------------------------------------
        {
        uint32_t l_uint32 = 1;
        uint32_t l_uint32array2[2][3];

        // Test set
        l_uint32 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                l_uint32array2[i][j] = l_uint32++;
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_uint32array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_2. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                l_uint32array2[i][j] = 0;
            }
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_uint32array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        l_uint32 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                if (l_uint32array2[i][j] != l_uint32++)
                {
                    FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_2. GET [%d:%d] returned %d",
                             i, j, l_uint32array2[i][j]);
                    break;
                }
            }
            if (l_rc)
            {
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                l_uint32array2[i][j]= 0;
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_uint32array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_ARRAY_1
        //----------------------------------------------------------------------
        {
        // Demonstrate the use of a heap based array
        uint64_t (&l_uint64array1)[4] = *(reinterpret_cast<uint64_t(*)[4]>(new uint64_t[4]));

        // Test set
        for (uint32_t i = 0; i < 4; i++)
        {
            l_uint64array1[i] = i + 1;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_ARRAY_1, NULL, l_uint64array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 4; i++)
        {
            l_uint64array1[i] = 0;
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_ARRAY_1, NULL, l_uint64array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 4; i++)
        {
            if (l_uint64array1[i] != (i + 1))
            {
                FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. GET [%d] returned %d",
                          i, static_cast<uint32_t>(l_uint64array1[i]));
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 4; i++)
        {
            l_uint64array1[i] = 0;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_ARRAY_1, NULL, l_uint64array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. Error from SET (2)");
            break;
        }

        delete [] &l_uint64array1;
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_ARRAY_2
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = 1;
        uint64_t l_uint64array2[2][2];

        // Test set
        l_uint64 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                l_uint64array2[i][j] = l_uint64++;
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_uint64array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_2. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                l_uint64array2[i][j] = 0;
            }
        }

        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_uint64array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        l_uint64 = 1;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                if (l_uint64array2[i][j] != l_uint64++)
                {
                    FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_2. GET [%d:%d] returned %d",
                             i, j, static_cast<uint32_t>(l_uint64array2[i][j]));
                    break;
                }
            }
            if (l_rc)
            {
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Set to zero
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                l_uint64array2[i][j]= 0;
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_uint64array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_2. Error from SET (2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test setting and getting an enum value from a scratch attribute
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = fapi::ENUM_ATTR_SCRATCH_UINT64_2_VAL_C;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from SET (enum)");
            break;
        }

        // Test get
        l_uint64 = 0;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from GET (enum)");
            break;
        }

        // Check value
        if (l_uint64 != fapi::ENUM_ATTR_SCRATCH_UINT64_2_VAL_C)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. GET returned %d (enum)",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Set to zero
        l_uint64 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from SET (enum2)");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Removed getting scratch attributes using fapiGetInitFileAttr(). This
        // now only supports the getting of attributes that are actually used by
        // initfiles and those are excercised by the test initfile
        //----------------------------------------------------------------------

        //----------------------------------------------------------------------
        // Test getting an invalid attribute using fapiGetInitFileAttr()
        //----------------------------------------------------------------------
        uint64_t l_val = 0;
        fapi::AttributeId l_badId = static_cast<fapi::AttributeId>(0xff);
        l_rc = fapiGetInitFileAttr(l_badId, NULL, l_val);

        if (l_rc)
        {
            // Delete the error rather than logging it to avoid it getting
            // interpreted as a real problem
            FAPI_INF("hwpTestAttributes: Deleting expected error 0x%x from fapiGetInitFileAttr",
                     static_cast<uint32_t>(l_rc));
            l_rc = fapi::FAPI_RC_SUCCESS;
        }
        else
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Did not get error from fapiGetInitFileAttr");
            break;
        }

        //----------------------------------------------------------------------
        // Test invalid accesses
        //----------------------------------------------------------------------

        // All of the following should not compile due to wrong types used
        {
        //uint32_t l_val;
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_val);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_val);
        }
        {
        //uint64_t l_val;
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_1, NULL, l_val);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_val);
        }
        {
        //uint8_t l_val;
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_1, NULL, l_val);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_val);
        }
        {
        //uint8_t l_array[33]; // size should be 32
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_array);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_array);
        }
        {
        //uint8_t l_array[2][3]; // type should be uint32_t
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_array);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_array);
        }
        {
        //uint64_t l_array[2][1]; // second dimension should be 2
        //l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_array);
        //l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_array);
        }
        
        //----------------------------------------------------------------------
        // Test AttributeTank functions with empty tank
        //----------------------------------------------------------------------
        {
        // Create a local OverrideAttributeTank (this is not the singleton)
        fapi::OverrideAttributeTank l_tank;
        
        // Check that tank is empty
        if (l_tank.attributesExist())
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. AttributeTank is not empty (1.1)");
            break;
        }
        
        // Clear all attributes from empty tank
        l_tank.clearAllAttributes();
        
        // Clear a non-const system attribute from empty tank
        l_tank.clearNonConstAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL);
        
        // Try to get a system attribute from empty tank
        uint64_t l_val = 0;
        if (l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL, l_val))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got sys attr from empty tank (1.2)");
            break;
        }
        
        // Try to get a chiplet attribute from empty tank
        if (l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_1, &i_mbaTarget,
                                l_val))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got chiplet attr from empty tank (1.3)");
            break;
        }
        
        // Try to get all attributes from empty tank
        std::vector<fapi::AttributeChunk> l_attributes;
        l_tank.getAllAttributes(fapi::AttributeTank::ALLOC_TYPE_MALLOC,
                                l_attributes);

        if (l_attributes.size())
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got all attrs from empty tank (1.4)");
            break;
        }
        }
        
        //----------------------------------------------------------------------
        // Test AttributeTank functions with single attribute in tank
        //----------------------------------------------------------------------
        {
        // Create a local OverrideAttributeTank (this is not the singleton)
        fapi::OverrideAttributeTank l_tank;
        
        // Add ATTR_SCRATCH_UINT64_1 as a sytem attribute to the tank
        uint64_t l_val = 4;
        l_tank.setAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL, l_val);
        
        // Check that attributes exist in the tank
        if (!l_tank.attributesExist())
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. AttributeTank is empty (2.1)");
            break;
        }
        
        // Try to get the wrong attribute from the tank
        l_val = 0;
        if (l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_2, NULL, l_val))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong attr from tank (2.2)");
            break;
        }
        
        // Get the attribute from the tank
        if (!(l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL, l_val)))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Did not get attr from tank (2.3)");
            break;
        }
        
        if (l_val != 4)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (2.4)",
                     l_val);
            break;
        }
        
        // Get all attributes from the tank
        std::vector<fapi::AttributeChunk> l_attributes;
        l_tank.getAllAttributes(fapi::AttributeTank::ALLOC_TYPE_NEW,
                                l_attributes);
        
        if (l_attributes.size() != 1)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong chunk size (%d) of attrs from tank (2.5)",
                     l_attributes.size());
            break;
        }
            
        if (l_attributes[0].iv_numAttributes != 1)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong size (%d) of attrs from tank (2.6)",
                     l_attributes[0].iv_numAttributes);
            break;
        }
        
        fapi::Attribute * l_pAttr = reinterpret_cast<fapi::Attribute *>
            (l_attributes[0].iv_pAttributes);
        if (l_pAttr[0].iv_val != 4)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (2.7)",
                     l_pAttr[0].iv_val);
            break;
        }
        delete [] l_attributes[0].iv_pAttributes;
        }
        
        //----------------------------------------------------------------------
        // Test AttributeTank functions with multiple attributes in tank
        //----------------------------------------------------------------------
        {
        // Create a local OverrideAttributeTank (this is not the singleton)
        fapi::OverrideAttributeTank l_tank;
        
        // Add ATTR_SCRATCH_UINT64_1 as a chip attribute to the tank
        uint64_t l_val = 4;
        l_tank.setAttribute(fapi::ATTR_SCRATCH_UINT64_1, &i_procTarget, l_val);
        
        // Add ATTR_SCRATCH_UINT64_2 as an MBA attribute to the tank
        l_val = 5;
        l_tank.setAttribute(fapi::ATTR_SCRATCH_UINT64_2, &i_mbaTarget, l_val);
        
        // Get the first attribute from the tank
        if (!(l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_1, &i_procTarget, l_val)))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Did not get attr from tank (3.1)");
            break;
        }
        
        if (l_val != 4)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (3.2)",
                     l_val);
            break;
        }
        
        // Get the second attribute from the tank
        if (!(l_tank.getAttribute(fapi::ATTR_SCRATCH_UINT64_2, &i_mbaTarget, l_val)))
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Did not get attr from tank (3.3)");
            break;
        }
        
        if (l_val != 5)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (3.4)",
                     l_val);
            break;
        }
        
        // Get all attributes from the tank
        std::vector<fapi::AttributeChunk> l_attributes;
        l_tank.getAllAttributes(fapi::AttributeTank::ALLOC_TYPE_MALLOC,
                                l_attributes);
        
        if (l_attributes.size() != 1)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong chunk size (%d) of attrs from tank (3.5)",
                     l_attributes.size());
            break;
        }
        
        if (l_attributes[0].iv_numAttributes != 2)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong size (%d) of attrs from tank (3.6)",
                     l_attributes[0].iv_numAttributes);
            break;
        }
        
        fapi::Attribute * l_pAttr = reinterpret_cast<fapi::Attribute *>
            (l_attributes[0].iv_pAttributes);
        if (l_pAttr[0].iv_val != 4)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (3.7)",
                     l_pAttr[0].iv_val);
            break;
        }
        
        if (l_pAttr[1].iv_val != 5)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (3.8)",
                     l_pAttr->iv_val);
            break;
        }
        
        free (l_attributes[0].iv_pAttributes);
        }
        
        //----------------------------------------------------------------------
        // Test AttributeTank functions with constant attribute
        //----------------------------------------------------------------------
        {
        // Create a local OverrideAttributeTank (this is not the singleton)
        fapi::OverrideAttributeTank l_tank;
        
        // Set const attribute
        fapi::Attribute l_attr;
        l_attr.iv_val = 7;
        l_attr.iv_attrId = fapi::ATTR_SCRATCH_UINT64_2;
        l_attr.iv_targetType = fapi::TARGET_TYPE_SYSTEM;
        l_attr.iv_pos = fapi::ATTR_POS_NA;
        l_attr.iv_unitPos = fapi::ATTR_UNIT_POS_NA;
        l_attr.iv_flags = fapi::ATTR_FLAG_CONST;
        l_attr.iv_arrayD1 = 0;
        l_attr.iv_arrayD2 = 0;
        l_attr.iv_arrayD3 = 0;
        l_attr.iv_arrayD4 = 0;
        l_tank.setAttribute(l_attr);
            
        // Try to clear the attribute, it should not be cleared
        l_tank.clearNonConstAttribute(fapi::ATTR_SCRATCH_UINT64_2, NULL);
        
        // Check that tank is not-empty
        if (!l_tank.attributesExist())
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. AttributeTank is empty (4.1)");
            break;
        }
        
        // Clear all attribute
        l_tank.clearAllAttributes();
        
        // Check that tank is empty
        if (l_tank.attributesExist())
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. AttributeTank is not empty (4.2)");
            break;
        }
        }
        
        //----------------------------------------------------------------------
        // Test adding the same attribute twice to a tank
        //----------------------------------------------------------------------
        {
        // Create a local OverrideAttributeTank (this is not the singleton)
        fapi::OverrideAttributeTank l_tank;
        
        // Add ATTR_SCRATCH_UINT64_1 to the tank twice
        uint64_t l_val = 4;
        l_tank.setAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL, l_val);
        l_val = 5;
        l_tank.setAttribute(fapi::ATTR_SCRATCH_UINT64_1, NULL, l_val);
        
        // Get all attributes from the tank
        std::vector<fapi::AttributeChunk> l_attributes;
        l_tank.getAllAttributes(fapi::AttributeTank::ALLOC_TYPE_MALLOC,
                                l_attributes);
        
        if (l_attributes.size() != 1)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong chunk size (%d) of attrs from tank (5.1)",
                     l_attributes.size());
            break;
        }
        
        if (l_attributes[0].iv_numAttributes != 1)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got wrong size (%d) of attrs from tank (5.2)",
                     l_attributes[0].iv_numAttributes);
            break;
        }
        
        fapi::Attribute * l_pAttr = reinterpret_cast<fapi::Attribute *>
            (l_attributes[0].iv_pAttributes);
        if (l_pAttr[0].iv_val != 5)
        {
            FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
            FAPI_ERR("hwpTestAttributes: Error. Got bad value (0x%llx) from tank (5.3)",
                     l_pAttr[0].iv_val);
            break;
        }
        
        free (l_attributes[0].iv_pAttributes);
        }
        
    } while (0);

    FAPI_INF("hwpTestAttributes: End HWP");
    return l_rc;
}

} // extern "C"
