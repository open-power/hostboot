/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_revert_sbe_mcs_setup.C $     */
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

#include    <stdint.h>

#include    <trace/interface.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>

#include    <isteps/hwpisteperror.H>
#include    <initservice/isteps_trace.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <p9_revert_sbe_mcs_setup.H>

namespace ISTEP_06
{

void* call_host_revert_sbe_mcs_setup( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_revert_sbe_mcs_setup entry" );

    TARGETING::Target * l_masterProc;
    TARGETING::targetService().masterProcChipTargetHandle( l_masterProc );

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "Running p9_revert_sbe_mcs_setup on "
              "target HUID %.8X",
              TARGETING::get_huid(l_masterProc));

    // cast the target to a fapi2 target
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_master_proc( l_masterProc );

    //Invode p9_revert_sbe_mcs_setup
    FAPI_INVOKE_HWP( l_err, p9_revert_sbe_mcs_setup, l_fapi_master_proc );

    if (l_err)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "ERROR 0x%.8X: p9_revert_sbe_mcs_setup",
                  l_err->reasonCode());
        // Create IStep error log and cross reference error
        l_stepError.addErrorDetails(l_err);
        // Commit error
        errlCommit(l_err,SBE_COMP_ID);
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_revert_sbe_mcs_setup exit" );

    return l_stepError.getErrorHandle();
}

};
