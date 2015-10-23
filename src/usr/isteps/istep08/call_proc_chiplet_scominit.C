/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_chiplet_scominit.C $         */
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
   @file call_proc_chiplet_scominit.C
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

//******************************************************************************
// wrapper function to call proc_chiplet_scominit
//******************************************************************************
void*    call_proc_chiplet_scominit( void    *io_pArgs )
{
    //errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                             "call_proc_chiplet_scominit entry" );

    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    do
    {
        // If running Sapphire, set sleep enable attribute here so
        // initfile can be run correctly
        if(is_sapphire_load())
        {
            TARGETING::Target* l_sys = NULL;
            TARGETING::targetService().getTopLevelTarget(l_sys);
            assert( l_sys != NULL );
            uint8_t l_sleepEnable = 1;
            l_sys->setAttr<TARGETING::ATTR_PM_SLEEP_ENABLE>(l_sleepEnable);
        }

        // ----------------------------------------------
        // Execute PROC_CHIPLET_SCOMINIT_FBC_IF initfile
        // ----------------------------------------------

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            /* @TODO: RTC:134078 Use fapi2 targets
            const TARGETING::Target* l_cpu_target = *l_cpuIter;
            const fapi::Target l_fapi_proc_target( TARGET_TYPE_PROC_CHIP,
                    ( const_cast<TARGETING::Target*>(l_cpu_target) ) );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_chiplet_scominit HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_cpu_target));

            // @TODO RTC:134078 call the HWP with each fapi::Target
            //FAPI_INVOKE_HWP(l_err, p9_chiplet_scominit, l_fapi_proc_target);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR 0x%.8X : "
                 "proc_chiplet_scominit HWP returns error.  target HUID %.8X",
                        l_err->reasonCode(), TARGETING::get_huid(l_cpu_target));

                ErrlUserDetailsTarget(l_cpu_target).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }
            //call p9_psi_scominit
            //FAPI_INVOKE_HWP(l_err,p9_psi_scominit);
            */
        }

    } while (0);

    return l_StepError.getErrorHandle();
}
};
