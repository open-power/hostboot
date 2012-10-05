/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/activate_powerbus/proc_build_smp/proc_build_smp_fbc_ab.H $ */
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
// $Id: proc_build_smp_fbc_ab.H,v 1.2 2012/09/05 03:12:18 jmcgill Exp $
// $Source: /afs/awd/projects/eclipz/KnowledgeBase/.cvsroot/eclipz/chips/p8/working/procedures/ipl/fapi/proc_build_smp_fbc_ab.H,v $
//------------------------------------------------------------------------------
// *|
// *! (C) Copyright International Business Machines Corp. 2011
// *! All Rights Reserved -- Property of IBM
// *! *** IBM Confidential ***
// *|
// *! TITLE       : proc_build_smp_fbc_ab.H
// *! DESCRIPTION : Fabric configuration (hotplug, AB) functions (FAPI)
// *!
// *! OWNER NAME  : Joe McGill    Email: jmcgill@us.ibm.com
// *!
//------------------------------------------------------------------------------

#ifndef _PROC_BUILD_SMP_FBC_AB_H_
#define _PROC_BUILD_SMP_FBC_AB_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "proc_build_smp.H"
#include "p8_scom_addresses.H"

//------------------------------------------------------------------------------
// Structure definitions
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// PB Hotplug Mode register field/bit definitions
const uint32_t PB_HP_MODE_LINK_A_EN_BIT[PROC_FAB_SMP_NUM_A_LINKS]       = {  1,  2,  3 };
const uint32_t PB_HP_MODE_LINK_A_ADDR_DIS_BIT[PROC_FAB_SMP_NUM_A_LINKS] = {  4,  5,  6 };
const uint32_t PB_HP_MODE_LINK_A_ID_START_BIT[PROC_FAB_SMP_NUM_A_LINKS] = {  7, 10, 13 };
const uint32_t PB_HP_MODE_LINK_A_ID_END_BIT[PROC_FAB_SMP_NUM_A_LINKS]   = {  9, 12, 15 };

const uint32_t PB_HP_MODE_PCIE_NOT_DSMP_BIT[PROC_FAB_SMP_NUM_F_LINKS]   = { 38, 39 };
const uint32_t PB_HP_MODE_LINK_F_MASTER_BIT[PROC_FAB_SMP_NUM_F_LINKS]   = { 42, 43 };
const uint32_t PB_HP_MODE_LINK_F_EN_BIT[PROC_FAB_SMP_NUM_F_LINKS]       = { 44, 45 };
const uint32_t PB_HP_MODE_LINK_F_ADDR_DIS_BIT[PROC_FAB_SMP_NUM_F_LINKS] = { 46, 47 };
const uint32_t PB_HP_MODE_LINK_F_ID_START_BIT[PROC_FAB_SMP_NUM_F_LINKS] = { 48, 51 };
const uint32_t PB_HP_MODE_LINK_F_ID_END_BIT[PROC_FAB_SMP_NUM_F_LINKS]   = { 50, 53 };

const uint32_t PB_HP_MODE_MASTER_CHIP_BIT = 0;
const uint32_t PB_HP_MODE_A_AGGREGATE_BIT = 16;
const uint32_t PB_HP_MODE_TM_MASTER_BIT = 17;
const uint32_t PB_HP_MODE_CHG_RATE_GP_MASTER_BIT = 18;
const uint32_t PB_HP_MODE_CHG_RATE_SP_MASTER_BIT = 19;
const uint32_t PB_HP_MODE_PUMP_MODE_BIT = 20;
const uint32_t PB_HP_MODE_SINGLE_MC_BIT = 21;
const uint32_t PB_HP_MODE_DCACHE_CAPP_MODE_BIT = 22;
const uint32_t PB_HP_MODE_A_CMD_RATE_START_BIT = 24;
const uint32_t PB_HP_MODE_A_CMD_RATE_END_BIT = 31;
const uint32_t PB_HP_MODE_A_CMD_RATE_MIN_VALUE = 1;
const uint32_t PB_HP_MODE_A_CMD_RATE_MAX_VALUE = 0x7F;
const uint32_t PB_HP_MODE_A_GATHER_ENABLE_BIT = 32;
const uint32_t PB_HP_MODE_A_GATHER_DLY_CNT_START_BIT = 33;
const uint32_t PB_HP_MODE_A_GATHER_DLY_CNT_END_BIT = 37;
const uint32_t PB_HP_MODE_GATHER_ENABLE_BIT = 40;
const uint32_t PB_HP_MODE_F_AGGREGATE_BIT = 55;
const uint32_t PB_HP_MODE_F_CMD_RATE_START_BIT = 56;
const uint32_t PB_HP_MODE_F_CMD_RATE_END_BIT = 63;
const uint32_t PB_HP_MODE_F_CMD_RATE_MIN_VALUE = 1;
const uint32_t PB_HP_MODE_F_CMD_RATE_MAX_VALUE = 0x7F;

