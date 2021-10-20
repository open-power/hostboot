/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_transfer.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <time.h>
#include <devicefw/userif.H>
#include <trace/interface.H>
#include <targeting/targplatutil.H>
#include <secureboot/nodecommif.H>
#include <secureboot/secure_reasoncodes.H>
#include "node_comm.H"
#include "node_comm_transfer.H"

// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace SECUREBOOT
{

namespace NODECOMM
{
// mutex for TransferSizeMap access
mutex_t g_transferSizeMutex = MUTEX_INITIALIZER;

errlHndl_t nodeCommTransferSend(TARGETING::Target* i_pTarget,
                                const uint8_t i_linkId,
                                const uint8_t i_mboxId,
                                const uint8_t i_recvNode,
                                node_comm_transfer_types_t i_transferType,
                                const uint8_t * i_data,
                                const size_t i_dataSize)
{
    errlHndl_t err = nullptr;

    // Determine how many messages need to be sent:
    // msg sequence 0: Initiation Message
    // msg sequence 1..N: 8-byte data messages
    size_t msg_seq = 0;
    size_t total_data_msgs = (i_dataSize + (sizeof(uint64_t)-1))
                             /sizeof(uint64_t);

    auto my_node = TARGETING::UTIL::getCurrentNodePhysId();

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommTransferSend: i_pTarget=0x%.08X "
              "to send %d bytes of data through linkId=%d mboxId=%d over "
              "%d data messages to node %d",
              get_huid(i_pTarget), i_dataSize, i_linkId, i_mboxId,
              total_data_msgs, i_recvNode);

    do
    {
        // Check expected size of msgType here
        // need mutex as map accesses are not thread-safe
        mutex_lock(&g_transferSizeMutex);
        size_t typeCount = TransferSizeMap.count(i_transferType);
        size_t transferSize = -1;
        if (typeCount > 0)
        {
            transferSize = TransferSizeMap.at(i_transferType);
        }
        mutex_unlock(&g_transferSizeMutex);

        // If msgType is found and the size is different
        if ((typeCount > 0) && (transferSize != i_dataSize))
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: i_pTarget=0x%.08X: "
              "i_dataSize %d bytes does not align with i_transferType 0x%X: "
              "Expected size %d bytes.",
              get_huid(i_pTarget), i_dataSize, i_transferType,
              transferSize);

            /*@
             * @errortype
             * @reasoncode       RC_NCT_TYPE_SIZE_MISMATCH
             * @moduleid         MOD_NCT_SEND
             * @userdata1[0:31]  Input TARGET HUID
             * @userdata1[32:63] Input Data Size
             * @userdata2[0:31]  Input Transfer Type
             * @userdata2[32:63] Expected Size For Input Transfer Type
             * @devdesc          Invalid Input Args for Node Comm Transfer Send
             * @custdesc         Trusted Boot failure
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_NCT_SEND,
                                          RC_NCT_TYPE_SIZE_MISMATCH,
                                          TWO_UINT32_TO_UINT64(
                                            get_huid(i_pTarget),
                                            i_dataSize),
                                          TWO_UINT32_TO_UINT64(
                                            i_transferType,
                                            transferSize),
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }

        // Keep track of data sent
        size_t bytes_sent = 0;
        size_t bytes_left = i_dataSize;

        // Loop of sending messages (initiation and data) and receiving ACKs
        for ( ; msg_seq <= total_data_msgs; ++msg_seq)
        {
            TRACUTCOMP(g_trac_nc,INFO_MRK"nodeCommTransferSend: loop start: "
                      "seq = %d (msg %d of %d)",
                      msg_seq, msg_seq+1, total_data_msgs);

            uint64_t data = 0;

            if (msg_seq==0)
            {
                // Send Initiaion Message
                node_comm_msg_format_t send_msg;
                send_msg.value = 0;  // Clear out the data

                send_msg.sendingNode = my_node;
                send_msg.recvingNode = i_recvNode;

                send_msg.msgType = i_transferType;
                send_msg.msgSeqNum = msg_seq;
                send_msg.totalDataMsgs = total_data_msgs;
                send_msg.totalDataSize = i_dataSize;

                data = send_msg.value;
            }
            else
            {
                // Send Data
                // Write a max of 8 bytes at a time
                size_t loop_data_length =
                            (bytes_left > sizeof(uint64_t)) ?
                                sizeof(uint64_t) :
                                bytes_left;

                data=0;
                memcpy(&data,
                       i_data + bytes_sent,
                       loop_data_length);

                // Update amount of data left to be written
                bytes_sent += loop_data_length;
                bytes_left -= loop_data_length;
            }
            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferSend: "
                      "msg %d: sending data=0x%.16llX (bytes_sent=%d, "
                      "bytes_left=%d)",
                      msg_seq, data, bytes_sent, bytes_left);

            err = nodeCommSendMessage(i_pTarget,
                                      data,
                                      i_linkId,
                                      i_mboxId);

            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: "
                          "nodeCommSendMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pTarget), data, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));
                break;
            }

            // Get ACK
            uint64_t data_recv = 0;
            err = nodeCommRecvMessage(i_pTarget,
                                      i_linkId,
                                      i_mboxId,
                                      data_recv);
            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: "
                          "nodeCommRecvMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pTarget), data, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));

                break;
            }
            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferSend: "
                      "msg %d: receiving ACK = 0x%.16llX",
                      msg_seq, data_recv);

            // Verify that ACK returned has expected data
            node_comm_msg_format_t ack_msg = {.value = data_recv};
            auto ack_expected_msg_type = NCT_ACK_OF_DATA;
            if (msg_seq==0)
            {
                ack_expected_msg_type = NCT_ACK_OF_INTIATION;
            }

            if ((ack_msg.sendingNode != i_recvNode) ||
                (ack_msg.recvingNode != my_node) ||
                (ack_msg.msgType     != ack_expected_msg_type) ||
                (ack_msg.msgSeqNum   != msg_seq))
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: "
                  "ACK has bad data! Got (expected): sN=%d (%d), rN=%d (%d), "
                  "msgType=0x%X (0x%X), msgSeqNum=0x%X (0x%X)",
                  ack_msg.sendingNode, i_recvNode,
                  ack_msg.recvingNode, my_node,
                  ack_msg.msgType, ack_expected_msg_type,
                  ack_msg.msgSeqNum, msg_seq);

                /*@
                 * @errortype
                 * @reasoncode       RC_NCT_ACK_MISMATCH
                 * @moduleid         MOD_NCT_SEND
                 * @userdata1[0:15]  Actual Node Sending the ACK
                 * @userdata1[16:31] Expected Node Sending the ACK
                 * @userdata1[32:47] Actual Node Receiving the ACK
                 * @userdata1[48:63] Expected Node Receiving the ACK
                 * @userdata2[0:15]  Actual Message Type from the ACK
                 * @userdata2[16:31] Expected Message Type from the ACK
                 * @userdata2[32:47] Actual Sequence Number from the ACK
                 * @userdata2[48:63] Expected Sequence Number from the ACK
                 * @devdesc          Invalid data from ACK for Node Comm
                 *                   Transfer Send
                 * @custdesc         Trusted Boot failure
                 */
                err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_NCT_SEND,
                              RC_NCT_ACK_MISMATCH,
                              FOUR_UINT16_TO_UINT64(
                                ack_msg.sendingNode,
                                i_recvNode,
                                ack_msg.recvingNode,
                                my_node),
                              FOUR_UINT16_TO_UINT64(
                                ack_msg.msgType,
                                ack_expected_msg_type,
                                ack_msg.msgSeqNum,
                                msg_seq),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

        }  // end of for-loop of messages

        if (err)
        {
            break;
        }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommTransferSend: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommTransferSend



errlHndl_t nodeCommTransferRecv(TARGETING::Target* i_pTarget,
                                const uint8_t i_linkId,
                                const uint8_t i_mboxId,
                                const uint8_t i_sentNode,
                                node_comm_transfer_types_t i_transferType,
                                uint8_t*& o_data,
                                size_t & o_dataSize)
{
    errlHndl_t err = nullptr;

    auto my_node = TARGETING::UTIL::getCurrentNodePhysId();

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommTransferRecv: i_pTarget=0x%.08X "
              "expecting messages of type 0x%.02x from linkId=%d mboxId=%d, "
              "node=%d",
              get_huid(i_pTarget), i_transferType, i_linkId, i_mboxId,
              i_sentNode);

    // Clear the output variables to be safe
    o_data = nullptr;
    o_dataSize = 0;

    do
    {

        // Wait for Message
        uint64_t data_recv = 0;
        err = nodeCommRecvMessage(i_pTarget,
                                  i_linkId,
                                  i_mboxId,
                                  data_recv);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                      "nodeCommRecvMessage returned an error: "
                      "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget), data_recv, i_linkId, i_mboxId,
                      TRACE_ERR_ARGS(err));

            break;
        }
        node_comm_msg_format_t init_msg = {.value = data_recv};
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommTransferRecv: "
                  "Initiation Message 0x%.16llX: sN=%d, rN=%d, msgType=0x%X, "
                  "msgSeqNum=%d, totalDataMsgs=%d.totalDataSize=%d",
                  init_msg.value, init_msg.sendingNode, init_msg.recvingNode,
                  init_msg.msgType, init_msg.msgSeqNum, init_msg.totalDataMsgs,
                  init_msg.totalDataSize);

        // Verify Data in the Initiation message
        auto expected_msg_seq = 0;
        if ((init_msg.sendingNode != i_sentNode) ||
            (init_msg.recvingNode != my_node) ||
            (init_msg.msgType     != i_transferType) ||
            (init_msg.msgSeqNum   != expected_msg_seq))
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
              "Initiation Message has bad data! Got (expected): "
              "sN=%d (%d), rN=%d (%d), "
              "msgType=0x%X (0x%X), msgSeqNum=0x%X (0x%X)",
              init_msg.sendingNode, i_sentNode,
              init_msg.recvingNode, my_node,
              init_msg.msgType, i_transferType,
              init_msg.msgSeqNum, expected_msg_seq);

            /*@
             * @errortype
             * @reasoncode       RC_NCT_INITIATION_MISMATCH
             * @moduleid         MOD_NCT_RECEIVE
             * @userdata1[0:15]  Actual Node Sending the Initiation Message
             * @userdata1[16:31] Expected Node Sending the Initiation Message
             * @userdata1[32:47] Actual Node Receiving the Initiation Message
             * @userdata1[48:63] Expected Node Receiving the Initiaion Message
             * @userdata2[0:15]  Actual Message Type from Initiation Message
             * @userdata2[16:31] Expected Message Type from Initiation Message
             * @userdata2[32:47] Actual Sequence Number from Initiation Message
             * @userdata2[48:63] Expected Sequence Number from Initiation Msg
             * @devdesc          Invalid data from Initiation Message
             * @custdesc         Trusted Boot failure
             */
            err = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                          MOD_NCT_RECEIVE,
                                          RC_NCT_INITIATION_MISMATCH,
                                          FOUR_UINT16_TO_UINT64(
                                            init_msg.sendingNode,
                                            i_sentNode,
                                            init_msg.recvingNode,
                                            my_node),
                                          FOUR_UINT16_TO_UINT64(
                                            init_msg.msgType,
                                            i_transferType,
                                            init_msg.msgSeqNum,
                                            expected_msg_seq),
                                          ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
            break;
        }
        // Reply with ACK:
        node_comm_msg_format_t ack_msg = {.value = 0};
        ack_msg.value = 0;

        // Set node info
        // NOTE: These values are from the perspective of
        // sending the ACK and *not* from sending/receiving the data
        ack_msg.sendingNode = TARGETING::UTIL::getCurrentNodePhysId();
        ack_msg.recvingNode = i_sentNode;

        // Always set these for ACK of Initiation:
        ack_msg.msgSeqNum = 0;
        ack_msg.msgType = NCT_ACK_OF_INTIATION;

        // ACK total number of expected data messages
        ack_msg.totalDataMsgs = init_msg.totalDataMsgs;

        // Send ACK message
        err = nodeCommSendMessage(i_pTarget,
                                  ack_msg.value,
                                  i_linkId,
                                  i_mboxId);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                      "nodeCommSendMessage returned an error: "
                      "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pTarget), ack_msg.value, i_linkId, i_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }


        // msg sequence 0: Initiation Message
        // msg sequence 1..N: 8-byte data messages
        size_t msg_seq = 1;
        size_t total_data_msgs = init_msg.totalDataMsgs;

        // Keep track of data read
        size_t bytes_read = 0;
        size_t bytes_left = init_msg.totalDataSize;

        // Create output buffer to store the data
        uint8_t * data_buffer = reinterpret_cast<uint8_t*>
                                  (malloc(init_msg.totalDataSize));


        // Loop of receiving data messages and sending ACKs
        for ( ; msg_seq <= total_data_msgs; ++msg_seq)
        {
            // Wait for Data Message
            data_recv = 0;
            err = nodeCommRecvMessage(i_pTarget,
                                      i_linkId,
                                      i_mboxId,
                                      data_recv);
            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                          "nodeCommRecvMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pTarget), data_recv, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));

                    break;
            }
            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferRecv: "
                      "Data Msg Recvd: %d: 0x%.16llX",
                      msg_seq, data_recv);

            size_t loop_bytes_read = (bytes_left > sizeof(uint64_t)) ?
                                        sizeof(uint64_t) :
                                        bytes_left;

            memcpy(data_buffer+bytes_read,
                   &data_recv,
                   loop_bytes_read);

            data_recv=0; // clear for next loop

            bytes_read += loop_bytes_read;
            bytes_left -= loop_bytes_read;

            // Send Data ACK (re-uses previous ack_msg settings)
            ack_msg.msgType = NCT_ACK_OF_DATA;
            ack_msg.msgSeqNum = msg_seq;
            ack_msg.totalDataSize = bytes_read;

            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferRecv: "
                      "Data Msg ACK: %d: 0x%.16llX (bytes_read=%d, "
                      "bytes_left=%d)",
                      msg_seq, ack_msg.value, bytes_read, bytes_left);

            err = nodeCommSendMessage(i_pTarget,
                                      ack_msg.value,
                                      i_linkId,
                                      i_mboxId);

            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                          "nodeCommSendMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pTarget), ack_msg.value, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));
                break;
            }
        }  // end of for-loop for receiving data messages

        if (err)
        {
            free(data_buffer);
            o_data=nullptr;
            o_dataSize=0;
            break;
        }
        else
        {
            o_data = data_buffer;
            o_dataSize = init_msg.totalDataSize;

            // Check size of data returned against the expected amount based
            // on the msgType
            // need mutex as map accesses are not thread-safe
            mutex_lock(&g_transferSizeMutex);
            size_t typeCount = TransferSizeMap.count(i_transferType);
            size_t transferSize = -1;
            if (typeCount > 0)
            {
                transferSize = TransferSizeMap.at(i_transferType);
            }
            mutex_unlock(&g_transferSizeMutex);

            // If msgType is found and the size is different
            if ((typeCount > 0) && (transferSize != o_dataSize))
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferReceive: "
                          "iProc=0x%.08X: o_dataSize %d bytes does not "
                          "align with i_transferType 0x%X: "
                          "Expected size %d bytes.",
                          get_huid(i_pTarget), o_dataSize, i_transferType,
                          transferSize);

                /*@
                 * @errortype
                 * @reasoncode       RC_NCT_TYPE_SIZE_MISMATCH
                 * @moduleid         MOD_NCT_RECEIVE
                 * @userdata1[0:31]  Input TARGET HUID
                 * @userdata1[32:63] Output Data Size
                 * @userdata2[0:31]  Input Transfer Type
                 * @userdata2[32:63] Expected Size For Input Transfer Type
                 * @devdesc          Unexpected Size of Data Received based on
                 *                   Input Transfer Type
                 * @custdesc         Trusted Boot failure
                 */
                err = new ERRORLOG::ErrlEntry(
                              ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                              MOD_NCT_RECEIVE,
                              RC_NCT_TYPE_SIZE_MISMATCH,
                              TWO_UINT32_TO_UINT64(
                                get_huid(i_pTarget),
                                o_dataSize),
                              TWO_UINT32_TO_UINT64(
                                i_transferType,
                                transferSize),
                              ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
                break;
            }

        }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommTransferRecv: "
              "o_data=%p, o_dataSize=%d. "
              TRACE_ERR_FMT,
              o_data, o_dataSize,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommTransferRecv

} // end NODECOMM namespace

} // end SECUREBOOT namespace


