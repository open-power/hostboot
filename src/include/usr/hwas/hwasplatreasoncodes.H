/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/hwasplatreasoncodes.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2014                   */
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
