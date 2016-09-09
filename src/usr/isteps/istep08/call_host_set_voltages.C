/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_set_voltages.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>
// targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <errl/errlmanager.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

#include <p9_setup_evid.H>


#include <hbToHwsvVoltageMsg.H>

using namespace TARGETING;
using namespace ERRORLOG;
using namespace ISTEP_ERROR;

namespace ISTEP_08
{

//*****************************************************************************
// call_host_set_voltages()
//*****************************************************************************
void* call_host_set_voltages(void *io_pArgs)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_set_voltages enter");

    errlHndl_t l_err = NULL;
    TargetHandleList l_procList;
    IStepError l_stepError;
    bool l_noError = true;
    do
    {
        // Get the system's procs
        getAllChips( l_procList,
                     TYPE_PROC,
                     true ); // true: return functional procs

        // Iterate over the found procs calling p9_setup_evid
        for( const auto & l_procTarget : l_procList )
        {
            // Cast to fapi2 target
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                        l_fapiProcTarget( l_procTarget );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Running p9_setup_evid HWP on processor target %.8X",
                        get_huid( l_procTarget ) );

            FAPI_INVOKE_HWP( l_err,
                             p9_setup_evid,
                             l_fapiProcTarget,
                             APPLY_VOLTAGE_SETTINGS);

            if( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Error running p9_setup_evid on processor target %.8X",
                        get_huid( l_procTarget ) );
                l_stepError.addErrorDetails( l_err );

                errlCommit( l_err, HWPF_COMP_ID );
                l_noError = false;
            }
        } // Processor Loop

        if( l_noError )
        {
#if 0 // TODO RTC: 160517 - Uncomment the call to send processor voltage data to HWSV
            //If FSP is present, send voltage information to HWSV
            if( INITSERVICE::spBaseServicesEnabled() )
            {
                l_err = platform_set_nest_voltages();

                if( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Error in call_host_set_voltages::platform_set_nest_voltages()")

                    // Create IStep error log and cross reference occurred error
                    l_stepError.addErrorDetails( l_err );

                    //Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );

                }
            }
#endif
        }
    }while( 0 );


    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
            "call_host_set_voltages exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

}; // end namespace
