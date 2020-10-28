/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/hbblreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
        MOD_BOOTLOADER_INVALID           = 0x00, /**< Zero is an invalid module id */
        MOD_BOOTLOADER_TERMINATE         = 0x01, /**< bl_terminate.C : save SRC */
        MOD_BOOTLOADER_MAIN              = 0x02, /**< bootloader.C : main */
        MOD_PNORACC_READTOC              = 0x03, /**< bl_pnorAccess.C : read TOC */
        MOD_PNORACC_GETHBBSECT           = 0x04, /**< bl_pnorAccess.C : get HBB sect */
        MOD_BOOTLOADER_VERIFY            = 0x05, /**< bootloader.C : verifyContainer */
        MOD_BOOTLOADER_ASSERT            = 0x06, /**< bootloader.H assert */
        MOD_BOOTLOADER_VERIFY_COMP_ID    = 0x07, /**< bootloader.C : verifyComponentId */
        MOD_PNORACC_FINDTOC              = 0x08, /**< bl_pnorAccess.C : find TOC */
    };

/**
 * @enum hbblReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
    enum hbblReasonCode
    {
        RC_NO_ERROR                = 0x0,
        RC_ASSERT                  = HBBL_COMP_ID | 0x01, /**< Assert */
        RC_SHUTDOWN                = HBBL_COMP_ID | 0x02, /**< Shutdown */
        RC_STD_EXCEPTION           = HBBL_COMP_ID | 0x03, /**< Standard Exception */
        RC_STD_EX_W_DSISR          = HBBL_COMP_ID | 0x04, /**< Std Except w/ DSISR */
        RC_STD_EX_W_SRR1           = HBBL_COMP_ID | 0x05, /**< Std Except w/ SRR1 */
        RC_HYPE_EXCEPTION          = HBBL_COMP_ID | 0x06, /**< Hypervisor Exception */
        //termination_rc
        RC_REMOVE_ECC_FAIL         = HBBL_COMP_ID | 0x07, /**< Remove ECC Failed */
        RC_CHK_NULL_BUFFER         = HBBL_COMP_ID | 0x08, /**< Check for NULL Buffr */
        //termination_rc
        RC_HDR_CHECKSUM_ERR        = HBBL_COMP_ID | 0x09, /**< Hdr Checksum Error */
        //termination_rc
        RC_CHECK_HEADER_ERR        = HBBL_COMP_ID | 0x0A, /**< Check Header Error */
        //termination_rc
        RC_PARSE_ENTRIES_ERR       = HBBL_COMP_ID | 0x0B, /**< Parse Entries Error */
        //termination_rc
        RC_NO_HBB_IN_TOC           = HBBL_COMP_ID | 0x0C, /**< No HBB Sect in TOC */
        RC_PNOR_SECID_OUT_OF_RANGE = HBBL_COMP_ID | 0x0D, /**< Requested PNOR SecId DNE in string array */
        RC_PNOR_NULLPTR            = HBBL_COMP_ID | 0x0E, /**< Requested address to compare is a nullptr */
        //termination_rc
        RC_BAD_WORK_LEN            = HBBL_COMP_ID | 0x0F, /**< Working length too large */
        //termination_rc
        RC_LPC_ERR                 = HBBL_COMP_ID | 0x10, /**< LPC Error */
        //termination_rc
        RC_TOC_NOT_FOUND_ERR       = HBBL_COMP_ID | 0x11, /**< TOC Not Found Error */
        RC_XSCOM_BAD_PARAM         = HBBL_COMP_ID | 0x12  /**< Bad params passed to XSCOM op */

    };

};  // end Bootloader


#endif
