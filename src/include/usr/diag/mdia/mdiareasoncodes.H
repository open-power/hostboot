/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/mdia/mdiareasoncodes.H $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
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
/**
 * @file mdiareasoncodes.H
 *
 * @brief Reason codes and module ids for memory diagnostics
 *
 */
#ifndef __MDIA_MDIAREASONCODES_H
#define __MDIA_MDIAREASONCODES_H

#include <hbotcompid.H>

namespace MDIA
{

/**
* @enum Moduleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum ModuleId
{
    INVALID_MODULE                  = 0x00,
    PROCESS_COMMAND_TIMEOUT         = 0x01,
};

/**
 * @enum ReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum ReasonCode
{
    INVALID_REASONCODE           = MDIA_COMP_ID | 0x00,   // Invalid Reasoncode
    MAINT_COMMAND_TIMED_OUT      = MDIA_COMP_ID | 0x01,
};

}
#endif
