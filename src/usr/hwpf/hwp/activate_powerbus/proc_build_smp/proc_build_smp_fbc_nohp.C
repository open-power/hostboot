/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_nohp.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2014                        */
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
// $Id: proc_build_smp_fbc_nohp.C,v 1.6 2014/02/23 21:41:07 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_nohp.C,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! ***  ***
// *|
// *! TITLE       : proc_build_smp_fbc_nohp.C
// *! DESCRIPTION : Fabric configuration (non-hotplug) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <proc_build_smp_fbc_nohp.H>


//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------

// enumerate chips per group configurations
enum proc_build_smp_chips_per_group {
    PROC_BUILD_SMP_1CPG = 0x0,
    PROC_BUILD_SMP_2CPG = 0x1,
    PROC_BUILD_SMP_4CPG = 0x2
};


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// PB Mode register field/bit definitions
//

const uint32_t PB_MODE_CHIP_IS_SYSTEM_BIT = 4;

const uint32_t PB_MODE_SHADOWS[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_MODE_WEST_0x02010C0A,
    PB_MODE_CENT_0x02010C4A,
    PB_MODE_EAST_0x02010C8A
};


//
// Group/Remote Group/System Command Pacing Rate register field/bit definitions
//

const uint8_t PROC_BUILD_SMP_DP_LEVELS = 8;

const uint8_t PB_GP_CMD_RATE_DP_LO_1CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   1,   2,   3,   4,   5,   6,   7,   8 };
const uint8_t PB_GP_CMD_RATE_DP_HI_1CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   2,   4,   6,   8,   8,   8,   8,   8 };
const uint8_t PB_RGP_CMD_RATE_DP_LO_1CPG[PROC_BUILD_SMP_DP_LEVELS] = {   9,   9,   9,   9,  10,  10,  11,  12 };
const uint8_t PB_RGP_CMD_RATE_DP_HI_1CPG[PROC_BUILD_SMP_DP_LEVELS] = {   9,  10,  11,  12,  13,  14,  15,  16 };
const uint8_t PB_SP_CMD_RATE_DP_LO_1CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   9,  10,  11,  12,  13,  14,  15,  16 };
const uint8_t PB_SP_CMD_RATE_DP_HI_1CPG[PROC_BUILD_SMP_DP_LEVELS]  = {  12,  13,  14,  16,  18,  20,  22,  24 };

const uint8_t PB_GP_CMD_RATE_DP_LO_2CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   3,   4,   5,   6,   7,   8,  10,  16 };
const uint8_t PB_GP_CMD_RATE_DP_HI_2CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   4,   5,   6,   7,   8,  10,  12,  16 };
const uint8_t PB_RGP_CMD_RATE_DP_LO_2CPG[PROC_BUILD_SMP_DP_LEVELS] = {   9,  10,  11,  12,  13,  14,  16,  32 };
const uint8_t PB_RGP_CMD_RATE_DP_HI_2CPG[PROC_BUILD_SMP_DP_LEVELS] = {  12,  13,  14,  15,  16,  20,  32,  32 };
const uint8_t PB_SP_CMD_RATE_DP_LO_2CPG[PROC_BUILD_SMP_DP_LEVELS]  = {  12,  13,  14,  15,  16,  20,  32,  64 };
const uint8_t PB_SP_CMD_RATE_DP_HI_2CPG[PROC_BUILD_SMP_DP_LEVELS]  = {  20,  22,  24,  26,  32,  40,  64,  64 };

const uint8_t PB_GP_CMD_RATE_DP_LO_4CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   3,   4,   5,   6,   8,  10,  16,  32 };
const uint8_t PB_GP_CMD_RATE_DP_HI_4CPG[PROC_BUILD_SMP_DP_LEVELS]  = {   4,   6,   8,  12,  16,  20,  32,  32 };
const uint8_t PB_RGP_CMD_RATE_DP_LO_4CPG[PROC_BUILD_SMP_DP_LEVELS] = {   9,  10,  11,  12,  16,  20,  32,  64 };
const uint8_t PB_RGP_CMD_RATE_DP_HI_4CPG[PROC_BUILD_SMP_DP_LEVELS] = {  12,  14,  16,  24,  32,  40,  64,  64 };
const uint8_t PB_SP_CMD_RATE_DP_LO_4CPG[PROC_BUILD_SMP_DP_LEVELS]  = {  12,  14,  16,  24,  32,  40,  64, 128 };
const uint8_t PB_SP_CMD_RATE_DP_HI_4CPG[PROC_BUILD_SMP_DP_LEVELS]  = {  20,  24,  32,  48,  64,  80, 128, 128 };

