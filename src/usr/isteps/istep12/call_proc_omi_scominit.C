/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_proc_omi_scominit.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2024                        */
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
 * @file    call_proc_omi_scominit.C
 *
 *  Contains wrappers for Istep 12.3
 *      p10_omi_scominit
 *      p10_omi_setup_bars
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

// HWP
#include <p10_omi_setup_bars.H>
#include <p10_omi_scominit.H>

#include    <mmio/mmio.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   TARGETING::UTIL;


namespace ISTEP_12
{
void* call_proc_omi_scominit (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    do
    {

    if (assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "call_proc_omi_scominit entry. Skipping HWPs for MPIPL.");

        break;
    }

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_omi_scominit "
        "entry. %d procs found", l_procTargetList.size());

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK"p10_omi_scominit");

    for (const auto l_proc_target : l_procTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p10_omi_scominit HWP target HUID %.8x",
            TARGETING::get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p10_omi_scominit, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : call p10_omi_scominit HWP(): failed on target 0x%08X. "
                TRACE_ERR_FMT,
                get_huid(l_proc_target),
                TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, l_proc_target);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  p10_omi_scominit HWP");
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK"p10_omi_scominit");

    // 12.3.b p10_omi_setup_bars.C
    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK"p10_omi_setup_bars");

    for (const auto l_proc_target : l_procTargetList)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p10_omi_setup_bars HWP target HUID %.8x",
            TARGETING::get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p10_omi_setup_bars, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "ERROR : call p10_omi_setup_bars HWP(): failed on target 0x%08X. "
              TRACE_ERR_FMT,
              get_huid(l_proc_target),
              TRACE_ERR_ARGS(l_err));

            // Capture error
            captureError(l_err, l_StepError, HWPF_COMP_ID, l_proc_target);
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  p10_omi_setup_bars HWP");
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK"p10_omi_setup_bars");

    } while (false);

    // map OCMBs into Hostboot memory
    l_err = MMIO::mmioSetup();
    if ( l_err )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "ERROR : call mmioSetup() : unable to initialize MMIO! "
            TRACE_ERR_FMT,
            TRACE_ERR_ARGS(l_err));

        // Capture error
        captureError(l_err, l_StepError, ISTEP_COMP_ID);
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_omi_scominit exit");

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
