#include <util/singleton.H>
#include <kernel/vmmmgr.H>
#include <kernel/console.H>
#include <arch/ppc.H>
#include <kernel/ptmgr.H>

extern void* data_load_address;

VmmManager::VmmManager() : lock()
{
}

void VmmManager::init()
{
    printk("Starting VMM...\n");
    
    VmmManager& v = Singleton<VmmManager>::instance();

    v.initSLB();
    v.initPTEs();
    v.initSDR1();

    printk("...done.\n");
};

void VmmManager::init_slb()
{
    VmmManager& v = Singleton<VmmManager>::instance();
    v.initSLB();
    v.initSDR1();
}

bool VmmManager::pteMiss(task_t* t)
{
    return Singleton<VmmManager>::instance()._pteMiss(t);
}

void* VmmManager::mmioMap(void* ra, size_t pages)
{
    return Singleton<VmmManager>::instance()._mmioMap(ra,pages);
}

int VmmManager::mmioUnmap(void* ea, size_t pages)
{
    return Singleton<VmmManager>::instance()._mmioUnmap(ea,pages);
}

void VmmManager::initSLB()
{
    register uint64_t slbRS, slbRB;

    // ESID = 0, V = 1, Index = 1.
    slbRB = 0x0000000008000001; 
    
    // B = 01 (1TB), VSID = 0, Ks = 0, Kp = 1, NLCLP = 0
    slbRS = 0x4000000000000400;
    
    asm volatile("slbia" ::: "memory");
    asm volatile("isync" ::: "memory");    
    asm volatile("slbmte %0, %1" :: "r"(slbRS), "r"(slbRB) : "memory");

    // ESID = 2TB, V = 1, Index = 3
    slbRB = 0x0000020008000003;
    // B = 01 (1TB), VSID = 2TB, Ks = 0, Kp = 1, NLCLP = 0
    slbRS = 0x4000020000000400;

    asm volatile("slbmte %0, %1" :: "r"(slbRS), "r"(slbRB) : "memory");
    asm volatile("isync" ::: "memory");
}

void VmmManager::initPTEs()
{
    // Initialize and invalidate the page table
    PageTableManager::init();

    // Set up linear map for every 4K page
    for(size_t i = 0; i < (FULL_MEM_SIZE / PAGESIZE); i++)
    {
	ACCESS_TYPES access = NORMAL_ACCESS;
	if (0 == i)
	{
	    access = NO_USER_ACCESS;
	}
	else if (((uint64_t)&data_load_address) > (i * PAGESIZE))
	{
	    access = READ_O_ACCESS;
	}

        PageTableManager::addEntry( i*PAGESIZE, i, access );
    }
}

void VmmManager::initSDR1()
{
    // HTABORG, HTABSIZE = 0 (11 bits, 256k table)
    register uint64_t sdr1 = (uint64_t)HTABORG;
    asm volatile("mtsdr1 %0" :: "r"(sdr1) : "memory");
}

bool VmmManager::_pteMiss(task_t* t)
{
    lock.lock();

    uint64_t effAddr = getDAR();
    uint64_t effPid = effAddr / FULL_MEM_SIZE;

    
    if (effPid <= LinearSpace)
    {
	lock.unlock();
	return false;	// Should not get this exception in Linear space
			// because it is all mapped in all the time.
    }
    
    // Check for exception in MMIO vs Dynamic Stack space.
    if (effPid <= MMIOSpace)
    {
	// Do MMIO mapping.
	uint64_t effAddrPage = (effAddr - FULL_MEM_SIZE) / PAGESIZE;

	// Check for valid entry in MMIO map.
	uint64_t mmioMapEntry = mmioMapT[effAddrPage];
	if (0 == mmioMapEntry)
	{
	    lock.unlock();
	    return false;
	}
	
	uint64_t mmioMapPage = mmioMapEntry / PAGESIZE;

	// Update PTE.
        PageTableManager::addEntry( effAddr, mmioMapPage, CI_ACCESS );
	
	lock.unlock();
	return true;
    }
    else
    {
	// TODO: Do dynamic stack mapping.
	lock.unlock();
	return false;
    }
}

void* VmmManager::_mmioMap(void* ra, size_t pages)
{
    lock.lock();

    ssize_t match = -1;
    uint64_t _ra = (uint64_t) ra;

    // Search for memory already mapped in.
    for (size_t i = 0; i < MMIO_T_ENTRIES; i++)
    {
	if ((mmioMapT[i] & ~(PAGESIZE - 1)) == _ra)
	{
	    if (i + pages < MMIO_T_ENTRIES)
	    {
		bool matched = true;
		for (size_t j = 1; j < pages; j++)
		{
		    if ((mmioMapT[i+j] & ~(PAGESIZE - 1)) != 
			(_ra + (j*PAGESIZE)))
		    {
			matched = false; 
			break;
		    }
		}
		if (matched)
		{
		    match = i;
		    break;
		}
	    }
	}
    }
    
    // Found region already mapped in.
    if (-1 != match)
    {
	// Increment ref counts.
	for (size_t i = 0; i < pages; i++)
	{
	    mmioMapT[match + i]++;
	}
	// Return calculated effective address.
	lock.unlock();
	return (void*)(FULL_MEM_SIZE + (match * PAGESIZE));
    }

    // Search for empty region in map.
    for (size_t i = 0; i < MMIO_T_ENTRIES; i++)
    {
	if (0 == mmioMapT[i])
	{
	    bool matched = true;
	    for (size_t j = 1; j < pages; j++)
	    {
		if (0 != mmioMapT[i+j])
		{
		    matched = false;
		    break;
		}
	    }
	    if (matched)
	    {
		match = i;
		break;
	    }
	}
    }

    // Found region to use for map.
    if (-1 != match)
    {
	for (size_t i = 0; i < pages; i++)
	{
	    mmioMapT[match + i] = _ra + 1; // RA + ref count of 1.
	}

	lock.unlock();
	return (void*)(FULL_MEM_SIZE + (match * PAGESIZE));
    }

    // No entry found and no space for more, return NULL.
    lock.unlock();
    return NULL;
}

int VmmManager::_mmioUnmap(void* ea, size_t pages)
{
    return -1;
}

