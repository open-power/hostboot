#include <util/singleton.H>
#include <kernel/vmmmgr.H>
#include <kernel/console.H>

VmmManager::VmmManager()
{
}

void VmmManager::init()
{
    printk("Starting VMM...");
    
    VmmManager& v = Singleton<VmmManager>::instance();

    //v.initSLB();
    v.initPTEs();
    v.initSDR1();

    printk("done.\n");
};

void VmmManager::initSLB()
{
    register uint64_t slbRS, slbRB;

    // ESID = 0, V = 1, Index = 0.
    slbRB = 0x0000000008000000; 
    
    // B = 01 (1TB), VSID = 0, Ks = 0, Kp = 1, NLCLP = 0
    slbRS = 0x4000000000000400;

    asm volatile("slbmte %0, %1" :: "r"(slbRS), "r"(slbRB) : "memory");
}

void VmmManager::initPTEs()
{
    // Invalidate all.
    for(int i = 0; i < PTEG_COUNT; i++)
	for (int j = 0; j < PTEG_SIZE; j++)
	    setValid(false, getPte(i,j));
    
    // Set up linear map.
    for(int i = 0; i < (FULL_MEM_SIZE / PAGESIZE); i++)
    {
	pte_t& pte = getPte(i, 0);
	defaultPte(pte);
	setTid(LinearSpace, pte);
	setAccess( (0 == i) ? NO_USER_ACCESS : NORMAL_ACCESS, pte);
	setPage(i, pte);
	setValid(true, pte);
    }
}

void VmmManager::initSDR1()
{
    // HTABORG << 17, HTABSIZE = 0 (11 bits, 256k table)
    register uint64_t sdr1 = (((uint64_t)HTABORG) << 17);
    asm volatile("mtsdr1 %0" :: "r"(sdr1) : "memory");
}


VmmManager::pte_t* VmmManager::page_table = (VmmManager::pte_t*) HTABORG;
