/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2DdimmGetEfdTest.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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


#include <cxxtest/TestSuite.H>
#include <fapi2DdimmGetEfdTest.H>

//******************************************************************************
//                               Useful Constants
//
// Set up some constants to facilitate the testing
//
//******************************************************************************

// Set a default size for the SPD buffer
const size_t DEFAULT_SPD_BUFFER_SIZE_DEFAULT = (5 * KILOBYTE);

// SPD DDIMM consts
const size_t  SPD_DDIMM_TYPE_OFFSET = 2;
const uint8_t DEFAULT_SPD_DDIMM_TYPE = 0x0C;
const size_t  DEFAULT_SPD_DDIMM_SIZE = 512;

// EFD data block consts
const size_t   DEFAULT_EFD_BLOCK_SIZE_MULTIPLIER = 4;  // 4 thirty two bytes
const size_t   DEFAULT_EFD_BLOCK_SIZE =
              (DEFAULT_EFD_BLOCK_SIZE_MULTIPLIER * 32);// 4 * 32 bytes = 128
const size_t   EFD_MEMORY_SPACE_OFFSET = 277;
const size_t   DEFAULT_EFD_MEMORY_SPACE_LOCATION = 1024;
const size_t   EFD_MEMORY_SPACE_SIZE_OFFSET = 285;
const size_t   DEFAULT_EFD_MEMORY_SPACE_SIZE = 0x02;
const size_t   EFD_COUNT_OFFSET = 286;
const uint16_t DEFAULT_EFD_COUNT = 32;

// DMB consts
const size_t   SPD_DMB_MFG_ID_OFFSET = 198;
const uint16_t DEFAULT_SPD_DMB_MFG_ID = 0x2980;
const size_t   SPD_DMB_REVISION_OFFSET = 200;
const uint8_t  DEFAULT_SPD_DMB_REVISION = 0x00;

/// EFD consts
const size_t  EFD_META_DATA_OFFSET = 288;
// EFD's extended function type consts
const size_t  EXTENDED_FUNCTION_TYPE_MASK = 0x0F;
const size_t  EXTENDED_FUNCTION_TYPE_INVERSE_MASK = 0xF0;
const uint8_t DEFAULT_EXTENDED_FUNCTION_TYPE = 0x03;
// EFD's is implemented consts
const size_t IS_IMPLEMENTED_MASK = 0x80;
const size_t IS_IMPLEMENTED_INVERSE_MASK = 0x7F;

// Frequency valid values and what they map to in the code
// 12800(0x0001), 14930(0x0002), 17060(0x0004), 19200(0x0008),
// 21330(0x0010), 23460(0x0020), 25600(0x0040)
const uint16_t DEFAULT_FREQUENCY = 25600;

// Master Rank valid values and what they map to in the code
// MR0(0x01), MR1(0x02), MR3(0x04), MR4(0x08),
const uint8_t  DEFAULT_MASTER_RANK = 0; // MR0


//******************************************************************************
//                                 Public API
//******************************************************************************

//******************************************************************************
// fapi2DdimmGetEfdTest ctor
//******************************************************************************
fapi2DdimmGetEfdTest::fapi2DdimmGetEfdTest()
    : iv_efdBufferPtr(nullptr),
      iv_spdBufferPtr(nullptr),
      iv_spdBufferSize(DEFAULT_SPD_BUFFER_SIZE_DEFAULT),
      iv_efdMetaDataPtr(nullptr),
      iv_efdBlockDataPtr(nullptr),
      iv_efdBlockSizeMultiplier(DEFAULT_EFD_BLOCK_SIZE_MULTIPLIER),
      iv_efdBlockSize(DEFAULT_EFD_BLOCK_SIZE),
      iv_efdMemorySpaceLocation(DEFAULT_EFD_MEMORY_SPACE_LOCATION),
      iv_efdMemorySpaceSize(DEFAULT_EFD_MEMORY_SPACE_SIZE),
      iv_efdCount(DEFAULT_EFD_COUNT),
      iv_spdDmbMfgId(DEFAULT_SPD_DMB_MFG_ID),
      iv_spdDmbRevision(DEFAULT_SPD_DMB_REVISION),
      iv_extendedFunctionType(DEFAULT_EXTENDED_FUNCTION_TYPE),
      iv_frequency(DEFAULT_FREQUENCY),
      iv_rank(DEFAULT_MASTER_RANK),
      iv_ocmbChipTarget(nullptr),
      iv_rc(fapi2::FAPI2_RC_SUCCESS),
      iv_vpdInfo(fapi2::EFD),
      iv_numTests(0),
      iv_numFails(0),
      iv_attrModel(TARGETING::MODEL_NA)
{
    FAPI_INF(">> fapi2DdimmGetEfdTest");

    // Find a valid target of type OCMB_CHIP
    TARGETING::TargetHandleList l_ocmbTargetList;
    TARGETING::getAllChips(l_ocmbTargetList, TARGETING::TYPE_OCMB_CHIP, true);
    if (!l_ocmbTargetList.size())
    {
        TS_FAIL("<< fapi2DdimmGetEfdTest: Not enough OCMB_CHIPs found. "
                "Can not execute tests.");
        return;
    }
    else
    {
        iv_ocmbChipTarget = l_ocmbTargetList[0];
    }

    // Initialize the SPD buffer to a known good state
    initializeSpdBuffer();
    // Initialize the VPDInfo to a known good state and match SPD buffer
    initializeVpdInfo(iv_vpdInfo);
    // Create EFD buffer to match VPDInfo iv_size
    createEfdBuffer(iv_efdBufferPtr, iv_vpdInfo.iv_size);
};

