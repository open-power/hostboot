/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/sys/msg.h $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2010,2021                        */
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
#ifndef __SYS_MSG_H
#define __SYS_MSG_H

#include <stdint.h>
#include <stdlib.h>
#include <builtins.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef void* msg_q_t;

struct msg_t
{
    uint32_t type;
    struct
    {
        uint32_t __reserved__async:1;
        uint32_t __reserved__pseudosync:1;
        uint32_t __reserved__unused:30;
    };
    uint64_t data[2];  // data[0] start of variable payload calculations
    void* extra_data;
};

// System-defined message types.
/** @enum msg_sys_types_t
 *  @brief Message types potentially sent from the kernel itself.
 */
enum msg_sys_types_t
{
    MSG_FIRST_SYS_TYPE = 0x80000000,

    MSG_MM_RP_READ,
    MSG_MM_RP_WRITE,
    MSG_MM_RP_PERM,

    MSG_INTR_EXTERN,    //!< Msg sent from kernel to user space on ext intr
    MSG_INTR_ADD_CPU,   //!< Add cpu core, data[0] = cpuid (PIR)
    MSG_INTR_CPU_WAKEUP, //!< Msg sent from kernel to user space on cpu wakeup
                         // data[0] = cpuid (PIR)
    MSG_INTR_ISSUE_SBE_MBOX_WA,   //!< Issue EOI to mailbox
    MSG_INTR_IPC,       //!< Msg sent from kernel to user space for multi-node
                        // communication

};

// System-defined root queue types
/** @enum msg_root_queue_types_t
 * @brief Message queue types that the kernel tracks
 */
enum msg_root_queue_types_t
{
    MSGQ_ROOT_VFS,
    MSGQ_ROOT_INTR,
    MSGQ_TYPE_IPC = 0x08,   //!< Value is OR'd with the physical node number
};

/** @var msg_sys_types_t::MSG_MM_RP_READ
 *  @brief Memory Management - Resource Provider Read
 *
 *  Sent from the kernel to a msg_q_t registered with mm_block_create when
 *  a page is requested to be read in from a resource.
 *
 *  <pre>
 *  Format:
 *      type = MSG_MM_RP_READ
 *      data[0] = virtual address requested
 *      data[1] = address to place contents
 *
 *  Expected Response:
 *      type = MSG_MM_RP_READ
 *      data[0] = virtual address requested
 *      data[1] = rc (0 or negative errno value)
 *  </pre>
 */
/** @var msg_sys_types_t::MSG_MM_RP_WRITE
 *  @brief Memory Management - Resource Provider Write
 *
 *  Sent from the kernel to a msg_q_t registered with mm_block_create when
 *  a page is requested to be written back to a resource.
 *
 *  <pre>
 *  Format:
 *      type = MSG_MM_RP_WRITE
 *      data[0] = virtual address requested
 *      data[1] = address to read contents from
 *
 *  Expected Response:
 *      type = MSG_MM_RP_WRITE
 *      data[0] = virtual address requested
 *      data[1] = rc (0 or negative errno value)
 *  </pre>
 */
/** @var msg_sys_types_t::MSG_MM_RP_PERM
 *  @brief Memory Management - Resource Provider Permission Fault
 *
 *  TODO.
 */



// Message queue interfaces.

/** @fn msg_q_create
  * @brief Create a new message queue.
  *
  * @return msg_q_t handle
  */
msg_q_t msg_q_create();


/** @fn msg_q_destroy
  * @brief Deallocate a message queue previously allocated with msg_q_create()
  *
  * @param[in] q - handle to message queue to destroy
  */
void msg_q_destroy( msg_q_t q );


/** @fn msg_q_register
  * @brief Assign a name to a message queue.
  *
  * @param[in] q - handle of message queue to name
  * @param[in] name - name
  *
  * @return  Result of the syscall where zero indicates success
  */
int msg_q_register(msg_q_t q, const char* name);

/** @fn msg_intr_q_register
  * @brief Register the interrupt message queue
  *
  * @param[in] q - handle of message queue to register
  * @param[in] i_ipc_base_addr Is the base MMIO address of the
  *                            IPC register set
  *
  * @return Result of the syscall where zero indicates success
  *         < 0 is the ERRNO
  */
int msg_intr_q_register(msg_q_t q,
                        uint64_t i_ipc_base_addr);

/** @fn msg_q_remove
 * @brief Remove a message queue from the registry
 *
 * @param[in] name - name of the message queue
 *
 * @return 0 on success or -ENXIO if queue not found.
 */
int msg_q_remove(const char * name);


/** @fn msg_q_resolve
  * @brief Given the name of a message queue, return the handle to it.
  *
  * @param[in] name - name of message queue
  *
  * @return message queue handle or null if name not found.
  */
msg_q_t msg_q_resolve(const char* name);





