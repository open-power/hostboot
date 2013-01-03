/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/devtree/bld_devtree.C $                               */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include <devtree/devtree_reasoncodes.H>
#include <devtree/devtreeif.H>
#include "devtree.H"
#include <sys/mmio.h> //THIRTYTWO_GB
#include <intr/interrupt.H>


trace_desc_t *g_trac_devtree = NULL;
TRAC_INIT(&g_trac_devtree, "DEVTREE", 4096);

namespace DEVTREE
{
using   namespace   TARGETING;

enum BuildConstants
{
    DEVTREE_DATA_ADDR   =0xFF00000,    /* 256MB - 1MB*/
    DEVTREE_SPACE_SIZE  =0x10000,      /*64KB*/
    XSCOM_NODE_SHIFT    =38,           /*Node pos is 25, so 63-25=38*/
    XSCOM_CHIP_SHIFT    =35,           /*Chip pos is 28, so 63-28=35*/
    CHIPID_NODE_SHIFT   =3,            /*CHIPID is NNNCCC, shift 3*/
    PHB0_MASK           =0x80,
    MAX_PHBs            = 3,           /*Max PHBs per chip is 3*/
};


errlHndl_t bld_fdt_cpu(devTree * i_dt)
{
    errlHndl_t errhdl = NULL;
    const char* cpuNodeName = "PowerPC,POWER8";
    const char* cpuIntrName = "interrupt-controller";
    const char* xscomNodeName = "xscom";
    const char* todNodeName = "chiptod";
    const char* pciNodeName = "pbcq";
    const char* lpcNodeName = "lpc";
    const uint32_t THREADPERCORE = 8;

    /* Find the / node and add a cpus node under it. */
    dtOffset_t rootNode = i_dt->findNode("/");
    dtOffset_t cpusNode = i_dt->addNode(rootNode, "cpus");

    // Grab a system object to work with
    TARGETING::Target* sys = NULL;
    TARGETING::targetService().getTopLevelTarget(sys);
    uint64_t l_xscomBaseAddr =
      sys->getAttr<TARGETING::ATTR_XSCOM_BASE_ADDRESS>();


    /* Add the # address & size cell properties to /cpus. */
    i_dt->addPropertyCell32(cpusNode, "#address-cells", 1);
    i_dt->addPropertyCell32(cpusNode, "#size-cells", 0);

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


    // Get all functional proc chip targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for ( size_t proc = 0; (!errhdl) && (proc < l_cpuTargetList.size()); proc++)
    {
        const TARGETING::Target * l_pProc = l_cpuTargetList[proc];

        uint32_t l_fabId = l_pProc->getAttr<TARGETING::ATTR_FABRIC_NODE_ID>();
        uint32_t l_procPos = l_pProc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
        uint32_t l_chipid = (l_fabId << CHIPID_NODE_SHIFT) + l_procPos;

        /* Find calculate the Xscom addr for this chip and add it */
        uint64_t l_xscomAddr = l_xscomBaseAddr +
          (static_cast<uint64_t>(l_chipid) << XSCOM_CHIP_SHIFT);

        dtOffset_t xscomNode = i_dt->addNode(rootNode, xscomNodeName,
                                             l_xscomAddr);

        uint64_t xscom_prop[2] = { l_xscomAddr,  THIRTYTWO_GB};
        i_dt->addPropertyCells64(xscomNode, "reg", xscom_prop, 2);
        const char* xscom_compatStrs[] = {"ibm,xscom","ibm,power8-xscom",NULL};
        i_dt->addPropertyCell32(xscomNode, "#address-cells", 1);
        i_dt->addPropertyCell32(xscomNode, "#size-cells", 1);
        i_dt->addPropertyCell32(xscomNode, "ibm,chip-id", l_chipid);
        i_dt->addPropertyStrings(xscomNode, "compatible", xscom_compatStrs);


        /*ChipTod*/
        uint32_t l_todInfo = 0x40000; /*Chip tod Scom addr*/
        dtOffset_t todNode = i_dt->addNode(xscomNode, todNodeName, l_todInfo);
        const char* tod_compatStrs[] = {"ibm,power-chiptod",
                                        "ibm,power8-chiptod", NULL};
        i_dt->addPropertyStrings(todNode, "compatible", tod_compatStrs);
        uint32_t tod_prop[2] = { l_todInfo, 0x34 }; //# of scoms in range
        i_dt->addPropertyCells32(todNode, "reg", tod_prop, 2);

        if(l_chipid == 0x0) //Master chip
        {
            i_dt->addProperty(todNode, "primary");  //TODO -- get from  ATTR

            uint32_t l_lpcInfo = 0xB0020; /*ECCB FW addr*/
            dtOffset_t lpcNode = i_dt->addNode(xscomNode,lpcNodeName,l_lpcInfo);
            i_dt->addPropertyString(lpcNode, "compatible", "ibm,power8-lpc");
            uint32_t lpc_prop[2] = { l_lpcInfo, 0x4 }; //# of scoms in range
            i_dt->addPropertyCells32(lpcNode, "reg", lpc_prop, 2);
        }

        /*PCIE*/
        uint8_t l_phbActive =
                       l_pProc->getAttr<TARGETING::ATTR_PROC_PCIE_PHB_ACTIVE>();
        //TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION_type l_laneEq =
        //  l_pProc->getAttr<TARGETING::ATTR_PROC_PCIE_LANE_EQUALIZATION>();
        uint32_t l_laneEq[] = {0,0,0,0};

        TRACFCOMP( g_trac_devtree, "Chip %X PHB Active mask %X",
                   l_chipid, l_phbActive);

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
            i_dt->addPropertyCell32(pcieNode, "ibm,lane-eq", l_laneEq[l_phb]);
        }

        TARGETING::TargetHandleList l_exlist;
        getChildChiplets( l_exlist, l_pProc, TYPE_CORE );
        for (size_t core = 0; core < l_exlist.size(); core++)
        {
            const TARGETING::Target * l_ex = l_exlist[core];
            if(l_ex->getAttr<TARGETING::ATTR_HWAS_STATE>().functional != true)
            {
                continue; //Not functional
            }

            /* TODO -- need to add cache info */

            /* Add a dev node for each cpu core. The unit address is the
             *interrupt server number of the first thread of the core.
             */

            /* Proc ID Reg is N NNCC CPPP PTTT Where
                               NNN           is node number
                                  CCC        is Chip
                                     PPPP    is the core number
                                         TTT is Thread num
             */
            uint32_t l_coreNum = l_ex->getAttr<TARGETING::ATTR_CHIP_UNIT>();
            INTR::PIR_t pir(0);
            pir.nodeId = l_fabId;
            pir.chipId = l_procPos;
            pir.coreId = l_coreNum;

            TRACFCOMP( g_trac_devtree, "Added pir[%x] node %d proc %d core %d",
                       pir.word, l_fabId, l_procPos, l_coreNum );

            cpusNode = i_dt->findNode("/cpus");
            dtOffset_t cpuNode = i_dt->addNode(cpusNode, cpuNodeName,
                                               pir.word);
            i_dt->addPropertyString(cpuNode, "device_type", "cpu");
            i_dt->addPropertyString(cpuNode, "status", "okay");
            i_dt->addPropertyCell32(cpuNode, "reg", pir.word);
            i_dt->addPropertyCell32(cpuNode, "d-cache-size", 0x10000);
            i_dt->addPropertyCell32(cpuNode, "i-cache-size", 0x8000);
            i_dt->addPropertyCell32(cpuNode, "d-cache-line-size", 128);
            i_dt->addPropertyCell32(cpuNode, "i-cache-line-size", 128);
            i_dt->addPropertyCell32(cpuNode, "ibm,dfp", 1);
            i_dt->addPropertyCell32(cpuNode, "ibm,vmx", 2);
            i_dt->addPropertyCell32(cpuNode, "timebase-frequency", 512000000);
            i_dt->addPropertyCell32(cpuNode, "clock-frequency", 2000000000);
            i_dt->addPropertyCell32(cpuNode, "ibm,pir", pir.word);
            i_dt->addPropertyCell32(cpuNode, "ibm,chip-id", l_chipid);
            i_dt->addPropertyCells32(cpuNode, "ibm,processor-segment-sizes",
                                     segmentSizes,
                                     sizeof(segmentSizes) / sizeof(uint32_t));
            i_dt->addPropertyCells32(cpuNode, "ibm,segment-page-sizes",
                                     segmentPageSizes,
                                     sizeof(segmentPageSizes)/sizeof(uint32_t));
            i_dt->addPropertyCell32(cpuNode, "ibm,slb-size", 32);

            uint32_t interruptServerNum[THREADPERCORE];
            for(size_t i = 0; i < THREADPERCORE ; i++)
            {
                pir.threadId = i;
                interruptServerNum[i] = pir.word;
            }

            i_dt->addPropertyCells32(cpuNode, "ibm,ppc-interrupt-server#s",
                                     interruptServerNum, THREADPERCORE);

            //IBASE ADDRESS
            uint64_t l_ibase = INTR::getIntpAddr(l_ex, 0);

            rootNode = i_dt->findNode("/");
            dtOffset_t intNode = i_dt->addNode(rootNode, cpuIntrName, l_ibase);
            const char* intr_compatStrs[] = {"ibm,ppc-xicp", "ibm,power8-xicp",
                                             NULL};
            i_dt->addPropertyStrings(intNode, "compatible", intr_compatStrs);
            uint32_t int_serv[2] = { interruptServerNum[0], THREADPERCORE};
            i_dt->addPropertyCells32(intNode, "ibm,interrupt-server-ranges",
                                     int_serv, 2);
            i_dt->addPropertyCell32(intNode, "#address-cells", 0);
            i_dt->addPropertyCell32(intNode, "#interrupt-cells", 1);
            i_dt->addPropertyString(intNode, "device_type",
                                    "PowerPC-External-Interrupt-Presentation");
            uint64_t intr_prop[THREADPERCORE][2];
            for(size_t i=0; i < THREADPERCORE; i++)
            {
                intr_prop[i][0] = INTR::getIntpAddr(l_ex, i);
                intr_prop[i][1] = 0x1000;
            }
            i_dt->addPropertyCells64(intNode, "reg",
                                     reinterpret_cast<uint64_t*>(intr_prop),
                                     sizeof(intr_prop) / sizeof(uint64_t));

            /* TODO add associativity*/
        }
    }

