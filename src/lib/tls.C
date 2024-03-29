/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/tls.C $                                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
#define assert crit_assert

#include <kernel/task.H>
#include <stdint.h>
#include <sys/sync.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#ifndef __HOSTBOOT_RUNTIME
#include <util/lockfree/stack.H>
#else
#include <util/nolockfree/stack.H>
#endif
#include <sys/vfs.h>


void* allocate(size_t size) {
    /* HBRT uses PHYP for memory allocations, it doesn't have the
     * allocators that Hostboot does, so we call malloc directly in
     * that case. */
#ifdef __HOSTBOOT_RUNTIME
    return malloc(size);
#else
    return contiguous_malloc(size);
#endif
}

/**
 *  @brief Mask which suppresses ignored portions of a TLS module ID.  When
 *      The linker creates a module ID, it prefixes it with "TLS" + 0x00
 *      as the first 32 bits.  This mask slices that off to leave just the
 *      normalized module ID
 */
const size_t TLS_MODULE_MASK = 0x00000000FFFFFFFFULL;

/** Thread Local Storage - How it works.
 *
 *  For background:
 *      - http://www.akkadia.org/drepper/tls.pdf
 *      - http://www.uclibc.org/docs/tls-ppc64.txt
 *
 *  Normal global variables go into a per-module ELF section of .data or .bss
 *  depending on if the variable is non-zero or zero initialized respectively.
 *  To support TLS, the compiler emits a new .tdata and .tbss data.  It is
 *  expected that the runtime support (this code) will create a new copy of
 *  the .tdata / .tbss section per-thread.
 *
 *  The implementation of TLS needs to be both fast and use minimum memory.
 *  The TLS design (in tls.pdf and the compiler implementation) allows lazy
 *  creation of the TLS data on a per-thread and per-module basis and it is
 *  also organized in a way to allow TLS variable lookups to typically be done
 *  with only a few pointer dereferences.
 *
 *  When you create a thread local variable, such as through the thread_local
 *  C++11 syntax, the compiler will create a tuple for each variable.  Each
 *  module is assigned a module-id by the linker and the tuple has the
 *  module-id and the offset in the .tdata / .tbss section for each variable.
 *  In the case where a TLS variable from a module has already been accessed,
 *  TLS access is as simple as:  task_t->tls_context->blobs[module][offset].
 *  When a variable has not yet been accessed by a thread, the blob for the
 *  module must be allocated and initialized from the module's original
 *  .tdata / .tbss section.
 *
 *  One oddity in the design is the disconnect between the tuples and the
 *  .tdata section.  The module_init code can find if a .tdata exists, by
 *  checking the size of __tls_start_addr and __tls_end_addr, but it does not
 *  know the module-id that was assigned by the linker.  Therefore, we have
 *  module_init 'register' the tls_start/tls_end when the module loads, but
 *  have to defer determining the module-id until the first TLS access of
 *  a variable (in any thread).  At this point, we find the .tdata address
 *  closest to the variable to match up the module-id and .tdata address.  This
 *  is the purpose of the __tls_pending_modules and __tls_modules structures.
 *  Once a module has been matched up once we can use the __tls_modules for
 *  quicker lookups of a TLS access in any other thread.
 */


/** Tuple created by the linker for each TLS variable. */
struct __tls_linker_tuple
{
    size_t module;
    size_t offset;
};

/** Info about the .tdata section for each module. */
struct __tls_module
{
    void* sect_addr; //< Starting address of module
    size_t size;     //< Size of module
    size_t module;   //< Module ID of this module
                     //< (set by custom linker)

    /**
     *  @brief Default constructor
     */
    __tls_module()
     : sect_addr(0),
       size(0),
       module(0)
    {
    }

    /**
     *  @brief Specialized contstructor
     *
     *  @param[in] i_start  Module starting address.  Must not be nullptr.
     *  @param[in] i_size   Module size in bytes
     *  @param[in] i_module Modue ID of the module
     */
    __tls_module(void* const  i_start,
                 const size_t i_size,
                 const size_t i_module)
      : sect_addr(i_start),
        size(i_size),
        module(i_module)
    {
    }
};

/** TLS destructor data. */
struct __tls_dtor
{
    void (*dtor)(void*);
    void* arg;

    __tls_dtor* next;
};

/** TLS data for each task to go into task_t. */
struct __tls_thread_info
{
    size_t count;
#ifndef __HOSTBOOT_RUNTIME
    Util::Lockfree::Stack<__tls_dtor> dtors;
#else
    Util::NoLockFree::Stack<__tls_dtor> dtors;
#endif
    void* blobs[0];
};

mutex_t __tls_mutex = MUTEX_INITIALIZER;
std::vector<__tls_module> __tls_modules;
std::vector<__tls_module> __tls_pending_modules;

/** Get the previously registered __tls_module data for a TLS variable */
const __tls_module* __tls_get_module(const __tls_linker_tuple* tuple)
{
    size_t tuple_module = tuple->module & TLS_MODULE_MASK;

    // Look the module up in the __tls_modules first, in case we've seen
    // this module before in another thread.
    if ((__tls_modules.size() > tuple_module) &&
        (__tls_modules[tuple_module].sect_addr != nullptr))
    {
        return &__tls_modules[tuple_module];
    }

    // We plan to insert a new module, so make sure we can contain it.
    if (__tls_modules.size() <= tuple_module)
    {
        __tls_modules.resize(tuple_module+1);
    }

    // This is the first time we've seen this module.  Need to look up in
    // pending.

    // The module should have pre-registered its module ID in association
    // with its starting address and size; look for a module ID match.
    auto moduleItr = std::find_if(
        __tls_pending_modules.begin(),
        __tls_pending_modules.end(),
        [&tuple_module](const __tls_module& i_module)
        {
            return (tuple_module == i_module.module);
        });
    assert(moduleItr != __tls_pending_modules.end());

    // Copy it into the __tls_modules and remove it from the pending list.
    __tls_modules[tuple_module] = *moduleItr;
    __tls_pending_modules.erase(moduleItr);

    return &__tls_modules[tuple_module];
}

