/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/testcore/lib/string.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

/** @file string.H
 *  @brief Test cases for the string.h system library header.
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
};

const char * StringTest::string1 = "This is a string.";
const char * StringTest::string2 = "Another string am I.";


#endif
