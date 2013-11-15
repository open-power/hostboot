/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/ipc_msg_types.H $                        */
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
#if !defined(__IPC_MSG_TYPES_H)
#define __IPC_MSG_TYPES_H

#include <mbox/mbox_queues.H>

namespace IPC
{
    /**
     * IPC message types
     */
    enum ipc_msg_type_t
    {
        IPC_POPULATE_ATTRIBUTES = MBOX::FIRST_SECURE_MSG + 1,
        IPC_TEST_CONNECTION = MBOX::FIRST_SECURE_MSG + 2,
        IPC_START_PAYLOAD,
    };

}; // namespace IPC
#endif
