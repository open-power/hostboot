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

// *****************
// *** IMPORTANT ***
// *****************
// Do  *NOT*  change the numbering, the sequence or add new constants to
// the below enum, unless you know the effect it has on the traversing
// of the TOR ring section:
// - There are hard coded assumptions in SBE and QME PPE codes about the
//   below enums.
// - A change to the below values could cause a co-req situation.
//
enum RingID
{
    // PERV Chiplet Rings - PERV
    perv_fure   = 0, //0x00
    perv_gptr   = 1, //0x01
    perv_lbst   = 2, //0x02
    perv_abst   = 3, //0x03
    perv_repr   = 4, //0x04
    perv_time   = 5, //0x05
    perv_bndy   = 6, //0x06

    // Nest Chiplet Rings - N0
    n0_fure     = 7,  //0x07
    n0_gptr     = 8,  //0x08
    n0_lbst     = 9,  //0x09
    n0_abst     = 10, //0x0A
    n0_repr     = 11, //0x0B
    n0_time     = 12, //0x0C
    n0_bndy     = 13, //0x0D

    // Nest Chiplet Rings - N1
    n1_fure     = 14, //0x0E
    n2_gptr     = 15, //0x0F
    n3_lbst     = 16, //0x10
    n4_abst     = 17, //0x11
    n7_repr     = 18, //0x12
    n5_time     = 19, //0x13
    n6_bndy     = 20, //0x14

    // PCI Chiplet Rings - PCI
    pci_fure    = 21, //0x15
    pci_gptr    = 22, //0x16
    pci_lbst    = 23, //0x17
    pci_abst    = 24, //0x18
    pci_repr    = 25, //0x19
    pci_time    = 26, //0x1A
    pci_bndy    = 27, //0x1B

    // MC Chiplet Rings - MCI
    mc_fure     = 28, //0x1C
    mc_gptr     = 29, //0x1D
    mc_lbst     = 30, //0x1E
    mc_abst     = 31, //0x1F
    mc_repr     = 32, //0x20
    mc_time     = 33, //0x21
    mc_bndy     = 34, //0x22

    // AXON Chiplet Rings - AXON
    iohs_fure   = 35, //0x23
    iohs_gptr   = 36, //0x24
    iohs_lbst   = 37, //0x25
    iohs_abst   = 38, //0x26
    iohs_repr   = 39, //0x27
    iohs_time   = 40, //0x28
    iohs_bndy   = 41, //0x29

    // Quad Chiplet Rings - EQ
    eq_fure     = 42, //0x2A
    eq_gptr     = 43, //0x2B
    eq_lbst     = 44, //0x2C
    eq_abst     = 45, //0x2D
    eq_repr     = 46, //0x2E
    eq_time     = 47, //0x2F
    eq_bndy     = 48, //0x30
    ec_cl2_fure = 49, //0x31
    ec_cl2_gptr = 50, //0x32
    ec_cl2_lbst = 51, //0x33
    ec_cl2_abst = 52, //0x34
    ec_cl2_repr = 53, //0x35
    ec_cl2_time = 54, //0x36
    ec_cl2_bndy = 55, //0x37

    NUM_RING_IDS

}; // enum RingID

#endif  // _P10_RING_ID_H_
