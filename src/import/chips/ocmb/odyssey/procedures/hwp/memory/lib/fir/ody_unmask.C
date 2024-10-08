/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/fir/ody_unmask.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
#include <ody_scom_omi_odc.H>
#include <ody_scom_mp.H>
#include <ody_scom_mp_mastr_b0.H>
#include <ody_scom_mp_drtub0.H>
#include <poz_scom_perv_tpchip.H>
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
/// @brief Unmask and setup actions specifically related to ODP_FIR PhyStickyUnlockErr
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode unmask_phy_sticky_unlock_err( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    fapi2::buffer<uint64_t> l_reg_data;
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    for (const auto& l_port : l_ports)
    {
        mss::fir::reg2<scomt::mp::S_LFIR_RW_WCLEAR> l_top0_lfir(l_port);

        // Phy special set up

        //PhyInterruptEnable bit [15]
        FAPI_TRY(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE, l_reg_data));
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYSTICKYUNLOCKEN>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE, l_reg_data));


        // LcdlDbgCntl3_p0 setup StickyUnlockThreshold - recommended minimum threshold is 3 = 0b011
        constexpr uint64_t l_min_stickythreshold = 0x0000000000000003;
        FAPI_TRY(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_LCDLDBGCNTL3_P0, l_reg_data));
        l_reg_data.insertFromRight<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_LCDLDBGCNTL3_P0_STICKYUNLOCKTHRESHOLD,
                                   scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_LCDLDBGCNTL3_P0_STICKYUNLOCKTHRESHOLD_LEN>
                                   (l_min_stickythreshold);
        FAPI_TRY(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_LCDLDBGCNTL3_P0, l_reg_data));

        FAPI_TRY(l_top0_lfir.recoverable_error<scomt::mp::S_LFIR_PHYSTICKYUNLOCKERR>()
                 .write(), "Failed to Write ODP FIR register " GENTARGTIDFORMAT, GENTARGTID(l_port));
    }

