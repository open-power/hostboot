/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mailboxsp.C $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/**
 * @file mailboxsp.C
 * @brief mailbox service provider definition
 */

#include "mailboxsp.H"
#include "mboxdd.H"
#include "ipcSp.H"
#include <sys/task.h>
#include <initservice/taskargs.H>
#include <initservice/initserviceif.H>
#include <sys/vfs.h>
#include <devicefw/userif.H>
#include <mbox/mbox_reasoncodes.H>
#include <mbox/mboxUdParser.H>
#include <targeting/common/commontargeting.H>
#include <kernel/ipc.H>
#include <arch/ppc.H>
#include <errl/errlmanager.H>

#define MBOX_TRACE_NAME MBOX_COMP_NAME

// Local functions
namespace MBOX
{
    errlHndl_t makeErrlMsgQSendFail(uint64_t i_errno);
};

using namespace MBOX;

// Defined in mboxdd.C
extern trace_desc_t * g_trac_mbox;
extern trace_desc_t * g_trac_mboxmsg;

const char MBOXMSG_TRACE_NAME[] = "MBOXMSG";
trace_desc_t* g_trac_mboxmsg = NULL; // g_trac_mbox;
TRAC_INIT(&g_trac_mboxmsg, MBOXMSG_TRACE_NAME,
          2*KILOBYTE, TRACE::BUFFER_SLOW);



/**
 * setup _start and handle barrier
 */
TASK_ENTRY_MACRO( MailboxSp::init );


MailboxSp::MailboxSp()
    :
        iv_msgQ(),
        iv_sendq(),
        iv_respondq(),
        iv_dmaBuffer(),
        iv_trgt(NULL),
        iv_shutdown_msg(NULL),
        iv_rts(true),
        iv_dma_pend(false),
        iv_disabled(true),
        iv_suspended(false)
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
void* MailboxSp::msg_handler(void * unused)
{
    Singleton<MailboxSp>::instance().msgHandler();
    return NULL;
}


