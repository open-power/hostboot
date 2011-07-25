#ifndef __KERNEL_VMMMGR_H
#define __KERNEL_VMMMGR_H

#include <limits.h>
#include <kernel/types.h>
#include <kernel/spinlock.H>

class VmmManager
{
    public:
        enum VMM_CONSTS
        {
            ONE_MEG = 1 * 1024 * 1024,
            THREE_MEG = 3 * ONE_MEG,
            EIGHT_MEG = 8 * ONE_MEG,

            FULL_MEM_SIZE = THREE_MEG,

            // put the Page Table at the end of our memory space
            PTSIZE = (1 << 18),
            HTABORG = (FULL_MEM_SIZE - PTSIZE),
        };

        enum ACCESS_TYPES
        {
            NO_USER_ACCESS,
            READ_O_ACCESS,
            NORMAL_ACCESS,
            CI_ACCESS,
            RO_EXE_ACCESS,
        };

        static void init();
        static void init_slb();

        /**
         * @brief Responsible for handling PTE misses.
         *
         * @param[in] t - Task causing the page fault.
         * @param[in] effAddr - Effective address accessed to cause fault.
         *
         * @return true - PTE miss was successfully handled.
         *
         * If the PTE miss is not successfully handled, the exception
         * handler should collect debug information and kill the task.
         */
        static bool pteMiss(task_t* t, uint64_t effAddr);

        static void* mmioMap(void*, size_t);
        static int mmioUnmap(void*, size_t);


    protected:
        VmmManager();
        ~VmmManager() {};

    private:
        Spinlock lock;

        void initPTEs();
        void initSDR1();

        bool _pteMiss(task_t*, uint64_t);

};

#endif
