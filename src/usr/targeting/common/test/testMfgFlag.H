/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/targeting/common/test/testMfgFlag.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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
#ifndef __TARGETING_COMMON_MFG_FLAG_UNIT_TEST_H
#define __TARGETING_COMMON_MFG_FLAG_UNIT_TEST_H

/**
 * @file targeting/common/test/testMfgFlag.H
 *
 * @brief Test the API for setting/getting and determining if a manufacturing
 *        flag is set.
 */

// This code relies heavily on std::array which is supported by c++11 and beyond
#if __cplusplus >= 201103L

//******************************************************************************
// Includes
//******************************************************************************

// This component
#include <targeting/common/mfgFlagAccessors.H>
#include <targeting/targplatutil.H>

using namespace TARGETING;

class MfgFlagTestingTestSuite: public CxxTest::TestSuite
{
  public:
    MfgFlagTestingTestSuite()
    : iv_allMfgFlags{0}
    {
        /// Get the System target MFG FLAGS
        // Get a handle to the System target
        TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

        // Save the manufacturing flags from the System target
        iv_allMfgFlags = l_systemTarget->getAttrAsStdArr<ATTR_MFG_FLAGS>();
    }

    ~MfgFlagTestingTestSuite()
    {
        /// Reset the System target MFG FLAGS
        // Get a handle to the System target
        TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

        // Set the manufacturing flags back to the System target
        l_systemTarget->setAttrFromStdArr<ATTR_MFG_FLAGS>(iv_allMfgFlags);
    }

    /**
     * @brief Test the MFG FLAG constants
     *
     * @details Confirm that the constants still contain the values that MFG
     *          FLAG was originally designed for.  If any of the test fails,
     *          it could signify a design change or a careless mistake,
     *          either way, better to catch this issue in a test and address
     *          it early rather than in production.
     */
    static_assert(MFG_FLAG_CELL_0_MASK == 0x00000000, "ERROR, BAD VALUE: "
            "MFG FLAG Cell 0 mask, expected to be 0x00000000, but it is not.");

    static_assert(MFG_FLAG_CELL_1_MASK == 0x00020000, "ERROR, BAD VALUE: "
            "MFG FLAG Cell 1 mask, expected to be 0x00020000, but it is not.");

    static_assert(MFG_FLAG_CELL_2_MASK == 0x00040000, "ERROR, BAD VALUE: "
            "MFG FLAG Cell 2 mask, expected to be 0x00040000, but it is not.");

    static_assert(MFG_FLAG_CELL_3_MASK == 0x00080000, "ERROR, BAD VALUE: "
            "MFG FLAG Cell 3 mask, expected to be 0x00080000, but it is not.");


    static_assert(MFG_FLAG_CELL_0_INDEX == 0, "ERROR, BAD VALUE: "
                  "MFG FLAG Cell 0 index, expected  0, but it is not.");

    static_assert(MFG_FLAG_CELL_1_INDEX == 1, "ERROR, BAD VALUE: "
                  "MFG FLAG Cell 1 index, expected  1, but it is not.");

    static_assert(MFG_FLAG_CELL_2_INDEX == 2, "ERROR, BAD VALUE: "
                  "MFG FLAG Cell 2 index, expected  2, but it is not.");

    static_assert(MFG_FLAG_CELL_3_INDEX == 3, "ERROR, BAD VALUE: "
                  "MFG FLAG Cell 3 index, expected  3, but it is not.");


    static_assert(MFG_FLAG_SIZE_OF_CELL_IN_BITS == 32, "ERROR, BAD VALUE: "
           "MFG FLAG number or bits/per cell, expected 32, but it is not.");

    static_assert(MFG_FLAG_NUM_CELLS == 4, "ERROR, BAD VALUE: "
                  "MFG FLAG number or cells, expected 4, but it is not.");

    static_assert(MFG_FLAG_SIZE_OF_A_CELL_IN_BYTES == 4, "ERROR, BAD VALUE: "
             "MFG FLAG size of bytes/per cell, expected 4, but it is not.");

    static_assert(MFG_FLAG_SIZE_OF_ALL_CELLS_IN_BYTES == 16,
                 "ERROR, BAD VALUE: "
                 "MFG FLAG size of ALL bytes, expected 16, but it is not.");


