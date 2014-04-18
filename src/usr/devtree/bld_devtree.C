/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/bld_devtree.C $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/* $IBMCopyrightBlock:
 IBM Confidential

 OCO Source Materials

 5733-907

 (C) Copyright IBM Corp. 2011

 The source code for this program is not published or other-
 wise divested of its trade secrets, irrespective of what has
 been deposited with the U.S. Copyright Office.
$ */

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/attrrp.H>
#include <devtree/devtree_reasoncodes.H>
#include <devtree/devtreeif.H>
#include "devtree.H"
#include <sys/mmio.h> //THIRTYTWO_GB
#include <intr/interrupt.H>
#include <vpd/vpd_if.H>
#include <stdio.h>
#include <pnor/pnorif.H>
#include <sys/mm.h>
#include <util/align.H>
#include <vector>
#include <vfs/vfs.H>

trace_desc_t *g_trac_devtree = NULL;
TRAC_INIT(&g_trac_devtree, "DEVTREE", 4096);

namespace DEVTREE
{
using   namespace   TARGETING;

#define CHIPID_EXTRACT_NODE(i_chipid) (i_chipid >> CHIPID_NODE_SHIFT)
#define CHIPID_EXTRACT_PROC(i_chipid) (i_chipid & CHIPID_PROC_MASK)

enum BuildConstants
{
    DEVTREE_DATA_ADDR   =0xFF00000,    /* 256MB - 1MB*/
    DEVTREE_SPACE_SIZE  =0x10000,      /*64KB*/
    XSCOM_NODE_SHIFT    =38,           /*Node pos is 25, so 63-25=38*/
    XSCOM_CHIP_SHIFT    =35,           /*Chip pos is 28, so 63-28=35*/
    CHIPID_NODE_SHIFT   =3,            /*CHIPID is NNNCCC, shift 3*/
    CHIPID_PROC_MASK    =0x7,            /*CHIPID is NNNCCC, shift 3*/
    PHB0_MASK           =0x80,
    MAX_PHBs            =3,             /*Max PHBs per chip is 3*/
    THREADPERCORE       =8,             /*8 threads per core*/
    MHZ                 =1000000,

    /* The Cache unit address (and reg property) is mostly free-for-all
     * as long as there is no collisions. On HDAT machines we use the
     * following encoding which I encourage you to also follow to limit
     * surprises:
     *
     * L2   :  (0x20 << 24) | PIR (PIR is PIR value of thread 0 of core)
     * L3   :  (0x30 << 24) | PIR
     * L3.5 :  (0x35 << 24) | PIR */
    L2_HDR              = (0x20 << 24),
    L3_HDR              = (0x30 << 24),
    CEN_ID_SHIFT        = 4,
    CEN_ID_TAG          = 0x80000000,
};



uint32_t getProcChipId(const TARGETING::Target * i_pProc)
{
    uint32_t l_fabId = i_pProc->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
    uint32_t l_procPos = i_pProc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
    return ( (l_fabId << CHIPID_NODE_SHIFT) + l_procPos);
}

uint64_t getHomerPhysAddr(const TARGETING::Target * i_pProc)
{
    //If running Sapphire need to place this at the top of memory
    uint64_t homerPhysAddrBase = VMM_HOMER_REGION_START_ADDR;
    if(TARGETING::is_sapphire_load())
    {
        homerPhysAddrBase = TARGETING::get_top_mem_addr();
        assert (homerPhysAddrBase != 0,
                "bld_devtree: Top of memory was 0!");
        homerPhysAddrBase -= VMM_ALL_HOMER_OCC_MEMORY_SIZE;
    }

    uint8_t tmpPos = i_pProc->getAttr<ATTR_POSITION>();
    uint64_t tmpOffset = tmpPos*VMM_HOMER_INSTANCE_SIZE;
    uint64_t targHomer = homerPhysAddrBase + tmpOffset;

    TRACFCOMP( g_trac_devtree, "proc ChipID [%X] HOMER is at %.16X",
               getProcChipId(i_pProc), targHomer );

    return targHomer;
}


void bld_xscom_node(devTree * i_dt, dtOffset_t & i_parentNode,
                    const TARGETING::Target * i_pProc, uint32_t i_chipid)
{
    const char* xscomNodeName = "xscom";
    const char* todNodeName = "chiptod";
    const char* pciNodeName = "pbcq";

    // Grab a system object to work with
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);

    uint64_t l_xscomBaseAddr =
      sys->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();

    /**********************************************************/
    /*                   Xscom node                           */
    /**********************************************************/
    uint64_t l_xscomAddr = l_xscomBaseAddr +
      (static_cast<uint64_t>(i_chipid) << XSCOM_CHIP_SHIFT);

    dtOffset_t xscomNode = i_dt->addNode(i_parentNode, xscomNodeName,
                                         l_xscomAddr);