const bool PB_HP_MODE_DCACHE_CAPP_EN = false;
const bool PB_HP_MODE_A_GATHER_ENABLE = true;
const uint8_t PB_HP_MODE_A_GATHER_DLY_CNT = 0x04;
const bool PB_HP_MODE_GATHER_ENABLE = true;

const uint32_t PB_HP_MODE_NEXT_SHADOWS[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HP_MODE_NEXT_WEST_0x02010C0B,
    PB_HP_MODE_NEXT_CENT_0x02010C4B,
    PB_HP_MODE_NEXT_EAST_0x02010C8B
};
const uint32_t PB_HP_MODE_CURR_SHADOWS[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HP_MODE_CURR_WEST_0x02010C0C,
    PB_HP_MODE_CURR_CENT_0x02010C4C,
    PB_HP_MODE_CURR_EAST_0x02010C8C
};

// PB Hotplug Extension Mode register field/bit definitions
const uint32_t PB_HPX_MODE_LINK_X_EN_BIT[PROC_FAB_SMP_NUM_X_LINKS]           = {  0,  1,  2,  3 };
const uint32_t PB_HPX_MODE_LINK_X_ADDR_DIS_BIT[PROC_FAB_SMP_NUM_X_LINKS]     = {  5,  6,  7,  8 };
const uint32_t PB_HPX_MODE_LINK_X_CHIPID_START_BIT[PROC_FAB_SMP_NUM_X_LINKS] = { 10, 13, 16, 19 };
const uint32_t PB_HPX_MODE_LINK_X_CHIPID_END_BIT[PROC_FAB_SMP_NUM_X_LINKS]   = { 12, 15, 18, 21 };

const uint32_t PB_HPX_MODE_X_AGGREGATE_BIT = 25;
const uint32_t PB_HPX_MODE_X_INDIRECT_EN_BIT = 26;
const uint32_t PB_HPX_MODE_X_GATHER_ENABLE_BIT = 32;
const uint32_t PB_HPX_MODE_X_GATHER_DLY_CNT_START_BIT = 33;
const uint32_t PB_HPX_MODE_X_GATHER_DLY_CNT_END_BIT = 37;
const uint32_t PB_HPX_MODE_X_ONNODE_12QUEUES_BIT = 38;
const uint32_t PB_HPX_MODE_X_CMD_RATE_START_BIT = 56;
const uint32_t PB_HPX_MODE_X_CMD_RATE_END_BIT = 63;
const uint32_t PB_HPX_MODE_X_CMD_RATE_MIN_VALUE = 1;
const uint32_t PB_HPX_MODE_X_CMD_RATE_MAX_VALUE = 0x7F;

const bool PB_HPX_MODE_X_INDIRECT_EN = true;
const bool PB_HPX_MODE_X_GATHER_ENABLE = true;
const uint8_t PB_HPX_MODE_X_GATHER_DLY_CNT = 0x04;
const bool PB_HPX_MODE_X_ONNODE_12QUEUES = true;

