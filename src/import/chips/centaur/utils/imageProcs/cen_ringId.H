/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/utils/imageProcs/cen_ringId.H $      */
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

#ifndef _CEN_RINGID_H_
#define _CEN_RINGID_H_

#include <stdint.h>
#include <stddef.h>
#include <common_ringId.H>
#include <cen_ring_id.h>

enum CHIPLET_TYPE
{
    CEN_TYPE,
    CEN_NOOF_CHIPLETS
};

namespace CEN
{
extern const GenRingIdList RING_ID_LIST_COMMON[];
extern const RingVariantOrder RING_VARIANT_ORDER[];

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
    0x01,         // Centaur chiplet ID
    NUM_RING_IDS, // Num of common rings for Centaur chiplet
    0,            // Num of instance rings for Centaur chiplet
    0,
    2,            // Num of ring variants: BASE, RL
};
}; // namespace CEN

#ifndef __PPE__

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { CEN::tcm_perv_cmsk, "tcm_perv_cmsk", CEN_TYPE },
    { CEN::tcm_perv_lbst, "tcm_perv_lbst", CEN_TYPE },
    { CEN::tcm_perv_gptr, "tcm_perv_gptr", CEN_TYPE },
    { CEN::tcm_perv_func, "tcm_perv_func", CEN_TYPE },
    { CEN::tcm_perv_time, "tcm_perv_time", CEN_TYPE },
    { CEN::tcm_perv_abst, "tcm_perv_abst", CEN_TYPE },
    { CEN::tcm_perv_repr, "tcm_perv_repr", CEN_TYPE },
    { CEN::tcm_perv_FARR, "tcm_perv_FARR", CEN_TYPE },
    { CEN::tcm_memn_time, "tcm_memn_time", CEN_TYPE },
    { CEN::tcm_memn_regf, "tcm_memn_regf", CEN_TYPE },
    { CEN::tcm_memn_gptr, "tcm_memn_gptr", CEN_TYPE },
    { CEN::tcm_memn_func, "tcm_memn_func", CEN_TYPE },
    { CEN::tcm_memn_lbst, "tcm_memn_lbst", CEN_TYPE },
    { CEN::tcm_memn_cmsk, "tcm_memn_cmsk", CEN_TYPE },
    { CEN::tcm_memn_abst, "tcm_memn_abst", CEN_TYPE },
    { CEN::tcm_memn_repr, "tcm_memn_repr", CEN_TYPE },
    { CEN::tcm_memn_FARR, "tcm_memn_FARR", CEN_TYPE },
    { CEN::tcm_mems_time, "tcm_mems_time", CEN_TYPE },
    { CEN::tcm_mems_regf, "tcm_mems_regf", CEN_TYPE },
    { CEN::tcm_mems_gptr, "tcm_mems_gptr", CEN_TYPE },
    { CEN::tcm_mems_func, "tcm_mems_func", CEN_TYPE },
    { CEN::tcm_mems_lbst, "tcm_mems_lbst", CEN_TYPE },
    { CEN::tcm_mems_cmsk, "tcm_mems_cmsk", CEN_TYPE },
    { CEN::tcm_mems_bndy, "tcm_mems_bndy", CEN_TYPE },
    { CEN::tcm_mems_abst, "tcm_mems_abst", CEN_TYPE },
    { CEN::tcm_mems_repr, "tcm_mems_repr", CEN_TYPE },
    { CEN::tcm_mems_FARR, "tcm_mems_FARR", CEN_TYPE },
    { CEN::tcm_ddrn_bndy, "tcm_ddrn_bndy", CEN_TYPE },
    { CEN::tcm_ddrn_gptr, "tcm_ddrn_gptr", CEN_TYPE },
    { CEN::tcm_ddrn_func, "tcm_ddrn_func", CEN_TYPE },
    { CEN::tcm_ddrn_cmsk, "tcm_ddrn_cmsk", CEN_TYPE },
    { CEN::tcm_ddrn_lbst, "tcm_ddrn_lbst", CEN_TYPE },
    { CEN::tcm_ddrs_bndy, "tcm_ddrs_bndy", CEN_TYPE },
    { CEN::tcm_ddrs_gptr, "tcm_ddrs_gptr", CEN_TYPE },
    { CEN::tcm_ddrs_func, "tcm_ddrs_func", CEN_TYPE },
    { CEN::tcm_ddrs_lbst, "tcm_ddrs_lbst", CEN_TYPE },
    { CEN::tcm_ddrs_cmsk, "tcm_ddrs_cmsk", CEN_TYPE },
    { CEN::tcn_perv_cmsk, "tcn_perv_cmsk", CEN_TYPE },
    { CEN::tcn_perv_lbst, "tcn_perv_lbst", CEN_TYPE },
    { CEN::tcn_perv_gptr, "tcn_perv_gptr", CEN_TYPE },
    { CEN::tcn_perv_func, "tcn_perv_func", CEN_TYPE },
    { CEN::tcn_perv_time, "tcn_perv_time", CEN_TYPE },
    { CEN::tcn_perv_FARR, "tcn_perv_FARR", CEN_TYPE },
    { CEN::tcn_perv_abst, "tcn_perv_abst", CEN_TYPE },
    { CEN::tcn_mbi_FARR , "tcn_mbi_FARR" , CEN_TYPE },
    { CEN::tcn_mbi_time , "tcn_mbi_time" , CEN_TYPE },
    { CEN::tcn_mbi_repr , "tcn_mbi_repr" , CEN_TYPE },
    { CEN::tcn_mbi_abst , "tcn_mbi_abst" , CEN_TYPE },
    { CEN::tcn_mbi_regf , "tcn_mbi_regf" , CEN_TYPE },
    { CEN::tcn_mbi_gptr , "tcn_mbi_gptr" , CEN_TYPE },
    { CEN::tcn_mbi_func , "tcn_mbi_func" , CEN_TYPE },
    { CEN::tcn_mbi_cmsk , "tcn_mbi_cmsk" , CEN_TYPE },
    { CEN::tcn_mbi_lbst , "tcn_mbi_lbst" , CEN_TYPE },
    { CEN::tcn_dmi_bndy , "tcn_dmi_bndy" , CEN_TYPE },
    { CEN::tcn_dmi_gptr , "tcn_dmi_gptr" , CEN_TYPE },
    { CEN::tcn_dmi_func , "tcn_dmi_func" , CEN_TYPE },
    { CEN::tcn_dmi_cmsk , "tcn_dmi_cmsk" , CEN_TYPE },
    { CEN::tcn_dmi_lbst , "tcn_dmi_lbst" , CEN_TYPE },
    { CEN::tcn_msc_gptr , "tcn_msc_gptr" , CEN_TYPE },
    { CEN::tcn_msc_func , "tcn_msc_func" , CEN_TYPE },
    { CEN::tcn_mbs_FARR , "tcn_mbs_FARR" , CEN_TYPE },
    { CEN::tcn_mbs_time , "tcn_mbs_time" , CEN_TYPE },
    { CEN::tcn_mbs_repr , "tcn_mbs_repr" , CEN_TYPE },
    { CEN::tcn_mbs_abst , "tcn_mbs_abst" , CEN_TYPE },
    { CEN::tcn_mbs_regf , "tcn_mbs_regf" , CEN_TYPE },
    { CEN::tcn_mbs_gptr , "tcn_mbs_gptr" , CEN_TYPE },
    { CEN::tcn_mbs_func , "tcn_mbs_func" , CEN_TYPE },
    { CEN::tcn_mbs_lbst , "tcn_mbs_lbst" , CEN_TYPE },
    { CEN::tcn_mbs_cmsk , "tcn_mbs_cmsk" , CEN_TYPE },
    { CEN::tcn_refr_cmsk, "tcn_refr_cmsk", CEN_TYPE },
    { CEN::tcn_refr_FARR, "tcn_refr_FARR", CEN_TYPE },
    { CEN::tcn_refr_time, "tcn_refr_time", CEN_TYPE },
    { CEN::tcn_refr_repr, "tcn_refr_repr", CEN_TYPE },
    { CEN::tcn_refr_abst, "tcn_refr_abst", CEN_TYPE },
    { CEN::tcn_refr_lbst, "tcn_refr_lbst", CEN_TYPE },
    { CEN::tcn_refr_regf, "tcn_refr_regf", CEN_TYPE },
    { CEN::tcn_refr_gptr, "tcn_refr_gptr", CEN_TYPE },
    { CEN::tcn_refr_func, "tcn_refr_func", CEN_TYPE },
    { CEN::tcn_perv_repr, "tcn_perv_repr", CEN_TYPE },
    { CEN::tp_perv_func , "tp_perv_func" , CEN_TYPE },
    { CEN::tp_perv_gptr , "tp_perv_gptr" , CEN_TYPE },
    { CEN::tp_perv_mode , "tp_perv_mode" , CEN_TYPE },
    { CEN::tp_perv_regf , "tp_perv_regf" , CEN_TYPE },
    { CEN::tp_perv_lbst , "tp_perv_lbst" , CEN_TYPE },
    { CEN::tp_perv_abst , "tp_perv_abst" , CEN_TYPE },
    { CEN::tp_perv_repr , "tp_perv_repr" , CEN_TYPE },
    { CEN::tp_perv_time , "tp_perv_time" , CEN_TYPE },
    { CEN::tp_perv_bndy , "tp_perv_bndy" , CEN_TYPE },
    { CEN::tp_perv_farr , "tp_perv_farr" , CEN_TYPE },
    { CEN::tp_perv_cmsk , "tp_perv_cmsk" , CEN_TYPE },
    { CEN::tp_pll_func  , "tp_pll_func"  , CEN_TYPE },
    { CEN::tp_pll_gptr  , "tp_pll_gptr"  , CEN_TYPE },
    { CEN::tp_net_func  , "tp_net_func"  , CEN_TYPE },
    { CEN::tp_net_gptr  , "tp_net_gptr"  , CEN_TYPE },
    { CEN::tp_net_abst  , "tp_net_abst"  , CEN_TYPE },
    { CEN::tp_pib_func  , "tp_pib_func"  , CEN_TYPE },
    { CEN::tp_pib_fuse  , "tp_pib_fuse"  , CEN_TYPE },
    { CEN::tp_pib_gptr  , "tp_pib_gptr"  , CEN_TYPE },
    { CEN::tp_pll_bndy  , "tp_pll_bndy"  , CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_1, "tp_pll_bndy_bucket_1", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_2, "tp_pll_bndy_bucket_2", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_3, "tp_pll_bndy_bucket_3", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_4, "tp_pll_bndy_bucket_4", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_5, "tp_pll_bndy_bucket_5", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_6, "tp_pll_bndy_bucket_6", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_7, "tp_pll_bndy_bucket_7", CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_8, "tp_pll_bndy_bucket_8", CEN_TYPE }
};