    i_dt->addPropertyCell32(xscomNode, "#address-cells", 1);
    i_dt->addPropertyCell32(xscomNode, "#size-cells", 1);
    i_dt->addProperty(xscomNode, "scom-controller");
    const char* xscom_compatStrs[] = {"ibm,xscom","ibm,power8-xscom",NULL};
    i_dt->addPropertyStrings(xscomNode, "compatible", xscom_compatStrs);

    i_dt->addPropertyCell32(xscomNode, "ibm,chip-id", i_chipid);

    uint64_t xscom_prop[2] = { l_xscomAddr,  THIRTYTWO_GB};
    i_dt->addPropertyCells64(xscomNode, "reg", xscom_prop, 2);

    /*PSI Host Bridge*/
    uint32_t l_psiInfo = 0x2010900; /*PSI Host Bridge Scom addr*/
    dtOffset_t psiNode = i_dt->addNode(xscomNode, "psihb", l_psiInfo);
    const char* psi_compatStrs[] = {"ibm,power8-psihb-x",
    "ibm,psihb-x", NULL};
    i_dt->addPropertyStrings(psiNode, "compatible", psi_compatStrs);
    uint32_t psi_prop[2] = { l_psiInfo, 0x20 }; //# of scoms in range
    i_dt->addPropertyCells32(psiNode, "reg", psi_prop, 2);
    i_dt->addPropertyString(psiNode, "status", "ok");

    /*ChipTod*/
    uint32_t l_todInfo = 0x40000; /*Chip tod Scom addr*/
    dtOffset_t todNode = i_dt->addNode(xscomNode, todNodeName, l_todInfo);
    const char* tod_compatStrs[] = {"ibm,power-chiptod",
    "ibm,power8-chiptod", NULL};
    i_dt->addPropertyStrings(todNode, "compatible", tod_compatStrs);
    uint32_t tod_prop[2] = { l_todInfo, 0x34 }; //# of scoms in range
    i_dt->addPropertyCells32(todNode, "reg", tod_prop, 2);

    //Mark TOD pri/sec
    uint8_t l_role = i_pProc->getAttr<ATTR_TOD_ROLE>();
    if(l_role & TARGETING::TOD_ROLE_PRIMARY)
    {
        i_dt->addProperty(todNode, "primary");
    }
    if(l_role & TARGETING::TOD_ROLE_SECONDARY)
    {
        i_dt->addProperty(todNode, "secondary");
    }

    if(i_chipid == 0x0) //Master chip
    {
        uint32_t l_lpcInfo = 0xB0020; /*ECCB FW addr*/
        dtOffset_t lpcNode = i_dt->addNode(xscomNode,"lpc",l_lpcInfo);
        i_dt->addPropertyString(lpcNode, "compatible", "ibm,power8-lpc");
        uint32_t lpc_prop[2] = { l_lpcInfo, 0x4 }; //# of scoms in range
        i_dt->addPropertyCells32(lpcNode, "reg", lpc_prop, 2);
        i_dt->addPropertyCell32(lpcNode, "#address-cells", 2);
        i_dt->addPropertyCell32(lpcNode, "#size-cells", 1);

    }

    /*NX*/
    uint32_t l_nxInfo = 0x2010000; /*NX Scom addr*/
    dtOffset_t nxNode = i_dt->addNode(xscomNode, "nx", l_nxInfo);
    const char* nx_compatStrs[] = {"ibm,power-nx",
    "ibm,power8-nx", NULL};
    i_dt->addPropertyStrings(nxNode, "compatible", nx_compatStrs);
    uint32_t nx_prop[2] = { l_nxInfo, 0x4000 }; //# of scoms in range
    i_dt->addPropertyCells32(nxNode, "reg", nx_prop, 2);


    /*PCIE*/
    uint8_t l_phbActive =
      i_pProc->getAttr<TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>();
    //TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_type l_laneEq =
    //  l_pProc->getAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION>();
    uint32_t l_laneEq[] = {0,0,0,0};

    TRACFCOMP( g_trac_devtree, "Chip %X PHB Active mask %X",
               i_chipid, l_phbActive);

    for(uint32_t l_phb =0; l_phb < MAX_PHBs; l_phb++)
    {
        if(!(l_phbActive & (PHB0_MASK>>l_phb)))
        {
            continue;
        }

        TRACFCOMP( g_trac_devtree, "Adding PHB %d", l_phb);

        /*PHB is active, add to Xscom map*/
        uint32_t l_peInfo   = 0x02012000 + (l_phb * 0x400);
        uint32_t l_pciInfo  = 0x09012000 + (l_phb * 0x400);
        uint32_t l_spciInfo = 0x09013c00 + (l_phb * 0x40);
        dtOffset_t pcieNode = i_dt->addNode(xscomNode,pciNodeName,l_peInfo);
        const char* pcie_compatStrs[] = {"ibm,power8-pbcq", NULL};
        i_dt->addPropertyStrings(pcieNode, "compatible", pcie_compatStrs);
        uint32_t pcie_prop[6] = { l_peInfo, 0x20, //# of scoms in range
        l_pciInfo, 0x5, //# of scoms in range
        l_spciInfo, 0x15}; //# of scoms in range
        i_dt->addPropertyCells32(pcieNode, "reg", pcie_prop, 6);
        i_dt->addPropertyCell32(pcieNode, "ibm,phb-index", l_phb);
        i_dt->addProperty(pcieNode, "ibm,use-ab-detect");
        i_dt->addPropertyCell32(pcieNode, "ibm,lane-eq", l_laneEq[l_phb]);
    }
}

