/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/fir/exp_unmask.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file exp_unmask.C
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
#include <lib/shared/exp_defaults.H>
#include <lib/dimm/exp_kind.H>
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fld.H>
#include <lib/fir/exp_fir_traits.H>
#include <generic/memory/lib/utils/fir/gen_mss_unmask.H>
#include <mss_generic_attribute_getters.H>
#include <mss_generic_system_attribute_getters.H>
#include <mss_explorer_attribute_getters.H>
#include <lib/workarounds/exp_fir_workarounds.H>
#include <lib/phy/exp_phy_utils.H>
#include <generic/memory/lib/generic_attribute_accessors_manual.H>
#include <lib/exp_attribute_accessors_manual.H>

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_draminit_mc<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success for MCBISTFIR and SRQFIR and RDFFIR
    mss::fir::reg<EXPLR_MCBIST_MCBISTFIRQ> l_exp_mcbist_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srq_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_RDF_FIR> l_exp_rdf_reg(i_target, l_rc3);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_MCBIST_MCBISTFIRQ 0x%08X", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%08X", EXPLR_SRQ_SRQFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for EXPLR_RDF_FIR 0x%08X", EXPLR_RDF_FIR);

    // Write MCBISTFIR register per Explorer unmask spec
    FAPI_TRY(l_exp_mcbist_reg.attention<EXPLR_MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
             .write());

    // Write RDF FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_rdf_reg.recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_AUE>()
             .recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_IAUE>()
             .recoverable_error<EXPLR_RDF_FIR_RDDATA_VALID_ERROR>()
             .recoverable_error<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_STATUS>()
             .recoverable_error<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_RECOVERABLE>()
             .checkstop<EXPLR_RDF_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
             .checkstop<EXPLR_RDF_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW0>()
             .recoverable_error<EXPLR_RDF_FIR_ECC_RBUF_CE_DW1>()
             .checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW0>()
             .checkstop<EXPLR_RDF_FIR_ECC_RBUF_UE_DW1>()
             .write(), "Failed to Write RDF FIR register %s", mss::c_str(i_target));

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_REFRESH_OVERRUN>()
             .write());

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after draminit_training
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_draminit_training<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success for MCBISTFIR and SRQFIR
    mss::fir::reg<EXPLR_MCBIST_MCBISTFIRQ> l_exp_mcbist_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srq_reg(i_target, l_rc2);

    // Post-draminit: disable alert N bit on MASTER0_MEMALERTCONTROL
    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        FAPI_TRY(mss::exp::phy::disable_alert_n(l_port));
    }

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_MCBIST_MCBISTFIRQ 0x%08X", EXPLR_MCBIST_MCBISTFIRQ);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%08X", EXPLR_SRQ_SRQFIRQ);

    // Write MCBISTFIR register per Explorer unmask spec; omit bit 10 cmd_complete until draminit_mc
    FAPI_TRY(l_exp_mcbist_reg.recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_CCS_ARRAY_UNCORRECT_CE_OR_UE>()
             .recoverable_error<EXPLR_MCBIST_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .checkstop<EXPLR_MCBIST_MCBISTFIRQ_SCOM_FATAL_REG_PE>()
             .write());

    // Write SRQ FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_srq_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_MCB_LOGIC_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_MCB_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WRQ_RRQ_HANG_ERR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_SM_1HOT_ERR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_CMD_PARITY_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR2>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR3>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WDF_ERROR7>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_UE>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_LOGIC_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_NCF_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_NCF_CORR_ERROR>()
             .write(), "Failed to write SRQ FIR register for %s", mss::c_str(i_target));

fapi_try_exit:

    return fapi2::current_err;
}


