//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/barrier.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __KERNEL_BARRIER_H
#define __KERNEL_BARRIER_H

#include <kernel/spinlock.H>
#include <stdint.h>

/**
 * Barrier to be used in kernel space
 */
class Barrier
{
    public:

        /**
         * Default Constructor
         */
        Barrier() :
            iv_count(0),
            iv_event(0),
            iv_missing(0) {};

        /**
         * Construct and init a barrier
         * @param[in] i_count number of cpus to wait on
         */
        Barrier(size_t i_count) :
            iv_count(i_count),
            iv_event(0),
            iv_missing(i_count) {}
        
        /**
         * Initialize the barrier
         * @param[in] i_count number of cpus to wait on
         */
        void init(size_t i_count)
        {
            iv_count = i_count;
            iv_missing = i_count;
        }

        /**
         * Wait until all threads have been arrived
         */
	void wait();

    private:

        Spinlock iv_spinlock;           //!< Spinlock acts as mutex
        volatile size_t iv_count;       //!< Barrier thread count
        volatile size_t iv_event;       //!< Barrier event
        volatile size_t iv_missing;     //!< # of missing threads to wait for
};

#endif
