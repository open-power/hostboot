/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/runtime/populate_hbruntime.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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


namespace RUNTIME
{

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

    } while(0);


    return(l_elog);
} // end populate_RtDataByNode


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

