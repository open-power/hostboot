/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/pir/test_pirformat.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __TEST_PIRFORMAT_H
#define __TEST_PIRFORMAT_H

/**
 *  @file test_pirformat.H
 *  @brief Tests pirformat structure and utility functions
 */

#include <cxxtest/TestSuite.H>
#include <arch/pirformat.H>
#include <errl/errlmanager.H>

trace_desc_t* g_trac_pir = NULL;
TRAC_INIT(&g_trac_pir, "PIR_TEST", KILOBYTE);

class PirformatTest: public CxxTest::TestSuite
{
  public:

    void testPirformat(void)
    {
        TRACFCOMP(g_trac_pir, ENTER_MRK
            "testPirformat> start" );

        PIR_t zeroPir      = PIR_t(0);
        PIR_t otherZeroPir = PIR_t(0, 0, 0, 0);

        if ((PIR_t::groupFromPir(zeroPir.word)
                              != PIR_t::groupFromPir(otherZeroPir.word))
            || (PIR_t::chipFromPir(zeroPir.word)
                              != PIR_t::chipFromPir(otherZeroPir.word))
            || (PIR_t::threadFromPir(zeroPir.word)
                              != PIR_t::threadFromPir(otherZeroPir.word)))
        {
            TS_FAIL("Zero PIR constructors not equivalent.");

        }

        //Test with some arbitrary values
        TRACFCOMP(g_trac_pir, ENTER_MRK
            "testPirformat: Test with 1,2,5,3 values");
        testPirformat(1,2,5,3);

        //Test with 'max' values
        TRACFCOMP(g_trac_pir, ENTER_MRK
            "testPirformat: Test with 15,7,31,3 values");
        testPirformat(15,7,31,3);

        TRACFCOMP(g_trac_pir, ENTER_MRK
                "testPirformat> finish" );

    }


    void testPirformat(uint32_t i_group, uint32_t i_chip,
                       uint32_t i_core,  uint32_t i_thread)
    {

        //Test PIR with various values and the "fromPir" helpers
        uint32_t GROUP_TEST_VAL = i_group;
        uint32_t CHIP_TEST_VAL = i_chip;
        uint32_t CORE_TEST_VAL = i_core;
        uint32_t THREAD_TEST_VAL = i_thread;
        PIR_t test1 = PIR_t(GROUP_TEST_VAL, CHIP_TEST_VAL,
                            CORE_TEST_VAL,  THREAD_TEST_VAL);

        if (  (test1.groupId != PIR_t::groupFromPir(test1.word))
            || (test1.groupId != GROUP_TEST_VAL))
        {
            TS_FAIL("Group constructors or fromPir helper not working.");
        }

        if (  (test1.chipId != PIR_t::chipFromPir(test1.word))
             || (test1.chipId != CHIP_TEST_VAL))
        {
            TS_FAIL("Chip constructors or fromPir helper not working.");
        }

        if (  (test1.coreId != PIR_t::coreFromPir(test1.word))
             || (test1.coreId != CORE_TEST_VAL))
        {
            TS_FAIL("Core constructors or fromPir helper not working.");
        }

        if (  (test1.threadId != PIR_t::threadFromPir(test1.word))
             || (test1.threadId != THREAD_TEST_VAL))
        {
            TS_FAIL("Thread constructors or helpers not working.");
        }

        //Test masks + 'AFTER' constants
        if (((test1.word & PIR_t::GROUP_MASK) >> PIR_t::BITS_AFTER_GROUP)
                 != GROUP_TEST_VAL)
        {
            TS_FAIL("GROUP_MASK or BITS_AFTER_GROUP not correct.");
        }

        if (((test1.word & PIR_t::CHIP_MASK) >> PIR_t::BITS_AFTER_CHIP)
                 != CHIP_TEST_VAL)
        {
            TS_FAIL("CHIP_MASK or BITS_AFTER_CHIP not correct.");
        }

        if (((test1.word & PIR_t::CORE_MASK) >> PIR_t::BITS_AFTER_CORE)
                 != CORE_TEST_VAL)
        {
            TS_FAIL("CORE_MASK or BITS_AFTER_CORE not correct.");
        }

        if (((test1.word & PIR_t::THREAD_MASK) >> PIR_t::BITS_AFTER_THREAD)
                 != THREAD_TEST_VAL)
        {
            TS_FAIL("THREAD_MASK or BITS_AFTER_THREAD not correct.");
        }

        //Test Core ID Constructors and helpers
        uint32_t coreId0 = PIR_t::createCoreId( GROUP_TEST_VAL,
                                                CHIP_TEST_VAL,
                                                CORE_TEST_VAL );

        uint32_t coreId1 = PIR_t::createCoreId( CHIP_TEST_VAL,
                                                CORE_TEST_VAL );

        if (PIR_t::groupFromCoreId(coreId0) != GROUP_TEST_VAL)
        {
            TRACFCOMP(g_trac_pir, "Value from helper: 0x%x, not equal to known group value: 0x%x",
                      PIR_t::groupFromCoreId(coreId0), GROUP_TEST_VAL);
            TS_FAIL("Group from CoreID not correct.");
        }

        if ( (PIR_t::chipFromCoreId(coreId0) != CHIP_TEST_VAL)
             || (PIR_t::chipFromCoreId(coreId1) != CHIP_TEST_VAL))
        {
            TRACFCOMP(g_trac_pir, "Value from helper: 0x%x, not equal to known chip value: 0x%x",
                      PIR_t::chipFromCoreId(coreId0), CHIP_TEST_VAL);
            TRACFCOMP(g_trac_pir, "OR - Value from helper: 0x%x, not equal to known chip value: 0x%x",
                      PIR_t::chipFromCoreId(coreId1), CHIP_TEST_VAL);
                TS_FAIL("Chip from CoreID not correct.");
        }

        if ( (PIR_t::coreFromCoreId(coreId0) != CORE_TEST_VAL)
             || (PIR_t::coreFromCoreId(coreId1) != CORE_TEST_VAL))
        {
            TRACFCOMP(g_trac_pir, "Value from helper: 0x%x, not equal to known core value: 0x%x",
                      PIR_t::coreFromCoreId(coreId0), CORE_TEST_VAL);
            TRACFCOMP(g_trac_pir, "OR - Value from helper: 0x%x, not equal to known core value: 0x%x",
                      PIR_t::coreFromCoreId(coreId1), CORE_TEST_VAL);
            TS_FAIL("Core from CoreID not correct.");
        }

        //Test Chip ID Constructors and helpers
        uint32_t chipId = PIR_t::createChipId( GROUP_TEST_VAL,
                                               CHIP_TEST_VAL );

        if (PIR_t::groupFromChipId(chipId) != GROUP_TEST_VAL)
        {
            TRACFCOMP(g_trac_pir, "Value from helper: 0x%x, not equal to known group value: 0x%x",
                      PIR_t::groupFromChipId(chipId), GROUP_TEST_VAL);
            TS_FAIL("Group from ChipID not correct.");
        }

        if (PIR_t::chipFromChipId(chipId) != CHIP_TEST_VAL)
        {
            TRACFCOMP(g_trac_pir, "Value from helper: 0x%x, not equal to known group value: 0x%x",
                      PIR_t::chipFromChipId(chipId), CHIP_TEST_VAL);
            TS_FAIL("Chip from ChipID not correct.");
        }
    }

};

#endif

