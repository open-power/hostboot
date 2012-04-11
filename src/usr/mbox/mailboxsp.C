//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/mailbox/mailboxsp.C $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file mailboxsp.C
 * @brief mailbox service provider definition
 */

#include "mailboxsp.H"
#include "mboxdd.H"
#include <sys/task.h>
#include <initservice/taskargs.H>
#include <sys/vfs.h>
#include <devicefw/userif.H>
#include <mbox/mbox_reasoncodes.H>

#define HBMBOX_TRACE_NAME HBMBOX_COMP_NAME

using namespace MBOX;

// Defined in mboxdd.C
extern trace_desc_t * g_trac_mbox;
extern trace_desc_t * g_trac_mboxmsg;

const char HBMBOXMSG_TRACE_NAME[] = "MBOXMSG";
trace_desc_t* g_trac_mboxmsg = NULL; // g_trac_mbox;
TRAC_INIT(&g_trac_mboxmsg, HBMBOXMSG_TRACE_NAME, 2048);



/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( MailboxSp::init );


MailboxSp::MailboxSp()
    :
        iv_msgQ(),
        iv_sendq(),
        iv_respondq(),
        iv_trgt(NULL),
        iv_rts(true),
        iv_dma_pend(false)
{
    // mailbox target
    TARGETING::targetService().masterProcChipTargetHandle(iv_trgt);
}

MailboxSp::~MailboxSp()
{
    msg_q_destroy(iv_msgQ);
}

void MailboxSp::init(errlHndl_t& o_errl)
{
    o_errl = Singleton<MailboxSp>::instance()._init();
}

// helper function to start mailbox message handler
void MailboxSp::msg_handler(void * unused)
{
    Singleton<MailboxSp>::instance().msgHandler();
}


errlHndl_t MailboxSp::_init()
{
    errlHndl_t err = NULL;
    size_t rc = 0;
    iv_msgQ = msg_q_create();
    rc = msg_q_register(iv_msgQ, VFS_ROOT_MSG_MBOX);

    // Register to get interrupts for mailbox
    err = INTR::registerMsgQ(iv_msgQ, INTR::FSP_MAILBOX);

    if(!err)
    {
        err = MboxDD::init(iv_trgt);

        task_create(MailboxSp::msg_handler, NULL);
    }

    return err;
}


