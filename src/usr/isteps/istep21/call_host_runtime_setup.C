/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_runtime_setup.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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

#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <initservice/isteps_trace.H>
#include <isteps/hwpisteperror.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <vfs/vfs.H>
#include <runtime/runtime.H>
#include <devtree/devtreeif.H>
#include <runtime/customize_attrs_for_payload.H>
#include <targeting/common/util.H>
#include <vpd/vpd_if.H>

//SBE interfacing
#include    <sbeio/sbeioif.H>
#include    <sys/misc.h>

#include <hbotcompid.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;

namespace ISTEP_21
{
void* call_host_runtime_setup (void *io_pArgs)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup entry" );

    errlHndl_t l_err = NULL;

    IStepError l_StepError;

    // Need to wait here until Fsp tells us go
    INITSERVICE::waitForSyncPoint();

    do
    {
        //Need to send System Configuration down to SBE
        //Use targeting code to get a list of all processors
        TARGETING::TargetHandleList l_procChips;
        getAllChips( l_procChips, TARGETING::TYPE_PROC , true);
        uint64_t l_systemFabricConfigurationMap = 0x0;


        for(auto l_proc : l_procChips)
        {
            //Get fabric info from proc
            uint8_t l_fabricChipId = l_proc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
            uint8_t l_fabricGroupId = l_proc->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
            //Calculate what bit position this will be
            uint8_t l_bitPos = l_fabricChipId + (8 * l_fabricGroupId);

            //Set the bit @ l_bitPos to be 1 because this is a functional proc
            l_systemFabricConfigurationMap |= (0x8000000000000000 >> l_bitPos);
        }

        l_err = SBEIO::sendSystemConfig(l_systemFabricConfigurationMap);
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "sendSystemConfig ERROR : Returning errorlog, reason=0x%x",
                    l_err->reasonCode() );
                    break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "sendSystemConfig SUCCESS"  );
        }



        // Need to load up the runtime module if it isn't already loaded
        if (  !VFS::module_is_loaded( "libruntime.so" ) )
        {
            l_err = VFS::module_load( "libruntime.so" );

            if ( l_err )
            {
                //  load module returned with errl set
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Could not load runtime module" );
                // break from do loop if error occured
                break;
            }
        }

        // Configure the ATTR_HBRT_HYP_ID attributes so that runtime code and
        // whichever hypervisor is loaded can reference equivalent targets
        l_err = RUNTIME::configureHbrtHypIds(TARGETING::is_phyp_load());
        if(l_err)
        {
            break;
        }

        // Map the Host Data into the VMM if applicable
        l_err = RUNTIME::load_host_data();
        if( l_err )
        {
            break;
        }

        // Fill in Hostboot runtime data for all nodes
        // (adjunct partition)
        if( TARGETING::is_phyp_load() )
        {
            // Write the HB runtime data into mainstore
            l_err = RUNTIME::populate_hbRuntimeData();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed hbRuntimeData setup" );
                // break from do loop if error occured
                break;
            }

        } // end if phyp load


        bool l_activateOCC = TARGETING::is_avp_load();

#ifdef CONFIG_START_OCC_DURING_BOOT
        l_activateOCC = true;
#endif
        if(l_activateOCC)
        {
#if 0 //@TODO-RTC:159931-Start OCC during boot
            l_err = HBOCC::activateOCCs();
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "activateOCCs failed");
                break;
            }
#endif
        }

#if 0 //@TODO-RTC:164022-Support max pstate without OCC
#ifdef CONFIG_SET_NOMINAL_PSTATE
        // Speed up processors.
        l_err = setMaxPstate();
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        }
#endif
#endif

        if( TARGETING::is_sapphire_load()
            && (!INITSERVICE::spBaseServicesEnabled()) )
        {
            // Update the VPD switches for golden side boot
            // Must do this before building the devtree
            l_err = VPD::goldenSwitchUpdate();
            if ( l_err )
            {
                break;
            }

            // Write the devtree out in Sapphire mode when SP Base Services not
            // enabled
            l_err = DEVTREE::build_flatdevtree();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not build dev tree" );
                // break from do loop if error occured
                break;
            }

            // Invalidate the VPD cache for golden side boot
            // Also invalidate in manufacturing mode
            // Must do this after building the devtree
            l_err = VPD::goldenCacheInvalidate();
            if ( l_err )
            {
                break;
            }

        }
        else if( TARGETING::is_sapphire_load() )
        {
            // Find area in HDAT to load devtree.
            uint64_t l_dtAddr = 0;
            size_t l_dtSize = 0;
            l_err = RUNTIME::get_host_data_section(RUNTIME::HSVC_SYSTEM_DATA,
                                                   0, l_dtAddr, l_dtSize);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not find system data area for Devtree.");
                break;
            }

            l_err = DEVTREE::build_flatdevtree(l_dtAddr, l_dtSize, true);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed to build small dev-tree for HDAT.");
                break;
            }

        }
        else if( TARGETING::is_phyp_load() )
        {
            //Update the MDRT value (for MS Dump)
            l_err = RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
            if(l_err != NULL)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "write_MDRT_Count failed" );
                break;
            }
        }

#if 0 //@TODO-RTC:147565-Core checkstop escalation
        // Revert back to standard runtime mode where core checkstops
        //  do not escalate to system checkstops
        // Workaround for HW286670
        l_err = enableCoreCheckstops();
        if ( l_err )
        {
            break;
        }
#endif

    } while(0);

    if( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep start_payload_failed see plid 0x%x", l_err->plid());

        // Create IStep error log and cross reference error that occurred
        l_StepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit(l_err, ISTEP_COMP_ID);

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_runtime_setup exit" );

    return l_StepError.getErrorHandle();
}


};
