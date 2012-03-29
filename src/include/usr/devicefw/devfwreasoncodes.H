//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/devicefw/devfwreasoncodes.H $
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
#ifndef __DEVICEFW_DEVFWREASONCODES_H
#define __DEVICEFW_DEVFWREASONCODES_H

#include <hbotcompid.H>

namespace DeviceFW
{
    enum DevFwModuleId
    {
        DEVFW_MOD_ASSOCIATOR    = 0x01,
    };

    enum DevFwReasonCode
    {
        DEVFW_RC_INVALID_REGISTRATION   = DEVFW_COMP_ID | 0x01,
        DEVFW_RC_NO_ROUTE_FOUND         = DEVFW_COMP_ID | 0x02,
        DEVFW_RC_NULL_TARGET            = DEVFW_COMP_ID | 0x03,
        DEVFW_RC_DOUBLE_REGISTRATION    = DEVFW_COMP_ID | 0x04,
    };
};

#endif
