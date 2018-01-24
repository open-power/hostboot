/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/utils/imageProcs/cen_ringId.C $      */
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

#include <string.h>
#include <common_ringId.H>

namespace CEN_RID
{

#include "cen_ringId.H"

namespace CEN
{

const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"tcm_perv_cmsk", 0x00, 0x01, 0x01, CEN_RING, 0x0303400a},
    {"tcm_perv_lbst", 0x01, 0x01, 0x01, CEN_RING, 0x03034004},
    {"tcm_perv_gptr", 0x02, 0x01, 0x01, CEN_RING, 0x03034002},
    {"tcm_perv_func", 0x03, 0x01, 0x01, CEN_RING, 0x03034000},
    {"tcm_perv_time", 0x04, 0x01, 0x01, CEN_RING, 0x03034007},
    {"tcm_perv_abst", 0x05, 0x01, 0x01, CEN_RING, 0x03034005},
    {"tcm_perv_repr", 0x06, 0x01, 0x01, CEN_RING, 0x03034006},
    {"tcm_perv_FARR", 0x07, 0x01, 0x01, CEN_RING, 0x03034009},
    {"tcm_memn_time", 0x08, 0x01, 0x01, CEN_RING, 0x03032007},
    {"tcm_memn_regf", 0x09, 0x01, 0x01, CEN_RING, 0x03032003},
    {"tcm_memn_gptr", 0x0a, 0x01, 0x01, CEN_RING, 0x03032002},
    {"tcm_memn_func", 0x0b, 0x01, 0x01, CEN_RING, 0x03032000},
    {"tcm_memn_lbst", 0x0c, 0x01, 0x01, CEN_RING, 0x03032004},
    {"tcm_memn_cmsk", 0x0d, 0x01, 0x01, CEN_RING, 0x0303200a},
    {"tcm_memn_abst", 0x0e, 0x01, 0x01, CEN_RING, 0x03032005},
    {"tcm_memn_repr", 0x0f, 0x01, 0x01, CEN_RING, 0x03032006},
    {"tcm_memn_FARR", 0x10, 0x01, 0x01, CEN_RING, 0x03032009},
    {"tcm_mems_time", 0x11, 0x01, 0x01, CEN_RING, 0x03031007},
    {"tcm_mems_regf", 0x12, 0x01, 0x01, CEN_RING, 0x03031003},
    {"tcm_mems_gptr", 0x13, 0x01, 0x01, CEN_RING, 0x03031002},
    {"tcm_mems_func", 0x14, 0x01, 0x01, CEN_RING, 0x03031000},
    {"tcm_mems_lbst", 0x15, 0x01, 0x01, CEN_RING, 0x03031004},
    {"tcm_mems_cmsk", 0x16, 0x01, 0x01, CEN_RING, 0x0303100a},
    {"tcm_mems_bndy", 0x17, 0x01, 0x01, CEN_RING, 0x03031008},
    {"tcm_mems_abst", 0x18, 0x01, 0x01, CEN_RING, 0x03031005},
    {"tcm_mems_repr", 0x19, 0x01, 0x01, CEN_RING, 0x03031006},
    {"tcm_mems_FARR", 0x1a, 0x01, 0x01, CEN_RING, 0x03031009},
    {"tcm_ddrn_bndy", 0x1b, 0x01, 0x01, CEN_RING, 0x03030408},
    {"tcm_ddrn_gptr", 0x1c, 0x01, 0x01, CEN_RING, 0x03030402},
    {"tcm_ddrn_func", 0x1d, 0x01, 0x01, CEN_RING, 0x03030400},
    {"tcm_ddrn_cmsk", 0x1e, 0x01, 0x01, CEN_RING, 0x0303040a},
    {"tcm_ddrn_lbst", 0x1f, 0x01, 0x01, CEN_RING, 0x03030404},
    {"tcm_ddrs_bndy", 0x20, 0x01, 0x01, CEN_RING, 0x03030208},
    {"tcm_ddrs_gptr", 0x21, 0x01, 0x01, CEN_RING, 0x03030202},
    {"tcm_ddrs_func", 0x22, 0x01, 0x01, CEN_RING, 0x03030200},
    {"tcm_ddrs_lbst", 0x23, 0x01, 0x01, CEN_RING, 0x03030204},
    {"tcm_ddrs_cmsk", 0x24, 0x01, 0x01, CEN_RING, 0x0303020a},
    {"tcn_perv_cmsk", 0x25, 0x01, 0x01, CEN_RING, 0x0203400a},
    {"tcn_perv_lbst", 0x26, 0x01, 0x01, CEN_RING, 0x02034004},
    {"tcn_perv_gptr", 0x27, 0x01, 0x01, CEN_RING, 0x02034002},
    {"tcn_perv_func", 0x28, 0x01, 0x01, CEN_RING, 0x02034000},
    {"tcn_perv_time", 0x29, 0x01, 0x01, CEN_RING, 0x02034007},
    {"tcn_perv_FARR", 0x2a, 0x01, 0x01, CEN_RING, 0x02034009},
    {"tcn_perv_abst", 0x2b, 0x01, 0x01, CEN_RING, 0x02034005},
    {"tcn_mbi_FARR" , 0x2c, 0x01, 0x01, CEN_RING, 0x02032009},
    {"tcn_mbi_time" , 0x2d, 0x01, 0x01, CEN_RING, 0x02032007},
    {"tcn_mbi_repr" , 0x2e, 0x01, 0x01, CEN_RING, 0x02032006},
    {"tcn_mbi_abst" , 0x2f, 0x01, 0x01, CEN_RING, 0x02032005},
    {"tcn_mbi_regf" , 0x30, 0x01, 0x01, CEN_RING, 0x02032003},
    {"tcn_mbi_gptr" , 0x31, 0x01, 0x01, CEN_RING, 0x02032002},
    {"tcn_mbi_func" , 0x32, 0x01, 0x01, CEN_RING, 0x02032000},
    {"tcn_mbi_cmsk" , 0x33, 0x01, 0x01, CEN_RING, 0x0203200a},
    {"tcn_mbi_lbst" , 0x34, 0x01, 0x01, CEN_RING, 0x02032004},
    {"tcn_dmi_bndy" , 0x35, 0x01, 0x01, CEN_RING, 0x02031008},
    {"tcn_dmi_gptr" , 0x36, 0x01, 0x01, CEN_RING, 0x02031002},
    {"tcn_dmi_func" , 0x37, 0x01, 0x01, CEN_RING, 0x02031000},
    {"tcn_dmi_cmsk" , 0x38, 0x01, 0x01, CEN_RING, 0x0203100a},
    {"tcn_dmi_lbst" , 0x39, 0x01, 0x01, CEN_RING, 0x02031004},
    {"tcn_msc_gptr" , 0x3a, 0x01, 0x01, CEN_RING, 0x02030802},
    {"tcn_msc_func" , 0x3b, 0x01, 0x01, CEN_RING, 0x02030800},
    {"tcn_mbs_FARR" , 0x3c, 0x01, 0x01, CEN_RING, 0x02030409},
    {"tcn_mbs_time" , 0x3d, 0x01, 0x01, CEN_RING, 0x02030407},
    {"tcn_mbs_repr" , 0x3e, 0x01, 0x01, CEN_RING, 0x02030406},
    {"tcn_mbs_abst" , 0x3f, 0x01, 0x01, CEN_RING, 0x02030405},
    {"tcn_mbs_regf" , 0x40, 0x01, 0x01, CEN_RING, 0x02030403},
    {"tcn_mbs_gptr" , 0x41, 0x01, 0x01, CEN_RING, 0x02030402},
    {"tcn_mbs_func" , 0x42, 0x01, 0x01, CEN_RING, 0x02030400},
    {"tcn_mbs_lbst" , 0x43, 0x01, 0x01, CEN_RING, 0x02030404},
    {"tcn_mbs_cmsk" , 0x44, 0x01, 0x01, CEN_RING, 0x0203040a},
    {"tcn_refr_cmsk", 0x45, 0x01, 0x01, CEN_RING, 0x0203010a},
    {"tcn_refr_FARR", 0x46, 0x01, 0x01, CEN_RING, 0x02030109},
    {"tcn_refr_time", 0x47, 0x01, 0x01, CEN_RING, 0x02030107},
    {"tcn_refr_repr", 0x48, 0x01, 0x01, CEN_RING, 0x02030106},
    {"tcn_refr_abst", 0x49, 0x01, 0x01, CEN_RING, 0x02030105},
    {"tcn_refr_lbst", 0x4a, 0x01, 0x01, CEN_RING, 0x02030104},
    {"tcn_refr_regf", 0x4b, 0x01, 0x01, CEN_RING, 0x02030103},
    {"tcn_refr_gptr", 0x4c, 0x01, 0x01, CEN_RING, 0x02030102},
    {"tcn_refr_func", 0x4d, 0x01, 0x01, CEN_RING, 0x02030100},
    {"tcn_perv_repr", 0x4e, 0x01, 0x01, CEN_RING, 0x02034006},
    {"tp_perv_func" , 0x4f, 0x01, 0x01, CEN_RING, 0x01034000},
    {"tp_perv_gptr" , 0x50, 0x01, 0x01, CEN_RING, 0x01034002},
    {"tp_perv_mode" , 0x51, 0x01, 0x01, CEN_RING, 0x01034001},
    {"tp_perv_regf" , 0x52, 0x01, 0x01, CEN_RING, 0x01034003},
    {"tp_perv_lbst" , 0x53, 0x01, 0x01, CEN_RING, 0x01034004},
    {"tp_perv_abst" , 0x54, 0x01, 0x01, CEN_RING, 0x01034005},
    {"tp_perv_repr" , 0x55, 0x01, 0x01, CEN_RING, 0x01034006},
    {"tp_perv_time" , 0x56, 0x01, 0x01, CEN_RING, 0x01034007},
    {"tp_perv_bndy" , 0x57, 0x01, 0x01, CEN_RING, 0x01034008},
    {"tp_perv_farr" , 0x58, 0x01, 0x01, CEN_RING, 0x01034009},
    {"tp_perv_cmsk" , 0x59, 0x01, 0x01, CEN_RING, 0x0103400a},
    {"tp_pll_func"  , 0x5a, 0x01, 0x01, CEN_RING, 0x01030080},
    {"tp_pll_gptr"  , 0x5b, 0x01, 0x01, CEN_RING, 0x01030082},
    {"tp_net_func"  , 0x5c, 0x01, 0x01, CEN_RING, 0x00032000},
    {"tp_net_gptr"  , 0x5d, 0x01, 0x01, CEN_RING, 0x00032002},
    {"tp_net_abst"  , 0x5e, 0x01, 0x01, CEN_RING, 0x00032005},
    {"tp_pib_func"  , 0x5f, 0x01, 0x01, CEN_RING, 0x00031000},
    {"tp_pib_fuse"  , 0x60, 0x01, 0x01, CEN_RING, 0x00031005},
    {"tp_pib_gptr"  , 0x61, 0x01, 0x01, CEN_RING, 0x00031002},
    {"tp_pll_bndy"  , 0x62, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_1", 0x63, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_2", 0x64, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_3", 0x65, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_4", 0x66, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_5", 0x67, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_6", 0x68, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_7", 0x69, 0x01, 0x01, CEN_RING, 0x01030088},
    {"tp_pll_bndy_bucket_8", 0x6a, 0x01, 0x01, CEN_RING, 0x01030088},
};

const RingVariantOrder RING_VARIANT_ORDER[] = { RV_BASE, RV_RL, UNDEFINED_RING_VARIANT, UNDEFINED_RING_VARIANT };

}; // namespace CEN

}; // namespace CEN_RID


