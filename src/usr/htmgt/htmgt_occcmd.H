/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occcmd.H $                                */
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

#ifndef HTMGT_OCCCMD_H
#define HTMGT_OCCCMD_H

#include "htmgt_utility.H"
#include "htmgt_activate.H"
#include "htmgt_occ.H"

#include <stdint.h>
#include <errl/errlmanager.H>

namespace HTMGT
{

    const uint32_t OCC_CMD_ADDR        = 0x001EE000;
    const uint32_t OCC_RSP_ADDR        = 0x001EF000;
    const uint32_t OCC_MAX_DATA_LENGTH = 0x00001000;
    const uint32_t OCC_RSP_SRAM_ADDR   = 0xFFFF7000;

    // The following header lengths include the 2 byte checksum
    const uint16_t OCC_CMD_HDR_LENGTH = 6;
    const uint16_t OCC_RSP_HDR_LENGTH = 7;

    enum occReturnCodes
    {
        OCC_RC_SUCCESS                  = 0x00,
        OCC_RC_INVALID_COMMAND          = 0x11,
        OCC_RC_INVALID_COMMAND_LENGTH   = 0x12,
        OCC_RC_INVALID_DATA_FIELD       = 0x13,
        OCC_RC_CHECKSUM_FAILURE         = 0x14,
        OCC_RC_INTERNAL_ERROR           = 0x15,
        OCC_RC_PRESENT_STATE_PROHIBITS  = 0x16,

        // 0xE0-EF are reserved for OCC exceptions on command timeouts
        // TMGT should collect all the data in the response as FFDC
        OCC_RC_OCC_EXCEPTION            = 0xE0,
        OCC_RC_OCC_INIT_CHECKPOINT      = 0xE1,
        OCC_RC_OCC_WATCHDOG_TIMEOUT     = 0xE2,
        OCC_RC_OCC_TIMEOUT              = 0xE3,
        OCC_RC_OCC_HW_ERROR             = 0xE4,
        OCC_RC_OCC_EXCEPTION_RESERVED   = 0xEF,

        OCC_COMMAND_IN_PROGRESS         = 0xFF
    };

    enum occCommandType
    {
        OCC_CMD_POLL                    = 0x00,
        OCC_CMD_CLEAR_ERROR_LOG         = 0x12,
        OCC_CMD_SET_STATE               = 0x20,
        OCC_CMD_SETUP_CFG_DATA          = 0x21,
        OCC_CMD_SET_POWER_CAP           = 0x22,
        OCC_CMD_RESET_PREP              = 0x25,
        OCC_CMD_GET_FIELD_DEBUG_DATA    = 0x42,

        OCC_CMD_END_OF_TABLE            = 0xFF
    };

    enum occCheckRspLengthType
    {
        OCC_CHECK_RSP_LENGTH_NONE    = 0x00,
        OCC_CHECK_RSP_LENGTH_EQUALS  = 0x01,
        OCC_CHECK_RSP_LENGTH_GREATER = 0x02,
    };

    enum occCmdTraceEnum
    {
        OCC_TRACE_NEVER          = 0x00,
        OCC_TRACE_EXTENDED       = 0x01,
        OCC_TRACE_CONDITIONAL    = 0x02,
        OCC_TRACE_ALWAYS         = 0x03,
    };

    struct occCommandTable_t
    {
        occCommandType    cmdType;
        uint8_t            supported;
        occCheckRspLengthType checkRspLength;
        uint16_t           rspLength;
        uint32_t           timeout;
        uint16_t           maxBytesRead;
        occCmdTraceEnum   traceCmd;

        bool operator== (const occCommandType i_cmd)
        {
            return (cmdType == i_cmd);
        }
    };

    struct occCommandStruct_t
    {
        uint8_t          sequenceNumber;
        occCommandType   cmdType;
        uint16_t         dataLength;
        uint8_t          cmdData[OCC_MAX_DATA_LENGTH];
        uint16_t         checksum;
    };

    struct occResponseStruct_t
    {
        uint8_t          sequenceNumber;
        occCommandType   cmdType;
        occReturnCodes   returnStatus;
        uint16_t         dataLength;
        uint8_t          rspData[OCC_MAX_DATA_LENGTH];
        uint16_t         checksum;
    };