///
/// @brief Unmask Explorer Global FIR and SPECIAL ATTN mask registers afer exp_omi_init
/// @param[in] i_target Explorer to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
template<>
fapi2::ReturnCode after_mc_omi_init<mss::mc_type::EXPLORER>(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    constexpr uint8_t EXPLR_TLXT_TLX_ERR1_REPORTQ_TLXT_INTRP_REQ_FAILED = 38;

    fapi2::ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS_Type l_omi_crc_dd1_mask = false;
    fapi2::ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS_Type l_omi_edpl_dd1_mask = false;
    fapi2::ATTR_MSS_EXP_INTR_MASK_DISABLE_Type l_intr_mask_disable = 0;
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc4 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_mnfg_screen_test_crc = false;
    bool l_mnfg_screen_test_edpl = false;

    mss::fir::reg<EXPLR_MMIO_MFIR> l_exp_mmio_mfir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_TLXT_TLXFIRQ> l_exp_tlxt_fir_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR> l_exp_local_fir_reg(i_target, l_rc3);
    mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG> l_exp_dlx_omi_fir_reg(i_target, l_rc4);

    FAPI_TRY(l_rc1, "for target %s unable to create fir::reg for EXPLR_MMIO_MFIR 0x%0x",
             mss::c_str(i_target), EXPLR_MMIO_MFIR);
    FAPI_TRY(l_rc2, "for target %s unable to create fir::reg for EXPLR_TLXT_TLXFIRQ 0x%0x",
             mss::c_str(i_target), EXPLR_TLXT_TLXFIRQ);
    FAPI_TRY(l_rc3, "for target %s unable to create fir::reg for EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR 0x%0x",
             mss::c_str(i_target), EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR);
    FAPI_TRY(l_rc4, "for target %s unable to create fir::reg for EXPLR_DLX_MC_OMI_FIR_REG 0x%0x",
             mss::c_str(i_target), EXPLR_DLX_MC_OMI_FIR_REG);

    // check chip EC attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS,
                           mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target),
                           l_omi_crc_dd1_mask),
             "%s Failed to read ATTR_CHIP_EC_FEATURE_OMI_CRC_FIRS",
             mss::c_str(i_target));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS,
                           mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target),
                           l_omi_edpl_dd1_mask),
             "%s Failed to read ATTR_CHIP_EC_FEATURE_OMI_EDPL_FIRS",
             mss::c_str(i_target));

    // check for mnfg OMI screen settings
    FAPI_TRY(mss::exp::check_omi_mfg_screen_crc_setting(l_mnfg_screen_test_crc));
    FAPI_TRY(mss::exp::check_omi_mfg_screen_edpl_setting(l_mnfg_screen_test_edpl));

    FAPI_TRY(mss::attr::get_exp_intr_mask_disable(i_target, l_intr_mask_disable));

    // Now that we've set up obj handles and command tags we can unmask the Explorer interrupts
    if (l_intr_mask_disable == fapi2::ENUM_ATTR_MSS_EXP_INTR_MASK_DISABLE_ENABLE)
    {
        fapi2::buffer<uint64_t> l_interrupt_mask;

        FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG, l_interrupt_mask));
        l_interrupt_mask.clearBit<EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG_SMASK_IN,
                                  EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG_SMASK_IN_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG, l_interrupt_mask));
    }

    // Setup MMIO MFIR unmasks per spec
    FAPI_TRY(l_exp_mmio_mfir_reg.recoverable_error<EXPLR_MMIO_MFIR_SCOM_ERR>()
             .checkstop<EXPLR_MMIO_MFIR_FSM_PERR>()
             .checkstop<EXPLR_MMIO_MFIR_FIFO_OVERFLOW>()
             .checkstop<EXPLR_MMIO_MFIR_CTL_REG_PERR>()
             .recoverable_error<EXPLR_MMIO_MFIR_INFO_REG_PERR>()
             .write());

    // Setup TLXT FIR unmasks per spec
    FAPI_TRY(l_exp_tlxt_fir_reg.checkstop<EXPLR_TLXT_TLXFIRQ_TLXT_PARITY_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_RECOVERABLE_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_CONFIG_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXT_INFORMATIONAL_PERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXT_HARD_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_MALFORMED>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXR_OC_PROTOCOL_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_ADDR_XLAT>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_METADATA_UNC_DPERR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_UNSUPPORTED>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_OC_FATAL>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_CONTROL_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLXR_INTERNAL_ERROR>()
             .recoverable_error<EXPLR_TLXT_TLXFIRQ_TLXR_INFORMATIONAL>()
             .write(), "Failed to write TLXT FIR unmasks for %s", mss::c_str(i_target));

    // Setup LOCAL FIR unmasks per spec
    FAPI_TRY(l_exp_local_fir_reg.recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN0>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN1>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN2>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN8>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_IN63>()
             .write(), "Failed to write LOCAL FIR unmasks for %s", mss::c_str(i_target));

    // Set up MNFG OMI screen or DD1 workaround settings for CRC and EDPL FIRs
    exp::workarounds::fir::omi_crc_after_omi_init(i_target,
            l_omi_crc_dd1_mask,
            l_mnfg_screen_test_crc,
            l_exp_dlx_omi_fir_reg);
    exp::workarounds::fir::omi_edpl_after_omi_init(i_target,
            l_omi_edpl_dd1_mask,
            l_mnfg_screen_test_edpl,
            l_exp_dlx_omi_fir_reg);

    // Setup MC OMI FIR unmasks per spec
    FAPI_TRY(l_exp_dlx_omi_fir_reg.recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_FLIT_CE>()
             .write());

    // Setup checker masks for certain FIRs
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TLXT_TLX_ERR0_REPORTQ_MASK, l_reg_data));
    l_reg_data.setBit<EXPLR_TLXT_TLX_ERR0_REPORTQ_BAR0_PERR_NF>()
    .setBit<EXPLR_TLXT_TLX_ERR0_REPORTQ_ADDR_XLATE_HOLE>()
    .setBit<EXPLR_TLXT_TLX_ERR0_REPORTQ_BAD_DATA_RXD>()
    .setBit<EXPLR_TLXT_TLX_ERR0_REPORTQ_EPOW_SIGNALLED>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TLXT_TLX_ERR0_REPORTQ_MASK, l_reg_data));

    // Per FIR spec: TLXFIRQ_TLXR_BAR0_OR_MMIO_NF: Bar0 parity error
    // Want to route this to TLXTFIR[25] instead, and configure as fatal,
    // since we don't plan to rewrite the bar0 reg to recover
    // Set TLX_ERR0_REPORTQ_MASK[8] = 1, to keep this from setting TLXTFIR[17]
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TLXT_TLX_ERR1_REPORTQ_MASK, l_reg_data));
    l_reg_data.setBit<EXPLR_TLXT_TLX_ERR1_REPORTQ_TLXT_INTRP_REQ_FAILED>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TLXT_TLX_ERR1_REPORTQ_MASK, l_reg_data));
    // Set TLXCFG1[6]: TLXCFG1_SHUTDOWN_ON_BAR0_BAD = 1, to trigger TLXTFIR[25]
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TLXT_TLXCFG1, l_reg_data));
    l_reg_data.setBit<EXPLR_TLXT_TLXCFG1_SHUTDOWN_ON_BAR0_BAD>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TLXT_TLXCFG1, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_scominit
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_scominit<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;

    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srqfir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR> l_exp_local_fir_reg(i_target, l_rc2);

    FAPI_TRY(l_rc1, "for target %s unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%016x",
             mss::c_str(i_target), EXPLR_SRQ_SRQFIRQ);
    FAPI_TRY(l_rc2, "for target %s unable to create fir::reg for EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR 0x%0x",
             mss::c_str(i_target), EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR);

    // Unmask SRQFIR bits specified by PRD spec
    FAPI_TRY(l_exp_srqfir_reg.recoverable_error<EXPLR_SRQ_SRQFIRQ_MBA_RECOVERABLE_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_MBA_NONRECOVERABLE_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_REG_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_INFO_REG_PARITY_ERROR>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_DEBUG_PARITY_ERROR>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR0>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR1>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR4>()
             .recoverable_error<EXPLR_SRQ_SRQFIRQ_WDF_ERROR5>()
             .checkstop<EXPLR_SRQ_SRQFIRQ_WDF_ERROR6>()
             .write(), "Failed to write SRQFIR for %s", mss::c_str(i_target));

    // Unmask DDR4_PHY bits per PRD spec
    FAPI_TRY(l_exp_local_fir_reg.recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_DDR4_PHY__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_DDR4_PHY__NON_FATAL>()
             .write());

    // Set FARB0 [54,57] to disable RCD recovery and port fail
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_SRQ_MBA_FARB0Q, l_reg_data));

    l_reg_data.setBit<EXPLR_SRQ_MBA_FARB0Q_CFG_DISABLE_RCD_RECOVERY>()
    .setBit<EXPLR_SRQ_MBA_FARB0Q_CFG_PORT_FAIL_DISABLE>();

    FAPI_TRY(fapi2::putScom(i_target, EXPLR_SRQ_MBA_FARB0Q, l_reg_data));

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// TODO: Need to implement this function
template<>
fapi2::ReturnCode after_phy_reset<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Unmask and setup actions performed after exp_omi_setup
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
///
template<>
fapi2::ReturnCode after_mc_omi_setup<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    constexpr uint64_t MASK_ALL = ~0ull;

    fapi2::ATTR_OMI_X4_DEGRADE_ACTION_Type l_degrade_fail_action = 0;
    fapi2::ATTR_OMI_CRC_DEBUG_Type l_omi_crc_debug = 0;
    fapi2::ATTR_MSS_EXP_INTR_MASK_DISABLE_Type l_intr_mask_disable = 0;
    fapi2::buffer<uint64_t> l_dl0_error_mask;
    fapi2::buffer<uint64_t> l_global_fir_mask_reg;
    fapi2::buffer<uint64_t> l_global_spa_attn_reg;

    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success
    mss::fir::reg<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR> l_exp_local_fir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_TLXT_TLXFIRQ> l_exp_tlx_fir_reg(i_target, l_rc2);
    mss::fir::reg<EXPLR_DLX_MC_OMI_FIR_REG> l_exp_mc_omi_fir_reg(i_target, l_rc3);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR 0x%08X", EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_TLXT_TLXFIRQ 0x%08X", EXPLR_TLXT_TLXFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for EXPLR_DLX_MC_OMI_FIR_REG 0x%08X", EXPLR_DLX_MC_OMI_FIR_REG);

    FAPI_TRY(mss::attr::get_omi_x4_degrade_action(l_degrade_fail_action));
    FAPI_TRY(mss::attr::get_omi_crc_debug(l_omi_crc_debug));
    FAPI_TRY(mss::attr::get_exp_intr_mask_disable(i_target, l_intr_mask_disable));

    // Before we unmask any FIRs we need to mask all Explorer interrupts due to SW515594
    if (l_intr_mask_disable == fapi2::ENUM_ATTR_MSS_EXP_INTR_MASK_DISABLE_ENABLE)
    {
        fapi2::buffer<uint64_t> l_interrupt_mask;

        // Special handling for this scom because it wasn't available in very old versions of Explorer FW
        fapi2::ReturnCode l_rc_scom = fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG, l_interrupt_mask);

        if (l_rc_scom != fapi2::FAPI2_RC_SUCCESS)
        {
            fapi2::logError(l_rc_scom, fapi2::FAPI2_ERRL_SEV_RECOVERED);
            FAPI_ASSERT(false,
                        fapi2::MSS_EXP_SUM_MASK_REG_SCOM_FAIL().
                        set_OCMB_TARGET(i_target).
                        set_ADDRESS(EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG),
                        "%s Scom fail for EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG. Possibly due to old Explorer FW version. Needs to be at least CL402648",
                        mss::c_str(i_target) );
        }

        l_interrupt_mask.setBit<EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG_SMASK_IN,
                                EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG_SMASK_IN_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_SUM_MASK_REG, l_interrupt_mask));
    }

    // Write LOCAL_FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_local_fir_reg.recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_106>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_111>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PCS_GPBC_IRQ_112>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PROC_SS__TOP_FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_PROC_SS__TOP_NON_FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_7__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_6__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_5__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_4__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_3__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_2__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_1__FATAL>()
             .recoverable_error<EXPLR_TP_MB_UNIT_TOP_LOCAL_FIR_FOXHOUND_LANE_0__FATAL>()
             .write(), "Failed to write LOCAL_FIR register for %s", mss::c_str(i_target));

    // Write TLX FIR register per Explorer unmask spec
    FAPI_TRY(l_exp_tlx_fir_reg.recoverable_error<EXPLR_TLXT_TLXFIRQ_INFO_REG_PARITY_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_CTRL_REG_PARITY_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLX_VC0_MAX_CRD_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLX_VC1_MAX_CRD_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLX_DCP0_MAX_CRD_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_TLX_DCP3_MAX_CRD_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_CREDIT_MGMT_ERROR>()
             .checkstop<EXPLR_TLXT_TLXFIRQ_CREDIT_MGMT_PERROR>()
             .write(), "Failed to write TLX FIR register for %s", mss::c_str(i_target));

    // Write MC_OMI FIR register per Explorer unmask spec
    // Note: Explorer doesn't initialize its DLX_MC_OMI_FIR masks to the masked state, so mask them all first
    FAPI_DBG("Masking entire EXPLR_DLX_MC_OMI_FIR_MASK_REG on %s", mss::c_str(i_target));
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_DLX_MC_OMI_FIR_MASK_REG, MASK_ALL));
    l_exp_mc_omi_fir_reg.checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
    .checkstop<EXPLR_DLX_MC_OMI_FIR_REG_DL0_DATA_UE>()
    .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_X4_MODE>()
    .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_TIMEOUT>()
    .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
    .recoverable_error<EXPLR_DLX_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();

    // Set up OMI CRC debug mode if requested
    mss::exp::workarounds::fir::override_omi_crc_firs(i_target, l_omi_crc_debug, l_exp_mc_omi_fir_reg);

    // Set up x4 degrade FIR attribute overrides
    mss::exp::workarounds::fir::override_x4_degrade_fir(i_target, l_degrade_fail_action, l_exp_mc_omi_fir_reg);

    FAPI_TRY(l_exp_mc_omi_fir_reg.write(), "Failed to write MC_OMI FIR register for %s", mss::c_str(i_target));

    FAPI_TRY(fapi2::getScom(i_target, EXPLR_DLX_DL0_ERROR_MASK, l_dl0_error_mask));
    l_dl0_error_mask.setBit<EXPLR_DLX_DL0_ERROR_MASK_47>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_46>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_45>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_44>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_43>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_42>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_41>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_40>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_38>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_37>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_36>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_33>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_32>()
    .setBit<EXPLR_DLX_DL0_ERROR_MASK_18>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_17>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_16>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_15>()
    .clearBit<EXPLR_DLX_DL0_ERROR_MASK_14>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_DLX_DL0_ERROR_MASK, l_dl0_error_mask));

    // Pull global fir mask state and unmask bits per spec
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_FIR_MASK, l_global_fir_mask_reg));
    l_global_fir_mask_reg.clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN0>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN3>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN4>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN7>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN8>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN9>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN11>()
    .clearBit<EXPLR_TP_MB_UNIT_TOP_XFIR_IN12>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_FIR_MASK, l_global_fir_mask_reg));

    // Pull global special attn state and unmask bits per spec
    FAPI_TRY(fapi2::getScom(i_target, EXPLR_TP_MB_UNIT_TOP_SPA_MASK, l_global_spa_attn_reg));
    l_global_spa_attn_reg.clearBit<EXPLR_TP_MB_UNIT_TOP_SPATTN_IN5>();
    FAPI_TRY(fapi2::putScom(i_target, EXPLR_TP_MB_UNIT_TOP_SPA_MASK, l_global_spa_attn_reg));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
