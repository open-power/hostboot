/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_io_run_training.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file    call_omi_io_run_training.C
 *
 *  Contains the HWP wrapper for Istep 12.7
 *      exp_omi_train
 *      p10_omi_train
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>        // captureError

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <exp_omi_train.H>
#include    <p10_omi_train.H>
#include    <chipids.H>                 // for EXPLORER ID

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ERRORLOG;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{

void* call_omi_io_run_training (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training entry" );
    bool encounteredHwpError = false;

    do
    {
        // Starting beginning at this istep, we may be unable to scom the OCMBs
        // until the next istep is complete, except in certain cases where the
        // hardware procedure fails. Set ATTR_ATTN_POLL_PLID so ATTN knows to
        // poll the PRD_HWP_PLID before scomming the OCMBs.
        TargetHandle_t sys = nullptr;
        targetService().getTopLevelTarget(sys);
        assert(sys != nullptr);
        sys->setAttr<ATTR_ATTN_POLL_PLID>(1);

        // 12.7.a p10_omi_train.C
        TargetHandleList l_omicTargetList;
        getAllChiplets(l_omicTargetList, TYPE_OMIC);

        for (const auto & l_omic_target : l_omicTargetList)
        {
            TRACFCOMP(g_trac_isteps_trace, "p10_omi_train HWP target HUID %.8x",
                get_huid(l_omic_target));

            //  call the HWP with each OMIC target
            fapi2::Target<fapi2::TARGET_TYPE_OMIC>
                l_fapi_omic_target(l_omic_target);

            FAPI_INVOKE_HWP(l_err, p10_omi_train, l_fapi_omic_target );

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "ERROR : call p10_omi_train HWP: failed on target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_omic_target),
                    TRACE_ERR_ARGS(l_err));

                // Capture error
                captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID, l_omic_target);
                encounteredHwpError = true;
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                        "SUCCESS :  p10_omi_train HWP on 0x%.08X",
                        get_huid(l_omic_target));
            }
        }

        // Do not continue if an error was encountered
        if(encounteredHwpError)
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_io_run_training exited early because "
                "p10_omi_train had failures" );
            break;
        }

        // 12.7.b exp_omi_train.C
        TargetHandleList l_ocmbTargetList;
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

        for (const auto & l_ocmb_target : l_ocmbTargetList)
        {
            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                (l_ocmb_target);

            // Only run exp_omi_train on EXPLORER OCMB targets.
            uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();
            if (chipId == POWER_CHIPID::EXPLORER_16)
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "Start exp_omi_train on target HUID 0x%.8X",
                    get_huid(l_ocmb_target) );
                FAPI_INVOKE_HWP(l_err, exp_omi_train, l_fapi_ocmb_target);

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( g_trac_isteps_trace,
                    "ERROR : call exp_omi_train HWP(): failed on target 0x%08X."
                        TRACE_ERR_FMT,
                        get_huid(l_ocmb_target),
                        TRACE_ERR_ARGS(l_err));

                    // Capture error
                    captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID,
                                 l_ocmb_target);
                    encounteredHwpError = true;
                }
                else
                {
                    TRACFCOMP( g_trac_isteps_trace,
                        "SUCCESS :  exp_omi_train HWP on target 0x%.08X",
                        get_huid(l_ocmb_target));
                }
            }
            else
            {
                // Skip exp_omi_train call on non-Explorer chips
                TRACFCOMP( g_trac_isteps_trace,
                    "Skipping exp_omi_train HWP on target HUID 0x%.8X, "
                    "chipId 0x%.4X",
                    get_huid(l_ocmb_target), chipId );
            }
        }

    } while (0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
