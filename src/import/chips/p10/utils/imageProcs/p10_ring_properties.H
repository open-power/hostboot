/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ring_properties.H $ */
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
#ifndef _P10_RING_PROPERTIES_H_
#define _P10_RING_PROPERTIES_H_

static const uint8_t RING_TABLE_VERSION_DOC = 22;
static const uint8_t RING_TABLE_VERSION_MVPD = 22;
static const uint8_t RING_TABLE_VERSION_EKB = 22;

// RingID values where the MVPD and EKB rings' enum values start
// (Used in p10_ring_id.H)
#define RINGID_START_MVPD  (RingId_t)0
#define RINGID_END_MVPD    (RingId_t)160
#define RINGID_START_EKB   (RingId_t)256
#define RINGID_END_EKB     (RingId_t)352

// Ring indices where the MVPD and EKB rings' metadata start
// (Used in p10_ring_properties.H (This file))
#define RING_INDEX_START_MVPD  (RingId_t)0
#define RING_INDEX_START_EKB   (RingId_t)161

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
    perv_dpll_time           = 9,
    perv_dpll_gptr           = 10,
    perv_pll_func            = 11,
    perv_pll_bndy            = 12,
    perv_pll_gptr            = 13,
    // Instance Rings
    perv_occ_repr            = (0 | INSTANCE_RING_MARK),
    pib_repr                 = (1 | INSTANCE_RING_MARK),
    sbe_repr                 = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x01, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    14, // 14 common rings for PERV Chiplet
    3,  // 3 instance specific rings for PERV Chiplet
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
    n0_abst                  = 3,
    // Instance Rings
    n0_repr                  = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x02, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    4,  // 4 common rings for N0 Chiplet
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
    n1_abst                  = 6,
    n1_nmmu1_abst            = 7,
    // Instance Rings
    n1_repr                  = (0 | INSTANCE_RING_MARK),
    n1_nmmu1_repr            = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x03, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for N1 Chiplet
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
    pci_pll_gptr             = 4,
    pci_pll_bndy             = 5,
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
    mc_pll_gptr              = 4,
    mc_pll_bndy              = 5,
    mc_pll_bndy_bucket_0     = 5,
    mc_pll_bndy_bucket_1     = 6,
    mc_pll_bndy_bucket_2     = 7,
    mc_pll_bndy_bucket_3     = 8,
    mc_pll_bndy_bucket_4     = 9,
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
    iohs1_pll_gptr           = 10,
    // Instance Rings
    iohs1_repr               = (0 | INSTANCE_RING_MARK),
    iohs1_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs1_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x19, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON1 Chiplet
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
    iohs2_pll_gptr           = 10,
    // Instance Rings
    iohs2_repr               = (0 | INSTANCE_RING_MARK),
    iohs2_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs2_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1A, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON2 Chiplet
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
    iohs3_pll_gptr           = 10,
    // Instance Rings
    iohs3_repr               = (0 | INSTANCE_RING_MARK),
    iohs3_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs3_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1B, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON3 Chiplet
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
    iohs4_pll_gptr           = 10,
    // Instance Rings
    iohs4_repr               = (0 | INSTANCE_RING_MARK),
    iohs4_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs4_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1C, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON4 Chiplet
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
    iohs5_pll_gptr           = 10,
    // Instance Rings
    iohs5_repr               = (0 | INSTANCE_RING_MARK),
    iohs5_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs5_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1D, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON5 Chiplet
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
    iohs6_pll_gptr           = 10,
    // Instance Rings
    iohs6_repr               = (0 | INSTANCE_RING_MARK),
    iohs6_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs6_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1E, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON6 Chiplet
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
    iohs7_pll_gptr           = 10,
    // Instance Rings
    iohs7_repr               = (0 | INSTANCE_RING_MARK),
    iohs7_ndl_repr           = (1 | INSTANCE_RING_MARK),
    iohs7_pdl_repr           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1F, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    11, // 11 common rings for AXON7 Chiplet
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
    eq_clkadj_fure           = 6,
    eq_clkadj_gptr           = 7,
    eq_clkadj_time           = 8,
    eq_clkadj_cmsk           = 9,
    eq_clkadj_inex           = 10,
    eq_clkadj_mode           = 11,
    ec_cl2_fure              = 12,
    ec_cl2_gptr              = 13,
    ec_cl2_time              = 14,
    ec_cl2_cmsk              = 15,
    ec_cl2_inex              = 16,
    ec_cl2_mode              = 17,
    ec_mma_fure              = 18,
    ec_mma_gptr              = 19,
    ec_mma_time              = 20,
    ec_mma_cmsk              = 21,
    ec_mma_inex              = 22,
    ec_l3_fure               = 23,
    ec_l3_gptr               = 24,
    ec_l3_time               = 25,
    ec_l3_cmsk               = 26,
    ec_l3_inex               = 27,
    ec_l3_mode               = 28,
    ec_cl2_abst              = 29,
    ec_mma_abst              = 30,
    // Instance Rings
    eq_repr                  = (0 | INSTANCE_RING_MARK),
    eq_clkadj_repr           = (1 | INSTANCE_RING_MARK),
    ec_cl2_repr              = (2 | INSTANCE_RING_MARK),
    ec1_cl2_repr             = (3 | INSTANCE_RING_MARK),
    ec2_cl2_repr             = (4 | INSTANCE_RING_MARK),
    ec3_cl2_repr             = (5 | INSTANCE_RING_MARK),
    ec_mma_repr              = (6 | INSTANCE_RING_MARK),
    ec1_mma_repr             = (7 | INSTANCE_RING_MARK),
    ec2_mma_repr             = (8 | INSTANCE_RING_MARK),
    ec3_mma_repr             = (9 | INSTANCE_RING_MARK),
    ec_l3_repr               = (10 | INSTANCE_RING_MARK),
    ec1_l3_repr              = (11 | INSTANCE_RING_MARK),
    ec2_l3_repr              = (12 | INSTANCE_RING_MARK),
    ec3_l3_repr              = (13 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x20, // Base chiplet/instance ID.
    8,  // Number of chiplet instances
    31, // 31 common rings for EQ Chiplet
    14, // 14 instance specific rings for EQ Chiplet
};
}; // end of namespace EQ


