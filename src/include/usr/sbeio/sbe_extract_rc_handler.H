/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_extract_rc_handler.H $              */
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
#ifndef __SBE_EXTRACT_RC_HANDLER_H
#define __SBE_EXTRACT_RC_HANDLER_H

#include <isteps/hwpisteperror.H>
#include <p9_extract_sbe_rc.H>
#include <p9_get_sbe_msg_register.H>

enum SBE_REG_RETURN
{
    FUNCTION_ERROR      = 0, // Error returned from HWP
    SBE_AT_RUNTIME      = 1, // SBE is at runtime and booted
    SBE_FAILED_TO_BOOT  = 2, // SBE has failed to boot
};

/*************************** State declarations ***************************/
/**
 * @brief This is the initial retry. If we get to a failure, we attempt to
 *  reboot the SBE on the other side.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION same_side_retry_state(
                TARGETING::Target * i_target,uint8_t i_orig_error);

/**
 * @brief This is the other side retry.  If we fail twice on the same side
 *        We attempt to reboot the SBE on the other proc.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION other_side_state(
                TARGETING::Target * i_target,uint8_t i_orig_error);

/**
 * @brief This is the working (passing) exit state.  This state occurs when
 *        we start an SBE correctly within the threshold FSM. Depending on
 *        which state we come from, there are some different functions.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION working_exit_state(
                TARGETING::Target * i_target,uint8_t i_orig_error);

/**
 * @brief This is the failing exit state.  This state only occurs when we
 *        fail on every retry.  In this case we look at where we came from
 *        and either escalate to REIPL_BKP_SEEPROM or we gard and callout
 *        this proc and return to complete the istep.
 *
 * @param[in] i_target     - current proc target
 * @param[in] i_orig_error - Original SBE error
 *
 * @return - pass(0) or specific returned SBE error
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION failing_exit_state(
                TARGETING::Target * i_target,uint8_t i_orig_error);

/**
 * @brief This is the main function of the finite state machine.  It handles
 *        the outputs, current state and next state transitions.
 *
 * @param[in] i_procSide      - Which side we want to try to reboot.
 *                              false/true: current/other
 * @param[in] i_target        - Current Proc target
 * @param[in] i_currentAction - Most recent return value from HWP
 * @param[in] i_previousError - The previous return value from HWP
 */
void sbe_threshold_handler( bool i_procSide,
                            TARGETING::Target * i_target,
                            P9_EXTRACT_SBE_RC::RETURN_ACTION i_currentAction,
                            uint8_t i_previousError );

/**
 * @brief This is the switch case that handles the different actions needed for
 *        each output of the proc_extract_sbe_rc HWP.
 *
 * @param[in] i_target         - current proc target
 * @param[in] i_current_error  - The most recent return value from HWP
 *
 * @return - NULL
 */
void proc_extract_sbe_handler( TARGETING::Target * i_target,
                               uint8_t i_current_error);

/**
 * @brief This function handles the call to the p9_get_sbe_msg_handler.
 *        It determines what state the SBE is in and returns an enum
 *        that describes the future actions needed.
 *
 * @param[in] i_target - current proc target
 *
 * @return  - SBE_REG_RETURN enum value describing the action needed next
 */
SBE_REG_RETURN check_sbe_reg(TARGETING::Target * i_target);

/**
 * @brief This function handles the SBE register value and the actions that
 *        go along with it.  The state machine is handled separately, but
 *        every other instance of check_sbe_reg should be accompanied
 *        by this handler function.
 *
 * @param[in] i_target            - current proc target
 * @param[in] i_sbe_reg           - returned enum value from check_sbe_reg
 * @param[in] i_current_sbe_error - current sbe conditions value
 * @param[in] i_fromStateMachine  - if we are coming from state machine
 *                                  functions or not.
 *
 * @return - sbe returned action
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION  handle_sbe_reg_value(
            TARGETING::Target * i_target,
            SBE_REG_RETURN i_sbe_reg,
            P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_sbe_error,
            bool i_fromStateMachine);

/**
 * @brief This function handles the HWP calls and error logs
 *        associated with them
 *
 * @param[in] i_target            - current proc target
 * @param[in] i_fromStateMachine  - true: from state machine, false: not
 * @param[in] i_current_condition - current sbe conditions value
 *
 * @return - sbe returned action
 *
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION handle_sbe_restart(
            TARGETING::Target * i_target,
            bool i_fromStateMachine,
            P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_condition);

/**
 * @brief  This function handles the SBE timeout and loops
 *         required to start it.
 *
 * @param[out] o_sbeReg       - pointer to the sbe register
 * @param[in]  i_target       - current proc target
 * @param[out] o_returnAction - sbe returned action
 *
 * @return - error, NULL if no error
 */

errlHndl_t sbe_timeout_handler(sbeMsgReg_t * o_sbeReg,
                TARGETING::Target * i_target,
                SBE_REG_RETURN * o_returnAction);

/**
 * @brief This is the switch case that identifies the action needed for the RC
 *        value in an SBE FFDC package.
 *
 * @param[in] i_rc            - RC value from SBE FFDC package
 *
 * @return - pass(0) or specific returned SBE action
 */
P9_EXTRACT_SBE_RC::RETURN_ACTION action_for_ffdc_rc( uint32_t i_rc);

/**
 * @brief  This function handles getting the SBE FFDC.
 *
 * @param[in]     i_target        - current proc target
 *
 * @return - bool for flow control on return to caller, if false, caller should
 *           go on with the processing flow, if true, caller should interrupt
 *           the processing flow and get out of loop or current iteration
 */

bool sbe_get_ffdc_handler(TARGETING::Target * i_target);

/**
 * @brief  This function handles the SBE failed to boot error.
 *
 * @param[in]     i_target        - current proc target
 * @param[in]     i_sbeReg        - sbe register
 *
 * @return - NULL
 */

void sbe_boot_fail_handler(TARGETING::Target * i_target,
                           sbeMsgReg_t i_sbeReg);

/**
 * @brief  This function deals with the mask needed to switch
 *         boot side on the SBE for a given proc
 *
 * @param[in] i_target - current proc target
 *
 * @return - error, NULL if no error
 */
errlHndl_t switch_sbe_sides(TARGETING::Target * i_target);

#endif
