/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/utils/imageProcs/p9_ringId.C $            */
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

#include <string.h>
#include <common_ringId.H>

namespace P9_RID
{

#include "p9_ringId.H"


namespace PERV
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"perv_fure"             , 0x00, 0x01, 0x01, EKB_RING    , 0x0103400F},
    {"perv_gptr"             , 0x01, 0x01, 0x01, EKB_RING    , 0x01034002},
    {"perv_time"             , 0x02, 0x01, 0x01, VPD_RING    , 0x01034007},
    {"occ_fure"              , 0x03, 0x01, 0x01, EKB_RING    , 0x0103080F},
    {"occ_gptr"              , 0x04, 0x01, 0x01, EKB_RING    , 0x01030802},
    {"occ_time"              , 0x05, 0x01, 0x01, VPD_RING    , 0x01030807},
    {"perv_ana_func"         , 0x06, 0x01, 0x01, EKB_RING    , 0x01030400},
    {"perv_ana_gptr"         , 0x07, 0x01, 0x01, EKB_RING    , 0x01030402},
    {"perv_pll_gptr"         , 0x08, 0x01, 0x01, EKB_RING    , 0x01030012},
    {"perv_pll_bndy_bucket_1", 0x09, 0x01, 0x01, EKB_RING    , 0x01030018},
    {"perv_pll_bndy_bucket_2", 0x0a, 0x01, 0x01, EKB_RING    , 0x01030018},
    {"perv_pll_bndy_bucket_3", 0x0b, 0x01, 0x01, EKB_RING    , 0x01030018},
    {"perv_pll_bndy_bucket_4", 0x0c, 0x01, 0x01, EKB_RING    , 0x01030018},
    {"perv_pll_bndy_bucket_5", 0x0d, 0x01, 0x01, EKB_RING    , 0x01030018},
    {"perv_pll_func"         , 0x0e, 0x01, 0x01, EKB_RING    , 0x01030010},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"perv_repr"             , 0x0f, 0x01, 0x01, VPD_RING    , 0x01034006},
    {"occ_repr"              , 0x10, 0x01, 0x01, VPD_RING    , 0x01030806},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace N0
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n0_fure"             , 0x00, 0x02, 0x02, EKB_RING    , 0x02034E0F},
    {"n0_gptr"             , 0x01, 0x02, 0x02, EKB_RING    , 0x02034E02},
    {"n0_time"             , 0x02, 0x02, 0x02, VPD_RING    , 0x02034E07},
    {"n0_nx_fure"          , 0x03, 0x02, 0x02, EKB_RING    , 0x0203200F},
    {"n0_nx_gptr"          , 0x04, 0x02, 0x02, EKB_RING    , 0x02032002},
    {"n0_nx_time"          , 0x05, 0x02, 0x02, VPD_RING    , 0x02032007},
    {"n0_cxa0_fure"        , 0x06, 0x02, 0x02, EKB_RING    , 0x0203100F},
    {"n0_cxa0_gptr"        , 0x07, 0x02, 0x02, EKB_RING    , 0x02031002},
    {"n0_cxa0_time"        , 0x08, 0x02, 0x02, VPD_RING    , 0x02031007},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n0_repr"             , 0x09, 0x02, 0x02, VPD_RING    , 0x02034E06},
    {"n0_nx_repr"          , 0x0a, 0x02, 0x02, VPD_RING    , 0x02032006},
    {"n0_cxa0_repr"        , 0x0b, 0x02, 0x02, VPD_RING    , 0x02031006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID};
};


