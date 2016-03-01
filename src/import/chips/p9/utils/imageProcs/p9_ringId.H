/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_ringId.H $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

#ifndef _P9_RINGID_H_
#define _P9_RINGID_H_

#include <stdint.h>

namespace RING_TYPES
{
enum RINGTYPE
{
    COMMON_RING = 0,
    INSTANCE_RING = 1
};
}; //end of RING_TYPES namespace
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
    OB_TYPE,
    XB_TYPE,
    EQ_TYPE,
    EC_TYPE,
};

///
/// @enum RingID
/// @brief Enumeration of Ring ID values. These values are used to traverse
///        an image having Ring Containers.
// NOTE: Do not change the numbering, the sequence or add new constants to
//       the below enum, unless you know the effect it has on the traversing
//       of the image for Ring Containers.
enum RingID
{
    //*****************************
    // Rings needed for SBE - Start
    //*****************************
    // Perv Chiplet Rings
    perv_fure = 0,
    perv_gptr = 1,
    perv_time = 2,
    occ_fure = 3,
    occ_gptr = 4,
    occ_time = 5,
    perv_ana_func = 6,
    perv_ana_gptr = 7,
    perv_pll_gptr = 8,
    perv_pll_bndy = 9,
    perv_pll_bndy_bucket_1 = 10,
    perv_pll_bndy_bucket_2 = 11,
    perv_pll_bndy_bucket_3 = 12,
    perv_pll_bndy_bucket_4 = 13,
    perv_pll_bndy_bucket_5 = 14,
    perv_repr = 15,
    occ_repr = 16,
    // values 17-18 unused

    // Nest Chiplet Rings - N0
    n0_fure = 19,
    n0_gptr = 20,
    n0_time = 21,
    n0_nx_fure = 22,
    n0_nx_gptr = 23,
    n0_nx_time = 24,
    n0_cxa0_fure = 25,
    n0_cxa0_gptr = 26,
    n0_cxa0_time = 27,
    n0_repr = 28,
    n0_nx_repr = 29,
    n0_cxa0_repr = 30,
    // values 31-33 unused

    // Nest Chiplet Rings - N1
    n1_fure = 34,
    n1_gptr = 35,
    n1_time = 36,
    n1_ioo0_fure = 37,
    n1_ioo0_gptr = 38,
    n1_ioo0_time = 39,
    n1_ioo1_fure = 40,
    n1_ioo1_gptr = 41,
    n1_ioo1_time = 42,
    n1_mcs23_fure = 43,
    n1_mcs23_gptr = 44,
    n1_mcs23_time = 45,
    n1_repr = 46,
    n1_ioo0_repr = 47,
    n1_ioo1_repr = 48,
    n1_mcs23_repr = 49,
    // values 50-52 unused

    // Nest Chiplet Rings - N2
    n2_fure = 53,
    n2_gptr = 54,
    n2_time = 55,
    n2_cxa1_fure = 56,
    n2_cxa1_gptr = 57,
    n2_cxa1_time = 58,
    n2_repr = 59,
    n2_cxa1_repr = 60,
    // values 61-63 unused

    // Nest Chiplet Rings - N3
    n3_fure = 64,
    n3_gptr = 65,
    n3_time = 66,
    n3_mcs01_fure = 67,
    n3_mcs01_gptr = 68,
    n3_mcs01_time = 69,
    n3_repr = 70,
    n3_mcs01_repr = 71,
    // values 72-74 unused

    // X-Bus Chiplet Rings
    // Common - apply to all instances of X-Bus
    xb_fure = 75,
    xb_gptr = 76,
    xb_time = 77,
    xb_io0_fure = 78,
    xb_io0_gptr = 79,
    xb_io0_time = 80,
    xb_io1_fure = 81,
    xb_io1_gptr = 82,
    xb_io1_time = 83,
    xb_io2_fure = 84,
    xb_io2_gptr = 85,
    xb_io2_time = 86,
    xb_pll_gptr = 87,
    xb_pll_other = 88,
    xb_pll_bndy  = 89,
    xb_pll_bndy_bucket_1 = 90,
    xb_pll_bndy_bucket_2 = 91,
    xb_pll_bndy_bucket_3 = 92,
    xb_pll_bndy_bucket_4 = 93,
    xb_pll_bndy_bucket_5 = 94,

    // X-Bus Chiplet Rings
    // X0, X1 and X2 instance specific Rings
    xb_repr = 95,
    xb_io0_repr = 96,
    xb_io1_repr = 97,
    xb_io2_repr = 98,
    // values 99-100 unused

    // MC Chiplet Rings
    // Common - apply to all instances of MC
    mc_fure = 101,
    mc_gptr = 102,
    mc_time = 103,
    mc_iom01_fure = 104,
    mc_iom01_gptr = 105,
    mc_iom01_time = 106,
    mc_iom23_fure = 107,
    mc_iom23_gptr = 108,
    mc_iom23_time = 109,
    mc_pll_gptr = 110,
    mc_pll_other = 111,
    mc_pll_bndy  = 112,
    mc_pll_bndy_bucket_1 = 113,
    mc_pll_bndy_bucket_2 = 114,
    mc_pll_bndy_bucket_3 = 115,
    mc_pll_bndy_bucket_4 = 116,
    mc_pll_bndy_bucket_5 = 117,

    // MC Chiplet Rings
    // MC01 and MC23 instance specific Rings
    mc_repr = 118,
    mc_iom01_repr = 119,
    mc_iom23_repr = 120,
    // values 121-123 unused

