/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_fbc_eff_config.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_fbc_eff_config.C
/// @brief Set fabric system-wide effective config attributes (FAPI2)
///
/// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
/// *HWP Team: Nest
/// *HWP Level: 2
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_eff_config.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// base epsilon table values
//

const uint32_t EPSILON_MIN_VALUE = 0x1;
const uint32_t EPSILON_MAX_VALUE = 0xFFFFFFFF;

const uint8_t NUM_EPSILON_READ_TIERS = 3;
const uint8_t NUM_EPSILON_WRITE_TIERS = 2;

// LE epsilon (2 chips per-group)
const uint32_t EPSILON_R_T0_LE[] = {    4,    5,    5,    5,    6,    8 };
const uint32_t EPSILON_R_T1_LE[] = {    4,    5,    5,    5,    6,    8 };
const uint32_t EPSILON_R_T2_LE[] = {   47,   48,   49,   51,   54,   68 };
const uint32_t EPSILON_W_T0_LE[] = {    0,    0,    0,    0,    0,    0 };
const uint32_t EPSILON_W_T1_LE[] = {    0,    0,    0,    0,    0,    0 };

// TODO: These values need to be updated whenever HE system info is available.
// HE epsilon (4 chips per-group)
const uint32_t EPSILON_R_T0_HE[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t EPSILON_R_T1_HE[] = {   56,   58,   60,   62,   65,   84 };
const uint32_t EPSILON_R_T2_HE[] = {  102,  104,  105,  108,  111,  130 };
const uint32_t EPSILON_W_T0_HE[] = {    6,    6,    7,    8,    9,   15 };
const uint32_t EPSILON_W_T1_HE[] = {   56,   58,   60,   62,   65,   84 };


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Utility function to apply positive/negative scaing factor
///        to base epsilon value
///
/// @param[in] i_gb_percentage       Scaling factor (e.g. 20% = 20)
/// @param[in/out] io_target_value   Target epsilon value, after application of
///                                  scaling factor
///                                  NOTE: scaling will be clamped to
///                                  minimum/maximum value
///
/// @return void.
///
void p9_fbc_eff_config_guardband_epsilon(
    const uint8_t i_gb_percentage,
    uint32_t& io_target_value)
{
    FAPI_DBG("Start");
    uint32_t l_delta =  ((io_target_value * i_gb_percentage) / 100) +
                        (((io_target_value * i_gb_percentage) % 100) ? (1) : (0));


    // Apply guardband
    if (i_gb_percentage >= 0)
    {
        // Clamp to maximum value if necessary
        if (l_delta > (EPSILON_MAX_VALUE - io_target_value))
        {
            FAPI_DBG("Guardband application generated out-of-range target value, clamping to maximum value!");
            io_target_value = EPSILON_MAX_VALUE;
        }
        else
        {
            io_target_value += l_delta;
        }
    }
    else
    {
        // Clamp to minimum value if necessary
        if (l_delta >= io_target_value)
        {
            FAPI_DBG("Guardband application generated out-of-range target value, clamping to minimum value!");
            io_target_value = EPSILON_MIN_VALUE;
        }
        else
        {
            io_target_value -= l_delta;
        }
    }

    FAPI_DBG("End");
    return;
}


///
/// @brief Calculate target epsilon settings to apply based on
///        system configuration
///
/// @param[in] i_target                System target
/// @param[in] io_core_floor_ratio     Fabric/core floor enum
/// @param[in] io_core_ceiling_ratio   Fabric/core ceiling enum
/// @param[in] i_freq_fbc              Absolute fabric frequency
/// @param[in] i_freq_core_ceiling     Absolute core ceiling frequency
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_fbc_eff_config_calc_epsilons(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
    fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_Type i_core_floor_ratio,
    fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type i_core_ceiling_ratio,
    fapi2::ATTR_FREQ_PB_Type i_freq_fbc,
    fapi2::ATTR_FREQ_CORE_CEILING_Type i_freq_core_ceiling)
{
    FAPI_DBG("Start");

    // epsilon output attributes
    uint32_t l_eps_r[NUM_EPSILON_READ_TIERS];
    uint32_t l_eps_w[NUM_EPSILON_WRITE_TIERS];
    fapi2::ATTR_PROC_EPS_GB_PERCENTAGE_Type l_eps_gb;

    // fetch epsilon table type/pump mode attributes
    fapi2::ATTR_PROC_EPS_TABLE_TYPE_Type l_eps_table_type;
    fapi2::ATTR_PROC_FABRIC_PUMP_MODE_Type l_pump_mode;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE, i_target, l_eps_table_type),
             "Error from FAPI_ATTR_GET(ATTR_PROC_EPS_TABLE_TYPE)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, i_target, l_pump_mode),
             "Error from FAPI_ATTR_GET(ATTR_PROC_FABRIC_PUMP_MODE)");

    switch(l_eps_table_type)
    {
        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE:
            if (l_pump_mode == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_HE[i_core_floor_ratio];
            }
            else
            {
                l_eps_r[0] = EPSILON_R_T1_HE[i_core_floor_ratio];
            }

            l_eps_r[1] = EPSILON_R_T1_HE[i_core_floor_ratio];
            l_eps_r[2] = EPSILON_R_T2_HE[i_core_floor_ratio];

            l_eps_w[0] = EPSILON_W_T0_HE[i_core_floor_ratio];
            l_eps_w[1] = EPSILON_W_T1_HE[i_core_floor_ratio];
            break;

        case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_LE:
            if (l_pump_mode == fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_CHIP_IS_NODE)
            {
                l_eps_r[0] = EPSILON_R_T0_LE[i_core_floor_ratio];
            }
            else
            {
                l_eps_r[0] = EPSILON_R_T1_LE[i_core_floor_ratio];
            }

            l_eps_r[1] = EPSILON_R_T1_LE[i_core_floor_ratio];
            l_eps_r[2] = EPSILON_R_T2_LE[i_core_floor_ratio];

            l_eps_w[0] = EPSILON_W_T0_LE[i_core_floor_ratio];
            l_eps_w[1] = EPSILON_W_T1_LE[i_core_floor_ratio];
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::P9_FBC_EFF_CONFIG_EPSILON_INVALID_TABLE_ERR()
                        .set_TABLE_TYPE(l_eps_table_type),
                        "Invalid epsilon table type 0x%.8X", l_eps_table_type);
            break;
    }

    // dump base epsilon values
    FAPI_DBG("Base epsilon values read from table:");

    for (uint32_t ii = 0; ii < NUM_EPSILON_READ_TIERS; ii++)
    {
        FAPI_DBG(" R_T[%d] = %d", ii, l_eps_r[ii]);
    }

    for (uint32_t ii = 0; ii < NUM_EPSILON_WRITE_TIERS; ii++)
    {
        FAPI_DBG(" W_T[%d] = %d", ii, l_eps_w[ii]);
    }

    // set guardband default value to +20%
    l_eps_gb = +20;
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_GB_PERCENTAGE, i_target, l_eps_gb),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_GB_PERCENTAGE)");

    // get gardband attribute
    // Note: if a user makes an attribute override with CONST, it would
    // override the above default value settings. This mechanism is to
    // allow users to change the default settings for testing.
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_GB_PERCENTAGE, i_target, l_eps_gb),
             "Error from FAPI_ATTR_GET (ATTR_PROC_EPS_GB_PERCENTAGE)");

    FAPI_DBG("ATTR_PROC_EPS_GB_PERCENTAGE %s%d, ",
             (l_eps_gb >= 0) ? ("+") : ("-"), l_eps_gb);

    // scale base epsilon values if core is running 2x nest frequency
    if (i_core_ceiling_ratio == fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_8_8)
    {
        FAPI_DBG("Scaling based on ceiling frequency");
        uint8_t l_scale_percentage =
            100 *
            i_freq_core_ceiling /
            (2 * i_freq_fbc);
        l_scale_percentage -= 100;

        // scale/apply guardband read epsilons
        for (uint32_t ii = 0; ii < NUM_EPSILON_READ_TIERS; ii++)
        {
            p9_fbc_eff_config_guardband_epsilon(l_scale_percentage, l_eps_r[ii]);

        }

        // Scale write epsilons
        for (uint32_t ii = 0; ii < NUM_EPSILON_WRITE_TIERS; ii++)
        {
            p9_fbc_eff_config_guardband_epsilon(l_scale_percentage, l_eps_w[ii]);
        }
    }

    // scale based on guardband, and output final values
    FAPI_DBG("Scaled epsilon values based on %s%d percent guardband:",
             (l_eps_gb >= 0) ? ("+") : ("-"),
             l_eps_gb);

    for (uint32_t ii = 0; ii < NUM_EPSILON_READ_TIERS; ii++)
    {
        p9_fbc_eff_config_guardband_epsilon(l_eps_gb, l_eps_r[ii]);
        FAPI_DBG(" R_T[%d] = %d", ii, l_eps_r[ii]);
    }

    for (uint32_t ii = 0; ii < NUM_EPSILON_WRITE_TIERS; ii++)
    {
        p9_fbc_eff_config_guardband_epsilon(l_eps_gb, l_eps_w[ii]);
        FAPI_DBG(" W_T[%d] = %d", ii, l_eps_w[ii]);
    }

    // check relationship of epsilon counters rules:
    //   read tier values are strictly increasing
    //   write tier values are strictly increaing
    if ((l_eps_r[0] > l_eps_r[1]) ||
        (l_eps_r[1] > l_eps_r[2]) ||
        (l_eps_w[0] > l_eps_w[1]))
    {
        FAPI_ASSERT(false,
                    fapi2::P9_FBC_EFF_CONFIG_EPSILON_INVALID_TABLE_ERR()
                    .set_TABLE_TYPE(l_eps_table_type),
                    "Invalid relationship between base epsilon values");
    }

    // write attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T0, i_target, l_eps_r[0]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T0)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T1, i_target, l_eps_r[1]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_READ_CYCLES_T2, i_target, l_eps_r[2]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_READ_CYCLES_T2)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T1, i_target, l_eps_w[0]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_WRITE_CYCLES_T1)");
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_WRITE_CYCLES_T2, i_target, l_eps_w[1]),
             "Error from FAPI_ATTR_SET (ATTR_PROC_EPS_WRITE_CYCLES_T2)");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}


