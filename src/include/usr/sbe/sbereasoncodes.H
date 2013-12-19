/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/vpd/vpdreasoncodes.H $                        */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __SBEREASONCODES_H
#define __SBEREASONCODES_H

// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace SBE
{

/**
* @enum SbeModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum sbeModuleId
{
    SBE_INVALID_MODULE                  = 0x00,
    SBE_FIND_IN_PNOR                    = 0x01,
    SBE_UPDATE_SEEPROMS                 = 0x02,
    SBE_GETSET_MVPD_VERSION             = 0x03,
    SBE_READ_PNOR_VERSION               = 0x04,
    SBE_READ_SBE_FROM_PNOR              = 0x05,
    SBE_CREATE_TEST_SPACE               = 0x06,
    SBE_CLEANUP_TEST_SPACE              = 0x07,
    SBE_GET_TARGET_INFO_STATE           = 0x08,
    SBE_GET_SEEPROM_INFO                = 0x09,
    SBE_DECISION_TREE                   = 0x0A,
    SBE_CUSTOMIZE_IMG                   = 0x0B,
};

/**
 * @enum sbeReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum sbeReasonCode
{
    SBE_INVALID_REASONCODE              = SBE_COMP_ID | 0x00,   // Invalid RC
    SBE_ALLOC_BLOCK_FAIL                = SBE_COMP_ID | 0x01,
    SBE_SET_PERMISSION_FAIL             = SBE_COMP_ID | 0x02,
    SBE_REMOVE_PAGES_FAIL               = SBE_COMP_ID | 0x03,
    SBE_REMOVE_PAGES_FOR_EC             = SBE_COMP_ID | 0x04,
    SBE_REMOVE_PAGES_CLEANUP            = SBE_COMP_ID | 0x05,
    SBE_UNSUPPORTED_TOC                 = SBE_COMP_ID | 0x06,
    SBE_INVALID_EYECATCHER              = SBE_COMP_ID | 0x07,
    SBE_EC_NOT_FOUND                    = SBE_COMP_ID | 0x08,
    SBE_XIP_IMG_SIZE_FAIL               = SBE_COMP_ID | 0x09,
    SBE_MVPD_LEN_INVALID                = SBE_COMP_ID | 0x0A,
    SBE_VERSION_NOT_FOUND               = SBE_COMP_ID | 0x0B,

    // SBE_UPDATE_REQUEST_REIPL Must have one unique use
    //   for Shutdown path. FSP relies on it.
    // termination_rc
    SBE_UPDATE_REQUEST_REIPL            = SBE_COMP_ID | 0x0C,

    SBE_INVALID_INPUT                   = SBE_COMP_ID | 0x0D,
    SBE_INVALID_SEEPROM_SIDE            = SBE_COMP_ID | 0x0E,
    SBE_ECC_FAIL                        = SBE_COMP_ID | 0x0F,
    SBE_PERM_SIDE_DIRTY_BAD_PATH        = SBE_COMP_ID | 0x10,
    SBE_P8_XIP_CUSTOMIZE_UNSUCCESSFUL   = SBE_COMP_ID | 0x11,
};

};  // end SBE

#endif
