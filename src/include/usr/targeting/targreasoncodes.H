//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/targeting/targreasoncodes.H $
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
#ifndef __TARGETING_TARGREASONCODES_H
#define __TARGETING_TARGREASONCODES_H

#include <hbotcompid.H>

namespace TARGETING
{
    enum TargetingModuleId
    {
        TARG_MOD_TEST           = 0x01,
        TARG_MOD_ATTRRP         = 0x02,
    };

    enum TargetingReasonCode
    {
        TARG_RC_TEST_TARGET_FFDC        = TARG_COMP_ID | 0x01,
        TARG_RC_BAD_EYECATCH            = TARG_COMP_ID | 0x02,
        TARG_RC_MM_BLOCK_FAIL           = TARG_COMP_ID | 0x03,
        TARG_RC_MM_PERM_FAIL            = TARG_COMP_ID | 0x04,
        TARG_RC_ATTR_MSG_FAIL           = TARG_COMP_ID | 0x05,
    };
};

#endif