void MailboxSp::msgHandler()
{
    errlHndl_t err = NULL;

    while(1)
    {
        msg_t* msg = msg_wait(iv_msgQ);

        // First look for responses to messages sent to HB msg queues
        // Theses are responses to sync messages from FSP to HB.
        msg_respond_t * response = iv_respondq.find(msg);
        if(response)
        {
            iv_respondq.erase(response);

            mbox_msg_t mbox_msg;
            mbox_msg.msg_id = response->msg_id;
            mbox_msg.msg_queue_id = response->msg_queue_id;
            mbox_msg.msg_payload = *msg;

            msg_free(msg);
            delete response;

            send_msg(&mbox_msg);

            continue;
        }

        // Now look for other messages
        switch(msg->type)
        {
            // Interrupt from the mailbox hardware
            case MSG_INTR:
                {
                    mbox_msg_t mbox_msg;
                    size_t mbox_msg_size = sizeof(mbox_msg_t);
                    uint64_t mbox_status = 0;

                    // Read message from DD
                    err = DeviceFW::deviceRead(iv_trgt,
                                               static_cast<void*>(&mbox_msg),
                                               mbox_msg_size,
                                               DEVICE_MBOX_ADDRESS(&mbox_status)
                                              );
                    if(err)
                    {
                        err->collectTrace(HBMBOX_TRACE_NAME);
                        err->collectTrace(HBMBOXMSG_TRACE_NAME);
                        // still need to repond to interrupt handler
                        // will cause assert() below.
                    }
                    else
                    {

                        TRACDCOMP(g_trac_mbox,"MBOXSP status=%lx",mbox_status);

                        if(mbox_status & MboxDD::MBOX_HW_ACK)
                        {
                            // send next message if there is one.
                            iv_rts = true;
                            send_msg();
                        }

                        if(mbox_status & MboxDD::MBOX_DATA_PENDING)
                        {
                            recv_msg(mbox_msg);
                        }

                        // Look for error status from MB hardware
                        if(mbox_status & MboxDD::MBOX_DOORBELL_ERROR)
                        {
                            TRACFCOMP(g_trac_mbox,
                                      ERR_MRK"MBOX status 0x%lx",
                                      mbox_status);

                            if(mbox_status & MboxDD::MBOX_DATA_WRITE_ERR)
                            {
                                // Write attempted before ACK - HB code error
                                /*@ errorlog tag
                                 * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                                 * @moduleid        MOD_MBOXSRV_HNDLR
                                 * @reasoncode      RC_DATA_WRITE_ERR
                                 * @userdata1       Status from MB device driver
                                 * @defdesc         Mailbox Data Write attempted
                                 *                  before ACK.
                                 *
                                 */
                                err = new ERRORLOG::ErrlEntry
                                    (
                                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                                     MBOX::MOD_MBOXSRV_HNDLR,
                                     MBOX::RC_DATA_WRITE_ERR,  //  reason Code
                                     mbox_status,              //  Status from DD
                                     0
                                    );

                                err->collectTrace(HBMBOX_TRACE_NAME);
                                err->collectTrace(HBMBOXMSG_TRACE_NAME);
                                // will assert later below
                            }

                            else if(mbox_status & MboxDD::MBOX_PARITY_ERR)
                            {
                                // Hardware detected parity error
                                // - TODO How does BB handle this error ???
                                // Log it and continue

                                /*@ errorlog tag
                                 * @errortype       ERRL_SEV_INFORMATIONAL
                                 * @moduleid        MOD_MBOXSRV_HNDLR
                                 * @reasoncode      RC_PARITY_ERR
                                 * @userdata1       Status from MB device driver
                                 * @defdesc         Mailbox Hardware detected
                                 *                  parity error.
                                 */
                                err = new ERRORLOG::ErrlEntry
                                    (
                                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                     MBOX::MOD_MBOXSRV_HNDLR,
                                     MBOX::RC_PARITY_ERR,    //  reason Code
                                     mbox_status,            //  Status from DD
                                     0
                                    );

                                err->collectTrace(HBMBOX_TRACE_NAME);
                                errlCommit(err,HBMBOX_COMP_ID);
                                // err = NULL
                            }
                            else if(mbox_status & MboxDD::MBOX_ILLEGAL_OP)
                            {
                                // Code problem could be FSP or HB 
                                // - log error and continue.

                                /*@ errorlog tag
                                 * @errortype       ERRL_SEV_INFORMATIONAL
                                 * @moduleid        MOD_MBOXSRV_HNDLR
                                 * @reasoncode      RC_ILLEGAL_OP
                                 * @userdata1       Status from MB device driver
                                 * @defdesc         Retry failed. Bad status
                                 *                  indicated in PIB status reg.
                                 *
                                 */
                                err = new ERRORLOG::ErrlEntry
                                    (
                                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                                     MBOX::MOD_MBOXSRV_HNDLR,
                                     MBOX::RC_ILLEGAL_OP,    //  reason Code
                                     mbox_status,            //  Status from DD
                                     0
                                    );
                                err->collectTrace(HBMBOX_TRACE_NAME);
                                errlCommit(err,HBMBOX_COMP_ID);
                                // err = NULL
                            }

                            //else if(mbox_status & MboxDD::MBOX_DATA_READ_ERR)
                            //{
                            //    // Read when no message available 
                            //    - Just ignore this one per Dean.
                            //}


                            // The code has the ability to retry sending a
                            // message, but currently there is no error state
                            // that requires it.
                        }
                    }


                    // Respond to the interrupt handler
                    msg->data[0] = 0;
                    msg->data[1] = 0;
                    msg_respond(iv_msgQ,msg);

                    // err will be set if scom failed in mbox DD
                    // or MBOX_DATA_WRITE_ERR  - serious - assert
                    if(err)
                    {
                        // TODO Mask off MB interrupts??
                        errlCommit(err,HBMBOX_COMP_ID);

                        assert(0);
                    }
                }

                break;


            case MSG_SEND:
                {
                    // Build mailbox message
                    mbox_msg_t mbox_msg;
                    mbox_msg.msg_queue_id = static_cast<uint32_t>(msg->data[0]);
                    msg_t * payload = reinterpret_cast<msg_t*>(msg->extra_data);
                    mbox_msg.msg_payload = *payload;  //copy in payload

                    if(msg_is_async(msg))
                    {
                        msg_free(payload);
                        msg_free(msg);
                    }
                    else  //synchronous
                    {
                        msg->data[1] = 0;  // used later for return value

                        // need to watch for a response
                        response = new msg_respond_t(msg);

                        // Convert a 64 bit pointer to a 32 bit unsigned int.
                        mbox_msg.msg_id =
                            static_cast<uint32_t>
                            (reinterpret_cast<uint64_t>(response->key));

                        iv_respondq.insert(response);
                    }

                    send_msg(&mbox_msg);

                }
                break;

            case MSG_REGISTER_MSGQ:
                {
                    errlHndl_t err = NULL;
                    queue_id_t queue_id = static_cast<queue_id_t>(msg->data[0]);
                    msg_q_t msgQ = reinterpret_cast<msg_q_t>(msg->data[1]);
                    err = msgq_register(queue_id,msgQ);
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_UNREGISTER_MSGQ:
                {
                    queue_id_t queue_id = static_cast<queue_id_t>(msg->data[0]);
                    msg_q_t msgQ = msgq_unregister(queue_id);
                    msg->data[1] = reinterpret_cast<uint64_t>(msgQ);
                    msg_respond(iv_msgQ,msg);
                }
                break;

            default: //Huh? Ignore it.

                TRACFCOMP(g_trac_mbox, ERR_MRK "MailboxSp::msgHandler() "
                          "invalid message received 0x%08x",msg->type);

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MOD_MBOXSRV_HNDLR
                 * @reasoncode      RC_INVALID_MBOX_MSG_TYPE
                 * @userdata1       Message type
                 * @defdesc         Invalid message type sent to mailbox msgQ
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_HNDLR,
                     MBOX::RC_INVALID_MBOX_MSG_TYPE,    //  reason Code
                     msg->type,                         // msg type
                     0
                    );

                errlCommit(err,HBMBOX_COMP_ID);
                err = NULL;

                msg_free(msg);

                break;
        }

    } // while(1)
}



