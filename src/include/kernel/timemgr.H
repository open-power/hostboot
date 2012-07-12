/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/kernel/timemgr.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2010-2012
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
#ifndef __KERNEL_TIMEMGR_H
#define __KERNEL_TIMEMGR_H

#include <kernel/types.h>
#include <kernel/cpu.H>
#include <arch/ppc.H>

#include <util/locked/pqueue.H>
#include <kernel/spinlock.H>

class Scheduler;

/** Struct to hold sleeping tasks in a pqueue */
struct _TimeManager_Delay_t
{
    _TimeManager_Delay_t * next;
    _TimeManager_Delay_t * prev;
    uint64_t key;
    task_t* task;
};

/** @class TimeManager
 *  @brief Keeps track of sleeping of tasks and conversions between TB and time.
 */
class TimeManager
{
    public:
        enum
        {
            /** Number of time-slices to allow per second.
             *
             *  Context length becomes (1/TIMESLICE_PER_SECOND) sec.
             */
            TIMESLICE_PER_SEC = 1000,

            /** Yield Threshold per timeslice
             *
             * @note At 512MHZ clock and TIMESLICE_PER_SEC = 1000,
             *   Timeslice = 512000 ticks.
             * If threshold/slice = 100 then threhold = 5120 ticks
             * FYI, a Context switch ~ 476 ticks
             */
            YIELD_THRESHOLD_PER_SLICE = 100,    // 1%
        };

            /** Initialize the time subsystem. */
        static void init();

            /** Initialize the task-delay structures for a CPU. */
        static void init_cpu(cpu_t* cpu);

            /** Return the number of ticks per time-slice. */
        static uint64_t getTimeSliceCount()
            {
                return iv_timebaseFreq / TIMESLICE_PER_SEC;
            };

        /**
         * Return the number of ticks for an idle time-slice
         */
        static uint64_t getIdleTimeSliceCount();

        /**
         * Perform a simple delay if the time is below the yield threshold.
         *
         * @param[in] sec, Delay time in seconds
         * @param[in] nsec, Delay time in nano seconds
         * @return false if the delay requires a task yield | true - The
         * requested delay was performed by this routine.
         */
        static bool simpleDelay(uint64_t sec, uint64_t nsec);

            /** Returns the value of the processor timebase register. */
        static uint64_t getCurrentTimeBase()
            {
                return getTB();
            };

        /** Converts seconds/nsecs to timebase ticks.
         *
         *  Typically this is used for calculating the number of ticks in an
         *  interval.
         *
         *  @param[in] i_sec - Number of seconds.
         *  @param[in] i_nsec - Number of nsecs.
         *
         *  @return Number of timebase ticks.
         */
        static uint64_t convertSecToTicks(uint64_t i_sec, uint64_t i_nsec);
        /** Converts timebase ticks to seconds/nsecs.
         *
         *  @param[in] i_ticks - Number of ticks.
         *  @param[out] o_sec - Number of seconds.
         *  @param[out] o_nsec - Number of nsecs.
         */
        static void convertTicksToSec(uint64_t i_ticks,
                                      uint64_t& o_sec, uint64_t& o_nsec);

        /** Delay (sleep) a task for a length of time.
         *
         *  @param[in] t - Task to delay.
         *  @param[in] i_sec - Seconds.
         *  @param[in] i_nsec - Nsecs.
         */
        static void delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
        /** Checks the sleep queue to determine if any tasks should be woken. */
        static void checkReleaseTasks(Scheduler* s);

    protected:
        TimeManager() {};
        ~TimeManager() {};

    private:

        typedef Util::Locked::PQueue<_TimeManager_Delay_t, uint64_t>
            delaylist_t;

        void _init();
        void _init_cpu(cpu_t* cpu);
        void _delayTask(task_t* t, uint64_t i_sec, uint64_t i_nsec);
        void _checkReleaseTasks(Scheduler* s);
        static delaylist_t* _get_delaylist();

        /** Frequency of the timebase register in Hz. (ticks per second) */
        static uint64_t iv_timebaseFreq;
};

#endif
