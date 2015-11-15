/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/misc.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2015                        */
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
    /** @brief master host boot instance number (node) */
    extern uint64_t g_masterHBInstance;

    /** @brief Indicate whether HB is running or not */
    enum HbRunning
    {
        HB_RUNNING = 0,
        HB_SHUTDOWN = 1,
    };

    /** @fn setHbScratchStatus
     *  @brief Set scratch register indicating HB running status
     *
     *  @param i_status Indicates whether to say HB is running or shutdown
     *  @return void
     */
    void setHbScratchStatus(enum HbRunning i_status);

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
             *  @param i_fusedCores - true if using 8 threaded cores 
             */
            WinkleCore(task_t* i_caller, bool i_fusedCores) :
                iv_caller(i_caller), iv_timebase(0),
                iv_fusedCores(i_fusedCores) {};

            void masterPreWork();
            void activeMainWork();
            void masterPostWork();
            void nonactiveMainWork();

        private:
                /** Caller of cpu_master_winkle() */
            task_t* iv_caller;
                /** Current time-base value for restore after winkle. */
            uint64_t iv_timebase;
                /** Fused core has 8 threads per core (normal is 4).   */
                /** So when winkling core, we need a 2nd core started. */
            bool  iv_fusedCores;
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
