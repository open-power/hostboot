/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fabric_iovalid.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
const uint32_t DL_POLL_HW_DELAY_NS = 10000000;

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
    l_scom_addr = PB_PTLSCOM45_PR0123_ERR;
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
/// @param[in] i_loc_endp_target    Reference to IOHS target for local endpoint
/// @param[out] o_rem_endp_target   Reference to IOHS target for remote endpoint
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_get_rem_endp(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_loc_endp_target,
    fapi2::Target<fapi2::TARGET_TYPE_IOHS>& o_rem_endp_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_endp_target;
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
    uint64_t l_lane_failed_count     = DL_NUM_LANES_PER_HALF_LINK;
    uint64_t l_lane_not_locked_count = DL_NUM_LANES_PER_HALF_LINK;
    o_bus_failed = false;

    FAPI_DBG("Checking for fail on %s lanes", ((i_even_not_odd) ? ("even") : ("odd")));

    if(i_even_not_odd)
    {
        FAPI_TRY(GET_DLP_LINK0_RX_LANE_CONTROL(i_iohs_target, l_dl_rx_control),
                 "Error from getScom (DLP_LINK0_RX_LANE_CONTROL)");

        // extract first 8 lanes, last lane is spare
        GET_DLP_LINK0_RX_LANE_CONTROL_FAILED(l_dl_rx_control, l_lane_failed);
        l_lane_failed = l_lane_failed >> 1;

        l_dl_rx_control.invert();
        GET_DLP_LINK0_RX_LANE_CONTROL_LOCKED(l_dl_rx_control, l_lane_not_locked);
    }
    else
    {
        FAPI_TRY(GET_DLP_LINK1_RX_LANE_CONTROL(i_iohs_target, l_dl_rx_control),
                 "Error from getScom (DLP_LINK1_RX_LANE_CONTROL)");

        // extract first 8 lanes, last lane is spare
        GET_DLP_LINK1_RX_LANE_CONTROL_FAILED(l_dl_rx_control, l_lane_failed);
        l_lane_failed = l_lane_failed >> 1;

        l_dl_rx_control.invert();
        GET_DLP_LINK1_RX_LANE_CONTROL_LOCKED(l_dl_rx_control, l_lane_not_locked);
    }

    p10_fabric_iovalid_count_ones(l_lane_failed, l_lane_failed_count);
    p10_fabric_iovalid_count_ones(l_lane_not_locked, l_lane_not_locked_count);

    if ((l_lane_failed_count == 0) && (l_lane_not_locked_count == 0))
    {
        goto fapi_try_exit;
    }
    else
    {
        FAPI_DBG("Non-zero lane error count: lanes failed = %d, lanes not locked = %d",
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
/// @param[in] i_link_id            Link ID for given IOHS target
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_link_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_loc_endp_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type& i_link_id)
{
    using namespace scomt::pauc;
    using namespace scomt::iohs;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_dl_fir_reg;
    fapi2::buffer<uint64_t> l_dl_status_reg;
    fapi2::buffer<uint64_t> l_dl_rx_control;
    fapi2::buffer<uint64_t> l_tl_fir_reg;
    uint64_t l_dl_timeout_state_evn = 0;
    uint64_t l_dl_timeout_state_odd = 0;
    bool l_dl_trained = false;
    bool l_dl_fail_evn = false;
    bool l_dl_fail_odd = false;
    bool l_tl_trained = false;

    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_loc_link_train;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_loc_link_train_next;
    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_loc_pauc_target;
    fapi2::Target<fapi2::TARGET_TYPE_PAUC> l_rem_pauc_target;
    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_endp_target;

    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_loc_endp_target, l_targetStr, sizeof(l_targetStr));

    // obtain link endpoints for FFDC
    FAPI_TRY(p10_fabric_iovalid_get_rem_endp(i_loc_endp_target, l_rem_endp_target),
             "Error from p10_fabric_iovalid_get_rem_endp");

    // determine associated pauc target for local/remote links
    l_loc_pauc_target = i_loc_endp_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    l_rem_pauc_target = l_rem_endp_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    // determine which sublinks are trained
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_loc_endp_target, l_loc_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN)");

    // validate DL training state; poll for training completion
    for(uint32_t l_poll_loops = DL_MAX_POLL_LOOPS; l_poll_loops > 0 && !l_dl_trained; l_poll_loops--)
    {
        FAPI_TRY(GET_DLP_DLL_STATUS(i_loc_endp_target, l_dl_status_reg),
                 "Error from getScom (DLP_DLL_STATUS)");

        GET_DLP_DLL_STATUS_0_TIMEOUT_STATE(l_dl_status_reg, l_dl_timeout_state_evn);
        GET_DLP_DLL_STATUS_1_TIMEOUT_STATE(l_dl_status_reg, l_dl_timeout_state_odd);

        FAPI_TRY(GET_DLP_FIR_REG_RW(i_loc_endp_target, l_dl_fir_reg),
                 "Error from getScom (DLP_FIR_REG_RW)");

        if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
        {
            l_dl_trained = GET_DLP_FIR_REG_0_TRAINED(l_dl_fir_reg) &&
                           GET_DLP_FIR_REG_1_TRAINED(l_dl_fir_reg);

            if (!l_dl_trained)
            {
                l_dl_fail_evn = !(l_dl_timeout_state_evn == DL_STATE_LAT_MEASURE);
                l_dl_fail_odd = !(l_dl_timeout_state_odd == DL_STATE_LAT_MEASURE);

                FAPI_DBG("evn fail: %d, timeout_state: 0x%X / odd fail: %d, timeout_state: 0x%X",
                         l_dl_fail_evn ? (1) : (0), l_dl_timeout_state_evn,
                         l_dl_fail_odd ? (1) : (0), l_dl_timeout_state_odd);
            }
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
        FAPI_DBG("Checking for DL lane failures");

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
        FAPI_DBG("Skipping check for DL lane failures");
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

            FAPI_DBG("Retraining is possible with half-link configuration");
        }
        // otherwise, no retraining will be attempted:
        // - tried to train only half-width, and was not successful
        // - tried to train full-width, and both links failed
        else
        {
            l_loc_link_train_next = fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE;
            FAPI_DBG("Retraining not possible and will not be attempted");
        }

        FAPI_DBG("Reconfiguring ATTR_IOHS_LINK_TRAIN from 0x%X -> 0x%X for %s",
                 l_loc_link_train, l_loc_link_train_next, l_targetStr);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_LINK_TRAIN, i_loc_endp_target, l_loc_link_train_next),
                 "Error from FAPI_ATTR_SET (ATTR_IOHS_LINK_TRAIN)");

        // if nothing is left to run on, emit RC with callout/deconfig on endpoints (no retraining for this bus)
        FAPI_ASSERT(l_loc_link_train_next != fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_NONE,
                    fapi2::P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_LINK_FAILED0(l_dl_fail_evn)
                    .set_LOC_LINK_FAILED1(l_dl_fail_odd)
                    .set_REM_ENDP_TARGET(l_rem_endp_target),
                    "Link DL training did not complete successfully!");

        // else, emit RC with no deconfig (and attempt retraining on half link)
        FAPI_ASSERT(false,
                    fapi2::P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR()
                    .set_LOC_ENDP_TARGET(i_loc_endp_target)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_LINK_FAILED0(l_dl_fail_evn)
                    .set_LOC_LINK_FAILED1(l_dl_fail_odd)
                    .set_REM_ENDP_TARGET(l_rem_endp_target),
                    "Link DL training did not complete successfully!");
    }

    // validate TL training state
    FAPI_DBG("Validating TL training state...");

    FAPI_TRY(GET_PB_PTL_FIR_REG_RW(l_loc_pauc_target, l_tl_fir_reg),
             "Error from getScom (PB_PTLSCOM10_PTL_FIR_REG_RW)");

    if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH)
    {
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg) && GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));
    }
    else if (l_loc_link_train == fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY)
    {
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR02_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR00_TRAINED(l_tl_fir_reg));
    }
    else
    {
        l_tl_trained  = (i_link_id % 2) ?
                        (GET_PB_PTL_FIR_REG_FMR03_TRAINED(l_tl_fir_reg)) :
                        (GET_PB_PTL_FIR_REG_FMR01_TRAINED(l_tl_fir_reg));
    }

    FAPI_ASSERT(l_tl_trained,
                fapi2::P10_FAB_IOVALID_TL_NOT_TRAINED_ERR()
                .set_LOC_ENDP_TARGET(i_loc_endp_target)
                .set_LOC_LINK_TRAIN(l_loc_link_train)
                .set_REM_ENDP_TARGET(l_rem_endp_target),
                "Error in TL training for %s (ATTR_IOHS_LINK_TRAIN: 0x%X)",
                l_targetStr, l_loc_link_train);

