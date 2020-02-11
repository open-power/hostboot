/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9a/procedures/hwp/memory/lib/fir/p9a_fir.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#ifndef _P9A_FIR_H_
#define _P9A_FIR_H_

#include <fapi2.H>
#include <p9a_mc_scom_addresses.H>
#include <p9a_mc_scom_addresses_fld.H>
#include <p9a_mc_scom_addresses_fixes.H>
#include <p9a_mc_scom_addresses_fld_fixes.H>
#include <lib/fir/p9a_fir_traits.H>
#include <lib/mc/host_mc_traits.H>
#include <generic/memory/lib/utils/pos.H>
#include <generic/memory/lib/utils/fir/gen_mss_fir.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/find.H>

namespace mss
{

namespace unmask
{

///
/// @brief Clear error bits P9A_MC_REGm_DLn_ERROR_MASK registers m[0:2], n[0:2] since they are now "active"
/// @tparam R the REG_DL register we want to write to
/// @param[in] i_target MC target to find targets to initialize
/// @param[in] i_state state to set FIR masks to
/// @return fapi2::FAPI2_RC_SUCCESS iff ok
///
template<uint64_t R>
inline fapi2::ReturnCode setup_reg_dl_helper(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target,
        mss::states i_state)
{
    fapi2::buffer<uint64_t> l_reg_data;

    FAPI_TRY(mss::getScom(i_target, R, l_reg_data));
    l_reg_data.writeBit<P9A_MC_REG2_DL2_ERROR_MASK_34>(i_state);
    l_reg_data.writeBit<P9A_MC_REG2_DL2_ERROR_MASK_33>(i_state);
    l_reg_data.writeBit<P9A_MC_REG2_DL2_ERROR_MASK_32>(i_state);
    FAPI_TRY(mss::putScom(i_target, R, l_reg_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Unmask FIR registers after p9_chiplet_scominit procedure on Axone
/// @param[in] i_target MC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS iff success
///
inline fapi2::ReturnCode after_p9a_chiplet_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MC>& i_target)
{
    using MCT = mss::mcTraits<mss::proc_type::AXONE>;

    fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;
    fapi2::ReturnCode l_rc3 = fapi2::FAPI2_RC_SUCCESS;

    // Create registers and check success
    mss::fir::reg<P9A_MC_LOCAL_FIR> l_mc_local_fir_reg(i_target, l_rc1);
    mss::fir::reg<P9A_MC_MCBISTFIRQ> l_mc_mcbistfirq_reg(i_target, l_rc2);
    mss::fir::reg<P9A_MC_REG0_OMI_FIR> l_mc_omi_fir_reg(i_target, l_rc3);

    FAPI_TRY(l_rc1, "unable to create fir::reg for P9A_MC_LOCAL_FIR 0x%08X", P9A_MC_LOCAL_FIR);
    FAPI_TRY(l_rc2, "unable to create fir::reg for P9A_MC_MCBISTFIRQ 0x%08X", P9A_MC_MCBISTFIRQ);
    FAPI_TRY(l_rc3, "unable to create fir::reg for P9A_MC_REG0_OMI_FIR 0x%08X", P9A_MC_REG0_OMI_FIR);

    // Write LOCAL_FIR register per Axone unmask spec
    FAPI_TRY(l_mc_local_fir_reg.recoverable_error<P9A_MC_LOCAL_FIR_IN0>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN1>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN2>()
             .recoverable_error<P9A_MC_LOCAL_FIR_IN3>()
             .write());

    // Write MCBISTFIRQ register per Axone unmask spec
    FAPI_TRY(l_mc_mcbistfirq_reg.recoverable_error<P9A_MC_MCBISTFIRQ_SCOM_RECOVERABLE_REG_PE>()
             .write());

    for (const auto& l_omic : mss::find_targets<fapi2::TARGET_TYPE_OMIC>(i_target))
    {
        const auto l_pos = mss::relative_pos<fapi2::TARGET_TYPE_MC>(l_omic);

        // Set up MC_OMI_FIR register per Axone unmask spec
        // Note that there are child-target-specific FIR bits in this reg, so we need to check
        // what's configured inside the OMIC loop
        switch(l_pos)
        {
            case 0:
                l_mc_omi_fir_reg.local_checkstop<P9A_MC_MC_OMI_FIR_REG_DL0_FATAL_ERROR>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_DATA_UE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_X4_MODE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_TIMEOUT>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_ERROR_RETRAIN>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL0_EDPL_RETRAIN>();
                break;

            case 1:
                l_mc_omi_fir_reg.local_checkstop<P9A_MC_MC_OMI_FIR_REG_DL1_FATAL_ERROR>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_DATA_UE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_X4_MODE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_TIMEOUT>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_ERROR_RETRAIN>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL1_EDPL_RETRAIN>();
                break;

            case 2:
                l_mc_omi_fir_reg.local_checkstop<P9A_MC_MC_OMI_FIR_REG_DL2_FATAL_ERROR>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_DATA_UE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_X4_MODE>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_TIMEOUT>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_ERROR_RETRAIN>()
                .recoverable_error<P9A_MC_MC_OMI_FIR_REG_DL2_EDPL_RETRAIN>();
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::MSS_INVALID_OMIC_POSITION().
                            set_POSITION(l_pos).
                            set_OMIC_TARGET(l_omic),
                            "Invalid OMIC position (%d) for %s", l_pos, mss::c_str(l_omic));
                break;
        }

        fapi2::ReturnCode l_rc1 = fapi2::FAPI2_RC_SUCCESS;
        fapi2::ReturnCode l_rc2 = fapi2::FAPI2_RC_SUCCESS;

        mss::fir::reg<P9A_OMIC_FIR_REG> l_omic_fir_reg(l_omic, l_rc1);
        mss::fir::reg<P9A_OMIC_PPE_FIR_REG> l_omic_ppe_fir_reg(l_omic, l_rc2);

        FAPI_TRY(l_rc1, "unable to create fir::reg for P9A_OMIC_FIR_REG 0x%08X", P9A_OMIC_FIR_REG);
        FAPI_TRY(l_rc2, "unable to create fir::reg for P9A_OMIC_PPE_FIR_REG 0x%08X", P9A_OMIC_PPE_FIR_REG);

        // Write OMIC FIR register per Axone unmask spec
        FAPI_TRY(l_omic_fir_reg.recoverable_error<P9A_OMIC_FIR_REG_RX_INVALID_STATE_OR_PARITY_ERROR>()
                 .recoverable_error<P9A_OMIC_FIR_REG_TX_INVALID_STATE_OR_PARITY_ERROR>()
                 .recoverable_error<P9A_OMIC_FIR_REG_GCR_HANG_ERROR>()
                 .write());

        // Write OMIC PPE FIR register per Axone unmask spec
        // Note that the spec says this entire reg should be (re)masked just in case
        // so this is intentional
        FAPI_TRY( (l_omic_ppe_fir_reg.masked<P9A_OMIC_PPE_FIR_REG_ERROR, P9A_OMIC_PPE_FIR_REG_ERROR_LEN>()
                   .masked<P9A_OMIC_PPE_FIR_REG_HALTED>()
                   .masked<P9A_OMIC_PPE_FIR_REG_WATCHDOG_TIMEOUT>()
                   .masked<P9A_OMIC_PPE_FIR_REG_MMIO_DATA_IN>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_MISSED_SCRUB_TICK>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_ARY_UE>()
                   .masked<P9A_OMIC_PPE_FIR_REG_ARB_ARY_CE>()
                   .masked<P9A_OMIC_PPE_FIR_REG_RESERVED>()
                   .masked<P9A_OMIC_PPE_FIR_REG_SCOMFIR_ERROR>()
                   .masked<P9A_OMIC_PPE_FIR_REG_SCOMFIR_ERROR_CLONE>()
                   .write()) );
    }

    // Write MC_OMI_FIR register now that it's been set up in the loop above
    FAPI_TRY(l_mc_omi_fir_reg.write());

    for (const auto& l_mcc : mss::find_targets<fapi2::TARGET_TYPE_MCC>(i_target))
    {
        fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
        mss::fir::reg<P9A_MCC_DSTLFIR> l_mcc_dstlfir_reg(l_mcc, l_rc);
        FAPI_TRY(l_rc, "unable to create fir::reg for P9A_MCC_DSTLFIR 0x%08X", P9A_MCC_DSTLFIR);

        // Write DSTLFIR register per Axone unmask spec
        FAPI_TRY(l_mcc_dstlfir_reg.checkstop<P9A_MCC_DSTLFIR_ASYNC_CROSSING_PARITY_ERROR>()
                 .checkstop<P9A_MCC_DSTLFIR_ASYNC_CROSSING_SEQUENCE_ERROR>()
                 .recoverable_error<P9A_MCC_DSTLFIR_CONFIG_REG_RECOVERABLE_PARITY_ERROR>()
                 .checkstop<P9A_MCC_DSTLFIR_CONFIG_REG_FATAL_PARITY_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_A_COUNTER_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_B_COUNTER_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_A_BUFFER_OVERUSE_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_SUBCHANNEL_B_BUFFER_OVERUSE_ERROR>()
                 .local_checkstop<P9A_MCC_DSTLFIR_CHANNEL_TIMEOUT_SUBCH_A>()
                 .local_checkstop<P9A_MCC_DSTLFIR_CHANNEL_TIMEOUT_SUBCH_B>()
                 .write());
    }

    // Set ERROR_MASK on REGm_DLn 0:2 registers because they are not considered valid at this point
    FAPI_TRY(setup_reg_dl_helper<MCT::REG0_DL0_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG0_DL1_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG0_DL2_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG1_DL0_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG1_DL1_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG1_DL2_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG2_DL0_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG2_DL1_ERROR_MASK>(i_target, mss::HIGH));
    FAPI_TRY(setup_reg_dl_helper<MCT::REG2_DL2_ERROR_MASK>(i_target, mss::HIGH));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:

    return fapi2::current_err;
}

} // end unmask ns

} // end mss ns
#endif
