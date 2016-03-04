/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_pcie_scominit.C $            */
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
/**
   @file call_proc_pcie_scominit.C
 *
 *  Support file for IStep: nest_chiplets
 *   Nest Chiplets
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

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>

#include <p9_pcie_scominit.H>

namespace   ISTEP_08
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
    errlHndl_t          l_errl      =   NULL;
    IStepError          l_StepError;

    bool spBaseServicesEnabled = INITSERVICE::spBaseServicesEnabled();

    //
    //  get the master Proc target, we want to IGNORE this one.
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        if ( l_cpu_target  ==  l_pMasterProcTarget )
        {
            // we are just checking the Slave PCI's, skip the master
            continue;
        }

        // Compute the PCIE attribute config on all non-SP systems, since SP
        // won't be there to do it.
        if(!spBaseServicesEnabled)
        {
            // Unlike SP which operates on all present procs, the SP-less
            // algorithm only needs to operate on functional ones
            // TODO-RTC:149525
            //l_errl = computeProcPcieConfigAttrs(l_cpu_target);
            if(l_errl != NULL)
            {
                // Any failure to configure PCIE that makes it to this handler
                // implies a firmware bug that should be fixed, everything else
                // is tolerated internally (usually as disabled PHBs)
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         ERR_MRK "call_proc_pcie_scominit> Failed in call to "
                         "computeProcPcieConfigAttrs for target with HUID = "
                         "0x%08X",
                        l_cpu_target->getAttr<TARGETING::ATTR_HUID>() );
                l_StepError.addErrorDetails(l_errl);
                errlCommit( l_errl, ISTEP_COMP_ID );
            }
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2_proc_target(
                l_cpu_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "Running p9_pcie_scominit HWP on "
                 "target HUID %.8X", TARGETING::get_huid(l_cpu_target) );

        //  call the HWP with each fapi2::Target
        FAPI_INVOKE_HWP(l_errl, p9_pcie_scominit, l_fapi2_proc_target);

        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X : p9_pcie_scominit HWP returned error",
                     l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "SUCCESS :  proc_pcie_scominit HWP" );
        }
    } // end of looping through all processors

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_pcie_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};
