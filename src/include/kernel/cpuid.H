/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/cpuid.H $                                  */
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
#ifndef __KERNEL_CPUID_H
#define __KERNEL_CPUID_H

#include <stdint.h>
#include <arch/ppc.H>
#include <sys/misc.h>

namespace CpuID
{
    /** @fn getCpuType()
     *  @brief Decode the processor type from the PVR register.
     *
     *  These values come from the pervasive spec for each processor.
     *
     *  @return ProcessorCoreType - Value from enumeration for this core.
     */
    ProcessorCoreType getCpuType();

    /** @fn getCpuDD
     *  @brief Decode the processor DD level from the PVR register.
     *
     *  These offsets come from the pervasive spec for each processor.
     *
     *  @return 1 byte DD level as <major nibble, minor nibble>.
     */
    uint8_t getCpuDD();
};
#endif
