/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/intmsghandler.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2012              */
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

const char* VFS_ROOT_MSG_INTR = "/msg/interrupt";

InterruptMsgHdlr * InterruptMsgHdlr::cv_instance = NULL;
uint64_t InterruptMsgHdlr::cv_ipc_base_address = 0;

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
        uint64_t xirrAddress = cv_ipc_base_address; 

        xirrAddress += mmio_offset(pir); // Add offset for this cpu
        xirrAddress += XIRR_ADDR_OFFSET; // Add offset for XIRR register

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
                                     (void *)pir,
                                     (void *)xirr,
                                     NULL);
        }
    }

    if(cv_ipc_base_address == 0 || cv_instance == NULL)
    {
        static bool hit = false;

        // print the message once
        if(!hit)
        {
            printk("InterrurptMsgHdlr got called before IPC was setup\n");
            hit = true;
        }


        // else we got an external interrupt before we got things set up.
        // TODO Is there anything that can be done other than
        // leave the interrupt presenter locked.
        // Does the code that sets up the IP registers need to check to see if
        // there is an interrupt sitting there and send an EOI?
        // Story 41868 -  Mask off all interrupts very early - might
        // resolve this TODO.
    }

}

void InterruptMsgHdlr::addCpuCore(uint64_t i_pir)
{
    task_t* t = TaskManager::getCurrentTask();

    if(cv_instance)
    {
        // To avoid conflict with interrupts on thread i_pir, change the key
        // for the message to be an invalid PIR.
        uint64_t pir_key = i_pir | 0x8000000000000000ul;

        cv_instance->sendMessage(MSG_INTR_ADD_CPU,
                                 (void*)pir_key,(void *)i_pir,t);
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

