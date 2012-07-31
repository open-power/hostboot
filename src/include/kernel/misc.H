/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/kernel/misc.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/** @file misc.H
 *  @brief Misc. Kernel functions and utilities.
 */

#ifndef __KERNEL_MISC_H
#define __KERNEL_MISC_H

#include <stdint.h>
#include <usr/vmmconst.h>
#include <kernel/deferred.H>
#include <kernel/task.H>

namespace KernelMisc
{
    /** @fn shutdown
     *  @brief Sequence kernel to shutdown and switch to payload.
     */
    void shutdown();

    /** @brief Base address (target HRMOR) of the payload. */
    extern uint64_t g_payload_base;
    /** @brief Address from base of payload entry-point. */
    extern uint64_t g_payload_entry;

    /** @fn in_kernel_mode
     *  @brief Determine if the code is currently in kernel mode or not.
     *
     *  @return [true | false]
     */
    inline bool in_kernel_mode()
    {
        uint64_t stack = 0;
        asm volatile("mr %0, 1" : "=r"(stack));
        if((stack >= VMM_VADDR_STACK_SEGMENT) &&
           (stack < (VMM_VADDR_STACK_SEGMENT + VMM_SEGMENT_SIZE)))
        {
            return false;
        }
        return true;
    }

    /** @class WinkleCore
     *
     *  @brief DeferredWork class for implementing cpu_master_winkle.
     */
    class WinkleCore : public ::DeferredWork
    {
        public:
            /** ctor
             *
             *  @param i_caller - Task calling cpu_master_winkle to be
             *                    restored after winkle is complete.
             */
            WinkleCore(task_t* i_caller) :
                iv_caller(i_caller), iv_timebase(0) {};

            void masterPreWork();
            void activeMainWork();
            void masterPostWork();
            void nonactiveMainWork();

        private:
                /** Caller of cpu_master_winkle() */
            task_t* iv_caller;
                /** Current time-base value for restore after winkle. */
            uint64_t iv_timebase;
    };
};
#endif
