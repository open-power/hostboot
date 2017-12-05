/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/utils/imageProcs/cen_ring_id.h $     */
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
#ifndef _CEN_RING_ID_H_
#define _CEN_RING_ID_H_

//
// @brief Enumeration of Ring ID values. These values are used to organize
//        rings and to traverse TOR ring sections.
// NOTE: Do not change the numbering, the sequence or add new constants to
//       the below enum, unless you know the effect it has on the traversing
//       TOR.
//

enum RingID
{
    tcm_perv_cmsk         = 0,  //0x00
    tcm_perv_lbst         = 1,  //0x01
    tcm_perv_gptr         = 2,  //0x02
    tcm_perv_func         = 3,  //0x03
    tcm_perv_time         = 4,  //0x04
    tcm_perv_abst         = 5,  //0x05
    tcm_perv_repr         = 6,  //0x06
    tcm_perv_FARR         = 7,  //0x07
    tcm_memn_time         = 8,  //0x08
    tcm_memn_regf         = 9,  //0x09
    tcm_memn_gptr         = 10, //0x0A
    tcm_memn_func         = 11, //0x0B
    tcm_memn_lbst         = 12, //0x0C
    tcm_memn_cmsk         = 13, //0x0D
    tcm_memn_abst         = 14, //0x0E
    tcm_memn_repr         = 15, //0x0F
    tcm_memn_FARR         = 16, //0x10
    tcm_mems_time         = 17, //0x11
    tcm_mems_regf         = 18, //0x12
    tcm_mems_gptr         = 19, //0x13
    tcm_mems_func         = 20, //0x14
    tcm_mems_lbst         = 21, //0x15
    tcm_mems_cmsk         = 22, //0x16
    tcm_mems_bndy         = 23, //0x17
    tcm_mems_abst         = 24, //0x18
    tcm_mems_repr         = 25, //0x19
    tcm_mems_FARR         = 26, //0x1A
    tcm_ddrn_bndy         = 27, //0x1B
    tcm_ddrn_gptr         = 28, //0x1C
    tcm_ddrn_func         = 29, //0x1D
    tcm_ddrn_cmsk         = 30, //0x1E
    tcm_ddrn_lbst         = 31, //0x1F
    tcm_ddrs_bndy         = 32, //0x20
    tcm_ddrs_gptr         = 33, //0x21
    tcm_ddrs_func         = 34, //0x22
    tcm_ddrs_lbst         = 35, //0x23
    tcm_ddrs_cmsk         = 36, //0x24
    tcn_perv_cmsk         = 37, //0x25
    tcn_perv_lbst         = 38, //0x26
    tcn_perv_gptr         = 39, //0x27
    tcn_perv_func         = 40, //0x28
    tcn_perv_time         = 41, //0x29
    tcn_perv_FARR         = 42, //0x2A
    tcn_perv_abst         = 43, //0x2B
    tcn_mbi_FARR          = 44, //0x2C
    tcn_mbi_time          = 45, //0x2D
    tcn_mbi_repr          = 46, //0x2E
    tcn_mbi_abst          = 47, //0x2F
    tcn_mbi_regf          = 48, //0x30
    tcn_mbi_gptr          = 49, //0x31
    tcn_mbi_func          = 50, //0x32
    tcn_mbi_cmsk          = 51, //0x33
    tcn_mbi_lbst          = 52, //0x34
    tcn_dmi_bndy          = 53, //0x35
    tcn_dmi_gptr          = 54, //0x36
    tcn_dmi_func          = 55, //0x37
    tcn_dmi_cmsk          = 56, //0x38
    tcn_dmi_lbst          = 57, //0x39
    tcn_msc_gptr          = 58, //0x3A
    tcn_msc_func          = 59, //0x3B
    tcn_mbs_FARR          = 60, //0x3C
    tcn_mbs_time          = 61, //0x3D
    tcn_mbs_repr          = 62, //0x3E
    tcn_mbs_abst          = 63, //0x3F
    tcn_mbs_regf          = 64, //0x40
    tcn_mbs_gptr          = 65, //0x41
    tcn_mbs_func          = 66, //0x42
    tcn_mbs_lbst          = 67, //0x43
    tcn_mbs_cmsk          = 68, //0x44
    tcn_refr_cmsk         = 69, //0x45
    tcn_refr_FARR         = 70, //0x46
    tcn_refr_time         = 71, //0x47
    tcn_refr_repr         = 72, //0x48
    tcn_refr_abst         = 73, //0x49
    tcn_refr_lbst         = 74, //0x4A
    tcn_refr_regf         = 75, //0x4B
    tcn_refr_gptr         = 76, //0x4C
    tcn_refr_func         = 77, //0x4D
    tcn_perv_repr         = 78, //0x4E
    tp_perv_func          = 79, //0x4F
    tp_perv_gptr          = 80, //0x50
    tp_perv_mode          = 81, //0x51
    tp_perv_regf          = 82, //0x52
    tp_perv_lbst          = 83, //0x53
    tp_perv_abst          = 84, //0x54
    tp_perv_repr          = 85, //0x55
    tp_perv_time          = 86, //0x56
    tp_perv_bndy          = 87, //0x57
    tp_perv_farr          = 88, //0x58
    tp_perv_cmsk          = 89, //0x59
    tp_pll_func           = 90, //0x5A
    tp_pll_gptr           = 91, //0x5B
    tp_net_func           = 92, //0x5C
    tp_net_gptr           = 93, //0x5D
    tp_net_abst           = 94, //0x5E
    tp_pib_func           = 95, //0x5F
    tp_pib_fuse           = 96, //0x60
    tp_pib_gptr           = 97, //0x61
    tp_pll_bndy           = 98, //0x62
    tp_pll_bndy_bucket_1  = 99, //0x63
    tp_pll_bndy_bucket_2  = 100,//0x64
    tp_pll_bndy_bucket_3  = 101,//0x65
    tp_pll_bndy_bucket_4  = 102,//0x66
    tp_pll_bndy_bucket_5  = 103,//0x67
    tp_pll_bndy_bucket_6  = 104,//0x68
    tp_pll_bndy_bucket_7  = 105,//0x69
    tp_pll_bndy_bucket_8  = 106,//0x6A
    NUM_RING_IDS

}; // enum RingID

#endif  // _CEN_RING_ID_H_