namespace N1
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n1_fure"             , 0x00, 0x03, 0x03, EKB_RING    , 0x0303700F},
    {"n1_gptr"             , 0x01, 0x03, 0x03, EKB_RING    , 0x03037002},
    {"n1_time"             , 0x02, 0x03, 0x03, VPD_RING    , 0x03037007},
    {"n1_ioo0_fure"        , 0x03, 0x03, 0x03, EKB_RING    , 0x0303080F},
    {"n1_ioo0_gptr"        , 0x04, 0x03, 0x03, EKB_RING    , 0x03030802},
    {"n1_ioo0_time"        , 0x05, 0x03, 0x03, VPD_RING    , 0x03030807},
    {"n1_ioo1_fure"        , 0x06, 0x03, 0x03, EKB_RING    , 0x0303040F},
    {"n1_ioo1_gptr"        , 0x07, 0x03, 0x03, EKB_RING    , 0x03030402},
    {"n1_ioo1_time"        , 0x08, 0x03, 0x03, VPD_RING    , 0x03030407},
    {"n1_mcs23_fure"       , 0x09, 0x03, 0x03, EKB_RING    , 0x0303020F},
    {"n1_mcs23_gptr"       , 0x0a, 0x03, 0x03, EKB_RING    , 0x03030202},
    {"n1_mcs23_time"       , 0x0b, 0x03, 0x03, VPD_RING    , 0x03030207},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n1_repr"             , 0x0c, 0x03, 0x03, VPD_RING    , 0x03037006},
    {"n1_ioo0_repr"        , 0x0d, 0x03, 0x03, VPD_RING    , 0x03030806},
    {"n1_ioo1_repr"        , 0x0e, 0x03, 0x03, VPD_RING    , 0x03030406},
    {"n1_mcs23_repr"       , 0x0f, 0x03, 0x03, VPD_RING    , 0x03030206},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID};
};


