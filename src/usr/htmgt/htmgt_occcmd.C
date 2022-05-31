/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/htmgt/htmgt_occcmd.C $                                */
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

#include <htmgt/htmgt.H>
#include <htmgt/htmgt_reasoncodes.H>
#include "htmgt_occcmd.H"
#include "htmgt_cfgdata.H"
#include "htmgt_poll.H"
#include "htmgt_occmanager.H"

//  Targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>

#include <ecmdDataBufferBase.H>
#include <isteps/pm/occAccess.H>

#include <sys/time.h>
#include <arch/ppc.H>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <stdio.h>
#include <console/consoleif.H>
#include <variable_buffer.H>
#include <fapi2.H>

namespace HTMGT
{
    uint8_t g_cmd = 0;
    uint8_t g_seq = 0;

    const uint8_t OCC_COMM_ESTABLISHED_CHECKPOINT[2] = { 0x0E, 0xFF };

    struct occCircBufferCmd_t
    {
        uint8_t senderId;
        uint8_t commandType;
        uint8_t reserved[6];
    }__attribute__((packed));


    // Note: Read length must be 8 byte aligned (for SRAM reads)
    const uint16_t RD_MAX = (OCC_MAX_DATA_LENGTH - 8);
    const occCommandTable_t OccCmd::cv_occCommandTable[] =
    {
        // Command                   Support  RspCheck
        //   RspLen  Timeout  ReadMax  Tracing
        {OCC_CMD_POLL,                 0xE0,  OCC_CHECK_RSP_LENGTH_GREATER,
            0x0028, TO_20SEC,  0x0017, OCC_TRACE_EXTENDED},
        {OCC_CMD_CLEAR_ERROR_LOG,      0xC0,  OCC_CHECK_RSP_LENGTH_EQUALS,
            0x0000, TO_20SEC,  0x0008, OCC_TRACE_EXTENDED},
        {OCC_CMD_SET_STATE,            0xE0,  OCC_CHECK_RSP_LENGTH_EQUALS,
            0x0000, TO_20SEC,  0x0008, OCC_TRACE_ALWAYS},
        {OCC_CMD_SETUP_CFG_DATA,       0x80,  OCC_CHECK_RSP_LENGTH_EQUALS,
            0x0000, TO_20SEC,  0x0008, OCC_TRACE_CONDITIONAL},
        {OCC_CMD_SET_POWER_CAP,        0x80,  OCC_CHECK_RSP_LENGTH_NONE,
            0x0000, TO_20SEC,  0x0090, OCC_TRACE_EXTENDED},
        {OCC_CMD_RESET_PREP,           0x80,  OCC_CHECK_RSP_LENGTH_GREATER,
            0x0000, TO_20SEC,  0x0190, OCC_TRACE_ALWAYS},
        {OCC_CMD_DEBUG_PASS_THROUGH,   0xF0,  OCC_CHECK_RSP_LENGTH_NONE,
            0x0000, TO_20SEC,  RD_MAX, OCC_TRACE_EXTENDED},
        {OCC_CMD_AME_PASS_THROUGH,     0xF0,  OCC_CHECK_RSP_LENGTH_NONE,
            0x0000, TO_20SEC,  RD_MAX, OCC_TRACE_EXTENDED},
        {OCC_CMD_GET_FIELD_DEBUG_DATA, 0x80,  OCC_CHECK_RSP_LENGTH_GREATER,
            0x0001, TO_20SEC,  RD_MAX, OCC_TRACE_NEVER},
        {OCC_CMD_MFG_TEST,             0xF0,  OCC_CHECK_RSP_LENGTH_NONE,
            0x0001, TO_20SEC,  RD_MAX, OCC_TRACE_ALWAYS},

        // If command not found, use this last entry
        {OCC_CMD_END_OF_TABLE,         0xE0,  OCC_CHECK_RSP_LENGTH_NONE,
            0x0000, TO_20SEC,  RD_MAX, OCC_TRACE_NEVER}
    };


#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
    // Dump header information and set of binary data to the console.
    // NOTE: Data is dumped in groups of 16 bytes. If i_len is not a
    // multiple of 16, additional data data will be dumped.
    void dumpToConsole(const char * i_header,
                       const uint8_t * i_data,
                       uint16_t i_len)
    {
#ifndef __HOSTBOOT_RUNTIME
        if (i_header[0] != '\0')
        {
            TMGT_CONSOLE("%s", i_header);
        }
        uint16_t index = 0;
        while (index < i_len)
        {
            TMGT_CONSOLE("%04X:  %08X %08X %08X %08X",
                         index,
                         UINT32_GET(&i_data[index]),
                         UINT32_GET(&i_data[index+4]),
                         UINT32_GET(&i_data[index+8]),
                         UINT32_GET(&i_data[index+12]));
            index += 16;
        }
        CONSOLE::flush();
#endif
    }
#endif


    /**
     * @brief Get the index of the specified command in the command table
     *
     * @param[in] i_cmd  OCC command type
     *
     * @note If command not found/invalid, index to END_OF_TABLE will
     *       be returned and checked by caller
     *
     * @return index into command table
     */
    uint8_t OccCmd::getCmdIndex(const occCommandType i_cmd)
    {
        uint8_t l_index = 0;

        while ((cv_occCommandTable[l_index].cmdType != OCC_CMD_END_OF_TABLE) &&
               (cv_occCommandTable[l_index].cmdType != i_cmd))
        {
            l_index++;
        }

        if (cv_occCommandTable[l_index].cmdType == OCC_CMD_END_OF_TABLE)
        {
            TMGT_ERR("getCmdIndex: Invalid cmd (0x%02X) specified", i_cmd);
        }

        return l_index;
    }



