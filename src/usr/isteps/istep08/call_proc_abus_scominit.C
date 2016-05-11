/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_abus_scominit.C $            */
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
   @file call_proc_abus_scominit.C
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


namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//*****************************************************************************
// wrapper function to call proc_abus_scominit
//******************************************************************************
void* call_proc_abus_scominit( void    *io_pArgs )
{
    errlHndl_t l_err = NULL;
    IStepError l_StepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
        "call_proc_abus_scominit entry" );

    do
    {
        /* TargetPairs_t is defined in pbusLinkSvc, which is used by
         * other isteps too */
        EDI_EI_INITIALIZATION::TargetPairs_t l_AbusConnections;
        // Note:
        // i_noDuplicate parameter must be set to false because
        // two separate  calls would be needed:
        //    A0 <--> A1
        //    A1 <--> A0
        // only the first target is used to issue SCOMs
        l_err =
        EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().getPbusConnections(
                                          l_AbusConnections, TYPE_ABUS, false);
        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : getPbusConnections ABUS returns error",
                    l_err->reasonCode());

            // Create IStep error log and cross reference to error that occurred
            l_StepError.addErrorDetails( l_err );

            // Commit the error log
            // Log should be deleted and set to NULL in errlCommit.
            errlCommit(l_err, HWPF_COMP_ID);

            // Shouldn't continue on this fatal error (no ABUS), break out
            break;
        }

        // For each ABUS pair
        for (const auto & l_AbusConnection: l_AbusConnections)
        {
            // Make local copies of ABUS targets for ease of use
            TARGETING::Target* l_thisAbusTarget =
                 const_cast<TARGETING::Target*>(l_AbusConnection.first);
            TARGETING::Target* l_connectedAbusTarget =
                 const_cast<TARGETING::Target*>(l_AbusConnection.second);

            // Get this abus fapi2 target
            const fapi2::Target<fapi2::TARGET_TYPE_ABUS> l_thisAbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_thisAbusTarget)));

            // Get connected abus fapi2 target
            const fapi2::Target<fapi2::TARGET_TYPE_ABUS>
                l_connectedAbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_connectedAbusTarget)));

            // Call HW procedure
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running proc_abus_scominit HWP on "
                "Abus target HUID %.8X Connected Abus target HUID %.8X",
                TARGETING::get_huid(l_thisAbusTarget),
                TARGETING::get_huid(l_connectedAbusTarget));

            //@TODO RTC:144076
            //FAPI_INVOKE_HWP(l_err, p9_io_abus_scominit,
            //                l_thisAbusFapi2Target,
            //                l_connectedAbusFapi2Target);
            if (l_err)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR %.8X : proc_abus_scominit HWP returns error. "
                    "Abus target HUID %.8X,  Connected Abus target HUID %.8X",
                    l_err->reasonCode(),
                    TARGETING::get_huid(l_thisAbusTarget),
                    TARGETING::get_huid(l_connectedAbusTarget));

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_thisAbusTarget).addToLog( l_err );
                ErrlUserDetailsTarget(l_connectedAbusTarget).addToLog( l_err );

                // Create IStep error log and cross ref to error that occurred
                l_StepError.addErrorDetails( l_err );
                // We want to continue to the next target instead of exiting,
                // Commit the error log and move on
                // Note: Error log should already be deleted and set to NULL
                // after committing
                errlCommit(l_err, HWPF_COMP_ID);
            }
        } // End abus pair list loop
    } while (0);

    return l_StepError.getErrorHandle();
}
};
