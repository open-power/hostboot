//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/mbox/mbox_reasoncodes.H $
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
    };

    enum MBOXReasonCode
    {
        RC_INVALID_LENGTH            = MBOX_COMP_ID | 0x01,
        RC_INVALID_MESSAGE_TYPE      = MBOX_COMP_ID | 0x02,
        RC_NO_PERM_TO_SEND           = MBOX_COMP_ID | 0x03,
        RC_MSG_PENDING               = MBOX_COMP_ID | 0x04,
    };
};

#endif
