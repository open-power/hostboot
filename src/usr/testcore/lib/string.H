/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/testcore/lib/string.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
