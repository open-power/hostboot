/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/p9_ringId.H $                                  */
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
/// @file p9_ringId.H
/// @brief This file will have all the constants and structures used to scan
///        a Ring.

#ifndef _P9_RINGID_H_
#define _P9_RINGID_H_

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
    PERV_FURE = 0,
    PERV_GPTR = 1,
    PERV_TIME = 2,
    OCC_FURE = 3,
    OCC_GPTR = 4,
    OCC_TIME = 5,
    PERV_ANA_FUNC = 6,
    PERV_ANA_GPTR = 7,
    PERV_PLL_GPTR = 8,
    PERV_PLL_FUNC = 9,
    // values 10-13 might be needed for
    // the remaining 4 PLL buckets
    PERV_REPR = 14,
    OCC_REPR = 15,
    // values 16-18 unused

    // Nest Chiplet Rings - N0
    N0_FURE = 19,
    N0_GPTR = 20,
    N0_TIME = 21,
    N0_NX_FURE = 22,
    N0_NX_GPTR = 23,
    N0_NX_TIME = 24,
    N0_CXA0_FURE = 25,
    N0_CXA0_GPTR = 26,
    N0_CXA0_TIME = 27,
    N0_REPR = 28,
    N0_NX_REPR = 29,
    N0_CXA0_REPR = 30,
    // values 31-33 unused

    // Nest Chiplet Rings - N1
    N1_FURE = 34,
    N1_GPTR = 35,
    N1_TIME = 36,
    N1_IOO0_FURE = 37,
    N1_IOO0_GPTR = 38,
    N1_IOO0_TIME = 39,
    N1_IOO1_FURE = 40,
    N1_IOO1_GPTR = 41,
    N1_IOO1_TIME = 42,
    N1_MCS23_FURE = 43,
    N1_MCS23_GPTR = 44,
    N1_MCS23_TIME = 45,
    N1_REPR = 46,
    N1_IOO0_REPR = 47,
    N1_IOO1_REPR = 48,
    N1_MCS23_REPR = 49,
    // values 50-52 unused

    // Nest Chiplet Rings - N2
    N2_FURE = 53,
    N2_GPTR = 54,
    N2_TIME = 55,
    N2_CXA1_FURE = 56,
    N2_CXA1_GPTR = 57,
    N2_CXA1_TIME = 58,
    N2_REPR = 59,
    N2_CXA1_REPR = 60,
    // values 61-63 unused

    // Nest Chiplet Rings - N3
    N3_FURE = 64,
    N3_GPTR = 65,
    N3_TIME = 66,
    N3_MCS01_FURE = 67,
    N3_MCS01_GPTR = 68,
    N3_MCS01_TIME = 69,
    N3_REPR = 70,
    N3_MCS01_REPR = 71,
    // values 72-74 unused

    // X-Bus Chiplet Rings
    // Common - apply to all instances of X-Bus
    XB_FURE = 75,
    XB_GPTR = 76,
    XB_TIME = 77,
    XB_IO0_FURE = 78,
    XB_IO0_GPTR = 79,
    XB_IO0_TIME = 80,
    XB_IO1_FURE = 81,
    XB_IO1_GPTR = 82,
    XB_IO1_TIME = 83,
    XB_IO2_FURE = 84,
    XB_IO2_GPTR = 85,
    XB_IO2_TIME = 86,
    XB_PLL_GPTR = 87,
    XB_PLL_OTHER = 88,
    XB_PLL_FUNC = 89,
    // values 90-93 might be needed for
    // the remaining 4 PLL buckets

    // X-Bus Chiplet Rings
    // X0, X1 and X2 instance specific Rings
    XB_REPR = 94,
    XB_IO0_REPR = 95,
    XB_IO1_REPR = 96,
    XB_IO2_REPR = 97,
    // values 98-100 unused

    // MC Chiplet Rings
    // Common - apply to all instances of MC
    MC_FURE = 101,
    MC_GPTR = 102,
    MC_TIME = 103,
    MC_IOM01_FURE = 104,
    MC_IOM01_GPTR = 105,
    MC_IOM01_TIME = 106,
    MC_IOM23_FURE = 107,
    MC_IOM23_GPTR = 108,
    MC_IOM23_TIME = 109,
    MC_PLL_GPTR = 110,
    MC_PLL_OTHER = 111,
    MC_PLL_FUNC_BUCKET_1 = 112,
    MC_PLL_FUNC_BUCKET_2 = 113,
    MC_PLL_FUNC_BUCKET_3 = 114,
    MC_PLL_FUNC_BUCKET_4 = 115,
    MC_PLL_FUNC_BUCKET_5 = 116,

    // MC Chiplet Rings
    // MC01 and MC23 instance specific Rings
    MC_REPR = 117,
    MC_IOM01_REPR = 118,
    MC_IOM23_REPR = 119,
    // values 120-122 unused

    // OB Chiplet Rings
    // Common - apply to all instances of O-Bus
    OB_FURE = 123,
    OB_GPTR = 124,
    OB_TIME = 125,
    OB_PLL_GPTR = 126,
    OB_PLL_OTHER = 127,
    OB_PLL_FUNC = 128,
    // values 129-132 might be needed for
    // the remaining 4 PLL buckets

    // OB Chiplet Rings
    // OB0, OB1, OB2 and OB3 instance specific Ring
    OB_REPR = 133,
    // values 134-136 unused

    // PCI Chiplet Rings
    // PCI0 Common Rings
    PCI0_FURE = 137,
    PCI0_GPTR = 138,
    PCI0_TIME = 139,
    // Instance specific Rings
    PCI0_REPR = 140,

    // PCI1 Common Rings
    PCI1_FURE = 141,
    PCI1_GPTR = 142,
    PCI1_TIME = 143,
    // Instance specific Rings
    PCI1_REPR = 144,

    // PCI2 Common Rings
    PCI2_FURE = 145,
    PCI2_GPTR = 146,
    PCI2_TIME = 147,
    // Instance specific Rings
    PCI2_REPR = 148,
    // vlaues 149-151 unused

    // Quad Chiplet Rings
    // Common - apply to all Quad instances
    EQ_FURE = 152,
    EQ_GPTR = 153,
    EQ_TIME = 154,
    EX_L3_FURE = 155,
    EX_L3_GPTR = 156,
    EX_L3_TIME = 157,
    EX_L2_FURE = 158,
    EX_L2_GPTR = 159,
    EX_L2_TIME = 160,
    EX_L3_REFR_FURE = 161,
    EX_L3_REFR_GPTR = 162,
    EX_L3_REFR_TIME = 163,
    EQ_ANA_FUNC = 164,
    EQ_ANA_GPTR = 165,
    EQ_DPLL_FUNC = 166,
    EQ_DPLL_GPTR = 167,
    EQ_DPLL_OTHER = 168,

    // Quad Chiplet Rings
    // EQ0 - EQ5 instance specific Rings
    EQ_REPR = 169,
    EX_L3_REPR = 170,
    EX_L2_REPR = 171,
    EX_L3_REFR_REPR = 172,
    // values 173-175 unused

    // Core Chiplet Rings
    // Common - apply to all Core instances
    EC_FUNC = 176,
    EC_GPTR = 177,
    EC_TIME = 178,

    // Core Chiplet Rings
    // EC0 - EC23 instance specific Ring
    EC_REPR = 179,
    //***************************
    // Rings needed for SBE - End
    //***************************

    NUM_RINGS // This shoud always be the last constant
}; // end of enum RingID

#endif
