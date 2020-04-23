/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/devtree/devtreereasoncodes.H $                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2011,2020                        */
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
#ifndef __DEVTREE_REASONCODES_H
#define __DEVTREE_REASONCODES_H

/** @file devtreereasoncodes.H
 *  @brief Defines the DEVTREE error codes
 */

#include <hbotcompid.H>

namespace DEVTREE
{
    enum devtreeModuleId
    {
        HANDLE_DEVTREE_ERRORS       = 0x00,
        DEVTREE_SYNC_ATTRS          = 0x01,
        DEBUG_READ_CMP_DATA         = 0x02,
    };

    enum devtreeReasonCode
    {
        LIBFDT_ERROR_RC             = DEVTREE_COMP_ID | 0x01,
        TARGET_ATTR_ZERO_SIZE       = DEVTREE_COMP_ID | 0x02,
        GET_TARGET_ATTR_FAILED      = DEVTREE_COMP_ID | 0x03,
        TARGET_DTREE_SIZE_MISMATCH  = DEVTREE_COMP_ID | 0x04,
    };
};

#endif
