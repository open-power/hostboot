/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_threshold_fsm.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
#include <p9_extract_sbe_rc.H>
#include <sbeio/sbe_retry_handler.H>

namespace SBE_FSM
{

/**
  * @brief This is the initial retry. If we get to a failure, we
  *  attempt to reboot the SBE on the other side.
  *
  * @param[in] i_target     - current proc target
  * @param[in] i_orig_error - Original SBE error
  * @param[in] i_obj        - SbeRetryHandler object
  *
  * @return - pass(0) or specific returned SBE error
  */
P9_EXTRACT_SBE_RC::RETURN_ACTION same_side_retry_state(
                        TARGETING::Target * i_target,uint8_t i_orig_error,
                        SBEIO::SbeRetryHandler * i_obj);

/**
 * @brief This is the other side retry.  If we fail twice on the same
 *        side. We attempt to reboot the SBE on the other proc.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 * @param[in] i_obj        - SbeRetryHandler object
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION other_side_state(
                        TARGETING::Target * i_target,uint8_t i_orig_error,
                        SBEIO::SbeRetryHandler * i_obj);

/**
 * @brief This is the working (passing) exit state.  This state occurs
 *        when we start an SBE correctly within the threshold FSM.
 *        Depending on which state we come from, there are some
 *        different functions.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 * @param[in] i_obj        - SbeRetryHandler object
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION working_exit_state(
                        TARGETING::Target * i_target,uint8_t i_orig_error,
                        SBEIO::SbeRetryHandler * i_obj);

/**
 * @brief This is the failing exit state.  This state only occurs when
 *        we fail on every retry.  In this case we look at where we
 *        came from and either escalate to REIPL_BKP_SEEPROM or we gard
 *        and callout this proc and return to complete the istep.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 * @param[in] i_obj        - SbeRetryHandler object
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION failing_exit_state(
                        TARGETING::Target * i_target,uint8_t i_orig_error,
                        SBEIO::SbeRetryHandler * i_obj);

/**
 * @brief This is the main function of the finite state machine. It
 *        handles the outputs, current state and next
 *        state transitions.
 *
 * @param[in] i_procSide      - Which side we want to try to reboot.
 *                              false/true: current/other
 * @param[in] i_target        - Current Proc target
 * @param[in] i_currentAction - Most recent return value from HWP
 * @param[in] i_previousError - The previous return value from HWP
 * @param[in] i_obj           - SbeRetryHandler object
 */
void sbe_threshold_handler( bool i_procSide,
                            TARGETING::Target * i_target,
                            P9_EXTRACT_SBE_RC::RETURN_ACTION i_currentAction,
                            uint8_t i_previousError,
                            SBEIO::SbeRetryHandler * i_obj );

}; // End of namespace SBE_FSM
