//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/errl/errlreasoncodes.H $
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
#ifndef __ERRL_REASON_CODES_H
#define __ERRL_REASON_CODES_H

/**
 *  @file errlreasoncodes.H
 *
 *  @brief  Reason code and Module ID definitions for ERRL component.
 *
 */

#include <hbotcompid.H>

// Module IDs for ERRL component
enum
{
    ERRL_FIRST_MODULE_ID        = 0x00,
    //........
    ERRL_LAST_MODULE_ID         = 0xFF
};

// Reason codes for ERRL component
enum errlReasonCode
{
    ERRL_FIRST_ERR          = ERRL_COMP_ID | 0x01,
    //........
    ERRL_LAST_ERR           = ERRL_COMP_ID | 0xFF
};


#endif
