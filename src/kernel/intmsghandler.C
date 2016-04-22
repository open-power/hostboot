/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/intmsghandler.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2016                        */
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
        printk("InterruptMsgHdlr got called before IPC was setup\n");
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

        //If this is an IPI -- clean it up
        //TODO RTC 137564
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
        uint64_t pir_key = i_pir | 0x4000000000000000ul;

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
        uint64_t pir_key = i_pir | 0x8000000000000000ul;

        cv_instance->iv_lock.lock();
        cv_instance->sendMessage(MSG_INTR_CPU_WAKEUP,
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
