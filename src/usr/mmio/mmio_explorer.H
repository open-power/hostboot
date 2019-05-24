/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/mmio/mmio_explorer.H $                                */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

/** @file  mmio_explorer.H
 *  @brief Provides interface to perform Explorer MMIO operations
 */

#include <errl/errlentry.H>
#include <targeting/common/target.H>

namespace MMIOEXP
{

/**
 *
 * @brief Determine if the OCMB detected a failure on a specific MMIO
 *        transaction to the specified OCMB target.
 *
 * @param[in] i_expTarget Handle for the target OCMB chip.
 * @param[in] i_va Virtual address of the transaction to check
 * @param[in] i_accessLimit The byte range of the transaction
 * @param[in] i_offset The offset of the config reg, scom reg, MSCC reg or
 *            SRAM to be accessed on the explorer chip.
 * @param[in] i_opType The operation type (read or write)
 * @param[out] o_errorAddressMatches Set to true if the OCMB chip detected a
 *             failure on our transaction.
 * @param[out] o_errorAddressIsZero Set to true if no error has been detected
 *             yet.
 * @return nullptr on succesful read of OCMB error status, non-null otherwise.
 *
 */
errlHndl_t checkExpError(const TARGETING::TargetHandle_t i_expTarget,
                         const uint64_t i_va,
                         const uint64_t i_accessLimit,
                         const uint64_t i_offset,
                         DeviceFW::OperationType i_opType,
                         bool& o_errorAddressMatches,
                         bool& o_errorAddressIsZero);

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
