/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ringId.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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

#ifndef _P9_RINGID_H_
#define _P9_RINGID_H_

#ifdef WIN32
    #include "win32_stdint.h"
    #include "p9_ring_id.h"
    #include <common_ringId.H>
#else
    #include <stdint.h>
    #include <stddef.h>
    #include <common_ringId.H>
    #include <p9_ring_id.h>
#endif


enum Chiplets
{
    PERV_TYPE,
    N0_TYPE,
    N1_TYPE,
    N2_TYPE,
    N3_TYPE,
    XB_TYPE,
    MC_TYPE,
    OB0_TYPE,
    OB1_TYPE,
    OB2_TYPE,
    OB3_TYPE,
    PCI0_TYPE,
    PCI1_TYPE,
    PCI2_TYPE,
    EQ_TYPE,
    EC_TYPE,
    SBE_NUM_CHIPLETS
};

const ChipletType_t CME_NUM_CHIPLETS = 1;
const ChipletType_t SGPE_NUM_CHIPLETS = 1;


namespace PERV
{
enum RingOffset
{
    // Common Rings
    perv_fure     = 0,
    perv_gptr     = 1,
    perv_time     = 2,
    occ_fure      = 3,
    occ_gptr      = 4,
    occ_time      = 5,
    perv_ana_func = 6,
    perv_ana_gptr = 7,
    perv_pll_gptr = 8,
    perv_pll_bndy = 9,
    // The values for this and the following constant are purposefully made
    // identical. The idea is to enable the user to specify directly the bucket
    // number or use the Attribute. Giving same number here will enable
    // evaluating to the same offset.
    perv_pll_bndy_bucket_1 = 9,
    perv_pll_bndy_bucket_2 = 10,
    perv_pll_bndy_bucket_3 = 11,
    perv_pll_bndy_bucket_4 = 12,
    perv_pll_bndy_bucket_5 = 13,
    perv_pll_func   = 14,
    perv_pll_bndy_flt_1 = 15,
    perv_pll_bndy_flt_2 = 16,
    perv_pll_bndy_flt_3 = 17,
    perv_pll_bndy_flt_4 = 18,
    sbe_fure = 19,
    sbe_gptr = 20,
    // Instance Rings
    perv_repr     = (0 | INSTANCE_RING_MARK),
    occ_repr      = (1 | INSTANCE_RING_MARK),
    sbe_repr      = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x01,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    21, // 21 common rings for pervasive chiplet
    3,  // 3 instance specific rings for pervasive chiplet
    3,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace PERV

namespace N0
{
enum RingOffset
{
    // Common Rings
    n0_fure      = 0,
    n0_gptr      = 1,
    n0_time      = 2,
    n0_nx_fure   = 3,
    n0_nx_gptr   = 4,
    n0_nx_time   = 5,
    n0_cxa0_fure = 6,
    n0_cxa0_gptr = 7,
    n0_cxa0_time = 8,
    // Instance Rings
    n0_repr      = (0 | INSTANCE_RING_MARK),
    n0_nx_repr   = (1 | INSTANCE_RING_MARK),
    n0_cxa0_repr = (2 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x02,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    9,  // 9 common rings for N0 Chiplet
    3,  // 3 instance specific rings for N0 chiplet
    3,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace N1
{
enum RingOffset
{
    // Common Rings
    n1_fure       = 0,
    n1_gptr       = 1,
    n1_time       = 2,
    n1_ioo0_fure  = 3,
    n1_ioo0_gptr  = 4,
    n1_ioo0_time  = 5,
    n1_ioo1_fure  = 6,
    n1_ioo1_gptr  = 7,
    n1_ioo1_time  = 8,
    n1_mcs23_fure = 9,
    n1_mcs23_gptr = 10,
    n1_mcs23_time = 11,
    // Instance Rings
    n1_repr       = (0 | INSTANCE_RING_MARK),
    n1_ioo0_repr  = (1 | INSTANCE_RING_MARK),
    n1_ioo1_repr  = (2 | INSTANCE_RING_MARK),
    n1_mcs23_repr = (3 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x03,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    12, // 12 common rings for N1 Chiplet
    4,  // 4 instance specific rings for N1 chiplet
    4,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace N2
{
enum RingOffset
{
    // Common Rings
    n2_fure      = 0,
    n2_gptr      = 1,
    n2_time      = 2,
    n2_cxa1_fure = 3,
    n2_cxa1_gptr = 4,
    n2_cxa1_time = 5,
    n2_psi_fure = 6,
    n2_psi_gptr = 7,
    n2_psi_time = 8,
    // Instance Rings
    n2_repr      = (0 | INSTANCE_RING_MARK),
    n2_cxa1_repr = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x04, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    9, // 9 common rings for N2 Chiplet
    2, // 2 instance specific rings for N2 chiplet
    2,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace N3
{
enum RingOffset
{
    // Common Rings
    n3_fure       = 0,
    n3_gptr       = 1,
    n3_time       = 2,
    n3_mcs01_fure = 3,
    n3_mcs01_gptr = 4,
    n3_mcs01_time = 5,
    n3_np_fure = 6,
    n3_np_gptr = 7,
    n3_np_time = 8,
    n3_br_fure = 9,
    // Instance Rings
    n3_repr       = (0 | INSTANCE_RING_MARK),
    n3_mcs01_repr = (1 | INSTANCE_RING_MARK),
    n3_np_repr = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x05, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    10,// 10 common rings for N3 Chiplet
    3, // 3 instance specific rings for N3 chiplet
    3,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace XB
{
enum RingOffset
{
    // Common Rings
    xb_fure      = 0,
    xb_gptr      = 1,
    xb_time      = 2,
    xb_io0_fure  = 3,
    xb_io0_gptr  = 4,
    xb_io0_time  = 5,
    xb_io1_fure  = 6,
    xb_io1_gptr  = 7,
    xb_io1_time  = 8,
    xb_io2_fure  = 9,
    xb_io2_gptr  = 10,
    xb_io2_time  = 11,
    xb_pll_gptr  = 12,
    xb_pll_bndy  = 13,
    xb_pll_func  = 14,
    // Instance Rings
    xb_repr      = (0 | INSTANCE_RING_MARK),
    xb_io0_repr  = (1 | INSTANCE_RING_MARK),
    xb_io1_repr  = (2 | INSTANCE_RING_MARK),
    xb_io2_repr  = (3 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x06,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    15, // 15 common rings for X-Bus Chiplet
    4,  // 4 instance specific rings for XB chiplet
    4,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace XB

namespace MC
{
enum RingOffset
{
    // Common Rings
    mc_fure       = 0,
    mc_gptr       = 1,
    mc_time       = 2,
    mc_iom01_fure = 3,
    mc_iom01_gptr = 4,
    mc_iom01_time = 5,
    mc_iom23_fure = 6,
    mc_iom23_gptr = 7,
    mc_iom23_time = 8,
    mc_pll_gptr   = 9,
    mc_pll_bndy = 10,
    mc_pll_bndy_bucket_1 = 10,
    mc_pll_bndy_bucket_2 = 11,
    mc_pll_bndy_bucket_3 = 12,
    mc_pll_bndy_bucket_4 = 13,
    mc_pll_bndy_bucket_5 = 14,
    mc_pll_func = 15,
    mc_omi0_fure = 16,
    mc_omi0_gptr = 17,
    mc_omi1_fure = 18,
    mc_omi1_gptr = 19,
    mc_omi2_fure = 20,
    mc_omi2_gptr = 21,
    mc_omippe_fure = 22,
    mc_omippe_gptr = 23,
    mc_omippe_time = 24,
    // Instance Rings
    mc_repr        = (0 | INSTANCE_RING_MARK),
    mc_iom23_repr  = (1 | INSTANCE_RING_MARK),
    mc_omippe_repr = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x07,  // Base chiplet/instance ID
    2,     // Number of chiplet instances
    25, // 25 common rings for MC Chiplet
    3,  // 3 instance specific rings for each MC instance
    3,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace MC

namespace OB0
{
enum RingOffset
{
    // Common Rings
    ob0_pll_bndy  = 0,
    ob0_pll_bndy_bucket_1  = 0,
    ob0_pll_bndy_bucket_2  = 1,
    ob0_gptr      = 2,
    ob0_time      = 3,
    ob0_pll_gptr  = 4,
    ob0_fure      = 5,
    ob0_pll_bndy_bucket_3  = 6,
    // Instance Rings
    ob0_repr      = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x09,  // Base chiplet/instance ID
    1,     // Number of chiplet instances
    7,  // 7 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace OB0

namespace OB1
{
enum RingOffset
{
    // Common Rings
    ob1_pll_bndy  = 0,
    ob1_pll_bndy_bucket_1  = 0,
    ob1_pll_bndy_bucket_2  = 1,
    ob1_gptr      = 2,
    ob1_time      = 3,
    ob1_pll_gptr  = 4,
    ob1_fure      = 5,
    ob1_pll_bndy_bucket_3  = 6,
    // Instance Rings
    ob1_repr      = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0a, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    7,  // 7 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace OB1


namespace OB2
{
enum RingOffset
{
    // Common Rings
    ob2_pll_bndy  = 0,
    ob2_pll_bndy_bucket_1  = 0,
    ob2_pll_bndy_bucket_2  = 1,
    ob2_gptr      = 2,
    ob2_time      = 3,
    ob2_pll_gptr  = 4,
    ob2_fure      = 5,
    ob2_pll_bndy_bucket_3  = 6,
    // Instance Rings
    ob2_repr      = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0b, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    7,  // 7 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace OB2

namespace OB3
{
enum RingOffset
{
    // Common Rings
    ob3_pll_bndy  = 0,
    ob3_pll_bndy_bucket_1  = 0,
    ob3_pll_bndy_bucket_2  = 1,
    ob3_gptr      = 2,
    ob3_time      = 3,
    ob3_pll_gptr  = 4,
    ob3_fure      = 5,
    ob3_pll_bndy_bucket_3  = 6,
    // Instance Rings
    ob3_repr      = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0c, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    7,  // 7 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

}; // end of namespace OB2

namespace PCI0
{
enum RingOffset
{
    // Common Rings
    pci0_fure = 0,
    pci0_gptr = 1,
    pci0_time = 2,
    pci0_pll_bndy = 3,
    pci0_pll_gptr = 4,
    // Instance Rings
    pci0_repr = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0d, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    5,  // 5 common rings for PCI0 chiplet
    1,  // 1 instance specific rings for PCI0 chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace PCI1
{
enum RingOffset
{
    // Common Rings
    pci1_fure = 0,
    pci1_gptr = 1,
    pci1_time = 2,
    pci1_pll_bndy = 3,
    pci1_pll_gptr = 4,
    // Instance Rings
    pci1_repr = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0e, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    5,  // 5 common rings for PCI1 chiplet
    1,  // 1 instance specific rings for PCI1 chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace PCI2
{
enum RingOffset
{
    // Common Rings
    pci2_fure = 0,
    pci2_gptr = 1,
    pci2_time = 2,
    pci2_pll_bndy = 3,
    pci2_pll_gptr = 4,
    // Instance Rings
    pci2_repr = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x0f, // Base chiplet/instance ID
    1,    // Number of chiplet instances
    5,  // 5 common rings for PCI2 chiplet
    1,  // 1 instance specific rings for PCI2 chiplet
    1,
    2,  // 2 common ring variants: BASE, RL
    {
        RV_BASE,
        RV_RL,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT,
        UNDEFINED_RING_VARIANT
    }
};

};

namespace EQ
{
enum RingOffset
{
    // Common Rings
    eq_fure         = 0,
    eq_gptr         = 1,
    eq_time         = 2,
    eq_inex         = 3,
    ex_l3_fure      = 4,
    ex_l3_gptr      = 5,
    ex_l3_time      = 6,
    ex_l2_mode      = 7,
    ex_l2_fure      = 8,
    ex_l2_gptr      = 9,
    ex_l2_time      = 10,
    ex_l3_refr_fure = 11,
    ex_l3_refr_gptr = 12,
    eq_ana_func     = 13,
    eq_ana_gptr     = 14,
    eq_dpll_func    = 15,
    eq_dpll_gptr    = 16,
    eq_dpll_mode    = 17,
    eq_ana_bndy     = 18,
    eq_ana_bndy_bucket_0   = 18,
    eq_ana_bndy_bucket_1   = 19,
    eq_ana_bndy_bucket_2   = 20,
    eq_ana_bndy_bucket_3   = 21,
    eq_ana_bndy_bucket_4   = 22,
    eq_ana_bndy_bucket_5   = 23,
    eq_ana_bndy_bucket_6   = 24,
    eq_ana_bndy_bucket_7   = 25,
    eq_ana_bndy_bucket_8   = 26,
    eq_ana_bndy_bucket_9   = 27,
    eq_ana_bndy_bucket_10  = 28,
    eq_ana_bndy_bucket_11  = 29,
    eq_ana_bndy_bucket_12  = 30,
    eq_ana_bndy_bucket_13  = 31,
    eq_ana_bndy_bucket_14  = 32,
    eq_ana_bndy_bucket_15  = 33,
    eq_ana_bndy_bucket_16  = 34,
    eq_ana_bndy_bucket_17  = 35,
    eq_ana_bndy_bucket_18  = 36,
    eq_ana_bndy_bucket_19  = 37,
    eq_ana_bndy_bucket_20  = 38,
    eq_ana_bndy_bucket_21  = 39,
    eq_ana_bndy_bucket_22  = 40,
    eq_ana_bndy_bucket_23  = 41,
    eq_ana_bndy_bucket_24  = 42,
    eq_ana_bndy_bucket_25  = 43,
    eq_ana_bndy_bucket_l3dcc  = 44,
    eq_ana_mode     = 45,
    eq_ana_bndy_bucket_26 = 46,
    eq_ana_bndy_bucket_27 = 47,
    eq_ana_bndy_bucket_28 = 48,
    eq_ana_bndy_bucket_29 = 49,
    eq_ana_bndy_bucket_30 = 50,
    eq_ana_bndy_bucket_31 = 51,
    eq_ana_bndy_bucket_32 = 52,
    eq_ana_bndy_bucket_33 = 53,
    eq_ana_bndy_bucket_34 = 54,
    eq_ana_bndy_bucket_35 = 55,
    eq_ana_bndy_bucket_36 = 56,
    eq_ana_bndy_bucket_37 = 57,
    eq_ana_bndy_bucket_38 = 58,
    eq_ana_bndy_bucket_39 = 59,
    eq_ana_bndy_bucket_40 = 60,
    eq_ana_bndy_bucket_41 = 61,
    eq_inex_bucket_1      = 62,
    eq_inex_bucket_2      = 63,
    eq_inex_bucket_3      = 64,
    eq_inex_bucket_4      = 65,

    // Instance Rings
    eq_repr         = (0 | INSTANCE_RING_MARK),
    ex_l3_repr      = (1 | INSTANCE_RING_MARK),
    ex_l2_repr      = (2 | INSTANCE_RING_MARK),
    ex_l3_refr_repr = (3 | INSTANCE_RING_MARK),
    ex_l3_refr_time = (4 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x10, // Base chiplet/instance ID.
    // Note that the Quad EQ chiplet/instance ID range is 16 - 21 but that in addition
    // to this there are two EXs per EQ: even and odd, making a total of 12 instances
    12,   // Max num of EX/EQ combined instance IDs = 2 (EX) x 6 (EQ) = 12
    66, // 66 common rings for Quad chiplet.
    5,  // 5 instance specific rings for each EQ chiplet
    9,  // 9 different rings since 2 per EX ring and 1 per EQ
    7,  // 7 common ring variants: BASE, CC, RL, RL2/3/4/5
    {
        RV_BASE,
        RV_CC,
        RV_RL,
        RV_RL2,
        RV_RL3,
        RV_RL4,
        RV_RL5
    }
};

}; // end of namespace EQ

namespace EC
{
enum RingOffset
{
    // Common Rings
    ec_func = 0,
    ec_gptr = 1,
    ec_time = 2,
    ec_mode = 3,
    ec_abst = 4,
    ec_cmsk = 5,
    // Instance Rings
    ec_repr = (0 | INSTANCE_RING_MARK)
};

static const ChipletData_t g_chipletData =
{
    0x20, // Core chiplet/instance ID range is 32-55. The base instance ID is 32.
    24,   // Number of chiplet instances
    6,  // 6 common rings for Core chiplet
    1,  // 1 instance specific ring for each Core chiplet
    1,
    7,  // 7 common ring variants: BASE, CC, RL, RL2/3/4/5
    {
        RV_BASE,
        RV_CC,
        RV_RL,
        RV_RL2,
        RV_RL3,
        RV_RL4,
        RV_RL5
    }
};

}; // end of namespace EC


#ifndef __PPE__

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { "perv_fure"               , 0x0103400F, PERV::perv_fure             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 0
    { "perv_gptr"               , 0x01034002, PERV::perv_gptr             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 1
    { "perv_time"               , 0x01034007, PERV::perv_time             , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 2
    { "occ_fure"                , 0x0103080F, PERV::occ_fure              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 3
    { "occ_gptr"                , 0x01030802, PERV::occ_gptr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 4
    { "occ_time"                , 0x01030807, PERV::occ_time              , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 5
    { "perv_ana_func"           , 0x01030400, PERV::perv_ana_func         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 6
    { "perv_ana_gptr"           , 0x01030402, PERV::perv_ana_gptr         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 7
    { "perv_pll_gptr"           , 0x01030012, PERV::perv_pll_gptr         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 8
    { "perv_pll_bndy"           , 0x01030018, PERV::perv_pll_bndy         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 9
    { "perv_pll_bndy_bucket_1"  , 0x01030018, PERV::perv_pll_bndy_bucket_1, PERV_TYPE,                  RCLS_EKB_FLUSH_RING }, // 10
    { "perv_pll_bndy_bucket_2"  , 0x01030018, PERV::perv_pll_bndy_bucket_2, PERV_TYPE,                  RCLS_EKB_FLUSH_RING }, // 11
    { "perv_pll_bndy_bucket_3"  , 0x01030018, PERV::perv_pll_bndy_bucket_3, PERV_TYPE,                  RCLS_EKB_FLUSH_RING }, // 12
    { "perv_pll_bndy_bucket_4"  , 0x01030018, PERV::perv_pll_bndy_bucket_4, PERV_TYPE,                  RCLS_EKB_FLUSH_RING }, // 13
    { "perv_pll_bndy_bucket_5"  , 0x01030018, PERV::perv_pll_bndy_bucket_5, PERV_TYPE,                  RCLS_EKB_FLUSH_RING }, // 14
    { "perv_pll_func"           , 0x01030010, PERV::perv_pll_func         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 15
    { "perv_repr"               , 0x01034006, PERV::perv_repr             , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 16
    { "occ_repr"                , 0x01030806, PERV::occ_repr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 17
    { "sbe_fure"                , 0x0103020F, PERV::sbe_fure              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 18
    { "sbe_gptr"                , 0x01030202, PERV::sbe_gptr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 19
    { "sbe_repr"                , 0x01030206, PERV::sbe_repr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 20
    { "n0_fure"                 , 0x02034E0F, N0::n0_fure                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 21
    { "n0_gptr"                 , 0x02034E02, N0::n0_gptr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 22
    { "n0_time"                 , 0x02034E07, N0::n0_time                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 23
    { "n0_nx_fure"              , 0x0203200F, N0::n0_nx_fure              , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 24
    { "n0_nx_gptr"              , 0x02032002, N0::n0_nx_gptr              , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 25
    { "n0_nx_time"              , 0x02032007, N0::n0_nx_time              , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 26
    { "n0_cxa0_fure"            , 0x0203100F, N0::n0_cxa0_fure            , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 27
    { "n0_cxa0_gptr"            , 0x02031002, N0::n0_cxa0_gptr            , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 28
    { "n0_cxa0_time"            , 0x02031007, N0::n0_cxa0_time            , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 29
    { "n0_repr"                 , 0x02034E06, N0::n0_repr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 30
    { "n0_nx_repr"              , 0x02032006, N0::n0_nx_repr              , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 31
    { "n0_cxa0_repr"            , 0x02031006, N0::n0_cxa0_repr            , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 32
    { "n1_fure"                 , 0x0303700F, N1::n1_fure                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 33
    { "n1_gptr"                 , 0x03037002, N1::n1_gptr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 34
    { "n1_time"                 , 0x03037007, N1::n1_time                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 35
    { "n1_ioo0_fure"            , 0x0303080F, N1::n1_ioo0_fure            , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 36
    { "n1_ioo0_gptr"            , 0x03030802, N1::n1_ioo0_gptr            , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 37
    { "n1_ioo0_time"            , 0x03030807, N1::n1_ioo0_time            , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 38
    { "n1_ioo1_fure"            , 0x0303040F, N1::n1_ioo1_fure            , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 39
    { "n1_ioo1_gptr"            , 0x03030402, N1::n1_ioo1_gptr            , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 40
    { "n1_ioo1_time"            , 0x03030407, N1::n1_ioo1_time            , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 41
    { "n1_mcs23_fure"           , 0x0303020F, N1::n1_mcs23_fure           , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 42
    { "n1_mcs23_gptr"           , 0x03030202, N1::n1_mcs23_gptr           , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 43
    { "n1_mcs23_time"           , 0x03030207, N1::n1_mcs23_time           , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 44
    { "n1_repr"                 , 0x03037006, N1::n1_repr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 45
    { "n1_ioo0_repr"            , 0x03030806, N1::n1_ioo0_repr            , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 46
    { "n1_ioo1_repr"            , 0x03030406, N1::n1_ioo1_repr            , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 47
    { "n1_mcs23_repr"           , 0x03030206, N1::n1_mcs23_repr           , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 48
    { "n2_fure"                 , 0x04035C0F, N2::n2_fure                 , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 49
    { "n2_gptr"                 , 0x04035C02, N2::n2_gptr                 , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 50
    { "n2_time"                 , 0x04035C07, N2::n2_time                 , N2_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 51
    { "n2_cxa1_fure"            , 0x0403200F, N2::n2_cxa1_fure            , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 52
    { "n2_cxa1_gptr"            , 0x04032002, N2::n2_cxa1_gptr            , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 53
    { "n2_cxa1_time"            , 0x04032007, N2::n2_cxa1_time            , N2_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 54
    { "n2_psi_fure"             , 0x0403020F, N2::n2_psi_fure             , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 55
    { "n2_psi_gptr"             , 0x04030202, N2::n2_psi_gptr             , N2_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 56
    { "n2_psi_time"             , 0x04030207, N2::n2_psi_time             , N2_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 57
    { "n2_repr"                 , 0x04035C06, N2::n2_repr                 , N2_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 58
    { "n2_cxa1_repr"            , 0x04032006, N2::n2_cxa1_repr            , N2_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 59
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, N2_TYPE  ,                  UNDEFINED_RING_CLASS }, // 60
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, N2_TYPE  ,                  UNDEFINED_RING_CLASS }, // 61
    { "n3_fure"                 , 0x0503660F, N3::n3_fure                 , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 62
    { "n3_gptr"                 , 0x05037602, N3::n3_gptr                 , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 63
    { "n3_time"                 , 0x05037607, N3::n3_time                 , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 64
    { "n3_mcs01_fure"           , 0x0503010F, N3::n3_mcs01_fure           , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 65
    { "n3_mcs01_gptr"           , 0x05030102, N3::n3_mcs01_gptr           , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 66
    { "n3_mcs01_time"           , 0x05030107, N3::n3_mcs01_time           , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 67
    { "n3_np_fure"              , 0x0503080F, N3::n3_np_fure              , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 68
    { "n3_np_gptr"              , 0x05030802, N3::n3_np_gptr              , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 69
    { "n3_np_time"              , 0x05030807, N3::n3_np_time              , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 70
    { "n3_repr"                 , 0x05037606, N3::n3_repr                 , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 71
    { "n3_mcs01_repr"           , 0x05030106, N3::n3_mcs01_repr           , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 72
    { "n3_np_repr"              , 0x05030806, N3::n3_np_repr              , N3_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 73
    { "n3_br_fure"              , 0x0503100F, N3::n3_br_fure              , N3_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 74
    { "xb_fure"                 , 0x0603440F, XB::xb_fure                 , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 75
    { "xb_gptr"                 , 0x06034402, XB::xb_gptr                 , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 76
    { "xb_time"                 , 0x06034407, XB::xb_time                 , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 77
    { "xb_io0_fure"             , 0x0603220F, XB::xb_io0_fure             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 78
    { "xb_io0_gptr"             , 0x06032202, XB::xb_io0_gptr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 79
    { "xb_io0_time"             , 0x06032207, XB::xb_io0_time             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 80
    { "xb_io1_fure"             , 0x0603110F, XB::xb_io1_fure             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 81
    { "xb_io1_gptr"             , 0x06031102, XB::xb_io1_gptr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 82
    { "xb_io1_time"             , 0x06031107, XB::xb_io1_time             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 83
    { "xb_io2_fure"             , 0x0603088F, XB::xb_io2_fure             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 84
    { "xb_io2_gptr"             , 0x06030882, XB::xb_io2_gptr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 85
    { "xb_io2_time"             , 0x06030887, XB::xb_io2_time             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 86
    { "xb_pll_gptr"             , 0x06030012, XB::xb_pll_gptr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 87
    { "xb_pll_bndy"             , 0x06030018, XB::xb_pll_bndy             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 88
    { "xb_pll_func"             , 0x06030010, XB::xb_pll_func             , XB_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 89
    { "xb_repr"                 , 0x06034406, XB::xb_repr                 , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 90
    { "xb_io0_repr"             , 0x06032206, XB::xb_io0_repr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 91
    { "xb_io1_repr"             , 0x06031106, XB::xb_io1_repr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 92
    { "xb_io2_repr"             , 0x06030886, XB::xb_io2_repr             , XB_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 93
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, XB_TYPE  ,                  UNDEFINED_RING_CLASS }, // 94
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, XB_TYPE  ,                  UNDEFINED_RING_CLASS }, // 95
    { "mc_fure"                 , 0x0703600F, MC::mc_fure                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 96
    { "mc_gptr"                 , 0x07036002, MC::mc_gptr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 97
    { "mc_time"                 , 0x07036007, MC::mc_time                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 98
    { "mc_iom01_fure"           , 0x0703100F, MC::mc_iom01_fure           , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 99
    { "mc_iom01_gptr"           , 0x07031002, MC::mc_iom01_gptr           , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 100
    { "mc_iom01_time"           , 0x07031007, MC::mc_iom01_time           , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 101
    { "mc_iom23_fure"           , 0x0703080F, MC::mc_iom23_fure           , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 102
    { "mc_iom23_gptr"           , 0x07030802, MC::mc_iom23_gptr           , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 103
    { "mc_iom23_time"           , 0x07030807, MC::mc_iom23_time           , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 104
    { "mc_pll_gptr"             , 0x07030012, MC::mc_pll_gptr             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 105
    { "mc_pll_bndy"             , 0x07030018, MC::mc_pll_bndy             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 106
    { "mc_pll_bndy_bucket_1"    , 0x07030018, MC::mc_pll_bndy_bucket_1    , MC_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 107
    { "mc_pll_bndy_bucket_2"    , 0x07030018, MC::mc_pll_bndy_bucket_2    , MC_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 108
    { "mc_pll_bndy_bucket_3"    , 0x07030018, MC::mc_pll_bndy_bucket_3    , MC_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 109
    { "mc_pll_bndy_bucket_4"    , 0x07030018, MC::mc_pll_bndy_bucket_4    , MC_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 110
    { "mc_pll_bndy_bucket_5"    , 0x07030018, MC::mc_pll_bndy_bucket_5    , MC_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 111
    { "mc_pll_func"             , 0x07030010, MC::mc_pll_func             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 112
    { "mc_repr"                 , 0x07036006, MC::mc_repr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 113
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, MC_TYPE  ,                  UNDEFINED_RING_CLASS }, // 114
    { "mc_iom23_repr"           , 0x07030806, MC::mc_iom23_repr           , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 115
    { "ob0_pll_bndy"            , 0x09030018, OB0::ob0_pll_bndy           , OB0_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 116
    { "ob0_pll_bndy_bucket_1"   , 0x09030018, OB0::ob0_pll_bndy_bucket_1  , OB0_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 117
    { "ob0_pll_bndy_bucket_2"   , 0x09030018, OB0::ob0_pll_bndy_bucket_2  , OB0_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 118
    { "ob0_gptr"                , 0x09037002, OB0::ob0_gptr               , OB0_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 119
    { "ob0_time"                , 0x09037007, OB0::ob0_time               , OB0_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 120
    { "ob0_pll_gptr"            , 0x09030012, OB0::ob0_pll_gptr           , OB0_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 121
    { "ob0_fure"                , 0x0903700F, OB0::ob0_fure               , OB0_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 122
    { "ob0_pll_bndy_bucket_3"   , 0x09030018, OB0::ob0_pll_bndy_bucket_3  , OB0_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 123
    { "ob0_repr"                , 0x09037006, OB0::ob0_repr               , OB0_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 124
    { "ob1_pll_bndy"            , 0x0A030018, OB1::ob1_pll_bndy           , OB1_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 125
    { "ob1_pll_bndy_bucket_1"   , 0x0A030018, OB1::ob1_pll_bndy_bucket_1  , OB1_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 126
    { "ob1_pll_bndy_bucket_2"   , 0x0A030018, OB1::ob1_pll_bndy_bucket_2  , OB1_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 127
    { "ob1_gptr"                , 0x0A037002, OB1::ob1_gptr               , OB1_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 128
    { "ob1_time"                , 0x0A037007, OB1::ob1_time               , OB1_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 129
    { "ob1_pll_gptr"            , 0x0A030012, OB1::ob1_pll_gptr           , OB1_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 130
    { "ob1_fure"                , 0x0A03700F, OB1::ob1_fure               , OB1_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 131
    { "ob1_pll_bndy_bucket_3"   , 0x0A030018, OB1::ob1_pll_bndy_bucket_3  , OB1_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 132
    { "ob1_repr"                , 0x0A037006, OB1::ob1_repr               , OB1_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 133
    { "ob2_pll_bndy"            , 0x0B030018, OB2::ob2_pll_bndy           , OB2_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 134
    { "ob2_pll_bndy_bucket_1"   , 0x0B030018, OB2::ob2_pll_bndy_bucket_1  , OB2_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 135
    { "ob2_pll_bndy_bucket_2"   , 0x0B030018, OB2::ob2_pll_bndy_bucket_2  , OB2_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 136
    { "ob2_gptr"                , 0x0B037002, OB2::ob2_gptr               , OB2_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 137
    { "ob2_time"                , 0x0B037007, OB2::ob2_time               , OB2_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 138
    { "ob2_pll_gptr"            , 0x0B030012, OB2::ob2_pll_gptr           , OB2_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 139
    { "ob2_fure"                , 0x0B03700F, OB2::ob2_fure               , OB2_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 140
    { "ob2_pll_bndy_bucket_3"   , 0x0B030018, OB2::ob2_pll_bndy_bucket_3  , OB2_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 141
    { "ob2_repr"                , 0x0B037006, OB2::ob2_repr               , OB2_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 142
    { "ob3_pll_bndy"            , 0x0C030018, OB3::ob3_pll_bndy           , OB3_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 143
    { "ob3_pll_bndy_bucket_1"   , 0x0C030018, OB3::ob3_pll_bndy_bucket_1  , OB3_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 144
    { "ob3_pll_bndy_bucket_2"   , 0x0C030018, OB3::ob3_pll_bndy_bucket_2  , OB3_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 145
    { "ob3_gptr"                , 0x0C037002, OB3::ob3_gptr               , OB3_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 146
    { "ob3_time"                , 0x0C037007, OB3::ob3_time               , OB3_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 147
    { "ob3_pll_gptr"            , 0x0C030012, OB3::ob3_pll_gptr           , OB3_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 148
    { "ob3_fure"                , 0x0C03700F, OB3::ob3_fure               , OB3_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 149
    { "ob3_pll_bndy_bucket_3"   , 0x0C030018, OB3::ob3_pll_bndy_bucket_3  , OB3_TYPE ,                  RCLS_EKB_FLUSH_RING }, // 150
    { "ob3_repr"                , 0x0C037006, OB3::ob3_repr               , OB3_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 151
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, OB3_TYPE ,                  UNDEFINED_RING_CLASS }, // 152
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, OB3_TYPE ,                  UNDEFINED_RING_CLASS }, // 153
    { "pci0_fure"               , 0x0D03700F, PCI0::pci0_fure             , PCI0_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 154
    { "pci0_gptr"               , 0x0D037002, PCI0::pci0_gptr             , PCI0_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 155
    { "pci0_time"               , 0x0D037007, PCI0::pci0_time             , PCI0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 156
    { "pci0_pll_bndy"           , 0x0D030018, PCI0::pci0_pll_bndy         , PCI0_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 157
    { "pci0_pll_gptr"           , 0x0D030012, PCI0::pci0_pll_gptr         , PCI0_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 158
    { "pci0_repr"               , 0x0D037006, PCI0::pci0_repr             , PCI0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 159
    { "pci1_fure"               , 0x0E03780F, PCI1::pci1_fure             , PCI1_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 160
    { "pci1_gptr"               , 0x0E037802, PCI1::pci1_gptr             , PCI1_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 161
    { "pci1_time"               , 0x0E037807, PCI1::pci1_time             , PCI1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 162
    { "pci1_pll_bndy"           , 0x0E030018, PCI1::pci1_pll_bndy         , PCI1_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 163
    { "pci1_pll_gptr"           , 0x0E030012, PCI1::pci1_pll_gptr         , PCI1_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 164
    { "pci1_repr"               , 0x0E037806, PCI1::pci1_repr             , PCI1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 165
    { "pci2_fure"               , 0x0F037C0F, PCI2::pci2_fure             , PCI2_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 166
    { "pci2_gptr"               , 0x0F037C02, PCI2::pci2_gptr             , PCI2_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 167
    { "pci2_time"               , 0x0F037C07, PCI2::pci2_time             , PCI2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 168
    { "pci2_pll_bndy"           , 0x0F030018, PCI2::pci2_pll_bndy         , PCI2_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 169
    { "pci2_pll_gptr"           , 0x0F030012, PCI2::pci2_pll_gptr         , PCI2_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 170
    { "pci2_repr"               , 0x0F037C06, PCI2::pci2_repr             , PCI2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 171
    { "eq_fure"                 , 0x1003608F, EQ::eq_fure                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 172
    { "eq_gptr"                 , 0x10036082, EQ::eq_gptr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 173
    { "eq_time"                 , 0x10036087, EQ::eq_time                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 174
    { "eq_inex"                 , 0x1003608B, EQ::eq_inex                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 175
    { "ex_l3_fure"              , 0x1003100F, EQ::ex_l3_fure              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 176
    { "ex_l3_gptr"              , 0x10031002, EQ::ex_l3_gptr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 177
    { "ex_l3_time"              , 0x10031007, EQ::ex_l3_time              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 178
    { "ex_l2_mode"              , 0x10030401, EQ::ex_l2_mode              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 179
    { "ex_l2_fure"              , 0x1003040F, EQ::ex_l2_fure              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 180
    { "ex_l2_gptr"              , 0x10030402, EQ::ex_l2_gptr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 181
    { "ex_l2_time"              , 0x10030407, EQ::ex_l2_time              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 182
    { "ex_l3_refr_fure"         , 0x1003004F, EQ::ex_l3_refr_fure         , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 183
    { "ex_l3_refr_gptr"         , 0x10030042, EQ::ex_l3_refr_gptr         , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 184
    { "ex_l3_refr_time"         , 0x10030047, EQ::ex_l3_refr_time         , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 185
    { "eq_ana_func"             , 0x10030100, EQ::eq_ana_func             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 186
    { "eq_ana_gptr"             , 0x10030102, EQ::eq_ana_gptr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 187
    { "eq_dpll_func"            , 0x10030010, EQ::eq_dpll_func            , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 188
    { "eq_dpll_gptr"            , 0x10030012, EQ::eq_dpll_gptr            , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 189
    { "eq_dpll_mode"            , 0x10030011, EQ::eq_dpll_mode            , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 190
    { "eq_ana_bndy"             , 0x10030108, EQ::eq_ana_bndy             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FSM_RING }, // 191
    { "eq_ana_bndy_bucket_0"    , 0x10030108, EQ::eq_ana_bndy_bucket_0    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 192
    { "eq_ana_bndy_bucket_1"    , 0x10030108, EQ::eq_ana_bndy_bucket_1    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 193
    { "eq_ana_bndy_bucket_2"    , 0x10030108, EQ::eq_ana_bndy_bucket_2    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 194
    { "eq_ana_bndy_bucket_3"    , 0x10030108, EQ::eq_ana_bndy_bucket_3    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 195
    { "eq_ana_bndy_bucket_4"    , 0x10030108, EQ::eq_ana_bndy_bucket_4    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 196
    { "eq_ana_bndy_bucket_5"    , 0x10030108, EQ::eq_ana_bndy_bucket_5    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 197
    { "eq_ana_bndy_bucket_6"    , 0x10030108, EQ::eq_ana_bndy_bucket_6    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 198
    { "eq_ana_bndy_bucket_7"    , 0x10030108, EQ::eq_ana_bndy_bucket_7    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 199
    { "eq_ana_bndy_bucket_8"    , 0x10030108, EQ::eq_ana_bndy_bucket_8    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 200
    { "eq_ana_bndy_bucket_9"    , 0x10030108, EQ::eq_ana_bndy_bucket_9    , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 201
    { "eq_ana_bndy_bucket_10"   , 0x10030108, EQ::eq_ana_bndy_bucket_10   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 202
    { "eq_ana_bndy_bucket_11"   , 0x10030108, EQ::eq_ana_bndy_bucket_11   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 203
    { "eq_ana_bndy_bucket_12"   , 0x10030108, EQ::eq_ana_bndy_bucket_12   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 204
    { "eq_ana_bndy_bucket_13"   , 0x10030108, EQ::eq_ana_bndy_bucket_13   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 205
    { "eq_ana_bndy_bucket_14"   , 0x10030108, EQ::eq_ana_bndy_bucket_14   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 206
    { "eq_ana_bndy_bucket_15"   , 0x10030108, EQ::eq_ana_bndy_bucket_15   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 207
    { "eq_ana_bndy_bucket_16"   , 0x10030108, EQ::eq_ana_bndy_bucket_16   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 208
    { "eq_ana_bndy_bucket_17"   , 0x10030108, EQ::eq_ana_bndy_bucket_17   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 209
    { "eq_ana_bndy_bucket_18"   , 0x10030108, EQ::eq_ana_bndy_bucket_18   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 210
    { "eq_ana_bndy_bucket_19"   , 0x10030108, EQ::eq_ana_bndy_bucket_19   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 211
    { "eq_ana_bndy_bucket_20"   , 0x10030108, EQ::eq_ana_bndy_bucket_20   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 212
    { "eq_ana_bndy_bucket_21"   , 0x10030108, EQ::eq_ana_bndy_bucket_21   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 213
    { "eq_ana_bndy_bucket_22"   , 0x10030108, EQ::eq_ana_bndy_bucket_22   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 214
    { "eq_ana_bndy_bucket_23"   , 0x10030108, EQ::eq_ana_bndy_bucket_23   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 215
    { "eq_ana_bndy_bucket_24"   , 0x10030108, EQ::eq_ana_bndy_bucket_24   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 216
    { "eq_ana_bndy_bucket_25"   , 0x10030108, EQ::eq_ana_bndy_bucket_25   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 217
    { "eq_ana_bndy_bucket_l3dcc", 0x10030108, EQ::eq_ana_bndy_bucket_l3dcc, EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 218
    { "eq_ana_mode"             , 0x10030101, EQ::eq_ana_mode             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 219
    { "eq_repr"                 , 0x10036086, EQ::eq_repr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 220
    { "ex_l3_repr"              , 0x10031006, EQ::ex_l3_repr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 221
    { "ex_l2_repr"              , 0x10030406, EQ::ex_l2_repr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 222
    { "ex_l3_refr_repr"         , 0x10030046, EQ::ex_l3_refr_repr         , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 223
    { "ec_func"                 , 0x2003700F, EC::ec_func                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_STUMPED_RING }, // 224
    { "ec_gptr"                 , 0x20037002, EC::ec_gptr                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 225
    { "ec_time"                 , 0x20037007, EC::ec_time                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 226
    { "ec_mode"                 , 0x20037001, EC::ec_mode                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 227
    { "ec_repr"                 , 0x20037006, EC::ec_repr                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 228
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, EQ_TYPE  ,                  UNDEFINED_RING_CLASS }, // 229
    { "invalid"                 , UNDEFINED_SCOM_ADDR, INVALID_RING_OFFSET, EQ_TYPE  ,                  UNDEFINED_RING_CLASS }, // 230
    { "ec_abst"                 , 0x20037005, EC::ec_abst                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 231
    { "eq_ana_bndy_bucket_26"   , 0x10030108, EQ::eq_ana_bndy_bucket_26   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 232
    { "eq_ana_bndy_bucket_27"   , 0x10030108, EQ::eq_ana_bndy_bucket_27   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 233
    { "eq_ana_bndy_bucket_28"   , 0x10030108, EQ::eq_ana_bndy_bucket_28   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 234
    { "eq_ana_bndy_bucket_29"   , 0x10030108, EQ::eq_ana_bndy_bucket_29   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 235
    { "eq_ana_bndy_bucket_30"   , 0x10030108, EQ::eq_ana_bndy_bucket_30   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 236
    { "eq_ana_bndy_bucket_31"   , 0x10030108, EQ::eq_ana_bndy_bucket_31   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 237
    { "eq_ana_bndy_bucket_32"   , 0x10030108, EQ::eq_ana_bndy_bucket_32   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 238
    { "eq_ana_bndy_bucket_33"   , 0x10030108, EQ::eq_ana_bndy_bucket_33   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 239
    { "eq_ana_bndy_bucket_34"   , 0x10030108, EQ::eq_ana_bndy_bucket_34   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 240
    { "eq_ana_bndy_bucket_35"   , 0x10030108, EQ::eq_ana_bndy_bucket_35   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 241
    { "eq_ana_bndy_bucket_36"   , 0x10030108, EQ::eq_ana_bndy_bucket_36   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 242
    { "eq_ana_bndy_bucket_37"   , 0x10030108, EQ::eq_ana_bndy_bucket_37   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 243
    { "eq_ana_bndy_bucket_38"   , 0x10030108, EQ::eq_ana_bndy_bucket_38   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 244
    { "eq_ana_bndy_bucket_39"   , 0x10030108, EQ::eq_ana_bndy_bucket_39   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 245
    { "eq_ana_bndy_bucket_40"   , 0x10030108, EQ::eq_ana_bndy_bucket_40   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 246
    { "eq_ana_bndy_bucket_41"   , 0x10030108, EQ::eq_ana_bndy_bucket_41   , EQ_TYPE  ,                  RCLS_EKB_FSM_RING }, // 247
    { "eq_inex_bucket_1"        , 0x1003608B, EQ::eq_inex_bucket_1        , EQ_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 248
    { "eq_inex_bucket_2"        , 0x1003608B, EQ::eq_inex_bucket_2        , EQ_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 249
    { "eq_inex_bucket_3"        , 0x1003608B, EQ::eq_inex_bucket_3        , EQ_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 250
    { "eq_inex_bucket_4"        , 0x1003608B, EQ::eq_inex_bucket_4        , EQ_TYPE  ,                  RCLS_EKB_FLUSH_RING }, // 251
    { "ec_cmsk"                 , 0x2003700A, EC::ec_cmsk                 , EC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_CMSK_RING }, // 252
    { "perv_pll_bndy_flt_1"     , 0x01030018, PERV::perv_pll_bndy_flt_1   , PERV_TYPE,                  RCLS_EKB_NONFLUSH_RING }, // 253
    { "perv_pll_bndy_flt_2"     , 0x01030018, PERV::perv_pll_bndy_flt_2   , PERV_TYPE,                  RCLS_EKB_NONFLUSH_RING }, // 254
    { "perv_pll_bndy_flt_3"     , 0x01030018, PERV::perv_pll_bndy_flt_3   , PERV_TYPE,                  RCLS_EKB_NONFLUSH_RING }, // 255
    { "perv_pll_bndy_flt_4"     , 0x01030018, PERV::perv_pll_bndy_flt_4   , PERV_TYPE,                  RCLS_EKB_NONFLUSH_RING }, // 256
    { "mc_omi0_fure"            , 0x0703100F, MC::mc_omi0_fure            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 257
    { "mc_omi0_gptr"            , 0x07031002, MC::mc_omi0_gptr            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 258
    { "mc_omi1_fure"            , 0x0703080F, MC::mc_omi1_fure            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 259
    { "mc_omi1_gptr"            , 0x07030802, MC::mc_omi1_gptr            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 260
    { "mc_omi2_fure"            , 0x0703040F, MC::mc_omi2_fure            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 261
    { "mc_omi2_gptr"            , 0x07030402, MC::mc_omi2_gptr            , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 262
    { "mc_omippe_fure"          , 0x0703020F, MC::mc_omippe_fure          , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 263
    { "mc_omippe_gptr"          , 0x07030202, MC::mc_omippe_gptr          , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING }, // 264
    { "mc_omippe_time"          , 0x07030207, MC::mc_omippe_time          , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING }, // 265
    { "mc_omippe_repr"          , 0x07030206, MC::mc_omippe_repr          , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING }, // 266
};
#endif

#ifdef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { PERV::perv_fure              , PERV_TYPE }, // 0
    { PERV::perv_gptr              , PERV_TYPE }, // 1
    { PERV::perv_time              , PERV_TYPE }, // 2
    { PERV::occ_fure               , PERV_TYPE }, // 3
    { PERV::occ_gptr               , PERV_TYPE }, // 4
    { PERV::occ_time               , PERV_TYPE }, // 5
    { PERV::perv_ana_func          , PERV_TYPE }, // 6
    { PERV::perv_ana_gptr          , PERV_TYPE }, // 7
    { PERV::perv_pll_gptr          , PERV_TYPE }, // 8
    { PERV::perv_pll_bndy          , PERV_TYPE }, // 9
    { PERV::perv_pll_bndy_bucket_1 , PERV_TYPE }, // 10
    { PERV::perv_pll_bndy_bucket_2 , PERV_TYPE }, // 11
    { PERV::perv_pll_bndy_bucket_3 , PERV_TYPE }, // 12
    { PERV::perv_pll_bndy_bucket_4 , PERV_TYPE }, // 13
    { PERV::perv_pll_bndy_bucket_5 , PERV_TYPE }, // 14
    { PERV::perv_pll_func          , PERV_TYPE }, // 15
    { PERV::perv_repr              , PERV_TYPE }, // 16
    { PERV::occ_repr               , PERV_TYPE }, // 17
    { PERV::sbe_fure               , PERV_TYPE }, // 18
    { PERV::sbe_gptr               , PERV_TYPE }, // 19
    { PERV::sbe_repr               , PERV_TYPE }, // 20
    { N0::n0_fure                  , N0_TYPE   }, // 21
    { N0::n0_gptr                  , N0_TYPE   }, // 22
    { N0::n0_time                  , N0_TYPE   }, // 23
    { N0::n0_nx_fure               , N0_TYPE   }, // 24
    { N0::n0_nx_gptr               , N0_TYPE   }, // 25
    { N0::n0_nx_time               , N0_TYPE   }, // 26
    { N0::n0_cxa0_fure             , N0_TYPE   }, // 27
    { N0::n0_cxa0_gptr             , N0_TYPE   }, // 28
    { N0::n0_cxa0_time             , N0_TYPE   }, // 29
    { N0::n0_repr                  , N0_TYPE   }, // 30
    { N0::n0_nx_repr               , N0_TYPE   }, // 31
    { N0::n0_cxa0_repr             , N0_TYPE   }, // 32
    { N1::n1_fure                  , N1_TYPE   }, // 33
    { N1::n1_gptr                  , N1_TYPE   }, // 34
    { N1::n1_time                  , N1_TYPE   }, // 35
    { N1::n1_ioo0_fure             , N1_TYPE   }, // 36
    { N1::n1_ioo0_gptr             , N1_TYPE   }, // 37
    { N1::n1_ioo0_time             , N1_TYPE   }, // 38
    { N1::n1_ioo1_fure             , N1_TYPE   }, // 39
    { N1::n1_ioo1_gptr             , N1_TYPE   }, // 40
    { N1::n1_ioo1_time             , N1_TYPE   }, // 41
    { N1::n1_mcs23_fure            , N1_TYPE   }, // 42
    { N1::n1_mcs23_gptr            , N1_TYPE   }, // 43
    { N1::n1_mcs23_time            , N1_TYPE   }, // 44
    { N1::n1_repr                  , N1_TYPE   }, // 45
    { N1::n1_ioo0_repr             , N1_TYPE   }, // 46
    { N1::n1_ioo1_repr             , N1_TYPE   }, // 47
    { N1::n1_mcs23_repr            , N1_TYPE   }, // 48
    { N2::n2_fure                  , N2_TYPE   }, // 49
    { N2::n2_gptr                  , N2_TYPE   }, // 50
    { N2::n2_time                  , N2_TYPE   }, // 51
    { N2::n2_cxa1_fure             , N2_TYPE   }, // 52
    { N2::n2_cxa1_gptr             , N2_TYPE   }, // 53
    { N2::n2_cxa1_time             , N2_TYPE   }, // 54
    { N2::n2_psi_fure              , N2_TYPE   }, // 55
    { N2::n2_psi_gptr              , N2_TYPE   }, // 56
    { N2::n2_psi_time              , N2_TYPE   }, // 57
    { N2::n2_repr                  , N2_TYPE   }, // 58
    { N2::n2_cxa1_repr             , N2_TYPE   }, // 59
    { INVALID_RING_OFFSET          , N2_TYPE   }, // 60
    { INVALID_RING_OFFSET          , N2_TYPE   }, // 61
    { N3::n3_fure                  , N3_TYPE   }, // 62
    { N3::n3_gptr                  , N3_TYPE   }, // 63
    { N3::n3_time                  , N3_TYPE   }, // 64
    { N3::n3_mcs01_fure            , N3_TYPE   }, // 65
    { N3::n3_mcs01_gptr            , N3_TYPE   }, // 66
    { N3::n3_mcs01_time            , N3_TYPE   }, // 67
    { N3::n3_np_fure               , N3_TYPE   }, // 68
    { N3::n3_np_gptr               , N3_TYPE   }, // 69
    { N3::n3_np_time               , N3_TYPE   }, // 70
    { N3::n3_repr                  , N3_TYPE   }, // 71
    { N3::n3_mcs01_repr            , N3_TYPE   }, // 72
    { N3::n3_np_repr               , N3_TYPE   }, // 73
    { N3::n3_br_fure               , N3_TYPE   }, // 74
    { XB::xb_fure                  , XB_TYPE   }, // 75
    { XB::xb_gptr                  , XB_TYPE   }, // 76
    { XB::xb_time                  , XB_TYPE   }, // 77
    { XB::xb_io0_fure              , XB_TYPE   }, // 78
    { XB::xb_io0_gptr              , XB_TYPE   }, // 79
    { XB::xb_io0_time              , XB_TYPE   }, // 80
    { XB::xb_io1_fure              , XB_TYPE   }, // 81
    { XB::xb_io1_gptr              , XB_TYPE   }, // 82
    { XB::xb_io1_time              , XB_TYPE   }, // 83
    { XB::xb_io2_fure              , XB_TYPE   }, // 84
    { XB::xb_io2_gptr              , XB_TYPE   }, // 85
    { XB::xb_io2_time              , XB_TYPE   }, // 86
    { XB::xb_pll_gptr              , XB_TYPE   }, // 87
    { XB::xb_pll_bndy              , XB_TYPE   }, // 88
    { XB::xb_pll_func              , XB_TYPE   }, // 89
    { XB::xb_repr                  , XB_TYPE   }, // 90
    { XB::xb_io0_repr              , XB_TYPE   }, // 91
    { XB::xb_io1_repr              , XB_TYPE   }, // 92
    { XB::xb_io2_repr              , XB_TYPE   }, // 93
    { INVALID_RING_OFFSET          , XB_TYPE   }, // 94
    { INVALID_RING_OFFSET          , XB_TYPE   }, // 95
    { MC::mc_fure                  , MC_TYPE   }, // 96
    { MC::mc_gptr                  , MC_TYPE   }, // 97
    { MC::mc_time                  , MC_TYPE   }, // 98
    { MC::mc_iom01_fure            , MC_TYPE   }, // 99
    { MC::mc_iom01_gptr            , MC_TYPE   }, // 100
    { MC::mc_iom01_time            , MC_TYPE   }, // 101
    { MC::mc_iom23_fure            , MC_TYPE   }, // 102
    { MC::mc_iom23_gptr            , MC_TYPE   }, // 103
    { MC::mc_iom23_time            , MC_TYPE   }, // 104
    { MC::mc_pll_gptr              , MC_TYPE   }, // 105
    { MC::mc_pll_bndy              , MC_TYPE   }, // 106
    { MC::mc_pll_bndy_bucket_1     , MC_TYPE   }, // 107
    { MC::mc_pll_bndy_bucket_2     , MC_TYPE   }, // 108
    { MC::mc_pll_bndy_bucket_3     , MC_TYPE   }, // 109
    { MC::mc_pll_bndy_bucket_4     , MC_TYPE   }, // 110
    { MC::mc_pll_bndy_bucket_5     , MC_TYPE   }, // 111
    { MC::mc_pll_func              , MC_TYPE   }, // 112
    { MC::mc_repr                  , MC_TYPE   }, // 113
    { INVALID_RING_OFFSET          , MC_TYPE   }, // 114
    { MC::mc_iom23_repr            , MC_TYPE   }, // 115
    { OB0::ob0_pll_bndy            , OB0_TYPE  }, // 116
    { OB0::ob0_pll_bndy_bucket_1   , OB0_TYPE  }, // 117
    { OB0::ob0_pll_bndy_bucket_2   , OB0_TYPE  }, // 118
    { OB0::ob0_gptr                , OB0_TYPE  }, // 119
    { OB0::ob0_time                , OB0_TYPE  }, // 120
    { OB0::ob0_pll_gptr            , OB0_TYPE  }, // 121
    { OB0::ob0_fure                , OB0_TYPE  }, // 122
    { OB0::ob0_pll_bndy_bucket_3   , OB0_TYPE  }, // 123
    { OB0::ob0_repr                , OB0_TYPE  }, // 124
    { OB1::ob1_pll_bndy            , OB1_TYPE  }, // 125
    { OB1::ob1_pll_bndy_bucket_1   , OB1_TYPE  }, // 126
    { OB1::ob1_pll_bndy_bucket_2   , OB1_TYPE  }, // 127
    { OB1::ob1_gptr                , OB1_TYPE  }, // 128
    { OB1::ob1_time                , OB1_TYPE  }, // 129
    { OB1::ob1_pll_gptr            , OB1_TYPE  }, // 130
    { OB1::ob1_fure                , OB1_TYPE  }, // 131
    { OB1::ob1_pll_bndy_bucket_3   , OB1_TYPE  }, // 132
    { OB1::ob1_repr                , OB1_TYPE  }, // 133
    { OB2::ob2_pll_bndy            , OB2_TYPE  }, // 134
    { OB2::ob2_pll_bndy_bucket_1   , OB2_TYPE  }, // 135
    { OB2::ob2_pll_bndy_bucket_2   , OB2_TYPE  }, // 136
    { OB2::ob2_gptr                , OB2_TYPE  }, // 137
    { OB2::ob2_time                , OB2_TYPE  }, // 138
    { OB2::ob2_pll_gptr            , OB2_TYPE  }, // 139
    { OB2::ob2_fure                , OB2_TYPE  }, // 140
    { OB2::ob2_pll_bndy_bucket_3   , OB2_TYPE  }, // 141
    { OB2::ob2_repr                , OB2_TYPE  }, // 142
    { OB3::ob3_pll_bndy            , OB3_TYPE  }, // 143
    { OB3::ob3_pll_bndy_bucket_1   , OB3_TYPE  }, // 144
    { OB3::ob3_pll_bndy_bucket_2   , OB3_TYPE  }, // 145
    { OB3::ob3_gptr                , OB3_TYPE  }, // 146
    { OB3::ob3_time                , OB3_TYPE  }, // 147
    { OB3::ob3_pll_gptr            , OB3_TYPE  }, // 148
    { OB3::ob3_fure                , OB3_TYPE  }, // 149
    { OB3::ob3_pll_bndy_bucket_3   , OB3_TYPE  }, // 150
    { OB3::ob3_repr                , OB3_TYPE  }, // 151
    { INVALID_RING_OFFSET          , OB3_TYPE  }, // 152
    { INVALID_RING_OFFSET          , OB3_TYPE  }, // 153
    { PCI0::pci0_fure              , PCI0_TYPE }, // 154
    { PCI0::pci0_gptr              , PCI0_TYPE }, // 155
    { PCI0::pci0_time              , PCI0_TYPE }, // 156
    { PCI0::pci0_pll_bndy          , PCI0_TYPE }, // 157
    { PCI0::pci0_pll_gptr          , PCI0_TYPE }, // 158
    { PCI0::pci0_repr              , PCI0_TYPE }, // 159
    { PCI1::pci1_fure              , PCI1_TYPE }, // 160
    { PCI1::pci1_gptr              , PCI1_TYPE }, // 161
    { PCI1::pci1_time              , PCI1_TYPE }, // 162
    { PCI1::pci1_pll_bndy          , PCI1_TYPE }, // 163
    { PCI1::pci1_pll_gptr          , PCI1_TYPE }, // 164
    { PCI1::pci1_repr              , PCI1_TYPE }, // 165
    { PCI2::pci2_fure              , PCI2_TYPE }, // 166
    { PCI2::pci2_gptr              , PCI2_TYPE }, // 167
    { PCI2::pci2_time              , PCI2_TYPE }, // 168
    { PCI2::pci2_pll_bndy          , PCI2_TYPE }, // 169
    { PCI2::pci2_pll_gptr          , PCI2_TYPE }, // 170
    { PCI2::pci2_repr              , PCI2_TYPE }, // 171
    { EQ::eq_fure                  , EQ_TYPE   }, // 172
    { EQ::eq_gptr                  , EQ_TYPE   }, // 173
    { EQ::eq_time                  , EQ_TYPE   }, // 174
    { EQ::eq_inex                  , EQ_TYPE   }, // 175
    { EQ::ex_l3_fure               , EQ_TYPE   }, // 176
    { EQ::ex_l3_gptr               , EQ_TYPE   }, // 177
    { EQ::ex_l3_time               , EQ_TYPE   }, // 178
    { EQ::ex_l2_mode               , EQ_TYPE   }, // 179
    { EQ::ex_l2_fure               , EQ_TYPE   }, // 180
    { EQ::ex_l2_gptr               , EQ_TYPE   }, // 181
    { EQ::ex_l2_time               , EQ_TYPE   }, // 182
    { EQ::ex_l3_refr_fure          , EQ_TYPE   }, // 183
    { EQ::ex_l3_refr_gptr          , EQ_TYPE   }, // 184
    { EQ::ex_l3_refr_time          , EQ_TYPE   }, // 185
    { EQ::eq_ana_func              , EQ_TYPE   }, // 186
    { EQ::eq_ana_gptr              , EQ_TYPE   }, // 187
    { EQ::eq_dpll_func             , EQ_TYPE   }, // 188
    { EQ::eq_dpll_gptr             , EQ_TYPE   }, // 189
    { EQ::eq_dpll_mode             , EQ_TYPE   }, // 190
    { EQ::eq_ana_bndy              , EQ_TYPE   }, // 191
    { EQ::eq_ana_bndy_bucket_0     , EQ_TYPE   }, // 192
    { EQ::eq_ana_bndy_bucket_1     , EQ_TYPE   }, // 193
    { EQ::eq_ana_bndy_bucket_2     , EQ_TYPE   }, // 194
    { EQ::eq_ana_bndy_bucket_3     , EQ_TYPE   }, // 195
    { EQ::eq_ana_bndy_bucket_4     , EQ_TYPE   }, // 196
    { EQ::eq_ana_bndy_bucket_5     , EQ_TYPE   }, // 197
    { EQ::eq_ana_bndy_bucket_6     , EQ_TYPE   }, // 198
    { EQ::eq_ana_bndy_bucket_7     , EQ_TYPE   }, // 199
    { EQ::eq_ana_bndy_bucket_8     , EQ_TYPE   }, // 200
    { EQ::eq_ana_bndy_bucket_9     , EQ_TYPE   }, // 201
    { EQ::eq_ana_bndy_bucket_10    , EQ_TYPE   }, // 202
    { EQ::eq_ana_bndy_bucket_11    , EQ_TYPE   }, // 203
    { EQ::eq_ana_bndy_bucket_12    , EQ_TYPE   }, // 204
    { EQ::eq_ana_bndy_bucket_13    , EQ_TYPE   }, // 205
    { EQ::eq_ana_bndy_bucket_14    , EQ_TYPE   }, // 206
    { EQ::eq_ana_bndy_bucket_15    , EQ_TYPE   }, // 207
    { EQ::eq_ana_bndy_bucket_16    , EQ_TYPE   }, // 208
    { EQ::eq_ana_bndy_bucket_17    , EQ_TYPE   }, // 209
    { EQ::eq_ana_bndy_bucket_18    , EQ_TYPE   }, // 210
    { EQ::eq_ana_bndy_bucket_19    , EQ_TYPE   }, // 211
    { EQ::eq_ana_bndy_bucket_20    , EQ_TYPE   }, // 212
    { EQ::eq_ana_bndy_bucket_21    , EQ_TYPE   }, // 213
    { EQ::eq_ana_bndy_bucket_22    , EQ_TYPE   }, // 214
    { EQ::eq_ana_bndy_bucket_23    , EQ_TYPE   }, // 215
    { EQ::eq_ana_bndy_bucket_24    , EQ_TYPE   }, // 216
    { EQ::eq_ana_bndy_bucket_25    , EQ_TYPE   }, // 217
    { EQ::eq_ana_bndy_bucket_l3dcc , EQ_TYPE   }, // 218
    { EQ::eq_ana_mode              , EQ_TYPE   }, // 219
    { EQ::eq_repr                  , EQ_TYPE   }, // 220
    { EQ::ex_l3_repr               , EQ_TYPE   }, // 221
    { EQ::ex_l2_repr               , EQ_TYPE   }, // 222
    { EQ::ex_l3_refr_repr          , EQ_TYPE   }, // 223
    { EC::ec_func                  , EC_TYPE   }, // 224
    { EC::ec_gptr                  , EC_TYPE   }, // 225
    { EC::ec_time                  , EC_TYPE   }, // 226
    { EC::ec_mode                  , EC_TYPE   }, // 227
    { EC::ec_repr                  , EC_TYPE   }, // 228
    { INVALID_RING_OFFSET          , EQ_TYPE   }, // 229
    { INVALID_RING_OFFSET          , EQ_TYPE   }, // 230
    { EC::ec_abst                  , EC_TYPE   }, // 231
    { EQ::eq_ana_bndy_bucket_26    , EQ_TYPE   }, // 232
    { EQ::eq_ana_bndy_bucket_27    , EQ_TYPE   }, // 233
    { EQ::eq_ana_bndy_bucket_28    , EQ_TYPE   }, // 234
    { EQ::eq_ana_bndy_bucket_29    , EQ_TYPE   }, // 235
    { EQ::eq_ana_bndy_bucket_30    , EQ_TYPE   }, // 236
    { EQ::eq_ana_bndy_bucket_31    , EQ_TYPE   }, // 237
    { EQ::eq_ana_bndy_bucket_32    , EQ_TYPE   }, // 238
    { EQ::eq_ana_bndy_bucket_33    , EQ_TYPE   }, // 239
    { EQ::eq_ana_bndy_bucket_34    , EQ_TYPE   }, // 240
    { EQ::eq_ana_bndy_bucket_35    , EQ_TYPE   }, // 241
    { EQ::eq_ana_bndy_bucket_36    , EQ_TYPE   }, // 242
    { EQ::eq_ana_bndy_bucket_37    , EQ_TYPE   }, // 243
    { EQ::eq_ana_bndy_bucket_38    , EQ_TYPE   }, // 244
    { EQ::eq_ana_bndy_bucket_39    , EQ_TYPE   }, // 245
    { EQ::eq_ana_bndy_bucket_40    , EQ_TYPE   }, // 246
    { EQ::eq_ana_bndy_bucket_41    , EQ_TYPE   }, // 247
    { EQ::eq_inex_bucket_1         , EQ_TYPE   }, // 248
    { EQ::eq_inex_bucket_2         , EQ_TYPE   }, // 249
    { EQ::eq_inex_bucket_3         , EQ_TYPE   }, // 250
    { EQ::eq_inex_bucket_4         , EQ_TYPE   }, // 251
    { EC::ec_cmsk                  , EC_TYPE   }, // 252
    { PERV::perv_pll_bndy_flt_1    , PERV_TYPE }, // 253
    { PERV::perv_pll_bndy_flt_2    , PERV_TYPE }, // 254
    { PERV::perv_pll_bndy_flt_3    , PERV_TYPE }, // 255
    { PERV::perv_pll_bndy_flt_4    , PERV_TYPE }, // 256
    { MC::mc_omi0_fure             , MC_TYPE   }, // 257
    { MC::mc_omi0_gptr             , MC_TYPE   }, // 258
    { MC::mc_omi1_fure             , MC_TYPE   }, // 259
    { MC::mc_omi1_gptr             , MC_TYPE   }, // 260
    { MC::mc_omi2_fure             , MC_TYPE   }, // 261
    { MC::mc_omi2_gptr             , MC_TYPE   }, // 262
    { MC::mc_omippe_fure           , MC_TYPE   }, // 263
    { MC::mc_omippe_gptr           , MC_TYPE   }, // 264
    { MC::mc_omippe_time           , MC_TYPE   }, // 265
    { MC::mc_omippe_repr           , MC_TYPE   }, // 266
};
#endif


// Returns data structure assocated with chipletType
int
ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData);


#endif
