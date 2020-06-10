/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/populate_hbruntime.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

/**
 *  @file populate_runtime.C
 *
 *  @brief Populate HDAT Area for Host runtime data
 */

#include <kernel/vmmmgr.H>
#include <sys/misc.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/initserviceif.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/entitypath.H>
#include <targeting/common/commontargeting.H>
#include <targeting/targplatutil.H>
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include "hdatstructs.H"
#include <mbox/ipc_msg_types.H>
#include <sys/task.h>
#include <intr/interrupt.H>
#include <errl/errlmanager.H>
#include <sys/internode.h>
#include <vpd/vpd_if.H>
#include <pnor/pnorif.H>
#include <targeting/attrrp.H>
#include <sys/mm.h>
#include <util/align.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <hdat/hdat.H>
#include <config.h>
#include "../hdat/hdattpmdata.H"
#include "../hdat/hdatpcrd.H"
#include "../secureboot/trusted/tpmLogMgr.H"
#include "../secureboot/trusted/trustedboot.H"
#include <targeting/common/attributeTank.H>
#include <runtime/interface.h>
#include <targeting/attrPlatOverride.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/runtime/sbe_msg_passing.H>
#include <kernel/bltohbdatamgr.H>
#include <util/utilrsvdmem.H>
#include <util/utillidpnor.H>
#include <stdio.h>
#include <runtime/populate_hbruntime.H>
#include <runtime/preverifiedlidmgr.H>
#include <util/utilmclmgr.H>
#include <pnor/pnor_reasoncodes.H>
#include <runtime/common/runtime_utils.H>
#include <limits.h>
#include <errno.h>
#include <vmmconst.h>
#include <runtime/customize_attrs_for_payload.H>
namespace RUNTIME
{

mutex_t g_rhbMutex = MUTEX_INITIALIZER;

// used for populating the TPM required bit in HDAT
const uint16_t TPM_REQUIRED_BIT = 0x8000; //leftmost bit of uint16_t set to 1

const uint8_t BITS_PER_BYTE = 8;

// The upper limit of the hostboot reserved memory. Only applies to PHYP.
// The lower limit is Hostboot HRMOR + 64MB; 4KB is the PHYP component's
// secure header.
const uint64_t HB_RES_MEM_UPPER_LIMIT = 256*MEGABYTE - 4*KILOBYTE;

// The lower limit of the hostboot reserved memory. Do not allow to reserve
// any memory below this limit.
const uint64_t HB_RES_MEM_LOWER_LIMIT = VMM_MEMORY_SIZE + VMM_HRMOR_OFFSET;

trace_desc_t *g_trac_runtime = nullptr;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);


/**
 *  @brief Get a pointer to the next available
 *          HDAT HB Reserved Memory entry
 *  @param[out] o_rngPtr Pointer to the addr range entry
 *  @return Error handle if error
 */
errlHndl_t getNextRhbAddrRange(hdatMsVpdRhbAddrRange_t* & o_rngPtr)
{
    errlHndl_t l_elog = nullptr;

    mutex_lock( &g_rhbMutex );

    do {

        TARGETING::Target * l_sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( l_sys );
        assert(l_sys != nullptr);


        uint32_t l_nextSection =
            l_sys->getAttr<TARGETING::ATTR_HB_RSV_MEM_NEXT_SECTION>();

        uint64_t l_rsvMemDataAddr = 0;
        uint64_t l_rsvMemDataSizeMax = 0;

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(mproc);

        TARGETING::EntityPath epath =
            mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        const TARGETING::EntityPath::PathElement pe =
            epath.pathElementOfType(TARGETING::TYPE_NODE);

        uint64_t nodeid = pe.instance;

        // there are 50 reserved memory spots per node,
        // use the node number to index into the hb reserved mem pointers
        // for this node. HB_RSV_MEM_NUM_PTRS is defined as the number
        // of usable pointers - see runtime.H for some background
        uint32_t instance = l_nextSection +
            ((HB_RSV_MEM_NUM_PTRS + 1) * nodeid);

        // Get the address of the next section
        l_elog = RUNTIME::get_host_data_section( RUNTIME::RESERVED_MEM,
                instance,
                l_rsvMemDataAddr,
                l_rsvMemDataSizeMax );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                    "getNextRhbAddrRange fail get_host_data_section %d",
                    l_nextSection );
            break;
        }

        o_rngPtr =
            reinterpret_cast<hdatMsVpdRhbAddrRange_t *>(l_rsvMemDataAddr);

        l_nextSection++;
        l_sys->setAttr
            <TARGETING::ATTR_HB_RSV_MEM_NEXT_SECTION>(l_nextSection);

    } while(0);

    mutex_unlock( &g_rhbMutex );

    return(l_elog);
}

errlHndl_t mapPhysAddr(uint64_t i_addr,
                       size_t i_size,
                       uint64_t& o_addr)
{
    errlHndl_t l_elog = nullptr;

    o_addr = reinterpret_cast<uint64_t>(mm_block_map(
                reinterpret_cast<void*>(i_addr), i_size));

    // Check if address returned from the block map is NULL
    if(o_addr == 0)
    {
        TRACFCOMP( g_trac_runtime,
                   "mapPhysAddr fail to map physical addr %p, size %lx",
                   reinterpret_cast<void*>(i_addr), i_size );

        /*@ errorlog tag
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        RUNTIME::MOD_MAP_PHYS_ADDR
         * @reasoncode      RUNTIME::RC_CANNOT_MAP_MEMORY
         * @userdata1       Phys address we are trying to map
         * @userdata2       Size of memory we are trying to map
         *
         * @devdesc         Error mapping a virtual memory map
         * @custdesc        Kernel failed to map memory
         */
        l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_MAP_PHYS_ADDR,
                            RUNTIME::RC_CANNOT_MAP_MEMORY,
                            i_addr,
                            i_size,
                            true);
        l_elog->collectTrace(RUNTIME_COMP_NAME);
    }

    return l_elog;
}

errlHndl_t unmapVirtAddr(uint64_t i_addr)
{
    errlHndl_t l_elog = nullptr;

    int l_rc = mm_block_unmap(reinterpret_cast<void*>(i_addr));

    if(l_rc)
    {
        TRACFCOMP( g_trac_runtime,
                   "unmapVirtAddr fail to unmap virt addr %p",
                   reinterpret_cast<void*>(i_addr));
        /*@ errorlog tag
         * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
         * @moduleid        RUNTIME::MOD_UNMAP_VIRT_ADDR
         * @reasoncode      RUNTIME::RC_UNMAP_FAIL
         * @userdata1       Virtual address we are trying to unmap
         * @userdata2       0
         * @devdesc         Error unmapping a virtual memory map
         * @custdesc        Kernel failed to unmap memory
         */
        l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_UNMAP_VIRT_ADDR,
                            RUNTIME::RC_UNMAP_FAIL,
                            i_addr,
                            0,
                            true);
        l_elog->collectTrace(RUNTIME_COMP_NAME);
    }

    return l_elog;
}


void traceHbRsvMemRange(hdatMsVpdRhbAddrRange_t* & i_rngPtr )
{
    TRACFCOMP(g_trac_runtime,
              "Setting HDAT HB Reserved Memory Range: "
              "%s RangeType 0x%X RangeId 0x%X "
              "StartAddress 0x%16llX EndAddress 0x%16llX Permissions 0x%.2X",
              i_rngPtr->hdatRhbLabelString,
              i_rngPtr->hdatRhbRngType,
              i_rngPtr->hdatRhbRngId,
              i_rngPtr->hdatRhbAddrRngStrAddr,
              i_rngPtr->hdatRhbAddrRngEndAddr,
              i_rngPtr->hdatRhbPermission);
}

errlHndl_t checkHbResMemLimit(const uint64_t i_addr, const uint64_t i_size)
{
    errlHndl_t l_errl = nullptr;

    //Get base HRMOR Base attribute
    TARGETING::Target * pTgt = NULL;
    TARGETING::targetService().getTopLevelTarget(pTgt);
    assert(pTgt != NULL);
    auto hrmor_base = pTgt->getAttr<TARGETING::ATTR_HB_HRMOR_NODAL_BASE>();

    //get this hb instance
    pTgt = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(pTgt);
    auto epath = pTgt->getAttr<TARGETING::ATTR_PHYS_PATH>();
    auto pe = epath.pathElementOfType(TARGETING::TYPE_NODE);
    auto this_node = pe.instance;

    auto hrmor = hrmor_base * this_node;
    // Only check if PHYP is running or if running in standalone.
    if(TARGETING::is_phyp_load() || TARGETING::is_no_load())
    {
        if((i_addr < (HB_RES_MEM_LOWER_LIMIT + hrmor)) or
           ((i_addr + i_size - 1) > (HB_RES_MEM_UPPER_LIMIT+hrmor)))
        {
            TRACFCOMP(g_trac_runtime, "checkHbResMemLimit> Attempt to write"
            " to hostboot reserved memory outside of allowed hostboot address"
            " range. Start addresss - 0x%08x end address - 0x%08x;"
            " bottom limit - 0x%08x top limit - 0x%08x.",
            i_addr, i_addr + i_size - 1,
            HB_RES_MEM_LOWER_LIMIT, HB_RES_MEM_UPPER_LIMIT);

            /*@
             * @errortype
             * @moduleid     RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT
             * @reasoncode   RUNTIME::RC_HB_RES_MEM_EXCEEDED
             * @userdata1    Starting address
             * @userdata2    Size of the section
             * @devdesc      Hostboot attempted to reserve memory past allowed
             *               range. Bottom limit = Hostboot HRMOR + 64M, top
             *               limit = 256M - 4K.
             * @custdesc     Hostboot attempted to reserve memory outside of
             *               allowed range.
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         RUNTIME::MOD_CHECK_HB_RES_MEM_LIMIT,
                                         RUNTIME::RC_HB_RES_MEM_EXCEEDED,
                                         i_addr,
                                         i_size,
                                         true /*Add HB Software Callout*/);
            l_errl->collectTrace(RUNTIME_COMP_NAME,KILOBYTE);
        }
    }
    return l_errl;
}

errlHndl_t setNextHbRsvMemEntry(const HDAT::hdatMsVpdRhbAddrRangeType i_type,
                                const uint16_t i_rangeId,
                                const uint64_t i_startAddr,
                                const uint64_t i_size,
                                const char* i_label,
                                const HDAT::hdatRhbPermType i_permission,
                                const bool i_checkMemoryLimit)
{
    errlHndl_t l_elog = nullptr;

    do {

    // Check whether hostboot is trying to access memory outside of its allowed
    // range.
    if(i_checkMemoryLimit)
    {
        l_elog = checkHbResMemLimit(i_startAddr, i_size);
        if(l_elog)
        {
            break;
        }
    }

    // Get a pointer to the next available HDAT HB Rsv Mem entry
    hdatMsVpdRhbAddrRange_t* l_rngPtr = nullptr;
    l_elog = getNextRhbAddrRange(l_rngPtr);
    if(l_elog)
    {
        break;
    }

    assert(l_rngPtr != nullptr, "getNextRhbAddrRange returned nullptr");

    // Determine starting address
    // Logical OR staring adddress with enum FORCE_PHYS_ADDR to
    //        ignore the HRMOR bit
    uint64_t l_startAddr = i_startAddr | VmmManager::FORCE_PHYS_ADDR;

    // Fill in the entry
    l_rngPtr->set(i_type, i_rangeId, l_startAddr, i_size, i_label,
                  i_permission);
    traceHbRsvMemRange(l_rngPtr);

    } while(0);

    return l_elog;
}

/**
 *  @brief Load the HB_DATA section for reserved memory
 *
 *  -----  HB Data Layout -------
 * io_start_address
 *    -- HB Table of Contents
 *    -- ATTR Override Data
 *    -- ATTR Data
 *    -- VPD
 *    -- Padding
 * io_end_address
 *
 * Either pass in a low starting physical address (io_start_address) or
 * a high ending physical address (io_end_address).
 * The function will then calculate the size of data and
 * determine the opposite address.
 * Set i_startAddressValid to true, if you set io_start_address.
 * Set i_startAddressValid to false, if you set io_end_address.
 *
 *  @param[in/out]  io_start_address where to start loading data
 *  @param[in/out]  io_end_address   where to stop loading data
 *  @param[in]      i_startAddressValid Is io_start_address valid?
 *  @param[out]     io_size if not zero, maxSize in bytes allowed
 *                          returns Total 64kb aligned size for all the data
 *  @return Error handle if error
 */
