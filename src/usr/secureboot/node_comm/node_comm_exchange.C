/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/secureboot/node_comm/node_comm_exchange.C $           */
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
#include <util/threadpool.H>

#include "node_comm.H"
#include "node_comm_transfer.H"
#include "node_comm_exchange_helper.H"

#include <secureboot/service.H>
#include <securerom/contrib/sha512.H>

#include "../trusted/trustedTypes.H"
#include "../trusted/tpmLogMgr.H"

#include <tracinterface.H>

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

/**
 * @brief Helper function to send a flush context command to the primary TPM.
 *        This command flushes out all of the secure info that was generated on
 *        the TPM. The command needs to be run after we've collected ALL of the
 *        information for all of the nodes.
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t flushTpmContext()
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    do {

    TARGETING::Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);

    l_errl = TRUSTEDBOOT::validateTpmHandle(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"flushTpmContext: Invalid TPM handle"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Flush the AK from the TPM
    l_errl = TRUSTEDBOOT::flushContext(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"flushTpmContext: could not flush TPM context"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }
    }while(0);
#endif

    return l_errl;
}

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
errlHndl_t nodeCommGetRandom(uint64_t & o_nonce)
{
    errlHndl_t err = nullptr;
    o_nonce = NODE_COMM_DEFAULT_NONCE;
#ifdef CONFIG_TPMDD
    Target* tpm_tgt = nullptr;

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommGetRandom:");

    do
    {

    // Can only use the functional Primary TPM
    // This function call requires the CONFIG check for compilation purposes,
    // but no extra error handling is needed as it should not have gotten this
    // far if CONFIG_TPMDD wasn't set
    TRUSTEDBOOT::getPrimaryTpm(tpm_tgt);
    HwasState hwasState{};
    if(tpm_tgt)
    {
        hwasState = tpm_tgt->getAttr<TARGETING::ATTR_HWAS_STATE>();
        TRACUTCOMP(g_trac_nc,INFO_MRK
                  "TPM HUID 0x%08X has state of {present=%d, "
                  "functional=%d}",
                  get_huid(tpm_tgt),
                  hwasState.present,hwasState.functional);

    }

    if ((tpm_tgt == nullptr) ||
        (hwasState.functional == false))
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGetRandom: no functional "
                  "Primary TPM: huid=0x%.08X: functional=%d",
                  get_huid(tpm_tgt), hwasState.functional);

        /*@
         * @errortype
         * @reasoncode       RC_NCEX_NO_FUNCTIONAL_PRIMARY_TPM
         * @moduleid         MOD_NCEX_GET_RANDOM
         * @userdata1        TPM Target HUID
         * @userdata2[0:31]  TPM Target HWAS State Present
         * @userdata2[31:63] TPM Target HWAS State Functional
         * @devdesc          Functional Primary TPM was not found
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_PREDICTIVE,
                                       MOD_NCEX_GET_RANDOM,
                                       RC_NCEX_NO_FUNCTIONAL_PRIMARY_TPM,
                                       get_huid(tpm_tgt),
                                       TWO_UINT32_TO_UINT64(
                                         hwasState.present,
                                         hwasState.functional),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        // break here to skip calling GetRandom() below
        break;
    }

    // This function call requires the CONFIG check for compilation purposes,
    // but no extra error handling is needed as it should not have gotten this
    // far if CONFIG_TPMDD wasn't set
    err = TRUSTEDBOOT::GetRandom(tpm_tgt,
                                 sizeof(o_nonce),
                                 reinterpret_cast<uint8_t*>(&o_nonce));
    if (err)
    {
        // Reset just to make sure above call didn't change it
        o_nonce = NODE_COMM_DEFAULT_NONCE;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGetRandom: GetRandom "
                  "returned a fail for TPM 0x%.08X. Commiting err: "
                  TRACE_ERR_FMT
                  ". Using default nonce=0x%.16llX",
                  get_huid(tpm_tgt),
                  TRACE_ERR_ARGS(err),
                  o_nonce);
        // break to be safe in case code gets added later
        break;
    }

    } while( 0 );

    if(err)
    {
        if(!TRUSTEDBOOT::isTpmRequired())
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGetRandom: Error occurred; "
                      "RC: 0x%.04X; PLID: 0x%.08X. TPM Required policy is off; "
                      "deleting the error and trying to continue.",
                      err->reasonCode(),
                      err->plid());
            // TPM is not required - do not return the error
            delete err;
            err = nullptr;
        }
        else
        {
            err->collectTrace(TRBOOT_COMP_NAME);
            err->collectTrace(NODECOMM_TRACE_NAME);
        }
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommGetRandom: "
              "nonce=0x%.16llX from TPM=0x%.08X. "
              TRACE_ERR_FMT,
              o_nonce, get_huid(tpm_tgt),
              TRACE_ERR_ARGS(err));

#endif
    return err;

} // end of nodeCommGetRandom

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
errlHndl_t nodeCommLogNonce(uint64_t & i_nonce)
{
    errlHndl_t err = nullptr;

    TRACUTCOMP(g_trac_nc,ENTER_MRK"nodeCommLogNonce: i_nonce=0x%.16llX",
              i_nonce);

    do
    {

    // Extend the nonce asychronously to all available TPMs
    uint8_t l_digest[sizeof(i_nonce)]={0};
    memcpy(l_digest, &i_nonce, sizeof(i_nonce));

    uint8_t l_logMsg[] = "Node Nonce";
    err = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                 TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                 l_digest,
                                 sizeof(uint64_t),
                                 l_logMsg,
                                 sizeof(l_logMsg));
    if (err)
    {
       TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommLogNonce: pcrExtend "
                  "returned a fail: "
                  TRACE_ERR_FMT,
                  TRACE_ERR_ARGS(err));
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommLogNonce: i_nonce=0x%.16llX. "
              TRACE_ERR_FMT,
              i_nonce,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommLogNonce

// Global authentication key certificate that can be shared between threads
// and different node comm exchange algorithms
TRUSTEDBOOT::TPM2B_MAX_NV_BUFFER g_nodeAK {};

/**
 * @brief Generates and reads out the Attestation Key Certificate from primary
 *        TPM. The certificate is stored in the shared global variable. The hash
 *        of the cert is extended into TPM PCR1 and the full cert is logged
 *        into the TPM log.
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t generateAKCertificate()
{
    TRACFCOMP(g_trac_nc,ENTER_MRK"generateAKCertificate");
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    do {
    TARGETING::Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);

    l_errl = TRUSTEDBOOT::validateTpmHandle(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"generateAKCertificate: Invalid TPM handle"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Generate the AK Certificate
    l_errl = TRUSTEDBOOT::createAttestationKeys(l_primaryTpm);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"generateAKCertificate: could not create attestation keys"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Read the AK Certificate
    l_errl = TRUSTEDBOOT::readAKCertificate(l_primaryTpm, &g_nodeAK);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"generateAKCertificate: could not read AK certificate"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Hash the AK Certificate and extend the hash into PCR1
    SHA512_t l_AKCertHash = {0};
    hashBlob(g_nodeAK.buffer,
             g_nodeAK.size,
             l_AKCertHash);

    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                    TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                    l_AKCertHash,
                                    sizeof(SHA512_t),
                                    g_nodeAK.buffer,
                                    g_nodeAK.size);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"generateAKCertificate: could not extend AK Certificate hash to TPM"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"generateAKCertificate");

    }while(0);
#endif
    return l_errl;
}

/**
 * @brief A function to create the slave node quote response that consists of
 *        eye catcher, slave node ID, quote and signature data (represented by
 *        the QuoteDataOut structure), the contents of PCRs 0-7, the
 *        Attestation Key Certificate returned from TPM, the size
 *        and the contents of the TPM log
 * @param[in] i_request the master node request structure
 * @param[out] o_size the size of the slave quote
 * @param[out] o_resp the slave quote in binary format
 * @note If an error occurs within the function, the o_resp will only have an
 *       eye catcher indicating that the slave quote is bad.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t nodeCommGenSlaveQuoteResponse(const MasterQuoteRequestBlob* const i_request,
                                         size_t& o_size,
                                         std::unique_ptr<uint8_t>& o_resp)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc, ENTER_MRK"nodeCommGenSlaveQuoteResponse");
    bool l_tpmRequired = TRUSTEDBOOT::isTpmRequired();
    bool l_errorOccurred = false;

    TRUSTEDBOOT::QuoteDataOut l_quoteData;
    uint32_t l_nodeId = TARGETING::UTIL::getCurrentNodePhysId();
    uint8_t* l_quotePtr = nullptr;

    do {

    o_resp = nullptr;

    TARGETING::Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);
    if(!l_primaryTpm ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().functional ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().present)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: primary TPM not found or not functional");
        l_errorOccurred = true;
        break;
    }


    // If Master indicated that there is an issue with its TPM: Case 1: If the
    // TPM Required policy is on, terminate the boot; Case 2: If TPM required
    // policy is off, send back a token indicating that no nodecomm TPM commands
    // have been performed (remote attestation is not possible with bad master
    // TPM); do not fail the boot.
    if(i_request->EyeCatcher == MSTNOTPM)
    {
        l_errorOccurred = true;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: Master indicated an issue with secure nodecomm (master eye catcher is MSTNOTPM)");
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
    else if(i_request->EyeCatcher != MASTERQ_)
    {
        l_errorOccurred = true;
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: Invalid master eye catcher received: 0x%x", i_request->EyeCatcher);
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
                                              i_request->EyeCatcher);
            // It is unlikely that there is an issue with this node, but collect
            // the logs anyway for ease of debug.
            l_errl->collectTrace(NODECOMM_TRACE_NAME);
            l_errl->collectTrace(TRBOOT_COMP_NAME);
            l_errl->collectTrace(SECURE_COMP_NAME);
        }
        break;
    }

    // If the size of node Attestation Keys is 0, then they have not been generated yet, so generate
    // them here
    if(g_nodeAK.size == 0)
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommGenSlaveQuoteResponse: AK certificate is empty; generating AK certificate");
        l_errl = generateAKCertificate();
        if(l_errl)
        {
            break;
        }
    }

    l_quoteData.data = new uint8_t[1 * KILOBYTE]{};// the actual data size will
                                                   // be smaller than 1KB
    // Generate quote and signature data (presented as binary data in
    // the QuoteDataOut structure)
    l_errl = TRUSTEDBOOT::generateQuote(l_primaryTpm,
                                        &i_request->MasterNonce,
                                        &l_quoteData);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: could not generate TPM quote");
        break;
    }

    // Read the selected PCRs
    // Make sure there is only 1 algo selection
    assert(i_request->PcrSelect.count == 1, "nodeCommGenSlaveQuoteResponse: only 1 hash algo is supported for PCR read");
    uint32_t l_pcrCount = 0;
    TRUSTEDBOOT::TPM_Pcr l_pcrRegs[TRUSTEDBOOT::FW_USED_PCR_COUNT] = {
                                                  TRUSTEDBOOT::PCR_0,
                                                  TRUSTEDBOOT::PCR_1,
                                                  TRUSTEDBOOT::PCR_2,
                                                  TRUSTEDBOOT::PCR_3,
                                                  TRUSTEDBOOT::PCR_4,
                                                  TRUSTEDBOOT::PCR_5,
                                                  TRUSTEDBOOT::PCR_6,
                                                  TRUSTEDBOOT::PCR_7
                                                 };
    TRUSTEDBOOT::TPM_Alg_Id l_algId = static_cast<TRUSTEDBOOT::TPM_Alg_Id>
                            (i_request->PcrSelect.pcrSelections[0].algorithmId);
    size_t l_digestSize = TRUSTEDBOOT::getDigestSize(l_algId);

    // An array of PCR Digest structures to hold the contents of the selected
    // PCRs
    TRUSTEDBOOT::TPM2B_DIGEST l_pcrDigests[TRUSTEDBOOT::FW_USED_PCR_COUNT] {};

    // Iterate through PCRs that hostboot interacts with (PCR0-7) and see
    // if any of those were seleceted; read the selected ones
    for(const auto l_pcr : l_pcrRegs)
    {
        if((i_request->PcrSelect.pcrSelections[0]
            .pcrSelect[l_pcr/TRUSTEDBOOT::FW_USED_PCR_COUNT]) &
            (0x01 << (l_pcr % TRUSTEDBOOT::FW_USED_PCR_COUNT)))
        {
            ++l_pcrCount;
            l_pcrDigests[l_pcr].size = l_digestSize;
            l_errl = TRUSTEDBOOT::pcrRead(l_primaryTpm,
                                      l_pcr,
                                      l_algId,
                                      l_digestSize,
                                      l_pcrDigests[l_pcr].buffer);
            if(l_errl)
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: could not read PCR%d", l_pcr);
                break;
            }
        }
    }
    if(l_errl)
    {
        break;
    }

    // Read out the primary TPM's Log and copy it into the quote
    TRUSTEDBOOT::TpmLogMgr* l_primaryLogMgr =
                                        TRUSTEDBOOT::getTpmLogMgr(l_primaryTpm);
    if(!l_primaryLogMgr)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: could not fetch primary TPM's log");
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

    NCEyeCatcher_t l_goodEyeCatch = NODEQUOT;

    // Figure out the size of the slave quote
    o_size = sizeof(l_goodEyeCatch) +
             sizeof(l_nodeId) +
             sizeof(l_quoteData.size) +
             l_quoteData.size +
             sizeof(l_pcrCount) +
             // Only include the read PCRs in the slave quote
             sizeof(TRUSTEDBOOT::TPM2B_DIGEST) * l_pcrCount +
             sizeof(g_nodeAK) +
             sizeof(l_logSize) +
             l_logSize;

    // Allocate the output
    l_quotePtr = new uint8_t[o_size] {};
    // Now populate the output
    size_t l_currentOffset = 0;

    // First the good eye catcher
    memcpy(l_quotePtr, &l_goodEyeCatch, sizeof(l_goodEyeCatch));
    l_currentOffset += sizeof(l_goodEyeCatch);
    // Now the node ID
    memcpy(l_quotePtr + l_currentOffset, &l_nodeId, sizeof(l_nodeId));
    l_currentOffset += sizeof(l_nodeId);
    // The size of the quote and signature structures
    memcpy(l_quotePtr + l_currentOffset,&l_quoteData.size,sizeof(l_quoteData.size));
    l_currentOffset += sizeof(l_quoteData.size);
    // The TPM quote & signature information (both are included in the TPM
    // quote blob)
    memcpy(l_quotePtr + l_currentOffset, l_quoteData.data, l_quoteData.size);
    l_currentOffset += l_quoteData.size;
    // The number of PCRs read
    memcpy(l_quotePtr + l_currentOffset, &l_pcrCount, sizeof(l_pcrCount));
    l_currentOffset += sizeof(l_pcrCount);
    // PCR contents
    for(const auto l_pcr : l_pcrRegs)
    {
        if(l_pcrDigests[l_pcr].size != 0)
        {
            // Copy the size of the PCR
            memcpy(l_quotePtr + l_currentOffset,
                   &l_pcrDigests[l_pcr].size,
                   sizeof(l_pcrDigests[l_pcr].size));
            l_currentOffset += sizeof(l_pcrDigests[l_pcr].size);
            // Now the actual data
            memcpy(l_quotePtr + l_currentOffset,
                   l_pcrDigests[l_pcr].buffer,
                   l_pcrDigests[l_pcr].size);
            l_currentOffset += l_pcrDigests[l_pcr].size;
        }
    }
    // AK certificate size
    memcpy(l_quotePtr + l_currentOffset, &g_nodeAK.size, sizeof(g_nodeAK.size));
    l_currentOffset += sizeof(g_nodeAK.size);
    // Actual AK certificate
    memcpy(l_quotePtr + l_currentOffset, g_nodeAK.buffer, g_nodeAK.size);
    l_currentOffset += g_nodeAK.size;
    // The length of the TPM log
    memcpy(l_quotePtr + l_currentOffset, &l_logSize, sizeof(l_logSize));
    l_currentOffset += sizeof(l_logSize);
    // The actual TPM log
    memcpy(l_quotePtr + l_currentOffset, l_logPtr, l_logSize);

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
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: An error "
                 "occurred during slave quote composition. Sending NDNOTPM_ "
                 "back Master Node after poisoning all TPMs on this node");

        NCEyeCatcher_t l_badEyeCatcher = NDNOTPM_;
        delete[] l_quotePtr;
        l_quotePtr = new uint8_t[sizeof(l_badEyeCatcher) + sizeof(l_nodeId)]{};
        memcpy(l_quotePtr, &l_badEyeCatcher, sizeof(l_badEyeCatcher));
        memcpy(l_quotePtr + sizeof(l_badEyeCatcher), &l_nodeId, sizeof(l_nodeId));
        o_size = sizeof(l_badEyeCatcher) + sizeof(l_nodeId);

        errlHndl_t l_poisonTpmErr = TRUSTEDBOOT::poisonAllTpms();
        if(l_poisonTpmErr)
        {
            if(l_errl)
            {
                l_poisonTpmErr->plid(l_errl->plid());
            }
            if(l_tpmRequired)
            {
                errlCommit(l_poisonTpmErr, SECURE_COMP_ID);
            }
            else
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenSlaveQuoteResponse: "
                          "Could not poison TPMs. Errl PLID: 0x%.08X "
                          "Deleting the error log and continuing anyway.",
                          l_poisonTpmErr->plid());
                delete l_poisonTpmErr;
                l_poisonTpmErr = nullptr;
            }
        }
    }

    o_resp.reset(l_quotePtr);

    TRACFCOMP(g_trac_nc, EXIT_MRK"nodeCommGenSlaveQuoteResponse: " TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
#endif
    return l_errl;
} //nodeCommGenSlaveQuoteResponse

errlHndl_t nodeCommGenMasterQuoteRequest(MasterQuoteRequestBlob* const o_request)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc, ENTER_MRK"nodeCommGenMasterQuoteRequest");
    bool l_tpmRequired = TRUSTEDBOOT::isTpmRequired();
    do {
    TARGETING::Target* l_primaryTpm = nullptr;
    TRUSTEDBOOT::getPrimaryTpm(l_primaryTpm);
    if(!l_primaryTpm ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().functional ||
       !l_primaryTpm->getAttr<TARGETING::ATTR_HWAS_STATE>().present)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenMasterQuoteRequest: primary TPM not found or is not functional");

        l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         MOD_NC_GEN_MASTER_REQUEST,
                                         RC_NC_BAD_MASTER_TPM);
        l_errl->collectTrace(SECURE_COMP_NAME);
        l_errl->collectTrace(TRBOOT_COMP_NAME);
        l_errl->collectTrace(NODECOMM_TRACE_NAME);
        break;
    }

    o_request->EyeCatcher = MASTERQ_;

    // Generate the 32-byte nonce for master request
    l_errl = TRUSTEDBOOT::GetRandom(l_primaryTpm,
                                    sizeof(o_request->MasterNonce),
                                    o_request->MasterNonce);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenMasterQuoteRequest: GetRandom failed");
        break;
    }

    // Select PCRs (PCR0-7) to include in slave quote response
    o_request->PcrSelect.count = 1; // One algorithm
    o_request->PcrSelect.pcrSelections[0].algorithmId =
                                                    TRUSTEDBOOT::TPM_ALG_SHA256;
    o_request->PcrSelect.pcrSelections[0].sizeOfSelect =
                                                    TRUSTEDBOOT::PCR_SELECT_MAX;
    memset(o_request->PcrSelect.pcrSelections[0].pcrSelect, 0,
            sizeof(o_request->PcrSelect.pcrSelections[0].pcrSelect));

    TRUSTEDBOOT::TPM_Pcr l_pcrRegs[TRUSTEDBOOT::FW_USED_PCR_COUNT] = {
                                                             TRUSTEDBOOT::PCR_0,
                                                             TRUSTEDBOOT::PCR_1,
                                                             TRUSTEDBOOT::PCR_2,
                                                             TRUSTEDBOOT::PCR_3,
                                                             TRUSTEDBOOT::PCR_4,
                                                             TRUSTEDBOOT::PCR_5,
                                                             TRUSTEDBOOT::PCR_6,
                                                             TRUSTEDBOOT::PCR_7
                                                             };
    for(const auto l_pcr : l_pcrRegs)
    {
        o_request->PcrSelect.pcrSelections[0]
            .pcrSelect[l_pcr/TRUSTEDBOOT::FW_USED_PCR_COUNT] |=
                0x01 << (l_pcr % TRUSTEDBOOT::FW_USED_PCR_COUNT);
    }

    } while(0);

    if(l_errl)
    {
        // Error occurred. Tell the slave that the master TPM is unavailable and
        // poison the TPMs on master node.
        o_request->EyeCatcher = MSTNOTPM;
        errlHndl_t l_poisonTpmErr = TRUSTEDBOOT::poisonAllTpms();
        if(l_poisonTpmErr)
        {
            if(l_errl)
            {
                l_poisonTpmErr->plid(l_errl->plid());
            }
            if(l_tpmRequired)
            {
                errlCommit(l_poisonTpmErr, SECURE_COMP_ID);
            }
            else
            {
                TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommGenMasterQuoteRequest: "
                          "Could not poison TPMs. Errl PLID: 0x%.08X. "
                          "Deleting the error log and continuing anyway.",
                          l_poisonTpmErr->plid());
                delete l_poisonTpmErr;
                l_poisonTpmErr = nullptr;
            }
        }
    }

    TRACFCOMP(g_trac_nc, EXIT_MRK"nodeCommGenMasterQuoteRequest: " TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
#endif
    return l_errl;
} // nodeCommGenMasterQuoteRequest

/**
 * @brief A function to process the response of one of the slave nodes
 * @param[in] i_slaveQuote the quote received from a slave node in binary format
 * @param[in] i_slaveQuoteSize the size of the slave quote (in bytes)
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t nodeCommProcessSlaveQuote(uint8_t* const i_slaveQuote,
                                     const size_t i_slaveQuoteSize)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc, ENTER_MRK"nodeCommProcessSlaveQuote: size=0x%016llX",i_slaveQuoteSize);
    bool l_tpmRequired = TRUSTEDBOOT::isTpmRequired();
    bool l_errorOccurred = false;

    do {
    NCEyeCatcher_t* l_eyeCatcher =
                                reinterpret_cast<NCEyeCatcher_t*>(i_slaveQuote);
    uint32_t* l_slaveNodeId = reinterpret_cast<uint32_t*>(i_slaveQuote +
                                                          sizeof(l_eyeCatcher));
    if(*l_eyeCatcher == NDNOTPM_)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommProcessSlaveQuote: Slave node %d indicated that it could not complete the slave quote generation process", *l_slaveNodeId);
        l_errorOccurred = true;
        if(l_tpmRequired)
        {
            // Slave sent bad data and TPM is required - return an error and
            // the IPL should be terminated

            /* @
             * @errortype
             * @reasoncode RC_NC_BAD_SLAVE_QUOTE
             * @moduleid   MOD_NC_PROCESS_SLAVE_QUOTE
             * @userdata1  Slave node where the quote came from
             * @devdesc    One of the slave nodes indicated that there was
             *             an issue with its TPM or quote generation process
             * @custdesc   trustedboot failure
             */
            l_errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                             MOD_NC_PROCESS_SLAVE_QUOTE,
                                             RC_NC_BAD_SLAVE_QUOTE,
                                             *l_slaveNodeId,
                                             0);
            l_errl->collectTrace(SECURE_COMP_NAME);
            l_errl->collectTrace(TRBOOT_COMP_NAME);
            l_errl->collectTrace(NODECOMM_TRACE_NAME);
        }
        break;
    }

    // Extend the hash of the slave quote to PCR 1, and include the whole quote
    // in binary form as the message in the TPM log
    SHA512_t l_quoteHash = {0};
    hashBlob(i_slaveQuote, i_slaveQuoteSize, l_quoteHash);
    l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                    TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                    l_quoteHash,
                                    sizeof(l_quoteHash),
                                    i_slaveQuote,
                                    i_slaveQuoteSize);
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommProcessSlaveQuote: could not extend slave response to PCR 1");
        break;
    }

    } while(0);

    if(l_errl || l_errorOccurred)
    {
        errlHndl_t l_poisonTpmErr = TRUSTEDBOOT::poisonAllTpms();
        if(l_poisonTpmErr)
        {
            if(l_errl)
            {
                l_poisonTpmErr->plid(l_errl->plid());
            }
            if(TRUSTEDBOOT::isTpmRequired())
            {
                errlCommit(l_poisonTpmErr, SECURE_COMP_ID);
            }
            else
            {
                TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommProcessSlaveQuote: "
                          "Could not poison TPMs. Errl PLID: 0x%.08X. "
                          "Deleting the error log and continuing.",
                          l_poisonTpmErr->plid());
                delete l_poisonTpmErr;
                l_poisonTpmErr = nullptr;
            }
        }
    }

    TRACFCOMP(g_trac_nc, EXIT_MRK"nodeCommProcessSlaveQuote: " TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
#endif
    return l_errl;
} // nodeCommProcessSlaveQuote

