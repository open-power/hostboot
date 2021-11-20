/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_tdm_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
/// @file p10_fbc_tdm_utils.C
/// @brief Utility functions for TDM entry/exit (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: FSP

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_tdm_utils.H>
#include <p10_smp_link_firs.H>
#include <p10_io_iohs_poll_recal.H>
#include <p10_io_lib.H>
#include <p10_scom_iohs.H>
#include <p10_scom_pauc.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


/////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_get_iolink
/////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_get_iolink(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const bool i_even_not_odd,
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& o_iolink_target)
{
    FAPI_DBG("Start");

    bool l_found = false;

    for (auto l_iolink : i_iohs_target.getChildren<fapi2::TARGET_TYPE_IOLINK>())
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iolink, l_unit_pos));

        if (i_even_not_odd && ((l_unit_pos % 2) == 0))
        {
            l_found = true;
            o_iolink_target = l_iolink;
            break;
        }
        else if (!i_even_not_odd && ((l_unit_pos % 2) == 1))
        {
            l_found = true;
            o_iolink_target = l_iolink;
            break;
        }
    }

    FAPI_ASSERT(l_found,
                fapi2::P10_FBC_TDM_UTILS_IOLINK_SEARCH_ERR()
                .set_IOHS_TARGET(i_iohs_target)
                .set_EVEN_NOT_ODD(i_even_not_odd),
                "No IOLINK target found to match requested link half!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_fir_mask
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_fir_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::pauc;
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_data = 0;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
    sublink_t l_sublink_opt;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_unit),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    l_sublink_opt = (i_even_not_odd) ?
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::EVEN_PAUE) : (sublink_t::EVEN_PAUO)) :
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::ODD_PAUE) : (sublink_t::ODD_PAUO));

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink_opt, action_t::INACTIVE, false),
             "Error from p10_smp_link_firs");

    // additionally mask RECAL_NOT_RUN (not covered by p10_smp_link_firs, which only touches
    // link specific bits)
    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_MASK_REG_RW(l_pauc_target));
    SET_PHY_SCOM_MAC_FIR_MASK_REG_PPE_CODE_RECAL_NOT_RUN_MASK(l_data);
    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_MASK_REG_WO_OR(l_pauc_target));
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_WO_OR(l_pauc_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_fir_reset_all
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_fir_reset_all(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
    sublink_t l_sublink_opt;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_unit),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    l_sublink_opt = (i_even_not_odd) ?
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::EVEN_PAUE) : (sublink_t::EVEN_PAUO)) :
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::ODD_PAUE) : (sublink_t::ODD_PAUO));

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink_opt, action_t::CLEAR_ALL, false),
             "Error from p10_smp_link_firs");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_fir_reset_err
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_fir_reset_err(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
    sublink_t l_sublink_opt;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_unit),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    l_sublink_opt = (i_even_not_odd) ?
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::EVEN_PAUE) : (sublink_t::EVEN_PAUO)) :
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::ODD_PAUE) : (sublink_t::ODD_PAUO));

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink_opt, action_t::CLEAR_ERR, false),
             "Error from p10_smp_link_firs");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_fir_unmask
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_fir_unmask(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
    sublink_t l_sublink_opt;
    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_lane_vec_valid = fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_FALSE;
    fapi2::ATTR_CHIP_EC_FEATURE_HW561216_Type l_hw561216 = 0;
    bool l_mask_dl_lane_errors = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_unit),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    l_sublink_opt = (i_even_not_odd) ?
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::EVEN_PAUE) : (sublink_t::EVEN_PAUO)) :
                    (((l_iohs_unit % 2) == 0) ? (sublink_t::ODD_PAUE) : (sublink_t::ODD_PAUO));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, i_target, l_bad_lane_vec_valid));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW561216, i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>(),
                           l_hw561216));
    l_mask_dl_lane_errors = (l_hw561216 && (l_bad_lane_vec_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_FALSE));

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink_opt, action_t::RUNTIME, l_mask_dl_lane_errors),
             "Error from p10_smp_link_firs");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_tdm_query
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_tdm_query(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd,
    bool& o_link_down)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_link_quality;
    uint64_t l_tx_bandwidth = 0;
    uint64_t l_rx_bandwidth = 0;
    o_link_down = false;

    if(i_even_not_odd)
    {
        FAPI_TRY(GET_DLP_LINK0_QUALITY(i_target, l_dl_link_quality));
        GET_DLP_LINK0_QUALITY_TX_BW(l_dl_link_quality, l_tx_bandwidth);
        GET_DLP_LINK0_QUALITY_RX_BW(l_dl_link_quality, l_rx_bandwidth);
    }
    else
    {
        FAPI_TRY(GET_DLP_LINK1_QUALITY(i_target, l_dl_link_quality));
        GET_DLP_LINK1_QUALITY_TX_BW(l_dl_link_quality, l_tx_bandwidth);
        GET_DLP_LINK1_QUALITY_RX_BW(l_dl_link_quality, l_rx_bandwidth);
    }

    o_link_down = ((l_tx_bandwidth == 0) && (l_rx_bandwidth == 0));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_validate_targets
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_validate_targets(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOHS>>& o_targets)
{
    using namespace scomt::iohs;
    using namespace scomt::pauc;

    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_loc_iolink_target;
    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_loc_config_mode;
    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_rem_config_mode;
    fapi2::ReturnCode l_rc;

    FAPI_DBG("Start");

    // verify link configuration
    auto l_loc_iolink_targets = i_target.getChildren<fapi2::TARGET_TYPE_IOLINK>();

    FAPI_ASSERT(l_loc_iolink_targets.size() != 0,
                fapi2::P10_FBC_TDM_UTILS_LOC_ENDP_TARGET_ERR()
                .set_LOC_ENDP_TARGET(i_target),
                "No IOLINK targets found for given local link endpoint!");

    l_loc_iolink_target = l_loc_iolink_targets.front();
    l_rc = l_loc_iolink_target.getOtherEnd(l_rem_iolink_target);

    FAPI_ASSERT(!l_rc,
                fapi2::P10_FBC_TDM_UTILS_REM_IOLINK_TARGET_ERR()
                .set_LOC_IOLINK_TARGET(l_loc_iolink_target),
                "No remote iolink target found for given local link iolink target!");

    l_rem_target = l_rem_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, i_target, l_loc_config_mode),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_rem_target, l_rem_config_mode),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");

    FAPI_ASSERT((l_loc_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
                || (l_loc_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA),
                fapi2::P10_FBC_TDM_UTILS_CONFIG_MODE_ERR()
                .set_TARGET(i_target)
                .set_IOHS_CONFIG_MODE(l_loc_config_mode),
                "Requested link (local endpoint) is not carrying SMP traffic!");

    FAPI_ASSERT((l_rem_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX)
                || (l_rem_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA),
                fapi2::P10_FBC_TDM_UTILS_CONFIG_MODE_ERR()
                .set_TARGET(l_rem_target)
                .set_IOHS_CONFIG_MODE(l_rem_config_mode),
                "Requested link (remote endpoint) is not carrying SMP traffic!");

    // prepare vector of targets
    o_targets.clear();
    o_targets.push_back(i_target);
    o_targets.push_back(l_rem_target);

    // tdm inject/recovery should never be attempted if the link
    // was brought up in half width mode at ipl time
    for (auto l_target : o_targets)
    {
        using namespace scomt::iohs;

        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;
        fapi2::buffer<uint64_t> l_dl_config;
        fapi2::buffer<uint64_t> l_tl_config;
        uint64_t l_dl_link_pair = 0;
        uint64_t l_tl_link_pair = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_target, l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_TRY(GET_DLP_CONFIG(l_target, l_dl_config));
        GET_DLP_CONFIG_LINK_PAIR(l_dl_config, l_dl_link_pair);

        FAPI_TRY(GET_PB_MISC_CFG(l_target.getParent<fapi2::TARGET_TYPE_PAUC>(), l_tl_config));

        ((l_unit_pos % 2) == 0) ?
        GET_PB_MISC_CFG_SCOM_PTLX_IS_LOGICAL_PAIR(l_tl_config, l_tl_link_pair) :
        GET_PB_MISC_CFG_SCOM_PTLY_IS_LOGICAL_PAIR(l_tl_config, l_tl_link_pair);

        FAPI_ASSERT(l_dl_link_pair && l_tl_link_pair,
                    fapi2::P10_FBC_TDM_UTILS_CCM_NOT_SUPPORTED_ERR()
                    .set_IOHS_TARGET(l_target)
                    .set_PAUC_TARGET(l_target.getParent<fapi2::TARGET_TYPE_PAUC>())
                    .set_DL_CONFIG(l_dl_config())
                    .set_TL_CONFIG(l_tl_config()),
                    "Requested link does not support TDM inject/recovery, "
                    "link was statically configured for half-width at IPL time! "
                    "l_dl_link_pair = %s, l_tl_link_pair = %s",
                    l_dl_link_pair ? "true" : "false",
                    l_tl_link_pair ? "true" : "false");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_dl_send_command
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_dl_send_command(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd,
    const p10_fbc_tdm_utils_dl_cmd_t i_command)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_control_data;
    fapi2::buffer<uint64_t> l_dl_control_mask;

    FAPI_TRY(GET_DLP_CONTROL(i_target, l_dl_control_data));

    if (i_command == p10_fbc_tdm_utils_dl_cmd_t::PART_RESET)
    {
        (i_even_not_odd) ?
        CLEAR_DLP_CONTROL_0_STARTUP(l_dl_control_data) :
        CLEAR_DLP_CONTROL_1_STARTUP(l_dl_control_data);
        (i_even_not_odd) ?
        CLEAR_DLP_CONTROL_0_PHY_TRAINING(l_dl_control_data) :
        CLEAR_DLP_CONTROL_1_PHY_TRAINING(l_dl_control_data);
    }

    (i_even_not_odd) ?
    SET_DLP_CONTROL_0_COMMAND(i_command, l_dl_control_data) :
    SET_DLP_CONTROL_1_COMMAND(i_command, l_dl_control_data);

    FAPI_TRY(PUT_DLP_CONTROL(i_target, l_dl_control_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_recal_stop
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_recal_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_config_data;

    // update DL config register
    FAPI_TRY(GET_DLP_CONFIG(i_target, l_dl_config_data),
             "Error from getScom (DLP_CONFIG)");
    SET_DLP_CONFIG_DISABLE_RECAL_START(l_dl_config_data);
    FAPI_TRY(PUT_DLP_CONFIG(i_target, l_dl_config_data),
             "Error from putScom (DLP_CONFIG)");

    // send command via DL state machine
    FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                 i_target,
                 i_even_not_odd,
                 p10_fbc_tdm_utils_dl_cmd_t::RESET_RECAL),
             "Error from p10_fbc_tdm_utils_dl_send_command (%s)",
             (i_even_not_odd) ? ("even") : ("odd"));

    FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                 i_target,
                 !i_even_not_odd,
                 p10_fbc_tdm_utils_dl_cmd_t::RESET_RECAL),
             "Error from p10_fbc_tdm_utils_dl_send_command (%s)",
             (!i_even_not_odd) ? ("odd") : ("even"));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_confirm_recal_stop
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_confirm_recal_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    FAPI_TRY(p10_io_iohs_poll_recal(i_target),
             "Error from p10_io_iohs_poll_recal");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_recal_restart
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_recal_restart(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::pauc;
    FAPI_DBG("Start");

    // send command via DL state machine
    FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                 i_target,
                 i_even_not_odd,
                 p10_fbc_tdm_utils_dl_cmd_t::START_RECAL),
             "Error from p10_fbc_tdm_utils_dl_send_command (%s)",
             (i_even_not_odd) ? ("even") : ("odd"));

    FAPI_TRY(p10_fbc_tdm_utils_dl_send_command(
                 i_target,
                 !i_even_not_odd,
                 p10_fbc_tdm_utils_dl_cmd_t::START_RECAL),
             "Error from p10_fbc_tdm_utils_dl_send_command (%s)",
             (!i_even_not_odd) ? ("odd") : ("even"));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_phy_pon
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_phy_pon(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_phy_psave_data = 0;

    // clear psave force reg/fence req on RX and TX lanes, in sequence
    if (i_even_not_odd)
    {
        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 9>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
    }
    else
    {
        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL13_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL14_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<57, 7>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL1_PG, l_phy_psave_data));

        FAPI_TRY(fapi2::getScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
        l_phy_psave_data.clearBit<48, 2>();
        FAPI_TRY(fapi2::putScom(i_target, IOO_TX0_TXCTL_TX_CTL_SM_REGS_CTLSM_CNTL2_PG, l_phy_psave_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_recal_cleanup
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_recal_cleanup(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt;
    using namespace scomt::pauc;
    FAPI_DBG("Start");

    // The delay must be longer than the time to recal 17/18 lanes.  We expect this to be less
    //   than 500ms, but we put in an extra 100ms buffer.  This is a long delay, but I
    //   don't expect this to be a problem as it is only running the Abus CCM rcovery case.
    const uint32_t c_ns_delay        = 1000000000;
    const uint32_t c_sim_cycle_delay = 10000;
    fapi2::buffer<uint64_t> l_data64(0x0);
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();


    FAPI_TRY(fapi2::delay(c_ns_delay, c_sim_cycle_delay),
             "Error from fapi2 delay while waiting for dl transition to recal start to complete");

    // re-enable error reporting for RECAL_NOT_RUN
    // clear FIR bit
    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_REG_WO_AND(l_pauc_target));
    CLEAR_PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN(l_data64);
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_REG_WO_AND(l_pauc_target, l_data64));
    //// clear FIR mask bit
    //FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_MASK_REG_WO_AND(l_pauc_target));
    //FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_WO_AND(l_pauc_target, l_data64));

    // clear IO PPE error valid state
    FAPI_TRY(p10_io_clear_error_valid(l_pauc_target));

    FAPI_TRY(p10_iohs_phy_set_action_state(i_target, 0x0));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_log_regs
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_log_regs(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    uint64_t l_scom_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    l_scom_addr = DLP_FIR_REG_RW;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_FIR_REG_RW: %016lX", l_scom_data);

    l_scom_addr = DLP_CONFIG;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_CONFIG: %016lX", l_scom_data);

    l_scom_addr = DLP_CONTROL;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_CONTROL: %016lX", l_scom_data);

    l_scom_addr = DLP_PHY_CONFIG;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_PHY_CONFIG: %016lX", l_scom_data);

    l_scom_addr = DLP_SEC_CONFIG;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_SEC_CONFIG: %016lX", l_scom_data);

    l_scom_addr = DLP_LAT_MEASURE;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LAT_MEASURE: %016lX", l_scom_data);

    l_scom_addr = DLP_OPTICAL_CONFIG;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_OPTICAL_CONFIG: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK0_TX_LANE_CONTROL;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK0_TX_LANE_CONTROL: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK1_TX_LANE_CONTROL;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK1_TX_LANE_CONTROL: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK0_RX_LANE_CONTROL;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK0_RX_LANE_CONTROL: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK1_RX_LANE_CONTROL;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK1_RX_LANE_CONTROL: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK0_ERROR_STATUS;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK0_ERROR_STATUS: %016lX", l_scom_data);

    l_scom_addr = DLP_LINK1_ERROR_STATUS;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_LINK1_ERROR_STATUS: %016lX", l_scom_data);

    l_scom_addr = DLP_DLL_STATUS;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_DLL_STATUS: %016lX", l_scom_data);

    l_scom_addr = DLP_MISC_ERROR_STATUS;
    FAPI_TRY(fapi2::getScom(i_target, l_scom_addr, l_scom_data));
    FAPI_DBG("DLP_MISC_ERROR_STATUS: %016lX", l_scom_data);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
