/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fab_iovalid.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_fab_iovalid.C
/// @brief Manage fabric link iovalid controls (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fab_iovalid.H>
#include <p9_fbc_smp_utils.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
// EXTFIR/RAS FIR field constants
const uint8_t IOVALID_FIELD_NUM_BITS = 2;

// DL FIR register field constants
const uint8_t DL_FIR_LINK0_TRAINED_BIT = 0;
const uint8_t DL_FIR_LINK1_TRAINED_BIT = 1;

// DL register FFDC address offset constants
const uint64_t DL_CONFIG_REG_OFFSET = 0x0A;
const uint64_t DL_CONTROL_REG_OFFSET = 0x0B;
const uint64_t DL_CONFIG_PHY_REG_OFFSET = 0x0C;        // Optical only
const uint64_t DL_SECONDARY_CONFIG_REG_OFFSET = 0x0D;
const uint64_t DL_LATENCY_REG_OFFSET = 0x0E;
const uint64_t DL_OPTICAL_CONFIG_REG_OFFSET = 0x0F;    // Optical only
const uint64_t DL_TX0_LANE_CONTROL_REG_OFFSET = 0x10;  // Optical only
const uint64_t DL_TX1_LANE_CONTROL_REG_OFFSET = 0x11;  // Optical only
const uint64_t DL_RX0_LANE_CONTROL_REG_OFFSET = 0x12;  // Optical only
const uint64_t DL_RX1_LANE_CONTROL_REG_OFFSET = 0x13;  // Optical only
const uint64_t DL_ERR0_STATUS_REG_OFFSET = 0x16;
const uint64_t DL_ERR1_STATUS_REG_OFFSET = 0x17;
const uint64_t DL_STATUS_REG_OFFSET = 0x28;
const uint64_t DL_ERR_MISC_REG_OFFSET = 0x29;          // Optical only

// TL FIR register field constants
const uint8_t TL_FIR_TRAINED_FIELD_LENGTH = 2;
const uint8_t TL_FIR_TRAINED_LINK_TRAINED = 0x3;

// TL Link Delay register field constants
const uint8_t TL_LINK_DELAY_FIELD_NUM_BITS = 12;

