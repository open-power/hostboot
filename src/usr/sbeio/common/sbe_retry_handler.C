/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/common/sbe_retry_handler.C $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2022                        */
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

// System
#include <stdint.h>

// Hostboot userspace
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errlreasoncodes.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/istepdispatcherif.H>
#include <initservice/initsvcreasoncodes.H>
#include <errl/errludtarget.H>
#include <errl/errludlogregister.H>
#include <util/misc.H>
#include <arch/magic.H>
#include <sbe/sbe_update.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_sp_intf.H>
#include <sbeio/sbe_ffdc_parser.H>
#include <sbeio/sbeioreasoncodes.H>
#include <../../usr/sbeio/sbe_fifodd.H>
#include <../../usr/sbeio/sbe_fifo_buffer.H>
#include <sbe/sbe_common.H>
#include <sbe/sbeif.H>
#include <vpd/mvpdenums.H>
#include <sbeio/sbe_retry_handler.H>
#include <secureboot/service.H>
#include <i2c/i2cif.H>
#include <spi/spi.H> // for SPI lock support
#include <devicefw/driverif.H>
#include <plat_utils.H>
#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>
#include <targeting/targplatutil.H>
#include <initservice/mboxRegs.H>

// FAPI2 Infrastructure
#include <fapi2.H>

// FAPI2 HWPs
#include <p10_start_cbs.H>
#include <p10_sbe_hreset.H>
#include <p10_get_sbe_msg_register.H>
#include <p10_scom_perv_a.H>

// Generated
#include <set_sbe_error.H>

// PLDM
#if defined(CONFIG_PLDM)
#include <pldm/extended/sbe_dump.H>
#endif

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
using namespace SBE;

