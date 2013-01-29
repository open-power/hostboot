/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2013              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
// $Id: proc_build_smp.C,v 1.7 2013/01/28 14:45:45 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp.C
// *! DESCRIPTION : Perform fabric configuration (FAPI)
// *!
// *! OWNER NAME  : Joe McGill              Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp.H"
#include "proc_build_smp_epsilon.H"
#include "proc_build_smp_fbc_nohp.H"
#include "proc_build_smp_fbc_ab.H"
#include "proc_build_smp_fbc_cd.H"
#include "proc_build_smp_adu.H"

extern "C"
{

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: wrapper function to call all system attribute query functions
//           (fabric configuration/frequencies/etc)
// parameters: io_smp_chip => structure encapsulating single chip in SMP topology
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_FAB_SMP_X_BUS_WIDTH_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_PUMP_TYPE_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_MCS_INTERLEAVED_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_EPSILON_TABLE_TYPE_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_EPSILON_GB_DIRECTION_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_CORE_FLOOR_FREQ_RATIO_ERR if cache/nest frequency
//              ratio is unsupported,
//          RC_PROC_FAB_SMP_ASYNC_SAFE_MODE_ATTR_ERR if attribute value is
//              invalid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_process_system(
    proc_build_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;
    // temporary attribute storage
    uint8_t temp_attr;

    // mark function entry
    FAPI_DBG("proc_build_smp_process_system: Start");

    do
    {
        // get PB frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying PB frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_PB,
                           NULL,
                           io_smp.freq_pb);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_PB");
            break;
        }

        // get A bus frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying A bus frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_A,
                           NULL,
                           io_smp.freq_a);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_A");
            break;
        }

        // get X bus frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying X bus frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_X,
                           NULL,
                           io_smp.freq_x);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_X");
            break;
        }

        // get core floor frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying core floor frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_BOOT_FREQ_MHZ,
                           NULL,
                           io_smp.freq_core_floor);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_BOOT_FREQ_MHZ");
            break;
        }

        // get PCIe frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying PCIe frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_PCIE,
                           NULL,
                           io_smp.freq_pcie);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_PCIE");
            break;
        }

        // get X bus width attribute
        FAPI_DBG("proc_build_smp_process_system: Querying X bus width attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_X_BUS_WIDTH,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_X_BUS_WIDTH)");
            break;
        }

        // translate to output value
        switch (temp_attr)
        {
            case 1:
                io_smp.x_bus_8B = false;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_X_BUS_WIDTH = 4B");
                break;
            case 2:
                io_smp.x_bus_8B = true;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_X_BUS_WIDTH = 8B");
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid X bus width attribute value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_X_BUS_WIDTH_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // get PB pump type attribute
        FAPI_DBG("proc_build_smp_process_system: Querying PB pump mode attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_PUMP_MODE,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_PUMP_MODE)");
            break;
        }

        // translate to output value
        switch (temp_attr)
        {
            case 1:
                io_smp.pump_mode = PROC_FAB_SMP_PUMP_MODE1;
                FAPI_DBG("proc_build_smp_process_system: ATTR_FABRIC_PROC_PUMP_MODE = NODAL_IS_CHIP_GROUP_IS_GROUP");
                break;
            case 2:
                io_smp.pump_mode = PROC_FAB_SMP_PUMP_MODE2;
                FAPI_DBG("proc_build_smp_process_system: ATTR_FABRIC_PROC_PUMP_MODE = NODAL_AND_GROUP_IS_GROUP");
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid fabric pump mode attribute value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_PUMP_MODE_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // get MCS interleaving attribute
        FAPI_DBG("proc_build_smp_process_system: Querying MC interleave attribute");
        rc = FAPI_ATTR_GET(ATTR_ALL_MCS_IN_INTERLEAVING_GROUP,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_ALL_MCS_IN_INTERLEAVING_GROUP)");
            break;
        }

        // translate to output value
        switch (temp_attr)
        {
            case 0:
                io_smp.all_mcs_interleaved = false;
                FAPI_DBG("proc_build_smp_process_system: ATTR_ALL_MCS_IN_INTERLEAVING_GROUP = false");
                break;
            case 1:
                FAPI_DBG("proc_build_smp_process_system: ATTR_ALL_MCS_IN_INTERLEAVING_GROUP = true");
                io_smp.all_mcs_interleaved = true;
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid MCS interleaving value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_MCS_INTERLEAVED_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // get epsilon attributes
        FAPI_DBG("proc_build_smp_process_system: Querying epsilon table type attribute");
        rc = FAPI_ATTR_GET(ATTR_PROC_EPS_TABLE_TYPE,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_EPS_TABLE_TYPE)");
            break;
        }

        // translate to output value
        switch (temp_attr)
        {
            case 1:
                io_smp.eps_cfg.table_type = PROC_FAB_SMP_EPSILON_TABLE_TYPE_LE;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_TABLE_TYPE = LE");
                break;
            case 2:
                io_smp.eps_cfg.table_type = PROC_FAB_SMP_EPSILON_TABLE_TYPE_HE;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_TABLE_TYPE = HE");
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid epsilon table type attribute value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_EPSILON_TABLE_TYPE_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        FAPI_DBG("proc_build_smp_process_system: Querying epsilon guardband attributes");
        // set default value (+20%)
        temp_attr = 0x0;
        rc = FAPI_ATTR_SET(ATTR_PROC_EPS_GB_DIRECTION,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_SET (ATTR_PROC_EPS_GB_DIRECTION)");
            break;
        }

        io_smp.eps_cfg.gb_percentage = 20;
        rc = FAPI_ATTR_SET(ATTR_PROC_EPS_GB_PERCENTAGE,
                           NULL,
                           io_smp.eps_cfg.gb_percentage);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_SET (ATTR_PROC_EPS_GB_PERCENTAGE)");
            break;
        }

        // retrieve guardband attributes
        // if user overrides are set, the user overrides will take presedence over writes above
        rc = FAPI_ATTR_GET(ATTR_PROC_EPS_GB_DIRECTION,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_EPS_GB_DIRECTION)");
            break;
        }

        rc = FAPI_ATTR_GET(ATTR_PROC_EPS_GB_PERCENTAGE,
                           NULL,
                           io_smp.eps_cfg.gb_percentage);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_EPS_GB_PERCENTAGE)");
            break;
        }

        // print attribute values
        FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_GB_PERCENTAGE = 0x%X",
                 io_smp.eps_cfg.gb_percentage);

        // translate to output value
        switch (temp_attr)
        {
            case 0:
                io_smp.eps_cfg.gb_positive = true;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_GB_DIRECTION = +");
                break;
            case 1:
                io_smp.eps_cfg.gb_positive = false;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_GB_DIRECTION = -");
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid epsilon guardband direction attribute value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_EPSILON_GB_DIRECTION_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // manage safe mode attribute
        FAPI_DBG("proc_build_smp_process_system: Querying async safe mode attribute");
        // set default value (performance mode)
        temp_attr = 0x0;
        rc = FAPI_ATTR_SET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_SET (ATTR_PROC_FABRIC_ASYNC_SAFE_MODE)");
            break;
        }

        // retrieve safe mode attribute
        // if user overrides is set, it will take precedence over write above
        rc = FAPI_ATTR_GET(ATTR_PROC_FABRIC_ASYNC_SAFE_MODE,
                           NULL,
                           temp_attr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_ASYNC_SAFE_MODE)");
            break;
        }

        // translate to output value
        switch (temp_attr)
        {
            case 0:
                io_smp.async_safe_mode = false;
                FAPI_DBG("proc_build_smp_process_system: ATTR_FABRIC_PROC_ASYNC_SAFE_MODE = false");
                break;
            case 1:
                io_smp.async_safe_mode = true;
                FAPI_DBG("proc_build_smp_process_system: ATTR_FABRIC_PROC_ASYNC_SAFE_MODE = true");
                break;
            default:
                FAPI_ERR("proc_build_smp_process_system: Invalid fabric async safe mode attribute value 0x%02X",
                         temp_attr);
                const uint8_t& ATTR_DATA = temp_attr;
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_FAB_SMP_ASYNC_SAFE_MODE_ATTR_ERR);
                break;
        }
        if (!rc.ok())
        {
            break;
        }

        // determine epsilon table index based on pb/core floor frequency ratio
        // breakpoint ratio: core floor 4.8, pb 2.4 (cache floor :: pb = 8/8)
        FAPI_DBG("proc_build_smp_process_system: Calculating core floor to nest frequency ratio");
        if ((io_smp.freq_core_floor) >= (2 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_8_8;
        }
        // breakpoint ratio: core floor 4.2, pb 2.4 (cache floor :: pb = 7/8)
        else if ((4 * io_smp.freq_core_floor) >= (7 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_7_8;
        }
        // breakpoint ratio: core floor 3.6, pb 2.4 (cache floor :: pb = 6/8)
        else if ((2 * io_smp.freq_core_floor) >= (3 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_6_8;
        }
        // breakpoint ratio: core floor 3.0, pb 2.4 (cache floor :: pb = 5/8)
        else if ((4 * io_smp.freq_core_floor) >= (5 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_5_8;
        }
        // breakpoint ratio: core floor 2.4, pb 2.4 (cache floor :: pb = 4/8)
        else if (io_smp.freq_core_floor >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_4_8;
        }
        // breakpoint ratio: core floor 1.2, pb 2.4 (cache floor :: pb = 2/8)
        else if ((2 * io_smp.freq_core_floor) >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_FLOOR_RATIO_2_8;
        }
        // under-range, raise error
        else
        {
            FAPI_ERR("proc_build_smp_process_system: Unsupported core floor/PB frequency ratio (=%d/%d)",
                     io_smp.freq_core_floor, io_smp.freq_pb);
            const uint32_t& FREQ_PB = io_smp.freq_pb;
            const uint32_t& FREQ_CORE_FLOOR = io_smp.freq_core_floor;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_CORE_FLOOR_FREQ_RATIO_ERR);
            break;
        }
    } while(0);

    // mark function entry
    FAPI_DBG("proc_build_smp_process_system: End");
    return rc;
};


//------------------------------------------------------------------------------
// function: wrapper function to call all chip attribute query functions
//           (fabric configuration/node/position)
// parameters: i_proc_chip => pointer to HWP input structure for this chip
//             io_smp_chip => structure encapsulating single chip in SMP topology
// returns: FAPI_RC_SUCCESS if all attribute reads are successful & values
//              are valid,
//          RC_PROC_FAB_SMP_PCIE_NOT_F_LINK_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_process_chip(
    proc_build_smp_proc_chip* i_proc_chip,
    proc_build_smp_chip& io_smp_chip)
{
    // return code
    fapi::ReturnCode rc;
    uint8_t pcie_enabled;
    uint8_t nx_enabled;
    uint8_t x_enabled;
    uint8_t a_enabled;

    // mark function entry
    FAPI_DBG("proc_build_smp_process_chip: Start");

    do
    {
        // set HWP input pointer
        io_smp_chip.chip = i_proc_chip;

        // display target information for this chip
        FAPI_DBG("proc_build_smp_process_chip: Target: %s",
                 io_smp_chip.chip->this_chip.toEcmdString());

        // get PCIe/DSMP mux attributes
        FAPI_DBG("proc_build_smp_process_chip: Querying PCIe/DSMP mux attribute");
        rc = proc_fab_smp_get_pcie_dsmp_mux_attrs(&(io_smp_chip.chip->this_chip),
                                                  io_smp_chip.pcie_not_f_link);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error from proc_fab_smp_get_pcie_dsmp_mux_attrs");
            break;
        }

        // get node ID attribute
        FAPI_DBG("proc_build_smp_process_chip: Querying node ID attribute");
        rc = proc_fab_smp_get_node_id_attr(&(io_smp_chip.chip->this_chip),
                                           io_smp_chip.node_id);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error from proc_fab_smp_get_node_id_attr");
            break;
        }

        // get chip ID attribute
        FAPI_DBG("proc_build_smp_process_chip: Querying chip ID attribute");
        rc = proc_fab_smp_get_chip_id_attr(&(io_smp_chip.chip->this_chip),
                                           io_smp_chip.chip_id);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error from proc_fab_smp_get_chip_id_attr");
            break;
        }

        // query NX partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_NX_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           nx_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_NX_ENABLE");
            break;
        }

        // query X partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           x_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_X_ENABLE");
            break;
        }

        // query A partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           a_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_A_ENABLE");
            break;
        }

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           pcie_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_setup_bars_process_chip: Error querying ATTR_PROC_PCIE_ENABLE");
            break;
        }

        io_smp_chip.nx_enabled =
            (nx_enabled == fapi::ENUM_ATTR_PROC_NX_ENABLE_ENABLE);

        io_smp_chip.x_enabled =
            (x_enabled == fapi::ENUM_ATTR_PROC_X_ENABLE_ENABLE);

        io_smp_chip.a_enabled =
            (a_enabled == fapi::ENUM_ATTR_PROC_A_ENABLE_ENABLE);

        io_smp_chip.pcie_enabled =
            (pcie_enabled == fapi::ENUM_ATTR_PROC_PCIE_ENABLE_ENABLE);

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_process_chip: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: set chip master status (node/system) for PB operations
// parameters: i_first_chip_in_sys  => first chip processed in system?
//             i_first_chip_in_node => first chip processed in node?
//             i_op                 => procedure operation phase/mode
//             io_smp_chip          => structure encapsulating single chip in
//                                     SMP topology
//             io_smp               => structure encapsulating SMP
//             o_master_chip_sys    => indication that this chip is current
//                                     system master
// returns: FAPI_RC_SUCCESS if insertion is successful and merged node ranges
//              are valid,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_master_config(
    const bool i_first_chip_in_sys,
    const bool i_first_chip_in_node,
    const proc_build_smp_operation i_op,
    proc_build_smp_chip& io_smp_chip,
    proc_build_smp_system& io_smp,
    bool & o_master_chip_sys)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    bool error = false;
    o_master_chip_sys = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_master_config: Start");

    do
    {
        // retrieve CURR state of node/system master designation from HW
        rc = proc_build_smp_get_hotplug_curr_reg(io_smp_chip,
                                                 true,
                                                 data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_master_config: Error from proc_build_smp_get_hotplug_curr_reg");
            break;
        }

        io_smp_chip.master_chip_sys_curr =
            (data.isBitSet(PB_HP_MODE_MASTER_CHIP_BIT));

        io_smp_chip.master_chip_node_curr =
            (data.isBitSet(PB_HP_MODE_CHG_RATE_GP_MASTER_BIT));

        // check/set expectation for NEXT state based on current HW programming
        // as well as input parameters
        // HBI
        if (i_op == SMP_ACTIVATE_PHASE1)
        {
            // check input state
            if (!io_smp_chip.master_chip_sys_curr ||
                io_smp_chip.master_chip_node_curr)
            {
                error = true;
            }
            // set next state based on input parameters
            io_smp_chip.master_chip_sys_next = i_first_chip_in_sys;
            io_smp_chip.master_chip_node_next = i_first_chip_in_node;

            // set current system master pointer
            if (!io_smp.master_chip_curr_set &&
                io_smp_chip.master_chip_sys_curr)
            {
                o_master_chip_sys = true;
            }
        }
        // FSP
        else if (i_op == SMP_ACTIVATE_PHASE2)
        {
            // if designated as new master, should already be one
            if (!io_smp_chip.master_chip_sys_curr &&
                i_first_chip_in_sys)
            {
                error = true;
            }

            // set next state based on input parameters
            io_smp_chip.master_chip_sys_next = i_first_chip_in_sys;
            io_smp_chip.master_chip_node_next = io_smp_chip.master_chip_node_curr;

            // set current system master pointer
            if (!io_smp.master_chip_curr_set &&
                io_smp_chip.master_chip_sys_curr)
            {
                o_master_chip_sys = true;
            }
        }
        // unsupported operation
        else
        {
            FAPI_ERR("proc_build_smp_set_master_config: Unsupported operation presented");
            const uint8_t& OP = i_op;
            FAPI_SET_HWP_ERROR(
                rc,
                RC_PROC_BUILD_SMP_INVALID_OPERATION_ERR);
            break;
        }

        // error for supported operation
        if (error)
        {
           FAPI_ERR("proc_build_smp_set_master_config: Node/system master designation error");
           const uint8_t& OP = i_op;
           const bool& MASTER_CHIP_SYS_CURR = io_smp_chip.master_chip_sys_curr;
           const bool& MASTER_CHIP_NODE_CURR = io_smp_chip.master_chip_node_curr;
           const bool& FIRST_CHIP_IN_SYS = i_first_chip_in_sys;
           const bool& FIRST_CHIP_IN_NODE = i_first_chip_in_node;
           FAPI_SET_HWP_ERROR(
               rc,
               RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR);
           break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_master_config: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: insert chip structure into proper position within SMP model based
//           on its fabric node/chip ID
// parameters: io_smp_chip          => structure encapsulating single chip in
//                                     SMP topology
//             i_first_chip_in_sys  => first chip processed in system?
//             i_op                 => procedure operation phase/mode
//             io_smp               => structure encapsulating full SMP
// returns: FAPI_RC_SUCCESS if insertion is successful and merged node ranges
//              are valid,
//          RC_PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_insert_chip(
    proc_build_smp_chip& io_smp_chip,
    const bool i_first_chip_in_sys,
    const proc_build_smp_operation i_op,
    proc_build_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;
    // node/chip ID
    proc_fab_smp_node_id node_id = io_smp_chip.node_id;
    proc_fab_smp_chip_id chip_id = io_smp_chip.chip_id;
    // first chip found in node?
    bool first_chip_in_node  = false;
    // chip is current SMP master?
    bool master_chip_sys_curr;

    // mark function entry
    FAPI_DBG("proc_build_smp_insert_chip: Start");

    do
    {
        FAPI_DBG("proc_build_smp_insert_chip: Inserting n%d p%d",
                 node_id, chip_id);

        // search to see if node structure already exists for the node ID
        // associated with this chip
        std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator
            n_iter;
        n_iter = io_smp.nodes.find(node_id);
        // no matching node found, create one
        if (n_iter == io_smp.nodes.end())
        {
            FAPI_DBG("proc_build_smp_insert_chip: No matching node found, inserting new node structure");
            proc_build_smp_node n;
            n.node_id = io_smp_chip.node_id;
            std::pair<
                std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator,
                bool> ret;
            ret = io_smp.nodes.insert(
                std::pair<proc_fab_smp_node_id, proc_build_smp_node>
                (node_id, n));
            n_iter = ret.first;
            if (!ret.second)
            {
                FAPI_ERR("proc_build_smp_insert_chip: Error encountered adding node to SMP");
                FAPI_SET_HWP_ERROR(rc,
                    RC_PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR);
                break;
            }
            // first chip in node
            first_chip_in_node = true;
        }

        // search to see if match exists in this node for the chip ID associated
        // with this chip
        std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator
            p_iter;
        p_iter = io_smp.nodes[node_id].chips.find(chip_id);
        // matching chip ID & node ID already found, flag an error
        if (p_iter != io_smp.nodes[node_id].chips.end())
        {
            FAPI_ERR("proc_build_smp_insert_chip: Duplicate fabric node ID / chip ID found");
            const uint8_t& NODE_ID = node_id;
            const uint8_t& CHIP_ID = chip_id;
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR);
            break;
        }

        // determine node/system master status
        FAPI_DBG("proc_build_smp_insert_chip: Determining node/system master status");
        rc = proc_build_smp_set_master_config(i_first_chip_in_sys,
                                              first_chip_in_node,
                                              i_op,
                                              io_smp_chip,
                                              io_smp,
                                              master_chip_sys_curr);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_insert_chip: Error from proc_fab_smp_set_master_config");
            break;
        }

        // insert chip into SMP
        io_smp.nodes[node_id].chips[chip_id] = io_smp_chip;
        // save pointer to current system master chip?
        if (master_chip_sys_curr)
        {
            io_smp.master_chip_curr_set = true;
            io_smp.master_chip_curr_node_id = node_id;
            io_smp.master_chip_curr_chip_id = chip_id;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_insert_chip: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: wrapper function to process all HWP input structures and build
//           SMP data structure
// parameters: i_proc_chips => vector of HWP input structures (one entry per
//                             chip in SMP)
//             i_op         => procedure operation phase/mode
//             io_smp       => fully specified structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if all processing is successful,
//          RC_PROC_FAB_SMP_PCIE_NOT_F_LINK_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_process_chips(
    std::vector<proc_build_smp_proc_chip>& i_proc_chips,
    const proc_build_smp_operation i_op,
    proc_build_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;

    // mark function entry
    FAPI_DBG("proc_build_smp_process_chips: Start");

    // loop over all chips passed from platform to HWP
    std::vector<proc_build_smp_proc_chip>::iterator i;
    for (i = i_proc_chips.begin(); i != i_proc_chips.end(); i++)
    {
        // process platform provided data in chip argument,
        // query chip specific attributes
        proc_build_smp_chip smp_chip;
        rc = proc_build_smp_process_chip(&(*i),
                                         smp_chip);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chips: Error from proc_build_smp_process_chip");
            break;
        }

        // insert chip into SMP data structure given node & chip ID
        rc = proc_build_smp_insert_chip(smp_chip,
                                        (i == i_proc_chips.begin()),
                                        i_op,
                                        io_smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chips: Error from proc_build_smp_insert_chip");
            break;
        }
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_process_chips: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: proc_setup_bars HWP entry point
//           NOTE: see comments above function prototype in header
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp(
    std::vector<proc_build_smp_proc_chip> & i_proc_chips,
    const proc_build_smp_operation i_op)
{
    fapi::ReturnCode rc;
    proc_build_smp_system smp;
    smp.master_chip_curr_set = false;

    // mark function entry
    FAPI_DBG("proc_build_smp: Start");

    do
    {
        // query system specific attributes
        rc = proc_build_smp_process_system(smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp: Error from proc_build_smp_process_system");
            break;
        }

        // process HWP input vector of chip structures
        rc = proc_build_smp_process_chips(i_proc_chips, i_op, smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp: Error from proc_build_smp_process_chips");
            break;
        }

        // initialize fabric configuration
        if (i_op == SMP_ACTIVATE_PHASE1)
        {
            // program nest epsilon attributes/registers
            rc = proc_build_smp_set_epsilons(smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp: Error from proc_build_smp_set_epsilons");
                break;
            }

            // set fabric configuration registers (non-hotplug)
            rc = proc_build_smp_set_fbc_nohp(smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp: Error from proc_build_smp_set_fbc_nohp");
                break;
            }

            // set fabric configuration registers (hotplug, switch CD set)
            rc = proc_build_smp_set_fbc_cd(smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp: Error from proc_build_smp_set_fbc_cd");
                break;
            }
        }

        // activate SMP
        // set fabric configuration registers (hotplug, switch AB set)
        rc = proc_build_smp_set_fbc_ab(smp, i_op);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp: Error from proc_build_smp_set_fbc_ab");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp: End");
    return rc;
}


} // extern "C"
