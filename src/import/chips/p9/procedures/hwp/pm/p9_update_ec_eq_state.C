/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_update_ec_eq_state.C $ */
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
//          and EQ chiplets)
///     - MC group 1 (using EC MC register @2)  - All good cores (EC only)
///  - Use the functional state to find all good cores
///  -ÅWrite the good core and quad mask into OCC CCSR and QCSR respectively
///         These become the "master record " of the enabled cores/quad in
///         the system for runtime
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include "p9_update_ec_eq_state.H"

// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------
static fapi2::ReturnCode update_ec_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

static fapi2::ReturnCode update_eq_config(
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
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_data64 = 0;

    FAPI_IMP("> p9_update_ec_eq_state");

    FAPI_TRY(update_ec_config(i_target),
             "Error update_core_config detected");

    FAPI_TRY(update_eq_config(i_target),
             "Error update_cache_config detected");


    //If this is NOT the master processor then need to set
    //the default value the OCC Quad Status Status Register
    //As the SBE doesn't do this on the slave chips
    FAPI_TRY(fapi2::getScom(i_target, PU_OCB_OCI_QSSR_SCOM, l_data64));

    if(l_data64() == 0x0)
    {
        l_data64.setBit<0, 12>();       // L2 Stopped
        l_data64.setBit<14, 6>();      // Quad Stopped
        FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_QSSR_SCOM2, l_data64));
    }


fapi_try_exit:
    FAPI_INF("< p9_update_ec_eq_state");

    return fapi2::current_err;
} // END p9_update_ec_eq_state


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
        FAPI_DBG("  Checking if present EC %d is functional",
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
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_CCSR_SCOM2, l_core_config),
             "Error writing to CCSR");


fapi_try_exit:
    FAPI_INF("< update_core_config...");
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
    FAPI_TRY(fapi2::putScom(i_target, PU_OCB_OCI_QCSR_SCOM2, l_ex_config),
             "Error writing to CCSR");

fapi_try_exit:
    FAPI_INF("< update_cache_config");
    return fapi2::current_err;

} // END p9_update_ec_eq_state
