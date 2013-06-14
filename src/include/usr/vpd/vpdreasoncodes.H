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
#ifndef __VPDREASONCODES_H
#define __VPDREASONCODES_H

// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace VPD
{

/**
* @enum vpdModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum vpdModuleId
{
    VPD_INVALID_MODULE                      = 0x00,

    // Common VPD

    // IPVPD
    VPD_IPVPD_TRANSLATE_RECORD              = 0x20,
    VPD_IPVPD_TRANSLATE_KEYWORD             = 0x21,
    VPD_IPVPD_FIND_RECORD_OFFSET            = 0x22,
    VPD_IPVPD_FIND_KEYWORD_ADDR             = 0x23,
    VPD_IPVPD_CHECK_BUFFER_SIZE             = 0x24,


    // DIMM SPD
    VPD_SPD_GET_KEYWORD_VALUE               = 0x61,
    VPD_SPD_GET_VALUE                       = 0x62,
    VPD_SPD_CHECK_SIZE                      = 0x63,
    VPD_SPD_READ_BINARY_FILE                = 0x64,
    VPD_SPD_WRITE_KEYWORD_VALUE             = 0x65,
    VPD_SPD_SPECIAL_CASES                   = 0x66,
    VPD_SPD_DDR3_SPECIAL_CASES              = 0x67,
    VPD_SPD_DDR4_SPECIAL_CASES              = 0x68,
    VPD_SPD_PRESENCE_DETECT                 = 0x69,
    VPD_SPD_CHECK_MODULE_SPECIFIC_KEYWORD   = 0x6A,
    VPD_SPD_WRITE_VALUE                     = 0x6B,
    VPD_SPD_GET_KEYWORD_ENTRY               = 0x6C,
    VPD_SPD_WRITE_DATA                      = 0x6D,
    VPD_SPD_GET_MOD_TYPE                    = 0x6E,

    // Centaur FRU VPD

};

/**
 * @enum vpdReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum vpdReasonCode
{
    VPD_INVALID_REASONCODE              = VPD_COMP_ID | 0x00,   // Invalid RC
    VPD_INSUFFICIENT_FILE_SIZE          = VPD_COMP_ID | 0x01,
    VPD_OPERATION_NOT_SUPPORTED         = VPD_COMP_ID | 0x02,
    VPD_RECORD_NOT_FOUND                = VPD_COMP_ID | 0x03,
    VPD_KEYWORD_NOT_FOUND               = VPD_COMP_ID | 0x04,
    VPD_RECORD_MISMATCH                 = VPD_COMP_ID | 0x05,
    VPD_INSUFFICIENT_BUFFER_SIZE        = VPD_COMP_ID | 0x06,
    VPD_INVALID_BASIC_MEMORY_TYPE       = VPD_COMP_ID | 0x07,
    VPD_BASIC_MEMORY_TYPE               = VPD_COMP_ID | 0x08,
    VPD_INVALID_SPD_KEYWORD             = VPD_COMP_ID | 0x09,
    VPD_MEMTYPE_NOT_SUPPORTED           = VPD_COMP_ID | 0x0A,
    VPD_KEYWORD_NOT_WRITABLE            = VPD_COMP_ID | 0x0B,
    VPD_NOT_SUPPORTED                   = VPD_COMP_ID | 0x0C,
    VPD_MOD_SPECIFIC_MISMATCH_UMM       = VPD_COMP_ID | 0x0D,
    VPD_MOD_SPECIFIC_MISMATCH_RMM       = VPD_COMP_ID | 0x0E,
    VPD_MOD_SPECIFIC_MISMATCH_CMM       = VPD_COMP_ID | 0x0F,
    VPD_MOD_SPECIFIC_MISMATCH_LRMM      = VPD_COMP_ID | 0x10,
    VPD_MOD_SPECIFIC_UNSUPPORTED        = VPD_COMP_ID | 0x11,
    VPD_SIZE_MISMATCH                   = VPD_COMP_ID | 0x12,
    VPD_INVALID_WRITE_METHOD            = VPD_COMP_ID | 0x13,
    VPD_NULL_ENTRY                      = VPD_COMP_ID | 0x14,
    VPD_UNSUPPORTED_WRITE               = VPD_COMP_ID | 0x15,
};

};  // end MVPD

#endif
