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
#ifndef _CEN_RINGID_ENUM_H_
#define _CEN_RINGID_ENUM_H_

///
/// @enum RingID
/// @brief Enumeration of Ring ID values. These values are used to traverse
///        an image having Ring Containers.
// NOTE: Do not change the numbering, the sequence or add new constants to
//       the below enum, unless you know the effect it has on the traversing
//       of the image for Ring Containers.
enum RingID
{
    // temp centaur rings
    tcm_perv_cmsk,
    tcm_perv_lbst,
    tcm_perv_gptr,
    tcm_perv_func,
    tcm_perv_time,
    tcm_perv_abst,
    tcm_perv_repr,
    tcm_perv_FARR,
    tcm_memn_time,
    tcm_memn_regf,
    tcm_memn_gptr,
    tcm_memn_func,
    tcm_memn_lbst,
    tcm_memn_cmsk,
    tcm_memn_abst,
    tcm_memn_repr,
    tcm_memn_FARR,
    tcm_mems_time,
    tcm_mems_regf,
    tcm_mems_gptr,
    tcm_mems_func,
    tcm_mems_lbst,
    tcm_mems_cmsk,
    tcm_mems_bndy,
    tcm_mems_abst,
    tcm_mems_repr,
    tcm_mems_FARR,
    tcm_ddrn_bndy,
    tcm_ddrn_gptr,
    tcm_ddrn_func,
    tcm_ddrn_cmsk,
    tcm_ddrn_lbst,
    tcm_ddrs_bndy,
    tcm_ddrs_gptr,
    tcm_ddrs_func,
    tcm_ddrs_lbst,
    tcm_ddrs_cmsk,
    tcn_perv_cmsk,
    tcn_perv_lbst,
    tcn_perv_gptr,
    tcn_perv_func,
    tcn_perv_time,
    tcn_perv_FARR,
    tcn_perv_abst,
    tcn_mbi_FARR,
    tcn_mbi_time,
    tcn_mbi_repr,
    tcn_mbi_abst,
    tcn_mbi_regf,
    tcn_mbi_gptr,
    tcn_mbi_func,
    tcn_mbi_cmsk,
    tcn_mbi_lbst,
    tcn_dmi_bndy,
    tcn_dmi_gptr,
    tcn_dmi_func,
    tcn_dmi_cmsk,
    tcn_dmi_lbst,
    tcn_msc_gptr,
    tcn_msc_func,
    tcn_mbs_FARR,
    tcn_mbs_time,
    tcn_mbs_repr,
    tcn_mbs_abst,
    tcn_mbs_regf,
    tcn_mbs_gptr,
    tcn_mbs_func,
    tcn_mbs_lbst,
    tcn_mbs_cmsk,
    tcn_refr_cmsk,
    tcn_refr_FARR,
    tcn_refr_time,
    tcn_refr_repr,
    tcn_refr_abst,
    tcn_refr_lbst,
    tcn_refr_regf,
    tcn_refr_gptr,
    tcn_refr_func,
    tcn_perv_repr,
    tp_perv_func,
    tp_perv_gptr,
    tp_perv_mode,
    tp_perv_regf,
    tp_perv_lbst,
    tp_perv_abst,
    tp_perv_repr,
    tp_perv_time,
    tp_perv_bndy,
    tp_perv_farr,
    tp_perv_cmsk,
    tp_pll_func,
    tp_pll_gptr,
    tp_net_func,
    tp_net_gptr,
    tp_net_abst,
    tp_pib_func,
    tp_pib_fuse,
    tp_pib_gptr,
    tp_pll_bndy,
    tp_pib_repr,
    tp_vitl,
    NUM_RING_IDS // This shoud always be the last constant
}; // end of enum RingID

#endif  // _P9_RINGID_ENUM_H_
