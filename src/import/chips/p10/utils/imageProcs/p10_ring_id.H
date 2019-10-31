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
    perv_dpll_time           = 11, //0x0B
    perv_dpll_gptr           = 12, //0x0C
    perv_pll_func            = 13, //0x0D
    perv_pll_bndy            = 14, //0x0E
    perv_pll_gptr            = 15, //0x0F

    // N0 Chiplet Rings
    n0_fure                  = 16, //0x10
    n0_gptr                  = 17, //0x11
    n0_repr                  = 18, //0x12
    n0_time                  = 19, //0x13

    // N1 Chiplet Rings
    n1_fure                  = 20, //0x14
    n1_gptr                  = 21, //0x15
    n1_repr                  = 22, //0x16
    n1_time                  = 23, //0x17
    n1_nmmu1_fure            = 24, //0x18
    n1_nmmu1_gptr            = 25, //0x19
    n1_nmmu1_repr            = 26, //0x1A
    n1_nmmu1_time            = 27, //0x1B

    // PCI Chiplet Rings
    pci_fure                 = 28, //0x1C
    pci_gptr                 = 29, //0x1D
    pci_repr                 = 30, //0x1E
    pci_time                 = 31, //0x1F
    pci_pll_func             = 32, //0x20
    pci_pll_gptr             = 33, //0x21
    pci_pll_bndy             = 34, //0x22

    // MC Chiplet Rings
    mc_fure                  = 35, //0x23
    mc_gptr                  = 36, //0x24
    mc_repr                  = 37, //0x25
    mc_time                  = 38, //0x26
    mc_pll_func              = 39, //0x27
    mc_pll_gptr              = 40, //0x28
    mc_pll_bndy              = 41, //0x29
    mc_pll_bndy_bucket_0     = 42, //0x2A
    mc_pll_bndy_bucket_1     = 43, //0x2B
    mc_pll_bndy_bucket_2     = 44, //0x2C
    mc_pll_bndy_bucket_3     = 45, //0x2D
    mc_pll_bndy_bucket_4     = 46, //0x2E

    // PAU0 Chiplet Rings
    pau0_fure                = 47, //0x2F
    pau0_gptr                = 48, //0x30
    pau0_repr                = 49, //0x31
    pau0_time                = 50, //0x32
    pau0_pau0_fure           = 51, //0x33
    pau0_pau0_gptr           = 52, //0x34
    pau0_pau0_repr           = 53, //0x35
    pau0_pau0_time           = 54, //0x36

    // PAU1 Chiplet Rings
    pau1_fure                = 55, //0x37
    pau1_gptr                = 56, //0x38
    pau1_repr                = 57, //0x39
    pau1_time                = 58, //0x3A
    pau1_pau3_fure           = 59, //0x3B
    pau1_pau3_gptr           = 60, //0x3C
    pau1_pau3_repr           = 61, //0x3D
    pau1_pau3_time           = 62, //0x3E

    // PAU2 Chiplet Rings
    pau2_fure                = 63, //0x3F
    pau2_gptr                = 64, //0x40
    pau2_repr                = 65, //0x41
    pau2_time                = 66, //0x42
    pau2_pau4_fure           = 67, //0x43
    pau2_pau4_gptr           = 68, //0x44
    pau2_pau4_repr           = 69, //0x45
    pau2_pau4_time           = 70, //0x46
    pau2_pau5_fure           = 71, //0x47
    pau2_pau5_gptr           = 72, //0x48
    pau2_pau5_repr           = 73, //0x49
    pau2_pau5_time           = 74, //0x4A

    // PAU3 Chiplet Rings
    pau3_fure                = 75, //0x4B
    pau3_gptr                = 76, //0x4C
    pau3_repr                = 77, //0x4D
    pau3_time                = 78, //0x4E
    pau3_pau6_fure           = 79, //0x4F
    pau3_pau6_gptr           = 80, //0x50
    pau3_pau6_repr           = 81, //0x51
    pau3_pau6_time           = 82, //0x52
    pau3_pau7_fure           = 83, //0x53
    pau3_pau7_gptr           = 84, //0x54
    pau3_pau7_repr           = 85, //0x55
    pau3_pau7_time           = 86, //0x56

    // AXON0 Chiplet Rings
    iohs0_fure               = 87, //0x57
    iohs0_gptr               = 88, //0x58
    iohs0_repr               = 89, //0x59
    iohs0_time               = 90, //0x5A
    iohs0_ndl_fure           = 91, //0x5B
    iohs0_ndl_gptr           = 92, //0x5C
    iohs0_ndl_repr           = 93, //0x5D
    iohs0_ndl_time           = 94, //0x5E
    iohs0_pdl_fure           = 95, //0x5F
    iohs0_pdl_gptr           = 96, //0x60
    iohs0_pdl_repr           = 97, //0x61
    iohs0_pdl_time           = 98, //0x62
    iohs0_pll_func           = 99, //0x63
    iohs0_pll_bndy           = 100, //0x64
    iohs0_pll_bndy_bucket_0  = 101, //0x65
    iohs0_pll_bndy_bucket_1  = 102, //0x66
    iohs0_pll_bndy_bucket_2  = 103, //0x67
    iohs0_pll_bndy_bucket_3  = 104, //0x68
    iohs0_pll_bndy_bucket_4  = 105, //0x69
    iohs0_pll_bndy_bucket_5  = 106, //0x6A
    iohs0_pll_bndy_bucket_6  = 107, //0x6B
    iohs0_pll_bndy_bucket_7  = 108, //0x6C
    iohs0_pll_gptr           = 109, //0x6D

    // AXON1 Chiplet Rings
    iohs1_fure               = 110, //0x6E
    iohs1_gptr               = 111, //0x6F
    iohs1_repr               = 112, //0x70
    iohs1_time               = 113, //0x71
    iohs1_ndl_fure           = 114, //0x72
    iohs1_ndl_gptr           = 115, //0x73
    iohs1_ndl_repr           = 116, //0x74
    iohs1_ndl_time           = 117, //0x75
    iohs1_pdl_fure           = 118, //0x76
    iohs1_pdl_gptr           = 119, //0x77
    iohs1_pdl_repr           = 120, //0x78
    iohs1_pdl_time           = 121, //0x79
    iohs1_pll_func           = 122, //0x7A
    iohs1_pll_gptr           = 123, //0x7B

    // AXON2 Chiplet Rings
    iohs2_fure               = 124, //0x7C
    iohs2_gptr               = 125, //0x7D
    iohs2_repr               = 126, //0x7E
    iohs2_time               = 127, //0x7F
    iohs2_ndl_fure           = 128, //0x80
    iohs2_ndl_gptr           = 129, //0x81
    iohs2_ndl_repr           = 130, //0x82
    iohs2_ndl_time           = 131, //0x83
    iohs2_pdl_fure           = 132, //0x84
    iohs2_pdl_gptr           = 133, //0x85
    iohs2_pdl_repr           = 134, //0x86
    iohs2_pdl_time           = 135, //0x87
    iohs2_pll_func           = 136, //0x88
    iohs2_pll_gptr           = 137, //0x89

    // AXON3 Chiplet Rings
    iohs3_fure               = 138, //0x8A
    iohs3_gptr               = 139, //0x8B
    iohs3_repr               = 140, //0x8C
    iohs3_time               = 141, //0x8D
    iohs3_ndl_fure           = 142, //0x8E
    iohs3_ndl_gptr           = 143, //0x8F
    iohs3_ndl_repr           = 144, //0x90
    iohs3_ndl_time           = 145, //0x91
    iohs3_pdl_fure           = 146, //0x92
    iohs3_pdl_gptr           = 147, //0x93
    iohs3_pdl_repr           = 148, //0x94
    iohs3_pdl_time           = 149, //0x95
    iohs3_pll_func           = 150, //0x96
    iohs3_pll_gptr           = 151, //0x97

    // AXON4 Chiplet Rings
    iohs4_fure               = 152, //0x98
    iohs4_gptr               = 153, //0x99
    iohs4_repr               = 154, //0x9A
    iohs4_time               = 155, //0x9B
    iohs4_ndl_fure           = 156, //0x9C
    iohs4_ndl_gptr           = 157, //0x9D
    iohs4_ndl_repr           = 158, //0x9E
    iohs4_ndl_time           = 159, //0x9F
    iohs4_pdl_fure           = 160, //0xA0
    iohs4_pdl_gptr           = 161, //0xA1
    iohs4_pdl_repr           = 162, //0xA2
    iohs4_pdl_time           = 163, //0xA3
    iohs4_pll_func           = 164, //0xA4
    iohs4_pll_gptr           = 165, //0xA5

    // AXON5 Chiplet Rings
    iohs5_fure               = 166, //0xA6
    iohs5_gptr               = 167, //0xA7
    iohs5_repr               = 168, //0xA8
    iohs5_time               = 169, //0xA9
    iohs5_ndl_fure           = 170, //0xAA
    iohs5_ndl_gptr           = 171, //0xAB
    iohs5_ndl_repr           = 172, //0xAC
    iohs5_ndl_time           = 173, //0xAD
    iohs5_pdl_fure           = 174, //0xAE
    iohs5_pdl_gptr           = 175, //0xAF
    iohs5_pdl_repr           = 176, //0xB0
    iohs5_pdl_time           = 177, //0xB1
    iohs5_pll_func           = 178, //0xB2
    iohs5_pll_gptr           = 179, //0xB3

    // AXON6 Chiplet Rings
    iohs6_fure               = 180, //0xB4
    iohs6_gptr               = 181, //0xB5
    iohs6_repr               = 182, //0xB6
    iohs6_time               = 183, //0xB7
    iohs6_ndl_fure           = 184, //0xB8
    iohs6_ndl_gptr           = 185, //0xB9
    iohs6_ndl_repr           = 186, //0xBA
    iohs6_ndl_time           = 187, //0xBB
    iohs6_pdl_fure           = 188, //0xBC
    iohs6_pdl_gptr           = 189, //0xBD
    iohs6_pdl_repr           = 190, //0xBE
    iohs6_pdl_time           = 191, //0xBF
    iohs6_pll_func           = 192, //0xC0
    iohs6_pll_gptr           = 193, //0xC1

    // AXON7 Chiplet Rings
    iohs7_fure               = 194, //0xC2
    iohs7_gptr               = 195, //0xC3
    iohs7_repr               = 196, //0xC4
    iohs7_time               = 197, //0xC5
    iohs7_ndl_fure           = 198, //0xC6
    iohs7_ndl_gptr           = 199, //0xC7
    iohs7_ndl_repr           = 200, //0xC8
    iohs7_ndl_time           = 201, //0xC9
    iohs7_pdl_fure           = 202, //0xCA
    iohs7_pdl_gptr           = 203, //0xCB
    iohs7_pdl_repr           = 204, //0xCC
    iohs7_pdl_time           = 205, //0xCD
    iohs7_pll_func           = 206, //0xCE
    iohs7_pll_gptr           = 207, //0xCF

    // EQ Chiplet Rings
    eq_fure                  = 208, //0xD0
    eq_gptr                  = 209, //0xD1
    eq_repr                  = 210, //0xD2
    eq_time                  = 211, //0xD3
    eq_cmsk                  = 212, //0xD4
    eq_inex                  = 213, //0xD5
    eq_mode                  = 214, //0xD6
    ec_cl2_fure              = 215, //0xD7
    ec_cl2_gptr              = 216, //0xD8
    ec_cl2_repr              = 217, //0xD9
    ec_cl2_time              = 218, //0xDA
    ec_cl2_cmsk              = 219, //0xDB
    ec_cl2_inex              = 220, //0xDC
    ec_cl2_mode              = 221, //0xDD
    ec1_cl2_repr             = 222, //0xDE
    ec2_cl2_repr             = 223, //0xDF
    ec3_cl2_repr             = 224, //0xE0
    ec_mma_fure              = 225, //0xE1
    ec_mma_gptr              = 226, //0xE2
    ec_mma_repr              = 227, //0xE3
    ec_mma_time              = 228, //0xE4
    ec_mma_cmsk              = 229, //0xE5
    ec_mma_inex              = 230, //0xE6
    ec1_mma_repr             = 231, //0xE7
    ec2_mma_repr             = 232, //0xE8
    ec3_mma_repr             = 233, //0xE9
    ec_l3_fure               = 234, //0xEA
    ec_l3_gptr               = 235, //0xEB
    ec_l3_repr               = 236, //0xEC
    ec_l3_time               = 237, //0xED
    ec_l3_cmsk               = 238, //0xEE
    ec_l3_inex               = 239, //0xEF
    ec_l3_mode               = 240, //0xF0
    ec1_l3_repr              = 241, //0xF1
    ec2_l3_repr              = 242, //0xF2
    ec3_l3_repr              = 243, //0xF3

    NUM_RING_IDS
}; // enum RingID

#endif  // _P10_RING_ID_H_
