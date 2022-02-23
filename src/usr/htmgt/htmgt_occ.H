/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.H $                                   */
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

#ifndef HTMGT_OCC_H
#define HTMGT_OCC_H

#include <stdint.h>
#include <vector>


namespace HTMGT
{

    const uint8_t  MASTER_OCC = 0xFF;

    const uint32_t OCC_POLL_DATA_MIN_SIZE = 40;

    const uint16_t OCC_COMM_INIT_COMPLETE = 0x0EFF;

    const uint16_t OCC_INIT_FAILURE = 0xE000;

    const uint16_t OCC_TRACE_BUFFER_SIZE = 0x2000;

    enum occStateId
    {
        OCC_STATE_NO_CHANGE                = 0x00,
        OCC_STATE_STANDBY                  = 0x01,
        OCC_STATE_OBSERVATION              = 0x02,
        OCC_STATE_ACTIVE                   = 0x03,
        OCC_STATE_SAFE                     = 0x04,
        OCC_STATE_CHARACTERIZATION         = 0x05,
        // the following states are internal to TMGT
        OCC_STATE_RESET                    = 0x85,
        OCC_STATE_IN_TRANSITION            = 0x87,
        OCC_STATE_LOADING                  = 0x88,
        OCC_STATE_UNKNOWN                  = 0x89,
    };

    enum occRole
    {
        OCC_ROLE_SLAVE          = 0x00,
        OCC_ROLE_MASTER         = 0x01,
        OCC_ROLE_BACKUP_MASTER  = 0x02,
        OCC_ROLE_FIR_MASTER     = 0x80
    };

    enum
    {
        OCC_RESET_COUNT_THRESHOLD   = 3,
        WOF_RESET_COUNT_THRESHOLD   = 3,
    };

    enum occResetReason
    {
        OCC_RESET_REASON_NONE              = 0x00,
        OCC_RESET_REASON_CRIT_FAILURE      = 0x01,
        OCC_RESET_REASON_PWR_ON_FAIL       = 0x02,
        OCC_RESET_REASON_ERROR             = 0x03,
        OCC_RESET_REASON_POWER_FAULT       = 0x04,
        OCC_RESET_REASON_DIFF_OCC          = 0x05,
        OCC_RESET_REASON_OCC_REQUEST       = 0x06,
        OCC_RESET_REASON_OCC_AFO           = 0x07,
        OCC_RESET_REASON_CODE_UPDATE       = 0x08,
        OCC_RESET_REASON_OCC_IN_DIFF_NODE  = 0x09,
        OCC_RESET_REASON_EXTERNAL_REQUEST  = 0x0A,
        OCC_RESET_REASON_ATTR_CHANGE       = 0x0B,
        OCC_RESET_REASON_WOF_RESET         = 0x0C,
        OCC_RESET_REASON_CHECKPOINT_FAIL   = 0x0D,
        OCC_RESET_REASON_CANCEL_CODE_UPDATE= 0x0E,
        OCC_RESET_REASON_POWER_OFF         = 0xFF,
    };

