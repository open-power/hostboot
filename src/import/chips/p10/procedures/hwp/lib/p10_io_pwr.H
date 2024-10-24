/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2024                        */
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
//File:P11_Link_Power_0.9vio_v4.xlsx
//
#ifndef __P10_IO_PWR_H__
#define __P10_IO_PWR_H__
#include <p10_io_pwr_types.H>

//static uint64_t io_powr_sheet_version = 0x550B56494f5604;//P11VIOV04
static char io_powr_sheet_version_str[64] = "P11_Link_Power_0.9vio_v4.xlsx";

static io_link_powers_data_t link_powers[] =
{
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            2636,                   // Full Width  mv
            1800,                   // 1/2 Width  mv
            1698,                   // 1/4 Width  mv
            1596,                   // 1Lane  mv
            687,                    // Disable  mv
            20,                     // Pgated  mv
        },
        1948,                       // Max to Min  mv
        593,                        // PLSF  mv
        0x97,                       // PSLF encode
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
            // power_mv
            2998,                   // Full Width  mv
            2044,                   // 1/2 Width  mv
            1917,                   // 1/4 Width  mv
            1791,                   // 1Lane  mv
            777,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2221,                       // Max to Min  mv
        675,                        // PLSF  mv
        0xAC,                       // PSLF encode
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
            // power_mv
            3618,                   // Full Width  mv
            2473,                   // 1/2 Width  mv
            2321,                   // 1/4 Width  mv
            2169,                   // 1Lane  mv
            933,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2685,                       // Max to Min  mv
        817,                        // PLSF  mv
        0xD0,                       // PSLF encode
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
            // power_mv
            3098,                   // Full Width  mv
            2060,                   // 1/2 Width  mv
            1959,                   // 1/4 Width  mv
            1857,                   // 1Lane  mv
            704,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2394,                       // Max to Min  mv
        728,                        // PLSF  mv
        0xBA,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3513,                   // Full Width  mv
            2332,                   // 1/2 Width  mv
            2205,                   // 1/4 Width  mv
            2078,                   // 1Lane  mv
            794,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2719,                       // Max to Min  mv
        827,                        // PLSF  mv
        0xD3,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_38G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mv
            4236,                   // Full Width  mv
            2818,                   // 1/2 Width  mv
            2666,                   // 1/4 Width  mv
            2514,                   // 1Lane  mv
            950,                    // Disable  mv
            20,                     // Pgated  mv
        },
        3286,                       // Max to Min  mv
        1000,                       // PLSF  mv
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
            // power_mv
            2004,                   // Full Width  mv
            1173,                   // 1/2 Width  mv
            803,                    // 1/4 Width  mv
            803,                    // 1Lane  mv
            951,                    // Disable  mv
            20,                     // Pgated  mv
        },
        1053,                       // Max to Min  mv
        320,                        // PLSF  mv
        0x52,                       // PSLF encode
        0x3,                        // 1/2 Width
        0x0,               // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2282,                   // Full Width  mv
            1328,                   // 1/2 Width  mv
            904,                    // 1/4 Width  mv
            904,                    // 1Lane  mv
            1008,                   // Disable  mv
            20,                     // Pgated  mv
        },
        1273,                       // Max to Min  mv
        387,                        // PLSF  mv
        0x63,                       // PSLF encode
        0x4,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2513,                   // Full Width  mv
            1457,                   // 1/2 Width  mv
            988,                    // 1/4 Width  mv
            988,                    // 1Lane  mv
            968,                    // Disable  mv
            20,                     // Pgated  mv
        },
        1545,                       // Max to Min  mv
        470,                        // PLSF  mv
        0x78,                       // PSLF encode
        0x5,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2859,                   // Full Width  mv
            1647,                   // 1/2 Width  mv
            1109,                   // 1/4 Width  mv
            1109,                   // 1Lane  mv
            1025,                   // Disable  mv
            20,                     // Pgated  mv
        },
        1833,                       // Max to Min  mv
        558,                        // PLSF  mv
        0x8E,                       // PSLF encode
        0x5,                        // 1/2 Width
        0x1,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3067,                   // Full Width  mv
            2174,                   // 1/2 Width  mv
            2020,                   // 1/4 Width  mv
            1866,                   // 1Lane  mv
            951,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2116,                       // Max to Min  mv
        644,                        // PLSF  mv
        0xA4,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3559,                   // Full Width  mv
            2520,                   // 1/2 Width  mv
            2328,                   // 1/4 Width  mv
            2136,                   // 1Lane  mv
            1099,                   // Disable  mv
            20,                     // Pgated  mv
        },
        2459,                       // Max to Min  mv
        748,                        // PLSF  mv
        0xBF,                       // PSLF encode
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
            // power_mv
            3527,                   // Full Width  mv
            2434,                   // 1/2 Width  mv
            2280,                   // 1/4 Width  mv
            2125,                   // 1Lane  mv
            968,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2559,                       // Max to Min  mv
        778,                        // PLSF  mv
        0xC7,                       // PSLF encode
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
            // power_mv
            4079,                   // Full Width  mv
            2810,                   // 1/2 Width  mv
            2618,                   // 1/4 Width  mv
            2427,                   // 1Lane  mv
            1116,                   // Disable  mv
            20,                     // Pgated  mv
        },
        2962,                       // Max to Min  mv
        901,                        // PLSF  mv
        0xE6,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_25G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            620,                    // Full Width  mv
            527,                    // 1/2 Width  mv
            434,                    // 1/4 Width  mv
            340,                    // 1Lane  mv
            340,                    // Disable  mv
            20,                     // Pgated  mv
        },
        279,                        // Max to Min  mv
        85,                         // PLSF  mv
        0x16,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_32G,                      // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            741,                    // Full Width  mv
            625,                    // 1/2 Width  mv
            509,                    // 1/4 Width  mv
            393,                    // 1Lane  mv
            393,                    // Disable  mv
            20,                     // Pgated  mv
        },
        347,                        // Max to Min  mv
        105,                        // PLSF  mv
        0x1B,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_25G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mv
            620,                    // Full Width  mv
            527,                    // 1/2 Width  mv
            434,                    // 1/4 Width  mv
            340,                    // 1Lane  mv
            340,                    // Disable  mv
            20,                     // Pgated  mv
        },
        279,                        // Max to Min  mv
        85,                         // PLSF  mv
        0x16,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_32G,                      // Speed
        1000,                       // VIO
        16,                         // #AC lanes
        {
            // power_mv
            741,                    // Full Width  mv
            625,                    // 1/2 Width  mv
            509,                    // 1/4 Width  mv
            393,                    // 1Lane  mv
            393,                    // Disable  mv
            20,                     // Pgated  mv
        },
        347,                        // Max to Min  mv
        105,                        // PLSF  mv
        0x1B,                       // PSLF encode
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
            // power_mv
            4392,                   // Full Width  mv
            4392,                   // 1/2 Width  mv
            2749,                   // 1/4 Width  mv
            1231,                   // 1Lane  mv
            843,                    // Disable  mv
            122,                    // Pgated  mv
        },
        3548,                       // Max to Min  mv
        1079,                       // PLSF  mv
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
            // power_mv
            5182,                   // Full Width  mv
            3132,                   // 1/2 Width  mv
            2049,                   // 1/4 Width  mv
            1210,                   // 1Lane  mv
            843,                    // Disable  mv
            122,                    // Pgated  mv
        },
        4338,                       // Max to Min  mv
        1320,                       // PLSF  mv
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
            // power_mv
            4203,                   // Full Width  mv
            2821,                   // 1/2 Width  mv
            1907,                   // 1/4 Width  mv
            1302,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        3280,                       // Max to Min  mv
        998,                        // PLSF  mv
        0xFF,                       // PSLF encode
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
            // power_mv
            3905,                   // Full Width  mv
            2462,                   // 1/2 Width  mv
            1722,                   // 1/4 Width  mv
            1291,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        2982,                       // Max to Min  mv
        907,                        // PLSF  mv
        0xE7,                       // PSLF encode
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
            // power_mv
            3562,                   // Full Width  mv
            2279,                   // 1/2 Width  mv
            1626,                   // 1/4 Width  mv
            1280,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        2639,                       // Max to Min  mv
        803,                        // PLSF  mv
        0xCD,                       // PSLF encode
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
            // power_mv
            4392,                   // Full Width  mv
            4392,                   // 1/2 Width  mv
            2749,                   // 1/4 Width  mv
            1231,                   // 1Lane  mv
            843,                    // Disable  mv
            122,                    // Pgated  mv
        },
        3548,                       // Max to Min  mv
        1079,                       // PLSF  mv
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
            // power_mv
            5182,                   // Full Width  mv
            3132,                   // 1/2 Width  mv
            2049,                   // 1/4 Width  mv
            1210,                   // 1Lane  mv
            843,                    // Disable  mv
            122,                    // Pgated  mv
        },
        4338,                       // Max to Min  mv
        1320,                       // PLSF  mv
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
            // power_mv
            4203,                   // Full Width  mv
            2821,                   // 1/2 Width  mv
            1907,                   // 1/4 Width  mv
            1302,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        3280,                       // Max to Min  mv
        998,                        // PLSF  mv
        0xFF,                       // PSLF encode
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
            // power_mv
            3905,                   // Full Width  mv
            2462,                   // 1/2 Width  mv
            1722,                   // 1/4 Width  mv
            1291,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        2982,                       // Max to Min  mv
        907,                        // PLSF  mv
        0xE7,                       // PSLF encode
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
            // power_mv
            3562,                   // Full Width  mv
            2279,                   // 1/2 Width  mv
            1626,                   // 1/4 Width  mv
            1280,                   // 1Lane  mv
            923,                    // Disable  mv
            201,                    // Pgated  mv
        },
        2639,                       // Max to Min  mv
        803,                        // PLSF  mv
        0xCD,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },

};

#endif
