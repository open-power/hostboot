/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_exchange_helper.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/**
 * @file  node_comm_exchange_helper.C
 * @brief Contains the implementations of the node comm helper functions and
 *        classes.
 */

#include "node_comm_exchange_helper.H"
#include "node_comm_transfer.H"
#include <secureboot/secure_reasoncodes.H>
#include <sys/time.h>
#include <isteps/istepHelperFuncs.H>
#include <secureboot/trustedbootif.H>

namespace SECUREBOOT
{

namespace NODECOMM
{

mutex_t NodeCommExchangeQuotes::iv_quoteMutex = MUTEX_INITIALIZER;
mutex_t NodeCommExchange::iv_errorMutex = MUTEX_INITIALIZER;

/**
 * @brief Helper function to capture an error safely
 *
 * @param[in] i_errl the error to capture
 */
void NodeCommExchange::handleError(errlHndl_t i_errl)
{
    errlHndl_t l_poisonTpmErr = TRUSTEDBOOT::poisonAllTpms();
    if(l_poisonTpmErr)
    {
        if(i_errl)
        {
            l_poisonTpmErr->plid(i_errl->plid());
        }
        TRACFCOMP(g_trac_nc,ERR_MRK"NodeCommExchange::handleError(): Could not poison TPMs");
        if(!TRUSTEDBOOT::isTpmRequired())
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"NodeCommExchange::handleError(): TPM is not required, setting errl EID 0x%x to Informational",
                      l_poisonTpmErr->eid());
            l_poisonTpmErr->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        }
        errlCommit(l_poisonTpmErr, SECURE_COMP_ID);
    }

    mutex_lock(&iv_errorMutex);
    if(!TRUSTEDBOOT::isTpmRequired())
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"NodeCommExchange::handleError(): TPM is not required; changing the severity of error 0x%x to INFORMATIONAL",
                  i_errl->eid());
        i_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
        // Don't propagate informational errors to istep
        errlCommit(i_errl, SECURE_COMP_ID);
    }
    else
    {
        captureError(i_errl, *iv_istepError, SECURE_COMP_ID);
    }
    mutex_unlock(&iv_errorMutex);
}

/**
 * @brief Helper function to get the link and mailbox IDs for this node
 *        and the peer node from the IOHS info provided.
 *
 * @param[in] i_iohsInstance the IOHS info of the current node and the
 *            peer
 * @param[out] o_myLinkId the resulting link ID of the current node
 * @param[out] o_myMboxId the resulting mailbox ID of the current node
 * @param[out] o_peerLinkId the resulting link ID of the peer node
 * @param[out] o_peerMboxId the resulting mailbox ID of the peer node
 */
void getLinkMboxInfo(const iohs_instances_t& i_iohsInstance,
                     uint8_t& o_myLinkId, uint8_t& o_myMboxId,
                     uint8_t& o_peerLinkId, uint8_t& o_peerMboxId)
{
    // Get the link and mbox ID for the current node
    getLinkMboxFromIohsInstance(i_iohsInstance.myIohsInstance,
                                i_iohsInstance.myIohsRelLink,
                                o_myLinkId,
                                o_myMboxId);

    // Get the link and mbox ID for the peer node
    getLinkMboxFromIohsInstance(i_iohsInstance.peerIohsInstance,
                                // same relative link for peer path:
                                i_iohsInstance.myIohsRelLink,
                                o_peerLinkId,
                                o_peerMboxId);
}

