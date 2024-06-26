/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/test/mmiotest_common.H $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2024                        */
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
 *  @file mmiotest_common.H
 *
 *  @brief Common defines and testcases for MMIO CI
 */
#ifndef __MMIOTEST_COMMON_H
#define __MMIOTEST_COMMON_H

#include <cxxtest/TestSuite.H>
#include <cxxtest/TestInject.H>
#include <devicefw/driverif.H>
#include <targeting/odyutil.H>
#include <errl/errlmanager.H>
#include <mmio/mmio.H>
#include <mmio/mmio_ocmb_common.H>
#include <ody_oc_regs.H>

#include <sbeio/sbe_getCodeLevels.H>
#include <ody_code_getlevels.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace CxxTest;

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
   // Compile out this code because it uses data types from TestInject_defs.H
   //  and TestInject.C
   // Those data types are compiled out using this flag in those files, so this
   //  code must be compiled out also.

/**
 * @brief  Turn on inband mmio and PIPE
 */
void enableMmioFlags(TargetHandle_t i_target)
{
    ScomSwitches l_switches;
    l_switches               = i_target->getAttr<ATTR_SCOM_SWITCHES>();
    l_switches.useInbandScom = 1;
    l_switches.useSbeScom    = 0;
    i_target->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
    i_target->setAttr<ATTR_USE_PIPE_FIFO>(1);
}

/* @brief  Used to validate the results of a Testcase */
enum expected_error_log_t
{
    ERROR_LOG_NOT_EXPECTED,  // The Testcase op is expected to succeed
    ERROR_LOG_EXPECTED       // The Testcase op is expected to fail
};

/* @brief  Used to validate the results of a Testcase */
enum expected_switches_t
{
    SWITCHES_INBAND,  // The switches after the testcase are set to inband
    SWITCHES_CFAM     // The switches after the testcase are set to CFAM
};

/* @brief  Used to validate the results of a Testcase */
enum testcase_op_t
{
    READ_OP,      // config space read
    WRITE_OP,     // config space write
    CHIP_OP       // FIFO chip op
};

/* @brief  Used to track the running of a Testcase
 *         List of Odyssey MMIO testcases for IPL and RUNTIME
 */
enum testcase_t
{
    TC1_INBAND_READ=1,
    TC2_INBAND_READ_INJECT_UE,
    TC3_INBAND_READ_INJECT_CHECKSTOP,
    TC4_CFAM_READ,
    TC5_INBAND_WRITE,
    TC6_INBAND_WRITE_INJECT,
    TC7_INBAND_WRITE_INJECT_CHECKSTOP,
    TC8_CFAM_WRITE,
    TC9_INBAND_CHIPOP,
    TC10_INBAND_CHIPOP_UE,
    TC11_INBAND_CHIPOP
};

/*******************************************************************************
 * @brief  Validate the results of an Ody MMIO Testcase
 *
 * @param[in] i_expectErrl      is an error log expected from the test?
 * @param[in] i_expectSwitches  how should the switches be set now, after the test?
 * @param[in] i_testcase        which testcase was run
 * @param[in] i_target          which odyssey was tested
 * @param[in] i_errl            ptr to a log, if one was returned from the test
 ******************************************************************************/
