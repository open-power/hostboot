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
// EKB-Mirror-To: hostboot
#ifndef __P10_IO_PWR_H__
#define __P10_IO_PWR_H__

#include <p10_io_pwr_types.H>



static io_link_powers_data_t link_powers[] =
{
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            6365,                   // Full Width  mv
            4323,                   // 1/2 Width  mv
            4261,                   // 1/4 Width  mv
            4199,                   // 1Lane  mv
            1120,                   // Disable  mv
            20,                     // Pgated  mv
        },
        5245,                       // Max to Min  mv
        860,                        // PLSF  mv
        0xDC,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x9,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_25G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            6854,                   // Full Width  mv
            4774,                   // 1/2 Width  mv
            4674,                   // 1/4 Width  mv
            4574,                   // 1Lane  mv
            1457,                   // Disable  mv
            20,                     // Pgated  mv
        },
        5397,                       // Max to Min  mv
        885,                        // PLSF  mv
        0xE2,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x9,                        // 1/4 Width
    },
    {
        PWR_OMI,                    // IO Power Type
        OMI,                        // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            7827,                   // Full Width  mv
            5476,                   // 1/2 Width  mv
            5352,                   // 1/4 Width  mv
            5228,                   // 1Lane  mv
            1733,                   // Disable  mv
            32,                     // Pgated  mv
        },
        6093,                       // Max to Min  mv
        1000,                       // PLSF  mv
        0xFF,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x9,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        18,                         // #AC lanes
        {
            // power_mv
            3255,                   // Full Width  mv
            1976,                   // 1/2 Width  mv
            1408,                   // 1/4 Width  mv
            1408,                   // 1Lane  mv
            327,                    // Disable  mv
            0,                      // Pgated  mv
        },
        2927,                       // Max to Min  mv
        480,                        // PLSF  mv
        0x7B,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_25G,                        // Speed
        800,                        // VDN
        18,                         // #AC lanes
        {
            // power_mv
            3255,                   // Full Width  mv
            1976,                   // 1/2 Width  mv
            1408,                   // 1/4 Width  mv
            1408,                   // 1Lane  mv
            327,                    // Disable  mv
            0,                      // Pgated  mv
        },
        2927,                       // Max to Min  mv
        480,                        // PLSF  mv
        0x7B,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_AX,                     // IO Power Type
        AX,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        18,                         // #AC lanes
        {
            // power_mv
            3665,                   // Full Width  mv
            2224,                   // 1/2 Width  mv
            1583,                   // 1/4 Width  mv
            1583,                   // 1Lane  mv
            376,                    // Disable  mv
            0,                      // Pgated  mv
        },
        3289,                       // Max to Min  mv
        539,                        // PLSF  mv
        0x8A,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x6,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3886,                   // Full Width  mv
            2648,                   // 1/2 Width  mv
            2546,                   // 1/4 Width  mv
            2444,                   // 1Lane  mv
            834,                    // Disable  mv
            0,                      // Pgated  mv
        },
        3051,                       // Max to Min  mv
        500,                        // PLSF  mv
        0x80,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_25G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4447,                   // Full Width  mv
            3146,                   // 1/2 Width  mv
            2982,                   // 1/4 Width  mv
            2817,                   // 1Lane  mv
            1145,                   // Disable  mv
            0,                      // Pgated  mv
        },
        3301,                       // Max to Min  mv
        541,                        // PLSF  mv
        0x8A,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_OC,                     // IO Power Type
        OC,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            5179,                   // Full Width  mv
            3693,                   // 1/2 Width  mv
            3489,                   // 1/4 Width  mv
            3285,                   // 1Lane  mv
            1392,                   // Disable  mv
            0,                      // Pgated  mv
        },
        3786,                       // Max to Min  mv
        621,                        // PLSF  mv
        0x9E,                       // PSLF encode
        0x9,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            464,                    // Full Width  mv
            394,                    // 1/2 Width  mv
            325,                    // 1/4 Width  mv
            256,                    // 1Lane  mv
            186,                    // Disable  mv
            87,                     // Pgated  mv
        },
        277,                        // Max to Min  mv
        45,                         // PLSF  mv
        0x0C,                       // PSLF encode
        0xB,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_25G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            748,                    // Full Width  mv
            636,                    // 1/2 Width  mv
            524,                    // 1/4 Width  mv
            413,                    // 1Lane  mv
            301,                    // Disable  mv
            126,                    // Pgated  mv
        },
        447,                        // Max to Min  mv
        73,                         // PLSF  mv
        0x13,                       // PSLF encode
        0xB,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_AXO_Base,             // IO Power Type
        AXO_Base,                 // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            929,                    // Full Width  mv
            790,                    // 1/2 Width  mv
            651,                    // 1/4 Width  mv
            513,                    // 1Lane  mv
            374,                    // Disable  mv
            126,                    // Pgated  mv
        },
        555,                        // Max to Min  mv
        91,                         // PLSF  mv
        0x17,                       // PSLF encode
        0xB,                        // 1/2 Width
        0x8,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        8,                          // #AC lanes
        {
            // power_mv
            3944,                   // Full Width  mv
            3944,                   // 1/2 Width  mv
            2567,                   // 1/4 Width  mv
            1069,                   // 1Lane  mv
            721,                    // Disable  mv
            207,                    // Pgated  mv
        },
        3222,                       // Max to Min  mv
        528,                        // PLSF  mv
        0x87,                       // PSLF encode
        0xF,                        // 1/2 Width
        0x9,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G5,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        8,                          // #AC lanes
        {
            // power_mv
            4552,                   // Full Width  mv
            4552,                   // 1/2 Width  mv
            3077,                   // 1/4 Width  mv
            1481,                   // 1Lane  mv
            1035,                   // Disable  mv
            207,                    // Pgated  mv
        },
        3516,                       // Max to Min  mv
        577,                        // PLSF  mv
        0x93,                       // PSLF encode
        0xF,                        // 1/2 Width
        0x9,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4813,                   // Full Width  mv
            2808,                   // 1/2 Width  mv
            1784,                   // 1/4 Width  mv
            1054,                   // 1Lane  mv
            721,                    // Disable  mv
            207,                    // Pgated  mv
        },
        4092,                       // Max to Min  mv
        671,                        // PLSF  mv
        0xAB,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G4,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            5483,                   // Full Width  mv
            3390,                   // 1/2 Width  mv
            2277,                   // 1/4 Width  mv
            1458,                   // 1Lane  mv
            1035,                   // Disable  mv
            207,                    // Pgated  mv
        },
        4447,                       // Max to Min  mv
        729,                        // PLSF  mv
        0xBA,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3925,                   // Full Width  mv
            2350,                   // 1/2 Width  mv
            1548,                   // 1/4 Width  mv
            1040,                   // 1Lane  mv
            721,                    // Disable  mv
            207,                    // Pgated  mv
        },
        3204,                       // Max to Min  mv
        525,                        // PLSF  mv
        0x86,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G3,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            4560,                   // Full Width  mv
            2905,                   // 1/2 Width  mv
            2022,                   // 1/4 Width  mv
            1434,                   // 1Lane  mv
            1035,                   // Disable  mv
            207,                    // Pgated  mv
        },
        3524,                       // Max to Min  mv
        578,                        // PLSF  mv
        0x93,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3303,                   // Full Width  mv
            2031,                   // 1/2 Width  mv
            1385,                   // 1/4 Width  mv
            1033,                   // 1Lane  mv
            721,                    // Disable  mv
            207,                    // Pgated  mv
        },
        2581,                       // Max to Min  mv
        423,                        // PLSF  mv
        0x6C,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G2,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3919,                   // Full Width  mv
            2573,                   // 1/2 Width  mv
            1851,                   // 1/4 Width  mv
            1423,                   // 1Lane  mv
            1035,                   // Disable  mv
            207,                    // Pgated  mv
        },
        2883,                       // Max to Min  mv
        473,                        // PLSF  mv
        0x79,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        S_25G,                        // Speed
        650,                       // VDN
        16,                         // #AC lanes
        {
            // power_mv
            2987,                   // Full Width  mv
            1866,                   // 1/2 Width  mv
            1299,                   // 1/4 Width  mv
            1025,                   // 1Lane  mv
            721,                    // Disable  mv
            207,                    // Pgated  mv
        },
        2265,                       // Max to Min  mv
        371,                        // PLSF  mv
        0x5F,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
    {
        PWR_PCIE_IO,              // IO Power Type
        G1,                         // Sub Type
        S_32G,                        // Speed
        800,                        // VDN
        16,                         // #AC lanes
        {
            // power_mv
            3586,                   // Full Width  mv
            2394,                   // 1/2 Width  mv
            1756,                   // 1/4 Width  mv
            1411,                   // 1Lane  mv
            1035,                   // Disable  mv
            207,                    // Pgated  mv
        },
        2550,                       // Max to Min  mv
        418,                        // PLSF  mv
        0x6B,                       // PSLF encode
        0x8,                        // 1/2 Width
        0x4,                        // 1/4 Width
    },
};
#endif
