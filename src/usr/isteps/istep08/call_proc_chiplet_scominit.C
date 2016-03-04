/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_chiplet_scominit.C $         */
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
/**
   @file call_proc_chiplet_scominit.C
 *
 *  Support file for IStep: nest_chiplets
 *   Nest Chiplets
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>

//#include <p9_chiplet_scominit.H> //TODO-RTC:149687
#include <p9_psi_scominit.H>

namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//******************************************************************************
// wrapper function to call proc_chiplet_scominit
//******************************************************************************
void*    call_proc_chiplet_scominit( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                             "call_proc_chiplet_scominit entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Loop through all processors including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2_proc_target(
            l_cpu_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9_chiplet_scominit HWP on "
            "target HUID %.8X", TARGETING::get_huid(l_cpu_target));

        //TODO-RTC:149687
        //FAPI_INVOKE_HWP(l_err, p9_chiplet_scominit, l_fapi2_proc_target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : "
             "p9_chiplet_scominit HWP returns error.  target HUID %.8X",
                    l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

            ErrlUserDetailsTarget(l_cpu_target).addToLog( l_err );

            // Create IStep error log and cross ref to error that occurred
            l_StepError.addErrorDetails( l_err );
            // We want to continue to the next target instead of exiting,
            // Commit the error log and move on
            // Note: Error log should already be deleted and set to NULL
            // after committing
            errlCommit(l_err, HWPF_COMP_ID);
        }

        //call p9_psi_scominit
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "Running p9_psi_scominit HWP on "
            "target HUID %.8X", TARGETING::get_huid(l_cpu_target));
        FAPI_INVOKE_HWP(l_err,p9_psi_scominit, l_fapi2_proc_target);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : "
             "proc_psi_scominit HWP returns error.  target HUID %.8X",
                    l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

            ErrlUserDetailsTarget(l_cpu_target).addToLog( l_err );

            // Create IStep error log and cross ref to error that occurred
            l_StepError.addErrorDetails( l_err );

            // We want to continue to the next target instead of exiting,
            // Commit the error log and move on
            // Note: Error log should already be deleted and set to NULL
            // after committing
            errlCommit(l_err, HWPF_COMP_ID);
        }
    } // end of going through all processors

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                             "call_proc_chiplet_scominit exit" );

    return l_StepError.getErrorHandle();
}
};