//******************************************************************************
// testDdimmGetEfdHwpCall
//******************************************************************************
void fapi2DdimmGetEfdTest::testDdimmGetEfdHwpCall()
{
    // If initialization process was unable to find an OCMB chip target, then
    // exit without running any tests.
    if (!iv_ocmbChipTarget)
    {
        return;
    }

    if (!sanityCheckTest())
    {
        TS_FAIL("<< fapi2DdimmGetEfdTest: Test configuration failed. "
                "Test is broken - needs fixing/updating.");
    }
    else
    {
        // Call the actual tests
        sizeMisMatchTest();
        dmbDataTest();
        vpdInfoInputTest();
        findMatchTest();
    }

    FAPI_INF("<< fapi2DdimmGetEfdTest: Test Complete. %d/%d fails.",
             iv_numFails, iv_numTests);
}

//******************************************************************************
//                              Private Test Cases
//******************************************************************************

//******************************************************************************
// sanityCheckTest
//******************************************************************************
bool fapi2DdimmGetEfdTest::sanityCheckTest()
{
    FAPI_INF(">> sanityCheckTest");

    bool l_sanityCheckTestPassed(true);

    // Create a TARGET_TYPE_OCMB_CHIP FAPI2 target
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                               l_fapi2Target(iv_ocmbChipTarget);


    ++iv_numTests;
    // Should get a match immediately, if not, test setup is broken
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        l_sanityCheckTestPassed = false;
        ++iv_numFails;
        TS_FAIL("sanityCheckTest: Test configuration failed: "
                "Should have found a match for frequency(%d) and master rank(%d) on %.8X",
                iv_vpdInfo.iv_omi_freq_mhz,
                iv_vpdInfo.iv_rank,
                TARGETING::get_huid(iv_ocmbChipTarget));
    }

    FAPI_INF("<< sanityCheckTest");

    return l_sanityCheckTestPassed;
}

//******************************************************************************
// sizeMisMatchTest
//******************************************************************************
void fapi2DdimmGetEfdTest::sizeMisMatchTest()
{
    FAPI_INF(">> sizeMisMatchTest");

    // Create a TARGET_TYPE_OCMB_CHIP FAPI2 target
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                               l_fapi2Target(iv_ocmbChipTarget);

    // Some handy variables
    size_t  l_bufferSize(0);
    // This type is an invalid type, it is used for negative tetsting
    uint8_t l_ddrType(0xAA);


    ++iv_numTests;
    /// Test when buffer size is 0
    // Set the buffer size to 0
    l_bufferSize = 0;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, l_bufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed. Buffer size is %d",
                l_bufferSize);
    }


    ++iv_numTests;
    /// Test when buffer size is < the needed DDR size,
    /// but DDR type is the correct type
    // Set the buffer size to 1 less than size of the DDR type's size
    l_bufferSize = DEFAULT_SPD_DDIMM_SIZE - 1;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, l_bufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed. Buffer (%d) size is "
                "less than the DDR size (%d)",
                l_bufferSize, DEFAULT_SPD_DDIMM_SIZE);
    }


    ++iv_numTests;
    /// Test when buffer size is large enough, but DDR type is incorrect
    // Set the DDR type to an incorrect type
    l_ddrType = 0xAA;
    setSpdDdimmType(l_ddrType);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed. "
                "Should have failed with DDR type set at 0xAA");
    }
    // Restore the DDR type
    setSpdDdimmType(DEFAULT_SPD_DDIMM_TYPE);


    ++iv_numTests;
    /// Test when buffer is a nullptr
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, nullptr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "Passing a nullptr EFD buffer is a valid value.");
    }
    else if (iv_vpdInfo.iv_size != DEFAULT_EFD_BLOCK_SIZE)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "Returned EFD buffer size is not what is expected. "
                "May just need to update test to reflect code.");
    }


    ++iv_numTests;
    /// Test when EFD memory space location resides within the DDR4 memory space
    // Set the memory space location to reside within the DDR4 memory space
    setEfdMemorySpaceLocation(DEFAULT_SPD_DDIMM_SIZE - 1);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "EFD memory space cannot reside in the DDR4 memory space.");
    }
    // Restore the memory space location
    setEfdMemorySpaceLocation(iv_efdMemorySpaceLocation);


    ++iv_numTests;
    /// Test when mapping for EFD memory size is incorrect
    // Set the memory space size mapping value to an incorrect value
    setEfdMemorySpaceSize(0x07);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "There is no EFD memory space maping for 0x07.");
    }
    // Restore the memory space size mapping value
    setEfdMemorySpaceSize(iv_efdMemorySpaceSize);


    ++iv_numTests;
    /// Test when mapping for EFD memory size + EFD memory space offset
    /// is out of bounds.
    // In this scenario, increase the EFD memory space size beyond
    // the VPD memory bounds.
    setEfdMemorySpaceSize(iv_efdMemorySpaceSize + 1);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore the EFD memory space size
    setEfdMemorySpaceSize(iv_efdMemorySpaceSize);


    ++iv_numTests;
    /// Test when mapping for EFD memory size + EFD memory space location
    /// is out of bounds
    // In this scenario, increase the EFD memory space location such that the
    // EFD memory size +EFD memory space offset is beyond the VPD memory bounds.
    setEfdMemorySpaceLocation(iv_efdMemorySpaceLocation + 1);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore the memory space location
    setEfdMemorySpaceLocation(iv_efdMemorySpaceLocation);


    ++iv_numTests;
    /// Test when the number of EFDs is 0.
    // Set EFD count to 0
    setEfdCount(0);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "Number of EFDs is 0, need at least one.");
    }
    // Restore the EFD count
    setEfdCount(iv_efdCount);


    ++iv_numTests;
    /// Test when the size of the EFD data block size is greater than the
    /// EFD buffer size
    // Increase the EFD data block size
    setAllEfdMetaDatasEfdDataBlockSize(5);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "EFD data block size is greater than EFD buffer size.");
    }
    // Restore the EFD data block size
    setAllEfdMetaDatasEfdDataBlockSize(iv_efdBlockSizeMultiplier);


    ++iv_numTests;
    // Test when the size of the EFD buffer size is less than the
    // EFD data block size
    // Shrink EFD buffer size
    iv_vpdInfo.iv_size = DEFAULT_EFD_BLOCK_SIZE - 1;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("sizeMisMatchTest: test failed: "
                "EFD buffer size is greater than EFD data block size.");
    }
    // Restore the EFD buffer size
    iv_vpdInfo.iv_size = DEFAULT_EFD_BLOCK_SIZE;

    FAPI_INF("<< sizeMisMatchTest");
}

