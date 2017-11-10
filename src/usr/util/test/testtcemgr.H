/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/testtcemgr.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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


class TCETest: public CxxTest::TestSuite
{
  public:

// TODO RTC 168745 - reenable helper functions
#if 0

    // This helper functions retrieves the private member variable
    // iv_allocatedAddrs from the Singleton UtilTceMgr class
    std::map<uint64_t, uint32_t> getAllocatedAddrsMap(void)
    {
        std::map<uint64_t, uint32_t> o_map(TCE::getTceManager().iv_allocatedAddrs);
        return o_map;
    };


    // This helper function looks for the position associated with the input
    // address in the Singleton's UtilTceMgr::iv_allocatedAddrs
    uint32_t getPos(uint64_t i_addr)
    {
        uint32_t o_pos = 0xFEFEFEFE; // Default for no position found

        auto map = getAllocatedAddrsMap();

        TRACDCOMP(g_trac_tce,ENTER_MRK"TCETest::getPos: i_addr=0x%llX, map.size=%d", i_addr, map.size());

        // Debug-only loop
        for (auto mapElement : map )
        {
            TRACDCOMP(g_trac_tce,"TCETest::getPos: printIvMap: addr=0x%llX, pos=0x%X", mapElement.first, mapElement.second);
        }

        // Find i_addr in map; otherwise o_pos = bad default from above
        auto map_itr = map.find(i_addr);
        if (map_itr != map.end())
        {
            o_pos = map_itr->second;
        }

        TRACDCOMP(g_trac_tce,EXIT_MRK"TCETest::getPos: i_addr=0x%llX, o_pos=0x%X", i_addr, o_pos);

        return o_pos;
    }
#endif


    void testTCE(void)
    {
// TODO RTC 168745 - reenable testcase
#if 0

        TRACFCOMP( g_trac_tce, ENTER_MRK"testTCE> start" );

        errlHndl_t errhdl = nullptr;

        uint64_t fails = 0x0;
        uint64_t total = 0x0;

        struct
        {
            uint64_t addr;  // Start address that TCEs Map To
            uint64_t size;  // Size of memory that TCEs Map To
            uint32_t pos;  // Starting Entry Position in TCE Table
        } testData[] =
        {
           { 0x00,     16*PAGESIZE, 0x0},
           { 0x0000000004000000, PAGESIZE*8,  0x10},
           { 0x0000000004010000, PAGESIZE*16, 0x18},
           { 0x0000000004800000, PAGESIZE*50, 0x28},
           { 0x0000000004020000, PAGESIZE*10, 0x18},
           { 0x0000000005010000, PAGESIZE*20, 0x5A},
           { 0x0000000006010000, PAGESIZE*6,  0x22},
        };


        //---------------------------------------------------
        // TEST 1 - Call Allocate with unaligned addr
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilAllocateTces(PAGESIZE+1, PAGESIZE);

        if (errhdl == nullptr)
        {
            TRACFCOMP( g_trac_tce,"testTCE> T1:  Did not get expected error from utilAllocateTces");
            TS_FAIL("testTCE> T1: Did not get expected error back from utilAllocateTces.");
            ++fails;
        }
        else if ( ERRL_GETRC_SAFE(errhdl) == Util::UTIL_TCE_ADDR_NOT_ALIGNED )
        {
            TRACFCOMP( g_trac_tce,"testTCE> T1: Got expected error unaligned addr back from utilAllocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            delete errhdl;
            errhdl = nullptr;
        }
        else
        {
            TRACFCOMP( g_trac_tce,"testTCE> T1: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X (expected rc=0x%X)", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl), Util::UTIL_TCE_ADDR_NOT_ALIGNED);
            TS_FAIL("testTCE> T1: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X (expected rc=0x%X)", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl), Util::UTIL_TCE_ADDR_NOT_ALIGNED);
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }


        //---------------------------------------------------
        // TEST 2 - Call create with aligned addr with large size
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilAllocateTces(PAGESIZE, 520*KILOBYTE*PAGESIZE);

