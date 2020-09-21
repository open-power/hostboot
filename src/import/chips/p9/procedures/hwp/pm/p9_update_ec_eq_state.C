/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_update_ec_eq_state.C $ */
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
/// @file p9_update_ec_eq_state.H
/// @brief Update the "permanent" multicast groups  reflect any additional
///          deconfigured by Hostboot
///
// *HWP HWP Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 2
// *HWP Consumed by: SBE
///
///
///
/// High-level procedure flow:
/// @verbatim
///  - Update the "permanent" multicast groups  reflect any additional
///        deconfiguration by Hostboot.
///     - MC group 0 (using MC register #1) - All good chiplets (deal with EC
///          and EQ chiplets)
///     - MC group 1 (using EC MC register @2)  - All good cores (EC only)
///  - Use the functional state to find all good cores
///  -Write the good core and quad mask into OCC CCSR and QCSR respectively
///         These become the "master record " of the enabled cores/quad in
///         the system for runtime
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include "p9_update_ec_eq_state.H"

#define PERV_TO_CORE_POS_OFFSET 0x20
#define PERV_TO_EQ_POS_OFFSET 0x10
enum P9_HCD_L2_STOPCLOCKS_CONSTANTS
{
    CACHE_L2_CLK_SYNC_POLLING_HW_NS_DELAY     = 10000,
    CACHE_L2_CLK_SYNC_POLLING_SIM_CYCLE_DELAY = 320000,
    CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY     = 10000,
    CACHE_L2_CLK_STOP_POLLING_SIM_CYCLE_DELAY = 320000
};
enum P9_HCD_CORE_STOPCLOCKS_CONSTANTS
{
    CORE_PCB_MUX_POLLING_HW_NS_DELAY      = 10000,
    CORE_PCB_MUX_POLLING_SIM_CYCLE_DELAY  = 320000,
    CORE_CLK_SYNC_POLLING_HW_NS_DELAY     = 10000,
    CORE_CLK_SYNC_POLLING_SIM_CYCLE_DELAY = 320000,
    CORE_CLK_STOP_POLLING_HW_NS_DELAY     = 10000,
    CORE_CLK_STOP_POLLING_SIM_CYCLE_DELAY = 320000
};
enum P9_HCD_CACHE_STOPCLOCKS_CONSTANTS
{
    CACHE_CLK_STOP_POLLING_HW_NS_DELAY     = 10000,
    CACHE_CLK_STOP_POLLING_SIM_CYCLE_DELAY = 320000,
};

enum
{
    FSM_IDLE_POLLING_HW_NS_DELAY = 500,
    FSM_IDLE_POLLING_SIM_CYCLE_DELAY = 320000,
    PB_PURGE_CACHE_STOP_POLLING_DELAY_HW_MILLISEC = 1000000ULL, // 1msec
    PB_PURGE_CACHE_STOP_POLLING_DELAY_SIM_CYCLES = 10000ULL,
    PB_PURGE_CACHE_STOP_POLLING_TIMEOUT = 10,
    CORE_QUEISCE_TIMEOUT_LOOP = 500,
};


#define CLK_REGION_ALL_BUT_PLL  0x0ffc000000000000
#define CLK_REGION_ALL          0x0ffe000000000000
#define CLK_STOP_CMD            0x8000000000000000
#define CLK_THOLD_ALL           0x000000000000e000
// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

static fapi2::ReturnCode update_eq_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode p9_check_core_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    uint8_t i_core_unit_pos,
    uint8_t i_ex_unit_pos);


fapi2::ReturnCode p9_check_quad_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_quad_target,
    uint8_t i_quad_unit_pos);

fapi2::ReturnCode p9_check_ex_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    uint8_t i_ex_unit_pos);

fapi2::ReturnCode verify_eq_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

template< fapi2::TargetType K >
inline fapi2::ReturnCode set_mc_group(
    const fapi2::Target<K>& i_target,
    const uint32_t          i_reg_address,
    const uint32_t          i_group)
{
    FAPI_INF("<< set_mc_group" );

    fapi2::buffer<uint64_t> l_data64 = 0;
    uint32_t l_present_mc_group = 0x7;

    // Get MULTICAST_GROUP register
    FAPI_TRY(fapi2::getScom(i_target, i_reg_address, l_data64));
    l_data64.extractToRight<3, 3>(l_present_mc_group);
    FAPI_DBG("  l_present_mc_group %X", l_present_mc_group);

    if (l_present_mc_group != i_group)
    {
        // Entering group
        l_data64.insertFromRight<0, 3>(0x7);
        l_data64.insertFromRight<3, 3>(i_group);
        // Removed group
        l_data64.insertFromRight<19, 3>(l_present_mc_group);

        FAPI_TRY(fapi2::putScom(i_target, i_reg_address, l_data64));
    }

fapi_try_exit:
    FAPI_INF("<< set_mc_group" );
    return fapi2::current_err;
}

// template<>
// inline fapi2::ReturnCode set_mc_group(
//     const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
//     const uint32_t          i_reg_address,
//     const uint32_t          i_group);
//
//
// template<>
// inline fapi2::ReturnCode set_mc_group(
//     const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
//     const uint32_t          i_reg_address,
//     const uint32_t          i_group);
//
// template<>
// inline fapi2::ReturnCode set_mc_group(
//     const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_target,
//     const uint32_t          i_reg_address,
//     const uint32_t          i_group);

// -----------------------------------------------------------------------------
//  Constants
// -----------------------------------------------------------------------------
static const uint8_t CORE_CHIPLET_START     = 0x20;
static const uint8_t CORE_CHIPLET_COUNT     = 24;

static const uint8_t ALL_FUNCTIONAL_CHIPLETS_GROUP  = 0;
static const uint8_t ALL_CORES_GROUP                = 1;
static const uint8_t CORE_STOP_MC_GROUP             = 3;
static const uint8_t EQ_STOP_MC_GROUP               = 4;
static const uint8_t EX_EVEN_STOP_MC_GROUP          = 5;
static const uint8_t EX_ODD_STOP_MC_GROUP           = 6;
static const uint8_t BROADCAST_GROUP                = 7;

// See .H for documentation
fapi2::ReturnCode p9_update_ec_eq_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t i_qssr_skip)
{
    fapi2::buffer<uint64_t> l_data64 = 0;
    uint8_t l_is_master_chip = 0;

    FAPI_IMP("> p9_update_ec_eq_state");

    FAPI_TRY(update_ec_config(i_target),
             "Error update_core_config detected");

    FAPI_TRY(update_eq_config(i_target),
             "Error update_cache_config detected");

// Remove to keep from accessing a deconfigured core or quad
//    FAPI_TRY(verify_eq_ec_hw_state(i_target));

    //Check PROC_SBE_MASTER attr to see if this is master proc
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target, l_is_master_chip))

    if(l_is_master_chip == 0x0 && !i_qssr_skip)
    {
        l_data64.setBit<0, 12>();       // L2 Stopped
        l_data64.setBit<14, 6>();      // Quad Stopped
        FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_QSSR_SCOM2, l_data64));
    }


