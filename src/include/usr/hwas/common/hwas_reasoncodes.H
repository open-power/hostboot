/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwas_reasoncodes.H $              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2022                        */
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
        MOD_DECONFIG_GARD                       = 0x01,
        MOD_PROCESS_CALLOUT                     = 0x02,
        MOD_CHECK_MIN_HW                        = 0x03,
        MOD_DECONFIG_TARGETS_FROM_GARD          = 0x04,
        MOD_VALIDATE_EC_LEVELS                  = 0x05,
        MOD_RUNTIME_DECONFIG                    = 0x06,
        MOD_DISABLE_OBUS                        = 0x07,
        MOD_UPDATE_PROC_MEM_TO_USE              = 0x08,
        MOD_IS_DESCENDANT_FUNCTIONAL            = 0x09,
        MOD_FIND_RULES_FOR_TARGET               = 0x0A,
        MOD_DISCOVER_TARGETS                    = 0x0B,
        MOD_UPDATE_PROC_COMPAT_RISK_LEVEL       = 0x0C,
        MOD_CHECK_PG_FOR_DESC                   = 0x0D,
        MOD_OCMB_IDEC                           = 0x0E,
        MOD_OCMB_IDEC_PHASE_1                   = 0x0F,
        MOD_OCMB_IDEC_PHASE_2                   = 0x10,
        MOD_OCMB_TRANSLATE_SPD_IDEC             = 0x11,
        MOD_DECONFIG_TARGETS_FROM_GARD_AND_VPD  = 0x12,
        MOD_VALIDATE_EC_MSL_LEVELS              = 0x13,
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
        RC_SYSAVAIL_INSUFFICIENT_HW              = HWAS_COMP_ID | 0x04,
        RC_SYSAVAIL_NO_CORES_FUNC                = HWAS_COMP_ID | 0x05,
        RC_SYSAVAIL_NO_MEMORY_FUNC               = HWAS_COMP_ID | 0x06,
        RC_SYSAVAIL_NO_PROCS_FUNC                = HWAS_COMP_ID | 0x07,
        RC_SYSAVAIL_NO_NODES_FUNC                = HWAS_COMP_ID | 0x08,
        RC_SYSAVAIL_NO_MEMBUFS_FUNC              = HWAS_COMP_ID | 0x09,
        RC_RESOURCE_RECOVERED                    = HWAS_COMP_ID | 0x0A,
        RC_SYSAVAIL_MISSING_CRITICAL_RESOURCE    = HWAS_COMP_ID | 0x0B,
        RC_SYSAVAIL_NO_MCAS_FUNC                 = HWAS_COMP_ID | 0x0C,
        RC_SYSAVAIL_NO_NX_FUNC                   = HWAS_COMP_ID | 0x0E,
        RC_EC_MISMATCH                           = HWAS_COMP_ID | 0x0F,
        RC_FAILED_EC_VALIDATION                  = HWAS_COMP_ID | 0x10,
        RC_INVALID_PARAM                         = HWAS_COMP_ID | 0x11,
        RC_NOT_AT_RUNTIME                        = HWAS_COMP_ID | 0x12,
        RC_NULL_TARGET                           = HWAS_COMP_ID | 0x13,
        RC_ONLY_TWO_OBUS_SHOULD_BE_CONFIGURED    = HWAS_COMP_ID | 0x14,
        RC_NO_UPDATE_WHEN_MEM_MISSING            = HWAS_COMP_ID | 0x15,
        RC_NO_PG_LOGIC                           = HWAS_COMP_ID | 0x16,
        RC_SYSAVAIL_NO_OCMBS_FUNC                = HWAS_COMP_ID | 0x17,
        RC_SYSAVAIL_NO_MEMORY_PRESENT            = HWAS_COMP_ID | 0x18,
        RC_PG_INDEX_INVALID                      = HWAS_COMP_ID | 0x19,
        RC_PARTIAL_GOOD_INFORMATION              = HWAS_COMP_ID | 0x1A,
        RC_FORCED_COMPAT_INVALID_LEVEL           = HWAS_COMP_ID | 0x1B,
        RC_FORCED_NATIVE_INVALID_MIXED_EC        = HWAS_COMP_ID | 0x1C,
        RC_FORCED_NATIVE_OF_INCOMPATIBLE_RISK    = HWAS_COMP_ID | 0x1D,
        RC_PARTIAL_GOOD_MISSING_TARGET           = HWAS_COMP_ID | 0x1E,
        RC_OCMB_SPD_REVISION_MISMATCH            = HWAS_COMP_ID | 0x1F,
        RC_OCMB_UNEXPECTED_IDEC                  = HWAS_COMP_ID | 0x20,
        RC_OCMB_UNKNOWN_CHIP_TYPE                = HWAS_COMP_ID | 0x21,
        RC_OCMB_INTERFACE_TYPE_MISMATCH          = HWAS_COMP_ID | 0x22,
        RC_OCMB_CHIP_ID_MISMATCH                 = HWAS_COMP_ID | 0x23,
        RC_HB_SBE_DECONFIG_MISMATCH              = HWAS_COMP_ID | 0x24,
        RC_HB_SBE_DECONFIG_MISMATCHES_EXIST      = HWAS_COMP_ID | 0x25,
        RC_SYSAVAIL_SBE_NOT_ENOUGH_BACKING_CACHE = HWAS_COMP_ID | 0x26,
        RC_FAILED_MSL_EC_VALIDATION              = HWAS_COMP_ID | 0x27,
        RC_EMPTY_MRW_MSL_ARRAY                   = HWAS_COMP_ID | 0x28,
    };

    enum HwasPlatUserDetailsTypes
    {
        HWAS_UDT_PARTIAL_GOOD_DATA = 0x01,
        HWAS_UDT_PARTIAL_GOOD_DATA_V2 = 0x02
    };

    enum HwasPlatUserDetailsVersions
    {
        HWAS_UDT_VERSION_1 = 0x01
    };

};

#endif
