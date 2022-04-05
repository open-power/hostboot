/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occmanager.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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

#ifndef HTMGT_OCCMANAGER_H
#define HTMGT_OCCMANAGER_H

#include <stdint.h>
#include <vector>
#include "htmgt_occ.H"


namespace HTMGT
{

    /**
     *  @class OccManager
     *
     *  @brief System / Node class
     *
     *  @par Detailed Description:
     *      Manages all Occ classes and contains data specific to
     *      this system / node.
     */
    class OccManager
    {
        friend class Occ;

        public:
            /**
             * @brief Constructor
             */
            OccManager();


            /**
             * @brief Destructor
             */
            ~OccManager();


            /**
             * @brief Query the functional OCCs and build OCC objects
             *
             * @param[in] i_occStart  true if call is being made after
             *                        OCCs have just been started.
             * @param[in] i_skipComm  true if sendOccPoll should not
             *                        be called
             * @return NULL on success, or error handle on failure
             */
            static errlHndl_t buildOccs(bool i_occStart = false,
                                        bool i_skipComm = false);


            /**
             * @brief Get number of functional OCCs
             *
             * @return number of OCCs
             */
            static uint8_t getNumOccs();


            /**
             * @brief Return array of current OCCs
             *
             * @return vector of OCC objects
             */
            static std::vector<Occ*> getOccArray();


            /**
             * @brief Return pointer to master OCC
             *
             * @return pointer to master OCC
             */
            static Occ * getMasterOcc();


            /**
             * @brief Return pointer to specified OCC
             *
             * @return pointer to specified OCC or NULL if not found
             */
            static Occ * getOcc(const uint8_t i_instance);


            /**
             * @brief Reset the OCCs
             *
             * @param[in] Failing occ target
             * @param[in] i_skipCountIncrement  true will prevent incrementing
             *            the system reset count
             * @param[in] i_skipComm            true will prevent attempts to
             *            communicate with OCC before reset (poll/resetPrep)
             *            Used when exiting safe mode.
             * @param[in] i_reason              reason for the reset
             *            Reason will not be updated for OCC_RESET_REASON_NONE
             * @return Error Log | NULL
             */
            static errlHndl_t resetOccs(TARGETING::Target * i_failedOccTarget,
                                        bool i_skipCountIncrement = false,
                                        bool i_skipComm = false,
                                        enum occResetReason i_reason =
                                        OCC_RESET_REASON_NONE);


            /**
             * @brief Set the state of the OCCs.  If i_state is
             *        not specified (NO_CHANGE), OCCs will be set
             *        to the target state (last requested state
             *        or if not requested the default is ACTIVE)
             *
             * @param[in]  i_state  Desired OCC state
             *
             * @return NULL on success, or error handle on failure
             */
            static errlHndl_t setOccState(const occStateId i_state =
                                          OCC_STATE_NO_CHANGE);


            /**
             * @brief Return the consolidated OCC state
             */
            static occStateId getState();


            /**
             * @brief Get the OCC state that should be used after the OCCs
             *        have been loaded or reset
             *
             * @note Target state will default to ACTIVE, but
             *       can be changed with HTMGT::enableOccActuation()
             *
             * @return target state
             */
            static occStateId getTargetState();



            /**
             * @brief Wait for all of the OCCs to reach their checkpoint
             *        state.  That indicates that the OCCs are ready to
             *        communicate and start handling commands.  This
             *        function will wait up to 10 seconds for all OCCs
             *        before returning to the caller.
             *
             * @return NULL on success, or error handle for the first OCC
             *         that did not reach its checkpoint.  If additional OCCs
             *         do not reach their checkpoint an elog will be committed
             *         for each.
             */
            static errlHndl_t waitForOccCheckpoint();


