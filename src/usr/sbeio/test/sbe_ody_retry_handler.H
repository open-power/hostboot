/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/test/sbe_ody_retry_handler.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
#ifndef __SBE_ODY_RETRY_HANDLER_H
#define __SBE_ODY_RETRY_HANDLER_H

/**
 *  @file sbe_ody_retry_handler.H
 *
 *  @brief Test cases for Odyssey Retry Handler
*/

#include <cxxtest/TestSuite.H>
#include <cxxtest/TestInject.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <sbe_getCodeLevels.H>
#include <ody_code_getlevels.H>
#include <targeting/odyutil.H>
#include <sbeio/sbe_retry_handler.H>

#define SBE_TRACD_ODY(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"odyRetryHandlerTest: " printf_string,##args)
#define SBE_TRACF_ODY(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"odyRetryHandlerTest: " printf_string,##args)

using namespace TARGETING;
using namespace ERRORLOG;
using namespace SBEIO;
using namespace CxxTest;

extern trace_desc_t* g_trac_sbeio;

/*******************************************************************************
 * class odyRetryHandlerTest
*******************************************************************************/
class OdySbeRetryHandlerTest : public TestSuite
{
  public:

        // Compile out this code because it uses data types from TestInject_defs.H
        //  and TestInject.C
        // Those data types are compiled out using this flag in those files, so this
        //  code must be compiled out also.

    /* @brief  Used to validate the results of a Testcase */
    enum expected_error_log_t
    {
        ERROR_LOG_NOT_EXPECTED,
        ERROR_LOG_EXPECTED,
    };

    /* @brief  Used to validate the results of a Testcase */
    enum expected_side_switch_t
    {
        SIDE_SWITCH_NOT_EXPECTED,
        SIDE_SWITCH_EXPECTED,
    };

    /* @brief  Used to track the running of a Testcase
     *         List of Odyssey hreset testcases for IPL and RUNTIME
     */
    enum testcase_t
    {
        TC_1_HRESET_DUMP=1,
        TC_2_HRESET,
        TC_3_HRESET_ody_sbe_hreset,
        TC_4_HRESET_ody_sppe_check_for_ready,
        TC_5_HRESET_sendAttrUpdateRequest,
        TC_6_HRESET_ThermalSensorPolling,
        TC_7_HRESET_FAIL,
        TC_8_HRESET,
    };

    /***************************************************************************
     * @brief  return the side which just booted
     *         if the CFAM read fails, just use the ATTR_SPPE_BOOT_SIDE value
     *
     * @param[in] i_target          odyssey being tested
     * @param[in] i_testcase        testcase being run
    ***************************************************************************/
    uint32_t getBootSide(TargetHandle_t i_target,
                         testcase_t     i_testcase)
    {
        uint32_t   l_attr_side   = i_target->getAttr<TARGETING::ATTR_SPPE_BOOT_SIDE>();
        uint32_t   l_return_side = l_attr_side;
        uint32_t   l_query_side  = 0;
        size_t     l_dataSize    = sizeof(l_query_side);
        errlHndl_t l_errl        = nullptr;

        l_errl = deviceRead(i_target,
                            &l_query_side, // contains a bit which tells the BOOT_SIDE
                            l_dataSize,
                            DEVICE_CFAM_ADDRESS(0x2808));
        if (l_errl)
        {
            TS_FAIL("testOdySbeRetryHandler: TC_%d 0x%x: failed to read boot side "
                    "addr:0x2808 via CFAM",
                    i_testcase, get_huid(i_target));
        }
        else
        {
            // ensure ATTR_SPPE_BOOT_SIDE matches what we read from SBE

            auto l_query_save = l_query_side;

            // this bit tells us the current boot side
            l_query_side = (l_query_side & 0x00002000) >> 13;

            TS_INFO("testOdySbeRetryHandler: TC_%d 0x%x: checking boot sides: "
                    "query_side:%d attr_side:%d query_data:0x%x",
                    i_testcase, get_huid(i_target),
                    l_query_side, l_attr_side, l_query_save);

            // verify that query_side == attr_side
            if (l_query_side != l_attr_side)
            {
                TS_FAIL("testOdySbeRetryHandler: TC_%d 0x%x: checking boot side matches: "
                        "query_side:%d != attr_side:%d query_data:0x%x",
                        i_testcase, get_huid(i_target),
                        l_query_side, l_attr_side, l_query_save);
            }
        }
        return l_return_side;
    }

