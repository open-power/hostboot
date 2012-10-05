/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_nohp.H $ */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
// $Id: proc_build_smp_fbc_nohp.H,v 1.2 2012/09/05 03:13:18 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_nohp.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_nohp.H
// *! DESCRIPTION : Fabric configuration (non-hotplug) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_NOHP_H_
#define _PROC_BUILD_SMP_FBC_NOHP_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp.H"
#include "p8_scom_addresses.H"

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


extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: program fabric configuration registers (non-hotplug)
// parameters: i_smp => structure encapsulating SMP topology
// returns: FAPI_RC_SUCCESS if register programming is successful,
//          RC_PROC_BUILD_SMP_INVALID_GROUP_SIZE_ERR if group size is too
//              small/large,
//          RC_PROC_BUILD_SMP_PACING_RATE_TABLE_ERR if pacing rate table lookup
//              is unsuccessful,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_nohp(
    proc_build_smp_system& i_smp);

} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_NOHP_H_
