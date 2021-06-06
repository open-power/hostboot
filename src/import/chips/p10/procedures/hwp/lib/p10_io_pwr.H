/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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



static io_link_powers_data_t link_powers[] =
{
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                        // Speed
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
        677,                        // PLSF  mv
        0xAD,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                        // Speed
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
        771,                        // PLSF  mv
        0xC5,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                        // Speed
        1000,                          // VIO
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
        831,                        // PLSF  mv
        0xD4,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
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
        944,                        // PLSF  mv
        0xF1,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                        // Speed
        900,                        // VIO
        18,                         // #AC lanes
        {
            // power_mv
            1984,                   // Full Width  mv
            1155,                   // 1/2 Width  mv
            786,                    // 1/4 Width  mv
            786,                    // 1Lane  mv
            151,                    // Disable  mv
            20,                     // Pgated  mv
        },
        1832,                       // Max to Min  mv
        636,                        // PLSF  mv
        0xA2,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2258,                   // Full Width  mv
            1306,                   // 1/2 Width  mv
            883,                    // 1/4 Width  mv
            883,                    // 1Lane  mv
            169,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2089,                       // Max to Min  mv
        725,                        // PLSF  mv
        0xB9,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                        // Speed
        1000,                          // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2494,                   // Full Width  mv
            1439,                   // 1/2 Width  mv
            970,                    // 1/4 Width  mv
            970,                    // 1Lane  mv
            169,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2325,                       // Max to Min  mv
        807,                        // PLSF  mv
        0xCE,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        18,                         // #AC lanes
        {
            // power_mv
            2835,                   // Full Width  mv
            1625,                   // 1/2 Width  mv
            1087,                   // 1/4 Width  mv
            1087,                   // 1Lane  mv
            186,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2649,                       // Max to Min  mv
        920,                        // PLSF  mv
        0xEB,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            2880,                   // Full Width  mv
            2009,                   // 1/2 Width  mv
            1876,                   // 1/4 Width  mv
            1742,                   // 1Lane  mv
            831,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2049,                       // Max to Min  mv
        711,                        // PLSF  mv
        0xB6,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3335,                   // Full Width  mv
            2323,                   // 1/2 Width  mv
            2157,                   // 1/4 Width  mv
            1991,                   // 1Lane  mv
            960,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2375,                       // Max to Min  mv
        825,                        // PLSF  mv
        0xD2,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3340,                   // Full Width  mv
            2269,                   // 1/2 Width  mv
            2135,                   // 1/4 Width  mv
            2002,                   // 1Lane  mv
            848,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2491,                       // Max to Min  mv
        865,                        // PLSF  mv
        0xDD,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3855,                   // Full Width  mv
            2613,                   // 1/2 Width  mv
            2448,                   // 1/4 Width  mv
            2282,                   // 1Lane  mv
            977,                    // Disable  mv
            20,                     // Pgated  mv
        },
        2878,                       // Max to Min  mv
        1000,                       // PLSF  mv
        0xFF,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_25G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            537,                    // Full Width  mv
            456,                    // 1/2 Width  mv
            375,                    // 1/4 Width  mv
            294,                    // 1Lane  mv
            294,                    // Disable  mv
            20,                     // Pgated  mv
        },
        242,                        // Max to Min  mv
        84,                         // PLSF  mv
        0x15,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            641,                    // Full Width  mv
            541,                    // 1/2 Width  mv
            440,                    // 1/4 Width  mv
            340,                    // 1Lane  mv
            340,                    // Disable  mv
            20,                     // Pgated  mv
        },
        300,                        // Max to Min  mv
        104,                        // PLSF  mv
        0x1B,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_25G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            537,                    // Full Width  mv
            456,                    // 1/2 Width  mv
            375,                    // 1/4 Width  mv
            294,                    // 1Lane  mv
            294,                    // Disable  mv
            20,                     // Pgated  mv
        },
        242,                        // Max to Min  mv
        84,                         // PLSF  mv
        0x15,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,               // IO Power Type
        AXO_Base,                   // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            641,                    // Full Width  mv
            541,                    // 1/2 Width  mv
            440,                    // 1/4 Width  mv
            340,                    // 1Lane  mv
            340,                    // Disable  mv
            20,                     // Pgated  mv
        },
        300,                        // Max to Min  mv
        104,                        // PLSF  mv
        0x1B,                       // PSLF encode
        0xA,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        8,                          // #AC lanes
        {
            // power_mv
            4014,                   // Full Width  mv
            4014,                   // 1/2 Width  mv
            2560,                   // 1/4 Width  mv
            1198,                   // 1Lane  mv
            827,                    // Disable  mv
            105,                    // Pgated  mv
        },
        3186,                       // Max to Min  mv
        1107,                       // PLSF  mv
        0x0,                        // PSLF encode
        0xF,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            4738,                   // Full Width  mv
            2911,                   // 1/2 Width  mv
            1938,                   // 1/4 Width  mv
            1177,                   // 1Lane  mv
            827,                    // Disable  mv
            105,                    // Pgated  mv
        },
        3911,                       // Max to Min  mv
        1359,                       // PLSF  mv
        0x0,                        // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3876,                   // Full Width  mv
            2630,                   // 1/2 Width  mv
            1807,                   // 1/4 Width  mv
            1254,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2980,                       // Max to Min  mv
        1035,                       // PLSF  mv
        0x0,                        // PSLF encode
        0x9,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3608,                   // Full Width  mv
            2313,                   // 1/2 Width  mv
            1643,                   // 1/4 Width  mv
            1243,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2712,                       // Max to Min  mv
        942,                        // PLSF  mv
        0xF0,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        S_32G,                        // Speed
        900,                        // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3301,                   // Full Width  mv
            2149,                   // 1/2 Width  mv
            1555,                   // 1/4 Width  mv
            1232,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2405,                       // Max to Min  mv
        835,                        // PLSF  mv
        0xD5,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        8,                          // #AC lanes
        {
            // power_mv
            4014,                   // Full Width  mv
            4014,                   // 1/2 Width  mv
            2560,                   // 1/4 Width  mv
            1198,                   // 1Lane  mv
            827,                    // Disable  mv
            105,                    // Pgated  mv
        },
        3186,                       // Max to Min  mv
        1107,                       // PLSF  mv
        0x0,                        // PSLF encode
        0xF,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            4738,                   // Full Width  mv
            2911,                   // 1/2 Width  mv
            1938,                   // 1/4 Width  mv
            1177,                   // 1Lane  mv
            827,                    // Disable  mv
            105,                    // Pgated  mv
        },
        3911,                       // Max to Min  mv
        1359,                       // PLSF  mv
        0x0,                        // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3876,                   // Full Width  mv
            2630,                   // 1/2 Width  mv
            1807,                   // 1/4 Width  mv
            1254,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2980,                       // Max to Min  mv
        1035,                       // PLSF  mv
        0x0,                        // PSLF encode
        0x9,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3608,                   // Full Width  mv
            2313,                   // 1/2 Width  mv
            1643,                   // 1/4 Width  mv
            1243,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2712,                       // Max to Min  mv
        942,                        // PLSF  mv
        0xF0,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        S_32G,                        // Speed
        1000,                          // VIO
        16,                         // #AC lanes
        {
            // power_mv
            3301,                   // Full Width  mv
            2149,                   // 1/2 Width  mv
            1555,                   // 1/4 Width  mv
            1232,                   // 1Lane  mv
            895,                    // Disable  mv
            174,                    // Pgated  mv
        },
        2405,                       // Max to Min  mv
        835,                        // PLSF  mv
        0xD5,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
};
#endif
