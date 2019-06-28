/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_mss_getecid.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
/* FIXME RTC: 210975
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
*/
#include    <util/utilmbox_scratch.H>

/* FIXME RTC: 210975
//HWP
#ifndef CONFIG_AXONE

#else
    #include <chipids.H>
// @todo RTC 208512   #include  <exp_getecid.H>
    #include  <gem_getecid.H>
#endif
*/


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void cumulus_mss_getecid(IStepError & io_istepError);
void axone_mss_getecid(IStepError & io_istepError);

void* call_mss_getecid (void *io_pArgs)
{
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid entry" );
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    switch (l_procModel)
    {
        case TARGETING::MODEL_CUMULUS:
            cumulus_mss_getecid(l_StepError);
            break;
        case TARGETING::MODEL_AXONE:
            axone_mss_getecid(l_StepError);
            break;
        case TARGETING::MODEL_NIMBUS:
        default:
            break;
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_getecid exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

#ifndef CONFIG_AXONE
void cumulus_mss_getecid(IStepError & io_istepError)
{

}
#else
void cumulus_mss_getecid(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9c_mss_get_cen_ecid' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

#ifdef CONFIG_AXONE
void axone_mss_getecid(IStepError & io_istepError)
{
/* FIXME RTC: 210975
    errlHndl_t l_err = NULL;

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    bool isGeminiChip = false;
    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP>
            l_fapi_ocmb_target(l_ocmb_target);

        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< TARGETING::ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            isGeminiChip = false;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running exp_getecid HWP on target HUID 0x%.8X",
                TARGETING::get_huid(l_ocmb_target) );
            //@todo RTC 208512: FAPI_INVOKE_HWP(l_err, exp_getecid, l_fapi_ocmb_target);
        }
        else
        {
            isGeminiChip = true;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running gem_getecid HWP on target HUID 0x%.8X, chipId 0x%.4X",
                TARGETING::get_huid(l_ocmb_target), chipId );
            FAPI_INVOKE_HWP(l_err, gem_getecid, l_fapi_ocmb_target);
        }

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X : %s_getecid HWP returned error",
                l_err->reasonCode(), isGeminiChip?"gem":"exp");

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_ocmb_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS running %s_getecid HWP on target HUID 0x%.8X",
                isGeminiChip?"gem":"exp", TARGETING::get_huid(l_ocmb_target) );
        }
    }
*/
}
#else
void axone_mss_getecid(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'gem_getecid' or 'exp_getecid' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif
};