// TL register FFDC address offset constants
const uint64_t TL_CONFIG01_REG_OFFSET = 0x0A;
const uint64_t TL_CONFIG23_REG_OFFSET = 0x0B;
const uint64_t TL_CONFIG45_REG_OFFSET = 0x0C;
const uint64_t TL_CONFIG67_REG_OFFSET = 0x0D;          // Optical only
const uint64_t TL_MISC_CONFIG_REG_OFFSET = 0x23;
const uint64_t TL_FRAMER0123_ERR_REG_OFFSET = 0x25;
const uint64_t TL_FRAMER4567_ERR_REG_OFFSET = 0x26;
const uint64_t TL_PARSER0123_ERR_REG_OFFSET = 0x27;
const uint64_t TL_PARSER4567_ERR_REG_OFFSET = 0x28;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Append DL layer specific FFDC in the event of a training failure
///
/// @tparam T template parameter, defines endpoint type
/// @param[in]    i_chip_target  Processor chip target
/// @param[in]    i_link_ctl     X/A link control structure for link
/// @param[inout] o_rc           Return code object to be appended
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
void
p9_fab_iovalid_append_dl_ffdc(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip_target,
    const p9_fbc_link_ctl_t& i_link_ctl,
    fapi2::ReturnCode& o_rc)
{
    uint64_t l_base_scom_addr = i_link_ctl.dl_fir_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    uint64_t l_fir_reg;
    fapi2::ffdc_t FIR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr, l_scom_data);
    l_fir_reg = l_scom_data();
    FIR_REG.ptr() = static_cast<void*>(&l_fir_reg);
    FIR_REG.size() = sizeof(l_fir_reg);

    uint64_t l_config_reg;
    fapi2::ffdc_t CONFIG_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_CONFIG_REG_OFFSET, l_scom_data);
    l_config_reg = l_scom_data();
    CONFIG_REG.ptr() = static_cast<void*>(&l_config_reg);
    CONFIG_REG.size() = sizeof(l_config_reg);

    uint64_t l_control_reg;
    fapi2::ffdc_t CONTROL_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_CONTROL_REG_OFFSET, l_scom_data);
    l_control_reg = l_scom_data();
    CONTROL_REG.ptr() = static_cast<void*>(&l_control_reg);
    CONTROL_REG.size() = sizeof(l_control_reg);

    uint64_t l_config_phy_reg;
    fapi2::ffdc_t CONFIG_PHY_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_CONFIG_PHY_REG_OFFSET, l_scom_data);
    }

    l_config_phy_reg = l_scom_data();
    CONFIG_PHY_REG.ptr() = static_cast<void*>(&l_config_phy_reg);
    CONFIG_PHY_REG.size() = sizeof(l_config_phy_reg);

    uint64_t l_secondary_config_reg;
    fapi2::ffdc_t SECONDARY_CONFIG_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_SECONDARY_CONFIG_REG_OFFSET, l_scom_data);
    l_secondary_config_reg = l_scom_data();
    SECONDARY_CONFIG_REG.ptr() = static_cast<void*>(&l_secondary_config_reg);
    SECONDARY_CONFIG_REG.size() = sizeof(l_secondary_config_reg);

    uint64_t l_latency_reg;
    fapi2::ffdc_t LATENCY_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_LATENCY_REG_OFFSET, l_scom_data);
    l_latency_reg = l_scom_data();
    LATENCY_REG.ptr() = static_cast<void*>(&l_latency_reg);
    LATENCY_REG.size() = sizeof(l_latency_reg);

    uint64_t l_optical_config_reg;
    fapi2::ffdc_t OPTICAL_CONFIG_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_OPTICAL_CONFIG_REG_OFFSET, l_scom_data);
    }

    l_optical_config_reg = l_scom_data();
    OPTICAL_CONFIG_REG.ptr() = static_cast<void*>(&l_optical_config_reg);
    OPTICAL_CONFIG_REG.size() = sizeof(l_optical_config_reg);

    uint64_t l_tx0_lane_control_reg;
    fapi2::ffdc_t TX0_LANE_CONTROL_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_TX0_LANE_CONTROL_REG_OFFSET, l_scom_data);
    }

    l_tx0_lane_control_reg = l_scom_data();
    TX0_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_tx0_lane_control_reg);
    TX0_LANE_CONTROL_REG.size() = sizeof(l_tx0_lane_control_reg);

    uint64_t l_tx1_lane_control_reg;
    fapi2::ffdc_t TX1_LANE_CONTROL_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_TX1_LANE_CONTROL_REG_OFFSET, l_scom_data);
    }

    l_tx1_lane_control_reg = l_scom_data();
    TX1_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_tx1_lane_control_reg);
    TX1_LANE_CONTROL_REG.size() = sizeof(l_tx1_lane_control_reg);

    uint64_t l_rx0_lane_control_reg;
    fapi2::ffdc_t RX0_LANE_CONTROL_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_RX0_LANE_CONTROL_REG_OFFSET, l_scom_data);
    }

    l_rx0_lane_control_reg = l_scom_data();
    RX0_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_rx0_lane_control_reg);
    RX0_LANE_CONTROL_REG.size() = sizeof(l_rx0_lane_control_reg);

    uint64_t l_rx1_lane_control_reg;
    fapi2::ffdc_t RX1_LANE_CONTROL_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_RX1_LANE_CONTROL_REG_OFFSET, l_scom_data);
    }

    l_rx1_lane_control_reg = l_scom_data();
    RX1_LANE_CONTROL_REG.ptr() = static_cast<void*>(&l_rx1_lane_control_reg);
    RX1_LANE_CONTROL_REG.size() = sizeof(l_rx1_lane_control_reg);

    uint64_t l_err0_status_reg;
    fapi2::ffdc_t ERR0_STATUS_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_ERR0_STATUS_REG_OFFSET, l_scom_data);
    l_err0_status_reg = l_scom_data();
    ERR0_STATUS_REG.ptr() = static_cast<void*>(&l_err0_status_reg);
    ERR0_STATUS_REG.size() = sizeof(l_err0_status_reg);

    uint64_t l_err1_status_reg;
    fapi2::ffdc_t ERR1_STATUS_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_ERR1_STATUS_REG_OFFSET, l_scom_data);
    l_err1_status_reg = l_scom_data();
    ERR1_STATUS_REG.ptr() = static_cast<void*>(&l_err1_status_reg);
    ERR1_STATUS_REG.size() = sizeof(l_err1_status_reg);

    uint64_t l_status_reg;
    fapi2::ffdc_t STATUS_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_STATUS_REG_OFFSET, l_scom_data);
    l_status_reg = l_scom_data();
    STATUS_REG.ptr() = static_cast<void*>(&l_status_reg);
    STATUS_REG.size() = sizeof(l_status_reg);

    uint64_t l_err_misc_reg;
    fapi2::ffdc_t ERR_MISC_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + DL_ERR_MISC_REG_OFFSET, l_scom_data);
    }

    l_err_misc_reg = l_scom_data();
    ERR_MISC_REG.ptr() = static_cast<void*>(&l_err_misc_reg);
    ERR_MISC_REG.size() = sizeof(l_err_misc_reg);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P9_FAB_IOVALID_DL_FFDC_ERR);
}


