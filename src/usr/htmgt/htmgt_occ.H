/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occ.H $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
            const uint8_t getInstance() { return instance; };


            /**
             * @brief Return pointer to the last poll response
             *
             * @return pointer to last poll response
             */
            const uint8_t *getLastPollRsp() { return lastPollResponse; };


            /**
             * @brief Return pointer OCC target
             *
             * @return pointer to last poll response
             */
            TARGETING::TargetHandle_t getTarget() { return target; };


        protected:
            // Instance number of this OCC: 0 = first physical OCC
            uint8_t         instance;
            // true if this OCC is capable of Master role (wired to APSS)
            bool            masterCapable;
            // Role of this OCC
            occRole         role;
            // State of this OCC
            occStateId      state;
            // true if communication to this OCC has been established
            bool            commEstablished;
            // true if OCC needs to be reset
            bool            needsReset;
            // true if OCC failed
            bool            failed;
            // Sequence number of last/current OCC command
            uint8_t         seqNumber;
            // HOMER base address
            uint8_t *       homer;
            // OCC target
            TARGETING::TargetHandle_t target;
            // Last poll response (excluding sensor data)
            uint8_t         lastPollResponse[OCC_POLL_DATA_MIN_SIZE];
            // true if lastPollResponse contains valid data
            bool            lastPollValid;

            // HOM Unit Id of this OCC
             TARGETING::ATTR_HUID_type  huid;


        private:
            // Version of data stored (0 = not written)
            uint8_t         version;

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


        private:
            Occ *                   iv_occMaster;
            std::vector<Occ*>       iv_occArray;
            occStateId              iv_state;

            /* See buildOccs() above */
            uint32_t _buildOccs();


            /* See getNumOccs() above */
            uint8_t _getNumOccs() { return iv_occArray.size(); };


            /* See getOccArray() above */
            std::vector<Occ*> _getOccArray() { return iv_occArray; };


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


    };

    typedef Singleton<OccManager> occMgr;

} // end namespace
#endif
