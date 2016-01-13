/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/workitem.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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

#ifndef __KERNEL_WORKITEM_H
#define __KERNEL_WORKITEM_H

//The WorkItem class is a generic base class for a work item.
class KernelWorkItem
{
    public:
        //Virtual operator to be defined by child classes to define proper
        // behavior in that situation
        virtual void operator() (void);

        /** Default destructor */
        virtual ~KernelWorkItem() = default;

        //Next Pointer is needed to be used with the lockfree::Stack container
        KernelWorkItem* next;
};

//A work item to be created/executed during a CPU core/thread
// wakeup scenario
class CpuWakeupDoorbellWorkItem : public KernelWorkItem
{
    public:
        //Implement operator() function
        void operator() (void);

        //No data to clean up, use default destructor
        ~CpuWakeupDoorbellWorkItem() = default;
};


/* TODO RTC 150861

//A work item to be created/executed during an IPC scenario
class IPCDoorbellWorkItem : public KernelWorkItem
{
    public:
        //Implement operator() function
        void operator() (void);
};
**/
#endif

