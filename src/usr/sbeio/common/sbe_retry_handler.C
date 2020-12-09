/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/sbe_retry_handler.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2020                        */
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
 * @file sbe_retry_handler.C
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
#include <errl/errlreasoncodes.H>
#include <p10_extract_sbe_rc.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/initsvcreasoncodes.H>
#include <errl/errludtarget.H>
#include <util/misc.H>
#include <ipmi/ipmiwatchdog.H>

#include <p10_start_cbs.H>
#include <p10_sbe_hreset.H>
#include <p10_get_sbe_msg_register.H>
#include <p10_scom_perv_a.H>
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
#include <plat_utils.H>



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
using namespace fapi2;
using namespace scomt::perv;

namespace SBEIO
{

// Define constant expressions to be used

//There are only 2 sides to the seeproms, so we only want to flip sides once
constexpr uint8_t MAX_SWITCH_SIDE_COUNT         = 1;

//We only want to attempt to boot with the same side seeprom twice
constexpr uint8_t MAX_SIDE_BOOT_ATTEMPTS        = 2;

// Currently we expect a maxiumum of 2 FFDC packets, the one
// that is useful to HB is the HWP FFDC. It is possible there is
//  a packet that details an internal sbe fail that hostboot will
// add to an errorlog but otherwise ignores
constexpr uint8_t MAX_EXPECTED_FFDC_PACKAGES    = 2;

// Set up constants that will be used for setting up the timeout for
// reading the sbe message register
constexpr uint64_t SBE_RETRY_TIMEOUT_HW_SEC     = 60;  // 60 seconds
constexpr uint64_t SBE_RETRY_TIMEOUT_SIMICS_SEC = 600; // 600 seconds
constexpr uint32_t SBE_RETRY_NUM_LOOPS          = 60;

SbeRetryHandler::SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode)
: SbeRetryHandler(i_sbeMode, 0)
{
}

SbeRetryHandler::SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode,
                                 uint32_t i_plid)

: iv_useSDB(false)
, iv_secureModeDisabled(false) //Per HW team this should always be 0
, iv_masterErrorLogPLID(i_plid)
, iv_switchSidesCount(0)
, iv_currentAction(P10_EXTRACT_SBE_RC::ERROR_RECOVERED)
, iv_currentSBEState(SBE_REG_RETURN::SBE_NOT_AT_RUNTIME)
, iv_shutdownReturnCode(0)
, iv_currentSideBootAttempts(1) // It is safe to assume that the current side has attempted to boot
, iv_sbeMode(i_sbeMode)
, iv_sbeRestartMethod(SBE_RESTART_METHOD::HRESET)
, iv_initialPowerOn(false)
{
    SBE_TRACF(ENTER_MRK "SbeRetryHandler::SbeRetryHandler()");

    // Initialize members that have no default initialization
    iv_sbeRegister.reg = 0;

    SBE_TRACF(EXIT_MRK "SbeRetryHandler::SbeRetryHandler()");
}

SbeRetryHandler::~SbeRetryHandler() {}

