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
    OMI_25G_VIO_PT_9V,
    OMI_32G_VIO_PT_9V,
    OMI_25G_VIO_1V,
    OMI_32G_VIO_1V,
    AX_25G_VIO_PT_9V,
    AX_32G_VIO_PT_9V,
    AX_25G_VIO_1V,
    AX_32G_VIO_1V,
    OC_25G_VIO_PT_9V,
    OC_32G_VIO_PT_9V,
    OC_25G_VIO_1V,
    OC_32G_VIO_1V,
    AX_BASE_25G_VIO_PT_9V,
    AX_BASE_32G_VIO_PT_9V,
    AX_BASE_25G_VIO_1V,
    AX_BASE_32G_VIO_1V,
    G5_32G_VIO_PT_9V,
    G4_32G_VIO_PT_9V,
    G3_32G_VIO_PT_9V,
    G2_32G_VIO_PT_9V,
    G1_32G_VIO_PT_9V,
    G5_32G_VIO_1V,
    G4_32G_VIO_1V,
    G3_32G_VIO_1V,
    G2_32G_VIO_1V,
    G1_32G_VIO_1V,
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
    NONE,      //0
    EMO01,     //1
    EMO23,     //2
    EMO45,     //3
    EMO67,     //4
    PAU0,      //5
    Reserved1, //6
    Reserved2, //7
    PAU3,      //8
    PAU4,      //9
    PAU5,      //10
    PAU6,      //11
    PAU7,      //12
    PEC0,      //13
    PEC1,      //14
    NUM_IO_CNTRLS,  //15
} io_controllers;

typedef enum
{
    MC00_OMI0, //0
    MC00_OMI1, //1
    MC01_OMI0, //2
    MC01_OMI1, //3
    MC10_OMI0, //4
    MC10_OMI1, //5
    MC11_OMI0, //6
    MC11_OMI1, //7
    MC20_OMI0, //8
    MC20_OMI1, //9
    MC21_OMI0, //10
    MC21_OMI1, //11
    MC30_OMI0, //12
    MC30_OMI1, //13
    MC31_OMI0, //14
    MC31_OMI1, //15
    PCI0_0,    //16
    PCI0_1,    //17
    PCI0_2,    //18
    PCI1_0,    //19
    PCI1_1,    //20
    PCI1_2,    //21
    OPT0_AX0,  //22
    OPT0_AX1,  //23
    OPT1_AX0,  //24
    OPT1_AX1,  //25
    OPT2_AX0,  //26
    OPT2_AX1,  //27
    OPT3_AX0,  //28
    OPT3_AX1,  //29
    OPT4_AX0,  //30
    OPT4_AX1,  //31
    OPT5_AX0,  //32
    OPT5_AX1,  //33
    OPT6_AX0,  //34
    OPT6_AX1,  //35
    OPT7_AX0,  //36
    OPT7_AX1,  //37
    OPT0_O0,   //38
    OPT0_O1,   //39
    OPT1_O0,   //40
    OPT1_O1,   //41
    OPT2_O0,   //42
    OPT2_O1,   //43
    OPT3_O0,   //44
    OPT3_O1,   //45
    OPT4_O0,   //46
    OPT4_O1,   //47
    OPT5_O0,   //48
    OPT5_O1,   //49
    OPT6_O0,   //50
    OPT6_O1,   //51
    OPT7_O0,   //52
    OPT7_O1,   //53
    NUMBER_OF_IO_LINKS, //54
} link_controllers;


typedef struct
{
    io_pwr_types_t  type;                       // IO power type
    io_sub_types_t  subtype;                    // IO power subtype (PCIE gen; DL type)
    uint8_t         speed;                      // Speed of the lanes (25, 32)
    uint16_t        vio_mv;                     // VIO voltage
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
    uint64_t io_active_links;
} io_static_lnks_cntrls;



typedef struct
{
//    uint32_t io_magic;
    uint32_t  sub_type;
    uint32_t base_power_mw;
#if 0
    uint32_t ct_address;  // Activity Proxy Control Address
    uint32_t sm_address;  // Activity Proxy Sample Address
    uint32_t ov_address;  // Activity Proxy Override Address
    uint32_t st_address;  // Activity Proxy Status Address
#endif
} link_entry_t;

typedef struct
{
//   uint32_t io_magic;
    uint32_t  sub_type;
    uint32_t base_power_mw;  // only applies to A/X and OC links
#if 0
    uint32_t ct_address;  // Activity Proxy Control Address
    uint32_t sm_address;  // Activity Proxy Sample Address
    uint32_t ov_address;  // Activity Proxy Override Address
    uint32_t st_address;  // Activity Proxy Status Address
#endif
} controller_entry_t;



#endif  // __P10_IO_PWR_H__
