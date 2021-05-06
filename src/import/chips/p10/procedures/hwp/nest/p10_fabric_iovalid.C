/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_iovalid.C $ */
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
/// @file p10_fabric_iovalid.C
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fabric_iovalid.H>
#include <p10_scom_proc.H>
#include <p10_scom_pauc.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

enum dl_training_states
{
    DL_STATE_INACTIVE       = 0,
    DL_STATE_PSAVE_TSTART   = 1,
    DL_STATE_SEND_T2        = 2,
    DL_STATE_SEND_TSTART    = 3,
    DL_STATE_WAIT_TCOMP     = 4,
    DL_STATE_READY          = 5,
    DL_STATE_LAT_MEASURE    = 6,
    DL_STATE_PSAVE_TCOMP    = 7,
    DL_STATE_SEND_TS1       = 8,
    DL_STATE_SEND_TS2       = 9,
    DL_STATE_SEND_TS3       = 10,
    DL_STATE_LINKDOWN       = 11,
    DL_STATE_SEND_PATTA     = 12,
    DL_STATE_SEND_PATTB     = 13,
    DL_STATE_SEND_SYNC      = 14,
    DL_STATE_LINKUP         = 15,
};

const uint32_t DL_NUM_LANES_PER_HALF_LINK = 9;

const uint32_t DL_MAX_POLL_LOOPS   = 1000;
const uint32_t DL_POLL_SIM_CYCLES  = 10000000;
const uint32_t DL_POLL_HW_DELAY_NS = 20000000;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Append DL layer specific FFDC in the event of a training failure
///
/// @param[in] i_iohs_target    Reference to IOHS target
/// @param[inout] o_rc          Return code object to be appended
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
void p10_fabric_iovalid_append_dl_ffdc(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    fapi2::ReturnCode& o_rc)
{
    using namespace scomt::iohs;

    uint64_t l_scom_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    uint64_t l_fir_reg;
    fapi2::ffdc_t FIR_REG;
    l_scom_addr = DLP_FIR_REG_RW;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_fir_reg = l_scom_data();
    FIR_REG.ptr() = static_cast<void*>(&l_fir_reg);
    FIR_REG.size() = sizeof(l_fir_reg);

    uint64_t l_config_reg;
    fapi2::ffdc_t CONFIG_REG;
    l_scom_addr = DLP_CONFIG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_config_reg = l_scom_data();
    CONFIG_REG.ptr() = static_cast<void*>(&l_config_reg);
    CONFIG_REG.size() = sizeof(l_config_reg);

    uint64_t l_control_reg;
    fapi2::ffdc_t CONTROL_REG;
    l_scom_addr = DLP_CONTROL;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_control_reg = l_scom_data();
    CONTROL_REG.ptr() = static_cast<void*>(&l_control_reg);
    CONTROL_REG.size() = sizeof(l_control_reg);

    uint64_t l_config_phy_reg;
    fapi2::ffdc_t CONFIG_PHY_REG;
    l_scom_addr = DLP_PHY_CONFIG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_config_phy_reg = l_scom_data();
    CONFIG_PHY_REG.ptr() = static_cast<void*>(&l_config_phy_reg);
    CONFIG_PHY_REG.size() = sizeof(l_config_phy_reg);

    uint64_t l_secondary_config_reg;
    fapi2::ffdc_t SECONDARY_CONFIG_REG;
    l_scom_addr = DLP_SEC_CONFIG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_secondary_config_reg = l_scom_data();
    SECONDARY_CONFIG_REG.ptr() = static_cast<void*>(&l_secondary_config_reg);
    SECONDARY_CONFIG_REG.size() = sizeof(l_secondary_config_reg);

    uint64_t l_latency_reg;
    fapi2::ffdc_t LATENCY_REG;
    l_scom_addr = DLP_LAT_MEASURE;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_latency_reg = l_scom_data();
    LATENCY_REG.ptr() = static_cast<void*>(&l_latency_reg);
    LATENCY_REG.size() = sizeof(l_latency_reg);

    uint64_t l_optical_config_reg;
    fapi2::ffdc_t OPTICAL_CONFIG_REG;
    l_scom_addr = DLP_OPTICAL_CONFIG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_optical_config_reg = l_scom_data();
    OPTICAL_CONFIG_REG.ptr() = static_cast<void*>(&l_optical_config_reg);
    OPTICAL_CONFIG_REG.size() = sizeof(l_optical_config_reg);

    uint64_t l_tx0_lane_control_reg;
    fapi2::ffdc_t TX0_LANE_CONTROL_REG;
    l_scom_addr = DLP_LINK0_TX_LANE_CONTROL;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_tx0_lane_control_reg = l_scom_data();
    TX0_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_tx0_lane_control_reg);
    TX0_LANE_CONTROL_REG.size() = sizeof(l_tx0_lane_control_reg);

    uint64_t l_tx1_lane_control_reg;
    fapi2::ffdc_t TX1_LANE_CONTROL_REG;
    l_scom_addr = DLP_LINK1_TX_LANE_CONTROL;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_tx1_lane_control_reg = l_scom_data();
    TX1_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_tx1_lane_control_reg);
    TX1_LANE_CONTROL_REG.size() = sizeof(l_tx1_lane_control_reg);

    uint64_t l_rx0_lane_control_reg;
    fapi2::ffdc_t RX0_LANE_CONTROL_REG;
    l_scom_addr = DLP_LINK0_RX_LANE_CONTROL;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_rx0_lane_control_reg = l_scom_data();
    RX0_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_rx0_lane_control_reg);
    RX0_LANE_CONTROL_REG.size() = sizeof(l_rx0_lane_control_reg);

    uint64_t l_rx1_lane_control_reg;
    fapi2::ffdc_t RX1_LANE_CONTROL_REG;
    l_scom_addr = DLP_LINK1_RX_LANE_CONTROL;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_rx1_lane_control_reg = l_scom_data();
    RX1_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_rx1_lane_control_reg);
    RX1_LANE_CONTROL_REG.size() = sizeof(l_rx1_lane_control_reg);

    uint64_t l_err0_status_reg;
    fapi2::ffdc_t ERR0_STATUS_REG;
    l_scom_addr = DLP_LINK0_ERROR_STATUS;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_err0_status_reg = l_scom_data();
    ERR0_STATUS_REG.ptr() = static_cast<void*>(&l_err0_status_reg);
    ERR0_STATUS_REG.size() = sizeof(l_err0_status_reg);

    uint64_t l_err1_status_reg;
    fapi2::ffdc_t ERR1_STATUS_REG;
    l_scom_addr = DLP_LINK1_ERROR_STATUS;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_err1_status_reg = l_scom_data();
    ERR1_STATUS_REG.ptr() = static_cast<void*>(&l_err1_status_reg);
    ERR1_STATUS_REG.size() = sizeof(l_err1_status_reg);

    uint64_t l_status_reg;
    fapi2::ffdc_t STATUS_REG;
    l_scom_addr = DLP_DLL_STATUS;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_status_reg = l_scom_data();
    STATUS_REG.ptr() = static_cast<void*>(&l_status_reg);
    STATUS_REG.size() = sizeof(l_status_reg);

    uint64_t l_err_misc_reg;
    fapi2::ffdc_t ERR_MISC_REG;
    l_scom_addr = DLP_MISC_ERROR_STATUS;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_iohs_target, l_scom_addr, l_scom_data);
    l_err_misc_reg = l_scom_data();
    ERR_MISC_REG.ptr() = static_cast<void*>(&l_err_misc_reg);
    ERR_MISC_REG.size() = sizeof(l_err_misc_reg);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P10_FAB_IOVALID_DL_FFDC_ERR);
}