    /***************************************************************************
     * @brief  Validate the results of an Ody hreset Testcase
     *
     * @param[in] i_expectErrl      is an error log expected from the test?
     * @param[in] i_expectSide      which side should be booted after the test?
     * @param[in] i_expectState     which ODY_RECOVERY_STATE exists after the test?
     * @param[in] i_testcase        which testcase was run
     * @param[in] i_target          which odyssey was tested
     * @param[in] i_errl            ptr to a log, if one was returned from the test
     **************************************************************************/
    void verifyResult(expected_error_log_t         i_expectErrl,
                      uint32_t                     i_expectSide,
                      ATTR_ODY_RECOVERY_STATE_type i_expectState,
                      testcase_t                   i_testcase,
                      TargetHandle_t               i_target,
                      errlHndl_t                   i_errl)
    {
        //----------------------------------------------------------------------
        // verify error log
        //----------------------------------------------------------------------
        if (i_expectErrl && !i_errl)
        {
            // a log was expected, but none exist
            TS_FAIL("testOdySbeRetryHandler: TC_%d 0x%x: Error log not found",
                    i_testcase, get_huid(i_target));
        }
        else if (!i_expectErrl && i_errl)
        {
            // a log was not expected, but one exists
            TS_FAIL("testOdySbeRetryHandler: TC_%d 0x%x: Unexpected Error log, rc:0x%x",
                    i_testcase, get_huid(i_target), ERRL_GETRC_SAFE(i_errl));
        }

        //----------------------------------------------------------------------
        // verify BOOT_SIDE
        //----------------------------------------------------------------------
        uint32_t l_boot_side = getBootSide(i_target, i_testcase);
        if (l_boot_side != i_expectSide)
        {
            TS_FAIL("testOdySbeRetryHandler: TC_%d: 0x%x : boot_side:%d != "
                    "i_expectSide:%d",
                    i_testcase, get_huid(i_target), l_boot_side, i_expectSide)
        }

        //----------------------------------------------------------------------
        // verify ODY_RECOVERY_STATE
        //----------------------------------------------------------------------
        ATTR_ODY_RECOVERY_STATE_type l_state = i_target->getAttr<ATTR_ODY_RECOVERY_STATE>();
        if (l_state != i_expectState)
        {
            TS_FAIL("testOdySbeRetryHandler: TC_%d: 0x%x : bad ODY_RECOVERY_STATE "
                    "state:%d != expectedState:%d",
                    i_testcase, get_huid(i_target), l_state, i_expectState);
        }

        //----------------------------------------------------------------------
        // commit error log as informational, if it exists
        //----------------------------------------------------------------------
        if (i_errl)
        {
            i_errl->setSev(ERRL_SEV_INFORMATIONAL);
            errlCommit(i_errl, CXXTEST_COMP_ID);
        }
    }

