/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_stdlib.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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
#include <stdlib.h>
#include <runtime/interface.h>
#include <string.h>

void* malloc(size_t s)
{
    return g_hostInterfaces->malloc(s);
}

void free(void* p)
{
    g_hostInterfaces->free(p);
}

void* realloc(void* p, size_t s)
{
    return g_hostInterfaces->realloc(p, s);
}

void* calloc(size_t num, size_t size)
{
    // Allocate a block of memory for an array of 'num' elements, each of them
    // 'size' bytes long and initialize to zero
    size_t total_size = num * size;
    void* mem = NULL;

    if (total_size)
    {
        mem = malloc(total_size);
        memset(mem, 0, total_size);
    }

    return mem;
}

/**
 * Note: endptr is not currently supported
 */
uint64_t strtoul(const char *nptr, char **endptr, int base)
{
    uint64_t l_data = 0;
    size_t i = 0;

    crit_assert(base == 16);

    while( nptr[i] != '\0' )
    {
        uint64_t l_nib = 0;
        switch(nptr[i])
        {
            // handle leading '0x' or 'x'
            case('x'): case('X'):
                l_data = 0;
                break;
            case('0'): l_nib = 0; break;
            case('1'): l_nib = 1; break;
            case('2'): l_nib = 2; break;
            case('3'): l_nib = 3; break;
            case('4'): l_nib = 4; break;
            case('5'): l_nib = 5; break;
            case('6'): l_nib = 6; break;
            case('7'): l_nib = 7; break;
            case('8'): l_nib = 8; break;
            case('9'): l_nib = 9; break;
            case('A'): case('a'): l_nib = 0xA; break;
            case('B'): case('b'): l_nib = 0xB; break;
            case('C'): case('c'): l_nib = 0xC; break;
            case('D'): case('d'): l_nib = 0xD; break;
            case('E'): case('e'): l_nib = 0xE; break;
            case('F'): case('f'): l_nib = 0xF; break;
            default:
                return 0ULL;
        }
        l_data <<= 4;
        l_data |= l_nib;
        i++;
    }
    return l_data;
}