void SbeRetryHandler::main_sbe_handler( TARGETING::Target * i_target )
{
    SBE_TRACF(ENTER_MRK "main_sbe_handler()");
    do
    {
        errlHndl_t l_errl = nullptr;

        // Only set the secure debug bit (SDB) if we are not using xscom yet
        if(!i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom &&
            !i_target->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>())
        {
            this->iv_useSDB = true;
        }

        // Get the SBE status register, this will tell us what state
        // the SBE is in , if the asynFFDC bit is set on the sbe_reg
        // then FFDC will be collected at this point in time.
        // sbe_run_extract_msg_reg will return true if there was an error reading the status
        if(!this->sbe_run_extract_msg_reg(i_target))
        {
            SBE_TRACF("main_sbe_handler(): Failed to get sbe register something is seriously wrong, we should always be able to read that!!");
            //Error log should have already committed in sbe_run_extract_msg_reg for this issue
            break;
        }

        // We will only trust the currState value if we know the SBE has just been booted.
        // In this case we have been told by the caller that the sbe just powered on
        // so it is safe to assume that the currState value is legit and we can trust that
        // the sbe has booted successfully to runtime.
        if( this->iv_initialPowerOn && (this->iv_sbeRegister.currState == SBE_STATE_RUNTIME))
        {
            //We have successfully powered on the SBE
            SBE_TRACF("main_sbe_handler(): Initial power on of the SBE was a success!!");
            break;
        }

        //////******************************************************************
        // If we have made it this far we can assume that something is wrong w/ the SBE
        //////******************************************************************

        // If something is wrong w/ the SBE during IPL time on a FSP based system then
        // we will always TI and let hwsv deal with the problem. This is a unique path
        // so we will have it handled in a separate procedure
#ifndef __HOSTBOOT_RUNTIME
        if(INITSERVICE::spBaseServicesEnabled())
        {
            if(iv_initialPowerOn)
            {
                // If this is the initial power on there will be no logs that point out this fail
                // so we need to create one now
                /*@
                * @errortype  ERRL_SEV_UNRECOVERABLE
                * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                * @reasoncode SBEIO_SLAVE_FAILED_TO_BOOT
                * @userdata1  Bool to describe if FFDC data is found
                * @userdata2  HUID of proc
                * @devdesc    There was a problem attempting to boot SBE
                *             on the slave processor
                * @custdesc   Processor Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_SLAVE_FAILED_TO_BOOT,
                            this->iv_sbeRegister.asyncFFDC,
                            TARGETING::get_huid(i_target));

                l_errl->collectTrace( "ISTEPS_TRACE", 256);
                l_errl->collectTrace( SBEIO_COMP_NAME, 256);
                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
            }
            // This function will TI Hostboot so don't expect to return
            handleFspIplTimeFail(i_target);
            SBE_TRACF("main_sbe_handler(): We failed to TI the system when we should have, forcing an assert(0) call");
            // We should never return from handleFspIplTimeFail
            assert(0, "We have determined that there was an error with the SBE and should have TI'ed but for some reason we did not.");
        }
#endif


        // if the sbe is not booted at all extract_rc will fail so we only
        // will run extract RC if we know the sbe has at least tried to boot
        if(this->iv_sbeRegister.sbeBooted)
        {
            SBE_TRACF("main_sbe_handler(): No async ffdc found and sbe says it has been booted, running p10_sbe_extract_rc.");
            // Call the function that runs extract_rc, this needs to run to determine
            // what broke and what our retry action should be
            this->sbe_run_extract_rc(i_target);
        }
        // If we have determined that the sbe never booted
        // then set the current action to be "restart sbe"
        // that way we will attempt to start the sbe again
        else
        {
            SBE_TRACF("main_sbe_handler(): SBE reports it was never booted, calling p10_sbe_extract_rc will fail. Setting action to be RESTART_SBE");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::RESTART_SBE;
        }

        // If the mode was marked as informational that means the caller did not want
        // any actions to take place, the caller only wanted information collected
        if(this->iv_sbeMode == INFORMATIONAL_ONLY)
        {
            SBE_TRACF("main_sbe_handler(): Retry handler is being called in INFORMATIONAL mode so we are exiting without attempting any retry actions");
            break;
        }

        // This do-while loop will continuously look at iv_currentAction, act
        // accordingly, then read status register and determine next action.
        // The ideal way to exit the loop is if the SBE makes it up to runtime after
        // attempting a retry which indicates we have recovered. If the currentAction
        // says NO_RECOVERY_ACTION then we break out of this loop.  Also if we fail
        // to read the sbe's status register or if we get write fails when trying to switch
        // seeprom sides. Both the fails mentioned last indicate there is a larger problem
        do
        {
            // We need to handle the following values that currentAction could be,
            // it is possible that iv_currentAction can be any of these values except there
            // is currently no path that will set it to be ERROR_RECOVERED
            //        ERROR_RECOVERED    = 0,
            //           - We should never hit this, if we have recovered then
            //             curreState should be RUNTIME
            //        RESTART_SBE        = 1,
            //        RESTART_CBS        = 2,
            //           - We will not listen to p10_extract_rc on HOW to restart the
            //             sbe. We will assume iv_sbeRestartMethod is correct and
            //             perform the restart method that iv_sbeRestartMethod says
            //             regardless if currentAction = RESTART_SBE or RESTART_CBS
            //        REIPL_BKP_SEEPROM  = 3,
            //        REIPL_UPD_SEEPROM  = 4,
            //            - We will switch the seeprom side (if we have not already)
            //            - then attempt to restart the sbe w/ iv_sbeRestartMethod
            //        NO_RECOVERY_ACTION = 5,
            //            - we deconfigure the processor we are retrying and fail out
            //
            // Important things to remember, we only want to attempt a single side
            // a maxiumum of 2 times, and also we only want to switch sides once

            SBE_TRACF("main_sbe_handler(): iv_sbeRegister.currState: %d , "
                        "iv_currentSideBootAttempts: %d , "
                        "iv_currentAction: %d , ",
                        this->iv_sbeRegister.currState,
                        this->iv_currentSideBootAttempts,
                        this->iv_currentAction);

            if(this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION)
            {
                SBE_TRACF("main_sbe_handler(): We have concluded there are no further recovery actions to take, deconfiguring proc and exiting handler");
                /* There is no action possible. Gard and Callout the proc
                    * @errortype  ERRL_SEV_UNRECOVERABLE
                    * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                    * @reasoncode SBEIO_NO_RECOVERY_ACTION
                    * @userdata1  SBE current error
                    * @userdata2  HUID of proc
                    * @devdesc    There is no recovery action on the SBE.
                    *             We're deconfiguring this proc
                    * @custdesc   Processor Error
                    */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_NO_RECOVERY_ACTION,
                            P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION,
                            TARGETING::get_huid(i_target));
                l_errl->collectTrace( "ISTEPS_TRACE", 256);
                l_errl->collectTrace( SBEIO_COMP_NAME, 256);
                l_errl->addHwCallout( i_target,
                                        HWAS::SRCI_PRIORITY_HIGH,
                                        HWAS::DELAYED_DECONFIG,
                                        HWAS::GARD_NULL );

                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
                this->iv_currentSBEState = SBE_REG_RETURN::PROC_DECONFIG;
                break;
            }

            // if the bkp_seeprom or upd_seeprom, attempt to switch sides.
            // This is also dependent on the iv_switchSideCount.
            // Note: we do this for upd_seeprom because we don't support
            //       updating the seeprom during IPL time
            if((this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM ||
                this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM))
            {
                // We cannot switch sides and perform an hreset if the seeprom's
                // versions do not match. If this happens, log an error and stop
                // trying to recover the SBE
                if(this->iv_sbeRestartMethod == HRESET)
                {
                    TARGETING::ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH_type l_versionsMismatch =
                            i_target->getAttr<TARGETING::ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH>();

                    if(l_versionsMismatch)
                    {
                        SBE_TRACF("main_sbe_handler(): We cannot switch SEEPROM sides if their versions do not match, exiting handler");
                        /*@
                            * @errortype  ERRL_SEV_UNRECOVERABLE
                            * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                            * @reasoncode SBEIO_SEEPROM_VERSION_MISMATCH
                            * @userdata1  HUID of proc
                            * @userdata2  unused
                            * @devdesc    Attempted to swap seeprom sides and
                            *             boot using hreset but version mismatched
                            * @custdesc   Processor Error
                            */
                        l_errl = new ERRORLOG::ErrlEntry(
                                    ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                    SBEIO_EXTRACT_RC_HANDLER,
                                    SBEIO_SEEPROM_VERSION_MISMATCH,
                                    TARGETING::get_huid(i_target),0);
                        l_errl->collectTrace( "ISTEPS_TRACE", 256);
                        l_errl->collectTrace( SBEIO_COMP_NAME, 256);
                        l_errl->addHwCallout( i_target,
                                                HWAS::SRCI_PRIORITY_HIGH,
                                                HWAS::NO_DECONFIG,
                                                HWAS::GARD_NULL );

                        // Set the PLID of the error log to master PLID
                        // if the master PLID is set
                        updatePlids(l_errl);

                        errlCommit(l_errl, SBEIO_COMP_ID);
                        // break out of the retry loop
                        break;
                    }
                }
                if(this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT)
                {
                    /*@
                    * @errortype  ERRL_SEV_PREDICTIVE
                    * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                    * @reasoncode SBEIO_EXCEED_MAX_SIDE_SWITCHES
                    * @userdata1  Switch Sides Count
                    * @userdata2  HUID of proc
                    * @devdesc    We have already flipped seeprom sides once
                    *             and we should not have attempted to flip again
                    * @custdesc   Processor Error
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                SBEIO_EXTRACT_RC_HANDLER,
                                SBEIO_EXCEED_MAX_SIDE_SWITCHES,
                                this->iv_switchSidesCount,
                                TARGETING::get_huid(i_target));
                    l_errl->collectTrace( SBEIO_COMP_NAME, 256);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit(l_errl, SBEIO_COMP_ID);
                    // Break out of loop, something bad happened and we dont want end
                    // up in a endless loop
                    break;
                }
                l_errl = this->switch_sbe_sides(i_target);
                if(l_errl)
                {
                    errlCommit(l_errl, SBEIO_COMP_ID);
                    // If any error occurs while we are trying to switch sides
                    // this indicates big problems so we want to break out of the
                    // retry loop
                    break;
                }
                // Note that we do not want to continue here because we want to
                // attempt to restart using whatever sbeRestartMethod is set to after
                // switching seeprom sides
            }

            // Both of the retry methods require a FAPI2 version of the target because they
            // are fapi2 HWPs
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2_proc_target (i_target);
            if(this->iv_currentSideBootAttempts >= MAX_SIDE_BOOT_ATTEMPTS)
            {
               /*@
                * @errortype  ERRL_SEV_PREDICTIVE
                * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                * @reasoncode SBEIO_EXCEED_MAX_SIDE_BOOTS
                * @userdata1  # of boots attempts on this side
                * @userdata2  HUID of proc
                * @devdesc    We have already done the max attempts for
                *             the current seeprom side. For some reason
                *             we are attempting to do another boot.
                * @custdesc   Processor Error
                */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_EXCEED_MAX_SIDE_BOOTS,
                            this->iv_currentSideBootAttempts,
                            TARGETING::get_huid(i_target));

                l_errl->collectTrace( SBEIO_COMP_NAME, 256);

                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
                // Break out of loop, something bad happened and we dont want end
                // up in a endless loop
                break;
            }
            // Look at the sbeRestartMethd instance variable to determine which method
            // we will use to attempt the restart. In general during IPL time we will
            // attempt CBS, during runtime we will want to use HRESET.
            else if(this->iv_sbeRestartMethod == SBE_RESTART_METHOD::START_CBS)
            {
                //Increment attempt count for this side
                this->iv_currentSideBootAttempts++;

                SBE_TRACF("Invoking p10_start_cbs HWP on processor %.8X", get_huid(i_target));

                // We cannot use FAPI_INVOKE in this case because it is possible
                // we are handling a HWP fail. If we attempted to use FAPI_INVOKE
                // while we are already inside a FAPI_INVOKE call then we can
                // end up in an endless wait on the fapi mutex lock
                fapi2::ReturnCode l_rc;

                // For now we only use p10_start_cbs if we fail to boot the slave SBE
                // on our initial attempt, the bool param is true we are telling the
                // HWP that we are starting up the SBE which is true in this case
                FAPI_EXEC_HWP(l_rc, p10_start_cbs,
                                l_fapi2_proc_target, true);

                l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);

                if(l_errl)
                {
                    SBE_TRACF("ERROR: call p10_start_cbs, PLID=0x%x",
                                l_errl->plid() );
                    l_errl->collectTrace(SBEIO_COMP_NAME, 256 );
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_errl->collectTrace(FAPI_TRACE_NAME, 384);

                    // Deconfig the target when SBE Retry fails
                    l_errl->addHwCallout(i_target,
                                            HWAS::SRCI_PRIORITY_LOW,
                                            HWAS::DELAYED_DECONFIG,
                                            HWAS::GARD_NULL);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit( l_errl, SBEIO_COMP_ID);
                    // If we got an errlog while attempting start_cbs
                    // we will assume that no future retry actions
                    // will work so we will break out of the retry loop
                    break;
                }
            }
            // The only other type of reset method is HRESET
            else
            {
                // Increment attempt count for this side
                this->iv_currentSideBootAttempts++;

                SBE_TRACF("Invoking p10_sbe_hreset HWP on processor %.8X", get_huid(i_target));

                // We cannot use FAPI_INVOKE in this case because it is possible
                // we are handling a HWP fail. If we attempted to use FAPI_INVOKE
                // while we are already inside a FAPI_INVOKE call then we can
                // end up in an endless wait on the fapi mutex lock
                fapi2::ReturnCode l_rc;

                // For now we only use HRESET during runtime
                FAPI_EXEC_HWP(l_rc, p10_sbe_hreset,
                                l_fapi2_proc_target);

                l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);

                if(l_errl)
                {
                    SBE_TRACF("ERROR: call p10_sbe_hreset, PLID=0x%x",
                                l_errl->plid() );
                    l_errl->collectTrace(SBEIO_COMP_NAME, 256 );
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_errl->collectTrace(FAPI_TRACE_NAME, 384);

                    // Deconfig the target when SBE Retry fails
                    l_errl->addHwCallout(i_target,
                                            HWAS::SRCI_PRIORITY_LOW,
                                            HWAS::DELAYED_DECONFIG,
                                            HWAS::GARD_NULL);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit( l_errl, SBEIO_COMP_ID);
                    // If we got an errlog while attempting p10_sbe_hreset
                    // we will assume that no future retry actions
                    // will work so we will exit
                    break;
                }
            }

            // Get the sbe register  (note that if asyncFFDC bit is set in status register then
            // we will read it in this call)
            if(!this->sbe_run_extract_msg_reg(i_target))
            {
                // Error log should have already committed in sbe_run_extract_msg_reg for this issue
                // we need to stop our recovery efforts and bail out of the retry handler
                break;
            }

            // If the currState of the SBE is not RUNTIME then we will assume
            // our attempt to boot the SBE has failed, so run extract rc again
            // to determine why we have failed
            if (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME)
            {
                this->sbe_run_extract_rc(i_target);
            }

        } while( (this->iv_sbeRegister).currState != SBE_STATE_RUNTIME );

        // If we ended up switching sides we want to mark it down as
        // as informational log
        if(this->iv_switchSidesCount)
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
            l_errl->collectTrace(SBEIO_COMP_NAME,256);

            // Set the PLID of the error log to master PLID
            // if the master PLID is set
            updatePlids(l_errl);

            errlCommit(l_errl, SBEIO_COMP_ID);
        }

    }while(0);

    SBE_TRACF(EXIT_MRK "main_sbe_handler()");
}

