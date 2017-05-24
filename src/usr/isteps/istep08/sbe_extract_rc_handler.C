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
 * @file sbe_extract_rc_handler.H
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
#include <errl/errludtarget.H>

#include <p9_start_cbs.H>
#include "sbe_extract_rc_handler.H"

/* array and enum must be in sync */
P9_EXTRACT_SBE_RC::RETURN_ACTION (* state[])(TARGETING::Target * i_target,
                uint8_t i_prev_error) =
      { same_side_retry_state, other_side_state,
        working_exit_state, failing_exit_state };
enum state_codes { same_side_retry, other_side,
                   working_exit, failing_exit };
struct transition
{
    enum state_codes src_state;
    uint8_t ret_code;
    enum state_codes dst_state;
};

/* transistions from end states aren't needed */
struct transition state_transitions[] = {
    { same_side_retry, 0, working_exit },
    { same_side_retry, 1, other_side },
    { other_side, 0, working_exit },
    { other_side, 1, failing_exit }
};

enum state_codes get_next_state( enum state_codes i_src, uint8_t i_rc )
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

    state_codes cur_state = same_side_retry;

    // The initial state depends on our inputs
    if( i_procSide )
    {
        cur_state = other_side;
    }

    // Setup the rest of the FSM
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_returnedAction;
    P9_EXTRACT_SBE_RC::RETURN_ACTION (*state_fcn)(TARGETING::Target * i_target,
                    uint8_t i_prev_error);

    P9_EXTRACT_SBE_RC::RETURN_ACTION l_currentAction = i_initialAction;

    // Begin FSM
    for(;;)
    {
        state_fcn = state[cur_state];
        l_returnedAction = state_fcn(i_target, l_currentAction);

        if( cur_state == working_exit || cur_state == failing_exit)
        {
            break;
        }
        l_currentAction = l_returnedAction;
        // If the returned action was 0, the return is a pass: 0,
        // Else, the SBE did not start cleanly and we continue
        cur_state = get_next_state(cur_state,
                !(P9_EXTRACT_SBE_RC::ERROR_RECOVERED == l_returnedAction));

    }

    return;

}

P9_EXTRACT_SBE_RC::RETURN_ACTION same_side_retry_state(
                            TARGETING::Target * i_target,
                            uint8_t i_prev_error)
{
    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}

P9_EXTRACT_SBE_RC::RETURN_ACTION other_side_state(
                         TARGETING::Target * i_target,
                         uint8_t i_prev_error)
{
    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}

P9_EXTRACT_SBE_RC::RETURN_ACTION working_exit_state(
                           TARGETING::Target * i_target,
                           uint8_t i_prev_error)
{
    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}

P9_EXTRACT_SBE_RC::RETURN_ACTION failing_exit_state(
                           TARGETING::Target * i_target,
                           uint8_t i_prev_error)
{
    return P9_EXTRACT_SBE_RC::ERROR_RECOVERED; //pass
}
// end FSM


