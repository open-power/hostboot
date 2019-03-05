/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_dmi_io_dccal.C $                  */
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

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

// HWP (only bring in model-specific HWP headers to save space)
#ifdef CONFIG_AXONE
#include    <p9a_io_omi_dccal.H>
#include    <p9a_io_omi_scominit.H>
#else
#include    <p9_io_dmi_dccal.H>
#include    <p9_io_cen_dccal.H>
#endif

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{

// Declare local functions
void cumulus_dccal_setup(IStepError & io_istepError);
void axone_dccal_setup(IStepError & io_istepError);

void* call_dmi_io_dccal (void *io_pArgs)
{
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_dccal entry" );

    do
    {
        auto l_procModel = TARGETING::targetService().getProcessorModel();

        switch (l_procModel)
        {
            case TARGETING::MODEL_CUMULUS:
                cumulus_dccal_setup(l_StepError);
                break;
            case TARGETING::MODEL_AXONE:
                axone_dccal_setup(l_StepError);
                break;
            case TARGETING::MODEL_NIMBUS:
            default:
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "skipping p9_io_dmi_dccal because not required for current processor model 0x%x", l_procModel);
                break;
        }

    }while(0);


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_dmi_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

#ifndef CONFIG_AXONE
void cumulus_dccal_setup(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for (const auto & l_proc_target : l_procTargetList)
    {
        // a. p9_io_dmi_dccal.C (DMI target)

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_io_dmi_dccal HWP target HUID %.8x",
            TARGETING::get_huid(l_proc_target));

        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                (l_proc_target);

        FAPI_INVOKE_HWP(l_err, p9_io_dmi_dccal, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9_io_dmi_dccal HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_proc_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9_io_dmi_dccal HWP on target HUID %.8x",
                       TARGETING::get_huid(l_proc_target) );
        }

        // b. p9_io_cen_dccal.C (Centaur target)

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9_io_cen_dccal HWP target HUID %.8x",
            TARGETING::get_huid(l_proc_target));

        FAPI_INVOKE_HWP(l_err, p9_io_cen_dccal, l_fapi_proc_target);

        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9_io_cen_dccal HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_proc_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9_io_cen_dccal HWP on target HUID %.8x",
                       TARGETING::get_huid(l_proc_target) );
        }

    }
}
#else
void cumulus_dccal_setup(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
          "Error: Trying to call 'p9_io_dmi_dccal' and 'p9_io_cen_dccal' but Cumulus code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

#ifdef CONFIG_AXONE
void axone_dccal_setup(IStepError & io_istepError)
{
    errlHndl_t l_err = nullptr;
    TARGETING::TargetHandleList l_omicTargetList;
    getAllChiplets(l_omicTargetList, TYPE_OMIC);

    for (const auto & l_omic_target : l_omicTargetList)
    {
        //  call the HWP with each target
        fapi2::Target<fapi2::TARGET_TYPE_OMIC> l_fapi_omic_target
                (l_omic_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "p9a_io_omi_scominit HWP target HUID %.8x",
            TARGETING::get_huid(l_omic_target));

        FAPI_INVOKE_HWP(l_err, p9a_io_omi_scominit, l_fapi_omic_target);
        //  process return code.
        if ( l_err )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X:  p9a_io_omi_scominit HWP on target HUID %.8x",
                l_err->reasonCode(), TARGETING::get_huid(l_omic_target) );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_omic_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            io_istepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, ISTEP_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9a_io_omi_scominit HWP on target HUID %.8x",
                       TARGETING::get_huid(l_omic_target) );
        }
    }
}
#else
void axone_dccal_setup(IStepError & io_istepError)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
          "Error: Trying to call 'p9a_io_omi_scominit' but Axone code is not compiled in");
    assert(0, "Calling wrong Model's HWPs");
}
#endif

};