fapi_try_exit:

    if ((fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
        (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR))
    {
        p10_fabric_iovalid_append_dl_ffdc(i_loc_endp_target, fapi2::current_err);
        p10_fabric_iovalid_append_dl_ffdc(l_rem_endp_target, fapi2::current_err);
    }
    else if (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_TL_NOT_TRAINED_ERR)
    {
        p10_fabric_iovalid_append_tl_ffdc(l_loc_pauc_target, fapi2::current_err);
        p10_fabric_iovalid_append_tl_ffdc(l_rem_pauc_target, fapi2::current_err);
    }

    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Validate DL/TL link layers are trained
///
/// @param[in] i_iohs_target        Reference to IOHS target
/// @param[in] i_link_id            Link ID for given IOHS target
/// @param[in] i_update_internode   True if IOHS link is used as internode connection
/// @param[out] o_retrain           Indication that DL link training should be re-attempted
/// @param[out] o_rcs               Vector of return code objects, to append
///                                 in case of reported DL training failure
///
/// @return fapi2::ReturnCode       FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_link_validate_wrap(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type& i_link_id,
    const bool i_update_internode,
    bool& o_retrain,
    std::vector<fapi2::ReturnCode>& o_rcs)
{
    fapi2::ReturnCode l_rc;
    l_rc = p10_fabric_iovalid_link_validate(i_iohs_target, i_link_id);

    if (((l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
         (l_rc == (fapi2::ReturnCode) fapi2::RC_P10_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR))
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
/// @brief Compute link delay for a single endpoint of a given link
///
/// @param[in]  i_iohs_target   Reference to IOHS target
/// @param[in]  i_link_train    Sublinks to monitor
/// @param[out] o_link_delay    Average link delay across sublinks if monitoring
///                             both, else delay value for individual sublink
///
/// @return fapi2::ReturnCode   FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_get_link_delay(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const fapi2::ATTR_IOHS_LINK_TRAIN_Type i_link_train,
    uint32_t o_link_delay)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    auto l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    fapi2::buffer<uint64_t> l_link_delay_reg;
    uint64_t l_sublink_delay_evn;
    uint64_t l_sublink_delay_odd;
    bool l_is_even_iohs;

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    l_is_even_iohs = ((l_iohs_pos % 2) == 0);

    FAPI_TRY(GET_PB_TL_LINK_DLY_0123_REG(l_pauc_target, l_link_delay_reg),
             "Error from getScom (PB_TL_LINK_DLY_0123_REG)");

    if(l_is_even_iohs)
    {
        GET_PB_TL_LINK_DLY_0123_REG_X0_LINK_DELAY(l_link_delay_reg, l_sublink_delay_evn);
        GET_PB_TL_LINK_DLY_0123_REG_X1_LINK_DELAY(l_link_delay_reg, l_sublink_delay_odd);
    }
    else
    {
        GET_PB_TL_LINK_DLY_0123_REG_Y0_LINK_DELAY(l_link_delay_reg, l_sublink_delay_evn);
        GET_PB_TL_LINK_DLY_0123_REG_Y1_LINK_DELAY(l_link_delay_reg, l_sublink_delay_odd);
    }

    switch(i_link_train)
    {
        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_BOTH:
            o_link_delay = (l_sublink_delay_evn + l_sublink_delay_odd) / 2;;
            break;

        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_EVEN_ONLY:
            o_link_delay = l_sublink_delay_evn;
            break;

        case fapi2::ENUM_ATTR_IOHS_LINK_TRAIN_ODD_ONLY:
            o_link_delay = l_sublink_delay_odd;
            break;

        default:
            o_link_delay = 0xFFFFFFFF;
            break;
    }

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
    uint32_t o_agg_link_delay)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_IOHS> l_rem_endp_target;

    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_loc_link_train;
    fapi2::ATTR_IOHS_LINK_TRAIN_Type l_rem_link_train;
    uint32_t l_loc_link_delay = 0xFFF;
    uint32_t l_rem_link_delay = 0xFFF;

    // get remote link endpoint target
    FAPI_TRY(p10_fabric_iovalid_get_rem_endp(i_loc_endp_target, l_rem_endp_target),
             "Error from p10_fabric_iovalid_get_rem_endp");

    // get valid sublinks for local/remote targets
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, i_loc_endp_target, l_loc_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN, local)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_LINK_TRAIN, l_rem_endp_target, l_rem_link_train),
             "Error from FAPI_ATTR_GET (ATTR_IOHS_LINK_TRAIN, remote)");

    // read link delay from local endpoint target
    FAPI_TRY(p10_fabric_iovalid_get_link_delay(
                 i_loc_endp_target,
                 l_loc_link_train,
                 l_loc_link_delay),
             "Error from p10_fabric_iovalid_get_link_delay (local)");

    // read link delay from remote endpoint target
    FAPI_TRY(p10_fabric_iovalid_get_link_delay(
                 l_rem_endp_target,
                 l_rem_link_train,
                 l_rem_link_delay),
             "Error from p10_fabric_iovalid_get_link_delay (remote)");

    o_agg_link_delay = l_loc_link_delay + l_rem_link_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Update iovalid settings for a single fabric link (X/A)
