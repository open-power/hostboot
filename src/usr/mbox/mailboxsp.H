/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/usr/mbox/mailboxsp.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
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
             * message returned
             * @return errlHndl_t on error
             */
            static errlHndl_t send(queue_id_t i_q_id, msg_t * io_msg);

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
                mbox_msg_t() : msg_id(0), msg_queue_id(0), msg_payload() {}
            };

            // Private functions

            /* See init() above */
            errlHndl_t _init();

            /**
             * The mailbox service provider task
             */
            void msgHandler();

            /**
             * Send or queue up a message to the device driver
             * @param[in] i_mbox_msg, the mailbox message
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
             */
            void handleShutdown();

            /**
             * Query Quiesced
             * @returns [true|false]
             */
            ALWAYS_INLINE
            bool quiesced()
            {
                return (iv_rts &&
                        !iv_dma_pend &&
                        iv_sendq.empty() &&
                        iv_respondq.empty());
            }


            enum
            {
                MAX_RETRY_COUNT = 3,
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

            msg_q_t     iv_msgQ;        //!< mailbox mesage queue
            send_q_t    iv_sendq;       //!< msg to send queue
            mbox_msg_t  iv_msg_to_send; //!< message being sent
            respond_q_t iv_respondq;    //!< msg respond pending list
            registry_t  iv_registry;    //!< Registered queue
            DmaBuffer   iv_dmaBuffer;   //!< DMA buffer manager
            send_q_t    iv_pendingq;    //!< Pending for queue registration

            TARGETING::Target * iv_trgt;//!< mailbox device driver target
            msg_t *     iv_shutdown_msg;//!< Message to shutdown mbox
            bool        iv_rts;         //!< ready to send flag
            bool        iv_dma_pend;    //!< Request pending for more DMA buffers
            bool        iv_disabled;    //!< Mailboxsp is shut off
    };
};

#endif
