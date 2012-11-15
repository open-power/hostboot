/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/common/iipglobl.h $                         */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2002,2012              */
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

#ifndef IIPGLOBL_H
#define IIPGLOBL_H

/* Module Description *************************************************/
/*                                                                    */
/*  Name:  iipglobl.h                                                 */
/*                                                                    */
/*  Description:  This module contains the Processor Runtime
                  Diagnostics global variable and type declarations.  */
/*                                                                    */
/* End Module Description *********************************************/

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/

#ifdef __HOSTBOOT_MODULE
  #include <errl/errlmanager.H>
  #include <util/singleton.H>
#else
  #include <errlentry.H>
  #include <hwsvSvrErrl.H>
  #include <utilsingleton.H>
  // FIXME: uncomment dump include when Adriana's fix is in
  //#include <dumpHWURequest_applet.H>
#endif

#include <prdfTrace.H>
#include <prdf_types.h>
#include <prdfErrlSmartPtr.H>

/*--------------------------------------------------------------------*/
/*  Forward References                                                */
/*--------------------------------------------------------------------*/

class System;

/*--------------------------------------------------------------------*/
/*  Global Variables                                                  */
/*--------------------------------------------------------------------*/

namespace PRDF
{
  extern System * systemPtr;
  extern PrdfErrlSmartPtr g_prd_errlHndl;
}

/*--------------------------------------------------------------------*/
/*  Singleton macros common to both FSP and Hostboot                  */
/*--------------------------------------------------------------------*/
/**
 *  @brief common singleton declaration to specific platform
 *
 *  @param[in] __T__
 *      Type of singleton, fully namespaced
 *
 *  @param[in] __NAME__
 *      Symbol name for singleton
 */

/**
 *  @brief common singleton "getter" to the specific platform
 *
 *  @param[in] __TYPE__
 *      Typedef for singleton, as created above
 *
 *  @return Singleton reference for the given singleton
 */

// ----------- Hostboot macros begin -----------
#ifdef  __HOSTBOOT_MODULE

#define PRDF_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__


#define PRDF_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

// ----------- FSP macros begin -----------
#else

#define PRDF_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef util::SingletonHolder<__T__> __NAME__

#define PRDF_GET_SINGLETON(__TYPE__) \
    __TYPE__::Instance()

#endif
// end Singleton macros

/*--------------------------------------------------------------------*/
/*  Errl macros common to both FSP and Hostboot                      */
/*--------------------------------------------------------------------*/

/**
 * @brief Convert any integer to uint64_t
 */
#define PRDF_GET_UINT64(x)    static_cast<uint64_t>(x)

/**
 * @brief store two uint32_t to uint64_t
 */
#define PRDF_GET_UINT64_FROM_UINT32(l_32, r_32) \
            ( (PRDF_GET_UINT64(l_32) << 32) | PRDF_GET_UINT64(r_32) )

// ----------- Hostboot macros begin -----------
#ifdef  __HOSTBOOT_MODULE

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
// FIXME: hberr does not use i_actions for commit
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
// FIXME: hberrl hasn't added this in yet so make it a no-op for now
#define PRDF_ADD_SW_ERR(io_errl, i_rc, i_fileId, i_codeloc)

/**
 * @brief Set the platform Log Id
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_SET_PLID(io_errl, i_plid)

/**
 * @brief Get the platform Log Id
 */
#define PRDF_GET_PLID(io_errl, o_plid) \
    o_plid = io_errl->plid()

/**
 * @brief Set 32 bit user defined return code
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_SET_RC(io_errl, i_rc)

/**
 * @brief Get 32 bit user defined return code
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_GET_RC(io_errl, o_rc)

/**
 * @brief Get reason code
 */
#define PRDF_GET_REASONCODE(io_errl, o_reasonCode) \
    o_reasonCode = io_errl->reasonCode()

/**
 * @brief get previously stored SRC
 *        A special index ( 0 ) is used to a
 *        ccess the primary src.
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_GET_SRC(io_errl, o_src, i_idx)

/**
 * @brief Determine if the src is terminating
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_GET_TERM_SRC(io_errl, o_termSRC)

/**
 * @brief write SRC termination flag
 */
// FIXME: hberrl doesn't have this setter method so make it a no-op for now
#define PRDF_SRC_WRITE_TERM_STATE_ON(io_errl, i_flags)


// ----------- Hostboot macros end   -----------

// ----------- FSP macros begin -----------
#else

/**
 * @brief create ErrlEntry in FSP
 */
