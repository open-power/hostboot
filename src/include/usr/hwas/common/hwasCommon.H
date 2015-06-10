/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/hwas/common/hwasCommon.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  vector. The caller is responsible for allocating and de-allocating the
 *  space.
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
const uint32_t VPD_CP00_PG_DATA_LENGTH      = 128;
const uint32_t VPD_CP00_PG_HDR_LENGTH       = 1;
const uint32_t VPD_CP00_PG_DATA_ENTRIES     = VPD_CP00_PG_DATA_LENGTH / 2;

// components of the partial good vector
// * = region does not exist in Nimbus
// + = partial good region
// '0' = region is good (NOTE: opposite of P8 where '1' represented good)
// '1' = region is bad or does not exist

const uint32_t VPD_CP00_PG_FSI_INDEX        = 0;
// all good - 4:FSI0, 5:FSI1, 6:FSIa
const uint32_t VPD_CP00_PG_FSI_GOOD         = 0xF1FF;

const uint32_t VPD_CP00_PG_PERVASIVE_INDEX  = 1;
// all good - 3:VITAL, 4:PRV, 5:NET, 6:PIB, 7:OCC, 8:ANPERV, 14:PLLNEST
const uint32_t VPD_CP00_PG_PERVASIVE_GOOD   = 0xE07D;

const uint32_t VPD_CP00_PG_N0_INDEX         = 2;
// all good - 3:VITAL, 4:PRV, 5:NX, 6:CXA0, 7:PBIOE0, 8:PBIOE1, 9:PBIOE2
const uint32_t VPD_CP00_PG_N0_GOOD          = 0xE03F;

const uint32_t VPD_CP00_PG_N1_INDEX         = 3;
// all good - 3:VITAL, 4:PRV, 5:MCD, 6:VA, 7:PBIOO0+, 8:PBIOO1+, 9:MCS23+
const uint32_t VPD_CP00_PG_N1_GOOD          = 0xE03F;
const uint32_t VPD_CP00_PG_N1_PG_MASK       = 0x01C0;
const uint32_t VPD_CP00_PG_N1_PBIOO0        = 0x0100;
const uint32_t VPD_CP00_PG_N1_PBIOO1        = 0x0080;
const uint32_t VPD_CP00_PG_N1_MCS23         = 0x0040;

const uint32_t VPD_CP00_PG_N2_INDEX         = 4;
// all good - 3:VITAL, 4:PRV, 5:CXA1, 6:PCIS0, 7:PCIS1, 8:PCIS2, 9:IOPSI
const uint32_t VPD_CP00_PG_N2_GOOD          = 0xE03F;

const uint32_t VPD_CP00_PG_N3_INDEX         = 5;
// all good - 3:VITAL, 4:PRV, 5:PB, 6:BR, 7:NPU+, 8:MM, 9:INT, 10:MCS01+
const uint32_t VPD_CP00_PG_N3_GOOD          = 0xE01F;
const uint32_t VPD_CP00_PG_N3_PG_MASK       = 0x0120;
const uint32_t VPD_CP00_PG_N3_NPU           = 0x0100;
const uint32_t VPD_CP00_PG_N3_MCS01         = 0x0020;

const uint32_t VPD_CP00_PG_XBUS_INDEX       = 6;
// all good - 3:VITAL, 4:PRV, 5:IOX0*+, 6:IOX1+, 7:IOX2+,
//            8:PBIOX0*, 9:PBIOX1, 10:PBIOX2, 14:PLLIOX
const uint32_t VPD_CP00_PG_XBUS_GOOD        = 0xE01D;
const uint32_t VPD_CP00_PG_XBUS_PG_MASK     = 0x07E0;
const uint32_t VPD_CP00_PG_XBUS_IOX_PAIR[3] = {0x0480, 0x0240, 0x0120};

const uint32_t VPD_CP00_PG_MCxx_INDEX[4]    = {7, 7, 8, 8}; // by MCS
// all good - 3:VITAL, 4:PRV, 5:MCA01, 6:IOM01+, 7:IOM23+, 14:PLLMEM
// all good - 3:VITAL, 4:PRV, 5:MCA23, 6:IOM45+, 7:IOM67+, 14:PLLMEM
const uint32_t VPD_CP00_PG_MCxx_GOOD        = 0xE0FD;
const uint32_t VPD_CP00_PG_MCxx_PG_MASK     = 0x0300;
const uint32_t VPD_CP00_PG_MCxx_IOMyy[4]    = {0x0200, 0x0100, 0x0200, 0x0100};

