/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_unmask.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_unmask.C
/// @brief Subroutines for unmasking and setting up MSS FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/fir/ody_fir_traits.H>
#include <lib/fir/ody_unmask.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>

namespace mss
{

namespace unmask
{

///
/// @brief Finds if a specific port is present
/// @param[in] i_ports the vector of ports present on this OCMB chip
/// @param[in] i_port_pos the port to look for in terms of the relative pos
/// @return true if the port is present, otherwise false
///
bool is_port_present(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>>& i_ports, const uint8_t i_port_pos)
{
    // Loops through all ports
    for(const auto& l_port : i_ports)
    {
        // If this port has the same relative position as the desired port, set to true and break out of the loop
        if(mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(l_port) == i_port_pos)
        {
            return true;
        }
    }

    // No port with this position exists, so return false
    return false;
}

///
/// @brief Unmask and setup actions performed after draminit_training
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::ODYSSEY specialization
///
template<>
fapi2::ReturnCode after_draminit_training<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    // Create registers and check success for MCBISTFIR and SRQFIR
    mss::fir::reg2<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR> l_mcbist_reg(i_target);
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);

    // Write MCBISTFIR register per Odyssey unmask spec
    FAPI_TRY(l_mcbist_reg.recoverable_error<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_COMMAND_ADDRESS_TIMEOUT>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_INTERNAL_FSM_ERROR>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>()
             .recoverable_error<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_SCOM_FATAL_REG_PE>()
             .write(), "Failed to write MCBIST FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Write SRQ LFIR register per Odyssey unmask spec
    l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_05>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_18>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_19>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_23>();

    // Port specific errors
    // Port 0
    if(is_port_present(l_ports, 0))
    {
        l_srq_reg.recoverable_error<scomt::ody::ODC_SRQ_LFIR_02>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_07>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_09>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_10>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_11>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_12>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_24>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_25>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_26>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_31>();
    }

    // Port 1
    if(is_port_present(l_ports, 1))
    {
        l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_27>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_32>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_36>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_37>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_38>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_39>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_41>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_42>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_43>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_45>();
    }

    FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_memdiags<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    constexpr uint8_t PORT0 = 0;
    constexpr uint8_t PORT1 = 1;

    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
    bool l_has_rcd = false;
    uint8_t l_is_planar = 0;
    bool l_mfg_thresholds = false;

    // Create registers and check success for SRQFIR
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);

    // Check MNFG THRESHOLDS Policy flag
    FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS, l_mfg_thresholds));
    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));
    FAPI_TRY(mss::attr::get_mem_mrw_is_planar(i_target, l_is_planar));

    // Unmask SRQ FIRs
    if (l_has_rcd && l_is_planar)
    {
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_13>(l_ports, PORT0, mss::fir::action::LXSTOP, l_srq_reg));
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_40>(l_ports, PORT1, mss::fir::action::LXSTOP, l_srq_reg));

        FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));
    }

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Create register for RDFFIR
        mss::fir::reg2<scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR> l_rdf_reg(l_port);

        if(!l_mfg_thresholds)
        {
            // Unmask FIR_MAINTENANCE_IUE to recoverable if Threshold not set
            l_rdf_reg.recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IUE>();
        }

        // Unmask remaining RDF FIRs
        FAPI_TRY(l_rdf_reg.checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_AUE>()
                 // Note: MAINLINE_UE will need to be changed to lxstop on P11
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_UE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_RCD>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_IAUE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_IUE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_IRCD>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_AUE>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IAUE>()
                 .write(), "Failed to Write RDF FIR register " GENTARGTIDFORMAT, GENTARGTID(l_port));
    }

fapi_try_exit:
    return fapi2::FAPI2_RC_SUCCESS;
}

} // end unmask ns
} // end mss ns