/* Since Hostboot runtime only has a single thread, we'll just create a
 * single global TLS area. */
#ifdef __HOSTBOOT_RUNTIME
task_t tls_task_struct;
#endif

/** Get a TLS variable address
 *
 *  Calls to this automatically inserted by the compiler.
 */
extern "C"
void* __tls_get_addr(const __tls_linker_tuple* tuple)
{
    size_t tuple_module = tuple->module & TLS_MODULE_MASK;

    task_t* task = nullptr;
#ifdef __HOSTBOOT_RUNTIME
    task = &tls_task_struct;
#else
    // Get the task_t pointer from register 13.
    asm volatile("mr %0, 13" : "=r"(task));
#endif

    auto tls_info = reinterpret_cast<__tls_thread_info*>(task->tls_context);

    // If:
    //      - tls_info is nullptr.
    //      - tls count is not at least as large as this module id.
    //      - tls[module] is nullptr
    // Then: module blob needs to be allocated.
    if ((tls_info == nullptr) ||
        (tls_info->count <= tuple_module) ||
        (tls_info->blobs[tuple_module] == nullptr))
    {

        // If there isn't room for the module's blob, we need to allocate it.
        if ((tls_info == nullptr) || (tls_info->count <= tuple_module))
        {
            decltype(__tls_thread_info::count) old_count = 0;
            auto new_size = sizeof(__tls_thread_info) +
                            sizeof(void*)*(tuple_module+1);

            // Allocate or reallocate the tls info.
            if (tls_info == nullptr)
            {
                old_count = 0;
                tls_info = reinterpret_cast<decltype(tls_info)>(
                    allocate(new_size));
                memset(&tls_info->dtors, '\0', sizeof(tls_info->dtors));
            }
            else
            {
                old_count = tls_info->count;
                tls_info = reinterpret_cast<decltype(tls_info)>(
                    realloc(tls_info, new_size));
            }

            // Clear the newly allocated area and update the count.
            memset(&tls_info->blobs[old_count], '\0', new_size -
                   (sizeof(__tls_thread_info) + sizeof(void*)*old_count));
            tls_info->count = tuple_module+1;

            // save into task struct.
            task->tls_context = tls_info;

        }

        // Allocate and copy TLS blob.
        mutex_lock(&__tls_mutex);
        {
            auto module = __tls_get_module(tuple);
            auto blob = tls_info->blobs[tuple_module] = allocate(module->size);
            memcpy(blob, module->sect_addr, module->size);
        }
        mutex_unlock(&__tls_mutex);

    }

    // Return the offset of the TLS variable from this module's blob.
    return &reinterpret_cast<uint8_t*>(tls_info->blobs[tuple_module])
        [tuple->offset+VFS_PPC64_DTPREL_OFFSET];
}

/** Register a module's __tls_start_address / __tls_end_address.
 *
 *  Called by init() in module_init.
 */
void __tls_register(void* s, void* e, const size_t i_module)
{
    if (s == e)
        return;

    __tls_module m(s,  ((size_t)e) - ((size_t)s), i_module );
    mutex_lock(&__tls_mutex);
    {
        __tls_pending_modules.push_back(m);
    }
    mutex_unlock(&__tls_mutex);
}

/** Clean up registration on unload.
 *
 *  Called by fini() in module_init.
 */
void __tls_unregister(void* s, void* e)
{
    if (s == e)
        return;

    using std::remove_if;

    mutex_lock(&__tls_mutex);
    {
        auto& v = __tls_pending_modules;
        v.erase(remove_if(v.begin(), v.end(),
                    [s](const auto& i){ return i.sect_addr == s; }),
                v.end());
    }
    mutex_unlock(&__tls_mutex);
}

/** Clean up TLS data for a task.
 *
 *  Called by task_end_stub.
 */
extern "C"
void __tls_cleanup(__tls_thread_info* info)
{
    // Call TLS destructors.
    while(auto d = info->dtors.pop())
    {
        d->dtor(d->arg);
        free(d);
    }

    // Free TLS blobs.
    decltype(__tls_thread_info::count) i = 0;
    while(i < info->count)
    {
        free(info->blobs[i]);
        ++i;
    }
    free(info);
}

/** Register a C++ dtor for TLS data.
 *
 *  Automatically called by compiler when a TLS variable has a constructor /
 *  destructor.
 */
extern "C"
int __cxa_thread_atexit(void (*dtor)(void*), void* arg, void* dso)
{
    task_t* task = nullptr;
#ifdef __HOSTBOOT_RUNTIME
    task = &tls_task_struct;
#else
    // Get the task_t pointer from register 13.
    asm volatile("mr %0, 13" : "=r"(task));
#endif

    // Get tls_info from task_t or allocate a new one.
    auto tls_info = reinterpret_cast<__tls_thread_info*>(task->tls_context);
    if (nullptr == tls_info)
    {
        task->tls_context = tls_info =
            reinterpret_cast<decltype(tls_info)>(
                calloc(1, sizeof(decltype(*tls_info))));
    }

    // Insert a new dtor registration.
    auto dtor_info = reinterpret_cast<__tls_dtor*>(allocate(sizeof(__tls_dtor)));
    dtor_info->dtor = dtor;
    dtor_info->arg = arg;
    tls_info->dtors.push(dtor_info);

    return 0;
}
