/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ipmi/ipmi_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014                             */
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
#ifndef __IPMI_REASONCODES_H
#define __IPMI_REASONCODES_H

#include <hbotcompid.H>

namespace IPMI
{
    enum IPMIModuleId
    {
        MOD_IPMISRV_SEND        = 0x01, // IPMI::send/IPMI::sendrecv
        MOD_IPMISRV_REPLY       = 0x02, // IPMI::respond
    };

    enum IPMIReasonCode
    {
        RC_INVALID_QRESPONSE         = IPMI_COMP_ID | 0x01,
        RC_INVALID_SENDRECV          = IPMI_COMP_ID | 0x02,
        RC_INVALID_SEND              = IPMI_COMP_ID | 0x03,
    };
};

#endif
