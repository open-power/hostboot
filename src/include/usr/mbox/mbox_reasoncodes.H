/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mbox_reasoncodes.H $                     */
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
#ifndef __MBOX_REASONCODES_H
#define __MBOX_REASONCODES_H

#include <hbotcompid.H>

namespace MBOX
{
    enum MBOXModuleId
    {
        MOD_MBOXDD_INVALID      = 0x00, /**< Zero is an invalid module id */
        MOD_MBOXDD_READ         = 0x01,
        MOD_MBOXDD_WRITE        = 0x02,
        MOD_MBOXSRV_SEND        = 0x03, // MailboxSp::send
        MOD_MBOXSRV_HNDLR       = 0x04, // MailboxSp::msgHandler
        MOD_MBOXSRV_RCV         = 0x05, // MailboxSp::recv_msg
        MOD_MBOXREGISTER        = 0x06, // MailboxSp::msgq_register
        MOD_MBOXSRV_FSP_MSG     = 0x07, // MailboxSp::handle_hbmbox_msg
        MOD_MBOXSRV_SENDMSG     = 0x08, // MailboxSp::send_msg
        MOD_MBOXSRV_INIT        = 0x09, // MailboxSp::_init
        MOD_MBOXSRC_UNCLAIMED   = 0x0A, // MailboxSp::handleUnclaimed
    };

    enum MBOXReasonCode
    {
        RC_INVALID_LENGTH            = MBOX_COMP_ID | 0x01,
        RC_INVALID_MESSAGE_TYPE      = MBOX_COMP_ID | 0x02,
        RC_NO_PERM_TO_SEND           = MBOX_COMP_ID | 0x03,
        RC_MSG_PENDING               = MBOX_COMP_ID | 0x04,
        RC_INVALID_QUEUE             = MBOX_COMP_ID | 0x05,
        RC_RETRY_FAILED              = MBOX_COMP_ID | 0x06,
        RC_ALREADY_REGISTERED        = MBOX_COMP_ID | 0x07,
        RC_UNREGISTERED_MSG_QUEUE    = MBOX_COMP_ID | 0x08,
        RC_ILLEGAL_OP                = MBOX_COMP_ID | 0x09,
        RC_DATA_WRITE_ERR            = MBOX_COMP_ID | 0x0A,
        RC_PARITY_ERR                = MBOX_COMP_ID | 0x0B,
        RC_INVALID_MBOX_MSG_TYPE     = MBOX_COMP_ID | 0x0C,
        RC_MBOX_SERVICE_NOT_READY    = MBOX_COMP_ID | 0x0D,
        RC_INVALID_DMA_LENGTH        = MBOX_COMP_ID | 0x0E,
        RC_KERNEL_REG_FAILED         = MBOX_COMP_ID | 0x0F,
        RC_MAILBOX_DISABLED          = MBOX_COMP_ID | 0x10,
    };


    /**
     * Defins for MBOX error og user detail data sections
     */
    enum mboxUserDetailDataSubsection
    {
        MBOX_UDT_MBOXMSG_DATA = 0x01,
    };

};
#endif
