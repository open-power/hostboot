/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/segment.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
/** @file segment.H
 *  @brief Contains the definition of the virtual Segment class.
 */
#ifndef __KERNEL_SEGMENT_H
#define __KERNEL_SEGMENT_H

#include <kernel/task.H>
#include <errno.h>
#include <kernel/ptmgr.H>

/** @class Segment
 *  @brief Virtual segment class to handle virtual memory management within
 *         a 1TB segment.
 */
class Segment
{
    public:
        /**
         * @brief Constructor.
         * @param[in] i_baseAddr - Base [virtual] address of this segment.
         */
        explicit Segment(uint64_t i_baseAddr) : iv_baseAddress(i_baseAddr) {};
        /**
         * @brief Destructor.
         * No additional action necessary.
         */
        virtual ~Segment() {};

        /**
         * @brief Responsible for handling page faults within the segment.
         *
         * @param[in] i_task - Task causing the page fault.
         * @param[in] i_addr - Effective address accessed to cause fault.
         * @param[in] i_store - The fault was due to a store.
         * @param[out] o_oom - Handler failed due to OOM condition
         *
         * @return true - Page fault was successfully handled.
         *
         * If the page fault is not successfully handled the expectation is
         * that the VMM will perform appropriate action, such as killing the
         * task.
         *
         * If o_oom is non-null, it will be set to true of an OOM occurs. If an
         * OOM does not occur, it will not be altered. If it is null, then an
         * OOM may trigger a kernel assert.
         */
        virtual bool handlePageFault(task_t* i_task, uint64_t i_addr,
                                     bool i_store, bool* o_oom) = 0;

        /**
         * @brief Get the base address of this segment.
         * @return Base address (as uint64_t).
         */
        uint64_t getBaseAddress() const { return iv_baseAddress; };

        /**
         * @brief Locate the physical address of the given virtual address
         * @param[in] i_vaddr virtual address
         * @return the physical address bound to the virtual address,
         *          or -EFAULT if i_vaddr not found. @see errno.h
         */
         virtual uint64_t findPhysicalAddress(uint64_t i_vaddr) const { return -EFAULT; };

        /**
         * @brief Update LRU statistics on the block that owns the address
         *
         * @param[in] i_vaddr - Virtual Address of page
         * @param[in] i_stats - Usage statistics
         */
        virtual void updateRefCount( uint64_t i_vaddr,
				     PageTableManager::UsageStats_t i_stats )
	{
	    //default to a NOOP
	    return;
	};

        /**
         * @brief Cast out older physical memory pages
         * @param[in] i_type Constraint @see VmmManager::castOutPages
         */
        virtual void castOutPages(uint64_t i_type) {} // default to NOOP

    protected:
            /** The base address of the segment. */
        const uint64_t iv_baseAddress;
};

#endif