/**
 * @brief Sends a nonce (8-byte random number) to the peer node
 *        of the current node as defined by the IOHS link info.
 *
 * @param[in] i_iohsInstance the IOHS info of the current and peer nodes
 * @param[in] i_nonce the 8-byte nonce to send to the peer node
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t sendNonceToPeer(const iohs_instances_t& i_iohsInstance,
                           const uint64_t& i_nonce)
{
    errlHndl_t l_errl = nullptr;
    uint8_t l_myLinkId = 0;
    uint8_t l_myMboxId = 0;
    uint8_t l_expectedPeerLinkId = 0;
    uint8_t l_expectedPeerMboxId = 0;

    // Get this node and peer's link and mbox info
    getLinkMboxInfo(i_iohsInstance, l_myLinkId, l_myMboxId,
                    l_expectedPeerLinkId, l_expectedPeerMboxId);

    TRACFCOMP(g_trac_nc,INFO_MRK"sendNonceToPeer: "
              "my: linkId=%d, mboxId=%d, IohsInstance=%d. "
              "expected peer: n%d linkId=%d, mboxId=%d, IohsInstance=%d",
              l_myLinkId, l_myMboxId, i_iohsInstance.myIohsInstance,
              i_iohsInstance.peerNodeInstance, l_expectedPeerLinkId,
              l_expectedPeerMboxId, i_iohsInstance.peerIohsInstance);

    // Message data to contain the nonce
    msg_format_t l_msgData;
    l_msgData.value = i_nonce;
    size_t l_msgSize = sizeof(l_msgData.value);

    // The node comm control and data regs live on PAUC parents of IOHS
    TARGETING::Target* l_paucParent =
           TARGETING::getImmediateParentByAffinity(i_iohsInstance.myIohsTarget);

    // Send the message
    l_errl = nodeCommTransferSend(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_SBID,
                                  reinterpret_cast<uint8_t*>(&(l_msgData.value)),
                                  l_msgSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"sendNonceToPeer: Could not send message to the peer node %d",
                  i_iohsInstance.peerNodeInstance);
    }

    return l_errl;
}

/**
 * @brief Receives a nonce (8-byte random number) from the peer node
 *        of the current node as defined by the IOHS link info
 *
 * @param[in] i_iohsInstance the IOHS info of the current and peer nodes
 * @param[out] o_nonce the 8-byte nonce received from the peer node (0 in case
 *             of an error)
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t receiveNonceFromPeer(const iohs_instances_t& i_iohsInstance,
                                uint64_t& o_nonce)
{
    errlHndl_t l_errl = nullptr;
    // Pointer to buffer used for receiving data from nodeCommTransferRecv()
    uint8_t * l_dataRcvBuffer = nullptr;
    uint8_t l_myLinkId = 0;
    uint8_t l_myMboxId = 0;
    uint8_t l_expectedPeerLinkId = 0;
    uint8_t l_expectedPeerMboxId = 0;

    // Get this node and peer's link and mbox info
    getLinkMboxInfo(i_iohsInstance, l_myLinkId, l_myMboxId,
                    l_expectedPeerLinkId, l_expectedPeerMboxId);

    TRACFCOMP(g_trac_nc,INFO_MRK"receiveNonceFromPeer: "
              "my: linkId=%d, mboxId=%d, IohsInstance=%d. "
              "expected peer: n%d linkId=%d, mboxId=%d, IohsInstance=%d",
              l_myLinkId, l_myMboxId, i_iohsInstance.myIohsInstance,
              i_iohsInstance.peerNodeInstance, l_expectedPeerLinkId,
              l_expectedPeerMboxId, i_iohsInstance.peerIohsInstance);

    // The node comm control and data regs live on PAUC parents of IOHS
    TARGETING::Target* l_paucParent =
           TARGETING::getImmediateParentByAffinity(i_iohsInstance.myIohsTarget);
    size_t l_msgSize = sizeof(o_nonce);
    l_errl = nodeCommTransferRecv(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_SBID,
                                  l_dataRcvBuffer,
                                  l_msgSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"receiveNonceFromPeer: Could not get nonce from peer node %d",
                  i_iohsInstance.peerNodeInstance);
        o_nonce = NODE_COMM_DEFAULT_NONCE;
    }
    else
    {
        // If no err is returned, l_dataRcvBuffer should be valid, but do a
        // sanity check here to be certain
        assert(l_dataRcvBuffer!=nullptr,"receiveNonceFromPeer: l_dataRcvBuffer returned as nullptr");
        memcpy(&o_nonce, l_dataRcvBuffer, l_msgSize);
    }
    return l_errl;
}

/**
 * @brief Performs nonce exchange between two nodes as defined by internal iv_iohsInstance
 *        variable. If the current node's ID is lower than the peer's, then the current node
 *        will send its nonce first, and the peer node will receive the nonce first. Then
 *        the order reverses.
 */
