/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCommon.H $                    */
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
#include <hwas/common/hwasError.H>
#include <hwas/common/hwasCallout.H>

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
 * @brief platform specific code to determine whether the System is at runtime.
 *
 * @return bool  Return true if the System is at runtime; false if not.
 */

bool platSystemIsAtRuntime();

/**
 * @brief platform specific code to determine if minimum hardware
 * check is allowed.
 *
 * @param[out] o_minHwCheckingAllowed   boolean:
 *             TRUE if minimum hardware checking is allowed
 *             FALSE if minimum hardware checking is not allowed
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platIsMinHwCheckingAllowed(bool &o_minHwCheckingAllowed);

/**
 * @brief platform specific code to determine if the targets in the
 *  input list are present or not. If a target is NOT present, it is erased
 *  from the list
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
 * @param[in]  i_target    target to read the Partial Good keyword from
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
// all good - 0:PRV, 1:NET, 2:PIB, 3:OCC, 7:PLL, 8:OSCSW - 0xF180
const uint32_t VPD_CP00_PG_PERVASIVE_GOOD   = 0xF180;

const uint32_t VPD_CP00_PG_POWERBUS_INDEX   = 2;
// all good - 0:PRV, 1:PB, 2:NX, 3:PCIS, 4:MCL, 5:MCR - 0xFC00
//     base - 0:PRV, 1:PB, 2:NX, 3:PCIS               - 0xF000
//     MCL - mcs-[0..3]                               - 0x0800
//     MCR - mcs-[4..7]                               - 0x0400
const uint32_t VPD_CP00_PG_POWERBUS_BASE    = 0xF000;
const uint32_t VPD_CP00_PG_POWERBUS_MCL     = 0x0800;
const uint32_t VPD_CP00_PG_POWERBUS_MCR     = 0x0400;

const uint32_t VPD_CP00_PG_XBUS_INDEX       = 4;
// all good - 0:PRV, 1:IOX, 2:IOPCI, 3:XH - 0xF000
const uint32_t VPD_CP00_PG_XBUS_GOOD        = 0xF000;

const uint32_t VPD_CP00_PG_ABUS_INDEX       = 8;
// all good - 0:PRV, 1:AB, 2:IOA, 7:PLL - 0xE100
const uint32_t VPD_CP00_PG_ABUS_GOOD        = 0xE100;

const uint32_t VPD_CP00_PG_PCIE_INDEX       = 9;
// all good - 0:PRV, 1:PCI0, 2:PCI1, 3:PCI2, 5:IOPCI, 6:PBF, 7:PLL - 0xF700
const uint32_t VPD_CP00_PG_PCIE_GOOD        = 0xF700;

const uint32_t VPD_CP00_PG_EX0_INDEX        = 16;
// all good - 0:PRV, 1:rC, 2:L2, 3:L3NP, 6:REFR, 7:DPLL - 0xF300
const uint32_t VPD_CP00_PG_EX0_GOOD         = 0xF300;

/**
 * @brief platform specific code to determine the PR vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is reponsible for allocating and de-allocating the space.
 *
 * @param[in]  i_target    target to read the PR keyword from
 * @param[out] o_prData    pointer to area that will hold the PR keyword
 *                          read from VPD; must be malloc'ed by the caller,
 *                          and must be VPD_CP00_PR_DATA_LENGTH in size.
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platReadPR(const TARGETING::TargetHandle_t &i_target,
                                void *o_prData);

// constants the platReadPR will use for looking at the VPD data
const uint32_t VPD_VINI_PR_DATA_LENGTH      = 8;

// Byte 2 Number of processors per module chip
const uint32_t VPD_VINI_PR_B2_MASK          = 0xF0; // bits 0-3
const uint32_t VPD_VINI_PR_B2_SHIFT         = 4;
// Byte 7 Max VPD copies (aka replication factor)
// Bits 2:7
//   Number of chips using this VPD minus 1, i.e., Used to
//   calculate the maximum number of duplicate copies of the B9
//   keyword allowed. Multiply PR byte 2 (number of processor
//   per module) times this value [(PR byte 7) + 1] to get the max
//   number of copies of any given B9 keyword data in the SPIRA
//   PACA structure.
//   If the number of functional processors is different on chips
//   within the same module. It will be firmwares responsibility
//   average them out as specified in byte 2 above.
const uint32_t VPD_VINI_PR_B7_MASK          = 0x3F; // bits 2-7

/**
 * @brief platform specific code to read the Field Core Override
 *
 * @param[in]   i_node      node target, where the FCO is stored
 * @param[out]  o_fco       field core override value
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platGetFCO(
        const TARGETING::TargetHandle_t &i_node,
        uint32_t &o_fco);


/**
 * @brief platform specific code to get the address in PNOR to read
 *  and write GARD data
 *
 * @param[out] o_addr       pointer to where GARD data is in PNOR
 * @param[out] o_size       size (in bytes) of GARD data section in PNOR
 *
 * @return errlHndl_t       valid errlHndl_t handle if there was an error
 *                          NULL if no errors;
 */
errlHndl_t platGetGardPnorAddr(void *& o_addr,
                               uint64_t &o_size);

const uint32_t EMPTY_GARD_RECORDID=0xFFFFFFFF;
const uint32_t EMPTY_GARD_VALUE=0xFF;

/**
 * @brief wrapper function to create new errlog in platform-specific manner.
 *
 * @param[in] i_sev        Severity
 * @param[in] i_modId      Module ID   (from HwasModuleID enum)
 * @param[in] i_reasonCode Reason Code (from HwasReasonCode enum)
 * @param[in] i_user1      User Data 1 (defaults to zero)
 * @param[in] i_user2      User Data 2 (defaults to zero)
 *
 * @return errlHndl_t handle pointing to newly created error log
 */
errlHndl_t hwasError(const uint8_t i_sev,
                     const uint8_t i_modId,
                     const uint16_t i_reasonCode,
                     const uint64_t i_user1 = 0,
                     const uint64_t i_user2 = 0);

/**
 * @brief wrapper function to add a procedure callout to an error log in a
 *  platform-specific manner.
 *
 * @param[io] io_errl     Reference to error log handle. Updated with callout
 * @param[in] i_procedure Procedure to callout
 * @param[in] i_priority  Callout Priority
 */
void hwasErrorAddProcedureCallout(errlHndl_t & io_errl,
                                  const HWAS::epubProcedureID i_procedure,
                                  const HWAS::callOutPriority i_priority);

/**
 * @brief wrapper function to update the plid in a platform-specific manner.
 *
 * If io_plid is non-zero then io_errl is updated with io_plid
 * Else io_plid is updated with the plid in io_errl
 *
 * @param[io] io_errl Reference to error log handle.
 * @param[io] io_plid Reference to plid.
 */
void hwasErrorUpdatePlid(errlHndl_t & io_errl,
                         uint32_t & io_plid);

/**
 * @brief Platform-specific checks for minimum hardware.
 *  Verifies that the system has enough hardware to proceed through
 *  the IPL. If it does not, error log(s) will be created and committed
 *  for each problem.
 *
 * If io_plid is non-zero then any newly created Error Logs use io_plid
 * Else io_plid is updated with the plid used in the newly created Error Logs
 *
 * @param[io] io_plid Reference to plid.
 */
void platCheckMinimumHardware(uint32_t & io_plid);

} // namespace HWAS

#endif // HWASCOMMON_H_
