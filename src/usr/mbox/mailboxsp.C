/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mbox/mailboxsp.C $                                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
/* [+] Google Inc.                                                        */
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
#include <sys/misc.h>
#include <util/misc.H>
#include <errl/errludprintk.H>
#include <errno.h>
#include <kernel/console.H>
#include <arch/pirformat.H>
#include <sbeio/sbeioif.H>
#include <sys/time.h>
#include <intr/interrupt.H>
#include <targeting/attrrp.H>

// Local functions
namespace MBOX
{
    errlHndl_t makeErrlMsgQSendFail(uint64_t i_errno);
};

using namespace MBOX;

// Defined in mboxdd.C
extern trace_desc_t * g_trac_mbox;
extern trace_desc_t * g_trac_mboxmsg;

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
        iv_dmaRequestWatchdog(0),
        iv_trgt(NULL),
        iv_shutdown_msg(NULL),
        iv_rts(true),
        iv_dma_pend(false),
        iv_disabled(true),
        iv_suspended(false),
        iv_suspend_intr(false),
        iv_allow_blk_resp(false),
        iv_sum_alloc(0),
        iv_pend_alloc(),
        iv_allocAddrs(),
        iv_reclaim_sent_cnt(0),
        iv_reclaim_rsp_cnt(0)
{
    recursive_mutex_init(&iv_sendq_mutex);
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

    do {

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
         * @custdesc        An internal firmware error occurred
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
             MBOX::MOD_MBOXSRV_INIT,
             MBOX::RC_KERNEL_REG_FAILED,    //  reason Code
             rc,                        // rc from msg_send
             0,
             true //Add HB Software Callout
            );
        break;
    }

    bool mbxComm = mailbox_enabled();

    // create task before registering the msgQ so any waiting interrupts get
    // handled as soon as the msgQ is registered with the interrupt service
    // provider
    task_create(MailboxSp::msg_handler, NULL);

#ifdef CONFIG_SBE_PRESENT
    // Tell SBE to create Read-Write Memory Region for the DMA Buffer
    err = SBEIO::openUnsecureMemRegion(
        iv_dmaBuffer.toPhysAddr(iv_dmaBuffer.getDmaBufferHead()),
        VmmManager::MBOX_DMA_SIZE,
        true); //true=Read-Write
#endif
    if (err)
    {
        errlCommit(err,MBOX_COMP_ID);
    }

    if(mbxComm)
    {
        //TODO RTC 150260 Move after init after mask issues resolved
        // Register to get interrupts for mailbox
        err = INTR::registerMsgQ(iv_msgQ,
                                 MSG_INTR,
                                 INTR::FSP_MAILBOX);

        if (err)
        {
            break;
        }

        // Initialize the mailbox hardware
        err = mboxInit(iv_trgt);

        if (err)
        {
            break;
        }
    }

    // Register for IPC messages
    err = INTR::registerMsgQ(iv_msgQ,
                             MSG_IPC,
                             INTR::ISN_INTERPROC);
    if(err)
    {
        break;
    }

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
        INITSERVICE::registerShutdownEvent(MBOX_COMP_ID,
                                           iv_msgQ,
                                           MSG_MBOX_SHUTDOWN,
                                           INITSERVICE::MBOX_PRIORITY);

    }
    // else leave iv_disabled as true;

#ifndef CONFIG_VPO_COMPILE
    // Start the the interprocessor communications message handler
    IPC::IpcSp::init(err);

    // On error VFS won't initialize the mailbox address space, opening up
    // the chance of downstream task crashes later.
    if(!err)
    {
        // call ErrlManager function - tell him that MBOX is ready!
        // Note: this API does -not- return an error log, unlike the one below.
        ERRORLOG::ErrlManager::errlResourceReady(ERRORLOG::MBOX);

        // Inform attribute resource provider to enable FSP attribute sync
        // functionality
        err = TARGETING::AttrRP::notifyResourceReady(
                  TARGETING::AttrRP::RESOURCE::MAILBOX);
        if(err)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MailboxSp::_init: Failed in call to "
                      "TARGETING::AttrRP::notifyResourceReady.");
            break;
        }
    }

