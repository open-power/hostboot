/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/lib/p10_io_pwr.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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

#include <p10_io_pwr.H>



const static io_link_powers_t link_powers[] =
{
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            6153,                   // Full Width  mv
            4172,                   // 1/2 Width  mv
            586,                    // 1/4 Width  mv
            0,                      // 1Lane  mv
            739,                    // Disable  mv
        },
        5413,                       // Max to Min  mv
        837,                        // PLSF  mv
        0xD6,                       // PSLF encode
        0xF,                        // Full Width
        0xA,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            7401,                   // Full Width  mv
            5175,                   // 1/2 Width  mv
            1173,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            938,                    // Disable  mv
        },
        6463,                       // Max to Min  mv
        1000,                       // PLSF  mv
        0xFF,                       // PSLF encode
        0xF,                        // Full Width
        0xA,                        // 1/2 Width
        0x1,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        18,                         // #AC lanes
        {
            // power_mv
            3403,                   // Full Width  mv
            2125,                   // 1/2 Width  mv
            1556,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            369,                    // Disable  mv
        },
        3033,                       // Max to Min  mv
        469,                        // PLSF  mv
        0x78,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        18,                         // #AC lanes
        {
            // power_mv
            3962,                   // Full Width  mv
            2521,                   // 1/2 Width  mv
            1880,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            452,                    // Disable  mv
        },
        3510,                       // Max to Min  mv
        543,                        // PLSF  mv
        0x8A,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3614,                   // Full Width  mv
            2478,                   // 1/2 Width  mv
            643,                    // 1/4 Width  mv
            0,                      // 1Lane  mv
            560,                    // Disable  mv
        },
        3053,                       // Max to Min  mv
        472,                        // PLSF  mv
        0x78,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4669,                   // Full Width  mv
            3388,                   // 1/2 Width  mv
            1324,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            797,                    // Disable  mv
        },
        3871,                       // Max to Min  mv
        599,                        // PLSF  mv
        0x99,                       // PSLF encode
        0xF,                        // Full Width
        0xA,                        // 1/2 Width
        0x2,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        8,                          // #AC lanes
        {
            // power_mv
            0,                      // Full Width  mv
            0,                      // 1/2 Width  mv
            0,                      // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        0,                          // Max to Min  mv
        0,                          // PLSF  mv
        0x0,                        // PSLF encode
        0x0,                        // Full Width
        0x0,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        8,                          // #AC lanes
        {
            // power_mv
            0,                      // Full Width  mv
            0,                      // 1/2 Width  mv
            0,                      // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        0,                          // Max to Min  mv
        0,                          // PLSF  mv
        0x0,                        // PSLF encode
        0x0,                        // Full Width
        0x0,                        // 1/2 Width
        0x0,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4328,                   // Full Width  mv
            2469,                   // 1/2 Width  mv
            1590,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        4120,                       // Max to Min  mv
        637,                        // PLSF  mv
        0xA3,                       // PSLF encode
        0xF,                        // Full Width
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4702,                   // Full Width  mv
            2842,                   // 1/2 Width  mv
            1964,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        4494,                       // Max to Min  mv
        695,                        // PLSF  mv
        0xB1,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3498,                   // Full Width  mv
            2054,                   // 1/2 Width  mv
            1383,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        3291,                       // Max to Min  mv
        509,                        // PLSF  mv
        0x82,                       // PSLF encode
        0xF,                        // Full Width
        0x8,                        // 1/2 Width
        0x5,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3872,                   // Full Width  mv
            2428,                   // 1/2 Width  mv
            1756,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        3664,                       // Max to Min  mv
        566,                        // PLSF  mv
        0x91,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            2905,                   // Full Width  mv
            1757,                   // 1/2 Width  mv
            1234,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        2697,                       // Max to Min  mv
        417,                        // PLSF  mv
        0x6A,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3278,                   // Full Width  mv
            2131,                   // 1/2 Width  mv
            1608,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        3071,                       // Max to Min  mv
        475,                        // PLSF  mv
        0x79,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x7,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        25G,                        // Speed
        0.65,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            2618,                   // Full Width  mv
            1614,                   // 1/2 Width  mv
            1163,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        2410,                       // Max to Min  mv
        372,                        // PLSF  mv
        0x5F,                       // PSLF encode
        0xF,                        // Full Width
        0x9,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        32G,                        // Speed
        0.8,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            2991,                   // Full Width  mv
            1987,                   // 1/2 Width  mv
            1536,                   // 1/4 Width  mv
            0,                      // 1Lane  mv
            207,                    // Disable  mv
        },
        2784,                       // Max to Min  mv
        430,                        // PLSF  mv
        0x6E,                       // PSLF encode
        0xF,                        // Full Width
        0xA,                        // 1/2 Width
        0x7,                        // 1/4 Width
    },
};
