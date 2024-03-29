/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_explorer.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
#ifndef __MMIO_EXPLORER_H
#define __MMIO_EXPLORER_H

/**
 * @file  mmio_explorer.H
 * @brief Provides interface to perform Explorer MMIO operations
 */

#include <errl/errlentry.H>
#include <targeting/common/target.H>
#include <explorer_scom_addresses.H>
#include "mmio_ocmb_common.H"

namespace MMIOEXP
{

// List of common register addresses, order must match RegNames_t
constexpr uint64_t REG_ADDRS[] = {
    EXPLR_MMIO_MCFGERR,
    EXPLR_MMIO_MCFGERRA,
    EXPLR_MMIO_MMIOERR,
};
static_assert( sizeof(REG_ADDRS)/sizeof(REG_ADDRS[0])
               == MMIOCOMMON::RegNames_t_SIZE,
               "Explorer REG_ADDRS wrong size" );

const uint32_t FFDC_REGISTERLIST[] = {
    0x08012800,   // OMI_FIR REG
    0x08010870,   // MMIOFIR
    0x08011800,   // MCBISTFIR
    0x08011c00,   // RDFFIR
    0x08011400,   // SRQFIR
    0x08012400,   // TLXFIR
    0x0804000A,   // OCMB_LFIR
    0x08040000,   // XFIR
    0x08040001,   // RFIR
    0x08040004,   // Special Attention
    0x08040018 }; // Local Checkstop FIR


/**
 *
 * @brief Collect additional failure data from the target explorer chip and add
 *        appropriate FRU/Procedure callouts.
 *
 * @note Must call checkExpError to determine that a transaction failed before
 *       calling this function.
 *
 * @param[in] i_expTarget Handle of explorer to collect extra FFDC from
 * @param[in] i_offset The offset of the config reg, scom reg, MSCC reg or
 *                     SRAM that was accessed on the explorer chip.
 * @param[in] i_opType The operation type (read or write)
 * @param[in] i_err There error log for adding additional FFDC
 * @param[out] o_fwFailure The failure was a firmware failure if true,
 *                         otherwise, it was a hardware failure.
 *
 * @return non-nullptr if unable to determine failure type, nullptr otherwise.
 */
errlHndl_t determineExpCallouts(const TARGETING::TargetHandle_t i_expTarget,
                             const uint64_t i_offset,
                             DeviceFW::OperationType i_opType,
                             errlHndl_t i_err,
                             bool& o_fwFailure);

}; // End MMIOEXP namespace

#endif