namespace SBEIO
{

// Define constant expressions to be used

//There are only 2 sides to the seeproms, so we only want to flip sides once
constexpr uint8_t MAX_SWITCH_SIDE_COUNT         = 1;

//We only want to attempt to boot with the same side seeprom twice
constexpr uint8_t MAX_SIDE_BOOT_ATTEMPTS        = 2;

//How many times to attempt RESTART_SBE
constexpr uint8_t MAX_RESTARTS                  = 2;

// Currently we expect a maxiumum of 2 FFDC packets, the one
// that is useful to HB is the HWP FFDC. It is possible there is
// a packet that details an internal sbe fail that hostboot will
// add to an errorlog but otherwise ignores
constexpr uint8_t MAX_EXPECTED_FFDC_PACKAGES    = 2;

// Set up constants that will be used for setting up the timeout for
// reading the sbe message register
constexpr uint64_t SBE_RETRY_TIMEOUT_HW_SEC     = 60;  // 60 seconds
constexpr uint64_t SBE_RETRY_TIMEOUT_SIMICS_SEC = 600; // 600 seconds
constexpr uint32_t SBE_RETRY_NUM_LOOPS          = 60;

SbeRetryHandler::SbeRetryHandler(TARGETING::Target * const i_proc,
                                 SBE_MODE_OF_OPERATION i_sbeMode,
                                 SBE_RESTART_METHOD i_restartMethod,
                                 const uint32_t i_plid,
                                 const bool i_isInitialPoweron)
: iv_useSDB(false)
, iv_masterErrorLogPLID(i_plid)
, iv_switchSidesCount(0)
, iv_switchSidesCount_mseeprom(0)
, iv_switchSidesFlag(0)
, iv_boot_restart_count(0)
, iv_currentAction(P10_EXTRACT_SBE_RC::ERROR_RECOVERED)
, iv_currentSBEState(SBE_STATUS::SBE_NOT_AT_RUNTIME)
, iv_shutdownReturnCode(0)
, iv_currentSideBootAttempts(1) // It is safe to assume that the current side has attempted to boot
, iv_currentSideBootAttempts_mseeprom(1) // It is safe to assume that the current side has attempted to boot
, iv_sbeMode(i_sbeMode)
, iv_sbeRestartMethod(i_restartMethod)
, iv_initialPowerOn(i_isInitialPoweron)
, iv_proc(i_proc)
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
, iv_sbeTestMode_recommendations(0)
, iv_sbeTestMode(SBE_FORCED_TEST_PATH::TEST_ERROR_RECOVERED)
#endif
{
    SBE_TRACF(ENTER_MRK "SbeRetryHandler::SbeRetryHandler() proc %08X, sbe_mode %X, restart %X",
        get_huid(i_proc), i_sbeMode, i_restartMethod);

    // Initialize members that have no default initialization
    iv_sbeRegister.reg = 0;

    SBE_TRACF(EXIT_MRK "SbeRetryHandler::SbeRetryHandler()");
}

SbeRetryHandler::~SbeRetryHandler() {}

void SbeRetryHandler::main_sbe_handler( bool i_sbeHalted )
{
    SBE_TRACF(ENTER_MRK "main_sbe_handler()");

    TARGETING::Target* l_sys = TARGETING::UTIL::assertGetToplevelTarget();
    bool isMpIpl = l_sys->getAttr<TARGETING::ATTR_IS_MPIPL_HB>();

    bool isRuntimeOrMpIpl = isMpIpl;
#if defined(__HOSTBOOT_RUNTIME)
    isRuntimeOrMpIpl = true;
#endif
    SBE_TRACF("main_sbe_handler(): isRuntimeOrMpIpl = %d", isRuntimeOrMpIpl);

#if defined(CONFIG_PLDM)
    PLDM::sbe_hreset_states old_hreset_states;
    if (isRuntimeOrMpIpl)
    {
        old_hreset_states = PLDM::notifyBeginSbeHreset(iv_proc);
    }
#endif

    do
    {
        errlHndl_t l_errl = nullptr;

        // Only set the secure debug bit (SDB) if we are not using xscom yet
        if(!iv_proc->getAttr<TARGETING::ATTR_SCOM_SWITCHES>().useXscom &&
            !iv_proc->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>())
        {
            this->iv_useSDB = true;
        }

        // Get the SBE status register, this will tell us what state
        // the SBE is in , if the asynFFDC bit is set on the sbe_reg
        // then FFDC will be collected at this point in time.
        // sbe_run_extract_msg_reg will return true if there was an error reading the status
        if( !i_sbeHalted && !this->sbe_run_extract_msg_reg())
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

        // Grab the current seeprom sides from the HW directly
        //  before we change anything
        uint8_t l_bootside = 0xFF;
        uint8_t l_mside = 0xFF;
        uint32_t l_ctl_reg = 0;
        errlHndl_t tmp_errl = accessControlReg( ACCESS_READ,
                                                l_ctl_reg );
        if( tmp_errl )
        {
            SBE_TRACF("Error from accessControlReg, data is invalid");
            delete tmp_errl;
            tmp_errl = nullptr;
        }
        else
        {
            l_bootside = (l_ctl_reg & SBE_BOOT_SELECT_MASK_FSI) ? 1 : 0;
            l_mside = (l_ctl_reg & SBE_MBOOT_SELECT_MASK_FSI) ? 1 : 0;
        }

        // if the sbe is not halted, run extract_rc
        // NOTE: If we have any asyncFFDC it would have previously been
        //  collected in the call to sbe_run_extract_msg_reg above. In
        //  this case we don't want to run extract_rc as that logic
        //  assumes a dead or hung SBE.
        if(!i_sbeHalted && !((this->iv_sbeRegister).asyncFFDC))
        {
            SBE_TRACF("main_sbe_handler(sides:b=%d,m=%d): No async ffdc found and sbe isn't explicitly halted, running p10_sbe_extract_rc.", l_bootside, l_mside);
            // Call the function that runs extract_rc, this needs to run to determine
            // what broke and what our retry action should be
            this->sbe_run_extract_rc();

#if !defined(__HOSTBOOT_RUNTIME) && defined(CONFIG_PLDM)
            // only dumpSbe if not runtime or last resort for MPIPL (ie NO_RECOVERY_ACTION is set)
            if (!isMpIpl || (this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) )
            {
                errlHndl_t dump_errl = PLDM::dumpSbe(iv_proc, iv_masterErrorLogPLID);

                if (dump_errl)
                {
                    SBE_TRACF("main_sbe_handler(1): SBE dump failed for processor 0x%08x, PLID 0x%08x",
                              get_huid(iv_proc), iv_masterErrorLogPLID);
                    dump_errl->collectTrace("ISTEPS_TRACE");
                    dump_errl->collectTrace(SBEIO_COMP_NAME);
                    dump_errl->plid(iv_masterErrorLogPLID);
                    errlCommit(dump_errl, SBEIO_COMP_ID);
                }
            }
            else
            {
                SBE_TRACF("main_sbe_handler(1): Skipping PLDM::dumpSbe(0x%08X, 0x%08x) currentAction = %d",
                    get_huid(iv_proc), iv_masterErrorLogPLID, this->iv_currentAction);
            }
#endif
        }
        // If we are halted then set the current action to be "restart sbe"
        // (the restart handler should already be initialized with with the HRESET reason)
        else if( i_sbeHalted )
        {
            SBE_TRACF("main_sbe_handler(): SBE is halted. Setting action to be RESTART_SBE");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::RESTART_SBE;
        }
        // If we have async FFDC then set the current action to be "restart sbe"
        else if( iv_sbeRegister.asyncFFDC )
        {
            SBE_TRACF("main_sbe_handler(): SBE has async FFDC. Setting action to be RESTART_SBE");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::RESTART_SBE;
        }

#ifndef __HOSTBOOT_RUNTIME
        // Need to switch SPI control register back to FSI_ACCESS mode
        // if we are in the initial boot flow since SBE might flip the
        // access mode into PIB_ACCESS.  Do this after we read the hw
        // regs in extract_rc and the sbe dump, but before we take
        // any actions ourselves.
        if( this->iv_initialPowerOn && !isMpIpl )
        {
            l_errl = SPI::spiSetAccessMode(iv_proc, SPI::FSI_ACCESS);
            if (l_errl)
            {
                SBE_TRACF("ERROR: SPI access mode switch to FSI_ACCESS failed for target %.8X"
                          TRACE_ERR_FMT,
                          TARGETING::get_huid(iv_proc),
                          TRACE_ERR_ARGS(l_errl));
                // this error is secondary to what we're really trying
                // to do so just commit it as informational
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                errlCommit( l_errl, SBEIO_COMP_ID);
            }
        }
#endif

        // If the mode was marked as informational that means the caller did not want
        // any actions to take place, the caller only wanted information collected
        if(this->iv_sbeMode == INFORMATIONAL_ONLY)
        {
            SBE_TRACF("main_sbe_handler(sides:b=%d,m=%d): Retry handler is being called in INFORMATIONAL mode so we are exiting without attempting any retry actions", l_bootside, l_mside);
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
            //
            // See src/import/chips/p10/procedures/hwp/perv/p10_extract_sbe_rc.H
            //
            //        ERROR_RECOVERED    = 0,
            //           - We should never hit this, if we have recovered then
            //             currState should be RUNTIME
            //        RESTART_SBE        = 1,
            //        RESTART_CBS        = 2,
            //           - We will not listen to p10_extract_rc on HOW to restart the
            //             sbe. We will assume iv_sbeRestartMethod is correct and
            //             perform the restart method that iv_sbeRestartMethod says
            //             regardless if currentAction = RESTART_SBE or RESTART_CBS
            //        REIPL_BKP_SEEPROM  = 3,
            //        REIPL_UPD_SEEPROM  = 4,
            //        REIPL_BKP_MSEEPROM  = 5,
            //        REIPL_UPD_MSEEPROM  = 6,
            //            - We will switch the seeprom side (or mseeprom), if we have not already
            //            - then attempt to restart the sbe w/ iv_sbeRestartMethod
            //        NO_RECOVERY_ACTION = 8,
            //            - we deconfigure the processor we are retrying and fail out
            //        REIPL_BKP_BMSEEPROM  = 9,
            //            - Select the backup Measurement and Boot seeproms
            //            - then attempt to restart the sbe w/ iv_sbeRestartMethod
            //        RECONFIG_WITH_CLOCK_GARD = 10,
            //            - we deconfigure the processor we are retrying and fail out
            //
            // Important things to remember, we only want to attempt a single side
            // a maxiumum of 2 times, and also we only want to switch sides once

            SBE_TRACF("main_sbe_handler(%.8X): iv_sbeRegister.currState: %d , "
                        "iv_currentSBEState: 0x%X ,"
                        "iv_currentSideBootAttempts: %d , "
                        "iv_currentAction: %d , "
                        "iv_currentSideBootAttempts_mseeprom: %d , "
                        "bootside=%d , measurementside=%d",
                        TARGETING::get_huid(this->iv_proc),
                        this->iv_sbeRegister.currState,
                        this->iv_currentSBEState,
                        this->iv_currentSideBootAttempts,
                        this->iv_currentAction,
                        this->iv_currentSideBootAttempts_mseeprom,
                        l_bootside,
                        l_mside);

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
            if (this->iv_sbeTestMode)
            {
                // if we are forcing the failure we will be iterating trying to recover
                if (this->iv_sbeTestMode != TEST_SBE_FAILURE)
                {
                    // simple cases
                    this->iv_currentAction = sbe_op_map[this->iv_sbeTestMode];
                }
                else
                {
                    // we want to take looping SBE extract rc recommendations
                    if ((this->iv_sbeTestMode_recommendations) == 0)
                    {
                        this->iv_sbeTestMode_recommendations++;
                        // first time logic kick the test off
                        this->iv_currentAction = sbe_op_map[this->iv_sbeTestMode];
                    }
                    else
                    {
                        // loop iterations just keep a counter and go with extract rc
                        this->iv_sbeTestMode_recommendations++;
                    }
                }
            }
#endif

            if (this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION
                || this->iv_currentAction == P10_EXTRACT_SBE_RC::RECONFIG_WITH_CLOCK_GARD)
            {
                SBE_TRACF("main_sbe_handler(): We have concluded there are no further recovery actions to take, deconfiguring proc and exiting handler");

                if (this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION)
                {
                    /*@ There is no action possible. Gard and Callout the proc
                     * @errortype  ERRL_SEV_UNRECOVERABLE
                     * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                     * @reasoncode SBEIO_NO_RECOVERY_ACTION
                     * @userdata1  SBE current error
                     * @userdata2  HUID of proc
                     * @devdesc    There is no recovery action on the SBE.
                     *             We're deconfiguring this proc
                     * @custdesc   Processor Error
                     */
                    l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                     SBEIO_EXTRACT_RC_HANDLER,
                                                     SBEIO_NO_RECOVERY_ACTION,
                                                     P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION,
                                                     TARGETING::get_huid(iv_proc));
                    l_errl->addHwCallout(iv_proc, HWAS::SRCI_PRIORITY_HIGH, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
                }
                else if (this->iv_currentAction == P10_EXTRACT_SBE_RC::RECONFIG_WITH_CLOCK_GARD)
                {
                    /*@ There is no action possible. Gard and Callout the proc
                     * @errortype  ERRL_SEV_UNRECOVERABLE
                     * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                     * @reasoncode SBEIO_RECONFIG_WITH_CLOCK_GUARD
                     * @userdata1  SBE current error
                     * @userdata2  HUID of proc
                     * @devdesc    Deconfiguring processor due to clock guard
                     * @custdesc   Processor Error
                     */
                    l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                                     SBEIO_EXTRACT_RC_HANDLER,
                                                     SBEIO_RECONFIG_WITH_CLOCK_GUARD,
                                                     P10_EXTRACT_SBE_RC::RECONFIG_WITH_CLOCK_GARD,
                                                     TARGETING::get_huid(iv_proc));



                    if (iv_clock_error_handler)
                    {
                        iv_clock_error_handler(l_errl, iv_proc, HWAS::OSCREFCLK_TYPE);
                    }
                    else
                    {
                        l_errl->addClockCallout(iv_proc, HWAS::OSCREFCLK_TYPE, HWAS::SRCI_PRIORITY_HIGH);
                        l_errl->addHwCallout(iv_proc, HWAS::SRCI_PRIORITY_MED, HWAS::DELAYED_DECONFIG, HWAS::GARD_NULL);
                    }
                }

                l_errl->collectTrace("ISTEPS_TRACE", 256);
                l_errl->collectTrace(SBEIO_COMP_NAME, 256);
                addRegisterFFDC(l_errl);

                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
                this->iv_currentSBEState = SBE_STATUS::PROC_DECONFIG;
                break;
            }

            // if the bkp_seeprom or upd_seeprom, attempt to switch sides.
            // This is also dependent on the iv_switchSideCount and
            // iv_switchSideCount_mseeprom respectively.
            //
            // Note: we do this for upd_seeprom because we don't support
            //       updating the seeprom during IPL time
            // OPTION 1 - Check if we are DONE, we've switched sides MAX on seeprom or mseeprom
            // We always flip sides on SEEPROM or MSEEPROM
            // RESTART_SBE is the path that considers same side REIPL which is a special case
            // on initialPowerOn and bestEffortCheck flows.
            if((this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM) ||
               (this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM) ||
               (this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM) ||
               (this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM) ||
               (this->iv_currentAction ==
                            P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)
               )
            {
                // We cannot switch sides and perform an hreset if the seeprom's
                // versions do not match. If this happens, log an error and stop
                // trying to recover the SBE
                if(this->iv_sbeRestartMethod == HRESET)
                {
                    TARGETING::ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH_type l_versionsMismatch =
                            iv_proc->getAttr<TARGETING::ATTR_HB_SBE_SEEPROM_VERSION_MISMATCH>();

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
                                    TARGETING::get_huid(iv_proc),0);
                        l_errl->collectTrace("ISTEPS_TRACE", 256);
                        l_errl->collectTrace(SBEIO_COMP_NAME, 256);
                        l_errl->addHwCallout(iv_proc,
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

                SBE_TRACF("main_sbe_handler(): iv_switchSidesCount=%d, iv_switchSidesCount_mseeprom=%d",
                          iv_switchSidesCount,
                          iv_switchSidesCount_mseeprom);
                if( ( (this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT) &&
                      ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM)
                       || (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM)
                       || (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)) )
                    ||
                    ( (this->iv_switchSidesCount_mseeprom >= MAX_SWITCH_SIDE_COUNT) &&
                      ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM)
                       || (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM)
                       || (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)) )
                   )
                {
                    SBE_TRACF("main_sbe_handler(): Exhausted the number of side switch attempts on %.8X",
                              TARGETING::get_huid(iv_proc));
                    /*@
                    * @errortype  ERRL_SEV_PREDICTIVE
                    * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                    * @reasoncode SBEIO_EXCEED_MAX_SIDE_SWITCHES
                    * @userdata1[00:31]  Switch Sides Count
                    * @userdata1[32:63]  Switch Sides Count Mseeprom
                    * @userdata2[00:31]  Current Action
                    * @userdata2[32:63]  HUID of proc
                    * @devdesc    We have already flipped seeprom sides once
                    *             and we should not have attempted to flip again
                    * @custdesc   Processor Error
                    */
                    l_errl = new ERRORLOG::ErrlEntry(
                                ERRORLOG::ERRL_SEV_PREDICTIVE,
                                SBEIO_EXTRACT_RC_HANDLER,
                                SBEIO_EXCEED_MAX_SIDE_SWITCHES,
                                TWO_UINT32_TO_UINT64(this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom),
                                TWO_UINT32_TO_UINT64(this->iv_currentAction, TARGETING::get_huid(iv_proc)));
                    l_errl->collectTrace( SBEIO_COMP_NAME, 256);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit(l_errl, SBEIO_COMP_ID);
                    // Break out of loop, something bad happened and we dont want end
                    // up in a endless loop
                    break;
                }
                // HRESET in RUNTIME AND IPL 10.x steps need to SKIP
                // the switch_sbe_sides call in the FSP flow, to avoid
                // altering the CFAM registers and MVPD.
                // HWSV owns the policy for when and what algorithms
                // are performed during any type of SEEPROM or MSEEPROM
                // recovery, therefore do -NOT- make any modifications.
                if(!INITSERVICE::spBaseServicesEnabled())
                {
                    l_errl = this->switch_sbe_sides(this->iv_currentAction, true);
                    if(l_errl)
                    {
                        errlCommit(l_errl, SBEIO_COMP_ID);
                        // If any error occurs while we are trying to switch sides
                        // this indicates big problems so we want to break out of the
                        // retry loop
                        break;
                    }
                }
                // Note that we do not want to continue here because we want to
                // attempt to restart using whatever sbeRestartMethod is set to after
                // switching seeprom sides
            }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
            if (this->iv_sbeTestMode == TEST_MAX_LIMITS)
            {
                (this->iv_currentSideBootAttempts) = MAX_SIDE_BOOT_ATTEMPTS;
                (this->iv_currentSideBootAttempts_mseeprom) = MAX_SIDE_BOOT_ATTEMPTS;
                (this->iv_boot_restart_count) = MAX_RESTARTS;
            }