#endif
    } while(0);

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

        printkd("mbox received type: %d\n", (uint32_t) msg->type);

        // Now look for other messages
        switch(msg->type)
        {
            // Interrupt from the mailbox hardware
            case MSG_INTR:
                {
                    printkd("MSG_INTR type - handling interrupt\n");
                    err = handleInterrupt();

                    printkd("MSG_INTR type - sending EOI\n");
                    // Respond to the interrupt handler regardless of err
                    INTR::sendEOI(iv_msgQ,msg);

                    // err will be set if scom failed in mbox DD
                    // or MBOX_DATA_WRITE_ERR  - serious - assert
                    if(err)
                    {
                        errlCommit(err,MBOX_COMP_ID);

                        TRACFCOMP(g_trac_mbox, ERR_MRK
                                  "MBOXSP HALTED on critical error!");
                        crit_assert(0);
                    }

                    // note : an outstanding req dma bfrs msg
                    //         will cause quiesce to be false
                    if(iv_shutdown_msg && quiesced())
                    {
                        if // all DMA buffers have been reclaimed
                          ( iv_dmaBuffer.ownsAllBlocks() )
                        {
                            // continue with shutdown
                            TRACFCOMP(g_trac_mbox,
                                      INFO_MRK"MBOXSP DMA bfrs reclaimed "
                                              "on shutdown");

                            handleShutdown();
                        }

                        else if // a "reclaim bfr" msg is outstanding
                          ( isDmaReqBfrMsgOutstanding() )
                        {
                            // (need to wait for the msg(s) to complete
                            //   before sending another msg)
                            TRACFCOMP(g_trac_mbox,
                                      INFO_MRK
                                      "MailboxSp::msgHandler - "
                                      "Wait for Reclaim Msg Completion");
                        }

                        else if // more "reclaim bfr" msgs can be sent
                          ( iv_dmaBuffer.maxShutdownDmaRequestSent() == false )
                        {
                            TRACFCOMP(g_trac_mbox,
                                      INFO_MRK
                                      "MailboxSp::msgHandler - "
                                      "Send Reclaim Msg to FSP");

                            // send a "reclaim bfr" msg
                            iv_dmaBuffer.incrementShutdownDmaRequestSentCnt();
                            sendReclaimDmaBfrsMsg();
                        }

                        else
                        {
                            // continue with shutdown
                            TRACFCOMP(g_trac_mbox,
                                      INFO_MRK"MBOXSP DMA bfrs not reclaimed "
                                              "on shutdown");

                            handleShutdown();
                        }
                    } // end shutdown msg & quiesced

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
                    TRACFCOMP(g_trac_mbox,
                              "MBOXSP Shutdown event received. Status 0x%x",
                              msg->data[1]);

                    iv_shutdown_msg = msg;      // Respond to this when done

                    if(iv_suspended == true)
                    {
                        resume();
                    }
                    // Set iv_disabled after we have resumed the mbox interrupts so that the
                    // message queue can drain. If iv_disabled is true, resume() will not do
                    // anything and the mbox msg queue will not drain. This can cause us to
                    // hang in the shutdown path because we will never reach the quiesced
                    // state that we need to be in before initiating handleShutdown()
                    iv_disabled = true;         // stop incomming new messages

                    // Deal with messages never claimed by any HB component
                    handleUnclaimed();

                    // State:  MBOX is quiesced() and owns all the DMA buffers
                    // Action: handleShutdown() now
                    //
                    // State:  MBOX is quiesced(), but does not own all the DMA
                    //         buffers
                    // Action: Must send message to retrieve the buffers.
                    //
                    // State:  MBOX is still busy
                    // Action: Send message to retrieve the DMA buffers if one
                    //         is not pending, but may not get them all back
                    //         at this time.
                    //
                    if( !iv_dmaBuffer.ownsAllBlocks() &&
                        !iv_dma_pend &&
                        !isDmaReqBfrMsgOutstanding() )
                    {
                        sendReclaimDmaBfrsMsg();
                    }

                    if(quiesced()) //already in shutdown state
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
                    iv_suspend_intr = static_cast<bool>(msg->data[0]);
                    iv_allow_blk_resp = static_cast<bool>(msg->data[1]);

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

            case MSG_IPC: // Look for Interprocessor Messages
                {
                    if (msg->data[0] == INTR::SHUT_DOWN)
                    {
                        TRACFCOMP(g_trac_mbox, INFO_MRK
                          "Shutdown Message sent for IPC, ignoring.");
                    }
                    else
                    {
                        uint64_t msg_q_id = KernelIpc::ipc_data_area.msg_queue_id;
                        if(msg_q_id == IPC_DATA_AREA_LOCKED)
                        {
                            TRACFCOMP(g_trac_mbox, INFO_MRK
                                 "MBOXSP IPC data area locked");
                            // msg is being written, but not yet ready to handle
                            msg_q_id = IPC_DATA_AREA_CLEAR;
                        }
                        // desination message queue id is lower 32 bits
                        msg_q_id &= 0x00000000FFFFFFFFull;

                        if(IPC_DATA_AREA_CLEAR != msg_q_id)
                        {
                            // message is ready to handle
                            msg_t * ipc_msg = msg_allocate();
                            isync();
                            *ipc_msg = KernelIpc::ipc_data_area.msg_payload;
                            lwsync();
                            // Clear ipc area so another message can be sent
                            KernelIpc::ipc_data_area.msg_queue_id =
                                IPC_DATA_AREA_CLEAR;
                            handleIPC(static_cast<queue_id_t>(msg_q_id), ipc_msg);
                        }
                        else
                        {
                            TRACFCOMP(g_trac_mbox, ERR_MRK
                                "MBOXSP invalid data found in IPC data area: "
                                " %0xlx", msg_q_id);

                            TRACFBIN(g_trac_mbox, "IPC Data Area:",
                                  &KernelIpc::ipc_data_area,
                                  sizeof(KernelIpc::ipc_data_area));

                            /*@ errorlog tag
                             * @errortype       ERRL_SEV_PREDICTIVE
                             * @moduleid        MBOX::MOD_MBOXSRV_HNDLR
                             * @reasoncode      MBOX::RC_IPC_INVALID_DATA
                             * @userdata1       IPC Data Area MSG Queue ID
                             * @devdesc         IPC Message data corrupted
                             * @custdesc        An internal firmware error occurred
                             */
                            err = new ERRORLOG::ErrlEntry
                                (
                                 ERRORLOG::ERRL_SEV_PREDICTIVE,
                                 MBOX::MOD_MBOXSRV_HNDLR,
                                 MBOX::RC_IPC_INVALID_DATA,         // reason Code
                                 msg_q_id,                          // IPC Data
                                 0
                                );

                            err->collectTrace(MBOX_COMP_NAME, 256);
                            err->collectTrace(INTR_COMP_NAME, 256);

                            errlCommit(err,MBOX_COMP_ID);
                        }
                    }
                    INTR::sendEOI(iv_msgQ,msg);
                }

                break;

            case MSG_LOCAL_IPC:
                {
                    queue_id_t q_id = static_cast<queue_id_t>(msg->data[0]);
                    msg_t* ipc_msg = reinterpret_cast<msg_t*>(msg->extra_data);

                    handleIPC(q_id, ipc_msg);

                    msg_free(msg);
                }

                break;

            case MSG_MBOX_ALLOCATE:
                handleAllocate(msg);
                break;

            case MSG_MBOX_DEALLOCATE:
                {
                    void * ptr = reinterpret_cast<void*>(msg->data[0]);
                    deallocate(ptr);
                }
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
                 * @custdesc        An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_HNDLR,
                     MBOX::RC_INVALID_MBOX_MSG_TYPE,    //  reason Code
                     msg->type,                         // msg type
                     0,
                     true //Add HB Software Callout
                    );

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
#ifdef CONFIG_DROPPED_MSG_WARNING_AS_DEBUG
        TRACDCOMP(g_trac_mbox,WARN_MRK
                  "MSGSEND - mailboxsp is disabled. Message dropped!"
                  " msgQ=0x%x type=0x%x",
                  mbox_msg.msg_queue_id,
                  mbox_msg.msg_payload.type);
#else
        TRACFCOMP(g_trac_mbox,WARN_MRK
                  "MSGSEND - mailboxsp is disabled. Message dropped!"
                  " msgQ=0x%x type=0x%x",
                  mbox_msg.msg_queue_id,
                  mbox_msg.msg_payload.type);
#endif

        if(!i_msg_is_async) // synchronous
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_INFORMATIONAL
             * @moduleid        MOD_MBOXSRV_SENDMSG
             * @reasoncode      RC_MAILBOX_DISABLED
             * @userdata1       queue_id
             * @userdata2       message type
             * @devdesc         Mailbox is disabled, message dropped.
             * @custdesc        An internal firmware error occurred
             */
            errlHndl_t err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,
                 MBOX::MOD_MBOXSRV_SENDMSG,
                 MBOX::RC_MAILBOX_DISABLED,        //  reason Code
                 i_msg->data[0],                   // queue id
                 payload->type,                    // message type
                 true //Add HB Software Callout
                );

            i_msg->data[1] = reinterpret_cast<uint64_t>(err);

            payload->extra_data = NULL;

            msg_respond(iv_msgQ,i_msg);
        }

        if( mbox_msg.msg_payload.extra_data != NULL )
        {
            TRACDCOMP( g_trac_mbox, "free extra_data %p",
                        mbox_msg.msg_payload.extra_data );

            deallocate ( mbox_msg.msg_payload.extra_data );

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

        // NOTE:This message could still get sent if iv_suspended == true.
        // This could happen if a suspend action has been requested, but the
        // response to the suspend request has not yet been sent.
        // (that is, the iv_sendq has not had a chance to "drain" yet.)
        if(!iv_suspended)
        {
            send_msg(&mbox_msg);
        }
        else
        {
            recursive_mutex_lock(&iv_sendq_mutex);
            iv_sendq.push_back(mbox_msg);
            recursive_mutex_unlock(&iv_sendq_mutex);
            TRACFCOMP(g_trac_mbox,"I>Mailbox suspending or suspended.");
            trace_msg("QUEUED",mbox_msg);
        }
    }

}