void NodeCommExchangeNonces::operator()()
{
    errlHndl_t l_errl = nullptr;

    // Create a msg_format_t structure so that we can populate the link and node
    // info into the nonce later.
    msg_format_t l_myNonce, l_peerNonce;
    l_myNonce.value = 0;
    l_peerNonce.value = 0;

    TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeNonces: This thread from node %d to node %d",
              iv_iohsInstance.myNodeInstance, iv_iohsInstance.peerNodeInstance);

    l_errl = nodeCommGetRandom(l_myNonce.value);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: could not get nonce from the TPM");
        // Commit error and continue to prevent deadlocks
        handleError(l_errl);
        l_myNonce.value = NODE_COMM_DEFAULT_NONCE;
    }
    else
    {
        uint8_t l_mboxIdUnused = 0;
        uint8_t l_myLinkId = 0;
        uint8_t l_peerLinkId = 0;

        // Incorporate our link ID and the link ID of the receiver into the nonce
        getLinkMboxInfo(iv_iohsInstance,
                        l_myLinkId, l_mboxIdUnused,
                        l_peerLinkId, l_mboxIdUnused);

        l_myNonce.origin_linkId = l_myLinkId;
        l_myNonce.receiver_linkId = l_peerLinkId;
    }

    // Node with lower position sends nonce first and then receives response,
    // while node with higher position receives the nonce first, and then
    // sends its nonce in response.
    if(iv_iohsInstance.myNodeInstance < iv_iohsInstance.peerNodeInstance)
    {
        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeNonces This node (%d) will send nonce first to node %d",
                  iv_iohsInstance.myNodeInstance, iv_iohsInstance.peerNodeInstance);
        l_errl = sendNonceToPeer(iv_iohsInstance, l_myNonce.value);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not send nonce to peer node %d"
                      TRACE_ERR_FMT, iv_iohsInstance.peerNodeInstance,
                      TRACE_ERR_ARGS(l_errl));
            // Commit the error so that we can continue the exchange and prevent
            // deadlocks.
            handleError(l_errl);
        }

        // Wait 100ms to make sure that the other node had a chance to proces
        // the message ack from the previous transaction before requesting a
        // new exchange.
        nanosleep(0, 100*NS_PER_MSEC);

        l_errl = receiveNonceFromPeer(iv_iohsInstance, l_peerNonce.value);

        if(l_errl)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not receive nonce from peer node %d"
                      TRACE_ERR_FMT, iv_iohsInstance.peerNodeInstance,
                      TRACE_ERR_ARGS(l_errl));
            // Commit the error so that we can continue the exchange and prevent
            // deadlocks.
            handleError(l_errl);
        }
    }
    else
    {
        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeNonces This node (%d) will receive nonce first from node %d",
                  iv_iohsInstance.myNodeInstance, iv_iohsInstance.peerNodeInstance);
        l_errl = receiveNonceFromPeer(iv_iohsInstance, l_peerNonce.value);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not receive nonce from peer node %d"
                      TRACE_ERR_FMT, iv_iohsInstance.peerNodeInstance,
                      TRACE_ERR_ARGS(l_errl));
            // Commit the error so that we can continue the exchange and prevent
            // deadlocks.
            handleError(l_errl);
        }

        // Wait 100ms to make sure that the other node had a chance to proces
        // the message ack from the previous transaction before requesting a
        // new exchange.
        nanosleep(0, 100*NS_PER_MSEC);

        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeNonces This node (%d) will now send nonce 0x%x to node %d",
                  iv_iohsInstance.myNodeInstance, l_myNonce.value, iv_iohsInstance.peerNodeInstance);
        l_errl = sendNonceToPeer(iv_iohsInstance, l_myNonce.value);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not send nonce to peer node %d"
                      TRACE_ERR_FMT, iv_iohsInstance.peerNodeInstance,
                      TRACE_ERR_ARGS(l_errl));
            // Commit the error so that we can continue the exchange and prevent
            // deadlocks.
            handleError(l_errl);
        }
    }

    l_errl = nodeCommLogNonce(l_myNonce.value);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not extend this node's nonce into TPM");
        handleError(l_errl);
    }

    l_errl = nodeCommLogNonce(l_peerNonce.value);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"NodeCommExchangeNonces: Could not extend node %d nonce into TPM",
                  iv_iohsInstance.peerNodeInstance);
        handleError(l_errl);
    }
}

