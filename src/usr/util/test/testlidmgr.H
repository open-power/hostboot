/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/test/testlidmgr.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef _TESTLIDMGR_H
#define _TESTLIDMGR_H

/**
 *  @file testlidmgr.H
 *
 *  @brief Test case for utillidmgr (non-runtime)
*/

#include <cxxtest/TestSuite.H>

#include <errl/errlmanager.H>
#include "../utilbase.H"
#include "../utillidpnor.H"

class LidMgrTest : public CxxTest::TestSuite
{
public:

    /**
     *  @brief Test to check if the const array lidToPnor is sorted
     */
    void testLidToPnorSorted(void)
    {
        for (size_t i = 0; (i+1) < Util::NUM_LID_TO_PNOR; ++i)
        {
            if (Util::lidToPnor[i].first > Util::lidToPnor[i+1].first)
            {
                TS_FAIL("testLidToPnorSorted: utilidmgr lidToPnor[] is not sorted");
            }
        }
    }

    /**
     *  @brief Test to check if the structure that maps lidID's to pnor sections
     *         is working correctly
     */
    void testLidInPnorTest(void)
    {
        errlHndl_t l_errl = NULL;
        size_t l_lidSize = 0;
        UtilLidMgr l_lidMgr(Util::TEST_LIDID);

        do
        {
            l_errl = l_lidMgr.getLidSize(l_lidSize);
            if(l_errl)
            {
                errlCommit(l_errl,UTIL_COMP_ID);
                TS_FAIL("testLidInPnor: Error getting lidId=0x%.8x",
                        Util::TEST_LIDID);
                break;
            }

            PNOR::SectionInfo_t l_lidPnorInfo;
            l_errl = PNOR::getSectionInfo(PNOR::TEST, l_lidPnorInfo);
            if(l_errl)
            {
                errlCommit(l_errl,UTIL_COMP_ID);
                TS_FAIL("testLidInPnor: could not get pnor section %s",
                            l_lidPnorInfo.name);
                break;
            }

            if (l_lidSize != l_lidPnorInfo.size)
            {
                TS_FAIL("testLidInPnor: lidSize does not match pnor test section size 0x%.8X > 0x%.8X",
                        l_lidSize, l_lidPnorInfo.size);
                break;
            }

            // Purposely pass in a size smaller than the pnor test section size
            uint32_t l_testSize = 0x1000;
            char * l_ptrTest = new char[l_lidPnorInfo.size];
            l_errl = l_lidMgr.getLid(l_ptrTest, l_testSize);
            if(l_errl)
            {
                UTIL_FT(INFO_MRK"testLidInPnor: expected error");
                delete l_errl;
                l_errl = NULL;
            }
            else
            {
                TS_FAIL("testLidInPnor: should fail getLid() due to lidSize > provided size");
            }
            delete[] l_ptrTest;
        }while(0);
    }

    /**
     *  @brief Test to check if the structure that maps lidID's to pnor sections
     *         is working correctly
     */
    void testLidInPnorOcc(void)
    {
        errlHndl_t l_errl = NULL;

        do
        {
            size_t l_lidSize = 0;
            UtilLidMgr l_lidMgr(Util::OCC_LIDID);

            PNOR::SectionInfo_t l_lidPnorInfo;
            l_errl = PNOR::getSectionInfo(PNOR::OCC, l_lidPnorInfo);
            // Section only present in openPOWER systems
            if (l_errl)
            {
                delete l_errl;
                l_errl = NULL;
                break;
            }

            l_errl = l_lidMgr.getLidSize(l_lidSize);
            if(l_errl)
            {
                errlCommit(l_errl,UTIL_COMP_ID);
                TS_FAIL("testLidInPnorOcc: Error getting lidId=0x%.8x",
                        Util::TEST_LIDID);
                break;
            }

            if (l_lidSize != l_lidPnorInfo.size)
            {
                TS_FAIL("testLidInPnorOcc: lidSize does not match pnor OCC section size 0x%.8X > 0x%.8X",
                        l_lidSize, l_lidPnorInfo.size);
                break;
            }

            char * l_ptrOcc = new char[l_lidPnorInfo.size];
            l_errl = l_lidMgr.getLid(l_ptrOcc, l_lidPnorInfo.size);
            if(l_errl)
            {
                errlCommit(l_errl, UTIL_COMP_ID);
                TS_FAIL("testLidInPnorOcc: failed to get lid from PNOR");
            }
            delete[] l_ptrOcc;
        }while(0);
    }
};

#endif