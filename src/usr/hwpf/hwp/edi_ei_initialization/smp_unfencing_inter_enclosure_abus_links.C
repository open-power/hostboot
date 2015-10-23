/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/edi_ei_initialization/smp_unfencing_inter_enclosure_abus_links.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <pbusLinkSvc.H>

//  Uncomment these files as they become available:
#include    "io_restore_erepair.H"
// #include    "fabric_io_dccal/fabric_io_dccal.H"
// #include    "fabric_erepair/fabric_erepair.H"
#include    "fabric_io_run_training/fabric_io_run_training.H"
#include    "io_pre_trainadv.H"
#include    "io_post_trainadv.H"
// #include    "host_startprd_pbus/host_startprd_pbus.H"
// #include    "host_attnlisten_proc/host_attnlisten_proc.H"
#include    "proc_fab_iovalid/proc_fab_iovalid.H"
#include    <diag/prdf/prdfMain.H>
#include    "fabric_io_dccal/fabric_io_dccal.H"

// eRepair Restore
#include <erepairAccessorHwpFuncs.H>

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    #include    <occ/occ_common.H>
#endif

namespace EDI_EI_INITIALIZATION
{
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
        assert(sys != NULL);

        TARGETING::ATTR_HB_EXISTING_IMAGE_type hb_images =
            sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();

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
/*
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "smp_unfencing_inter_enclosure_abus_links entry" );

    // Get all chip/chiplet targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    std::vector<proc_fab_iovalid_proc_chip> l_smp;

    for (TargetHandleList::const_iterator l_cpu_iter = l_cpuTargetList.begin();
         l_cpu_iter != l_cpuTargetList.end();
         ++l_cpu_iter)
    {
        proc_fab_iovalid_proc_chip l_procEntry;

        TARGETING::TargetHandle_t l_pTarget = *l_cpu_iter;
        fapi::Target l_fapiproc_target(TARGET_TYPE_PROC_CHIP, l_pTarget);

        l_procEntry.this_chip = l_fapiproc_target;
        l_procEntry.a0 = false;
        l_procEntry.a1 = false;
        l_procEntry.a2 = false;
        l_procEntry.x0 = false;
        l_procEntry.x1 = false;
        l_procEntry.x2 = false;
        l_procEntry.x3 = false;

        TARGETING::TargetHandleList l_abuses;
        getChildChiplets( l_abuses, l_pTarget, TYPE_ABUS );
        bool l_flag = false;
        for (TargetHandleList::const_iterator l_abus_iter = l_abuses.begin();
            l_abus_iter != l_abuses.end();
            ++l_abus_iter)
        {
            TARGETING::TargetHandle_t l_pAbusTarget = *l_abus_iter;
            ATTR_CHIP_UNIT_type l_srcID;
            l_srcID = l_pAbusTarget->getAttr<ATTR_CHIP_UNIT>();
            l_flag = isPeerPresent(l_pAbusTarget);
            switch (l_srcID)
            {
                case 0: l_procEntry.a0 = l_flag; break;
                case 1: l_procEntry.a1 = l_flag; break;
                case 2: l_procEntry.a2 = l_flag; break;
               default: break;
            }
        }

        l_smp.push_back(l_procEntry);
    }

    FAPI_INVOKE_HWP( l_errl, proc_fab_iovalid, l_smp, true );

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "%s : proc_fab_iovalid HWP.",
                (l_errl ? "ERROR" : "SUCCESS"));

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "smp_unfencing_inter_enclosure_abus_links exit" );
*/
    return l_errl;
}
};
