/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/util/UtilHash.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2004,2014              */
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

#ifndef __UTIL_UTILHASH_H
#define __UTIL_UTILHASH_H

#include <stdint.h>

namespace PRDF
{

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

} // end namespace PRDF

#endif

