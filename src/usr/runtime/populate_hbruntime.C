/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/populate_hbruntime.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include <config.h>
#include "../hdat/hdattpmdata.H"
#include "../secureboot/trusted/tpmLogMgr.H"
#include "../secureboot/trusted/trustedboot.H"


namespace RUNTIME
{

mutex_t g_rhbMutex = MUTEX_INITIALIZER;

// used for populating the TPM required bit in HDAT
const uint16_t TPM_REQUIRED_BIT = 0x8000; //leftmost bit of uint16_t set to 1

const uint8_t BITS_PER_BYTE = 8;

trace_desc_t *g_trac_runtime = nullptr;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);

/** This is the original function used to load the HDAT data
 *  It contains support for PHYP payload
 *  It does not support OPAL payload
 *  OPAL must use the new function below - populate_HbRsvMem()
 *  RTC 169478 - remove when new rsv_mem structure is supported in FSP
 */
errlHndl_t populate_RtDataByNode(uint64_t iNodeId)
{
    errlHndl_t  l_elog = nullptr;
    const char* l_stringLabels[] =
                     { "ibm,hbrt-vpd-image" ,
                       "ibm,hbrt-target-image" };

    // OPAL not supported
    if(TARGETING::is_sapphire_load())
    {
        return l_elog;
    }

    do {
        // Wipe out our cache of the NACA/SPIRA pointers
        RUNTIME::rediscover_hdat();

        // Find pointer for HBRT data structure on given Node
        // Each node will have HBRT_NUM_PTRS sections

        // We will update VPD part first
        uint64_t l_section = (iNodeId * HBRT_NUM_PTRS) + HBRT_VPD_SECTION;
        uint64_t l_hbrtDataAddr = 0;
        uint64_t l_hbrtDataSizeMax = 0;
        l_elog = RUNTIME::get_host_data_section(RUNTIME::HBRT,
                                                l_section,
                                                l_hbrtDataAddr,
                                                l_hbrtDataSizeMax );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                       "populate_RtDataByNode fail getHostDataSection VPD" );
            break;
        }

        // Currently have access to HBRT data pointer
        // So start filling in the structure
        hdatHBRT_t*  l_hbrtPtr = reinterpret_cast<hdatHBRT_t *>(l_hbrtDataAddr);

        memcpy( l_hbrtPtr->hdatStringName,
                l_stringLabels[HBRT_VPD_SECTION],
                strlen(l_stringLabels[HBRT_VPD_SECTION]) );

        l_hbrtPtr->hdatInstance = static_cast<uint32_t>(iNodeId);

        // Need to get the blob pointer one level deeper
        l_elog = RUNTIME::get_host_data_section(RUNTIME::HBRT_DATA,
                                                l_section,
                                                l_hbrtDataAddr,
                                                l_hbrtDataSizeMax );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                "populate_RtDataByNode fail getHostDataSection VPD data" );
            break;
        }

        // Put VPD data into the structure now
        l_elog = VPD::vpd_load_rt_image( l_hbrtDataAddr );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                       "populate_RtDataByNode fail VPD call" );
            break;
        }

        // Time to update ATTRIB section now
        l_section = (iNodeId * HBRT_NUM_PTRS) + HBRT_ATTRIB_SECTION;
        l_elog = RUNTIME::get_host_data_section(RUNTIME::HBRT,
                                                l_section,
                                                l_hbrtDataAddr,
                                                l_hbrtDataSizeMax );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                "populate_RtDataByNode fail getHostDataSection ATTRIB" );
            break;
        }

        // Put in string/instance into HBRT area
        l_hbrtPtr = reinterpret_cast<hdatHBRT_t *>(l_hbrtDataAddr);
        memcpy( l_hbrtPtr->hdatStringName,
                l_stringLabels[HBRT_ATTRIB_SECTION],
                strlen(l_stringLabels[HBRT_ATTRIB_SECTION]) );

        l_hbrtPtr->hdatInstance = static_cast<uint32_t>(iNodeId);

        // Need to get the blob pointer one level deeper
        l_elog = RUNTIME::get_host_data_section(RUNTIME::HBRT_DATA,
                                                l_section,
                                                l_hbrtDataAddr,
                                                l_hbrtDataSizeMax );
        if(l_elog != nullptr)
        {
            TRACFCOMP( g_trac_runtime,
                "populate_RtDataByNode fail getHostDataSection ATTRIB data" );
            break;
        }

        // Load ATTRIBUTE data into HDAT
        TARGETING::AttrRP::save(l_hbrtDataAddr);

        //Create a block map of memory so we can save a copy of the attribute
        //data incase we need to MPIPL
        //Account HRMOR (non 0 base addr)
        uint64_t    l_attrDataAddr =   cpu_spr_value(CPU_SPR_HRMOR)
                                       + VMM_ATTR_DATA_START_OFFSET;
        uint64_t l_attrCopyVmemAddr =
        reinterpret_cast<uint64_t>(mm_block_map(
            reinterpret_cast<void*>(l_attrDataAddr),
            VMM_ATTR_DATA_SIZE ));

        //Make sure the address returned from the block map call is not NULL
        if(l_attrCopyVmemAddr != 0)
        {
            //The function save() for AttrRP saves then entire HBD data
            // section of PNOR to the provided vmm address
            TARGETING::AttrRP::save(l_attrCopyVmemAddr);

            //Make sure to unmap the virtual address
            // because we won't need it anymore
            int l_rc =
                mm_block_unmap(reinterpret_cast<void*>(l_attrCopyVmemAddr));

            if(l_rc)
            {
                TRACFCOMP( g_trac_runtime,
                           "populate_RtDataByNode fail to unmap physical addr %p, virt addr %p",
                           reinterpret_cast<void*>(l_attrDataAddr),
                           reinterpret_cast<void*>(l_attrCopyVmemAddr));
                /*@ errorlog tag
                * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
                * @moduleid        RUNTIME::MOD_POPULATE_RTDATABYNODE
                * @reasoncode      RUNTIME::RC_UNMAP_FAIL
                * @userdata1       Phys address we are trying to unmap
                * @userdata2       Virtual address we are trying to unmap
                *
                * @devdesc         Error unmapping a virtual memory map
                * @custdesc        Kernel failed to unmap memory
                */
                l_elog = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       RUNTIME::MOD_POPULATE_RTDATABYNODE,
                                       RUNTIME::RC_UNMAP_FAIL,
                                       l_attrDataAddr,
                                       l_attrCopyVmemAddr,
                                       true);
            }
        }
        else
        {
            TRACFCOMP( g_trac_runtime,
                       "populate_RtDataByNode fail to map  physical addr %p, size %lx",
                       reinterpret_cast<void*>(l_attrDataAddr),
                       VMM_ATTR_DATA_SIZE );
            /*@ errorlog tag
            * @errortype       ERRORLOG::ERRL_SEV_UNRECOVERABLE
            * @moduleid        RUNTIME::MOD_POPULATE_RTDATABYNODE
            * @reasoncode      RUNTIME::RC_CANNOT_MAP_MEMORY
            * @userdata1       Phys address we are trying to unmap
            * @userdata2       Size of memory we are trying to map
            *
            * @devdesc         Error unmapping a virtual memory map
            * @custdesc        Kernel failed to map memory
            */
            l_elog = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                   RUNTIME::MOD_POPULATE_RTDATABYNODE,
                                   RUNTIME::RC_CANNOT_MAP_MEMORY,
                                   l_attrDataAddr,
                                   VMM_ATTR_DATA_SIZE,
                                   true);
        }

    } while(0);

    return(l_elog);
} // end populate_RtDataByNode


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

        // Get the address of the next section
        l_elog = RUNTIME::get_host_data_section( RUNTIME::RESERVED_MEM,
                                                 l_nextSection,
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


/**
 *  @brief Map physical address to virtual
 *  @param[in]  i_addr Physical address
 *  @param[in]  i_size Size of block to be mapped
 *  @param[out] o_addr Virtual address
 *  @return Error handle if error
 */
errlHndl_t mapPhysAddr(uint64_t i_addr,
                       uint64_t i_size,
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
    }

    return l_elog;
}


