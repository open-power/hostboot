/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/intmsghandler.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2019                        */
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
#include <kernel/intmsghandler.H>
#include <sys/msg.h>
#include <util/singleton.H>
#include <kernel/console.H>
#include <util/lockfree/atomic_construct.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>
#include <arch/ppc.H>
#include <assert.h>

const char* VFS_ROOT_MSG_INTR = "/msg/interrupt";

InterruptMsgHdlr * InterruptMsgHdlr::cv_instance = NULL;
uint64_t InterruptMsgHdlr::cv_ipc_base_address = 0;
uint64_t InterruptMsgHdlr::cv_ipc_salt = 0;

void InterruptMsgHdlr::create(MessageQueue * i_msgQ, uint64_t i_ipc_addr)
{
    cv_ipc_base_address = i_ipc_addr;
    if(cv_instance)
    {
        // TODO should this be considered an unrecoverable error?
        // i_msgQ has already been changed by the syscall, so we either have to
        // make a new InterrupMsgHdlr object to match the new queue or we halt
        // the system.
        printk("WARNING replacing existing Interrupt handler!\n");

        InterruptMsgHdlr* instance = cv_instance;
        while(instance != NULL)
        {
            if(__sync_bool_compare_and_swap(&cv_instance, instance, NULL))
            {
                delete instance;
            }
            instance = cv_instance;
        }
    }

    // Atomically construct.
    if (__sync_bool_compare_and_swap(&cv_instance, NULL, NULL))
    {
        InterruptMsgHdlr* instance = new InterruptMsgHdlr(i_msgQ);
        if (!__sync_bool_compare_and_swap(&cv_instance, NULL, instance))
        {
            delete instance;
        }
    }
}


void InterruptMsgHdlr::handleInterrupt()
{
    uint64_t pir = getPIR();

    if( cv_ipc_base_address != 0 )
    {
        uint64_t ackHypeInt2RegAddress = cv_ipc_base_address;
        ackHypeInt2RegAddress += ACK_HYPERVISOR_INT_REG_OFFSET;

        // Ignore HRMOR setting
        ackHypeInt2RegAddress |= 0x8000000000000000ul;
        uint16_t ackHypeInt2Reg = 0;

        // Reading this register acknowledges the interrupt and deactivates the
        // external interrupt signal to the processor. The XIRR is now locked
        // and can't be pre-empted by a "more favored" interrupt.
        // This is a cache-inhibited load from hypervisor state.
        // lhzcix      BOP1,Ref_G0,BOP2
        asm volatile("lhzcix %0, 0, %1"
                     : "=r" (ackHypeInt2Reg)           // output, %0
                     : "r" (ackHypeInt2RegAddress)     // input,  %1
                     : );                              // no impacts

        if(cv_instance)
        {
            cv_instance->iv_lock.lock();

            //sendMessage needs a unique key, otherwise it
            //drops messages.  PIR is not unique enough, make
            //it (ackHypInt2Reg<<32) | PIR
            uint64_t l_data0 =
                             pir | (static_cast<uint64_t>(ackHypeInt2Reg) <<32);
            cv_instance->sendMessage(MSG_INTR_EXTERN,
                                     reinterpret_cast<void*>(l_data0),
                                     NULL,
                                     NULL);
            cv_instance->iv_lock.unlock();
        }
    }
    else
    {
        // This block had P8 legacy code that should never run on P9/P10.
        // Still, placing an assert here just in case we ever do get here.
        printk("InterruptMsgHdlr got called before IPC was setup");
        kassert(false);
    }
}

