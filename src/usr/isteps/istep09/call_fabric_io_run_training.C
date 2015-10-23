/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_io_run_training.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  @file call_fabric_io_run_training.C
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

namespace   ISTEP_09
{


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;
//
//  Wrapper function to call fabric_io_run_training
//
void*    call_fabric_io_run_training( void    *io_pArgs )
{

    IStepError  l_StepError;
    //@TODO RTC:134079
/*    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training entry" );

    TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 2;

    // Note: Run XBUS first to match with Cronus
    TYPE busSet[MaxBusSet] = { TYPE_XBUS, TYPE_ABUS };

    for (uint32_t i = 0; l_StepError.isNull() && (i < MaxBusSet); i++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[i] );

        if ( l_errl )
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        for (TargetPairs_t::const_iterator l_itr = l_PbusConnections.begin();
             (l_StepError.isNull()) && (l_itr != l_PbusConnections.end());
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (i ? TARGET_TYPE_ABUS_ENDPOINT : TARGET_TYPE_XBUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (i ? TARGET_TYPE_ABUS_ENDPOINT : TARGET_TYPE_XBUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            //@TODO RTC:133830  call the HWP with each bus connection
            //FAPI_INVOKE_HWP( l_errl, p9_io_run_training,
            //                 l_fapi_endp1_target, l_fapi_endp2_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection io_run_training",
                       (l_errl ? "ERROR" : "SUCCESS"),
                       (i ? 'A' : 'X') );

            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};