errlHndl_t fill_RsvMem_hbData(uint64_t & io_start_address,
                              uint64_t & io_end_address,
                              bool i_startAddressValid,
                              uint64_t & io_size)
{
    TRACFCOMP( g_trac_runtime, ENTER_MRK"fill_RsvMem_hbData> io_start_address=0x%.16llX,io_end_address=0x%.16llX,startAddressValid=%d",
                io_start_address, io_end_address, i_startAddressValid?1:0 );

    errlHndl_t l_elog = nullptr;
    uint64_t l_vAddr = 0x0;
    uint64_t l_prevDataAddr = 0;
    uint64_t l_prevDataSize = 0;

    // TOC to be filled in and added to beginning of HB Data section
    Util::hbrtTableOfContents_t l_hbTOC;
    strcpy(l_hbTOC.toc_header, "Hostboot Table of Contents");
    l_hbTOC.toc_version = Util::HBRT_TOC_VERSION_1;
    l_hbTOC.total_entries = 0;

    /////////////////////////////////////////////////////////////
    // Figure out the total size needed so we can place the TOC
    // at the beginning
    /////////////////////////////////////////////////////////////
    uint64_t l_totalSectionSize = 0;

    // Begin with ATTROVER

    // default to the minimum space we have to allocate anyway
    size_t l_attrOverMaxSize = HBRT_RSVD_MEM_OPAL_ALIGN;

    // copy overrides into local buffer
    uint8_t* l_overrideData =
      reinterpret_cast<uint8_t*>(malloc(l_attrOverMaxSize));
    size_t l_actualSize = l_attrOverMaxSize;
    l_elog = TARGETING::AttrRP::saveOverrides( l_overrideData,
                                               l_actualSize );
    if( l_elog )
    {
        // check if the issue was a lack of space (unlikely)
        if( unlikely( l_actualSize > 0 ) )
        {
            TRACFCOMP( g_trac_runtime, "Expanding override section to %d", l_actualSize );
            free(l_overrideData);
            l_overrideData =
              reinterpret_cast<uint8_t*>(malloc(l_actualSize));
            l_elog = TARGETING::AttrRP::saveOverrides( l_overrideData,
                                                       l_actualSize );
        }

        // overrides are not critical so just commit this
        //  and keep going without any
        if( l_elog )
        {
            TRACFCOMP( g_trac_runtime, "Errors applying overrides, just skipping" );
            errlCommit( l_elog, RUNTIME_COMP_ID );
            l_elog = NULL;
            l_actualSize = 0;
        }
    }

    // Should we create an ATTROVER section?
    if (l_actualSize > 0)
    {
        l_hbTOC.entry[l_hbTOC.total_entries].label =
                                                Util::HBRT_MEM_LABEL_ATTROVER;
        l_hbTOC.entry[l_hbTOC.total_entries].offset = 0;
        l_hbTOC.entry[l_hbTOC.total_entries].size = l_actualSize;
        l_totalSectionSize += ALIGN_PAGE(l_actualSize);
        l_hbTOC.total_entries++;
    }

    // Now calculate ATTR size
    l_hbTOC.entry[l_hbTOC.total_entries].label = Util::HBRT_MEM_LABEL_ATTR;
    l_hbTOC.entry[l_hbTOC.total_entries].offset = 0;
    uint64_t l_attrSize = TARGETING::AttrRP::maxSize();
    // add 10% more extra space to account for a concurrent update
    //  that adds more attributes
    l_attrSize = ((l_attrSize*110)/100);
    l_hbTOC.entry[l_hbTOC.total_entries].size = l_attrSize;
    l_totalSectionSize +=
        ALIGN_PAGE(l_hbTOC.entry[l_hbTOC.total_entries].size);
    l_hbTOC.total_entries++;

    // Fill in VPD size
    l_hbTOC.entry[l_hbTOC.total_entries].label = Util::HBRT_MEM_LABEL_VPD;
    l_hbTOC.entry[l_hbTOC.total_entries].offset = 0;
    l_hbTOC.entry[l_hbTOC.total_entries].size = VMM_RT_VPD_SIZE;
    l_totalSectionSize +=
        ALIGN_PAGE(l_hbTOC.entry[l_hbTOC.total_entries].size);
    l_hbTOC.total_entries++;

    // Fill in HYPCOMM size
    l_hbTOC.entry[l_hbTOC.total_entries].label = Util::HBRT_MEM_LABEL_HYPCOMM;
    l_hbTOC.entry[l_hbTOC.total_entries].offset = 0;
    l_hbTOC.entry[l_hbTOC.total_entries].size = sizeof(hbHypCommArea_t);
    l_totalSectionSize +=
        ALIGN_PAGE(l_hbTOC.entry[l_hbTOC.total_entries].size);
    l_hbTOC.total_entries++;

    l_totalSectionSize += sizeof(l_hbTOC);  // Add 4KB Table of Contents

    // Fill in PADDING size
    // Now calculate how much padding is needed for OPAL alignment
    // of the whole data section
    size_t l_totalSizeAligned = ALIGN_X( l_totalSectionSize,
                                         HBRT_RSVD_MEM_OPAL_ALIGN );

    // l_actualSizeAligned will bring section to OPAL alignment
    uint64_t l_actualSizeAligned = l_totalSizeAligned - l_totalSectionSize;

    // Do we need a Padding section?
    if (l_actualSizeAligned > 0)
    {
        // Add padding section
        l_hbTOC.entry[l_hbTOC.total_entries].label =
                                                Util::HBRT_MEM_LABEL_PADDING;
        l_hbTOC.entry[l_hbTOC.total_entries].offset = 0;
        l_hbTOC.entry[l_hbTOC.total_entries].size = l_actualSizeAligned;
        l_hbTOC.total_entries++;
    }

    // Set total_size to the 64k aligned size
    l_hbTOC.total_size = l_totalSizeAligned;

    do {

        if ((io_size != 0) && (io_size < l_totalSizeAligned))
        {
            // create an error
            TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData - Will exceed max allowed size %lld, need %lld",
                   io_size, l_totalSizeAligned);

            /*@ errorlog tag
             * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
             * @moduleid        RUNTIME::MOD_FILL_RSVMEM_HBDATA
             * @reasoncode      RUNTIME::RC_EXCEEDED_MEMORY
             * @userdata1       Total size needed
             * @userdata2       Size allowed
             *
             * @devdesc         Unable to fill in HB data memory
             */
            l_elog = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                RUNTIME::MOD_FILL_RSVMEM_HBDATA,
                                RUNTIME::RC_EXCEEDED_MEMORY,
                                l_totalSizeAligned,
                                io_size,
                                true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        // update return size to amount filled in
        io_size = l_totalSizeAligned;


        // Figure out the start and end addresses
        if (i_startAddressValid)
        {
            io_end_address = io_start_address + l_totalSizeAligned;
        }
        else
        {
            io_start_address = io_end_address - l_totalSizeAligned;
        }


        TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> mapping 0x%.16llX address, size %lld",
                io_start_address, l_totalSizeAligned );

        // Grab the virtual address for the entire HB Data section
        l_elog = mapPhysAddr(io_start_address, l_totalSizeAligned, l_vAddr);
        if(l_elog)
        {
            break;
        }

        TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> virtual start address: %p", l_vAddr);

        // Skip TOC at the beginning, pretend it was added
        l_prevDataAddr = l_vAddr;
        l_prevDataSize = sizeof(l_hbTOC);
        uint64_t l_offset = 0;

        int i = 0;
        while ( i < l_hbTOC.total_entries )
        {
            uint64_t actual_size = l_hbTOC.entry[i].size;
            uint64_t aligned_size = ALIGN_PAGE(actual_size);

            l_offset += l_prevDataSize;

            // update offset to current data section
            l_hbTOC.entry[i].offset = l_offset;

            l_prevDataAddr += l_prevDataSize;
            l_prevDataSize = aligned_size;

            switch ( l_hbTOC.entry[i].label )
            {
                case Util::HBRT_MEM_LABEL_ATTROVER:
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> ATTROVER  v address 0x%.16llX, size: %lld", l_prevDataAddr, aligned_size);
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> memcpy %d size", actual_size);
                    memcpy( reinterpret_cast<void*>(l_prevDataAddr),
                            l_overrideData,
                            actual_size);
                    break;
                case Util::HBRT_MEM_LABEL_ATTR:
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> ATTR v address 0x%.16llX, size: %lld", l_prevDataAddr, aligned_size);
                    l_elog = TARGETING::AttrRP::save(
                                reinterpret_cast<uint8_t*>(l_prevDataAddr),
                                aligned_size);
                    if(l_elog)
                    {
                        TRACFCOMP( g_trac_runtime,
                                   "populate_HbRsvMem fail ATTR save call" );
                        break;
                    }
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> TARGETING::AttrRP::save(0x%.16llX) done", l_prevDataAddr);
                    break;
                case Util::HBRT_MEM_LABEL_VPD:
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> VPD v address 0x%.16llX, size: %lld", l_prevDataAddr, aligned_size);
                    l_elog = VPD::vpd_load_rt_image(l_prevDataAddr);
                    if(l_elog)
                    {
                        TRACFCOMP( g_trac_runtime,
                                   "fill_RsvMem_hbData> failed VPD call" );
                        break;
                    }
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> VPD v address 0x%.16llX, size: %lld done", l_prevDataAddr, aligned_size);
                    break;
                case Util::HBRT_MEM_LABEL_HYPCOMM:
                {
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> HYPCOMM v address 0x%.16llX, size: %lld", l_prevDataAddr, aligned_size);
                    //This will call default contructor setting up the version and magic number,
                    // and zero'ing out the data area
                    TARGETING::Target * sys = NULL;
                    TARGETING::targetService().getTopLevelTarget( sys );
                    assert(sys != NULL);

                    // Figure out what kind of payload we have
                    TARGETING::PAYLOAD_KIND payload_kind
                        = sys->getAttr<TARGETING::ATTR_PAYLOAD_KIND>();

                    hbHypCommArea_t l_hbCommArea;
                    static_assert((sizeof(hbHypCommArea_t) % 8) == 0,
                                  "hbHypCommArea_t's size must be 8 byte aligned");
                    uint64_t l_hdatPtrToHrmorStashAddr = 0;
                    size_t   l_hdatPtrHrmorStashSize   = 0;
                    uint64_t * l_pHdatPtrToHrmorStashAddr;
                    // memcpy a copy of the hbHypCommArea struct into the reserved mem area
                    memcpy( reinterpret_cast<void*>(l_prevDataAddr),
                            reinterpret_cast<void*>(&l_hbCommArea),
                            sizeof(hbHypCommArea_t));

                    if(payload_kind != TARGETING::PAYLOAD_KIND_NONE)
                    {
                        //Find the v addr in hdat that the hypervisor will look
                        //at to determine where to write HRMOR and possibly in
                        //the future information in hostboot's reserved memory section.
                        l_elog = RUNTIME::get_host_data_section( RUNTIME::HRMOR_STASH,
                                                                0,
                                                                l_hdatPtrToHrmorStashAddr,
                                                                l_hdatPtrHrmorStashSize );
                        if(l_elog)
                        {
                            TRACFCOMP( g_trac_runtime,
                                    "fill_RsvMem_hbData> failed to find HRMOR stash address in HDAT" );
                            break;
                        }

                        //This should always return a size of 8 as this is a 64 bit address
                        assert(l_hdatPtrHrmorStashSize == sizeof(uint64_t),
                               "The size of the HRMOR_STASH area should always be %d bytes,  not %d",
                               sizeof(uint64_t), l_hdatPtrHrmorStashSize);

                        //Cast the value returned from get_host_data_section to a uint64_t pointer
                        l_pHdatPtrToHrmorStashAddr = reinterpret_cast<uint64_t *>(l_hdatPtrToHrmorStashAddr);

                        //Set the value of the pointer to be the physical address
                        //of the hrmor stash in the hb-hyp communication area
                        *l_pHdatPtrToHrmorStashAddr = io_start_address + l_hbTOC.entry[i].offset + HYPCOMM_STRUCT_HRMOR_OFFSET;

                        TRACFCOMP( g_trac_runtime,
                                  "fill_RsvMem_hbData> HYPCOMM v address 0x%.16llX, size: %lld done",
                                  l_prevDataAddr, aligned_size);
                    }
                    else
                    {
                        TRACFCOMP( g_trac_runtime,
                                  "fill_RsvMem_hbData> Payload kind was determined to be NONE, skipping setting up HYP comm");
                    }
                    break;
                }
                default:
                    break;
            }
            i++;
        }

        // exit if we hit an error
        if(l_elog)
        {
            break;
        }

        TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> TOC address 0x%.16llX, size: %lld", l_vAddr, sizeof(l_hbTOC));

        // Now copy the TOC at the head of the HB Data section
        memcpy( reinterpret_cast<void*>(l_vAddr),
                &l_hbTOC,
                sizeof(l_hbTOC));
    } while (0);

    if (l_vAddr != 0)
    {
        // release the virtual address
        errlHndl_t l_errl = unmapVirtAddr(l_vAddr);
        if (l_errl)
        {
            TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData> unmap %p failed", l_vAddr );
            if (l_elog)
            {
                // Already have an error log so just commit this new one
                errlCommit(l_errl, RUNTIME_COMP_ID);
            }
            else
            {
                l_elog = l_errl;
            }
        }
        l_vAddr = 0;
    }

    // free ATTR_OVERRIDE memory
    free(l_overrideData);

    TRACFCOMP( g_trac_runtime,EXIT_MRK"fill_RsvMem_hbData> io_start_address=0x%.16llX,io_end_address=0x%.16llX,size=%lld",
                io_start_address, io_end_address, io_size );

    return l_elog;
}

errlHndl_t hbResvLoadSecureSection (const PNOR::SectionId i_sec,
                                    const bool i_secHdrExpected)
{
    TRACFCOMP( g_trac_runtime,ENTER_MRK"hbResvloadSecureSection() sec %s",
              PNOR::SectionIdToString(i_sec));

    errlHndl_t l_elog = nullptr;

#ifdef CONFIG_SECUREBOOT
        auto l_sectionSecurelyLoaded = false;
#endif

    do {

        // Check for inhibited sections
        if(PNOR::isInhibitedSection(i_sec))
        {
            TRACFCOMP( g_trac_runtime, INFO_MRK"hbResvloadSecureSection() Skipping - Cannot load inhibited section %s",
                      PNOR::SectionIdToString(i_sec));
            break;
        }

        PNOR::SectionInfo_t l_info;
        l_elog = PNOR::getSectionInfo( i_sec, l_info );
        if(l_elog)
        {
            //No need to commit error here, it gets handled later
            //just break out to escape this function
            TRACFCOMP( g_trac_runtime, ERR_MRK"hbResvloadSecureSection() getSectionInfo failed");
            break;
        }

#ifdef CONFIG_SECUREBOOT
        // Skip verification if a section does not have a Secureboot Header
        if (l_info.secure)
        {
            // Securely Load PNOR section
            l_elog = loadSecureSection(i_sec);
            if (l_elog)
            {
                TRACFCOMP( g_trac_runtime,
                           ERR_MRK"hbResvloadSecureSection() - Error from "
                           "loadSecureSection(%s)", PNOR::SectionIdToString(i_sec));
                break;
            }
            l_sectionSecurelyLoaded = true;
        }
#endif

        auto l_pnorVaddr = l_info.vaddr;
        auto l_imgSize = l_info.size;

        // Check if the section is expected to have a secure header regardless
        // of compile options
#ifdef CONFIG_SECUREBOOT
        if (i_secHdrExpected)
        {
            // If section is signed, only the protected size was loaded into memory
            l_imgSize = l_info.secureProtectedPayloadSize;
            // Include secure header
            // NOTE: we do not preserve the header in virtual memory when SB
            // is compiled out. So "-PAGESIZE" only works when SB is compiled in
            l_pnorVaddr -= PAGESIZE;
        }
#endif
        // Add size for secure header, as a header is REQUIRED for lid load
        // from hostboot reserved memory to work in every scenario.
        // NOTE: if SB compiled out or a header is never added, one will be
        // injected later with min information. So preserve space for the header.
        l_imgSize += PAGESIZE;

        // Load Pnor section into HB reserved memory
        l_elog = PreVerifiedLidMgr::loadFromPnor(i_sec, l_pnorVaddr, l_imgSize);
        if(l_elog)
        {
            break;
        }
    } while(0);


#ifdef CONFIG_SECUREBOOT
    // Skip unload if a section was not securely loaded in the first place
    if (l_sectionSecurelyLoaded )
    {
        // Unload Secure PNOR section
        auto l_unloadErrlog = unloadSecureSection(i_sec);
        if (l_unloadErrlog)
        {
            TRACFCOMP( g_trac_runtime,
                       ERR_MRK"hbResvloadSecureSection() - Error from "
                       "unloadSecureSection(%s)", PNOR::SectionIdToString(i_sec));
            // Link unload error log to existing errorlog plid and commit error
            if(l_elog)
            {
                l_unloadErrlog->plid(l_elog->plid());
                ERRORLOG::errlCommit(l_unloadErrlog, RUNTIME_COMP_ID);
            }
            // This is the only error so return that.
            else
            {
                l_elog = l_unloadErrlog;
                l_unloadErrlog = nullptr;
            }
        }
    }
#endif

    return l_elog;
}

/**
 *  @brief Load the HDAT HB Reserved Memory
 *         address range structures on given node
 *  @param[in]  i_nodeId Node ID
 *  @param[in]  i_master_node = true if we are the master hb instance
 *  @return Error handle if error
 */