#ifndef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    // MVPD Rings:
    {perv_occ_gptr          , "perv_occ_gptr"           , 0x01034902, PERV::perv_occ_gptr           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 0
    {perv_occ_repr          , "perv_occ_repr"           , 0x01034906, PERV::perv_occ_repr           , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 1
    {perv_occ_time          , "perv_occ_time"           , 0x01034907, PERV::perv_occ_time           , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 2
    {pib_repr               , "pib_repr"                , 0x01031006, PERV::pib_repr                , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 3
    {sbe_gptr               , "sbe_gptr"                , 0x01032002, PERV::sbe_gptr                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 4
    {sbe_repr               , "sbe_repr"                , 0x01032006, PERV::sbe_repr                , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 5
    {sbe_time               , "sbe_time"                , 0x01032007, PERV::sbe_time                , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 6
    {HOLE_RING_ID           , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 7
    {perv_dpll_gptr         , "perv_dpll_gptr"          , 0x01030062, PERV::perv_dpll_gptr          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 8
    {perv_pll_gptr          , "perv_pll_gptr"           , 0x01030012, PERV::perv_pll_gptr           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 9
    {n0_gptr                , "n0_gptr"                 , 0x02036402, N0::n0_gptr                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 10
    {n0_repr                , "n0_repr"                 , 0x02036406, N0::n0_repr                   , N0_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 11
    {n0_time                , "n0_time"                 , 0x02036407, N0::n0_time                   , N0_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 12
    {n1_gptr                , "n1_gptr"                 , 0x03035402, N1::n1_gptr                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 13
    {n1_repr                , "n1_repr"                 , 0x03035406, N1::n1_repr                   , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 14
    {n1_time                , "n1_time"                 , 0x03035407, N1::n1_time                   , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 15
    {n1_nmmu1_gptr          , "n1_nmmu1_gptr"           , 0x03030202, N1::n1_nmmu1_gptr             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 16
    {n1_nmmu1_repr          , "n1_nmmu1_repr"           , 0x03030206, N1::n1_nmmu1_repr             , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 17
    {n1_nmmu1_time          , "n1_nmmu1_time"           , 0x03030207, N1::n1_nmmu1_time             , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 18
    {pci_gptr               , "pci_gptr"                , 0x08037F82, PCI::pci_gptr                 , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 19
    {pci_repr               , "pci_repr"                , 0x08037F86, PCI::pci_repr                 , PCI_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 20
    {pci_time               , "pci_time"                , 0x08037F87, PCI::pci_time                 , PCI_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 21
    {pci_pll_gptr           , "pci_pll_gptr"            , 0x08030012, PCI::pci_pll_gptr             , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 22
    {mc_gptr                , "mc_gptr"                 , 0x0C036F02, MC::mc_gptr                   , MC_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 23
    {mc_repr                , "mc_repr"                 , 0x0C036F06, MC::mc_repr                   , MC_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 24
    {mc_time                , "mc_time"                 , 0x0C036F07, MC::mc_time                   , MC_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 25
    {mc_pll_gptr            , "mc_pll_gptr"             , 0x0C030012, MC::mc_pll_gptr               , MC_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 26
    {pau0_gptr              , "pau0_gptr"               , 0x10034302, PAU0::pau0_gptr               , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 27
    {pau0_repr              , "pau0_repr"               , 0x10034306, PAU0::pau0_repr               , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 28
    {pau0_time              , "pau0_time"               , 0x10034307, PAU0::pau0_time               , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 29
    {pau0_pau0_gptr         , "pau0_pau0_gptr"          , 0x10032002, PAU0::pau0_pau0_gptr          , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 30
    {pau0_pau0_repr         , "pau0_pau0_repr"          , 0x10032006, PAU0::pau0_pau0_repr          , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 31
    {pau0_pau0_time         , "pau0_pau0_time"          , 0x10032007, PAU0::pau0_pau0_time          , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 32
    {pau1_gptr              , "pau1_gptr"               , 0x11034302, PAU1::pau1_gptr               , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 33
    {pau1_repr              , "pau1_repr"               , 0x11034306, PAU1::pau1_repr               , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 34
    {pau1_time              , "pau1_time"               , 0x11034307, PAU1::pau1_time               , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 35
    {pau1_pau3_gptr         , "pau1_pau3_gptr"          , 0x11032002, PAU1::pau1_pau3_gptr          , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 36
    {pau1_pau3_repr         , "pau1_pau3_repr"          , 0x11032006, PAU1::pau1_pau3_repr          , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 37
    {pau1_pau3_time         , "pau1_pau3_time"          , 0x11032007, PAU1::pau1_pau3_time          , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 38
    {pau2_gptr              , "pau2_gptr"               , 0x12034302, PAU2::pau2_gptr               , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 39
    {pau2_repr              , "pau2_repr"               , 0x12034306, PAU2::pau2_repr               , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 40
    {pau2_time              , "pau2_time"               , 0x12034307, PAU2::pau2_time               , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 41
    {pau2_pau4_gptr         , "pau2_pau4_gptr"          , 0x12032002, PAU2::pau2_pau4_gptr          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 42
    {pau2_pau4_repr         , "pau2_pau4_repr"          , 0x12032006, PAU2::pau2_pau4_repr          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 43
    {pau2_pau4_time         , "pau2_pau4_time"          , 0x12032007, PAU2::pau2_pau4_time          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 44
    {pau2_pau5_gptr         , "pau2_pau5_gptr"          , 0x12031002, PAU2::pau2_pau5_gptr          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 45
    {pau2_pau5_repr         , "pau2_pau5_repr"          , 0x12031006, PAU2::pau2_pau5_repr          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 46
    {pau2_pau5_time         , "pau2_pau5_time"          , 0x12031007, PAU2::pau2_pau5_time          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 47
    {pau3_gptr              , "pau3_gptr"               , 0x13034302, PAU3::pau3_gptr               , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 48
    {pau3_repr              , "pau3_repr"               , 0x13034306, PAU3::pau3_repr               , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 49
    {pau3_time              , "pau3_time"               , 0x13034307, PAU3::pau3_time               , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 50
    {pau3_pau6_gptr         , "pau3_pau6_gptr"          , 0x13032002, PAU3::pau3_pau6_gptr          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 51
    {pau3_pau6_repr         , "pau3_pau6_repr"          , 0x13032006, PAU3::pau3_pau6_repr          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 52
    {pau3_pau6_time         , "pau3_pau6_time"          , 0x13032007, PAU3::pau3_pau6_time          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 53
    {pau3_pau7_gptr         , "pau3_pau7_gptr"          , 0x13031002, PAU3::pau3_pau7_gptr          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 54
    {pau3_pau7_repr         , "pau3_pau7_repr"          , 0x13031006, PAU3::pau3_pau7_repr          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 55
    {pau3_pau7_time         , "pau3_pau7_time"          , 0x13031007, PAU3::pau3_pau7_time          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 56
    {iohs0_gptr             , "iohs0_gptr"              , 0x18036002, AXON0::iohs0_gptr             , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 57
    {iohs0_repr             , "iohs0_repr"              , 0x18036006, AXON0::iohs0_repr             , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 58
    {iohs0_time             , "iohs0_time"              , 0x18036007, AXON0::iohs0_time             , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 59
    {iohs0_ndl_gptr         , "iohs0_ndl_gptr"          , 0x18030402, AXON0::iohs0_ndl_gptr         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 60
    {iohs0_ndl_repr         , "iohs0_ndl_repr"          , 0x18030406, AXON0::iohs0_ndl_repr         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 61
    {iohs0_ndl_time         , "iohs0_ndl_time"          , 0x18030407, AXON0::iohs0_ndl_time         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 62
    {iohs0_pdl_gptr         , "iohs0_pdl_gptr"          , 0x18030202, AXON0::iohs0_pdl_gptr         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 63
    {iohs0_pdl_repr         , "iohs0_pdl_repr"          , 0x18030206, AXON0::iohs0_pdl_repr         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 64
    {iohs0_pdl_time         , "iohs0_pdl_time"          , 0x18030207, AXON0::iohs0_pdl_time         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 65
    {iohs0_pll_gptr         , "iohs0_pll_gptr"          , 0x18030012, AXON0::iohs0_pll_gptr         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 66
    {iohs1_gptr             , "iohs1_gptr"              , 0x19036002, AXON1::iohs1_gptr             , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 67
    {iohs1_repr             , "iohs1_repr"              , 0x19036006, AXON1::iohs1_repr             , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 68
    {iohs1_time             , "iohs1_time"              , 0x19036007, AXON1::iohs1_time             , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 69
    {iohs1_ndl_gptr         , "iohs1_ndl_gptr"          , 0x19030402, AXON1::iohs1_ndl_gptr         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 70
    {iohs1_ndl_repr         , "iohs1_ndl_repr"          , 0x19030406, AXON1::iohs1_ndl_repr         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 71
    {iohs1_ndl_time         , "iohs1_ndl_time"          , 0x19030407, AXON1::iohs1_ndl_time         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 72
    {iohs1_pdl_gptr         , "iohs1_pdl_gptr"          , 0x19030202, AXON1::iohs1_pdl_gptr         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 73
    {iohs1_pdl_repr         , "iohs1_pdl_repr"          , 0x19030206, AXON1::iohs1_pdl_repr         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 74
    {iohs1_pdl_time         , "iohs1_pdl_time"          , 0x19030207, AXON1::iohs1_pdl_time         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 75
    {iohs1_pll_gptr         , "iohs1_pll_gptr"          , 0x19030012, AXON1::iohs1_pll_gptr         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 76
    {iohs2_gptr             , "iohs2_gptr"              , 0x1A036002, AXON2::iohs2_gptr             , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 77
    {iohs2_repr             , "iohs2_repr"              , 0x1A036006, AXON2::iohs2_repr             , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 78
    {iohs2_time             , "iohs2_time"              , 0x1A036007, AXON2::iohs2_time             , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 79
    {iohs2_ndl_gptr         , "iohs2_ndl_gptr"          , 0x1A030402, AXON2::iohs2_ndl_gptr         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 80
    {iohs2_ndl_repr         , "iohs2_ndl_repr"          , 0x1A030406, AXON2::iohs2_ndl_repr         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 81
    {iohs2_ndl_time         , "iohs2_ndl_time"          , 0x1A030407, AXON2::iohs2_ndl_time         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 82
    {iohs2_pdl_gptr         , "iohs2_pdl_gptr"          , 0x1A030202, AXON2::iohs2_pdl_gptr         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 83
    {iohs2_pdl_repr         , "iohs2_pdl_repr"          , 0x1A030206, AXON2::iohs2_pdl_repr         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 84
    {iohs2_pdl_time         , "iohs2_pdl_time"          , 0x1A030207, AXON2::iohs2_pdl_time         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 85
    {iohs2_pll_gptr         , "iohs2_pll_gptr"          , 0x1A030012, AXON2::iohs2_pll_gptr         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 86
    {iohs3_gptr             , "iohs3_gptr"              , 0x1B036002, AXON3::iohs3_gptr             , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 87
    {iohs3_repr             , "iohs3_repr"              , 0x1B036006, AXON3::iohs3_repr             , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 88
    {iohs3_time             , "iohs3_time"              , 0x1B036007, AXON3::iohs3_time             , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 89
    {iohs3_ndl_gptr         , "iohs3_ndl_gptr"          , 0x1B030402, AXON3::iohs3_ndl_gptr         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 90
    {iohs3_ndl_repr         , "iohs3_ndl_repr"          , 0x1B030406, AXON3::iohs3_ndl_repr         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 91
    {iohs3_ndl_time         , "iohs3_ndl_time"          , 0x1B030407, AXON3::iohs3_ndl_time         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 92
    {iohs3_pdl_gptr         , "iohs3_pdl_gptr"          , 0x1B030202, AXON3::iohs3_pdl_gptr         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 93
    {iohs3_pdl_repr         , "iohs3_pdl_repr"          , 0x1B030206, AXON3::iohs3_pdl_repr         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 94
    {iohs3_pdl_time         , "iohs3_pdl_time"          , 0x1B030207, AXON3::iohs3_pdl_time         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 95
    {iohs3_pll_gptr         , "iohs3_pll_gptr"          , 0x1B030012, AXON3::iohs3_pll_gptr         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 96
    {iohs4_gptr             , "iohs4_gptr"              , 0x1C036002, AXON4::iohs4_gptr             , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 97
    {iohs4_repr             , "iohs4_repr"              , 0x1C036006, AXON4::iohs4_repr             , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 98
    {iohs4_time             , "iohs4_time"              , 0x1C036007, AXON4::iohs4_time             , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 99
    {iohs4_ndl_gptr         , "iohs4_ndl_gptr"          , 0x1C030402, AXON4::iohs4_ndl_gptr         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 100
    {iohs4_ndl_repr         , "iohs4_ndl_repr"          , 0x1C030406, AXON4::iohs4_ndl_repr         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 101
    {iohs4_ndl_time         , "iohs4_ndl_time"          , 0x1C030407, AXON4::iohs4_ndl_time         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 102
    {iohs4_pdl_gptr         , "iohs4_pdl_gptr"          , 0x1C030202, AXON4::iohs4_pdl_gptr         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 103
    {iohs4_pdl_repr         , "iohs4_pdl_repr"          , 0x1C030206, AXON4::iohs4_pdl_repr         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 104
    {iohs4_pdl_time         , "iohs4_pdl_time"          , 0x1C030207, AXON4::iohs4_pdl_time         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 105
    {iohs4_pll_gptr         , "iohs4_pll_gptr"          , 0x1C030012, AXON4::iohs4_pll_gptr         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 106
    {iohs5_gptr             , "iohs5_gptr"              , 0x1D036002, AXON5::iohs5_gptr             , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 107
    {iohs5_repr             , "iohs5_repr"              , 0x1D036006, AXON5::iohs5_repr             , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 108
    {iohs5_time             , "iohs5_time"              , 0x1D036007, AXON5::iohs5_time             , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 109
    {iohs5_ndl_gptr         , "iohs5_ndl_gptr"          , 0x1D030402, AXON5::iohs5_ndl_gptr         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 110
    {iohs5_ndl_repr         , "iohs5_ndl_repr"          , 0x1D030406, AXON5::iohs5_ndl_repr         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 111
    {iohs5_ndl_time         , "iohs5_ndl_time"          , 0x1D030407, AXON5::iohs5_ndl_time         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 112
    {iohs5_pdl_gptr         , "iohs5_pdl_gptr"          , 0x1D030202, AXON5::iohs5_pdl_gptr         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 113
    {iohs5_pdl_repr         , "iohs5_pdl_repr"          , 0x1D030206, AXON5::iohs5_pdl_repr         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 114
    {iohs5_pdl_time         , "iohs5_pdl_time"          , 0x1D030207, AXON5::iohs5_pdl_time         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 115
    {iohs5_pll_gptr         , "iohs5_pll_gptr"          , 0x1D030012, AXON5::iohs5_pll_gptr         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 116
    {iohs6_gptr             , "iohs6_gptr"              , 0x1E036002, AXON6::iohs6_gptr             , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 117
    {iohs6_repr             , "iohs6_repr"              , 0x1E036006, AXON6::iohs6_repr             , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 118
    {iohs6_time             , "iohs6_time"              , 0x1E036007, AXON6::iohs6_time             , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 119
    {iohs6_ndl_gptr         , "iohs6_ndl_gptr"          , 0x1E030402, AXON6::iohs6_ndl_gptr         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 120
    {iohs6_ndl_repr         , "iohs6_ndl_repr"          , 0x1E030406, AXON6::iohs6_ndl_repr         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 121
    {iohs6_ndl_time         , "iohs6_ndl_time"          , 0x1E030407, AXON6::iohs6_ndl_time         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 122
    {iohs6_pdl_gptr         , "iohs6_pdl_gptr"          , 0x1E030202, AXON6::iohs6_pdl_gptr         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 123
    {iohs6_pdl_repr         , "iohs6_pdl_repr"          , 0x1E030206, AXON6::iohs6_pdl_repr         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 124
    {iohs6_pdl_time         , "iohs6_pdl_time"          , 0x1E030207, AXON6::iohs6_pdl_time         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 125
    {iohs6_pll_gptr         , "iohs6_pll_gptr"          , 0x1E030012, AXON6::iohs6_pll_gptr         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 126
    {iohs7_gptr             , "iohs7_gptr"              , 0x1F036002, AXON7::iohs7_gptr             , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 127
    {iohs7_repr             , "iohs7_repr"              , 0x1F036006, AXON7::iohs7_repr             , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 128
    {iohs7_time             , "iohs7_time"              , 0x1F036007, AXON7::iohs7_time             , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 129
    {iohs7_ndl_gptr         , "iohs7_ndl_gptr"          , 0x1F030402, AXON7::iohs7_ndl_gptr         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 130
    {iohs7_ndl_repr         , "iohs7_ndl_repr"          , 0x1F030406, AXON7::iohs7_ndl_repr         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 131
    {iohs7_ndl_time         , "iohs7_ndl_time"          , 0x1F030407, AXON7::iohs7_ndl_time         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 132
    {iohs7_pdl_gptr         , "iohs7_pdl_gptr"          , 0x1F030202, AXON7::iohs7_pdl_gptr         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 133
    {iohs7_pdl_repr         , "iohs7_pdl_repr"          , 0x1F030206, AXON7::iohs7_pdl_repr         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                         }, // 134
    {iohs7_pdl_time         , "iohs7_pdl_time"          , 0x1F030207, AXON7::iohs7_pdl_time         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 135
    {iohs7_pll_gptr         , "iohs7_pll_gptr"          , 0x1F030012, AXON7::iohs7_pll_gptr         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 136
    {eq_gptr                , "eq_gptr"                 , 0x20034022, EQ::eq_gptr                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 137
    {eq_repr                , "eq_repr"                 , 0x20034026, EQ::eq_repr                   , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_EQ                           }, // 138
    {eq_time                , "eq_time"                 , 0x20034027, EQ::eq_time                   , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 139
    {eq_clkadj_gptr         , "eq_clkadj_gptr"          , 0x20030012, EQ::eq_clkadj_gptr            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                     }, // 140
    {eq_clkadj_repr         , "eq_clkadj_repr"          , 0x20030016, EQ::eq_clkadj_repr            , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_EQ                           }, // 141
    {eq_clkadj_time         , "eq_clkadj_time"          , 0x20030017, EQ::eq_clkadj_time            , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                         }, // 142
    {ec_cl2_gptr            , "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME    }, // 143
    {ec_cl2_repr            , "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 144
    {ec_cl2_time            , "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME        }, // 145
    {ec1_cl2_repr           , "ec1_cl2_repr"            , 0x20031006, EQ::ec1_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 146
    {ec2_cl2_repr           , "ec2_cl2_repr"            , 0x20030806, EQ::ec2_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 147
    {ec3_cl2_repr           , "ec3_cl2_repr"            , 0x20030406, EQ::ec3_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 148
    {ec_mma_gptr            , "ec_mma_gptr"             , 0x20830002, EQ::ec_mma_gptr               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME    }, // 149
    {ec_mma_repr            , "ec_mma_repr"             , 0x20830006, EQ::ec_mma_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 150
    {ec_mma_time            , "ec_mma_time"             , 0x20830007, EQ::ec_mma_time               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME        }, // 151
    {ec1_mma_repr           , "ec1_mma_repr"            , 0x20430006, EQ::ec1_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 152
    {ec2_mma_repr           , "ec2_mma_repr"            , 0x20230006, EQ::ec2_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 153
    {ec3_mma_repr           , "ec3_mma_repr"            , 0x20130006, EQ::ec3_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 154
    {ec_l3_gptr             , "ec_l3_gptr"              , 0x20030202, EQ::ec_l3_gptr                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME    }, // 155
    {ec_l3_repr             , "ec_l3_repr"              , 0x20030206, EQ::ec_l3_repr                , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 156
    {ec_l3_time             , "ec_l3_time"              , 0x20030207, EQ::ec_l3_time                , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME        }, // 157
    {ec1_l3_repr            , "ec1_l3_repr"             , 0x20030106, EQ::ec1_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 158
    {ec2_l3_repr            , "ec2_l3_repr"             , 0x20030086, EQ::ec2_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 159
    {ec3_l3_repr            , "ec3_l3_repr"             , 0x20030046, EQ::ec3_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME        }, // 160

    // EKB Rings:
    {perv_fure              , "perv_fure"               , 0x0103410F, PERV::perv_fure               , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 256
    {sbe_fure               , "sbe_fure"                , 0x0103200F, PERV::sbe_fure                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 257
    {occ_fure               , "occ_fure"                , 0x0103080F, PERV::occ_fure                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 258
    {perv_dpll_func         , "perv_dpll_func"          , 0x01030060, PERV::perv_dpll_func          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 259
    {perv_dpll_bndy         , "perv_dpll_bndy"          , 0x01030068, PERV::perv_dpll_bndy          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 260
    {perv_dpll_time         , "perv_dpll_time"          , 0x01030067, PERV::perv_dpll_time          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 261
    {perv_pll_func          , "perv_pll_func"           , 0x01030010, PERV::perv_pll_func           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 262
    {perv_pll_bndy          , "perv_pll_bndy"           , 0x01030018, PERV::perv_pll_bndy           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 263
    {n0_fure                , "n0_fure"                 , 0x0203640F, N0::n0_fure                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 264
    {n1_fure                , "n1_fure"                 , 0x0303540F, N1::n1_fure                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 265
    {n1_nmmu1_fure          , "n1_nmmu1_fure"           , 0x0303020F, N1::n1_nmmu1_fure             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 266
    {pci_fure               , "pci_fure"                , 0x08037F8F, PCI::pci_fure                 , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 267
    {pci_pll_func           , "pci_pll_func"            , 0x08030010, PCI::pci_pll_func             , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 268
    {pci_pll_bndy           , "pci_pll_bndy"            , 0x08030018, PCI::pci_pll_bndy             , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 269
    {mc_fure                , "mc_fure"                 , 0x0C036F0F, MC::mc_fure                   , MC_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 270
    {mc_pll_func            , "mc_pll_func"             , 0x0C030010, MC::mc_pll_func               , MC_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 271
    {mc_pll_bndy            , "mc_pll_bndy"             , 0x0C030018, MC::mc_pll_bndy               , MC_TYPE   , RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS             }, // 272
    {mc_pll_bndy_bucket_0   , "mc_pll_bndy_bucket_0"    , 0x0C030018, MC::mc_pll_bndy_bucket_0      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 273
    {mc_pll_bndy_bucket_1   , "mc_pll_bndy_bucket_1"    , 0x0C030018, MC::mc_pll_bndy_bucket_1      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 274
    {mc_pll_bndy_bucket_2   , "mc_pll_bndy_bucket_2"    , 0x0C030018, MC::mc_pll_bndy_bucket_2      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 275
    {mc_pll_bndy_bucket_3   , "mc_pll_bndy_bucket_3"    , 0x0C030018, MC::mc_pll_bndy_bucket_3      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 276
    {mc_pll_bndy_bucket_4   , "mc_pll_bndy_bucket_4"    , 0x0C030018, MC::mc_pll_bndy_bucket_4      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 277
    {pau0_fure              , "pau0_fure"               , 0x1003430F, PAU0::pau0_fure               , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 278
    {pau0_pau0_fure         , "pau0_pau0_fure"          , 0x1003200F, PAU0::pau0_pau0_fure          , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 279
    {pau1_fure              , "pau1_fure"               , 0x1103430F, PAU1::pau1_fure               , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 280
    {pau1_pau3_fure         , "pau1_pau3_fure"          , 0x1103200F, PAU1::pau1_pau3_fure          , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 281
    {pau2_fure              , "pau2_fure"               , 0x1203430F, PAU2::pau2_fure               , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 282
    {pau2_pau4_fure         , "pau2_pau4_fure"          , 0x1203200F, PAU2::pau2_pau4_fure          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 283
    {pau2_pau5_fure         , "pau2_pau5_fure"          , 0x1203100F, PAU2::pau2_pau5_fure          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 284
    {pau3_fure              , "pau3_fure"               , 0x1303430F, PAU3::pau3_fure               , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 285
    {pau3_pau6_fure         , "pau3_pau6_fure"          , 0x1303200F, PAU3::pau3_pau6_fure          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 286
    {pau3_pau7_fure         , "pau3_pau7_fure"          , 0x1303100F, PAU3::pau3_pau7_fure          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 287
    {iohs0_fure             , "iohs0_fure"              , 0x1803600F, AXON0::iohs0_fure             , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 288
    {iohs0_ndl_fure         , "iohs0_ndl_fure"          , 0x1803040F, AXON0::iohs0_ndl_fure         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 289
    {iohs0_pdl_fure         , "iohs0_pdl_fure"          , 0x1803020F, AXON0::iohs0_pdl_fure         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 290
    {iohs0_pll_func         , "iohs0_pll_func"          , 0x18030010, AXON0::iohs0_pll_func         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 291
    {iohs0_pll_bndy         , "iohs0_pll_bndy"          , 0x18030018, AXON0::iohs0_pll_bndy         , AXON0_TYPE, RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS             }, // 292
    {iohs0_pll_bndy_bucket_0, "iohs0_pll_bndy_bucket_0" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 293
    {iohs0_pll_bndy_bucket_1, "iohs0_pll_bndy_bucket_1" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 294
    {iohs0_pll_bndy_bucket_2, "iohs0_pll_bndy_bucket_2" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 295
    {iohs0_pll_bndy_bucket_3, "iohs0_pll_bndy_bucket_3" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 296
    {iohs0_pll_bndy_bucket_4, "iohs0_pll_bndy_bucket_4" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 297
    {iohs0_pll_bndy_bucket_5, "iohs0_pll_bndy_bucket_5" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 298
    {iohs0_pll_bndy_bucket_6, "iohs0_pll_bndy_bucket_6" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 299
    {iohs0_pll_bndy_bucket_7, "iohs0_pll_bndy_bucket_7" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 300
    {iohs1_fure             , "iohs1_fure"              , 0x1903600F, AXON1::iohs1_fure             , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 301
    {iohs1_ndl_fure         , "iohs1_ndl_fure"          , 0x1903040F, AXON1::iohs1_ndl_fure         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 302
    {iohs1_pdl_fure         , "iohs1_pdl_fure"          , 0x1903020F, AXON1::iohs1_pdl_fure         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 303
    {iohs1_pll_func         , "iohs1_pll_func"          , 0x19030010, AXON1::iohs1_pll_func         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 304
    {iohs2_fure             , "iohs2_fure"              , 0x1A03600F, AXON2::iohs2_fure             , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 305
    {iohs2_ndl_fure         , "iohs2_ndl_fure"          , 0x1A03040F, AXON2::iohs2_ndl_fure         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 306
    {iohs2_pdl_fure         , "iohs2_pdl_fure"          , 0x1A03020F, AXON2::iohs2_pdl_fure         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 307
    {iohs2_pll_func         , "iohs2_pll_func"          , 0x1A030010, AXON2::iohs2_pll_func         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 308
    {iohs3_fure             , "iohs3_fure"              , 0x1B03600F, AXON3::iohs3_fure             , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 309
    {iohs3_ndl_fure         , "iohs3_ndl_fure"          , 0x1B03040F, AXON3::iohs3_ndl_fure         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 310
    {iohs3_pdl_fure         , "iohs3_pdl_fure"          , 0x1B03020F, AXON3::iohs3_pdl_fure         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 311
    {iohs3_pll_func         , "iohs3_pll_func"          , 0x1B030010, AXON3::iohs3_pll_func         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 312
    {iohs4_fure             , "iohs4_fure"              , 0x1C03600F, AXON4::iohs4_fure             , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 313
    {iohs4_ndl_fure         , "iohs4_ndl_fure"          , 0x1C03040F, AXON4::iohs4_ndl_fure         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 314
    {iohs4_pdl_fure         , "iohs4_pdl_fure"          , 0x1C03020F, AXON4::iohs4_pdl_fure         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 315
    {iohs4_pll_func         , "iohs4_pll_func"          , 0x1C030010, AXON4::iohs4_pll_func         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 316
    {iohs5_fure             , "iohs5_fure"              , 0x1D03600F, AXON5::iohs5_fure             , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 317
    {iohs5_ndl_fure         , "iohs5_ndl_fure"          , 0x1D03040F, AXON5::iohs5_ndl_fure         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 318
    {iohs5_pdl_fure         , "iohs5_pdl_fure"          , 0x1D03020F, AXON5::iohs5_pdl_fure         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 319
    {iohs5_pll_func         , "iohs5_pll_func"          , 0x1D030010, AXON5::iohs5_pll_func         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 320
    {iohs6_fure             , "iohs6_fure"              , 0x1E03600F, AXON6::iohs6_fure             , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 321
    {iohs6_ndl_fure         , "iohs6_ndl_fure"          , 0x1E03040F, AXON6::iohs6_ndl_fure         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 322
    {iohs6_pdl_fure         , "iohs6_pdl_fure"          , 0x1E03020F, AXON6::iohs6_pdl_fure         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 323
    {iohs6_pll_func         , "iohs6_pll_func"          , 0x1E030010, AXON6::iohs6_pll_func         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 324
    {iohs7_fure             , "iohs7_fure"              , 0x1F03600F, AXON7::iohs7_fure             , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 325
    {iohs7_ndl_fure         , "iohs7_ndl_fure"          , 0x1F03040F, AXON7::iohs7_ndl_fure         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 326
    {iohs7_pdl_fure         , "iohs7_pdl_fure"          , 0x1F03020F, AXON7::iohs7_pdl_fure         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 327
    {iohs7_pll_func         , "iohs7_pll_func"          , 0x1F030010, AXON7::iohs7_pll_func         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                             }, // 328
    {eq_fure                , "eq_fure"                 , 0x2003402F, EQ::eq_fure                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 329
    {eq_cmsk                , "eq_cmsk"                 , 0x2003402A, EQ::eq_cmsk                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 330
    {eq_inex                , "eq_inex"                 , 0x2003402B, EQ::eq_inex                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 331
    {eq_mode                , "eq_mode"                 , 0x20034021, EQ::eq_mode                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 332
    {eq_clkadj_fure         , "eq_clkadj_fure"          , 0x2003001F, EQ::eq_clkadj_fure            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 333
    {eq_clkadj_cmsk         , "eq_clkadj_cmsk"          , 0x2003001A, EQ::eq_clkadj_cmsk            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 334
    {eq_clkadj_inex         , "eq_clkadj_inex"          , 0x2003001B, EQ::eq_clkadj_inex            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 335
    {eq_clkadj_mode         , "eq_clkadj_mode"          , 0x20030011, EQ::eq_clkadj_mode            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                             }, // 336
    {ec_cl2_fure            , "ec_cl2_fure"             , 0x2003200F, EQ::ec_cl2_fure               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 337
    {ec_cl2_cmsk            , "ec_cl2_cmsk"             , 0x2003200A, EQ::ec_cl2_cmsk               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 338
    {ec_cl2_inex            , "ec_cl2_inex"             , 0x2003200B, EQ::ec_cl2_inex               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 339
    {ec_cl2_mode            , "ec_cl2_mode"             , 0x20032001, EQ::ec_cl2_mode               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 340
    {ec_mma_fure            , "ec_mma_fure"             , 0x2083000F, EQ::ec_mma_fure               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 341
    {ec_mma_cmsk            , "ec_mma_cmsk"             , 0x2083000A, EQ::ec_mma_cmsk               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 342
    {ec_mma_inex            , "ec_mma_inex"             , 0x2083000B, EQ::ec_mma_inex               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 343
    {ec_l3_fure             , "ec_l3_fure"              , 0x2003020F, EQ::ec_l3_fure                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 344
    {ec_l3_cmsk             , "ec_l3_cmsk"              , 0x2003020A, EQ::ec_l3_cmsk                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 345
    {ec_l3_inex             , "ec_l3_inex"              , 0x2003020B, EQ::ec_l3_inex                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 346
    {ec_l3_mode             , "ec_l3_mode"              , 0x20030201, EQ::ec_l3_mode                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME            }, // 347
    {n0_abst                , "n0_abst"                 , 0x02036405, N0::n0_abst                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                               }, // 348
    {n1_abst                , "n1_abst"                 , 0x03035405, N1::n1_abst                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                               }, // 349
    {n1_nmmu1_abst          , "n1_nmmu1_abst"           , 0x03030205, N1::n1_nmmu1_abst             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                               }, // 350
    {ec_cl2_abst            , "ec_cl2_abst"             , 0x20032005, EQ::ec_cl2_abst               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                               }, // 351
    {ec_mma_abst            , "ec_mma_abst"             , 0x20830005, EQ::ec_mma_abst               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                               }, // 352
};
#endif

#ifdef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    // MVPD Rings:
    {PERV::perv_occ_gptr           , PERV_TYPE }, // 0
    {PERV::perv_occ_repr           , PERV_TYPE }, // 1
    {PERV::perv_occ_time           , PERV_TYPE }, // 2
    {PERV::pib_repr                , PERV_TYPE }, // 3
    {PERV::sbe_gptr                , PERV_TYPE }, // 4
    {PERV::sbe_repr                , PERV_TYPE }, // 5
    {PERV::sbe_time                , PERV_TYPE }, // 6
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 7
    {PERV::perv_dpll_gptr          , PERV_TYPE }, // 8
    {PERV::perv_pll_gptr           , PERV_TYPE }, // 9
    {N0::n0_gptr                   , N0_TYPE   }, // 10
    {N0::n0_repr                   , N0_TYPE   }, // 11
    {N0::n0_time                   , N0_TYPE   }, // 12
    {N1::n1_gptr                   , N1_TYPE   }, // 13
    {N1::n1_repr                   , N1_TYPE   }, // 14
    {N1::n1_time                   , N1_TYPE   }, // 15
    {N1::n1_nmmu1_gptr             , N1_TYPE   }, // 16
    {N1::n1_nmmu1_repr             , N1_TYPE   }, // 17
    {N1::n1_nmmu1_time             , N1_TYPE   }, // 18
    {PCI::pci_gptr                 , PCI_TYPE  }, // 19
    {PCI::pci_repr                 , PCI_TYPE  }, // 20
    {PCI::pci_time                 , PCI_TYPE  }, // 21
    {PCI::pci_pll_gptr             , PCI_TYPE  }, // 22
    {MC::mc_gptr                   , MC_TYPE   }, // 23
    {MC::mc_repr                   , MC_TYPE   }, // 24
    {MC::mc_time                   , MC_TYPE   }, // 25
    {MC::mc_pll_gptr               , MC_TYPE   }, // 26
    {PAU0::pau0_gptr               , PAU0_TYPE }, // 27
    {PAU0::pau0_repr               , PAU0_TYPE }, // 28
    {PAU0::pau0_time               , PAU0_TYPE }, // 29
    {PAU0::pau0_pau0_gptr          , PAU0_TYPE }, // 30
    {PAU0::pau0_pau0_repr          , PAU0_TYPE }, // 31
    {PAU0::pau0_pau0_time          , PAU0_TYPE }, // 32
    {PAU1::pau1_gptr               , PAU1_TYPE }, // 33
    {PAU1::pau1_repr               , PAU1_TYPE }, // 34
    {PAU1::pau1_time               , PAU1_TYPE }, // 35
    {PAU1::pau1_pau3_gptr          , PAU1_TYPE }, // 36
    {PAU1::pau1_pau3_repr          , PAU1_TYPE }, // 37
    {PAU1::pau1_pau3_time          , PAU1_TYPE }, // 38
    {PAU2::pau2_gptr               , PAU2_TYPE }, // 39
    {PAU2::pau2_repr               , PAU2_TYPE }, // 40
    {PAU2::pau2_time               , PAU2_TYPE }, // 41
    {PAU2::pau2_pau4_gptr          , PAU2_TYPE }, // 42
    {PAU2::pau2_pau4_repr          , PAU2_TYPE }, // 43
    {PAU2::pau2_pau4_time          , PAU2_TYPE }, // 44
    {PAU2::pau2_pau5_gptr          , PAU2_TYPE }, // 45
    {PAU2::pau2_pau5_repr          , PAU2_TYPE }, // 46
    {PAU2::pau2_pau5_time          , PAU2_TYPE }, // 47
    {PAU3::pau3_gptr               , PAU3_TYPE }, // 48
    {PAU3::pau3_repr               , PAU3_TYPE }, // 49
    {PAU3::pau3_time               , PAU3_TYPE }, // 50
    {PAU3::pau3_pau6_gptr          , PAU3_TYPE }, // 51
    {PAU3::pau3_pau6_repr          , PAU3_TYPE }, // 52
    {PAU3::pau3_pau6_time          , PAU3_TYPE }, // 53
    {PAU3::pau3_pau7_gptr          , PAU3_TYPE }, // 54
    {PAU3::pau3_pau7_repr          , PAU3_TYPE }, // 55
    {PAU3::pau3_pau7_time          , PAU3_TYPE }, // 56
    {AXON0::iohs0_gptr             , AXON0_TYPE}, // 57
    {AXON0::iohs0_repr             , AXON0_TYPE}, // 58
    {AXON0::iohs0_time             , AXON0_TYPE}, // 59
    {AXON0::iohs0_ndl_gptr         , AXON0_TYPE}, // 60
    {AXON0::iohs0_ndl_repr         , AXON0_TYPE}, // 61
    {AXON0::iohs0_ndl_time         , AXON0_TYPE}, // 62
    {AXON0::iohs0_pdl_gptr         , AXON0_TYPE}, // 63
    {AXON0::iohs0_pdl_repr         , AXON0_TYPE}, // 64
    {AXON0::iohs0_pdl_time         , AXON0_TYPE}, // 65
    {AXON0::iohs0_pll_gptr         , AXON0_TYPE}, // 66
    {AXON1::iohs1_gptr             , AXON1_TYPE}, // 67
    {AXON1::iohs1_repr             , AXON1_TYPE}, // 68
    {AXON1::iohs1_time             , AXON1_TYPE}, // 69
    {AXON1::iohs1_ndl_gptr         , AXON1_TYPE}, // 70
    {AXON1::iohs1_ndl_repr         , AXON1_TYPE}, // 71
    {AXON1::iohs1_ndl_time         , AXON1_TYPE}, // 72
    {AXON1::iohs1_pdl_gptr         , AXON1_TYPE}, // 73
    {AXON1::iohs1_pdl_repr         , AXON1_TYPE}, // 74
    {AXON1::iohs1_pdl_time         , AXON1_TYPE}, // 75
    {AXON1::iohs1_pll_gptr         , AXON1_TYPE}, // 76
    {AXON2::iohs2_gptr             , AXON2_TYPE}, // 77
    {AXON2::iohs2_repr             , AXON2_TYPE}, // 78
    {AXON2::iohs2_time             , AXON2_TYPE}, // 79
    {AXON2::iohs2_ndl_gptr         , AXON2_TYPE}, // 80
    {AXON2::iohs2_ndl_repr         , AXON2_TYPE}, // 81
    {AXON2::iohs2_ndl_time         , AXON2_TYPE}, // 82
    {AXON2::iohs2_pdl_gptr         , AXON2_TYPE}, // 83
    {AXON2::iohs2_pdl_repr         , AXON2_TYPE}, // 84
    {AXON2::iohs2_pdl_time         , AXON2_TYPE}, // 85
    {AXON2::iohs2_pll_gptr         , AXON2_TYPE}, // 86
    {AXON3::iohs3_gptr             , AXON3_TYPE}, // 87
    {AXON3::iohs3_repr             , AXON3_TYPE}, // 88
    {AXON3::iohs3_time             , AXON3_TYPE}, // 89
    {AXON3::iohs3_ndl_gptr         , AXON3_TYPE}, // 90
    {AXON3::iohs3_ndl_repr         , AXON3_TYPE}, // 91
    {AXON3::iohs3_ndl_time         , AXON3_TYPE}, // 92
    {AXON3::iohs3_pdl_gptr         , AXON3_TYPE}, // 93
    {AXON3::iohs3_pdl_repr         , AXON3_TYPE}, // 94
    {AXON3::iohs3_pdl_time         , AXON3_TYPE}, // 95
    {AXON3::iohs3_pll_gptr         , AXON3_TYPE}, // 96
    {AXON4::iohs4_gptr             , AXON4_TYPE}, // 97
    {AXON4::iohs4_repr             , AXON4_TYPE}, // 98
    {AXON4::iohs4_time             , AXON4_TYPE}, // 99
    {AXON4::iohs4_ndl_gptr         , AXON4_TYPE}, // 100
    {AXON4::iohs4_ndl_repr         , AXON4_TYPE}, // 101
    {AXON4::iohs4_ndl_time         , AXON4_TYPE}, // 102
    {AXON4::iohs4_pdl_gptr         , AXON4_TYPE}, // 103
    {AXON4::iohs4_pdl_repr         , AXON4_TYPE}, // 104
    {AXON4::iohs4_pdl_time         , AXON4_TYPE}, // 105
    {AXON4::iohs4_pll_gptr         , AXON4_TYPE}, // 106
    {AXON5::iohs5_gptr             , AXON5_TYPE}, // 107
    {AXON5::iohs5_repr             , AXON5_TYPE}, // 108
    {AXON5::iohs5_time             , AXON5_TYPE}, // 109
    {AXON5::iohs5_ndl_gptr         , AXON5_TYPE}, // 110
    {AXON5::iohs5_ndl_repr         , AXON5_TYPE}, // 111
    {AXON5::iohs5_ndl_time         , AXON5_TYPE}, // 112
    {AXON5::iohs5_pdl_gptr         , AXON5_TYPE}, // 113
    {AXON5::iohs5_pdl_repr         , AXON5_TYPE}, // 114
    {AXON5::iohs5_pdl_time         , AXON5_TYPE}, // 115
    {AXON5::iohs5_pll_gptr         , AXON5_TYPE}, // 116
    {AXON6::iohs6_gptr             , AXON6_TYPE}, // 117
    {AXON6::iohs6_repr             , AXON6_TYPE}, // 118
    {AXON6::iohs6_time             , AXON6_TYPE}, // 119
    {AXON6::iohs6_ndl_gptr         , AXON6_TYPE}, // 120
    {AXON6::iohs6_ndl_repr         , AXON6_TYPE}, // 121
    {AXON6::iohs6_ndl_time         , AXON6_TYPE}, // 122
    {AXON6::iohs6_pdl_gptr         , AXON6_TYPE}, // 123
    {AXON6::iohs6_pdl_repr         , AXON6_TYPE}, // 124
    {AXON6::iohs6_pdl_time         , AXON6_TYPE}, // 125
    {AXON6::iohs6_pll_gptr         , AXON6_TYPE}, // 126
    {AXON7::iohs7_gptr             , AXON7_TYPE}, // 127
    {AXON7::iohs7_repr             , AXON7_TYPE}, // 128
    {AXON7::iohs7_time             , AXON7_TYPE}, // 129
    {AXON7::iohs7_ndl_gptr         , AXON7_TYPE}, // 130
    {AXON7::iohs7_ndl_repr         , AXON7_TYPE}, // 131
    {AXON7::iohs7_ndl_time         , AXON7_TYPE}, // 132
    {AXON7::iohs7_pdl_gptr         , AXON7_TYPE}, // 133
    {AXON7::iohs7_pdl_repr         , AXON7_TYPE}, // 134
    {AXON7::iohs7_pdl_time         , AXON7_TYPE}, // 135
    {AXON7::iohs7_pll_gptr         , AXON7_TYPE}, // 136
    {EQ::eq_gptr                   , EQ_TYPE   }, // 137
    {EQ::eq_repr                   , EQ_TYPE   }, // 138
    {EQ::eq_time                   , EQ_TYPE   }, // 139
    {EQ::eq_clkadj_gptr            , EQ_TYPE   }, // 140
    {EQ::eq_clkadj_repr            , EQ_TYPE   }, // 141
    {EQ::eq_clkadj_time            , EQ_TYPE   }, // 142
    {EQ::ec_cl2_gptr               , EQ_TYPE   }, // 143
    {EQ::ec_cl2_repr               , EQ_TYPE   }, // 144
    {EQ::ec_cl2_time               , EQ_TYPE   }, // 145
    {EQ::ec1_cl2_repr              , EQ_TYPE   }, // 146
    {EQ::ec2_cl2_repr              , EQ_TYPE   }, // 147
    {EQ::ec3_cl2_repr              , EQ_TYPE   }, // 148
    {EQ::ec_mma_gptr               , EQ_TYPE   }, // 149
    {EQ::ec_mma_repr               , EQ_TYPE   }, // 150
    {EQ::ec_mma_time               , EQ_TYPE   }, // 151
    {EQ::ec1_mma_repr              , EQ_TYPE   }, // 152
    {EQ::ec2_mma_repr              , EQ_TYPE   }, // 153
    {EQ::ec3_mma_repr              , EQ_TYPE   }, // 154
    {EQ::ec_l3_gptr                , EQ_TYPE   }, // 155
    {EQ::ec_l3_repr                , EQ_TYPE   }, // 156
    {EQ::ec_l3_time                , EQ_TYPE   }, // 157
    {EQ::ec1_l3_repr               , EQ_TYPE   }, // 158
    {EQ::ec2_l3_repr               , EQ_TYPE   }, // 159
    {EQ::ec3_l3_repr               , EQ_TYPE   }, // 160

    // EKB Rings:
    {PERV::perv_fure               , PERV_TYPE }, // 256
    {PERV::sbe_fure                , PERV_TYPE }, // 257
    {PERV::occ_fure                , PERV_TYPE }, // 258
    {PERV::perv_dpll_func          , PERV_TYPE }, // 259
    {PERV::perv_dpll_bndy          , PERV_TYPE }, // 260
    {PERV::perv_dpll_time          , PERV_TYPE }, // 261
    {PERV::perv_pll_func           , PERV_TYPE }, // 262
    {PERV::perv_pll_bndy           , PERV_TYPE }, // 263
    {N0::n0_fure                   , N0_TYPE   }, // 264
    {N1::n1_fure                   , N1_TYPE   }, // 265
    {N1::n1_nmmu1_fure             , N1_TYPE   }, // 266
    {PCI::pci_fure                 , PCI_TYPE  }, // 267
    {PCI::pci_pll_func             , PCI_TYPE  }, // 268
    {PCI::pci_pll_bndy             , PCI_TYPE  }, // 269
    {MC::mc_fure                   , MC_TYPE   }, // 270
    {MC::mc_pll_func               , MC_TYPE   }, // 271
    {MC::mc_pll_bndy               , MC_TYPE   }, // 272
    {MC::mc_pll_bndy_bucket_0      , MC_TYPE   }, // 273
    {MC::mc_pll_bndy_bucket_1      , MC_TYPE   }, // 274
    {MC::mc_pll_bndy_bucket_2      , MC_TYPE   }, // 275
    {MC::mc_pll_bndy_bucket_3      , MC_TYPE   }, // 276
    {MC::mc_pll_bndy_bucket_4      , MC_TYPE   }, // 277
    {PAU0::pau0_fure               , PAU0_TYPE }, // 278
    {PAU0::pau0_pau0_fure          , PAU0_TYPE }, // 279
    {PAU1::pau1_fure               , PAU1_TYPE }, // 280
    {PAU1::pau1_pau3_fure          , PAU1_TYPE }, // 281
    {PAU2::pau2_fure               , PAU2_TYPE }, // 282
    {PAU2::pau2_pau4_fure          , PAU2_TYPE }, // 283
    {PAU2::pau2_pau5_fure          , PAU2_TYPE }, // 284
    {PAU3::pau3_fure               , PAU3_TYPE }, // 285
    {PAU3::pau3_pau6_fure          , PAU3_TYPE }, // 286
    {PAU3::pau3_pau7_fure          , PAU3_TYPE }, // 287
    {AXON0::iohs0_fure             , AXON0_TYPE}, // 288
    {AXON0::iohs0_ndl_fure         , AXON0_TYPE}, // 289
    {AXON0::iohs0_pdl_fure         , AXON0_TYPE}, // 290
    {AXON0::iohs0_pll_func         , AXON0_TYPE}, // 291
    {AXON0::iohs0_pll_bndy         , AXON0_TYPE}, // 292
    {AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE}, // 293
    {AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE}, // 294
    {AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE}, // 295
    {AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE}, // 296
    {AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE}, // 297
    {AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE}, // 298
    {AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE}, // 299
    {AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE}, // 300
    {AXON1::iohs1_fure             , AXON1_TYPE}, // 301
    {AXON1::iohs1_ndl_fure         , AXON1_TYPE}, // 302
    {AXON1::iohs1_pdl_fure         , AXON1_TYPE}, // 303
    {AXON1::iohs1_pll_func         , AXON1_TYPE}, // 304
    {AXON2::iohs2_fure             , AXON2_TYPE}, // 305
    {AXON2::iohs2_ndl_fure         , AXON2_TYPE}, // 306
    {AXON2::iohs2_pdl_fure         , AXON2_TYPE}, // 307
    {AXON2::iohs2_pll_func         , AXON2_TYPE}, // 308
    {AXON3::iohs3_fure             , AXON3_TYPE}, // 309
    {AXON3::iohs3_ndl_fure         , AXON3_TYPE}, // 310
    {AXON3::iohs3_pdl_fure         , AXON3_TYPE}, // 311
    {AXON3::iohs3_pll_func         , AXON3_TYPE}, // 312
    {AXON4::iohs4_fure             , AXON4_TYPE}, // 313
    {AXON4::iohs4_ndl_fure         , AXON4_TYPE}, // 314
    {AXON4::iohs4_pdl_fure         , AXON4_TYPE}, // 315
    {AXON4::iohs4_pll_func         , AXON4_TYPE}, // 316
    {AXON5::iohs5_fure             , AXON5_TYPE}, // 317
    {AXON5::iohs5_ndl_fure         , AXON5_TYPE}, // 318
    {AXON5::iohs5_pdl_fure         , AXON5_TYPE}, // 319
    {AXON5::iohs5_pll_func         , AXON5_TYPE}, // 320
    {AXON6::iohs6_fure             , AXON6_TYPE}, // 321
    {AXON6::iohs6_ndl_fure         , AXON6_TYPE}, // 322
    {AXON6::iohs6_pdl_fure         , AXON6_TYPE}, // 323
    {AXON6::iohs6_pll_func         , AXON6_TYPE}, // 324
    {AXON7::iohs7_fure             , AXON7_TYPE}, // 325
    {AXON7::iohs7_ndl_fure         , AXON7_TYPE}, // 326
    {AXON7::iohs7_pdl_fure         , AXON7_TYPE}, // 327
    {AXON7::iohs7_pll_func         , AXON7_TYPE}, // 328
    {EQ::eq_fure                   , EQ_TYPE   }, // 329
    {EQ::eq_cmsk                   , EQ_TYPE   }, // 330
    {EQ::eq_inex                   , EQ_TYPE   }, // 331
    {EQ::eq_mode                   , EQ_TYPE   }, // 332
    {EQ::eq_clkadj_fure            , EQ_TYPE   }, // 333
    {EQ::eq_clkadj_cmsk            , EQ_TYPE   }, // 334
    {EQ::eq_clkadj_inex            , EQ_TYPE   }, // 335
    {EQ::eq_clkadj_mode            , EQ_TYPE   }, // 336
    {EQ::ec_cl2_fure               , EQ_TYPE   }, // 337
    {EQ::ec_cl2_cmsk               , EQ_TYPE   }, // 338
    {EQ::ec_cl2_inex               , EQ_TYPE   }, // 339
    {EQ::ec_cl2_mode               , EQ_TYPE   }, // 340
    {EQ::ec_mma_fure               , EQ_TYPE   }, // 341
    {EQ::ec_mma_cmsk               , EQ_TYPE   }, // 342
    {EQ::ec_mma_inex               , EQ_TYPE   }, // 343
    {EQ::ec_l3_fure                , EQ_TYPE   }, // 344
    {EQ::ec_l3_cmsk                , EQ_TYPE   }, // 345
    {EQ::ec_l3_inex                , EQ_TYPE   }, // 346
    {EQ::ec_l3_mode                , EQ_TYPE   }, // 347
    {N0::n0_abst                   , N0_TYPE   }, // 348
    {N1::n1_abst                   , N1_TYPE   }, // 349
    {N1::n1_nmmu1_abst             , N1_TYPE   }, // 350
    {EQ::ec_cl2_abst               , EQ_TYPE   }, // 351
    {EQ::ec_mma_abst               , EQ_TYPE   }, // 352
};
#endif  // __PPE__

#endif  // _P10_RING_PROPERTIES_H_