const uint32_t PB_SCOPE_COMMAND_PACING_LVL_START_BIT[PROC_BUILD_SMP_DP_LEVELS] = {  0,  8, 16, 24, 32, 40, 48, 56 };
const uint32_t PB_SCOPE_COMMAND_PACING_LVL_END_BIT[PROC_BUILD_SMP_DP_LEVELS]   = {  7, 15, 23, 31, 39, 47, 55, 63 };


// define set of group scope command pacing rate settings
struct proc_build_smp_gp_low_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_GP_CMD_RATE_DP_LO_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_GP_CMD_RATE_DP_LO_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_GP_CMD_RATE_DP_LO_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};

struct proc_build_smp_gp_high_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_GP_CMD_RATE_DP_HI_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_GP_CMD_RATE_DP_HI_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_GP_CMD_RATE_DP_HI_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};

struct proc_build_smp_sp_low_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_SP_CMD_RATE_DP_LO_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_SP_CMD_RATE_DP_LO_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_SP_CMD_RATE_DP_LO_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};

struct proc_build_smp_sp_high_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_SP_CMD_RATE_DP_HI_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_SP_CMD_RATE_DP_HI_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_SP_CMD_RATE_DP_HI_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};

struct proc_build_smp_rgp_low_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_RGP_CMD_RATE_DP_LO_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_RGP_CMD_RATE_DP_LO_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_RGP_CMD_RATE_DP_LO_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};

struct proc_build_smp_rgp_high_pacing_table
{
    static std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> create_map()
    {
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> m;
        m.insert(std::make_pair(PROC_BUILD_SMP_1CPG, &PB_RGP_CMD_RATE_DP_HI_1CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_2CPG, &PB_RGP_CMD_RATE_DP_HI_2CPG));
        m.insert(std::make_pair(PROC_BUILD_SMP_4CPG, &PB_RGP_CMD_RATE_DP_HI_4CPG));
        return m;
    }
    static const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> xlate_map;
};



const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_gp_low_pacing_table::xlate_map =
    proc_build_smp_gp_low_pacing_table::create_map();

const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_gp_high_pacing_table::xlate_map =
    proc_build_smp_gp_high_pacing_table::create_map();

const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_sp_low_pacing_table::xlate_map =
    proc_build_smp_sp_low_pacing_table::create_map();

const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_sp_high_pacing_table::xlate_map =
    proc_build_smp_sp_high_pacing_table::create_map();

const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_rgp_low_pacing_table::xlate_map =
    proc_build_smp_rgp_low_pacing_table::create_map();

const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]> proc_build_smp_rgp_high_pacing_table::xlate_map =
    proc_build_smp_rgp_high_pacing_table::create_map();


//
// X Link Mode register field/bit definitions
//

const uint32_t PB_X_MODE_TRACE_ENABLE_BIT = 4;
const uint32_t PB_X_MODE_TRACE_SELECT_START_BIT = 5;
const uint32_t PB_X_MODE_TRACE_SELECT_END_BIT = 7;


//
// A Link Trace register field/bit definitions
//

