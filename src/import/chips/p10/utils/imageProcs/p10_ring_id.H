/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ring_id.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
#ifndef _P10_RING_ID_H_
#define _P10_RING_ID_H_

///
/// @enum RingID
/// @brief Master enumeration of all conceivable Ring ID values. These values
///        are used everywhere in Infrastructure codes, ifCompiler,
///        HWPs, Cronus, ipl_customize and ipl_image_tool.

enum RingID
{
    // PERV Chiplet Rings
    perv_fure                = 0, //0x00
    perv_occ_gptr            = 1, //0x01
    perv_occ_repr            = 2, //0x02
    perv_occ_time            = 3, //0x03
    sbe_fure                 = 4, //0x04
    sbe_gptr                 = 5, //0x05
    sbe_repr                 = 6, //0x06
    sbe_time                 = 7, //0x07
    occ_fure                 = 8, //0x08
    perv_dpll_func           = 9, //0x09
    perv_dpll_bndy           = 10, //0x0A
    perv_dpll_gptr           = 11, //0x0B
    perv_pll_func            = 12, //0x0C
    perv_pll_bndy            = 13, //0x0D
    perv_pll_gptr            = 14, //0x0E

    // N0 Chiplet Rings
    n0_fure                  = 15, //0x0F
    n0_gptr                  = 16, //0x10
    n0_repr                  = 17, //0x11
    n0_time                  = 18, //0x12

    // N1 Chiplet Rings
    n1_fure                  = 19, //0x13
    n1_gptr                  = 20, //0x14
    n1_repr                  = 21, //0x15
    n1_time                  = 22, //0x16
    n1_nmmu1_fure            = 23, //0x17
    n1_nmmu1_gptr            = 24, //0x18
    n1_nmmu1_repr            = 25, //0x19
    n1_nmmu1_time            = 26, //0x1A

    // PCI Chiplet Rings
    pci_fure                 = 27, //0x1B
    pci_gptr                 = 28, //0x1C
    pci_repr                 = 29, //0x1D
    pci_time                 = 30, //0x1E
    pci_pll_func             = 31, //0x1F
    pci_pll_bndy             = 32, //0x20
    pci_pll_gptr             = 33, //0x21

    // MC Chiplet Rings
    mc_fure                  = 34, //0x22
    mc_gptr                  = 35, //0x23
    mc_repr                  = 36, //0x24
    mc_time                  = 37, //0x25
    mc_pll_func              = 38, //0x26
    mc_pll_bndy              = 39, //0x27
    mc_pll_bndy_bucket_0     = 40, //0x28
    mc_pll_bndy_bucket_1     = 41, //0x29
    mc_pll_bndy_bucket_2     = 42, //0x2A
    mc_pll_bndy_bucket_3     = 43, //0x2B
    mc_pll_bndy_bucket_4     = 44, //0x2C
    mc_pll_gptr              = 45, //0x2D

    // PAU0 Chiplet Rings
    pau0_fure                = 46, //0x2E
    pau0_gptr                = 47, //0x2F
    pau0_repr                = 48, //0x30
    pau0_time                = 49, //0x31
    pau0_pau0_fure           = 50, //0x32
    pau0_pau0_gptr           = 51, //0x33
    pau0_pau0_repr           = 52, //0x34
    pau0_pau0_time           = 53, //0x35

    // PAU1 Chiplet Rings
    pau1_fure                = 54, //0x36
    pau1_gptr                = 55, //0x37
    pau1_repr                = 56, //0x38
    pau1_time                = 57, //0x39
    pau1_pau3_fure           = 58, //0x3A
    pau1_pau3_gptr           = 59, //0x3B
    pau1_pau3_repr           = 60, //0x3C
    pau1_pau3_time           = 61, //0x3D

    // PAU2 Chiplet Rings
    pau2_fure                = 62, //0x3E
    pau2_gptr                = 63, //0x3F
    pau2_repr                = 64, //0x40
    pau2_time                = 65, //0x41
    pau2_pau4_fure           = 66, //0x42
    pau2_pau4_gptr           = 67, //0x43
    pau2_pau4_repr           = 68, //0x44
    pau2_pau4_time           = 69, //0x45
    pau2_pau5_fure           = 70, //0x46
    pau2_pau5_gptr           = 71, //0x47
    pau2_pau5_repr           = 72, //0x48
    pau2_pau5_time           = 73, //0x49

