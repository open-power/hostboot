/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_iohs_enable_ridi.C $         */
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
 *  @file call_proc_iohs_enable_ridi.C
 *
 *  Support file for IStep: proc_iohs_enable_ridi
 *   Enable RI/DI for iohs
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
#include <nest/nestHwpHelperFuncs.H>
#include <p10_iohs_enable_ridi.H>
#include <p10_chiplet_enable_ridi.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_proc_iohs_enable_ridi()
//******************************************************************************
void* call_proc_iohs_enable_ridi(void *io_pArgs)
{
    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_iohs_enable_ridi");

    IStepError  l_stepError;
    errlHndl_t l_errl = nullptr;

    //  get a list of all the procs in the system
    //
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto & l_procChip: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (l_procChip);

        TRACFCOMP(g_trac_isteps_trace,
                  "Running call_proc_iohs_enable_ridi p10_chiplet_enable_ridi HWP on processor target %.8X",
                  get_huid(l_procChip));

        // Call p10_chiplet_enable_ridi hwp
        FAPI_INVOKE_HWP( l_errl, p10_chiplet_enable_ridi, l_fapi2_proc_target);

        if(l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : call p10_chiplet_enable_ridi HWP(): failed on target 0x%08X. "
                       TRACE_ERR_FMT,
                       get_huid(l_procChip),
                       TRACE_ERR_ARGS(l_errl));

            // Capture Error
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_procChip);
            // Run HWP on all procs even if one reports an error
            continue;
        }

        TRACFCOMP(g_trac_isteps_trace,
                  "Running call_proc_iohs_enable_ridi p10_iohs_enable_ridi HWP on processor target %.8X",
                  get_huid(l_procChip));

        FAPI_INVOKE_HWP(l_errl,
                        p10_iohs_enable_ridi,
                        l_fapi2_proc_target);
        if(l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : call_proc_iohs_enable_ridi p10_iohs_enable_ridi target %.8X"
                      TRACE_ERR_FMT,
                      get_huid(l_procChip),
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_procChip);
            // Run HWP on all procs even if one reports an error
            continue;
        }

    } // end of cycling through all processor chips

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_iohs_enable_ridi");
    return l_stepError.getErrorHandle();
}
};