#endif

            // Both of the retry methods require a FAPI2 version of the target because they
            // are fapi2 HWPs
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2_proc_target (iv_proc);
            // OPTION 2 - Check if we are DONE on THIS SIDE BOOT ATTEMPTS for MAX on seeprom or mseeprom
            // each cycle we are working on the SEEPROM or MSEEPROM, so each cycle a new object is instantiated
            if( ((this->iv_currentSideBootAttempts >= MAX_SIDE_BOOT_ATTEMPTS) &&
                  ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM) ||
                   (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM) ||
                   (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)))
                ||
                ((this->iv_currentSideBootAttempts_mseeprom >= MAX_SIDE_BOOT_ATTEMPTS)&&
                  ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM) ||
                   (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM) ||
                   (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM))))
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
                            TARGETING::get_huid(iv_proc));

                l_errl->collectTrace( SBEIO_COMP_NAME, 256);

                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
                // Break out of loop, something bad happened and we dont want end
                // up in a endless loop
                break;
            }
            // Look at the sbeRestartMethod instance variable to determine which method
            // we will use to attempt the restart. In general during IPL time we will
            // attempt CBS, during runtime we will want to use HRESET.
            // OPTION 3 - ATTEMPT START_CBS on THIS SIDE
            else if(this->iv_sbeRestartMethod == SBE_RESTART_METHOD::START_CBS)
            {
                //Increment attempt count for this side

                const bool boot_seeprom_switch_requested
                    = (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM
                       || this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM);

                if (boot_seeprom_switch_requested)
                {
                    this->iv_currentSideBootAttempts++;
                }
                else if ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM) ||
                         (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM))
                {
                    this->iv_currentSideBootAttempts_mseeprom++;
                    // increment even though we may switch sides later
                }
                else //catch all other cases, i.e. REIPL_BKP_BMSEEPROM and any other future proofing
                {
                    this->iv_currentSideBootAttempts++;
                    this->iv_currentSideBootAttempts_mseeprom++;
                }

                ++this->iv_boot_restart_count;
                if (this->iv_boot_restart_count > MAX_RESTARTS)
                {
                    this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                    SBE_TRACF("main_sbe_handler(): SBE reports it was never booted and we reached MAX_RESTARTS. Setting next action to be NO_RECOVERY_ACTION");
                }

                // For the eBMC flow, if something is requiring a restart, we
                // flip the [M]SEEPROM on eBMC systems to try to fix the problem.
                //
                // For the FSP flow, we SKIP the call to switch_sbe_sides to
                // avoid altering the CFAM registers and MVPD.
                // HWSV owns the policy for when and what algorithms
                // are performed during any type of SEEPROM or MSEEPROM
                // recovery, therefore do -NOT- make any modifications in FSP flow.
                if(!INITSERVICE::spBaseServicesEnabled())
                {
                    /*
                     Switching the measurement SEEPROM (MSEEPROM) side is the
                     less risky operation compared to switching the Boot SEEPROM
                     side, because both sides of the MSEEPROM should have
                     exactly the same contents and its functionality shouldn't
                     change by switching. Switching Boot SEEPROM sides on the
                     other hand could lead to completely different behavior and
                     expose bugs, lead to version mismatches, and maybe other
                     bad things.

                     Therefore, in this path, we switch the MSEEPROM side first,
                     and only if that doesn't fix the problem do we switch the
                     Boot SEEPROM side. (But if this is our last chance to boot,
                     we'll switch the boot SEEPROM side if we haven't before,
                     because that has a greater chance of working.)
                    */

                    const bool last_try = this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                    const bool already_switched_boot_sides = this->iv_switchSidesCount > 0;
                    const bool already_switched_meas_sides = this->iv_switchSidesCount_mseeprom > 0;

                    if ((already_switched_meas_sides && !already_switched_boot_sides && boot_seeprom_switch_requested)
                        || (last_try && !already_switched_boot_sides))
                    {
                        SBE_TRACF("main_sbe_handler(): Switching boot SEEPROM sides in START_CBS path: "
                                  "boot_seeprom_switch_requested=%d iv_currentAction=%d "
                                  "last_try=%d already_switched_boot_sides=%d already_switched_meas_sides=%d",
                                  boot_seeprom_switch_requested, iv_currentAction,
                                  last_try, already_switched_boot_sides, already_switched_meas_sides);

                        l_errl = this->switch_sbe_sides(P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM, true);
                    }
                    else if (!already_switched_meas_sides)
                    {
                        SBE_TRACF("main_sbe_handler(): Switching meas SEEPROM sides in START_CBS path: "
                                  "boot_seeprom_switch_requested=%d iv_currentAction=%d "
                                  "last_try=%d already_switched_boot_sides=%d already_switched_meas_sides=%d",
                                  boot_seeprom_switch_requested, iv_currentAction,
                                  last_try, already_switched_boot_sides, already_switched_meas_sides);

                        l_errl = this->switch_sbe_sides(P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM, true);
                    }

                    if(l_errl)
                    {
                        errlCommit(l_errl, SBEIO_COMP_ID);
                        // If any error occurs while we are trying to switch sides
                        // this indicates big problems so we want to break out of the
                        // retry loop
                        break;
                    }
                }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
                if (this->iv_sbeTestMode == TEST_RESTART_CBS)
                {
                    break;
                }
#endif

