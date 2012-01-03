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
 *                          camvanng    10/26/2011  Update scratch test
 *                          mjjones     10/28/2011  Fix error generation
 *                          camvanng    11/09/2011  Update attr enum test
 *                          mjjones     11/17/2011  Removed some initfile attr tests
 *                          mjjones     11/22/2011  Demonstrate use of heap based array
 */

#include <fapiTestHwpAttr.H>
#include <targeting/targetservice.H>
#include <targeting/predicates/predicatectm.H>
#include <targeting/iterators/rangefilter.H>

extern "C"
{

//******************************************************************************
// hwpTestAttributes function
//******************************************************************************
fapi::ReturnCode hwpTestAttributes()
{
    FAPI_INF("hwpTestAttributes: Start HWP");
    fapi::ReturnCode l_rc;

    do
    {
        //----------------------------------------------------------------------
        // Test ATTR_MSS_DIMM_MFG_ID_CODE
        //----------------------------------------------------------------------
        {
            uint32_t l_data[2][2];

            TARGETING::PredicateCTM l_pred(TARGETING::CLASS_UNIT, TARGETING::TYPE_MBA);
            TARGETING::TargetRangeFilter l_filter(TARGETING::targetService().begin(),
                                                  TARGETING::targetService().end(),
                                                  &l_pred);

            // Just look at the first MBA chiplet
            if (l_filter)
            {
                fapi::Target l_target(fapi::TARGET_TYPE_MBA_CHIPLET, *l_filter); 

                l_rc = FAPI_ATTR_GET(ATTR_MSS_DIMM_MFG_ID_CODE, &l_target, l_data);

                if (l_rc)
                {
                    FAPI_ERR("hwpTestAttributes: ATTR_MSS_DIMM_MFG_ID_CODE. Error from GET");
                    break;
                }
            }
            else
            {
                FAPI_ERR("hwpTestAttributes: ATTR_MSS_DIMM_MFG_ID_CODE. No MBAs found");
                FAPI_SET_HWP_ERROR(l_rc, RC_HWP_ATTR_UNIT_TEST_FAIL);
                break;
            }
        }

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
            break;
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

    } while (0);

    FAPI_INF("hwpTestAttributes: End HWP");
    return l_rc;
}

} // extern "C"
