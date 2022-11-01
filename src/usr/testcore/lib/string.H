/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/string.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
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
#ifndef __TESTCORE_LIB_STRING_H
#define __TESTCORE_LIB_STRING_H

#include <string.h>
#include <stdlib.h>

/** @file string.H
 *  @brief Test cases for the string.h system library header and
 *         strtoul from stdlib.h system library header.
 */

class StringTest : public CxxTest::TestSuite
{
    private:
        static const char * string1;
        static const char * string2;

    public:
        /**
         * Tests for strcat.
         */
        void testStrcat()
        {
            char a[64];

            size_t len1 = strlen(string1);

            strcpy(a, string1);
            strcat(a, string2);

            if (0 != memcmp(a, string1, len1))
            {
                TS_FAIL("strcat: String1 contents not copied properly.");
            }
            if (0 != strcmp(&a[len1], string2))
            {
                TS_FAIL("strcat: String2 contents not cat'd properly.");
            }
        }

        /**
         * Tests for strncat.
         */
        void testStrncat()
        {
            char a[64];
            memset(a, '\0', sizeof(a));

            size_t len1 = strlen(string1);

            strcpy(a, string1);
            strncat(a, string2, 7);

            if (0 != memcmp(a, string1, len1))
            {
                TS_FAIL("strncat: String1 contents not copied properly.");
            }
            if (0 != strcmp(&a[len1], "Another"))
            {
                TS_FAIL("strncat: String2 contents not cat'd properly.");
            }
        }

        /**
         * Tests for strcspn.
         */
        void testStrcspn()
        {
            size_t span = 0;

            span = strcspn(string1, "Ts.");
            if (span != 0)
            {
                TS_FAIL("strcspn: span incorrect for Ts. in string1.");
            }

            span = strcspn(string1, "s.");
            if (span != 3)
            {
                TS_FAIL("strcspn: span incorrect for s. in string1.");
            }

            span = strcspn(string1, ".");
            if (span != 16)
            {
                TS_FAIL("strcspn: span incorrect for . in string1.");
            }
        }

        /**
         * Tests for strstr.
         */
        void testStrstr()
        {
            const char * strPtr = nullptr;

            strPtr = strstr(string1, "string");
            if (0 != strcmp(strPtr, "string."))
            {
                TS_FAIL("strstr: string not found in string1");
            }

            strPtr = strstr(string1, " ");
            if (0 != strcmp(strPtr, " is a string."))
            {
                TS_FAIL("strstr: first string not found in string1");
            }

            strPtr = strstr(string2, "not found");
            if (strPtr != nullptr)
            {
                TS_FAIL("strstr: expected nullptr for string not found");
            }
        }

        /**
         * Tests for strtoul.
         */
        void testStrtoul()
        {
            const char * hexStr1  = "0x123456789ABCDEF0"; // hex with 0x
            const char * hexStr2  = "123456789ABCDEF0"; // hex no 0x
            const char * decStr   = "1311768467463790320"; // 0x123456789ABCDEF0
            const char * hexExtra = "0x12ABSomething"; // hex partial
            const char * decExtra = "123456Something"; // dec partial 0x1E240
            char * endptr;

            uint64_t result = 0;

            result = strtoul(hexStr1, nullptr, 16);
            if (result != 0x123456789ABCDEF0)
            {
                TS_FAIL("strtoul: 0xHEX conversion failed");
            }

            result = strtoul(hexStr2, nullptr, 16);
            if (result != 0x123456789ABCDEF0)
            {
                TS_FAIL("strtoul: HEX conversion failed");
            }

            result = strtoul(decStr, nullptr, 10);
            if (result != 0x123456789ABCDEF0)
            {
                TS_FAIL("strtoul: DEC conversion failed");
            }

            result = strtoul(hexExtra, &endptr, 16);
            if (result != 0x12AB)
            {
                TS_FAIL("strtoul: HEX extra string conversion failed");
            }
            if (endptr != hexExtra + 6)
            {
                TS_FAIL("strtoul: endptr check failed");
            }

            result = strtoul(decExtra, &endptr, 10);
            if (result != 0x1E240)
            {
                TS_FAIL("strtoul: DEC extra string conversion failed");
            }
            if (endptr != decExtra + 6)
            {
                TS_FAIL("strtoul: endptr check failed");
            }
        }
}; // end class StringTest : public CxxTest::TestSuite

const char * StringTest::string1 = "This is a string.";
const char * StringTest::string2 = "Another string am I.";


#endif
