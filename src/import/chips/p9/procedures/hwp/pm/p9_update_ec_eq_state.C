/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_update_ec_eq_state.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
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

// -----------------------------------------------------------------------------
//  Constants
// -----------------------------------------------------------------------------
static const uint8_t CORE_CHIPLET_START     = 0x20;
static const uint8_t CORE_CHIPLET_COUNT     = 24;

// See .H for documentation
fapi2::ReturnCode p9_update_ec_eq_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_IMP("> p9_update_ec_eq_state");

    FAPI_TRY(update_ec_config(i_target),
             "Error update_core_config detected");

    FAPI_TRY(update_eq_config(i_target),
             "Error update_cache_config detected");

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

                // Setting into ALL chiplets group (multicast group 0) using
                // MULTICAST_GROUP_1 register
                FAPI_INF("  Setting EC %d into MC group 0 (All chiplets)",
                         l_present_core_unit_pos);
                FAPI_TRY(fapi2::putScom(core_functional_it, C_MULTICAST_GROUP_1,
                                        p9UpdateECEQ::MCGR0_CNFG_SETTINGS));

                // Setting into good core group (multicast group 1) using
                // MULTICAST_GROUP_2 register in the EC chiplets
                FAPI_INF("  Setting EC %d into MC group 1 (All core chiplets)",
                         l_present_core_unit_pos);
                FAPI_TRY(fapi2::putScom(core_functional_it, C_MULTICAST_GROUP_2,
                                        p9UpdateECEQ::MCGR1_CNFG_SETTINGS));

                // Set the appropriate bit in the Core Configuration Status
                // Register buffer
                FAPI_INF("  Setting EC %d as good in value to be written to CCSR",
                         l_present_core_unit_pos);
                l_core_config.setBit(l_present_core_unit_pos);

                b_core_functional = true;

                break;
            }
        }

        // If not functional, clear the core chiplet out of all multicast groups
        // As the chiplet is not functional, it can only addressed with the chip
        // target, not a core target
        if (!b_core_functional)
        {

            // Clearing from the ALL chiplets group (multicast group 0) using
            // MULTICAST_GROUP_1 register
            FAPI_INF("  Removing EC %d from MC group 0 (All chiplets)",
                     l_present_core_unit_pos);

            uint32_t address = C_MULTICAST_GROUP_1 +
                               0x01000000 * l_present_core_unit_pos;
            FAPI_TRY(fapi2::putScom(i_target, address,
                                    p9UpdateECEQ::MCGR_CLEAR_CNFG_SETTINGS));

            // Clearing from the good cores (multicast group 1) using
            // MULTICAST_GROUP_2 register
            FAPI_INF("  Removing EC %d from MC group 1 (All core chiplets)",
                     l_present_core_unit_pos);
            address = C_MULTICAST_GROUP_2 +
                      0x01000000 * l_present_core_unit_pos;
            FAPI_TRY(fapi2::putScom(i_target, address,
                                    p9UpdateECEQ::MCGR_CLEAR_CNFG_SETTINGS));

            // The Core Configuration Status Register buffer bit is already clear

        }
    }

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



    // For each functinal EQ,  set the multicast groups to match (including
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

                // Setting into ALL chiplets group (multicast group 0) using
                // MULTICAST_GROUP_1 register
                FAPI_INF("  Setting EQ %d into MC group 0 (All chiplets)",
                         l_functional_eq_unit_pos);
                FAPI_TRY(fapi2::putScom(eq_functional_it, EQ_MULTICAST_GROUP_1,
                                        p9UpdateECEQ::MCGR0_CNFG_SETTINGS));

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
            FAPI_INF("  Remove EQ %d from MC group 0 (All chiplets)",
                     l_present_eq_unit_pos);
            uint32_t address = EQ_MULTICAST_GROUP_1 +
                               0x01000000 * l_present_eq_unit_pos;
            FAPI_DBG("  address = 0x%X", address);
            FAPI_TRY(fapi2::putScom(i_target, address,
                                    p9UpdateECEQ::MCGR_CLEAR_CNFG_SETTINGS));

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