    enum powerMode
    {
        POWERMODE_UNKNOWN           = 0x00, // Not set yet
        POWERMODE_DISABLE           = 0x01, // Disabled Mode
        POWERMODE_SFP               = 0x03, // Static Frequency Point
        POWERMODE_SAFE              = 0x04, // -- not settable mode --
        POWERMODE_POWER_SAVE        = 0x05, // Static Power Save
        POWERMODE_FMAX              = 0x09, // Maximum Frequency
        POWERMODE_DYNAMIC_PERF      = 0x0A, // Dynamic Performace
        POWERMODE_FFO               = 0x0B, // Fixed Frequency Override
        POWERMODE_MAX_PERF          = 0x0C, // Maximum Performance
        POWERMODE_INVALID           = 0xFF  // NOT A VALID MODE
    };

#define IS_VALID_MODE(mode) ((mode == POWERMODE_DISABLE) || \
                             (mode == POWERMODE_SFP) || \
                             (mode == POWERMODE_POWER_SAVE) || \
                             (mode == POWERMODE_FMAX) || \
                             (mode == POWERMODE_DYNAMIC_PERF) || \
                             (mode == POWERMODE_FFO) || \
                             (mode == POWERMODE_MAX_PERF))

    // OCC Callout Structure
    struct occErrlCallout
    {
        uint64_t    calloutValue;
        uint8_t     type;
        uint8_t     priority;
        uint8_t     reserved[6];
    } __attribute__ ((__packed__));
    typedef struct occErrlCallout occErrlCallout_t;


    /**
     *  @class Occ
     *
     *  @brief OCC data class
     *
     *  @par Detailed Description:
     *      Provides configuration data for a specific OCC.
     *      Data will be saved during IPL so it can be used
     *      at runtime.
     */
    class Occ
    {
        friend class OccManager;
        friend class OccCmd;

        public:
            /**
             * @brief Constructor
             *
             * @param[in] i_instance       OCC instance number
             * @param[in] i_masterCapable  Is OCC capable of being master
             * @param[in] i_homer          Virtual address of HOMER
             * @param[in] i_target         OCC target pointer
             * @param[in] i_role           The role of this OCC
             */
            Occ(const uint8_t   i_instance,
                const bool      i_masterCapable,
                uint8_t       * i_homer,
                TARGETING::TargetHandle_t i_target,
                const occRole   i_role);


            /**
             * @brief Destructor
             */
            ~Occ();


            /**
             * @brief Return the instance nubmer
             *
             * @return instance number for this OCC
             */
            uint8_t getInstance() const { return iv_instance; };


            /**
             * @brief Return pointer to the last poll response
             *
             * @param[out] o_pollRspPtr  pointer to last poll rsp data
             *
             * @return true if data is valid, else false
             */
            bool getLastPollRsp(const uint8_t * & o_pollRspPtr)
            {
                o_pollRspPtr = iv_lastPollResponse;
                return iv_lastPollValid;
            };


            /**
             * @brief Return pointer OCC target
             *
             * @return pointer to OCC target (not processor target)
             */
            TARGETING::TargetHandle_t getTarget() const { return iv_target; };


            /**
             * @brief Poll for Errors
             *
             * @param[in]  i_flushAllErrors:
             *      If set to true, HTMGT will send poll cmds
             *      to the OCC as long as the OCC continues
             *      to report errors.  If false, only one
             *      poll will be sent.
             *
             * @return NULL on success, else error handle
             */
            errlHndl_t pollForErrors(const bool i_flushAllErrors = false);


            /**
             * @brief Return true if the specified status bit was set in
             *        the last poll response
             *
             * @param[in]  i_statusBit  Bit(s) to check in the poll response
             *
             * @return true if the bit(s) are set, else false
             */
            bool statusBitSet(const uint8_t i_statusBit);


            /**
             * @brief Set the state of the OCC.
             *        This is only allowed on the master OCC
             *
             * @param[in]  i_state  Desired OCC state
             *
             * @return NULL on success, or error handle on failure
             */
            errlHndl_t setState(const occStateId i_state);


            /**
             * @brief Return OCC role
             *
             * @return role of this OCC
             */
            occRole getRole() { return iv_role; };


            /**
             * @brief Return OCC state
             *
             * @return state of this OCC
             */
            occStateId getState() { return iv_state; };


            /**
             * @brief Return power mode
             *
             * @return power mode of this OCC
             */
            powerMode getMode() { return iv_mode; };


            /**
             * @brief Prepare this OCC for reset
             * @return return true if at threshold otherwise false
             */
            bool resetPrep();


            /**
             * @brief Set BMC OCC enabled sensor state
             * @param i_enabled: true - OCC enabled
             *                   false - OCC disabled
             * @param i_safe:    true if system is in safe mode
             *
             * @return error log on error
             */
            errlHndl_t bmcSensor(const bool i_enabled, const bool i_safe = false);


            /**
             * @brief Set failed state
             * @param[in] failed state
             */
            void failed(bool i_state) { iv_failed = i_state; }


            /**
             * @brief Determine if OCC needs to be reset
             *
             * @return true if this OCC needs to be reset
             */
            bool needsReset() { return iv_needsReset; }


            /**
             * @brief Determine if OCC needs to be reset due to WOF
             *
             * @return true if this OCC needs to be reset
             */
            bool needsWofReset() { return iv_needsWofReset; }


            /**
             * @brief Returns the number of times a WOF reset has occured
             *
             * @return Number of WOF resets for this OCC
             */
            uint8_t wofResetCount() const { return iv_wofResetCount; }


            /**
             * @brief Returns a bit vector representing aggregate WOF
             *        resets reasons
             *
             * @return WOF Reset reason bit vector
             */
            uint32_t getWofResetReasons() { return iv_wofResetReasons; }

            /**
             * @brief Return OCCs present bits
             *
             * @return bitmask representing this OCC position
             */
            uint8_t getPresentBits() { return iv_occsPresent; };


            /**
             * @brief Update OCCs present bits in the master OCC
             *
             * @note Should only be called for Maseter OCC.  This is
             *       used to ensure the master can see all Slave OCCs
             *       and that no two slaves have same chip id.
             *
             * @param[in]  i_slavePresent  Bitmask for slave OCC to add
             */
            void updateOccPresentBits(uint8_t i_slavePresent);


            /**
             * @brief Add channel 1 (circular buffer) SCOM data to elog
             *
             * @param[in,out]  i_err  Error log to add data to
             */
            void collectCheckpointScomData(errlHndl_t i_err);


            /**
             * @brief Add OCC trace buffers to given error log (ERR, IMP, INF)
             *
             * @param[in,out] - the error log handle to add user data for
             */
            void addOccTrace( errlHndl_t & io_errl );


            /**
             * @brief Set the HOMER address for this OCC (required for sending commands)
             *
             * @param[in] - the virtual address of HOMER
             */
            void setHomerAddr(const uint64_t i_homer_vaddress);


            /**
             * @brief Invalidate and zero the HOMER address for this OCC
             */
            void invalidateHomer();


            /**
             * @brief Set the mode of the OCC.
             *        This is only allowed on the master OCC
             *
             * @param[in]  i_mode   Desired power mode
             * @param[in]  i_freq   Frequency for FFO or SFP modes
             *
             * @return NULL on success, or error handle on failure
             */
            errlHndl_t setMode(const uint8_t i_mode,
                               const uint16_t i_freq = 0);


        private:   // functions

            /**
             * @brief Process an OCC poll response
             *
             * @param[in] i_pollResponse      pointer to the response
             * @param[in] i_pollResponseSize  length of the poll response
             */
            void pollRspHandler(const uint8_t * i_pollResponse,
                                const uint16_t i_pollResponseSize);


            /**
             * @brief Process elog entry from OCC poll response.
             *        Collect, Commit and Clear error log from the OCC.
             *
             * @param[in] i_id       OCC elog id to retrieve
             * @param[in] i_address  SRAM address for elog entry
             * @param[in] i_length   size of the elog entry
             * @param[in] i_source   OCC Error Log Source (405, PGPE, etc)
             */
            void occProcessElog(const uint8_t  i_id,
                                const uint32_t i_address,
                                const uint16_t i_length,
                                const uint8_t  i_source);


            /**
             * @brief Determine what actions are required for elog
             *
             * @param[in]     i_actions        Action flags requested by OCC
             * @param[in]     i_src            SRC being reported by OCC
             * @param[in]     i_data           Additional data used when
             *                                 processing actions
             * @param[in,out] io_errlSeverity  Severity to use for elog
             * @param[out]    o_call_home      True if info error should be
             *                                 reported to BMC
             */
            void elogProcessActions(const uint8_t  i_actions,
                                    const uint32_t i_src,
                                    const uint32_t i_data,
                                    ERRORLOG::errlSeverity_t & io_errlSeverity,
                                    bool         & o_call_home);


            /**
             * @brief Add specified callout to the error log
             *
             * @param[in,out] io_errlHndl     elog to add callout
             * @param[in]     i_priority      priority for callout
             * @param[in]     i_callout       callout from OCC
             * @param[in,out] io_numCallouts  number of callouts in elog,
             *                                incremented if new callout added
             * */
            bool elogAddCallout(errlHndl_t &               io_errlHndl,
                                HWAS::callOutPriority    & i_priority,
                                const occErrlCallout_t     i_callout,
                                uint8_t &                  io_callout_num);


            /**
             * @brief Update the GPU presence sensors in the system
             */
            void updateGpuPresence();


        protected:
            // Instance number of this OCC: 0 = first physical OCC
            uint8_t         iv_instance;
            // true if this OCC is capable of Master role (wired to APSS)
            bool            iv_masterCapable;
            // Role of this OCC
            occRole         iv_role;
            // State of this OCC
            occStateId      iv_state;
            // Power mode of this OCC
            powerMode       iv_mode;
            // true if communication to this OCC has been established
            bool            iv_commEstablished;
            // true if OCC needs to be reset
            bool            iv_needsReset;
            // true if OCC needs to be reset due to WOF
            bool            iv_needsWofReset;
            // WOF reset count
            uint8_t         iv_wofResetCount;
            // WOF reset reason. Aggregate across all WOF resets until cleared.
            uint32_t        iv_wofResetReasons;
            // true if OCC failed
            bool            iv_failed;
            // Sequence number of last/current OCC command
            uint8_t         iv_seqNumber;
            // HOMER base address
            uint8_t *       iv_homer;
            // HOMER address valid?
            bool            iv_homerValid;
            // OCC target
            TARGETING::TargetHandle_t iv_target;
            // Last poll response (excluding sensor data)
            uint8_t         iv_lastPollResponse[OCC_POLL_DATA_MIN_SIZE];
            // true if lastPollResponse contains valid data
            bool            iv_lastPollValid;
            // expected occsPresent byte in POLL response
            uint8_t         iv_occsPresent;
            // GPU configuration from poll response data
            uint8_t         iv_gpuCfg;

            occResetReason  iv_resetReason;

            // Value of last exception committed (to prevent duplicates)
            uint8_t         iv_exceptionLogged;

            /**
             * @brief Clear flags after OCC has been reset
             */
            void postResetClear();


        private:
            // Reset count
            uint8_t         iv_resetCount;
            // Version of data stored (0 = not written)
            uint8_t         iv_version;
    };


} // end namespace
#endif
