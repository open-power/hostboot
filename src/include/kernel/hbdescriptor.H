/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/hbdescriptor.H $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

/** @file hbdescriptor.H
 *  @brief Defines hostboot data area
 */

#ifndef __KERNEL_HBDESCRIPTOR_H
#define __KERNEL_HBDESCRIPTOR_H

#include <stdint.h>

struct HB_TI_DataArea;

namespace KernelIpc { struct ipc_data_area_t; };

struct HB_Descriptor
{
     HB_TI_DataArea *TI_DataAreaPtr;  // ptr to the TI data area structure
     KernelIpc::ipc_data_area_t *IPC_DataAreaPtr; // ptr to the IPC data area
     uint64_t kernelMemoryState;
};

#endif /* __KERNEL_HBDESCRIPTOR_H */