    // OB Chiplet Rings
    // Common - apply to all instances of O-Bus
    ob_fure = 124,
    ob_gptr = 125,
    ob_time = 126,
    ob_pll_gptr = 127,
    ob_pll_other = 128,
    ob_pll_bndy  = 129,
    ob_pll_bndy_bucket_1 = 130,
    ob_pll_bndy_bucket_2 = 131,
    ob_pll_bndy_bucket_3 = 132,
    ob_pll_bndy_bucket_4 = 133,
    ob_pll_bndy_bucket_5 = 134,

    // OB Chiplet Rings
    // OB0, OB1, OB2 and OB3 instance specific Ring
    ob_repr = 135,
    // values 136-137 unused

    // PCI Chiplet Rings
    // PCI0 Common Rings
    pci0_fure = 138,
    pci0_gptr = 139,
    pci0_time = 140,
    // Instance specific Rings
    pci0_repr = 141,

    // PCI1 Common Rings
    pci1_fure = 142,
    pci1_gptr = 143,
    pci1_time = 144,
    // Instance specific Rings
    pci1_repr = 145,

    // PCI2 Common Rings
    pci2_fure = 146,
    pci2_gptr = 147,
    pci2_time = 148,
    // Instance specific Rings
    pci2_repr = 149,
    // vlaues 150-152 unused

    // Quad Chiplet Rings
    // Common - apply to all Quad instances
    eq_fure = 153,
    eq_gptr = 154,
    eq_time = 155,
    ex_l3_fure = 156,
    ex_l3_gptr = 157,
    ex_l3_time = 158,
    ex_l2_fure = 159,
    ex_l2_gptr = 160,
    ex_l2_time = 161,
    ex_l3_refr_fure = 162,
    ex_l3_refr_gptr = 163,
    ex_l3_refr_time = 164,
    eq_ana_func = 165,
    eq_ana_gptr = 166,
    eq_dpll_func = 167,
    eq_dpll_gptr = 168,
    eq_dpll_other = 169,

    // Quad Chiplet Rings
    // EQ0 - EQ5 instance specific Rings
    eq_repr = 170,
    ex_l3_repr = 171,
    ex_l2_repr = 172,
    ex_l3_refr_repr = 173,

    // Quad Chiplet Rings
    // Common - apply to all Quad instances
    eq_ana_bndy = 174,
    // values 175-176 unused

    // Core Chiplet Rings
    // Common - apply to all Core instances
    ec_func = 177,
    ec_gptr = 178,
    ec_time = 179,
    ec_mode = 180,

    // Core Chiplet Rings
    // EC0 - EC23 instance specific Ring
    ec_repr = 181,
    //***************************
    // Rings needed for SBE - End
    //***************************

    P9_NUM_RINGS // This shoud always be the last constant
}; // end of enum RingID

struct CHIPLET_DATA
{
    // This is the chiplet-ID of the first instance of the Chiplet
    uint8_t iv_base_chiplet_number;

    // The no.of common rings for the Chiplet
    uint8_t iv_num_common_rings;

    // The no.of instance rings for the Chiplet
    uint8_t iv_num_instance_rings;
};

// This is used to Set (Mark) the left-most bit
const uint32_t INSTANCE_RING_MARK = 0x8000000;
//
// This is used to Set (Mark) the left-most bit
const uint32_t INSTANCE_RING_MASK = 0x7FFFFFFF;

