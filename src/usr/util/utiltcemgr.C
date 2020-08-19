/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/util/utiltcemgr.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#ifndef __UTILTCEMGR_C
#define __UTILTCEMGR_C

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <util/utiltce.H>
#include <util/align.H>
#include <sys/mmio.h>
#include <sys/mm.h>
#include <sys/misc.h>
#include <arch/ppc.H>
#include <errno.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>
#include <kernel/console.H>
#include "utiltcemgr.H"
#include <util/util_reasoncodes.H>
#include <assert.h>
#include <intr/interrupt.H>
#include <limits.h>
#include <hwas/common/hwasCallout.H>
#include <attributetraits.H>
#include <pnor/pnorif.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <initservice/initserviceif.H>
#include <sbeio/sbeioif.H>
#include <runtime/runtime.H>

trace_desc_t* g_trac_tce = nullptr;
TRAC_INIT(&g_trac_tce, UTILTCE_TRACE_NAME, 4*KILOBYTE);

// ------------------------
// Macros for unit testing - leave extra trace enabled for now
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)


namespace TCE
{

/************************************************************************/
// Defines
/************************************************************************/
// TCE Table Address must be 4MB Aligned
#define TCE_TABLE_ADDRESS_ALIGNMENT (4*MEGABYTE)


/************************************************************************/
//  External Interface:
//  NAME: utilAllocateTces
//     Responsible for allocating TCEs
//
/************************************************************************/
errlHndl_t utilAllocateTces(const uint64_t i_startingAddress,
                            const size_t   i_size,
                            uint32_t&      o_startingToken,
                            const bool     i_rwNotRO)
{
    return Singleton<UtilTceMgr>::instance().allocateTces(i_startingAddress,
                                                          i_size,
                                                          o_startingToken,
                                                          i_rwNotRO);
};

/************************************************************************/
// External Interface:
// NAME: utilDeallocateTces
//     Responsible for deallocating TCEs
//
/************************************************************************/
errlHndl_t utilDeallocateTces(const uint32_t i_startingToken)
{
    return Singleton<UtilTceMgr>::instance().deallocateTces(i_startingToken);
};


/************************************************************************/
// External Interface:
// NAME: utilDisableTces
//     Responsible for disabling TCE on the system, including
//     deallocating TCE Entries and disabling the Processor settings
//
/************************************************************************/
errlHndl_t utilDisableTces(void)
{
    return Singleton<UtilTceMgr>::instance().disableTces();
};

/************************************************************************/
// External Interface:
// NAME: getTceManager
//       Returns a copy of Singleton<UtilTceMgr>::instance()
//
/************************************************************************/
UtilTceMgr&  getTceManager(void)
{
   return Singleton<UtilTceMgr>::instance();
};

errlHndl_t utilSetupPayloadTces(void)
{
    errlHndl_t errl = nullptr;

    uint64_t addr=0x0;
    size_t   size=0x0;
    uint32_t token=0x0;
    uint8_t  nodeId = TARGETING::UTIL::getCurrentNodePhysId();

    do{

    TRACFCOMP(g_trac_tce,ENTER_MRK"utilSetupPayloadTces(): nodeId=0x%X", nodeId);
    // Get the hostboot base address adjusted for mirrored
    // memory if neccessary
    const uint64_t hostboot_base_address = RUNTIME::getHbBaseAddr();

    // Allocate TCEs for PAYLOAD to Temporary Space
    addr = hostboot_base_address + MCL_TMP_ADDR;
    size = MCL_TMP_SIZE;
    TRACFCOMP(g_trac_tce,"utilSetupPayloadTces(): addr=0x%.16llX, hrmor=0x%.16llX, size=0x%X", addr, hostboot_base_address, size);

    errl = utilAllocateTces(addr, size, token);
    if (errl)
    {
        TRACFCOMP(g_trac_tce,"utilSetupPayloadTces(): ERROR back from utilAllocateTces() for PAYLOAD using addr=0x%.16llX, size=0x%llX", addr, size);
        break;
    }
    else
    {
        TRACUCOMP(g_trac_tce,"utilSetupPayloadTces(): utilAllocateTces() for PAYLOAD: addr=0x%.16llX, size=0x%llX, token=0x%X", addr, size, token);
    }

    // Set attribute to tell FSP what the PAYLOAD token is
    TARGETING::Target* pNodeTgt = TARGETING::UTIL::getCurrentNodeTarget();
    pNodeTgt->setAttr<TARGETING::ATTR_TCE_START_TOKEN_FOR_PAYLOAD>(token);

    // For PSI Diagnostics Test the FSP writes and reads back patterns to the
    // PAYLOAD section via PSI and FSI so it needs to know the starting memory
    // address of this section and have an unsecure read-write memory region
    // opened for it
    pNodeTgt->setAttr<TARGETING::ATTR_START_MEM_ADDRESS_FOR_PAYLOAD_TCE_TOKEN>(addr);

    // Save for internal use since can't trust FSP won't change attribute
    Singleton<UtilTceMgr>::instance().setToken(UtilTceMgr::PAYLOAD_TOKEN,
                                               token);

    // Open Read-Write Unsecure Memory Region
    errl = SBEIO::openUnsecureMemRegion(addr,
                                        size,
                                        true,     //Read-Write
                                        nullptr); //Master Processor

    if (errl)
    {
        TRACFCOMP(g_trac_tce,"utilSetupPayloadTces(): ERROR back from SBEIO::openUnsecureMemRegion() for PAYLOAD using addr=0x%.16llX, size=0x%llX", addr, size);
        break;
    }

    // Allocate TCEs for HDAT
    // -- Address must be HRMOR-specific
    addr = hostboot_base_address + HDAT_TMP_ADDR;
    size = HDAT_TMP_SIZE;

    errl = utilAllocateTces(addr, size, token);
    if (errl)
    {
        TRACFCOMP(g_trac_tce,"utilSetupPayloadTces(): ERROR back from utilAllocateTces() for HDAT using addr=0x%.16llX, size=0x%llX", addr, size);
        break;
    }
    else
    {
        TRACUCOMP(g_trac_tce,"utilSetupPayloadTces(): utilAllocateTces() for HDAT: addr=0x%.16llX, size=0x%llX, token=0x%X", addr, size, token);
    }

    // Set attribute to tell FSP what the HDAT token is
    pNodeTgt->setAttr<TARGETING::ATTR_TCE_START_TOKEN_FOR_HDAT>(token);

    // Save for internal use since we can't trust FSP won't change the attribute
    Singleton<UtilTceMgr>::instance().setToken(UtilTceMgr::HDAT_TOKEN,
                                               token);

    } while(0);

    TRACFCOMP(g_trac_tce,EXIT_MRK"utilSetupPayloadTces(): errl_rc=0x%X", ERRL_GETRC_SAFE(errl));

    return errl;
}

errlHndl_t utilClosePayloadTces(void)
{
    errlHndl_t errl = nullptr;

    uint32_t token=0x0;
    uint8_t  nodeId = TARGETING::UTIL::getCurrentNodePhysId();

    do{

    TRACFCOMP(g_trac_tce,ENTER_MRK"utilClosePayloadTces(): nodeId=0x%X", nodeId);

    // Close PAYLOAD TCEs
    token = Singleton<UtilTceMgr>::instance().getToken(UtilTceMgr::PAYLOAD_TOKEN);
    errl = utilDeallocateTces(token);
    if (errl)
    {
        TRACFCOMP(g_trac_tce,"utilClosePayloadTces(): ERROR back from utilDeallocateTces() using token=0x%.8X", token);
        break;
    }

    // Get the hostboot base address adjusted for mirrored
    // memory if neccessary
    const uint64_t hostboot_base_address = RUNTIME::getHbBaseAddr();
    // Close the Unsecure Memory Region that was opened for the FSP to run
    // PSI Diagnostics Test using the PAYLOAD section
    // -- addr is a constant for PAYLOAD
    uint64_t addr = hostboot_base_address + MCL_TMP_ADDR;
    TRACUCOMP(g_trac_tce,"utilClosePayloadTces(): addr=0x%.16llX, hrmor=0x%.16llX", addr, hostboot_base_address);

    errl = SBEIO::closeUnsecureMemRegion(addr,
                                         nullptr); //Master Processor
    if(errl)
    {
        TRACFCOMP(g_trac_tce,"utilClosePayloadTces(): ERROR back from closeUnsecureMemRegion() using start address=0x%016llX",addr);
        break;
    }

    // Close HDAT TCEs
    token = Singleton<UtilTceMgr>::instance().getToken(UtilTceMgr::HDAT_TOKEN);
    errl = utilDeallocateTces(token);
    if (errl)
    {
        TRACFCOMP(g_trac_tce,"utilClosePayloadTces(): ERROR back from utilDeallocateTces() using token=0x%.8X", token);
        break;
    }


    } while(0);

    TRACFCOMP(g_trac_tce,EXIT_MRK"utilClosePayloadTces(): errl_rc=0x%X", ERRL_GETRC_SAFE(errl));

    return errl;
}


/************************************************************************/
//
// NAME: UtilTceMgr
//      Constructor - set up Tce Table pointers
//
/************************************************************************/
UtilTceMgr::UtilTceMgr(const uint64_t i_tableAddr, const size_t i_tableSize)
  :iv_isTceHwInitDone(false)
  ,iv_isTceTableInitDone(false)
  ,iv_tceTableVaAddr(0)
  ,iv_tceTablePhysAddr(i_tableAddr)
  ,iv_tceEntryCount(0)
  ,iv_tceTableSize(i_tableSize)
  ,iv_payloadToken(INVALID_TOKEN_VALUE)
  ,iv_hdatToken(INVALID_TOKEN_VALUE)
{
    // Get the hostboot base address adjusted for mirrored
    // memory if neccessary
    const uint64_t hostboot_base_address = RUNTIME::getHbBaseAddr();

    iv_tceTablePhysAddr = hostboot_base_address + TCE_TABLE_ADDR;

    // Table Address must be 4MB Aligned and default input is TCE_TABLE_ADDR
    static_assert( TCE_TABLE_ADDR % TCE_TABLE_ADDRESS_ALIGNMENT == 0,"TCE Table must align on 4 MB boundary");
    assert( iv_tceTablePhysAddr % TCE_TABLE_ADDRESS_ALIGNMENT == 0,"TCE Table must align on 4 MB boundary: 0x%.16llX", iv_tceTablePhysAddr);

    // TCE Entry counts are based on the following assumption
    static_assert((sizeof(uint64_t) == sizeof(TceEntry_t)), "TceEntry_t struct must be size of uint64_t)");

    // i_tableSize must be a multiple of TCE Entries
    assert( i_tableSize % sizeof(TceEntry_t) == 0,"TCE Table Size (0x%llX) must be multiple of TceEntry_t size (0x%X))", i_tableSize, sizeof(TceEntry_t));

    iv_tceEntryCount = iv_tceTableSize/(sizeof (uint64_t));


    TRACFCOMP(g_trac_tce,"UtilTceMgr::UtilTceMgr: iv_tceTableVaAddr=0x%.16llX, iv_tceTablePhysAddr=0x%.16llX, iv_tceTableSize=0x%llX, iv_tceEntryCount=0x%X, iv_allocatedAddrs,size=%d, hostboot_base_address=0x%.16llX", iv_tceTableVaAddr, iv_tceTablePhysAddr, iv_tceTableSize, iv_tceEntryCount, iv_allocatedAddrs.size(), hostboot_base_address);

    // Initialize HW without Initializing Table so that FSP cannot DMA
    // to memory without Hostboot control
    auto errl = UtilTceMgr::initTceInHdw();
    if (errl)
    {
        uint32_t errl_eid = errl->eid();
        TRACFCOMP(g_trac_tce,"UtilTceMgr::UtilTceMgr initTceInHdw() failed with rc=0x%X. Shutting down"
                  TRACE_ERR_FMT, ERRL_GETRC_SAFE(errl), TRACE_ERR_ARGS(errl));
        errl->setSev(ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM);
        errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
        errlCommit( errl, UTIL_COMP_ID );
        INITSERVICE::doShutdown(errl_eid, true);
    }

};

/**************************************************************************/
//
// NAME: createTceTable
//      Utilty to map the Tce Table
//
/**************************************************************************/
errlHndl_t UtilTceMgr::createTceTable()
{
    errlHndl_t errl = nullptr;

    TRACFCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::createTceTable: iv_tceTableVaAddr=0x%.16llX, iv_tceTablePhysAddr = 0x%.16llX,iv_tceTableSize = 0x%llX, iv_tceEntryCount=0x%X, iv_isTceTableInitDone=%d", iv_tceTableVaAddr, iv_tceTablePhysAddr, iv_tceTableSize, iv_tceEntryCount, iv_isTceTableInitDone);

    do
    {
        // If init was already run, then skip here
        if (iv_isTceTableInitDone)
        {
            TRACFCOMP(g_trac_tce,"UtilTceMgr::createTceTable: iv_isTceTableInitDone (%d) already true, so skipping init", iv_isTceTableInitDone);
            break;
        }


        // check to make sure the TCE table is not larger than Max Table Size
        if (iv_tceTableSize > MAX_TCE_TABLE_SIZE)
        {
            // TCE table size larger than 32M.. code bug likely as the real
            //   TCE table is a fixed address and size.
            TRACFCOMP(g_trac_tce,"UtilTceMgr::createTceTable: Table size 0x%X too large (>0x%llX) - cannot map.", iv_tceTableSize, MAX_TCE_TABLE_SIZE);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_CREATE_TABLE
             * @reasoncode   Util::UTIL_TCE_INVALID_SIZE
             * @userdata1    Size of of the table that is too large
             * @userdata2    Max TCE Table Size
             * @devdesc      TCE Table size requested too large.
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_CREATE_TABLE,
                                           Util::UTIL_TCE_INVALID_SIZE,
                                           iv_tceTableSize,
                                           MAX_TCE_TABLE_SIZE,
                                           true /*Add HB SW Callout*/);
            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;

        }


        // Check that iv_tceEntryCount isn't larger than MAX_NUM_TCE_TABLE_ENTRIES
        if (iv_tceEntryCount > MAX_NUM_TCE_TABLE_ENTRIES )
        {
            // TCE Count is larger than TCE Table Can Support
            TRACFCOMP(g_trac_tce,"UtilTceMgr::createTceTable: iv_tceEntryCount 0x%X too large (>0x%llX) - cannot map.", iv_tceEntryCount, MAX_NUM_TCE_TABLE_ENTRIES);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_CREATE_TABLE
             * @reasoncode   Util::UTIL_TCE_INVALID_COUNT
             * @userdata1    Number of TCEs Requested
             * @userdata2    Max Number of TCEs that TCE Table can hold
             * @devdesc      TCE Table size requested too large.
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(
                                           ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_CREATE_TABLE,
                                           Util::UTIL_TCE_INVALID_COUNT,
                                           iv_tceEntryCount,
                                           MAX_NUM_TCE_TABLE_ENTRIES,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Check that the TCE TABLE Address is aligned on 4MB
        if (iv_tceTablePhysAddr % (4*MEGABYTE))
        {
            // Address not page aligned
            TRACFCOMP(g_trac_tce,ERR_MRK"UtilTceMgr::createTceTable: Table Addr 0x%.16llX not aligned on 4MB Boundary", iv_tceTablePhysAddr);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_CREATE_TABLE
             * @reasoncode   Util::UTIL_TCE_ADDR_NOT_ALIGNED
             * @userdata1    Phyiscal Address of the TCE Table
             * @userdata2    <unused>
             * @devdesc      TCE Table not page aligned.
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_CREATE_TABLE,
                                           Util::UTIL_TCE_ADDR_NOT_ALIGNED,
                                           iv_tceTablePhysAddr,
                                           0,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

       // Allocate Memory for TCE Table
       // - Reserve a block of physical memory and get a pointer to
       //   virtual memory to manipulate it
       iv_tceTableVaAddr = reinterpret_cast<uint64_t>(mm_block_map(
                              reinterpret_cast<void*>(iv_tceTablePhysAddr),
                              iv_tceTableSize));

        // Check that a valid Virtual Memory Address was returned
        if (reinterpret_cast<void*>(iv_tceTableVaAddr) == nullptr)
        {
            // Invalid Virtual Address was returned
            TRACFCOMP(g_trac_tce,ERR_MRK"UtilTceMgr::createTceTable: mm_block_map for Table Addr 0x%.16llX and size=0x%X returned NULL", iv_tceTablePhysAddr, iv_tceTableSize);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_CREATE_TABLE
             * @reasoncode   Util::UTIL_ERC_BAD_PTR
             * @userdata1    Physical Address of the TCE Table
             * @userdata2    Requested Size of the TCE Table
             * @devdesc      TCE Table Could Not Be Block-Mapped
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_CREATE_TABLE,
                                           Util::UTIL_ERC_BAD_PTR,
                                           iv_tceTablePhysAddr,
                                           iv_tceTableSize,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Zero out the TCE Table space
        memset(reinterpret_cast<void*>(iv_tceTableVaAddr), 0, iv_tceTableSize);

        // make sure that the memset completes.
        sync();

    }while(0);

    // If succsesfull set init to true
    if ((errl == nullptr) &&
        (iv_isTceTableInitDone == false))
    {
        iv_isTceTableInitDone = true;

        // Successfully initialized the TCE table and hardware.
        TRACUCOMP(g_trac_tce, "UtilTceMgr::createTceTable: TCE Table initialized and setup: iv_isTceTableInitDone=%d", iv_isTceTableInitDone);
    }

    TRACFCOMP(g_trac_tce, EXIT_MRK"UtilTceMgr::createTceTable: iv_tceTableVaAddr=0x%.16llX, iv_tceTablePhysAddr = 0x%.16llX,iv_tceTableSize = 0x%llX, iv_tceEntryCount=0x%X, iv_isTceTableInitDone=%d", iv_tceTableVaAddr, iv_tceTablePhysAddr, iv_tceTableSize, iv_tceEntryCount, iv_isTceTableInitDone);

    return errl;
}


/**************************************************************************/
//
// NAME: initTceInHdw
//      Responsible for setting up the Processors to point to the TCE table
//
/**************************************************************************/
errlHndl_t UtilTceMgr::initTceInHdw()
{
    errlHndl_t errl = nullptr;

    TRACFCOMP(g_trac_tce, ENTER_MRK"UtilTceMgr::initTceInHdw: iv_tceTablePhysAddr = 0x%.16llX, iv_isTceHwInitDone=%d", iv_tceTablePhysAddr, iv_isTceHwInitDone);

    do
    {
        // If init was already run, then skip here
        if (iv_isTceHwInitDone)
        {
            TRACFCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: iv_isTceHwInitDone (%d) already true, so skipping init", iv_isTceHwInitDone);
            break;
        }

        // Loop through the processors and setup PSI Host Bridge for TCE
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        for ( auto l_pTarget : l_cpuTargetList )
        {

            void * PsiBridgeAddr = nullptr;
            INTR::PSIHB_SW_INTERFACES_t * l_psihb_ptr = nullptr;
            TarTceAddrRegister_t l_tar;

            // MMIO Map the PSI Host Bridge
            errl = mapPsiHostBridge(l_pTarget, PsiBridgeAddr);
            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: call to mapPsiHostBridge failed with rc=0x%X, plid=0x%X. Committing Log, but continuing the loop", ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
                errlCommit( errl, UTIL_COMP_ID );
                continue;
            }

            TRACUCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: Psi Bridge Addr = 0x%.16llX huid = 0x%.8X", PsiBridgeAddr, TARGETING::get_huid(l_pTarget));

            l_psihb_ptr = reinterpret_cast<INTR::PSIHB_SW_INTERFACES_t*>
                                           (PsiBridgeAddr);

            // Read back PSIHBBAR
            TRACUCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: Read Back psihbbar = 0x%.16llX", l_psihb_ptr->psihbbar);


            // Set TAR - TCE Address Register
            // Put the TCE Table Starting Physical Address and set up the
            // system for max of 512K entries
            l_tar.WholeTAR=0;

            // Since iv_tceTablePhysAddr already checked for 4MB alignment in
            // createTceTable() we can copy it directly in here
            l_tar.WholeTAR = iv_tceTablePhysAddr;
            l_tar.tceEntries = TAR_TCE_ENTRIES_512K;

            TRACFCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: iv_tceTablePhysAddr = 0x%.16llX, l_psihb_ptr=0x%.16llX, TAR=0x%.16llX",iv_tceTablePhysAddr, l_psihb_ptr, l_tar.WholeTAR);

            l_psihb_ptr->tceaddr = l_tar.WholeTAR;

            eieio();

            TRACUCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: Read Back tceaddr = 0x%.16llX", l_psihb_ptr->tceaddr);

            // Turn on TCE enable PSI Host Bridge Secure Register
            l_psihb_ptr->phbsecure = PHBSECURE_TCE_ENABLE;

            eieio();

            TRACUCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: Read Back phbsecure = 0x%.16llX", l_psihb_ptr->phbsecure);

            // Unmap the PSI Host Bridge
            errl = unmapPsiHostBridge(PsiBridgeAddr);
            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: call to unmapPsiHostBridge failed with rc=0x%X, plid=0x%X. Committing Log, but continuing the loop", ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
                errlCommit( errl, UTIL_COMP_ID );
                continue;
            }
            TRACUCOMP(g_trac_tce,"UtilTceMgr::initTceInHdw: After unmap: Psi Bridge Addr = 0x%.16llX huid = 0x%.8X", PsiBridgeAddr, TARGETING::get_huid(l_pTarget));

        }

    }while(0);

    // If succsesfull set init to true
    if ((errl == nullptr) &&
        (iv_isTceHwInitDone == false))
    {
        iv_isTceHwInitDone = true;

        // Successfully initialized the TCE table and hardware.
        TRACUCOMP(g_trac_tce, "UtilTceMgr::initTceInHdw: TCE initialized and setup");
    }

    TRACFCOMP(g_trac_tce, EXIT_MRK"UtilTceMgr::initTceInHdw: iv_isTceHwInitDone=%d", iv_isTceHwInitDone);

    return errl;
}


/************************************************************************/
//
//  NAME: allocateTces
//     Responsible for allocating TCE Entries
//
/************************************************************************/
errlHndl_t UtilTceMgr::allocateTces(const uint64_t i_startingAddress,
                                    const size_t   i_size,
                                    uint32_t&      o_startingToken,
                                    const bool     i_rwNotRO)
{
    errlHndl_t errl = nullptr;
    uint32_t numTcesNeeded = 0;
    o_startingToken = 0;

    TceEntry_t *tablePtr = nullptr;

    TRACFCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::allocateTces: start for addr = 0x%.16llX , size = 0x%X, rwNorRO=%d", i_startingAddress, i_size, i_rwNotRO);

    do
    {
        // Assert if i_size is not greater than zero
        assert(i_size > 0, "UtilTceMgr::allocateTces: i_size = %d, not greater than zero", i_size);

        // Expecting a page-aligned starting address
        if (i_startingAddress % PAGESIZE)
        {
            TRACFCOMP(g_trac_tce,ERR_MRK"UtilTceMgr::allocateTces: ERROR-Address 0x%.16llX not page aligned", i_startingAddress);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_ALLOCATE
             * @reasoncode   Util::UTIL_TCE_ADDR_NOT_ALIGNED
             * @userdata1    Address to start TCE
             * @userdata2    Size of the address space trying to get TCEs
             *               for.
             * @devdesc      The Physical Address for the TCE entry is not
             *               page aligned.
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_ALLOCATE,
                                           Util::UTIL_TCE_ADDR_NOT_ALIGNED,
                                           i_startingAddress,
                                           i_size,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Calculate the number of TCE entries needed - rounding up
        numTcesNeeded = ALIGN_PAGE(i_size)/PAGESIZE;

        // If more than the number of TCEs available are expected or the
        // size is too big then error out
        if ((numTcesNeeded > iv_tceEntryCount) ||
            (i_size > MAX_TCE_MEMORY_SPACE))
        {
            TRACFCOMP(g_trac_tce,ERR_MRK"UtilTceMgr::allocateTces: ERROR - Too many entries (0x%X) requested (>0x%X) (i_size=0x%X)", numTcesNeeded, iv_tceEntryCount, i_size);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_ALLOCATE
             * @reasoncode   Util::UTIL_TCE_INVALID_SIZE
             * @userdata1[0:31]  Number of TCEs Needed
             * @userdate1[32:64] Maximum Number of Tce Entries
             * @userdata2    Size of the address space trying to get TCEs
             * @devdesc      The size requested is too large for the TCE table
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_ALLOCATE,
                                           Util::UTIL_TCE_INVALID_SIZE,
                                           TWO_UINT32_TO_UINT64(
                                             numTcesNeeded,
                                             iv_tceEntryCount),
                                           i_size,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Check to see if we've already allocated TCEs associated with
        // this starting address
        bool previouslyAllocated = false;
        uint32_t pos = 0;
        for ( auto const& map_itr : iv_allocatedAddrs )
        {
           if (map_itr.second.start_addr == i_startingAddress)
           {
               // found the starting address
               previouslyAllocated = true;
               pos = map_itr.first;
               break;
           }
        }

        if(previouslyAllocated)
        {
            // This starting address has already had TCEs allocated for it
            TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: ERROR - This starting address 0x%.16llX already has TCEs allocated (pos=0x%X)", i_startingAddress, pos);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_ALLOCATE
             * @reasoncode   Util::UTIL_TCE_PREVIOUSLY_ALLOCATED
             * @userdata1    Starting Address
             * @userdata2    Starting TCE position in TCE Table
             * @devdesc      The starting address was previously allocated
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_ALLOCATE,
                                           Util::UTIL_TCE_PREVIOUSLY_ALLOCATED,
                                           i_startingAddress,
                                           pos,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Check to see if createTceTable ran before allocate.  If not we
        // need to create the table and make sure it is mapped.
        // If we are in multi-node we would run create on only 1 node and
        // other nodes could use that table
        if (!iv_isTceTableInitDone)
        {
            // createTceTable has not run
            TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: createTceTable has not run so call createTceTable() here.");

            errl = createTceTable();

            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: createTceTable() failed with rc=0x%X",ERRL_GETRC_SAFE(errl));
                break;
            }
        }

        // Check to see if HW has been initialized to use the TCEs
        if (!iv_isTceHwInitDone)
        {
            // TceInit did not run before allocate was called so call it here
            TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: initTceInHdw has not run yet: call it now");

            errl = initTceInHdw();

            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: initTceInHdw() failed with rc=0x%X",ERRL_GETRC_SAFE(errl));
                break;
            }
        }

        tablePtr = reinterpret_cast<TceEntry_t*>(iv_tceTableVaAddr);

        // Find a first consecutive group of TCEs requested
        uint32_t startingIndex = 0;
        bool found = false;

        // Start at the beginning and search for the first empty entry
        for (uint32_t tceIndex = 0;
             tceIndex < iv_tceEntryCount;
             ++tceIndex)
        {
            // Look for no-write AND no-read access for the entry to be empty
            if (tablePtr[tceIndex].readAccess == 0 &&
                tablePtr[tceIndex].writeAccess == 0)
            {
                uint32_t availIndex = 0;

                // if not enough space avail.
                if (numTcesNeeded+tceIndex > iv_tceEntryCount)
                {
                    break;
                }
                for (uint32_t IndexInRow = tceIndex;
                     IndexInRow < numTcesNeeded + tceIndex;
                     IndexInRow++)
                {
                    // If the entry has no read or write access then the
                    // entry is available
                    if (tablePtr[IndexInRow].readAccess == 0 &&
                        tablePtr[IndexInRow].writeAccess == 0)
                    {
                        // Increment availIndex
                        availIndex++;
                    }
                    // found a valid entry so need to start the count over.
                    else
                    {
                        // increment past the tce entries we already checked
                        tceIndex = IndexInRow+1;

                        // reset the avail index
                        availIndex = 0;

                        break;
                    }

                    // If we found enough consecutive TCE entries
                    if (availIndex >= numTcesNeeded)
                    {
                        // set the starting index
                        startingIndex = tceIndex;
                        // mark it found
                        found = true;
                        break;
                    }
                }
                // break out and update the table
                if (found)
                {
                    break;
                }

                // did not find consecutive TCE entries so continue.
            }
        }

        TRACUCOMP(g_trac_tce,"UtilTceMgr::allocateTces: found=%d, startingIndex=0x%X, numTcesNeeded=0x%X", found, startingIndex, numTcesNeeded);

        if (found)
        {
            // Do a for loop here to loop through the number of TCE entries
            // and set the valid bits.  The real page number gets incremented
            // by 1 for each entry
            for ( uint32_t i = 0, index=startingIndex;
                  i < numTcesNeeded;
                  ++i, ++index )
            {
                tablePtr[index].realPageNumber = (i_startingAddress +
                                                  (i*PAGESIZE))/PAGESIZE;

                if (i_rwNotRO)
                {
                    tablePtr[index].writeAccess = 1;
                }
                tablePtr[index].readAccess = 1;

                TRACDCOMP(g_trac_tce,INFO_MRK"UtilTceMgr::allocateTces: TCE Entry/Token[%d] (hex) = 0x%llX", index, tablePtr[index]);
            }

            // Save And Return Information about Allocated TCEs
            // Key to this map is the token, which is a DMA address that =
            // (Starting Index in TCE Table) * PAGESIZE
            o_startingToken = startingIndex*PAGESIZE;
            iv_allocatedAddrs[o_startingToken].start_addr = i_startingAddress;
            iv_allocatedAddrs[o_startingToken].size = i_size;

            TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: SUCCESSFUL: addr = 0x%.16llX, size = 0x%llX, starting entry=0x%X",i_startingAddress, i_size, startingIndex);
        }
        else  // not found means not enough space for request
        {
            TRACFCOMP(g_trac_tce,"UtilTceMgr::allocateTces: ERROR -Not enough free entries for this request: addr=0x%.16llX, size=0x%llX, startingIndex=0x%X, numTcesNeeded=0x%X", i_startingAddress, i_size, startingIndex, numTcesNeeded);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_ALLOCATE
             * @reasoncode   Util::UTIL_TCE_NOT_ENOUGH_FREE_ENTRIES
             * @userdata1[0:31]  Number of TCEs Needed
             * @userdate1[32:64] Starting Index in TCE Table
             * @userdata2    Size of address space TCEs are tying to map to
             * @devdesc      Requested size is too large to fit into TCE Table
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(
                                 ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                 Util::UTIL_TCE_ALLOCATE,
                                 Util::UTIL_TCE_NOT_ENOUGH_FREE_ENTRIES,
                                 TWO_UINT32_TO_UINT64(
                                   numTcesNeeded,
                                   startingIndex),
                                 i_size,
                                 true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }
    }while(0);

    TRACFCOMP(g_trac_tce, EXIT_MRK"UtilTceMgr::allocateTces: END: addr = 0x%.16llX and size = 0x%X, numTcesNeeded=0x%X. returning o_startingToken=0x%.8X", i_startingAddress, i_size, numTcesNeeded, o_startingToken);
    printIvMap(); //Debug

    return errl;
}


/*************************************************************************/
//
// NAME: deallocateTces
//     Responsible for deallocating TCE Entries
//
/*************************************************************************/
errlHndl_t UtilTceMgr::deallocateTces(const uint32_t i_startingToken)
{

    errlHndl_t errl = nullptr;
    bool isContiguous = true;
    uint32_t startingIndex = 0x0;
    uint64_t startingAddress = 0x0;
    size_t size = 0;

    TceEntry_t *tablePtr = nullptr;

    TRACFCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::deallocateTces: Token = 0x%.8X", i_startingToken);

    do
    {
        // Assert if i_startingToken is not aligned on PAGESIZE
        assert((i_startingToken % PAGESIZE) == 0, "UtilTceMgr::deallocateTces: i_startingToken (0x%.8X) is not page aligned", i_startingToken);

        std::map<uint32_t, TceEntryInfo_t>::iterator map_itr
                 = iv_allocatedAddrs.find(i_startingToken);
        if( map_itr == iv_allocatedAddrs.end() )
        {
            // Can't find this starting token. Trace that nothing happens,
            // but do not create an error log
            TRACFCOMP(g_trac_tce,INFO_MRK"UtilTceMgr::deallocateTces: Can't find match of Starting Token = 0x%.16llX", i_startingToken);
            break;
        }
        else
        {
            startingIndex = (map_itr->first) / PAGESIZE;
            startingAddress = map_itr->second.start_addr;
            size = map_itr->second.size;
        }

        // Assert if size is not greater than zero
        assert(size > 0, "UtilTceMgr::deallocateTces: i_size = %d, not greater than zero", size);

        // Get number of TCEs needed - rounding up
        uint32_t numTcesNeeded = ALIGN_PAGE(size)/PAGESIZE;

        TRACUCOMP(g_trac_tce,"UtilTceMgr::deallocateTces: size=0x%X, numTcesNeeded=0x%X, startingAddress = 0x%X", size, numTcesNeeded, startingAddress);

        // startingIndex is larger than the max number of indexes avail
        // --OR-- startingIndex and the number of TCEs needed exceeds the
        // number of TCEs in the Table
        if (startingIndex > iv_tceEntryCount ||
            startingIndex+numTcesNeeded > iv_tceEntryCount)
        {
            TRACFCOMP(g_trac_tce,ERR_MRK"UtilTceMgr::deallocateTces:  Invalid startingAddress=0x%X and/or numTcesNeeded=0x%X for table with iv_tceEntryCount=0x%X (startingIndex=0x%X), No deallocate.", startingAddress, numTcesNeeded, iv_tceEntryCount, startingIndex);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_DEALLOCATE
             * @reasoncode   Util::UTIL_TCE_INVALID_SIZE
             * @userdata1[0:31]    starting index
             * @userdata1[32:63]   number of TCEs needed for this request
             * @userdata2    Number of Entries Current TCE Table Supports
             * @devdesc      The size requested is too large based on the
             *               startingAddress the space avilable in the table
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_DEALLOCATE,
                                           Util::UTIL_TCE_INVALID_SIZE,
                                           TWO_UINT32_TO_UINT64(
                                             startingIndex,
                                             numTcesNeeded),
                                           iv_tceEntryCount,
                                           true /*Add HB SW Callout*/);
            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);

            errlCommit(errl,UTIL_COMP_ID);

            break;
        }

        // Currently do not check for valid entries.. Just clear as
        // requested.
        uint64_t previousAddress = 0;

        tablePtr = reinterpret_cast<TceEntry_t*>(iv_tceTableVaAddr);

        for (uint32_t tceIndex = startingIndex;
             tceIndex < (startingIndex + numTcesNeeded);
             tceIndex++)
        {

            // check that the address space is contiguous
            if ((tceIndex != startingIndex) &&
                ((tablePtr[tceIndex].realPageNumber  -
                     previousAddress) != 1))
            {
                isContiguous = false;
                TRACUCOMP(g_trac_tce,INFO_MRK"UtilTceMgr::deallocateTces: isContiguous set to false (%d) for tablePtr[tceIndex=0x%X]=0x%.16llX, previousAddress_RPN=0x%X", isContiguous, tceIndex, tablePtr[tceIndex].WholeTceEntry, previousAddress);
            }

            // Save off real address of page pointed to be this TCE for
            // isContiguous check on next interation
            previousAddress = tablePtr[tceIndex].realPageNumber;

            // Clear out the TCE entry to 0
            tablePtr[tceIndex].WholeTceEntry = 0;
        }

        // Remove the entry from iv_allocatedAddrs even if 'isContiguous' issue
        iv_allocatedAddrs.erase(i_startingToken);

        if (!isContiguous)
        {
            // We know the range to delete is not contingous. The address and
            // size inputs crossesd other allocates.
            // Error log created to indicate this but will clear number of
            // entries requested by caller
            TRACFCOMP(g_trac_tce,"UtilTceMgr::deallocateTces: ERROR - request was not contiguous TCE entries");

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_DEALLOCATE
             * @reasoncode   Util::UTIL_TCE_ENTRY_NOT_CONTIGUOUS
             * @userdata1    Starting address of the TCEs to be deallocated
             * @userdata2    Size of the address space to be deallocated
             * @devdesc      The deallocate went across TCE Allocate space.
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                           Util::UTIL_TCE_DEALLOCATE,
                                           Util::UTIL_TCE_ENTRY_NOT_CONTIGUOUS,
                                           startingAddress,
                                           size,
                                           true /*Add HB SW Callout*/);
            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);

            TRACFCOMP(g_trac_tce,"UtilTceMgr::deallocateTces: not-contiuguos ERROR created (rc=0x%X) and committed", ERRL_GETRC_SAFE(errl));
            errlCommit(errl,UTIL_COMP_ID);
            break;
        }

    }while(0);

