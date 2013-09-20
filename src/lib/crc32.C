/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/crc32.C $                                             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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

