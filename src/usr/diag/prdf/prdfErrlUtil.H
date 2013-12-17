/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfErrlUtil.H $                            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2014              */
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

#ifndef __prdfErrlUtil_H
#define __prdfErrlUtil_H

/**
 * @file  prdfErrlUtil.H
 * @brief PRD error logging code specific to hostboot.
 *
 * This file contains the Processor Runtime Diagnostics error logging
 * related declarations specific to hostboot.
 */

#include <prdfEnums.H>

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
 * @brief Commit the log
 */
// NOTE: Hostboot error log commit function does not need the action flag
#define PRDF_COMMIT_ERRL(io_errl, i_actions) \
    if(i_actions) {} \
    errlCommit(io_errl, PRDF_COMP_ID)

/**
 * @brief Collect component trace
 */
#define PRDF_COLLECT_TRACE(io_errl, i_max) \
    io_errl->collectTrace(PRDF_COMP_NAME, i_max)

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
 * @brief function to create an error log.
 */
#define  PRDF_HW_CREATE_ERRL(io_errl,      \
                             i_sev,        \
                             i_etype,      \
                             i_type,       \
                             i_srcAttr,    \
                             i_mid,        \
                             i_refCode,    \
                             i_reasonCode, \
                             i_userData1,  \
                             i_userData2,  \
                             i_userData3,  \
                             i_userData4,  \
                             i_termFlag,   \
                             i_pldCheck)   \
  PRDF_CREATE_ERRL(io_errl, i_sev, i_etype, i_type,            \
                   i_srcAttr, i_mid, i_refCode, i_reasonCode,  \
                   i_userData1, i_userData2, i_userData3, i_userData4)

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
                        (i_deconfigState == HWAS::DECONFIG ?         \
                        HWAS::DELAYED_DECONFIG : i_deconfigState),   \
                        (const HWAS::GARD_ErrorType)i_gardErrType);  \
  (void)(i_diag_need)

/**
 * @brief Add clock callout
 */
#define PRDF_ADD_CLOCK_CALLOUT(io_errl, i_target, i_clockType, i_priority) \
    io_errl->addClockCallout(i_target,                          \
                (PRDcalloutData::TYPE_PROCCLK == i_clockType) ? \
                 HWAS::OSCREFCLK_TYPE : HWAS::OSCPCICLK_TYPE,   \
                             (const HWAS::callOutPriority)i_priority);

/**
 * @brief Process's pending deconfig and GARD service actions
 *        and thencommits and deletes the error log.
 */
#define PRDF_HW_COMMIT_ERRL(io_errl, i_deferDeconfig, i_action) \
  PRDF_COMMIT_ERRL(io_errl, i_action);

/**
 * @brief  indicate whether an abort is active or not
 */
// no-op in Hostboot
#define PRDF_ABORTING(o_abort) \
  o_abort = false;

/**
 * @brief Interface to request a Hardware Unit dump collection
 */
// FIXME:RTC: 65609 will address this issue.
// need to implement in Hostboot
#define PRDF_HWUDUMP( i_errl, i_content, i_huid ) \
  SUCCESS


#endif // __prdfErrlUtil_H
