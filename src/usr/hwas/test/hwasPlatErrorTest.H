/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwas/test/hwasPlatErrorTest.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/**
*  @file hwasPlatErrorTest.H
*
*  @brief Test cases for the wrapper functions of platform specific error functions
*/

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <errl/errlreasoncodes.H>
#include <hwas/common/hwasCommon.H>

using namespace TARGETING;

class hwasPlatErrorTest: public CxxTest::TestSuite
{
    public:
        /**
        * @brief testing hwasErrorUpdatePlid()
        */
        void test_hwasErrorUpdatePlid( void ) {
            TS_INFO(ENTER_MRK"test_hwasErrorUpdatePlid - Start");
            //Create error log
            errlHndl_t l_err = hwasError(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                         ERRORLOG::ERRL_TEST_REASON_CODE);
            //Save original l_err plid value
            uint32_t l_startPlid = l_err->plid();

            //Set l_plid to 0 to update it to original l_err plid value
            uint32_t l_plid = 0;
            hwasErrorUpdatePlid(l_err, l_plid);

            if (l_err->plid() != l_startPlid) {
                TS_FAIL("test_hwasErrorUpdatePlid - l_err plid was updated - "
                        "should have stayed the same")
            }
            if (l_startPlid != l_plid) {
                TS_FAIL("test_hwasErrorUpdatePlid - l_plid should have been "
                        "updated to l_err's plid value")
            }

            delete l_err;
            l_err = nullptr;

            TS_INFO(EXIT_MRK"test_hwasErrorUpdatePlid - End");
        }

        /**
        * @brief testing hwasErrorAddProcedureCallout()
        */
        void test_hwasErrorAddProcedureCallout( void ) {
            TS_INFO(ENTER_MRK"test_hwasErrorAddProcedureCallout - Start");

            //Create error log with random data
            uint64_t userdata1 = 0x1;
            uint64_t userdata2 = 0x2;
            errlHndl_t l_err = hwasError(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                         ERRORLOG::ERRL_RT_TEST_MOD_ID,
                                         ERRORLOG::ERRL_TEST_REASON_CODE,
                                         userdata1,
                                         userdata2);

            //Call function to add procedure callout
            hwasErrorAddProcedureCallout(l_err,
                                         EPUB_PRC_FIND_DECONFIGURED_PART,
                                         SRCI_PRIORITY_HIGH);

            bool l_procedureAdded = false;
            //Get errlog Callout User Detail sections
            for(auto l_calloutData : l_err->getUDSections(ERRL_COMP_ID, ERRORLOG::ERRL_UDT_CALLOUT))
            {
                //Check for procedure callout data
                HWAS::callout_ud_t *l_ud = reinterpret_cast<HWAS::callout_ud_t*>(l_calloutData);
                if (l_ud->type != HWAS::PROCEDURE_CALLOUT)
                {
                    TS_FAIL("test_hwasErrorAddProcedureCallout - unexpected type in "
                            "procedure callout: 0x%x", l_ud->type)
                }
                else if (l_ud->flag != HWAS::FLAG_NONE)
                {
                    TS_FAIL("test_hwasErrorAddProcedureCallout - unexpected flag in "
                            "procedure callout: 0x%x", l_ud->flag)
                }
                else if (l_ud->procedure != EPUB_PRC_FIND_DECONFIGURED_PART)
                {
                    TS_FAIL("test_hwasErrorAddProcedureCallout - unexpected procedure in "
                            "procedure callout: 0x%x", l_ud->procedure)
                }
                else if (l_ud->priority != SRCI_PRIORITY_HIGH)
                {
                    TS_FAIL("test_hwasErrorAddProcedureCallout - unexpected priority in "
                            "procedure callout: 0x%x", l_ud->priority)
                }
                else {
                    l_procedureAdded = true;
                    break;
                }
            }

            if (!l_procedureAdded)
            {
                errlCommit( l_err, CXXTEST_COMP_ID );
            }
            else {
                delete l_err;
                l_err = nullptr;
            }

            TS_INFO(EXIT_MRK"test_hwasErrorAddProcedureCallout - End");
        }
};