errlHndl_t populate_HbRsvMem(uint64_t i_nodeId, bool i_master_node)
{
    TRACFCOMP( g_trac_runtime, ENTER_MRK"populate_HbRsvMem> i_nodeId=%d", i_nodeId );
    errlHndl_t l_elog = nullptr;
    bool l_preVerLidMgrLock = false;

#ifdef CONFIG_SECUREBOOT
    auto l_hbrtSecurelyLoaded = false;
#endif

    do
    {
        // Configure the ATTR_HBRT_HYP_ID attributes so that runtime code and
        // whichever hypervisor is loaded can reference equivalent targets
        // When populating hbRuntimeData, we make IPC calls if we are running
        // on a multi-node configuration. The message handler for that IPC call,
        // calls populateHbRsvMem. We want to setup hbrt target types for all
        // the nodes. That's why, we moved this call here instead of directly
        // calling it from istep21.
        l_elog = RUNTIME::configureHbrtHypIds(TARGETING::is_phyp_load());
        if (l_elog)
        {
            TRACFCOMP(g_trac_runtime, ERR_MRK"populate_HbRsvMem> i_nodeId=%d"
                    " configureHbrtHypIds failed");
            break;
        }

        // Wipe out our cache of the NACA/SPIRA pointers
        RUNTIME::rediscover_hdat();

        if(i_master_node == true )
        {
            // Wipe out all HB reserved memory sections
            l_elog = RUNTIME::clear_host_data_section(RUNTIME::RESERVED_MEM);

            if( l_elog )
            {
                TRACFCOMP( g_trac_runtime, ERR_MRK
                        "populate_HbRsvMem> i_nodeId=%d"
                        " call to clear_host_data_section() returned error",
                        i_nodeId );
                break;
            }
        }

        uint64_t l_topMemAddr = 0x0;
        uint64_t l_vAddr = 0x0;

        // Get list of processor chips
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips,
                TARGETING::TYPE_PROC,
                true);

        if(TARGETING::is_phyp_load())
        {
            // First phyp entry is for the entire 256M HB space
            uint64_t l_hbAddr = cpu_spr_value(CPU_SPR_HRMOR)
                - VMM_HRMOR_OFFSET;
            l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_PRIMARY,
                                          i_nodeId,
                                          l_hbAddr,
                                          VMM_HB_RSV_MEM_SIZE,
                                          HBRT_RSVD_MEM__PRIMARY,
                                          HDAT::RHB_READ_WRITE,
                                          false);
            if(l_elog != nullptr)
            {
                break;
            }

        }
        else if(TARGETING::is_sapphire_load())
        {
            // Opal data goes at top_of_mem
            l_topMemAddr = TARGETING::get_top_mem_addr();
            assert (l_topMemAddr != 0,
                    "populate_HbRsvMem: Top of memory was 0!");

            // Opal HB reserved memory data
            // -----TOP_OF_MEM-------
            // -----OCC Common-------
            // -----HOMER_N----------
            // -----...--------------
            // -----HOMER_0----------
            // -----HB Data ---------
            //   -- VPD
            //   -- ATTR Data
            //   -- ATTR Override Data
            //   -- HB TOC
            // -----HBRT Image-------
            // -----SBE Comm---------
            // -----SBE FFDC---------
            // -----Secureboot cryptographic algorithms code---------
            // -----Verified Images---------
            //   -- OCC
            //   -- WOFDATA
            //   -- HCODE

            // First opal entries are for the HOMERs
            uint64_t l_homerAddr = l_topMemAddr;

            // Loop through all functional Procs
            for (const auto & l_procChip: l_procChips)
            {

                l_homerAddr = l_procChip->getAttr
                    <TARGETING::ATTR_HOMER_PHYS_ADDR>();
                // Note: the instance we use to retrieve the data must
                //   match the value we used to populate HDAT originally
                l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HOMER_OCC,
                        l_procChip->getAttr<TARGETING::ATTR_HBRT_HYP_ID>(),
                        l_homerAddr,
                        VMM_HOMER_INSTANCE_SIZE,
                        HBRT_RSVD_MEM__HOMER);
                if(l_elog)
                {
                    break;
                }
            }

            if(l_elog)
            {
                break;
            }

#ifdef CONFIG_START_OCC_DURING_BOOT
            ///////////////////////////////////////////////////
            // OCC Common entry
            if( !(TARGETING::is_phyp_load()) )
            {
                TARGETING::Target * l_sys = nullptr;
                TARGETING::targetService().getTopLevelTarget( l_sys );
                assert(l_sys != nullptr);
                uint64_t l_occCommonAddr = l_sys->getAttr
                    <TARGETING::ATTR_OCC_COMMON_AREA_PHYS_ADDR>();
                l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HOMER_OCC,
                        i_nodeId,
                        l_occCommonAddr,
                        VMM_OCC_COMMON_SIZE,
                        HBRT_RSVD_MEM__OCC_COMMON);
                if(l_elog)
                {
                    break;
                }
            }
#endif
        }


        ////////////////////////////////////////////////////
        // HB Data area
        ////////////////////////////////////////////////////

        //====================
        // Note that for PHYP we build up starting at the end of the
        //  previously allocated HOMER/OCC areas, for OPAL we build
        //  downwards from the top of memory where the HOMER/OCC
        //  areas were placed
        uint64_t l_startAddr = 0;
        uint64_t l_endAddr = 0;
        uint64_t l_totalSizeAligned = 0;
        bool startAddressValid = true;

        if(TARGETING::is_phyp_load())
        {
            l_startAddr = cpu_spr_value(CPU_SPR_HRMOR)
                + VMM_HB_DATA_TOC_START_OFFSET;
        }
        else if(TARGETING::is_sapphire_load())
        {
            l_endAddr = l_topMemAddr -
                VMM_ALL_HOMER_OCC_MEMORY_SIZE;
            startAddressValid = false;
        }

        // fills in the reserved memory with HB Data and
        // will update addresses and totalSize
        l_elog = fill_RsvMem_hbData(l_startAddr, l_endAddr,
                startAddressValid, l_totalSizeAligned);

        if (l_elog)
        {
            break;
        }

        // Loop through all functional Procs
        for (const auto & l_procChip: l_procChips)
        {
            //Pass start address down to SBE via chipop
            l_elog = SBEIO::sendPsuStashKeyAddrRequest(SBEIO::RSV_MEM_ATTR_ADDR,
                    l_startAddr,
                    l_procChip);
            if (l_elog)
            {
                TRACFCOMP( g_trac_runtime, "sendPsuStashKeyAddrRequest failed for target: %x",
                        TARGETING::get_huid(l_procChip) );
                break;
            }
        }

        if (l_elog)
        {
            break;
        }

        l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HBRT,
                i_nodeId,
                l_startAddr,
                l_totalSizeAligned,
                HBRT_RSVD_MEM__DATA);
        if(l_elog)
        {
            break;
        }

        // Establish a couple variables to keep track of where the
        // next section lands as we deal with the less statically
        // sized areas.  These values must always remain 64KB
        // aligned
        uint64_t l_prevDataAddr = l_startAddr;
        uint64_t l_prevDataSize = l_totalSizeAligned;

        //////////////////////////////////////////////////////////
        // HBRT image entry
        //   OPAL w/ FSP could get the hbrt image from the LID
        //   Include hbrt_code_image here to be consistent with P8
        if(TARGETING::is_sapphire_load())
        {
            uint64_t l_hbrtImageAddr = 0x0;
#ifdef CONFIG_SECUREBOOT
            l_elog = loadSecureSection(PNOR::HB_RUNTIME);
            if(l_elog)
            {
                break;
            }
            l_hbrtSecurelyLoaded = true;
#endif
            PNOR::SectionInfo_t l_pnorInfo;
            l_elog = getSectionInfo( PNOR::HB_RUNTIME , l_pnorInfo);
            if (l_elog)
            {
                break;
            }

            // Find start of image.
            //     For Secureboot we might need to deal with the header but
            //     for now that is hidden by the PNOR-RP.
            uint64_t l_imageStart = l_pnorInfo.vaddr;

            // The "VFS_LAST_ADDRESS" variable is 2 pages in.
            uint64_t l_vfsLastAddress =
                *reinterpret_cast<uint64_t*>(l_imageStart + 2*PAGE_SIZE);

            // At the end of the image are the relocations, get the number.
            uint64_t l_relocateCount =
                *reinterpret_cast<uint64_t*>
                (l_imageStart + l_vfsLastAddress);

            // Sum up the total size.
            uint64_t l_imageSize = l_vfsLastAddress +
                (l_relocateCount+1)*sizeof(uint64_t);

            // Set the image address, align down for OPAL
            l_hbrtImageAddr = ALIGN_PAGE_DOWN(l_prevDataAddr);
            l_hbrtImageAddr = ALIGN_PAGE_DOWN(l_hbrtImageAddr - l_imageSize);
            l_hbrtImageAddr = ALIGN_DOWN_X(l_hbrtImageAddr,
                    HBRT_RSVD_MEM_OPAL_ALIGN);
            size_t l_hbrtImageSizeAligned = ALIGN_X( l_imageSize,
                    HBRT_RSVD_MEM_OPAL_ALIGN);

            l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HBRT,
                    i_nodeId,
                    l_hbrtImageAddr,
                    l_hbrtImageSizeAligned,
                    HBRT_RSVD_MEM__CODE);
            if(l_elog)
            {
                break;
            }

            l_prevDataAddr = l_hbrtImageAddr;
            l_prevDataSize = l_hbrtImageSizeAligned;

            // Load the HBRT image into memory
            l_elog = mapPhysAddr(l_hbrtImageAddr, l_imageSize, l_vAddr);
            if(l_elog)
            {
                break;
            }

            memcpy(reinterpret_cast<void*>(l_vAddr),
                    reinterpret_cast<void*>(l_imageStart),
                    l_imageSize);

            l_elog = unmapVirtAddr(l_vAddr);
            if(l_elog)
            {
                break;
            }
        }

        ///////////////////////////////////////////////////
        // SBE Communications buffer entry
        // SBE FFDC entry
        uint64_t l_sbeCommAddr = 0x0;
        uint64_t l_sbeCommSize = SBE_MSG::SBE_COMM_BUFFER_SIZE;

        uint64_t l_sbeffdcAddr = 0x0;
        uint64_t l_sbeffdcSize =
            SBEIO::SbePsu::getTheInstance().getSbeFFDCBufferSize();

        // Align size for OPAL
        size_t l_sbeCommSizeAligned = ALIGN_X( l_sbeCommSize,
                HBRT_RSVD_MEM_OPAL_ALIGN );
        size_t l_sbeffdcSizeAligned = ALIGN_X( l_sbeffdcSize,
                HBRT_RSVD_MEM_OPAL_ALIGN );

        // Loop through all functional Procs
        for (const auto & l_procChip: l_procChips)
        {
            // Note: the instance we use to retrieve the data must
            //   match the value we used to populate HDAT originally
            uint32_t l_id = l_procChip->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();

            // -- SBE Communications buffer entry
            if(TARGETING::is_phyp_load())
            {
                l_sbeCommAddr = l_prevDataAddr + l_prevDataSize;
            }
            else if(TARGETING::is_sapphire_load())
            {
                l_sbeCommAddr = l_prevDataAddr - l_sbeCommSizeAligned;
            }

            l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HBRT,
                    l_id,
                    l_sbeCommAddr,
                    l_sbeCommSizeAligned,
                    HBRT_RSVD_MEM__SBE_COMM);
            if(l_elog)
            {
                break;
            }

            l_prevDataAddr = l_sbeCommAddr;
            l_prevDataSize = l_sbeCommSizeAligned;

            // Save SBE Communication buffer address to attribute
            l_procChip->setAttr<TARGETING::ATTR_SBE_COMM_ADDR>(l_sbeCommAddr);

            // -- SBE FFDC entry

            if(TARGETING::is_phyp_load())
            {
                l_sbeffdcAddr = l_prevDataAddr + l_prevDataSize;
            }
            else if(TARGETING::is_sapphire_load())
            {
                l_sbeffdcAddr = l_prevDataAddr - l_sbeffdcSizeAligned;
            }

            l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_HBRT,
                    l_id,
                    l_sbeffdcAddr,
                    l_sbeffdcSizeAligned,
                    HBRT_RSVD_MEM__SBE_FFDC);
            if(l_elog)
            {
                break;
            }

            l_prevDataAddr = l_sbeffdcAddr;
            l_prevDataSize = l_sbeffdcSizeAligned;

            // Save SBE FFDC address to attribute
            l_procChip->setAttr<TARGETING::ATTR_SBE_FFDC_ADDR>(l_sbeffdcAddr);

            // Open Unsecure Memory Region for SBE FFDC Section
            l_elog = SBEIO::openUnsecureMemRegion(l_sbeffdcAddr,
                    l_sbeffdcSize,
                    false, //Read-Only
                    l_procChip);

            if(l_elog)
            {
                TRACFCOMP( g_trac_runtime,
                        "populate_HbRsvMem: openUnsecureMemRegion failed");

                break;
            }


            // Send Set FFDC Address, tell SBE where to write FFDC and messages
            l_elog = SBEIO::sendSetFFDCAddr(l_sbeffdcSize,
                    l_sbeCommSize,
                    l_sbeffdcAddr,
                    l_sbeCommAddr,
                    l_procChip);

            if(l_elog)
            {
                TRACFCOMP( g_trac_runtime,
                        "populate_HbRsvMem: sendSetFFDCAddr failed");

                break;
            }
        }

        // just load this stuff once
        if( i_master_node == true )
        {
            ///////////////////////////////////////////////////
            // -- Secureboot cryptographic algorithms code
            //    Only add if SecureROM is available and valid.
            if (g_BlToHbDataManager.isValid())
            {
                size_t l_secureRomSize = g_BlToHbDataManager.getSecureRomSize();
                // Align size for OPAL
                size_t l_secRomSizeAligned = ALIGN_X(l_secureRomSize,
                        HBRT_RSVD_MEM_OPAL_ALIGN);
                // @TODO: RTC:183697 determine if OPAL can also use the
                // actual size and remove the need for l_hdatEntrySize
                // Size to add to HDAT entry
                size_t l_hdatEntrySize = l_secRomSizeAligned;

                uint64_t l_secureRomAddr = 0x0;
                if(TARGETING::is_phyp_load())
                {
                    l_secureRomAddr = l_prevDataAddr + l_prevDataSize;
                    // Specify actual size in HDAT entry for POWERVM
                    l_hdatEntrySize = l_secureRomSize;
                }
                else if(TARGETING::is_sapphire_load())
                {
                    l_secureRomAddr = l_prevDataAddr - l_secRomSizeAligned;
                }

                l_elog = setNextHbRsvMemEntry(HDAT::RHB_TYPE_SECUREBOOT,
                        i_nodeId,
                        l_secureRomAddr,
                        l_hdatEntrySize,
                        HBRT_RSVD_MEM__SECUREBOOT);
                if(l_elog)
                {
                    break;
                }

                l_prevDataAddr = l_secureRomAddr;
                l_prevDataSize = l_secRomSizeAligned;

                // Load the Cached SecureROM into memory
                l_elog = mapPhysAddr(l_secureRomAddr, l_secureRomSize, l_vAddr);
                if(l_elog)
                {
                    break;
                }

                memcpy(reinterpret_cast<void*>(l_vAddr),
                        g_BlToHbDataManager.getSecureRom(),
                        l_secureRomSize);

                l_elog = unmapVirtAddr(l_vAddr);
                if(l_elog)
                {
                    break;
                }
            }

            // Initialize Pre-Verified Lid manager
            PreVerifiedLidMgr::initLock(l_prevDataAddr, l_prevDataSize,
                                        i_nodeId);
            l_preVerLidMgrLock = true;

            // Handle all Pre verified PNOR sections
            for (const auto & secIdPair : preVerifiedPnorSections)
            {
                // Skip RINGOVD section in POWERVM mode
                if (secIdPair.first == PNOR::RINGOVD &&
                        INITSERVICE::spBaseServicesEnabled() &&
                        TARGETING::is_phyp_load())
                {
                    continue;
                }

                l_elog = hbResvLoadSecureSection(secIdPair.first,
                                                 secIdPair.second);
                if (l_elog)
                {
                    break;
                }
            }
            if (l_elog)
            {
                break;
            }

            // Load lids from Master Container Lid Container provided by FSP and
            // in POWERVM mode
            if (INITSERVICE::spBaseServicesEnabled() &&
                    TARGETING::is_phyp_load())
            {
                MCL::MasterContainerLidMgr l_mcl;
                l_elog = l_mcl.processComponents();
                if(l_elog)
                {
                    break;
                }
            }
        }
    } while(0);

