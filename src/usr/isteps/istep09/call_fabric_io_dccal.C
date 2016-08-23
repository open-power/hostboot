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

        //This HWP is broken into substeps, we want to deconfigure
        //bad targets if one of the substeps fails so check this error
        // between each substep.
        bool l_subStepError = false;

        for (const auto & l_PbusConnection: l_PbusConnections)
        {
            bool l_firstTargetValid = true;
            bool l_secondTargetValid = true;

            //Set up fapi2 targets for each end of the connections
            const TARGETING::Target* l_firstPbusTarget = l_PbusConnection.first;
            const TARGETING::Target* l_secondPbusTarget = l_PbusConnection.second;

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_firstPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_firstPbusTarget)));
            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_secondPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_secondPbusTarget)));

            // group is either 0 or 1
            std::vector<uint8_t> l_groups = {0,1};
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Running p9_io_xbus_dccal HWP  on "
                        "this %cbus target %.8X on all groups",
                        (ii ? 'X' : 'O'),
                        TARGETING::get_huid(l_firstPbusTarget) );

            FAPI_INVOKE_HWP( l_errl,
                           p9_io_xbus_dccal,
                           XbusDccalMode::TxZcalRunBus,
                           l_firstPbusFapi2Target,
                           l_groups[0] );

            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_firstPbusFapi2Target).addToLog(l_errl);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
                l_errl = NULL;

                //Note that the first target is invalid
                l_firstTargetValid = false;
                //Note that this substep had an error
                l_subStepError = true;

            }

            if(l_firstTargetValid)
            {
                for(auto l_group : l_groups)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                p9_io_xbus_dccal,
                                XbusDccalMode::TxZcalSetGrp,
                                     l_firstPbusFapi2Target,
                                l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_firstPbusFapi2Target).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        l_errl = NULL;
                        //Note that this target is invalid
                        l_firstTargetValid = false;
                        //Note that this substep had an error
                        l_subStepError = true;
                        //if any of the groups have an error just break out
                        break;
                    }
                }
            }

           TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           "Running p9_io_xbus_dccal HWP on "
           "this %cbus target %.8X on all groups",
           (ii ? 'X' : 'O'),
           TARGETING::get_huid(l_secondPbusTarget) );

           FAPI_INVOKE_HWP( l_errl,
                            p9_io_xbus_dccal,
                            XbusDccalMode::TxZcalRunBus,
                            l_secondPbusFapi2Target,
                            l_groups[0] );

            if ( l_errl )
            {
                // capture the target data in the elog
                ErrlUserDetailsTarget(l_secondPbusFapi2Target).addToLog(l_errl);

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
                l_errl = NULL;
                // Note that the second target is invalid
                l_secondTargetValid = false;
                // Note that an error was detected during this substep
                l_subStepError = true;

            }

            if(l_secondTargetValid)
            {
                for(auto l_group : l_groups)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                    p9_io_xbus_dccal,
                                    XbusDccalMode::TxZcalSetGrp,
                                    l_secondPbusFapi2Target,
                                    l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_secondPbusFapi2Target).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );

                        //set l_errl to null for future use
                        l_errl = NULL;

                        //one of the channels is bad on this target, its not valid
                        l_secondTargetValid = false;

                        //if any errors were found on this substep, we will skip the remainder
                        l_subStepError = true;

                        //if any of the groups have an error just break out
                        break;
                    }
                }
            }
        }

        if(l_subStepError)
        {
            //Try the next connection set
            continue;
        }

        for (const auto & l_PbusConnection: l_PbusConnections)
        {
            //Initially assume both targets are valid
            uint8_t l_firstTargetValid = true;
            uint8_t l_secondTargetValid = true;

            //Set up fapi2 targets for each end of the connections
            const TARGETING::Target* l_firstPbusTarget = l_PbusConnection.first;
            const TARGETING::Target* l_secondPbusTarget = l_PbusConnection.second;

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_firstPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_firstPbusTarget)));
            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_secondPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_secondPbusTarget)));

            // group is either 0 or 1
            std::vector<uint8_t> l_groups = {0,1};

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                    "this %cbus target %.8X on all groups",
                    (ii ? 'X' : 'O'),
                    XbusDccalMode::RxDccalStartGrp,
                    TARGETING::get_huid(l_firstPbusTarget) );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                        "this %cbus target %.8X on all groups",
                        (ii ? 'X' : 'O'),
                        XbusDccalMode::RxDccalStartGrp,
                        TARGETING::get_huid(l_secondPbusTarget) );

            for(auto l_group : l_groups)
            {
                if(l_firstTargetValid)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                    p9_io_xbus_dccal,
                                    XbusDccalMode::RxDccalStartGrp,
                                    l_firstPbusFapi2Target,
                                    l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_firstPbusTarget).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        l_errl = NULL;

                        //Note the error on this substep
                        l_subStepError = true;
                        //Note that first target is invalid for next group
                        l_firstTargetValid = false;
                    }
                }

                if(l_secondTargetValid)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                    p9_io_xbus_dccal,
                                    XbusDccalMode::RxDccalStartGrp,
                                    l_secondPbusFapi2Target,
                                    l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_secondPbusTarget).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        l_errl = NULL;

                        //Note the error on this substep
                        l_subStepError = true;
                        //Note that second target is invalid for next group
                        l_secondTargetValid = false;
                    }
                }
            }
        }

        if(l_subStepError)
        {
            //Try the next connection set
            continue;
        }

        for (const auto & l_PbusConnection: l_PbusConnections)
        {
            //Initially assume both targets are valid
            uint8_t l_firstTargetValid = true;
            uint8_t l_secondTargetValid = true;

            //Set up fapi2 targets for each end of the connections
            const TARGETING::Target* l_firstPbusTarget = l_PbusConnection.first;
            const TARGETING::Target* l_secondPbusTarget = l_PbusConnection.second;

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
            l_firstPbusFapi2Target(
            (const_cast<TARGETING::Target*>(l_firstPbusTarget)));
            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
            l_secondPbusFapi2Target(
            (const_cast<TARGETING::Target*>(l_secondPbusTarget)));

            // group is either 0 or 1
            std::vector<uint8_t> l_groups = {0,1};
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                        "this %cbus target %.8X on all groups",
                        (ii ? 'X' : 'O'),
                        XbusDccalMode::RxDccalCheckGrp,
                        TARGETING::get_huid(l_firstPbusFapi2Target) );

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                        "this %cbus target %.8X on all groups",
                        (ii ? 'X' : 'O'),
                        XbusDccalMode::RxDccalCheckGrp,
                        TARGETING::get_huid(l_secondPbusFapi2Target) );

            for(auto l_group : l_groups)
            {
                if(l_firstTargetValid)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                    p9_io_xbus_dccal,
                                    XbusDccalMode::RxDccalCheckGrp,
                                    l_firstPbusFapi2Target,
                                    l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_firstPbusFapi2Target).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        // We want to continue the training despite the error, so
                        // no break
                        l_errl = NULL;
                        //Note that first target is invalid for next group
                        l_firstTargetValid = false;
                    }
                }

                if(l_secondTargetValid)
                {
                    FAPI_INVOKE_HWP( l_errl,
                                    p9_io_xbus_dccal,
                                    XbusDccalMode::RxDccalCheckGrp,
                                    l_secondPbusFapi2Target,
                                    l_group );

                    if ( l_errl )
                    {
                        // capture the target data in the elog
                        ErrlUserDetailsTarget(l_secondPbusFapi2Target).addToLog(l_errl);

                        // Create IStep error log and cross ref error that occurred
                        l_StepError.addErrorDetails( l_errl );

                        // Commit Error
                        errlCommit( l_errl, HWPF_COMP_ID );
                        // We want to continue the training despite the error, so
                        // no break
                        l_errl = NULL;
                        //Note that second target is invalid for next group
                        l_secondTargetValid = false;
                    }
                }
            }
        }
    } // end of connection set loop

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
