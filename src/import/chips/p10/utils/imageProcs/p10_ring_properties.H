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
    pci_ph5_fure             = 3,
    pci_ph5_gptr             = 4,
    pci_ph5_time             = 5,
    pci_pll_func             = 6,
    pci_pll_bndy             = 7,
    pci_pll_gptr             = 8,
    // Instance Rings
    pci_repr                 = (0 | INSTANCE_RING_MARK),
    pci_ph5_repr             = (1 | INSTANCE_RING_MARK),
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
    mc_fure                  = 0,
    mc_gptr                  = 1,
    mc_time                  = 2,
    mc_emo_fure              = 3,
    mc_emo_gptr              = 4,
    mc_emo_time              = 5,
    mc_pll_func              = 6,
    mc_pll_bndy              = 7,
    mc_pll_bndy_bucket_0     = 7,
    mc_pll_bndy_bucket_1     = 8,
    mc_pll_bndy_bucket_2     = 9,
    mc_pll_bndy_bucket_3     = 10,
    mc_pll_bndy_bucket_4     = 11,
    mc_pll_gptr              = 12,
    // Instance Rings
    mc_repr                  = (0 | INSTANCE_RING_MARK),
    mc_emo_repr              = (1 | INSTANCE_RING_MARK),
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

namespace AXON
{
enum RingOffset
{
    // Common Rings
    iohs_fure                = 0,
    iohs_gptr                = 1,
    iohs_time                = 2,
    iohs_ndl_fure            = 3,
    iohs_ndl_gptr            = 4,
    iohs_ndl_time            = 5,
    iohs_pdl_fure            = 6,
    iohs_pdl_gptr            = 7,
    iohs_pdl_time            = 8,
    iohs_pll_func            = 9,
    iohs_pll_bndy            = 10,
    iohs_pll_bndy_bucket_0   = 10,
    iohs_pll_bndy_bucket_1   = 11,
    iohs_pll_bndy_bucket_2   = 12,
    iohs_pll_bndy_bucket_3   = 13,
    iohs_pll_bndy_bucket_4   = 14,
    iohs_pll_gptr            = 15,
    // Instance Rings
    iohs_repr                = (0 | INSTANCE_RING_MARK),
    iohs_ndl_repr            = (1 | INSTANCE_RING_MARK),
    iohs_pdl_repr            = (2 | INSTANCE_RING_MARK),
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
    eq_fure                  = 0,
    eq_gptr                  = 1,
    eq_time                  = 2,
    eq_cmsk                  = 3,
    eq_inex                  = 4,
    ec_cl2_fure              = 5,
    ec_cl2_gptr              = 6,
    ec_cl2_time              = 7,
    ec_cl2_cmsk              = 8,
    ec_cl2_inex              = 9,
    ec_mma_fure              = 10,
    ec_mma_gptr              = 11,
    ec_mma_time              = 12,
    ec_mma_cmsk              = 13,
    ec_mma_inex              = 14,
    ec_l3_fure               = 15,
    ec_l3_gptr               = 16,
    ec_l3_time               = 17,
    ec_l3_cmsk               = 18,
    ec_l3_inex               = 19,
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
    20, // 20 common rings for EQ Chiplet
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
    { "pci_gptr"                , 0x08035FE2, PCI::pci_gptr               , PCI_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 28
    { "pci_repr"                , 0x08035FE6, PCI::pci_repr               , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 29
    { "pci_time"                , 0x08035FE7, PCI::pci_time               , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 30
    { "pci_ph5_fure"            , 0x0803200F, PCI::pci_ph5_fure           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 31
    { "pci_ph5_gptr"            , 0x08032002, PCI::pci_ph5_gptr           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 32
    { "pci_ph5_repr"            , 0x08032006, PCI::pci_ph5_repr           , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 33
    { "pci_ph5_time"            , 0x08032007, PCI::pci_ph5_time           , PCI_TYPE , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 34
    { "pci_pll_func"            , 0x08030018, PCI::pci_pll_func           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 35
    { "pci_pll_bndy"            , 0x08030012, PCI::pci_pll_bndy           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 36
    { "pci_pll_gptr"            , 0x0803001B, PCI::pci_pll_gptr           , PCI_TYPE , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 37
    { "mc_fure"                 , 0x0C036F0F, MC::mc_fure                 , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 38
    { "mc_gptr"                 , 0x0C034F02, MC::mc_gptr                 , MC_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 39
    { "mc_repr"                 , 0x0C034F06, MC::mc_repr                 , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 40
    { "mc_time"                 , 0x0C034F07, MC::mc_time                 , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 41
    { "mc_emo_fure"             , 0x0C03200F, MC::mc_emo_fure             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 42
    { "mc_emo_gptr"             , 0x0C032002, MC::mc_emo_gptr             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 43
    { "mc_emo_repr"             , 0x0C032006, MC::mc_emo_repr             , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 44
    { "mc_emo_time"             , 0x0C032007, MC::mc_emo_time             , MC_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 45
    { "mc_pll_func"             , 0x0C030018, MC::mc_pll_func             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 46
    { "mc_pll_bndy"             , 0x0C030012, MC::mc_pll_bndy             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 47
    { "mc_pll_bndy_bucket_0"    , 0x0C030012, MC::mc_pll_bndy_bucket_0    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 48
    { "mc_pll_bndy_bucket_1"    , 0x0C030012, MC::mc_pll_bndy_bucket_1    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 49
    { "mc_pll_bndy_bucket_2"    , 0x0C030012, MC::mc_pll_bndy_bucket_2    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 50
    { "mc_pll_bndy_bucket_3"    , 0x0C030012, MC::mc_pll_bndy_bucket_3    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 51
    { "mc_pll_bndy_bucket_4"    , 0x0C030012, MC::mc_pll_bndy_bucket_4    , MC_TYPE  , RCLS_EKB_RINGS                                        }, // 52
    { "mc_pll_gptr"             , 0x0C03001B, MC::mc_pll_gptr             , MC_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 53
    { "pau0_fure"               , 0x1003430F, PAU0::pau0_fure             , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 54
    { "pau0_gptr"               , 0x10034302, PAU0::pau0_gptr             , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 55
    { "pau0_repr"               , 0x10034306, PAU0::pau0_repr             , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 56
    { "pau0_time"               , 0x10034307, PAU0::pau0_time             , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 57
    { "pau0_pau0_fure"          , 0x1003200F, PAU0::pau0_pau0_fure        , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 58
    { "pau0_pau0_gptr"          , 0x10032002, PAU0::pau0_pau0_gptr        , PAU0_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 59
    { "pau0_pau0_repr"          , 0x10032006, PAU0::pau0_pau0_repr        , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 60
    { "pau0_pau0_time"          , 0x10032007, PAU0::pau0_pau0_time        , PAU0_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 61
    { "pau1_fure"               , 0x1103430F, PAU1::pau1_fure             , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 62
    { "pau1_gptr"               , 0x11034302, PAU1::pau1_gptr             , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 63
    { "pau1_repr"               , 0x11034306, PAU1::pau1_repr             , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 64
    { "pau1_time"               , 0x11034307, PAU1::pau1_time             , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 65
    { "pau1_pau3_fure"          , 0x1103200F, PAU1::pau1_pau3_fure        , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 66
    { "pau1_pau3_gptr"          , 0x11032002, PAU1::pau1_pau3_gptr        , PAU1_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 67
    { "pau1_pau3_repr"          , 0x11032006, PAU1::pau1_pau3_repr        , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 68
    { "pau1_pau3_time"          , 0x11032007, PAU1::pau1_pau3_time        , PAU1_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 69
    { "pau2_fure"               , 0x1203430F, PAU2::pau2_fure             , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 70
    { "pau2_gptr"               , 0x12034302, PAU2::pau2_gptr             , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 71
    { "pau2_repr"               , 0x12034306, PAU2::pau2_repr             , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 72
    { "pau2_time"               , 0x12034307, PAU2::pau2_time             , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 73
    { "pau2_pau4_fure"          , 0x1203200F, PAU2::pau2_pau4_fure        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 74
    { "pau2_pau4_gptr"          , 0x12032002, PAU2::pau2_pau4_gptr        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 75
    { "pau2_pau4_repr"          , 0x12032006, PAU2::pau2_pau4_repr        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 76
    { "pau2_pau4_time"          , 0x12032007, PAU2::pau2_pau4_time        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 77
    { "pau2_pau5_fure"          , 0x1203100F, PAU2::pau2_pau5_fure        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 78
    { "pau2_pau5_gptr"          , 0x12031002, PAU2::pau2_pau5_gptr        , PAU2_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 79
    { "pau2_pau5_repr"          , 0x12031006, PAU2::pau2_pau5_repr        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 80
    { "pau2_pau5_time"          , 0x12031007, PAU2::pau2_pau5_time        , PAU2_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 81
    { "pau3_fure"               , 0x1303430F, PAU3::pau3_fure             , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 82
    { "pau3_gptr"               , 0x13034302, PAU3::pau3_gptr             , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 83
    { "pau3_repr"               , 0x13034306, PAU3::pau3_repr             , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 84
    { "pau3_time"               , 0x13034307, PAU3::pau3_time             , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 85
    { "pau3_pau6_fure"          , 0x1303200F, PAU3::pau3_pau6_fure        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 86
    { "pau3_pau6_gptr"          , 0x13032002, PAU3::pau3_pau6_gptr        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 87
    { "pau3_pau6_repr"          , 0x13032006, PAU3::pau3_pau6_repr        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 88
    { "pau3_pau6_time"          , 0x13032007, PAU3::pau3_pau6_time        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 89
    { "pau3_pau7_fure"          , 0x1303100F, PAU3::pau3_pau7_fure        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 90
    { "pau3_pau7_gptr"          , 0x13031002, PAU3::pau3_pau7_gptr        , PAU3_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 91
    { "pau3_pau7_repr"          , 0x13031006, PAU3::pau3_pau7_repr        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 92
    { "pau3_pau7_time"          , 0x13031007, PAU3::pau3_pau7_time        , PAU3_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 93
    { "iohs_fure"               , 0x1803600F, AXON::iohs_fure             , AXON_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 94
    { "iohs_gptr"               , 0x18036002, AXON::iohs_gptr             , AXON_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 95
    { "iohs_repr"               , 0x18036006, AXON::iohs_repr             , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 96
    { "iohs_time"               , 0x18036007, AXON::iohs_time             , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 97
    { "iohs_ndl_fure"           , 0x1803040F, AXON::iohs_ndl_fure         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 98
    { "iohs_ndl_gptr"           , 0x18030402, AXON::iohs_ndl_gptr         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 99
    { "iohs_ndl_repr"           , 0x18030406, AXON::iohs_ndl_repr         , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 100
    { "iohs_ndl_time"           , 0x18030407, AXON::iohs_ndl_time         , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 101
    { "iohs_pdl_fure"           , 0x1803020F, AXON::iohs_pdl_fure         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 102
    { "iohs_pdl_gptr"           , 0x18030202, AXON::iohs_pdl_gptr         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 103
    { "iohs_pdl_repr"           , 0x18030206, AXON::iohs_pdl_repr         , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDR_NEST                        }, // 104
    { "iohs_pdl_time"           , 0x18030207, AXON::iohs_pdl_time         , AXON_TYPE, RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 105
    { "iohs_pll_func"           , 0x18030018, AXON::iohs_pll_func         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 106
    { "iohs_pll_bndy"           , 0x18030012, AXON::iohs_pll_bndy         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_RINGS                            }, // 107
    { "iohs_pll_bndy_bucket_0"  , 0x18030012, AXON::iohs_pll_bndy_bucket_0, AXON_TYPE, RCLS_EKB_RINGS                                        }, // 108
    { "iohs_pll_bndy_bucket_1"  , 0x18030012, AXON::iohs_pll_bndy_bucket_1, AXON_TYPE, RCLS_EKB_RINGS                                        }, // 109
    { "iohs_pll_bndy_bucket_2"  , 0x18030012, AXON::iohs_pll_bndy_bucket_2, AXON_TYPE, RCLS_EKB_RINGS                                        }, // 110
    { "iohs_pll_bndy_bucket_3"  , 0x18030012, AXON::iohs_pll_bndy_bucket_3, AXON_TYPE, RCLS_EKB_RINGS                                        }, // 111
    { "iohs_pll_bndy_bucket_4"  , 0x18030012, AXON::iohs_pll_bndy_bucket_4, AXON_TYPE, RCLS_EKB_RINGS                                        }, // 112
    { "iohs_pll_gptr"           , 0x1803001B, AXON::iohs_pll_gptr         , AXON_TYPE, RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 113
    { "eq_fure"                 , 0x2003403F, EQ::eq_fure                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 114
    { "eq_gptr"                 , 0x20034032, EQ::eq_gptr                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY                    }, // 115
    { "eq_repr"                 , 0x20034036, EQ::eq_repr                 , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_EQ                          }, // 116
    { "eq_time"                 , 0x20034037, EQ::eq_time                 , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME                        }, // 117
    { "eq_cmsk"                 , 0x2003403A, EQ::eq_cmsk                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 118
    { "eq_inex"                 , 0x2003403B, EQ::eq_inex                 , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS                            }, // 119
    { "ec_cl2_fure"             , 0x2003200F, EQ::ec_cl2_fure             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 120
    { "ec_cl2_gptr"             , 0x20032002, EQ::ec_cl2_gptr             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 121
    { "ec_cl2_repr"             , 0x20032006, EQ::ec_cl2_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 122
    { "ec_cl2_time"             , 0x20032007, EQ::ec_cl2_time             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 123
    { "ec_cl2_cmsk"             , 0x2003200A, EQ::ec_cl2_cmsk             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 124
    { "ec_cl2_inex"             , 0x2003200B, EQ::ec_cl2_inex             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 125
    { "ec1_cl2_repr"            , 0x20031006, EQ::ec1_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 126
    { "ec2_cl2_repr"            , 0x20030806, EQ::ec2_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 127
    { "ec3_cl2_repr"            , 0x20030406, EQ::ec3_cl2_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 128
    { "ec_mma_fure"             , 0x2083000F, EQ::ec_mma_fure             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 129
    { "ec_mma_gptr"             , 0x20830002, EQ::ec_mma_gptr             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 130
    { "ec_mma_repr"             , 0x20830006, EQ::ec_mma_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 131
    { "ec_mma_time"             , 0x20830007, EQ::ec_mma_time             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 132
    { "ec_mma_cmsk"             , 0x2083000A, EQ::ec_mma_cmsk             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 133
    { "ec_mma_inex"             , 0x2083000B, EQ::ec_mma_inex             , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 134
    { "ec1_mma_repr"            , 0x20430006, EQ::ec1_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 135
    { "ec2_mma_repr"            , 0x20230006, EQ::ec2_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 136
    { "ec3_mma_repr"            , 0x20130006, EQ::ec3_mma_repr            , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 137
    { "ec_l3_fure"              , 0x2003020F, EQ::ec_l3_fure              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 138
    { "ec_l3_gptr"              , 0x20030202, EQ::ec_l3_gptr              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_MVPD_PDG_OVLY | RMRK_SCAN_BY_QME }, // 139
    { "ec_l3_repr"              , 0x20030206, EQ::ec_l3_repr              , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 140
    { "ec_l3_time"              , 0x20030207, EQ::ec_l3_time              , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDG_TIME | RMRK_SCAN_BY_QME     }, // 141
    { "ec_l3_cmsk"              , 0x2003020A, EQ::ec_l3_cmsk              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 142
    { "ec_l3_inex"              , 0x2003020B, EQ::ec_l3_inex              , EQ_TYPE  , RMRK_ROOT | RCLS_EKB_RINGS | RMRK_SCAN_BY_QME         }, // 143
    { "ec1_l3_repr"             , 0x20030106, EQ::ec1_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 144
    { "ec2_l3_repr"             , 0x20030086, EQ::ec2_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 145
    { "ec3_l3_repr"             , 0x20030046, EQ::ec3_l3_repr             , EQ_TYPE  , RMRK_ROOT | RCLS_MVPD_PDR_CORE | RMRK_SCAN_BY_QME     }, // 146
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
    { EQ::ec1_cl2_repr            , EQ_TYPE   }, // 126
    { EQ::ec2_cl2_repr            , EQ_TYPE   }, // 127
    { EQ::ec3_cl2_repr            , EQ_TYPE   }, // 128
    { EQ::ec_mma_fure             , EQ_TYPE   }, // 129
    { EQ::ec_mma_gptr             , EQ_TYPE   }, // 130
    { EQ::ec_mma_repr             , EQ_TYPE   }, // 131
    { EQ::ec_mma_time             , EQ_TYPE   }, // 132
    { EQ::ec_mma_cmsk             , EQ_TYPE   }, // 133
    { EQ::ec_mma_inex             , EQ_TYPE   }, // 134
    { EQ::ec1_mma_repr            , EQ_TYPE   }, // 135
    { EQ::ec2_mma_repr            , EQ_TYPE   }, // 136
    { EQ::ec3_mma_repr            , EQ_TYPE   }, // 137
    { EQ::ec_l3_fure              , EQ_TYPE   }, // 138
    { EQ::ec_l3_gptr              , EQ_TYPE   }, // 139
    { EQ::ec_l3_repr              , EQ_TYPE   }, // 140
    { EQ::ec_l3_time              , EQ_TYPE   }, // 141
    { EQ::ec_l3_cmsk              , EQ_TYPE   }, // 142
    { EQ::ec_l3_inex              , EQ_TYPE   }, // 143
    { EQ::ec1_l3_repr             , EQ_TYPE   }, // 144
    { EQ::ec2_l3_repr             , EQ_TYPE   }, // 145
    { EQ::ec3_l3_repr             , EQ_TYPE   }, // 146
};
#endif  // __PPE__

#endif  // _P10_RING_PROPERTIES_H_
