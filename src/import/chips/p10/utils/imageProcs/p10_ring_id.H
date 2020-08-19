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
    // hole_ring: 5, //0x05
    // hole_ring: 6, //0x06
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
    // hole_ring: 60, //0x3C
    // hole_ring: 61, //0x3D
    // hole_ring: 62, //0x3E
    iohs0_pdl_gptr           = 63, //0x3F
    iohs0_pdl_repr           = 64, //0x40
    iohs0_pdl_time           = 65, //0x41
    iohs0_pll_gptr           = 66, //0x42
    iohs1_gptr               = 67, //0x43
    iohs1_repr               = 68, //0x44
    iohs1_time               = 69, //0x45
    // hole_ring: 70, //0x46
    // hole_ring: 71, //0x47
    // hole_ring: 72, //0x48
    iohs1_pdl_gptr           = 73, //0x49
    iohs1_pdl_repr           = 74, //0x4A
    iohs1_pdl_time           = 75, //0x4B
    iohs1_pll_gptr           = 76, //0x4C
    iohs2_gptr               = 77, //0x4D
    iohs2_repr               = 78, //0x4E
    iohs2_time               = 79, //0x4F
    // hole_ring: 80, //0x50
    // hole_ring: 81, //0x51
    // hole_ring: 82, //0x52
    iohs2_pdl_gptr           = 83, //0x53
    iohs2_pdl_repr           = 84, //0x54
    iohs2_pdl_time           = 85, //0x55
    iohs2_pll_gptr           = 86, //0x56
    iohs3_gptr               = 87, //0x57
    iohs3_repr               = 88, //0x58
    iohs3_time               = 89, //0x59
    // hole_ring: 90, //0x5A
    // hole_ring: 91, //0x5B
    // hole_ring: 92, //0x5C
    iohs3_pdl_gptr           = 93, //0x5D
    iohs3_pdl_repr           = 94, //0x5E
    iohs3_pdl_time           = 95, //0x5F
    iohs3_pll_gptr           = 96, //0x60
    iohs4_gptr               = 97, //0x61
    iohs4_repr               = 98, //0x62
    iohs4_time               = 99, //0x63
    // hole_ring: 100, //0x64
    // hole_ring: 101, //0x65
    // hole_ring: 102, //0x66
    iohs4_pdl_gptr           = 103, //0x67
    iohs4_pdl_repr           = 104, //0x68
    iohs4_pdl_time           = 105, //0x69
    iohs4_pll_gptr           = 106, //0x6A
    iohs5_gptr               = 107, //0x6B
    iohs5_repr               = 108, //0x6C
    iohs5_time               = 109, //0x6D
    // hole_ring: 110, //0x6E
    // hole_ring: 111, //0x6F
    // hole_ring: 112, //0x70
    iohs5_pdl_gptr           = 113, //0x71
    iohs5_pdl_repr           = 114, //0x72
    iohs5_pdl_time           = 115, //0x73
    iohs5_pll_gptr           = 116, //0x74
    iohs6_gptr               = 117, //0x75
    iohs6_repr               = 118, //0x76
    iohs6_time               = 119, //0x77
    // hole_ring: 120, //0x78
    // hole_ring: 121, //0x79
    // hole_ring: 122, //0x7A
    iohs6_pdl_gptr           = 123, //0x7B
    iohs6_pdl_repr           = 124, //0x7C
    iohs6_pdl_time           = 125, //0x7D
    iohs6_pll_gptr           = 126, //0x7E
    iohs7_gptr               = 127, //0x7F
    iohs7_repr               = 128, //0x80
    iohs7_time               = 129, //0x81
    // hole_ring: 130, //0x82
    // hole_ring: 131, //0x83
    // hole_ring: 132, //0x84
    iohs7_pdl_gptr           = 133, //0x85
    iohs7_pdl_repr           = 134, //0x86
    iohs7_pdl_time           = 135, //0x87
    iohs7_pll_gptr           = 136, //0x88
    eq_gptr                  = 137, //0x89
    eq_repr                  = 138, //0x8A
    eq_time                  = 139, //0x8B
    eq_clkadj_gptr           = 140, //0x8C
    // hole_ring: 141, //0x8D
    // hole_ring: 142, //0x8E
    ec_cl2_gptr              = 143, //0x8F
    ec_cl2_repr              = 144, //0x90
    ec_cl2_time              = 145, //0x91
    ec1_cl2_repr             = 146, //0x92
    ec2_cl2_repr             = 147, //0x93
    ec3_cl2_repr             = 148, //0x94
    ec_mma_gptr              = 149, //0x95
    // hole_ring: 150, //0x96
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
    // hole_ring: 256, //0x100
    // hole_ring: 257, //0x101
    // hole_ring: 258, //0x102
    perv_dpll_func           = 259, //0x103
    // hole_ring: 260, //0x104
    perv_dpll_time           = 261, //0x105
    perv_pll_func            = 262, //0x106
    perv_pll_bndy            = 263, //0x107
    // hole_ring: 264, //0x108
    // hole_ring: 265, //0x109
    // hole_ring: 266, //0x10A
    // hole_ring: 267, //0x10B
    pci_pll_func             = 268, //0x10C
    pci_pll_bndy             = 269, //0x10D
    // hole_ring: 270, //0x10E
    mc_pll_func              = 271, //0x10F
    mc_pll_bndy              = 272, //0x110
    mc_pll_bndy_bucket_0     = 273, //0x111
    mc_pll_bndy_bucket_1     = 274, //0x112
    mc_pll_bndy_bucket_2     = 275, //0x113
    mc_pll_bndy_bucket_3     = 276, //0x114
    mc_pll_bndy_bucket_4     = 277, //0x115
    // hole_ring: 278, //0x116
    // hole_ring: 279, //0x117
    // hole_ring: 280, //0x118
    // hole_ring: 281, //0x119
    // hole_ring: 282, //0x11A
    // hole_ring: 283, //0x11B
    // hole_ring: 284, //0x11C
    // hole_ring: 285, //0x11D
    // hole_ring: 286, //0x11E
    // hole_ring: 287, //0x11F
    // hole_ring: 288, //0x120
    // hole_ring: 289, //0x121
    // hole_ring: 290, //0x122
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
    // hole_ring: 301, //0x12D
    // hole_ring: 302, //0x12E
    // hole_ring: 303, //0x12F
    iohs1_pll_func           = 304, //0x130
    // hole_ring: 305, //0x131
    // hole_ring: 306, //0x132
    // hole_ring: 307, //0x133
    iohs2_pll_func           = 308, //0x134
    // hole_ring: 309, //0x135
    // hole_ring: 310, //0x136
    // hole_ring: 311, //0x137
    iohs3_pll_func           = 312, //0x138
    // hole_ring: 313, //0x139
    // hole_ring: 314, //0x13A
    // hole_ring: 315, //0x13B
    iohs4_pll_func           = 316, //0x13C
    // hole_ring: 317, //0x13D
    // hole_ring: 318, //0x13E
    // hole_ring: 319, //0x13F
    iohs5_pll_func           = 320, //0x140
    // hole_ring: 321, //0x141
    // hole_ring: 322, //0x142
    // hole_ring: 323, //0x143
    iohs6_pll_func           = 324, //0x144
    // hole_ring: 325, //0x145
    // hole_ring: 326, //0x146
    // hole_ring: 327, //0x147
    iohs7_pll_func           = 328, //0x148
    // hole_ring: 329, //0x149
    eq_cmsk                  = 330, //0x14A
    // hole_ring: 331, //0x14B
    eq_mode                  = 332, //0x14C
    // hole_ring: 333, //0x14D
    eq_clkadj_cmsk           = 334, //0x14E
    // hole_ring: 335, //0x14F
    // hole_ring: 336, //0x150
    // hole_ring: 337, //0x151
    ec_cl2_cmsk              = 338, //0x152
    ec_cl2_inex              = 339, //0x153
    ec_cl2_mode              = 340, //0x154
    // hole_ring: 341, //0x155
    ec_mma_cmsk              = 342, //0x156
    // hole_ring: 343, //0x157
    // hole_ring: 344, //0x158
    ec_l3_cmsk               = 345, //0x159
    ec_l3_inex               = 346, //0x15A
    // hole_ring: 347, //0x15B
    n0_abst                  = 348, //0x15C
    n1_abst                  = 349, //0x15D
    n1_nmmu1_abst            = 350, //0x15E
    ec_cl2_abst              = 351, //0x15F
    ec_mma_abst              = 352, //0x160
    perv_func                = 353, //0x161
    sbe_func                 = 354, //0x162
    occ_func                 = 355, //0x163
    perv_pll_bndy_bucket_0   = 356, //0x164
    perv_pll_bndy_bucket_1   = 357, //0x165
    perv_pll_bndy_bucket_2   = 358, //0x166
    perv_pll_bndy_bucket_3   = 359, //0x167
    n0_func                  = 360, //0x168
    n1_func                  = 361, //0x169
    n1_nmmu1_func            = 362, //0x16A
    pci_func                 = 363, //0x16B
    pci_pll_bndy_bucket_0    = 364, //0x16C
    pci_pll_bndy_bucket_1    = 365, //0x16D
    pci_pll_bndy_bucket_2    = 366, //0x16E
    pci_pll_bndy_bucket_3    = 367, //0x16F
    mc_func                  = 368, //0x170
    mc_pll_bndy_bucket_5     = 369, //0x171
    mc_pll_bndy_bucket_6     = 370, //0x172
    mc_pll_bndy_bucket_7     = 371, //0x173
    pau0_func                = 372, //0x174
    pau0_pau0_func           = 373, //0x175
    pau1_func                = 374, //0x176
    pau1_pau3_func           = 375, //0x177
    pau2_func                = 376, //0x178
    pau2_pau4_func           = 377, //0x179
    pau2_pau5_func           = 378, //0x17A
    pau3_func                = 379, //0x17B
    pau3_pau6_func           = 380, //0x17C
    pau3_pau7_func           = 381, //0x17D
    iohs0_func               = 382, //0x17E
    iohs0_pdl_func           = 383, //0x17F
    iohs0_pll_bndy_bucket_8  = 384, //0x180
    iohs0_pll_bndy_bucket_9  = 385, //0x181
    iohs0_pll_bndy_bucket_10 = 386, //0x182
    iohs0_pll_bndy_bucket_11 = 387, //0x183
    iohs0_pll_bndy_bucket_12 = 388, //0x184
    iohs0_pll_bndy_bucket_13 = 389, //0x185
    iohs0_pll_bndy_bucket_14 = 390, //0x186
    iohs0_pll_bndy_bucket_15 = 391, //0x187
    iohs1_func               = 392, //0x188
    iohs1_pdl_func           = 393, //0x189
    iohs2_func               = 394, //0x18A
    iohs2_pdl_func           = 395, //0x18B
    iohs3_func               = 396, //0x18C
    iohs3_pdl_func           = 397, //0x18D
    iohs4_func               = 398, //0x18E
    iohs4_pdl_func           = 399, //0x18F
    iohs5_func               = 400, //0x190
    iohs5_pdl_func           = 401, //0x191
    iohs6_func               = 402, //0x192
    iohs6_pdl_func           = 403, //0x193
    iohs7_func               = 404, //0x194
    iohs7_pdl_func           = 405, //0x195
    eq_func                  = 406, //0x196
    eq_clkadj_func           = 407, //0x197
    ec_cl2_func              = 408, //0x198
    ec_mma_func              = 409, //0x199
    ec_l3_func               = 410, //0x19A
    eq_inex                  = 411, //0x19B
    NUM_RING_IDS_EKB         = 156,

    NUM_RING_IDS             = 324, // = NUM_RING_IDS_MVPD + NUM_RING_IDS_EKB
}; // enum RingID

#endif  // _P10_RING_ID_H_
