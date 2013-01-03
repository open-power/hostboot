/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/misc.H $                                   */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
/** @file misc.H
 *  @brief Misc. Kernel functions and utilities.
 */

#ifndef __KERNEL_MISC_H
#define __KERNEL_MISC_H

#include <stdint.h>
#include <usr/vmmconst.h>
#include <kernel/deferred.H>
#include <kernel/task.H>
#include <kernel/memstate.H>
#include <sys/mmio.h>

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
    /** @brief Address from base of payload data pointer. */
    extern uint64_t g_payload_data;

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

    /** @class WinkleAll
     *
     * @brief DeferredWork class for implementing cpu_all_winkle.
     */
    class WinkleAll : public ::DeferredWork
    {
        public:
            /** ctor
             *
             *  @param i_caller - Task calling cpu_all_winkle to be restored
             *                    after winkle is complete.
             *
             */
            WinkleAll(task_t* i_caller) :
                iv_caller(i_caller), iv_timebase(0), iv_firstThread(0) {};

            void masterPreWork();
            void activeMainWork();
            void masterPostWork();
            void nonactiveMainWork();

        private:
                /** Caller of cpu_all_winkle() */
            task_t* iv_caller;
                /** Current time-base value for restore after winkle. */
            uint64_t iv_timebase;
                /** Sync value for first thread to wake up. */
            uint64_t iv_firstThread;

    };

    /** @fn expand_half_cache
     *
     *  @brief Expands the image footprint from a quarter-cache (top 512k of
     *         each cache column) to a half-cache (full 1mb of each column).
     *
     *  @return 0 or -errno
     */
    int expand_half_cache();

    /** @fn expand_full_cache
     *
     *  @brief Expands the image footprint from a half-cache to full-cache
     *         mode.
     *
     *  @return 0 or -errno
     */
    int expand_full_cache();

    /** @fn populate_cache_lines
     *
     *  @brief Populates a range of memory addresses into the cache via dcbz.
     *
     *  This is meant to be used while the processor is in cache-contained
     *  mode.  The entire cache line is zero'd so if the range is less then
     *  a cache-line, or starts misaligned, then more memory might be zero'd
     *  then would be expected.
     *
     *  @param[in] i_start - Address to start dcbz at.
     *  @param[in] i_end - Address to stop dcbz at.
     *                     (This address is not dcbz'd itself)
     */
    void populate_cache_lines(uint64_t* i_start, uint64_t* i_end);

    /** @fn set
     *
     *  @brief Update value of scratch register to specified data.
     *
     *  This is used to update any core scratch reg defined by the enum
     *      MMIO_SCRATCH_REG with the data passed in.
     *
     *     NOTE: This function is a wrapper function for writeScratchReg that
     *     takes care of modifying the scratch register address value depending
     *     on the getCPUType.   The writeScratchReg takes the scratch address
     *     passed in and puts that data in that register using assembly code
     *
     *  @param[in] uint64_t - scratch_addr
     *  @param[in] uint64_t - Data
     */
    void updateScratchReg(MMIO_Scratch_Register scratch_addr, uint64_t data);

};
#endif
