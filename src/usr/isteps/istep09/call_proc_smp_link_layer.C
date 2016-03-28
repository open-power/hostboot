/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_proc_smp_link_layer.C $           */
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
 *  @file call_proc_smp_link_layer.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlmanager.H>

#include <p9_smp_link_layer.H>

namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;


//
// Wrapper function to call proc_smp_link_layer
//
void*   call_proc_smp_link_layer( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;
    IStepError  l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_smp_link_layer entry" );

    //
    //  get a list of all the procs in the system
    //
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_smp_link_layer HWP on processor target %.8X",
                     TARGETING::get_huid(l_cpu_target) );

        FAPI_INVOKE_HWP(l_errl,p9_smp_link_layer, l_fapi2_proc_target);
        if(l_errl)
        {
          TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     ERR_MRK "call_proc_smp_link_layer> Failed HWP call, "
                     " HUID = 0x%08X",
                     TARGETING::get_huid(l_cpu_target) );
            l_StepError.addErrorDetails(l_errl);
            errlCommit(l_errl, HWPF_COMP_ID);
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_smp_link_layer exit" );

    return l_StepError.getErrorHandle();
}

};
