/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/ucd/ucd_reasoncodes.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef __UCD_REASONCODES_H
#define __UCD_REASONCODES_H

#include <hbotcompid.H>

namespace UCD_RC
{

    enum UcdModuleId
    {
        MOD_UCD_INIT              = 0x01,
    };

    enum UcdReasonCode
    {
        RC_DEVICE_READ_UNEXPECTED_SIZE_DEVICE_ID      = UCD_COMP_ID | 0x01,
        RC_DEVICE_READ_UNEXPECTED_SIZE_MFR_REVISION   = UCD_COMP_ID | 0x02,
    };

}; // namespace UCD

#endif