// Note: When called due to an ACK or retry, iv_rts should be true.
void MailboxSp::send_msg(mbox_msg_t * i_msg)
{
    if(i_msg)
    {
        iv_sendq.push_back(*i_msg);
    }

    // Can't send now if:
    //  - busy (waiting for ACK)
    //  - a DMA buffer request is pending
    //  - there is nothing to send
    //
    //  TODO future optimization: If both iv_rts and iv_dma_pend are true then
    //  could look for a mesaage in the sendq that does not require a DMA
    //  buffer and send it.
    if(!iv_rts || iv_dma_pend || iv_sendq.size() == 0)
    {
        return;
    }

    errlHndl_t err = NULL;

    mbox_msg_t * mbox_msg = &(iv_sendq.front());;
    msg_t * payload = &(mbox_msg->msg_payload);

    iv_msg_to_send = *mbox_msg; //copy

    // TODO remove the following line when DMA buffer support is available
    payload->extra_data = NULL;

    // Is a DMA buffer needed?
    if(payload->extra_data != NULL)

    {
        size_t size = payload->data[1];
        void * dma_buffer = NULL;
        // TODO getDMA buffer

        if(dma_buffer)
        {
            memcpy(dma_buffer,payload->extra_data,size);
            iv_msg_to_send.msg_payload.extra_data = dma_buffer;

            free(payload->extra_data);
            iv_sendq.pop_front();
        }
        else // can't get buffer
        {
            //   -- can't send the current message - leave it on the queue
            //   -- Instead send a message to FSP for more buffers
            //   TODO set sync flag when  implementing DMA buffer
            iv_msg_to_send.msg_id = 0;
            iv_msg_to_send.msg_queue_id = FSP_MAILBOX_MSGQ;
            iv_msg_to_send.msg_payload.type = MSG_REQUEST_DMA_BUFFERS;
            iv_msg_to_send.msg_payload.data[0] = 0;
            iv_msg_to_send.msg_payload.data[1] = 0;
            iv_msg_to_send.msg_payload.extra_data = NULL;
            iv_dma_pend = true;
        }
    }
    else // simple message
    {
        iv_sendq.pop_front();
    }

    size_t mbox_msg_len = sizeof(mbox_msg_t);
    iv_rts = false;

    trace_msg("SEND",iv_msg_to_send);

    err = DeviceFW::deviceWrite(iv_trgt,
                                &iv_msg_to_send,
                                mbox_msg_len,
                                DeviceFW::MAILBOX);

    if(err)
    {
        // If the message that could not be sent was a sync msg
        // originating from HB then there is a task waiting for a response.
        if(!msg_is_async(&(iv_msg_to_send.msg_payload)))
        {
            if(iv_msg_to_send.msg_queue_id >= FSP_FIRST_MSGQ)
            {
                msg_t * key = reinterpret_cast<msg_t *>(iv_msg_to_send.msg_id);
                msg_respond_t * response = iv_respondq.find(key);
                if(response)
                {
                    iv_respondq.erase(response);
                    msg_t * msg = response->key;
                    msg->data[1] = reinterpret_cast<uint64_t>(err);
                    err = NULL;
                    msg_respond(iv_msgQ,msg);
                    delete response;
                }
                // else could be request for more DMA buffers
                // - for now just commit the error. TODO recovery options?
            }
            // else msg is a HB response to a FSP originating sync msg
            // What do we do here? Can't respond to the FSP.
            // For now just commit the error. TODO recovery options?
        }
        // else msg was HB originating async - Just commit it.

        if(err) // have error log and no where to respond to, so commit it.
        {
            errlCommit(err,HBMBOX_COMP_ID);
            err = NULL;
        }
    }
}


