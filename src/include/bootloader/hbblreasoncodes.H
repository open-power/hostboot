/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/hbblreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#ifndef __HBBLREASONCODES_H
#define __HBBLREASONCODES_H


#include <usr/hbotcompid.H>



namespace Bootloader
{

/**
* @enum hbblModuleId
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
    enum hbblModuleId
    {
        MOD_BOOTLOADER_INVALID   = 0x00, /**< Zero is an invalid module id */
        MOD_BOOTLOADER_TERMINATE = 0x01, /**< bl_terminate.C : save SRC */
        MOD_BOOTLOADER_MAIN      = 0x02, /**< bootloader.C : main */
        MOD_PNORACC_READTOC      = 0x03, /**< bl_pnorAccess.C : read TOC */
        MOD_PNORACC_GETHBBSECT   = 0x04, /**< bl_pnorAccess.C : get HBB sect */

    };

/**
 * @enum hbblReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
    enum hbblReasonCode
    {
        RC_ASSERT            = HBBL_COMP_ID | 0x01, /**< Assert */
        RC_SHUTDOWN          = HBBL_COMP_ID | 0x02, /**< Shutdown */
        RC_UNHANDLED_EX      = HBBL_COMP_ID | 0x03, /**< Unhandled Exception */
        RC_REMOVE_ECC_FAIL   = HBBL_COMP_ID | 0x04, /**< Remove ECC Failed */
        RC_CHK_NULL_BUFFER   = HBBL_COMP_ID | 0x05, /**< Check for NULL Buffr */
        RC_HDR_CHECKSUM_ERR  = HBBL_COMP_ID | 0x06, /**< Hdr Checksum Error */
        RC_CHECK_HEADER_ERR  = HBBL_COMP_ID | 0x07, /**< Check Header Error */
        RC_PARSE_ENTRIES_ERR = HBBL_COMP_ID | 0x08, /**< Parse Entries Error */
        RC_NO_HBB_IN_TOC     = HBBL_COMP_ID | 0x09, /**< No HBB Sect in TOC */
    };

};  // end Bootloader


#endif
