/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fab_iovalid.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
#include <p9_obus_scom_addresses.H>
#include <p9_obus_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// DL FIR register field constants
const uint8_t DL_FIR_LINK0_TRAINED_BIT = 0;
const uint8_t DL_FIR_LINK1_TRAINED_BIT = 1;

// DL RX Control register field constants
const uint32_t OFFSET_FROM_DL_CONTROL_TO_RX_EVEN_LANE_CONTROL = 7;
const uint32_t OFFSET_FROM_DL_CONTROL_TO_RX_ODD_LANE_CONTROL  = 8;

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

//  DL polling constants
const uint32_t DL_MAX_POLL_LOOPS = 100;
const uint32_t DL_POLL_SIM_CYCLES = 10000000;
const uint32_t DL_POLL_HW_DELAY_NS = 1000000;

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


/// @brief Helper function to count half-link per-lane train/fail bit indications
///
/// @param[in]  i_lane_info       Lane information data
/// @param[in]  o_lane_count      Number of bits set in lane information input
///
/// @return void
void p9_fab_iovalid_count_ones(
    const uint16_t i_lane_info,
    uint8_t& o_lane_count)
{
    uint16_t l_lane_info = i_lane_info;
    o_lane_count = 0;

    for (auto ii = 0; ii < 11; ++ii)
    {
        if (l_lane_info & 1)
        {
            o_lane_count++;
        }

        l_lane_info = l_lane_info >> 1;
    }
}


