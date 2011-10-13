//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/fsiscom/fsiscom_reasoncodes.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
#ifndef __FSISCOM_REASONCODES_H
#define __FSISCOM_REASONCODES_H

#include <hbotcompid.H>

namespace FSISCOM
{
    enum FSISCOMModuleId
    {
        MOD_FSISCOM_INVALID           = 0x00, /**< Zero is an invalid module id */
        MOD_FSISCOM_PERFORMOP         = 0x01, /**< fsiscom.C : fsiScomPerformOp */

    };

    enum FSISCOMReasonCode
    {
        RC_INVALID                   = FSISCOM_COMP_ID | 0x00, 
        RC_WRITE_ERROR               = FSISCOM_COMP_ID | 0x01, 
        RC_READ_ERROR                = FSISCOM_COMP_ID | 0x02,
        RC_INVALID_LENGTH            = FSISCOM_COMP_ID | 0x03,
        RC_INVALID_ADDRESS           = FSISCOM_COMP_ID | 0x04,
        RC_INVALID_OPTYPE            = FSISCOM_COMP_ID | 0x05,
    };
};

#endif