#ifndef __HOSTBOOT_RUNTIME
                // If something is wrong w/ the SBE during IPL time on a FSP based system then
                // we will always TI and let hwsv deal with the problem.
                if(!isMpIpl && INITSERVICE::spBaseServicesEnabled())
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
                                                     TARGETING::get_huid(iv_proc));

                    l_errl->collectTrace( "ISTEPS_TRACE", 256);
                    l_errl->collectTrace( SBEIO_COMP_NAME, 256);
                    addRegisterFFDC(l_errl);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit(l_errl, SBEIO_COMP_ID);
                    // This function will TI Hostboot so don't expect to return
                    handleFspIplTimeFail();
                    SBE_TRACF("main_sbe_handler(): We failed to TI the system when we should have, forcing an assert(0) call");
                    // We should never return from handleFspIplTimeFail
                    assert(0, "We have determined that there was an error with the SBE and should have TI'ed but for some reason we did not.");
                }
#endif

                SBE_TRACF("Invoking p10_start_cbs HWP on processor %.8X", get_huid(iv_proc));

                // For now we only use p10_start_cbs if we fail to boot the slave SBE
                // on our initial attempt, the bool param is true we are telling the
                // HWP that we are starting up the SBE which is true in this case
                FAPI_INVOKE_HWP( l_errl,
                                 p10_start_cbs,
                                 l_fapi2_proc_target,
                                 true );

                if(l_errl)
                {
                    // Grab the side info again since we switched it above
                    errlHndl_t tmp_errl = accessControlReg( ACCESS_READ,
                                                            l_ctl_reg );
                    if( tmp_errl )
                    {
                        SBE_TRACF("Error from accessControlReg, data is invalid");
                        delete tmp_errl;
                        tmp_errl = nullptr;
                    }
                    else
                    {
                        l_bootside = (l_ctl_reg & SBE_BOOT_SELECT_MASK_FSI) ? 1 : 0;
                        l_mside = (l_ctl_reg & SBE_MBOOT_SELECT_MASK_FSI) ? 1 : 0;
                    }

                    // Flag the currentSBEState since something bad has happened
                    // and the caller checks the currentSBEState as an indicator of success
                    // This prevents infinite loop when we deconfig the proc
                    // and caller checks only isSbeAtRuntime
                    SBE_TRACF("ERROR: call p10_start_cbs boot/meas-side=%d/%d, iv_currentSBEState=%d, PLID=0x%x",
                              l_bootside,
                              l_mside,
                              this->iv_currentSBEState,
                              l_errl->plid() );
                    this->iv_currentSBEState = SbeRetryHandler::SBE_STATUS::SBE_NOT_AT_RUNTIME;
                    l_errl->collectTrace(SBEIO_COMP_NAME, 256 );
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_errl->collectTrace(FAPI_TRACE_NAME, 384);

                    // Deconfig the target when SBE Retry fails
                    l_errl->addHwCallout(iv_proc,
                                         HWAS::SRCI_PRIORITY_LOW,
                                         HWAS::DELAYED_DECONFIG,
                                         HWAS::GARD_NULL);

                    addRegisterFFDC(l_errl);

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
            // OPTION 4 - ATTEMPT HRESET on PRE-SET OR SAME SIDE
            else
            {
                // Increment attempt count for this side
                // Note - RESTART_SBE does -NOT- bump boot attempts
                if ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM) ||
                   (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM))
                {
                    this->iv_currentSideBootAttempts++;
                }
                else if ((this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM) ||
                        (this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM))
                {
                    this->iv_currentSideBootAttempts_mseeprom++;
                }
                else if (this->iv_currentAction == P10_EXTRACT_SBE_RC::RESTART_SBE)
                {
                    this->iv_currentSideBootAttempts++;
                    this->iv_currentSideBootAttempts_mseeprom++;
                    ++this->iv_boot_restart_count;
                }
                else // catch all other cases, i.e. REIPL_BKP_BMSEEPROM and any other future proofing
                {
                    // bumping the counters prevent infinite loops to make sure we have an exit path
                    this->iv_currentSideBootAttempts++;
                    this->iv_currentSideBootAttempts_mseeprom++;
                    ++this->iv_boot_restart_count;
                }

                if (this->iv_boot_restart_count > MAX_RESTARTS)
                {
                    this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                    SBE_TRACF("main_sbe_handler(): OPTION 4 HRESET We reached MAX_RESTARTS. Setting next action to be NO_RECOVERY_ACTION");
                }

                SBE_TRACF("Invoking p10_sbe_hreset HWP on processor %.8X", get_huid(iv_proc));

                FAPI_INVOKE_HWP( l_errl,
                                 p10_sbe_hreset,
                                 l_fapi2_proc_target );
                if(l_errl)
                {
                    SBE_TRACF("ERROR: call p10_sbe_hreset, PLID=0x%x",
                                l_errl->plid() );
                    l_errl->collectTrace(SBEIO_COMP_NAME, 256 );
                    l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
                    l_errl->collectTrace(FAPI_TRACE_NAME, 384);

                    // Deconfig the target when SBE Retry fails
                    l_errl->addHwCallout(iv_proc,
                                         HWAS::SRCI_PRIORITY_LOW,
                                         HWAS::DELAYED_DECONFIG,
                                         HWAS::GARD_NULL);

                    addRegisterFFDC(l_errl);

                    // Set the PLID of the error log to master PLID
                    // if the master PLID is set
                    updatePlids(l_errl);

                    errlCommit( l_errl, SBEIO_COMP_ID);
                    // If we got an errlog while attempting p10_sbe_hreset
                    // we will assume that no future retry actions
                    // will work so we will exit
                    break;
                }

                // Need to make sure the SBE didn't die with the I2C lock held
                l_errl = I2C::forceClearAtomicLock(iv_proc,
                                                   I2C::I2C_ENGINE_SELECT_ALL);
                if(l_errl)
                {
                    SBE_TRACF("ERROR: I2C::forceClearAtomicLock() failed, committing log as info" );
                    // commit as informational since it is possible nothing
                    //  bad will happen, we'll catch a hard fail elsewhere
                    l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    errlCommit( l_errl, SBEIO_COMP_ID);
                }
            }

            // Get the sbe register  (note that if asyncFFDC bit is set in status register then
            // we will read it in this call)
            if(!this->sbe_run_extract_msg_reg())
            {
                // Error log should have already committed in sbe_run_extract_msg_reg for this issue
                // we need to stop our recovery efforts and bail out of the retry handler
                break;
            }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
            if (this->iv_sbeTestMode == TEST_SBE_FAILURE)
            {
                (this->iv_sbeRegister).currState = SBE_STATE_FAILURE;
                this->iv_currentSBEState = SbeRetryHandler::SBE_STATUS::SBE_NOT_AT_RUNTIME;
            }
