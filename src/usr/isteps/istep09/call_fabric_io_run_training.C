/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_io_run_training.C $        */
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

//  Integral and component ID support
#include <stdint.h>                     // uint32_t
#include <hbotcompid.H>                 // HWPF_COMP_ID

//  Tracing support
#include <trace/interface.H>            // TRACFCOMP
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace

//  Targeting support
#include <fapi2_target.H>               // fapi2::Target
#include <target.H>                     // TARGETING::Target

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <isteps/hwpisteperror.H>       // IStepError

//  Pbus link service support
#include <pbusLinkSvc.H>                // TargetPairs_t, PbusLinkSvc

//  HWP call support
#include <istepHelperFuncs.H>           // captureError
#include <istep09/istep09HelperFuncs.H> // trainBusHandler
#include <p9_io_xbus_linktrain.H>       // p9_io_xbus_linktrain

namespace   ISTEP_09
{
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

// helper function prototypes
uint8_t run_linktraining(
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_master_target,
                const fapi2::Target<fapi2::TARGET_TYPE_XBUS> &i_slave_target,
                ISTEP_ERROR::IStepError & o_step_error );

//******************************************************************************
// Wrapper function to call fabric_io_run_training
//******************************************************************************
void* call_fabric_io_run_training( void *io_pArgs )
{
    errlHndl_t  l_err(nullptr);
    IStepError  l_stepError;

    TRACFCOMP(g_trac_isteps_trace,ENTER_MRK"call_fabric_io_run_training entry");

    uint32_t l_numberOfTrainFailures(0);
    EDI_EI_INITIALIZATION::TargetPairs_t l_pbusConnections;
    TYPE l_busSet[] = { TYPE_XBUS, TYPE_OBUS };
    constexpr uint32_t l_maxBusSet(sizeof(l_busSet)/sizeof(TYPE));

    for (uint32_t ii = 0; ii < l_maxBusSet; ++ii)
    {
        l_err = EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().
                    getPbusConnections(l_pbusConnections, l_busSet[ii]);
        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                "ERROR 0x%.8X : getPbusConnections TYPE_%cBUS returns error",
                l_err->reasonCode(), (ii ? 'O':'X') );

            // Capture error and then
            captureError(l_err,
                         l_stepError,
                         HWPF_COMP_ID);

            // Don't continue with a potential bad connection set
            break;
        }

        if (TYPE_XBUS == l_busSet[ii])
        {
            for (const auto & l_pbusConnection: l_pbusConnections)
            {
                // Default the master and slave fapi2 targets
                fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_masterFapi2Target(
                (const_cast<TARGETING::Target*>(l_pbusConnection.first)));

                fapi2::Target <fapi2::TARGET_TYPE_XBUS>
                l_slaveFapi2Target(
                (const_cast<TARGETING::Target*>(l_pbusConnection.second)));

                //Swap master and slave fapi2 targets if master mode is NOT true
                if (l_pbusConnection.first->getAttr
                                  <TARGETING::ATTR_IO_XBUS_MASTER_MODE>() !=
                    fapi2::ENUM_ATTR_IO_XBUS_MASTER_MODE_TRUE)
                {
                    l_masterFapi2Target =
                    (const_cast<TARGETING::Target*>(l_pbusConnection.second));

                    l_slaveFapi2Target =
                    (const_cast<TARGETING::Target*>(l_pbusConnection.first));
                }

                TARGETING::ATTR_FAPI_NAME_type  l_master_target_name = {0};
                TARGETING::ATTR_FAPI_NAME_type  l_slave_target_name = {0};

                l_numberOfTrainFailures = run_linktraining(l_masterFapi2Target,
                                                           l_slaveFapi2Target,
                                                           l_stepError);
                fapi2::toString(l_masterFapi2Target,
                                l_master_target_name,
                                sizeof(l_master_target_name));

                fapi2::toString(l_slaveFapi2Target,
                                l_slave_target_name,
                                sizeof(l_slave_target_name));

                if (l_numberOfTrainFailures)
                {
                    TRACFCOMP(g_trac_isteps_trace,
                        "%d attempts to linktrain XBUS targets failed. "
                        "Master: %s, Slave: %s", l_numberOfTrainFailures,
                        l_master_target_name, l_slave_target_name);
                }
                else
                {
                    TRACFCOMP(g_trac_isteps_trace,
                        "Successfully linktrained XBUS targets. "
                        "Master: %s, Slave: %s",
                        l_master_target_name, l_slave_target_name);
                }
            }  // end for (const auto & l_pbusConnection: l_pbusConnections)
        }  // end if (TYPE_XBUS == l_busSet[ii])
#ifdef CONFIG_SMP_WRAP_TEST
        else if (TYPE_OBUS == l_busSet[ii])
        {
            // Make the FAPI call to p9_io_obus_linktrain
            if (!trainBusHandler(l_busSet[ii],
                                 P9_IO_OBUS_LINKTRAIN,
                                 l_stepError,
                                 HWPF_COMP_ID,
                                 l_pbusConnections))
            {
                break;
            }
        }  // end else if (TYPE_OBUS == l_busSet[ii])
#endif
    } // end for (uint32_t ii = 0; ii < l_maxBusSet; ++ii)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_fabric_io_run_training exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
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
    errlHndl_t l_err(nullptr);

    // group is either 0 or 1
    std::vector<uint8_t> l_groups = {0,1};

    for (auto l_group : l_groups)
    {

        TRACFCOMP(g_trac_isteps_trace,
                 "Running p9_io_xbus_linktrain HWP on "
                 "master target %.8X and "
                 "slave target %.8X on group %d.",
                 TARGETING::get_huid(i_master_target),
                 TARGETING::get_huid(i_slave_target),
                 l_group );

        FAPI_INVOKE_HWP(l_err,
                        p9_io_xbus_linktrain,
                        i_master_target,
                        i_slave_target,
                        l_group);

        if (l_err)
        {
            o_failures++;
            TRACFCOMP(g_trac_isteps_trace,
                 "Failure #%d) ERROR 0x%.8X : p9_io_xbus_linktrain "
                 "HWP on master target %.8X and "
                 "slave target %.8X on group %d.",
                 o_failures, l_err->reasonCode(),
                 TARGETING::get_huid(i_master_target),
                 TARGETING::get_huid(i_slave_target),
                 l_group );

            // Create a target list out of the master and slave target
            TargetHandleList l_targetList =
                  { i_master_target.get(),
                    i_slave_target.get() };

            // Capture error and continue
            captureError(l_err,
                         o_step_error,
                         HWPF_COMP_ID,
                         l_targetList);
        }
    }
    return o_failures;
}
};   // end namespace   ISTEP_09
