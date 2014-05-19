/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/libc++/builtins.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#include <stdlib.h>

#include <arch/ppc.H>
#include <util/locked/list.H>
#include <sys/sync.h>

void* operator new(size_t s)
{
    return malloc(s);
};

void* operator new[](size_t s)
{
    return malloc(s);
};

void* operator new(size_t s, void *place)
{
    return place;
}

void* operator new[](size_t s, void *place)
{
    return place;
}

void operator delete(void* p)
{
    return free(p);
};

void operator delete[](void* p)
{
    return free(p);
};

extern "C" int __cxa_guard_acquire(volatile uint64_t* gv)
{
    // States:
    //     0 -> uninitialized
    //     1 -> locked
    //     2 -> unlocked and initialized

    uint32_t v = __sync_val_compare_and_swap((volatile uint32_t*)gv, 0, 1);
    if (v == 0)
	return 1;
    if (v == 2)
	return 0;

    // Wait for peer thread to perform initialization (state 2).
    while(2 != *(volatile uint32_t*)gv);

    // Instruction barrier to ensure value is set before later loads execute.
    isync();

    return 0;
}

extern "C" void __cxa_guard_release(volatile uint64_t* gv)
{
    // Memory barrier to ensure all preceeding writes have completed before
    // releasing guard.
    lwsync();

    (*(volatile uint32_t*)gv) = 2;
    return;
}

extern "C" void __cxa_pure_virtual()
{
    // TODO: Add better code for invalid pure virtual call.
    while(1);
}

// ----------------------------------------------------------------------------
//   Module exit support
// ----------------------------------------------------------------------------


// This one is just for the base object.  Each module has it's own giving
// each module a unique value for __dso_handle.
void*   __dso_handle = (void*) &__dso_handle;

struct DtorEntry_t
{
    typedef void * key_type;
    key_type    key;
    void (*dtor)(void*);
    void * arg;

    DtorEntry_t * next;
    DtorEntry_t * prev;
};

Util::Locked::List<DtorEntry_t, DtorEntry_t::key_type> g_dtorRegistry;
mutex_t g_dtorLock = MUTEX_INITIALIZER;


/**
 * Call all the static destructors for the module identified by i_dso_handle
 * @param[in] i_dso_handle  unique identifier for a module
 * @post matching dtor functions called and then removed from the dtor registry
 */
void call_dtors(void * i_dso_handle)
{
    mutex_lock(&g_dtorLock);

    DtorEntry_t * entry = NULL;
    while( NULL != (entry = g_dtorRegistry.find(i_dso_handle)) )
    {
        g_dtorRegistry.erase(entry);  // remove from list
        (*(entry->dtor))(entry->arg);
        delete entry;
    }

    mutex_unlock(&g_dtorLock);
}


extern "C" int __cxa_atexit(void (*i_dtor)(void*),
                            void* i_arg,
                            void* i_dso_handle)
{
    // Base kernel code may try to call this before mem heap is
    // available - so don't add it.
    // TODO - Only need dtors for extended image modules
    if(i_dso_handle != __dso_handle)
    {
        DtorEntry_t * entry = new DtorEntry_t();
        entry->key = i_dso_handle;
        entry->dtor = i_dtor;
        entry->arg = i_arg;

        mutex_lock(&g_dtorLock);
        g_dtorRegistry.insert(entry);
        mutex_unlock(&g_dtorLock);
    }
    return 0;
}



