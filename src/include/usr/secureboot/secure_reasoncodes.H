/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/secureboot/secure_reasoncodes.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2016                        */
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
#ifndef __SECUREBOOT_REASONCODES_H
#define __SECUREBOOT_REASONCODES_H

#include <hbotcompid.H>

namespace SECUREBOOT
{
    enum SECUREModuleId
    {
        MOD_SECURE_INVALID              = 0x00,
        MOD_SECURE_BLINDPURGE           = 0x01,
        MOD_SECURE_ROM_INIT             = 0x02,
        MOD_SECURE_ROM_VERIFY           = 0x03,
        MOD_SECURE_ROM_CLEANUP          = 0x04,
        MOD_SECURE_ROM_SHA512           = 0x05,
   };

    enum SECUREReasonCode
    {
        RC_PURGEOP_PENDING              = SECURE_COMP_ID | 0x01,
        RC_PURGEOP_FAIL_COMPLETE        = SECURE_COMP_ID | 0x02,
        RC_DEV_MAP_FAIL                 = SECURE_COMP_ID | 0x03,
        RC_PAGE_ALLOC_FAIL              = SECURE_COMP_ID | 0x04,
        RC_SET_PERMISSION_FAIL_EXE      = SECURE_COMP_ID | 0x05,
        RC_SET_PERMISSION_FAIL_WRITE    = SECURE_COMP_ID | 0x06,
        RC_ROM_VERIFY                   = SECURE_COMP_ID | 0x07,
        RC_ROM_SHA512                   = SECURE_COMP_ID | 0x08,

        // Reason codes 0xA0 - 0xEF reserved for trustedboot_reasoncodes.H
    };
}

#endif
