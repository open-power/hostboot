/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/bootloader/hbblreasoncodes.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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
        RC_XSCOM_BAD_PARAM         = HBBL_COMP_ID | 0x12,  /**< Bad params passed to XSCOM op */
        RC_XSCOM_OP_FAILED         = HBBL_COMP_ID | 0x13,  /**< XSCOM operation failed */
        RC_XSCOM_OP_TIMEOUT        = HBBL_COMP_ID | 0x14,  /**< XSCOM operation timeout */
        RC_SPI_TPM_READ_FAIL       = HBBL_COMP_ID | 0x15,  /**< A SPI read from TPM failed */
        RC_SPI_TPM_WRITE_FAIL      = HBBL_COMP_ID | 0x16,  /**< A SPI write to TPM failed */
        RC_TPM_INVALID_READ_SIZE   = HBBL_COMP_ID | 0x17,  /**< We read out more or less data than we wanted */
        RC_TPM_INVALID_WRITE_SIZE  = HBBL_COMP_ID | 0x18,  /**< We wrote less or more data than we wanted */
        RC_TPM_COMMAND_NOT_READY   = HBBL_COMP_ID | 0x19,  /**< TPM is not ready for a command */
        RC_TPM_NOT_EXPECTING       = HBBL_COMP_ID | 0x1a,  /**< TPM not expecting more data while it should be */
        RC_TPM_TIMEOUT_D_1         = HBBL_COMP_ID | 0x1b,  /**< TPM hit the TPM D timeout (1) */
        RC_TPM_TIMEOUT_D_2         = HBBL_COMP_ID | 0x1c,  /**< TPM hit the TPM D timeout (2) */
        RC_TPM_IS_EXPECTING        = HBBL_COMP_ID | 0x1d,  /**< TPM expecting more data while it shouldn't be */
        RC_TPM_STS_TIMEOUT         = HBBL_COMP_ID | 0x1e,  /**< Timeout out waiting for TPM status valid reg */
        RC_TPM_OVERFLOW            = HBBL_COMP_ID | 0x1f,  /**< TPM expected more data than we thought */
        RC_TPM_EXTRA_DATA_AVAIL    = HBBL_COMP_ID | 0x20,  /**< Data size mismatch */
        RC_TPM_READ_TIMEOUT        = HBBL_COMP_ID | 0x21,  /**< TPM read fifo timeout */
        RC_TPM_TIMEOUT_B           = HBBL_COMP_ID | 0x22,  /**< TPM hit the TPM timeout B */
        RC_TPM_INIT_FAIL           = HBBL_COMP_ID | 0x23,  /**< Failed to init the TPM */
        RC_SPI_CLK_INIT_FAIL       = HBBL_COMP_ID | 0x24,  /**< Failed to init SPI clock for TPM engine */
        RC_TPM_PCR_EXTEND_FAIL     = HBBL_COMP_ID | 0x25,  /**< TPM PCR extend failed */
        RC_SPI_RESET_FAIL          = HBBL_COMP_ID | 0x26,  /**< Failed to reset SPI enging */
        RC_SPI_CLR_ERR_FAIL        = HBBL_COMP_ID | 0x27,  /**< Failed to clear SPI status errors */
        //termination_rc
        RC_BAD_PROTECTED_SIZE_LEN  = HBBL_COMP_ID | 0x28,  /**< Protected Size of HBB is too large */
        RC_TPM_STS_TIMEOUT_REG     = HBBL_COMP_ID | 0x29,  /**< Timeout out waiting for TPM status reg */

        RC_TPM_INITIALIZE          = 0x100, /**< Special TPM RC that signals if TPM's been initialized already */

    };

};  // end Bootloader


#endif