#endif

            // If the currState of the SBE is not RUNTIME then we will assume
            // our attempt to boot the SBE has failed, so run extract rc again
            // to determine why we have failed, if the sbeBooted is true
            if ((this->iv_sbeRegister.currState != SBE_STATE_RUNTIME) && (this->iv_sbeRegister.sbeBooted))
            {
                if(!i_sbeHalted && !((this->iv_sbeRegister).asyncFFDC))
                {
                    this->sbe_run_extract_rc();

#if !defined(__HOSTBOOT_RUNTIME) && defined(CONFIG_PLDM)
                    // only call dumpSbe if not runtime or last resort for MPIPL (ie NO_RECOVERY_ACTION is set)
                    if ( !isMpIpl || (this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION) )
                    {
                        errlHndl_t dump_errl = PLDM::dumpSbe(iv_proc, iv_masterErrorLogPLID);

                        if (dump_errl)
                        {
                            SBE_TRACF("main_sbe_handler(2): SBE dump failed for processor 0x%08x, PLID 0x%08x",
                                      get_huid(iv_proc), iv_masterErrorLogPLID);
                            dump_errl->collectTrace("ISTEPS_TRACE");
                            dump_errl->collectTrace(SBEIO_COMP_NAME);
                            dump_errl->plid(iv_masterErrorLogPLID);
                            errlCommit(dump_errl, SBEIO_COMP_ID);
                        }
                    }
                    else
                    {
                        SBE_TRACF("main_sbe_handler(2): Skipping PLDM::dumpSbe(0x%08X, 0x%08x) while in MPIPL mode and currentAction = %d",
                            get_huid(iv_proc), iv_masterErrorLogPLID, this->iv_currentAction);
                    }
#endif
                }
                else
                {
                    SBE_TRACF("main_sbe_handler: Skipping extract_rc call because we have asyncFFDC");

                    // Note this call is important, if this is not called we could end up in a
                    // endless loop because this enforces MAX_SWITCH_SIDE_COUNT and MAX_SIDE_BOOT_ATTEMPTS
                    this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
                    this->bestEffortCheck();
                }
            }

        } while( (this->iv_sbeRegister).currState != SBE_STATE_RUNTIME );

        // If we ended up switching sides we want to mark it down as
        // as informational log
        //
        // Depending on how many times we may loop, log the counters
        // to help determine what path may have been taken
        if (this->iv_switchSidesFlag)
        {
            this->iv_switchSidesFlag = 0; // Clear for next time
            /*@
             * @errortype   ERRL_SEV_INFORMATIONAL
             * @moduleid    SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode  SBEIO_BOOTED_UNEXPECTED_SIDE
             * @userdata1[00:07]  Current SBE boot side
             * @userdata1[08:15]  Current SBE measurement side
             * @userdata1[16:31] Switch Sides Count
             * @userdata1[32:63] Switch Sides Count Mseeprom
             * @userdata2[00:31] Current Action
             * @userdata2[32:63] HUID of proc
             * @devdesc     SBE booted from unexpected side.
             * @custdesc    Processor Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_INFORMATIONAL,
                        SBEIO_EXTRACT_RC_HANDLER,
                        SBEIO_BOOTED_UNEXPECTED_SIDE,
                        TWO_UINT32_TO_UINT64(
                           TWO_UINT16_TO_UINT32(
                              TWO_UINT8_TO_UINT16(l_bootside, l_mside),
                              this->iv_switchSidesCount),
                           this->iv_switchSidesCount_mseeprom),
                        TWO_UINT32_TO_UINT64(this->iv_currentAction, TARGETING::get_huid(iv_proc)));
            l_errl->collectTrace("ISTEPS_TRACE",256);
            l_errl->collectTrace(SBEIO_COMP_NAME,256);

            // Set the PLID of the error log to master PLID
            // if the master PLID is set
            updatePlids(l_errl);

            errlCommit(l_errl, SBEIO_COMP_ID);
        }

    }while(0);

#if defined(CONFIG_PLDM)
    if (isRuntimeOrMpIpl)
    {
        TARGETING::ATTR_CURRENT_SBE_HRESET_STATUS_type op_result = 0;

        if (isSbeAtRuntime())
        {
            SBE_TRACF("main_sbe_handler: HRESET on processor 0x%08x succeeded", get_huid(iv_proc));

            op_result = TARGETING::SBE_HRESET_STATUS_READY;
        }
        else
        {
            SBE_TRACF("main_sbe_handler: HRESET on processor 0x%08x failed", get_huid(iv_proc));

            op_result = TARGETING::SBE_HRESET_STATUS_FAILED;
        }

        PLDM::notifyEndSbeHreset(iv_proc, op_result, old_hreset_states);
    }
#endif

    SBE_TRACF(EXIT_MRK"main_sbe_handler: iv_switchSidesCount=%llx iv_switchSidesCount_mseeprom=%llx "
                      "iv_currentSideBootAttempts=%llx iv_currentSideBootAttempts_mseeprom=%llx iv_boot_restart_count=%d",
                      this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom,
                      this->iv_currentSideBootAttempts, this->iv_currentSideBootAttempts_mseeprom, this->iv_boot_restart_count);
}

bool SbeRetryHandler::sbe_run_extract_msg_reg()
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
    l_errl = this->sbe_poll_status_reg();

    // If there is no error getting the status register, and the SBE
    // did not make it to runtime AND the asyncFFDC bit is set, we will
    // use the FFDC to decide our actions rather than using p10_extract_sbe_rc
    if((!l_errl) &&
       (this->iv_sbeRegister.currState != SBE_STATE_RUNTIME) &&
       this->iv_sbeRegister.asyncFFDC)
    {
        SBE_TRACF("WARNING: sbe_run_extract_msg_reg completed without error for proc 0x%.8X .  "
                    "However, there was asyncFFDC found though so we will run the FFDC parser",
                  TARGETING::get_huid(iv_proc));
        // The SBE has responded to an asynchronous request that hostboot
        // made with FFDC indicating an error has occurred.
        // This should be the path we hit when we are waiting to see
        // if the sbe boots
        this->sbe_get_ffdc_handler();
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
        ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog( l_errl );

        // Commit error log
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    // No error,  able to read the sbe status register okay
    // No guarantees that the SBE made it to runtime
    else
    {
        SBE_TRACF("sbe_run_extract_msg_reg completed without error for proc 0x%.8X",
                    TARGETING::get_huid(iv_proc));
    }

    SBE_TRACF(EXIT_MRK "sbe_run_extract_msg_reg()");

    return l_statusReadSuccess;

}

errlHndl_t SbeRetryHandler::sbe_poll_status_reg()
{
    SBE_TRACF(ENTER_MRK "sbe_poll_status_reg()");

    errlHndl_t l_errl = nullptr;

    this->iv_currentSBEState =
            SbeRetryHandler::SBE_STATUS::SBE_NOT_AT_RUNTIME;

    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
            l_fapi2_proc_target(iv_proc);

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

    SBE_TRACF("sbe_poll_status_reg Running p10_get_sbe_msg_register HWP on proc target %.8X",
               TARGETING::get_huid(iv_proc));

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
                    SbeRetryHandler::SBE_STATUS::FAILED_COLLECTING_REG;
            break;
        }
        else if ((this->iv_sbeRegister).currState == SBE_STATE_RUNTIME)
        {
            SBE_TRACF("SBE 0x%.8X booted and at runtime, "
                      "iv_sbeRegister=0x%.8X, on loop %d",
                      TARGETING::get_huid(iv_proc),
                      (this->iv_sbeRegister).reg,
                      l_loops);
            this->iv_currentSBEState =
                  SbeRetryHandler::SBE_STATUS::SBE_AT_RUNTIME;
            break;
        }
        else if ((this->iv_sbeRegister).asyncFFDC)
        {
            SBE_TRACF("SBE 0x%.8X has async FFDC bit set, "
                      "iv_sbeRegister=0x%.8X",TARGETING::get_huid(iv_proc),
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
                          TARGETING::get_huid(iv_proc),
                           (this->iv_sbeRegister).reg);
            }
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
            iv_proc->getAttr<TARGETING::ATTR_SCOM_SWITCHES>();
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
                    TARGETING::get_huid(iv_proc));
            iv_proc->setAttr<TARGETING::ATTR_SCOM_SWITCHES>(l_switches);
        }
    }

    SBE_TRACF(EXIT_MRK "sbe_poll_status_reg()");
    return l_errl;
}

#ifndef __HOSTBOOT_RUNTIME
void SbeRetryHandler::handleFspIplTimeFail()
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

    // Before triggering the shutdown, disable the automatic attribute sync
    //  that we would normally do if the dead SBE is the boot proc.  This is
    //  to prevent hangs on the FSP since they use the SBE to handle the
    //  messages we send them.
    TARGETING::Target* l_bootproc = nullptr;
    TARGETING::targetService().masterProcChipTargetHandle( l_bootproc );
    if( l_bootproc == iv_proc )
    {
        errlHndl_t l_errhdl = TARGETING::AttrRP::disableAttributeSyncToSP();
        if( l_errhdl )
        {
            SBE_TRACF("SbeRetryHandler::handleFspIplTimeFail> Error disabling shutdown");
            errlCommit(l_errhdl, INITSVC_COMP_ID);
        }
    }

    // On FSP systems if we failed to recover the SBE then we should shutdown w/ the
    // correct error so that HWSV will know what FFDC to collect
    INITSERVICE::doShutdownWithError(this->iv_shutdownReturnCode,
                                     TARGETING::get_huid(iv_proc));
}
#endif

void SbeRetryHandler::sbe_get_ffdc_handler()
{
    SBE_TRACF(ENTER_MRK "sbe_get_ffdc_handler()");
    uint32_t l_responseSize = SbeFifoRespBuffer::MSG_BUFFER_SIZE_WORDS;
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
    l_errl = getFifoSBEFFDC(iv_proc,
                            l_pFifoResponse,
                            l_responseSize);

    // Check if there was an error log created
    if(l_errl)
    {
        // Trace but otherwise silently ignore error
        SBE_TRACF("sbe_get_ffdc_handler: ignoring error PLID=0x%x from "
                  "get SBE FFDC FIFO request to proc 0x%.8X",
                  l_errl->plid(),
                  TARGETING::get_huid(iv_proc));
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
            ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(l_errl);
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
                                             TARGETING::get_huid(iv_proc),
                                             l_pkgs);

            // Also log the failing proc as FFDC
            ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog(l_errl);


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

                    //Put FFDC data into sbeFfdc_t struct and
                    //call FAPI_SET_SBE_ERROR
                    fapi2::sbeFfdc_t * l_sbeFfdc = reinterpret_cast<sbeFfdc_t * >(l_package.ffdcPtr);
                    uint32_t l_pos = iv_proc->getAttr<TARGETING::ATTR_FAPI_POS>();
                    FAPI_SET_SBE_ERROR(l_fapiRc, l_rc, l_sbeFfdc, l_pos);

                    errlHndl_t l_sbeHwpfErr = rcToErrl(l_fapiRc);
                    // If we created an error successfully we must now commit it
                    if(l_sbeHwpfErr)
                    {
                        bool l_redundant_clock_failure_handling_needed = false;
                        HWAS::clockTypeEnum l_clock_failure_type = { };

                        // Iterate over user details sections of the error log to check for UD
                        // callouts from the HWPF component
                        // NOTE: rcToErrl will make UD Callouts have ERRL_COMP_ID/ERRL_UDT_CALLOUT
                        for(const auto l_callout : l_sbeHwpfErr->getUDSections(ERRL_COMP_ID,
                                                                                ERRORLOG::ERRL_UDT_CALLOUT) )
                        {
                            const auto l_ud = reinterpret_cast<HWAS::callout_ud_t*>(l_callout);

                            if (l_ud->type == HWAS::CLOCK_CALLOUT)
                            {
                                // we delay the clock failure handling until the
                                // end because the code may add callouts, and we
                                // don't want to modify the callout list while
                                // we're iterating it.
                                l_redundant_clock_failure_handling_needed = true;
                                l_clock_failure_type = l_ud->clockType;
                            }

                            // IF the callout has a gard associated with it we need to do a reconfig loop
                            if((l_ud->type == HWAS::HW_CALLOUT && l_ud->gardErrorType != HWAS::GARD_NULL) ||
                               (l_ud->type == HWAS::CLOCK_CALLOUT && l_ud->clkGardErrorType != HWAS::GARD_NULL) ||
                               (l_ud->type == HWAS::PART_CALLOUT && l_ud->partGardErrorType != HWAS::GARD_NULL))
                            {
                                l_reconfigRequired = true;
                            }
                        }

                        if (l_redundant_clock_failure_handling_needed && iv_clock_error_handler)
                        {
                            iv_clock_error_handler(l_sbeHwpfErr, iv_proc, l_clock_failure_type);
                        }

                        addRegisterFFDC(l_sbeHwpfErr);

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

            addRegisterFFDC(l_errl);

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


void SbeRetryHandler::sbe_run_extract_rc()
{
    SBE_TRACF(ENTER_MRK "sbe_run_extract_rc()");

    errlHndl_t l_errl = nullptr;

    // Setup for the HWP
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi2ProcTarget(
                        const_cast<TARGETING::Target*> (iv_proc));

    // Default the return action to be NO_RECOVERY , if something goes
    // wrong in p10_extract_sbe_rc and l_ret doesn't get set in that function
    // then we want to fall back on NO_RECOVERY which we will handle
    // accordingly in bestEffortCheck
    P10_EXTRACT_SBE_RC::RETURN_ACTION l_ret =
        P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;

    /**
     * @brief This param is only used in the lab when running this HWP with
     *        cronus. Hostboot offered to have this param set based on the
     *        security settings of the system, however, HW team said it
     *        would be safer for us to always assume the system is in
     *        secure mode.
     */
    const bool UNSECURE_MODE_disabled = false;

    FAPI_INVOKE_HWP( l_errl,
                     p10_extract_sbe_rc, l_fapi2ProcTarget,
                     l_ret, iv_useSDB, UNSECURE_MODE_disabled);

    this->iv_currentAction = l_ret;
    SBE_TRACF("sbe_run_extract_rc p10_extract_sbe_rc returned iv_currentAction=%d", this->iv_currentAction);

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
                  " returned action %d (from bestEffortCheck) and errorlog PLID=0x%x, rc=0x%.4X",
                  this->iv_currentAction, l_errl->plid(), l_errl->reasonCode());

        l_errl->collectTrace(SBEIO_COMP_NAME,512);
        l_errl->collectTrace(FAPI_IMP_TRACE_NAME, 256);
        l_errl->collectTrace(FAPI_TRACE_NAME, 384);

        // Capture the target data in the elog
        ERRORLOG::ErrlUserDetailsTarget(iv_proc).addToLog( l_errl );

        addRegisterFFDC(l_errl);

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
    SBE_TRACF(ENTER_MRK"bestEffortCheck: iv_switchSidesCount=%llx iv_switchSidesCount_mseeprom=%llx "
                      "iv_currentSideBootAttempts=%llx iv_currentSideBootAttempts_mseeprom=%llx iv_boot_restart_count=%d",
                      this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom,
                      this->iv_currentSideBootAttempts, this->iv_currentSideBootAttempts_mseeprom, this->iv_boot_restart_count);
    // We don't want to accept that there is no recovery action just
    // because that is what extract_rc is telling us. We want to make
    // sure we have tried booting on this seeprom twice, and that we
    // have tried the other seeprom twice as well. If we have tried all of
    // those cases then we will fail out
    //
    // We have to check each flow separate to determine
    if(this->iv_currentAction == P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION)
    {
        if ((this->iv_currentSideBootAttempts < MAX_SIDE_BOOT_ATTEMPTS) ||
            (this->iv_currentSideBootAttempts_mseeprom < MAX_SIDE_BOOT_ATTEMPTS))
        {
            SBE_TRACF("bestEffortCheck(): suggested action was NO_RECOVERY_ACTION but we are trying RESTART_SBE");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::RESTART_SBE;
        }
        else if (this->iv_switchSidesCount < MAX_SWITCH_SIDE_COUNT)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was NO_RECOVERY_ACTION but we are trying REIPL_BKP_SEEPROM");
            // Since we don't know to try SEEPROM or MSEEPROM, we will iterate on both if we continue to get NO_RECOVERY_ACTION
            // and fall into this logic, until we exhaust the MAX
            this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
        }
        else if (this->iv_switchSidesCount_mseeprom < MAX_SWITCH_SIDE_COUNT)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was NO_RECOVERY_ACTION but we are trying REIPL_BKP_MSEEPROM");
            // Since we don't know to try SEEPROM or MSEEPROM, we will iterate on both if we continue to get NO_RECOVERY_ACTION
            // and fall into this logic, until we exhaust the MAX
            this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
        }
        else
        {
            SBE_TRACF("bestEffortCheck(): Exhausted max boot and max sides attempts, NO_RECOVERY_ACTION available, time to give up");
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
    else if(this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM ||
        this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM )
    {
        if (this->iv_switchSidesCount_mseeprom >= MAX_SWITCH_SIDE_COUNT)
        {
            SBE_TRACF("bestEffortCheck(): suggested action was REIPL_BKP_MSEEPROM/REIPL_UPD_MSEEPROM but that is not possible so changing to NO_RECOVERY_ACTION");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
        }
    }
    else if(this->iv_currentAction == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)
    {
        // Only switch to NO_RECOVERY_ACTION if BOTH sides have reached the maximum limit
        // - This means if (only) 1 side has reached the limit both sides will still be switched
        // as there is still a chance that switching the other side might help
        if ((this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT) &&
            (this->iv_switchSidesCount_mseeprom >= MAX_SWITCH_SIDE_COUNT))
        {
            SBE_TRACF("bestEffortCheck(): suggested action was REIPL_BKP_BMSEEPROM but that is not possible so changing to NO_RECOVERY_ACTION");
            this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
        }
    }

    // If the extract sbe rc hwp tells us to restart, and we have already
    // done 2 retries on this side, then attempt to switch sides, if we can't
    // switch sides, set currentAction to NO_RECOVERY_ACTION
    else if(this->iv_currentAction == P10_EXTRACT_SBE_RC::RESTART_SBE ||
            this->iv_currentAction == P10_EXTRACT_SBE_RC::RESTART_CBS)
    {
        // Each recovery cycle will have re-instantiated the object, so the counts related to the failures tell us
        // which SEEPROM or MSEEPROM to attempt the action on
        if (this->iv_currentSideBootAttempts >= MAX_SIDE_BOOT_ATTEMPTS)
        {
            if (this->iv_switchSidesCount >= MAX_SWITCH_SIDE_COUNT)
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS SEEPROM but no actions possible so changing to NO_RECOVERY_ACTION");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            }
            else
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS but max attempts tried already so changing to REIPL_BKP_SEEPROM");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM;
            }
        }
        else if (this->iv_currentSideBootAttempts_mseeprom >= MAX_SIDE_BOOT_ATTEMPTS)
        {
            if (this->iv_switchSidesCount_mseeprom >= MAX_SWITCH_SIDE_COUNT)
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS MSEEPROM but no actions possible so changing to NO_RECOVERY_ACTION");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::NO_RECOVERY_ACTION;
            }
            else
            {
                SBE_TRACF("bestEffortCheck(): suggested action was RESTART_SBE/RESTART_CBS but max attempts tried already so changing to REIPL_BKP_MSEEPROM");
                this->iv_currentAction = P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM;
            }
        }
    }

    SBE_TRACF(EXIT_MRK"bestEffortCheck: iv_switchSidesCount=%llx iv_switchSidesCount_mseeprom=%llx "
                      "iv_currentSideBootAttempts=%llx iv_currentSideBootAttempts_mseeprom=%llx iv_boot_restart_count=%d",
                      this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom,
                      this->iv_currentSideBootAttempts, this->iv_currentSideBootAttempts_mseeprom, this->iv_boot_restart_count);
}