using namespace CEN_RID;

ChipletType_t CEN_RID::ringid_get_chiplet(RingId_t i_ringId)
{
    return RING_PROPERTIES[i_ringId].iv_type;
}

void CEN_RID::ringid_get_chiplet_properties(
    ChipletType_t      i_chipletType,
    ChipletData_t**    o_cpltData,
    GenRingIdList**    o_ringComm,
    GenRingIdList**    o_ringInst,
    RingVariantOrder** o_varOrder,
    uint8_t*           o_varNumb)
{
    switch (i_chipletType)
    {
        case CEN_TYPE :
            *o_cpltData = (ChipletData_t*)   &CEN::g_chipletData;
            *o_ringComm = (GenRingIdList*)    CEN::RING_ID_LIST_COMMON;
            *o_ringInst = NULL;
            *o_varOrder = (RingVariantOrder*) CEN::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        default :
            *o_cpltData = NULL;
            *o_ringComm = NULL;
            *o_ringInst = NULL;
            *o_varOrder = NULL;
            *o_varNumb = 0;
            break;
    }
}

GenRingIdList* CEN_RID::ringid_get_ring_list(RingId_t i_ringId)
{
    ChipletData_t*    l_cpltData;
    GenRingIdList*    l_ringList[2];    // 0: common, 1: instance
    RingVariantOrder* l_varOrder;
    uint8_t           l_varNumb;
    int               i, j, n;

    CEN_RID::ringid_get_chiplet_properties(
        CEN_RID::ringid_get_chiplet(i_ringId),
        &l_cpltData, &l_ringList[0], &l_ringList[1], &l_varOrder, &l_varNumb);

    if (!l_ringList[0])
    {
        return NULL;
    }

    for (j = 0; j < 2; j++)     // 0: common, 1: instance
    {
        n = (j ? l_cpltData->iv_num_instance_rings
             : l_cpltData->iv_num_common_rings);

        for (i = 0; i < n; i++)
        {
            if (!strcmp(l_ringList[j][i].ringName,
                        RING_PROPERTIES[i_ringId].iv_name))
            {
                return &(l_ringList[j][i]);
            }
        }
    }

    return NULL;
}
