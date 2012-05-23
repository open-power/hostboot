/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwas/common/hwas_reasoncodes.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2011-2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
#ifndef HWAS_REASONCODES_H
#define HWAS_REASONCODES_H

#include <hbotcompid.H>

namespace HWAS
{
    enum HwasModuleID
    {
        MOD_DECONFIG_GARD    = 0x01,
    };

    enum HwasReasonCode
    {
        RC_TARGET_NOT_DECONFIGURABLE        = HWAS_COMP_ID | 0x01,
        RC_TARGET_NOT_GARDABLE              = HWAS_COMP_ID | 0x02,
        RC_GARD_REPOSITORY_FULL             = HWAS_COMP_ID | 0x03,
        RC_TARGET_NOT_FOUND_FOR_GARD_RECORD = HWAS_COMP_ID | 0x04,
    };
};

#endif
