/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_scomoverride_chiplets.C $    */
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
   @file call_proc_scomoverride_chiplets.C
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

#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <errl/errlmanager.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>

#include <p9_scomoverride_chiplets.H>


namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//*****************************************************************************
// wrapper function to call proc_scomoverride_chiplets
//*****************************************************************************
void* call_proc_scomoverride_chiplets( void *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_scomoverride_chiplets entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    // Loop through all processors, including master
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (l_cpu_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_scomoverride_chiplets HWP on processor target %.8X",
                TARGETING::get_huid(l_cpu_target) );

        FAPI_INVOKE_HWP(l_errl, p9_scomoverride_chiplets, l_fapi2_proc_target);

        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X : proc_scomoverride_chiplets "
                     "HWP returns error",
                     l_errl->reasonCode() );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  proc_scomoverride_chiplets HWP" );
        }
    } // end of going through all processors

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_scomoverride_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};
