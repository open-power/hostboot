/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp_fbc_ab.C $          */
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
/// @file p9_build_smp_fbc_ab.C
///
/// @brief Fabric configuration (hotplug, AB) functions.
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB,FSP
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_build_smp_fbc_ab.H>
#include <p9_build_smp_adu.H>
#include <p9_fab_smp_utils.H>
#include <p9_build_smp_epsilon.H>
#include <p9_misc_scom_addresses.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// The start/end bits for each link in each link delay regs are the same
const uint32_t OPTIC_EVEN_LINK_DELAY_START_BIT[P9_FAB_SMP_NUM_OPTIC_LINKS] =
{  4, 36, 4, 36 };

const uint32_t X_EVEN_LINK_DELAY_START_BIT[P9_FAB_SMP_NUM_X_LINKS] =
{  4, 36, 4 };

// All link delays have same bit len
const uint32_t LINK_DELAY_BIT_LEN = 12;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// See doxygen in header file
template<fapi2::TargetType T>
fapi2::ReturnCode p9_build_smp_query_link_state(
    const p9_build_smp_chip& i_smp_chip,
    const uint8_t i_source_link_id,
    const fapi2::Target<T>& i_dest_target,
    bool& o_link_is_enabled,
    p9_fab_smp_node_id& o_dest_target_node_id,
    p9_fab_smp_chip_id& o_dest_target_chip_id)
{
    FAPI_DBG("Start");
    fapi2::ReturnCode l_rc;

    if (fapi2::is_same<T, fapi2::TARGET_TYPE_XBUS>())
    {
        FAPI_DBG("Bus type %s, SourceId %d", "X-BUS", i_source_link_id);
    }
    else if (fapi2::is_same<T, fapi2::TARGET_TYPE_OBUS>())
    {
        FAPI_DBG("Bus type %s, SourceId %d", "O-BUS", i_source_link_id);
    }

    // TODO: RTC 147511 - Need to set enabled/disabled based on ATTR_PG attributes.
    if (i_dest_target.get() == NULL)
    {
        FAPI_DBG("No target link");
        o_link_is_enabled = false;
        o_dest_target_node_id = FBC_NODE_ID_0;
        o_dest_target_chip_id = FBC_CHIP_ID_0;
    }
    else
    {
        o_link_is_enabled = true;

        // Extract chip/node ID from destination chip
        FAPI_TRY(p9_fab_smp_get_node_id_attr(i_dest_target,
                                             o_dest_target_node_id),
                 "p9_fab_smp_get_node_id_attr() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_TRY(p9_fab_smp_get_chip_id_attr(i_dest_target,
                                             o_dest_target_chip_id),
                 "p9_fab_smp_get_chip_id_attr() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

///
/// @brief Read PB Link Mode register and extract per-link training delays
///
/// @tparam T template parameter, passed in target.
/// @param[in]  i_smp_chip           Structure encapsulating single chip in SMP
/// @param[in]  i_link_en            Per-link enable values
/// @param[in]  i_link_target        Link endpoint targets
/// @param[out] o_link_delay_local   Array of link round trip delay values
///                                  (measured by local chip)
/// @param[out] o_link_delay_remote  Array of link round trip delay values
///                                  (measured by remote chips)
/// @param[out] o_link_number_remote Array of link numbers
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_build_smp_get_link_delays(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    fapi2::Target<T> i_link_target[],
    uint16_t o_link_delay_local[],
    uint16_t o_link_delay_remote[],
    uint8_t o_link_number_remote[]);

// Specialization for OBUS
template<>
fapi2::ReturnCode p9_build_smp_get_link_delays(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> i_link_target[],
    uint16_t o_link_delay_local[],
    uint16_t o_link_delay_remote[],
    uint8_t o_link_number_remote[])
{
    FAPI_DBG("OBUS: Start");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData;

    // Link delay values
    fapi2::buffer<uint64_t> pu_ioe_olink_0123_delay;
    fapi2::buffer<uint64_t> pu_ioe_olink_4567_delay;
    fapi2::buffer<uint64_t> l_temp;

    // Read PB Link Mode registers on local chip
    FAPI_TRY(fapi2::getScom(i_smp_chip.chip->this_chip,
                            PU_IOE_PB_OLINK_DLY_0123_REG,
                            pu_ioe_olink_0123_delay),
             "OBUS: getScom error on addr 0x%.16llX", PU_IOE_PB_OLINK_DLY_0123_REG);

    FAPI_TRY(fapi2::getScom(i_smp_chip.chip->this_chip,
                            PU_IOE_PB_OLINK_DLY_4567_REG,
                            pu_ioe_olink_4567_delay),
             "OBUS: getScom error on addr 0x%.16llX", PU_IOE_PB_OLINK_DLY_4567_REG);

    // TODO: RTC 147511 - Update link delay calculation methods
    // Per Joe, we want to compute the link delay as the average of the
    // even/odd numbers (same for X link)

    // Extract & return link training delays
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
    {
        if (!i_link_en[ll])
        {
            o_link_delay_local[ll] = 0xFF; // Even
        }
        else
        {
            // Select data buffer to get delay values from
            if (ll < 2)
            {
                l_temp = pu_ioe_olink_0123_delay;
            }
            else
            {
                l_temp = pu_ioe_olink_4567_delay;
            }

            // Even
            FAPI_TRY( l_temp.extractToRight(o_link_delay_local[ll],
                                            OPTIC_EVEN_LINK_DELAY_START_BIT[ll],
                                            LINK_DELAY_BIT_LEN),
                      "OBUS: l_temp.extractToRight() - OBUS/Even returns an error, l_rc 0x%.8X",
                      (uint64_t)fapi2::current_err);
        }
    }

    // Process remote links
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
    {
        if (!i_link_en[ll])
        {
            o_link_delay_remote[ll] = 0xFF;
        }
        else
        {
            uint8_t remote_link_number = 0x0;

            // Determine link number on remote end (equivalent to chiplet #)
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_link_target[ll],
                                   remote_link_number),
                     "OBUS: Error querying ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            o_link_number_remote[ll] = remote_link_number;

            // Obtain parent chip target
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procChip;
            l_procChip =
                i_link_target[ll].getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

            // Read PB Link Mode registers on remote chip
            FAPI_TRY(fapi2::getScom(l_procChip,
                                    PU_IOE_PB_OLINK_DLY_0123_REG,
                                    pu_ioe_olink_0123_delay),
                     "OBUS: getScom error on addr 0x%.16llX", PU_IOE_PB_OLINK_DLY_0123_REG);

            FAPI_TRY(fapi2::getScom(l_procChip,
                                    PU_IOE_PB_OLINK_DLY_4567_REG,
                                    pu_ioe_olink_4567_delay),
                     "OBUS: getScom error on addr 0x%.16llX", PU_IOE_PB_OLINK_DLY_4567_REG);

            // Select data buffer to get delay values from
            if (remote_link_number < 2)
            {
                l_temp = pu_ioe_olink_0123_delay;
            }
            else
            {
                l_temp = pu_ioe_olink_4567_delay;
            }

            // Even
            FAPI_TRY( l_temp.extractToRight(
                          o_link_delay_remote[ll],
                          OPTIC_EVEN_LINK_DELAY_START_BIT[ll],
                          LINK_DELAY_BIT_LEN),
                      "OBUS: l_temp.extractToRight() - OBUS/Even/Remote returns an error, "
                      "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        }
    }

fapi_try_exit:
    FAPI_DBG("OBUS: End");
    return fapi2::current_err;
}

// Specialization for XBUS
template<>
fapi2::ReturnCode p9_build_smp_get_link_delays(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_link_target[],
    uint16_t o_link_delay_local[],
    uint16_t o_link_delay_remote[],
    uint8_t o_link_number_remote[])
{
    FAPI_DBG("XBUS: Start");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData;

    // Link delay values
    fapi2::buffer<uint64_t> pu_elink_0123_delay;
    fapi2::buffer<uint64_t> pu_elink_45_delay;
    fapi2::buffer<uint64_t> l_temp;

    // Read PB Link Mode registers on local chip
    FAPI_TRY(fapi2::getScom(i_smp_chip.chip->this_chip,
                            PU_PB_ELINK_DLY_0123_REG,
                            pu_elink_0123_delay),
             "XBUS: getScom error on addr 0x%.16llX", PU_PB_ELINK_DLY_0123_REG);

    FAPI_TRY(fapi2::getScom(i_smp_chip.chip->this_chip,
                            PU_PB_ELINK_DLY_45_REG,
                            pu_elink_45_delay),
             "XBUS: getScom error on addr 0x%.16llX", PU_PB_ELINK_DLY_45_REG);

    // TODO: RTC 147511 - Update link delay calculation methods
    // Per Joe, we want to compute the link delay as the average of the
    // even/odd numbers (same for X link)

    // Extract & return link training delays
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
    {
        if (!i_link_en[ll])
        {
            o_link_delay_local[ll] = 0xFF; // Even
        }
        else
        {
            // Select data buffer to get delay values from
            if (ll < 2)
            {
                l_temp = pu_elink_0123_delay;
            }
            else
            {
                l_temp = pu_elink_45_delay;
            }

            // Even
            FAPI_TRY( l_temp.extractToRight(o_link_delay_local[ll],
                                            X_EVEN_LINK_DELAY_START_BIT[ll],
                                            LINK_DELAY_BIT_LEN),
                      "XBUS: l_temp.extractToRight() - XBUS/Even returns an error, l_rc 0x%.8X",
                      (uint64_t)fapi2::current_err);
        }
    }

    // Process remote links
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
    {
        if (!i_link_en[ll])
        {
            o_link_delay_remote[ll] = 0xFF;
        }
        else
        {
            uint8_t remote_link_number = 0x0;

            // Determine link number on remote end (equivalent to chiplet #)
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_link_target[ll],
                                   remote_link_number),
                     "XBUS: Error querying ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            o_link_number_remote[ll] = remote_link_number;

            // Obtain parent chip target
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_procChip;
            l_procChip =
                i_link_target[ll].getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

            // Read PB Link Mode registers on remote chip
            FAPI_TRY(fapi2::getScom(l_procChip,
                                    PU_PB_ELINK_DLY_0123_REG,
                                    pu_elink_0123_delay),
                     "XBUS: getScom error on addr 0x%.16llX", PU_PB_ELINK_DLY_0123_REG);

            FAPI_TRY(fapi2::getScom(l_procChip,
                                    PU_PB_ELINK_DLY_45_REG,
                                    pu_elink_45_delay),
                     "OBUS: getScom error on addr 0x%.16llX", PU_PB_ELINK_DLY_45_REG);

            // Select data buffer to get delay values from
            if (remote_link_number < 2)
            {
                l_temp = pu_elink_0123_delay;
            }
            else
            {
                l_temp = pu_elink_45_delay;
            }

            // Even
            FAPI_TRY( l_temp.extractToRight(
                          o_link_delay_remote[ll],
                          X_EVEN_LINK_DELAY_START_BIT[ll],
                          LINK_DELAY_BIT_LEN),
                      "XBUS: l_temp.extractToRight() - XBUS/Even/Remote returns an error, l_rc 0x%.8X",
                      (uint64_t)fapi2::current_err);
        }
    }

fapi_try_exit:
    FAPI_DBG("XBUS: End");
    return fapi2::current_err;
}

///
/// @brief Determine link address/data
///
/// @tparam T template parameter, passed in target.
/// @param[in]  i_smp_chip          Structure encapsulating single chip in SMP
/// @param[in]  i_link_en           Per-link enable values
/// @param[in]  i_link_id           Per-link destination chip/node ID values
/// @param[in]  i_link_target       Per-link destination targets
/// @param[out] o_link_addr_dis     Per-link address disable values
///                                 (true=address only, false=address/data)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode p9_build_smp_calc_link_setup(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    const uint8_t i_link_id[],
    fapi2::Target<T> i_link_target[],
    bool o_link_addr_dis[]);

// Specialization for OBUS
template<>
fapi2::ReturnCode p9_build_smp_calc_link_setup(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    const uint8_t i_link_id[],
    fapi2::Target<fapi2::TARGET_TYPE_OBUS> i_link_target[],
    bool o_link_addr_dis[])
{
    FAPI_DBG("OBUS: Start");
    fapi2::ReturnCode l_rc;
    uint8_t l_idLocal = 0;

    // Mark number of links targeting each ID
    uint8_t l_idActiveCount[P9_FAB_SMP_NUM_NODE_IDS];

    // Link round trip delay values
    uint16_t link_delay_local[P9_FAB_SMP_NUM_OPTIC_LINKS];
    uint16_t link_delay_remote[P9_FAB_SMP_NUM_OPTIC_LINKS];
    uint8_t  link_number_remote[P9_FAB_SMP_NUM_OPTIC_LINKS];

    // Init local arrays
    for (uint8_t id = 0; id < P9_FAB_SMP_NUM_CHIP_IDS; id++)
    {
        l_idActiveCount[id] = 0;
    }

    // Process all links
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
    {
        // Mark link ID
        if (i_link_en[ll])
        {
            l_idActiveCount[i_link_id[ll]]++;
        }

        // Set default value for link address disable (enable coherency)
        o_link_addr_dis[ll] = false;
    }

    // Figure out if link is to carry data only (Address disabled)
    for (uint8_t l_id = 0; l_id < P9_FAB_SMP_NUM_NODE_IDS; l_id++)
    {
        // Skip if not active
        if (!l_idActiveCount[l_id])
        {
            continue;
        }

        // Flip default value for link address disable
        // (disable coherency)
        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
        {
            if (i_link_en[ll])
            {
                o_link_addr_dis[ll] = true;
            }
        }

        // Select link with the lowest round trip latency value
        // to carry coherency
        FAPI_TRY(p9_build_smp_get_link_delays(i_smp_chip,
                                              i_link_en,
                                              i_link_target,
                                              link_delay_local,
                                              link_delay_remote,
                                              link_number_remote),
                 "p9_build_smp_get_link_delays() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Debug trace
        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
        {
            FAPI_DBG("Link[%d]):");
            FAPI_DBG("    link_delay_local: %d, link_delay_remote: %d, "
                     "link_number_remote: %d", ll, link_delay_local[ll],
                     link_delay_remote[ll], link_number_remote[ll]);
        }

        // Sum local/remote delay factors & scan for smallest value
        uint32_t link_delay_total[P9_FAB_SMP_NUM_OPTIC_LINKS];
        uint8_t coherent_link_index = 0xFF;
        uint32_t coherent_link_delay = 0xFFFFFFFF;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
        {
            link_delay_total[ll] = link_delay_local[ll] + link_delay_remote[ll];

            if ( i_link_en[ll] &&
                 (link_delay_total[ll] < coherent_link_delay) )
            {
                coherent_link_delay = link_delay_total[ll];
                FAPI_DBG("Setting coherent_link_delay = %d", coherent_link_delay);
            }
        }

        // Ties must be broken consistently on both connected chips
        // search if a tie has occurred
        uint8_t matches = 0;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
        {
            if (i_link_en[ll] &&
                (link_delay_total[ll] == coherent_link_delay))
            {
                matches++;
                coherent_link_index = ll;
            }
        }

        // If no ties, we're done
        // else, break tie

        // Select link with lowest link number on chip with smaller ID
        // (chip ID if X links, node ID if A links)
        l_idLocal = i_smp_chip.node_id;

        if (matches != 1)
        {
            FAPI_DBG("Breaking tie");

            if (l_idLocal < l_id)
            {
                for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
                {
                    if (i_link_en[ll] &&
                        (link_delay_total[ll] == coherent_link_delay))
                    {
                        coherent_link_index = ll;
                        break;
                    }
                }

                FAPI_DBG("Selecting coherent link = link %d based on this chip (%d)",
                         coherent_link_index, l_idLocal);
            }
            else
            {
                uint8_t lowest_remote_link_number = 0xFF;

                for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
                {
                    if ((i_link_en[ll]) &&
                        (link_delay_total[ll] == coherent_link_delay) &&
                        (link_number_remote[ll] < lowest_remote_link_number))
                    {
                        lowest_remote_link_number = link_number_remote[ll];
                        coherent_link_index = ll;
                    }
                }

                FAPI_DBG("Selecting coherent link = linkd %d based on remote chip ID (%d)",
                         coherent_link_index, l_id);
            }
        }

        o_link_addr_dis[coherent_link_index] = false;
    }

fapi_try_exit:
    FAPI_DBG("OBUS: End");
    return fapi2::current_err;
}

// Specialization for XBUS
template<>
fapi2::ReturnCode p9_build_smp_calc_link_setup(
    const p9_build_smp_chip& i_smp_chip,
    const bool i_link_en[],
    const uint8_t i_link_id[],
    fapi2::Target<fapi2::TARGET_TYPE_XBUS> i_link_target[],
    bool o_link_addr_dis[])
{
    FAPI_DBG("XBUS: Start");
    fapi2::ReturnCode l_rc;
    uint8_t l_idLocal = 0;

    // Mark number of links targeting each ID
    uint8_t l_idActiveCount[P9_FAB_SMP_NUM_CHIP_IDS];

    // Link round trip delay values
    uint16_t link_delay_local[P9_FAB_SMP_NUM_X_LINKS];
    uint16_t link_delay_remote[P9_FAB_SMP_NUM_X_LINKS];
    uint8_t  link_number_remote[P9_FAB_SMP_NUM_X_LINKS];

    // Init local arrays
    for (uint8_t id = 0; id < P9_FAB_SMP_NUM_X_LINKS; id++)
    {
        l_idActiveCount[id] = 0;
    }

    // Process all links
    for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
    {
        // Mark link ID
        if (i_link_en[ll])
        {
            l_idActiveCount[i_link_id[ll]]++;
        }

        // Set default value for link address disable (enable coherency)
        o_link_addr_dis[ll] = false;
    }

    // Figure out if link is to carry data only (ADDR_DIS)
    for (uint8_t l_id = 0; l_id < P9_FAB_SMP_NUM_CHIP_IDS; l_id++)
    {
        // Skip if not active
        if (!l_idActiveCount[l_id])
        {
            continue;
        }

        // Flip default value for link address disable
        // (disable coherency)
        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
        {
            if (i_link_en[ll])
            {
                o_link_addr_dis[ll] = true;
            }
        }

        // Select link with the lowest round trip latency value
        // to carry coherency
        FAPI_TRY(p9_build_smp_get_link_delays(i_smp_chip,
                                              i_link_en,
                                              i_link_target,
                                              link_delay_local,
                                              link_delay_remote,
                                              link_number_remote),
                 "p9_build_smp_get_link_delays() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Debug trace
        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
        {
            FAPI_DBG("Link[%d]):");
            FAPI_DBG("    link_delay_local: %d, link_delay_remote: %d, "
                     "link_number_remote: %d", ll, link_delay_local[ll],
                     link_delay_remote[ll], link_number_remote[ll]);
        }

        // Sum local/remote delay factors & scan for smallest value
        uint32_t link_delay_total[P9_FAB_SMP_NUM_X_LINKS];
        uint8_t coherent_link_index = 0xFF;
        uint32_t coherent_link_delay = 0xFFFFFFFF;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
        {
            link_delay_total[ll] = link_delay_local[ll] + link_delay_remote[ll];

            if ( i_link_en[ll] &&
                 (link_delay_total[ll] < coherent_link_delay) )
            {
                coherent_link_delay = link_delay_total[ll];
                FAPI_DBG("Setting coherent_link_delay = %d", coherent_link_delay);
            }
        }

        // Ties must be broken consistently on both connected chips
        // search if a tie has occurred
        uint8_t matches = 0;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
        {
            if (i_link_en[ll] &&
                (link_delay_total[ll] == coherent_link_delay))
            {
                matches++;
                coherent_link_index = ll;
            }
        }

        // If no ties, we're done
        // else, break tie

        // Select link with lowest link number on chip with smaller ID
        // (chip ID if X links, node ID if A links)
        l_idLocal = i_smp_chip.chip_id;

        if (matches != 1)
        {
            FAPI_DBG("Breaking tie");

            if (l_idLocal < l_id)
            {
                for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
                {
                    if (i_link_en[ll] &&
                        (link_delay_total[ll] == coherent_link_delay))
                    {
                        coherent_link_index = ll;
                        break;
                    }
                }

                FAPI_DBG("Selecting coherent link = link %d based on this chip (%d)",
                         coherent_link_index, l_idLocal);
            }
            else
            {
                uint8_t lowest_remote_link_number = 0xFF;

                for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
                {
                    if ((i_link_en[ll]) &&
                        (link_delay_total[ll] == coherent_link_delay) &&
                        (link_number_remote[ll] < lowest_remote_link_number))
                    {
                        lowest_remote_link_number = link_number_remote[ll];
                        coherent_link_index = ll;
                    }
                }

                FAPI_DBG("Selecting coherent link = linkd %d based on remote chip ID (%d)",
                         coherent_link_index, l_id);
            }
        }

        o_link_addr_dis[coherent_link_index] = false;
    }

fapi_try_exit:
    FAPI_DBG("XBUS: End");
    return fapi2::current_err;
}

extern "C" {

// See doxygen in header file
    fapi2::ReturnCode p9_build_smp_get_hotplug_curr_reg(
        const p9_build_smp_chip& i_smp_chip,
        const bool i_hp_not_hpx,
        fapi2::buffer<uint64_t>& o_data)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;

        // Check consistency of west/center/east register copies
        for (uint8_t rr = 0; rr < P9_BUILD_SMP_NUM_SHADOWS; rr++)
        {
            // Get current (working) register
            uint64_t l_reg = i_hp_not_hpx ? PB_HP_MODE_CURR_SHADOWS[rr] :
                             PB_HPX_MODE_CURR_SHADOWS[rr];

            FAPI_TRY(fapi2::getScom(i_smp_chip.chip->this_chip, l_reg, l_scomData),
                     "getScom returns error: Addr 0x%016llX, l_rc 0x%.8X",
                     l_reg, (uint64_t)fapi2::current_err);

            // Raise error if shadow copies aren't equal
            FAPI_ASSERT( (rr == 0) || (l_scomData == o_data),
                         fapi2::PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR()
                         .set_ADDRESS0((i_hp_not_hpx) ? (PB_HP_MODE_CURR_SHADOWS[rr - 1]) :
                                       (PB_HPX_MODE_CURR_SHADOWS[rr - 1])
                                      )
                         .set_ADDRESS1(l_reg)
                         .set_DATA0(o_data)
                         .set_DATA1(l_scomData),
                         "Shadow copies are not equivalent");

            // Set output (will be used to compare with next HW read)
            o_data = l_scomData;
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Program PB Hotplug Mode register
///
/// @param[in] i_smp_chip      Structure encapsulating single chip in SMP
/// @param[in] i_smp           Structure encapsulating SMP topology
/// @param[in] i_set_curr      Set CURR register set?
/// @param[in] i_set_next      Set NEXT register set?
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_pb_hp_mode(
        const p9_build_smp_chip& i_smp_chip,
        const p9_build_smp_system& i_smp,
        const bool i_set_curr,
        const bool i_set_next)
    {

        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;

        // Set of per-link destination chip targets
        fapi2::Target<fapi2::TARGET_TYPE_OBUS> o_target[P9_FAB_SMP_NUM_OPTIC_LINKS];
        // Per-link enables
        bool o_en[P9_FAB_SMP_NUM_OPTIC_LINKS];
        // Per-link destination IDs
        uint8_t o_id[P9_FAB_SMP_NUM_OPTIC_LINKS];
        // Per-link address disable values
        bool o_addr_dis[P9_FAB_SMP_NUM_OPTIC_LINKS];

        // TODO: RTC 147511 - Need to handle PCIE link

        // Process all optic links
        o_target[0] = i_smp_chip.chip->o0_chip;
        o_target[1] = i_smp_chip.chip->o1_chip;
        o_target[2] = i_smp_chip.chip->o2_chip;
        o_target[3] = i_smp_chip.chip->o2_chip;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_OPTIC_LINKS; ll++)
        {
            // Determine link enable/ID
            p9_fab_smp_node_id dest_node_id;
            p9_fab_smp_chip_id dest_chip_id;
            FAPI_TRY(p9_build_smp_query_link_state(i_smp_chip,
                                                   ll,
                                                   o_target[ll],
                                                   o_en[ll],
                                                   dest_node_id,
                                                   dest_chip_id),
                     "p9_build_smp_query_link_state() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            o_id[ll] = (uint8_t) dest_node_id;
        }

        // Determine address/data assignents
        // link command rates (A)
        if (i_smp_chip.o_enabled)
        {
            FAPI_TRY(p9_build_smp_calc_link_setup(i_smp_chip,
                                                  o_en,
                                                  o_id,
                                                  o_target,
                                                  o_addr_dis),
                     "p9_build_smp_calc_link_setup() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Set attributes
        if (i_smp_chip.smpOpticsMode ==
            fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_X_BUS)
        {
            uint8_t l_x_address_dis[P9_FAB_SMP_NUM_X_LINKS +
                                    P9_FAB_SMP_NUM_OPTIC_LINKS];

            // Optic is XBUS, write to X-LINK attribute

            // Read current values to preserve the first 3 values from XBUS
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS,
                                   i_smp_chip.chip->this_chip,
                                   l_x_address_dis),
                     "Error getting ATTR_PROC_FABRIC_X_ADDR_DIS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Store optic addr_dis starting at index 3
            for (uint8_t ii = 0; ii < P9_FAB_SMP_NUM_OPTIC_LINKS; ii++)
            {
                l_x_address_dis[ii + P9_FAB_SMP_NUM_X_LINKS] =
                    o_addr_dis[ii] ? 1 : 0;
            }

            // Write attribute back
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS,
                                   i_smp_chip.chip->this_chip,
                                   l_x_address_dis),
                     "Error setting ATTR_PROC_FABRIC_X_ADDR_DIS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }
        else
        {
            uint8_t l_a_address_dis[P9_FAB_SMP_NUM_OPTIC_LINKS];

            for (uint8_t ii = 0; ii < P9_FAB_SMP_NUM_OPTIC_LINKS; ii++)
            {
                l_a_address_dis[ii] = o_addr_dis[ii] ? 1 : 0;
            }

            // Optic is ABUS, write to A-LINK attribute
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_A_ADDR_DIS,
                                   i_smp_chip.chip->this_chip,
                                   l_a_address_dis),
                     "Error setting ATTR_PROC_FABRIC_A_ADDR_DIS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // TODO: RTC 147511 - Call initfile
        // Call initfile when available to re-program slave fabrics
#if 0

        // Run initfile to set CURR (OBUS)
        if (i_set_curr)
        {
            FAPI_TRY(p9_set_curr_initfile(),
                     "p9_set_curr_initfile() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Run initfile to set NEXT (OBUS)
        if (i_set_next)
        {
            FAPI_TRY(p9_set_next_initfile(),
                     "p9_set_next_initfile() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

#endif


    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Program PB Hotplug Extension Mode register
///
/// @param[in] i_smp_chip      Structure encapsulating single chip in SMP
/// @param[in] i_smp           Structure encapsulating SMP topology
/// @param[in] i_set_curr      Set CURR register set?
/// @param[in] i_set_next      Set NEXT register set?
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_pb_hpx_mode(
        const p9_build_smp_chip& i_smp_chip,
        const p9_build_smp_system& i_smp,
        const bool i_set_curr,
        const bool i_set_next)
    {

        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;

        // set of per-link destination chip targets
        fapi2::Target<fapi2::TARGET_TYPE_XBUS> x_target[P9_FAB_SMP_NUM_X_LINKS];
        // Per-link enables
        bool x_en[P9_FAB_SMP_NUM_X_LINKS];
        // Per-link destination IDs
        uint8_t x_id[P9_FAB_SMP_NUM_X_LINKS];
        // Per-link address disable values
        bool x_addr_dis[P9_FAB_SMP_NUM_X_LINKS];

        // Process all links
        x_target[0] = i_smp_chip.chip->x0_chip;
        x_target[1] = i_smp_chip.chip->x1_chip;
        x_target[2] = i_smp_chip.chip->x2_chip;

        for (uint8_t ll = 0; ll < P9_FAB_SMP_NUM_X_LINKS; ll++)
        {
            // Determine link enable/ID
            p9_fab_smp_node_id dest_node_id;
            p9_fab_smp_chip_id dest_chip_id;
            FAPI_TRY(p9_build_smp_query_link_state(i_smp_chip,
                                                   ll,
                                                   x_target[ll],
                                                   x_en[ll],
                                                   dest_node_id,
                                                   dest_chip_id),
                     "p9_build_smp_query_link_state() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
            x_id[ll] = (uint8_t) dest_chip_id;
        }

        // Determine address/data assignents
        if (i_smp_chip.x_enabled)
        {
            FAPI_TRY(p9_build_smp_calc_link_setup(i_smp_chip,
                                                  x_en,
                                                  x_id,
                                                  x_target,
                                                  x_addr_dis),
                     "p9_build_smp_calc_link_setup() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Set attributes
        uint8_t l_x_address_dis[P9_FAB_SMP_NUM_X_LINKS +
                                P9_FAB_SMP_NUM_OPTIC_LINKS];

        // Read current values to preserve the settings for OBUS
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS,
                               i_smp_chip.chip->this_chip,
                               l_x_address_dis),
                 "Error getting ATTR_PROC_FABRIC_X_ADDR_DIS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Store at first 3 indexes for XBUS targets
        for (uint8_t ii = 0; ii < P9_FAB_SMP_NUM_X_LINKS; ii++)
        {
            l_x_address_dis[ii] = x_addr_dis[ii] ? 1 : 0;
        }

        // Write attribute back
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_X_ADDR_DIS,
                               i_smp_chip.chip->this_chip,
                               l_x_address_dis),
                 "Error setting ATTR_PROC_FABRIC_X_ADDR_DIS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // TODO: RTC 147511 - Call initfile
        // Call initfile when available to re-program slave fabrics
#if 0

        // Run initfile to set CURR (XBUS)
        if (i_set_curr)
        {
            FAPI_TRY(p9_set_curr_initfile(),
                     "p9_build_smp_set_pb_hp_mode: p9_set_curr_initfile() "
                     "returns an error, l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        }

        // Run initfile to set NEXT (XBUS)
        if (i_set_next)
        {
            FAPI_TRY(p9_set_next_initfile(),
                     "p9_build_smp_set_pb_hp_mode: p9_set_next_initfile() "
                     "returns an error, l_rc 0x%.8X", (uint64_t)fapi2::current_err);
        }

#endif

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


///
/// @brief Utility function to program set of PB hotplug registers
///
/// @param[in] i_smp_chip      Structure encapsulating single chip in SMP
/// @param[in] i_curr_not_next Choose CURR/NEXT register set (true=CURR,
///                            false=NEXT)
/// @param[in] i_hp_not_hpx    Structure encapsulating SMP topology
/// @param[in] i_set_curr      Choose HP/HPX register set (true=HP,
///                            false=HPX)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_hotplug_reg(
        const p9_build_smp_chip& i_smp_chip,
        const bool i_curr_not_next,
        const bool i_hp_not_hpx,
        const fapi2::buffer<uint64_t> i_data)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        uint64_t l_scomAddr;

        // write west/center/east register copies
        for (uint8_t rr = 0; rr < P9_BUILD_SMP_NUM_SHADOWS; rr++)
        {
            // Set target scom address based on input parameters
            if (i_curr_not_next)
            {
                if (i_hp_not_hpx)
                {
                    l_scomAddr = PB_HP_MODE_CURR_SHADOWS[rr];
                }
                else
                {
                    l_scomAddr = PB_HPX_MODE_CURR_SHADOWS[rr];
                }
            }
            else
            {
                if (i_hp_not_hpx)
                {
                    l_scomAddr = PB_HP_MODE_NEXT_SHADOWS[rr];
                }
                else
                {
                    l_scomAddr = PB_HPX_MODE_NEXT_SHADOWS[rr];
                }
            }

            // Write register
            FAPI_TRY(fapi2::putScom(i_smp_chip.chip->this_chip, l_scomAddr, i_data),
                     "putScom error, addr 0x%.16llX", l_scomAddr);
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Reset (copy CURR->NEXT) PB Hotplug Mode/Mode Extension register
///
/// @param[in] i_smp_chip      Structure encapsulating single chip in SMP
/// @param[in] i_hp_not_hpx    Structure encapsulating SMP topology
/// @param[in] i_set_curr      Choose HP/HPX register set (true=HP,
///                            false=HPX)
///
/// @return fapi2:ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_reset_hotplug_next_reg(
        const p9_build_smp_chip& i_smp_chip,
        const bool i_hp_not_hpx)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;

        // Read CURR state
        FAPI_TRY(p9_build_smp_get_hotplug_curr_reg(i_smp_chip,
                 i_hp_not_hpx,
                 l_scomData),
                 "p9_build_smp_get_hotplug_curr_reg() Returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Write NEXT state
        FAPI_TRY(p9_build_smp_set_hotplug_reg(i_smp_chip,
                                              false,
                                              i_hp_not_hpx,
                                              l_scomData),
                 "p9_build_smp_set_hotplug_reg() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

// NOTE: see comments above function prototype in header
    fapi2::ReturnCode p9_build_smp_set_fbc_ab(p9_build_smp_system& i_smp,
            const p9_build_smp_operation i_op)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        // Chip/Node map iterators
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;

        // Quiesce 'slave' fabrics in preparation for joining
        //   PHASE1 -> quiesce all chips except the chip which is the new fabric master
        //   PHASE2 -> quiesce all drawers except the drawer containing the new fabric master
        FAPI_TRY(p9_build_smp_quiesce_pb(i_smp, i_op),
                 "p9_build_smp_quiesce_pb() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Program CURR register set only for chips which were just quiesced
        // Program NEXT register set for all chips
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {
                FAPI_TRY(p9_build_smp_set_pb_hp_mode(
                             p_iter->second, i_smp,
                             p_iter->second.quiesced_next,  // Set CURR
                             true),                         // Set NEXT
                         "p9_build_smp_set_pb_hp_mode() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                FAPI_TRY(p9_build_smp_set_pb_hpx_mode(
                             p_iter->second, i_smp,
                             p_iter->second.quiesced_next,  // Set CURR
                             true),                         // Set NEXT
                         "p9_build_smp_set_pb_hpx_mode() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

        // Issue switch AB reconfiguration from chip designated as new master
        // (which is guaranteed to be a master now)
        FAPI_TRY(p9_build_smp_switch_ab(i_smp, i_op),
                 "p9_build_smp_switch_ab() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Reset NEXT register set (copy CURR->NEXT) for all chips
        for (n_iter = i_smp.nodes.begin();
             n_iter != i_smp.nodes.end();
             ++n_iter)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 ++p_iter)
            {

                FAPI_TRY(p9_build_smp_reset_hotplug_next_reg(p_iter->second, true),
                         "p9_build_smp_reset_hotplug_next_reg(true) returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                FAPI_TRY(p9_build_smp_reset_hotplug_next_reg(p_iter->second, false),
                         "p9_build_smp_reset_hotplug_next_reg(false) returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


} // extern "C"
