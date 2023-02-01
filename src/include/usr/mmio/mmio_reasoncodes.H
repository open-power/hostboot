/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mmio/mmio_reasoncodes.H $                     */
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
#ifndef __MMIO_REASONCODES_H
#define __MMIO_REASONCODES_H

#include <hbotcompid.H>

namespace MMIO
{
    enum MMIOModuleId
    {
        MOD_MMIO_INVALID             = 0x00,
        MOD_MMIO_SETUP               = 0x01,
        MOD_MMIO_PERFORM_OP          = 0x02,
        MOD_MMIO_GET_MCC_SCOM        = 0x03,
        // unused 0x04
        MOD_VALIDATE_OCMB_MMIO_OP    = 0x05,
        MOD_MMIO_CHAN_CHECKSTOP      = 0x06,
        MOD_CHECK_OCMB_ERROR         = 0x07,
        MOD_DETERMINE_CALLOUTS       = 0x08,
        MOD_DETERMINE_EXP_CALLOUTS   = 0x09,
        RT_OCMB_MMIO_PERFORM_OP      = 0x0A,
        MOD_DETERMINE_ODY_CALLOUTS   = 0x0B,
        MOD_CHECK_OCMB_ERRORS        = 0x0C,
    };

    enum MMIOReasonCode
    {
        RC_INVALID                   = MMIO_COMP_ID | 0x00,
        RC_INVALID_SETUP             = MMIO_COMP_ID | 0x01,
        RC_INVALID_BUFFER            = MMIO_COMP_ID | 0x02,
        RC_INSUFFICIENT_BUFFER       = MMIO_COMP_ID | 0x03,
        RC_INCORRECT_BUFFER_LENGTH   = MMIO_COMP_ID | 0x04,
        RC_INVALID_OFFSET            = MMIO_COMP_ID | 0x05,
        RC_INVALID_OFFSET_ALIGNMENT  = MMIO_COMP_ID | 0x06,
        RC_INVALID_ACCESS_LIMIT      = MMIO_COMP_ID | 0x07,
        RC_BAD_MMIO_READ             = MMIO_COMP_ID | 0x08,
        RC_BAD_MMIO_WRITE            = MMIO_COMP_ID | 0x09,
        RC_MCC_NOT_FOUND             = MMIO_COMP_ID | 0x0A,
        RC_BAR_OFFSET_MISMATCH       = MMIO_COMP_ID | 0x0B,
        RC_MMIO_CHAN_CHECKSTOP       = MMIO_COMP_ID | 0x0C,
        RC_UNSUPPORTED_CHIPID        = MMIO_COMP_ID | 0x0D,
    };
};

#endif