fapi_try_exit:
    FAPI_INF("< p9_update_ec_eq_state");

    return fapi2::current_err;
} // END p9_update_ec_eq_state

fapi2::ReturnCode verify_eq_ec_hw_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF (">>verify_hw_state");
    uint8_t l_present_core_unit_pos;
    uint8_t l_functional_core_unit_pos;

    uint8_t l_present_quad_unit_pos;
    uint8_t l_functional_quad_unit_pos;
    uint8_t l_quad_match = 0;
    uint8_t l_core_match = 0;
    std::vector <fapi2::Target<fapi2::TARGET_TYPE_EX>> l_ex_list;
    uint8_t l_ex_pos = 0;
    uint8_t l_repeat_ex_pos = 0xFF;

    //Get the perv target lists
    auto l_perv_core_target_vector = i_target.getChildren<fapi2::TARGET_TYPE_PERV>(
                                         fapi2::TARGET_FILTER_ALL_CORES, fapi2::TARGET_STATE_FUNCTIONAL);

    auto l_perv_quad_target_vector = i_target.getChildren<fapi2::TARGET_TYPE_PERV>(
                                         fapi2::TARGET_FILTER_ALL_CACHES, fapi2::TARGET_STATE_FUNCTIONAL);

    //Get the functional lists
    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    auto l_quad_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    //Verify Core state
    for (auto core_present_it : l_perv_core_target_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                core_present_it,
                                l_present_core_unit_pos));

        l_present_core_unit_pos = l_present_core_unit_pos - PERV_TO_CORE_POS_OFFSET;
        l_core_match = 1;

        FAPI_INF("Present core %d ", l_present_core_unit_pos);

        for (auto core_functional_it : l_core_functional_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    core_functional_it,
                                    l_functional_core_unit_pos));
            FAPI_INF("  Functional EC %d",
                     l_functional_core_unit_pos);

            if (l_functional_core_unit_pos == l_present_core_unit_pos)
            {
                l_core_match = 1;
                break;
            }
            else
            {
                l_core_match = 0;
            }
        }//end of functional

        if (!l_core_match)
        {
            for ( auto l_core_target : core_present_it.getChildren<fapi2::TARGET_TYPE_CORE>(fapi2::TARGET_STATE_PRESENT) )
            {
                uint8_t l_ex_pos = 0;
                auto l_ex_target = l_core_target.getParent<fapi2::TARGET_TYPE_EX>();

                FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                        l_ex_target,
                                        l_ex_pos));
                FAPI_INF("  EX %d Core %d",
                         l_ex_pos, l_present_core_unit_pos);

                if (!l_ex_target.isFunctional())
                {
                    l_ex_list.push_back(l_ex_target);
                }

                //Check the clock state and power state
                FAPI_TRY(p9_check_core_clock_power_state(l_core_target, l_ex_target,
                         l_present_core_unit_pos, l_ex_pos));

            }
        }
    }//end of present

    //Verify ex chiplets
    for (auto l_ex = l_ex_list.begin(); l_ex != l_ex_list.end(); l_ex++)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                *l_ex,
                                l_ex_pos));

        if (l_repeat_ex_pos == 0xFF)
        {
            l_repeat_ex_pos = l_ex_pos;
        }
        else
        {
            if (l_repeat_ex_pos == l_ex_pos)
            {
                l_repeat_ex_pos = 0xFF;
                continue;
            }
        }

        FAPI_INF("Verify EX %d clock/power state", l_ex_pos);
        //Check the clock state and power state
        FAPI_TRY(p9_check_ex_clock_power_state(*l_ex,
                                               l_ex_pos));

    }



    //Verify quad states
    for (auto quad_present_it : l_perv_quad_target_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                quad_present_it,
                                l_present_quad_unit_pos));

        l_present_quad_unit_pos = l_present_quad_unit_pos - PERV_TO_EQ_POS_OFFSET;

        l_quad_match = 1;

        for (auto quad_functional_it : l_quad_functional_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    quad_functional_it,
                                    l_functional_quad_unit_pos));
            FAPI_INF("  Functional EQ %d present EQ %d",
                     l_functional_quad_unit_pos, l_present_quad_unit_pos);

            if (l_functional_quad_unit_pos == l_present_quad_unit_pos)
            {
                l_quad_match = 1;
                break;
            }
            else
            {
                l_quad_match = 0;
            }
        }//end of functional

        if (!l_quad_match)
        {
            for ( auto l_quad_target : quad_present_it.getChildren<fapi2::TARGET_TYPE_EQ>(fapi2::TARGET_STATE_PRESENT) )
            {
                //Check the clock state and power state
                FAPI_TRY(p9_check_quad_clock_power_state(l_quad_target,
                         l_present_quad_unit_pos));
            }
        }
    }


fapi_try_exit:
    FAPI_INF("< update_core_config...");
    return fapi2::current_err;

}

/// @brief Update multicast groups and the CCSR for cores
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("> update_core_config...");

    uint8_t l_present_core_unit_pos;
    uint8_t l_functional_core_unit_pos;
    fapi2::buffer<uint64_t> l_core_config = 0;

    auto l_core_present_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_PRESENT);

    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_INF("  Number of present cores = %d; Number of functional cores = %d",
             l_core_present_vector.size(),
             l_core_functional_vector.size());

    // For each present core,  set multicast groups and the CCSR
    for (auto core_present_it : l_core_present_vector)
    {
        bool b_core_functional = false;

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                core_present_it,
                                l_present_core_unit_pos));
        l_present_core_unit_pos = l_present_core_unit_pos % fapi2::TARGET_FILTER_CORE0;

        FAPI_INF("  Checking if present EC %d is functional",
                 l_present_core_unit_pos);

        for (auto core_functional_it : l_core_functional_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    core_functional_it,
                                    l_functional_core_unit_pos));
            FAPI_DBG("  Functional EC %d",
                     l_functional_core_unit_pos);

            if (l_functional_core_unit_pos == l_present_core_unit_pos)
            {

                // Set this core into the multicast groups.  These should already
                // be set but we won't assume anything

                // Read the MC register 1 to determine if in MC 0.  If already
                // in the group, leave it there.  If not in group 0, add it
                // while removing it from the group that it is presently in (eg
                // as found in bits 3:5)

                FAPI_INF("  Setting EC %d into MC group 0 (All chiplets)",
                         l_present_core_unit_pos);
                FAPI_TRY(set_mc_group(  core_functional_it,
                                        C_MULTICAST_GROUP_1,
                                        ALL_FUNCTIONAL_CHIPLETS_GROUP));

                // Read the MC register 2 to determine if in MC 1.  If already
                // in the group, leave it there.  If not in group 1, add it
                // while removing it from the group that it is presently in (eg
                // as found in bits 3:5)

                FAPI_INF("  Setting EC %d into MC group 1 (All core chiplets)",
                         l_present_core_unit_pos);
                FAPI_TRY(set_mc_group(  core_functional_it,
                                        C_MULTICAST_GROUP_2,
                                        ALL_CORES_GROUP));

                // Set the appropriate bit in the Core Configuration Status
                // Register buffer
                FAPI_INF("  Setting EC %d as good in value to be written to CCSR",
                         l_present_core_unit_pos);
                l_core_config.setBit(l_present_core_unit_pos);

                b_core_functional = true;

                break;
            }  // Current core
        } // Functional core loop

        // If not functional, clear the core chiplet out of all multicast groups
        // As the chiplet is not functional, it can only addressed with the chip
        // target, not a core target
        if (!b_core_functional)
        {

            // Clearing from the ALL chiplets group (multicast group 0) using
            // MULTICAST_GROUP_1 register
            uint32_t address = C_MULTICAST_GROUP_1 +
                               0x01000000 * l_present_core_unit_pos;
            FAPI_INF("  Removing EC %d from MC group 0 (All chiplets)",
                     l_present_core_unit_pos);
            FAPI_TRY(set_mc_group(  i_target,
                                    address,
                                    BROADCAST_GROUP));

            // Clearing from the good cores (multicast group 1) using
            // MULTICAST_GROUP_2 register

            address = C_MULTICAST_GROUP_2 +
                      0x01000000 * l_present_core_unit_pos;
            FAPI_INF("  Removing EC %d from MC group 1 (All core chiplets)",
                     l_present_core_unit_pos);
            FAPI_TRY(set_mc_group(  i_target,
                                    address,
                                    BROADCAST_GROUP));

            // The Core Configuration Status Register buffer bit is already clear

        }  // Non functional cores
    }  // Present core loop

    // Write the recalculated OCC Core Configuration Status Register
    FAPI_INF("  Writing OCC CCSR");
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_CCSR_SCOM, l_core_config),
             "Error writing to CCSR");


