/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilHash.H $                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2012              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef __UTIL_UTILHASH_H
#define __UTIL_UTILHASH_H

#include <stdint.h>

namespace Util
{
    inline uint32_t hashString(const char * i_str)
    {
        // This hash is a simple "n*s[0] + (n-1)*s[1] + ... + s[n-1]" algorithm,
        // where s[i] is a two byte chunk of the input string. It is currently
        // intended to return a 16-bit hash of the input string.

        uint32_t sumA = 0;
        uint32_t sumB = 0;
        uint32_t pos = 0;
        uint32_t val = 0;

        const uint32_t bytes = sizeof(uint16_t); // 16-bit hashing

        i_str--; // This looks weird but it is because of the do-while loop. We
                 // want it to loop through one more time when we have reached
                 // the end of the string (i.e. with the '\0' character).

        do
        {
            i_str++;

            if ('\0' != *i_str)
            {
                val <<= 8;
                val |= (uint8_t) *i_str;
                pos++;
            }
            else
            {
                while (bytes != pos)
                {
                    val <<= 8;
                    pos++;
                }
            }

            if (bytes == pos)
            {
                pos = 0;
                sumA += val;
                sumB += sumA;
                val = 0;
            }

        } while ('\0' != *i_str);

        return (sumB & 0xffff); // 16-bit hashing
    };

    inline uint32_t hashAdler32(const char * i_str)
    {
        uint32_t sumA = 1;
        uint32_t sumB = 0;
        while ('\0' != *i_str)
        {
            sumA += *i_str;
            sumB += sumA;

            sumA %= 65521;
            sumB %= 65521;

            i_str++;
        }
        return ((sumB << 16) | sumA) & 0x7FFFFFFF;
    };
};

#endif