namespace N2
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n2_fure"             , 0x00, 0x04, 0x04, EKB_RING    , 0x04035C0F},
    {"n2_gptr"             , 0x01, 0x04, 0x04, EKB_RING    , 0x04035C02},
    {"n2_time"             , 0x02, 0x04, 0x04, VPD_RING    , 0x04035C07},
    {"n2_cxa1_fure"        , 0x03, 0x04, 0x04, EKB_RING    , 0x0403200F},
    {"n2_cxa1_gptr"        , 0x04, 0x04, 0x04, EKB_RING    , 0x04032002},
    {"n2_cxa1_time"        , 0x05, 0x04, 0x04, VPD_RING    , 0x04032007},
    {"n2_psi_fure"         , 0x06, 0x04, 0x04, EKB_RING    , 0x0403020F},
    {"n2_psi_gptr"         , 0x07, 0x04, 0x04, EKB_RING    , 0x04030202},
    {"n2_psi_time"         , 0x08, 0x04, 0x04, VPD_RING    , 0x04030207},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n2_repr"             , 0x09, 0x04, 0x04, VPD_RING    , 0x04035C06},
    {"n2_cxa1_repr"        , 0x0a, 0x04, 0x04, VPD_RING    , 0x04032006},
    {"n2_psi_repr"         , 0x0b, 0x04, 0x04, VPD_RING    , 0x04030206},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace N3
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n3_fure"             , 0x00, 0x05, 0x05, EKB_RING    , 0x0503660F},
    {"n3_gptr"             , 0x01, 0x05, 0x05, EKB_RING    , 0x05037602},
    {"n3_time"             , 0x02, 0x05, 0x05, VPD_RING    , 0x05037607},
    {"n3_mcs01_fure"       , 0x03, 0x05, 0x05, EKB_RING    , 0x0503010F},
    {"n3_mcs01_gptr"       , 0x04, 0x05, 0x05, EKB_RING    , 0x05030102},
    {"n3_mcs01_time"       , 0x05, 0x05, 0x05, VPD_RING    , 0x05030107},
    {"n3_np_fure"          , 0x06, 0x05, 0x05, EKB_RING    , 0x0503080F},
    {"n3_np_gptr"          , 0x07, 0x05, 0x05, EKB_RING    , 0x05030802},
    {"n3_np_time"          , 0x08, 0x05, 0x05, VPD_RING    , 0x05030807},
    {"n3_br_fure"          , 0x09, 0x05, 0x05, EKB_RING    , 0x0503100F},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n3_repr"             , 0x0a, 0x05, 0x05, VPD_RING    , 0x05037606},
    {"n3_mcs01_repr"       , 0x0b, 0x05, 0x05, VPD_RING    , 0x05030106},
    {"n3_np_repr"          , 0x0c, 0x05, 0x05, VPD_RING    , 0x05030806},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace XB
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"xb_fure"             , 0x00, 0x06, 0x06, EKB_RING    , 0x0603440F},
    {"xb_gptr"             , 0x01, 0x06, 0x06, EKB_RING    , 0x06034402},
    {"xb_time"             , 0x02, 0x06, 0x06, VPD_RING    , 0x06034407},
    {"xb_io0_fure"         , 0x03, 0x06, 0x06, EKB_RING    , 0x0603220F},
    {"xb_io0_gptr"         , 0x04, 0x06, 0x06, EKB_RING    , 0x06032202},
    {"xb_io0_time"         , 0x05, 0x06, 0x06, VPD_RING    , 0x06032207},
    {"xb_io1_fure"         , 0x06, 0x06, 0x06, EKB_RING    , 0x0603110F},
    {"xb_io1_gptr"         , 0x07, 0x06, 0x06, EKB_RING    , 0x06031102},
    {"xb_io1_time"         , 0x08, 0x06, 0x06, VPD_RING    , 0x06031107},
    {"xb_io2_fure"         , 0x09, 0x06, 0x06, EKB_RING    , 0x0603088F},
    {"xb_io2_gptr"         , 0x0a, 0x06, 0x06, EKB_RING    , 0x06030882},
    {"xb_io2_time"         , 0x0b, 0x06, 0x06, VPD_RING    , 0x06030887},
    {"xb_pll_gptr"         , 0x0c, 0x06, 0x06, EKB_RING    , 0x06030012},
    {"xb_pll_bndy"         , 0x0d, 0x06, 0x06, EKB_RING    , 0x06030018},
    {"xb_pll_func"         , 0x0e, 0x06, 0x06, EKB_RING    , 0x06030010},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"xb_repr"             , 0x13, 0x06, 0x06, VPD_RING    , 0x06034406},
    {"xb_io0_repr"         , 0x14, 0x06, 0x06, VPD_RING    , 0x06032206},
    {"xb_io1_repr"         , 0x15, 0x06, 0x06, VPD_RING    , 0x06031106},
    {"xb_io2_repr"         , 0x16, 0x06, 0x06, VPD_RING    , 0x06030886},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace MC
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"mc_fure"             , 0x00, 0x07, 0x07, EKB_RING    , 0x0703600F},
    {"mc_gptr"             , 0x01, 0x07, 0x07, EKB_RING    , 0x07036002},
    {"mc_time"             , 0x02, 0x07, 0x07, VPD_RING    , 0x07036007},
    {"mc_iom01_fure"       , 0x03, 0x07, 0x07, EKB_RING    , 0x0703100F},
    {"mc_iom01_gptr"       , 0x04, 0x07, 0x07, EKB_RING    , 0x07031002},
    {"mc_iom01_time"       , 0x05, 0x07, 0x07, VPD_RING    , 0x07031007},
    {"mc_iom23_fure"       , 0x06, 0x07, 0x07, EKB_RING    , 0x0703080F},
    {"mc_iom23_gptr"       , 0x07, 0x07, 0x07, EKB_RING    , 0x07030802},
    {"mc_iom23_time"       , 0x08, 0x07, 0x07, VPD_RING    , 0x07030807},
    {"mc_pll_gptr"         , 0x09, 0x07, 0x07, EKB_RING    , 0x07030012},
    {"mc_pll_bndy_bucket_1", 0x0a, 0x07, 0x07, EKB_RING    , 0x07030018},
    {"mc_pll_bndy_bucket_2", 0x0b, 0x07, 0x07, EKB_RING    , 0x07030018},
    {"mc_pll_bndy_bucket_3", 0x0c, 0x07, 0x07, EKB_RING    , 0x07030018},
    {"mc_pll_bndy_bucket_4", 0x0d, 0x07, 0x07, EKB_RING    , 0x07030018},
    {"mc_pll_bndy_bucket_5", 0x0e, 0x07, 0x07, EKB_RING    , 0x07030018},
    {"mc_pll_func"         , 0x0f, 0x07, 0x07, EKB_RING    , 0x07030010},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"mc_repr"             , 0x10, 0x07, 0x08, VPD_RING    , 0x07036006},
    {"mc_iom01_repr"       , 0x11, 0x07, 0x08, VPD_RING    , 0x07031006},
    {"mc_iom23_repr"       , 0x12, 0x07, 0x08, VPD_RING    , 0x07030806},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace OB0
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"ob0_pll_bndy_bucket_1" , 0x00, 0x09, 0x09, EKB_RING    , 0x09030018},
    {"ob0_pll_bndy_bucket_2" , 0x01, 0x09, 0x09, EKB_RING    , 0x09030018},
    {"ob0_gptr"              , 0x02, 0x09, 0x09, EKB_RING    , 0x09037002},
    {"ob0_time"              , 0x03, 0x09, 0x09, VPD_RING    , 0x09037007},
    {"ob0_pll_gptr"          , 0x04, 0x09, 0x09, EKB_RING    , 0x09030012},
    {"ob0_fure"              , 0x05, 0x09, 0x09, EKB_RING    , 0x0903700F},
    {"ob0_pll_bndy_bucket_3" , 0x06, 0x09, 0x09, EKB_RING    , 0x09030018},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"ob0_repr"              , 0x07, 0x09, 0x09, VPD_RING    , 0x09037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace OB1
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"ob1_pll_bndy_bucket_1" , 0x00, 0x0a, 0x0a, EKB_RING    , 0x0A030018},
    {"ob1_pll_bndy_bucket_2" , 0x01, 0x0a, 0x0a, EKB_RING    , 0x0A030018},
    {"ob1_gptr"              , 0x02, 0x0a, 0x0a, EKB_RING    , 0x0A037002},
    {"ob1_time"              , 0x03, 0x0a, 0x0a, VPD_RING    , 0x0A037007},
    {"ob1_pll_gptr"          , 0x04, 0x0a, 0x0a, EKB_RING    , 0x0A030012},
    {"ob1_fure"              , 0x05, 0x0a, 0x0a, EKB_RING    , 0x0A03700F},
    {"ob1_pll_bndy_bucket_3" , 0x06, 0x0a, 0x0a, EKB_RING    , 0x0A030018},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"ob1_repr"              , 0x07, 0x0a, 0x0a, VPD_RING    , 0x0A037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace OB2
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"ob2_pll_bndy_bucket_1" , 0x00, 0x0b, 0x0b, EKB_RING    , 0x0B030018},
    {"ob2_pll_bndy_bucket_2" , 0x01, 0x0b, 0x0b, EKB_RING    , 0x0B030018},
    {"ob2_gptr"              , 0x02, 0x0b, 0x0b, EKB_RING    , 0x0B037002},
    {"ob2_time"              , 0x03, 0x0b, 0x0b, VPD_RING    , 0x0B037007},
    {"ob2_pll_gptr"          , 0x04, 0x0b, 0x0b, EKB_RING    , 0x0B030012},
    {"ob2_fure"              , 0x05, 0x0b, 0x0b, EKB_RING    , 0x0B03700F},
    {"ob2_pll_bndy_bucket_3" , 0x06, 0x0b, 0x0b, EKB_RING    , 0x0B030018},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"ob2_repr"              , 0x07, 0x0b, 0x0b, VPD_RING    , 0x0B037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace OB3
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"ob3_pll_bndy_bucket_1" , 0x00, 0x0c, 0x0c, EKB_RING    , 0x0C030018},
    {"ob3_pll_bndy_bucket_2" , 0x01, 0x0c, 0x0c, EKB_RING    , 0x0C030018},
    {"ob3_gptr"              , 0x02, 0x0c, 0x0c, EKB_RING    , 0x0C037002},
    {"ob3_time"              , 0x03, 0x0c, 0x0c, VPD_RING    , 0x0C037007},
    {"ob3_pll_gptr"          , 0x04, 0x0c, 0x0c, EKB_RING    , 0x0C030012},
    {"ob3_fure"              , 0x05, 0x0c, 0x0c, EKB_RING    , 0x0C03700F},
    {"ob3_pll_bndy_bucket_3" , 0x06, 0x0c, 0x0c, EKB_RING    , 0x0C030018},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"ob3_repr"              , 0x07, 0x0c, 0x0c, VPD_RING    , 0x0C037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace PCI0
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci0_fure"           , 0x00, 0x0d, 0x0d, EKB_RING    , 0x0D03700F},
    {"pci0_gptr"           , 0x01, 0x0d, 0x0d, EKB_RING    , 0x0D037002},
    {"pci0_time"           , 0x02, 0x0d, 0x0d, VPD_RING    , 0x0D037007},
    {"pci0_pll_bndy"       , 0x03, 0x0d, 0x0d, EKB_RING    , 0x0D030018},
    {"pci0_pll_gptr"       , 0x04, 0x0d, 0x0d, EKB_RING    , 0x0D030012},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci0_repr"           , 0x05, 0x0d, 0x0d, VPD_RING    , 0x0D037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace PCI1
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci1_fure"           , 0x00, 0x0e, 0x0e, EKB_RING    , 0x0E03780F},
    {"pci1_gptr"           , 0x01, 0x0e, 0x0e, EKB_RING    , 0x0E037802},
    {"pci1_time"           , 0x02, 0x0e, 0x0e, VPD_RING    , 0x0E037807},
    {"pci1_pll_bndy"       , 0x03, 0x0e, 0x0e, EKB_RING    , 0x0E030018},
    {"pci1_pll_gptr"       , 0x04, 0x0e, 0x0e, EKB_RING    , 0x0E030012},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci1_repr"           , 0x05, 0x0e, 0x0e, VPD_RING    , 0x0E037806},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace PCI2
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci2_fure"           , 0x00, 0x0f, 0x0f, EKB_RING    , 0x0F037C0F},
    {"pci2_gptr"           , 0x01, 0x0f, 0x0f, EKB_RING    , 0x0F037C02},
    {"pci2_time"           , 0x02, 0x0f, 0x0f, VPD_RING    , 0x0F037C07},
    {"pci2_pll_bndy"       , 0x03, 0x0f, 0x0f, EKB_RING    , 0x0F030018},
    {"pci2_pll_gptr"       , 0x04, 0x0f, 0x0f, EKB_RING    , 0x0F030012},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci2_repr"           , 0x05, 0x0F, 0x0F, VPD_RING    , 0x0F037C06},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, RL, NOT_VALID };
};


