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
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <targeting/common/targetservice.H>
#include <devicefw/userif.H>
#include <devicefw/driverif.H>
#include <secureboot/secure_reasoncodes.H>
#include <secureboot/nodecommif.H>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/targplatutil.H>
#include <sys/internode.h>
#include <sys/time.h>
#include <sys/task.h>
#include <util/misc.H>

#include "node_comm.H"

// ----------------------------------------------
// Defines
// ----------------------------------------------
// If the link(s) are up the operation should complete right away
// so there will only be a short polling window
#define NODE_COMM_POLL_DELAY_NS (1 * NS_PER_MSEC)  // Sleep for 1ms per poll
// FSP is expecting a reply in 30 seconds, so leave some buffer
#define NODE_COMM_POLL_DELAY_TOTAL_NS (25 * NS_PER_SEC) // Total time 25s

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
    uint8_t  sendObusInstance = 0;

    // Expect to receive on the PEER_PATH instances
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
 *  @brief This function waits for the master processor of the current node to
 *         receive a message over ABUS from a master processor on another node.
 *         This function also handles storing the message received into the TPM.
 *
 *  @param[in]  i_mProcInfo - Information about Master Proc
 *  @param[out] o_linkId - Link Id that received the message
 *  @param[out] o_mboxId - Mailbox Id that received the message
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommAbusRecvMessage(const master_proc_info_t & i_mProcInfo,
                                   uint64_t & o_linkId,
                                   uint64_t & o_mboxId)
{

    errlHndl_t err = nullptr;
    bool attn_found = false;

    const uint64_t interval_ns = NODE_COMM_POLL_DELAY_NS;
    uint64_t time_polled_ns = 0;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusRecvMessage: mProc=0x%.08X",
              get_huid(i_mProcInfo.tgt));

    do
    {
        do
        {

        // Look for Attention
        err = nodeCommMapAttn(i_mProcInfo.tgt,
                              NCDD_MODE_ABUS,
                              attn_found,
                              o_linkId,
                              o_mboxId);
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusRecvMessage: Error Back "
                      "From nodeCommMapAttn: Tgt=0x%X: "
                      TRACE_ERR_FMT,
                      get_huid(i_mProcInfo.tgt),
                      TRACE_ERR_ARGS(err));
            break;
        }
        if (attn_found == true)
        {
            TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusRecvMessage: "
              "nodeCommMapAttn attn_found (%d) for Tgt=0x%X, link=%d, mbox=%d",
              attn_found, get_huid(i_mProcInfo.tgt), o_linkId, o_mboxId);
            break;
        }

        // @TODO RTC 184518 Create Error For Timeout
        if (time_polled_ns >= NODE_COMM_POLL_DELAY_TOTAL_NS)
        {
            TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusRecvMessage: "
              "timeout: time_polled_ns-0x%.16llX, MAX=0x%.16llX, "
              "interval=0x%.16llX",
              time_polled_ns, NODE_COMM_POLL_DELAY_TOTAL_NS, interval_ns);
            break;
        }

        // Sleep before polling again
        nanosleep( 0, interval_ns );
        task_yield(); // wait patiently
        time_polled_ns += interval_ns;

        } while(attn_found == false);

    if (err)
    {
        break;
    }

    if (attn_found == true)
    {
        //  Read message on proc with Link Mailbox found above
        uint64_t data = 0;
        size_t size = sizeof(data);
        err = DeviceFW::deviceRead(i_mProcInfo.tgt,
                                   &data,
                                   size,
                                   DEVICE_NODECOMM_ADDRESS(NCDD_MODE_ABUS,
                                                           o_linkId,
                                                           o_mboxId));

        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommRecvMessage: Error Back From "
                      "Abus MBox Read: Tgt=0x%X, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_mProcInfo.tgt), o_linkId, o_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }
        // Add receiver Link Id to the message data
        msg_format_t msg_data;
        msg_data.value = data;
        msg_data.receiver_linkId = o_linkId;
        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommRecvMessage: Msg retrieved = "
                  "0x%.16llX. After adding recv Link Id, 0x%.16llX will be "
                  "stored in the TPM",
                  data, msg_data.value);


        // @TODO RTC 184518 Push this msg_data to TPM
    }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusRecvMessage: "
              "Tgt=0x%X, link=%d, mbox=%d attn_found=%d: "
              TRACE_ERR_FMT,
              get_huid(i_mProcInfo.tgt), o_linkId, o_mboxId, attn_found,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusRecvMessage

/**
 *  @brief This function sends a message over the ABUS from the
 *          master processor of the current node to a master processor
 *          on another node. This function also handles the generation
 *          of a random number from the TPM to be used as part of the message.
 *
 *  @param[in] i_mProcInfo - Information about Master Proc
 *  @param[in] i_linkId - Link Id Message is sent from
 *  @param[in] i_mboxId - Mailbox Id Message is sent from
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommAbusSendMessage(const master_proc_info_t & i_mProcInfo,
                                   const uint8_t & i_linkId,
                                   const uint8_t & i_mboxId)
{

    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusSendMessage: mProc=0x%.08X "
              "to communicate through linkId=%d mboxId=%d",
              get_huid(i_mProcInfo.tgt), i_linkId, i_mboxId);

    do
    {
        // @TODO RTC 184518 get random number from TPM; use node huid for now
        Target* node_tgt = nullptr;
        TARGETING::UTIL::getMasterNodeTarget(node_tgt);
        msg_format_t msg_data;
        msg_data.value = get_huid(node_tgt);
        msg_data.origin_linkId = i_linkId;

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusSendMessage: "
                  "linkId=%d, mboxId=%d, data=0x%.016llX",
                  i_linkId, i_mboxId, msg_data.value);

        // Send Data
        size_t size = sizeof(msg_data.value);
        err = DeviceFW::deviceWrite(i_mProcInfo.tgt,
                                    &msg_data.value,
                                    size,
                                    DEVICE_NODECOMM_ADDRESS(NCDD_MODE_ABUS,
                                                            i_linkId,
                                                            i_mboxId));
        if (err)
        {
            TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusSendMessage: Error Back "
                      "From Abus MBox Send: Tgt=0x%X, link=%d, mbox=%d: "
                      TRACE_ERR_FMT,
                      get_huid(i_mProcInfo.tgt), i_linkId, i_mboxId,
                      TRACE_ERR_ARGS(err));
            break;
        }

    } while( 0 );

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusSendMessage: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    return err;

} // end of nodeCommAbusSendMessage


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
              "to communicate through %d obus connections",
              get_huid(i_mProcInfo.tgt), i_obus_instances.size());

    do
    {

    for ( auto const l_obus : i_obus_instances)
    {
        uint8_t send_linkId = 0;
        uint8_t send_mboxId = 0;
        getSecureLinkMboxFromObus(l_obus.sendObusInstance,
                                  send_linkId,
                                  send_mboxId);

        TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeMaster: "
                  "send_linkId=%d, send_mboxId=%d, sendObusInstance=%d",
                  send_linkId, send_mboxId, l_obus.sendObusInstance);

        // Send a message to a slave
        err =  nodeCommAbusSendMessage(i_mProcInfo, send_linkId, send_mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                      "nodeCommAbusSendMessage returned an error");
           break;
        }

        // Look for Return Message From This Slave
        uint64_t recv_linkId = 0;
        uint64_t recv_mboxId = 0;
        err = nodeCommAbusRecvMessage(i_mProcInfo,recv_linkId,recv_mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeMaster: "
                      "nodeCommAbusRecvMessage returned an error");
           break;
        }

        // @TODO RTC 184518 Verify that receive link/mboxIds were the
        // same as the send ones

    }
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
 *  @param[in] i_obus_instances - Vector containing all of the OBUS connections
 *                                that the Master Proc of this slave node has.
 *                                One of these connections will be used by the
 *                                Master Proc on the Master Node to send
 *                                messages back and forth.
 *
 *  @return errlHndl_t Error log handle
 *  @retval nullptr Operation was successful
 *  @retval !nullptr Operation failed with valid error log
 */
errlHndl_t nodeCommAbusExchangeSlave(const master_proc_info_t & i_mProcInfo,
                                     const std::vector<obus_instances_t> &
                                       i_obus_instances)
{
    errlHndl_t err = nullptr;

    TRACFCOMP(g_trac_nc,ENTER_MRK"nodeCommAbusExchangeSlave: mProc=0x%.08X "
              "Looking for message from master node via %d obus connections",
              get_huid(i_mProcInfo.tgt), i_obus_instances.size());

    do
    {
        // First Wait for Message From Master
        uint64_t linkId = 0;
        uint64_t mboxId = 0;
        err = nodeCommAbusRecvMessage(i_mProcInfo,linkId,mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,INFO_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommAbusRecvMessage returned an error");
           break;
        }

        // @TODO RTC 184518 check that right node indicated itself as master
        // and then use that value

        // Send a message back to the master node
        err =  nodeCommAbusSendMessage(i_mProcInfo, linkId, mboxId);
        if (err)
        {
           TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchangeSlave: "
                      "nodeCommAbusSendMessage returned an error");
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
                          "(l_nodeId=%d, hb_existing_image=0x%X",
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
        // @TODO RTC 184518 Make An Error Log
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
        l_obusInstance.peerObusInstance = l_peObus.instance;
        l_obusInstance.peerProcInstance = l_peProc.instance;
        l_obusInstance.peerNodeInstance = l_peNode.instance;


        l_obusInstance.sendObusInstance = l_obusTgt->getAttr<ATTR_ORDINAL_ID>();

        obus_instances.push_back(l_obusInstance);
        TRACFCOMP(g_trac_nc,"nodeCommAbusExchange: Using masterProc 0x%.08X "
                  "OBUS HUID 0x%.08X's peer path %s with obus_instance "
                  "send=%d, rcv/peer=n%d/p%d/obus%d (vector size=%d)",
                  get_huid(mProcInfo.tgt), get_huid(l_obusTgt),
                  l_peer_path_str, l_obusInstance.sendObusInstance,
                  l_obusInstance.peerNodeInstance,
                  l_obusInstance.peerProcInstance,
                  l_obusInstance.peerObusInstance, obus_instances.size());
    }

    // If invalid number of peer paths fail
    if((obus_instances.size() == 0) ||
       (obus_instances.size() != (static_cast<uint32_t>(total_nodes)-1)))
    {
        TRACFCOMP(g_trac_nc,ERR_MRK"nodeCommAbusExchange: "
                  "ERR: Invalid number of PEER_PATHs %d found when "
                  "there are %d nodes in the system",
                  obus_instances.size(), total_nodes);
        // @TODO RTC 184518 Make An Error Log
        break;
    }

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
        err = nodeCommAbusExchangeSlave(mProcInfo,obus_instances);
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

    TRACFCOMP(g_trac_nc,EXIT_MRK"nodeCommAbusExchange: "
              TRACE_ERR_FMT,
              TRACE_ERR_ARGS(err));

    if (err)
    {
        err->collectTrace(SECURE_COMP_NAME);
        err->collectTrace(NODECOMM_TRACE_NAME);
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


    return err;

} // end of nodeCommAbusExchange

} // End NODECOMM namespace

} // End SECUREBOOT namespace


