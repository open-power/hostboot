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
            // power_mw
            2636,                   // Full Width  mw
            1800,                   // 1/2 Width  mw
            1698,                   // 1/4 Width  mw
            1596,                   // 1Lane  mw
            687,                    // Disable  mw
            20,                     // Pgated  mw
        },
        1948,                       // Max to Min  mw
        593,                        // PLSF  mw
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
            // power_mw
            2998,                   // Full Width  mw
            2044,                   // 1/2 Width  mw
            1917,                   // 1/4 Width  mw
            1791,                   // 1Lane  mw
            777,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2221,                       // Max to Min  mw
        675,                        // PLSF  mw
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
            // power_mw
            3618,                   // Full Width  mw
            2473,                   // 1/2 Width  mw
            2321,                   // 1/4 Width  mw
            2169,                   // 1Lane  mw
            933,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2685,                       // Max to Min  mw
        817,                        // PLSF  mw
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
            // power_mw
            3098,                   // Full Width  mw
            2060,                   // 1/2 Width  mw
            1959,                   // 1/4 Width  mw
            1857,                   // 1Lane  mw
            704,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2394,                       // Max to Min  mw
        728,                        // PLSF  mw
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
            // power_mw
            3513,                   // Full Width  mw
            2332,                   // 1/2 Width  mw
            2205,                   // 1/4 Width  mw
            2078,                   // 1Lane  mw
            794,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2719,                       // Max to Min  mw
        827,                        // PLSF  mw
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
            // power_mw
            4236,                   // Full Width  mw
            2818,                   // 1/2 Width  mw
            2666,                   // 1/4 Width  mw
            2514,                   // 1Lane  mw
            950,                    // Disable  mw
            20,                     // Pgated  mw
        },
        3286,                       // Max to Min  mw
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
            2004,                   // Full Width  mw
            1173,                   // 1/2 Width  mw
            803,                    // 1/4 Width  mw
            803,                    // 1Lane  mw
            951,                    // Disable  mw
            20,                     // Pgated  mw
        },
        1053,                       // Max to Min  mw
        320,                        // PLSF  mw
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
            // power_mw
            2282,                   // Full Width  mw
            1328,                   // 1/2 Width  mw
            904,                    // 1/4 Width  mw
            904,                    // 1Lane  mw
            1008,                   // Disable  mw
            20,                     // Pgated  mw
        },
        1273,                       // Max to Min  mw
        387,                        // PLSF  mw
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
            // power_mw
            2513,                   // Full Width  mw
            1457,                   // 1/2 Width  mw
            988,                    // 1/4 Width  mw
            988,                    // 1Lane  mw
            968,                    // Disable  mw
            20,                     // Pgated  mw
        },
        1545,                       // Max to Min  mw
        470,                        // PLSF  mw
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
            // power_mw
            2859,                   // Full Width  mw
            1647,                   // 1/2 Width  mw
            1109,                   // 1/4 Width  mw
            1109,                   // 1Lane  mw
            1025,                   // Disable  mw
            20,                     // Pgated  mw
        },
        1833,                       // Max to Min  mw
        558,                        // PLSF  mw
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
            // power_mw
            3067,                   // Full Width  mw
            2174,                   // 1/2 Width  mw
            2020,                   // 1/4 Width  mw
            1866,                   // 1Lane  mw
            951,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2116,                       // Max to Min  mw
        644,                        // PLSF  mw
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
            // power_mw
            3559,                   // Full Width  mw
            2520,                   // 1/2 Width  mw
            2328,                   // 1/4 Width  mw
            2136,                   // 1Lane  mw
            1099,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2459,                       // Max to Min  mw
        748,                        // PLSF  mw
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
            // power_mw
            3527,                   // Full Width  mw
            2434,                   // 1/2 Width  mw
            2280,                   // 1/4 Width  mw
            2125,                   // 1Lane  mw
            968,                    // Disable  mw
            20,                     // Pgated  mw
        },
        2559,                       // Max to Min  mw
        778,                        // PLSF  mw
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
            // power_mw
            4079,                   // Full Width  mw
            2810,                   // 1/2 Width  mw
            2618,                   // 1/4 Width  mw
            2427,                   // 1Lane  mw
            1116,                   // Disable  mw
            20,                     // Pgated  mw
        },
        2962,                       // Max to Min  mw
        901,                        // PLSF  mw
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
            // power_mw
            620,                    // Full Width  mw
            527,                    // 1/2 Width  mw
            434,                    // 1/4 Width  mw
            340,                    // 1Lane  mw
            340,                    // Disable  mw
            20,                     // Pgated  mw
        },
        279,                        // Max to Min  mw
        85,                         // PLSF  mw
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
            // power_mw
            741,                    // Full Width  mw
            625,                    // 1/2 Width  mw
            509,                    // 1/4 Width  mw
            393,                    // 1Lane  mw
            393,                    // Disable  mw
            20,                     // Pgated  mw
        },
        347,                        // Max to Min  mw
        105,                        // PLSF  mw
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
            // power_mw
            620,                    // Full Width  mw
            527,                    // 1/2 Width  mw
            434,                    // 1/4 Width  mw
            340,                    // 1Lane  mw
            340,                    // Disable  mw
            20,                     // Pgated  mw
        },
        279,                        // Max to Min  mw
        85,                         // PLSF  mw
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
            // power_mw
            741,                    // Full Width  mw
            625,                    // 1/2 Width  mw
            509,                    // 1/4 Width  mw
            393,                    // 1Lane  mw
            393,                    // Disable  mw
            20,                     // Pgated  mw
        },
        347,                        // Max to Min  mw
        105,                        // PLSF  mw
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
            // power_mw
            4392,                   // Full Width  mw
            4392,                   // 1/2 Width  mw
            2749,                   // 1/4 Width  mw
            1231,                   // 1Lane  mw
            843,                    // Disable  mw
            122,                    // Pgated  mw
        },
        3548,                       // Max to Min  mw
        1079,                       // PLSF  mw
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
            5182,                   // Full Width  mw
            3132,                   // 1/2 Width  mw
            2049,                   // 1/4 Width  mw
            1210,                   // 1Lane  mw
            843,                    // Disable  mw
            122,                    // Pgated  mw
        },
        4338,                       // Max to Min  mw
        1320,                       // PLSF  mw
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
            4203,                   // Full Width  mw
            2821,                   // 1/2 Width  mw
            1907,                   // 1/4 Width  mw
            1302,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        3280,                       // Max to Min  mw
        998,                        // PLSF  mw
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
            // power_mw
            3905,                   // Full Width  mw
            2462,                   // 1/2 Width  mw
            1722,                   // 1/4 Width  mw
            1291,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        2982,                       // Max to Min  mw
        907,                        // PLSF  mw
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
            // power_mw
            3562,                   // Full Width  mw
            2279,                   // 1/2 Width  mw
            1626,                   // 1/4 Width  mw
            1280,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        2639,                       // Max to Min  mw
        803,                        // PLSF  mw
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
            // power_mw
            4392,                   // Full Width  mw
            4392,                   // 1/2 Width  mw
            2749,                   // 1/4 Width  mw
            1231,                   // 1Lane  mw
            843,                    // Disable  mw
            122,                    // Pgated  mw
        },
        3548,                       // Max to Min  mw
        1079,                       // PLSF  mw
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
            5182,                   // Full Width  mw
            3132,                   // 1/2 Width  mw
            2049,                   // 1/4 Width  mw
            1210,                   // 1Lane  mw
            843,                    // Disable  mw
            122,                    // Pgated  mw
        },
        4338,                       // Max to Min  mw
        1320,                       // PLSF  mw
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
            4203,                   // Full Width  mw
            2821,                   // 1/2 Width  mw
            1907,                   // 1/4 Width  mw
            1302,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        3280,                       // Max to Min  mw
        998,                        // PLSF  mw
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
            // power_mw
            3905,                   // Full Width  mw
            2462,                   // 1/2 Width  mw
            1722,                   // 1/4 Width  mw
            1291,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        2982,                       // Max to Min  mw
        907,                        // PLSF  mw
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
            // power_mw
            3562,                   // Full Width  mw
            2279,                   // 1/2 Width  mw
            1626,                   // 1/4 Width  mw
            1280,                   // 1Lane  mw
            923,                    // Disable  mw
            201,                    // Pgated  mw
        },
        2639,                       // Max to Min  mw
        803,                        // PLSF  mw
        0xCD,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },

};

#endif
