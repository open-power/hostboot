/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/unmask.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file unmask.C
/// @brief Subroutines for unmasking and setting up MSS FIR
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <lib/shared/nimbus_defaults.H>
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>
#include <lib/utils/find_magic.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/utils/nimbus_find.H>
#include <lib/fir/fir.H>
#include <lib/mc/port.H>
#include <lib/fir/unmask.H>
#include <lib/workarounds/mcbist_workarounds.H>

using fapi2::TARGET_TYPE_MCBIST;
using fapi2::TARGET_TYPE_MCA;

namespace mss
{

namespace unmask
{

///
/// @brief Unmask and setup actions performed after draminit_mc
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_draminit_mc<mss::mc_type::NIMBUS>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("unmask mss fir after draminit_mc");

    fapi2::ReturnCode l_rc;

    // TK - unclear right now if these can become generic per MCBIST or whether these are specific
    // to Nimbus. If they can be generic,this whole thing can go back in the H file and the specifics
    // of the registers and bits can be handled generically.

    fir::reg<MCBIST_MCBISTFIRQ> l_mcbist_fir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCBIST_MCBISTFIRQ);

    // Setup mcbist fir. All mcbist attentions are already special attentions
    // Write this out before the work-around as it will read and write.
    l_mcbist_fir_reg.attention<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>();

    FAPI_TRY(l_mcbist_fir_reg.write(), "unable to write fir::reg %d", MCBIST_MCBISTFIRQ);

    // Broadcast mode workaround for UEs causing out of sync
    FAPI_TRY(mss::workarounds::mcbist::broadcast_out_of_sync(i_target, mss::OFF));

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_FIR> l_mca_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_FIR);

        l_mca_fir_reg.recoverable_error<MCA_FIR_MAINTENANCE_AUE>()
        .recoverable_error<MCA_FIR_MAINTENANCE_IAUE>()
        .recoverable_error<MCA_FIR_SCOM_PARITY_CLASS_STATUS>()
        .recoverable_error<MCA_FIR_SCOM_PARITY_CLASS_RECOVERABLE>()
        .checkstop<MCA_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE>()
        .checkstop<MCA_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR>()
        .recoverable_error<MCA_FIR_WRITE_RMW_CE>()
        .checkstop<MCA_FIR_WRITE_RMW_UE>()
        .checkstop<MCA_FIR_WDF_OVERRUN_ERROR_0>()
        .checkstop<MCA_FIR_WDF_OVERRUN_ERROR_1>()
        .checkstop<MCA_FIR_WDF_SCOM_SEQUENCE_ERROR>()
        .checkstop<MCA_FIR_WDF_STATE_MACHINE_ERROR>()
        .checkstop<MCA_FIR_WDF_MISC_REGISTER_PARITY_ERROR>()
        .checkstop<MCA_FIR_WRT_SCOM_SEQUENCE_ERROR>()
        .checkstop<MCA_FIR_WRT_MISC_REGISTER_PARITY_ERROR>()
        .checkstop<MCA_FIR_ECC_GENERATOR_INTERNAL_PARITY_ERROR>()
        .checkstop<MCA_FIR_READ_BUFFER_OVERFLOW_ERROR>()
        .checkstop<MCA_FIR_WDF_ASYNC_INTERFACE_ERROR>()
        .checkstop<MCA_FIR_READ_ASYNC_INTERFACE_PARITY_ERROR>()
        .checkstop<MCA_FIR_READ_ASYNC_INTERFACE_SEQUENCE_ERROR>();

        FAPI_TRY(l_mca_fir_reg.write(), "unable to write fir::reg %d", MCA_FIR);

    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after draminit_training
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_draminit_training<mss::mc_type::NIMBUS>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("unmask mss fir after draminit_training");

    fapi2::ReturnCode l_rc;

    // TK - unclear right now if these can become generic per MCBIST or whether these are specific
    // to Nimbus. If they can be generic,this whole thing can go back in the H file and the specifics
    // of the registers and bits can be handled generically.

    fir::reg<MCBIST_MCBISTFIRQ> l_mcbist_fir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCBIST_MCBISTFIRQ);

    // Setup mcbist fir. All mcbist attentions are already special attentions
    FAPI_TRY(l_mcbist_fir_reg.recoverable_error<MCBIST_MCBISTFIRQ_COMMAND_ADDRESS_TIMEOUT>().write(),
             "unable to write fir::reg %d", MCBIST_MCBISTFIRQ);

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_MBACALFIRQ> l_mca_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        l_mca_fir_reg.recoverable_error<MCA_MBACALFIRQ_REFRESH_OVERRUN>()
        .recoverable_error<MCA_MBACALFIRQ_DDR_CAL_TIMEOUT_ERR>()
        .recoverable_error<MCA_MBACALFIRQ_DDR_CAL_RESET_TIMEOUT>()
        .recoverable_error<MCA_MBACALFIRQ_WRQ_RRQ_HANG_ERR>()
        .checkstop<MCA_MBACALFIRQ_ASYNC_IF_ERROR>()
        .checkstop<MCA_MBACALFIRQ_CMD_PARITY_ERROR>()
        .recoverable_error<MCA_MBACALFIRQ_RCD_CAL_PARITY_ERROR>();

        FAPI_TRY(l_mca_fir_reg.write(), "unable to write fir::reg %d", MCA_MBACALFIRQ);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_scominit
