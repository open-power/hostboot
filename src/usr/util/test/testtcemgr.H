/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/testtcemgr.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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

#ifndef __TEST_TCETEST_H
#define __TEST_TCETEST_H

/**
 *  @file tcetest.H
 *
 */

#include <cxxtest/TestSuite.H>

#include <errl/errlmanager.H>
#include <targeting/common/commontargeting.H>
#include <util/utiltce.H>
#include <util/util_reasoncodes.H>
#include "../utiltcemgr.H"

extern trace_desc_t* g_trac_tce;

// ------------------------
// Macros for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

class TCETest: public CxxTest::TestSuite
{
  public:

    // This helper functions retrieves the private member variable
    // iv_allocatedAddrs from the Singleton UtilTceMgr class
    std::map<uint32_t, TCE::TceEntryInfo_t> getAllocatedAddrsMap(void)
    {
        std::map<uint32_t, TCE::TceEntryInfo_t> o_map(TCE::getTceManager().iv_allocatedAddrs);
        return o_map;
    };


    void testTCE(void)
    {
        TRACFCOMP( g_trac_tce, ENTER_MRK"testTCE> start" );

        errlHndl_t errhdl = nullptr;

        uint64_t fails = 0x0;
        uint64_t total = 0x0;


        // Call before running test loop
        TRACFCOMP( g_trac_tce,"testTCE> Calling TCE::utilEnableTcesWithoutTceTable");
        ++total;
        errhdl = TCE::utilEnableTcesWithoutTceTable();
        if (errhdl != nullptr)
        {
            TRACUCOMP(g_trac_tce,ERR_MRK"testTCE> "
                      "TCE::utilEnableTcesWithoutTceTable returned unexpected "
                      "error: rc=0x%X, plid=0x%X",
                      ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> TCE::utilEnableTcesWithoutTceTable returned "
                    "unexpected error: rc=0x%X, plid=0x%X",
                    ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        // NOTE: Not calling utilSetupPayloadTces() and utilClosePayloadTces()
        // because they open/close SBEIO memRegions and that could interfere
        // with the SBEIO memRegions testcases.

        // Create testData[] structure to then loop on
        struct
        {
            bool func;       // Function: false=deallocate; true=allocate
            uint64_t addr;
            size_t   size;
            uint32_t token;
            uint16_t err_rc; // expected reason code (0x0=no error expected)
        } testData[] =
        {
            { true, //T0
                PAGESIZE+1,
                  PAGESIZE,
                    0x0,
                      Util::UTIL_TCE_ADDR_NOT_ALIGNED},
            { true, //T1
               PAGESIZE,
                 (TCE::UtilTceMgr::MAX_NUM_TCE_TABLE_ENTRIES+1)*PAGESIZE,
                   0x0,
                     Util::UTIL_TCE_INVALID_SIZE},
            { true, //T2
               0x0000000004010000,
                 16*PAGESIZE,
                   0x0,
                     0x0},
            { true, //T3
               0x0000000004800000,
                 50*PAGESIZE,
                   16*PAGESIZE,
                     0x0},
            { true, //T4
               0x0000000004800000,
                 50*PAGESIZE,
                   16*PAGESIZE,
                     Util::UTIL_TCE_PREVIOUSLY_ALLOCATED},
            { true, //T5
                PAGESIZE,
                  TCE::UtilTceMgr::MAX_NUM_TCE_TABLE_ENTRIES*PAGESIZE,
                    0x0,
                      Util::UTIL_TCE_NOT_ENOUGH_FREE_ENTRIES},
            { false, //T6
                0x0,
                  0x0,
                    0x0,  // deallocate of T2
                      0x0},
            { true, //T7
                0x0000000004020000,
                  10*PAGESIZE,
                    0x0, // Into gap created by T6
                      0x0},
            { true, //T8
                0x0000000005010000,
                  20*PAGESIZE,
                    66*PAGESIZE, // Skipping gap created by T6
                      0x0},
           { true, //T9
               0x0000000006010000,
                 6*PAGESIZE,
                   10*PAGESIZE, // Also into gap created by T6
                     0x0},
            { false, //T10
                0x0,
                  0x0,
                    66*PAGESIZE,  // deallocate of T8
                      0x0},
            { false, //T11
                0x0,
                  0x0,
                    10*PAGESIZE,  // deallocate of T9
                      0x0},
            { false, //T12
                0x0,
                  0x0,
                    0x0,  // deallocate of T7
                      0x0},
            { false, //T14
                0x0,
                  0x0,
                    16*PAGESIZE,  // deallocate of T3
                      0x0},

        };
        const size_t NUM_CMDS = sizeof(testData)/sizeof(testData[0]);

        // Test Loop over testData[]
        for (size_t i=0; i < NUM_CMDS; i++)
        {
            uint32_t l_token = 0;

            ++total;
            // Make function call
            if (testData[i].func)
            {
                errhdl = TCE::utilAllocateTces(testData[i].addr,
                                               testData[i].size,
                                               l_token);
            }
            else
            {
                errhdl = TCE::utilDeallocateTces(testData[i].token);
            }

            // Check error returnCode
            if (ERRL_GETRC_SAFE(errhdl) == testData[i].err_rc)
            {
                // Success: got expected error back
                TRACFCOMP(g_trac_tce,"testTCE> T%d: Got Expected Result back "
                          "from %s: rc=0x%X (Expected: addr=0x%.16llX, "
                          "size=0x%.8X, token=0x%.8X, err_rc=0x%X)",
                          i, testData[i].func ? "TCE::utilAllocateTces" :
                          "TCE::utilDeallocateTces", ERRL_GETRC_SAFE(errhdl),
                          testData[i].addr, testData[i].size,
                          testData[i].token, testData[i].err_rc);

                // Cleanup, if necessary 
                if (errhdl)
                {
                    delete errhdl;
                    errhdl = nullptr;
                }
            }
            else
            {
                // Fail: got unexpected error back
                ++fails;
                TS_FAIL("testTCE> T%d: FAIL: Got Unexpected Result back from "
                        "%s: rc=0x%X (addr=0x%.16llX, size=0x%.8X, "
                        "token=0x%.8X, err_rc=0x%X)",
                        i, testData[i].func ? "TCE::utilAllocateTces" :
                        "TCE::utilDeallocateTces", ERRL_GETRC_SAFE(errhdl),
                        testData[i].addr, testData[i].size,
                        testData[i].token, testData[i].err_rc);

                // Commit Log if there is one
                if (errhdl)
                {
                    errlCommit(errhdl,UTIL_COMP_ID);
                }
            }

            // Check that successful TCE allocation returned the correct token
            if ((testData[i].func  == true) &&
                (testData[i].err_rc == 0x0) &&
                (testData[i].token != l_token))
            {
                // Report fail but keep going
                ++fails;
                TS_FAIL("testTCE> T%d: FAIL: Got Unexpected TOKEN back from "
                        "TCE::utilAllocateTces: l_token=0x%.8X (addr=0x%.16llX,"
                        " size=0x%.8X, token=0x%.8X, err_rc=0x%X)",
                        i, l_token, testData[i].addr, testData[i].size,
                        testData[i].token, testData[i].err_rc);
            }

        } // end of Test Loop over testData[]

        // After testloop no entries should remain
        std::map<uint32_t, TCE::TceEntryInfo_t> l_map = getAllocatedAddrsMap();
        ++total;
        if (l_map.size() != 0 )
        {
            TS_FAIL("testTCE> Unexpected sizeof l_map=%d (should be zero)", l_map.size());
            ++fails;
        }
        else
        {
            TRACUCOMP( g_trac_tce,"testTCE> After loop expected sizeof l_map=%d was found", l_map.size());
        }

        // Disable TCEs before finishing test
        TRACFCOMP( g_trac_tce,"testTCE> Calling TCE::utilDisableTces");
        ++total;
        errhdl = TCE::utilDisableTces();

        if (errhdl != nullptr)
        {
            TS_FAIL("testTCE> TCE::utilDisableTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        TRACFCOMP(g_trac_tce, EXIT_MRK"testTCE> complete - %d/%d fails", fails, total);
    }

};
#endif
