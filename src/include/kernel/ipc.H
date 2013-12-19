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

extern ipc_data_area_t ipc_data_area;
};

#endif