uint32_t bld_l3_node(devTree * i_dt, dtOffset_t & i_parentNode,
                     uint32_t i_pir)
{
    uint32_t l3Id = i_pir | L3_HDR;

    /* Build L3 Cache information */
    dtOffset_t l3Node = i_dt->addNode(i_parentNode, "l3-cache",l3Id);
    i_dt->addPropertyString(l3Node, "device_type", "cache");
    i_dt->addPropertyCell32(l3Node, "reg", l3Id);
    i_dt->addProperty(l3Node, "cache-unified");
    i_dt->addPropertyCell32(l3Node, "d-cache-sets", 0x8);
    i_dt->addPropertyCell32(l3Node, "i-cache-sets", 0x8);
    i_dt->addPropertyCell32(l3Node, "d-cache-size", 0x800000); //8MB
    i_dt->addPropertyCell32(l3Node, "i-cache-size", 0x800000); //8MB
    i_dt->addPropertyString(l3Node, "status", "okay");

    return i_dt->getPhandle(l3Node);
}

uint32_t bld_l2_node(devTree * i_dt, dtOffset_t & i_parentNode,
                     uint32_t i_pir, uint32_t i_nextCacheHandle)
{
    uint32_t l2Id = i_pir | L2_HDR;

    /* Build l2 Cache information */
    dtOffset_t l2Node = i_dt->addNode(i_parentNode, "l2-cache",l2Id);
    i_dt->addPropertyString(l2Node, "device_type", "cache");
    i_dt->addPropertyCell32(l2Node, "reg", l2Id);
    i_dt->addProperty(l2Node, "cache-unified");
    i_dt->addPropertyCell32(l2Node, "d-cache-sets", 0x8);
    i_dt->addPropertyCell32(l2Node, "i-cache-sets", 0x8);
    i_dt->addPropertyCell32(l2Node, "d-cache-size", 0x80000); //512KB
    i_dt->addPropertyCell32(l2Node, "i-cache-size", 0x80000); //512KB
    i_dt->addPropertyString(l2Node, "status", "okay");
    i_dt->addPropertyCell32(l2Node, "next-level-cache", i_nextCacheHandle);


    return i_dt->getPhandle(l2Node);
}

