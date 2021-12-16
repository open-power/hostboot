/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_retry_handler.H $                   */
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
 * @file sbe_retry_handler.H
 *
 * @brief Header file for the SbeRetryHandler class which is used to either:
 *          Detect if a SBE has successfully booted, and retry if it has not
 *           - OR -
 *          Force a recovery of the SBE if an error has been detected by another entity
 */

#ifndef __SBE_RETRY_HANDLER_H
#define __SBE_RETRY_HANDLER_H

// Hostboot userspace
#include <sbe/sbe_update.H>
#include <isteps/hwpisteperror.H>
// Fapi2 HWP
#include <p10_sbe_ext_defs.H>
#include <p10_extract_sbe_rc.H>

class SbeRetryHandlerTest;

namespace SBEIO
{
const bool IS_INITIAL_POWERON = true;
const bool NOT_INITIAL_POWERON = false;
const uint32_t EMPTY_PLID = 0;

class SbeRetryHandler
{
    public:
        /*
         * We cannot always trust the status that the sbe reports about itself.
         * This enum will be used by iv_currentSBEState so Hostboot can track what
         * we think the status of the SBE is.
         */
        enum SBE_STATUS
        {
            FAILED_COLLECTING_REG = 0, // Error returned from HWP
            SBE_AT_RUNTIME        = 1, // SBE is at runtime and booted
            SBE_NOT_AT_RUNTIME    = 2, // SBE has failed to boot
            PROC_DECONFIG         = 3, // Deconfig done on Proc with SBE
        };
        /**
         * @brief In some situations we only want to perform some FFDC collection
         *        rather than attempting to actually recover the SBE.
         */
        enum SBE_MODE_OF_OPERATION
        {
            INFORMATIONAL_ONLY, // This will not attempt an SBE restart but will run
                                // extract RC which will produce a visible error log.
                                // -- On FSP systems : If informational mode is set we
                                //    will run extract_rc then TI.
                                //
                                // -- On BMC systems : Hostboot will run extract_rc then
                                //    return back to the caller.

            ATTEMPT_REBOOT, // This mode will exhaust all boot attempts and sbe sides
                            // in an effort to recover the SBE.
                            // -- On FSP systems : Hostboot does not attempt to recover
                            //    the SBE during IPL time. At runtime SBE recovery will
                            //    be attempted.
                            //
                            // -- On BMC systems : Hostboot will only attempt to recover
                            //    secondary SBEs during inital booting of the SBE.
                            //    Subsequent failures during the IPL should result in
                            //    the processor getting garded and trigger a reconfig loop.
                            //    At runtime, SBE recovery will be attempted.
        };

        /**
         * @brief There are two options to restart an SBE. Either we can run the
         *        hreset HWP which can be thought of as a 'warm reboot' or we can
         *        run the start_cbs HWP which can be thought of as a 'cold reboot'.
         *        Typically once we get a SBE up to runtime at least once, we will
         *        only use hreset to restart the SBE. In the initial boot START_CBS
         *        will always be used.
         */
        enum SBE_RESTART_METHOD
        {
            START_CBS = 0,  // Use p10_start_cbs to restart the SBE
            HRESET    = 1,  // Use p10_sbe_hreset to restart the SBE
        };

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        enum SBE_FORCED_TEST_PATH
        {
            TEST_ERROR_RECOVERED,
            TEST_BKP_SEEPROM,
            TEST_UPD_SEEPROM,
            TEST_BKP_MSEEPROM,
            TEST_UPD_MSEEPROM,
            TEST_RESTART_SBE,
            TEST_RESTART_CBS,
            TEST_MAX_LIMITS,
            TEST_SBE_FAILURE
        };