namespace EQ
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"eq_fure"                    , 0x00, 0x10, 0x10, EKB_RING    , 0x1003608F},
    {"eq_gptr"                    , 0x01, 0x10, 0x10, EKB_RING    , 0x10036082},
    {"eq_time"                    , 0x02, 0x10, 0x10, VPD_RING    , 0x10036087},
    {"eq_inex"                    , 0x03, 0x10, 0x10, EKB_RING    , 0x1003608B},
    {"ex_l3_fure"                 , 0x04, 0x10, 0x10, EKB_RING    , 0x1003100F},
    {"ex_l3_gptr"                 , 0x05, 0x10, 0x10, EKB_RING    , 0x10031002},
    {"ex_l3_time"                 , 0x06, 0x10, 0x10, VPD_RING    , 0x10031007},
    {"ex_l2_mode"                 , 0x07, 0x10, 0x10, EKB_RING    , 0x10030401},
    {"ex_l2_fure"                 , 0x08, 0x10, 0x10, EKB_RING    , 0x1003040F},
    {"ex_l2_gptr"                 , 0x09, 0x10, 0x10, EKB_RING    , 0x10030402},
    {"ex_l2_time"                 , 0x0a, 0x10, 0x10, VPD_RING    , 0x10030407},
    {"ex_l3_refr_fure"            , 0x0b, 0x10, 0x10, EKB_RING    , 0x1003004F},
    {"ex_l3_refr_gptr"            , 0x0c, 0x10, 0x10, EKB_RING    , 0x10030042},
    {"eq_ana_func"                , 0x0d, 0x10, 0x10, EKB_RING    , 0x10030100},
    {"eq_ana_gptr"                , 0x0e, 0x10, 0x10, EKB_RING    , 0x10030102},
    {"eq_dpll_func"               , 0x0f, 0x10, 0x10, EKB_RING    , 0x10030010},
    {"eq_dpll_gptr"               , 0x10, 0x10, 0x10, EKB_RING    , 0x10030012},
    {"eq_dpll_mode"               , 0x11, 0x10, 0x10, EKB_RING    , 0x10030011},
    {"eq_ana_bndy_bucket_0"       , 0x12, 0x10, 0x10, EKB_RING    , 0x10030108},
    {"eq_ana_bndy_bucket_1"       , 0x13, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_2"       , 0x14, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_3"       , 0x15, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_4"       , 0x16, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_5"       , 0x17, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_6"       , 0x18, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_7"       , 0x19, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_8"       , 0x1a, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_9"       , 0x1b, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_10"      , 0x1c, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_11"      , 0x1d, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_12"      , 0x1e, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_13"      , 0x1f, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_14"      , 0x20, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_15"      , 0x21, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_16"      , 0x22, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_17"      , 0x23, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_18"      , 0x24, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_19"      , 0x25, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_20"      , 0x26, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_21"      , 0x27, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_22"      , 0x28, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_23"      , 0x29, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_24"      , 0x2a, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_25"      , 0x2b, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_l3dcc"   , 0x2c, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_mode"                , 0x2d, 0x10, 0x10, EKB_RING    , 0x10030101},
    {"eq_ana_bndy_bucket_26"      , 0x2e, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_27"      , 0x2f, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_28"      , 0x30, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_29"      , 0x31, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_30"      , 0x32, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_31"      , 0x33, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_32"      , 0x34, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_33"      , 0x35, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_34"      , 0x36, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_35"      , 0x37, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_36"      , 0x38, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_37"      , 0x39, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_38"      , 0x3a, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_39"      , 0x3b, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_40"      , 0x3c, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_ana_bndy_bucket_41"      , 0x3d, 0x10, 0x10, EKB_FSM_RING, 0x10030108},
    {"eq_inex_bucket_1"           , 0x3e, 0x10, 0x10, EKB_RING    , 0x1003608B},
    {"eq_inex_bucket_2"           , 0x3f, 0x10, 0x10, EKB_RING    , 0x1003608B},
    {"eq_inex_bucket_3"           , 0x40, 0x10, 0x10, EKB_RING    , 0x1003608B},
    {"eq_inex_bucket_4"           , 0x41, 0x10, 0x10, EKB_RING    , 0x1003608B},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"eq_repr"                    , 0x42, 0x10, 0x1b, VPD_RING    , 0x10036086},
    {"ex_l3_repr"                 , 0x43, 0x10, 0x1b, VPD_RING    , 0x10031006},
    {"ex_l2_repr"                 , 0x44, 0x10, 0x1b, VPD_RING    , 0x10030406},
    {"ex_l3_refr_repr"            , 0x45, 0x10, 0x1b, VPD_RING    , 0x10030046},
    {"ex_l3_refr_time"            , 0x46, 0x10, 0x1b, VPD_RING    , 0x10030047},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, CC, RL };
};