//******************************************************************************
// dmbDataTest
//******************************************************************************
void fapi2DdimmGetEfdTest::dmbDataTest()
{
    FAPI_INF(">> dmbDataTest");

    // Create a TARGET_TYPE_OCMB_CHIP FAPI2 target
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                               l_fapi2Target(iv_ocmbChipTarget);


    ++iv_numTests;
    /// Test when DMB manufacturer ID is incorrect
    // Set the DMB manufacturer ID to an incorrect value
    // and FFDC enabled is false
    setSpdDmbMfgId(0x5540);
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("dmbDataTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore the DMB manufacturer ID
    setSpdDmbMfgId(iv_spdDmbMfgId);


    ++iv_numTests;
    /// Test when DMB revision is incorrect
    // Set the DMB revision to an incorrect value
    // and FFDC enabled is false
    setSpdDmbRevision(0x20);
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("dmbDataTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore DMB manufacturer ID
    setSpdDmbRevision(iv_spdDmbRevision);

    /// Test when DMB manufacturer ID is incorrect
    // Set the DMB manufacturer ID to an incorrect value
    // and FFDC enabled is true
    setSpdDmbMfgId(0x5540);
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("dmbDataTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore the DMB manufacturer ID
    setSpdDmbMfgId(iv_spdDmbMfgId);


    ++iv_numTests;
    /// Test when DMB revision is incorrect
    // Set the DMB revision to an incorrect value
    // and FFDC enabled is true
    setSpdDmbRevision(0x20);
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("dmbDataTest: test failed: "
                "EFD memory size + EFD memory space offset is out of bounds.");
    }
    // Restore DMB manufacturer ID
    setSpdDmbRevision(iv_spdDmbRevision);


    FAPI_INF("<< dmbDataTest");
}

//******************************************************************************
// vpdInfoInputTest
//******************************************************************************
void fapi2DdimmGetEfdTest::vpdInfoInputTest()
{
    FAPI_INF(">> vpdInfoInputTest");

    // Create a TARGET_TYPE_OCMB_CHIP FAPI2 target
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                               l_fapi2Target(iv_ocmbChipTarget);


    ++iv_numTests;
    /// Test when caller passes in an incorrect frequency value and
    /// set FFDC enabled flag to true
    // Set the frequency to an incorrect value and enable FFDC flag
    iv_vpdInfo.iv_omi_freq_mhz = iv_frequency - 1;
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("vpdInfoInputTest: test failed: "
                "VPD info frequency value (%d) is not valid.",
                iv_vpdInfo.iv_omi_freq_mhz);
    }
    // Restore frequency
    iv_vpdInfo.iv_omi_freq_mhz = iv_frequency;


    ++iv_numTests;
    /// Test when caller passes in an incorrect master rank and
    /// set FFDC enabled flag to true
    // Set the master rank to an incorrect value and enable FFDC flag
    iv_vpdInfo.iv_rank = 4;
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("vpdInfoInputTest: test failed: "
                "VPD info master rank (%d) is not valid.",
                iv_vpdInfo.iv_rank);
    }
    // Restore master rank
    iv_vpdInfo.iv_rank = iv_rank;


    ++iv_numTests;
    /// Test when caller passes in an incorrect frequency value and
    /// set FFDC enabled flag to false
    // Set the frequency to an incorrect value and disable FFDC flag
    iv_vpdInfo.iv_omi_freq_mhz = iv_frequency - 1;
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("vpdInfoInputTest: test failed: "
                "VPD info frequency value (%d) is not valid.",
                iv_vpdInfo.iv_omi_freq_mhz);
    }
    // Restore frequency and FFDC flag
    iv_vpdInfo.iv_omi_freq_mhz = iv_frequency;
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;


    ++iv_numTests;
    /// Test when caller passes in an incorrect master rank and
    /// set FFDC enabled flag to false
    // Set the master rank to an incorrect value and enable FFDC flag
    iv_vpdInfo.iv_rank = 4;
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("vpdInfoInputTest: test failed: "
                "VPD info master rank (%d) is not valid.",
                iv_vpdInfo.iv_rank);
    }
    // Restore master rank and FFDC flag
    iv_vpdInfo.iv_rank = iv_rank;
    iv_vpdInfo.iv_is_config_ffdc_enabled = true;

    FAPI_INF("<< vpdInfoInputTest");
}