    /***************************************************************************
     * @brief  Run the steps for a Testcase
     *         1. set the injects, if requested
     *         2. set the expected boot side after the hreset
     *         2. execute the op
     *         3. verify the results (call TS_FAIL if appropriate)
     *         4. clear the inject bits
     *
     * @param[in] i_target         which odyssey to test
     * @param[in] i_testcase       which testcase is running
     * @param[in] i_inject1        if set, the first error inject bit for this test
     * @param[in] i_inject2        if set, the second error inject bit for this test
     * @param[in] i_inject3        if set, the second error inject bit for this test
     * @param[in] i_expectErrl     is an error log expected after the test?
     * @param[in] i_expectSide     which side should be booted after the test?
     * @param[in] i_expectState    which ODY_RECOVERY_STATE exists after the test?
     **************************************************************************/
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
    void runOdyRetryHandlerTest(TargetHandle_t               i_target,
                                testcase_t                   i_testcase,
                                CxxTestInjects               i_inject1,
                                CxxTestInjects               i_inject2,
                                CxxTestInjects               i_inject3,
                                expected_error_log_t         i_expectErrl,
                                expected_side_switch_t       i_expectSide,
                                ATTR_ODY_RECOVERY_STATE_type i_expectState)
    {
        TS_INFO("testOdySbeRetryHandler: TC_%d 0x%x", i_testcase, get_huid(i_target));
        getCodeLevelsResponse_t l_response{};
        errlHndl_t              l_errl = nullptr;

        //----------------------------------------------------------------------
        // SET THE INJECT BITS
        //----------------------------------------------------------------------
        if (i_inject1 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject1); // activate inject1
        }
        if (i_inject2 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject2); // activate inject2
        }
        if (i_inject3 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject3); // activate inject3
        }

        //----------------------------------------------------------------------
        // SET the expected boot side after the hreset
        //----------------------------------------------------------------------
        auto l_boot_side = getBootSide(i_target, i_testcase);
        if (i_expectSide == SIDE_SWITCH_EXPECTED)
        {
            // flip to expect the other side
            l_boot_side = !l_boot_side;
        }

        //----------------------------------------------------------------------
        // EXECUTE THE OP
        //----------------------------------------------------------------------
        l_errl = SBEIO::getFifoSbeCodeLevels(i_target, l_response);

        //----------------------------------------------------------------------
        // VERIFY THE RESULTS
        //----------------------------------------------------------------------
        verifyResult(i_expectErrl,        // do a TS_FAIL in here if appropriate
                     l_boot_side,
                     i_expectState,
                     i_testcase,
                     i_target,
                     l_errl);

        //----------------------------------------------------------------------
        // MAKE SURE THE INJECT BITS ARE CLEAR
        //----------------------------------------------------------------------
        if (i_inject1 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject1);
        }
        if (i_inject2 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject2);
        }
        if (i_inject3 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject3);
        }
    }
#endif // cxxhooks

    /**
     * @brief Test the Odyssey RetryHandler in IPL and HBRT
     */
    void testOdySbeRetryHandler(void)
    {
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        /*----------------------------------------------------------------------
          These testcases validate the Odyssey hreset paths.
            There are error injects during the hreset path on the current SIDE.
            This causes a side switch. Most testcases are then successful on the
            alternate side. One inject is done during the hreset on the alternate
            SIDE, which fails the hreset.

          Expectations:
            1. A FIFO TIMEOUT is injected to start the hreset
            2. IPL only has one hreset path, which is to pull a dump, and go DEAD
            3. HBRT does the full hreset, including side switching, if required
            4. No dump is actually pulled, since it kills the SBE. This code
               forces the dump pull to be skipped.

          IPL Testcases:
           TC_1_HRESET_DUMP                     timeout, hreset, dump, DEAD

          HBRT Testcases:
           TC_2_HRESET                          timeout, hreset, success
           TC_3_HRESET_ody_sbe_hreset           timeout, hreset error, switch, success
           TC_4_HRESET_ody_sppe_check_for_ready timeout, hreset error, switch, success
           TC_5_HRESET_sendAttrUpdateRequest    timeout, hreset error, switch, success
           TC_6_HRESET_ThermalSensorPolling     timeout, log info error, success
           TC_7_HRESET_FAIL                     timeout, hreset error, switch, hreset error, DEAD
           TC_8_HRESET                          timeout, hreset, success
         *--------------------------------------------------------------------*/

        TS_INFO("testOdySbeRetryHandler: Enter");

#if HB_TEMPORARY_REMOVE_THESE_TESTCASES

        TargetHandle_t   l_target = nullptr;
        TargetHandleList l_ocmbTargetList{};

        // get OCMBs, and use the first Odyssey in the list
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
        for (auto l_ocmb : l_ocmbTargetList)
        {
            if (UTIL::isOdysseyChip(l_ocmb))
            {
                l_target = l_ocmb;
                break;
            }
        }
        if (!l_target)
        {
            TS_INFO("testOdySbeRetryHandler: NO Odyssey targets found");
            goto EXIT;
        }

        // ensure these are clear
        g_cxxTestInject.clear(SBEIO_INJECT_FIFO_HANG);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sbe_hreset);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sppe_check_for_ready);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_sendAttrUpdateRequest);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ThermalSensorPolling);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_TWO_FAILS);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_SKIP_DUMP);

        // This flag only indicates that the SBEIO Testcases are running
        // It may be used to conditionally trace, or something similiar
        g_cxxTestInject.set(SBEIO_INJECT_IN_PROGRESS);

        // pre-check ATTR_ODY_RECOVERY_STATE
        if (l_target->getAttr<ATTR_ODY_RECOVERY_STATE>() != ODY_RECOVERY_STATUS_VIABLE)
        {
            TS_FAIL("testOdySbeRetryHandler: pre-check: bad ODY_RECOVERY_STATE:%d for 0x%x",
                    l_target->getAttr<ATTR_ODY_RECOVERY_STATE>(),
                    get_huid(l_target));
            goto EXIT;
        }

