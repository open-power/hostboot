/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_build_smp.C $                 */
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
/// @file p9_build_smp.C
/// @brief Perform fabric configuration (FAPI2)
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
#include <p9_build_smp.H>
#include <p9_build_smp_fbc_ab.H>
#include <p9_build_smp_epsilon.H>
#include <p9_build_smp_fbc_nohp.H>
#include <p9_build_smp_fbc_ab.H>
#include <p9_build_smp_fbc_cd.H>

extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

///
/// @brief Calculate SMP ratio and delay settings from input SMP info.
///        Output will be written to the same in/out structure.
///
/// @param[in/out] io_smp     Input/Output p9_build_smp_system data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_calc_ratio_delay_settings(p9_build_smp_system& io_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        // Determine epsilon table index based on pb/core floor frequency ratio
        // Breakpoint ratio: core floor 4.0, pb 2.0 (cache floor :: pb = 8/8)
        if ((io_smp.freq_core_floor) >= (2 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_8_8;
        }
        // breakpoint ratio: core floor 3.5, pb 2.0 (cache floor :: pb = 7/8)
        else if ((4 * io_smp.freq_core_floor) >= (7 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_7_8;
        }
        // breakpoint ratio: core floor 3.0, pb 2.0 (cache floor :: pb = 6/8)
        else if ((2 * io_smp.freq_core_floor) >= (3 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_6_8;
        }
        // breakpoint ratio: core floor 2.5, pb 2.0 (cache floor :: pb = 5/8)
        else if ((4 * io_smp.freq_core_floor) >= (5 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_5_8;
        }
        // breakpoint ratio: core floor 2.0, pb 2.0 (cache floor :: pb = 4/8)
        else if (io_smp.freq_core_floor >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_4_8;
        }
        // breakpoint ratio: core floor 1.0, pb 2.0 (cache floor :: pb = 2/8)
        else if ((2 * io_smp.freq_core_floor) >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = P9_BUILD_SMP_CORE_RATIO_2_8;
        }
        // Under-range, raise error
        else
        {
            FAPI_ASSERT(false,
                        fapi2::PROC_BUILD_SMP_CORE_FLOOR_FREQ_RATIO_ERR()
                        .set_FREQ_PB(io_smp.freq_pb)
                        .set_FREQ_CORE_FLOOR(io_smp.freq_core_floor),
                        "Unsupported core floor/PB frequency "
                        "ratio (=%d/%d)", io_smp.freq_core_floor, io_smp.freq_pb);
        }

        FAPI_INF("Core floor to nest frequency ratio %d", io_smp.core_floor_ratio);


        // TODO: RTC 147511 - No epsilon core ceilling data available yet.
        // Need to init values in structure whenever values are available.

        // Determine table index based on pb/core ceiling frequency ratio
        // Breakpoint ratio: core ceiling 4.8, pb 2.4 (cache ceiling :: pb = 8/8)
        if ((io_smp.freq_core_ceiling) >= (2 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_8_8;
        }
        // breakpoint ratio: core ceiling 4.2, pb 2.4 (cache ceiling :: pb = 7/8)
        else if ((4 * io_smp.freq_core_ceiling) >= (7 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_7_8;
        }
        // breakpoint ratio: core ceiling 3.6, pb 2.4 (cache ceiling :: pb = 6/8)
        else if ((2 * io_smp.freq_core_ceiling) >= (3 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_6_8;
        }
        // breakpoint ratio: core ceiling 3.0, pb 2.4 (cache ceiling :: pb = 5/8)
        else if ((4 * io_smp.freq_core_ceiling) >= (5 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_5_8;
        }
        // breakpoint ratio: core ceiling 2.4, pb 2.4 (cache ceiling :: pb = 4/8)
        else if (io_smp.freq_core_ceiling >= io_smp.freq_pb)
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_4_8;
        }
        // breakpoint ratio: core ceiling 1.2, pb 2.4 (cache ceiling :: pb = 2/8)
        else if ((2 * io_smp.freq_core_ceiling) >= io_smp.freq_pb)
        {
            io_smp.core_ceiling_ratio = P9_BUILD_SMP_CORE_RATIO_2_8;
        }
        // under-range, raise error
        else
        {
            FAPI_ASSERT(false,
                        fapi2::PROC_BUILD_SMP_CORE_CEILING_FREQ_RATIO_ERR()
                        .set_FREQ_PB(io_smp.freq_pb)
                        .set_FREQ_CORE_CEILING(io_smp.freq_core_ceiling),
                        "Unsupported core ceiling/PB frequency ratio (=%d/%d)",
                        io_smp.freq_core_ceiling, io_smp.freq_pb);
        }

        FAPI_INF("Core ceiling to nest frequency ratio %d", io_smp.core_ceiling_ratio);

        // TODO: RTC 147511 - No CPU delay settings available yet
        // Need to init values in structure whenever values are available.

        // Determine full CPU delay settings
        if ((2400 * io_smp.freq_core_ceiling) >= (4800 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4800_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (4431 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4431_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (4114 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4114_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3840 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3840_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3338 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3338_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3032 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3032_2400;
        }
        else
        {
            io_smp.full_cpu_delay = P9_BUILD_SMP_CPU_DELAY_2743_2400;
        }

        FAPI_INF("CPU delay %d", io_smp.full_cpu_delay);

        // Determine nominal CPU delay settings
        if ((2400 * io_smp.freq_core_nom) >= (4800 * io_smp.freq_pb))
        {
            // shift to avoid equivalent index
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4431_2400;
        }
        else if ((2400 * io_smp.freq_core_nom) >= (4431 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4431_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4114_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (4114 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_4114_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3840_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3840 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3840_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3338_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3338 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3338_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3032_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3032 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_3032_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_2743_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (2743 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_2743_2400;

            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_2504_2400;
            }
        }
        else
        {
            io_smp.nom_cpu_delay = P9_BUILD_SMP_CPU_DELAY_2504_2400;
        }

        FAPI_INF("Nominal delay %d", io_smp.nom_cpu_delay);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


///
/// @brief Fill in p9_build_smp_system structure with info such as
///        fabric configuration/frequencies/etc based on attribute settings.
///        The structure will then be used for the SMP build operation later.
///
/// @param[out] o_smp     Output p9_build_smp_system data
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_process_system(p9_build_smp_system& o_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        uint8_t l_tempAttr = 0;

        // Get Nest freq attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PB, FAPI_SYSTEM, o_smp.freq_pb),
                 "Error getting ATTR_FREQ_PB, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_PB 0x%.8X", o_smp.freq_pb);

        // Get A bus frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_A, FAPI_SYSTEM, o_smp.freq_a),
                 "Error getting ATTR_FREQ_A, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_A 0x%.8X", o_smp.freq_a);

        // Get X bus frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_X, FAPI_SYSTEM, o_smp.freq_x),
                 "Error getting ATTR_FREQ_X, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_X 0x%.8X", o_smp.freq_x);

        // Get core floor frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_FLOOR, FAPI_SYSTEM,
                               o_smp.freq_core_floor),
                 "Error getting ATTR_FREQ_CORE_FLOOR, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_CORE_FLOOR 0x%.8X", o_smp.freq_core_floor);

        // Get core nominal frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_NOMINAL, FAPI_SYSTEM,
                               o_smp.freq_core_nom),
                 "Error getting ATTR_FREQ_CORE_NOMINAL, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_CORE_NOMINAL 0x%.8X", o_smp.freq_core_nom);

        // Get core ceiling frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_CEILING, FAPI_SYSTEM,
                               o_smp.freq_core_ceiling),
                 "Error getting ATTR_FREQ_CORE_CEILING, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_CORE_CEILING 0x%.8X", o_smp.freq_core_ceiling);

        // Verify the floor/nominal/ceiling frequencies
        // Expect ceiling >= nominal, nominal >= floor
        FAPI_ASSERT( ((o_smp.freq_core_ceiling >= o_smp.freq_core_nom) &&
                      (o_smp.freq_core_nom     >= o_smp.freq_core_floor)),
                     fapi2::PROC_BUILD_SMP_CORE_FREQ_RANGE_ERR()
                     .set_FREQ_CORE_CEILING(o_smp.freq_core_ceiling)
                     .set_FREQ_CORE_NOM(o_smp.freq_core_nom)
                     .set_FREQ_CORE_FLOOR(o_smp.freq_core_floor),
                     "Invalid core frequency ranges: FLOOR: 0x%.8X, NOMINAL: 0x%.8X, CEILING: 0x%.8X",
                     o_smp.freq_core_floor, o_smp.freq_core_nom, o_smp.freq_core_ceiling);

        // Get PCIe frequency attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PCIE, FAPI_SYSTEM,
                               o_smp.freq_pcie),
                 "Error getting ATTR_FREQ_PCIE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_FREQ_PCIE 0x%.8X", o_smp.freq_pcie);

        // Get PB pump type attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PUMP_MODE, FAPI_SYSTEM,
                               l_tempAttr),
                 "error getting ATTR_PROC_FABRIC_PUMP_MODE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_PROC_FABRIC_PUMP_MODE 0x%.8X", l_tempAttr);

        switch (l_tempAttr)
        {
            case fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_MODE1:
            case fapi2::ENUM_ATTR_PROC_FABRIC_PUMP_MODE_MODE2:
                o_smp.pump_mode = static_cast<p9_fab_smp_pump_mode>(l_tempAttr);
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::P9_FAB_SMP_PUMP_MODE_ATTR_ERR()
                            .set_ATTR_DATA(l_tempAttr),
                            "Invalid fabric pump mode value 0x%02X", l_tempAttr);
                break;
        }

        // Get Epsilon attribute
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_TABLE_TYPE,
                               FAPI_SYSTEM, l_tempAttr),
                 "Error getting ATTR_PROC_EPS_TABLE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_DBG("ATTR_PROC_EPS_TABLE_TYPE 0x%.8X", l_tempAttr);

        switch (l_tempAttr)
        {
            case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_LE:
            case fapi2::ENUM_ATTR_PROC_EPS_TABLE_TYPE_EPS_TYPE_HE:
                o_smp.eps_cfg.table_type =
                    static_cast<p9_fab_smp_eps_table_type>(l_tempAttr);
                break;

            default:
                FAPI_ASSERT(false,
                            fapi2::P9_FAB_SMP_EPSILON_TABLE_TYPE_ATTR_ERR()
                            .set_ATTR_DATA(l_tempAttr),
                            "Invalid epsilon table type attribute value 0x%02X", l_tempAttr);
                break;
        }

        // Set Guardband default value to +20%
        o_smp.eps_cfg.gb_percentage = +20;
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_EPS_GB_PERCENTAGE, FAPI_SYSTEM,
                               o_smp.eps_cfg.gb_percentage),
                 "Error setting ATTR_PROC_EPS_GB_PERCENTAGE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get Gardband attributes
        // Note: if a user makes an attribute override with CONST, it would
        // override the above default value settings. This mechanism is to
        // allow users to change the default settings for testings.
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EPS_GB_PERCENTAGE,
                               FAPI_SYSTEM, o_smp.eps_cfg.gb_percentage),
                 "Error getting ATTR_PROC_EPS_GB_PERCENTAGE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_DBG("ATTR_PROC_EPS_GB_PERCENTAGE %s%d, ",
                 (o_smp.eps_cfg.gb_percentage >= 0) ? ("+") : ("-"),
                 o_smp.eps_cfg.gb_percentage);

        // Call function to calculate ratio and delay setting
        FAPI_TRY(p9_calc_ratio_delay_settings(o_smp),
                 "p9_build_smp: p9_calc_ratio_delay_settings returns an error, "
                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

        // Optic configuration
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SMP_OPTICS_MODE, FAPI_SYSTEM,
                               o_smp.smpOpticsMode),
                 "Error getting ATTR_PROC_FABRIC_SMP_OPTICS_MODE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Query all chip attribute query functions
