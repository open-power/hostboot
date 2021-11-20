/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_lib.C $         */
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
/// @file p10_io_lib.H
/// @brief Common IO functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <p10_io_lib.H>
#include <p10_scom_omi.H>
#include <p10_scom_omic.H>
#include <p10_io_ppe_lib.H>
#include <p10_io_ppe_regs.H>

//------------------------------------------------------------------------------
// Consts
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------
class p10_io_lib : public p10_io_ppe_cache_proc
{
    public:
        fapi2::ReturnCode clear_error_valid(
            const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target);
};

/// @brief Determines the thread number for the given iohs target
/// @param[in] i_iohs_target    IOHS target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    int& o_thread)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_num;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    o_thread = l_iohs_num % P10_IO_LIB_NUMBER_OF_IOHS_THREADS;

    if (l_iohs_num >= 2)
    {
        //AX0/1 are swapped for ioo1..3
        o_thread = (P10_IO_LIB_NUMBER_OF_IOHS_THREADS - 1) - o_thread;
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines the thread number for the given omic target
/// @param[in] i_omic_target    OMIC target to get thread id for
/// @param[out] o_thread        The thread id for this target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_thread(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    int& o_thread)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_omic_target, l_omic_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    o_thread = l_omic_num % P10_IO_LIB_NUMBER_OF_OMIC_THREADS;
    //omic threads start after iohc threads
    o_thread += P10_IO_LIB_NUMBER_OF_IOHS_THREADS;
fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an IOLINK target
/// @param[in] i_iolink_target  IOLINK target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iolink_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
    std::vector<int>& o_lanes)
{
    int l_start_bit = 0;
    int l_end_bit = 0;

    fapi2::ATTR_CHIP_UNIT_POS_Type l_iolink_pos;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iolink_target, l_iolink_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    if (l_iolink_pos % 2)
    {
        l_start_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES / 2;
        l_end_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES;
    }
    else
    {
        l_end_bit = P10_IO_LIB_NUMBER_OF_IOHS_LANES / 2;
    }

    for (int l_lane = l_start_bit; l_lane < l_end_bit; l_lane++)
    {
        o_lanes.push_back(l_lane);
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an IOHS target
/// @param[in] i_iohs_target    IOHS target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_iohs_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    std::vector<int>& o_lanes)
{
    auto l_iolink_targets = i_iohs_target.getChildren<fapi2::TARGET_TYPE_IOLINK>();

    // handle Cronus platform implementation of IOLINK targets -- both
    // children are always returned as functional, even if no valid remote endpoint
    // connection exists
    if (fapi2::is_platform<fapi2::PLAT_CRONUS>())
    {
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_IOLINK>> l_iolink_targets_filtered;

        for (auto l_loc_iolink_target : l_iolink_targets)
        {
            fapi2::ReturnCode l_rc;
            fapi2::Target<fapi2::TARGET_TYPE_IOLINK> l_rem_iolink_target;
            l_rc = l_loc_iolink_target.getOtherEnd(l_rem_iolink_target);

            if (l_rc == fapi2::FAPI2_RC_SUCCESS)
            {
                l_iolink_targets_filtered.push_back(l_loc_iolink_target);
            }
        }

        l_iolink_targets = l_iolink_targets_filtered;
    }

    for (const auto l_iolink_target : l_iolink_targets)
    {
        std::vector<int> l_iolink_lanes;
        FAPI_TRY(p10_io_get_iolink_lanes(l_iolink_target,
                                         l_iolink_lanes));

        for (auto l_lane : l_iolink_lanes)
        {
            o_lanes.push_back(l_lane);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an OMIC target
/// @param[in] i_omic_target    OMIC target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omic_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    std::vector<int>& o_lanes)
{
    auto l_omi_targets = i_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    for (auto l_omi_target : l_omi_targets)
    {
        auto l_ocmbs = l_omi_target.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

        if (l_ocmbs.size() > 0)
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi_target, l_omi_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
            l_omi_num = l_omi_num % 2;

            for (int l_lane = l_omi_num * 8; l_lane < (l_omi_num + 1) * 8; l_lane++)
            {
                o_lanes.push_back(l_lane);
            }
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determines which lanes are enabled for an OMI target
/// @param[in] i_omi_target    OMI target to get lanes for
/// @param[out] o_lanes         The configured lanes
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_get_omi_lanes(
    const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target,
    std::vector<int>& o_lanes)
{
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_num;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_omi_target, l_omi_num),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    l_omi_num = l_omi_num % 2;

    for (int l_lane = l_omi_num * 8; l_lane < (l_omi_num + 1) * 8; l_lane++)
    {
        o_lanes.push_back(l_lane);
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write IOHS Per-Lane Hardware Data, writes ALL lanes
///
/// @param[in] i_target IOHS target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_put_pl_regs(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint32_t i_num_lanes,
        const uint64_t i_fld_data)
{
    const uint64_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    for (uint64_t l_lane = 0; l_lane < i_num_lanes; ++l_lane)
    {
        l_addr = i_reg_base_addr | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
        FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));
        FAPI_TRY(l_data.insertFromRight(i_fld_data, i_reg_start, i_reg_len));
        FAPI_TRY(fapi2::putScom(i_target, l_addr, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Write IOLINK Per-Lane Hardware Data, only writes 1 lane, not multiple lanes
///
/// @param[in] i_target IOHS target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_iohs_put_pl_regs_single(const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint64_t i_lane,
        const uint64_t i_fld_data)
{
    const uint64_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    FAPI_DBG("Begin single lane scom...");
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    l_addr = i_reg_base_addr | ((i_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
    FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));
    FAPI_TRY(l_data.insertFromRight(i_fld_data, i_reg_start, i_reg_len));
    FAPI_TRY(fapi2::putScom(i_target, l_addr, l_data));

fapi_try_exit:
    FAPI_DBG("End single lane scom...");
    return fapi2::current_err;
}

///
/// @brief Write OMI Per-Lane Hardware Data
///
/// @param[in] i_target OMI target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_omi_put_pl_regs(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_target,
        const uint64_t i_reg_base_addr,
        const uint32_t i_reg_start,
        const uint32_t i_reg_len,
        const uint32_t i_num_lanes,
        const uint64_t i_fld_data)
{
    const uint32_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    FAPI_DBG("Begin");
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;

    for (uint64_t l_lane = 0; l_lane < i_num_lanes; ++l_lane)
    {
        l_addr = i_reg_base_addr | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
        FAPI_TRY(fapi2::getScom(i_target, l_addr, l_data));
        FAPI_TRY(l_data.insertFromRight(i_fld_data, i_reg_start, i_reg_len));
        FAPI_TRY(fapi2::putScom(i_target, l_addr, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Check OMI init dones
///
/// @param[in] i_omi_target OMI target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_io_omi_poll_init_done(const fapi2::Target<fapi2::TARGET_TYPE_OMI>& i_omi_target)
{
    FAPI_DBG("Begin");
    using namespace scomt::omi;
    const uint32_t SCOM_LANE_SHIFT = 32;
    const uint64_t SCOM_LANE_MASK  = 0x0000001F00000000;
    fapi2::buffer<uint64_t> l_data = 0;
    uint64_t l_addr = 0x0;
    uint32_t l_num_lanes = P10_IO_LIB_NUMBER_OF_OMI_LANES;

    bool l_done = false;

    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_omi_target, l_tgt_str, sizeof(l_tgt_str));

    //Poll for done
    const int POLLING_LOOPS = 10000;

    for (int l_try = 0; l_try < POLLING_LOOPS && !l_done; l_try++)
    {
        FAPI_DBG("Loop %d / %d on %s", l_try, POLLING_LOOPS, l_tgt_str);
        l_done = true;

        for (uint64_t l_lane = 0; l_lane < l_num_lanes; ++l_lane)
        {
            // rx_phy_dl_init_done
            //  rx_datasm_cntl1_pl
            l_addr = RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL | ((l_lane << SCOM_LANE_SHIFT) & SCOM_LANE_MASK);
            FAPI_TRY(fapi2::getScom(i_omi_target, l_addr, l_data));

            uint64_t l_init_done = 0;
            FAPI_TRY(l_data.extractToRight(l_init_done, RXCTL_DATASM_0_PLREGS_RX_CNTL1_PL_INIT_DONE, 1));

            if (l_init_done == 0x0)
            {
                FAPI_DBG("%s Lane %d is not done with initial training.", l_tgt_str, l_lane);
                l_done = false;
                break;
            }

        }

        if (l_done)
        {
            break;
        }
        else
        {
            fapi2::delay(1000000, 10000000);
        }
    }

    // Avoid failing in Simics until the models get updated
    if( !l_done )
    {
        FAPI_ERR("OMI PHY Init Done Timeout on %s", l_tgt_str);

        fapi2::ATTR_IS_SIMICS_Type l_simics;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMICS, FAPI_SYSTEM, l_simics),
                 "Error from FAPI_ATTR_GET (ATTR_IS_SIMICS)");

        if( l_simics == fapi2::ENUM_ATTR_IS_SIMICS_SIMICS )
        {
            FAPI_INF("p10_io_omi_poll_init_done> Skipping timeout in Simics");
            l_done = true;
        }
    }

    FAPI_ASSERT(l_done,
                fapi2::P10_IO_OMI_POLL_INIT_DONE_TIMEOUT_ERROR()
                .set_TARGET(i_omi_target),
                "Timeout waiting on io init done to complete");
fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Cleared PPE Error Valid
/// @param[in] i_pauc_target    PAUC target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_clear_error_valid(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target)
{
    FAPI_DBG("Begin");
    p10_io_lib l_proc;
    FAPI_TRY(l_proc.clear_error_valid(i_pauc_target));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

/// @brief Cleared PPE Error Valid
/// @param[in] i_pauc_target    PAUC target
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_lib::clear_error_valid(const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target)
{
    FAPI_DBG("Begin");
    FAPI_TRY(p10_io_ppe_ppe_error_valid.putData(i_pauc_target, 0, true));

    FAPI_TRY(p10_io_ppe_img_regs.flush());


fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_iohs_phy_get_action_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_iohs_phy_get_action_state(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    bool& o_data)
{
    FAPI_DBG("Start");
    using namespace scomt::pauc;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_data(0x0);

    FAPI_TRY(GET_PHY_PPE_WRAP_SCOM_WORK_REG1(l_pauc_target, l_data));

    if (l_data.getBit<0>())
    {
        o_data = true;
    }
    else
    {
        o_data = false;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_iohs_phy_set_action_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_iohs_phy_set_action_state(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target,
    const bool& i_data)
{
    FAPI_DBG("Start");
    using namespace scomt::pauc;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_data(0x0);

    FAPI_TRY(GET_PHY_PPE_WRAP_SCOM_WORK_REG1(l_pauc_target, l_data));

    if (i_data)
    {
        l_data.setBit<0>();
    }
    else
    {
        l_data.clearBit<0>();
    }

    FAPI_TRY(PUT_PHY_PPE_WRAP_SCOM_WORK_REG1(l_pauc_target, l_data));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_iohs_phy_poll_action_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_iohs_phy_poll_action_state(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_target)
{
    FAPI_DBG("Start");
    using namespace scomt::pauc;
    const uint32_t C_MAX_LOOPS = 6000; // 60 seconds
    const uint32_t C_HW_NS_DELAY = 10000000; // 10ms
    const uint32_t C_SIM_CYCLE_DELAY = 1000;
    uint32_t l_loops = 0;
    auto l_pauc_target = i_target.getParent<fapi2::TARGET_TYPE_PAUC>();
    fapi2::buffer<uint64_t> l_data(0x0);

    // Wait for action to complete
    for(; l_loops < C_MAX_LOOPS; l_loops++)
    {
        FAPI_TRY(GET_PHY_PPE_WRAP_SCOM_WORK_REG1(l_pauc_target, l_data));

        if(l_data.getBit<1>() == 0)
        {
            break;
        }

        FAPI_TRY(fapi2::delay(C_HW_NS_DELAY, C_SIM_CYCLE_DELAY),
                 "fapiDelay error");
    }

    FAPI_ASSERT(l_loops < C_MAX_LOOPS,
                fapi2::P10_IOHS_POLL_ACTION_STATE_ERROR()
                .set_IOHS_TARGET(i_target)
                .set_PAUC_TARGET(l_pauc_target),
                "IOHS Timeout waiting for PHY Action to Complete...");


fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