    // PAU3 Chiplet Rings
    pau3_fure                = 74, //0x4A
    pau3_gptr                = 75, //0x4B
    pau3_repr                = 76, //0x4C
    pau3_time                = 77, //0x4D
    pau3_pau6_fure           = 78, //0x4E
    pau3_pau6_gptr           = 79, //0x4F
    pau3_pau6_repr           = 80, //0x50
    pau3_pau6_time           = 81, //0x51
    pau3_pau7_fure           = 82, //0x52
    pau3_pau7_gptr           = 83, //0x53
    pau3_pau7_repr           = 84, //0x54
    pau3_pau7_time           = 85, //0x55

    // AXON0 Chiplet Rings
    iohs0_fure               = 86, //0x56
    iohs0_gptr               = 87, //0x57
    iohs0_repr               = 88, //0x58
    iohs0_time               = 89, //0x59
    iohs0_ndl_fure           = 90, //0x5A
    iohs0_ndl_gptr           = 91, //0x5B
    iohs0_ndl_repr           = 92, //0x5C
    iohs0_ndl_time           = 93, //0x5D
    iohs0_pdl_fure           = 94, //0x5E
    iohs0_pdl_gptr           = 95, //0x5F
    iohs0_pdl_repr           = 96, //0x60
    iohs0_pdl_time           = 97, //0x61
    iohs0_pll_func           = 98, //0x62
    iohs0_pll_bndy           = 99, //0x63
    iohs0_pll_bndy_bucket_0  = 100, //0x64
    iohs0_pll_bndy_bucket_1  = 101, //0x65
    iohs0_pll_bndy_bucket_2  = 102, //0x66
    iohs0_pll_bndy_bucket_3  = 103, //0x67
    iohs0_pll_bndy_bucket_4  = 104, //0x68
    iohs0_pll_bndy_bucket_5  = 105, //0x69
    iohs0_pll_bndy_bucket_6  = 106, //0x6A
    iohs0_pll_bndy_bucket_7  = 107, //0x6B
    iohs0_pll_gptr           = 108, //0x6C

    // AXON1 Chiplet Rings
    iohs1_fure               = 109, //0x6D
    iohs1_gptr               = 110, //0x6E
    iohs1_repr               = 111, //0x6F
    iohs1_time               = 112, //0x70
    iohs1_ndl_fure           = 113, //0x71
    iohs1_ndl_gptr           = 114, //0x72
    iohs1_ndl_repr           = 115, //0x73
    iohs1_ndl_time           = 116, //0x74
    iohs1_pdl_fure           = 117, //0x75
    iohs1_pdl_gptr           = 118, //0x76
    iohs1_pdl_repr           = 119, //0x77
    iohs1_pdl_time           = 120, //0x78
    iohs1_pll_func           = 121, //0x79
    iohs1_pll_bndy           = 122, //0x7A
    iohs1_pll_bndy_bucket_0  = 123, //0x7B
    iohs1_pll_bndy_bucket_1  = 124, //0x7C
    iohs1_pll_bndy_bucket_2  = 125, //0x7D
    iohs1_pll_bndy_bucket_3  = 126, //0x7E
    iohs1_pll_bndy_bucket_4  = 127, //0x7F
    iohs1_pll_bndy_bucket_5  = 128, //0x80
    iohs1_pll_bndy_bucket_6  = 129, //0x81
    iohs1_pll_bndy_bucket_7  = 130, //0x82
    iohs1_pll_gptr           = 131, //0x83

    // AXON2 Chiplet Rings
    iohs2_fure               = 132, //0x84
    iohs2_gptr               = 133, //0x85
    iohs2_repr               = 134, //0x86
    iohs2_time               = 135, //0x87
    iohs2_ndl_fure           = 136, //0x88
    iohs2_ndl_gptr           = 137, //0x89
    iohs2_ndl_repr           = 138, //0x8A
    iohs2_ndl_time           = 139, //0x8B
    iohs2_pdl_fure           = 140, //0x8C
    iohs2_pdl_gptr           = 141, //0x8D
    iohs2_pdl_repr           = 142, //0x8E
    iohs2_pdl_time           = 143, //0x8F
    iohs2_pll_func           = 144, //0x90
    iohs2_pll_bndy           = 145, //0x91
    iohs2_pll_bndy_bucket_0  = 146, //0x92
    iohs2_pll_bndy_bucket_1  = 147, //0x93
    iohs2_pll_bndy_bucket_2  = 148, //0x94
    iohs2_pll_bndy_bucket_3  = 149, //0x95
    iohs2_pll_bndy_bucket_4  = 150, //0x96
    iohs2_pll_bndy_bucket_5  = 151, //0x97
    iohs2_pll_bndy_bucket_6  = 152, //0x98
    iohs2_pll_bndy_bucket_7  = 153, //0x99
    iohs2_pll_gptr           = 154, //0x9A

