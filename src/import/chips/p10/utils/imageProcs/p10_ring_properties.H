/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ring_properties.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
#ifndef _P10_RING_PROPERTIES_H_
#define _P10_RING_PROPERTIES_H_

namespace PERV
{
enum RingOffset
{
    // Common Rings
    perv_fure                = 0,
    perv_occ_gptr            = 1,
    perv_occ_time            = 2,
    sbe_fure                 = 3,
    sbe_gptr                 = 4,
    sbe_time                 = 5,
    occ_fure                 = 6,
    perv_dpll_func           = 7,
    perv_dpll_bndy           = 8,
    perv_dpll_gptr           = 9,
    perv_pll_func            = 10,
    perv_pll_bndy            = 11,
    perv_pll_gptr            = 12,
    // Instance Rings
    perv_occ_repr            = (0 | INSTANCE_RING_MARK),
    sbe_repr                 = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x01, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    13, // 13 common rings for PERV Chiplet
    2,  // 2 instance specific rings for PERV Chiplet
};
}; // end of namespace PERV

namespace N0
{
enum RingOffset
{
    // Common Rings
    n0_fure                  = 0,
    n0_gptr                  = 1,
    n0_time                  = 2,
    // Instance Rings
    n0_repr                  = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x02, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    3,  // 3 common rings for N0 Chiplet
    1,  // 1 instance specific rings for N0 Chiplet
};
}; // end of namespace N0

namespace N1
{
enum RingOffset
{
    // Common Rings
    n1_fure                  = 0,
    n1_gptr                  = 1,
    n1_time                  = 2,
    n1_nmmu1_fure            = 3,
    n1_nmmu1_gptr            = 4,
    n1_nmmu1_time            = 5,
    // Instance Rings
    n1_repr                  = (0 | INSTANCE_RING_MARK),
    n1_nmmu1_repr            = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x03, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    6,  // 6 common rings for N1 Chiplet
    2,  // 2 instance specific rings for N1 Chiplet
};
}; // end of namespace N1

namespace PCI
{
enum RingOffset
{
    // Common Rings
    pci_fure                 = 0,
    pci_gptr                 = 1,
    pci_time                 = 2,
    pci_pll_func             = 3,
    pci_pll_bndy             = 4,
    pci_pll_gptr             = 5,
    // Instance Rings
    pci_repr                 = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x08, // Base chiplet/instance ID.
    2,  // Number of chiplet instances
    6,  // 6 common rings for PCI Chiplet
    1,  // 1 instance specific rings for PCI Chiplet
};
}; // end of namespace PCI

namespace MC
{
enum RingOffset
{
    // Common Rings
    mc_fure                  = 0,
    mc_gptr                  = 1,
    mc_time                  = 2,
    mc_pll_func              = 3,
    mc_pll_bndy              = 4,
    mc_pll_bndy_bucket_0     = 4,
    mc_pll_bndy_bucket_1     = 5,
    mc_pll_bndy_bucket_2     = 6,
    mc_pll_bndy_bucket_3     = 7,
    mc_pll_bndy_bucket_4     = 8,
    mc_pll_gptr              = 9,
    // Instance Rings
    mc_repr                  = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x0C, // Base chiplet/instance ID.
    4,  // Number of chiplet instances
    10, // 10 common rings for MC Chiplet
    1,  // 1 instance specific rings for MC Chiplet
};
}; // end of namespace MC

namespace PAU0
{
enum RingOffset
{
    // Common Rings
    pau0_fure                = 0,
    pau0_gptr                = 1,
    pau0_time                = 2,
    pau0_pau0_fure           = 3,
    pau0_pau0_gptr           = 4,
    pau0_pau0_time           = 5,
    // Instance Rings
    pau0_repr                = (0 | INSTANCE_RING_MARK),
    pau0_pau0_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x10, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    6,  // 6 common rings for PAU0 Chiplet
    2,  // 2 instance specific rings for PAU0 Chiplet
};
}; // end of namespace PAU0

namespace PAU1
{
enum RingOffset
{
    // Common Rings
    pau1_fure                = 0,
    pau1_gptr                = 1,
    pau1_time                = 2,
    pau1_pau3_fure           = 3,
    pau1_pau3_gptr           = 4,
    pau1_pau3_time           = 5,
    // Instance Rings
    pau1_repr                = (0 | INSTANCE_RING_MARK),
    pau1_pau3_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x11, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    6,  // 6 common rings for PAU1 Chiplet
    2,  // 2 instance specific rings for PAU1 Chiplet
};
}; // end of namespace PAU1

namespace PAU2
{
enum RingOffset
{
    // Common Rings
    pau2_fure                = 0,
    pau2_gptr                = 1,
    pau2_time                = 2,
    pau2_pau4_fure           = 3,
    pau2_pau4_gptr           = 4,
    pau2_pau4_time           = 5,
    pau2_pau5_fure           = 6,
    pau2_pau5_gptr           = 7,
    pau2_pau5_time           = 8,
    // Instance Rings
    pau2_repr                = (0 | INSTANCE_RING_MARK),
    pau2_pau4_repr           = (1 | INSTANCE_RING_MARK),
    pau2_pau5_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x12, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    9,  // 9 common rings for PAU2 Chiplet
    3,  // 3 instance specific rings for PAU2 Chiplet
};
}; // end of namespace PAU2

namespace PAU3
{
enum RingOffset
{
    // Common Rings
    pau3_fure                = 0,
    pau3_gptr                = 1,
    pau3_time                = 2,
    pau3_pau6_fure           = 3,
    pau3_pau6_gptr           = 4,
    pau3_pau6_time           = 5,
    pau3_pau7_fure           = 6,
    pau3_pau7_gptr           = 7,
    pau3_pau7_time           = 8,
    // Instance Rings
    pau3_repr                = (0 | INSTANCE_RING_MARK),
    pau3_pau6_repr           = (1 | INSTANCE_RING_MARK),
    pau3_pau7_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x13, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    9,  // 9 common rings for PAU3 Chiplet
    3,  // 3 instance specific rings for PAU3 Chiplet
};
}; // end of namespace PAU3

namespace AXON0
{
enum RingOffset
{
    // Common Rings
    iohs0_fure               = 0,
    iohs0_gptr               = 1,
    iohs0_time               = 2,
    iohs0_ndl_fure           = 3,
    iohs0_ndl_gptr           = 4,
    iohs0_ndl_time           = 5,
    iohs0_pdl_fure           = 6,
    iohs0_pdl_gptr           = 7,
    iohs0_pdl_time           = 8,
    iohs0_pll_func           = 9,
    iohs0_pll_bndy           = 10,
    iohs0_pll_bndy_bucket_0  = 10,
    iohs0_pll_bndy_bucket_1  = 11,
    iohs0_pll_bndy_bucket_2  = 12,
    iohs0_pll_bndy_bucket_3  = 13,
    iohs0_pll_bndy_bucket_4  = 14,
    iohs0_pll_bndy_bucket_5  = 15,
    iohs0_pll_bndy_bucket_6  = 16,
    iohs0_pll_bndy_bucket_7  = 17,
    iohs0_pll_gptr           = 18,
    // Instance Rings
    iohs0_repr               = (0 | INSTANCE_RING_MARK),
    iohs0_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs0_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x18, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON0 Chiplet
    3,  // 3 instance specific rings for AXON0 Chiplet
};
}; // end of namespace AXON0

namespace AXON1
{
enum RingOffset
{
    // Common Rings
    iohs1_fure               = 0,
    iohs1_gptr               = 1,
    iohs1_time               = 2,
    iohs1_ndl_fure           = 3,
    iohs1_ndl_gptr           = 4,
    iohs1_ndl_time           = 5,
    iohs1_pdl_fure           = 6,
    iohs1_pdl_gptr           = 7,
    iohs1_pdl_time           = 8,
    iohs1_pll_func           = 9,
    iohs1_pll_bndy           = 10,
    iohs1_pll_bndy_bucket_0  = 10,
    iohs1_pll_bndy_bucket_1  = 11,
    iohs1_pll_bndy_bucket_2  = 12,
    iohs1_pll_bndy_bucket_3  = 13,
    iohs1_pll_bndy_bucket_4  = 14,
    iohs1_pll_bndy_bucket_5  = 15,
    iohs1_pll_bndy_bucket_6  = 16,
    iohs1_pll_bndy_bucket_7  = 17,
    iohs1_pll_gptr           = 18,
    // Instance Rings
    iohs1_repr               = (0 | INSTANCE_RING_MARK),
    iohs1_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs1_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x19, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON1 Chiplet
    3,  // 3 instance specific rings for AXON1 Chiplet
};
}; // end of namespace AXON1

namespace AXON2
{
enum RingOffset
{
    // Common Rings
    iohs2_fure               = 0,
    iohs2_gptr               = 1,
    iohs2_time               = 2,
    iohs2_ndl_fure           = 3,
    iohs2_ndl_gptr           = 4,
    iohs2_ndl_time           = 5,
    iohs2_pdl_fure           = 6,
    iohs2_pdl_gptr           = 7,
    iohs2_pdl_time           = 8,
    iohs2_pll_func           = 9,
    iohs2_pll_bndy           = 10,
    iohs2_pll_bndy_bucket_0  = 10,
    iohs2_pll_bndy_bucket_1  = 11,
    iohs2_pll_bndy_bucket_2  = 12,
    iohs2_pll_bndy_bucket_3  = 13,
    iohs2_pll_bndy_bucket_4  = 14,
    iohs2_pll_bndy_bucket_5  = 15,
    iohs2_pll_bndy_bucket_6  = 16,
    iohs2_pll_bndy_bucket_7  = 17,
    iohs2_pll_gptr           = 18,
    // Instance Rings
    iohs2_repr               = (0 | INSTANCE_RING_MARK),
    iohs2_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs2_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1A, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON2 Chiplet
    3,  // 3 instance specific rings for AXON2 Chiplet
};
}; // end of namespace AXON2

