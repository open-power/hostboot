//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/kernel/intmsghandler.C $
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

#include <kernel/intmsghandler.H>
#include <sys/msg.h>
#include <util/singleton.H>
#include <kernel/console.H>
#include <sys/interrupt.h>
#include <util/lockfree/atomic_construct.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/scheduler.H>

const char* INTR_MSGQ = "/msg/interrupt";

InterruptMsgHdlr * InterruptMsgHdlr::cv_instance = NULL;


void InterruptMsgHdlr::create(MessageQueue * i_msgQ)
{
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
    // Save the current task in case we context-switch away when sending
    // the message.
    task_t* t = TaskManager::getCurrentTask();

    // TODO will this always be processor 0 core 0 thread 0?
    // Need a way to pass this addr down from user code?
    uint64_t xirrAddress = (static_cast<uint64_t>(ICPBAR_VAL) << 20) + 4;

    // Ignore HRMOR setting
    xirrAddress |= 0x8000000000000000ul;

    uint32_t xirr = 0;
    printkd ("XirrAddr %lx\n",xirrAddress);

    // Reading this register acknowledges the interrupt and deactivates the
    // external interrupt signal to the processor. The XIRR is now locked
    // and can't be pre-empted by a "more favored" interrupt.
    // This is a cache-inhibited load from hypervisor state.
    // lwzcix      BOP1,Ref_G0,BOP2
    asm volatile("lwzcix %0, 0, %1"
                 : "=r" (xirr)           // output, %0
                 : "r" (xirrAddress)     // input,  %1
                 : );                    // no impacts

    if(cv_instance)
    {
        cv_instance->sendMessage(MSG_INTR_EXTERN,
                                 (void *)xirr,
                                 NULL,
                                 NULL);
    }

    // else we got an external interrupt before we got things set up.
    // TODO Is there anything that can be done other than
    // leave the interrupt presenter locked.
    // Does the code that sets up the IP registers need to check to see if
    // there is an interrupt sitting there and send an EOI?

    // Return the task to the scheduler queue if we did a context-switch.
    if (TaskManager::getCurrentTask() != t)
    {
        t->cpu->scheduler->addTask(t);
    }
}


void InterruptMsgHdlr::addCpuCore(uint64_t i_pir)
{
    // Save the current task in case we context-switch away when sending
    // the message.
    task_t* t = TaskManager::getCurrentTask();

    if(cv_instance)
    {
        cv_instance->sendMessage(MSG_INTR_ADD_CPU,(void *)i_pir,NULL,NULL);
    }

    // Return the task to the scheduler queue if we did a context-switch.
    if (TaskManager::getCurrentTask() != t)
    {
        t->cpu->scheduler->addTask(t);
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
    return UNHANDLED_RC;
}