    return errhdl;
}

errlHndl_t bld_fdt_mem(devTree * i_dt)
{
    errlHndl_t errhdl = NULL;
    bool rc;

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

                    /*TODO -- add core affinity*/

                    /*TODO -- add VPD*/
                }
            }
        }
    }while(0);
    return errhdl;
}

errlHndl_t bld_fdt_io(devTree * i_dt)
{
    errlHndl_t errhdl = NULL;



    return errhdl;
}

errlHndl_t build_flatdevtree( void )
{
    errlHndl_t errhdl = NULL;
    devTree * dt = &Singleton<devTree>::instance();

    do
    {

        TRACFCOMP( g_trac_devtree, "---devtree init---" );
        dt->initialize(DEVTREE_DATA_ADDR, DEVTREE_SPACE_SIZE);

        TRACFCOMP( g_trac_devtree, "---devtree cpu ---" );
        errhdl = bld_fdt_cpu(dt);
        if(errhdl)
        {
            break;
        }

        TRACFCOMP( g_trac_devtree, "---devtree mem ---" );
        errhdl = bld_fdt_mem(dt);
        if(errhdl)
        {
            break;
        }

        TRACFCOMP( g_trac_devtree, "---devtree io  ---" );
        errhdl = bld_fdt_io(dt);
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
