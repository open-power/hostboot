/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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


    enum occStateId
    {
        OCC_STATE_NO_CHANGE                = 0x00,
        OCC_STATE_STANDBY                  = 0x01,
        OCC_STATE_OBSERVATION              = 0x02,
        OCC_STATE_ACTIVE                   = 0x03,
        OCC_STATE_SAFE                     = 0x04,
        OCC_STATE_RESET                    = 0x05,
        OCC_STATE_IN_TRANSITION            = 0x07,
        OCC_STATE_LOADING                  = 0x08,
        OCC_STATE_UNKNOWN                  = 0x09,
    };

    enum occRole
    {
        OCC_ROLE_SLAVE          = 0x00,
        OCC_ROLE_MASTER         = 0x01,
        OCC_ROLE_BACKUP_MASTER  = 0x02,
        OCC_ROLE_FIR_MASTER     = 0x80
    };



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
            uint8_t getInstance() { return iv_instance; };


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
             * @return pointer to last poll response
             */
            TARGETING::TargetHandle_t getTarget() { return iv_target; };


            /**
             * @brief Process an OCC poll response
             *
             * @param[in] i_pollResponse      pointer to the response
             * @param[in] i_pollResponseSize  length of the poll response
             */
            void pollRspHandler(const uint8_t * i_pollResponse,
                                const uint16_t i_pollResponseSize);


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


        protected:
            // Instance number of this OCC: 0 = first physical OCC
            uint8_t         iv_instance;
            // true if this OCC is capable of Master role (wired to APSS)
            bool            iv_masterCapable;
            // Role of this OCC
            occRole         iv_role;
            // State of this OCC
            occStateId      iv_state;
            // true if communication to this OCC has been established
            bool            iv_commEstablished;
            // true if OCC needs to be reset
            bool            iv_needsReset;
            // true if OCC failed
            bool            iv_failed;
            // Sequence number of last/current OCC command
            uint8_t         iv_seqNumber;
            // HOMER base address
            uint8_t *       iv_homer;
            // OCC target
            TARGETING::TargetHandle_t iv_target;
            // Last poll response (excluding sensor data)
            uint8_t         iv_lastPollResponse[OCC_POLL_DATA_MIN_SIZE];
            // true if lastPollResponse contains valid data
            bool            iv_lastPollValid;


        private:
            // Version of data stored (0 = not written)
            uint8_t         iv_version;

    };



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
             * @brief true if the required config data has been built
             *        This must be persisted across IPL/RT
             *        TODO: RTC 115296
             */
            bool  iv_configDataBuilt;


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
             * @return  Return the number of OCC objects that were created
             */
            static uint32_t buildOccs();


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
             * @brief Set the state of the OCCs.  If i_state is
             *        not specified (NO_CHANGE), OCCs will be set
             *        to the target state (last requested state
             *        or if not requested the default is ACTIVE)
             *
             * @param[in]  i_state  Desired OCC state
             *
             * @return NULL on success, or error handle on failure
             */
            errlHndl_t setOccState(const occStateId i_state =
                                   OCC_STATE_NO_CHANGE);


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



        private:
            Occ *                   iv_occMaster;
            std::vector<Occ*>       iv_occArray;
            occStateId              iv_state;
            occStateId              iv_targetState;

            /* See buildOccs() above */
            uint32_t _buildOccs();


            /* See getNumOccs() above */
            uint8_t _getNumOccs() { return iv_occArray.size(); };


            /* See getOccArray() above */
            std::vector<Occ*> _getOccArray() { return iv_occArray; };


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


            /* See setOccState() above */
            errlHndl_t _setOccState(const occStateId i_state);

    };

    typedef Singleton<OccManager> occMgr;

} // end namespace
#endif
