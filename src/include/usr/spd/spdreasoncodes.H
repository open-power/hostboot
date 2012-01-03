//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/spd/spdreasoncodes.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
/**
 * @file spdreasoncodes.H
 *
 * @brief Reason codes and module ids for the SPD device driver
 *
 */
#ifndef __SPDREASONCODES_H
#define __SPDREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace SPD
{

/**
* @enum spdModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum spdModuleId
{
    SPD_INVALID_MODULE                  = 0x00,
    SPD_GET_KEYWORD_VALUE               = 0x01,
    SPD_GET_VALUE                       = 0x02,
    SPD_CHECK_SIZE                      = 0x03,
    SPD_READ_BINARY_FILE                = 0x04,
    SPD_WRITE_KEYWORD_VALUE             = 0x05,
    SPD_SPECIAL_CASES                   = 0x06,
    SPD_PRESENCE_DETECT                 = 0x07,
};

/**
 * @enum spdReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum spdReasonCode
{
    SPD_INVALID_REASONCODE              = SPD_COMP_ID | 0x00,   // Invalid Reasoncode
    SPD_INVALID_BASIC_MEMORY_TYPE       = SPD_COMP_ID | 0x01,
    SPD_BASIC_MEMORY_TYPE               = SPD_COMP_ID | 0x02,
    SPD_INVALID_SPD_KEYWORD             = SPD_COMP_ID | 0x03,
    SPD_MEMTYPE_NOT_SUPPORTED           = SPD_COMP_ID | 0x04,
    SPD_INSUFFICIENT_BUFFER_SIZE        = SPD_COMP_ID | 0x05,
    SPD_INSUFFICIENT_FILE_SIZE          = SPD_COMP_ID | 0x06,
    SPD_NOT_SUPPORTED                   = SPD_COMP_ID | 0x07,
    SPD_KEYWORD_NOT_FOUND               = SPD_COMP_ID | 0x08,
};

};  // end SPD

#endif