    TRACFCOMP(g_trac_tce,"UtilTceMgr::deallocateTces: COMPLETE for Token = 0x%.8X, Addr = 0x%.16llX for size = 0x%X, errl=0x%X",i_startingToken, startingAddress, size, ERRL_GETRC_SAFE(errl));
    printIvMap(); //Debug

    return errl;
}


/**************************************************************************/
//
// NAME: disableTce
//      Deallocate any TCE entries and disable HW settings
//
/**************************************************************************/
errlHndl_t UtilTceMgr::disableTces(void)
{
    errlHndl_t errl = nullptr;
    int64_t rc = 0;

    TRACUCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::disableTces: iv_isTceHwInitDone=%d, iv_tceTableVaAddr=0x%.16llX iv_isTceTableInitDone=%d", iv_isTceHwInitDone, iv_tceTableVaAddr, iv_isTceTableInitDone );

    do {

    // If the HW was initialized to use TCEs then disable those settings
    // it needs to be released here
    if (iv_isTceHwInitDone==true)
    {
        // Loop through the processors and clear the TCE-related registers
        // in the PSI Host Bridge
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

        for ( auto l_pTarget : l_cpuTargetList )
        {
            void * PsiBridgeAddr = nullptr;
            INTR::PSIHB_SW_INTERFACES_t * l_psihb_ptr = nullptr;

            // MMIO Map the PSI Host Bridge
            errl = mapPsiHostBridge(l_pTarget, PsiBridgeAddr);
            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::disableTces: call to mapPsiHostBridge failed with rc=0x%X, plid=0x%X. Committing Log, but continuing the loop", ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl)); 

                errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
                errlCommit( errl, UTIL_COMP_ID );
                continue;
            }

            TRACUCOMP(g_trac_tce,"UtilTceMgr::disableTces: Psi Bridge Addr = 0x%.16llX huid = 0x%.8X", PsiBridgeAddr, TARGETING::get_huid(l_pTarget));

            l_psihb_ptr = reinterpret_cast<INTR::PSIHB_SW_INTERFACES_t*>
                                           (PsiBridgeAddr);

            // Read back PSIHBBAR
            TRACUCOMP(g_trac_tce,"UtilTceMgr::disableTces: Read Back psihbbar = 0x%.16llX", l_psihb_ptr->psihbbar);

            // Turn off TCE enable PSI Host Bridge Secure Register
            l_psihb_ptr->phbsecure = 0x0;

            eieio();

            TRACUCOMP(g_trac_tce,"UtilTceMgr::disableTces: Read Back phbsecure = 0x%.16llX", l_psihb_ptr->phbsecure);

            // Clear TAR - TCE Address Register
            l_psihb_ptr->tceaddr = 0x0;

            eieio();

            TRACUCOMP(g_trac_tce,"UtilTceMgr::disableTces: Read Back tceaddr = 0x%.16llX", l_psihb_ptr->tceaddr);

            // Unmap the PSI Host Bridge
            errl = unmapPsiHostBridge(PsiBridgeAddr);
            if (errl)
            {
                TRACFCOMP(g_trac_tce,"UtilTceMgr::disableTces: call to unmapPsiHostBridge failed with rc=0x%X, plid=0x%X. Committing Log, but continuing the loop", ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));

                errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
                errlCommit( errl, UTIL_COMP_ID );
                continue;
            }
            TRACUCOMP(g_trac_tce,"UtilTceMgr::disableTces: After unmap: Psi Bridge Addr = 0x%.16llX huid = 0x%.8X", PsiBridgeAddr, TARGETING::get_huid(l_pTarget));

        }

        // Clear the class variable
        iv_isTceHwInitDone=false;

    }
    else
    {
        TRACFCOMP(g_trac_tce,"UtilTceMgr::disableTces: No Need To Uninitialize HW: iv_isTceHwInitDone=%d", iv_isTceHwInitDone);
    }

    // Cleanup TCE Table In Memory
    if ( (iv_tceTableVaAddr!= 0) && (iv_isTceTableInitDone==true))
    {

        // Clear TCE Table
        memset(reinterpret_cast<void*>(iv_tceTableVaAddr), 0, iv_tceTableSize);

        // Unmap TCE Table In Memory
        rc = mm_block_unmap(reinterpret_cast<void*>(iv_tceTableVaAddr));

        if ( rc )
        {
            // Got a bad rc from mm_block_unmap
            TRACFCOMP(g_trac_tce, "UtilTceMgr::disableTces: mm_unmap_block failed: rc = 0x%.16llX, iv_tceTableVaAddr=0x%.16llX iv_tceTablePhysAddr=0x%X", rc, iv_tceTableVaAddr, iv_tceTablePhysAddr, rc);

            /*@
             * @errortype
             * @moduleid     Util::UTIL_TCE_DISABLE_TCES
             * @reasoncode   Util::UTIL_TCE_BLOCK_UNMAP_FAIL
             * @userdata1    Starting virtual address of pages to be removed
             * @userdata2    Return Code from mm_block_unmap
             * @devdesc      mm_block_unmap failed for TCE Table
             * @custdesc     A problem occurred during the IPL of the system
             */
            errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           Util::UTIL_TCE_DISABLE_TCES,
                                           Util::UTIL_TCE_BLOCK_UNMAP_FAIL,
                                           iv_tceTableVaAddr,
                                           rc,
                                           true /*Add HB SW Callout*/);

            errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
            break;
        }

        // Clear the class variable
        iv_isTceTableInitDone=false;
    }
    else
    {
        TRACFCOMP(g_trac_tce,"UtilTceMgr::disableTces: iv_tceTableVaAddr == NULL (0x%.16llX) - No Cleanup of TCE Table", iv_tceTableVaAddr);
    }

    // Clear allocated addresses map
    iv_allocatedAddrs.clear();

    }while(0);

    TRACUCOMP(g_trac_tce,EXIT_MRK"UtilTceMgr::disableTces");
    printIvMap(); //Debug

    return errl;
}


