/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_cbs_start.C $                */
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
/**
 *  @file call_host_cbs_start.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlmanager.H>

#include <p9_start_cbs.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_host_cbs_start()
//******************************************************************************
void* call_host_cbs_start(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_cbs_start entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    //
    //  Identify the master processor
    //
    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    // loop thru all processors, only call procedure on non-master processors
    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        if (l_cpu_target != l_pMasterProcTarget)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_start_cbs HWP on processor target %.8X",
                     TARGETING::get_huid(l_cpu_target) );

            FAPI_INVOKE_HWP(l_errl, p9_start_cbs, l_fapi2_proc_target);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR : call p9_start_cbs, "
                        "PLID=0x%x", l_errl->plid()  );
                l_stepError.addErrorDetails(l_errl);
                errlCommit(l_errl, HWPF_COMP_ID);
            }
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_cbs_start exit" );
    return l_stepError.getErrorHandle();
}
};
