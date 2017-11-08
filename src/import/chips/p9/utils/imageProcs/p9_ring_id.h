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
#ifndef _P9_RING_ID_H_
#define _P9_RING_ID_H_

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
    perv_fure = 0, //0x00
    perv_gptr = 1, //0x01
    perv_time = 2, //0x02
    occ_fure = 3, //0x03
    occ_gptr = 4, //0x04
    occ_time = 5, //0x05
    perv_ana_func = 6, //0x06
    perv_ana_gptr = 7, //0x07
    perv_pll_gptr = 8, //0x08
    perv_pll_bndy = 9, //0x09
    perv_pll_bndy_bucket_1 = 10, //0x0A
    perv_pll_bndy_bucket_2 = 11, //0x0B
    perv_pll_bndy_bucket_3 = 12, //0x0C
    perv_pll_bndy_bucket_4 = 13, //0x0D
    perv_pll_bndy_bucket_5 = 14, //0x0E
    perv_pll_func = 15, //0x0F
    perv_repr = 16, //0x10
    occ_repr = 17, //0x11
    // values 18-20 unused

    // Nest Chiplet Rings - N0
    n0_fure = 21, //0x15
    n0_gptr = 22, //0x16
    n0_time = 23, //0x17
    n0_nx_fure = 24, //0x18
    n0_nx_gptr = 25, //0x19
    n0_nx_time = 26, //0x1A
    n0_cxa0_fure = 27, //0x1B
    n0_cxa0_gptr = 28, //0x1C
    n0_cxa0_time = 29, //0x1D
    n0_repr = 30, //0x1E
    n0_nx_repr = 31, //0x1F
    n0_cxa0_repr = 32, //0x20

    // Nest Chiplet Rings - N1
    n1_fure = 33, //0x21
    n1_gptr = 34, //0x22
    n1_time = 35, //0x23
    n1_ioo0_fure = 36, //0x24
    n1_ioo0_gptr = 37, //0x25
    n1_ioo0_time = 38, //0x26
    n1_ioo1_fure = 39, //0x27
    n1_ioo1_gptr = 40, //0x28
    n1_ioo1_time = 41, //0x29
    n1_mcs23_fure = 42, //0x2A
    n1_mcs23_gptr = 43, //0x2B
    n1_mcs23_time = 44, //0x2C
    n1_repr = 45, //0x2D
    n1_ioo0_repr = 46, //0x2E
    n1_ioo1_repr = 47, //0x2F
    n1_mcs23_repr = 48, //0x30

    // Nest Chiplet Rings - N2
    n2_fure = 49, //0x31
    n2_gptr = 50, //0x32
    n2_time = 51, //0x33
    n2_cxa1_fure = 52, //0x34
    n2_cxa1_gptr = 53, //0x35
    n2_cxa1_time = 54, //0x36
    n2_psi_fure = 55, //0x37
    n2_psi_gptr = 56, //0x38
    n2_psi_time = 57, //0x39
    n2_repr = 58, //0x3A
    n2_cxa1_repr = 59, //0x3B
    n2_psi_repr = 60, //0x3C
    // values 61 unused

    // Nest Chiplet Rings - N3
    n3_fure = 62, //0x3E
    n3_gptr = 63, //0x3F
    n3_time = 64, //0x40
    n3_mcs01_fure = 65, //0x41
    n3_mcs01_gptr = 66, //0x42
    n3_mcs01_time = 67, //0x43
    n3_np_fure = 68, //0x44
    n3_np_gptr = 69, //0x45
    n3_np_time = 70, //0x46
    n3_repr = 71, //0x47
    n3_mcs01_repr = 72, //0x48
    n3_np_repr = 73, //0x49
    n3_br_fure = 74, //0x4A

    // X-Bus Chiplet Rings
    // Common - apply to all instances of X-Bus
    xb_fure = 75, //0x4B
    xb_gptr = 76, //0x4C
    xb_time = 77, //0x4D
    xb_io0_fure = 78, //0x4E
    xb_io0_gptr = 79, //0x4F
    xb_io0_time = 80, //0x50
    xb_io1_fure = 81, //0x51
    xb_io1_gptr = 82, //0x52
    xb_io1_time = 83, //0x53
    xb_io2_fure = 84, //0x54
    xb_io2_gptr = 85, //0x55
    xb_io2_time = 86, //0x56
    xb_pll_gptr = 87, //0x57
    xb_pll_bndy  = 88, //0x58
    xb_pll_func = 89, //0x59

    // X-Bus Chiplet Rings
    // X0, X1 and X2 instance specific Rings
    xb_repr = 90, //0x5A
    xb_io0_repr = 91, //0x5B
    xb_io1_repr = 92, //0x5C
    xb_io2_repr = 93, //0x5D
    // values 94-95 unused

    // MC Chiplet Rings
    // Common - apply to all instances of MC
    mc_fure = 96, //0x60
    mc_gptr = 97, //0x61
    mc_time = 98, //0x62
    mc_iom01_fure = 99, //0x63
    mc_iom01_gptr = 100, //0x64
    mc_iom01_time = 101, //0x65
    mc_iom23_fure = 102, //0x66
    mc_iom23_gptr = 103, //0x67
    mc_iom23_time = 104, //0x68
    mc_pll_gptr = 105, //0x69
    mc_pll_bndy  = 106, //0x6A
    mc_pll_bndy_bucket_1 = 107, //0x6B
    mc_pll_bndy_bucket_2 = 108, //0x6C
    mc_pll_bndy_bucket_3 = 109, //0x6D
    mc_pll_bndy_bucket_4 = 110, //0x6E
    mc_pll_bndy_bucket_5 = 111, //0x6F
    mc_pll_func = 112, //0x70

    // MC Chiplet Rings
    // MC01 and MC23 instance specific Rings
    mc_repr = 113, //0x71
    mc_iom01_repr = 114, //0x72
    mc_iom23_repr = 115, //0x73

    // OB0 Chiplet Rings
    ob0_pll_bndy = 116, //0x74
    ob0_pll_bndy_bucket_1 = 117, //0x75
    ob0_pll_bndy_bucket_2 = 118, //0x76
    ob0_gptr = 119, //0x77
    ob0_time = 120, //0x78
    ob0_pll_gptr = 121, //0x79
    ob0_fure = 122, //0x7A
    ob0_pll_bndy_bucket_3 = 123, //0x7B

    // OB0 Chiplet instance specific Ring
    ob0_repr = 124, //0x7C

    // OB1 Chiplet Rings
    ob1_pll_bndy = 125, //0x7D
    ob1_pll_bndy_bucket_1 = 126, //0x7E
    ob1_pll_bndy_bucket_2 = 127, //0x7F
    ob1_gptr = 128, //0x80
    ob1_time = 129, //0x81
    ob1_pll_gptr = 130, //0x82
    ob1_fure = 131, //0x83
    ob1_pll_bndy_bucket_3 = 132, //0x84

    // OB1 Chiplet instance specific Ring
    ob1_repr = 133, //0x85

    // OB2 Chiplet Rings
    ob2_pll_bndy = 134, //0x86
    ob2_pll_bndy_bucket_1 = 135, //0x87
    ob2_pll_bndy_bucket_2 = 136, //0x88
    ob2_gptr = 137, //0x89
    ob2_time = 138, //0x8A
    ob2_pll_gptr = 139, //0x8B
    ob2_fure = 140, //0x8C
    ob2_pll_bndy_bucket_3 = 141, //0x8D

    // OB2 Chiplet instance specific Ring
    ob2_repr = 142, //0x8E

    // OB3 Chiplet Rings
    ob3_pll_bndy = 143, //0x8F
    ob3_pll_bndy_bucket_1 = 144, //0x90
    ob3_pll_bndy_bucket_2 = 145, //0x91
    ob3_gptr = 146, //0x92
    ob3_time = 147, //0x93
    ob3_pll_gptr = 148, //0x94
    ob3_fure = 149, //0x95
    ob3_pll_bndy_bucket_3 = 150, //0x96

    // OB3 Chiplet instance specific Rings
    ob3_repr = 151, //0x97

    // values 152-153 unused

    // PCI Chiplet Rings
    // PCI0 Common Rings
    pci0_fure = 154, //0x9A
    pci0_gptr = 155, //0x9B
    pci0_time = 156, //0x9C
    pci0_pll_bndy = 157, //0x9D
    pci0_pll_gptr = 158, //0x9E
    // Instance specific Rings
    pci0_repr = 159, //0x9F

    // PCI1 Common Rings
    pci1_fure = 160, //0xA0
    pci1_gptr = 161, //0xA1
    pci1_time = 162, //0xA2
    pci1_pll_bndy = 163, //0xA3
    pci1_pll_gptr = 164, //0xA4
    // Instance specific Rings
    pci1_repr = 165, //0xA5

    // PCI2 Common Rings
    pci2_fure = 166, //0xA6
    pci2_gptr = 167, //0xA7
    pci2_time = 168, //0xA8
    pci2_pll_bndy = 169, //0xA9
    pci2_pll_gptr = 170, //0xAA
    // Instance specific Rings
    pci2_repr = 171, //0xAB

    // Quad Chiplet Rings
    // Common - apply to all Quad instances
    eq_fure = 172, //0xAC
    eq_gptr = 173, //0xAD
    eq_time = 174, //0xAE
    eq_inex = 175, //0xAF
    ex_l3_fure = 176, //0xB0
    ex_l3_gptr = 177, //0xB1
    ex_l3_time = 178, //0xB2
    ex_l2_mode = 179, //0xB3
    ex_l2_fure = 180, //0xB4
    ex_l2_gptr = 181, //0xB5
    ex_l2_time = 182, //0xB6
    ex_l3_refr_fure = 183, //0xB7
    ex_l3_refr_gptr = 184, //0xB8
    ex_l3_refr_time = 185, //0xB9
    eq_ana_func = 186, //0xBA
    eq_ana_gptr = 187, //0xBB
    eq_dpll_func = 188, //0xBC
    eq_dpll_gptr = 189, //0xBD
    eq_dpll_mode = 190, //0xBE
    eq_ana_bndy = 191, //0xBF
    eq_ana_bndy_bucket_0 = 192, //0xC0
    eq_ana_bndy_bucket_1 = 193, //0xC1
    eq_ana_bndy_bucket_2 = 194, //0xC2
    eq_ana_bndy_bucket_3 = 195, //0xC3
    eq_ana_bndy_bucket_4 = 196, //0xC4
    eq_ana_bndy_bucket_5 = 197, //0xC5
    eq_ana_bndy_bucket_6 = 198, //0xC6
    eq_ana_bndy_bucket_7 = 199, //0xC7
    eq_ana_bndy_bucket_8 = 200, //0xC8
    eq_ana_bndy_bucket_9 = 201, //0xC9
    eq_ana_bndy_bucket_10 = 202, //0xCA
    eq_ana_bndy_bucket_11 = 203, //0xCB
    eq_ana_bndy_bucket_12 = 204, //0xCC
    eq_ana_bndy_bucket_13 = 205, //0xCD
    eq_ana_bndy_bucket_14 = 206, //0xCE
    eq_ana_bndy_bucket_15 = 207, //0xCF
    eq_ana_bndy_bucket_16 = 208, //0xD0
    eq_ana_bndy_bucket_17 = 209, //0xD1
    eq_ana_bndy_bucket_18 = 210, //0xD2
    eq_ana_bndy_bucket_19 = 211, //0xD3
    eq_ana_bndy_bucket_20 = 212, //0xD4
    eq_ana_bndy_bucket_21 = 213, //0xD5
    eq_ana_bndy_bucket_22 = 214, //0xD6
    eq_ana_bndy_bucket_23 = 215, //0xD7
    eq_ana_bndy_bucket_24 = 216, //0xD8
    eq_ana_bndy_bucket_25 = 217, //0xD9
    eq_ana_bndy_bucket_l3dcc = 218, //0xDA
    eq_ana_mode = 219, //0xDB

    // Quad Chiplet Rings
    // EQ0 - EQ5 instance specific Rings
    eq_repr = 220, //0xDC
    ex_l3_repr = 221, //0xDD
    ex_l2_repr = 222, //0xDE
    ex_l3_refr_repr = 223, //0xDF

    // Core Chiplet Rings
    // Common - apply to all Core instances
    ec_func = 224, //0xE0
    ec_gptr = 225, //0xE1
    ec_time = 226, //0xE2
    ec_mode = 227, //0xE3

    // Core Chiplet Rings
    // EC0 - EC23 instance specific Ring
    ec_repr = 228, //0xE4

    // Values 229-230 unused

    // Core Chiplet Rings
    // ABIST engine mode
    ec_abst = 231, //0xE7

    // Additional rings for Nimbus DD2
    eq_ana_bndy_bucket_26 = 232, //0xE8
    eq_ana_bndy_bucket_27 = 233, //0xE9
    eq_ana_bndy_bucket_28 = 234, //0xEA
    eq_ana_bndy_bucket_29 = 235, //0xEB
    eq_ana_bndy_bucket_30 = 236, //0xEC
    eq_ana_bndy_bucket_31 = 237, //0xED
    eq_ana_bndy_bucket_32 = 238, //0xEE
    eq_ana_bndy_bucket_33 = 239, //0xEF
    eq_ana_bndy_bucket_34 = 240, //0xF0
    eq_ana_bndy_bucket_35 = 241, //0xF1
    eq_ana_bndy_bucket_36 = 242, //0xF2
    eq_ana_bndy_bucket_37 = 243, //0xF3
    eq_ana_bndy_bucket_38 = 244, //0xF4
    eq_ana_bndy_bucket_39 = 245, //0xF5
    eq_ana_bndy_bucket_40 = 246, //0xF6
    eq_ana_bndy_bucket_41 = 247, //0xF7

    //EQ Inex ring bucket
    eq_inex_bucket_1      = 248, //0xF8
    eq_inex_bucket_2      = 249, //0xF9
    eq_inex_bucket_3      = 250, //0xFA
    eq_inex_bucket_4      = 251, //0xFB

    // CMSK ring
    ec_cmsk = 252, //0xFC

    // Perv PLL filter override rings
    perv_pll_bndy_flt_1   = 253, //0xFD
    perv_pll_bndy_flt_2   = 254, //0xFE
    perv_pll_bndy_flt_3   = 255, //0xFF
    perv_pll_bndy_flt_4   = 256, //0x100

    //***************************
    // Rings needed for SBE - End
    //***************************

    NUM_RING_IDS

}; // enum RingID

#endif  // _P9_RING_ID_H_
