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
    // invalid_ring: 7, //0x07
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
    NUM_RING_IDS_MVPD        = 161,

    // EKB Rings:
    perv_fure                = 161, //0xA1
    sbe_fure                 = 162, //0xA2
    occ_fure                 = 163, //0xA3
    perv_dpll_func           = 164, //0xA4
    perv_dpll_bndy           = 165, //0xA5
    perv_dpll_time           = 166, //0xA6
    perv_pll_func            = 167, //0xA7
    perv_pll_bndy            = 168, //0xA8
    n0_fure                  = 169, //0xA9
    n1_fure                  = 170, //0xAA
    n1_nmmu1_fure            = 171, //0xAB
    pci_fure                 = 172, //0xAC
    pci_pll_func             = 173, //0xAD
    pci_pll_bndy             = 174, //0xAE
    mc_fure                  = 175, //0xAF
    mc_pll_func              = 176, //0xB0
    mc_pll_bndy              = 177, //0xB1
    mc_pll_bndy_bucket_0     = 178, //0xB2
    mc_pll_bndy_bucket_1     = 179, //0xB3
    mc_pll_bndy_bucket_2     = 180, //0xB4
    mc_pll_bndy_bucket_3     = 181, //0xB5
    mc_pll_bndy_bucket_4     = 182, //0xB6
    pau0_fure                = 183, //0xB7
    pau0_pau0_fure           = 184, //0xB8
    pau1_fure                = 185, //0xB9
    pau1_pau3_fure           = 186, //0xBA
    pau2_fure                = 187, //0xBB
    pau2_pau4_fure           = 188, //0xBC
    pau2_pau5_fure           = 189, //0xBD
    pau3_fure                = 190, //0xBE
    pau3_pau6_fure           = 191, //0xBF
    pau3_pau7_fure           = 192, //0xC0
    iohs0_fure               = 193, //0xC1
    iohs0_ndl_fure           = 194, //0xC2
    iohs0_pdl_fure           = 195, //0xC3
    iohs0_pll_func           = 196, //0xC4
    iohs0_pll_bndy           = 197, //0xC5
    iohs0_pll_bndy_bucket_0  = 198, //0xC6
    iohs0_pll_bndy_bucket_1  = 199, //0xC7
    iohs0_pll_bndy_bucket_2  = 200, //0xC8
    iohs0_pll_bndy_bucket_3  = 201, //0xC9
    iohs0_pll_bndy_bucket_4  = 202, //0xCA
    iohs0_pll_bndy_bucket_5  = 203, //0xCB
    iohs0_pll_bndy_bucket_6  = 204, //0xCC
    iohs0_pll_bndy_bucket_7  = 205, //0xCD
    iohs1_fure               = 206, //0xCE
    iohs1_ndl_fure           = 207, //0xCF
    iohs1_pdl_fure           = 208, //0xD0
    iohs1_pll_func           = 209, //0xD1
    iohs2_fure               = 210, //0xD2
    iohs2_ndl_fure           = 211, //0xD3
    iohs2_pdl_fure           = 212, //0xD4
    iohs2_pll_func           = 213, //0xD5
    iohs3_fure               = 214, //0xD6
    iohs3_ndl_fure           = 215, //0xD7
    iohs3_pdl_fure           = 216, //0xD8
    iohs3_pll_func           = 217, //0xD9
    iohs4_fure               = 218, //0xDA
    iohs4_ndl_fure           = 219, //0xDB
    iohs4_pdl_fure           = 220, //0xDC
    iohs4_pll_func           = 221, //0xDD
    iohs5_fure               = 222, //0xDE
    iohs5_ndl_fure           = 223, //0xDF
    iohs5_pdl_fure           = 224, //0xE0
    iohs5_pll_func           = 225, //0xE1
    iohs6_fure               = 226, //0xE2
    iohs6_ndl_fure           = 227, //0xE3
    iohs6_pdl_fure           = 228, //0xE4
    iohs6_pll_func           = 229, //0xE5
    iohs7_fure               = 230, //0xE6
    iohs7_ndl_fure           = 231, //0xE7
    iohs7_pdl_fure           = 232, //0xE8
    iohs7_pll_func           = 233, //0xE9
    eq_fure                  = 234, //0xEA
    eq_cmsk                  = 235, //0xEB
    eq_inex                  = 236, //0xEC
    eq_mode                  = 237, //0xED
    eq_clkadj_fure           = 238, //0xEE
    eq_clkadj_cmsk           = 239, //0xEF
    eq_clkadj_inex           = 240, //0xF0
    eq_clkadj_mode           = 241, //0xF1
    ec_cl2_fure              = 242, //0xF2
    ec_cl2_cmsk              = 243, //0xF3
    ec_cl2_inex              = 244, //0xF4
    ec_cl2_mode              = 245, //0xF5
    ec_mma_fure              = 246, //0xF6
    ec_mma_cmsk              = 247, //0xF7
    ec_mma_inex              = 248, //0xF8
    ec_l3_fure               = 249, //0xF9
    ec_l3_cmsk               = 250, //0xFA
    ec_l3_inex               = 251, //0xFB
    ec_l3_mode               = 252, //0xFC
    NUM_RING_IDS_EKB         = 92,

    NUM_RING_IDS             = 253, // = NUM_RING_IDS_MVPD + NUM_RING_IDS_EKB
}; // enum RingID

#endif  // _P10_RING_ID_H_
