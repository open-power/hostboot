/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/string.C $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2014                        */
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
	do
	{
	    ldest[--i] = lch;
	}
	while( i > 0 );
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

extern "C" void bzero(void *vdest, size_t len)
{
    memset(vdest, 0, len);
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

extern "C" void *memmem(const void *haystack, size_t haystacklen,
                        const void *needle, size_t needlelen)
{
    const void * result = NULL;

    if (haystacklen >= needlelen)
    {
        const char * c_haystack = static_cast<const char *>(haystack);
        const char * c_needle = static_cast<const char *>(needle);
        bool match = false;

        for (size_t i = 0; i <= (haystacklen - needlelen); i++)
        {
            match = true;

            for (size_t j = 0; j < needlelen; j++)
            {
                if (*(c_haystack + i + j) != *(c_needle + j))
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                result = (c_haystack + i);
                break;
            }
        }
    }

    return const_cast<void *>(result);
}


extern "C" char* strcpy(char* d, const char* s)
{
    char* d1 = d;

    do
    {
	*d1 = *s;
	if (*s == '\0') return d;
	d1++; s++;
    } while(1);
}

extern "C" char* strncpy(char* d, const char* s, size_t l)
{
    char* d1 = d;
    size_t len = 0;

    do
    {
        if (len++ >= l) break;
        *d1 = *s;
        if (*s == '\0') break;
        d1++; s++;
    } while(1);

    // pad the remainder
    while( len < l )
    {
        d1[len++] = '\0';
    }

    return d;
}

extern "C" int strcmp(const char* a, const char* b)
{
    while((*a != '\0') && (*b != '\0'))
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
	return 0;
    if (*a == '\0')
	return -1;
    else
	return 1;
}

extern "C" size_t strlen(const char* a)
{
    size_t length = 0;
    while(*a++)
    {
	length++;
    }
    return length;
}

extern "C" size_t strnlen(const char* s, size_t n)
{
    size_t length = 0;
    while((length < n) && (*s++))
    {
        length++;
    }
    return length;
}

extern "C" char* strcat(char* d, const char* s)
{
    char* _d = d;
    while(*_d)
    {
        _d++;
    }

    while(*s)
    {
        *_d = *s;
        _d++; s++;
    }
    *_d = '\0';

    return d;
}

extern "C" char* strncat(char* d, const char* s, size_t n)
{
    char* _d = d;
    while(*_d)
    {
        _d++;
    }

    while((*s) && (0 != n))
    {
        *_d = *s;
        _d++; s++;
        n--;
    }
    *_d = '\0';

    return d;
}


extern "C" char* strchr(const char* s, int c)
{
    while((*s != '\0') && (*s != c))
    {
        s++;
    }

    if (*s == c) return (char*)s;
    return NULL;
}

char* strdup(const char* s)
{
    return strcpy(static_cast<char*>(malloc(strlen(s)+1)), s);
}