errlHndl_t MailboxSp::_init()
{
    errlHndl_t err = NULL;
    size_t rc = 0;

    iv_msgQ = msg_q_create();
    rc = msg_q_register(iv_msgQ, VFS_ROOT_MSG_MBOX);

    if(rc)   // could not register msgQ with kernel
    {
        TRACFCOMP(g_trac_mbox,ERR_MRK "MailboxSP::_init() Could not register"
                  "message qeueue with kernel");

        /*@ errorlog tag
         * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
         * @moduleid        MBOX::MOD_MBOXSRV_INIT
         * @reasoncode      MBOX::RC_KERNEL_REG_FAILED
         * @userdata1       rc from msq_q_register
         * @devdesc         Could not register mailbox message queue
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
             MBOX::MOD_MBOXSRV_INIT,
             MBOX::RC_KERNEL_REG_FAILED,    //  reason Code
             rc,                        // rc from msg_send
             0
            );

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        return err;
    }

    bool mbxComm = mailbox_enabled();

    // create task before registering the msgQ so any waiting interrupts get
    // handled as soon as the msgQ is registered with the interrupt service
    // provider
    task_create(MailboxSp::msg_handler, NULL);

    if(mbxComm)
    {
        // Initialize the mailbox hardware
        err = mboxInit(iv_trgt);
        if (err)
        {
            return err;
        }

        // Register to get interrupts for mailbox
        err = INTR::registerMsgQ(iv_msgQ,
                                 MSG_INTR,
                                 INTR::FSP_MAILBOX);
        if(err)
        {
            return err;
        }
    }

    // Register for IPC messages
    err = INTR::registerMsgQ(iv_msgQ,
                             MSG_IPC,
                             INTR::ISN_INTERPROC);


    if(mbxComm)
    {
        // Enable the mailbox
        iv_disabled = false;

        // Send message to FSP on base DMA buffer zone
        msg_t * msg = msg_allocate();
        msg->type = MSG_INITIAL_DMA;
        msg->data[0] = 0;
        msg->data[1] =iv_dmaBuffer.toPhysAddr(iv_dmaBuffer.getDmaBufferHead());
        msg->extra_data = NULL;
        MBOX::send(FSP_MAILBOX_MSGQ,msg);

        // Register for shutdown
        INITSERVICE::registerShutdownEvent(iv_msgQ,
                                           MSG_MBOX_SHUTDOWN,
                                           INITSERVICE::MBOX_PRIORITY);
    }
    // else leave iv_disabled as true;

    // Start the the interprocessor communications message handler
    IPC::IpcSp::init(err);

    // call ErrlManager function - tell him that MBOX is ready!
    ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::MBOX);

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
                    err = handleInterrupt();

                    // Respond to the interrupt handler regardless of err
                    msg->data[0] = 0;
                    msg->data[1] = 0;
                    msg_respond(iv_msgQ,msg);

                    // err will be set if scom failed in mbox DD
                    // or MBOX_DATA_WRITE_ERR  - serious - assert
                    if(err)
                    {
                        errlCommit(err,MBOX_COMP_ID);

                        TRACFCOMP(g_trac_mbox, ERR_MRK"MBOXSP HALTED on critical error!");
                        crit_assert(0);
                    }

                    if(iv_shutdown_msg && quiesced())
                    {
                        handleShutdown();
                    }

                    if(iv_suspended && quiesced())
                    {
                        suspend();
                    }
                }

                break;


            case MSG_SEND:
                handleNewMessage(msg);
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

            case MSG_MBOX_SHUTDOWN:
                {
                    TRACFCOMP(g_trac_mbox,"MBOXSP Shutdown event received");

                    iv_shutdown_msg = msg;      // Respond to this when done
                    iv_disabled = true;         // stop incomming new messages

                    if(iv_suspended == true)
                    {
                        resume();
                    }

                    handleUnclaimed();
                    if(quiesced())
                    {
                        handleShutdown();       // done - shutdown now.
                    }
                    // else wait for things to quiesce
                }
                break;

            case MSG_MBOX_SUSPEND:

                if(!iv_disabled)
                {
                    TRACFCOMP(g_trac_mbox,
                              INFO_MRK"MBOXSP Suspend event received");

                    iv_suspend_msg = msg;   // Respond to this when done
                    iv_suspended = true;    // Queue any new messages

                    if(quiesced())
                    {
                        suspend();    // suspended
                    }
                }
                else
                {
                    TRACFCOMP(g_trac_mbox,
                              INFO_MRK"MBOXSP Ignored request to suspend a"
                              " disabled mailbox");
                    msg_respond(iv_msgQ,msg);
                }
                break;

            case MSG_MBOX_RESUME:

                resume();
                msg_respond(iv_msgQ,msg);
                TRACFCOMP(g_trac_mbox,INFO_MRK"Mailbox function resumed");

                break;

            case MSG_IPC: // Interprocessor Messages
                // Look for IPC message
                // If not, just ignore
                handleIPC();
                msg->data[0] = 0;
                msg->data[1] = 0;
                msg_respond(iv_msgQ,msg);

                break;

            default:

                TRACFCOMP(g_trac_mbox, ERR_MRK "MailboxSp::msgHandler() "
                          "invalid message received 0x%08x",msg->type);

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MBOX::MOD_MBOXSRV_HNDLR
                 * @reasoncode      MBOX::RC_INVALID_MBOX_MSG_TYPE
                 * @userdata1       Message type
                 * @devdesc         Invalid message type sent to mailbox msgQ
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_HNDLR,
                     MBOX::RC_INVALID_MBOX_MSG_TYPE,    //  reason Code
                     msg->type,                         // msg type
                     0
                    );

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                errlCommit(err,MBOX_COMP_ID);
                err = NULL;

                msg_free(msg);

                break;
        }

    } // while(1)
}


void MailboxSp::handleNewMessage(msg_t * i_msg)
{
    // Build mailbox message
    mbox_msg_t mbox_msg;
    mbox_msg.msg_queue_id = static_cast<uint32_t>(i_msg->data[0]);
    msg_t * payload = reinterpret_cast<msg_t*>(i_msg->extra_data);
    mbox_msg.msg_payload = *payload;  //copy in payload
    bool i_msg_is_async = msg_is_async(i_msg);

    if(i_msg_is_async)
    {
        msg_free(payload);
        msg_free(i_msg);
        payload = NULL;
        i_msg = NULL;
    }

    if(iv_disabled)
    {
        TRACFCOMP(g_trac_mbox,WARN_MRK
                  "MSGSEND - mailboxsp is disabled. Message dropped!"
                  " msgQ=0x%x type=0x%x",
                  mbox_msg.msg_queue_id,
                  mbox_msg.msg_payload.type);

        if(!i_msg_is_async) // synchronous
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        MOD_MBOXSRV_SENDMSG
             * @reasoncode      RC_MAILBOX_DISABLED
             * @userdata1       queue_id
             * @userdata2       message type
             * @devdesc         Mailbox is disabled, message dropped.
             */
            errlHndl_t err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,
                 MBOX::MOD_MBOXSRV_SENDMSG,
                 MBOX::RC_MAILBOX_DISABLED,        //  reason Code
                 i_msg->data[0],                   // queue id
                 payload->type                     // message type
                );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

            i_msg->data[1] = reinterpret_cast<uint64_t>(err);

            payload->extra_data = NULL;

            msg_respond(iv_msgQ,i_msg);
        }

        if( mbox_msg.msg_payload.extra_data != NULL )
        {
            TRACDCOMP( g_trac_mbox, "free extra_data %p",
                        mbox_msg.msg_payload.extra_data );

            free ( mbox_msg.msg_payload.extra_data );

            mbox_msg.msg_payload.extra_data = NULL;
        }

    }
    else
    {

        if(!i_msg_is_async)  //synchronous
        {
            i_msg->data[1] = 0;  // used later for return value

            // need to watch for a response
            msg_respond_t * response = new msg_respond_t(i_msg);

            // Convert a 64 bit pointer to a 32 bit unsigned int.
            mbox_msg.msg_id =
                static_cast<uint32_t>
                (reinterpret_cast<uint64_t>(response->key));

            iv_respondq.insert(response);
        }

        send_msg(&mbox_msg);
    }

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
    //  - The mailbox is suspended
    //  - there is nothing to send
    //
    //  Future enhancement: If both iv_rts and iv_dma_pend are true then
    //  could look for a mesaage from a different msgq in the sendq that does
    //  not require a DMA buffer and send it.
    if(!iv_rts || iv_dma_pend || iv_suspended || iv_sendq.size() == 0)
    {
        return;
    }

    errlHndl_t err = NULL;

    mbox_msg_t * mbox_msg = &(iv_sendq.front());;
    msg_t * payload = &(mbox_msg->msg_payload);

    iv_msg_to_send = *mbox_msg; //copy

    // Is a DMA buffer needed?
    if((payload->extra_data != NULL) ||
       ((iv_msg_to_send.msg_queue_id == HB_MAILBOX_MSGQ) &&
        (payload->type == MSG_REQUEST_DMA_BUFFERS)))

    {
        uint64_t dma_size = payload->data[1];

        if(payload->extra_data == NULL) // DMA req. from FSP.
        {
            dma_size = payload->data[0];
        }

        // getBuffer() returns bit map in dma_size variable.
        void * dma_buffer = iv_dmaBuffer.getBuffer(dma_size);

        if(dma_buffer)
        {
            if(payload->extra_data != NULL)
            {
                memcpy(dma_buffer,payload->extra_data,payload->data[1]);
                iv_msg_to_send.msg_payload.extra_data =
                  reinterpret_cast<void*>(iv_dmaBuffer.toPhysAddr(dma_buffer));

                free(payload->extra_data);
            }
            else  // DMA buffer request from FSP
            {
                iv_msg_to_send.msg_payload.data[0] = dma_size; // bitmap
                iv_msg_to_send.msg_payload.data[1] =
                iv_dmaBuffer.toPhysAddr(dma_buffer);
            }
            iv_sendq.pop_front();
        }
        else // can't get buffer
        {
            if(!iv_dmaBuffer.ownsAllBlocks())
            {
                //   -- can't send the current message - leave it on the queue
                //   -- Instead send a message to FSP for more buffers
                iv_msg_to_send.msg_id = 0;
                iv_msg_to_send.msg_queue_id = FSP_MAILBOX_MSGQ;
                iv_msg_to_send.msg_payload.type = MSG_REQUEST_DMA_BUFFERS;
                iv_msg_to_send.msg_payload.data[0] = 0;
                iv_msg_to_send.msg_payload.data[1] = 0;
                iv_msg_to_send.msg_payload.extra_data = NULL;
                iv_msg_to_send.msg_payload.__reserved__async = 1;
                iv_dma_pend = true;
            }
            else
            {
                // message is asking from more DMA space than exists
                TRACFCOMP(g_trac_mbox,
                          ERR_MRK
                          "MailboxSp::send_msg - Message dropped. "
                          "Can't get DMA buffer size %d. queueid 0x%x",
                          payload->data[1],
                          iv_msg_to_send.msg_queue_id);

                iv_sendq.pop_front();
                if(payload->extra_data == NULL)  //Request was from FSP
                {
                    // just respond with failure
                    iv_msg_to_send.msg_payload.data[0] = 0;
                    iv_msg_to_send.msg_payload.data[1] = 0;
                }
                else
                {
                    /*@ errorlog tag
                     * @errortype       ERRL_SEV_INFORMATIONAL
                     * @moduleid        MOD_MBOXSRV_SENDMSG
                     * @reasoncode      RC_INVALID_DMA_LENGTH
                     * @userdata1       DMA length requested
                     * @userdata2       queue_id
                     * @devdesc         Failed to allocate a DMA buffer.
                     *                  Message dropped.
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         MBOX::MOD_MBOXSRV_SENDMSG,
                         MBOX::RC_INVALID_DMA_LENGTH,      //  reason Code
                         payload->data[1],                 // DMA data len
                         iv_msg_to_send.msg_queue_id       // MSG queueid
                        );

                    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_HIGH);

                    send_msg();  // drop this message, but send next message
                }
            }
        }
    }
    else // simple message
    {
        iv_sendq.pop_front();
    }

    if(!err)
    {
        size_t mbox_msg_len = sizeof(mbox_msg_t);
        iv_rts = false;

        trace_msg("SEND",iv_msg_to_send);

        err = DeviceFW::deviceWrite(iv_trgt,
                                    &iv_msg_to_send,
                                    mbox_msg_len,
                                    DeviceFW::MAILBOX);
    }

    if(err)
    {
        TRACFCOMP(g_trac_mbox,
                  ERR_MRK
                  "MBOX send_msg could not send message. queue:%x type:%x",
                  iv_msg_to_send.msg_queue_id,
                  iv_msg_to_send.msg_payload.type);

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
            errlCommit(err,MBOX_COMP_ID);
            err = NULL;
        }
    }
}


void MailboxSp::recv_msg(mbox_msg_t & i_mbox_msg)
{
    errlHndl_t err = NULL;
    int rc = 0;

    //trace_msg("RECV",i_mbox_msg);

    msg_t * msg = msg_allocate();
    *msg = i_mbox_msg.msg_payload;  // copy

    // Handle moving data from DMA buffer
    if(iv_dmaBuffer.isDmaAddress(msg->extra_data))
    {
        uint64_t msg_sz = msg->data[1];
        void * buf = malloc(msg_sz);
        memcpy(buf,msg->extra_data,msg_sz);

        iv_dmaBuffer.release(msg->extra_data,msg_sz);
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

        // resonse->key points to original carrier msg
        // reponse->key->extra_data points to the orignal msg
        // Overwrite original message with response

        *(reinterpret_cast<msg_t *>((response->key)->extra_data)) = *msg; // copy

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
                     * @moduleid        MBOX::MOD_MBOXSRV_RCV
                     * @reasoncode      MBOX::RC_MSG_SEND_ERROR
                     * @userdata1       rc from msg_send()
                     * @userdata2       msg queue id
                     * @devdesc         Invalid msg or msg queue
                     *
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         MBOX::MOD_MBOXSRV_RCV,
                         MBOX::RC_MSG_SEND_ERROR,   //  reason Code
                         rc,                        // rc from msg_send
                         i_mbox_msg.msg_queue_id
                        );

                    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                             HWAS::SRCI_PRIORITY_HIGH);

                    UserDetailsMboxMsg
                        ffdc(reinterpret_cast<uint64_t*>(&i_mbox_msg),
                             sizeof(mbox_msg_t),
                             reinterpret_cast<uint64_t*>(msg->extra_data),
                             msg->data[1]);

                    ffdc.addToLog(err);

                    err->collectTrace(MBOXMSG_TRACE_NAME);
                    errlCommit(err,MBOX_COMP_ID);

                    free(msg->extra_data);
                    msg_free(msg);

                    TRACFCOMP(g_trac_mbox,
                              ERR_MRK"MBOXSP HALTED on critical error!");
                    crit_assert(0);

                }
            }
            else // Bad type range
            {
                //  Send a message to the FSP
                mbox_msg_t mbox_msg;
                mbox_msg.msg_queue_id = FSP_MAILBOX_MSGQ;
                mbox_msg.msg_payload.type = MSG_INVALID_MSG_TYPE;
                mbox_msg.msg_id = i_mbox_msg.msg_id;

                // msg_id and msg_queue_id
                mbox_msg.msg_payload.data[0] =
                    *(reinterpret_cast<uint64_t*>(&i_mbox_msg));
                // type & flags
                mbox_msg.msg_payload.data[1] =
                    *(reinterpret_cast<uint64_t*>(msg));

                mbox_msg.msg_payload.extra_data = NULL;
                mbox_msg.msg_payload.__reserved__async = 0; // async


                send_msg(&mbox_msg);

                TRACFCOMP(g_trac_mbox,
                          ERR_MRK
                          "MailboxSp::recv_msg-Message type 0x%x range error."
                          " Message dropped.",
                          msg->type);

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MBOX::MOD_MBOXSRV_RCV
                 * @reasoncode      MBOX::RC_INVALID_MESSAGE_TYPE
                 * @userdata1       msg queue
                 * @userdata2       msg type
                 * @devdesc         Message from FSP. Message type is not
                 *                  within a valid range. Message dropped.
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_RCV,
                     MBOX::RC_INVALID_MESSAGE_TYPE  ,    //  reason Code
                     i_mbox_msg.msg_queue_id,            // rc from msg_send
                     msg->type
                    );

                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                UserDetailsMboxMsg
                    ffdc(reinterpret_cast<uint64_t*>(&i_mbox_msg),
                         sizeof(mbox_msg_t),
                         reinterpret_cast<uint64_t*>(msg->extra_data),
                         msg->data[1]);

                ffdc.addToLog(err);

                err->collectTrace(MBOXMSG_TRACE_NAME);
                errlCommit(err,MBOX_COMP_ID);

                free(msg->extra_data);
                msg_free(msg);
            }
        }
        // Else unregistered msg_queue_id
        //  For NOW, ignore FSP mailbox stuff bounced back by the echo server
        else if(i_mbox_msg.msg_queue_id != FSP_MAILBOX_MSGQ)
        {
            // copy in non-dma instance of payload msg back to mbox msg
            i_mbox_msg.msg_payload = *msg;

            // Is this msg_queue_id valid ?
            if(i_mbox_msg.msg_queue_id < HB_LAST_VALID_MSGQ  &&
               i_mbox_msg.msg_queue_id > HB_MAILBOX_MSGQ)
            {
                // Queue message to wait until queue is registered.
                iv_pendingq.push_back(i_mbox_msg);

                TRACFCOMP(g_trac_mbox,
                          INFO_MRK
                          "MailboxSp::recv_msg. Unregistered msg queue id 0x%x"
                          " message queued.",
                          i_mbox_msg.msg_queue_id);
            }
            else // un defined HB message queue
            {
                // Tell the FSP mbox about it and log an error
                invalidMsgResponder(i_mbox_msg);
                free(msg->extra_data); // toss this if it exists
                msg->extra_data = NULL;
            }
            msg_free(msg);
        }
        else // This is a bounce-back msg from the echo server - Ignore
        {
            free(msg->extra_data);
            msg_free(msg);
        }
    }
}

void MailboxSp::handle_hbmbox_msg(mbox_msg_t & i_mbox_msg)
{
    msg_t * msg = &(i_mbox_msg.msg_payload);

    if(msg->type == MSG_REQUEST_DMA_BUFFERS)
    {
        // DMA req. will be resolved by send_msg
        send_msg(&i_mbox_msg);   // response message
    }
    else if(msg->type == MSG_INVALID_MSG_QUEUE_ID ||
            msg->type == MSG_INVALID_MSG_TYPE)
    {
        mbox_msg_t * bad_mbox_msg =
            reinterpret_cast<mbox_msg_t*>(&(msg->data[0]));
        msg_t * bad_msg = &(bad_mbox_msg->msg_payload);

        TRACFCOMP(g_trac_mbox, ERR_MRK"Invalid message was sent to FSP. Queue"
                  " id: 0x%08x Type: %08x",
                  bad_mbox_msg->msg_queue_id,
                  bad_msg->type);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MOD_MBOXSRV_FSP_MSG
         * @reasoncode      RC_INVALID_QUEUE
         * @userdata1       msg queue
         * @userdata2       msg type
         * @devdesc         Message from FSP. An invalid message queue ID
         *                  or mesage type was sent to the FSP.
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,
             MBOX::MOD_MBOXSRV_FSP_MSG,
             MBOX::RC_INVALID_QUEUE,
             bad_mbox_msg->msg_queue_id,
             bad_msg->type
            );

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);

        UserDetailsMboxMsg
            ffdc(reinterpret_cast<uint64_t*>(&i_mbox_msg),
                 sizeof(mbox_msg_t),
                 reinterpret_cast<uint64_t*>(msg->extra_data),
                 msg->data[1]);

        ffdc.addToLog(err);

        err->collectTrace(MBOXMSG_TRACE_NAME);

        // If the msg was sync then we need to respond to the
        // orignal sender and clean up the respondq
        if(!msg_is_async(bad_msg))
        {
            msg_t * key = reinterpret_cast<msg_t*>(bad_mbox_msg->msg_id);
            msg_respond_t * response = iv_respondq.find(key);
            if(response)
            {
                iv_respondq.erase(response); // unlink from the list

                //response->key->extra_data points to the original msg
                // Send back the error log
                response->key->data[1] = reinterpret_cast<uint64_t>(err);
                err = NULL;
                msg_respond(iv_msgQ,response->key);

                delete response;
            }
            else // nothing to respond to - just log the error
            {
                errlCommit(err,MBOX_COMP_ID);
            }
        }
        else // async - nothing to respond to -just log the error
        {
            errlCommit(err,MBOX_COMP_ID);
        }
    }
    else // unknown/un-architected message from fsp MBOX
    {
        TRACFCOMP(g_trac_mbox,
                  ERR_MRK
                  "Unknown message of type 0x%x received from FSP.",
                  msg->type);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MBOX::MOD_MBOXSRV_FSP_MSG
         * @reasoncode      MBOX::RC_INVALID_MESSAGE_TYPE
         * @userdata1       msg type
         * @userdata2       msg queue id
         * @devdesc         Message from FSP to HB MBOX of an unknown type
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,
             MBOX::MOD_MBOXSRV_FSP_MSG,
             MBOX::RC_INVALID_MESSAGE_TYPE,
             msg->type,
             i_mbox_msg.msg_queue_id
            );

        err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
        UserDetailsMboxMsg
            ffdc(reinterpret_cast<uint64_t*>(&i_mbox_msg),
                 sizeof(mbox_msg_t),
                 reinterpret_cast<uint64_t*>(msg->extra_data),
                 msg->data[1]);

        ffdc.addToLog(err);

        err->collectTrace(MBOXMSG_TRACE_NAME);

        errlCommit(err,MBOX_COMP_ID);
    }

}


void MailboxSp::handle_hbmbox_resp(mbox_msg_t & i_mbox_msg)
{

    //Response for more DMA buffers
    if(i_mbox_msg.msg_payload.data[0] != 0)
    {
        iv_dmaBuffer.addBuffers
            (i_mbox_msg.msg_payload.data[0]);
        iv_dma_pend = false;
        send_msg(); // send next message on queue
    }
    else // This is not really a response from the FSP
        // This is an echo back from echo server of a req the HB MBOX sent.
    {
        // This message should never come from the real FSP, so it must be
        // from the echo server. Responding to the echo server will
        // make the message echo back again as if it were a response from the
        // FSP. Since it's not possible to know which buffers the FSP owns, for
        // testing purposes play the role of the FSP and assume the FSP owns
        // all DMA buffers and will return them all.
        // TODO This should probably be removed when/if the echo server
        // is no longer used.
        TRACFCOMP(g_trac_mbox,"FAKEFSP returning all DMA buffers");

        i_mbox_msg.msg_payload.data[0] = 0xFFFFFFFFFFFFFFFF;

        // Since the HB is waiting for DMA buffers and holding up all other
        // messages, just sneek this one on the front of the queue, disable
        // the dma_pending flag to just long enough to send this message.
        // All other values in the msg should be left as is.
        iv_dma_pend = false;
        iv_sendq.push_front(i_mbox_msg);
        send_msg(); // respond
        iv_dma_pend = true;
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

    if(mboxQ != NULL)
    {
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
             * @moduleid        MBOX::MOD_MBOXSRV_SEND
             * @reasoncode      MBOX::RC_INVALID_QUEUE
             * @userdata1       returncode from msg_sendrecv()
             *
             * @devdesc         Invalid message or message queue
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

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

            // This Trace has the msg
            err->collectTrace(MBOXMSG_TRACE_NAME);
        }
    }
    else
    {
        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MBOX::MOD_MBOXSRV_SEND
         * @reasoncode      MBOX::RC_MBOX_SERVICE_NOT_READY
         * @userdata1       The destination message queue id
         *
         * @devdesc         Host boot mailbox service is not available
         *                  at this time.
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
             MBOX::MOD_MBOXSRV_SEND,                 //  moduleid
             MBOX::RC_MBOX_SERVICE_NOT_READY,        //  reason Code
             i_q_id,                                 //  queue id
             0                                       //
            );

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
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

        TRACFCOMP(g_trac_mbox,INFO_MRK"MailboxSp::msgq_register queue id 0x%x",
                  i_queue_id);

        // Look for pending messages and send them.
        // Note: remove_if and remove_copy_if not implemented in HB code.
        size_t size = iv_pendingq.size();
        while(size--)
        {
            send_q_t::iterator mbox_msg = iv_pendingq.begin();
            if(i_queue_id == mbox_msg->msg_queue_id)
            {
                recv_msg(*mbox_msg);
            }
            else
            {
                iv_pendingq.push_back(*mbox_msg);
            }

            iv_pendingq.pop_front();
        }
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
             * @devdesc         Message queue already registered with mailbox
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

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);
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
        TRACFCOMP(g_trac_mbox,INFO_MRK"MailboxSp::msgq_unregister queue id 0x%x",
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


errlHndl_t MailboxSp::handleInterrupt()
{
    errlHndl_t err = NULL;
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
        err->collectTrace(MBOX_TRACE_NAME);
        err->collectTrace(MBOXMSG_TRACE_NAME);
    }
    else
    {
        TRACDCOMP(g_trac_mbox,"MBOXSP: status=%lx",mbox_status);

        if(mbox_status & MBOX_HW_ACK)
        {
            // send next message if there is one.
            iv_rts = true;
            send_msg();
        }

        if(mbox_status & MBOX_DATA_PENDING)
        {
            trace_msg("RECV",mbox_msg);
            //Adjust address back to Virt here if present
            uint64_t l_dma = reinterpret_cast<uint64_t>(
                           mbox_msg.msg_payload.extra_data);
            if(l_dma)
            {
                mbox_msg.msg_payload.extra_data =
                  iv_dmaBuffer.toVirtAddr(l_dma);
            }

            if(mbox_msg.msg_queue_id == HB_MAILBOX_MSGQ)
            {
                // msg to hb mailbox from fsp mbox
                handle_hbmbox_msg(mbox_msg);
            }
            else if((mbox_msg.msg_queue_id==FSP_MAILBOX_MSGQ)&&
                    (mbox_msg.msg_payload.type == MSG_REQUEST_DMA_BUFFERS))
            {
                // This is a response from the FSP mbox for more DMA buffers
                handle_hbmbox_resp(mbox_msg);
            }
            else
            {
                // anything else
                recv_msg(mbox_msg);
            }
        }

        // Look for error status from MB hardware
        if(mbox_status & MBOX_DOORBELL_ERROR)
        {
            TRACFCOMP(g_trac_mbox,
                      ERR_MRK"MBOX Hardware reported errors detected status 0x%lx",
                      mbox_status);

            if(mbox_status & MBOX_DATA_WRITE_ERR)
            {
                // Write attempted before ACK - HB code error
                /*@ errorlog tag
                 * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid        MOD_MBOXSRV_HNDLR
                 * @reasoncode      RC_DATA_WRITE_ERR
                 * @userdata1       Status from MB device driver
                 * @devdesc         Mailbox Data Write attempted
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

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->collectTrace(MBOX_TRACE_NAME);
                err->collectTrace(MBOXMSG_TRACE_NAME);
                // return err
            }

            else if(mbox_status & MBOX_PARITY_ERR)
            {
                // Hardware detected parity error
                // Log it and continue

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MBOX::MOD_MBOXSRV_HNDLR
                 * @reasoncode      MBOX::RC_PARITY_ERR
                 * @userdata1       Status from MB device driver
                 * @devdesc         Mailbox Hardware detected
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

                err->addHwCallout(iv_trgt,
                                  HWAS::SRCI_PRIORITY_HIGH,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL);

                err->collectTrace(MBOX_TRACE_NAME);
                errlCommit(err,MBOX_COMP_ID);
            }
            else if(mbox_status & MBOX_ILLEGAL_OP)
            {
                // Code problem could be FSP or HB
                // - log error and continue.

                /*@ errorlog tag
                 * @errortype       ERRL_SEV_INFORMATIONAL
                 * @moduleid        MBOX::MOD_MBOXSRV_HNDLR
                 * @reasoncode      MBOX::RC_ILLEGAL_OP
                 * @userdata1       Status from MB device driver
                 * @devdesc         Retry failed. Bad status
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

                err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                err->addHwCallout(iv_trgt,
                                  HWAS::SRCI_PRIORITY_LOW,
                                  HWAS::NO_DECONFIG,
                                  HWAS::GARD_NULL);

                err->collectTrace(MBOX_TRACE_NAME);
                errlCommit(err,MBOX_COMP_ID);
            }

            //else if(mbox_status & MBOX_DATA_READ_ERR)
            //{
            //    // Read when no message available
            //    - Just ignore this one per Dean.
            //}


            // The code has the ability to retry sending a
            // message, but currently there is no error state
            // that requires it.
        }
    }

    return err;
}

void MailboxSp::handleIPC()
{
    // Check for IPC message. If no msg then ignore - could be other things
    // All IPC messages are secure
    uint64_t msg_q_id = KernelIpc::ipc_data_area.msg_queue_id;

    // msg_q_id == 0  means no IPC message available
    // msg_q_id == (all ones) means message incomming, but not ready and
    //                not associated with this interupt
    if(msg_q_id == 0xFFFFFFFFFFFFFFFFul)
    {
        msg_q_id = 0;
    }

    // destination message queue id is lower 32 bits.
    msg_q_id &= 0x00000000FFFFFFFFull;
    if(0 != msg_q_id)
    {
        msg_t * msg = msg_allocate();
        isync();
        *msg = KernelIpc::ipc_data_area.msg_payload;
        lwsync();
        KernelIpc::ipc_data_area.msg_queue_id = 0; // set ready for next msg

        TRACFCOMP(g_trac_mboxmsg,
                  "MBOXSP IPC RECV MSG: msg_id:0x%08x",
                  (uint32_t)msg_q_id);
        TRACFCOMP(g_trac_mboxmsg,
                  "MBOXSP IPC RECV MSG: 0x%08x 0x%016lx 0x%016lx %p",
                  msg->type,
                  msg->data[0],
                  msg->data[1],
                  msg->extra_data);
        
        registry_t::iterator r = 
            iv_registry.find(static_cast<queue_id_t>(msg_q_id));
        if(r != iv_registry.end())
        {
            // found queue
            msg_q_t msgq = r->second;

            // Only async message supported right now
            // Interface already inforces this.
            int rc = msg_send(msgq,msg);

            if(rc)
            {
                /*@ errorlog tag
                 * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid        MBOX::MOD_MBOXSRV_IPC_MSG
                 * @reasoncode      MBOX::RC_MSG_SEND_ERROR
                 * @userdata1       rc from msg_send()
                 * @userdata2       msg queue id
                 * @devdesc         Invalid msg or msg queue
                 *
                 */
                errlHndl_t err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     MBOX::MOD_MBOXSRV_IPC_MSG,
                     MBOX::RC_MSG_SEND_ERROR,   //  reason Code
                     rc,                        // rc from msg_send
                     msg_q_id
                    );

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);

                UserDetailsMboxMsg
                    ffdc(reinterpret_cast<uint64_t*>(msg),
                         sizeof(msg_t));

                ffdc.addToLog(err);

                err->collectTrace(MBOXMSG_TRACE_NAME);
                errlCommit(err,MBOX_COMP_ID);

                msg_free(msg);
            }
        }
        else // not registered
        {
            // thow it away log error
            TRACFCOMP(g_trac_mbox,
                      ERR_MRK
                      "MailboxSp::handleIPC: Unregistered msg queue id 0x%x"
                      " message dropped.",
                      msg_q_id);

            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        MOD_MBOXSRV_IPC_MSG
             * @reasoncode      RC_INVALID_QUEUE
             * @userdata1       msg queue
             * @userdata2       msg type
             * @devdesc         Invalid message queue ID
             */
            errlHndl_t err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,
                 MBOX::MOD_MBOXSRV_IPC_MSG,
                 MBOX::RC_INVALID_QUEUE,
                 msg_q_id,
                 msg->type
                );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);

            UserDetailsMboxMsg
                ffdc(reinterpret_cast<uint64_t*>(msg), sizeof(msg_t));

            ffdc.addToLog(err);
            err->collectTrace(MBOXMSG_TRACE_NAME);
            errlCommit(err,MBOX_COMP_ID);

            msg_free(msg);
        }
        
    }
}

