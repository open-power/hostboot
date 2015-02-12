/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/util_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

#ifndef __UTIL_REASONCODES_H
#define __UTIL_REASONCODES_H

#include <hbotcompid.H>

namespace Util
{
    enum ModuleId
    {
        UTIL_MOD_MEM_READ       = 0x01,       // UtilMem::Read
        UTIL_MOD_MEM_WRITE      = 0x02,       // UtilMem::Write
        UTIL_LIDMGR_GETLID      = 0x03,       // UtilLidMgr::getLid
        UTIL_LIDMGR_GETLIDSIZE  = 0x04,       // UtilLidMgr::getLidSize
        UTIL_LIDMGR_GETLIDPNOR  = 0x05,       // UtilLidMgr::getLidPnor
        UTIL_LIDMGR_RT          = 0x06,
    };

    enum ReasonCode
    {
        UTIL_ERC_NONE                = UTIL_COMP_ID | 0x01,
        UTIL_ERC_BAD_PTR             = UTIL_COMP_ID | 0x02,
        UTIL_ERC_EOF                 = UTIL_COMP_ID | 0x03,
        UTIL_LIDMGR_RC_FAIL          = UTIL_COMP_ID | 0x04,
        UTIL_LIDMGR_INVAL_DATA       = UTIL_COMP_ID | 0x05,
        UTIL_LIDMGR_INVAL_SIZE       = UTIL_COMP_ID | 0x06,
        UTIL_LIDMGR_UNSUP_MSG        = UTIL_COMP_ID | 0x07,
        UTIL_LIDMGR_INVAL_SIZE_PNOR  = UTIL_COMP_ID | 0x08,
        UTIL_LIDMGR_UNLOAD_RC_FAIL   = UTIL_COMP_ID | 0x09,
    };
};

#endif
