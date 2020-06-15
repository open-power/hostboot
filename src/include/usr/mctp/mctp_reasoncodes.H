/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mctp/mctp_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __MCTP_REASONCODES_H
#define __MCTP_REASONCODES_H

#include <hbotcompid.H>

namespace MCTP
{
    enum MCTPModuleId
    {
        MOD_MCTP_INVALID      = 0x00, // Zero is an invalid module id
        MOD_MCTP_CHANNEL_INIT = 0x01, // _mctp_channel_init
        MOD_HANDLE_OUTBOUND   = 0x02, // handle_outbound_messages
        MOD_RX_CALLBACK       = 0x03, // rx_message
    };

    enum MCTPReasonCode
    {
        RC_CHANNEL_INACTIVE   = MCTP_COMP_ID | 0x01,
        RC_SEND_PLDM_FAIL     = MCTP_COMP_ID | 0x02,
        RC_INVALID_MSG_TYPE   = MCTP_COMP_ID | 0x03,
        RC_ERROR_CACHING_MSG  = MCTP_COMP_ID | 0x04,
    };
};
#endif