/**
 *  @brief Unmap virtual address block
 *  @param[in]  i_addr Virtual address
 *  @return Error handle if error
 */
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
         *
         * @devdesc         Error unmapping a virtual memory map
         * @custdesc        Kernel failed to unmap memory
         */
        l_elog = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            RUNTIME::MOD_UNMAP_VIRT_ADDR,
                            RUNTIME::RC_UNMAP_FAIL,
                            i_addr,
                            true);
    }

    return l_elog;
}


void traceHbRsvMemRange(hdatMsVpdRhbAddrRange_t* & i_rngPtr )
{
    TRACFCOMP(g_trac_runtime,
              "Setting HDAT HB Reserved Memory Range: "
              "%s RangeType 0x%X RangeId 0x%X "
              "StartAddress 0x%16X EndAddress 0x%16X",
              i_rngPtr->hdatRhbLabelString,
              i_rngPtr->hdatRhbRngType,
              i_rngPtr->hdatRhbRngId,
              i_rngPtr->hdatRhbAddrRngStrAddr,
              i_rngPtr->hdatRhbAddrRngEndAddr);
}


/**
 *  @brief Load the HDAT HB Reserved Memory
 *         address range structures on given node
 *  @param[in]  i_nodeId Node ID
 *  @return Error handle if error
 */