    // AXON3 Chiplet Rings
    iohs3_fure               = 155, //0x9B
    iohs3_gptr               = 156, //0x9C
    iohs3_repr               = 157, //0x9D
    iohs3_time               = 158, //0x9E
    iohs3_ndl_fure           = 159, //0x9F
    iohs3_ndl_gptr           = 160, //0xA0
    iohs3_ndl_repr           = 161, //0xA1
    iohs3_ndl_time           = 162, //0xA2
    iohs3_pdl_fure           = 163, //0xA3
    iohs3_pdl_gptr           = 164, //0xA4
    iohs3_pdl_repr           = 165, //0xA5
    iohs3_pdl_time           = 166, //0xA6
    iohs3_pll_func           = 167, //0xA7
    iohs3_pll_bndy           = 168, //0xA8
    iohs3_pll_bndy_bucket_0  = 169, //0xA9
    iohs3_pll_bndy_bucket_1  = 170, //0xAA
    iohs3_pll_bndy_bucket_2  = 171, //0xAB
    iohs3_pll_bndy_bucket_3  = 172, //0xAC
    iohs3_pll_bndy_bucket_4  = 173, //0xAD
    iohs3_pll_bndy_bucket_5  = 174, //0xAE
    iohs3_pll_bndy_bucket_6  = 175, //0xAF
    iohs3_pll_bndy_bucket_7  = 176, //0xB0
    iohs3_pll_gptr           = 177, //0xB1

    // AXON4 Chiplet Rings
    iohs4_fure               = 178, //0xB2
    iohs4_gptr               = 179, //0xB3
    iohs4_repr               = 180, //0xB4
    iohs4_time               = 181, //0xB5
    iohs4_ndl_fure           = 182, //0xB6
    iohs4_ndl_gptr           = 183, //0xB7
    iohs4_ndl_repr           = 184, //0xB8
    iohs4_ndl_time           = 185, //0xB9
    iohs4_pdl_fure           = 186, //0xBA
    iohs4_pdl_gptr           = 187, //0xBB
    iohs4_pdl_repr           = 188, //0xBC
    iohs4_pdl_time           = 189, //0xBD
    iohs4_pll_func           = 190, //0xBE
    iohs4_pll_bndy           = 191, //0xBF
    iohs4_pll_bndy_bucket_0  = 192, //0xC0
    iohs4_pll_bndy_bucket_1  = 193, //0xC1
    iohs4_pll_bndy_bucket_2  = 194, //0xC2
    iohs4_pll_bndy_bucket_3  = 195, //0xC3
    iohs4_pll_bndy_bucket_4  = 196, //0xC4
    iohs4_pll_bndy_bucket_5  = 197, //0xC5
    iohs4_pll_bndy_bucket_6  = 198, //0xC6
    iohs4_pll_bndy_bucket_7  = 199, //0xC7
    iohs4_pll_gptr           = 200, //0xC8

    // AXON5 Chiplet Rings
    iohs5_fure               = 201, //0xC9
    iohs5_gptr               = 202, //0xCA
    iohs5_repr               = 203, //0xCB
    iohs5_time               = 204, //0xCC
    iohs5_ndl_fure           = 205, //0xCD
    iohs5_ndl_gptr           = 206, //0xCE
    iohs5_ndl_repr           = 207, //0xCF
    iohs5_ndl_time           = 208, //0xD0
    iohs5_pdl_fure           = 209, //0xD1
    iohs5_pdl_gptr           = 210, //0xD2
    iohs5_pdl_repr           = 211, //0xD3
    iohs5_pdl_time           = 212, //0xD4
    iohs5_pll_func           = 213, //0xD5
    iohs5_pll_bndy           = 214, //0xD6
    iohs5_pll_bndy_bucket_0  = 215, //0xD7
    iohs5_pll_bndy_bucket_1  = 216, //0xD8
    iohs5_pll_bndy_bucket_2  = 217, //0xD9
    iohs5_pll_bndy_bucket_3  = 218, //0xDA
    iohs5_pll_bndy_bucket_4  = 219, //0xDB
    iohs5_pll_bndy_bucket_5  = 220, //0xDC
    iohs5_pll_bndy_bucket_6  = 221, //0xDD
    iohs5_pll_bndy_bucket_7  = 222, //0xDE
    iohs5_pll_gptr           = 223, //0xDF

