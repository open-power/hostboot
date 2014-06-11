/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mbox/mbox_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
        MOD_MBOX_SEND           = 0x0B, // MBOX::send
        MOD_MBOXSRV_IPC_MSG     = 0x0C, // MailboxSp::handleIPC
        MOD_MBOX_MSGQ_FAIL      = 0x0D, // MBOX::makeErrlMsgQSendFail
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
        RC_IPC_INVALID_NODE          = MBOX_COMP_ID | 0x11,
        RC_MSG_SEND_ERROR            = MBOX_COMP_ID | 0x12,
    };


    /**
     * Defins for MBOX error og user detail data sections
     */
    enum mboxUserDetailDataSubsection
    {
        MBOX_UDT_MBOXMSG_DATA = 0x01,
        MBOX_UDT_MSG_DATA     = 0x02, //@todo: RTC:93750
    };

};
#endif