const uint32_t VPD_CP00_PG_OB0_INDEX        = 9;
const uint32_t VPD_CP00_PG_OB3_INDEX        = 12;
// all good - 3:VITAL, 4:PRV, 5:PLIOOAx, 6:IOOx, 14:PLLIOO; x=0, 1*, 2*, 3
const uint32_t VPD_CP00_PG_OBUS_GOOD        = 0xE1FD;

const uint32_t VPD_CP00_PG_PCI0_INDEX       = 13;
// all good - 3:VITAL, 4:PRV, 5:PCI00, 6:IOPCI0, 14:PLLPCI0
// all good - 3:VITAL, 4:PRV, 5:PCI11, 6:PCI12, 7:IOPCI1, 14:PLLPCI1
// all good - 3:VITAL, 4:PRV, 5:PCI23, 6:PCI24, 7:PCI25, 8:IOPCI2, 14:PLLPCI2
const uint32_t VPD_CP00_PG_PCIx_GOOD[3]     = {0xE1FD, 0xE0FD, 0xE07D};

const uint32_t VPD_CP00_PG_EP0_INDEX        = 16;
const uint32_t VPD_CP00_PG_EP5_INDEX        = 21;
// all good - 3:VITAL, 4:PRV, 5:EQPB, 6:L30+, 7:L31+,
//            8:L20+, 9:L21+, 10:AN, 11:PBLEQ, 12:REFR0, 13:REFR1, 14:DPLL
const uint32_t VPD_CP00_PG_EPx_GOOD         = 0xE001;
const uint32_t VPD_CP00_PG_EPx_PG_MASK      = 0x03CC;
const uint32_t VPD_CP00_PG_EPx_L3L2REFR[2]  = {0x0288, 0x0144};

const uint32_t VPD_CP00_PG_EC00_INDEX       = 32;
// all good - 3:VITAL, 4:PRV, 5:C00, 6:C01
const uint32_t VPD_CP00_PG_ECxx_GOOD        = 0xE1FF;

const uint32_t VPD_CP00_PG_MAX_USED_INDEX   = 55;
const uint32_t VPD_CP00_PG_xxx_PERV         = 0x0800;
const uint32_t VPD_CP00_PG_RESERVED_GOOD    = 0xFFFF;


/**
 * @brief Checks the PG keyword data to determine if the target chip is
 *  functional. The caller is responsible for allocating and de-allocating the
 *  PG keyword space.
 *
 * @param[in]  i_target    pointer to target that we're looking at
 * @param[in]  i_pgData    pointer to area holding the PG keyword read from
 *                          VPD; must be malloc'ed by the caller, and must be
 *                          VPD_CP00_PG_DATA_LENGTH in size.
 *
 * @return bool Return true if the chip is functional; false if not.
 *
 */
bool isChipFunctional(const TARGETING::TargetHandle_t &i_target,
                      const uint16_t i_pgData[VPD_CP00_PG_DATA_LENGTH]);


/**
 * @brief Checks the PG keyword data to determine if the descendant chiplet is
 *  functional. The caller is responsible for allocating and de-allocating the
 *  PG keyword space.
 *
 * @param[in]  i_desc      pointer to descendant of target we're looking at
 * @param[in]  i_pgData    pointer to area holding the PG keyword read from
 *                          VPD; must be malloc'ed by the caller, and must be
 *                          VPD_CP00_PG_DATA_LENGTH in size.
 *
 * @return bool Return true if the descendant is functional; false if not.
 *
 */
bool isDescFunctional(const TARGETING::TargetHandle_t &i_desc,
                      const uint16_t i_pgData[VPD_CP00_PG_DATA_LENGTH]);


/**
 * @brief platform specific code to determine the PR vector of the input
 *  target. The platform specific code is responsible for returning the
 *  vector. The caller is responsible for allocating and de-allocating the
 *  space.
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
 * @param[in] i_node  node target to restrict hw check
 * @param[out] o_bootable Indicates whether system is bootable with current
 *             configuratio, if a non NULL pointer is passed erros will not
 *             be logged if system cannot ipl and just return a true or false.
 */
void platCheckMinimumHardware(uint32_t & io_plid,
                            const TARGETING::ConstTargetHandle_t i_node = NULL,
                            bool *o_bootable = NULL);

} // namespace HWAS

#endif // HWASCOMMON_H_