    /**
     * @brief Convert OCC response status to a string
     *
     * @param[in] i_status OCC response status
     *
     * @return text string describing status
     */
    const char *rsp_status_string(const occReturnCodes i_status)
    {
        const uint8_t STATUS_STRING_COUNT = 11;
        struct string_data_t
        {
            uint8_t       str_num;
            const char    *str_data;
        };
        const static struct string_data_t L_status_string[STATUS_STRING_COUNT]=
        {
            {OCC_RC_SUCCESS, "SUCCESS"},
            {OCC_RC_INVALID_COMMAND, "INVALID_COMMAND"},
            {OCC_RC_INVALID_COMMAND_LENGTH, "INVALID_COMMAND_LENGTH"},
            {OCC_RC_INVALID_DATA_FIELD, "INVALID_DATA_FIELD"},
            {OCC_RC_CHECKSUM_FAILURE, "CHECKSUM_FAILURE"},
            {OCC_RC_INTERNAL_ERROR, "INTERNAL_ERROR"},
            {OCC_RC_PRESENT_STATE_PROHIBITS, "PRESENT_STATE_PROHIBITS"},
            {OCC_RC_OCC_EXCEPTION, "OCC_EXCEPTION"},
            {OCC_RC_OCC_INIT_CHECKPOINT, "OCC_INIT_FAILURE"},
            {OCC_COMMAND_IN_PROGRESS, "IN_PROGRESS"},
            {OCC_COMMAND_IN_PROGRESS, "UNKNOWN"}
        };

        uint8_t l_idx = 0;
        for (l_idx=0; l_idx < STATUS_STRING_COUNT; l_idx++)
        {
            if (i_status == L_status_string[l_idx].str_num)
            {
                // Return Code found
                break;
            }
        }

        if (STATUS_STRING_COUNT == l_idx)
        {
            // Set index to last entry record
            l_idx = STATUS_STRING_COUNT - 1;
        }

        return L_status_string[l_idx].str_data;
    }



    // Constructor for OccCmd
    OccCmd::OccCmd(Occ * i_occ,
                   const occCommandType i_cmd,
                   const uint16_t i_cmdDataLength,
                   const uint8_t *i_data)
        :iv_RetryCmd(false),
        iv_OccCmd(),
        iv_OccRsp(),
        iv_Occ(i_occ)
    {
        iv_OccCmd.cmdType = i_cmd;
        iv_OccCmd.dataLength = i_cmdDataLength;
        if (0 != i_cmdDataLength)
        {
            if (i_cmdDataLength > OCC_MAX_DATA_LENGTH)
            {
                TMGT_ERR("OccCmd: truncating data length (0x%04X)",
                         i_cmdDataLength);
                iv_OccCmd.dataLength = OCC_MAX_DATA_LENGTH;
            }
            memcpy(iv_OccCmd.cmdData, i_data, iv_OccCmd.dataLength);
        }

    } // end OccCmd()



    // Destructor for OccCmd
    OccCmd::~OccCmd()
    {
    }


    // Determine if command needs to be traced and if so, trace it.
    bool OccCmd::traceCommand()
    {
        bool o_cmdWasTraced = true;
        const uint8_t l_instance = iv_Occ->iv_instance;

        const uint8_t l_cmd_index = getCmdIndex(iv_OccCmd.cmdType);
        switch(cv_occCommandTable[l_cmd_index].traceCmd)
        {
            case OCC_TRACE_ALWAYS:
                // Always trace command
                break;

            case OCC_TRACE_EXTENDED:
                // Trace command when tracing enabled
                o_cmdWasTraced = (G_debug_trace & DEBUG_TRACE_OCCCMD);
                break;

            case OCC_TRACE_NEVER:
                // Never trace these cmds (unless full tracing enabled)
                o_cmdWasTraced = (G_debug_trace&DEBUG_TRACE_OCCCMD_FULL);
                break;

            default:
                // Do nothing
                break;
        }

        if (o_cmdWasTraced)
        {
            // Trace command (and up to 16 bytes of data)
            if ((OCC_CMD_SETUP_CFG_DATA == iv_OccCmd.cmdType) &&
                (iv_OccCmd.dataLength > 0))
            {
                // Trace config format and first parms since TRACFBIN does
                // not always work
                TMGT_INF("Send OCC%d cmd=0x%02X (%s), length=0x%04X,"
                         " data=0x%08X...",
                         l_instance, iv_OccCmd.cmdType,
                         command_string(iv_OccCmd.cmdType),
                         iv_OccCmd.dataLength,
                         UINT32_GET(iv_OccCmd.cmdData));
            }
            else
            {
                TMGT_INF("Send OCC%d cmd=0x%02X (%s), length=0x%04X",
                         l_instance, iv_OccCmd.cmdType,
                         command_string(iv_OccCmd.cmdType),
                         iv_OccCmd.dataLength);
            }
            if (iv_OccCmd.dataLength > 0)
            {
                TMGT_BIN("cmd data (up to 16 bytes)", iv_OccCmd.cmdData,
                         std::min(iv_OccCmd.dataLength,(uint16_t)16));
            }
        }

        return o_cmdWasTraced;

    } // end OccCmd::traceCommand()


    void OccCmd::traceResponse()
    {
        char l_rsp_status_string[64] = "";
        const uint8_t l_instance = iv_Occ->iv_instance;

        if (iv_OccRsp.returnStatus != OCC_RC_SUCCESS)
        {
            sprintf(l_rsp_status_string, " (%s)",
                    rsp_status_string(iv_OccRsp.returnStatus));
        }

        TMGT_INF("OCC%d rsp status=0x%02X%s, length=0x%04X",
                 l_instance, iv_OccRsp.returnStatus,
                 l_rsp_status_string, iv_OccRsp.dataLength);
        if (iv_OccRsp.dataLength > 0)
        {
            TMGT_BIN("rsp data: (up to 16 bytes)", iv_OccRsp.rspData,
                     std::min(iv_OccRsp.dataLength,(uint16_t)16));
        }
    }