void InterruptMsgHdlr::sendMessage(msg_sys_types_t i_type, void* i_key,
                                 void* i_data, task_t* i_task)
{
    // Task to switch to due to waiter being ready to handle message.
    task_t* ready_task = nullptr;

    // Save pending info for when we get the response.
    MessageHandler_Pending* mhp = new MessageHandler_Pending();
    mhp->key = i_key;
    mhp->task = i_task;

    // Update block status for task.
    if (nullptr != i_task)
    {
        i_task->state = TASK_STATE_BLOCK_USRSPACE;
        i_task->state_info = i_key;
    }

    // Send userspace message if one hasn't been sent for this key.
    if (!iv_pending.find(i_key))
    {
        // Create message.
        msg_t* m = new msg_t();
        m->type = i_type;
        m->data[0] = reinterpret_cast<uint64_t>(i_key);
        m->data[1] = reinterpret_cast<uint64_t>(i_data);
        m->extra_data = nullptr;
        m->__reserved__async = 1;

        // Create pending response object.
        MessagePending* mp = new MessagePending();
        mp->key = m;
        mp->task = reinterpret_cast<task_t*>(this);

        // Send to userspace...
        iv_msgq->lock.lock();
        task_t* waiter = iv_msgq->waiting.remove();
        if (nullptr == waiter) // No waiting task, queue for msg_wait call.
        {
            iv_msgq->messages.insert(mp);
        }
        else // Waiting task, set msg as return and release.
        {
            TASK_SETRTN(waiter, (uint64_t) m);
            iv_msgq->responses.insert(mp);
            ready_task = waiter;
        }
        iv_msgq->lock.unlock();
    }

    // Defer task while waiting for message response.
    if (nullptr != i_task)
    {
        if (i_task == TaskManager::getCurrentTask())
        {
            // Switch to ready waiter, or pick a new task off the scheduler.
            if (ready_task)
            {
                TaskManager::setCurrentTask(ready_task);
                ready_task = nullptr;
            }
            else
            {
                // Select next task off scheduler.
                i_task->cpu->scheduler->setNextRunnable();
            }
        }
    }

    // Add ready waiter to the task queue
    if (nullptr != ready_task)
    {
        task_t* current = TaskManager::getCurrentTask();
        current->cpu->scheduler->addTask(ready_task);
        ready_task = nullptr;
    }

    // Insert pending info into our queue until response is recv'd.
    iv_pending.insert(mhp);
}


void InterruptMsgHdlr::addCpuCore(uint64_t i_pir)
{
    task_t* t = TaskManager::getCurrentTask();

    if(cv_instance)
    {
        // To avoid conflict with interrupts on thread i_pir, change the key
        // for the message to be an invalid PIR.
        uint64_t pir_key = i_pir | MSG_KEY_ADD_CPU_CORE;

        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_ADD_CPU,
                                 (void*)pir_key,(void *)i_pir,t);
        cv_instance->iv_lock.unlock();
    }
}

void InterruptMsgHdlr::sendThreadWakeupMsg(uint64_t i_pir)
{
    if(cv_instance)
    {
        // To avoid conflict with interrupts on thread i_pir, change the key
        // for the message to be an invalid PIR.
        uint64_t pir_key = i_pir | MSG_KEY_THREAD_WKUP;

        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_CPU_WAKEUP,
                                 (void*)pir_key,(void *)i_pir,NULL);
        cv_instance->iv_lock.unlock();
    }
}

void InterruptMsgHdlr::sendIpcMsg(uint64_t i_pir)
{
    if(cv_instance)
    {
        //Note that due to how IPC works between independent HB
        //Instances, their is a race between when the  data area
        //"lock" is released and when  the doorbell handled response
        //is sent back to the kernel. Basically the other instances
        //pounce on the data area as soon as it is unlocked, and
        //a duplicate doorbell happens before kernel clears first
        //message.
        //Since the kernel will drop any message with the same PIR
        //key on the floor, need to make it unique with an incrementing
        //counter

        cv_ipc_salt += MSG_IPC_SALT;
        uint64_t pir_key = i_pir | MSG_KEY_IPC_MSG | cv_ipc_salt;

        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_IPC,
                                (void*)pir_key,(void *)i_pir,NULL);
        cv_instance->iv_lock.unlock();
    }
}

MessageHandler::HandleResult InterruptMsgHdlr::handleResponse
(
 msg_sys_types_t i_type,
 void* i_key,
 task_t* i_task,
 int i_rc
 )
{
    if (MSG_INTR_ADD_CPU == i_type)
    {
        TASK_SETRTN(i_task, i_rc);
        return SUCCESS;
    }
    return UNHANDLED_RC;
}


void InterruptMsgHdlr::issueSbeMboxWA()
{
    if(cv_instance)
    {
        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_ISSUE_SBE_MBOX_WA,
                     reinterpret_cast<void*>(MSG_INTR_ISSUE_SBE_MBOX_WA),
                     NULL,NULL);
        cv_instance->iv_lock.unlock();
    }
}