fapi_try_exit:
    FAPI_INF("< update_core_config...");
    return fapi2::current_err;

}

fapi2::ReturnCode p9_check_core_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_core_target,
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    uint8_t i_core_unit_pos,
    uint8_t i_ex_unit_pos)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t               l_loops1ms;
    uint8_t l2_quiesce_state = 0;

    do
    {
        //Check the Power state
        FAPI_INF(" Check core is powered off");
        FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_PPM_PFSNS, l_data),
                 "Error reading P9N2_C_PPM_PFSNS");

        if (l_data.getBit<1>())
        {
            FAPI_INF ("Clear Poweron bit in VDMCR");

            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_CPPM_CPMMR_SCOM1, l_data),
                     "Error writing to P9N2_C_CPPM_CPMMR_SCOM1");
            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_PPM_VDMCR_CLEAR, l_data),
                     "Error writing to P9N2_C_PPM_VDMCR_CLEAR");

            break; //power is off
        }

        l_data.flush<0>().setBit<0>();
        FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_CPPM_CPMMR_SCOM1, l_data),
                 "Error writing to P9N2_C_CPPM_CPMMR_SCOM1");

        FAPI_INF("Assert core-L2 + core-CC quiesces via SICR[6/7,8/9]");

        if (i_core_unit_pos % 2)
        {
            l_data.flush<0>().setBit<P9N2_EX_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C1>().
            setBit<P9N2_EX_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C1>();
        }
        else
        {
            l_data.flush<0>().setBit<P9N2_EX_CME_SCOM_SICR_PCC_CORE_INTF_QUIESCE_C0>().
            setBit<P9N2_EX_CME_SCOM_SICR_L2_CORE_INTF_QUIESCE_C0>();
        }

        FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_CME_SCOM_SICR_SCOM2, l_data),
                 "Error writing to P9N2_EX_CME_SCOM_SICR_SCOM2");

        FAPI_INF("Poll for L2 interface quiesced via SISR[30/31]");
        l_loops1ms = CORE_QUEISCE_TIMEOUT_LOOP;

        do
        {

            FAPI_TRY(fapi2::delay(PB_PURGE_CACHE_STOP_POLLING_DELAY_HW_MILLISEC,
                                  PB_PURGE_CACHE_STOP_POLLING_DELAY_SIM_CYCLES),
                     "Error from delay"); //1msec delay

            FAPI_TRY(fapi2::getScom(i_ex_target, P9N2_EX_CME_LCL_SISR_SCOM, l_data),
                     "Error reading to P9N2_EX_CME_LCL_SISR_SCOM");

            if (i_core_unit_pos % 2)
            {
                l2_quiesce_state = l_data.getBit<31>();
            }
            else
            {
                l2_quiesce_state = l_data.getBit<30>();
            }

        }
        while (!l2_quiesce_state && l_loops1ms -- != 0);

        if (!l2_quiesce_state)
        {
            FAPI_ASSERT(false,
                        fapi2::CORE_QUIESCES_INTF_FAILED()
                        .set_CORE_TARGET(i_core_target)
                        .set_CORE_POS(i_core_unit_pos)
                        .set_EX_TARGET(i_ex_target)
                        .set_EX_POS(i_ex_unit_pos),
                        "Core QUIESCES failed");
        }


        FAPI_INF(" Check core %d clock is stopped via CLOCK_STAT_SL[4-13]", i_core_unit_pos);
        FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_CLOCK_STAT_SL, l_data),
                 "Error reading P9N2_C_CLOCK_STAT_SL");

        if ((~l_data & CLK_REGION_ALL_BUT_PLL) != 0)
        {
            l_data.flush<0>().setBit<18>();
            FAPI_INF("Assert core chiplet fence via NET_CTRL0[18]");
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_C_NET_CTRL0_WOR");

            l_data.flush<0>();
            FAPI_INF("Clear SCAN_REGION_TYPE prior to stop core clocks");
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_SCAN_REGION_TYPE, l_data),
                     "Error writing to P9N2_C_SCAN_REGION_TYPE");

            FAPI_INF("Stop Core Clocks via CLK_REGION");
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_CLK_REGION,
                                    (CLK_STOP_CMD | CLK_REGION_ALL_BUT_PLL | CLK_THOLD_ALL)),
                     "Error writing to P9N2_C_CLK_REGION");

            FAPI_INF("Poll for core clocks stopped via CPLT_STAT0[8]");
            l_loops1ms = 0x1E6 / CORE_CLK_STOP_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CORE_CLK_STOP_POLLING_HW_NS_DELAY,
                             CORE_CLK_STOP_POLLING_SIM_CYCLE_DELAY);

                FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_CPLT_STAT0, l_data),
                         "Error reading P9N2_C_CPLT_STAT0");

            }
            while ((l_data.getBit<8>() != 1) && ((--l_loops1ms) != 0));


            FAPI_INF(" Check core %d clock is stopped via CLOCK_STAT_SL[4-13]", i_core_unit_pos);
            FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_CLOCK_STAT_SL, l_data),
                     "Error reading P9N2_C_CLOCK_STAT_SL");

            if ((~l_data & CLK_REGION_ALL_BUT_PLL) != 0)
            {
                FAPI_ERR("Core %d Clock Stop Failed", i_core_unit_pos);
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CORE_CLOCK_STOP_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CORE_TARGET(i_core_target)
                                   .set_CORE_POS(i_core_unit_pos),
                                   "Core clock is still on");
            }

            FAPI_DBG("Drop core clock sync enable via CPPM_CACCR[15]");
            l_data.flush<0>().setBit<15>();
            FAPI_TRY(putScom(i_core_target, P9N2_C_CPPM_CACCR_CLEAR, l_data));

            FAPI_DBG("Poll for core clock sync done to drop via CPPM_CACSR[13]");
            l_loops1ms = 1E6 / CORE_CLK_SYNC_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CORE_CLK_SYNC_POLLING_HW_NS_DELAY,
                             CORE_CLK_SYNC_POLLING_SIM_CYCLE_DELAY);

                FAPI_TRY(getScom(i_core_target, P9N2_C_CPPM_CACSR, l_data));
            }
            while((l_data.getBit<13>() == 1) && ((--l_loops1ms) != 0));

            if (l_data.getBit<13>())
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CORE_CLOCKSYNC_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CORE_TARGET(i_core_target)
                                   .set_CORE_POS(i_core_unit_pos),
                                   "Core clock sync is not dropped");
            }

            FAPI_INF("Core clock sync done dropped");

            l_data.flush<0>();
            FAPI_TRY(putScom(i_core_target, P9N2_C_PPM_CGCR, l_data));

            FAPI_INF("Assert skew sense to skew adjust fence via NET_CTRL0[22]");
            l_data.flush<0>().setBit<22>();
            FAPI_TRY(putScom(i_core_target, P9N2_C_NET_CTRL0_WOR, l_data));

            FAPI_INF("Drop ABIST_SRAM_MODE_DC to support ABIST Recovery via BIST[1]");
            FAPI_TRY(getScom(i_core_target, P9N2_C_BIST, l_data));
            l_data.clearBit<1>();
            FAPI_TRY(putScom(i_core_target, P9N2_C_BIST, l_data));

            FAPI_INF("Assert vital fence via CPLT_CTRL1[3]");
            l_data.flush<0>().setBit<3>();
            FAPI_TRY(putScom(i_core_target, P9N2_C_CPLT_CTRL1_OR, l_data));

            FAPI_INF("Assert regional fences via CPLT_CTRL1[4-14]");
            FAPI_TRY(putScom(i_core_target, P9N2_C_CPLT_CTRL1_OR, CLK_REGION_ALL));

        }
        else
        {
            FAPI_INF("Core %d clock is off", i_core_unit_pos);
        }

        //Check the Power state
        FAPI_INF(" Check core is powered off");
        FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_PPM_PFSNS, l_data),
                 "Error reading P9N2_C_PPM_PFSNS");

        if (!l_data.getBit<1>())
        {
            FAPI_INF("Assert PCB fence, electrical fence,vital thold via NET_CTRL0");
            l_data.flush<0>().setBit<25>().setBit<26>().setBit<16>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_C_NET_CTRL0_WOR");

            FAPI_INF ("Clear Poweron bit in VDMCR");
            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_PPM_VDMCR_CLEAR, l_data),
                     "Error writing to P9N2_C_PPM_VDMCR_CLEAR");

            FAPI_INF("Drop vdd_pfet_val/sel_override/regulation_finger_en via PFCS[4,5,8]");
            l_data.flush<0>().setBit<4>().setBit<5>().setBit<8>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_PPM_PFCS_SCOM1, l_data),
                     "Error writing to P9N2_C_PPM_PFCS_SCOM1");

            FAPI_INF("Power off core VDD via PFCS[0-1]");
            l_data.flush<0>().setBit<1>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_PPM_PFCS_SCOM2, l_data),
                     "Error writing to P9N2_C_PPM_PFCS_SCOM2");

            FAPI_INF("Poll for vdd_pfets_disabled_sense via PFSNS[1]");
            l_loops1ms = 0x1E6 / FSM_IDLE_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(FSM_IDLE_POLLING_HW_NS_DELAY,
                             FSM_IDLE_POLLING_SIM_CYCLE_DELAY);
                FAPI_TRY(fapi2::getScom(i_core_target, P9N2_C_PPM_PFSNS, l_data),
                         "Error reading P9N2_C_PPM_PFSNS");
            }
            while(!l_data.getBit<1>() && ((--l_loops1ms) != 0));

            if (!l_data.getBit<1>())
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::CORE_CLOCK_POWEROFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_CORE_TARGET(i_core_target)
                                   .set_CORE_POS(i_core_unit_pos),
                                   "Core power off failed");
            }


            FAPI_INF("Turn off force voff via PFCS[0-1]");
            l_data.flush<0>().setBit<0, 2>();
            FAPI_TRY(fapi2::putScom(i_core_target, P9N2_C_PPM_PFCS_SCOM1, l_data),
                     "Error writing to P9N2_C_PPM_PFCS_SCOM1");

        }
        else
        {
            FAPI_INF("Core %d is powered off", i_core_unit_pos);
        }
    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p9_check_core_clock_power_state...");
    return fapi2::current_err;

}
fapi2::ReturnCode p9_check_ex_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EX>& i_ex_target,
    uint8_t i_ex_unit_pos)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint8_t l_ex_pos = i_ex_unit_pos % 2;
    uint8_t l2_clock_stat_val = 0;
    uint64_t l2_region_clk = 0;
    uint64_t l3_region_clk = 0;
    uint8_t l3_clock_stat_val = 0;
    uint64_t l2_ring_fence_mask = 0;
    uint64_t l3_ring_fence_mask = 0;
    uint32_t               l_loops1ms;
    uint8_t l2_clock_sync_val;
    uint32_t l_timeout;
    uint8_t l_eq_pos = 0;
    uint64_t l_qssr_data = 0;

    do
    {
        auto l_eq_target = i_ex_target.getParent<fapi2::TARGET_TYPE_EQ>();
        auto l_proc_chip = l_eq_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                l_eq_target,
                                l_eq_pos));
        //Check the Power state
        FAPI_INF(" Check cache %d is powered off", l_eq_pos);
        FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_PPM_PFSNS, l_data),
                 "Error reading P9N2_EQ_PPM_PFSNS");

        FAPI_INF("P9N2_EQ_PPM_PFSNS %08x", l_data >> 32);

        if (l_data.getBit<1>())
        {

            FAPI_DBG("Set L2 as stopped in QSSR");
            l_qssr_data = 1;
            l_qssr_data = l_qssr_data << ((11 - i_ex_unit_pos) + 52);
            l_data = l_qssr_data;
            FAPI_TRY(fapi2::putScom(l_proc_chip, P9N2_PU_OCB_OCI_QSSR_SCOM2,
                                    l_data));
            break;
        }

        FAPI_INF(" Check L2 clock is stopped via CLOCK_STAT_SL[8-9]");
        FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_CLOCK_STAT_SL, l_data),
                 "Error reading P9N2_EQ_CLOCK_STAT_SL");

        if (l_ex_pos)
        {
            l2_region_clk = 0x0040000000000000;
            l3_region_clk = 0x0100000000000000;
            l2_clock_stat_val = l_data.getBit<9>();
            l3_clock_stat_val = l_data.getBit<7>();
            l2_ring_fence_mask = 0x1010000000000000;
            l3_ring_fence_mask = 0x0540000000000000;
        }
        else
        {
            l2_region_clk = 0x0080000000000000;
            l3_region_clk = 0x0200000000000000;
            l2_clock_stat_val = l_data.getBit<8>();
            l3_clock_stat_val = l_data.getBit<6>();
            l2_ring_fence_mask = 0x2020000000000000;
            l3_ring_fence_mask = 0x0A80000000000000;
        }

        if (!l2_clock_stat_val)
        {
            FAPI_INF("Assert L2+NCU purge and NCU tlbie quiesce via SICR[18,21,22]");
            l_data.flush<0>().setBit<18>().setBit<21>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_CME_SCOM_SICR_SCOM2, l_data),
                     "Error writing to P9N2_EX_CME_SCOM_SICR_SCOM2");

            l_data.flush<0>().setBit<22>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_CME_SCOM_SICR_SCOM2, l_data),
                     "Error writing to P9N2_EX_CME_SCOM_SICR_SCOM2");

            FAPI_INF("Poll for purged done via EISR[22,23] then Drop L2+NCU purges via SICR[18,22]");

            l_timeout = PB_PURGE_CACHE_STOP_POLLING_TIMEOUT;

            do
            {
                FAPI_TRY(fapi2::delay(PB_PURGE_CACHE_STOP_POLLING_DELAY_HW_MILLISEC,
                                      PB_PURGE_CACHE_STOP_POLLING_DELAY_SIM_CYCLES),
                         "Error from delay"); //1msec delay

                FAPI_TRY(fapi2::getScom(i_ex_target, P9N2_EX_CME_LCL_EISR_SCOM, l_data),
                         "Error reading to P9N2_EX_CME_LCL_EISR_SCOM");
            }
            while ( !(l_data.getBit<22>() && l_data.getBit<23>()) && (l_timeout-- != 0));

            FAPI_INF("L2 Purge values Bit 22 %d  Bit 23 %d", l_data.getBit<22>(), l_data.getBit<23>());

            if (!(l_data.getBit<22>()))
            {
                FAPI_ERR("Timeout is zero .. L2 purge failed and L2 Purge values Bit 22 %d ",
                         l_data.getBit<22>());
                FAPI_ASSERT(false,
                            fapi2::EX_L2_PURGE_FAILED()
                            .set_EX_TARGET(i_ex_target)
                            .set_EX_POS(i_ex_unit_pos),
                            "EX L2 purge failed");
            }

            if (!(l_data.getBit<23>()))
            {
                FAPI_ERR("Timeout is zero .. NCU purge failed and NCU Purge values Bit 23 %d",
                         l_data.getBit<23>());
                FAPI_ASSERT(false,
                            fapi2::EX_NCU_PURGE_FAILED()
                            .set_EX_TARGET(i_ex_target)
                            .set_EX_POS(i_ex_unit_pos),
                            "EX NCU purge failed");
            }

            l_data.flush<0>().setBit<18, 2>().setBit<22, 2>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_CME_SCOM_SICR_SCOM1, l_data),
                     "Error writing to P9N2_EX_CME_SCOM_SICR_SCOM1");

            FAPI_INF("Drop L2 Snoop(quiesce L2-L3 interface) via EX_PM_L2_RCMD_DIS_REG[0]");
            l_data.flush<0>().setBit(0);
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_PM_L2_RCMD_DIS_REG, l_data),
                     "Error writing to P9N2_EX_PM_L2_RCMD_DIS_REG");


            FAPI_INF("Assert partial bad L2/L3 and stopping/stoped l2 pscom masks via RING_FENCE_MASK_LATCH");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_RING_FENCE_MASK_LATCH_REG, l2_ring_fence_mask),
                     "Error writing to P9N2_EX_RING_FENCE_MASK_LATCH_REG");


            l_data.flush<0>();
            FAPI_INF("Clear SCAN_REGION_TYPE prior to stop L2 clocks");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_SCAN_REGION_TYPE, l_data),
                     "Error writing to P9N2_EX_SCAN_REGION_TYPE");

            FAPI_INF("Stop L2 Clocks via CLK_REGION");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_CLK_REGION,
                                    (CLK_STOP_CMD | CLK_THOLD_ALL | l2_region_clk)),
                     "Error writing to P9N2_C_CLK_REGION");

            FAPI_INF("Poll for L2 clocks stopped via CPLT_STAT0[8]");
            l_loops1ms = 0x1E6 / CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY,
                             CACHE_L2_CLK_STOP_POLLING_SIM_CYCLE_DELAY);
                FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_CPLT_STAT0, l_data),
                         "Error reading P9N2_EX_CPLT_STAT0");
            }
            while ((l_data.getBit<8>() != 1) && ((--l_loops1ms) != 0));


            FAPI_INF("Check L2 clock is stopped via CLOCK_STAT_SL[4-13]");
            FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_CLOCK_STAT_SL, l_data),
                     "Error reading P9N2_EX_CLOCK_STAT_SL");

            if (l_ex_pos)
            {
                l2_clock_stat_val = l_data.getBit<9>();
            }
            else
            {
                l2_clock_stat_val = l_data.getBit<8>();
            }


            if (!l2_clock_stat_val)
            {
                FAPI_ERR("L2 clock %d couldn't stop", i_ex_unit_pos);
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EX_L2_CLOCKOFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EX_TARGET(i_ex_target)
                                   .set_EX_POS(i_ex_unit_pos),
                                   "EX L2 clock off failed");
            }

            FAPI_INF("Drop clock sync enable before switch to refclk via EXCGCR[36/37]");

            if (l_ex_pos)
            {
                l_data.flush<0>().setBit<37>();
            }
            else
            {
                l_data.flush<0>().setBit<36>();
            }

            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_QPPM_EXCGCR_CLEAR, l_data),
                     "Error reading P9N2_EX_CLOCK_STAT_SL");

            FAPI_INF("Poll for clock sync done to drop via QACSR[36/37]");
            l_loops1ms = 1E6 / CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY,
                             CACHE_L2_CLK_STOP_POLLING_SIM_CYCLE_DELAY);


                FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_QPPM_QACSR, l_data),
                         "Error reading P9N2_EQ_QPPM_QACSR");

                if (l_ex_pos)
                {
                    l2_clock_sync_val = l_data.getBit<37>();
                }
                else
                {
                    l2_clock_sync_val = l_data.getBit<36>();
                }

            }
            while(l2_clock_sync_val && (--l_loops1ms) != 0);

            if (l2_clock_sync_val)
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EX_L2_CLOCKSYNC_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EX_TARGET(i_ex_target)
                                   .set_EX_POS(i_ex_unit_pos),
                                   "EX L2 clock sync failed");
            }

            FAPI_INF("Switch glsmux to refclk to save clock grid power via EXCGCR[34/35]");

            if (l_ex_pos)
            {
                l_data.flush<0>().setBit<35>();
            }
            else
            {
                l_data.flush<0>().setBit<34>();
            }

            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_QPPM_EXCGCR_CLEAR, l_data),
                     "Error writing P9N2_EQ_QPPM_EXCGCR_CLEAR");
        }
        else
        {
            FAPI_INF("L2 %d clock is off", i_ex_unit_pos);
        }

        FAPI_INF("Set L2 as stopped in QSSR");
        l_qssr_data = 1;
        l_qssr_data = l_qssr_data << ((11 - i_ex_unit_pos) + 52);
        l_data = l_qssr_data;
        FAPI_TRY(fapi2::putScom(l_proc_chip, P9N2_PU_OCB_OCI_QSSR_SCOM2,
                                l_data));


        FAPI_INF(" Check L3 clock is stopped via CLOCK_STAT_SL[6-7]");

        if (!l3_clock_stat_val)
        {

            FAPI_INF("Drop LCO and Cache Inject prior to purge via EX_L3_MODE_REG1[22]");
            FAPI_TRY(fapi2::getScom(i_ex_target, P9N2_EX_L3_MODE_REG1, l_data),
                     "Error reading to P9N2_EX_L3_MODE_REG1");
            l_data.setBit<P9N2_EX_L3_MODE_REG1_L3_SCOM_CINJ_LCO_DIS>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_L3_MODE_REG1, l_data),
                     "Error writing to P9N2_EX_L3_MODE_REG1");

            FAPI_INF("Halt CHTM[0+1] on EX via HTM_TRIG[1]");
            l_data.flush<0>().setBit<1>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_HTM_TRIG, l_data),
                     "Error writing to P9N2_EX_HTM_TRIG");
            l_data.flush<0>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_HTM_CTRL, l_data),
                     "Error writing to P9N2_EX_HTM_CTRL");
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_HTM_MODE, l_data),
                     "Error writing to P9N2_EX_HTM_MODE");

            FAPI_INF("Disable cme trace array via DEBUG_TRACE_CONTROL[1]");
            l_data.flush<0>().setBit<1>();
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_DEBUG_TRACE_CONTROL, l_data),
                     "Error writing to P9N2_EQ_DEBUG_TRACE_CONTROL");

            FAPI_INF("Assert purge L3");
            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_ex_target, P9N2_EX_L3_PM_PURGE_REG, l_data),
                     "Error writing to P9N2_EX_L3_PM_PURGE_REG");

            FAPI_INF("Poll for purged done ");
            l_timeout = PB_PURGE_CACHE_STOP_POLLING_TIMEOUT;

            do
            {
                FAPI_TRY(fapi2::delay(PB_PURGE_CACHE_STOP_POLLING_DELAY_HW_MILLISEC,
                                      PB_PURGE_CACHE_STOP_POLLING_DELAY_SIM_CYCLES),
                         "Error from delay"); //1msec delay
                FAPI_TRY(fapi2::getScom(i_ex_target, P9N2_EX_L3_PM_PURGE_REG, l_data),
                         "Error writing to EX_CME_LCL_EISR_SCOM");
            }
            while ( (l_data.getBit<P9N2_EX_L3_PM_PURGE_REG_L3_REQ>()) && (l_timeout-- != 0));

            FAPI_INF("L3 Purge values Bit 0 %d",
                     l_data.getBit<P9N2_EX_L3_PM_PURGE_REG_L3_REQ>());

            if (l_data.getBit<P9N2_EX_L3_PM_PURGE_REG_L3_REQ>())
            {
                FAPI_ERR("Timeout is zero .. L3 purge failed Purge values Bit 0 %d ",
                         l_data.getBit<P9N2_EX_L3_PM_PURGE_REG_L3_REQ>());
                FAPI_ASSERT(false,
                            fapi2::EX_L3_PURGE_FAILED()
                            .set_EX_TARGET(i_ex_target)
                            .set_EX_POS(i_ex_unit_pos),
                            "EX L3 purge failed");
            }


            FAPI_INF("Assert partial bad L2/L3 and stopping/stoped l2 pscom masks via RING_FENCE_MASK_LATCH");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_RING_FENCE_MASK_LATCH_REG, l3_ring_fence_mask),
                     "Error writing to P9N2_EX_RING_FENCE_MASK_LATCH_REG");

            l_data.flush<0>();
            FAPI_INF("Clear SCAN_REGION_TYPE prior to stop L3 clocks");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_SCAN_REGION_TYPE, l_data),
                     "Error writing to P9N2_EQ_SCAN_REGION_TYPE");

            FAPI_INF("Stop L3 Clocks via CLK_REGION");
            FAPI_TRY(fapi2::putScom(l_eq_target, P9N2_EQ_CLK_REGION,
                                    (CLK_STOP_CMD | CLK_THOLD_ALL | l3_region_clk)),
                     "Error writing to P9N2_EQ_CLK_REGION");

            FAPI_INF("Poll for L3 clocks stopped via CPLT_STAT0[8]");
            l_loops1ms = 0x1E6 / CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CACHE_L2_CLK_STOP_POLLING_HW_NS_DELAY,
                             CACHE_L2_CLK_STOP_POLLING_SIM_CYCLE_DELAY);
                FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_CPLT_STAT0, l_data),
                         "Error reading P9N2_EX_CPLT_STAT0");
            }
            while ((l_data.getBit<8>() != 1) && ((--l_loops1ms) != 0));


            FAPI_INF("Check L3 clock is stopped via CLOCK_STAT_SL[4-13]");
            FAPI_TRY(fapi2::getScom(l_eq_target, P9N2_EQ_CLOCK_STAT_SL, l_data),
                     "Error reading P9N2_EQ_CLOCK_STAT_SL");

            if (l_ex_pos)
            {
                l3_clock_stat_val = l_data.getBit<7>();
            }
            else
            {
                l3_clock_stat_val = l_data.getBit<6>();
            }

            if (!l3_clock_stat_val)
            {
                FAPI_ERR("L3 clock %d couldn't stop", i_ex_unit_pos);
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EX_L3_CLOCKOFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EX_TARGET(i_ex_target)
                                   .set_EX_POS(i_ex_unit_pos),
                                   "EX L3 clock off failed");
            }
        }
        else
        {
            FAPI_INF("L3 %d clock is off", i_ex_unit_pos);
        }

    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p9_check_ex_clock_power_state...");
    return fapi2::current_err;
}