namespace AXON3
{
enum RingOffset
{
    // Common Rings
    iohs3_fure               = 0,
    iohs3_gptr               = 1,
    iohs3_time               = 2,
    iohs3_ndl_fure           = 3,
    iohs3_ndl_gptr           = 4,
    iohs3_ndl_time           = 5,
    iohs3_pdl_fure           = 6,
    iohs3_pdl_gptr           = 7,
    iohs3_pdl_time           = 8,
    iohs3_pll_func           = 9,
    iohs3_pll_bndy           = 10,
    iohs3_pll_bndy_bucket_0  = 10,
    iohs3_pll_bndy_bucket_1  = 11,
    iohs3_pll_bndy_bucket_2  = 12,
    iohs3_pll_bndy_bucket_3  = 13,
    iohs3_pll_bndy_bucket_4  = 14,
    iohs3_pll_bndy_bucket_5  = 15,
    iohs3_pll_bndy_bucket_6  = 16,
    iohs3_pll_bndy_bucket_7  = 17,
    iohs3_pll_gptr           = 18,
    // Instance Rings
    iohs3_repr               = (0 | INSTANCE_RING_MARK),
    iohs3_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs3_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1B, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON3 Chiplet
    3,  // 3 instance specific rings for AXON3 Chiplet
};
}; // end of namespace AXON3

namespace AXON4
{
enum RingOffset
{
    // Common Rings
    iohs4_fure               = 0,
    iohs4_gptr               = 1,
    iohs4_time               = 2,
    iohs4_ndl_fure           = 3,
    iohs4_ndl_gptr           = 4,
    iohs4_ndl_time           = 5,
    iohs4_pdl_fure           = 6,
    iohs4_pdl_gptr           = 7,
    iohs4_pdl_time           = 8,
    iohs4_pll_func           = 9,
    iohs4_pll_bndy           = 10,
    iohs4_pll_bndy_bucket_0  = 10,
    iohs4_pll_bndy_bucket_1  = 11,
    iohs4_pll_bndy_bucket_2  = 12,
    iohs4_pll_bndy_bucket_3  = 13,
    iohs4_pll_bndy_bucket_4  = 14,
    iohs4_pll_bndy_bucket_5  = 15,
    iohs4_pll_bndy_bucket_6  = 16,
    iohs4_pll_bndy_bucket_7  = 17,
    iohs4_pll_gptr           = 18,
    // Instance Rings
    iohs4_repr               = (0 | INSTANCE_RING_MARK),
    iohs4_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs4_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1C, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON4 Chiplet
    3,  // 3 instance specific rings for AXON4 Chiplet
};
}; // end of namespace AXON4

namespace AXON5
{
enum RingOffset
{
    // Common Rings
    iohs5_fure               = 0,
    iohs5_gptr               = 1,
    iohs5_time               = 2,
    iohs5_ndl_fure           = 3,
    iohs5_ndl_gptr           = 4,
    iohs5_ndl_time           = 5,
    iohs5_pdl_fure           = 6,
    iohs5_pdl_gptr           = 7,
    iohs5_pdl_time           = 8,
    iohs5_pll_func           = 9,
    iohs5_pll_bndy           = 10,
    iohs5_pll_bndy_bucket_0  = 10,
    iohs5_pll_bndy_bucket_1  = 11,
    iohs5_pll_bndy_bucket_2  = 12,
    iohs5_pll_bndy_bucket_3  = 13,
    iohs5_pll_bndy_bucket_4  = 14,
    iohs5_pll_bndy_bucket_5  = 15,
    iohs5_pll_bndy_bucket_6  = 16,
    iohs5_pll_bndy_bucket_7  = 17,
    iohs5_pll_gptr           = 18,
    // Instance Rings
    iohs5_repr               = (0 | INSTANCE_RING_MARK),
    iohs5_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs5_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1D, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON5 Chiplet
    3,  // 3 instance specific rings for AXON5 Chiplet
};
}; // end of namespace AXON5

namespace AXON6
{
enum RingOffset
{
    // Common Rings
    iohs6_fure               = 0,
    iohs6_gptr               = 1,
    iohs6_time               = 2,
    iohs6_ndl_fure           = 3,
    iohs6_ndl_gptr           = 4,
    iohs6_ndl_time           = 5,
    iohs6_pdl_fure           = 6,
    iohs6_pdl_gptr           = 7,
    iohs6_pdl_time           = 8,
    iohs6_pll_func           = 9,
    iohs6_pll_bndy           = 10,
    iohs6_pll_bndy_bucket_0  = 10,
    iohs6_pll_bndy_bucket_1  = 11,
    iohs6_pll_bndy_bucket_2  = 12,
    iohs6_pll_bndy_bucket_3  = 13,
    iohs6_pll_bndy_bucket_4  = 14,
    iohs6_pll_bndy_bucket_5  = 15,
    iohs6_pll_bndy_bucket_6  = 16,
    iohs6_pll_bndy_bucket_7  = 17,
    iohs6_pll_gptr           = 18,
    // Instance Rings
    iohs6_repr               = (0 | INSTANCE_RING_MARK),
    iohs6_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs6_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1E, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON6 Chiplet
    3,  // 3 instance specific rings for AXON6 Chiplet
};
}; // end of namespace AXON6

namespace AXON7
{
enum RingOffset
{
    // Common Rings
    iohs7_fure               = 0,
    iohs7_gptr               = 1,
    iohs7_time               = 2,
    iohs7_ndl_fure           = 3,
    iohs7_ndl_gptr           = 4,
    iohs7_ndl_time           = 5,
    iohs7_pdl_fure           = 6,
    iohs7_pdl_gptr           = 7,
    iohs7_pdl_time           = 8,
    iohs7_pll_func           = 9,
    iohs7_pll_bndy           = 10,
    iohs7_pll_bndy_bucket_0  = 10,
    iohs7_pll_bndy_bucket_1  = 11,
    iohs7_pll_bndy_bucket_2  = 12,
    iohs7_pll_bndy_bucket_3  = 13,
    iohs7_pll_bndy_bucket_4  = 14,
    iohs7_pll_bndy_bucket_5  = 15,
    iohs7_pll_bndy_bucket_6  = 16,
    iohs7_pll_bndy_bucket_7  = 17,
    iohs7_pll_gptr           = 18,
    // Instance Rings
    iohs7_repr               = (0 | INSTANCE_RING_MARK),
    iohs7_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs7_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1F, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    19, // 19 common rings for AXON7 Chiplet
    3,  // 3 instance specific rings for AXON7 Chiplet
};
}; // end of namespace AXON7