    static_assert(MFG_FLAG_CELL_0_MAX_VAL == 31, "ERROR, BAD VALUE: "
              "MFG FLAG cell 0 maximum value, expected 31, but it is not.");

    static_assert(MFG_FLAG_CELL_1_MAX_VAL == 63, "ERROR, BAD VALUE: "
              "MFG FLAG cell 0 maximum value, expected 63, but it is not.");

    static_assert(MFG_FLAG_CELL_2_MAX_VAL == 95, "ERROR, BAD VALUE: "
              "MFG FLAG cell 0 maximum value, expected 95, but it is not.");

    static_assert(MFG_FLAG_CELL_3_MAX_VAL == 127, "ERROR, BAD VALUE: "
             "MFG FLAG cell 0 maximum value, expected 127, but it is not.");


    /**
     * @brief Test method: void getAllMfgFlags(
     *                               ATTR_MFG_FLAGS_typeStdArr &o_allMfgFlags);
     *
     * @details This method will test getting the manufacturing flags
     *          is working correctly.
     */
    void testGetAllMfgFlags()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "testGetAllMfgFlags" );
        {
            /// Get MFG FLAGS the old fashion way
            // Get a handle to the System target
            TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

            // Get the manufacturing flags from the System target
            auto l_value = l_systemTarget->getAttrAsStdArr<ATTR_MFG_FLAGS>();

            /// Get MFG FLAGS our way
            // Create local storage to hold all of the manufacturing flags
            ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = {1};
            // Method to test: Get the manufacturing flags
            getAllMfgFlags(l_allMfgFlags);

            // Verify all cells
            validateAllMfgFlags(l_allMfgFlags, l_value);
        }
        TRACFCOMP(g_trac_targeting, EXIT_MRK "testGetAllMfgFlags" );
    }

    /**
     * @brief Test method: void setAllMfgFlags(
     *                      const ATTR_MFG_FLAGS_typeStdArr &i_allMfgFlags);
     *
     * @details This method will test the setting of all of the manufacturing
     *          flags. Each cell is tested individually.
     */
    void testSetAllMfgFlags()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "testSetAllMfgFlags" );

        // Zero out the manufacturing flags before testing
        zeroOutMfgFlags();

        // Create local storage to hold all of the manufacturing flags
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlagsUpdated = {0};
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlagsReceived = {0};

        // Test setting cell 0
        {
            /// Get and set cell 0 to a known value
            // Use our method, that was previously tested and vetted
            getAllMfgFlags(l_allMfgFlagsUpdated);
            l_allMfgFlagsUpdated[MFG_FLAG_CELL_0_INDEX] = 0x04000000;
            // Method to test: Set all of the manufacturing flags
            setAllMfgFlags(l_allMfgFlagsUpdated);

            /// Validate cell 0 with known value
            // Get the manufacturing flags
            getAllMfgFlags(l_allMfgFlagsReceived);

            // Verify all cells
            validateAllMfgFlags(l_allMfgFlagsUpdated, l_allMfgFlagsReceived);

            // Explicitly verify cell 0
            if (l_allMfgFlagsReceived[MFG_FLAG_CELL_0_INDEX] != 0x04000000)
            {
                TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                         "but expected 0x04000000",
                         MFG_FLAG_CELL_0_INDEX,
                         l_allMfgFlagsReceived[MFG_FLAG_CELL_0_INDEX] );
            }
        }

        // Test setting cell 1
        {
            /// Get and set cell 1 to a known value
            // Use our method, that was previously tested and vetted
            getAllMfgFlags(l_allMfgFlagsUpdated);
            l_allMfgFlagsUpdated[MFG_FLAG_CELL_1_INDEX] = 0x00020000;
            // Method to test: Set all of the manufacturing flags
            setAllMfgFlags(l_allMfgFlagsUpdated);

            /// Validate cell 1 with known value
            // Get the manufacturing flags
            getAllMfgFlags(l_allMfgFlagsReceived);

            // Verify all cells
            validateAllMfgFlags(l_allMfgFlagsUpdated, l_allMfgFlagsReceived);

            // Explicitly verify cell 1
            if (l_allMfgFlagsReceived[MFG_FLAG_CELL_1_INDEX] != 0x00020000)
            {
                TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                         "but expected 0x00020000",
                         MFG_FLAG_CELL_1_INDEX,
                         l_allMfgFlagsReceived[MFG_FLAG_CELL_1_INDEX] );
            }
        }

        // Test setting cell 2
        {
            /// Get and set cell 2 to a known value
            // Use our method, that was previously tested and vetted
            getAllMfgFlags(l_allMfgFlagsUpdated);
            l_allMfgFlagsUpdated[MFG_FLAG_CELL_2_INDEX] = 0x00000100;
            // Method to test: Set all of the manufacturing flags
            setAllMfgFlags(l_allMfgFlagsUpdated);

            /// Validate cell 2 with known value
            // Get the manufacturing flags
            getAllMfgFlags(l_allMfgFlagsReceived);

            // Verify all cells
            validateAllMfgFlags(l_allMfgFlagsUpdated, l_allMfgFlagsReceived);

            // Explicitly verify cell 2
            if (l_allMfgFlagsReceived[MFG_FLAG_CELL_2_INDEX] != 0x00000100)
            {
                TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                         "but expected 0x00000100",
                         MFG_FLAG_CELL_2_INDEX,
                         l_allMfgFlagsReceived[MFG_FLAG_CELL_2_INDEX] );
            }
        }

        // Test setting cell 3
        {
            /// Get and set cell 3 to a known value
            // Use our method, that was previously tested and vetted
            getAllMfgFlags(l_allMfgFlagsUpdated);
            l_allMfgFlagsUpdated[MFG_FLAG_CELL_3_INDEX] = 0x00000008;
            // Method to test: Set all of the manufacturing flags
            setAllMfgFlags(l_allMfgFlagsUpdated);

            /// Validate cell 3 with known value
            // Get the manufacturing flags
            getAllMfgFlags(l_allMfgFlagsReceived);

            // Verify all cells
            validateAllMfgFlags(l_allMfgFlagsUpdated, l_allMfgFlagsReceived);

            // Explicitly verify cell 3
            if (l_allMfgFlagsReceived[MFG_FLAG_CELL_3_INDEX] != 0x00000008)
            {
                TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                         "but expected 0x00000008",
                         MFG_FLAG_CELL_3_INDEX,
                         l_allMfgFlagsReceived[MFG_FLAG_CELL_3_INDEX] );
            }
        }

        TRACFCOMP(g_trac_targeting, EXIT_MRK "testSetAllMfgFlags");
    }  // testSetAllMfgFlags

    /**
     * @brief Test method:void setMfgFlag(TARGETING::MFG_FLAGS i_mfgFlag)
     *
     * @details This method will test the setting of an individual flag
     *          for the System target
     */
    void testSetMfgFlag()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "testSetMfgFlag" );

        // Zero out the manufacturing flags before testing
        zeroOutMfgFlags();

        // Create some local variables to be used through out the test
        TARGETING::MFG_FLAGS l_mfgFlag;
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        uint32_t l_cellIndex(0), l_currentValue(0), l_expectedValue(0);

        /// Test cell 0
        // Test manufacturing flag 0, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        l_cellIndex = 0;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 11, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(11);
        l_cellIndex = 0;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(31);
        l_cellIndex = 0,
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100001;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        /// Test cell 1
        // Test manufacturing flag 32, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(32);
        l_cellIndex = 1;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 47, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(47);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(63);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010001;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        /// Test cell 2
        // Test manufacturing flag 64, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(64);
        l_cellIndex = 2;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 83, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(83);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 95, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(95);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001001;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        /// Test cell 3
        // Test manufacturing flag 96, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(96);
        l_cellIndex = 3;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 119, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(119);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000100;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        // Test manufacturing flag 127, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(127);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000101;
        runTestSetMfgFlag(l_mfgFlag,      l_cellIndex,
                          l_currentValue, l_expectedValue);

        TRACFCOMP(g_trac_targeting, EXIT_MRK "testSetMfgFlag");
    } // testSetMfgFlag

    /**
     * @brief Test method: void setMfgFlag(TARGETING::MFG_FLAGS i_mfgFlag,
     *                               ATTR_MFG_FLAGS_typeStdArr &io_allMfgFlags);
     *
     * @details This method will test the setting of an individual flag
     *          for the given data.
     */
    void testSetMfgFlagForGivenData()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "testSetMfgFlagForGivenData" );

        // Create some local variables to be used through out the test
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = { 0 };
        TARGETING::MFG_FLAGS l_mfgFlag;
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        uint32_t l_cellIndex(0), l_currentValue(0), l_expectedValue(0);


        /// Test cell 0
        // Test manufacturing flag 0, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        l_cellIndex = 0;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 11, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(11);
        l_cellIndex = 0;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(31);
        l_cellIndex = 0,
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100001;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        /// Test cell 1
        // Test manufacturing flag 32, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(32);
        l_cellIndex = 1;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 47, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(47);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(63);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010001;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        /// Test cell 2
        // Test manufacturing flag 64, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(64);
        l_cellIndex = 2;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 83, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(83);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 95, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(95);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001001;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        /// Test cell 3
        // Test manufacturing flag 96, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(96);
        l_cellIndex = 3;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 119, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(119);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000100;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        // Test manufacturing flag 127, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(127);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000101;
        runTestSetMfgFlagForGivenData(l_mfgFlag, l_allMfgFlags, l_cellIndex,
                                      l_currentValue, l_expectedValue);

        TRACFCOMP(g_trac_targeting, EXIT_MRK "testSetMfgFlagForGivenData");
    } // testSetMfgFlagForGivenData


    /**
     * @brief Test methods:
     *            bool isMfgFlagSet(const TARGETING::MFG_FLAGS i_mfgFlag,
     *                      const uint32_t i_allMfgFlags[MFG_FLAG_NUM_CELLS]);
     *         and
     *            bool isMfgFlagSet(const char32_t i_mfgFlag);
     *         with raw values.
     *
     * @details This method will test the two methods that determine whether
     *          a manufacturing flag is set or not. Each cell is tested
     *          individually.  Each cell is tested at it's minimum and
     *          maximum value, plus a value in between.  Each cell is tested
     *          before and after the manufacturing flag is set.
     */
    void testIsMfgFlagSet()
    {
        TRACFCOMP(g_trac_targeting, ENTER_MRK "testIsMfgFlagSet" );

        // Zero out the manufacturing flags before testing
        zeroOutMfgFlags();

        // Create some local variables to be used through out the test
        TARGETING::MFG_FLAGS l_mfgFlag;
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        uint32_t l_cellIndex(0), l_currentValue(0), l_expectedValue(0);

        /// Test cell 0
        // Test manufacturing flag 0, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(0);
        l_cellIndex = 0;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 11, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(11);
        l_cellIndex = 0;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(31);
        l_cellIndex = 0;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80100001;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        /// Test cell 1
        // Test manufacturing flag 32, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(32);
        l_cellIndex = 1;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 47, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(47);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 31, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(63);
        l_cellIndex = 1;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80010001;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        /// Test cell 2
        // Test manufacturing flag 64, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(64);
        l_cellIndex = 2;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 83, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(83);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 95, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(95);
        l_cellIndex = 2;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80001001;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        /// Test cell 3
        // Test manufacturing flag 96, minimum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(96);
        l_cellIndex = 3;
        l_currentValue = 0x00000000;
        l_expectedValue = 0x80000000;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 119, a value between min and max
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(119);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000100;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        // Test manufacturing flag 127, maximum value for cell
        l_mfgFlag = static_cast<TARGETING::MFG_FLAGS>(127);
        l_cellIndex = 3;
        l_currentValue = l_expectedValue;
        l_expectedValue = 0x80000101;
        runTestIsMfgFlagSet(l_mfgFlag,      l_cellIndex,
                            l_currentValue, l_expectedValue);

        TRACFCOMP(g_trac_targeting, EXIT_MRK "testIsMfgFlagSet" );
    }

    // private helper methods
    private:

    /**
     * @brief Clear (zero-out) the manufacturing flags of the System target.
     *        Useful for starting a test with a clean slate.
     */
    void zeroOutMfgFlags()
    {
        // Create local storage to hold all of the manufacturing flags
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = {0};

        // Get a handle to the System target
        TargetHandle_t l_systemTarget = UTIL::assertGetToplevelTarget();

        // Update the System target with zeroed-out manufacturing flags
        l_systemTarget->setAttrFromStdArr<ATTR_MFG_FLAGS>(l_allMfgFlags);
    } // zeroOutMfgFlags

    /**
     * @brief Validate that the received manufacturing flags equal the
     *        expected received manufacturing flags.
     */
    bool validateAllMfgFlags(const ATTR_MFG_FLAGS_typeStdArr i_receivedMfgFlags,
                             const ATTR_MFG_FLAGS_typeStdArr i_expectedMfgFlags)
    {
        bool retVal = true;

        if ( i_receivedMfgFlags[MFG_FLAG_CELL_0_INDEX] !=
             i_expectedMfgFlags[MFG_FLAG_CELL_0_INDEX] )
        {
            TS_FAIL("ERROR: Received value for cell[0] (0x%.8X) does not "
                    "equal expected value for cell[0] (0x%.8X)",
                    i_receivedMfgFlags[MFG_FLAG_CELL_0_INDEX],
                    i_expectedMfgFlags[MFG_FLAG_CELL_0_INDEX] );
            retVal = false;
        }

        if ( i_receivedMfgFlags[MFG_FLAG_CELL_1_INDEX] !=
             i_expectedMfgFlags[MFG_FLAG_CELL_1_INDEX] )
        {
            TS_FAIL("ERROR: Received value for cell[1] (0x%.8X) does not "
                    "equal expected value for cell[1] (0x%.8X)",
                    i_receivedMfgFlags[MFG_FLAG_CELL_1_INDEX],
                    i_expectedMfgFlags[MFG_FLAG_CELL_1_INDEX] );
            retVal = false;
        }

        if ( i_receivedMfgFlags[MFG_FLAG_CELL_2_INDEX] !=
             i_expectedMfgFlags[MFG_FLAG_CELL_2_INDEX] )
        {
            TS_FAIL("ERROR: Received value for cell[2] (0x%.8X) does not "
                    "equal expected value for cell[2] (0x%.8X)",
                    i_receivedMfgFlags[MFG_FLAG_CELL_2_INDEX],
                    i_expectedMfgFlags[MFG_FLAG_CELL_2_INDEX] );
            retVal = false;
        }

        if ( i_receivedMfgFlags[MFG_FLAG_CELL_3_INDEX] !=
             i_expectedMfgFlags[MFG_FLAG_CELL_3_INDEX] )
        {
            TS_FAIL("ERROR: Received value for cell[3] (0x%.8X) does not "
                    "equal expected value for cell[3] (0x%.8X)",
                    i_receivedMfgFlags[MFG_FLAG_CELL_3_INDEX],
                    i_expectedMfgFlags[MFG_FLAG_CELL_3_INDEX] );
            retVal = false;
        }

        return retVal;
    } // validateAllMfgFlags

    /**
     * @brief Run the test for method testSetMfgFlag
     *
     * @see method testSetMfgFlag
     *
     * @param[in] i_mfgFlag       - the manufacturing flag to set and test with
     * @param[in] i_cellIndex     - the cell's index that the manufacturing
     *                              flag is associated with
     * @param[in] i_currentValue  - the current value of the cell, before
     *                              setting the manufacturing flag
     * @param[in] i_expectedValue - the expected value of the cell, after
     *                              setting the manufacturing flag
     */
    void runTestSetMfgFlag(const TARGETING::MFG_FLAGS i_mfgFlag,
                           const uint32_t i_cellIndex,
                           const uint32_t i_currentValue,
                           const uint32_t i_expectedValue)
    {
        // Create local storage to hold all of the manufacturing flags
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = {0};

        /// Test BEFORE setting manufacturing flag
        // Get the manufacturing flags with flag NOT set
        getAllMfgFlags(l_allMfgFlags);

        if (l_allMfgFlags[i_cellIndex] != i_currentValue)
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) BEFORE setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_currentValue,
                     i_mfgFlag );
        }

        /// Test AFTER setting manufacturing flag
        // Method to test: Setting a manufacturing flag
        setMfgFlag(i_mfgFlag);

        // Get the manufacturing flags with flag set
        getAllMfgFlags(l_allMfgFlags);

        if (l_allMfgFlags[i_cellIndex] != i_expectedValue)
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) AFTER setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_expectedValue,
                     i_mfgFlag );
        }
    }

    /**
     * @brief Run the test for method testSetMfgFlag
     *
     * @see method testSetMfgFlagForGivenData
     *
     * @param[in] i_mfgFlag       - the manufacturing flag to set and test with
     * @param[in] i_cellIndex     - the cell's index that the manufacturing
     *                              flag is associated with
     * @param[in] i_currentValue  - the current value of the cell, before
     *                              setting the manufacturing flag
     * @param[in] i_expectedValue - the expected value of the cell, after
     *                              setting the manufacturing flag
     */
    void runTestSetMfgFlagForGivenData
                          (const TARGETING::MFG_FLAGS i_mfgFlag,
                                 ATTR_MFG_FLAGS_typeStdArr &io_allMfgFlags,
                           const uint32_t i_cellIndex,
                           const uint32_t i_currentValue,
                           const uint32_t i_expectedValue)
    {
        if (io_allMfgFlags[i_cellIndex] != i_currentValue)
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) BEFORE setting flag (%d)",
                     i_cellIndex,
                     io_allMfgFlags[i_cellIndex],
                     i_currentValue,
                     i_mfgFlag );
        }

        /// Test AFTER setting manufacturing flag
        // Method to test: Setting a manufacturing flag on the given data
        setMfgFlag(i_mfgFlag, io_allMfgFlags);


        if (io_allMfgFlags[i_cellIndex] != i_expectedValue)
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) AFTER setting flag (%d)",
                     i_cellIndex,
                     io_allMfgFlags[i_cellIndex],
                     i_expectedValue,
                     i_mfgFlag );
        }
    }

    /**
     * @brief Run the test for method testIsMfgFlagSet
     *
     * @see method testIsMfgFlagSet
     *
     * @param[in] i_mfgFlag       - the manufacturing flag to set and test with
     * @param[in] i_cellIndex     - the cell's index that the manufacturing
     *                              flag is associated with
     * @param[in] i_currentValue  - the current value of the cell, before
     *                              setting the manufacturing flag
     * @param[in] i_expectedValue - the expected value of the cell, after
     *                              setting the manufacturing flag
     */
    void runTestIsMfgFlagSet(const TARGETING::MFG_FLAGS i_mfgFlag,
                             const uint32_t i_cellIndex,
                             const uint32_t i_currentValue,
                             const uint32_t i_expectedValue)
    {
        // Create local storage to hold all of the manufacturing flags
        ATTR_MFG_FLAGS_typeStdArr l_allMfgFlags = {0};

        /// Test BEFORE setting manufacturing flag
        // Get the manufacturing flags with flag NOT set
        getAllMfgFlags(l_allMfgFlags);

        // Method to test: Is manufacturing flag set, passing in the set
        //                 of all manufacturing flags
        if (isMfgFlagSet(i_mfgFlag, l_allMfgFlags))
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) BEFORE setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_currentValue,
                     i_mfgFlag );
        }

        // Method to test: Is manufacturing flag set against the Sytem
        //                 Targets's manufacturing flags
        if (isMfgFlagSet(i_mfgFlag))
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) BEFORE setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_currentValue,
                     i_mfgFlag );
        }

        /// Test AFTER setting manufacturing flag
        // Set the manufacturing flag
        setMfgFlag(i_mfgFlag);

        // Get the manufacturing flags with flag set
        getAllMfgFlags(l_allMfgFlags);

        // Method to test: Is manufacturing flag set, passing in the set
        //                 of all manufacturing flags
        if (!isMfgFlagSet(i_mfgFlag, l_allMfgFlags))
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) AFTER setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_expectedValue,
                     i_mfgFlag );
        }

        // Method to test: Is manufacturing flag set against the System
        //                 Targets's manufacturing flags
        if (!isMfgFlagSet(i_mfgFlag))
        {
            TS_FAIL( "ERROR: Received value for cell[%d] (0x%.8X) "
                     "but expected (0x%.8X) AFTER setting flag (%d)",
                     i_cellIndex,
                     l_allMfgFlags[i_cellIndex],
                     i_expectedValue,
                     i_mfgFlag );
        }
    } // runTestIsMfgFlagSet


    // private attributes
    private:

    // Create local storage to hold all of the manufacturing flags'
    // of the System target, to reset once testing is done.
    ATTR_MFG_FLAGS_typeStdArr iv_allMfgFlags;
};  // class MfgFlagTestingTestSuite

#endif // __cplusplus >= 201103L

#endif // __TARGETING_COMMON_MFG_FLAG_UNIT_TEST_H