///
/// @brief Append TL layer specific FFDC in the event of a training failure
///
/// @param[in] i_pauc_target    Reference to PAUC target associated with link
/// @param[inout] o_rc          Return code object to be appended
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
void p10_fabric_iovalid_append_tl_ffdc(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    fapi2::ReturnCode& o_rc)
{
    using namespace scomt::proc;

    uint64_t l_scom_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    uint64_t l_fir_reg;
    fapi2::ffdc_t FIR_REG;
    l_scom_addr = PB_PTLSCOM10_PTL_FIR_REG_RW;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_fir_reg = l_scom_data();
    FIR_REG.ptr() = static_cast<void*>(&l_fir_reg);
    FIR_REG.size() = sizeof(l_fir_reg);

    uint64_t l_config01_reg;
    fapi2::ffdc_t CONFIG01_REG;
    l_scom_addr = PB_PTLSCOM10_FP01_CFG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_config01_reg = l_scom_data();
    CONFIG01_REG.ptr() = static_cast<void*>(&l_config01_reg);
    CONFIG01_REG.size() = sizeof(l_config01_reg);

    uint64_t l_config23_reg;
    fapi2::ffdc_t CONFIG23_REG;
    l_scom_addr = PB_PTLSCOM10_FP23_CFG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_config23_reg = l_scom_data();
    CONFIG23_REG.ptr() = static_cast<void*>(&l_config23_reg);
    CONFIG23_REG.size() = sizeof(l_config23_reg);

    uint64_t l_misc_config_reg;
    fapi2::ffdc_t MISC_CONFIG_REG;
    l_scom_addr = PB_PTLSCOM10_MISC_CFG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_misc_config_reg = l_scom_data();
    MISC_CONFIG_REG.ptr() = static_cast<void*>(&l_misc_config_reg);
    MISC_CONFIG_REG.size() = sizeof(l_misc_config_reg);

    uint64_t l_framer0123_err_reg;
    fapi2::ffdc_t FRAMER0123_ERR_REG;
    l_scom_addr = PB_PTLSCOM10_FM0123_ERR;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_framer0123_err_reg = l_scom_data();
    FRAMER0123_ERR_REG.ptr() = static_cast<void*>(&l_framer0123_err_reg);
    FRAMER0123_ERR_REG.size() = sizeof(l_framer0123_err_reg);

    uint64_t l_parser0123_err_reg;
    fapi2::ffdc_t PARSER0123_ERR_REG;
    l_scom_addr = PB_PTLSCOM10_PR0123_ERR;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_pauc_target, l_scom_addr, l_scom_data);
    l_parser0123_err_reg = l_scom_data();
    PARSER0123_ERR_REG.ptr() = static_cast<void*>(&l_parser0123_err_reg);
    PARSER0123_ERR_REG.size() = sizeof(l_parser0123_err_reg);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P10_FAB_IOVALID_TL_FFDC_ERR);
}

