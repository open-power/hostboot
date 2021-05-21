/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_retry_handler.H $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
 * SBE Retry Handler
 *
 */

#ifndef __SBE_RETRY_HANDLER_H
#define __SBE_RETRY_HANDLER_H

#include <isteps/hwpisteperror.H>
#include <p10_extract_sbe_rc.H>
#include <p10_sbe_ext_defs.H>
#include <sys/time.h>
#include <sbe/sbe_update.H>

namespace SBEIO
{

class SbeRetryHandler
{
    public:
        enum SBE_REG_RETURN
        {
            FAILED_COLLECTING_REG = 0, // Error returned from HWP
            SBE_AT_RUNTIME        = 1, // SBE is at runtime and booted
            SBE_NOT_AT_RUNTIME    = 2, // SBE has failed to boot
            PROC_DECONFIG         = 3, // Deconfig done on Proc with SBE
        };

        //Possible values of iv_sbeMode
        enum SBE_MODE_OF_OPERATION
        {
            INFORMATIONAL_ONLY = 0, // Get error logs from the SBE HWP's
                                    // This will not attempt an SBE restart
                                    // On FSP systems if informational mode is set we will TI
                                    // On BMC systems we will run extract_rc then bail out
            ATTEMPT_REBOOT     = 1, // Full SBE run, attempt to restart
                                    // This will run all the steps and HWP's to attempt
                                    // an SBE restart on both sides.
#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
            // TEST variation values need to be greater than ATTEMPT_REBOOT
            // so when we check greater than ATTEMPT_REBOOT we get the TEST_* values
            TEST_BKP_SEEPROM   = 2,
            TEST_UPD_SEEPROM   = 3,
            TEST_BKP_MSEEPROM  = 4,
            TEST_UPD_MSEEPROM  = 5,
            TEST_RESTART_SBE   = 6,
            TEST_RESTART_CBS   = 7,
            TEST_MAX_LIMITS    = 8,
            TEST_SBE_FAILURE   = 9,
#endif
        };


#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        std::map<SBE_MODE_OF_OPERATION, P10_EXTRACT_SBE_RC::RETURN_ACTION> sbe_op_map =
        {
            {INFORMATIONAL_ONLY, P10_EXTRACT_SBE_RC::ERROR_RECOVERED},
            {ATTEMPT_REBOOT, P10_EXTRACT_SBE_RC::RESTART_SBE},
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

        enum SBE_RESTART_METHOD
        {
            START_CBS = 0,  // Use p10_start_cbs to restart the SBE
            HRESET    = 1,  // Use Hreset to restart the SBE
        };

        /**
         * @brief Constructor
         *
         * @param[in] i_sbeMode  Execute the SbeRetryHandler in either
         *                       informational mode, attempt to reboot mode,
         *                       or action set mode.
         *                       (@see sbe_retry_handler.H)
         */
        explicit SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode);

        /**
         * @brief Constructor
         *
         * @param[in] i_sbeMode  Execute the SbeRetryHandler in either
         *                       informational mode, attempt to reboot mode,
         *                       or action set mode.
         *                       (@see sbe_retry_handler.H)
         * @param[in] i_plid     A PLID that is to be propagated down to any
         *                       Error Log Entries that may be created
         */
        SbeRetryHandler(SBE_MODE_OF_OPERATION i_sbeMode, uint32_t i_plid);

        /**
         * @brief Destructor
         */
        ~SbeRetryHandler();

        /**************** Functions to return Class Elements ****************/
        inline bool isSbeAtRuntime()
        {
            return (iv_currentSBEState ==
                        SbeRetryHandler::SBE_REG_RETURN::SBE_AT_RUNTIME);
        }

        inline uint32_t getMasterPLID()
        {
            return iv_masterErrorLogPLID;
        }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        inline uint8_t getSwitchCount() const
        {
            return iv_switchSidesCount;
        }

        inline uint8_t getSwitchCountMseeprom() const
        {
            return iv_switchSidesCount_mseeprom;
        }

        inline uint8_t getCurrentSideCount() const
        {
            return iv_currentSideBootAttempts;
        }

        inline uint8_t getCurrentSideCountMseeprom() const
        {
            return iv_currentSideBootAttempts_mseeprom;
        }

        inline uint8_t getBootRestartCount() const
        {
            return iv_boot_restart_count;
        }
#endif

        inline sbeMsgReg_t getSbeRegister()
        {
            return iv_sbeRegister;
        }

