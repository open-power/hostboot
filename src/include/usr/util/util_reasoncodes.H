/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/util/util_reasoncodes.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
        UTIL_LIDMGR_CLEANUP     = 0x07,       // UtilLidMgr::cleanup
        UTIL_RT_CMDS            = 0x08,       // rt_cmds.C
        UTIL_TCE_INIT_HDW       = 0x09,       // UtilTceMgr::initTceInHdw
        UTIL_TCE_ALLOCATE       = 0x0A,       // UtilTceMgr::allocateTces
        UTIL_TCE_DEALLOCATE     = 0x0B,       // UtilTceMgr::deallocateTces
        UTIL_TCE_CREATE_TABLE   = 0x0C,       // UtilTceMgr::createTceTable
        UTIL_TCE_DISABLE_TCES   = 0x0D,       // Util::UTIL_TCE_DISABLE_TCES
        UTIL_TCE_MAP_PSIHB      = 0x0E,       // UtilTceMgr::mapPsiHostBridge
        UTIL_TCE_UNMAP_PSIHB    = 0x0F,       // UtilTceMgr::unmapPsiHostBridge

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
        UTIL_LIDMGR_NOT_FOUND        = UTIL_COMP_ID | 0x0A,
        UTIL_LIDMGR_MM_FAIL          = UTIL_COMP_ID | 0x0B,
        UTIL_TCE_INVALID_SIZE        = UTIL_COMP_ID | 0x0C,
        UTIL_TCE_ADDR_NOT_ALIGNED    = UTIL_COMP_ID | 0x0D,
        UTIL_TCE_DEV_MAP_FAIL        = UTIL_COMP_ID | 0x0E,
        UTIL_TCE_DEV_UNMAP_FAIL      = UTIL_COMP_ID | 0x0F,
        UTIL_TCE_NOT_ENOUGH_FREE_ENTRIES = UTIL_COMP_ID | 0x10,
        UTIL_TCE_ENTRY_NOT_CONTIGUOUS    = UTIL_COMP_ID | 0x11,
        UTIL_TCE_PREVIOUSLY_ALLOCATED    = UTIL_COMP_ID | 0x12,
        UTIL_TCE_INVALID_COUNT       = UTIL_COMP_ID | 0x13,
        UTIL_TCE_ALLOC_BLOCK_FAIL    = UTIL_COMP_ID | 0x14,
        UTIL_TCE_BLOCK_UNMAP_FAIL    = UTIL_COMP_ID | 0x15,

    };
};

#endif