/// @brief Signal lane sparing FIR if link trains but reports a failed lane
///        (OBUS DL only)
///
/// @param[in]  i_target        Processor chip target
/// @param[in]  i_loc_link_ctl  X/A link control structure for link local end
/// @param[in]  i_even_not_odd  Indicate link half to check (true=even, false=odd)
/// @param[out] o_bus_failed    Mark bus failed based on lane status
///
/// @return fapi2::ReturnCode.  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fab_iovalid_lane_validate(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const bool i_even_not_odd,
    bool& o_bus_failed)
{
    FAPI_DBG("Start");

    uint64_t l_dl_rx_control_addr;
    fapi2::buffer<uint64_t> l_dl_rx_control;
    fapi2::buffer<uint64_t> l_dl_fir;
    uint16_t l_lane_failed = 0x7FF, l_lane_not_locked = 0x7FF;
    uint8_t l_lane_failed_count = 11, l_lane_not_locked_count = 11;

    FAPI_DBG("Checking for fail on %s lanes" ,
             ((i_even_not_odd) ? ("even") : ("odd")));

    o_bus_failed = false;

    l_dl_rx_control_addr = i_loc_link_ctl.dl_control_addr +
                           ((i_even_not_odd) ?
                            (OFFSET_FROM_DL_CONTROL_TO_RX_EVEN_LANE_CONTROL) :
                            (OFFSET_FROM_DL_CONTROL_TO_RX_ODD_LANE_CONTROL));

    FAPI_TRY(fapi2::getScom(i_target,
                            l_dl_rx_control_addr,
                            l_dl_rx_control),
             "Error from getScom (0x%08X)", l_dl_rx_control_addr);

    if (i_even_not_odd)
    {
        l_dl_rx_control.extractToRight < OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_FAILED,
                                       OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_FAILED_LEN - 1 > (l_lane_failed);
        l_dl_rx_control.invert();
        l_dl_rx_control.extractToRight < OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_LOCKED,
                                       OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_LOCKED_LEN - 1 > (l_lane_not_locked);
    }
    else
    {
        l_dl_rx_control.extractToRight < OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_FAILED,
                                       OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_FAILED_LEN - 1 > (l_lane_failed);
        l_dl_rx_control.invert();
        l_dl_rx_control.extractToRight < OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_LOCKED,
                                       OBUS_LL0_IOOL_LINK1_RX_LANE_CONTROL_LOCKED_LEN - 1 > (l_lane_not_locked);
    }

    p9_fab_iovalid_count_ones(l_lane_failed, l_lane_failed_count);
    p9_fab_iovalid_count_ones(l_lane_not_locked, l_lane_not_locked_count);

    if ((l_lane_failed_count == 0) && (l_lane_not_locked_count == 0))
    {
        goto fapi_try_exit;
    }
    else
    {
        FAPI_DBG("Non zero lane fail/not locked count: %d %d",
                 l_lane_failed_count, l_lane_not_locked_count);

        if ((l_lane_failed_count <= 1) && (l_lane_not_locked_count <= 1))
        {
            if (i_even_not_odd)
            {
                l_dl_fir.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK0_SPARE_DONE>();
            }
            else
            {
                l_dl_fir.setBit<OBUS_LL0_LL0_LL0_PB_IOOL_FIR_REG_LINK1_SPARE_DONE>();
            }

            FAPI_TRY(fapi2::putScomUnderMask(i_target,
                                             i_loc_link_ctl.dl_fir_addr,
                                             l_dl_fir,
                                             l_dl_fir),
                     "Error from putScom (0x%.16llX)", i_loc_link_ctl.dl_fir_addr);
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
    fapi2::buffer<uint64_t> l_dl_status_reg;
    fapi2::buffer<uint64_t> l_dl_rx_control;
    fapi2::Target<T> l_loc_endp_target;
    fapi2::Target<T> l_rem_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_chip_target;
    fapi2::ATTR_LINK_TRAIN_Type l_loc_link_train;
    fapi2::ATTR_LINK_TRAIN_Type l_loc_link_train_next;
    bool l_dl_trained = false;
    uint8_t l_dl_status_even = 0, l_dl_prior_status_even = 0;
    bool l_dl_fail_even = false;
    uint8_t l_dl_status_odd = 0, l_dl_prior_status_odd = 0;
    bool l_dl_fail_odd = false;
    uint8_t l_tl_trained = 0;
    uint32_t l_poll_loops = DL_MAX_POLL_LOOPS;
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];

    // obtain link endpoints for FFDC
    FAPI_TRY(p9_fab_iovalid_get_link_endpoints(i_target,
             i_loc_link_ctl,
             i_rem_link_ctl,
             l_loc_endp_target,
             l_rem_endp_target,
             l_rem_chip_target),
             "Error from p9_fab_iovalid_get_link_endpoints");

    fapi2::toString(l_loc_endp_target, l_target_str, sizeof(l_target_str));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN,
                           l_loc_endp_target,
                           l_loc_link_train),
             "Error from FAPI_ATTR_GET (ATTR_LINK_TRAIN)");
    l_loc_link_train_next = l_loc_link_train;

    // poll for DL trained indications
    do
    {
        // validate DL training state
        FAPI_TRY(fapi2::getScom(i_target, i_loc_link_ctl.dl_fir_addr, l_dl_fir_reg),
                 "Error from getScom (0x%.16llX)", i_loc_link_ctl.dl_fir_addr);

        FAPI_TRY(fapi2::getScom(i_target, i_loc_link_ctl.dl_status_addr, l_dl_status_reg),
                 "Error from getScom (0x%.16llX)", i_loc_link_ctl.dl_status_addr);

        l_dl_status_reg.extractToRight<XBUS_LL0_IOEL_DLL_STATUS_LINK0_CURRENT_STATE,
                                       XBUS_LL0_IOEL_DLL_STATUS_LINK0_CURRENT_STATE_LEN>
                                       (l_dl_status_even);

        l_dl_status_reg.extractToRight<XBUS_LL0_IOEL_DLL_STATUS_LINK0_PRIOR_STATE,
                                       XBUS_LL0_IOEL_DLL_STATUS_LINK0_PRIOR_STATE_LEN>
                                       (l_dl_prior_status_even);

        l_dl_status_reg.extractToRight<XBUS_LL0_IOEL_DLL_STATUS_LINK1_CURRENT_STATE,
                                       XBUS_LL0_IOEL_DLL_STATUS_LINK1_CURRENT_STATE_LEN>
                                       (l_dl_status_odd);

        l_dl_status_reg.extractToRight<XBUS_LL0_IOEL_DLL_STATUS_LINK1_PRIOR_STATE,
                                       XBUS_LL0_IOEL_DLL_STATUS_LINK1_PRIOR_STATE_LEN>
                                       (l_dl_prior_status_odd);

        if (l_loc_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH)
        {
            l_dl_trained   = l_dl_fir_reg.getBit<DL_FIR_LINK0_TRAINED_BIT>() &&
                             l_dl_fir_reg.getBit<DL_FIR_LINK1_TRAINED_BIT>();

            if (!l_dl_trained)
            {
                l_dl_fail_even = !((((l_dl_status_even == 0x8) || (l_dl_prior_status_even == 0x8) || (l_dl_status_even == 0x9)
                                     || (l_dl_prior_status_even == 0x9)) &&
                                    ((l_dl_status_odd  >= 0xB) && (l_dl_status_odd  <= 0xE))) ||
                                   ((l_dl_status_even == 0x2) && ((l_dl_status_odd  >= 0x8) && (l_dl_status_odd  <= 0xC))));
                l_dl_fail_odd  = !((((l_dl_status_odd == 0x8) || (l_dl_prior_status_odd == 0x8) || (l_dl_status_odd == 0x9)
                                     || (l_dl_prior_status_odd == 0x9)) &&
                                    ((l_dl_status_even >= 0xB) && (l_dl_status_even <= 0xE))) ||
                                   ((l_dl_status_odd == 0x2) && ((l_dl_status_even >= 0x8) && (l_dl_status_even <= 0xC))));
            }

            FAPI_DBG("even -- fail: %d, status_even: %X, prior_status_even: %X", l_dl_fail_even ? (1) : (0), l_dl_status_even,
                     l_dl_prior_status_even);
            FAPI_DBG("odd  -- fail: %d, status_odd: %X, prior_status_odd: %X", l_dl_fail_odd ? (1) : (0), l_dl_status_odd,
                     l_dl_prior_status_odd);
        }
        else if (l_loc_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)
        {
            l_dl_trained   = l_dl_fir_reg.getBit<DL_FIR_LINK0_TRAINED_BIT>();
            l_dl_fail_even = !l_dl_trained;
            l_dl_fail_odd  = true;
        }
        else
        {
            l_dl_trained   = l_dl_fir_reg.getBit<DL_FIR_LINK1_TRAINED_BIT>();
            l_dl_fail_even = true;
            l_dl_fail_odd  = !l_dl_trained;
        }

        if (!l_dl_trained)
        {
            FAPI_TRY(fapi2::delay(DL_POLL_HW_DELAY_NS, DL_POLL_SIM_CYCLES), "fapiDelay error");
        }

        l_poll_loops--;
    }
    while (l_poll_loops > 0 && !l_dl_trained);

    // OBUS DL reported trained, need to validate that no lane sparing occurred
    // in some cases, a spare may occur but not report in the FIR
    //
    // as we are not persisting bad lane information, we don't want to fail the
    // IPL directly if a single spare occurs, but can raise a FIR to indicate that the
    // spare has been consumed (MFG may choose to fail based on this criteria)
    //
    // if more than one spare is detected, mark the link as failed
    if (l_dl_trained && (T == fapi2::TARGET_TYPE_OBUS))
    {
        bool l_dl_fail_by_lane_status = false;
        FAPI_DBG("OBUS - Checking for DL lane failures");

        if (!l_dl_fail_even)
        {
            FAPI_TRY(p9_fab_iovalid_lane_validate(i_target,
                                                  i_loc_link_ctl,
                                                  true,
                                                  l_dl_fail_by_lane_status),
                     "Error from p9_fab_iovalid_lane_validate");

            if (l_dl_fail_by_lane_status)
            {
                l_dl_trained = false;
                l_dl_fail_even = true;
            }
        }

        if (!l_dl_fail_odd)
        {
            FAPI_TRY(p9_fab_iovalid_lane_validate(i_target,
                                                  i_loc_link_ctl,
                                                  false,
                                                  l_dl_fail_by_lane_status),
                     "Error from p9_fab_iovalid_lane_validate");

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

    // control reconfig loop behavior
    if (!l_dl_trained)
    {
        FAPI_ERR("Error in DL training for %s (ATTR_LINK_TRAIN: 0x%x, DL training failed: %d / %d)",
                 l_target_str,
                 l_loc_link_train,
                 l_dl_fail_even,
                 l_dl_fail_odd);

        // retrain on half link, only if:
        // - tried to train in full width mdoe
        // - exactly one half reported good & one half reported bad
        if ((l_loc_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH) &&
            (T == fapi2::TARGET_TYPE_OBUS) &&
            ((l_dl_fail_even && !l_dl_fail_odd) ||
             (!l_dl_fail_even && l_dl_fail_odd)))
        {
            l_loc_link_train_next = (l_dl_fail_even) ?
                                    (fapi2::ENUM_ATTR_LINK_TRAIN_ODD_ONLY) :
                                    (fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY);

            FAPI_DBG("Setting up to retrain with ATTR_LINK_TRAIN: 0x%x",
                     l_loc_link_train_next);
        }
        // otherwise, no retraining will be attempted:
        // - tried to train only half-width, and were not successful
        // - tried to train full-width, and both links were detected
        //   to be failed (or passed, should only result from code issue)
        else
        {
            l_loc_link_train_next = fapi2::ENUM_ATTR_LINK_TRAIN_NONE;
        }

        FAPI_INF("Resetting ATTR_LINK_TRAIN: 0x%X for %s",
                 l_loc_link_train_next,
                 l_target_str);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_LINK_TRAIN,
                               l_loc_endp_target,
                               l_loc_link_train_next),
                 "Error from FAPI_ATTR_SET (ATTR_LINK_TRAIN)");

        // if nothing is left to run on, emit RC with callout/deconfig on endpoints
        // (no retraining for this bus)
        FAPI_ASSERT(l_loc_link_train_next != fapi2::ENUM_ATTR_LINK_TRAIN_NONE,
                    fapi2::P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR()
                    .set_TARGET(i_target)
                    .set_LOC_ENDP_TARGET(l_loc_endp_target)
                    .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                    .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_LINK_FAILED0(l_dl_fail_even)
                    .set_LOC_LINK_FAILED1(l_dl_fail_odd)
                    .set_REM_ENDP_TARGET(l_rem_endp_target)
                    .set_REM_ENDP_TYPE(i_rem_link_ctl.endp_type)
                    .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                    "Link DL training did not complete successfully!");
        // else, emit RC with no deconfig (and attempt retraining on half link)
        FAPI_ASSERT(false,
                    fapi2::P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR()
                    .set_TARGET(i_target)
                    .set_LOC_ENDP_TARGET(l_loc_endp_target)
                    .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                    .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                    .set_LOC_LINK_TRAIN(l_loc_link_train)
                    .set_LOC_LINK_TRAIN_NEXT(l_loc_link_train_next)
                    .set_LOC_LINK_FAILED0(l_dl_fail_even)
                    .set_LOC_LINK_FAILED1(l_dl_fail_odd)
                    .set_REM_ENDP_TARGET(l_rem_endp_target)
                    .set_REM_ENDP_TYPE(i_rem_link_ctl.endp_type)
                    .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                    "Link DL training did not complete successfully!");
    }

    // validate TL training state
    FAPI_DBG("Validating TL training state...");
    FAPI_TRY(fapi2::getScom(i_target, i_loc_link_ctl.tl_fir_addr, l_tl_fir_reg),
             "Error from getScom (0x%.16llX)", i_loc_link_ctl.tl_fir_addr);

    if (l_loc_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH)
    {
        l_tl_trained = l_tl_fir_reg.getBit(i_loc_link_ctl.tl_fir_trained_field_start_bit) &&
                       l_tl_fir_reg.getBit(i_loc_link_ctl.tl_fir_trained_field_start_bit + 1);
    }
    else if (l_loc_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)
    {
        l_tl_trained = l_tl_fir_reg.getBit(i_loc_link_ctl.tl_fir_trained_field_start_bit);
    }
    else
    {
        l_tl_trained = l_tl_fir_reg.getBit(i_loc_link_ctl.tl_fir_trained_field_start_bit + 1);
    }

    FAPI_ASSERT(l_tl_trained,
                fapi2::P9_FAB_IOVALID_TL_NOT_TRAINED_ERR()
                .set_TARGET(i_target)
                .set_LOC_ENDP_TARGET(l_loc_endp_target)
                .set_LOC_ENDP_TYPE(i_loc_link_ctl.endp_type)
                .set_LOC_ENDP_UNIT_ID(i_loc_link_ctl.endp_unit_id)
                .set_LOC_LINK_TRAIN(l_loc_link_train)
                .set_REM_ENDP_TARGET(l_rem_endp_target)
                .set_REM_ENDP_TYPE(i_rem_link_ctl.endp_type)
                .set_REM_ENDP_UNIT_ID(i_rem_link_ctl.endp_unit_id),
                "Error in TL training for %s (ATTR_LINK_TRAIN: 0x%X)",
                l_target_str,
                l_loc_link_train);

