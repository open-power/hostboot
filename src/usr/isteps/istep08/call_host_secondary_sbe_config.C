/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_secondary_sbe_config.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 *  @file call_host_secondary_sbe_config.C
 *
 *  Support file for IStep: host_secondary_sbe_config
 *   Secondary SBE
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
#include <initservice/mboxRegs.H>
#include <sbe/sbeif.H>
#include <hwas/common/hwas.H>
#include <errl/errludtarget.H>
#include <p10_setup_sbe_config.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace ISTEPS_TRACE;
using namespace TARGETING;
using namespace HWAS;
using namespace INITSERVICE::SPLESS;
using namespace SBE;

namespace ISTEP_08
{
//******************************************************************************
// call_host_secondary_sbe function
//******************************************************************************
void* call_host_secondary_sbe_config(void *io_pArgs)
{
    IStepError  l_stepError;
    errlHndl_t l_errl = nullptr;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_host_secondary_sbe_config");

    Target* l_pMasterProcTarget = nullptr;
    targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    Target* l_sys = nullptr;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != nullptr );

    // Setup the boot flags attribute for the slaves based on the data
    //  from the master proc
    MboxScratch3_t l_scratch3;
    const auto l_scratchRegs = l_sys->getAttrAsStdArr<TARGETING::ATTR_MASTER_MBOX_SCRATCH>();

    l_scratch3.data32 = l_scratchRegs[MboxScratch3_t::REG_IDX];

    // turn off the istep bit
    l_scratch3.fwModeCtlFlags.istepMode = 0;

    // write the attribute
    l_sys->setAttr<ATTR_BOOT_FLAGS>(l_scratch3.data32);

    TRACFCOMP(g_trac_isteps_trace, "ATTR_BOOT_FLAGS=%.8X", l_scratch3.data32);
    if(l_scratch3.fwModeCtlFlags.overrideSecurity)
    {
        TRACFCOMP(g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting security disable on non-master processors.");
    }
    if(l_scratch3.fwModeCtlFlags.allowAttrOverrides)
    {
        TRACFCOMP(g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting allowing Attribute Overrides on "
            "non-master processors even if secure mode.");
    }

    // execute p10_setup_sbe_config.C for non-primary processor targets
    TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        // do not call HWP on master processor
        if (l_cpu_target != l_pMasterProcTarget)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

            TRACFCOMP(g_trac_isteps_trace,
                      "Running p10_setup_sbe_config HWP on processor target %.8X",
                      get_huid(l_cpu_target));

            FAPI_INVOKE_HWP(l_errl, p10_setup_sbe_config, l_fapi2_proc_target);

            if(l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : call p10_setup_sbe_config target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));

                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
                continue;
            }

            l_errl = updateSbeBootSeeprom(l_cpu_target);

            if(l_errl)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "ERROR : updateSbeBootSeeprom target %.8X"
                          TRACE_ERR_FMT,
                          get_huid(l_cpu_target),
                          TRACE_ERR_ARGS(l_errl));

                captureError(l_errl, l_stepError, HWPF_COMP_ID, l_cpu_target);
            }
        }
    } // end of cycling through all processor chips

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_host_secondary_sbe_config");
    return l_stepError.getErrorHandle();

}

};