// Note: When called due to an ACK or retry, iv_rts should be true.
void MailboxSp::send_msg(mbox_msg_t * i_msg)
{
    recursive_mutex_lock(&iv_sendq_mutex);
    if(i_msg)
    {
        iv_sendq.push_back(*i_msg);
    }

    // Can't send now if:
    //  - busy (waiting for ACK)
    //  - a DMA buffer request is pending
    //  - there is nothing to send
    //
    if(!iv_rts || iv_dma_pend || iv_sendq.size() == 0)
    {
        recursive_mutex_unlock(&iv_sendq_mutex);
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

                deallocate( payload->extra_data );
                payload->extra_data = NULL;
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

                TRACFCOMP(g_trac_mbox,
                          INFO_MRK
                          "MailboxSp::send_msg - "
                          "Send Reclaim Msg to FSP");

                // track the msg until completion
                //  actual msg send happens below
                __sync_fetch_and_add( &iv_reclaim_sent_cnt, 1 );
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
                     * @userdata2[00:31] message type
                     * @userdata2[32:63] queue_id
                     * @devdesc         Failed to allocate a DMA buffer.
                     *                  Message dropped.
                     * @custdesc        Internal firmware error during IPL
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_INFORMATIONAL,
                         MBOX::MOD_MBOXSRV_SENDMSG,
                         MBOX::RC_INVALID_DMA_LENGTH,      //  reason Code
                         dma_size,                         // DMA data len
                         TWO_UINT32_TO_UINT64(
                             iv_msg_to_send.msg_payload.type,
                             iv_msg_to_send.msg_queue_id),      // MSG queueid
                         true //Add HB Software Callout
                        );

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

        if(iv_msg_to_send.msg_queue_id == FSP_MAILBOX_MSGQ &&
           iv_msg_to_send.msg_payload.type == MSG_REQUEST_DMA_BUFFERS)
        {
            iv_dma_pend = true;
        }

        trace_msg("SEND",iv_msg_to_send);

        err = DeviceFW::deviceWrite(iv_trgt,
                                    &iv_msg_to_send,
                                    mbox_msg_len,
                                    DeviceFW::MAILBOX);

        // Create a watchdog task that will run for 60 seconds
        // if there is no response in 60 seconds then dbg info will
        // be printed in the slow trace buffer
        if(iv_msg_to_send.msg_payload.type == MSG_REQUEST_DMA_BUFFERS
            && !Util::isSimicsRunning()
            && !iv_dmaRequestWatchdog)
        {
            iv_dmaRequestWatchdog = task_create(&watchdogTimeoutTask, this);
            assert (iv_dmaRequestWatchdog > 0 );
        }
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
                // - for now just commit the error.
                //@TODO- RTC:93751 recovery options?
            }
            // else msg is a HB response to a FSP originating sync msg
            // What do we do here? Can't respond to the FSP.
            // For now just commit the error.
            //@TODO- RTC:93751 recovery options?
        }
        // else msg was HB originating async - Just commit it.

        if(err) // have error log and no where to respond to, so commit it.
        {
            errlCommit(err,MBOX_COMP_ID);
            err = NULL;
        }
    }

    recursive_mutex_unlock(&iv_sendq_mutex);
    return;
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
                    // for response
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
                     * @custdesc        An internal firmware error occurred
                     *
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         MBOX::MOD_MBOXSRV_RCV,
                         MBOX::RC_MSG_SEND_ERROR,   //  reason Code
                         rc,                        // rc from msg_send
                         i_mbox_msg.msg_queue_id,
                         true //Add HB Software Callout
                        );

                    //@todo: RTC:93750 Create real parseable FFDC class
                    err->addFFDC(MBOX_COMP_ID,
                                 msg,
                                 sizeof(msg_t),
                                 1,//version
                                 MBOX_UDT_MSG_DATA);//subsect
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
                 * @custdesc        An internal firmware error occurred
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_INFORMATIONAL,
                     MBOX::MOD_MBOXSRV_RCV,
                     MBOX::RC_INVALID_MESSAGE_TYPE  ,    //  reason Code
                     i_mbox_msg.msg_queue_id,            // rc from msg_send
                     msg->type,
                     true //Add HB Software Callout
                    );

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
                i_mbox_msg.msg_payload.extra_data = NULL;
            }
            msg_free(msg);
        }
        else // This is a bounce-back msg from the echo server - Ignore
        {
            free(msg->extra_data);
            msg->extra_data = NULL;
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
         * @custdesc        An internal firmware error occurred
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,
             MBOX::MOD_MBOXSRV_FSP_MSG,
             MBOX::RC_INVALID_QUEUE,
             bad_mbox_msg->msg_queue_id,
             bad_msg->type,
             true //Add HB Software Callout
            );

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
         * @custdesc        An internal firmware error occurred
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
    TRACFCOMP(g_trac_mbox,
              INFO_MRK
              "MailboxSp::handle_hbmbox_resp - "
              "Reclaim Msg response from FSP");

    //Response for more DMA buffers
    iv_dmaBuffer.addBuffers
        (i_mbox_msg.msg_payload.data[0]);

    // track response received
    __sync_fetch_and_add( &iv_reclaim_rsp_cnt, 1);

    iv_dma_pend = false;

    send_msg(); // send next message, if there is one
}

