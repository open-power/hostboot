/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr_types.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __P10_IO_PWR_H__
#define __P10_IO_PWR_H__


enum io_sub_types_t
{
    OMI,
    AX,
    OC,
    NV,
    G5,
    G4,
    G3,
    G2,
    G1,
    DL0,
    DL1,
    DL2
    NUM_OF_IO_TYPES,
};

static const io_types_strings[] =
{
    "OMI"
    "AX",
    "OC",
    "NV",
    "PCIE",
    "NA",
};

static const uint16_t io_pcie_supported_gens[]    = {1, 2, 3, 4, 5};
static const uint16_t io_pcie_supported_widths[]  = {4, 8, 16};


enum io_pwr_types_t
{
    PWR_OMI,
    PWR_AX,
    PWR_OC,
    PWR_PCIE_DL,
    PWR_PCIE_IO,
    NUM_OF_IO_PWR_TYPES,
};


enum io_link_powers_t
{
    FULL        = 0,
    HALF        = 1,
    QTR         = 2,
    SINGLE      = 3,
    DISABLED    = 4,
    NUM_OF_IO_PWRS,
};


typedef struct
{
    io_pwr_types_t  type;                       // IO power type
    io_sub_types_t  subtype;                    // IO power subtype (PCIE gen; DL type)
    uint8_t         speed;                      // Speed of the lanes (25, 32)
    uint16_t        vdn_mv;                     // VDN voltage
    uint8_t         ac_lanes;                   // Number of AC lanes
    uint16_t        power_mw[NUM_OF_IO_PWRS];   // Total IO power types that comprise a link type
    uint16_t        max_min_delta;              // Maximum to minimum
    uint8_t         plsf_raw;                   // Per Link Scaling Factor
    uint8_t         plsf;                       // Per Link Scaling Factor - encoded
    uint8_t         half_weight;                // Weight for half width mode for APCR (1/16th)
    uint8_t         qtr_weight;                 // Weight for quarter width mode for APCR (1/16th)
} io_link_powers_t;



#endif  // __P10_IO_PWR_H__
