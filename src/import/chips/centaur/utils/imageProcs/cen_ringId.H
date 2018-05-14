/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/utils/imageProcs/cen_ringId.H $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

#ifndef _CEN_RINGID_H_
#define _CEN_RINGID_H_

#include <stdint.h>
#include <stddef.h>
#include <common_ringId.H>
#include <cen_ring_id.h>

enum Chiplets
{
    CEN_TYPE,
    CEN_NUM_CHIPLETS
};

namespace CEN
{

enum RingOffset
{
    // Common Rings
    tcm_perv_cmsk = 0,
    tcm_perv_lbst = 1,
    tcm_perv_gptr = 2,
    tcm_perv_func = 3,
    tcm_perv_time = 4,
    tcm_perv_abst = 5,
    tcm_perv_repr = 6,
    tcm_perv_FARR = 7,
    tcm_memn_time = 8,
    tcm_memn_regf = 9,
    tcm_memn_gptr = 10,
    tcm_memn_func = 11,
    tcm_memn_lbst = 12,
    tcm_memn_cmsk = 13,
    tcm_memn_abst = 14,
    tcm_memn_repr = 15,
    tcm_memn_FARR = 16,
    tcm_mems_time = 17,
    tcm_mems_regf = 18,
    tcm_mems_gptr = 19,
    tcm_mems_func = 20,
    tcm_mems_lbst = 21,
    tcm_mems_cmsk = 22,
    tcm_mems_bndy = 23,
    tcm_mems_abst = 24,
    tcm_mems_repr = 25,
    tcm_mems_FARR = 26,
    tcm_ddrn_bndy = 27,
    tcm_ddrn_gptr = 28,
    tcm_ddrn_func = 29,
    tcm_ddrn_cmsk = 30,
    tcm_ddrn_lbst = 31,
    tcm_ddrs_bndy = 32,
    tcm_ddrs_gptr = 33,
    tcm_ddrs_func = 34,
    tcm_ddrs_lbst = 35,
    tcm_ddrs_cmsk = 36,
    tcn_perv_cmsk = 37,
    tcn_perv_lbst = 38,
    tcn_perv_gptr = 39,
    tcn_perv_func = 40,
    tcn_perv_time = 41,
    tcn_perv_FARR = 42,
    tcn_perv_abst = 43,
    tcn_mbi_FARR  = 44,
    tcn_mbi_time  = 45,
    tcn_mbi_repr  = 46,
    tcn_mbi_abst  = 47,
    tcn_mbi_regf  = 48,
    tcn_mbi_gptr  = 49,
    tcn_mbi_func  = 50,
    tcn_mbi_cmsk  = 51,
    tcn_mbi_lbst  = 52,
    tcn_dmi_bndy  = 53,
    tcn_dmi_gptr  = 54,
    tcn_dmi_func  = 55,
    tcn_dmi_cmsk  = 56,
    tcn_dmi_lbst  = 57,
    tcn_msc_gptr  = 58,
    tcn_msc_func  = 59,
    tcn_mbs_FARR  = 60,
    tcn_mbs_time  = 61,
    tcn_mbs_repr  = 62,
    tcn_mbs_abst  = 63,
    tcn_mbs_regf  = 64,
    tcn_mbs_gptr  = 65,
    tcn_mbs_func  = 66,
    tcn_mbs_lbst  = 67,
    tcn_mbs_cmsk  = 68,
    tcn_refr_cmsk = 69,
    tcn_refr_FARR = 70,
    tcn_refr_time = 71,
    tcn_refr_repr = 72,
    tcn_refr_abst = 73,
    tcn_refr_lbst = 74,
    tcn_refr_regf = 75,
    tcn_refr_gptr = 76,
    tcn_refr_func = 77,
    tcn_perv_repr = 78,
    tp_perv_func  = 79,
    tp_perv_gptr  = 80,
    tp_perv_mode  = 81,
    tp_perv_regf  = 82,
    tp_perv_lbst  = 83,
    tp_perv_abst  = 84,
    tp_perv_repr  = 85,
    tp_perv_time  = 86,
    tp_perv_bndy  = 87,
    tp_perv_farr  = 88,
    tp_perv_cmsk  = 89,
    tp_pll_func   = 90,
    tp_pll_gptr   = 91,
    tp_net_func   = 92,
    tp_net_gptr   = 93,
    tp_net_abst   = 94,
    tp_pib_func   = 95,
    tp_pib_fuse   = 96,
    tp_pib_gptr   = 97,
    tp_pll_bndy   = 98,
    tp_pll_bndy_bucket_1 = 99,
    tp_pll_bndy_bucket_2 = 100,
    tp_pll_bndy_bucket_3 = 101,
    tp_pll_bndy_bucket_4 = 102,
    tp_pll_bndy_bucket_5 = 103,
    tp_pll_bndy_bucket_6 = 104,
    tp_pll_bndy_bucket_7 = 105,
    tp_pll_bndy_bucket_8 = 106
                           // Instance rings
                           // ** none **
};

static const ChipletData_t g_chipletData =
{
    0x01,         // Base chiplet/instance ID
    1,            // Number of chiplet instances
    NUM_RING_IDS, // Num of common rings for Centaur chiplet
    0,            // Num of instance rings for Centaur chiplet
    0,
    2,            // Num of ring variants: BASE, RL
    { RV_BASE, RV_RL, UNDEFINED_RING_VARIANT, UNDEFINED_RING_VARIANT, UNDEFINED_RING_VARIANT, UNDEFINED_RING_VARIANT, UNDEFINED_RING_VARIANT }
};

}; // namespace CEN