//******************************************************************************
// findMatchTest
//******************************************************************************
void fapi2DdimmGetEfdTest::findMatchTest()
{
    FAPI_INF(">> findMatchTest");

    // Create a TARGET_TYPE_OCMB_CHIP FAPI2 target
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                                               l_fapi2Target(iv_ocmbChipTarget);


    ++iv_numTests;
    // Match EFD data block[0]
    configureEfdDataBlockN(0, iv_frequency, iv_rank, 0xAA, 0xDD);
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) "
                "are valid.  Should have been found in the EFD data block.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }
    else if ( !(verifyEfdBuffer(iv_frequency, iv_rank, 0xAA, 0xDD) ) )
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "Found matches for frequency value (%d) / master rank "
                "(%d) but the EFD buffer returned frequency value "
                "(%d) / master rank (%d) which don't match.",
                iv_frequency, iv_rank,
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }


    ++iv_numTests;
    /// Match EFD data block[31]
    // 31 - The EFD data block to set up for this test
    // 14930 - a valid frequency (see doc 1U2UDDIMM_SPD.docx) to be found
    // 2 - a valid master rank (see doc 1U2UDDIMM_SPD.docx) to be found
    // 0x11 and 0x22 - Tag data for the EFD data block.  This will tag the
    // EFD data block, at the start and end, so that it can be confirmed
    // the actual EFD data block is returned.  Without this tag, the
    // ddimm_get_efd call can spoof data coming back.  This is to keep the
    // code honest.
    configureEfdDataBlockN(31, 14930, 2, 0x11, 0x22);
    iv_vpdInfo.iv_omi_freq_mhz = 14930;
    iv_vpdInfo.iv_rank = 2;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) "
                "are valid.  Should have been found in the EFD data block.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }
    else if ( !(verifyEfdBuffer(14930, 2, 0x11, 0x22) ) )
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "Found matches for frequency value (14930) / master rank "
                "(2) but the EFD buffer returned frequency value "
                "(%d) / master rank (%d) which don't match.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }


    ++iv_numTests;
    /// Set EFD data block[31] to not implemented, no match
    // 31 -The EFD data block to set to not implemented.  Although
    // the data is match, this should not be returned because it is
    // not implemented.
    setEfdMetaDataNisImplemented(31, false);
    // 31 - The EFD data block to set up for this test
    // 14930 - a valid frequency (see doc 1U2UDDIMM_SPD.docx) to be found
    // 2 - a valid master rank (see doc 1U2UDDIMM_SPD.docx) to be found
    // 0x11 and 0x22 - Tag data for the EFD data block.  This will tag the
    // EFD data block, at the start and end, so that it can be confirmed
    // the actual EFD data block is returned.  Without this tag, the
    // ddimm_get_efd call can spoof data coming back.  This is to keep the
    // code honest.  BUT, in this case nothing should be returned because
    // the block is not implemented.
    configureEfdDataBlockN(31, 14930, 2, 0x11, 0x22);
    iv_vpdInfo.iv_omi_freq_mhz = 14930;
    iv_vpdInfo.iv_rank = 2;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) should "
                "not have been found in the EFD data block, because the "
                "implemented flag is false.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }


    ++iv_numTests;
    /// Set EFD data block[31] to not implemented, turn FFDC off, no match
    // 31 -The EFD data block to set to not implemented.  Although
    // the data is match, this should not be returned because it is
    // not implemented.
    setEfdMetaDataNisImplemented(31, false);
    // 31 - The EFD data block to set up for this test
    // 14930 - a valid frequency (see doc 1U2UDDIMM_SPD.docx) to be found
    // 2 - a valid master rank (see doc 1U2UDDIMM_SPD.docx) to be found
    // 0x11 and 0x22 - Tag data for the EFD data block.  This will tag the
    // EFD data block, at the start and end, so that it can be confirmed
    // the actual EFD data block is returned.  Without this tag, the
    // ddimm_get_efd call can spoof data coming back.  This is to keep the
    // code honest.  BUT, in this case nothing should be returned because
    // the block is not implemented.
    configureEfdDataBlockN(31, 14930, 2, 0x11, 0x22);
    iv_vpdInfo.iv_omi_freq_mhz = 14930;
    iv_vpdInfo.iv_rank = 2;
    // Exercise the FFDC enabled flag to not do FFDC
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc == fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) should "
                "not have been found in the EFD data block, because the "
                "implemented flag is false.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }


    ++iv_numTests;
    /// Match on EFD data block[15]
    // 31 -The EFD data block to set to implemented.  So the EFD data block
    // is returned when matched.
    setEfdMetaDataNisImplemented(15, true);
    // 15 - The EFD data block to set up for this test
    // 21330 - a valid frequency (see doc 1U2UDDIMM_SPD.docx) to be found
    // 2 - a valid master rank (see doc 1U2UDDIMM_SPD.docx) to be found
    // 0x44 and 0x55 - Tag data for the EFD data block.  This will tag the
    // EFD data block, at the start and end, so that it can be confirmed
    // the actual EFD data block is returned.  Without this tag, the
    // ddimm_get_efd call can spoof data coming back.  This is to keep the
    // code honest.
    configureEfdDataBlockN(15, 21330, 2, 0x44, 0x55);
    // 12800, 17060, 25600 - these valid frequencies (see doc
    // 1U2UDDIMM_SPD.docx) will be ORed to all EFD data blocks.  This will
    // test if the data block is found when the frequency is obfuscated with
    // other frequencies.
    appendToAllEfdDataBlocksFreq(12800);
    appendToAllEfdDataBlocksFreq(17060);
    appendToAllEfdDataBlocksFreq(25600);
    iv_vpdInfo.iv_omi_freq_mhz = 21330;
    iv_vpdInfo.iv_rank = 2;
    // Exercise the FFDC enabled flag to not do FFDC
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) "
                "are valid.  Should have been found in the EFD data block.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }
    else if ( !(verifyEfdBuffer(21330, 2, 0x44, 0x55) ) )
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "Found matches for frequency value (21330) / master rank "
                "(2) but the EFD buffer returned frequency value "
                "(%d) / master rank (%d) which don't match.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }


    ++iv_numTests;
    /// Match on EFD data block[23]
    // 23 -The EFD data block to set to implemented.  So the EFD data block
    // is returned when matched.
    setEfdMetaDataNisImplemented(23, true);
    // 1 - set all EFD data blocks to this valid master rank (see doc
    // 1U2UDDIMM_SPD.docx) will
    setAllEfdDataBlocksRank(1);
    // 12800 - set all EFD data blocks to this valid frequency (see doc
    // 1U2UDDIMM_SPD.docx) will
    setAllEfdDataBlocksFreq(12800);
    // 23 - The EFD data block to set up for this test
    // 19200 - a valid frequency (see doc 1U2UDDIMM_SPD.docx) to be found
    // 3 - a valid master rank (see doc 1U2UDDIMM_SPD.docx) to be found
    // 0x13 and 0x67 - Tag data for the EFD data block.  This will tag the
    // EFD data block, at the start and end, so that it can be confirmed
    // the actual EFD data block is returned.  Without this tag, the
    // ddimm_get_efd call can spoof data coming back.  This is to keep the
    // code honest.
    configureEfdDataBlockN(23, 19200, 3, 0x13, 0x67);
    // 12800, 14930, 17060, 21330, 23460, 25600 - these valid frequencies (see
    // doc 1U2UDDIMM_SPD.docx) will be ORed to all EFD data blocks.  This will
    // test if the data block is found when the frequency is obfuscated with
    // other frequencies.
    appendToAllEfdDataBlocksFreq(12800);
    appendToAllEfdDataBlocksFreq(14930);
    appendToAllEfdDataBlocksFreq(17060);
    appendToAllEfdDataBlocksFreq(21330);
    appendToAllEfdDataBlocksFreq(23460);
    appendToAllEfdDataBlocksFreq(25600);
    iv_vpdInfo.iv_omi_freq_mhz = 19200;
    iv_vpdInfo.iv_rank = 3;
    // Exercise the FFDC enabled flag to not do FFDC
    iv_vpdInfo.iv_is_config_ffdc_enabled = false;
    iv_rc = ddimm_get_efd(l_fapi2Target, iv_vpdInfo, iv_efdBufferPtr,
                          iv_spdBufferPtr, iv_spdBufferSize);
    if (iv_rc != fapi2::FAPI2_RC_SUCCESS)
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "VPD info frequency value (%d) / master rank (%d) "
                "are valid.  Should have been found in the EFD data block.",
                iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }
    else if ( !(verifyEfdBuffer(19200, 3, 0x13, 0x67) ) )
    {
        ++iv_numFails;
        TS_FAIL("findMatchTest: test failed: "
                "Found matches for frequency value (19200) / master rank "
                "(3) but the EFD buffer returned frequency value "
                "(%d) / master rank (%d) which don't match.",
                 iv_vpdInfo.iv_omi_freq_mhz, iv_vpdInfo.iv_rank);
    }

    FAPI_INF("<< findMatchTest");
}

//******************************************************************************
//                   Private Utilities To Facilitate Testing
//******************************************************************************

//******************************************************************************
// initializeSpdBuffer
//******************************************************************************
void fapi2DdimmGetEfdTest::initializeSpdBuffer()
{
    // Create SPD buffer and scrub the memory
    createSpdBuffer(iv_spdBufferPtr, iv_spdBufferSize);

    // I am not going to check if buffer is large enough to do the
    // following.  I am not writing tests for test cases!!!

    // Configure the SPD buffer to defaults
    setSpdDdimmType(DEFAULT_SPD_DDIMM_TYPE);
    setEfdMemorySpaceLocation(iv_efdMemorySpaceLocation);
    setEfdMemorySpaceSize(iv_efdMemorySpaceSize);
    setEfdCount(iv_efdCount);
    setSpdDmbMfgId(iv_spdDmbMfgId);
    setSpdDmbRevision(iv_spdDmbRevision);

    // Configure the EFD meta data to defaults
    setAllEfdMetaDatasEfdDataBlockSize(iv_efdBlockSizeMultiplier);
    setAllEfdMetaDatasExtendedFunctionType(iv_extendedFunctionType);
    setAllEfdMetaDatasIsImplemented(true);

    // Configure the EFD data blocks to defaults
    setAllEfdDataBlocksFreq(iv_frequency);
    setAllEfdDataBlocksRank(iv_rank);
}

//******************************************************************************
// createSpdBuffer
//******************************************************************************
void fapi2DdimmGetEfdTest::createSpdBuffer(uint8_t*     &o_spdBufferPtr,
                                     const size_t  i_spdBufferSize)
{
    delete o_spdBufferPtr; // it is OK to delete a nullptr

    o_spdBufferPtr = new uint8_t[i_spdBufferSize];
    // Set data to all 1's, so testing can be more vigorous
    memset(o_spdBufferPtr, 0xFF, i_spdBufferSize);

    // Set the pointer to beginning of the EFD meta data
    iv_efdMetaDataPtr = o_spdBufferPtr + EFD_META_DATA_OFFSET;
}

//******************************************************************************
// setSpdDdimmType
//******************************************************************************
void fapi2DdimmGetEfdTest::setSpdDdimmType(const uint8_t i_spdDdimmType)
{
    memcpy(&(iv_spdBufferPtr[SPD_DDIMM_TYPE_OFFSET]),
           reinterpret_cast<const uint8_t*>(&i_spdDdimmType),
           sizeof(i_spdDdimmType) );
}

//******************************************************************************
// setEfdMemorySpaceLocation
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdMemorySpaceLocation(
                                        const uint64_t i_efdMemorySpaceLocation)
{
    uint64_t l_efdMemorySpaceLocation = le64toh(i_efdMemorySpaceLocation);
    memcpy(&(iv_spdBufferPtr[EFD_MEMORY_SPACE_OFFSET]),
           reinterpret_cast<const uint8_t*>(&l_efdMemorySpaceLocation),
           sizeof(l_efdMemorySpaceLocation) );

    // Update / Set EFD Memory Block pointer to point the beginning of the
    // memory space
    l_efdMemorySpaceLocation = *(reinterpret_cast<const uint64_t*>
                                   (&iv_spdBufferPtr[EFD_MEMORY_SPACE_OFFSET]));
    l_efdMemorySpaceLocation = le64toh(l_efdMemorySpaceLocation);
    iv_efdBlockDataPtr = iv_spdBufferPtr + l_efdMemorySpaceLocation;
}

//******************************************************************************
// setEfdMemorySpaceSize
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdMemorySpaceSize(
                                             const uint8_t i_efdMemorySpaceSize)
{
    memcpy(&(iv_spdBufferPtr[EFD_MEMORY_SPACE_SIZE_OFFSET]),
           &i_efdMemorySpaceSize,
           sizeof(i_efdMemorySpaceSize) );
}

//******************************************************************************
// setEfdCount
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdCount(const uint16_t i_efdCount)
{
    uint16_t l_efdCount = le16toh(i_efdCount);
    memcpy(&(iv_spdBufferPtr[EFD_COUNT_OFFSET]),
            reinterpret_cast<const uint8_t*>(&l_efdCount),
            sizeof(l_efdCount) );
}

//******************************************************************************
// setSpdDmbMfgId
//******************************************************************************
void fapi2DdimmGetEfdTest::setSpdDmbMfgId(const uint16_t i_spdDmbMfgId)
{
    uint16_t l_spdDmbMfgId = le16toh(i_spdDmbMfgId);
    memcpy( &(iv_spdBufferPtr[SPD_DMB_MFG_ID_OFFSET]),
            reinterpret_cast<const uint8_t*>(&l_spdDmbMfgId),
            sizeof(l_spdDmbMfgId) );
}

//******************************************************************************
// setSpdDmbRevision
//******************************************************************************
void fapi2DdimmGetEfdTest::setSpdDmbRevision(const uint8_t i_spdDmbRevision)
{
    memcpy( &(iv_spdBufferPtr[SPD_DMB_REVISION_OFFSET]),
            &i_spdDmbRevision,
            sizeof(i_spdDmbRevision) );
}

//******************************************************************************
// setEfdMetaDataNEfdDataBlockEnd
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdMetaDataNEfdDataBlockEnd(
                                           const size_t  i_efdMetaDataN,
                                           const uint8_t i_efdDataBlockEnd)
{
    memcpy( &(iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 2]),
            &i_efdDataBlockEnd,
            sizeof(i_efdDataBlockEnd) );
}

//******************************************************************************
// setAllEfdMetaDatasEfdDataBlockSize
//******************************************************************************
void fapi2DdimmGetEfdTest::setAllEfdMetaDatasEfdDataBlockSize(
                                           const uint8_t i_efdDataBlockSize)
{
    for (int ii = 0; ii < iv_efdCount; ++ii)
    {
        setEfdMetaDataNEfdDataBlockEnd(ii, (ii + 1) * i_efdDataBlockSize);
    }
}

//******************************************************************************
// setEfdMetaDataExtendedFunctionType
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdMetaDataExtendedFunctionType(
                                           const size_t  i_efdMetaDataN,
                                           const uint8_t i_extendedFunctionType)

