/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/lib/p9_ppe_defs.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///
/// @file  p9_ppe_defs.H
/// @brief PPE commonly used definitions
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP HW Backup Owner : Brian Vanderpool <vanderp@us.ibm.com>
/// *HWP FW Owner        : Amit Tendolkar <amit.tendolkar@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 1
/// *HWP Consumed by     : FSP, HB, SBE
#ifndef __P9_PPE_DEFS_H__
#define __P9_PPE_DEFS_H__

#include <p9_quad_scom_addresses.H>
#include <p9_misc_scom_addresses.H>
#include <p9_xbus_scom_addresses.H>

/// @brief Base SCOM addresses for PPE State Collection
const uint64_t SBE_BASE_ADDRESS = PU_PPE_XIXCR;
const uint64_t GPE0_BASE_ADDRESS = PU_GPE0_PPE_XIXCR;
const uint64_t GPE1_BASE_ADDRESS = PU_GPE1_PPE_XIXCR;
const uint64_t PGPE_BASE_ADDRESS = PU_GPE2_PPE_XIXCR;
const uint64_t SGPE_BASE_ADDRESS = PU_GPE3_PPE_XIXCR;
const uint64_t CME0_BASE_ADDRESS = EX_PPE_XIXCR;
const uint64_t IOPPE_BASE_ADDRESS = XBUS_IOPPE_PPE_XIXCR;

/// @brief Each CME is associated with an EX target, that contains the 2 cores,
///        that are controlled by that CME. Using this relation,
///        this helper function gets the base SCOM address
///        to collect PPE State of the CME associated with an EX
/// @param[in]  i_ExChipUnitPos The EX targets's ATTR_CHIP_UNIT_POS
/// @return     uint64_t        PPE State collection base address of the
///                             associated CME
inline uint64_t getCmeBaseAddress (const uint8_t i_ExChipUnitPos)
{
    return ( CME0_BASE_ADDRESS |
             ((i_ExChipUnitPos / 2) << 24) |
             ((i_ExChipUnitPos % 2) << 10) );
}

#endif  // __P9_PPE_DEFS_H__
