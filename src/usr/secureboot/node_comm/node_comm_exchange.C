/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_exchange.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
 * @file node_comm_exchange.C
 *
 * @brief Runs the procedure for the drawers/nodes to exchange messages
 *        over the ABUS Link Mailbox facility
 *
 */

// ----------------------------------------------
// Includes
// ----------------------------------------------
#include <string.h>
#include <algorithm>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <errl/errludstring.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/nodecommif.H>
#include <secureboot/trustedbootif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>
#include <sys/internode.h>
#include <util/misc.H>
#include <config.h>

#include "node_comm.H"
#include "node_comm_transfer.H"

#include <secureboot/service.H>
#include <securerom/contrib/sha512.H>

#include "../trusted/trustedTypes.H"
#include "../trusted/tpmLogMgr.H"

// ----------------------------------------------
// Defines
// ----------------------------------------------
// Use if there is an issue getting random number from a functional TPM
#define NODE_COMM_DEFAULT_NONCE 0xFFFFFFFFFFFFFFFF

using   namespace   TARGETING;

namespace SECUREBOOT
{

namespace NODECOMM
{

/*
 * Struct used to collect data about current node's master proc and other info
 */
struct master_proc_info_t
{
    TARGETING::Target* tgt = nullptr;
    uint8_t     procInstance = 0;
    uint8_t     nodeInstance = 0;
};


/*
 * Struct used to hold data about obus instances
 */
struct obus_instances_t
{
    uint8_t  myObusInstance = 0;
    uint8_t  myObusRelLink  = 0;

    // Expect data to be received on the PEER_PATH instances
    uint8_t  peerNodeInstance = 0;
    uint8_t  peerProcInstance = 0;
    uint8_t  peerObusInstance = 0;
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
errlHndl_t nodeCommAbusGetRandom(uint64_t & o_nonce)
{
    errlHndl_t err = nullptr;
    o_nonce = NODE_COMM_DEFAULT_NONCE;
    Target* tpm_tgt = nullptr;
    TargetHandleList tpmTargetList;

    TRACUCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusGetRandom:");

    do
    {

    // Get all possible functional TPMs
    TRUSTEDBOOT::getTPMs(tpmTargetList);

    if (tpmTargetList.size() == 0)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusGetRandom: no functional "
                  "TPMs found - tpmTargetList.size() = %d - Committing "
                  "predictive error. Continuing using default nonce=0x%.16llX",
                  tpmTargetList.size(), o_nonce);

        /*@
         * @errortype
         * @reasoncode       RC_NCEX_NO_FUNCTIONAL_TPMS
         * @moduleid         MOD_NCEX_GET_RANDOM
         * @userdata1        <Unused>
         * @userdata2        <Unused>
         * @devdesc          No functional TPMs were found
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       MOD_NCEX_GET_RANDOM,
                                       RC_NCEX_NO_FUNCTIONAL_TPMS,
                                       0,
                                       0,
                                       true /*Add HB SW Callout*/ );

        // err commited outside of do-while loop below

        // break here to skip calling GetRandom() below
        break;
    }

    // Use first of functional TPM target list
    // @TODO RTC 203642 Update this to use Primary TPM
    tpm_tgt = tpmTargetList[0];

    // This function call requires the CONFIG check for compilation purposes,
    // but no extra error handling is needed as it should not have gotten this
    // far if CONFIG_TPMDD wasn't set
#ifdef CONFIG_TPMDD
    err = TRUSTEDBOOT::GetRandom(tpm_tgt,
                                 sizeof(o_nonce),
                                 reinterpret_cast<uint8_t*>(&o_nonce));
#endif
    if (err)
    {
        // Reset just to make sure above call didn't change it
        o_nonce = NODE_COMM_DEFAULT_NONCE;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusGetRandom: GetRandom "
                  "returned a fail for TPM 0x%.08X. Commiting err: "
                  TRACE_ERR_FMT
                  ". Using default nonce=0x%.16llX",
                  get_huid(tpm_tgt),
                  TRACE_ERR_ARGS(err),
                  o_nonce);
        // err commited outside of do-while loop below

        // break to be safe in case code gets added later
        break;
    }

    } while( 0 );

    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);
        err->collectTrace(TRBOOT_COMP_NAME);
        errlCommit(err, SECURE_COMP_ID);
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusGetRandom: "
              "nonce=0x%.16llX from TPM=0x%.08X. "
              TRACE_ERR_FMT,
              o_nonce, get_huid(tpm_tgt),
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusGetRandom

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
errlHndl_t nodeCommAbusLogNonce(uint64_t & i_nonce)
{
    errlHndl_t err = nullptr;

    TRACUCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusLogNonce: i_nonce=0x%.16llX",
              i_nonce);

    do
    {

    // Extend the nonce asychronously to all available TPMs
    uint8_t l_digest[sizeof(i_nonce)]={0};
    memcpy(l_digest, &i_nonce, sizeof(i_nonce));

    err = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                 TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                 l_digest,
                                 sizeof(uint64_t),
                                 "Node Nonce");
    if (err)
    {
       TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusLogNonce: pcrExtend "
                  "returned a fail: "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(err));
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusLogNonce: i_nonce=0x%.16llX. "
              TRACE_ERR_FMT,
              i_nonce,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusLogNonce

/**
 * @brief A function to create the slave node response quote that consists of
 *        eye catcher, slave node ID, quote and signature data (represented by
 *        the QuoteDataOut structure), the contents of PCRs 0-7, the
 *        Attestation Key Certificate returned from TPM, the size
 *        and the contents of the TPM log
 * @param[in] i_masterEyeCatcher the eye catcher from master node that indicates
 *            the state of master node's TPM. (If master node's TPM is in bad
 *            state, the slave node won't generate the full quote, as remote
 *            attestation is not possible)
 * @param[in] i_nonce the 32-byte nonce generated by the master node
 * @param[in] i_pcrSelect the PCR selection structure
 * @param[out] o_size the size of the slave quote
 * @param[out] o_resp the slave quote in binary format
 * @note Assuming CONFIG_TPMDD is compiled in, o_resp is always allocated
 *       dynamically in this function, and it is the responsibility of the
 *       calller to delete it after the function returns. If an error occurs
 *       within the function, the o_resp will only have an eye catcher
 *       indicating that the slave quote is bad.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t nodeCommGenSlaveResponseQuote(const SECUREBOOT::NODECOMM::NCEyeCatcher_t i_masterEyeCatch,
                                         const TRUSTEDBOOT::MasterTpmNonce_t* const i_nonce,
                                         const TRUSTEDBOOT::TPML_PCR_SELECTION* const i_pcrSelect,
                                         size_t& o_size,
                                         uint8_t*& o_resp)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc, ENTER_MRK"nodeCommGenSlaveResponseQuote");
    bool l_tpmRequired = TRUSTEDBOOT::isTpmRequired();
    bool l_errorOccurred = false;

    TRUSTEDBOOT::QuoteDataOut l_quoteData;
    uint32_t l_nodeId = TARGETING::UTIL::getCurrentNodePhysId();
    do {

    o_resp = nullptr;

    TARGETING::Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);
    if(!l_primaryTpm ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().functional ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().present)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: primary TPM not found or not functional");
        l_errorOccurred = true;
        break;
    }


    // If Master indicated that there is an issue with its TPM: Case 1: If the
    // TPM Required policy is on, terminate the boot; Case 2: If TPM required
    // policy is off, send back a token indicating that no nodecomm TPM commands
    // have been performed (remote attestation is not possible with bad master
    // TPM); do not fail the boot.
    if(i_masterEyeCatch == SECUREBOOT::NODECOMM::MSTNOTPM)
    {
        l_errorOccurred = true;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: Master indicated an issue with secure nodecomm (master eye catcher is MSTNOTPM)");
        // Case 1
        if(l_tpmRequired)
        {
            /* @
             * @errortype
             * @reasoncode RC_NC_BAD_MASTER_TPM
             * @moduleid   MOD_NC_GEN_SLAVE_RESPONSE
             * @userdata1  <unused>
             * @userdata2  <unused>
             * @devdesc    The system policy is set to not allow boot without a
             *             functioning TPM, but the system's master node
             *             indicated that its TPM is compromised. This slave
             *             node must terminate the boot process.
             * @custdesc   Trustedboot failure
             */
             l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_NC_GEN_SLAVE_RESPONSE,
                                              RC_NC_BAD_MASTER_TPM);
            // It is unlikely that there is an issue with this node, but collect
            // the logs anyway for ease of debug.
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(TRBOOT_COMP_NAME);
            l_errl->collectTrace(NODECOMM_TRACE_NAME);


            break;
        }
        // Case 2
        // The error condition will be handled below in the if branch that
        // checks l_errorOccurred
    }
    else if(i_masterEyeCatch != SECUREBOOT::NODECOMM::MASTERQ_)
    {
        l_errorOccurred = true;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: Invalid master eye catcher received: 0x%x", i_masterEyeCatch);
        if(l_tpmRequired)
        {
            /* @
             * @errortype
             * @reasoncode RC_NC_BAD_MASTER_EYE_CATCH
             * @moduleid   MOD_NC_GEN_SLAVE_RESPONSE
             * @userdata1  Eye catcher received from master
             * @devdesc    Master node sent an unrecognized eye catcher
             * @custdesc   Trustedboot failure
             */
             l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                              MOD_NC_GEN_SLAVE_RESPONSE,
                                              RC_NC_BAD_MASTER_EYE_CATCH,
                                              i_masterEyeCatch);
            // It is unlikely that there is an issue with this node, but collect
            // the logs anyway for ease of debug.
            l_errl->collectTrace(NODECOMM_TRACE_NAME);
            l_errl->collectTrace(TRBOOT_COMP_NAME);
            l_errl->collectTrace(SECURE_COMP_NAME);
        }
        break;
    }

    // Step 1: Recreate node Attestation Key (AK)
    l_errl = TRUSTEDBOOT::createAttestationKeys(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not create attestation keys");
        break;
    }

    TRUSTEDBOOT::TPM2B_MAX_NV_BUFFER l_AKCert;
    // Step 2: Read the AK Certificate
    l_errl = TRUSTEDBOOT::readAKCertificate(l_primaryTpm, &l_AKCert);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not read AK certificate");
        break;
    }

    // Hash the AK Certificate and extend the hash into PCR1
    SHA512_t l_AKCertHash = {0};
    hashBlob(l_AKCert.buffer,
             sizeof(l_AKCert.buffer),
             l_AKCertHash);

    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                    TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                    l_AKCertHash,
                                    sizeof(l_AKCertHash),
                                    "AK Certificate Hash"); // @TODO RTC 203644 this should be a full AK certificate in binary
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not extend AK Certificate hash to TPM");
        break;
    }

    l_quoteData.data = new uint8_t[1 * KILOBYTE]{};// the actual data size will
                                                   // be smaller than 1KB
    // Step 3: Generate quote and signature data (presented as binary data in
    // the QuoteDataOut structure)
    l_errl = TRUSTEDBOOT::generateQuote(l_primaryTpm,
                                        i_nonce,
                                        &l_quoteData);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not generate TPM quote");
        break;
    }

    // Step 4: Flush the AK from the TPM
    l_errl = TRUSTEDBOOT::flushContext(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not flush TPM context");
        break;
    }

    // @TODO RTC 203645 use the i_pcrSelect to read selected PCRs
    // Step 5: Read PCRs 0-7
    uint32_t l_pcrCount = TRUSTEDBOOT::FW_USED_PCR_COUNT;
    TRUSTEDBOOT::TPM_Pcr l_pcrRegs[l_pcrCount] = {
                                                  TRUSTEDBOOT::PCR_0,
                                                  TRUSTEDBOOT::PCR_1,
                                                  TRUSTEDBOOT::PCR_2,
                                                  TRUSTEDBOOT::PCR_3,
                                                  TRUSTEDBOOT::PCR_4,
                                                  TRUSTEDBOOT::PCR_5,
                                                  TRUSTEDBOOT::PCR_6,
                                                  TRUSTEDBOOT::PCR_7
                                                 };
    size_t l_digestSize =
                        TRUSTEDBOOT::getDigestSize(TRUSTEDBOOT::TPM_ALG_SHA256);

    // An array of PCR Digest structures to hold the contents of PCRs 0-7
    TRUSTEDBOOT::TPM2B_DIGEST l_pcrDigests[l_pcrCount];
    for(const auto l_pcr : l_pcrRegs)
    {
        l_pcrDigests[l_pcr].size = l_digestSize;
        l_errl = TRUSTEDBOOT::pcrRead(l_primaryTpm,
                                      l_pcr,
                                      TRUSTEDBOOT::TPM_ALG_SHA256,
                                      l_digestSize,
                                      l_pcrDigests[l_pcr].buffer);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not read PCR%d", l_pcr);
            break;
        }
    }
    if(l_errl)
    {
        break;
    }

    // Step 6: Read out the primary TPM's Log and copy it into the quote
    TRUSTEDBOOT::TpmLogMgr* l_primaryLogMgr =
                                        TRUSTEDBOOT::getTpmLogMgr(l_primaryTpm);
    if(!l_primaryLogMgr)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveResponseQuote: could not fetch primary TPM's log");
        /*@
         * @errortype
         * @reasoncode RC_NC_NO_PRIMARY_TPM_LOG
         * @moduleid   MOD_NC_GEN_SLAVE_RESPONSE
         * @userdata1  Primary TPM HUID
         * @devdesc    Could not fetch primary TPM's Log
         * @custdes    Trustedboot failure
         */
        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_NC_GEN_SLAVE_RESPONSE,
                                         RC_NC_NO_PRIMARY_TPM_LOG,
                                         get_huid(l_primaryTpm));
        l_errl->collectTrace(NODECOMM_TRACE_NAME);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        break;
    }
    uint32_t l_logSize = TRUSTEDBOOT::TpmLogMgr_getLogSize(l_primaryLogMgr);
    const uint8_t* l_logPtr =
                         TRUSTEDBOOT::TpmLogMgr_getLogStartPtr(l_primaryLogMgr);

    SECUREBOOT::NODECOMM::NCEyeCatcher_t l_goodEyeCatch =
                                                 SECUREBOOT::NODECOMM::NODEQUOT;

    // Figure out the size of the slave quote
    o_size = sizeof(l_goodEyeCatch) +
             sizeof(l_nodeId) +
             l_quoteData.size +
             sizeof(l_pcrCount) +
             sizeof(l_pcrDigests) +
             sizeof(l_AKCert) +
             sizeof(l_logSize) +
             l_logSize;

    // Allocate the output
    o_resp = new uint8_t[o_size] {};
    // Now populate the output
    size_t l_currentOffset = 0;

    // First the good eye catcher
    memcpy(o_resp, &l_goodEyeCatch, sizeof(l_goodEyeCatch));
    l_currentOffset += sizeof(l_goodEyeCatch);
    // Now the node ID
    memcpy(o_resp + l_currentOffset, &l_nodeId, sizeof(l_nodeId));
    l_currentOffset += sizeof(l_nodeId);
    // The TPM quote & signature information (both are included in the TPM
    // quote blob)
    memcpy(o_resp + l_currentOffset, l_quoteData.data, l_quoteData.size);
    l_currentOffset += l_quoteData.size;
    // The number of PCRs read
    memcpy(o_resp + l_currentOffset, &l_pcrCount, sizeof(l_pcrCount));
    l_currentOffset += sizeof(l_pcrCount);
    // PCR0-7 contents
    memcpy(o_resp + l_currentOffset,
           reinterpret_cast<uint8_t*>(&l_pcrDigests),
           sizeof(l_pcrDigests));
    l_currentOffset += sizeof(l_pcrDigests);
    // AK certificate size
    memcpy(o_resp + l_currentOffset, &l_AKCert.size, sizeof(l_AKCert.size));
    l_currentOffset += sizeof(l_AKCert.size);
    // Actual AK certificate
    memcpy(o_resp + l_currentOffset, l_AKCert.buffer, sizeof(l_AKCert.buffer));
    l_currentOffset += sizeof(l_AKCert.buffer);
    // The length of the TPM log
    memcpy(o_resp + l_currentOffset, &l_logSize, sizeof(l_logSize));
    l_currentOffset += sizeof(l_logSize);
    // The actual TPM log
    memcpy(o_resp + l_currentOffset, l_logPtr, l_logSize);

    } while(0);

    if(l_quoteData.data)
    {
        delete[](l_quoteData.data);
        l_quoteData.data = nullptr;
    }

    if(l_errl || l_errorOccurred)
    {
        // There was some error; allocate the output buffer just big enough
        // for an eye catcher and node ID
        SECUREBOOT::NODECOMM::NCEyeCatcher_t l_badEyeCatcher =
                                                 SECUREBOOT::NODECOMM::NDNOTPM_;
        o_resp = new uint8_t[sizeof(l_badEyeCatcher) + sizeof(l_nodeId)]{};
        memcpy(o_resp, &l_badEyeCatcher, sizeof(l_badEyeCatcher));
        memcpy(o_resp + sizeof(l_badEyeCatcher), &l_nodeId, sizeof(l_nodeId));
        o_size = sizeof(l_badEyeCatcher) + sizeof(l_nodeId);

        errlHndl_t l_poisonTpmErr = TRUSTEDBOOT::poisonAllTpms();
        if(l_poisonTpmErr)
        {
            if(l_errl)
            {
                l_poisonTpmErr->plid(l_errl->plid());
            }
            errlCommit(l_poisonTpmErr, SECURE_COMP_ID);
        }
    }

    if(l_errl)
    {
        if(!l_tpmRequired)
        {
            // TPM is not required, so no need to propagate the error up and
            // fail the boot.
            errlCommit(l_errl, SECURE_COMP_ID);
        }
    }

    TRACFCOMP(g_trac_nc, EXIT_MRK"nodeCommGenSlaveResponseQuote: " TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
#endif
    return l_errl;
} //nodeCommGenSlaveResponseQuote

