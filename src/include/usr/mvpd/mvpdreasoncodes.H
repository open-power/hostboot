//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/mvpd/mvpdreasoncodes.H $
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
 * @file mvpdreasoncodes.H
 *
 * @brief Reason codes and module ids for the MVPD device driver
 *
 */
#ifndef __MVPDREASONCODES_H
#define __MVPDREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace MVPD
{

/**
* @enum mvpdModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum mvpdModuleId
{
    MVPD_INVALID_MODULE                 = 0x00,
    MVPD_READ_BINARY_FILE               = 0x01,
    MVPD_READ                           = 0x02,
    MVPD_WRITE                          = 0x03,
    MVPD_TRANSLATE_RECORD               = 0x04,
    MVPD_TRANSLATE_KEYWORD              = 0x05,
    MVPD_FIND_RECORD_OFFSET             = 0x06,
    MVPD_RETRIEVE_KEYWORD               = 0x07,
    MVPD_FETCH_DATA                     = 0x08,
    MVPD_CHECK_BUFFER_SIZE              = 0x09,
};

/**
 * @enum mvpdReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum mvpdReasonCode
{
    MVPD_INVALID_REASONCODE             = MVPD_COMP_ID | 0x00,   // Invalid Reasoncode
    MVPD_INSUFFICIENT_FILE_SIZE         = MVPD_COMP_ID | 0x01,
    MVPD_OPERATION_NOT_SUPPORTED        = MVPD_COMP_ID | 0x02,
    MVPD_RECORD_NOT_FOUND               = MVPD_COMP_ID | 0x03,
    MVPD_KEYWORD_NOT_FOUND              = MVPD_COMP_ID | 0x04,
    MVPD_RECORD_MISMATCH                = MVPD_COMP_ID | 0x05,
    MVPD_INSUFFICIENT_BUFFER_SIZE       = MVPD_COMP_ID | 0x06,
};

};  // end MVPD

#endif