uint32_t bld_cpu_node(devTree * i_dt, dtOffset_t & i_parentNode,
                      const TARGETING::Target * i_ex,
                      INTR::PIR_t i_pir, uint32_t i_chipId,
                      uint32_t i_nextCacheHandle)
{
    /*
     * The following node must exist for each *core* in the system. The unit
     * address (number after the @) is the hexadecimal HW CPU number (PIR value)
     * of thread 0 of that core.
     */

    uint32_t paFeatures[8] = { 0x6, 0x0, 0xf6, 0x3f, 0xc7, 0x0, 0x80, 0xc0 };
    uint32_t pageSizes[4] = { 0xc, 0x10, 0x18, 0x22 };
    uint32_t segmentSizes[4] = { 0x1c, 0x28, 0xffffffff, 0xffffffff };
    uint32_t segmentPageSizes[] =
    {
        12, 0x0, 3,   /* 4k SLB page size, L,LP = 0,x1, 3 page size encodings */
        12, 0x0,      /* 4K PTE page size, L,LP = 0,x0 */
        16, 0x7,      /* 64K PTE page size, L,LP = 1,x7 */
        24, 0x38,     /* 16M PTE page size, L,LP = 1,x38 */
        16, 0x110, 2, /* 64K SLB page size, L,LP = 1,x1, 2 page size encodings*/
        16, 0x1,      /* 64K PTE page size, L,LP = 1,x1 */
        24, 0x8,      /* 16M PTE page size, L,LP = 1,x8 */
        20, 0x130, 1, /* 1M SLB page size, L,LP = 1,x3, 1 page size encoding */
        20, 0x2,      /* 1M PTE page size, L,LP = 1,x2 */
        24, 0x100, 1, /* 16M SLB page size, L,LP = 1,x0, 1 page size encoding */
        24, 0x0,      /* 16M PTE page size, L,LP = 1,x0 */
        34, 0x120, 1, /* 16G SLB page size, L,LP = 1,x2, 1 page size encoding */
        34, 0x3       /* 16G PTE page size, L,LP = 1,x3 */
    };


    dtOffset_t cpuNode = i_dt->addNode(i_parentNode, "PowerPC,POWER8",
                                       i_pir.word);
    i_dt->addPropertyString(cpuNode, "device_type", "cpu");
    i_dt->addProperty(cpuNode, "64-bit");
    i_dt->addProperty(cpuNode, "32-64-bridge");
    i_dt->addProperty(cpuNode, "graphics");
    i_dt->addProperty(cpuNode, "general-purpose");
    i_dt->addPropertyString(cpuNode, "status", "okay");
    i_dt->addPropertyCell32(cpuNode, "reg", i_pir.word);
    i_dt->addPropertyCell32(cpuNode, "ibm,pir", i_pir.word);
    i_dt->addPropertyCell32(cpuNode, "ibm,chip-id", i_chipId);

    uint32_t numThreads = 0;
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();

    uint32_t interruptServerNum[THREADPERCORE];
    for(size_t i = 0; i < THREADPERCORE ; i++)
    {
        if (en_threads & (0x8000000000000000 >> i))
        {
            i_pir.threadId = i;
            interruptServerNum[numThreads++] = i_pir.word;
        }
    }
    i_dt->addPropertyCells32(cpuNode, "ibm,ppc-interrupt-server#s",
                             interruptServerNum, numThreads);

    /* This is the "architected processor version" as defined in PAPR. Just
     * stick to 0x0f000004 for P8 and things will be fine */
    i_dt->addPropertyCell32(cpuNode, "cpu-version", 0x0f000004);

    i_dt->addPropertyCells32(cpuNode, "ibm,processor-segment-sizes",
                             segmentSizes,
                             sizeof(segmentSizes) / sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,processor-page-sizes",
                             pageSizes,
                             sizeof(pageSizes) / sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,segment-page-sizes",
                             segmentPageSizes,
                             sizeof(segmentPageSizes)/sizeof(uint32_t));
    i_dt->addPropertyCells32(cpuNode, "ibm,pa-features",
                             paFeatures,
                             sizeof(paFeatures)/sizeof(uint32_t));

    i_dt->addPropertyCell32(cpuNode, "ibm,slb-size", 32);
    i_dt->addPropertyCell32(cpuNode, "ibm,dfp", 1);
    i_dt->addPropertyCell32(cpuNode, "ibm,vmx", 2);
    i_dt->addPropertyCell32(cpuNode, "ibm,purr", 1);
    i_dt->addPropertyCell32(cpuNode, "ibm,spurr", 1);

    //Set Nominal freq
    uint64_t freq = sys->getAttr<TARGETING::ATTR_NOMINAL_FREQ_MHZ>();
    freq *= MHZ;

    uint32_t ex_freq[2] = {static_cast<uint32_t>(freq >> 32),
    static_cast<uint32_t>(freq & 0xFFFFFFFF)};
    if(ex_freq[0] == 0) //Only create if fits into 32 bits
    {
        i_dt->addPropertyCell32(cpuNode, "clock-frequency", ex_freq[1]);
    }
    i_dt->addPropertyCells32(cpuNode, "ibm,extended-clock-frequency",
                             ex_freq, 2);

    uint32_t timebase_freq[2] = {0, 512000000};
    i_dt->addPropertyCell32(cpuNode, "timebase-frequency", timebase_freq[1]);
    i_dt->addPropertyCells32(cpuNode, "ibm,extended-timebase-frequency",
                             timebase_freq, 2);


    i_dt->addPropertyCell32(cpuNode, "reservation-granule-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "d-tlb-size", 0x800);
    i_dt->addPropertyCell32(cpuNode, "i-tlb-size", 0x0);
    i_dt->addPropertyCell32(cpuNode, "tlb-size", 0x800);
    i_dt->addPropertyCell32(cpuNode, "d-tlb-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "i-tlb-sets", 0x0);
    i_dt->addPropertyCell32(cpuNode, "tlb-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "d-cache-block-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "i-cache-block-size", 0x80);
    i_dt->addPropertyCell32(cpuNode, "d-cache-size", 0x10000);
    i_dt->addPropertyCell32(cpuNode, "i-cache-size", 0x8000);
    i_dt->addPropertyCell32(cpuNode, "i-cache-sets", 0x4);
    i_dt->addPropertyCell32(cpuNode, "d-cache-sets", 0x8);
    i_dt->addPropertyCell64(cpuNode, "performance-monitor", 0x1);
    i_dt->addPropertyCell32(cpuNode, "next-level-cache", i_nextCacheHandle);

    return i_dt->getPhandle(cpuNode);
}

uint32_t bld_intr_node(devTree * i_dt, dtOffset_t & i_parentNode,
                      const TARGETING::Target * i_ex,
                      INTR::PIR_t i_pir)

{
    /*
     * Interrupt presentation controller (ICP) nodes
     *
     * There is some flexibility as to how many of these are presents since
     * a given node can represent multiple ICPs. When generating from HDAT we
     * chose to create one per core
     */

    uint64_t l_ibase = INTR::getIntpAddr(i_ex, 0);     //IBASE ADDRESS

    dtOffset_t intNode = i_dt->addNode(i_parentNode, "interrupt-controller",
                                       l_ibase);

    const char* intr_compatStrs[] = {"ibm,ppc-xicp", "ibm,power8-xicp",NULL};
    i_dt->addPropertyStrings(intNode, "compatible", intr_compatStrs);
    i_dt->addProperty(intNode,"interrupt-controller");
    i_dt->addPropertyCell32(intNode, "#address-cells", 0);
    i_dt->addPropertyCell32(intNode, "#interrupt-cells", 1);
    i_dt->addPropertyString(intNode, "device_type",
                            "PowerPC-External-Interrupt-Presentation");

    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t en_threads = sys->getAttr<TARGETING::ATTR_ENABLED_THREADS>();
    uint32_t numThreads = 0;

    uint64_t intr_prop[THREADPERCORE][2];
    for(size_t i=0; i < THREADPERCORE; i++)
    {
        if (en_threads & (0x8000000000000000 >> i))
        {
            intr_prop[numThreads][0] = INTR::getIntpAddr(i_ex, i);
            intr_prop[numThreads][1] = 0x1000;
            numThreads++;
        }
    }
    i_dt->addPropertyCells64(intNode, "reg",
                             reinterpret_cast<uint64_t*>(intr_prop),
                             numThreads * 2);

    uint32_t int_serv[2] = { i_pir.word, numThreads};
    i_dt->addPropertyCells32(intNode, "ibm,interrupt-server-ranges",
                             int_serv, 2);

    return i_dt->getPhandle(intNode);
}


void add_reserved_mem(devTree * i_dt,
                      std::vector<uint64_t>& i_homerAddr,
                      uint64_t i_extraAddr[],
                      uint64_t i_extraSize[],
                      const char* i_extraStr[],
                      uint64_t i_extraCnt)
{
    /*
     * The reserved-names and reserve-names properties work hand in hand.
     * The first one is a list of strings providing a "name" for each entry
     * in the second one using the traditional "vendor,name" format.
     *
     * The reserved-ranges property contains a list of ranges, each in the
     * form of 2 cells of address and 2 cells of size (64-bit x2 so each
     * entry is 4 cells) indicating regions of memory that are reserved
     * and must not be overwritten by skiboot or subsequently by the Linux
     * Kernel.
     *
     * Corresponding entries must also be created in the "reserved map" part
     * of the flat device-tree (which is a binary list in the header of the
     * fdt).
     *
     * Unless a component (skiboot or Linux) specifically knows about a region
     * (usually based on its name) and decides to change or remove it, all
     * these regions are passed as-is to Linux and to subsequent kernels
     * accross kexec and are kept preserved.
     */

    dtOffset_t rootNode = i_dt->findNode("/");

    size_t l_num = i_homerAddr.size();

    const char* homerStr = "ibm,slw-occ-image";
    const char* reserve_strs[l_num+i_extraCnt+1];
    uint64_t ranges[l_num+i_extraCnt][2];
    uint64_t cell_count = sizeof(ranges) / sizeof(uint64_t);
    uint64_t res_mem_addrs[l_num+i_extraCnt];
    uint64_t res_mem_sizes[l_num+i_extraCnt];

    for(size_t i = 0; i<l_num; i++)
    {
        reserve_strs[i] = homerStr;
        ranges[i][0] = i_homerAddr[i];
        ranges[i][1] = VMM_HOMER_INSTANCE_SIZE;
        res_mem_addrs[i] = i_homerAddr[i];
        res_mem_sizes[i] = VMM_HOMER_INSTANCE_SIZE;
    }

    for(size_t i = 0; i < i_extraCnt; i++)
    {
        if (i_extraAddr[i])
        {
            TRACFCOMP( g_trac_devtree, "Reserved Region %s @ %lx, %lx",
                       i_extraStr[i], i_extraAddr[i], i_extraSize[i]);

            reserve_strs[l_num] = i_extraStr[i];
            ranges[l_num][0] = i_extraAddr[i];
            ranges[l_num][1] = i_extraSize[i];

            res_mem_addrs[l_num] = i_extraAddr[i];
            res_mem_sizes[l_num] = i_extraSize[i];

            l_num++;
        }
        else
        {
            cell_count -= sizeof(ranges[0]);
        }
    }
    reserve_strs[l_num] = NULL;

    i_dt->addPropertyStrings(rootNode, "reserved-names", reserve_strs);
    i_dt->addPropertyCells64(rootNode, "reserved-ranges",
                             reinterpret_cast<uint64_t*>(ranges),
                             cell_count);

    // added per comment from Dean Sanner
    // cell_count has limit of DT_MAX_MEM_RESERVE  = 16. Is this enough
    // for all processors + 1 vpd area + 1 target area?
    i_dt->populateReservedMem(res_mem_addrs, res_mem_sizes, cell_count);
}

void load_hbrt_image(uint64_t& io_address)
{
    errlHndl_t l_errl = NULL;

    do
    {

        PNOR::SectionInfo_t l_pnorInfo;
        l_errl = getSectionInfo( PNOR::HB_RUNTIME , l_pnorInfo);
        if (l_errl) { break; }

            // Find start of image.
            //     For Secureboot we might need to deal with the header but
            //     for now that is hidden by the PNOR-RP.
        uint64_t image_start = l_pnorInfo.vaddr;

            // The "VFS_LAST_ADDRESS" variable is 2 pages in.
        uint64_t vfs_last_address =
                *reinterpret_cast<uint64_t*>(image_start + 2*PAGE_SIZE);

            // At the end of the image are the relocations, get the number.
        uint64_t relocate_count =
                *reinterpret_cast<uint64_t*>(image_start + vfs_last_address);

            // Sum up the total size.
        uint64_t image_size = vfs_last_address +
                              (relocate_count+1)*sizeof(uint64_t);

        TRACFCOMP(g_trac_devtree, "HBRT image: start = %lx, size = %lx",
                  image_start, image_size);
        io_address -= ALIGN_PAGE(image_size);

            // Copy image.
        void* memArea = mm_block_map(reinterpret_cast<void*>(io_address),
                                     ALIGN_PAGE(image_size));
        memcpy(memArea, reinterpret_cast<void*>(image_start), image_size);
        mm_block_unmap(memArea);

    } while (0);

    if (l_errl)
    {
        io_address = 0;
        errlCommit(l_errl, DEVTREE_COMP_ID);
    }
}

errlHndl_t bld_fdt_system(devTree * i_dt, bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    dtOffset_t rootNode = i_dt->findNode("/");

    //Common settings
    /* Define supported power states -- options:
                         nap, deep-sleep, fast-sleep, winkle*/
    const char* pmode_compatStrs[] = {"nap", NULL};
    i_dt->addPropertyStrings(rootNode, "ibm,enabled-idle-states",
                             pmode_compatStrs);

    // Nothing to do for small trees currently.
    if (!i_smallTree)
    {

        /* Add compatibility node */
        i_dt->addPropertyString(rootNode, "compatible", "ibm,powernv");

        /* Add system model node */
        //TODO RTC:88056 - store model type in attributes?
        i_dt->addPropertyString(rootNode, "model", "rhesus");
    }

    return errhdl;
}


errlHndl_t bld_fdt_cpu(devTree * i_dt,
                       std::vector<uint64_t>& o_homerRegions,
                       bool i_smallTree)
{
    // Nothing to do for small trees currently.
    if (i_smallTree) { return NULL; }

    errlHndl_t errhdl = NULL;

    /* Find the / node and add a cpus node under it. */
    dtOffset_t rootNode = i_dt->findNode("/");
    dtOffset_t cpusNode = i_dt->addNode(rootNode, "cpus");

    /* Add the # address & size cell properties to /cpus. */
    i_dt->addPropertyCell32(cpusNode, "#address-cells", 1);
    i_dt->addPropertyCell32(cpusNode, "#size-cells", 0);

    // Get all functional proc chip targets
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for (size_t proc = 0; (!errhdl) && (proc < l_procTargetList.size()); proc++)
    {
        const TARGETING::Target * l_pProc = l_procTargetList[proc];

        uint32_t l_chipid = getProcChipId(l_pProc);

        bld_xscom_node(i_dt, rootNode, l_pProc, l_chipid);

        //Each processor will have a HOMER image that needs
        //to be reserved -- save it away
        o_homerRegions.push_back(getHomerPhysAddr(l_pProc));

        TARGETING::TargetHandleList l_exlist;
        getChildChiplets( l_exlist, l_pProc, TYPE_CORE );
        for (size_t core = 0; core < l_exlist.size(); core++)
        {
            const TARGETING::Target * l_ex = l_exlist[core];
            if(l_ex->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
            {
                continue; //Not functional
            }

            /* Proc ID Reg is N NNCC CPPP PTTT Where
                               NNN           is node number
                                  CCC        is Chip
                                     PPPP    is the core number
                                         TTT is Thread num
             */
            uint32_t l_coreNum = l_ex->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            INTR::PIR_t pir(0);
            pir.nodeId = CHIPID_EXTRACT_NODE(l_chipid);
            pir.chipId = CHIPID_EXTRACT_PROC(l_chipid);
            pir.coreId = l_coreNum;

            TRACFCOMP( g_trac_devtree, "Added pir[%x] chipid 0x%x core %d",
                       pir.word, l_chipid, l_coreNum );

            cpusNode = i_dt->findNode("/cpus");

            uint32_t l3pHandle = bld_l3_node(i_dt, cpusNode, pir.word);
            uint32_t l2pHandle = bld_l2_node(i_dt, cpusNode, pir.word,
                                             l3pHandle);
            bld_cpu_node(i_dt, cpusNode, l_ex, pir, l_chipid, l2pHandle);

            rootNode = i_dt->findNode("/");
            bld_intr_node(i_dt, rootNode, l_ex, pir);
        }
    }

    return errhdl;
}

errlHndl_t bld_fdt_reserved_mem(devTree * i_dt,
                                std::vector<uint64_t>& i_homerRegions,
                                bool i_smallTree)
{
    errlHndl_t errhdl = NULL;

    // VPD
    uint64_t l_vpd_addr = 0;

    errhdl = VPD::vpd_load_rt_image(l_vpd_addr);

    // Targeting
    uint64_t l_targ_addr = l_vpd_addr;
    TARGETING::AttrRP::save(l_targ_addr);

    // HBRT image
    uint64_t l_hbrt_addr = l_targ_addr;
    load_hbrt_image(l_hbrt_addr);

    uint64_t l_extra_addrs[] = { l_vpd_addr, l_targ_addr, l_hbrt_addr };
    uint64_t l_extra_sizes[] = { VMM_RT_VPD_SIZE,
                                 l_vpd_addr - l_targ_addr,
                                 l_targ_addr - l_hbrt_addr};
    const char* l_extra_addrs_str[] =
                    { "ibm,hbrt-vpd-image" ,
                      "ibm,hbrt-target-image",
                      "ibm,hbrt-code-image" };
    size_t l_extra_addr_cnt = sizeof(l_extra_addrs) / sizeof(uint64_t);

    //Add in reserved memory for HOMER images and HBRT sections.
    add_reserved_mem(i_dt,
                     i_homerRegions,
                     l_extra_addrs,
                     l_extra_sizes,
                     l_extra_addrs_str,
                     l_extra_addr_cnt);

    return errhdl;

}

errlHndl_t bld_fdt_mem(devTree * i_dt, bool i_smallTree)
{
    // Nothing to do for small trees currently.
    if (i_smallTree) { return NULL; }

    errlHndl_t errhdl = NULL;
    bool rc;

    /*
     * The "memory" nodes represent physical memory in the system. They
     * do not represent DIMMs, memory controllers or Centaurs, thus will
     * be expressed separately.
     *
     * In order to be able to handle affinity propertly, we require that
     * a memory node is created for each range of memory that has a different
     * "affinity", which in practice means for each chip since we don't
     * support memory interleaved accross multiple chips on P8.
     *
     * Additionally, it is *not* required that one chip = one memory node,
     * it is perfectly acceptable to break down the memory of one chip into
     * multiple memory nodes (typically skiboot does that if the two MCs
     * are not interlaved).
     */

    do
    {
        /* Find the / node and add a memory node(s) under it. */
        dtOffset_t rootNode = i_dt->findNode("/");

        // Grab a system object to work with
        TARGETING::Target* sys = NULL;
        TARGETING::targetService().getTopLevelTarget(sys);

        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for ( size_t proc = 0;
              (!errhdl) && (proc < l_cpuTargetList.size()); proc++ )
        {
            const TARGETING::Target * l_pProc = l_cpuTargetList[proc];

            uint64_t l_bases[8] = {0,};
            uint64_t l_sizes[8] = {0,};
            rc = l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_BASES>(l_bases);
            if(!rc)
            {
                /*@
                 * @errortype
                 * @reasoncode       DEVTREE::RC_ATTR_MEMBASE_GET_FAIL
                 * @moduleid         DEVTREE::MOD_DEVTREE_BLD_MEM
                 * @userdata1        Return code from ATTR_GET
                 * @userdata2        Attribute Id that failed
                 * @devdesc          Error retrieving attribute
                 */
                errhdl=new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_DEVTREE_BLD_MEM,
                                               RC_ATTR_MEMBASE_GET_FAIL,
                                               rc,
                                               ATTR_PROC_MEM_BASES);
                break;
            }

            rc = l_pProc->tryGetAttr<TARGETING::ATTR_PROC_MEM_SIZES>(l_sizes);
            if(!rc)
            {
                /*@
                 * @errortype
                 * @reasoncode       DEVTREE::RC_ATTR_MEMSIZE_GET_FAIL
                 * @moduleid         DEVTREE::MOD_DEVTREE_BLD_MEM
                 * @userdata1        Return code from ATTR_GET
                 * @userdata2        Attribute Id that failed
                 * @devdesc          Error retrieving attribute
                 */
                errhdl=new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                               MOD_DEVTREE_BLD_MEM,
                                               RC_ATTR_MEMSIZE_GET_FAIL,
                                               rc,
                                               ATTR_PROC_MEM_SIZES);
                break;
            }

            for (size_t i=0; i< 8; i++)
            {
                if(l_sizes[i]) //non zero means that there is memory present
                {
                    dtOffset_t memNode = i_dt->addNode(rootNode, "memory",
                                                       l_bases[i]);
                    i_dt->addPropertyString(memNode, "device_type","memory");
                    uint64_t propertyCells[2] = {l_bases[i],l_sizes[i]};
                    i_dt->addPropertyCells64(memNode, "reg", propertyCells, 2);

                    //Add the attached proc chip for affinity
                    i_dt->addPropertyCell32(memNode, "ibm,chip-id",
                                            getProcChipId(l_pProc));

                }
            }
        }

        /***************************************************************/
        /* Now loop on all the centaurs in the system and add their    */
        /* inband scom address                                         */
        /***************************************************************/
        rootNode = i_dt->findNode("/");

        // Get all functional memb chip targets
        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        for ( size_t memb = 0;
              (!errhdl) && (memb < l_memBufList.size()); memb++ )
        {
            const TARGETING::Target * l_pMemB = l_memBufList[memb];

            //Get MMIO Offset from parent MCS attribute.
            PredicateCTM l_mcs(CLASS_UNIT,TYPE_MCS, MODEL_NA);

            TargetHandleList mcs_list;
            targetService().getAssociated(mcs_list,
                            l_pMemB,
                            TargetService::PARENT_BY_AFFINITY,
                            TargetService::ALL,
                            &l_mcs);

            if( mcs_list.size() != 1 )
            {
                //This error should have already been caught in
                //the inband Scom DD.... going to skip creating node
                //if true
                TRACFCOMP(g_trac_devtree,ERR_MRK" MCS for 0x%x not found",
                          TARGETING::get_huid(l_pMemB));
                continue;
            }
            Target* parentMCS = *(mcs_list.begin());
            uint64_t l_ibscomBase =
              parentMCS->getAttr<ATTR_IBSCOM_MCS_BASE_ADDR>();


            dtOffset_t membNode = i_dt->addNode(rootNode, "memory-buffer",
                                               l_ibscomBase);
            uint64_t propertyCells[2] = {l_ibscomBase,THIRTYTWO_GB};
            i_dt->addPropertyCells64(membNode, "reg", propertyCells, 2);

            uint32_t l_ec = l_pMemB->getAttr<ATTR_EC>();
            char cenVerStr[32];
            snprintf(cenVerStr, 32, "ibm,centaur-v%.2x", l_ec);
            const char* intr_compatStrs[] = {"ibm,centaur", cenVerStr,NULL};
            i_dt->addPropertyStrings(membNode, "compatible", intr_compatStrs);


            if(l_pMemB->
               getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useInbandScom == 0x0)
            {
                i_dt->addProperty(membNode,"use-fsi");
            }

            //Add the attached proc chip for affinity
            uint32_t l_procId = getProcChipId(getParentChip(parentMCS));
            i_dt->addPropertyCell32(membNode, "ibm,fsi-master-chip-id",
                                    l_procId);

            uint32_t l_cenId = CEN_ID_TAG | (l_procId << CEN_ID_SHIFT);
            l_cenId |= parentMCS->getAttr<ATTR_CHIP_UNIT>();
            i_dt->addPropertyCell32(membNode, "ibm,chip-id",l_cenId);

            //Add the CMFSI (which CMFSI 0 or 1) and port
            //TODO RTC93298 make which CMFSI correct
            uint32_t cmfsiCells[2] =
                           {0,l_pMemB->getAttr<ATTR_FSI_MASTER_PORT>()};
            i_dt->addPropertyCells32(membNode, "ibm,fsi-master-port",
                                     cmfsiCells, 2);
        }


    }while(0);
    return errhdl;
}

errlHndl_t build_flatdevtree( uint64_t i_dtAddr, size_t i_dtSize,
                              bool i_smallTree )
{
    errlHndl_t errhdl = NULL;
    devTree * dt = &Singleton<devTree>::instance();
    bool devTreeVirtual = true;

    do
    {
        if (0 == i_dtAddr)
        {
            i_dtAddr = DEVTREE_DATA_ADDR;
            i_dtSize = DEVTREE_SPACE_SIZE;
            devTreeVirtual = false;
        }

        TRACFCOMP( g_trac_devtree, "---devtree init---" );
        dt->initialize(i_dtAddr, i_dtSize, devTreeVirtual);
        errhdl = bld_fdt_system(dt, i_smallTree);
        if (errhdl)
        {
            break;
        }

        std::vector<uint64_t> l_homerRegions;

        TRACFCOMP( g_trac_devtree, "---devtree cpu ---" );
        errhdl = bld_fdt_cpu(dt, l_homerRegions, i_smallTree);
        if(errhdl)
        {
            break;
        }

        TRACFCOMP( g_trac_devtree, "---devtree reserved mem ---" );
        errhdl = bld_fdt_reserved_mem(dt, l_homerRegions, i_smallTree);
        if(errhdl)
        {
            break;
        }

        TRACFCOMP( g_trac_devtree, "---devtree mem ---" );
        errhdl = bld_fdt_mem(dt, i_smallTree);
        if(errhdl)
        {
            break;
        }

    }while(0);

    return errhdl;
}


uint64_t get_flatdevtree_phys_addr()
{
    return Singleton<devTree>::instance().getBlobPhys();
}

}
