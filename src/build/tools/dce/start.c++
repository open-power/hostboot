/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/build/tools/dce/start.c++ $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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

/* @brief
 *
 * This file provides setup and teardown functions as well as implementations of
 * some library functions for DCE scripts that would otherwise be provided by a
 * C++ standard library implementation.
 */

#include <stdint.h>
#include <list>

#include <errl/errlentry.H>
#include <return_code.H>

// This variable will get placed directly after the .text section by the linker
// script in the ELF that we generate, and the .data_segment_addr section has
// page alignment requirements. This is so that we can set memory permissions
// on a page boundary when we load the ELF into memory.
uint64_t _data_segment_addr __attribute__ ((section (".data_segment_addr")));

// This is passed as a parameter to __cxa_atexit when we have global objects
// with destructors. We just need to provide a definition for it.
void* __dso_handle;

// This structure is the list of things that we have to do when we're finished
// executing.
struct destructor
{
    destructor* next;
    void (*dtor)(void*);
    void* arg;
};

// This is a global linked list that we use to track destructor registrations.
destructor* destructors;

// This is a function normally provided by the environment that we are
// redefining for DCE so that when main() finishes, we can invoke the list of
// destructors. The compiler generates code that calls this function to register
// a callback that will invoke global destructors. Note that if DCE code
// crashes, destructors won't be invoked.
extern "C" int __cxa_atexit(void (*i_dtor)(void*),
                            void* i_arg,
                            void* i_dso_handle)
{
    destructor* new_destructor = new destructor;
    new_destructor->next = destructors;
    new_destructor->dtor = i_dtor;
    new_destructor->arg = i_arg;

    destructors = new_destructor;
    return 0;
}

// Call all the destructors that have been registered via __cxa_atexit.
static void dce_invoke_destructors()
{
    destructor* d = destructors;
    destructors = nullptr;

    while (d)
    {
        d->dtor(d->arg);
        destructor* next = d->next;
        delete d;
        d = next;
    }
}

// _start_ctors is a symbol defined by the linker script that points to the
// start of the .init_array ELF segment. The memory in that section is an array
// of function pointers (i.e. pointers to descriptors) that will be executed in
// order. The end of the array is marked by the symbol _end_ctors. (Those
// symbols are a DCE-specific thing that we had to add to our linker script, but
// the .init_array segment is not.)
extern void(*_start_ctors)();
extern void(*_end_ctors)();

// This function is defined by users.
int main();

// Declarations for FAPI globals which are required to use FAPI macros.
namespace fapi2 {
    ReturnCode current_err;
    std::list<errlHndl_t> g_platErrList;
}


// This is the entrypoint for the ELF. It will first invoke constructors, then
// call the user-defined main() function, and then invoke destructors and return.
extern "C" int _start()
{
    auto ctors = &_start_ctors;

    while (ctors != &_end_ctors)
    {
        (*ctors)();
        ctors++;
    }

    const int rc = main();

    dce_invoke_destructors();

    return rc;
}
