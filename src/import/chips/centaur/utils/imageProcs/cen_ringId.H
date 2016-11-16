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
#include <cen_ring_id.h>

enum CHIPLET_TYPE
{
    PERV_TYPE,
};


static const uint8_t INVALID_RING = 0xFF;

// This structure is needed for mapping a RingID to it's corresponding name.
// The names will be used by the build scripts when generating the TOR.
struct ringProperties_t
{
    uint8_t iv_torOffSet;
    char iv_name[50];
    CHIPLET_TYPE iv_type;
};

static const ringProperties_t RING_PROPERTIES[NUM_RING_IDS] =
{
    { 0                                  , "tcm_perv_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_lbst"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_gptr"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_func"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_time"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_abst"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_repr"               , PERV_TYPE  },
    { 0                                  , "tcm_perv_FARR"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_time"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_regf"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_gptr"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_func"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_lbst"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_abst"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_repr"               , PERV_TYPE  },
    { 0                                  , "tcm_memn_FARR"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_time"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_regf"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_gptr"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_func"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_lbst"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_bndy"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_abst"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_repr"               , PERV_TYPE  },
    { 0                                  , "tcm_mems_FARR"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrn_bndy"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrn_gptr"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrn_func"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrn_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrn_lbst"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrs_bndy"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrs_gptr"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrs_func"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrs_lbst"               , PERV_TYPE  },
    { 0                                  , "tcm_ddrs_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_lbst"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_gptr"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_func"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_time"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_FARR"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_abst"               , PERV_TYPE  },
    { 0                                  , "tcn_mbi_FARR"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_time"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_repr"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_abst"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_regf"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_gptr"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_func"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_cmsk"                , PERV_TYPE  },
    { 0                                  , "tcn_mbi_lbst"                , PERV_TYPE  },
    { 0                                  , "tcn_dmi_bndy"                , PERV_TYPE  },
    { 0                                  , "tcn_dmi_gptr"                , PERV_TYPE  },
    { 0                                  , "tcn_dmi_func"                , PERV_TYPE  },
    { 0                                  , "tcn_dmi_cmsk"                , PERV_TYPE  },
    { 0                                  , "tcn_dmi_lbst"                , PERV_TYPE  },
    { 0                                  , "tcn_msc_gptr"                , PERV_TYPE  },
    { 0                                  , "tcn_msc_func"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_FARR"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_time"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_repr"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_abst"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_regf"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_gptr"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_func"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_lbst"                , PERV_TYPE  },
    { 0                                  , "tcn_mbs_cmsk"                , PERV_TYPE  },
    { 0                                  , "tcn_refr_cmsk"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_FARR"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_time"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_repr"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_abst"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_lbst"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_regf"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_gptr"               , PERV_TYPE  },
    { 0                                  , "tcn_refr_func"               , PERV_TYPE  },
    { 0                                  , "tcn_perv_repr"               , PERV_TYPE  },
    { 0                                  , "tp_perv_func"                , PERV_TYPE  },
    { 0                                  , "tp_perv_gptr"                , PERV_TYPE  },
    { 0                                  , "tp_perv_mode"                , PERV_TYPE  },
    { 0                                  , "tp_perv_regf"                , PERV_TYPE  },
    { 0                                  , "tp_perv_lbst"                , PERV_TYPE  },
    { 0                                  , "tp_perv_abst"                , PERV_TYPE  },
    { 0                                  , "tp_perv_repr"                , PERV_TYPE  },
    { 0                                  , "tp_perv_time"                , PERV_TYPE  },
    { 0                                  , "tp_perv_bndy"                , PERV_TYPE  },
    { 0                                  , "tp_perv_farr"                , PERV_TYPE  },
    { 0                                  , "tp_perv_cmsk"                , PERV_TYPE  },
    { 0                                  , "tp_pll_func"                 , PERV_TYPE  },
    { 0                                  , "tp_pll_gptr"                 , PERV_TYPE  },
    { 0                                  , "tp_net_func"                 , PERV_TYPE  },
    { 0                                  , "tp_net_gptr"                 , PERV_TYPE  },
    { 0                                  , "tp_net_abst"                 , PERV_TYPE  },
    { 0                                  , "tp_pib_func"                 , PERV_TYPE  },
    { 0                                  , "tp_pib_fuse"                 , PERV_TYPE  },
    { 0                                  , "tp_pib_gptr"                 , PERV_TYPE  },
    { 0                                  , "tp_pll_bndy"                 , PERV_TYPE  },
    { 0                                  , "tp_pib_repr"                 , PERV_TYPE  },
    { 0                                  , "tp_vitl"                     , PERV_TYPE  },
};
#endif
