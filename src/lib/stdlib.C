/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/stdlib.C $                                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2012              */
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
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <kernel/heapmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>

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
    if (NULL == p) return;

#ifdef HOSTBOOT_MEMORY_LEAKS
    memoryleak_magic_instruction(MEMORYLEAK_FREE, 0, p, NULL);
#endif

    HeapManager::free(p);
}


void* realloc(void* p, size_t s)
{
    if (NULL == p) return malloc(s);

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

