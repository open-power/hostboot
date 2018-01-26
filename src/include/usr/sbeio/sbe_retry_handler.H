/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_retry_handler.H $                   */
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
#ifndef __SBE_RETRY_HANDLER_H
#define __SBE_RETRY_HANDLER_H

#include <isteps/hwpisteperror.H>
#include <p9_extract_sbe_rc.H>
#include <p9_get_sbe_msg_register.H>

namespace SBEIO
{

class SbeRetryHandler
{
    public:

        static const uint8_t MAX_SWITCH_SIDE_COUNT = 2;

        enum SBE_REG_RETURN
        {
            HWP_ERROR           = 0, // Error returned from HWP
            SBE_AT_RUNTIME      = 1, // SBE is at runtime and booted
            SBE_FAILED_TO_BOOT  = 2, // SBE has failed to boot
            PROC_DECONFIG       = 3, // Deconfig done on Proc with SBE
        };

        enum SBE_MODE_OF_OPERATION
        {
            INFORMATIONAL_ONLY = 0, // Get error logs from the SBE HWP's
                    // This will not attempt a SBE restart, and it will only
                    // run the steps to get the p9_extract_sbe_rc return value.
            ATTEMPT_REBOOT     = 1, // Full SBE run, attempt to restart
                    // This will run all the steps and HWP's to attempt
                    // an SBE restart on both sides.
            SBE_ACTION_SET     = 2, // Full SBE run, but with a set action
                    // This will run all the steps and HWP's to attempt
                    // an SBE restart, however in this case we are specifying
                    // which SBE RETURN_ACTION we are attempting instead of
                    // the action the SBE thinks we should attempt.
        };

        enum SBE_RESTART_METHOD
        {
            START_CBS = 0,  // Use p9_start_cbs to restart the SBE
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
        inline bool getSbeRestart()
        {
            return this->iv_sbeRestarted;
        }

        inline uint8_t getSbeSide()
        {
            return this->iv_sbeSide;
        }

        inline uint32_t getPLID()
        {
            return this->iv_errorLogPLID;
        }

        inline uint32_t getCallerPLID()
        {
            return this->iv_callerErrorLogPLID;
        }

        inline uint8_t getSwitchCount()
        {
            return this->iv_switchSidesCount;
        }

        inline sbeMsgReg_t getSbeRegister()
        {
            return this->iv_sbeRegister;
        }

        inline P9_EXTRACT_SBE_RC::RETURN_ACTION getCurrentAction()
        {
            return this->iv_currentAction;
        }

        inline SBE_REG_RETURN getCurrentSBEState()
        {
            return this->iv_currentSBEState;
        }
        inline SBE_RESTART_METHOD getSbeRestartMethod()
        {
            return this->iv_sbeRestartMethod;
        }
        inline void setSbeRestartMethod(SBE_RESTART_METHOD i_method)
        {
            this->iv_sbeRestartMethod = i_method;
        }

        inline SBE_MODE_OF_OPERATION getSBEMode()
        {
            return this->iv_sbeMode;
        }

        inline void setSBEMode(SBE_MODE_OF_OPERATION i_sbeMode)
        {
            this->iv_sbeMode = i_sbeMode;
        }

        inline bool getUseSDB()
        {
            return this->iv_useSDB;
        }

        inline void setUseSDB(bool i_useSDB)
        {
            this->iv_useSDB = i_useSDB;
        }

        inline bool getSecureModeDisabled()
        {
            return this->iv_secureModeDisabled;
        }

        inline void setSecureModeDisabled(bool i_secureModeDisabled)
        {
            this->iv_secureModeDisabled = i_secureModeDisabled;
        }

        /**
         * @brief  This function is the main entry point for all of the
         *         SBE handler functions.
         *
         * @param[in]  i_target    - current proc target
         */

        void main_sbe_handler( TARGETING::Target * i_target);

    private:

        /**
         * @brief  This function handles the SBE timeout and loops
         *         required to start it.
         *
         * @param[in]  i_target       - current proc target
         *
         * @return - error, NULL if no error
         */

        errlHndl_t sbe_timeout_handler(TARGETING::Target * i_target);