errlHndl_t populate_HbRsvMem(uint64_t i_nodeId)
{
    errlHndl_t l_elog = nullptr;

    do {
        // Wipe out our cache of the NACA/SPIRA pointers
        RUNTIME::rediscover_hdat();

        uint64_t l_topMemAddr = 0x0;
        const char* l_label = nullptr;
        uint32_t l_labelSize = 0;
        hdatMsVpdRhbAddrRange_t* l_rngPtr;
        uint64_t l_vAddr = 0x0;

        if(TARGETING::is_phyp_load())
        {
            // First phyp entry is for the entire 256M HB space
            uint64_t l_hbAddr = cpu_spr_value(CPU_SPR_HRMOR)
                                                - VMM_HRMOR_OFFSET;
            l_label = "ibm,hb-rsv-mem";
            l_labelSize = strlen(l_label) + 1;

            // Get a pointer to the next available HDAT HB Rsv Mem entry
            l_rngPtr = nullptr;
            l_elog = getNextRhbAddrRange(l_rngPtr);
            if(l_elog)
            {
                break;
            }

            // Fill in the entry
            l_rngPtr->hdatRhbRngType =
                    static_cast<uint8_t>(RANGE_TYPE_PRIMARY);
            l_rngPtr->hdatRhbRngId = i_nodeId;
            l_rngPtr->hdatRhbAddrRngStrAddr =
                    l_hbAddr | VmmManager::FORCE_PHYS_ADDR;
            l_rngPtr->hdatRhbAddrRngEndAddr =
                    (l_hbAddr | VmmManager::FORCE_PHYS_ADDR)
                        + VMM_HB_RSV_MEM_SIZE - 1 ;
            l_rngPtr->hdatRhbLabelSize = l_labelSize;
            memcpy( l_rngPtr->hdatRhbLabelString,
                    l_label,
                    l_labelSize );

            traceHbRsvMemRange(l_rngPtr);
        }

        else if(TARGETING::is_sapphire_load())
        {
            // Opal data goes at top_of_mem
            l_topMemAddr = TARGETING::get_top_mem_addr();
            assert (l_topMemAddr != 0,
                    "populate_HbRsvMem: Top of memory was 0!");

            // Opal HB reserved memory data
            // -----TOP_OF_MEM-------
            // -----HOMER_0----------
            // -----...--------------
            // -----HOMER_N----------
            // -----OCC Common-------
            // -----VPD--------------
            // -----ATTR Data--------
            // -----HBRT Image-------

            // First opal entries are for the HOMERs
            uint64_t l_homerAddr = l_topMemAddr;
            l_label = "ibm,homer-image";
            l_labelSize = strlen(l_label) + 1;

            // Loop through all functional Procs
            TARGETING::TargetHandleList l_procChips;
            getAllChips( l_procChips,
                         TARGETING::TYPE_PROC );

            for (const auto & l_procChip: l_procChips)
            {
                l_homerAddr -= VMM_HOMER_INSTANCE_SIZE;

                // Get a pointer to the next available HDAT HB Rsv Mem entry
                l_rngPtr = nullptr;
                l_elog = getNextRhbAddrRange(l_rngPtr);
                if(l_elog)
                {
                    break;
                }

                // Fill in the entry
                l_rngPtr->hdatRhbRngType =
                        static_cast<uint8_t>(RANGE_TYPE_HOMER_OCC);
                l_rngPtr->hdatRhbRngId =
                        l_procChip->getAttr<TARGETING::ATTR_HBRT_HYP_ID>();
                l_rngPtr->hdatRhbAddrRngStrAddr =
                        l_homerAddr | VmmManager::FORCE_PHYS_ADDR;
                l_rngPtr->hdatRhbAddrRngEndAddr =
                        (l_homerAddr | VmmManager::FORCE_PHYS_ADDR)
                            + VMM_HOMER_INSTANCE_SIZE - 1 ;
                l_rngPtr->hdatRhbLabelSize = l_labelSize;
                memcpy( l_rngPtr->hdatRhbLabelString,
                        l_label,
                        l_labelSize );

                traceHbRsvMemRange(l_rngPtr);
            }

            if(l_elog)
            {
                break;
            }


#ifdef CONFIG_START_OCC_DURING_BOOT
            // OCC Common entry
            uint64_t l_occCommonAddr = l_topMemAddr
                    - VMM_ALL_HOMER_OCC_MEMORY_SIZE;
            l_label = "ibm,occ-common-area";
            l_labelSize = strlen(l_label) + 1;

            // Get a pointer to the next available HDAT HB Rsv Mem entry
            l_rngPtr = nullptr;
            l_elog = getNextRhbAddrRange(l_rngPtr);
            if(l_elog)
            {
                break;
            }

            // Fill in the entry
            l_rngPtr->hdatRhbRngType =
                    static_cast<uint8_t>(RANGE_TYPE_HOMER_OCC);
            l_rngPtr->hdatRhbRngId = i_nodeId;
            l_rngPtr->hdatRhbAddrRngStrAddr =
                    l_occCommonAddr | VmmManager::FORCE_PHYS_ADDR;
            l_rngPtr->hdatRhbAddrRngEndAddr =
                    (l_occCommonAddr | VmmManager::FORCE_PHYS_ADDR)
                        + VMM_OCC_COMMON_SIZE - 1 ;
            l_rngPtr->hdatRhbLabelSize = l_labelSize;
            memcpy( l_rngPtr->hdatRhbLabelString,
                    l_label,
                    l_labelSize );

            traceHbRsvMemRange(l_rngPtr);
#endif
        }


        // VPD entry
        uint64_t l_vpdAddr = 0x0;
        l_label = "ibm,hbrt-vpd-image";
        l_labelSize = strlen(l_label) + 1;

        if(TARGETING::is_phyp_load())
        {
            l_vpdAddr = cpu_spr_value(CPU_SPR_HRMOR)
                    + VMM_VPD_START_OFFSET;
        }
        else if(TARGETING::is_sapphire_load())
        {
            // @todo RTC 170298 Reduce space allocated for VPD at runtime
            l_vpdAddr = l_topMemAddr
                    - VMM_RT_VPD_OFFSET;
        }

        // Get a pointer to the next available HDAT HB Rsv Mem entry
        l_rngPtr = nullptr;
        l_elog = getNextRhbAddrRange(l_rngPtr);
        if(l_elog)
        {
            break;
        }

        // Fill in the entry
        l_rngPtr->hdatRhbRngType =
                static_cast<uint8_t>(RANGE_TYPE_HBRT);
        l_rngPtr->hdatRhbRngId = i_nodeId;
        l_rngPtr->hdatRhbAddrRngStrAddr =
                l_vpdAddr | VmmManager::FORCE_PHYS_ADDR;
        l_rngPtr->hdatRhbAddrRngEndAddr =
                (l_vpdAddr | VmmManager::FORCE_PHYS_ADDR)
                    + VMM_RT_VPD_SIZE - 1 ;
        l_rngPtr->hdatRhbLabelSize = l_labelSize;
        memcpy( l_rngPtr->hdatRhbLabelString,
                l_label,
                l_labelSize );

        traceHbRsvMemRange(l_rngPtr);

        // Load the VPD into memory
        l_elog = mapPhysAddr(l_vpdAddr, VMM_RT_VPD_SIZE, l_vAddr);
        if(l_elog)
        {
            break;
        }

        l_elog = VPD::vpd_load_rt_image(l_vAddr);
        if(l_elog)
        {
            TRACFCOMP( g_trac_runtime,
                       "populate_HbRsvMem fail VPD call" );
            break;
        }

        l_elog = unmapVirtAddr(l_vAddr);
        if(l_elog)
        {
            break;
        }


        // ATTR Data entry
        uint64_t l_attrDataAddr = 0x0;
        l_label = "ibm,hbrt-target-image";
        l_labelSize = strlen(l_label) + 1;
        uint64_t l_attrSize = TARGETING::AttrRP::maxSize();

        if(TARGETING::is_phyp_load())
        {
            l_attrDataAddr = l_vpdAddr + VMM_RT_VPD_SIZE;
            l_attrDataAddr = ALIGN_X(l_attrDataAddr,64*KILOBYTE);
        }
        else if(TARGETING::is_sapphire_load())
        {
            l_attrDataAddr = l_vpdAddr - l_attrSize;
            l_attrDataAddr = ALIGN_DOWN_X(l_attrDataAddr,64*KILOBYTE);
        }

        // Get a pointer to the next available HDAT HB Rsv Mem entry
        l_rngPtr = nullptr;
        l_elog = getNextRhbAddrRange(l_rngPtr);
        if(l_elog)
        {
            break;
        }

        // Fill in the entry
        l_rngPtr->hdatRhbRngType =
                static_cast<uint8_t>(RANGE_TYPE_HBRT);
        l_rngPtr->hdatRhbRngId = i_nodeId;
        l_rngPtr->hdatRhbAddrRngStrAddr =
                l_attrDataAddr | VmmManager::FORCE_PHYS_ADDR;
        l_rngPtr->hdatRhbAddrRngEndAddr =
                (l_attrDataAddr | VmmManager::FORCE_PHYS_ADDR)
                    + l_attrSize - 1 ;
        l_rngPtr->hdatRhbLabelSize = l_labelSize;
        memcpy( l_rngPtr->hdatRhbLabelString,
                l_label,
                l_labelSize );

        traceHbRsvMemRange(l_rngPtr);

        // Load the attribute data into memory
        l_elog = mapPhysAddr(l_attrDataAddr, l_attrSize, l_vAddr);
        if(l_elog)
        {
            break;
        }

        TARGETING::AttrRP::save(l_vAddr);

        l_elog = unmapVirtAddr(l_vAddr);
        if(l_elog)
        {
            break;
        }


        // HBRT image entry
        if(TARGETING::is_sapphire_load() &&
                (!INITSERVICE::spBaseServicesEnabled()))
        {
            uint64_t l_hbrtImageAddr = 0x0;
            l_label = "ibm,hbrt-code-image";
            l_labelSize = strlen(l_label) + 1;

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

            // Set the image address, align down 64K for Opal
            l_hbrtImageAddr = ALIGN_PAGE_DOWN(l_attrDataAddr - l_imageSize);
            l_hbrtImageAddr = ALIGN_DOWN_X(l_hbrtImageAddr,64*KILOBYTE);

            // Get a pointer to the next available HDAT HB Rsv Mem entry
            l_rngPtr = nullptr;
            l_elog = getNextRhbAddrRange(l_rngPtr);
            if(l_elog)
            {
                break;
            }

            // Fill in the entry
            l_rngPtr->hdatRhbRngType =
                    static_cast<uint8_t>(RANGE_TYPE_HBRT);
            l_rngPtr->hdatRhbRngId = i_nodeId;
            l_rngPtr->hdatRhbAddrRngStrAddr =
                    l_hbrtImageAddr | VmmManager::FORCE_PHYS_ADDR;
            l_rngPtr->hdatRhbAddrRngEndAddr =
                    (l_hbrtImageAddr | VmmManager::FORCE_PHYS_ADDR)
                        + l_imageSize - 1 ;
            l_rngPtr->hdatRhbLabelSize = l_labelSize;
            memcpy( l_rngPtr->hdatRhbLabelString,
                    l_label,
                    l_labelSize );

            traceHbRsvMemRange(l_rngPtr);

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

    } while(0);

    return(l_elog);
} // end populate_HbRsvMem


errlHndl_t populate_hbSecurebootData ( void )
{
    using namespace TARGETING;

    errlHndl_t l_elog = nullptr;

    do {

    const uint64_t l_instance = 0; // pass 0 since sys parms has only one record
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
        uint16_t reserved : 14;
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

    // populate TPM config bits in hdat
    bool tpmRequired = false;
    #ifdef CONFIG_TPMDD
        tpmRequired = TRUSTEDBOOT::isTpmRequired();
    #endif

    l_sysParmsPtr->hdatTpmConfBits = tpmRequired? TPM_REQUIRED_BIT: 0;

    // get max # of TPMs per drawer and populate hdat with it
    auto l_maxTpms = HDAT::hdatTpmDataCalcMaxSize();

    l_sysParmsPtr->hdatTpmDrawer = l_maxTpms;
    TRACFCOMP(g_trac_runtime,"Max TPMs = 0x%04X", l_maxTpms);

    // populate hw key hash in hdat
    #ifdef CONFIG_SECUREBOOT
    auto hash = l_sysParmsPtr->hdatHwKeyHashValue;
    SECUREBOOT::getHwKeyHash(hash);
    #else
    memset(l_sysParmsPtr->hdatHwKeyHashValue,0,
                                 sizeof(l_sysParmsPtr->hdatHwKeyHashValue));
    #endif

    } while(0);

    return (l_elog);
} // end populate_hbRuntime

errlHndl_t populate_TpmInfoByNode()
{
    errlHndl_t l_elog = nullptr;

    do {

    uint64_t l_baseAddr = 0;
    uint64_t l_dataSizeMax = 0;
    const uint64_t l_instance = 0; // pass 0 since there is only one record

    // TODO RTC 167290 - We will need to pass the appropriate instance value
    // when we implement multinode support

    l_elog = RUNTIME::get_host_data_section(RUNTIME::NODE_TPM_RELATED,
                                                l_instance,
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

    auto const l_hdatTpmData
                    = reinterpret_cast<HDAT::hdatTpmData_t*>(l_baseAddr);

    // make sure we have enough room
    auto const l_tpmDataCalculatedMax = HDAT::hdatTpmDataCalcMaxSize();
    assert(l_dataSizeMax >= l_tpmDataCalculatedMax,
        "Bug! The TPM data hdat section doesn't have enough space");

    // check that hdat structure format and eye catch were filled out
    assert(l_hdatTpmData->hdatHdr.hdatStructId == HDAT::HDAT_HDIF_STRUCT_ID,
        "Bug! The TPM data hdat struct format value doesn't match");

    auto l_eyeCatchLen = strlen(HDAT::g_hdatTpmDataEyeCatch);
    assert(memcmp(l_hdatTpmData->hdatHdr.hdatStructName,
                  HDAT::g_hdatTpmDataEyeCatch,
                  l_eyeCatchLen)==0,
        "Bug! The TPM data hdat struct name eye catcher doesn't match");

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

    // populate first part of pointer pair for secure boot TPM info
    l_hdatTpmData->hdatSbTpmInfo.hdatOffset = l_currOffset;

    // the second part of the pointer pair for secure boot TPM info will be
    // populated using the following start offset
    auto l_sbTpmInfoStart = l_currOffset;

    auto const l_hdatSbTpmInfo = reinterpret_cast<HDAT::hdatSbTpmInfo_t*>
                                                    (l_baseAddr + l_currOffset);

    TARGETING::TargetHandleList tpmList;
    TRUSTEDBOOT::getTPMs(tpmList);

    TARGETING::TargetHandleList l_procList;

    getAllChips(l_procList,TARGETING::TYPE_PROC,false);

    auto const l_numTpms = tpmList.size();

    // fill in the values for the Secure Boot TPM Info Array Header
    l_hdatSbTpmInfo->hdatSbTpmArrayOffset = sizeof(*l_hdatSbTpmInfo);
    l_hdatSbTpmInfo->hdatSbTpmArrayNumEntries = l_numTpms;
    l_hdatSbTpmInfo->hdatSbTpmArrayEntrySize = sizeof(HDAT::hdatSbTpmInstInfo_t);

    // advance current offset to after the Secure Boot TPM info array header
    l_currOffset += sizeof(*l_hdatSbTpmInfo);

    // fill in the values for each Secure Boot TPM Instance Info in the array
    for (auto pTpm : tpmList)
    {
        auto l_tpmInstInfo = reinterpret_cast<HDAT::hdatSbTpmInstInfo_t*>
                                                    (l_baseAddr + l_currOffset);
        auto l_tpmInfo = pTpm->getAttr<TARGETING::ATTR_TPM_INFO>();

        TARGETING::PredicateAttrVal<TARGETING::ATTR_PHYS_PATH>
                                      hasSameI2cMaster(l_tpmInfo.i2cMasterPath);

        auto itr = std::find_if(l_procList.begin(),l_procList.end(),
        [&hasSameI2cMaster](const TARGETING::TargetHandle_t & t)
        {
            return hasSameI2cMaster(t);
        });

        assert(itr != l_procList.end(), "Bug! TPM must have a processor.");
        auto l_proc = *itr;

        l_tpmInstInfo->hdatChipId = l_proc->getAttr<TARGETING::ATTR_CHIP_ID>();

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

        // advance the current offset to account for this tpm instance info
        l_currOffset += sizeof(*l_tpmInstInfo);

        // use the current offset for the beginning of the SRTM event log
        l_tpmInstInfo->hdatTpmSrtmEventLogOffset = sizeof(*l_tpmInstInfo);

        // copy the contents of the SRTM event log into HDAT picking the
        // min of log size and log max (to make sure log size never goes
        // over the max)
        auto * const pLogMgr = TRUSTEDBOOT::getTpmLogMgr(pTpm);
        size_t logSize = 0;
        if(pLogMgr != nullptr)
        {
            #ifdef CONFIG_TPMDD
            auto const * const pLogStart =
                TRUSTEDBOOT::TpmLogMgr_getLogStartPtr(pLogMgr);
            assert(pLogStart != nullptr,"populate_TpmInfoByNode: BUG! An "
                "allocated log manager's log start pointer should never be "
                "nullptr");

            logSize = (pLogMgr->logSize < TPM_SRTM_EVENT_LOG_MAX) ?
                pLogMgr->logSize : TPM_SRTM_EVENT_LOG_MAX;

            memcpy(reinterpret_cast<void*>(l_baseAddr + l_currOffset),
                pLogStart,
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

    // populate second part of pointer pair for secure boot TPM info
    l_hdatTpmData->hdatSbTpmInfo.hdatSize = l_currOffset - l_sbTpmInfoStart;

    // the current offset now corresponds to the physical interaction mechanism
    // info array header
    auto l_physInter = reinterpret_cast<HDAT::hdatPhysInterMechInfo_t*>
                                                    (l_baseAddr + l_currOffset);

    // populate the first part of pointer pair from earlier to point here
    l_hdatTpmData->hdatPhysInter.hdatOffset = l_currOffset;

    // the following will be used to calculate the second part of pointer pair
    auto l_physInterStart = l_currOffset;

    // set up the physical interaction mechanism info header
    // @TODO RTC 170638: Calculate the real IDs
    l_physInter->i2cLinkIdWindowOpen = HDAT::I2C_LINK_ID::NOT_APPLICABLE;
    l_physInter->i2cLinkIdPhysicalPresence = HDAT::I2C_LINK_ID::NOT_APPLICABLE;

    // advance the current offset to account for the physical interaction
    // mechanism info struct
    l_currOffset =+ sizeof(*l_physInter);

    // populate the second part of the pointer pair from earlier
    l_hdatTpmData->hdatPhysInter.hdatSize = l_currOffset - l_physInterStart;

    // set the total structure length to the current offset
    l_hdatTpmData->hdatHdr.hdatSize = l_currOffset;

    } while (0);

    return (l_elog);
}

errlHndl_t populate_hbTpmInfo()
{
    errlHndl_t l_elog = nullptr;

    do {
        // TODO RTC 171851 Remove FSP restriction when FSP code provides
        // Node TPM Related Data

        // Skip populating HDAT TPM Node Related Data on FSP systems
        if (INITSERVICE::spBaseServicesEnabled())
        {
            break;
        }

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
            l_elog = populate_TpmInfoByNode();
            if(l_elog != nullptr)
            {
                TRACFCOMP( g_trac_runtime, "populate_hbTpmInfo: "
                    "populate_RtDataByNode failed" );
            }
            break;
        }

        // start the 1 in the mask at leftmost position
        decltype(hb_images) l_mask = 0x1 << (sizeof(hb_images)*BITS_PER_BYTE-1);

        // start at node 0
        uint32_t l_node = 0;

        // while the one in the mask hasn't shifted out
        while (l_mask)
        {
            // if this node is present
            if(l_mask & hb_images)
            {
                TRACFCOMP( g_trac_runtime, "populate_hbTpmInfo: "
                    "MsgToNode %d for HBRT TPM Info",
                           l_node );
                // @TODO RTC 167290
                // Need to send message to the current node
                // When node receives a message it should call
                // populate_TpmInfoByNode()
            }
            l_mask >>= 1; // shift to the right for the next node
            l_node++; // go to the next node
        }

    } while(0);

    return (l_elog);
} // end populate_hbTpmInfo



errlHndl_t populate_hbRuntimeData( void )
{
    errlHndl_t  l_elog = nullptr;

    do {
        TRACFCOMP(g_trac_runtime, "Running populate_hbRuntimeData");

        TARGETING::Target * sys = nullptr;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != nullptr);

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
            sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        // Figure out which node we are running on
        TARGETING::Target* mproc = nullptr;
        TARGETING::targetService().masterProcChipTargetHandle(mproc);

        TARGETING::EntityPath epath =
            mproc->getAttr<TARGETING::ATTR_PHYS_PATH>();

        const TARGETING::EntityPath::PathElement pe =
            epath.pathElementOfType(TARGETING::TYPE_NODE);

        uint64_t nodeid = pe.instance;

        // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
        // Currently set up in host_sys_fab_iovalid_processing() which only
        // gets called if there are multiple physical nodes.   It eventually
        // needs to be setup by a hb routine that snoops for multiple nodes.
        if (0 == hb_images)  //Single-node
        {
            // Single node system, call inline and pass in our node number
            l_elog = populate_RtDataByNode(nodeid);
            if(l_elog != nullptr)
            {
                TRACFCOMP( g_trac_runtime, "populate_RtDataByNode failed" );
            }
            // RTC 169478 - enable for PHYP when supported in FSP
            if(TARGETING::is_sapphire_load())
            {
                l_elog = populate_HbRsvMem(nodeid);
                if(l_elog != nullptr)
                {
                    TRACFCOMP( g_trac_runtime, "populate_HbRsvMem failed" );
                }
            }
            break;
        }

        // continue only for multi-node system

        // loop thru rest of NODES -- sending msg to each
        TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
          ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

        for (uint64_t l_node=0; (l_node < MAX_NODES_PER_SYS); l_node++ )
        {
            if( 0 != ((mask >> l_node) & hb_images ) )
            {
                // @TODO RTC 142908

                // Need to send message to the node (l_node)
                // When NODE receives the msg it should
                // call populate_RtDataByNode(itsNodeId)
                // call populate_HbRsvMem(itsNodeId)
                TRACFCOMP( g_trac_runtime, "MsgToNode %d for HBRT Data",
                           l_node );

            } // end if node to process
        } // end for loop on nodes

    } while(0);


    return(l_elog);

} // end populate_hbRuntimeData

} //namespace RUNTIME