///        (fabric configuration/node/position)
///
/// @param[in] i_proc_chip    Pointer to HWP input structure for this chip
/// @param[in] io_smp_chip    Structure encapsulating single chip in SMP
///                           topology
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_process_chip(p9_build_smp_proc_chip* i_proc_chip,
            p9_build_smp_chip& io_smp_chip)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        // Set HWP input pointer
        io_smp_chip.chip = i_proc_chip;

        // Display target information for this proc
        char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
        fapi2::toString(io_smp_chip.chip->this_chip, l_targetStr,
                        sizeof(l_targetStr));
        FAPI_INF("Target: %s", l_targetStr);

        // Get node ID attribute
        FAPI_TRY(p9_fab_smp_get_node_id_attr( io_smp_chip.chip->this_chip,
                                              io_smp_chip.node_id ),
                 "p9_fab_smp_get_node_id_attr() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get chip ID attribute
        FAPI_TRY(p9_fab_smp_get_chip_id_attr( io_smp_chip.chip->this_chip,
                                              io_smp_chip.chip_id ),
                 "p9_fab_smp_get_chip_id_attr() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }


///
/// @brief Set chip master status (node/system) for PB operations.
///
/// @param[in] i_first_chip_in_node  First chip processed in node?
/// @param[in] i_op           Procedure operation phase/mode
/// @param[in] io_smp_chip    Structure encapsulating single chip in SMP
///                           topology
/// @param[in] io_smp         Fully specified structure encapsulating SMP
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_set_master_config(
        const bool i_first_chip_in_node,
        const p9_build_smp_operation i_op,
        p9_build_smp_chip& io_smp_chip,
        p9_build_smp_system& io_smp)
    {

        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData;
        bool l_err = false;

        // Retrieve CURR state of node/system master designation from HW
        FAPI_TRY(p9_build_smp_get_hotplug_curr_reg(io_smp_chip, true, l_scomData),
                 "p9_build_smp_get_hotplug_curr_reg() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        io_smp_chip.master_chip_sys_curr =
            l_scomData.getBit<PB_HP_MODE_MASTER_CHIP_BIT>();
        io_smp_chip.master_chip_node_curr =
            l_scomData.getBit<PB_HP_MODE_CHG_RATE_GP_MASTER_BIT>();

        FAPI_DBG("Current reg: 0x%.16llX", l_scomData);
        FAPI_DBG("   master_chip_sys_curr 0x%.8X, master_chip_node_curr 0x%.8X",
                 io_smp_chip.master_chip_sys_curr,
                 io_smp_chip.master_chip_node_curr);


        // Check/set expectation for CURR/NEXT states based on HW state
        // as well as input parameters

        // Call from HBI to initialize scope of HBI drawer
        if (i_op == SMP_ACTIVATE_PHASE1)
        {
            FAPI_DBG("SMP_ACTIVATE_PHASE1");

            // Each chip should match the flush state of the fabric logic
            if (!io_smp_chip.master_chip_sys_curr ||
                io_smp_chip.master_chip_node_curr)
            {
                l_err = true;
            }
            else
            {
                // Set next state
                io_smp_chip.master_chip_node_next = i_first_chip_in_node;
            }
        }
        // Call from FSP used to stitch drawers/CCM
        else if (i_op == SMP_ACTIVATE_PHASE2)
        {
            FAPI_DBG("SMP_ACTIVATE_PHASE2");
            // Set next state
            io_smp_chip.master_chip_node_next = io_smp_chip.master_chip_node_curr;
        }
        // Unsupported operation
        else
        {
            FAPI_ASSERT(false,
                        fapi2::PROC_BUILD_SMP_INVALID_OPERATION_ERR()
                        .set_OP(i_op),
                        "Unsupported input SMP operation 0x%.8X", i_op);
        }

        // Mark system master for launching fabric reconfiguration operations
        // also track which slave fabrics will be quiesced
        FAPI_DBG("master_chip_sys_next 0x%.8X", io_smp_chip.chip->master_chip_sys_next);

        if (io_smp_chip.chip->master_chip_sys_next)
        {
            // this chip will not be quiesced, to enable switch AB
            io_smp_chip.issue_quiesce_next = false;

            // in both activation scenarios, we expect that:
            //   - only a single chip is designated to be the new master
            //   - the newly designated master is currently configured
            //     as a master within the scope of its current enclosing fabric
            if (!io_smp.master_chip_curr_set &&
                io_smp_chip.master_chip_sys_curr)
            {
                io_smp.master_chip_curr_set = true;
                io_smp.master_chip_curr_node_id = io_smp_chip.node_id;
                io_smp.master_chip_curr_chip_id = io_smp_chip.chip_id;
            }
            else
            {
                l_err = true;
            }
        }
        else
        {
            // This chip will not be the new master, but is one now
            // use it to quiesce all chips in its fabric
            if (io_smp_chip.master_chip_sys_curr)
            {
                io_smp_chip.issue_quiesce_next = true;
            }
            else
            {
                io_smp_chip.issue_quiesce_next = false;
            }
        }

        // Assert if local error is set
        FAPI_ASSERT(l_err == false,
                    fapi2::PROC_BUILD_SMP_MASTER_DESIGNATION_ERR()
                    .set_TARGET(io_smp_chip.chip->this_chip)
                    .set_OP(i_op)
                    .set_MASTER_CHIP_SYS_CURR(io_smp_chip.master_chip_sys_curr)
                    .set_MASTER_CHIP_NODE_CURR(io_smp_chip.master_chip_node_curr)
                    .set_MASTER_CHIP_SYS_NEXT(io_smp_chip.chip->master_chip_sys_next)
                    .set_MASTER_CHIP_NODE_NEXT(io_smp_chip.master_chip_node_next)
                    .set_SYS_RECONFIG_MASTER_SET(io_smp.master_chip_curr_set),
                    "Node/system master designation error");

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Insert chip structure into proper position within SMP model based
///        on its fabric node/chip ID
///
/// @param[in/out] io_smp_chip    Structure encapsulating single chip in
///                               SMP topology.
/// @param[in] i_op               Procedure operation phase/mode
/// @param[in/out] io_smp         Fully specified structure encapsulating SMP
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_insert_chip(p9_build_smp_chip& io_smp_chip,
            const p9_build_smp_operation i_op,
            p9_build_smp_system& io_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        // Node/chip ID
        p9_fab_smp_node_id l_nodeId = io_smp_chip.node_id;
        p9_fab_smp_chip_id l_chipId = io_smp_chip.chip_id;

        // Chip/Node map iterators
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;

        // First chip found in node?
        bool l_firstChipInNode = false;

        FAPI_INF("Inserting n%d p%d", l_nodeId, l_chipId);

        // Search to see if node structure already exists for the node ID
        // associated with this chip
        n_iter = io_smp.nodes.find(l_nodeId);

        // If no matching node found, create one
        if (n_iter == io_smp.nodes.end())
        {
            FAPI_DBG("proc_build_smp_insert_chip: No matching node found, "
                     "inserting new node structure");

            p9_build_smp_node l_smpNode;
            l_smpNode.node_id = io_smp_chip.node_id;

            std::pair<std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator,
                bool> l_ret;
            l_ret = io_smp.nodes.insert(
                        std::pair<p9_fab_smp_node_id, p9_build_smp_node>
                        (l_nodeId, l_smpNode) );
            n_iter = l_ret.first;

            FAPI_ASSERT(l_ret.second,
                        fapi2::PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR()
                        .set_TARGET(io_smp_chip.chip->this_chip)
                        .set_NODE_ID(l_nodeId),
                        "Error encountered adding node to SMP");

            // First chip in node
            l_firstChipInNode = true;
        }

        // Search to see if match exists in this node for the chip ID associated
        // with this chip
        p_iter = io_smp.nodes[l_nodeId].chips.find(l_chipId);

        // Matching chip ID & node ID already found, flag an error
        FAPI_ASSERT(p_iter == io_smp.nodes[l_nodeId].chips.end(),
                    fapi2::PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR()
                    .set_TARGET1(io_smp_chip.chip->this_chip)
                    .set_TARGET2(p_iter->second.chip->this_chip)
                    .set_NODE_ID(l_nodeId)
                    .set_CHIP_ID(l_chipId),
                    "Duplicate fabric nodeID/chipID "
                    "found");

        // Determine node/system master status
        FAPI_TRY(p9_build_smp_set_master_config(l_firstChipInNode, i_op,
                                                io_smp_chip, io_smp),
                 "p9_build_smp_set_master_config() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Insert chip into SMP
        io_smp.nodes[l_nodeId].chips[l_chipId] = io_smp_chip;

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Process X/A links of a proc chip.
///
/// @param[in] i_smp_proc_chip    Structure defining properties of a proc chip
/// @param[in] i_smp_chip         Structure encapsulating single chip in SMP
/// @param[in] i_local_node_id    This chip's node ID
/// @param[in] i_local_chip_id    This chip's chip ID
/// @param[in] i_nodeIdsInSystem  Bit-wise marking the existed nodes in system.
/// @param[in] i_chipIdsInNode    Bit-wise marking the existed chips in the
///                               node where this chip resides.
///
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_process_proc_links(
        p9_build_smp_proc_chip& i_smp_proc_chip,
        const p9_build_smp_chip& i_smp_chip,
        const p9_fab_smp_node_id i_local_node_id,
        const p9_fab_smp_chip_id i_local_chip_id,
        const fapi2::buffer<uint8_t> i_nodeIdsInSystem,
        const fapi2::buffer<uint8_t> i_chipIdsInNode)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;

        bool internode_set_match = false;
        bool intranode_set_match = false;

        fapi2::buffer<uint8_t> l_xConnectedChipIds;
        fapi2::buffer<uint8_t> l_aConnectedNodeIds;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_XBUS>*> l_xLinkTargets;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>*> l_oLinkTargets;

        // Process X-connected chips
        l_xLinkTargets.push_back(&i_smp_proc_chip.x0_chip);
        l_xLinkTargets.push_back(&i_smp_proc_chip.x1_chip);
        l_xLinkTargets.push_back(&i_smp_proc_chip.x2_chip);

        for (auto l_xbusItr = l_xLinkTargets.begin();
             l_xbusItr != l_xLinkTargets.end();
             ++l_xbusItr)
        {
            bool l_linkIsEnabled = false;
            p9_fab_smp_node_id dest_node_id;
            p9_fab_smp_chip_id dest_chip_id;

            FAPI_TRY(p9_build_smp_query_link_state(i_smp_chip,
                                                   (l_xbusItr - l_xLinkTargets.begin()),
                                                   **l_xbusItr,
                                                   l_linkIsEnabled,
                                                   dest_node_id,
                                                   dest_chip_id),
                     "(XBUS): p9_build_smp_query_link_state() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            if (l_linkIsEnabled)
            {
                if (dest_node_id == i_local_node_id)
                {
                    FAPI_TRY(l_xConnectedChipIds.setBit(dest_chip_id),
                             "(XBUS): (l_xConnectedChipIds.setBit() returns an error, "
                             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
                }
                else
                {
                    FAPI_TRY(l_xConnectedChipIds.clearBit(dest_chip_id),
                             "(XBUS): (l_xConnectedChipIds.clearBit() returns an error, "
                             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
                }

                FAPI_INF("(XBUS): n%d:p%d X%zd -> n%d:p%d",
                         i_local_node_id, i_local_chip_id,
                         (l_xbusItr - l_xLinkTargets.begin()),
                         dest_node_id, dest_chip_id);
            }
        }

        // OBUS targets
        l_oLinkTargets.push_back(&i_smp_proc_chip.o0_chip);
        l_oLinkTargets.push_back(&i_smp_proc_chip.o1_chip);
        l_oLinkTargets.push_back(&i_smp_proc_chip.o2_chip);
        l_oLinkTargets.push_back(&i_smp_proc_chip.o3_chip);

        // Process O-connected chips
        for (auto l_obusItr = l_oLinkTargets.begin();
             l_obusItr != l_oLinkTargets.end();
             ++l_obusItr)
        {
            bool l_linkIsEnabled = false;
            p9_fab_smp_node_id dest_node_id;
            p9_fab_smp_chip_id dest_chip_id;

            FAPI_TRY(p9_build_smp_query_link_state(i_smp_chip,
                                                   (l_obusItr - l_oLinkTargets.begin()),
                                                   **l_obusItr,
                                                   l_linkIsEnabled,
                                                   dest_node_id,
                                                   dest_chip_id),
                     "(OBUS): p9_build_smp_query_link_state() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            if (l_linkIsEnabled)
            {
                // Optic configured as XBUS
                if (i_smp_chip.smpOpticsMode ==
                    fapi2::ENUM_ATTR_PROC_FABRIC_SMP_OPTICS_MODE_OPTICS_IS_X_BUS)
                {
                    // Additional X links from optic
                    // Set bit #3 thru 6 to indicate more X-links
                    if (dest_node_id == i_local_node_id)
                    {
                        FAPI_TRY(l_xConnectedChipIds.setBit(dest_chip_id +
                                                            P9_FAB_SMP_NUM_X_LINKS),
                                 "(OBUS): (l_xConnectedChipIds.setBit() returns an error, "
                                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
                    }
                    else
                    {
                        FAPI_TRY(l_xConnectedChipIds.clearBit(dest_chip_id +
                                                              P9_FAB_SMP_NUM_X_LINKS),
                                 "(OBUS): (l_xConnectedChipIds.clearBit() returns an error, "
                                 "l_rc 0x%.8X",
                                 (uint64_t)fapi2::current_err);
                    }

                    FAPI_INF("(OBUS): n%d:p%d X%zd -> n%d:p%d",
                             i_local_node_id, i_local_chip_id,
                             (l_obusItr - l_oLinkTargets.begin()),
                             dest_node_id, dest_chip_id);
                }
                // Optic configured as ABUS
                else
                {
                    if (dest_chip_id == i_local_chip_id)
                    {
                        FAPI_TRY(l_aConnectedNodeIds.setBit(dest_node_id),
                                 "(OBUS): l_aConnectedNodeIds.setBit() returns an error, "
                                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
                    }
                    else
                    {
                        FAPI_TRY(l_aConnectedNodeIds.clearBit(dest_node_id),
                                 "(OBUS): (l_aConnectedNodeIds.clearBit() returns an error, "
                                 "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
                    }

                    FAPI_INF("(OBUS): n%d:p%d X%zd -> n%d:p%d",
                             i_local_node_id, i_local_chip_id,
                             (l_obusItr - l_oLinkTargets.begin()),
                             dest_node_id, dest_chip_id);
                }
            }
        }

        // Add IDs associated with current chip, to make direct set comparison easy
        FAPI_DBG("Checking connectivity for n%d:p%d", i_local_node_id, i_local_chip_id);

        FAPI_TRY(l_xConnectedChipIds.setBit(i_local_chip_id),
                 "l_xConnectedChipIds.setBit() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        FAPI_TRY(l_aConnectedNodeIds.setBit(i_local_node_id),
                 "l_xConnectedChipIds.setBit() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Compare ID sets, exit if they don't match
        internode_set_match = (i_nodeIdsInSystem == l_aConnectedNodeIds);
        intranode_set_match = (i_chipIdsInNode == l_xConnectedChipIds);

        if (!internode_set_match ||
            !intranode_set_match)
        {
            // Display target information
            char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
            fapi2::toString(i_smp_proc_chip.this_chip, l_targetStr,
                            sizeof(l_targetStr));

            if (!intranode_set_match)
            {
                FAPI_ERR("Target %s is not fully connected (X) to all other chips "
                         "in its node", l_targetStr);
            }

            if (!internode_set_match)
            {
                FAPI_ERR("Target %s is not fully connected (A) to all other nodes",
                         l_targetStr);
            }

            FAPI_ASSERT(false,
                        fapi2::PROC_BUILD_SMP_INVALID_TOPOLOGY()
                        .set_TARGET(i_smp_proc_chip.this_chip)
                        .set_A_CONNECTIONS_OK(internode_set_match)
                        .set_A_CONNECTED_NODE_IDS(l_aConnectedNodeIds)
                        .set_X_CONNECTIONS_OK(intranode_set_match)
                        .set_X_CONNECTED_CHIP_IDS(l_xConnectedChipIds),
                        "Invalid fabric topology detected!!");
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief Process all HWP input structures and build SMP data structure
///
/// @param[in] i_proc_chips    Vector of HWP input structures (one entry per
///                            chip in SMP)
/// @param[in] i_op            Procedure operation phase/mode
/// @param[in] io_smp          Fully specified structure encapsulating SMP
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_build_smp_process_chips(
        std::vector<p9_build_smp_proc_chip>& i_proc_chips,
        const p9_build_smp_operation i_op,
        p9_build_smp_system& io_smp)
    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

        // Mapping of node/chip id vs smp info data
        std::map<p9_fab_smp_node_id, p9_build_smp_node>::iterator n_iter;
        std::map<p9_fab_smp_chip_id, p9_build_smp_chip>::iterator p_iter;

        fapi2::buffer<uint8_t> l_nodeIdsInSystem;
        fapi2::buffer<uint8_t> l_chipIdsInNode;

        std::vector<fapi2::Target<fapi2::TARGET_TYPE_XBUS>*> l_xLinkTargets;
        std::vector<fapi2::Target<fapi2::TARGET_TYPE_OBUS>*> l_oLinkTargets;

        io_smp.master_chip_curr_set = false;

        // Loop over input proc chips
        for (auto itr = i_proc_chips.begin(); itr != i_proc_chips.end(); ++itr)
        {
            // Process platform provided data in chip argument,
            // Query chip specific attributes
            p9_build_smp_chip smp_chip;
            FAPI_TRY(p9_build_smp_process_chip( &(*itr), smp_chip ),
                     "p9_build_smp_process_chip() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Copy system attribute to chip structure for later use
            smp_chip.smpOpticsMode = io_smp.smpOpticsMode;

            // Insert chip into SMP data structure given node & chip ID
            FAPI_TRY(p9_build_smp_insert_chip( smp_chip, i_op, io_smp ),
                     "p9_build_smp_insert_chip() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Set attached chips' attributes
            FAPI_TRY(p9_fab_set_attached_chip_attr(itr->this_chip),
                     "p9_fab_set_attached_chip_attr() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Ensure that new master was designated
        FAPI_ASSERT(io_smp.master_chip_curr_set,
                    fapi2::PROC_BUILD_SMP_NO_MASTER_SPECIFIED_ERR()
                    .set_OP(i_op),
                    "No system master specified!");


        // Based on master designation, and operation phase,
        // determine whether each chip will be quiesced as a result
        // of switch activity
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                if (((i_op == SMP_ACTIVATE_PHASE1) &&
                     (p_iter->second.issue_quiesce_next)) ||
                    ((i_op == SMP_ACTIVATE_PHASE2) &&
                     (n_iter->first != io_smp.master_chip_curr_node_id)))
                {
                    p_iter->second.quiesced_next = true;
                }
                else
                {
                    p_iter->second.quiesced_next = false;
                }
            }
        }

        // Check that fabric topology is logically valid
        // 1) In a given node, all chips are connected to every other
        //    chip in the node, by an X bus
        // 2) Each chip is connected to its partner chip (with same chip id)
        //    in every other node, by an A bus

        // Build set of all valid node ids in system
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            FAPI_INF("Adding n%d", n_iter->first);
            FAPI_TRY(l_nodeIdsInSystem.setBit(n_iter->first),
                     "l_nodeIdsInSystem.setBit() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

        }

        // Iterate over all nodes
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            // Build set of all valid chip ids in node
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                FAPI_INF("Adding n%d:p%d", n_iter->first, p_iter->first);
                FAPI_TRY(l_chipIdsInNode.setBit(p_iter->first),
                         "l_chipIdsInNode.setBit() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }

            // Iterate over all chips in current node
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                FAPI_INF("Processing links for n%d:p%d", n_iter->first, p_iter->first);

                // Process X/A links
                FAPI_TRY(p9_process_proc_links(*p_iter->second.chip,
                                               p_iter->second,
                                               n_iter->first,
                                               p_iter->first,
                                               l_nodeIdsInSystem,
                                               l_chipIdsInNode),
                         "p9_process_proc_links() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

///
/// @brief p9_build_smp procedure entry point
/// See doxygen in p9_build_smp.H
///
    fapi2::ReturnCode p9_build_smp(
        std::vector<p9_build_smp_proc_chip>& i_proc_chips,
        const p9_build_smp_operation i_op)

    {
        FAPI_DBG("Start");
        fapi2::ReturnCode l_rc;
        p9_build_smp_system l_smp;

        // Get the p9 target attributes needed to perform grouping
        FAPI_TRY(p9_build_smp_process_system(l_smp),
                 "p9_build_smp_process_system() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Process HWP input vector of chip structures
        FAPI_TRY(p9_build_smp_process_chips(i_proc_chips, i_op, l_smp),
                 "p9_build_smp_process_chips() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Initialize fabric configuration
        if (i_op == SMP_ACTIVATE_PHASE1)
        {
            // Program nest epsilon attributes/registers
            FAPI_TRY(p9_build_smp_set_epsilons(l_smp),
                     "p9_build_smp_set_epsilons() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Set fabric configuration registers (non-hotplug)
            FAPI_TRY(p9_build_smp_set_fbc_nohp(l_smp),
                     "p9_build_smp_set_fbc_nohp() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Set fabric configuration registers (hotplug, switch CD set)
            FAPI_TRY(p9_build_smp_set_fbc_cd(l_smp),
                     "p9_build_smp_set_fbc_nohp() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Set fabric trace configuration registers (non-hotplug)
        FAPI_TRY(p9_build_smp_set_fbc_nohp_trace(l_smp),
                 "p9_build_smp_set_fbc_nohp_trace() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);


        // Activate SMP
        // Set fabric configuration registers (hotplug, switch AB set)
        FAPI_TRY(p9_build_smp_set_fbc_ab(l_smp, i_op),
                 "p9_build_smp_set_fbc_ab() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

    fapi_try_exit:
        FAPI_DBG("End");
        return fapi2::current_err;
    }

} // extern "C"