            /**
             * @brief Send a poll command to one or all OCCs
             *
             * @param[in]  i_flushAllErrors:
             *                 If set to true, HTMGT will send poll cmds
             *                 to each OCC that is selected as long as that OCC
             *                 continues to report errors.  If false, only one
             *                 poll will be send to each OCC.
             * @param[in] i_occTarget: The Selected OCC or NULL for all OCCs
             *
             * @return NULL on success, else error handle
             */
            static errlHndl_t
                sendOccPoll(const bool i_flushAllErrors = false,
                            TARGETING::Target * i_occTarget = NULL);


            /**
             * @brief Save the reason that the system is entering safe mode
             *
             * @param[in]  i_src       SRC which triggered safe mode
             * @param[in]  i_instance  OCC which triggered safe mode
             */
            static void updateSafeModeReason(uint32_t i_src,
                                             uint32_t i_instance);


            /**
             * @brief Return the reason the system entered safe mode
             *
             * @param[out]  o_instance   OCC instance
             *
             * @return     SRC which triggered safe mode
             */
            static uint32_t getSafeModeReason(uint32_t & o_instance);


            /**
             * @brief Check if any OCCs need to be reset
             *
             * @return true if any OCC needs to be reset
             */
            static bool occNeedsReset();

            /**
             * @brief Collect FFDC debug data for HTMGT and OCCs
             *
             * @param[out] o_length Length of data returned in o_data
             * @param[out] o_data   Buffer of 256 bytes where data will
             *                      be copied
             */
            static void getHtmgtData(uint16_t & o_length, uint8_t *o_data);

            /**
             * @brief Collect WOF reset reasons for ALL OCCs
             *
             * @param[out] o_length Length of data returned in o_data
             * @param[out] o_data   Buffer containing all OCCs 32-bit
             *                      WOF reset reason vector preceded by
             *                      their instanceId
             */
            static void getWOFResetReasons(uint16_t & o_length,
                                           uint8_t * o_data);

            /**
             * @brief Update error log with safe mode callouts and set
             *        attribute indicating system is in safe mode.
             *
             * @param[in,out] io_err  Error log to be updated
             * */
            void updateForSafeMode(errlHndl_t & io_err);


            /**
             * @brief Check if any OCC has failed
             *
             * @return true if any OCC has been marked as failed
             */
            static bool occFailed();


            /**
             * @brief Update OCC manager state with consolidated OCC state
             *
             */
            static void syncOccStates();


            /**
             * @brief Clear all OCC reset counts
             *
             * @param[in]  i_periodicClear  When TRUE, the WOF reset counts
             *             will not get cleared if WOF was disabled.
             *
             */
            static void clearResetCounts(const bool i_periodicClear = false);


            /**
             * @brief Validate OCC present value is unique
             *
             */
            static uint8_t validateOccsPresent(const uint8_t i_present,
                                               const uint8_t i_instance);


            /**
             * @brief Query the Mode and functions of the system
             *
             * @param[out] o_length Length of data returned in o_data
             * @param[out] o_data   Buffer containing query structure
             *
             * @return NULL on success, or error handle on failure
             */
            static errlHndl_t queryModeAndFunction(uint16_t & o_length,
                                                   uint8_t *o_data);


            /**
             * @brief Check if the OCCs are running
             *
             * @return true if OCC active sensor has been set/enabled
             */
            static bool occsAreRunning();

            /**
             * @brief Set flag indicating the OCCs status
             *
             * @param[in] i_running set to true if OCCs are running, else false
             */
            static void setOccsAreRunning(const bool i_running);


            /**
             * @brief Check if the OCCs have been started
             *
             * @return true if the OCCs were started, else false
             */
            static bool getOccsStarted();

            /**
             * @brief Set flag indicating if the OCCs were started
             *
             * @param[in] i_started set to true if OCCs were started, else false
             */
            static void setOccsStarted(const bool i_started);

        private:

            typedef std::vector<Occ*> occList_t;

            Occ *                   iv_occMaster;
            occList_t               iv_occArray;
            occStateId              iv_state;
            occStateId              iv_targetState;
            uint8_t                 iv_sysResetCount;
            powerMode               iv_mode;
            uint16_t                iv_freqPoint; // for FFO/SFP
            bool                    iv_occsAreRunning;
            bool                    iv_needsReset;
            bool                    iv_occsStarted;


