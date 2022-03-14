/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_fir_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_fir_traits.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ODY_FIR_TRAITS_H_
#define _MSS_ODY_FIR_TRAITS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <ody_scom_ody.H>
#include <ody_scom_perv.H>
#include <ody_scom_omi.H>

namespace mss
{

///
/// @brief FIR Register Traits for Odyssey MCBIST FIR
///
template <>
struct firTraits2<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_WO_OR;
    static constexpr uint64_t ATTN = scomt::ody::ODC_MCBIST_SCOM_MCBISTCFGSPATTN;
    static constexpr uint64_t LXSTOP = scomt::ody::ODC_MCBIST_SCOM_MCBISTCFGLXSTOP;
    static constexpr uint64_t RECOV = scomt::ody::ODC_MCBIST_SCOM_MCBISTCFGRECOV;
    static constexpr uint64_t XSTOP = scomt::ody::ODC_MCBIST_SCOM_MCBISTCFGXSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRMASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Odyssey SRQ FIR
///
template <>
struct firTraits2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::ody::ODC_SRQ_LFIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::ody::ODC_SRQ_CFG_ATTN;
    static constexpr uint64_t LXSTOP = scomt::ody::ODC_SRQ_CFG_LXSTOP;
    static constexpr uint64_t RECOV = scomt::ody::ODC_SRQ_CFG_RECOV;
    static constexpr uint64_t XSTOP = scomt::ody::ODC_SRQ_CFG_XSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::ody::ODC_SRQ_MASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::ody::ODC_SRQ_MASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Odyssey RDF FIR (one per mem_port)
///
template <>
struct firTraits2<scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::ody::ODC_RDF0_SCOM_FIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::ody::ODC_RDF0_SCOM_RDFCFGSPATTN;
    static constexpr uint64_t LXSTOP = scomt::ody::ODC_RDF0_SCOM_RDFCFGLXSTOP;
    static constexpr uint64_t RECOV = scomt::ody::ODC_RDF0_SCOM_RDFCFGRECOV;
    static constexpr uint64_t XSTOP = scomt::ody::ODC_RDF0_SCOM_RDFCFGXSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::ody::ODC_RDF0_SCOM_RDFFIRMASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::ody::ODC_RDF0_SCOM_RDFFIRMASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MEM_PORT;
};

///
/// @brief FIR Register Traits for Odyssey LOCAL FIR
///
template <>
struct firTraits2<scomt::perv::TPCHIP_TPC_LFIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::perv::TPCHIP_TPC_LFIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::perv::TPCHIP_TPC_LFIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::perv::TPCHIP_TPC_EPS_FIR_CFG_ATTN;
    static constexpr uint64_t LXSTOP = scomt::perv::TPCHIP_TPC_EPS_FIR_CFG_LXSTOP;
    static constexpr uint64_t RECOV = scomt::perv::TPCHIP_TPC_EPS_FIR_CFG_RECOV;
    static constexpr uint64_t XSTOP = scomt::perv::TPCHIP_TPC_EPS_FIR_CFG_XSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::perv::TPCHIP_TPC_EPS_FIR_MASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::perv::TPCHIP_TPC_EPS_FIR_MASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Odyssey TLX FIR
///
template <>
struct firTraits2<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::ody::ODC_TLXT_REGS_TLX_LFIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::ody::ODC_TLXT_REGS_TLX_LFIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::ody::ODC_TLXT_REGS_CFG_ATTN;
    static constexpr uint64_t LXSTOP = scomt::ody::ODC_TLXT_REGS_CFG_LXSTOP;
    static constexpr uint64_t RECOV = scomt::ody::ODC_TLXT_REGS_CFG_RECOV;
    static constexpr uint64_t XSTOP = scomt::ody::ODC_TLXT_REGS_CFG_XSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::ody::ODC_TLXT_REGS_TLX_MASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::ody::ODC_TLXT_REGS_TLX_MASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Odyssey MC_OMI FIR
///
template <>
struct firTraits2<scomt::omi::D_REG_MC_OMI_FIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::omi::D_REG_MC_OMI_FIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::omi::D_REG_MC_OMI_FIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::omi::D_REG_MC_OMI_FIR_CFGSPATTN;
    static constexpr uint64_t LXSTOP = scomt::omi::D_REG_MC_OMI_FIR_CFGLXSTOP;
    static constexpr uint64_t RECOV = scomt::omi::D_REG_MC_OMI_FIR_CFGRECOV;
    static constexpr uint64_t XSTOP = scomt::omi::D_REG_MC_OMI_FIR_CFGXSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::omi::D_REG_MC_OMI_FIR_MASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::omi::D_REG_MC_OMI_FIR_MASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

///
/// @brief FIR Register Traits for Odyssey MMIO MFIR
///
template <>
struct firTraits2<scomt::ody::ODC_MMIO_MFIR_RW_WCLEAR>
{
    static constexpr uint64_t FIR_CLEAR = scomt::ody::ODC_MMIO_MFIR_RW_WCLEAR;
    static constexpr uint64_t FIR_SET = scomt::ody::ODC_MMIO_MFIR_WO_OR;
    static constexpr uint64_t ATTN = scomt::ody::ODC_MMIO_MCFGSPATTN;
    static constexpr uint64_t LXSTOP = scomt::ody::ODC_MMIO_MCFGLXSTOP;
    static constexpr uint64_t RECOV = scomt::ody::ODC_MMIO_MCFGRECOV;
    static constexpr uint64_t XSTOP = scomt::ody::ODC_MMIO_MCFGXSTOP;
    static constexpr uint64_t MASK_CLEAR = scomt::ody::ODC_MMIO_MFIRMASK_RW_WCLEAR;
    static constexpr uint64_t MASK_SET = scomt::ody::ODC_MMIO_MFIRMASK_WO_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_OCMB_CHIP;
};

} // end mss ns
#endif