/**
 * Send message to mailbox service to send a remote message
 */
errlHndl_t MailboxSp::send(queue_id_t i_q_id,
                           msg_t * io_msg,
                           msgq_msg_t i_mbox_msg_type)
{
    errlHndl_t err = NULL;
    int rc = 0;

    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);

    msg_t* msg = msg_allocate();
    msg->type = i_mbox_msg_type;
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
             * @custdesc        An internal firmware error occurred
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,   //  severity
                 MBOX::MOD_MBOXSRV_SEND,                 //  moduleid
                 MBOX::RC_INVALID_QUEUE,                 //  reason Code
                 rc,                                     //  msg_sendrecv errno
                 i_q_id,                                 //  msg queue id
                 true //Add HB Software Callout
                );

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
         * @custdesc        An internal firmware error occurred
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
             MBOX::MOD_MBOXSRV_SEND,                 //  moduleid
             MBOX::RC_MBOX_SERVICE_NOT_READY,        //  reason Code
             i_q_id,                                 //  queue id
             0,                                      //
             true //Add HB Software Callout
            );

        msg_free(msg);
    }

    return err;
}

/**
 * Reclaim any DMA buffers owned by the FSP
 */
errlHndl_t MailboxSp::reclaimDmaBfrsFromFsp( void )
{
    errlHndl_t err = NULL;

    // locate the FSP mailbox
    MailboxSp & fspMbox = Singleton<MailboxSp>::instance();

    // reclaim the dma bfrs
    err = fspMbox._reclaimDmaBfrsFromFsp();

    return( err );
}

errlHndl_t MailboxSp::_reclaimDmaBfrsFromFsp( void )
{
    errlHndl_t err = NULL;
    int msgSentCnt = 0;
    int maxDmaBfrs = iv_dmaBuffer.maxDmaBfrs();

    TRACFBIN(g_trac_mbox,
             INFO_MRK
             "MailboxSp::_reclaimDmaBfrsFromFsp - Start."
             " DmaBuffer = ",
             &iv_dmaBuffer,
             sizeof(iv_dmaBuffer) );

    while // bfrs still need to be reclaimed
        ( iv_dmaBuffer.ownsAllBlocks() == false )
    {
        if // request dma bfrs msg is outstanding
          ( isDmaReqBfrMsgOutstanding() == true )
        {
            // (wait for msg to complete)
            nanosleep( 0, 1000000 );  // 1ms to avoid tight busy loop
            task_yield();
        }

        else if // can send another request dma bfrs msg
          (msgSentCnt < maxDmaBfrs)
        {
            // send the message
            msgSentCnt++;
            sendReclaimDmaBfrsMsg();
        }

        else
        {
            // (sent max number of reclaims and bfrs still not free)
            // (something real bad is happening, exit so we don't hang)

            // create a snapshot of DMA buffer control object for tracing
            char dmyArray[sizeof(iv_dmaBuffer)];
            memcpy( &dmyArray[0],
                    (void *)&iv_dmaBuffer,
                    sizeof(dmyArray) );

            TRACFBIN(g_trac_mbox,
                     ERR_MRK
                     "MailboxSp::_reclaimDmaBfrsFromFsp -"
                     "Reclaim Did Not Complete. "
                     "DmaBuffer = ",
                     &dmyArray[0],
                     sizeof(dmyArray) );

            break;
        }
    } // end wait for bfrs to be reclaimed

    return( err );
}


void MailboxSp::sendReclaimDmaBfrsMsg( void )
{
    // allocate local msg bfr on the stack
    mbox_msg_t local_msg_bfr;

    sendReclaimDmaBfrsMsg( local_msg_bfr );

    return;
}


void MailboxSp::sendReclaimDmaBfrsMsg( mbox_msg_t & i_mbox_msg )
{
    // isolate all occurrences of this message to this routine
    //  so the total number of outstanding Request DMA Bfr
    //  messages can be tracked in one place.   This allows
    //  a mechanism to determine if any of these messages are
    //  on either the message Q or have been sent on HW to FSP.
    // iv_dma_pend only tracks the msg from load on HW to
    //  response received.  Does not consider Queue.
    TRACFCOMP(g_trac_mbox,
              INFO_MRK
              "MailboxSp::sendReclaimDmaBfrsMsg - "
              "Send Reclaim Msg to FSP");

    // send a request dma bfrs msg to reclaim from fsp
    new (&i_mbox_msg) mbox_msg_t();

    i_mbox_msg.msg_queue_id = FSP_MAILBOX_MSGQ;
    i_mbox_msg.msg_payload.type = MSG_REQUEST_DMA_BUFFERS;
    i_mbox_msg.msg_payload.__reserved__async = 1;

    // track the msg until completion;
    __sync_fetch_and_add( &iv_reclaim_sent_cnt, 1 );

    send_msg(&i_mbox_msg);

    return;
}

void * MailboxSp::watchdogTimeoutTask(void * i_mailboxSp)
{
    // We don't want this to be a zombie because parent keeps going
    task_detach();

    // create a task which we can wait, this way we can print
    // an error message if the taskWorker crashes
    tid_t l_tid = task_create( &watchdogTimeoutTaskWorker, i_mailboxSp);
    assert (l_tid > 0 );

    int   l_status = 0;
    void* l_rc     = nullptr;

    tid_t l_tidRc = task_wait_tid(l_tid, &l_status, &l_rc);

    if(l_status == TASK_STATUS_CRASHED)
    {
        TRACFCOMP(g_trac_mbox,
                  ERR_MRK
                  "MailboxSp::watchdogTimeoutTask - "
                  "Watchdog timeout crashed!! %lx", l_tidRc);
    }

    return nullptr;
}

void * MailboxSp::watchdogTimeoutTaskWorker(void * i_mailboxSp)
{

    uint64_t MAX_TIMEOUT = 200000000000;  // nanoseconds
    uint64_t POLL_RATE   = 1000000;       // nanoseconds
    uint64_t cur_timeout = 0;             // nanoseconds
    errlHndl_t err = nullptr;

    assert(i_mailboxSp != nullptr, "nullptr was passed to watchdogTimeoutTaskWorker");

    MailboxSp & mboxSp = *static_cast<MailboxSp *>(i_mailboxSp);

    while(cur_timeout < MAX_TIMEOUT)
    {
        if( !mboxSp.iv_dma_pend )
        {
            TRACFCOMP(g_trac_mbox,
                      INFO_MRK
                      "Breaking out of watchdog because FSP responded to DMA request");
            break;
        }
        // sleep for 1 ms
        nanosleep(0, POLL_RATE);
        cur_timeout += POLL_RATE;
    }

    if(cur_timeout >= MAX_TIMEOUT)
    {
        TRACFCOMP(g_trac_mbox,
                  INFO_MRK
                  "Hang during DMA request detected, dumping state information");
        err = dumpMboxRegs();
        if(err)
        {
            TRACFCOMP(g_trac_mbox,
                      INFO_MRK
                      "Error occured while dumping MBOX information");
                      err->collectTrace(MBOX_COMP_NAME);
                      errlCommit(err,MBOX_COMP_ID);
        }
        err = INTR::printInterruptInfo();
        if(err)
        {
            TRACFCOMP(g_trac_mbox,
                      INFO_MRK
                      "Error occured while dumping INTR information");
                      err->collectTrace(INTR_COMP_NAME);
                      errlCommit(err,MBOX_COMP_ID);
        }
    }

    //Zero out the TID so another watchdog task can be created if needed
    mboxSp.iv_dmaRequestWatchdog = 0;
    return nullptr;

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
             * @custdesc        An internal firmware error occurred
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
                 MBOX::MOD_MBOXREGISTER,              // moduleid
                 MBOX::RC_ALREADY_REGISTERED,         // reason code
                 i_queue_id,
                 0,
                 true //Add HB Software Callout
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
                 * @custdesc        An internal firmware error occurred
                 *
                 */
                err = new ERRORLOG::ErrlEntry
                    (
                     ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                     MBOX::MOD_MBOXSRV_HNDLR,
                     MBOX::RC_DATA_WRITE_ERR,  //  reason Code
                     mbox_status,              //  Status from DD
                     0,
                     true //Add HB Software Callout
                    );

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
                 * @custdesc        An internal firmware error occurred
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
                 * @custdesc        An internal firmware error occurred
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

bool MailboxSp::quiesced()
{
    bool result = iv_rts && !iv_dma_pend && iv_sendq.empty();

    TRACDCOMP(g_trac_mbox,INFO_MRK"Checking quiesced.. rts[%d] dma_pend[%d] sendq[%d]",
              iv_rts, iv_dma_pend, iv_sendq.empty());


    if( result == true )
    {
        TRACFCOMP(g_trac_mbox,INFO_MRK"quiesced == true, iv_shutdown_msg[%p]",
                  iv_shutdown_msg);
        if(iv_shutdown_msg == NULL ||
           (iv_shutdown_msg->data[1] == SHUTDOWN_STATUS_GOOD))
        {
            //Check that respond q is empty OR don't care
            result = result && (iv_respondq.empty() || iv_allow_blk_resp);
        }
        else // mbox is shutting down and system status is bad
        {
            // Wait for HB to FSP sync message to complete.
            // Don't wait for FSP to HB sync message to complete
            msg_respond_t * resp = iv_respondq.begin();
            while(resp)
            {
                if( resp->msg_queue_id >= MBOX::FSP_FIRST_MSGQ)
                {
                    // stil have pending HB->FSP sync messages
                    result = false;
                    break;
                }
                resp = resp->next;
            }
            // if result is still true then remaining responds, if any,
            // should be ignored - mbox is quiesced.
            if(result)
            {
                while(!iv_respondq.empty())
                {
                    resp = iv_respondq.begin();
                    iv_respondq.erase(resp);
                    delete resp;
                }
            }
        }
    }

    TRACFCOMP(g_trac_mbox,INFO_MRK"Quiesced [%d]", result);

    return result;
}

void MailboxSp::handleIPC(queue_id_t i_msg_q_id, msg_t * i_msg)
{

    TRACFCOMP(g_trac_mboxmsg,
              "MBOXSP IPC RECV MSG: msg_id:0x%08x",
              (uint32_t)i_msg_q_id);
    TRACFCOMP(g_trac_mboxmsg,
              "MBOXSP IPC RECV MSG: 0x%08x 0x%016lx 0x%016lx %p",
              i_msg->type,
              i_msg->data[0],
              i_msg->data[1],
              i_msg->extra_data);

    registry_t::iterator r =
        iv_registry.find(static_cast<queue_id_t>(i_msg_q_id));
    if(r != iv_registry.end())
    {
        // found queue
        msg_q_t msgq = r->second;

        // Only async message supported right now
        // Interface already enforces this.
        int rc = msg_send(msgq,i_msg);

        if(rc)
        {
            /*@ errorlog tag
             * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
             * @moduleid        MBOX::MOD_MBOXSRV_IPC_MSG
             * @reasoncode      MBOX::RC_MSG_SEND_ERROR
             * @userdata1       rc from msg_send()
             * @userdata2       msg queue id
             * @devdesc         Invalid msg or msg queue
             * @custdesc        An internal firmware error occurred
             *
             */
            errlHndl_t err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                 MBOX::MOD_MBOXSRV_IPC_MSG,
                 MBOX::RC_MSG_SEND_ERROR,   //  reason Code
                 rc,                        // rc from msg_send
                 i_msg_q_id,
                 true //Add HB Software Callout
                );

            UserDetailsMboxMsg
                ffdc(reinterpret_cast<uint64_t*>(i_msg),
                     sizeof(msg_t));

            ffdc.addToLog(err);

            err->collectTrace(MBOXMSG_TRACE_NAME);
            errlCommit(err,MBOX_COMP_ID);

            msg_free(i_msg);
        }
    }
    else // not registered
    {
        // thow it away log error
        TRACFCOMP(g_trac_mbox,
                  ERR_MRK
                  "MailboxSp::handleIPC: Unregistered msg queue id 0x%x"
                  " message dropped.",
                  i_msg_q_id);

        /*@ errorlog tag
         * @errortype       ERRL_SEV_INFORMATIONAL
         * @moduleid        MOD_MBOXSRV_IPC_MSG
         * @reasoncode      RC_INVALID_QUEUE
         * @userdata1       msg queue
         * @userdata2       msg type
         * @devdesc         Invalid message queue ID
         * @custdesc        An internal firmware error occurred
         */
        errlHndl_t err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,
             MBOX::MOD_MBOXSRV_IPC_MSG,
             MBOX::RC_INVALID_QUEUE,
             i_msg_q_id,
             i_msg->type,
             true //Add HB Software Callout
            );

        UserDetailsMboxMsg
            ffdc(reinterpret_cast<uint64_t*>(i_msg), sizeof(msg_t));

        ffdc.addToLog(err);
        err->collectTrace(MBOXMSG_TRACE_NAME);
        errlCommit(err,MBOX_COMP_ID);

        msg_free(i_msg);
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
     * @custdesc        An internal firmware error occurred
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
    iv_dmaBuffer.clrShutdownDmaRequestSentCnt();
    errlHndl_t err = mboxddShutDown(iv_trgt);

#if (0) // @todo RTC:126643
    INTR::unRegisterMsgQ(INTR::LSI_FSIMBOX);
#endif

    INTR::unRegisterMsgQ(INTR::ISN_INTERPROC);

    if(err)  // SCOM failed.
    {
        // If this failed, the whole system is probably buggered up.

        errlCommit(err,MBOX_COMP_ID);

        TRACFCOMP(g_trac_mbox,
                  ERR_MRK"MBOXSP Shutdown. HALTED on critical error!");
        crit_assert(0);
    }

    if(iv_pend_alloc.size() || iv_allocAddrs.size() || iv_sum_alloc)
    {
        TRACFCOMP(g_trac_mbox,WARN_MRK
                  "Pending memory allocations = %d "
                  "Allocated memory entrys = %d "
                  "Allocated memory size = %d",
                  iv_pend_alloc.size(),
                  iv_allocAddrs.size(),
                  iv_sum_alloc);
    }

    msg_respond(iv_msgQ,iv_shutdown_msg);
    TRACFCOMP(g_trac_mbox,INFO_MRK"Mailbox is shutdown");
}

void MailboxSp::suspend()
{
    TRACFCOMP(g_trac_mbox,INFO_MRK"Entering suspended");
    if(iv_suspend_intr)
    {
        errlHndl_t err = mboxddMaskInterrupts(iv_trgt);
        if(err)  // SCOM failed.
        {
            // If this failed, the whole system is probably buggered up.
            errlCommit(err,MBOX_COMP_ID);
            TRACFCOMP(g_trac_mbox,
                      ERR_MRK"MBOXSP suspend HALTED on critical error!");
            crit_assert(0);
        }
    }
    msg_respond(iv_msgQ,iv_suspend_msg);
    TRACFCOMP(g_trac_mbox,INFO_MRK"Mailbox is suspended");
}

void MailboxSp::resume()
{
    iv_suspended = false;
    iv_allow_blk_resp = false;

    if(!iv_disabled)
    {
        //If interrupts were disabled, re-enable
        if(iv_suspend_intr)
        {
            errlHndl_t err = mboxddEnableInterrupts(iv_trgt);
            if(err)  // SCOM failed.
            {
                // If this failed, the whole system is probably buggered up.
                errlCommit(err,MBOX_COMP_ID);
                TRACFCOMP(g_trac_mbox,
                          ERR_MRK"MBOXSP resume HALTED on critical error!");
                crit_assert(0);
            }
            iv_suspend_intr = false;
        }

        send_msg();   // send next message on queue
    }
}

void MailboxSp::handleAllocate(msg_t * i_msg)
{
    uint64_t size = i_msg->data[0];
    msg_t * msg = i_msg;

    // Try to allocate storage
    // If success then respond to message now else respond to message later
    if((iv_sum_alloc + size) < MAX_ALLOCATION)
    {
        uint64_t address = reinterpret_cast<uint64_t>(malloc(size));
        iv_sum_alloc += size;
        iv_allocAddrs.push_back(addr_size_t(address,size));
        msg->data[1] = address;
        msg_respond(iv_msgQ,msg);
    }
    else // save request on pending queue & block task by not responding
    {
        iv_pend_alloc.push_back(msg);
    }
}