/**
 *  @brief This function runs the procedure for the master processor on the
 *         master node to send and receive messages to the master processors
 *         on the slave nodes
 *
 *  @param[in] i_mProcInfo - Information about Master Proc
 *  @param[in] i_iohs_instances - Vector containing all of the connections
 *                                that the Master Proc on the Master Node needs
 *                                to send and received messages across
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommExchangeMaster(const master_proc_info_t & i_mProcInfo,
                                      const std::vector<iohs_instances_t> &
                                        i_iohs_instances)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommExchangeMaster: mProc=0x%.08X "
              "to communicate through %d IOHS connection(s)",
              get_huid(i_mProcInfo.tgt), i_iohs_instances.size());

    // Pointer to buffer used for receiving data from nodeCommTransferRecv()
    uint8_t * data_rcv_buffer = nullptr;

    do
    {

    // The slave quote that is returned by the slave nodes as part of the node
    // comm protocol is too big to be placed in the TPM's log without moving the
    // log to a new memory location, so before processing the slave quote, we
    // need to send a message to the TPM queue to expand the log. We need to
    // expand logs on all TPMs, since logging and PCR extends are mirrorred into
    // all TPMs/logs on the node.
    TARGETING::TargetHandleList l_tpms;
    TRUSTEDBOOT::getTPMs(l_tpms);
    for(const auto& l_tpm : l_tpms)
    {
        err = TRUSTEDBOOT::expandTpmLog(l_tpm);
        if(err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: could not expand the TPM log for TPM HUID 0x%x", TARGETING::get_huid(l_tpm));
            break;
        }
    }

    if(err)
    {
        break;
    }

    // Loop 1: Exchange SBID/nonces between Master and each of the Slave Nodes
    for ( auto const l_iohs : i_iohs_instances)
    {
        uint8_t my_linkId = 0;
        uint8_t my_mboxId = 0;
        getLinkMboxFromIohsInstance(l_iohs.myIohsInstance,
                                    l_iohs.myIohsRelLink,
                                    my_linkId,
                                    my_mboxId);

        uint8_t expected_peer_linkId = 0;
        uint8_t expected_peer_mboxId = 0;
        getLinkMboxFromIohsInstance(l_iohs.peerIohsInstance,
                                    // same relative link for peer path:
                                    l_iohs.myIohsRelLink,
                                    expected_peer_linkId,
                                    expected_peer_mboxId);

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeMaster: Loop 1: "
                  "my: linkId=%d, mboxId=%d, IohsInstance=%d. "
                  "expected peer: n%d linkId=%d, mboxId=%d, IohsInstance=%d",
                  my_linkId, my_mboxId, l_iohs.myIohsInstance,
                  l_iohs.peerNodeInstance, expected_peer_linkId,
                  expected_peer_mboxId, l_iohs.peerIohsInstance);

        // Get random number from TPM
        msg_format_t msg_data;
        msg_data.value = 0;

        err = nodeCommGetRandom(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 1: "
                      "Error Back From nodeCommGetRandom: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Set the send and expected receive LinkIds in the nonce
        msg_data.origin_linkId = my_linkId;
        msg_data.receiver_linkId = expected_peer_linkId;

        // The node comm control and data regs live on PAUC parents of IOHS
        TARGETING::Target* l_paucParent =
                TARGETING::getImmediateParentByAffinity(l_iohs.myIohsTarget);

        // Send a message to a slave
        size_t tmp_size = sizeof(msg_data.value);
        err = nodeCommTransferSend(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   l_iohs.peerNodeInstance,
                                   NCT_TRANSFER_SBID,
                                   reinterpret_cast<uint8_t*>
                                     (&(msg_data.value)),
                                   tmp_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 1: "
                      "nodeCommTransferSend returned an error");
            break;
        }

        // Push this msg_data to TPM
        err = nodeCommLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 1: "
                      "Error Back From nodeCommLogNonce: "
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
        err = nodeCommTransferRecv(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   l_iohs.peerNodeInstance,
                                   NCT_TRANSFER_SBID,
                                   data_rcv_buffer,
                                   data_rcv_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeMaster: Loop 1: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_rcv_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_rcv_buffer!=nullptr,"nodeCommExchangeMaster: Loop 1: data_rcv_buffer returned as nullptr");

        // Add receiver Link Id to the message data
        // here and in other places where SBID is handled
        memcpy(&(msg_data.value), data_rcv_buffer, data_rcv_size);
        msg_data.receiver_linkId = my_linkId;
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeMaster: Msg received, "
                  "after adding recv link (%d), 0x%.16llX will be "
                  "stored in the TPM",
                  my_linkId, msg_data.value);

        // Push this msg_data to TPM
        err = nodeCommLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 1: "
                      "Error Back From nodeCommLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

    } // end of Loop 1 (SBID/nonces) on i_iohs_instances

    if(err)
    {
        break;
    }

    // Loop 2: Master Node will request quotes from each Slave Node by first
    // sending a Quote Request and then waiting to receive a Quote Response
    for ( auto const l_iohs : i_iohs_instances)
    {
        uint8_t my_linkId = 0;
        uint8_t my_mboxId = 0;
        getLinkMboxFromIohsInstance(l_iohs.myIohsInstance,
                                    l_iohs.myIohsRelLink,
                                    my_linkId,
                                    my_mboxId);

        uint8_t expected_peer_linkId = 0;
        uint8_t expected_peer_mboxId = 0;
        getLinkMboxFromIohsInstance(l_iohs.peerIohsInstance,
                                    // same relative link for peer path:
                                    l_iohs.myIohsRelLink,
                                    expected_peer_linkId,
                                    expected_peer_mboxId);

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeMaster: Loop 2: "
                  "my: linkId=%d, mboxId=%d, IohsInstance=%d. "
                  "expected peer: linkId=%d, mboxId=%d, ObusInstance=%d.",
                  my_linkId, my_mboxId, l_iohs.myIohsInstance,
                  expected_peer_linkId, expected_peer_mboxId,
                  l_iohs.peerIohsInstance);

        // Generate Master Quote Request
        MasterQuoteRequestBlob quote_request{};
        err = nodeCommGenMasterQuoteRequest(&quote_request);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 2: "
                      "Error Back From nodeCommGenMasterQuoteRequest: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // The node comm control and data regs live on PAUC parents of IOHS
        TARGETING::Target* l_paucParent =
                TARGETING::getImmediateParentByAffinity(l_iohs.myIohsTarget);

        // Send Quote Request to a slave
        size_t tmp_size = sizeof(quote_request);
        err = nodeCommTransferSend(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   l_iohs.peerNodeInstance,
                                   NCT_TRANSFER_QUOTE_REQUEST,
                                   reinterpret_cast<uint8_t*>
                                     (&quote_request),
                                   tmp_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 2: "
                      "nodeCommTransferSend returned an error");
            break;
        }

        // Look for Quote Response from the slave node
        size_t data_rcv_size = 0;
        if (data_rcv_buffer != nullptr)
        {
            free(data_rcv_buffer);
            data_rcv_buffer = nullptr;
        }

        err = nodeCommTransferRecv(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   l_iohs.peerNodeInstance,
                                   NCT_TRANSFER_QUOTE_RESPONSE,
                                   data_rcv_buffer,
                                   data_rcv_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeMaster: Loop 2: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_rcv_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_rcv_buffer!=nullptr,"nodeCommExchangeMaster: Loop 2: data_rcv_buffer returned as nullptr");

        // Process the Quote Response that was returned from the slave node
        err = nodeCommProcessSlaveQuote(data_rcv_buffer, data_rcv_size);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeMaster: Loop 2: "
                      "Error Back nodeCommProcessSlaveQuote: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

    } // end of Loop-2 (Quotes) on i_obus_instances

    if (err)
    {
        break;
    }
    } while( 0 );

    if (data_rcv_buffer != nullptr)
    {
        free(data_rcv_buffer);
        data_rcv_buffer = nullptr;
    }

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommExchangeMaster: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommExchangeMaster


/**
 *  @brief This function runs the procedure for the master processor on the
 *         slave nodes to receive and send messages to the master processor on
 *         the master node
 *
 *  @param[in] i_mProcInfo - Information about Master Proc
 *  @param[in] i_iohs_instance - connection that should pertain to the
 *                               Master Proc on the master node that will send
 *                               a message to Master Proc of this slave node
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommExchangeSlave(const master_proc_info_t & i_mProcInfo,
                                     const iohs_instances_t & i_iohs_instance)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommExchangeSlave: mProc=0x%.08X "
              "Looking for message from master node via iohs connection "
              "n%d/p%d/iohs%d",
              get_huid(i_mProcInfo.tgt),
              i_iohs_instance.peerNodeInstance,
              i_iohs_instance.peerProcInstance,
              i_iohs_instance.peerIohsInstance);

    // Pointer to buffer used for transferring and receiving data
    // from nodeCommTransferSend() and nodeCommTransferRecv()
    uint8_t * data_buffer = nullptr;

    do
    {
        // Used for check that right node indicated itself as master
        uint8_t my_linkId = 0;
        uint8_t my_mboxId = 0;
        getLinkMboxFromIohsInstance(i_iohs_instance.myIohsInstance,
                                    i_iohs_instance.myIohsRelLink,
                                    my_linkId,
                                    my_mboxId);


        // First Wait for Message From Master
        if (data_buffer != nullptr)
        {
            free(data_buffer);
            data_buffer = nullptr;
        }
        size_t data_size = 0;
        // The node comm control and data regs live on PAUC parents of IOHS
        TARGETING::Target* l_paucParent =
                TARGETING::getImmediateParentByAffinity(i_iohs_instance.myIohsTarget);
        err = nodeCommTransferRecv(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   i_iohs_instance.peerNodeInstance,
                                   NCT_TRANSFER_SBID,
                                   data_buffer,
                                   data_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeSlave: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_buffer!=nullptr,"nodeCommExchangeSlave: data_buffer returned as nullptr");


        // Add receiver Link Id to the message data
        msg_format_t msg_data;
        memcpy(&(msg_data.value), data_buffer, data_size);
        msg_data.receiver_linkId = my_linkId;

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeSlave: Msg received, "
                  "after adding recv Link Id (%d), 0x%.16llX will "
                  "be stored in the TPM",
                  my_linkId, msg_data.value);

        // Push this msg_data to TPM
        err = nodeCommLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: Error Back "
                      "From nodeCommLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Send a message back to the master node
        // Pass in expected peer linkId for nonce logging/extending purposes
        uint8_t peer_linkId = 0;
        uint8_t peer_mboxId = 0;
        getLinkMboxFromIohsInstance(i_iohs_instance.peerIohsInstance,
                                    // same relative link for peer path:
                                    i_iohs_instance.myIohsRelLink,
                                    peer_linkId,
                                    peer_mboxId);

        // Get random number from TPM
        msg_data.value = 0;
        err = nodeCommGetRandom(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: Error Back "
                      "From nodeCommGetRandom: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Set the send and expected receive LinkIds in the nonce
        msg_data.origin_linkId = my_linkId;
        msg_data.receiver_linkId = my_linkId;

        // Send a message to a slave
        size_t tmp_size = sizeof(msg_data.value);
        err = nodeCommTransferSend(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   i_iohs_instance.peerNodeInstance,
                                   NCT_TRANSFER_SBID,
                                   reinterpret_cast<uint8_t*>
                                     (&(msg_data.value)),
                                   tmp_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: "
                      "nodeCommAbusTransferSend returned an error");
            break;
        }

        // Push this msg_data to TPM
        err = nodeCommLogNonce(msg_data.value);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: Error Back From "
                      "nodeCommLogNonce: "
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(err));
            break;
        }

        // Wait for Quote Request from Master Node
        if (data_buffer != nullptr)
        {
            free(data_buffer);
            data_buffer = nullptr;
        }
        data_size = 0;
        err = nodeCommTransferRecv(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   i_iohs_instance.peerNodeInstance,
                                   NCT_TRANSFER_QUOTE_REQUEST,
                                   data_buffer,
                                   data_size);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeSlave: "
                      "nodeCommTransferRecv returned an error");
           break;
        }
        // If no err is returned, data_buffer should be valid, but do a
        // sanity check here to be certain
        assert(data_buffer!=nullptr,"nodeCommExchangeSlave: data_buffer returned as nullptr");

        // Cast the data received into a MasterQuoteRequestBlob
        MasterQuoteRequestBlob quote_request{};
        memcpy(&quote_request, data_buffer, data_size);

        // re-use data_buffer and data_size for the Quote Response
        if (data_buffer != nullptr)
        {
            free(data_buffer);
            data_buffer = nullptr;
        }
        data_size = 0;

        std::unique_ptr<uint8_t>l_quotePtr = nullptr;

        // Generate the Quote Response
        err = nodeCommGenSlaveQuoteResponse(&quote_request,
                                            data_size,
                                            l_quotePtr);

        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchangeSlave: "
                      "nodeCommGenSlaveQuoteResponse returned an error");
           errlCommit(err, SECURE_COMP_ID);
           // Continuing to send the response to master
        }

        err = flushTpmContext();
        if(err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: Could not flush TPM context");
            errlCommit(err, SECURE_COMP_ID);
            // Continuing to send the response to master
        }

        // Send the Quote Response
        err = nodeCommTransferSend(l_paucParent,
                                   my_linkId,
                                   my_mboxId,
                                   i_iohs_instance.peerNodeInstance,
                                   NCT_TRANSFER_QUOTE_RESPONSE,
                                   l_quotePtr.get(),
                                   data_size);

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchangeSlave: "
                      "nodeCommTransferSend returned an error");
            break;
        }

        // Nothing left for slave node to do

    } while( 0 );

    if (data_buffer != nullptr)
    {
        free(data_buffer);
        data_buffer = nullptr;
    }


    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommExchangeSlave: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommExchangeSlave

/**
 * @brief Helper function to send a sync message to a node or to receive
 *        a sync message from a node.
 *
 * @param[in] i_sendMessage whether to send or receive the sync message
 * @param[in] i_iohsInstance IOHS information used to send/receive message
 *            to/from the other node
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t sendRecvNodeSyncMessage(const bool i_sendMessage,
                                   const iohs_instances_t& i_iohsInstance)
{
    errlHndl_t l_errl = nullptr;

    uint8_t l_myLinkId = 0;
    uint8_t l_myMboxId = 0;
    uint8_t l_peerLinkId = 0;
    uint8_t l_peerMboxId = 0;

    getLinkMboxFromIohsInstance(i_iohsInstance.myIohsInstance,
                                i_iohsInstance.myIohsRelLink,
                                l_myLinkId,
                                l_myMboxId);

    getLinkMboxFromIohsInstance(i_iohsInstance.peerIohsInstance,
                                // same relative link for peer path:
                                i_iohsInstance.myIohsRelLink,
                                l_peerLinkId,
                                l_peerMboxId);

    TRACFCOMP(g_trac_nc,INFO_MRK"sendRecvNodeSyncMessage: %s message; "
              "my: linkId=%d, mboxId=%d, IohsInstance=%d. "
              "expected peer: n%d linkId=%d, mboxId=%d, IohsInstance=%d",
              i_sendMessage ? "sending" : "receiving",
              l_myLinkId, l_myMboxId, i_iohsInstance.myIohsInstance,
              i_iohsInstance.peerNodeInstance, l_peerLinkId,
              l_peerMboxId, i_iohsInstance.peerIohsInstance);

    // The node comm control and data regs live on PAUC parents of IOHS
    TARGETING::Target* l_paucParent =
           TARGETING::getImmediateParentByAffinity(i_iohsInstance.myIohsTarget);
    uint8_t* l_buffer = nullptr;
    size_t l_size = 0;

    if(i_sendMessage)
    {
        l_errl = nodeCommTransferSend(l_paucParent,
                                      l_myLinkId,
                                      l_myMboxId,
                                      i_iohsInstance.peerNodeInstance,
                                      NCT_NODE_SYNC,
                                      l_buffer,
                                      l_size);
    }
    else
    {
        l_errl = nodeCommTransferRecv(l_paucParent,
                                      l_myLinkId,
                                      l_myMboxId,
                                      i_iohsInstance.peerNodeInstance,
                                      NCT_NODE_SYNC,
                                      l_buffer,
                                      l_size);
    }
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"sendRecvNodeSyncMessage: Could not %s sync message to/from node %d"
                  TRACE_ERR_FMT, i_sendMessage ? "send" : "receive", i_iohsInstance.peerNodeInstance,
                  TRACE_ERR_ARGS(l_errl));
    }

    return l_errl;
}

/**
 * @brief Performs a sync with all other nodes on the system. A sync message is an empty message
 *        whose purpose is to indicate that the node is currently not in the middle of other
 *        multinode transactions. Primary node will send this message to all other nodes, and
 *        secondary nodes will wait for this message from the primary node.
 *
 * @param[in] i_iohsInstances the array of IOHS target information used to communicate with other
 *            nodes.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t syncWithAllNodes(const std::vector<iohs_instances_t>& i_iohsInstances)
{
    errlHndl_t l_errl = nullptr;
    const bool SEND_MESSAGE = true;
    const bool RECEIVE_MESSAGE = false;

    // Primary node will send the sync message to all secondary nodes
    if(TARGETING::UTIL::isCurrentMasterNode())
    {
        // Send a sync message to all secondary nodes
        for(const auto& l_iohsInstance : i_iohsInstances)
        {
            l_errl = sendRecvNodeSyncMessage(SEND_MESSAGE, l_iohsInstance);
            if(l_errl)
            {
                break;
            }
        }
        TRACFCOMP(g_trac_nc,INFO_MRK"syncWithAllNodes: Primary node completed sync with other nodes");
    }
    else
    {
        TRACFCOMP(g_trac_nc,INFO_MRK"syncWithAllNodes: Receiving the sync message from primary node");
        // The array of IOHS targes is sorted by node ID, so the first IOHS target
        // is connected to node 0. Look for a message from the links associated with
        // that target.
        l_errl = sendRecvNodeSyncMessage(RECEIVE_MESSAGE, i_iohsInstances[0]);
    }

    return l_errl;
}


/**
 * @brief Performs a multithreaded nonce exchange between all nodes in the system. Each node
 *        sends its nonce (56-bit random number and 8-bit link info) to every other node.
 *        Each node generates a unique nonce per each other node it needs to communicate with.
 *
 * @param[in] i_iohsInstances the array of IOHS target information used to communicate with other
 *            nodes.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t exchangeNoncesMultithreaded(const std::vector<iohs_instances_t>& i_iohsInstances)
{
    Util::ThreadPool<NodeCommExchangeNonces> l_threadpool;

    for(const auto& l_iohsInstance: i_iohsInstances)
    {
        l_threadpool.insert(new NodeCommExchangeNonces(l_iohsInstance));
    }

    // Get the number of nodes on the machine (each thread will service a
    // different node)
    auto l_hbImages = TARGETING::UTIL::assertGetToplevelTarget()->
                        getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
    const int l_nodeCnt = __builtin_popcount(l_hbImages);
    // A thread per each node OTHER than this one (so, total nodes - 1)
    Util::ThreadPoolManager::setThreadCount(l_nodeCnt - 1);

    // Start all threads
    l_threadpool.start();

    // Wait for the threads to finish running
    errlHndl_t l_errl = l_threadpool.shutdown();
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"exchangeNoncesMultithreaded: Error returned from thread pool"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
    }
    else
    {
        // Sync with all nodes
        l_errl = syncWithAllNodes(i_iohsInstances);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"exchangeNoncesMultithreaded: Could not sync the nodes"
                      TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        }
    }
    return l_errl;
}

/**
 * @brief Helper function to extend hashes of all of the collected quotes from
 *        other nodes into the TPM. The full quotes in binary form are copied
 *        into the TPM log.
 *         The function cleans up all dynamically-allocated memory.
 *
 * @param[in] i_quotes the vector of quotes to extend to the TPM
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t extendAllQuotes(std::vector<quoteInfo_t>& i_quotes)
{
    errlHndl_t l_errl = nullptr;
#ifdef CONFIG_TPMDD
    for(const auto& l_quoteInf : i_quotes)
    {
        // Extend the hash of the quote to PCR 1 and include the whole quote
        // in binary form as the message in the TPM log
        SHA512_t l_quoteHash = {};
        hashBlob(l_quoteInf.quoteData, l_quoteInf.quoteSize, l_quoteHash);
        l_errl = TRUSTEDBOOT::pcrExtend(TRUSTEDBOOT::PCR_1,
                                        TRUSTEDBOOT::EV_PLATFORM_CONFIG_FLAGS,
                                        l_quoteHash,
                                        sizeof(SHA512_t),
                                        l_quoteInf.quoteData,
                                        l_quoteInf.quoteSize);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"extendAllQuotes: Could not extend quote");
            break;
        }
    }
#endif

    // Free all quotes
    for(auto& l_quoteInf : i_quotes)
    {
        delete[] l_quoteInf.quoteData;
        l_quoteInf.quoteData = nullptr;
    }
    // Clear the quote vector
    i_quotes.clear();

    return l_errl;
}

/**
 * @brief Perform quote exchange between the nodes on the system. Each node, when communicating with
 *        other node, will act as a requestor once and as a responder once, so in any given system,
 *        each node will send its quote to every other node and will receive quotes from every other
 *        node. If the current node is a lower node ID, it will request the quote first, and then
 *        send its quote to the peer. Otherwise, the opposite happens.
 *
 * @param[in] i_iohsInstances the array of IOHS information of all connected peer nodes.
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t exchangeQuotesMultithreaded(const std::vector<iohs_instances_t>& i_iohsInstances)
{
    errlHndl_t l_errl = nullptr;

    do {
    // First, expand each TPM's log. The TPM's logs are created early in IPL,
    // when we're still running out of the cache, so the sizes of the logs
    // are quite small. We need to expand each log here so that it can fit
    // all of the quotes from all of the nodes. It is safe to do so, since
    // at this point we will have expanded into full memory.
    TARGETING::TargetHandleList l_tpms;
    TRUSTEDBOOT::getTPMs(l_tpms);
    for(const auto& l_tpm : l_tpms)
    {
        l_errl = TRUSTEDBOOT::expandTpmLog(l_tpm);
        if(l_errl)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"exchangeQuotesMultithreaded: could not expand the TPM log for TPM HUID 0x%x"
                      TRACE_ERR_FMT, TARGETING::get_huid(l_tpm), TRACE_ERR_ARGS(l_errl));
            break;
        }
    }
    if(l_errl)
    {
        break;
    }

    // Pre-generate attestation keys
    l_errl = generateAKCertificate();
    if(l_errl)
    {
        break;
    }

    Util::ThreadPool<NodeCommExchangeQuotes> l_threadpool;
    std::vector<quoteInfo_t> l_quotes;

    for(const auto& l_iohsInstance : i_iohsInstances)
    {
        l_threadpool.insert(new NodeCommExchangeQuotes(l_iohsInstance, &l_quotes));
    }

    // Get the number of nodes on the machine (each thread will service a
    // different node)
    auto l_hbImages = TARGETING::UTIL::assertGetToplevelTarget()->
                        getAttr<TARGETING::ATTR_HB_EXISTING_IMAGE>();
    const int l_nodeCnt = __builtin_popcount(l_hbImages);
    // A thread per each node OTHER than this one (so, total nodes - 1)
    Util::ThreadPoolManager::setThreadCount(l_nodeCnt - 1);

    // Start all threads
    l_threadpool.start();

    // Wait for the threads to finish running
    l_errl = l_threadpool.shutdown();
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"exchangeQuotesMultithreaded: Error returned from thread pool"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Ensure all nodes have completed their exchanges. The primary node will send out
    // a sync message to all nodes.
    l_errl = syncWithAllNodes(i_iohsInstances);
    if(l_errl)
    {
       TRACFCOMP(g_trac_nc,ERR_MRK"exchangeQuotesMultithreaded: Could not sync the nodes"
                 TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Flush all secure info/certificates from the TPM
    l_errl = flushTpmContext();
    if(l_errl)
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"exchangeQuotesMultithreaded: Could not flush TPM context"
                  TRACE_ERR_FMT, TRACE_ERR_ARGS(l_errl));
        break;
    }

    // Extend all received quotes to TPM
    l_errl = extendAllQuotes(l_quotes);
    if(l_errl)
    {
        break;
    }

    }while(0);

    return l_errl;
}

/**
 *  @brief Runs the procedure for the drawers/nodes to exchange messages
 *         over the ABUS Link Mailbox facility
 *
 *  Defined in nodecommif.H
 */
