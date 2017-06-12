/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/sbe_extract_rc_handler.C $             */
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
/**
 * @file sbe_extract_rc_handler.C
 *
 * Handle a SBE extract rc error.  We use a switch-case to determine
 * what action to take, and a finite state machine to control the
 * threshold actions.
 */

/*****************************************************************************/
// Includes
/*****************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <p9_extract_sbe_rc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <isteps/istep_reasoncodes.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <errl/errludtarget.H>
#include <sys/time.h>
#include <util/misc.H>
#include <ipmi/ipmiwatchdog.H>

#include <p9_start_cbs.H>
#include <p9_get_sbe_msg_register.H>
#include <p9_perv_scom_addresses.H>
#include "sbe_extract_rc_handler.H"
#include <sbe/sbe_update.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_sp_intf.H>
#include <../../usr/sbeio/sbe_fifodd.H>
#include <../../usr/sbeio/sbe_fifo_buffer.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbeioreasoncodes.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;

/* Global switch sides count */
static uint8_t g_switch_sides_count = 0;

/* array and enum must be in sync */
P9_EXTRACT_SBE_RC::RETURN_ACTION (* sbe_handler_state[])(
                TARGETING::Target * i_target,
                uint8_t i_prev_error) =
      { same_side_retry_state, // SAME_SIDE_RETRY
        other_side_state,      // OTHER_SIDE
        working_exit_state,    // WORKING_EXIT
        failing_exit_state };  // FAILING_EXIT

enum STATE_CODES { SAME_SIDE_RETRY,
                   OTHER_SIDE,
                   WORKING_EXIT,
                   FAILING_EXIT };
struct transition
{
    enum STATE_CODES src_state;
    uint8_t ret_code;
    enum STATE_CODES dst_state;
};

/* transistions from end states aren't needed */
struct transition state_transitions[] = {
    { SAME_SIDE_RETRY,   0,   WORKING_EXIT },
    { SAME_SIDE_RETRY,   1,   OTHER_SIDE },
    { OTHER_SIDE,        0,   WORKING_EXIT },
    { OTHER_SIDE,        1,   FAILING_EXIT }
};

enum STATE_CODES get_next_state( enum STATE_CODES i_src, uint8_t i_rc )
{
    return (state_transitions[ i_src*2 + i_rc ]).dst_state;
}

void sbe_threshold_handler( bool i_procSide,
                          TARGETING::Target * i_target,
                          P9_EXTRACT_SBE_RC::RETURN_ACTION i_initialAction,
                          uint8_t i_previousError )
{
    // Note: This is set up as a finite state machine since all actions are
    //       connected and most of them lead to another.

    STATE_CODES cur_state = SAME_SIDE_RETRY;

    // The initial state depends on our inputs
    if( i_procSide )
    {
        cur_state = OTHER_SIDE;
    }

    // Setup the rest of the FSM
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_returnedAction;
    P9_EXTRACT_SBE_RC::RETURN_ACTION (*state_fcn)(TARGETING::Target * i_target,
                    uint8_t i_orig_error);

    // Begin FSM
    for(;;)
    {
#ifdef CONFIG_BMC_IPMI
        // This could potentially take awhile, reset watchdog
        errlHndl_t l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Inside sbe_extract_rc_handler FSM, "
                      "Resetting watchdog");
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif

        state_fcn = sbe_handler_state[cur_state];
        l_returnedAction = state_fcn(i_target, i_initialAction);

        if( cur_state == WORKING_EXIT || cur_state == FAILING_EXIT)
        {
            break;
        }
        // If the returned action was 0, the return is a pass: 0,
        // Else, the SBE did not start cleanly and we continue
        cur_state = get_next_state(cur_state,
                !(P9_EXTRACT_SBE_RC::ERROR_RECOVERED == l_returnedAction));

    }

    return;

}

P9_EXTRACT_SBE_RC::RETURN_ACTION same_side_retry_state(
                            TARGETING::Target * i_target,
                            uint8_t i_orig_error)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Running p9_start_cbs HWP on processor target %.8X",
               TARGETING::get_huid(i_target));

    // We don't actually need an accurate p9_extract_sbe_rc value if
    // we're coming from the state machine, so we send in a pass.
    return handle_sbe_restart(i_target,true,
                    P9_EXTRACT_SBE_RC::ERROR_RECOVERED);
}

