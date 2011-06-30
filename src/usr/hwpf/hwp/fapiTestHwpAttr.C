/**
 *  @file fapiTestHwpAttr.C
 *
 *  @brief Implements the test Hardware Procedure that exercises the test
 *         attributes
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     06/30/2011  Created.
 *
 */

#include <fapiTestHwpAttr.H>

extern "C"
{

//******************************************************************************
// hwpTestAttributes function
//******************************************************************************
fapi::ReturnCode hwpTestAttributes()
{
    // Attempt to call the attribute get/set functions for the test attributes
    fapi::ReturnCode l_rc;

    // Test getting and setting the test attributes
    do
    {
        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT8 (DefaultVal 6)
        //----------------------------------------------------------------------
        uint8_t l_uint8 = 0;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8. Error from GET");
            break;
        }

        // Check value
        if (l_uint8 != 6)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8. GET returned %d",
                     l_uint8);
            break;
        }

        // Test set
        l_uint8 = 7;
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8. Error from SET");
            break;
        }

        // Test get
        l_uint8 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8, NULL, l_uint8);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8. Error from GET (2)");
            break;
        }

        // Check value
        if (l_uint8 != 7)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8. GET returned %d (2)",
                     l_uint8);
            break;
        }

        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT32 (PLAT (sets val to 3). RO)
        //----------------------------------------------------------------------
        uint32_t l_uint32 = 0;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32, NULL, l_uint32);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32. Error from GET");
            break;
        }

        // Check value
        if (l_uint32 != 3)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32. GET returned %d",
                     l_uint32);
            break;
        }

        // Cannot set read-only attribute

        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT64 (Enum. DefaultVal VALB)
        //----------------------------------------------------------------------
        uint64_t l_uint64 = 0;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64. Error from GET");
            break;
        }

        // Check value
        if (l_uint64 != fapi::ATTR_TEST_UINT64_VALB)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64. GET returned %d",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        // Test set
        l_uint64 = fapi::ATTR_TEST_UINT64_VALA;
        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64. Error from SET");
            break;
        }

        // Test get
        l_uint64 = fapi::ATTR_TEST_UINT64_VALC;
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, NULL, l_uint64);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64. Error from GET (2)");
            break;
        }

        if (l_uint64 != fapi::ATTR_TEST_UINT64_VALA)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64. GET returned %d (2)",
                     static_cast<uint32_t>(l_uint64));
            break;
        }

        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT8_ARRAY ([3], DefaultVal 2)
        //----------------------------------------------------------------------
        uint8_t l_uint8Array[3];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8_ARRAY, NULL, l_uint8Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8_ARRAY. Error from GET");
            break;
        }

        // Check values
        for (uint32_t i = 0; i < 3; i++)
        {
            if (l_uint8Array[i] != 2)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8_ARRAY GET "
                        "returned %d in index %d", l_uint8Array[i], i);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Test set
        l_uint8Array[0] = 0;
        l_uint8Array[1] = 1;
        l_uint8Array[2] = 2;

        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8_ARRAY, NULL, l_uint8Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8_ARRAY. Error from SET");
            break;
        }

        // Test get
        l_uint8Array[0] = 6;
        l_uint8Array[1] = 7;
        l_uint8Array[2] = 8;
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8_ARRAY, NULL, l_uint8Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8_ARRAY. Error from GET (2)");
            break;
        }

        // Check values
        for (uint32_t i = 0; i < 3; i++)
        {
            if (l_uint8Array[i] != i)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT8_ARRAY. GET "
                        "returned %d in index %d", l_uint8Array[i], i);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT32_ARRAY ([2][3][4], DefaultVal 8)
        //----------------------------------------------------------------------
        uint32_t l_uint32Array[2][3][4];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32_ARRAY, NULL, l_uint32Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32_ARRAY. Error from GET");
            break;
        }

        // Check values
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    if (l_uint32Array[i][j][k] != 8)
                    {
                        l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                        FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32_ARRAY. "
                                "GET returned %d in index %d:%d:%d",
                                l_uint32Array[i][j][j], i, j, k);
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
        uint32_t l_val = 0;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    l_uint32Array[i][j][k] = l_val++;
                }
            }
        }

        l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32_ARRAY, NULL, l_uint32Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32_ARRAY. Error from SET");
            break;
        }

        // Test get
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    l_uint32Array[i][j][k] = 32;
                }
            }
        }

        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32_ARRAY, NULL, l_uint32Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: Error from GET uint32 array (2)");
            break;
        }

        // Check values
        l_val = 0;
        for (uint32_t i = 0; i < 2; i++)
        {
            for (uint32_t j = 0; j < 3; j++)
            {
                for (uint32_t k = 0; k < 4; k++)
                {
                    if (l_uint32Array[i][j][k] != l_val)
                    {
                        l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                        FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT32_ARRAY. "
                                 "GET returned %d in index %d:%d:%d (2)",
                                   l_uint32Array[i][j][j], i, j, k);
                        break;
                    }
                    l_val++;
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

        //----------------------------------------------------------------------
        // Test ATTR_TEST_UINT64_ARRAY ([5]. PLAT (sets vals to 4). RO)
        //----------------------------------------------------------------------
        uint64_t l_uint64Array[5];

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, NULL, l_uint64Array);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64_ARRAY. Error from GET");
            break;
        }

        // Check values
        for (uint32_t i = 0; i < 5; i++)
        {
            if (l_uint64Array[i] != 4)
            {
                l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
                FAPI_ERR("hwpTestAttributes: ATTR_TEST_UINT64_ARRAY. GET "
                         "returned %d in index %d",
                         static_cast<uint32_t>(l_uint64Array[i]), i);
                break;
            }
        }

        if (l_rc)
        {
            break;
        }

        // Cannot set read-only attribute

        //----------------------------------------------------------------------
        // Test ATTR_TEST_STRING1 (DefaultVal 'mike')
        //----------------------------------------------------------------------
        char * l_pString1 = NULL;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING1, NULL, l_pString1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. Error from GET");
            break;
        }

        // Check value
        if (l_pString1 == NULL)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. GET returned NULL");
            break;
        }

        if (strcmp(l_pString1, "mike") != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. GET returned %s",
                     l_pString1);
            break;
        }

        delete [] l_pString1;

        // Test set
        l_pString1 = "test1";

        l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING1, NULL, l_pString1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. Error from SET");
            break;
        }

        l_pString1 = NULL;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING1, NULL, l_pString1);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. Error from GET (2)");
            break;
        }

        // Check value
        if (l_pString1 == NULL)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. GET returned NULL (2)");
            break;
        }

        if (strcmp(l_pString1, "test1") != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING1. GET returned %s (2)",
                     l_pString1);
            break;
        }

        delete [] l_pString1;

        //----------------------------------------------------------------------
        // Test ATTR_TEST_STRING2 (PLAT (sets val to 'platString'))
        //----------------------------------------------------------------------
        char * l_pString2 = NULL;

        // Test get
        l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING2, NULL, l_pString2);
        if (l_rc)
        {
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING2. Error from GET");
            break;
        }

        // Check value
        if (l_pString2 == NULL)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING2. GET returned NULL");
            break;
        }

        if (strcmp(l_pString2, "platString") != 0)
        {
            l_rc = fapi::FAPI_RC_ATTR_UNIT_TEST_FAIL;
            FAPI_ERR("hwpTestAttributes: ATTR_TEST_STRING2. GET returned %s",
                     l_pString2);
            break;
        }


        // All of the following should not compile due to setting read-only
        // attributes
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32, NULL, l_uint32);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64_ARRAY, NULL, l_uint64Array);

        // All of the following should not compile due to wrong types used
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING1, NULL, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING2, NULL, l_uint32);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING1, NULL, l_uint64);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_STRING2, NULL, l_uint8Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8, NULL, l_pString1);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32, NULL, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, NULL, l_uint8Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64, NULL, l_uint64Array);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT8_ARRAY, NULL, l_pString1);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT32_ARRAY, NULL, l_uint8);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, NULL, l_uint64);
        //l_rc = FAPI_ATTR_GET(ATTR_TEST_UINT64_ARRAY, NULL, &l_uint32Array[0][0][0]);

        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING1, NULL, l_uint8);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING2, NULL, l_uint32);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING1, NULL, l_uint64);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_STRING2, NULL, l_uint64Array);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8, NULL, l_pString1);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32, NULL, l_uint64);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, NULL, &l_uint32Array[0][0][0]);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64, NULL, l_uint64Array);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT8_ARRAY, NULL, l_pString2);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT32_ARRAY, NULL, l_uint8);
        //l_rc = FAPI_ATTR_SET(ATTR_TEST_UINT64_ARRAY, NULL, l_uint64);

    } while (0);

    return l_rc;
}

} // extern "C"
