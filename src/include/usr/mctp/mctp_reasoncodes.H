/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __MCTP_REASONCODES_H
#define __MCTP_REASONCODES_H

#include <hbotcompid.H>

namespace MCTP
{
    enum MCTPModuleId
    {
        MOD_MCTP_INVALID      = 0x00, /**< Zero is an invalid module id */
        MOD_MCTP_PROCESS_VER  = 0x01, // _mctp_process_version
    };

    enum MCTPReasonCode
    {
        RC_CHANNEL_INACTIVE   = MCTP_COMP_ID | 0x01,

    };
};
#endif
