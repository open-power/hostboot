/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/devicesegment.H $                          */
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

/**
 * @file devicesegment.H
 *
 * @brief DeviceSegment class and APIs; this class allows to map certain devices
 *        to virtual memory
*/

#ifndef __KERNEL_DEVICESEGMENT_H
#define __KERNEL_DEVICESEGMENT_H

#include <kernel/segment.H>
#include <sys/mmio.h>
#include <usr/vmmconst.h>

/**
 * @class DeviceSegment
 * @brief Manages the device virtual memory segment
 */
class DeviceSegment : public Segment
{
    public:
        /**
         * @brief Constructor (Device segment at 2TB + N)
         *
         * @param[in] segId - Segment ID to map this device segment at.
         *
         * Associates itself with the SegmentManager.
         */
        explicit DeviceSegment(size_t segId) : Segment(segId * VMM_SEGMENT_SIZE)
                { init(segId); };

        /**
         * @brief Destructor
         */
        ~DeviceSegment() {};

        /**
         * @brief Add the device segment to the SegmentManager.
         */
        void init(size_t segId);

        /**
         * @brief Handle a page fault for a device address access
         * @param[in] i_task - Task pointer to the task requiring the page
         * @param[in] i_addr - 64-bit address needed to be paged
         * @param[in] i_store - Fault was due to a store.
         * @param[in] o_oom - Whether the handler failed due to OOM condition
         * @return bool - true: Page added to page table
         *               false: Not a valid address to be paged
         *
         * If o_oom is non-null, it will be set to true of an OOM occurs. If an
         * OOM does not occur, it will not be altered. If it is null, then an
         * OOM may trigger a kernel assert.
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr, bool i_store, bool* o_oom);


        /**
         * @brief Map a device into the device segment.
         * @param ra[in] - Void pointer to real address to be mapped in
         * @param i_devDataSize[in] - Size of device segment block
         * @param i_nonCI[in] - Device should be mapped cacheable instead of CI
         * @param i_guarded[in] - Whether to prevent out-of-order acces to
         *     instructions or data in the segment.  Ignored if CI.
         * @return void* - Pointer to beginning virtual address, NULL otherwise
         */
        void* devMap(void* ra, uint64_t i_devDataSize, bool i_nonCI,
            bool i_guarded);

        /**
         * @brief Unmap a device from the device segment.
         * @param ea[in] - Void pointer to effective address
         * @return int - 0 for successful unmap, non-zero otherwise
         */
        int devUnmap(void* ea);

        /**
         * @brief Locate the physical address of the given virtual address
         * @param[in] i_vaddr virtual address
         * @return the physical address bound to the virtual address, or
         *         -EFAULT if i_vaddr not found. @see errno.h
         */
        uint64_t findPhysicalAddress(uint64_t i_vaddr) const;

    private:
        /**
         * Attributes to represent a mapped device within a segment block
         */
        struct devSegData
        {
            uint64_t addr;      //< Real address assigned to device
            uint64_t no_ci:1;   //< Device should be mapped non-CI.
            uint64_t guarded:1; //< Whether to prevent out-of-order access to
                                //< instructions or data in the segment
            uint64_t size:62;   //< A particular device's segment block size
        };

        /**
         * Number of devices that can be mapped with a given segment block size
         */
        enum
        {
            MMIO_MAP_DEVICES = 32
        };

        devSegData iv_mmioMap[MMIO_MAP_DEVICES] {};

        /**
         * @brief Add the device segment
         */
        void _init();

};

#endif
