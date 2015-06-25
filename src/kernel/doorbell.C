/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/doorbell.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <kernel/cpumgr.H>

void doorbell_clear()
{
    register uint64_t msgtype = 0x0000000028000000; /// Comes from the ISA.
    asm volatile("msgclr %0" :: "r" (msgtype));

    return;
}

void doorbell_broadcast()
{
    size_t threadCount = CpuManager::getThreadCount();

    uint64_t msgtype = 0x0000000028000000;  /// Comes from the ISA.
    uint64_t thread = getPIR() & (threadCount - 1);
    for (size_t i = 0; i < threadCount; ++i)
    {
        if (i != thread)
        {
            register uint64_t msg = msgtype | i;
            asm volatile("msgsnd %0" :: "r" (msg));
        }
    }
}