void verifyResult(expected_error_log_t i_expectErrl,
                  expected_switches_t  i_expectSwitches,
                  testcase_t           i_testcase,
                  TargetHandle_t       i_target,
                  errlHndl_t           i_errl)
{
    if (i_expectErrl && !i_errl)
    {
        // a log was expected, but none exist
        TS_FAIL("runOdyMmioTestcase: TC_%d 0x%x: Error log not found",
                i_testcase, get_huid(i_target));
    }
    else if (!i_expectErrl && i_errl)
    {
        // a log was not expected, but one exists
        TS_FAIL("runOdyMmioTestcase: TC_%d 0x%x: Unexpected Error log, rc:0x%x",
                i_testcase, get_huid(i_target), ERRL_GETRC_SAFE(i_errl));
    }

    ScomSwitches l_switches    = i_target->getAttr<ATTR_SCOM_SWITCHES>();
    auto         l_usePipeFifo = i_target->getAttr<ATTR_USE_PIPE_FIFO>();

    if ( (i_expectSwitches == SWITCHES_INBAND) &&
         (l_switches.useSbeScom || !l_switches.useInbandScom || !l_usePipeFifo) )
    {
        // Inband was expected, but not all the switches are correct
        TS_FAIL("runOdyMmioTestcase: TC_%d 0x%x: switches should be Inband "
                "useSbeScom:%d useInbandScom:%d ATTR_USE_PIPE_FIFO:%d",
                i_testcase, get_huid(i_target),
                l_switches.useSbeScom, l_switches.useInbandScom, l_usePipeFifo);
    }
    if ( (i_expectSwitches == SWITCHES_CFAM) &&
         (!l_switches.useSbeScom || l_switches.useInbandScom || l_usePipeFifo) )
    {
        // CFAM was expected, but not all the switches are correct
        TS_FAIL("runOdyMmioTestcase: TC_%d 0x%x: switches should be CFAM "
                "useSbeScom:%d useInbandScom:%d ATTR_USE_PIPE_FIFO:%d",
                i_testcase, get_huid(i_target),
                l_switches.useSbeScom, l_switches.useInbandScom, l_usePipeFifo);
    }

    if (i_errl)
    {
        // commit the log if it exists
        i_errl->setSev(ERRL_SEV_INFORMATIONAL);
        errlCommit(i_errl, CXXTEST_COMP_ID);
    }
}

/*******************************************************************************
 * @brief  Run the steps for a Testcase
 *         1. set the injects, if requested
 *         2. execute the op
 *         3. verify the results (call TS_FAIL if appropriate)
 *         4. clear the injects
 *
 * @param[in] i_target          which odyssey to test
 * @param[in] i_testcase        which testcase is running
 * @param[in] i_op              which op to run
 * @param[in] i_inject1         if set, the first error inject bit for this test
 * @param[in] i_inject2         if set, the second error inject bit for this test
 * @param[in] i_expectErrl      is an error log expected from the test?
 * @param[in] i_expectSwitches  how should the switches be set now, after the test?
 ******************************************************************************/
void runOdyMmioTestcase(TargetHandle_t       i_target,
                        testcase_t           i_testcase,
                        testcase_op_t        i_op,
                        CxxTestInjects       i_inject1,
                        CxxTestInjects       i_inject2,
                        expected_error_log_t i_expectErrl,
                        expected_switches_t  i_expectSwitches)
{
    getCodeLevelsResponse_t l_response{};
    errlHndl_t              l_errl      = nullptr;
    uint32_t                l_regdata4  = 0;
    size_t                  l_op_size   = sizeof(l_regdata4);
    uint64_t                l_rd_offset = ODY_OC_O0MBIT_O0DID_LSB;
    uint64_t                l_wr_offset = ODY_OC_O0CCD_LSB;

#ifdef __HOSTBOOT_RUNTIME
    l_rd_offset += MMIOCOMMON::OCMB_IB_MMIO_OFFSET;
    l_wr_offset += MMIOCOMMON::OCMB_IB_MMIO_OFFSET;
#endif

    TS_INFO("runOdyMmioTestcase: TC_%d 0x%x", i_testcase, get_huid(i_target));

    //--------------------------------------------------------------------------
    // SET THE INJECT BITS
    //--------------------------------------------------------------------------
    if (i_inject1 != INJECT_NONE)
    {
        g_cxxTestInject.set(i_inject1); // activate inject1
    }
    if (i_inject2 != INJECT_NONE)
    {
        g_cxxTestInject.set(i_inject2); // activate inject2
    }

    //--------------------------------------------------------------------------
    // EXECUTE THE OP
    //--------------------------------------------------------------------------
    if (i_op == READ_OP)
    {
        // valid read from config space register
        l_errl = DeviceFW::deviceRead(
                     i_target,
                     &l_regdata4,
                     l_op_size,
                     DEVICE_MMIO_ADDRESS(l_rd_offset,l_op_size));
    }
    else if (i_op == WRITE_OP)
    {
        // valid write to config space register
        l_errl = DeviceFW::deviceWrite(
                          i_target,
                          &l_regdata4,
                          l_op_size,
                          DEVICE_MMIO_ADDRESS(l_wr_offset,l_op_size));
    }
    else if (i_op == CHIP_OP)
    {
        l_errl = SBEIO::getFifoSbeCodeLevels(i_target, l_response);
    }

    //--------------------------------------------------------------------------
    // VERIFY THE RESULTS
    //--------------------------------------------------------------------------
    verifyResult(i_expectErrl,      // do a TS_FAIL in here if appropriate
                 i_expectSwitches,
                 i_testcase,
                 i_target,
                 l_errl);

    //--------------------------------------------------------------------------
    // MAKE SURE THE INJECT BITS ARE CLEAR
    //--------------------------------------------------------------------------
    if (i_inject1 != INJECT_NONE)
    {
        g_cxxTestInject.clear(i_inject1);
    }
    if (i_inject2 != INJECT_NONE)
    {
        g_cxxTestInject.clear(i_inject2);
    }
}

