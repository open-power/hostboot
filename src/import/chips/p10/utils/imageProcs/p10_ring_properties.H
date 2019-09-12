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

#ifndef __RING_PROPERTIES_H__
#define __RING_PROPERTIES_H__

namespace PERV
{
enum RingOffset
{
    // Common Rings
    perv_fure        = 0,
    perv_occ_gptr    = 1,
    perv_occ_time    = 2,
    sbe_fure         = 3,
    sbe_gptr         = 4,
    sbe_time         = 5,
    occ_fure         = 6,
    perv_dpll_func   = 7,
    perv_dpll_bndy   = 8,
    perv_dpll_gptr   = 9,
    perv_pll_func    = 10,
    perv_pll_bndy    = 11,
    perv_pll_gptr    = 12,
    // Instance Rings
    perv_occ_repr    = (0 | INSTANCE_RING_MARK),
    sbe_repr         = (1 | INSTANCE_RING_MARK),
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
    n0_fure          = 0,
    n0_gptr          = 1,
    n0_time          = 2,
    // Instance Rings
    n0_repr          = (0 | INSTANCE_RING_MARK),
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
    n1_fure          = 0,
    n1_gptr          = 1,
    n1_time          = 2,
    n1_nmmu1_fure    = 3,
    n1_nmmu1_gptr    = 4,
    n1_nmmu1_time    = 5,
    // Instance Rings
    n1_repr          = (0 | INSTANCE_RING_MARK),
    n1_nmmu1_repr    = (1 | INSTANCE_RING_MARK),
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
    pci_fure         = 0,
    pci_gptr         = 1,
    pci_time         = 2,
    pci_ph5_fure     = 3,
    pci_ph5_gptr     = 4,
    pci_ph5_time     = 5,
    pci_pll_func     = 6,
    pci_pll_bndy     = 7,
    pci_pll_gptr     = 8,
    // Instance Rings
    pci_repr         = (0 | INSTANCE_RING_MARK),
    pci_ph5_repr     = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x08, // Base chiplet/instance ID.
    2,  // Number of chiplet instances
    9,  // 9 common rings for PCI Chiplet
    2,  // 2 instance specific rings for PCI Chiplet
};
}; // end of namespace PCI

namespace MC
{
enum RingOffset
{
    // Common Rings
    mc_fure          = 0,
    mc_gptr          = 1,
    mc_time          = 2,
    mc_emo_fure      = 3,
    mc_emo_gptr      = 4,
    mc_emo_time      = 5,
    mc_pll_func      = 6,
    mc_pll_bndy      = 7,
    mc_pll_bndy_bucket_0 = 7,
    mc_pll_bndy_bucket_1 = 8,
    mc_pll_bndy_bucket_2 = 9,
    mc_pll_bndy_bucket_3 = 10,
    mc_pll_bndy_bucket_4 = 11,
    mc_pll_gptr      = 12,
    // Instance Rings
    mc_repr          = (0 | INSTANCE_RING_MARK),
    mc_emo_repr      = (1 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x0C, // Base chiplet/instance ID.
    4,  // Number of chiplet instances
    13, // 13 common rings for MC Chiplet
    2,  // 2 instance specific rings for MC Chiplet
};
}; // end of namespace MC

namespace PAU0
{
enum RingOffset
{
    // Common Rings
    pau0_fure        = 0,
    pau0_gptr        = 1,
    pau0_time        = 2,
    pau0_pau0_fure   = 3,
    pau0_pau0_gptr   = 4,
    pau0_pau0_time   = 5,
    // Instance Rings
    pau0_repr        = (0 | INSTANCE_RING_MARK),
    pau0_pau0_repr   = (1 | INSTANCE_RING_MARK),
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
    pau1_fure        = 0,
    pau1_gptr        = 1,
    pau1_time        = 2,
    pau1_pau3_fure   = 3,
    pau1_pau3_gptr   = 4,
    pau1_pau3_time   = 5,
    // Instance Rings
    pau1_repr        = (0 | INSTANCE_RING_MARK),
    pau1_pau3_repr   = (1 | INSTANCE_RING_MARK),
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
    pau2_fure        = 0,
    pau2_gptr        = 1,
    pau2_time        = 2,
    pau2_pau4_fure   = 3,
    pau2_pau4_gptr   = 4,
    pau2_pau4_time   = 5,
    pau2_pau5_fure   = 6,
    pau2_pau5_gptr   = 7,
    pau2_pau5_time   = 8,
    // Instance Rings
    pau2_repr        = (0 | INSTANCE_RING_MARK),
    pau2_pau4_repr   = (1 | INSTANCE_RING_MARK),
    pau2_pau5_repr   = (2 | INSTANCE_RING_MARK),
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
    pau3_fure        = 0,
    pau3_gptr        = 1,
    pau3_time        = 2,
    pau3_pau6_fure   = 3,
    pau3_pau6_gptr   = 4,
    pau3_pau6_time   = 5,
    pau3_pau7_fure   = 6,
    pau3_pau7_gptr   = 7,
    pau3_pau7_time   = 8,
    // Instance Rings
    pau3_repr        = (0 | INSTANCE_RING_MARK),
    pau3_pau6_repr   = (1 | INSTANCE_RING_MARK),
    pau3_pau7_repr   = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x13, // Base chiplet/instance ID.
    1,  // Number of chiplet instances
    9,  // 9 common rings for PAU3 Chiplet
    3,  // 3 instance specific rings for PAU3 Chiplet
};
}; // end of namespace PAU3

namespace AXON
{
enum RingOffset
{
    // Common Rings
    iohs_fure        = 0,
    iohs_gptr        = 1,
    iohs_time        = 2,
    iohs_ndl_fure    = 3,
    iohs_ndl_gptr    = 4,
    iohs_ndl_time    = 5,
    iohs_pdl_fure    = 6,
    iohs_pdl_gptr    = 7,
    iohs_pdl_time    = 8,
    iohs_pll_func    = 9,
    iohs_pll_bndy    = 10,
    iohs_pll_bndy_bucket_0 = 10,
    iohs_pll_bndy_bucket_1 = 11,
    iohs_pll_bndy_bucket_2 = 12,
    iohs_pll_bndy_bucket_3 = 13,
    iohs_pll_bndy_bucket_4 = 14,
    iohs_pll_gptr    = 15,
    // Instance Rings
    iohs_repr        = (0 | INSTANCE_RING_MARK),
    iohs_ndl_repr    = (1 | INSTANCE_RING_MARK),
    iohs_pdl_repr    = (2 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x18, // Base chiplet/instance ID.
    8,  // Number of chiplet instances
    16, // 16 common rings for AXON Chiplet
    3,  // 3 instance specific rings for AXON Chiplet
};
}; // end of namespace AXON

namespace EQ
{
enum RingOffset
{
    // Common Rings
    eq_fure          = 0,
    eq_gptr          = 1,
    eq_time          = 2,
    eq_cmsk          = 3,
    eq_inex          = 4,
    ec_cl2_fure      = 5,
    ec_cl2_gptr      = 6,
    ec_cl2_time      = 7,
    ec_cl2_cmsk      = 8,
    ec_cl2_inex      = 9,
    ec_mma_fure      = 10,
    ec_mma_gptr      = 11,
    ec_mma_time      = 12,
    ec_mma_cmsk      = 13,
    ec_mma_inex      = 14,
    ec_l3_fure       = 15,
    ec_l3_gptr       = 16,
    ec_l3_time       = 17,
    ec_l3_cmsk       = 18,
    ec_l3_inex       = 19,
    // Instance Rings
    eq_repr          = (0 | INSTANCE_RING_MARK),
    ec_cl2_repr      = (1 | INSTANCE_RING_MARK),
    ec_mma_repr      = (2 | INSTANCE_RING_MARK),
    ec_l3_repr       = (3 | INSTANCE_RING_MARK),
};

static const ChipletData_t g_chipletData =
{
    0x20, // Base chiplet/instance ID.
    8,  // Number of chiplet instances
    20, // 20 common rings for EQ Chiplet
    4,  // 4 instance specific rings for EQ Chiplet
};
}; // end of namespace EQ

#ifndef __PPE__
static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { "perv_fure"               , 0x0103400F, PERV::perv_fure             , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 0
    { "perv_occ_gptr"           , 0x01034802, PERV::perv_occ_gptr         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 1
    { "perv_occ_repr"           , 0x01034806, PERV::perv_occ_repr         , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 2
    { "perv_occ_time"           , 0x01034807, PERV::perv_occ_time         , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 3
    { "sbe_fure"                , 0x0103200F, PERV::sbe_fure              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 4
    { "sbe_gptr"                , 0x01032002, PERV::sbe_gptr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 5
    { "sbe_repr"                , 0x01032006, PERV::sbe_repr              , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 6
    { "sbe_time"                , 0x01032007, PERV::sbe_time              , PERV_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 7
    { "occ_fure"                , 0x0103080F, PERV::occ_fure              , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 8
    { "perv_dpll_func"          , 0x01030060, PERV::perv_dpll_func        , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 9
    { "perv_dpll_bndy"          , 0x01030068, PERV::perv_dpll_bndy        , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 10
    { "perv_dpll_gptr"          , 0x01030062, PERV::perv_dpll_gptr        , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 11
    { "perv_pll_func"           , 0x01030010, PERV::perv_pll_func         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 12
    { "perv_pll_bndy"           , 0x01030018, PERV::perv_pll_bndy         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 13
    { "perv_pll_gptr"           , 0x01030012, PERV::perv_pll_gptr         , PERV_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 14
    { "n0_fure"                 , 0x0203640F, N0::n0_fure                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 15
    { "n0_gptr"                 , 0x02036402, N0::n0_gptr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 16
    { "n0_repr"                 , 0x02036406, N0::n0_repr                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 17
    { "n0_time"                 , 0x02036407, N0::n0_time                 , N0_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 18
    { "n1_fure"                 , 0x0303550F, N1::n1_fure                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 19
    { "n1_gptr"                 , 0x03035502, N1::n1_gptr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 20
    { "n1_repr"                 , 0x03035506, N1::n1_repr                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 21
    { "n1_time"                 , 0x03035507, N1::n1_time                 , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 22
    { "n1_nmmu1_fure"           , 0x0303020F, N1::n1_nmmu1_fure           , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 23
    { "n1_nmmu1_gptr"           , 0x03030202, N1::n1_nmmu1_gptr           , N1_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 24
    { "n1_nmmu1_repr"           , 0x03030206, N1::n1_nmmu1_repr           , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 25
    { "n1_nmmu1_time"           , 0x03030207, N1::n1_nmmu1_time           , N1_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 26
    { "pci_fure"                , 0x08F37F8F, PCI::pci_fure               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 27
    { "pci_gptr"                , 0x08035FE2, PCI::pci_gptr               , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 28
    { "pci_repr"                , 0x08035FE6, PCI::pci_repr               , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 29
    { "pci_time"                , 0x08035FE7, PCI::pci_time               , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 30
    { "pci_ph5_fure"            , 0x0803200F, PCI::pci_ph5_fure           , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 31
    { "pci_ph5_gptr"            , 0x08032002, PCI::pci_ph5_gptr           , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 32
    { "pci_ph5_repr"            , 0x08032006, PCI::pci_ph5_repr           , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 33
    { "pci_ph5_time"            , 0x08032007, PCI::pci_ph5_time           , PCI_TYPE , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 34
    { "pci_pll_func"            , 0x08030018, PCI::pci_pll_func           , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 35
    { "pci_pll_bndy"            , 0x08030012, PCI::pci_pll_bndy           , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 36
    { "pci_pll_gptr"            , 0x0803001B, PCI::pci_pll_gptr           , PCI_TYPE , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 37
    { "mc_fure"                 , 0x0C036F0F, MC::mc_fure                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 38
    { "mc_gptr"                 , 0x0C034F02, MC::mc_gptr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 39
    { "mc_repr"                 , 0x0C034F06, MC::mc_repr                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 40
    { "mc_time"                 , 0x0C034F07, MC::mc_time                 , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 41
    { "mc_emo_fure"             , 0x0C03200F, MC::mc_emo_fure             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 42
    { "mc_emo_gptr"             , 0x0C032002, MC::mc_emo_gptr             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 43
    { "mc_emo_repr"             , 0x0C032006, MC::mc_emo_repr             , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 44
    { "mc_emo_time"             , 0x0C032007, MC::mc_emo_time             , MC_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 45
    { "mc_pll_func"             , 0x0C030018, MC::mc_pll_func             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 46
    { "mc_pll_bndy"             , 0x0C030012, MC::mc_pll_bndy             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 47
    { "mc_pll_bndy_bucket_0"    , 0x0C030012, MC::mc_pll_bndy_bucket_0    , MC_TYPE  , RCLS_EKB_FLUSH_RING                  }, // 48
    { "mc_pll_bndy_bucket_1"    , 0x0C030012, MC::mc_pll_bndy_bucket_1    , MC_TYPE  , RCLS_EKB_FLUSH_RING                  }, // 49
    { "mc_pll_bndy_bucket_2"    , 0x0C030012, MC::mc_pll_bndy_bucket_2    , MC_TYPE  , RCLS_EKB_FLUSH_RING                  }, // 50
    { "mc_pll_bndy_bucket_3"    , 0x0C030012, MC::mc_pll_bndy_bucket_3    , MC_TYPE  , RCLS_EKB_FLUSH_RING                  }, // 51
    { "mc_pll_bndy_bucket_4"    , 0x0C030012, MC::mc_pll_bndy_bucket_4    , MC_TYPE  , RCLS_EKB_FLUSH_RING                  }, // 52
    { "mc_pll_gptr"             , 0x0C03001B, MC::mc_pll_gptr             , MC_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 53
    { "pau0_fure"               , 0x1003430F, PAU0::pau0_fure             , PAU0_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 54
    { "pau0_gptr"               , 0x10034302, PAU0::pau0_gptr             , PAU0_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 55
    { "pau0_repr"               , 0x10034306, PAU0::pau0_repr             , PAU0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 56
    { "pau0_time"               , 0x10034307, PAU0::pau0_time             , PAU0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 57
    { "pau0_pau0_fure"          , 0x1003200F, PAU0::pau0_pau0_fure        , PAU0_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 58
    { "pau0_pau0_gptr"          , 0x10032002, PAU0::pau0_pau0_gptr        , PAU0_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 59
    { "pau0_pau0_repr"          , 0x10032006, PAU0::pau0_pau0_repr        , PAU0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 60
    { "pau0_pau0_time"          , 0x10032007, PAU0::pau0_pau0_time        , PAU0_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 61
    { "pau1_fure"               , 0x1103430F, PAU1::pau1_fure             , PAU1_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 62
    { "pau1_gptr"               , 0x11034302, PAU1::pau1_gptr             , PAU1_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 63
    { "pau1_repr"               , 0x11034306, PAU1::pau1_repr             , PAU1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 64
    { "pau1_time"               , 0x11034307, PAU1::pau1_time             , PAU1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 65
    { "pau1_pau3_fure"          , 0x1103200F, PAU1::pau1_pau3_fure        , PAU1_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 66
    { "pau1_pau3_gptr"          , 0x11032002, PAU1::pau1_pau3_gptr        , PAU1_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 67
    { "pau1_pau3_repr"          , 0x11032006, PAU1::pau1_pau3_repr        , PAU1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 68
    { "pau1_pau3_time"          , 0x11032007, PAU1::pau1_pau3_time        , PAU1_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 69
    { "pau2_fure"               , 0x1203430F, PAU2::pau2_fure             , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 70
    { "pau2_gptr"               , 0x12034302, PAU2::pau2_gptr             , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 71
    { "pau2_repr"               , 0x12034306, PAU2::pau2_repr             , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 72
    { "pau2_time"               , 0x12034307, PAU2::pau2_time             , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 73
    { "pau2_pau4_fure"          , 0x1203200F, PAU2::pau2_pau4_fure        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 74
    { "pau2_pau4_gptr"          , 0x12032002, PAU2::pau2_pau4_gptr        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 75
    { "pau2_pau4_repr"          , 0x12032006, PAU2::pau2_pau4_repr        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 76
    { "pau2_pau4_time"          , 0x12032007, PAU2::pau2_pau4_time        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 77
    { "pau2_pau5_fure"          , 0x1203100F, PAU2::pau2_pau5_fure        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 78
    { "pau2_pau5_gptr"          , 0x12031002, PAU2::pau2_pau5_gptr        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 79
    { "pau2_pau5_repr"          , 0x12031006, PAU2::pau2_pau5_repr        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 80
    { "pau2_pau5_time"          , 0x12031007, PAU2::pau2_pau5_time        , PAU2_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 81
    { "pau3_fure"               , 0x1303430F, PAU3::pau3_fure             , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 82
    { "pau3_gptr"               , 0x13034302, PAU3::pau3_gptr             , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 83
    { "pau3_repr"               , 0x13034306, PAU3::pau3_repr             , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 84
    { "pau3_time"               , 0x13034307, PAU3::pau3_time             , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 85
    { "pau3_pau6_fure"          , 0x1303200F, PAU3::pau3_pau6_fure        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 86
    { "pau3_pau6_gptr"          , 0x13032002, PAU3::pau3_pau6_gptr        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 87
    { "pau3_pau6_repr"          , 0x13032006, PAU3::pau3_pau6_repr        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 88
    { "pau3_pau6_time"          , 0x13032007, PAU3::pau3_pau6_time        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 89
    { "pau3_pau7_fure"          , 0x1303100F, PAU3::pau3_pau7_fure        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 90
    { "pau3_pau7_gptr"          , 0x13031002, PAU3::pau3_pau7_gptr        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 91
    { "pau3_pau7_repr"          , 0x13031006, PAU3::pau3_pau7_repr        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 92
    { "pau3_pau7_time"          , 0x13031007, PAU3::pau3_pau7_time        , PAU3_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 93
    { "iohs_fure"               , 0x1803600F, AXON::iohs_fure             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 94
    { "iohs_gptr"               , 0x18036002, AXON::iohs_gptr             , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 95
    { "iohs_repr"               , 0x18036006, AXON::iohs_repr             , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 96
    { "iohs_time"               , 0x18036007, AXON::iohs_time             , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 97
    { "iohs_ndl_fure"           , 0x1803040F, AXON::iohs_ndl_fure         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 98
    { "iohs_ndl_gptr"           , 0x18030402, AXON::iohs_ndl_gptr         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 99
    { "iohs_ndl_repr"           , 0x18030406, AXON::iohs_ndl_repr         , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 100
    { "iohs_ndl_time"           , 0x18030407, AXON::iohs_ndl_time         , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 101
    { "iohs_pdl_fure"           , 0x1803020F, AXON::iohs_pdl_fure         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 102
    { "iohs_pdl_gptr"           , 0x18030202, AXON::iohs_pdl_gptr         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 103
    { "iohs_pdl_repr"           , 0x18030206, AXON::iohs_pdl_repr         , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 104
    { "iohs_pdl_time"           , 0x18030207, AXON::iohs_pdl_time         , AXON_TYPE, RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 105
    { "iohs_pll_func"           , 0x18030018, AXON::iohs_pll_func         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 106
    { "iohs_pll_bndy"           , 0x18030012, AXON::iohs_pll_bndy         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 107
    { "iohs_pll_bndy_bucket_0"  , 0x18030012, AXON::iohs_pll_bndy_bucket_0, AXON_TYPE, RCLS_EKB_FLUSH_RING                  }, // 108
    { "iohs_pll_bndy_bucket_1"  , 0x18030012, AXON::iohs_pll_bndy_bucket_1, AXON_TYPE, RCLS_EKB_FLUSH_RING                  }, // 109
    { "iohs_pll_bndy_bucket_2"  , 0x18030012, AXON::iohs_pll_bndy_bucket_2, AXON_TYPE, RCLS_EKB_FLUSH_RING                  }, // 110
    { "iohs_pll_bndy_bucket_3"  , 0x18030012, AXON::iohs_pll_bndy_bucket_3, AXON_TYPE, RCLS_EKB_FLUSH_RING                  }, // 111
    { "iohs_pll_bndy_bucket_4"  , 0x18030012, AXON::iohs_pll_bndy_bucket_4, AXON_TYPE, RCLS_EKB_FLUSH_RING                  }, // 112
    { "iohs_pll_gptr"           , 0x1803001B, AXON::iohs_pll_gptr         , AXON_TYPE, RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 113
    { "eq_fure"                 , 0x2003403F, EQ::eq_fure                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 114
    { "eq_gptr"                 , 0x20034032, EQ::eq_gptr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 115
    { "eq_repr"                 , 0x20034036, EQ::eq_repr                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 116
    { "eq_time"                 , 0x20034037, EQ::eq_time                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 117
    { "eq_cmsk"                 , 0x2003403A, EQ::eq_cmsk                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 118
    { "eq_inex"                 , 0x2003403B, EQ::eq_inex                 , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 119
    { "ec_cl2_fure"             , 0x2003200F, EQ::ec_cl2_fure             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 120
    { "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 121
    { "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 122
    { "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 123
    { "ec_cl2_cmsk"             , 0x2003200A, EQ::ec_cl2_cmsk             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 124
    { "ec_cl2_inex"             , 0x2003200B, EQ::ec_cl2_inex             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 125
    { "ec_mma_fure"             , 0x2083000F, EQ::ec_mma_fure             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 126
    { "ec_mma_gptr"             , 0x20830002, EQ::ec_mma_gptr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 127
    { "ec_mma_repr"             , 0x20830006, EQ::ec_mma_repr             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 128
    { "ec_mma_time"             , 0x20830007, EQ::ec_mma_time             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 129
    { "ec_mma_cmsk"             , 0x2083000A, EQ::ec_mma_cmsk             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 130
    { "ec_mma_inex"             , 0x2083000B, EQ::ec_mma_inex             , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 131
    { "ec_l3_fure"              , 0x2003020F, EQ::ec_l3_fure              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 132
    { "ec_l3_gptr"              , 0x20030202, EQ::ec_l3_gptr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_OVLY_RING  }, // 133
    { "ec_l3_repr"              , 0x20030206, EQ::ec_l3_repr              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDR_RING  }, // 134
    { "ec_l3_time"              , 0x20030207, EQ::ec_l3_time              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_MVPD_PDG_RING  }, // 135
    { "ec_l3_cmsk"              , 0x2003020A, EQ::ec_l3_cmsk              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 136
    { "ec_l3_inex"              , 0x2003020B, EQ::ec_l3_inex              , EQ_TYPE  , RCLS_ROOT_RING | RCLS_EKB_FLUSH_RING }, // 137
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
    { PCI::pci_ph5_fure           , PCI_TYPE  }, // 31
    { PCI::pci_ph5_gptr           , PCI_TYPE  }, // 32
    { PCI::pci_ph5_repr           , PCI_TYPE  }, // 33
    { PCI::pci_ph5_time           , PCI_TYPE  }, // 34
    { PCI::pci_pll_func           , PCI_TYPE  }, // 35
    { PCI::pci_pll_bndy           , PCI_TYPE  }, // 36
    { PCI::pci_pll_gptr           , PCI_TYPE  }, // 37
    { MC::mc_fure                 , MC_TYPE   }, // 38
    { MC::mc_gptr                 , MC_TYPE   }, // 39
    { MC::mc_repr                 , MC_TYPE   }, // 40
    { MC::mc_time                 , MC_TYPE   }, // 41
    { MC::mc_emo_fure             , MC_TYPE   }, // 42
    { MC::mc_emo_gptr             , MC_TYPE   }, // 43
    { MC::mc_emo_repr             , MC_TYPE   }, // 44
    { MC::mc_emo_time             , MC_TYPE   }, // 45
    { MC::mc_pll_func             , MC_TYPE   }, // 46
    { MC::mc_pll_bndy             , MC_TYPE   }, // 47
    { MC::mc_pll_bndy_bucket_0    , MC_TYPE   }, // 48
    { MC::mc_pll_bndy_bucket_1    , MC_TYPE   }, // 49
    { MC::mc_pll_bndy_bucket_2    , MC_TYPE   }, // 50
    { MC::mc_pll_bndy_bucket_3    , MC_TYPE   }, // 51
    { MC::mc_pll_bndy_bucket_4    , MC_TYPE   }, // 52
    { MC::mc_pll_gptr             , MC_TYPE   }, // 53
    { PAU0::pau0_fure             , PAU0_TYPE }, // 54
    { PAU0::pau0_gptr             , PAU0_TYPE }, // 55
    { PAU0::pau0_repr             , PAU0_TYPE }, // 56
    { PAU0::pau0_time             , PAU0_TYPE }, // 57
    { PAU0::pau0_pau0_fure        , PAU0_TYPE }, // 58
    { PAU0::pau0_pau0_gptr        , PAU0_TYPE }, // 59
    { PAU0::pau0_pau0_repr        , PAU0_TYPE }, // 60
    { PAU0::pau0_pau0_time        , PAU0_TYPE }, // 61
    { PAU1::pau1_fure             , PAU1_TYPE }, // 62
    { PAU1::pau1_gptr             , PAU1_TYPE }, // 63
    { PAU1::pau1_repr             , PAU1_TYPE }, // 64
    { PAU1::pau1_time             , PAU1_TYPE }, // 65
    { PAU1::pau1_pau3_fure        , PAU1_TYPE }, // 66
    { PAU1::pau1_pau3_gptr        , PAU1_TYPE }, // 67
    { PAU1::pau1_pau3_repr        , PAU1_TYPE }, // 68
    { PAU1::pau1_pau3_time        , PAU1_TYPE }, // 69
    { PAU2::pau2_fure             , PAU2_TYPE }, // 70
    { PAU2::pau2_gptr             , PAU2_TYPE }, // 71
    { PAU2::pau2_repr             , PAU2_TYPE }, // 72
    { PAU2::pau2_time             , PAU2_TYPE }, // 73
    { PAU2::pau2_pau4_fure        , PAU2_TYPE }, // 74
    { PAU2::pau2_pau4_gptr        , PAU2_TYPE }, // 75
    { PAU2::pau2_pau4_repr        , PAU2_TYPE }, // 76
    { PAU2::pau2_pau4_time        , PAU2_TYPE }, // 77
    { PAU2::pau2_pau5_fure        , PAU2_TYPE }, // 78
    { PAU2::pau2_pau5_gptr        , PAU2_TYPE }, // 79
    { PAU2::pau2_pau5_repr        , PAU2_TYPE }, // 80
    { PAU2::pau2_pau5_time        , PAU2_TYPE }, // 81
    { PAU3::pau3_fure             , PAU3_TYPE }, // 82
    { PAU3::pau3_gptr             , PAU3_TYPE }, // 83
    { PAU3::pau3_repr             , PAU3_TYPE }, // 84
    { PAU3::pau3_time             , PAU3_TYPE }, // 85
    { PAU3::pau3_pau6_fure        , PAU3_TYPE }, // 86
    { PAU3::pau3_pau6_gptr        , PAU3_TYPE }, // 87
    { PAU3::pau3_pau6_repr        , PAU3_TYPE }, // 88
    { PAU3::pau3_pau6_time        , PAU3_TYPE }, // 89
    { PAU3::pau3_pau7_fure        , PAU3_TYPE }, // 90
    { PAU3::pau3_pau7_gptr        , PAU3_TYPE }, // 91
    { PAU3::pau3_pau7_repr        , PAU3_TYPE }, // 92
    { PAU3::pau3_pau7_time        , PAU3_TYPE }, // 93
    { AXON::iohs_fure             , AXON_TYPE }, // 94
    { AXON::iohs_gptr             , AXON_TYPE }, // 95
    { AXON::iohs_repr             , AXON_TYPE }, // 96
    { AXON::iohs_time             , AXON_TYPE }, // 97
    { AXON::iohs_ndl_fure         , AXON_TYPE }, // 98
    { AXON::iohs_ndl_gptr         , AXON_TYPE }, // 99
    { AXON::iohs_ndl_repr         , AXON_TYPE }, // 100
    { AXON::iohs_ndl_time         , AXON_TYPE }, // 101
    { AXON::iohs_pdl_fure         , AXON_TYPE }, // 102
    { AXON::iohs_pdl_gptr         , AXON_TYPE }, // 103
    { AXON::iohs_pdl_repr         , AXON_TYPE }, // 104
    { AXON::iohs_pdl_time         , AXON_TYPE }, // 105
    { AXON::iohs_pll_func         , AXON_TYPE }, // 106
    { AXON::iohs_pll_bndy         , AXON_TYPE }, // 107
    { AXON::iohs_pll_bndy_bucket_0, AXON_TYPE }, // 108
    { AXON::iohs_pll_bndy_bucket_1, AXON_TYPE }, // 109
    { AXON::iohs_pll_bndy_bucket_2, AXON_TYPE }, // 110
    { AXON::iohs_pll_bndy_bucket_3, AXON_TYPE }, // 111
    { AXON::iohs_pll_bndy_bucket_4, AXON_TYPE }, // 112
    { AXON::iohs_pll_gptr         , AXON_TYPE }, // 113
    { EQ::eq_fure                 , EQ_TYPE   }, // 114
    { EQ::eq_gptr                 , EQ_TYPE   }, // 115
    { EQ::eq_repr                 , EQ_TYPE   }, // 116
    { EQ::eq_time                 , EQ_TYPE   }, // 117
    { EQ::eq_cmsk                 , EQ_TYPE   }, // 118
    { EQ::eq_inex                 , EQ_TYPE   }, // 119
    { EQ::ec_cl2_fure             , EQ_TYPE   }, // 120
    { EQ::ec_cl2_gptr             , EQ_TYPE   }, // 121
    { EQ::ec_cl2_repr             , EQ_TYPE   }, // 122
    { EQ::ec_cl2_time             , EQ_TYPE   }, // 123
    { EQ::ec_cl2_cmsk             , EQ_TYPE   }, // 124
    { EQ::ec_cl2_inex             , EQ_TYPE   }, // 125
    { EQ::ec_mma_fure             , EQ_TYPE   }, // 126
    { EQ::ec_mma_gptr             , EQ_TYPE   }, // 127
    { EQ::ec_mma_repr             , EQ_TYPE   }, // 128
    { EQ::ec_mma_time             , EQ_TYPE   }, // 129
    { EQ::ec_mma_cmsk             , EQ_TYPE   }, // 130
    { EQ::ec_mma_inex             , EQ_TYPE   }, // 131
    { EQ::ec_l3_fure              , EQ_TYPE   }, // 132
    { EQ::ec_l3_gptr              , EQ_TYPE   }, // 133
    { EQ::ec_l3_repr              , EQ_TYPE   }, // 134
    { EQ::ec_l3_time              , EQ_TYPE   }, // 135
    { EQ::ec_l3_cmsk              , EQ_TYPE   }, // 136
    { EQ::ec_l3_inex              , EQ_TYPE   }, // 137
};
#endif  //__PPE__
#endif // __RING_PROPERTIES_H__
