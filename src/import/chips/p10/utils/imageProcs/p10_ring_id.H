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
    pci_ph5_fure             = 31, //0x1F
    pci_ph5_gptr             = 32, //0x20
    pci_ph5_repr             = 33, //0x21
    pci_ph5_time             = 34, //0x22
    pci_pll_func             = 35, //0x23
    pci_pll_bndy             = 36, //0x24
    pci_pll_gptr             = 37, //0x25

    // MC Chiplet Rings
    mc_fure                  = 38, //0x26
    mc_gptr                  = 39, //0x27
    mc_repr                  = 40, //0x28
    mc_time                  = 41, //0x29
    mc_emo_fure              = 42, //0x2A
    mc_emo_gptr              = 43, //0x2B
    mc_emo_repr              = 44, //0x2C
    mc_emo_time              = 45, //0x2D
    mc_pll_func              = 46, //0x2E
    mc_pll_bndy              = 47, //0x2F
    mc_pll_bndy_bucket_0     = 48, //0x30
    mc_pll_bndy_bucket_1     = 49, //0x31
    mc_pll_bndy_bucket_2     = 50, //0x32
    mc_pll_bndy_bucket_3     = 51, //0x33
    mc_pll_bndy_bucket_4     = 52, //0x34
    mc_pll_gptr              = 53, //0x35

    // PAU0 Chiplet Rings
    pau0_fure                = 54, //0x36
    pau0_gptr                = 55, //0x37
    pau0_repr                = 56, //0x38
    pau0_time                = 57, //0x39
    pau0_pau0_fure           = 58, //0x3A
    pau0_pau0_gptr           = 59, //0x3B
    pau0_pau0_repr           = 60, //0x3C
    pau0_pau0_time           = 61, //0x3D

    // PAU1 Chiplet Rings
    pau1_fure                = 62, //0x3E
    pau1_gptr                = 63, //0x3F
    pau1_repr                = 64, //0x40
    pau1_time                = 65, //0x41
    pau1_pau3_fure           = 66, //0x42
    pau1_pau3_gptr           = 67, //0x43
    pau1_pau3_repr           = 68, //0x44
    pau1_pau3_time           = 69, //0x45

    // PAU2 Chiplet Rings
    pau2_fure                = 70, //0x46
    pau2_gptr                = 71, //0x47
    pau2_repr                = 72, //0x48
    pau2_time                = 73, //0x49
    pau2_pau4_fure           = 74, //0x4A
    pau2_pau4_gptr           = 75, //0x4B
    pau2_pau4_repr           = 76, //0x4C
    pau2_pau4_time           = 77, //0x4D
    pau2_pau5_fure           = 78, //0x4E
    pau2_pau5_gptr           = 79, //0x4F
    pau2_pau5_repr           = 80, //0x50
    pau2_pau5_time           = 81, //0x51

    // PAU3 Chiplet Rings
    pau3_fure                = 82, //0x52
    pau3_gptr                = 83, //0x53
    pau3_repr                = 84, //0x54
    pau3_time                = 85, //0x55
    pau3_pau6_fure           = 86, //0x56
    pau3_pau6_gptr           = 87, //0x57
    pau3_pau6_repr           = 88, //0x58
    pau3_pau6_time           = 89, //0x59
    pau3_pau7_fure           = 90, //0x5A
    pau3_pau7_gptr           = 91, //0x5B
    pau3_pau7_repr           = 92, //0x5C
    pau3_pau7_time           = 93, //0x5D

    // AXON Chiplet Rings
    iohs_fure                = 94, //0x5E
    iohs_gptr                = 95, //0x5F
    iohs_repr                = 96, //0x60
    iohs_time                = 97, //0x61
    iohs_ndl_fure            = 98, //0x62
    iohs_ndl_gptr            = 99, //0x63
    iohs_ndl_repr            = 100, //0x64
    iohs_ndl_time            = 101, //0x65
    iohs_pdl_fure            = 102, //0x66
    iohs_pdl_gptr            = 103, //0x67
    iohs_pdl_repr            = 104, //0x68
    iohs_pdl_time            = 105, //0x69
    iohs_pll_func            = 106, //0x6A
    iohs_pll_bndy            = 107, //0x6B
    iohs_pll_bndy_bucket_0   = 108, //0x6C
    iohs_pll_bndy_bucket_1   = 109, //0x6D
    iohs_pll_bndy_bucket_2   = 110, //0x6E
    iohs_pll_bndy_bucket_3   = 111, //0x6F
    iohs_pll_bndy_bucket_4   = 112, //0x70
    iohs_pll_gptr            = 113, //0x71

    // EQ Chiplet Rings
    eq_fure                  = 114, //0x72
    eq_gptr                  = 115, //0x73
    eq_repr                  = 116, //0x74
    eq_time                  = 117, //0x75
    eq_cmsk                  = 118, //0x76
    eq_inex                  = 119, //0x77
    ec_cl2_fure              = 120, //0x78
    ec_cl2_gptr              = 121, //0x79
    ec_cl2_repr              = 122, //0x7A
    ec_cl2_time              = 123, //0x7B
    ec_cl2_cmsk              = 124, //0x7C
    ec_cl2_inex              = 125, //0x7D
    ec_mma_fure              = 126, //0x7E
    ec_mma_gptr              = 127, //0x7F
    ec_mma_repr              = 128, //0x80
    ec_mma_time              = 129, //0x81
    ec_mma_cmsk              = 130, //0x82
    ec_mma_inex              = 131, //0x83
    ec_l3_fure               = 132, //0x84
    ec_l3_gptr               = 133, //0x85
    ec_l3_repr               = 134, //0x86
    ec_l3_time               = 135, //0x87
    ec_l3_cmsk               = 136, //0x88
    ec_l3_inex               = 137, //0x89

    NUM_RING_IDS
}; // enum RingID

#endif  // _P10_RING_ID_H_
