/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_erepair.C $                */
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
 *  @file call_fabric_erepair.C
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

#include    <pbusLinkSvc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <errl/errlmanager.H>

//@TODO RTC:134079 Re-enable for l2 story
// HWP procedure
// #include <p9_io_xbus_restore_erepair.H>

namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;


// prototype
/**
 *  @brief Try to restore target's endpoints
 *
 *  Runs restore_erepair HWP on each group combination for this target
 *  This hardware procedure should update the bad lane vector and
 *  power down the bad lanes.
 *
 *  @param[in]  i_target       XBUS target endpoint
 *  @param[in]  i_rx_bad_lanes Vector of Rx Bad Lanes
 *  @param[in]  i_tx_bad_lanes Vector of Tx Bad Lanes
 *  @param[out] o_step_error   Failing error logs added to this
 *
 *  @pre Target service must be initialized
 *  @post See "return"
 *  @return uint8_t Number of failures
 *  @retval 0 means successfully restored target endpoint
 *  @retval 4 Means all attempts to restore/erepair failed
 */
uint8_t restore_endpoint(const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_target,
                         const std::vector< uint8_t >& i_rx_bad_lanes,
                         const std::vector< uint8_t >& i_tx_bad_lanes,
                         ISTEP_ERROR::IStepError& o_step_error);

//
//  Wrapper function to call fabric_erepair
//
void*    call_fabric_erepair( void    *io_pArgs )
{
    errlHndl_t l_errl = NULL;
    ISTEP_ERROR::IStepError l_StepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair entry" );

    do {

    // Check if the system can support multiple nest frequencies
    // and if so, see if an SBE Update is required
    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL, "call_fabric_erepair: sys target is NULL" );
    MRW_NEST_CAPABLE_FREQUENCIES_SYS l_mrw_nest_capable;
    l_mrw_nest_capable =
               l_sys->getAttr<ATTR_MRW_NEST_CAPABLE_FREQUENCIES_SYS>();
    if ( l_mrw_nest_capable ==
               MRW_NEST_CAPABLE_FREQUENCIES_SYS_2000_MHZ_OR_2400_MHZ )
    {
        // Call to check Processor SBE SEEPROM Images against NEST_FREQ_MHZ
        // attributes and make any necessary updates
        // TODO-RTC:138226 - add it after SBE is ported to fapi2
        //l_errl = SBE::updateProcessorSbeSeeproms(
        //                SBE::SBE_UPDATE_ONLY_CHECK_NEST_FREQ);

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }
    }

    std::vector<uint8_t> l_endp1_txFaillanes;
    std::vector<uint8_t> l_endp1_rxFaillanes;
    std::vector<uint8_t> l_endp2_txFaillanes;
    std::vector<uint8_t> l_endp2_rxFaillanes;
    uint8_t l_restore_failures = 0;

    EDI_EI_INITIALIZATION::TargetPairs_t l_PbusConnections;
    const uint32_t MaxBusSet = 1;
    TYPE busSet[MaxBusSet] = { TYPE_XBUS }; // TODO RTC:152304 - add TYPE_OBUS

    uint32_t l_count = 0;
    fapi2::TargetType l_tgtType = fapi2::TARGET_TYPE_NONE;

    TARGETING::ATTR_FAPI_NAME_type  l_target_name = {0};

    for (uint32_t i = 0; l_StepError.isNull() && (i < MaxBusSet); i++)
    {
        // grab the unique pairs for this particular type
        l_errl = EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().
                    getPbusConnections( l_PbusConnections, busSet[i] );
        if ( l_errl )
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );

            break;
        }

        for (const auto & l_PbusConnection: l_PbusConnections)
        {
            const TARGETING::Target* l_thisPbusTarget = l_PbusConnection.first;
            const TARGETING::Target* l_connectedPbusTarget =
                                                    l_PbusConnection.second;

            // TODO-RTC:152304 - need to adjust target types if adding OBUS/ABUS
            const fapi2::Target<fapi2::TARGET_TYPE_XBUS> l_fapi_endp1_target
              (const_cast<TARGETING::Target*>(l_thisPbusTarget));

            const fapi2::Target<fapi2::TARGET_TYPE_XBUS> l_fapi_endp2_target
              (const_cast<TARGETING::Target*>(l_connectedPbusTarget));

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "===== " );

            // Get the repair lanes from the VPD
            fapi2::ReturnCode l_rc;
            l_endp1_txFaillanes.clear();
            l_endp1_rxFaillanes.clear();
            l_endp2_txFaillanes.clear();
            l_endp2_rxFaillanes.clear();