void MailboxSp::recv_msg(mbox_msg_t & i_mbox_msg)
{
    errlHndl_t err = NULL;
    int rc = 0;

    // TODO look for response to requests for more DMA buffers
    // and handle now
    // add dma buffers
    // iv_dma_pend = false;
    // call send_msg to send next message if available and rts
    //

    msg_t * msg = msg_allocate();
    *msg = i_mbox_msg.msg_payload;  // copy

    trace_msg("RECV",i_mbox_msg);

    // Handle moving data from DMA buffer
    if(msg->extra_data != NULL)
    {
        uint64_t msg_sz = msg->data[1];
        void * buf = malloc(msg_sz);
        memcpy(buf,msg->extra_data,msg_sz);

        // DMArelease(msg->extra_data,msg_sz); TODO
        msg->extra_data = buf;
        // receiver of the message frees buffer.
    }


    // Is sync response message from FSP

    msg_t * key = reinterpret_cast<msg_t *>(i_mbox_msg.msg_id);

    msg_respond_t * response = iv_respondq.find(key);

    // msg_id matches and the msg_queue_id is an FSP queue id
    // If it's a hostboot target then it's not a response.
    if(response && i_mbox_msg.msg_queue_id >= FSP_FIRST_MSGQ)
    {
        // remove from the list
        iv_respondq.erase(response);

        *(response->key) = *msg; // copy

        msg_free(msg);

        msg_respond(iv_msgQ,response->key);

        delete response;
    }
    else
    {
        // New incomming message
        msg_q_t msgq = NULL;

        registry_t::iterator r = iv_registry.find
            (static_cast<queue_id_t>(i_mbox_msg.msg_queue_id));

        if(r != iv_registry.end())
        {
            msgq = r->second;

            // Check that the type is within range
            // TODO also check if in secure mode msg->type > LAST_SECURE_MSG 
            if(msg->type < MSG_FIRST_SYS_TYPE) // &&
                // (!is_secure() || (is_secure() && msg->type > LAST_SECURE_MSG))
            {
                if(msg_is_async(msg))
                {
                    // send msg to queue
                    rc = msg_send(msgq,msg);
                }
                else //sync message from FSP
                {
                    // Need to save queue_id and msg_id and msg ptr
                    // for reponse
                    msg_respond_t * response = new msg_respond_t(msg);
                    response->msg_id = i_mbox_msg.msg_id;
                    response->msg_queue_id = i_mbox_msg.msg_queue_id;

                    iv_respondq.insert(response);

                    rc = msg_sendrecv_noblk(msgq,msg,iv_msgQ);
                }

                // Since we've filtered out illegal types this can only mean
                // msgq or msg has a bad memory reference - code problem
                if(rc)
                {
                    /*@ errorlog tag
                     * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                     * @moduleid        MOD_MBOXSRV_RCV
                     * @reasoncode      RC_INVALID_QUEUE
                     * @userdata1       rc from msg_send()
                     * @userdata2       msg queue id
                     * @defdesc         Ivalid msg or msg queue
                     *
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         MBOX::MOD_MBOXSRV_RCV,
                         MBOX::RC_INVALID_QUEUE,    //  reason Code
                         rc,                        // rc from msg_send
                         i_mbox_msg.msg_queue_id
                        );

                    err->collectTrace(HBMBOXMSG_TRACE_NAME);
                    errlCommit(err,HBMBOX_COMP_ID);

                    free(msg->extra_data);
                    msg_free(msg);

                    assert(0);

                }
            }
            else // Bad type range
            {
                //  Send a message to the FSP
                mbox_msg_t mbox_msg;
                mbox_msg.msg_queue_id = FSP_MAILBOX_MSGQ;
                mbox_msg.msg_payload.type = MSG_INVALID_MSG_TYPE;
                mbox_msg.msg_payload.data[0] = msg->type;
                mbox_msg.msg_payload.data[1] = i_mbox_msg.msg_queue_id;
                mbox_msg.msg_payload.extra_data = NULL;
                mbox_msg.msg_payload.__reserved__async = 1;


                send_msg(&mbox_msg);

                TRACFCOMP(g_trac_mbox,
                          ERR_MRK
                          "MailboxSp::recv_msg-Message type 0x%x range error."
                          " Message dropped.",
                          msg->type);

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MOD_MBOXSRV_RCV
                 * @reasoncode      RC_INVALID_MESSAGE_TYPE
                 * @userdata1       msg queue
                 * @userdata2       msg type
                 * @defdesc         Message from FSP. Message type is not
                 *                  within a valid range. Message dropped.
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_RCV,
                     MBOX::RC_INVALID_MESSAGE_TYPE  ,    //  reason Code
                     i_mbox_msg.msg_queue_id,            // rc from msg_send
                     0
                    );

                err->collectTrace(HBMBOXMSG_TRACE_NAME);
                errlCommit(err,HBMBOX_COMP_ID);

                free(msg->extra_data);
                msg_free(msg);
            }
        }
        else  // unregistered msg_queue_id
        {

            TRACFCOMP(g_trac_mbox,
                      ERR_MRK
                      "MailboxSp::recv_msg - Message dropped. "
                      "Unregistered msg queue id 0x%x",
                      i_mbox_msg.msg_queue_id);

            //  Send a message to the FSP
            mbox_msg_t mbox_msg;
            mbox_msg.msg_queue_id = FSP_MAILBOX_MSGQ;
            mbox_msg.msg_payload.type = MSG_INVALID_MSG_QUEUE_ID;
            mbox_msg.msg_payload.data[0] = i_mbox_msg.msg_queue_id;
            mbox_msg.msg_payload.extra_data = NULL;
            mbox_msg.msg_payload.__reserved__async = 1;


            send_msg(&mbox_msg);


            /*@ errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        MOD_MBOXSRV_RCV
             * @reasoncode      RC_UNREGISTERED_MSG_QUEUE
             * @userdata1       msg queueid
             * @defdesc         msg queue type is not registered with the
             *                  mailbox. Message dropped.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                 MBOX::MOD_MBOXSRV_RCV,
                 MBOX::RC_UNREGISTERED_MSG_QUEUE,    //  reason Code
                 i_mbox_msg.msg_queue_id,            // rc from msg_send
                 0
                );

            // This trace will have the message content.
            err->collectTrace(HBMBOXMSG_TRACE_NAME);

            errlCommit(err,HBMBOX_COMP_ID);

            free(msg->extra_data);
            msg_free(msg);
       }
    }
}

/**
 * Send message to mailbox service to send a remote message
 */
errlHndl_t MailboxSp::send(queue_id_t i_q_id, msg_t * io_msg)
{
    errlHndl_t err = NULL;
    int rc = 0;

    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);

    msg_t* msg = msg_allocate();
    msg->type = MBOX::MSG_SEND;
    msg->data[0] = static_cast<uint64_t>(i_q_id);
    msg->extra_data = reinterpret_cast<void*>(io_msg); // Payload message

    if(msg_is_async(io_msg))
    {
        rc = msg_send(mboxQ, msg);
    }
    else
    {
        rc = msg_sendrecv(mboxQ, msg);

        if(0 == rc)
        {
            err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        }

        msg_free(msg);

        // io_msg now contains response message
    }

    if(rc != 0)
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        MOD_MBOXSRV_SEND
         * @reasoncode      RC_INVALID_QUEUE
         * @userdata1       returncode from msg_sendrecv()
         *
         * @defdesc         Invalid message or message queue
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
             MBOX::MOD_MBOXSRV_SEND,                 //  moduleid
             MBOX::RC_INVALID_QUEUE,                 //  reason Code
             rc,                                     //  msg_sendrecv errno
             i_q_id                                  //  msg queue id
            );

        // This Trace has the msg
        err->collectTrace(HBMBOXMSG_TRACE_NAME);
    }

    return err;
}


errlHndl_t MailboxSp::msgq_register(queue_id_t i_queue_id, msg_q_t i_msgQ)
{
    errlHndl_t err = NULL;

    registry_t::iterator r = iv_registry.find(i_queue_id);
    if(r == iv_registry.end())
    {
        iv_registry[i_queue_id] = i_msgQ;

        TRACFCOMP(g_trac_mbox,INFO_MRK"MailboxSp::msgq_register queue id %d",
                  i_queue_id);
    }
    else
    {
        // If its the same queue being registered again, just ignore it.
        // If its a different queue then error.
        if(r->second != i_msgQ)
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        MBOX::MOD_MBOXREGISTER
             * @reasoncode      MBOX::RC_ALREADY_REGISTERED
             * @userdata1       queue_id_t queueId
             * @userdata2       0
             *
             * @defdesc         Message queue already registered with mailbox
             *                  using a different queue.
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
                 MBOX::MOD_MBOXREGISTER,              // moduleid
                 MBOX::RC_ALREADY_REGISTERED,         // reason code
                 i_queue_id,
                 0
                );
        }
    }
    return err;
}