#ifndef __HOSTBOOT_RUNTIME

        // IPL testcase, hreset causes a dump, then DEAD state
        runOdyRetryHandlerTest(l_target,                      // ocmb target
                               TC_1_HRESET_DUMP,              // testcase name
                               SBEIO_INJECT_FIFO_HANG,        // first inject bit to set
                               SBEIO_INJECT_HRESET_SKIP_DUMP, // second inject bit to set
                               INJECT_NONE,                   // third inject bit to set
                               ERROR_LOG_EXPECTED,            // no log means chipop success
                               SIDE_SWITCH_NOT_EXPECTED,      // should hreset do a side switch
                               ODY_RECOVERY_STATUS_DEAD);     // state of SBE after hreset
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);

#else

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset and it works
        runOdyRetryHandlerTest(l_target,
                               TC_2_HRESET,
                               SBEIO_INJECT_FIFO_HANG,
                               INJECT_NONE,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_NOT_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset
        //  but in the hreset we fail ody_sbe_hreset
        //  which causes a side switch
        //  and then the hreset on the alternate side works
        runOdyRetryHandlerTest(l_target,
                               TC_3_HRESET_ody_sbe_hreset,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_ody_sbe_hreset,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset
        //  but in the hreset we fail ody_sppe_check_for_ready
        //  which causes a side switch
        //  and then the hreset on the alternate side works
        runOdyRetryHandlerTest(l_target,
                               TC_4_HRESET_ody_sppe_check_for_ready,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_ody_sppe_check_for_ready,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset
        //  but in the hreset we fail sendAttrUpdateRequest
        //  which causes a side switch
        //  and then the hreset on the alternate side works
        runOdyRetryHandlerTest(l_target,
                               TC_5_HRESET_sendAttrUpdateRequest,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_sendAttrUpdateRequest,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset
        //  but in the hreset we fail ThermalSensorPolling
        //  and then the hreset on the current side works
        runOdyRetryHandlerTest(l_target,
                               TC_6_HRESET_ThermalSensorPolling,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_ThermalSensorPolling,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_NOT_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset
        //  but in the hreset we fail ody_sppe_check_for_ready
        //  which causes a side switch
        //  and then the hreset runs on the alternate side
        //  but in the hreset we fail ody_sppe_check_for_ready
        //  and then the hreset fails and grabs a dump
        runOdyRetryHandlerTest(l_target,
                               TC_7_HRESET_FAIL,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_TWO_FAILS,
                               SBEIO_INJECT_HRESET_SKIP_DUMP,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_DEAD);
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);

        // inject FIFO TIMEOUT
        //  then OdySbeRetryHandler runs the hreset and it works
        //  (this testcase ensures the SBE is in a good state)
        runOdyRetryHandlerTest(l_target,
                               TC_8_HRESET,
                               SBEIO_INJECT_FIFO_HANG,
                               INJECT_NONE,
                               INJECT_NONE,
                               ERROR_LOG_EXPECTED,
                               SIDE_SWITCH_NOT_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);

#endif // runtime

    EXIT:
        // cleanup
        g_cxxTestInject.clear(SBEIO_INJECT_IN_PROGRESS);
        g_cxxTestInject.clear(SBEIO_INJECT_FIFO_HANG);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sbe_hreset);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sppe_check_for_ready);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_sendAttrUpdateRequest);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ThermalSensorPolling);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_TWO_FAILS);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_SKIP_DUMP);

