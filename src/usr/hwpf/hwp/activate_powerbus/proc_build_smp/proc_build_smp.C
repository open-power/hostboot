/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp.C $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
// $Id: proc_build_smp.C,v 1.16 2014/03/27 03:35:53 jmcgill Exp $
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
#include <proc_build_smp.H>
#include <proc_build_smp_epsilon.H>
#include <proc_build_smp_fbc_nohp.H>
#include <proc_build_smp_fbc_ab.H>
#include <proc_build_smp_fbc_cd.H>
#include <proc_build_smp_adu.H>


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
//          RC_PROC_BUILD_SMP_CORE_FREQ_RANGE_ERR if invalid relationship exists
//              between ceiling/nominal/floor core frequency attributes,
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
        io_smp.avp_mode = false;

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
        rc = FAPI_ATTR_GET(ATTR_FREQ_CORE_FLOOR,
                           NULL,
                           io_smp.freq_core_floor);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_FLOOR)");
            break;
        }

        // get core nominal frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying core nominal frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_CORE_NOMINAL,
                           NULL,
                           io_smp.freq_core_nom);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_NOMINAL)");
            break;
        }

        // get core ceiling frequency attribute
        FAPI_DBG("proc_build_smp_process_system: Querying core ceiling frequency attribute");
        rc = FAPI_ATTR_GET(ATTR_FREQ_CORE_MAX,
                           NULL,
                           io_smp.freq_core_ceiling);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_system: Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_MAX)");
            break;
        }

        if (!((io_smp.freq_core_ceiling >= io_smp.freq_core_nom) &&
              (io_smp.freq_core_nom     >= io_smp.freq_core_floor)))
        {
            const uint32_t& FREQ_CORE_CEILING = io_smp.freq_core_ceiling;
            const uint32_t& FREQ_CORE_NOM = io_smp.freq_core_nom;
            const uint32_t& FREQ_CORE_FLOOR = io_smp.freq_core_floor;
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_BUILD_SMP_CORE_FREQ_RANGE_ERR);
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
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_FABRIC_PUMP_MODE = NODAL_IS_CHIP_GROUP_IS_GROUP");
                break;
            case 2:
                io_smp.pump_mode = PROC_FAB_SMP_PUMP_MODE2;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_FABRIC_PUMP_MODE = NODAL_AND_GROUP_IS_GROUP");
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
            case 3:
                io_smp.eps_cfg.table_type = PROC_FAB_SMP_EPSILON_TABLE_TYPE_1S;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_EPS_TABLE_TYPE = 1S");
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
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_FABRIC_ASYNC_SAFE_MODE = false");
                break;
            case 1:
                io_smp.async_safe_mode = true;
                FAPI_DBG("proc_build_smp_process_system: ATTR_PROC_FABRIC_ASYNC_SAFE_MODE = true");
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
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_8_8;
        }
        // breakpoint ratio: core floor 4.2, pb 2.4 (cache floor :: pb = 7/8)
        else if ((4 * io_smp.freq_core_floor) >= (7 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_7_8;
        }
        // breakpoint ratio: core floor 3.6, pb 2.4 (cache floor :: pb = 6/8)
        else if ((2 * io_smp.freq_core_floor) >= (3 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_6_8;
        }
        // breakpoint ratio: core floor 3.0, pb 2.4 (cache floor :: pb = 5/8)
        else if ((4 * io_smp.freq_core_floor) >= (5 * io_smp.freq_pb))
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_5_8;
        }
        // breakpoint ratio: core floor 2.4, pb 2.4 (cache floor :: pb = 4/8)
        else if (io_smp.freq_core_floor >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_4_8;
        }
        // breakpoint ratio: core floor 1.2, pb 2.4 (cache floor :: pb = 2/8)
        else if ((2 * io_smp.freq_core_floor) >= io_smp.freq_pb)
        {
            io_smp.core_floor_ratio = PROC_BUILD_SMP_CORE_RATIO_2_8;
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

        // determine table index based on pb/core ceiling frequency ratio
        // breakpoint ratio: core ceiling 4.8, pb 2.4 (cache ceiling :: pb = 8/8)
        FAPI_DBG("proc_build_smp_process_system: Calculating core ceiling to nest frequency ratio");
        if ((io_smp.freq_core_ceiling) >= (2 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_8_8;
        }
        // breakpoint ratio: core ceiling 4.2, pb 2.4 (cache ceiling :: pb = 7/8)
        else if ((4 * io_smp.freq_core_ceiling) >= (7 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_7_8;
        }
        // breakpoint ratio: core ceiling 3.6, pb 2.4 (cache ceiling :: pb = 6/8)
        else if ((2 * io_smp.freq_core_ceiling) >= (3 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_6_8;
        }
        // breakpoint ratio: core ceiling 3.0, pb 2.4 (cache ceiling :: pb = 5/8)
        else if ((4 * io_smp.freq_core_ceiling) >= (5 * io_smp.freq_pb))
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_5_8;
        }
        // breakpoint ratio: core ceiling 2.4, pb 2.4 (cache ceiling :: pb = 4/8)
        else if (io_smp.freq_core_ceiling >= io_smp.freq_pb)
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_4_8;
        }
        // breakpoint ratio: core ceiling 1.2, pb 2.4 (cache ceiling :: pb = 2/8)
        else if ((2 * io_smp.freq_core_ceiling) >= io_smp.freq_pb)
        {
            io_smp.core_ceiling_ratio = PROC_BUILD_SMP_CORE_RATIO_2_8;
        }
        // under-range, raise error
        else
        {
            FAPI_ERR("proc_build_smp_process_system: Unsupported core ceiling/PB frequency ratio (=%d/%d)",
                     io_smp.freq_core_ceiling, io_smp.freq_pb);
            const uint32_t& FREQ_PB = io_smp.freq_pb;
            const uint32_t& FREQ_CORE_CEILING = io_smp.freq_core_ceiling;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_CORE_CEILING_FREQ_RATIO_ERR);
            break;
        }

        // determine full CPU delay settings
        FAPI_DBG("proc_build_smp_process_system: Calculating full CPU delay settings:");
        if ((2400 * io_smp.freq_core_ceiling) >= (4800 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4800_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (4431 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4431_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (4114 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4114_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3840 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3840_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3338 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3338_2400;
        }
        else if ((2400 * io_smp.freq_core_ceiling) >= (3032 * io_smp.freq_pb))
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3032_2400;
        }
        else
        {
            io_smp.full_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_2743_2400;
        }

        // determine nominal CPU delay settings
        FAPI_DBG("proc_build_smp_process_system: Calculating nominal CPU delay settings:");
        if ((2400 * io_smp.freq_core_nom) >= (4800 * io_smp.freq_pb))
        {
            // shift to avoid equivalent index
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4431_2400;
        }
        else if ((2400 * io_smp.freq_core_nom) >= (4431 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4431_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4114_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (4114 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_4114_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3840_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3840 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3840_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3338_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3338 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3338_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3032_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (3032 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_3032_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_2743_2400;
            }
        }
        else if ((2400 * io_smp.freq_core_nom) >= (2743 * io_smp.freq_pb))
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_2743_2400;
            // shift to avoid equivalent index
            if (io_smp.nom_cpu_delay == io_smp.full_cpu_delay)
            {
                io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_2504_2400;
            }
        }
        else
        {
            io_smp.nom_cpu_delay = PROC_BUILD_SMP_CPU_DELAY_2504_2400;
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
            FAPI_ERR("proc_build_smp_process_chip: Error querying ATTR_PROC_NX_ENABLE");
            break;
        }

        // query X partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_X_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           x_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error querying ATTR_PROC_X_ENABLE");
            break;
        }

        // query A partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_A_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           a_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error querying ATTR_PROC_A_ENABLE");
            break;
        }

        // query PCIE partial good attribute
        rc = FAPI_ATTR_GET(ATTR_PROC_PCIE_ENABLE,
                           &(io_smp_chip.chip->this_chip),
                           pcie_enabled);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_process_chip: Error querying ATTR_PROC_PCIE_ENABLE");
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
// parameters: i_first_chip_in_node   => first chip processed in node?
//             i_op                   => procedure operation phase/mode
//             io_smp_chip            => structure encapsulating single chip in
//                                       SMP topology
//             io_smp                 => structure encapsulating SMP
// returns: FAPI_RC_SUCCESS if insertion is successful and merged node ranges
//              are valid,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              error is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION_ERR if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_master_config(
    const bool i_first_chip_in_node,
    const proc_build_smp_operation i_op,
    proc_build_smp_chip& io_smp_chip,
    proc_build_smp_system& io_smp)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);
    bool error = false;

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

         // check/set expectation for CURR/NEXT states based on HW state
        // as well as input parameters
        // HBI
        if (i_op == SMP_ACTIVATE_PHASE1)
        {
            // each chip should match the flush state of the fabric logic
            if (!io_smp_chip.master_chip_sys_curr ||
                io_smp_chip.master_chip_node_curr)
            {
                error = true;
                break;
            }

            // set next state
            io_smp_chip.master_chip_node_next = i_first_chip_in_node;
        }
        // FSP
        else if (i_op == SMP_ACTIVATE_PHASE2)
        {
            // set next state
            io_smp_chip.master_chip_node_next = io_smp_chip.master_chip_node_curr;
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

        // mark system master for launching fabric reconfiguration operations
        // also track which slave fabrics will be quiesced
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
                error = true;
                break;
            }
        }
        else
        {
            // this chip will not be the new master, but is one now
            // use it to quisece all chips in its fabric
            if (io_smp_chip.master_chip_sys_curr)
            {
                io_smp_chip.issue_quiesce_next = true;
            }
            else
            {
                io_smp_chip.issue_quiesce_next = false;
            }
        }

    } while(0);

    // error for supported operation
    if (rc.ok() && error)
    {
       FAPI_ERR("proc_build_smp_set_master_config: Node/system master designation error");
       const fapi::Target& TARGET = io_smp_chip.chip->this_chip;
       const uint8_t& OP = i_op;
       const bool& MASTER_CHIP_SYS_CURR = io_smp_chip.master_chip_sys_curr;
       const bool& MASTER_CHIP_NODE_CURR = io_smp_chip.master_chip_node_curr;
       const bool& MASTER_CHIP_SYS_NEXT = io_smp_chip.chip->master_chip_sys_next;
       const bool& MASTER_CHIP_NODE_NEXT = io_smp_chip.master_chip_node_next;
       const bool& SYS_RECONFIG_MASTER_SET = io_smp.master_chip_curr_set;
       FAPI_SET_HWP_ERROR(
           rc,
           RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR);
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_set_master_config: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: insert chip structure into proper position within SMP model based
//           on its fabric node/chip ID
// parameters: io_smp_chip          => structure encapsulating single chip in
//                                     SMP topology
//             i_op                 => procedure operation phase/mode
//             io_smp               => structure encapsulating full SMP
// returns: FAPI_RC_SUCCESS if insertion is successful and merged node ranges
//              are valid,
//          RC_PROC_BUILD_SMP_NODE_ADD_INTERNAL_ERR if node map insert fails,
//          RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR if chips with duplicate
//              fabric node/chip IDs are detected,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION_ERR if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_insert_chip(
    proc_build_smp_chip& io_smp_chip,
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
                const fapi::Target & TARGET = io_smp_chip.chip->this_chip;
                const proc_fab_smp_node_id & NODE_ID = node_id;
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
            const fapi::Target & TARGET1 = io_smp_chip.chip->this_chip;
            const fapi::Target & TARGET2 = p_iter->second.chip->this_chip;
            const proc_fab_smp_node_id & NODE_ID = node_id;
            const proc_fab_smp_chip_id & CHIP_ID = chip_id;
            FAPI_SET_HWP_ERROR(rc,
                RC_PROC_BUILD_SMP_DUPLICATE_FABRIC_ID_ERR);
            break;
        }

        // determine node/system master status
        FAPI_DBG("proc_build_smp_insert_chip: Determining node/system master status");
        rc = proc_build_smp_set_master_config(first_chip_in_node,
                                              i_op,
                                              io_smp_chip,
                                              io_smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_insert_chip: Error from proc_build_smp_set_master_config");
            break;
        }

        // insert chip into SMP
        io_smp.nodes[node_id].chips[chip_id] = io_smp_chip;

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
//          RC_PROC_BUILD_SMP_NO_MASTER_SPECIFIED_ERR if input parameters
//              do not specify a new fabric system master,
//          RC_PROC_BUILD_SMP_MASTER_DESIGNATION_ERR if node/system master
//              error is detected based on chip state and input paramters,
//          RC_PROC_BUILD_SMP_INVALID_OPERATION_ERR if an unsupported operation
//              is specified
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          RC_PROC_BUILD_SMP_AX_PARTIAL_GOOD_ERR if partial good attribute
//              state does not allow for action on target,
//          RC_PROC_BUILD_SMP_PCIE_PARTIAL_GOOD_ERR if partial good attribute
//              state does not allow for action on target,
//          RC_PROC_BUILD_SMP_LINK_TARGET_TYPE_ERR if link target type is
//              unsupported,
//          RC_PROC_BUILD_SMP_INVALID_TOPOLOGY if specified fabric topology
//              is illegal,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_process_chips(
    std::vector<proc_build_smp_proc_chip>& i_proc_chips,
    const proc_build_smp_operation i_op,
    proc_build_smp_system& io_smp)
{
    // return code
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0;

    // mark function entry
    FAPI_DBG("proc_build_smp_process_chips: Start");

    // loop over all chips passed from platform to HWP
    std::vector<proc_build_smp_proc_chip>::iterator i;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;
    io_smp.master_chip_curr_set = false;

    do
    {

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
                                            i_op,
                                            io_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_process_chips: Error from proc_build_smp_insert_chip");
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // ensure that new master was designated
        if (!io_smp.master_chip_curr_set)
        {
            FAPI_ERR("proc_build_smp_process_chips: No system master specified!");
            const uint8_t& OP = i_op;
            FAPI_SET_HWP_ERROR(
                rc,
                RC_PROC_BUILD_SMP_NO_MASTER_SPECIFIED_ERR);
            break;
        }

        // based on master designation, and operation phase,
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

        // check that fabric topology is logically valid
        // 1) in a given node, all chips are connected to every other
        //    chip in the node, by an X bus
        // 2) each chip is connected to its partner chip (with same chip id)
        //    in every other node, by an A bus

        // build set of all valid node ids in system
        FAPI_DBG("proc_build_smp_process_chips: Checking fabric topology");
        ecmdDataBufferBase node_ids_in_system(PROC_FAB_SMP_NUM_NODE_IDS); 
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            FAPI_DBG("proc_build_smp_process_chips: Adding n%d", n_iter->first);
            rc_ecmd |= node_ids_in_system.setBit(n_iter->first);
        }
        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_process_chips: Error 0x%x forming system node ID set data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // iterate over all nodes
        for (n_iter = io_smp.nodes.begin();
             n_iter != io_smp.nodes.end();
             n_iter++)
        {
            // build set of all valid chip ids in node
            ecmdDataBufferBase chip_ids_in_node(PROC_FAB_SMP_NUM_CHIP_IDS);
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                FAPI_DBG("proc_build_smp_process_chips: Adding n%d:p%d",
                         n_iter->first, p_iter->first);
                rc_ecmd |= chip_ids_in_node.setBit(p_iter->first);
            }
            if (rc_ecmd)
            {
                FAPI_ERR("proc_build_smp_process_chips: Error 0x%x forming node %d chip ID set data buffer",
                         rc_ecmd, n_iter->first);
                rc.setEcmdError(rc_ecmd);
                break;
            }

            // iterate over all chips in current node
            for (p_iter = n_iter->second.chips.begin();
                 p_iter != n_iter->second.chips.end();
                 p_iter++)
            {
                FAPI_DBG("proc_build_smp_process_chips: Processing links for n%d:p%d",
                         n_iter->first, p_iter->first);
                std::vector<fapi::Target *> x_link_targets;
                x_link_targets.push_back(&(p_iter->second.chip->x0_chip));
                x_link_targets.push_back(&(p_iter->second.chip->x1_chip));
                x_link_targets.push_back(&(p_iter->second.chip->x2_chip));
                x_link_targets.push_back(&(p_iter->second.chip->x3_chip));

                std::vector<fapi::Target *> a_link_targets;
                a_link_targets.push_back(&(p_iter->second.chip->a0_chip));
                a_link_targets.push_back(&(p_iter->second.chip->a1_chip));
                a_link_targets.push_back(&(p_iter->second.chip->a2_chip));

                // process X-connected chips
                ecmdDataBufferBase x_connected_chip_ids(PROC_FAB_SMP_NUM_CHIP_IDS);
                for (std::vector<fapi::Target*>::iterator l = x_link_targets.begin();
                     l != x_link_targets.end();
                     l++)
                {
                    bool link_is_enabled;
                    proc_fab_smp_node_id dest_node_id;
                    proc_fab_smp_chip_id dest_chip_id;
                    rc = proc_build_smp_query_link_state(p_iter->second,
                                                         (l - x_link_targets.begin()),
                                                         *l,
                                                         link_is_enabled,
                                                         dest_node_id,
                                                         dest_chip_id);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_process_chips: Error from proc_build_smp_query_link_state (X)");
                        break;
                    }

                    if (link_is_enabled)
                    {
                        rc_ecmd |= x_connected_chip_ids.writeBit(
                            (uint8_t) dest_chip_id, 
                            ((((uint8_t) dest_node_id) == n_iter->first)?(1):(0)));
                        if (rc_ecmd)
                        {
                            FAPI_ERR("proc_build_smp_process_chips: Error 0x%x writing n%d:p%d X connected chip ID set data buffer",
                                     rc_ecmd, n_iter->first, p_iter->first);
                            rc.setEcmdError(rc_ecmd);
                            break;
                        }

                        FAPI_DBG("proc_build_smp_process_chips: n%d:p%d X%d -> n%d:p%d",
                                 n_iter->first, p_iter->first, (l - x_link_targets.begin()),
                                 dest_node_id, dest_chip_id);
                    }
                }
                if (!rc.ok())
                {
                    break;
                }

                // process A-connected chips
                ecmdDataBufferBase a_connected_node_ids(PROC_FAB_SMP_NUM_NODE_IDS);
                for (std::vector<fapi::Target*>::iterator l = a_link_targets.begin();
                     l != a_link_targets.end();
                     l++)
                {
                    bool link_is_enabled;
                    proc_fab_smp_node_id dest_node_id;
                    proc_fab_smp_chip_id dest_chip_id;
                    rc = proc_build_smp_query_link_state(p_iter->second,
                                                         (l - a_link_targets.begin()),
                                                         *l,
                                                         link_is_enabled,
                                                         dest_node_id,
                                                         dest_chip_id);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_process_chips: Error from proc_build_smp_query_link_state (A)");
                        break;
                    }

                    if (link_is_enabled)
                    {
                        rc_ecmd |= a_connected_node_ids.writeBit(
                            (uint8_t) dest_node_id,
                            ((((uint8_t) dest_chip_id) == p_iter->first)?(1):(0)));
                        if (rc_ecmd)
                        {
                            FAPI_ERR("proc_build_smp_process_chips: Error 0x%x writing n%d:p%d A connected node ID set data buffer",
                                     rc_ecmd, n_iter->first, p_iter->first);
                            rc.setEcmdError(rc_ecmd);
                            break;
                        }

                        FAPI_DBG("proc_build_smp_process_chips: n%d:p%d A%d -> n%d:p%d",
                                 n_iter->first, p_iter->first, (l - a_link_targets.begin()),
                                 dest_node_id, dest_chip_id);
                    }
                }
                if (!rc.ok())
                {
                    break;
                }

                // add IDs associated with current chip, to make direct set comparison easy
                FAPI_DBG("proc_build_smp_process_chips: Checking connectivity for n%d:p%d",
                         n_iter->first, p_iter->first);
                rc_ecmd |= a_connected_node_ids.setBit(n_iter->first);
                rc_ecmd |= x_connected_chip_ids.setBit(p_iter->first);
                if (rc_ecmd)
                {
                    FAPI_ERR("proc_build_smp_process_chips: Error 0x%x writing n%d:p%d connected ID set data buffer (self)",
                             rc_ecmd, n_iter->first, p_iter->first);
                    rc.setEcmdError(rc_ecmd);
                    break;
                }

                // compare ID sets, exit if they don't match
                bool internode_set_match = (node_ids_in_system == a_connected_node_ids);
                bool intranode_set_match = (chip_ids_in_node == x_connected_chip_ids);
                if (!internode_set_match ||
                    !intranode_set_match)
                {
                    FAPI_ERR("proc_build_smp_process_chips: Invalid fabric topology detected!");
                    if (!intranode_set_match)
                    {
                        FAPI_ERR("proc_build_smp_process_chips: Target %s is not fully connected (X) to all other chips in its node",
                                 p_iter->second.chip->this_chip.toEcmdString());
                    }
                    if (!internode_set_match)
                    {
                        FAPI_ERR("proc_build_smp_process_chips: Target %s is not fully connected (A) to all other nodes",
                                 p_iter->second.chip->this_chip.toEcmdString());
                    }

                    const fapi::Target& TARGET = p_iter->second.chip->this_chip;
                    const bool& A_CONNECTIONS_OK = internode_set_match;
                    const ecmdDataBufferBase& A_CONNECTED_NODE_IDS = a_connected_node_ids;
                    const bool& X_CONNECTIONS_OK = intranode_set_match;
                    const ecmdDataBufferBase& X_CONNECTED_CHIP_IDS = x_connected_chip_ids;
                    FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_INVALID_TOPOLOGY);
                    break;
                }
            }
            if (!rc.ok())
            {
                break;
            }
        }
        if (!rc.ok())
        {
            break;
        }        

    } while(0);

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