fapi_try_exit:

    return fapi2::current_err;
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
    FAPI_TRY(l_mcbist_reg.recoverable_error<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>()
             .recoverable_error<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .checkstop<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_SCOM_FATAL_REG_PE>()
             .write(), "Failed to write MCBIST FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Write SRQ LFIR register per Odyssey unmask spec
    l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_IN05>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN18>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN19>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN23>();

    // Port specific errors
    // Port 0
    if(is_port_present(l_ports, 0))
    {
        l_srq_reg.recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN02>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN07>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN09>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN10>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN11>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN12>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN24>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN25>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN26>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN31>();
    }

    // Port 1
    if(is_port_present(l_ports, 1))
    {
        l_srq_reg.checkstop<scomt::ody::ODC_SRQ_LFIR_IN27>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN32>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN36>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN37>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN38>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN39>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN41>()
        .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN42>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN43>()
        .checkstop<scomt::ody::ODC_SRQ_LFIR_IN45>();
    }

    FAPI_TRY(l_srq_reg.write(), "Failed to write SRQ FIR register for " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Workaround: unmask ODP FIR PhyStickyUnlockErr here to avoid it coming on during training
    FAPI_TRY(unmask_phy_sticky_unlock_err(i_target));

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
/// @brief Unmask and setup actions performed after omi_init - specialization for Odyssey
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Code is based upon the RAS document from 1FEB2023
///
template<>
fapi2::ReturnCode after_mc_omi_init<mss::mc_type::ODYSSEY>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_reg_data;

    // Create registers and check success for SRQFIR
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);

    // Create register for MMIO_MFIR, TLX_LFIR, and MC_OMI_FIR
    mss::fir::reg2<scomt::ody::ODC_MMIO_MFIR_RW_WCLEAR> l_mmio_mfir_reg(i_target);
    mss::fir::reg2<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_RW_WCLEAR> l_tlx_lfir_reg(i_target);
    mss::fir::reg2<scomt::omi::D_REG_MC_OMI_FIR_RW_WCLEAR> l_mc_omi_fir_reg(i_target);

    // Unmask MMIO_MFIR
    FAPI_TRY(l_mmio_mfir_reg.checkstop<scomt::ody::ODC_MMIO_MFIR_FSM_PERR>()
             .checkstop<scomt::ody::ODC_MMIO_MFIR_FIFO_OVERFLOW>()
             .checkstop<scomt::ody::ODC_MMIO_MFIR_CTL_REG_PERR>()
             .recoverable_error<scomt::ody::ODC_MMIO_MFIR_INFO_REG_PERR>()
             .write(), "Failed to Write MMIO MFIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Unmask TLX_LFIR
    FAPI_TRY(l_tlx_lfir_reg.checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN08>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN09>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN10>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN11>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN12>()
             .recoverable_error<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN13>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN14>()
             .recoverable_error<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN15>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN17>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN18>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN19>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN20>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN21>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN23>()
             .checkstop<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN25>()
             .recoverable_error<scomt::ody::ODC_TLXT_REGS_TLX_LFIR_IN26>()
             .write(), "Failed to Write TLX LFIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Special setup for checkers that feed MC_OMI_FIR
    FAPI_TRY(fapi2::getScom(i_target, scomt::omi::D_REG_DL0_ERROR_MASK, l_reg_data));
    l_reg_data.clearBit<scomt::omi::D_REG_DL0_ERROR_MASK_14>()
    .clearBit<scomt::omi::D_REG_DL0_ERROR_MASK_15>()
    .clearBit<scomt::omi::D_REG_DL0_ERROR_MASK_16>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::omi::D_REG_DL0_ERROR_MASK, l_reg_data));

    // Unmask MC_OMI_FIR
    FAPI_TRY(l_mc_omi_fir_reg.recoverable_error<scomt::omi::D_REG_MC_OMI_FIR_DL0_FLIT_CE>()
             .write(), "Failed to Write MC OMI FIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));

    // Unmask IPOLL bits to enable interrupts
    FAPI_TRY(fapi2::getScom(i_target, scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG, l_reg_data));
    l_reg_data.clearBit<scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG_ERROR_MASK_0>();
    l_reg_data.clearBit<scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG_ERROR_MASK_1>();
    l_reg_data.clearBit<scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG_ERROR_MASK_2>();
    l_reg_data.clearBit<scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG_ERROR_MASK_3>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::poz::PCBCTL_COMP_INTR_HOST_MASK_REG, l_reg_data));

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
    l_srq_lfir.checkstop<scomt::ody::ODC_SRQ_LFIR_IN01>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN16>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN17>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN20>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN22>()
    .checkstop<scomt::ody::ODC_SRQ_LFIR_IN44>()

    // Recoverables + unmasks
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN14>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN21>()
    .recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN29>();

    // Port specific errors
    // Port 0
    if(is_port_present(l_ports, mss::unmask::IDX_PORT0))
    {
        l_srq_lfir.recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN30>();
    }

    // Port 1
    if(is_port_present(l_ports, mss::unmask::IDX_PORT1))
    {
        l_srq_lfir.recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN34>();
    }

    FAPI_TRY(mss::has_rcd(i_target, l_has_rcd));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, i_target, l_is_planar));

    // Things get interesting if we have an RCD on a planar system
    if(l_has_rcd && l_is_planar)
    {
        // Disable the port fail and RCD recovery mechanisms (they will be enabled after memdiags)
        FAPI_TRY(after_scominit_disable_rcd_recovery_helper(i_target));

        // Set the RCD errors to recoverable based upon the port
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN04>(l_ports,
                 mss::unmask::IDX_PORT0,
                 mss::fir::action::RECOV,
                 l_srq_lfir));
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN33>(l_ports,
                 mss::unmask::IDX_PORT1,
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
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MRW_IS_PLANAR, i_target, l_is_planar));

    // Unmask SRQ FIRs
    if (l_has_rcd && l_is_planar)
    {
        // Enable the port fail and RCD recovery mechanisms and set RCD protection time
        FAPI_TRY(after_memdiags_enable_rcd_recovery_helper(i_target));

        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN13>(l_ports,
                 mss::unmask::IDX_PORT0,
                 mss::fir::action::LXSTOP,
                 l_srq_reg));
        FAPI_TRY(set_fir_bit_if_port_has_rcd<scomt::ody::ODC_SRQ_LFIR_IN40>(l_ports,
                 mss::unmask::IDX_PORT1,
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
    FAPI_TRY(l_mcbist_reg.attention<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
             .write(), "Failed to Write MCBIST FIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        // Create register for RDFFIR
        mss::fir::reg2<scomt::ody::ODC_RDF0_SCOM_FIR_RW_WCLEAR> l_rdf_reg(l_port);

        // These checkers should reset to '0' (unmasked state) but we clear them just in case
        FAPI_TRY(fapi2::getScom(l_port, scomt::ody::ODC_RDF0_SCOM_MASK1, l_reg_data));
        l_reg_data.clearBit<scomt::ody::ODC_RDF0_SCOM_MASK1_UNEXPECTED_RDDATA_VALID>();
        l_reg_data.clearBit<scomt::ody::ODC_RDF0_SCOM_MASK1_MISSING_RDDATA_VALID>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::ody::ODC_RDF0_SCOM_MASK1, l_reg_data));

        // Write RDF FIR register per Odyssey unmask spec
        FAPI_TRY(l_rdf_reg.recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IAUE>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_IRCD>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_MAINTENANCE_RCD>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_RDDATA_VALID_ERROR>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_STATUS>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_RECOVERABLE>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_CE_DW0>()
                 .recoverable_error<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_CE_DW1>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_UE_DW0>()
                 .checkstop<scomt::ody::ODC_RDF0_SCOM_FIR_ECC_RBUF_UE_DW1>()
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

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_phy_reset<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    fapi2::buffer<uint64_t> l_reg_data;
    const auto& l_ports = mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target);

    for (const auto& l_port : l_ports)
    {
        // Create register for ODP_TOP0 temporarily declared in ody_fir_traits.h until added into engd
        mss::fir::reg2<scomt::mp::S_LFIR_RW_WCLEAR> l_top0_lfir(l_port);

        // Phy special set up
        // Workaround: ODP FIR PhyStickyUnlockErr unmasked after draminit to avoid it coming on during training

        //PhyInterruptEnable bits [12-8]
        FAPI_TRY(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE, l_reg_data));
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYD5ACSM0PARITYEN>();
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYD5ACSM1PARITYEN>();
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYRXFIFOCHECKEN>();
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYTXPPTEN>();
        l_reg_data.setBit<scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE_PHYECCEN>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_MASTER0_BASE0_PHYINTERRUPTENABLE, l_reg_data));

        // ArcPmuEccCtl Overrides/Control for ARC Error Protection Hardware Control Register, ECC Enable => Bits 1:0 = 0b00, Do not change Debug Bits 2:5
        FAPI_TRY(fapi2::getScom(l_port, scomt::mp::DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL, l_reg_data));
        l_reg_data.clearBit<scomt::mp::DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL_ARCPMUECCCTL, 2>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::mp::DWC_DDRPHYA_DRTUB0_ARCPMUECCCTL, l_reg_data));

        // Flush reg and clear PHYERR bit 5 before unmasking since it comes on erroneously during Odyssey ABIST
        l_reg_data.flush<0>();
        l_reg_data.setBit<scomt::mp::S_LFIR_PHYERR>();
        FAPI_TRY(fapi2::putScom(l_port, scomt::mp::S_LFIR_RW_WCLEAR, l_reg_data));

        FAPI_TRY(l_top0_lfir.recoverable_error<scomt::mp::S_LFIR_FSMPERR>()
                 .recoverable_error<scomt::mp::S_LFIR_WPERR>()
                 .recoverable_error<scomt::mp::S_LFIR_PSLVPERR>()
                 .recoverable_error<scomt::mp::S_LFIR_ODPCTRLPERR>()
                 .recoverable_error<scomt::mp::S_LFIR_PHYD5ACSM0PARITYERR>()
                 .recoverable_error<scomt::mp::S_LFIR_PHYD5ACSM1PARITYERR>()
                 // Workaround: Leaving PHYRXFIFOCHECKERR masked since it is lighting erroneously at mainline
                 //.recoverable_error<scomt::mp::S_LFIR_PHYRXFIFOCHECKERR>()
                 .recoverable_error<scomt::mp::S_LFIR_PHYRXTXPPTERR>()
                 .recoverable_error<scomt::mp::S_LFIR_PHYECCERR>()
                 .write(), "Failed to Write ODP FIR register " GENTARGTIDFORMAT, GENTARGTID(l_port));
    }

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Re-mask MCBIST_PROGRAM_COMPLETE at the beginning of Cronus memdiags
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids an unnecessary processor attention when the sf_init program completes in memdiags
///
fapi2::ReturnCode pre_init_mask_prog_complete( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    // Create register for MCBISTFIR
    mss::fir::reg2<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR> l_mcbist_reg(i_target);

    // Re-mask MCBISTFIR PROGRAM_COMPLETE before Cronus mode memdiags
    FAPI_TRY(l_mcbist_reg.remask<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>(),
             "Failed to Write MCBIST FIR Mask register " GENTARGTIDFORMAT, GENTARGTID(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear and Re-unmask MCBIST_PROGRAM_COMPLETE at the end of Cronus memdiags
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note this avoids an unnecessary processor attention when the sf_init program completes in memdiags
///
fapi2::ReturnCode post_init_unmask_prog_complete( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    // Create register for MCBISTFIR
    mss::fir::reg2<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_RW_WCLEAR> l_mcbist_reg(i_target);

    // Clear and re-unmask MCBISTFIR PROGRAM_COMPLETE after Cronus mode memdiags
    FAPI_TRY(l_mcbist_reg.clear<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>(),
             "Failed to Clear MCBIST FIR register " GENTARGTIDFORMAT, GENTARGTID(i_target));
    FAPI_TRY(l_mcbist_reg.attention<scomt::ody::ODC_MCBIST_SCOM_MCBISTFIRQ_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
             .write(), "Failed to Write MCBIST FIR Mask register " GENTARGTIDFORMAT, GENTARGTID(i_target));

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Set a FIR bit to recoverable, unmask and set it for DQS drift tracking error path
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::ODYSSEY specialization
///
template<>
fapi2::ReturnCode dqs_drift_track_error<mss::mc_type::ODYSSEY>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    // Create registers and check success for SRQFIR
    mss::fir::reg2<scomt::ody::ODC_SRQ_LFIR_RW_WCLEAR> l_srq_reg(i_target);
    fapi2::buffer<uint64_t> l_reg_data;

    // Set to recoverable and unmask
    FAPI_TRY(l_srq_reg.recoverable_error<scomt::ody::ODC_SRQ_LFIR_IN47>().write(),
             "Failed to write SRQ FIR register for" GENTARGTIDFORMAT, GENTARGTID(i_target));

    l_reg_data.setBit<scomt::ody::ODC_SRQ_LFIR_IN47>();
    FAPI_TRY(fapi2::putScom(i_target, scomt::ody::ODC_SRQ_LFIR_WO_OR, l_reg_data));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns
