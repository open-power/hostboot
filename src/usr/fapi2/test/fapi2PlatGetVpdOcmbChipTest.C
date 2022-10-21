/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/fapi2/test/fapi2PlatGetVpdOcmbChipTest.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2022                        */
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

#include <fapi2PlatGetVpdOcmbChipTest.H>
#include <plat_vpd_access.H>

// The maximum size of a the EFD buffer
// Ony used if failed to get buffer size
const size_t DEFAULT_MAX_BYTES_BUFFER_SIZE = 128;


void fapi2PlatGetVpdOcmbChipTest::testPlatGetVPD_EFD()
{
    FAPI_INF(">>testGetVPD_EFD");

    // Find a valid target of type OCMB_CHIP
    TARGETING::TargetHandleList l_ocmbTargetList;
    TARGETING::getAllChips(l_ocmbTargetList, TARGETING::TYPE_OCMB_CHIP, true);
    TS_INFO("testPlatGetVPD_EFD: l_ocmbTargetList.size=%d", l_ocmbTargetList.size());
    if (!l_ocmbTargetList.size())
    {
        TS_FAIL("<<testGetVPD_EFD: No valid TYPE_OCMB_CHIP target found. "
                "Can not execute test cases.");
        return;
    }

    // Some useful variables
    size_t l_numTests(0);
    size_t l_numFails(0);
    fapi2::ReturnCode l_rc{fapi2::FAPI2_RC_SUCCESS};
    fapi2::VPDInfo<fapi2::TARGET_TYPE_OCMB_CHIP> l_vpdInfo(fapi2::EFD);

    /// Test case 1
    // Test with a "bad" target
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 1 start");

        fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_ocmbChipTarget;
        uint8_t* o_efdBuffer(nullptr);

        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 1 failed: OCMB_CHIP target is a "
                    "nullptr but platGetVPD returned SUCCESS.");

            ++l_numFails;
            break;
        }

    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 1 end");


    /// Test case 2
    // Test with an invalid target.  If no invalid target is found, then move
    // on - do not fail the test.  This test is an unlikely scenario and not
    // so critical that it needs to fail if unable to perform.
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 2 start");

        // Get a list of targets
        TARGETING::TargetRangeFilter l_targetList(
                                     TARGETING::targetService().begin(),
                                     TARGETING::targetService().end(),
                                     nullptr);

        // Iterate thru the list looking for the first NON OCMB_CHIP target
        for ( ; l_targetList; ++l_targetList)
        {
            if ( TARGETING::TYPE_OCMB_CHIP !=
                 (*l_targetList)->getAttr<TARGETING::ATTR_TYPE>() )
            {
                // Found first non OCMB_CHIP target, break out and use it
                TS_INFO("testGetVPD_EFD: Using %.8X for test case 2",
                        TARGETING::get_huid(*l_targetList));
                break;
            }
        }

        // l_targetList is just an iterator that gets advanced in a container.
        // If that iterator is still valid then we can safely assume that
        // it points to a non OCMB_CHIP target
        if (l_targetList)
        {
            ++l_numTests;
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_ocmbChipTarget
                = { *l_targetList };
            uint8_t* o_efdBuffer(nullptr);

            l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                TS_FAIL("testGetVPD_EFD: Test case 2 failed: OCMB_CHIP target "
                        "is invalid (the target is being spoofed with a "
                        "different type) but platGetVPD returned SUCCESS.");

                ++l_numFails;
                break;
            } // end if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        }  // end if (l_targetList)
    } while (0);
    TS_INFO("testGetVPD_EFD: Test case 2 end");


    // Initialize input data
    fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_ocmbChipTarget(l_ocmbTargetList[0]);
    uint8_t* o_efdBuffer{nullptr};

    // check if the OCMB is Planar, to add some additional data to l_vpdInfo
    if(l_ocmbTargetList[0]->getAttr<TARGETING::ATTR_MEM_MRW_IS_PLANAR>())
    {
        // data taken from a Bonito config ipl.
        // see add_planar_efd_info() for how this
        // data is normally populated
        l_vpdInfo.iv_dimm_count = 1;
        l_vpdInfo.iv_total_ranks_dimm0 = 1;
        l_vpdInfo.iv_total_ranks_dimm1 = 0;
        l_vpdInfo.iv_dimm_type = 5;
    }

    /// Test case 3
    // Test with nullptr buffer
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 3 start");

        // Initialize the essential input variables
        l_vpdInfo.iv_size = 0;

        // Make the platGetVPD call with buffer size 0 and buffer set at nullptr
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        // Error if call not successful and size is 0
        if (l_rc != fapi2::FAPI2_RC_SUCCESS || !l_vpdInfo.iv_size)
        {
            TS_FAIL("testGetVPD_EFD: Test case 3 failed: Failed to return a "
                     "buffer size.");

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 3 end");

    // If no buffer size returned from previous call then set size to default
    if (!l_vpdInfo.iv_size)
    {
        l_vpdInfo.iv_size = DEFAULT_MAX_BYTES_BUFFER_SIZE;
    }

    // Create the memory for the buffer
    o_efdBuffer = new uint8_t[l_vpdInfo.iv_size];

    /// Test case 4
    // Test with data that will not find a match on frequency
    // and enable ffdc set to false.
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 4 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 19200;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = false;

        // Make the platGetVPD call
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 4 failed: Request for EFD with "
                    "frequency %d and rank %d should have failed.",
                    l_vpdInfo.iv_omi_freq_mhz, l_vpdInfo.iv_rank);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 4 end");


    /// Test case 5
    // Test with data that will not find a match on frequency
    // and enable ffdc set to true.
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 5 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 25600;
        l_vpdInfo.iv_rank = 2;
        l_vpdInfo.iv_is_config_ffdc_enabled = true;

        // Make the platGetVPD call
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 5 failed: Request for EFD with "
                    "frequency %d and rank %d should have failed.",
                    l_vpdInfo.iv_omi_freq_mhz, l_vpdInfo.iv_rank);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 5 end");


    /// Test case 6
    // Test when the size of the output buffer is insufficient to hold
    // the found EFD block data
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 6 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 21330;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = false;

        // Shrink the buffer size to be less than size of returning data
        --l_vpdInfo.iv_size;

        // Make the platGetVPD call
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc == fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 6 failed: Size of buffer (%d) "
                    "is inadequate to hold returning data, size (%d).",
                    l_vpdInfo.iv_size, (l_vpdInfo.iv_size + 1));

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 6 end");

    /// Test case 7
    // Test when the size of the output buffer is greater than
    // the size of the found EFD block data
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 7 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 21330;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = false;

        // Increase the buffer size to be greater than size of returning data
        ++l_vpdInfo.iv_size;

        // Make the platGetVPD call
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 7 failed: Failed with known "
                     "good data - frequency(%d), master rank(%d) "
                     "and buffer size(%d)",
                     l_vpdInfo.iv_omi_freq_mhz,
                     l_vpdInfo.iv_rank,
                     l_vpdInfo.iv_size);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 7 end");

    /// Test case 8
    // Test with data that is guaranteed to find a match 1
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 8 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 25600;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = true;

        // Make the platGetVPD call to find the EFD data block that matches
        // given data
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 8 failed: Failed with known "
                     "good data - frequency(%d), master rank(%d) "
                     "and buffer size(%d)",
                     l_vpdInfo.iv_omi_freq_mhz,
                     l_vpdInfo.iv_rank,
                     l_vpdInfo.iv_size);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 8 end");


    //TODO RTC: 258808 - Re-enable when we have VPD that supports it
