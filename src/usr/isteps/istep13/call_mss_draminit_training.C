/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit_training.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include "istep13consts.H"

#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_mss_draminit_training.H>


using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
{
void* call_mss_draminit_training (void *io_pArgs)
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "call_mss_draminit_training entry" );

    // Get all MCBIST targets
    TARGETING::TargetHandleList l_mcbistTargetList;
    getAllChiplets(l_mcbistTargetList, TYPE_MCBIST);

    for (const auto & l_mcbist_target : l_mcbistTargetList)
    {
        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running p9_mss_draminit_training HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_mcbist_target));

        fapi2::Target <fapi2::TARGET_TYPE_MCBIST> l_fapi_mcbist_target
            (l_mcbist_target);
            //TODO 134081
//         FAPI_INVOKE_HWP(l_err, p9_mss_draminit_training, l_fapi_mcbist_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : p9_mss_draminit_training HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_mcbist_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  p9_mss_draminit_training HWP( )" );
        }

    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_draminit_training exit" );

    return l_stepError.getErrorHandle();
}

};