bool SbeRetryHandler::sbe_run_extract_msg_reg(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_run_extract_msg_reg()");

    errlHndl_t l_errl = nullptr;

    //Assume that reading the status succeeded
    bool l_statusReadSuccess = true;

    // This function will poll the status register for 60 seconds
    // waiting for the SBE to reach runtime
    // we will exit the polling before 60 seconds if we either reach
    // runtime, or get an error reading the status reg, or if the asyncFFDC
    // bit is set
    l_errl = this->sbe_poll_status_reg(i_target);

    // If there is no error getting the status register, and the SBE
    // did not make it to runtime AND the asyncFFDC bit is set, we will
    // use the FFDC to decide our actions rather than using p10_extract_sbe_rc
    if((!l_errl) &&
       (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME) &&
       this->iv_sbeRegister.asyncFFDC)
    {
        SBE_TRACF("WARNING: sbe_run_extract_msg_reg completed without error for proc 0x%.8X .  "
                    "However, there was asyncFFDC found though so we will run the FFDC parser",
                  TARGETING::get_huid(i_target));
        // The SBE has responded to an asyncronus request that hostboot
        // made with FFDC indicating an error has occurred.
        // This should be the path we hit when we are waiting to see
        // if the sbe boots
        this->sbe_get_ffdc_handler(i_target);
    }
    // If there was an error log that means that we failed to read the
    // cfam register to get the SBE status, something is seriously wrong
    // if we hit this
    else if (l_errl)
    {
        l_statusReadSuccess = false;
        SBE_TRACF("ERROR: call sbe_run_extract_msg_reg, PLID=0x%x", l_errl->plid() );

        l_errl->collectTrace(SBEIO_COMP_NAME,256);
        // Set the PLID of the error log to master PLID
        // if the master PLID is set
        updatePlids(l_errl);

        // capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    // No error,  able to read the sbe status register okay
    // No guarantees that the SBE made it to runtime
    else
    {
        SBE_TRACF("sbe_run_extract_msg_reg completed without error for proc 0x%.8X",
                    TARGETING::get_huid(i_target));
    }

    SBE_TRACF(EXIT_MRK "sbe_run_extract_msg_reg()");

    return l_statusReadSuccess;

}

errlHndl_t SbeRetryHandler::sbe_poll_status_reg(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_poll_status_reg()");

    errlHndl_t l_errl = nullptr;

    this->iv_currentSBEState =
            SbeRetryHandler::SBE_REG_RETURN::SBE_NOT_AT_RUNTIME;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(i_target);

    // Each sbe gets 60s to respond with the fact that it's
    // booted and at runtime (stable state)
    uint64_t l_sbeTimeout = SBE_RETRY_TIMEOUT_HW_SEC;  // 60 seconds
    // Bump this up really high for simics, things are slow there
    if( Util::isSimicsRunning() )
    {
        l_sbeTimeout = SBE_RETRY_TIMEOUT_SIMICS_SEC; // 600 seconds
    }

    //Sleep time should be 1 second on HW, 10 seconds on simics
    const uint64_t SBE_WAIT_SLEEP_SEC = (l_sbeTimeout/SBE_RETRY_NUM_LOOPS);

    SBE_TRACF("Running p10_get_sbe_msg_register HWP on proc target %.8X",
               TARGETING::get_huid(i_target));

    for( uint64_t l_loops = 0; l_loops < SBE_RETRY_NUM_LOOPS; l_loops++ )
    {
        fapi2::ReturnCode l_rc;

        // We cannot use FAPI_INVOKE in this case because it is possible
        // we are handling a HWP fail. If we attempted to use FAPI_INVOKE
        // while we are already inside a FAPI_INVOKE call then we can
        // end up in an endless wait on the fapi mutex lock
        FAPI_EXEC_HWP(l_rc, p10_get_sbe_msg_register,
                        l_fapi2_proc_target, this->iv_sbeRegister);

        l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
        if (l_errl)
        {
            SBE_TRACF("ERROR : call p10_get_sbe_msg_register, PLID=0x%x, "
                      "on loop %d",
                      l_errl->plid(),
                      l_loops );

            l_errl->collectTrace(SBEIO_COMP_NAME,256);
            l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
            l_errl->collectTrace(FAPI_TRACE_NAME, 384);

            this->iv_currentSBEState =
                    SbeRetryHandler::SBE_REG_RETURN::FAILED_COLLECTING_REG;
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
                SBE_TRACF("Loop %d> SBE 0x%.8X NOT booted yet, "
                          "iv_sbeRegister=0x%.8X", l_loops,
                          TARGETING::get_huid(i_target),
                           (this->iv_sbeRegister).reg);
            }
            l_loops++;
#ifndef __HOSTBOOT_RUNTIME
            // reset watchdog before performing the nanosleep
            INITSERVICE::sendProgressCode();
#endif
            nanosleep(SBE_WAIT_SLEEP_SEC,0);
        }
    }

    if ((this->iv_sbeRegister).currState != SBE_STATE_RUNTIME)
    {
        // Switch to using FSI SCOM if we are not using xscom
        TARGETING::ScomSwitches l_switches =
            i_target->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
        TARGETING::ScomSwitches l_switches_before = l_switches;

        if(!l_switches.useXscom)
        {
            // Turn off SBE SCOM and turn on FSI SCOM.
            l_switches.useFsiScom = 1;
            l_switches.useSbeScom = 0;

            SBE_TRACF("sbe_poll_status_reg: changing SCOM switches from 0x%.2X "
                    "to 0x%.2X for proc 0x%.8X",
                    l_switches_before,
                    l_switches,
                    TARGETING::get_huid(i_target));
            i_target->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        }
    }

    SBE_TRACF(EXIT_MRK "sbe_poll_status_reg()");
    return l_errl;
}

