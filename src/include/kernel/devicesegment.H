//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/devicesegment.H $
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
         * @brief Constructor (Device segment at 2TB)
         */
        DeviceSegment() : Segment(VMM_VADDR_DEVICE_SEGMENT) {};

        /**
         * @brief Destructor
         */
        ~DeviceSegment() {};

        /**
         * @brief Add the device segment
         */
        static void init();

        /**
         * @brief Handle a page fault for a device address access
         * @param i_task[in] - Task pointer to the task requiring the page
         * @param i_addr[in] - 64-bit address needed to be paged
         * @return bool - true: Page added to page table
         *               false: Not a valid address to be paged
         */
        bool handlePageFault(task_t* i_task, uint64_t i_addr);


        /**
         * @brief Map a device into the device segment(2TB)
         * @param ra[in] - Void pointer to real address to be mapped in
         * @param i_devDataSize[in] - Size of device segment block
         * @return void* - Pointer to beginning virtual address, NULL otherwise
         */
        static void* devMap(void* ra, uint64_t i_devDataSize);

        /**
         * @brief Unmap a device from the device segment(2TB)
         * @param ea[in] - Void pointer to effective address
         * @return int - 0 for successful unmap, non-zero otherwise
         */
        static int devUnmap(void* ea);

    private:
        /**
         * Attributes to represent a mapped device within a segment block
         */
        struct devSegData
        {
            uint64_t addr; /* Real address assigned to device */
            uint64_t size; /* A particular device's segment block size */
            devSegData(): addr(0),size(THIRTYTWO_GB){};
        };

        /**
         * Number of devices that can be mapped with a given segment block size
         */
        enum
        {
            MMIO_MAP_DEVICES = 32
        }; //TODO - Only necessary if a device uses a SCOM region other than 32GB

        devSegData iv_mmioMap[MMIO_MAP_DEVICES];

        /**
         * @brief Add the device segment
         */
        void _init();

        /**
         * @brief Map a device into the device segment(2TB)
         * @param ra[in] - Void pointer to real address to be mapped in
         * @param i_devDataSize[in] - Size of device segment block
         * @return void* - Pointer to beginning virtual address, NULL otherwise
         */
        void* _devMap(void* ra, uint64_t i_devDataSize);

        /**
         * @brief Unmap a device from the device segment(2TB)
         * @param ea[in] - Void pointer to effective address
         * @return int - 0 for successful unmap, non-zero otherwise
         */
        int _devUnmap(void* ea);
};

#endif
