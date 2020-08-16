/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_chiplet_scominit.C $         */
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

//  Component ID support
#include <hbotcompid.H>                // HWPF_COMP_ID

//  TARGETING support
#include <attributeenums.H>            // TYPE_PROC

//  Error handling support
#include <isteps/hwpisteperror.H>      // ISTEP_ERROR::IStepError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

// Util TCE Support
#include <util/utiltce.H>              // TCE::utilUseTcesForDmas

#include <istepHelperFuncs.H>          // captureError
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <p10_chiplet_scominit.H>
#include <p10_psi_scominit.H>

namespace ISTEP_10
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//******************************************************************************
// Wrapper function to call proc_chiplet_scominit
//******************************************************************************
void* call_proc_chiplet_scominit( void *io_pArgs )
{
    errlHndl_t l_err(nullptr);
    IStepError l_stepError;
    TARGETING::TargetHandleList l_procTargetList;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_chiplet_scominit entry" );

    //Get a list of all proc chips
    getAllChips(l_procTargetList, TYPE_PROC);

    // Loop through all proc chips, convert to fap2 target, and execute hwp
    for (const auto & curproc: l_procTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (curproc);

        // Call p10_chiplet_scominit hwp
        FAPI_INVOKE_HWP( l_err, p10_chiplet_scominit,
                         l_fapi2_proc_target);

        if(l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR in p10_chiplet_scominit HWP(): failed on target 0x%.08X. "
                       TRACE_ERR_FMT,
                       get_huid(curproc),
                       TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_stepError, HWPF_COMP_ID, curproc);

            // Skip rest of functionality for this proc, but let others run.
            continue;
        }

        // Call p10_psi_scominit hwp
        FAPI_INVOKE_HWP( l_err, p10_psi_scominit, l_fapi2_proc_target);

        if(l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "ERROR in p10_psi_scominit HWP(): failed on target 0x%.08X. "
                       TRACE_ERR_FMT,
                       get_huid(curproc),
                       TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_stepError, HWPF_COMP_ID, curproc);

            // Skip rest of functionality for this proc, but let others run.
            continue;
        }
    } // for (const auto & curproc: l_procTargetList)

    // Enable TCEs with an empty TCE Table, if necessary
    // This will prevent the FSP from DMAing to system memory without
    // hostboot's knowledge
    if (l_stepError.isNull())
    {
        if ( TCE::utilUseTcesForDmas() )
        {
            l_err = TCE::utilEnableTcesWithoutTceTable();

            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           ERR_MRK"call_proc_chiplet_scominit: utilEnableTcesWithoutTceTable, returned ERROR"
                           TRACE_ERR_FMT,
                           TRACE_ERR_ARGS(l_err));

                // Capture error
                captureError(l_err, l_stepError, HWPF_COMP_ID);
            }
        }
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_chiplet_scominit exit" );

    return l_stepError.getErrorHandle();
}
};   // end namespace ISTEP_10
