/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
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
 * @file    call_mss_getecid.C
 *
 *  Contains the wrapper for Istep 12.1 exp_getecid
 *
 */

#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <istepHelperFuncs.H>          // captureError

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

//HWP
#include  <chipids.H>
#include  <exp_getecid.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{

void* call_mss_getecid (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    compId_t  l_componentId = HWPF_COMP_ID;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid entry" );

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
            l_fapi_ocmb_target(l_ocmb_target);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< TARGETING::ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running exp_getecid HWP on target HUID 0x%.8X",
                TARGETING::get_huid(l_ocmb_target) );
            FAPI_INVOKE_HWP(l_err, exp_getecid, l_fapi_ocmb_target);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR : call exp_getecid HWP(): failed on target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_ocmb_target),
                    TRACE_ERR_ARGS(l_err));
                l_componentId = HWPF_COMP_ID;
            }
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Unknown chip ID 0x%X on target HUID 0x%.8X",
                chipId, TARGETING::get_huid(l_ocmb_target) );

            /*@
             *  @errortype
             *  @reasoncode  ISTEP::RC_INVALID_OCMB_CHIP_ID
             *  @severity    ERRORLOG::ERRL_SEV_UNRECOVERABLE
             *  @moduleid    ISTEP::MOD_MSS_GETECID
             *  @userdata1   Huid of the ocmb target
             *  @userdata2   Chip ID
             *  @devdesc     Invalid chip ID (!= POWER_CHIPID::EXPLORER_16)
             *  @custdesc    A problem occurred during the IPL of the system.
             */
            l_err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_MSS_GETECID,
                              RC_INVALID_OCMB_CHIP_ID,
                              TO_UINT64( TARGETING::get_huid(l_ocmb_target) ),
                              TO_UINT64( chipId ) );
            l_err->addHwCallout(l_ocmb_target,
                               HWAS::SRCI_PRIORITY_HIGH,
                               HWAS::DECONFIG,
                               HWAS::GARD_NULL);

            l_err->collectTrace(ISTEP_COMP_NAME);
            l_componentId = ISTEP_COMP_ID;
        }

        if ( l_err )
        {
            // Capture error
            captureError(l_err, l_StepError, l_componentId, l_ocmb_target);

            // Continue the next chip to gather up all the errors
            continue;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS running %s_getecid HWP on target HUID 0x%.8X",
                "exp", TARGETING::get_huid(l_ocmb_target) );
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