namespace EC
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    { "ec_func"            , 0x00, 0x20, 0x20, EKB_STUMPED_RING , 0x2003700F},
    { "ec_gptr"            , 0x01, 0x20, 0x20, EKB_RING         , 0x20037002},
    { "ec_time"            , 0x02, 0x20, 0x20, VPD_RING         , 0x20037007},
    { "ec_mode"            , 0x03, 0x20, 0x20, EKB_RING         , 0x20037001},
    { "ec_abst"            , 0x04, 0x20, 0x20, EKB_RING         , 0x20037005},
    { "ec_cmsk"            , 0xFF, 0xFF, 0xFF, EKB_CMSK_RING    , 0x2003700A},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    { "ec_repr"            , 0x05, 0x20, 0x37, VPD_RING    , 0x20037006},
};
const RingVariantOrder RING_VARIANT_ORDER[] = { BASE, CC, RL };
};


}; // namespace P9_RID


using namespace P9_RID;

ChipletType_t P9_RID::ringid_get_chiplet(RingId_t i_ringId)
{
    return RING_PROPERTIES[i_ringId].iv_type;
}

void P9_RID::ringid_get_chiplet_properties(
    ChipletType_t      i_chiplet,
    ChipletData_t**    o_cpltData,
    GenRingIdList**    o_ringComm,
    GenRingIdList**    o_ringInst,
    RingVariantOrder** o_varOrder,
    uint8_t*           o_varNumb)
{
    switch (i_chiplet)
    {
        case PERV_TYPE :
            *o_cpltData = (ChipletData_t*)   &PERV::g_chipletData;
            *o_ringComm = (GenRingIdList*)    PERV::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    PERV::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) PERV::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case N0_TYPE :
            *o_cpltData = (ChipletData_t*)   &N0::g_chipletData;
            *o_ringComm = (GenRingIdList*)    N0::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    N0::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) N0::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case N1_TYPE :
            *o_cpltData = (ChipletData_t*)   &N1::g_chipletData;
            *o_ringComm = (GenRingIdList*)    N1::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    N1::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) N1::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case N2_TYPE :
            *o_cpltData = (ChipletData_t*)   &N2::g_chipletData;
            *o_ringComm = (GenRingIdList*)    N2::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    N2::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) N2::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case N3_TYPE :
            *o_cpltData = (ChipletData_t*)   &N3::g_chipletData;
            *o_ringComm = (GenRingIdList*)    N3::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    N3::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) N3::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case XB_TYPE :
            *o_cpltData = (ChipletData_t*)   &XB::g_chipletData;
            *o_ringComm = (GenRingIdList*)    XB::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    XB::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) XB::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case MC_TYPE :
            *o_cpltData = (ChipletData_t*)   &MC::g_chipletData;
            *o_ringComm = (GenRingIdList*)    MC::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    MC::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) MC::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case OB0_TYPE :
            *o_cpltData = (ChipletData_t*)   &OB0::g_chipletData;
            *o_ringComm = (GenRingIdList*)    OB0::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    OB0::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) OB0::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case OB1_TYPE :
            *o_cpltData = (ChipletData_t*)   &OB1::g_chipletData;
            *o_ringComm = (GenRingIdList*)    OB1::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    OB1::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) OB1::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case OB2_TYPE :
            *o_cpltData = (ChipletData_t*)   &OB2::g_chipletData;
            *o_ringComm = (GenRingIdList*)    OB2::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    OB2::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) OB2::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case OB3_TYPE :
            *o_cpltData = (ChipletData_t*)   &OB3::g_chipletData;
            *o_ringComm = (GenRingIdList*)    OB3::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    OB3::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) OB3::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case PCI0_TYPE :
            *o_cpltData = (ChipletData_t*)   &PCI0::g_chipletData;
            *o_ringComm = (GenRingIdList*)    PCI0::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    PCI0::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) PCI0::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case PCI1_TYPE :
            *o_cpltData = (ChipletData_t*)   &PCI1::g_chipletData;
            *o_ringComm = (GenRingIdList*)    PCI1::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    PCI1::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) PCI1::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case PCI2_TYPE :
            *o_cpltData = (ChipletData_t*)   &PCI2::g_chipletData;
            *o_ringComm = (GenRingIdList*)    PCI2::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    PCI2::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) PCI2::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case EQ_TYPE :
            *o_cpltData = (ChipletData_t*)   &EQ::g_chipletData;
            *o_ringComm = (GenRingIdList*)    EQ::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    EQ::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) EQ::RING_VARIANT_ORDER;
            *o_varNumb  = (*(*o_cpltData)).iv_num_ring_variants;
            break;

        case EC_TYPE :
            *o_cpltData = (ChipletData_t*)   &EC::g_chipletData;
            *o_ringComm = (GenRingIdList*)    EC::RING_ID_LIST_COMMON;
            *o_ringInst = (GenRingIdList*)    EC::RING_ID_LIST_INSTANCE;
            *o_varOrder = (RingVariantOrder*) EC::RING_VARIANT_ORDER;
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

GenRingIdList* P9_RID::ringid_get_ring_list(RingId_t i_ringId)
{
    ChipletData_t*    l_cpltData;
    GenRingIdList*    l_ringList[2];    // 0: common, 1: instance
    RingVariantOrder* l_varOrder;
    uint8_t           l_varNumb;
    int               i, j, n;

    P9_RID::ringid_get_chiplet_properties(
        P9_RID::ringid_get_chiplet(i_ringId),
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
