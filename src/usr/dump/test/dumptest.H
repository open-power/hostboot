/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/dump/test/dumptest.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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

#ifndef __DUMPTEST_H
#define __DUMPTEST_H

/**
 *  @file dumptest.H
 *
 *  @brief Test case for dump code
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>
#include <targeting/common/util.H>
#include <runtime/runtime.H>
#include <sys/mm.h>
#include <util/align.H>
#include <sys/mm.h>
#include <dump/dumpif.H>
#include <vfs/vfs.H>
#include "../dumpCollect.H"

extern trace_desc_t* g_trac_dump;

class DumpTest: public CxxTest::TestSuite
{
  public:

    // Load the dump module as it is loaded on demand
    DumpTest(): CxxTest::TestSuite()
    {
        errlHndl_t l_err = VFS::module_load( "libdump.so" );

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:DumpTest> got an error back from moduleLoad : RC=%X",l_err->reasonCode() );
            TS_FAIL( "DumpTest::DumpTest ERROR : Unexpected error log from moduleLoad" );
            errlCommit(l_err,DUMP_COMP_ID);

        }
    };

     // unload the dump module
    ~DumpTest()
    {
        // Need to unload the dump module regardless of whether we have
        // an error or not.
        errlHndl_t l_err = VFS::module_unload( "libdump.so" );

        if (l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:~DumpTest> got an error back from moduleUnLoad : RC=%X",l_err->reasonCode() );
            TS_FAIL( "DumpTest::DumpTest ERROR : Unexpected error log from moduleUnLoad" );
            errlCommit(l_err,DUMP_COMP_ID);

        }
    };

    /**
     * @brief Basic dump test that has sequential src addresses to
     *   equivalent destination locations and sizes.
     *
     */

    void test_DumpCollect(void)
    {

        TRACFCOMP( g_trac_dump, "DumpTest::test_dumpCollect START" );

        errlHndl_t l_err = NULL;

        uint64_t srcTableSize = 0;
        uint64_t dstTableSize = 0;
        uint64_t resultsTableSize = 0;

        DUMP::dumpEntry *srcTable = NULL;
        DUMP::dumpEntry *destTable = NULL;
        DUMP::resultsEntry *resultsTable = NULL;

        // For testing I am using my own data pointers and setting it up
        // to look like PHYP would have to test the copy function.
        l_err = DUMP::getHostDataPtrs(srcTable, srcTableSize,
                                      destTable, dstTableSize,
                                      resultsTable, resultsTableSize);
        if(l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> error getting getHostDataPtrs: RC=%X"
                      ,l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDump ERROR : Failed getHostDataPtrs" );
            errlCommit(l_err,DUMP_COMP_ID);
            return;
        }

        // Point to the location of the src Data pointer.
        // Point to the location of the dest Data pointer.
        uint64_t *srcTablePtr = reinterpret_cast<uint64_t *>(srcTable);
        uint64_t *dstTablePtr = reinterpret_cast<uint64_t *>(destTable);
        uint64_t *resultTablePtr = reinterpret_cast<uint64_t *>(resultsTable);

        uint64_t src_data[8] = {DUMP_TEST_SRC_DATA_AREA, 64,  // 450000
                                DUMP_TEST_SRC_DATA_AREA + 64, 64,
                                (0x8000000000000000 | DUMP_TEST_SRC_DATA_AREA)
                                                      + 192, 64,
                                DUMP_TEST_SRC_DATA_AREA + 256, 64};


        uint64_t dst_data[8] = {DUMP_TEST_DST_DATA_AREA, 64,   // 460000
                                (0x8000000000000000 | DUMP_TEST_DST_DATA_AREA)
                                                      + 64, 64,
                                DUMP_TEST_DST_DATA_AREA + 256, 64,
                                DUMP_TEST_DST_DATA_AREA + 512, 64};


        // Put the src addresses defined above into the MDST
        memcpy(srcTablePtr, src_data, sizeof(src_data));

       // Put the src addresses defined above into the MDDT
        memcpy(dstTablePtr, dst_data, sizeof(dst_data));

        // Need to memory map
        uint64_t src_Inputdata[4][8] = {
                                 {0x1111111111111111, 0x1111111111111111,
                                  0x1111111111111111, 0x1111111111111111,
                                  0x1111111111111111, 0x1111111111111111,
                                  0x1111111111111111, 0x1111111111111111},

                                 {0x2222222222222222, 0x2222222222222222,
                                  0x2222222222222222, 0x2222222222222222,
                                  0x2222222222222222, 0x2222222222222222,
                                  0x2222222222222222, 0x2222222222222222},

                                 {0x3333333333333333, 0x3333333333333333,
                                  0x3333333333333333, 0x3333333333333333,
                                  0x3333333333333333, 0x3333333333333333,
                                  0x3333333333333333, 0x3333333333333333},

                                 {0x4444444444444444, 0x4444444444444444,
                                  0x4444444444444444, 0x4444444444444444,
                                  0x4444444444444444, 0x4444444444444444,
                                  0x4444444444444444, 0x4444444444444444}
        };


        // results output data expected
        uint64_t result_data[] = {
            0x8000000000000000|DUMP_TEST_SRC_DATA_AREA,
            0x8000000000000000|DUMP_TEST_DST_DATA_AREA,
            64, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA) +64,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA) +64,
            64, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+192,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+256,
            64, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+512,
            64, 0,
        };

        uint64_t *va_mapsrcTableAddr = 0;
        uint64_t *va_srcTableAddr = 0;
        uint64_t offset = 0;
        int index = 0;

        for (int i = 0; i<4; i++)
        {

            // Get the Va for the page aligned Physical address
            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_srcTableAddr = va_mapsrcTableAddr;

            // calculate offset based on page alignment.
            offset = src_data[index] - ALIGN_PAGE_DOWN(src_data[index]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_Inputdata[i], sizeof(src_Inputdata[i]));

            // unmap the previous src entry
            int rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> got an error back from unmap : RC=%X",rc);
               TS_FAIL( "DumpTest::CollectDump ERROR : BAD Rc from mm_block_unmap" );
               break;
            }
            index+=2;
        }

        l_err = DUMP::doDumpCollect();

        if( l_err )
        {
            TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> got an error back from dumpcollect : RC=%X",l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDump ERROR : Unexpected error log from dumpcollect" );
            errlCommit(l_err,DUMP_COMP_ID);
        }


        // Verify that the data and the VA mapping is correct.
        uint64_t *va_mapdestTableAddr = 0;
        uint64_t *va_destTableAddr = 0;
        offset = 0;
        index = 0;

        for (int i = 0; i<4; i++)
        {
            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            uint64_t paddr = mm_virt_to_phys(va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest:test_DumpCollect:1> mapping mismatch actual paddr = %lx, expected paddr = %lx", paddr, dst_data[index]);
                TS_FAIL( "DumpTest:test_DumpCollect:1 ERROR : Unexpected error physical address mismatch" );
            }


            // Check the destination table.
            int src_rc = memcmp(va_destTableAddr,src_Inputdata[i],sizeof(src_Inputdata[i]));

            if (src_rc!=0)
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollect:1 : Results Data mismatch rc = %d", src_rc);
                TS_FAIL( "DumpTest::DumpCollect ERROR : Unexpected error DATA mismatch in results" );
            }


            // Unmap the previous destination entry
            int rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollect got an error back from unmap : RC=%X",rc);
               TS_FAIL( "DumpTest::DumpCollect ERROR : BAD Rc from mm_block_unmap" );
               break;
            }
            index+=2;
        }

        // Ensure there is enough space to fit the real results
        if( resultsTableSize < sizeof(result_data) )
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::Allocated size (%d) is too small for results (%d)",
                      resultsTableSize, sizeof(result_data));
            TS_FAIL( "DumpTest::Allocated size is too small for results" );
        }
        else
        {
            // Check the results table.
            int result_rc = memcmp( resultTablePtr,
                                    result_data,
                                    sizeof(result_data) );

            if (result_rc!=0)
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollect:1 : Results Table mismatch rc = %d", result_rc);
                TRACFBIN( g_trac_dump, "MDRT=", resultTablePtr, sizeof(result_data) );
                TRACFBIN( g_trac_dump, "expected=", result_data, sizeof(result_data)  );
                TS_FAIL( "DumpTest::DumpCollect ERROR : Unexpected mismatch in results table" );
            }
        }

        TRACFCOMP( g_trac_dump, "DumpTest::DumpCollect COMPLETE" );

    }

    /**
     * @brief Basic dump test that has sequential src addresses to
     *   imbalanced destination locations and sizes.
     *
     */
    void test_DumpCollectUnevenDest(void)
    {

        TRACFCOMP( g_trac_dump, "DumpTest::DumpCollectUnevenDest START" );
        errlHndl_t l_err = NULL;
        uint64_t srcTableSize = 0;
        uint64_t dstTableSize = 0;
        uint64_t resultsTableSize = 0;

        DUMP::dumpEntry *srcTable = NULL;
        DUMP::dumpEntry *destTable = NULL;
        DUMP::resultsEntry *resultsTable = NULL;

        // For testing I am using my own data pointers and setting it up
        // to look like PHYP would have to test the copy function.
        l_err = DUMP::getHostDataPtrs(srcTable, srcTableSize,
                                      destTable, dstTableSize,
                                      resultsTable, resultsTableSize);
        if(l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> error getting getHostDataPtrs: RC=%X"
                      ,l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDump ERROR : Failed getHostDataPtrs" );
            errlCommit(l_err,DUMP_COMP_ID);
            return;
        }

        uint64_t *srcTablePtr = reinterpret_cast<uint64_t *>(srcTable);
        uint64_t *dstTablePtr = reinterpret_cast<uint64_t *>(destTable);
        uint64_t *resultTablePtr = reinterpret_cast<uint64_t *>(resultsTable);

        uint64_t src_data[8] = {DUMP_TEST_SRC_DATA_AREA+256, 64,      // 4500100
                                DUMP_TEST_SRC_DATA_AREA+256 + 64,64,  // 4500140
                                DUMP_TEST_SRC_DATA_AREA+256 + 128,64, // 4500180
                                DUMP_TEST_SRC_DATA_AREA+256 + 192, 64}; // 45001C0

        uint64_t dst_data[8] = {DUMP_TEST_DST_DATA_AREA+1024, 64,     //4600400
                             DUMP_TEST_DST_DATA_AREA+1024 + 64, 32,   //4600440
                             DUMP_TEST_DST_DATA_AREA+1024 + 256, 32,  //4600500
                             DUMP_TEST_DST_DATA_AREA+1024 + 128, 128};//4600520

        memcpy(srcTablePtr, src_data, sizeof(src_data));
        memcpy(dstTablePtr, dst_data, sizeof(dst_data));


        // Need to memory map
        uint64_t src_Inputdata[4][8] = {
                                        {0xaaaaaaaaaaaaaaaa, 0xaaaaaaaaaaaaaaaa,
                                         0xaaaaaaaaaaaaaaaa, 0xaaaaaaaaaaaaaaaa,
                                         0xaaaaaaaaaaaaaaaa, 0xaaaaaaaaaaaaaaaa,
                                         0xaaaaaaaaaaaaaaaa, 0xaaaaaaaaaaaaaaaa},

                                        {0xbbbbbbbbbbbbbbbb, 0xbbbbbbbbbbbbbbbb,
                                         0xbbbbbbbbbbbbbbbb, 0xbbbbbbbbbbbbbbbb,
                                         0xbbbbbbbbbbbbbbbb, 0xbbbbbbbbbbbbbbbb,
                                         0xbbbbbbbbbbbbbbbb, 0xbbbbbbbbbbbbbbbb},

                                        {0xcccccccccccccccc, 0xcccccccccccccccc,
                                         0xcccccccccccccccc, 0xcccccccccccccccc,
                                         0xcccccccccccccccc, 0xcccccccccccccccc,
                                         0xcccccccccccccccc, 0xcccccccccccccccc},

                                        {0xdddddddddddddddd, 0xdddddddddddddddd,
                                         0xdddddddddddddddd, 0xdddddddddddddddd,
                                         0xdddddddddddddddd, 0xdddddddddddddddd,
                                         0xdddddddddddddddd, 0xdddddddddddddddd},
        };

        // results output data expected
        uint64_t result_data[] = {
            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+1024, 64, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256+64,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+1024+64, 32, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256+64+32,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+1024+256, 32, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256+128,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+1024+128, 64, 0,

            (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+256+128+64,
            (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+1024+128+64, 64, 0,
        };

        uint64_t *va_mapsrcTableAddr = 0;
        uint64_t *va_srcTableAddr = 0;
        uint64_t offset = 0;
        int index = 0;

        for (int i = 0; i<4; i++)
        {
            // Get the Va for the page aligned Physical address
            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer
            va_srcTableAddr = va_mapsrcTableAddr;
            TS_INFO("UNEVENDEST 1 MAPPED SRC i=0x%X va_mapsrcTableAddr=0x%X "
                "va_srcTableAddr=0x%X",
                i, va_mapsrcTableAddr, va_srcTableAddr);

            // calculate offset based on page alignment.
            offset = src_data[index] - ALIGN_PAGE_DOWN(src_data[index]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));
            TS_INFO("UNEVENDEST UPDATED SRC OFFSET i=0x%X va_srcTableAddr=0x%X",
                i, va_srcTableAddr);

            memcpy(va_srcTableAddr, src_Inputdata[i], sizeof(src_Inputdata[i]));
            TRACFBIN( g_trac_dump, "UNEVENDEST SETUP memcpy "
                "from src_Inputdata[i] to va_srcTableAddr=",
                src_Inputdata[i], sizeof(src_Inputdata[i]) );

            // unmap the previous src entry
            TS_INFO("UNEVENDEST 1 UNMAPPING SRC i=0x%X va_mapsrcTableAddr=0x%X",
                i, va_mapsrcTableAddr);
            int rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollectUnevenDest> got an error back from unmap : RC=%X",rc);
               TS_FAIL( "DumpTest::CollectDumpUnevenDest ERROR : BAD Rc from mm_block_unmap" );
               break;
            }
            index+=2;
        }

        l_err = DUMP::doDumpCollect();

        if( l_err )
        {
            TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenDest got an error back from dumpcollect : RC=%X",l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDumpUnevenDest ERROR : Unexpected error log from dumpcollect" );
            errlCommit(l_err,DUMP_COMP_ID);
        }

        //----------------------------------------------------------------
        // !!!!! VERIFYING RESULTS
        // Verify that the data and the VA mapping is correct.
        //--------------------------------------------------------------
        do
        {

            uint64_t *va_mapdestTableAddr = 0;
            uint64_t *va_destTableAddr = 0;
            offset = 0;
            index = 0;

            int src_rc = 0;
            uint64_t paddr = 0;

            // Looping through the first 3 destinations
            for (int i = 0; i<3; i++)
            {

                // Get the Va for the page aligned Physical address
                va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                    mm_block_map(reinterpret_cast<void*>(
                                    ALIGN_PAGE_DOWN(dst_data[index])),
                                 PAGESIZE));

                // copy the mapped VA to a VA pointer we will
                va_destTableAddr = va_mapdestTableAddr;
                TS_INFO("UNEVENDEST 1 MAPPED DEST VERIFY i=0x%X "
                    "va_mapdestTableAddr=0x%X va_destTableAddr=0x%X",
                    i, va_mapdestTableAddr, va_destTableAddr);

                // calculate offset based on page alignment.
                offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

                // increment the offset to correct VA offset.
                va_destTableAddr += (offset/(sizeof (uint64_t)));
                TS_INFO("UNEVENDEST UPDATED DEST OFFSET i=0x%X "
                    "va_destTableAddr=0x%X",
                    i, va_destTableAddr);

                paddr = mm_virt_to_phys(va_destTableAddr);
                TS_INFO("UNEVENDEST index=0x%X paddr=0x%X dst_data[index]=0x%X",
                    index, paddr, dst_data[index]);

                if (paddr != dst_data[index])
                {
                    TRACFCOMP(g_trac_dump,
                              "DumpTest::DumpCollectUnevenDest:1> mapping mismatch actual paddr = %lx, expected paddr = %lx",
                               paddr, dst_data[index]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenDest ERROR : Unexpected error physical address mismatch" );
                }

                //if entry need to compare destination data to second portion of previous src
                TS_INFO("UNEVENDEST i=0x%X index=0x%X va_destTableAddr=0x%X"
                    " src_Inputdata[i]=0x%X &src_Inputdata[i]=0x%X "
                    "&src_Inputdata[1][4]=0x%X",
                    i, index, va_destTableAddr, src_Inputdata[i],
                    &src_Inputdata[i], &src_Inputdata[1][4]);
                TRACFBIN( g_trac_dump, "UNEVENDEST va_destTableAddr=",
                    va_destTableAddr, sizeof(va_destTableAddr) );
                TRACFBIN( g_trac_dump, "UNEVENDEST src_Inputdata[i]=",
                    src_Inputdata[i], sizeof(src_Inputdata[i]) );
                TRACFBIN( g_trac_dump, "UNEVENDEST src_Inputdata[1][4]=",
                    &src_Inputdata[1][4], sizeof(src_Inputdata[1][4]) );
                if (i == 2)
                {
                    src_rc = memcmp(va_destTableAddr, &src_Inputdata[1][4], dst_data[index+1]);
                }
                else
                {
                    // Check the destination table.
                    src_rc = memcmp(va_destTableAddr,src_Inputdata[i],dst_data[index+1]);
                }

                // If got a memcmp fail
                if (src_rc!=0)
                {
                    TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenDest:1 : Results Data mismatch rc = %d for index = %d", src_rc, i);
                    TS_FAIL( "DumpTest::DumpCollectUnevenDest ERROR : Unexpected error data mismatch in results data" );
                }


                // unmap the previous dest entry
                TS_INFO("UNEVENDEST UNMAPPING DEST VERIFY i=0x%X "
                    "va_mapdestTableAddr=0x%X",
                    i, va_mapdestTableAddr);
                int rc =
                  mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

                if (rc != 0)
                {
                    TRACFCOMP(g_trac_dump,
                              "DumpTest::DumpCollectUnevenDest got an error back from unmap : RC=%X",rc);
                    TS_FAIL( "DumpTest::DumpCollectUnevenDest ERROR : BAD Rc from mm_block_unmap" );
                    break;
                }
                index+=2;
            }


            // checking the 4th entry as it crosses through 2 source entries

            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;
            TS_INFO("UNEVENDEST MAPPED DEST 4th ENTRY CHECK "
                "va_mapdestTableAddr=0x%X va_destTableAddr=0x%X",
                va_mapdestTableAddr, va_destTableAddr);

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            paddr = mm_virt_to_phys(va_destTableAddr);
            TS_INFO("UNEVENDEST 4th ENTRY CHECK index 0x%X "
                "mm_virt_to_phys paddr=0x%X va_destTableAddr=0x%X",
                index, paddr, va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenDest:2> mapping mismatch actual paddr = %lx, expected paddr = %lx",
                          paddr, dst_data[index]);
                TS_FAIL( "DumpTest::DumpCollectUnevenDest:2 ERROR : Unexpected error physical address mismatch" );
            }

            int dataentries = (dst_data[index+1]/16);

            // start with 3rd src index..
            int i = 2;
            // Src Data input.
            int dataIndex = 0;

            // Now loop through the data at this memory address and compare it to the data
            for (int j = 0; j<dataentries; j++)
            {
                TS_INFO("UNEVENDEST WATCH i=0x%X j=0x%X dataIndex=0x%X "
                    "src_Inputdata[i]=0x%X &src_Inputdata[i][dataIndex]=0x%X "
                    "&va_destTableAddr[j]=0x%X",
                    i, j, dataIndex, src_Inputdata[i],
                    &src_Inputdata[i][dataIndex], &va_destTableAddr[j]);
                TRACFBIN( g_trac_dump, "UNEVENDEST src_Inputdata[i][dataIndex]=",
                    &src_Inputdata[i][dataIndex],
                    sizeof(src_Inputdata[i][dataIndex]) );
                TRACFBIN( g_trac_dump, "UNEVENDEST va_destTableAddr[j]=",
                    &va_destTableAddr[j], sizeof(va_destTableAddr[j]) );
                if (va_destTableAddr[j] != src_Inputdata[i][dataIndex])
                {
                    // error
                    TRACFCOMP(g_trac_dump,
                        "DumpTest::DumpCollectUnevenDest:3 : "
                        "WATCH Data mismatch input data = %lX "
                        "outputdata = %lx",
                        src_Inputdata[i][dataIndex],
                        va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenDest:3 ERROR : "
                        "Unexpected error data mismatch" );
                    break;
                }

                dataIndex++;

                if (j == 7)
                {
                    i++;
                    dataIndex = 0;
                }

            }


            // unmap the previous dest entry
            TS_INFO("UNEVENDEST UNMAPPING DEST 4th ENTRY CHECK "
                "va_mapdestTableAddr=0x%X",
                va_mapdestTableAddr);
            int rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenDest got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::CollectDumpUnevenDest ERROR : BAD Rc from mm_block_unmap" );
                break;
            }
            index+=2;

        }while(0);

        // Ensure there is enough space to fit the real results
        if( resultsTableSize < sizeof(result_data) )
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::Allocated size (%d) is too small for results (%d)",
                      resultsTableSize, sizeof(result_data));
            TS_FAIL( "DumpTest::Allocated size is too small for results" );
        }
        else
        {
            // Check the results table.
            int result_rc = memcmp( resultTablePtr,
                                    result_data,
                                    sizeof(result_data) );

            if (result_rc!=0)
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenDest : Results Table mismatch rc = %d", result_rc);
                TRACFBIN( g_trac_dump, "MDRT=", resultTablePtr, sizeof(result_data) );
                TRACFBIN( g_trac_dump, "expected=", result_data, sizeof(result_data)  );
                TS_FAIL( "DumpTest::DumpCollectUnevenDest ERROR : Unexpected error TABLE mismatch in results table" );
            }
        }


        TRACFCOMP( g_trac_dump, "dumpTest::test_dumpCollectUnevenDest COMPLETE" );
    }


    /**
     * @brief Basic dump test that has non sequential src addresses with varying
     *     sizes to non sequential destination locations and uneven src
     *
     */

    void test_DumpCollectUnevenSrc(void)
    {

        TRACFCOMP( g_trac_dump, "dumpTest::test_dumpCollectUnevenSrc START" );

        errlHndl_t l_err = NULL;

        uint64_t srcTableSize = 0;
        uint64_t dstTableSize = 0;
        uint64_t resultsTableSize = 0;
        uint64_t offset = 0;

        DUMP::dumpEntry *srcTable = NULL;
        DUMP::dumpEntry *destTable = NULL;
        DUMP::resultsEntry *resultsTable = NULL;

        // For testing I am using my own data pointers and setting it up
        // to look like PHYP would have to test the copy function.
        l_err = DUMP::getHostDataPtrs(srcTable, srcTableSize,
                                      destTable, dstTableSize,
                                      resultsTable, resultsTableSize);
        if(l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> error getting getHostDataPtrs: RC=%X"
                      ,l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDump ERROR : Failed getHostDataPtrs" );
            errlCommit(l_err,DUMP_COMP_ID);
            return;
        }

        uint64_t *srcTablePtr = reinterpret_cast<uint64_t *>(srcTable);
        uint64_t *dstTablePtr = reinterpret_cast<uint64_t *>(destTable);
        uint64_t *resultTablePtr = reinterpret_cast<uint64_t *>(resultsTable);

        uint64_t src_data[8] = {DUMP_TEST_SRC_DATA_AREA+1024, 16,   // 4500400
                                DUMP_TEST_SRC_DATA_AREA+2048, 48,   // 4500800
                                DUMP_TEST_SRC_DATA_AREA+3072, 32,   // 4500C00
                                DUMP_TEST_SRC_DATA_AREA+4096, 160}; // 4501000


        uint64_t dst_data[8] = {DUMP_TEST_DST_DATA_AREA+2048,     64,  // 4600800
                                DUMP_TEST_DST_DATA_AREA+2048+128, 32,  // 4600880
                                DUMP_TEST_DST_DATA_AREA+3072,     32,  // 4600C00
                                DUMP_TEST_DST_DATA_AREA+3072+64,  128}; // 4600C40

        memcpy(srcTablePtr, src_data, sizeof(src_data));
        memcpy(dstTablePtr, dst_data, sizeof(dst_data));


        // Need to memory map
        uint64_t src_data0[2] = {0x1212121212121212, 0x1212121212121212};

        uint64_t src_data1[6] = {0x3434343434343434, 0x3434343434343434,
                                 0x3434343434343434, 0x3434343434343434,
                                 0x3434343434343434, 0x3434343434343434};

        uint64_t src_data2[4] = {0x5656565656565656, 0x5656565656565656,
                                 0x5656565656565656, 0x5656565656565656};

        uint64_t src_data3[20] = {0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878,
                                  0x7878787878787878, 0x7878787878787878};


        // results output data expected
         uint64_t result_data[] = {
             (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+1024,
             (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+2048,
             16, 0,

             (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+2048,
             (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+2048+16,
             48, 0,

             (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+3072,
             (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+2048+128,
             32, 0,

             (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+4096,
             (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+3072,
             32, 0,

             (0x8000000000000000|DUMP_TEST_SRC_DATA_AREA)+4096+32,
             (0x8000000000000000|DUMP_TEST_DST_DATA_AREA)+3072+64,
             128, 0,
         };

        do
        {
            uint64_t *va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[0])),
                             PAGESIZE));

            uint64_t *va_srcTableAddr = va_mapsrcTableAddr;

            offset = src_data[0] - ALIGN_PAGE_DOWN(src_data[0]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_data0, sizeof(src_data0));

            // unmap the previous src entry
            int rc = mm_block_unmap(
                        reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollectUnevenSrc mm_block_map (1) bad RC=%X for addr %llx",rc, va_mapsrcTableAddr);
               TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : BAD Rc from mm_block_unmap" );
               break;

            }

            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[2])),
                             PAGESIZE));

            va_srcTableAddr = va_mapsrcTableAddr;

            // calculate offset based on page alignment.
            offset = src_data[2] - ALIGN_PAGE_DOWN(src_data[2]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_data1, sizeof(src_data1));

            // unmap the previous src entry
            rc =  mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollectUnevenSrc mm_block_map (2) bad RC=%X for addr %llx",rc, va_mapsrcTableAddr);
               TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : BAD Rc from mm_block_unmap" );
               break;
            }


            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[4])),
                             PAGESIZE));

            va_srcTableAddr = va_mapsrcTableAddr;

            // calculate offset based on page alignment.
            offset = src_data[4] - ALIGN_PAGE_DOWN(src_data[4]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_data2, sizeof(src_data2));

            // unmap the previous src entry
            rc =  mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollectUnevenSrc mm_block_map (3) bad RC=%X for addr %llx",rc, va_mapsrcTableAddr);
               TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : BAD Rc from mm_block_unmap" );
               break;

            }

            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[6])),
                             PAGESIZE));

            va_srcTableAddr = va_mapsrcTableAddr;

            // calculate offset based on page alignment.
            offset = src_data[6] - ALIGN_PAGE_DOWN(src_data[6]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_data3, sizeof(src_data3));


            // unmap the previous src entry
            rc = mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
               TRACFCOMP(g_trac_dump,
                         "DumpTest::DumpCollectUnevenSrc mm_block_map (4) bad RC=%X for addr %llx",rc, va_mapsrcTableAddr);
               TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : BAD Rc from mm_block_unmap" );
               break;
            }
        }while(0);

        l_err = DUMP::doDumpCollect();

        if( l_err )
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::DumpCollectUnevenSrc got an error back from copySrcToDest : RC=%X",
                       l_err->reasonCode() );
            TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error log from copySrcToDest" );
            errlCommit(l_err,DUMP_COMP_ID);
        }


        //----------------------------------------------------------------
        // !!!!! VERIFYING RESULTS
        // Verify that the data and the VA mapping is correct.
        //----------------------------------------------------------------

        do
        {

            uint64_t *va_mapdestTableAddr = 0;
            uint64_t *va_destTableAddr = 0;
            offset = 0;
            int index = 0;


            // FIRST Destination ENTRY source entires 0 and 1   !!!!
            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            uint64_t paddr = mm_virt_to_phys(va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:1 mapping mismatch actual paddr = %lx, expected paddr = %lx",
                           paddr, dst_data[index]);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error log from dumpcollect" );
            }

            int dataentries = (dst_data[index+1]/16);

           int curSrcEntry = 0;

            // Now loop through the data at this memory address and compare it to the data
            for (int j = 0; j<2; j++)
            {
                if (va_destTableAddr[j] != src_data0[j])
                {
                    // error
                    TRACFCOMP(g_trac_dump,
                              "DumpTest::DumpCollectUnevenSrc:1 : Data mismatch input data = %lX, outputdata = %lx",
                               src_data0[j], va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error data mismatch" );
                    break;
                }
                dataentries = dataentries-1;
                curSrcEntry++;
            }


            // Now loop through the remainder of this destination to a new src data entry
            for (int j = 0; j<dataentries; j++)
            {
                if (va_destTableAddr[curSrcEntry] != src_data1[j])
                {
                    // error
                    TRACFCOMP(g_trac_dump,
                              "DumpTest::DumpCollectUnevenSrc:2 : Data mismatch input data = %lX, outputdata = %lx",
                               src_data1[j], va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error data mismatch" );
                    break;
                }

            }

            // unmap the previous src entry
            int rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:5 got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:5 ERROR : BAD Rc from mm_block_unmap" );
                break;
            }
            index+=2;


            // SECOND DEStination ENTRY  third source entry!!!!

            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            paddr = mm_virt_to_phys(va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenSrc:2 mapping mismatch actual paddr = %lx, expected paddr = %lx", paddr, dst_data[index]);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:2 ERROR : Unexpected error log from dumpcollect" );
            }

            dataentries = (dst_data[index+1]/16);

            // Now loop through the data at this memory address and compare it to the data
            for (int j = 0; j<dataentries; j++)
            {
                if (va_destTableAddr[j] != src_data2[j])
                {
                    // error
                    TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenSrc:3 : Data mismatch input data = %lX, outputdata = %lx", src_data2[j], va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenSrc:3 ERROR : Unexpected error data mismatch" );
                    break;
                }
            }

            // unmap the previous src entry
            rc = mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:6 got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:6 ERROR : BAD Rc from mm_block_unmap" );
                break;
            }

            index+=2;

            // THIRD destination entry - part of last source!!!!

            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            paddr = mm_virt_to_phys(va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenSrc:3 mapping mismatch actual paddr = %lx, expected paddr = %lx", paddr, dst_data[index]);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:3 ERROR : Unexpected error log from dumpcollect" );
            }

            dataentries = (dst_data[index+1]/16);

            curSrcEntry = 0;


            // Now loop through the data at this memory address and compare it to the data
            for (int j = 0; j<dataentries; j++)
            {
                if (va_destTableAddr[j] != src_data3[j])
                {
                    // error
                    TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenSrc:4: Data mismatch input data = %lX, outputdata = %lx", src_data3[j], va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error data mismatch" );
                    break;
                }
                curSrcEntry++;
            }


            // unmap the previous src entry
            rc =
              mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:7  got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:7 ERROR : BAD Rc from mm_block_unmap" );
                break;
            }
            index+=2;


            // FOURTH SRC ENTRY !!!!

            // Get the Va for the page aligned Physical address
            va_mapdestTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(dst_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_destTableAddr = va_mapdestTableAddr;

            // calculate offset based on page alignment.
            offset = dst_data[index] - ALIGN_PAGE_DOWN(dst_data[index]);

            // increment the offset to correct VA offset.
            va_destTableAddr += (offset/(sizeof (uint64_t)));

            paddr = mm_virt_to_phys(va_destTableAddr);

            if (paddr != dst_data[index])
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:5 mapping mismatch actual paddr = %lx, expected paddr = %lx",
                           paddr, dst_data[index]);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:4 ERROR : Unexpected error log from dumpcollect" );
            }

            dataentries = (dst_data[index+1]/16);

            // Now loop through the data at this memory address and compare it to the data
            for (int j = 0; j<dataentries; j++)
            {
                if (va_destTableAddr[j] != src_data3[curSrcEntry])
                {
                    // error
                    TRACFCOMP(g_trac_dump,
                              "DumpTest::DumpCollectUnevenSrc:5 : Data mismatch input data = %lX, outputdata = %lx",
                               src_data3[curSrcEntry], va_destTableAddr[j]);
                    TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error data mismatch" );
                    break;
                }

                curSrcEntry++;
            }

            // unmap the previous src entry
            rc = mm_block_unmap(reinterpret_cast<void*>(va_mapdestTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectUnevenSrc:8 got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc:8 ERROR : BAD Rc from mm_block_unmap" );
                break;
            }
            index+=2;

        }while(0);


        // Ensure there is enough space to fit the real results
        if( resultsTableSize < sizeof(result_data) )
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::Allocated size (%d) is too small for results (%d)",
                      resultsTableSize, sizeof(result_data));
            TS_FAIL( "DumpTest::Allocated size is too small for results" );
        }
        else
        {
            // Check the results table.
            int result_rc = memcmp( resultTablePtr,
                                    result_data,
                                    sizeof(result_data) );

            if (result_rc!=0)
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectUnevenSRC:1 : Results Table mismatch rc = %d", result_rc);
                TRACFBIN( g_trac_dump, "MDRT=", resultTablePtr, sizeof(result_data) );
                TRACFBIN( g_trac_dump, "expected=", result_data, sizeof(result_data)  );
                TS_FAIL( "DumpTest::DumpCollectUnevenSrc ERROR : Unexpected error TABLE mismatch in results table" );
            }
        }

        TRACFCOMP( g_trac_dump, "dumpTest::test_dumpCollectUnevenSrc COMPLETE" );
    }


    /**
     * @brief Basic dump test that forces an error condition that does not have
     *     enough destination space to hold the src size.
     *     This testcase also verifies that we can send a mbox message with
     *     dump status to the FSP.
     *
     */

    void test_DumpCollectNotEnoughDest(void)
    {

        TRACFCOMP( g_trac_dump, "dumpTest::test_dumpCollectNotEnoughDest START" );

        errlHndl_t l_err = NULL;

        uint64_t srcTableSize = 0;
        uint64_t dstTableSize = 0;
        uint64_t resultsTableSize = 0;

        DUMP::dumpEntry *srcTable = NULL;
        DUMP::dumpEntry *destTable = NULL;
        DUMP::resultsEntry *resultsTable = NULL;

        // For testing I am using my own data pointers and setting it up
        // to look like PHYP would have to test the copy function.
        l_err = DUMP::getHostDataPtrs(srcTable, srcTableSize,
                                      destTable, dstTableSize,
                                      resultsTable, resultsTableSize);
        if(l_err)
        {
            TRACFCOMP(g_trac_dump, "DumpTest:test_DumpCollect> error getting getHostDataPtrs: RC=%X"
                      ,l_err->reasonCode() );
            TS_FAIL( "DumpTest::CollectDump ERROR : Failed getHostDataPtrs" );
            errlCommit(l_err,DUMP_COMP_ID);
            return;
        }

        uint64_t *srcTablePtr = reinterpret_cast<uint64_t *>(srcTable);
        uint64_t *dstTablePtr = reinterpret_cast<uint64_t *>(destTable);

        uint64_t src_data[8] = {DUMP_TEST_SRC_DATA_AREA, 64,  // 450000
                                (0x8000000000000000 | DUMP_TEST_SRC_DATA_AREA)
                                                     + 64, 64,
                                DUMP_TEST_SRC_DATA_AREA + 128, 64,
                                DUMP_TEST_SRC_DATA_AREA + 192, 64};


        uint64_t dst_data[8] = {DUMP_TEST_DST_DATA_AREA+4096, 64,   // 4601000
                                DUMP_TEST_DST_DATA_AREA + 4096 + 64, 64,
                                (0x8000000000000000 | DUMP_TEST_DST_DATA_AREA)
                                                     + 4096 + 128, 64,
                                DUMP_TEST_DST_DATA_AREA + 4096 + 192, 32};  // NOTE>> TOO SMALL of a space..


        // Put the src addresses defined above into the MDST
        memcpy(srcTablePtr, src_data, sizeof(src_data));

        // Put the src addresses defined above into the MDDT
        memcpy(dstTablePtr, dst_data, sizeof(dst_data));


        // Need to memory map
        uint64_t src_Inputdata[4][8] = {
            {0x1111111111111111, 0x1111111111111111,
            0x1111111111111111, 0x1111111111111111,
            0x1111111111111111, 0x1111111111111111,
            0x1111111111111111, 0x1111111111111111},

            {0x2222222222222222, 0x2222222222222222,
            0x2222222222222222, 0x2222222222222222,
            0x2222222222222222, 0x2222222222222222,
            0x2222222222222222, 0x2222222222222222},

            {0x3333333333333333, 0x3333333333333333,
            0x3333333333333333, 0x3333333333333333,
            0x3333333333333333, 0x3333333333333333,
            0x3333333333333333,0x3333333333333333},

            {0x4444444444444444, 0x4444444444444444,
            0x4444444444444444, 0x4444444444444444,
            0x4444444444444444, 0x4444444444444444,
            0x4444444444444444, 0x4444444444444444}
        };

        uint64_t *va_mapsrcTableAddr = 0;
        uint64_t *va_srcTableAddr = 0;
        uint64_t offset = 0;
        int index = 0;

        for (int i = 0; i<4; i++)
        {

            // Get the Va for the page aligned Physical address
            va_mapsrcTableAddr = reinterpret_cast<uint64_t*>(
                mm_block_map(reinterpret_cast<void*>(
                                ALIGN_PAGE_DOWN(src_data[index])),
                             PAGESIZE));

            // copy the mapped VA to a VA pointer we will
            va_srcTableAddr = va_mapsrcTableAddr;

            // calculate offset based on page alignment.
            offset = src_data[index] - ALIGN_PAGE_DOWN(src_data[index]);

            // increment the offset to correct VA offset.
            va_srcTableAddr += (offset/(sizeof (uint64_t)));

            memcpy(va_srcTableAddr, src_Inputdata[i], sizeof(src_Inputdata[i]));

            // unmap the previous src entry
            int rc =
                mm_block_unmap(reinterpret_cast<void*>(va_mapsrcTableAddr));

            if (rc != 0)
            {
                TRACFCOMP(g_trac_dump, "DumpTest::DumpCollectNotEnoughDest ERROR..got an error back from unmap : RC=%X",rc);
                TS_FAIL( "DumpTest::DumpCollectNotEnoughDest ERROR : BAD Rc from mm_block_unmap" );
                break;
            }
            index+=2;
        }

        l_err = DUMP::sendMboxMsg(DUMP::DUMP_MSG_START_MSG_TYPE);
        // On the end message queue we need to add the results talble..
        if (l_err)
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-start");
            TS_FAIL(
                    "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-start" );
            errlCommit(l_err,DUMP_COMP_ID);
        }

        l_err = DUMP::doDumpCollect();

        // this testcase expects an error returned.
        if( l_err )
        {

            TRACFCOMP(g_trac_dump,
                      "DumpTest::DumpCollectNotEnoughDest got an EXPECTED error back from copySrcToDest : RC=%X",l_err->reasonCode() );
            delete l_err;

            // Send an Error mbox msg to FSP that we got an error
            l_err = DUMP::sendMboxMsg(DUMP::DUMP_MSG_ERROR_MSG_TYPE);

            if (l_err)
            {
                TRACFCOMP(g_trac_dump,
                          "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-error");
                TS_FAIL( "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-error" );
            }
        }
        else
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::DumpCollectNotEnoughDest ERROR : Did NOT get errorlog back from copySrcToDest");
            TS_FAIL( "DumpTest::DumpCollectNotEnoughDest ERROR : DID not get expected error on too small dest entry" );
        }


        // This call is just to verify we can call MSG_END .. even though with
        // this flow we already sent a msg ERROR.


        // Successful so send mbox message indicating the dump is complete and successful
        l_err = DUMP::sendMboxMsg(DUMP::DUMP_MSG_END_MSG_TYPE);

        if (l_err)
        {
            TRACFCOMP(g_trac_dump,
                      "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-END");
            TS_FAIL( "DumpTest::DumpCollectNotEnoughDest ERROR : Got an errorlog back from sendMboxMsg-END" );
        }


        TRACFCOMP( g_trac_dump, "dumpTest::test_dumpCollectNotEnoughDest COMPLETE" );

    }
};

#endif