errlHndl_t nodeCommExchange(void)
{
    errlHndl_t err = nullptr;

#ifndef CONFIG_TPMDD
    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: Not running procedure "
              "since CONFIG_TPMDD is not set");
#else


    master_proc_info_t mProcInfo;
    std::vector<iohs_instances_t> iohs_instances;
    char * l_phys_path_str = nullptr;
    char * l_peer_path_str = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommExchange:");

    do
    {
    Target* sys = TARGETING::UTIL::assertGetToplevelTarget();

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
                TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                          "this node is position %d of %d total nodes "
                          "(l_nodeId=%d, hb_existing_image=0x%X)",
                          my_round, total_nodes, my_nodeid, hb_images );
                break;
            }
        }
    }

    // Get master proc for this node
    err = targetService().queryMasterProcChipTargetHandle(mProcInfo.tgt);
    if (err)
    {
        TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommExchange: "
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
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchange: "
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
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        ERRORLOG::ErrlUserDetailsStringSet path;
        path.add("mProc PHYS Entity Path", l_phys_path_str);
        path.addToLog(err);

        break;
    }
    mProcInfo.nodeInstance = l_peMasterNode.instance;
    mProcInfo.procInstance = l_peMasterProc.instance;
    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
              "Master Proc 0x%.08X: PHYS_PATH=%s: "
              "nodeInstance=%d, procInstance=%d",
              get_huid(mProcInfo.tgt),
              l_phys_path_str,
              mProcInfo.nodeInstance,
              mProcInfo.procInstance);

    // Walk Through IOHS Chiplets on the Master Proc
    TargetHandleList l_iohsTargetList;
    getChildChiplets(l_iohsTargetList, mProcInfo.tgt, TYPE_IOHS);

    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: proc 0x%.08X has "
              "%d functional IOHS Chiplets",
              get_huid(mProcInfo.tgt), l_iohsTargetList.size());

    // Loop through IOHS Targets and evaluate their PEER_TARGETs
    for (const auto & l_iohsTgt : l_iohsTargetList)
    {
        if(l_iohsTgt->getAttr<TARGETING::ATTR_IOHS_CONFIG_MODE>() !=
           TARGETING::IOHS_CONFIG_MODE_SMPA)
        {
            // Only looking for SMPA connection types
            continue;
        }

        EntityPath l_peerPath = l_iohsTgt->getAttr<ATTR_PEER_PATH>();
        EntityPath::PathElement l_peProc =
                                  l_peerPath.pathElementOfType(TYPE_PROC);

        if (l_peer_path_str != nullptr)
        {
            free(l_peer_path_str);
        }
        l_peer_path_str = l_peerPath.toString();

        if(l_peProc.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X "
                      "IOHS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find PROC in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str);
            continue;
        }

        // check that proc has same position as our master
        if (l_peProc.instance != mProcInfo.procInstance)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X "
                      "IOHS HUID 0x%.08X's PEER_PATH %s because PROC "
                      "Instance=%d does not match masterProc Instance=%d",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str, l_peProc.instance,
                      mProcInfo.procInstance);
            continue;
        }

        EntityPath::PathElement l_peNode =
                                  l_peerPath.pathElementOfType(TYPE_NODE);
        if(l_peNode.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X "
                      "IOHS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find NODE in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str);
            continue;
        }

        // Check that node exists and isn't this node
        if (!((mask >> l_peNode.instance) & hb_images) ||
             (l_peNode.instance == my_nodeid))
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X "
                      "IOHS HUID 0x%.08X's PEER_PATH %s because either "
                      "Node=%d is not configured or is this node (%d)",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str, l_peNode.instance, my_nodeid);
            continue;
        }

        iohs_instances_t l_iohsInstance;

        EntityPath::PathElement l_peIohs =
                                  l_peerPath.pathElementOfType(TYPE_IOHS);
        if(l_peIohs.type == TYPE_NA)
        {
            TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X "
                      "IOHS HUID 0x%.08X's PEER_PATH %s because "
                      "cannot find OBUS in PEER_PATH",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str);
            continue;
        }

        bool link0_trained = false;
        bool link1_trained = false;
        uint64_t fir_data = 0;
        err = getIohsTrainedLinks(l_iohsTgt,
                                  link0_trained,
                                  link1_trained,
                                  fir_data);
        if (err)
        {
            TRACFCOMP(g_trac_nc, ERR_MRK"nodeCommExchange: "
                      "getIohsTrainedLinks returned error so "
                      "Skipping masterProc 0x%.08X IOHS HUID 0x%.08X. "
                      TRACE_ERR_FMT,
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      TRACE_ERR_ARGS(err));
            break;
        }
        else
        {
            TRACFCOMP(g_trac_nc, INFO_MRK"nodeCommExchange: "
                      "getIohsTrainedLinks: link0=%d, link1=%d",
                      link0_trained, link1_trained);

            l_iohsInstance.myIohsRelLink = (link0_trained) ? 0 :
                                             ((link1_trained) ? 1 :
                                               NCDD_INVALID_LINK_MBOX);

            if (l_iohsInstance.myIohsRelLink == NCDD_INVALID_LINK_MBOX)
            {
               TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                         "Skipping masterProc 0x%.08X "
                         "IOHS HUID 0x%.08X's because neither link has been "
                         "trained: link0=%d, link1=%d (fir_data=0x%.16llX)",
                         get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                         link0_trained, link1_trained, fir_data);
                continue;
            }

        }

        // Using this IOHS instance so save it off
        l_iohsInstance.peerIohsInstance = l_peIohs.instance;
        l_iohsInstance.peerProcInstance = l_peProc.instance;
        l_iohsInstance.peerNodeInstance = l_peNode.instance;
        l_iohsInstance.myIohsInstance = l_iohsTgt->getAttr<ATTR_REL_POS>();
        l_iohsInstance.myIohsTarget = l_iohsTgt;
        l_iohsInstance.myNodeInstance = my_nodeid;

        // Before adding to list check that on a 2-node system that we ignore
        // redundant connections to the same node
        if (total_nodes==2)
        {
            bool l_duplicate_found = false;
            for (auto l_saved_instance : iohs_instances)
            {
                if (l_saved_instance.peerNodeInstance ==
                    l_iohsInstance.peerNodeInstance)
                {
                    TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "Skipping masterProc 0x%.08X IOHS HUID 0x%.08X's "
                      "PEER_PATH %s because already have saved connection to "
                      "that node: myObusInstance=%d, peerInstance:n%d/p%d/obus%d",
                      get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                      l_peer_path_str,
                      l_saved_instance.myIohsInstance,
                      l_saved_instance.peerNodeInstance,
                      l_saved_instance.peerProcInstance,
                      l_saved_instance.peerIohsInstance);

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

        iohs_instances.push_back(l_iohsInstance);
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: Using masterProc 0x%.08X "
                  "IOHS HUID 0x%.08X's peer path %s with iohs_instance "
                  "myIohsInstance=%d, peer=n%d/p%d/obus%d (vector size=%d)",
                  get_huid(mProcInfo.tgt), get_huid(l_iohsTgt),
                  l_peer_path_str, l_iohsInstance.myIohsInstance,
                  l_iohsInstance.peerNodeInstance,
                  l_iohsInstance.peerProcInstance,
                  l_iohsInstance.peerIohsInstance, iohs_instances.size());
    }

    // If invalid number of peer paths fail
    if((iohs_instances.size() == 0) ||
       (iohs_instances.size() != (static_cast<uint32_t>(total_nodes)-1)))
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommExchange: "
                  "ERR: Invalid number of PEER_PATHs %d found for proc=0x%.08X "
                  "when there are %d nodes in the system",
                  iohs_instances.size(), get_huid(mProcInfo.tgt),
                  total_nodes);

        /*@
         * @errortype
         * @reasoncode       RC_NCEX_INVALID_INSTANCE_COUNT
         * @moduleid         MOD_NCEX_MAIN
         * @userdata1        Master Proc Target HUID
         * @userdata2[0:31]  Number of Valid IOHS Instances
         * @userdata2[32:63] Total Number Of Nodes
         * @devdesc          When processing the IOHS Peer paths, the wrong
         *                   count of valid paths was found
         * @custdesc         Trusted Boot failure
         */
        err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       MOD_NCEX_MAIN,
                                       RC_NCEX_INVALID_INSTANCE_COUNT,
                                       get_huid(mProcInfo.tgt),
                                       TWO_UINT32_TO_UINT64(
                                         iohs_instances.size(),
                                         total_nodes),
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT );

        break;
    }


    // Master node should have lowest node number in vector of instance info.
    // So sort here by node number and then only pass first instance to
    // nodeCommExchangeSlave() below.  Then when message is received it
    // will be checked against the expected master instance.
    std::sort(iohs_instances.begin(),
              iohs_instances.end(),
              [](iohs_instances_t & lhs,
                 iohs_instances_t & rhs)
    {
        return lhs.peerNodeInstance < rhs.peerNodeInstance;
    });


    // @TODO RTC 194053 - This won't work on simics until the action files
    // are there
    if (Util::isSimicsRunning())
    {
        TRACFCOMP(g_trac_nc,"nodeCommExchange: actual operation is not "
                  "supported on simics yet");
        break;
    }

