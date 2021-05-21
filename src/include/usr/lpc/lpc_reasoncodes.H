/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/lpc/lpc_reasoncodes.H $                       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2021                        */
/* [+] Google Inc.                                                        */
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
#ifndef __LPC_REASONCODES_H
#define __LPC_REASONCODES_H

#include <hbotcompid.H>

namespace LPC
{
    enum LPCModuleId
    {
        MOD_LPCDD_INVALID_MODULE        = 0x00,
        MOD_LPCDD_CHECKADDR             = 0x01,
        MOD_LPCDD_READLPC               = 0x02,
        MOD_LPCDD_WRITELPC              = 0x03,
        MOD_LPCDD_CHECKFORLPCERRORS     = 0x04,
        MOD_LPCDD_HWRESET               = 0x05,
        MOD_CREATE_ALTMASTER            = 0x06,
        MOD_READLPC                     = 0x07,
        MOD_WRITELPC                    = 0x08,
        MOD_XSCOMLPC_LPCRW              = 0x09,
        MOD_XSCOMLPC_HWRESET            = 0x0A,
        MOD_XSCOMLPC_CHECKFORLPCERRORS  = 0x0B,
        MOD_XSCOMLPC_CHECK_OPBM_ERRORS  = 0x0C,
    };

    enum LPCReasonCode
    {
        RC_INVALID_ADDR              = LPC_COMP_ID | 0x01,
        RC_ECCB_ERROR                = LPC_COMP_ID | 0x02,
        RC_BAD_ARG                   = LPC_COMP_ID | 0x03,
        RC_OPB_ERROR                 = LPC_COMP_ID | 0x04,
        RC_UNSUPPORTED_OPERATION     = LPC_COMP_ID | 0x05,
        RC_ALTMASTER_EXISTS          = LPC_COMP_ID | 0x06,
        RC_CANT_USE_MASTER           = LPC_COMP_ID | 0x07,
        RC_CANT_USE_SENTINEL         = LPC_COMP_ID | 0x08,
        RC_BAD_TARGET                = LPC_COMP_ID | 0x09,
        RC_LPCHC_ERROR               = LPC_COMP_ID | 0x0A,
        RC_LPC_TIMEOUT               = LPC_COMP_ID | 0x0B,
    };
};

#endif