#else

static const RingProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { CEN::tcm_perv_cmsk, CEN_TYPE },
    { CEN::tcm_perv_lbst, CEN_TYPE },
    { CEN::tcm_perv_gptr, CEN_TYPE },
    { CEN::tcm_perv_func, CEN_TYPE },
    { CEN::tcm_perv_time, CEN_TYPE },
    { CEN::tcm_perv_abst, CEN_TYPE },
    { CEN::tcm_perv_repr, CEN_TYPE },
    { CEN::tcm_perv_FARR, CEN_TYPE },
    { CEN::tcm_memn_time, CEN_TYPE },
    { CEN::tcm_memn_regf, CEN_TYPE },
    { CEN::tcm_memn_gptr, CEN_TYPE },
    { CEN::tcm_memn_func, CEN_TYPE },
    { CEN::tcm_memn_lbst, CEN_TYPE },
    { CEN::tcm_memn_cmsk, CEN_TYPE },
    { CEN::tcm_memn_abst, CEN_TYPE },
    { CEN::tcm_memn_repr, CEN_TYPE },
    { CEN::tcm_memn_FARR, CEN_TYPE },
    { CEN::tcm_mems_time, CEN_TYPE },
    { CEN::tcm_mems_regf, CEN_TYPE },
    { CEN::tcm_mems_gptr, CEN_TYPE },
    { CEN::tcm_mems_func, CEN_TYPE },
    { CEN::tcm_mems_lbst, CEN_TYPE },
    { CEN::tcm_mems_cmsk, CEN_TYPE },
    { CEN::tcm_mems_bndy, CEN_TYPE },
    { CEN::tcm_mems_abst, CEN_TYPE },
    { CEN::tcm_mems_repr, CEN_TYPE },
    { CEN::tcm_mems_FARR, CEN_TYPE },
    { CEN::tcm_ddrn_bndy, CEN_TYPE },
    { CEN::tcm_ddrn_gptr, CEN_TYPE },
    { CEN::tcm_ddrn_func, CEN_TYPE },
    { CEN::tcm_ddrn_cmsk, CEN_TYPE },
    { CEN::tcm_ddrn_lbst, CEN_TYPE },
    { CEN::tcm_ddrs_bndy, CEN_TYPE },
    { CEN::tcm_ddrs_gptr, CEN_TYPE },
    { CEN::tcm_ddrs_func, CEN_TYPE },
    { CEN::tcm_ddrs_lbst, CEN_TYPE },
    { CEN::tcm_ddrs_cmsk, CEN_TYPE },
    { CEN::tcn_perv_cmsk, CEN_TYPE },
    { CEN::tcn_perv_lbst, CEN_TYPE },
    { CEN::tcn_perv_gptr, CEN_TYPE },
    { CEN::tcn_perv_func, CEN_TYPE },
    { CEN::tcn_perv_time, CEN_TYPE },
    { CEN::tcn_perv_FARR, CEN_TYPE },
    { CEN::tcn_perv_abst, CEN_TYPE },
    { CEN::tcn_mbi_FARR , CEN_TYPE },
    { CEN::tcn_mbi_time , CEN_TYPE },
    { CEN::tcn_mbi_repr , CEN_TYPE },
    { CEN::tcn_mbi_abst , CEN_TYPE },
    { CEN::tcn_mbi_regf , CEN_TYPE },
    { CEN::tcn_mbi_gptr , CEN_TYPE },
    { CEN::tcn_mbi_func , CEN_TYPE },
    { CEN::tcn_mbi_cmsk , CEN_TYPE },
    { CEN::tcn_mbi_lbst , CEN_TYPE },
    { CEN::tcn_dmi_bndy , CEN_TYPE },
    { CEN::tcn_dmi_gptr , CEN_TYPE },
    { CEN::tcn_dmi_func , CEN_TYPE },
    { CEN::tcn_dmi_cmsk , CEN_TYPE },
    { CEN::tcn_dmi_lbst , CEN_TYPE },
    { CEN::tcn_msc_gptr , CEN_TYPE },
    { CEN::tcn_msc_func , CEN_TYPE },
    { CEN::tcn_mbs_FARR , CEN_TYPE },
    { CEN::tcn_mbs_time , CEN_TYPE },
    { CEN::tcn_mbs_repr , CEN_TYPE },
    { CEN::tcn_mbs_abst , CEN_TYPE },
    { CEN::tcn_mbs_regf , CEN_TYPE },
    { CEN::tcn_mbs_gptr , CEN_TYPE },
    { CEN::tcn_mbs_func , CEN_TYPE },
    { CEN::tcn_mbs_lbst , CEN_TYPE },
    { CEN::tcn_mbs_cmsk , CEN_TYPE },
    { CEN::tcn_refr_cmsk, CEN_TYPE },
    { CEN::tcn_refr_FARR, CEN_TYPE },
    { CEN::tcn_refr_time, CEN_TYPE },
    { CEN::tcn_refr_repr, CEN_TYPE },
    { CEN::tcn_refr_abst, CEN_TYPE },
    { CEN::tcn_refr_lbst, CEN_TYPE },
    { CEN::tcn_refr_regf, CEN_TYPE },
    { CEN::tcn_refr_gptr, CEN_TYPE },
    { CEN::tcn_refr_func, CEN_TYPE },
    { CEN::tcn_perv_repr, CEN_TYPE },
    { CEN::tp_perv_func , CEN_TYPE },
    { CEN::tp_perv_gptr , CEN_TYPE },
    { CEN::tp_perv_mode , CEN_TYPE },
    { CEN::tp_perv_regf , CEN_TYPE },
    { CEN::tp_perv_lbst , CEN_TYPE },
    { CEN::tp_perv_abst , CEN_TYPE },
    { CEN::tp_perv_repr , CEN_TYPE },
    { CEN::tp_perv_time , CEN_TYPE },
    { CEN::tp_perv_bndy , CEN_TYPE },
    { CEN::tp_perv_farr , CEN_TYPE },
    { CEN::tp_perv_cmsk , CEN_TYPE },
    { CEN::tp_pll_func  , CEN_TYPE },
    { CEN::tp_pll_gptr  , CEN_TYPE },
    { CEN::tp_net_func  , CEN_TYPE },
    { CEN::tp_net_gptr  , CEN_TYPE },
    { CEN::tp_net_abst  , CEN_TYPE },
    { CEN::tp_pib_func  , CEN_TYPE },
    { CEN::tp_pib_fuse  , CEN_TYPE },
    { CEN::tp_pib_gptr  , CEN_TYPE },
    { CEN::tp_pll_bndy  , CEN_TYPE },
    { CEN::tp_pib_repr  , CEN_TYPE },
    { CEN::tp_vitl      , CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_1, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_2, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_3, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_4, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_5, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_6, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_7, CEN_TYPE },
    { CEN::tp_pll_bndy_bucket_8, CEN_TYPE }
};

#endif // __PPE__



// returns our own chiplet enum value for this ringId
ChipletType_t
ringid_get_chiplet(RingId_t i_ringId);

// returns data structures defined for chiplet type
// as determined by ringId
void
ringid_get_chiplet_properties(
    ChipletType_t      i_chiplet,
    ChipletData_t**    o_cpltData,
    GenRingIdList**    o_ringComm,
    GenRingIdList**    o_ringInst,
    RingVariantOrder** o_varOrder,
    uint8_t*           o_varNumb);

// returns properties of a ring as determined by ringId
GenRingIdList*
ringid_get_ring_list(RingId_t i_ringId);


#endif // _CEN_RINGID_H_
