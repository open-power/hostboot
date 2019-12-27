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
    // PERV Chiplet Rings
    perv_fure                = 0, //0x00
    perv_occ_gptr            = 1, //0x01
    perv_occ_repr            = 2, //0x02
    perv_occ_time            = 3, //0x03
    pib_repr                 = 4, //0x04
    sbe_fure                 = 5, //0x05
    sbe_gptr                 = 6, //0x06
    sbe_repr                 = 7, //0x07
    sbe_time                 = 8, //0x08
    occ_fure                 = 9, //0x09
    perv_dpll_func           = 10, //0x0A
    perv_dpll_bndy           = 11, //0x0B
    perv_dpll_time           = 12, //0x0C
    perv_dpll_gptr           = 13, //0x0D
    perv_pll_func            = 14, //0x0E
    perv_pll_bndy            = 15, //0x0F
    perv_pll_gptr            = 16, //0x10

    // N0 Chiplet Rings
    n0_fure                  = 17, //0x11
    n0_gptr                  = 18, //0x12
    n0_repr                  = 19, //0x13
    n0_time                  = 20, //0x14

    // N1 Chiplet Rings
    n1_fure                  = 21, //0x15
    n1_gptr                  = 22, //0x16
    n1_repr                  = 23, //0x17
    n1_time                  = 24, //0x18
    n1_nmmu1_fure            = 25, //0x19
    n1_nmmu1_gptr            = 26, //0x1A
    n1_nmmu1_repr            = 27, //0x1B
    n1_nmmu1_time            = 28, //0x1C

    // PCI Chiplet Rings
    pci_fure                 = 29, //0x1D
    pci_gptr                 = 30, //0x1E
    pci_repr                 = 31, //0x1F
    pci_time                 = 32, //0x20
    pci_pll_func             = 33, //0x21
    pci_pll_gptr             = 34, //0x22
    pci_pll_bndy             = 35, //0x23

    // MC Chiplet Rings
    mc_fure                  = 36, //0x24
    mc_gptr                  = 37, //0x25
    mc_repr                  = 38, //0x26
    mc_time                  = 39, //0x27
    mc_pll_func              = 40, //0x28
    mc_pll_gptr              = 41, //0x29
    mc_pll_bndy              = 42, //0x2A
    mc_pll_bndy_bucket_0     = 43, //0x2B
    mc_pll_bndy_bucket_1     = 44, //0x2C
    mc_pll_bndy_bucket_2     = 45, //0x2D
    mc_pll_bndy_bucket_3     = 46, //0x2E
    mc_pll_bndy_bucket_4     = 47, //0x2F

    // PAU0 Chiplet Rings
    pau0_fure                = 48, //0x30
    pau0_gptr                = 49, //0x31
    pau0_repr                = 50, //0x32
    pau0_time                = 51, //0x33
    pau0_pau0_fure           = 52, //0x34
    pau0_pau0_gptr           = 53, //0x35
    pau0_pau0_repr           = 54, //0x36
    pau0_pau0_time           = 55, //0x37

    // PAU1 Chiplet Rings
    pau1_fure                = 56, //0x38
    pau1_gptr                = 57, //0x39
    pau1_repr                = 58, //0x3A
    pau1_time                = 59, //0x3B
    pau1_pau3_fure           = 60, //0x3C
    pau1_pau3_gptr           = 61, //0x3D
    pau1_pau3_repr           = 62, //0x3E
    pau1_pau3_time           = 63, //0x3F

    // PAU2 Chiplet Rings
    pau2_fure                = 64, //0x40
    pau2_gptr                = 65, //0x41
    pau2_repr                = 66, //0x42
    pau2_time                = 67, //0x43
    pau2_pau4_fure           = 68, //0x44
    pau2_pau4_gptr           = 69, //0x45
    pau2_pau4_repr           = 70, //0x46
    pau2_pau4_time           = 71, //0x47
    pau2_pau5_fure           = 72, //0x48
    pau2_pau5_gptr           = 73, //0x49
    pau2_pau5_repr           = 74, //0x4A
    pau2_pau5_time           = 75, //0x4B

    // PAU3 Chiplet Rings
    pau3_fure                = 76, //0x4C
    pau3_gptr                = 77, //0x4D
    pau3_repr                = 78, //0x4E
    pau3_time                = 79, //0x4F
    pau3_pau6_fure           = 80, //0x50
    pau3_pau6_gptr           = 81, //0x51
    pau3_pau6_repr           = 82, //0x52
    pau3_pau6_time           = 83, //0x53
    pau3_pau7_fure           = 84, //0x54
    pau3_pau7_gptr           = 85, //0x55
    pau3_pau7_repr           = 86, //0x56
    pau3_pau7_time           = 87, //0x57

    // AXON0 Chiplet Rings
    iohs0_fure               = 88, //0x58
    iohs0_gptr               = 89, //0x59
    iohs0_repr               = 90, //0x5A
    iohs0_time               = 91, //0x5B
    iohs0_ndl_fure           = 92, //0x5C
    iohs0_ndl_gptr           = 93, //0x5D
    iohs0_ndl_repr           = 94, //0x5E
    iohs0_ndl_time           = 95, //0x5F
    iohs0_pdl_fure           = 96, //0x60
    iohs0_pdl_gptr           = 97, //0x61
    iohs0_pdl_repr           = 98, //0x62
    iohs0_pdl_time           = 99, //0x63
    iohs0_pll_func           = 100, //0x64
    iohs0_pll_bndy           = 101, //0x65
    iohs0_pll_bndy_bucket_0  = 102, //0x66
    iohs0_pll_bndy_bucket_1  = 103, //0x67
    iohs0_pll_bndy_bucket_2  = 104, //0x68
    iohs0_pll_bndy_bucket_3  = 105, //0x69
    iohs0_pll_bndy_bucket_4  = 106, //0x6A
    iohs0_pll_bndy_bucket_5  = 107, //0x6B
    iohs0_pll_bndy_bucket_6  = 108, //0x6C
    iohs0_pll_bndy_bucket_7  = 109, //0x6D
    iohs0_pll_gptr           = 110, //0x6E

    // AXON1 Chiplet Rings
    iohs1_fure               = 111, //0x6F
    iohs1_gptr               = 112, //0x70
    iohs1_repr               = 113, //0x71
    iohs1_time               = 114, //0x72
    iohs1_ndl_fure           = 115, //0x73
    iohs1_ndl_gptr           = 116, //0x74
    iohs1_ndl_repr           = 117, //0x75
    iohs1_ndl_time           = 118, //0x76
    iohs1_pdl_fure           = 119, //0x77
    iohs1_pdl_gptr           = 120, //0x78
    iohs1_pdl_repr           = 121, //0x79
    iohs1_pdl_time           = 122, //0x7A
    iohs1_pll_func           = 123, //0x7B
    iohs1_pll_gptr           = 124, //0x7C

    // AXON2 Chiplet Rings
    iohs2_fure               = 125, //0x7D
    iohs2_gptr               = 126, //0x7E
    iohs2_repr               = 127, //0x7F
    iohs2_time               = 128, //0x80
    iohs2_ndl_fure           = 129, //0x81
    iohs2_ndl_gptr           = 130, //0x82
    iohs2_ndl_repr           = 131, //0x83
    iohs2_ndl_time           = 132, //0x84
    iohs2_pdl_fure           = 133, //0x85
    iohs2_pdl_gptr           = 134, //0x86
    iohs2_pdl_repr           = 135, //0x87
    iohs2_pdl_time           = 136, //0x88
    iohs2_pll_func           = 137, //0x89
    iohs2_pll_gptr           = 138, //0x8A

    // AXON3 Chiplet Rings
    iohs3_fure               = 139, //0x8B
    iohs3_gptr               = 140, //0x8C
    iohs3_repr               = 141, //0x8D
    iohs3_time               = 142, //0x8E
    iohs3_ndl_fure           = 143, //0x8F
    iohs3_ndl_gptr           = 144, //0x90
    iohs3_ndl_repr           = 145, //0x91
    iohs3_ndl_time           = 146, //0x92
    iohs3_pdl_fure           = 147, //0x93
    iohs3_pdl_gptr           = 148, //0x94
    iohs3_pdl_repr           = 149, //0x95
    iohs3_pdl_time           = 150, //0x96
    iohs3_pll_func           = 151, //0x97
    iohs3_pll_gptr           = 152, //0x98

    // AXON4 Chiplet Rings
    iohs4_fure               = 153, //0x99
    iohs4_gptr               = 154, //0x9A
    iohs4_repr               = 155, //0x9B
    iohs4_time               = 156, //0x9C
    iohs4_ndl_fure           = 157, //0x9D
    iohs4_ndl_gptr           = 158, //0x9E
    iohs4_ndl_repr           = 159, //0x9F
    iohs4_ndl_time           = 160, //0xA0
    iohs4_pdl_fure           = 161, //0xA1
    iohs4_pdl_gptr           = 162, //0xA2
    iohs4_pdl_repr           = 163, //0xA3
    iohs4_pdl_time           = 164, //0xA4
    iohs4_pll_func           = 165, //0xA5
    iohs4_pll_gptr           = 166, //0xA6

    // AXON5 Chiplet Rings
    iohs5_fure               = 167, //0xA7
    iohs5_gptr               = 168, //0xA8
    iohs5_repr               = 169, //0xA9
    iohs5_time               = 170, //0xAA
    iohs5_ndl_fure           = 171, //0xAB
    iohs5_ndl_gptr           = 172, //0xAC
    iohs5_ndl_repr           = 173, //0xAD
    iohs5_ndl_time           = 174, //0xAE
    iohs5_pdl_fure           = 175, //0xAF
    iohs5_pdl_gptr           = 176, //0xB0
    iohs5_pdl_repr           = 177, //0xB1
    iohs5_pdl_time           = 178, //0xB2
    iohs5_pll_func           = 179, //0xB3
    iohs5_pll_gptr           = 180, //0xB4

    // AXON6 Chiplet Rings
    iohs6_fure               = 181, //0xB5
    iohs6_gptr               = 182, //0xB6
    iohs6_repr               = 183, //0xB7
    iohs6_time               = 184, //0xB8
    iohs6_ndl_fure           = 185, //0xB9
    iohs6_ndl_gptr           = 186, //0xBA
    iohs6_ndl_repr           = 187, //0xBB
    iohs6_ndl_time           = 188, //0xBC
    iohs6_pdl_fure           = 189, //0xBD
    iohs6_pdl_gptr           = 190, //0xBE
    iohs6_pdl_repr           = 191, //0xBF
    iohs6_pdl_time           = 192, //0xC0
    iohs6_pll_func           = 193, //0xC1
    iohs6_pll_gptr           = 194, //0xC2

    // AXON7 Chiplet Rings
    iohs7_fure               = 195, //0xC3
    iohs7_gptr               = 196, //0xC4
    iohs7_repr               = 197, //0xC5
    iohs7_time               = 198, //0xC6
    iohs7_ndl_fure           = 199, //0xC7
    iohs7_ndl_gptr           = 200, //0xC8
    iohs7_ndl_repr           = 201, //0xC9
    iohs7_ndl_time           = 202, //0xCA
    iohs7_pdl_fure           = 203, //0xCB
    iohs7_pdl_gptr           = 204, //0xCC
    iohs7_pdl_repr           = 205, //0xCD
    iohs7_pdl_time           = 206, //0xCE
    iohs7_pll_func           = 207, //0xCF
    iohs7_pll_gptr           = 208, //0xD0

    // EQ Chiplet Rings
    eq_fure                  = 209, //0xD1
    eq_gptr                  = 210, //0xD2
    eq_repr                  = 211, //0xD3
    eq_time                  = 212, //0xD4
    eq_cmsk                  = 213, //0xD5
    eq_inex                  = 214, //0xD6
    eq_mode                  = 215, //0xD7
    eq_clkadj_fure           = 216, //0xD8
    eq_clkadj_gptr           = 217, //0xD9
    eq_clkadj_repr           = 218, //0xDA
    eq_clkadj_time           = 219, //0xDB
    eq_clkadj_cmsk           = 220, //0xDC
    eq_clkadj_inex           = 221, //0xDD
    eq_clkadj_mode           = 222, //0xDE
    ec_cl2_fure              = 223, //0xDF
    ec_cl2_gptr              = 224, //0xE0
    ec_cl2_repr              = 225, //0xE1
    ec_cl2_time              = 226, //0xE2
    ec_cl2_cmsk              = 227, //0xE3
    ec_cl2_inex              = 228, //0xE4
    ec_cl2_mode              = 229, //0xE5
    ec1_cl2_repr             = 230, //0xE6
    ec2_cl2_repr             = 231, //0xE7
    ec3_cl2_repr             = 232, //0xE8
    ec_mma_fure              = 233, //0xE9
    ec_mma_gptr              = 234, //0xEA
    ec_mma_repr              = 235, //0xEB
    ec_mma_time              = 236, //0xEC
    ec_mma_cmsk              = 237, //0xED
    ec_mma_inex              = 238, //0xEE
    ec1_mma_repr             = 239, //0xEF
    ec2_mma_repr             = 240, //0xF0
    ec3_mma_repr             = 241, //0xF1
    ec_l3_fure               = 242, //0xF2
    ec_l3_gptr               = 243, //0xF3
    ec_l3_repr               = 244, //0xF4
    ec_l3_time               = 245, //0xF5
    ec_l3_cmsk               = 246, //0xF6
    ec_l3_inex               = 247, //0xF7
    ec_l3_mode               = 248, //0xF8
    ec1_l3_repr              = 249, //0xF9
    ec2_l3_repr              = 250, //0xFA
    ec3_l3_repr              = 251, //0xFB

    NUM_RING_IDS
}; // enum RingID

#endif  // _P10_RING_ID_H_
