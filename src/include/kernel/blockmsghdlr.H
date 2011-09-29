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
#include <util/locked/list.H>

//Forward declaration.
class Spinlock;
class MessageQueue;
class Block;

struct TaskMsgNode
{
    //Next pointer for list.
    TaskMsgNode* next;
    //Previous pointer for list.
    TaskMsgNode* prev;

    task_t* key;
    uint64_t msgCount;
};

struct PageAddrNode
{
    //Next pointer for list.
    PageAddrNode* next;
    //Previous pointer for list.
    PageAddrNode* prev;

    void* key;
    uint64_t pageAddr;
};

/**
 * @class BlockReadMsgHdlr
 * @brief Class to handle read messages for blocks
 *
 * This class extends from the base MessageHandler so the base send/receive
 * message functions can be utilized. It overrides how to handle the message
 * responses for blocks within the base virtual memory segment.
 */
class BlockReadMsgHdlr : public MessageHandler
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
        BlockReadMsgHdlr(Spinlock* i_lock,MessageQueue* i_msgq,
                         Block* i_block) :
                         MessageHandler(i_lock,i_msgq), iv_block(i_block) {};

        /**
         * @brief Destructor
         */
        ~BlockReadMsgHdlr() {};

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

/**
 * @class BlockWriteMsgHdlr
 * @brief Class to handle write messages for blocks
 *
 * This class extends from the base MessageHandler so the base send/receive
 * message functions can be utilized. It overrides how to handle the message
 * responses for blocks within the base virtual memory segment.
 */
class BlockWriteMsgHdlr : public MessageHandler
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
        BlockWriteMsgHdlr(Spinlock* i_lock,MessageQueue* i_msgq,
                          Block* i_block) :
                          MessageHandler(i_lock,i_msgq), iv_block(i_block) {};

        /**
         * @brief Destructor
         */
        ~BlockWriteMsgHdlr() {};

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

        /**
         * @brief Increments the number of messages sent from the given task
         * @param[in] i_task - Associated task to message sent
         */
        void incMsgCount(task_t* i_task);

        /**
         * @brief Adds the virtual address to page address association for
         * page removal upon response
         * @param[in] i_vaddr - Virtual address sent on message
         * @param[in] i_pgAddr - Page address to be removed
         */
        void addVirtAddr(void* i_vaddr,uint64_t i_pgAddr);

    private:

        /* Associated block for this message handler */
        Block* const iv_block;
        /* List of associated tasks to number of messages */
        Util::Locked::List<TaskMsgNode, task_t*> iv_msgGrpList;
        /* List of associated virtual address to page address */
        Util::Locked::List<PageAddrNode, void*> iv_va2paList;
};

#endif