/**
 * @brief Helper function to generate a quote request from the peer node, send the quote request to
 *        that node, and receive a quote from the node.
 *
 * @param[in] i_iohsInstance the IOHS information of the peer node
 * @param[out] o_quote the node quote in binary format (received from the peer node)
 * @param[out] o_quoteSize the size of the node quote in bytes
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t requestQuote(const iohs_instances_t& i_iohsInstance, uint8_t*& o_quote, size_t& o_quoteSize)
{
    errlHndl_t l_errl = nullptr;

    do {
    // Generate quote request
    QuoteRequestBlob l_quoteRequest{};
    l_errl = nodeCommGenQuoteRequest(&l_quoteRequest);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"requestQuote: Could not generate quote request"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Send the quote request
    // The node comm control and data regs live on PAUC parents of IOHS
    TARGETING::Target* l_paucParent =
            TARGETING::getImmediateParentByAffinity(i_iohsInstance.myIohsTarget);
    uint8_t l_myLinkId = 0;
    uint8_t l_myMboxId = 0;

    getLinkMboxFromIohsInstance(i_iohsInstance.myIohsInstance,
                                i_iohsInstance.myIohsRelLink,
                                l_myLinkId,
                                l_myMboxId);

    size_t l_quoteRequestSize = sizeof(l_quoteRequest);
    l_errl = nodeCommTransferSend(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_QUOTE_REQUEST,
                                  reinterpret_cast<uint8_t*>(&l_quoteRequest),
                                  l_quoteRequestSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"requestQuote: Could not send quote to peer node %d"
                  TRACE_ERR_FMT, i_iohsInstance.peerNodeInstance, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Get the response (quote) from the other node
    l_errl = nodeCommTransferRecv(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_QUOTE_RESPONSE,
                                  o_quote,
                                  o_quoteSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"requestQuote: Cound not receive response from node %d"
                  TRACE_ERR_FMT, i_iohsInstance.peerNodeInstance, TRACE_ERR_ARGS(l_errl));
        break;
    }

    assert(o_quote, "requestQuote: Response buffer is nullptr!");

    NCEyeCatcher_t* l_eyeCatcher =
        reinterpret_cast<NCEyeCatcher_t*>(o_quote);
    uint32_t* l_peerNodeId = reinterpret_cast<uint32_t*>(o_quote + sizeof(*l_eyeCatcher));

    // Check if the peer node had any TPM issues
    if(*l_eyeCatcher == NDNOTPM_)
    {
        /*@
         * @errortype
         * @reasoncode RC_NC_BAD_QUOTE
         * @moduleid   MOD_NCT_REQUEST_QUOTE
         * @userdata1  Peer node ID
         * @devdesc    Peer node indicated that it encountered an issue during
         *             secure node comm.
         * @custdesc   trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_NCT_REQUEST_QUOTE,
                                         RC_NC_BAD_QUOTE,
                                         *l_peerNodeId,
                                         0,
                                         ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        l_errl->collectTrace(NODECOMM_TRACE_NAME);
        break;
    }

    }while(0);
    return l_errl;
}

/**
 * @brief A helper function to look for a quote request from the peer node, generate the
 *        node quote, and send the quote to the peer node.
 *
 * @param[in] i_iohsInstance IOHS information of the peer node.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t sendQuote(const iohs_instances_t& i_iohsInstance)
{
    errlHndl_t l_errl = nullptr;
    uint8_t* l_dataBuffer = nullptr;
    size_t l_dataSize = 0;

    do {
    uint8_t l_myLinkId = 0;
    uint8_t l_myMboxId = 0;
    getLinkMboxFromIohsInstance(i_iohsInstance.myIohsInstance,
                                i_iohsInstance.myIohsRelLink,
                                l_myLinkId,
                                l_myMboxId);
    // The node comm control and data regs live on PAUC parents of IOHS
    TARGETING::Target* l_paucParent =
           TARGETING::getImmediateParentByAffinity(i_iohsInstance.myIohsTarget);

    // Wait for a request from peer
    l_errl = nodeCommTransferRecv(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_QUOTE_REQUEST,
                                  l_dataBuffer,
                                  l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"sendQuote: Could not receive quote request from peer node %d"
                  TRACE_ERR_FMT, i_iohsInstance.peerNodeInstance, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Make a quote request out of the received data
    QuoteRequestBlob l_quoteRequest{};
    memcpy(&l_quoteRequest, l_dataBuffer, l_dataSize);

    // Re-use the data buffer for the response quote
    free(l_dataBuffer);
    l_dataBuffer = nullptr;

    std::unique_ptr<uint8_t>l_quotePtr = nullptr;

    // Generate a response
    l_errl = nodeCommGenQuoteResponse(&l_quoteRequest,
                                      l_dataSize,
                                      l_quotePtr);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"sendQuote: Could not generate quote to respond to node %d"
                  TRACE_ERR_FMT, i_iohsInstance.peerNodeInstance, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Send the quote to the peer node
    l_errl = nodeCommTransferSend(l_paucParent,
                                  l_myLinkId,
                                  l_myMboxId,
                                  i_iohsInstance.peerNodeInstance,
                                  NCT_TRANSFER_QUOTE_RESPONSE,
                                  l_quotePtr.get(),
                                  l_dataSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"sendQuote: Could not send the quote to peer node %d"
                  TRACE_ERR_FMT, i_iohsInstance.peerNodeInstance, TRACE_ERR_ARGS(l_errl));
        break;
    }

    }while(0);

    return l_errl;
}

/**
 * @brief Perform quote exchange between the nodes on the system. Each node, when communicating with
 *        another node, will act as a requestor once and as a responder once, so in any given system,
 *        each node will send its quote to every other node and will receive quotes from every other
 *        node. If the current node is a lower node ID, it will request the quote first, and then
 *        send its quote to the peer. Otherwise, the opposite happens.
 */