/**************************************************************************/
//
// NAME: ~UtilTceMgr
//      Destructor
//
/**************************************************************************/
UtilTceMgr::~UtilTceMgr()
{
    errlHndl_t errl = nullptr;

    TRACUCOMP(g_trac_tce,"UtilTceMgr::~UtilTceMgr");

    // Call disableTce in case it hasn't already been called
    errl = disableTces();

    if (errl)
    {
        TRACFCOMP(g_trac_tce,"UtilTceMgr::~UtilTceMgr: disableTces Failed rc=0x%X. Committing plid=0x%X", ERRL_GETRC_SAFE(errl), ERRL_GETPLID_SAFE(errl));
        errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
        errlCommit( errl, UTIL_COMP_ID );
    }

    iv_allocatedAddrs.clear();
}

// Debug for printing out iv_allocatedAddrs map
void UtilTceMgr::printIvMap(void) const
{
    TRACUCOMP(g_trac_tce,"UtilTceMgr::printIvMap: size=%d", iv_allocatedAddrs.size());

    for ( auto const& map_itr : iv_allocatedAddrs )
    {
        TRACDCOMP(g_trac_tce,"UtilTceMgr: printIvMap: token=0x%.8X, addr=0x%.16llX, size=0x%.8X", map_itr.first, map_itr.second.start_addr, map_itr.second.size);
    }
}


