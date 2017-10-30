/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_threshold_fsm.C $                           */
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

/*****************************************************************************/
// Includes
/*****************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <ipmi/ipmiwatchdog.H>

#include <sbeio/sbeioreasoncodes.H>
#include "sbe_threshold_fsm.H"
#include <sbeio/sbe_extract_rc_handler.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_FSM_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"sbe_threshold_fsm.C: " printf_string,##args)
#define SBE_FSM_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"sbe_threshold_fsm.C: " printf_string,##args)
#define SBE_FSM_TRACU(args...)
#define SBE_FSM_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"sbe_threshold_fsm.C: " printf_string,##args)
#define SBE_FSM_TRACDBIN(printf_string,args...) \
    TRACDBIN(g_trac_sbeio,"sbe_threshold_fsm.C: " printf_string,##args)



using namespace SBEIO;

namespace SBE_FSM
{

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

// transistions from end states aren't needed //
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
                          uint8_t i_previousError)
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
                    uint8_t i_orig_error );

    // Begin FSM
    for(;;)
    {
#ifdef CONFIG_BMC_IPMI
        // This could potentially take awhile, reset watchdog
        errlHndl_t l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            SBE_FSM_TRACF("Inside sbe_extract_dd FSM, "
                      "Resetting watchdog");
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif

        state_fcn = SBE_FSM::sbe_handler_state[cur_state];
        l_returnedAction = state_fcn(i_target, i_initialAction);

        if( cur_state == WORKING_EXIT ||
            cur_state == FAILING_EXIT)
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
    SBE_FSM_TRACF("Running p9_start_cbs HWP on processor target %.8X",
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
    SBE_FSM_TRACF("Running p9_start_cbs HWP on processor target %.8X",
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
         * @moduleid    SBEIO_THRESHOLD_FSM
         * @reasoncode  SBEIO_BOOTED_UNEXPECTED_SIDE_BKP
         * @userdata1   SBE status reg
         * @userdata2   HUID
         * @devdesc     The SBE has booted on an unexpected side
         */
        l_errl = new ERRORLOG::ErrlEntry(
                ERRORLOG::ERRL_SEV_INFORMATIONAL,
                SBEIO_THRESHOLD_FSM,
                SBEIO_BOOTED_UNEXPECTED_SIDE_BKP,
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
            SBE_FSM_TRACF("Inside sbe_extract_dd FSM, before sbe_handler "
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
         * @moduleid   SBEIO_THRESHOLD_FSM
         * @reasoncode SBEIO_NO_RECOVERY_ACTION
         * @userdata1  SBE current error
         * @userdata2  HUID of proc
         * @devdesc    There is no recovery action on the SBE.
         *             We're garding this proc
             */
        l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                        SBEIO_THRESHOLD_FSM,
                        SBEIO_NO_RECOVERY_ACTION,
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

}; // End of namespace SBE_FSM

