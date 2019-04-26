/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_scominit.C $                  */
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

//Error handling and tracing
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

// fapi2 HWP invoker
#include    <fapi2/plat_hwp_invoker.H>

//From Import Directory (EKB Repository)
#include    <config.h>
#include    <fapi2.H>
#include    <p9_mss_scominit.H>
#include    <p9_throttle_sync.H>
#include    <p9c_mss_scominit.H>
#ifdef CONFIG_AXONE
#include    <exp_scominit.H>
#include    <chipids.H> // for EXPLORER ID
#endif

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
{
void nimbus_call_mss_scominit(IStepError & io_istepError);
void cumulus_call_mss_scominit(IStepError & io_istepError);
void axone_call_mss_scominit(IStepError & io_istepError);

void* call_mss_scominit (void *io_pArgs)
{
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit entry" );
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    switch (l_procModel)
    {
        case TARGETING::MODEL_CUMULUS:
            cumulus_call_mss_scominit(l_StepError);
            break;
        case TARGETING::MODEL_AXONE:
            axone_call_mss_scominit(l_StepError);
            break;
        case TARGETING::MODEL_NIMBUS:
            nimbus_call_mss_scominit(l_StepError);
            break;
        default:
            assert(0, "call_mss_scominit: Unsupported model type 0x%04X",
                l_procModel);
            break;
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

#ifndef CONFIG_AXONE

void nimbus_call_mss_scominit(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;

    // Get all MCBIST targets
    TARGETING::TargetHandleList l_mcbistTargetList;
    getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

    for (const auto & l_target : l_mcbistTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_mss_scominit HWP on target HUID %.8X",
                TARGETING::get_huid(l_target));

        fapi2::Target <fapi2::TARGET_TYPE_MCBIST> l_fapi_target
            (l_target);

        //  call the HWP with each fapi2::Target
        FAPI_INVOKE_HWP(l_err, p9_mss_scominit, l_fapi_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: p9_mss_scominit HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that
            // occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS running p9_mss_scominit HWP on target HUID %.8X",
                    TARGETING::get_huid(l_target));
        }
    }
}

void cumulus_call_mss_scominit(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;

    // Get all MBA targets
    TARGETING::TargetHandleList l_membufTargetList;
    getAllChips(l_membufTargetList, TYPE_MEMBUF);

    for (const auto & l_membuf_target : l_membufTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9c_mss_scominit HWP on target HUID %.8X",
                TARGETING::get_huid(l_membuf_target));

        fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapi_membuf_target
            (l_membuf_target);

        //  call the HWP with each fapi2::Target
        FAPI_INVOKE_HWP(l_err, p9c_mss_scominit, l_fapi_membuf_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: p9c_mss_scominit HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that
            // occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "SUCCESS running p9c_mss_scominit HWP on target HUID %.8X",
                  TARGETING::get_huid(l_membuf_target));
        }
    }
}
#else
void nimbus_call_mss_scominit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9_mss_scominit' but Nimbus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}

void cumulus_call_mss_scominit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'p9c_mss_scominit' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}

#endif

#ifdef CONFIG_AXONE
void axone_call_mss_scominit(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;

    // Get all OCMB targets
    TARGETING::TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmb_target : l_ocmbTargetList)
    {
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb_target->getAttr< TARGETING::ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                (l_ocmb_target);

            // Dump current run on target
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running exp_scominit HWP on target HUID %.8X",
                TARGETING::get_huid(l_ocmb_target));

            //  call the HWP with each fapi2::Target
            FAPI_INVOKE_HWP(l_err, exp_scominit, l_fapi_ocmb_target);
        }
        else
        {
            // Gemini, NOOP
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Skipping scominit HWP on target HUID 0x%.8X, chipId 0x%.4X",
                TARGETING::get_huid(l_ocmb_target), chipId );
        }

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X: exp_scominit HWP returns error",
                      l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_ocmb_target).addToLog(l_err);

            // Create IStep error log and cross reference to error that
            // occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );

            break;
        }
        else if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "SUCCESS running exp_scominit HWP on "
                  "target HUID %.8X", TARGETING::get_huid(l_ocmb_target));
        }
    }
}
#else
void axone_call_mss_scominit(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
              "Error: Trying to call 'exp_scominit' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif
};