P9_EXTRACT_SBE_RC::RETURN_ACTION other_side_state(
                         TARGETING::Target * i_target,
                         uint8_t i_orig_error)
{
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Running p9_start_cbs HWP on processor target %.8X",
               TARGETING::get_huid(i_target));

    errlHndl_t l_errl = NULL;

    // Run HWP, but from the other side.
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    l_errl = switch_sbe_sides(i_target);
    if(l_errl)
    {
        errlCommit(l_errl,ISTEP_COMP_ID);
        return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
    }

    // We don't actually need an accurate p9_extract_sbe_rc value if
    // we're coming from the state machine, so we send in a pass.
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
            handle_sbe_restart(i_target, true,
                    P9_EXTRACT_SBE_RC::ERROR_RECOVERED);
    if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>())
    {
        // Information log
        /*@
         * @errortype
         * @moduleid    MOD_SBE_THRESHOLD_FSM
         * @reasoncode  RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP
         * @userdata1   SBE status reg
         * @userdata2   HUID
         * @devdesc     The SBE has booted on an unexpected side
         */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                MOD_SBE_THRESHOLD_FSM,
                RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP,
                l_ret,
                get_huid(i_target));

        l_errl->collectTrace( "ISTEPS_TRACE", 256);

        errlCommit(l_errl, ISTEP_COMP_ID);

    }

    return l_ret;
}

P9_EXTRACT_SBE_RC::RETURN_ACTION working_exit_state(
                           TARGETING::Target * i_target,
                           uint8_t i_orig_error)
{
    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}

P9_EXTRACT_SBE_RC::RETURN_ACTION failing_exit_state(
                           TARGETING::Target * i_target,
                           uint8_t i_orig_error)
{
    errlHndl_t l_errl = NULL;

    // Look at original error
    // Escalate to REIPL_BKP_SEEPROM (recall fcn)
    if( (i_orig_error == P9_EXTRACT_SBE_RC::RESTART_SBE) ||
        (i_orig_error == P9_EXTRACT_SBE_RC::RESTART_CBS) ||
        (i_orig_error == P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM) )
    {
#ifdef CONFIG_BMC_IPMI
        // This could potentially take awhile, reset watchdog
        l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "Inside sbe_extract_rc_handler FSM, before sbe_handler "
                      "Resetting watchdog");
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif
        proc_extract_sbe_handler(i_target,
                                 P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);
    }
    // Gard and callout proc, return back to 8.4
    else if(i_orig_error == P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM)
    {
        // There is no action possible. Gard and Callout the proc
        /*@
         * @errortype  ERRL_SEV_UNRECOVERABLE
         * @moduleid   MOD_SBE_THRESHOLD_FSM
         * @reasoncode RC_NO_RECOVERY_ACTION
         * @userdata1  SBE current error
         * @userdata2  HUID of proc
         * @devdesc    There is no recovery action on the SBE.
         *             We're garding this proc
             */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        MOD_SBE_THRESHOLD_FSM,
                        RC_NO_RECOVERY_ACTION,
                        i_orig_error,
                        TARGETING::get_huid(i_target));
        l_errl->collectTrace( "ISTEPS_TRACE", 256);
        l_errl->addHwCallout( i_target,
                              HWAS::SRCI_PRIORITY_HIGH,
                              HWAS::DECONFIG,
                              HWAS::GARD_Predictive );
        errlCommit(l_errl, ISTEP_COMP_ID);

    }

    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}
// end FSM