        std::map<SBE_FORCED_TEST_PATH, P10_EXTRACT_SBE_RC::RETURN_ACTION> sbe_op_map =
        {
            {TEST_ERROR_RECOVERED, P10_EXTRACT_SBE_RC::ERROR_RECOVERED},
            {TEST_BKP_SEEPROM, P10_EXTRACT_SBE_RC::REIPL_BKP_SEEPROM},
            {TEST_UPD_SEEPROM, P10_EXTRACT_SBE_RC::REIPL_UPD_SEEPROM},
            {TEST_BKP_MSEEPROM, P10_EXTRACT_SBE_RC::REIPL_BKP_MSEEPROM},
            {TEST_UPD_MSEEPROM, P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM},
            {TEST_RESTART_SBE, P10_EXTRACT_SBE_RC::RESTART_SBE},
            {TEST_RESTART_CBS, P10_EXTRACT_SBE_RC::RESTART_CBS},
            {TEST_MAX_LIMITS, P10_EXTRACT_SBE_RC::REIPL_UPD_MSEEPROM},
            {TEST_SBE_FAILURE, P10_EXTRACT_SBE_RC::RESTART_SBE},
        };
#endif

        /**
         * @brief Constructor
         *
         * @param[in] i_proc Processor target whose SBE we wish to run the retry
         *                   logic on.
         * @param[in] i_sbeMode  Execute the SbeRetryHandler in either
         *                       informational mode, attempt to reboot mode.
         * @param[in] i_restartMethod The method to use if a restart is attempted.
         * @param[in] i_plid A PLID that is to be propagated down to any errorlog
         *                   entries that may be created
         * @param[in] i_isInitialPoweron boolean describing if this retry effort
         *                               is after an initial power on of the SBE
         *                               associated with i_proc
         */
         SbeRetryHandler(TARGETING::Target * const i_proc,
                         SBE_MODE_OF_OPERATION i_sbeMode,
                         SBE_RESTART_METHOD i_restartMethod,
                         const uint32_t i_plid,
                         const bool i_isInitialPoweron);

        /**
         * @brief Destructor
         */
        ~SbeRetryHandler();

        /**
         * @brief Return a bool stating whether or not Hostboot believes
         *        that the SBE is operational at runtime. Note that we are
         *        not relying on the curr_state stated in the SBE status
         *        register as that value has proven to be stale in cases
         *        where the SBE has made it to runtime but then later became
         *        unresponsive.
         */
        inline bool isSbeAtRuntime()
        {
            return (iv_currentSBEState ==
                        SbeRetryHandler::SBE_STATUS::SBE_AT_RUNTIME);
        }

        inline uint32_t getMasterPLID()
        {
            return iv_masterErrorLogPLID;
        }

        inline sbeMsgReg_t getSbeRegister()
        {
            return iv_sbeRegister;
        }

        /**
         * @brief  This function is the main entry point for all of the
         *         SBE handler functions.
         *
         * @param[in]  i_sbeHalted - sbe is halted on purpose, skip error path collection
         */
        void main_sbe_handler(bool i_sbeHalted = false);

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        inline void setSBETestMode(SBE_FORCED_TEST_PATH i_sbeTestMode)
        {
            iv_sbeTestMode = i_sbeTestMode;
        }
#endif

    private:
#ifndef __HOSTBOOT_RUNTIME
        /**
         * @brief  This function will look at the SBE status register and decide
         *         whether to send the SBEIO_DEAD_SBE or SBEIO_HWSV_COLLECT_SBE_RC
         *         along with the TI depending on if the asyncFFDC bit is set in
         *         the status register
         *
         * @return - void
         */
        void handleFspIplTimeFail();
#endif

        /**
         * @brief  This function will look at what iv_currentAction is set to
         *          and take into account how many times we have tried to boot
         *          and how many times we have switched sides.
         *          Note: no_recovery is only an acceptable answer if we have tried
         *                all possibilities. That means that we must have attempted
         *                two boots on both sides. If we have not hit our max attempts
         *                for both sides then this procedure should change iv_currentAction
         *                to either RESTART_SBE or REIPL_BKP_SEEPROM
         *
         * @return - void
         */
        void bestEffortCheck();

