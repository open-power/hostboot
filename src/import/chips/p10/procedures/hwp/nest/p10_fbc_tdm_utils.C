/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_tdm_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
//#include <p10_io_scom.H>
//#include <p10_io_regs.H>
//#include <p10_io_common.H>
//#include <p10_obus_fir_utils.H>
#include <p10_scom_iohs_c.H>
#include <p10_scom_iohs_d.H>
#include <p10_scom_iohs_e.H>
#include <p10_scom_pauc_2.H>
#include <p10_scom_pauc_9.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_fir_mask
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_fir_mask(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    FAPI_DBG("Start");

    sublink_t l_sublink = (i_even_not_odd) ? (sublink_t::EVEN) : (sublink_t::ODD);
    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink, action_t::INACTIVE),
             "Error from p10_smp_link_firs");

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

    sublink_t l_sublink = (i_even_not_odd) ? (sublink_t::EVEN) : (sublink_t::ODD);

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink, action_t::CLEAR_ALL),
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

    sublink_t l_sublink = (i_even_not_odd) ? (sublink_t::EVEN) : (sublink_t::ODD);

    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink, action_t::CLEAR_ERR),
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

    sublink_t l_sublink = (i_even_not_odd) ? (sublink_t::EVEN) : (sublink_t::ODD);
    FAPI_TRY(p10_smp_link_firs(i_target, l_sublink, action_t::RUNTIME),
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
    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_loc_config_mode;
    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_rem_config_mode;
    fapi2::ReturnCode l_rc;

    FAPI_DBG("Start");

    // verify link configuration
    l_rc = i_target.getOtherEnd(l_rem_target);

    FAPI_ASSERT(!l_rc,
                fapi2::P10_FBC_TDM_UTILS_REM_ENDP_TARGET_ERR()
                .set_LOC_ENDP_TARGET(i_target),
                "No remote endpoint target found for given local link endpoint!");

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

    (i_even_not_odd) ?
    SET_DLP_CONTROL_0_COMMAND(i_command, l_dl_control_data) :
    SET_DLP_CONTROL_1_COMMAND(i_command, l_dl_control_data);

    FAPI_TRY(PUT_DLP_CONTROL(i_target, l_dl_control_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_ppe_halt
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_ppe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_ppe_xixcr(0x0);

    FAPI_TRY(PREP_DL_PPE_WRAP_XIXCR(l_pauc_target));
    SET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(p10_fbc_tdm_utils_ppe_cmd_t::HALT, l_ppe_xixcr);
    FAPI_TRY(PUT_DL_PPE_WRAP_XIXCR(l_pauc_target, l_ppe_xixcr));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_tdm_utils_ppe_restart
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_tdm_utils_ppe_restart(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_even_not_odd)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_ppe_xixcr(0x0);

    FAPI_TRY(PREP_DL_PPE_WRAP_XIXCR(l_pauc_target));

    SET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(p10_fbc_tdm_utils_ppe_cmd_t::HARD_RESET, l_ppe_xixcr);
    FAPI_TRY(PUT_DL_PPE_WRAP_XIXCR(l_pauc_target, l_ppe_xixcr));

    SET_DL_PPE_WRAP_XIXCR_PPE_XIXCR_XCR(p10_fbc_tdm_utils_ppe_cmd_t::RESUME, l_ppe_xixcr);
    FAPI_TRY(PUT_DL_PPE_WRAP_XIXCR(l_pauc_target, l_ppe_xixcr));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
