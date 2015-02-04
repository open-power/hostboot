/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/test/testlidmgr_rt.H $                   */
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
#include <util/utillidmgr.H>
#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <utilbase.H>
#include <config.h>

class LidMgrRtTest : public CxxTest::TestSuite
{
    public:
        void testMissingLid()
        {
            UtilLidMgr lidmgr(-1);

            size_t l_size = 0;
            errlHndl_t l_errl = lidmgr.getLidSize(l_size);

            if (l_size != 0)
            {
                TS_FAIL("Found missing lid -1.");
            }
            else
            {
                delete l_errl;
                l_errl = NULL;
            }
        }

        /**
         *  @brief Test to check if the structure that maps lidID's to pnor
         *         sections is working correctly
         */
        void testLidInPnor(void)
        {
            errlHndl_t l_errl = NULL;

            do
            {
                size_t l_lidSize = 0;

                UtilLidMgr l_lidMgr(Util::TEST_LIDID);

                PNOR::SectionInfo_t l_lidPnorInfo;
                l_errl = PNOR::getSectionInfo(PNOR::TEST, l_lidPnorInfo);
                if (l_errl)
                {
                    errlCommit(l_errl,UTIL_COMP_ID);
                    TS_FAIL("testLidInPnor: Error getting lidId=0x%.8x",
                            Util::TEST_LIDID);
                    break;
                }

                l_errl = l_lidMgr.getLidSize(l_lidSize);
                if(l_errl)
                {
                    errlCommit(l_errl,UTIL_COMP_ID);
                    TS_FAIL("testLidInPnor: Error getting lidId=0x%.8x",
                            Util::TEST_LIDID);
                    break;
                }

                if (l_lidSize != l_lidPnorInfo.size)
                {
                    TS_FAIL("testLidInPnor: lidSize does not match pnor TEST"
                            " section size 0x%.8X != 0x%.8X",
                            l_lidSize, l_lidPnorInfo.size);
                    break;
                }

                char * l_ptr = new char[l_lidPnorInfo.size];
                l_errl = l_lidMgr.getLid(l_ptr, l_lidPnorInfo.size);
                if(l_errl)
                {
                    errlCommit(l_errl, UTIL_COMP_ID);
                    TS_FAIL("testLidInPnor: failed to get lid from PNOR");
                }
                delete[] l_ptr;
            }while(0);
        }
};
