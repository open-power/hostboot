/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ring_id.h $           */
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
#ifndef _P9_RINGID_ENUM_H_
#define _P9_RINGID_ENUM_H_

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
    perv_pll_func = 15,
    perv_repr = 16,
    occ_repr = 17,
    // values 18-20 unused

    // Nest Chiplet Rings - N0
    n0_fure = 21,
    n0_gptr = 22,
    n0_time = 23,
    n0_nx_fure = 24,
    n0_nx_gptr = 25,
    n0_nx_time = 26,
    n0_cxa0_fure = 27,
    n0_cxa0_gptr = 28,
    n0_cxa0_time = 29,
    n0_repr = 30,
    n0_nx_repr = 31,
    n0_cxa0_repr = 32,

    // Nest Chiplet Rings - N1
    n1_fure = 33,
    n1_gptr = 34,
    n1_time = 35,
    n1_ioo0_fure = 36,
    n1_ioo0_gptr = 37,
    n1_ioo0_time = 38,
    n1_ioo1_fure = 39,
    n1_ioo1_gptr = 40,
    n1_ioo1_time = 41,
    n1_mcs23_fure = 42,
    n1_mcs23_gptr = 43,
    n1_mcs23_time = 44,
    n1_repr = 45,
    n1_ioo0_repr = 46,
    n1_ioo1_repr = 47,
    n1_mcs23_repr = 48,

    // Nest Chiplet Rings - N2
    n2_fure = 49,
    n2_gptr = 50,
    n2_time = 51,
    n2_cxa1_fure = 52,
    n2_cxa1_gptr = 53,
    n2_cxa1_time = 54,
    n2_psi_fure = 55,
    n2_psi_gptr = 56,
    n2_psi_time = 57,
    n2_repr = 58,
    n2_cxa1_repr = 59,
    n2_psi_repr = 60,
    // values 61 unused

    // Nest Chiplet Rings - N3
    n3_fure = 62,
    n3_gptr = 63,
    n3_time = 64,
    n3_mcs01_fure = 65,
    n3_mcs01_gptr = 66,
    n3_mcs01_time = 67,
    n3_np_fure = 68,
    n3_np_gptr = 69,
    n3_np_time = 70,
    n3_repr = 71,
    n3_mcs01_repr = 72,
    n3_np_repr = 73,
    n3_br_fure = 74,

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
    xb_pll_bndy  = 88,
    xb_pll_func = 89,

    // X-Bus Chiplet Rings
    // X0, X1 and X2 instance specific Rings
    xb_repr = 90,
    xb_io0_repr = 91,
    xb_io1_repr = 92,
    xb_io2_repr = 93,
    // values 94-95 unused

    // MC Chiplet Rings
    // Common - apply to all instances of MC
    mc_fure = 96,
    mc_gptr = 97,
    mc_time = 98,
    mc_iom01_fure = 99,
    mc_iom01_gptr = 100,
    mc_iom01_time = 101,
    mc_iom23_fure = 102,
    mc_iom23_gptr = 103,
    mc_iom23_time = 104,
    mc_pll_gptr = 105,
    mc_pll_bndy  = 106,
    mc_pll_bndy_bucket_1 = 107,
    mc_pll_bndy_bucket_2 = 108,
    mc_pll_bndy_bucket_3 = 109,
    mc_pll_bndy_bucket_4 = 110,
    mc_pll_bndy_bucket_5 = 111,
    mc_pll_func = 112,

    // MC Chiplet Rings
    // MC01 and MC23 instance specific Rings
    mc_repr = 113,
    mc_iom01_repr = 114,
    mc_iom23_repr = 115,

    // OB0 Chiplet Rings
    ob0_pll_bndy = 116,
    ob0_pll_bndy_bucket_1 = 117,
    ob0_pll_bndy_bucket_2 = 118,
    ob0_gptr = 119,
    ob0_time = 120,
    ob0_pll_gptr = 121,
    ob0_fure = 122,
    ob0_pll_bndy_bucket_3 = 123,

    // OB0 Chiplet instance specific Ring
    ob0_repr = 124,

    // OB1 Chiplet Rings
    ob1_pll_bndy = 125,
    ob1_pll_bndy_bucket_1 = 126,
    ob1_pll_bndy_bucket_2 = 127,
    ob1_gptr = 128,
    ob1_time = 129,
    ob1_pll_gptr = 130,
    ob1_fure = 131,
    ob1_pll_bndy_bucket_3 = 132,

    // OB1 Chiplet instance specific Ring
    ob1_repr = 133,

    // OB2 Chiplet Rings
    ob2_pll_bndy = 134,
    ob2_pll_bndy_bucket_1 = 135,
    ob2_pll_bndy_bucket_2 = 136,
    ob2_gptr = 137,
    ob2_time = 138,
    ob2_pll_gptr = 139,
    ob2_fure = 140,
    ob2_pll_bndy_bucket_3 = 141,

    // OB2 Chiplet instance specific Ring
    ob2_repr = 142,

    // OB3 Chiplet Rings
    ob3_pll_bndy = 143,
    ob3_pll_bndy_bucket_1 = 144,
    ob3_pll_bndy_bucket_2 = 145,
    ob3_gptr = 146,
    ob3_time = 147,
    ob3_pll_gptr = 148,
    ob3_fure = 149,
    ob3_pll_bndy_bucket_3 = 150,

    // OB3 Chiplet instance specific Rings
    ob3_repr = 151,

    // values 152-153 unused

    // PCI Chiplet Rings
    // PCI0 Common Rings
    pci0_fure = 154,
    pci0_gptr = 155,
    pci0_time = 156,
    pci0_pll_bndy = 157,
    pci0_pll_gptr = 158,
    // Instance specific Rings
    pci0_repr = 159,

    // PCI1 Common Rings
    pci1_fure = 160,
    pci1_gptr = 161,
    pci1_time = 162,
    pci1_pll_bndy = 163,
    pci1_pll_gptr = 164,
    // Instance specific Rings
    pci1_repr = 165,

    // PCI2 Common Rings
    pci2_fure = 166,
    pci2_gptr = 167,
    pci2_time = 168,
    pci2_pll_bndy = 169,
    pci2_pll_gptr = 170,
    // Instance specific Rings
    pci2_repr = 171,

    // Quad Chiplet Rings
    // Common - apply to all Quad instances
    eq_fure = 172,
    eq_gptr = 173,
    eq_time = 174,
    eq_inex = 175,
    ex_l3_fure = 176,
    ex_l3_gptr = 177,
    ex_l3_time = 178,
    ex_l2_mode = 179,
    ex_l2_fure = 180,
    ex_l2_gptr = 181,
    ex_l2_time = 182,
    ex_l3_refr_fure = 183,
    ex_l3_refr_gptr = 184,
    ex_l3_refr_time = 185,
    eq_ana_func = 186,
    eq_ana_gptr = 187,
    eq_dpll_func = 188,
    eq_dpll_gptr = 189,
    eq_dpll_mode = 190,
    eq_ana_bndy = 191,
    eq_ana_bndy_bucket_0 = 192,
    eq_ana_bndy_bucket_1 = 193,
    eq_ana_bndy_bucket_2 = 194,
    eq_ana_bndy_bucket_3 = 195,
    eq_ana_bndy_bucket_4 = 196,
    eq_ana_bndy_bucket_5 = 197,
    eq_ana_bndy_bucket_6 = 198,
    eq_ana_bndy_bucket_7 = 199,
    eq_ana_bndy_bucket_8 = 200,
    eq_ana_bndy_bucket_9 = 201,
    eq_ana_bndy_bucket_10 = 202,
    eq_ana_bndy_bucket_11 = 203,
    eq_ana_bndy_bucket_12 = 204,
    eq_ana_bndy_bucket_13 = 205,
    eq_ana_bndy_bucket_14 = 206,
    eq_ana_bndy_bucket_15 = 207,
    eq_ana_bndy_bucket_16 = 208,
    eq_ana_bndy_bucket_17 = 209,
    eq_ana_bndy_bucket_18 = 210,
    eq_ana_bndy_bucket_19 = 211,
    eq_ana_bndy_bucket_20 = 212,
    eq_ana_bndy_bucket_21 = 213,
    eq_ana_bndy_bucket_22 = 214,
    eq_ana_bndy_bucket_23 = 215,
    eq_ana_bndy_bucket_24 = 216,
    eq_ana_bndy_bucket_25 = 217,
    eq_ana_bndy_bucket_l3dcc = 218,
    eq_ana_mode = 219,

    // Quad Chiplet Rings
    // EQ0 - EQ5 instance specific Rings
    eq_repr = 220,
    ex_l3_repr = 221,
    ex_l2_repr = 222,
    ex_l3_refr_repr = 223,

    // Core Chiplet Rings
    // Common - apply to all Core instances
    ec_func = 224,
    ec_gptr = 225,
    ec_time = 226,
    ec_mode = 227,

    // Core Chiplet Rings
    // EC0 - EC23 instance specific Ring
    ec_repr = 228,

    // Values 229-230 unused

    // Core Chiplet Rings
    // ABIST engine mode
    ec_abst = 231,

    // Additional rings for Nimbus DD2
    eq_ana_bndy_bucket_26 = 232,
    eq_ana_bndy_bucket_27 = 233,
    eq_ana_bndy_bucket_28 = 234,
    eq_ana_bndy_bucket_29 = 235,
    eq_ana_bndy_bucket_30 = 236,
    eq_ana_bndy_bucket_31 = 237,
    eq_ana_bndy_bucket_32 = 238,
    eq_ana_bndy_bucket_33 = 239,
    eq_ana_bndy_bucket_34 = 240,
    eq_ana_bndy_bucket_35 = 241,
    eq_ana_bndy_bucket_36 = 242,
    eq_ana_bndy_bucket_37 = 243,
    eq_ana_bndy_bucket_38 = 244,
    eq_ana_bndy_bucket_39 = 245,
    eq_ana_bndy_bucket_40 = 246,
    eq_ana_bndy_bucket_41 = 247,

    //EQ Inex ring bucket
    eq_inex_bucket_1      = 248,
    eq_inex_bucket_2      = 249,
    eq_inex_bucket_3      = 250,
    eq_inex_bucket_4      = 251,

    // CMSK ring
    ec_cmsk = 252,

    //***************************
    // Rings needed for SBE - End
    //***************************

    NUM_RING_IDS // This shoud always be the last constant
}; // end of enum RingID

#endif  // _P9_RINGID_ENUM_H_
