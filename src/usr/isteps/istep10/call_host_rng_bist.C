/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_rng_bist.C $                 */
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
 *  @file call_host_rng_bist.C
 *
 *  Support file for IStep: call_host_rng_bist
 *     Trigger the Random Number Generator Built In Self Test (BIST).
 *     Results are checked later in step16 when RNG is secured.
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlreasoncodes.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <istepHelperFuncs.H>          // captureError
#include    <fapi2/plat_hwp_invoker.H>
#include    <p10_rng_init_phase1.H>

namespace   ISTEP_10
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//******************************************************************************
// wrapper function to call host_rng_bist
//******************************************************************************
void* call_host_rng_bist( void *io_pArgs )
{
    errlHndl_t l_err(nullptr);
    IStepError l_stepError;
    TARGETING::TargetHandleList l_procTargetList;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_rng_bist entry" );

    // Get a list of all proc chips
    getAllChips(l_procTargetList, TYPE_PROC);

    // Loop through all proc chips
    for (const auto & curproc: l_procTargetList)
    {
        //Convert to fapi2 target
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapi2_proc_target(
                curproc);

        // Check for functional NX
        TARGETING::TargetHandleList l_nxTargetList;
        getChildChiplets(l_nxTargetList, curproc, TYPE_NX, true);
        if (l_nxTargetList.empty())
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "p10_rng_init_phase1: no functional NX found for proc %.8X",
                TARGETING::get_huid(curproc));
            //Continue loop for other proc chips
            continue;
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
          "Running p10_rng_init_phase1 HWP on processor target %.8X",
          TARGETING::get_huid(curproc) );

        FAPI_INVOKE_HWP(l_err, p10_rng_init_phase1, l_fapi2_proc_target);
        if(l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR : call p10_rng_init_phase1 HWP(): failed on target 0x%08X. "
                           TRACE_ERR_FMT,
                           get_huid(curproc),
                           TRACE_ERR_ARGS(l_err));

            //Loop through errorlog userdetails sections
            for (const auto l_callout : l_err->getUDSections(
                    HWPF_COMP_ID,
                    ERRORLOG::ERRL_UDT_CALLOUT))
            {
                //Check if the callout type was a HW_CALLOUT
                if(reinterpret_cast<HWAS::callout_ud_t*>
                    (l_callout)->type == HWAS::HW_CALLOUT)
                {
                    //Add a HW Callout for each NX target associated
                    // with the proc that failed the HWP
                    for (const auto & l_nxTarget: l_nxTargetList)
                    {
                        l_err->addHwCallout( l_nxTarget,
                            HWAS::SRCI_PRIORITY_HIGH,
                            HWAS::DECONFIG,
                            HWAS::GARD_NULL );
                    }
                 }
            }

            // Capture Error
            captureError(l_err, l_stepError, HWPF_COMP_ID, curproc);

            // Run HWP on all procs even if one reports an error
            continue;
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_rng_bist exit");

    return l_stepError.getErrorHandle();
}

};   // end namespace
