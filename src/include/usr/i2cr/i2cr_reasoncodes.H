/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/i2cr/i2cr_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2023                        */
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
#ifndef __I2CR_REASONCODES_H
#define __I2CR_REASONCODES_H

#include <hbotcompid.H>

namespace I2CR
{
    enum I2CRModuleId
    {
        MOD_I2CR_INVALID             = 0x00, // Zero is an invalid module id
        MOD_I2CR_PERFORM_OP          = 0x01, // i2cr.C : i2crPerformOp
    };

    enum I2CRReasonCode
    {
        RC_INVALID                   = I2CR_COMP_ID | 0x00,
        RC_WRITE_ERROR               = I2CR_COMP_ID | 0x01,
        RC_READ_ERROR                = I2CR_COMP_ID | 0x02,
        RC_INVALID_OCMBTYPE          = I2CR_COMP_ID | 0x03,
        RC_INVALID_ADDRESS           = I2CR_COMP_ID | 0x04,
        RC_INVALID_OPTYPE            = I2CR_COMP_ID | 0x05,
        RC_INVALID_ACCESSTYPE        = I2CR_COMP_ID | 0x06,
        RC_INVALID_MASTER_TARGET     = I2CR_COMP_ID | 0x07,
        RC_ATTR_NOT_FOUND            = I2CR_COMP_ID | 0x08,
    };
};

#endif
