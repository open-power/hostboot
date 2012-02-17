//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/mbox/mboxif.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __MBOX_MBOXIF_H
#define __MBOX_MBOXIF_H

namespace MBOX
{
    static const uint32_t MBOX_MAX_DATA_BYTES = 64; //16 32-bit Data Registers

    enum MboxReadStatus {
        MBOX_ABORT_LAST_MSG  = 0x00000040, /* Cancel Timed Out Operation */
        MBOX_DOORBELL_ERROR  = 0x00000010, /* Error Set In Error Register */
        MBOX_XDN_ACK         = 0x00000004, /* LBUS Data Acknowledgment */
        MBOX_DATA_PENDING    = 0x00000001, /* PIB Data Pending */
        MBOX_ILLEGAL_OP      = 0x08000000, /* Illegal Operation Attempted */
        MBOX_DATA_WRITE_ERR  = 0x04000000, /* Write Full LBUS Mailbox Error */
        MBOX_DATA_READ_ERR   = 0x02000000, /* Read Empty LBUS Mailbox Error */
        MBOX_PARITY_ERR      = 0x01000000, /* LBUS RAM Parity Error Detected */
    };
};
#endif
