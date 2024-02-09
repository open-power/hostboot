/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_update_omi_firmware.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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

#include    <ocmbupd/ocmbupd.H>

#include    <istepHelperFuncs.H>          // captureError
#include    <fapi2/plat_hwp_invoker.H>
#include    <chipids.H>
#include    <exp_process_image_status.H>

// Misc
#include <hwas/common/hwas.H>
#include <console/consoleif.H>

#include <targeting/odyutil.H>
#include <ocmbupd/ody_upd_fsm.H>

#include <secureboot/ody_secureboot.H>
#include <secureboot/service.H>
#include <arch/magic.H>
#include <util/misc.H>
#include <targeting/attrrp.H>
#include <targeting/common/mfgFlagAccessors.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;
using   namespace   HWAS;
using   namespace   ocmbupd;

namespace ISTEP_12
{

void* call_update_omi_firmware (void *io_pArgs)
{
    IStepError l_StepError;
    TRACISTEP("call_update_omi_firmware entry" );

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
            TRACISTEP("Running exp_process_image_status HWP on target HUID 0x%.8X",
                      get_huid(l_ocmb_target) );
            errlHndl_t hwp_err = nullptr;
            FAPI_INVOKE_HWP(hwp_err, exp_process_image_status, l_fapi_ocmb_target);

            if ( hwp_err )
            {
                TRACISTEP("ERROR : call exp_process_image_status HWP(): failed on target 0x%08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_ocmb_target),
                          TRACE_ERR_ARGS(hwp_err));

                // Capture error and continue to the next chip
                captureError(hwp_err, l_StepError, HWPF_COMP_ID, l_ocmb_target);
            }
            else
            {
                TRACISTEP("SUCCESS running exp_process_image_status HWP on target HUID 0x%.8X",
                          get_huid(l_ocmb_target) );
            }
        }
        else if (!UTIL::isOdysseyChip(l_ocmb_target))
        {
            TRACISTEP("call_update_omi_firmware: Unknown chip ID 0x%X on target HUID 0x%.8X",
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
        TRACISTEP("skipping OCMB firmware update due to MPIPL");
    }
    else
    {
        TRACISTEP("Updating Explorer OCMBs");

        ocmbupd::explorerUpdateAll(l_StepError);

        TRACISTEP("Processing Odyssey OCMB firmware update events");

        using namespace ocmbupd;
        auto errl = ody_upd_all_process_event(UPDATE_OMI_FIRMWARE_REACHED,
                                              EVENT_ON_FUNCTIONAL_OCMBS,
                                              REQUEST_RECONFIG_IF_NEEDED);

        if (errl)
        {
            TRACISTEP(ERR_MRK"call_update_omi_firmware: ody_upd_all_process_event(UPDATE_OMI_FIRMWARE_REACHED) failed: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(errl));
            captureError(move(errl), l_StepError, HWPF_COMP_ID);
        }
    }

#ifdef CONFIG_SECUREBOOT

    // Run the secureboot checks if secureboot is enabled AND
    // NOT manufacturing mode OR if secureboot checks are explicitly
    // requested in manufacturing mode.
    // Currently there is an issue with DIMMs not having the security
    // bits fused correctly in MFG mode, which causes secureboot checks
    // to fail. This workaround will allow secureboot checks to run normally
    // or by request in MFG mode while the DIMMs are being fixed up.
    bool l_doOdySecurebootVerification = (SECUREBOOT::enabled() &&
                                          (!areAllSrcsTerminating() ||
                                            UTIL::assertGetToplevelTarget()->getAttr<ATTR_FORCE_ODY_SB_CHK_IN_MFG>() == 1));

    // Do not perform the Odyssey secureboot verification in simics unless Ody
    // secureboot is explicitly enabled.
    if( Util::isSimicsRunning() )
    {
        if( !magic_check_feature(MAGIC_FEATURE__ODYSECURITY) )
        {
            TRACISTEP("Skipping Ody security verification in Simics");
            l_doOdySecurebootVerification = false;
        }
    }

    if(l_doOdySecurebootVerification)
    {

        errlHndl_t l_securebootErrl = nullptr;
        for(auto l_ocmb : l_ocmbTargetList)
        {
            l_securebootErrl = odySecurebootVerification(l_ocmb);
            if(l_securebootErrl)
            {
                TRACISTEP(ERR_MRK"call_update_omi_firmware: Secureboot verification for OCMB 0x%x failed",
                          get_huid(l_ocmb));
                captureError(l_securebootErrl, l_StepError, SECURE_COMP_ID);
            }
        }
    }
#endif

    TRACISTEP("call_update_omi_firmware exit");

    return l_StepError.getErrorHandle();
}

}