        /**
         * @brief  This function handles getting the SBE FFDC.
         *
         * @param[in]     i_target        - current proc target
         *
         * @return - bool for flow control on return to caller, if false,
         *           caller should go on with the processing flow, if true,
         *           caller should interrupt the processing flow and get out
         *           of loop or current iteration
         */

        bool sbe_get_ffdc_handler(TARGETING::Target * i_target);

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

        bool sbe_boot_fail_handler(TARGETING::Target * i_target);

        /**
        * @brief  This function handles the SBE failed to boot error.
        *
        * @param[in]     i_target    - current proc target
        * @param[in]     i_exposeLog - an error log is created at the top
        *                              of this function, if we are doing retries
        *                              we might not want to have this log show up
        *                              i_exposeLog = true will make the elog PREDICTIVE
        *
        * @return - bool: true if we need to retry
        */

        bool sbe_boot_fail_handler(TARGETING::Target * i_target,
                                   bool i_exposeLog);

        /**
         * @brief  This function deals with the mask needed to switch
         *         boot side on the SBE for a given proc
         *
         * @param[in] i_target - current proc target
         *
         * @return - error, NULL if no error
         */
        errlHndl_t switch_sbe_sides(TARGETING::Target * i_target);

        /**
         * @brief This function handles the SBE register value and the actions
         *        that go along with it.
         *
         * @param[in] i_target            - current proc target
         */
        void handle_sbe_reg_value( TARGETING::Target * i_target);

        /**
         * @brief This is the switch case that identifies the action needed
         *        for the RC value in an SBE FFDC package.
         *
         * @param[in] i_rc            - RC value from SBE FFDC package
         *
         * @return - pass(0) or specific returned SBE action
         */
        P9_EXTRACT_SBE_RC::RETURN_ACTION action_for_ffdc_rc( uint32_t i_rc);

        /**
         * @brief This function handles the call to the p9_get_sbe_msg_handler.
         *        It determines what state the SBE is in.
         *
         * @param[in] i_target - current proc target
         *
         */
        void get_sbe_reg(TARGETING::Target * i_target);

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
        */
        bool iv_secureModeDisabled;

        /*
         * @brief True if we successfully restarted the SBE
         */
        bool iv_sbeRestarted;

        /*
         * @brief True if we switched to the other side of the SBE
         */
        uint8_t iv_sbeSide;

        /*
         * @brief PLID of the error logged. 0 if no error
         *        was logged.
         */
        uint32_t iv_errorLogPLID;

        /*
         * @brief PLID of the caller. 0 if caller does not
         *        provide one.  Not to be confused with the
         *        PLID when error log is created in the usage
         *        of this class.
         */
        uint32_t iv_callerErrorLogPLID;

        /*
         * @brief Number of times we switch SBE sides. Max is 2
         */
        uint8_t iv_switchSidesCount;

        /*
         * @brief The current sbe register
         */
        sbeMsgReg_t iv_sbeRegister;

        /*
         * @brief The current SBE return action that has to be taken
         */
        P9_EXTRACT_SBE_RC::RETURN_ACTION iv_currentAction;

        /*
         * @brief The current SBE state - booted, failed, or deconfig
         */
        SBE_REG_RETURN iv_currentSBEState;

        /*
         * @brief There are a few situations in which we have to retrigger
         *        the main function. This variable ensures we do not fall into
         *        an infinite loop situation
         */
        bool iv_retriggeredMain;

        /*
         * @brief The mode of operation that needs to be run through the
         *        SbeRetryHandler.  The different modes are specified in the
         *        SBE_MODE_OF_OPERATION enum
         */
        SBE_MODE_OF_OPERATION iv_sbeMode;

        /*
         * @brief If true, use the HWP p9_start_cbs to restart the SBE. This
         *        HWP kills the proc we're on, so there are some situations
         *        where we want to use hreset instead. Each choice is noted
         *        in the SBE_RESTART_METHOD enum
         */
        SBE_RESTART_METHOD iv_sbeRestartMethod;

}; // End of class SbeRetryHandler

}  // End of namespace SBEIO
#endif