/// (yeah, it's clearing bits - it's ok)
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_scominit<mss::mc_type::NIMBUS>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("unmask (and clear) mss fir after scominit");

    fapi2::ReturnCode l_rc;

    // TK - unclear right now if these can become generic per MCBIST or whether these are specific
    // to Nimbus. If they can be generic,this whole thing can go back in the H file and the specifics
    // of the registers and bits can be handled generically.

    for (const auto& p : mss::find_targets_with_magic<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_IOM_PHY0_DDRPHY_FIR_REG> l_mca_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_IOM_PHY0_DDRPHY_FIR_REG);

        fir::reg<MCA_MBACALFIRQ> l_cal_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_2>());
        FAPI_TRY(l_mca_fir_reg.clear<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>());

        FAPI_TRY(l_cal_fir_reg.clear<MCA_MBACALFIRQ_RCD_PARITY_ERROR>());
        FAPI_TRY(l_cal_fir_reg.clear<MCA_MBACALFIRQ_DDR_MBA_EVENT_N>());

        // No need to write after clearing - the clear does the read/modify/write.
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions performed after mss_ddr_phy_reset
/// @param[in] i_target the fapi2::Target of the MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_phy_reset<mss::mc_type::NIMBUS>( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
{
    FAPI_INF("unmask mss fir after phy reset");

    fapi2::ReturnCode l_rc;

    // TK - unclear right now if these can become generic per MCBIST or whether these are specific
    // to Nimbus. If they can be generic,this whole thing can go back in the H file and the specifics
    // of the registers and bits can be handled generically.

    fir::reg<MCBIST_MCBISTFIRQ> l_mcbist_fir_reg(i_target, l_rc);
    FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCBIST_MCBISTFIRQ);

    l_mcbist_fir_reg.checkstop<MCBIST_MCBISTFIRQ_INTERNAL_FSM_ERROR>()
    .recoverable_error<MCBIST_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
    .checkstop<MCBIST_MCBISTFIRQ_SCOM_FATAL_REG_PE>();

    FAPI_TRY(l_mcbist_fir_reg.write(), "unable to write fir::reg %d", MCBIST_MCBISTFIRQ);

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_IOM_PHY0_DDRPHY_FIR_REG> l_mca_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_IOM_PHY0_DDRPHY_FIR_REG);

        fir::reg<MCA_MBACALFIRQ> l_cal_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        l_cal_fir_reg.recoverable_error<MCA_MBACALFIRQ_MBA_RECOVERABLE_ERROR>()
        .checkstop<MCA_MBACALFIRQ_MBA_NONRECOVERABLE_ERROR>()
        .recoverable_error<MCA_MBACALFIRQ_RCD_PARITY_ERROR>()
        .checkstop<MCA_MBACALFIRQ_SM_1HOT_ERR>();

        l_mca_fir_reg.recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_0>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_1>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_3>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_4>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_5>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_6>()
        .recoverable_error<MCA_IOM_PHY0_DDRPHY_FIR_REG_ERROR_7>();

        FAPI_TRY(l_mca_fir_reg.write(), "unable to write fir::reg %d", MCA_IOM_PHY0_DDRPHY_FIR_REG);
        FAPI_TRY(l_cal_fir_reg.write(), "unable to write fir::reg %d", MCA_MBACALFIRQ);
    }

fapi_try_exit:
    return fapi2::current_err;

}


