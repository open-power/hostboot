/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_ipl_complete.C $             */
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

#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

#include    <initservice/initserviceif.H>
#include    <initservice/istepdispatcherif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/namedtarget.H>


using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;


namespace ISTEP_16
{
void* call_host_ipl_complete (void *io_pArgs)
{
    errlHndl_t  l_err  =   NULL;

    IStepError  l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete entry" );
    do
    {
#if 0
        // We only need to run cfsim on the master Processor.
        TARGETING::Target * l_masterProc =   NULL;
        (void)TARGETING::targetService().
            masterProcChipTargetHandle( l_masterProc );

        //@TODO RTC:133832
        //const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
        //        ( const_cast<TARGETING::Target*>(l_masterProc) ) );

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_switch_cfsim HWP on target HUID %.8X",
                TARGETING::get_huid(l_masterProc) );


        //  call proc_switch_cfsim
    // TODO: RTC 64136 - Comment out to work around Centaur FSI scom issue
    // during BU
    // RTC 64136 is opened to undo this when in-band scoms are available.
#if 0
        FAPI_INVOKE_HWP(l_err, proc_switch_cfsim, l_fapi_proc_target,
                        true, // RESET
                        true, // RESET_OPB_SWITCH
                        true, // FENCE_FSI0
                        true, // FENCE_PIB_NH
                        true, // FENCE_PIB_H
                        true, // FENCE_FSI1
                        true); // FENCE_PIB_SW1
#endif
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: proc_switch_cfsim HWP returned error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_masterProc).addToLog( l_err );

            // Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails( l_err );

            // commit errorlog
            errlCommit( l_err, HWPF_COMP_ID );

            //break to end because if proc_switch_cfsim fails
            //then FSP does not have FSI control again and system is toast
            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS: proc_switch_cfsim HWP( )" );
        }


        if ( INITSERVICE::spBaseServicesEnabled())
        {
            // For FSP based systems, do not route centaur
            // attentions through host after this step.
            // Loop through all the centaurs in the system
            // and run cen_switch_rec_attn
            TARGETING::TargetHandleList l_memTargetList;
            getAllChips(l_memTargetList, TYPE_MEMBUF );

            for ( TargetHandleList::iterator l_iter = l_memTargetList.begin();
                  l_iter != l_memTargetList.end();
                  ++l_iter )
            {
                TARGETING::Target * l_memChip  =   (*l_iter) ;

                //  dump physical path to target
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "Running cen_switch_rec_attn HWP on target HUID %.8X",
                         TARGETING::get_huid(l_memChip) );

                // @TODO RTC:133832 cast OUR type of target
                // to a FAPI type of target.
                /*
                fapi::Target l_fapi_centaur_target( TARGET_TYPE_MEMBUF_CHIP,
                                                    l_memChip );
                FAPI_INVOKE_HWP( l_err,
                                 cen_switch_rec_attn,
                                 l_fapi_centaur_target );
                                 */
                if (l_err)
                {
                    // log error for this centaur and continue

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR 0x%.8X: cen_switch_rec_attn HWP( )",
                              l_err->reasonCode() );

                    // Add all the details for this centaur
                    ErrlUserDetailsTarget myDetails(l_memChip);

                    // capture the target data in the elog
                    myDetails.addToLog(l_err);

                    // Create IStep error log and cross ref error that occurred
                    l_stepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS: cen_switch_rec_attn HWP( )" );
                }
            }   // endfor


            //  Loop through all the mcs in the system
            //  and run proc_switch_rec_attn
            TARGETING::TargetHandleList l_mcsTargetList;
            getAllChiplets(l_mcsTargetList, TYPE_MCS);

            for ( TargetHandleList::iterator l_iter = l_mcsTargetList.begin();
                l_iter != l_mcsTargetList.end();
                ++l_iter )
            {
                TARGETING::Target * l_mcsChiplet  =   (*l_iter) ;

                //  dump physical path to target
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "Running cen_switch_rec_attn HWP on target HUID %.8X",
                       TARGETING::get_huid(l_mcsChiplet) );

                //@TODO RTC:133832 cast OUR type of target
                //to a FAPI type of target.
                /*fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                                                l_mcsChiplet );

                FAPI_INVOKE_HWP( l_err,
                                 proc_switch_rec_attn,
                                 l_fapi_mcs_target );
                */
                if (l_err)
                {
                    // log error for this mcs and continue

                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "ERROR 0x%.8X: proc_switch_rec_attn HWP( )",
                              l_err->reasonCode() );

                    // Add all the details for this proc
                    ErrlUserDetailsTarget myDetails(l_mcsChiplet);

                    // capture the target data in the elog
                    myDetails.addToLog(l_err);

                    // Create IStep error log and cross ref error that occurred
                    l_stepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, HWPF_COMP_ID );
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               "SUCCESS: proc_switch_rec_attn HWP( )" );
                }

            }   //  endfor
        } // end if ( INITSERVICE::spBaseServicesEnabled())

#ifdef CONFIG_PCIE_HOTPLUG_CONTROLLER
        //  Loop through all the procs in the system
        //  and run proc_pcie_slot_power to  power on the hot plug controller
        //  for Sapphire systems. PowerVM will turn on the hot plug
        //  controller.
        if (is_sapphire_load())
        {

            //  get a list of all the procs in the system
            TARGETING::Target* l_pMasterProcTarget = NULL;
            TARGETING::targetService().
                       masterProcChipTargetHandle(l_pMasterProcTarget);
            TARGETING::TargetHandleList l_procTargetList;
            getAllChips(l_procTargetList, TYPE_PROC);

            for (TargetHandleList::const_iterator
                    l_proc_iter = l_procTargetList.begin();
                    l_proc_iter != l_procTargetList.end();
                    ++l_proc_iter)
            {
                //  make a local copy of the Processor target
                TARGETING::Target* l_pProcTarget = *l_proc_iter;

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X",
                    TARGETING::get_huid(l_pProcTarget));

                //@TODO RTC:133832
                /*
                fapi::Target l_fapiProcTarget( fapi::TARGET_TYPE_PROC_CHIP,
                                       l_pProcTarget    );

                // Invoke the HWP
                FAPI_INVOKE_HWP(l_err,
                        proc_pcie_slot_power,
                        l_fapiProcTarget,
                        true  );  // turn on
                */
                if (l_err)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : proc_pcie_hotplug_control",
                          " failed, returning errorlog" );

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_pProcTarget).addToLog( l_err );

                    // informational. Don't add to istep error or return error
                    l_err->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);

                    // Commit error log
                    errlCommit( l_err, HWPF_COMP_ID );
                }
                else
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS : proc_pcie_hotplug_control",
                      " completed ok");
                }
            }   // endfor
        }
#endif
#endif
        // Sync attributes to Fsp
        l_err = syncAllAttributesToFsp();

        if( l_err )
        {
            break;
        }

        // Send Sync Point to Fsp
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   INFO_MRK"Send SYNC_POINT_REACHED msg to Fsp" );
        l_err = INITSERVICE::sendSyncPoint();

    } while( 0 );

    if( l_err )
    {
        // collect and log any remaining errors

        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, HWPF_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_ipl_complete exit ");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}


};
