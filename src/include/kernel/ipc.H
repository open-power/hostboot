/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/ipc.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2020                        */
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
#if !defined(__IPC_H)
#define __IPC_H

#include <sys/msg.h>
#include <sys/internode.h>

#define IPC_DATA_AREA_LOCKED 0xFFFFFFFFFFFFFFFFul
#define IPC_DATA_AREA_READ   0xFFFFFFFFFFFFFFFEul
#define IPC_DATA_AREA_CLEAR  0

namespace KernelIpc
{

    /** @fn send()
     *  @brief Send an IPC message to a remote node
     *
     *  @param[in] i_q - message queue
     *  @param[in] i_msg - message
     *
     *  @note
     */
    int send(uint64_t i_q, msg_t * i_msg);

    /** @fn updateRemoteIpcAddr()
     *  @brief update the Remote Address used to send IPC
     *         messages to the specified node
     *
     *  @param[in] i_node - node
     *  @param[in] i_remoteAddr - IPC address of Remote Node's ipc_data_area
     *
     *  @note
     */
    int updateRemoteIpcAddr(uint64_t i_node, uint64_t i_remoteAddr);

    /** @fn qryLocalIpcInfo()
     *  @brief query the node and remote address other nodes will use to
     *         send messages to this IPC instance.
     *
     *  @param[in] i_pONode - buffer the node will be returned in
     *  @param[in] i_pOAddr - buffer the address will be returned in
     *
     *  @note
     */
    int qryLocalIpcInfo(uint64_t * i_pONode, uint64_t * i_pOAddr);

    /** @fn set_topology_mode
     *  @brief Tells the kernel what topology mode the system is in.
     *         0 == Mode 0; GGGC where G = Group (3 bits) and C = Chip (1 bit). In this mode the chip bit isn't used and
     *                      group=chip. That is to say that group bits correspond to the proc chip number. This mode is
     *                      for single node systems such as Rainier and Everest.
     *         1 == Mode 1; GGCC 2 bits group and 2 bits chip. Confusingly, this mode is referred to as chip=node but
     *                      the group bits actually determine the node and the chip bits are used for the proc chip
     *                      number.
     *
     *  @param[in]  i_topologyMode   The topology mode setting for this system.
     */
    void setTopologyMode(uint8_t i_topologyMode);


struct ipc_data_area_t
{
    uint64_t msg_queue_id;
    msg_t    msg_payload;
    uint64_t hrmor_base;
    uint32_t pir;
    struct ipc_data_area_t *
      remote_ipc_data_addr[internode_info_vals_t::MAX_NODES_PER_SYS];
};

/**
 * This structure maps an IPC data area needed by start_payload that is common
 * to all HB instances.
 * @note  Don't change the order or size of this structure
 * w/o also changing src/kernel/shutdown.S
 */
struct start_payload_data_area_t
{
    /** barriers needed in shutdown.S - see src/kernel/shutdown.S
     *  barrier[0] blocks until all nodes have reported cpu/node_count
     *  barrier[1] blocks until safe to update HRMOR on master
     *  barrier[2] blocks until HRMORs updated
     *  barrier[3] blocks until SLBs, ERATs etc. cleared
     *  barrier[4] blocks until all CPUs have jumpted to payload except the
     *             one with the lowest PIR
     */
    uint64_t barrier[5];
    uint64_t lowest_PIR;    //!< Lowest cpu PIR in entire system (all nodes)
    uint64_t cpu_count;     //!< Total number of cpu threads in entire system
    uint64_t node_count;    //!< Total number of nodes in entire system
};


extern ipc_data_area_t ipc_data_area;
extern start_payload_data_area_t start_payload_data_area;
};

#endif