const uint32_t PB_A_TRACE_A0_OUT_SEL0_START_BIT = 0;
const uint32_t PB_A_TRACE_A0_OUT_SEL0_END_BIT = 1;
const uint32_t PB_A_TRACE_A0_OUT_SEL1_START_BIT = 2;
const uint32_t PB_A_TRACE_A0_OUT_SEL1_END_BIT = 3;
const uint32_t PB_A_TRACE_A0_OUT_SEL2_START_BIT = 4;
const uint32_t PB_A_TRACE_A0_OUT_SEL2_END_BIT = 5;
const uint32_t PB_A_TRACE_A1_OUT_SEL0_START_BIT = 6;
const uint32_t PB_A_TRACE_A1_OUT_SEL0_END_BIT = 7;
const uint32_t PB_A_TRACE_A1_OUT_SEL1_START_BIT = 8;
const uint32_t PB_A_TRACE_A1_OUT_SEL1_END_BIT = 9;
const uint32_t PB_A_TRACE_A1_OUT_SEL2_START_BIT = 10;
const uint32_t PB_A_TRACE_A1_OUT_SEL2_END_BIT = 11;
const uint32_t PB_A_TRACE_A2_OUT_SEL0_START_BIT = 12;
const uint32_t PB_A_TRACE_A2_OUT_SEL0_END_BIT = 13;
const uint32_t PB_A_TRACE_A2_OUT_SEL1_START_BIT = 14;
const uint32_t PB_A_TRACE_A2_OUT_SEL1_END_BIT = 15;
const uint32_t PB_A_TRACE_A2_OUT_SEL2_START_BIT = 16;
const uint32_t PB_A_TRACE_A2_OUT_SEL2_END_BIT = 17;

//
// F Link Trace register field/bit definitions
//

const uint32_t PB_F_TRACE_F0_OUT_SEL0_START_BIT = 0;
const uint32_t PB_F_TRACE_F0_OUT_SEL0_END_BIT = 3;
const uint32_t PB_F_TRACE_F0_OUT_SEL1_START_BIT = 8;
const uint32_t PB_F_TRACE_F0_OUT_SEL1_END_BIT = 11;
const uint32_t PB_F_TRACE_F1_OUT_SEL0_START_BIT = 16;
const uint32_t PB_F_TRACE_F1_OUT_SEL0_END_BIT = 19;
const uint32_t PB_F_TRACE_F1_OUT_SEL1_START_BIT = 24;
const uint32_t PB_F_TRACE_F1_OUT_SEL1_END_BIT = 27;
const uint32_t PB_F_TRACE_F0_OBS_SEL = 32;
const uint32_t PB_F_TRACE_F1_OBS_SEL = 33;