template<>
fapi2::ReturnCode after_memdiags<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::buffer<uint64_t> l_reg_data;
    bool l_mfg_thresholds = false;

    mss::fir::reg<EXPLR_RDF_FIR> l_exp_rdf_fir_reg(i_target, l_rc1);
    mss::fir::reg<EXPLR_SRQ_SRQFIRQ> l_exp_srq_srqfirq_reg(i_target, l_rc2);

    FAPI_TRY(l_rc1, "unable to create fir::reg for EXPLR_RDF_FIR 0x%08X", EXPLR_RDF_FIR);
    FAPI_TRY(l_rc2, "unable to create fir::reg for EXPLR_SRQ_SRQFIRQ 0x%08X", EXPLR_SRQ_SRQFIRQ);

    // Check MNFG THRESHOLDS Policy flag
    FAPI_TRY(mss::check_mfg_flag(fapi2::ENUM_ATTR_MFG_FLAGS_MNFG_THRESHOLDS, l_mfg_thresholds));

    if(!l_mfg_thresholds)
    {
        // Unmask FIR_MAINTENANCE_IUE to recoverable if Threshold not set
        l_exp_rdf_fir_reg.recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_IUE>();
    }

    // Write remainder of RDF FIR mask per Explorer unmask spec
    FAPI_TRY(l_exp_rdf_fir_reg.checkstop<EXPLR_RDF_FIR_MAINLINE_AUE>()
             .recoverable_error<EXPLR_RDF_FIR_MAINLINE_UE>()
             .checkstop<EXPLR_RDF_FIR_MAINLINE_IAUE>()
             .recoverable_error<EXPLR_RDF_FIR_MAINLINE_IUE>()
             .checkstop_nomask<EXPLR_RDF_FIR_MAINTENANCE_AUE>()
             .checkstop_nomask<EXPLR_RDF_FIR_MAINTENANCE_IAUE>()
             .write(), "Failed to write RDF FIR mask and action regs for %s", mss::c_str(i_target));

    // Write SRQ FIR mask per Explorer unmask spec
    FAPI_TRY(l_exp_srq_srqfirq_reg.checkstop<EXPLR_SRQ_SRQFIRQ_PORT_FAIL>().write());

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for scrub related FIR
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note mc_type::EXPLORER specialization
template<>
fapi2::ReturnCode after_background_scrub<mss::mc_type::EXPLORER>( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>&
        i_target )
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    mss::fir::reg<EXPLR_RDF_FIR> l_exp_rdf_fir_reg(i_target, l_rc);

    FAPI_TRY(l_rc, "unable to create fir::reg for EXPLR_RDF_FIR 0x%08X", EXPLR_RDF_FIR);

    // Write RDF FIR per Explorer unmask spec
    FAPI_TRY((l_exp_rdf_fir_reg.recoverable_error<EXPLR_RDF_FIR_MAINLINE_MPE_RANK_0_TO_7,
              EXPLR_RDF_FIR_MAINLINE_MPE_RANK_0_TO_7_LEN>()
              .recoverable_error<EXPLR_RDF_FIR_MAINLINE_NCE>()
              .recoverable_error<EXPLR_RDF_FIR_MAINLINE_TCE>()
              .recoverable_error<EXPLR_RDF_FIR_MAINLINE_IMPE>()
              .recoverable_error<EXPLR_RDF_FIR_MAINTENANCE_IMPE>()
              .write()), "Failed to write RDF FIR for %s", mss::c_str(i_target));

fapi_try_exit:

    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns
