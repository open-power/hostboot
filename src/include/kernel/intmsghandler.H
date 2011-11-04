//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/intmsghandler.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __KERNEL_INTERRUPTMSGHDLR_H
#define __KERNEL_INTERRUPTMSGHDLR_H

#include <stdint.h>
#include <kernel/types.h>
#include <kernel/msghandler.H>
#include <kernel/msg.H>

/**
 * @class InterruptMsgHdlr
 * @brief Class to handle sending a message to user space for
 *        an External Interrupt.
 *
 * This class extends from the base MessageHandler so the base send/receive
 * message functions can be utilized. It overrides how to handle the message
 * responses
 */
class InterruptMsgHdlr : public MessageHandler
{
    public:

        // Notes:
        //   All external interrupts are routed to one cpu core
        //   External Interrupts are only processed one at a time
        //   So we don't need a spinlock
        /**
         * Constructor
         */
        InterruptMsgHdlr(MessageQueue * i_msgQ)
            : MessageHandler(NULL,i_msgQ) {} // TODO need splinlock?

        /** 
         * Destructor.
         */
        virtual ~InterruptMsgHdlr() {};

        /**
         * Handle response to 'send message'
         *
         *  @param[in] i_type - The message type previously sent.
         *  @param[in] i_key - The key value for the received message.
         *  @param[in] i_task - The deferred task.
         *  @param[in] i_rc - The response rc from userspace.
         *
         *  @return HandleResult - The desired behavior on the 'recv message'
         *                         interface for this <key, task> pair.
         */
        virtual HandleResult handleResponse(msg_sys_types_t i_type,void* i_key,
                                            task_t* i_task,int i_rc);


        /**
         * Create the InterruptMsgHdlr to handle external interrupts
         * @param[in] i_msgQ The message queue
         */
        static void create(MessageQueue * i_msgQ);

        /**
         * Handle an external interrupt from HW
         */
        static void handleInterrupt();

        /**
         * Add cpu core - set up the external interrupt registers
         * @param[in] i_pir The cpu id of the core to to set-up
         * @note should be called when ever a new core becomes active
         */
        static void addCpuCore(uint64_t i_pir);

    private:

        static InterruptMsgHdlr * cv_instance;
};


#endif