#ifdef CONFIG_SECUREBOOT
    // Skip unload if a section was not securely loaded in the first place
    if (l_hbrtSecurelyLoaded )
    {
        // Unload HBRT PNOR section
        auto l_unloadErrlog = unloadSecureSection(PNOR::HB_RUNTIME);
        if (l_unloadErrlog)
        {
            TRACFCOMP( g_trac_runtime,
                       ERR_MRK"hbResvloadSecureSection() - Error from "
                       "unloadSecureSection(%s)", PNOR::SectionIdToString(PNOR::HB_RUNTIME));
            // Link unload error log to existing errorlog plid and commit error
            if(l_elog)
            {
                l_unloadErrlog->plid(l_elog->plid());
                ERRORLOG::errlCommit(l_unloadErrlog, RUNTIME_COMP_ID);
            }
            // This is the only error so return that.
            else
            {
                l_elog = l_unloadErrlog;
                l_unloadErrlog = nullptr;
            }
        }
    }
#endif

    // If lock obtained, always unlock Pre verified lid manager
    if (l_preVerLidMgrLock)
    {
        PreVerifiedLidMgr::unlock();
    }

    TRACFCOMP( g_trac_runtime, EXIT_MRK"populate_HbRsvMem> l_elog=%.8X", ERRL_GETRC_SAFE(l_elog) );
    return(l_elog);
} // end populate_HbRsvMem

errlHndl_t populate_hbSecurebootData ( void )
{
    using namespace TARGETING;

    errlHndl_t l_elog = nullptr;

    do {
        // pass 0 since sys parms has only one record
        const uint64_t l_instance = 0;
        uint64_t l_hbrtDataAddr = 0;
        uint64_t l_hbrtDataSizeMax = 0;
        l_elog = RUNTIME::get_host_data_section(RUNTIME::IPLPARMS_SYSTEM,
                l_instance,
                l_hbrtDataAddr,
                l_hbrtDataSizeMax);
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_hbSecurebootData: "
                    "get_host_data_section() failed for system IPL parameters section");
            break;
        }

        hdatSysParms_t* const l_sysParmsPtr
            = reinterpret_cast<hdatSysParms_t*>(l_hbrtDataAddr);

        typedef struct sysSecSets
        {
            // bit 0: Code Container Digital Signature Checking
            uint16_t secureboot : 1;
            // bit 1: Measurements Extended to Secure Boot TPM
            uint16_t trustedboot : 1;
            // bit 2: SBE Security Backdoor bit.
            // NOTE: This bit is labeled "Platform Security Overrides Allowed"
            // in the section 6.1.1 of HDAT spec.
            uint16_t sbeSecBackdoor : 1;
            uint16_t reserved : 13;
        } SysSecSets;

        // populate system security settings in hdat
        SysSecSets* const l_sysSecSets =
            reinterpret_cast<SysSecSets*>(&l_sysParmsPtr->hdatSysSecuritySetting);

        // populate secure setting for trusted boot
        bool trusted = false;
#ifdef CONFIG_TPMDD
        trusted = TRUSTEDBOOT::enabled();
#endif
        l_sysSecSets->trustedboot = trusted? 1: 0;

        // populate secure setting for secureboot
        bool secure = false;
#ifdef CONFIG_SECUREBOOT
        secure = SECUREBOOT::enabled();
#endif
        l_sysSecSets->secureboot = secure? 1: 0;

        // populate security override setting
        l_sysSecSets->sbeSecBackdoor = SECUREBOOT::getSbeSecurityBackdoor();

        // populate TPM config bits in hdat
        bool tpmRequired = false;
#ifdef CONFIG_TPMDD
        tpmRequired = TRUSTEDBOOT::isTpmRequired();
#endif

        l_sysParmsPtr->hdatTpmConfBits = tpmRequired? TPM_REQUIRED_BIT: 0;

        // get max # of TPMs per drawer and populate hdat with it
        auto l_maxTpms = HDAT::hdatCalcMaxTpmsPerNode();

        l_sysParmsPtr->hdatTpmDrawer = l_maxTpms;
        TRACFCOMP(g_trac_runtime,"Max TPMs = 0x%04X", l_maxTpms);

        // Populate HW Keys' Hash size + value in HDAT
        l_sysParmsPtr->hdatHwKeyHashSize =
            sizeof(l_sysParmsPtr->hdatHwKeyHashValue);
        TRACFCOMP(g_trac_runtime,"HW Keys' Hash Size = %d",
                l_sysParmsPtr->hdatHwKeyHashSize);

#ifdef CONFIG_SECUREBOOT
        auto hash = l_sysParmsPtr->hdatHwKeyHashValue;
        SECUREBOOT::getHwKeyHash(hash);
#else
        memset(l_sysParmsPtr->hdatHwKeyHashValue,0,
                sizeof(l_sysParmsPtr->hdatHwKeyHashValue));
#endif

        // Populate FW Secure Version
        // TODO RTC 254577 - put in real value
        // Clear for now
        l_sysParmsPtr->hdatFwSecureVersion = 0;
        TRACFCOMP(g_trac_runtime, INFO_MRK"populate_hbSecurebootData: "
                  "Setting hdatFwSecureVersion to 0x%.2X",
                  l_sysParmsPtr->hdatFwSecureVersion);

    } while(0);

    return (l_elog);
} // end populate_hbRuntime

