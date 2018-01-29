/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_retry_handler.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
#include <sbeio/sbe_retry_handler.H>
#include <secureboot/service.H>

#include <devicefw/driverif.H>


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

using namespace ERRORLOG;

namespace SBEIO
{

SbeRetryHandler::SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode)
: SbeRetryHandler(i_sbeMode, 0)
{
}

SbeRetryHandler::SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode,
                                 uint32_t i_plid)

: iv_useSDB(false)
, iv_secureModeDisabled(false) //Per HW team this should always be 0
, iv_sbeRestarted(false)
, iv_sbeSide(0)
, iv_errorLogPLID(0)
, iv_callerErrorLogPLID(i_plid)
, iv_switchSidesCount(0)
, iv_currentAction(P9_EXTRACT_SBE_RC::ERROR_RECOVERED)
, iv_currentSBEState(SBE_REG_RETURN::SBE_FAILED_TO_BOOT)
, iv_retriggeredMain(false)
, iv_sbeMode(i_sbeMode)
, iv_sbeRestartMethod(SBE_RESTART_METHOD::START_CBS)
{
    SBE_TRACF(ENTER_MRK "SbeRetryHandler::SbeRetryHandler()");

    // Initialize members that have no default initialization
    iv_sbeRegister.reg = 0;

    SBE_TRACF(EXIT_MRK "SbeRetryHandler::SbeRetryHandler()");
}

SbeRetryHandler::~SbeRetryHandler()
{

}

void SbeRetryHandler::main_sbe_handler( TARGETING::Target * i_target )
{
    SBE_TRACF(ENTER_MRK "main_sbe_handler()");

    do
    {
        errlHndl_t l_errl = NULL;

        if(!i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom)
        {
            this->iv_useSDB = true;
        }

        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));

        bool l_retry = false;

        if(this->iv_sbeMode != INFORMATIONAL_ONLY)
        {
            this->get_sbe_reg(i_target);

            if( (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME) &&
               !(this->iv_sbeMode == SBE_ACTION_SET))
            {
                // return, false if no boot is needed, true if boot is needed.
                l_retry = this->sbe_boot_fail_handler(i_target);
            }
            else if(this->iv_sbeMode == SBE_ACTION_SET)
            {
                l_retry = true;
            }

            while((this->iv_sbeRegister.currState != SBE_STATE_RUNTIME) &&
                   l_retry)
            {

                SBE_TRACF("main_sbe_handler(): current SBE state is %d, retry "
                          "is %d current SBE action is %d",
                          this->iv_sbeRegister.currState,
                          l_retry, this->iv_currentAction);

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
                 * @custdesc The SBE did not start, we will attempt a reboot
                 *           if possible
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        SBEIO_EXTRACT_RC_HANDLER,
                        SBEIO_EXTRACT_RC_ERROR,
                        TARGETING::get_huid(i_target),
                        this->iv_currentAction);

                l_errl->collectTrace("ISTEPS_TRACE",256);

                // Set the PLID of the error log to caller's PLID,
                // if provided
                if (iv_callerErrorLogPLID)
                {
                   l_errl->plid(iv_callerErrorLogPLID);
                }

                // Commit error and continue
                errlCommit(l_errl, ISTEP_COMP_ID);

                // if no recovery action, fail out.
                if(this->iv_currentAction ==
                                P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION)
                {
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

                    // Cache PLID of error log
                    iv_errorLogPLID = l_errl->plid();

                    // Set the PLID of the error log to caller's PLID,
                    // if provided
                    if (iv_callerErrorLogPLID)
                    {
                       l_errl->plid(iv_callerErrorLogPLID);
                    }

                    errlCommit(l_errl, ISTEP_COMP_ID);

                    SBE_TRACF("main_sbe_handler(): updating return value "
                          "to indicate that we have deconfigured the proc");
                    this->iv_currentSBEState = SBE_REG_RETURN::PROC_DECONFIG;

                    break;
                }

                // if the bkp_seeprom or upd_seeprom, attempt to switch sides.
                // This is also dependent on the iv_switchSideCount.
                if(this->iv_currentAction ==
                                P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM ||
                   this->iv_currentAction ==
                                P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM)
                {
                    l_errl = this->switch_sbe_sides(i_target);
                    if(l_errl)
                    {
                        errlCommit(l_errl, ISTEP_COMP_ID);
                        break;
                    }
                }

                // Attempt SBE restart
                if(this->iv_sbeRestartMethod == SBE_RESTART_METHOD::START_CBS)
                {
                    SBE_TRACF("Invoking p9_start_cbs HWP");
                    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                          l_fapi2_proc_target (i_target);

                    FAPI_INVOKE_HWP(l_errl, p9_start_cbs,
                                    l_fapi2_proc_target, true);
                    if(l_errl)
                    {
                        SBE_TRACF("ERROR: call p9_start_cbs, PLID=0x%x",
                                   l_errl->plid() );
                        l_errl->collectTrace( "ISTEPS_TRACE", 256 );

                        // Gard the target, when SBE Retry fails
                        l_errl->addHwCallout(i_target,
                                             HWAS::SRCI_PRIORITY_HIGH,
                                             HWAS::NO_DECONFIG,
                                             HWAS::GARD_Predictive);

                        // Set the PLID of the error log to caller's PLID,
                        // if provided
                        if (iv_callerErrorLogPLID)
                        {
                           l_errl->plid(iv_callerErrorLogPLID);
                        }

                        errlCommit( l_errl, ISTEP_COMP_ID);
                    }
                }else
                {
                    //@todo - RTC:180242 - Restart SBE
                }

                // Get the sbe register
                this->get_sbe_reg(i_target);

                if( (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME))
                {
                    // return, false if no boot is needed.
                    l_retry = this->sbe_boot_fail_handler(i_target);
                }
            }
        }
        else
        {
            // In the informational only mode, we just need enough information
            // to get the SBE RC returned from the HWP.  We are running with
            // the knowledge that the SBE has failed already.
            this->sbe_boot_fail_handler(i_target, true); // pass true to have log show up
            this->iv_currentSBEState = SBE_FAILED_TO_BOOT;
        }

        this->handle_sbe_reg_value(i_target);

        // if we have started the sbe, and the current action is upd_seeprom
        // or bkp_seeprom, note that we started on an unexpected side
        if(i_target->getAttr<TARGETING::ATTR_SBE_IS_STARTED>() &&
           (this->iv_currentAction == P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM ||
            this->iv_currentAction == P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM) )
        {
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode  SBEIO_BOOTED_UNEXPECTED_SIDE
             * @userdata1   0
             * @userdata2   HUID of working proc
             * @devdesc     SBE booted from unexpected side.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        SBEIO_EXTRACT_RC_HANDLER,
                        SBEIO_BOOTED_UNEXPECTED_SIDE,
                        0,TARGETING::get_huid(i_target));
            l_errl->collectTrace("ISTEPS_TRACE",256);

            // Set the PLID of the error log to caller's PLID,
            // if provided
            if (iv_callerErrorLogPLID)
            {
                l_errl->plid(iv_callerErrorLogPLID);
            }

            errlCommit(l_errl, ISTEP_COMP_ID);
        }

    }while(0);

    SBE_TRACF(EXIT_MRK "main_sbe_handler()");
}