    // AXON6 Chiplet Rings
    iohs6_fure               = 224, //0xE0
    iohs6_gptr               = 225, //0xE1
    iohs6_repr               = 226, //0xE2
    iohs6_time               = 227, //0xE3
    iohs6_ndl_fure           = 228, //0xE4
    iohs6_ndl_gptr           = 229, //0xE5
    iohs6_ndl_repr           = 230, //0xE6
    iohs6_ndl_time           = 231, //0xE7
    iohs6_pdl_fure           = 232, //0xE8
    iohs6_pdl_gptr           = 233, //0xE9
    iohs6_pdl_repr           = 234, //0xEA
    iohs6_pdl_time           = 235, //0xEB
    iohs6_pll_func           = 236, //0xEC
    iohs6_pll_bndy           = 237, //0xED
    iohs6_pll_bndy_bucket_0  = 238, //0xEE
    iohs6_pll_bndy_bucket_1  = 239, //0xEF
    iohs6_pll_bndy_bucket_2  = 240, //0xF0
    iohs6_pll_bndy_bucket_3  = 241, //0xF1
    iohs6_pll_bndy_bucket_4  = 242, //0xF2
    iohs6_pll_bndy_bucket_5  = 243, //0xF3
    iohs6_pll_bndy_bucket_6  = 244, //0xF4
    iohs6_pll_bndy_bucket_7  = 245, //0xF5
    iohs6_pll_gptr           = 246, //0xF6

    // AXON7 Chiplet Rings
    iohs7_fure               = 247, //0xF7
    iohs7_gptr               = 248, //0xF8
    iohs7_repr               = 249, //0xF9
    iohs7_time               = 250, //0xFA
    iohs7_ndl_fure           = 251, //0xFB
    iohs7_ndl_gptr           = 252, //0xFC
    iohs7_ndl_repr           = 253, //0xFD
    iohs7_ndl_time           = 254, //0xFE
    iohs7_pdl_fure           = 255, //0xFF
    iohs7_pdl_gptr           = 256, //0x100
    iohs7_pdl_repr           = 257, //0x101
    iohs7_pdl_time           = 258, //0x102
    iohs7_pll_func           = 259, //0x103
    iohs7_pll_bndy           = 260, //0x104
    iohs7_pll_bndy_bucket_0  = 261, //0x105
    iohs7_pll_bndy_bucket_1  = 262, //0x106
    iohs7_pll_bndy_bucket_2  = 263, //0x107
    iohs7_pll_bndy_bucket_3  = 264, //0x108
    iohs7_pll_bndy_bucket_4  = 265, //0x109
    iohs7_pll_bndy_bucket_5  = 266, //0x10A
    iohs7_pll_bndy_bucket_6  = 267, //0x10B
    iohs7_pll_bndy_bucket_7  = 268, //0x10C
    iohs7_pll_gptr           = 269, //0x10D

    // EQ Chiplet Rings
    eq_fure                  = 270, //0x10E
    eq_gptr                  = 271, //0x10F
    eq_repr                  = 272, //0x110
    eq_time                  = 273, //0x111
    eq_cmsk                  = 274, //0x112
    eq_inex                  = 275, //0x113
    eq_mode                  = 276, //0x114
    ec_cl2_fure              = 277, //0x115
    ec_cl2_gptr              = 278, //0x116
    ec_cl2_repr              = 279, //0x117
    ec_cl2_time              = 280, //0x118
    ec_cl2_cmsk              = 281, //0x119
    ec_cl2_inex              = 282, //0x11A
    ec_cl2_mode              = 283, //0x11B
    ec1_cl2_repr             = 284, //0x11C
    ec2_cl2_repr             = 285, //0x11D
    ec3_cl2_repr             = 286, //0x11E
    ec_mma_fure              = 287, //0x11F
    ec_mma_gptr              = 288, //0x120
    ec_mma_repr              = 289, //0x121
    ec_mma_time              = 290, //0x122
    ec_mma_cmsk              = 291, //0x123
    ec_mma_inex              = 292, //0x124
    ec1_mma_repr             = 293, //0x125
    ec2_mma_repr             = 294, //0x126
    ec3_mma_repr             = 295, //0x127
    ec_l3_fure               = 296, //0x128
    ec_l3_gptr               = 297, //0x129
    ec_l3_repr               = 298, //0x12A
    ec_l3_time               = 299, //0x12B
    ec_l3_cmsk               = 300, //0x12C
    ec_l3_inex               = 301, //0x12D
    ec_l3_mode               = 302, //0x12E
    ec1_l3_repr              = 303, //0x12F
    ec2_l3_repr              = 304, //0x130
    ec3_l3_repr              = 305, //0x131

    NUM_RING_IDS
}; // enum RingID

#endif  // _P10_RING_ID_H_