errlHndl_t populate_TpmInfoByNode(const uint64_t i_instance)
{
    errlHndl_t l_elog = nullptr;

    do {

        uint64_t l_baseAddr = 0;
        uint64_t l_dataSizeMax = 0;

        TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: "
                    "calling get_host_data_section() to populate instance %d",i_instance);

        l_elog = RUNTIME::get_host_data_section(RUNTIME::NODE_TPM_RELATED,
                i_instance,
                l_baseAddr,
                l_dataSizeMax);
        if(l_elog)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: "
                    "get_host_data_section() failed for Node TPM-related Data section");
            break;
        }

        // obtain the node target, used later to populate fields
        TARGETING::Target* mproc = nullptr;
        l_elog = TARGETING::targetService().queryMasterProcChipTargetHandle(mproc);
        if(l_elog)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: "
                    "could not obtain the master processor from targeting");
            break;
        }
        auto targetType = TARGETING::TYPE_NODE;
        const TARGETING::Target* l_node = getParent(mproc, targetType);
        assert(l_node != nullptr, "Bug! getParent on master proc returned null.");

        // this will additively keep track of the next available offset
        // as we fill the section
        uint32_t l_currOffset = 0;

        ////////////////////////////////////////////////////////////////////////
        // Section Node Secure and Trusted boot Related Data
        ////////////////////////////////////////////////////////////////////////

        auto const l_hdatTpmData
            = reinterpret_cast<HDAT::hdatTpmData_t*>(l_baseAddr);

        // make sure we have enough room
        auto const l_tpmDataCalculatedMax = HDAT::hdatTpmDataCalcInstanceSize();
        if(l_dataSizeMax < l_tpmDataCalculatedMax)
        {

            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: The TPM data hdat section doesn't have enough space");

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_HDAT_OUT_OF_SPACE
             * @userdata1     Size of hdat data struct
             * @userdata2     Max size of hdat data struct
             * @devdesc       The TPM data hdat section doesn't have enough space
             * @custdesc      Platform security problem detected
             */
            l_elog = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_TPM_HDAT_OUT_OF_SPACE,
                    l_dataSizeMax,
                    l_tpmDataCalculatedMax,
                    true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        // TODO RTC 190522 - Remove the following two lines of code once FSP
        // adds missing eyecatch and magic number to non-master nodes
        l_hdatTpmData->hdatHdr.hdatStructId = HDAT::HDAT_HDIF_STRUCT_ID;
        memcpy(l_hdatTpmData->hdatHdr.hdatStructName,
           HDAT::g_hdatTpmDataEyeCatch,
           strlen(HDAT::g_hdatTpmDataEyeCatch));

        // check that hdat structure format and eye catch were filled out
        if(l_hdatTpmData->hdatHdr.hdatStructId != HDAT::HDAT_HDIF_STRUCT_ID)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: The TPM data hdat struct format value doesn't match");

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_HDAT_ID_MISMATCH
             * @userdata1     hdat struct format value
             * @userdata2     Expected hdat struct format value
             * @devdesc       TPM data hdat struct format value doesn't match
             * @custdesc      Platform security problem detected
             */
            l_elog = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_TPM_HDAT_ID_MISMATCH,
                    l_hdatTpmData->hdatHdr.hdatStructId,
                    HDAT::HDAT_HDIF_STRUCT_ID,
                    true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        auto l_eyeCatchLen = strlen(HDAT::g_hdatTpmDataEyeCatch);
        if(memcmp(l_hdatTpmData->hdatHdr.hdatStructName,
                    HDAT::g_hdatTpmDataEyeCatch,
                    l_eyeCatchLen) != 0)
        {

            // Convert char strings to uin64_t for errorlogs
            uint64_t l_eyeCatch = 0;
            memcpy(&l_eyeCatch,
                    l_hdatTpmData->hdatHdr.hdatStructName,
                    strnlen(l_hdatTpmData->hdatHdr.hdatStructName,sizeof(uint64_t)));
            uint64_t l_expectedEyeCatch = 0;
            memcpy(&l_expectedEyeCatch,
                    HDAT::g_hdatTpmDataEyeCatch,
                    strnlen(HDAT::g_hdatTpmDataEyeCatch, sizeof(uint64_t)));

            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: The TPM data hdat struct name eye catcher (0x%X) doesn't match expected value (0x%X",
                    l_eyeCatch, l_expectedEyeCatch);

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_HDAT_EYE_CATCH_MISMATCH
         * @userdata1     hdat struct name eye catcher
         * @userdata2     Expected hdat eye catch
         * @devdesc       TPM data hdat struct name eye catcher doesn't match
         * @custdesc      Platform security problem detected
         */
        l_elog = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
            RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
            RUNTIME::RC_TPM_HDAT_EYE_CATCH_MISMATCH,
            l_eyeCatch,
            l_expectedEyeCatch,
            true);
        l_elog->collectTrace(RUNTIME_COMP_NAME);
        break;
    }

    l_hdatTpmData->hdatHdr.hdatInstance = HDAT::TpmDataInstance;
    l_hdatTpmData->hdatHdr.hdatVersion = HDAT::TpmDataVersion;
    l_hdatTpmData->hdatHdr.hdatHdrSize = HDAT::TpmDataHdrSize;
    l_hdatTpmData->hdatHdr.hdatDataPtrOffset = HDAT::TpmDataPtrOffset;
    l_hdatTpmData->hdatHdr.hdatDataPtrCnt = HDAT::TpmDataPtrCnt;
    l_hdatTpmData->hdatHdr.hdatChildStrCnt = HDAT::TpmDataChildStrCnt;
    l_hdatTpmData->hdatHdr.hdatChildStrOffset = HDAT::TpmDataChildStrOffset;

    TRACFCOMP(g_trac_runtime,"populate_TpmInfoByNode: "
        "HDAT TPM Data successfully read. Struct Format:0x%X",
        l_hdatTpmData->hdatHdr.hdatStructId);
    TRACFBIN(g_trac_runtime, "populate_TpmINfoByNode - EyeCatch: ",
         l_hdatTpmData->hdatHdr.hdatStructName, l_eyeCatchLen);

    // go past the end of the first struct to get to the next one
    l_currOffset += sizeof(*l_hdatTpmData);

    ////////////////////////////////////////////////////////////////////////////
    // Section Secure Boot and Trusted boot info array
    ////////////////////////////////////////////////////////////////////////////

    // populate first part of pointer pair for secure boot TPM info
    l_hdatTpmData->hdatSbTpmInfo.hdatOffset = l_currOffset;

    // the second part of the pointer pair for secure boot TPM info will be
    // populated using the following start offset
    auto l_sbTpmInfoStart = l_currOffset;

    auto const l_hdatSbTpmInfo = reinterpret_cast<HDAT::hdatHDIFDataArray_t*>
                                                    (l_baseAddr + l_currOffset);

    TARGETING::TargetHandleList tpmList;
    TRUSTEDBOOT::getTPMs(tpmList, TRUSTEDBOOT::TPM_FILTER::ALL_IN_BLUEPRINT);

    TARGETING::TargetHandleList l_procList;

    getAllChips(l_procList,TARGETING::TYPE_PROC,false);

    auto const l_numTpms = tpmList.size();

    // fill in the values for the Secure Boot TPM Info Array Header
    l_hdatSbTpmInfo->hdatOffset = sizeof(*l_hdatSbTpmInfo);
    l_hdatSbTpmInfo->hdatArrayCnt = l_numTpms;
    l_hdatSbTpmInfo->hdatAllocSize = sizeof(HDAT::hdatSbTpmInstInfo_t);
    l_hdatSbTpmInfo->hdatActSize = l_hdatSbTpmInfo->hdatAllocSize;

    // advance current offset to after the Secure Boot TPM info array header
    l_currOffset += sizeof(*l_hdatSbTpmInfo);

    ////////////////////////////////////////////////////////////////////////////
    // Section Secure Boot and TPM Instance Info
    ////////////////////////////////////////////////////////////////////////////

    // save of a list of TPM / Instance Info pairs to fix up in a second pass
    std::vector<std::pair<TARGETING::Target*,
                          HDAT::hdatSbTpmInstInfo_t*> > fixList;

    // Calculate the SRTM log offset
    auto l_srtmLogOffset = 0;

    // fill in the values for each Secure Boot TPM Instance Info in the array
    for (auto pTpm : tpmList)
    {
        auto l_tpmInstInfo = reinterpret_cast<HDAT::hdatSbTpmInstInfo_t*>
                                                    (l_baseAddr + l_currOffset);

        // save for second pass SRTM/DRTM log offset fixups
        fixList.push_back(std::make_pair(pTpm, l_tpmInstInfo));

        auto l_tpmInfo = pTpm->getAttr<TARGETING::ATTR_TPM_INFO>();

        TARGETING::PredicateAttrVal<TARGETING::ATTR_PHYS_PATH>
                                      hasSameI2cMaster(l_tpmInfo.i2cMasterPath);

        auto itr = std::find_if(l_procList.begin(),l_procList.end(),
        [&hasSameI2cMaster](const TARGETING::TargetHandle_t & t)
        {
            return hasSameI2cMaster(t);
        });

        if(itr == l_procList.end())
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: TPM does not have a processor.");

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_MISSING_PROC
             * @userdata1     Number of processors
             * @userdata2     0
             * @devdesc       TPM does not have a processor
             * @custdesc      Platform security problem detected
             */
            l_elog = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                RUNTIME::RC_TPM_MISSING_PROC,
                l_procList.size(),
                0,
                true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        auto l_proc = *itr;

        l_tpmInstInfo->hdatChipId = l_proc->getAttr<
                                                 TARGETING::ATTR_ORDINAL_ID>();

        l_tpmInstInfo->hdatDbobId = l_node->getAttr<
                                                 TARGETING::ATTR_ORDINAL_ID>();

        l_tpmInstInfo->hdatLocality1Addr = l_tpmInfo.devAddrLocality1;
        l_tpmInstInfo->hdatLocality2Addr = l_tpmInfo.devAddrLocality2;
        l_tpmInstInfo->hdatLocality3Addr = l_tpmInfo.devAddrLocality3;
        l_tpmInstInfo->hdatLocality4Addr = l_tpmInfo.devAddrLocality4;

        auto hwasState = pTpm->getAttr<TARGETING::ATTR_HWAS_STATE>();

        if (hwasState.functional && hwasState.present)
        {
            // present and functional
            l_tpmInstInfo->hdatFunctionalStatus = HDAT::TpmPresentAndFunctional;
        }
        else if (hwasState.present)
        {
            // present and not functional
            l_tpmInstInfo->hdatFunctionalStatus = HDAT::TpmPresentNonFunctional;
        }
        else
        {
            // not present
            l_tpmInstInfo->hdatFunctionalStatus = HDAT::TpmNonPresent;
        }

        // Set TPM configuration flag
        l_tpmInstInfo->hdatTpmConfigFlags.pcrPoisonedFlag = 0;

        // advance the current offset to account for this tpm instance info
        l_currOffset += sizeof(*l_tpmInstInfo);

        // advance the SRTM log offset to account for this tpm instance info
        l_srtmLogOffset += sizeof(*l_tpmInstInfo);

    }

    for (auto tpmInstPair : fixList)
    {
        const auto pTpm = tpmInstPair.first;
        const auto l_tpmInstInfo = tpmInstPair.second;

        ////////////////////////////////////////////////////////////////////////
        // Section Secure Boot TPM Event Log
        ////////////////////////////////////////////////////////////////////////

        // The SRTM offset we had been tallying in the previous loop happens to
        // be the offset from the first TPM Instance Info to the first SRTM log
        l_tpmInstInfo->hdatTpmSrtmEventLogOffset = l_srtmLogOffset;

        // As we go through the list we remove a TPM instance info length and
        // add an SRTM log length to the previous offset. The reason is b/c a
        // TPM Instance info's log offset is counted from the start of the
        // that instance info. We subtract an instance info length from the
        // previous offset to account for that difference. We also add a log max
        // to account for the previous instance info's log.
        l_srtmLogOffset += (TPM_SRTM_EVENT_LOG_MAX - sizeof(*l_tpmInstInfo));

        // copy the contents of the SRTM event log into HDAT picking the
        // min of log size and log max (to make sure log size never goes
        // over the max)
        auto * const pLogMgr = TRUSTEDBOOT::getTpmLogMgr(pTpm);
        size_t logSize = 0;
        if(pLogMgr != nullptr)
        {
            #ifdef CONFIG_TPMDD

            // The log size always has to be specified to the max
            //  this is because after HDAT is populated additional
            //  entries can be posted to the log to cause it to
            //  grow beyond its current size
            logSize = TPM_SRTM_EVENT_LOG_MAX;

            // Although the TPM log's physical memory is currently memory mapped
            // to a virtual address range, said range will go out of scope when
            // processing other HDAT sections.  Therefore, for every TPM log,
            // open a secondary and persistent virtual memory window to it, so
            // that the TPM log manager will have a consistent
            // virtual-to-physical address mapping to write its log data to.
            // Hostboot will keep this range open since TPM extensions
            // happen up until invoking the payload.
            const uint64_t tpmLogVirtAddr = l_baseAddr + l_currOffset;
            const auto tpmLogPhysAddr =
                mm_virt_to_phys(reinterpret_cast<void*>(tpmLogVirtAddr));
            if(static_cast<int64_t>(tpmLogPhysAddr) == -EFAULT)
            {
                TRACFCOMP(g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: "
                    "Failed in call to mm_virt_to_phys() with virtual address "
                    "0x%016llX",
                    tpmLogVirtAddr);
                /*@
                 * @errortype
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   RUNTIME::MOD_POPULATE_TPMINFOBYNODE
                 * @reasoncode RUNTIME::RC_TPM_HDAT_VIRT_TO_PHYS_ERR
                 * @userdata1  Requested virtual address to convert
                 * @devdesc    Failed to convert virtual address to physical
                 *             address
                 * @custdesc   Firmware encountered an internal error
                 */
                l_elog = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_TPM_HDAT_VIRT_TO_PHYS_ERR,
                    tpmLogVirtAddr,
                    0,
                    true);
                l_elog->collectTrace(RUNTIME_COMP_NAME);
                break;
            }

            decltype(tpmLogPhysAddr) tpmLogAlignedPhysAddr
                = ALIGN_PAGE_DOWN(tpmLogPhysAddr);
            decltype(logSize) diff = tpmLogPhysAddr-tpmLogAlignedPhysAddr;
            decltype(logSize) tpmLogAlignedSize
                = ALIGN_PAGE(diff + logSize);

            auto tpmLogNewVirtAddr =
                mm_block_map(reinterpret_cast<void*>(tpmLogAlignedPhysAddr),
                             tpmLogAlignedSize);
            if(tpmLogNewVirtAddr == nullptr)
            {
                TRACFCOMP(g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: "
                    "Failed in call to mm_block_map with aligned physical "
                    "address 0x%016llX and aligned size 0x%016llX",
                    tpmLogAlignedPhysAddr,tpmLogAlignedSize);

                /*@
                 * @errortype
                 * @severity   ERRL_SEV_UNRECOVERABLE
                 * @moduleid   RUNTIME::MOD_POPULATE_TPMINFOBYNODE
                 * @reasoncode RUNTIME::RC_TPM_HDAT_MAP_BLOCK_ERR
                 * @userdata1  Aligned physical address to map
                 * @userdata2  Aligned size or region to map
                 * @devdesc    Failed to map physical memory to virtual memory
                 * @custdesc   Firmware encountered an internal error
                 */
                l_elog = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_TPM_HDAT_MAP_BLOCK_ERR,
                    tpmLogAlignedPhysAddr,
                    tpmLogAlignedSize,
                    true);
                l_elog->collectTrace(RUNTIME_COMP_NAME);
                break;
            }
            tpmLogNewVirtAddr=
                reinterpret_cast<void*>(
                    diff+reinterpret_cast<uint8_t*>(tpmLogNewVirtAddr));

            TRACFCOMP(g_trac_runtime, INFO_MRK "Moving TPM log; "
                "Current virtual address = 0x%016llX, "
                "Current log size = 0x%016llX, "
                "Current physical address = 0x%016llX, "
                "Aligned physical address = 0x%016llX, "
                "Aligned log size = 0x%016llX, "
                "New virtual address = 0x%016llX.",
                tpmLogVirtAddr,
                logSize,
                tpmLogPhysAddr,
                tpmLogAlignedPhysAddr,
                tpmLogAlignedSize,
                tpmLogNewVirtAddr);

            // Move TPM log to the new virtual memory mapping
            TRUSTEDBOOT::TpmLogMgr_relocateTpmLog(pLogMgr,
                          reinterpret_cast<uint8_t*>(tpmLogNewVirtAddr),
                          logSize);
            #endif
        }
        else
        {
            TRACFCOMP( g_trac_runtime, INFO_MRK "populate_TpmInfoByNode: "
                "No static log available to propagate for TPM with HUID of "
                "0x%08X",TARGETING::get_huid(pTpm));
        }

        // set the size value for the data that was copied
        l_tpmInstInfo->hdatTpmSrtmEventLogEntrySize = logSize;

        // advance the current offset to account for the SRTM event log
        l_currOffset += TPM_SRTM_EVENT_LOG_MAX;

        // set the DRTM offset to zero as it is not yet supported
        l_tpmInstInfo->hdatTpmDrtmEventLogOffset = 0;

        // set the DRTM event log size to zero as it is not yet supported
        l_tpmInstInfo->hdatTpmDrtmEventLogEntrySize = 0;

        // Note: We don't advance the current offset, because the size of the
        // DRTM event log is zero
    }
    if (l_elog)
    {
        break;
    }

    // populate second part of pointer pair for secure boot TPM info
    l_hdatTpmData->hdatSbTpmInfo.hdatSize = l_currOffset - l_sbTpmInfoStart;

    ////////////////////////////////////////////////////////////////////////////
    // Section User physical interaction mechanism information
    ////////////////////////////////////////////////////////////////////////////

    // the current offset now corresponds to the physical interaction mechanism
    // info array header
    auto l_physInter = reinterpret_cast<HDAT::hdatPhysInterMechInfo_t*>
                                                    (l_baseAddr + l_currOffset);

    // populate the first part of pointer pair from earlier to point here
    l_hdatTpmData->hdatPhysInter.hdatOffset = l_currOffset;

    // the following will be used to calculate the second part of pointer pair
    auto l_physInterStart = l_currOffset;

    // start with an empty list of link IDs
    std::vector<HDAT::i2cLinkId_t> l_linkIds;

    // obtain a list of i2c targets
    std::vector<I2C::DeviceInfo_t> l_i2cTargetList;
    I2C::getDeviceInfo(mproc, l_i2cTargetList);
    auto i2cDevItr = l_i2cTargetList.begin();
    while(i2cDevItr != l_i2cTargetList.end())
    {
        switch((*i2cDevItr).devicePurpose)
        {
        case TARGETING::HDAT_I2C_DEVICE_PURPOSE_WINDOW_OPEN:
        case TARGETING::HDAT_I2C_DEVICE_PURPOSE_PHYSICAL_PRESENCE:
            // keep devices with these two purposes
            ++i2cDevItr;
            break;
        default:
            // remove devices with any other purpose
            i2cDevItr = l_i2cTargetList.erase(i2cDevItr);
            break;
        }
    }

    uint64_t l_numInstances = 0;

    l_elog = RUNTIME::get_instance_count(RUNTIME::PCRD, l_numInstances);
    if (l_elog)
    {
        TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: get_instance_count() failed for PCRD HDAT section");
        break;
    }

    uint64_t l_pcrdAddr = 0;
    uint64_t l_pcrdSizeMax = 0;

    // Initialize i2cLinkIds to NA before attempting populate
    l_physInter->i2cLinkIdPhysicalPresence = HDAT::I2C_LINK_ID::NOT_APPLICABLE;
    l_physInter->i2cLinkIdWindowOpen = HDAT::I2C_LINK_ID::NOT_APPLICABLE;

    for (uint64_t l_pcrdInstance = 0;
         l_pcrdInstance < l_numInstances;
         ++l_pcrdInstance)
    {

        l_elog = RUNTIME::get_host_data_section(RUNTIME::PCRD,
                                                l_pcrdInstance,
                                                l_pcrdAddr,
                                                l_pcrdSizeMax);
        if(l_elog)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: get_host_data_section() failed for PCRD HDAT section, instance %d", l_pcrdInstance);
            break;
        }

        // Get a pointer to the PCRD header
        auto l_pcrd = reinterpret_cast<const HDAT::hdatSpPcrd_t*>(l_pcrdAddr);

        // Check the version of the PCRD section header
        if(l_pcrd->hdatHdr.hdatVersion < HDAT::TpmDataMinRqrdPcrdVersion)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: Bad PCRD section version 0x%X - must be 0x%X or greater",
                      l_pcrd->hdatHdr.hdatVersion,
                       HDAT::TpmDataMinRqrdPcrdVersion);

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_HDAT_BAD_VERSION
             * @userdata1     hdat version
             * @userdata2     Expected support version
             * @devdesc       Bad PCRD section version
             * @custdesc      Platform security problem detected
             */
            l_elog = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                RUNTIME::RC_TPM_HDAT_BAD_VERSION,
                l_pcrd->hdatHdr.hdatVersion,
                HDAT::TpmDataMinRqrdPcrdVersion,
                true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        // Get offset for the i2c array header
        auto i2cAryOff =
            l_pcrd->hdatPcrdIntData[HDAT::HDAT_PCRD_DA_HOST_I2C].hdatOffset;

        // If pointer pair's offset value is 0, advance to next PCRD instance
        // as this one has no I2C links
        if(!i2cAryOff)
        {
            continue;
        }

        // Convert i2c array header offset to a pointer to the i2c array header
        const auto l_hostI2cPcrdHdrPtr =
           reinterpret_cast<HDAT::hdatHDIFDataArray_t*>(l_pcrdAddr + i2cAryOff);

        // make sure the array count is within reasonable limits
        if(l_hostI2cPcrdHdrPtr->hdatArrayCnt > HDAT_PCRD_MAX_I2C_DEV)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "populate_TpmInfoByNode: HDAT PCRD reported more than the max number of i2c devices! Count:%d",
                       l_hostI2cPcrdHdrPtr->hdatArrayCnt);

            /*@
             * @errortype
             * @severity      ERRL_SEV_UNRECOVERABLE
             * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
             * @reasoncode    RUNTIME::RC_TPM_HDAT_BAD_NUM_I2C
             * @userdata1     hdat array count
             * @userdata2     max number of i2c devices
             * @devdesc       HDAT PCRD reported more than the max number of i2c devices
             * @custdesc      Platform security problem detected
             */
            l_elog = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                RUNTIME::RC_TPM_HDAT_BAD_NUM_I2C,
                l_hostI2cPcrdHdrPtr->hdatArrayCnt,
                HDAT_PCRD_MAX_I2C_DEV,
                true);
            l_elog->collectTrace(RUNTIME_COMP_NAME);
            break;
        }

        // Get the pointer to the first element in the i2c array
        // This is the address of the header plus the offset given in the header
        auto l_i2cDevStart =
            reinterpret_cast<const uint8_t*>(l_hostI2cPcrdHdrPtr)
            + l_hostI2cPcrdHdrPtr->hdatOffset;

        // Calculate the stop pointer
        auto l_i2cDevStop = l_i2cDevStart + (l_hostI2cPcrdHdrPtr->hdatArrayCnt *
                                           l_hostI2cPcrdHdrPtr->hdatAllocSize);

        // for each link ID in the PCRD
        for (auto l_cur = l_i2cDevStart;
             l_cur != l_i2cDevStop;
             l_cur += l_hostI2cPcrdHdrPtr->hdatAllocSize )
        {
            // reinterpret the byte pointer as a struct pointer
            auto l_i2cDev = reinterpret_cast<const HDAT::hdatI2cData_t*>(l_cur);

            // if we've seen it already
            auto it = std::find(l_linkIds.begin(),
                            l_linkIds.end(),
                            l_i2cDev->hdatI2cLinkId);
            if (it != l_linkIds.end())
            {
                const auto l_linkId = *it;
                TRACFCOMP(g_trac_runtime,
                    "populate_TpmInfoByNode: A duplicate link Id was found. %d",
                    l_linkId);

                // terminate the boot due to an integrity violation
                /*@
                 * @errortype
                 * @reasoncode    RUNTIME::RC_DUPLICATE_I2C_LINK_IDS
                 * @moduleid      RUNTIME::MOD_POPULATE_TPMINFOBYNODE
                 * @severity      ERRL_SEV_UNRECOVERABLE
                 * @userdata1     I2C Link ID
                 * @devdesc       Found duplicate I2C link IDs in PCRD section
                 *                of HDAT. System security cannot be guaranteed.
                 * @custdesc      Platform security problem detected
                 */
                auto err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_DUPLICATE_I2C_LINK_IDS,
                    l_linkId,
                    0,
                    true);
                err->collectTrace(RUNTIME_COMP_NAME);
                SECUREBOOT::handleSecurebootFailure(err);

                assert(false,"Bug! handleSecurebootFailure shouldn't return!");
            }
            else
            {
                // add it to a known list to make sure we don't see it again
                l_linkIds.push_back(l_i2cDev->hdatI2cLinkId);
            }
            // use this pointer to avoid having to repeat the switch statement
            // later
            HDAT::i2cLinkId_t* l_pLinkId = nullptr;

            switch(l_i2cDev->hdatI2cSlaveDevPurp)
            {
            case TARGETING::HDAT_I2C_DEVICE_PURPOSE_WINDOW_OPEN:

                l_pLinkId = &l_physInter->i2cLinkIdWindowOpen;
                break;

            case TARGETING::HDAT_I2C_DEVICE_PURPOSE_PHYSICAL_PRESENCE:

                l_pLinkId = &l_physInter->i2cLinkIdPhysicalPresence;
                break;

            default:
                // Physical Presence Info not supported for this I2c device
                // purpose.  This device will not be referred to by the Node TPM
                // Related Info Section, but we still ensure uniqueness of all
                // link IDs in the I2c device list from the PCRD.
            continue;
            }

            // now make sure we have a match in the mrw
            auto itr = std::find_if(l_i2cTargetList.begin(),
                                    l_i2cTargetList.end(),

            [&l_i2cDev,&l_pcrd](const I2C::DeviceInfo_t & i_i2cDevMrw)
            {
                return
                    i_i2cDevMrw.masterChip->getAttr<
                        TARGETING::ATTR_ORDINAL_ID>() ==
                            l_pcrd->hdatChipData.hdatPcrdProcChipId &&
                    l_i2cDev->hdatI2cEngine == i_i2cDevMrw.engine &&
                    l_i2cDev->hdatI2cMasterPort == i_i2cDevMrw.masterPort &&
                    l_i2cDev->hdatI2cBusSpeed == i_i2cDevMrw.busFreqKhz &&
                    l_i2cDev->hdatI2cSlaveDevType == i_i2cDevMrw.deviceType &&
                    l_i2cDev->hdatI2cSlaveDevAddr == i_i2cDevMrw.addr &&
                    l_i2cDev->hdatI2cSlavePort == i_i2cDevMrw.slavePort &&
                    l_i2cDev->hdatI2cSlaveDevPurp == i_i2cDevMrw.devicePurpose
                    &&
                    !strcmp(l_i2cDev->hdatI2cLabel, i_i2cDevMrw.deviceLabel);
            });

            if (itr == l_i2cTargetList.end())
            {
                // couldn't find it, physical presense will not be available
                TRACFCOMP(g_trac_runtime,
                    "populate_TpmInfoByNode: I2c device in the PCRD with link ID %d does not have a match in the MRW",
                    l_i2cDev->hdatI2cLinkId);
                /*@
                 * @errortype
                 * @reasoncode   RUNTIME::RC_I2C_DEVICE_NOT_IN_MRW
                 * @moduleid     RUNTIME::MOD_POPULATE_TPMINFOBYNODE
                 * @severity     ERRL_SEV_INFORMATIONAL
                 * @userdata1    I2C Link ID
                 * @devdesc      An I2C device in the PCRD does not have a match
                 *               in the MRW. Physical presence detection
                 *               will not be available.
                 * @custdesc     Platform security problem detected
                 */
                auto err = new ERRORLOG::ErrlEntry(
                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                    RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                    RUNTIME::RC_I2C_DEVICE_NOT_IN_MRW,
                    l_i2cDev->hdatI2cLinkId,
                    0,
                    true);
                err->collectTrace(RUNTIME_COMP_NAME);
                ERRORLOG::errlCommit(err, RUNTIME_COMP_ID);
            }
            else
            {
                if (*l_pLinkId != HDAT::I2C_LINK_ID::NOT_APPLICABLE)
                {
                    // found a duplicate link id match indicating that there
                    // was an error in the model
                    TRACFCOMP(g_trac_runtime,
                        "populate_TpmInfoByNode: I2c device in the PCRD with link ID %d has a duplicate match in the MRW",
                        l_i2cDev->hdatI2cLinkId);
                    /*@
                     * @errortype
                     * @reasoncode   RUNTIME::RC_I2C_DEVICE_DUPLICATE_IN_MRW
                     * @moduleid     RUNTIME::MOD_POPULATE_TPMINFOBYNODE
                     * @severity     ERRL_SEV_INFORMATIONAL
                     * @userdata1    I2C Link ID
                     * @devdesc      An I2C device in the PCRD has a duplicate
                     *               match in the MRW. Physical presence
                     *               detection will still be available.
                     * @custdesc     Platform security problem detected
                     */
                    auto err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                        RUNTIME::RC_I2C_DEVICE_DUPLICATE_IN_MRW,
                        l_i2cDev->hdatI2cLinkId,
                        0,
                        true);
                    err->collectTrace(RUNTIME_COMP_NAME);
                    ERRORLOG::errlCommit(err, RUNTIME_COMP_ID);
                }
                else // found a match
                {
                    *l_pLinkId = l_i2cDev->hdatI2cLinkId;
                    l_i2cTargetList.erase(itr);
                }
            }

        } // for each link ID in the current PCRD instance

    } // for each instance
    if (l_elog)
    {
        break;
    }

    if (!l_i2cTargetList.empty())
    {
        for (auto i2cDev : l_i2cTargetList)
        {
            TRACFCOMP(g_trac_runtime,
                "populate_TpmInfoByNode: I2c device in the MRW was not found in the PCRD having engine: 0x%X masterport: 0x%X devicetype: 0x%X address: 0x%X slaveport: 0x%X devicepurpose: 0x%X master HUID: %X",
                i2cDev.engine,
                i2cDev.masterPort,
                i2cDev.deviceType,
                i2cDev.addr,
                i2cDev.slavePort,
                i2cDev.devicePurpose,
                TARGETING::get_huid(i2cDev.masterChip));
           /*@
            * @errortype
            * @reasoncode   RUNTIME::RC_EXTRA_I2C_DEVICE_IN_MRW
            * @moduleid     RUNTIME::MOD_POPULATE_TPMINFOBYNODE
            * @severity     ERRL_SEV_UNRECOVERABLE
            * @userdata1    [0:7] I2C engine
            * @userdata1    [8:15] I2C masterPort
            * @userdata1    [16:23] I2C slave deviceType
            * @userdata1    [24:31] I2C slave address
            * @userdata1    [32:39] I2C slave port
            * @userdata1    [40:47] I2C device purpose
            * @userdata1    [48:63] Bus speed in KHz
            * @userdata2    master chip HUID
            * @devdesc      An I2C device in the MRW has no match
            *               in the PCRD.
            * @custdesc     Platform security problem detected
            */
            auto err = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                RUNTIME::MOD_POPULATE_TPMINFOBYNODE,
                RUNTIME::RC_EXTRA_I2C_DEVICE_IN_MRW,
                TWO_UINT32_TO_UINT64(
                    FOUR_UINT8_TO_UINT32(i2cDev.engine,
                                     i2cDev.masterPort,
                                     i2cDev.deviceType,
                                     i2cDev.addr),
                    TWO_UINT16_TO_UINT32(
                        TWO_UINT8_TO_UINT16(i2cDev.slavePort,
                                        i2cDev.devicePurpose),
                        i2cDev.busFreqKhz)
                ),
                TARGETING::get_huid(i2cDev.masterChip),
                true);
            err->collectTrace(RUNTIME_COMP_NAME);
            ERRORLOG::errlCommit(err, RUNTIME_COMP_ID);
        }
    }

    // advance the current offset to account for the physical
    // interaction mechanism info struct
    l_currOffset += sizeof(*l_physInter);

    // populate the second part of the pointer pair from earlier
    l_hdatTpmData->hdatPhysInter.hdatSize = l_currOffset - l_physInterStart;

    ////////////////////////////////////////////////////////////////////////////
    // Section Hash and Verification Function offsets array
    ////////////////////////////////////////////////////////////////////////////

    // Only add if SecureROM is available and valid.
    if (g_BlToHbDataManager.isValid())
    {
        // populate the first part of pointer pair from earlier to point here
        l_hdatTpmData->hdatHashVerifyFunc.hdatOffset = l_currOffset;

        // the following will be used to calculate the second part of pointer pair
        auto l_hdatHashVerifyStart = l_currOffset;

        // the current offset now corresponds to the hash and verification function
        // info array header
        auto const l_hdatHashVerifyFunc = reinterpret_cast<
                            HDAT::hdatHDIFDataArray_t*>(l_baseAddr + l_currOffset);

        // fill in the values for the Secure Boot TPM Info Array Header
        l_hdatHashVerifyFunc->hdatOffset = sizeof(*l_hdatHashVerifyFunc);

        // Assert the number of function types does not exceed the HDAT spec
        assert(SecRomFuncTypes.size() <= SB_FUNC_TYPES::MAX_TYPES, "Number entries per node exceeds HDAT spec");
        l_hdatHashVerifyFunc->hdatArrayCnt = SecRomFuncTypes.size();
        l_hdatHashVerifyFunc->hdatAllocSize = sizeof(HDAT::hdatHashVerifyFunc_t);
        l_hdatHashVerifyFunc->hdatActSize = sizeof(HDAT::hdatHashVerifyFunc_t);

        // advance current offset to after the Hash and Verification Function
        // offsets array header
        l_currOffset += sizeof(*l_hdatHashVerifyFunc);

        // Iterate through all function types available and obtain their current
        // version and offset
        for (auto const &funcType : SecRomFuncTypes)
        {
            auto l_hdatHashVerifyInfo =
                reinterpret_cast<HDAT::hdatHashVerifyFunc_t*>(l_baseAddr +
                                                              l_currOffset);

            // Set Function type
            l_hdatHashVerifyInfo->sbFuncType = funcType;

            // Get version of function currently selected
            l_hdatHashVerifyInfo->sbFuncVer =
                                         SECUREBOOT::getSecRomFuncVersion(funcType);

            // Set DbobID
            l_hdatHashVerifyInfo->dbobId = l_node->getAttr<
                                                      TARGETING::ATTR_ORDINAL_ID>();

            // Obtain function offset based on the current version
            l_hdatHashVerifyInfo->sbFuncOffset =
                                         SECUREBOOT::getSecRomFuncOffset(funcType);

            // advance the current offset and instance pointer
            l_currOffset += sizeof(*l_hdatHashVerifyInfo);
        }

        // populate the second part of the pointer pair from earlier
        l_hdatTpmData->hdatHashVerifyFunc.hdatSize = l_currOffset -
                                                     l_hdatHashVerifyStart;
    }
    else
    {
        // SecureROM not available or valid set pointer pair to 0's
        l_hdatTpmData->hdatHashVerifyFunc.hdatOffset = 0;
        l_hdatTpmData->hdatHashVerifyFunc.hdatSize = 0;
    }

    // set the total structure length to the current offset
    l_hdatTpmData->hdatHdr.hdatSize = l_currOffset;

    } while (0);

    return (l_elog);
}

