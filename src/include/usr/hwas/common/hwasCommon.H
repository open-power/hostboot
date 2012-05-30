/*  IBM_PROLOG_BEGIN_TAG
 *  This is an automatically generated prolog.
 *
 *  $Source: src/include/usr/hwas/common/hwasCommon.H $
 *
 *  IBM CONFIDENTIAL
 *
 *  COPYRIGHT International Business Machines Corp. 2012
 *
 *  p1
 *
 *  Object Code Only (OCO) source materials
 *  Licensed Internal Code Source Materials
 *  IBM HostBoot Licensed Internal Code
 *
 *  The source code for this program is not published or other-
 *  wise divested of its trade secrets, irrespective of what has
 *  been deposited with the U.S. Copyright Office.
 *
 *  Origin: 30
 *
 *  IBM_PROLOG_END_TAG
 */
/**
 *  @file hwasCommon.H
 *
 *  @brief Notes the HWAS common functions and the HWAS platform-specific
 *          interfaces that need to be defined and implemented.
 */

#ifndef HWASCOMMON_H_
#define HWASCOMMON_H_

// 'system' headers
#include <stdint.h>
#include <targeting/common/target.H>
#include <targeting/common/targetservice.H>

// platform specific headers

// following file needs to do
//  #define HWAS_DBG(_fmt_, _args_...)
//  #define HWAS_ERR(_fmt_, _args_...)
#include <hwas/hwasPlatTrace.H>

// following file needs to do
//  #define HWAS_ASSERT(_expr_...)
#include <hwas/hwasPlatAssert.H>

namespace HWAS
{

/**
 * @brief platform specific code to determine if the targets in the
 *  input list are present or not. If the target is NOT present,
 *  target should be erased from the list
 *
 * @param[in]  io_targets   TargetHandleList of targets to check for presence
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platPresenceDetect(TARGETING::TargetHandleList &io_targets);

/**
 * @brief platform specific code to determine the ID/EC of the input
 *  target. The platform specific code is responsible for setting the
 *  ATTR_EC and ATTR_CHIP_ID in each target.
 *
 * @param[in]  i_target    target to check for chip ID/EC
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadIDEC(const TARGETING::TargetHandle_t &i_target);

} // namespace HWAS

#endif // HWASCOMMON_H_