msg_q_t MailboxSp::msgq_unregister(queue_id_t i_queue_id)
{
    msg_q_t msgQ = NULL;
    registry_t::iterator r = iv_registry.find(i_queue_id);
    if(r != iv_registry.end())
    {
        msgQ = r->second;
        iv_registry.erase(r);
        TRACFCOMP(g_trac_mbox,INFO_MRK"MailboxSp::msgq_unregister queue id %d",
                  i_queue_id);
    }
    return msgQ;
}

void MailboxSp::trace_msg(const char * i_text,
                          const mbox_msg_t & i_mbox_msg) const
{
    TRACFCOMP(g_trac_mboxmsg,
              "MBOXSP %s MSG HEAD: msg_id:0x%x msg_queue_id:0x%x",
              i_text,
              i_mbox_msg.msg_id,
              i_mbox_msg.msg_queue_id);

    TRACFCOMP(g_trac_mboxmsg,
              "MBOXSP %s MSG: 0x%08x 0x%016lx 0x%016lx %p",
              i_text,
              i_mbox_msg.msg_payload.type,
              i_mbox_msg.msg_payload.data[0],
              i_mbox_msg.msg_payload.data[1],
              i_mbox_msg.msg_payload.extra_data);
}

// ----------------------------------------------------------------------------
// External Interfaces @see mboxif.H
// ----------------------------------------------------------------------------

