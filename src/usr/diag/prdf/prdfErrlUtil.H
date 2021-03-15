/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfErrlUtil.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2021                        */
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

#ifndef __prdfErrlUtil_H
#define __prdfErrlUtil_H

/**
 * @file  prdfErrlUtil.H
 * @brief PRD error logging code specific to hostboot.
 *
 * This file contains the Processor Runtime Diagnostics error logging
 * related declarations specific to hostboot.
 */

#include <errlentry.H>

#include <prdfEnums.H>
#include <prdfRasServices.H>

/**
 * @brief create ErrlEntry in Hostboot
 */
/* This macro does not use the below FSP input parms:

   - i_etype    : errlEventType
   - i_type     : srciType
   - i_srcAttr  : srcAttr
   - i_refCode  : serviceCodes
*/
#define  PRDF_CREATE_ERRL(io_errl, i_sev, i_etype, i_type,            \
                          i_srcAttr, i_mid, i_refCode, i_reasonCode,  \
                          i_user1 ,  i_user2,  i_user3 ,  i_user4)    \
    io_errl = new ERRORLOG::ErrlEntry(ERRORLOG::i_sev,             \
                                      i_mid,                       \
                                      i_reasonCode,                \
                                      PRDF_GET_UINT64_FROM_UINT32( \
                                      i_user1,                     \
                                      i_user2),                    \
                                      PRDF_GET_UINT64_FROM_UINT32( \
                                      i_user3,                     \
                                      i_user4))

/**
 * @brief Add user data to the log
 */
#define PRDF_ADD_FFDC(io_errl, i_buf, i_size, i_ver, i_subsec) \
    io_errl->addFFDC(PRDF_COMP_ID, i_buf, i_size, i_ver, i_subsec)

/**
 * @brief Set eLog severity
 */
#define PRDF_SET_ERRL_SEV(io_errl, i_sev) \
    io_errl->setSev(ERRORLOG::i_sev)

/**
 * @brief Commit the log
 */
// NOTE: Hostboot error log commit function does not need the action flag
#define PRDF_COMMIT_ERRL(io_errl, i_actions) { \
    errlHndl_t globalErrl = \
                ServiceGeneratorClass::ThisServiceGenerator().getErrl(); \
    if( nullptr != globalErrl ) io_errl->plid( globalErrl->plid() ); \
    uint64_t l_d1 = io_errl->getUserData1();                      \
    uint64_t l_d2 = io_errl->getUserData2();                      \
    TRACFCOMP( PRDF::traceDesc,"SRC 16:19  %16llx %16llx",        \
               l_d1, l_d2 );                                      \
    if( 0 != (i_actions) ) {} \
    errlCommit(io_errl, PRDF_COMP_ID); }

/**
 * @brief Collect component trace
 */
#define PRDF_COLLECT_TRACE(io_errl, i_max) \
    io_errl->collectTrace(PRDF_COMP_NAME, i_max); \
    io_errl->collectTrace(ATTN_COMP_NAME, i_max)

/**
 * @brief Add a procedure ( software ) callout
 */
#define PRDF_ADD_PROCEDURE_CALLOUT(io_errl, i_priority, i_procedure) \
    io_errl->addProcedureCallout((const HWAS::epubProcedureID)i_procedure, \
                                 (const HWAS::callOutPriority)i_priority)

/**
 * @brief Adds a software section to the log
 * mostly used as a stack call indicator
 */
// NOTE: hberrl doesn't support this so make it a no-op.
#define PRDF_ADD_SW_ERR(io_errl, i_rc, i_fileId, i_codeloc)

/**
 * @brief Get the platform Log Id
 */
#define PRDF_GET_PLID(io_errl, o_plid) \
    o_plid = io_errl->plid()

/**
 * @brief Set 32 bit user defined return code
 */
// NOTE: hberrl doesn't support this so make it a no-op.
#define PRDF_SET_RC(io_errl, i_rc)

/**
 * @brief Get 32 bit user defined return code
 */
// NOTE: hberrl doesn't support this so make it a no-op.
#define PRDF_GET_RC(io_errl, i_rc)

/**
 * @brief Get reason code
 */
#define PRDF_GET_REASONCODE(io_errl, o_reasonCode) \
    o_reasonCode = io_errl->reasonCode()

/**
 * @brief Determine if the src is terminating
 */
// NOTE: hberrl doesn't support this so make it a no-op.
#define PRDF_GET_TERM_SRC(io_errl, o_termSRC)

/**
 * @brief write SRC termination flag
 */
// NOTE: hberrl doesn't support this so make it a no-op.
#define PRDF_SRC_WRITE_TERM_STATE_ON(io_errl, i_flags)

// end Singleton macros

/*--------------------------------------------------------------------*/
/*  HW Deconfig Errl macros for Hostboot                              */
/*--------------------------------------------------------------------*/

/**
 * @brief Add a procedure callout to an existing error log
 */
#define PRDF_HW_ADD_PROC_CALLOUT(i_procedure,   \
                                 i_priority,    \
                                 io_errl,       \
                                 i_severity)    \
  PRDF_ADD_PROCEDURE_CALLOUT(io_errl, i_priority, i_procedure)

/**
 * @brief Error log interface to add a HW callout to an existing error log.
 * @note  convert immediate deconfig to delayed deconfig in HB.
 */
#define PRDF_HW_ADD_CALLOUT(i_target, i_priority,         \
                            i_deconfigState,              \
                            io_errl, i_gardErrType,       \
                            i_severity, i_diag_need)      \
  io_errl->addHwCallout(i_target,                                    \
                        (const HWAS::callOutPriority)i_priority,     \
                        i_deconfigState,                             \
                        (const HWAS::GARD_ErrorType)i_gardErrType);  \
  (void)(i_diag_need)

/**
 * @brief Add clock callout
 */
#define PRDF_ADD_CLOCK_CALLOUT(io_errl, i_target, i_clockType, i_priority, \
                               i_deconfigState, i_gardErrType)             \
    io_errl->addClockCallout(i_target,                          \
                             i_clockType,                       \
                (const HWAS::callOutPriority)i_priority,        \
                i_deconfigState,                                \
                i_gardErrType);

/**
 * @brief Process's pending deconfig and GARD service actions
 *        and thencommits and deletes the error log.
 */
#define PRDF_HW_COMMIT_ERRL(io_errl, i_action) \
  PRDF_COMMIT_ERRL(io_errl, i_action);

/**
 * @brief  indicate whether an abort is active or not
 */
// no-op in Hostboot
#define PRDF_ABORTING(o_abort) \
  o_abort = false;

/**
 * @brief Interface to indicate errlog that hostboot need to do a
 *        soft terminate.
 */
#define PRDF_SET_TERM_STATE( i_errl ) \
  i_errl->setTermState( ERRORLOG::TERM_STATE_SOFT )

#endif // __prdfErrlUtil_H
