/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/utils/imageProcs/p10_ring_id.H $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
    // MVPD Rings:
    perv_occ_gptr            = 0, //0x00
    perv_occ_repr            = 1, //0x01
    perv_occ_time            = 2, //0x02
    pib_repr                 = 3, //0x03
    sbe_gptr                 = 4, //0x04
    sbe_repr                 = 5, //0x05
    sbe_time                 = 6, //0x06
    // hole_ring: 7, //0x07
    perv_dpll_gptr           = 8, //0x08
    perv_pll_gptr            = 9, //0x09
    n0_gptr                  = 10, //0x0A
    n0_repr                  = 11, //0x0B
    n0_time                  = 12, //0x0C
    n1_gptr                  = 13, //0x0D
    n1_repr                  = 14, //0x0E
    n1_time                  = 15, //0x0F
    n1_nmmu1_gptr            = 16, //0x10
    n1_nmmu1_repr            = 17, //0x11
    n1_nmmu1_time            = 18, //0x12
    pci_gptr                 = 19, //0x13
    pci_repr                 = 20, //0x14
    pci_time                 = 21, //0x15
    pci_pll_gptr             = 22, //0x16
    mc_gptr                  = 23, //0x17
    mc_repr                  = 24, //0x18
    mc_time                  = 25, //0x19
    mc_pll_gptr              = 26, //0x1A
    pau0_gptr                = 27, //0x1B
    pau0_repr                = 28, //0x1C
    pau0_time                = 29, //0x1D
    pau0_pau0_gptr           = 30, //0x1E
    pau0_pau0_repr           = 31, //0x1F
    pau0_pau0_time           = 32, //0x20
    pau1_gptr                = 33, //0x21
    pau1_repr                = 34, //0x22
    pau1_time                = 35, //0x23
    pau1_pau3_gptr           = 36, //0x24
    pau1_pau3_repr           = 37, //0x25
    pau1_pau3_time           = 38, //0x26
    pau2_gptr                = 39, //0x27
    pau2_repr                = 40, //0x28
    pau2_time                = 41, //0x29
    pau2_pau4_gptr           = 42, //0x2A
    pau2_pau4_repr           = 43, //0x2B
    pau2_pau4_time           = 44, //0x2C
    pau2_pau5_gptr           = 45, //0x2D
    pau2_pau5_repr           = 46, //0x2E
    pau2_pau5_time           = 47, //0x2F
    pau3_gptr                = 48, //0x30
    pau3_repr                = 49, //0x31
    pau3_time                = 50, //0x32
    pau3_pau6_gptr           = 51, //0x33
    pau3_pau6_repr           = 52, //0x34
    pau3_pau6_time           = 53, //0x35
    pau3_pau7_gptr           = 54, //0x36
    pau3_pau7_repr           = 55, //0x37
    pau3_pau7_time           = 56, //0x38
    iohs0_gptr               = 57, //0x39
    iohs0_repr               = 58, //0x3A
    iohs0_time               = 59, //0x3B
    iohs0_ndl_gptr           = 60, //0x3C
    iohs0_ndl_repr           = 61, //0x3D
    iohs0_ndl_time           = 62, //0x3E
    iohs0_pdl_gptr           = 63, //0x3F
    iohs0_pdl_repr           = 64, //0x40
    iohs0_pdl_time           = 65, //0x41
    iohs0_pll_gptr           = 66, //0x42
    iohs1_gptr               = 67, //0x43
    iohs1_repr               = 68, //0x44
    iohs1_time               = 69, //0x45
    iohs1_ndl_gptr           = 70, //0x46
    iohs1_ndl_repr           = 71, //0x47
    iohs1_ndl_time           = 72, //0x48
    iohs1_pdl_gptr           = 73, //0x49
    iohs1_pdl_repr           = 74, //0x4A
    iohs1_pdl_time           = 75, //0x4B
    iohs1_pll_gptr           = 76, //0x4C
    iohs2_gptr               = 77, //0x4D
    iohs2_repr               = 78, //0x4E
    iohs2_time               = 79, //0x4F
    iohs2_ndl_gptr           = 80, //0x50
    iohs2_ndl_repr           = 81, //0x51
    iohs2_ndl_time           = 82, //0x52
    iohs2_pdl_gptr           = 83, //0x53
    iohs2_pdl_repr           = 84, //0x54
    iohs2_pdl_time           = 85, //0x55
    iohs2_pll_gptr           = 86, //0x56
    iohs3_gptr               = 87, //0x57
    iohs3_repr               = 88, //0x58
    iohs3_time               = 89, //0x59
    iohs3_ndl_gptr           = 90, //0x5A
    iohs3_ndl_repr           = 91, //0x5B
    iohs3_ndl_time           = 92, //0x5C
    iohs3_pdl_gptr           = 93, //0x5D
    iohs3_pdl_repr           = 94, //0x5E
    iohs3_pdl_time           = 95, //0x5F
    iohs3_pll_gptr           = 96, //0x60
    iohs4_gptr               = 97, //0x61
    iohs4_repr               = 98, //0x62
    iohs4_time               = 99, //0x63
    iohs4_ndl_gptr           = 100, //0x64
    iohs4_ndl_repr           = 101, //0x65
    iohs4_ndl_time           = 102, //0x66
    iohs4_pdl_gptr           = 103, //0x67
    iohs4_pdl_repr           = 104, //0x68
    iohs4_pdl_time           = 105, //0x69
    iohs4_pll_gptr           = 106, //0x6A
    iohs5_gptr               = 107, //0x6B
    iohs5_repr               = 108, //0x6C
    iohs5_time               = 109, //0x6D
    iohs5_ndl_gptr           = 110, //0x6E
    iohs5_ndl_repr           = 111, //0x6F
    iohs5_ndl_time           = 112, //0x70
    iohs5_pdl_gptr           = 113, //0x71
    iohs5_pdl_repr           = 114, //0x72
    iohs5_pdl_time           = 115, //0x73
    iohs5_pll_gptr           = 116, //0x74
    iohs6_gptr               = 117, //0x75
    iohs6_repr               = 118, //0x76
    iohs6_time               = 119, //0x77
    iohs6_ndl_gptr           = 120, //0x78
    iohs6_ndl_repr           = 121, //0x79
    iohs6_ndl_time           = 122, //0x7A
    iohs6_pdl_gptr           = 123, //0x7B
    iohs6_pdl_repr           = 124, //0x7C
    iohs6_pdl_time           = 125, //0x7D
    iohs6_pll_gptr           = 126, //0x7E
    iohs7_gptr               = 127, //0x7F
    iohs7_repr               = 128, //0x80
    iohs7_time               = 129, //0x81
    iohs7_ndl_gptr           = 130, //0x82
    iohs7_ndl_repr           = 131, //0x83
    iohs7_ndl_time           = 132, //0x84
    iohs7_pdl_gptr           = 133, //0x85
    iohs7_pdl_repr           = 134, //0x86
    iohs7_pdl_time           = 135, //0x87
    iohs7_pll_gptr           = 136, //0x88
    eq_gptr                  = 137, //0x89
    eq_repr                  = 138, //0x8A
    eq_time                  = 139, //0x8B
    eq_clkadj_gptr           = 140, //0x8C
    eq_clkadj_repr           = 141, //0x8D
    eq_clkadj_time           = 142, //0x8E
    ec_cl2_gptr              = 143, //0x8F
    ec_cl2_repr              = 144, //0x90
    ec_cl2_time              = 145, //0x91
    ec1_cl2_repr             = 146, //0x92
    ec2_cl2_repr             = 147, //0x93
    ec3_cl2_repr             = 148, //0x94
    ec_mma_gptr              = 149, //0x95
    ec_mma_repr              = 150, //0x96
    ec_mma_time              = 151, //0x97
    ec1_mma_repr             = 152, //0x98
    ec2_mma_repr             = 153, //0x99
    ec3_mma_repr             = 154, //0x9A
    ec_l3_gptr               = 155, //0x9B
    ec_l3_repr               = 156, //0x9C
    ec_l3_time               = 157, //0x9D
    ec1_l3_repr              = 158, //0x9E
    ec2_l3_repr              = 159, //0x9F
    ec3_l3_repr              = 160, //0xA0
    n0_gptr_ovly             = 161, //0xA1
    n1_gptr_ovly             = 162, //0xA2
    pau0_gptr_ovly           = 163, //0xA3
    pau1_gptr_ovly           = 164, //0xA4
    pau2_gptr_ovly           = 165, //0xA5
    pau3_gptr_ovly           = 166, //0xA6
    eq_gptr_ovly             = 167, //0xA7
    NUM_RING_IDS_MVPD        = 168,

    // EKB Rings:
    perv_fure                = 256, //0x100
    sbe_fure                 = 257, //0x101
    occ_fure                 = 258, //0x102
    perv_dpll_func           = 259, //0x103
    perv_dpll_bndy           = 260, //0x104
    perv_dpll_time           = 261, //0x105
    perv_pll_func            = 262, //0x106
    perv_pll_bndy            = 263, //0x107
    n0_fure                  = 264, //0x108
    n1_fure                  = 265, //0x109
    n1_nmmu1_fure            = 266, //0x10A
    pci_fure                 = 267, //0x10B
    pci_pll_func             = 268, //0x10C
    pci_pll_bndy             = 269, //0x10D
    mc_fure                  = 270, //0x10E
    mc_pll_func              = 271, //0x10F
    mc_pll_bndy              = 272, //0x110
    mc_pll_bndy_bucket_0     = 273, //0x111
    mc_pll_bndy_bucket_1     = 274, //0x112
    mc_pll_bndy_bucket_2     = 275, //0x113
    mc_pll_bndy_bucket_3     = 276, //0x114
    mc_pll_bndy_bucket_4     = 277, //0x115
    pau0_fure                = 278, //0x116
    pau0_pau0_fure           = 279, //0x117
    pau1_fure                = 280, //0x118
    pau1_pau3_fure           = 281, //0x119
    pau2_fure                = 282, //0x11A
    pau2_pau4_fure           = 283, //0x11B
    pau2_pau5_fure           = 284, //0x11C
    pau3_fure                = 285, //0x11D
    pau3_pau6_fure           = 286, //0x11E
    pau3_pau7_fure           = 287, //0x11F
    iohs0_fure               = 288, //0x120
    iohs0_ndl_fure           = 289, //0x121
    iohs0_pdl_fure           = 290, //0x122
    iohs0_pll_func           = 291, //0x123
    iohs0_pll_bndy           = 292, //0x124
    iohs0_pll_bndy_bucket_0  = 293, //0x125
    iohs0_pll_bndy_bucket_1  = 294, //0x126
    iohs0_pll_bndy_bucket_2  = 295, //0x127
    iohs0_pll_bndy_bucket_3  = 296, //0x128
    iohs0_pll_bndy_bucket_4  = 297, //0x129
    iohs0_pll_bndy_bucket_5  = 298, //0x12A
    iohs0_pll_bndy_bucket_6  = 299, //0x12B
    iohs0_pll_bndy_bucket_7  = 300, //0x12C
    iohs1_fure               = 301, //0x12D
    iohs1_ndl_fure           = 302, //0x12E
    iohs1_pdl_fure           = 303, //0x12F
    iohs1_pll_func           = 304, //0x130
    iohs2_fure               = 305, //0x131
    iohs2_ndl_fure           = 306, //0x132
    iohs2_pdl_fure           = 307, //0x133
    iohs2_pll_func           = 308, //0x134
    iohs3_fure               = 309, //0x135
    iohs3_ndl_fure           = 310, //0x136
    iohs3_pdl_fure           = 311, //0x137
    iohs3_pll_func           = 312, //0x138
    iohs4_fure               = 313, //0x139
    iohs4_ndl_fure           = 314, //0x13A
    iohs4_pdl_fure           = 315, //0x13B
    iohs4_pll_func           = 316, //0x13C
    iohs5_fure               = 317, //0x13D
    iohs5_ndl_fure           = 318, //0x13E
    iohs5_pdl_fure           = 319, //0x13F
    iohs5_pll_func           = 320, //0x140
    iohs6_fure               = 321, //0x141
    iohs6_ndl_fure           = 322, //0x142
    iohs6_pdl_fure           = 323, //0x143
    iohs6_pll_func           = 324, //0x144
    iohs7_fure               = 325, //0x145
    iohs7_ndl_fure           = 326, //0x146
    iohs7_pdl_fure           = 327, //0x147
    iohs7_pll_func           = 328, //0x148
    eq_fure                  = 329, //0x149
    eq_cmsk                  = 330, //0x14A
    eq_inex                  = 331, //0x14B
    eq_mode                  = 332, //0x14C
    eq_clkadj_fure           = 333, //0x14D
    eq_clkadj_cmsk           = 334, //0x14E
    eq_clkadj_inex           = 335, //0x14F
    eq_clkadj_mode           = 336, //0x150
    ec_cl2_fure              = 337, //0x151
    ec_cl2_cmsk              = 338, //0x152
    ec_cl2_inex              = 339, //0x153
    ec_cl2_mode              = 340, //0x154
    ec_mma_fure              = 341, //0x155
    ec_mma_cmsk              = 342, //0x156
    ec_mma_inex              = 343, //0x157
    ec_l3_fure               = 344, //0x158
    ec_l3_cmsk               = 345, //0x159
    ec_l3_inex               = 346, //0x15A
    ec_l3_mode               = 347, //0x15B
    n0_abst                  = 348, //0x15C
    n1_abst                  = 349, //0x15D
    n1_nmmu1_abst            = 350, //0x15E
    ec_cl2_abst              = 351, //0x15F
    ec_mma_abst              = 352, //0x160
    NUM_RING_IDS_EKB         = 97,

    NUM_RING_IDS             = 265, // = NUM_RING_IDS_MVPD + NUM_RING_IDS_EKB
}; // enum RingID

#endif  // _P10_RING_ID_H_