#ifdef CONFIG_NODE_COMM_V1
    if (TARGETING::UTIL::isCurrentMasterNode())
    {
        err = nodeCommExchangeMaster(mProcInfo,iohs_instances);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "nodeCommExchangeMaster returned an error");
           break;
        }
    }
    else
    {
        // Only pass first instance, which should be master instance
        err = nodeCommExchangeSlave(mProcInfo,
                                        iohs_instances[0]);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommExchange: "
                      "nodeCommExchangeSlave returned an error");
           break;
        }
    }
#else

    // Exchange the nonces first
    err = exchangeNoncesMultithreaded(iohs_instances);
    if(err)
    {
        break;
    }

    // Now exchange the quotes
    err = exchangeQuotesMultithreaded(iohs_instances);
    if(err)
    {
        break;
    }
#endif

    if(err)
    {
        break;
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommExchange: %s: "
              TRACE_ERR_FMT,
              (err == nullptr) ? "SUCCESSFUL" : "FAILED",
              TRACE_ERR_ARGS(err));

    if (err)
    {
        // Flush the trace buffers for debug purposes
        TRAC_FLUSH_BUFFERS();
        if(!TRUSTEDBOOT::isTpmRequired())
        {
            TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommExchange:An error occurred"
                     " during secure node communication, but the TPM required "
                     "policy is not set, so the error will not be propagated."
                     " Original error RC: 0x%.04X; PLID: 0x%.08X."
                     " Deleting the error log and continuing.",
                     err->reasonCode(),
                     err->plid());
            delete err;
            err = nullptr;
        }
        else
        {
            err->collectTrace(SECURE_COMP_NAME);
            err->collectTrace(NODECOMM_TRACE_NAME);
            err->collectTrace(TRBOOT_COMP_NAME);
        }
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

} // end of nodeCommExchange

} // End NODECOMM namespace

} // End SECUREBOOT namespace


