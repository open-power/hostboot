/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mailboxsp.H $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
#if !defined(__MBOXSP__)
#define __MBOXSP__
/**
 * @file mailboxrp.C
 * @brief Mailbox service provider declariation
 */
#include "mbox_dma_buffer.H"
#include <stdint.h>
#include <builtins.h>
#include <mbox/mboxif.H>
#include <errl/errlentry.H>
#include <sys/msg.h>
#include <sys/sync.h>
#include <list>
#include <map>
#include <util/locked/list.H>
#include <intr/interrupt.H>
#include <limits.h>

extern const char* VFS_ROOT_MSG_MBOX;

namespace TARGETING
{
    class Target;
};

namespace MBOX
{
    /**
     * Messages to the mailbox queue
     */
    enum msgq_msg_t
    {
        MSG_SEND,
        MSG_REGISTER_MSGQ,
        MSG_UNREGISTER_MSGQ,
        MSG_INTR,
        MSG_MBOX_SHUTDOWN,
        MSG_MBOX_SUSPEND,
        MSG_MBOX_RESUME,
        MSG_IPC,
        MSG_LOCAL_IPC,
        MSG_MBOX_ALLOCATE,
        MSG_MBOX_DEALLOCATE,
    };


    class MailboxSp
    {
        public:

            /**
             * Initialize the mailbox service
             * @param[in] i_taskArgs
             */
            static void init(errlHndl_t& o_errl);

            /**
             * Send a message to the mailbox service
             * @param[in] i_q_id, the queue id
             * @param[in/out] io_msg the message to send and if async, the
             * @param[in] i_mbox_msg_type - mailbox message type
             * message returned
             * @return errlHndl_t on error
             */
            static errlHndl_t send(queue_id_t i_q_id,
                                   msg_t * io_msg,
                                   msgq_msg_t i_mbox_msg_type);

        protected:

            /**
             * Default constructor
             */
            MailboxSp();

            /**
             * Destructor
             */
            ~MailboxSp();

            /**
             * Start message handler
             */
            static void* msg_handler(void * unused);

        private:

            /**
             * mailbox message header
             * @note We decided to send this
             */
            struct mbox_msg_t
            {
                /**
                 * @brief Identifier assigned by originating endpoint for correlating
                 * sync message responses.
                 */
                uint32_t msg_id;

                /**
                 * Message queue id.
                 * @see src/include/usr/mbox/mbox_queues.H
                 */
                uint32_t msg_queue_id;

                /**
                 * Message
                 */
                msg_t msg_payload;

                /**
                 * Default constructor
                 */
                mbox_msg_t() : msg_id(0), msg_queue_id(0), msg_payload()
                {
                    memset(&msg_payload,'\0',sizeof(msg_t));
                }
            };

            // Private functions

            /* See init() above */
            errlHndl_t _init();

            /**
             * The mailbox service provider task
             */
            void msgHandler();

            /**
             * Send or queue up the next message to the device driver
             * @param[in] i_mbox_msg, ptr to the mailbox message | NULL
             * @NOTE if the mailbox message ptr is NULL then no new message is
             * added to the queue, but the next message on the queue is sent
             * provided there is one available.
             */
            void send_msg(mbox_msg_t * i_msg = NULL);

            /**
             * Handle a mailbox message received from the device driver
             * @param[in] i_mbox_msg, the mailbox message
             * @return nothing
             * @NOTE will commit an error log on errors.
             */
            void recv_msg(mbox_msg_t & i_mbox_msg);

            /**
             * Register a message queue to receive mailbox messages
             * @param[in] i_queueu_id, The queue identifier
             * @param[in] i_msgQ, The message queue created with msg_q_create()
             *                    @see sys/msg.h
             * @return errlHndl_t on error
             */
            errlHndl_t msgq_register(queue_id_t i_queue_id, msg_q_t i_msgQ);


            /**
             * Un register a message queue from the mailbox service
             * @param[in] i_queue_id, The queue identifier
             * @return The message queue
             */
            msg_q_t msgq_unregister(queue_id_t i_queue_id);

            /**
             * Handle interrupt from Intr presenter
             * @param[in] i_msg, The message 
             */
            errlHndl_t handleInterrupt();

            /**
             * Handle potential IPC message
             */
            void handleIPC(queue_id_t i_queue_id, msg_t * i_msg);