            /**
             * @brief SRC that caused system to enter safe mode
             */
            static uint32_t         cv_safeReturnCode;

            /**
             * @brief OCC instance that triggered safe mode
             */
            static uint32_t         cv_safeOccInstance;


            /* See buildOccs() above */
            errlHndl_t _buildOccs(bool i_occStart = false,
                                  bool i_skipComm = false);


            /* See getNumOccs() above */
            uint8_t _getNumOccs() { return iv_occArray.size(); };


            /* See getOccArray() above */
            std::vector<Occ*> _getOccArray() { return iv_occArray; };


            /** See getState() above */
            occStateId _getState() { return iv_state; };


            /* See getTargetState() above */
            occStateId _getTargetState() { return iv_targetState; };


            /**
             * @brief Remove all OCC objects
             */
            void _removeAllOccs();


            /**
             * @brief Add a functional OCC to be monitored
             *
             * @param[in] i_instance       OCC instance number
             * @param[in] i_masterCapable  Is OCC capable of being master
             * @param[in] i_homer          Virtual address of HOMER
             * @param[in] i_target         OCC target pointer
             * @param[in] i_role           OCC role
             */
            void  _addOcc(const uint8_t   i_instance,
                          const bool      i_masterCapable,
                          uint8_t       * i_homer,
                          TARGETING::TargetHandle_t i_target);


            /* See getMasterOcc() above */
            Occ * _getMasterOcc() { return iv_occMaster; };


            /* See getOcc() above */
            Occ * _getOcc(const uint8_t i_instance);


            /* See setOccState() above */
            errlHndl_t _setOccState(const occStateId i_state);

            /* See waitForOccCheckpoint() above */
            errlHndl_t _waitForOccCheckpoint();

            /* See resetOccs() above */
            errlHndl_t _resetOccs(TARGETING::Target * i_failedOccTarget,
                                  bool i_skipCountIncrement,
                                  bool i_skipComm,
                                  enum occResetReason i_reason);

            /** See sendOccPoll() above */
            /* @param[in] i_onlyIfEstablished: If true, only send poll if
             *                 communications has already been established
             *                 with that OCC */
            errlHndl_t
                _sendOccPoll(const bool i_flushAllErrors,
                             TARGETING::Target * i_occTarget,
                             const bool i_onlyIfEstablished = false);

            /** See updateSafeModeReason() above */
            void _updateSafeModeReason(uint32_t i_src,
                                       uint32_t i_instance);

            /** See getSafeModeReason() above */
            uint32_t _getSafeModeReason(uint32_t & o_instance);

            /** See occNeedsReset() above */
            bool _occNeedsReset();

            /** See occFailed() above */
            bool _occFailed();

            /** See getHtmgtData() above */
            void _getHtmgtData(uint16_t & o_length, uint8_t *o_data);

            /** See getWOFResetReasons above */
            void _getWOFResetReasons(uint16_t & o_length, uint8_t *o_data);

            /** See syncOccStates() above */
            void _syncOccStates();

            /** See clearResetCounts() above */
            void _clearResetCounts(const bool i_periodicClear);

            /** See validateOccsPresent() above */
            uint8_t _validateOccsPresent(const uint8_t i_present,
                                         const uint8_t i_instance);

            /** See queryModeAndFunction() above */
            errlHndl_t _queryModeAndFunction(uint16_t & o_length, uint8_t *o_data);

            /** See occsAreRunning() above */
            bool _occsAreRunning() { return iv_occsAreRunning; };

            /** See setOccsAreRunning() above */
            void _setOccsAreRunning(const bool i_running)
            { iv_occsAreRunning = i_running; };

            /* See getOccsStarted() above */
            uint8_t _getOccsStarted() { return iv_occsStarted; };

            /** See setOccsStarted() above */
            void _setOccsStarted(const bool i_started)
            { iv_occsStarted = i_started; };
    };

    typedef Singleton<OccManager> occMgr;

} // end namespace
#endif
