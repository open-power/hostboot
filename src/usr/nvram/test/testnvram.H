/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/nvram/test/testnvram.H $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __TEST_NVRAM_H
#define __TEST_NVRAM_H

#include <cxxtest/TestSuite.H>
#include <nvram/import/nvram.h>
#include <stdlib.h>
#include <string.h>

class NvramTestSuite : public CxxTest::TestSuite
{
public:

    void testNvram() const
    {
        TS_INFO(ENTER_MRK"testNvram");

        const uint32_t NVRAM_SIZE = 0x90000;
        uint8_t* l_nvramImg = static_cast<uint8_t*>(malloc(NVRAM_SIZE));

        // Unformatted NVRAM - the check should fail
        int l_rc = nvram_check(l_nvramImg, NVRAM_SIZE);
        if(l_rc == 0)
        {
            TS_FAIL("testNvram: nvram_check returned clean on unformatted NVRAM");
        }

        // Format the memory area to look like NVRAM from skiboot perspective
        l_rc = nvram_format(l_nvramImg, NVRAM_SIZE);
        if(l_rc)
        {
            TS_FAIL("testNvram: could not nvram_format; rc = %d", l_rc);
        }

        // Now check it
        l_rc = nvram_check(l_nvramImg, NVRAM_SIZE);
        if(l_rc)
        {
            TS_FAIL("testNvram: nvram_check failed; rc = %d", l_rc);
        }

        char l_test_kv[] = "test=val";

        // Insert the test K/V right after the header
        memcpy(l_nvramImg + sizeof(chrp_nvram_hdr), l_test_kv,
               sizeof(l_test_kv)/sizeof(l_test_kv[0]));

        const char* l_key = "test";
        const char* l_expectedVal = "val";
        const char* l_val = nvram_query(l_key);
        if(!l_val)
        {
            TS_FAIL("testNvram: test key not found!");
        }
        else
        {
            if(strcmp(l_val, l_expectedVal))
            {
                TS_FAIL("testNvram: unexpected test value returned. Expected \"%s\", actual \"%s\"", l_expectedVal, l_val);
            }
        }

        const char* l_notExistingKey = "key_dne";
        l_val = nvram_query(l_notExistingKey);
        if(l_val)
        {
            TS_FAIL("testNvram: non-existing key found!");
        }

        free(l_nvramImg);
        l_nvramImg = nullptr;

        TS_INFO(EXIT_MRK"testNvram");
    }
};

#endif
