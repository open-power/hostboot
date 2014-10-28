/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/pnor/runtime/test/testpnor_rt.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/userif.H>

#include <pnor/pnorif.H>
#include "../../pnor_common.H"
#include "../rt_pnor.H"

#include <runtime/interface.h>
#include <trace/interface.H>

#include "../../ffs.h"           //Common header file with BuildingBlock.
#include "../../common/ffs_hb.H" //Hostboot def of user data in ffs_entry struct

extern trace_desc_t* g_trac_pnor;
using namespace TARGETING;

/*
 * these taest cases are turned off as they have dependency on pnorddtest cases
 */
class PnorRtTest : public CxxTest::TestSuite
{
    public:
    /**
     * @brief: testTOC
     *      tests that the TOC is read/parsed properly during runtime
     */
    void testTOC (void)
    {
#if 1
        TRACFCOMP(g_trac_pnor, "PnorRtTest::testTOC - skipping - as it"
                " adversly affects pnorddtests");
#else
        TRACFCOMP(g_trac_pnor, "PnorRtTest::testTOC Start" );
        errlHndl_t l_err = NULL;
        uint32_t l_proc = 0;
        uint64_t offset = 0;
        uint8_t* tocHeader = new uint8_t[PAGESIZE];
        uint8_t* tocEntry = new uint8_t[PAGESIZE];
        uint8_t* corruptBuffer = new uint8_t[PAGESIZE];

        // Corrupt both ffs header and first entry for each TOC
        for (uint32_t cur_TOC = 0; cur_TOC < PNOR::NUM_TOCS; ++cur_TOC)
        {
            uint32_t TOC_used = cur_TOC;
            offset = (cur_TOC == 0) ? PNOR::TOC_0_OFFSET : PNOR::TOC_1_OFFSET;

            // Read cur_TOC header data
            l_err = RtPnor::getInstance().readFromDevice(l_proc,PNOR::TOC,
                                  offset,PAGESIZE,false,tocHeader);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: readFromDevice failed");
                break;
            }

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocHeader, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;

            l_err = RtPnor::getInstance().writeToDevice(l_proc,PNOR::TOC,
                    offset,PAGESIZE,false,corruptBuffer);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: writeToDevice failed");
            }

            // Check if cur_TOC failed that other TOC is used
            l_err = RtPnor::getInstance().readTOC();
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: readTOC failed");
            }

            TOC_used = RtPnor::getInstance().iv_TOC_used;
            TRACFCOMP(g_trac_pnor, "PnorRtTest::testTOC : TOC %d Corrupt"
                    " Header, Toc_used = %d", cur_TOC, TOC_used);

            if (TOC_used == cur_TOC)
            {
                TS_FAIL("PnorRtTest::testTOC>ERROR:TOC %d header is corrupted,"
                        " did not use other TOC");
                break;
            }
            // Fix cur_TOC header
            l_err = RtPnor::getInstance().writeToDevice(l_proc,PNOR::TOC,
                    offset,PAGESIZE,false,tocHeader);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: writeToDevice failed");
            }

            // Read cur_TOC first entry data
            l_err = RtPnor::getInstance().readFromDevice(l_proc,PNOR::TOC,
                                  offset+FFS_HDR_SIZE,PAGESIZE,false,tocEntry);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: readTOC failed");
                break;
            }

            // Corrupt cur_TOC header data
            memcpy(corruptBuffer, tocEntry, PAGESIZE);
            corruptBuffer[0] = 0xFF;
            corruptBuffer[1] = 0xFF;

            l_err = RtPnor::getInstance().writeToDevice(l_proc,PNOR::TOC,
                    offset+FFS_HDR_SIZE,PAGESIZE,false,corruptBuffer);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: writeToDevice failed");
            }

            // Check if cur_TOC failed that other TOC is used
            TOC_used = cur_TOC;
            l_err = RtPnor::getInstance().readTOC();
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: readTOC failed");
            }
            TOC_used = RtPnor::getInstance().iv_TOC_used;
            TRACFCOMP(g_trac_pnor,"PnorRtTest::testTOC:TOC %d Corrupt"
                    " Entry, Toc_used = %d", cur_TOC, TOC_used);

            if (TOC_used == cur_TOC)
            {
                TS_FAIL("PnorRtTest::testTOC>ERROR: TOC %d entry is corrupted,"
                        " did not use other TOC", cur_TOC);
            }

            // Fix cur_TOC first entry
            l_err = RtPnor::getInstance().writeToDevice(l_proc,PNOR::TOC,
                    offset+FFS_HDR_SIZE,PAGESIZE,false,tocEntry);
            if (l_err)
            {
                TS_FAIL("PnorRtTest::testTOC: writeToDevice failed");
            }
        }

        delete tocHeader;
        delete tocEntry;
        delete corruptBuffer;

        TRACFCOMP(g_trac_pnor, "PnorRtTest::testTOC End");
