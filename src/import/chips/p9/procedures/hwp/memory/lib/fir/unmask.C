/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/fir/unmask.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>
#include <p9_mc_scom_addresses.H>
#include <p9_mc_scom_addresses_fld.H>

#include <generic/memory/lib/utils/scom.H>
#include <lib/fir/fir.H>
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
fapi2::ReturnCode after_draminit_mc( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
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
    l_mcbist_fir_reg.attention<MCBIST_MCBISTFIRQ_MCBIST_PROGRAM_COMPLETE>()
    .checkstop<MCBIST_MCBISTFIRQ_MCBIST_BRODCAST_OUT_OF_SYNC>();

    FAPI_TRY(l_mcbist_fir_reg.write(), "unable to write fir::reg %d", MCBIST_MCBISTFIRQ);

    FAPI_TRY(mss::workarounds::mcbist::wat_debug_attention(i_target));

    for (const auto& p : mss::find_targets<TARGET_TYPE_MCA>(i_target))
    {
        fir::reg<MCA_FIR> l_mca_fir_reg(p, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for %d", MCA_FIR);

        l_mca_fir_reg.checkstop<MCA_FIR_MAINTENANCE_AUE>()
        .checkstop<MCA_FIR_MAINTENANCE_IAUE>()
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
fapi2::ReturnCode after_draminit_training( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
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
fapi2::ReturnCode after_scominit( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
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
fapi2::ReturnCode after_phy_reset( const fapi2::Target<TARGET_TYPE_MCBIST>& i_target )
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

}
}
