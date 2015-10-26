/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/isteps/istep_reasoncodes.H $                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#ifndef _ISTEP_REASONCODES_H_
#define _ISTEP_REASONCODES_H_

#include <hbotcompid.H>
namespace ISTEP
{
    /**
     * @brief Defines the ISTEP error log module IDs
     */
    enum istepModuleId
    {
        MOD_EXIT_CACHE_CONTAINED                   = 0x01,
    };

    /**
     * @brief Defines the ISTEP error log reason codes
     */
    enum istepReasonCode
    {
        RC_NO_MIRRORED_MEMORY         = HWPF_COMP_ID | 0x01,
        RC_MM_EXTEND_FAILED           = HWPF_COMP_ID | 0x02,
    };

};

#endif
