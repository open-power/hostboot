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
#include <ody_scom_ody_odc.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/fir/ody_fir_traits.H>
#include <lib/fir/ody_unmask.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <mss_generic_system_attribute_getters.H>

namespace mss
{

namespace unmask
{

constexpr uint8_t IDX_PORT0 = 0;
constexpr uint8_t IDX_PORT1 = 1;

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
/// @brief Helper function to disable the RCD recovery
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Code is based upon the RAS document from 13DEC2022
///
fapi2::ReturnCode after_scominit_disable_rcd_recovery_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_data));
    l_data.setBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>()
    .setBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function to enable the RCD recovery
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Code is based upon the RAS document from 16DEC2022
///
fapi2::ReturnCode after_memdiags_enable_rcd_recovery_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::buffer<uint64_t> l_dsm0;
    fapi2::buffer<uint64_t> l_farb0;
    uint8_t l_wrdone_dly = 0;

    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_DSM0Q, l_dsm0));
    l_dsm0.extractToRight<scomt::ody::ODC_SRQ_MBA_DSM0Q_WRDONE_DLY, scomt::ody::ODC_SRQ_MBA_DSM0Q_WRDONE_DLY_LEN>
    (l_wrdone_dly);

    // Prevent an underflow of RCD_PROTECTION_TIME since we subtract 1 below
    l_wrdone_dly = (l_wrdone_dly < 1) ? 1 : l_wrdone_dly;

    // Per the unmask spec, need to set DISABLE_RCD_RECOVERY and PORT_FAIL_DISABLE to '0'
    // and set RCD_PROTECTION_TIME to just less than WRDONE_DLY
    FAPI_TRY(fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_farb0));

    l_farb0.clearBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>()
    .clearBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE>()
    .insertFromRight<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME,
                     scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_RCD_PROTECTION_TIME_LEN>(l_wrdone_dly - 1);

    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_farb0));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_scominit - specialization for Odyssey
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Code is based upon the RAS document from 13DEC2022
///
template<>
fapi2::ReturnCode after_scominit<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);
    bool l_has_rcd = false;
    uint8_t l_is_planar = 0;

    // Creates the fir class
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_lfir(i_target);

    // Checkstops + unmasks
    l_srq_lfir.checkstop<scomt::ody::ODC_SRQ_LFIR_01>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_16>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_17>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_20>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_22>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_44>()

    // Recoverables + unmasks
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_14>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_21>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_29>();

    // Port specific errors
    // Port 0
    if(is_port_present(l_ports, IDX_PORT0))
    {
        l_srq_lfir.recoverable_error<scomt::ody::ODC_SRQ_LFIR_30>();
    }

    // Port 1
    if(is_port_present(l_ports, IDX_PORT1))
    {
        l_srq_lfir.recoverable_error<scomt::ody::ODC_SRQ_LFIR_34>();
    }

    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));
    FAPI_TRY(mss::attr::get_mem_mrw_is_planar(i_target, l_is_planar));

    // Things get interesting if we have an RCD on a planar system
    if(l_has_rcd && l_is_planar)
    {
        // Disable the port fail and RCD recovery mechanisms (they will be enabled after memdiags)
        FAPI_TRY(after_scominit_disable_rcd_recovery_helper(i_target));

        // Set the RCD errors to recoverable based upon the port
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_04>(l_ports,
                 IDX_PORT0,
                 mss::fir::action::RECOV,
                 l_srq_lfir));
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_33>(l_ports,
                 IDX_PORT1,
                 mss::fir::action::RECOV,
                 l_srq_lfir));
    }

    // Configure the FIR register
    FAPI_TRY(l_srq_lfir.write());

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
        // Enable the port fail and RCD recovery mechanisms and set RCD protection time
        FAPI_TRY(after_memdiags_enable_rcd_recovery_helper(i_target));

        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_13>(l_ports,
                 IDX_PORT0,
                 mss::fir::action::LXSTOP,
                 l_srq_reg));
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_40>(l_ports,
                 IDX_PORT1,
                 mss::fir::action::LXSTOP,
                 l_srq_reg));

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

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::ODYSSEY specialization
///
template<>
fapi2::ReturnCode after_draminit_mc<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::buffer<uint64_t> l_reg_data;

    // Create register for MCBISTFIR
    mss::fir::reg2<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR> l_mcbist_reg(i_target);

    // Write MCBISTFIR register per Odyssey unmask spec
    // NOTE: when this gets ported to p11 this will need to be changed to recoverable
    FAPI_TRY(l_mcbist_reg.attention<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_ISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
             .write(), "Failed to Write MCBIST FIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Create register for RDFFIR
        mss::fir::reg2<scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR> l_rdf_reg(l_port);

        // Set this to mask off missing dfi_rddata_valid from triggering ODC_RDF0_SCOM_FIR_RDDATA_VALID_ERROR
        FAPI_TRY(fapi2::getScom(l_port, scomt::ody::ODC_RDF0_SCOM_MASK1, l_reg_data));
        l_reg_data.setBit<scomt::ody::ODC_RDF0_SCOM_MASK1_MISSING_RDDATA_VALID>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::ody::ODC_RDF0_SCOM_MASK1, l_reg_data));

        // Write RDF FIR register per Odyssey unmask spec
        FAPI_TRY(l_rdf_reg.recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_AUE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IAUE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IRCD>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_RCD>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_RDDATA_VALID_ERROR>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_STATUS>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_RECOVERABLE>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_CE_DW0>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_UE_DW0>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_TLXT_RDF_RBUF_PERR>()
                 .write(), "Failed to Write RDF FIR register " GENTARGTIDFORMAT, GENTARGTID(l_port));
    }

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for scrub related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::ODYSSEY specialization
template<>
fapi2::ReturnCode after_background_scrub<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Create register for RDFFIR
        mss::fir::reg2<scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR> l_rdf_reg(l_port);

        // Write RDF FIR register per Odyssey unmask spec
        // Note we can't put MAINLINE_MPE_RANK_0_TO_7 into the FAPI_TRY because it won't parse within the macro
        l_rdf_reg.recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_MPE_RANK_0_TO_7,
                                    scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_MPE_RANK_0_TO_7_LEN>()
                                    .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_NCE>()
                                    .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_TCE>()
                                    .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINLINE_IMPE>()
                                    .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IMPE>();
        FAPI_TRY( l_rdf_reg.write(), "Failed to Write RDF FIR register " GENTARGTIDFORMAT, GENTARGTID(l_port) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns
