/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ringId.H $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#else
    #include <stdint.h>
    #include <stddef.h>
    #include <p9_ring_id.h>
#endif

enum RingClass
{
    EKB_RING,
    EKB_FSM_RING,
    VPD_RING,
    NUM_RING_CLASSES
};

// General Ring ID list structure
typedef struct
{
    const char*  ringName;
    uint8_t      ringId;
    uint8_t      instanceIdMin;
    uint8_t      instanceIdMax;
    RingClass    ringClass;
    uint32_t     scanScomAddress;
} GenRingIdList;

typedef enum RingVariant   // Base variables
{
    BASE     = 0x00,
    CC       = 0x01,
    RL       = 0x02,
    OVERRIDE = 0x03,
    OVERLAY  = 0x04,
    NUM_RING_VARIANTS = 0x05,
    NOT_VALID = 0xff
} RingVariant_t;

typedef struct
{
    uint8_t  variant[3];
} RingVariantOrder;


namespace PERV
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace N3
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace XB
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace MC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace OB3
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI0
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI1
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace PCI2
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace EQ
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace EC
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const GenRingIdList RING_ID_LIST_INSTANCE[];
extern const RingVariantOrder RING_VARIANT_ORDER[];
}

namespace RING_TYPES
{
enum RINGTYPE
{
    COMMON_RING = 0,
    INSTANCE_RING = 1
};

}; //end of RS4 namespace
enum CHIPLET_TYPE
{
    PERV_TYPE,
    N0_TYPE,
    N1_TYPE,
    N2_TYPE,
    N3_TYPE,
    MC_TYPE,
    PCI0_TYPE,
    PCI1_TYPE,
    PCI2_TYPE,
    OB0_TYPE,
    OB1_TYPE,
    OB2_TYPE,
    OB3_TYPE,
    XB_TYPE,
    EQ_TYPE,
    EC_TYPE,
};

struct CHIPLET_DATA
{
    // This is the chiplet-ID of the first instance of the Chiplet
    uint8_t iv_base_chiplet_number;

    // The no.of common rings for the Chiplet
    uint8_t iv_num_common_rings;

    // The no.of instance rings for the Chiplet (w/different ringId values)
    uint8_t iv_num_instance_rings;

    // The no.of instance rings for the Chiplet (w/different ringId values
    // AND different scanAddress values)
    uint8_t iv_num_instance_rings_scan_addrs;
};

// This is used to Set (Mark) the left-most bit
const uint8_t INSTANCE_RING_MARK = 0x80;
//
// This is used to Set (Mark) the left-most bit
const uint8_t INSTANCE_RING_MASK = 0x7F;

namespace PERV
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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
    // Instance Rings
    perv_repr     = (0 | INSTANCE_RING_MARK),
    occ_repr      = (1 | INSTANCE_RING_MARK),
};

static const CHIPLET_DATA g_pervData =
{
    1,  // Pervasive Chiplet ID is 1
    15, // 15 common rings for pervasive chiplet
    2,  // 2 instance specific rings for pervasive chiplet
    2
};
}; // end of namespace PERV

namespace N0
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_n0Data =
{
    2, // N0 Chiplet ID is 2.
    9, // 9 common rings for N0 Chiplet
    3, // 3 instance specific rings for N0 chiplet
    3
};
};

namespace N1
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_n1Data =
{
    3,  // N1 Chiplet ID is 3.
    12, // 12 common rings for N1 Chiplet
    4,  // 4 instance specific rings for N1 chiplet
    4
};
};

namespace N2
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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
    n2_psi_repr  = (2 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_n2Data =
{
    4, // N2 Chiplet ID is 4.
    9, // 9 common rings for N2 Chiplet
    3, // 3 instance specific rings for N2 chiplet
    3
};
};

namespace N3
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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
    // Instance Rings
    n3_repr       = (0 | INSTANCE_RING_MARK),
    n3_mcs01_repr = (1 | INSTANCE_RING_MARK),
    n3_np_repr = (2 | INSTANCE_RING_MARK),
};

static const CHIPLET_DATA g_n3Data =
{
    5, // N3 Chiplet ID is 5
    9, // 9 common rings for N3 Chiplet
    3, // 3 instance specific rings for N3 chiplet
    3
};
};

namespace XB
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_xbData =
{
    6,  // X-Bus Chiplet ID is 6
    15, // 15 common rings for X-Bus Chiplet
    4,  // 4 instance specific rings for XB chiplet
    4
};
}; // end of namespace XB

namespace MC
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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
    // Instance Rings
    mc_repr       = (0 | INSTANCE_RING_MARK),
    mc_iom01_repr = (1 | INSTANCE_RING_MARK),
    mc_iom23_repr = (2 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_mcData =
{
    7,  // MC Chiplet ID range is 7 - 8. The base ID is 7.
    16, // 16 common rings for MC Chiplet
    3,  // 3 instance specific rings for each MC instance
    3
};
}; // end of namespace MC

namespace OB0
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    ob0_fure      = 0,
    ob0_gptr      = 1,
    ob0_time      = 2,
    ob0_pll_gptr  = 3,
    ob0_pll_bndy  = 4,
    ob0_pll_func  = 5,
    // Instance Rings
    ob0_repr      = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_ob0Data =
{
    9,  // O-Bus Chiplet ID range is 9 - 12. The base ID is 9.
    6,  // 6 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1
};
}; // end of namespace OB0

namespace OB1
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    ob1_fure      = 0,
    ob1_gptr      = 1,
    ob1_time      = 2,
    ob1_pll_gptr  = 3,
    ob1_pll_bndy  = 4,
    ob1_pll_func  = 5,
    // Instance Rings
    ob1_repr      = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_ob1Data =
{
    10, // O-Bus Chiplet ID range is 9 - 12. The base ID is 9.
    6,  // 6 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1
};
}; // end of namespace OB1


namespace OB2
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    ob2_fure      = 0,
    ob2_gptr      = 1,
    ob2_time      = 2,
    ob2_pll_gptr  = 3,
    ob2_pll_bndy  = 4,
    ob2_pll_func  = 5,
    // Instance Rings
    ob2_repr      = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_ob2Data =
{
    11, // O-Bus Chiplet ID range is 9 - 12. The base ID is 9.
    6,  // 6 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1
};
}; // end of namespace OB2

namespace OB3
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    ob3_fure      = 0,
    ob3_gptr      = 1,
    ob3_time      = 2,
    ob3_pll_gptr  = 3,
    ob3_pll_bndy  = 4,
    ob3_pll_func  = 5,
    // Instance Rings
    ob3_repr      = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_ob3Data =
{
    12, // O-Bus Chiplet ID range is 9 - 12. The base ID is 9.
    6,  // 10 common rings for OB Chiplet
    1,  // 1 instance specific rings for each OB chiplet
    1
};
}; // end of namespace OB2
namespace PCI0
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_pci0Data =
{
    13, // PCI0 Chiplet Chiplet ID is 13
    5,  // 5 common rings for PCI0 chiplet
    1,  // 1 instance specific rings for PCI0 chiplet
    1
};
};

