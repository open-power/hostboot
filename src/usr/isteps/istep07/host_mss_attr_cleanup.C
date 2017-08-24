/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/host_mss_attr_cleanup.C $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
 *  @file call_mss_attr_update.C
 *  Contains the wrapper for istep 7.5
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>
#include    <arch/pirformat.H>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>

#include    <isteps/hwpisteperror.H>

#include    <errl/errludtarget.H>
#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

#include    <hwas/common/hwasCallout.H> //@fixme-RTC:149250-Remove

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

// fapi2 support
#include <fapi2.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

#include <config.h>

// HWP
#include <p9c_mss_attr_cleanup.H>

namespace   ISTEP_07
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//
//  Wrapper function to call mss_attr_update
//
void*    host_mss_attr_cleanup( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_mss_attr_cleanup entry");
    // errlHndl_t l_err = NULL;

    TargetHandleList l_funcDimmList;
    // Get all the functional Dimms
    TARGETING::getAllLogicalCards(l_funcDimmList, TYPE_DIMM, true);

    for (const auto & l_Dimm: l_funcDimmList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_DIMM>
          l_fapi2_dimm_target(l_Dimm);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "Running p9c_mss_attr_cleanup HWP on "
                  "DIMM target HUID %.8X", TARGETING::get_huid(l_Dimm));
        FAPI_INVOKE_HWP(l_err, p9c_mss_attr_cleanup, l_fapi2_dimm_target);
        if(l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : p9c_mss_attr_cleanup HWP returned "
                      "error for HUID %.8x",
                      l_err->reasonCode(), TARGETING::get_huid(l_Dimm));
            l_StepError.addErrorDetails(l_err);
            errlCommit( l_err, HWPF_COMP_ID );
        }
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "host_mss_attr_cleanup exit" );

    return l_StepError.getErrorHandle();
}

};   // end namespace
