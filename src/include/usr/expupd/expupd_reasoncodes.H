/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/expupd/expupd_reasoncodes.H $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

#ifndef __EXPUPD_REASONCODES_H
#define __EXPUPD_REASONCODES_H

#include <hbotcompid.H>

namespace EXPUPD
{

    enum ExpUpdModuleId
    {
        MOD_OCMB_FW_VALIDATE_IMAGE = 0x01,
        MOD_PARSE_TAGGED_DATA_TRIPLET = 0x02,
        MOD_SET_FW_VERSION_INFO = 0x03,
        MOD_WRITE_EXPLORER_FW_VERSION = 0x04,
        MOD_IS_MDS_DDIMM = 0x05,
    };

    enum ExpUpdReasonCode
    {
        INVALID_PARMS                             = EXPUPD_COMP_ID | 0x01,
        INVALID_EYE_CATCHER                       = EXPUPD_COMP_ID | 0x02,
        INVALID_HEADER_VERSION                    = EXPUPD_COMP_ID | 0x03,
        INVALID_HEADER_SIZE                       = EXPUPD_COMP_ID | 0x04,
        MISSING_SHA512_HASH                       = EXPUPD_COMP_ID | 0x05,
        INVALID_DATA_TRIPLET_SIZE                 = EXPUPD_COMP_ID | 0x06,
        INVALID_HASH_TRIPLET_SIZE                 = EXPUPD_COMP_ID | 0x07,
        INVALID_TAG_ID                            = EXPUPD_COMP_ID | 0x08,
        MISSING_FW_VERSION                        = EXPUPD_COMP_ID | 0x09,
        UNSUPPORTED_NUMBER_OF_DIMMS               = EXPUPD_COMP_ID | 0x0a,
        DEVICE_READ_FAIL                          = EXPUPD_COMP_ID | 0x0b,
    };

}; // namespace EXPUPD

#endif