errlHndl_t MBOX::send(queue_id_t i_q_id, msg_t * i_msg)
{
    i_msg->__reserved__async = 0;
    return MailboxSp::send(i_q_id, i_msg);
}

errlHndl_t MBOX::sendrecv(queue_id_t i_q_id, msg_t * io_msg)
{
    io_msg->__reserved__async = 1;
    return MailboxSp::send(i_q_id, io_msg);
}

errlHndl_t MBOX::msgq_register(queue_id_t i_queue_id, msg_q_t i_msgQ)
{
    // Could use a mutex to protect the queueid to msgQ map, but since
    // registering is a rare thing, just send a message to the mailbox service.
    errlHndl_t err = NULL;
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);

    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_REGISTER_MSGQ;
        msg->data[0] = static_cast<uint64_t>(i_queue_id);
        msg->data[1] = reinterpret_cast<uint64_t>(i_msgQ);

        int rc = msg_sendrecv(mboxQ, msg);

        if(!rc)
        {
            err = reinterpret_cast<errlHndl_t>(msg->data[1]);
        }
        else
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::msgq_register - msg_sendrecv failed. errno = %d",
                      rc);
        }
        msg_free(msg);
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"Mailbox Service not available");

        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MBOX::MOD_MBOXREGISTER
         * @reasoncode      MBOX::RC_MBOX_SERVICE_NOT_READY
         * @userdata1       queue_id_t queueId
         * @userdata2       0
         *
         * @defdesc         Mailbox service is not available now.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
             MBOX::MOD_MBOXREGISTER,              // moduleid
             MBOX::RC_MBOX_SERVICE_NOT_READY,     // reason code
             i_queue_id,
             0
            );
    }

    return err;
}

msg_q_t MBOX::msgq_unregister(queue_id_t i_queue_id)
{
    msg_q_t msgQ = NULL;
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_UNREGISTER_MSGQ;
        msg->data[0] = static_cast<uint64_t>(i_queue_id);

        int rc = msg_sendrecv(mboxQ, msg);

        if(!rc)
        {
            msgQ = reinterpret_cast<msg_q_t>(msg->data[1]);
        }
        else
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::msgq_unregister - msg_sendrecv failed. errno = %d",
                      rc);
        }

        msg_free(msg);
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"Mailbox Service not available");
    }

    return msgQ;
}