fapi_try_exit:

    if ((fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
        (fapi2::current_err == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR))
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





/// @brief Resume I/O PPE engines if HW446279_USE_PPE
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_loc_link_ctl    X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl    X/A link control structure for link remote end
///
/// @return fapi2::ReturnCode
fapi2::ReturnCode p9_fab_iovalid_enable_ppe(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl)
{
    const uint64_t OBUS_PPE_XCR_ADDR = 0x0000000009011050ull;
    const uint64_t HARD_RESET        = 0x6000000000000000ull; // xcr cmd=110
    const uint64_t RESUME_FROM_HALT  = 0x2000000000000000ull; // xcr cmd=010
    fapi2::buffer<uint64_t> l_hard_reset_data(HARD_RESET);
    fapi2::buffer<uint64_t> l_resume_data(RESUME_FROM_HALT);

    fapi2::Target<fapi2::TARGET_TYPE_OBUS> l_loc_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> l_rem_endp_target;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_rem_chip_target;

    // obtain link endpoints for FFDC
    FAPI_TRY(p9_fab_iovalid_get_link_endpoints(i_target,
             i_loc_link_ctl,
             i_rem_link_ctl,
             l_loc_endp_target,
             l_rem_endp_target,
             l_rem_chip_target),
             "Error from p9_fab_iovalid_get_link_endpoints");

    FAPI_TRY(fapi2::putScom(l_loc_endp_target,
                            OBUS_PPE_XCR_ADDR,
                            l_hard_reset_data),
             "Resume From Halt Failed.");

    FAPI_TRY(fapi2::putScom(l_loc_endp_target,
                            OBUS_PPE_XCR_ADDR,
                            l_resume_data),
             "Resume From Halt Failed.");

fapi_try_exit:
    return fapi2::current_err;
}



/// @brief Validate DL/TL link layers are trained
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_loc_link_ctl    X/A link control structure for link local end
/// @param[in]  i_rem_link_ctl    X/A link control structure for link remote end
/// @param[out] o_retrain         Indication that DL link training should be
///                               re-attempted
/// @param[out] o_rcs             Vector of return code objects, to append
///                               in case of reported DL training failure
///
/// @return fapi2::ReturnCode
template<fapi2::TargetType T>
fapi2::ReturnCode p9_fab_iovalid_link_validate_wrap(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_loc_link_ctl,
    const p9_fbc_link_ctl_t& i_rem_link_ctl,
    bool& o_retrain,
    std::vector<fapi2::ReturnCode>& o_rcs)
{
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    l_rc = p9_fab_iovalid_link_validate<T>(
               i_target,
               i_loc_link_ctl,
               i_rem_link_ctl);

    do
    {
        if (((l_rc == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_NONE_ERR) ||
             (l_rc == (fapi2::ReturnCode) fapi2::RC_P9_FAB_IOVALID_DL_NOT_TRAINED_RETRAIN_HALF_ERR)) &&
            (T == fapi2::TARGET_TYPE_OBUS))
        {
            o_retrain = true;
            o_rcs.push_back(l_rc);
            break;
        }
        else
        {
            o_retrain = false;

            if (l_rc != fapi2::FAPI2_RC_SUCCESS)
            {
                FAPI_ERR("Error from p9_fab_iovalid_link_validate_wrap");
                break;
            }

            if (T == fapi2::TARGET_TYPE_OBUS)
            {
                fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE_Type l_hw446279_use_ppe;

                l_rc = FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE,
                                     i_target,
                                     l_hw446279_use_ppe);

                if (l_rc)
                {
                    FAPI_ERR("Error from FAPI_ATTR_GET (fapi2::ATTR_CHIP_EC_FEATURE_HW446279_USE_PPE");
                    break;
                }

                if (l_hw446279_use_ppe)
                {
                    // At this point, both halves of the SMP ABUS have completed training and
                    // we will kick off the ppe if we need HW446279_USE_PPE
                    l_rc = p9_fab_iovalid_enable_ppe(
                               i_target,
                               i_loc_link_ctl,
                               i_rem_link_ctl);

                    if (l_rc != fapi2::FAPI2_RC_SUCCESS)
                    {
                        FAPI_ERR("Error from p9_fab_iovalid_enable_ppe");
                        break;
                    }
                }
            }
        }

    }
    while(0);

    return l_rc;
}


