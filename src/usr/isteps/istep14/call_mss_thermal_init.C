/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_thermal_init.C $              */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>

#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

namespace ISTEP_14
{
void* call_mss_thermal_init (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;
    IStepError  l_StepError;

    do
    {
        // Get all Centaur targets
        TARGETING::TargetHandleList l_memBufTargetList;
        getAllChips(l_memBufTargetList, TYPE_MEMBUF );

        //  --------------------------------------------------------------------
        //  run mss_thermal_init on all Centaurs
        //  --------------------------------------------------------------------
        for (TargetHandleList::const_iterator
                l_iter = l_memBufTargetList.begin();
                l_iter != l_memBufTargetList.end();
                ++l_iter)
        {
            //  make a local copy of the target for ease of use
            const TARGETING::Target*  l_pCentaur = *l_iter;

            //  write HUID of target
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "target HUID %.8X", TARGETING::get_huid(l_pCentaur));

            //@TODO RTC:133831 cast OUR type of target to a FAPI type of target.
            //const fapi::Target l_fapi_pCentaur( TARGET_TYPE_MEMBUF_CHIP,
            //        (const_cast<TARGETING::Target*>(l_pCentaur)) );

            // Current run on target
            //TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            //        "Running call_mss_thermal_init HWP on "
            //        "target HUID %.8X", TARGETING::get_huid(l_pCentaur));


            //  call the HWP with each fapi::Target
            //FAPI_INVOKE_HWP( l_errl, mss_thermal_init, l_fapi_pCentaur );

            if ( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X: mss_thermal_init HWP returns error",
                        l_errl->reasonCode());

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_pCentaur).addToLog( l_errl );

                // Create IStep error log and cross reference
                // to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS : mss_thermal_init HWP( )" );
            }
        }
        if (l_errl)
        {
            break;
        }

        // Run proc throttle sync
        // Get all functional proc chip targets
        TARGETING::TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for (TARGETING::TargetHandleList::const_iterator
             l_cpuIter = l_cpuTargetList.begin();
             l_cpuIter != l_cpuTargetList.end();
             ++l_cpuIter)
        {
            const TARGETING::Target* l_pTarget = *l_cpuIter;

            //@TODO RTC:133831
            //fapi::Target l_fapiproc_target( TARGET_TYPE_PROC_CHIP,
            //     (const_cast<TARGETING::Target*>(l_pTarget)));

            //TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            //        "Running proc_throttle_sync HWP on "
            //        "target HUID %.8X", TARGETING::get_huid(l_pTarget));

            // Call proc_throttle_sync
            //FAPI_INVOKE_HWP( l_errl, proc_throttle_sync, l_fapiproc_target );

            if (l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR 0x%.8X: proc_throttle_sync HWP returns error",
                          l_errl->reasonCode());

                // Capture the target data in the elog
                ErrlUserDetailsTarget(l_pTarget).addToLog(l_errl);

                // Create IStep error log and cross reference
                //  to error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );

                break;
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS :  proc_throttle_sync HWP( )" );
            }
        }

    } while (0);


    if(l_StepError.isNull())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "SUCCESS : call_mss_thermal_init" );
    }

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