#define  PRDF_CREATE_ERRL(io_errl, i_sev, i_etype, i_type,            \
                          i_srcAttr, i_mid, i_refCode, i_reasonCode,  \
                          i_user1 ,  i_user2,  i_user3 ,  i_user4)    \
    io_errl = new ErrlEntry(PRDF_COMP_ID,  \
                            i_sev,         \
                            i_etype,       \
                            i_type,        \
                            i_srcAttr,     \
                            i_mid,         \
                            i_refCode,     \
                            i_reasonCode,  \
                            i_user1,       \
                            i_user2,       \
                            i_user3,       \
                            i_user4,       \
                            EPUB_FIRMWARE_SP)

/**
 * @brief Add user data to the log
 */
#define PRDF_ADD_FFDC(io_errl, i_buf, i_size, i_ver, i_subsec) \
    io_errl->addUsrDtls(i_buf, i_size, PRDF_COMP_ID, i_ver, i_subsec)

/**
 * @brief Commit the log
 */
#define PRDF_COMMIT_ERRL(io_errl, i_actions)  \
    io_errl->commit(PRDF_COMP_ID, i_actions); \
    delete io_errl; io_errl=NULL;

/**
 * @brief Collect component trace
 */
#define PRDF_COLLECT_TRACE(io_errl, i_max) \
    io_errl->CollectTrace(PRDF_COMP_NAME, i_max)

/**
 * @brief Add a procedure ( software ) callout
 */
#define PRDF_ADD_PROCEDURE_CALLOUT(io_errl, i_priority, i_procedure) \
    io_errl->addProcedureCallout(i_priority, i_procedure)

/**
 * @brief Adds a software section to the log
 *        mostly used as a stack call indicator
 */
#define PRDF_ADD_SW_ERR(io_errl, i_rc, i_fileId, i_codeloc) \
    io_errl->addSwErr(PRDF_COMP_ID, i_rc, i_fileId, i_codeloc)

/**
 * @brief Set the platform Log Id
 */
#define PRDF_SET_PLID(io_errl, i_plid) \
    io_errl->plid(i_plid)

/**
 * @brief Get the platform Log Id
 */
#define PRDF_GET_PLID(io_errl, o_plid) \
    o_plid = io_errl->plid()

/**
 * @brief Set 32 bit user defined return code
 */
#define PRDF_SET_RC(io_errl, i_rc) \
    io_errl->setRC(i_rc)

/**
 * @brief Get 32 bit user defined return code
 */
#define PRDF_GET_RC(io_errl, o_rc) \
    o_rc = io_errl->getRC()

/**
 * @brief Get reason code
 */
#define PRDF_GET_REASONCODE(io_errl, o_reasonCode) \
    o_reasonCode = io_errl->getSRC() == NULL ? 0 : \
                   io_errl->getSRC()->reasonCode()

/**
 * @brief get previously stored SRC
 *        A special index ( 0 ) is used to a
 *        ccess the primary src.
 */
#define PRDF_GET_SRC(io_errl, o_src, i_idx) \
    o_src = io_errl->getSRC(i_idx)

/**
 * @brief Determine if the src is terminating
 */
#define PRDF_GET_TERM_SRC(io_errl, o_termSRC) \
    o_termSRC = io_errl->getSRC()->isTerminateSRC()

/**
 * @brief write SRC termination flag
 */
#define PRDF_SRC_WRITE_TERM_STATE_ON(io_errl, i_flags) \
    io_errl->getSRC()->writeTermState_ON(i_flags)


// ----------- FSP macros end   -----------
#endif


/*--------------------------------------------------------------------*/
/*  HW Deconfig Errl macros common to both FSP and Hostboot           */
/*--------------------------------------------------------------------*/

// FIXME: defines for enums that are not available in hostboot
#ifdef  __HOSTBOOT_MODULE

// FIXME: these ERRL sevs are currently not supported in HB
#define ERRL_SEV_PREDICTIVE          ERRL_SEV_UNRECOVERABLE
#define ERRL_SEV_DIAGNOSTIC_ERROR1   ERRL_SEV_UNRECOVERABLE
#define ERRL_SEV_RECOVERED           ERRL_SEV_INFORMATIONAL

#include <prdfEnums.H>

#endif

// ----------- Hostboot macros begin -----------
#ifdef  __HOSTBOOT_MODULE

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
 */
#define PRDF_HW_ADD_CALLOUT(io_sysTerm, i_target, i_priority,         \
                            i_deconfigState, i_gardState,             \
                            io_errl, i_writeVpd,                      \
                            i_gardErrType, i_severity, i_hcdb_update) \
  io_errl->addHwCallout(i_target,                                    \
                        (const HWAS::callOutPriority)i_priority,     \
                        (const HWAS::DeconfigEnum)i_deconfigState,   \
                        (const HWAS::GARD_ErrorType)i_gardErrType)

/**
 * @brief Error log interface to add a HW callout to an existing error log.
 */