#endif // temporary
        TS_INFO("testOdySbeRetryHandler: Exit");
#endif // cxxhooks
        return;
    }

    /**
     * @brief Run the Odyssey Recovery in IPL and HBRT
     */
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
    void runOdyRecoveryTest(TargetHandle_t                   i_target,
                                testcase_t                   i_testcase,
                                CxxTestInjects               i_inject1,
                                CxxTestInjects               i_inject2,
                                CxxTestInjects               i_inject3,
                                expected_error_log_t         i_expectErrl,
                                expected_side_switch_t       i_expectSide,
                                ATTR_ODY_RECOVERY_STATE_type i_expectState)
    {
        TS_INFO("runOdyRecoveryTest: TC_%d HUID=0x%X", i_testcase, get_huid(i_target));
        errlHndl_t              l_errl = nullptr;

        if (i_inject1 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject1); // activate inject1
        }
        if (i_inject2 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject2); // activate inject2
        }
        if (i_inject3 != INJECT_NONE)
        {
            g_cxxTestInject.set(i_inject3); // activate inject3
        }

        auto l_boot_side = getBootSide(i_target, i_testcase);
        if (i_expectSide == SIDE_SWITCH_EXPECTED)
        {
            // flip to expect the other side
            l_boot_side = !l_boot_side;
        }

        bool l_recovered = false;
        OdySbeRetryHandler l_SBEobj = OdySbeRetryHandler(i_target);
        l_recovered = l_SBEobj.odyssey_recovery_handler();

        verifyResult(i_expectErrl,        // do a TS_FAIL in here if appropriate
                     l_boot_side,
                     i_expectState,
                     i_testcase,
                     i_target,
                     l_errl);
        switch(i_testcase)
        {
            case TC_2_HRESET:
            case TC_4_HRESET_ody_sppe_check_for_ready:
            case TC_8_HRESET:
                if (l_recovered == true)
                {
                    TS_INFO("runOdyRecoveryTest TC=%d success", i_testcase);
                }
                else
                {
                    TS_FAIL("runOdyRecoveryTest TC=%d failed", i_testcase);
                }
                break;

            case TC_1_HRESET_DUMP:
            case TC_7_HRESET_FAIL:
                if (l_recovered == true)
                {
                    TS_FAIL("runOdyRecoveryTest TC=%d failed", i_testcase);
                }
                else
                {
                    TS_INFO("runOdyRecoveryTest TC=%d success", i_testcase);
                }
                break;
            default:
                TS_FAIL("runOdyRecoveryTest TC=%d UNEXPECTED", i_testcase);
        }

        if (i_inject1 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject1);
        }
        if (i_inject2 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject2);
        }
        if (i_inject3 != INJECT_NONE)
        {
            g_cxxTestInject.clear(i_inject3);
        }
    }
#endif // cxxhooks

    /**
     * @brief Test the Odyssey Recovery in IPL and HBRT
     */
    void testOdyRecovery(void)
    {
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        TS_INFO("testOdyRecovery: Enter");

#if HB_TEMPORARY_REMOVE_THESE_TESTCASES

        TargetHandle_t   l_target = nullptr;
        TargetHandleList l_ocmbTargetList{};

        // get OCMBs, and use the first Odyssey in the list
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
        for (auto l_ocmb : l_ocmbTargetList)
        {
            if (UTIL::isOdysseyChip(l_ocmb))
            {
                l_target = l_ocmb;
                break;
            }
        }
        if (!l_target)
        {
            TS_INFO("testOdyRecovery: NO Odyssey targets found");
            goto EXIT;
        }

        // ensure these are clear
        g_cxxTestInject.clear(SBEIO_INJECT_FIFO_HANG);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sbe_hreset);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sppe_check_for_ready);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_sendAttrUpdateRequest);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ThermalSensorPolling);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_TWO_FAILS);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_SKIP_DUMP);

        // This flag only indicates that the SBEIO Testcases are running
        // It may be used to conditionally trace, or something similiar
        g_cxxTestInject.set(SBEIO_INJECT_IN_PROGRESS);

        // pre-check ATTR_ODY_RECOVERY_STATE
        if (l_target->getAttr<ATTR_ODY_RECOVERY_STATE>() != ODY_RECOVERY_STATUS_VIABLE)
        {
            TS_FAIL("testOdyRecovery: pre-check: bad ODY_RECOVERY_STATE:%d for 0x%x",
                    l_target->getAttr<ATTR_ODY_RECOVERY_STATE>(),
                    get_huid(l_target));
            goto EXIT;
        }

