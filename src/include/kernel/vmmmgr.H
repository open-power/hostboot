#ifndef __KERNEL_VMMMGR_H
#define __KERNEL_VMMMGR_H

#include <kernel/types.h>
#include <kernel/spinlock.H>

class VmmManager
{
    public:
	enum VMM_CONSTS
	{
	    EIGHT_MEG = 8 * 1024 * 1024,

	    FULL_MEM_SIZE = 1 * EIGHT_MEG,
	    PAGESIZE = 4096,

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

	enum PID_ALLOCATIONS
	{
	    LinearSpace = (FULL_MEM_SIZE / EIGHT_MEG) - 1,
	    MMIOSpace = LinearSpace + 1,
	    FirstPid,
	};

	enum MMIO_SPACE_INFO
	{
	    MMIO_T_ENTRIES = 
		FULL_MEM_SIZE * (MMIOSpace - LinearSpace) / PAGESIZE,
	};

	static void init();
	static void init_slb();
	static bool pteMiss(task_t*);

	static void* mmioMap(void*, size_t);
	static int mmioUnmap(void*, size_t);

    protected:
	VmmManager();
	~VmmManager() {};
    
    private:
	Spinlock lock;
	uint64_t mmioMapT[MMIO_T_ENTRIES];

	void initSLB();
	void initPTEs();	
	void initSDR1();

	bool _pteMiss(task_t*);
	void* _mmioMap(void*, size_t);
	int _mmioUnmap(void*, size_t);

};

#endif
