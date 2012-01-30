//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/xscom/scomreasoncodes.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
//
//  p1
//
//  Object Code Only (OCO) source materials
// Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __SCOM_REASONCODES_H
#define __SCOM_REASONCODES_H

#include <hbotcompid.H>

namespace SCOM
{
    enum scomModuleId
    {
        SCOM_PERFORM_OP            = 0x00,
        SCOM_TRANSLATE             = 0x01,
        SCOM_PERFORM_TRANSLATE     = 0x02,
        SCOM_FIND_PARENT_TARGET    = 0x03,

    };

    enum scomReasonCode
    {
        SCOM_INVALID_ADDR           = SCOM_COMP_ID | 0x01,
        SCOM_NO_MATCHING_PARENT     = SCOM_COMP_ID | 0x02,
        SCOM_TRANS_INVALID_TYPE     = SCOM_COMP_ID | 0x03,
        SCOM_TRANS_UNSUPPORTED      = SCOM_COMP_ID | 0x04,
    };
};

#endif