        /**
        * @brief  It is possible that multiple error logs will get created throughout
        *         the process of trying to recover the SBE. We want all of these logs
        *         to share the same platform log id (PLID). This function will check
        *         if iv_masterErrorLogPLID is non-zero, if it is we will set the PLID
        *         of the error log passed into this function to be iv_masterErrorLogPLID.
        *         If iv_masterErrorLogPLID is zero, we will update iv_masterErrorLogPLID
        *         to be whatever the PLID is of the error log passed to this function.
        *
        * @return - void
        */
        inline void updatePlids(errlHndl_t & i_errl)
        {
            if(iv_masterErrorLogPLID)
            {
                i_errl->plid(iv_masterErrorLogPLID);
            }
            else
            {
                iv_masterErrorLogPLID = i_errl->plid();
            }
        }

        /**
         * @brief This function will poll the SBE status register every 1 sec
         *        (10 secs on simics) for 60 secs (600 seconds on simics).
         *        iv_sbeRegister will be populated with the value read from the
         *        status register. If an error occurs reading the SBE status
         *        register, iv_sbeRegister will be set to 0 and the retry_handler
         *        should give up. If iv_sbeRegister.currState == SBE_STATE_RUNTIME,
         *        then we know the SBE has booted successfully and we exit the polling
         *        loop. Else if the iv_sbeRegister.asyncFFDC == 1 then we know the SBE
         *        has failed to boot and we will exit the polling loop.
         *
         * @return - error, nullptr if no error
         */
        errlHndl_t sbe_poll_status_reg();

        /**
         * @brief  This function handles getting the SBE FFDC.
         *
         * @return void
         */
        void sbe_get_ffdc_handler();

        /**
         * @brief Run extract_sbe_rc HWP on iv_proc. This HWP should
         *        always return an error, which will be committed within
         *        this function. extract_sbe_rc will return a 'suggested
         *        action' as one of its out parameters. This function
         *        will set this value to iv_currentAction.
         *
         * @return void
         *
         */
        void sbe_run_extract_rc();

        /**
         * @brief  This function deals with the mask needed to switch
         *         boot side on the SBE for a given proc
         *
         * @param[in] i_action - extract rc action recommendation
         * @param[in] i_updateMVPD - flag to indicate whether to update MVPD
         *
         * @return - error, nullptr if no error
         */
        errlHndl_t switch_sbe_sides(P10_EXTRACT_SBE_RC::RETURN_ACTION i_action,
                                    bool i_updateMVPD);

        /**
         * @brief This function handles the call to the p10_get_sbe_msg_handler.
         *        It will read the sbe msg register (Cfam 2809 or Scom 50009)
         *        and update iv_currentSBEState to reflect the state that
         *        the sbe's msg register is telling us
         *
         * @return - return true if reading the message register was a success
         *           return false if there was an error getting the sbe msg register
         */
        bool sbe_run_extract_msg_reg();

        /**
         * @brief  Read or write the Selfboot Control/Status register
         *
         * @param[in] i_writeNotRead - true=write; false=read
         * @param[inout] io_ctlreg - data to read or write
         *
         * @return - error, NULL if no error
         */
        errlHndl_t accessControlReg( bool i_writeNotRead,
                                     uint32_t& io_ctlreg );
        static constexpr bool ACCESS_WRITE = true;
        static constexpr bool ACCESS_READ = false;

        /************************** Class Elements **************************/

        /**
         * @brief Bit used to tell if we are in secure debug mode. This means
         *        we are expecting a complete restart so it is safe to perform
         *        some extra operations.
         */
        bool iv_useSDB;

        /**
         * @brief If the caller of this class sets the PLID in the ctor
         *        then the ctor will set that PLID to this instance variable.
         *        If the caller does not pass a PLID into the ctor then the
         *        first error log created while doing the retry will set this
         *        PLID.
         */
        uint32_t iv_masterErrorLogPLID;

        /**
         * @brief Number of times we switch SBE sides. Max is defined by
         *        MAX_SWITCH_SIDE_COUNT
         */
        uint8_t iv_switchSidesCount;

        /**
         * @brief Number of times we switch SBE MSEEPROM sides. Max is defined by
         *        MAX_SWITCH_SIDE_COUNT
         */
        uint8_t iv_switchSidesCount_mseeprom;

        /**
         * @brief Flag used to indicate if we performed a side flip
         */
        uint8_t iv_switchSidesFlag;