/**
 *  @brief This function runs the procedure for the master processor on the
 *         master node to send and receive messages over the ABUS to the
 *         master processors on the slave nodes
 *
 *  @param[in] i_mProcInfo - Information about Master Proc
 *  @param[in] i_obus_instances - Vector containing all of the OBUS connections
 *                                that the Master Proc on the Master Node needs
 *                                to send and received messages across
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommAbusExchangeMaster(const master_proc_info_t & i_mProcInfo,
                                      const std::vector<obus_instances_t> &
                                        i_obus_instances)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusExchangeMaster: mProc=0x%.08X "
              "to communicate through %d obus connection(s)",
              get_huid(i_mProcInfo.tgt), i_obus_instances.size());

    // Pointer to buffer used for receiving data from nodeCommTransferRecv()
    uint8_t * data_rcv_buffer = nullptr;

    do
    {

    for ( auto const l_obus : i_obus_instances)
    {
        uint8_t my_linkId = 0;
        uint8_t my_mboxId = 0;
        getLinkMboxFromObusInstance(l_obus.myObusInstance,
                                    l_obus.myObusRelLink,
                                    my_linkId,
                                    my_mboxId);

        uint8_t expected_peer_linkId = 0;
        uint8_t expected_peer_mboxId = 0;
        getLinkMboxFromObusInstance(l_obus.peerObusInstance,
                                    // same relative link for peer path:
                                    l_obus.myObusRelLink,
                                    expected_peer_linkId,
                                    expected_peer_mboxId);

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeMaster: "
                  "my: linkId=%d, mboxId=%d, ObusInstance=%d. "
                  "expected peer: linkId=%d, mboxId=%d, ObusInstance=%d.",
                  my_linkId, my_mboxId, l_obus.myObusInstance,
                  expected_peer_linkId, expected_peer_mboxId,
                  l_obus.peerObusInstance);

        // Get random number from TPM
        msg_format_t msg_data;
        msg_data.value = 0;

        err = nodeCommAbusGetRandom(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: Error Back "
                      "From nodeCommAbusGetRandom: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }
        // Set the send and expected receive LinkIds in the nonce
        msg_data.origin_linkId = my_linkId;
        msg_data.receiver_linkId = expected_peer_linkId;

        // Send a message to a slave
        size_t tmp_size = sizeof(msg_data.value);
        err = nodeCommTransferSend(i_mProcInfo.tgt,
                                   my_linkId,
                                   my_mboxId,
                                   NCT_TRANSFER_SBID,
                                   reinterpret_cast<uint8_t*>
                                     (&(msg_data.value)),
                                   tmp_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                      "nodeCommAbusTransferSend returned an error");
            break;
        }

        // Push this msg_data to TPM
        err = nodeCommAbusLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: Error Back From "
                      "nodeCommAbusLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Look for Return Message From The Slave
        size_t data_rcv_size = 0;
        if (data_rcv_buffer != nullptr)
        {
            free(data_rcv_buffer);
            data_rcv_buffer = nullptr;
        }
        err = nodeCommTransferRecv(i_mProcInfo.tgt,
                                   my_linkId,
                                   my_mboxId,
                                   NCT_TRANSFER_SBID,
                                   data_rcv_buffer,
                                   data_rcv_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeMaster: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_rcv_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_rcv_buffer!=nullptr,"nodeCommAbusExchangeMaster: data_rcv_buffer returned as nullptr");

        // Add receiver Link Id to the message data
        // @TODO RTC 203642 Check that data_rcv_size == sizeof(uint64_t)
        // here and in other places where SBID is handled
        memcpy(&(msg_data.value), data_rcv_buffer, data_rcv_size);
        msg_data.receiver_linkId = my_linkId;
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeMaster: Msg received, "
                  "after adding recv link (%d), 0x%.16llX will be "
                  "stored in the TPM",
                  my_linkId, msg_data.value);

        // Push this msg_data to TPM
        err = nodeCommAbusLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: Error Back "
                      "From nodeCommAbusLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

    } // end of loop on i_obus_instances

    if(err)
    {
        break;
    }

    // @TODO RTC 203642 Do Another Loop for Quotes

    } while( 0 );

    if (data_rcv_buffer != nullptr)
    {
        free(data_rcv_buffer);
        data_rcv_buffer = nullptr;
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusExchangeMaster: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusExchangeMaster


/**
 *  @brief This function runs the procedure for the master processor on the
 *         slave nodes to receive and send messages over the ABUS to the
 *         master processor on the master node
 *
 *  @param[in] i_mProcInfo - Information about Master Proc
 *  @param[in] i_obus_instance - OBUS connection that should pertain to the
 *                               Master Proc on the master node that will send
 *                               a message to Master Proc of this slave node
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommAbusExchangeSlave(const master_proc_info_t & i_mProcInfo,
                                     const obus_instances_t & i_obus_instance)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusExchangeSlave: mProc=0x%.08X "
              "Looking for message from master node via obus connection "
              "n%d/p%d/obus%d",
              get_huid(i_mProcInfo.tgt),
              i_obus_instance.peerNodeInstance,
              i_obus_instance.peerProcInstance,
              i_obus_instance.peerObusInstance);

    // Pointer to buffer used for receiving data from nodeCommTransferRecv()
    uint8_t * data_rcv_buffer = nullptr;

    do
    {
        // Used for check that right node indicated itself as master
        uint8_t my_linkId = 0;
        uint8_t my_mboxId = 0;
        getLinkMboxFromObusInstance(i_obus_instance.myObusInstance,
                                    i_obus_instance.myObusRelLink,
                                    my_linkId,
                                    my_mboxId);


        // First Wait for Message From Master
        if (data_rcv_buffer != nullptr)
        {
            free(data_rcv_buffer);
            data_rcv_buffer = nullptr;
        }
        size_t data_rcv_size = 0;
        err = nodeCommTransferRecv(i_mProcInfo.tgt,
                                   my_linkId,
                                   my_mboxId,
                                   NCT_TRANSFER_SBID,
                                   data_rcv_buffer,
                                   data_rcv_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_rcv_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_rcv_buffer!=nullptr,"nodeCommAbusExchangeSlave: data_rcv_buffer returned as nullptr");


        // Add receiver Link Id to the message data
        msg_format_t msg_data;
        memcpy(&(msg_data.value), data_rcv_buffer, data_rcv_size);
        msg_data.receiver_linkId = my_linkId;

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeSlave: Msg received, "
                  "after adding recv Link Id (%d), 0x%.16llX will "
                  "be stored in the TPM",
                  my_linkId, msg_data.value);

        // Push this msg_data to TPM
        err = nodeCommAbusLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: Error Back "
                      "From nodeCommAbusLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Send a message back to the master node
        // Pass in expected peer linkId for nonce logging/extending purposes
        uint8_t peer_linkId = 0;
        uint8_t peer_mboxId = 0;
        getLinkMboxFromObusInstance(i_obus_instance.peerObusInstance,
                                    // same relative link for peer path:
                                    i_obus_instance.myObusRelLink,
                                    peer_linkId,
                                    peer_mboxId);

        // Get random number from TPM
        msg_data.value = 0;
        err = nodeCommAbusGetRandom(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: Error Back "
                      "From nodeCommAbusGetRandom: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Set the send and expected receive LinkIds in the nonce
        msg_data.origin_linkId = my_linkId;
        msg_data.receiver_linkId = my_linkId;

        // Send a message to a slave
        size_t tmp_size = sizeof(msg_data.value);
        err = nodeCommTransferSend(i_mProcInfo.tgt,
                                   my_linkId,
                                   my_mboxId,
                                   NCT_TRANSFER_SBID,
                                   reinterpret_cast<uint8_t*>
                                     (&(msg_data.value)),
                                   tmp_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommAbusTransferSend returned an error");
            break;
        }

        // Push this msg_data to TPM
        err = nodeCommAbusLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: Error Back From "
                      "nodeCommAbusLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

    } while( 0 );

    if (data_rcv_buffer != nullptr)
    {
        free(data_rcv_buffer);
        data_rcv_buffer = nullptr;
    }


    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusExchangeSlave: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusExchangeSlave


/**
 *  @brief Runs the procedure for the drawers/nodes to exchange messages
 *         over the ABUS Link Mailbox facility
 *
 *  Defined in nodecommif.H
 */
