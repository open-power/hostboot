/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/string_utils.C $                                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
#include <string.h>
#include <stdlib.h>

extern "C" void *memset(void *vdest, int ch, size_t len)
{
    // TODO: align to an 8-byte boundary
    // Loop, storing 8 bytes every 3 instructions
    long *ldest = reinterpret_cast<long *>(vdest);
    if (len >= sizeof(long))
    {
        long lch = ch & 0xFF;
        lch |= lch<<8;
        lch |= lch<<16;
        lch |= lch<<32;
        size_t len8 = len / sizeof(long);
        size_t i = len8;
        do {
            ldest[--i] = lch;
        } while( i > 0 );
        ldest += len8;
        len -= len8 * sizeof(long);
    }

    // Loop, storing 1 byte every 3 instructions
    char *cdest = reinterpret_cast<char *>(ldest);
    while (len >= sizeof(char))
    {
        *cdest++ = ch;
        len -= sizeof(char);
    }

    return vdest;
}

extern "C" void *memcpy(void *vdest, const void *vsrc, size_t len)
{
    // TODO: align to an 8-byte boundary?

    // Loop, copying 8 bytes every 5 instructions (TODO: 8/4 should be possible)
    long *ldest = reinterpret_cast<long *>(vdest);
    const long *lsrc = reinterpret_cast<const long *>(vsrc);

    while (len >= sizeof(long))
    {
        *ldest++ = *lsrc++;
        len -= sizeof(long);
    }

    // Loop, copying 1 byte every 4 instructions
    char *cdest = reinterpret_cast<char *>(ldest);
    const char *csrc = reinterpret_cast<const char *>(lsrc);
    for (size_t i = 0; i < len; ++i)
    {
        cdest[i] = csrc[i];
    }

    return vdest;
}

#ifndef BOOTLOADER
extern "C" void *memmove(void *vdest, const void *vsrc, size_t len)
{
    // Copy first-to-last
    if (vdest <= vsrc)
    {
        return memcpy(vdest,vsrc,len);
    }

    // Copy last-to-first (TO_DO: optimize)
    char *dest = reinterpret_cast<char *>(vdest);
    const char *src = reinterpret_cast<const char *>(vsrc);
    for (size_t i = len; i > 0;)
    {
        --i;
        dest[i] = src[i];
    }

    return vdest;
}
#endif

extern "C" int memcmp(const void *p1, const void *p2, size_t len)
{
    const char *c1 = reinterpret_cast<const char *>(p1);
    const char *c2 = reinterpret_cast<const char *>(p2);

    for (size_t i = 0; i < len; ++i)
    {
        long n = static_cast<long>(c1[i]) - static_cast<long>(c2[i]);
        if (n != 0)
        {
            return n;
        }
    }

    return 0;
}

extern "C" int strncmp(const char* a, const char* b, size_t l)
{
    if(l==0)
    {
        return 0;
    }

    const char* begin=a;
    while(   (*a != '\0') && (*b != '\0')
          && (static_cast<size_t>(a-begin)+1<l) )
    {
        if (*a == *b)
        {
            a++; b++;
        }
        else
        {
            return (*a > *b) ? 1 : -1;
        }
    }
    if (*a == *b)
    {
        return 0;
    }
    if (*a == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

extern "C" char* strncpy(char* d, const char* s, size_t l)
{
    char* d1 = d;
    while ( (l > 0) && (*s != '\0') )
    {
        *d1++ = *s++;
        --l;
    }

    // pad the remainder
    while (l > 0)
    {
        *d1++ = '\0';
        --l;
    }

    return d;
}

