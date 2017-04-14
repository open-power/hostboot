/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep21/call_host_runtime_setup.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <isteps/pm/pm_common_ext.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <vfs/vfs.H>
#include <htmgt/htmgt.H>
#include <runtime/runtime.H>
#include <runtime/customize_attrs_for_payload.H>
#include <targeting/common/util.H>
#include <vpd/vpd_if.H>
#include <util/utiltce.H>

//SBE interfacing
#include    <sbeio/sbeioif.H>
#include    <sys/misc.h>

#include <hbotcompid.H>

#include <occ/occ_common.H>
#include <occ/occAccess.H>

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
            uint8_t l_fabricChipId =
                            l_proc->getAttr<TARGETING::ATTR_FABRIC_CHIP_ID>();
            uint8_t l_fabricGroupId =
                            l_proc->getAttr<TARGETING::ATTR_FABRIC_GROUP_ID>();
            //Calculate what bit position this will be
            uint8_t l_bitPos = l_fabricChipId + (8 * l_fabricGroupId);

            //Set the bit @ l_bitPos to be 1 because this is a functional proc
            l_systemFabricConfigurationMap |= (0x8000000000000000 >> l_bitPos);
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Setting sending systemConfig to all Procs...");

        for(auto l_proc : l_procChips)
        {
            TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "calling sendSystemConfig on proc 0x%x",
                       l_proc->getAttr<TARGETING::ATTR_POSITION>());
            l_err = SBEIO::sendSystemConfig(l_systemFabricConfigurationMap,
                                            l_proc);
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "sendSystemConfig ERROR : Error sending sbe chip-op to proc 0x%.8X. Returning errorlog, reason=0x%x",
                            TARGETING::get_huid(l_proc),
                            l_err->reasonCode() );
                break;
            }
            else
            {
                TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "sendSystemConfig SUCCESS"  );
            }
        }

        if(l_err)
        {
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Successfully sent all system configs to procs via SBE chip op !!");
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

        // Fill in Hostboot runtime data if there is a PAYLOAD
        if( !(TARGETING::is_no_load()) )
        {
            // API call to fix up the secureboot fields
            l_err = RUNTIME::populate_hbSecurebootData();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Failed hbSecurebootData setup" );
                break;
            }

            // API call to populate the TPM Info fields
            l_err = RUNTIME::populate_hbTpmInfo();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Failed hbTpmInfo setup" );
                break;
            }

            // Fill in Hostboot runtime data for all nodes
            // (adjunct partition)
            // Write the HB runtime data into mainstore
            l_err = RUNTIME::populate_hbRuntimeData();
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Failed hbRuntimeData setup" );
                // break from do loop if error occured
                break;
            }
        }

#ifdef CONFIG_START_OCC_DURING_BOOT
        bool l_activatePM = !(TARGETING::is_phyp_load());
#else
        bool l_activatePM = false;
#endif

        if(l_activatePM)
        {
            TARGETING::Target* l_failTarget = NULL;
            bool pmStartSuccess = true;

            l_err = loadAndStartPMAll(HBPM::PM_LOAD, l_failTarget);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "loadAndStartPMAll failed");

                // Commit the error and continue with the istep
                errlCommit(l_err, ISTEP_COMP_ID);
                pmStartSuccess = false;
            }

#ifdef CONFIG_HTMGT
            // Report PM status to HTMGT
            HTMGT::processOccStartStatus(pmStartSuccess,l_failTarget);
#else
            // Verify all OCCs have reached the checkpoint
            if (pmStartSuccess)
            {
                l_err = HBPM::verifyOccChkptAll();
                if (l_err)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "verifyOccCheckpointAll failed");

                    // Commit the error and continue with the istep
                    errlCommit(l_err, ISTEP_COMP_ID);
                }
            }
#endif
        }

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
        if(TARGETING::is_phyp_load() )
        {
            //Explicity clearing the SRAM flag before starting Payload.
            //This tells the OCC bootloader where to pull the OCC image from
            //0: mainstore, 1: SRAM. We want to use mainstore after this point

            //Get master proc
            TargetService & tS = targetService();
            TARGETING::Target* masterproc = NULL;
            tS.masterProcChipTargetHandle( masterproc );

            //Clear (up to and including the IPL flag)
            const uint32_t l_SramAddrApp = HBOCC::OCC_SRAM_ADDRESS;
            ecmdDataBufferBase l_occAppData((HBOCC::OCC_OFFSET_IPL_FLAG + 6)
                                                * 8 /* bits */);
            l_err = HBOCC::writeSRAM(masterproc, l_SramAddrApp, l_occAppData);
            if(l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                "Error in writeSRAM of 0");
                break;
            }
        }
#endif


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
            //@fixme-RTC:172836-broken for HDAT mode?
            // Update the VPD switches for golden side boot
            // Must do this before building the devtree
            l_err = VPD::goldenSwitchUpdate();
            if ( l_err )
            {
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

        // Close PAYLOAD TCEs
/*      @TODO RTC 168745 - make this call when FSP is ready for TCE Support
 *                         and add check that we're on a FSP system
 *      NOTE:  move this call to the start of this function
 *      NOTE:  add check to do this only on FSP-based systems
 *        l_err = TCE::utilClosePayloadTces();
 *       if ( l_err )
 *       {
 *           TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
 *                      "Failed TCE::utilClosePayloadTces" );
 *           // break from do loop if error occured
 *           break;
 *       }
 *
 *
 *       // Disable all TCEs
 *       l_err = TCE::utilDisableTces();
 *       if ( l_err )
 *       {
 *           TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
 *                      "Failed TCE::utilDisableTces" );
 *           // break from do loop if error occured
 *           break;
 *       }
 */

    } while(0);

    if( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "istep host_runtime_setup failed see plid 0x%x", l_err->plid());

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