/**************************************************************************/
//
// NAME: mapPsiHostBridge:
//       Helper function to Memory Map PSI Host Bridge
//
/**************************************************************************/
errlHndl_t UtilTceMgr::mapPsiHostBridge(const TARGETING::Target * i_tgt,
                                        void *& o_psihb_ptr) const
{
    errlHndl_t errl = nullptr;
    void * l_ptr = nullptr;
    o_psihb_ptr = nullptr;

    // Assert if i_tgt is NULL or not a Processor
    assert((i_tgt != nullptr) &&
           (i_tgt->getAttr<TARGETING::ATTR_TYPE>() == TARGETING::TYPE_PROC ),
           "UtilTceMgr::mapPsiHostBridge: i_tgt=0x%X either NULL or !TYPE_PROC",
           TARGETING::get_huid(i_tgt));

    uint64_t PsiBridgeAddr =
               i_tgt->getAttr<TARGETING::ATTR_PSI_BRIDGE_BASE_ADDR>();

    TRACUCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::mapPsiHostBridge:Psi Bridge Addr = 0x%.16llX huid = 0x%.8X", PsiBridgeAddr, TARGETING::get_huid(i_tgt));

    // Assert if the PSI_BRIDEG_BASE_ADDR is zero or not page aligned
    assert((PsiBridgeAddr != 0) &&
           ((PsiBridgeAddr - ALIGN_PAGE_DOWN(PsiBridgeAddr)) == 0),
           "PsiBridgeAddr (0x%.16llX) is ZERO or not Page Aligned",
           PsiBridgeAddr);

    // Map the device for the PSI_BRIDGE_ADDR
    l_ptr = mmio_dev_map(reinterpret_cast<void*>(PsiBridgeAddr), PAGESIZE);

    if (l_ptr == nullptr)
    {
        // Got a bad rc from device Map
        TRACFCOMP(g_trac_tce, "UtilTceMgr::mapPsiHostBtidge: Device map error.");

        /*@
         * @errortype
         * @moduleid     Util::UTIL_TCE_MAP_PSIHB
         * @reasoncode   Util::UTIL_TCE_DEV_MAP_FAIL
         * @userdata1    Address to be mapped PsiBridgeAddr
         * @userdata2    Target Unit Id
         * @devdesc      PSI Bridge device Map failed
         * @custdesc     A problem occurred during the IPL of the
         *               system
         */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       Util::UTIL_TCE_MAP_PSIHB,
                                       Util::UTIL_TCE_DEV_MAP_FAIL,
                                       PsiBridgeAddr,
                                       TARGETING::get_huid(i_tgt),
                                       true /*Add HB SW Callout*/);

        errl->addHwCallout( i_tgt,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::DELAYED_DECONFIG,
                            HWAS::GARD_NULL );

        errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
    }

    o_psihb_ptr = l_ptr;

    TRACUCOMP(g_trac_tce,EXIT_MRK"UtilTceMgr::mapPsiHostBridge: o_psihb_ptr=0x%.16llX, Psi Bridge Addr = 0x%.16llX, huid = 0x%.8X", o_psihb_ptr, PsiBridgeAddr, TARGETING::get_huid(i_tgt));

    return errl;
}


