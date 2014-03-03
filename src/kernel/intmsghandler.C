/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/intmsghandler.C $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
            cv_instance->iv_lock.lock();

            //sendMessage needs a unique key, otherwise it
            //drops messages.  PIR is not unique enough, make
            //it (xirr<<32) | PIR
            uint64_t l_data0 = pir | (static_cast<uint64_t>(xirr) <<32);
            cv_instance->sendMessage(MSG_INTR_EXTERN,
                                     reinterpret_cast<void*>(l_data0),
                                     NULL,
                                     NULL);
            cv_instance->iv_lock.unlock();
        }
    }
    else
    {
        printk("InterrurptMsgHdlr got called before IPC was setup\n");

        // The INTR mmio base address is not yet available via the attributes.
        // If we get here during an MPIPL then the BAR value could be read
        // from the ICP BAR SCOM register, however, since this value will
        // never change unless PHYP changes its memory map, it is deemed
        // sufficient to hard code the value.  If this is not an MPIPL then
        // there is a serious problem elsewhere.

        cv_ipc_base_address = (uint64_t)(INTP_BAR_VALUE) << 32; // val in BAR
        cv_ipc_base_address >>= 14;                 // convert to base address

        uint64_t xirrAddress =
            cv_ipc_base_address + mmio_offset(pir) + XIRR_ADDR_OFFSET;

        // Ignore HRMOR setting
        xirrAddress |= 0x8000000000000000ul;

        uint32_t xirr = 0;

        asm volatile("lwzcix %0, 0, %1"
                     : "=r" (xirr)
                     : "r" (xirrAddress)
                     : );

        // There should not be any more interrupts until an eoi is sent
        // by writing the xirr back with the value read.

        printk("XIRR @ %lx = %x\n",xirrAddress,xirr);

        //If this is an IPI -- clean it up
        if((xirr & 0x00FFFFFF) == INTERPROC_XISR)
        {
            uint64_t mfrrAddress =
              cv_ipc_base_address + mmio_offset(pir) + MFRR_ADDR_OFFSET;

            // Ignore HRMOR setting
            mfrrAddress |= 0x8000000000000000ul;
            uint8_t mfrr = 0xFF;

            asm volatile("stbcix %0,0,%1" :: "r" (mfrr) , "r" (mfrrAddress));
            asm volatile("stwcix %0,0,%1" :: "r" (xirr) , "r" (xirrAddress));
        }
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

        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_ADD_CPU,
                                 (void*)pir_key,(void *)i_pir,t);
        cv_instance->iv_lock.unlock();
    }
}

void InterruptMsgHdlr::sendIPI(uint64_t i_pir, uint8_t i_favor)
{
    uint64_t mfrrAddress = cv_ipc_base_address;
    mfrrAddress += mmio_offset(i_pir);
    mfrrAddress += MFRR_ADDR_OFFSET;

    mfrrAddress |= 0x8000000000000000ul;

    register uint8_t data = i_favor;

    eieio(); sync();
    MAGIC_INSTRUCTION(MAGIC_SIMICS_CORESTATESAVE);
    asm volatile("stbcix %0,0,%1" :: "r" (data) , "r" (mfrrAddress));
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
