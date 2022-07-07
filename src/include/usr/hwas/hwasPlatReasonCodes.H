/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasPlatReasonCodes.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2022                        */
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
        MOD_HOST_DISCOVER_TARGETS  = 0x80,
        MOD_PLAT_DECONFIG_GARD     = 0x81,
        MOD_PLAT_READIDEC          = 0x82,
        MOD_PLAT_READLX            = 0x83,
        MOD_CHECK_HB_NVDIMM        = 0x84,
        MOD_CROSSCHECK_SP_PRESENCE = 0x85,
        MOD_PLAT_CHECK_OCMB_CRC    = 0x86,
    };

    enum HwasPlatReasonCode
    {
        //  @note Must always start @ 0x80, since common reason codes occupy
        //      0x00 -> 0x7F range
        RC_TOP_LEVEL_TARGET_NULL            = HWAS_COMP_ID | 0x80,
        RC_TARGET_NOT_GARDABLE              = HWAS_COMP_ID | 0x81,
        RC_GARD_REPOSITORY_FULL             = HWAS_COMP_ID | 0x82,
        RC_BAD_CHIPID                       = HWAS_COMP_ID | 0x83,
        RC_BAD_LX                           = HWAS_COMP_ID | 0x84,
        RC_BAD_MCA                          = HWAS_COMP_ID | 0x85,
        RC_RT_NULL_FIRMWARE_REQUEST_PTR     = HWAS_COMP_ID | 0x86,
        RC_RT_NULL_FIRMWARE_MSG_PTR         = HWAS_COMP_ID | 0x87,
        RC_HB_PROC_ONLY_NVDIMM              = HWAS_COMP_ID | 0x88,
        RC_BAD_CLEAR_ALL_RESET_VERSION      = HWAS_COMP_ID | 0x89,
        RC_NO_FRU_PART_NUM                  = HWAS_COMP_ID | 0x8A,
        RC_NO_FRU_SERIAL_NUM                = HWAS_COMP_ID | 0x8B,
        RC_NO_FRU_TARGET                    = HWAS_COMP_ID | 0x8C,
        RC_NOT_CURRENT_GARD_VERSION         = HWAS_COMP_ID | 0x8D,
        RC_CLEAN_GARD_RECORDS               = HWAS_COMP_ID | 0x8E,
        RC_PRESENCE_MISMATCH_SP             = HWAS_COMP_ID | 0x8F,
        RC_PRESENCE_MISMATCH_HB             = HWAS_COMP_ID | 0x90,
        RC_PNOR_ACCESS_FAILED               = HWAS_COMP_ID | 0x91,
        RC_RT_POSSIBLE_PNOR_CORRUPTION      = HWAS_COMP_ID | 0x92,
        RC_CRC_MISMATCH_FOUND               = HWAS_COMP_ID | 0x93,
    };

};

#endif
