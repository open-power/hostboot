//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/kernel/blockmsghdlr.H $
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
/** @file blockmsghdlr.H
 *  @brief Defines the implementation for a block's handling of messages.
 */
#ifndef __KERNEL_BLOCKMSGHDLR_H
#define __KERNEL_BLOCKMSGHDLR_H

#include <stdint.h>
#include <kernel/types.h>
#include <kernel/msghandler.H>

//Forward declaration.
class Spinlock;
class MessageQueue;
class Block;

/**
 * @class BlockMsgHdlr
 * @brief Class to handle message data for blocks
 *
 * This class extends from the base MessageHandler so the base send/receive
 * message functions can be utilized. It overrides how to handle the message
 * responses for blocks within the base virtual memory segment.
 */
class BlockMsgHdlr : public MessageHandler
{
    public:

        /**
         * @brief Constructor
         *
         * @param[in] i_lock - Subsystem lock for this message handler, passed
         *                     directly onto the MessageHandler
         * @param[in] i_msgq - Queue used to send messages into userspace,
         *                     passed directly onto the MessageHandler
         * @param[in] i_block - Block to associate this message handler to
         */
        BlockMsgHdlr(Spinlock* i_lock, MessageQueue* i_msgq, Block* i_block) :
                     MessageHandler(i_lock,i_msgq), iv_block(i_block) {};

        /**
         * @brief Destructor
         */
        ~BlockMsgHdlr() {};

        /**
         * @brief Handle response to 'send message' associated with this block
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

    private:

        /* Associated block for this message handler */
        Block* const iv_block;
};

#endif