errlHndl_t SbeRetryHandler::switch_sbe_sides(P10_EXTRACT_SBE_RC::RETURN_ACTION i_action,
                                             bool i_updateMVPD)
{
    SBE_TRACF(ENTER_MRK "switch_sbe_sides: i_action=0x%X i_updateMVPD=%d iv_currentAction=0x%X "
                        "iv_switchSidesCount=%llx iv_switchSidesCount_mseeprom=%llx "
                        "iv_currentSideBootAttempts=%llx iv_currentSideBootAttempts_mseeprom=%llx",
                        i_action, i_updateMVPD, this->iv_currentAction,
                        this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom,
                        this->iv_currentSideBootAttempts, this->iv_currentSideBootAttempts_mseeprom);

    // switch_sbe_sides works on one seeprom at a time in order to track counts
    errlHndl_t l_errl = nullptr;
    SBE::mvpdSbKeyword_t l_mvpdSbKeyword = {0};

#ifndef __HOSTBOOT_RUNTIME
    if (i_updateMVPD)
    {
        l_errl = SBE::getSetMVPDVersion(iv_proc, SBE::MVPDOP_READ, l_mvpdSbKeyword);
        SBE_TRACF("MVPDOP_READ flags READ l_mvpdSbKeyword.flags=0x%X", l_mvpdSbKeyword.flags);

        if (l_errl)
        {
            // If we fail to READ we can later just WRITE a valid value
            // so log a PREDICTIVE event
            /*@
             * @errortype  ERRL_SEV_PREDICTIVE
             * @moduleid   SBEIO_EXTRACT_RC_HANDLER
             * @reasoncode SBEIO_MVPD_READ_FAILURE
             * @userdata1  l_mvpdSbKeyword.flags
             * @userdata2  HUID of proc
             * @devdesc    We failed trying to READ the MVPD
             * @custdesc   Processor Error
             */
            l_errl = new ERRORLOG::ErrlEntry(
                        ERRORLOG::ERRL_SEV_PREDICTIVE,
                        SBEIO_EXTRACT_RC_HANDLER,
                        SBEIO_MVPD_READ_FAILURE,
                        l_mvpdSbKeyword.flags,
                        TARGETING::get_huid(iv_proc));
            l_errl->collectTrace( SBEIO_COMP_NAME, 256);

            // Set the PLID of the error log to master PLID
            // if the master PLID is set
            updatePlids(l_errl);

            errlCommit(l_errl, SBEIO_COMP_ID);

            SBE_TRACF("ERROR MVPDOP_READ switch_sbe_sides: getSetMVPDVersion IPL time proc target = %.8X",
                      TARGETING::get_huid(iv_proc),
                       ERRL_GETRC_SAFE(l_errl),
                       ERRL_GETPLID_SAFE(l_errl));
        }
    }
#endif

    bool l_switch_boot_seeprom = false;
    bool l_switch_measurement_seeprom = false;

    if ((i_action == P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM) ||
        (i_action == P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM))
    {
        l_switch_boot_seeprom = true;
    }
    else if ((i_action == P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM) ||
        (i_action == P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM))
    {
        l_switch_measurement_seeprom = true;
    }
    else if (i_action == P10_EXTRACT_SBE_RC::REIPL_BKP_BMSEEPROM)
    {
        l_switch_boot_seeprom = true;
        l_switch_measurement_seeprom = true;
    }
    else
    {
        // FAIL SAFE option is to flip both boot and measurement
        l_switch_boot_seeprom = true;
        l_switch_measurement_seeprom = true;
        SBE_TRACF("switch_sbe_sides: FAIL SAFE case i_action=0x%X, switch boot and measurement seeprom sides",
                  i_action);
    }
    SBE_TRACF("switch_sbe_sides: i_action=0x%X l_switch_boot_seeprom=%d, "
              "l_switch_measurement_seeprom=%d l_mvpdSbKeyword.flags=0x%X",
              i_action, l_switch_boot_seeprom, l_switch_measurement_seeprom, l_mvpdSbKeyword.flags);

    do{
        // Read the Selfboot Control/Status reg (used as the authoritative source at this point)
        uint32_t l_ctl_reg = 0;
        l_errl = accessControlReg( ACCESS_READ, l_ctl_reg );
        if( l_errl )
        {
            SBE_TRACF( ERR_MRK"switch_sbe_sides: Control reg read failed : proc target = %.8X, RC=0x%X, PLID=0x%lX",
                       TARGETING::get_huid(iv_proc),
                       ERRL_GETRC_SAFE(l_errl),
                       ERRL_GETPLID_SAFE(l_errl));
            break;
        }

        // Determine which boot and measurement sides are currently set and
        // then flip sides accordingly based on logic above
        // NOTE: bit 17 represents the boot seeprm (SEEPROM)
        //       bit 18 represents the measurement seeprom (MSEEPROM)
        SBE_TRACF("switch_sbe_sides: HUID=0x%X Currently l_ctl_reg=0x%.8X",
                  TARGETING::get_huid(iv_proc), l_ctl_reg);

        if (l_switch_boot_seeprom)
        {
            if (l_ctl_reg & (SBE::SBE_BOOT_SELECT_MASK >> 32))
            {
                // bit17 already set, so clear it
                // Set Boot Side 0
                SBE_TRACF("switch_sbe_sides: iv_switchSidesCount=%d, Flip to Set Boot Seeprom Side 0 for HUID 0x%08X",
                          iv_switchSidesCount, TARGETING::get_huid(iv_proc));
                l_ctl_reg &= ~(SBE::SBE_BOOT_SELECT_MASK >> 32); // clear bit 17
                l_mvpdSbKeyword.flags &= ~REIPL_SEEPROM_MASK;  // clear MVPD SEEPROM flag bit
            }
            else
            {
                // bit17 is not set, so set it
                // Set Boot Side 1
                SBE_TRACF("switch_sbe_sides: iv_switchSidesCount=%d, Flip to Set Boot Seeprom Side 1 for HUID 0x%08X",
                          iv_switchSidesCount, TARGETING::get_huid(iv_proc));
                l_ctl_reg |= (SBE::SBE_BOOT_SELECT_MASK >> 32); // set bit 17
                l_mvpdSbKeyword.flags |= REIPL_SEEPROM_MASK;   // set MVPD SEEPROM flag bit
            }
        }

        if (l_switch_measurement_seeprom)
        {
            if (l_ctl_reg & (SBE::SBE_MBOOT_SELECT_MASK >> 32))
            {
                // bit18 already set, so clear it
                // Set Measurement Side 0
                SBE_TRACF("switch_sbe_sides: iv_switchSidesCount_mseeprom=%d, Flip to Set Measurement Seeprom Side 0 for HUID 0x%08X",
                          iv_switchSidesCount_mseeprom, TARGETING::get_huid(iv_proc));
                l_ctl_reg &= ~(SBE::SBE_MBOOT_SELECT_MASK >> 32); // clear bit 18
                l_mvpdSbKeyword.flags &= ~REIPL_MSEEPROM_MASK;  // clear MVPD MSEEPROM flag bit
            }
            else
            {
                // bit18 is not set, so set it
                // Set Measurement Side 1
                SBE_TRACF("switch_sbe_sides: iv_switchSidesCount_mseeprom=%d, Flip to Set Measurement Seeprom Side 1 for HUID 0x%08X",
                          iv_switchSidesCount_mseeprom, TARGETING::get_huid(iv_proc));
                l_ctl_reg |= (SBE::SBE_MBOOT_SELECT_MASK >> 32); // set bit 18
                l_mvpdSbKeyword.flags |= REIPL_MSEEPROM_MASK;   // set MVPD MSEEPROM flag bit
            }
        }
        SBE_TRACF("switch_sbe_sides: HUID=0x%X register to WRITE l_read_reg=0x%.8X MVPDOP_WRITE l_mvpdSbKeyword.flags=0x%X",
                  TARGETING::get_huid(iv_proc), l_ctl_reg, l_mvpdSbKeyword.flags);

        // Write updated Selfboot Control/Status register back into target proc
        l_errl = accessControlReg( ACCESS_WRITE, l_ctl_reg );
        if( l_errl )
        {
            SBE_TRACF( ERR_MRK"switch_sbe_sides: Control reg read failed : proc target = %.8X, RC=0x%X, PLID=0x%lX",
                       TARGETING::get_huid(iv_proc),
                       ERRL_GETRC_SAFE(l_errl),
                       ERRL_GETPLID_SAFE(l_errl));
            break;
        }

#ifndef __HOSTBOOT_RUNTIME
        if (i_updateMVPD)
        {
            // we could have failed to read earlier, but we have zeroes so no harm in writing
            SBE_TRACF("MVPDOP_WRITE flags to WRITE l_mvpdSbKeyword.flags=0x%X", l_mvpdSbKeyword.flags);
            l_errl = SBE::getSetMVPDVersion(iv_proc, SBE::MVPDOP_WRITE, l_mvpdSbKeyword);

            if (l_errl)
            {
                // If we fail to WRITE log a PREDICTIVE event
                /*@
                 * @errortype  ERRL_SEV_PREDICTIVE
                 * @moduleid   SBEIO_EXTRACT_RC_HANDLER
                 * @reasoncode SBEIO_MVPD_WRITE_FAILURE
                 * @userdata1  l_mvpdSbKeyword.flags
                 * @userdata2  HUID of proc
                 * @devdesc    We failed trying to READ the MVPD
                 * @custdesc   Processor Error
                 */
                l_errl = new ERRORLOG::ErrlEntry(
                            ERRORLOG::ERRL_SEV_PREDICTIVE,
                            SBEIO_EXTRACT_RC_HANDLER,
                            SBEIO_MVPD_WRITE_FAILURE,
                            l_mvpdSbKeyword.flags,
                            TARGETING::get_huid(iv_proc));
                l_errl->collectTrace( SBEIO_COMP_NAME, 256);

                // Set the PLID of the error log to master PLID
                // if the master PLID is set
                updatePlids(l_errl);

                errlCommit(l_errl, SBEIO_COMP_ID);
                SBE_TRACF("ERROR MVPDOP_WRITE switch_sbe_sides: getSetMVPDVersion IPL time proc target = %.8X",
                          TARGETING::get_huid(iv_proc),
                           ERRL_GETRC_SAFE(l_errl),
                           ERRL_GETPLID_SAFE(l_errl));
            }
        }
#endif

        // Increment switch sides count
        if (l_switch_boot_seeprom) // SEEPROM
        {
            ++(this->iv_switchSidesCount);
            ++(this->iv_switchSidesFlag);
            // Since we just switched sides, and we havent attempted a boot yet,
            // set the current attempts for this side to be 0
            this->iv_currentSideBootAttempts = 0;
        }
        if (l_switch_measurement_seeprom) // MSEEPROM
        {
            ++(this->iv_switchSidesCount_mseeprom);
            ++(this->iv_switchSidesFlag);
            // Since we just switched sides, and we havent attempted a boot yet,
            // set the current attempts for this side to be 0
            this->iv_currentSideBootAttempts_mseeprom = 0;
        }
        SBE_TRACF("switch_sbe_sides: iv_switchSidesCount=%llx iv_switchSidesCount_mseeprom=%llx "
                  "iv_currentSideBootAttempts=%llx iv_currentSideBootAttempts_mseeprom=%llx iv_boot_restart_count=%d",
                  this->iv_switchSidesCount, this->iv_switchSidesCount_mseeprom,
                  this->iv_currentSideBootAttempts, this->iv_currentSideBootAttempts_mseeprom, this->iv_boot_restart_count);
    }while(0);

    if (l_errl)
    {
        // Set the PLID of the error log to master PLID
        // if the master PLID is set
        updatePlids(l_errl);
    }

    SBE_TRACF(EXIT_MRK "switch_sbe_sides");
    return l_errl;
}

