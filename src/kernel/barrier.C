/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/barrier.C $                                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#include <kernel/barrier.H>
#include <arch/ppc.H>

void Barrier::wait()
{
    iv_spinlock.lock();
    --iv_missing;
    if(iv_missing > 0)
    {
        size_t l_event = iv_event;
        iv_spinlock.unlock();
        while(iv_event == l_event) { setThreadPriorityLow(); }
    }
    else
    {
        iv_missing = iv_count;
        ++iv_event;
        iv_spinlock.unlock();
    }
    setThreadPriorityHigh();
}
