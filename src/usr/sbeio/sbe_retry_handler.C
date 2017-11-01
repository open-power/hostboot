/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_retry_handler.C $                           */
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
 * @file sbe_extract_dd.C
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
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <errl/errludtarget.H>
#include <sys/time.h>
#include <util/misc.H>
#include <ipmi/ipmiwatchdog.H>

#include <p9_start_cbs.H>
#include <p9_get_sbe_msg_register.H>
#include <p9_perv_scom_addresses.H>
#include <sbe/sbe_update.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_sp_intf.H>
#include <../../usr/sbeio/sbe_fifodd.H>
#include <../../usr/sbeio/sbe_fifo_buffer.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbeioreasoncodes.H>
#include "sbe_threshold_fsm.H"

#include <devicefw/driverif.H>

/* Global switch sides count */
static uint8_t g_switch_sides_count = 0;

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"sbe_retry_handler.C: " printf_string,##args)
#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"sbe_retry_handler.C: " printf_string,##args)
#define SBE_TRACU(args...)
#define SBE_TRACFBIN(printf_string,args...) \
    TRACFBIN(g_trac_sbeio,"sbe_retry_handler.C: " printf_string,##args)
#define SBE_TRACDBIN(printf_string,args...) \
    TRACDBIN(g_trac_sbeio,"sbe_retry_handler.C: " printf_string,##args)

namespace SBEIO
{

/**
 * @brief Static instance function
 */
SbeRetryHandler& SbeRetryHandler::getInstance()
{
    return Singleton<SbeRetryHandler>::instance();
}

SbeRetryHandler::SbeRetryHandler()
: iv_sbeRestarted(false)
, iv_sbeOtherSide(false)
, iv_sbeErrorLogged(false)
{
    SBE_TRACF(ENTER_MRK "SbeRetryHandler::SbeRetryHandler()");

    SBE_TRACF(EXIT_MRK "SbeRetryHandler::SbeRetryHandler()");
}

SbeRetryHandler::~SbeRetryHandler()
{

}

void SbeRetryHandler::proc_extract_sbe_handler( TARGETING::Target * i_target,
                               uint8_t i_current_error,
                               SBE_REG_RETURN * o_regReturn)
{
    SBE_TRACF(ENTER_MRK "proc_extract_sbe_handler error: %x",
                    i_current_error);

    errlHndl_t l_errl = NULL;

    /*@
     * @errortype
     * @severity   ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid   SBEIO_EXTRACT_RC_HANDLER
     * @reasoncode SBEIO_EXTRACT_RC_ERROR
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
            SBEIO_EXTRACT_RC_HANDLER,
            SBEIO_EXTRACT_RC_ERROR,
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
            SBE_TRACF("proc_extract_sbe_handler(): case RESTART_SBE");
            // Note: These two are only going to have the same handling until
            //       we have runtime handling in place.

            SBE_TRACF("Running p9_start_cbs HWP on processor target %.8X",
                       TARGETING::get_huid(i_target));
            this->handle_sbe_restart(i_target, false,
                            P9_EXTRACT_SBE_RC::RESTART_SBE);
            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM:
        {
            SBE_TRACF("proc_extract_sbe_handler(): case REIPL_BKP_SEEPROM");
            // Log additional error on proc.
            /*@
             * @errortype  ERRL_SEV_INFORMATIONAL
             * @moduleid   SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode SBEIO_BOOT_FROM_BKP_SEEPROM
             * @userdata1  SBE return code
             * @userdata2  HUID current side
             * @devdesc    Attempting to boot from backup SEEPROM
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_BOOT_FROM_BKP_SEEPROM,
                            i_current_error,
                            get_huid(i_target));
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            l_errl = this->switch_sbe_sides(i_target);
            if(l_errl)
            {
                errlCommit(l_errl,ISTEP_COMP_ID);
                break;
            }

            // Run HWP, but from the other side.
                // if it passes make a note that we booted from
                //    an unexpected side
                // if it fails, call the threshold handler
            SBE_TRACF( "Running p9_start_cbs HWP on processor target %.8X",
                   TARGETING::get_huid(i_target));

            this->handle_sbe_restart(i_target, false,
                   P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);

            if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>())
            {
                // Make a note that we booted from an unexpected side
                /*@
                 * @errortype   ERRL_SEV_INFORMATIONAL
                 * @moduleid    SBEIO_EXTRACT_RC_HANDLER
                 * @reasoncode  SBEIO_BOOTED_UNEXPECTED_SIDE_BKP
                 * @userdata1   0
                 * @userdata2   HUID of working proc
                 * @devdesc     SBE booted from unexpected side.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_BOOTED_UNEXPECTED_SIDE_BKP,
                            0,TARGETING::get_huid(i_target));
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM:
        {
            SBE_TRACF("proc_extract_sbe_handler(): case REIPL_UPD_SEEPROM");

            l_errl = this->switch_sbe_sides(i_target);
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
            SBE_TRACF( "Running p9_start_cbs HWP on processor target %.8X",
                   TARGETING::get_huid(i_target));

            this->handle_sbe_restart(i_target, false,
                    P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM);

            if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>())
            {
                // Make a note that we booted from an unexpected side
                /*@
                 * @errortype   ERRL_SEV_INFORMATIONAL
                 * @moduleid    SBEIO_EXTRACT_RC_HANDLER
                 * @reasoncode  SBEIO_BOOTED_UNEXPECTED_SIDE_UPD
                 * @userdata1   0
                 * @userdata2   HUID of proc
                 * @devdesc     SBE booted from unexpected side.
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_BOOTED_UNEXPECTED_SIDE_UPD,
                            0,TARGETING::get_huid(i_target));
                l_errl->collectTrace("ISTEPS_TRACE",256);
                errlCommit(l_errl, ISTEP_COMP_ID);
            }

            break;
        }
        case P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION:
        {
            SBE_TRACF("proc_extract_sbe_handler(): case NO_RECOVERY_ACTION");
            // There is no action possible. Gard and Callout the proc
            /*@
             * @errortype  ERRL_SEV_UNRECOVERABLE
             * @moduleid   SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode SBEIO_NO_RECOVERY_ACTION
             * @userdata1  SBE current error
             * @userdata2  HUID of proc
             * @devdesc    There is no recovery action on the SBE.
             *             We're garding this proc
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_NO_RECOVERY_ACTION,
                            P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION,
                            TARGETING::get_huid(i_target));
            l_errl->collectTrace( "ISTEPS_TRACE", 256);
            l_errl->addHwCallout( i_target,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::DECONFIG,
                                  HWAS::GARD_NULL );
            errlCommit(l_errl, ISTEP_COMP_ID);

            // Set register return to indicate Gard and Callout of proc
            if(o_regReturn)
            {
                SBE_TRACF("proc_extract_sbe_handler(): updating return value "
                          "to indicate that we have deconfigured the proc");
                *o_regReturn = SBE_REG_RETURN::PROC_DECONFIG;
            }

            break;
        }
        default:
        {
            //Error out, unexpected enum value returned.
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode  SBEIO_INCORRECT_FCN_CALL
             * @userdata1   SBE current error
             * @userdata2   HUID of proc
             * @devdesc     This function was called incorrectly or
             *              there is a new enum that is not handled yet.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_INCORRECT_FCN_CALL,
                            i_current_error,
                            TARGETING::get_huid(i_target));
            l_errl->collectTrace( "ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);

            break;
        }
    }

    SBE_TRACF(EXIT_MRK "proc_extract_sbe_handler");

    return;
}

SbeRetryHandler::SBE_REG_RETURN SbeRetryHandler::check_sbe_reg(
                TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "check_sbe_reg");

    errlHndl_t l_errl = nullptr;
    SbeRetryHandler::SBE_REG_RETURN l_ret =
            SbeRetryHandler::SBE_REG_RETURN::SBE_FAILED_TO_BOOT;

    do
    {
        sbeMsgReg_t l_sbeReg;

        l_errl = this->sbe_timeout_handler(&l_sbeReg,i_target,&l_ret);

        if((!l_errl) && (l_sbeReg.currState != SBE_STATE_RUNTIME))
        {
            // See if async FFDC bit is set in SBE register
            if(l_sbeReg.asyncFFDC)
            {
                bool l_flowCtrl = this->sbe_get_ffdc_handler(i_target);

                if(l_flowCtrl)
                {
                    break;
                }
            }

            // Handle that SBE failed to boot in the allowed time
            this->sbe_boot_fail_handler(i_target,l_sbeReg,&l_ret);
        }
        else if (l_errl)
        {
            SBE_TRACF("ERROR: call check_sbe_reg, PLID=0x%x", l_errl->plid() );

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

            SBE_TRACF("SUCCESS: check_sbe_reg completed okay for proc 0x%.8X",
                      TARGETING::get_huid(i_target));
        }
        //@TODO-RTC:100963 - this should match the logic in
        //call_proc_check_slave_sbe_seeprom.C
    } while(0);

    SBE_TRACF(EXIT_MRK "check_sbe_reg");
    return l_ret;

}

P9_EXTRACT_SBE_RC::RETURN_ACTION  SbeRetryHandler::handle_sbe_reg_value(
                TARGETING::Target * i_target,
                SbeRetryHandler::SBE_REG_RETURN i_sbe_reg,
                P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_sbe_error,
                bool i_fromStateMachine)
{
    errlHndl_t l_errl = NULL;
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
            P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;

    SBE_TRACF(ENTER_MRK "handle_sbe_reg_value()");

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    switch(i_sbe_reg)
    {
        case SbeRetryHandler::SBE_REG_RETURN::HWP_ERROR:
        {
            SBE_TRACF("handle_sbe_reg_value(): case FUNCTION_ERROR");
            // There has been a failure getting the SBE register
            // We cannot continue any further, return failure.
            l_ret = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            break;
        }
        case SbeRetryHandler::SBE_REG_RETURN::SBE_AT_RUNTIME:
        {
            SBE_TRACF("handle_sbe_reg_value(): case SBE_AT_RUNTIME");
            // The SBE has successfully booted at runtime
            l_ret = P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
            break;
        }
        case SbeRetryHandler::SBE_REG_RETURN::SBE_FAILED_TO_BOOT:
        {
            SBE_TRACF("handle_sbe_reg_value(): case SBE_FAILED_TO_BOOT");
            if((!i_fromStateMachine) &&
               (i_current_sbe_error == P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM))
            {
#ifdef CONFIG_BMC_IPMI
                // This could potentially take awhile, reset watchdog
                l_errl = IPMIWATCHDOG::resetWatchDogTimer();
                if(l_errl)
                {
                    SBE_TRACF("Inside handle_sbe_reg_value before sbe_handler "
                              "Resetting watchdog");
                    l_errl->collectTrace("ISTEPS_TRACE",256);
                    errlCommit(l_errl,ISTEP_COMP_ID);
                }
#endif
                SBE_TRACF("handle_sbe_reg_value(): Attempting "
                   "REIPL_UPD_SEEPROM failed. Recalling with BKP_SEEPROM");
                // If we were trying to reipl and hit the error, we need
                // to start with a new seeprom before hitting the threshold
                proc_extract_sbe_handler(i_target,
                                         P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM);
                l_ret = P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
                break;
            }

            SBE_TRACF("Inside handle_sbe_reg_value, calling p9_extract_sbe_rc HWP");
            // Get SBE extract rc
            P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
                    P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
            FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                    l_fapi2_proc_target, l_rcAction);

            if(l_errl)
            {
                SBE_TRACF("ERROR : p9_extract_sbe_rc HWP returning errorlog "
                          "PLID-0x%x", l_errl->plid());

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            if(i_fromStateMachine)
            {
                l_ret = l_rcAction;
                break;
            }

            uint8_t l_prevError = (i_target)->getAttr<
                    TARGETING::ATTR_PREVIOUS_SBE_ERROR>();
            (i_target)->setAttr<TARGETING::ATTR_PREVIOUS_SBE_ERROR>(
                            l_rcAction);

            if(i_current_sbe_error == P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM)
            {
                // Call sbe_threshold handler on the opposite side
                SBE_FSM::sbe_threshold_handler(false, i_target, l_rcAction,
                                l_prevError, this);
            }
            else
            {
                // Call sbe_threshold handler on the same side
                SBE_FSM::sbe_threshold_handler(true, i_target, l_rcAction,
                                l_prevError, this);
            }
            l_ret = P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
            break;
        }
        default:
        {
            // This should never happened
            // error out, unexpected enum value returned.
            //return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    SBEIO_HANDLE_SBE_REG_VALUE
             * @reasoncode  SBEIO_INCORRECT_FCN_CALL
             * @userdata1   HUID of target
             * @userdata2   check_sbe_reg return value
             * @devdesc     This function was called incorrectly or
             *              there is a new enum that is not handled yet.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_INFORMATIONAL,
                            SBEIO_HANDLE_SBE_REG_VALUE,
                            SBEIO_INCORRECT_FCN_CALL,
                            get_huid(i_target),i_sbe_reg);
            l_errl->collectTrace("ISTEPS_TRACE",256);
            errlCommit(l_errl, ISTEP_COMP_ID);
            l_ret = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            break;
        }
    }

    SBE_TRACF(EXIT_MRK "handle_sbe_reg_value()");
    return l_ret;
}

P9_EXTRACT_SBE_RC::RETURN_ACTION SbeRetryHandler::handle_sbe_restart(
            TARGETING::Target * i_target,
            bool i_fromStateMachine,
            P9_EXTRACT_SBE_RC::RETURN_ACTION i_current_condition)
{
    SBE_TRACF(ENTER_MRK "handle_sbe_restart()");

    errlHndl_t l_errl = NULL;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target (i_target);

    FAPI_INVOKE_HWP(l_errl, p9_start_cbs, l_fapi2_proc_target, true);
    if(l_errl)
    {
        SBE_TRACF("ERROR: call p9_start_cbs, "
                 "PLID=0x%x", l_errl->plid() );
        l_errl->collectTrace( "ISTEPS_TRACE", 256);

        errlCommit(l_errl, ISTEP_COMP_ID);
    }

    SbeRetryHandler::SBE_REG_RETURN l_checkSBE = check_sbe_reg(i_target);
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret = handle_sbe_reg_value(i_target,
                    l_checkSBE, i_current_condition, i_fromStateMachine);

    SBE_TRACF(EXIT_MRK "handle_sbe_restart()");
    return l_ret;
}

errlHndl_t SbeRetryHandler::sbe_timeout_handler(sbeMsgReg_t * o_sbeReg,
                TARGETING::Target * i_target,
                SbeRetryHandler::SBE_REG_RETURN * o_returnAction)
{
    SBE_TRACF(ENTER_MRK "sbe_timeout_handler()");

    errlHndl_t l_errl = NULL;

    (*o_returnAction) = SbeRetryHandler::SBE_REG_RETURN::SBE_FAILED_TO_BOOT;

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

    SBE_TRACF("Running p9_get_sbe_msg_register HWP on proc target %.8X",
               TARGETING::get_huid(i_target));

    for( uint64_t l_loops = 0; l_loops < SBE_NUM_LOOPS; l_loops++ )
    {
        (*o_sbeReg).reg = 0;
        FAPI_INVOKE_HWP(l_errl, p9_get_sbe_msg_register,
                        l_fapi2_proc_target, (*o_sbeReg));
        if (l_errl)
        {
            SBE_TRACF("ERROR : call p9_get_sbe_msg_register, PLID=0x%x, "
                      "on loop %d",
                      l_errl->plid(),
                      l_loops );
            (*o_returnAction) = SbeRetryHandler::SBE_REG_RETURN::HWP_ERROR;
            break;
        }
        else if ((*o_sbeReg).currState == SBE_STATE_RUNTIME)
        {
            SBE_TRACF("SBE 0x%.8X booted and at runtime, o_sbeReg=0x%.8X, "
                      "on loop %d",
                      TARGETING::get_huid(i_target), (*o_sbeReg).reg,
                      l_loops);
            (*o_returnAction) = SbeRetryHandler::SBE_REG_RETURN::SBE_AT_RUNTIME;
            break;
        }
        else if ((*o_sbeReg).asyncFFDC)
        {
            SBE_TRACF("SBE 0x%.8X has async FFDC bit set, o_sbeReg=0x%.8X",
                      TARGETING::get_huid(i_target), (*o_sbeReg).reg);
            // Async FFDC is indicator that SBE is failing to boot, and if
            // in DUMP state, that SBE is done dumping, so leave loop
            break;
        }
        else
        {
            if( !(l_loops % 10) )
            {
                SBE_TRACF("%d> SBE 0x%.8X NOT booted yet, o_sbeReg=0x%.8X",
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

        SBE_TRACF("sbe_timeout_handler: changing SCOM switches from 0x%.2X "
                  "to 0x%.2X for proc 0x%.8X",
                  l_switches_before,
                  l_switches,
                  TARGETING::get_huid(i_target));
        i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
    }

    SBE_TRACF(EXIT_MRK "sbe_timeout_handler()");
    return l_errl;
}

P9_EXTRACT_SBE_RC::RETURN_ACTION SbeRetryHandler::action_for_ffdc_rc(
                uint32_t i_rc)
{
    SBE_TRACF(ENTER_MRK "action_for_ffdc_rc()");

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
        case fapi2::RC_EXTRACT_SBE_RC_FI2C_ECC_ERR_NONSECURE_MODE:

            l_action = P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;

            break;

        case fapi2::RC_EXTRACT_SBE_RC_FI2C_TIMEOUT:
        case fapi2::RC_EXTRACT_SBE_RC_SBE_L1_LOADER_FAIL:
        case fapi2::RC_EXTRACT_SBE_RC_SBE_L2_LOADER_FAIL:
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

    SBE_TRACF(EXIT_MRK "action_for_ffdc_rc()");
    return l_action;
}

bool SbeRetryHandler::sbe_get_ffdc_handler(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_get_ffdc_handler()");

    bool l_flowCtrl = false;
    errlHndl_t l_errl = nullptr;
    uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE;
    uint32_t *l_pFifoResponse =
        reinterpret_cast<uint32_t *>(malloc(l_responseSize));

    l_errl = getFifoSBEFFDC(i_target,
                                   l_pFifoResponse,
                                   l_responseSize);

    // Check if there was an error log created
    if(l_errl)
    {
        // Trace but otherwise silently ignore error
        SBE_TRACF("sbe_get_ffdc_handler: ignoring error PLID=0x%x from "
                  "get SBE FFDC FIFO request to proc 0x%.8X",
                  l_errl->plid(),
                  TARGETING::get_huid(i_target));
        delete l_errl;
        l_errl = nullptr;
    }
    else
    {
        // Parse the FFDC package(s) in the response
        SbeFFDCParser * l_ffdc_parser =
            new SbeFFDCParser();
        l_ffdc_parser->parseFFDCData(reinterpret_cast<void *>(l_pFifoResponse));

        uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();
        P9_EXTRACT_SBE_RC::RETURN_ACTION l_action;

        // If there are FFDC packages, make a log for FFDC from SBE
        if(l_pkgs > 0)
        {
            /*@
             * @errortype
             * @moduleid     SBEIO_GET_FFDC_HANDLER
             * @reasoncode   SBEIO_RETURNED_FFDC
             * @userdata1    Processor Target
             * @userdata2    Number of FFDC packages
             * @devdesc      FFDC returned by SBE after failing to reach runtime
             * @custdesc     FFDC associated with boot device failing to boot
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             SBEIO_GET_FFDC_HANDLER,
                                             SBEIO_RETURNED_FFDC,
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
                             SBEIO_UDT_PARAMETERS,
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

    SBE_TRACF(EXIT_MRK "sbe_get_ffdc_handler()");
    return l_flowCtrl;
}

void SbeRetryHandler::sbe_boot_fail_handler(TARGETING::Target * i_target,
                           sbeMsgReg_t i_sbeReg,
                           SBE_REG_RETURN * o_regReturn)
{
    SBE_TRACF(ENTER_MRK "sbe_boot_fail_handler()");

    errlHndl_t l_errl = nullptr;

    SBE_TRACF("SBE 0x%.8X never started, sbeReg=0x%.8X",
               TARGETING::get_huid(i_target),i_sbeReg.reg );
    /*@
     * @errortype
     * @reasoncode  SBEIO_SLAVE_TIMEOUT
     * @severity    ERRORLOG::ERRL_SEV_INFORMATIONAL
     * @moduleid    SBEIO_EXTRACT_RC_HANDLER
     * @userdata1   HUID of proc which had SBE timeout
     * @userdata2   SBE MSG Register
     *
     * @devdesc Slave SBE did not get to ready state within
     *          allotted time
     *
     * @custdesc A processor in the system has failed to initialize
     */
    l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                     SBEIO_EXTRACT_RC_HANDLER,
                                     SBEIO_SLAVE_TIMEOUT,
                                     TARGETING::get_huid(i_target),
                                     i_sbeReg.reg);

    l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

    // Commit error and continue, this is not terminating since
    // we can still at least boot with master proc
    errlCommit(l_errl,ISTEP_COMP_ID);

    SBE_TRACF("Inside sbe_boot_fail_handler, calling p9_extract_sbe_rc HWP");

    // Setup for the HWP
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));
    P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
            P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
    FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                    l_fapi2ProcTarget, l_rcAction);

    //TODO:RTC 180961 handle error. ^^


    if(l_rcAction != P9_EXTRACT_SBE_RC::ERROR_RECOVERED)
    {

        if(l_errl) //TODO:RTC 180961 handle error ^^
        {
            SBE_TRACF("Error found from p9_extract_sbe, fixing later");
            SBE_TRACF("p9_extract_sbe_rc HWP returned action %d and errorlog "
                      "PLID=0x%x, rc=0x%.4X", l_rcAction, l_errl->plid(),
                      l_errl->reasonCode() );
            delete l_errl;
            l_errl = nullptr;
        }

        if(INITSERVICE::spBaseServicesEnabled())
        {
            // When we are on an FSP machine, we want to fail out of
            // hostboot and give control back to the FSP. They have
            // better diagnostics for this type of error.
            INITSERVICE::doShutdownWithError(SBEIO_HWSV_COLLECT_SBE_RC,
                                TARGETING::get_huid(i_target));
        }

        // Save the current rc error
        (i_target)->setAttr<TARGETING::ATTR_PREVIOUS_SBE_ERROR>(l_rcAction);
#ifdef CONFIG_BMC_IPMI
        // This could potentially take awhile, reset watchdog
        l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            SBE_TRACF("sbe_boot_fail_handler "
                      "Resetting watchdog before sbe_handler");
            l_errl->collectTrace("ISTEPS_TRACE",KILOBYTE/4);
            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif

        // Only attempt to recover twice before erroring out
        if((l_rcAction == P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) &&
           (g_switch_sides_count < 2))
        {
            // Change action to attempt coming up from backup SEEPROM
            l_rcAction = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
        }

        // Handle the p9_extract_sbe_rc results (as modified)
        // Pass o_regReturn back through call chain.
        proc_extract_sbe_handler( i_target,
                                  l_rcAction,
                                  o_regReturn);
    }

    if(l_errl)
    {
        SBE_TRACF("Error: sbe_boot_fail_handler : p9_extract_sbe_rc HWP "
                  " returned action %d and errorlog PLID=0x%x, rc=0x%.4X",
                  l_rcAction, l_errl->plid(), l_errl->reasonCode());

        // Capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    SBE_TRACF(EXIT_MRK "sbe_boot_fail_handler()");
    return;
}