    // Process the OCC response and determine if retry is required
    void OccCmd::processOccResponse(errlHndl_t & io_errlHndl,
                                    const bool i_traceRsp)
    {
        const uint8_t l_instance = iv_Occ->iv_instance;
        const bool alreadyRetriedOnce = iv_RetryCmd;
        iv_RetryCmd = false;

        if (i_traceRsp)
        {
            traceResponse();
        }

        if (io_errlHndl == NULL)
        {
            // A response was received
            io_errlHndl = checkOccResponse();
            if (io_errlHndl != NULL)
            {
                // Error checking on response failed...
                if ((alreadyRetriedOnce == false) &&
                    (OCC_RC_PRESENT_STATE_PROHIBITS != iv_OccRsp.returnStatus))
                {
                    // A retry has not been sent yet, commit the error
                    // and retry.
                    ERRORLOG::errlCommit(io_errlHndl, HTMGT_COMP_ID);
                    iv_RetryCmd = true;
                    // Clear/init the response data structure
                    memset(&iv_OccRsp, 0x00, sizeof(occResponseStruct_t));
                    iv_OccRsp.returnStatus = OCC_COMMAND_IN_PROGRESS;
                }
                else
                {
                    // A retry has already been sent...
                    TMGT_ERR("OCC%d cmd 0x%02X failed retry, status=0x%02X,"
                             " returned length=0x%04X",
                             l_instance, iv_OccCmd.cmdType,
                             iv_OccRsp.returnStatus, iv_OccRsp.dataLength);
                    if (iv_OccRsp.dataLength)
                    {
                        TMGT_BIN("OCC rsp data:", iv_OccRsp.rspData,
                                 iv_OccRsp.dataLength);
                    }

                    if ((OCC_RC_CHECKSUM_FAILURE == iv_OccRsp.returnStatus) ||
                        (OCC_RC_INTERNAL_ERROR == iv_OccRsp.returnStatus) )
                    {
                        // failed due to rsp data checksum failure... reset OCC
                        TMGT_ERR("processOccResponse: OCC%d response had"
                                 " checksum or internal error,"
                                 " need to RESET OCC", l_instance);
                        iv_Occ->iv_needsReset = true;
                        // Mark OCC as failed
                        iv_Occ->iv_failed = true;
                        // Update safe mode reason (if not already set) in case they dont recover
                        OccManager::updateSafeModeReason(io_errlHndl->reasonCode(), l_instance);
                    }
                }
            }
            // else response was good
        }
        else
        {
            // Send of OCC command failed
            if ( /*(TMGT_RC_SEND_FAIL == io_errlHndl->reasonCode()) &&*/
                 (alreadyRetriedOnce == true) )
            {
                // failed due to send/receive problem and retry has been
                // sent... reset OCC
                TMGT_ERR("Sending OCC%d command failed twice, need to RESET"
                         " OCC", l_instance);
                iv_Occ->iv_needsReset = true;
                // Unable to communicate with OCC, mark as failed
                iv_Occ->iv_failed = true;
                // Update safe mode reason (if not already set) in case they dont recover
                OccManager::updateSafeModeReason(io_errlHndl->reasonCode(), l_instance);
            }
            else
            {
                if ((alreadyRetriedOnce == false) &&
                     (OCC_RC_PRESENT_STATE_PROHIBITS != iv_OccRsp.returnStatus))
                {
                    // A retry has not been sent yet, commit the error
                    // and retry.
                    ERRORLOG::errlCommit(io_errlHndl, HTMGT_COMP_ID);
                    iv_RetryCmd = true;

                    // Clear/init the response data structure
                    memset(&iv_OccRsp, 0x00, sizeof(occResponseStruct_t));
                    iv_OccRsp.returnStatus = OCC_COMMAND_IN_PROGRESS;
                }
                else
                {
                    // A retry has already been sent...
                    TMGT_ERR("OCC%d cmd 0x%02X failed.  status=0x%02X,"
                             " returned length=0x%04X",
                             l_instance, iv_OccCmd.cmdType,
                             iv_OccRsp.returnStatus, iv_OccRsp.dataLength);
                    if (iv_OccRsp.dataLength)
                    {
                        TMGT_BIN("response data:", iv_OccRsp.rspData,
                                 iv_OccRsp.dataLength);
                    }

                    if ((OCC_RC_CHECKSUM_FAILURE == iv_OccRsp.returnStatus) ||
                        (OCC_RC_INTERNAL_ERROR == iv_OccRsp.returnStatus) )
                    {
                        // failed due to rsp data checksum failure... reset OCC
                        TMGT_ERR("processOccResponse: OCC%d response had"
                                 " checksum or internal error,"
                                 " need to RESET OCC", l_instance);
                        iv_Occ->iv_needsReset = true;
                        // Unable to communicate with OCC, mark as failed
                        iv_Occ->iv_failed = true;
                        // Update safe mode reason (if not already set) in case they dont recover
                        OccManager::updateSafeModeReason(io_errlHndl->reasonCode(), l_instance);
                    }
                }
            }
        }
    } // end OccCmd::processOccResponse()