void NodeCommExchangeQuotes::operator()()
{
    errlHndl_t l_errl = nullptr;
    uint8_t* l_data = nullptr;
    size_t l_dataSize = 0;

    do {

    // Node with lower position requests the quote first and then waits for quote request
    // from the peer node, while node with higher position does the procedure in reverse.
    if(iv_iohsInstance.myNodeInstance < iv_iohsInstance.peerNodeInstance)
    {
        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeQuotes: This node will request the quote first from node %d",
                  iv_iohsInstance.peerNodeInstance);
        // Request a quote from the peer node
        l_errl = requestQuote(iv_iohsInstance, l_data, l_dataSize);
        if(l_errl)
        {
            // Capture and continue communicating
            handleError(l_errl);
        }

        // Wait 10ms before sending the quote to make sure the communication protocol
        // has a chance to catch up.
        nanosleep(0, 10*NS_PER_MSEC);

        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeQuotes: This node will now wait for a request from node %d",
                  iv_iohsInstance.peerNodeInstance);
        // Wait for a quote request from the peer node
        l_errl = sendQuote(iv_iohsInstance);
        if(l_errl)
        {
            // Capture and continue communicating
            handleError(l_errl);
        }
    }
    else
    {
        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeQuotes: This node will first wait for a request from node %d",
                  iv_iohsInstance.peerNodeInstance);
        // Look for a request from the peer node
        l_errl = sendQuote(iv_iohsInstance);
        if(l_errl)
        {
            // Capture and continue communicating
            handleError(l_errl);
        }

        // Wait 10ms before sending the quote to make sure the communication protocol
        // has a chance to catch up.
        nanosleep(0, 10*NS_PER_MSEC);

        // Now request a quote from the peer node
        TRACFCOMP(g_trac_nc, INFO_MRK"NodeCommExchangeQuotes: This node will now request the quote from node %d",
                  iv_iohsInstance.peerNodeInstance);
        l_errl = requestQuote(iv_iohsInstance, l_data, l_dataSize);
        if(l_errl)
        {
            // Capture and continue communicating
            handleError(l_errl);
        }
    }

    // Grab the quote mutex
    mutex_lock(&iv_quoteMutex);
    // Add the recieved quote to the list
    quoteInfo_t l_quoteInfo {};
    l_quoteInfo.quoteData = new uint8_t[l_dataSize];
    l_quoteInfo.quoteSize = l_dataSize;
    memcpy(l_quoteInfo.quoteData, l_data, l_dataSize);
    iv_quotes->push_back(l_quoteInfo);
    mutex_unlock(&iv_quoteMutex);

    TRACDBIN(g_trac_nc, "Quote received:", l_data, l_dataSize);
    } while(0);

    free(l_data);
    l_data = nullptr;
}

} // namespace NODECOMM
} // namespace SECUREBOOT
