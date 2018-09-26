/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_set_voltages.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

//  Component ID support
#include <hbotcompid.H>                // HWPF_COMP_ID

//  TARGETING support
#include <attributeenums.H>            // TYPE_PROC

//  Error handling support
#include <isteps/hwpisteperror.H>      // ISTEP_ERROR::IStepError
#include <errl/errlentry.H>            // errlHndl_t
#include <istepHelperFuncs.H>          // captureError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

//  HWP call support
#include <p9_setup_evid.H>
#include <nest/nestHwpHelperFuncs.H>   // fapiHWPCallWrapperForChip
#include <hbToHwsvVoltageMsg.H>        // platform_set_nest_voltages

//  Init Service support
#include <initservice/initserviceif.H> // INITSERVICE::spBaseServicesEnabled

namespace ISTEP_08
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//*****************************************************************************
// Wrapper function to call host_set_voltages
//*****************************************************************************
void* call_host_set_voltages(void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_set_voltages enter");

    errlHndl_t l_err(nullptr);
    IStepError l_stepError;

    do
    {
        TargetHandleList l_procList;
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

            TRACFCOMP(g_trac_isteps_trace,
                      "Running p9_setup_evid HWP on processor target %.8X",
                      get_huid( l_procTarget ) );

            FAPI_INVOKE_HWP(l_err,
                            p9_setup_evid,
                            l_fapiProcTarget,
                            APPLY_VOLTAGE_SETTINGS);

            if( l_err )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "Error running p9_setup_evid on processor target %.8X",
                        get_huid( l_procTarget ) );

                // Capture error and continue
                captureError(l_err,
                             l_stepError,
                             HWPF_COMP_ID,
                             l_procTarget);
            }

            TRACFCOMP(g_trac_isteps_trace, "Done with p9_setup_evid" );
        } // Processor Loop

        // Exit if FAPI call failed or returned an error
        if (!l_stepError.isNull())
        {
            break;
        }

        // If no error occurred and FSP is present,
        // send voltage information to HWSV
        if (INITSERVICE::spBaseServicesEnabled())
        {
            l_err = platform_set_nest_voltages();

            if( l_err )
            {
                TRACFCOMP(g_trac_isteps_trace,
                 "Error in call_host_set_voltages::platform_set_nest_voltages()")

                // Capture error and continue
                captureError(l_err,
                             l_stepError,
                             ISTEP_COMP_ID);
            }
        }

        // Exit if setting voltage failed or returned an error
        if (!l_stepError.isNull())
        {
            break;
        }

        if (INITSERVICE::isSMPWrapConfig())
        {
            // Make the FAPI call to p9_fbc_eff_config_links
            // Make the FAPI call to p9_sys_chiplet_scominit, if previous call succeeded
            fapiHWPCallWrapperHandler(P9_FBC_EFF_CONFIG_LINKS_F_T, l_stepError,
                                      HWPF_COMP_ID, TYPE_PROC)                  &&
            fapiHWPCallWrapperHandler(P9_SYS_CHIPLET_SCOMINIT, l_stepError,
                                      HWPF_COMP_ID, TYPE_PROC)                  &&
            // Make call to p9_io_obus_image_build
            fapiHWPCallWrapperHandler(P9_IO_OBUS_IMAGE_BUILD, l_stepError,
                                      HWPF_COMP_ID, TYPE_OBUS)                  &&
            // Make call to p9_io_xbus_image_build
            fapiHWPCallWrapperHandler(P9_IO_XBUS_IMAGE_BUILD, l_stepError,
                                      HWPF_COMP_ID, TYPE_PROC);
        }
    }while( 0 );


    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_set_voltages exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};   // end namespace ISTEP_08
