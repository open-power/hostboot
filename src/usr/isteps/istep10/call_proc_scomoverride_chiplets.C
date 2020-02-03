/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_scomoverride_chiplets.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
 *  @file call_proc_scomoverride_chiplets.C
 *
 *  Support file for IStep: call_proc_scomoverride_chiplets
 *       Apply any sequence driven scom overrides to chiplets
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

#include    <istepHelperFuncs.H>          // captureError
#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <errl/errlmanager.H>
#include    <p10_scomoverride_chiplets.H>


namespace   ISTEP_10
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
    errlHndl_t l_err(nullptr);
    IStepError l_stepError;
    TARGETING::TargetHandleList l_procTargetList;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_scomoverride_chiplets entry" );

    // Get a list of all proc chips
    getAllChips(l_procTargetList, TYPE_PROC);

    // Loop through all proc chips, convert to fap2 target, and execute hwp
    for (const auto & curproc : l_procTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (curproc);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Running p10_scomoverride_chiplets HWP on processor target %.8X",
               TARGETING::get_huid(curproc) );

        FAPI_INVOKE_HWP(l_err, p10_scomoverride_chiplets, l_fapi2_proc_target);

        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR : call p10_scomoverride_chiplets HWP(): failed on target 0x%08X. "
                           TRACE_ERR_FMT,
                           get_huid(curproc),
                           TRACE_ERR_ARGS(l_err));

            // Capture Error
            captureError(l_err, l_stepError, HWPF_COMP_ID, curproc);

            // Run HWP on all procs even if one reports an error
            continue;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  proc_scomoverride_chiplets HWP" );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_scomoverride_chiplets exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}
};
