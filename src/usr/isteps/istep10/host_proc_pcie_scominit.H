/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/host_proc_pcie_scominit.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
#ifndef __ISTEPS_HOST_PROC_PCIE_SCOMINIT_H
#define __ISTEPS_HOST_PROC_PCIE_SCOMINIT_H

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>

namespace   ISTEP_10
{

/**
 *  @brief Computes PCIE configuration attributes based on MRW values
 *
 *  @param i_pProcChipTarget: Proc chip to compute the PCIE Configuration
 *      attributes for.
 */
errlHndl_t computeProcPcieConfigAttrs(TARGETING::Target* i_pProcChipTarget);

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
    IOP_LANES_PER_PROC_48X = 48,// 48 Lanes per proc
};

/**
 *  @brief Struct for PCIE lane properties within IOP configuration tables
 */
struct LaneSet
{
    uint8_t width; // Width of each PCIE lane set (0, 4, 8, or 16)
};

/**
 *  @brief Lane groups per PEC
 */
static const size_t MAX_LANE_GROUPS_PER_PEC = 4;

/**
 *  @brief Max Number of PEC Targets expected
 *     per Processor target
 */
static const size_t NUM_PECS_PER_PROC = 2;

/**
 *  @brief Struct for each row in PCIE IOP configuration table.
 *      Used by code to compute the IOP config and PHBs active mask.
 */
struct laneConfigRow
{
    // Grouping of lanes under one IOP
    LaneSet laneSet[MAX_LANE_GROUPS_PER_PEC];

    // IOP config value from PCIE IOP configuration table
    uint8_t laneConfig;

    // PHB active mask (see PhbActiveMask enum)
    // PHB0 = 0x80
    // PHB1 = 0x40
    // PHB2 = 0x20
    // PHB3 = 0x10
    // PHB4 = 0x08
    // PHB5 = 0x04
    uint8_t phbActive;
    uint16_t phb_to_pcieMAC;
};

/**
 *  @brief Enum indicating lane width (units = "number of lanes")
 */
enum LaneWidth
{
    LANE_WIDTH_NC  = 0,
    LANE_WIDTH_4X  = 4,
    LANE_WIDTH_8X  = 8,
    LANE_WIDTH_16X = 16
};

/**
 *  @brief Enumeration of lane mask values
 */
enum LaneMask
{
    LANE_MASK_X16     = 0xFFFF,
    LANE_MASK_X8_GRP0 = 0xFF00,
    LANE_MASK_X8_GRP1 = 0x00FF,
    LANE_MASK_X4_GRP0 = 0x00F0,
    LANE_MASK_X4_GRP1 = 0x000F,
};

/**
 *  @brief Enumeration of PHB to PCI MAC mappings
 */
enum PhbToMAC
{
    PHB_X16_MAC_MAP      = 0x0000,
    PHB_X8_X8_MAC_MAP    = 0x0050,
    PHB_X8_X4_X4_MAC_MAP = 0x0090,
};

/**
 *  @brief Enum giving bitmask values for enabled PHBs
 */
enum PhbActiveMask
{
    PHB_MASK_NA  = 0x0000000000000000, ///< Sentinel mask (loop terminations)
    PHB0_MASK    = 0x8000000000000000, ///< PHB0 enabled
    PHB1_MASK    = 0x4000000000000000, ///< PHB1 enabled
    PHB2_MASK    = 0x2000000000000000, ///< PHB2 enabled
    PHB_ANY_MASK = PHB0_MASK | PHB1_MASK | PHB2_MASK, ///< Any PHB Enabled
};

};

#endif
