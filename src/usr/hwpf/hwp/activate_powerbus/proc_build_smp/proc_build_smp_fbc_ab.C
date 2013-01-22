/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_ab.C $ */
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
// $Id: proc_build_smp_fbc_ab.C,v 1.5 2013/01/21 03:11:32 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_ab.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_ab.C
// *! DESCRIPTION : Fabric configuration (hotplug, AB) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp_fbc_ab.H"
#include "proc_build_smp_epsilon.H"
#include "proc_build_smp_adu.H"

extern "C" {


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: read PB A Link Framer Configuration register and determine
//           OW packing setup
// parameters: i_smp_chip        => structure encapsulating SMP chip
//             o_owpack          => OW packing enabled?
//             o_owpack_priority => OW pack priority enabled?
// returns: FAPI_RC_SUCCESS if SCOM is successful & output pack values are
//              valid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_get_a_owpack_config(
    const proc_build_smp_chip& i_smp_chip,
    bool & o_owpack,
    bool & o_owpack_priority)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_get_a_owpack_config: Start");

    do
    {
        // read PB A Link Framer Configuration register
        rc = fapiGetScom(i_smp_chip.chip->this_chip,
                         PB_A_FMR_CFG_0x08010813,
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_get_a_owpack_config: fapiGetScom error (PB_A_FMR_CFG_0x08010813)");
            break;
        }

        // set outputs
        o_owpack = data.isBitSet(PB_A_FMR_CFG_OW_PACK_BIT);
        o_owpack_priority = data.isBitSet(PB_A_FMR_CFG_OW_PACK_PRIORITY_BIT);

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_get_a_owpack_config: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: read PB F Link Framer Configuration register and determine
//           OW packing setup
// parameters: i_smp_chip        => structure encapsulating SMP chip
//             o_owpack          => OW packing enabled?
//             o_owpack_priority => OW pack priority enabled?
// returns: FAPI_RC_SUCCESS if SCOM is successful & output pack values are
//              valid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_get_f_owpack_config(
    const proc_build_smp_chip& i_smp_chip,
    bool & o_owpack,
    bool & o_owpack_priority)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_get_f_owpack_config: Start");

    do
    {
        // read PB F Link Framer Configuration register
        rc = fapiGetScom(i_smp_chip.chip->this_chip,
                         PB_F_FMR_CFG_0x09010813,
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_get_f_owpack_config: fapiGetScom error (PB_F_FMR_CFG_0x09010813)");
            break;
        }

        // set outputs
        o_owpack = data.isBitSet(PB_F_FMR_CFG_OW_PACK_BIT);
        o_owpack_priority = data.isBitSet(PB_F_FMR_CFG_OW_PACK_PRIORITY_BIT);

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_get_f_owpack_config: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: read PB Link Mode register and extract per-link training delays
// parameters: i_smp_chip         => structure encapsulating SMP chip
//             i_num_links        => number of links to process
//             i_scom_addr        => address for SCOM register containing link
//                                   delay values
//             i_link_delay_start => per-link delay field start bit offsets
//             i_link_delay_end   => per-link delay field end bit offsets
//             o_link_delays      => array of link round trip delay values
// returns: FAPI_RC_SUCCESS if SCOM is successful & output link delays are
//              valid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_get_link_delays(
    const proc_build_smp_chip& i_smp_chip,
    const uint8_t i_num_links,
    const uint32_t i_scom_addr,
    const uint32_t i_link_delay_start[],
    const uint32_t i_link_delay_end[],
    uint16_t o_link_delays[])
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_get_link_delays: Start");

    do
    {
        // read PB Link Mode register
        rc = fapiGetScom(i_smp_chip.chip->this_chip,
                         i_scom_addr,
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_get_link_delays: fapiGetScom error (%08X)",
                     i_scom_addr);
            break;
        }

        // extract & return link training delays
        for (uint8_t l = 0; l < i_num_links; l++)
        {
            rc_ecmd |= data.extractToRight(
                &(o_link_delays[l]),
                i_link_delay_start[l],
                (i_link_delay_end[l]-
                 i_link_delay_start[l]+1));

            if (rc_ecmd)
            {
                FAPI_ERR("proc_build_smp_get_link_delays: Error 0x%x accessing data buffer",
                         rc_ecmd);
                rc.setEcmdError(rc_ecmd);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_get_link_delays: Start");
    return rc;
}


//------------------------------------------------------------------------------
// function: determine link address/data & aggregate mode setup
// parameters: i_smp_chip         => structure encapsulating SMP chip
//             i_num_links        => number of links to process
//             i_num_ids          => maximum number of ID values
//             i_scom_addr        => address for SCOM register containing link
//                                   delay values
//             i_link_delay_start => per-link delay field start bit offsets
//             i_link_delay_end   => per-link delay field end bit offsets
//             i_link_en          => per-link enable values
//             i_link_id          => per-link ID values
//             o_link_addr_dis    => per-link address disable values
//                                   (true=address only, false=address/data)
//             o_link_aggregate   => enable aggregate link mode?
// returns: FAPI_RC_SUCCESS if output values are valid,
//          RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR if configuration
//              specifies invalid aggregate link setup,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_link_setup(
    const proc_build_smp_chip& i_smp_chip,
    const uint8_t i_num_links,
    const uint8_t i_num_ids,
    const uint32_t i_scom_addr,
    const uint32_t i_link_delay_start[],
    const uint32_t i_link_delay_end[],
    const bool i_link_en[],
    const uint8_t i_link_id[],
    bool o_link_addr_dis[],
    bool &o_link_aggregate)
{
    fapi::ReturnCode rc;
    // mark precisely which links target each ID
    bool id_active[i_num_ids][i_num_links];
    // mark number of links targeting each ID
    uint8_t id_active_count[i_num_ids];
    // link round trip delay values
    uint16_t link_delays[i_num_links];

    // mark function entry
    FAPI_DBG("proc_build_smp_calc_link_setup: Start");

    do
    {
        // init local arrays
        for (uint8_t id = 0; id < i_num_ids; id++)
        {
            id_active_count[id] = 0;
            for (uint8_t l = 0; l < i_num_links; l++)
            {
                id_active[id][l] = false;
            }
        }

        // process all links
        for (uint8_t l = 0; l < i_num_links; l++)
        {
            // mark link ID
            if (i_link_en[l])
            {
                id_active_count[i_link_id[l]]++;
                id_active[i_link_id[l]][l] = true;
            }
            // set default value for link address disable (enable coherency)
            o_link_addr_dis[l] = false;
        }

        // calculate aggregate setting, check for errors
        o_link_aggregate = false;
        for (uint8_t id = 0; id < i_num_ids; id++)
        {
            // more than one link pointed at current destination ID
            if (id_active_count[id] > 1)
            {
                // design only supports one set of aggregate links per chip
                if (o_link_aggregate)
                {
                    FAPI_ERR("proc_build_smp_calc_link_setup: Invalid aggregate link configuration");
                    FAPI_SET_HWP_ERROR(
                        rc,
                        RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR);
                    break;
                }
                o_link_aggregate = true;

                // flip default value for link address disable
                // (disable coherency)
                for (uint8_t l = 0; l < i_num_links; l++)
                {
                    if (id_active[id][l])
                    {
                        o_link_addr_dis[l] = true;
                    }
                }

                // select link with the lowest round trip latency value
                // to carry coherency
                rc = proc_build_smp_get_link_delays(i_smp_chip,
                                                    i_num_links,
                                                    i_scom_addr,
                                                    i_link_delay_start,
                                                    i_link_delay_end,
                                                    link_delays);
                if (rc)
                {
                    FAPI_ERR("proc_build_smp_calc_link_setup: Error from proc_build_smp_get_link_delays");
                    break;
                }

                // search link delays to find smallest value
                uint8_t coherent_link_id = 0;
                uint16_t min_delay = 0xFFFF;
                for (uint8_t l = 0; l < i_num_links; l++)
                {
                    if (i_link_en[l] && (link_delays[l] <= min_delay))
                    {
                        coherent_link_id = l;
                        min_delay = link_delays[l];
                    }
                }

                // assign this link to carry coherency
                o_link_addr_dis[coherent_link_id] = false;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_link_setup: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to calculate X link reflected command rate
// parameters: i_freq_x      => X-bus frequency
//             i_freq_pb     => PB frequency
//             i_x_is_8B     => boolean representing X bus width
//                              (true=8B, false=4B)
//             i_x_aggregate => X aggregate mode enabled?
//             o_x_cmd_rate  => output X link command rate
// returns: FAPI_RC_SUCCESS if output command rate is in range,
//          else RC_PROC_BUILD_SMP_X_CMD_RATE_ERR
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_x_cmd_rate(
    const uint32_t i_freq_x,
    const uint32_t i_freq_pb,
    const bool i_x_is_8B,
    const bool i_x_aggregate,
    uint8_t & o_x_cmd_rate)
{
    fapi::ReturnCode rc;
    uint32_t n = i_freq_pb;
    uint32_t d = i_freq_x / 2;
    uint32_t cmd_rate;

    // mark function entry
    FAPI_DBG("proc_build_smp_calc_x_cmd_rate: Start");

    do
    {
        if (i_x_is_8B)
        {
            d *= 2;
        }

        if (i_x_aggregate)
        {
            n *= 5;
        }
        else
        {
            n *= 7;
        }

        cmd_rate = proc_build_smp_round_ceiling(n, d);
        if ((cmd_rate < PB_HPX_MODE_X_CMD_RATE_MIN_VALUE) ||
            (cmd_rate > PB_HPX_MODE_X_CMD_RATE_MAX_VALUE))
        {
            FAPI_ERR("proc_build_smp_calc_x_cmd_rate: X link command rate is out of range");
            const uint32_t & CMD_RATE = cmd_rate;
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_BUILD_SMP_X_CMD_RATE_ERR);
            break;
        }
    } while(0);

    o_x_cmd_rate = (uint8_t) cmd_rate;

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_x_cmd_rate: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to calculate A link reflected command rate
// parameters: i_freq_a             => A-bus frequency
//             i_freq_pb            => PB frequency
//             i_a_ow_pack          => A link OW packing enabled?
//             i_a_ow_pack_priority => A link OW packing priority set?
//             i_a_aggregate        => A aggregate mode enabled?
//             o_a_cmd_rate         => output A link command rate
// returns: FAPI_RC_SUCCESS if output command rate is in range,
//          else RC_PROC_BUILD_SMP_A_CMD_RATE_ERR
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_a_cmd_rate(
    const uint32_t i_freq_a,
    const uint32_t i_freq_pb,
    const bool i_a_ow_pack,
    const bool i_a_ow_pack_priority,
    const bool i_a_aggregate,
    uint8_t & o_a_cmd_rate)
{
    fapi::ReturnCode rc;
    uint32_t n = i_freq_pb;
    uint32_t d = i_freq_a / 4;
    uint32_t n_ow_pack = 0;
    uint32_t cmd_rate;

    // mark function entry
    FAPI_DBG("proc_build_smp_calc_a_cmd_rate: Start");

    do
    {
        if (i_a_ow_pack)
        {
            n_ow_pack = (i_a_ow_pack_priority?1:0) + 3;
        }
        if (i_a_aggregate)
        {
            n_ow_pack += 3;
        }
        else
        {
            n_ow_pack += 4;
        }

        n *= (2 * n_ow_pack);

        cmd_rate = proc_build_smp_round_ceiling(n, d);
        if ((cmd_rate < PB_HP_MODE_A_CMD_RATE_MIN_VALUE) ||
            (cmd_rate > PB_HP_MODE_A_CMD_RATE_MAX_VALUE))
        {
            FAPI_ERR("proc_build_smp_calc_a_cmd_rate: A link command rate is out of range");
            const uint32_t & CMD_RATE = cmd_rate;
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_BUILD_SMP_A_CMD_RATE_ERR);
            break;
        }
    } while(0);

    o_a_cmd_rate = (uint8_t) cmd_rate;

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_a_cmd_rate: Start");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to calculate F link reflected command rate
// parameters: i_freq_f             => F-bus frequency
//             i_freq_pb            => PB frequency
//             i_f_ow_pack          => F link OW packing enabled?
//             i_f_ow_pack_priority => F link OW packing priority set?
//             i_f_aggregate        => F aggregate mode enabled?
//             o_f_cmd_rate         => output F link command rate
// returns: FAPI_RC_SUCCESS if output command rate is in range,
//          else RC_PROC_BUILD_SMP_F_CMD_RATE_ERR
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_f_cmd_rate(
    const uint32_t i_freq_f,
    const uint32_t i_freq_pb,
    const bool i_f_ow_pack,
    const bool i_f_ow_pack_priority,
    const bool i_f_aggregate,
    uint8_t & o_f_cmd_rate)
{
    fapi::ReturnCode rc;
    uint32_t n = i_freq_pb;
    uint32_t d = i_freq_f;
    uint32_t n_ow_pack = 0;
    uint32_t cmd_rate;

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_f_cmd_rate: Start");

    do
    {
        if (i_f_ow_pack)
        {
            n_ow_pack = (i_f_ow_pack_priority?1:0) + 3;
        }
        if (i_f_aggregate)
        {
            n_ow_pack += 3;
            n_ow_pack *= 30;
        }
        else
        {
            n_ow_pack += 4;
            n_ow_pack *= 29;
        }

        n *= (2 * n_ow_pack);
        d *= 25;

        cmd_rate = proc_build_smp_round_ceiling(n, d);
        if ((cmd_rate < PB_HP_MODE_F_CMD_RATE_MIN_VALUE) ||
            (cmd_rate > PB_HP_MODE_F_CMD_RATE_MAX_VALUE))
        {
            FAPI_ERR("proc_build_smp_calc_f_cmd_rate: F link command rate is out of range");
            const uint32_t & CMD_RATE = cmd_rate;
            FAPI_SET_HWP_ERROR(rc,
                               RC_PROC_BUILD_SMP_F_CMD_RATE_ERR);
            break;
        }

    } while(0);

    o_f_cmd_rate = (uint8_t) cmd_rate;

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_f_cmd_rate: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to program set of PB hotplug registers
// parameters: i_smp_chip      => structure encapsulating SMP chip
//             i_curr_not_next => choose CURR/NEXT register set (true=CURR,
//                                false=NEXT)
//             i_hp_not_hpx    => choose HP/HPX register set (true=HP,
//                                false=HPX)
//             i_data          => data buffer containing write data
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_hotplug_reg(
    const proc_build_smp_chip& i_smp_chip,
    const bool i_curr_not_next,
    const bool i_hp_not_hpx,
    ecmdDataBufferBase& i_data)
{
    fapi::ReturnCode rc;
    uint32_t scom_addr;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_hotplug_reg: Start");

    // write west/center/east register copies
    for (uint8_t r = 0; r < PROC_BUILD_SMP_NUM_SHADOWS; r++)
    {
        // set target scom address based on input parameters
        if (i_curr_not_next)
        {
            if (i_hp_not_hpx)
            {
                scom_addr = PB_HP_MODE_CURR_SHADOWS[r];
            }
            else
            {
                scom_addr = PB_HPX_MODE_CURR_SHADOWS[r];
            }
        }
        else
        {
            if (i_hp_not_hpx)
            {
                scom_addr = PB_HP_MODE_NEXT_SHADOWS[r];
            }
            else
            {
                scom_addr = PB_HPX_MODE_NEXT_SHADOWS[r];
            }
        }

        // write register
        rc = fapiPutScom(i_smp_chip.chip->this_chip,
                         scom_addr,
                         i_data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_hotplug_reg: fapiPutScom error (%08X)",
                     scom_addr);
            break;
        }
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_set_hotplug_reg: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_get_hotplug_curr_reg(
    const proc_build_smp_chip& i_smp_chip,
    const bool i_hp_not_hpx,
    ecmdDataBufferBase& o_data)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_get_hotplug_curr_reg: Start");

    // check consistency of west/center/east register copies
    for (uint8_t r = 0; r < PROC_BUILD_SMP_NUM_SHADOWS; r++)
    {
        // get current (working) register
        rc = fapiGetScom(i_smp_chip.chip->this_chip,
                         ((i_hp_not_hpx)?
                          (PB_HP_MODE_CURR_SHADOWS[r]):
                          (PB_HPX_MODE_CURR_SHADOWS[r])),
                         data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_get_hotplug_curr_reg: fapiGetScom error (%08X)",
                     ((i_hp_not_hpx)?
                      (PB_HP_MODE_CURR_SHADOWS[r]):
                      (PB_HPX_MODE_CURR_SHADOWS[r])));
            break;
        }

        // raise error if shadow copies aren't equal
        if ((r != 0) &&
            (o_data != data))
        {
            FAPI_ERR("proc_build_smp_get_hotplug_curr_reg: Shadow copies are not equivalent");
            const uint32_t& ADDRESS0 = ((i_hp_not_hpx)?
                                        (PB_HP_MODE_CURR_SHADOWS[r-1]):
                                        (PB_HPX_MODE_CURR_SHADOWS[r-1]));
            const uint32_t& ADDRESS1 = ((i_hp_not_hpx)?
                                        (PB_HP_MODE_CURR_SHADOWS[r]):
                                        (PB_HPX_MODE_CURR_SHADOWS[r]));
            const uint64_t& DATA0 = o_data.getDoubleWord(0);
            const uint64_t& DATA1 = data.getDoubleWord(0);
            FAPI_SET_HWP_ERROR(
                rc,
                RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR);
            break;
        }

        // set output (will be used to compare with next HW read)
        data.copy(o_data);
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_get_hotplug_curr_reg: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: reset (copy CURR->NEXT) PB Hotplug Mode register
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_reset_pb_hp_mode(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_reset_pb_hp_mode: Start");

    do
    {
        // read CURR state
        rc = proc_build_smp_get_hotplug_curr_reg(i_smp_chip,
                                                 true,
                                                 data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_reset_pb_hp_mode: proc_build_smp_get_hotplug_curr_reg");
            break;
        }

        // write NEXT state
        rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                            false,
                                            true,
                                            data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_reset_pb_hp_mode: proc_build_smp_set_hotplug_reg");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_reset_pb_hp_mode: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB Hotplug Mode register
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP topology
//             i_set_curr => set CURR register set?
//             i_set_next => set NEXT register set?
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR if configuration
//              specifies invalid aggregate link setup,
//          RC_PROC_BUILD_SMP_A_CMD_RATE_ERR if calculated A link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_F_CMD_RATE_ERR if calculated F link command rate
//              is invalid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_pb_hp_mode(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp,
    const bool i_set_curr,
    const bool i_set_next)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    // set of per-link destination chip targets
    fapi::Target * a_target[PROC_FAB_SMP_NUM_A_LINKS];
    // per-link enables
    bool a_en[PROC_FAB_SMP_NUM_A_LINKS];
    bool f_en[PROC_FAB_SMP_NUM_F_LINKS];
    // per-link destination IDs
    uint8_t a_id[PROC_FAB_SMP_NUM_A_LINKS];
    uint8_t f_id[PROC_FAB_SMP_NUM_F_LINKS];
    // per-link address disable values
    bool a_addr_dis[PROC_FAB_SMP_NUM_A_LINKS] = { false, false, false };
    bool f_addr_dis[PROC_FAB_SMP_NUM_F_LINKS] = { false, false };
    // aggregate link settings
    bool a_link_aggregate = false;
    bool f_link_aggregate = false;
    // link ow pack settings
    bool a_link_owpack = false;
    bool a_link_owpack_priority = false;
    bool f_link_owpack = false;
    bool f_link_owpack_priority = false;
    // link command rates
    uint8_t a_cmd_rate = 0x00;
    uint8_t f_cmd_rate = 0x00;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_pb_hp_mode: Start");

    do
    {
        // process all A links
        a_target[0] = &(i_smp_chip.chip->a0_chip);
        a_target[1] = &(i_smp_chip.chip->a1_chip);
        a_target[2] = &(i_smp_chip.chip->a2_chip);
        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_A_LINKS; l++)
        {
            // determine link enable
            a_en[l] = (a_target[l]->getType() != fapi::TARGET_TYPE_NONE);
            if (a_en[l] && !i_smp_chip.a_enabled)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Partial good attribute error (A)");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_A_PARTIAL_GOOD_ERR);
                break;
            }

            // determine link ID
            proc_fab_smp_node_id dest_node_id = FBC_NODE_ID_0;
            if (a_en[l])
            {
                rc = proc_fab_smp_get_node_id_attr(a_target[l], dest_node_id);
                if (rc)
                {
                    FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_fab_smp_get_node_id_attr");
                    break;
                }
            }
            a_id[l] = (uint8_t) dest_node_id;
        }
        if (rc)
        {
            break;
        }


        // process all F links
        f_en[0] = i_smp_chip.chip->enable_f0;
        f_id[0] = i_smp_chip.chip->f0_node_id;
        f_en[1] = i_smp_chip.chip->enable_f1;
        f_id[1] = i_smp_chip.chip->f1_node_id;

        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_F_LINKS; l++)
        {
            if (f_en[l] && !i_smp_chip.pcie_enabled)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Partial good attribute error (PCIE)");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_PCIE_PARTIAL_GOOD_ERR);
                break;
            }
        }
        if (rc)
        {
            break;
        }

        // determine address/data assignents, aggregate mode programming &
        // link command rates (A)
        if (i_smp_chip.a_enabled)
        {
            rc = proc_build_smp_calc_link_setup(i_smp_chip,
                                                PROC_FAB_SMP_NUM_A_LINKS,
                                                PROC_FAB_SMP_NUM_NODE_IDS,
                                                PB_A_MODE_0x0801080A,
                                                PB_A_MODE_LINK_DELAY_START_BIT,
                                                PB_A_MODE_LINK_DELAY_END_BIT,
                                                a_en,
                                                a_id,
                                                a_addr_dis,
                                                a_link_aggregate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_calc_link_setup (A)");
                break;
            }

            rc = proc_build_smp_get_a_owpack_config(i_smp_chip,
                                                    a_link_owpack,
                                                    a_link_owpack_priority);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_get_a_owpack_config");
                break;
            }

            rc = proc_build_smp_calc_a_cmd_rate(i_smp.freq_a,
                                                i_smp.freq_pb,
                                                a_link_owpack,
                                                a_link_owpack_priority,
                                                a_link_aggregate,
                                                a_cmd_rate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_calc_a_cmd_rate");
                break;
            }
        }

        if (i_smp_chip.pcie_enabled)
        {
            // determine address/data assignents, aggregate mode programming &
            // link command rates (F)
            rc = proc_build_smp_calc_link_setup(i_smp_chip,
                                                PROC_FAB_SMP_NUM_F_LINKS,
                                                PROC_FAB_SMP_NUM_NODE_IDS,
                                                PB_IOF_MODE_0x09011C0A,
                                                PB_IOF_MODE_LINK_DELAY_START_BIT,
                                                PB_IOF_MODE_LINK_DELAY_END_BIT,
                                                f_en,
                                                f_id,
                                                f_addr_dis,
                                                f_link_aggregate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_calc_link_setup (F)");
                break;
            }

            rc = proc_build_smp_get_f_owpack_config(i_smp_chip,
                                                    f_link_owpack,
                                                    f_link_owpack_priority);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_get_f_owpack_config");
                break;
            }

            rc = proc_build_smp_calc_f_cmd_rate(i_smp.freq_pcie,
                                                i_smp.freq_pb,
                                                f_link_owpack,
                                                f_link_owpack_priority,
                                                f_link_aggregate,
                                                f_cmd_rate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_calc_f_cmd_rate");
                break;
            }
        }

        // build data buffer with per-link values
        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_A_LINKS; l++)
        {
            // pb_cfg_link_a#_en
            rc_ecmd |= data.writeBit(PB_HP_MODE_LINK_A_EN_BIT[l],
                                     a_en[l]?1:0);

            // pb_cfg_link_na#_addr_dis
            rc_ecmd |= data.writeBit(PB_HP_MODE_LINK_A_ADDR_DIS_BIT[l],
                                     a_addr_dis[l]?1:0);
            // pb_cfg_link_a#_chipid
            rc_ecmd |= data.insertFromRight(
                a_id[l],
                PB_HP_MODE_LINK_A_ID_START_BIT[l],
                (PB_HP_MODE_LINK_A_ID_END_BIT[l]-
                 PB_HP_MODE_LINK_A_ID_START_BIT[l]+1));
        }

        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_F_LINKS; l++)
        {
            // pb_cfg_link_f#_master
            rc_ecmd |= data.writeBit(PB_HP_MODE_LINK_F_MASTER_BIT[l],
                                     f_en[l]?1:0);

            // pb_cfg_link_f#_en
            rc_ecmd |= data.writeBit(PB_HP_MODE_LINK_F_EN_BIT[l],
                                     f_en[l]?1:0);

            // pb_cfg_link_nf#_addr_dis
            rc_ecmd |= data.writeBit(PB_HP_MODE_LINK_F_ADDR_DIS_BIT[l],
                                     f_addr_dis[l]?1:0);

            // pb_cfg_link_f#_chipid
            rc_ecmd |= data.insertFromRight(
                f_id[l],
                PB_HP_MODE_LINK_F_ID_START_BIT[l],
                (PB_HP_MODE_LINK_F_ID_END_BIT[l]-
                 PB_HP_MODE_LINK_F_ID_START_BIT[l]+1));

            // pb_cfg_p#_x8tok
            rc_ecmd |= data.writeBit(
                PB_HP_MODE_PCIE_NOT_DSMP_BIT[l],
                i_smp_chip.pcie_not_f_link[l]);
        }

        // pb_cfg_master_chip
        rc_ecmd |= data.writeBit(PB_HP_MODE_MASTER_CHIP_BIT,
                                 i_smp_chip.master_chip_sys_next?1:0);

        // pb_cfg_a_aggregate
        rc_ecmd |= data.writeBit(PB_HP_MODE_A_AGGREGATE_BIT,
                                 a_link_aggregate?1:0);

        // pb_cfg_tm_master
        rc_ecmd |= data.writeBit(PB_HP_MODE_TM_MASTER_BIT,
                                 i_smp_chip.master_chip_sys_next?1:0);

        // pb_cfg_chg_rate_gp_master
        rc_ecmd |= data.writeBit(PB_HP_MODE_CHG_RATE_GP_MASTER_BIT,
                                 i_smp_chip.master_chip_node_next?1:0);

        // pb_cfg_chg_rate_sp_master
        rc_ecmd |= data.writeBit(PB_HP_MODE_CHG_RATE_SP_MASTER_BIT,
                                 i_smp_chip.master_chip_sys_next?1:0);

        // pb_cfg_pump_mode
        rc_ecmd |= data.writeBit(PB_HP_MODE_PUMP_MODE_BIT,
            (i_smp.pump_mode == PROC_FAB_SMP_PUMP_MODE2)?1:0);

        // pb_cfg_single_mc
        rc_ecmd |= data.writeBit(PB_HP_MODE_SINGLE_MC_BIT,
            (i_smp.all_mcs_interleaved == false)?1:0);

        // pb_cfg_dcache_capp_mode
        rc_ecmd |= data.writeBit(PB_HP_MODE_DCACHE_CAPP_MODE_BIT,
                                 PB_HP_MODE_DCACHE_CAPP_EN?1:0);

        // pb_cfg_a_cmd_rate
        rc_ecmd |= data.insertFromRight(
            a_cmd_rate,
            PB_HP_MODE_A_CMD_RATE_START_BIT,
            (PB_HP_MODE_A_CMD_RATE_END_BIT-
             PB_HP_MODE_A_CMD_RATE_START_BIT+1));

        // pb_cfg_a_gather_enable
        rc_ecmd |= data.writeBit(PB_HP_MODE_A_GATHER_ENABLE_BIT,
                                 PB_HP_MODE_A_GATHER_ENABLE?1:0);

        // pb_cfg_a_dly_cnt
        rc_ecmd |= data.insertFromRight(
            PB_HP_MODE_A_GATHER_DLY_CNT,
            PB_HP_MODE_A_GATHER_DLY_CNT_START_BIT,
            (PB_HP_MODE_A_GATHER_DLY_CNT_END_BIT-
             PB_HP_MODE_A_GATHER_DLY_CNT_START_BIT+1));

        // pb_cfg_gather_enable
        rc_ecmd |= data.writeBit(PB_HP_MODE_GATHER_ENABLE_BIT,
                                 PB_HP_MODE_GATHER_ENABLE?1:0);

        // pb_cfg_f_aggregate
        rc_ecmd |= data.writeBit(PB_HP_MODE_F_AGGREGATE_BIT,
                                 f_link_aggregate?1:0);

        // pb_cfg_f_cmd_rate
        rc_ecmd |= data.insertFromRight(
            f_cmd_rate,
            PB_HP_MODE_F_CMD_RATE_START_BIT,
            (PB_HP_MODE_F_CMD_RATE_END_BIT-
             PB_HP_MODE_F_CMD_RATE_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error 0x%x setting up PB Hotplug Mode register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write current (working) registers
        if (i_set_curr)
        {
            rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                                true,
                                                true,
                                                data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_set_hotplug_reg (CURR)");
                break;
            }
        }

        // write next (switch) registers
        if (i_set_next)
        {
            rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                                false,
                                                true,
                                                data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_pb_hp_mode: Error from proc_build_smp_set_hotplug_reg (NEXT)");
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_pb_hp_mode: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: reset (copy CURR->NEXT) PB Hotplug Extension Mode register
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_reset_pb_hpx_mode(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_reset_pb_hpx_mode: Start");

    do
    {
        // read CURR state
        rc = proc_build_smp_get_hotplug_curr_reg(i_smp_chip,
                                                 false,
                                                 data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_reset_pb_hpx_mode: proc_build_smp_get_hotplug_curr_reg");
            break;
        }

        // write NEXT state
        rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                            false,
                                            false,
                                            data);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_reset_pb_hpx_mode: proc_build_smp_set_hotplug_reg");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_reset_pb_hpx_mode: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB Hotplug Extension Mode register
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP topology
//             i_set_curr => set CURR register set?
//             i_set_next => set NEXT register set?
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR if configuration
//              specifies invalid aggregate link setup,
//          RC_PROC_BUILD_SMP_X_CMD_RATE_ERR if calculated X link command rate
//              is invalid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_pb_hpx_mode(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_system& i_smp,
    const bool i_set_curr,
    const bool i_set_next)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    // set of per-link destination chip targets
    fapi::Target * x_target[PROC_FAB_SMP_NUM_X_LINKS];
    // per-link enables
    bool x_en[PROC_FAB_SMP_NUM_X_LINKS];
    // per-link destination IDs
    uint8_t x_id[PROC_FAB_SMP_NUM_X_LINKS];
    // per-link address disable values
    bool x_addr_dis[PROC_FAB_SMP_NUM_X_LINKS] = { false, false, false, false };
    // aggregate link setting
    bool x_link_aggregate = false;
    // link command rate
    uint8_t x_cmd_rate = 0x00;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_pb_hpx_mode: Start");

    do
    {
        // process all links
        x_target[0] = &(i_smp_chip.chip->x0_chip);
        x_target[1] = &(i_smp_chip.chip->x1_chip);
        x_target[2] = &(i_smp_chip.chip->x2_chip);
        x_target[3] = &(i_smp_chip.chip->x3_chip);
        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_X_LINKS; l++)
        {
            // determine link enable
            x_en[l] = (x_target[l]->getType() != fapi::TARGET_TYPE_NONE);
            if (x_en[l] && !i_smp_chip.x_enabled)
            {
                FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Partial good attribute error (X)");
                FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_X_PARTIAL_GOOD_ERR);
                break;
            }

            // determine link ID
            proc_fab_smp_chip_id dest_chip_id = FBC_CHIP_ID_0;
            if (x_en[l])
            {
                rc = proc_fab_smp_get_chip_id_attr(x_target[l], dest_chip_id);
                if (rc)
                {
                    FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error from proc_fab_smp_get_chip_id_attr");
                    break;
                }
            }
            x_id[l] = (uint8_t) dest_chip_id;
        }
        if (rc)
        {
            break;
        }

        if (i_smp_chip.x_enabled)
        {
            // determine address/data assignents & aggregate mode programming
            rc = proc_build_smp_calc_link_setup(i_smp_chip,
                                                PROC_FAB_SMP_NUM_X_LINKS,
                                                PROC_FAB_SMP_NUM_CHIP_IDS,
                                                PB_X_MODE_0x04010C0A,
                                                PB_X_MODE_LINK_DELAY_START_BIT,
                                                PB_X_MODE_LINK_DELAY_END_BIT,
                                                x_en,
                                                x_id,
                                                x_addr_dis,
                                                x_link_aggregate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error from proc_build_smp_calc_link_setup (X)");
                break;
            }

            // determine link command rate
            rc = proc_build_smp_calc_x_cmd_rate(i_smp.freq_x,
                                                i_smp.freq_pb,
                                                i_smp.x_bus_8B,
                                                x_link_aggregate,
                                                x_cmd_rate);
            if (rc)
            {
                FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error from proc_build_smp_calc_x_cmd_rate");
                break;
            }
        }

        // build data buffer with per-link values
        for (uint8_t l = 0; l < PROC_FAB_SMP_NUM_X_LINKS; l++)
        {
            // pb_cfg_link_x#_en
            rc_ecmd |= data.writeBit(PB_HPX_MODE_LINK_X_EN_BIT[l],
                                     x_en[l]?1:0);

            // pb_cfg_link_nx#_addr_dis
            rc_ecmd |= data.writeBit(PB_HPX_MODE_LINK_X_ADDR_DIS_BIT[l],
                                     x_addr_dis[l]?1:0);

            // pb_cfg_link_x#_chipid
            rc_ecmd |= data.insertFromRight(
                x_id[l],
                PB_HPX_MODE_LINK_X_CHIPID_START_BIT[l],
                (PB_HPX_MODE_LINK_X_CHIPID_END_BIT[l]-
                 PB_HPX_MODE_LINK_X_CHIPID_START_BIT[l]+1));
        }

        // pb_cfg_x_aggregate
        rc_ecmd |= data.writeBit(PB_HPX_MODE_X_AGGREGATE_BIT,
                                 x_link_aggregate);

        // pb_cfg_x_indirect_en
        rc_ecmd |= data.writeBit(PB_HPX_MODE_X_INDIRECT_EN_BIT,
                                 PB_HPX_MODE_X_INDIRECT_EN?1:0);

        // pb_cfg_x_gather_enable
        rc_ecmd |= data.writeBit(PB_HPX_MODE_X_GATHER_ENABLE_BIT,
                                 PB_HPX_MODE_X_GATHER_ENABLE?1:0);

        // pb_cfg_x_dly_cnt
        rc_ecmd |= data.insertFromRight(
            PB_HPX_MODE_X_GATHER_DLY_CNT,
            PB_HPX_MODE_X_GATHER_DLY_CNT_START_BIT,
            (PB_HPX_MODE_X_GATHER_DLY_CNT_END_BIT-
             PB_HPX_MODE_X_GATHER_DLY_CNT_START_BIT+1));

        // pb_cfg_x_onnode_12queues
        rc_ecmd |= data.writeBit(PB_HPX_MODE_X_ONNODE_12QUEUES_BIT,
                                 PB_HPX_MODE_X_ONNODE_12QUEUES?1:0);

        // pb_cfg_x_cmd_rate
        rc_ecmd |= data.insertFromRight(
            x_cmd_rate,
            PB_HPX_MODE_X_CMD_RATE_START_BIT,
            (PB_HPX_MODE_X_CMD_RATE_END_BIT-
             PB_HPX_MODE_X_CMD_RATE_START_BIT+1));

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error 0x%x setting up PB Hotplug Extension Mode register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write current (working) registers
        if (i_set_curr)
        {
            rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                                true,
                                                false,
                                                data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error from proc_build_smp_set_hotplug_reg (CURR)");
                break;
            }
        }

        // write next (switch) registers
        if (i_set_next)
        {
            rc = proc_build_smp_set_hotplug_reg(i_smp_chip,
                                                false,
                                                false,
                                                data);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_pb_hpx_mode: Error from proc_build_smp_set_hotplug_reg (NEXT)");
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_pb_hpx_mode: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_set_fbc_ab(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_fbc_ab: Start");

    do
    {
        // loop through all chips
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                // in SMP activate phase1, quisece hostboot slave chips
                if ((i_op == SMP_ACTIVATE_PHASE1) &&
                    (!p_iter->second.master_chip_sys_next))
                {
                    rc = proc_build_smp_quiesce_pb(p_iter->second);
                    if (!rc.ok())
                    {
                        FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_quiesce_pb");
                        break;
                    }
                }

                // always program NEXT register set
                // only program CURR register set for hostboot slave chips in
                // SMP activate phase 1
                rc = proc_build_smp_set_pb_hp_mode(
                    p_iter->second,
                    i_smp,
                    ((i_op == SMP_ACTIVATE_PHASE1) &&
                     (!p_iter->second.master_chip_sys_next)),
                    true);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_set_pb_hp_mode");
                    break;
                }

                rc = proc_build_smp_set_pb_hpx_mode(
                    p_iter->second,
                    i_smp,
                    ((i_op == SMP_ACTIVATE_PHASE1) &&
                     (!p_iter->second.master_chip_sys_next)),
                    true);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_set_pb_hpx_mode");
                    break;
                }
            }
        }
        if (!rc.ok())
        {
            break;
        }

        // issue switch AB from current SMP master chip
        proc_fab_smp_node_id node_id = i_smp.master_chip_curr_node_id;
        proc_fab_smp_chip_id chip_id = i_smp.master_chip_curr_chip_id;
        rc = proc_build_smp_switch_ab(
            i_smp.nodes[node_id].chips[chip_id],
            i_smp);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_switch_ab");
            break;
        }

        // reset NEXT register set (copy CURR->NEXT)
        for (n_iter = i_smp.nodes.begin();
             (n_iter != i_smp.nodes.end()) && (rc.ok());
             n_iter++)
        {
            for (p_iter = n_iter->second.chips.begin();
                 (p_iter != n_iter->second.chips.end()) && (rc.ok());
                 p_iter++)
            {
                rc = proc_build_smp_reset_pb_hp_mode(p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_reset_pb_hp_mode");
                    break;
                }

                rc = proc_build_smp_reset_pb_hpx_mode(p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_ab: Error from proc_build_smp_reset_pb_hpx_mode");
                    break;
                }
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_fbc_ab: End");
    return rc;
}


} // extern "C"
