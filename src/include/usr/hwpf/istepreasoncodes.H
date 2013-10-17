/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwpf/istepreasoncodes.H $                     */
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
 * @file istepreasoncodes.H
 *
 * @brief Reason codes and module ids for the isteps
 *
 */
#ifndef __ISTEPREASONCODES_H
#define __ISTEPREASONCODES_H
// -----------------------------------------------
// Includes
// -----------------------------------------------
#include <hbotcompid.H>

namespace ISTEP
{

/**
* @enum istepModuleid
*
* @brief Module Ids used in created errorlogs.  Indicates which
*      functions an error log was created in.
*
*/
enum istepModuleId
{
    ISTEP_INVALID_MODULE                                = 0x00,
    ISTEP_REPORTING_ERROR                               = 0x01,
    ISTEP_START_PAYLOAD_CALL_SHUTDOWN                   = 0x02,
    ISTEP_HOST_ACTIVATE_SLAVE_CORES                     = 0x03,
    ISTEP_BUILD_WINKLE_IMAGES                           = 0x04,
    ISTEP_PROC_SET_PORE_BAR                             = 0x05,
    ISTEP_HOST_ACTIVATE_MASTER                          = 0x06,
    ISTEP_SBE_CENTAUR_INIT                              = 0x07,
    ISTEP_INITSVC_MOD_ID                                = 0x08,
};

/**
 * @enum istepReasonCode
 *
 * @brief Reasoncodes used to describe what errors are being indicated.
 *
 */
enum istepReasonCode
{
    ISTEP_INVALID_REASONCODE                    = ISTEP_COMP_ID | 0x00,
    ISTEP_FAILURE                               = ISTEP_COMP_ID | 0x01,
    ISTEP_TARGET_NULL                           = ISTEP_COMP_ID | 0x02,
    ISTEP_BAD_RC                                = ISTEP_COMP_ID | 0x03,
    ISTEP_FAIL_MASTER_WINKLE_RC                 = ISTEP_COMP_ID | 0x04,
    ISTEP_MM_UNMAP_ERR                          = ISTEP_COMP_ID | 0x05,
    ISTEP_LOAD_SLW_FROM_PNOR_FAILED             = ISTEP_COMP_ID | 0x06,
    ISTEP_REPAIR_LOADER_RETRY_OCCURED           = ISTEP_COMP_ID | 0x07,
};  // end ISTEP

}
#endif
