/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/expupd/test/expupdatetest.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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

#ifndef __EXPUPDATETEST_H
#define __EXPUPDATETEST_H

/**
 *  @file expupdatetest.H
 *
 *  @brief Test cases for explorer chip firmware update
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <exp_inband.H>
#include <exp_data_structs.H>
#include <exp_fw_update.H>
#include <generic/memory/lib/utils/endian_utils.H>
#include <test/exptest_utils.H>
#include <expupd/ocmbFwImage_const.H>
#include <ocmbFwImage.H>
#include <expupd_trace.H>
#include <expupd/expupd_reasoncodes.H>
#include <spdenums.H>
#include <spd.H>
#include <ocmb_spd.H>
#include <algorithm>
#ifndef __HOSTBOOT_RUNTIME
#include <vfs/vfs.H> // module_is_loaded & module_load
#endif

namespace expupd
{
    // Functionality entry-points being brought in to be tested
    void writeExplorerFwVersion(TARGETING::TargetHandle_t i_ocmb, const uint8_t* i_versionStr,
        const size_t i_strSize);
    errlHndl_t ocmbFwValidateImage(const uint64_t i_imageStart, const uint64_t i_imageSize,
        rawImageInfo_t& o_imageInfo);
    errlHndl_t setFwVersionInfo(const uint8_t* i_tripletStartPtr, const size_t i_tripletSize,
        rawImageInfo_t& o_imageInfo);
}

using namespace expupd;

const char MSS_LIBRARY_NAME[] = "libisteps_mss.so";
const char EXPUPD_LIBRARY_NAME[] = "libexpupd.so";

/**
 * @brief Generic function to load a module
 * @param i_modName - module name to load
 * @return error handle if module_load call fails
 */
errlHndl_t loadModule(const char * i_modName)
{
    errlHndl_t err = nullptr;

// VFS functions only compilable in non-runtime environment
#ifndef __HOSTBOOT_RUNTIME
    if(!VFS::module_is_loaded(i_modName))
    {
        err = VFS::module_load(i_modName);
        if(err)
        {
            TS_FAIL("loadModule() - %s load failed", i_modName );
        }
        else
        {
            TS_TRACE("loadModule: %s loaded", i_modName);
        }
    }
#endif
    return err;
}


class ExpUpdateTest: public CxxTest::TestSuite
{
  public:

    /**
     *  @brief Test the explorer firmware update hardware procedure
     */
    void  testExpFwUpdate( void )
    {
        TS_INFO(ENTER_MRK "testExpFwUpdate: entering");
        // Create a vector of TARGETING::Target pointers
        TARGETING::TargetHandleList l_chipList;

        // Get a list of all of the functioning ocmb chips
        TARGETING::getAllChips(l_chipList, TARGETING::TYPE_OCMB_CHIP, true);

        //Enable update code
        uint8_t l_dataBuffer[4096] = {0};
        errlHndl_t l_errl = nullptr;

        TARGETING::HB_MUTEX_SERIALIZE_TEST_LOCK_ATTR l_mutex = exptest::getTestMutex();
        if (l_mutex == nullptr)
        {
            TS_FAIL("testExpFwUpdate: unable to get test mutex");
        }
        else
        {
            for (const auto & l_ocmb: l_chipList)
            {
                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2_target(l_ocmb);

                // Inband operations can't be run at the same time
                // atomic section >>
                mutex_lock(l_mutex);

                // Invoke procedure
                FAPI_INVOKE_HWP(l_errl, exp_fw_update, l_fapi2_target,
                                l_dataBuffer, sizeof(l_dataBuffer));

                // << atomic section
                mutex_unlock(l_mutex);
                if (l_errl)
                {
#if 0  // skipping exp_fw_update error until simics is changed - @fixme:RTC-209865
                    TS_FAIL("Error from exp_fw_update for 0x%.8X target",
                        TARGETING::get_huid(l_ocmb));
#endif
                    break;
                }
            }

            if (l_errl)
            {
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
        }
        TS_INFO(EXIT_MRK "testExpFwUpdate: exiting");
    };

    /**
     *  @brief When the firmware of an OCMB chip is updated, the firmware version is written to the
     *  SPD of the corresponding DDIMM. Test this writing functionality.
     */
    void testFwVersionWrite( void )
    {
        TS_INFO(ENTER_MRK "testFwVersionWrite: entering");

        errlHndl_t l_err = nullptr;

        // FW-version test string
        const size_t l_testStrSize = 8;
        const uint8_t l_testStr[l_testStrSize] = {'t', 'e', 's', 't', '1', '2', '3', '4'};

        // Get one functional OCMB target
        TARGETING::TargetHandleList l_ocmbList;
        TARGETING::getAllChips(l_ocmbList, TARGETING::TYPE_OCMB_CHIP);
        TARGETING::TargetHandle_t l_ocmb = l_ocmbList[0];

        // Get SPD-keyword EXPLORER_FW_VERSION length
        const uint64_t l_fwVersionKW = SPD::EXPLORER_FW_VERSION;
        const SPD::KeywordData *l_fWVerKeyword = {nullptr};
        uint8_t l_memType(SPD::MEM_TYPE_INVALID);

        do
        {
            l_err = OCMB_SPD::getMemType( l_memType, l_ocmb );
            if( l_err )
            {
                TS_FAIL("testFwVersionWrite: Failed to get the memType of OCMB: 0x%08X",
                        TARGETING::get_huid(l_ocmb));
                break;
            }

            l_err = getKeywordEntry(l_fwVersionKW, l_memType, l_ocmb, l_fWVerKeyword);
            if( l_err )
            {
                TS_FAIL("testFwVersionWrite: Failed to get the Keyword entry for EXPLORER_FW_VERSION "
                        "on OCMB: 0x%08X",
                        TARGETING::get_huid(l_ocmb));
                break;
            }

            // skip the test if the keyword isn't writable in this config
            if( !l_fWVerKeyword->writable )
            {
                TS_INFO("EXPLORER_FW_VERSION is readonly on %.8X, skipping test",
                        TARGETING::get_huid(l_ocmb));
                break;
            }

            const size_t l_spdKeywordSize = l_fWVerKeyword->length;

            uint8_t l_originalData [l_spdKeywordSize] = {};


            /* Save off original data in the EXPLORER_FW_VERSION SPD keyword section */
            l_err = deviceRead(l_ocmb, &l_originalData, (size_t&)l_spdKeywordSize,
                DEVICE_SPD_ADDRESS(l_fwVersionKW));

            if (l_err)
            {
                TS_FAIL("testFwVersionWrite: Failed to read SPD keyword data EXPLORER_FW_VERSION. "
                    "OCMB: 0x%08X", TARGETING::get_huid(l_ocmb));
                break;
            }

            /* Run version string update */
            TS_TRACE("testFwVersionWrite: Testing with OCMB chip 0x%08X.", TARGETING::get_huid(l_ocmb));
            writeExplorerFwVersion(l_ocmb, l_testStr, l_testStrSize);

            /* Check that the version string was placed correctly */
            uint8_t l_readBackData [l_spdKeywordSize] = {};
            uint8_t l_paddedTestStr [l_spdKeywordSize] = {};
            memcpy(l_paddedTestStr, l_testStr, l_testStrSize);
            l_err = deviceRead(l_ocmb, &l_readBackData, (size_t&)l_spdKeywordSize,
                DEVICE_SPD_ADDRESS(l_fwVersionKW));
            if (l_err)
            {
                TS_FAIL("testFwVersionWrite: Failed to read SPD keyword data EXPLORER_FW_VERSION "
                    "after running writeExplorerFwVersion. OCMB: 0x%08X", TARGETING::get_huid(l_ocmb));
                break;
            }
            if (memcmp(l_readBackData, l_paddedTestStr, l_spdKeywordSize) != 0)
            {
                TRACFBIN(g_trac_expupd, "testFwVersionWrite: Test FW version string:",
                    l_paddedTestStr, l_spdKeywordSize);
                TRACFBIN(g_trac_expupd, "testFwVersionWrite: Actual FW version string read back:",
                    l_readBackData, l_spdKeywordSize);
                TS_FAIL("testFwVersionWrite: expupd::writeExplorerFwVersion failed to write "
                    "version string to SPD of OCMB: 0x%08X", TARGETING::get_huid(l_ocmb));
            }

            /* Write back original data*/
            l_err = deviceWrite(l_ocmb, l_originalData, (size_t&)l_spdKeywordSize,
                DEVICE_SPD_ADDRESS(l_fwVersionKW));
            if (l_err)
            {
                TS_FAIL("testFwVersionWrite: Failed to write back SPD keyword data "
                    "EXPLORER_FW_VERSION. OCMB: 0x%08X", TARGETING::get_huid(l_ocmb));
                break;
            }

        } while (0);

        // Commit error if any
        if (l_err)
        {
            errlCommit(l_err, CXXTEST_COMP_ID);
        }

        TS_INFO(EXIT_MRK "testFwVersionWrite: exiting");
    }

    /**
     *  @brief Test expupd::ocmbFwValidateImage by passing a hard-coded, correctly formatted OCMB
     *  FW header. The test is considered a success if the output struct of the function o_imageInfo
     *  has imageSHA512HashPtr, fwVersionStrPtr, and fwVersionStrSize set to the values of the
     *  hard-coded header.
     *  Note that expupd::ocmbFwValidateImage uses expupd::setFwVersionInfo() to fill in
     *  fwVersionStrPtr and fwVersionStrSize. Therefore, the expected path of that function is being
     *  tested here as well.
     */
    void testOcmbFwValidateImage( void )
    {
        TS_INFO(ENTER_MRK "testOcmbFwValidateImage: entering");

        errlHndl_t l_err = nullptr;

        const size_t l_testHeaderSize = 184;
        const uint8_t l_testHeader[l_testHeaderSize] =
        {
        0x4F, 0x43, 0x4D, 0x42, 0x48, 0x44, 0x52, 0x00,   0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xB8, 0x00, 0x00, 0x00, 0x02,   0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x40,
        0x2B, 0xE2, 0x09, 0x76, 0xC0, 0x10, 0x34, 0xE7,   0xE9, 0x19, 0x8A, 0xDF, 0xB2, 0x25, 0x6C, 0xC3,
        0x7E, 0x77, 0xB7, 0xB5, 0xFA, 0x6B, 0x29, 0x15,   0xE1, 0x9F, 0x47, 0xAB, 0xDF, 0x18, 0x9C, 0xAC,
        0xE4, 0xB9, 0x49, 0xDA, 0xB8, 0x9D, 0x64, 0xBB,   0x34, 0x72, 0xE9, 0x24, 0x7D, 0x07, 0x91, 0x78,
        0x57, 0x50, 0xA6, 0x80, 0x10, 0xBD, 0xE9, 0x1A,   0x01, 0xD3, 0x4B, 0x44, 0xDB, 0x54, 0x6F, 0xF3,
        0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x50,   0x75, 0x72, 0x6c, 0x3d, 0x68, 0x74, 0x74, 0x70,
        0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77, 0x2e, 0x69,   0x62, 0x6d, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x76,
        0x65, 0x72, 0x2c, 0x76, 0x65, 0x72, 0x73, 0x69,   0x6f, 0x6e, 0x3d, 0x31, 0x2e, 0x32, 0x2e, 0x33,
        0x2c, 0x74, 0x69, 0x6d, 0x65, 0x73, 0x74, 0x61,   0x6d, 0x70, 0x3d, 0x4d, 0x6f, 0x6e, 0x20, 0x44,
        0x65, 0x63, 0x20, 0x32, 0x38, 0x20, 0x31, 0x38,   0x3a, 0x32, 0x39, 0x3a, 0x33, 0x39, 0x20, 0x43,
        0x53, 0x54, 0x20, 0x32, 0x30, 0x32, 0x30, 0x00,
        };
            // ASCII translation:
            // *OCMBHDR.........*
            // *...............@*  ________________
            // *+..v..4......%l.*  Tagged data triplet with tag ID 1
            // *~w...k)...G.....*  SHA512 section
            // *..I...d.4r.$}..x*
            // *WP........KD.To.*  ________________
            // *.......Purl=http*  Tagged data triplet with tag ID 2
            // *://www.ibm.com/v*  Contains url, version, and timestamp
            // *er,version=1.2.3*  (starting with url all the way to the end)
            // *,timestamp=Mon D*
            // *ec 28 18:29:39 C*
            // *ST 2020.           ________________

        // Version string from l_testHeader above, starts at offset 131
        const size_t l_testFwStrSize = 13;
        uint8_t l_testFwStr[l_testFwStrSize] = {};
        memcpy(l_testFwStr, l_testHeader + 131, l_testFwStrSize);

        // SHA512 from l_testHeader above, starts at offset 32
        uint8_t l_testSHA512[HEADER_SHA512_SIZE] = {};
        memcpy(l_testSHA512, l_testHeader + 32, HEADER_SHA512_SIZE);

        do
        {
            rawImageInfo_t l_imageInfo;

            l_err = ocmbFwValidateImage((uint64_t)&l_testHeader, l_testHeaderSize, l_imageInfo);

            if (l_err)
            {
                TS_FAIL("testOcmbFwValidateImage: Error found when running ocmbFwValidateImage().");
                break;
            }

            if (l_testFwStrSize != l_imageInfo.fwVersionStrSize)
            {
                TS_FAIL("testOcmbFwValidateImage: Incorrect version string size retrieved when "
                    "testing ocmbFwValidateImage(). Expected: %lu, actual : %lu", l_testFwStrSize,
                    l_imageInfo.fwVersionStrSize);
            }

            if (memcmp(l_testFwStr, l_imageInfo.fwVersionStrPtr, l_testFwStrSize) != 0)
            {
                TS_FAIL("testOcmbFwValidateImage: Incorrect version string retrieved when testing "
                    "ocmbFwValidateImage().");
                TRACFBIN(g_trac_expupd, "testOcmbFwValidateImage: Firmware version string expected:",
                    l_testFwStr, l_testFwStrSize);
                TRACFBIN(g_trac_expupd, "testOcmbFwValidateImage: Firmware version string retrieved:",
                    l_imageInfo.fwVersionStrPtr, std::min(l_imageInfo.fwVersionStrSize, (size_t)MAX_BIN_TRACE));
            }

            if (memcmp(l_testSHA512, l_imageInfo.imageSHA512HashPtr, HEADER_SHA512_SIZE) != 0)
            {
                TS_FAIL("testOcmbFwValidateImage: Incorrect SHA512 retrieved when testing "
                    "ocmbFwValidateImage().");
                TRACFBIN(g_trac_expupd, "testOcmbFwValidateImage: SHA512 value expected:",
                    l_testSHA512, HEADER_SHA512_SIZE);
                TRACFBIN(g_trac_expupd, "testOcmbFwValidateImage: SHA512 value retrieved:",
                    l_imageInfo.imageSHA512HashPtr, HEADER_SHA512_SIZE);
            }

        } while (0);

        if (l_err)
        {
            errlCommit(l_err, CXXTEST_COMP_ID);
        }

        TS_INFO(EXIT_MRK "testOcmbFwValidateImage: exiting");
    }

    /**
     *  @brief Test failure path of expupd::setFwVersionInfo() when the "version=" string is not
     *  found in the data blob passed to the function.
     */
    void testSetFwVersionInfoFailurePath( void )
    {
        TS_INFO(ENTER_MRK "testSetFwVersionInfoFailurePath: entering");

        errlHndl_t l_err = nullptr;

        const size_t l_testFwVersionSize = 8;
        const uint8_t l_testFwVersion[l_testFwVersionSize] = {};

        do
        {
            rawImageInfo_t l_imageInfo;
            l_err = setFwVersionInfo(l_testFwVersion, l_testFwVersionSize, l_imageInfo);

            if ( l_err
                 && l_imageInfo.fwVersionStrSize == 0
                 && l_imageInfo.fwVersionStrPtr  == nullptr
                 && (l_err->reasonCode() == EXPUPD::MISSING_FW_VERSION)
                 && (l_err->moduleId()   == EXPUPD::MOD_SET_FW_VERSION_INFO) )
            {
                TS_TRACE("testSetFwVersionInfoFailurePath: Missing fw version string failed as expected.");
                delete l_err;
                l_err = nullptr;

                break;
            }

            TS_FAIL("testSetFwVersionInfoFailurePath: Test did not fail as expected.");

            if (l_imageInfo.fwVersionStrPtr)
            {
                TS_INFO("testSetFwVersionInfoFailurePath: From test fail, "
                    "l_imageInfo.fwVersionStrSize: %lu", l_imageInfo.fwVersionStrSize);
                TRACFBIN(g_trac_expupd, "testSetFwVersionInfoFailurePath: From test fail, FW "
                    "string representation in l_imageInfo:", l_imageInfo.fwVersionStrPtr,
                    std::min(l_imageInfo.fwVersionStrSize, (size_t)MAX_BIN_TRACE));
            }

            if (l_err)
            {
                TS_INFO("testSetFwVersionInfoFailurePath: Error info. "
                    "Expected RC: 0x%x ModId: 0x%x. Actual RC: 0x%x ModId: 0x%x.",
                    EXPUPD::MISSING_FW_VERSION, EXPUPD::MOD_SET_FW_VERSION_INFO,
                    l_err->reasonCode(), l_err->moduleId());
            }
            else
            {
                TS_INFO("testSetFwVersionInfoFailurePath: No error was returned.");
            }


        } while (0);

        if (l_err)
        {
            errlCommit(l_err, CXXTEST_COMP_ID);
        }

        TS_INFO(EXIT_MRK "testSetFwVersionInfoFailurePath: exiting");
    }

    /**
     * @brief Constructor
     */
    ExpUpdateTest() : CxxTest::TestSuite()
    {
        // All modules are loaded by runtime,
        // so testcase loading of modules is not required
#ifndef __HOSTBOOT_RUNTIME
        errlHndl_t err = nullptr;

        err = loadModule(MSS_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("ExpUpdateTest() - Constuctor: failed to load MSS module");
            errlCommit( err, CXXTEST_COMP_ID );
        }
        err = loadModule(EXPUPD_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("ExpUpdateTest() - Constuctor: failed to load EXPUPD module");
            errlCommit( err, CXXTEST_COMP_ID );
        }
#endif
    };


    /**
     * @brief Destructor
     */
    ~ExpUpdateTest()
    {
    };

    private:
};

#endif
