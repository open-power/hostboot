/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/kernel/spinlock.C $                                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2010,2014              */
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
#include <kernel/spinlock.H>
#include <arch/ppc.H>

void Spinlock::lock()
{
    uint64_t reservation = __sync_fetch_and_add(&iv_reserve, 1);
    if (iv_ready != reservation)
    {
	do
	{
	    setThreadPriorityLow();
	}
	while(iv_ready != reservation);
	setThreadPriorityHigh();
    }
    isync();
}

void Spinlock::unlock()
{
    __sync_add_and_fetch(&iv_ready, 1);
}