#endif
    }

    /**
     * @brief RtPnor::testPnorReadWrite
     *       Compares the values read and written by runtime interfaces and
     *       IPL interfaces
     */
    void testPnorReadWrite(void)
    {
        TRACFCOMP(g_trac_pnor, ENTER_MRK"testPnorReadWrite");
        do {
            errlHndl_t l_err = NULL;
            uint32_t   l_proc = 0;
            uint64_t   l_offset = PNOR::pnorTestSec_rt_readwrite_offset;
            uint64_t   l_writeData = 0x0123456789ABCDEF;
            PNOR::SectionId l_id = PNOR::TEST;
            PNOR::SectionInfo_t l_info;

            size_t l_sizeBytes = (RtPnor::getInstance().iv_TOC[l_id].size) -
                                 l_offset;
            void*  l_readData  = malloc (l_sizeBytes);

            //read via hostInterfaces
            l_err = RtPnor::getInstance().readFromDevice(l_proc,l_id,l_offset,
                                          l_sizeBytes,true,l_readData);
            if(l_err)
            {
                TS_FAIL("testPnorReadWrite: readFromDevice failed");
                break;
            }

            //read using getSectionInfo
            l_err = PNOR::getSectionInfo(l_id, l_info);
            if (l_err)
            {
                TS_FAIL("testPnorReadWrite: getSectionInfo failed");
                break;
            }

            void* l_gData = reinterpret_cast<void*> (l_info.vaddr);

            //verify that data is read correctly
            if (0 != memcmp (l_readData, l_gData, l_sizeBytes))
            {
                TS_FAIL("testPnorReadWrite: read failed");
                break;
            }
            TRACFCOMP(g_trac_pnor, "testPnorReadWrite: read successfull");

            /***********************************************************/
            //make changes to the getSectionInfo pointer and call flush
            uint8_t* l_vaddr =  reinterpret_cast<uint8_t*>(l_info.vaddr);

            memcpy(l_vaddr, &l_writeData, 4);
            memcpy(l_vaddr+PAGESIZE+20, &l_writeData, 4);

            l_err = PNOR::flush(l_id);
            if (l_err)
            {
                TS_FAIL("testPnorReadWrite: flush failed");
                break;
            }

            /***********************************************************/
            //calling read again to make sure data was written properly
            //using pnor_wirte
            l_err = RtPnor::getInstance().readFromDevice(l_proc,l_id,l_offset,
                                                l_sizeBytes,true,l_readData);
            if(l_err)
            {
                TS_FAIL("testPnorReadWrite: readFromDevice failed");
                break;
            }

            if (0 != memcmp (l_readData, l_gData, l_sizeBytes))
            {
                TS_FAIL("testPnorReadWrite: flush failed");
                break;
            }
            TRACFCOMP(g_trac_pnor, "testPnorReadWrite: flush passed");

        } while (0);
        TRACFCOMP(g_trac_pnor, EXIT_MRK"testPnorReadWrite");
    }

};
