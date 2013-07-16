/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/runtime/rt_assert.C $                                     */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <assert.h>
#include <stdio.h>
#include <runtime/interface.h>
#include <kernel/console.H>

/** Hook location for trace module to set up when loaded. */
namespace TRACE { void (*traceCallback)(void*, size_t) = NULL; };

extern "C" void __assert(AssertBehavior i_assertb, int i_line)
{
    if (i_assertb != ASSERT_TRACE_DONE)
    {
        printk("Assertion failed @%p on line %d.\n",
                linkRegister(), i_line);
    }

    g_hostInterfaces->assert();
    while(1);
}
