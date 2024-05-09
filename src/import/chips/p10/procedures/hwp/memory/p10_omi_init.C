/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_omi_init.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2024                        */
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
/// @file p10_omi_init.C
/// @brief Finalize the OMI
///
// *HWP HW Maintainer: Benjamin Gass <bgass@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: HB

#include <p10_omi_init.H>
#include <p10_omi_init_scom.H>
#include <p10_io_lib.H>
#include <p10_scom_mcc_4.H>
#include <p10_scom_omi_7.H>
#include <p10_scom_mcc_d.H>
#include <lib/fir/p10_fir.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/find.H>


/// @brief                      Builds address to access SCOMs
/// @param i_base_addr          The chip's base address
/// @param i_group              The group being accessed
/// @param i_lane               The lane being accessed
/// @param i_reg                The reg being accessed & tx direction. Specify register in hex then append 0 (Rx) or 1 (Tx)
///                                         111111
///                               0123456789012345
///                               xxxRRRRRRRRRTxxx
///
///                             R : register address bits
///                             T : TX bit
///                             x : don't care
/// @return                     Returns the address that's been built from the input parameters
inline uint64_t buildAddr(const uint32_t i_base_addr,
                          const uint8_t i_group,
                          const uint8_t i_lane,
                          const uint16_t i_reg)
{
    uint64_t r_addr = static_cast<uint64_t>(i_base_addr);
    r_addr |= static_cast<uint64_t>(0x3F);
    r_addr |= static_cast<uint64_t>(i_reg & 0x1FF8) << 39;  // 63-21-3=39
    // 21 is the starting location for Tx, but need to shift back another 3 bits so the
    //  direction bit of the nibble is in the correct position
    r_addr |= static_cast<uint64_t>(i_lane & 0x1F) << 32;   // 63-31=32
    r_addr |= static_cast<uint64_t>(i_group & 0x1F) << 37;   // 63-26=37
    r_addr |= static_cast<uint64_t>(0x1) << 63;

    return r_addr;
}

///
/// @brief Run initfile to enable templates and set pacing.
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_scominit(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ReturnCode l_rc;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_EXEC_HWP(l_rc, p10_omi_init_scom, i_target, FAPI_SYSTEM);

    if (l_rc)
    {
        FAPI_ERR("Error from p10.omi_init.scom.initfile");
        fapi2::current_err = l_rc;
    }

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Check and enable supported templates
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_enable_templates(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_1_Type l_enable_tmpl_1;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_4_Type l_enable_tmpl_4;
    fapi2::ATTR_PROC_ENABLE_DL_TMPL_7_Type l_enable_tmpl_7;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_1,
                           i_target,
                           l_enable_tmpl_1),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_1)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_4,
                           i_target,
                           l_enable_tmpl_4),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_4)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_ENABLE_DL_TMPL_7,
                           i_target,
                           l_enable_tmpl_7),
             "Error from FAPI_ATTR_GET (ATTR_PROC_ENABLE_DL_TMPL_7)");

    FAPI_ASSERT(l_enable_tmpl_1 != 0,
                fapi2::P10_DOWNSTREAM_TMPL1_REQUIRED_ERR()
                .set_TARGET(i_target),
                "Downstream template 1 is required.");

    FAPI_ASSERT(l_enable_tmpl_4 != 0 || l_enable_tmpl_7 != 0,
                fapi2::P10_DOWNSTREAM_TMPL4OR7_REQUIRED_ERR()
                .set_TARGET(i_target),
                "Downstream template 4 and/or 7 is required.");

    //Turn off temp0_only
    FAPI_TRY(scomt::mcc::GET_DSTL_DSTLCFG(i_target, l_data));
    scomt::mcc::CLEAR_DSTL_DSTLCFG_TMPL0_ONLY(l_data);
    FAPI_TRY(scomt::mcc::PUT_DSTL_DSTLCFG(i_target, l_data));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

///
/// @brief Enable ibm buffer chip low latency mode
///
/// @param[in] i_target                 p10 channel to work on
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_enable_lol(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    fapi2::buffer<uint64_t> l_data;
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_OMI>> l_omi_targets;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_pos;

    l_omi_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_TRY(scomt::mcc::GET_USTL_USTLCFG(i_target, l_data));

    for (const auto l_omi_target : l_omi_targets)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_omi_target,
                                l_omi_pos));

        // Set for proper channel
        if ((l_omi_pos % 2) == 0)
        {
            scomt::mcc::SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANA_ENABLE(l_data);
        }
        else
        {
            scomt::mcc::SET_USTL_USTLCFG_IBM_BUFFER_CHIP_CHANB_ENABLE(l_data);
        }
    }

    FAPI_TRY(scomt::mcc::PUT_USTL_USTLCFG(i_target, l_data));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}


