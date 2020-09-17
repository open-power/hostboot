/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expscom/expscom_reasoncodes.H $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef __EXPSCOM_REASONCODES_H
#define __EXPSCOM_REASONCODES_H

#include <hbotcompid.H>

namespace EXPSCOM
{
    enum EXPSCOMModuleId
    {
        MOD_OCMBSCOM_INVALID    = 0x00, // Zero is an invalid module id
        MOD_OCMB_UTILS          = 0x01, // expscom_utils.C
    };

    enum EXPSCOMReasonCode
    {
        RC_INVALID                   = EXPSCOM_COMP_ID | 0x00,
        RC_INVALID_LENGTH            = EXPSCOM_COMP_ID | 0x01,
        RC_INVALID_MODEL_TYPE        = EXPSCOM_COMP_ID | 0x02,
        RC_INVALID_OPTYPE            = EXPSCOM_COMP_ID | 0x03,
        RC_INVALID_ADDRESS           = EXPSCOM_COMP_ID | 0x04,
    };

    enum UserDetailsTypes
    {
        EXPSCOM_UDT_ACTIVE_LOG     = 0x01,
        EXPSCOM_UDT_SAVED_LOG_A    = 0x02,
        EXPSCOM_UDT_SAVED_LOG_B    = 0x03,
    };
};

#endif