void proc_extract_sbe_handler( TARGETING::Target * i_target,
                               uint8_t i_current_error)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK
              "proc_extract_sbe_handler error: %llx",i_current_error);

    errlHndl_t l_errl = NULL;

    /*@
     * @errortype
     * @severity   ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid   MOD_SBE_EXTRACT_RC_HANDLER
     * @reasoncode RC_SBE_EXTRACT_RC_ERROR
     * @userdata1  HUID of proc that had the SBE timeout
     * @userdata2  SBE failing code
     *
     * @devdesc SBE did not start, this function is looking at
     *          the error to determine next course of action
     *
     * @custdesc The SBE did not start, we will attempt a reboot if possible
     */
    l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            MOD_SBE_EXTRACT_RC_HANDLER,
            RC_SBE_EXTRACT_RC_ERROR,
            TARGETING::get_huid(i_target),
            i_current_error);

    l_errl->collectTrace("ISTEPS_TRACE",256);

    // Commit error and continue
    errlCommit(l_errl, ISTEP_COMP_ID);

    switch(i_current_error)
    {
        case P9_EXTRACT_SBE_RC::RESTART_SBE:
        case P9_EXTRACT_SBE_RC::RESTART_CBS:
        {
            // Note: These two are only going to have the same handling until
            //       we have runtime handling in place.

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Running p9_start_cbs HWP on processor target %.8X",
                       TARGETING::get_huid(i_target));
            handle_sbe_restart(i_target, false,
                            P9_EXTRACT_SBE_RC::RESTART_SBE);
            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM:
        {
            // Log additional error on proc.
            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_SBE_EXTRACT_RC_HANDLER
             * @reasoncode RC_BOOT_FROM_BKP_SEEPROM
             * @userdata1  SBE return code
             * @userdata2  HUID current side
             * @devdesc    Attempting to boot from backup SEEPROM
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_SBE_EXTRACT_RC_HANDLER,
                            RC_BOOT_FROM_BKP_SEEPROM,
                            i_current_error,
                            get_huid(i_target));
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            // Run HWP, but from the other side.
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target(i_target);

            l_errl = switch_sbe_sides(i_target);
            if(l_errl)
            {
                errlCommit(l_errl,ISTEP_COMP_ID);
                break;
            }

            // Run HWP, but from the other side.
                // if it passes make a note that we booted from
                //    an unexpected side
                // if it fails, call the threshold handler
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running p9_start_cbs HWP on processor target %.8X",
                   TARGETING::get_huid(i_target));

            handle_sbe_restart(i_target, false,
                   P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);

            if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>())
            {
                // Make a note that we booted from an unexpected side
                /*@
                 * @errortype   ERRL_SEV_INFORMATIONAL
                 * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
                 * @reasoncode  RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP
                 * @userdata1   0
                 * @userdata2   HUID of working proc
                 * @devdesc     SBE booted from unexpected side.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_SBE_EXTRACT_RC_HANDLER,
                            RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP,
                            0,TARGETING::get_huid(i_target));
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM:
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target(i_target);

            l_errl = switch_sbe_sides(i_target);
            if(l_errl)
            {
                errlCommit(l_errl,ISTEP_COMP_ID);
                break;
            }

            // Run HWP, but from the other side.
                // if it passes make a note that we booted from an
                //   unexpected side
                // if it fails, escalate to RE_IPL_SEEPROM and call
                //   this function again.
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Running p9_start_cbs HWP on processor target %.8X",
                   TARGETING::get_huid(i_target));

            handle_sbe_restart(i_target, false,
                    P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM);

            if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>())
            {
                // Make a note that we booted from an unexpected side
                /*@
                 * @errortype   ERRL_SEV_INFORMATIONAL
                 * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
                 * @reasoncode  RC_SBE_BOOTED_UNEXPECTED_SIDE_UPD
                 * @userdata1   0
                 * @userdata2   HUID of proc
                 * @devdesc     SBE booted from unexpected side.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_SBE_EXTRACT_RC_HANDLER,
                            RC_SBE_BOOTED_UNEXPECTED_SIDE_UPD,
                            0,TARGETING::get_huid(i_target));
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION:
        {
            // There is no action possible. Gard and Callout the proc
            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   MOD_SBE_EXTRACT_RC_HANDLER
             * @reasoncode RC_NO_RECOVERY_ACTION
             * @userdata1  SBE current error
             * @userdata2  HUID of proc
             * @devdesc    There is no recovery action on the SBE.
             *             We're garding this proc
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            MOD_SBE_EXTRACT_RC_HANDLER,
                            RC_NO_RECOVERY_ACTION,
                            P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION,
                            TARGETING::get_huid(i_target));
            l_errl->collectTrace( "ISTEPS_TRACE", 256);
            l_errl->addHwCallout( i_target,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DECONFIG,
                                  HWAS::GARD_NULL );
            errlCommit(l_errl, ISTEP_COMP_ID);

            break;
        }
        default:
        {
            //Error out, unexpected enum value returned.
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
             * @reasoncode  RC_INCORRECT_FCN_CALL
             * @userdata1   SBE current error
             * @userdata2   HUID of proc
             * @devdesc     This function was called incorrectly or
             *              there is a new enum that is not handled yet.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_SBE_EXTRACT_RC_HANDLER,
                            RC_INCORRECT_FCN_CALL,
                            i_current_error,
                            TARGETING::get_huid(i_target));
            l_errl->collectTrace( "ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            break;
        }
    }

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, EXIT_MRK
              "proc_extract_sbe_handler");

    return;
}

SBE_REG_RETURN check_sbe_reg(TARGETING::Target * i_target)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK
              "check_sbe_reg");

    errlHndl_t l_errl = nullptr;
    SBE_REG_RETURN l_ret = SBE_REG_RETURN::SBE_FAILED_TO_BOOT;

    do
    {
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target(i_target);

        sbeMsgReg_t l_sbeReg;

        l_errl = sbe_timeout_handler(&l_sbeReg,i_target,&l_ret);

        if((!l_errl) && (l_sbeReg.currState != SBE_STATE_RUNTIME))
        {
            // See if async FFDC bit is set in SBE register
            if(l_sbeReg.asyncFFDC)
            {
                bool l_flowCtrl = sbe_get_ffdc_handler(i_target);

                if(l_flowCtrl)
                {
                    break;
                }
            }

            // Handle that SBE failed to boot in the allowed time
            sbe_boot_fail_handler(i_target,l_sbeReg);
        }
        else if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR: call check_sbe_reg, PLID=0x%x", l_errl->plid() );

            // capture the target data in the elog
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

            // Commit error log
            errlCommit( l_errl, HWPF_COMP_ID );
        }
        // No error and still functional
        else if(i_target->getAttr<TARGETING::ATTR_HWAS_STATE>().functional)
        {
            // Set attribute indicating that SBE is started
            i_target->setAttr<TARGETING::ATTR_SBE_IS_STARTED>(1);

            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SUCCESS: check_sbe_reg completed okay for proc 0x%.8X",
                      TARGETING::get_huid(i_target));
        }
        //@TODO-RTC:100963 - this should match the logic in
        //call_proc_check_slave_sbe_seeprom.C
    } while(0);

    return l_ret;

}

P9_EXTRACT_SBE_RC::RETURN_ACTION  handle_sbe_reg_value(
                TARGETING::Target * i_target,
                SBE_REG_RETURN i_sbe_reg,
                P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_sbe_error,
                bool i_fromStateMachine)
{
    errlHndl_t l_errl = NULL;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    switch(i_sbe_reg)
    {
        case SBE_REG_RETURN::FUNCTION_ERROR:
        {
            // There has been a failure getting the SBE register
            // We cannot continue any further, return failure.
            return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
        }
        case SBE_REG_RETURN::SBE_AT_RUNTIME:
        {
            // The SBE has successfully booted at runtime
            return P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
        }
        case SBE_REG_RETURN::SBE_FAILED_TO_BOOT:
        {
            if((!i_fromStateMachine) &&
               (i_current_sbe_error == P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM))
            {
#ifdef CONFIG_BMC_IPMI
                // This could potentially take awhile, reset watchdog
                l_errl = IPMIWATCHDOG::resetWatchDogTimer();
                if(l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                              "Inside handle_sbe_reg_value before sbe_handler "
                              "Resetting watchdog");
                    l_errl->collectTrace("ISTEPS_TRACE",256);
                    errlCommit(l_errl,ISTEP_COMP_ID);
                }
#endif
                // If we were trying to reipl and hit the error, we need
                // to start with a new seeprom before hitting the threshold
                proc_extract_sbe_handler(i_target,
                                         P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);
                return P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
            }

            // Get SBE extract rc
            P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
                    P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
            FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                    l_fapi2_proc_target, l_rcAction);

            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                          "ERROR : p9_extract_sbe_rc HWP returning errorlog "
                          "PLID-0x%x", l_errl->plid());

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            if(i_fromStateMachine)
            {
                return l_rcAction;
            }

            uint8_t l_prevError = (i_target)->getAttr<
                    TARGETING::ATTR_PREVIOUS_SBE_ERROR>();
            (i_target)->setAttr<TARGETING::ATTR_PREVIOUS_SBE_ERROR>(
                            l_rcAction);

            if(i_current_sbe_error == P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM)
            {
                // Call sbe_threshold handler on the opposite side
                sbe_threshold_handler(false, i_target, l_rcAction, l_prevError);
            }
            else
            {
                // Call sbe_threshold handler on the same side
                sbe_threshold_handler(true, i_target, l_rcAction, l_prevError);
            }
            return P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
        }
        default:
        {
            // This should never happened
            // error out, unexpected enum value returned.
            //return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    MOD_HANDLE_SBE_REG_VALUE
             * @reasoncode  RC_INCORRECT_FCN_CALL
             * @userdata1   HUID of target
             * @userdata2   check_sbe_reg return value
             * @devdesc     This function was called incorrectly or
             *              there is a new enum that is not handled yet.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            MOD_HANDLE_SBE_REG_VALUE,
                            RC_INCORRECT_FCN_CALL,
                            get_huid(i_target),i_sbe_reg);
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);
            return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
        }
    }
}

P9_EXTRACT_SBE_RC::RETURN_ACTION handle_sbe_restart(
            TARGETING::Target * i_target,
            bool i_fromStateMachine,
            P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_condition)
{
    errlHndl_t l_errl = NULL;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (i_target);

    FAPI_INVOKE_HWP(l_errl, p9_start_cbs, l_fapi2_proc_target, true);
    if(l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                 "ERROR: call p9_start_cbs, "
                 "PLID=0x%x", l_errl->plid() );
        l_errl->collectTrace( "ISTEPS_TRACE", 256);

        errlCommit(l_errl, ISTEP_COMP_ID);
    }

    SBE_REG_RETURN l_checkSBE = check_sbe_reg(i_target);
    return handle_sbe_reg_value(i_target, l_checkSBE,
                    i_current_condition, i_fromStateMachine);
}

errlHndl_t sbe_timeout_handler(sbeMsgReg_t * o_sbeReg,
                TARGETING::Target * i_target,
                SBE_REG_RETURN * o_returnAction)
{
    errlHndl_t l_errl = NULL;

    (*o_returnAction) = SBE_FAILED_TO_BOOT;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    // Each slave sbe gets 60s to respond with the fact that it's
    // booted and at runtime (stable state)
    uint64_t SBE_TIMEOUT_NSEC = 60*NS_PER_SEC; //60 sec
    // Bump this up really high for simics, things are slow there
    if( Util::isSimicsRunning() )
    {
        SBE_TIMEOUT_NSEC *= 10;
    }
    const uint64_t SBE_NUM_LOOPS = 100;
    const uint64_t SBE_WAIT_SLEEP = (SBE_TIMEOUT_NSEC/SBE_NUM_LOOPS);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "Running p9_get_sbe_msg_register HWP on proc target %.8X",
               TARGETING::get_huid(i_target));

    for( uint64_t l_loops = 0; l_loops < SBE_NUM_LOOPS; l_loops++ )
    {
        (*o_sbeReg).reg = 0;
        FAPI_INVOKE_HWP(l_errl, p9_get_sbe_msg_register,
                        l_fapi2_proc_target, (*o_sbeReg));
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR : call p9_get_sbe_msg_register, PLID=0x%x, "
                      "on loop %d",
                      l_errl->plid(),
                      l_loops );
            (*o_returnAction) = SBE_REG_RETURN::FUNCTION_ERROR;
            break;
        }
        else if ((*o_sbeReg).currState == SBE_STATE_RUNTIME)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SBE 0x%.8X booted and at runtime, o_sbeReg=0x%.8X, "
                      "on loop %d",
                      TARGETING::get_huid(i_target), (*o_sbeReg).reg,
                      l_loops);
            (*o_returnAction) = SBE_REG_RETURN::SBE_AT_RUNTIME;
            break;
        }
        else if ((*o_sbeReg).asyncFFDC)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "SBE 0x%.8X has async FFDC bit set, o_sbeReg=0x%.8X",
                      TARGETING::get_huid(i_target), (*o_sbeReg).reg);
            // Async FFDC is indicator that SBE is failing to boot, and if
            // in DUMP state, that SBE is done dumping, so leave loop
            break;
        }
        else
        {
            if( !(l_loops % 10) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "%d> SBE 0x%.8X NOT booted yet, o_sbeReg=0x%.8X",
                           l_loops, TARGETING::get_huid(i_target),
                           (*o_sbeReg).reg);
            }
            l_loops++;
            nanosleep(0,SBE_WAIT_SLEEP);
        }
    }

    if ((*o_sbeReg).currState != SBE_STATE_RUNTIME)
    {
        // Switch to using FSI SCOM
        TARGETING::ScomSwitches l_switches =
            i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        TARGETING::ScomSwitches l_switches_before = l_switches;

        // Turn off SBE SCOM and turn on FSI SCOM.
        l_switches.useFsiScom = 1;
        l_switches.useSbeScom = 0;

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "sbe_timeout_handler: changing SCOM switches from 0x%.2X "
                  "to 0x%.2X for proc 0x%.8X",
                  l_switches_before,
                  l_switches,
                  TARGETING::get_huid(i_target));
        i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
    }

    return l_errl;
}

P9_EXTRACT_SBE_RC::RETURN_ACTION action_for_ffdc_rc(uint32_t i_rc)
{
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_action;

    switch(i_rc)
    {
        case fapi2::RC_EXTRACT_SBE_RC_RUNNING:
        case fapi2::RC_EXTRACT_SBE_RC_NEVER_STARTED:
        case fapi2::RC_EXTRACT_SBE_RC_PROGRAM_INTERRUPT:
        case fapi2::RC_EXTRACT_SBE_RC_ADDR_NOT_RECOGNIZED:
        case fapi2::RC_EXTRACT_SBE_RC_PIBMEM_ECC_ERR:
        case fapi2::RC_EXTRACT_SBE_RC_FI2CM_BIT_RATE_ERR_NONSECURE_MODE:

            l_action = P9_EXTRACT_SBE_RC::RESTART_SBE;

            break;

        case fapi2::RC_EXTRACT_SBE_RC_MAGIC_NUMBER_MISMATCH:
        case fapi2::RC_EXTRACT_SBE_RC_FI2C_ECC_ERR:

            l_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;

            break;

        case fapi2::RC_EXTRACT_SBE_RC_FI2C_TIMEOUT:
        case fapi2::RC_EXTRACT_SBE_RC_UNKNOWN_ERROR:

            l_action = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;

            break;

        case fapi2::RC_EXTRACT_SBE_RC_OTP_TIMEOUT:
        case fapi2::RC_EXTRACT_SBE_RC_OTP_PIB_ERR:
        case fapi2::RC_EXTRACT_SBE_RC_PIBMEM_PIB_ERR:
        case fapi2::RC_EXTRACT_SBE_RC_FI2C_SPRM_CFG_ERR:
        case fapi2::RC_EXTRACT_SBE_RC_FI2C_PIB_ERR:

            l_action = P9_EXTRACT_SBE_RC::RESTART_CBS;

            break;

        case fapi2::RC_EXTRACT_SBE_RC_BRANCH_TO_SEEPROM_FAIL:
        case fapi2::RC_EXTRACT_SBE_RC_UNEXPECTED_OTPROM_HALT:
        case fapi2::RC_EXTRACT_SBE_RC_OTP_ECC_ERR:
        default:

            l_action = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;

            break;
    }

    return l_action;
}

bool sbe_get_ffdc_handler(TARGETING::Target * i_target)
{
    bool l_flowCtrl = false;
    errlHndl_t l_errl = nullptr;
    uint32_t l_responseSize = SBEIO::SbeFifoRespBuffer::MSG_BUFFER_SIZE;
    uint32_t *l_pFifoResponse =
        reinterpret_cast<uint32_t *>(malloc(l_responseSize));

    l_errl = SBEIO::getFifoSBEFFDC(i_target,
                                   l_pFifoResponse,
                                   l_responseSize);

    // Check if there was an error log created
    if(l_errl)
    {
        // Trace but otherwise silently ignore error
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                  "sbe_get_ffdc_handler: ignoring error PLID=0x%x from "
                  "get SBE FFDC FIFO request to proc 0x%.8X",
                  l_errl->plid(),
                  TARGETING::get_huid(i_target));
        delete l_errl;
        l_errl = nullptr;

    }
    else
    {
        // Parse the FFDC package(s) in the response
        SBEIO::SbeFFDCParser * l_ffdc_parser =
            new SBEIO::SbeFFDCParser();
        l_ffdc_parser->parseFFDCData(reinterpret_cast<void *>(l_pFifoResponse));

        uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
        P9_EXTRACT_SBE_RC::RETURN_ACTION l_action;

        // If there are FFDC packages, make a log for FFDC from SBE
        if(l_pkgs > 0)
        {
            /*@
             * @errortype
             * @moduleid     MOD_SBE_GET_FFDC_HANDLER
             * @reasoncode   RC_RETURNED_FFDC
             * @userdata1    Processor Target
             * @userdata2    Number of FFDC packages
             * @devdesc      FFDC returned by SBE after failing to reach runtime
             * @custdesc     FFDC associated with boot device failing to boot
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             MOD_SBE_GET_FFDC_HANDLER,
                                             RC_RETURNED_FFDC,
                                             TARGETING::get_huid(i_target),
                                             l_pkgs);

            // Also log the failing proc as FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
        }

        // Process each FFDC package
        for(auto i=0; i<l_pkgs; i++)
        {
            // Add each package to the log
            l_errl->addFFDC( SBEIO_COMP_ID,
                             l_ffdc_parser->getFFDCPackage(i),
                             l_ffdc_parser->getPackageLength(i),
                             0,
                             SBEIO::SBEIO_UDT_PARAMETERS,
                             false );

            // Get the RC from the FFDC package
            uint32_t l_rc = l_ffdc_parser->getPackageRC(i);

            // Determine an action for the RC
            l_action = action_for_ffdc_rc(l_rc);

            // Handle that action
            proc_extract_sbe_handler(i_target,
                                     l_action);
        }

        // If there are FFDC packages, commit the log
        if(l_pkgs > 0)
        {
            l_errl->collectTrace( SBEIO_COMP_NAME, KILOBYTE/4);
            l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

            errlCommit(l_errl, ISTEP_COMP_ID);
        }

        delete l_ffdc_parser;
        l_ffdc_parser = nullptr;

        l_flowCtrl = true;
    }

    free(l_pFifoResponse);
    l_pFifoResponse = nullptr;

    return l_flowCtrl;
}

void sbe_boot_fail_handler(TARGETING::Target * i_target,
                           sbeMsgReg_t i_sbeReg,
                           IStepError *io_stepError)
{
    errlHndl_t l_errl = nullptr;
    errlHndl_t l_temp_errl = nullptr;
    bool retry = true;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "SBE 0x%.8X never started, sbeReg=0x%.8X",
               TARGETING::get_huid(i_target),i_sbeReg.reg );
    /*@
     * @errortype
     * @reasoncode  RC_SBE_SLAVE_TIMEOUT
     * @severity    ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
     * @userdata1   HUID of proc which had SBE timeout
     * @userdata2   SBE MSG Register
     *
     * @devdesc Slave SBE did not get to ready state within
     *          allotted time
     *
     * @custdesc A processor in the system has failed to initialize
     */
    l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                     MOD_SBE_EXTRACT_RC_HANDLER,
                                     RC_SBE_SLAVE_TIMEOUT,
                                     TARGETING::get_huid(i_target),
                                     i_sbeReg.reg);

    l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

    // Commit error and continue, this is not terminating since
    // we can still at least boot with master proc
    errlCommit(l_errl,ISTEP_COMP_ID);

    // Setup for the HWP
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
            P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
    FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                    l_fapi2ProcTarget, l_rcAction);

    if(l_rcAction != P9_EXTRACT_SBE_RC::ERROR_RECOVERED)
    {
        if (l_errl)
        {
            // Save this in the event we are out of retries
            //  and want to commit it
            l_temp_errl = l_errl;
            l_errl = nullptr;
        }

        if(INITSERVICE::spBaseServicesEnabled())
        {
            // When we are on an FSP machine, we want to fail out of
            // hostboot and give control back to the FSP. They have
            // better diagnostics for this type of error.
            INITSERVICE::doShutdownWithError(RC_HWSV_COLLECT_SBE_RC,
                                TARGETING::get_huid(i_target));
        }

        // Save the current rc error
        (i_target)->setAttr<TARGETING::ATTR_PREVIOUS_SBE_ERROR>(l_rcAction);
#ifdef CONFIG_BMC_IPMI
        // This could potentially take awhile, reset watchdog
        l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "sbe_boot_fail_handler "
                      "Resetting watchdog before sbe_handler");
            l_errl->collectTrace("ISTEPS_TRACE",KILOBYTE/4);
            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif

        //Only attempt to recover twice before erroring out
        if((l_rcAction == P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) &&
           (g_switch_sides_count < 2))
        {
            g_switch_sides_count++;
            // Change action to attempt coming up from backup SEEPROM
            l_rcAction = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
        }
        else if ((l_rcAction == P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) &&
           (g_switch_sides_count >= 2))
        {
            if (l_temp_errl)
            {
                l_errl = l_temp_errl;
                l_temp_errl = nullptr;
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR : sbe_boot_fail_handler : "
                   "p9_extract_sbe_rc HWP returned action %d and errorlog "
                   "PLID=0x%x, rc=0x%.4X",
                   l_rcAction, l_errl->plid(), l_errl->reasonCode());

                //Callout Slave Proc so we can reboot only on master
                l_errl->addHwCallout( i_target,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DECONFIG,
                                  HWAS::GARD_Predictive );

                // Create IStep error log and cross reference to error
                io_stepError->addErrorDetails( l_errl );

                // Commit error log
                errlCommit(l_errl, HWPF_COMP_ID);
            }
            else
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "ERROR : sbe_boot_fail_handler : "
                   "p9_extract_sbe_rc HWP returned action %d but no errorlog."
                    " Will not retry proc_extract_sbe_handler()", l_rcAction);

            }
            retry = false;
        }

        delete l_temp_errl;

        if (retry)
        {
            proc_extract_sbe_handler( i_target,
                                      l_rcAction);
        }
    }

    if(l_errl)
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,"ERROR : sbe_boot_fail_handler : "
               "p9_extract_sbe_rc HWP returned action %d and errorlog "
               "PLID=0x%x, rc=0x%.4X",
               l_rcAction, l_errl->plid(), l_errl->reasonCode());

        // capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    return;
}

