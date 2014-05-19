/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/fapiAttrTest.C $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
/**
 *  @file fapiAttrTest.C
 *
 *  @brief Implements FAPI Attribute unit test functions.
 *
 *  This is provided by FAPI and can be pulled into any unit test framework.
 *  Each unit test returns 0 for success, else error value.
 */

/*
 * Change Log ******************************************************************
 * Flag     Defect/Feature  User        Date        Description
 * ------   --------------  ----------  ----------- ----------------------------
 *                          mjjones     02/15/2013  Created. Ported from HWP.
 */

#include <fapi.H>

namespace fapi
{

//******************************************************************************
// attrTest1. Test ATTR_SCRATCH_UINT8_1
//******************************************************************************
uint32_t attrTest1()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

        uint8_t l_uint8 = 0x87;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest1: ATTR_SCRATCH_UINT8_1. Error from SET (1)");
            l_result = 1;
            break;
        }

        // Test get
        l_uint8 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest1: ATTR_SCRATCH_UINT8_1. Error from GET (2)");
            l_result = 2;
            break;
        }

        // Check value
        if (l_uint8 != 0x87)
        {
            FAPI_ERR("attrTest1: ATTR_SCRATCH_UINT8_1. GET returned %d (3)",
                     l_uint8);
            l_result = 3;
            break;
        }

        // Set to zero
        l_uint8 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_1, NULL, l_uint8);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest1: ATTR_SCRATCH_UINT8_1. Error from SET (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest1: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest2. Test ATTR_SCRATCH_UINT32_1
//******************************************************************************
uint32_t attrTest2()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

        uint32_t l_uint32 = 0x80000001;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest2: ATTR_SCRATCH_UINT32_1. Error from SET (1)");
            l_result = 1;
            break;
        }

        // Test get
        l_uint32 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest2: ATTR_SCRATCH_UINT32_1. Error from GET (2)");
            l_result = 2;
            break;
        }

        // Check value
        if (l_uint32 != 0x80000001)
        {
            FAPI_ERR("attrTest2: ATTR_SCRATCH_UINT32_1. GET returned %d (3)",
                     l_uint32);
            l_result = 3;
            break;
        }

        // Set to zero
        l_uint32 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT32_1, NULL, l_uint32);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest2: ATTR_SCRATCH_UINT32_1. Error from SET (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest2: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest3. Test ATTR_SCRATCH_UINT64_1
//******************************************************************************
uint32_t attrTest3()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

        uint64_t l_uint64 = 3;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest3: ATTR_SCRATCH_UINT64_1. Error from SET (1)");
            l_result = 1;
            break;
        }

        // Test get
        l_uint64 = 8;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest3: ATTR_SCRATCH_UINT64_1. Error from GET (2)");
            l_result = 2;
            break;
        }

        // Check value
        if (l_uint64 != 3)
        {
            FAPI_ERR("attrTest3: ATTR_SCRATCH_UINT64_1. GET returned %d (3)",
                     static_cast<uint32_t>(l_uint64));
            l_result = 3;
            break;
        }

        // Set to zero
        l_uint64 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_1, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest3: ATTR_SCRATCH_UINT64_1. Error from SET (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest3: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest4. Test ATTR_SCRATCH_UINT8_ARRAY_1
//******************************************************************************
uint32_t attrTest4()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

        uint8_t l_uint8array1[32];

        // Test set
        for (uint32_t i = 0; i < 32; i++)
        {
            l_uint8array1[i] = i + 1;
        }

        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT8_ARRAY_1, NULL, l_uint8array1);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest4: ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET (1)");
            l_result = 1;
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest4: ATTR_SCRATCH_UINT8_ARRAY_1. Error from GET (2)");
            l_result = 2;
            break;
        }

        // Check value
        for (uint32_t i = 0; i < 32; i++)
        {
            if (l_uint8array1[i] != (i + 1))
            {
                FAPI_ERR("attrTest4: ATTR_SCRATCH_UINT8_ARRAY_1. GET [%d] returned %d (3)",
                          i, l_uint8array1[i]);
                l_result = 3;
                break;
            }
        }

        if (l_result)
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest4: ATTR_SCRATCH_UINT8_ARRAY_1. Error from SET (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest4: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest5. Test ATTR_SCRATCH_UINT32_ARRAY_2
//******************************************************************************
uint32_t attrTest5()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest5: ATTR_SCRATCH_UINT32_ARRAY_2. Error from SET (1)");
            l_result = 1;
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest5: ATTR_SCRATCH_UINT32_ARRAY_2. Error from GET (2)");
            l_result = 2;
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
                    FAPI_ERR("attrTest5: ATTR_SCRATCH_UINT32_ARRAY_2. GET [%d:%d] returned %d (3)",
                             i, j, l_uint32array2[i][j]);
                    l_result = 3;
                    break;
                }
            }
            if (l_result)
            {
                break;
            }
        }

        if (l_result)
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest5: ATTR_SCRATCH_UINT32_ARRAY_2. Error from SET (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest5: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest6. Test ATTR_SCRATCH_UINT64_ARRAY_2
//******************************************************************************
uint32_t attrTest6()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest6: ATTR_SCRATCH_UINT64_ARRAY_2. Error from SET (1)");
            l_result = 1;
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest6: ATTR_SCRATCH_UINT64_ARRAY_2. Error from GET (2)");
            l_result = 2;
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
                    FAPI_ERR("attrTest6: ATTR_SCRATCH_UINT64_ARRAY_2. GET [%d:%d] returned %d (3)",
                             i, j, static_cast<uint32_t>(l_uint64array2[i][j]));
                    l_result = 3;
                    break;
                }
            }
            if (l_result)
            {
                break;
            }
        }

        if (l_result)
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
            fapiLogError(l_rc);
            FAPI_ERR("attrTest6: ATTR_SCRATCH_UINT64_ARRAY_2. Error from SET (4)");
            l_result = 4;
            break;
        }
    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest6: unit test success");
    }
    return l_result;
}

//******************************************************************************
// attrTest7. Test setting and getting an enum value from a scratch attribute
//******************************************************************************
uint32_t attrTest7()
{
    uint32_t l_result = 0;

    do
    {
        fapi::ReturnCode l_rc;

        uint64_t l_uint64 = fapi::ENUM_ATTR_SCRATCH_UINT64_2_VAL_C;

        // Test set
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest7: ATTR_SCRATCH_UINT64_2. Error from SET (enum) (1)");
            l_result = 1;
            break;
        }

        // Test get
        l_uint64 = 0;
        l_rc = FAPI_ATTR_GET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest7: ATTR_SCRATCH_UINT64_2. Error from GET (enum) (2)");
            l_result = 2;
            break;
        }

        // Check value
        if (l_uint64 != fapi::ENUM_ATTR_SCRATCH_UINT64_2_VAL_C)
        {
            FAPI_ERR("attrTest7: ATTR_SCRATCH_UINT64_2. GET returned %d (enum) (3)",
                     static_cast<uint32_t>(l_uint64));
            l_result = 3;
            break;
        }

        // Set to zero
        l_uint64 = 0;
        l_rc = FAPI_ATTR_SET(ATTR_SCRATCH_UINT64_2, NULL, l_uint64);
        if (l_rc)
        {
            fapiLogError(l_rc);
            FAPI_ERR("attrTest7: ATTR_SCRATCH_UINT64_2. Error from SET (enum2) (4)");
            l_result = 4;
            break;
        }

    } while (0);

    if (!l_result)
    {
        FAPI_INF("attrTest7: unit test success");
    }
    return l_result;
}

}
