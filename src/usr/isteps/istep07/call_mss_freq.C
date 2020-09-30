/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_freq.C $                      */
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
 *  @file call_mss_freq.C
 *  Contains the wrapper for istep 7.3
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlentry.H>
#include <errl/errludtarget.H>
#include    <targeting/targplatutil.H> //assertGetToplevelTarget

// SBE
#include    <sbeif.H>

// HWP
#include    <p10_mss_freq.H>
#include    <p10_mss_freq_system.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//
//  Wrapper function to call mss_freq
//
void*    call_mss_freq( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq entry" );

    do
    {
        TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);
        
        for (const auto & l_proc_target : l_procTargetList)
        {
            //  call the HWP on each processor
            fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target(l_proc_target);
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "call_mss_freq: p10_mss_freq HWP target HUID 0x%.08X",
                get_huid(l_proc_target));

            FAPI_INVOKE_HWP(l_err, p10_mss_freq, l_fapi_proc_target);

            //  process return code.
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_freq: ERROR in p10_mss_freq HWP on target 0x%.08x. "
                    TRACE_ERR_FMT,
                    get_huid(l_proc_target),
                    TRACE_ERR_ARGS(l_err));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_err );

                // Commit Error, but continue to next mem_port
                l_err->collectTrace("ISTEPS_TRACE");
                errlCommit( l_err, ISTEP_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_mss_freq: p10_mss_freq HWP succeeded on target 0x%.08X",
                      get_huid(l_proc_target));
            }
        }

        if(l_StepError.getErrorHandle() != nullptr)
        {
            // If we have encountered an error, bail out now
            break;
        }

        for (const auto & l_proc_target : l_procTargetList)
        {
            //  call the HWP on each processor
            fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target(l_proc_target);
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_freq: running p10_mss_freq_system HWP on target 0x%.08X",
                    get_huid(l_proc_target));

            FAPI_INVOKE_HWP(l_err, p10_mss_freq_system, l_fapi_proc_target);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_freq: p10_mss_freq_system failed "
                    "on proc target 0x%.08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_proc_target),
                    TRACE_ERR_ARGS(l_err));

                ERRORLOG::ErrlUserDetailsTarget(l_proc_target).addToLog(l_err);

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails(l_err);

                // Commit Error, but continue to next processor target
                l_err->collectTrace("ISTEPS_TRACE");
                errlCommit(l_err, ISTEP_COMP_ID);
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_mss_freq: p10_mss_freq_system succeeded on target 0x%.08X",
                    get_huid(l_proc_target));
            }
        }

        if(l_StepError.getErrorHandle() != nullptr)
        {
            // If we have encountered an error, bail out now
            break;
        }

    } while(0);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_freq exit");

    return l_StepError.getErrorHandle();
}

};   // end namespace