fapi2::ReturnCode p9_check_quad_clock_power_state(
    const fapi2::Target<fapi2::TARGET_TYPE_EQ>& i_quad_target,
    uint8_t i_cache_unit_pos)
{
    fapi2::buffer<uint64_t> l_data = 0;
    uint32_t               l_loops1ms;
    uint64_t l_qssr_data = 0;
    uint8_t l_loop = 100;

    do
    {
        auto l_proc_chip = i_quad_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
        //Check the Power state
        FAPI_INF(" Check cache is powered off");
        FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_PPM_PFSNS, l_data),
                 "Error reading P9N2_EQ_PPM_PFSNS");

        if (l_data.getBit<1>())
        {
            l_data.flush<0>().setBit<20>().setBit<22>().setBit<24>().setBit<26>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_QPPM_QPMMR_CLEAR, l_data),
                     "Error writing to P9N2_EQ_QPPM_QPMMR_CLEAR");

            FAPI_INF ("Clear Poweron bit in VDMCR");
            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_VDMCR_CLEAR, l_data),
                     "Error writing to P9N2_EQ_PPM_VDMCR_CLEAR");

            FAPI_INF("Set cache as stopped in QSSR");
            l_qssr_data = 1;
            l_qssr_data = l_qssr_data << ((5 - i_cache_unit_pos) + 44);
            l_data = l_qssr_data;
            FAPI_TRY(fapi2::putScom(l_proc_chip, P9N2_PU_OCB_OCI_QSSR_SCOM2,
                                    l_data));

            break;
        }

        FAPI_INF("Assert powerbus purge via QCCR[30]");
        l_data.flush<0>().setBit<30>();
        FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_QPPM_QCCR_SCOM2, l_data));

        FAPI_INF("Poll PowerBus purge done via QCCR[31]");

        do
        {
            FAPI_TRY(fapi2::delay(PB_PURGE_CACHE_STOP_POLLING_DELAY_HW_MILLISEC,
                                  PB_PURGE_CACHE_STOP_POLLING_DELAY_SIM_CYCLES),
                     "Error from delay"); //1msec delay
            FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_QPPM_QCCR_SCOM, l_data));
        }
        while (!l_data.getBit<31>() && (--l_loop != 0));

        if (!l_data.getBit<31>())
        {
            FAPI_ERR(" Power bus purge failed Bit 31 %d", l_data.getBit<31>());
            FAPI_ASSERT(false,
                        fapi2::EQ_POWERBUS_PURGE_FAILED()
                        .set_EQ_TARGET(i_quad_target)
                        .set_EQ_POS(i_cache_unit_pos),
                        "EQ power bus failed");
        }


        FAPI_INF("Drop powerbus purge via QCCR[30]");
        l_data.flush<0>().setBit<30>();
        FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_QPPM_QCCR_SCOM1, l_data));

        l_data.flush<0>().setBit<20>().setBit<22>().setBit<24>().setBit<26>();
        FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_QPPM_QPMMR_CLEAR, l_data),
                 "Error writing to P9N2_EQ_QPPM_QPMMR_CLEAR");

        FAPI_INF(" Check cache clock is stopped via CLOCK_STAT_SL[4-13]");
        FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_CLOCK_STAT_SL, l_data),
                 "Error reading P9N2_EQ_CLOCK_STAT_SL");

        if ((~l_data & CLK_REGION_ALL) != 0)
        {
            FAPI_INF ("Clear Poweron bit in VDMCR");
            l_data.flush<0>().setBit<0>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_VDMCR_CLEAR, l_data),
                     "Error writing to P9N2_EQ_PPM_VDMCR_CLEAR");

            l_data.flush<0>().setBit<18>();
            FAPI_INF("Assert quad chiplet fence via NET_CTRL0[18]");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_EQ_NET_CTRL0_WOR");

            l_data.flush<0>();
            FAPI_INF("Switch glsmux to refclk to save clock grid power via CGCR[3]");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_CGCR, l_data),
                     "Error writing to P9N2_EQ_PPM_CGCR");


            l_data.flush<0>();
            FAPI_INF("Clear SCAN_REGION_TYPE prior to stop cache clocks");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_SCAN_REGION_TYPE, l_data),
                     "Error writing to P9N2_EQ_SCAN_REGION_TYPE");

            FAPI_INF("Stop Cache Clocks via CLK_REGION");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_CLK_REGION,
                                    (CLK_STOP_CMD | CLK_REGION_ALL | CLK_THOLD_ALL)),
                     "Error writing to P9N2_C_CLK_REGION");

            FAPI_INF("Poll for cache clocks stopped via CPLT_STAT0[8]");
            l_loops1ms = 0x1E6 / CACHE_CLK_STOP_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(CACHE_CLK_STOP_POLLING_HW_NS_DELAY,
                             CACHE_CLK_STOP_POLLING_SIM_CYCLE_DELAY);

                FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_CPLT_STAT0, l_data),
                         "Error reading P9N2_EQ_CPLT_STAT0");

            }
            while ((l_data.getBit<8>() != 1) && ((--l_loops1ms) != 0));


            FAPI_INF(" Check cache clock is stopped via CLOCK_STAT_SL[4-13]");
            FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_CLOCK_STAT_SL, l_data),
                     "Error reading P9N2_EQ_CLOCK_STAT_SL");

            if ((~l_data & CLK_REGION_ALL) != 0)
            {
                FAPI_ERR("Cache clock couldn't stop");
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EQ_CLOCKOFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EQ_TARGET(i_quad_target)
                                   .set_EQ_POS(i_cache_unit_pos),
                                   "EQ clock off failed");
            }

            l_data.flush<0>().setBit<3>();
            FAPI_INF("Assert vital fence via CPLT_CTRL1[3]");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_CPLT_CTRL1_OR,
                                    l_data),
                     "Error writing to P9N2_EQ_CPLT_CTRL1_OR");

            FAPI_INF("Assert partial good regional fences via CPLT_CTRL1[4-14]");
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_CPLT_CTRL1_OR,
                                    CLK_REGION_ALL), "Error writing to P9N2_EQ_CPLT_CTRL1_OR");


        }
        else
        {
            FAPI_INF("Cache %d clock is off", i_cache_unit_pos);
        }

        FAPI_INF("Set cache as stopped in QSSR");
        l_qssr_data = 1;
        l_qssr_data = l_qssr_data << ((5 - i_cache_unit_pos) + 44);
        l_data = l_qssr_data;
        FAPI_TRY(fapi2::putScom(l_proc_chip, P9N2_PU_OCB_OCI_QSSR_SCOM2,
                                l_data));

        //Check the Power state
        FAPI_INF(" Check cache is powered off");
        FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_PPM_PFSNS, l_data),
                 "Error reading P9N2_EQ_PPM_PFSNS");

        if (!l_data.getBit<1>())
        {

            FAPI_INF("Assert PCB fence, electrical fence,sram enable, vital thold via NET_CTRL0");
            FAPI_INF("Assert PCB fence via NET_CTRL0[25]");
            l_data.flush<0>().setBit<25>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_EQ_NET_CTRL0_WOR");

            FAPI_INF("Assert electrical fence via NET_CTRL0[26]");
            l_data.flush<0>().setBit<26>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_EQ_NET_CTRL0_WOR");

            FAPI_INF("Drop sram_enable via NET_CTRL0[23]");
            l_data.flush<1>().clearBit<23>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_NET_CTRL0_WAND, l_data),
                     "Error writing to P9N2_EQ_NET_CTRL0_WAND");

            FAPI_INF("Assert vital thold via NET_CTRL0[16]");
            l_data.flush<0>().setBit<16>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_NET_CTRL0_WOR, l_data),
                     "Error writing to P9N2_EQ_NET_CTRL0_WOR");


            FAPI_INF(":Drop vdd/vcs_pfet_val/sel_override/regulation_finger_en via PFCS[4-7,8]");
            l_data.flush<0>().setBit<4, 4>().setBit<8>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_PFCS_SCOM1, l_data),
                     "Error writing to P9N2_EQ_PPM_PFCS_SCOM1");

            FAPI_INF("Power off VCS via PFCS[2-3]");
            l_data.flush<0>().setBit<3>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_PFCS_SCOM2, l_data),
                     "Error writing to P9N2_EQ_PPM_PFCS_SCOM2");

            FAPI_INF("Poll for vcs_pfets_disabled_sense via PFSNS[3]");
            l_loops1ms = 0x1E6 / FSM_IDLE_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(FSM_IDLE_POLLING_HW_NS_DELAY,
                             FSM_IDLE_POLLING_SIM_CYCLE_DELAY);
                FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_PPM_PFSNS, l_data),
                         "Error reading P9N2_EQ_PPM_PFSNS");

            }
            while(!l_data.getBit<3>() && (--l_loops1ms != 0));

            if (!l_data.getBit<3>())
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EQ_VCS_POWEROFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EQ_TARGET(i_quad_target)
                                   .set_EQ_POS(i_cache_unit_pos),
                                   "EQ VCS poweroff failed");
            }

            FAPI_INF("Power off VDD via PFCS[2-3]");
            l_data.flush<0>().setBit<1>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_PFCS_SCOM2, l_data),
                     "Error writing to P9N2_EQ_PPM_PFCS_SCOM2");

            FAPI_INF("Poll for vdd_pfets_disabled_sense via PFSNS[1]");
            l_loops1ms = 0x1E6 / FSM_IDLE_POLLING_HW_NS_DELAY;

            do
            {
                fapi2::delay(FSM_IDLE_POLLING_HW_NS_DELAY,
                             FSM_IDLE_POLLING_SIM_CYCLE_DELAY);

                FAPI_TRY(fapi2::getScom(i_quad_target, P9N2_EQ_PPM_PFSNS, l_data),
                         "Error reading P9N2_EQ_PPM_PFSNS");

            }
            while(!l_data.getBit<1>() && (--l_loops1ms != 0));

            if (!l_data.getBit<1>())
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::EQ_VDD_POWEROFF_FAILED(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                                   .set_EQ_TARGET(i_quad_target)
                                   .set_EQ_POS(i_cache_unit_pos),
                                   "EQ VDD poweroff failed");
            }

            FAPI_INF("Turn off force voff via PFCS[0-3]");
            l_data.flush<0>().setBit<0, 4>();
            FAPI_TRY(fapi2::putScom(i_quad_target, P9N2_EQ_PPM_PFCS_SCOM1, l_data),
                     "Error writing to P9N2_EQ_PPM_PFCS_SCOM1");

        }
        else
        {
            FAPI_INF("Cache %d is powered off", i_cache_unit_pos);
        }
    }
    while(0);