    /**
     *  @class OccCmd
     *
     *  @brief OCC Command handling class.
     *
     *  @par Detailed Description:
     *      Provides ability to build and send commands to the OCC and
     *      process the responses returned by the OCC.
     */
    class OccCmd
    {
        private:
            bool iv_RetryCmd;
            occCommandStruct_t  iv_OccCmd;
            occResponseStruct_t iv_OccRsp;
            Occ * iv_Occ;

            static const occCommandTable_t cv_occCommandTable[];

            /**
             * @brief Get the index of the specified command in the command
             *        table
             *
             * @param[in] i_cmd  OCC command type
             *
             * @note If command not found/invalid, index to END_OF_TABLE will
             *       be returned and checked by caller
             *
             * @return index into command table
             */
            uint8_t getCmdIndex(const occCommandType i_cmd);

            /**
             * @brief Write the full OCC command into HOMER (memory) including
             *        checksum.
             */
            uint16_t buildOccCmdBuffer();

            /**
             * @brief Verify the status, checksum and length of the OCC
             *        response.
             *
             * @return NULL on success, or errlHndl_t for any failure
             */
            errlHndl_t checkOccResponse();

            /**
             * @brief Parse the OCC response into the object and verify
             *        lengths are valid.
             *
             * @return NULL on success, or errlHndl_t for any failure
             */
            errlHndl_t parseOccResponse();

            /**
             * @brief Create and commit error log from the exception data
             *        in the response buffer.  It is assumed that the OCC
             *        response status is 0xE0-0xEF when called.
             */
            void handleOccException(void);

            /**
             * @brief Send the command to the OCC
             *
             * @return NULL on success, or errlHndl_t for any failure
             */
            errlHndl_t writeOccCmd();

            /**
             * @brief Waits for the OCC response to be received
             *
             * @param[in] i_timeout  max time to wait for response (in seconds)
             *
             * @return true if timeout was reached before good response, or
             *         false if response was received within the timeout
             */
            bool waitForOccRsp(uint32_t i_timeout);


        public:
            /**
             * @brief Constructor
             *
             * @param[in] i_occ  target OCC for the command
             * @param[in] i_cmd  OCC command to send
             * @param[in] i_dataLength  Size of Data buffer (i_data)
             * @param[in] i_data        Data buffer to send with command
             */
            OccCmd(Occ * i_occ,
                   const occCommandType i_cmd,
                   const uint16_t i_dataLength,
                   const uint8_t *i_data);

            /**
             * @brief Destructor
             */
            ~OccCmd();

            /**
             * @brief Send this command to the OCC
             *
             * @return NULL on success, or errlHndl_t for any failure
             */
            errlHndl_t sendOccCmd();

            /**
             * @brief Determine if the command needs to be traced and trace it
             *
             * @return true if the command was traced
             */
            bool traceCommand();

            /**
             * @brief Trace the response
             */
            void traceResponse();

            /**
             * @brief Process the OCC response and determine if a retry
             *        is necessary (iv_retryCmd will be true if required)
             *
             * @param[in,out] io_errlHndl Error handle from sending command
             *                and response error handle if failed
             * @param[in]     i_traceRsp  true if the response should be traced
             */
            void processOccResponse(errlHndl_t & io_errlHndl,
                                    const bool i_traceRsp);
            /**
             * @brief Return the OCC response status from the response buffer
             *
             * @return OCC response status
             */
            occReturnCodes getRspStatus() { return iv_OccRsp.returnStatus; }

            /**
             * @brief Return the data length from the OCC response
             *
             * @return OCC response data length
             */
            uint16_t getRspLength() { return iv_OccRsp.dataLength; }

            /**
             * @brief Return a pointer to the response data and length
             *
             * @param[in,out] rsp_data  pointer to the response data
             *
             * @return OCC response data length
             */
            uint16_t getResponseData(uint8_t* & rsp_data)
            {
                rsp_data = iv_OccRsp.rspData;
                return iv_OccRsp.dataLength;
            }


#ifdef SIMICS_TESTING
            /**
             * @brief Auto-responder for testing in simics
             *
             * @param[in] iOcc  OCC target
             */
            void fakeOccResponse();
#endif

    };



} // end namespace

#endif
