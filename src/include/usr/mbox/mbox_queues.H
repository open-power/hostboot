/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mbox_queues.H $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
#ifndef __MBOX_QUEUES_H
#define __MBOX_QUEUES_H

/**
 * @file mbox_queues.H
 * @brief Mailbox queue identifiers. This file is shared between
 *        Hostboot and FSP.
 */

namespace MBOX
{
    /**
     * message queue IDs
     * FSP msg_queue range      0x80000000 - 0xFFFFFFFF
     * Hostboot msg_queue range 0x00000001 - 0x7FFFFFFF
     */
    enum queue_id_t
    {
        NOT_FOUND               = 0,
        HB_MAILBOX_MSGQ         = 1,
        // Add HB services here:
        HB_ISTEP_MSGQ           = 2,
        HB_ATTR_SYNC_MSGQ       = 3,
        HB_ERROR_MSGQ           = 4,
        //                        5,  // Reserved for VID
        HB_HWPF_ATTR_MSGQ       = 6, // HWPF Attribute override/sync
        HB_TRACE_MSGQ           = 7,
        HB_LID_MSGQ             = 8, //For transferring LIDs from FSP.
        HB_TEST_MSGQ            = 0x7FFFFFFF,

        // FSP mailboxes
        FSP_FIRST_MSGQ          = 0x80000000,
        FSP_MAILBOX_MSGQ        = 0x80000001,
        // Add FSP services here:
        FSP_TRACE_MSGQ          = 0x80000002,
        FSP_PROGRESS_CODES_MSGQ = 0x80000003,
        FSP_ERROR_MSGQ          = 0x80000004,
        FSP_VDDR_MSGQ           = 0x80000005,
        IPL_SERVICE_QUEUE       = 0x80000008, 
        FSP_ATTR_SYNC_MSGQ      = 0x80000009,
        FSP_DUMP_MSGQ_ID        = 0x8000000A,
        FSP_HWPF_ATTR_MSGQ      = 0x8000000B, // HWPF Attribute override/sync
        FSP_VPD_MSGQ            = 0x8000000C,
        FSP_LID_MSGQ            = FSP_ATTR_SYNC_MSGQ,


        FSP_ECHO_MSGQ = 0xFFFFFFFF,     // Fake FSP for test
    };

    // Message types are only unique with in each message queue. Each message queue can
    // use the entire range limited only by the restrictions listed below.
    //
    // Each HB and FSP service will need it's own list of message types
    // Not sure where they belong.
    //
    // types 0x00000000 - 0x3FFFFFFF are considered secure messages
    // and are disabled when under SecureBoot environment
    // types 0x40000000 - 0x7FFFFFFF can be done at anytime
    // types 0x80000000 - 0xFFFFFFFF are reserved on hostboot for kernel services
    // This means hostboot services can't use them, but this is not a restriction
    // on FSP services
    enum
    {
        FIRST_SECURE_MSG        = 0,
        LAST_SECURE_MSG         = 0x3FFFFFFF,
        FIRST_UNSECURE_MSG      = 0x40000000,
        LAST_UNSECURE_MSG       = 0x7FFFFFFF,
        FIRST_HB_KERNEL_MSG     = 0x80000000,
        LAST_KERNEL_MSG         = 0xFFFFFFFF
    };

    /**
     * MBOX to MBOX service message types.
     */
    enum msg_type_t
    {
        MSG_INVALID_MSG_QUEUE_ID = FIRST_UNSECURE_MSG + 1,
        MSG_INVALID_MSG_TYPE,
        MSG_REQUEST_DMA_BUFFERS,
        MSG_INITIAL_DMA,
    };


};

#endif