/**************************************************************************/
//
// NAME: unmapPsiHostBridge:
//       Helper function to Unmap PSI Host Bridge from Memory
//
/**************************************************************************/
errlHndl_t UtilTceMgr::unmapPsiHostBridge(void *& io_psihb_ptr) const
{
    errlHndl_t errl = nullptr;
    int64_t rc = 0;

    TRACUCOMP(g_trac_tce,ENTER_MRK"UtilTceMgr::unmapPsiHostBridge: "
                                  "io_psihb_ptr = %p", io_psihb_ptr);

    // unmap the device..
    rc = mmio_dev_unmap(io_psihb_ptr);

    if (rc != 0)
    {
        // Got a bad rc from device unmap
        TRACFCOMP(g_trac_tce, "UtilTceMgr::unmapPsiHostBridge: device unmap "
                              "error: rc=0x%X", rc);

        /*@
         * @errortype
         * @moduleid     Util::UTIL_TCE_UNMAP_PSIHB
         * @reasoncode   Util::UTIL_TCE_DEV_UNMAP_FAIL
         * @userdata1    Address to be unmapped
         * @userdata2    Return Code of mmio_dev_unmap
         * @devdesc      PSI Bridge device Map failed
         * @custdesc     A problem occurred during the IPL of the
         *               system
         */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       Util::UTIL_TCE_UNMAP_PSIHB,
                                       Util::UTIL_TCE_DEV_UNMAP_FAIL,
                                       reinterpret_cast<uint64_t>(io_psihb_ptr),
                                       rc,
                                       true /*Add HB SW Callout*/);

        errl->collectTrace(UTILTCE_TRACE_NAME,KILOBYTE);
    }
    else
    {
        io_psihb_ptr = nullptr;
        TRACUCOMP(g_trac_tce,EXIT_MRK"UtilTceMgr::unmapPsiHostBridge Successful");
    }

    return errl;
}