void SbeRetryHandler::get_sbe_reg(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "get_sbe_reg()");

    errlHndl_t l_errl = nullptr;

    do
    {
        l_errl = this->sbe_timeout_handler(i_target);

        if((!l_errl) && (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME))
        {
            // See if async FFDC bit is set in SBE register
            if(this->iv_sbeRegister.asyncFFDC)
            {
                bool l_flowCtrl = this->sbe_get_ffdc_handler(i_target);

                if(l_flowCtrl)
                {
                    break;
                }
            }
        }
        else if (l_errl)
        {
            SBE_TRACF("ERROR: call get_sbe_reg, PLID=0x%x", l_errl->plid() );

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
            this->iv_sbeRestarted = true;

            SBE_TRACF("SUCCESS: get_sbe_reg completed okay for proc 0x%.8X",
                      TARGETING::get_huid(i_target));
        }
        //@TODO-RTC:100963 - this should match the logic in
        //call_proc_check_slave_sbe_seeprom.C
    } while(0);

    SBE_TRACF(EXIT_MRK "get_sbe_reg()");

}

void SbeRetryHandler::handle_sbe_reg_value(TARGETING::Target * i_target)
{
    errlHndl_t l_errl = NULL;

    SBE_TRACF(ENTER_MRK "handle_sbe_reg_value()");

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    switch(this->iv_currentSBEState)
    {
        case SbeRetryHandler::SBE_REG_RETURN::HWP_ERROR:
        {
            SBE_TRACF("handle_sbe_reg_value(): case FUNCTION_ERROR");
            // There has been a failure getting the SBE register
            // We cannot continue any further, return failure.
            this->iv_currentAction = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            break;
        }
        case SbeRetryHandler::SBE_REG_RETURN::SBE_AT_RUNTIME:
        {
            SBE_TRACF("handle_sbe_reg_value(): case SBE_AT_RUNTIME");
            // The SBE has successfully booted at runtime
            this->iv_currentAction = P9_EXTRACT_SBE_RC::ERROR_RECOVERED;
            break;
        }
        case SbeRetryHandler::SBE_REG_RETURN::SBE_FAILED_TO_BOOT:
        {
            SBE_TRACF("handle_sbe_reg_value(): case SBE_FAILED_TO_BOOT");
            if((this->iv_currentAction == P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM)
                && (!iv_retriggeredMain))

            {
                iv_retriggeredMain = true;
#ifdef CONFIG_BMC_IPMI
#ifndef __HOSTBOOT_RUNTIME
                // This could potentially take awhile, reset watchdog
                l_errl = IPMIWATCHDOG::resetWatchDogTimer();
                if(l_errl)
                {
                    SBE_TRACF("Inside handle_sbe_reg_value before sbe_handler "
                              "Resetting watchdog");
                    l_errl->collectTrace("ISTEPS_TRACE",256);

                    // Set the PLID of the error log to caller's PLID,
                    // if provided
                    if (iv_callerErrorLogPLID)
                    {
                       l_errl->plid(iv_callerErrorLogPLID);
                    }

                    errlCommit(l_errl,ISTEP_COMP_ID);
                }
#endif
#endif
                SBE_TRACF("handle_sbe_reg_value(): Attempting "
                   "REIPL_UPD_SEEPROM failed. Recalling with BKP_SEEPROM");
                // If we were trying to reipl and hit the error, we need
                // to start with a new seeprom before hitting the threshold
                this->iv_currentAction =
                      P9_EXTRACT_SBE_RC::RETURN_ACTION::REIPL_BKP_SEEPROM;
                this->iv_sbeMode = SBE_MODE_OF_OPERATION::SBE_ACTION_SET;
                main_sbe_handler(i_target);
                break;
            }

            // Failed to boot, setting the final action for debugging.
            SBE_TRACF("Inside handle_sbe_reg_value, calling "
                      "p9_extract_sbe_rc HWP");
            // Get SBE extract rc
            P9_EXTRACT_SBE_RC::RETURN_ACTION l_rcAction =
                    P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;
            FAPI_INVOKE_HWP(l_errl, p9_extract_sbe_rc,
                    l_fapi2_proc_target, l_rcAction);
            this->iv_currentAction = l_rcAction;

            SBE_TRACF("handle_sbe_reg_value(): SBE failed to boot. Final "
                      "action is %llx", l_rcAction);

            if(l_errl)
            {
                SBE_TRACF("ERROR : p9_extract_sbe_rc HWP returning errorlog "
                          "PLID-0x%x", l_errl->plid());

                // capture the target data in the elog
                ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);

                // Cache PLID of error log
                iv_errorLogPLID = l_errl->plid();

                // Set the PLID of the error log to caller's PLID,
                // if provided
                if (iv_callerErrorLogPLID)
                {
                   l_errl->plid(iv_callerErrorLogPLID);
                }

                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }

            break;
        }
        default:
        {
            // This should never happened
            // error out, unexpected enum value returned.
            //return P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            /*@
             * @errortype   ERRL_SEV_PREDICTIVE
             * @moduleid    SBEIO_HANDLE_SBE_REG_VALUE
             * @reasoncode  SBEIO_INCORRECT_FCN_CALL
             * @userdata1   HUID of target
             * @userdata2   SBE current state
             * @devdesc     This function was called incorrectly or
             *              there is a new enum that is not handled yet.
             */
            l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            SBEIO_HANDLE_SBE_REG_VALUE,
                            SBEIO_INCORRECT_FCN_CALL,
                            get_huid(i_target),this->iv_currentSBEState);
            l_errl->collectTrace("ISTEPS_TRACE",256);

            // Set the PLID of the error log to caller's PLID,
            // if provided
            if (iv_callerErrorLogPLID)
            {
                l_errl->plid(iv_callerErrorLogPLID);
            }

            errlCommit(l_errl, ISTEP_COMP_ID);
            this->iv_currentAction = P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            break;
        }
    }
    SBE_TRACF(EXIT_MRK "handle_sbe_reg_value()");
}

errlHndl_t SbeRetryHandler::sbe_timeout_handler(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_timeout_handler()");

    errlHndl_t l_errl = NULL;

    this->iv_currentSBEState =
            SbeRetryHandler::SBE_REG_RETURN::SBE_FAILED_TO_BOOT;

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
        sbeMsgReg_t l_reg;
        FAPI_INVOKE_HWP(l_errl, p9_get_sbe_msg_register,
                        l_fapi2_proc_target, l_reg);
        this->iv_sbeRegister = l_reg;
        if (l_errl)
        {
            SBE_TRACF("ERROR : call p9_get_sbe_msg_register, PLID=0x%x, "
                      "on loop %d",
                      l_errl->plid(),
                      l_loops );
            this->iv_currentSBEState =
                    SbeRetryHandler::SBE_REG_RETURN::HWP_ERROR;
            break;
        }
        else if ((this->iv_sbeRegister).currState == SBE_STATE_RUNTIME)
        {
            SBE_TRACF("SBE 0x%.8X booted and at runtime, "
                      "iv_sbeRegister=0x%.8X, on loop %d",
                      TARGETING::get_huid(i_target),
                      (this->iv_sbeRegister).reg,
                      l_loops);
            this->iv_currentSBEState =
                  SbeRetryHandler::SBE_REG_RETURN::SBE_AT_RUNTIME;
            break;
        }
        else if ((this->iv_sbeRegister).asyncFFDC)
        {
            SBE_TRACF("SBE 0x%.8X has async FFDC bit set, "
                      "iv_sbeRegister=0x%.8X",TARGETING::get_huid(i_target),
                      (this->iv_sbeRegister).reg);
            // Async FFDC is indicator that SBE is failing to boot, and if
            // in DUMP state, that SBE is done dumping, so leave loop
            break;
        }
        else
        {
            if( !(l_loops % 10) )
            {
                SBE_TRACF("%d> SBE 0x%.8X NOT booted yet, "
                          "iv_sbeRegister=0x%.8X", l_loops,
                          TARGETING::get_huid(i_target),
                           (this->iv_sbeRegister).reg);
            }
            l_loops++;
            nanosleep(0,SBE_WAIT_SLEEP);
        }
    }

    if ((this->iv_sbeRegister).currState != SBE_STATE_RUNTIME)
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

    // Set the PLID of the error log to caller's PLID,
    // if provided
    if (l_errl && iv_callerErrorLogPLID)
    {
        l_errl->plid(iv_callerErrorLogPLID);
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
    uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE;
    uint32_t *l_pFifoResponse =
        reinterpret_cast<uint32_t *>(malloc(l_responseSize));

#ifndef __HOSTBOOT_RUNTIME
    errlHndl_t l_errl = nullptr;
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
            this->iv_currentAction = l_action;
            this->iv_retriggeredMain = true;
            this->iv_sbeMode = SBE_MODE_OF_OPERATION::SBE_ACTION_SET;
            main_sbe_handler(i_target);
        }

        // If there are FFDC packages, commit the log
        if(l_pkgs > 0)
        {
            l_errl->collectTrace( SBEIO_COMP_NAME, KILOBYTE/4);
            l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

            // Set the PLID of the error log to caller's PLID,
            // if provided
            if (iv_callerErrorLogPLID)
            {
                l_errl->plid(iv_callerErrorLogPLID);
            }

            errlCommit(l_errl, ISTEP_COMP_ID);
        }

        delete l_ffdc_parser;
        l_ffdc_parser = nullptr;

        l_flowCtrl = true;
    }
#endif

    free(l_pFifoResponse);
    l_pFifoResponse = nullptr;

    SBE_TRACF(EXIT_MRK "sbe_get_ffdc_handler()");
    return l_flowCtrl;
}

//By default we want to call the 2 param version of the func w/ "true"
//passed in to tell the function we want to hide the mandatory errlog
bool SbeRetryHandler::sbe_boot_fail_handler(TARGETING::Target * i_target)
{
    return SbeRetryHandler::sbe_boot_fail_handler(i_target, false);
}

bool SbeRetryHandler::sbe_boot_fail_handler(TARGETING::Target * i_target,
                                            bool i_exposeLog)
{
    SBE_TRACF(ENTER_MRK "sbe_boot_fail_handler()");

    errlHndl_t l_errl = nullptr;
    fapi2::ReturnCode l_rc;
    bool o_needRetry = false;

    SBE_TRACF("SBE 0x%.8X never started, sbeReg=0x%.8X",
               TARGETING::get_huid(i_target),(this->iv_sbeRegister).reg );
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
                                     (this->iv_sbeRegister).reg);

    l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

    // Set the PLID of the error log to caller's PLID,
    // if provided
    if (iv_callerErrorLogPLID)
    {
        l_errl->plid(iv_callerErrorLogPLID);
    }

    if(i_exposeLog)
    {
        l_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);

    }

    // Commit error and continue, this is not terminating since
    // we can still at least boot with master proc
    errlCommit(l_errl,ISTEP_COMP_ID);

    SBE_TRACF("Inside sbe_boot_fail_handler, calling p9_extract_sbe_rc HWP");

    // Setup for the HWP
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));

    P9_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
                     P9_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM;

    //Note that we are calling this while we are already inside
    //of a FAPI_INVOKE_HWP call. This might cause issue w/ current_err
    //but unsure how to get around it.
    FAPI_EXEC_HWP(l_rc, p9_extract_sbe_rc, l_fapi2ProcTarget,
                  l_ret, iv_useSDB, iv_secureModeDisabled);

    l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
    this->iv_currentAction = l_ret;

    if(this->iv_currentAction != P9_EXTRACT_SBE_RC::ERROR_RECOVERED)
    {

        if(l_errl)
        {
            SBE_TRACF("p9_extract_sbe_rc HWP returned action %d and errorlog "
                      "PLID=0x%x, rc=0x%.4X", this->iv_currentAction,
                      l_errl->plid(), l_errl->reasonCode() );
            delete l_errl;
            l_errl = nullptr;
        }

        if(INITSERVICE::spBaseServicesEnabled())
        {
#ifndef __HOSTBOOT_RUNTIME
            // When we are on an FSP machine, we want to fail out of
            // hostboot and give control back to the FSP. They have
            // better diagnostics for this type of error.
            INITSERVICE::doShutdownWithError(SBEIO_HWSV_COLLECT_SBE_RC,
                                TARGETING::get_huid(i_target));
#endif
        }

#ifdef CONFIG_BMC_IPMI
#ifndef __HOSTBOOT_RUNTIME
        // This could potentially take awhile, reset watchdog
        l_errl = IPMIWATCHDOG::resetWatchDogTimer();
        if(l_errl)
        {
            SBE_TRACF("sbe_boot_fail_handler "
                      "Resetting watchdog before sbe_handler");
            l_errl->collectTrace("ISTEPS_TRACE",KILOBYTE/4);

            // Set the PLID of the error log to caller's PLID,
            // if provided
            if (iv_callerErrorLogPLID)
            {
                l_errl->plid(iv_callerErrorLogPLID);
            }

            errlCommit(l_errl,ISTEP_COMP_ID);
        }
#endif
#endif
        SBE_TRACF("sbe_boot_fail_handler. iv_switchSides count is %llx",
                   iv_switchSidesCount);
        if((this->iv_currentAction == P9_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) &&
           (iv_switchSidesCount < MAX_SWITCH_SIDE_COUNT))
        {
            this->iv_currentAction = P9_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
            o_needRetry = true;
        }
        else if(iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT)
        {
            o_needRetry = false;
        }
        else
        {
            o_needRetry = true;
        }

    }
    if(l_errl)
    {
        SBE_TRACF("Error: sbe_boot_fail_handler : p9_extract_sbe_rc HWP "
                  " returned action %d and errorlog PLID=0x%x, rc=0x%.4X",
                  this->iv_currentAction, l_errl->plid(), l_errl->reasonCode());

        // Capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

        // Set the PLID of the error log to caller's PLID,
        // if provided
        if (iv_callerErrorLogPLID)
        {
           l_errl->plid(iv_callerErrorLogPLID);
        }

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    SBE_TRACF(EXIT_MRK "sbe_boot_fail_handler() current action is %llx",
                        this->iv_currentAction);
    return o_needRetry;
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
                       iv_switchSidesCount,
                       TARGETING::get_huid(i_target));
            l_read_reg &= ~l_sbeBootSelectMask;
            this->iv_sbeSide = 1;
        }
        else // Currently set for Boot Side 0
        {
            // Set Boot Side 1 by setting bit for side 1
            SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 1 for HUID 0x%08X",
                       iv_switchSidesCount,
                       TARGETING::get_huid(i_target));
            l_read_reg |= l_sbeBootSelectMask;
            this->iv_sbeSide = 0;
        }

        SBE_TRACF("switch_sbe_sides(): iv_switchSidesCount is %llx",
                   iv_switchSidesCount);
        // Increment switch sides count
        ++iv_switchSidesCount;

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

    // Set the PLID of the error log to caller's PLID,
    // if provided
    if (l_errl && iv_callerErrorLogPLID)
    {
       l_errl->plid(iv_callerErrorLogPLID);
    }

    SBE_TRACF(EXIT_MRK "switch_sbe_sides()");
    return l_errl;
}

} // End of namespace SBEIO
