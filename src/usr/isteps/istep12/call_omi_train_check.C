/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_train_check.C $               */
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
 * @file    call_omi_train_check.C
 *
 *  Contains the HWP wrapper for Istep 12.8
 *      exp_omi_train_check
 *      p10_omi_train_check
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>    // captureError

#include    <util/misc.H>           // isSimicsRunning()

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <p10_omi_train_check.H>
#include    <exp_omi_train_check.H>
#include    <chipids.H>             // for EXPLORER ID

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{

void* call_omi_train_check (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check entry");

    do
    {
        // 12.8.a exp_omi_train_check.C
        //        - Check for training errors

        // Find functional ocmb targets
        TargetHandleList l_chipList;
        getAllChips(l_chipList, TYPE_OCMB_CHIP, true);

        for (auto & l_ocmb: l_chipList)
        {
            // Only run exp_omi_train_check on EXPLORER OCMB targets.
            uint32_t chipId = l_ocmb->getAttr<ATTR_CHIP_ID>();
            if (chipId == POWER_CHIPID::EXPLORER_16)
            {
                fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>
                    l_ocmb_target( l_ocmb );
                FAPI_INVOKE_HWP(l_err, exp_omi_train_check, l_ocmb_target );

                //  process return code.
                if ( l_err )
                {
                    TRACFCOMP( g_trac_isteps_trace,
                        "ERROR : call exp_omi_train_check HWP(): failed on "
                        "target 0x%08X. "
                        TRACE_ERR_FMT,
                        get_huid(l_ocmb),
                        TRACE_ERR_ARGS(l_err));

                    // Capture error
                    captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID, l_ocmb);
                }
                else
                {
                    TRACFCOMP( g_trac_isteps_trace,
                        "SUCCESS : exp_omi_train_check HWP on target "
                        "HUID %.08x",
                        get_huid(l_ocmb));
                }
            }
            else
            {
                // Not an Explorer, just skip exp_omi_train_check call
                TRACFCOMP( g_trac_isteps_trace,
                    "Skipping exp_omi_train_check HWP because target "
                    "HUID 0x%.8X, chipId 0x%.4X is not an Explorer OCMB",
                    get_huid(l_ocmb), chipId );
            }
        } // OCMB loop

        // Do not continue if an error was encountered
        if(!l_StepError.isNull())
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_omi_train_check exited early because "
                "exp_omi_train_check had failures" );
            break;
        }

        // 12.8.b p10_omi_train_check.C
        //        - Check for training errors

        // Find omi targets
        TargetHandleList l_omiTargetList;
        getAllChiplets(l_omiTargetList, TYPE_OMI);

        for (const auto & l_omi_target : l_omiTargetList)
        {
            //  call the HWP with each OMI target
            fapi2::Target<fapi2::TARGET_TYPE_OMI>
                l_fapi_omi_target(l_omi_target);

            FAPI_INVOKE_HWP(l_err, p10_omi_train_check, l_fapi_omi_target );

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "ERROR : call p10_omi_train_check HWP(): failed on "
                    "target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_omi_target),
                    TRACE_ERR_ARGS(l_err));

                // Capture error
                captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID,
                    l_omi_target);
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "SUCCESS : p10_omi_train_check HWP on target HUID %.08x",
                    get_huid(l_omi_target));
            }
        } // OMI loop
    } while (0);

    // Beyond this point, scoms to the OCMBs should be working, so clear the
    // ATTR_ATTN_POLL_PLID attribute since attention won't need to check the
    // PRD_HWP_PLID attribute before scomming the OCMBs anymore.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget(sys);
    assert(sys != nullptr);
    sys->setAttr<ATTR_ATTN_POLL_PLID>(0);

    TRACFCOMP( g_trac_isteps_trace, "call_omi_train_check exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
