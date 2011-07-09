#ifndef __KERNEL_DEVICESEGMENT_H
#define __KERNEL_DEVICESEGMENT_H

#include <kernel/segment.H>

class DeviceSegment : public Segment
{
    public:
        DeviceSegment() : Segment(0x020000000000ull) 
            { 
                for (int i = 0; i < MMIO_MAP_DEVICES; i++)
                    iv_mmioMap[i] = 0;
            };
        ~DeviceSegment() {};

        static void init();
        
        bool handlePageFault(task_t* i_task, uint64_t i_addr);

        static void* mmioMap(void* ra, size_t pages); // to be deprecated.
        static int mmioUnmap(void* ea, size_t pages); // to be deprecated.

    private:
        enum { MMIO_MAP_DEVICES = 32 };
        uint64_t iv_mmioMap[MMIO_MAP_DEVICES];

        void _init();

        void* _mmioMap(void* ra, size_t pages);
        int _mmioUnmap(void* ea, size_t pages);
};

#endif
