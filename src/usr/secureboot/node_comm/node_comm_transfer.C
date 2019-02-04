/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_transfer.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#include <config.h>
#include <time.h>
#include <devicefw/userif.H>
#include <trace/interface.H>
#include <scom/centaurScomCache.H> // for TRACE_ERR_FMT, TRACE_ERR_ARGS
#include <secureboot/nodecommif.H>
#include "node_comm.H"
#include "node_comm_transfer.H"

// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace SECUREBOOT
{

namespace NODECOMM
{


errlHndl_t nodeCommTransferSend(TARGETING::Target* i_pProc,
                                const uint8_t i_linkId,
                                const uint8_t i_mboxId,
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

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommTransferSend: iProc=0x%.08X "
              "to send %d bytes of data through linkId=%d mboxId=%d over "
              "%d data messages",
              get_huid(i_pProc), i_dataSize, i_linkId, i_mboxId, total_data_msgs);

    do
    {
        // Keep track of data sent
        size_t bytes_sent = 0;
        size_t bytes_left = i_dataSize;

        // Loop of sending messages (initiation and data) and receiving ACKs
        for ( ; msg_seq <= total_data_msgs; ++msg_seq)
        {
            TRACUCOMP(g_trac_nc,INFO_MRK"nodeCommTransferSend: loop start: "
                      "seq = %d (msg %d of %d)",
                      msg_seq, msg_seq+1, total_data_msgs);

            uint64_t data = 0;

            if (msg_seq==0)
            {
                // Send Initiaion Message
                node_comm_msg_format_t send_msg;
                send_msg.value = 0;  // Clear out the data

                // @TODO RTC 203642 Fix sendingNode and recving Node
                send_msg.sendingNode = 0;
                send_msg.recvingNode = 1;

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

            err = nodeCommAbusSendMessage(i_pProc,
                                          data,
                                          i_linkId,
                                          i_mboxId);

            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: "
                          "nodeCommAbusSendMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pProc), data, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));
                break;
            }

            // Get ACK
            uint64_t data_recv = 0;
            err = nodeCommAbusRecvMessage(i_pProc,
                                          i_linkId,
                                          i_mboxId,
                                          data_recv);
            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferSend: "
                          "nodeCommAbusRecvMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pProc), data, i_linkId, i_mboxId,
                          TRACE_ERR_ARGS(err));

                break;
            }
            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferSend: "
                      "msg %d: receiving ACK = 0x%.16llX",
                      msg_seq, data_recv);



            // @TODO RTC 203642 Check that ACK is
            // -- from the right node
            // -- from right linkId/mboxId
            // -- the right type of ACK

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



errlHndl_t nodeCommTransferRecv(TARGETING::Target* i_pProc,
                                const uint8_t i_linkId,
                                const uint8_t i_mboxId,
                                node_comm_transfer_types_t i_transferType,
                                uint8_t*& o_data,
                                size_t & o_dataSize)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommTransferRecv: i_pProc=0x%.08X "
              "expecting messages of type 0x%.02x from linkId=%d mboxId=%d",
              get_huid(i_pProc), i_transferType, i_linkId, i_mboxId);

    // Clear the output variables to be safe
    o_data = nullptr;
    o_dataSize = 0;

    do
    {

        // Wait for Message
        uint64_t data_recv = 0;
        err = nodeCommAbusRecvMessage(i_pProc,
                                      i_linkId,
                                      i_mboxId,
                                      data_recv);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                      "nodeCommAbusRecvMessage returned an error: "
                      "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pProc), data_recv, i_linkId, i_mboxId,
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

        // @TODO RTC 203642 Add the following checks:
        // - check nodes
        // - init_msg.msgSeqNum should be 0 for initiation message
        // - check that expected transfer type is received


        // Reply with ACK:
        node_comm_msg_format_t ack_msg = {.value = 0};
        ack_msg.value = 0;

        // @TODO RTC 203642 Fix sending node Ids
        // Always set these for ACK of Initiation:
        ack_msg.msgSeqNum = 0;
        ack_msg.msgType = NCT_ACK_OF_INTIATION;

        // ACK total number of expected data messages
        ack_msg.totalDataMsgs = init_msg.totalDataMsgs;

        // Send ACK message
        err = nodeCommAbusSendMessage(i_pProc,
                                      ack_msg.value,
                                      i_linkId,
                                      i_mboxId);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                      "nodeCommAbusSendMessage returned an error: "
                      "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_pProc), ack_msg.value, i_linkId, i_mboxId,
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
            err = nodeCommAbusRecvMessage(i_pProc,
                                          i_linkId,
                                          i_mboxId,
                                          data_recv);
            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                          "nodeCommAbusRecvMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pProc), data_recv, i_linkId, i_mboxId,
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

            // Send Data ACK
            ack_msg.msgType = NCT_ACK_OF_DATA;
            ack_msg.msgSeqNum = msg_seq;
            ack_msg.totalDataSize = bytes_read;

            TRACDCOMP(g_trac_nc,INFO_MRK"nodeCommTransferRecv: "
                      "Data Msg ACK: %d: 0x%.16llX (bytes_read=%d, "
                      "bytes_left=%d)",
                      msg_seq, ack_msg.value, bytes_read, bytes_left);

            err = nodeCommAbusSendMessage(i_pProc,
                                          ack_msg.value,
                                          i_linkId,
                                          i_mboxId);

            if (err)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommTransferRecv: "
                          "nodeCommAbusSendMessage returned an error: "
                          "Tgt=0x%.08X, data=0x%.16llX, link=%d, mbox=%d: "
                          TRACE_ERR_FMT,
                          get_huid(i_pProc), ack_msg.value, i_linkId, i_mboxId,
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


