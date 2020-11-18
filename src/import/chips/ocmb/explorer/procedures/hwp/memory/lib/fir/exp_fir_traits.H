/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_fir_traits.H $ */
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
/// @file exp_fir_traits.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_EXP_FIR_TRAITS_H_
#define _MSS_EXP_FIR_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>

namespace mss
{

///
/// @brief FIR Register Traits for Explorer MCBIST FIR
///
template <>
struct firTraits<EXPLR_MCBIST_MCBISTFIRQ>
{
    static constexpr uint64_t REG = EXPLR_MCBIST_MCBISTFIRQ;
    static constexpr uint64_t ACT0 = EXPLR_MCBIST_MCBISTFIRACT0;
    static constexpr uint64_t ACT1 = EXPLR_MCBIST_MCBISTFIRACT1;
    static constexpr uint64_t ACT2 = EXPLR_MCBIST_MCBISTFIRACT1;
    static constexpr uint64_t MASK = EXPLR_MCBIST_MCBISTFIRMASK;
    static constexpr uint64_t MASK_AND = EXPLR_MCBIST_MCBISTFIRMASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_MCBIST_MCBISTFIRMASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer SRQ FIR
///
template <>
struct firTraits<EXPLR_SRQ_SRQFIRQ>
{
    static constexpr uint64_t REG = EXPLR_SRQ_SRQFIRQ;
    static constexpr uint64_t ACT0 = EXPLR_SRQ_SRQFIR_ACTION0;
    static constexpr uint64_t ACT1 = EXPLR_SRQ_SRQFIR_ACTION1;
    static constexpr uint64_t ACT2 = EXPLR_SRQ_SRQFIR_ACTION1;
    static constexpr uint64_t MASK = EXPLR_SRQ_SRQFIR_MASK;
    static constexpr uint64_t MASK_AND = EXPLR_SRQ_SRQFIR_MASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_SRQ_SRQFIR_MASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer RDF FIR
///
template <>
struct firTraits<EXPLR_RDF_FIR>
{
    static constexpr uint64_t REG = EXPLR_RDF_FIR;
    static constexpr uint64_t ACT0 = EXPLR_RDF_ACTION0;
    static constexpr uint64_t ACT1 = EXPLR_RDF_ACTION1;
    static constexpr uint64_t ACT2 = EXPLR_RDF_ACTION1;
    static constexpr uint64_t MASK = EXPLR_RDF_MASK;
    static constexpr uint64_t MASK_AND = EXPLR_RDF_MASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_RDF_MASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer LOCAL FIR
///
template <>
struct firTraits<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR>
{
    static constexpr uint64_t REG = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR;
    static constexpr uint64_t ACT0 = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_ACTION0;
    static constexpr uint64_t ACT1 = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_ACTION1;
    static constexpr uint64_t ACT2 = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_ACTION1;
    static constexpr uint64_t MASK = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK;
    static constexpr uint64_t MASK_AND = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_MASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer TLX FIR
///
template <>
struct firTraits<EXPLR_TLXT_TLXFIRQ>
{
    static constexpr uint64_t REG = EXPLR_TLXT_TLXFIRQ;
    static constexpr uint64_t ACT0 = EXPLR_TLXT_TLXFIRACT0;
    static constexpr uint64_t ACT1 = EXPLR_TLXT_TLXFIRACT1;
    static constexpr uint64_t ACT2 = EXPLR_TLXT_TLXFIRACT1;
    static constexpr uint64_t MASK = EXPLR_TLXT_TLXFIRMASK;
    static constexpr uint64_t MASK_AND = EXPLR_TLXT_TLXFIRMASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_TLXT_TLXFIRMASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer MC_OMI FIR
///
template <>
struct firTraits<EXPLR_DLX_MC_OMI_FIR_REG>
{
    static constexpr uint64_t REG = EXPLR_DLX_MC_OMI_FIR_REG;
    static constexpr uint64_t ACT0 = EXPLR_DLX_MC_OMI_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = EXPLR_DLX_MC_OMI_FIR_ACTION1_REG;
    static constexpr uint64_t ACT2 = EXPLR_DLX_MC_OMI_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = EXPLR_DLX_MC_OMI_FIR_MASK_REG;
    static constexpr uint64_t MASK_AND = EXPLR_DLX_MC_OMI_FIR_MASK_REG_AND;
    static constexpr uint64_t MASK_OR = EXPLR_DLX_MC_OMI_FIR_MASK_REG_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Explorer MMIO MFIR
///
template <>
struct firTraits<EXPLR_MMIO_MFIR>
{
    static constexpr uint64_t REG = EXPLR_MMIO_MFIR;
    static constexpr uint64_t ACT0 = EXPLR_MMIO_MFIRACT0;
    static constexpr uint64_t ACT1 = EXPLR_MMIO_MFIRACT1;
    static constexpr uint64_t ACT2 = EXPLR_MMIO_MFIRACT1;
    static constexpr uint64_t MASK = EXPLR_MMIO_MFIRMASK;
    static constexpr uint64_t MASK_AND = EXPLR_MMIO_MFIRMASK_AND;
    static constexpr uint64_t MASK_OR = EXPLR_MMIO_MFIRMASK_OR;
    static constexpr bool HAS_ACT2 = false;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

} // end mss ns
#endif
