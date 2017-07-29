/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_smp_link_layer.C $ */
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
/// @file p9_smp_link_layer.C
/// @brief Start SMP DLL/link layer (FAPI2)
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
#include <p9_smp_link_layer.H>
#include <p9_fbc_smp_utils.H>
#include <p9_obus_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Constant Definitions
//------------------------------------------------------------------------------
const uint32_t OFFSET_FROM_DL_CONTROL_TO_TX_EVEN_LANE_CONTROL = 5;
const uint32_t OFFSET_FROM_DL_CONTROL_TO_TX_ODD_LANE_CONTROL  = 6;
const uint32_t OFFSET_FROM_DL_CONTROL_TO_RX_EVEN_LANE_CONTROL = 7;
const uint32_t OFFSET_FROM_DL_CONTROL_TO_RX_ODD_LANE_CONTROL  = 8;

const uint32_t LANES_PER_HALF_LINK = 11;

const uint8_t MAX_LOCK_INDICATOR_POLLS = 10;
const uint8_t MIN_LOCK_INDICATOR_STABLE_POLLS = 3;

const uint64_t DL_RX_CONTROL_LANE_LOCK_MASK   = 0x000000000FFF0000ULL;
const uint64_t DL_RX_CONTROL_ALL_LANES_LOCKED = 0x000000000FFE0000ULL;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Engage DLL/TL training for a single fabric link (X)
///        running on X PHY
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_ctl Reference to link control structure
/// @param[in] i_en Defines sublinks to enable
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_smp_link_layer_train_link_electrical(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_ctl,
    const uint8_t i_en)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dll_control;

    bool l_even = (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
                  (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_EVEN_ONLY);

    bool l_odd = (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_TRUE) ||
                 (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG_ODD_ONLY);

    // read control register
    FAPI_TRY(fapi2::getScom(i_target, i_ctl.dl_control_addr, l_dll_control),
             "Error reading DLL control register (0x%08X)!",
             i_ctl.dl_control_addr);

    if (l_even)
    {
        l_dll_control.setBit<XBUS_LL0_IOEL_CONTROL_LINK0_STARTUP>();
    }

    if (l_odd)
    {
        l_dll_control.setBit<XBUS_LL0_IOEL_CONTROL_LINK1_STARTUP>();
    }

    FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
             "Error writing DLL control register (0x%08X)!",
             i_ctl.dl_control_addr);

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Determine PHY TX lane inversions required to lock DL RX lanes
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_loc_target Local endpoint target
/// @param[in] i_rem_target Remote endpoint target
/// @param[in] i_ctl Reference to link control structure
/// @param[in] i_even True=process even half-link, False=process odd half-link
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_smp_link_layer_lock_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_loc_target,
    const fapi2::Target<fapi2::TARGET_TYPE_OBUS>& i_rem_target,
    const p9_fbc_link_ctl_t& i_ctl,
    const bool i_even)
{
    FAPI_DBG("Start");

    bool l_all_locked = 0;
    fapi2::buffer<uint64_t> l_dl_rx_control;
    uint64_t l_dl_rx_control_addr = i_ctl.dl_control_addr +
                                    ((i_even) ?
                                     (OFFSET_FROM_DL_CONTROL_TO_RX_EVEN_LANE_CONTROL) :
                                     (OFFSET_FROM_DL_CONTROL_TO_RX_ODD_LANE_CONTROL));


    // loop a maximum of two times to determine lane lock status
    // 1st check is prior to application of any PHY TX inversions
    // if any lanes do not lock, apply inversions and check again
    // assert if any lane is unlocked at this point
    for (uint8_t l_phase = 0; (l_phase < 2) && !l_all_locked; l_phase++)
    {
        uint8_t l_stable_reads = 1;
        fapi2::buffer<uint64_t> l_dl_rx_control_stable = 0;

        FAPI_DBG("Polling for stable lane lock field (phase=%d)", l_phase);

        // poll for stable pattern
        for (uint8_t l_poll = 0; l_poll < MAX_LOCK_INDICATOR_POLLS; l_poll++)
        {
            FAPI_TRY(fapi2::delay(100000000, 1000000),
                     "Error from delay (even, poll = %d)", l_poll + 1);

            FAPI_TRY(fapi2::getScom(i_target,
                                    l_dl_rx_control_addr,
                                    l_dl_rx_control),
                     "Error from getScom (0x%08X)", l_dl_rx_control_addr);

            if ((l_dl_rx_control() & DL_RX_CONTROL_LANE_LOCK_MASK) != l_dl_rx_control_stable())
            {
                l_dl_rx_control_stable = (l_dl_rx_control() & DL_RX_CONTROL_LANE_LOCK_MASK);
                l_stable_reads = 1;
            }
            else
            {
                l_stable_reads++;

                if (l_stable_reads == MIN_LOCK_INDICATOR_STABLE_POLLS)
                {
                    break;
                }
            }
        }

        FAPI_ASSERT(l_stable_reads == MIN_LOCK_INDICATOR_STABLE_POLLS,
                    fapi2::P9_SMP_LINK_LAYER_RX_CONTROL_STABILITY_ERR()
                    .set_TARGET(i_loc_target)
                    .set_DL_RX_CONTROL_ADDR(l_dl_rx_control_addr)
                    .set_DL_RX_CONTROL(l_dl_rx_control())
                    .set_PHASE(l_phase),
                    "DL RX Control register per-lane lock value did not stabilize prior to timeout (phase=%d)!",
                    l_phase);

        l_all_locked = ((l_dl_rx_control() & DL_RX_CONTROL_LANE_LOCK_MASK) == DL_RX_CONTROL_ALL_LANES_LOCKED);

        // apply PHY TX inversions only if needed
        if (!l_phase && !l_all_locked)
        {
            for (uint8_t l_lane = 0; l_lane < LANES_PER_HALF_LINK; l_lane++)
            {
                // set PHY TX lane address, start at:
                // - PHY lane 0 for even (work up)
                // - PHY lane 23 for odd (work down)
                uint64_t l_phy_tx_mode1_pl_addr = OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL;

                if (i_even)
                {
                    l_phy_tx_mode1_pl_addr |= ((uint64_t) l_lane << 32);
                }
                else
                {
                    l_phy_tx_mode1_pl_addr |= ((uint64_t) (23 - l_lane) << 32);
                }

                // read DL RX per-lane lock indicator bit
                // if locked: do nothing
                // if not locked: apply lane-invert to associated PHY TX side
                if (!l_dl_rx_control.getBit(OBUS_LL0_IOOL_LINK0_RX_LANE_CONTROL_LOCKED + l_lane))
                {
                    FAPI_DBG("Inverting lane %d", l_lane);
                    fapi2::buffer<uint64_t> l_phy_tx_mode1_pl;
                    FAPI_TRY(fapi2::getScom(i_rem_target,
                                            l_phy_tx_mode1_pl_addr,
                                            l_phy_tx_mode1_pl),
                             "Error from getScom (0x%08X)", l_phy_tx_mode1_pl_addr);

                    l_phy_tx_mode1_pl.setBit<OBUS_TX0_TXPACKS0_SLICE0_TX_MODE1_PL_LANE_INVERT>();

                    FAPI_TRY(fapi2::putScom(i_rem_target,
                                            l_phy_tx_mode1_pl_addr,
                                            l_phy_tx_mode1_pl),
                             "Error from putScom (0x%08X)", l_phy_tx_mode1_pl_addr);
                }
            }
        }
    }

    FAPI_ASSERT(l_all_locked,
                fapi2::P9_SMP_LINK_LAYER_RX_CONTROL_NOT_LOCKED_ERR()
                .set_TARGET(i_loc_target)
                .set_DL_RX_CONTROL_ADDR(l_dl_rx_control_addr)
                .set_DL_RX_CONTROL(l_dl_rx_control()),
                "DL RX Control register reports some lanes did not lock!");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Engage DLL/TL training for a single fabric link (X/A)
///        running on O PHY
///
/// @param[in] i_target Reference to processor chip target
/// @param[in] i_ctl Reference to link control structure
/// @param[in] i_en Defines sublinks to enable
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_smp_link_layer_train_link_optical(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_link_ctl_t& i_ctl,
    const uint8_t i_en)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_dll_control;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> l_loc_target;
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> l_rem_target;
    fapi2::ATTR_CHIP_EC_FEATURE_HW419022_Type l_hw419022 = 0;

    bool l_even = (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE) ||
                  (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_EVEN_ONLY);

    bool l_odd = (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_TRUE) ||
                 (i_en == fapi2::ENUM_ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG_ODD_ONLY);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW419022,
                           i_target,
                           l_hw419022),
             "Error from FAPI_ATTR_GET (fapi2::ATTR_CHIP_EC_FEATURE_HW419022)");

    // find local endpoint target associated with this link
    for (auto& l_target : i_target.getChildren<fapi2::TARGET_TYPE_OBUS>())
    {
        uint8_t l_unit_pos;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_target,
                               l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        if (l_unit_pos == i_ctl.endp_unit_id)
        {
            l_loc_target = l_target;
            break;
        }
    }

    FAPI_TRY(l_loc_target.getOtherEnd(l_rem_target),
             "Error from getOtherEnd");

    // read control register
    FAPI_TRY(fapi2::getScom(i_target, i_ctl.dl_control_addr, l_dll_control),
             "Error reading DLL control register (0x%08X)!",
             i_ctl.dl_control_addr);

    if (!l_hw419022)
    {
        if (l_even)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_PHY_TRAINING>();
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_STARTUP>();
        }

        if (l_odd)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_PHY_TRAINING>();
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_STARTUP>();
        }

        FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
                 "Error writing DLL control register (0x%08X)!",
                 i_ctl.dl_control_addr);
    }
    else
    {
        // force assertion of run_lane
        if (l_even)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_RUN_LANE_OVERRIDE>();
        }

        if (l_odd)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_RUN_LANE_OVERRIDE>();
        }

        FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
                 "Error writing DLL control register (0x%08X, force RUN_LANE)",
                 i_ctl.dl_control_addr);

        // ensure that DL RX sees lane lock
        if (l_even)
        {
            FAPI_TRY(p9_smp_link_layer_lock_lanes(i_target,
                                                  l_loc_target,
                                                  l_rem_target,
                                                  i_ctl,
                                                  true),
                     "Error from p9_smp_link_layer_lock_lanes (even)");
        }

        if (l_odd)
        {
            FAPI_TRY(p9_smp_link_layer_lock_lanes(i_target,
                                                  l_loc_target,
                                                  l_rem_target,
                                                  i_ctl,
                                                  false),
                     "Error from p9_smp_link_layer_lock_lanes (odd)");
        }

        // enable link startup
        if (l_even)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK0_STARTUP>();
        }

        if (l_odd)
        {
            l_dll_control.setBit<OBUS_LL0_IOOL_CONTROL_LINK1_STARTUP>();
        }

        FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
                 "Error writing DLL control register (0x%08X, set LINK_STARTUP)!",
                 i_ctl.dl_control_addr);

        // disable run lane override
        if (l_even)
        {
            l_dll_control.clearBit<OBUS_LL0_IOOL_CONTROL_LINK0_RUN_LANE_OVERRIDE>();
        }

        if (l_odd)
        {
            l_dll_control.clearBit<OBUS_LL0_IOOL_CONTROL_LINK1_RUN_LANE_OVERRIDE>();
        }

        FAPI_TRY(fapi2::putScom(i_target, i_ctl.dl_control_addr, l_dll_control),
                 "Error writing DLL control register (0x%08X, clar RUN_LANE_OVERRIDE)!",
                 i_ctl.dl_control_addr);

        // clear TX lane control override, set to ENABLED
        if (l_even)
        {
            uint64_t l_addr = i_ctl.dl_control_addr +
                              OFFSET_FROM_DL_CONTROL_TO_TX_EVEN_LANE_CONTROL;

            FAPI_TRY(fapi2::putScom(i_target,
                                    l_addr,
                                    0x0000000000000000ULL),
                     "Error from putScom (0x%08X, ENABLE)", l_addr);
        }

        if (l_odd)
        {
            uint64_t l_addr = i_ctl.dl_control_addr +
                              OFFSET_FROM_DL_CONTROL_TO_TX_ODD_LANE_CONTROL;

            FAPI_TRY(fapi2::putScom(i_target,
                                    l_addr,
                                    0x0000000000000000ULL),
                     "Error from putScom (0x%08X, ENABLE)", l_addr);
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_smp_link_layer(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const bool i_train_electrical,
    const bool i_train_optical)
{
    FAPI_INF("Start");

    FAPI_DBG("Input args: i_train_electrical: %d, i_train_optical: %d\n",
             i_train_electrical, i_train_optical);

    // logical link (X/A) configuration parameters
    // enable on local end
    uint8_t l_x_en[P9_FBC_UTILS_MAX_X_LINKS];
    uint8_t l_a_en[P9_FBC_UTILS_MAX_A_LINKS];

    // process set of enabled links
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_x_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_X_ATTACHED_CHIP_CNFG");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG,
                           i_target,
                           l_a_en),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_A_ATTACHED_CHIP_CNFG");

    for (uint8_t l_link = 0; l_link < P9_FBC_UTILS_MAX_X_LINKS; l_link++)
    {
        if (l_x_en[l_link])
        {
            if (i_train_electrical &&
                (P9_FBC_XBUS_LINK_CTL_ARR[l_link].endp_type == ELECTRICAL))
            {
                FAPI_DBG("Training link X%d (electrical)", l_link);
                FAPI_TRY(p9_smp_link_layer_train_link_electrical(
                             i_target,
                             P9_FBC_XBUS_LINK_CTL_ARR[l_link],
                             l_x_en[l_link]),
                         "Error from p9_smp_link_layer_train_link (X, electrical)");
            }

            if (i_train_optical &&
                (P9_FBC_XBUS_LINK_CTL_ARR[l_link].endp_type == OPTICAL))
            {
                FAPI_DBG("Training link X%d (optical)", l_link);
                FAPI_TRY(p9_smp_link_layer_train_link_optical(
                             i_target,
                             P9_FBC_XBUS_LINK_CTL_ARR[l_link],
                             l_x_en[l_link]),
                         "Error from p9_smp_link_layer_train_link (X, optical)");
            }
        }
        else
        {
            FAPI_DBG("Skipping link X%d", l_link);
        }
    }

    for (uint8_t l_link = 0; l_link < P9_FBC_UTILS_MAX_A_LINKS; l_link++)
    {
        if (l_a_en[l_link])
        {
            if (i_train_optical &&
                (P9_FBC_ABUS_LINK_CTL_ARR[l_link].endp_type == OPTICAL))
            {
                FAPI_DBG("Training link A%d", l_link);
                FAPI_TRY(p9_smp_link_layer_train_link_optical(
                             i_target,
                             P9_FBC_ABUS_LINK_CTL_ARR[l_link],
                             l_a_en[l_link]),
                         "Error from p9_smp_link_layer_train_link (A)");
            }
        }
        else
        {
            FAPI_DBG("Skipping link A%d", l_link);
        }
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