errlHndl_t nodeCommAbusExchange(void)
{
    errlHndl_t err = nullptr;

#ifndef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: Not running procedure "
              "since CONFIG_TPMDD is not set");
#else


    master_proc_info_t mProcInfo;
    std::vector<obus_instances_t> obus_instances;
    char * l_phys_path_str = nullptr;
    char * l_peer_path_str = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusExchange:");

    do
    {
    // Get Target Service, and the system target.
    TargetService& tS = targetService();
    Target* sys = nullptr;
    (void) tS.getTopLevelTarget( sys );
    assert(sys, "nodeCommAbusExchange: system target is NULL");


    // Get some info about the nodes in the system
    auto hb_images = sys->getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
    const int total_nodes = __builtin_popcount(hb_images);
    uint64_t my_nodeid = TARGETING::UTIL::getCurrentNodePhysId();
    size_t my_round = 0;

    // Create mask to use for check later
    ATTR_HB_EXISTING_IMAGE_type mask = 0x1 <<
        ((sizeof(ATTR_HB_EXISTING_IMAGE_type) * 8) -1);

    for (size_t l_node=0, count=0;
         (l_node < MAX_NODES_PER_SYS);
         ++l_node )
    {
        if( 0 != ((mask >> l_node) & hb_images ) )
        {
            ++count;
            if (l_node == my_nodeid)
            {
                my_round = count;
                TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                          "this node is position %d of %d total nodes "
                          "(l_nodeId=%d, hb_existing_image=0x%X)",
                          my_round, total_nodes, my_nodeid, hb_images );
                break;
            }
        }
    }

    // Get master proc for this node
    err = tS.queryMasterProcChipTargetHandle(mProcInfo.tgt);
    if (err)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommAbusExchange: "
                  "queryMasterProcChipTargetHandle returned error: "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(err));
        break;
    }

    // Extract info from the master proc of this node
    EntityPath l_PHYS_PATH = mProcInfo.tgt->getAttr<ATTR_PHYS_PATH>();
    EntityPath::PathElement l_peMasterNode =
                              l_PHYS_PATH.pathElementOfType(TYPE_NODE);
    EntityPath::PathElement l_peMasterProc =
                              l_PHYS_PATH.pathElementOfType(TYPE_PROC);
    l_phys_path_str = l_PHYS_PATH.toString();

    if((l_peMasterNode.type == TYPE_NA) ||
       (l_peMasterProc.type == TYPE_NA))
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchange: "
                  "ERR: Cannot find NODE or PROC in masterProc 0x%.08X "
                  "PHYS_PATH %s",
                  get_huid(mProcInfo.tgt),
                  l_phys_path_str);
        /*@
         * @errortype
         * @reasoncode       RC_NCEX_INVALID_PHYS_PATH
         * @moduleid         MOD_NCEX_MAIN
         * @userdata1        Master Proc Target HUID
         * @userdata2        <Unused>
         * @devdesc          Master Proc's ATTR_PHYS_PATH is invalid as it
         *                   doesn't have either a NODE or PROC elemenent
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCEX_MAIN,
                                       RC_NCEX_INVALID_PHYS_PATH,
                                       get_huid(mProcInfo.tgt),
                                       0,
                                       true /*Add HB SW Callout*/ );

        ERRORLOG::ErrlUserDetailsStringSet path;
        path.add("mProc PHYS Entity Path", l_phys_path_str);
        path.addToLog(err);

        break;
    }
    mProcInfo.nodeInstance = l_peMasterNode.instance;
    mProcInfo.procInstance = l_peMasterProc.instance;
    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
              "Master Proc 0x%.08X: PHYS_PATH=%s: "
              "nodeInstance=%d, procInstance=%d",
              get_huid(mProcInfo.tgt),
              l_phys_path_str,
              mProcInfo.nodeInstance,
              mProcInfo.procInstance);

    // Walk Through OBUS Chiplets on the Master Proc
    TargetHandleList l_obusTargetList;
    getChildChiplets(l_obusTargetList, mProcInfo.tgt, TYPE_OBUS);

    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: proc 0x%.08X has "
              "%d functional OBUS Chiplets",
              get_huid(mProcInfo.tgt), l_obusTargetList.size());

    // Loop through OBUS Targets and evaluate their PEER_TARGETs
    for (const auto & l_obusTgt : l_obusTargetList)
    {

        EntityPath l_peerPath = l_obusTgt->getAttr<ATTR_PEER_PATH>();
        EntityPath::PathElement l_peProc =
                                  l_peerPath.pathElementOfType(TYPE_PROC);

        if (l_peer_path_str != nullptr)
        {
            free(l_peer_path_str);
        }
        l_peer_path_str = l_peerPath.toString();


        if(l_peProc.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X "
                      "OBUS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find PROC in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str);
            continue;
        }

        // check that proc has same position as our master
        if (l_peProc.instance != mProcInfo.procInstance)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X "
                      "OBUS HUID 0x%.08X's PEER_PATH %s because PROC "
                      "Instance=%d does not match masterProc Instance=%d",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str, l_peProc.instance,
                      mProcInfo.procInstance);
            continue;
        }

        EntityPath::PathElement l_peNode =
                                  l_peerPath.pathElementOfType(TYPE_NODE);
        if(l_peNode.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X "
                      "OBUS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find NODE in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str);
            continue;
        }

        // Check that node exists and isn't this node
        if (!((mask >> l_peNode.instance) & hb_images) ||
             (l_peNode.instance == my_nodeid))
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X "
                      "OBUS HUID 0x%.08X's PEER_PATH %s because either "
                      "Node=%d is not configured or is this node (%d)",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str, l_peNode.instance, my_nodeid);
            continue;
        }

        obus_instances_t l_obusInstance;

        EntityPath::PathElement l_peObus =
                                  l_peerPath.pathElementOfType(TYPE_OBUS);
        if(l_peObus.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X "
                      "OBUS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find OBUS in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str);
            continue;
        }

        bool link0_trained = false;
        bool link1_trained = false;
        uint64_t fir_data = 0;
        err = getObusTrainedLinks(l_obusTgt,
                                  link0_trained,
                                  link1_trained,
                                  fir_data);
        if (err)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommAbusExchange: "
                      "getObusTrainedLinks returned error so "
                      "Skipping masterProc 0x%.08X OBUS HUID 0x%.08X. "
                      TRACE_ERR_FMT,
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      TRACE_ERR_ARGS(err));
            break;
        }
        else
        {
            TRACFCOMP(g_trac_nc, INFO_MRK"nodeCommAbusExchange: "
                      "getObusTrainedLinks: link0=%d, link1=%d",
                      link0_trained, link1_trained);

            l_obusInstance.myObusRelLink = (link0_trained) ? 0 :
                                             ((link1_trained) ? 1 :
                                               NCDD_INVALID_LINK_MBOX);

            if (l_obusInstance.myObusRelLink == NCDD_INVALID_LINK_MBOX)
            {
               TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                         "Skipping masterProc 0x%.08X "
                         "OBUS HUID 0x%.08X's because neither link has been "
                         "trained: link0=%d, link1=%d (fir_data=0x%.16llX)",
                         get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                         link0_trained, link1_trained, fir_data);
                continue;
            }

        }

        // Using this OBUS instance so save it off
        l_obusInstance.peerObusInstance = l_peObus.instance;
        l_obusInstance.peerProcInstance = l_peProc.instance;
        l_obusInstance.peerNodeInstance = l_peNode.instance;
        l_obusInstance.myObusInstance = l_obusTgt->getAttr<ATTR_REL_POS>();

        // Before adding to list check that on a 2-node system that we ignore
        // redundant connections to the same node
        if (total_nodes==2)
        {
            bool l_duplicate_found = false;
            for (auto l_saved_instance : obus_instances)
            {
                if (l_saved_instance.peerNodeInstance ==
                    l_obusInstance.peerNodeInstance)
                {
                    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "Skipping masterProc 0x%.08X OBUS HUID 0x%.08X's "
                      "PEER_PATH %s because already have saved connection to "
                      "that node: myObusInstance=%d, peerInstance:n%d/p%d/obus%d",
                      get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                      l_peer_path_str,
                      l_saved_instance.myObusInstance,
                      l_saved_instance.peerNodeInstance,
                      l_saved_instance.peerProcInstance,
                      l_saved_instance.peerObusInstance);

                    l_duplicate_found = true;
                    break;
                }
            }
            if (l_duplicate_found == true)
            {
                 // continue to skip adding this instance to obus_instances
                 continue;
            }
        }

        obus_instances.push_back(l_obusInstance);
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: Using masterProc 0x%.08X "
                  "OBUS HUID 0x%.08X's peer path %s with obus_instance "
                  "myObusInstance=%d, peer=n%d/p%d/obus%d (vector size=%d)",
                  get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                  l_peer_path_str, l_obusInstance.myObusInstance,
                  l_obusInstance.peerNodeInstance,
                  l_obusInstance.peerProcInstance,
                  l_obusInstance.peerObusInstance, obus_instances.size());
    }

    // If invalid number of peer paths fail
    if((obus_instances.size() == 0) ||
       (obus_instances.size() != (static_cast<uint32_t>(total_nodes)-1)))
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchange: "
                  "ERR: Invalid number of PEER_PATHs %d found for proc=0x%.08X "
                  "when there are %d nodes in the system",
                  obus_instances.size(), get_huid(mProcInfo.tgt),
                  total_nodes);

        /*@
         * @errortype
         * @reasoncode       RC_NCEX_INVALID_INSTANCE_COUNT
         * @moduleid         MOD_NCEX_MAIN
         * @userdata1        Master Proc Target HUID
         * @userdata2[0:31]  Number of Valid OBUS Instances
         * @userdata2[32:63] Total Number Of Nodes
         * @devdesc          When processing the OBUS Peer paths, the wrong
         *                   count of valid paths was found
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCEX_MAIN,
                                       RC_NCEX_INVALID_INSTANCE_COUNT,
                                       get_huid(mProcInfo.tgt),
                                       TWO_UINT32_TO_UINT64(
                                         obus_instances.size(),
                                         total_nodes),
                                       true /*Add HB SW Callout*/ );

        break;
    }


    // Master node should have lowest node number in vector of instance info.
    // So sort here by node number and then only pass first instance to
    // nodeCommAbusExchangeSlave() below.  Then when message is received it
    // will be checked against the expected master instance.
    std::sort(obus_instances.begin(),
              obus_instances.end(),
              [](obus_instances_t & lhs,
                 obus_instances_t & rhs)
    {
        return lhs.peerNodeInstance < rhs.peerNodeInstance;
    });


    // @TODO RTC 194053 - This won't work on simics until the action files
    // are there
    if (Util::isSimicsRunning())
    {
        TRACFCOMP(g_trac_nc,"nodeCommAbusExchange: actual operation is not "
                  "supported on simics yet");
        break;
    }

    if (TARGETING::UTIL::isCurrentMasterNode())
    {
        err = nodeCommAbusExchangeMaster(mProcInfo,obus_instances);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "nodeCommAbusExchangeMaster returned an error");
           break;
        }
    }
    else
    {
        // Only pass first instance, which should be master instance
        err = nodeCommAbusExchangeSlave(mProcInfo,
                                        obus_instances[0]);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchange: "
                      "nodeCommAbusExchangeSlave returned an error");
           break;
        }
    }

    if(err)
    {
        break;
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusExchange: %s: "
              TRACE_ERR_FMT,
              (err == nullptr) ? "SUCCESSFUL" : "FAILED",
              TRACE_ERR_ARGS(err));

    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);
        err->collectTrace(TRBOOT_COMP_NAME);
    }

    if (l_phys_path_str != nullptr)
    {
        free(l_phys_path_str);
        l_phys_path_str = nullptr;
    }
    if (l_peer_path_str != nullptr)
    {
        free(l_peer_path_str);
        l_peer_path_str = nullptr;
    }

#endif

    return err;

} // end of nodeCommAbusExchange

} // End NODECOMM namespace

} // End SECUREBOOT namespace