/// @brief Compute single end link delay of individual link
///
/// @param[in]  i_target          Processor chip target
/// @param[in]  i_link_ctl        X/A link control structure for link
/// @param[in]  i_link_train      Sublinks to monitor
/// @param[out] o_link_delay      Link delay
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p9_fab_iovalid_get_link_delay(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_link_ctl,
    const fapi2::ATTR_LINK_TRAIN_Type i_link_train,
    uint32_t o_link_delay)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_link_delay_reg;
    uint32_t l_sublink_delay[2] = {};

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

    if (i_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_BOTH)
    {
        o_link_delay = (l_sublink_delay[0] + l_sublink_delay[1]) / 2;
    }
    else if (i_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)
    {
        o_link_delay = l_sublink_delay[0];
    }
    else if (i_link_train == fapi2::ENUM_ATTR_LINK_TRAIN_EVEN_ONLY)
    {
        o_link_delay = l_sublink_delay[1];
    }
    else
    {
        o_link_delay = 0xFFFFFFFF;
    }

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
    fapi2::ATTR_LINK_TRAIN_Type l_loc_link_train;
    fapi2::ATTR_LINK_TRAIN_Type l_rem_link_train;

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
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN,
                           l_loc_endp_target,
                           l_loc_link_train),
             "Error from FAPI_ATTR_GET (ATTR_LINK_TRAIN, local)");

    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 i_loc_chip_target,
                 i_loc_link_ctl,
                 l_loc_link_train,
                 l_loc_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (local)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_LINK_TRAIN,
                           l_rem_endp_target,
                           l_rem_link_train),
             "Error from FAPI_ATTR_GET (ATTR_LINK_TRAIN, remote)");

    FAPI_TRY(p9_fab_iovalid_get_link_delay(
                 l_rem_chip_target,
                 i_rem_link_ctl,
                 l_rem_link_train,
                 l_rem_link_delay),
             "Error from p9_fab_iovalid_get_link_delay (remote)");

    o_agg_link_delay = l_loc_link_delay + l_rem_link_delay;

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}



