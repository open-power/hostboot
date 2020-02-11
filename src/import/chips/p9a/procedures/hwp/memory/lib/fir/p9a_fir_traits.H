/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/fir/p9a_fir_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p9a_fir_traits.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P9A_FIR_TRAITS_H_
#define _P9A_FIR_TRAITS_H_

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief FIR Register Traits for base DSTLFIR_MCC
///
template <>
struct firTraits<P9A_MCC_DSTLFIR>
{
    static constexpr uint64_t REG = P9A_MCC_DSTLFIR;
    static constexpr uint64_t ACT0 = P9A_MCC_DSTLFIRACT0;
    static constexpr uint64_t ACT1 = P9A_MCC_DSTLFIRACT1;
    static constexpr uint64_t MASK = P9A_MCC_DSTLFIRMASK;
    static constexpr uint64_t MASK_AND = P9A_MCC_DSTLFIRMASK_AND;
    static constexpr uint64_t MASK_OR = P9A_MCC_DSTLFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCC;
};

///
/// @brief FIR Register Traits for base USTLFIR_MCC
///
template <>
struct firTraits<P9A_MCC_USTLFIR>
{
    static constexpr uint64_t REG = P9A_MCC_USTLFIR;
    static constexpr uint64_t ACT0 = P9A_MCC_USTLFIRACT0;
    static constexpr uint64_t ACT1 = P9A_MCC_USTLFIRACT1;
    static constexpr uint64_t MASK = P9A_MCC_USTLFIRMASK;
    static constexpr uint64_t MASK_AND = P9A_MCC_USTLFIRMASK_AND;
    static constexpr uint64_t MASK_OR = P9A_MCC_USTLFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCC;
};

///
/// @brief FIR Register Traits for base MC_OMI_FIR_REG
///
template <>
struct firTraits<P9A_MC_REG0_OMI_FIR>
{
    static constexpr uint64_t REG = P9A_MC_REG0_OMI_FIR;
    static constexpr uint64_t ACT0 = P9A_MC_REG0_OMI_FIR_ACTION0;
    static constexpr uint64_t ACT1 = P9A_MC_REG0_OMI_FIR_ACTION1;
    static constexpr uint64_t MASK = P9A_MC_REG0_OMI_FIR_MASK;
    static constexpr uint64_t MASK_AND = P9A_MC_REG0_OMI_FIR_MASK_AND;
    static constexpr uint64_t MASK_OR = P9A_MC_REG0_OMI_FIR_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MC;
};

///
/// @brief FIR Register Traits for base MC_LOCAL_FIR
///
template <>
struct firTraits<P9A_MC_LOCAL_FIR>
{
    static constexpr uint64_t REG = P9A_MC_LOCAL_FIR;
    static constexpr uint64_t ACT0 = P9A_MC_LOCAL_FIR_ACTION0;
    static constexpr uint64_t ACT1 = P9A_MC_LOCAL_FIR_ACTION1;
    static constexpr uint64_t MASK = P9A_MC_LOCAL_FIR_MASK;
    static constexpr uint64_t MASK_AND = P9A_MC_LOCAL_FIR_MASK_AND;
    static constexpr uint64_t MASK_OR = P9A_MC_LOCAL_FIR_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MC;
};

///
/// @brief FIR Register Traits for base MC_MCBISTFIRQ
///
template <>
struct firTraits<P9A_MC_MCBISTFIRQ>
{
    static constexpr uint64_t REG = P9A_MC_MCBISTFIRQ;
    static constexpr uint64_t ACT0 = P9A_MC_MCBISTFIRACT0;
    static constexpr uint64_t ACT1 = P9A_MC_MCBISTFIRACT1;
    static constexpr uint64_t MASK = P9A_MC_MCBISTFIRMASK;
    static constexpr uint64_t MASK_AND = P9A_MC_MCBISTFIRMASK_AND;
    static constexpr uint64_t MASK_OR = P9A_MC_MCBISTFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MC;
};

///
/// @brief FIR Register Traits for base OMIC_FIR_REG
///
template <>
struct firTraits<P9A_OMIC_FIR_REG>
{
    static constexpr uint64_t REG = P9A_OMIC_FIR_REG;
    static constexpr uint64_t ACT0 = P9A_OMIC_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = P9A_OMIC_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = P9A_OMIC_FIR_MASK_REG;
    static constexpr uint64_t MASK_AND = P9A_OMIC_FIR_MASK_REG_AND;
    static constexpr uint64_t MASK_OR = P9A_OMIC_FIR_MASK_REG_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OMIC;
};

///
/// @brief FIR Register Traits for base OMIC_PPE_FIR_REG
///
template <>
struct firTraits<P9A_OMIC_PPE_FIR_REG>
{
    static constexpr uint64_t REG = P9A_OMIC_PPE_FIR_REG;
    static constexpr uint64_t ACT0 = P9A_OMIC_PPE_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = P9A_OMIC_PPE_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = P9A_OMIC_PPE_FIR_MASK_REG;
    static constexpr uint64_t MASK_AND = P9A_OMIC_PPE_FIR_MASK_REG_AND;
    static constexpr uint64_t MASK_OR = P9A_OMIC_PPE_FIR_MASK_REG_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OMIC;
};

} // end mss ns
#endif