        if (errhdl == nullptr)
        {
            TRACFCOMP( g_trac_tce,"testTCE> T2:  Did not get expected error from utilAllocateTces");
            TS_FAIL("testTcE> T2: Did not get expected error back from utilAllocateTces.");
            ++fails;
        }
        else if ( ERRL_GETRC_SAFE(errhdl) == Util::UTIL_TCE_INVALID_SIZE )
        {
            TRACFCOMP( g_trac_tce,"testTCE> T2: Got expected error of invalid size back from utilAllocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            delete errhdl;
            errhdl = nullptr;
        }
        else
        {
            TRACFCOMP( g_trac_tce,"testTCE> T2: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X (expected rc=0x%X)", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl), Util::UTIL_TCE_ADDR_NOT_ALIGNED);
            TS_FAIL("testTCE> T2: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X (expected rc=0x%X)", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl), Util::UTIL_TCE_INVALID_SIZE);
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        //---------------------------------------------------
        // TEST 3 - Four allocate calls
        // - init will be called under the covers for the first test
        //---------------------------------------------------
        for ( size_t i = 0; i <= 3; ++i )
        {
            ++total;
            errhdl = TCE::utilAllocateTces(testData[i].addr, testData[i].size);

            if (errhdl != nullptr)
            {
                TRACFCOMP( g_trac_tce,"testTCE> T3-%d: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", i, ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
                TS_FAIL("testTCE> T3-%d: got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", i, ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
                errlCommit(errhdl,UTIL_COMP_ID);
                ++fails;
            }
            else if (testData[i].pos !=
                     getPos(testData[i].addr))
            {
                TRACFCOMP( g_trac_tce,"testTCE> T3-%d: From TCE::utilAllocateTces testData[0].pos=0x%X !=  map-pos=0x%X", i, testData[i].pos, getPos(testData[i].addr));
                TS_FAIL("testTCE> T3-%d: From TCE::utilAllocateTces testData[0].pos !=  map-pos", i);
                ++fails;
            }
        }

        //---------------------------------------------------
        // TEST 4 - Deallocate token with 16 pages from above
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilDeallocateTces(testData[2].addr, testData[2].size);

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce, "testTCE> T4:  Got unexpected error back from TCE::utilDeallocateTces(testData[2].addr=0x%X, testData[2].size=0x%X: error rc=0x%X, plid=0x%X ", testData[2].addr, testData[2].size, ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T4: Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }


        //---------------------------------------------------
        // TEST 5: Two Allocates:
        // 1) Allocate 10 pages to go into the available slot left by the
        //    previous deallocate
        // 2) Allocate 20 pages that will skip past some available slots
        //    left by the previous deallocate
        //---------------------------------------------------
        for ( size_t i = 0; i <= 1; ++i )
        {
            ++total;
            errhdl = TCE::utilAllocateTces(testData[i+4].addr, testData[i+4].size);

            if (errhdl != nullptr)
            {
                TRACFCOMP( g_trac_tce, "testTCE> T5-%d:  Got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", i, ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
                TS_FAIL("testTCE> T5-%d: Got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", i, ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
                errlCommit(errhdl,UTIL_COMP_ID);
                ++fails;
            }
            else if (testData[i+4].pos !=
                     getPos(testData[i+4].addr))
            {
                TRACFCOMP( g_trac_tce,"testTCE> T5-%d: From TCE::utilAllocateTces testData[%d].pos=0x%X !=  map-pos=0x%X", i, i+4, testData[i+4].pos, getPos(testData[i+4].addr));
                TS_FAIL("testTCE> T5-%d: From TCE::utilAllocateTces testData[%d].pos !=  map-pos", i, i+4);
                ++fails;
            }
        }

        //---------------------------------------------------
        // TEST 6 Allocate 6 pages which should go into the 6
        //        slots available from the 16 page deallocate
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilAllocateTces(testData[6].addr, testData[6].size);

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> T6:  Got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T6: Got unexpected error back from TCE::utilAllocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }
        else if (testData[6].pos !=
                 getPos(testData[6].addr))
        {
            TRACFCOMP( g_trac_tce,"testTCE> T6: From TCE::utilAllocateTces testData[6].pos=0x%X !=  map-pos=0x%X", testData[6].pos, getPos(testData[6].addr));
            TS_FAIL("testTCE> T6: From TCE::utilAllocateTces testData[6].pos !=  map-pos");
            ++fails;
        }

        //---------------------------------------------------
        // TEST 7 Deallocate 20 pages from above
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilDeallocateTces(testData[5].addr, testData[5].size);
        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> T7:  Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T7: Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        //---------------------------------------------------
        // TEST 8 Deallocate 10 pages from above
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilDeallocateTces(testData[4].addr, testData[4].size);

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> T8: Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T8: Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }


        //---------------------------------------------------
        // TEST 9 Deallocate Too large of size.   No error returned instead the
        // code should go to end of the TCE table and commit errorlog and return
        //---------------------------------------------------
        ++total;
        errhdl = TCE::utilDeallocateTces(0x0,  (520*KILOBYTE*PAGESIZE));

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> T9:  Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T9: Got unexpected error back from TCE::utilDeallocateTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        //---------------------------------------------------
        // TEST 10 disable TCEs, which should deallocate all existing TCEs
        //---------------------------------------------------
        TRACFCOMP( g_trac_tce,"testTCE> 10: Calling TCE::utilDisableTces");
        ++total;
        errhdl = TCE::utilDisableTces();

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> 10: Got unexpected error back from TCE::utilDisableTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> T10: Got unexpected error back from TCE::utilDisableTces: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }


        /************************************************************/
        /* @TODO RTC 168745:                                        */
        /* Make The PAYLOAD calls here in the testcase for now      */
        /* Consider removing when when part of the IPL              */
        /************************************************************/

        TRACFCOMP( g_trac_tce,"testTCE> TA: Calling TCE::utilSetupPayloadTces");
        ++total;
        errhdl = TCE::utilSetupPayloadTces();

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> TA: TCE::utilSetupPayloadTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> TA: TCE::utilSetupPayloadTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        TRACFCOMP( g_trac_tce,"testTCE> TB: Calling TCE::utilClosePayloadTces");
        ++total;
        errhdl = TCE::utilClosePayloadTces();

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> TB:  TCE::utilClosePayloadTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> TB: TCE::utilClosePayloadTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        TRACFCOMP( g_trac_tce,"testTCE> TC: Calling TCE::utilDisableTces");
        ++total;
        errhdl = TCE::utilDisableTces();

        if (errhdl != nullptr)
        {
            TRACFCOMP( g_trac_tce,ERR_MRK"testTCE> TC:  TCE::utilDisableTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            TS_FAIL("testTCE> TC: TCE::utilDisableTces returned unexpected error: rc=0x%X, plid=0x%X", ERRL_GETRC_SAFE(errhdl), ERRL_GETPLID_SAFE(errhdl));
            errlCommit(errhdl,UTIL_COMP_ID);
            ++fails;
        }

        TRACFCOMP(g_trac_tce, EXIT_MRK"testTCE> complete - %d/%d fails", fails, total);
#endif
    }

};
#endif
