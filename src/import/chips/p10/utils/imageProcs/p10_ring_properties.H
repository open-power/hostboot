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

static const uint8_t RING_TABLE_VERSION_DOC = 23;
static const uint8_t RING_TABLE_VERSION_MVPD = 23;
static const uint8_t RING_TABLE_VERSION_EKB = 23;

#define RINGID_START_MVPD    (RingId_t)0
#define RINGID_END_MVPD      (RingId_t)167
#define RINGID_START_EKB     (RingId_t)256
#define RINGID_END_EKB       (RingId_t)411

#define RING_INDEX_START_MVPD   (RingId_t)0
#define RING_INDEX_START_EKB    (RingId_t)168

namespace PERV
{
enum RingOffset
{
    // Common Rings
    perv_occ_gptr            = 0,
    perv_occ_time            = 1,
    sbe_gptr                 = 2,
    perv_dpll_gptr           = 3,
    perv_pll_gptr            = 4,
    perv_dpll_func           = 5,
    perv_dpll_time           = 6,
    perv_pll_func            = 7,
    perv_func                = 8,
    sbe_func                 = 9,
    occ_func                 = 10,
    perv_pll_bndy_bucket_0   = 11,
    perv_pll_bndy_bucket_1   = 12,
    perv_pll_bndy_bucket_2   = 13,
    perv_pll_bndy_bucket_3   = 14,
    // Instance Rings
    perv_occ_repr            = (0 | INSTANCE_RING_MARK),
    pib_repr                 = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x01, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    15, // 15 common rings for PERV Chiplet
    2,  // 2 instance specific rings for PERV Chiplet
};
}; // end of namespace PERV

namespace N0
{
enum RingOffset
{
    // Common Rings
    n0_gptr                  = 0,
    n0_time                  = 1,
    n0_abst                  = 2,
    n0_func                  = 3,
    // Instance Rings
    n0_repr                  = (0 | INSTANCE_RING_MARK),
    n0_gptr_ovly             = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x02, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    4,  // 4 common rings for N0 Chiplet
    2,  // 2 instance specific rings for N0 Chiplet
};
}; // end of namespace N0

namespace N1
{
enum RingOffset
{
    // Common Rings
    n1_gptr                  = 0,
    n1_time                  = 1,
    n1_nmmu1_gptr            = 2,
    n1_nmmu1_time            = 3,
    n1_abst                  = 4,
    n1_nmmu1_abst            = 5,
    n1_func                  = 6,
    n1_nmmu1_func            = 7,
    // Instance Rings
    n1_repr                  = (0 | INSTANCE_RING_MARK),
    n1_nmmu1_repr            = (1 | INSTANCE_RING_MARK),
    n1_gptr_ovly             = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x03, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for N1 Chiplet
    3,  // 3 instance specific rings for N1 Chiplet
};
}; // end of namespace N1

namespace PCI
{
enum RingOffset
{
    // Common Rings
    pci_gptr                 = 0,
    pci_time                 = 1,
    pci_pll_gptr             = 2,
    pci_pll_func             = 3,
    pci_func                 = 4,
    pci_pll_bndy_bucket_0    = 5,
    pci_pll_bndy_bucket_1    = 6,
    pci_pll_bndy_bucket_2    = 7,
    pci_pll_bndy_bucket_3    = 8,
    // Instance Rings
    pci_repr                 = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x08, // Base chiplet/instance ID.
    2,  // Number of chiplet instances
    9,  // 9 common rings for PCI Chiplet
    1,  // 1 instance specific rings for PCI Chiplet
};
}; // end of namespace PCI

