/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/runtime/test/testlidmgr_rt.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
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

class LidMgrRtTest : public CxxTest::TestSuite
{
    public:
        void testMissingLid()
        {
            UTIL_FT(ENTER_MRK"testMissingLid()");
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
            UTIL_FT(EXIT_MRK"testMissingLid()");
        }

        /**
         *  @brief Test a lid request that flows through lid_load
         */
        void testLidLoad(void)
        {
            UTIL_FT(ENTER_MRK"testLidLoad()");
            errlHndl_t l_errl = NULL;

            do
            {
                size_t l_lidSize = 0;

                UtilLidMgr l_lidMgr(Util::OCC_LIDID);

                l_errl = l_lidMgr.getLidSize(l_lidSize);
                if(l_errl)
                {
                    errlCommit(l_errl,UTIL_COMP_ID);
                    TS_FAIL("testLidLoad: Error getting lidId=0x%.8x",
                            Util::TEST_LIDID);
                    break;
                }

#if 0 //@fixme-RTC:249746-we are getting the real size back, not the full partition
                const size_t EXPECTED_SIZE = 0x120000; //from pnorLayoutP10.xml
                if (l_lidSize != EXPECTED_SIZE)
                {
                    TS_FAIL("testLidLoad: lidSize does not match expected"
                            " section size 0x%.8X != 0x%.8X",
                            l_lidSize, EXPECTED_SIZE);
                    break;
                }
#endif

                char * l_ptr = new char[l_lidSize];
                l_errl = l_lidMgr.getLid(l_ptr, l_lidSize);
                if(l_errl)
                {
                    errlCommit(l_errl, UTIL_COMP_ID);
                    TS_FAIL("testLidLoad: failed to get lid");
                }
                delete[] l_ptr;

                void* l_pLidImage = NULL;
                size_t l_lidImageSize = 0;
                l_errl = l_lidMgr.getStoredLidImage(l_pLidImage,
                                                    l_lidImageSize);
                if (l_errl)
                {
                    errlCommit(l_errl, UTIL_COMP_ID);
                    TS_FAIL("testLidLoad: failed to get stored lid");
                }

#if 0 //@fixme-RTC:249746-we are getting the real size back, not the full partition
                if (l_lidImageSize != EXPECTED_SIZE)
                {
                    TS_FAIL("testLidLoad: stored size does not match"
                            " section size 0x%.8X != 0x%.8X",
                            l_lidImageSize, EXPECTED_SIZE);
                }
#endif

                l_errl = l_lidMgr.releaseLidImage();
                if(l_errl)
                {
                    errlCommit(l_errl, UTIL_COMP_ID);
                    TS_FAIL("testLidLoad: failed to release lid");
                }
            }while(0);
            UTIL_FT(EXIT_MRK"testLidLoad()");
        }

};
