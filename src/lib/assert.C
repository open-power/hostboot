/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/lib/assert.C $                                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
/** @file assert.C
 *  @brief Common handling functions for assert paths.
 */

#include <builtins.h>
#include <kernel/console.H>
#include <assert.h>
#include <sys/task.h>
#include <arch/ppc.H>
#include <kernel/misc.H>

#include <kernel/hbterminatetypes.H>
#include <kernel/terminate.H>
#include <sys/misc.h>
#include <kernel/kernel_reasoncodes.H>

/** Hook location for trace module to set up when loaded. */
namespace TRACE { void (*traceCallback)(void*, size_t) = NULL; };

extern "C" void __assert(AssertBehavior i_assertb, int i_line)
{
    if ((i_assertb == ASSERT_CRITICAL) && (KernelMisc::in_kernel_mode()))
    {
        i_assertb = ASSERT_KERNEL;
    }

    switch (i_assertb)
    {
        case ASSERT_TRACE_DONE: // Custom trace was provided.
            task_crash();
            break;

        case ASSERT_TRACE_NOTDONE: // Do a normal trace.
            if (NULL != TRACE::traceCallback)
            {
                (*TRACE::traceCallback)(linkRegister(), i_line);
            }
            else
            {
                printk("Assertion failed @%p on line %d.\n",
                       linkRegister(), i_line);
            }
            task_crash();
            break;

        case ASSERT_CRITICAL:  // Critical task, trace not available.
            printk("Assertion failed @%p on line %d.(Crit_Assert)\n",
                   linkRegister(), i_line);

            // Need to call the external CritAssert system call
            cpu_crit_assert(reinterpret_cast<uint64_t>(linkRegister()));
            break;

        case ASSERT_KERNEL:  // Kernel assert called.
            printk("Assertion failed @%p on line %d. (kassert)\n",
                   linkRegister(), i_line);

            // Call function to create SRC and update TI Data area
            termWriteSRC(TI_KERNEL_ASSERT, RC_ASSERT,
                         reinterpret_cast<uint64_t>(linkRegister()));

            // Call to force TI
            terminateExecuteTI();
            break;
    }

    // Loop forever if we make it here.  Should only happen in kernel code.
    while (true)
    {
        setThreadPriorityLow();
    }
}