namespace PCI1
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_pci1Data =
{
    14, // PCI1 Chiplet Chiplet ID is 14
    5,  // 5 common rings for PCI1 chiplet
    1,  // 1 instance specific rings for PCI1 chiplet
    1
};
};

namespace PCI2
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_riskLevel;
};

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

static const CHIPLET_DATA g_pci2Data =
{
    15, // PCI2 Chiplet Chiplet ID is 15
    5,  // 5 common rings for PCI2 chiplet
    1,  // 1 instance specific rings for PCI2 chiplet
    1
};

};

namespace EQ
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_cacheContained;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    eq_fure         = 0,
    eq_gptr         = 1,
    eq_time         = 2,
    eq_mode         = 3,
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
    eq_ana_bndy_l3dcc_bucket_26  = 44,
    eq_ana_mode     = 45,
    ex_l2_fure_1    = 46,
    ex_l3_fure_1    = 47,
    // Instance Rings
    eq_repr         = (0 | INSTANCE_RING_MARK),
    ex_l3_repr      = (1 | INSTANCE_RING_MARK),
    ex_l2_repr      = (2 | INSTANCE_RING_MARK),
    ex_l3_refr_repr = (3 | INSTANCE_RING_MARK),
    ex_l3_refr_time = (4 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_eqData =
{
    16, // Quad Chiplet ID range is 16 - 21. The base ID is 16.
    48, // 48 common rings for Quad chiplet.
    5,  // 5 instance specific rings for each EQ chiplet
    9   // 9 different rings since 2 per EX ring and 1 per EQ
};
}; // end of namespace EQ