/**************************************************************************/
//
// NAME: getToken:
//       Returns one of two internally stored tokens
//
/**************************************************************************/

uint32_t UtilTceMgr::getToken(const tokenLabels i_tokenLabel)
{
    assert((i_tokenLabel==UtilTceMgr::PAYLOAD_TOKEN)||(i_tokenLabel==UtilTceMgr::HDAT_TOKEN),"UtilTceMgr::getToken bad input parm: 0x%X", i_tokenLabel);

    return (i_tokenLabel==UtilTceMgr::PAYLOAD_TOKEN)
            ? iv_payloadToken : iv_hdatToken;

}

/**************************************************************************/
//
// NAME: setToken:
//       Sets one of two internally stored tokens
//
/**************************************************************************/
void UtilTceMgr::setToken(const tokenLabels i_tokenLabel,
                          const uint32_t i_tokenValue)
{
    assert((i_tokenLabel==UtilTceMgr::PAYLOAD_TOKEN)||(i_tokenLabel==UtilTceMgr::HDAT_TOKEN),"UtilTceMgr::setToken bad input parm: 0x%X", i_tokenLabel);

    if (i_tokenLabel==UtilTceMgr::PAYLOAD_TOKEN)
    {
        iv_payloadToken = i_tokenValue;
    }
    else
    {
        iv_hdatToken = i_tokenValue;
    }

    return;
}


/******************************************************/
/* Miscellaneous Functions                            */
/******************************************************/
bool utilUseTcesForDmas(void)
{
    bool retVal = false;

    if (INITSERVICE::spBaseServicesEnabled())
    {
        // @TODO RTC 187906 - This could eventually default to true in all cases
        // where was have a FSP

        // Get Target Service and the system target to get ATTR_USE_TCES_FOR_DMA
        TARGETING::TargetService& tS = TARGETING::targetService();
        TARGETING::Target* sys = nullptr;
        (void) tS.getTopLevelTarget( sys );
        assert(sys, "utilUseTcesForDmas() system target is NULL");

        retVal = sys->getAttr<TARGETING::ATTR_USE_TCES_FOR_DMAS>();
    }

    TRACFCOMP(g_trac_tce,INFO_MRK"utilUseTcesForDmas: %s",
              retVal ? "TRUE" : "FALSE");

    return retVal;
}

errlHndl_t utilEnableTcesWithoutTceTable(void)
{
    errlHndl_t errl = nullptr;

    // This will call the constructor, which in turn will initialize the
    // HW to point at a TCE Table with invalid entries
    Singleton<UtilTceMgr>::instance();

    return errl;

}

}; // namespace TCE

#endif
