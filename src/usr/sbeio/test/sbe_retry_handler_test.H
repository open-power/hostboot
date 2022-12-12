/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_retry_handler_test.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2023                        */
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
#include <vfs/vfs.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbeioreasoncodes.H>
#include <sbeio/sbe_retry_handler.H>

#define SBE_TRACD_RHT(printf_string, args...) \
    TRACDCOMP(g_trac_sbeio,"retry_handler_test: " printf_string,##args)
#define SBE_TRACF_RHT(printf_string, args...) \
    TRACFCOMP(g_trac_sbeio,"retry_handler_test: " printf_string,##args)

extern trace_desc_t* g_trac_sbeio;

const char SBE_LIBRARY_NAME[16]    = "libsbe.so";

using namespace SBE;
using namespace SBEIO;

errlHndl_t loadSbeModule(bool& o_loaded)
{
    errlHndl_t err = NULL;
    o_loaded = false;

    if(!VFS::module_is_loaded(SBE_LIBRARY_NAME))
    {
        err = VFS::module_load(SBE_LIBRARY_NAME);
        if(err)
        {
            TS_FAIL("loadSbeModule() - %s load failed", SBE_LIBRARY_NAME );

        }
        else
        {
            o_loaded = true;
        }
    }

    return err;
}

errlHndl_t unloadSbeModule()
{
    errlHndl_t err = NULL;

    err = VFS::module_unload(SBE_LIBRARY_NAME);
    if(err)
    {
        TS_FAIL("unloadSbeModule() - %s unload failed", SBE_LIBRARY_NAME );

        // No break or return - still try and unload other module

    }

    return err;
}

class SbeRetryHandlerTest : public CxxTest::TestSuite
{
  public:

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowRESTART_SBE(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE: Testing SbeRetryHandler");

        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowRESTART_SBE PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowRESTART_SBE skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_RESTART_SBE);
            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // l_sbeTestBootRestartCount is bumped in this test to 1 (for a boot restart attempt)
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            // so we are looking for an increase from 1 to 2 for CurrentSideCount's
            if ((l_sbeTestSwitchSidesCount != 0) || (l_sbeTestSwitchSidesCountMseeprom != 0) ||
                (l_sbeTestCurrentSideCount != 2) || (l_sbeTestCurrentSideCountMseeprom != 2) ||
                (l_sbeTestBootRestartCount != 1))
            {
                TS_FAIL("testSBEFlowRESTART_SBE failed to match expected results for RESTART_SBE attempt");
            }
            else
            {
                TS_INFO("testSBEFlowRESTART_SBE: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowRESTART_SBE: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowRESTART_CBS(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_CBS: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_CBS: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowRESTART_CBS PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowRESTART_CBS skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::START_CBS,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_RESTART_CBS);
            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // l_sbeTestBootRestartCount is bumped in this test to 1 (for a boot restart attempt)
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            // Since the mseeprom is flipped, CurrentSideCount's for mseeprom will be zero'd out
            // This test We ALWAYS flip the MSEEPROM
            if ((l_sbeTestSwitchSidesCount != 0) || (l_sbeTestSwitchSidesCountMseeprom != 1) ||
                (l_sbeTestCurrentSideCount != 2) || (l_sbeTestCurrentSideCountMseeprom != 0) ||
                (l_sbeTestBootRestartCount != 1))
            {
                TS_FAIL("testSBEFlowRESTART_CBS failed to match expected results for RESTART_CBS attempt");
            }
            else
            {
                TS_INFO("testSBEFlowRESTART_CBS: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowRESTART_CBS: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowREIPL_BKP_SEEPROM(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_BKP_SEEPROM: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_BKP_SEEPROM: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowREIPL_BKP_SEEPROM PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowREIPL_BKP_SEEPROM skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_BKP_SEEPROM);
            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // Most important value is the l_sbeTestSwitchSidesCount, this is what gets set in this test
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            if ((l_sbeTestSwitchSidesCount != 1) || (l_sbeTestSwitchSidesCountMseeprom != 0) ||
                (l_sbeTestCurrentSideCount != 1) || (l_sbeTestCurrentSideCountMseeprom != 1) ||
                (l_sbeTestBootRestartCount != 0))
            {
                TS_FAIL("testSBEFlowREIPL_BKP_SEEPROM failed to properly switch sides");
            }
            else
            {
                TS_INFO("testSBEFlowREIPL_BKP_SEEPROM: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowREIPL_BKP_SEEPROM: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowREIPL_UPD_SEEPROM(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_UPD_SEEPROM: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_UPD_SEEPROM: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowREIPL_UPD_SEEPROM PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowREIPL_UPD_SEEPROM skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_UPD_SEEPROM);
            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // Most important value is the l_sbeTestSwitchSidesCount, this is what gets set in this test
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            if ((l_sbeTestSwitchSidesCount != 1) || (l_sbeTestSwitchSidesCountMseeprom != 0) ||
                (l_sbeTestCurrentSideCount != 1) || (l_sbeTestCurrentSideCountMseeprom != 1) ||
                (l_sbeTestBootRestartCount != 0))
            {
                TS_FAIL("testSBEFlowREIPL_UPD_SEEPROM failed to properly switch sides");
            }
            else
            {
                TS_INFO("testSBEFlowREIPL_UPD_SEEPROM: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowREIPL_UPD_SEEPROM: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowREIPL_BKP_MSEEPROM(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_BKP_MSEEPROM: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_BKP_MSEEPROM: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowREIPL_BKP_MSEEPROM PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowREIPL_BKP_MSEEPROM skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);
            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_BKP_MSEEPROM);

            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // Most important value is the l_sbeTestSwitchSidesCountMseeprom, this is what gets set in this test
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            if ((l_sbeTestSwitchSidesCount != 0) || (l_sbeTestSwitchSidesCountMseeprom != 1) ||
                (l_sbeTestCurrentSideCount != 1) || (l_sbeTestCurrentSideCountMseeprom != 1) ||
                (l_sbeTestBootRestartCount != 0))
            {
                TS_FAIL("testSBEFlowREIPL_BKP_MSEEPROM failed to properly switch sides");
            }
            else
            {
                TS_INFO("testSBEFlowREIPL_BKP_MSEEPROM: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowREIPL_BKP_MSEEPROM: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowREIPL_UPD_MSEEPROM(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_UPD_MSEEPROM: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowREIPL_UPD_MSEEPROM: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowREIPL_UPD_MSEEPROM PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowREIPL_UPD_MSEEPROM skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);
            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_UPD_MSEEPROM);

            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;

            // Most important value is the l_sbeTestSwitchSidesCountMseeprom, this is what gets set in this test
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            if ((l_sbeTestSwitchSidesCount != 0) || (l_sbeTestSwitchSidesCountMseeprom != 1) ||
                (l_sbeTestCurrentSideCount != 1) || (l_sbeTestCurrentSideCountMseeprom != 1) ||
                (l_sbeTestBootRestartCount != 0))
            {
                TS_FAIL("testSBEFlowREIPL_UPD_MSEEPROM failed to properly switch sides");
            }
            else
            {
                TS_INFO("testSBEFlowREIPL_UPD_MSEEPROM: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowREIPL_UPD_MSEEPROM: Testing SbeRetryHandler");
#endif
    }

    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEFlowRESTART_SBE_MAX_LIMITS(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE_MAX_LIMITS: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE_MAX_LIMITS: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowRESTART_SBE_MAX_LIMITS PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowRESTART_SBE_MAX_LIMITS skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);
            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_MAX_LIMITS);

            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // Most important value is the l_sbeTestSwitchSidesCountMseeprom, this is what gets set in this test
            // CurrentSideCount's are always initially set to 1 since we have booted on them already once
            if ((l_sbeTestSwitchSidesCount != 0) || (l_sbeTestSwitchSidesCountMseeprom != 1) ||
                (l_sbeTestCurrentSideCount != 2) || (l_sbeTestCurrentSideCountMseeprom != 2) ||
                (l_sbeTestBootRestartCount != 2))
            {
                TS_FAIL("testSBEFlowRESTART_SBE_MAX_LIMITS failed to properly handle MAX LIMITS");
            }
            else
            {
                TS_INFO("testSBEFlowRESTART_SBE_MAX_LIMITS: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowRESTART_SBE_MAX_LIMITS: Testing SbeRetryHandler");
#endif
    }


    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and test out
     *
     *        This will not run fully without a slave SBE
     *
     *        NOTE: This covers the case of recovery action REIPL_BKP_BMSEEPROM
     */
    void testSBEFlowRESTART_SBE_FAILURE(void)
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE_FAILURE: SKIPPING Testing SbeRetryHandler");
#else
        SBE_TRACF_RHT(ENTER_MRK"testSBEFlowRESTART_SBE_FAILURE: Testing SbeRetryHandler");
        // Get master proc target
        TARGETING::Target* l_pMasterProcTarget = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(
                        l_pMasterProcTarget);

        // Get a list of all procs
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        // Loop through CPU's
        for( const auto & l_cpu_target: l_cpuTargetList)
        {

            SBE_TRACF_RHT("testSBEFlowRESTART_SBE_FAILURE PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEFlowRESTART_SBE_FAILURE skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            uint8_t l_sbeTestSwitchSidesCount = 0;
            uint8_t l_sbeTestSwitchSidesCountMseeprom = 0;
            uint8_t l_sbeTestCurrentSideCount = 0;
            uint8_t l_sbeTestCurrentSideCountMseeprom = 0;
            uint8_t l_sbeTestBootRestartCount = 0;
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);
            l_SBEobj.setSBETestMode(SbeRetryHandler::SBE_FORCED_TEST_PATH::TEST_SBE_FAILURE);

            l_SBEobj.main_sbe_handler();

            l_sbeTestSwitchSidesCount = l_SBEobj.iv_switchSidesCount;
            l_sbeTestSwitchSidesCountMseeprom = l_SBEobj.iv_switchSidesCount_mseeprom;
            l_sbeTestCurrentSideCount = l_SBEobj.iv_currentSideBootAttempts;
            l_sbeTestCurrentSideCountMseeprom = l_SBEobj.iv_currentSideBootAttempts_mseeprom;
            l_sbeTestBootRestartCount = l_SBEobj.iv_boot_restart_count;

            // Most important values here are the SwitchSidesCount, CurrentSideCount and RestartCount
            // The flow would have switched sides on just the boot seeprom and
            // not the mseeprom and finally given up
            if ((l_sbeTestSwitchSidesCount != 1) || (l_sbeTestSwitchSidesCountMseeprom != 1) ||
                (l_sbeTestCurrentSideCount != 1) || (l_sbeTestCurrentSideCountMseeprom != 1) ||
                (l_sbeTestBootRestartCount != 2))
            {
                TS_FAIL("testSBEFlowRESTART_SBE_FAILURE failed to properly handle SBE Failures: "
                        "l_sbeTestSwitchSidesCount=%d, l_sbeTestSwitchSidesCountMseeprom=%d, "
                        "l_sbeTestCurrentSideCount=%d, l_sbeTestCurrentSideCountMseeprom=%d, "
                        "l_sbeTestBootRestartCount=%d",
                        l_sbeTestSwitchSidesCount, l_sbeTestSwitchSidesCountMseeprom,
                        l_sbeTestCurrentSideCount, l_sbeTestCurrentSideCountMseeprom,
                        l_sbeTestBootRestartCount);
            }
            else
            {
                TS_INFO("testSBEFlowRESTART_SBE_FAILURE: Success, returned from main_sbe_handler HUID=0x%X", get_huid(l_cpu_target));
            }

        }
        SBE_TRACF_RHT(EXIT_MRK"testSBEFlowRESTART_SBE_FAILURE: Testing SbeRetryHandler");
#endif
    }


    /**
     * @brief Call into sbe handler retry on the slave SBE,
     *        and ensure that we return back
     *
     *        This will not run fully without a slave SBE
     */
    void testSBEReturns(void)
    {
        SBE_TRACF_RHT(ENTER_MRK"testSBEReturns: Testing we come back from SbeRetryHandler");
        // Tests normal call return, no test overhead
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

            SBE_TRACF_RHT("testSBEReturns Working on PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEReturns skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.main_sbe_handler();

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
        // Tests normal call return, no test overhead

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

            SBE_TRACF_RHT("testSBEStarted Working on PROC HUID=0x%X", get_huid(l_cpu_target));
            if(l_cpu_target == l_pMasterProcTarget)
            {
                // we are just looking at Slave SBE's
                SBE_TRACF_RHT("testSBEStarted skipping PRIMARY PROC HUID=0x%X", get_huid(l_cpu_target));
                continue;
            }
            SBE_TRACF_RHT("testSBEStarted calling SbeRetryHandler SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT");
            SbeRetryHandler l_SBEobj = SbeRetryHandler(
                    l_cpu_target,
                    SbeRetryHandler::SBE_MODE_OF_OPERATION::ATTEMPT_REBOOT,
                    SbeRetryHandler::SBE_RESTART_METHOD::HRESET,
                    EMPTY_PLID,
                    NOT_INITIAL_POWERON);

            l_SBEobj.main_sbe_handler();

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

    /**
     *      * @brief Constructor
     */
    SbeRetryHandlerTest() : CxxTest::TestSuite()
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"SbeRetryHandlerTest SKIPPING Constructor");
#else
        errlHndl_t err = nullptr;
        bool sbe_loaded = false;

        SBE_TRACF_RHT(ENTER_MRK"SbeRetryHandlerTest Constructor");
        err = loadSbeModule(sbe_loaded);
        if(err)
        {
            TS_FAIL("SbeRetryHandlerTest() - Constuctor: failed to load modules");
            errlCommit( err, SBEIO_COMP_ID );
        }

        err = createSbeImageVmmSpace(VMM_VADDR_SBE_UPDATE);
        if(err)
        {
            TS_FAIL("SbeRetryHandlerTest() - Constructor: Call to createSbeImageVmmSpace() failed");
            errlCommit( err, SBEIO_COMP_ID );
        }
#endif

    };


    /**
     * @brief Destructor
     */
    ~SbeRetryHandlerTest()
    {
#ifndef CONFIG_COMPILE_CXXTEST_HOOKS
        SBE_TRACF_RHT(ENTER_MRK"SbeRetryHandlerTest SKIPPING Destructor");
#else
        SBE_TRACF_RHT(ENTER_MRK"SbeRetryHandlerTest Destructor");
        errlHndl_t err = nullptr;

        err = cleanupSbeImageVmmSpace(VMM_VADDR_SBE_UPDATE);
        if(err)
        {
            TS_FAIL("~SbeRetryHandlerTest() - Destructor: Call to cleanupSbeImageVmmSpace() failed.");
            errlCommit( err, SBEIO_COMP_ID );
        }

        err = unloadSbeModule();
        if(err)
        {
            TS_FAIL("~SbeRetryHandlerTest() - Destructor: failed to load modules");
            errlCommit( err, SBEIO_COMP_ID );
        }
#endif

    };

};
#endif