fapi_try_exit:
    FAPI_INF("< p9_check_quad_clock_power_state...");
    return fapi2::current_err;
}


/// @brief Update multicast groups and the QCSR for caches
///
/// @param[in]     i_target   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
static fapi2::ReturnCode update_eq_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("> update_cache_config...");

    uint8_t l_present_eq_unit_pos;
    uint8_t l_present_ex_unit_pos;
    uint8_t l_functional_eq_unit_pos;
    uint8_t l_functional_ex_unit_pos;
    fapi2::buffer<uint64_t> l_ex_config = 0;

    auto l_eq_present_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_PRESENT);

    auto l_eq_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    auto l_ex_present_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EX>
        (fapi2::TARGET_STATE_PRESENT);

    auto l_ex_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EX>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    FAPI_INF("  Number of present cache chiplets = %d; Number of functional cache chiplets = %d",
             l_eq_present_vector.size(),
             l_eq_functional_vector.size());

    FAPI_INF("  Number of functional EX regions = %d",
             l_ex_functional_vector.size());

    // For each functional EQ,  set the multicast groups to match (including
    // removal of the non-functional ones from all groups)
    for (auto eq_present_it : l_eq_present_vector)
    {
        bool b_eq_functional = false;

        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                eq_present_it,
                                l_present_eq_unit_pos));
        FAPI_DBG("  Checking if present EQ %d is functional)",
                 l_present_eq_unit_pos);

        for (auto eq_functional_it : l_eq_functional_vector)
        {

            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    eq_functional_it,
                                    l_functional_eq_unit_pos));

            if (l_functional_eq_unit_pos == l_present_eq_unit_pos)
            {

                // Read the MC register 1 to determine if in MC 0.  If already
                // in the group, leave it there.  If not in group 0, add it
                // while removing it from the group that it is presently in (eg
                // as found in bits 3:5)

                FAPI_INF("  Setting EQ %d into MC group 0 (All chiplets)",
                         l_present_eq_unit_pos);
                FAPI_TRY(set_mc_group(  eq_functional_it,
                                        EQ_MULTICAST_GROUP_1,
                                        ALL_FUNCTIONAL_CHIPLETS_GROUP));

                b_eq_functional = true;
                break;

            }
        }

        // If not functional, clear the eq chiplet out of all multicast groups
        // As the chiplet is not functional, it can only addressed with the chip
        // target, not an EQ target
        if (!b_eq_functional)
        {
            // Clearing from the ALL chiplets group (multicast group 0) using
            // MULTICAST_GROUP_1 register
            uint32_t address =  EQ_MULTICAST_GROUP_1 +
                                0x01000000 * l_present_eq_unit_pos;
            FAPI_DBG("   address = 0x%X", address);
            FAPI_INF("   Remove EQ %d from MC group 0 (All chiplets)",
                     l_present_eq_unit_pos);
            FAPI_TRY(set_mc_group(  i_target,
                                    address,
                                    BROADCAST_GROUP));
        }
    }

    // For each present EX,  set the QCSR
    // This is done last so that hardware is accurate in the event of errors.
    for (auto ex_present_it : l_ex_present_vector)
    {
        FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                ex_present_it,
                                l_present_ex_unit_pos));

        for (auto ex_functional_it : l_ex_functional_vector)
        {

            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    ex_functional_it,
                                    l_functional_ex_unit_pos));

            if (l_functional_ex_unit_pos == l_present_ex_unit_pos)
            {

                // Set the bit in the buffer to written to the hardware
                FAPI_INF("  Setting EX %d as good in value to be written to QCSR",
                         l_present_ex_unit_pos);
                l_ex_config.setBit(l_present_ex_unit_pos);

            }
        }
    }


    // Write the recalculated OCC Quad Configuration Status Register
    FAPI_INF("  Writing OCC QCSR");
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_QCSR_SCOM, l_ex_config),
             "Error writing to CCSR");

fapi_try_exit:
    FAPI_INF("< update_cache_config");
    return fapi2::current_err;

} // END p9_update_ec_eq_state
