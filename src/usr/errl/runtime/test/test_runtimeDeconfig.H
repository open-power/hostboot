/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/runtime/test/test_runtimeDeconfig.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
#ifndef _TEST_DECONFIGRUNTIME_H
#define _TEST_DECONFIGRUNTIME_H

#include <cxxtest/TestSuite.H>
#include <errl/errlmanager.H>
#include <hbotcompid.H>
#include <hwas/common/hwas_reasoncodes.H>
#include <hwas/common/deconfigGard.H>
#include <targeting/common/utilFilter.H>

extern trace_desc_t* g_trac_runtime;

// enable this test to execute all unit tests
//#define __ENABLE_DECONFIG_TEST

class deconfigureTargetAtRuntimeTest : public CxxTest::TestSuite
{
    public:


        void testNullTarget()
        {
            TRACFCOMP(g_trac_runtime, "testNullTarget running");

            // pass in a null target pointer
            TARGETING::Target * l_target = nullptr;

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            do{

                if(l_errl)
                {
                    TRACFCOMP(g_trac_runtime, "testNullTarget:"
                            " errl returned (expected)");

                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_NULL_TARGET))
                    {
                        TRACFCOMP(g_trac_runtime, "testNullTarget:"
                                " error's module id and reason code match "
                                "expected values");

                    }
                    else
                    {
                        TS_FAIL("testNullTarget: error with unexpected"
                                " module id/reason code returned. Expected module "
                                "id = 0x%x returned module id = 0x%x; expected "
                                "reason code ="
                                " 0x%x returned reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_TARGET,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;
                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testNullTarget: no errl returned from"
                            " checkHbResMemLimit under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testNullTarget finished");
        }


        void testInvalidDeconfigOption()
        {
            TRACFCOMP(g_trac_runtime, "testInvalidDeconfig running");

            TARGETING::Target * l_target = nullptr;

            TARGETING::TargetHandleList l_cores;
            TARGETING::getAllChiplets(l_cores, TARGETING::TYPE_CORE);

            if( l_cores.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found 0 cores");

            }

            l_target = l_cores.at(0);

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::SPEC_DECONFIG,
                    l_errl);
            do{

                if(l_errl)
                {
                    TRACDCOMP(g_trac_runtime, "testInvalidDeconfigOption:"
                            " errl returned (expected)");

                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_INVALID_PARAM))
                    {
                        TRACDCOMP(g_trac_runtime, "testInvalidDeconfigOption:"
                                " error's module id and reason code match "
                                "expected values");

                    }
                    else
                    {
                        TS_FAIL("testInvalidDeconfigOption: error with unexpected"
                                " module id/reason code returned. Expected module "
                                "id = 0x%x returned module id = 0x%x; expected "
                                "reason code = 0x%x returned reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_PARAM,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;
                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testInvalidDeconfigOption: no errl returned from"
                            " checkHbResMemLimit under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testInvalidDeconfigOption finished");
        }

        void testInvalidTarget()
        {
            TRACFCOMP(g_trac_runtime, "testInvalidTarget running");

            TARGETING::TargetHandleList l_proc;
            TARGETING::getAllChips(l_proc, TARGETING::TYPE_PROC);

            if( l_proc.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found procs");
            }

            TARGETING::Target * l_target = l_proc.at(0);

            errlHndl_t l_errl = nullptr;
            l_errl = HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            do{

                if(l_errl)
                {
                    TRACDCOMP(g_trac_runtime, "deconfigureTargetAtRuntime:"
                            " errl returned (expected)");
                    //Check module id and reason code
                    if((l_errl->moduleId() == HWAS::MOD_RUNTIME_DECONFIG) and
                            (l_errl->reasonCode() == HWAS::RC_INVALID_TARGET))
                    {
                        TRACDCOMP(g_trac_runtime, "testInvalidTarget:"
                                " error's module id and reason code match "
                                "expected values");
                    }
                    else
                    {

                        TS_FAIL("testInvalidTarget: error with unexpected"
                                " module id/reason code returned. Expected "
                                "module id = 0x%x returned module id = "
                                "0x%x; expected reason code = 0x%x returned "
                                "reason code = 0x%x",
                                HWAS::MOD_RUNTIME_DECONFIG,
                                l_errl->moduleId(),
                                HWAS::RC_INVALID_TARGET,
                                l_errl->reasonCode());
                        errlCommit(l_errl, CXXTEST_COMP_ID);
                        break;

                    }
                    delete l_errl;
                    l_errl = nullptr;
                }
                else
                {
                    TS_FAIL("testInvalidTarget: no errl returned from"
                            " deconfigTargetAtRuntime under error condition");
                }

            }while(0);
            TRACFCOMP(g_trac_runtime, "testInvalidTarget finished");
        }

        void testDeconfigAtRuntime()
        {
            TRACFCOMP(g_trac_runtime, "testDeconfigAtRuntime ENTRY");

#ifndef __ENABLE_DECONFIG_TEST
            //  NOTE:  This test marks targets nonfunctional and then
            //         restore them.  Since all the unit tests run in
            //         parallel, this may cause other tests to fail.
            //         Do not leave this test enabled for normal operations.
            TS_INFO(INFO_MRK "testDeconfigAtRuntime SKIPPING: other tests could be affected.");
#else
            TS_INFO(INFO_MRK "testDeconfigAtRuntime: RUNNING other tests could be affected.");
            TARGETING::TargetHandleList l_cores;
            TARGETING::getAllChiplets(l_cores, TARGETING::TYPE_CORE);

            if( l_cores.size() == 0 )
            {
                TS_FAIL("Unable to execute test, found procs");
            }

            TARGETING::Target * l_target = l_cores.at(0);

            TARGETING::HwasState l_origState =
                l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();

            errlHndl_t l_errl =
                HWAS::theDeconfigGard().deconfigureTargetAtRuntime(
                    l_target,
                    HWAS::DeconfigGard::FULLY_AT_RUNTIME,
                    l_errl);

            if(l_errl)
            {
                TS_FAIL("testDeconfigAtRuntime: deconfigureTargetAtRuntime"
                        " returned an unexpected error");
                errlCommit(l_errl, CXXTEST_COMP_ID);
            }
            else
            {
                TRACDCOMP(g_trac_runtime, "testDeconfigAtRuntime:"
                        " no error returned (expected)");

                TARGETING::HwasState l_state =
                    l_target->getAttr<TARGETING::ATTR_HWAS_STATE>();

                if(l_state.functional)
                {
                    TS_FAIL("testDeconfigureAtRuntime(): target functional after deconfigure");
                }

                l_target->setAttr<TARGETING::ATTR_HWAS_STATE>(l_origState);
            }
#endif
            TRACFCOMP(g_trac_runtime, "testDeconfigAtRuntime finished");
        }


};


#endif