/// @brief Append TL layer specific FFDC in the event of a training failure
///
/// @tparam T template parameter, defines endpoint type
/// @param[in]    i_chip_target  Processor chip target
/// @param[in]    i_link_ctl     X/A link control structure for link
/// @param[inout] o_rc           Return code object to be appended
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
void
p9_fab_iovalid_append_tl_ffdc(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_chip_target,
    const p9_fbc_link_ctl_t& i_link_ctl,
    fapi2::ReturnCode& o_rc)
{
    uint64_t l_base_scom_addr = i_link_ctl.tl_fir_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    uint64_t l_fir_reg;
    fapi2::ffdc_t FIR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr, l_scom_data);
    l_fir_reg = l_scom_data();
    FIR_REG.ptr() = static_cast<void*>(&l_fir_reg);
    FIR_REG.size() = sizeof(l_fir_reg);

    uint64_t l_config01_reg;
    fapi2::ffdc_t CONFIG01_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_CONFIG01_REG_OFFSET, l_scom_data);
    l_config01_reg = l_scom_data();
    CONFIG01_REG.ptr() = static_cast<void*>(&l_config01_reg);
    CONFIG01_REG.size() = sizeof(l_config01_reg);

    uint64_t l_config23_reg;
    fapi2::ffdc_t CONFIG23_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_CONFIG23_REG_OFFSET, l_scom_data);
    l_config23_reg = l_scom_data();
    CONFIG23_REG.ptr() = static_cast<void*>(&l_config23_reg);
    CONFIG23_REG.size() = sizeof(l_config23_reg);

    uint64_t l_config45_reg;
    fapi2::ffdc_t CONFIG45_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_CONFIG45_REG_OFFSET, l_scom_data);
    l_config45_reg = l_scom_data();
    CONFIG45_REG.ptr() = static_cast<void*>(&l_config45_reg);
    CONFIG45_REG.size() = sizeof(l_config45_reg);

    uint64_t l_config67_reg;
    fapi2::ffdc_t CONFIG67_REG;
    l_scom_data.flush<1>();

    if (T == fapi2::TARGET_TYPE_OBUS)
    {
        (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_CONFIG67_REG_OFFSET, l_scom_data);
    }

    l_config67_reg = l_scom_data();
    CONFIG67_REG.ptr() = static_cast<void*>(&l_config67_reg);
    CONFIG67_REG.size() = sizeof(l_config67_reg);

    uint64_t l_misc_config_reg;
    fapi2::ffdc_t MISC_CONFIG_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_MISC_CONFIG_REG_OFFSET, l_scom_data);
    l_misc_config_reg = l_scom_data();
    MISC_CONFIG_REG.ptr() = static_cast<void*>(&l_misc_config_reg);
    MISC_CONFIG_REG.size() = sizeof(l_misc_config_reg);

    uint64_t l_framer0123_err_reg;
    fapi2::ffdc_t FRAMER0123_ERR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_FRAMER0123_ERR_REG_OFFSET, l_scom_data);
    l_framer0123_err_reg = l_scom_data();
    FRAMER0123_ERR_REG.ptr() = static_cast<void*>(&l_framer0123_err_reg);
    FRAMER0123_ERR_REG.size() = sizeof(l_framer0123_err_reg);

    uint64_t l_framer4567_err_reg;
    fapi2::ffdc_t FRAMER4567_ERR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_FRAMER4567_ERR_REG_OFFSET, l_scom_data);
    l_framer4567_err_reg = l_scom_data();
    FRAMER4567_ERR_REG.ptr() = static_cast<void*>(&l_framer4567_err_reg);
    FRAMER4567_ERR_REG.size() = sizeof(l_framer4567_err_reg);

    uint64_t l_parser0123_err_reg;
    fapi2::ffdc_t PARSER0123_ERR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_PARSER0123_ERR_REG_OFFSET, l_scom_data);
    l_parser0123_err_reg = l_scom_data();
    PARSER0123_ERR_REG.ptr() = static_cast<void*>(&l_parser0123_err_reg);
    PARSER0123_ERR_REG.size() = sizeof(l_parser0123_err_reg);

    uint64_t l_parser4567_err_reg;
    fapi2::ffdc_t PARSER4567_ERR_REG;
    l_scom_data.flush<1>();
    (void) fapi2::getScom(i_chip_target, l_base_scom_addr + TL_PARSER4567_ERR_REG_OFFSET, l_scom_data);
    l_parser4567_err_reg = l_scom_data();
    PARSER4567_ERR_REG.ptr() = static_cast<void*>(&l_parser4567_err_reg);
    PARSER4567_ERR_REG.size() = sizeof(l_parser4567_err_reg);

    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_P9_FAB_IOVALID_TL_FFDC_ERR);
}


