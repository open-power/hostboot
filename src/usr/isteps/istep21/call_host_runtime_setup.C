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

        // Map the Host Data into the VMM if applicable
        l_err = RUNTIME::load_host_data();
        if( l_err )
        {
            break;
        }

        //@TODO RTC:133848
/*
        bool l_activateOCC = is_avp_load();

#ifdef CONFIG_START_OCC_DURING_BOOT
        l_activateOCC = true;
#endif
        if(l_activateOCC)
        {
            l_err = HBOCC::activateOCCs();
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "activateOCCs failed");
                break;
            }
        }
#ifdef CONFIG_SET_NOMINAL_PSTATE
        // Speed up processors.
        l_err = setMaxPstate();
        if (l_err)
        {
            l_err->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
            ERRORLOG::errlCommit(l_err, ISTEP_COMP_ID);
        }
#endif

        if( is_sapphire_load() && (!INITSERVICE::spBaseServicesEnabled()) )
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
        else if( is_sapphire_load() )
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
        else if( is_phyp_load() )
        {
            //If PHYP then clear out the PORE BARs
            l_err = clearPoreBars();
            if( l_err )
            {
                break;
            }

            //Update the MDRT value (for MS Dump)
            l_err = RUNTIME::writeActualCount(RUNTIME::MS_DUMP_RESULTS_TBL);
            if(l_err != NULL)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "write_MDRT_Count failed" );
                break;
            }

            // Write the HostServices attributes into mainstore
            l_err = RUNTIME::populate_attributes();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not populate attributes" );
                // break from do loop if error occured
                break;
            }
        }
        else if( !is_avp_load() )
        {
            // Write the HostServices attributes into mainstore
            //  for our testcases
            l_err = RUNTIME::populate_attributes();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Could not populate attributes" );
                // break from do loop if error occured
                break;
            }
        }

        // Revert back to standard runtime mode where core checkstops
        //  do not escalate to system checkstops
        // Workaround for HW286670
        l_err = enableCoreCheckstops();
        if ( l_err )
        {
            break;
        }

        //  - Update HDAT/DEVTREE with tpmd logs
*/
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