///
/// @param[in] i_target         Reference to IOHS target to configure
/// @param[in] i_link_id        Chiplet number for given IOHS target
/// @param[in] i_set_not_clear  Define iovalid operation (true=set, false=clear)
/// @param[in] i_en             Defines sublinks to enable
///
/// @return fapi::ReturnCode    FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p10_fabric_iovalid_update_link(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type i_link_id,
    const bool i_set_not_clear,
    const uint8_t i_en)
{
    using namespace scomt::pauc;

    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_iovalid_mask;

    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    if(i_set_not_clear)
    {
        FAPI_TRY(PREP_CPLT_CONF1_WO_OR(l_pauc_target));
    }
    else
    {
        FAPI_TRY(PREP_CPLT_CONF1_WO_CLEAR(l_pauc_target));
    }

    if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
        (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY))
    {
        if(i_link_id % 2)
        {
            SET_CPLT_CONF1_3_IOVALID_DC(l_iovalid_mask);
        }
        else
        {
            SET_CPLT_CONF1_1_IOVALID_DC(l_iovalid_mask);
        }
    }

    if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
        (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY))
    {
        if(i_link_id % 2)
        {
            SET_CPLT_CONF1_2_IOVALID_DC(l_iovalid_mask);
        }
        else
        {
            SET_CPLT_CONF1_0_IOVALID_DC(l_iovalid_mask);
        }
    }

    if(i_set_not_clear)
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
    std::vector<fapi2::ReturnCode>& o_dl_fail_rcs)
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
        fapi2::ATTR_CHIP_UNIT_POS_Type l_link;
        fapi2::ATTR_IOHS_DRAWER_INTERCONNECT_Type l_drawer_interconnect;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs, l_link),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_DRAWER_INTERCONNECT, l_iohs, l_drawer_interconnect),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_DRAWER_INTERCONNECT)");

        if ((l_x_en[l_link] && i_update_intranode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_FALSE))
            || (l_x_en[l_link] && i_update_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE))
            || (l_a_en[l_link] && i_update_internode && (l_drawer_interconnect == fapi2::ENUM_ATTR_IOHS_DRAWER_INTERCONNECT_TRUE)))
        {
            FAPI_DBG("Updating iovalid for link %d (%s)", l_link, l_x_en[l_link] ? ("SMPX") : ("SMPA"));

            bool l_link_needs_retraining = false;

            if (i_set_not_clear)
            {
                FAPI_DBG("Validating link state prior to iovalid update");
                FAPI_TRY(p10_fabric_iovalid_link_validate_wrap(
                             l_iohs,
                             l_link,
                             i_update_internode,
                             l_link_needs_retraining,
                             o_dl_fail_rcs),
                         "Error from p10_fabric_iovalid_link_validate_wrap");
            }

            if (l_link_needs_retraining)
            {
                continue;
            }

            FAPI_DBG("Configuring iovalid state (%s)", i_set_not_clear ? ("set") : ("clear"));
            FAPI_TRY(p10_fabric_iovalid_update_link(
                         l_iohs,
                         l_link,
                         i_set_not_clear,
                         l_x_en[l_link] ? (l_x_en[l_link]) : (l_a_en[l_link])),
                     "Error from p10_fabric_iovalid_update_link");

            if (i_set_not_clear)
            {
                FAPI_DBG("Collecting link delay counter values");
                FAPI_TRY(p10_fabric_iovalid_get_link_delays(
                             l_iohs,
                             l_x_en[l_link] ? (l_x_agg_link_delay[l_link]) : (l_a_agg_link_delay[l_link])),
                         "Error from p10_fabric_iovalid_get_link_delays");

                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
                         "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");
            }
        }
        else
        {
            char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
            fapi2::toString(l_iohs, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

            FAPI_DBG("Skipping iovalid update for %s", l_targetStr);
            FAPI_DBG("  i_update_intranode:     %d", i_update_intranode);
            FAPI_DBG("  i_update_internode:     %d", i_update_internode);
            FAPI_DBG("  l_drawer_interconnect:  %d", l_drawer_interconnect);
            FAPI_DBG("  x_enable:               %d", l_x_en[l_link]);
            FAPI_DBG("  a_enable:               %d", l_a_en[l_link]);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
