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
        MOD_UCD_INIT                    = 0x01,
        MOD_UPDATE_ALL_UCD_FLASH_IMAGES = 0x02,
        MOD_UPDATE_UCD_FLASH_IMAGE      = 0x03,
        MOD_VERIFY_UPDATE               = 0x04,
    };

    enum UcdReasonCode
    {
        RC_DEVICE_READ_UNEXPECTED_SIZE_DEVICE_ID      = UCD_COMP_ID | 0x01,
        RC_DEVICE_READ_UNEXPECTED_SIZE_MFR_REVISION   = UCD_COMP_ID | 0x02,
        UCD_INVALID_EYECATCHER                        = UCD_COMP_ID | 0x03,
        UCD_INVALID_MAJOR_VER                         = UCD_COMP_ID | 0x04,
        UCD_TOC_ENTRY_TOO_SMALL                       = UCD_COMP_ID | 0x05,
        UCD_UNSUPPORTED_DEVICE_ID                     = UCD_COMP_ID | 0x06,
        UCD_EOF                                       = UCD_COMP_ID | 0x07,
        UCD_UNSUPPORTED_OPERATION_REQUEST             = UCD_COMP_ID | 0x08,
        UCD_INVALID_COMMANDLINE                       = UCD_COMP_ID | 0x09,
        UCD_ERROR_STORING_TO_FLASH                    = UCD_COMP_ID | 0x0A,
        UCD_TIMEDOUT_STORING_TO_FLASH                 = UCD_COMP_ID | 0x0B,
    };

}; // namespace UCD

#endif
