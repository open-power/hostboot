/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/libc++/builtins.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2022                        */
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
#ifndef bl_builtins_C
#include <stdint.h>
#include <stdlib.h>

#include <arch/ppc.H>
#include <util/locked/list.H>
#include <sys/sync.h>

#ifdef __HOSTBOOT_RUNTIME
#include <assert.h>
#include <builtins.h>
#endif

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

void operator delete(void* p, size_t)
{
    return free(p);
}

void operator delete[](void* p, size_t)
{
    return free(p);
}
#endif // bl_builtins_C

enum CXA_GUARD_LOCK_VALUE : uint32_t
{
    UNINITIALIZED = 0,
    LOCKED = 1,
    UNLOCKED_AND_INITIALIZED = 2
};

enum CXA_GUARD_ACTION : int
{
    DO_NOT_RUN_CONSTRUCTOR = 0,
    RUN_CONSTRUCTOR = 1,
};

extern "C" int __cxa_guard_acquire(volatile uint64_t* gv)
{
    // States:
    //     0 -> uninitialized
    //     1 -> locked
    //     2 -> unlocked and initialized

    uint32_t v = __sync_val_compare_and_swap((volatile uint32_t*)gv, 0, 1);
    if (v == UNINITIALIZED)
        return RUN_CONSTRUCTOR;
    if (v == UNLOCKED_AND_INITIALIZED)
        return DO_NOT_RUN_CONSTRUCTOR;

#ifdef __HOSTBOOT_RUNTIME
    // Hostboot runtime is single-threaded. If we go to initialize a local
    // static variable and see that it's already in the "locked" state, it means
    // that this thread is already initializing the object and we must have
    // entered this path recursively. Trying to acquire the lock again will
    // result in a deadlock; so instead, we assert here to fail faster. The C++
    // standard specifies that if the initialization of a local static variable
    // is entered recursively, the behavior is undefined, so we are permitted to
    // do whatever we want here.
    crit_assert(false);
#endif

    // Wait for peer thread to perform initialization (state 2).
    while(UNLOCKED_AND_INITIALIZED != *(volatile uint32_t*)gv);

    // Instruction barrier to ensure value is set before later loads execute.
    isync();

    return DO_NOT_RUN_CONSTRUCTOR;
}

extern "C" void __cxa_guard_release(volatile uint64_t* gv)
{
    // Memory barrier to ensure all preceding writes have completed before
    // releasing guard.
    lwsync();

    (*(volatile uint32_t*)gv) = 2;
    return;
}

#ifndef bl_builtins_C
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
#endif // bl_builtins_C