///
/// @brief Enable P11 performance updates
///
/// @param[in] i_target                 p10 channel to work on
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init_performance(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    constexpr uint64_t c_base_addr = 0x10012c3full;

    constexpr uint16_t c_reg_rx_ctl_mode12_pg = 0x10C0;
    constexpr uint16_t c_reg_tx_ctl_mode3_pl = 0x0008;

    constexpr uint8_t c_bit_iref_clk_dac = 0; // rx_ctl_mode12_pg
    constexpr uint8_t c_len_iref_clk = 3;
    constexpr uint8_t c_bit_iref_vset_dac = 6; // rx_ctl_mode12_pg
    constexpr uint8_t c_len_iref_vset = 2;
    constexpr uint8_t c_bit_tx_boost_en = 4; // tx_ctl_mode3_pl
    constexpr uint8_t c_len_tx = 1;
    constexpr uint8_t c_max_groups = 2;
    constexpr uint8_t c_max_lanes = 8;
    constexpr uint8_t c_indirect_scom_offset = 48;

    auto l_omi_targets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_addr = 0;

    uint32_t l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;

    uint8_t l_group = 0;
    uint8_t l_lane = 0;

    for (l_group = 0; l_group < c_max_groups; l_group++)
    {
        l_addr = buildAddr(c_base_addr, l_group, 0, c_reg_rx_ctl_mode12_pg);
        FAPI_DBG("RX_CTL_MODE12_PG Address 0x%08X%08X", (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);
        FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                 "Error putscom to address 0x%08X.", l_addr);

        FAPI_DBG("Setting IREF CLOCK DAC to 4");
        l_buffer.insertFromRight(4, c_bit_iref_clk_dac + c_indirect_scom_offset, c_len_iref_clk);

        FAPI_DBG("Setting IREF VSET DAC to 2");
        l_buffer.insertFromRight(2, c_bit_iref_vset_dac + c_indirect_scom_offset, c_len_iref_vset);

        FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                 "Error putscom to address 0x%08X.", l_addr);

        l_buffer.flush<0>();

        for (l_lane = 0; l_lane < c_max_lanes; l_lane++)
        {
            l_addr = buildAddr(c_base_addr, l_group, l_lane, c_reg_tx_ctl_mode3_pl);
            FAPI_DBG("TX_CTL_MODE3_PL Address 0x%08X%08X", (l_addr >> 32) & 0xFFFFFFFF, l_addr & 0xFFFFFFFF);
            FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                     "Error putscom to address 0x%08X.", l_addr);

            FAPI_DBG("Setting Tx Boost En to disabled");
            l_buffer.insertFromRight(0, c_bit_tx_boost_en + c_indirect_scom_offset, c_len_tx);

            FAPI_TRY(putScom(i_target, l_addr, l_buffer),
                     "Error putscom to address 0x%08X.", l_addr);

            l_buffer.flush<0>();
        }

    }

    for (auto l_omi_target : l_omi_targets)
    {
        FAPI_TRY(p10_io_omi_put_pl_regs(l_omi_target,
                                        scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL,
                                        scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP,
                                        scomt::omi::RXPACKS_0_DEFAULT_RD_RX_BIT_REGS_MODE4_PL_PHASE_STEP_LEN,
                                        l_num_lanes,
                                        0x08));
    }

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

// Putting unmask function in mss::unmask for consistency with p9/EXPL/etc.
namespace mss
{
namespace unmask
{

///
/// @brief Initialize Axone DSTLFIR mask bits after p9a omi init
/// @param[in] i_target MCC target to find targets to initialize
/// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code
///
fapi2::ReturnCode after_p10_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    // Unmask MC_OMI_FIR per FIR XML spec
    const auto& l_mc = mss::find_target<fapi2::TARGET_TYPE_MC>(i_target);
    FAPI_TRY(after_p10_omi_init_omi_fir_helper(l_mc));

    // Unmask MCC DSTLFIR per FIR XML spec
    FAPI_TRY(after_p10_omi_init_dstlfir_helper(i_target));

    // Unmask MCC USTLFIR per FIR XML spec
    FAPI_TRY(after_p10_omi_init_ustlfir_helper(i_target));

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}

} // end unmask ns
} // end mss ns

///
/// @brief Finalize the OMI
/// @param[in] i_target MCC target
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_omi_init(const fapi2::Target<fapi2::TARGET_TYPE_MCC>& i_target)
{
    auto l_proc_target = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    uint32_t l_omi_freq = 0;
    uint8_t l_enable_fir_unmasking = 0;

    FAPI_TRY(p10_omi_init_scominit(i_target));
    FAPI_TRY(p10_omi_init_enable_templates(i_target));
    FAPI_TRY(p10_omi_init_enable_lol(i_target));


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ, l_proc_target, l_omi_freq));

    // Performance updates are only for 38.4
    if (l_omi_freq == 38400)
    {
        FAPI_TRY(p10_omi_init_performance(i_target));
    }

    // Perform fir unmasking if attribute is set to enabled, default disabled
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ENABLE_FIR_UNMASKING, fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_enable_fir_unmasking));

    if (l_enable_fir_unmasking == fapi2::ENUM_ATTR_ENABLE_FIR_UNMASKING_ENABLED)
    {
        FAPI_TRY(mss::unmask::after_p10_omi_init(i_target));
    }

fapi_try_exit:

    FAPI_DBG("Exiting with return code : 0x%08X...", (uint64_t) fapi2::current_err);
    return fapi2::current_err;
}
