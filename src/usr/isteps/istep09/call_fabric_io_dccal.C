/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_io_dccal.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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

//  Integral and component ID support
#include <stdint.h>                     // uint32_t
#include <hbotcompid.H>                 // HWPF_COMP_ID

//  Targeting support
#include <fapi2_target.H>               // fapi2::Target
#include <target.H>                     // TARGETING::Target

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <isteps/hwpisteperror.H>       // IStepError

//  Tracing support
#include <trace/interface.H>            // TRACFCOMP
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace
#include <initservice/initserviceif.H>  // isSMPWrapConfig

//  Pbus link service support
#include <pbusLinkSvc.H>                // TargetPairs_t, PbusLinkSvc

//  HWP call support
#include <istepHelperFuncs.H>           // captureError
#include <istep09/istep09HelperFuncs.H> // trainBusHandler
#include <p9_io_xbus_dccal.H>           // p9_io_xbus_dccal

namespace ISTEP_09
{
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

/**
 *  @brief
 *     This function actually makes the FAPI call to p9_io_xbus_dccal.
 *
 *  @param[out] o_stepError   The details of an error, if any, will be added to this
 *  @param[in]  i_dccalMode   XbusDccalMode -- selects what operation to perform
 *  @param[in]  i_fapi2Target fapi2 target
 *  @param[in]  i_group       clock group
 *  @return  True if NO errors occurred, false otherwise
 */
bool configureXbusConnections(IStepError          &o_stepError,
                              const XbusDccalMode  i_dccalMode,
                              const XBUS_TGT       i_fapi2Target,
                              const uint8_t        i_group);

/**
 *  @brief This function explicitly makes the FAPI call for XbusDccalMode
 *         TxZcalRunBus and XbusDccalMod.  This function iterates over the
 *         groups within the iteration of individual targets.
 *
 *  @param[out] o_stepError   The details of an error, if any, will be added to this
 *  @param[in]  i_pbusConnections   XBUS pair connections
 *  @return  True if NO errors occurred, false otherwise
 */
bool configureXbusConnectionsRunBusMode(IStepError &o_stepError,
             const EDI_EI_INITIALIZATION::TargetPairs_t &i_pbusConnections);

/**
 *  @brief This function makes the FAPI call for the given XbusDccalMode.
 *         This function also iterates over the individual targets within
 *         the iteration of individual groups.
 *
 *  @param[out] o_stepError   The details of an error, if any, will be added to this
 *  @param[in]  i_pbusConnections   XBUS pair connections
 *  @param[in]  i_dccalMode   XbusDccalMode -- selects what operation to perform
 *  @return  True if NO errors occurred, false otherwise
 */
bool configureXbusConnectionsMode(IStepError &o_stepError,
             const EDI_EI_INITIALIZATION::TargetPairs_t &i_PbusConnections,
             XbusDccalMode i_dccalMode);

//******************************************************************************
// Wrapper function to call fabric_io_dccal
//******************************************************************************
void* call_fabric_io_dccal( void *io_pArgs )
{
    errlHndl_t  l_errl(nullptr);
    IStepError  l_stepError;

    // We are not running this analog procedure in VPO
    if (TARGETING::is_vpo())
    {
        TRACFCOMP(g_trac_isteps_trace, "Skip call_fabric_io_dccal in VPO!");
        return l_stepError.getErrorHandle();
    }

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_fabric_io_dccal entry");

    EDI_EI_INITIALIZATION::TargetPairs_t l_pbusConnections;
    TYPE l_busSet[] = { TYPE_XBUS, TYPE_OBUS };
    constexpr uint32_t l_maxBusSet = sizeof(l_busSet)/sizeof(TYPE);

    for (uint32_t ii = 0; ii < l_maxBusSet; ++ii)
    {
        l_errl = EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().
                    getPbusConnections(l_pbusConnections, l_busSet[ii]);
        if (l_errl)
        {
            TRACFCOMP(g_trac_isteps_trace,
                "ERROR 0x%.8X : getPbusConnections TYPE_%cBUS returns error",
                l_errl->reasonCode(), (ii ? 'O':'X') );

            // Capture error and then exit
            captureError(l_errl,
                         l_stepError,
                         HWPF_COMP_ID);

            // Don't continue with a potential bad connection set
            break;
        }

        if (TYPE_XBUS == l_busSet[ii])
        {
            if (l_pbusConnections.empty())
            {
                TRACFCOMP(g_trac_isteps_trace, "Connection bus list is empty. "
                          "HWP call p9_io_xbus_dccal will not be called.");
            }

            // if any one of these returns an error then just move on to the next Bus Set
            configureXbusConnectionsRunBusMode(l_stepError,
                                               l_pbusConnections) &&
            configureXbusConnectionsMode(l_stepError,
                                         l_pbusConnections,
                                         XbusDccalMode::RxDccalStartGrp) &&
            configureXbusConnectionsMode(l_stepError,
                                         l_pbusConnections,
                                         XbusDccalMode::RxDccalCheckGrp);
        }  // end if (TYPE_XBUS == l_busSet[ii])
        else if (INITSERVICE::isSMPWrapConfig() &&
                (TYPE_OBUS == l_busSet[ii]))
        {
            // Make the FAPI call to p9_io_obus_dccal
            if (!trainBusHandler(l_busSet[ii],
                                 P9_IO_OBUS_DCCAL,
                                 l_stepError,
                                 HWPF_COMP_ID,
                                 l_pbusConnections))
            {
                break;
            }
        }  // end else if (TYPE_OBUS == l_busSet[ii])
    } // end  for (uint32_t ii = 0; ii < l_maxBusSet; ii++)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_fabric_io_dccal exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

/**
 *  configureXbusConnectionsRunBusMode
 */
bool configureXbusConnectionsRunBusMode(IStepError &o_stepError,
             const EDI_EI_INITIALIZATION::TargetPairs_t &i_PbusConnections)
{
    bool l_retSuccess = true;

    // Group is either 0 or 1
    std::vector<uint8_t> l_groups = {0,1};

    // Iterate over the connections
    for (const auto & l_pbusConnection: i_PbusConnections)
    {
        // Put targets in a container that can be traversed
        std::vector<const TARGETING::Target*> l_targets =
                            { l_pbusConnection.first, l_pbusConnection.second };

        // Iterate over the targets
        for (const auto l_target: l_targets)
        {
            // Convert current target to a fapi2 target
            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_pbusFapi2Target
                (const_cast<TARGETING::Target*>(l_target));

            TRACFCOMP(g_trac_isteps_trace,
                      "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                      "XBUS target %.8X on group %d",
                      XbusDccalMode::TxZcalRunBus,
                      TARGETING::get_huid(l_target),
                      l_groups[0]);

            l_retSuccess = configureXbusConnections(o_stepError,
                                                    XbusDccalMode::TxZcalRunBus,
                                                    l_pbusFapi2Target,
                                                    l_groups[0]);

            if (!l_retSuccess) break; // Don't continue if an error occurred

            for (auto l_group : l_groups)
            {
                TRACFCOMP(g_trac_isteps_trace,
                          "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                          "XBUS target %.8X on group %d",
                          XbusDccalMode::TxZcalSetGrp,
                          TARGETING::get_huid(l_target),
                          l_group);

                l_retSuccess =
                       configureXbusConnections(o_stepError,
                                                XbusDccalMode::TxZcalSetGrp,
                                                l_pbusFapi2Target,
                                                l_group);
                if (!l_retSuccess) break; // Don't continue if an error occurred
            }

            TRACFCOMP(g_trac_isteps_trace,
                      "%s : XBUS connection p9_io_xbus_dccal, target 0x%.8X",
                      (l_retSuccess ? "SUCCESS": "ERROR"),
                      TARGETING::get_huid(l_target));

            if (!l_retSuccess) break; // Don't continue if an error occurred
        } // for (const auto l_target: l_targets)

        if (!l_retSuccess) break; // Don't continue if an error occurred
    } // for (const auto & l_pbusConnection: l_pbusConnections)

    // return true if call was successful, else false
    return l_retSuccess;
}

/**
 *  configureXbusConnectionsMode
 */
bool configureXbusConnectionsMode(IStepError &o_stepError,
             const EDI_EI_INITIALIZATION::TargetPairs_t &i_PbusConnections,
             XbusDccalMode i_dccalMode)
{
    bool l_retSuccess = true;

    // Group is either 0 or 1
    std::vector<uint8_t> l_groups = {0,1};

    // Iterate over the connections
    for (const auto & l_pbusConnection: i_PbusConnections)
    {
        // Put targets in a container that can be traversed
        std::vector<const TARGETING::Target*> l_targets =
                            { l_pbusConnection.first, l_pbusConnection.second };

        // Iterate over the groups
        for (auto l_group : l_groups)
        {
            // Iterate over targets
            for (const auto l_target: l_targets)
            {
                // Convert current target to a fapi2 target
                const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                    l_pbusFapi2Target
                    (const_cast<TARGETING::Target*>(l_target));

                TRACFCOMP(g_trac_isteps_trace,
                          "Running p9_io_xbus_dccal HWP with mode = %.8X on "
                          "XBUS target %.8X on group %d",
                          i_dccalMode,
                          TARGETING::get_huid(l_target),
                          l_group);

                l_retSuccess = configureXbusConnections(o_stepError,
                                                        i_dccalMode,
                                                        l_pbusFapi2Target,
                                                        l_group);
                // Ignore errors in RxDccalCheckGrp mode
                if (XbusDccalMode::RxDccalCheckGrp == i_dccalMode)
                {
                    l_retSuccess = true;
                }

                TRACFCOMP(g_trac_isteps_trace,
                          "%s : XBUS connection p9_io_xbus_dccal, target 0x%.8X",
                          (l_retSuccess ? "SUCCESS" : "ERROR"),
                          TARGETING::get_huid(l_target));
                if (!l_retSuccess) break; // Don't continue if an error occurred
            } // end for (const auto l_target: l_targets)

            if (!l_retSuccess) break; // Don't continue if an error occurred
        } // end for (auto l_group : l_groups)

        if (!l_retSuccess) break; // Don't continue if an error occurred
    } // for (const auto & l_pbusConnection: l_pbusConnections)

    // return true if call was successful, else false
    return l_retSuccess;
}

/**
 *  configureXbusConnections
 */
bool configureXbusConnections(IStepError          &o_stepError,
                              const XbusDccalMode  i_dccalMode,
                              const XBUS_TGT       i_fapi2Target,
                              const uint8_t        i_group)
{
    bool l_retSuccess = true;
    errlHndl_t l_err = nullptr;

    FAPI_INVOKE_HWP(l_err,
                    p9_io_xbus_dccal,
                    i_dccalMode,
                    i_fapi2Target,
                    i_group);

    if ( l_err )
    {
        // Capture error and then exit
        captureError(l_err,
                     o_stepError,
                     HWPF_COMP_ID,
                     i_fapi2Target);

        // Note that this step had an error
        l_retSuccess = false;
    }

   // return true if call was successful, else false
   return l_retSuccess;
}

};   // end namespace ISTEP_09