{
    // Extended Function Type is located 1 byte from the beginning of the meta
    // data.  It is in bits 4 - 7 of byte 1 (0 based)

    // First extracts bits 4 to 7 from input
    uint8_t l_eft = EXTENDED_FUNCTION_TYPE_MASK & i_extendedFunctionType;

    // Retrieve the Extended Function Type
    // (iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 1]) and zero out bits 4 - 7,
    // then OR this with the given Extended Function Type (l_eft).
    l_eft = (l_eft |
               ( (iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 1]) &
                  EXTENDED_FUNCTION_TYPE_INVERSE_MASK) );

    memcpy(&(iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 1]),
           &l_eft,
           sizeof(l_eft) );
}

//******************************************************************************
// setAllEfdMetaDatasExtendedFunctionType
//******************************************************************************
void fapi2DdimmGetEfdTest::setAllEfdMetaDatasExtendedFunctionType(
                                           const uint8_t i_extendedFunctionType)
{
    for (int ii = 0; ii < iv_efdCount; ++ii)
    {
        setEfdMetaDataExtendedFunctionType(ii, i_extendedFunctionType);
    }
}

//******************************************************************************
// setEfdMetaDataNisImplemented
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdMetaDataNisImplemented(
                                           const size_t i_efdMetaDataN,
                                           const bool   i_isImplemented)
{
    // Initially set to false
    uint8_t l_isImplemented = 0x00;
    if (i_isImplemented)
    {
        // Change to true
        l_isImplemented = 0x80;
    }

    // Implemented state is located 3 bytes from the beginning of the meta
    // data.  It is in bit 7 of byte 3 (0 based)
    // Then map that to the byte that is there
    l_isImplemented = l_isImplemented |
                     (iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 3] &
                      IS_IMPLEMENTED_INVERSE_MASK) ;

    memcpy( &(iv_efdMetaDataPtr[(i_efdMetaDataN * 4) + 3]),
            &l_isImplemented,
            sizeof(l_isImplemented) );
}

//******************************************************************************
// setAllEfdMetaDatasIsImplemented
//******************************************************************************
void fapi2DdimmGetEfdTest::setAllEfdMetaDatasIsImplemented(
                                                     const bool i_isImplemented)
{
    for (size_t ii = 0; ii < iv_efdCount; ++ii)
    {
        setEfdMetaDataNisImplemented(ii, i_isImplemented);
    }
}

//******************************************************************************
// convertFrequency
//
//   Byte 0 of an EFD data block (data from document 1U2UDDIMM_SPD.docx)
//   INPUT:   25600 | 23460 | 21330 | 19200 | 17060 | 14930 | 12800
//   OUTPUT:  Bit 6 | Bit 5 | Bit 4 | Bit 3 | Bit 2 | Bit 1 | Bit 0
//******************************************************************************
uint16_t fapi2DdimmGetEfdTest::convertFrequency(const uint16_t i_frequency)
{
    uint16_t l_frequency(0);
    switch (i_frequency)
    {
        // data from document 1U2UDDIMM_SPD.docx
        case 12800: l_frequency = 0x0001; break;
        case 14930: l_frequency = 0x0002; break;
        case 17060: l_frequency = 0x0004; break;
        case 19200: l_frequency = 0x0008; break;
        case 21330: l_frequency = 0x0010; break;
        case 23460: l_frequency = 0x0020; break;
        case 25600: l_frequency = 0x0040; break;
        default: TS_FAIL("Uknown Frequency (0x%.4X). Test needs updating "
                 "to accommodate this value", i_frequency ); break;
    }

    return le16toh(l_frequency);
}

//******************************************************************************
// setEfdDataBlockNFreq
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdDataBlockNFreq(const size_t   i_efdDataBlockN,
                                          const uint16_t i_frequency)
{
    uint16_t l_frequency = convertFrequency(i_frequency);
    memcpy(&(iv_efdBlockDataPtr[i_efdDataBlockN * iv_efdBlockSize]),
             reinterpret_cast<const uint8_t*>(&l_frequency),
             sizeof(l_frequency) );
}

//******************************************************************************
// setAllEfdDataBlocksFreq
//******************************************************************************
void fapi2DdimmGetEfdTest::setAllEfdDataBlocksFreq(const uint16_t i_frequency)
{
    for (size_t ii = 0; ii < iv_efdCount; ++ii)
    {
        setEfdDataBlockNFreq(ii, i_frequency);
    }
}

//******************************************************************************
// appendToEfdDataBlockNFreq
//******************************************************************************
void fapi2DdimmGetEfdTest::appendToEfdDataBlockNFreq(
                                               const size_t   i_efdDataBlockN,
                                               const uint16_t i_frequency)
{
    uint16_t l_frequency = convertFrequency(i_frequency);
    uint16_t l_currentFreq = *(reinterpret_cast<const uint16_t*>(
              &(iv_efdBlockDataPtr[i_efdDataBlockN * iv_efdBlockSize]) ) );
    l_frequency = l_frequency | l_currentFreq;
    memcpy(&(iv_efdBlockDataPtr[i_efdDataBlockN * iv_efdBlockSize]),
             reinterpret_cast<const uint8_t*>(&l_frequency),
             sizeof(l_frequency) );
}


//******************************************************************************
// appendToAllEfdDataBlocksFreq
//******************************************************************************
void fapi2DdimmGetEfdTest::appendToAllEfdDataBlocksFreq(
                                                     const uint16_t i_frequency)
{
    for (size_t ii = 0; ii < iv_efdCount; ++ii)
    {
        appendToEfdDataBlockNFreq(ii, i_frequency);
    }
}

