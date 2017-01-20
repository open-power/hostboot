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


#include <sys/misc.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/entitypath.H>
#include <runtime/runtime_reasoncodes.H>
#include <runtime/runtime.H>
#include "hdatstructs.H"
#include <mbox/ipc_msg_types.H>
#include <sys/task.h>
#include <intr/interrupt.H>
#include <errl/errlmanager.H>
#include <sys/internode.h>
#include <vpd/vpd_if.H>
#include <targeting/attrrp.H>
#include <sys/mm.h>
#include <util/align.H>
#include <secureboot/trustedbootif.H>
#include <secureboot/service.H>
#include <config.h>


namespace RUNTIME
{

// used for populating the TPM required bit in HDAT
const uint16_t TPM_REQUIRED_BIT = 0x8000; //leftmost bit of uint16_t set to 1

trace_desc_t *g_trac_runtime = NULL;
TRAC_INIT(&g_trac_runtime, RUNTIME_COMP_NAME, KILOBYTE);

errlHndl_t populate_RtDataByNode(uint64_t iNodeId)
{
    errlHndl_t  l_elog = NULL;
    const char* l_stringLabels[] =
                     { "ibm,hbrt-vpd-image" ,
                       "ibm,hbrt-target-image" };

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
        if(l_elog != NULL)
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
        if(l_elog != NULL)
        {
            TRACFCOMP( g_trac_runtime,
                "populate_RtDataByNode fail getHostDataSection VPD data" );
            break;
        }

        // Put VPD data into the structure now
        l_elog = VPD::vpd_load_rt_image( l_hbrtDataAddr );
        if(l_elog != NULL)
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
        if(l_elog != NULL)
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
        if(l_elog != NULL)
        {
            TRACFCOMP( g_trac_runtime,
                "populate_RtDataByNode fail getHostDataSection ATTRIB data" );
            break;
        }

        // Get ATTRIBUTE data
        TARGETING::AttrRP::save(l_hbrtDataAddr);

        //Create a block map of memory so we can save a copy of the attribute
        //data incase we need to MPIPL
        //Account HRMOR (non 0 base addr)
        uint64_t    l_attr_data_addr =   cpu_spr_value(CPU_SPR_HRMOR)
                                       + MPIPL_ATTR_DATA_ADDR;
        uint64_t l_attrCopyVmemAddr =
        reinterpret_cast<uint64_t>(mm_block_map(
            reinterpret_cast<void*>(l_attr_data_addr),
            MPIPL_ATTR_VMM_SIZE ));

        //Make sure the address returned from the block map call is not NULL
        if(l_attrCopyVmemAddr != 0)
        {
            //The function save() for AttrRP saves then entire HBD data
            // section of PNOR to the provided vmm address
            void * l_region = TARGETING::AttrRP::save(l_attrCopyVmemAddr);

            //Make sure to unmap the virtual address because we won't need it anymore
            int l_rc = mm_block_unmap(reinterpret_cast<void*>(l_region));

            if(l_rc)
            {
                TRACFCOMP( g_trac_runtime,
                           "populate_RtDataByNode fail to unmap physical addr %p, virt addr %p",
                           reinterpret_cast<void*>(l_attr_data_addr),
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
                                       l_attr_data_addr,
                                       l_attrCopyVmemAddr,
                                       true);
            }
        }
        else
        {
            TRACFCOMP( g_trac_runtime,
                       "populate_RtDataByNode fail to map  physical addr %p, size %lx",
                       reinterpret_cast<void*>(l_attr_data_addr),
                       MPIPL_ATTR_VMM_SIZE );
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
                                   l_attr_data_addr,
                                   MPIPL_ATTR_VMM_SIZE,
                                   true);
        }
    } while(0);


    return(l_elog);
} // end populate_RtDataByNode


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
    #ifdef CONFIG_TRUSTEDBOOT
        tpmRequired = TRUSTEDBOOT::isTpmRequired();
    #endif

    l_sysParmsPtr->hdatTpmConfBits = tpmRequired? TPM_REQUIRED_BIT: 0;

    // find max # of TPMs per drawer and populate hdat with it

    // look for class ENC type NODE and class chip TPM to find TPMs
    TARGETING::TargetHandleList l_nodeEncList;

    getEncResources(l_nodeEncList, TYPE_NODE, UTIL_FILTER_ALL);

    uint16_t l_maxTpms = 0;

    // loop thru the nodes and check number of TPMs
    for (TargetHandleList::const_iterator
        l_node_iter = l_nodeEncList.begin();
        l_node_iter != l_nodeEncList.end();
        ++l_node_iter)
    {
        // for this Node, get a list of tpms
        TARGETING::TargetHandleList l_tpmChipList;

        getChildAffinityTargets ( l_tpmChipList, *l_node_iter,
                        TARGETING::CLASS_CHIP, TYPE_TPM, false );

        size_t l_numTpms = l_tpmChipList.size();

        if (l_numTpms > l_maxTpms)
        {
            l_maxTpms = static_cast<uint16_t>(l_numTpms);
        }
    }

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
} // end populate_hbRuntiome

errlHndl_t populate_hbRuntimeData( void )
{
    errlHndl_t  l_elog = NULL;

    do {
        TRACFCOMP(g_trac_runtime, "Running populate_hbRuntimeData");

        TARGETING::Target * sys = NULL;
        TARGETING::targetService().getTopLevelTarget( sys );
        assert(sys != NULL);

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
            sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

        // Figure out which node we are running on
        TARGETING::Target* mproc = NULL;
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
            if(l_elog != NULL)
            {
                TRACFCOMP( g_trac_runtime, "populate_RtDataByNode failed" );
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
                TRACFCOMP( g_trac_runtime, "MsgToNode %d for HBRT Data",
                           l_node );

            } // end if node to process
        } // end for loop on nodes

    } while(0);


    return(l_elog);

} // end populate_hbRuntimeData

} //namespace RUNTIME

