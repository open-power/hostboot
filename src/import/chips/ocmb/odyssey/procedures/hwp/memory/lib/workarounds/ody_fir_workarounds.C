/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_fir_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2025                             */
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
/// @file ody_fir_workarounds.C
/// @brief Workarounds for Odyssey FIR related issues
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/find.H>
#include <ody_scom_ody_odc.H>
#include <lib/workarounds/ody_fir_workarounds.H>
#include <lib/fir/ody_fir_traits.H>
#include <lib/fir/ody_unmask.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>

namespace mss
{
namespace ody
{
namespace fir
{
namespace workarounds
{

///
/// @brief Mask SRQ0_SM_1HOT_ERR
/// @param[in] i_target the OCMB_CHIP target
/// @param[out] o_unmasked will be set to TRUE if either of the FIR bits were initially unmasked
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids unnecessary checkstop caused by state machine glitches
/// during scominit and standalone CCS at high memory frequency
///
fapi2::ReturnCode mask_srq_one_hot( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                    bool& o_unmasked )
{
    fapi2::buffer<uint64_t> l_current_mask;

    // Create register for SRQ_LFIR
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);

    o_unmasked = false;
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MASK_RW_WCLEAR, l_current_mask));
    o_unmasked |= !l_current_mask.getBit<scomt::ody::ODC_SRQ_LFIR_IN10>();
    o_unmasked |= !l_current_mask.getBit<scomt::ody::ODC_SRQ_LFIR_IN37>();

    FAPI_TRY(l_srq_reg.remask<scomt::ody::ODC_SRQ_LFIR_IN10>(),
             "Failed to Write SRQ FIR Mask register " GENTARGTIDFORMAT, GENTARGTID(i_target));
    FAPI_TRY(l_srq_reg.remask<scomt::ody::ODC_SRQ_LFIR_IN37>(),
             "Failed to Write SRQ FIR Mask register " GENTARGTIDFORMAT, GENTARGTID(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear and Re-unmask SRQ0_SM_1HOT_ERR
/// @param[in] i_target the fapi2::Target
/// @param[in] i_unmasked set to TRUE if either of the FIR bits were initially unmasked
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids unnecessary checkstop caused by state machine glitches
/// during scominit and standalone CCS at high memory frequency
///
fapi2::ReturnCode clear_and_unmask_srq_one_hot( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const bool i_unmasked )
{
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
    fapi2::buffer<uint64_t> l_reg_data;

    // Create register for SRQ_LFIR
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);

    // Clear the checker
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_SRQCFG0, l_reg_data));
    l_reg_data.setBit<scomt::ody::ODC_SRQ_SRQCFG0_CLEAR>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_SRQCFG0, l_reg_data));

    // Clear the FIR if it is set
    FAPI_TRY(l_srq_reg.clear<scomt::ody::ODC_SRQ_LFIR_IN10>(),
             "Failed to clear SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));
    FAPI_TRY(l_srq_reg.clear<scomt::ody::ODC_SRQ_LFIR_IN37>(),
             "Failed to clear SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Unmask the FIR on any present mem_ports
    if(i_unmasked && mss::unmask::is_port_present(l_ports, 0))
    {
        l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_IN10>();
    }

    if(i_unmasked && mss::unmask::is_port_present(l_ports, 1))
    {
        l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_IN37>();
    }

    FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Get the checker ready again
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_SRQCFG0, l_reg_data));
    l_reg_data.clearBit<scomt::ody::ODC_SRQ_SRQCFG0_CLEAR>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_SRQCFG0, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // ns workarounds
} // ns fir
} // ns ody
} // ns mss