///
/// @brief Manipulate iovalid settings for a single fabric link (X/A)
///
/// @param[in] i_target        Reference to processor chip target
/// @param[in] i_ctl           Reference to link control structure
/// @param[in] i_set_not_clear Define iovalid operation (true=set, false=clear)
/// @param[in] i_en            Defines sublinks to enable
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_fab_iovalid_update_link(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                           const p9_fbc_link_ctl_t& i_ctl,
                           const bool i_set_not_clear,
                           const uint8_t i_en)
{
    FAPI_DBG("Start");

    // form data buffers for iovalid/RAS FIR mask updates
    fapi2::buffer<uint64_t> l_iovalid_mask;

    if (i_set_not_clear)
    {
        fapi2::buffer<uint64_t> l_ras_fir_mask;
        fapi2::buffer<uint64_t> l_extfir_action;
        fapi2::buffer<uint64_t> l_fbc_cent_fir_data;

        // set iovalid
        l_iovalid_mask.flush<0>();

        if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
            (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY))
        {
            FAPI_TRY(l_iovalid_mask.setBit(i_ctl.iovalid_field_start_bit));
        }

        if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
            (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY))
        {
            FAPI_TRY(l_iovalid_mask.setBit(i_ctl.iovalid_field_start_bit + 1));
        }

        FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM0_PB_CENT_FIR_REG, l_fbc_cent_fir_data),
                 "Error from getScom (PU_PB_CENT_SM0_PB_CENT_FIR_REG)");

        // clear RAS FIR mask for optical link, or electrical link if not already setup by SBE
        if (((i_ctl.endp_type == OPTICAL) &&
             (!l_fbc_cent_fir_data.getBit<PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_SPARE_14>())) ||
            ((i_ctl.endp_type == ELECTRICAL) &&
             (!l_fbc_cent_fir_data.getBit<PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_SPARE_13>())))
        {
            // get the value of the action 0 register, clear the bit and write it
            FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION0_REG, l_extfir_action),
                     "Error reading RAS FIR Action 0 register");
            FAPI_TRY(l_extfir_action.clearBit(i_ctl.ras_fir_field_bit));
            FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION0_REG, l_extfir_action),
                     "Error writing RAS FIR Action 0 register");

            // get the value of the action 1 registers, clear the bit, and write it
            FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action),
                     "Error reading RAS FIR Action 1 register");
            FAPI_TRY(l_extfir_action.clearBit(i_ctl.ras_fir_field_bit));
            FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_ACTION1_REG, l_extfir_action),
                     "Error writing RAS FIR Action 1 register");

            // clear associated mask bit
            l_ras_fir_mask.flush<1>();
            FAPI_TRY(l_ras_fir_mask.clearBit(i_ctl.ras_fir_field_bit));
            FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND, l_ras_fir_mask),
                     "Error writing RAS FIR mask register (PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND)!");
        }
    }
    else
    {
        // clear iovalid
        l_iovalid_mask.flush<1>();

        if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
            (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY))
        {
            FAPI_TRY(l_iovalid_mask.clearBit(i_ctl.iovalid_field_start_bit));
        }

        if ((i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
            (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY))
        {
            FAPI_TRY(l_iovalid_mask.clearBit(i_ctl.iovalid_field_start_bit + 1));
        }
    }

    // use AND/OR mask registers to atomically update link specific fields
    // in iovalid control register
    FAPI_TRY(fapi2::putScom(i_target,
                            (i_set_not_clear) ? (i_ctl.iovalid_or_addr) : (i_ctl.iovalid_clear_addr),
                            l_iovalid_mask),
             "Error writing iovalid control register (0x%08X)!",
             (i_set_not_clear) ? (i_ctl.iovalid_or_addr) : (i_ctl.iovalid_clear_addr));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fab_iovalid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
               const bool i_set_not_clear,
               const bool i_manage_electrical,
               const bool i_manage_optical,
               std::vector<fapi2::ReturnCode>& o_obus_dl_fail_rcs)
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

    // Add delay for dd1.1+ procedure to compensate for lack of lane lock polls
    FAPI_TRY(fapi2::delay(100000000, 1000000),
             "Error from delay");

    for (uint8_t l_link_id = 0; l_link_id < P9_FBC_UTILS_MAX_X_LINKS; l_link_id++)
    {
        if (l_x_en[l_link_id])
        {
            if ((i_manage_electrical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)) ||
                (i_manage_optical &&
                 (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == OPTICAL)))
            {
                bool l_link_needs_retraining = false;

                FAPI_DBG("Updating link X%d", l_link_id);

                if (i_set_not_clear)
                {
                    if (P9_FBC_XBUS_LINK_CTL_ARR[l_link_id].endp_type == ELECTRICAL)
                    {
                        FAPI_TRY(p9_fab_iovalid_link_validate_wrap<fapi2::TARGET_TYPE_XBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_link_needs_retraining,
                                     o_obus_dl_fail_rcs),
                                 "Error from p9_fab_iovalid_link_validate_wrap (X, electrical)");
                    }
                    else
                    {
                        FAPI_TRY(p9_fab_iovalid_link_validate_wrap<fapi2::TARGET_TYPE_OBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_link_needs_retraining,
                                     o_obus_dl_fail_rcs),
                                 "Error from p9_fab_iovalid_link_validate_wrap (X, optical)");
                    }
                }

                if (l_link_needs_retraining)
                {
                    continue;
                }

                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear,
                                                    l_x_en[l_link_id]),
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
                    }
                    else
                    {
                        FAPI_TRY(p9_fab_iovalid_get_link_delays<fapi2::TARGET_TYPE_OBUS>(
                                     i_target,
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_link_id],
                                     P9_FBC_XBUS_LINK_CTL_ARR[l_x_rem_link_id[l_link_id]],
                                     l_x_agg_link_delay[l_link_id]),
                                 "Error from p9_fab_iovalid_get_link_delays (X, optical)");
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
                bool l_link_needs_retraining = false;
                FAPI_DBG("Updating link A%d", l_link_id);

                if (i_set_not_clear)
                {
                    FAPI_TRY(p9_fab_iovalid_link_validate_wrap<fapi2::TARGET_TYPE_OBUS>(
                                 i_target,
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                 P9_FBC_ABUS_LINK_CTL_ARR[l_a_rem_link_id[l_link_id]],
                                 l_link_needs_retraining,
                                 o_obus_dl_fail_rcs),
                             "Error from p9_fab_iovalid_link_validate_wrap (A)");
                }

                if (l_link_needs_retraining)
                {
                    continue;
                }

                FAPI_TRY(p9_fab_iovalid_update_link(i_target,
                                                    P9_FBC_ABUS_LINK_CTL_ARR[l_link_id],
                                                    i_set_not_clear,
                                                    l_a_en[l_link_id]),
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
