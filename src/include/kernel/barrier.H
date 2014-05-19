/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/barrier.H $                                */
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