///
/// @brief Unmask and setup actions for memdiags related FIR
/// @param[in] i_target the fapi2::Target MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_memdiags<mss::mc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>& i_target )
{
    fapi2::ReturnCode l_rc1, l_rc2;
    fapi2::buffer<uint64_t> dsm0_buffer;
    fapi2::buffer<uint64_t> l_mnfg_buffer;
    uint64_t rd_tag_delay = 0;
    uint64_t wr_done_delay = 0;
    fapi2::buffer<uint64_t> l_aue_buffer;
    fapi2::ATTR_CHIP_EC_FEATURE_HW414700_Type l_checkstop_flag;
    constexpr uint64_t MNFG_THRESHOLDS_ATTR = 63;

    // Broadcast mode workaround for UEs causing out of sync
    FAPI_TRY(mss::workarounds::mcbist::broadcast_out_of_sync(i_target, mss::ON));

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_FIR> l_ecc64_fir_reg(p, l_rc1);
        fir::reg<MCA_MBACALFIRQ> l_cal_fir_reg(p, l_rc2);
        uint64_t rcd_protect_time = 0;
        const auto l_chip_target = mss::find_target<fapi2::TARGET_TYPE_PROC_CHIP>(i_target);

        FAPI_TRY(l_rc1, "unable to create fir::reg for %d", MCA_FIR);
        FAPI_TRY(l_rc2, "unable to create fir::reg for %d", MCA_MBACALFIRQ);

        // Read out the wr_done and rd_tag delays and find min
        // and set the RCD Protect Time to this value
        FAPI_TRY (mss::read_dsm0q_register(p, dsm0_buffer) );
        mss::get_wrdone_delay(dsm0_buffer, wr_done_delay);
        mss::get_rdtag_delay(dsm0_buffer, rd_tag_delay);
        rcd_protect_time = std::min(wr_done_delay, rd_tag_delay);
        FAPI_TRY (mss::change_rcd_protect_time(p, rcd_protect_time) );

        l_ecc64_fir_reg.checkstop<MCA_FIR_MAINLINE_AUE>()
        .recoverable_error<MCA_FIR_MAINLINE_UE>()
        .checkstop<MCA_FIR_MAINLINE_IAUE>()
        .recoverable_error<MCA_FIR_MAINLINE_IUE>();

        l_cal_fir_reg.recoverable_error<MCA_MBACALFIRQ_PORT_FAIL>();

        // If ATTR_CHIP_EC_FEATURE_HW414700 is enabled set checkstops
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW414700, l_chip_target, l_checkstop_flag) );

        // If the system is running DD2 chips override some recoverable firs with checkstop
        // Due to a known hardware defect with DD2 certain errors are not handled properly
        // As a result, these firs are marked as checkstop for DD2 to avoid any mishandling
        if (l_checkstop_flag)
        {
            l_ecc64_fir_reg.checkstop<MCA_FIR_MAINLINE_UE>()
            .checkstop<MCA_FIR_MAINLINE_RCD>();
            l_cal_fir_reg.checkstop<MCA_MBACALFIRQ_PORT_FAIL>();
        }

        // If MNFG FLAG Threshhold is enabled skip IUE unflagging
        FAPI_TRY ( mss::mnfg_flags(l_mnfg_buffer) );

        if ( !(l_mnfg_buffer.getBit<MNFG_THRESHOLDS_ATTR>()) )
        {
            l_ecc64_fir_reg.recoverable_error<MCA_FIR_MAINTENANCE_IUE>();
        }

        FAPI_TRY(l_ecc64_fir_reg.write(), "unable to write fir::reg %d", MCA_FIR);
        FAPI_TRY(l_cal_fir_reg.write(), "unable to write fir::reg %d", MCA_MBACALFIRQ);

        // Change Maint AUE and IAUE to checkstop without unmasking
        // Normal setup modifies masked bits in addition to setting checkstop
        // This causes issues if error has occured, manually scoming to avoid this
        FAPI_TRY( mss::getScom(p, MCA_ACTION1, l_aue_buffer) );
        l_aue_buffer.clearBit<MCA_FIR_MAINTENANCE_AUE>();
        l_aue_buffer.clearBit<MCA_FIR_MAINTENANCE_IAUE>();
        FAPI_TRY( mss::putScom(p, MCA_ACTION1, l_aue_buffer) );

        // Note: We also want to include the following setup RCD recovery and port fail
        FAPI_TRY( mss::change_port_fail_disable(p, mss::LOW) );
        FAPI_TRY( mss::change_rcd_recovery_disable(p, mss::LOW) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask and setup actions for scrub related FIR
/// @param[in] i_target the fapi2::Target MCBIST
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
fapi2::ReturnCode after_background_scrub<mss::mc_type::NIMBUS>( const fapi2::Target<fapi2::TARGET_TYPE_MCBIST>&
        i_target )
{
    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fapi2::ReturnCode l_rc;
        fir::reg<MCA_FIR> l_ecc64_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg 0x%016lx for %s", MCA_FIR, mss::c_str(p));

        l_ecc64_fir_reg.recoverable_error<MCA_FIR_MAINLINE_MPE_RANK_0_TO_7,
                                          MCA_FIR_MAINLINE_MPE_RANK_0_TO_7_LEN>()
                                          .recoverable_error<MCA_FIR_MAINLINE_NCE>()
                                          .recoverable_error<MCA_FIR_MAINLINE_TCE>()
                                          .recoverable_error<MCA_FIR_MAINLINE_IMPE>()
                                          .recoverable_error<MCA_FIR_MAINTENANCE_IMPE>();

        FAPI_TRY(l_ecc64_fir_reg.write(), "unable to write fir::reg 0x%016lx for %s", MCA_FIR, mss::c_str(p));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

}
}
