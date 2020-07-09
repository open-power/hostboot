/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr_types.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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

///
/// @file  p10_io_pwr.H
/// @brief Structure definition of the IO power information
///
/// *HWP HWP Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner         : Prasad BG Ranganath <prasadbgr@in.ibm.com>
/// *Team                 : PM
/// *Consumed by          : XGPE
/// *Level                : 3
///

// EKB-Mirror-To: hostboot
#ifndef __P10_IO_PWR_TYPES_H__
#define __P10_IO_PWR_TYPES_H__


typedef enum
{
    OMI,
    AX,
    AXO_Base,
    OC,
    NV,
    G5,
    G4,
    G3,
    G2,
    G1,
    DL0,
    DL1,
    DL2,
    NUM_OF_IO_TYPES,
} io_sub_types_t;

typedef enum
{
    OMI_25G_0,
    OMI_25G_1,
    OMI_32G,
    AX_25G_0,
    AX_25G_1,
    AX_32G,
    OC_25G_0,
    OC_25G_1,
    OC_32G,
    AXO_BASE_25G_0,
    AXO_BASE_25G_1,
    AXO_BASE_32G,
    G5_25G,
    G5_32G,
    G4_25G,
    G4_32G,
    G3_25G,
    G3_32G,
    G2_25G,
    G2_32G,
    G1_25G,
    G1_32G,
    NUM_OF_IO_TYPES_SPEED,
} io_sub_type_speed_t;

typedef enum
{
    S_25G,
    S_32G
} io_speed_t;

char io_types_strings[][9] =
{
    "OMI",
    "AX",
    "AXO-Base",
    "OC",
    "NV",
    "PCIE",
    "NA",
};

static const uint16_t io_pcie_supported_gens[]    = {1, 2, 3, 4, 5};
static const uint16_t io_pcie_supported_widths[]  = {4, 8, 16};


typedef enum
{
    PWR_OMI,
    PWR_AX,
    PWR_OC,
    PWR_AXO_Base,
    PWR_PCIE_DL,
    PWR_PCIE_IO,
    NUM_OF_IO_PWR_TYPES,
} io_pwr_types_t;


typedef enum
{
    FULL        = 0,
    HALF        = 1,
    QTR         = 2,
    SINGLE      = 3,
    DISABLED    = 4,
    PGATED      = 5,
    NUM_OF_IO_PWRS,
} io_link_powers_t;

typedef enum
{
    NONE,
    EMO01,
    EMO23,
    EMO45,
    EMO67,
    PAU0,
    Reserved1,
    Reserved2,
    PAU3,
    PAU4,
    PAU5,
    PAU6,
    PAU7,
    PEC0,
    PEC1,
    NUM_IO_CNTRLS,
} io_controllers;

typedef enum
{
    MC00_OMI0,
    MC00_OMI1,
    MC01_OMI0,
    MC01_OMI1,
    MC10_OMI0,
    MC10_OMI1,
    MC11_OMI0,
    MC11_OMI1,
    MC20_OMI0,
    MC20_OMI1,
    MC21_OMI0,
    MC21_OMI1,
    MC30_OMI0,
    MC30_OMI1,
    MC31_OMI0,
    MC31_OMI1,
    PCI0_0,
    PCI0_1,
    PCI0_2,
    PCI1_0,
    PCI1_1,
    PCI1_2,
    OPT0_AX0,
    OPT0_AX1,
    OPT1_AX0,
    OPT1_AX1,
    OPT2_AX0,
    OPT2_AX1,
    OPT3_AX0,
    OPT3_AX1,
    OPT4_AX0,
    OPT4_AX1,
    OPT5_AX0,
    OPT5_AX1,
    OPT6_AX0,
    OPT6_AX1,
    OPT7_AX0,
    OPT7_AX1,
    OPT0_O0,
    OPT0_O1,
    OPT3_O0,
    OPT3_O1,
    OPT4_O0,
    OPT4_O1,
    OPT5_O0,
    OPT5_O1,
    OPT6_O0,
    OPT6_O1,
    OPT7_O0,
    OPT7_O1,
    NUMBER_OF_IO_LINKS,
} link_controllers;


typedef struct
{
    io_pwr_types_t  type;                       // IO power type
    io_sub_types_t  subtype;                    // IO power subtype (PCIE gen; DL type)
    uint8_t         speed;                      // Speed of the lanes (25, 32)
    uint16_t        vdn_mv;                     // VDN voltage
    uint8_t         ac_lanes;                   // Number of AC lanes
    uint16_t        power_mw[NUM_OF_IO_PWRS];   // Total IO power types that comprise a link type
    uint16_t        max_min_delta;              // Maximum to minimum
    uint16_t        plsf_raw;                   // Per Link Scaling Factor
    uint8_t         plsf;                       // Per Link Scaling Factor - encoded
    uint8_t         half_weight;                // Weight for half width mode for APCR (1/16th)
    uint8_t         qtr_weight;                 // Weight for quarter width mode for APCR (1/16th)
} io_link_powers_data_t;


typedef struct
{
    uint32_t io_magic;
    uint32_t io_pwr_gated_cntrlrs;
    uint64_t io_disable_links;
} io_static_lnks_cntrls;



typedef struct
{
    uint32_t io_magic;
    uint16_t  sub_type;
    uint16_t base_power_mw;
#if 0
    uint32_t ct_address;  // Activity Proxy Control Address
    uint32_t sm_address;  // Activity Proxy Sample Address
    uint32_t ov_address;  // Activity Proxy Override Address
    uint32_t st_address;  // Activity Proxy Status Address
#endif
} link_entry_t;

typedef struct
{
    uint32_t io_magic;
    uint16_t  sub_type;
    uint16_t base_power_mw;  // only applies to A/X and OC links
#if 0
    uint32_t ct_address;  // Activity Proxy Control Address
    uint32_t sm_address;  // Activity Proxy Sample Address
    uint32_t ov_address;  // Activity Proxy Override Address
    uint32_t st_address;  // Activity Proxy Status Address
#endif
} controller_entry_t;



#endif  // __P10_IO_PWR_H__
