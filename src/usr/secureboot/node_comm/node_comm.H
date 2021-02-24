/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2021                        */
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
#ifndef __NODE_COMM_H
#define __NODE_COMM_H

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <time.h>
#include <devicefw/userif.H>
#include <trace/interface.H>
#include <secureboot/nodecommif.H>
#include "../trusted/trustedboot.H"
#include <secureboot/trustedbootif.H>
#include "../trusted/trustedTypes.H"
#include <util/impl/unique_ptr.H>

// ----------------------------------------------
// Defines
// ----------------------------------------------
#define NODECOMM_TRACE_NAME "NODECOMM"
extern trace_desc_t* g_trac_nc;

// Switch from TRACDCOMP to TRACFCOMP to enable unit test tracing
#define TRACUTCOMP(args...) TRACDCOMP(args)

// Use if there is an issue getting random number from a functional TPM
#define NODE_COMM_DEFAULT_NONCE 0xFFFFFFFFFFFFFFFF

namespace SECUREBOOT
{

namespace NODECOMM
{

/*
 * Struct used to hold data about iohs instances
 */
struct iohs_instances_t
{
    TARGETING::Target* myIohsTarget = nullptr;
    uint8_t  myIohsInstance = 0;
    uint8_t  myIohsRelLink  = 0;
    uint8_t  myNodeInstance = 0;

    // Expect data to be received on the PEER_PATH instances
    uint8_t  peerNodeInstance = 0;
    uint8_t  peerProcInstance = 0;
    uint8_t  peerIohsInstance = 0;
};

/*
 * Union used to hold the 3-tuple of information passed between the nodes -
 *       master node to every sibling node, and all those sibling nodes
 *       back to the master node
 */
union msg_format_t
{
    uint64_t value;
    struct
    {
        uint64_t origin_linkId   : 4;  // relative to the originator
        uint64_t receiver_linkId : 4;  // relative to the receiver
        uint64_t nonce           : 56; // a cryptographically strong random
                                       // nummber requested from the TPM
    } PACKED;
};

/*
 * @brief Node Comm Registers - see above for description
 */
enum node_comm_registers_t : uint64_t
{
    NCDD_REG_FIR          =  0x10011800,
    NCDD_REG_FIR_WOX_AND  =  0x10011801,
    NCDD_REG_FIR_WOX_OR   =  0x10011802,

    NCDD_REG_CTRL         =  0x1001182E,
    NCDD_REG_DATA         =  0x1001182F,