///
/// @brief Return remote endpoint target for given local endpoint
///
/// @param[in] i_loc_endp_target    Reference to IOLINK target for local endpoint
/// @param[out] o_rem_endp_target   Reference to IOLINK target for remote endpoint
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_get_rem_endp(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_loc_endp_target,
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& o_rem_endp_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_endp_target;
    fapi2::ReturnCode l_rc = i_loc_endp_target.getOtherEnd(l_rem_endp_target);

    FAPI_ASSERT(!l_rc,
                fapi2::P10_FAB_IOVALID_REM_ENDP_TARGET_ERR()
                .set_LOC_ENDP_TARGET(i_loc_endp_target),
                "Endpoint target at other end of link is invalid!");

    o_rem_endp_target = l_rem_endp_target;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

//
// @brief Helper function to count half-link per-lane train/fail bit indications
//
// @param[in] i_lane_info      Lane information data
// @param[in] o_lane_count     Number of bits set in lane information input
//
// @return void.
//
void p10_fabric_iovalid_count_ones(
    const uint64_t i_lane_info,
    uint64_t& o_lane_count)
{
    uint16_t l_lane_info = i_lane_info;
    o_lane_count = 0;

    for (uint32_t ii = 0; ii < DL_NUM_LANES_PER_HALF_LINK; ii++)
    {
        if (l_lane_info & 1)
        {
            o_lane_count++;
        }

        l_lane_info = l_lane_info >> 1;
    }
}

//
// @brief Signal lane sparing FIR if link trains but reports a failed lane
//
// @param[in] i_iohs_target    Reference to IOHS target
// @param[in] i_even_not_odd   Indicate link half to check (true=even, false=odd)
// @param[out] o_bus_failed    Mark bus failed based on lane status
//
// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
//
fapi2::ReturnCode p10_fabric_iovalid_lane_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const bool i_even_not_odd,
    bool& o_bus_failed)
{
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_rx_control;
    fapi2::buffer<uint64_t> l_dl_fir;
    uint64_t l_lane_failed           = 0x1FF;
    uint64_t l_lane_not_locked       = 0x1FF;
    uint64_t l_lane_enabled          = 0x1FF;
    uint64_t l_lane_failed_count     = DL_NUM_LANES_PER_HALF_LINK;
    uint64_t l_lane_not_locked_count = DL_NUM_LANES_PER_HALF_LINK;
    o_bus_failed = false;

    FAPI_INF("Checking for fail on %s lanes", ((i_even_not_odd) ? ("even") : ("odd")));

    if(i_even_not_odd)
    {
        FAPI_TRY(GET_DLP_LINK0_RX_LANE_CONTROL(i_iohs_target, l_dl_rx_control),
                 "Error from getScom (DLP_LINK0_RX_LANE_CONTROL)");

        GET_DLP_LINK0_RX_LANE_CONTROL_FAILED(l_dl_rx_control, l_lane_failed);
        l_dl_rx_control.invert();
        GET_DLP_LINK0_RX_LANE_CONTROL_DISABLED(l_dl_rx_control, l_lane_enabled);
        GET_DLP_LINK0_RX_LANE_CONTROL_LOCKED(l_dl_rx_control, l_lane_not_locked);
    }
    else
    {
        FAPI_TRY(GET_DLP_LINK1_RX_LANE_CONTROL(i_iohs_target, l_dl_rx_control),
                 "Error from getScom (DLP_LINK1_RX_LANE_CONTROL)");

        GET_DLP_LINK1_RX_LANE_CONTROL_FAILED(l_dl_rx_control, l_lane_failed);
        l_dl_rx_control.invert();
        GET_DLP_LINK1_RX_LANE_CONTROL_DISABLED(l_dl_rx_control, l_lane_enabled);
        GET_DLP_LINK1_RX_LANE_CONTROL_LOCKED(l_dl_rx_control, l_lane_not_locked);
    }

    FAPI_INF("Lane status: lanes failed = 0x%03X, lanes not locked = 0x%03X, lanes enabled = 0x%03X",
             l_lane_failed, l_lane_not_locked, l_lane_enabled);

    l_lane_failed &= l_lane_enabled;
    l_lane_not_locked &= l_lane_enabled;

    p10_fabric_iovalid_count_ones(l_lane_failed, l_lane_failed_count);
    p10_fabric_iovalid_count_ones(l_lane_not_locked, l_lane_not_locked_count);

    if ((l_lane_failed_count == 0) && (l_lane_not_locked_count == 0))
    {
        goto fapi_try_exit;
    }
    else
    {
        FAPI_INF("Non-zero lane error count: lanes failed = %d, lanes not locked = %d",
                 l_lane_failed_count, l_lane_not_locked_count);

        if ((l_lane_failed_count <= 1) && (l_lane_not_locked_count <= 1))
        {
            FAPI_TRY(PREP_DLP_FIR_REG_WO_OR(i_iohs_target));

            if (i_even_not_odd)
            {
                SET_DLP_FIR_REG_0_SPARE_DONE(l_dl_fir);
            }
            else
            {
                SET_DLP_FIR_REG_1_SPARE_DONE(l_dl_fir);
            }

            FAPI_TRY(PUT_DLP_FIR_REG_WO_OR(i_iohs_target, l_dl_fir),
                     "Error from putScom (DLP_FIR_REG_WO_OR)");
        }
        else
        {
            o_bus_failed = true;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Validate DL/TL link layers are trained
///
/// @param[in] i_loc_endp_target    Reference to IOHS target for local endpoint
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_link_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_loc_endp_target)
{
    using namespace scomt::pauc;
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_fir_reg;
    fapi2::buffer<uint64_t> l_dl_status_reg;
    fapi2::buffer<uint64_t> l_dl_rx_control;
    fapi2::buffer<uint64_t> l_tl_fir_reg;
    bool l_dl_trained = false;
    bool l_dl_fail_evn = false;
    bool l_dl_fail_odd = false;
    bool l_tl_trained = false;
    bool l_tl_fail_evn = false;
    bool l_tl_fail_odd = false;

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit_id;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_loc_link_train;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_loc_link_train_next;
    fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_rem_evn_pauc_target;
    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_rem_odd_pauc_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_evn_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_odd_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_loc_evn_iolink_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_loc_odd_iolink_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_evn_iolink_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_odd_iolink_target;
    auto l_loc_pauc_target = i_loc_endp_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    auto l_loc_iolink_targets = i_loc_endp_target.getChildren<fapi2::TARGET_TYPE_IOLINK>();

    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_loc_endp_target, l_targetStr, sizeof(l_targetStr));

    // handle Cronus platform implementation of IOLINK targets -- both
    // children are always returned as functional, even if no valid remote endpoint
    // connection exists
    if (fapi2::is_platform<fapi2::PLAT_CRONUS>())
    {
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>> l_loc_iolink_targets_filtered;

        for (auto l_loc_iolink_target : l_loc_iolink_targets)
        {
            fapi2::ReturnCode l_rc;
            fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;
            l_rc = l_loc_iolink_target.getOtherEnd(l_rem_iolink_target);

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                l_loc_iolink_targets_filtered.push_back(l_loc_iolink_target);
            }
        }

        l_loc_iolink_targets = l_loc_iolink_targets_filtered;
    }

    // obtain link endpoints and determine associated targets for FFDC
    for (auto l_loc_iolink_target : l_loc_iolink_targets)
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_loc_iolink_id;
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;

        char l_iolink_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_loc_iolink_target, l_iolink_targetStr, sizeof(l_iolink_targetStr));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_loc_iolink_target, l_loc_iolink_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        FAPI_INF("iolink: %s, unit_pos: %d",
                 l_iolink_targetStr, l_loc_iolink_id);

        if ((l_loc_iolink_id % 2) == 0)
        {
            FAPI_INF("  set even FFDC");
            l_loc_evn_iolink_target = l_loc_iolink_target;
        }
        else
        {
            FAPI_INF("  set odd FFDC");
            l_loc_odd_iolink_target = l_loc_iolink_target;
        }

        FAPI_TRY(p10_fabric_iovalid_get_rem_endp(l_loc_iolink_target, l_rem_iolink_target),
                 "Error from p10_fabric_iovalid_get_rem_endp");

        if ((l_loc_iolink_id % 2) == 0)
        {
            l_rem_evn_iolink_target = l_rem_iolink_target;
            l_rem_evn_endp_target = l_rem_evn_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();
            l_rem_evn_pauc_target = l_rem_evn_endp_target.getParent<fapi2::TARGET_TYPE_PAUC>();
        }
        else
        {
            l_rem_odd_iolink_target = l_rem_iolink_target;
            l_rem_odd_endp_target = l_rem_odd_iolink_target.getParent<fapi2::TARGET_TYPE_IOHS>();
            l_rem_odd_pauc_target = l_rem_odd_endp_target.getParent<fapi2::TARGET_TYPE_PAUC>();
        }
    }

    // determine which sublinks are trained
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_loc_endp_target, l_loc_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, i_loc_endp_target, l_link_split),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_loc_endp_target, l_iohs_unit_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    FAPI_INF("iohs: %s link_train: %d, link_split: %d, unit_pos: %d",
             l_targetStr, l_loc_link_train, l_link_split, l_iohs_unit_id);

    // validate DL training state; poll for training completion
    for(uint32_t l_poll_loops = DL_MAX_POLL_LOOPS; l_poll_loops > 0 && !l_dl_trained; l_poll_loops--)
    {
        uint64_t l_dl_timeout_state_evn = 0;
        uint64_t l_dl_current_state_evn = 0;
        uint64_t l_dl_prior_state_evn = 0;
        uint64_t l_dl_timeout_state_odd = 0;
        uint64_t l_dl_current_state_odd = 0;
        uint64_t l_dl_prior_state_odd = 0;

        FAPI_TRY(GET_DLP_DLL_STATUS(i_loc_endp_target, l_dl_status_reg),
                 "Error from getScom (DLP_DLL_STATUS)");

        GET_DLP_DLL_STATUS_0_TIMEOUT_STATE(l_dl_status_reg, l_dl_timeout_state_evn);
        GET_DLP_DLL_STATUS_0_CURRENT_STATE(l_dl_status_reg, l_dl_current_state_evn);
        GET_DLP_DLL_STATUS_0_PRIOR_STATE(l_dl_status_reg, l_dl_prior_state_evn);

        GET_DLP_DLL_STATUS_1_TIMEOUT_STATE(l_dl_status_reg, l_dl_timeout_state_odd);
        GET_DLP_DLL_STATUS_1_CURRENT_STATE(l_dl_status_reg, l_dl_current_state_odd);
        GET_DLP_DLL_STATUS_1_PRIOR_STATE(l_dl_status_reg, l_dl_prior_state_odd);

        FAPI_TRY(GET_DLP_FIR_REG_RW(i_loc_endp_target, l_dl_fir_reg),
                 "Error from getScom (DLP_FIR_REG_RW)");

        if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
        {
            l_dl_trained = GET_DLP_FIR_REG_0_TRAINED(l_dl_fir_reg) &&
                           GET_DLP_FIR_REG_1_TRAINED(l_dl_fir_reg);

            // *INDENT-OFF*
            if (!l_dl_trained)
            {
                // wihthout HW trained indication, mark half link failed unless
                // it matches one of two pass criteria:
                l_dl_fail_evn =
                    !(
                      // pass criteria #1: timeout state in Latency Measure on this link only
                      (
                       (l_dl_timeout_state_evn == DL_STATE_LAT_MEASURE) &&
                       (l_dl_timeout_state_odd != DL_STATE_LAT_MEASURE)
                      )

                      ||

                      // pass criteria #2: timeout state Inactive on this link:
                      (
                       (l_dl_timeout_state_evn == DL_STATE_INACTIVE) &&

                       (
                        // 2a) this link: TS1/TS2 and other: LINKDOWN/PATA/PATB/SYNC
                        (((l_dl_current_state_evn == DL_STATE_SEND_TS1) || (l_dl_prior_state_evn == DL_STATE_SEND_TS1) ||
                          (l_dl_current_state_evn == DL_STATE_SEND_TS2) || (l_dl_prior_state_evn == DL_STATE_SEND_TS2)) &&
                         ((l_dl_current_state_odd >= DL_STATE_LINKDOWN) && (l_dl_current_state_odd <= DL_STATE_SEND_SYNC)))

                        ||

                        // 2b) this link: T2 and other: TS1/TS2/TS3/LINKDOWN/PATA
                        ((l_dl_current_state_evn == DL_STATE_SEND_T2) &&
                         ((l_dl_current_state_odd >= DL_STATE_SEND_TS1) && (l_dl_current_state_odd <= DL_STATE_SEND_PATTA)))
                       )
                      )
                     );

                l_dl_fail_odd =
                    !(
                      // pass criteria #1: timeout state in Latency Measure on this link only
                      (
                       (l_dl_timeout_state_odd == DL_STATE_LAT_MEASURE) &&
                       (l_dl_timeout_state_evn != DL_STATE_LAT_MEASURE)
                      )

                      ||

                      // pass criteria #2: timeout state Inactive on this link:
                      (
                       (l_dl_timeout_state_odd == DL_STATE_INACTIVE) &&

                       (
                        // 2a) this link: TS1/TS2 and other: LINKDOWN/PATA/PATB/SYNC
                        (((l_dl_current_state_odd == DL_STATE_SEND_TS1) || (l_dl_prior_state_odd == DL_STATE_SEND_TS1) ||
                          (l_dl_current_state_odd == DL_STATE_SEND_TS2) || (l_dl_prior_state_odd == DL_STATE_SEND_TS2)) &&
                         ((l_dl_current_state_evn >= DL_STATE_LINKDOWN) && (l_dl_current_state_evn <= DL_STATE_SEND_SYNC)))

                        ||

                        // 2b) this link: T2 and other: TS1/TS2/TS3/LINKDOWN/PATA
                        ((l_dl_current_state_odd == DL_STATE_SEND_T2) &&
                         ((l_dl_current_state_evn >= DL_STATE_SEND_TS1) && (l_dl_current_state_evn <= DL_STATE_SEND_PATTA)))
                       )
                      )
                     );

                FAPI_INF("evn fail: %d, timeout_state: 0x%X / odd fail: %d, timeout_state: 0x%X",
                         l_dl_fail_evn ? (1) : (0), l_dl_timeout_state_evn,
                         l_dl_fail_odd ? (1) : (0), l_dl_timeout_state_odd);
            }
            else
            {
                // ensure fail indicators are cleared from prior loop, to
                // guarantee that spare lanes are checked on both even/odd
                l_dl_fail_evn = false;
                l_dl_fail_odd = false;
            }
            // *INDENT-ON*
        }
        else if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
        {
            l_dl_trained = GET_DLP_FIR_REG_0_TRAINED(l_dl_fir_reg);
            l_dl_fail_evn = !l_dl_trained;
            l_dl_fail_odd = true;
        }
        else
        {
            l_dl_trained = GET_DLP_FIR_REG_1_TRAINED(l_dl_fir_reg);
            l_dl_fail_evn = true;
            l_dl_fail_odd = !l_dl_trained;
        }

        if (!l_dl_trained)
        {
            FAPI_TRY(fapi2::delay(DL_POLL_HW_DELAY_NS, DL_POLL_SIM_CYCLES), "fapiDelay error");
        }
    }

    // If dl reported trained, validate that no lane sparing occurred during the
    // training process; hardware does not report to a FIR if a spare lane was
    // used during training
    //
    // As we are not persisting bad lane information, we do not want to fail the
    // IPL directly if a single spare occurs, but can raise a FIR to indicate to PRD
    // that the spare has been consumed during training (MFG may choose to fail
    // based on this criteria)
    //
    // If more than one spare is detected during training, mark the link as failed
    // (hw may also raise an error by setting the training_failed FIR at this point)
    if (l_dl_trained)
    {
        FAPI_INF("Checking for DL lane failures");

        bool l_dl_fail_by_lane_status = false;

        if (!l_dl_fail_evn)
        {
            FAPI_TRY(p10_fabric_iovalid_lane_validate(
                         i_loc_endp_target,
                         true,
                         l_dl_fail_by_lane_status),
                     "Error from p10_fabric_iovalid_lane_validate (even)");

            if (l_dl_fail_by_lane_status)
            {
                l_dl_trained = false;
                l_dl_fail_evn = true;
            }
        }

        if (!l_dl_fail_odd)
        {
            FAPI_TRY(p10_fabric_iovalid_lane_validate(
                         i_loc_endp_target,
                         false,
                         l_dl_fail_by_lane_status),
                     "Error from p10_fabric_iovalid_lane_validate (odd)");

            if (l_dl_fail_by_lane_status)
            {
                l_dl_trained = false;
                l_dl_fail_odd = true;
            }
        }
    }
    else
    {
        FAPI_INF("Skipping check for DL lane failures");
    }

    // Reconfigure link train attribute to attempt retrain
    if (!l_dl_trained)
    {
        FAPI_ERR("Error in DL training for %s (ATTR_IOHS_LINK_TRAIN: 0x%x, DL training failed: %d / %d)",
                 l_targetStr, l_loc_link_train, l_dl_fail_evn, l_dl_fail_odd);

        // attempt to retrain on half link, only if:
        // - tried to train in full width mode
        // - exactly one half reported good & one half reported bad
        if ((l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH) &&
            ((l_dl_fail_evn && !l_dl_fail_odd) || (!l_dl_fail_evn && l_dl_fail_odd)))
        {
            l_loc_link_train_next = (l_dl_fail_evn) ?
                                    (fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY) :
                                    (fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY);

            FAPI_INF("Retraining is possible with half-link configuration");
        }
        // otherwise, no retraining will be attempted:
        // - tried to train only half-width, and was not successful
        // - tried to train full-width, and both links failed
        else
        {
            l_loc_link_train_next = fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE;
            FAPI_INF("Retraining not possible and will not be attempted");
        }

        FAPI_INF("Reconfiguring ATTR_IOHS_LINK_TRAIN from 0x%X -> 0x%X for %s",
                 l_loc_link_train, l_loc_link_train_next, l_targetStr);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_LINK_TRAIN, i_loc_endp_target, l_loc_link_train_next),
                 "Error from FAPI_ATTR_SET (ATTR_IOHS_LINK_TRAIN)");

        // if nothing is left to run on, emit RC with callout/deconfig on IOHS endpoints (no retraining for this bus)
        if (l_loc_link_train_next == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE)
        {
            if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR()
                            .set_LOC_ENDP_TARGET(i_loc_endp_target)
                            .set_LOC_IOLINK_EVN_TARGET(l_loc_evn_iolink_target)
                            .set_LOC_IOLINK_ODD_TARGET(l_loc_odd_iolink_target)
                            .set_LOC_LINK_TRAIN(l_loc_link_train)
                            .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                            .set_LOC_IOLINK_EVN_FAIL(l_dl_fail_evn)
                            .set_LOC_IOLINK_ODD_FAIL(l_dl_fail_odd)
                            .set_REM_IOLINK_EVN_TARGET(l_rem_evn_iolink_target)
                            .set_REM_IOLINK_ODD_TARGET(l_rem_odd_iolink_target),
                            "Full-width link DL training did not complete successfully, no retry possible!");
            }
            else
            {
                FAPI_ASSERT(false,
                            fapi2::P10_FAB_IOVALID_DL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR()
                            .set_LOC_ENDP_TARGET(i_loc_endp_target)
                            .set_LOC_IOLINK_TARGET(l_dl_fail_evn ? l_loc_evn_iolink_target : l_loc_odd_iolink_target)
                            .set_LOC_LINK_TRAIN(l_loc_link_train)
                            .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                            .set_LOC_IOLINK_EVN_FAIL(l_dl_fail_evn)
                            .set_LOC_IOLINK_ODD_FAIL(l_dl_fail_odd)
                            .set_REM_IOLINK_TARGET(l_dl_fail_evn ? l_rem_evn_iolink_target : l_rem_odd_iolink_target),
                            "Half-width link DL training did not complete successfully, no retry possible!");
            }
        }

        // else, emit RC with callout/deconfig on IOHS sublink (and attempt retraining on other half link)
        FAPI_ASSERT(false,
                    fapi2::P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_IOLINK_TARGET(l_dl_fail_evn ? l_loc_evn_iolink_target : l_loc_odd_iolink_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_IOLINK_EVN_FAIL(l_dl_fail_evn)
                    .set_LOC_IOLINK_ODD_FAIL(l_dl_fail_odd)
                    .set_REM_ENDP_TARGET(l_dl_fail_evn ? l_rem_evn_endp_target : l_rem_odd_endp_target)
                    .set_REM_IOLINK_TARGET(l_dl_fail_evn ? l_rem_evn_iolink_target : l_rem_odd_iolink_target),
                    "Full-width link DL training did not complete successfully, attempt retraining with passing sublink!");
    }

    // validate TL training state
    FAPI_INF("Validating TL training state...");

    FAPI_TRY(GET_PB_PTL_FIR_REG_RW(l_loc_pauc_target, l_tl_fir_reg),
             "Error from getScom (PB_PTLSCOM10_PTL_FIR_REG_RW)");

    if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
    {
        if (l_link_split)
        {
            l_tl_fail_evn = !GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg);
            l_tl_fail_odd = !GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg);
        }
        else if ((l_iohs_unit_id % 2) == 0)
        {
            l_tl_fail_evn = !GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg);
            l_tl_fail_odd = !GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg);
        }
        else
        {
            l_tl_fail_evn = !GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg);
            l_tl_fail_odd = !GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg);
        }

        l_tl_trained = !l_tl_fail_evn && !l_tl_fail_odd;

        // if nothing is left to run on, emit RC with callout/deconfig on IOHS endpoints (no retraining for this bus)
        FAPI_ASSERT(!l_tl_fail_evn || !l_tl_fail_odd,
                    fapi2::P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_IOLINK_EVN_TARGET(l_loc_evn_iolink_target)
                    .set_LOC_IOLINK_ODD_TARGET(l_loc_odd_iolink_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_IOLINK_EVN_FAIL(l_tl_fail_evn)
                    .set_LOC_IOLINK_ODD_FAIL(l_tl_fail_odd)
                    .set_REM_IOLINK_EVN_TARGET(l_rem_evn_iolink_target)
                    .set_REM_IOLINK_ODD_TARGET(l_rem_odd_iolink_target),
                    "Full-width link TL training did not complete successfully, no retry possible!");

        // else if not trained, emit RC with callout/deconfig on IOHS sublink (and attempt retraining on other half link)
        FAPI_ASSERT(l_tl_trained,
                    fapi2::P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_IOLINK_TARGET(l_tl_fail_evn ? l_loc_evn_iolink_target : l_loc_odd_iolink_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_IOLINK_EVN_FAIL(l_tl_fail_evn)
                    .set_LOC_IOLINK_ODD_FAIL(l_tl_fail_odd)
                    .set_REM_ENDP_TARGET(l_tl_fail_evn ? l_rem_evn_endp_target : l_rem_odd_endp_target)
                    .set_REM_IOLINK_TARGET(l_tl_fail_evn ? l_rem_evn_iolink_target : l_rem_odd_iolink_target),
                    "Full-width link DL training did not complete successfully, attempt retraining with passing sublink!");
    }
    else
    {
        if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
        {
            l_tl_fail_odd = false;

            if (l_link_split ||
                ((l_iohs_unit_id % 2) == 0))
            {
                l_tl_fail_evn = !GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg);
            }
            else
            {
                l_tl_fail_evn = !GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg);
            }
        }
        else
        {
            l_tl_fail_evn = false;

            if ((l_iohs_unit_id % 2) == 0)
            {
                l_tl_fail_odd = !GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg);
            }
            else
            {
                l_tl_fail_odd = !GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg);
            }
        }

        l_tl_trained = !l_tl_fail_evn && !l_tl_fail_odd;

        // if nothing is left to run on, emit RC with callout/deconfig on IOHS endpoints (no retraining for this bus)
        FAPI_ASSERT(l_tl_trained,
                    fapi2::P10_FAB_IOVALID_TL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_IOLINK_TARGET(l_tl_fail_evn ? l_loc_evn_iolink_target : l_loc_odd_iolink_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_IOLINK_EVN_FAIL(l_tl_fail_evn)
                    .set_LOC_IOLINK_ODD_FAIL(l_tl_fail_odd)
                    .set_REM_IOLINK_TARGET(l_tl_fail_evn ? l_rem_evn_iolink_target : l_rem_odd_iolink_target),
                    "Half-width link TL training did not complete successfully, no retry possible!");

    }

