/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_post_trainadv.C $          */
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
 *  @file call_fabric_post_trainadv.C
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
//  Wrapper function to call fabric_post_trainadv
//
void*    call_fabric_post_trainadv( void    *io_pArgs )
{
    IStepError  l_StepError;
    //@TODO RTC:134079
/*    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_post_trainadv entry" );

    TargetPairs_t l_PbusConnections;
    TargetPairs_t::iterator l_itr;
    const uint32_t MaxBusSet = 2;
    TYPE busSet[MaxBusSet] = { TYPE_ABUS, TYPE_XBUS };

    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // both ends in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.

    for (uint32_t ii = 0; (!l_errl) && (ii < MaxBusSet); ii++)
    {
        l_errl = PbusLinkSvc::getTheInstance().getPbusConnections(
                                            l_PbusConnections, busSet[ii] );

        for (l_itr = l_PbusConnections.begin();
             l_itr != l_PbusConnections.end();
             ++l_itr)
        {
            const fapi::Target l_fapi_endp1_target(
                   (ii ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->first)));
            const fapi::Target l_fapi_endp2_target(
                   (ii ? TARGET_TYPE_XBUS_ENDPOINT : TARGET_TYPE_ABUS_ENDPOINT),
                   (const_cast<TARGETING::Target*>(l_itr->second)));

            //@TODO RTC:133830  call the HWP with each bus connection
            //FAPI_INVOKE_HWP( l_errl, p9_io_post_trainadv,
            //l_fapi_endp1_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "%s : %cbus connection fabric_post_trainadv. Target 0x%.8X",
                       (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'A'),
                        TARGETING::get_huid(l_itr->first) );
            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->first).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
                // We want to continue the training despite the error, so
                // no break
            }

            //@TODO RTC:133830 call the HWP with each bus connection
            FAPI_INVOKE_HWP( l_errl, io_post_trainadv, l_fapi_endp2_target );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                  "%s : %cbus connection fabric_post_trainadv. Target 0x%.8X",
                       (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'A'),
                        TARGETING::get_huid(l_itr->second) );
            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_itr->second).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
                // We want to continue the training despite the error, so
                // no break
            }
        }
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_post_trainadv exit" );
*/
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}
};