/* TODO-RTC:134079 - L2 HWP enablement
            l_rc = erepairGetRestoreLanes(l_fapi_endp1_target,
                                          l_endp1_txFaillanes,
                                          l_endp1_rxFaillanes,
                                          l_fapi_endp2_target,
                                          l_endp2_txFaillanes,
                                          l_endp2_rxFaillanes);

            if(l_rc)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Unable to"
                          " retrieve fabric eRepair data from the VPD");

                // convert the FAPI return code to an err handle
                l_errl = fapiRcToErrl(l_rc);

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_thisPbusTarget).addToLog( l_errl );
                ErrlUserDetailsTarget(l_connectedPbusTarget).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_StepError.addErrorDetails( l_errl);

                // Commit Error
                errlCommit(l_errl, HWPF_COMP_ID);
                break;
            }
*/
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                   "===== Call io_restore_erepair HWP"
                   "%cbus connection ", (i ? 'X' : 'O') );

            if(l_endp1_txFaillanes.size() || l_endp1_rxFaillanes.size())
            {
                // call the io_xbus_restore_erepair HWP to restore eRepair
                // lanes of endp1
                l_restore_failures = restore_endpoint(l_fapi_endp1_target,
                                                      l_endp1_rxFaillanes,
                                                      l_endp1_txFaillanes,
                                                      l_StepError);
            }

            fapi2::toString(l_fapi_endp1_target,
                            l_target_name,
                            sizeof(l_target_name));

            if (l_restore_failures)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "%d restore endpoint attempts to endpoint1 %s failed.",
                    l_restore_failures, l_target_name);
            }
            else
            {
                l_tgtType = l_fapi_endp1_target.getType();

                for(l_count = 0; l_count < l_endp1_txFaillanes.size();l_count++)
                {
                    fapi2::toString(l_fapi_endp1_target,
                                    l_target_name,
                                    sizeof(l_target_name));
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                        " restored Tx lane %d, of %s, of endpoint %s",
                        l_endp1_txFaillanes[l_count],
                        l_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus":
                        "O-Bus", l_target_name);
                }

                for(l_count = 0; l_count < l_endp1_rxFaillanes.size();l_count++)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Successfully"
                        " restored Rx lane %d, of %s, of endpoint %s",
                        l_endp1_rxFaillanes[l_count],
                        l_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus":
                        "O-Bus", l_target_name);
                }
            }

            if(l_endp2_txFaillanes.size() || l_endp2_rxFaillanes.size())
            {
                // call the io_xbus_restore_erepair HWP to restore eRepair
                // lanes of endp2
                l_restore_failures = restore_endpoint(l_fapi_endp2_target,
                                                      l_endp2_rxFaillanes,
                                                      l_endp2_txFaillanes,
                                                      l_StepError);
            }

            fapi2::toString(l_fapi_endp2_target,
                                l_target_name,
                                sizeof(l_target_name));

            if ( l_restore_failures )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "%d restore endpoint attempts to endpoint2 %s failed.",
                    l_restore_failures, l_target_name);

                continue;
            }

            l_tgtType = l_fapi_endp2_target.getType();
            for(l_count = 0; l_count < l_endp2_txFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                      " restored Tx lane %d, of %s, of endpoint %s",
                      l_endp2_txFaillanes[l_count],
                      l_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                      "O-Bus", l_target_name);
            }

            for(l_count = 0; l_count < l_endp2_rxFaillanes.size(); l_count++)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"Successfully"
                      " restored Rx lane %d, of %s, of endpoint %s",
                      l_endp2_rxFaillanes[l_count],
                      l_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT ? "X-Bus" :
                      "O-Bus", l_target_name);
            }
        } // end for l_PbusConnections
    } // end for MaxBusSet

    } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_fabric_erepair exit" );

    return l_StepError.getErrorHandle();
}


uint8_t restore_endpoint(const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_target,
                         const std::vector< uint8_t >& i_rx_bad_lanes,
                         const std::vector< uint8_t >& i_tx_bad_lanes,
                         ISTEP_ERROR::IStepError & o_step_error)
{
    uint8_t o_failures = 0;
    errlHndl_t l_errl = NULL;

    fapi2::TargetType l_tgtType = fapi2::TARGET_TYPE_NONE;
    l_tgtType = i_target.getType();

    // clock group is either 0 or 1
    // need to train both groups and allow for them to differ
    uint8_t l_this_group = 0;
    uint8_t l_connected_group = 0;
    uint8_t l_group_loop = 0;
    for (l_group_loop = 0; l_group_loop < 4; l_group_loop++)
    {
        l_this_group = l_group_loop / 2;      // 0, 0, 1, 1
        l_connected_group = l_group_loop % 2; // 0, 1, 1, 0


        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "Running p9_io_xbus_restore_erepair HWP on "
                 "this %C-BUS target %.8X (groups %d and %d)",
                 (l_tgtType == fapi2::TARGET_TYPE_XBUS_ENDPOINT) ? 'X':'O',
                 TARGETING::get_huid(i_target),
                 l_this_group, l_connected_group );

        /*
         * A HWP that runs Restore eRepair.
         * This procedure should update the
         * bad lane vector and power down the bad lanes.
         */
//@TODO RTC:134079 Re-enable for l2 story
//         FAPI_INVOKE_HWP(l_errl,
//                         p9_io_xbus_restore_erepair,
//                         i_target,
//                         l_this_group,
//                         i_rx_bad_lanes,
//                         i_target,
//                         l_connected_group,
//                         i_tx_bad_lanes);

        if (l_errl)
        {
            o_failures++;
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "ERROR 0x%.8X :  io_xbus_restore_erepair HWP "
              "xbus connection.", l_errl->reasonCode() );

            // capture the target data in the elog
            ErrlUserDetailsTarget(i_target).addToLog( l_errl );

            // Create IStep error log and cross ref error that occurred
            o_step_error.addErrorDetails( l_errl);

            // Commit Error
            errlCommit(l_errl, HWPF_COMP_ID);
            l_errl = NULL;
        }
    }
    return o_failures;
}

};
