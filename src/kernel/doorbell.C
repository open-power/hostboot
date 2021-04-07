/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/doorbell.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
#include <stdint.h>
#include <arch/ppc.H>
#include <kernel/task.H>
#include <kernel/taskmgr.H>
#include <kernel/cpu.H>
#include <kernel/doorbell.H>
#include <kernel/console.H>
#include <kernel/cpumgr.H>
#include <kernel/intmsghandler.H>
#include <config.h>
#include <util/misc.H>

void doorbell_clear()
{
    register uint64_t msgtype = _DOORBELL_MSG_TYPE;
    asm volatile("msgclr %0" :: "r" (msgtype));

    return;
}

void doorbell_broadcast()
{
    /*TODO RTC 152189
    size_t threadCount = CpuManager::getThreadCount();

    uint64_t msgtype = _DOORBELL_MSG_TYPE;
    uint64_t thread = getPIR() & (threadCount - 1);
    for (size_t i = 0; i < threadCount; ++i)
    {
        if (i != thread)
        {
            register uint64_t msg = msgtype | i;
            asm volatile("msgsnd %0" :: "r" (msg));
        }
    }
    **/
}

void doorbell_send(uint64_t i_pir)
{
    uint64_t msgtype = _DOORBELL_MSG_TYPE;
    register uint64_t msg = msgtype | i_pir;
    asm volatile("msgsnd %0" :: "r" (msg));

    return;
}

void send_doorbell_wakeup(uint64_t i_pir)
{
    // This printk shows up a lot and can cause important debug information to be lost later in the IPL if it's longer
    // than absolutely necessary.
    printk("sDBW:%lu\n", i_pir);

    if(Util::requiresSecondaryCoreWorkaround())
    {
        // We never get a real wakeup interrupt so just lie
        InterruptMsgHdlr::sendThreadWakeupMsg(i_pir);
    }
    else
    {
        //Create WorkItem and put on the stack to be executed during doorbell
        // execution
        KernelWorkItem* l_work = new CpuWakeupDoorbellWorkItem();
        cpu_t *l_cpu = CpuManager::getCpu(i_pir);
        l_cpu->doorbell_actions.push(l_work);
    }

    //Put a barrier here to prevent a possible weak consistency
    // issue with the l_work memory getting consumed incorrectly
    // by the new thread that wakes up
    sync();
    //Send doorbell to wakeup core/thread
    doorbell_send(i_pir);
}

void send_doorbell_restore_tb(uint64_t i_pir, uint64_t i_tb)
{
    cpu_t *l_cpu = CpuManager::getCpu(i_pir);
    l_cpu->cpu_restore_tb = i_tb;

    printkd("send_doorbell_restore_tb to pir: %lx\n", i_pir);

    //Create WorkItem and put on the stack to be executed during doorbell
    // execution
    KernelWorkItem* l_work = new CpuTbRestoreDoorbellWorkItem();
    l_cpu->doorbell_actions.push(l_work);
    //Put a barrier here to prevent a possible weak consistency
    // issue with the l_work memory getting consumed incorrectly
    // by the new thread that wakes up
    sync();
    //Send doorbell to wakeup core/thread
    doorbell_send(i_pir);
}

void send_doorbell_ipc(uint64_t i_pir)
{
    printk("send_doorbell_ipc to pir: %lx\n", i_pir);
    doorbell_send(i_pir);
}