namespace MC
{
enum RingOffset
{
    // Common Rings
    mc_gptr                  = 0,
    mc_time                  = 1,
    mc_pll_gptr              = 2,
    mc_pll_func              = 3,
    mc_pll_bndy_bucket_0     = 4,
    mc_pll_bndy_bucket_1     = 5,
    mc_pll_bndy_bucket_2     = 6,
    mc_pll_bndy_bucket_3     = 7,
    mc_pll_bndy_bucket_4     = 8,
    mc_func                  = 9,
    mc_pll_bndy_bucket_5     = 10,
    mc_pll_bndy_bucket_6     = 11,
    mc_pll_bndy_bucket_7     = 12,
    // Instance Rings
    mc_repr                  = (0 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x0C, // Base chiplet/instance ID.
    4,  // Number of chiplet instances
    13, // 13 common rings for MC Chiplet
    1,  // 1 instance specific rings for MC Chiplet
};
}; // end of namespace MC

namespace PAU0
{
enum RingOffset
{
    // Common Rings
    pau0_gptr                = 0,
    pau0_time                = 1,
    pau0_pau0_gptr           = 2,
    pau0_pau0_time           = 3,
    pau0_func                = 4,
    pau0_pau0_func           = 5,
    // Instance Rings
    pau0_repr                = (0 | INSTANCE_RING_MARK),
    pau0_pau0_repr           = (1 | INSTANCE_RING_MARK),
    pau0_gptr_ovly           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x10, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    6,  // 6 common rings for PAU0 Chiplet
    3,  // 3 instance specific rings for PAU0 Chiplet
};
}; // end of namespace PAU0

namespace PAU1
{
enum RingOffset
{
    // Common Rings
    pau1_gptr                = 0,
    pau1_time                = 1,
    pau1_pau3_gptr           = 2,
    pau1_pau3_time           = 3,
    pau1_func                = 4,
    pau1_pau3_func           = 5,
    // Instance Rings
    pau1_repr                = (0 | INSTANCE_RING_MARK),
    pau1_pau3_repr           = (1 | INSTANCE_RING_MARK),
    pau1_gptr_ovly           = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x11, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    6,  // 6 common rings for PAU1 Chiplet
    3,  // 3 instance specific rings for PAU1 Chiplet
};
}; // end of namespace PAU1

namespace PAU2
{
enum RingOffset
{
    // Common Rings
    pau2_gptr                = 0,
    pau2_time                = 1,
    pau2_pau4_gptr           = 2,
    pau2_pau4_time           = 3,
    pau2_pau5_gptr           = 4,
    pau2_pau5_time           = 5,
    pau2_func                = 6,
    pau2_pau4_func           = 7,
    pau2_pau5_func           = 8,
    // Instance Rings
    pau2_repr                = (0 | INSTANCE_RING_MARK),
    pau2_pau4_repr           = (1 | INSTANCE_RING_MARK),
    pau2_pau5_repr           = (2 | INSTANCE_RING_MARK),
    pau2_gptr_ovly           = (3 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x12, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    9,  // 9 common rings for PAU2 Chiplet
    4,  // 4 instance specific rings for PAU2 Chiplet
};
}; // end of namespace PAU2

namespace PAU3
{
enum RingOffset
{
    // Common Rings
    pau3_gptr                = 0,
    pau3_time                = 1,
    pau3_pau6_gptr           = 2,
    pau3_pau6_time           = 3,
    pau3_pau7_gptr           = 4,
    pau3_pau7_time           = 5,
    pau3_func                = 6,
    pau3_pau6_func           = 7,
    pau3_pau7_func           = 8,
    // Instance Rings
    pau3_repr                = (0 | INSTANCE_RING_MARK),
    pau3_pau6_repr           = (1 | INSTANCE_RING_MARK),
    pau3_pau7_repr           = (2 | INSTANCE_RING_MARK),
    pau3_gptr_ovly           = (3 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x13, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    9,  // 9 common rings for PAU3 Chiplet
    4,  // 4 instance specific rings for PAU3 Chiplet
};
}; // end of namespace PAU3

namespace AXON0
{
enum RingOffset
{
    // Common Rings
    iohs0_gptr               = 0,
    iohs0_time               = 1,
    iohs0_pdl_gptr           = 2,
    iohs0_pdl_time           = 3,
    iohs0_pll_gptr           = 4,
    iohs0_pll_func           = 5,
    iohs0_pll_bndy_bucket_0  = 6,
    iohs0_pll_bndy_bucket_1  = 7,
    iohs0_pll_bndy_bucket_2  = 8,
    iohs0_pll_bndy_bucket_3  = 9,
    iohs0_pll_bndy_bucket_4  = 10,
    iohs0_pll_bndy_bucket_5  = 11,
    iohs0_pll_bndy_bucket_6  = 12,
    iohs0_pll_bndy_bucket_7  = 13,
    iohs0_func               = 14,
    iohs0_pdl_func           = 15,
    iohs0_pll_bndy_bucket_8  = 16,
    iohs0_pll_bndy_bucket_9  = 17,
    iohs0_pll_bndy_bucket_10 = 18,
    iohs0_pll_bndy_bucket_11 = 19,
    iohs0_pll_bndy_bucket_12 = 20,
    iohs0_pll_bndy_bucket_13 = 21,
    iohs0_pll_bndy_bucket_14 = 22,
    iohs0_pll_bndy_bucket_15 = 23,
    // Instance Rings
    iohs0_repr               = (0 | INSTANCE_RING_MARK),
    iohs0_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x18, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    24, // 24 common rings for AXON0 Chiplet
    2,  // 2 instance specific rings for AXON0 Chiplet
};
}; // end of namespace AXON0

namespace AXON1
{
enum RingOffset
{
    // Common Rings
    iohs1_gptr               = 0,
    iohs1_time               = 1,
    iohs1_pdl_gptr           = 2,
    iohs1_pdl_time           = 3,
    iohs1_pll_gptr           = 4,
    iohs1_pll_func           = 5,
    iohs1_func               = 6,
    iohs1_pdl_func           = 7,
    // Instance Rings
    iohs1_repr               = (0 | INSTANCE_RING_MARK),
    iohs1_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x19, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON1 Chiplet
    2,  // 2 instance specific rings for AXON1 Chiplet
};
}; // end of namespace AXON1

namespace AXON2
{
enum RingOffset
{
    // Common Rings
    iohs2_gptr               = 0,
    iohs2_time               = 1,
    iohs2_pdl_gptr           = 2,
    iohs2_pdl_time           = 3,
    iohs2_pll_gptr           = 4,
    iohs2_pll_func           = 5,
    iohs2_func               = 6,
    iohs2_pdl_func           = 7,
    // Instance Rings
    iohs2_repr               = (0 | INSTANCE_RING_MARK),
    iohs2_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1A, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON2 Chiplet
    2,  // 2 instance specific rings for AXON2 Chiplet
};
}; // end of namespace AXON2

namespace AXON3
{
enum RingOffset
{
    // Common Rings
    iohs3_gptr               = 0,
    iohs3_time               = 1,
    iohs3_pdl_gptr           = 2,
    iohs3_pdl_time           = 3,
    iohs3_pll_gptr           = 4,
    iohs3_pll_func           = 5,
    iohs3_func               = 6,
    iohs3_pdl_func           = 7,
    // Instance Rings
    iohs3_repr               = (0 | INSTANCE_RING_MARK),
    iohs3_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1B, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON3 Chiplet
    2,  // 2 instance specific rings for AXON3 Chiplet
};
}; // end of namespace AXON3

namespace AXON4
{
enum RingOffset
{
    // Common Rings
    iohs4_gptr               = 0,
    iohs4_time               = 1,
    iohs4_pdl_gptr           = 2,
    iohs4_pdl_time           = 3,
    iohs4_pll_gptr           = 4,
    iohs4_pll_func           = 5,
    iohs4_func               = 6,
    iohs4_pdl_func           = 7,
    // Instance Rings
    iohs4_repr               = (0 | INSTANCE_RING_MARK),
    iohs4_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1C, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON4 Chiplet
    2,  // 2 instance specific rings for AXON4 Chiplet
};
}; // end of namespace AXON4

namespace AXON5
{
enum RingOffset
{
    // Common Rings
    iohs5_gptr               = 0,
    iohs5_time               = 1,
    iohs5_pdl_gptr           = 2,
    iohs5_pdl_time           = 3,
    iohs5_pll_gptr           = 4,
    iohs5_pll_func           = 5,
    iohs5_func               = 6,
    iohs5_pdl_func           = 7,
    // Instance Rings
    iohs5_repr               = (0 | INSTANCE_RING_MARK),
    iohs5_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1D, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON5 Chiplet
    2,  // 2 instance specific rings for AXON5 Chiplet
};
}; // end of namespace AXON5

namespace AXON6
{
enum RingOffset
{
    // Common Rings
    iohs6_gptr               = 0,
    iohs6_time               = 1,
    iohs6_pdl_gptr           = 2,
    iohs6_pdl_time           = 3,
    iohs6_pll_gptr           = 4,
    iohs6_pll_func           = 5,
    iohs6_func               = 6,
    iohs6_pdl_func           = 7,
    // Instance Rings
    iohs6_repr               = (0 | INSTANCE_RING_MARK),
    iohs6_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1E, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON6 Chiplet
    2,  // 2 instance specific rings for AXON6 Chiplet
};
}; // end of namespace AXON6

namespace AXON7
{
enum RingOffset
{
    // Common Rings
    iohs7_gptr               = 0,
    iohs7_time               = 1,
    iohs7_pdl_gptr           = 2,
    iohs7_pdl_time           = 3,
    iohs7_pll_gptr           = 4,
    iohs7_pll_func           = 5,
    iohs7_func               = 6,
    iohs7_pdl_func           = 7,
    // Instance Rings
    iohs7_repr               = (0 | INSTANCE_RING_MARK),
    iohs7_pdl_repr           = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x1F, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    8,  // 8 common rings for AXON7 Chiplet
    2,  // 2 instance specific rings for AXON7 Chiplet
};
}; // end of namespace AXON7

namespace EQ
{
enum RingOffset
{
    // Common Rings
    eq_gptr                  = 0,
    eq_time                  = 1,
    eq_clkadj_gptr           = 2,
    ec_cl2_gptr              = 3,
    ec_cl2_time              = 4,
    ec_mma_gptr              = 5,
    ec_mma_time              = 6,
    ec_l3_gptr               = 7,
    ec_l3_time               = 8,
    eq_cmsk                  = 9,
    eq_mode                  = 10,
    eq_clkadj_cmsk           = 11,
    ec_cl2_cmsk              = 12,
    ec_cl2_inex              = 13,
    ec_cl2_mode              = 14,
    ec_mma_cmsk              = 15,
    ec_l3_cmsk               = 16,
    ec_l3_inex               = 17,
    ec_cl2_abst              = 18,
    ec_mma_abst              = 19,
    eq_func                  = 20,
    eq_clkadj_func           = 21,
    ec_cl2_func              = 22,
    ec_mma_func              = 23,
    ec_l3_func               = 24,
    eq_inex                  = 25,
    // Instance Rings
    eq_repr                  = (0 | INSTANCE_RING_MARK),
    ec_cl2_repr              = (1 | INSTANCE_RING_MARK),
    ec1_cl2_repr             = (2 | INSTANCE_RING_MARK),
    ec2_cl2_repr             = (3 | INSTANCE_RING_MARK),
    ec3_cl2_repr             = (4 | INSTANCE_RING_MARK),
    ec1_mma_repr             = (5 | INSTANCE_RING_MARK),
    ec2_mma_repr             = (6 | INSTANCE_RING_MARK),
    ec3_mma_repr             = (7 | INSTANCE_RING_MARK),
    ec_l3_repr               = (8 | INSTANCE_RING_MARK),
    ec1_l3_repr              = (9 | INSTANCE_RING_MARK),
    ec2_l3_repr              = (10 | INSTANCE_RING_MARK),
    ec3_l3_repr              = (11 | INSTANCE_RING_MARK),
    eq_gptr_ovly             = (12 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x20, // Base chiplet/instance ID.
    8,  // Number of chiplet instances
    26, // 26 common rings for EQ Chiplet
    13, // 13 instance specific rings for EQ Chiplet
};
}; // end of namespace EQ


#ifndef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    // MVPD Rings:
    {perv_occ_gptr           , "perv_occ_gptr"           , 0x01034902, PERV::perv_occ_gptr           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 0
    {perv_occ_repr           , "perv_occ_repr"           , 0x01034906, PERV::perv_occ_repr           , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 1
    {perv_occ_time           , "perv_occ_time"           , 0x01034907, PERV::perv_occ_time           , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 2
    {pib_repr                , "pib_repr"                , 0x01031006, PERV::pib_repr                , PERV_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 3
    {sbe_gptr                , "sbe_gptr"                , 0x01032002, PERV::sbe_gptr                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 4
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 5
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 6
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 7
    {perv_dpll_gptr          , "perv_dpll_gptr"          , 0x01030062, PERV::perv_dpll_gptr          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 8
    {perv_pll_gptr           , "perv_pll_gptr"           , 0x01030012, PERV::perv_pll_gptr           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 9
    {n0_gptr                 , "n0_gptr"                 , 0x02036402, N0::n0_gptr                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 10
    {n0_repr                 , "n0_repr"                 , 0x02036406, N0::n0_repr                   , N0_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 11
    {n0_time                 , "n0_time"                 , 0x02036407, N0::n0_time                   , N0_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 12
    {n1_gptr                 , "n1_gptr"                 , 0x03035402, N1::n1_gptr                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 13
    {n1_repr                 , "n1_repr"                 , 0x03035406, N1::n1_repr                   , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 14
    {n1_time                 , "n1_time"                 , 0x03035407, N1::n1_time                   , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 15
    {n1_nmmu1_gptr           , "n1_nmmu1_gptr"           , 0x03030202, N1::n1_nmmu1_gptr             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 16
    {n1_nmmu1_repr           , "n1_nmmu1_repr"           , 0x03030206, N1::n1_nmmu1_repr             , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 17
    {n1_nmmu1_time           , "n1_nmmu1_time"           , 0x03030207, N1::n1_nmmu1_time             , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 18
    {pci_gptr                , "pci_gptr"                , 0x08037F82, PCI::pci_gptr                 , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 19
    {pci_repr                , "pci_repr"                , 0x08037F86, PCI::pci_repr                 , PCI_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 20
    {pci_time                , "pci_time"                , 0x08037F87, PCI::pci_time                 , PCI_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 21
    {pci_pll_gptr            , "pci_pll_gptr"            , 0x08030012, PCI::pci_pll_gptr             , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 22
    {mc_gptr                 , "mc_gptr"                 , 0x0C036F02, MC::mc_gptr                   , MC_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 23
    {mc_repr                 , "mc_repr"                 , 0x0C036F06, MC::mc_repr                   , MC_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 24
    {mc_time                 , "mc_time"                 , 0x0C036F07, MC::mc_time                   , MC_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 25
    {mc_pll_gptr             , "mc_pll_gptr"             , 0x0C030012, MC::mc_pll_gptr               , MC_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 26
    {pau0_gptr               , "pau0_gptr"               , 0x10034302, PAU0::pau0_gptr               , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 27
    {pau0_repr               , "pau0_repr"               , 0x10034306, PAU0::pau0_repr               , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 28
    {pau0_time               , "pau0_time"               , 0x10034307, PAU0::pau0_time               , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 29
    {pau0_pau0_gptr          , "pau0_pau0_gptr"          , 0x10032002, PAU0::pau0_pau0_gptr          , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 30
    {pau0_pau0_repr          , "pau0_pau0_repr"          , 0x10032006, PAU0::pau0_pau0_repr          , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 31
    {pau0_pau0_time          , "pau0_pau0_time"          , 0x10032007, PAU0::pau0_pau0_time          , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 32
    {pau1_gptr               , "pau1_gptr"               , 0x11034302, PAU1::pau1_gptr               , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 33
    {pau1_repr               , "pau1_repr"               , 0x11034306, PAU1::pau1_repr               , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 34
    {pau1_time               , "pau1_time"               , 0x11034307, PAU1::pau1_time               , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 35
    {pau1_pau3_gptr          , "pau1_pau3_gptr"          , 0x11032002, PAU1::pau1_pau3_gptr          , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 36
    {pau1_pau3_repr          , "pau1_pau3_repr"          , 0x11032006, PAU1::pau1_pau3_repr          , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 37
    {pau1_pau3_time          , "pau1_pau3_time"          , 0x11032007, PAU1::pau1_pau3_time          , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 38
    {pau2_gptr               , "pau2_gptr"               , 0x12034302, PAU2::pau2_gptr               , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 39
    {pau2_repr               , "pau2_repr"               , 0x12034306, PAU2::pau2_repr               , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 40
    {pau2_time               , "pau2_time"               , 0x12034307, PAU2::pau2_time               , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 41
    {pau2_pau4_gptr          , "pau2_pau4_gptr"          , 0x12032002, PAU2::pau2_pau4_gptr          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 42
    {pau2_pau4_repr          , "pau2_pau4_repr"          , 0x12032006, PAU2::pau2_pau4_repr          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 43
    {pau2_pau4_time          , "pau2_pau4_time"          , 0x12032007, PAU2::pau2_pau4_time          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 44
    {pau2_pau5_gptr          , "pau2_pau5_gptr"          , 0x12031002, PAU2::pau2_pau5_gptr          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 45
    {pau2_pau5_repr          , "pau2_pau5_repr"          , 0x12031006, PAU2::pau2_pau5_repr          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 46
    {pau2_pau5_time          , "pau2_pau5_time"          , 0x12031007, PAU2::pau2_pau5_time          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 47
    {pau3_gptr               , "pau3_gptr"               , 0x13034302, PAU3::pau3_gptr               , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 48
    {pau3_repr               , "pau3_repr"               , 0x13034306, PAU3::pau3_repr               , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 49
    {pau3_time               , "pau3_time"               , 0x13034307, PAU3::pau3_time               , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 50
    {pau3_pau6_gptr          , "pau3_pau6_gptr"          , 0x13032002, PAU3::pau3_pau6_gptr          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 51
    {pau3_pau6_repr          , "pau3_pau6_repr"          , 0x13032006, PAU3::pau3_pau6_repr          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 52
    {pau3_pau6_time          , "pau3_pau6_time"          , 0x13032007, PAU3::pau3_pau6_time          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 53
    {pau3_pau7_gptr          , "pau3_pau7_gptr"          , 0x13031002, PAU3::pau3_pau7_gptr          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 54
    {pau3_pau7_repr          , "pau3_pau7_repr"          , 0x13031006, PAU3::pau3_pau7_repr          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 55
    {pau3_pau7_time          , "pau3_pau7_time"          , 0x13031007, PAU3::pau3_pau7_time          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 56
    {iohs0_gptr              , "iohs0_gptr"              , 0x18036002, AXON0::iohs0_gptr             , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 57
    {iohs0_repr              , "iohs0_repr"              , 0x18036006, AXON0::iohs0_repr             , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 58
    {iohs0_time              , "iohs0_time"              , 0x18036007, AXON0::iohs0_time             , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 59
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 60
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 61
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 62
    {iohs0_pdl_gptr          , "iohs0_pdl_gptr"          , 0x18030202, AXON0::iohs0_pdl_gptr         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 63
    {iohs0_pdl_repr          , "iohs0_pdl_repr"          , 0x18030206, AXON0::iohs0_pdl_repr         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 64
    {iohs0_pdl_time          , "iohs0_pdl_time"          , 0x18030207, AXON0::iohs0_pdl_time         , AXON0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 65
    {iohs0_pll_gptr          , "iohs0_pll_gptr"          , 0x18030012, AXON0::iohs0_pll_gptr         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 66
    {iohs1_gptr              , "iohs1_gptr"              , 0x19036002, AXON1::iohs1_gptr             , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 67
    {iohs1_repr              , "iohs1_repr"              , 0x19036006, AXON1::iohs1_repr             , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 68
    {iohs1_time              , "iohs1_time"              , 0x19036007, AXON1::iohs1_time             , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 69
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 70
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 71
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 72
    {iohs1_pdl_gptr          , "iohs1_pdl_gptr"          , 0x19030202, AXON1::iohs1_pdl_gptr         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 73
    {iohs1_pdl_repr          , "iohs1_pdl_repr"          , 0x19030206, AXON1::iohs1_pdl_repr         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 74
    {iohs1_pdl_time          , "iohs1_pdl_time"          , 0x19030207, AXON1::iohs1_pdl_time         , AXON1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 75
    {iohs1_pll_gptr          , "iohs1_pll_gptr"          , 0x19030012, AXON1::iohs1_pll_gptr         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 76
    {iohs2_gptr              , "iohs2_gptr"              , 0x1A036002, AXON2::iohs2_gptr             , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 77
    {iohs2_repr              , "iohs2_repr"              , 0x1A036006, AXON2::iohs2_repr             , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 78
    {iohs2_time              , "iohs2_time"              , 0x1A036007, AXON2::iohs2_time             , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 79
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 80
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 81
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 82
    {iohs2_pdl_gptr          , "iohs2_pdl_gptr"          , 0x1A030202, AXON2::iohs2_pdl_gptr         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 83
    {iohs2_pdl_repr          , "iohs2_pdl_repr"          , 0x1A030206, AXON2::iohs2_pdl_repr         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 84
    {iohs2_pdl_time          , "iohs2_pdl_time"          , 0x1A030207, AXON2::iohs2_pdl_time         , AXON2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 85
    {iohs2_pll_gptr          , "iohs2_pll_gptr"          , 0x1A030012, AXON2::iohs2_pll_gptr         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 86
    {iohs3_gptr              , "iohs3_gptr"              , 0x1B036002, AXON3::iohs3_gptr             , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 87
    {iohs3_repr              , "iohs3_repr"              , 0x1B036006, AXON3::iohs3_repr             , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 88
    {iohs3_time              , "iohs3_time"              , 0x1B036007, AXON3::iohs3_time             , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 89
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 90
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 91
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 92
    {iohs3_pdl_gptr          , "iohs3_pdl_gptr"          , 0x1B030202, AXON3::iohs3_pdl_gptr         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 93
    {iohs3_pdl_repr          , "iohs3_pdl_repr"          , 0x1B030206, AXON3::iohs3_pdl_repr         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 94
    {iohs3_pdl_time          , "iohs3_pdl_time"          , 0x1B030207, AXON3::iohs3_pdl_time         , AXON3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 95
    {iohs3_pll_gptr          , "iohs3_pll_gptr"          , 0x1B030012, AXON3::iohs3_pll_gptr         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 96
    {iohs4_gptr              , "iohs4_gptr"              , 0x1C036002, AXON4::iohs4_gptr             , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 97
    {iohs4_repr              , "iohs4_repr"              , 0x1C036006, AXON4::iohs4_repr             , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 98
    {iohs4_time              , "iohs4_time"              , 0x1C036007, AXON4::iohs4_time             , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 99
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 100
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 101
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 102
    {iohs4_pdl_gptr          , "iohs4_pdl_gptr"          , 0x1C030202, AXON4::iohs4_pdl_gptr         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 103
    {iohs4_pdl_repr          , "iohs4_pdl_repr"          , 0x1C030206, AXON4::iohs4_pdl_repr         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 104
    {iohs4_pdl_time          , "iohs4_pdl_time"          , 0x1C030207, AXON4::iohs4_pdl_time         , AXON4_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 105
    {iohs4_pll_gptr          , "iohs4_pll_gptr"          , 0x1C030012, AXON4::iohs4_pll_gptr         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 106
    {iohs5_gptr              , "iohs5_gptr"              , 0x1D036002, AXON5::iohs5_gptr             , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 107
    {iohs5_repr              , "iohs5_repr"              , 0x1D036006, AXON5::iohs5_repr             , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 108
    {iohs5_time              , "iohs5_time"              , 0x1D036007, AXON5::iohs5_time             , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 109
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 110
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 111
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 112
    {iohs5_pdl_gptr          , "iohs5_pdl_gptr"          , 0x1D030202, AXON5::iohs5_pdl_gptr         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 113
    {iohs5_pdl_repr          , "iohs5_pdl_repr"          , 0x1D030206, AXON5::iohs5_pdl_repr         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 114
    {iohs5_pdl_time          , "iohs5_pdl_time"          , 0x1D030207, AXON5::iohs5_pdl_time         , AXON5_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 115
    {iohs5_pll_gptr          , "iohs5_pll_gptr"          , 0x1D030012, AXON5::iohs5_pll_gptr         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 116
    {iohs6_gptr              , "iohs6_gptr"              , 0x1E036002, AXON6::iohs6_gptr             , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 117
    {iohs6_repr              , "iohs6_repr"              , 0x1E036006, AXON6::iohs6_repr             , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 118
    {iohs6_time              , "iohs6_time"              , 0x1E036007, AXON6::iohs6_time             , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 119
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 120
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 121
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 122
    {iohs6_pdl_gptr          , "iohs6_pdl_gptr"          , 0x1E030202, AXON6::iohs6_pdl_gptr         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 123
    {iohs6_pdl_repr          , "iohs6_pdl_repr"          , 0x1E030206, AXON6::iohs6_pdl_repr         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 124
    {iohs6_pdl_time          , "iohs6_pdl_time"          , 0x1E030207, AXON6::iohs6_pdl_time         , AXON6_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 125
    {iohs6_pll_gptr          , "iohs6_pll_gptr"          , 0x1E030012, AXON6::iohs6_pll_gptr         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 126
    {iohs7_gptr              , "iohs7_gptr"              , 0x1F036002, AXON7::iohs7_gptr             , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 127
    {iohs7_repr              , "iohs7_repr"              , 0x1F036006, AXON7::iohs7_repr             , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 128
    {iohs7_time              , "iohs7_time"              , 0x1F036007, AXON7::iohs7_time             , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 129
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 130
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 131
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 132
    {iohs7_pdl_gptr          , "iohs7_pdl_gptr"          , 0x1F030202, AXON7::iohs7_pdl_gptr         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 133
    {iohs7_pdl_repr          , "iohs7_pdl_repr"          , 0x1F030206, AXON7::iohs7_pdl_repr         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                       }, // 134
    {iohs7_pdl_time          , "iohs7_pdl_time"          , 0x1F030207, AXON7::iohs7_pdl_time         , AXON7_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 135
    {iohs7_pll_gptr          , "iohs7_pll_gptr"          , 0x1F030012, AXON7::iohs7_pll_gptr         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 136
    {eq_gptr                 , "eq_gptr"                 , 0x20034022, EQ::eq_gptr                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 137
    {eq_repr                 , "eq_repr"                 , 0x20034026, EQ::eq_repr                   , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_EQ                         }, // 138
    {eq_time                 , "eq_time"                 , 0x20034027, EQ::eq_time                   , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME                       }, // 139
    {eq_clkadj_gptr          , "eq_clkadj_gptr"          , 0x20030012, EQ::eq_clkadj_gptr            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                   }, // 140
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 141
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 142
    {ec_cl2_gptr             , "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME}, // 143
    {ec_cl2_repr             , "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 144
    {ec_cl2_time             , "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME    }, // 145
    {ec1_cl2_repr            , "ec1_cl2_repr"            , 0x20031006, EQ::ec1_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 146
    {ec2_cl2_repr            , "ec2_cl2_repr"            , 0x20030806, EQ::ec2_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 147
    {ec3_cl2_repr            , "ec3_cl2_repr"            , 0x20030406, EQ::ec3_cl2_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 148
    {ec_mma_gptr             , "ec_mma_gptr"             , 0x20830002, EQ::ec_mma_gptr               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME}, // 149
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 150
    {ec_mma_time             , "ec_mma_time"             , 0x20830007, EQ::ec_mma_time               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME    }, // 151
    {ec1_mma_repr            , "ec1_mma_repr"            , 0x20430006, EQ::ec1_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 152
    {ec2_mma_repr            , "ec2_mma_repr"            , 0x20230006, EQ::ec2_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 153
    {ec3_mma_repr            , "ec3_mma_repr"            , 0x20130006, EQ::ec3_mma_repr              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 154
    {ec_l3_gptr              , "ec_l3_gptr"              , 0x20030202, EQ::ec_l3_gptr                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME}, // 155
    {ec_l3_repr              , "ec_l3_repr"              , 0x20030206, EQ::ec_l3_repr                , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 156
    {ec_l3_time              , "ec_l3_time"              , 0x20030207, EQ::ec_l3_time                , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME    }, // 157
    {ec1_l3_repr             , "ec1_l3_repr"             , 0x20030106, EQ::ec1_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 158
    {ec2_l3_repr             , "ec2_l3_repr"             , 0x20030086, EQ::ec2_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 159
    {ec3_l3_repr             , "ec3_l3_repr"             , 0x20030046, EQ::ec3_l3_repr               , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME    }, // 160
    {n0_gptr_ovly            , "n0_gptr_ovly"            , 0x02036402, N0::n0_gptr_ovly              , N0_TYPE   , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 161
    {n1_gptr_ovly            , "n1_gptr_ovly"            , 0x03035402, N1::n1_gptr_ovly              , N1_TYPE   , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 162
    {pau0_gptr_ovly          , "pau0_gptr_ovly"          , 0x10034302, PAU0::pau0_gptr_ovly          , PAU0_TYPE , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 163
    {pau1_gptr_ovly          , "pau1_gptr_ovly"          , 0x11034302, PAU1::pau1_gptr_ovly          , PAU1_TYPE , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 164
    {pau2_gptr_ovly          , "pau2_gptr_ovly"          , 0x12034302, PAU2::pau2_gptr_ovly          , PAU2_TYPE , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 165
    {pau3_gptr_ovly          , "pau3_gptr_ovly"          , 0x13034302, PAU3::pau3_gptr_ovly          , PAU3_TYPE , RMRK_ROOT | RCLS_MVPD_PDS_NEST                       }, // 166
    {eq_gptr_ovly            , "eq_gptr_ovly"            , 0x20034022, EQ::eq_gptr_ovly              , EQ_TYPE   , RMRK_ROOT | RCLS_MVPD_PDS_EQ                         }, // 167

    // EKB Rings:
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 256
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 257
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 258
    {perv_dpll_func          , "perv_dpll_func"          , 0x01030060, PERV::perv_dpll_func          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 259
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 260
    {perv_dpll_time          , "perv_dpll_time"          , 0x01030067, PERV::perv_dpll_time          , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 261
    {perv_pll_func           , "perv_pll_func"           , 0x01030010, PERV::perv_pll_func           , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 262
    {perv_pll_bndy           , "perv_pll_bndy"           , 0x01030018, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE , RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS         }, // 263
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 264
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 265
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 266
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 267
    {pci_pll_func            , "pci_pll_func"            , 0x08030010, PCI::pci_pll_func             , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 268
    {pci_pll_bndy            , "pci_pll_bndy"            , 0x08030018, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE , RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS         }, // 269
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 270
    {mc_pll_func             , "mc_pll_func"             , 0x0C030010, MC::mc_pll_func               , MC_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 271
    {mc_pll_bndy             , "mc_pll_bndy"             , 0x0C030018, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE , RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS         }, // 272
    {mc_pll_bndy_bucket_0    , "mc_pll_bndy_bucket_0"    , 0x0C030018, MC::mc_pll_bndy_bucket_0      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 273
    {mc_pll_bndy_bucket_1    , "mc_pll_bndy_bucket_1"    , 0x0C030018, MC::mc_pll_bndy_bucket_1      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 274
    {mc_pll_bndy_bucket_2    , "mc_pll_bndy_bucket_2"    , 0x0C030018, MC::mc_pll_bndy_bucket_2      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 275
    {mc_pll_bndy_bucket_3    , "mc_pll_bndy_bucket_3"    , 0x0C030018, MC::mc_pll_bndy_bucket_3      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 276
    {mc_pll_bndy_bucket_4    , "mc_pll_bndy_bucket_4"    , 0x0C030018, MC::mc_pll_bndy_bucket_4      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 277
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 278
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 279
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 280
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 281
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 282
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 283
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 284
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 285
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 286
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 287
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 288
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 289
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 290
    {iohs0_pll_func          , "iohs0_pll_func"          , 0x18030010, AXON0::iohs0_pll_func         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 291
    {iohs0_pll_bndy          , "iohs0_pll_bndy"          , 0x18030018, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE , RMRK_ROOT | RMRK_HAS_DERIVS | RCLS_EKB_RINGS         }, // 292
    {iohs0_pll_bndy_bucket_0 , "iohs0_pll_bndy_bucket_0" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 293
    {iohs0_pll_bndy_bucket_1 , "iohs0_pll_bndy_bucket_1" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 294
    {iohs0_pll_bndy_bucket_2 , "iohs0_pll_bndy_bucket_2" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 295
    {iohs0_pll_bndy_bucket_3 , "iohs0_pll_bndy_bucket_3" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 296
    {iohs0_pll_bndy_bucket_4 , "iohs0_pll_bndy_bucket_4" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 297
    {iohs0_pll_bndy_bucket_5 , "iohs0_pll_bndy_bucket_5" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 298
    {iohs0_pll_bndy_bucket_6 , "iohs0_pll_bndy_bucket_6" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 299
    {iohs0_pll_bndy_bucket_7 , "iohs0_pll_bndy_bucket_7" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 300
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 301
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 302
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 303
    {iohs1_pll_func          , "iohs1_pll_func"          , 0x19030010, AXON1::iohs1_pll_func         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 304
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 305
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 306
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 307
    {iohs2_pll_func          , "iohs2_pll_func"          , 0x1A030010, AXON2::iohs2_pll_func         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 308
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 309
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 310
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 311
    {iohs3_pll_func          , "iohs3_pll_func"          , 0x1B030010, AXON3::iohs3_pll_func         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 312
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 313
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 314
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 315
    {iohs4_pll_func          , "iohs4_pll_func"          , 0x1C030010, AXON4::iohs4_pll_func         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 316
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 317
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 318
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 319
    {iohs5_pll_func          , "iohs5_pll_func"          , 0x1D030010, AXON5::iohs5_pll_func         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 320
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 321
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 322
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 323
    {iohs6_pll_func          , "iohs6_pll_func"          , 0x1E030010, AXON6::iohs6_pll_func         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 324
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 325
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 326
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 327
    {iohs7_pll_func          , "iohs7_pll_func"          , 0x1F030010, AXON7::iohs7_pll_func         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 328
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 329
    {eq_cmsk                 , "eq_cmsk"                 , 0x2003402A, EQ::eq_cmsk                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 330
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 331
    {eq_mode                 , "eq_mode"                 , 0x20034021, EQ::eq_mode                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 332
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 333
    {eq_clkadj_cmsk          , "eq_clkadj_cmsk"          , 0x2003001A, EQ::eq_clkadj_cmsk            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 334
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 335
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 336
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 337
    {ec_cl2_cmsk             , "ec_cl2_cmsk"             , 0x2003200A, EQ::ec_cl2_cmsk               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 338
    {ec_cl2_inex             , "ec_cl2_inex"             , 0x2003200B, EQ::ec_cl2_inex               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 339
    {ec_cl2_mode             , "ec_cl2_mode"             , 0x20032001, EQ::ec_cl2_mode               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 340
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 341
    {ec_mma_cmsk             , "ec_mma_cmsk"             , 0x2083000A, EQ::ec_mma_cmsk               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 342
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 343
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 344
    {ec_l3_cmsk              , "ec_l3_cmsk"              , 0x2003020A, EQ::ec_l3_cmsk                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 345
    {ec_l3_inex              , "ec_l3_inex"              , 0x2003020B, EQ::ec_l3_inex                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 346
    {HOLE_RING_ID            , "invalid"                 , UNDEFINED_SCOM_ADDR, UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE, UNDEFINED_RING_CLASS                                 }, // 347
    {n0_abst                 , "n0_abst"                 , 0x02036405, N0::n0_abst                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 348
    {n1_abst                 , "n1_abst"                 , 0x03035405, N1::n1_abst                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 349
    {n1_nmmu1_abst           , "n1_nmmu1_abst"           , 0x03030205, N1::n1_nmmu1_abst             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 350
    {ec_cl2_abst             , "ec_cl2_abst"             , 0x20032005, EQ::ec_cl2_abst               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 351
    {ec_mma_abst             , "ec_mma_abst"             , 0x20830005, EQ::ec_mma_abst               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 352
    {perv_func               , "perv_func"               , 0x01034100, PERV::perv_func               , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 353
    {sbe_func                , "sbe_func"                , 0x01032000, PERV::sbe_func                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 354
    {occ_func                , "occ_func"                , 0x01030800, PERV::occ_func                , PERV_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 355
    {perv_pll_bndy_bucket_0  , "perv_pll_bndy_bucket_0"  , 0x01030018, PERV::perv_pll_bndy_bucket_0  , PERV_TYPE , RCLS_EKB_RINGS                                       }, // 356
    {perv_pll_bndy_bucket_1  , "perv_pll_bndy_bucket_1"  , 0x01030018, PERV::perv_pll_bndy_bucket_1  , PERV_TYPE , RCLS_EKB_RINGS                                       }, // 357
    {perv_pll_bndy_bucket_2  , "perv_pll_bndy_bucket_2"  , 0x01030018, PERV::perv_pll_bndy_bucket_2  , PERV_TYPE , RCLS_EKB_RINGS                                       }, // 358
    {perv_pll_bndy_bucket_3  , "perv_pll_bndy_bucket_3"  , 0x01030018, PERV::perv_pll_bndy_bucket_3  , PERV_TYPE , RCLS_EKB_RINGS                                       }, // 359
    {n0_func                 , "n0_func"                 , 0x02036400, N0::n0_func                   , N0_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 360
    {n1_func                 , "n1_func"                 , 0x03035400, N1::n1_func                   , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 361
    {n1_nmmu1_func           , "n1_nmmu1_func"           , 0x03030200, N1::n1_nmmu1_func             , N1_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 362
    {pci_func                , "pci_func"                , 0x08037F80, PCI::pci_func                 , PCI_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 363
    {pci_pll_bndy_bucket_0   , "pci_pll_bndy_bucket_0"   , 0x08030018, PCI::pci_pll_bndy_bucket_0    , PCI_TYPE  , RCLS_EKB_RINGS                                       }, // 364
    {pci_pll_bndy_bucket_1   , "pci_pll_bndy_bucket_1"   , 0x08030018, PCI::pci_pll_bndy_bucket_1    , PCI_TYPE  , RCLS_EKB_RINGS                                       }, // 365
    {pci_pll_bndy_bucket_2   , "pci_pll_bndy_bucket_2"   , 0x08030018, PCI::pci_pll_bndy_bucket_2    , PCI_TYPE  , RCLS_EKB_RINGS                                       }, // 366
    {pci_pll_bndy_bucket_3   , "pci_pll_bndy_bucket_3"   , 0x08030018, PCI::pci_pll_bndy_bucket_3    , PCI_TYPE  , RCLS_EKB_RINGS                                       }, // 367
    {mc_func                 , "mc_func"                 , 0x0C036F00, MC::mc_func                   , MC_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 368
    {mc_pll_bndy_bucket_5    , "mc_pll_bndy_bucket_5"    , 0x0C030018, MC::mc_pll_bndy_bucket_5      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 369
    {mc_pll_bndy_bucket_6    , "mc_pll_bndy_bucket_6"    , 0x0C030018, MC::mc_pll_bndy_bucket_6      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 370
    {mc_pll_bndy_bucket_7    , "mc_pll_bndy_bucket_7"    , 0x0C030018, MC::mc_pll_bndy_bucket_7      , MC_TYPE   , RCLS_EKB_RINGS                                       }, // 371
    {pau0_func               , "pau0_func"               , 0x10034300, PAU0::pau0_func               , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 372
    {pau0_pau0_func          , "pau0_pau0_func"          , 0x10032000, PAU0::pau0_pau0_func          , PAU0_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 373
    {pau1_func               , "pau1_func"               , 0x11034300, PAU1::pau1_func               , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 374
    {pau1_pau3_func          , "pau1_pau3_func"          , 0x11032000, PAU1::pau1_pau3_func          , PAU1_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 375
    {pau2_func               , "pau2_func"               , 0x12034300, PAU2::pau2_func               , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 376
    {pau2_pau4_func          , "pau2_pau4_func"          , 0x12032000, PAU2::pau2_pau4_func          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 377
    {pau2_pau5_func          , "pau2_pau5_func"          , 0x12031000, PAU2::pau2_pau5_func          , PAU2_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 378
    {pau3_func               , "pau3_func"               , 0x13034300, PAU3::pau3_func               , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 379
    {pau3_pau6_func          , "pau3_pau6_func"          , 0x13032000, PAU3::pau3_pau6_func          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 380
    {pau3_pau7_func          , "pau3_pau7_func"          , 0x13031000, PAU3::pau3_pau7_func          , PAU3_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 381
    {iohs0_func              , "iohs0_func"              , 0x18036000, AXON0::iohs0_func             , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 382
    {iohs0_pdl_func          , "iohs0_pdl_func"          , 0x18030200, AXON0::iohs0_pdl_func         , AXON0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 383
    {iohs0_pll_bndy_bucket_8 , "iohs0_pll_bndy_bucket_8" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_8, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 384
    {iohs0_pll_bndy_bucket_9 , "iohs0_pll_bndy_bucket_9" , 0x18030018, AXON0::iohs0_pll_bndy_bucket_9, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 385
    {iohs0_pll_bndy_bucket_10, "iohs0_pll_bndy_bucket_10", 0x18030018, AXON0::iohs0_pll_bndy_bucket_10, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 386
    {iohs0_pll_bndy_bucket_11, "iohs0_pll_bndy_bucket_11", 0x18030018, AXON0::iohs0_pll_bndy_bucket_11, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 387
    {iohs0_pll_bndy_bucket_12, "iohs0_pll_bndy_bucket_12", 0x18030018, AXON0::iohs0_pll_bndy_bucket_12, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 388
    {iohs0_pll_bndy_bucket_13, "iohs0_pll_bndy_bucket_13", 0x18030018, AXON0::iohs0_pll_bndy_bucket_13, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 389
    {iohs0_pll_bndy_bucket_14, "iohs0_pll_bndy_bucket_14", 0x18030018, AXON0::iohs0_pll_bndy_bucket_14, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 390
    {iohs0_pll_bndy_bucket_15, "iohs0_pll_bndy_bucket_15", 0x18030018, AXON0::iohs0_pll_bndy_bucket_15, AXON0_TYPE, RCLS_EKB_RINGS                                       }, // 391
    {iohs1_func              , "iohs1_func"              , 0x19036000, AXON1::iohs1_func             , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 392
    {iohs1_pdl_func          , "iohs1_pdl_func"          , 0x19030200, AXON1::iohs1_pdl_func         , AXON1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 393
    {iohs2_func              , "iohs2_func"              , 0x1A036000, AXON2::iohs2_func             , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 394
    {iohs2_pdl_func          , "iohs2_pdl_func"          , 0x1A030200, AXON2::iohs2_pdl_func         , AXON2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 395
    {iohs3_func              , "iohs3_func"              , 0x1B036000, AXON3::iohs3_func             , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 396
    {iohs3_pdl_func          , "iohs3_pdl_func"          , 0x1B030200, AXON3::iohs3_pdl_func         , AXON3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 397
    {iohs4_func              , "iohs4_func"              , 0x1C036000, AXON4::iohs4_func             , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 398
    {iohs4_pdl_func          , "iohs4_pdl_func"          , 0x1C030200, AXON4::iohs4_pdl_func         , AXON4_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 399
    {iohs5_func              , "iohs5_func"              , 0x1D036000, AXON5::iohs5_func             , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 400
    {iohs5_pdl_func          , "iohs5_pdl_func"          , 0x1D030200, AXON5::iohs5_pdl_func         , AXON5_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 401
    {iohs6_func              , "iohs6_func"              , 0x1E036000, AXON6::iohs6_func             , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 402
    {iohs6_pdl_func          , "iohs6_pdl_func"          , 0x1E030200, AXON6::iohs6_pdl_func         , AXON6_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 403
    {iohs7_func              , "iohs7_func"              , 0x1F036000, AXON7::iohs7_func             , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 404
    {iohs7_pdl_func          , "iohs7_pdl_func"          , 0x1F030200, AXON7::iohs7_pdl_func         , AXON7_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                           }, // 405
    {eq_func                 , "eq_func"                 , 0x20034020, EQ::eq_func                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 406
    {eq_clkadj_func          , "eq_clkadj_func"          , 0x20030010, EQ::eq_clkadj_func            , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS                           }, // 407
    {ec_cl2_func             , "ec_cl2_func"             , 0x20032000, EQ::ec_cl2_func               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 408
    {ec_mma_func             , "ec_mma_func"             , 0x20830000, EQ::ec_mma_func               , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 409
    {ec_l3_func              , "ec_l3_func"              , 0x20030200, EQ::ec_l3_func                , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 410
    {eq_inex                 , "eq_inex"                 , 0x2003402B, EQ::eq_inex                   , EQ_TYPE   , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME        }, // 411
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
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 5
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 6
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
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 60
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 61
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 62
    {AXON0::iohs0_pdl_gptr         , AXON0_TYPE}, // 63
    {AXON0::iohs0_pdl_repr         , AXON0_TYPE}, // 64
    {AXON0::iohs0_pdl_time         , AXON0_TYPE}, // 65
    {AXON0::iohs0_pll_gptr         , AXON0_TYPE}, // 66
    {AXON1::iohs1_gptr             , AXON1_TYPE}, // 67
    {AXON1::iohs1_repr             , AXON1_TYPE}, // 68
    {AXON1::iohs1_time             , AXON1_TYPE}, // 69
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 70
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 71
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 72
    {AXON1::iohs1_pdl_gptr         , AXON1_TYPE}, // 73
    {AXON1::iohs1_pdl_repr         , AXON1_TYPE}, // 74
    {AXON1::iohs1_pdl_time         , AXON1_TYPE}, // 75
    {AXON1::iohs1_pll_gptr         , AXON1_TYPE}, // 76
    {AXON2::iohs2_gptr             , AXON2_TYPE}, // 77
    {AXON2::iohs2_repr             , AXON2_TYPE}, // 78
    {AXON2::iohs2_time             , AXON2_TYPE}, // 79
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 80
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 81
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 82
    {AXON2::iohs2_pdl_gptr         , AXON2_TYPE}, // 83
    {AXON2::iohs2_pdl_repr         , AXON2_TYPE}, // 84
    {AXON2::iohs2_pdl_time         , AXON2_TYPE}, // 85
    {AXON2::iohs2_pll_gptr         , AXON2_TYPE}, // 86
    {AXON3::iohs3_gptr             , AXON3_TYPE}, // 87
    {AXON3::iohs3_repr             , AXON3_TYPE}, // 88
    {AXON3::iohs3_time             , AXON3_TYPE}, // 89
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 90
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 91
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 92
    {AXON3::iohs3_pdl_gptr         , AXON3_TYPE}, // 93
    {AXON3::iohs3_pdl_repr         , AXON3_TYPE}, // 94
    {AXON3::iohs3_pdl_time         , AXON3_TYPE}, // 95
    {AXON3::iohs3_pll_gptr         , AXON3_TYPE}, // 96
    {AXON4::iohs4_gptr             , AXON4_TYPE}, // 97
    {AXON4::iohs4_repr             , AXON4_TYPE}, // 98
    {AXON4::iohs4_time             , AXON4_TYPE}, // 99
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 100
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 101
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 102
    {AXON4::iohs4_pdl_gptr         , AXON4_TYPE}, // 103
    {AXON4::iohs4_pdl_repr         , AXON4_TYPE}, // 104
    {AXON4::iohs4_pdl_time         , AXON4_TYPE}, // 105
    {AXON4::iohs4_pll_gptr         , AXON4_TYPE}, // 106
    {AXON5::iohs5_gptr             , AXON5_TYPE}, // 107
    {AXON5::iohs5_repr             , AXON5_TYPE}, // 108
    {AXON5::iohs5_time             , AXON5_TYPE}, // 109
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 110
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 111
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 112
    {AXON5::iohs5_pdl_gptr         , AXON5_TYPE}, // 113
    {AXON5::iohs5_pdl_repr         , AXON5_TYPE}, // 114
    {AXON5::iohs5_pdl_time         , AXON5_TYPE}, // 115
    {AXON5::iohs5_pll_gptr         , AXON5_TYPE}, // 116
    {AXON6::iohs6_gptr             , AXON6_TYPE}, // 117
    {AXON6::iohs6_repr             , AXON6_TYPE}, // 118
    {AXON6::iohs6_time             , AXON6_TYPE}, // 119
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 120
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 121
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 122
    {AXON6::iohs6_pdl_gptr         , AXON6_TYPE}, // 123
    {AXON6::iohs6_pdl_repr         , AXON6_TYPE}, // 124
    {AXON6::iohs6_pdl_time         , AXON6_TYPE}, // 125
    {AXON6::iohs6_pll_gptr         , AXON6_TYPE}, // 126
    {AXON7::iohs7_gptr             , AXON7_TYPE}, // 127
    {AXON7::iohs7_repr             , AXON7_TYPE}, // 128
    {AXON7::iohs7_time             , AXON7_TYPE}, // 129
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 130
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 131
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 132
    {AXON7::iohs7_pdl_gptr         , AXON7_TYPE}, // 133
    {AXON7::iohs7_pdl_repr         , AXON7_TYPE}, // 134
    {AXON7::iohs7_pdl_time         , AXON7_TYPE}, // 135
    {AXON7::iohs7_pll_gptr         , AXON7_TYPE}, // 136
    {EQ::eq_gptr                   , EQ_TYPE   }, // 137
    {EQ::eq_repr                   , EQ_TYPE   }, // 138
    {EQ::eq_time                   , EQ_TYPE   }, // 139
    {EQ::eq_clkadj_gptr            , EQ_TYPE   }, // 140
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 141
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 142
    {EQ::ec_cl2_gptr               , EQ_TYPE   }, // 143
    {EQ::ec_cl2_repr               , EQ_TYPE   }, // 144
    {EQ::ec_cl2_time               , EQ_TYPE   }, // 145
    {EQ::ec1_cl2_repr              , EQ_TYPE   }, // 146
    {EQ::ec2_cl2_repr              , EQ_TYPE   }, // 147
    {EQ::ec3_cl2_repr              , EQ_TYPE   }, // 148
    {EQ::ec_mma_gptr               , EQ_TYPE   }, // 149
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 150
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
    {N0::n0_gptr_ovly              , N0_TYPE   }, // 161
    {N1::n1_gptr_ovly              , N1_TYPE   }, // 162
    {PAU0::pau0_gptr_ovly          , PAU0_TYPE }, // 163
    {PAU1::pau1_gptr_ovly          , PAU1_TYPE }, // 164
    {PAU2::pau2_gptr_ovly          , PAU2_TYPE }, // 165
    {PAU3::pau3_gptr_ovly          , PAU3_TYPE }, // 166
    {EQ::eq_gptr_ovly              , EQ_TYPE   }, // 167

    // EKB Rings:
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 256
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 257
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 258
    {PERV::perv_dpll_func          , PERV_TYPE }, // 259
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 260
    {PERV::perv_dpll_time          , PERV_TYPE }, // 261
    {PERV::perv_pll_func           , PERV_TYPE }, // 262
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 263
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 264
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 265
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 266
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 267
    {PCI::pci_pll_func             , PCI_TYPE  }, // 268
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 269
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 270
    {MC::mc_pll_func               , MC_TYPE   }, // 271
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 272
    {MC::mc_pll_bndy_bucket_0      , MC_TYPE   }, // 273
    {MC::mc_pll_bndy_bucket_1      , MC_TYPE   }, // 274
    {MC::mc_pll_bndy_bucket_2      , MC_TYPE   }, // 275
    {MC::mc_pll_bndy_bucket_3      , MC_TYPE   }, // 276
    {MC::mc_pll_bndy_bucket_4      , MC_TYPE   }, // 277
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 278
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 279
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 280
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 281
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 282
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 283
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 284
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 285
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 286
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 287
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 288
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 289
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 290
    {AXON0::iohs0_pll_func         , AXON0_TYPE}, // 291
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 292
    {AXON0::iohs0_pll_bndy_bucket_0, AXON0_TYPE}, // 293
    {AXON0::iohs0_pll_bndy_bucket_1, AXON0_TYPE}, // 294
    {AXON0::iohs0_pll_bndy_bucket_2, AXON0_TYPE}, // 295
    {AXON0::iohs0_pll_bndy_bucket_3, AXON0_TYPE}, // 296
    {AXON0::iohs0_pll_bndy_bucket_4, AXON0_TYPE}, // 297
    {AXON0::iohs0_pll_bndy_bucket_5, AXON0_TYPE}, // 298
    {AXON0::iohs0_pll_bndy_bucket_6, AXON0_TYPE}, // 299
    {AXON0::iohs0_pll_bndy_bucket_7, AXON0_TYPE}, // 300
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 301
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 302
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 303
    {AXON1::iohs1_pll_func         , AXON1_TYPE}, // 304
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 305
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 306
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 307
    {AXON2::iohs2_pll_func         , AXON2_TYPE}, // 308
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 309
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 310
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 311
    {AXON3::iohs3_pll_func         , AXON3_TYPE}, // 312
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 313
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 314
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 315
    {AXON4::iohs4_pll_func         , AXON4_TYPE}, // 316
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 317
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 318
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 319
    {AXON5::iohs5_pll_func         , AXON5_TYPE}, // 320
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 321
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 322
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 323
    {AXON6::iohs6_pll_func         , AXON6_TYPE}, // 324
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 325
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 326
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 327
    {AXON7::iohs7_pll_func         , AXON7_TYPE}, // 328
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 329
    {EQ::eq_cmsk                   , EQ_TYPE   }, // 330
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 331
    {EQ::eq_mode                   , EQ_TYPE   }, // 332
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 333
    {EQ::eq_clkadj_cmsk            , EQ_TYPE   }, // 334
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 335
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 336
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 337
    {EQ::ec_cl2_cmsk               , EQ_TYPE   }, // 338
    {EQ::ec_cl2_inex               , EQ_TYPE   }, // 339
    {EQ::ec_cl2_mode               , EQ_TYPE   }, // 340
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 341
    {EQ::ec_mma_cmsk               , EQ_TYPE   }, // 342
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 343
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 344
    {EQ::ec_l3_cmsk                , EQ_TYPE   }, // 345
    {EQ::ec_l3_inex                , EQ_TYPE   }, // 346
    {UNDEFINED_RING_INDEX          , UNDEFINED_CHIPLET_TYPE}, // 347
    {N0::n0_abst                   , N0_TYPE   }, // 348
    {N1::n1_abst                   , N1_TYPE   }, // 349
    {N1::n1_nmmu1_abst             , N1_TYPE   }, // 350
    {EQ::ec_cl2_abst               , EQ_TYPE   }, // 351
    {EQ::ec_mma_abst               , EQ_TYPE   }, // 352
    {PERV::perv_func               , PERV_TYPE }, // 353
    {PERV::sbe_func                , PERV_TYPE }, // 354
    {PERV::occ_func                , PERV_TYPE }, // 355
    {PERV::perv_pll_bndy_bucket_0  , PERV_TYPE }, // 356
    {PERV::perv_pll_bndy_bucket_1  , PERV_TYPE }, // 357
    {PERV::perv_pll_bndy_bucket_2  , PERV_TYPE }, // 358
    {PERV::perv_pll_bndy_bucket_3  , PERV_TYPE }, // 359
    {N0::n0_func                   , N0_TYPE   }, // 360
    {N1::n1_func                   , N1_TYPE   }, // 361
    {N1::n1_nmmu1_func             , N1_TYPE   }, // 362
    {PCI::pci_func                 , PCI_TYPE  }, // 363
    {PCI::pci_pll_bndy_bucket_0    , PCI_TYPE  }, // 364
    {PCI::pci_pll_bndy_bucket_1    , PCI_TYPE  }, // 365
    {PCI::pci_pll_bndy_bucket_2    , PCI_TYPE  }, // 366
    {PCI::pci_pll_bndy_bucket_3    , PCI_TYPE  }, // 367
    {MC::mc_func                   , MC_TYPE   }, // 368
    {MC::mc_pll_bndy_bucket_5      , MC_TYPE   }, // 369
    {MC::mc_pll_bndy_bucket_6      , MC_TYPE   }, // 370
    {MC::mc_pll_bndy_bucket_7      , MC_TYPE   }, // 371
    {PAU0::pau0_func               , PAU0_TYPE }, // 372
    {PAU0::pau0_pau0_func          , PAU0_TYPE }, // 373
    {PAU1::pau1_func               , PAU1_TYPE }, // 374
    {PAU1::pau1_pau3_func          , PAU1_TYPE }, // 375
    {PAU2::pau2_func               , PAU2_TYPE }, // 376
    {PAU2::pau2_pau4_func          , PAU2_TYPE }, // 377
    {PAU2::pau2_pau5_func          , PAU2_TYPE }, // 378
    {PAU3::pau3_func               , PAU3_TYPE }, // 379
    {PAU3::pau3_pau6_func          , PAU3_TYPE }, // 380
    {PAU3::pau3_pau7_func          , PAU3_TYPE }, // 381
    {AXON0::iohs0_func             , AXON0_TYPE}, // 382
    {AXON0::iohs0_pdl_func         , AXON0_TYPE}, // 383
    {AXON0::iohs0_pll_bndy_bucket_8, AXON0_TYPE}, // 384
    {AXON0::iohs0_pll_bndy_bucket_9, AXON0_TYPE}, // 385
    {AXON0::iohs0_pll_bndy_bucket_10, AXON0_TYPE}, // 386
    {AXON0::iohs0_pll_bndy_bucket_11, AXON0_TYPE}, // 387
    {AXON0::iohs0_pll_bndy_bucket_12, AXON0_TYPE}, // 388
    {AXON0::iohs0_pll_bndy_bucket_13, AXON0_TYPE}, // 389
    {AXON0::iohs0_pll_bndy_bucket_14, AXON0_TYPE}, // 390
    {AXON0::iohs0_pll_bndy_bucket_15, AXON0_TYPE}, // 391
    {AXON1::iohs1_func             , AXON1_TYPE}, // 392
    {AXON1::iohs1_pdl_func         , AXON1_TYPE}, // 393
    {AXON2::iohs2_func             , AXON2_TYPE}, // 394
    {AXON2::iohs2_pdl_func         , AXON2_TYPE}, // 395
    {AXON3::iohs3_func             , AXON3_TYPE}, // 396
    {AXON3::iohs3_pdl_func         , AXON3_TYPE}, // 397
    {AXON4::iohs4_func             , AXON4_TYPE}, // 398
    {AXON4::iohs4_pdl_func         , AXON4_TYPE}, // 399
    {AXON5::iohs5_func             , AXON5_TYPE}, // 400
    {AXON5::iohs5_pdl_func         , AXON5_TYPE}, // 401
    {AXON6::iohs6_func             , AXON6_TYPE}, // 402
    {AXON6::iohs6_pdl_func         , AXON6_TYPE}, // 403
    {AXON7::iohs7_func             , AXON7_TYPE}, // 404
    {AXON7::iohs7_pdl_func         , AXON7_TYPE}, // 405
    {EQ::eq_func                   , EQ_TYPE   }, // 406
    {EQ::eq_clkadj_func            , EQ_TYPE   }, // 407
    {EQ::ec_cl2_func               , EQ_TYPE   }, // 408
    {EQ::ec_mma_func               , EQ_TYPE   }, // 409
    {EQ::ec_l3_func                , EQ_TYPE   }, // 410
    {EQ::eq_inex                   , EQ_TYPE   }, // 411
};
#endif  // __PPE__

#endif  // _P10_RING_PROPERTIES_H_