errlHndl_t populate_hbTpmInfo()
{
    errlHndl_t l_elog = nullptr;

    do {

        TRACFCOMP(g_trac_runtime, "Running populate_hbTpmInfo");

        TARGETING::Target* sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr,
            "populate_hbTpmInfo: Bug! Could not obtain top level target");

        // This attribute is only set on a multi-node system.
        // We will use it below to detect a multi-node scenario
        auto hb_images = sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        // if single node system
        if (!hb_images)
        {
            TRACDCOMP( g_trac_runtime, "populate_hbTpmInfo: Single node system");
            l_elog = populate_TpmInfoByNode(0); // 0 for single node
            if(l_elog != nullptr)
            {
                TRACFCOMP( g_trac_runtime, "populate_hbTpmInfo: "
                    "populate_TpmInfoByNode failed" );
            }
            break;
        }
        // multinode system / grab payload base to give to the nodes
        uint64_t payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

        // get the node id for the master chip
        const auto l_masterNode = TARGETING::UTIL::getCurrentNodePhysId();


        // start the 1 in the mask at leftmost position
        decltype(hb_images) l_mask = 0x1 << (sizeof(hb_images)*BITS_PER_BYTE-1);

        TRACDCOMP( g_trac_runtime, "populate_hbTpmInfo: l_mask 0x%.16llX hb_images 0x%.16llX",l_mask,hb_images);

        // start at node 0, iterates thru all nodes in blueprint
        uint32_t l_node = 0;

        // As the master node we assign instances to each node for them to
        // write their HDAT TPM instance info to.
        // start node instance at 0, counts only present/functional nodes
        uint32_t l_instance = 0;

        // create a message queue for receipt of responses from nodes
        msg_q_t msgQ = msg_q_create();
        l_elog = MBOX::msgq_register(MBOX::HB_POP_TPM_INFO_MSGQ, msgQ);

        if(l_elog)
        {
            TRACFCOMP( g_trac_runtime, "populate_hbTpmInfo: MBOX::msgq_register failed!" );
            break;
        }

        // keep track of the number of messages we send so we know how
        // many responses to expect
        int msg_count = 0;

        // while the one in the mask hasn't shifted out
        while (l_mask)
        {
            // if this node is present
            if(l_mask & hb_images)
            {
                TRACFCOMP( g_trac_runtime, "populate_hbTpmInfo: "
                    "MsgToNode (instance) %d for HBRT TPM Info",
                           l_node );

                // Send message to the current node
                msg_t* msg = msg_allocate();
                msg->type = IPC::IPC_POPULATE_TPM_INFO_BY_NODE;
                msg->data[0] = l_instance;   // instance number
                msg->data[1] = l_masterNode; // respond to this node
                msg->extra_data = reinterpret_cast<uint64_t*>(payloadBase);

                l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);

                if (l_elog)
                {
                    TRACFCOMP( g_trac_runtime, "MBOX::send to node %d from node %d failed",
                               l_node, l_masterNode);
                    msg_free(msg);
                    break;
                }
                msg_count++;
                l_instance++;
            }
            l_mask >>= 1; // shift to the right for the next node
            l_node++; // go to the next node
        }

        if (l_elog == nullptr)
        {
            msg_t* l_response = nullptr;
            // TODO RTC:189356 - need timeout here
            while (msg_count)
            {
                l_response = msg_wait(msgQ);
                TRACFCOMP(g_trac_runtime,
                    "populate_hbTpmInfo: drawer %d completed",
                    l_response->data[0]);
                msg_free(l_response);
                msg_count--;
            }
        }

        MBOX::msgq_unregister(MBOX::HB_POP_TPM_INFO_MSGQ);
        msg_q_destroy(msgQ);

    } while(0);

    return (l_elog);
} // end populate_hbTpmInfo

