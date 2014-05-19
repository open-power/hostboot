/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/machchk.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
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
#ifndef __KERNEL_MACHCHK_H
#define __KERNEL_MACHCHK_H

#include <stdint.h>
#include <kernel/task.H>

namespace Kernel
{
    namespace MachineCheck
    {
        /** Handles memory UE machine checks.
         *
         *  @param[in] t - Task which took the machine check.
         *  @return bool - True if MC successfully handled, false otherwise.
         */
        bool handleLoadUE(task_t* t);

        /** Handle SLB parity and multi-hit error machine checks.
         *
         *  @param[in] t - Task which took the machine check.
         *  @return bool - True if MC successfully handled, false otherwise.
         */
        bool handleSLB(task_t* t);
    }
}

#endif
