/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/lib/fir/p10_fir_traits.H $ */
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
/// @file p10_fir_traits.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _P10_FIR_TRAITS_H_
#define _P10_FIR_TRAITS_H_

#include <fapi2.H>
#include <p10_scom_mc.H>
#include <p10_scom_mcc.H>
#include <p10_scom_omic.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{

///
/// @brief FIR Register Traits for base DSTLFIR_MCC
///
template <>
struct firTraits<scomt::mcc::DSTL_DSTLFIR_RW>
{
    static constexpr uint64_t REG = scomt::mcc::DSTL_DSTLFIR_RW;
    static constexpr uint64_t ACT0 = scomt::mcc::DSTL_DSTLFIRACT0;
    static constexpr uint64_t ACT1 = scomt::mcc::DSTL_DSTLFIRACT1;
    static constexpr uint64_t ACT2 = scomt::mcc::DSTL_DSTLFIRACT2;
    static constexpr uint64_t MASK = scomt::mcc::DSTL_DSTLFIRMASK_RW;
    static constexpr uint64_t MASK_AND = scomt::mcc::DSTL_DSTLFIRMASK_WO_AND;
    static constexpr uint64_t MASK_OR = scomt::mcc::DSTL_DSTLFIRMASK_WO_OR;
    static constexpr bool HAS_ACT2 = true;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCC;
};

///
/// @brief FIR Register Traits for base USTL_USTLFIR_RW
///
template <>
struct firTraits<scomt::mcc::USTL_USTLFIR_RW>
{
    static constexpr uint64_t REG = scomt::mcc::USTL_USTLFIR_RW;
    static constexpr uint64_t ACT0 = scomt::mcc::USTL_USTLFIRACT0;
    static constexpr uint64_t ACT1 = scomt::mcc::USTL_USTLFIRACT1;
    static constexpr uint64_t ACT2 = scomt::mcc::USTL_USTLFIRACT2;
    static constexpr uint64_t MASK = scomt::mcc::USTL_USTLFIRMASK_RW;
    static constexpr uint64_t MASK_AND = scomt::mcc::USTL_USTLFIRMASK_WO_AND;
    static constexpr uint64_t MASK_OR = scomt::mcc::USTL_USTLFIRMASK_WO_OR;
    static constexpr bool HAS_ACT2 = true;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCC;
};

///
/// @brief FIR Register Traits for base MC_OMI_FIR_REG_RW
///
template <>
struct firTraits<scomt::omic::MC_OMI_FIR_REG_RW>
{
    static constexpr uint64_t REG = scomt::omic::MC_OMI_FIR_REG_RW;
    static constexpr uint64_t ACT0 = scomt::omic::MC_OMI_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = scomt::omic::MC_OMI_FIR_ACTION1_REG;
    static constexpr uint64_t ACT2 = scomt::omic::MC_OMI_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = scomt::omic::MC_OMI_FIR_MASK_REG_RW;
    static constexpr uint64_t MASK_AND = scomt::omic::MC_OMI_FIR_MASK_REG_WO_AND;
    static constexpr uint64_t MASK_OR = scomt::omic::MC_OMI_FIR_MASK_REG_WO_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OMIC;
};

///
/// @brief FIR Register Traits for base MBA_SCOMFIR_MISCFIRQ_RW
///
template <>
struct firTraits<scomt::mc::MBA_SCOMFIR_MISCFIRQ_RW>
{
    static constexpr uint64_t REG = scomt::mc::MBA_SCOMFIR_MISCFIRQ_RW;
    static constexpr uint64_t ACT0 = scomt::mc::MBA_SCOMFIR_MISCFIRACT0;
    static constexpr uint64_t ACT1 = scomt::mc::MBA_SCOMFIR_MISCFIRACT1;
    static constexpr uint64_t ACT2 = scomt::mc::MBA_SCOMFIR_MISCFIRACT2;
    static constexpr uint64_t MASK = scomt::mc::MBA_SCOMFIR_MISCFIRMASK_RW;
    static constexpr uint64_t MASK_AND = scomt::mc::MBA_SCOMFIR_MISCFIRMASK_WO_AND;
    static constexpr uint64_t MASK_OR = scomt::mc::MBA_SCOMFIR_MISCFIRMASK_WO_OR;
    static constexpr bool HAS_ACT2 = true;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MC;
};

} // end mss ns
#endif