//******************************************************************************
// convertRank
//
//   Master Rank (MR) (data from document 1U2UDDIMM_SPD.docx)
//   Byte 2 of an EFD data block
//   INPUT:  MR 3  | MR 2  | MR 1  | MR 0
//   OUTPUT: Bit 3 | Bit 2 | Bit 1 | Bit 0
//******************************************************************************
uint8_t fapi2DdimmGetEfdTest::convertRank(const uint8_t i_rank)
{
    uint8_t l_rank(0);
    switch (i_rank)
    {
        // data from document 1U2UDDIMM_SPD.docx
        case 0: l_rank = 0x01; break;
        case 1: l_rank = 0x02; break;
        case 2: l_rank = 0x04; break;
        case 3: l_rank = 0x08; break;
        default: TS_FAIL("Uknown Rank (0x%.2X). Test needs updating "
                 "to accommodate this value", i_rank ); break;
    }

    return l_rank;
}


//******************************************************************************
// setEfdDataBlockNRank
//******************************************************************************
void fapi2DdimmGetEfdTest::setEfdDataBlockNRank(const size_t  i_efdDataBlockN,
                          const uint8_t i_rank)
{
    uint8_t l_rank = convertRank(i_rank);
    memcpy( &(iv_efdBlockDataPtr[(i_efdDataBlockN * iv_efdBlockSize) + 2]),
            &l_rank,
            sizeof(l_rank) );
}


//******************************************************************************
// setAllEfdDataBlocksRank
//******************************************************************************
void fapi2DdimmGetEfdTest::setAllEfdDataBlocksRank(const uint8_t i_rank)
{
    for (size_t ii = 0; ii < iv_efdCount; ++ii)
    {
        setEfdDataBlockNRank(ii, i_rank);
    }
}


//******************************************************************************
// createEfdBuffer
//******************************************************************************
void fapi2DdimmGetEfdTest::createEfdBuffer(uint8_t*     &o_efdBufferPtr,
                                     const size_t  i_efdBufferSize)
{
    delete o_efdBufferPtr; // it is OK to delete a nullptr

    o_efdBufferPtr = new uint8_t[i_efdBufferSize];
    // Set data to all 1's, so testing can be more vigorous
    memset(o_efdBufferPtr, 0xFF, i_efdBufferSize);
}


//******************************************************************************
// initializeVpdInfo
//******************************************************************************
void fapi2DdimmGetEfdTest::initializeVpdInfo(
                        fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP>& o_vpdInfo)
{
    // Set the size to a default value
    o_vpdInfo.iv_size = iv_efdBlockSize;

    // Set frequency to default value
    o_vpdInfo.iv_omi_freq_mhz = iv_frequency;

    // Set rank to default value
    o_vpdInfo.iv_rank = iv_rank;

    // Enable the FFDC enable flag
    o_vpdInfo.iv_is_config_ffdc_enabled = true;
}


//******************************************************************************
// configureEfdDataBlockN
//******************************************************************************
void fapi2DdimmGetEfdTest::configureEfdDataBlockN(
                                            const size_t   i_efdDataBlockN,
                                            const uint16_t i_frequency,
                                            const uint8_t  i_rank,
                                            const uint8_t  i_beginTag,
                                            const uint8_t  i_endTag)
{
    setEfdDataBlockNFreq(i_efdDataBlockN, i_frequency);
    setEfdDataBlockNRank(i_efdDataBlockN, i_rank);
    tagEfdDataBlockN(i_efdDataBlockN, i_beginTag, i_endTag);
}


//******************************************************************************
// verifyEfdBuffer
//******************************************************************************
bool fapi2DdimmGetEfdTest::verifyEfdBuffer(const uint16_t i_frequency,
                                     const uint8_t  i_rank,
                                     const uint8_t  i_beginTag,
                                     const uint8_t  i_endTag)

{
    uint8_t l_rank = convertRank(i_rank);
    uint16_t l_frequency = convertFrequency(i_frequency);

    const uint16_t l_efdfreq =
                          *(reinterpret_cast<const uint16_t*>(iv_efdBufferPtr));

    return ( (l_rank == iv_efdBufferPtr[2])     &&
             (l_frequency | l_efdfreq)        &&
             (iv_efdBufferPtr[4] == i_beginTag) &&
             (iv_efdBufferPtr[iv_efdBlockSize - 1] == i_endTag) );
}


//******************************************************************************
// tagEfdDataBlockN
//******************************************************************************
void fapi2DdimmGetEfdTest::tagEfdDataBlockN(const size_t  i_efdDataBlockN,
                                      const uint8_t i_beginTag,
                                      const uint8_t i_endTag)
{
    // Tag data 4 bytes beyond the beginning of the EFD data block.  The
    // first bytes of the EFD data block contain the frequency and master
    // rank.  Need that data for comparison.  Do not want to over write that
    // data so tag after the frequency and master rank data.
    memcpy(&(iv_efdBlockDataPtr[(i_efdDataBlockN * iv_efdBlockSize) + 4]),
           &i_beginTag,
           sizeof(i_beginTag) );

    // Tag the ending byte.
    memcpy(&(iv_efdBlockDataPtr[(i_efdDataBlockN * iv_efdBlockSize) +
                                 (iv_efdBlockSize - 1)]),
            &i_endTag,
            sizeof(i_endTag) );
}
