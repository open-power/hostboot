//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/hwpf/hwp/fapiTestHwpAttr.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
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
 */

#include <fapiTestHwpAttr.H>

extern "C"
{

//******************************************************************************
// hwpTestAttributes function
//******************************************************************************
fapi::ReturnCode hwpTestAttributes()
{
    FAPI_INF("hwpTestAttributes: Start HWP");

    // Attempt to call the attribute get/set macros for the scratch attributes
    fapi::ReturnCode l_rc;

    do
    {
        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_1
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8 = 1;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint8 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. GET returned %d",
                     l_uint8);
            break;
        }

        // Test set
        l_uint8 = 7;
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. Error from GET (2)");
            break;
        }

        // Check value
        if (l_uint8 != 7)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_1. GET returned %d (2)",
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
        uint8_t l_uint8 = 8;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint8 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. GET returned %d",
                     l_uint8);
            break;
        }

        // Set to zero
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_2, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_2. Error from SET");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT32_1
        //----------------------------------------------------------------------
        {
        uint32_t l_uint32 = 1;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint32 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. GET returned %d",
                     l_uint32);
            break;
        }

        // Test set
        l_uint32 = 7;
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. Error from GET (2)");
            break;
        }

        // Check value
        if (l_uint32 != 7)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_1. GET returned %d (2)",
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
        uint32_t l_uint32 = 1;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_2, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint32 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. GET returned %d",
                     l_uint32);
            break;
        }

        // Set to zero
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_2, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_2. Error from SET");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_1
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = 1;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. Error from GET");
            break;
        }

        // Check value
        if (l_uint64 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. GET returned %d",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Test set
        l_uint64 = 7;
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. Error from GET (2)");
            break;
        }

        // Check value
        if (l_uint64 != 7)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_1. GET returned %d (2)",
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
        uint64_t l_uint64 = 1;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from GET");
            break;
        }

        // Check value
        if (l_uint64 != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. GET returned %d",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Set to zero
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_2. Error from SET");
            break;
        }
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT8_ARRAY_1
        //----------------------------------------------------------------------
        {
        uint8_t l_uint8array1[32];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 32; i++)
        {
            if (l_uint8array1[i] != 0)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY1. GET [%d] returned %d",
                          i, l_uint8array1[i]);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_1. Error from GET (2)");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 32; i++)
        {
            if (l_uint8array1[i] != (i + 1))
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY1. GET [%d] returned %d (2)",
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

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_ARRAY_2, NULL, l_uint8array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    if (l_uint8array2[i][j][k] != 0)
                    {
                        l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                        FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY2. GET [%d:%d:%d] returned %d",
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from GET (2)");
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
                        l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                        FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY2. GET [%d:%d:%d] returned %d",
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

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_ARRAY_1, NULL, l_uint32array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 8; i++)
        {
            if (l_uint32array1[i] != 0)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY1. GET [%d] returned %d",
                          i, l_uint32array1[i]);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_1. Error from GET (2)");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 8; i++)
        {
            if (l_uint32array1[i] != (i + 1))
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY1. GET [%d] returned %d (2)",
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

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_ARRAY_2, NULL, l_uint32array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                if (l_uint32array2[i][j] != 0)
                {
                    l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY2. GET [%d:%d] returned %d",
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY_2. Error from GET (2)");
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
                    l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT32_ARRAY2. GET [%d:%d] returned %d",
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
        uint64_t l_uint64array1[4];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_ARRAY_1, NULL, l_uint64array1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 4; i++)
        {
            if (l_uint64array1[i] != 0)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY1. GET [%d] returned %d",
                          i, static_cast<uint32_t>(l_uint64array1[i]));
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_1. Error from GET (2)");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 4; i++)
        {
            if (l_uint64array1[i] != (i + 1))
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY1. GET [%d] returned %d (2)",
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
        }

        //----------------------------------------------------------------------
        // Test ATTR_SCRATCH_UINT64_ARRAY_2
        //----------------------------------------------------------------------
        {
        uint64_t l_uint64 = 1;
        uint64_t l_uint64array2[2][2];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_ARRAY_2, NULL, l_uint64array2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT8_ARRAY_2. Error from GET");
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 2; j++)
            {
                if (l_uint64array2[i][j] != 0)
                {
                    l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY2. GET [%d:%d] returned %d",
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
            FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY_2. Error from GET (2)");
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
                    l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                    FAPI_ERR("hwpTestAttributes: ATTR_SCRATCH_UINT64_ARRAY2. GET [%d:%d] returned %d",
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
        uint64_t l_uint64 = fapi::ATTR_SCRATCH_UINT64_2_VAL_C;

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
        if (l_uint64 != fapi::ATTR_SCRATCH_UINT64_2_VAL_C)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
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
        // Test getting scratch attributes with the fapiGetInitFileAttr function
        //----------------------------------------------------------------------
        uint64_t l_val = 0;
        fapi::AttributeId l_id;
        fapi::AttributeId l_ids[] = {fapi::ATTR_SCRATCH_UINT8_1,
                                     fapi::ATTR_SCRATCH_UINT8_2,
                                     fapi::ATTR_SCRATCH_UINT32_1,
                                     fapi::ATTR_SCRATCH_UINT32_2,
                                     fapi::ATTR_SCRATCH_UINT64_1,
                                     fapi::ATTR_SCRATCH_UINT64_2,
                                     fapi::ATTR_SCRATCH_UINT8_ARRAY_1,
                                     fapi::ATTR_SCRATCH_UINT8_ARRAY_2,
                                     fapi::ATTR_SCRATCH_UINT32_ARRAY_1,
                                     fapi::ATTR_SCRATCH_UINT32_ARRAY_2,
                                     fapi::ATTR_SCRATCH_UINT64_ARRAY_1,
                                     fapi::ATTR_SCRATCH_UINT64_ARRAY_2};

        for (uint32_t i = 0; i < 12; i++)
        {
            l_val = 7;
            l_id = l_ids[i];
            l_rc = fapiGetInitFileAttr(l_id, NULL, l_val);

            if (l_rc)
            {
                FAPI_ERR("hwpTestAttributes: ID: %d. Error 0x%x from fapiGetInitFileAttr",
                         l_ids[i], static_cast<uint32_t>(l_rc));
                break;
            }

            if (l_val != 0)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ID: %d. Get returned %d",
                         l_ids[i], static_cast<uint32_t>(l_val));
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        //----------------------------------------------------------------------
        // Test getting an invalid scratch attribute with the
        // fapiGetInitFileAttr function
        //----------------------------------------------------------------------
        fapi::AttributeId l_badId = static_cast<fapi::AttributeId>(0xff);
        l_rc = fapiGetInitFileAttr(l_badId, NULL, l_val);

        if (l_rc)
        {
            FAPI_INF("hwpTestAttributes: Logging expected error 0x%x from fapiGetInitFileAttr",
                     static_cast<uint32_t>(l_rc));
            fapiLogError(l_rc);
            break;
        }
        else
        {
            FAPI_ERR("hwpTestAttributes: Did not get error from fapiGetInitFileAttr");
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
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

    } while (0);

    FAPI_INF("hwpTestAttributes: End HWP");
    return l_rc;
}

} // extern "C"
