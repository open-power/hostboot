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
         * @custdesc         Secure Boot failure
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
    tpm_tgt = tpmTargetList[0];
    // This function call requires the CONFIG check for compilation purposes,
    // but no extra error handling is needed as it should not have gotten this
    // far if CONFIG_TPMDD wasn't set
#ifdef CONFIG_TPMDD
    err = TRUSTEDBOOT::GetRandom(tpm_tgt, o_nonce);
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

        // @TODO CQ: SW444320
        //
        // Restore errlCommit of this error as part of the referenced
        // defect fix.  Until that fix is in place, committing an error
        // in this path with the intent of continuing would set up a condition
        // where FSP fails to wake Hostboot out of winkle state.
        delete err;
        err=nullptr;
        //errlCommit(err, SECURE_COMP_ID);
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
        err =  nodeCommAbusSendMessage(i_mProcInfo.tgt,
                                       msg_data.value,
                                       my_linkId,
                                       my_mboxId);

        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                     "nodeCommAbusSendMessage returned an error");
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
        uint8_t actual_recv_linkId = 0;
        uint8_t actual_recv_mboxId = 0;
        uint64_t data_recv = 0;
        err = nodeCommAbusRecvMessage(i_mProcInfo.tgt,
                                      data_recv,
                                      actual_recv_linkId,
                                      actual_recv_mboxId);


        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                     "nodeCommAbusRecvMessage returned an error");

           // Since we know what bus we expected the message on, call it out
           addNodeCommBusCallout(NCDD_MODE_ABUS,
                                 i_mProcInfo.tgt,
                                 my_linkId,
                                 err);
           break;
        }

        // Verify that actual receive link/mboxIds were the same as the
        // ones this node sent from
        if ((my_linkId != actual_recv_linkId) ||
            (my_mboxId != actual_recv_mboxId))
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                      "Expected Link (%d) Mbox (%d) IDs DO NOT Match the "
                      "Actual Link (%d) Mbox (%d) IDs the return message used",
                       my_linkId, my_mboxId,
                       actual_recv_linkId, actual_recv_mboxId);

            /*@
             * @errortype
             * @reasoncode       RC_NCEX_MISMATCH_RECV_LINKS
             * @moduleid         MOD_NCEX_MASTER
             * @userdata1        Master Proc Target HUID
             * @userdata2[0:15]  Expected Link Id to receive message on
             * @userdata2[16:31] Expected Mailbox Id to receive message on
             * @userdata2[32:47] Acutal Link Id message was received on
             * @userdata2[48:63] Actual Mailbox Id message was receiveed on
             * @devdesc          Mismatch between expected and actual Link Mbox
             *                   Ids a secure ABUS message was received on
             * @custdesc         Secure Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NCEX_MASTER,
                                           RC_NCEX_MISMATCH_RECV_LINKS,
                                           get_huid(i_mProcInfo.tgt),
                                           FOUR_UINT16_TO_UINT64(
                                             my_linkId,
                                             my_mboxId,
                                             actual_recv_linkId,
                                             actual_recv_mboxId));

            // Since we know what bus we expected the message on, call it out
            addNodeCommBusCallout(NCDD_MODE_ABUS,
                                  i_mProcInfo.tgt,
                                  my_linkId,
                                  err);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            // Grab FFDC from the target
            getNodeCommFFDC(NCDD_MODE_ABUS,
                            i_mProcInfo.tgt,
                            err);

            break;
        }

        // Add receiver Link Id to the message data
        msg_data.value = data_recv;
        msg_data.receiver_linkId = actual_recv_linkId;
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeMaster: Msg received "
                  "= 0x%.16llX. After adding recv link (%d), 0x%.16llX will be "
                  "stored in the TPM",
                  data_recv, actual_recv_linkId, msg_data.value);


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

    } while( 0 );

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
        uint8_t actual_linkId = 0;
        uint8_t actual_mboxId = 0;
        uint64_t data_recv = 0;
        err = nodeCommAbusRecvMessage(i_mProcInfo.tgt,
                                      data_recv,
                                      actual_linkId,
                                      actual_mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommAbusRecvMessage returned an error");

           // Since we know what bus we expected the message on, call it out
           addNodeCommBusCallout(NCDD_MODE_ABUS,
                                 i_mProcInfo.tgt,
                                 my_linkId,
                                 err);
           break;
        }

        // Verify that actual receive link/mboxIds were the same as the
        // expected ones
        if ((actual_linkId != my_linkId) ||
            (actual_mboxId != my_mboxId))
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: "
                      "Expected Link (%d) Mbox (%d) IDs DO NOT Match the "
                      "Actual Link (%d) Mbox (%d) IDs the message was "
                      "received on",
                       my_linkId, my_mboxId,
                       actual_linkId, actual_mboxId);

            /*@
             * @errortype
             * @reasoncode       RC_NCEX_MISMATCH_RECV_LINKS
             * @moduleid         MOD_NCEX_SLAVE
             * @userdata1        Master Proc Target HUID
             * @userdata2[0:15]  Expected Link Id to receive message on
             * @userdata2[16:31] Expected Mailbox Id to receive message on
             * @userdata2[32:47] Actual Link Id message was received on
             * @userdata2[48:63] Actual Mailbox Id message was receiveed on
             * @devdesc          Mismatch between expected and actual Link Mbox
             *                   Ids a secure ABUS message was received on
             * @custdesc         Secure Boot failure
             */
            err = new ERRORLOG::ErrlEntry( ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                           MOD_NCEX_SLAVE,
                                           RC_NCEX_MISMATCH_RECV_LINKS,
                                           get_huid(i_mProcInfo.tgt),
                                           FOUR_UINT16_TO_UINT64(
                                             my_linkId,
                                             my_mboxId,
                                             actual_linkId,
                                             actual_mboxId));

            // Since we know what bus we expected the message on, call it out
            addNodeCommBusCallout(NCDD_MODE_ABUS,
                                  i_mProcInfo.tgt,
                                  my_linkId,
                                  err);

            // Or HB code failed to do the procedure correctly
            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_LOW);

            // Grab FFDC from the target
            getNodeCommFFDC(NCDD_MODE_ABUS,
                            i_mProcInfo.tgt,
                            err);

            break;
        }

        // Add receiver Link Id to the message data
        msg_format_t msg_data;
        msg_data.value = data_recv;
        msg_data.receiver_linkId = actual_linkId;
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeSlave: Msg received "
                  "= 0x%.16llX. After adding recv Link Id (%d), 0x%.16llX will "
                  "be stored in the TPM",
                  data_recv, actual_linkId, msg_data.value);


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
        err =  nodeCommAbusSendMessage(i_mProcInfo.tgt,
                                       msg_data.value,
                                       my_linkId,
                                       my_mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommAbusSendMessage returned an error");
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
         * @custdesc         Secure Boot failure
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
         * @custdesc         Secure Boot failure
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


