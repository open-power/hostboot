/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas_reasoncodes.H $              */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
        MOD_CHECK_MIN_HW          = 0x03,
    };

    enum HwasReasonCode
    {
        RC_TARGET_NOT_DECONFIGURABLE        = HWAS_COMP_ID | 0x01,
        RC_TARGET_NOT_FOUND_FOR_GARD_RECORD = HWAS_COMP_ID | 0x02,
        RC_INVALID_TARGET                   = HWAS_COMP_ID | 0x03,
        //
        //  System Availability Service codes
        //  The first is a blanket error that will be returned to the caller,
        //      further errors will be committed in the routine.
        //termination_rc
        RC_SYSAVAIL_INSUFFICIENT_HW         = HWAS_COMP_ID | 0x04,
        RC_SYSAVAIL_NO_CORES_FUNC           = HWAS_COMP_ID | 0x05,
        RC_SYSAVAIL_NO_MEMORY_FUNC          = HWAS_COMP_ID | 0x06,
        RC_SYSAVAIL_NO_PROCS_FUNC           = HWAS_COMP_ID | 0x07,
        RC_SYSAVAIL_NO_NODES_FUNC           = HWAS_COMP_ID | 0x08,
    };
};

#endif
