/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_stdlib.C $                                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2023                        */
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
#include <ctype.h>
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
 * Note: strtoul is also defined for ipl in lib/stdlib.C,
 *       any changes to this function should be mirrored there
 */
uint64_t strtoul(const char *nptr, char **endptr, int base)
{
    uint64_t l_data = 0;
    size_t i = 0;

    crit_assert((base == 10) || (base == 16));

    do
    {
        // Decimal
        if (base == 10)
        {
            while (nptr[i] != '\0')
            {
                // not dec then stop
                if (!isdigit(nptr[i]))
                {
                    break;
                }

                if (i > 0)
                {
                    l_data *= base;
                }

                l_data += nptr[i] - '0';

                i++;
            }
        } // base == 10

        // Hexadecimal
        else if (base == 16)
        {
            // handle the 'x' or '0x' first
            if ( (nptr[i] == 'x') ||
                 (nptr[i] == 'X') )
            {
                i++;
            }
            else if ( (nptr[i] == '0') &&
                    ( (nptr[i+1] == 'x') ||
                      (nptr[i+1] == 'X') ) )
            {
                i+=2;
            }

            while( nptr[i] != '\0' )
            {
                // not hex then stop
                if (!isxdigit(nptr[i]))
                {
                    break;
                }

                uint64_t l_nib = 0;
                switch(nptr[i])
                {
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
                    default: break; // should never get here
                }

                l_data <<= 4;
                l_data |= l_nib;

                i++;
            }
        } // base == 16
    } while(0);

    if (endptr != nullptr)
    {
        *endptr = const_cast<char*>(nptr) + i;
    }

    return l_data;
}