namespace EQ
{
enum RingOffset
{
    // Common Rings
    eq_fure                  = 0,
    eq_gptr                  = 1,
    eq_time                  = 2,
    eq_cmsk                  = 3,
    eq_inex                  = 4,
    eq_mode                  = 5,
    ec_cl2_fure              = 6,
    ec_cl2_gptr              = 7,
    ec_cl2_time              = 8,
    ec_cl2_cmsk              = 9,
    ec_cl2_inex              = 10,
    ec_cl2_mode              = 11,
    ec_mma_fure              = 12,
    ec_mma_gptr              = 13,
    ec_mma_time              = 14,
    ec_mma_cmsk              = 15,
    ec_mma_inex              = 16,
    ec_l3_fure               = 17,
    ec_l3_gptr               = 18,
    ec_l3_time               = 19,
    ec_l3_cmsk               = 20,
    ec_l3_inex               = 21,
    ec_l3_mode               = 22,
    // Instance Rings
    eq_repr                  = (0 | INSTANCE_RING_MARK),
    ec_cl2_repr              = (1 | INSTANCE_RING_MARK),
    ec1_cl2_repr             = (2 | INSTANCE_RING_MARK),
    ec2_cl2_repr             = (3 | INSTANCE_RING_MARK),
    ec3_cl2_repr             = (4 | INSTANCE_RING_MARK),
    ec_mma_repr              = (5 | INSTANCE_RING_MARK),
    ec1_mma_repr             = (6 | INSTANCE_RING_MARK),
    ec2_mma_repr             = (7 | INSTANCE_RING_MARK),
    ec3_mma_repr             = (8 | INSTANCE_RING_MARK),
    ec_l3_repr               = (9 | INSTANCE_RING_MARK),
    ec1_l3_repr              = (10 | INSTANCE_RING_MARK),
    ec2_l3_repr              = (11 | INSTANCE_RING_MARK),
    ec3_l3_repr              = (12 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x20, // Base chiplet/instance ID.
    8,  // Number of chiplet instances
    23, // 23 common rings for EQ Chiplet
    13, // 13 instance specific rings for EQ Chiplet
};
}; // end of namespace EQ


#ifndef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { "perv_fure"               , 0x0103400F, PERV::perv_fure             , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 0
    { "perv_occ_gptr"           , 0x01034802, PERV::perv_occ_gptr         , PERV_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 1
    { "perv_occ_repr"           , 0x01034806, PERV::perv_occ_repr         , PERV_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 2
    { "perv_occ_time"           , 0x01034807, PERV::perv_occ_time         , PERV_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 3
    { "sbe_fure"                , 0x0103200F, PERV::sbe_fure              , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 4
    { "sbe_gptr"                , 0x01032002, PERV::sbe_gptr              , PERV_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 5
    { "sbe_repr"                , 0x01032006, PERV::sbe_repr              , PERV_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 6
    { "sbe_time"                , 0x01032007, PERV::sbe_time              , PERV_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 7
    { "occ_fure"                , 0x0103080F, PERV::occ_fure              , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 8
    { "perv_dpll_func"          , 0x01030060, PERV::perv_dpll_func        , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 9
    { "perv_dpll_bndy"          , 0x01030068, PERV::perv_dpll_bndy        , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 10
    { "perv_dpll_gptr"          , 0x01030062, PERV::perv_dpll_gptr        , PERV_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 11
    { "perv_pll_func"           , 0x01030010, PERV::perv_pll_func         , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 12
    { "perv_pll_bndy"           , 0x01030018, PERV::perv_pll_bndy         , PERV_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 13
    { "perv_pll_gptr"           , 0x01030012, PERV::perv_pll_gptr         , PERV_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 14
    { "n0_fure"                 , 0x0203640F, N0::n0_fure                 , N0_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 15
    { "n0_gptr"                 , 0x02036402, N0::n0_gptr                 , N0_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 16
    { "n0_repr"                 , 0x02036406, N0::n0_repr                 , N0_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 17
    { "n0_time"                 , 0x02036407, N0::n0_time                 , N0_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 18
    { "n1_fure"                 , 0x0303550F, N1::n1_fure                 , N1_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 19
    { "n1_gptr"                 , 0x03035502, N1::n1_gptr                 , N1_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 20
    { "n1_repr"                 , 0x03035506, N1::n1_repr                 , N1_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 21
    { "n1_time"                 , 0x03035507, N1::n1_time                 , N1_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 22
    { "n1_nmmu1_fure"           , 0x0303020F, N1::n1_nmmu1_fure           , N1_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 23
    { "n1_nmmu1_gptr"           , 0x03030202, N1::n1_nmmu1_gptr           , N1_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 24
    { "n1_nmmu1_repr"           , 0x03030206, N1::n1_nmmu1_repr           , N1_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 25
    { "n1_nmmu1_time"           , 0x03030207, N1::n1_nmmu1_time           , N1_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 26
    { "pci_fure"                , 0x08F37F8F, PCI::pci_fure               , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 27
    { "pci_gptr"                , 0x08F37F82, PCI::pci_gptr               , PCI_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 28
    { "pci_repr"                , 0x08F37F86, PCI::pci_repr               , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 29
    { "pci_time"                , 0x08F37F87, PCI::pci_time               , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 30
    { "pci_pll_func"            , 0x08030010, PCI::pci_pll_func           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 31
    { "pci_pll_bndy"            , 0x08030018, PCI::pci_pll_bndy           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 32
    { "pci_pll_gptr"            , 0x08030012, PCI::pci_pll_gptr           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 33
    { "mc_fure"                 , 0x0C036F0F, MC::mc_fure                 , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 34
    { "mc_gptr"                 , 0x0C036F02, MC::mc_gptr                 , MC_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 35
    { "mc_repr"                 , 0x0C036F06, MC::mc_repr                 , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 36
    { "mc_time"                 , 0x0C036F07, MC::mc_time                 , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 37
    { "mc_pll_func"             , 0x0C030010, MC::mc_pll_func             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 38
    { "mc_pll_bndy"             , 0x0C030018, MC::mc_pll_bndy             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 39
    { "mc_pll_bndy_bucket_0"    , 0x0C030018, MC::mc_pll_bndy_bucket_0    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 40
    { "mc_pll_bndy_bucket_1"    , 0x0C030018, MC::mc_pll_bndy_bucket_1    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 41
    { "mc_pll_bndy_bucket_2"    , 0x0C030018, MC::mc_pll_bndy_bucket_2    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 42
    { "mc_pll_bndy_bucket_3"    , 0x0C030018, MC::mc_pll_bndy_bucket_3    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 43
    { "mc_pll_bndy_bucket_4"    , 0x0C030018, MC::mc_pll_bndy_bucket_4    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 44
    { "mc_pll_gptr"             , 0x0C030012, MC::mc_pll_gptr             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 45
    { "pau0_fure"               , 0x1003430F, PAU0::pau0_fure             , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 46
    { "pau0_gptr"               , 0x10034302, PAU0::pau0_gptr             , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 47
    { "pau0_repr"               , 0x10034306, PAU0::pau0_repr             , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 48
    { "pau0_time"               , 0x10034307, PAU0::pau0_time             , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 49
    { "pau0_pau0_fure"          , 0x1003200F, PAU0::pau0_pau0_fure        , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 50
    { "pau0_pau0_gptr"          , 0x10032002, PAU0::pau0_pau0_gptr        , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 51
    { "pau0_pau0_repr"          , 0x10032006, PAU0::pau0_pau0_repr        , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 52
    { "pau0_pau0_time"          , 0x10032007, PAU0::pau0_pau0_time        , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 53
    { "pau1_fure"               , 0x1103430F, PAU1::pau1_fure             , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 54
    { "pau1_gptr"               , 0x11034302, PAU1::pau1_gptr             , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 55
    { "pau1_repr"               , 0x11034306, PAU1::pau1_repr             , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 56
    { "pau1_time"               , 0x11034307, PAU1::pau1_time             , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 57
    { "pau1_pau3_fure"          , 0x1103200F, PAU1::pau1_pau3_fure        , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 58
    { "pau1_pau3_gptr"          , 0x11032002, PAU1::pau1_pau3_gptr        , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 59
    { "pau1_pau3_repr"          , 0x11032006, PAU1::pau1_pau3_repr        , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 60
    { "pau1_pau3_time"          , 0x11032007, PAU1::pau1_pau3_time        , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 61
    { "pau2_fure"               , 0x1203430F, PAU2::pau2_fure             , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 62
    { "pau2_gptr"               , 0x12034302, PAU2::pau2_gptr             , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 63
    { "pau2_repr"               , 0x12034306, PAU2::pau2_repr             , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 64
    { "pau2_time"               , 0x12034307, PAU2::pau2_time             , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 65
    { "pau2_pau4_fure"          , 0x1203200F, PAU2::pau2_pau4_fure        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 66
    { "pau2_pau4_gptr"          , 0x12032002, PAU2::pau2_pau4_gptr        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 67
    { "pau2_pau4_repr"          , 0x12032006, PAU2::pau2_pau4_repr        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 68
    { "pau2_pau4_time"          , 0x12032007, PAU2::pau2_pau4_time        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 69
    { "pau2_pau5_fure"          , 0x1203100F, PAU2::pau2_pau5_fure        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 70
    { "pau2_pau5_gptr"          , 0x12031002, PAU2::pau2_pau5_gptr        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 71
    { "pau2_pau5_repr"          , 0x12031006, PAU2::pau2_pau5_repr        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 72
    { "pau2_pau5_time"          , 0x12031007, PAU2::pau2_pau5_time        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 73
    { "pau3_fure"               , 0x1303430F, PAU3::pau3_fure             , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 74
    { "pau3_gptr"               , 0x13034302, PAU3::pau3_gptr             , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 75
    { "pau3_repr"               , 0x13034306, PAU3::pau3_repr             , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 76
    { "pau3_time"               , 0x13034307, PAU3::pau3_time             , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 77
    { "pau3_pau6_fure"          , 0x1303200F, PAU3::pau3_pau6_fure        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 78
    { "pau3_pau6_gptr"          , 0x13032002, PAU3::pau3_pau6_gptr        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 79
    { "pau3_pau6_repr"          , 0x13032006, PAU3::pau3_pau6_repr        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 80
    { "pau3_pau6_time"          , 0x13032007, PAU3::pau3_pau6_time        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 81
    { "pau3_pau7_fure"          , 0x1303100F, PAU3::pau3_pau7_fure        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 82
    { "pau3_pau7_gptr"          , 0x13031002, PAU3::pau3_pau7_gptr        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 83
    { "pau3_pau7_repr"          , 0x13031006, PAU3::pau3_pau7_repr        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 84
    { "pau3_pau7_time"          , 0x13031007, PAU3::pau3_pau7_time        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 85
    { "iohs0_fure"              , 0x1803600F, AXON0::iohs0_fure           , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 86
    { "iohs0_gptr"              , 0x18036002, AXON0::iohs0_gptr           , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 87
    { "iohs0_repr"              , 0x18036006, AXON0::iohs0_repr           , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 88
    { "iohs0_time"              , 0x18036007, AXON0::iohs0_time           , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 89
    { "iohs0_ndl_fure"          , 0x1803040F, AXON0::iohs0_ndl_fure       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 90
    { "iohs0_ndl_gptr"          , 0x18030402, AXON0::iohs0_ndl_gptr       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 91
    { "iohs0_ndl_repr"          , 0x18030406, AXON0::iohs0_ndl_repr       , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 92
    { "iohs0_ndl_time"          , 0x18030407, AXON0::iohs0_ndl_time       , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 93
    { "iohs0_pdl_fure"          , 0x1803020F, AXON0::iohs0_pdl_fure       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 94
    { "iohs0_pdl_gptr"          , 0x18030202, AXON0::iohs0_pdl_gptr       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 95
    { "iohs0_pdl_repr"          , 0x18030206, AXON0::iohs0_pdl_repr       , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 96
    { "iohs0_pdl_time"          , 0x18030207, AXON0::iohs0_pdl_time       , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 97
    { "iohs0_pll_func"          , 0x18030010, AXON0::iohs0_pll_func       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 98
    { "iohs0_pll_bndy"          , 0x18030018, AXON0::iohs0_pll_bndy       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 99
    { "iohs0_pll_bndy_bucket_0" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 100
    { "iohs0_pll_bndy_bucket_1" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 101
    { "iohs0_pll_bndy_bucket_2" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 102
    { "iohs0_pll_bndy_bucket_3" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 103
    { "iohs0_pll_bndy_bucket_4" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 104
    { "iohs0_pll_bndy_bucket_5" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 105
    { "iohs0_pll_bndy_bucket_6" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 106
    { "iohs0_pll_bndy_bucket_7" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE, RCLS_EKB_RINGS                                        }, // 107
    { "iohs0_pll_gptr"          , 0x18030012, AXON0::iohs0_pll_gptr       , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 108
    { "iohs1_fure"              , 0x1903600F, AXON1::iohs1_fure           , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 109
    { "iohs1_gptr"              , 0x19036002, AXON1::iohs1_gptr           , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 110
    { "iohs1_repr"              , 0x19036006, AXON1::iohs1_repr           , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 111
    { "iohs1_time"              , 0x19036007, AXON1::iohs1_time           , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 112
    { "iohs1_ndl_fure"          , 0x1903040F, AXON1::iohs1_ndl_fure       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 113
    { "iohs1_ndl_gptr"          , 0x19030402, AXON1::iohs1_ndl_gptr       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 114
    { "iohs1_ndl_repr"          , 0x19030406, AXON1::iohs1_ndl_repr       , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 115
    { "iohs1_ndl_time"          , 0x19030407, AXON1::iohs1_ndl_time       , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 116
    { "iohs1_pdl_fure"          , 0x1903020F, AXON1::iohs1_pdl_fure       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 117
    { "iohs1_pdl_gptr"          , 0x19030202, AXON1::iohs1_pdl_gptr       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 118
    { "iohs1_pdl_repr"          , 0x19030206, AXON1::iohs1_pdl_repr       , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 119
    { "iohs1_pdl_time"          , 0x19030207, AXON1::iohs1_pdl_time       , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 120
    { "iohs1_pll_func"          , 0x19030010, AXON1::iohs1_pll_func       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 121
    { "iohs1_pll_bndy"          , 0x19030018, AXON1::iohs1_pll_bndy       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 122
    { "iohs1_pll_bndy_bucket_0" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_0, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 123
    { "iohs1_pll_bndy_bucket_1" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_1, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 124
    { "iohs1_pll_bndy_bucket_2" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_2, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 125
    { "iohs1_pll_bndy_bucket_3" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_3, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 126
    { "iohs1_pll_bndy_bucket_4" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_4, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 127
    { "iohs1_pll_bndy_bucket_5" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_5, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 128
    { "iohs1_pll_bndy_bucket_6" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_6, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 129
    { "iohs1_pll_bndy_bucket_7" , 0x19030018, AXON1::iohs1_pll_bndy_bucket_7, AXON1_TYPE, RCLS_EKB_RINGS                                        }, // 130
    { "iohs1_pll_gptr"          , 0x19030012, AXON1::iohs1_pll_gptr       , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 131
    { "iohs2_fure"              , 0x1A03600F, AXON2::iohs2_fure           , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 132
    { "iohs2_gptr"              , 0x1A036002, AXON2::iohs2_gptr           , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 133
    { "iohs2_repr"              , 0x1A036006, AXON2::iohs2_repr           , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 134
    { "iohs2_time"              , 0x1A036007, AXON2::iohs2_time           , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 135
    { "iohs2_ndl_fure"          , 0x1A03040F, AXON2::iohs2_ndl_fure       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 136
    { "iohs2_ndl_gptr"          , 0x1A030402, AXON2::iohs2_ndl_gptr       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 137
    { "iohs2_ndl_repr"          , 0x1A030406, AXON2::iohs2_ndl_repr       , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 138
    { "iohs2_ndl_time"          , 0x1A030407, AXON2::iohs2_ndl_time       , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 139
    { "iohs2_pdl_fure"          , 0x1A03020F, AXON2::iohs2_pdl_fure       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 140
    { "iohs2_pdl_gptr"          , 0x1A030202, AXON2::iohs2_pdl_gptr       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 141
    { "iohs2_pdl_repr"          , 0x1A030206, AXON2::iohs2_pdl_repr       , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 142
    { "iohs2_pdl_time"          , 0x1A030207, AXON2::iohs2_pdl_time       , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 143
    { "iohs2_pll_func"          , 0x1A030010, AXON2::iohs2_pll_func       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 144
    { "iohs2_pll_bndy"          , 0x1A030018, AXON2::iohs2_pll_bndy       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 145
    { "iohs2_pll_bndy_bucket_0" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_0, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 146
    { "iohs2_pll_bndy_bucket_1" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_1, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 147
    { "iohs2_pll_bndy_bucket_2" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_2, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 148
    { "iohs2_pll_bndy_bucket_3" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_3, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 149
    { "iohs2_pll_bndy_bucket_4" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_4, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 150
    { "iohs2_pll_bndy_bucket_5" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_5, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 151
    { "iohs2_pll_bndy_bucket_6" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_6, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 152
    { "iohs2_pll_bndy_bucket_7" , 0x1A030018, AXON2::iohs2_pll_bndy_bucket_7, AXON2_TYPE, RCLS_EKB_RINGS                                        }, // 153
    { "iohs2_pll_gptr"          , 0x1A030012, AXON2::iohs2_pll_gptr       , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 154
    { "iohs3_fure"              , 0x1B03600F, AXON3::iohs3_fure           , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 155
    { "iohs3_gptr"              , 0x1B036002, AXON3::iohs3_gptr           , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 156
    { "iohs3_repr"              , 0x1B036006, AXON3::iohs3_repr           , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 157
    { "iohs3_time"              , 0x1B036007, AXON3::iohs3_time           , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 158
    { "iohs3_ndl_fure"          , 0x1B03040F, AXON3::iohs3_ndl_fure       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 159
    { "iohs3_ndl_gptr"          , 0x1B030402, AXON3::iohs3_ndl_gptr       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 160
    { "iohs3_ndl_repr"          , 0x1B030406, AXON3::iohs3_ndl_repr       , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 161
    { "iohs3_ndl_time"          , 0x1B030407, AXON3::iohs3_ndl_time       , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 162
    { "iohs3_pdl_fure"          , 0x1B03020F, AXON3::iohs3_pdl_fure       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 163
    { "iohs3_pdl_gptr"          , 0x1B030202, AXON3::iohs3_pdl_gptr       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 164
    { "iohs3_pdl_repr"          , 0x1B030206, AXON3::iohs3_pdl_repr       , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 165
    { "iohs3_pdl_time"          , 0x1B030207, AXON3::iohs3_pdl_time       , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 166
    { "iohs3_pll_func"          , 0x1B030010, AXON3::iohs3_pll_func       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 167
    { "iohs3_pll_bndy"          , 0x1B030018, AXON3::iohs3_pll_bndy       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 168
    { "iohs3_pll_bndy_bucket_0" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_0, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 169
    { "iohs3_pll_bndy_bucket_1" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_1, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 170
    { "iohs3_pll_bndy_bucket_2" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_2, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 171
    { "iohs3_pll_bndy_bucket_3" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_3, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 172
    { "iohs3_pll_bndy_bucket_4" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_4, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 173
    { "iohs3_pll_bndy_bucket_5" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_5, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 174
    { "iohs3_pll_bndy_bucket_6" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_6, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 175
    { "iohs3_pll_bndy_bucket_7" , 0x1B030018, AXON3::iohs3_pll_bndy_bucket_7, AXON3_TYPE, RCLS_EKB_RINGS                                        }, // 176
    { "iohs3_pll_gptr"          , 0x1B030012, AXON3::iohs3_pll_gptr       , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 177
    { "iohs4_fure"              , 0x1C03600F, AXON4::iohs4_fure           , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 178
    { "iohs4_gptr"              , 0x1C036002, AXON4::iohs4_gptr           , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 179
    { "iohs4_repr"              , 0x1C036006, AXON4::iohs4_repr           , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 180
    { "iohs4_time"              , 0x1C036007, AXON4::iohs4_time           , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 181
    { "iohs4_ndl_fure"          , 0x1C03040F, AXON4::iohs4_ndl_fure       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 182
    { "iohs4_ndl_gptr"          , 0x1C030402, AXON4::iohs4_ndl_gptr       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 183
    { "iohs4_ndl_repr"          , 0x1C030406, AXON4::iohs4_ndl_repr       , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 184
    { "iohs4_ndl_time"          , 0x1C030407, AXON4::iohs4_ndl_time       , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 185
    { "iohs4_pdl_fure"          , 0x1C03020F, AXON4::iohs4_pdl_fure       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 186
    { "iohs4_pdl_gptr"          , 0x1C030202, AXON4::iohs4_pdl_gptr       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 187
    { "iohs4_pdl_repr"          , 0x1C030206, AXON4::iohs4_pdl_repr       , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 188
    { "iohs4_pdl_time"          , 0x1C030207, AXON4::iohs4_pdl_time       , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 189
    { "iohs4_pll_func"          , 0x1C030010, AXON4::iohs4_pll_func       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 190
    { "iohs4_pll_bndy"          , 0x1C030018, AXON4::iohs4_pll_bndy       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 191
    { "iohs4_pll_bndy_bucket_0" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_0, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 192
    { "iohs4_pll_bndy_bucket_1" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_1, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 193
    { "iohs4_pll_bndy_bucket_2" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_2, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 194
    { "iohs4_pll_bndy_bucket_3" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_3, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 195
    { "iohs4_pll_bndy_bucket_4" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_4, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 196
    { "iohs4_pll_bndy_bucket_5" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_5, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 197
    { "iohs4_pll_bndy_bucket_6" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_6, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 198
    { "iohs4_pll_bndy_bucket_7" , 0x1C030018, AXON4::iohs4_pll_bndy_bucket_7, AXON4_TYPE, RCLS_EKB_RINGS                                        }, // 199
    { "iohs4_pll_gptr"          , 0x1C030012, AXON4::iohs4_pll_gptr       , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 200
    { "iohs5_fure"              , 0x1D03600F, AXON5::iohs5_fure           , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 201
    { "iohs5_gptr"              , 0x1D036002, AXON5::iohs5_gptr           , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 202
    { "iohs5_repr"              , 0x1D036006, AXON5::iohs5_repr           , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 203
    { "iohs5_time"              , 0x1D036007, AXON5::iohs5_time           , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 204
    { "iohs5_ndl_fure"          , 0x1D03040F, AXON5::iohs5_ndl_fure       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 205
    { "iohs5_ndl_gptr"          , 0x1D030402, AXON5::iohs5_ndl_gptr       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 206
    { "iohs5_ndl_repr"          , 0x1D030406, AXON5::iohs5_ndl_repr       , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 207
    { "iohs5_ndl_time"          , 0x1D030407, AXON5::iohs5_ndl_time       , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 208
    { "iohs5_pdl_fure"          , 0x1D03020F, AXON5::iohs5_pdl_fure       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 209
    { "iohs5_pdl_gptr"          , 0x1D030202, AXON5::iohs5_pdl_gptr       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 210
    { "iohs5_pdl_repr"          , 0x1D030206, AXON5::iohs5_pdl_repr       , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 211
    { "iohs5_pdl_time"          , 0x1D030207, AXON5::iohs5_pdl_time       , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 212
    { "iohs5_pll_func"          , 0x1D030010, AXON5::iohs5_pll_func       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 213
    { "iohs5_pll_bndy"          , 0x1D030018, AXON5::iohs5_pll_bndy       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 214
    { "iohs5_pll_bndy_bucket_0" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_0, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 215
    { "iohs5_pll_bndy_bucket_1" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_1, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 216
    { "iohs5_pll_bndy_bucket_2" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_2, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 217
    { "iohs5_pll_bndy_bucket_3" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_3, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 218
    { "iohs5_pll_bndy_bucket_4" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_4, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 219
    { "iohs5_pll_bndy_bucket_5" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_5, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 220
    { "iohs5_pll_bndy_bucket_6" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_6, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 221
    { "iohs5_pll_bndy_bucket_7" , 0x1D030018, AXON5::iohs5_pll_bndy_bucket_7, AXON5_TYPE, RCLS_EKB_RINGS                                        }, // 222
    { "iohs5_pll_gptr"          , 0x1D030012, AXON5::iohs5_pll_gptr       , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 223
    { "iohs6_fure"              , 0x1E03600F, AXON6::iohs6_fure           , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 224
    { "iohs6_gptr"              , 0x1E036002, AXON6::iohs6_gptr           , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 225
    { "iohs6_repr"              , 0x1E036006, AXON6::iohs6_repr           , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 226
    { "iohs6_time"              , 0x1E036007, AXON6::iohs6_time           , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 227
    { "iohs6_ndl_fure"          , 0x1E03040F, AXON6::iohs6_ndl_fure       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 228
    { "iohs6_ndl_gptr"          , 0x1E030402, AXON6::iohs6_ndl_gptr       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 229
    { "iohs6_ndl_repr"          , 0x1E030406, AXON6::iohs6_ndl_repr       , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 230
    { "iohs6_ndl_time"          , 0x1E030407, AXON6::iohs6_ndl_time       , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 231
    { "iohs6_pdl_fure"          , 0x1E03020F, AXON6::iohs6_pdl_fure       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 232
    { "iohs6_pdl_gptr"          , 0x1E030202, AXON6::iohs6_pdl_gptr       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 233
    { "iohs6_pdl_repr"          , 0x1E030206, AXON6::iohs6_pdl_repr       , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 234
    { "iohs6_pdl_time"          , 0x1E030207, AXON6::iohs6_pdl_time       , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 235
    { "iohs6_pll_func"          , 0x1E030010, AXON6::iohs6_pll_func       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 236
    { "iohs6_pll_bndy"          , 0x1E030018, AXON6::iohs6_pll_bndy       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 237
    { "iohs6_pll_bndy_bucket_0" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_0, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 238
    { "iohs6_pll_bndy_bucket_1" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_1, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 239
    { "iohs6_pll_bndy_bucket_2" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_2, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 240
    { "iohs6_pll_bndy_bucket_3" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_3, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 241
    { "iohs6_pll_bndy_bucket_4" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_4, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 242
    { "iohs6_pll_bndy_bucket_5" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_5, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 243
    { "iohs6_pll_bndy_bucket_6" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_6, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 244
    { "iohs6_pll_bndy_bucket_7" , 0x1E030018, AXON6::iohs6_pll_bndy_bucket_7, AXON6_TYPE, RCLS_EKB_RINGS                                        }, // 245
    { "iohs6_pll_gptr"          , 0x1E030012, AXON6::iohs6_pll_gptr       , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 246
    { "iohs7_fure"              , 0x1F03600F, AXON7::iohs7_fure           , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 247
    { "iohs7_gptr"              , 0x1F036002, AXON7::iohs7_gptr           , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 248
    { "iohs7_repr"              , 0x1F036006, AXON7::iohs7_repr           , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 249
    { "iohs7_time"              , 0x1F036007, AXON7::iohs7_time           , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 250
    { "iohs7_ndl_fure"          , 0x1F03040F, AXON7::iohs7_ndl_fure       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 251
    { "iohs7_ndl_gptr"          , 0x1F030402, AXON7::iohs7_ndl_gptr       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 252
    { "iohs7_ndl_repr"          , 0x1F030406, AXON7::iohs7_ndl_repr       , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 253
    { "iohs7_ndl_time"          , 0x1F030407, AXON7::iohs7_ndl_time       , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 254
    { "iohs7_pdl_fure"          , 0x1F03020F, AXON7::iohs7_pdl_fure       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 255
    { "iohs7_pdl_gptr"          , 0x1F030202, AXON7::iohs7_pdl_gptr       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 256
    { "iohs7_pdl_repr"          , 0x1F030206, AXON7::iohs7_pdl_repr       , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 257
    { "iohs7_pdl_time"          , 0x1F030207, AXON7::iohs7_pdl_time       , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 258
    { "iohs7_pll_func"          , 0x1F030010, AXON7::iohs7_pll_func       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 259
    { "iohs7_pll_bndy"          , 0x1F030018, AXON7::iohs7_pll_bndy       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 260
    { "iohs7_pll_bndy_bucket_0" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_0, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 261
    { "iohs7_pll_bndy_bucket_1" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_1, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 262
    { "iohs7_pll_bndy_bucket_2" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_2, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 263
    { "iohs7_pll_bndy_bucket_3" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_3, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 264
    { "iohs7_pll_bndy_bucket_4" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_4, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 265
    { "iohs7_pll_bndy_bucket_5" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_5, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 266
    { "iohs7_pll_bndy_bucket_6" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_6, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 267
    { "iohs7_pll_bndy_bucket_7" , 0x1F030018, AXON7::iohs7_pll_bndy_bucket_7, AXON7_TYPE, RCLS_EKB_RINGS                                        }, // 268
    { "iohs7_pll_gptr"          , 0x1F030012, AXON7::iohs7_pll_gptr       , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 269
    { "eq_fure"                 , 0x2003403F, EQ::eq_fure                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 270
    { "eq_gptr"                 , 0x20034032, EQ::eq_gptr                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 271
    { "eq_repr"                 , 0x20034036, EQ::eq_repr                 , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_EQ                          }, // 272
    { "eq_time"                 , 0x20034037, EQ::eq_time                 , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 273
    { "eq_cmsk"                 , 0x2003403A, EQ::eq_cmsk                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 274
    { "eq_inex"                 , 0x2003403B, EQ::eq_inex                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 275
    { "eq_mode"                 , 0x20034031, EQ::eq_mode                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 276
    { "ec_cl2_fure"             , 0x2003200F, EQ::ec_cl2_fure             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 277
    { "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 278
    { "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 279
    { "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 280
    { "ec_cl2_cmsk"             , 0x2003200A, EQ::ec_cl2_cmsk             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 281
    { "ec_cl2_inex"             , 0x2003200B, EQ::ec_cl2_inex             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 282
    { "ec_cl2_mode"             , 0x20032001, EQ::ec_cl2_mode             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 283
    { "ec1_cl2_repr"            , 0x20031006, EQ::ec1_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 284
    { "ec2_cl2_repr"            , 0x20030806, EQ::ec2_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 285
    { "ec3_cl2_repr"            , 0x20030406, EQ::ec3_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 286
    { "ec_mma_fure"             , 0x2083000F, EQ::ec_mma_fure             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 287
    { "ec_mma_gptr"             , 0x20830002, EQ::ec_mma_gptr             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 288
    { "ec_mma_repr"             , 0x20830006, EQ::ec_mma_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 289
    { "ec_mma_time"             , 0x20830007, EQ::ec_mma_time             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 290
    { "ec_mma_cmsk"             , 0x2083000A, EQ::ec_mma_cmsk             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 291
    { "ec_mma_inex"             , 0x2083000B, EQ::ec_mma_inex             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 292
    { "ec1_mma_repr"            , 0x20430006, EQ::ec1_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 293
    { "ec2_mma_repr"            , 0x20230006, EQ::ec2_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 294
    { "ec3_mma_repr"            , 0x20130006, EQ::ec3_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 295
    { "ec_l3_fure"              , 0x2003020F, EQ::ec_l3_fure              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 296
    { "ec_l3_gptr"              , 0x20030202, EQ::ec_l3_gptr              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 297
    { "ec_l3_repr"              , 0x20030206, EQ::ec_l3_repr              , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 298
    { "ec_l3_time"              , 0x20030207, EQ::ec_l3_time              , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 299
    { "ec_l3_cmsk"              , 0x2003020A, EQ::ec_l3_cmsk              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 300
    { "ec_l3_inex"              , 0x2003020B, EQ::ec_l3_inex              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 301
    { "ec_l3_mode"              , 0x20030201, EQ::ec_l3_mode              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 302
    { "ec1_l3_repr"             , 0x20030106, EQ::ec1_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 303
    { "ec2_l3_repr"             , 0x20030086, EQ::ec2_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 304
    { "ec3_l3_repr"             , 0x20030046, EQ::ec3_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 305
};
#endif

#ifdef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { PERV::perv_fure             , PERV_TYPE }, // 0
    { PERV::perv_occ_gptr         , PERV_TYPE }, // 1
    { PERV::perv_occ_repr         , PERV_TYPE }, // 2
    { PERV::perv_occ_time         , PERV_TYPE }, // 3
    { PERV::sbe_fure              , PERV_TYPE }, // 4
    { PERV::sbe_gptr              , PERV_TYPE }, // 5
    { PERV::sbe_repr              , PERV_TYPE }, // 6
    { PERV::sbe_time              , PERV_TYPE }, // 7
    { PERV::occ_fure              , PERV_TYPE }, // 8
    { PERV::perv_dpll_func        , PERV_TYPE }, // 9
    { PERV::perv_dpll_bndy        , PERV_TYPE }, // 10
    { PERV::perv_dpll_gptr        , PERV_TYPE }, // 11
    { PERV::perv_pll_func         , PERV_TYPE }, // 12
    { PERV::perv_pll_bndy         , PERV_TYPE }, // 13
    { PERV::perv_pll_gptr         , PERV_TYPE }, // 14
    { N0::n0_fure                 , N0_TYPE   }, // 15
    { N0::n0_gptr                 , N0_TYPE   }, // 16
    { N0::n0_repr                 , N0_TYPE   }, // 17
    { N0::n0_time                 , N0_TYPE   }, // 18
    { N1::n1_fure                 , N1_TYPE   }, // 19
    { N1::n1_gptr                 , N1_TYPE   }, // 20
    { N1::n1_repr                 , N1_TYPE   }, // 21
    { N1::n1_time                 , N1_TYPE   }, // 22
    { N1::n1_nmmu1_fure           , N1_TYPE   }, // 23
    { N1::n1_nmmu1_gptr           , N1_TYPE   }, // 24
    { N1::n1_nmmu1_repr           , N1_TYPE   }, // 25
    { N1::n1_nmmu1_time           , N1_TYPE   }, // 26
    { PCI::pci_fure               , PCI_TYPE  }, // 27
    { PCI::pci_gptr               , PCI_TYPE  }, // 28
    { PCI::pci_repr               , PCI_TYPE  }, // 29
    { PCI::pci_time               , PCI_TYPE  }, // 30
    { PCI::pci_pll_func           , PCI_TYPE  }, // 31
    { PCI::pci_pll_bndy           , PCI_TYPE  }, // 32
    { PCI::pci_pll_gptr           , PCI_TYPE  }, // 33
    { MC::mc_fure                 , MC_TYPE   }, // 34
    { MC::mc_gptr                 , MC_TYPE   }, // 35
    { MC::mc_repr                 , MC_TYPE   }, // 36
    { MC::mc_time                 , MC_TYPE   }, // 37
    { MC::mc_pll_func             , MC_TYPE   }, // 38
    { MC::mc_pll_bndy             , MC_TYPE   }, // 39
    { MC::mc_pll_bndy_bucket_0    , MC_TYPE   }, // 40
    { MC::mc_pll_bndy_bucket_1    , MC_TYPE   }, // 41
    { MC::mc_pll_bndy_bucket_2    , MC_TYPE   }, // 42
    { MC::mc_pll_bndy_bucket_3    , MC_TYPE   }, // 43
    { MC::mc_pll_bndy_bucket_4    , MC_TYPE   }, // 44
    { MC::mc_pll_gptr             , MC_TYPE   }, // 45
    { PAU0::pau0_fure             , PAU0_TYPE }, // 46
    { PAU0::pau0_gptr             , PAU0_TYPE }, // 47
    { PAU0::pau0_repr             , PAU0_TYPE }, // 48
    { PAU0::pau0_time             , PAU0_TYPE }, // 49
    { PAU0::pau0_pau0_fure        , PAU0_TYPE }, // 50
    { PAU0::pau0_pau0_gptr        , PAU0_TYPE }, // 51
    { PAU0::pau0_pau0_repr        , PAU0_TYPE }, // 52
    { PAU0::pau0_pau0_time        , PAU0_TYPE }, // 53
    { PAU1::pau1_fure             , PAU1_TYPE }, // 54
    { PAU1::pau1_gptr             , PAU1_TYPE }, // 55
    { PAU1::pau1_repr             , PAU1_TYPE }, // 56
    { PAU1::pau1_time             , PAU1_TYPE }, // 57
    { PAU1::pau1_pau3_fure        , PAU1_TYPE }, // 58
    { PAU1::pau1_pau3_gptr        , PAU1_TYPE }, // 59
    { PAU1::pau1_pau3_repr        , PAU1_TYPE }, // 60
    { PAU1::pau1_pau3_time        , PAU1_TYPE }, // 61
    { PAU2::pau2_fure             , PAU2_TYPE }, // 62
    { PAU2::pau2_gptr             , PAU2_TYPE }, // 63
    { PAU2::pau2_repr             , PAU2_TYPE }, // 64
    { PAU2::pau2_time             , PAU2_TYPE }, // 65
    { PAU2::pau2_pau4_fure        , PAU2_TYPE }, // 66
    { PAU2::pau2_pau4_gptr        , PAU2_TYPE }, // 67
    { PAU2::pau2_pau4_repr        , PAU2_TYPE }, // 68
    { PAU2::pau2_pau4_time        , PAU2_TYPE }, // 69
    { PAU2::pau2_pau5_fure        , PAU2_TYPE }, // 70
    { PAU2::pau2_pau5_gptr        , PAU2_TYPE }, // 71
    { PAU2::pau2_pau5_repr        , PAU2_TYPE }, // 72
    { PAU2::pau2_pau5_time        , PAU2_TYPE }, // 73
    { PAU3::pau3_fure             , PAU3_TYPE }, // 74
    { PAU3::pau3_gptr             , PAU3_TYPE }, // 75
    { PAU3::pau3_repr             , PAU3_TYPE }, // 76
    { PAU3::pau3_time             , PAU3_TYPE }, // 77
    { PAU3::pau3_pau6_fure        , PAU3_TYPE }, // 78
    { PAU3::pau3_pau6_gptr        , PAU3_TYPE }, // 79
    { PAU3::pau3_pau6_repr        , PAU3_TYPE }, // 80
    { PAU3::pau3_pau6_time        , PAU3_TYPE }, // 81
    { PAU3::pau3_pau7_fure        , PAU3_TYPE }, // 82
    { PAU3::pau3_pau7_gptr        , PAU3_TYPE }, // 83
    { PAU3::pau3_pau7_repr        , PAU3_TYPE }, // 84
    { PAU3::pau3_pau7_time        , PAU3_TYPE }, // 85
    { AXON0::iohs0_fure           , AXON0_TYPE }, // 86
    { AXON0::iohs0_gptr           , AXON0_TYPE }, // 87
    { AXON0::iohs0_repr           , AXON0_TYPE }, // 88
    { AXON0::iohs0_time           , AXON0_TYPE }, // 89
    { AXON0::iohs0_ndl_fure       , AXON0_TYPE }, // 90
    { AXON0::iohs0_ndl_gptr       , AXON0_TYPE }, // 91
    { AXON0::iohs0_ndl_repr       , AXON0_TYPE }, // 92
    { AXON0::iohs0_ndl_time       , AXON0_TYPE }, // 93
    { AXON0::iohs0_pdl_fure       , AXON0_TYPE }, // 94
    { AXON0::iohs0_pdl_gptr       , AXON0_TYPE }, // 95
    { AXON0::iohs0_pdl_repr       , AXON0_TYPE }, // 96
    { AXON0::iohs0_pdl_time       , AXON0_TYPE }, // 97
    { AXON0::iohs0_pll_func       , AXON0_TYPE }, // 98
    { AXON0::iohs0_pll_bndy       , AXON0_TYPE }, // 99
    { AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE }, // 100
    { AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE }, // 101
    { AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE }, // 102
    { AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE }, // 103
    { AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE }, // 104
    { AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE }, // 105
    { AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE }, // 106
    { AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE }, // 107
    { AXON0::iohs0_pll_gptr       , AXON0_TYPE }, // 108
    { AXON1::iohs1_fure           , AXON1_TYPE }, // 109
    { AXON1::iohs1_gptr           , AXON1_TYPE }, // 110
    { AXON1::iohs1_repr           , AXON1_TYPE }, // 111
    { AXON1::iohs1_time           , AXON1_TYPE }, // 112
    { AXON1::iohs1_ndl_fure       , AXON1_TYPE }, // 113
    { AXON1::iohs1_ndl_gptr       , AXON1_TYPE }, // 114
    { AXON1::iohs1_ndl_repr       , AXON1_TYPE }, // 115
    { AXON1::iohs1_ndl_time       , AXON1_TYPE }, // 116
    { AXON1::iohs1_pdl_fure       , AXON1_TYPE }, // 117
    { AXON1::iohs1_pdl_gptr       , AXON1_TYPE }, // 118
    { AXON1::iohs1_pdl_repr       , AXON1_TYPE }, // 119
    { AXON1::iohs1_pdl_time       , AXON1_TYPE }, // 120
    { AXON1::iohs1_pll_func       , AXON1_TYPE }, // 121
    { AXON1::iohs1_pll_bndy       , AXON1_TYPE }, // 122
    { AXON1::iohs1_pll_bndy_bucket_0, AXON1_TYPE }, // 123
    { AXON1::iohs1_pll_bndy_bucket_1, AXON1_TYPE }, // 124
    { AXON1::iohs1_pll_bndy_bucket_2, AXON1_TYPE }, // 125
    { AXON1::iohs1_pll_bndy_bucket_3, AXON1_TYPE }, // 126
    { AXON1::iohs1_pll_bndy_bucket_4, AXON1_TYPE }, // 127
    { AXON1::iohs1_pll_bndy_bucket_5, AXON1_TYPE }, // 128
    { AXON1::iohs1_pll_bndy_bucket_6, AXON1_TYPE }, // 129
    { AXON1::iohs1_pll_bndy_bucket_7, AXON1_TYPE }, // 130
    { AXON1::iohs1_pll_gptr       , AXON1_TYPE }, // 131
    { AXON2::iohs2_fure           , AXON2_TYPE }, // 132
    { AXON2::iohs2_gptr           , AXON2_TYPE }, // 133
    { AXON2::iohs2_repr           , AXON2_TYPE }, // 134
    { AXON2::iohs2_time           , AXON2_TYPE }, // 135
    { AXON2::iohs2_ndl_fure       , AXON2_TYPE }, // 136
    { AXON2::iohs2_ndl_gptr       , AXON2_TYPE }, // 137
    { AXON2::iohs2_ndl_repr       , AXON2_TYPE }, // 138
    { AXON2::iohs2_ndl_time       , AXON2_TYPE }, // 139
    { AXON2::iohs2_pdl_fure       , AXON2_TYPE }, // 140
    { AXON2::iohs2_pdl_gptr       , AXON2_TYPE }, // 141
    { AXON2::iohs2_pdl_repr       , AXON2_TYPE }, // 142
    { AXON2::iohs2_pdl_time       , AXON2_TYPE }, // 143
    { AXON2::iohs2_pll_func       , AXON2_TYPE }, // 144
    { AXON2::iohs2_pll_bndy       , AXON2_TYPE }, // 145
    { AXON2::iohs2_pll_bndy_bucket_0, AXON2_TYPE }, // 146
    { AXON2::iohs2_pll_bndy_bucket_1, AXON2_TYPE }, // 147
    { AXON2::iohs2_pll_bndy_bucket_2, AXON2_TYPE }, // 148
    { AXON2::iohs2_pll_bndy_bucket_3, AXON2_TYPE }, // 149
    { AXON2::iohs2_pll_bndy_bucket_4, AXON2_TYPE }, // 150
    { AXON2::iohs2_pll_bndy_bucket_5, AXON2_TYPE }, // 151
    { AXON2::iohs2_pll_bndy_bucket_6, AXON2_TYPE }, // 152
    { AXON2::iohs2_pll_bndy_bucket_7, AXON2_TYPE }, // 153
    { AXON2::iohs2_pll_gptr       , AXON2_TYPE }, // 154
    { AXON3::iohs3_fure           , AXON3_TYPE }, // 155
    { AXON3::iohs3_gptr           , AXON3_TYPE }, // 156
    { AXON3::iohs3_repr           , AXON3_TYPE }, // 157
    { AXON3::iohs3_time           , AXON3_TYPE }, // 158
    { AXON3::iohs3_ndl_fure       , AXON3_TYPE }, // 159
    { AXON3::iohs3_ndl_gptr       , AXON3_TYPE }, // 160
    { AXON3::iohs3_ndl_repr       , AXON3_TYPE }, // 161
    { AXON3::iohs3_ndl_time       , AXON3_TYPE }, // 162
    { AXON3::iohs3_pdl_fure       , AXON3_TYPE }, // 163
    { AXON3::iohs3_pdl_gptr       , AXON3_TYPE }, // 164
    { AXON3::iohs3_pdl_repr       , AXON3_TYPE }, // 165
    { AXON3::iohs3_pdl_time       , AXON3_TYPE }, // 166
    { AXON3::iohs3_pll_func       , AXON3_TYPE }, // 167
    { AXON3::iohs3_pll_bndy       , AXON3_TYPE }, // 168
    { AXON3::iohs3_pll_bndy_bucket_0, AXON3_TYPE }, // 169
    { AXON3::iohs3_pll_bndy_bucket_1, AXON3_TYPE }, // 170
    { AXON3::iohs3_pll_bndy_bucket_2, AXON3_TYPE }, // 171
    { AXON3::iohs3_pll_bndy_bucket_3, AXON3_TYPE }, // 172
    { AXON3::iohs3_pll_bndy_bucket_4, AXON3_TYPE }, // 173
    { AXON3::iohs3_pll_bndy_bucket_5, AXON3_TYPE }, // 174
    { AXON3::iohs3_pll_bndy_bucket_6, AXON3_TYPE }, // 175
    { AXON3::iohs3_pll_bndy_bucket_7, AXON3_TYPE }, // 176
    { AXON3::iohs3_pll_gptr       , AXON3_TYPE }, // 177
    { AXON4::iohs4_fure           , AXON4_TYPE }, // 178
    { AXON4::iohs4_gptr           , AXON4_TYPE }, // 179
    { AXON4::iohs4_repr           , AXON4_TYPE }, // 180
    { AXON4::iohs4_time           , AXON4_TYPE }, // 181
    { AXON4::iohs4_ndl_fure       , AXON4_TYPE }, // 182
    { AXON4::iohs4_ndl_gptr       , AXON4_TYPE }, // 183
    { AXON4::iohs4_ndl_repr       , AXON4_TYPE }, // 184
    { AXON4::iohs4_ndl_time       , AXON4_TYPE }, // 185
    { AXON4::iohs4_pdl_fure       , AXON4_TYPE }, // 186
    { AXON4::iohs4_pdl_gptr       , AXON4_TYPE }, // 187
    { AXON4::iohs4_pdl_repr       , AXON4_TYPE }, // 188
    { AXON4::iohs4_pdl_time       , AXON4_TYPE }, // 189
    { AXON4::iohs4_pll_func       , AXON4_TYPE }, // 190
    { AXON4::iohs4_pll_bndy       , AXON4_TYPE }, // 191
    { AXON4::iohs4_pll_bndy_bucket_0, AXON4_TYPE }, // 192
    { AXON4::iohs4_pll_bndy_bucket_1, AXON4_TYPE }, // 193
    { AXON4::iohs4_pll_bndy_bucket_2, AXON4_TYPE }, // 194
    { AXON4::iohs4_pll_bndy_bucket_3, AXON4_TYPE }, // 195
    { AXON4::iohs4_pll_bndy_bucket_4, AXON4_TYPE }, // 196
    { AXON4::iohs4_pll_bndy_bucket_5, AXON4_TYPE }, // 197
    { AXON4::iohs4_pll_bndy_bucket_6, AXON4_TYPE }, // 198
    { AXON4::iohs4_pll_bndy_bucket_7, AXON4_TYPE }, // 199
    { AXON4::iohs4_pll_gptr       , AXON4_TYPE }, // 200
    { AXON5::iohs5_fure           , AXON5_TYPE }, // 201
    { AXON5::iohs5_gptr           , AXON5_TYPE }, // 202
    { AXON5::iohs5_repr           , AXON5_TYPE }, // 203
    { AXON5::iohs5_time           , AXON5_TYPE }, // 204
    { AXON5::iohs5_ndl_fure       , AXON5_TYPE }, // 205
    { AXON5::iohs5_ndl_gptr       , AXON5_TYPE }, // 206
    { AXON5::iohs5_ndl_repr       , AXON5_TYPE }, // 207
    { AXON5::iohs5_ndl_time       , AXON5_TYPE }, // 208
    { AXON5::iohs5_pdl_fure       , AXON5_TYPE }, // 209
    { AXON5::iohs5_pdl_gptr       , AXON5_TYPE }, // 210
    { AXON5::iohs5_pdl_repr       , AXON5_TYPE }, // 211
    { AXON5::iohs5_pdl_time       , AXON5_TYPE }, // 212
    { AXON5::iohs5_pll_func       , AXON5_TYPE }, // 213
    { AXON5::iohs5_pll_bndy       , AXON5_TYPE }, // 214
    { AXON5::iohs5_pll_bndy_bucket_0, AXON5_TYPE }, // 215
    { AXON5::iohs5_pll_bndy_bucket_1, AXON5_TYPE }, // 216
    { AXON5::iohs5_pll_bndy_bucket_2, AXON5_TYPE }, // 217
    { AXON5::iohs5_pll_bndy_bucket_3, AXON5_TYPE }, // 218
    { AXON5::iohs5_pll_bndy_bucket_4, AXON5_TYPE }, // 219
    { AXON5::iohs5_pll_bndy_bucket_5, AXON5_TYPE }, // 220
    { AXON5::iohs5_pll_bndy_bucket_6, AXON5_TYPE }, // 221
    { AXON5::iohs5_pll_bndy_bucket_7, AXON5_TYPE }, // 222
    { AXON5::iohs5_pll_gptr       , AXON5_TYPE }, // 223
    { AXON6::iohs6_fure           , AXON6_TYPE }, // 224
    { AXON6::iohs6_gptr           , AXON6_TYPE }, // 225
    { AXON6::iohs6_repr           , AXON6_TYPE }, // 226
    { AXON6::iohs6_time           , AXON6_TYPE }, // 227
    { AXON6::iohs6_ndl_fure       , AXON6_TYPE }, // 228
    { AXON6::iohs6_ndl_gptr       , AXON6_TYPE }, // 229
    { AXON6::iohs6_ndl_repr       , AXON6_TYPE }, // 230
    { AXON6::iohs6_ndl_time       , AXON6_TYPE }, // 231
    { AXON6::iohs6_pdl_fure       , AXON6_TYPE }, // 232
    { AXON6::iohs6_pdl_gptr       , AXON6_TYPE }, // 233
    { AXON6::iohs6_pdl_repr       , AXON6_TYPE }, // 234
    { AXON6::iohs6_pdl_time       , AXON6_TYPE }, // 235
    { AXON6::iohs6_pll_func       , AXON6_TYPE }, // 236
    { AXON6::iohs6_pll_bndy       , AXON6_TYPE }, // 237
    { AXON6::iohs6_pll_bndy_bucket_0, AXON6_TYPE }, // 238
    { AXON6::iohs6_pll_bndy_bucket_1, AXON6_TYPE }, // 239
    { AXON6::iohs6_pll_bndy_bucket_2, AXON6_TYPE }, // 240
    { AXON6::iohs6_pll_bndy_bucket_3, AXON6_TYPE }, // 241
    { AXON6::iohs6_pll_bndy_bucket_4, AXON6_TYPE }, // 242
    { AXON6::iohs6_pll_bndy_bucket_5, AXON6_TYPE }, // 243
    { AXON6::iohs6_pll_bndy_bucket_6, AXON6_TYPE }, // 244
    { AXON6::iohs6_pll_bndy_bucket_7, AXON6_TYPE }, // 245
    { AXON6::iohs6_pll_gptr       , AXON6_TYPE }, // 246
    { AXON7::iohs7_fure           , AXON7_TYPE }, // 247
    { AXON7::iohs7_gptr           , AXON7_TYPE }, // 248
    { AXON7::iohs7_repr           , AXON7_TYPE }, // 249
    { AXON7::iohs7_time           , AXON7_TYPE }, // 250
    { AXON7::iohs7_ndl_fure       , AXON7_TYPE }, // 251
    { AXON7::iohs7_ndl_gptr       , AXON7_TYPE }, // 252
    { AXON7::iohs7_ndl_repr       , AXON7_TYPE }, // 253
    { AXON7::iohs7_ndl_time       , AXON7_TYPE }, // 254
    { AXON7::iohs7_pdl_fure       , AXON7_TYPE }, // 255
    { AXON7::iohs7_pdl_gptr       , AXON7_TYPE }, // 256
    { AXON7::iohs7_pdl_repr       , AXON7_TYPE }, // 257
    { AXON7::iohs7_pdl_time       , AXON7_TYPE }, // 258
    { AXON7::iohs7_pll_func       , AXON7_TYPE }, // 259
    { AXON7::iohs7_pll_bndy       , AXON7_TYPE }, // 260
    { AXON7::iohs7_pll_bndy_bucket_0, AXON7_TYPE }, // 261
    { AXON7::iohs7_pll_bndy_bucket_1, AXON7_TYPE }, // 262
    { AXON7::iohs7_pll_bndy_bucket_2, AXON7_TYPE }, // 263
    { AXON7::iohs7_pll_bndy_bucket_3, AXON7_TYPE }, // 264
    { AXON7::iohs7_pll_bndy_bucket_4, AXON7_TYPE }, // 265
    { AXON7::iohs7_pll_bndy_bucket_5, AXON7_TYPE }, // 266
    { AXON7::iohs7_pll_bndy_bucket_6, AXON7_TYPE }, // 267
    { AXON7::iohs7_pll_bndy_bucket_7, AXON7_TYPE }, // 268
    { AXON7::iohs7_pll_gptr       , AXON7_TYPE }, // 269
    { EQ::eq_fure                 , EQ_TYPE   }, // 270
    { EQ::eq_gptr                 , EQ_TYPE   }, // 271
    { EQ::eq_repr                 , EQ_TYPE   }, // 272
    { EQ::eq_time                 , EQ_TYPE   }, // 273
    { EQ::eq_cmsk                 , EQ_TYPE   }, // 274
    { EQ::eq_inex                 , EQ_TYPE   }, // 275
    { EQ::eq_mode                 , EQ_TYPE   }, // 276
    { EQ::ec_cl2_fure             , EQ_TYPE   }, // 277
    { EQ::ec_cl2_gptr             , EQ_TYPE   }, // 278
    { EQ::ec_cl2_repr             , EQ_TYPE   }, // 279
    { EQ::ec_cl2_time             , EQ_TYPE   }, // 280
    { EQ::ec_cl2_cmsk             , EQ_TYPE   }, // 281
    { EQ::ec_cl2_inex             , EQ_TYPE   }, // 282
    { EQ::ec_cl2_mode             , EQ_TYPE   }, // 283
    { EQ::ec1_cl2_repr            , EQ_TYPE   }, // 284
    { EQ::ec2_cl2_repr            , EQ_TYPE   }, // 285
    { EQ::ec3_cl2_repr            , EQ_TYPE   }, // 286
    { EQ::ec_mma_fure             , EQ_TYPE   }, // 287
    { EQ::ec_mma_gptr             , EQ_TYPE   }, // 288
    { EQ::ec_mma_repr             , EQ_TYPE   }, // 289
    { EQ::ec_mma_time             , EQ_TYPE   }, // 290
    { EQ::ec_mma_cmsk             , EQ_TYPE   }, // 291
    { EQ::ec_mma_inex             , EQ_TYPE   }, // 292
    { EQ::ec1_mma_repr            , EQ_TYPE   }, // 293
    { EQ::ec2_mma_repr            , EQ_TYPE   }, // 294
    { EQ::ec3_mma_repr            , EQ_TYPE   }, // 295
    { EQ::ec_l3_fure              , EQ_TYPE   }, // 296
    { EQ::ec_l3_gptr              , EQ_TYPE   }, // 297
    { EQ::ec_l3_repr              , EQ_TYPE   }, // 298
    { EQ::ec_l3_time              , EQ_TYPE   }, // 299
    { EQ::ec_l3_cmsk              , EQ_TYPE   }, // 300
    { EQ::ec_l3_inex              , EQ_TYPE   }, // 301
    { EQ::ec_l3_mode              , EQ_TYPE   }, // 302
    { EQ::ec1_l3_repr             , EQ_TYPE   }, // 303
    { EQ::ec2_l3_repr             , EQ_TYPE   }, // 304
    { EQ::ec3_l3_repr             , EQ_TYPE   }, // 305
};
#endif  // __PPE__

#endif  // _P10_RING_PROPERTIES_H_