//******************************************************************************
//sendSBEsystemConfig_timer function
//Used inside the sendSBEsystemConfig() to wait for responses from other nodes
//******************************************************************************
void* sendSBEsystemConfig_timer(void* i_msgQPtr)

{
    int rc=0;

    msg_t* msg = msg_allocate();
    msg->type = HB_SBE_SYSCONFIG_TIMER_MSG;
    uint32_t l_time_ms =0;

    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);


    //this loop will be broken when the main thread receives
    //all the messages and the timer thread receives the
    //HB_SBE_MSG_DONE message

    do
    {
        if (l_time_ms < MAX_TIME_ALLOWED_MS)
        {
            msg->data[1] = CONTINUE_WAIT_FOR_MSGS;
        }
        else
        {
            // HB_SBE_SYSCONFIG_TIMER_MSG is sent to the main thread indicating
            // timer expired so the main thread responds back with HB_SBE_MSG_DONE
            // indicating the timer is not needed and exit the loop
            msg->data[1]=TIME_EXPIRED;
        }

        rc= msg_sendrecv(*msgQ, msg);
        if (rc)
        {
            TRACFCOMP( g_trac_runtime,
                        "sendSBEsystemConfig timer failed msg sendrecv %d",rc);
        }
        if (msg->data[1] == HB_SBE_MSG_DONE)
        {
            TRACFCOMP( g_trac_runtime,
                        "sendSBEsystemConfig timer not needed.");
            break;
        }

        nanosleep(0,NS_PER_MSEC);
        l_time_ms++;

    }while(1);

    msg_free(msg);

    return NULL;
}

//******************************************************************************
//collectRespFromAllDrawers function
//Used inside the sendSBEsystemConfig() to wait and collect responses from
//all other drawers
//******************************************************************************
errlHndl_t collectRespFromAllDrawers( void* i_msgQPtr, uint64_t i_msgCount,
                                      uint32_t i_msgType,
                                      uint64_t& i_systemFabricConfigurationMap )
{
    errlHndl_t  l_elog = nullptr;
    uint64_t msg_count = i_msgCount;
    msg_q_t* msgQ = static_cast<msg_q_t*>(i_msgQPtr);

    //wait for all hb images to respond
    //want to spawn a timer thread
    tid_t l_progTid = task_create(
               RUNTIME::sendSBEsystemConfig_timer,msgQ);
    assert( l_progTid > 0 ,"sendSBEsystemConfig_timer failed");
    while(msg_count)
    {
        msg_t* response = msg_wait(*msgQ);

        if (response->type == HB_SBE_SYSCONFIG_TIMER_MSG)
        {
            if (response->data[1] == TIME_EXPIRED)
            {
                //timer has expired
                TRACFCOMP( g_trac_runtime,
                        "collectRespFromAllDrawers failed to "
                        "receive messages from all hb images in time" );
                //tell the timer thread to exit
                response->data[1] = HB_SBE_MSG_DONE;
                msg_respond(*msgQ,response);

                //generate an errorlog
                /*@
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       RUNTIME::MOD_SEND_SBE_SYSCONFIG,
                 *  @reasoncode     RUNTIME::RC_SEND_SBE_TIMER_EXPIRED,
                 *  @userdata1      Message Type IPC_QUERY_CHIPINFO or
                 *                               IPC_SET_SBE_CHIPINFO
                 *  @userdata2      Number of nodes that have not
                 *                  responded
                 *
                 *  @devdesc        messages from other nodes have
                 *                  not returned in time
                 */
                l_elog = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                RUNTIME::MOD_SEND_SBE_SYSCONFIG,
                                RUNTIME::RC_SEND_SBE_TIMER_EXPIRED,
                                i_msgType,
                                msg_count   );
                l_elog->collectTrace(RUNTIME_COMP_NAME);
                l_elog->collectTrace("IPC");
                l_elog->collectTrace("MBOXMSG");
                //Commit the Error log
                errlCommit(l_elog,RUNTIME_COMP_ID);
                // Break the While loop and wait for the child thread to exit
                break;

            }
            else if( response->data[1] == CONTINUE_WAIT_FOR_MSGS)
            {
                TRACFCOMP( g_trac_runtime,
                    "collectRespFromAllDrawers timer continue waiting message.");
                response->data[1] =HB_SBE_WAITING_FOR_MSG;
                msg_respond(*msgQ,response);
            }
        }
        else if (response->type == IPC::IPC_QUERY_CHIPINFO)
        {
            uint64_t l_nodeInfo =
                  reinterpret_cast<uint64_t>(response->extra_data);


            //Process msg, if we are waiting for IPC_QUERY_CHIPINFO response.
            if (i_msgType == IPC::IPC_QUERY_CHIPINFO)
            {
                TRACFCOMP(g_trac_runtime,
                    "IPC_QUERY_CHIPINFO : drawer %d completed info 0x%lx",
                    response->data[0], l_nodeInfo);
                //Apend the nodeInfo to be used in sendSBESystemConfig
                i_systemFabricConfigurationMap |= l_nodeInfo;
                --msg_count;
            }
            else
            {
                TRACFCOMP(g_trac_runtime,
                    "IPC_QUERY_CHIPINFO : unexpected message from drawer %d ",
                    response->data[0]);
            }

            msg_free(response);

        }
        else if (response->type == IPC::IPC_SET_SBE_CHIPINFO)
        {
            //Process msg, if we are waiting for IPC_SET_SBE_CHIPINFO response.
            if (i_msgType == IPC::IPC_SET_SBE_CHIPINFO)
            {
                TRACFCOMP(g_trac_runtime,
                  "IPC_SET_SBE_CHIPINFO : drawer %d completed",
                  response->data[0]);
                --msg_count;
            }
            else
            {
                TRACFCOMP(g_trac_runtime,
                    "IPC_SET_SBE_CHIPINFO : unexpected message from drawer %d ",
                    response->data[0]);
            }

            msg_free(response);
        }
    }

    //the msg_count should be 0 at this point to have
    //exited from the loop above.  If the msg count
    //is not zero then the timer must have expired
    //and the code would have asserted
    //Now need to tell the child timer thread to exit

    //tell the child timer thread to exit if didn't
    //already timeout
    if (msg_count ==0)
    {
        msg_t* response = msg_wait(*msgQ);
        if (response->type == HB_SBE_SYSCONFIG_TIMER_MSG)
        {
            TRACFCOMP( g_trac_runtime,
                    "collectRespFromAllDrawers received all hb "
                    "images in time for message type %d",i_msgType);

            response->data[1] = HB_SBE_MSG_DONE;
            msg_respond(*msgQ,response);
        }
    }

    //wait for the child thread to end
    int l_childsts =0;
    void* l_childrc = NULL;
    tid_t l_tidretrc = task_wait_tid(l_progTid,&l_childsts,&l_childrc);
    if ((static_cast<int16_t>(l_tidretrc) < 0)
        || (l_childsts != TASK_STATUS_EXITED_CLEAN ))
    {
        // the launched task failed or crashed,
        TRACFCOMP( g_trac_runtime,
            "task_wait_tid failed; l_tidretrc=0x%x, l_childsts=0x%x",
            l_tidretrc, l_childsts);

                //generate an errorlog
                /*@
                 *  @errortype      ERRL_SEV_CRITICAL_SYS_TERM
                 *  @moduleid       RUNTIME::MOD_SEND_SBE_SYSCONFIG,
                 *  @reasoncode     RUNTIME::RC_HOST_TIMER_THREAD_FAIL,,
                 *  @userdata1      l_tidretrc,
                 *  @userdata2      l_childsts,
                 *
                 *  @devdesc        sendSBESystemConfig timer thread
                 *                  failed
                 */
                l_elog = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                RUNTIME::MOD_SEND_SBE_SYSCONFIG,
                                RUNTIME::RC_HOST_TIMER_THREAD_FAIL,
                                l_tidretrc,
                                l_childsts);

                l_elog->collectTrace(RUNTIME_COMP_NAME);
                return l_elog;
    }

    return(l_elog);

}
// Sends the chip config down to the SBEs
// Determines the system wide chip information to send to
// the SBE so it knows which chips are present for syncing with in MPIPL.
// Uses IPC to communication between HB instances if multinode
errlHndl_t sendSBESystemConfig( void )
{
    errlHndl_t  l_elog = nullptr;
    uint64_t l_systemFabricConfigurationMap = 0x0;


    do {


        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr);

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(mproc);
        TARGETING::EntityPath epath = mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();
        const TARGETING::EntityPath::PathElement pe =
          epath.pathElementOfType(TARGETING::TYPE_NODE);
        uint64_t nodeid = pe.instance;


        //Determine this HB Instance SBE config.
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips, TARGETING::TYPE_PROC , true);
        for(auto l_proc : l_procChips)
        {
            //Get fabric info from proc
            uint8_t l_fabricChipId =
              l_proc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
            uint8_t l_fabricGroupId =
              l_proc->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
            //Calculate what bit position this will be
            uint8_t l_bitPos = l_fabricChipId + (MAX_PROCS_PER_NODE * l_fabricGroupId);

            //Set the bit @ l_bitPos to be 1 because this is a functional proc
            l_systemFabricConfigurationMap |= (0x8000000000000000 >> l_bitPos);
        }

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.   It eventually
        // needs to be setup by a hb routine that snoops for multiple nodes.
        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
          sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
        TRACFCOMP( g_trac_runtime, "hb_images = 0x%x, nodeid = 0x%x", hb_images, nodeid);
        if (0 != hb_images)  //Multi-node
        {
            // multi-node system
            // This msgQ catches the node responses from the commands
            msg_q_t msgQ = msg_q_create();
            l_elog = MBOX::msgq_register(MBOX::HB_SBE_SYSCONFIG_MSGQ,msgQ);
            if(l_elog)
            {
                TRACFCOMP( g_trac_runtime, "MBOX::msgq_register failed!" );
                break;
            }

            // keep track of the number of messages we send so we
            // know how many responses to expect
            uint64_t msg_count = 0;

            // loop thru rest all nodes -- sending msg to each
            TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
              ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);
            for (uint64_t l_node=0; (l_node < MAX_NODES_PER_SYS); l_node++ )
            {
                // skip sending to ourselves, we did our construction above
                if(l_node == nodeid)
                    continue;

                if( 0 != ((mask >> l_node) & hb_images ) )
                {
                    TRACFCOMP( g_trac_runtime, "send IPC_QUERY_CHIPINFO "
                               "message to node %d",l_node );

                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_QUERY_CHIPINFO;
                    msg->data[0] = l_node;      // destination node
                    msg->data[1] = nodeid;      // respond to this node

                    // send the message to the slave hb instance
                    l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);
                    if( l_elog )
                    {
                        TRACFCOMP( g_trac_runtime, "MBOX::send to node %d"
                                   " failed", l_node);
                        break;
                    }

                    ++msg_count;

                } // end if node to process
            } // end for loop on nodes

            // wait for a response to each message we sent
            if( l_elog == nullptr )
            {
                l_elog = collectRespFromAllDrawers( &msgQ, msg_count, IPC::IPC_QUERY_CHIPINFO, l_systemFabricConfigurationMap);
            }

            //////////////////////////////////////////////////////////////////////
            // Now send each HB instance the full info to write to the SBEs
            ////////////////////////////
            if( l_elog == nullptr )
            {
                msg_count = 0;
                for (uint64_t l_node=0; (l_node < MAX_NODES_PER_SYS); l_node++ )
                {
                    // skip sending to ourselves, we will do our set below
                    if(l_node == nodeid)
                        continue;

                    if( 0 != ((mask >> l_node) & hb_images ) )
                    {
                        TRACFCOMP( g_trac_runtime, "send IPC_SET_SBE_CHIPINFO "
                                   "message to node %d",l_node );

                        msg_t * msg = msg_allocate();
                        msg->type = IPC::IPC_SET_SBE_CHIPINFO;
                        msg->data[0] = l_node;      // destination node
                        msg->data[1] = nodeid;      // respond to this node
                        msg->extra_data = reinterpret_cast<uint64_t*>(l_systemFabricConfigurationMap);

                        // send the message to the slave hb instance
                        l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);
                        if( l_elog )
                        {
                            TRACFCOMP( g_trac_runtime, "MBOX::send to node %d"
                                       " failed", l_node);
                            break;
                        }

                        ++msg_count;

                    } // end if node to process
                } // end for loop on nodes
            }

            // wait for a response to each message we sent
            if( l_elog == nullptr )
            {
                l_elog = collectRespFromAllDrawers( &msgQ, msg_count, IPC::IPC_SET_SBE_CHIPINFO, l_systemFabricConfigurationMap);
            }

            MBOX::msgq_unregister(MBOX::HB_SBE_SYSCONFIG_MSGQ);
            msg_q_destroy(msgQ);
        }

        //Now do this HB instance
        if( l_elog == nullptr )
        {
            for(auto l_proc : l_procChips)
            {
                TRACDCOMP( g_trac_runtime,
                           "calling sendSystemConfig on proc 0x%x",
                           TARGETING::get_huid(l_proc));
                l_elog = SBEIO::sendSystemConfig(l_systemFabricConfigurationMap,
                                                l_proc);
                if ( l_elog )
                {
                    TRACFCOMP( g_trac_runtime,
                               "sendSystemConfig ERROR : Error sending sbe chip-op to proc 0x%.8X. Returning errorlog, reason=0x%x",
                               TARGETING::get_huid(l_proc),
                               l_elog->reasonCode() );
                    break;
                }
            }
        }

    } while(0);

    return(l_elog);

} // end sendSBESystemConfig