void proc_extract_sbe_handler( TARGETING::Target * i_target,
                uint8_t i_previous_error, uint8_t i_current_error)
{
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ENTER_MRK
              "proc_extract_sbe_handler error: %llx",i_current_error);

    errlHndl_t l_errl = NULL;

    /*@
     * @errortype
     * @severity   ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid   ISTEP::MOD_SBE_EXTRACT_RC_HANDLER
     * @reasoncode ISTEP::RC_SBE_EXTRACT_RC_ERROR
     * @userdata1  HUID of proc that had the SBE timeout
     * @userdata2  SBE failing code
     *
     * @devdesc SBE did not start, this funciton is looking at
     *          the error to determine next course of action
     *
     * @custdesc The SBE did not start, we will attempt a reboot if possible
     */
    l_errl = new ERRORLOG::ErrlEntry(
            ERRORLOG::ERRL_SEV_INFORMATIONAL,
            ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
            ISTEP::RC_SBE_EXTRACT_RC_ERROR,
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

            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                    l_fapi2_proc_target (i_target);
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                       "Running p9_start_cbs HWP on processor target %.8X",
                       TARGETING::get_huid(i_target));

            FAPI_INVOKE_HWP(l_errl, p9_start_cbs, l_fapi2_proc_target, true);
            if(l_errl)
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR: call p9_start_cbs, "
                         "PLID=0x%x", l_errl->plid() );
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);

                // Get SBE extract rc
                P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
                        P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                                l_fapi2_proc_target, l_rcAction);

                if(l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                             "ERROR : call p9_extract_sbe_rc, PLID=0x%x",
                             l_errl->plid());

                    // capture the target data in the elog
                    ERRORLOG::ErrlUserDetailsTarget(l_fapi2_proc_target).
                            addToLog( l_errl );

                    // Commit error log
                    errlCommit( l_errl, HWPF_COMP_ID );

                    break;
                }

                uint8_t l_prevError = (i_target)->getAttr<
                        TARGETING::ATTR_PREVIOUS_SBE_ERROR>();
                (i_target)->setAttr<TARGETING::ATTR_PREVIOUS_SBE_ERROR>(
                                l_rcAction);

                // Call sbe_threshold handler on the same side
                sbe_threshold_handler(true, i_target, l_rcAction, l_prevError);
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM:
        {
            // Log additional error on proc.
            /* @
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   MOD_SBE_EXTRACT_RC_HANDLER
             * @reasoncode RC_BOOT_FROM_BKP_SEEPROM
             * @userdata1  SBE return code
             * @userdata2  HUID current side
             * @devdesc    Attempting to boot from backup SEEPROM
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                            ISTEP::RC_BOOT_FROM_BKP_SEEPROM,
                            i_current_error,
                            get_huid(i_target));
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            // Get the other proc
            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);

            TARGETING::PredicateCTM predProc(TARGETING::CLASS_CHIP,
                            TARGETING::TYPE_PROC);
            TARGETING::TargetHandleList l_procs;
            TARGETING::targetService().getAssociated(l_procs, sys,
                            TARGETING::TargetService::CHILD,
                            TARGETING::TargetService::ALL,&predProc);

            for(auto childItr = l_procs.begin();
                childItr != l_procs.end(); ++childItr)
            {
                if( (*childItr) == i_target)
                {
                    continue;
                }
                else
                {
                    // Run HWP, but from the other side.
                        // if it passes make a note that we booted from
                        //    an unexpected side
                        // if it fails, call the threshold handler
                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_proc_target((*childItr));
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Running p9_start_cbs HWP on processor target %.8X",
                            TARGETING::get_huid((*childItr)));

                    FAPI_INVOKE_HWP(l_errl, p9_start_cbs,
                                    l_fapi2_proc_target, true);
                    if(l_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR: call p9_start_cbs, "
                                  "PLID=0x%x",l_errl->plid() );
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID);

                        // Get SBE extract rc
                        P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
                                P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
                        FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                                        l_fapi2_proc_target, l_rcAction);

                        if(l_errl)
                        {
                            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                 "ERROR : call p9_extract_sbe_rc, PLID=0x%x",
                                 l_errl->plid());

                            // capture the target data in the elog
                            ERRORLOG::ErrlUserDetailsTarget(
                                    l_fapi2_proc_target).addToLog( l_errl );

                            // Commit error log
                            errlCommit( l_errl, HWPF_COMP_ID );

                            break;
                        }

                        uint8_t l_prevError = (i_target)->getAttr<
                            TARGETING::ATTR_PREVIOUS_SBE_ERROR>();
                        (*childItr)->setAttr<
                            TARGETING::ATTR_PREVIOUS_SBE_ERROR>(l_rcAction);

                        // Call sbe_threshold handler on the other side
                        sbe_threshold_handler(false, i_target,
                                              l_rcAction, l_prevError);
                    }
                    else
                    {
                        // Make a note that we booted from an unexpected side
                        /* @
                         * @errortype   ERRL_SEV_INFORMATIONAL
                         * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
                         * @reasondcode RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP
                         * @userdata1   0
                         * @userdata2   HUID of other (working) proc
                         * @devdesc     SBE booted from unexpected side.
                         */
                        l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                                    ISTEP::RC_SBE_BOOTED_UNEXPECTED_SIDE_BKP,
                                    0,TARGETING::get_huid(*childItr));
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID);
                     }
                 }
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM:
        {
            // Get the other proc
            TARGETING::Target * sys = NULL;
            TARGETING::targetService().getTopLevelTarget(sys);

            TARGETING::PredicateCTM predProc(TARGETING::CLASS_CHIP,
                            TARGETING::TYPE_PROC);
            TARGETING::TargetHandleList l_procs;
            TARGETING::targetService().getAssociated(l_procs, sys,
                            TARGETING::TargetService::CHILD,
                            TARGETING::TargetService::ALL,&predProc);

            for(auto childItr = l_procs.begin();
                childItr != l_procs.end(); ++childItr)
            {
                if( (*childItr) == i_target)
                {
                    continue;
                }
                else
                {
                    // Run HWP, but from the other side.
                        // if it passes make a note that we booted from an
                        //   unexpected side
                        // if it fails, escalate to RE_IPL_SEEPROM and call
                        //   this function again.
                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                            l_fapi2_proc_target((*childItr));
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "Running p9_start_cbs HWP on processor target %.8X",
                           TARGETING::get_huid((*childItr)));

                    FAPI_INVOKE_HWP(l_errl, p9_start_cbs,
                                    l_fapi2_proc_target, true);
                    if(l_errl)
                    {
                        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                                  "ERROR: call p9_start_cbs, "
                                  "PLID=0x%x",l_errl->plid() );
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID);

                        proc_extract_sbe_handler( i_target,
                                        i_current_error,
                                        P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);

                        /* @
                         * @errortype  ERRL_SEV_INFORMATIONAL
                         * @moduleid   MOD_SBE_EXTRACT_RC_HANDLER
                         * @reasoncode RC_PROC_EXTRACT_SBE_MAIN_ERROR
                         * @userdata1  Current Error
                         * @userdata2  HUID of errored proc
                         * @devdesc    An error occurred after calling
                         *             proc_extract_sbe_handler again.
                         *             This should not occur.
                         */
                        l_errl = new ERRORLOG::ErrlEntry(
                                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                        ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                                        ISTEP::RC_PROC_EXTRACT_SBE_MAIN_ERROR,
                                        i_current_error,
                                        TARGETING::get_huid(i_target));
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID);
                    }
                    else
                    {
                        // Make a note that we booted from an unexpected side
                        /* @
                         * @errortype   ERRL_SEV_INFORMATIONAL
                         * @moduleid    MOD_SBE_EXTRACT_RC_HANDLER
                         * @reasoncode  RC_SBE_BOOTED_UNEXPECTED_SIDE_UPD
                         * @userdata1   0
                         * @userdata2   HUID of other (working) proc
                         * @devdesc     SBE booted from unexpected side.
                         */
                        l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                    ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                                    ISTEP::RC_SBE_BOOTED_UNEXPECTED_SIDE_UPD,
                                    0,TARGETING::get_huid(*childItr));
                        l_errl->collectTrace("ISTEPS_TRACE",256);
                        errlCommit(l_errl, ISTEP_COMP_ID);
                     }
                 }
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION:
        {
            // There is no action possible. Gard and Callout the proc
            /* @
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
                            ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                            ISTEP::RC_NO_RECOVERY_ACTION,
                            P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION,
                            TARGETING::get_huid(i_target));
            l_errl->collectTrace( "ISTEPS_TRACE", 246);
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
            /* @
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
                            ISTEP::MOD_SBE_EXTRACT_RC_HANDLER,
                            ISTEP::RC_INCORRECT_FCN_CALL,
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