// Send a message to the FSP mailbox that a message it sent
// had an invalid or undeliverable message
void MailboxSp::invalidMsgResponder(mbox_msg_t & i_mbox_msg)
{
    mbox_msg_t r_mbox_msg;
    r_mbox_msg.msg_queue_id = FSP_MAILBOX_MSGQ;
    r_mbox_msg.msg_payload.type = MSG_INVALID_MSG_QUEUE_ID;
    r_mbox_msg.msg_id = i_mbox_msg.msg_id;

    // data[0] = msg_id and msg_queue_id
    r_mbox_msg.msg_payload.data[0] =
        *(reinterpret_cast<uint64_t*>(&i_mbox_msg));
    // data[1] = type & flags
    r_mbox_msg.msg_payload.data[1] =
        *(reinterpret_cast<uint64_t*>(&(i_mbox_msg.msg_payload)));

    r_mbox_msg.msg_payload.extra_data = NULL;
    r_mbox_msg.msg_payload.__reserved__async = 0; // async

    send_msg(&r_mbox_msg);


    TRACFCOMP(g_trac_mbox,
              ERR_MRK
              "MailboxSp::invalidMsgResponder> Unclaimed mbox message from"
              " FSP. Queueid 0x%08x",
              i_mbox_msg.msg_queue_id);

    /*@ errorlog tag
     * @errortype       ERRL_SEV_INFORMATIONAL
     * @moduleid        MBOX::MOD_MBOXSRC_UNCLAIMED
     * @reasoncode      MBOX::RC_INVALID_QUEUE
     * @userdata1       msg queue
     * @userdata2       msg type
     * @devdesc         Message from FSP. Message not claimed
     *                  by any Hostboot service.
     */
    errlHndl_t err = new ERRORLOG::ErrlEntry
        (
         ERRORLOG::ERRL_SEV_INFORMATIONAL,
         MBOX::MOD_MBOXSRC_UNCLAIMED,
         MBOX::RC_INVALID_QUEUE,            //  reason Code
         i_mbox_msg.msg_queue_id,           //  message queue id
         i_mbox_msg.msg_payload.type        //  message type
        );

    err->addProcedureCallout(HWAS::EPUB_PRC_SP_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

    err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                             HWAS::SRCI_PRIORITY_HIGH);

    UserDetailsMboxMsg
        ffdc(reinterpret_cast<uint64_t*>(&i_mbox_msg),
             sizeof(mbox_msg_t),
             reinterpret_cast<uint64_t*>
             (i_mbox_msg.msg_payload.extra_data),
             i_mbox_msg.msg_payload.data[1]);

    ffdc.addToLog(err);

    errlCommit(err,MBOX_COMP_ID);
}

// Handle unclaimed messages in iv_pendingq
void MailboxSp::handleUnclaimed()
{
    for(send_q_t::iterator mbox_msg = iv_pendingq.begin();
        mbox_msg != iv_pendingq.end();
        ++mbox_msg)
    {
        invalidMsgResponder(*mbox_msg);
    }
    iv_pendingq.clear();
}


void MailboxSp::handleShutdown()
{
    // Shutdown the hardware
    errlHndl_t err = mboxddShutDown(iv_trgt);

    INTR::unRegisterMsgQ(INTR::FSP_MAILBOX);
    INTR::unRegisterMsgQ(INTR::ISN_INTERPROC);

    if(err)  // SCOM failed.
    {
        // If this failed, the whole system is probably buggered up.

        errlCommit(err,MBOX_COMP_ID);

        TRACFCOMP(g_trac_mbox,
                  ERR_MRK"MBOXSP Shutdown. HALTED on critical error!");
        crit_assert(0);
    }

    msg_respond(iv_msgQ,iv_shutdown_msg);
    TRACFCOMP(g_trac_mbox,INFO_MRK"Mailbox is shutdown");
}

void MailboxSp::suspend()
{
    // Mask interrupts in the mbox hardware
    errlHndl_t err = mboxddMaskInterrupts(iv_trgt);
    if(err)  // SCOM failed.
    {
        // If this failed, the whole system is probably buggered up.

        errlCommit(err,MBOX_COMP_ID);

        TRACFCOMP(g_trac_mbox,
                  ERR_MRK"MBOXSP Suspend. HALTED on critical error!");
        crit_assert(0);
    }

    msg_respond(iv_msgQ,iv_suspend_msg);
    TRACFCOMP(g_trac_mbox,INFO_MRK"Mailbox is suspended");
}

void MailboxSp::resume()
{
    iv_suspended = false;

    if(!iv_disabled)
    {
        // Enable the mbox hardware
        errlHndl_t err = mboxInit(iv_trgt);
        if(err)  // SCOM failed.
        {
            // If this failed, the whole system is probably buggered up.

            errlCommit(err,MBOX_COMP_ID);

            TRACFCOMP(g_trac_mbox,
                      ERR_MRK"MBOXSP Resume. HALTED on critical error!");
            crit_assert(0);
        }
        send_msg();   // send next message on queue
    }
}

// ----------------------------------------------------------------------------
// External Interfaces @see mboxif.H
// ----------------------------------------------------------------------------

errlHndl_t MBOX::send(queue_id_t i_q_id, msg_t * i_msg,int i_node)
{
    errlHndl_t err = NULL;

    i_msg->__reserved__async = 0;

    if(i_node == MBOX::MBOX_NODE_FSP)
    {
        err = MailboxSp::send(i_q_id, i_msg);
    }
    else // IPC msg
    {
        if(i_node < MSGQ_TYPE_IPC)
        {
            uint64_t q_handle = i_q_id;
            q_handle |= (((uint64_t)MSGQ_TYPE_IPC | (uint64_t)i_node) << 32);
            int rc = msg_send(reinterpret_cast<msg_q_t>(q_handle),
                              i_msg);

            if(rc)
            {
                /*@ errorlog tag
                 * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                 * @moduleid        MBOX::MOD_MBOX_SEND
                 * @reasoncode      MBOX::RC_INVALID_QUEUE
                 * @userdata1       returncode from msg_send()
                 *
                 * @devdesc         Invalid message or message queue
                 *
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,  //  severity
                     MBOX::MOD_MBOX_SEND,                   //  moduleid
                     MBOX::RC_INVALID_QUEUE,                //  reason Code
                     rc,                                    //  msg_send errno
                     q_handle                               //  msg queue id
                    );

                err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                         HWAS::SRCI_PRIORITY_HIGH);
                // This Trace has the msg
                err->collectTrace(MBOXMSG_TRACE_NAME);
            }
        }
        else
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        MBOX::MOD_MBOX_SEND
             * @reasoncode      MBOX::RC_IPC_INVALID_NODE
             * @userdata1       The destination queue id
             * @userdata2       The node
             *
             * @devdesc         An invalid node was specified
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
                 MBOX::MOD_MBOX_SEND,                    //  moduleid
                 MBOX::RC_IPC_INVALID_NODE,              //  reason Code
                 i_q_id,                                 //  queue id
                 i_node                                  //
                );

            err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                     HWAS::SRCI_PRIORITY_HIGH);
        }
    }
    return err;
}

// ---------------------------------------------------------------------------

errlHndl_t MBOX::sendrecv(queue_id_t i_q_id, msg_t * io_msg)
{
    io_msg->__reserved__async = 1;
    return MailboxSp::send(i_q_id, io_msg);
}

// ---------------------------------------------------------------------------

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
         * @devdesc         Mailbox service is not available now.
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

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
    }

    return err;
}

// ---------------------------------------------------------------------------

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

// ---------------------------------------------------------------------------

bool MBOX::mailbox_enabled()
{
    bool enabled = false;

    TARGETING::Target * sys = NULL;

    TARGETING::targetService().getTopLevelTarget( sys );

    TARGETING::SpFunctions spfuncs;

    if( sys &&
        sys->tryGetAttr<TARGETING::ATTR_SP_FUNCTIONS>(spfuncs) &&
        spfuncs.mailboxEnabled)
    {
        enabled = true;
    }

    return enabled;
}

errlHndl_t MBOX::suspend()
{
    errlHndl_t err = NULL;
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_MBOX_SUSPEND;

        int rc = msg_sendrecv(mboxQ, msg);

        if (rc)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::suspend msg_sendrecv() failed. errno = %d",
                      rc);

            err = makeErrlMsgQSendFail(rc);
        }

        msg_free(msg);
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"Mailbox Service not available");
    }

    return err;
}

errlHndl_t MBOX::resume()
{
    errlHndl_t err = NULL;
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_MBOX_RESUME;

        int rc = msg_sendrecv(mboxQ, msg);

        if (rc)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::resume msg_sendrecv failed. errno = %d",
                      rc);
            err = makeErrlMsgQSendFail(rc);
        }

        msg_free(msg);
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"Mailbox Service not available");
    }

    return err;
}

errlHndl_t MBOX::makeErrlMsgQSendFail(uint64_t i_errno)
{
        TRACFCOMP(g_trac_mbox, ERR_MRK"Mailbox Service not available");

        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MBOX::MOD_MBOX_MSGQ_FAIL
         * @reasoncode      MBOX::RC_MSG_SEND_ERROR
         * @userdata1       kernel errno
         * @userdata2       <unused>
         *
         * @devdesc         Message send to mailbox sp failed
         *
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
             MBOX::MOD_MBOX_MSGQ_FAIL,            // moduleid
             MBOX::RC_MSG_SEND_ERROR,             // reason code
             i_errno,
             0
            );

        err->addProcedureCallout(HWAS::EPUB_PRC_HB_CODE,
                                 HWAS::SRCI_PRIORITY_HIGH);
        
        return err;
}
