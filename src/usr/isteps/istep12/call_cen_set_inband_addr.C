/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_cen_set_inband_addr.C $           */
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
#include <util/misc.H>

//HWP
#include    <p9c_set_inband_addr.H>

#ifdef CONFIG_AXONE
#include    <exp_omi_init.H>
#include    <p9a_omi_init.H>
#endif

//Inband SCOM
#include    <ibscom/ibscomif.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_cen_set_inband_addr (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;
    auto l_procModel = TARGETING::targetService().getProcessorModel();

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr entry" );

    if(l_procModel == TARGETING::MODEL_CUMULUS)
    {
        TARGETING::TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr: %d proc chips found",
                l_procTargetList.size());

        for (const auto & l_proc_target : l_procTargetList)
        {

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "p9c_set_inband_addr HWP target HUID %.8x",
                TARGETING::get_huid(l_proc_target));

            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                    (l_proc_target);

            FAPI_INVOKE_HWP(l_err, p9c_set_inband_addr, l_fapi_proc_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9c_set_inband_addr HWP on target HUID %.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_proc_target) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_proc_target).addToLog( l_err );

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9c_set_inband_addr HWP");
            }

        }
    }

    // @todo RTC 187913 inband centaur scom in P9
    // Re-enable when support available in simics
    if ( Util::isSimicsRunning() == false )
    {
        //Now enable Inband SCOM for all membuf chips.
        IBSCOM::enableInbandScoms();
    }

#ifdef CONFIG_AXONE
    if(l_procModel == TARGETING::MODEL_AXONE)
    {

        TARGETING::TargetHandleList l_ocmbTargetList;
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr: %d ocmb chips found",
                l_ocmbTargetList.size());

        for (const auto & l_ocmb_target : l_ocmbTargetList)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "exp_omi_init HWP target HUID %.8x",
                TARGETING::get_huid(l_ocmb_target));

            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                    (l_ocmb_target);

            FAPI_INVOKE_HWP(l_err, exp_omi_init , l_fapi_ocmb_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  exp_omi_init HWP on target HUID 0x%.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_ocmb_target) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_ocmb_target).addToLog( l_err );

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "SUCCESS :  exp_omi_init HWP on target HUID 0x%.8x",
                          TARGETING::get_huid(l_ocmb_target));
            }

        }

        TARGETING::TargetHandleList l_mccTargetList;
        getAllChiplets(l_mccTargetList, TYPE_MCC);

        for (const auto & l_mcc_target : l_mccTargetList)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "p9a_omi_init HWP target HUID %.8x",
                TARGETING::get_huid(l_mcc_target));

            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_MCC> l_fapi_mcc_target
                    (l_mcc_target);

            FAPI_INVOKE_HWP(l_err, p9a_omi_init, l_fapi_mcc_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X:  p9a_omi_init HWP on target HUID %.8x",
                    l_err->reasonCode(), TARGETING::get_huid(l_mcc_target) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_mcc_target).addToLog( l_err );

                // Create IStep error log and cross reference to error that occurred
                l_StepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );

            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  p9a_omi_init HWP on target HUID 0x%.8x",
                          TARGETING::get_huid(l_mcc_target));
            }

        }
    }
#endif // CONFIG_AXONE


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_set_inband_addr exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
