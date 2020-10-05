/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_io_dccal_done.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 *  @file call_proc_io_dccal_done.C
 *
 *  Support file for IStep: proc_io_dccal_done
 *   Ensure the IO PPE has finished iodccal
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <map>

#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>

#include <isteps/hwpisteperror.H>
#include <errl/errludtarget.H>

#include <initservice/isteps_trace.H>

#include <hwas/common/deconfigGard.H>
#include <hwas/common/hwasCommon.H>

#include <sbe/sbeif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/trace.H>
#include <istepHelperFuncs.H>

#include <pbusLinkSvc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlmanager.H>

#include <p10_io_init_done.H>
#include <sys/time.h>

namespace ISTEP_09
{

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;
using namespace HWAS;

//
//  Wrapper function to call proc_io_dccal_done
//
void* call_proc_io_dccal_done(void* const io_pArgs)
{
    ISTEP_ERROR::IStepError l_stepError;
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_io_dccal_done entry");

    // Get all functional proc chip targets
    TARGETING::TargetHandleList l_cpuTargetList;
    TARGETING::getAllChips(l_cpuTargetList, TARGETING::TYPE_PROC);

    for (const auto l_handle : l_cpuTargetList)
    {
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procChip(l_handle);

        errlHndl_t l_errl = nullptr;
        FAPI_INVOKE_HWP(l_errl,
                        p10_io_init_done,
                        l_procChip);

        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "call_proc_io_dccal_done: p10_io_init_done failed on PROC HUID 0x%08x (reason: 0x%x). "
                      TRACE_ERR_FMT,
                      get_huid(l_handle),
                      l_errl->reasonCode(),
                      TRACE_ERR_ARGS(l_errl));

            captureError(l_errl, l_stepError, HWPF_COMP_ID, l_handle);
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_proc_io_dccal_done exit" );

    return l_stepError.getErrorHandle();
}

}