/**
 * @brief  Read or write the Selfboot Control/Status register
 */
errlHndl_t SbeRetryHandler::accessControlReg( bool i_writeNotRead,
                                              uint32_t& io_ctlreg )
{
    errlHndl_t l_errl = nullptr;

#ifdef __HOSTBOOT_RUNTIME
    const bool l_isRuntime = true;
#else
    const bool l_isRuntime = false;
#endif

    do {
    if(!l_isRuntime && !iv_proc->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>())
    {
        if( i_writeNotRead == ACCESS_READ ) //read
        {
            // Read FSXCOMP_FSXLOG_SB_CS_FSI_BYTE 0x2820 for target proc
            uint32_t l_read_reg = 0;
            size_t l_opSize = sizeof(uint32_t);
            l_errl = DeviceFW::deviceOp(
                                        DeviceFW::READ,
                                        iv_proc,
                                        &l_read_reg,
                                        l_opSize,
                                        DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );

            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"accessControlReg: FSI device read "
                           "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, // 0x2820
                           TARGETING::get_huid(iv_proc),
                           ERRL_GETRC_SAFE(l_errl),
                           ERRL_GETPLID_SAFE(l_errl));
                break;
            }

            io_ctlreg = l_read_reg;
        }
        else
        {
            // Write updated FSXCOMP_FSXLOG_SB_CS_FSI 0x2820 back into target proc
            uint32_t l_write_reg = io_ctlreg;
            size_t l_opSize = sizeof(uint32_t);
            l_errl = DeviceFW::deviceOp(
                                        DeviceFW::WRITE,
                                        iv_proc,
                                        &l_write_reg,
                                        l_opSize,
                                        DEVICE_FSI_ADDRESS(FSXCOMP_FSXLOG_SB_CS_FSI_BYTE) );
            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"accessControlReg: FSI device write "
                           "FSXCOMP_FSXLOG_SB_CS_FSI_BYTE (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           FSXCOMP_FSXLOG_SB_CS_FSI_BYTE, // 0x2820
                           TARGETING::get_huid(iv_proc),
                           ERRL_GETRC_SAFE(l_errl),
                           ERRL_GETPLID_SAFE(l_errl));
                break;
            }
        }
    }
    else
    {
        if( i_writeNotRead == ACCESS_READ ) //read
        {
            // Read FSXCOMP_FSXLOG_SB_CS 0x50008 for target proc
            uint64_t l_read_reg = 0;
            size_t l_opSize = sizeof(uint64_t);
            l_errl = DeviceFW::deviceOp(
                                        DeviceFW::READ,
                                        iv_proc,
                                        &l_read_reg,
                                        l_opSize,
                                        DEVICE_SCOM_ADDRESS(FSXCOMP_FSXLOG_SB_CS) );

            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"accessControlReg: SCOM device read "
                           "FSXCOMP_FSXLOG_SB_CS (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           FSXCOMP_FSXLOG_SB_CS, // 0x50008
                           TARGETING::get_huid(iv_proc),
                           ERRL_GETRC_SAFE(l_errl),
                           ERRL_GETPLID_SAFE(l_errl));
                break;
            }

            // data is in the top word
            io_ctlreg = static_cast<uint32_t>(l_read_reg >> 32);
        }
        else
        {
            // Write updated FSXCOMP_FSXLOG_SB_CS 0x50008 back into target proc
            uint64_t l_write_reg = io_ctlreg;
            l_write_reg = (l_write_reg << 32); //data is in the top word
            size_t l_opSize = sizeof(uint64_t);
            l_errl = DeviceFW::deviceOp(
                                        DeviceFW::WRITE,
                                        iv_proc,
                                        &l_write_reg,
                                        l_opSize,
                                        DEVICE_SCOM_ADDRESS(FSXCOMP_FSXLOG_SB_CS) );
            if( l_errl )
            {
                SBE_TRACF( ERR_MRK"accessControlReg: SCOM device write "
                           "FSXCOMP_FSXLOG_SB_CS (0x%.4X), proc target = %.8X, "
                           "RC=0x%X, PLID=0x%lX",
                           FSXCOMP_FSXLOG_SB_CS, // 0x50008
                           TARGETING::get_huid(iv_proc),
                           ERRL_GETRC_SAFE(l_errl),
                           ERRL_GETPLID_SAFE(l_errl));
                break;
            }
        }
    }
    } while(0);

    return l_errl;
}

