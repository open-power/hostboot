//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/include/usr/hwpf/plat/fapiPlatHwpInvoker.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2011
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
 *  @file fapiPlatHwpInvoker.H
 *
 *  @brief Defines the platform specific HW Procedure invoker functions.
 *
 *  Note that each platform needs to provide an invoker function for each HW
 *  procedure. Prototypes cannot be provided because each platform will have
 *  functions that take platform specific targets and return platform specific
 *  return codes.
 */

#ifndef FAPIPLATHWPINVOKER_H_
#define FAPIPLATHWPINVOKER_H_

#include <targeting/targetservice.H>
#include <errl/errlentry.H>

namespace fapi
{

/**
 * @brief Invokes hwpInitialTest procedure
 *
 * @param[in]  i_target   Pointer to Chip
 */
errlHndl_t invokeHwpInitialTest(TARGETING::Target* i_target);

/**
 * @brief Invokes hwpTestError procedure
 *
 * @param[in]  i_target   Pointer to Chip
 */
errlHndl_t invokeHwpTestError(TARGETING::Target* i_target);

}

#endif // FAPIPLATHWPINVOKER_H_