#ifndef __HOSTBOOT_RUNTIME
void SbeRetryHandler::handleFspIplTimeFail(TARGETING::Target * i_target)
{
    // If we found that there was async FFDC available we need to notify hwsv of this
    // even if we did not find anything useful in the ffdc for us, its possible hwsv
    // will be able to use it.
    if ((this->iv_sbeRegister).asyncFFDC)
    {
        iv_shutdownReturnCode = SBEIO_HWSV_COLLECT_SBE_RC;
    }
    // If the asyncFFDC bit is not set on the sbeRegister
    // then we need to pass the DEAD_SBE RC to hwsv when we
    // TI
    else
    {
        this->iv_shutdownReturnCode = SBEIO_DEAD_SBE;
    }
    SBE_TRACF("handleFspIplTimeFail(): During IPL time on FSP system hostboot will TI so that HWSV can handle the error. "
              "Shutting down w/ the error code %s" ,
              this->iv_sbeRegister.asyncFFDC ? "SBEIO_HWSV_COLLECT_SBE_RC" : "SBEIO_DEAD_SBE"  );

    // On FSP systems if we failed to recover the SBE then we should shutdown w/ the
    // correct error so that HWSV will know what FFDC to collect
    INITSERVICE::doShutdownWithError(this->iv_shutdownReturnCode,
                                    TARGETING::get_huid(i_target));
}
#endif

