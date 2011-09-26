//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/lib/stdlib.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2010 - 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <kernel/heapmgr.H>
#include <kernel/pagemgr.H>
#include <kernel/console.H>


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
    return HeapManager::allocate(s);
}


void free(void* p)
{
    if (NULL == p) return;

    HeapManager::free(p);
}


void* realloc(void* p, size_t s)
{
    if (NULL == p) return malloc(s);

    return HeapManager::realloc(p,s);
}    