namespace PERV
{
struct RingVariants
{
    uint16_t iv_base;
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
    // Instance Rings
    perv_repr     = (0 | INSTANCE_RING_MARK),
    occ_repr      = (1 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_pervData =
{
    1,  // Pervasive Chiplet ID is 1
    14, // 14 common rings for pervasive chiplet
    2   // 2 instance specific rings for pervasive chiplet
};
}; // end of namespace PERV

namespace N0
{
struct RingVariants
{
    uint16_t iv_base;
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
    3  // 3 instance specific rings for N0 chiplet
};
};

namespace N1
{
struct RingVariants
{
    uint16_t iv_base;
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
    4   // 4 instance specific rings for N1 chiplet
};
};

namespace N2
{
struct RingVariants
{
    uint16_t iv_base;
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
    // Instance Rings
    n2_repr      = (0 | INSTANCE_RING_MARK),
    n2_cxa1_repr = (1 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_n2Data =
{
    4, // N2 Chiplet ID is 4.
    6, // 6 common rings for N2 Chiplet
    2  // 2 instance specific rings for N2 chiplet
};
};

namespace N3
{
struct RingVariants
{
    uint16_t iv_base;
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
    // Instance Rings
    n3_repr       = (0 | INSTANCE_RING_MARK),
    n3_mcs01_repr = (1 | INSTANCE_RING_MARK),
};

static const CHIPLET_DATA g_n3Data =
{
    5, // N3 Chiplet ID is 5
    6, // 6 common rings for N3 Chiplet
    2  // 2 instance specific rings for N3 chiplet
};
};

namespace XB
{
struct RingVariants
{
    uint16_t iv_base;
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
    xb_pll_other = 13,
    xb_pll_bndy  = 14,
    // The values for this and the following constant are purposefully made
    // identical. The idea is to enable the user to specify directly the bucket
    // number or use the Attribute. Giving same number here will enable
    // evaluating to the same offset.
    xb_pll_bndy_bucket_1  = 14,
    xb_pll_bndy_bucket_2  = 15,
    xb_pll_bndy_bucket_3  = 16,
    xb_pll_bndy_bucket_4  = 17,
    xb_pll_bndy_bucket_5  = 18,
    // Instance Rings
    xb_repr      = (0 | INSTANCE_RING_MARK),
    xb_io0_repr  = (1 | INSTANCE_RING_MARK),
    xb_io1_repr  = (2 | INSTANCE_RING_MARK),
    xb_io2_repr  = (3 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_xbData =
{
    6,  // X-Bus Chiplet ID is 6
    19, // 19 common rings for X-Bus Chiplet
    4   // 4 instance specific rings for XB chiplet
};
}; // end of namespace XB

namespace MC
{
struct RingVariants
{
    uint16_t iv_base;
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
    mc_pll_other  = 10,
    // To find the bucket id for MC PLL, NEST_PLL_BUCKET attribute will be used
    mc_pll_bndy = 11,
    mc_pll_bndy_bucket_1 = 11,
    mc_pll_bndy_bucket_2 = 12,
    mc_pll_bndy_bucket_3 = 13,
    mc_pll_bndy_bucket_4 = 14,
    mc_pll_bndy_bucket_5 = 15,
    // Instance Rings
    mc_repr       = (0 | INSTANCE_RING_MARK),
    mc_iom01_repr = (1 | INSTANCE_RING_MARK),
    mc_iom23_repr = (2 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_mcData =
{
    7,  // MC Chiplet ID range is 7 - 8. The base ID is 7.
    16, // 16 common rings for MC Chiplet
    3   // 3 instance specific rings for each MC instance
};
}; // end of namespace MC

namespace OB
{
struct RingVariants
{
    uint16_t iv_base;
};

enum RingOffset
{
    // Common Rings
    ob_fure      = 0,
    ob_gptr      = 1,
    ob_time      = 2,
    ob_pll_gptr  = 3,
    ob_pll_other = 4,
    ob_pll_bndy  = 5,
    // The values for this and the following constant are purposefully made
    // identical. The idea is to enable the user to specify directly the bucket
    // number or use the Attribute. Giving same number here will enable
    // evaluating to the same offset.
    ob_pll_bndy_bucket_1 = 5,
    ob_pll_bndy_bucket_2 = 6,
    ob_pll_bndy_bucket_3 = 7,
    ob_pll_bndy_bucket_4 = 8,
    ob_pll_bndy_bucket_5 = 9,
    // Instance Rings
    ob_repr      = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_obData =
{
    9,  // O-Bus Chiplet ID range is 9 - 12. The base ID is 9.
    10, // 10 common rings for OB Chiplet
    1   // 1 instance specific rings for each OB chiplet
};
}; // end of namespace OB

namespace PCI0
{
struct RingVariants
{
    uint16_t iv_base;
};

enum RingOffset
{
    // Common Rings
    pci0_fure = 0,
    pci0_gptr = 1,
    pci0_time = 2,
    // Instance Rings
    pci0_repr = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_pci0Data =
{
    13, // PCI0 Chiplet Chiplet ID is 13
    3,  // 3 common rings for PCI0 chiplet
    1,  // 1 instance specific rings for PCI0 chiplet
};
};

namespace PCI1
{
struct RingVariants
{
    uint16_t iv_base;
};

enum RingOffset
{
    // Common Rings
    pci1_fure = 0,
    pci1_gptr = 1,
    pci1_time = 2,
    // Instance Rings
    pci1_repr = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_pci1Data =
{
    14, // PCI1 Chiplet Chiplet ID is 14
    3,  // 3 common rings for PCI1 chiplet
    1,  // 1 instance specific rings for PCI1 chiplet
};
};

namespace PCI2
{
struct RingVariants
{
    uint16_t iv_base;
};

enum RingOffset
{
    // Common Rings
    pci2_fure = 0,
    pci2_gptr = 1,
    pci2_time = 2,
    // Instance Rings
    pci2_repr = (0 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_pci2Data =
{
    15, // PCI2 Chiplet Chiplet ID is 15
    3,  // 3 common rings for PCI2 chiplet
    1,  // 1 instance specific rings for PCI2 chiplet
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
    ex_l3_fure      = 3,
    ex_l3_gptr      = 4,
    ex_l3_time      = 5,
    ex_l2_fure      = 6,
    ex_l2_gptr      = 7,
    ex_l2_time      = 8,
    ex_l3_refr_fure = 9,
    ex_l3_refr_gptr = 10,
    ex_l3_refr_time = 11,
    eq_ana_func     = 12,
    eq_ana_gptr     = 13,
    eq_dpll_func    = 14,
    eq_dpll_gptr    = 15,
    eq_dpll_other   = 16,
    eq_ana_bndy     = 17,
    // Instance Rings
    eq_repr         = (0 | INSTANCE_RING_MARK),
    ex_l3_repr      = (1 | INSTANCE_RING_MARK),
    ex_l2_repr      = (2 | INSTANCE_RING_MARK),
    ex_l3_refr_repr = (3 | INSTANCE_RING_MARK)
};

static const CHIPLET_DATA g_eqData =
{
    16, // Quad Chiplet ID range is 16 - 21. The base ID is 16.
    18, // 18 common rings for Quad chiplet
    4,  // 4 instance specific rings for each EQ chiplet
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
    1   // 1 instance specific ring for each Core chiplet
};
}; // end of namespace EC

static const uint32_t INVALID_RING = 999;

// This structure is needed for mapping a RingID to it's corresponding name.
// The names will be used by the build scripts when generating the TOR.
#ifndef __PPE__
struct ringProperties_t
{
    uint32_t iv_torOffSet;
    char iv_name[25];
    CHIPLET_TYPE iv_type;
};
#endif
#ifdef __PPE__
struct ringProperties_t
{
    uint32_t iv_torOffSet;
    CHIPLET_TYPE iv_type;
};
#endif

#ifndef __PPE__
static const ringProperties_t RING_PROPERTIES[P9_NUM_RINGS] =
{
    // Pervasive Ring
    {PERV::perv_fure,      "perv_fure"},      // 0
    {PERV::perv_gptr,      "perv_gptr"},      // 1
    {PERV::perv_time,      "perv_time"},      // 2
    {PERV::occ_fure,       "occ_fure"},       // 3
    {PERV::occ_gptr,       "occ_gptr"},       // 4
    {PERV::occ_time,       "occ_time"},       // 5
    {PERV::perv_ana_func,  "perv_ana_func"},  // 6
    {PERV::perv_ana_gptr,  "perv_ana_gptr"},  // 7
    {PERV::perv_pll_gptr,  "perv_pll_gptr"},  // 8
    {PERV::perv_pll_bndy,  "perv_pll_bndy"},  // 9
    {PERV::perv_pll_bndy_bucket_1, "perv_pll_bndy_bucket_1"},  // 10
    {PERV::perv_pll_bndy_bucket_2, "perv_pll_bndy_bucket_2"},  // 11
    {PERV::perv_pll_bndy_bucket_3, "perv_pll_bndy_bucket_3"},  // 12
    {PERV::perv_pll_bndy_bucket_4, "perv_pll_bndy_bucket_4"},  // 13
    {PERV::perv_pll_bndy_bucket_5, "perv_pll_bndy_bucket_5"},  // 14
    {PERV::perv_repr,      "perv_repr"},  // 15
    {PERV::occ_repr,       "occ_repr"},   // 16
    {INVALID_RING,         ""}, // 17 // for future.
    {INVALID_RING,         ""}, // 18 // for future.

    // Nest N0 Ring
    {N0::n0_fure,         "n0_fure"},      // 19
    {N0::n0_gptr,         "n0_gptr"},      // 20
    {N0::n0_time,         "n0_time"},      // 21
    {N0::n0_nx_fure,      "n0_nx_fure"},   // 22
    {N0::n0_nx_gptr,      "n0_nx_gptr"},   // 23
    {N0::n0_nx_time,      "n0_nx_time"},   // 24
    {N0::n0_cxa0_fure,    "n0_cxa0_fure"}, // 25
    {N0::n0_cxa0_gptr,    "n0_cxa0_gptr"}, // 26
    {N0::n0_cxa0_time,    "n0_cxa0_time"}, // 27
    {N0::n0_repr,         "n0_repr"},      // 28
    {N0::n0_nx_repr,      "n0_nx_repr"},   // 29
    {N0::n0_cxa0_repr,    "n0_cxa0_repr"}, // 30
    {INVALID_RING,         ""}, // 31 // for future.
    {INVALID_RING,         ""}, // 32 // for future.
    {INVALID_RING,         ""}, // 33 // for future.

    // Nest N1 Ring
    {N1::n1_fure,         "n1_fure"},       // 34
    {N1::n1_gptr,         "n1_gptr"},       // 35
    {N1::n1_time,         "n1_time"},       // 36
    {N1::n1_ioo0_fure,    "n1_ioo0_fure"},  // 37
    {N1::n1_ioo0_gptr,    "n1_ioo0_gptr"},  // 38
    {N1::n1_ioo0_time,    "n1_ioo0_time"},  // 39
    {N1::n1_ioo1_fure,    "n1_ioo1_fure"},  // 40
    {N1::n1_ioo1_gptr,    "n1_ioo1_gptr"},  // 41
    {N1::n1_ioo1_time,    "n1_ioo1_time"},  // 42
    {N1::n1_mcs23_fure,   "n1_mcs23_fure"}, // 43
    {N1::n1_mcs23_gptr,   "n1_mcs23_gptr"}, // 44
    {N1::n1_mcs23_time,   "n1_mcs23_time"}, // 45
    {N1::n1_repr,         "n1_repr"},       // 46
    {N1::n1_ioo0_repr,    "n1_ioo0_repr"},  // 47
    {N1::n1_ioo1_repr,    "n1_ioo1_repr"},  // 48
    {N1::n1_mcs23_repr,   "n1_mcs23_repr"}, // 49
    {INVALID_RING,         ""}, // 50 // for future.
    {INVALID_RING,         ""}, // 51 // for future.
    {INVALID_RING,         ""}, // 52 // for future.

    // Nest N2 Ring
    {N2::n2_fure,         "n2_fure"},       // 53
    {N2::n2_gptr,         "n2_gptr"},       // 54
    {N2::n2_time,         "n2_time"},       // 55
    {N2::n2_cxa1_fure,    "n2_cxa1_fure"},  // 56
    {N2::n2_cxa1_gptr,    "n2_cxa1_gptr"},  // 57
    {N2::n2_cxa1_time,    "n2_cxa1_time"},  // 58
    {N2::n2_repr,         "n2_repr"},       // 59
    {N2::n2_cxa1_repr,    "n2_cxa1_repr"},  // 60
    {INVALID_RING,         ""}, // 61 // for future.
    {INVALID_RING,         ""}, // 62 // for future.
    {INVALID_RING,         ""}, // 63 // for future.

    // Nest N3 Ring
    {N3::n3_fure,         "n3_fure"},       // 64
    {N3::n3_gptr,         "n3_gptr"},       // 65
    {N3::n3_time,         "n3_time"},       // 66
    {N3::n3_mcs01_fure,   "n3_mcs01_fure"}, // 67
    {N3::n3_mcs01_gptr,   "n3_mcs01_gptr"}, // 68
    {N3::n3_mcs01_time,   "n3_mcs01_time"}, // 69
    {N3::n3_repr,         "n3_repr"},       // 70
    {N3::n3_mcs01_repr,   "n3_mcs01_repr"}, // 71
    {INVALID_RING,        ""}, // 72 // for future.
    {INVALID_RING,        ""}, // 73 // for future.
    {INVALID_RING,        ""}, // 74 // for future.

    // XB Ring
    {XB::xb_fure,         "xb_fure"},      // 75
    {XB::xb_gptr,         "xb_gptr"},      // 76
    {XB::xb_time,         "xb_time"},      // 77
    {XB::xb_io0_fure,     "xb_io0_fure"},  // 78
    {XB::xb_io0_gptr,     "xb_io0_gptr"},  // 79
    {XB::xb_io0_time,     "xb_io0_time"},  // 80
    {XB::xb_io1_fure,     "xb_io1_fure"},  // 81
    {XB::xb_io1_gptr,     "xb_io1_gptr"},  // 82
    {XB::xb_io1_time,     "xb_io1_time"},  // 83
    {XB::xb_io2_fure,     "xb_io2_fure"},  // 84
    {XB::xb_io2_gptr,     "xb_io2_gptr"},  // 85
    {XB::xb_io2_time,     "xb_io2_time"},  // 86
    {XB::xb_pll_gptr,     "xb_pll_gptr"},  // 87
    {XB::xb_pll_other,    "xb_pll_other"}, // 88
    {XB::xb_pll_bndy,     "xb_pll_bndy"},  // 89
    {XB::xb_pll_bndy_bucket_1, "xb_pll_bndy_bucket_1"}, // 90
    {XB::xb_pll_bndy_bucket_2, "xb_pll_bndy_bucket_2"}, // 91
    {XB::xb_pll_bndy_bucket_3, "xb_pll_bndy_bucket_3"}, // 92
    {XB::xb_pll_bndy_bucket_4, "xb_pll_bndy_bucket_4"}, // 93
    {XB::xb_pll_bndy_bucket_5, "xb_pll_bndy_bucket_5"}, // 94
    {XB::xb_repr,         "xb_repr"},     // 95
    {XB::xb_io0_repr,     "xb_io0_repr"}, // 96
    {XB::xb_io1_repr,     "xb_io1_repr"}, // 97
    {XB::xb_io2_repr,     "xb_io2_repr"}, // 98
    {INVALID_RING,        ""}, // 99  // for future.
    {INVALID_RING,        ""}, // 100 // for future.

    // MC Ring
    {MC::mc_fure,         "mc_fure"},       // 101
    {MC::mc_gptr,         "mc_gptr"},       // 102
    {MC::mc_time,         "mc_time"},       // 103
    {MC::mc_iom01_fure,   "mc_iom01_fure"}, // 104
    {MC::mc_iom01_gptr,   "mc_iom01_gptr"}, // 105
    {MC::mc_iom01_time,   "mc_iom01_time"}, // 106
    {MC::mc_iom23_fure,   "mc_iom23_fure"}, // 107
    {MC::mc_iom23_gptr,   "mc_iom23_gptr"}, // 108
    {MC::mc_iom23_time,   "mc_iom23_time"}, // 119
    {MC::mc_pll_gptr,     "mc_pll_gptr"},   // 110
    {MC::mc_pll_other,    "mc_pll_other"},  // 111
    {MC::mc_pll_bndy,     "mc_pll_bndy"},   // 112
    {MC::mc_pll_bndy_bucket_1, "mc_pll_bndy_bucket_1"}, // 113
    {MC::mc_pll_bndy_bucket_2, "mc_pll_bndy_bucket_2"}, // 114
    {MC::mc_pll_bndy_bucket_3, "mc_pll_bndy_bucket_3"}, // 115
    {MC::mc_pll_bndy_bucket_4, "mc_pll_bndy_bucket_4"}, // 116
    {MC::mc_pll_bndy_bucket_5, "mc_pll_bndy_bucket_5"}, // 117
    {MC::mc_repr,         "mc_repr"},       // 118
    {MC::mc_iom01_repr,   "mc_iom01_repr"}, // 119
    {MC::mc_iom23_repr,   "mc_iom23_repr"}, // 120
    {INVALID_RING,        ""}, // 121 // for future.
    {INVALID_RING,        ""}, // 122 // for future.
    {INVALID_RING,        ""}, // 123 // for future.

    // OB Ring
    {OB::ob_fure,         "ob_fure"},  // 124
    {OB::ob_gptr,         "ob_gptr"},  // 125
    {OB::ob_time,         "ob_time"},  // 126
    {OB::ob_pll_gptr,     "ob_pll_gptr"},      // 127
    {OB::ob_pll_other,    "ob_pll_other"},     // 128
    {OB::ob_pll_bndy,     "ob_pll_bndy"},      // 129
    {OB::ob_pll_bndy_bucket_1, "ob_pll_bndy_bucket_1"}, // 130
    {OB::ob_pll_bndy_bucket_2, "ob_pll_bndy_bucket_2"}, // 131
    {OB::ob_pll_bndy_bucket_3, "ob_pll_bndy_bucket_3"}, // 132
    {OB::ob_pll_bndy_bucket_4, "ob_pll_bndy_bucket_4"}, // 133
    {OB::ob_pll_bndy_bucket_5, "ob_pll_bndy_bucket_5"}, // 134
    {OB::ob_repr,         "ob_repr"},          // 135
    {INVALID_RING,        ""}, // 136 // for future.
    {INVALID_RING,        ""}, // 137 // for future.

    // PCI0 Ring
    {PCI0::pci0_fure,     "pci0_fure"}, // 138
    {PCI0::pci0_gptr,     "pci0_gptr"}, // 139
    {PCI0::pci0_time,     "pci0_time"}, // 140
    {PCI0::pci0_repr,     "pci0_repr"}, // 141
    // PCI1 Ring
    {PCI1::pci1_fure,     "pci1_fure"}, // 142
    {PCI1::pci1_gptr,     "pci1_gptr"}, // 143
    {PCI1::pci1_time,     "pci1_time"}, // 144
    {PCI1::pci1_repr,     "pci1_repr"}, // 145
    // PCI2 Ring
    {PCI2::pci2_fure,     "pci2_fure"}, // 146
    {PCI2::pci2_gptr,     "pci2_gptr"}, // 147
    {PCI2::pci2_time,     "pci2_time"}, // 148
    {PCI2::pci2_repr,     "pci2_repr"}, // 149
    {INVALID_RING,         ""}, // 150 // for future.
    {INVALID_RING,         ""}, // 151 // for future.
    {INVALID_RING,         ""}, // 152 // for future.

    // EQ Ring
    {EQ::eq_fure,         "eq_fure"},    // 153
    {EQ::eq_gptr,         "eq_gptr"},    // 154
    {EQ::eq_time,         "eq_time"},    // 155
    {EQ::ex_l3_fure,      "ex_l3_fure"}, // 156
    {EQ::ex_l3_gptr,      "ex_l3_gptr"}, // 157
    {EQ::ex_l3_time,      "ex_l3_time"}, // 158
    {EQ::ex_l2_fure,      "ex_l2_fure"}, // 159
    {EQ::ex_l2_gptr,      "ex_l2_gptr"}, // 160
    {EQ::ex_l2_time,      "ex_l2_time"}, // 161
    {EQ::ex_l3_refr_fure, "ex_l3_refr_fure"}, // 162
    {EQ::ex_l3_refr_gptr, "ex_l3_refr_gptr"}, // 163
    {EQ::ex_l3_refr_time, "ex_l3_refr_time"}, // 164
    {EQ::eq_ana_func,     "eq_ana_func"},     // 165
    {EQ::eq_ana_gptr,     "eq_ana_gptr"},     // 166
    {EQ::eq_dpll_func,    "eq_dpll_func"},    // 167
    {EQ::eq_dpll_gptr,    "eq_dpll_gptr"},    // 168
    {EQ::eq_dpll_other,   "eq_dpll_other"},   // 169
    {EQ::eq_repr,         "eq_repr"},    // 170
    {EQ::ex_l3_repr,      "ex_l3_repr"}, // 171
    {EQ::ex_l2_repr,      "ex_l2_repr"}, // 172
    {EQ::ex_l3_refr_repr, "ex_l3_refr_repr"}, // 173
    {EQ::eq_ana_bndy,     "eq_ana_bndy"}, // 174
    {INVALID_RING,        ""}, // 175 // for future.
    {INVALID_RING,        ""}, // 176 // for future.

    // Core Ring
    {EC::ec_func,         "ec_func"}, // 177
    {EC::ec_gptr,         "ec_gptr"}, // 178
    {EC::ec_time,         "ec_time"}, // 179
    {EC::ec_mode,         "ec_mode"}, // 180
    {EC::ec_repr,         "ec_repr"}  // 181
};
#endif


#ifdef __PPE__
static const ringProperties_t RING_PROPERTIES[P9_NUM_RINGS] =
{
    // Pervasive Ring
    {PERV::perv_fure,       PERV_TYPE},      // 0
    {PERV::perv_gptr,      PERV_TYPE},      // 1
    {PERV::perv_time,      PERV_TYPE},      // 2
    {PERV::occ_fure,       PERV_TYPE},       // 3
    {PERV::occ_gptr,       PERV_TYPE},       // 4
    {PERV::occ_time,       PERV_TYPE},       // 5
    {PERV::perv_ana_func,  PERV_TYPE},  // 6
    {PERV::perv_ana_gptr,  PERV_TYPE},  // 7
    {PERV::perv_pll_gptr,  PERV_TYPE},  // 8
    {PERV::perv_pll_bndy,  PERV_TYPE},  // 9
    {PERV::perv_pll_bndy_bucket_1, PERV_TYPE},  // 10
    {PERV::perv_pll_bndy_bucket_2, PERV_TYPE},  // 11
    {PERV::perv_pll_bndy_bucket_3, PERV_TYPE},  // 12
    {PERV::perv_pll_bndy_bucket_4, PERV_TYPE},  // 13
    {PERV::perv_pll_bndy_bucket_5, PERV_TYPE},  // 14
    {PERV::perv_repr,      PERV_TYPE},  // 15
    {PERV::occ_repr,       PERV_TYPE},   // 16
    {INVALID_RING,         PERV_TYPE}, // 17 // for future.
    {INVALID_RING,         PERV_TYPE}, // 18 // for future.

    // Nest N0 Ring
    {N0::n0_fure,         N0_TYPE},      // 19
    {N0::n0_gptr,         N0_TYPE},      // 20
    {N0::n0_time,         N0_TYPE},      // 21
    {N0::n0_nx_fure,      N0_TYPE},   // 22
    {N0::n0_nx_gptr,      N0_TYPE},   // 23
    {N0::n0_nx_time,      N0_TYPE},   // 24
    {N0::n0_cxa0_fure,    N0_TYPE}, // 25
    {N0::n0_cxa0_gptr,    N0_TYPE}, // 26
    {N0::n0_cxa0_time,    N0_TYPE}, // 27
    {N0::n0_repr,         N0_TYPE},      // 28
    {N0::n0_nx_repr,      N0_TYPE},   // 29
    {N0::n0_cxa0_repr,    N0_TYPE}, // 30
    {INVALID_RING,         N0_TYPE}, // 31 // for future.
    {INVALID_RING,         N0_TYPE}, // 32 // for future.
    {INVALID_RING,         N0_TYPE}, // 33 // for future.

    // Nest N1 Ring
    {N1::n1_fure,         N1_TYPE},       // 34
    {N1::n1_gptr,         N1_TYPE},       // 35
    {N1::n1_time,         N1_TYPE},       // 36
    {N1::n1_ioo0_fure,    N1_TYPE},  // 37
    {N1::n1_ioo0_gptr,    N1_TYPE},  // 38
    {N1::n1_ioo0_time,    N1_TYPE},  // 39
    {N1::n1_ioo1_fure,    N1_TYPE},  // 40
    {N1::n1_ioo1_gptr,    N1_TYPE},  // 41
    {N1::n1_ioo1_time,    N1_TYPE},  // 42
    {N1::n1_mcs23_fure,   N1_TYPE}, // 43
    {N1::n1_mcs23_gptr,   N1_TYPE}, // 44
    {N1::n1_mcs23_time,   N1_TYPE}, // 45
    {N1::n1_repr,         N1_TYPE},       // 46
    {N1::n1_ioo0_repr,    N1_TYPE},  // 47
    {N1::n1_ioo1_repr,    N1_TYPE},  // 48
    {N1::n1_mcs23_repr,   N1_TYPE}, // 49
    {INVALID_RING,         N1_TYPE}, // 50 // for future.
    {INVALID_RING,         N1_TYPE}, // 51 // for future.
    {INVALID_RING,         N1_TYPE}, // 52 // for future.

    // Nest N2 Ring
    {N2::n2_fure,         N2_TYPE},       // 53
    {N2::n2_gptr,         N2_TYPE},       // 54
    {N2::n2_time,         N2_TYPE},       // 55
    {N2::n2_cxa1_fure,    N2_TYPE},  // 56
    {N2::n2_cxa1_gptr,    N2_TYPE},  // 57
    {N2::n2_cxa1_time,    N2_TYPE},  // 58
    {N2::n2_repr,         N2_TYPE},       // 59
    {N2::n2_cxa1_repr,    N2_TYPE},  // 60
    {INVALID_RING,         N2_TYPE}, // 61 // for future.
    {INVALID_RING,         N2_TYPE}, // 62 // for future.
    {INVALID_RING,         N2_TYPE}, // 63 // for future.

    // Nest N3 Ring
    {N3::n3_fure,         N3_TYPE},       // 64
    {N3::n3_gptr,         N3_TYPE},       // 65
    {N3::n3_time,         N3_TYPE},       // 66
    {N3::n3_mcs01_fure,   N3_TYPE}, // 67
    {N3::n3_mcs01_gptr,   N3_TYPE}, // 68
    {N3::n3_mcs01_time,   N3_TYPE}, // 69
    {N3::n3_repr,         N3_TYPE},       // 70
    {N3::n3_mcs01_repr,   N3_TYPE}, // 71
    {INVALID_RING,        N3_TYPE}, // 72 // for future.
    {INVALID_RING,        N3_TYPE}, // 73 // for future.
    {INVALID_RING,        N3_TYPE}, // 74 // for future.

    // XB Ring
    {XB::xb_fure,         XB_TYPE},      // 75
    {XB::xb_gptr,         XB_TYPE},      // 76
    {XB::xb_time,         XB_TYPE},      // 77
    {XB::xb_io0_fure,     XB_TYPE},  // 78
    {XB::xb_io0_gptr,     XB_TYPE},  // 79
    {XB::xb_io0_time,     XB_TYPE},  // 80
    {XB::xb_io1_fure,     XB_TYPE},  // 81
    {XB::xb_io1_gptr,     XB_TYPE},  // 82
    {XB::xb_io1_time,     XB_TYPE},  // 83
    {XB::xb_io2_fure,     XB_TYPE},  // 84
    {XB::xb_io2_gptr,     XB_TYPE},  // 85
    {XB::xb_io2_time,     XB_TYPE},  // 86
    {XB::xb_pll_gptr,     XB_TYPE},  // 87
    {XB::xb_pll_other,    XB_TYPE}, // 88
    {XB::xb_pll_bndy,     XB_TYPE},  // 89
    {XB::xb_pll_bndy_bucket_1, XB_TYPE}, // 90
    {XB::xb_pll_bndy_bucket_2, XB_TYPE}, // 91
    {XB::xb_pll_bndy_bucket_3, XB_TYPE}, // 92
    {XB::xb_pll_bndy_bucket_4, XB_TYPE}, // 93
    {XB::xb_pll_bndy_bucket_5, XB_TYPE}, // 94
    {XB::xb_repr,         XB_TYPE},     // 95
    {XB::xb_io0_repr,     XB_TYPE}, // 96
    {XB::xb_io1_repr,     XB_TYPE}, // 97
    {XB::xb_io2_repr,     XB_TYPE}, // 98
    {INVALID_RING,        XB_TYPE}, // 99  // for future.
    {INVALID_RING,        XB_TYPE}, // 100 // for future.

    // MC Ring
    {MC::mc_fure,         MC_TYPE},       // 101
    {MC::mc_gptr,         MC_TYPE},       // 102
    {MC::mc_time,         MC_TYPE},       // 103
    {MC::mc_iom01_fure,   MC_TYPE}, // 104
    {MC::mc_iom01_gptr,   MC_TYPE}, // 105
    {MC::mc_iom01_time,   MC_TYPE}, // 106
    {MC::mc_iom23_fure,   MC_TYPE}, // 107
    {MC::mc_iom23_gptr,   MC_TYPE}, // 108
    {MC::mc_iom23_time,   MC_TYPE}, // 119
    {MC::mc_pll_gptr,     MC_TYPE},   // 110
    {MC::mc_pll_other,    MC_TYPE},  // 111
    {MC::mc_pll_bndy,     MC_TYPE},   // 112
    {MC::mc_pll_bndy_bucket_1, MC_TYPE}, // 113
    {MC::mc_pll_bndy_bucket_2, MC_TYPE}, // 114
    {MC::mc_pll_bndy_bucket_3, MC_TYPE}, // 115
    {MC::mc_pll_bndy_bucket_4, MC_TYPE}, // 116
    {MC::mc_pll_bndy_bucket_5, MC_TYPE}, // 117
    {MC::mc_repr,         MC_TYPE},       // 118
    {MC::mc_iom01_repr,   MC_TYPE}, // 119
    {MC::mc_iom23_repr,   MC_TYPE}, // 120
    {INVALID_RING,        MC_TYPE}, // 121 // for future.
    {INVALID_RING,        MC_TYPE}, // 122 // for future.
    {INVALID_RING,        MC_TYPE}, // 123 // for future.

    // OB Ring
    {OB::ob_fure,         OB_TYPE},  // 124
    {OB::ob_gptr,         OB_TYPE},  // 125
    {OB::ob_time,         OB_TYPE},  // 126
    {OB::ob_pll_gptr,     OB_TYPE},      // 127
    {OB::ob_pll_other,    OB_TYPE},     // 128
    {OB::ob_pll_bndy,     OB_TYPE},      // 129
    {OB::ob_pll_bndy_bucket_1, OB_TYPE}, // 130
    {OB::ob_pll_bndy_bucket_2, OB_TYPE}, // 131
    {OB::ob_pll_bndy_bucket_3, OB_TYPE}, // 132
    {OB::ob_pll_bndy_bucket_4, OB_TYPE}, // 133
    {OB::ob_pll_bndy_bucket_5, OB_TYPE}, // 134
    {OB::ob_repr,         OB_TYPE},          // 135
    {INVALID_RING,        OB_TYPE}, // 136 // for future.
    {INVALID_RING,        OB_TYPE}, // 137 // for future.

    // PCI0 Ring
    {PCI0::pci0_fure,     PCI0_TYPE}, // 138
    {PCI0::pci0_gptr,     PCI0_TYPE}, // 139
    {PCI0::pci0_time,     PCI0_TYPE}, // 140
    {PCI0::pci0_repr,     PCI0_TYPE}, // 141
    // PCI1 Ring
    {PCI1::pci1_fure,     PCI1_TYPE}, // 142
    {PCI1::pci1_gptr,     PCI1_TYPE}, // 143
    {PCI1::pci1_time,     PCI1_TYPE}, // 144
    {PCI1::pci1_repr,     PCI1_TYPE}, // 145
    // PCI2 Ring
    {PCI2::pci2_fure,     PCI2_TYPE}, // 146
    {PCI2::pci2_gptr,     PCI2_TYPE}, // 147
    {PCI2::pci2_time,     PCI2_TYPE}, // 148
    {PCI2::pci2_repr,     PCI2_TYPE}, // 149
    {INVALID_RING,         PCI2_TYPE}, // 150 // for future.
    {INVALID_RING,         PCI2_TYPE}, // 151 // for future.
    {INVALID_RING,         PCI2_TYPE}, // 152 // for future.

    // EQ Ring
    {EQ::eq_fure,         EQ_TYPE},    // 153
    {EQ::eq_gptr,         EQ_TYPE},    // 154
    {EQ::eq_time,         EQ_TYPE},    // 155
    {EQ::ex_l3_fure,      EQ_TYPE}, // 156
    {EQ::ex_l3_gptr,      EQ_TYPE}, // 157
    {EQ::ex_l3_time,      EQ_TYPE}, // 158
    {EQ::ex_l2_fure,      EQ_TYPE}, // 159
    {EQ::ex_l2_gptr,      EQ_TYPE}, // 160
    {EQ::ex_l2_time,      EQ_TYPE}, // 161
    {EQ::ex_l3_refr_fure, EQ_TYPE}, // 162
    {EQ::ex_l3_refr_gptr, EQ_TYPE}, // 163
    {EQ::ex_l3_refr_time, EQ_TYPE}, // 164
    {EQ::eq_ana_func,     EQ_TYPE},     // 165
    {EQ::eq_ana_gptr,     EQ_TYPE},     // 166
    {EQ::eq_dpll_func,    EQ_TYPE},    // 167
    {EQ::eq_dpll_gptr,    EQ_TYPE},    // 168
    {EQ::eq_dpll_other,   EQ_TYPE},   // 169
    {EQ::eq_repr,         EQ_TYPE},    // 170
    {EQ::ex_l3_repr,      EQ_TYPE}, // 171
    {EQ::ex_l2_repr,      EQ_TYPE}, // 172
    {EQ::ex_l3_refr_repr, EQ_TYPE}, // 173
    {EQ::eq_ana_bndy,     EQ_TYPE}, // 174
    {INVALID_RING,        EQ_TYPE}, // 175 // for future.
    {INVALID_RING,        EQ_TYPE}, // 176 // for future.

    // Core Ring
    {EC::ec_func,         EC_TYPE}, // 177
    {EC::ec_gptr,         EC_TYPE}, // 178
    {EC::ec_time,         EC_TYPE}, // 179
    {EC::ec_mode,         EC_TYPE}, // 180
    {EC::ec_repr,         EC_TYPE}  // 181
};
#endif
#endif
