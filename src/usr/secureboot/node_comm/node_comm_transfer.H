/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_transfer.H $           */
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
#ifndef __NODE_COMM_TRANSFER_H
#define __NODE_COMM_TRANSFER_H

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include "node_comm.H"
#include <map>

// ----------------------------------------------
// Defines
// ----------------------------------------------


namespace SECUREBOOT
{

namespace NODECOMM
{


/*
 * @brief Node Comm Transfer Types - descriptions of messages sent between nodes
 */
enum node_comm_transfer_types_t : uint8_t
{
    // Size of 1 byte due to its inclusion in node_comm_msg_format_t

    // Invalid Type for node_comm_msg_format_t initialization
    NCT_INVALID_TYPE               =  0x00,

    // Types of ACKs (Ackowledgments)
    NCT_ACK_OF_INTIATION           =  0x01,
    NCT_ACK_OF_DATA                =  0x02,

    // Message Transfer Types
    NCT_TRANSFER_SBID              =  0x10,
    NCT_TRANSFER_QUOTE_REQUEST     =  0x11,
    NCT_TRANSFER_QUOTE_RESPONSE    =  0x12,
    NCT_NODE_SYNC                  =  0x13,
};

/**
 * @brief Node Comm Message Format
 *
 * @note: msg sequence 0: Initiation Message
 *        msg sequence 1..N: 8-byte data messages
 *
 */
union node_comm_msg_format_t
{
    uint64_t value;
    struct
    {
        uint64_t sendingNode   :  4; // Sending Node
        uint64_t recvingNode   :  4; // Receiving Node
        uint64_t msgType       :  8; // Msg Type (node_comm_transfer_types_t)
        uint64_t msgSeqNum     : 16; // Msg Sequence Number
        uint64_t totalDataMsgs : 16; // Total Number of Expected Data Messages
        uint64_t totalDataSize : 16; // Total Size of Data in bytes
    } PACKED;
};

/**
 * @brief Map of expected sizes associated with Message Transfer Types
 */
const std::map<node_comm_transfer_types_t, size_t>
    TransferSizeMap = {{NCT_TRANSFER_SBID,
                            sizeof(uint64_t)},
                        {NCT_TRANSFER_QUOTE_REQUEST,
                            sizeof(MasterQuoteRequestBlob)},
                        {NCT_NODE_SYNC,
                            0}};


/**
 *  @brief This function sends multiple messages with data from
           the processor of the current node to a processor on another node.
 *
 *  @param[in] i_pTarget       - The target containing the node comm registers.
 *                               Can't be nullptr
 *  @param[in] i_linkId        - Link Id Message is sent from
 *  @param[in] i_mboxId        - Mailbox Id Message is sent from
 *  @param[in] i_recvNode      - Node expected to receive the message
 *  @param[in] i_transferType  - Transfer Message Type to send
 *  @param[in] i_data          - Data to be sent
 *  @param[in] i_dataSize      - Size of Data to be sent in bytes
 *
 *  @note i_dataSize is verified to match i_transferType when applicable
 *        based on TransferSizeMap.
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommTransferSend(TARGETING::Target* i_pTarget,
                                uint8_t i_linkId,
                                uint8_t i_mboxId,
                                uint8_t i_recvNode,
                                node_comm_transfer_types_t i_transferType,
                                const uint8_t * i_data,
                                size_t i_dataSize);

/**
 *  @brief This function waits to receive multiple messages
 *         from a processor on another node.
 *
 *  @param[in]  i_pTarget       - The target containing the node comm registers.
 *                                Can't be nullptr
 *  @param[in]  i_linkId        - Link Id Message is expected from
 *  @param[in]  i_mboxId        - Mailbox Id Message is expected from
 *  @param[in]  i_sentNode      - Node expected to have sent the message
 *  @param[in]  i_transferType  - Expected Transfer Message Type to receive
 *                                Failure if different type is received
 *  @param[out] o_data          - Data received
 *  @param[out] o_dataSize      - Size of Data received
 *
 *  @note - While this function will dynamically create o_data buffer of size
 *          o_dataSize, the caller is responsible for deleting this buffer.
 *          If an error is returned, o_data will be nullptr and o_dataSize
 *          will be zero.
 *
 *  @note o_dataSize is verified to match i_transferType when applicable
 *        based on TransferSizeMap.
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommTransferRecv(TARGETING::Target* i_pTarget,
                                uint8_t i_linkId,
                                uint8_t i_mboxId,
                                uint8_t i_sentNode,
                                node_comm_transfer_types_t i_transferType,
                                uint8_t*& o_data,
                                size_t & o_dataSize);

} // end NODECOMM namespace

} // end SECUREBOOT namespace

#endif // End __NODE_COMM_TRANSFER_H

