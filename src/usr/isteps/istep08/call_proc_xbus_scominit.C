/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_xbus_scominit.C $            */
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
   @file call_proc_xbus_scominit.C
 *
 *  Support file for IStep: nest_chiplets
 *   Nest Chiplets
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */
/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>

#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include  <pbusLinkSvc.H>
#include  <fapi2/target.H>
#include  <fapi2/plat_hwp_invoker.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>
//#include <p9_io_xbus_scominit.H> // TODO-RTC:149687 - enable when ready

namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//******************************************************************************
// wrapper function to call proc_xbus_scominit
//******************************************************************************
void* call_proc_xbus_scominit( void *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_proc_xbus_scominit entry" );
    do
    {
        EDI_EI_INITIALIZATION::TargetPairs_t l_XbusConnections;
        // Note:
        // i_noDuplicate parameter must be set to false because
        // two separate  calls would be needed:
        //    X0 <--> X1
        //    X1 <--> X0
        // only the first target is used to issue SCOMs
        l_err =
        EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                                          l_XbusConnections, TYPE_XBUS, false);
        if (l_err)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "ERROR 0x%.8X : getPbusConnections XBUS returns error",
                     l_err->reasonCode() );

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );
            // Commit the error log
            // Log should be deleted and set to NULL in errlCommit.
            errlCommit(l_err, HWPF_COMP_ID);

            // Shouldn't continue on this fatal error (no XBUS), break out
            break;
        }

        for (const auto & l_XbusConnection: l_XbusConnections)
        {
            const TARGETING::Target* l_thisXbusTarget = l_XbusConnection.first;
            const TARGETING::Target* l_connectedXbusTarget =
                                                    l_XbusConnection.second;

            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                l_thisXbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_thisXbusTarget)));

            const fapi2::Target<fapi2::TARGET_TYPE_XBUS>
                l_connectedXbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_connectedXbusTarget)));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_io_xbus_scominit HWP on "
                     "This XBUS target %.8X - Connected XBUS target %.8X",
                     TARGETING::get_huid(l_thisXbusTarget),
                     TARGETING::get_huid(l_connectedXbusTarget) );

            // TODO-RTC:149687
            //FAPI_INVOKE_HWP(l_err, p9_io_xbus_scominit,
            //               l_thisXbusFapi2Target, l_connectedXbusFapi2Target);
            if (l_err)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X : proc_xbus_scominit HWP returned error. "
                        "This XBUS target %.8X - Connected XBUS target  %.8X",
                        l_err->reasonCode(),
                        TARGETING::get_huid(l_thisXbusTarget),
                        TARGETING::get_huid(l_connectedXbusTarget) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_thisXbusTarget).addToLog( l_err );
                ErrlUserDetailsTarget(l_connectedXbusTarget).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }
        } // end of going through pairs

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "call_proc_xbus_scominit exit" );

    return l_StepError.getErrorHandle();
}

};