extern "C" {

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// function: utility function to determine number of chips present
//           in enclosing group
// parameters: i_smp_chip        => structure encapsulating SMP chip
//             i_smp             => structure encapsulating SMP topology
//             o_chips_per_group => enum representing number of chips in
//                                  group enclosing i_smp_chip
// returns: FAPI_RC_SUCCESS if output group size is valid,
//          else RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR if group size is too
//              small/large
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_calc_chips_per_group(
    const proc_build_smp_chip& i_smp_chip,
    proc_build_smp_system& i_smp,
    proc_build_smp_chips_per_group& o_chips_per_group)
{
    fapi::ReturnCode rc;
    uint8_t chips_per_group_exact;

    // mark function entry
    FAPI_DBG("proc_build_smp_calc_chips_per_group: Start");

    chips_per_group_exact = i_smp.nodes[i_smp_chip.node_id].chips.size();
    switch(chips_per_group_exact)
    {
        case 1:
            o_chips_per_group = PROC_BUILD_SMP_1CPG;
            break;
        case 2:
            o_chips_per_group = PROC_BUILD_SMP_2CPG;
            break;
        case 3:
        case 4:
            o_chips_per_group = PROC_BUILD_SMP_4CPG;
            break;
        default:
            FAPI_ERR("proc_build_smp_calc_chips_per_group: Unsupported group size (=%d)",
                     chips_per_group_exact);
            const fapi::Target& TARGET = i_smp_chip.chip->this_chip;
            const uint8_t& GROUP_SIZE = chips_per_group_exact;
            const proc_fab_smp_node_id & NODE_ID = i_smp_chip.node_id;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR);
            break;
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_calc_chips_per_group: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: utility function to program one command scope drop priority
//           register
// parameters: i_smp_chip        => structure encapsulating SMP chip
//             i_chips_per_group => enum representing chips in group enclosing
//                                  i_smp_chip
//             i_map_table       => map defining drop priority programming rates
//             i_scom_addr       => target SCOM register
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_PACING_RATE_TABLE_ERR if pacing rate table lookup
//              is unsuccessful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_pacing_rate(
    const proc_build_smp_chip& i_smp_chip,
    const proc_build_smp_chips_per_group& i_chips_per_group,
    const std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]>& i_map_table,
    const uint32_t i_scom_addr)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);

    // mark function entry
    FAPI_DBG("proc_build_smp_set_pacing_rate: Start");

    do
    {
        // access map table
        std::map<uint8_t, const uint8_t(*)[PROC_BUILD_SMP_DP_LEVELS]>::const_iterator m =
            i_map_table.find(i_chips_per_group);

        if (m == i_map_table.end())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rate: Pacing rate map table lookup failed");
            const fapi::Target& TARGET = i_smp_chip.chip->this_chip;
            const proc_build_smp_chips_per_group& GROUP_SIZE = i_chips_per_group;
            const proc_fab_smp_node_id& NODE_ID = i_smp_chip.node_id;
            FAPI_SET_HWP_ERROR(rc, RC_PROC_BUILD_SMP_PACING_RATE_TABLE_ERR);
            break;
        }

        // set all drop priority level fields
        for (uint8_t l = 0; l < PROC_BUILD_SMP_DP_LEVELS; l++)
        {
            // pb_cfg_##_cmd_rate_dp#_lvl#
            rc_ecmd |= data.insertFromRight(
                (*(m->second))[l],
                PB_SCOPE_COMMAND_PACING_LVL_START_BIT[l],
                (PB_SCOPE_COMMAND_PACING_LVL_END_BIT[l]-
                 PB_SCOPE_COMMAND_PACING_LVL_START_BIT[l]+1));
        }

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_pacing_rate: Error 0x%x setting up data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScom(i_smp_chip.chip->this_chip, i_scom_addr, data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rate: fapiPutScom error (%08X)",
                     i_scom_addr);
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_pacing_rate: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program all command scope drop priority registers
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR if group size is too
//              small/large,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_pacing_rates(
    const proc_build_smp_chip& i_smp_chip,
    proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    proc_build_smp_chips_per_group chips_per_group;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_pacing_rates: Start");

    do
    {
        // determine number of chips in enclosing group (use to index proper
        // drop priority table)
        rc = proc_build_smp_calc_chips_per_group(i_smp_chip,
                                                 i_smp,
                                                 chips_per_group);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_calc_chips_per_group");
            break;
        }

        // group (low)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_gp_low_pacing_table::xlate_map,
                                            PB_GP_CMD_RATE_DP_LO_0x02010C62);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (GP low)");
            break;
        }

        // group (high)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_gp_high_pacing_table::xlate_map,
                                            PB_GP_CMD_RATE_DP_HI_0x02010C63);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (GP high)");
            break;
        }

        // remote group (low)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_rgp_low_pacing_table::xlate_map,
                                            PB_RGP_CMD_RATE_DP_LO_0x02010C64);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (RGP low)");
            break;
        }

        // remote group (high)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_rgp_high_pacing_table::xlate_map,
                                            PB_RGP_CMD_RATE_DP_HI_0x02010C65);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (RGP high)");
            break;
        }

        // system (low)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_sp_low_pacing_table::xlate_map,
                                            PB_SP_CMD_RATE_DP_LO_0x02010C66);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (SP low)");
            break;
        }

        // system (high)
        rc = proc_build_smp_set_pacing_rate(i_smp_chip,
                                            chips_per_group,
                                            proc_build_smp_sp_high_pacing_table::xlate_map,
                                            PB_SP_CMD_RATE_DP_HI_0x02010C67);
        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_pacing_rates: Error from proc_build_smp_set_pacing_rate (SP high)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_pacing_rates: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB mode register