        inline P10_EXTRACT_SBE_RC::RETURN_ACTION getCurrentAction()
        {
            return iv_currentAction;
        }

        inline SBE_REG_RETURN getCurrentSBEState()
        {
            return iv_currentSBEState;
        }
        inline SBE_RESTART_METHOD getSbeRestartMethod()
        {
            return iv_sbeRestartMethod;
        }
        inline void setSbeRestartMethod(SBE_RESTART_METHOD i_method)
        {
            iv_sbeRestartMethod = i_method;
        }

        inline SBE_MODE_OF_OPERATION getSBEMode()
        {
            return iv_sbeMode;
        }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        inline SBE_MODE_OF_OPERATION getSBETestMode() const
        {
            return iv_sbeTestMode;
        }
#endif

        inline void setSBEMode(SBE_MODE_OF_OPERATION i_sbeMode)
        {
            iv_sbeMode = i_sbeMode;
        }

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        inline void setSBETestMode(SBE_MODE_OF_OPERATION i_sbeTestMode)
        {
            iv_sbeTestMode = i_sbeTestMode;
        }
#endif

        inline bool getUseSDB()
        {
            return iv_useSDB;
        }

        inline void setUseSDB(bool i_useSDB)
        {
            iv_useSDB = i_useSDB;
        }

        inline bool getSecureModeDisabled()
        {
            return iv_secureModeDisabled;
        }

        inline void setSecureModeDisabled(bool i_secureModeDisabled)
        {
            iv_secureModeDisabled = i_secureModeDisabled;
        }

        inline void setInitialPowerOn(bool i_isInitialPowerOn)
        {
            iv_initialPowerOn = i_isInitialPowerOn;
        }

        /**
         * @brief  This function is the main entry point for all of the
         *         SBE handler functions.
         *
         * @param[in]  i_target    - current proc target
         * @param[in]  i_sbeHalted - sbe is halted on purpose, skip error path collection
         */

        void main_sbe_handler( TARGETING::Target * i_target, bool i_sbeHalted = false);

    private:
#ifndef __HOSTBOOT_RUNTIME
        /**
         * @brief  This function will look at the SBE status register and decide
         *         whether to send the SBEIO_DEAD_SBE or SBEIO_HWSV_COLLECT_SBE_RC
         *         along with the TI depending on if the asyncFFDC bit is set in
         *         the status register
         *
         * @param[in]  i_target    - current proc target we are handling fail for
         *
         * @return - void
         */
        void handleFspIplTimeFail(TARGETING::Target * i_target);
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
        *         to be whatever the PLID is of the error log passed to this function
        *
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
         * @brief  This function handles the SBE timeout and loops
         *         required to start it.
         *
         * @param[in]  i_target       - current proc target
         *
         * @return - error, NULL if no error
         */

        errlHndl_t sbe_poll_status_reg(TARGETING::Target * i_target);

        /**
         * @brief  This function handles getting the SBE FFDC.
         *
         * @param[in]     i_target        - current proc target
         *
         */

        void sbe_get_ffdc_handler(TARGETING::Target * i_target);

        /**
         * @brief  This function handles the SBE failed to boot error.
         *
         * @param[in]     i_target        - current proc target
         *
         * @return - bool: true if we need to retry
         *
         * Note: This will default to calling the 2 param version w/ i_hideLog
         *       set to TRUE
         */

        void sbe_run_extract_rc(TARGETING::Target * i_target);

        /**
         * @brief  This function deals with the mask needed to switch
         *         boot side on the SBE for a given proc
         *
         * @param[in] i_target - current proc target
         * @param[in] i_action - extract rc action recommendation
         * @param[in] i_updateMVPD - flag to indicate whether to update MVPD
         *
         * @return - error, NULL if no error
         */
        errlHndl_t switch_sbe_sides(TARGETING::Target * i_target,
                                    P10_EXTRACT_SBE_RC::RETURN_ACTION i_action,
                                    bool i_updateMVPD);

        /**
         * @brief This function handles the call to the p10_get_sbe_msg_handler.
         *        It will read the sbe msg register (Cfam 2809 or Scom 50009)
         *        and update iv_currentSBEState to reflect the state that
         *        the sbe's msg register is telling us
         *
         * @param[in] i_target - current proc target
         *
         * @return - return true if reading the message register was a success
         *           return false if there was an error getting the sbe msg register
         */
        bool sbe_run_extract_msg_reg(TARGETING::Target * i_target);

        /************************** Class Elements **************************/

