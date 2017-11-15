/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/sbeio/sbe_retry_handler.H $                   */
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

        /**
         * @brief Get the instance of this class
         *
         * @return the instance of SbeRetryHandler
         */
        NEVER_INLINE static SbeRetryHandler& getInstance();

        /**
         * @brief Constructor
         */
        SbeRetryHandler();

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

        inline bool getErrorLogged()
        {
            return this->iv_sbeErrorLogged;
        }

        inline uint32_t getPLID()
        {
            return this->iv_errorLogPLID;
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

        /**
         * @brief  This function is the main entry point for all of the
         *         SBE handler functions.
         *
         * @param[in]  i_target    - current proc target
         * @param[in]  i_actionSet - There are a few instances where we have
         *                  to recall the main function.  This variable is
         *                  set so that we don't override the new action.
         */

        void main_sbe_handler( TARGETING::Target * i_target, bool i_actionSet);

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
         * @param[out]    o_regReturn     - sbe reg return
         *
         * @return - bool: true if we need to retry
         */

        bool sbe_boot_fail_handler(TARGETING::Target * i_target);

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
         * @brief True if we successfully restarted the SBE
         */
        bool iv_sbeRestarted;

        /*
         * @brief True if we switched to the other side of the SBE
         */
        uint8_t iv_sbeSide;

        /*
         * @brief True if we logged an error during the SBE restart process
         */
        bool iv_sbeErrorLogged;

        /*
         * @brief PLID of the unrecoverable error logged. NULL if no error
         *        was logged.
         */
        uint32_t iv_errorLogPLID;

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

}; // End of class SbeRetryHandler

}  // End of namespace SBEIO
#endif
