/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_host_set_mem_volt.C $             */
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
 *  @file call_host_set_mem_volt.C
 *
 *  Support file for IStep: host_set_mem_volt
 *    Enable voltages on the DDIMMS
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <errl/errlmanager.H>
#include <istepHelperFuncs.H>           // captureError

//  Tracing support
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace

//  FAPI support
#include <fapi2.H>
#include <plat_hwp_invoker.H>
#include <isteps/hwpisteperror.H>       // IStepError

//  HWP call support
#include <chipids.H>                    // for EXPLORER ID
#include <pmic_enable.H>

using namespace ISTEPS_TRACE;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_11
{

void* call_host_set_mem_volt (void *io_pArgs)
{
    TRACFCOMP(
    g_trac_isteps_trace, ENTER_MRK"call_host_set_mem_volt");

    errlHndl_t  l_errl = nullptr;
    IStepError l_StepError;

    // Create a vector of Target pointers
    TargetHandleList l_chipList;

    // Get a list of all of the functioning ocmb chips
    getAllChips(l_chipList, TYPE_OCMB_CHIP, true);

    for (const auto & l_ocmb: l_chipList)
    {
        // PMICs are not present on Gemini, so skip this enable call
        // check EXPLORER first as this is most likely the configuration
        uint32_t chipId = l_ocmb->getAttr<ATTR_CHIP_ID>();
        if (chipId == POWER_CHIPID::EXPLORER_16)
        {
            TRACFCOMP( g_trac_isteps_trace,
                       "call_host_set_mem_volt: "
                       "calling pmic_enable on OCMB 0x%.8X",
                       get_huid(l_ocmb) );

            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>l_fapi2_target(l_ocmb);

            // Invoke procedure
            FAPI_INVOKE_HWP(l_errl, pmic_enable, l_fapi2_target);
        }

        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "ERROR : call_host_set_mem_volt HWP(): "
                      "pmic_enable failed on target 0x%08X."
                      TRACE_ERR_FMT,
                      get_huid(l_ocmb),
                      TRACE_ERR_ARGS(l_errl));

            // Capture error and continue to next OCMB
            captureError(l_errl, l_StepError, HWPF_COMP_ID, l_ocmb);
        }
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_set_mem_volt");
    return l_StepError.getErrorHandle();
}

};