// FIXME - will need to implement later
#define PRDF_HW_ADD_MEMMRU_CALLOUT(io_sysTerm, i_memMRU, i_priority,         \
                                   i_deconfigState, i_gardState,             \
                                   io_errl, i_writeVpd,                    \
                                   i_gardErrType, i_severity, i_hcdb_update)

/**
 * @brief Process's pending deconfig and GARD service actions
 *        and thencommits and deletes the error log.
 */
#define PRDF_HW_COMMIT_ERRL(io_sysTerm, io_errl, i_deferDeconfig, \
                            i_action, i_continue)                 \
  io_sysTerm = false;  \
  PRDF_COMMIT_ERRL(io_errl, i_action);

/**
 * @brief  indicate whether an abort is active or not
 */
// FIXME - not available in Hostboot?
#define PRDF_ABORTING(o_abort) \
  o_abort = false;

/**
 * @brief Interface to request a Hardware Unit dump collection
 */
// FIXME - need to implement in Hostboot
#define PRDF_HWUDUMP(io_dumpErrl, i_errl,   \
                     i_content, i_dumpHuid)

/**
 * @brief Interface to deconfig target at Runtime (Not valid in Hostboot)
 */
#define PRDF_RUNTIME_DECONFIG(io_errl, i_pTarget)

// ----------- Hostboot macros end   -----------

// ----------- FSP macros begin -----------
#else

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
  HWSV::SvrError::Elog(io_errl,      \
                       (const uint8_t)i_mid, \
                       i_reasonCode, \
                       PRDF_COMP_ID, \
                       i_userData1,  \
                       i_userData2,  \
                       i_userData3,  \
                       i_userData4,  \
                       (const HWSV::homTermEnum)i_termFlag, \
                       i_pldCheck)

/**
 * @brief Add a procedure callout to an existing error log
 */
#define PRDF_HW_ADD_PROC_CALLOUT(i_procedure, \
                                 i_priority,  \
                                 io_errl,   \
                                 i_severity)  \
  HWSV::SvrError::AddProcedureCallout((const epubProcedureID)i_procedure, \
                                      (const srciPriority)i_priority,     \
                                      io_errl,     \
                                      i_severity)

/**
 * @brief Error log interface to add a HW callout to an existing error log.
 */
#define PRDF_HW_ADD_CALLOUT(io_sysTerm, i_target, i_priority,           \
                            i_deconfigState, i_gardState,             \
                            io_errl, i_writeVpd,                    \
                            i_gardErrType, i_severity, i_hcdb_update) \
  io_sysTerm = HWSV::SvrError::AddHwCallout((HWSV::HUID)PlatServices::getHuid(i_target),  \
                                            (srciPriority)i_priority,                     \
                                            (const HWSV::homDeconfigEnum)i_deconfigState, \
                                            (const HWSV::homGardEnum)i_gardState,         \
                                            io_errl,          \
                                            i_gardErrType,      \
                                            i_severity,         \
                                            (homHCDBUpdate)i_hcdb_update)

/**
 * @brief Error log interface to add a HW callout to an existing error log.
 */
// FIXME - will need to implement later
#define PRDF_HW_ADD_MEMMRU_CALLOUT(io_sysTerm, i_memMRU, i_priority, \
                                   i_deconfigState, i_gardState,     \
                                   io_errl, i_writeVpd,            \
                                   i_gardErrType, i_severity, i_hcdb_update)

/**
 * @brief Process's pending deconfig and GARD service actions
 *        and thencommits and deletes the error log.
 */
#define PRDF_HW_COMMIT_ERRL(io_sysTerm, io_errl, i_deferDeconfig, \
                            i_action, i_continue)                 \
  io_sysTerm = HWSV::SvrError::CommitErrl(PRDF_COMP_ID,     \
                                          io_errl,          \
                                          i_deferDeconfig,  \
                                          i_action,         \
                                          i_continue)

/**
 * @brief  indicate whether an abort is active or not
 */
#define PRDF_ABORTING(o_abort) \
  o_abort = HWSV::theExecutionService::Instance().aborting()

/**
 * @brief Interface to request a Hardware Unit dump collection
 */
#define PRDF_HWUDUMP(io_dumpErrl, i_errl,   \
                     i_content, i_dumpHuid) \
  SrciSrc l_src(*(i_errl->getSRC(0)));          \
  io_dumpErrl= dumpHWURequestApplet( i_content, \
                                 PRDF_COMP_ID,  \
                                 i_errl->plid(),\
                                 l_src,         \
                                 i_dumpHuid );

/**
 * @brief Interface to deconfig target at Runtime
 */
#define PRDF_RUNTIME_DECONFIG( io_errl, i_target ) \
    io_errl = PlatServices::runtimeDeconfig( i_target );

// ----------- FSP macros end   -----------
#endif

#endif