            /**
             * Trace the message to the "fast" trace buffer
             * @param[in] i_text, a Description
             * @param[in] i_mbox_msg, the message to trace
             */
            void trace_msg(const char * i_text,
                           const mbox_msg_t & i_mbox_msg) const;

            /**
             * Handle a message to hbmbox from fspmbox
             * @param[in] i_mbox_msg, the mbox message
             */
            void handle_hbmbox_msg(mbox_msg_t & i_mbox_msg);

            /**
             * Handle a response from FSP
             * @param[in] i_mbox_msg, the mbox message
             */
            void handle_hbmbox_resp(mbox_msg_t & i_mbox_msg);

            /**
             * Handle a new message from HB to FSP
             * @param[in] i_msg, The carrier message
             */
            void handleNewMessage(msg_t* i_msg);

            /**
             * Handle any unclaimed messages from FSP to HB
             * @post iv_pending.size() == 0;
             */
            void handleUnclaimed();

            /**
             * Handle shutdown
             * @pre quiesced() == true
             */
            void handleShutdown();

            /**
             * Perform the final actions needed to suspend the mailbox sp
             * @pre quiesced() == true
             */
            void suspend();

            /**
             * Resume the mailbox from the suspend state
             */
            void resume();

            /**
             * Send message to FSP indicating an invalid or undeliverable
             * message queue.
             * @param[in] i_mbox_msg.  The invalid message
             */
            void invalidMsgResponder(mbox_msg_t & i_mbox_msg);

            /**
             * Handle an allocate message
             * @param[in] The allocate message
             */
            void handleAllocate(msg_t* i_msg);

            /**
             * Unallocate storage
             * @param[in] Pointer to allocated storage
             * @note If i_ptr is not owned by mbox then
             * storage is just freed
             */
            void deallocate(void * i_ptr);

            /**
             * Query Quiesced
             * @returns [true|false]
             */
            bool quiesced();


            enum
            {
                MAX_RETRY_COUNT = 3,
                MAX_ALLOCATION = 64 * KILOBYTE,
            };

            /**
             * Information needed for a resonse to a sync message
             */
            struct msg_respond_t
            {
                public:
                    msg_respond_t *     next;
                    msg_respond_t *     prev;
                    msg_t *             key;    //!< ptr to original msg

                    //These fields are only used in sync message from FSP to HB
                    uint32_t            msg_id;         //!< The message_id
                    uint32_t            msg_queue_id;   //!< The msg queue id

                    /**
                     * Ctor
                     */
                    msg_respond_t(msg_t * i_msg) :
                        next(NULL),
                        prev(NULL),
                        key(i_msg),
                        msg_id(0),
                        msg_queue_id(0) {}
            };

            typedef std::list<mbox_msg_t> send_q_t;
            typedef Util::Locked::List<msg_respond_t, msg_t *> respond_q_t;
            typedef std::map<queue_id_t,msg_q_t> registry_t;
            typedef std::list<msg_t *> msg_list_t;

            typedef std::pair<uint64_t, uint64_t> addr_size_t;
            typedef std::list<addr_size_t> addr_list_t;

            msg_q_t     iv_msgQ;        //!< mailbox mesage queue
            send_q_t    iv_sendq;       //!< msg to send queue
            mbox_msg_t  iv_msg_to_send; //!< message being sent
            respond_q_t iv_respondq;    //!< msg respond pending list
            registry_t  iv_registry;    //!< Registered queue
            DmaBuffer   iv_dmaBuffer;   //!< DMA buffer manager
            send_q_t    iv_pendingq;    //!< Pending for queue registration

            TARGETING::Target * iv_trgt;//!< mailbox device driver target
            msg_t *     iv_shutdown_msg;//!< Message to shutdown mbox
            msg_t *     iv_suspend_msg; //!< Message to suspend mbox
            bool        iv_rts;         //!< ready to send flag
            bool        iv_dma_pend;    //!< Request pending for more DMA bufs
            bool        iv_disabled;    //!< Mailboxsp shut off (rejects new)
            bool        iv_suspended;   //!< Mailbox is suspended (queues new)
            bool        iv_suspend_intr;//!< Disable HW interrupts on suspend
            bool        iv_allow_blk_resp;//!< Disable HW interrupts on suspend
            uint64_t    iv_sum_alloc;   //!< Total extra_data storage allocated
            msg_list_t  iv_pend_alloc;  //!< Pending memory allocations
            addr_list_t iv_allocAddrs;  //!< memory addresses allocated by mbox

    };
};

#endif