#ifndef __PPE__

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { "tcm_perv_cmsk",        0x0303400a, CEN::tcm_perv_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_lbst",        0x03034004, CEN::tcm_perv_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_gptr",        0x03034002, CEN::tcm_perv_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_func",        0x03034000, CEN::tcm_perv_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_time",        0x03034007, CEN::tcm_perv_time,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_abst",        0x03034005, CEN::tcm_perv_abst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_repr",        0x03034006, CEN::tcm_perv_repr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_perv_FARR",        0x03034009, CEN::tcm_perv_FARR,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_time",        0x03032007, CEN::tcm_memn_time,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_regf",        0x03032003, CEN::tcm_memn_regf,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_gptr",        0x03032002, CEN::tcm_memn_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_func",        0x03032000, CEN::tcm_memn_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_lbst",        0x03032004, CEN::tcm_memn_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_cmsk",        0x0303200a, CEN::tcm_memn_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_abst",        0x03032005, CEN::tcm_memn_abst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_repr",        0x03032006, CEN::tcm_memn_repr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_memn_FARR",        0x03032009, CEN::tcm_memn_FARR,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_time",        0x03031007, CEN::tcm_mems_time,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_regf",        0x03031003, CEN::tcm_mems_regf,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_gptr",        0x03031002, CEN::tcm_mems_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_func",        0x03031000, CEN::tcm_mems_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_lbst",        0x03031004, CEN::tcm_mems_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_cmsk",        0x0303100a, CEN::tcm_mems_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_bndy",        0x03031008, CEN::tcm_mems_bndy,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_abst",        0x03031005, CEN::tcm_mems_abst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_repr",        0x03031006, CEN::tcm_mems_repr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_mems_FARR",        0x03031009, CEN::tcm_mems_FARR,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrn_bndy",        0x03030408, CEN::tcm_ddrn_bndy,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrn_gptr",        0x03030402, CEN::tcm_ddrn_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrn_func",        0x03030400, CEN::tcm_ddrn_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrn_cmsk",        0x0303040a, CEN::tcm_ddrn_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrn_lbst",        0x03030404, CEN::tcm_ddrn_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrs_bndy",        0x03030208, CEN::tcm_ddrs_bndy,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrs_gptr",        0x03030202, CEN::tcm_ddrs_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrs_func",        0x03030200, CEN::tcm_ddrs_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrs_lbst",        0x03030204, CEN::tcm_ddrs_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcm_ddrs_cmsk",        0x0303020a, CEN::tcm_ddrs_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_cmsk",        0x0203400a, CEN::tcn_perv_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_lbst",        0x02034004, CEN::tcn_perv_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_gptr",        0x02034002, CEN::tcn_perv_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_func",        0x02034000, CEN::tcn_perv_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_time",        0x02034007, CEN::tcn_perv_time,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_FARR",        0x02034009, CEN::tcn_perv_FARR,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_abst",        0x02034005, CEN::tcn_perv_abst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_FARR" ,        0x02032009, CEN::tcn_mbi_FARR ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_time" ,        0x02032007, CEN::tcn_mbi_time ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_repr" ,        0x02032006, CEN::tcn_mbi_repr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_abst" ,        0x02032005, CEN::tcn_mbi_abst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_regf" ,        0x02032003, CEN::tcn_mbi_regf ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_gptr" ,        0x02032002, CEN::tcn_mbi_gptr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_func" ,        0x02032000, CEN::tcn_mbi_func ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_cmsk" ,        0x0203200a, CEN::tcn_mbi_cmsk ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbi_lbst" ,        0x02032004, CEN::tcn_mbi_lbst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_dmi_bndy" ,        0x02031008, CEN::tcn_dmi_bndy ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_dmi_gptr" ,        0x02031002, CEN::tcn_dmi_gptr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_dmi_func" ,        0x02031000, CEN::tcn_dmi_func ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_dmi_cmsk" ,        0x0203100a, CEN::tcn_dmi_cmsk ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_dmi_lbst" ,        0x02031004, CEN::tcn_dmi_lbst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_msc_gptr" ,        0x02030802, CEN::tcn_msc_gptr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_msc_func" ,        0x02030800, CEN::tcn_msc_func ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_FARR" ,        0x02030409, CEN::tcn_mbs_FARR ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_time" ,        0x02030407, CEN::tcn_mbs_time ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_repr" ,        0x02030406, CEN::tcn_mbs_repr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_abst" ,        0x02030405, CEN::tcn_mbs_abst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_regf" ,        0x02030403, CEN::tcn_mbs_regf ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_gptr" ,        0x02030402, CEN::tcn_mbs_gptr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_func" ,        0x02030400, CEN::tcn_mbs_func ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_lbst" ,        0x02030404, CEN::tcn_mbs_lbst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_mbs_cmsk" ,        0x0203040a, CEN::tcn_mbs_cmsk ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_cmsk",        0x0203010a, CEN::tcn_refr_cmsk,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_FARR",        0x02030109, CEN::tcn_refr_FARR,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_time",        0x02030107, CEN::tcn_refr_time,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_repr",        0x02030106, CEN::tcn_refr_repr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_abst",        0x02030105, CEN::tcn_refr_abst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_lbst",        0x02030104, CEN::tcn_refr_lbst,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_regf",        0x02030103, CEN::tcn_refr_regf,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_gptr",        0x02030102, CEN::tcn_refr_gptr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_refr_func",        0x02030100, CEN::tcn_refr_func,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tcn_perv_repr",        0x02034006, CEN::tcn_perv_repr,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_func" ,        0x01034000, CEN::tp_perv_func ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_gptr" ,        0x01034002, CEN::tp_perv_gptr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_mode" ,        0x01034001, CEN::tp_perv_mode ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_regf" ,        0x01034003, CEN::tp_perv_regf ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_lbst" ,        0x01034004, CEN::tp_perv_lbst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_abst" ,        0x01034005, CEN::tp_perv_abst ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_repr" ,        0x01034006, CEN::tp_perv_repr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_time" ,        0x01034007, CEN::tp_perv_time ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_bndy" ,        0x01034008, CEN::tp_perv_bndy ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_farr" ,        0x01034009, CEN::tp_perv_farr ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_perv_cmsk" ,        0x0103400a, CEN::tp_perv_cmsk ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pll_func"  ,        0x01030080, CEN::tp_pll_func  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pll_gptr"  ,        0x01030082, CEN::tp_pll_gptr  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_net_func"  ,        0x00032000, CEN::tp_net_func  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_net_gptr"  ,        0x00032002, CEN::tp_net_gptr  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_net_abst"  ,        0x00032005, CEN::tp_net_abst  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pib_func"  ,        0x00031000, CEN::tp_pib_func  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pib_fuse"  ,        0x00031005, CEN::tp_pib_fuse  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pib_gptr"  ,        0x00031002, CEN::tp_pib_gptr  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pll_bndy"  ,        0x01030088, CEN::tp_pll_bndy  ,        CEN_TYPE, RCLS_ROOT_RING | RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_1", 0x01030088, CEN::tp_pll_bndy_bucket_1, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_2", 0x01030088, CEN::tp_pll_bndy_bucket_2, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_3", 0x01030088, CEN::tp_pll_bndy_bucket_3, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_4", 0x01030088, CEN::tp_pll_bndy_bucket_4, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_5", 0x01030088, CEN::tp_pll_bndy_bucket_5, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_6", 0x01030088, CEN::tp_pll_bndy_bucket_6, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_7", 0x01030088, CEN::tp_pll_bndy_bucket_7, CEN_TYPE,                  RCLS_EKB_CEN_RING },
    { "tp_pll_bndy_bucket_8", 0x01030088, CEN::tp_pll_bndy_bucket_8, CEN_TYPE,                  RCLS_EKB_CEN_RING }
};

#else

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    // Not needed in SBE code
};

#endif // __PPE__


// Returns data structures associated with chipletType
void
ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_chipletData);


#endif // _CEN_RINGID_H_
