/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_io_dccal.C $               */
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
 *  @file call_fabric_io_dccal.C
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

#include  <pbusLinkSvc.H>
#include  <fapi2/target.H>
#include  <fapi2/plat_hwp_invoker.H>

// HWP
#include    <p9_io_xbus_dccal.H>

namespace   ISTEP_09
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;
//
//  Wrapper function to call fabric_io_dccal
//
void*    call_fabric_io_dccal( void    *io_pArgs )
{
    errlHndl_t  l_errl = NULL;
    IStepError  l_StepError;

    // We are not running this analog procedure in VPO
    if (TARGETING::is_vpo())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Skip call_fabric_io_dccal in VPO!");
        return l_StepError.getErrorHandle();
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal entry" );

    EDI_EI_INITIALIZATION::TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 1;
    TYPE busSet[MaxBusSet] = { TYPE_XBUS }; // TODO RTC:152304 - add TYPE_OBUS

    for (uint32_t ii = 0; (!l_errl) && (ii < MaxBusSet); ii++)
    {
        l_errl = EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().
                    getPbusConnections(l_PbusConnections, busSet[ii]);
        if (l_errl)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR 0x%.8X : getPbusConnections TYPE_%cBUS returns error",
                l_errl->reasonCode(), (ii ? 'X':'O') );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit the error log
            // Log should be deleted and set to NULL in errlCommit.
            errlCommit(l_errl, HWPF_COMP_ID);

            // Don't continue with a potential bad connection set
            break;
        }

        for (const auto & l_PbusConnection: l_PbusConnections)
        {
            const TARGETING::Target* l_thisPbusTarget = l_PbusConnection.first;
            const TARGETING::Target* l_connectedPbusTarget =
                                                    l_PbusConnection.second;

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_thisPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_thisPbusTarget)));

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_connectedPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_connectedPbusTarget)));

            // group is either 0 or 1
            uint8_t l_group = 0;
            for (l_group = 0; l_group < 2; l_group++)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "Running p9_io_xbus_dccal HWP on "
                         "this %cbus target %.8X, group %d",
                         (ii ? 'X' : 'O'),
                         TARGETING::get_huid(l_thisPbusTarget), l_group );

                FAPI_INVOKE_HWP( l_errl, p9_io_xbus_dccal,
                                 l_thisPbusFapi2Target, l_group );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "%s : %cbus connection p9_io_xbus_dccal "
                    "with group %d. Target 0x%.8X",
                    (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'O'),
                    l_group, TARGETING::get_huid(l_thisPbusTarget) );
                if ( l_errl )
                {
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_thisPbusTarget).addToLog(l_errl);

                    // Create IStep error log and cross ref error that occurred
                    l_StepError.addErrorDetails( l_errl );

                    // Commit Error
                    errlCommit( l_errl, HWPF_COMP_ID );
                    // We want to continue the training despite the error, so
                    // no break
                    l_errl = NULL;
                }

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running p9_io_xbus_dccal HWP on "
                    "connected %cbus target %.8X, group %d",
                    (ii ? 'X' : 'O'),
                    TARGETING::get_huid(l_connectedPbusTarget), l_group );

                // call the HWP with each bus connection
                FAPI_INVOKE_HWP( l_errl, p9_io_xbus_dccal,
                                 l_connectedPbusFapi2Target, l_group);

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "%s : %cbus connection p9_io_xbus_dccal "
                    "with group %d. Target 0x%.8X",
                    (l_errl ? "ERROR" : "SUCCESS"), (ii ? 'X' : 'O'),
                    l_group, TARGETING::get_huid(l_connectedPbusTarget) );
                if ( l_errl )
                {
                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_connectedPbusTarget).
                        addToLog(l_errl);

                    // Create IStep error log and cross ref error that occurred
                    l_StepError.addErrorDetails( l_errl );

                    // Commit Error
                    errlCommit( l_errl, HWPF_COMP_ID );
                    // We want to continue the training despite the error, so
                    // no break
                    l_errl = NULL;
                }
            } // end of groups
        } // end of connection TYPE combinations
    } // end of connection set loop

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