    //MailBox Registers:
    NCDD_REG_LINK_MBOX_00  =  0x10011830, //(secure)

/* These registers are calculated by getLinkMboxReg() below
   NCDD_REG_LINK_MBOX_01  =  0x10011831,
   NCDD_REG_LINK_MBOX_10  =  0x10011832, //(secure)
   NCDD_REG_LINK_MBOX_11  =  0x10011833,
   NCDD_REG_LINK_MBOX_20  =  0x10011834, //(secure)
   NCDD_REG_LINK_MBOX_21  =  0x10011835,
   NCDD_REG_LINK_MBOX_30  =  0x10011836, //(secure)
   NCDD_REG_LINK_MBOX_31  =  0x10011837,
*/
};

// Each hex number is an encoding of the ascii string
// corresponding to the name given below.
typedef enum : uint64_t
{
    MSTNOTPM = 0x4d53544e4f54504d,
    NDNOTPM_ = 0x4e444e4f54504d5f,
    MASTERQ_ = 0x4d4153545245515f,
    NODEQUOT = 0x4e4f444551554f54,
    INVALID_ = 0x494e56414c49445f,
} NCEyeCatcher_t;

// Enhanced multinode comm master node request blob
struct _MasterQuoteRequestBlob
{
    SECUREBOOT::NODECOMM::NCEyeCatcher_t EyeCatcher; // master node eye catcher
    TRUSTEDBOOT::MasterTpmNonce_t MasterNonce; //32-byte nonce
    TRUSTEDBOOT::TPML_PCR_SELECTION PcrSelect; // PCRs to read
} PACKED;
typedef struct _MasterQuoteRequestBlob MasterQuoteRequestBlob;

/**
 *  @brief Calculate Link Mailbox Base Register based on linkId and mboxId
 *
 *  @param[in] i_linkId - Link Id of the operation
 *  @param[in] i_mboxId - Mailbox Id of the operation
 *
 *  @return uint64_t - Calculated Link Mailbox Register Base Address
 *  @note   Returned value is Base Address - see node_comm_registers_t
 */
inline uint64_t getLinkMboxReg(const uint8_t i_linkId,
                               const uint8_t i_mboxId)
{
    return NCDD_REG_LINK_MBOX_00 + (2*i_linkId) + i_mboxId;
}

/**
 *  @brief Calculate Secure LinkId and MailboxId based on IOHS Instance
 *
 *  @param[in]  i_iohsInstance - IOHS instance of the operation
 *  @param[in]  i_iohsRelLink  - Relative Link (0 or 1) of the IOHS instance
 *  @param[out] o_linkId       - Link Id of the OBUS instance
 *  @param[out] o_mboxId       - Mailbox Id of the OBUS instance
 *
 *  @return void
 */
inline void getLinkMboxFromIohsInstance(const uint8_t i_iohsInstance,
                                        const uint8_t i_iohsRelLink,
                                        uint8_t & o_linkId,
                                        uint8_t & o_mboxId)
{
    // For each IOHS instance there are 2 links and 2 mailboxes
    // and the Secure Link and Mailbox is always the relative 'L0M0'
    // of these 4 possibilities
    o_linkId = (2*i_iohsInstance) + i_iohsRelLink;
    o_mboxId = 0;

    return;
}


enum node_comm_fir_reg_helpers_t : uint64_t
{
    NCDD_FIR_ATTN_MASK = 0x0000000FF0000000,
    NCDD_START_OF_ATTN_BITS = 0x0000000800000000,
};


/**
 *  @brief Calculate Link Mailbox FIR Register Attention Bit Mask
 *         based on linkId and mboxId
 *
 *  @param[in] i_linkId - Link Id of the operation
 *  @param[in] i_mboxId - Mailbox Id of the operation
 *
 *  @return uint64_t - Calculated FIR Register Attention Bit Mask
 */
inline uint64_t getLinkMboxFirAttnBit(const uint8_t i_linkId,
                                      const uint8_t i_mboxId)
{
    return (NCDD_START_OF_ATTN_BITS >> ((2*i_linkId) + i_mboxId));
}


/**
 *  @brief This function waits for the processor to receive a message
 *         from a processor on another node.
 *
 *  @param[in]  i_pTarget - PAUC target to look for attentions on
 *                          Can't be nullptr
 *  @param[in]  i_linkId  - Expected Link Id that received the message
 *  @param[in]  i_mboxId  - Expected Mailbox Id that received the message
 *  @param[out] o_data    - Data received
 *
 *  @note If message received on different LinkId/MailboxId than i_linkId and
 *        i_mboxId then an error will be created
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommRecvMessage(TARGETING::Target* i_pTarget,
                               uint8_t i_linkId,
                               uint8_t i_mboxId,
                               uint64_t & o_data);

/**
 *  @brief This function sends a message from the processor of
 *         the current node to a processor on another node.
 *
 *  @param[in] i_pTarget  - PAUC target sending message
 *                          Can't be nullptr
 *  @param[in] i_data     - Data to be sent
 *  @param[in] i_linkId   - Link Id Message is sent from
 *  @param[in] i_mboxId   - Mailbox Id Message is sent from
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommSendMessage(TARGETING::Target* i_pTarget,
                               uint64_t i_data,
                               uint8_t i_linkId,
                               uint8_t i_mboxId);


/**
 *  @brief Map Attention Bits in FIR Register to specific Link Mailbox
 *
 *  @param[in] i_pTarget     PAUC target to look for attentions on
 *                           Can't be nullptr
 *  @param[out] o_attn_found Returns true if attention was found;
 *                           otherwise false
 *  @param[out] o_linkId     Link Id attention was found on
 *  @param[out] o_mboxId     Mbox Id attention was found on
 *  @note - o_linkId and o_mboxId are only set/valid if o_attn_found is true
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommMapAttn(TARGETING::Target* i_pTarget,
                           bool & o_attn_found,
                           uint8_t & o_linkId,
                           uint8_t & o_mboxId);
/**
 *  @brief Return the status of whether or not the 2 links connected to the
 *         IOHS Chiplet are trained
 *
 *  @param[in] i_pIohs           Target representing IOHS Chiplet
 *                               Can't be nullptr
 *  @param[out] o_link0_trained  True if link0 is trained; otherwise false
 *  @param[out] o_link1_trained  True is link1 is trained; otherwise false
 *  @param[out] o_fir_data       The SCOM data read from the FIR register
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t getIohsTrainedLinks(TARGETING::Target* i_pIohs,
                               bool & o_link0_trained,
                               bool & o_link1_trained,
                               uint64_t & o_fir_data);

/**
 * @brief Add FFDC for the target to an error log
 *
 * @param[in] i_pTarget    PAUC target used to collect info from
 * @param[in,out] io_log   Error Log to add FFDC to
 *
 * @return void
 */
void getNodeCommFFDC(TARGETING::Target* i_pTarget,
                     errlHndl_t & io_log);

/**
 * @brief Adds a bus callout to the error log by determining the bus and the two
 *        targets associated with it
 *
 * @param[in] i_pTarget    PAUC target used to collect info from
 *                         Can't be nullptr
 * @param[in] i_linkId     Link ID associated with i_pProc
 * @param[in,out] io_log   Error Log to add FFDC to
 * @param[in] i_priority   Optional: Callout Priority (defaulted to HIGH)
 *
 * @return void
 */
void addNodeCommBusCallout(
    TARGETING::Target* i_pTarget,
    uint8_t i_linkId,
    errlHndl_t & io_log,
    HWAS::callOutPriority i_priority = HWAS::SRCI_PRIORITY_HIGH);

/**
 *  @brief This function logs a nonce to all available TPMs on the node by
 *         extending it to a specific PCR.
 *
 *  @param[in]  i_nonce - The nonce to be logged/extended
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommLogNonce(uint64_t & i_nonce);

/**
 *  @brief This function generates a nonce by calling GetRandom on an
 *         available TPM.
 *
 *  @param[out] o_nonce - The nonce that is generated
 *  @note       Nonce is only valid if the operation is successful
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommGetRandom(uint64_t & o_nonce);

/**
 * @brief A function to generate a master quote request blob that will be sent
 *        to the slave node(s) as part of the node communication protocol. The
 *        master request consists of an eye catcher, 32-byte TPM-generated
 *        random number, and a PCR selection structure.
 * @param[out] o_request the output master quote request data structure
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t nodeCommGenMasterQuoteRequest(MasterQuoteRequestBlob* o_request);

/**
 * @brief A function to create the slave node quote response that consists of
 *        eye catcher, slave node ID, quote and signature data (represented by
 *        the QuoteDataOut structure), the contents of PCRs 0-7, the
 *        Attestation Key Certificate returned from TPM, the size
 *        and the contents of the TPM log
 * @param[in] i_request the master node request structure
 * @param[out] o_size the size of the slave quote
 * @param[out] o_resp the slave quote in binary format
 * @note If an error occurs within the function, the o_resp will only have
 *       an eye catcher indicating that the slave quote is bad.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t nodeCommGenSlaveQuoteResponse(const MasterQuoteRequestBlob* const i_request,
                                         size_t& o_size,
                                         std::unique_ptr<uint8_t>& o_resp);

} // end NODECOMM namespace

} // end SECUREBOOT namespace

#endif // End __NODE_COMM_H

