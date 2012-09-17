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

/**
 * @brief platform specific code to determine the PG vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is reponsible for allocating and de-allocating the space.
 *
 * @param[in]  i_target    target to check for chip ID/EC
 * @param[out] o_pgData    pointer to area that will hold the partialGood vector
 *                          read from VPD; must be malloc'ed by the caller,
 *                          and must be VPD_CP00_PG_DATA_LENGTH in size.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadPartialGood(const TARGETING::TargetHandle_t &i_target,
                                void *o_pgData);

// constants the platReadPartialGood will use for looking at the VPD data
const uint32_t VPD_CP00_PG_DATA_LENGTH      = 64;
const uint32_t VPD_CP00_PG_HDR_LENGTH       = 1;

// components of the partial good vector
const uint32_t VPD_CP00_PG_PIB_INDEX        = 0;
const uint32_t VPD_CP00_PG_PIB_GOOD         = 0x0000;

const uint32_t VPD_CP00_PG_PERVASIVE_INDEX  = 1;
const uint32_t VPD_CP00_PG_PERVASIVE_GOOD   = 0xF180;

const uint32_t VPD_CP00_PG_POWERBUS_INDEX   = 2;
const uint32_t VPD_CP00_PG_POWERBUS_GOOD    = 0xFC00;

const uint32_t VPD_CP00_PG_XBUS_INDEX       = 4;
const uint32_t VPD_CP00_PG_XBUS_GOOD        = 0xF000;

const uint32_t VPD_CP00_PG_ABUS_INDEX       = 8;
const uint32_t VPD_CP00_PG_ABUS_GOOD        = 0xE100;

const uint32_t VPD_CP00_PG_PCIE_INDEX       = 9;
const uint32_t VPD_CP00_PG_PCIE_GOOD        = 0xF700;

const uint32_t VPD_CP00_PG_EX0_INDEX        = 16;
const uint32_t VPD_CP00_PG_EX0_GOOD         = 0xF300;


} // namespace HWAS

#endif // HWASCOMMON_H_
