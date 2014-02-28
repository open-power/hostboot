/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasplatreasoncodes.H $                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
#ifndef HWASPLATREASONCODES_H
#define HWASPLATREASONCODES_H

namespace HWAS
{
    enum HwasPlatModuleID
    {
        //
        // Code to identify discrete error locations/events
        //
        //  @note Must always start @ 0x80, since common module IDs occupy
        //      0x00 -> 0x7F range
        MOD_HOST_DISCOVER_TARGETS = 0x80,
        MOD_HOST_GARD             = 0x81,
        MOD_PLAT_DECONFIG_GARD    = 0x82,
        MOD_PLAT_READIDEC         = 0x83,
    };

    enum HwasPlatReasonCode
    {
        //  @note Must always start @ 0x80, since common reason codes occupy
        //      0x00 -> 0x7F range
        RC_TOP_LEVEL_TARGET_NULL            = HWAS_COMP_ID | 0x80,
        RC_TARGET_NOT_GARDABLE              = HWAS_COMP_ID | 0x81,
        RC_GARD_REPOSITORY_FULL             = HWAS_COMP_ID | 0x82,
        RC_BAD_CHIPID                       = HWAS_COMP_ID | 0x83,
    };
};

#endif
