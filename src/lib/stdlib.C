/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/stdlib.C $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <kernel/heapmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>
#include <assert.h>

#ifdef HOSTBOOT_MEMORY_LEAKS
#include <arch/ppc.H>

/** Memory allocation function type
 *
 *  These are used as parameters to the magic instruction so that the debug
 *  tools can determine what memory allocation function was being called.
 */
enum MemoryLeak_FunctionType
{
    MEMORYLEAK_MALLOC = 0,
    MEMORYLEAK_REALLOC = 1,
    MEMORYLEAK_FREE = 2
};

/** @fn memoryleak_magic_instruction
 *  @brief Triggers the simics memoryleak analysis magic hap-handler.
 *
 *  Arranges the memory allocation parameters into registers according to the
 *  Power ABI and triggers the magic instruction.  The ABI puts parameter 0-3
 *  into registers r3-r6.
 *
 *  Function attribute of "noinline" is required to ensure that the compiler
 *  treats this as a real function instead of attempting to inline it.  If it
 *  were to inline it then the parameters wouldn't end up in the right register.
 */
static void memoryleak_magic_instruction(MemoryLeak_FunctionType func,
                                         size_t size,
                                         void* ptr,
                                         void* ptr2) __attribute__((noinline));

static void memoryleak_magic_instruction(MemoryLeak_FunctionType func,
                                         size_t size,
                                         void* ptr,
                                         void* ptr2)
{
    // Newer GCC seems to optimize out the parameter placement unless we
    // fake them going into an assembly instruction.
    asm volatile("" :: "r"(func), "r"(size), "r"(ptr), "r"(ptr2));

    MAGIC_INSTRUCTION(MAGIC_MEMORYLEAK_FUNCTION);
    return;
}
#endif

#ifdef MEM_ALLOC_PROFILE
// alloc profile
uint16_t g_0 = 0;
uint16_t g_8 = 0;
uint16_t g_16 = 0;
uint16_t g_32 = 0;
uint16_t g_64 = 0;
uint16_t g_128 = 0;
uint16_t g_256 = 0;
uint16_t g_512 = 0;
uint16_t g_1k = 0;
uint16_t g_2k = 0;
uint16_t g_big = 0;
#endif

void* malloc(size_t s)
{
#ifdef MEM_ALLOC_PROFILE
    if(s == 0) ++g_0;
    else if (s <= 8) ++g_8;
    else if (s <= 16) ++g_16;
    else if (s <= 32) ++g_32;
    else if (s <= 64) ++g_64;
    else if (s <= 128) ++g_128;
    else if (s <= 256) ++g_256;
    else if (s <= 512) ++g_512;
    else if (s <= 1024) ++g_1k;
    else if (s <= 2048) ++g_2k;
    else ++g_big;
#endif

    void* result = HeapManager::allocate(s);

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_MALLOC, s, result, NULL);
#endif

    return result;
}

void free(void* p)
{
    if (nullptr == p)
    {
        return;
    }

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_FREE, 0, p, NULL);
#endif

    HeapManager::free(p);
}

void* realloc(void* p, size_t s)
{
    if (nullptr == p)
    {
        return malloc(s);
    }

    void* result = HeapManager::realloc(p,s);

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_REALLOC, s, result, p);
#endif

    return result;
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