        /*
        * @brief Bit used to tell if we are in secure debug mode. This means
        *        we are expecting a complete restart so it is safe to perform
        *        some extra operations.
        */
        bool iv_useSDB;

        /*
        * @brief Bit used for testing in the lab with systems that have secure
        *        mode disabled.
        *    NOTE: This bit is only used in the lab when running this HWP with cronus.
        *          We offered to have this bit set in FW based on the security settings of the
        *          system HW people told us it would be safer for us to always assume this bit
        *          is off in FW, so we will leave this bit as 0 until the HW devs tell us to use it.
        */
        bool iv_secureModeDisabled;

        /*
         * @brief If the caller of this class sets the PLID in the ctor
                  then the ctor will set that PLID to this instance variable.
                  If the caller does not pass a PLID into the ctor then the
                  first error log created while doing the retry will set this
                  PLID.
         */
        uint32_t iv_masterErrorLogPLID;

        /*
         * @brief Number of times we switch SBE sides. Max is defined by
         *        MAX_SWITCH_SIDE_COUNT
         */
        uint8_t iv_switchSidesCount;

        /*
         * @brief Number of times we switch SBE MSEEPROM sides. Max is defined by
         *        MAX_SWITCH_SIDE_COUNT
         */
        uint8_t iv_switchSidesCount_mseeprom;

        /*
         * @brief Flag used to indicate if we performed a side flip, then we log a message
         */
        uint8_t iv_switchSidesFlag;

        /*
         * @brief Counter used to indicate how many times we attempt RESTART_SBE's
         */
        uint8_t iv_boot_restart_count;

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        /*
         * @brief Counter used to drive test failure scenarios
         */
        uint8_t iv_sbeTestMode_recommendations;
#endif

        /*
         * @brief The current sbe register
         */
        sbeMsgReg_t iv_sbeRegister;

        /*
         * @brief The current SBE return action that has to be taken
         */
        P10_EXTRACT_SBE_RC::RETURN_ACTION iv_currentAction;

        /*
         * @brief The current SBE state - booted, failed, or deconfig
         */
        SBE_REG_RETURN iv_currentSBEState;

        /*
         * @brief Currently there are 3 options for what the shutdownReturnCode
         *        will be. It can be 0 if there is no return code we wish to
         *        send with shutdown. Then it can also be SBEIO_HWSV_COLLECT_SBE_RC
         *        to notify that HWSV should collect FFDC or it can be SBEIO_DEAD_SBE
         *        to tell HWSV that the SBE is dead.
         */
        uint32_t iv_shutdownReturnCode;

        /*
        * @brief This value will keep track of how many times we have attempted
        *        to boot the current side of the SBE's seeprom. In the ctor this
        *        value should be 1, because if the retry handler has been called
        *        that means that we have attempted to boot the current side at
        *        least 1 time. When we switch seeprom sides this value should
        *        drop back to 0. It will be incremeted each time we attempt
        *        to call start_cbs or hreset depending on iv_sbeRestartMethod
        */
        uint8_t iv_currentSideBootAttempts;

        /*
        * @brief This value will keep track of how many times we have attempted
        *        to boot the current side of the SBE's mseeprom. In the ctor this
        *        value should be 1, because if the retry handler has been called
        *        that means that we have attempted to boot the current side at
        *        least 1 time. When we switch mseeprom sides this value should
        *        drop back to 0. It will be incremeted each time we attempt
        *        to call start_cbs or hreset depending on iv_sbeRestartMethod
        */
        uint8_t iv_currentSideBootAttempts_mseeprom;

        /*
         * @brief The mode of operation that needs to be run through the
         *        SbeRetryHandler.  The different modes are specified in the
         *        SBE_MODE_OF_OPERATION enum
         */
        SBE_MODE_OF_OPERATION iv_sbeMode;

#ifdef CONFIG_COMPILE_CXXTEST_HOOKS
        /*
         * @brief The test mode of operation that needs to be run through the
         *        SbeRetryHandler.  The different modes are specified in the
         *        SBE_MODE_OF_OPERATION enum
         */
        SBE_MODE_OF_OPERATION iv_sbeTestMode;
#endif

        /*
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

        /*
        * @brief If true, this tells the retry_hanlder that the caller has recently
        *        attempted to boot the sbe on processor passed to the ctor. This
        *        tells us that the sbe_status register is not stale and that we
        *        can use the curState value on the status register to determine
        *        if the SBE made it to runtime or not
        */
        bool iv_initialPowerOn;

}; // End of class SbeRetryHandler

}  // End of namespace SBEIO
#endif