namespace EC
{
struct RingVariants
{
    uint16_t iv_base;
    uint16_t iv_cacheContained;
    uint16_t iv_riskLevel;
};

enum RingOffset
{
    // Common Rings
    ec_func = 0,
    ec_gptr = 1,
    ec_time = 2,
    ec_mode = 3,
    // Instance Rings
    ec_repr = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_ecData =
{
    32, // Core Chiplet ID range is 32-55. The base ID is 32.
    4,  // 4 common rings for Core chiplet
    1,  // 1 instance specific ring for each Core chiplet
    1
};
}; // end of namespace EC

static const uint8_t INVALID_RING = 0xFF;

// This structure is needed for mapping a RingID to it's corresponding name.
// The names will be used by the build scripts when generating the TOR.
#ifndef __PPE__
struct ringProperties_t
{
    uint8_t iv_torOffSet;
    char iv_name[50];
    CHIPLET_TYPE iv_type;
};
#endif
#ifdef __PPE__
struct ringProperties_t
{
    uint8_t iv_torOffSet;
    CHIPLET_TYPE iv_type;
};
#endif

#ifndef __PPE__
static const ringProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { PERV::perv_fure                    , "perv_fure"                   , PERV_TYPE  }, // 0
    { PERV::perv_gptr                    , "perv_gptr"                   , PERV_TYPE  }, // 1
    { PERV::perv_time                    , "perv_time"                   , PERV_TYPE  }, // 2
    { PERV::occ_fure                     , "occ_fure"                    , PERV_TYPE  }, // 3
    { PERV::occ_gptr                     , "occ_gptr"                    , PERV_TYPE  }, // 4
    { PERV::occ_time                     , "occ_time"                    , PERV_TYPE  }, // 5
    { PERV::perv_ana_func                , "perv_ana_func"               , PERV_TYPE  }, // 6
    { PERV::perv_ana_gptr                , "perv_ana_gptr"               , PERV_TYPE  }, // 7
    { PERV::perv_pll_gptr                , "perv_pll_gptr"               , PERV_TYPE  }, // 8
    { PERV::perv_pll_bndy                , "perv_pll_bndy"               , PERV_TYPE  }, // 9
    { PERV::perv_pll_bndy_bucket_1       , "perv_pll_bndy_bucket_1"      , PERV_TYPE  }, // 10
    { PERV::perv_pll_bndy_bucket_2       , "perv_pll_bndy_bucket_2"      , PERV_TYPE  }, // 11
    { PERV::perv_pll_bndy_bucket_3       , "perv_pll_bndy_bucket_3"      , PERV_TYPE  }, // 12
    { PERV::perv_pll_bndy_bucket_4       , "perv_pll_bndy_bucket_4"      , PERV_TYPE  }, // 13
    { PERV::perv_pll_bndy_bucket_5       , "perv_pll_bndy_bucket_5"      , PERV_TYPE  }, // 14
    { PERV::perv_pll_func                , "perv_pll_func"               , PERV_TYPE  }, // 15
    { PERV::perv_repr                    , "perv_repr"                   , PERV_TYPE  }, // 16
    { PERV::occ_repr                     , "occ_repr"                    , PERV_TYPE  }, // 17
    { INVALID_RING                       , "invalid"                     , PERV_TYPE  }, // 18
    { INVALID_RING                       , "invalid"                     , PERV_TYPE  }, // 19
    { INVALID_RING                       , "invalid"                     , PERV_TYPE  }, // 20
    { N0::n0_fure                        , "n0_fure"                     , N0_TYPE    }, // 21
    { N0::n0_gptr                        , "n0_gptr"                     , N0_TYPE    }, // 22
    { N0::n0_time                        , "n0_time"                     , N0_TYPE    }, // 23
    { N0::n0_nx_fure                     , "n0_nx_fure"                  , N0_TYPE    }, // 24
    { N0::n0_nx_gptr                     , "n0_nx_gptr"                  , N0_TYPE    }, // 25
    { N0::n0_nx_time                     , "n0_nx_time"                  , N0_TYPE    }, // 26
    { N0::n0_cxa0_fure                   , "n0_cxa0_fure"                , N0_TYPE    }, // 27
    { N0::n0_cxa0_gptr                   , "n0_cxa0_gptr"                , N0_TYPE    }, // 28
    { N0::n0_cxa0_time                   , "n0_cxa0_time"                , N0_TYPE    }, // 29
    { N0::n0_repr                        , "n0_repr"                     , N0_TYPE    }, // 30
    { N0::n0_nx_repr                     , "n0_nx_repr"                  , N0_TYPE    }, // 31
    { N0::n0_cxa0_repr                   , "n0_cxa0_repr"                , N0_TYPE    }, // 32
    { N1::n1_fure                        , "n1_fure"                     , N1_TYPE    }, // 33
    { N1::n1_gptr                        , "n1_gptr"                     , N1_TYPE    }, // 34
    { N1::n1_time                        , "n1_time"                     , N1_TYPE    }, // 35
    { N1::n1_ioo0_fure                   , "n1_ioo0_fure"                , N1_TYPE    }, // 36
    { N1::n1_ioo0_gptr                   , "n1_ioo0_gptr"                , N1_TYPE    }, // 37
    { N1::n1_ioo0_time                   , "n1_ioo0_time"                , N1_TYPE    }, // 38
    { N1::n1_ioo1_fure                   , "n1_ioo1_fure"                , N1_TYPE    }, // 39
    { N1::n1_ioo1_gptr                   , "n1_ioo1_gptr"                , N1_TYPE    }, // 40
    { N1::n1_ioo1_time                   , "n1_ioo1_time"                , N1_TYPE    }, // 41
    { N1::n1_mcs23_fure                  , "n1_mcs23_fure"               , N1_TYPE    }, // 42
    { N1::n1_mcs23_gptr                  , "n1_mcs23_gptr"               , N1_TYPE    }, // 43
    { N1::n1_mcs23_time                  , "n1_mcs23_time"               , N1_TYPE    }, // 44
    { N1::n1_repr                        , "n1_repr"                     , N1_TYPE    }, // 45
    { N1::n1_ioo0_repr                   , "n1_ioo0_repr"                , N1_TYPE    }, // 46
    { N1::n1_ioo1_repr                   , "n1_ioo1_repr"                , N1_TYPE    }, // 47
    { N1::n1_mcs23_repr                  , "n1_mcs23_repr"               , N1_TYPE    }, // 48
    { N2::n2_fure                        , "n2_fure"                     , N2_TYPE    }, // 49
    { N2::n2_gptr                        , "n2_gptr"                     , N2_TYPE    }, // 50
    { N2::n2_time                        , "n2_time"                     , N2_TYPE    }, // 51
    { N2::n2_cxa1_fure                   , "n2_cxa1_fure"                , N2_TYPE    }, // 52
    { N2::n2_cxa1_gptr                   , "n2_cxa1_gptr"                , N2_TYPE    }, // 53
    { N2::n2_cxa1_time                   , "n2_cxa1_time"                , N2_TYPE    }, // 54
    { N2::n2_psi_fure                    , "n2_psi_fure"                 , N2_TYPE    }, // 55
    { N2::n2_psi_gptr                    , "n2_psi_gptr"                 , N2_TYPE    }, // 56
    { N2::n2_psi_time                    , "n2_psi_time"                 , N2_TYPE    }, // 57
    { N2::n2_repr                        , "n2_repr"                     , N2_TYPE    }, // 58
    { N2::n2_cxa1_repr                   , "n2_cxa1_repr"                , N2_TYPE    }, // 59
    { N2::n2_psi_repr                    , "n2_psi_repr"                 , N2_TYPE    }, // 60
    { INVALID_RING                       , "invalid"                     , N2_TYPE    }, // 61
    { N3::n3_fure                        , "n3_fure"                     , N3_TYPE    }, // 62
    { N3::n3_gptr                        , "n3_gptr"                     , N3_TYPE    }, // 63
    { N3::n3_time                        , "n3_time"                     , N3_TYPE    }, // 64
    { N3::n3_mcs01_fure                  , "n3_mcs01_fure"               , N3_TYPE    }, // 65
    { N3::n3_mcs01_gptr                  , "n3_mcs01_gptr"               , N3_TYPE    }, // 66
    { N3::n3_mcs01_time                  , "n3_mcs01_time"               , N3_TYPE    }, // 67
    { N3::n3_np_fure                     , "n3_np_fure"                  , N3_TYPE    }, // 68
    { N3::n3_np_gptr                     , "n3_np_gptr"                  , N3_TYPE    }, // 69
    { N3::n3_np_time                     , "n3_np_time"                  , N3_TYPE    }, // 70
    { N3::n3_repr                        , "n3_repr"                     , N3_TYPE    }, // 71
    { N3::n3_mcs01_repr                  , "n3_mcs01_repr"               , N3_TYPE    }, // 72
    { N3::n3_np_repr                     , "n3_np_repr"                  , N3_TYPE    }, // 73
    { INVALID_RING                       , "invalid"                     , N3_TYPE    }, // 74
    { XB::xb_fure                        , "xb_fure"                     , XB_TYPE    }, // 75
    { XB::xb_gptr                        , "xb_gptr"                     , XB_TYPE    }, // 76
    { XB::xb_time                        , "xb_time"                     , XB_TYPE    }, // 77
    { XB::xb_io0_fure                    , "xb_io0_fure"                 , XB_TYPE    }, // 78
    { XB::xb_io0_gptr                    , "xb_io0_gptr"                 , XB_TYPE    }, // 79
    { XB::xb_io0_time                    , "xb_io0_time"                 , XB_TYPE    }, // 80
    { XB::xb_io1_fure                    , "xb_io1_fure"                 , XB_TYPE    }, // 81
    { XB::xb_io1_gptr                    , "xb_io1_gptr"                 , XB_TYPE    }, // 82
    { XB::xb_io1_time                    , "xb_io1_time"                 , XB_TYPE    }, // 83
    { XB::xb_io2_fure                    , "xb_io2_fure"                 , XB_TYPE    }, // 84
    { XB::xb_io2_gptr                    , "xb_io2_gptr"                 , XB_TYPE    }, // 85
    { XB::xb_io2_time                    , "xb_io2_time"                 , XB_TYPE    }, // 86
    { XB::xb_pll_gptr                    , "xb_pll_gptr"                 , XB_TYPE    }, // 87
    { XB::xb_pll_bndy                    , "xb_pll_bndy"                 , XB_TYPE    }, // 88
    { XB::xb_pll_func                    , "xb_pll_func"                 , XB_TYPE    }, // 89
    { XB::xb_repr                        , "xb_repr"                     , XB_TYPE    }, // 90
    { XB::xb_io0_repr                    , "xb_io0_repr"                 , XB_TYPE    }, // 91
    { XB::xb_io1_repr                    , "xb_io1_repr"                 , XB_TYPE    }, // 92
    { XB::xb_io2_repr                    , "xb_io2_repr"                 , XB_TYPE    }, // 93
    { INVALID_RING                       , "invalid"                     , XB_TYPE    }, // 94
    { INVALID_RING                       , "invalid"                     , XB_TYPE    }, // 95
    { MC::mc_fure                        , "mc_fure"                     , MC_TYPE    }, // 96
    { MC::mc_gptr                        , "mc_gptr"                     , MC_TYPE    }, // 97
    { MC::mc_time                        , "mc_time"                     , MC_TYPE    }, // 98
    { MC::mc_iom01_fure                  , "mc_iom01_fure"               , MC_TYPE    }, // 99
    { MC::mc_iom01_gptr                  , "mc_iom01_gptr"               , MC_TYPE    }, // 100
    { MC::mc_iom01_time                  , "mc_iom01_time"               , MC_TYPE    }, // 101
    { MC::mc_iom23_fure                  , "mc_iom23_fure"               , MC_TYPE    }, // 102
    { MC::mc_iom23_gptr                  , "mc_iom23_gptr"               , MC_TYPE    }, // 103
    { MC::mc_iom23_time                  , "mc_iom23_time"               , MC_TYPE    }, // 104
    { MC::mc_pll_gptr                    , "mc_pll_gptr"                 , MC_TYPE    }, // 105
    { MC::mc_pll_bndy                    , "mc_pll_bndy"                 , MC_TYPE    }, // 106
    { MC::mc_pll_bndy_bucket_1           , "mc_pll_bndy_bucket_1"        , MC_TYPE    }, // 107
    { MC::mc_pll_bndy_bucket_2           , "mc_pll_bndy_bucket_2"        , MC_TYPE    }, // 108
    { MC::mc_pll_bndy_bucket_3           , "mc_pll_bndy_bucket_3"        , MC_TYPE    }, // 109
    { MC::mc_pll_bndy_bucket_4           , "mc_pll_bndy_bucket_4"        , MC_TYPE    }, // 110
    { MC::mc_pll_bndy_bucket_5           , "mc_pll_bndy_bucket_5"        , MC_TYPE    }, // 111
    { MC::mc_pll_func                    , "mc_pll_func"                 , MC_TYPE    }, // 112
    { MC::mc_repr                        , "mc_repr"                     , MC_TYPE    }, // 113
    { MC::mc_iom01_repr                  , "mc_iom01_repr"               , MC_TYPE    }, // 114
    { MC::mc_iom23_repr                  , "mc_iom23_repr"               , MC_TYPE    }, // 115
    { INVALID_RING                       , "invalid"                     , MC_TYPE    }, // 116
    { INVALID_RING                       , "invalid"                     , MC_TYPE    }, // 117
    { OB0::ob0_fure                      , "ob0_fure"                    , OB0_TYPE   }, // 118
    { OB0::ob0_gptr                      , "ob0_gptr"                    , OB0_TYPE   }, // 119
    { OB0::ob0_time                      , "ob0_time"                    , OB0_TYPE   }, // 120
    { OB0::ob0_pll_gptr                  , "ob0_pll_gptr"                , OB0_TYPE   }, // 121
    { OB0::ob0_pll_bndy                  , "ob0_pll_bndy"                , OB0_TYPE   }, // 122
    { OB0::ob0_pll_func                  , "ob0_pll_func"                , OB0_TYPE   }, // 123
    { OB0::ob0_repr                      , "ob0_repr"                    , OB0_TYPE   }, // 124
    { INVALID_RING                       , "invalid"                     , OB0_TYPE   }, // 125
    { INVALID_RING                       , "invalid"                     , OB0_TYPE   }, // 126
    { OB1::ob1_fure                      , "ob1_fure"                    , OB1_TYPE   }, // 127
    { OB1::ob1_gptr                      , "ob1_gptr"                    , OB1_TYPE   }, // 128
    { OB1::ob1_time                      , "ob1_time"                    , OB1_TYPE   }, // 129
    { OB1::ob1_pll_gptr                  , "ob1_pll_gptr"                , OB1_TYPE   }, // 130
    { OB1::ob1_pll_bndy                  , "ob1_pll_bndy"                , OB1_TYPE   }, // 131
    { OB1::ob1_pll_func                  , "ob1_pll_func"                , OB1_TYPE   }, // 132
    { OB1::ob1_repr                      , "ob1_repr"                    , OB1_TYPE   }, // 133
    { INVALID_RING                       , "invalid"                     , OB1_TYPE   }, // 134
    { INVALID_RING                       , "invalid"                     , OB1_TYPE   }, // 135
    { OB2::ob2_fure                      , "ob2_fure"                    , OB2_TYPE   }, // 136
    { OB2::ob2_gptr                      , "ob2_gptr"                    , OB2_TYPE   }, // 137
    { OB2::ob2_time                      , "ob2_time"                    , OB2_TYPE   }, // 138
    { OB2::ob2_pll_gptr                  , "ob2_pll_gptr"                , OB2_TYPE   }, // 139
    { OB2::ob2_pll_bndy                  , "ob2_pll_bndy"                , OB2_TYPE   }, // 140
    { OB2::ob2_pll_func                  , "ob2_pll_func"                , OB2_TYPE   }, // 141
    { OB2::ob2_repr                      , "ob2_repr"                    , OB2_TYPE   }, // 142
    { INVALID_RING                       , "invalid"                     , OB2_TYPE   }, // 143
    { INVALID_RING                       , "invalid"                     , OB2_TYPE   }, // 144
    { OB3::ob3_fure                      , "ob3_fure"                    , OB3_TYPE   }, // 145
    { OB3::ob3_gptr                      , "ob3_gptr"                    , OB3_TYPE   }, // 146
    { OB3::ob3_time                      , "ob3_time"                    , OB3_TYPE   }, // 147
    { OB3::ob3_pll_gptr                  , "ob3_pll_gptr"                , OB3_TYPE   }, // 148
    { OB3::ob3_pll_bndy                  , "ob3_pll_bndy"                , OB3_TYPE   }, // 149
    { OB3::ob3_pll_func                  , "ob3_pll_func"                , OB3_TYPE   }, // 150
    { OB3::ob3_repr                      , "ob3_repr"                    , OB3_TYPE   }, // 151
    { INVALID_RING                       , "invalid"                     , OB3_TYPE   }, // 152
    { INVALID_RING                       , "invalid"                     , OB3_TYPE   }, // 153
    { PCI0::pci0_fure                    , "pci0_fure"                   , PCI0_TYPE  }, // 154
    { PCI0::pci0_gptr                    , "pci0_gptr"                   , PCI0_TYPE  }, // 155
    { PCI0::pci0_time                    , "pci0_time"                   , PCI0_TYPE  }, // 156
    { PCI0::pci0_pll_bndy                , "pci0_pll_bndy"               , PCI0_TYPE  }, // 157
    { PCI0::pci0_pll_gptr                , "pci0_pll_gptr"               , PCI0_TYPE  }, // 158
    { PCI0::pci0_repr                    , "pci0_repr"                   , PCI0_TYPE  }, // 159
    { PCI1::pci1_fure                    , "pci1_fure"                   , PCI1_TYPE  }, // 160
    { PCI1::pci1_gptr                    , "pci1_gptr"                   , PCI1_TYPE  }, // 161
    { PCI1::pci1_time                    , "pci1_time"                   , PCI1_TYPE  }, // 162
    { PCI1::pci1_pll_bndy                , "pci1_pll_bndy"               , PCI1_TYPE  }, // 163
    { PCI1::pci1_pll_gptr                , "pci1_pll_gptr"               , PCI1_TYPE  }, // 164
    { PCI1::pci1_repr                    , "pci1_repr"                   , PCI1_TYPE  }, // 165
    { PCI2::pci2_fure                    , "pci2_fure"                   , PCI2_TYPE  }, // 166
    { PCI2::pci2_gptr                    , "pci2_gptr"                   , PCI2_TYPE  }, // 167
    { PCI2::pci2_time                    , "pci2_time"                   , PCI2_TYPE  }, // 168
    { PCI2::pci2_pll_bndy                , "pci2_pll_bndy"               , PCI2_TYPE  }, // 169
    { PCI2::pci2_pll_gptr                , "pci2_pll_gptr"               , PCI2_TYPE  }, // 170
    { PCI2::pci2_repr                    , "pci2_repr"                   , PCI2_TYPE  }, // 171
    { EQ::eq_fure                        , "eq_fure"                     , EQ_TYPE    }, // 172
    { EQ::eq_gptr                        , "eq_gptr"                     , EQ_TYPE    }, // 173
    { EQ::eq_time                        , "eq_time"                     , EQ_TYPE    }, // 174
    { EQ::eq_mode                        , "eq_mode"                     , EQ_TYPE    }, // 175
    { EQ::ex_l3_fure                     , "ex_l3_fure"                  , EQ_TYPE    }, // 176
    { EQ::ex_l3_gptr                     , "ex_l3_gptr"                  , EQ_TYPE    }, // 177
    { EQ::ex_l3_time                     , "ex_l3_time"                  , EQ_TYPE    }, // 178
    { EQ::ex_l2_mode                     , "ex_l2_mode"                  , EQ_TYPE    }, // 179
    { EQ::ex_l2_fure                     , "ex_l2_fure"                  , EQ_TYPE    }, // 180
    { EQ::ex_l2_gptr                     , "ex_l2_gptr"                  , EQ_TYPE    }, // 181
    { EQ::ex_l2_time                     , "ex_l2_time"                  , EQ_TYPE    }, // 182
    { EQ::ex_l3_refr_fure                , "ex_l3_refr_fure"             , EQ_TYPE    }, // 183
    { EQ::ex_l3_refr_gptr                , "ex_l3_refr_gptr"             , EQ_TYPE    }, // 184
    { EQ::ex_l3_refr_time                , "ex_l3_refr_time"             , EQ_TYPE    }, // 185
    { EQ::eq_ana_func                    , "eq_ana_func"                 , EQ_TYPE    }, // 186
    { EQ::eq_ana_gptr                    , "eq_ana_gptr"                 , EQ_TYPE    }, // 187
    { EQ::eq_dpll_func                   , "eq_dpll_func"                , EQ_TYPE    }, // 188
    { EQ::eq_dpll_gptr                   , "eq_dpll_gptr"                , EQ_TYPE    }, // 189
    { EQ::eq_dpll_mode                   , "eq_dpll_mode"                , EQ_TYPE    }, // 190
    { EQ::eq_ana_bndy                    , "eq_ana_bndy"                 , EQ_TYPE    }, // 191
    { EQ::eq_ana_bndy_bucket_0           , "eq_ana_bndy_bucket_0"        , EQ_TYPE    }, // 192
    { EQ::eq_ana_bndy_bucket_1           , "eq_ana_bndy_bucket_1"        , EQ_TYPE    }, // 193
    { EQ::eq_ana_bndy_bucket_2           , "eq_ana_bndy_bucket_2"        , EQ_TYPE    }, // 194
    { EQ::eq_ana_bndy_bucket_3           , "eq_ana_bndy_bucket_3"        , EQ_TYPE    }, // 195
    { EQ::eq_ana_bndy_bucket_4           , "eq_ana_bndy_bucket_4"        , EQ_TYPE    }, // 196
    { EQ::eq_ana_bndy_bucket_5           , "eq_ana_bndy_bucket_5"        , EQ_TYPE    }, // 197
    { EQ::eq_ana_bndy_bucket_6           , "eq_ana_bndy_bucket_6"        , EQ_TYPE    }, // 198
    { EQ::eq_ana_bndy_bucket_7           , "eq_ana_bndy_bucket_7"        , EQ_TYPE    }, // 199
    { EQ::eq_ana_bndy_bucket_8           , "eq_ana_bndy_bucket_8"        , EQ_TYPE    }, // 200
    { EQ::eq_ana_bndy_bucket_9           , "eq_ana_bndy_bucket_9"        , EQ_TYPE    }, // 201
    { EQ::eq_ana_bndy_bucket_10          , "eq_ana_bndy_bucket_10"       , EQ_TYPE    }, // 202
    { EQ::eq_ana_bndy_bucket_11          , "eq_ana_bndy_bucket_11"       , EQ_TYPE    }, // 203
    { EQ::eq_ana_bndy_bucket_12          , "eq_ana_bndy_bucket_12"       , EQ_TYPE    }, // 204
    { EQ::eq_ana_bndy_bucket_13          , "eq_ana_bndy_bucket_13"       , EQ_TYPE    }, // 205
    { EQ::eq_ana_bndy_bucket_14          , "eq_ana_bndy_bucket_14"       , EQ_TYPE    }, // 206
    { EQ::eq_ana_bndy_bucket_15          , "eq_ana_bndy_bucket_15"       , EQ_TYPE    }, // 207
    { EQ::eq_ana_bndy_bucket_16          , "eq_ana_bndy_bucket_16"       , EQ_TYPE    }, // 208
    { EQ::eq_ana_bndy_bucket_17          , "eq_ana_bndy_bucket_17"       , EQ_TYPE    }, // 209
    { EQ::eq_ana_bndy_bucket_18          , "eq_ana_bndy_bucket_18"       , EQ_TYPE    }, // 210
    { EQ::eq_ana_bndy_bucket_19          , "eq_ana_bndy_bucket_19"       , EQ_TYPE    }, // 211
    { EQ::eq_ana_bndy_bucket_20          , "eq_ana_bndy_bucket_20"       , EQ_TYPE    }, // 212
    { EQ::eq_ana_bndy_bucket_21          , "eq_ana_bndy_bucket_21"       , EQ_TYPE    }, // 213
    { EQ::eq_ana_bndy_bucket_22          , "eq_ana_bndy_bucket_22"       , EQ_TYPE    }, // 214
    { EQ::eq_ana_bndy_bucket_23          , "eq_ana_bndy_bucket_23"       , EQ_TYPE    }, // 215
    { EQ::eq_ana_bndy_bucket_24          , "eq_ana_bndy_bucket_24"       , EQ_TYPE    }, // 216
    { EQ::eq_ana_bndy_bucket_25          , "eq_ana_bndy_bucket_25"       , EQ_TYPE    }, // 217
    { EQ::eq_ana_bndy_l3dcc_bucket_26    , "eq_ana_bndy_l3dcc_bucket_26" , EQ_TYPE    }, // 218
    { EQ::eq_ana_mode                    , "eq_ana_mode"                 , EQ_TYPE    }, // 219
    { EQ::eq_repr                        , "eq_repr"                     , EQ_TYPE    }, // 220
    { EQ::ex_l3_repr                     , "ex_l3_repr"                  , EQ_TYPE    }, // 221
    { EQ::ex_l2_repr                     , "ex_l2_repr"                  , EQ_TYPE    }, // 222
    { EQ::ex_l3_refr_repr                , "ex_l3_refr_repr"             , EQ_TYPE    }, // 223
    { EC::ec_func                        , "ec_func"                     , EC_TYPE    }, // 224
    { EC::ec_gptr                        , "ec_gptr"                     , EC_TYPE    }, // 225
    { EC::ec_time                        , "ec_time"                     , EC_TYPE    }, // 226
    { EC::ec_mode                        , "ec_mode"                     , EC_TYPE    }, // 227
    { EC::ec_repr                        , "ec_repr"                     , EC_TYPE    }, // 228
    { EQ::ex_l2_fure_1                   , "ex_l2_fure_1"                , EQ_TYPE    }, // 229
    { EQ::ex_l3_fure_1                   , "ex_l3_fure_1"                , EQ_TYPE    }, // 230
};
#endif
#ifdef __PPE__
static const ringProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { PERV::perv_fure                    , PERV_TYPE  }, // 0
    { PERV::perv_gptr                    , PERV_TYPE  }, // 1
    { PERV::perv_time                    , PERV_TYPE  }, // 2
    { PERV::occ_fure                     , PERV_TYPE  }, // 3
    { PERV::occ_gptr                     , PERV_TYPE  }, // 4
    { PERV::occ_time                     , PERV_TYPE  }, // 5
    { PERV::perv_ana_func                , PERV_TYPE  }, // 6
    { PERV::perv_ana_gptr                , PERV_TYPE  }, // 7
    { PERV::perv_pll_gptr                , PERV_TYPE  }, // 8
    { PERV::perv_pll_bndy                , PERV_TYPE  }, // 9
    { PERV::perv_pll_bndy_bucket_1       , PERV_TYPE  }, // 10
    { PERV::perv_pll_bndy_bucket_2       , PERV_TYPE  }, // 11
    { PERV::perv_pll_bndy_bucket_3       , PERV_TYPE  }, // 12
    { PERV::perv_pll_bndy_bucket_4       , PERV_TYPE  }, // 13
    { PERV::perv_pll_bndy_bucket_5       , PERV_TYPE  }, // 14
    { PERV::perv_pll_func                , PERV_TYPE  }, // 15
    { PERV::perv_repr                    , PERV_TYPE  }, // 16
    { PERV::occ_repr                     , PERV_TYPE  }, // 17
    { INVALID_RING                       , PERV_TYPE  }, // 18
    { INVALID_RING                       , PERV_TYPE  }, // 19
    { INVALID_RING                       , PERV_TYPE  }, // 20
    { N0::n0_fure                        , N0_TYPE    }, // 21
    { N0::n0_gptr                        , N0_TYPE    }, // 22
    { N0::n0_time                        , N0_TYPE    }, // 23
    { N0::n0_nx_fure                     , N0_TYPE    }, // 24
    { N0::n0_nx_gptr                     , N0_TYPE    }, // 25
    { N0::n0_nx_time                     , N0_TYPE    }, // 26
    { N0::n0_cxa0_fure                   , N0_TYPE    }, // 27
    { N0::n0_cxa0_gptr                   , N0_TYPE    }, // 28
    { N0::n0_cxa0_time                   , N0_TYPE    }, // 29
    { N0::n0_repr                        , N0_TYPE    }, // 30
    { N0::n0_nx_repr                     , N0_TYPE    }, // 31
    { N0::n0_cxa0_repr                   , N0_TYPE    }, // 32
    { N1::n1_fure                        , N1_TYPE    }, // 33
    { N1::n1_gptr                        , N1_TYPE    }, // 34
    { N1::n1_time                        , N1_TYPE    }, // 35
    { N1::n1_ioo0_fure                   , N1_TYPE    }, // 36
    { N1::n1_ioo0_gptr                   , N1_TYPE    }, // 37
    { N1::n1_ioo0_time                   , N1_TYPE    }, // 38
    { N1::n1_ioo1_fure                   , N1_TYPE    }, // 39
    { N1::n1_ioo1_gptr                   , N1_TYPE    }, // 40
    { N1::n1_ioo1_time                   , N1_TYPE    }, // 41
    { N1::n1_mcs23_fure                  , N1_TYPE    }, // 42
    { N1::n1_mcs23_gptr                  , N1_TYPE    }, // 43
    { N1::n1_mcs23_time                  , N1_TYPE    }, // 44
    { N1::n1_repr                        , N1_TYPE    }, // 45
    { N1::n1_ioo0_repr                   , N1_TYPE    }, // 46
    { N1::n1_ioo1_repr                   , N1_TYPE    }, // 47
    { N1::n1_mcs23_repr                  , N1_TYPE    }, // 48
    { N2::n2_fure                        , N2_TYPE    }, // 49
    { N2::n2_gptr                        , N2_TYPE    }, // 50
    { N2::n2_time                        , N2_TYPE    }, // 51
    { N2::n2_cxa1_fure                   , N2_TYPE    }, // 52
    { N2::n2_cxa1_gptr                   , N2_TYPE    }, // 53
    { N2::n2_cxa1_time                   , N2_TYPE    }, // 54
    { N2::n2_psi_fure                    , N2_TYPE    }, // 55
    { N2::n2_psi_gptr                    , N2_TYPE    }, // 56
    { N2::n2_psi_time                    , N2_TYPE    }, // 57
    { N2::n2_repr                        , N2_TYPE    }, // 58
    { N2::n2_cxa1_repr                   , N2_TYPE    }, // 59
    { N2::n2_psi_repr                    , N2_TYPE    }, // 60
    { INVALID_RING                       , N2_TYPE    }, // 61
    { N3::n3_fure                        , N3_TYPE    }, // 62
    { N3::n3_gptr                        , N3_TYPE    }, // 63
    { N3::n3_time                        , N3_TYPE    }, // 64
    { N3::n3_mcs01_fure                  , N3_TYPE    }, // 65
    { N3::n3_mcs01_gptr                  , N3_TYPE    }, // 66
    { N3::n3_mcs01_time                  , N3_TYPE    }, // 67
    { N3::n3_np_fure                     , N3_TYPE    }, // 68
    { N3::n3_np_gptr                     , N3_TYPE    }, // 69
    { N3::n3_np_time                     , N3_TYPE    }, // 70
    { N3::n3_repr                        , N3_TYPE    }, // 71
    { N3::n3_mcs01_repr                  , N3_TYPE    }, // 72
    { N3::n3_np_repr                     , N3_TYPE    }, // 73
    { INVALID_RING                       , N3_TYPE    }, // 74
    { XB::xb_fure                        , XB_TYPE    }, // 75
    { XB::xb_gptr                        , XB_TYPE    }, // 76
    { XB::xb_time                        , XB_TYPE    }, // 77
    { XB::xb_io0_fure                    , XB_TYPE    }, // 78
    { XB::xb_io0_gptr                    , XB_TYPE    }, // 79
    { XB::xb_io0_time                    , XB_TYPE    }, // 80
    { XB::xb_io1_fure                    , XB_TYPE    }, // 81
    { XB::xb_io1_gptr                    , XB_TYPE    }, // 82
    { XB::xb_io1_time                    , XB_TYPE    }, // 83
    { XB::xb_io2_fure                    , XB_TYPE    }, // 84
    { XB::xb_io2_gptr                    , XB_TYPE    }, // 85
    { XB::xb_io2_time                    , XB_TYPE    }, // 86
    { XB::xb_pll_gptr                    , XB_TYPE    }, // 87
    { XB::xb_pll_bndy                    , XB_TYPE    }, // 88
    { XB::xb_pll_func                    , XB_TYPE    }, // 89
    { XB::xb_repr                        , XB_TYPE    }, // 90
    { XB::xb_io0_repr                    , XB_TYPE    }, // 91
    { XB::xb_io1_repr                    , XB_TYPE    }, // 92
    { XB::xb_io2_repr                    , XB_TYPE    }, // 93
    { INVALID_RING                       , XB_TYPE    }, // 94
    { INVALID_RING                       , XB_TYPE    }, // 95
    { MC::mc_fure                        , MC_TYPE    }, // 96
    { MC::mc_gptr                        , MC_TYPE    }, // 97
    { MC::mc_time                        , MC_TYPE    }, // 98
    { MC::mc_iom01_fure                  , MC_TYPE    }, // 99
    { MC::mc_iom01_gptr                  , MC_TYPE    }, // 100
    { MC::mc_iom01_time                  , MC_TYPE    }, // 101
    { MC::mc_iom23_fure                  , MC_TYPE    }, // 102
    { MC::mc_iom23_gptr                  , MC_TYPE    }, // 103
    { MC::mc_iom23_time                  , MC_TYPE    }, // 104
    { MC::mc_pll_gptr                    , MC_TYPE    }, // 105
    { MC::mc_pll_bndy                    , MC_TYPE    }, // 106
    { MC::mc_pll_bndy_bucket_1           , MC_TYPE    }, // 107
    { MC::mc_pll_bndy_bucket_2           , MC_TYPE    }, // 108
    { MC::mc_pll_bndy_bucket_3           , MC_TYPE    }, // 109
    { MC::mc_pll_bndy_bucket_4           , MC_TYPE    }, // 110
    { MC::mc_pll_bndy_bucket_5           , MC_TYPE    }, // 111
    { MC::mc_pll_func                    , MC_TYPE    }, // 112
    { MC::mc_repr                        , MC_TYPE    }, // 113
    { MC::mc_iom01_repr                  , MC_TYPE    }, // 114
    { MC::mc_iom23_repr                  , MC_TYPE    }, // 115
    { INVALID_RING                       , MC_TYPE    }, // 116
    { INVALID_RING                       , MC_TYPE    }, // 117
    { OB0::ob0_fure                      , OB0_TYPE   }, // 118
    { OB0::ob0_gptr                      , OB0_TYPE   }, // 119
    { OB0::ob0_time                      , OB0_TYPE   }, // 120
    { OB0::ob0_pll_gptr                  , OB0_TYPE   }, // 121
    { OB0::ob0_pll_bndy                  , OB0_TYPE   }, // 122
    { OB0::ob0_pll_func                  , OB0_TYPE   }, // 123
    { OB0::ob0_repr                      , OB0_TYPE   }, // 124
    { INVALID_RING                       , OB0_TYPE   }, // 125
    { INVALID_RING                       , OB0_TYPE   }, // 126
    { OB1::ob1_fure                      , OB1_TYPE   }, // 127
    { OB1::ob1_gptr                      , OB1_TYPE   }, // 128
    { OB1::ob1_time                      , OB1_TYPE   }, // 129
    { OB1::ob1_pll_gptr                  , OB1_TYPE   }, // 130
    { OB1::ob1_pll_bndy                  , OB1_TYPE   }, // 131
    { OB1::ob1_pll_func                  , OB1_TYPE   }, // 132
    { OB1::ob1_repr                      , OB1_TYPE   }, // 133
    { INVALID_RING                       , OB1_TYPE   }, // 134
    { INVALID_RING                       , OB1_TYPE   }, // 135
    { OB2::ob2_fure                      , OB2_TYPE   }, // 136
    { OB2::ob2_gptr                      , OB2_TYPE   }, // 137
    { OB2::ob2_time                      , OB2_TYPE   }, // 138
    { OB2::ob2_pll_gptr                  , OB2_TYPE   }, // 139
    { OB2::ob2_pll_bndy                  , OB2_TYPE   }, // 140
    { OB2::ob2_pll_func                  , OB2_TYPE   }, // 141
    { OB2::ob2_repr                      , OB2_TYPE   }, // 142
    { INVALID_RING                       , OB2_TYPE   }, // 143
    { INVALID_RING                       , OB2_TYPE   }, // 144
    { OB3::ob3_fure                      , OB3_TYPE   }, // 145
    { OB3::ob3_gptr                      , OB3_TYPE   }, // 146
    { OB3::ob3_time                      , OB3_TYPE   }, // 147
    { OB3::ob3_pll_gptr                  , OB3_TYPE   }, // 148
    { OB3::ob3_pll_bndy                  , OB3_TYPE   }, // 149
    { OB3::ob3_pll_func                  , OB3_TYPE   }, // 150
    { OB3::ob3_repr                      , OB3_TYPE   }, // 151
    { INVALID_RING                       , OB3_TYPE   }, // 152
    { INVALID_RING                       , OB3_TYPE   }, // 153
    { PCI0::pci0_fure                    , PCI0_TYPE  }, // 154
    { PCI0::pci0_gptr                    , PCI0_TYPE  }, // 155
    { PCI0::pci0_time                    , PCI0_TYPE  }, // 156
    { PCI0::pci0_pll_bndy                , PCI0_TYPE  }, // 157
    { PCI0::pci0_pll_gptr                , PCI0_TYPE  }, // 158
    { PCI0::pci0_repr                    , PCI0_TYPE  }, // 159
    { PCI1::pci1_fure                    , PCI1_TYPE  }, // 160
    { PCI1::pci1_gptr                    , PCI1_TYPE  }, // 161
    { PCI1::pci1_time                    , PCI1_TYPE  }, // 162
    { PCI1::pci1_pll_bndy                , PCI1_TYPE  }, // 163
    { PCI1::pci1_pll_gptr                , PCI1_TYPE  }, // 164
    { PCI1::pci1_repr                    , PCI1_TYPE  }, // 165
    { PCI2::pci2_fure                    , PCI2_TYPE  }, // 166
    { PCI2::pci2_gptr                    , PCI2_TYPE  }, // 167
    { PCI2::pci2_time                    , PCI2_TYPE  }, // 168
    { PCI2::pci2_pll_bndy                , PCI2_TYPE  }, // 169
    { PCI2::pci2_pll_gptr                , PCI2_TYPE  }, // 170
    { PCI2::pci2_repr                    , PCI2_TYPE  }, // 171
    { EQ::eq_fure                        , EQ_TYPE    }, // 172
    { EQ::eq_gptr                        , EQ_TYPE    }, // 173
    { EQ::eq_time                        , EQ_TYPE    }, // 174
    { EQ::eq_mode                        , EQ_TYPE    }, // 175
    { EQ::ex_l3_fure                     , EQ_TYPE    }, // 176
    { EQ::ex_l3_gptr                     , EQ_TYPE    }, // 177
    { EQ::ex_l3_time                     , EQ_TYPE    }, // 178
    { EQ::ex_l2_mode                     , EQ_TYPE    }, // 179
    { EQ::ex_l2_fure                     , EQ_TYPE    }, // 180
    { EQ::ex_l2_gptr                     , EQ_TYPE    }, // 181
    { EQ::ex_l2_time                     , EQ_TYPE    }, // 182
    { EQ::ex_l3_refr_fure                , EQ_TYPE    }, // 183
    { EQ::ex_l3_refr_gptr                , EQ_TYPE    }, // 184
    { EQ::ex_l3_refr_time                , EQ_TYPE    }, // 185
    { EQ::eq_ana_func                    , EQ_TYPE    }, // 186
    { EQ::eq_ana_gptr                    , EQ_TYPE    }, // 187
    { EQ::eq_dpll_func                   , EQ_TYPE    }, // 188
    { EQ::eq_dpll_gptr                   , EQ_TYPE    }, // 189
    { EQ::eq_dpll_mode                   , EQ_TYPE    }, // 190
    { EQ::eq_ana_bndy                    , EQ_TYPE    }, // 191
    { EQ::eq_ana_bndy_bucket_0           , EQ_TYPE    }, // 192
    { EQ::eq_ana_bndy_bucket_1           , EQ_TYPE    }, // 193
    { EQ::eq_ana_bndy_bucket_2           , EQ_TYPE    }, // 194
    { EQ::eq_ana_bndy_bucket_3           , EQ_TYPE    }, // 195
    { EQ::eq_ana_bndy_bucket_4           , EQ_TYPE    }, // 196
    { EQ::eq_ana_bndy_bucket_5           , EQ_TYPE    }, // 197
    { EQ::eq_ana_bndy_bucket_6           , EQ_TYPE    }, // 198
    { EQ::eq_ana_bndy_bucket_7           , EQ_TYPE    }, // 199
    { EQ::eq_ana_bndy_bucket_8           , EQ_TYPE    }, // 200
    { EQ::eq_ana_bndy_bucket_9           , EQ_TYPE    }, // 201
    { EQ::eq_ana_bndy_bucket_10          , EQ_TYPE    }, // 202
    { EQ::eq_ana_bndy_bucket_11          , EQ_TYPE    }, // 203
    { EQ::eq_ana_bndy_bucket_12          , EQ_TYPE    }, // 204
    { EQ::eq_ana_bndy_bucket_13          , EQ_TYPE    }, // 205
    { EQ::eq_ana_bndy_bucket_14          , EQ_TYPE    }, // 206
    { EQ::eq_ana_bndy_bucket_15          , EQ_TYPE    }, // 207
    { EQ::eq_ana_bndy_bucket_16          , EQ_TYPE    }, // 208
    { EQ::eq_ana_bndy_bucket_17          , EQ_TYPE    }, // 209
    { EQ::eq_ana_bndy_bucket_18          , EQ_TYPE    }, // 210
    { EQ::eq_ana_bndy_bucket_19          , EQ_TYPE    }, // 211
    { EQ::eq_ana_bndy_bucket_20          , EQ_TYPE    }, // 212
    { EQ::eq_ana_bndy_bucket_21          , EQ_TYPE    }, // 213
    { EQ::eq_ana_bndy_bucket_22          , EQ_TYPE    }, // 214
    { EQ::eq_ana_bndy_bucket_23          , EQ_TYPE    }, // 215
    { EQ::eq_ana_bndy_bucket_24          , EQ_TYPE    }, // 216
    { EQ::eq_ana_bndy_bucket_25          , EQ_TYPE    }, // 217
    { EQ::eq_ana_bndy_l3dcc_bucket_26    , EQ_TYPE    }, // 218
    { EQ::eq_ana_mode                    , EQ_TYPE    }, // 219
    { EQ::eq_repr                        , EQ_TYPE    }, // 220
    { EQ::ex_l3_repr                     , EQ_TYPE    }, // 221
    { EQ::ex_l2_repr                     , EQ_TYPE    }, // 222
    { EQ::ex_l3_refr_repr                , EQ_TYPE    }, // 223
    { EC::ec_func                        , EC_TYPE    }, // 224
    { EC::ec_gptr                        , EC_TYPE    }, // 225
    { EC::ec_time                        , EC_TYPE    }, // 226
    { EC::ec_mode                        , EC_TYPE    }, // 227
    { EC::ec_repr                        , EC_TYPE    }, // 228
    { EQ::ex_l2_fure_1                   , EQ_TYPE    }, // 229
    { EQ::ex_l3_fure_1                   , EQ_TYPE    }, // 230
};
#endif

// returns our own chiplet enum value for this ringId
CHIPLET_TYPE
p9_ringid_get_chiplet(
    RingID i_ringId);

// returns data structures defined for chiplet type
// as determined by ringId
void
p9_ringid_get_chiplet_properties(
    CHIPLET_TYPE       i_chiplet,
    CHIPLET_DATA**     o_cpltData,
    GenRingIdList**    o_ringComm,
    GenRingIdList**    o_ringInst,
    RingVariantOrder** o_varOrder,
    uint8_t*           o_varNumb);

// returns properties of a ring as determined by ringId
GenRingIdList*
p9_ringid_get_ring_properties(
    RingID i_ringId);

#endif
