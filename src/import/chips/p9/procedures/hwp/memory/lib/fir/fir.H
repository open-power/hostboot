/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/fir.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file fir.H
/// @brief Memory subsystem FIR support
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_FIR_H_
#define _MSS_FIR_H_

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

namespace mss
{


///
/// @brief FIR Register Traits for MCBISTFIR
///
template <>
struct firTraits<MCBIST_MCBISTFIRQ>
{
    static constexpr uint64_t REG = MCBIST_MCBISTFIRQ;
    static constexpr uint64_t ACT0 = MCBIST_MCBISTFIRACT0;
    static constexpr uint64_t ACT1 = MCBIST_MCBISTFIRACT1;
    static constexpr uint64_t MASK = MCBIST_MCBISTFIRMASK;
    static constexpr uint64_t MASK_AND = MCBIST_MCBISTFIRMASK_AND;
    static constexpr uint64_t MASK_OR = MCBIST_MCBISTFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCBIST;
};

///
/// @brief FIR Register Traits for PHYFIR
///
template <>
struct firTraits<MCA_IOM_PHY0_DDRPHY_FIR_REG>
{
    static constexpr uint64_t REG = MCA_IOM_PHY0_DDRPHY_FIR_REG;
    static constexpr uint64_t ACT0 = MCA_IOM_PHY0_DDRPHY_FIR_ACTION0_REG;
    static constexpr uint64_t ACT1 = MCA_IOM_PHY0_DDRPHY_FIR_ACTION1_REG;
    static constexpr uint64_t MASK = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG;
    static constexpr uint64_t MASK_AND = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG_AND;
    static constexpr uint64_t MASK_OR = MCA_IOM_PHY0_DDRPHY_FIR_MASK_REG_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief FIR Register Traits for MCFIR
///
template <>
struct firTraits<MCS_MCFIR>
{
    static constexpr uint64_t REG = MCS_MCFIR;
    static constexpr uint64_t ACT0 = MCS_MCFIRACT0;
    static constexpr uint64_t ACT1 = MCS_MCFIRACT1;
    static constexpr uint64_t MASK = MCS_MCFIRMASK;
    static constexpr uint64_t MASK_AND = MCS_MCFIRMASK_AND;
    static constexpr uint64_t MASK_OR = MCS_MCFIRMASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCS;
};

///
/// @brief FIR Register Traits for MCA_FIR (ECC64.SCOM.FIR)
///
template <>
struct firTraits<MCA_FIR>
{
    static constexpr uint64_t REG = MCA_FIR;
    static constexpr uint64_t ACT0 = MCA_ACTION0;
    static constexpr uint64_t ACT1 = MCA_ACTION1;
    static constexpr uint64_t MASK = MCA_MASK;
    static constexpr uint64_t MASK_AND = MCA_MASK_AND;
    static constexpr uint64_t MASK_OR = MCA_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};

///
/// @brief FIR Register Traits for MBACALFIR
///
template <>
struct firTraits<MCA_MBACALFIRQ>
{
    static constexpr uint64_t REG = MCA_MBACALFIRQ;
    static constexpr uint64_t ACT0 = MCA_MBACALFIR_ACTION0;
    static constexpr uint64_t ACT1 = MCA_MBACALFIR_ACTION1;
    static constexpr uint64_t MASK = MCA_MBACALFIR_MASK;
    static constexpr uint64_t MASK_AND = MCA_MBACALFIR_MASK_AND;
    static constexpr uint64_t MASK_OR = MCA_MBACALFIR_MASK_OR;

    // Target type of this register
    static constexpr fapi2::TargetType T = fapi2::TARGET_TYPE_MCA;
};


}
#endif