const uint32_t PB_HPX_MODE_NEXT_SHADOWS[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HPX_MODE_NEXT_WEST_0x02010C0D,
    PB_HPX_MODE_NEXT_CENT_0x02010C4D,
    PB_HPX_MODE_NEXT_EAST_0x02010C8D
};
const uint32_t PB_HPX_MODE_CURR_SHADOWS[PROC_BUILD_SMP_NUM_SHADOWS] =
{
    PB_HPX_MODE_CURR_WEST_0x02010C0E,
    PB_HPX_MODE_CURR_CENT_0x02010C4E,
    PB_HPX_MODE_CURR_EAST_0x02010C8E
};

// PB X Link Mode register field/bit definitions
const uint32_t PB_X_MODE_LINK_DELAY_START_BIT[PROC_FAB_SMP_NUM_X_LINKS] = { 24, 32, 40, 48 };
const uint32_t PB_X_MODE_LINK_DELAY_END_BIT[PROC_FAB_SMP_NUM_X_LINKS]   = { 31, 39, 47, 55 };

// PB A Link Mode register field/bit definitions
const uint32_t PB_A_MODE_LINK_DELAY_START_BIT[PROC_FAB_SMP_NUM_A_LINKS] = { 40, 48, 56 };
const uint32_t PB_A_MODE_LINK_DELAY_END_BIT[PROC_FAB_SMP_NUM_A_LINKS]   = { 47, 55, 63 };

// PB A Link Framer Configuration register field/bit definitions
const uint32_t PB_A_FMR_CFG_OW_PACK_BIT = 24;
const uint32_t PB_A_FMR_CFG_OW_PACK_PRIORITY_BIT = 25;

// PB IOF Link Mode register field/bit definitions
const uint32_t PB_IOF_MODE_LINK_DELAY_START_BIT[PROC_FAB_SMP_NUM_F_LINKS] = { 32, 48 };
const uint32_t PB_IOF_MODE_LINK_DELAY_END_BIT[PROC_FAB_SMP_NUM_F_LINKS]   = { 47, 63 };

// PB F Link Framer Configuration register field/bit definitions
const uint32_t PB_F_FMR_CFG_OW_PACK_BIT = 20;
const uint32_t PB_F_FMR_CFG_OW_PACK_PRIORITY_BIT = 21;

extern "C"
{

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// function: utility function to read set of PB CURR hotplug registers
// parameters: i_smp_chip   => structure encapsulating SMP chip
//             i_hp_not_hpx => choose HP/HPX register set (true=HP,
//                             false=HPX)
//             o_data       => data buffer containing read data
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_get_hotplug_curr_reg(
    const proc_build_smp_chip& i_smp_chip,
    const bool i_hp_not_hpx,
    ecmdDataBufferBase& o_data);


//------------------------------------------------------------------------------
// function: program fabric configuration register (hotplug, A/B set)
// parameters: i_smp => structure encapsulating SMP topology
//             i_op  => enumerated type representing SMP build phase
// returns: FAPI_RC_SUCCESS if register reads are successful and all shadow
//               registers are equivalent,
//          RC_PROC_FAB_SMP_FABRIC_CHIP_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_FAB_SMP_FABRIC_NODE_ID_ATTR_ERR if attribute value is
//              invalid,
//          RC_PROC_BUILD_SMP_HOTPLUG_SHADOW_ERR if shadow registers are not
//              equivalent,
//          RC_PROC_BUILD_SMP_INVALID_AGGREGATE_CONFIG_ERR if configuration
//              specifies invalid aggregate link setup,
//          RC_PROC_BUILD_SMP_A_CMD_RATE_ERR if calculated A link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_F_CMD_RATE_ERR if calculated F link command rate
//              is invalid,
//          RC_PROC_BUILD_SMP_X_CMD_RATE_ERR if calculated X link command rate
//              is invalid,
//          else error
//------------------------------------------------------------------------------
fapi::ReturnCode proc_build_smp_set_fbc_ab(
    proc_build_smp_system& i_smp,
    const proc_build_smp_operation i_op);

} // extern "C"

#endif // _PROC_BUILD_SMP_FBC_AB_H_
