/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_set_voltages.C $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
 * @file call_host_set_voltages.C
 *
 * Support file for IStep: host_set_voltages
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <p10_setup_evid.H>

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
    IStepError l_stepError;
    errlHndl_t l_err = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_set_voltages");

    do
    {
        TargetHandleList l_procList;
        // Get the system's procs
        getAllChips(l_procList,
                     TYPE_PROC,
                     true); // true: return functional procs

        // Iterate over the found procs calling p10_setup_evid
        for( const auto & l_procTarget : l_procList )
        {
            // Cast to fapi2 target
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                        l_fapiProcTarget( l_procTarget );

            TRACFCOMP(g_trac_isteps_trace,
                      "Running p10_setup_evid HWP on processor target %.8X",
                      get_huid(l_procTarget));

            FAPI_INVOKE_HWP(l_err,
                            p10_setup_evid,
                            l_fapiProcTarget,
                            APPLY_VOLTAGE_SETTINGS);

            if(l_err)
            {
                TRACFCOMP(g_trac_isteps_trace,
                        "Error running p10_setup_evid on processor target %.8X"
                        TRACE_ERR_FMT,
                        get_huid(l_procTarget),
                        TRACE_ERR_ARGS(l_err));

                // Capture error and continue
                captureError(l_err, l_stepError, HWPF_COMP_ID, l_procTarget);
            }

            TRACFCOMP(g_trac_isteps_trace, "Done with p10_setup_evid");
        } // Processor Loop

        // Exit if setting voltage failed or returned an error
        if (!l_stepError.isNull())
        {
            break;
        }

    }while( 0 );


    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_set_voltages");
    return l_stepError.getErrorHandle();
}

};   // end namespace ISTEP_08