void MailboxSp::deallocate(void * i_ptr)
{
    // if MBOX owns this then adjust iv_sum_alloc and
    // remove addr from iv_allocAddrs
    addr_list_t::iterator itr = iv_allocAddrs.begin();
    for(; itr != iv_allocAddrs.end(); ++itr)
    {
        if(itr->first == reinterpret_cast<uint64_t>(i_ptr))
        {
            break;
        }
    }

    free(i_ptr);

    if(itr != iv_allocAddrs.end())
    {
        iv_sum_alloc -= itr->second;
        iv_allocAddrs.erase(itr);

        // check to see if next allocation(s) can be met
        while(iv_pend_alloc.size() != 0)
        {
            msg_t * msg = iv_pend_alloc.front();
            uint64_t size = msg->data[0];
            if((iv_sum_alloc + size) < MAX_ALLOCATION)
            {
                uint64_t address = reinterpret_cast<uint64_t>(malloc(size));
                iv_sum_alloc += size;
                iv_allocAddrs.push_back(addr_size_t(address,size));
                msg->data[1] = address;
                msg_respond(iv_msgQ,msg);
                iv_pend_alloc.pop_front();
            }
            else
            {
                // stop on first allocation that can't be met
                // Must keep messages in order
                break;
            }
        }
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
        err = MailboxSp::send(i_q_id, i_msg,MBOX::MSG_SEND);
    }
    else // IPC msg
    {
        if(i_node < MSGQ_TYPE_IPC)
        {
            uint64_t q_handle = i_q_id;
            q_handle |= (((uint64_t)MSGQ_TYPE_IPC | (uint64_t)i_node) << 32);

            TRACFCOMP(g_trac_mboxmsg,INFO_MRK
                      "MBOXSP IPC SEND MSG: Dest node %d. msg_id: %lx",
                      i_node,
                      (uint32_t)i_q_id);

            TRACFCOMP(g_trac_mboxmsg,INFO_MRK
                      "MBOXSP IPC SEND MSG: 0x%08x 0x%016lx 0x%016lx %p",
                      i_msg->type,
                      i_msg->data[0],
                      i_msg->data[1],
                      i_msg->extra_data);

            // node means Hb instance number in this context
            PIR_t my_pir (KernelIpc::ipc_data_area.pir);
            if ((static_cast<int>(PIR_t::nodeOrdinalFromPir(my_pir.word)) == i_node)
                && (MBOX::HB_TEST_MSGQ != i_q_id)) //use IPC for tests
            {
                // Message is to this node - don't use IPC path
                // MBOX sp can look up msgQ
                err = MailboxSp::send(i_q_id, i_msg,MBOX::MSG_LOCAL_IPC);
            }
            else
            {
                // stitch together routing if not already done
                IPC::IpcSp::acquireRemoteNodeAddrs();

                int rc = msg_send(reinterpret_cast<msg_q_t>(q_handle),
                                  i_msg);
                TRACFCOMP(g_trac_mboxmsg,INFO_MRK
                          "MBOXSP IPC SENT. This PIR 0x%x, rc=%d",
                          KernelIpc::ipc_data_area.pir, rc);


                if(rc)
                {
                    /*@ errorlog tag
                     * @errortype       ERRL_SEV_CRITICAL_SYS_TERM
                     * @moduleid        MBOX::MOD_MBOX_SEND
                     * @reasoncode      MBOX::RC_INVALID_QUEUE
                     * @userdata1       returncode from msg_send()
                     * @userdata2       q_handle
                     *
                     * @devdesc         Error sending IPC message
                     * @custdesc        A problem occurred during the IPL
                     *                  of the system
                     *
                     */
                    err = new ERRORLOG::ErrlEntry
                        (
                         ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,  //  severity
                         MBOX::MOD_MBOX_SEND,              //  moduleid
                         MBOX::RC_INVALID_QUEUE,           // reason Code
                         rc,                               // rc from msg_send
                         q_handle,                         //  msg queue id
                         true //Add HB Software Callout
                        );

                    // This Trace has the msg
                    err->collectTrace(MBOXMSG_TRACE_NAME);

                    ERRORLOG::ErrlUserDetailsPrintk().addToLog(err);
                }
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
             * @custdesc        An internal firmware error occurred
             *
             */
            err = new ERRORLOG::ErrlEntry
                (
                 ERRORLOG::ERRL_SEV_INFORMATIONAL,       //  severity
                 MBOX::MOD_MBOX_SEND,                    //  moduleid
                 MBOX::RC_IPC_INVALID_NODE,              //  reason Code
                 i_q_id,                                 //  queue id
                 i_node,                                 //
                 true //Add HB Software Callout
                );

        }
    }
    return err;
}

// ---------------------------------------------------------------------------

errlHndl_t MBOX::sendrecv(queue_id_t i_q_id, msg_t * io_msg)
{
    io_msg->__reserved__async = 1;
    return MailboxSp::send(i_q_id, io_msg, MBOX::MSG_SEND);
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
         * @custdesc        An internal firmware error occurred
         *
         */
        err = new ERRORLOG::ErrlEntry
            (
             ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
             MBOX::MOD_MBOXREGISTER,              // moduleid
             MBOX::RC_MBOX_SERVICE_NOT_READY,     // reason code
             i_queue_id,
             0,
             true //Add HB Software Callout
            );

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

errlHndl_t MBOX::suspend(bool i_disable_hw_int, bool i_allow_resp)
{
    errlHndl_t err = NULL;
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_MBOX_SUSPEND;
        msg->data[0] = static_cast<uint64_t>(i_disable_hw_int);
        msg->data[1] = static_cast<uint64_t>(i_allow_resp);

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
     * @custdesc        A problem occurred during the IPL of the system
     *
     */
    errlHndl_t err = new ERRORLOG::ErrlEntry
        (
         ERRORLOG::ERRL_SEV_INFORMATIONAL,    // severity
             MBOX::MOD_MBOX_MSGQ_FAIL,            // moduleid
             MBOX::RC_MSG_SEND_ERROR,             // reason code
             i_errno,
             0,
             true //Add HB Software Callout
            );

        return err;
}

// ----------------------------------------------------------------------------

void * MBOX::allocate(size_t i_size)
{
    void * response = NULL;

    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_MBOX_ALLOCATE;
        msg->data[0] = i_size;

        int rc = msg_sendrecv(mboxQ, msg);

        if (rc)
        {
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::allocate msg_sendrecv() failed. errno = %d",
                      rc);
            // Creating error log would cause recursion on this function.
            // Leave response NULL and get memory from the heap.
        }
        else
        {
            response = reinterpret_cast<void *>(msg->data[1]);
        }

        msg_free(msg);
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"MBOX::allocate - "
                  "Mailbox Service not available");
    }

    if(NULL == response)
    {
        response = malloc(i_size);
    }

    return response;
}

void MBOX::deallocate(void * i_ptr)
{
    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        msg_t * msg = msg_allocate();
        msg->type = MSG_MBOX_DEALLOCATE;
        msg->data[0] = reinterpret_cast<uint64_t>(i_ptr);

        int rc = msg_sendrecv(mboxQ, msg);
        if(rc)
        {
            // kernel problem, Creating error log could cause recursion on
            // this function - just free memory from heap
            TRACFCOMP(g_trac_mbox, ERR_MRK
                      "MBOX::deallocate msg_sendrecv() failed. errno = %d",
                      rc);
            free(i_ptr);
        }
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"MBOX::deallocate - "
                  "Mailbox Service not available");
        free(i_ptr);
    }
}

errlHndl_t MBOX::reclaimDmaBfrsFromFsp( void )
{
    errlHndl_t err = NULL;

    msg_q_t mboxQ = msg_q_resolve(VFS_ROOT_MSG_MBOX);
    if(mboxQ)
    {
        // reclaim the dma bfrs
        err = MailboxSp::reclaimDmaBfrsFromFsp();
    }
    else
    {
        TRACFCOMP(g_trac_mbox, ERR_MRK"MBOX::reclaimDmaBfrsFromFsp - "
                  "Mailbox Service not available");
    }

    return( err );
}