/*******************************************************************************
 * @brief  Run the common MMIO CI test code for IPL/RUNTIME
 ******************************************************************************/
void runOdyMmioCI()
{
    /*--------------------------------------------------------------------------
      These testcases run ops to two different paths.
        1. inband r/w and inband PIPE Fifo (MMIO via OMI bus)
        2. CFAM r/w and SPPE CFAM Fifo

      Expectations:
        1. A checkstop during an inband r/w disables inband r/w and the PIPE Fifo (OMI bus failure)
        2. An inband error does not bring down CFAM r/w nor SPPE CFAM Fifo
        3. These testcases do not disrupt either Fifo. The injects are done via
           bad return status, not by writing registers or leaving registers in a
           bad state.
        4. The testcases must be run in order, as they are dependent on previous results

     *After each testcase is run, we validate the switches are set correctly.
     *The switches must be reset after errors to run other testcases.

        TC1_INBAND_READ                    good path, expect success
        TC2_INBAND_READ_INJECT_UE          expect error, but no switch flipping
        TC3_INBAND_READ_INJECT_CHECKSTOP   expect inband and PIPE to be disabled
        TC4_CFAM_READ                      good path, expect success
        *re-enable inband
        TC5_INBAND_WRITE                   good path, expect success
        TC6_INBAND_WRITE_INJECT            expect error, but no switch flipping
        TC7_INBAND_WRITE_INJECT_CHECKSTOP  expect inband and PIPE to be disabled
        TC8_CFAM_WRITE                     good path, expect success
        *re-enable inband
        TC9_INBAND_CHIPOP                  good path, expect success
        TC10_INBAND_CHIPOP_UE              expect error, but no switch flipping
        TC11_INBAND_CHIPOP                 good path, expect success

     *------------------------------------------------------------------------*/

    TS_INFO("runOdyMmioCI: Enter");

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
        TS_INFO("runOdyMmioCI: NO Odyssey targets found");
        goto EXIT;
    }

    // initialize the switches to enable mmio and PIPE
    enableMmioFlags(l_target);

    // ensure these are clear
    g_cxxTestInject.clear(MMIO_INJECT_OP_ERROR);
    g_cxxTestInject.clear(MMIO_INJECT_CHECKSTOP);

    // This flag only indicates that the MMIO Testcases are running
    // It may be used to conditionally trace, or something similiar
    g_cxxTestInject.set(MMIO_INJECT_IN_PROGRESS);

    runOdyMmioTestcase(l_target,               // ocmb target
                       TC1_INBAND_READ,        // testcase name
                       READ_OP,                // op to run
                       INJECT_NONE,            // first inject to set
                       INJECT_NONE,            // second inject to set
                       ERROR_LOG_NOT_EXPECTED, // no log means op success is expected
                       SWITCHES_INBAND);       // after testcase, switches should be inband

    runOdyMmioTestcase(l_target,
                       TC2_INBAND_READ_INJECT_UE,
                       READ_OP,
                       MMIO_INJECT_OP_ERROR,
                       INJECT_NONE,
                       ERROR_LOG_EXPECTED,
                       SWITCHES_INBAND);

    runOdyMmioTestcase(l_target,
                       TC3_INBAND_READ_INJECT_CHECKSTOP,
                       READ_OP,
                       MMIO_INJECT_OP_ERROR,
                       MMIO_INJECT_CHECKSTOP,
                       ERROR_LOG_EXPECTED,
                       SWITCHES_CFAM);

    runOdyMmioTestcase(l_target,
                       TC4_CFAM_READ,
                       READ_OP,
                       INJECT_NONE,
                       INJECT_NONE,
                       ERROR_LOG_NOT_EXPECTED,
                       SWITCHES_CFAM);

    TS_INFO("runOdyMmioCI: Re-enable MMIO and PIPE 0x%x", get_huid(l_target));
    enableMmioFlags(l_target);

    runOdyMmioTestcase(l_target,
                       TC5_INBAND_WRITE,
                       WRITE_OP,
                       INJECT_NONE,
                       INJECT_NONE,
                       ERROR_LOG_NOT_EXPECTED,
                       SWITCHES_INBAND);

    runOdyMmioTestcase(l_target,
                       TC6_INBAND_WRITE_INJECT,
                       WRITE_OP,
                       MMIO_INJECT_OP_ERROR,
                       INJECT_NONE,
                       ERROR_LOG_EXPECTED,
                       SWITCHES_INBAND);

    runOdyMmioTestcase(l_target,
                       TC7_INBAND_WRITE_INJECT_CHECKSTOP,
                       WRITE_OP,
                       MMIO_INJECT_OP_ERROR,
                       MMIO_INJECT_CHECKSTOP,
                       ERROR_LOG_EXPECTED,
                       SWITCHES_CFAM);

    runOdyMmioTestcase(l_target,
                       TC8_CFAM_WRITE,
                       WRITE_OP,
                       INJECT_NONE,
                       INJECT_NONE,
                       ERROR_LOG_NOT_EXPECTED,
                       SWITCHES_CFAM);

    TS_INFO("runOdyMmioCI: Re-enable MMIO and PIPE 0x%x", get_huid(l_target));
    enableMmioFlags(l_target);

