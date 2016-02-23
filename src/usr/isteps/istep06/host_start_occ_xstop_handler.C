/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/host_start_occ_xstop_handler.C $       */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>

namespace ISTEP_06
{
void* host_start_occ_xstop_handler( void *io_pArgs )
{
//    errlHndl_t l_err = NULL;
      ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler entry" );

//TODO RTC 125486 add host_start_occ_xstop_handler
#if 0
/// This is a bunch of stuff that was put into P8 and git didn't handle
/// merging correctly.  Some of this may be a useful starting point for
/// enabling OCC checkstop handling.  -- Patrick

                "host_cancontinue_clear entry" );
    errlHndl_t errl = NULL;

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "host_cancontinue_clear: calling activateOCCs" );
    errl = HBOCC::activateOCCs(true);
    if (errl)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "activateOCCs failed");
    }
#endif

                //Create IStep error log and cross reference error that occurred
                l_stepError.addErrorDetails(errl);

                // Commit Error
                errlCommit(errl, HWPF_COMP_ID);

                // Don't keep calling proc_enable_reconfig. Treat as a fatal
                // unexpected unrecoverable error and terminate the IPL.
                break ; // break with error
            }
            // Success
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully ran proc_enable_reconfig HWP on "
                    "MCS target HUID %.8X", l_currMcsHuid);
        } // for

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
        // update firdata inputs for OCC
        TARGETING::Target* masterproc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(masterproc);
        errl = HBOCC::loadHostDataToSRAM(masterproc,
                                            PRDF::MASTER_PROC_CORE);
        if (errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Error returned from call to HBOCC::loadHostDataToSRAM");

            //Create IStep error log and cross reference error that occurred
            l_stepError.addErrorDetails(errl);

            // Commit Error
            errlCommit(errl, HWPF_COMP_ID);
            break;
        }
#endif

    }
    while(0);

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "host_prd_hwreconfig exit" );
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_start_occ_xstop_handler exit" );

    return l_stepError.getErrorHandle();
}

};
