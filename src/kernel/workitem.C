/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/workitem.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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

#include <arch/ppc.H>
#include <kernel/workitem.H>
#include <kernel/console.H>
#include <kernel/intmsghandler.H>
#include <kernel/cpumgr.H>

//Define the desired behavior for a CPU core/thread
// wakeup scenario
void CpuWakeupDoorbellWorkItem::operator() (void)
{
    size_t pir = getPIR();
    printkd("Wkup pir %ld done\n", pir);
    //Send message to the intrrp in userspace indicating this pir has woken up
    // There is a task associated with the intrrp that monitors that the proper
    // cores/threads have woken up
    InterruptMsgHdlr::sendThreadWakeupMsg(pir);
    return;
}

void CpuTbRestoreDoorbellWorkItem::operator() (void)
{
    size_t pir = getPIR();
    cpu_t *l_cpu = CpuManager::getCpu(pir);

    uint64_t l_restore_tb = l_cpu->cpu_restore_tb;
    printkd("pir:%lu tb:0x%0lX\n", pir, l_restore_tb);
    if (l_restore_tb > getTB())
    {
        setTB(l_restore_tb);
    }
    return;
}