#if 0 //fixme
    runOdyMmioTestcase(l_target,
                       TC9_INBAND_CHIPOP,
                       CHIP_OP,
                       INJECT_NONE,
                       INJECT_NONE,
                       ERROR_LOG_NOT_EXPECTED,
                       SWITCHES_INBAND);
#endif

    runOdyMmioTestcase(l_target,
                       TC10_INBAND_CHIPOP_UE,
                       CHIP_OP,
                       MMIO_INJECT_OP_ERROR,
                       INJECT_NONE,
                       ERROR_LOG_EXPECTED,
                       SWITCHES_INBAND);

    runOdyMmioTestcase(l_target,
                       TC11_INBAND_CHIPOP,
                       READ_OP,
                       INJECT_NONE,
                       INJECT_NONE,
                       ERROR_LOG_NOT_EXPECTED,
                       SWITCHES_INBAND);

    // cleanup
    enableMmioFlags(l_target);
    g_cxxTestInject.clear(MMIO_INJECT_OP_ERROR);
    g_cxxTestInject.clear(MMIO_INJECT_CHECKSTOP);

    EXIT:
    TS_INFO("runOdyMmioCI: Exit 0x%x", get_huid(l_target));

    return;
}

#else
void runOdyMmioCI() {return;}
#endif  // CONFIG_COMPILE_CXXTEST_HOOKS

#endif  // __MMIOTEST_COMMON_H
