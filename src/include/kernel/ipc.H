/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/ipc.H $                                    */
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
#if !defined(__IPC_H)
#define __IPC_H

#include <sys/msg.h>

#define IPC_DATA_AREA_LOCKED 0xFFFFFFFFFFFFFFFFul
#define IPC_DATA_AREA_READ   0xFFFFFFFFFFFFFFFEul
#define IPC_DATA_AREA_CLEAR  0

namespace KernelIpc
{
struct ipc_data_area_t
{
    uint64_t msg_queue_id;
    msg_t    msg_payload;
    uint64_t hrmor_base;
    uint32_t pir;
};

/**
 * This stucture maps an IPC data area needed by start_payload that is common
 * to all HB instances.
 * @note  Don't change the order or size of this stucture
 * w/o also changing src/kernel/shutdown.S
 */
struct start_payload_data_area_t
{
    /** barriers needed in shutdown.S - see src/kernel/shutdown.S
     *  barrier[0] blocks until all nodes have reported cpu/node_count
     *  barrier[1] blocks until safe to update HRMOR on master
     *  barrier[2] blocks until HRMORs updated
     *  barrier[3] blocks until SLBs, ERATs etc. cleared
     *  barrier[4] blocks until all CPUs have jumpted to payload except the
     *             one with the lowest PIR
     */
    uint64_t barrier[5];
    uint64_t lowest_PIR;    //!< Lowest cpu PIR in entire system (all nodes)
    uint64_t cpu_count;     //!< Total number of cpu threads in entire system
    uint64_t node_count;    //!< Total number of nodes in entire system
};


extern ipc_data_area_t ipc_data_area;
extern start_payload_data_area_t start_payload_data_area;
};

#endif
