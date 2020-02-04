/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_load_ioppe.C $               */
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
 *  @file call_proc_load_ioppe.C
 *
 *  Support file for IStep: proc_load_ioppe
 *   Load IO PPE images to their SRAMS
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
#include <p10_io_load_ppe.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ISTEPS_TRACE;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_proc_load_ioppe()
//******************************************************************************
void* call_proc_load_ioppe(void *io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t l_errl = nullptr;
    char* l_pHcodeImage = nullptr;
    PNOR::SectionInfo_t l_info;
#ifdef CONFIG_SECUREBOOT
    bool unload_hcode_pnor_section = false;
#endif

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_load_ioppe");

    do
    {
        // Load IOPPE image
#ifdef CONFIG_SECUREBOOT
        l_errl = loadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "call_proc_load_ioppe ERROR : "
                      "loadSecureSection(PNOR::HCODE)"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID);
            break;
        }
        unload_hcode_pnor_section = true;
#endif

        // Get HCODE PNOR section info from PNOR RP
        l_errl = PNOR::getSectionInfo(PNOR::HCODE, l_info);
        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "call_proc_load_ioppe ERROR : "
                      "getSectionInfo (PNOR::HCODE)"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID);
            break;
        }

        l_pHcodeImage = reinterpret_cast<char*>(l_info.vaddr);

        TRACFCOMP(g_trac_isteps_trace, "HCODE vaddr = 0x%p ", l_pHcodeImage);

        //  get a list of all the procs in the system
        TargetHandleList l_cpuTargetList;
        getAllChips(l_cpuTargetList, TYPE_PROC);

        for (const auto & l_procChip: l_cpuTargetList)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_procChip);

            TRACFCOMP(g_trac_isteps_trace,
                      "Running call_proc_load_ioppe p10_io_load_ppe HWP on processor target %.8X",
                      get_huid(l_procChip));

            FAPI_INVOKE_HWP(l_errl,
                            p10_io_load_ppe,
                            l_fapi2_proc_target,
                            reinterpret_cast<void*>(l_pHcodeImage));
            if (l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call_proc_load_ioppe p10_io_load_ppe %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_procChip),
                          TRACE_ERR_ARGS(l_errl));
                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_procChip);
            }

        } // end of cycling through all processor chips

    } while (0);

#ifdef CONFIG_SECUREBOOT
    // if we had failed somewhere earlier we try to cleanup here
    // add trace to help debug
    if (unload_hcode_pnor_section == true)
    {
        l_errl = unloadSecureSection(PNOR::HCODE);
        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "call_proc_load_ioppe() - Error from "
                      "unloadSecureSection(PNOR::HCODE)"
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            captureError(l_errl, l_stepError, HWPF_COMP_ID);
        }
    }
#endif

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_load_ioppe");
    return l_stepError.getErrorHandle();
}
};