errlHndl_t SbeRetryHandler::switch_sbe_sides(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "switch_sbe_sides()");

    errlHndl_t l_errl = NULL;
    const uint32_t l_sbeBootSelectMask = SBE::SBE_BOOT_SELECT_MASK >> 32;

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
            SBE_TRACF( ERR_MRK"switch_sbe_sides: FSI device read "
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
            SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 0 for HUID 0x%08X",
                       g_switch_sides_count,
                       TARGETING::get_huid(i_target));
            l_read_reg &= ~l_sbeBootSelectMask;
        }
        else // Currently set for Boot Side 0
        {
            // Set Boot Side 1 by setting bit for side 1
            SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 1 for HUID 0x%08X",
                       g_switch_sides_count,
                       TARGETING::get_huid(i_target));
            l_read_reg |= l_sbeBootSelectMask;
        }

        // Increment switch sides count
        ++g_switch_sides_count;
        this->iv_sbeOtherSide = true;

        // Write updated PERV_SB_CS_FSI 0x2820 back into target proc
        l_errl = DeviceFW::deviceOp(
                        DeviceFW::WRITE,
                        i_target,
                        &l_read_reg,
                        l_opSize,
                        DEVICE_FSI_ADDRESS(PERV_SB_CS_FSI_BYTE) );
        if( l_errl )
        {
            SBE_TRACF( ERR_MRK"switch_sbe_sides: FSI device write "
                      "PERV_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                      "RC=0x%X, PLID=0x%lX",
                      PERV_SB_CS_FSI_BYTE, // 0x2820
                      TARGETING::get_huid(i_target),
                      ERRL_GETRC_SAFE(l_errl),
                      ERRL_GETPLID_SAFE(l_errl));
            break;
        }
    }while(0);

    SBE_TRACF(EXIT_MRK "switch_sbe_sides()");
    return l_errl;
}

} // End of namespace SBEIO
