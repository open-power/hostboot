/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_proc_load_iop_xram.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
 *  @file  call_proc_load_iop_xram.C
 *  @brief Contains the wrapper for istep 14.3
 */
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <istepHelperFuncs.H> // captureError

//HWP Invoker
#include    <fapi2/plat_hwp_invoker.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include <fapi2/target.H>
#include <p10_load_iop_xram.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{

void* call_proc_load_iop_xram (void *io_pArgs)
{
    IStepError  l_stepError;

    errlHndl_t  l_errl  =   nullptr;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_load_iop_xram entry" );

    char* l_pHcodeImage = nullptr;
    // Load the reference image from PNOR
    bool l_hcodeLoaded = false;
    l_errl = loadHcodeImage(l_pHcodeImage, l_hcodeLoaded);
    if (l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                ERR_MRK"call_proc_load_iop_xram ERROR : errorlog "
                TRACE_ERR_FMT,
                TRACE_ERR_ARGS(l_errl));
        captureError(l_errl, l_stepError, HWPF_COMP_ID);
    }
    else
    {
        TargetHandleList l_procChips;
        getAllChips(l_procChips, TYPE_PROC );

        for (const auto & l_procChip: l_procChips)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi_cpu_target(l_procChip);
            //  write HUID of target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_proc_load_iop_xram target HUID %.8X", get_huid(l_procChip));

            //  call the HWP with each fapi::Target
            FAPI_INVOKE_HWP( l_errl, p10_load_iop_xram, l_fapi_cpu_target, l_pHcodeImage );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        ERR_MRK"ERROR : proc_load_iop_xram "
                        TRACE_ERR_FMT,
                        TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID);
                continue;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS : proc_load_iop_xram" );
            }
        }
    }

#ifdef CONFIG_SECUREBOOT
    // securely unload HCODE PNOR section, if necessary
    if (l_hcodeLoaded)
    {
        l_errl = unloadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"host_build_stop_image() - Error from "
                       "unloadSecureSection(PNOR::HCODE) "
                       TRACE_ERR_FMT,
                       TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID);
        }
    }
#endif


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_load_iop_xram exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
