/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2025                        */
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
#ifndef __P10_IO_PWR_H__
#define __P10_IO_PWR_H__
#include <p10_io_pwr_types.H>

static char io_powr_sheet_version_str[64] = "P11_Link_Power_v7_DLPwr_v3.xlsx";

static io_link_powers_data_t link_powers[] =
{
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            2957,                   // Full Width  mw
            2086,                   // 1/2 Width  mw
            1950,                   // 1/4 Width  mw
            1814,                   // 1Lane  mw
            899,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2058,                       // Max to Min  mw
        596,                        // PLSF  mw
        0x98,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            3376,                   // Full Width  mw
            2379,                   // 1/2 Width  mw
            2210,                   // 1/4 Width  mw
            2040,                   // 1Lane  mw
            1019,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2357,                       // Max to Min  mw
        682,                        // PLSF  mw
        0xAE,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_38G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4078,                   // Full Width  mw
            2882,                   // 1/2 Width  mw
            2679,                   // 1/4 Width  mw
            2475,                   // 1Lane  mw
            1227,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2851,                       // Max to Min  mw
        825,                        // PLSF  mw
        0xD3,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            3419,                   // Full Width  mw
            2347,                   // 1/2 Width  mw
            2211,                   // 1/4 Width  mw
            2074,                   // 1Lane  mw
            915,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2503,                       // Max to Min  mw
        725,                        // PLSF  mw
        0xB9,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            3891,                   // Full Width  mw
            2667,                   // 1/2 Width  mw
            2497,                   // 1/4 Width  mw
            2328,                   // 1Lane  mw
            1035,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2855,                       // Max to Min  mw
        827,                        // PLSF  mw
        0xD3,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_38G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4696,                   // Full Width  mw
            3227,                   // 1/2 Width  mw
            3024,                   // 1/4 Width  mw
            2821,                   // 1Lane  mw
            1244,                   // Disable  mw
            20,                     // Pgated  mw
        },
        3452,                       // Max to Min  mw
        1000,                       // PLSF  mw
        0xFF,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        18,                         // #AC lanes
        {
            // power_mw
            3382,                   // Full Width  mw
            2342,                   // 1/2 Width  mw
            848,                    // 1/4 Width  mw
            1558,                   // 1Lane  mw
            1250,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2132,                       // Max to Min  mw
        617,                        // PLSF  mw
        0x9E,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        18,                         // #AC lanes
        {
            // power_mw
            3871,                   // Full Width  mw
            2657,                   // 1/2 Width  mw
            1462,                   // 1/4 Width  mw
            1718,                   // 1Lane  mw
            1326,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2544,                       // Max to Min  mw
        737,                        // PLSF  mw
        0xBC,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x1,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        18,                         // #AC lanes
        {
            // power_mw
            3892,                   // Full Width  mw
            2626,                   // 1/2 Width  mw
            1032,                   // 1/4 Width  mw
            1743,                   // 1Lane  mw
            1267,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2625,                       // Max to Min  mw
        760,                        // PLSF  mw
        0xC2,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        18,                         // #AC lanes
        {
            // power_mw
            4448,                   // Full Width  mw
            2976,                   // 1/2 Width  mw
            1666,                   // 1/4 Width  mw
            1923,                   // 1Lane  mw
            1344,                   // Disable  mw
            20,                     // Pgated  mw
        },
        3104,                       // Max to Min  mw
        899,                        // PLSF  mw
        0xE5,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x2,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            3536,                   // Full Width  mw
            2588,                   // 1/2 Width  mw
            2382,                   // 1/4 Width  mw
            2176,                   // 1Lane  mw
            1250,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2286,                       // Max to Min  mw
        662,                        // PLSF  mw
        0xA9,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x7,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4119,                   // Full Width  mw
            3012,                   // 1/2 Width  mw
            2755,                   // 1/4 Width  mw
            2499,                   // 1Lane  mw
            1449,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2670,                       // Max to Min  mw
        773,                        // PLSF  mw
        0xC5,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x7,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            3996,                   // Full Width  mw
            2848,                   // 1/2 Width  mw
            2642,                   // 1/4 Width  mw
            2435,                   // 1Lane  mw
            1267,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2728,                       // Max to Min  mw
        790,                        // PLSF  mw
        0xCA,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4639,                   // Full Width  mw
            3302,                   // 1/2 Width  mw
            3046,                   // 1/4 Width  mw
            2790,                   // 1Lane  mw
            1466,                   // Disable  mw
            20,                     // Pgated  mw
        },
        3173,                       // Max to Min  mw
        919,                        // PLSF  mw
        0xEA,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x7,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            829,                    // Full Width  mw
            705,                    // 1/2 Width  mw
            580,                    // 1/4 Width  mw
            455,                    // 1Lane  mw
            455,                    // Disable  mw
            20,                     // Pgated  mw
        },
        374,                        // Max to Min  mw
        108,                        // PLSF  mw
        0x1C,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            991,                    // Full Width  mw
            836,                    // 1/2 Width  mw
            681,                    // 1/4 Width  mw
            526,                    // 1Lane  mw
            526,                    // Disable  mw
            20,                     // Pgated  mw
        },
        464,                        // Max to Min  mw
        134,                        // PLSF  mw
        0x22,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            829,                    // Full Width  mw
            705,                    // 1/2 Width  mw
            580,                    // 1/4 Width  mw
            455,                    // 1Lane  mw
            455,                    // Disable  mw
            20,                     // Pgated  mw
        },
        374,                        // Max to Min  mw
        108,                        // PLSF  mw
        0x1C,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            991,                    // Full Width  mw
            836,                    // 1/2 Width  mw
            681,                    // 1/4 Width  mw
            526,                    // 1Lane  mw
            526,                    // Disable  mw
            20,                     // Pgated  mw
        },
        464,                        // Max to Min  mw
        134,                        // PLSF  mw
        0x22,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G5,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        8,                          // #AC lanes
        {
            // power_mw
            4925,                   // Full Width  mw
            4925,                   // 1/2 Width  mw
            3202,                   // 1/4 Width  mw
            1564,                   // 1Lane  mw
            1087,                   // Disable  mw
            122,                    // Pgated  mw
        },
        3838,                       // Max to Min  mw
        1111,                       // PLSF  mw
        0x0,                        // PSLF encode
        0xF,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G4,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            5818,                   // Full Width  mw
            3633,                   // 1/2 Width  mw
            2462,                   // 1/4 Width  mw
            1535,                   // 1Lane  mw
            1087,                   // Disable  mw
            122,                    // Pgated  mw
        },
        4731,                       // Max to Min  mw
        1370,                       // PLSF  mw
        0x0,                        // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G3,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4800,                   // Full Width  mw
            3295,                   // 1/2 Width  mw
            2298,                   // 1/4 Width  mw
            1620,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        3634,                       // Max to Min  mw
        1052,                       // PLSF  mw
        0x0,                        // PSLF encode
        0x9,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G2,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4477,                   // Full Width  mw
            2920,                   // 1/2 Width  mw
            2104,                   // 1/4 Width  mw
            1606,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        3311,                       // Max to Min  mw
        959,                        // PLSF  mw
        0xF5,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G1,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4110,                   // Full Width  mw
            2722,                   // 1/2 Width  mw
            1998,                   // 1/4 Width  mw
            1591,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        2944,                       // Max to Min  mw
        852,                        // PLSF  mw
        0xD9,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G5,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        8,                          // #AC lanes
        {
            // power_mw
            4925,                   // Full Width  mw
            4925,                   // 1/2 Width  mw
            3202,                   // 1/4 Width  mw
            1564,                   // 1Lane  mw
            1087,                   // Disable  mw
            122,                    // Pgated  mw
        },
        3838,                       // Max to Min  mw
        1111,                       // PLSF  mw
        0x0,                        // PSLF encode
        0xF,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G4,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            5818,                   // Full Width  mw
            3633,                   // 1/2 Width  mw
            2462,                   // 1/4 Width  mw
            1535,                   // 1Lane  mw
            1087,                   // Disable  mw
            122,                    // Pgated  mw
        },
        4731,                       // Max to Min  mw
        1370,                       // PLSF  mw
        0x0,                        // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G3,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4800,                   // Full Width  mw
            3295,                   // 1/2 Width  mw
            2298,                   // 1/4 Width  mw
            1620,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        3634,                       // Max to Min  mw
        1052,                       // PLSF  mw
        0x0,                        // PSLF encode
        0x9,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G2,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4477,                   // Full Width  mw
            2920,                   // 1/2 Width  mw
            2104,                   // 1/4 Width  mw
            1606,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        3311,                       // Max to Min  mw
        959,                        // PLSF  mw
        0xF5,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,                // IO Power Type
        G1,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mw
            4110,                   // Full Width  mw
            2722,                   // 1/2 Width  mw
            1998,                   // 1/4 Width  mw
            1591,                   // 1Lane  mw
            1166,                   // Disable  mw
            201,                    // Pgated  mw
        },
        2944,                       // Max to Min  mw
        852,                        // PLSF  mw
        0xD9,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
};
#endif
