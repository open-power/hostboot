/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scom/scomreasoncodes.H $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
#ifndef __SCOM_REASONCODES_H
#define __SCOM_REASONCODES_H

#include <hbotcompid.H>

namespace SCOM
{
    enum scomModuleId
    {
        SCOM_PERFORM_OP                 = 0x00,
        SCOM_TRANSLATE                  = 0x01,
        SCOM_PERFORM_TRANSLATE          = 0x02,
        SCOM_FIND_PARENT_TARGET         = 0x03,
        SCOM_CHECK_INDIRECT_AND_DO_SCOM = 0x04,
        SCOM_TRANSLATE_P9               = 0x05,
    };

    enum scomReasonCode
    {
        SCOM_INVALID_ADDR           = SCOM_COMP_ID | 0x01,
        SCOM_NO_MATCHING_PARENT     = SCOM_COMP_ID | 0x02,
        SCOM_TRANS_INVALID_TYPE     = SCOM_COMP_ID | 0x03,
        SCOM_TRANS_UNSUPPORTED      = SCOM_COMP_ID | 0x04,
        SCOM_INDIRECT_READ_FAIL     = SCOM_COMP_ID | 0x05,
        SCOM_INDIRECT_READ_TIMEOUT  = SCOM_COMP_ID | 0x06,
        SCOM_INDIRECT_WRITE_FAIL    = SCOM_COMP_ID | 0x07,
        SCOM_INDIRECT_WRITE_TIMEOUT = SCOM_COMP_ID | 0x08,
        SCOM_P9_TRANS_INVALID_TYPE  = SCOM_COMP_ID | 0x09,
        SCOM_INVALID_TRANSLATION    = SCOM_COMP_ID | 0x0A,
        SCOM_TRANS_CANT_FIND_PARENT = SCOM_COMP_ID | 0x0B,
        SCOM_TARGET_ADDR_MISMATCH   = SCOM_COMP_ID | 0x0C,
        SCOM_ISCHIPUNITSCOM_INVALID = SCOM_COMP_ID | 0x0D,
    };
};

#endif