/**
 * @brief  Collect register data for FFDC to add to a log.
 */
void SbeRetryHandler::addRegisterFFDC( errlHndl_t i_errhdl )
{
    SBE_TRACF("addRegisterFFDC=%.8X",i_errhdl->eid());
    ErrlUserDetailsLogRegister l_regdata(iv_proc);

#ifdef __HOSTBOOT_RUNTIME
    const bool l_isRuntime = true;
#else
    const bool l_isRuntime = false;
#endif

    // Add all of the scratch registers
    // Use CFAM for secondary procs during IPL
    if(!l_isRuntime && !iv_proc->getAttr<TARGETING::ATTR_PROC_SBE_MASTER_CHIP>())
    {
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<1>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<2>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<3>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<4>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<5>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<6>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<7>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<8>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<9>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<10>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<11>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<12>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<13>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<14>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<15>::CFAM_ADDR));
        l_regdata.addData(DEVICE_CFAM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<16>::CFAM_ADDR));
    }
    else // otherwise use scoms
    {
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<1>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<2>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<3>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<4>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<5>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<6>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<7>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<8>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<9>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<10>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<11>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<12>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<13>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<14>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<15>::REG_ADDR));
        l_regdata.addData(DEVICE_SCOM_ADDRESS(INITSERVICE::SPLESS::MboxScratch_t<16>::REG_ADDR));
    }

    l_regdata.addToLog(i_errhdl);
}

} // End of namespace SBEIO
