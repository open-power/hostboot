/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/nest_chiplets/nest_chiplets.H $              */
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
#ifndef  __NEST_CHIPLETS_NEST_CHIPLETS_H
#define  __NEST_CHIPLETS_NEST_CHIPLETS_H

/**
 *  @file nest_chiplets.H
 *
 *  Nest Chiplets
 *
 *  All of the following routines are "named isteps" - they are invoked as
 *  tasks by the @ref IStepDispatcher.
 *
 *  *****************************************************************
 *  THIS FILE WAS GENERATED ON 2012-04-03:1952
 *  *****************************************************************
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

 /*  @tag isteplist
 *  @docversion     v1.28 (12/03/12)
 *  @istepname      nest_chiplets
 *  @istepnum       07
 *  @istepdesc      Nest Chiplets
 *
 *  @{
 *      @substepnum     1
 *      @substepname    proc_a_x_pci_dmi_pll_initf
 *      @substepdesc    : PLL Initfile for A, X, PCIe, DMI
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     2
 *      @substepname    proc_a_x_pci_dmi_pll_setup
 *      @substepdesc    : Setup PLL for A, X, PCIe, DMI
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     3
 *      @substepname    proc_startclock_chiplets
 *      @substepdesc    : Start clocks on A, X, PCIe chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     4
 *      @substepname    proc_chiplet_scominit
 *      @substepdesc    : Apply scom inits to chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     5
 *      @substepname    proc_xbus_scominit
 *      @substepdesc    : Apply scom inits to Xbus
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     6
 *      @substepname    proc_abus_scominit
 *      @substepdesc    : Apply scom inits to Abus
 *          @target_sched   serial
 *  @}

 *  @{
 *      @substepnum     7
 *      @substepname    proc_pcie_scominit
 *      @substepdesc    : Apply scom inits to PCIe chiplets
 *          @target_sched   serial
 *  @}
 *  @{
 *      @substepnum     8
 *      @substepname    proc_scomoverride_chiplets
 *      @substepdesc    : Apply sequenced scom inits
 *          @target_sched   serial
 *  @}
 *
 */ 

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   NEST_CHIPLETS
{

/**
 *  @brief # of bits in a byte for computation purposes
 */
static const size_t BITS_PER_BYTE = 8;

/**
 *  @brief Container for holding IOPs to bifurcate
 */
typedef std::list<uint32_t> BifurcatedIopsContainer;

/**
 *  @brief Enum indicating number of usable IOP lanes for a proc
 */
enum IopLanesPerProc
{
    IOP_LANES_PER_PROC_24X = 24,// 24 Lanes per proc
    IOP_LANES_PER_PROC_32X = 32 // 32 Lanes per proc
};

/**
 *  @brief Struct for PCIE lane properties within IOP configuration table
 */
struct LaneSet
{
    uint8_t width; // Width of each PCIE lane set (0, 8, or 16)
    uint8_t dsmp;  // Whether dSMP is enabled (0=disabled, 1=enabled)
};

/**
 *  @brief Max possible IOPs per processor; invarient across all POWER8
 *      processors
 */
static const size_t MAX_IOPS_PER_PROC = 2;

/**
 *  @brief Lane groups per IOP; invarient across all POWER8 processors
 */
static const size_t MAX_LANE_GROUPS_PER_IOP = 2;

/**
 *  @brief Struct for each row in PCIE IOP configuration table.
 *      Used by code to compute the IOP config and PHBs active mask.
 */
struct laneConfigRow
{
    // Grouping of lanes under one IOP
    LaneSet laneSet[MAX_IOPS_PER_PROC][MAX_LANE_GROUPS_PER_IOP];

    // IOP config value from PCIE IOP configuration table
    uint8_t laneConfig;

    // PHB active mask (see PhbActiveMask enum)
    // PHB0 = 0x80
    // PHB1 = 0x40
    // PHB1 = 0x20
    uint8_t phbActive;
};

/**
 *  @brief Enum indicating lane width (units = "number of lanes")
 */
enum LaneWidth
{
    LANE_WIDTH_NC  = 0,
    LANE_WIDTH_8X  = 8,
    LANE_WIDTH_16X = 16
};

/**
 *  @brief Enum indicating whether lane set has DSMP Capability
 */
enum DsmpCapability
{
    DSMP_DISABLE = 0,
    DSMP_ENABLE  = 1
};

/**
 *  @brief Enumeration of lane mask values
 */
enum LaneMask
{
    LANE_MASK_X16     = 0xFFFF,
    LANE_MASK_X8_GRP0 = 0xFF00,
    LANE_MASK_X8_GRP1 = 0x00FF,
};

/**
 *  @brief Enum giving bitmask values for enabled PHBs
 */
enum PhbActiveMask
{
    PHB_MASK_NA = 0x00, ///< Sentinel mask (loop terminations)
    PHB0_MASK   = 0x80, ///< PHB0 enabled
    PHB1_MASK   = 0x40, ///< PHB1 enabled
    PHB2_MASK   = 0x20, ///< PHB2 enabled
};

/**
 *  @brief  call_proc_attr_update
 *
 *           Stub to enable platforms to override attributes
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void * call_proc_attr_update( void * io_pArgs );

/**
 *  @brief  proc_a_x_pci_dmi_pll_initf
 *
 *           PLL init file for A, X, PCIe, DMI
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_a_x_pci_dmi_pll_initf( void    *io_pArgs );

/**
 *  @brief  proc_a_x_pci_dmi_pll_setup
 *
 *          Setup PLL for A, X, PCIe, DMI
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_a_x_pci_dmi_pll_setup( void    *io_pArgs );


/**
 *  @brief  proc_startclock_chiplets
 *
 *          Start clocks on A, X, PCIe chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_startclock_chiplets( void    *io_pArgs );

/**
 *  @brief  proc_chiplet_scominit
 *
 *          Apply scom inits to chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_chiplet_scominit( void    *io_pArgs );

/**
 *  @brief   proc_xbus_scominit
 *
 *           Apply scom inits to Xbus
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_xbus_scominit( void    *io_pArgs );

/**
 *  @brief   proc_abus_scominit
 *
 *           Apply scom inits to Abus
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_abus_scominit( void    *io_pArgs );

/**
 *  @brief   proc_pcie_scominit
 *
 *           Apply scom inits to PCIe chiplets
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_pcie_scominit( void    *io_pArgs );

/**
 *  @brief   proc_scomoverride_chiplets
 *
 *           Apply sequenced scom inits
 *
 *  param[in,out]   -   pointer to any arguments, usually NULL
 *
 *  return  any error logs to istep
 *
 */
void*    call_proc_scomoverride_chiplets( void    *io_pArgs );

/**
 *  @brief Setup the ATTR_CHIP_REGIONS_TO_ENABLE attribute for input proc.
 *
 *  @param[in] i_procTarget Processor target to customize data for.
 *
 *  @return Valid error handle otherwise NULL
 *
 */
errlHndl_t customizeChipRegions(TARGETING::Target* i_procTarget);

};   // end namespace

#endif

