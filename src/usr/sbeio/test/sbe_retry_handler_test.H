/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_retry_handler_test.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
#ifndef __SBE_RETRY_HANDLER_TEST_H
#define __SBE_RETRY_HANDLER_TEST_H

/**
 * @file sbe_retry_handler_test.H
 *
 * @brief Test cases for the SBE Retry Handler
 */

#include <cxxtest/TestSuite.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_retry_handler.H>

#define SBE_TRACD_RHT(printf_string, args...) \
    TRACDCOMP(g_trac_sbeio,"retry_handler_test: " printf_string,##args)
#define SBE_TRACF_RHT(printf_string, args...) \
    TRACFCOMP(g_trac_sbeio,"retry_handler_test: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

class SbeRetryHandlerTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and ensure that we return back
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEReturns(void)
    {
        SBE_TRACF_RHT(ENTER_MRK"testSBEReturns: Testing we come back from SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEReturns PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEReturns skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

            l_SBEobj.main_sbe_handler(l_cpu_target);

            SBE_TRACF_RHT("testSBEReturns: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEReturns: Testing we come back from SbeRetryHandler");
    }

    /**
     * @brief Call into SbeRetryHandler on the slave SBE, and ensure that
     *        the sbe started status matches the target attribute
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEStarted(void)
    {
        SBE_TRACF_RHT(ENTER_MRK"testSBEStarted: Match SBE started state with attribute");

        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEStarted PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEStarted skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT);

            l_SBEobj.main_sbe_handler(l_cpu_target);

            uint32_t l_sbeStarted = l_cpu_target->getAttr<
                                    TARGETING::ATTR_SBE_IS_STARTED>();

            if(l_SBEobj.isSbeAtRuntime() && !l_sbeStarted)
            {
                TS_FAIL("testSBEStarted: Mismatch between SBE state says at RUNTIME and attribute says -NOT- started");
            }else if(!(l_SBEobj.isSbeAtRuntime() && l_sbeStarted))
            {
                TS_FAIL("testSBEStarted: Mismatch between SBE state says -NOT- at RUNTIME and attribute says started");
            }
        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEStarted: Match SBE started state with attribute");
    }

};

#endif
