/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/crc32.C $                                             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#include <stdint.h>
#include <util/crc32.H>

namespace Util
{
    static const uint64_t CRC32_POLY = 0x104C11DB7ull;

    uint32_t crc32_calc(const void* ptr, size_t size)
    {
        const uint8_t* _ptr = (const uint8_t*)ptr;
        uint64_t crc = 0;
        while(size)
        {
            uint64_t data = 0;
            for (int i = 0; i < 4; ++i)
            {
                data <<= 8;
                if (size)
                {
                    data |= *(_ptr++);
                    --size;
                }
            }

            crc <<= 32;
            crc ^= (data << 32);


            int idx = 0;
            do
            {
                idx = __builtin_clzl(crc);
                if (idx < 32)
                {
                    crc ^= (CRC32_POLY << (31 - idx));
                }

            } while (idx < 32);
        }

        return crc;
    }

};

