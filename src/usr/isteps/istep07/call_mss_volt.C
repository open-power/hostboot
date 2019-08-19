/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep07/call_mss_volt.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
 *  @file call_mss_volt.C
 *  Contains the wrapper for istep 7.2
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <initservice/initserviceif.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

// Targeting Support
#include    <targeting/common/targetservice.H>
#include    <targeting/common/commontargeting.H>

// Fapi Support
#include    <fapi2.H>
#include    <target_types.H>
#include    <plat_hwp_invoker.H>

#include    <istepHelperFuncs.H>

// HWP
#include <p10_mss_volt.H>

namespace   ISTEP_07
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

void* call_mss_volt( void *io_pArgs )
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt entry" );

    // Check that DDR EFF_CONFIG attributes are set
    bool unused = false;
    set_eff_config_attrs_helper(DEFAULT, unused);


    do
    {
        TargetHandleList l_memportTargetList;
        getAllChiplets(l_memportTargetList, TYPE_MEM_PORT);

        if (l_memportTargetList.size() == 0)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: No MEM_PORT targets found, skipping p10_mss_volt HWP");
            break;
        }

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "Calling p10_mss_volt HWPs on list of %d MEM_PORT targets",
                  l_memportTargetList.size());
        std::vector< fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT> >
            l_memportFapiTargetsList;

        for(auto & l_memport_target : l_memportTargetList)
        {
            fapi2::Target <fapi2::TARGET_TYPE_MEM_PORT>
                l_memport_fapi_target (l_memport_target);

            l_memportFapiTargetsList.push_back(l_memport_fapi_target);

            FAPI_INVOKE_HWP(l_err, p10_mss_volt, l_memportFapiTargetsList);

            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR in p10_mss_volt HWP(): failed on target 0x%.08X. "
                          TRACE_ERR_FMT,
                          get_huid(l_memport_target),
                          TRACE_ERR_ARGS(l_err));

                // Create IStep error log and cross reference to error
                // that occurred
                l_StepError.addErrorDetails(l_err);

                // Commit Error
                errlCommit( l_err, HWPF_COMP_ID );
            }

            l_memportFapiTargetsList.clear();
        }
    }while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_volt exit" );

    return l_StepError.getErrorHandle();
}


};
