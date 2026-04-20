/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/ext/test/hashDrbgTest.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2026                             */
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

#ifndef __HASHDRBGTEST_H
#define __HASHDRBGTEST_H

#include <cxxtest/TestSuite.H>
#include <secureboot/hash_drbg.H>
#include <secureboot/hash_drbg_test_data.H>
#include <secureboot/secure_reasoncodes.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <string.h>
#include <secureboot/secure_buffer.H>

class HashDrbgTest : public CxxTest::TestSuite
{
  public:
    /**
     * @brief Known-answer test for two consecutive 1024-bit Hash_DRBG outputs.
     */
    void testHashDrbgKnownAnswer()
    {
        TS_INFO(ENTER_MRK"testHashDrbgKnownAnswer()");

        using namespace SECUREBOOT;

        Hash_DRBG l_drbg;
        errlHndl_t l_errl = nullptr;

        uint8_t l_output_1[DRBG_TEST_REQUESTED_BYTES] = {};
        uint8_t l_output_2[DRBG_TEST_REQUESTED_BYTES] = {};

        l_errl = l_drbg.instantiate(TEST1_ENTROPY,
                                    sizeof(TEST1_ENTROPY),
                                    nullptr,
                                    0);
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer: instantiate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        l_errl = l_drbg.generate(l_output_1, sizeof(l_output_1));
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer: first generate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        if (memcmp(l_output_1, TEST1_EXPECTED_OUTPUT_1, sizeof(l_output_1)) != 0)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer: first output mismatch");
        }

        l_errl = l_drbg.generate(l_output_2, sizeof(l_output_2));
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer: second generate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        if (memcmp(l_output_2, TEST1_EXPECTED_OUTPUT_2, sizeof(l_output_2)) != 0)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer: second output mismatch");
        }

        l_drbg.uninstantiate();

        TS_INFO(EXIT_MRK"testHashDrbgKnownAnswer()");
    }

    /**
     * @brief Second known-answer test for two consecutive 1024-bit Hash_DRBG outputs
     *        with personalization string.
     */
    void testHashDrbgKnownAnswer2()
    {
        TS_INFO(ENTER_MRK"testHashDrbgKnownAnswer2()");

        using namespace SECUREBOOT;

        Hash_DRBG l_drbg;
        errlHndl_t l_errl = nullptr;

        uint8_t l_output_1[DRBG_TEST_REQUESTED_BYTES] = {};
        uint8_t l_output_2[DRBG_TEST_REQUESTED_BYTES] = {};

        l_errl = l_drbg.instantiate(TEST2_ENTROPY,
                                    sizeof(TEST2_ENTROPY),
                                    TEST2_PERSONALIZATION,
                                    sizeof(TEST2_PERSONALIZATION));
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer2: instantiate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        l_errl = l_drbg.generate(l_output_1, sizeof(l_output_1));
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer2: first generate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        if (memcmp(l_output_1, TEST2_EXPECTED_OUTPUT_1, sizeof(l_output_1)) != 0)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer2: first output mismatch");
        }

        l_errl = l_drbg.generate(l_output_2, sizeof(l_output_2));
        if (l_errl)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer2: second generate failed");
            errlCommit(l_errl, SECURE_COMP_ID);
            return;
        }

        if (memcmp(l_output_2, TEST2_EXPECTED_OUTPUT_2, sizeof(l_output_2)) != 0)
        {
            TS_FAIL("HashDrbgTest::testHashDrbgKnownAnswer2: second output mismatch");
        }

        l_drbg.uninstantiate();

        TS_INFO(EXIT_MRK"testHashDrbgKnownAnswer2()");
    }

    void testCleanBuffer()
    {
        TS_INFO(ENTER_MRK"testCleanBuffer()");

        const size_t BUF_SIZE = 32;

        // Test CLEAN_BUFFER_HEAP
        {
            uint8_t* heap_buf = new uint8_t[BUF_SIZE];

            // Fill buffer with non-zero data
            memset(heap_buf, 0xBB, BUF_SIZE);

            // Verify buffer is filled with non-zero data
            for (size_t i = 0; i < BUF_SIZE; i++)
            {
                if (heap_buf[i] == 0)
                {
                    TS_FAIL("testCleanBuffer: Failed to initialize heap buffer with non-zero data");
                    break;
                }
            }

            // Clean the buffer using CLEAN_BUFFER_HEAP macro
            CLEAN_BUFFER_HEAP(heap_buf, BUF_SIZE);

            // Verify pointer was set to nullptr
            if (heap_buf != nullptr)
            {
                TS_FAIL("testCleanBuffer: CLEAN_BUFFER_HEAP did not set pointer to nullptr");
            }

        }

        // Test CLEAN_BUFFER_STACK
        {
            uint8_t stack_buf[BUF_SIZE];

            // Fill buffer with non-zero data
            memset(stack_buf, 0xAA, BUF_SIZE);

            // Verify buffer is filled with non-zero data
            for (size_t i = 0; i < BUF_SIZE; i++)
            {
                if (stack_buf[i] == 0)
                {
                    TS_FAIL("testCleanBuffer: Failed to initialize stack buffer with non-zero data");
                    break;
                }
            }

            // Clean the buffer using CLEAN_BUFFER_STACK macro
            CLEAN_BUFFER_STACK(stack_buf, BUF_SIZE);

            // Verify buffer was zeroed (is_zero_assert in the macro will assert if not)
            // Additional explicit check for test verification
            for (size_t i = 0; i < BUF_SIZE; i++)
            {
                if (stack_buf[i] != 0)
                {
                    TS_FAIL("testCleanBuffer: CLEAN_BUFFER_STACK did not zero out the buffer");
                    break;
                }
            }

        }

        TS_INFO(EXIT_MRK"testCleanBuffer()");
    }
};

#endif
