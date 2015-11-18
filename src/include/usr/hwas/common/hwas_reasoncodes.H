/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas_reasoncodes.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* Licensed under the Apache License, Version 2.0 (the "License");        */
/* you may not use this file except in compliance with the License.       */
/* You may obtain a copy of the License at                                */
/*                                                                        */
/*     http://www.apache.org/licenses/LICENSE-2.0                         */
/*                                                                        */
/* Unless required by applicable law or agreed to in writing, software    */
/* distributed under the License is distributed on an "AS IS" BASIS,      */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or        */
/* implied. See the License for the specific language governing           */
/* permissions and limitations under the License.                         */
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
        MOD_DECONFIG_TARGETS_FROM_GARD = 0x04,
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
        RC_SYSAVAIL_INSUFFICIENT_HW             = HWAS_COMP_ID | 0x04,
        RC_SYSAVAIL_NO_CORES_FUNC               = HWAS_COMP_ID | 0x05,
        RC_SYSAVAIL_NO_MEMORY_FUNC              = HWAS_COMP_ID | 0x06,
        RC_SYSAVAIL_NO_PROCS_FUNC               = HWAS_COMP_ID | 0x07,
        RC_SYSAVAIL_NO_NODES_FUNC               = HWAS_COMP_ID | 0x08,
        RC_SYSAVAIL_NO_MEMBUFS_FUNC             = HWAS_COMP_ID | 0x09,
        RC_RESOURCE_RECOVERED                   = HWAS_COMP_ID | 0x0A,
        RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE   = HWAS_COMP_ID | 0x0B,
        RC_SYSAVAIL_NO_MCAS_FUNC                = HWAS_COMP_ID | 0x0C,
    };
};

#endif