// parameters: i_smp_chip => structure encapsulating SMP chip
//             i_smp      => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_pb_mode(
    const proc_build_smp_chip& i_smp_chip,
    proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64), mask(64);
    bool chip_is_system = false;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_pb_mode: Start");

    do
    {
        // compute derived register fields
        // pb_cfg_chip_is_system
        // set for single chip SMP, only if AVP mode is off
        chip_is_system = ((i_smp.nodes.size() == 1) &&
                          (i_smp.nodes[i_smp_chip.node_id].chips.size() == 1) &&
                          (!i_smp.avp_mode));

        // pb_cfg_chip_is_system
        rc_ecmd |= data.writeBit(PB_MODE_CHIP_IS_SYSTEM_BIT,
                                 chip_is_system?1:0);
        rc_ecmd |= mask.setBit(PB_MODE_CHIP_IS_SYSTEM_BIT);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_pb_mode: Error 0x%x setting up PB Mode register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write west/center/east register copies (use mask to avoid overriding
        // other configuration settings in register)
        for (uint8_t r = 0; r < PROC_BUILD_SMP_NUM_SHADOWS; r++)
        {
            rc = fapiPutScomUnderMask(i_smp_chip.chip->this_chip,
                                      PB_MODE_SHADOWS[r],
                                      data,
                                      mask);

            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_pb_mode: fapiPutScomUnderMask error (%08X)",
                         PB_MODE_SHADOWS[r]);
                break;
            }
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_pb_mode: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB X Link Mode register (configure trace selection based
//           on first active link)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_x_trace(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64), mask(64);
    bool trace_enable = false;
    uint8_t trace_sel = 0x0;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_x_trace: Start");

    do
    {
        // find first configured link, set to trace outbound traffic
        if (i_smp_chip.chip->x0_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            trace_enable = true;
            trace_sel = 0x4;
        }
        else if (i_smp_chip.chip->x1_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            trace_enable = true;
            trace_sel = 0x5;
        }
        else if (i_smp_chip.chip->x2_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            trace_enable = true;
            trace_sel = 0x6;
        }
        else if (i_smp_chip.chip->x3_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            trace_enable = true;
            trace_sel = 0x7;
        }

        // build data buffer
        // trace enable
        rc_ecmd |= data.writeBit(
            PB_X_MODE_TRACE_ENABLE_BIT,
            trace_enable?1:0);
        rc_ecmd |= mask.setBit(
            PB_X_MODE_TRACE_ENABLE_BIT);

        // trace select
        rc_ecmd |= data.insertFromRight(
            trace_sel,
            PB_X_MODE_TRACE_SELECT_START_BIT,
            (PB_X_MODE_TRACE_SELECT_END_BIT-
             PB_X_MODE_TRACE_SELECT_START_BIT)+1);
        rc_ecmd |= mask.setBit(
            PB_X_MODE_TRACE_SELECT_START_BIT,
            (PB_X_MODE_TRACE_SELECT_END_BIT-
             PB_X_MODE_TRACE_SELECT_START_BIT)+1);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_x_trace: Error 0x%x setting up X Link Mode register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScomUnderMask(i_smp_chip.chip->this_chip,
                                  PB_X_MODE_0x04010C0A,
                                  data,
                                  mask);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_x_trace: fapiPutScomUnderMask error (PB_X_MODE_0x04010C0A)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_x_trace: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB A Link Trace register (configure trace selection based
//           on first active link)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_a_trace(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64);
    uint8_t a0_out_sel = 0x0;
    uint8_t a1_out_sel = 0x0;
    uint8_t a2_out_sel = 0x0;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_a_trace: Start");

    do
    {
        // find first configured link, set to trace outbound traffic
        if (i_smp_chip.chip->a0_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            a0_out_sel = 0x1;
            a1_out_sel = 0x0;
            a2_out_sel = 0x0;
        }
        else if (i_smp_chip.chip->a1_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            a0_out_sel = 0x0;
            a1_out_sel = 0x1;
            a2_out_sel = 0x0;
        }
        else if (i_smp_chip.chip->a2_chip.getType() != fapi::TARGET_TYPE_NONE)
        {
            a0_out_sel = 0x0;
            a1_out_sel = 0x0;
            a2_out_sel = 0x1;
        }

        // build data buffer (clear previous configuration)
        // A0 outbound trace select
        rc_ecmd |= data.insertFromRight(
            a0_out_sel,
            PB_A_TRACE_A0_OUT_SEL0_START_BIT,
            (PB_A_TRACE_A0_OUT_SEL0_END_BIT-
             PB_A_TRACE_A0_OUT_SEL0_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a0_out_sel,
            PB_A_TRACE_A0_OUT_SEL1_START_BIT,
            (PB_A_TRACE_A0_OUT_SEL1_END_BIT-
             PB_A_TRACE_A0_OUT_SEL1_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a0_out_sel,
            PB_A_TRACE_A0_OUT_SEL2_START_BIT,
            (PB_A_TRACE_A0_OUT_SEL2_END_BIT-
             PB_A_TRACE_A0_OUT_SEL2_START_BIT)+1);

        // A1 outbound trace select
        rc_ecmd |= data.insertFromRight(
            a1_out_sel,
            PB_A_TRACE_A1_OUT_SEL0_START_BIT,
            (PB_A_TRACE_A1_OUT_SEL0_END_BIT-
             PB_A_TRACE_A1_OUT_SEL0_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a1_out_sel,
            PB_A_TRACE_A1_OUT_SEL1_START_BIT,
            (PB_A_TRACE_A1_OUT_SEL1_END_BIT-
             PB_A_TRACE_A1_OUT_SEL1_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a1_out_sel,
            PB_A_TRACE_A1_OUT_SEL2_START_BIT,
            (PB_A_TRACE_A1_OUT_SEL2_END_BIT-
             PB_A_TRACE_A1_OUT_SEL2_START_BIT)+1);

        // A2 outbound trace select
        rc_ecmd |= data.insertFromRight(
            a2_out_sel,
            PB_A_TRACE_A2_OUT_SEL0_START_BIT,
            (PB_A_TRACE_A2_OUT_SEL0_END_BIT-
             PB_A_TRACE_A2_OUT_SEL0_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a2_out_sel,
            PB_A_TRACE_A2_OUT_SEL1_START_BIT,
            (PB_A_TRACE_A2_OUT_SEL1_END_BIT-
             PB_A_TRACE_A2_OUT_SEL1_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            a2_out_sel,
            PB_A_TRACE_A2_OUT_SEL2_START_BIT,
            (PB_A_TRACE_A2_OUT_SEL2_END_BIT-
             PB_A_TRACE_A2_OUT_SEL2_START_BIT)+1);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_a_trace: Error 0x%x setting up A Link Trace register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScom(i_smp_chip.chip->this_chip,
                         PB_A_TRACE_0x08010812,
                         data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_a_trace: fapiPutScom error (PB_A_TRACE_0x08010812)");
            break;
        }

    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_a_trace: End");
    return rc;
}


//------------------------------------------------------------------------------
// function: program PB F Link Trace register (configure trace selection based
//           on first active link)
// parameters: i_smp_chip => structure encapsulating SMP chip
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_f_trace(
    const proc_build_smp_chip& i_smp_chip)
{
    fapi::ReturnCode rc;
    uint32_t rc_ecmd = 0x0;
    ecmdDataBufferBase data(64), mask(64);
    uint8_t f0_out_sel = 0x0;
    uint8_t f1_out_sel = 0x0;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_f_trace: Start");

    do
    {
        // find first configured link, set to trace outbound traffic
        if (i_smp_chip.chip->enable_f0)
        {
            f0_out_sel = 0x1;
            f1_out_sel = 0x0;
        }
        else if (i_smp_chip.chip->enable_f1)
        {
            f0_out_sel = 0x0;
            f1_out_sel = 0x1;
        }

        // build data buffer (clear previous configuration)
        // F0 outbound trace select
        rc_ecmd |= data.insertFromRight(
            f0_out_sel,
            PB_F_TRACE_F0_OUT_SEL0_START_BIT,
            (PB_F_TRACE_F0_OUT_SEL0_END_BIT-
             PB_F_TRACE_F0_OUT_SEL0_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            f0_out_sel,
            PB_F_TRACE_F0_OUT_SEL1_START_BIT,
            (PB_F_TRACE_F0_OUT_SEL1_END_BIT-
             PB_F_TRACE_F0_OUT_SEL1_START_BIT)+1);

        // F1 outbound trace select
        rc_ecmd |= data.insertFromRight(
            f1_out_sel,
            PB_F_TRACE_F1_OUT_SEL0_START_BIT,
            (PB_F_TRACE_F1_OUT_SEL0_END_BIT-
             PB_F_TRACE_F1_OUT_SEL0_START_BIT)+1);
        rc_ecmd |= data.insertFromRight(
            f1_out_sel,
            PB_F_TRACE_F1_OUT_SEL1_START_BIT,
            (PB_F_TRACE_F1_OUT_SEL1_END_BIT-
             PB_F_TRACE_F1_OUT_SEL1_START_BIT)+1);

        if (rc_ecmd)
        {
            FAPI_ERR("proc_build_smp_set_f_trace: Error 0x%x setting up F Link Trace register data buffer",
                     rc_ecmd);
            rc.setEcmdError(rc_ecmd);
            break;
        }

        // write register
        rc = fapiPutScom(i_smp_chip.chip->this_chip,
                         PB_F_TRACE_0x09010812,
                         data);

        if (!rc.ok())
        {
            FAPI_ERR("proc_build_smp_set_f_trace: fapiPutScom error (PB_F_TRACE_0x09010812)");
            break;
        }
    } while(0);

    // mark function exit
    FAPI_DBG("proc_build_smp_set_f_trace: End");
    return rc;
}


// NOTE: see comments above function prototype in header
fapi::ReturnCode proc_build_smp_set_fbc_nohp(
    proc_build_smp_system& i_smp)
{
    fapi::ReturnCode rc;
    std::map<proc_fab_smp_node_id, proc_build_smp_node>::iterator n_iter;
    std::map<proc_fab_smp_chip_id, proc_build_smp_chip>::iterator p_iter;

    // mark function entry
    FAPI_DBG("proc_build_smp_set_fbc_nohp: Start");

    // process each chip in SMP, program unit non-hotplug registers
    for (n_iter = i_smp.nodes.begin();
         (n_iter != i_smp.nodes.end()) && (rc.ok());
         n_iter++)
    {
        for (p_iter = n_iter->second.chips.begin();
             (p_iter != n_iter->second.chips.end()) && (rc.ok());
             p_iter++)
        {
            fapi::Target target = p_iter->second.chip->this_chip;

            // PB Mode register
            rc = proc_build_smp_set_pb_mode(p_iter->second,
                                            i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_nohp: Error from proc_build_smp_set_pb_mode");
                break;
            }

            // command scope drop priority registers
            rc = proc_build_smp_set_pacing_rates(p_iter->second,
                                                 i_smp);
            if (!rc.ok())
            {
                FAPI_ERR("proc_build_smp_set_fbc_nohp: Error from proc_build_smp_set_pacing_rates");
                break;
            }

            // X link trace setup
            if (p_iter->second.x_enabled)
            {
                rc = proc_build_smp_set_x_trace(p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_nohp: Error from proc_build_smp_set_x_trace");
                    break;
                }
            }

            // A link trace setup
            if (p_iter->second.a_enabled)
            {
                rc = proc_build_smp_set_a_trace(p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_nohp: Error from proc_build_smp_set_a_trace");
                    break;
                }
            }

            // F link trace setup
            if (p_iter->second.pcie_enabled)
            {
                rc = proc_build_smp_set_f_trace(p_iter->second);
                if (!rc.ok())
                {
                    FAPI_ERR("proc_build_smp_set_fbc_nohp: Error from proc_build_smp_set_f_trace");
                    break;
                }
            }
        }
    }

    // mark function exit
    FAPI_DBG("proc_build_smp_set_fbc_nohp: End");
    return rc;
}


} // extern "C"
