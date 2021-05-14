/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_pcie_scominit.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
   @file call_proc_pcie_scominit.C
 *
 *  Support file for IStep: call_proc_pcie_scominit
 *    This istep will do 2 things:
 *        1) Perform PCIE SCOM initialization
 *        2) Setup necessary PCIe Attributes for later HWPs/FW
 *           to properly enable PCIe devices
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

#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <istepHelperFuncs.H>          // captureError
#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>

#include    "host_proc_pcie_scominit.H"
#include    <p10_pcie_scominit.H>
#include    <p10_perv_sbe_cmn.H>
#include    <p10_hang_pulse_mc_setup_tables.H>

namespace   ISTEP_10
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//*****************************************************************************
// wrapper function to call proc_pcie_scominit
//******************************************************************************
void*    call_proc_pcie_scominit( void    *io_pArgs )
{
    errlHndl_t l_errl(nullptr);
    IStepError l_stepError;
    TARGETING::TargetHandleList l_procTargetList;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_pcie_scominit enter" );

    // Get a list of all proc chips
    getAllChips(l_procTargetList, TYPE_PROC);

    // Loop through all proc chips, set PCIe attributes,
    //  convert to fap2 target, and execute hwp
    for (const auto & curproc : l_procTargetList)
    {
        l_errl = computeProcPcieConfigAttrs(curproc);
        if(l_errl != nullptr)
        {
            // Any failure to configure PCIE that makes it to this handler
            // implies a firmware bug that should be fixed, everything else
            // is tolerated internally (usually as disabled PHBs)
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK "call_proc_pcie_scominit> Failed in call to "
                       "computeProcPcieConfigAttrs for target with HUID = "
                       "0x%08X",
                       curproc->getAttr<TARGETING::ATTR_HUID>() );
            l_stepError.addErrorDetails(l_errl);
            errlCommit( l_errl, ISTEP_COMP_ID );
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2_proc_target(
                                                                 curproc);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running p10_pcie_scominit HWP on "
                   "target HUID %.8X", TARGETING::get_huid(curproc) );

        FAPI_INVOKE_HWP(l_errl, p10_pcie_scominit, l_fapi2_proc_target);

        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR : call p10_pcie_scominit HWP(): failed on target 0x%08X. "
                           TRACE_ERR_FMT,
                           get_huid(curproc),
                           TRACE_ERR_ARGS(l_errl));

            // Capture Error
            captureError(l_errl, l_stepError, HWPF_COMP_ID, curproc);

            // Run HWP on all procs even if one reports an error
            continue;

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "SUCCESS : proc_pcie_scominit HWP" );
        }

        // Reset multicast groups, since those may have changed based on the
        // the logic above.
        FAPI_INVOKE_HWP(l_errl, p10_perv_sbe_cmn_setup_multicast_groups,
                        l_fapi2_proc_target, ISTEP10_MC_GROUPS);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_proc_pcie_scominit: call to p10_perv_sbe_cmn_setup_multicast_groups failed for PROC HUID 0x%08x",
                      get_huid(curproc));

            // Capture this error and continue, since the HWP above needs
            // to run on all procs.
            captureError(l_errl, l_stepError, HWPF_COMP_ID, curproc);
            continue;
        }
    }
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_pcie_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}
};
