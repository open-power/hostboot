#ifndef __KERNEL_VMMMGR_H
#define __KERNEL_VMMMGR_H

#include <kernel/types.h>
#include <kernel/spinlock.H>

class VmmManager
{
    public:
	struct pte_t
	{
	    uint64_t a,b;
	};

	enum VMM_CONSTS
	{
	    FULL_MEM_SIZE = 8 * 1024 * 1024,
	    PAGESIZE = 4096,

	    PTSIZE = (1 << 18),
	    PTEG_SIZE = 8,
	    PTEG_COUNT = (PTSIZE / sizeof(pte_t)) / PTEG_SIZE,

	    HTABORG = (FULL_MEM_SIZE - PTSIZE),
	};

	enum ACCESS_TYPES
	{
	    NO_USER_ACCESS,
	    READ_O_ACCESS,
	    NORMAL_ACCESS,
	    CI_ACCESS,
	};

	enum PID_ALLOCATIONS
	{
	    LinearSpace = 0,
	    MMIOSpace = 1,
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

	static pte_t* page_table;

	inline volatile pte_t& getPte(uint64_t pteg, uint64_t idx)
	{
	    return page_table[pteg * PTEG_SIZE + idx];
	}
	
	inline void defaultPte(volatile pte_t& pte)
	{
	    pte.a = 0x4000000000000000; // B = 01 (1TB).
	    pte.b = 0x0;
	}

	inline void setValid(bool valid, volatile pte_t& pte)
	{
	    // Adding a page requires EIEIO to ensure update of PTE prior
	    // to making valid and PTESYNC afterwards.  
	    // Removing a page just requires PTESYNC afterwards.
	    if (valid)
	    {
		asm volatile("eieio" ::: "memory");
	    }
	    
	    pte.a &= ~0x01;
	    pte.a |= (valid ? 0x1 : 0x0);

	    if (!valid)
	    {
		asm volatile("ptesync" ::: "memory");
		
		register uint64_t rS = 0, rB = 0;
		rB = (getTid(pte) << 11) // VA[0:54).
		   | (((uint64_t)&pte) & 0x3FF8) >> 7; // VA[55:65].
		rB <<= 12; // Put in rB[0:51].
		rB |= 0x0100; // B = 01 (1TB).
		
		// TLBIE isn't correct in gcc, hand code asm.
		asm volatile(".long 0x7c000264 | (%0 << 11) | (%1 << 21)" ::
		             "r"(rB), "r"(rS) : "memory");
		
		asm volatile("eieio" ::: "memory");
		asm volatile("tlbsync" ::: "memory");
	    }
	    
	    asm volatile("ptesync" ::: "memory");
	}

	inline bool isValid(volatile pte_t& pte)
	{
	    return ((pte.a & 0x01) == 0x01);
	}

	inline void setTid(tid_t tid, volatile pte_t& pte)
	{
	    pte.a &= 0xC00000000000007F;
	    pte.a |= ((uint64_t) tid) << 7;
	}

	inline tid_t getTid(volatile pte_t& pte)
	{
	    return (tid_t) ((pte.a & 0xC00000000000007F) >> 7);
	}

	inline void setAccess(ACCESS_TYPES t, volatile pte_t& pte)
	{
	    uint64_t pteMask = ~0x800000000000007B;
	    pte.b &= pteMask;
	    pte.b |= (NO_USER_ACCESS == t ? 0x0000000000000010 :
		     (READ_O_ACCESS == t ?  0x0000000000000011 :
		     (NORMAL_ACCESS == t ?  0x0000000000000012 :
		     (CI_ACCESS == t ?      0x000000000000002A :
		      0x0))));
	}

	inline void setPage(uint64_t page, volatile pte_t& pte)
	{
	    pte.b &= ~0x0FFFFFFFFFFFF000;
	    pte.b |= page << 12;
	}

	inline uint64_t getPage(volatile pte_t& pte)
	{
	    return (pte.b & 0x0FFFFFFFFFFFF000) >> 12;
	}
};

#endif