/// @brief Return endpoint targets for local/remote ends of link, via local end
///        link control structure
///
/// @tparam T template parameter, defines endpoint type
/// @param[in]  i_loc_chip_target    Processor chip target
/// @param[in]  i_loc_link_ctl       X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl       X/A link control structure for link remote end
/// @param[out] io_loc_endp_target   Link endpoint target (local end)
/// @param[out] io_rem_endp_target   Link endpoint target (remote end)
/// @param[out] io_rem_chip_target   Processor chip target (remote end)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fab_iovalid_get_link_endpoints(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_loc_chip_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl,
    fapi2::Target<T>& io_loc_endp_target,
    fapi2::Target<T>& io_rem_endp_target,
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& io_rem_chip_target)
{
    FAPI_DBG("Start");

    // use local end link control structure to find associated endpoint target
    auto l_endp_targets = i_loc_chip_target.getChildren<T>();
    bool l_found = false;

    for (auto l_iter = l_endp_targets.begin();
         (l_iter != l_endp_targets.end()) && !l_found;
         l_iter++)
    {
        uint8_t l_loc_endp_unit_id;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, *l_iter, l_loc_endp_unit_id),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, local)");

        if ((static_cast<fapi2::TargetType>(i_loc_link_ctl.endp_type) == T) &&
            (i_loc_link_ctl.endp_unit_id == l_loc_endp_unit_id))
        {
            // associated endpoint target found, use getOtherEnd/getParent to reach chip
            // target of connected chip
            fapi2::Target<T> l_rem_endp_target;
            fapi2::ReturnCode l_rc = l_iter->getOtherEnd(l_rem_endp_target);
            FAPI_ASSERT(!l_rc,
                        fapi2::P9_FAB_IOVALID_REM_ENDP_TARGET_ERR()
                        .set_LOC_TARGET(i_loc_chip_target)
                        .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                        .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                        .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id)
                        .set_LOC_ENDP_TARGET(*l_iter),
                        "Endpoint target at other end of link is invalid!");
            l_found = true;
            io_loc_endp_target = *l_iter;
            io_rem_endp_target = l_rem_endp_target;
            io_rem_chip_target = io_rem_endp_target.template getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        }
    }

    FAPI_ASSERT(l_found,
                fapi2::P9_FAB_IOVALID_LOC_ENDP_TARGET_ERR()
                .set_LOC_TARGET(i_loc_chip_target)
                .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                .set_LOC_ENDP_TARGETS(l_endp_targets),
                "No matching local endpoint target found!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Validate DL/TL link layers are trained
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_loc_link_ctl    X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl    X/A link control structure for link remote end
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fab_iovalid_link_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dl_fir_reg;
    fapi2::buffer<uint64_t> l_tl_fir_reg;
    uint8_t l_tl_fir_trained_state = 0;
    fapi2::Target<T> l_loc_endp_target;
    fapi2::Target<T> l_rem_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_chip_target;

    // obtain link endpoints for FFDC
    FAPI_TRY(p9_fab_iovalid_get_link_endpoints(i_target,
             i_loc_link_ctl,
             i_rem_link_ctl,
             l_loc_endp_target,
             l_rem_endp_target,
             l_rem_chip_target),
             "Error from p9_fab_iovalid_get_link_endpoints");

    // validate DL training state
    FAPI_TRY(fapi2::getScom(i_target, i_loc_link_ctl.dl_fir_addr, l_dl_fir_reg),
             "Error from getScom (0x%.16llX)", i_loc_link_ctl.dl_fir_addr);

    FAPI_ASSERT(l_dl_fir_reg.getBit<DL_FIR_LINK0_TRAINED_BIT>() &&
                l_dl_fir_reg.getBit<DL_FIR_LINK1_TRAINED_BIT>(),
                fapi2::P9_FAB_IOVALID_DL_NOT_TRAINED_ERR()
                .set_TARGET(i_target)
                .set_LOC_ENDP_TARGET(l_loc_endp_target)
                .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                .set_REM_ENDP_TARGET(l_rem_endp_target)
                .set_REM_ENDP_TYPE(i_rem_link_ctl.endp_type)
                .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                "Link DL training did not complete successfully!");

    // validate TL training state
    FAPI_TRY(fapi2::getScom(i_target, i_loc_link_ctl.tl_fir_addr, l_tl_fir_reg),
             "Error from getScom (0x%.16llX)", i_loc_link_ctl.tl_fir_addr);
    FAPI_TRY(l_tl_fir_reg.extractToRight(l_tl_fir_trained_state,
                                         i_loc_link_ctl.tl_fir_trained_field_start_bit,
                                         TL_FIR_TRAINED_FIELD_LENGTH),
             "Error extracting TL layer training state");

    FAPI_ASSERT(l_tl_fir_trained_state == TL_FIR_TRAINED_LINK_TRAINED,
                fapi2::P9_FAB_IOVALID_TL_NOT_TRAINED_ERR()
                .set_TARGET(i_target)
                .set_LOC_ENDP_TARGET(l_loc_endp_target)
                .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                .set_REM_ENDP_TARGET(l_rem_endp_target)
                .set_REM_ENDP_TYPE(i_rem_link_ctl.endp_type)
                .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                "Link TL training did not complete successfully!");

fapi_try_exit:

    if (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_DL_NOT_TRAINED_ERR)
    {
        p9_fab_iovalid_append_dl_ffdc<T>(i_target,
                                         i_loc_link_ctl,
                                         fapi2::current_err);
        p9_fab_iovalid_append_dl_ffdc<T>(l_rem_chip_target,
                                         i_rem_link_ctl,
                                         fapi2::current_err);
    }
    else if (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_TL_NOT_TRAINED_ERR)
    {
        p9_fab_iovalid_append_tl_ffdc<T>(i_target,
                                         i_loc_link_ctl,
                                         fapi2::current_err);
        p9_fab_iovalid_append_tl_ffdc<T>(l_rem_chip_target,
                                         i_rem_link_ctl,
                                         fapi2::current_err);
    }

    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Compute single end link delay of individual link
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_link_ctl        X/A link control structure for link
/// @param[out] o_link_delay      Link delay
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fab_iovalid_get_link_delay(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_link_ctl,
    uint32_t o_link_delay)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_link_delay_reg;
    uint32_t l_sublink_delay[2];

    // read link delay register, extract hi/lo delay values & return their average
    FAPI_TRY(fapi2::getScom(i_target, i_link_ctl.tl_link_delay_addr, l_link_delay_reg),
             "Error from getScom (0x%.16llX)", i_link_ctl.tl_link_delay_addr);
    FAPI_TRY(l_link_delay_reg.extractToRight(l_sublink_delay[0],
             i_link_ctl.tl_link_delay_hi_start_bit,
             TL_LINK_DELAY_FIELD_NUM_BITS),
             "Error extracting link delay (hi>");
    FAPI_TRY(l_link_delay_reg.extractToRight(l_sublink_delay[1],
             i_link_ctl.tl_link_delay_lo_start_bit,
             TL_LINK_DELAY_FIELD_NUM_BITS),
             "Error extracting link delay (lo)");
    o_link_delay = (l_sublink_delay[0] + l_sublink_delay[1]) / 2;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Get round trip training delays reported by both endpoints
///        of a given link
///
/// @tparam T template parameter, defines endpoint type
/// @param[in]  i_loc_target        Source side chip target
/// @param[in]  i_loc_link_ctl      X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl      X/A link control structure for link remote end
/// @param[out] o_agg_link_delay    Sum of local and remote end link delays
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fab_iovalid_get_link_delays(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_loc_chip_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl,
    uint32_t& o_agg_link_delay)
{
    FAPI_DBG("Start");

    uint32_t l_loc_link_delay = 0xFFF;
    uint32_t l_rem_link_delay = 0xFFF;
    fapi2::Target<T> l_loc_endp_target;
    fapi2::Target<T> l_rem_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_chip_target;

    // get link endpoint targets
    FAPI_TRY(p9_fab_iovalid_get_link_endpoints(
                 i_loc_chip_target,
                 i_loc_link_ctl,
                 i_rem_link_ctl,
                 l_loc_endp_target,
                 l_rem_endp_target,
                 l_rem_chip_target),
             "Error from p9_fab_iovalid_get_link_endpoints");

    // read link delay from local/remote chip targets
    // link control structures provide register/bit offsets to collect
    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 i_loc_chip_target,
                 i_loc_link_ctl,
                 l_loc_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (local)");

    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 l_rem_chip_target,
                 i_rem_link_ctl,
                 l_rem_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (remote)");

    o_agg_link_delay = l_loc_link_delay + l_rem_link_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}



///
/// @brief Manipulate iovalid/FIR settings for a single fabric link (X/A)
///
/// @param[in] i_target        Reference to processor chip target
/// @param[in] i_ctl           Reference to link control structure
/// @param[in] i_set_not_clear Define iovalid operation (true=set, false=clear)
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_fab_iovalid_update_link(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const p9_fbc_link_ctl_t& i_ctl,
                           const bool i_set_not_clear)
{
    FAPI_DBG("Start");

    // form data buffers for iovalid/RAS FIR mask updates
    fapi2::buffer<uint64_t> l_iovalid_mask;
    fapi2::buffer<uint64_t> l_ras_fir_mask;
    fapi2::buffer<uint64_t> l_extfir_action;

    if (i_set_not_clear)
    {
        // set iovalid
        l_iovalid_mask.flush<0>();
        FAPI_TRY(l_iovalid_mask.setBit(i_ctl.iovalid_field_start_bit,
                                       IOVALID_FIELD_NUM_BITS));
        // clear RAS FIR mask
        l_ras_fir_mask.flush<1>();
        FAPI_TRY(l_ras_fir_mask.clearBit(i_ctl.ras_fir_field_bit));

        // get the value of the action 0 register, clear the bit and write it
        FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION0_REG, l_extfir_action),
                 "Error reading Action 0 register");
        FAPI_TRY(l_extfir_action.clearBit(i_ctl.ras_fir_field_bit));
        FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION0_REG, l_extfir_action),
                 "Error writing Action 0 register");

        // get the value of the action 1 registers, clear the bit, and write it
        FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action),
                 "Error reading Action 1 register");
        FAPI_TRY(l_extfir_action.clearBit(i_ctl.ras_fir_field_bit));
        FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action),
                 "Error writing Action 1 register");
    }
    else
    {
        // clear iovalid
        l_iovalid_mask.flush<1>();
        FAPI_TRY(l_iovalid_mask.clearBit(i_ctl.iovalid_field_start_bit,
                                         IOVALID_FIELD_NUM_BITS));
        // set RAS FIR mask
        l_ras_fir_mask.flush<0>();
        FAPI_TRY(l_ras_fir_mask.setBit(i_ctl.ras_fir_field_bit));
    }

    // use AND/OR mask registers to atomically update link specific fields
    // in iovalid/RAS FIR mask registers
    FAPI_TRY(fapi2::putScom(i_target,
                            (i_set_not_clear) ? (i_ctl.iovalid_or_addr) : (i_ctl.iovalid_clear_addr),
                            l_iovalid_mask),
             "Error writing iovalid control register (0x%08X)!",
             (i_set_not_clear) ? (i_ctl.iovalid_or_addr) : (i_ctl.iovalid_clear_addr));

    FAPI_TRY(fapi2::putScom(i_target,
                            (i_set_not_clear) ? (PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND) : (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR),
                            l_ras_fir_mask),
             "Error writing RAS FIR mask register (0x%08X)!",
             (i_set_not_clear) ? (PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND) : (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const bool i_set_not_clear,
               const bool i_manage_electrical,
               const bool i_manage_optical)
{
    FAPI_INF("Start");

    // logical link (X/A) configuration parameters
    // arrays indexed by link ID on local end
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS];
    // link ID on remote end
    uint8_t l_x_rem_link_id[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_rem_link_id[P9_FBC_UTILS_MAX_A_LINKS];
    // aggregate (local+remote) delays
    uint32_t l_x_agg_link_delay[P9_FBC_UTILS_MAX_X_LINKS];
    uint32_t l_a_agg_link_delay[P9_FBC_UTILS_MAX_A_LINKS];

    // seed arrays with attribute values
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG, i_target, l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID, i_target, l_x_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_LINK_ID");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG, i_target, l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID, i_target, l_a_rem_link_id),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_LINK_ID");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

    for (uint8_t l_link_id = 0; l_link_id < P9_FBC_UTILS_MAX_X_LINKS; l_link_id++)
    {
        if (l_x_en[l_link_id])
        {
            if ((i_manage_electrical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)) ||
                (i_manage_optical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == OPTICAL)))
            {
                FAPI_DBG("Updating link X%d", l_link_id);
                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear),
                         "Error from p9_fab_iovalid_update_link (X)");

                if (i_set_not_clear)
                {
                    FAPI_DBG("Collecting link delay counter values");

                    if (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)
                    {
                        FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_XBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_x_agg_link_delay[l_link_id]),
                                 "Error from p9_fab_iovalid_get_link_delays (X, electrical)");

                        FAPI_TRY(p9_fab_iovalid_link_validate<fapi2::TARGET_TYPE_XBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]]),
                                 "Error from p9_fab_iovalid_link_validate (X, electrical)");
                    }
                    else
                    {
                        FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_OBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_x_agg_link_delay[l_link_id]),
                                 "Error from p9_fab_iovalid_get_link_delays (X, optical)");

                        FAPI_TRY(p9_fab_iovalid_link_validate<fapi2::TARGET_TYPE_OBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]]),
                                 "Error from p9_fab_iovalid_link_validate (X, optical)");
                    }
                }
            }
        }
        else
        {
            FAPI_DBG("Skipping link X%d", l_link_id);
        }
    }

    for (uint8_t l_link_id = 0; l_link_id < P9_FBC_UTILS_MAX_A_LINKS; l_link_id++)
    {
        if (l_a_en[l_link_id])
        {
            if (i_manage_optical &&
                (P9_FBC_ABUS_LINK_CTL_ARR[l_link_id].endp_type == OPTICAL))
            {
                FAPI_DBG("Updating link A%d", l_link_id);
                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear),
                         "Error from p9_fab_iovalid_update_link (A)");

                if (i_set_not_clear)
                {
                    FAPI_DBG("Collecting link delay counter values");
                    FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_OBUS>(
                                 i_target,
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_a_rem_link_id[l_link_id]],
                                 l_a_agg_link_delay[l_link_id]),
                             "Error from p9_fab_iovalid_get_link_delays (A)");

                    FAPI_TRY(p9_fab_iovalid_link_validate<fapi2::TARGET_TYPE_OBUS>(
                                 i_target,
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_a_rem_link_id[l_link_id]]),
                             "Error from p9_fab_iovalid_link_validate (A)");
                }
            }
        }
        else
        {
            FAPI_DBG("Skipping link A%d", l_link_id);
        }
    }

    // update link delay attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_LINK_DELAY, i_target, l_x_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_LINK_DELAY");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_LINK_DELAY, i_target, l_a_agg_link_delay),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_LINK_DELAY");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
