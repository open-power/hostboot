/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/omi/ody_omi_traits.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file ody_omi_traits.H
/// @brief Odyssey's OMI traits
///
// *HWP HWP Owner: Geetha Pisapati <geetha.pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP
// EKB-Mirror-To: hostboot

#ifndef _ODY_OMI_TRAITS_H_
#define _ODY_OMI_TRAITS_H_

#include <fapi2.H>

#include <ody_scom_ody_odc.H>

#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/omi/gen_omi_traits.H>


namespace mss
{
namespace omi
{
//////////////////////////////////////////////////////////////
// Traits values for ODYSSEY
//////////////////////////////////////////////////////////////
///
/// @class Traits and policy class for omi code - specialization for Odyssey. The target of registers is TARGET_TYPE_OCMB_CHIP
///
template<>
class omiTraits< mss::mc_type::ODYSSEY>
{
    public:
        static constexpr uint64_t TLXT_TLXTINTHLD0 = scomt::ody::ODC_TLXT_REGS_TLXTINTHLD0;
        static constexpr uint64_t TLXT_TLXTINTHLD1 = scomt::ody::ODC_TLXT_REGS_TLXTINTHLD1;
        static constexpr uint64_t TLXT_TLXTINTHLD2 = scomt::ody::ODC_TLXT_REGS_TLXTINTHLD2;
        static constexpr uint64_t TLXT_TLXTINTHLD3 = scomt::ody::ODC_TLXT_REGS_TLXTINTHLD3;

        static const uint64_t TLXT_REGS_TLXCFG1 = scomt::ody::ODC_TLXT_REGS_TLXCFG1;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0 = scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0_LEN =
            scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0_LEN;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1 = scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1_LEN =
            scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1_LEN;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2 = scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2_LEN =
            scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2_LEN;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3 = scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3;
        static const uint32_t TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3_LEN =
            scomt::ody::ODC_TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3_LEN;

        static constexpr uint64_t MMIO_MFIR_RW_WCLEAR = scomt::ody::ODC_MMIO_MFIR_RW_WCLEAR;
        static constexpr uint64_t ACTAG_PASID_CFG_ERR = scomt::ody::ODC_MMIO_MFIR_ACTAG_PASID_CFG_ERR;
};

} // end omi
} // end mss

#endif
