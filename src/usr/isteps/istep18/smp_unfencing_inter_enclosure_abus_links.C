/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/smp_unfencing_inter_enclosure_abus_links.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2018                        */
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


/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//HWP
#include    <p9_fab_iovalid.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

//  fapi support
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <isteps/hwpf_reasoncodes.H>
#include    <isteps/hwpisteperror.H>
#include <config.h>
#include <vector>
#include "smp_unfencing_inter_enclosure_abus_links.H"

namespace   EDI_EI_INITIALIZATION
{


    using   namespace   ISTEP;
    using   namespace   ISTEP_ERROR;
    using   namespace   ERRORLOG;
    using   namespace   TARGETING;
    using   namespace   fapi;
    using   namespace   HWAS;



    /*
     *
     * brief function to check if peer target is present.
     *
     * returns true if peer is present, else false
     *
     */
    bool isPeerPresent(TARGETING::TargetHandle_t i_targetPtr)
    {
        bool l_flag = false;

        do
        {
            if( NULL == i_targetPtr)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "isPeerPresent:ERR: Null input target");
                break;
            }

            EntityPath l_peerPath;
            bool l_exists = i_targetPtr->tryGetAttr<ATTR_PEER_PATH>(l_peerPath);

            if( false == l_exists)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "isPeerPresent:ERR: Failed to get ATTR_PEER_PATH for "
                          "target HUID:0x%08x", get_huid(i_targetPtr));
                break;
            }

            EntityPath::PathElement l_pa = l_peerPath.pathElementOfType(TYPE_NODE);

            if(l_pa.type == TYPE_NA)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "isPeerPresent:ERR: Cannot find Node into in peer path: "
                          "[%s],target HUID:0x%08x", l_peerPath.toString(),
                          get_huid(i_targetPtr));
                break;
            }

            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget( sys );
            assert(sys != NULL, "isPeerPresent system target is NULL");

            TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images;
            
            l_exists =
                sys->tryGetAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>(hb_images);
                
            if( false == l_exists )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "isPeerPresent:ERR: Failed to get "
                          "ATTR_HB_EXISTING_IMAGE "
                          "for system target. Input target HUID:0x%08x",
                          get_huid(i_targetPtr));
                break;
            }

            // ATTR_HB_EXISTING_IMAGE only gets set on a multi-drawer system.
            // Currently set up in host_sys_fab_iovalid_processing() which only
            // gets called if there are multiple physical nodes.   It eventually
            // needs to be setup by a hb routine that snoops for multiple nodes.
            if(hb_images == 0)
            {
                // Single node system
                break;
            }

            // continue - multi-node
            uint8_t node_map[8];
            l_exists =
            sys->tryGetAttr<TARGETING::ATTR_FABRIC_TO_PHYSICAL_NODE_MAP>(node_map);

            if( false == l_exists )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "isPeerPresent:ERR: Failed to get "
                          "ATTR_FABRIC_TO_PHYSICAL_NODE_MAP "
                          "for system target. Input target HUID:0x%08x",
                          get_huid(i_targetPtr));
                break;
            }

            if(l_pa.instance < (sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8))
            {
                // set mask
                TARGETING::ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
                          ((sizeof(TARGETING::ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

                if( 0 != ((mask >> l_pa.instance) & hb_images ) )
                {
                    l_flag = true;
                }
            }

        }while(0);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "isPeerPresent:[%d], HUID:0x%08x",l_flag,get_huid(i_targetPtr));

        return l_flag;
    }
    //
    //  function to unfence inter-enclosure abus links
    //
    errlHndl_t  smp_unfencing_inter_enclosure_abus_links()
    {
        errlHndl_t l_errl = NULL;

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "smp_unfencing_inter_enclosure_abus_links entry" );

        // Get all chip/chiplet targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);


        // Loop through all processors including master
        for (const auto & l_cpu_target: l_cpuTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2_proc_target(
                      l_cpu_target);

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_fab_iovalid HWP on processor target %.8X",
                     TARGETING::get_huid(l_cpu_target) );
            FAPI_INVOKE_HWP(l_errl, p9_fab_iovalid, l_fapi2_proc_target,
                            true, true, false);
            if(l_errl)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR 0x%.8X : p9_fab_iovalid "
                         "HWP returns error for HUID %.8X",
                         l_errl->reasonCode(),
                         TARGETING::get_huid(l_cpu_target) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

                errlCommit(l_errl, HWPF_COMP_ID);
                l_errl = NULL;
            }
        } // end of going through all processors//


        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "smp_unfencing_inter_enclosure_abus_links exit" );

        return l_errl;
    }

};   // end namespace
