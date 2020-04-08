/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_scominit.C $                  */
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

// Istep framework
#include <istepHelperFuncs.H>

// fapi2 HWP invoker
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <config.h>

//From Import Directory (EKB Repository)
#include    <exp_scominit.H>
#include    <chipids.H> // for EXPLORER ID


using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

namespace ISTEP_13
{

void* call_mss_scominit (void *io_pArgs)
{
    IStepError l_stepError;

    TRACFCOMP( g_trac_isteps_trace, ENTER_MRK"call_mss_scominit" );

    errlHndl_t l_err = nullptr;

    // Get all functional OCMB targets
    TargetHandleList l_ocmbTargetList;
    getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);

    for (const auto & l_ocmb : l_ocmbTargetList)
    {
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb->getAttr< ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            fapi2::Target <fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                (l_ocmb);

            // Dump current run on target
            TRACFCOMP( g_trac_isteps_trace,
                "Running exp_scominit HWP on target HUID 0x%.8X",
                get_huid(l_ocmb) );

            //  call the HWP with each fapi2::Target
            FAPI_INVOKE_HWP(l_err, exp_scominit, l_fapi_ocmb_target);
        }
        else
        {
            // non-Explorer chip
            TRACFCOMP( g_trac_isteps_trace,
                "Skipping exp_scominit HWP on target HUID 0x%.8X, chipId 0x%.4X",
                get_huid(l_ocmb), chipId );
            continue;
        }

        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : exp_scominit target 0x%.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_ocmb),
                      TRACE_ERR_ARGS(l_err));
            // capture error and commit it
            captureError(l_err, l_stepError, HWPF_COMP_ID, l_ocmb);
            break;
        }
        else
        {
            TRACFCOMP( g_trac_isteps_trace,
                  "SUCCESS running exp_scominit HWP on "
                  "target HUID 0x%.8X", get_huid(l_ocmb));
        }
    }

    TRACFCOMP( g_trac_isteps_trace, EXIT_MRK"call_mss_scominit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
