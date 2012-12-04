/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas_reasoncodes.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2013              */
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
#ifndef HWAS_REASONCODES_H
#define HWAS_REASONCODES_H

namespace HWAS
{
    enum HwasModuleID
    {
        MOD_DECONFIG_GARD         = 0x01,
        MOD_PROCESS_CALLOUT       = 0x02,
        MOD_HOST_DISCOVER_TARGETS = 0x03,
    };

    enum HwasReasonCode
    {
        // these are HWAS Common specific, and will get mapped into 'correct'
        //  codes by the appropriate platform-specific function
        RC_TARGET_NOT_DECONFIGURABLE        = 0x01,
        RC_TARGET_NOT_GARDABLE              = 0x02,
        RC_GARD_REPOSITORY_FULL             = 0x03,
        RC_TARGET_NOT_FOUND_FOR_GARD_RECORD = 0x04,
        RC_INVALID_TARGET                   = 0x05,
        RC_TOP_LEVEL_TARGET_NULL            = 0x06,
        // if more are added, modify each hwasPlatError.C file as appropriate.
    };
};

#endif
