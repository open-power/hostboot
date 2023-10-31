/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ffdctest.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2023                        */
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
#ifndef __SBE_FFDCTEST_H
#define __SBE_FFDCTEST_H

/**
 *  @file sbe_ffdctest.H
 *
 *  @brief Test cases for sbe/hb ffdc package exchange
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbe_utils.H>
#include <return_code_defs.H>

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"ffdcParserTest: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class SbeFFDCTest : public CxxTest::TestSuite
{
public:

    /**
     *  @brief Test with zero data
     */
    void testSBEFFDC1(void)
    {
        bool testPassed = true;
        size_t l_num = 0;
        uint8_t data[16] = {
            0, 0,             // magic byte
            0, 0,             // package length
            0, 0,             // arbitrary sequence ID
            0, 0,             // arbitrary command class and commamd
            0, 0, 0, 0,       // return code
            0, 0, 0, 0        // arbitrary data
        };

        TS_TRACE("ffdcParserTest test 1 - no data");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data);

        l_num = l_ffdc_parser.getTotalPackages();
        if(l_num != 0)
        {
            TS_FAIL("ffdcParserTest test 1 FAILED: 0 expected, got %d", l_num);
            testPassed = false;
        }

        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 1 - no data PASSED");
        }
    }

    /**
     *  @brief Test with valid magic byte, 1 package, 1 word data
     */
    void testSBEFFDC2(void)
    {
        bool testPassed = true;
        size_t l_num = 0;
        uint8_t data[16] = {
            0xff, 0xdc,       // magic byte
            0, 4,             // package length of
            0, 1,             // arbitrary sequence ID
            1, 1,             // arbitrary command class and commamd
            0x00, 0x01, 0x02, 0x03, // return code
            1, 1, 1, 1        // arbitrary data
        };

        TS_TRACE("ffdcParserTest test 2 - 1 package, 1 word data");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data);

        l_num = l_ffdc_parser.getTotalPackages();
        if(l_num != 1)
        {
            TS_FAIL("ffdcParserTest test 2 FAILED: 1 expected, got %d", l_num);
            testPassed = false;
        }
        else
        {
            for(size_t i=0; i<l_num; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 66051)
                {
                    TS_FAIL("ffdcParserTest test 2 FAILED RC: expected 66051, got %d", l_rc);
                    testPassed = false;
                }
            }
        }

        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 2 - 1 package, 1 word data PASSED");
        }
    }

    /**
     *  @brief Test with valid magic byte, 1 package, 2 word data
     */
    void testSBEFFDC3(void)
    {
        bool testPassed = true;
        size_t l_num = 0;
        uint8_t data[20] = {
            0xff, 0xdc,      // magic byte
            0, 5,            // package length
            0, 2,            // arbitrary sequence ID
            1, 1,            // arbitrary command class and commamd
            0x01, 0x02, 0x03, 0x04, // return code
            1, 1, 1, 1,      // arbitrary data
            1, 1, 1, 1       // arbitrary data
        };

        TS_TRACE("ffdcParserTest test 3 - 1 package, 2 word data");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data);

        l_num = l_ffdc_parser.getTotalPackages();
        if(l_num != 1)
        {
            TS_FAIL("ffdcParserTest test 3 FAILED: 1 expected, got %d", l_num);
            testPassed = false;
        }
        else
        {
            for(size_t i=0; i<l_num; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 16909060)
                {
                    TS_FAIL("ffdcParserTest test 3 FAILED RC: expect 16909060, got %d", l_rc);
                    testPassed = false;
                }
            }
        }

        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 3 - 1 package, 2 word data PASSED");
        }
    }

    /**
     *  @brief Test with valid magic byte, 2 package
     */
    void testSBEFFDC4(void)
    {
        bool testPassed = true;
        size_t l_num = 0;
        uint8_t data[36] = {
            0xff, 0xdc,       // magic byte
            0, 5,             // package length
            0, 2,             // arbitrary sequence ID
            1, 1,             // arbitrary command class and commamd
            0x02, 0x03, 0x04, 0x05, // return code
            1, 1, 1, 1,       // arbitrary data
            1, 1, 1, 1,
            0xff, 0xdc,       // package 2
            0, 4,             // length of 1 word + 6
            0, 2,             // arbitrary sequence ID
            1, 1,             // arbitrary command class and commamd
            0x02, 0x03, 0x04, 0x05, // return code
            2, 2, 2, 2
        };

        TS_TRACE("ffdcParserTest test 4 - 2 packages, 2 word data");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data);

        l_num = l_ffdc_parser.getTotalPackages();
        if(l_num != 2)
        {
            TS_FAIL("ffdcParserTest test 4 FAILED: 2 expected, got %d", l_num);
            testPassed = false;
        }
        else
        {
            for(size_t i=0; i<l_num; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 33752069)
                {
                    TS_FAIL("ffdcParserTest test 4 FAILED RC: expect 33752069, got %d", l_rc);
                    testPassed = false;
                }
            }
        }

        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 4 - 2 packages, 2 word data PASSED");
        }
    }
    /**
     *  @brief Test with valid magic byte, 2 package, 2nd magic byte is bad
     */
    void testSBEFFDC5(void)
    {
        bool testPassed = true;
        size_t l_num = 0;
        uint8_t data[40] = {
            0xff, 0xdc,        // magic byte
            0, 6,              // package length
            0, 2,              // arbitrary sequence ID
            1, 1,              // arbitrary command class and commamd
            0x04, 0x05, 0x06, 0x07, // return code
            1, 1, 1, 1,        // arbitrary data
            1, 1, 1, 1,
            1, 1, 1, 1,
            0xdc, 0xdc,        // package 2 - bad magic byte
            0, 7,              // length of 1 word + 6
            0, 2,              // arbitrary sequence ID
            1, 1,              // arbitrary command class and commamd
            0x05, 0x06, 0x07, 0x08, // return code
            1, 1, 1, 1         // arbitrary data
        };

        TS_TRACE("ffdcParserTest test 5 - 2 packages, bad 2nd magic byte");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data);
        l_num = l_ffdc_parser.getTotalPackages();
        if(l_num != 1)
        {
            TS_FAIL("ffdcParserTest test 5 FAILED: 1 expected, got %d", l_num);
            testPassed = false;
        }
        else
        {
            for(size_t i=0; i<l_num; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 0x04050607)
                {
                    TS_FAIL("ffdcParserTest test 5 FAIL RC: 0x04050607, got 0%0.8X", l_rc);
                    testPassed = false;
                }
            }
        }

        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 5 - 2 packages, bad 2nd magic byte PASSED");
        }
    }

    /**
     * @brief Test with valid ODYSSEY magic byte.
     */
    void testSBEFFDC6()
    {
        bool testPassed = true;
        size_t l_numPackages = 0;
        std::vector<uint32_t> data = {
            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00000001,        // reserved fields and arbitrary chipid
            0x04050607,        // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
        };

        TS_TRACE("ffdcParserTest test 6 - 1 ODYSSEY package");

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data[0]);
        l_numPackages = l_ffdc_parser.getTotalPackages();
        if(l_numPackages != 1)
        {
            TS_FAIL("ffdcParserTest test 6 FAILED: 1 expected, got %d", l_numPackages);
            testPassed = false;
        }
        else
        {
            for(size_t i = 0; i < l_numPackages; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 0x04050607)
                {
                    TS_FAIL("ffdcParserTest test 6 FAIL RC: 0x04050607, got 0%0.8X", l_rc);
                    testPassed = false;
                }
            }
        }
        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 6 - 1 ODYSSEY package PASSED");
        }

    }

    /**
     * @brief Test an FFDC package overflow scenario. This test will also implicitly verify that strict weak ordering is
     *        adhered to in the sorting of the packages. If strict weak ordering is not followed, this test will crash
     *        and the printk backtrace for the task running this test will be full of infinite recursion traces.
     */
    void testSBEFFDC7()
    {
        bool testPassed = true;
        size_t l_numPackages = 0, l_totalNumPackages = 0;
        std::vector<uint32_t> odyPackage = {
            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00000001,        // reserved fields and arbitrary chipid
            0x04050607,        // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
        };

        // Create a vector of data which is large enough to cause a buffer overflow.
        std::vector<uint32_t> data;
        while (data.size() < (((PAGESIZE * SBEIO::SBE_FFDC_MAX_PAGES) / sizeof(uint32_t))
                    + odyPackage.size()))
        {
            data.insert(data.end(), odyPackage.begin(), odyPackage.end());
            l_totalNumPackages++;
        }

        TS_TRACE("ffdcParserTest test 7 - %d ODYSSEY packages which overflows the package buffer by 1",
                 l_totalNumPackages);

        SBEIO::SbeFFDCParser l_ffdc_parser;
        l_ffdc_parser.parseFFDCData(&data[0]);
        l_numPackages = l_ffdc_parser.getTotalPackages();
        if((l_numPackages + 1) != l_totalNumPackages)
        {
            TS_FAIL("ffdcParserTest test 7 FAILED:  Buffer should have overrun, expected %d: got %d.",
                    l_totalNumPackages - 1, // Should have overrun max size by 1, and returned total-1
                    l_numPackages);
            testPassed = false;
        }
        else
        {
            for(size_t i = 0; i < l_numPackages; i++)
            {
                uint32_t l_rc = l_ffdc_parser.getPackageRC(i);
                if(l_rc != 0x04050607)
                {
                    TS_FAIL("ffdcParserTest test 7 FAIL Expected RC: 0x04050607, got 0%0.8X for package %d/%d",
                            l_rc,
                            i,
                            l_numPackages);
                    testPassed = false;
                }
            }
        }
        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 7 PASSED");
        }
    }

    /*
     * Test that multiple Odyssey packages with different SLIDs are sorted by during parsing. The ordering is by SLID
     * then among packages with the same SLID, HWP RC < PLID < 0. This test also verifies that the parsing logic is
     * smart enough to tell that SLIDs and Severities are present.
     */
    void testSBEFFDC8()
    {
        struct expectedResults
        {
            uint16_t slid;
            uint32_t rc;
            ERRORLOG::errlSeverity_t sev;

            expectedResults(uint16_t i_slid,
                            uint32_t i_rc,
                            ERRORLOG::errlSeverity_t i_sev)
                            : slid(i_slid),
                              rc(i_rc),
                              sev(i_sev) {};
        };

        uint32_t PLAT_RC = fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA, HWP_RC = 0x04050607, BAD_RC = 0;

        // The packages will be sorted so make the expected list in sorted order.
        // It is required that severity is the same for all packages that have a matching SLID.
        std::vector<expectedResults> expected;
        expected.push_back({0x1, HWP_RC,  ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x1, PLAT_RC, ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x2, HWP_RC,  ERRORLOG::ERRL_SEV_PREDICTIVE});
        expected.push_back({0x3, HWP_RC,  ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x3, PLAT_RC, ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x3, BAD_RC,  ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x4, HWP_RC,  ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x4, PLAT_RC, ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x4, PLAT_RC, ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x5, HWP_RC,  ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x5, PLAT_RC, ERRORLOG::ERRL_SEV_RECOVERED});
        expected.push_back({0x5, BAD_RC,  ERRORLOG::ERRL_SEV_RECOVERED});

        bool testPassed = true;
        // A vector of thoughtfully scrambled data.
        // Test number = SLID
        // P = PLAT RC, H = HWP RC, 0 = BAD RC
        // Initial RC orders for each test, see above expected vector for correct order.
        // 1: HP
        // 2: H
        // 3: PH0
        // 4: HPP
        // 5: 0HP
        // The SLIDs have been mixed so that the relative RC order within the same SLID stays the same but the packages
        // aren't already in SLID order.
        std::vector<uint32_t> odyPackage = {

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00031001,        // SLID, errlSeverity_t, and arbitrary chipid
            PLAT_RC,           // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00011001,        // SLID, errlSeverity_t, and arbitrary chipid
            HWP_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00022001,        // SLID, errlSeverity_t, and arbitrary chipid
            HWP_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00041001,        // SLID, errlSeverity_t, and arbitrary chipid
            HWP_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00011001,        // SLID, errlSeverity_t, and arbitrary chipid
            PLAT_RC,           // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00031001,        // SLID, errlSeverity_t, and arbitrary chipid
            HWP_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00031001,        // SLID, errlSeverity_t, and arbitrary chipid
            BAD_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00051001,        // SLID, errlSeverity_t, and arbitrary chipid
            BAD_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00041001,        // SLID, errlSeverity_t, and arbitrary chipid
            PLAT_RC,           // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0006,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00051001,        // SLID, errlSeverity_t, and arbitrary chipid
            HWP_RC,            // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00041001,        // SLID, errlSeverity_t, and arbitrary chipid
            PLAT_RC,           // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

            0xFBAD0008,        // magic byte + package length
            0x00020101,        // arbitrary sequence ID, command class, and command
            0x00051001,        // SLID, errlSeverity_t, and arbitrary chipid
            PLAT_RC,           // return code
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data
            0xDEADC0DE,        // arbitrary FFDC data

        };

        SBEIO::SbeFFDCParser ffdcParser;
        ffdcParser.parseFFDCData(&odyPackage[0]);
        size_t numPackages = ffdcParser.getTotalPackages();
        if (numPackages != expected.size())
        {
            TS_FAIL("ffdcParserTest test 8 FAIL expected %d packages, got %d", expected.size(), numPackages);
            testPassed = false;
            goto TEST_EXIT;
        }

        for (size_t i = 0; i < numPackages; ++i)
        {
            if (ffdcParser.getPackageSlid(i) != expected[i].slid)
            {
                TS_FAIL("ffdcParserTest test 8: FAIL Package %d/%d SLID %d didn't match expected SLID %d",
                        i+1,
                        numPackages,
                        ffdcParser.getPackageSlid(i),
                        expected[i].slid);
                testPassed = false;
            }
            else if (ffdcParser.getPackageSeverity(i) != expected[i].sev)
            {
                TS_FAIL("ffdcParserTest test 8: FAIL Package %d/%d Severity 0x%X didn't match expected 0x%X",
                        i+1,
                        numPackages,
                        ffdcParser.getPackageSeverity(i),
                        expected[i].sev);
                testPassed = false;
            }
            else if (ffdcParser.getPackageRC(i) != expected[i].rc)
            {
                TS_FAIL("ffdcParserTest test 8: FAIL Package %d/%d RC 0x%X didn't match expected 0x%X",
                        i+1,
                        numPackages,
                        ffdcParser.getPackageRC(i),
                        expected[i].rc);
                testPassed = false;
            }
        }
        if (testPassed)
        {
            TS_TRACE("ffdcParserTest test 8 PASSED");
        }

TEST_EXIT:
    return;
    }
};

#endif
