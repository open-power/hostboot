/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/mdsaccess/mdsaccess_reasoncodes.H $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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

#ifndef MDS_ACCESS_REASON_CODES_H
#define MDS_ACCESS_REASON_CODES_H

/**
 *  @file mdsaccess_reasoncodes.H
 *
 *  @brief The reason codes and module ids for the MDS
 *         (Micro-architectural Data Sampling) controller
 */

#include <hbotcompid.H> // MDS_ACCESS_COMP_ID

namespace MDS_ACCESS
{
    enum MdsAccessModuleId
    {
        MOD_MDS_ACCESS_INVALID = 0x00, // Zero is an invalid module id
        MOD_MDS_UTILS          = 0x01, // mdsAccessUtils.C
    };

    enum MdsAccessReasonCode
    {
        RC_INVALID                = MDS_ACCESS_COMP_ID | 0x00,
        RC_INVALID_BUFFER_LENGTH  = MDS_ACCESS_COMP_ID | 0x01,
        RC_INVALID_DATA_BUFFER    = MDS_ACCESS_COMP_ID | 0x02,
        RC_INVALID_TARGET_TYPE    = MDS_ACCESS_COMP_ID | 0x03,
        RC_INVALID_OPTYPE         = MDS_ACCESS_COMP_ID | 0x04,
        RC_INVALID_SCOM_ADDRESS   = MDS_ACCESS_COMP_ID | 0x05,
    };
};

#endif // #ifndef MDS_ACCESS_REASON_CODES_H