///
/// @brief Process fabric/core frequency attributes and generate
///        derived attributes to drive fabric configuration
///
/// @param[in]     i_target                System target
/// @param[in/out] io_core_floor_ratio     Fabric/core floor enum
/// @param[in/out] io_core_ceiling_ratio   Fabric/core ceiling enum
/// @param[in/out] io_freq_fbc             Absolute fabric frequency
/// @param[in/out] io_freq_core_ceiling    Absolute core ceiling frequency
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p9_fbc_eff_config_process_freq_attributes(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target,
    fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_Type& io_core_floor_ratio,
    fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type& io_core_ceiling_ratio,
    fapi2::ATTR_FREQ_PB_Type& io_freq_fbc,
    fapi2::ATTR_FREQ_CORE_CEILING_Type& io_freq_core_ceiling)
{
    FAPI_DBG("Start");
    uint32_t l_freq_core_floor;
    uint32_t l_freq_core_nom;

    // get core floor/nominal/ceiling frequency attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR, i_target, l_freq_core_floor),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_FLOOR)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_NOMINAL, i_target, l_freq_core_nom),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_NOMINAL)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_CEILING, i_target, io_freq_core_ceiling),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_CEILING)");

    // verify the floor/nominal/ceiling frequencies
    // expect ceiling >= nominal, nominal >= floor
    FAPI_ASSERT(((io_freq_core_ceiling >= l_freq_core_nom) &&
                 (l_freq_core_nom     >= l_freq_core_floor)),
                fapi2::P9_FBC_EFF_CONFIG_CORE_FREQ_RANGE_ERR()
                .set_FREQ_CORE_CEILING(io_freq_core_ceiling)
                .set_FREQ_CORE_NOM(l_freq_core_nom)
                .set_FREQ_CORE_FLOOR(l_freq_core_floor),
                "Invalid core frequency ranges: FLOOR: 0x%.8X, NOMINAL: 0x%.8X, CEILING: 0x%.8X",
                l_freq_core_floor, l_freq_core_nom, io_freq_core_ceiling);

    // calculate fabric/core frequency ratio attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB, i_target, io_freq_fbc),
             "Error from FAPI_ATTR_GET (ATTR_FREQ_PB)");

    // determine table index based on fabric/core floor frequency ratio
    // breakpoint ratio: core floor 4.0, pb 2.0 (cache floor :: pb = 8/8)
    if ((l_freq_core_floor) >= (2 * io_freq_fbc))
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_8_8;
    }
    // breakpoint ratio: core floor 3.5, pb 2.0 (cache floor :: pb = 7/8)
    else if ((4 * l_freq_core_floor) >= (7 * io_freq_fbc))
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_7_8;
    }
    // breakpoint ratio: core floor 3.0, pb 2.0 (cache floor :: pb = 6/8)
    else if ((2 * l_freq_core_floor) >= (3 * io_freq_fbc))
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_6_8;
    }
    // breakpoint ratio: core floor 2.5, pb 2.0 (cache floor :: pb = 5/8)
    else if ((4 * l_freq_core_floor) >= (5 * io_freq_fbc))
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_5_8;
    }
    // breakpoint ratio: core floor 2.0, pb 2.0 (cache floor :: pb = 4/8)
    else if (l_freq_core_floor >= io_freq_fbc)
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_4_8;
    }
    // breakpoint ratio: core floor 1.0, pb 2.0 (cache floor :: pb = 2/8)
    else if ((2 * l_freq_core_floor) >= io_freq_fbc)
    {
        io_core_floor_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_RATIO_2_8;
    }
    // Under-range, raise error
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_FBC_EFF_CONFIG_CORE_FLOOR_FREQ_RATIO_ERR()
                    .set_FREQ_PB(io_freq_fbc)
                    .set_FREQ_CORE_FLOOR(l_freq_core_floor),
                    "Unsupported core floor/PB frequency ratio = (%d/%d)",
                    l_freq_core_floor, io_freq_fbc);
    }

    // determine table index based on fabric/core ceiling frequency ratio
    // breakpoint ratio: core ceiling 4.0, pb 2.0 (cache ceiling :: pb = 8/8)
    if ((io_freq_core_ceiling) >= (2 * io_freq_fbc))
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_8_8;
    }
    // breakpoint ratio: core ceiling 3.5, pb 2.0 (cache ceiling :: pb = 7/8)
    else if ((4 * io_freq_core_ceiling) >= (7 * io_freq_fbc))
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_7_8;
    }
    // breakpoint ratio: core ceiling 3.0, pb 2.0 (cache ceiling :: pb = 6/8)
    else if ((2 * io_freq_core_ceiling) >= (3 * io_freq_fbc))
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_6_8;
    }
    // breakpoint ratio: core ceiling 2.5, pb 2.0 (cache ceiling :: pb = 5/8)
    else if ((4 * io_freq_core_ceiling) >= (5 * io_freq_fbc))
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_5_8;
    }
    // breakpoint ratio: core ceiling 2.0, pb 2.0 (cache ceiling :: pb = 4/8)
    else if (io_freq_core_ceiling >= io_freq_fbc)
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_4_8;
    }
    // breakpoint ratio: core ceiling 1.0, pb 2.0 (cache ceiling :: pb = 2/8)
    else if ((2 * io_freq_core_ceiling) >= io_freq_fbc)
    {
        io_core_ceiling_ratio = fapi2::ENUM_ATTR_PROC_FABRIC_CORE_CEILING_RATIO_RATIO_2_8;
    }
    // Under-range, raise error
    else
    {
        FAPI_ASSERT(false,
                    fapi2::P9_FBC_EFF_CONFIG_CORE_CEILING_FREQ_RATIO_ERR()
                    .set_FREQ_PB(io_freq_fbc)
                    .set_FREQ_CORE_CEILING(io_freq_core_ceiling),
                    "Unsupported core ceiling/PB frequency ratio = (%d/%d)",
                    io_freq_core_ceiling, io_freq_fbc);
    }

    // write attributes
    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO, i_target, io_core_floor_ratio),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_CORE_FLOOR_RATIO)");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO, i_target, io_core_ceiling_ratio),
             "Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_CORE_CEILING_RATIO)");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_fbc_eff_config()
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_PROC_FABRIC_CORE_FLOOR_RATIO_Type l_core_floor_ratio;
    fapi2::ATTR_PROC_FABRIC_CORE_CEILING_RATIO_Type l_core_ceiling_ratio;
    fapi2::ATTR_FREQ_PB_Type l_freq_fbc;
    fapi2::ATTR_FREQ_CORE_CEILING_Type l_freq_core_ceiling;

    FAPI_TRY(p9_fbc_eff_config_process_freq_attributes(
                 FAPI_SYSTEM,
                 l_core_floor_ratio,
                 l_core_ceiling_ratio,
                 l_freq_fbc,
                 l_freq_core_ceiling),
             "Error from p9_fbc_eff_config_process_freq_attributes");

    FAPI_TRY(p9_fbc_eff_config_calc_epsilons(
                 FAPI_SYSTEM,
                 l_core_floor_ratio,
                 l_core_ceiling_ratio,
                 l_freq_fbc,
                 l_freq_core_ceiling),
             "Error from p9_fbc_eff_config_calc_epsilons");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