fapi_try_exit:

    if ((fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
        (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR) ||
        (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR))
    {
        p10_fabric_iovalid_append_dl_ffdc(i_loc_endp_target, fapi2::current_err);
        p10_fabric_iovalid_append_dl_ffdc(l_rem_evn_endp_target, fapi2::current_err);
        p10_fabric_iovalid_append_dl_ffdc(l_rem_odd_endp_target, fapi2::current_err);
    }
    else if ((fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
             (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR) ||
             (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR))
    {
        p10_fabric_iovalid_append_tl_ffdc(l_loc_pauc_target, fapi2::current_err);
        p10_fabric_iovalid_append_tl_ffdc(l_rem_evn_pauc_target, fapi2::current_err);
        p10_fabric_iovalid_append_tl_ffdc(l_rem_odd_pauc_target, fapi2::current_err);
    }

    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Validate DL/TL link layers are trained
///
/// @param[in] i_iohs_target        Reference to IOHS target
/// @param[in] i_update_internode   True if IOHS link is used as internode connection
/// @param[out] o_retrain           Indication that DL/TL link training should be re-attempted
/// @param[out] o_rcs               Vector of return code objects, to append
///                                 in case of reported DL/TL training failures
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_link_validate_wrap(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const bool i_update_internode,
    bool& o_retrain,
    std::vector<fapi2::ReturnCode>& o_rcs)
{
    fapi2::ReturnCode l_rc;
    l_rc = p10_fabric_iovalid_link_validate(i_iohs_target);

    if (((l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_HALF_NOT_TRAINED_RETRAIN_NONE_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_FULL_NOT_TRAINED_RETRAIN_HALF_ERR))
        && i_update_internode)
    {
        o_retrain = true;
        o_rcs.push_back(l_rc);
        return fapi2::FAPI2_RC_SUCCESS;
    }
    else
    {
        o_retrain = false;

        if (l_rc != fapi2::FAPI2_RC_SUCCESS)
        {
            FAPI_ERR("Error from p10_fabric_iovalid_link_validate_wrap");
        }

        return l_rc;
    }
}

///
/// @brief Compute link delay for a single end of a given sublink
///
/// @param[in]  i_iolink_target   Reference to IOHS sublink target
/// @param[out] o_link_delay      Measured delay
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_get_link_delay(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_target,
    uint32_t& o_link_delay)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    auto l_iohs_target = i_target.getParent<fapi2::TARGET_TYPE_IOHS>();
    auto l_pauc_target = l_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    uint64_t l_sublink_delay = 0;
    fapi2::buffer<uint64_t> l_link_delay_reg;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_pos;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
    fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iolink_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, iolink)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_iohs_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, iohs)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, l_iohs_target, l_link_split),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs_target, l_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

    FAPI_TRY(GET_PB_TL_LINK_DLY_0123_REG(l_pauc_target, l_link_delay_reg),
             "Error from getScom (PB_TL_LINK_DLY_0123_REG)");

    // X0
    if (((l_iolink_pos % 2) == 0) && (((l_iohs_pos % 2) == 0) || (l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_TRUE)))
    {
        GET_PB_TL_LINK_DLY_0123_REG_X0_LINK_DELAY(l_link_delay_reg, l_sublink_delay);
    }

    // X1
    if (((l_iolink_pos % 2) == 1) && ((l_iohs_pos % 2) == 0))
    {
        GET_PB_TL_LINK_DLY_0123_REG_X1_LINK_DELAY(l_link_delay_reg, l_sublink_delay);
    }

    // Y0
    if (((l_iolink_pos % 2) == 0) && ((l_iohs_pos % 2) == 1))
    {
        GET_PB_TL_LINK_DLY_0123_REG_Y0_LINK_DELAY(l_link_delay_reg, l_sublink_delay);
    }

    // Y1
    if (((l_iolink_pos % 2) == 1) && ((l_iohs_pos % 2) == 1))
    {
        GET_PB_TL_LINK_DLY_0123_REG_Y1_LINK_DELAY(l_link_delay_reg, l_sublink_delay);
    }

    o_link_delay = l_sublink_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Compute roundtrip training delay reported by both endpoints of a given link