void SbeRetryHandler::sbe_get_ffdc_handler(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_get_ffdc_handler()");
    uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE;
    uint32_t *l_pFifoResponse =
        reinterpret_cast<uint32_t *>(malloc(l_responseSize));

    // For OpenPower systems if a piece of HW is garded then we will
    // need to force a reconfigure loop and avoid the rest of the
    // sbe recovery process. On FSP systems if HW callouts are found in
    // the FFDC, we just commit the errorlog and TI telling HWSV to look
    // at the failure
    bool l_reconfigRequired = false;

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
        auto l_ffdc_parser = std::make_shared<SbeFFDCParser>();
        l_ffdc_parser->parseFFDCData(reinterpret_cast<void *>(l_pFifoResponse));

        uint8_t l_pkgs = l_ffdc_parser->getTotalPackages();

        // Currently we expect a maxiumum of 2 FFDC packets. These packets would be
        // a HWP FFDC packet which we will look at to determine what our retry action
        // should be. The other type of packet we might see would be details on the
        // internal SBE fail. For internal SBE fail packets we will just add the FFDC
        // to the error log and move on.
        //
        // Note:  If we exceed MAX_EXPECTED_FFDC_PACKAGES, commit an informational log.
        // It shouldn't break anything but this could help us understand if something odd
        // is happening
        if(l_pkgs > MAX_EXPECTED_FFDC_PACKAGES)
        {
            /*@
            * @errortype    ERRORLOG::ERRL_SEV_INFORMATIONAL
            * @moduleid     SBEIO_GET_FFDC_HANDLER
            * @reasoncode   SBEIO_MORE_FFDC_THAN_EXPECTED
            * @userdata1    Maximum expected packages
            * @userdata2    Number of FFDC packages
            * @devdesc      Unexpected number of FFDC packages in buffer
            * @custdesc     Extra FFDC gathered, marked information event
            */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                             SBEIO_GET_FFDC_HANDLER,
                                             SBEIO_MORE_FFDC_THAN_EXPECTED,
                                             MAX_EXPECTED_FFDC_PACKAGES,
                                             l_pkgs);

            l_errl->collectTrace( SBEIO_COMP_NAME, 256);

            // Set the PLID of the error log to master PLID
            // if the master PLID is set
            updatePlids(l_errl);

            // Also log the failing proc as FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);
            errlCommit(l_errl, SBEIO_COMP_ID);
        }

        // If there are FFDC packages, make a log for FFDC from SBE
        if(l_pkgs > 0)
        {
            /*@
             * @errortype    ERRORLOG::ERRL_SEV_PREDICTIVE
             * @moduleid     SBEIO_GET_FFDC_HANDLER
             * @reasoncode   SBEIO_RETURNED_FFDC
             * @userdata1    Processor Target
             * @userdata2    Number of FFDC packages
             * @devdesc      FFDC returned by SBE after failing to reach runtime
             * @custdesc     FFDC associated with boot device failing to boot
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_PREDICTIVE,
                                             SBEIO_GET_FFDC_HANDLER,
                                             SBEIO_RETURNED_FFDC,
                                             TARGETING::get_huid(i_target),
                                             l_pkgs);

            // Also log the failing proc as FFDC
            ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog(l_errl);


            // Process each FFDC package
            for(auto i=0; i<l_pkgs; i++)
            {
                // Get the RC from the FFDC package
                uint32_t l_rc = l_ffdc_parser->getPackageRC(i);

                //See if HWP error, create another error log with callouts
                if (l_rc != fapi2::FAPI2_RC_PLAT_ERR_SEE_DATA)
                {
                    fapi2::ReturnCode l_fapiRc;
                    ffdc_package l_package = {nullptr, 0, 0};
                    if(!l_ffdc_parser->getFFDCPackage(i, l_package))
                    {
                        continue;
                    }

                    //Put FFDC into sbeFfdc_t struct and
                    //call FAPI_SET_SBE_ERROR
                    // @TODO RTC 254961 fapi2::sbeFfdc_t l_sbeFfdc;
                    //l_sbeFfdc.size = l_package.size;
                    //l_sbeFfdc.data = reinterpret_cast<uint64_t>(l_package.ffdcPtr);

                    //uint32_t l_pos = i_target->getAttr<TARGETING::ATTR_FAPI_POS>();
                    //FAPI_SET_SBE_ERROR(l_fapiRc, l_rc, &l_sbeFfdc, l_pos);
                    errlHndl_t l_sbeHwpfErr = rcToErrl(l_fapiRc);
                    // If we created an error successfully we must now commit it
                    if(l_sbeHwpfErr)
                    {
                        // On BMC systems we must do a reconfig loop if gard is found
                        if(!INITSERVICE::spBaseServicesEnabled())
                        {
                            // Iterate over user details sections of the error log to check for UD
                            // callouts from the HWPF component
                            // NOTE: rcToErrl will make UD Callouts have ERRL_COMP_ID/ERRL_UDT_CALLOUT
                            for(const auto l_callout : l_sbeHwpfErr->getUDSections(ERRL_COMP_ID,
                                                                                    ERRORLOG::ERRL_UDT_CALLOUT) )
                            {
                              // IF the callout has a gard associated with it we need to do a reconfig loop
                              if((reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->type == HWAS::HW_CALLOUT &&
                                  reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->gardErrorType != HWAS::GARD_NULL) ||
                                 (reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->type == HWAS::CLOCK_CALLOUT &&
                                  reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->clkGardErrorType != HWAS::GARD_NULL) ||
                                 (reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->type == HWAS::PART_CALLOUT &&
                                  reinterpret_cast<HWAS::callout_ud_t*>(l_callout)->partGardErrorType != HWAS::GARD_NULL))
                              {
                                  l_reconfigRequired = true;
                              }
                            }
                        }
                        // Set the PLID of the error log to master PLID
                        // if the master PLID is set
                        updatePlids(l_sbeHwpfErr);

                        ERRORLOG::errlCommit( l_sbeHwpfErr, SBEIO_COMP_ID );
                    }
                }
                else
                {
                  // Add each package to the log
                  l_errl->addFFDC( SBEIO_COMP_ID,
                                  l_ffdc_parser->getFFDCPackage(i),
                                  l_ffdc_parser->getPackageLength(i),
                                  0,
                                  SBEIO_UDT_PARAMETERS,
                                  false );
                }
            }

            l_errl->collectTrace( SBEIO_COMP_NAME, KILOBYTE/4);
            l_errl->collectTrace( "ISTEPS_TRACE", KILOBYTE/4);

            // Set the PLID of the error log to master PLID
            // if the master PLID is set
            updatePlids(l_errl);

            errlCommit(l_errl, SBEIO_COMP_ID);
        }
    }
#endif

    free(l_pFifoResponse);
    l_pFifoResponse = nullptr;

    if(l_reconfigRequired)
    {
        INITSERVICE::doShutdown(INITSERVICE::SHUTDOWN_DO_RECONFIG_LOOP);
    }

    SBE_TRACF(EXIT_MRK "sbe_get_ffdc_handler()");
}


void SbeRetryHandler::sbe_run_extract_rc(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "sbe_run_extract_rc()");

    errlHndl_t l_errl = nullptr;
    fapi2::ReturnCode l_rc;

    SBE_TRACF("Inside sbe_run_extract_rc, calling p10_extract_sbe_rc HWP");

    // Setup for the HWP
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (i_target));

    // Default the return action to be NO_RECOVERY , if something goes
    // wrong in p10_extract_sbe_rc and l_ret doesn't get set in that function
    // then we want to fall back on NO_RECOVERY which we will handle
    // accordingly in bestEffortCheck
    P10_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
        P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;

    // TODO RTC: 190528 Force FAPI_INVOKE_HWP to call FAPI_EXEC_HWP when FAPI_INVOKE
    //          is blocked by mutex
    // Note that it's possible we are calling this while we are already inside
    // of a FAPI_INVOKE_HWP call. This might cause issue w/ current_err
    // but unsure how to get around it.
    FAPI_EXEC_HWP(l_rc, p10_extract_sbe_rc, l_fapi2ProcTarget,
                  l_ret, iv_useSDB, iv_secureModeDisabled);

    // Convert the returnCode into an UNRECOVERABLE error log which we will
    // associate w/ the caller's errlog via plid
    l_errl = rcToErrl(l_rc, ERRORLOG::ERRL_SEV_UNRECOVERABLE);
    this->iv_currentAction = l_ret;

    // This call will look at what p10_extact_sbe_rc had set the return action to
    // checks on how many times we have attempted to boot this side,
    // and if we have already tried switching sides
    //
    // Note this call is important, if this is not called we could end up in a
    // endless loop because this enforces MAX_SWITCH_SIDE_COUNT and MAX_SIDE_BOOT_ATTEMPTS
    this->bestEffortCheck();

#ifndef __HOSTBOOT_RUNTIME
    // This could potentially take awhile, reset watchdog
    INITSERVICE::sendProgressCode();
#endif

    if(l_errl)
    {
        SBE_TRACF("Error: sbe_boot_fail_handler : p10_extract_sbe_rc HWP "
                  " returned action %d and errorlog PLID=0x%x, rc=0x%.4X",
                  this->iv_currentAction, l_errl->plid(), l_errl->reasonCode());

        l_errl->collectTrace(SBEIO_COMP_NAME,256);
        l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
        l_errl->collectTrace(FAPI_TRACE_NAME, 384);

        // Capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(i_target).addToLog( l_errl );

        // Set the PLID of the error log to master PLID
        // if the master PLID is set
        updatePlids(l_errl);

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }

    SBE_TRACF(EXIT_MRK "sbe_run_extract_rc() current action is %llx",
                        this->iv_currentAction);
}

void SbeRetryHandler::bestEffortCheck()
{
    // We don't want to accept that there is no recovery action just
    // because that is what extract_rc is telling us. We want to make
    // sure we have tried booting on this seeprom twice, and that we
    // have tried the other seeprom twice as well. If we have tried all of
    // those cases then we will fail out
    if(this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION)
    {
        if (this->iv_currentSideBootAttempts < MAX_SIDE_BOOT_ATTEMPTS)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was NO_RECOVERY_ACTION but we are trying RESTART_SBE");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::RESTART_SBE;
        }
        else if (this->iv_switchSidesCount < MAX_SWITCH_SIDE_COUNT)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was NO_RECOVERY_ACTION but we are trying REIPL_BKP_SEEPROM");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
        }
        else
        {
            // If we have attempted the max boot attempts on current side
            // and have already switched sides once, then we will accept
            // that we don't know how to recover and pass this status out
        }
    }
    // If we have already switched sides, and extract rc is telling us to
    // switch sides again, there is nothing we can do, so change currentAction
    // to be NO_RECOVERY_ACTION
    else if(this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM ||
        this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM )
    {
        if (this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was REIPL_BKP_SEEPROM/REIPL_UPD_SEEPROM but that is not possible so changing to NO_RECOVERY_ACTION");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
        }
    }
    // If the extract sbe rc hwp tells us to restart, and we have already
    // done 2 retries on this side, then attempt to switch sides, if we can't
    // switch sides, set currentAction to NO_RECOVERY_ACTION
    else if(this->iv_currentAction == P10_EXTRACT_SBE_RC::RESTART_SBE ||
            this->iv_currentAction == P10_EXTRACT_SBE_RC::RESTART_CBS)
    {
        if (this->iv_currentSideBootAttempts >= MAX_SIDE_BOOT_ATTEMPTS)
        {
            if (this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT)
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS but no actions possible so changing to NO_RECOVERY_ACTION");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            }
            else
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS but max attempts tried already so changing to REIPL_BKP_SEEPROM");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
            }
        }
    }
}

errlHndl_t SbeRetryHandler::switch_sbe_sides(TARGETING::Target * i_target)
{
    SBE_TRACF(ENTER_MRK "switch_sbe_sides()");

    errlHndl_t l_errl = nullptr;

#ifdef __HOSTBOOT_RUNTIME
    const bool l_isRuntime = true;
#else
    const bool l_isRuntime = false;
#endif

    do{

        if(!l_isRuntime && !i_target->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>())
        {
            const uint32_t l_sbeBootSelectMask = SBE::SBE_BOOT_SELECT_MASK >> 32;
            // Read FSXCOMP_FSXLOG_SB_CS_FSI_BYTE 0x2820 for target proc
            uint32_t l_read_reg = 0;
            size_t l_opSize = sizeof(uint32_t);
            l_errl = DeviceFW::deviceOp(
                            DeviceFW::READ,
                            i_target,
                            &l_read_reg,
                            l_opSize,
                            DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );

            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"switch_sbe_sides: FSI device read "
                        "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                        "RC=0x%X, PLID=0x%lX",
                        FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, // 0x2820
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
            }
            else // Currently set for Boot Side 0
            {
                // Set Boot Side 1 by setting bit for side 1
                SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 1 for HUID 0x%08X",
                        iv_switchSidesCount,
                        TARGETING::get_huid(i_target));
                l_read_reg |= l_sbeBootSelectMask;
            }

            // Write updated FSXCOMP_FSXLOG_SB_CS_FSI 0x2820 back into target proc
            l_errl = DeviceFW::deviceOp(
                            DeviceFW::WRITE,
                            i_target,
                            &l_read_reg,
                            l_opSize,
                            DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );
            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"switch_sbe_sides: FSI device write "
                        "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                        "RC=0x%X, PLID=0x%lX",
                        FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, // 0x2820
                        TARGETING::get_huid(i_target),
                        ERRL_GETRC_SAFE(l_errl),
                        ERRL_GETPLID_SAFE(l_errl));
                break;
            }
        }
        else
        {
            // Read FSXCOMP_FSXLOG_SB_CS 0x50008 for target proc
            uint64_t l_read_reg = 0;
            size_t l_opSize = sizeof(uint64_t);
            l_errl = DeviceFW::deviceOp(
                            DeviceFW::READ,
                            i_target,
                            &l_read_reg,
                            l_opSize,
                            DEVICE_SCOM_ADDRESS(FSXCOMP_FSXLOG_SB_CS) );

            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"switch_sbe_sides: SCOM device read "
                        "FSXCOMP_FSXLOG_SB_CS (0x%.4X), proc target = %.8X, "
                        "RC=0x%X, PLID=0x%lX",
                        FSXCOMP_FSXLOG_SB_CS, // 0x50008
                        TARGETING::get_huid(i_target),
                        ERRL_GETRC_SAFE(l_errl),
                        ERRL_GETPLID_SAFE(l_errl));
                break;
            }

            // Determine how boot side is currently set
            if(l_read_reg & SBE::SBE_BOOT_SELECT_MASK) // Currently set for Boot Side 1
            {
                // Set Boot Side 0 by clearing bit for side 1
                SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 0 for HUID 0x%08X",
                        iv_switchSidesCount,
                        TARGETING::get_huid(i_target));
                l_read_reg &= ~SBE::SBE_BOOT_SELECT_MASK;
            }
            else // Currently set for Boot Side 0
            {
                // Set Boot Side 1 by setting bit for side 1
                SBE_TRACF( "switch_sbe_sides #%d: Set Boot Side 1 for HUID 0x%08X",
                        iv_switchSidesCount,
                        TARGETING::get_huid(i_target));
                l_read_reg |= SBE::SBE_BOOT_SELECT_MASK;
            }

            // Write updated FSXCOMP_FSXLOG_SB_CS 0x50008 back into target proc
            l_errl = DeviceFW::deviceOp(
                            DeviceFW::WRITE,
                            i_target,
                            &l_read_reg,
                            l_opSize,
                            DEVICE_SCOM_ADDRESS(FSXCOMP_FSXLOG_SB_CS) );
            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"switch_sbe_sides: SCOM device write "
                        "FSXCOMP_FSXLOG_SB_CS (0x%.4X), proc target = %.8X, "
                        "RC=0x%X, PLID=0x%lX",
                        FSXCOMP_FSXLOG_SB_CS, // 0x50008
                        TARGETING::get_huid(i_target),
                        ERRL_GETRC_SAFE(l_errl),
                        ERRL_GETPLID_SAFE(l_errl));
                break;
            }
        }

        // Increment switch sides count
        ++(this->iv_switchSidesCount);

        SBE_TRACF("switch_sbe_sides(): iv_switchSidesCount has been incremented to %llx",
                   iv_switchSidesCount);

        // Since we just switched sides, and we havent attempted a boot yet,
        // set the current attempts for this side to be 0
        this->iv_currentSideBootAttempts = 0;
    }while(0);

    if (l_errl)
    {
        // Set the PLID of the error log to master PLID
        // if the master PLID is set
        updatePlids(l_errl);
    }

    SBE_TRACF(EXIT_MRK "switch_sbe_sides()");
    return l_errl;
}

} // End of namespace SBEIO
