/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/ipc.H $                                    */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
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
