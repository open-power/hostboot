/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_pcie_scominit.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>

//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "start_clocks_on_nest_chiplets_custom.C" and include
//      the prototypes here.
//  #include    "nest_chiplets_custom.H"
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
    //@TODO RTC:134078
/*    IStepError          l_StepError;

    bool spBaseServicesEnabled = INITSERVICE::spBaseServicesEnabled();

    TARGETING::TargetHandleList l_procTargetList;
    getAllChips(l_procTargetList, TYPE_PROC);

    for ( TargetHandleList::const_iterator
          l_iter = l_procTargetList.begin();
          l_iter != l_procTargetList.end();
          ++l_iter )
    {
        TARGETING::Target* const l_proc_target = *l_iter;

        // Compute the PCIE attribute config on all non-SP systems, since SP
        // won't be there to do it.
        if(!spBaseServicesEnabled)
        {
            // Unlike SP which operates on all present procs, the SP-less
            // algorithm only needs to operate on functional ones
            l_errl = computeProcPcieConfigAttrs(l_proc_target);
            if(l_errl != NULL)
            {
                // Any failure to configure PCIE that makes it to this handler
                // implies a firmware bug that should be fixed, everything else
                // is tolerated internally (usually as disabled PHBs)
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    ERR_MRK "call_proc_pcie_scominit> Failed in call to "
                    "computeProcPcieConfigAttrs for target with HUID = "
                    "0x%08X",
                    l_proc_target->getAttr<TARGETING::ATTR_HUID>());
                l_StepError.addErrorDetails(l_errl);
                errlCommit( l_errl, ISTEP_COMP_ID );
            }
        }

        const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                ( const_cast<TARGETING::Target*>(l_proc_target) ));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_pcie_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_proc_target));

        //  call the HWP with each fapi::Target
        //  @TODO RTC: 134078
        //FAPI_INVOKE_HWP(l_errl, p9_pcie_scominit, l_fapi_proc_target);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X : proc_pcie_scominit HWP returns error",
                      l_errl->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_proc_target).addToLog( l_errl );

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
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "call_proc_pcie_scominit exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
    */
        return l_errl;
}
};
