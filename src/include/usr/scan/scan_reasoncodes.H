/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/scan/scan_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef __SCAN_REASONCODES_H
#define __SCAN_REASONCODES_H

#include <hbotcompid.H>

namespace SCAN
{
    enum SCANModuleId
    {
        MOD_SCANDD_INVALID   = 0x00, /**< Zero is an invalid module id */
        MOD_SCANDD_DDOP      = 0x01, /**< scandd.C : ddOp */
        MOD_SCANDD_DOSCAN    = 0x02, /**< scandd.C : ScanDD::scanDoScan */

    };

    enum SCANReasonCode
    {
        RC_INVALID_LENGTH            = SCAN_COMP_ID | 0x01,
        RC_INVALID_RING_ADDRESS      = SCAN_COMP_ID | 0x02,
        RC_INVALID_OPERATION         = SCAN_COMP_ID | 0x03,
        RC_INVALID_BUF_SIZE          = SCAN_COMP_ID | 0x04,
        RC_SCAN_LAST_BITS_FAIL       = SCAN_COMP_ID | 0x05,
        RC_SCAN_TYPE_SELECT_ERROR    = SCAN_COMP_ID | 0x06,
        RC_HEADER_WRITE_ERROR        = SCAN_COMP_ID | 0x07,
        RC_HEADER_READ_ERROR         = SCAN_COMP_ID | 0x08,
        RC_SCAN_READ_FAIL            = SCAN_COMP_ID | 0x09,
        RC_SCAN_READ_EXTRA_FAIL      = SCAN_COMP_ID | 0x0a,
        RC_SCAN_WRITE_FAIL           = SCAN_COMP_ID | 0x0b,
        RC_HEADER_DATA_MISMATCH      = SCAN_COMP_ID | 0x0c,
        RC_INVALID_DATA              = SCAN_COMP_ID | 0x0d,
    };
};

#endif