    // Send command to OCC
    errlHndl_t OccCmd::sendOccCmd()
    {
        errlHndl_t l_errlHndl = NULL;
        iv_OccRsp.returnStatus = OCC_COMMAND_IN_PROGRESS;

        if (iv_Occ != NULL)
        {
            const occStateId l_occState = iv_Occ->iv_state;
            const bool cmdTraced = traceCommand();

            // Only allow commands if comm has been established,
            // or this is a poll command
            const bool l_commEstablished = iv_Occ->iv_commEstablished;
            if ( (true == l_commEstablished) ||
                 ((false == l_commEstablished) &&
                  (OCC_CMD_POLL == iv_OccCmd.cmdType)) )
            {
                if (0 == iv_Occ->iv_exceptionLogged)
                {
                    iv_RetryCmd = false;
                    do
                    {
                        // Send the command and receive the response
                        l_errlHndl = writeOccCmd();

                        // process response if OCC did not hit an exception
                        if (0 == iv_Occ->iv_exceptionLogged)
                        {
                            processOccResponse(l_errlHndl, cmdTraced);
                        }

                        // skip retry if an exception was logged
                    } while ((iv_RetryCmd) &&
                             (0 == iv_Occ->iv_exceptionLogged));
                }
                else
                {
                    // OCC has already logged an exception, no need to send
                    TMGT_ERR("Skipping 0x%02X cmd since OCC has already "
                             "logged an exception 0x%04X",
                             iv_OccCmd.cmdType, iv_Occ->iv_exceptionLogged);
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_OCC_EXCEPTION
                     * @moduleid HTMGT_MOD_SEND_OCC_CMD
                     * @userdata1 OCC command
                     * @userdata2 comm established
                     * @userdata3 OCC state
                     * @userdata4 exception
                     * @devdesc Unable to send cmd to OCC exception
                     */
                    bldErrLog(l_errlHndl, HTMGT_MOD_SEND_OCC_CMD,
                              HTMGT_RC_OCC_EXCEPTION,
                              iv_OccCmd.cmdType, l_commEstablished,
                              l_occState, iv_Occ->iv_exceptionLogged,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
            else
            {
                // Ignore failure on GET_FIELD_DEBUG_DATA
                if (OCC_CMD_GET_FIELD_DEBUG_DATA != iv_OccCmd.cmdType)
                {
                    // Comm not established or command not supported
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_OCC_UNAVAILABLE
                     * @moduleid HTMGT_MOD_SEND_OCC_CMD
                     * @userdata1 OCC command
                     * @userdata2 comm established
                     * @userdata3 OCC state
                     * @userdata4 1
                     * @devdesc OCC comm not established or command is not
                     *          supported
                     */
                    bldErrLog(l_errlHndl, HTMGT_MOD_SEND_OCC_CMD,
                              HTMGT_RC_OCC_UNAVAILABLE,
                              iv_OccCmd.cmdType, l_commEstablished,
                              l_occState, 1,
                              ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
        }
        else
        {
            TMGT_ERR("sendOccCmd: ignoring command 0x%02X due to NULL OCC",
                     iv_OccCmd.cmdType);
            /*@
             * @errortype
             * @reasoncode HTMGT_RC_INTERNAL_ERROR
             * @moduleid HTMGT_MOD_SEND_OCC_CMD
             * @userdata1 OCC command type
             * @devdesc OCC is not valid
             */
            bldErrLog(l_errlHndl, HTMGT_MOD_SEND_OCC_CMD,
                      HTMGT_RC_INTERNAL_ERROR,
                      iv_OccCmd.cmdType, 0, 0, 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        if (l_errlHndl)
        {
            // Add OCC command data to user details
            if (iv_OccCmd.dataLength > 0)
            {
                l_errlHndl->addFFDC(HTMGT_COMP_ID,
                                    iv_OccCmd.cmdData,
                                    iv_OccCmd.dataLength,
                                    1,  // version
                                    SUBSEC_OCC_CMD_DATA);
            }
        }

        return l_errlHndl;

    } // end OccCmd::sendOccCmd()



#ifdef SIMICS_TESTING
    // Auto-responder for testing in simics
    void OccCmd::fakeOccResponse()
    {
        static uint8_t L_state = 0;
        static uint8_t L_prior_status = 0x00;
        static uint8_t L_prior_sequence = 0x00;
        assert(iv_Occ->iv_homerValid == true, "fakeOccResponse: HOMER is invalid");
        assert(iv_Occ->iv_homer != nullptr, "fakeOccResponse: HOMER is null");
        uint8_t * const rspBuffer = iv_Occ->iv_homer + OCC_RSP_ADDR;

        if (0 == L_state)
        {
            if (G_debug_data != 0x02)
            {
                TMGT_INF("fakeOccResponse: status=0xFF");
                rspBuffer[0] = g_seq;
                rspBuffer[1] = g_cmd;
                rspBuffer[2] = 0xFF; // status
                ++L_state;

                if (G_debug_data == 0x01)
                {
                    L_state = 0; // force command timeout
                }
            }
        }
        else
        {
            if (G_debug_data != 0xE0)
            {
                TMGT_INF("fakeOccResponse: status=0x00");
                rspBuffer[2] = 0x00; // status

                // Add full reseponse data
                const uint16_t dataLength = OCC_POLL_DATA_MIN_SIZE;
                const occPollRspStruct_t poll_rsp_data = {
                    // Status 0x8B = Master, AttnEnabled, ObsReady, ActReady
                    0x8B,
                    0,          // extStatus;
                    0x01,       // occsPresent;
                    0,          // requestedCfg;
                    0,          // state;
                    0,          // mode
                    0,          // IPSStatus
                    0,          // errorId;
                    0x00000000, // errorAddress;
                    0x0000,     // errorLength;
                    0x0000,     // reserved2;
                    { "occ825_simicsFF" }, // codeLevel[16];
                    { 'S', 'E', 'N', 'S', 'O', 'R' }, // sensor[6];
                    0,          // numBlocks;
                    0x01        // version;
                    //uint8_t   sensorData[4049];
                };
                UINT16_PUT(&rspBuffer[3], dataLength);
                TMGT_INF("fakeOccResponse: data length=%d", dataLength);
                if (dataLength)
                {
                    memcpy(&rspBuffer[5], &poll_rsp_data, dataLength);
                }
                uint16_t checksum = 0;
                const uint16_t checksumOffset = OCC_RSP_HDR_LENGTH +
                    dataLength - 2;
                for (uint16_t l_index = 0; l_index < checksumOffset; l_index++)
                {
                    checksum += rspBuffer[l_index];
                }
                if (G_debug_data == 0x03)
                {
                    TMGT_INF("fakeOccResponse: corrupting checksum"
                             " (good=0x%04X)", checksum);
                    checksum++;
                }
                TMGT_INF("fakeOccResponse: Writing checksum 0x%04X to offset"
                         " 0x%04X", checksum, checksumOffset);
                UINT16_PUT(&rspBuffer[checksumOffset], checksum);
            }
            else
            {
                TMGT_INF("fakeOccResponse: status=0xE1");
                rspBuffer[2] = 0xE0; // status
                const uint16_t dataLength = 32;
                UINT16_PUT(&rspBuffer[3], dataLength);
                const uint8_t excpData[dataLength] = { 0x11, 0x22, 0x33, 0x44 };
                TMGT_INF("fakeOccResponse: data length=%d", dataLength);
                if (dataLength)
                {
                    memcpy(&rspBuffer[5], &excpData, dataLength);
                }
            }

            L_state = 0;
        }

        // Check response buffer
        if (L_prior_status != rspBuffer[2])
        {
            TMGT_INF("fakeOccResponse: status updated to 0x%02X",
                     rspBuffer[2]);
            L_prior_status = rspBuffer[2];
        }
        if (L_prior_sequence != rspBuffer[0])
        {
            TMGT_INF("fakeOccResponse: sequence updated to 0x%02X"
                     " (expecting=0x%02X)",
                     rspBuffer[0], iv_Occ->iv_seqNumber);
            L_prior_sequence = rspBuffer[0];
        }

    } // end fakeOccResponse()
#endif



    // Returns true if timeout waiting for response
    bool OccCmd::waitForOccRsp(uint32_t i_timeout)
    {
        assert(iv_Occ->iv_homerValid == true, "waitForOccRsp: HOMER is invalid");
        assert(iv_Occ->iv_homer != nullptr, "waitForOccRsp: HOMER is null");
        const uint8_t * const rspBuffer = iv_Occ->iv_homer + OCC_RSP_ADDR;
        uint16_t rspLength = 0;
        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("waitForOccRsp(%d) address=0x%08llX",
                     i_timeout, rspBuffer);
        }

        bool l_time_expired = true;
        const int64_t OCC_RSP_SAMPLE_TIME = 100; // in milliseconds
        int64_t l_msec_remaining =
            std::max(int64_t(i_timeout * 1000), OCC_RSP_SAMPLE_TIME);
        while (l_msec_remaining >= 0)
        {
#ifdef SIMICS_TESTING
            fakeOccResponse();
#endif
            // 1. When OCC receives the command, they will set the status to
            //    COMMAND_IN_PROGRESS.
            // 2. When the response is ready they will update the full
            //    response buffer (except the status)
            // 3. The status field is updated last to indicate response ready
            //
            // Note: Need to check the sequence number to be sure we are
            //       processing the expected response
            if ((OCC_COMMAND_IN_PROGRESS != rspBuffer[2]) &&
                (iv_Occ->iv_seqNumber == rspBuffer[0]))
            {
                // Need an 'isync' here to ensure that previous instructions
                // have completed before the code continues on. This is a type
                // of read-barrier.  Without this the processor can do
                // speculative reads of the HOMER data and you can actually
                // get stale data as part of the instructions that happen
                // afterwards. Another 'weak consistency' issue.
                isync();

                // OCC must have processed the command
                const uint16_t rspDataLen = UINT16_GET(&rspBuffer[3]);
                rspLength = OCC_RSP_HDR_LENGTH + rspDataLen;
                if (G_debug_trace & DEBUG_TRACE_OCCCMD)
                {
                    TMGT_INF("waitForOccRsp: OCC%d rsp (rsp length=%d)",
                             iv_Occ->iv_instance, rspLength);
                    TMGT_BIN("waitForOccRsp: OCC rsp data (up to 40 bytes)",
                             rspBuffer, std::min(rspLength, (uint16_t)40));
                }
                l_time_expired = false;
                break;
            }

            if (l_msec_remaining > 0)
            {
                // delay before next check
                const int64_t l_sleep_msec = std::min(l_msec_remaining,
                                                      OCC_RSP_SAMPLE_TIME);
                nanosleep( 0, NS_PER_MSEC * l_sleep_msec );
                l_msec_remaining -= l_sleep_msec;
            }
            else
            {
                // time expired
                l_msec_remaining = -1;

                TMGT_ERR("waitForOccRsp: OCC%d timeout waiting for"
                         " response", iv_Occ->iv_instance);
                uint8_t * const rspBuffer = iv_Occ->iv_homer +
                    OCC_RSP_ADDR;
                TMGT_BIN("Rsp Buffer (32 bytes)", rspBuffer, 32);

                // Read SRAM response buffer to check for exception
                // (On exception, data may not be copied to HOMER)
                handleOccException();
            }

        } // while(time remaining)

        if (l_time_expired)
        {
            // timeout waiting for response
            TMGT_ERR("waitForOccRsp: OCC%d timeout waiting for response"
                     " (%d sec)",
                     iv_Occ->iv_instance, i_timeout/1000);
        }

        return l_time_expired;

    } // end OccCmd::waitForOccRsp()



    // Check for an OCC exception in SRAM.  If found:
    // create/commit an error log with the OCC exception data
    void OccCmd::handleOccException(void)
    {
#ifdef CONFIG_HTMGT
        // Read SRAM to check for exception
        // (Exception data not copied into HOMER)
        const size_t l_length = 4*KILOBYTE;

        fapi2::variable_buffer l_buffer(l_length*8); // convert to bits

        errlHndl_t l_err = HBOCC::readSRAM(iv_Occ->getTarget(),
                               OCC_RSP_SRAM_ADDR,
                               reinterpret_cast<uint64_t*>(l_buffer.pointer()),
                               l_length );
        if (NULL == l_err)
        {
            auto sramRspPtr = reinterpret_cast<uint8_t*>(l_buffer.pointer());
            uint32_t l_sramDataLen = l_buffer.getLength<uint8_t>();
            // Check buffer status for exception
            if ((l_sramDataLen >= 3) &&
                (sramRspPtr[2] == OCC_RC_OCC_INIT_CHECKPOINT) &&
                (sramRspPtr[6] == OCC_COMM_ESTABLISHED_CHECKPOINT[0]) &&
                (sramRspPtr[7] == OCC_COMM_ESTABLISHED_CHECKPOINT[1]))
            {
                // OCC has completed it initialization and is ready for
                // communication.  This is not an exception.
                if (false == iv_Occ->iv_commEstablished)
                {
                    TMGT_INF("handleOccException: OCC%d SRAM does have the "
                             "final COMM_INIT_COMPLETED checkpoint",
                             iv_Occ->iv_instance);
                }
            }
            // (don't log 0xE1 exception if communication has been established)
            else if (((l_sramDataLen >= 3) &&
                      (0xE0 == (sramRspPtr[2] & 0xE0))) &&
                     ((sramRspPtr[2] != OCC_RC_OCC_INIT_CHECKPOINT) ||
                      (false == iv_Occ->iv_commEstablished)))
            {
                const uint8_t exceptionType = sramRspPtr[2];
                uint16_t exceptionDataLength = 0;
                if (l_sramDataLen >= 5)
                {
                    exceptionDataLength = UINT16_GET(&sramRspPtr[3]);
                }
                // Exception length includes response header (w/o checksum) and
                // the data length
                uint32_t exceptionLength = OCC_RSP_HDR_LENGTH - 2 +
                    exceptionDataLength;
                if (exceptionLength > l_sramDataLen)
                {
                    exceptionLength = l_sramDataLen;
                }

                TMGT_ERR("handleOccException: OCC%d SRAM has exception"
                         " 0x%02X, length=%d",
                         iv_Occ->iv_instance, exceptionType,
                         exceptionDataLength);
                if (exceptionLength > 4*KILOBYTE)
                {
                    TMGT_INF("handleOccException: truncating length to 4K");
                    exceptionLength = 4*KILOBYTE;
                }

                TMGT_BIN("OCC Exception Data (up to 64 bytes)",
                         sramRspPtr, std::min(exceptionLength,(uint32_t)64));
                if (iv_Occ->iv_exceptionLogged != exceptionType)
                {
                    /*@
                     * @errortype
                     * @reasoncode HTMGT_RC_INTERNAL_ERROR
                     * @moduleid HTMGT_MOD_HANLDE_OCC_EXCEPTION
                     * @userdata1[0:31] rsp status
                     * @userdata1[32:63] exception data length
                     * @userdata2[0:31] OCC instance
                     * @userdata2[32:63] exception data
                     * @devdesc OCC reported exception
                     */
                    errlHndl_t l_excErr = NULL;
                    ERRORLOG::errlSeverity_t severity =
                        ERRORLOG::ERRL_SEV_INFORMATIONAL;
                    if (OCC_RESET_COUNT_THRESHOLD == iv_Occ->iv_resetCount)
                    {
                        // commit as unrecoverable if will end up in safe mode
                        severity = ERRORLOG::ERRL_SEV_UNRECOVERABLE;
                    }
                    bldErrLog(l_excErr, HTMGT_MOD_HANLDE_OCC_EXCEPTION,
                              (htmgtReasonCode)(OCCC_COMP_ID | exceptionType),
                              exceptionType, exceptionDataLength,
                              iv_Occ->iv_instance, UINT32_GET(&sramRspPtr[5]),
                              severity);
                    l_excErr->addFFDC(OCCC_COMP_ID,
                                      sramRspPtr,
                                      exceptionLength,
                                      1,  // version
                                      exceptionType); // subsection
#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
                    char header[64];
                    sprintf(header, "OCC%d 0x%02X Exception: (0x%04X bytes)",
                            iv_Occ->iv_instance, exceptionType,
                            exceptionLength);
                    dumpToConsole(header, (const uint8_t *)sramRspPtr,
                                  exceptionLength);
#endif

                    if (0xE1 == exceptionType)
                    {
                        iv_Occ->collectCheckpointScomData(l_excErr);
                    }

                    // Add processor callout
                    TARGETING::ConstTargetHandle_t procTarget =
                        TARGETING::getParentChip(iv_Occ->getTarget());
                    if (nullptr != procTarget)
                    {
                        const unsigned long huid =
                            procTarget->getAttr<TARGETING::ATTR_HUID>();
                        TMGT_ERR("handleOccException: Adding processor "
                                 "callout (HUID=0x%0lX)", huid);
                        l_excErr->addHwCallout(procTarget,
                                               HWAS::SRCI_PRIORITY_MED,
                                               HWAS::NO_DECONFIG,
                                               HWAS::GARD_NULL);
                    }
                    else
                    {
                        TMGT_ERR("handleOccException: Unable to determine "
                                 "parent chip to add callout");
                    }

                    // Add OCC trace buffer to error log (ERR, IMP, INF)
                    iv_Occ->addOccTrace( l_excErr );

                    ERRORLOG::errlCommit(l_excErr, HTMGT_COMP_ID);

                    // Save exception so we don't log it again
                    iv_Occ->iv_exceptionLogged = exceptionType;
                    // This OCC needs to be reset to recover
                    iv_Occ->failed(true);
                    iv_Occ->iv_needsReset = true;
                }
            }
        }
#endif

    } // end OccCmd::handleOccException()



    // Build OCC command buffer in HOMER, notify OCC and wait for
    // the response or timeout
    errlHndl_t OccCmd::writeOccCmd()
    {
        errlHndl_t l_err = NULL;
        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("writeOccCmd() called");
        }

        // Write the command to HOMER
        buildOccCmdBuffer();

        // Notify OCC that command is available (via circular buffer)
        const uint32_t l_bitsToSend = sizeof(occCircBufferCmd_t) * 8;

        const occCircBufferCmd_t tmgtDataWriteAttention =
        {
            0x10,   // sender: HTMGT
            0x01,   // command: Command Write Attention
            {0, 0, 0, 0, 0, 0} // reserved
        };

        fapi2::buffer<uint64_t> l_circ_buffer;
        l_circ_buffer.insert((*(uint64_t*)&tmgtDataWriteAttention),0, l_bitsToSend);


        if (G_debug_trace & DEBUG_TRACE_VERBOSE)
        {
            TMGT_INF("writeOccCmd: Calling writeCircularBuffer()");
        }
#ifdef CONFIG_HTMGT
        l_err = HBOCC::writeCircularBuffer(iv_Occ->iv_target, l_circ_buffer.pointer());
        if (NULL != l_err)
        {
            TMGT_ERR("writeOccCmd: Error writing to OCC Circular Buffer,"
                     " rc=0x%04X", l_err->reasonCode());
            iv_Occ->collectCheckpointScomData(l_err);
            iv_Occ->addOccTrace( l_err );
            l_err->collectTrace("HTMGT");
            ERRORLOG::errlCommit(l_err, HTMGT_COMP_ID);
        }
#endif

        // Continue to try to read response buffer, in case an
        // exception happened...

        // Wait for response from the OCC
        const uint8_t l_instance = iv_Occ->iv_instance;
        const uint8_t l_index = getCmdIndex(iv_OccCmd.cmdType);
        const uint16_t l_read_timeout = cv_occCommandTable[l_index].timeout;

        // Wait for OCC to process command and send response
        waitForOccRsp(l_read_timeout);

        // Parse the OCC response (called even on timeout to collect
        // rsp buffer)
        l_err = parseOccResponse();

        bool l_timeout = false;
        if (OCC_COMMAND_IN_PROGRESS != iv_OccRsp.returnStatus)
        {
            // Status of 0xE0-EF are reserved for OCC exceptions,
            // must collect data for these
            if (0xE0 == (iv_OccRsp.returnStatus & 0xF0))
            {
                handleOccException();
                l_timeout = true;
            }
            else
            {
                if (iv_OccRsp.sequenceNumber !=
                    iv_OccCmd.sequenceNumber)
                {
                    // Sequence number mismatch
                    TMGT_ERR("writeOccCmd: OCC%d sequence number mismatch"
                             " (from cmd: 0x%02X, rsp: 0x%02X)",
                             l_instance, iv_OccCmd.sequenceNumber,
                             iv_OccRsp.sequenceNumber);
                    l_timeout = true;
                }
            }
        }
        else
        {
            // OCC must not have completed processing the command before
            // timeout
            l_timeout = true;
        }

        if (l_timeout)
        {
            /*@
             * @errortype
             * @refcode LIC_REFCODE
             * @subsys EPUB_FIRMWARE_SP
             * @reasoncode HTMGT_RC_TIMEOUT
             * @moduleid HTMGT_MOD_WRITE_OCC_CMD
             * @userdata1[0:15] command
             * @userdata1[16:31] read timeout
             * @userdata2[0:15] response sequence number
             * @userdata2[16:31] response status
             * @devdesc Timeout waiting for OCC response
             */
            bldErrLog(l_err, HTMGT_MOD_WRITE_OCC_CMD, HTMGT_RC_TIMEOUT,
                      iv_OccCmd.cmdType, l_read_timeout,
                      iv_OccRsp.sequenceNumber,
                      iv_OccRsp.returnStatus,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);

            // The response buffer did not contain correct sequence number,
            // or status is still in progress ==> timeout
            assert(iv_Occ->iv_homerValid == true, "writeOccCmd: HOMER is invalid");
            assert(iv_Occ->iv_homer != nullptr, "writeOccCmd: HOMER is null");
            const uint8_t * const rspBuffer = iv_Occ->iv_homer + OCC_RSP_ADDR;
            l_err->addFFDC(HTMGT_COMP_ID,
                           rspBuffer,
                           KILOBYTE,
                           1,
                           SUBSEC_OCC_RSP_DATA);

            // timeout waiting for response (no data to return)
            iv_OccRsp.dataLength = 0;

            iv_Occ->collectCheckpointScomData( l_err );
            iv_Occ->addOccTrace( l_err );

        } // end timeout

        return l_err;

    } /* end of OccCmd::writeOccCmd() */



    // Copy OCC command into command buffer in HOMER
    uint16_t OccCmd::buildOccCmdBuffer()
    {
        assert(iv_Occ->iv_homerValid == true, "buildOccCmdBuffer: HOMER is invalid");
        assert(iv_Occ->iv_homer != nullptr, "buildOccCmdBuffer: HOMER is null");
        uint8_t * const cmdBuffer = iv_Occ->iv_homer + OCC_CMD_ADDR;
        uint16_t l_send_length = 0;

        if (0 == ++iv_Occ->iv_seqNumber)
        {
            // Do not use 0 for sequence number
            ++iv_Occ->iv_seqNumber;
        }
        iv_OccCmd.sequenceNumber = iv_Occ->iv_seqNumber;
        cmdBuffer[l_send_length++] = iv_OccCmd.sequenceNumber;
        cmdBuffer[l_send_length++] = iv_OccCmd.cmdType;
        cmdBuffer[l_send_length++] = (iv_OccCmd.dataLength >> 8) & 0xFF;
        cmdBuffer[l_send_length++] = iv_OccCmd.dataLength & 0xFF;
        memcpy(&cmdBuffer[l_send_length], iv_OccCmd.cmdData,
               iv_OccCmd.dataLength);
        l_send_length += iv_OccCmd.dataLength;

        // Calculate checksum
        iv_OccCmd.checksum = 0;
        for (uint16_t l_index = 0; l_index < l_send_length; l_index++)
        {
            iv_OccCmd.checksum += cmdBuffer[l_index];
        }
        cmdBuffer[l_send_length++] = (iv_OccCmd.checksum >> 8) & 0xFF;
        cmdBuffer[l_send_length++] = iv_OccCmd.checksum & 0xFF;

        if (G_debug_trace & DEBUG_TRACE_OCCCMD)
        {
            // Trace the command
            TMGT_BIN("buildOccCmdBuffer: OCC command (up to 300 bytes)",
                     cmdBuffer, std::min(l_send_length, (uint16_t)300));
        }

#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
        // Trace full OCC command
        char header[64];
        sprintf(header, "OCC%d Command: %s (0x%04X bytes)",
                iv_Occ->iv_instance, command_string(iv_OccCmd.cmdType),
                l_send_length);
        dumpToConsole(header, cmdBuffer, l_send_length);
#endif

#ifdef SIMICS_TESTING
        g_seq = iv_OccCmd.sequenceNumber;
        g_cmd = iv_OccCmd.cmdType;
#endif

        // When the P8 processor writes to memory (such as the HOMER) there is
        // no certainty that the writes happen in order or that they have
        // actually completed by the time the instructions complete. 'sync'
        // is a memory barrier to ensure the HOMER data has actually been made
        // consistent with respect to memory, so that if the OCC were to read
        // it they would see all of the data. Otherwise, there is potential
        // for them to get stale or incomplete data.
        sync();

        return l_send_length;

    } // end OccCmd::buildOccCmdBuffer()



    // Copy response into object
    errlHndl_t OccCmd::parseOccResponse()
    {
        errlHndl_t l_errlHndl = NULL;
        uint16_t l_index = 0;
        assert(iv_Occ->iv_homerValid == true, "parseOccResponse: HOMER is invalid");
        assert(iv_Occ->iv_homer != nullptr, "parseOccResponse: HOMER is null");
        const uint8_t * const rspBuffer = iv_Occ->iv_homer + OCC_RSP_ADDR;
        const uint16_t rspLen = OCC_RSP_HDR_LENGTH + UINT16_GET(&rspBuffer[3]);

        if ((NULL != rspBuffer) && (rspLen >= OCC_RSP_HDR_LENGTH))
        {
#ifdef CONFIG_CONSOLE_OUTPUT_OCC_COMM
            // Trace raw OCC response
            char header[64];
            sprintf(header, "OCC%d Response: (0x%04X bytes)",
                    iv_Occ->iv_instance, rspLen);
            dumpToConsole(header, rspBuffer, rspLen);
#endif
            iv_OccRsp.sequenceNumber = rspBuffer[l_index++];
            iv_OccRsp.cmdType = (enum occCommandType)rspBuffer[l_index++];
            iv_OccRsp.returnStatus = (occReturnCodes)rspBuffer[l_index++];

            iv_OccRsp.dataLength = UINT16_GET(&rspBuffer[l_index]);
            l_index += 2;
            if (rspLen >= (iv_OccRsp.dataLength + OCC_RSP_HDR_LENGTH))
            {
                if (iv_OccRsp.dataLength > 0)
                {
                    if (iv_OccRsp.dataLength > OCC_MAX_DATA_LENGTH)
                    {
                        TMGT_ERR("parseOccResponse: truncating data (0x%04X)",
                                 iv_OccRsp.dataLength);
                        iv_OccRsp.dataLength = OCC_MAX_DATA_LENGTH;
                    }
                    memcpy(iv_OccRsp.rspData, &rspBuffer[l_index],
                           iv_OccRsp.dataLength);
                    l_index += iv_OccRsp.dataLength;
                }
                iv_OccRsp.checksum = UINT16_GET(&rspBuffer[l_index]);
                l_index += 2;
            }
            else
            {
                // Log invalid read length (not enough data received)
                /*@
                 * @errortype
                 * @reasoncode HTMGT_RC_SEND_FAIL
                 * @moduleid HTMGT_MOD_PARSE_OCC_RSP
                 * @userdata1[0:15] response length
                 * @userdata1[16:31] response buffer[0-3]
                 * @userdata2[0:15] response buffer[4-7]
                 * @userdata2[16:31]
                 * @devdesc Invalid response length received
                 */
                bldErrLog(l_errlHndl, HTMGT_MOD_PARSE_OCC_RSP,
                          HTMGT_RC_SEND_FAIL,
                          rspLen, UINT32_GET(rspBuffer),
                          UINT32_GET(&rspBuffer[4]), 0,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
        }
        else
        {
            uint32_t l_data[2] = {0};
            if (NULL != rspBuffer)
            {
                memcpy(l_data, rspBuffer, sizeof(l_data));
            }
            // Log invalid read length (rsp too short)
            bldErrLog(l_errlHndl, HTMGT_MOD_PARSE_OCC_RSP, HTMGT_RC_SEND_FAIL,
                      rspLen, l_data[0], l_data[1], 0,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        if (l_errlHndl)
        {
            // Add full OCC response to user details
            l_errlHndl->addFFDC(HTMGT_COMP_ID,
                                rspBuffer,
                                rspLen,
                                1,  // version
                                SUBSEC_OCC_RSP_DATA);
        }

        return l_errlHndl;

    } // end OccCmd::parseOccResponse()



    // Verify status, checksum and length of OCC response
    errlHndl_t OccCmd::checkOccResponse()
    {
        errlHndl_t l_errlHndl = NULL;
        uint16_t l_calc_checksum = 0, l_index = 0;

        // Calculate checksum on response
        l_calc_checksum += iv_OccRsp.sequenceNumber;
        l_calc_checksum += iv_OccRsp.cmdType;
        l_calc_checksum += iv_OccRsp.returnStatus;
        l_calc_checksum += (iv_OccRsp.dataLength >> 8) & 0xFF;
        l_calc_checksum += iv_OccRsp.dataLength & 0xFF;
        for (l_index = 0; l_index < iv_OccRsp.dataLength; l_index++)
        {
            l_calc_checksum += iv_OccRsp.rspData[l_index];
        }

        if (l_calc_checksum == iv_OccRsp.checksum)
        {
            if (OCC_RC_SUCCESS == iv_OccRsp.returnStatus)
            {
                occCheckRspLengthType l_check_rsp_length;
                uint16_t l_rsp_length = 0;

                // Verify response length and log errors if bad
                l_index = getCmdIndex(iv_OccRsp.cmdType);
                // l_index should be valid since validation was done
                // in sendOccCmd()
                l_check_rsp_length = cv_occCommandTable[l_index].checkRspLength;
                l_rsp_length = cv_occCommandTable[l_index].rspLength;

                if (OCC_CHECK_RSP_LENGTH_EQUALS == l_check_rsp_length)
                {
                    if ( iv_OccRsp.dataLength != l_rsp_length )
                    {
                        TMGT_ERR("Invalid length in OCC response for"
                                 " cmd=0x%02X, length=0x%04X",
                                 iv_OccRsp.cmdType,
                                 iv_OccRsp.dataLength);
                        /*@
                         * @errortype
                         * @reasoncode HTMGT_RC_OCC_CMD_FAIL
                         * @moduleid HTMGT_MOD_CHECK_OCC_RSP
                         * @userdata1[0:15] OCC command type
                         * @userdata1[16:31] response data length
                         * @devdesc Invalid length in OCC response
                         */
                        bldErrLog(l_errlHndl, HTMGT_MOD_CHECK_OCC_RSP,
                                  HTMGT_RC_OCC_CMD_FAIL,
                                  iv_OccRsp.cmdType,
                                  iv_OccRsp.dataLength, 0, 1,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    }
                }
                else if (OCC_CHECK_RSP_LENGTH_GREATER == l_check_rsp_length)
                {
                    if ( iv_OccRsp.dataLength < l_rsp_length )
                    {
                        TMGT_ERR("Invalid length in OCC response for"
                                 " cmd=0x%02X, length=0x%04X",
                                 iv_OccRsp.cmdType,
                                 iv_OccRsp.dataLength);
                        bldErrLog(l_errlHndl, HTMGT_MOD_CHECK_OCC_RSP,
                                  HTMGT_RC_OCC_CMD_FAIL,
                                  iv_OccRsp.cmdType,
                                  iv_OccRsp.dataLength, 0, 2,
                                  ERRORLOG::ERRL_SEV_INFORMATIONAL);
                    }
                }
                else if (OCC_CHECK_RSP_LENGTH_NONE != l_check_rsp_length)
                {
                    TMGT_ERR("Invalid check response length=0x%02X in OCC"
                             " command table for cmd = 0x%02X",
                             l_check_rsp_length, iv_OccRsp.cmdType);
                    bldErrLog(l_errlHndl, HTMGT_MOD_CHECK_OCC_RSP,
                              HTMGT_RC_OCC_CMD_FAIL,
                              iv_OccRsp.cmdType, iv_OccRsp.dataLength,
                              0, 0, ERRORLOG::ERRL_SEV_INFORMATIONAL);
                }
            }
            else
            {
                // Command was not successfully processed
                uint8_t l_error_log_id = 0;

                if (1 == iv_OccRsp.dataLength)
                {
                    // Data should be error log id created for this failure
                    l_error_log_id = iv_OccRsp.rspData[0];

                    TMGT_ERR("checkOccResponse: Bad status (0x%02X=%s) from OCC"
                             " (returned elog=0x%02X)",
                             iv_OccRsp.returnStatus,
                             rsp_status_string(iv_OccRsp.returnStatus),
                             l_error_log_id);
                }
                else
                {
                    TMGT_ERR("checkOccResponse: Bad status (0x%02X=%s) from OCC"
                             " (data len=%d)",
                             iv_OccRsp.returnStatus,
                             rsp_status_string(iv_OccRsp.returnStatus),
                             iv_OccRsp.dataLength);

                    TMGT_ERR("OCC response packet length invalid (0x%04X)",
                             iv_OccRsp.dataLength);
                    l_error_log_id = 0;
                }
                /*  */
                bldErrLog(l_errlHndl, HTMGT_MOD_CHECK_OCC_RSP,
                          HTMGT_RC_OCC_CMD_FAIL,
                          iv_OccRsp.returnStatus, l_error_log_id,
                          iv_OccRsp.cmdType, 3,
                          ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
        }
        else
        {
            /*@
             * @errortype
             * @reasoncode HTMGT_RC_CHECKSUM_FAIL
             * @moduleid HTMGT_MOD_CHECK_OCC_RSP
             * @userdata1 OCC command type
             * @userdata2 sequence number
             * @userdata3 checksum
             * @userdata4 calculated checksum
             * @devdesc OCC response had checksum failure
             */
            bldErrLog(l_errlHndl, HTMGT_MOD_CHECK_OCC_RSP,
                      HTMGT_RC_CHECKSUM_FAIL,
                      iv_OccRsp.cmdType, iv_OccRsp.sequenceNumber,
                      iv_OccRsp.checksum, l_calc_checksum,
                      ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }

        if (l_errlHndl)
        {
            // Add OCC response data to user details
            l_errlHndl->addFFDC(HTMGT_COMP_ID,
                                iv_OccRsp.rspData,
                                iv_OccRsp.dataLength,
                                1,  // version
                                SUBSEC_OCC_RSP_DATA);
        }

        return(l_errlHndl);

    } /* end of OccCmd::checkOccResponse() */


}