// Message interfaces.
/** @fn msg_allocate
  * @brief Allocate space for message
  * @return Pointer to message
  */
msg_t* msg_allocate();


/** @fn msg_free
  * @brief Free a msg_t
  * @param[in] msg - message to free
  */

ALWAYS_INLINE
    inline void msg_free(msg_t* m) { free(m); }


/** @fn msg_send
  * @brief Send a message asynchronously.
  *
  * This call adds the message queue then returns
  * to the caller. Any process waiting for a message
  * in the queue will awake with this message.
  *
  * @param[in] q - message queue
  * @param[in] msg - message
  *
  * @return Status of message send.
  * @retval 0 - Success
  * @retval -EINVAL - Invalid pointer passed to kernel.
  * @retval -EINVAL - Message type is in kernel range.
  */
int msg_send(msg_q_t q, msg_t* msg);


/** @fn msg_sendrecv
  * @brief Send a message to a server and get a response synchronously.
  *
  * The calling [client] thread blocks until the recipient [server] receives
  * and replies to the message.
  *
  * @param[in] q - message queue
  * @param[in,out] msg - message
  * @return Zero on success, else negative.
  */
int msg_sendrecv(msg_q_t q, msg_t* msg);


/** @fn msg_sendrecv_noblk
 *  @brief Sends a message to a server and get a response without blocking.
 *
 *  From the persepective of the calling [client] task, the message
 *  transaction is asynchronous, but from the perspective of the recipient
 *  [server] it is synchronous.  When the recipient replies to the message
 *  the message is relayed onto a secondary message queue that the caller
 *  provided.
 *
 *  @param[in] q - The message queue to send on.
 *  @param[in] msg - The message.
 *  @param[in] q2 - The secondary queue for the response.
 *
 *  @return Zero on success, else negative.
 */
int msg_sendrecv_noblk(msg_q_t q, msg_t* msg, msg_q_t q2);

/** @fn msg_respond
  * @brief Respond to a synchronous message.
  *
  * This is how server-side code responds to synchronous
  * messaging when clients call msg_sendrecv().
  *
  * @param[in] q - message queue
  * @param[in] msg - response message
  *
  * @return Zero on success, else negative.
  * @retval -EBADF - Message was not sent synchronously.
  *
  */
int msg_respond(msg_q_t q, msg_t* msg);


/** @fn msg_wait
  * @brief  Read a message from the message queue.
  *
  * If a message is already on the queue, this call will return immediately
  * with the message. Otherwise the calling thread will block and wait for
  * a message.
  *
  * @param[in] q - message queue to read
  * @return the message posted to the queue
  */
msg_t* msg_wait(msg_q_t q);


/** @fn updateRemoteIpcAddr
  * @brief Update a Remote Node's IPC buffer address
  *
  * @param[in] i_node - node
  * @param[in] i_remoteAddr - Remote Node's IPC buffer address
  *
  * @return Result of update.
  * @retval 0 - Success
  * @retval EINVAL - Invalid Node.
  */
           // low nibble is remote node number
#define IPC_INVALID_REMOTE_ADDR_MASK     0xFFFFFFFFFFFFFFF0ull
#define IPC_INVALID_REMOTE_ADDR          0x00000000deadadd0ull

int updateRemoteIpcAddr(uint64_t i_node, uint64_t i_remoteAddr);


/** @fn qryLocalIpcInfo
  * @brief Query the local Node's node number and IPC bfr address
  *
  * @param[out] o_node - returned Node
  * @param[out] o_addr - returned Local Node's IPC bfr address
  *
  * @return Result of query.
  * @retval 0 - Success
   */
int qryLocalIpcInfo( uint64_t & o_node, uint64_t & o_addr);


/** @fn msg_is_async
  * @brief  Indicates if message is asynchronous.
  *
  * Tests the reserved message fields to determine if the message is
  * asynchronous or synchronous.  These fields are only manipulated by
  * system-call or kernel code to maintain the proper state of the fields
  * based on the msg interfaces used.
  *
  * @return true if asynchronous message
  */
    ALWAYS_INLINE
inline uint32_t msg_is_async(msg_t* msg)
{
    return (0 == msg->__reserved__async);
}

/** @fn msg_is_sync_noblk
 *  @brief  Indicates if the message is a non-blocking synchronous message.
 *
 *  Tests the reserved message fields to determine if the message is
 *  a blocking synchronous message.  These fields are only manipulated by
 *  system-call or kernel code to maintain the proper state of the fields
 *  based on the msg interfaces used.
 *
 *  @return true if non-blocking synchronous message.
 */
    ALWAYS_INLINE
inline uint32_t msg_is_sync_noblk(msg_t* msg)
{
    return (1 == msg->__reserved__pseudosync);
}

#ifdef __cplusplus
}
#endif

#endif