///
/// @param[in]  i_loc_endp_target   Reference to IOHS target for local endpoint
/// @param[out] o_agg_link_delay    Sum of local and remote end link delays
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_get_link_delays(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_loc_endp_target,
    uint32_t o_agg_link_delay[])
{
    FAPI_DBG("Start");

    std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>> l_loc_iolink_targets;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
    fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
    std::vector<uint8_t> l_loc_link_ids;

    // determine which logical links need to have their delay values updated based
    // on the IOHS endpoint target (up to two logical links depending on configuration)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_loc_endp_target, l_iohs_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, iohs)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, i_loc_endp_target, l_link_split),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_SPLIT)");

    for (auto l_iolink_target : i_loc_endp_target.getChildren<fapi2::TARGET_TYPE_IOLINK>())
    {
        fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_pos;
        uint8_t l_loc_link_id = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iolink_target, l_iolink_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, iolink)");

        if ((l_iolink_pos % 2) == 0)
        {
            if (((l_iohs_pos % 2) == 1) && (l_link_split == fapi2::ENUM_ATTR_IOHS_LINK_SPLIT_TRUE))
            {
                l_loc_link_id = l_iohs_pos - 1;
            }
            else
            {
                l_loc_link_id = l_iohs_pos;
            }
        }
        else
        {
            l_loc_link_id = l_iohs_pos;
        }

        // handle Cronus platform implementation of IOLINK targets -- both
        // children are always returned as functional, even if no valid remote endpoint
        // connection exists
        if (fapi2::is_platform<fapi2::PLAT_CRONUS>())
        {
            fapi2::ReturnCode l_rc;
            fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;
            l_rc = l_iolink_target.getOtherEnd(l_rem_iolink_target);

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                continue;
            }
        }

        l_loc_iolink_targets.push_back(l_iolink_target);
        l_loc_link_ids.push_back(l_loc_link_id);
    }

    for (uint8_t ii = 0; ii < l_loc_iolink_targets.size(); ii++)
    {
        uint32_t l_loc_link_delay = 0;
        uint32_t l_rem_link_delay = 0;
        fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink;

        // read link delay from local iolink target
        FAPI_TRY(p10_fabric_iovalid_get_link_delay(l_loc_iolink_targets[ii],
                 l_loc_link_delay),
                 "Error from p10_fabric_iovalid_get_link_delay (local)");

        FAPI_TRY(p10_fabric_iovalid_get_rem_endp(l_loc_iolink_targets[ii],
                 l_rem_iolink),
                 "Error from p10_fabric_iovalid_get_rem_endp");

        // read link delay from remote iolink target
        FAPI_TRY(p10_fabric_iovalid_get_link_delay(l_rem_iolink,
                 l_rem_link_delay),
                 "Error from p10_fabric_iovalid_get_link_delay (remote)");

        // aggregate link delay attribute is normalized to single sublink pair (local/remote)
        // divide by two if updating same logical link twice
        o_agg_link_delay[l_loc_link_ids[ii]] += (l_loc_link_delay + l_rem_link_delay);

        if ((ii == 1) &&
            (l_loc_link_ids[0] == l_loc_link_ids[1]))
        {
            o_agg_link_delay[l_loc_link_ids[ii]] /= 2;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Force psav on bad lanes
///
/// @param[in] i_target         Reference to IOHS target to configure
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_psav_bad_lanes(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::pauc;
    using namespace scomt::iohs;

    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_Type l_bad_valid;
    fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_Type l_bad_vec;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC_VALID, i_iohs_target, l_bad_valid),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_MFG_BAD_LANE_VEC_VALID)");

    if (l_bad_valid == fapi2::ENUM_ATTR_IOHS_MFG_BAD_LANE_VEC_VALID_TRUE)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_MFG_BAD_LANE_VEC, i_iohs_target, l_bad_vec),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_MFG_BAD_LANE_VEC)");

        if (l_bad_vec != 0)
        {
            fapi2::buffer<uint64_t> l_data;

            FAPI_TRY(GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG(i_iohs_target, l_data));

            l_data.insert(l_bad_vec,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN,
                          0);

            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG(i_iohs_target, l_data));


            FAPI_TRY(GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG(i_iohs_target, l_data));

            l_data.insert(l_bad_vec,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG_RX_PSAVE_FORCE_REQ_16_23_1_LEN,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNT32_PG_RX_PSAVE_FORCE_REQ_0_15_1_LEN);

            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNT33_PG(i_iohs_target, l_data));


            FAPI_TRY(GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG(i_iohs_target, l_data));

            l_data.insert(l_bad_vec,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN,
                          0);

            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG(i_iohs_target, l_data));

            FAPI_TRY(GET_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(i_iohs_target, l_data));

            l_data.insert(l_bad_vec,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG_RX_PSAVE_FENCE_REQ_DL_IO_16_23_LEN,
                          IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL5_PG_RX_PSAVE_FENCE_REQ_DL_IO_0_15_LEN);

            FAPI_TRY(PUT_IOO_RX0_RXCTL_DATASM_REGS_RX_CNTL6_PG(i_iohs_target, l_data));
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Update iovalid settings for fabric links (A/X) associated with
///        provided IOHS target
///
/// @param[in] i_target         Reference to IOHS target to configure
/// @param[in] i_set_not_clear  Define iovalid operation (true=set, false=clear)
/// @param[in] i_link_train     Defines sublinks to enable
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_update_link(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool i_set_not_clear,
    const fapi2::ATTR_IOHS_LINK_TRAIN_Type i_link_train)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_iovalid_mask;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_unit;
    fapi2::ATTR_IOHS_LINK_SPLIT_Type l_link_split;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_iohs_unit));
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_SPLIT, i_target, l_link_split));

    if (i_set_not_clear)
    {
        FAPI_TRY(PREP_CPLT_CONF1_WO_OR(l_pauc_target));
    }
    else
    {
        FAPI_TRY(PREP_CPLT_CONF1_WO_CLEAR(l_pauc_target));
    }

    if (i_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
    {
        if (l_link_split)
        {
            SET_CPLT_CONF1_1_IOVALID_DC(l_iovalid_mask);
            SET_CPLT_CONF1_2_IOVALID_DC(l_iovalid_mask);
        }
        else if ((l_iohs_unit % 2) == 0)
        {
            SET_CPLT_CONF1_1_IOVALID_DC(l_iovalid_mask);
            SET_CPLT_CONF1_0_IOVALID_DC(l_iovalid_mask);
        }
        else
        {
            SET_CPLT_CONF1_3_IOVALID_DC(l_iovalid_mask);
            SET_CPLT_CONF1_2_IOVALID_DC(l_iovalid_mask);
        }
    }
    else if (i_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
    {
        if (l_link_split)
        {
            SET_CPLT_CONF1_1_IOVALID_DC(l_iovalid_mask);
        }
        else if ((l_iohs_unit % 2) == 0)
        {
            SET_CPLT_CONF1_1_IOVALID_DC(l_iovalid_mask);
        }
        else
        {
            SET_CPLT_CONF1_3_IOVALID_DC(l_iovalid_mask);
        }
    }
    else if (i_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY)
    {
        if ((l_iohs_unit % 2) == 0)
        {
            SET_CPLT_CONF1_0_IOVALID_DC(l_iovalid_mask);
        }
        else
        {
            SET_CPLT_CONF1_2_IOVALID_DC(l_iovalid_mask);
        }
    }

    if (i_set_not_clear)
    {
        FAPI_TRY(PUT_CPLT_CONF1_WO_OR(l_pauc_target, l_iovalid_mask),
                 "Error setting iovalid bits (CPLT_CONF1_WO_OR)");
    }
    else
    {
        FAPI_TRY(PUT_CPLT_CONF1_WO_CLEAR(l_pauc_target, l_iovalid_mask),
                 "Error clearing iovalid bits (CPLT_CONF1_WO_CLEAR)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_fabric_iovalid(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_set_not_clear,
    const bool i_update_intranode,
    const bool i_update_internode,
    std::vector<fapi2::ReturnCode>& o_dltl_fail_rcs)
{
    FAPI_DBG("Start");

    fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_Type l_x_en;
    fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_Type l_a_en;
    fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY_Type l_x_agg_link_delay;
    fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY_Type l_a_agg_link_delay;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

    for (const auto l_iohs : i_target.getChildren<fapi2::TARGET_TYPE_IOHS>())
    {
        fapi2::ATTR_IOHS_LINK_TRAIN_Type l_link_train;
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_config_mode;
        fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;
        fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE_Type l_fabric_link_active;
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(l_iohs, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_iohs, l_link_train),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_iohs, l_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs, l_drawer_interconnect),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_LINK_ACTIVE, l_iohs, l_fabric_link_active),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_LINK_ACTIVE)");

        if ((l_link_train != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE) &&
            (l_fabric_link_active == fapi2::ENUM_ATTR_PROC_FABRIC_LINK_ACTIVE_TRUE) &&
            ((i_update_intranode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE)) ||
             (i_update_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE))))
        {
            FAPI_DBG("Updating iovalid for link %s", l_targetStr);

            bool l_link_needs_retraining = false;

            if (i_set_not_clear)
            {
                FAPI_DBG("Validating link state prior to iovalid update");
                FAPI_TRY(p10_fabric_iovalid_link_validate_wrap(
                             l_iohs,
                             i_update_internode,
                             l_link_needs_retraining,
                             o_dltl_fail_rcs),
                         "Error from p10_fabric_iovalid_link_validate_wrap");
            }

            if (l_link_needs_retraining)
            {
                continue;
            }

            FAPI_DBG("Configuring iovalid state (%s)", i_set_not_clear ? ("set") : ("clear"));
            FAPI_TRY(p10_fabric_iovalid_update_link(
                         l_iohs,
                         i_set_not_clear,
                         l_link_train),
                     "Error from p10_fabric_iovalid_update_link");

            if (i_set_not_clear)
            {
                FAPI_DBG("Collecting link delay counter values");
                FAPI_TRY(p10_fabric_iovalid_get_link_delays(
                             l_iohs,
                             (l_config_mode == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX) ?
                             (l_x_agg_link_delay) :
                             (l_a_agg_link_delay)),
                         "Error from p10_fabric_iovalid_get_link_delays");

                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

                FAPI_TRY(p10_psav_bad_lanes(l_iohs));
            }
        }
        else
        {
            FAPI_DBG("Skipping iovalid update for %s", l_targetStr);
            FAPI_DBG("  l_link_train:           %d", l_link_train);
            FAPI_DBG("  l_fabric_link_active:   %d", l_fabric_link_active);
            FAPI_DBG("  i_update_intranode:     %d", i_update_intranode);
            FAPI_DBG("  i_update_internode:     %d", i_update_internode);
            FAPI_DBG("  l_drawer_interconnect:  %d", l_drawer_interconnect);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
