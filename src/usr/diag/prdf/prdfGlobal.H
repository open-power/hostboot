/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/prdf/prdfGlobal.H $                              */
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

#ifndef PRDF_GLOBAL_HB_H
#define PRDF_GLOBAL_HB_H

/**
 * @file  prdfGlobal.H
 * @brief PRD global code specific to hostboot.
 *
 * This file contains the Processor Runtime Diagnostics global variable
 * and type declarations specific to hostboot.
 */

/*--------------------------------------------------------------------*/
/*  Includes                                                          */
/*--------------------------------------------------------------------*/
#include <prdfGlobal_common.H>
#include <util/singleton.H>

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

#define PRDF_DECLARE_SINGLETON(__T__,__NAME__) \
    typedef Singleton<__T__> __NAME__


#define PRDF_GET_SINGLETON(__TYPE__) \
    __TYPE__::instance()

// end Singleton macros

/**
 * @brief Interface to deconfig target at Runtime (Not valid in Hostboot)
 */
// FIXME:RTC: 65609 will address this issue.
// need to implement in Hostboot
#define PRDF_RUNTIME_DECONFIG( i_pTarget, i_errl ) \
  SUCCESS

/**
 * @brief macro to acquire scope lock on system target
 *        This macro is currently not used in hostboot.
 */
#define PRDF_SYSTEM_SCOPELOCK

#endif // PRDF_GLOBAL_HB_H
