/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_update_omi_firmware.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
 * @file    call_update_omi_firmware.C
 *
 *  Support file for Istep 12.12 Explorer firmware update
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

// Targeting support
#include    <targeting/targplatutil.H>

#include    <expupd/expupd.H>

#include    <istepHelperFuncs.H>          // captureError
#include    <fapi2/plat_hwp_invoker.H>
#include    <chipids.H>
#include    <exp_process_image_status.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
void* call_update_omi_firmware (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( g_trac_isteps_trace, "call_update_omi_firmware entry" );

    // Need to gather some information from the OCMBs before attempting
    //  the update flow

    // Get all OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
          l_fapi_ocmb_target(l_ocmb_target);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                       "Running exp_process_image_status HWP on target HUID 0x%.8X",
                       get_huid(l_ocmb_target) );
            errlHndl_t l_err = nullptr;
            FAPI_INVOKE_HWP(l_err, exp_process_image_status, l_fapi_ocmb_target);

            if ( l_err )
            {
                TRACFCOMP( g_trac_isteps_trace,
                           "ERROR : call exp_process_image_status HWP(): failed on target 0x%08X. "
                           TRACE_ERR_FMT,
                           get_huid(l_ocmb_target),
                           TRACE_ERR_ARGS(l_err));

                // Capture error and continue to the next chip
                captureError(l_err, l_StepError, HWPF_COMP_ID, l_ocmb_target);
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                           "SUCCESS running exp_process_image_status HWP on target HUID 0x%.8X",
                           get_huid(l_ocmb_target) );
            }
        }
        else // Not an Explorer, continue to the next chip.
        {
            TRACFCOMP( g_trac_isteps_trace,
                       "call_update_omi_firmware: Unknown chip ID 0x%X on target HUID 0x%.8X",
                       chipId, get_huid(l_ocmb_target) );
        }
    } // OCMB loop


    // Clear ATTR_ATTN_CHK_OCMBS to let ATTN know that interrupts from the OCMBs
    // should now be enabled.
    TargetHandle_t sys = nullptr;
    targetService().getTopLevelTarget( sys );
    assert( sys != nullptr );
    sys->setAttr<ATTR_ATTN_CHK_OCMBS>(0);

    // Check if any explorer chips require a firmware update and update them
    // (skipped on MPIPL)
    if (UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP( g_trac_isteps_trace,
                   "skipping expupd::UpdateAll() due to MPIPL");
    }
    else
    {
        expupd::updateAll(l_StepError);
    }

    TRACFCOMP( g_trac_isteps_trace, "call_update_omi_firmware exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
