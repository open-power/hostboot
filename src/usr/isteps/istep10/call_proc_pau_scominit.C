/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_pau_scominit.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

//  Component ID support
#include <hbotcompid.H>                // HWPF_COMP_ID

//  TARGETING support
#include <attributeenums.H>            // TYPE_PROC

//  Error handling support
#include <isteps/hwpisteperror.H>      // ISTEP_ERROR::IStepError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

#include <istepHelperFuncs.H>          // captureError
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_pau_scominit.H>


namespace ISTEP_10
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//******************************************************************************
// Wrapper function to call proc_pau_scominit
//******************************************************************************
void* call_proc_pau_scominit( void *io_pArgs )
{
    errlHndl_t l_err(nullptr);
    IStepError l_stepError;
    TARGETING::TargetHandleList l_procTargetList;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_pau_scominit entry");

    //Get a list of all proc chips
    getAllChips(l_procTargetList, TYPE_PROC);

    // Loop through all proc chips, convert to fap2 target, and execute hwp
    for (const auto & curproc: l_procTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (curproc);

        // Call p10_pau_scominit hwp
        FAPI_INVOKE_HWP( l_err, p10_pau_scominit, l_fapi2_proc_target);

        if(l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR : call p10_pau_scominit HWP(): failed on target 0x%08X. "
                       TRACE_ERR_FMT,
                       get_huid(curproc),
                       TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_stepError, HWPF_COMP_ID, curproc);

            // Run HWP on all procs even if one reports an error
            continue;
        }
    } // for (const auto & curproc: l_procTargetList)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_pau_scominit exit");

    return l_stepError.getErrorHandle();
}
};   // end namespace ISTEP_10