        /**
         * @brief Counter used to indicate how many times we attempt RESTART_SBE's
         */
        uint8_t iv_boot_restart_count;

        /**
         * @brief The current sbe register
         */
        sbeMsgReg_t iv_sbeRegister;

        /**
         * @brief The current SBE return action that has to be taken
         */
        P10_EXTRACT_SBE_RC::RETURN_ACTION iv_currentAction;

        /*
         * @brief The current SBE state - booted, failed, or deconfig
         */
        SBE_STATUS iv_currentSBEState;

        /*
         * @brief Currently there are 3 options for what the shutdownReturnCode
         *        will be. It can be 0 if there is no return code we wish to
         *        send with shutdown. Then it can also be SBEIO_HWSV_COLLECT_SBE_RC
         *        to notify that HWSV should collect FFDC or it can be SBEIO_DEAD_SBE
         *        to tell HWSV that the SBE is dead.
         */
        uint32_t iv_shutdownReturnCode;

        /**
         * @brief This value will keep track of how many times we have attempted
         *        to boot the current side of the SBE's seeprom. In the ctor this
         *        value should be 1, because if the retry handler has been called
         *        that means that we have attempted to boot the current side at
         *        least 1 time. When we switch seeprom sides this value should
         *        drop back to 0. It will be incremeted each time we attempt
         *        to call start_cbs or hreset depending on iv_sbeRestartMethod
         */
        uint8_t iv_currentSideBootAttempts;

        /**
         * @brief This value will keep track of how many times we have attempted
         *        to boot the current side of the SBE's mseeprom. In the ctor this
         *        value should be 1, because if the retry handler has been called
         *        that means that we have attempted to boot the current side at
         *        least 1 time. When we switch mseeprom sides this value should
         *        drop back to 0. It will be incremeted each time we attempt
         *        to call start_cbs or hreset depending on iv_sbeRestartMethod
         */
        uint8_t iv_currentSideBootAttempts_mseeprom;

        /**
         * @brief The mode of operation that needs to be run through the
         *        SbeRetryHandler.  The different modes are specified in the
         *        SBE_MODE_OF_OPERATION enum
         */
        SBE_MODE_OF_OPERATION iv_sbeMode;

        /**
         * @brief This instance variable will instruct the main_sbe_handler
         *        loop on what method to use when attempting to restart the
         *        sbe that we have detected an error on. Currently there are
         *        two options to recover an sbe in a bad state. The first option
         *        is to run "start_cbs", this essentially powers down the proc
         *        and starts the boot sequence from the beginning. This is okay
         *        to use when initially trying to poweron slave processor's sbe
         *        but it is not as useful after that as it will blow away any fabric
         *        initialization we have done on the slave proc chip. The other
         *        option is to use HRESET. HRESET will attempt to restart the
         *        sbe on the fly and does not require us to completely restart
         *        the processor. HRESET can be used during runtime to attempt
         *        to recover an sbe while not disrupting the rest of the proc
         *        chips. Both choices are noted in the SBE_RESTART_METHOD enum
         */
        SBE_RESTART_METHOD iv_sbeRestartMethod;

        /**
         * @brief If true, this tells the retry_handler that the caller has recently
         *        attempted to boot the sbe on processor passed to the ctor. This
         *        tells us that the sbe_status register is not stale and that we
         *        can use the curState value on the status register to determine
         *        if the SBE made it to runtime or not.
         */
        bool iv_initialPowerOn;

        /**
         * @brief Processor target whose SBE we wish to run the retry logic on.
         */
        TARGETING::Target* iv_proc;

        // For testcases
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        /*
         * @brief Counter used to drive test failure scenarios
         */
        uint8_t iv_sbeTestMode_recommendations;

        /*
         * @brief The test mode of operation that needs to be run through the
         *        SbeRetryHandler.  The different modes are specified in the
         *        SBE_FORCED_TEST_PATH enum
         */
        SBE_FORCED_TEST_PATH iv_sbeTestMode;
#endif
        friend class ::SbeRetryHandlerTest;

}; // End of class SbeRetryHandler

}  // End of namespace SBEIO
#endif