// populate the hostboot runtime data section for the system
// will send msg to slave nodes in multinode system
errlHndl_t populate_hbRuntimeData( void )
{
    errlHndl_t  l_elog = nullptr;

    do {
        TRACFCOMP(g_trac_runtime, "Running populate_hbRuntimeData");

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(mproc);

        TARGETING::EntityPath epath =
            mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        const TARGETING::EntityPath::PathElement pe =
            epath.pathElementOfType(TARGETING::TYPE_NODE);

        uint64_t nodeid = pe.instance;

        TRACFCOMP( g_trac_runtime, "Master node nodeid = %x",
                   nodeid);

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.   It eventually
        // needs to be setup by a hb routine that snoops for multiple nodes.
        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr);

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
            sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        TRACFCOMP( g_trac_runtime, "ATTR_HB_EXISTING_IMAGE (hb_images) = %x",
                hb_images);

        if (0 == hb_images)  //Single-node
        {
            if( !TARGETING::is_no_load() )
            {
                l_elog = populate_HbRsvMem(nodeid,true);
                if(l_elog != nullptr)
                {
                    TRACFCOMP( g_trac_runtime, "populate_HbRsvMem failed" );
                }
            }
            else
            {
                //When PAYLOAD_KIND = NONE (aka simics)
                //Configure the ATTR_HBRT_HYP_ID attributes
                //When PAYLOAD_KIND is set, we call this function from
                //populate_HbRsvMem as that function is also executed on slave
                //nodes in a multi-node config. But, moving it there removes
                //this call in simics case. Therefore, adding it here.
                l_elog = RUNTIME::configureHbrtHypIds(TARGETING::is_phyp_load());
                if (l_elog)
                {
                    TRACFCOMP(g_trac_runtime, ERR_MRK"populate_HbRsvMem> i_nodeId=%d"
                            " configureHbrtHypIds failed");
                    break;
                }
                // still fill in HB DATA for testing
                uint64_t l_startAddr = cpu_spr_value(CPU_SPR_HRMOR) +
                            VMM_HB_DATA_TOC_START_OFFSET;

                uint64_t l_endAddr = 0;
                uint64_t l_totalSizeAligned = 0;
                bool startAddressValid = true;

                l_elog = fill_RsvMem_hbData(l_startAddr, l_endAddr,
                                startAddressValid, l_totalSizeAligned);
                if(l_elog != nullptr)
                {
                    TRACFCOMP( g_trac_runtime, "fill_RsvMem_hbData failed" );
                }

                // Get list of processor chips
                TARGETING::TargetHandleList l_procChips;
                getAllChips( l_procChips,
                            TARGETING::TYPE_PROC,
                            true);
                //Pass start address down to SBE via chipop
                // Loop through all functional Procs
                for (const auto & l_procChip: l_procChips)
                {
                    //Pass start address down to SBE via chip-op
                    l_elog = SBEIO::sendPsuStashKeyAddrRequest(SBEIO::RSV_MEM_ATTR_ADDR,
                                                               l_startAddr,
                                                               l_procChip);
                    if (l_elog)
                    {
                        TRACFCOMP( g_trac_runtime, "sendPsuStashKeyAddrRequest failed for target: %x",
                                   TARGETING::get_huid(l_procChip) );
                        break;
                    }
                }
            }
        }
        else
        {
            // multi-node system
            uint64_t payloadBase = sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>();

            // populate our own node specific data + the common stuff
            l_elog = populate_HbRsvMem(nodeid,true);

            if(l_elog != nullptr)
            {
                TRACFCOMP( g_trac_runtime, "populate_HbRsvMem failed" );
                break;
            }

            // This msgQ catches the node responses from the commands
            msg_q_t msgQ = msg_q_create();
            l_elog = MBOX::msgq_register(MBOX::HB_POP_ATTR_MSGQ,msgQ);

            if(l_elog)
            {
                TRACFCOMP( g_trac_runtime, "MBOX::msgq_register failed!" );
                break;
            }

            // keep track of the number of messages we send so we
            // know how many responses to expect
            uint64_t msg_count = 0;

            // loop thru rest all nodes -- sending msg to each
            TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

            TRACFCOMP( g_trac_runtime, "HB_EXISTING_IMAGE (mask) = %x",
                    mask);

            for (uint64_t l_node=0; (l_node < MAX_NODES_PER_SYS); l_node++ )
            {
                // skip sending to ourselves, we did our construction above
                if(l_node == nodeid)
                    continue;

                if( 0 != ((mask >> l_node) & hb_images ) )
                {
                    TRACFCOMP( g_trac_runtime, "send IPC_POPULATE_ATTRIBUTES "
                            "message to node %d",
                            l_node );

                    msg_t * msg = msg_allocate();
                    msg->type = IPC::IPC_POPULATE_ATTRIBUTES;
                    msg->data[0] = l_node;      // destination node
                    msg->data[1] = nodeid;      // respond to this node
                    msg->extra_data = reinterpret_cast<uint64_t*>(payloadBase);

                    // send the message to the slave hb instance
                    l_elog = MBOX::send(MBOX::HB_IPC_MSGQ, msg, l_node);

                    if( l_elog )
                    {
                        TRACFCOMP( g_trac_runtime, "MBOX::send to node %d"
                                " failed", l_node);
                        break;
                    }

                    ++msg_count;

                } // end if node to process
            } // end for loop on nodes

            // wait for a response to each message we sent
            if( l_elog == nullptr )
            {
                //$TODO RTC:189356 - need timeout here
                while(msg_count)
                {
                    msg_t * response = msg_wait(msgQ);
                    TRACFCOMP(g_trac_runtime,
                            "IPC_POPULATE_ATTRIBUTES : drawer %d completed",
                            response->data[0]);
                    msg_free(response);
                    --msg_count;
                }
            }

            MBOX::msgq_unregister(MBOX::HB_POP_ATTR_MSGQ);
            msg_q_destroy(msgQ);
        }

    } while(0);

    return(l_elog);

} // end populate_hbRuntimeData


errlHndl_t persistent_rwAttrRuntimeCheck( void )
{
    errlHndl_t l_err = nullptr;
    // For security purposes make R/W attribute memory pages non-ejectable
    // and of these, verify the persistent attributes. If all goes well,
    // we can hand these over to runtime with added confidence of their
    // validity, otherwise we stop the IPL.
    msg_q_t l_msgQ = msg_q_resolve(TARGETING::ATTRRP_MSG_Q);

    assert(l_msgQ != nullptr, "Bug! Message queue did not resolve properly!");

    msg_t* l_msg = msg_allocate();

    assert(l_msg != nullptr, "Bug! Message allocation failed!");

    l_msg->type = TARGETING::MSG_MM_RP_RUNTIME_PREP;

    l_msg->data[0] = TARGETING::MSG_MM_RP_RUNTIME_PREP_BEGIN;

    int rc = msg_sendrecv(l_msgQ, l_msg);

    if (rc != 0 || l_msg->data[1])
    {
        uint64_t l_rc = l_msg->data[1];

        TRACFCOMP( g_trac_runtime,
            "persistent_rwAttrRuntimeCheck: failed to pin attribute memory. "
            "Message rc: %llX msg_sendrecv rc:%i", l_rc, rc);

        /*@
         * @errortype
         * @reasoncode RUNTIME::RC_UNABLE_TO_PIN_ATTR_MEM
         * @moduleid   RUNTIME::MOD_ATTR_RUNTIME_CHECK_PREP_FAIL
         * @userdata1  Message return code from message handler
         * @userdata2  Return code from msg_sendrecv function
         * @devdesc    Unable to pin read/write attribute memory
         * @custdesc   Internal system error occured
         */
        l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        RUNTIME::MOD_ATTR_RUNTIME_CHECK_PREP_FAIL,
                        RUNTIME::RC_UNABLE_TO_PIN_ATTR_MEM,
                        l_rc,
                        rc,
                        true /* Add HB Software Callout */);
        l_err->collectTrace(RUNTIME_COMP_NAME);
    }
    else
    {
         TARGETING::TargetRangeFilter targets(
            TARGETING::targetService().begin(),
            TARGETING::targetService().end());
        for ( ; targets; ++targets)
        {
            validateAllRwNvAttr( *targets );
        }

        l_msg->type = TARGETING::MSG_MM_RP_RUNTIME_PREP;
        l_msg->data[0] = TARGETING::MSG_MM_RP_RUNTIME_PREP_END;

        int rc = msg_sendrecv(l_msgQ, l_msg);

        if (rc != 0 || l_msg->data[1])
        {
            uint64_t l_rc = l_msg->data[1];

            TRACFCOMP( g_trac_runtime, "persistent_rwAttrRuntimeCheck:"
                " failed to unpin attribute memory. "
                "Message rc: %llX msg_sendrecv rc:%i", l_rc, rc);

            /*@
             * @errortype
             * @reasoncode RUNTIME::RC_UNABLE_TO_UNPIN_ATTR_MEM
             * @moduleid   RUNTIME::MOD_ATTR_RUNTIME_CHECK_PREP_FAIL
             * @userdata1  Message return code from message handler
             * @userdata2  Return code from msg_sendrecv function
             * @devdesc    Unable to unpin read/write attribute memory
             * @custdesc   Internal system error occured
             */
            l_err = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                        RUNTIME::MOD_ATTR_RUNTIME_CHECK_PREP_FAIL,
                        RUNTIME::RC_UNABLE_TO_UNPIN_ATTR_MEM,
                        l_rc,
                        rc,
                        true /* Add HB Software Callout */);
            l_err->collectTrace(RUNTIME_COMP_NAME);
        }
    }

    return l_err;
} // end persistent_rwAttrRuntimeCheck

errlHndl_t openUntrustedSpCommArea()
{
    TRACFCOMP( g_trac_runtime, ENTER_MRK "openUntrustedSpCommArea()");
    errlHndl_t l_err = nullptr;

    do {
    TARGETING::Target * l_sys = nullptr;
    TARGETING::targetService().getTopLevelTarget(l_sys);
    assert(l_sys != nullptr, "openUntrustedSpCommArea: top level target nullptr");

    // Get Payload HRMOR
    uint64_t l_hrmor = l_sys->getAttr<TARGETING::ATTR_PAYLOAD_BASE>() * MEGABYTE;

    // pass 0 since there is only one record
    const uint64_t l_instance = 0;
    uint64_t l_cpuCtrlDataAddr = 0;
    size_t l_cpuCtrlDataSizeMax = 0;

    // Get the address of the Spira-H CPU control section
    l_err = RUNTIME::get_host_data_section( RUNTIME::CPU_CTRL,
                                            l_instance,
                                            l_cpuCtrlDataAddr,
                                            l_cpuCtrlDataSizeMax);
    if(l_err != nullptr)
    {
        TRACFCOMP( g_trac_runtime, ERR_MRK "openUntrustedSpCommArea(): get_host_data_section() failed for CPU_CTRL HDAT section");
        break;
    }

    // Traverse CPU Controls Header Area pointer to find CPU Controls Structure
    auto const l_pCpuCtrlHdr =
        reinterpret_cast<hdatHDIF_t*>(l_cpuCtrlDataAddr);
    auto const l_pCpuDataPointer =
        reinterpret_cast<hdatHDIFDataHdr_t*>(l_cpuCtrlDataAddr +
                                             l_pCpuCtrlHdr->hdatDataPtrOffset);
    auto const l_pCpuCtrlInfo =
        reinterpret_cast<hdatCpuCtrlInfo_t*>(l_cpuCtrlDataAddr +
                                             l_pCpuDataPointer->hdatOffset);

    // Get Address of First SP ATTN area and size of both SP ATTN areas
    // Add HRMOR to address as it's relative to the HRMOR
    uint64_t l_spAttnStartAddr = l_pCpuCtrlInfo->spAttnArea1.address + l_hrmor;
    size_t l_spAttnCombinedSize = l_pCpuCtrlInfo->spAttnArea1.size +
                                  l_pCpuCtrlInfo->spAttnArea2.size;

    TRACFCOMP( g_trac_runtime, "openUntrustedSpCommArea() SP ATTN addr = 0x%016llx combined size 0x%X",
               l_spAttnStartAddr,
               l_spAttnCombinedSize);

    // Open unsecure SBE memory regions
    // Loop through all functional Procs
    TARGETING::TargetHandleList l_procChips;
    getAllChips(l_procChips, TARGETING::TYPE_PROC);
    for (const auto & l_procChip : l_procChips)
    {
        // Get HUID of proc for trace
        auto l_id = TARGETING::get_huid(l_procChip);

        // Open SP ATTN region
        l_err = SBEIO::openUnsecureMemRegion(l_spAttnStartAddr,
                                             l_spAttnCombinedSize,
                                             true, //true=Read-Write
                                             l_procChip);
        if (l_err)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "openUntrustedSpCommArea(): openUnsecureMemRegion() failed proc = 0x%X addr = 0x%016llx size = 0x%X",
                      l_id,
                      l_spAttnStartAddr,
                      l_spAttnCombinedSize);
            break;
        }

        // Only open additional SBE window in PHYP mode
        if(TARGETING::is_phyp_load())
        {
            l_err = SBEIO::openUnsecureMemRegion(
                                        RUNTIME::SP_HOST_UNTRUSTED_COMM_AREA_ADDR,
                                        RUNTIME::SP_HOST_UNTRUSTED_COMM_AREA_SIZE,
                                        true, //true=Read-Write
                                        l_procChip);
            if (l_err)
            {
                TRACFCOMP(g_trac_runtime, ERR_MRK "openUntrustedSpCommArea(): openUnsecureMemRegion() failed proc = 0x%X addr = 0x%016llx size = 0x%X",
                          l_id,
                          RUNTIME::SP_HOST_UNTRUSTED_COMM_AREA_ADDR,
                          RUNTIME::SP_HOST_UNTRUSTED_COMM_AREA_SIZE);
                break;
            }
        }

        // Open Unsecure Memory Region for SBE FFDC Section
        uint64_t l_sbeffdcAddr =
            l_procChip->getAttr<TARGETING::ATTR_SBE_FFDC_ADDR>();
        uint64_t l_sbeffdcSize =
            SBEIO::SbePsu::getTheInstance().getSbeFFDCBufferSize();

        // Open Unsecure Memory Region for SBE FFDC Section
        l_err = SBEIO::openUnsecureMemRegion(l_sbeffdcAddr,
                                             l_sbeffdcSize,
                                             false, //Read-Only
                                             l_procChip);
        if(l_err)
        {
            TRACFCOMP( g_trac_runtime, ERR_MRK "openUntrustedSpCommArea(): openUnsecureMemRegion() failed proc = 0x%X addr = 0x%016llx size = 0x%X",
                      l_id,
                      l_sbeffdcAddr,
                      l_sbeffdcSize);

            break;
        }
    }
    if(l_err)
    {
        break;
    }

    } while(0);

    TRACFCOMP( g_trac_runtime, EXIT_MRK"openUntrustedSpCommArea()");

    return l_err;
}

void setPayloadBaseAddress(uint64_t i_payloadAddress)
{
    TARGETING::Target * sys = NULL;
    TARGETING::targetService().getTopLevelTarget( sys );
    sys->setAttr<TARGETING::ATTR_PAYLOAD_BASE>(i_payloadAddress);
}

} //namespace RUNTIME