/*
    /// Test case 9
    // Test with data that is guaranteed to find a match 2
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 9 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 23460;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = true;

        // Make the platGetVPD call to find the EFD data block that matches
        // given data
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);


        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 9 failed: Failed with known "
                     "good data - frequency(%d), master rank(%d) "
                     "and buffer size(%d)",
                     l_vpdInfo.iv_omi_freq_mhz,
                     l_vpdInfo.iv_rank,
                     l_vpdInfo.iv_size);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 9 end");

**/

    /// Test case 10
    // Test with data that is guaranteed to find a match 3
    ++l_numTests;
    do
    {
        TS_INFO("testGetVPD_EFD: Test case 10 start");

        // Initialize the other input variables
        l_vpdInfo.iv_omi_freq_mhz = 21330;
        l_vpdInfo.iv_rank = 0;
        l_vpdInfo.iv_is_config_ffdc_enabled = true;

        // Make the platGetVPD call to find the EFD data block that matches
        // given data
        l_rc = platGetVPD(l_ocmbChipTarget, l_vpdInfo, o_efdBuffer);

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            TS_FAIL("testGetVPD_EFD: Test case 10 failed: Failed with known "
                     "good data - frequency(%d), master rank(%d) "
                     "and buffer size(%d)",
                     l_vpdInfo.iv_omi_freq_mhz,
                     l_vpdInfo.iv_rank,
                     l_vpdInfo.iv_size);

            ++l_numFails;
            break;
        }
    } while(0);
    TS_INFO("testGetVPD_EFD: Test case 10 end");

    // Clean up memory
    delete []o_efdBuffer;
    o_efdBuffer = nullptr;

    FAPI_INF("<<testGetVPD_EFD: Test Complete. %d/%d fails",
             l_numFails, l_numTests);
};  // end void fapi2PlatGetVpdOcmbChipTest::testPlatGetVPD_EFD()


