/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_io_run_training.C $        */
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
#include   <targeting/common/attributes.H>
#include   <targeting/common/targetservice.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

#include  <pbusLinkSvc.H>
#include  <fapi2/target.H>
#include  <fapi2/plat_hwp_invoker.H>

// HWP
#include    <p9_io_xbus_linktrain.H>

namespace   ISTEP_09
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;

// helper function prototypes
uint8_t run_linktraining(
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_master_target,
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_slave_target,
                ISTEP_ERROR::IStepError & o_step_error );
//
//  Wrapper function to call fabric_io_run_training
//
void*    call_fabric_io_run_training( void    *io_pArgs )
{

    IStepError  l_StepError;
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training entry" );

    uint8_t l_linktrain_failures = 0;
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
            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_thisPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_PbusConnection.first)));

            const fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_connectedPbusFapi2Target(
                (const_cast<TARGETING::Target*>(l_PbusConnection.second)));


            const TARGETING::ATTR_IO_XBUS_MASTER_MODE_type l_master_mode =
                l_PbusConnection.first->getAttr
                <TARGETING::ATTR_IO_XBUS_MASTER_MODE>();

            TARGETING::ATTR_FAPI_NAME_type  l_master_target_name = {0};
            TARGETING::ATTR_FAPI_NAME_type  l_slave_target_name = {0};
            if (l_master_mode == fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE)
            {
                l_linktrain_failures = run_linktraining(
                                            l_thisPbusFapi2Target,
                                            l_connectedPbusFapi2Target,
                                            l_StepError);
                fapi2::toString(l_thisPbusFapi2Target,
                                l_master_target_name,
                                sizeof(l_master_target_name));
                fapi2::toString(l_connectedPbusFapi2Target,
                                l_slave_target_name,
                                sizeof(l_slave_target_name));
            }
            else
            {
                l_linktrain_failures = run_linktraining(
                                            l_connectedPbusFapi2Target,
                                            l_thisPbusFapi2Target,
                                            l_StepError);
                fapi2::toString(l_connectedPbusFapi2Target,
                                l_master_target_name,
                                sizeof(l_master_target_name));
                fapi2::toString(l_thisPbusFapi2Target,
                                l_slave_target_name,
                                sizeof(l_slave_target_name));
            }

            if (l_linktrain_failures)
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "%d attempts to linktrain XBUS targets failed. "
                    "Master: %s, Slave: %s", l_linktrain_failures,
                    l_master_target_name, l_slave_target_name);
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "Successfully linktrained XBUS targets. "
                    "Master: %s, Slave: %s",
                    l_master_target_name, l_slave_target_name);
            }
        }
    } // end for MaxBusSet

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_fabric_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}




/**
 *  @brief Try to train link between target's endpoints
 *
 *  @param[in]  i_master_target  Master XBUS target endpoint
 *  @param[in]  i_slave_target   Slave  XBUS target endpoint
 *  @param[out] o_step_error   Failing error logs added to this
 *
 *  @pre Target services must be initialized
 *  @post See "return"
 *  @return uint8_t Number of failures (maximum failures = 4)
 *  @retval 4 Means all attempts to train links failed
 */
uint8_t run_linktraining(
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_master_target,
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_slave_target,
                ISTEP_ERROR::IStepError & o_step_error)
{
    uint8_t o_failures = 0;
    errlHndl_t l_errl = NULL;

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
                 "Running p9_io_xbus_linktrain HWP on "
                 "master target %.8X group %d and "
                 "slave target %.8X group %d.",
                 TARGETING::get_huid(i_master_target),
                 l_this_group,
                 TARGETING::get_huid(i_slave_target),
                 l_connected_group );

//@TODO RTC:134079 Re-enable for l2 story
//         FAPI_INVOKE_HWP(l_errl,
//                         p9_io_xbus_linktrain,
//                         i_master_target,
//                         l_this_group,
//                         i_slave_target,
//                         l_connected_group);

        if (l_errl)
        {
            o_failures++;
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                 "Failure #%d) ERROR 0x%.8X : p9_io_xbus_linktrain "
                 "HWP on master target %.8X group %d and "
                 "slave target %.8X group %d.",
                 o_failures, l_errl->reasonCode(),
                 TARGETING::get_huid(i_master_target),
                 l_this_group,
                 TARGETING::get_huid(i_slave_target),
                 l_connected_group );

            // capture the target data in the elog
            ErrlUserDetailsTarget(i_master_target).addToLog( l_errl );
            ErrlUserDetailsTarget(i_slave_target).addToLog( l_errl );

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