errlHndl_t switch_sbe_sides(TARGETING::Target * i_target)
{
    errlHndl_t l_errl = NULL;
    fapi2::buffer<uint32_t> l_read_reg;
    const uint32_t l_sbeBootSelectMask = SBE::SBE_BOOT_SELECT_MASK >> 32;
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target(i_target);

    do{
        // Read PERV_SB_CS_FSI_BYTE 0x2820 for target proc
        uint32_t l_read_reg = 0;
        size_t l_opSize = sizeof(uint32_t);
        l_errl = DeviceFW::deviceOp(
                     DeviceFW::READ,
                     i_target,
                     &l_read_reg,
                     l_opSize,
                     DEVICE_FSI_ADDRESS(PERV_SB_CS_FSI_BYTE) );
        if( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"switch_sbe_sides: FSI device read "
                       "PERV_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                       "RC=0x%X, PLID=0x%lX",
                       PERV_SB_CS_FSI_BYTE, // 0x2820
                       TARGETING::get_huid(i_target),
                       ERRL_GETRC_SAFE(l_errl),
                       ERRL_GETPLID_SAFE(l_errl));
            break;
        }

        // Determine how boot side is currently set
        if(l_read_reg & l_sbeBootSelectMask) // Currently set for Boot Side 1
        {
            // Set Boot Side 0 by clearing bit for side 1
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "switch_sbe_sides #%d: Set Boot Side 0 for HUID 0x%08X",
                      g_switch_sides_count,
                      TARGETING::get_huid(i_target));
            l_read_reg &= ~l_sbeBootSelectMask;
        }
        else // Currently set for Boot Side 0
        {
            // Set Boot Side 1 by setting bit for side 1
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "switch_sbe_sides #%d: Set Boot Side 1 for HUID 0x%08X",
                      g_switch_sides_count,
                      TARGETING::get_huid(i_target));
            l_read_reg |= l_sbeBootSelectMask;
        }

        // Write updated PERV_SB_CS_FSI 0x2820 back into target proc
        l_errl = DeviceFW::deviceOp(
                     DeviceFW::WRITE,
                     i_target,
                     &l_read_reg,
                     l_opSize,
                     DEVICE_FSI_ADDRESS(PERV_SB_CS_FSI_BYTE) );
        if( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       ERR_MRK"switch_sbe_sides: FSI device write "
                       "PERV_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                       "RC=0x%X, PLID=0x%lX",
                       PERV_SB_CS_FSI_BYTE, // 0x2820
                       TARGETING::get_huid(i_target),
                       ERRL_GETRC_SAFE(l_errl),
                       ERRL_GETPLID_SAFE(l_errl));
            break;
        }

    } while(0);

    return l_errl;
}