#ifndef __HOSTBOOT_RUNTIME
        TS_INFO("testOdyRecovery: IPL Time");
        // IPL testcase is unsupported for the odyssey_recovery_handler, so this
        // tests the entry to odyssey_recovery_handler and NO operational changes,
        // i.e. still VIABLE since the inject was actually NOT performed
        // which would have modified the state to DEAD
        runOdyRecoveryTest(l_target,                          // ocmb target
                               TC_1_HRESET_DUMP,              // testcase name
                               SBEIO_INJECT_FIFO_HANG,        // first inject bit to set
                               SBEIO_INJECT_HRESET_SKIP_DUMP, // second inject bit to set
                               INJECT_NONE,                   // third inject bit to set
                               ERROR_LOG_NOT_EXPECTED,        // no log means chipop success
                               SIDE_SWITCH_NOT_EXPECTED,      // should hreset do a side switch
                               ODY_RECOVERY_STATUS_VIABLE);   // state of SBE after hreset
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);
#else
        TS_INFO("testOdyRecovery: RUNTIME");
        // inject FIFO TIMEOUT
        runOdyRecoveryTest(l_target,
                               TC_2_HRESET,
                               SBEIO_INJECT_FIFO_HANG,
                               INJECT_NONE,
                               INJECT_NONE,
                               ERROR_LOG_NOT_EXPECTED,
                               SIDE_SWITCH_NOT_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);

        runOdyRecoveryTest(l_target,
                               TC_4_HRESET_ody_sppe_check_for_ready,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_ody_sppe_check_for_ready,
                               INJECT_NONE,
                               ERROR_LOG_NOT_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);

        runOdyRecoveryTest(l_target,
                               TC_7_HRESET_FAIL,
                               SBEIO_INJECT_FIFO_HANG,
                               SBEIO_INJECT_HRESET_TWO_FAILS,
                               SBEIO_INJECT_HRESET_SKIP_DUMP,
                               ERROR_LOG_NOT_EXPECTED,
                               SIDE_SWITCH_EXPECTED,
                               ODY_RECOVERY_STATUS_DEAD);
        // force back to a good state
        l_target->setAttr<ATTR_ODY_RECOVERY_STATE>(ODY_RECOVERY_STATUS_VIABLE);

        //  (this testcase ensures the SBE is in a good state)
        runOdyRecoveryTest(l_target,
                               TC_8_HRESET,
                               SBEIO_INJECT_FIFO_HANG,
                               INJECT_NONE,
                               INJECT_NONE,
                               ERROR_LOG_NOT_EXPECTED,
                               SIDE_SWITCH_NOT_EXPECTED,
                               ODY_RECOVERY_STATUS_VIABLE);
#endif // runtime

    TS_INFO("testOdyRecovery: Executed TESTS");
    EXIT:
        // cleanup
        g_cxxTestInject.clear(SBEIO_INJECT_IN_PROGRESS);
        g_cxxTestInject.clear(SBEIO_INJECT_FIFO_HANG);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sbe_hreset);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ody_sppe_check_for_ready);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_sendAttrUpdateRequest);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_ThermalSensorPolling);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_TWO_FAILS);
        g_cxxTestInject.clear(SBEIO_INJECT_HRESET_SKIP_DUMP);

#endif // HB_TEMPORARY_REMOVE_THESE_TESTCASES

        TS_INFO("testOdyRecovery: Exit TESTS");
#endif // cxxhooks
        return;
    }

}; // class

#endif // ifndef
