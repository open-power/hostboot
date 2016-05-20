/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/utils/imageProcs/p9_ringId.C $                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#include "p9_ringId.H"
#include "p9_ring_identification.H"

namespace PERV
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"perv_fure"                 , 0x00, 0x01, 0x01, "perv_fure_ring"               , NON_VPD_RING, 0,  0x0800000000009000},
    {"perv_gptr"                 , 0x01, 0x01, 0x01, "perv_gptr_ring"               , NON_VPD_RING, 0,  0x0800000000002000},
    {"perv_time"                 , 0x02, 0x01, 0x01, "perv_time_ring"               , NON_VPD_RING, 0,  0x0800000000000100},
    {"occ_fure"                  , 0x03, 0x01, 0x01, "occ_fure_ring"                , NON_VPD_RING, 0,  0x0100000000009000},
    {"occ_gptr"                  , 0x04, 0x01, 0x01, "occ_gptr_ring"                , NON_VPD_RING, 0,  0x0100000000002000},
    {"occ_time"                  , 0x05, 0x01, 0x01, "occ_time_ring"                , NON_VPD_RING, 0,  0x0100000000000100},
    {"perv_ana_func"             , 0x06, 0x01, 0x01, "perv_ana_func_ring"           , NON_VPD_RING, 0,  0x0080000000008000},
    {"perv_ana_gptr"             , 0x07, 0x01, 0x01, "perv_ana_gptr_ring"           , NON_VPD_RING, 0,  0x0080000000002000},
    {"perv_pll_gptr"             , 0x08, 0x01, 0x01, "perv_pll_gptr_ring"           , NON_VPD_PLL_RING, 0,  0x0002000000002000},
    {"perv_pll_bndy_bucket_1"    , 0x09, 0x01, 0x01, "perv_pll_bndy_bucket_1_ring"  , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"perv_pll_bndy_bucket_2"    , 0x0a, 0x01, 0x01, "perv_pll_bndy_bucket_2_ring"  , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"perv_pll_bndy_bucket_3"    , 0x0b, 0x01, 0x01, "perv_pll_bndy_bucket_3_ring"  , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"perv_pll_bndy_bucket_4"    , 0x0c, 0x01, 0x01, "perv_pll_bndy_bucket_4_ring"  , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"perv_pll_bndy_bucket_5"    , 0x0d, 0x01, 0x01, "perv_pll_bndy_bucket_5_ring"  , NON_VPD_PLL_RING, 5,  0x0002000000000080},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"perv_repr"        , 0x0f, 0x01, 0x01, "perv_repr_ring"            , NON_VPD_RING, 0,  0x0800000000000200},
    {"occ_repr"         , 0x10, 0x01, 0x01, "occ_repr_ring"             , NON_VPD_RING, 0,  0x0100000000000200},
};
};
namespace N0
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n0_fure"          , 0x00, 0x02, 0x02, "n0_fure_ring"              , NON_VPD_RING, 0,  0x09C0000000009000},
    {"n0_gptr"          , 0x01, 0x02, 0x02, "n0_gptr_ring"              , NON_VPD_RING, 0,  0x09C0000000002000},
    {"n0_time"          , 0x02, 0x02, 0x02, "n0_time_ring"              , NON_VPD_RING, 0,  0x09C0000000000100},
    {"n0_nx_fure"       , 0x03, 0x02, 0x02, "n0_nx_fure_ring"           , NON_VPD_RING, 0,  0x0400000000009000},
    {"n0_nx_gptr"       , 0x04, 0x02, 0x02, "n0_nx_gptr_ring"           , NON_VPD_RING, 0,  0x0400000000002000},
    {"n0_nx_time"       , 0x05, 0x02, 0x02, "n0_nx_time_ring"           , NON_VPD_RING, 0,  0x0400000000000100},
    {"n0_cxa0_fure"     , 0x06, 0x02, 0x02, "n0_cxa0_fure_ring"         , NON_VPD_RING, 0,  0x0200000000009000},
    {"n0_cxa0_gptr"     , 0x07, 0x02, 0x02, "n0_cxa0_gptr_ring"         , NON_VPD_RING, 0,  0x0200000000002000},
    {"n0_cxa0_time"     , 0x08, 0x02, 0x02, "n0_cxa0_time_ring"         , NON_VPD_RING, 0,  0x0200000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n0_repr"          , 0x09, 0x02, 0x02, "n0_repr_ring"              , NON_VPD_RING, 0,  0x09C0000000000200},
    {"n0_nx_repr"       , 0x0A, 0x02, 0x02, "n0_nx_repr_ring"           , NON_VPD_RING, 0,  0x0400000000000200},
    {"n0_cxa0_repr"     , 0x0B, 0x02, 0x02, "n0_cxa0_repr_ring"         , NON_VPD_RING, 0,  0x0200000000000200},
};
};
namespace N1
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n1_fure"          , 0x00, 0x03, 0x03, "n1_fure_ring"              , NON_VPD_RING, 0,  0x0E00000000009000},
    {"n1_gptr"          , 0x01, 0x03, 0x03, "n1_gptr_ring"              , NON_VPD_RING, 0,  0x0E00000000002000},
    {"n1_time"          , 0x02, 0x03, 0x03, "n1_time_ring"              , NON_VPD_RING, 0,  0x0E00000000000100},
    {"n1_ioo0_fure"     , 0x03, 0x03, 0x03, "n1_ioo0_fure_ring"         , NON_VPD_RING, 0,  0x0100000000009000},
    {"n1_ioo0_gptr"     , 0x04, 0x03, 0x03, "n1_ioo0_gptr_ring"         , NON_VPD_RING, 0,  0x0100000000002000},
    {"n1_ioo0_time"     , 0x05, 0x03, 0x03, "n1_ioo0_time_ring"         , NON_VPD_RING, 0,  0x0100000000000100},
    {"n1_ioo1_fure"     , 0x06, 0x03, 0x03, "n1_ioo1_fure_ring"         , NON_VPD_RING, 0,  0x0080000000009000},
    {"n1_ioo1_gptr"     , 0x07, 0x03, 0x03, "n1_ioo1_gptr_ring"         , NON_VPD_RING, 0,  0x0080000000002000},
    {"n1_ioo1_time"     , 0x08, 0x03, 0x03, "n1_ioo1_time_ring"         , NON_VPD_RING, 0,  0x0080000000000100},
    {"n1_mcs23_fure"    , 0x09, 0x03, 0x03, "n1_mcs23_fure_ring"        , NON_VPD_RING, 0,  0x0040000000009000},
    {"n1_mcs23_gptr"    , 0x0A, 0x03, 0x03, "n1_mcs23_gptr_ring"        , NON_VPD_RING, 0,  0x0040000000002000},
    {"n1_mcs23_time"    , 0x0B, 0x03, 0x03, "n1_mcs23_time_ring"        , NON_VPD_RING, 0,  0x0040000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n1_repr"          , 0x0C, 0x03, 0x03, "n1_repr_ring"              , NON_VPD_RING, 0,  0x0E00000000000200},
    {"n1_ioo0_repr"     , 0x0D, 0x03, 0x03, "n1_ioo0_repr_ring"         , NON_VPD_RING, 0,  0x0100000000000200},
    {"n1_ioo1_repr"     , 0x0E, 0x03, 0x03, "n1_ioo1_repr_ring"         , NON_VPD_RING, 0,  0x0080000000000200},
    {"n1_mcs23_repr"    , 0x0F, 0x03, 0x03, "n1_mcs23_repr_ring"        , NON_VPD_RING, 0,  0x0040000000000200},
};
};
namespace N2
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n2_fure"          , 0x00, 0x04, 0x04, "n2_fure_ring"              , NON_VPD_RING, 0,  0x0BC0000000009000},
    {"n2_gptr"          , 0x01, 0x04, 0x04, "n2_gptr_ring"              , NON_VPD_RING, 0,  0x0BC0000000002000},
    {"n2_time"          , 0x02, 0x04, 0x04, "n2_time_ring"              , NON_VPD_RING, 0,  0x0BC0000000000100},
    {"n2_cxa1_fure"     , 0x03, 0x04, 0x04, "n2_cxa1_fure_ring"         , NON_VPD_RING, 0,  0x0400000000009000},
    {"n2_cxa1_gptr"     , 0x04, 0x04, 0x04, "n2_cxa1_gptr_ring"         , NON_VPD_RING, 0,  0x0400000000002000},
    {"n2_cxa1_time"     , 0x05, 0x04, 0x04, "n2_cxa1_time_ring"         , NON_VPD_RING, 0,  0x0400000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n2_repr"          , 0x06, 0x04, 0x04, "n2_repr_ring"              , NON_VPD_RING, 0,  0x0BC0000000000200},
    {"n2_cxa1_repr"     , 0x07, 0x04, 0x04, "n2_cxa1_repr_ring"         , NON_VPD_RING, 0,  0x0400000000000200},
};
};
namespace N3
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"n3_fure"          , 0x00, 0x05, 0x05, "n3_fure_ring"              , NON_VPD_RING, 0,  0x0EC0000000009000},
    {"n3_gptr"          , 0x01, 0x05, 0x05, "n3_gptr_ring"              , NON_VPD_RING, 0,  0x0EC0000000002000},
    {"n3_time"          , 0x02, 0x05, 0x05, "n3_time_ring"              , NON_VPD_RING, 0,  0x0EC0000000000100},
    {"n3_mcs01_fure"    , 0x03, 0x05, 0x05, "n3_mcs01_fure_ring"        , NON_VPD_RING, 0,  0x0020000000009000},
    {"n3_mcs01_gptr"    , 0x04, 0x05, 0x05, "n3_mcs01_gptr_ring"        , NON_VPD_RING, 0,  0x0020000000002000},
    {"n3_mcs01_time"    , 0x05, 0x05, 0x05, "n3_mcs01_time_ring"        , NON_VPD_RING, 0,  0x0020000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"n3_repr"          , 0x06, 0x05, 0x05, "n3_repr_ring"              , NON_VPD_RING, 0,  0x0EC0000000000200},
    {"n3_mcs01_repr"    , 0x07, 0x05, 0x05, "n3_mcs01_repr-ring"        , NON_VPD_RING, 0,  0x0020000000000200},
};
};
namespace XB
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"xb_fure"                   , 0x00, 0x06, 0x06, "xb_fure_ring"              , NON_VPD_RING, 0,  0x0880000000009000},
    {"xb_gptr"                   , 0x01, 0x06, 0x06, "xb_gptr_ring"              , NON_VPD_RING, 0,  0x0880000000002000},
    {"xb_time"                   , 0x02, 0x06, 0x06, "xb_time_ring"              , NON_VPD_RING, 0,  0x0880000000000100},
    {"xb_io0_fure"               , 0x03, 0x06, 0x06, "xb_io0_fure_ring"          , NON_VPD_RING, 0,  0x0440000000009000},
    {"xb_io0_gptr"               , 0x04, 0x06, 0x06, "xb_io0_gptr_ring"          , NON_VPD_RING, 0,  0x0440000000002000},
    {"xb_io0_time"               , 0x05, 0x06, 0x06, "xb_io0_time_ring"          , NON_VPD_RING, 0,  0x0440000000000100},
    {"xb_io1_fure"               , 0x06, 0x06, 0x06, "xb_io1_fure_ring"          , NON_VPD_RING, 0,  0x0220000000009000},
    {"xb_io1_gptr"               , 0x07, 0x06, 0x06, "xb_io1_gptr_ring"          , NON_VPD_RING, 0,  0x0220000000002000},
    {"xb_io1_time"               , 0x08, 0x06, 0x06, "xb_io1_time_ring"          , NON_VPD_RING, 0,  0x0220000000000100},
    {"xb_io2_fure"               , 0x09, 0x06, 0x06, "xb_io2_fure_ring"          , NON_VPD_RING, 0,  0x0110000000009000},
    {"xb_io2_gptr"               , 0x0A, 0x06, 0x06, "xb_io2_gptr_ring"          , NON_VPD_RING, 0,  0x0110000000002000},
    {"xb_io2_time"               , 0x0B, 0x06, 0x06, "xb_io2_time_ring"          , NON_VPD_RING, 0,  0x0110000000000100},
    {"xb_pll_gptr"               , 0x0C, 0x06, 0x06, "xb_pll_gptr_ring"          , NON_VPD_PLL_RING, 0,  0x0002000000002000},
    {"xb_pll_other"              , 0x0D, 0x06, 0x06, "xb_pll_other_ring"         , NON_VPD_PLL_RING, 0,  0x0002000000005F70},
    {"xb_pll_bndy_bucket_1"      , 0x0E, 0x06, 0x06, "xb_pll_bndy_bucket_1_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"xb_pll_bndy_bucket_2"      , 0x0F, 0x06, 0x06, "xb_pll_bndy_bucket_2_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"xb_pll_bndy_bucket_3"      , 0x10, 0x06, 0x06, "xb_pll_bndy_bucket_3_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"xb_pll_bndy_bucket_4"      , 0x11, 0x06, 0x06, "xb_pll_bndy_bucket_4_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"xb_pll_bndy_bucket_5"      , 0x12, 0x06, 0x06, "xb_pll_bndy_bucket_5_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"xb_repr"          , 0x13, 0x06, 0x06, "xb_repr_ring"              , NON_VPD_RING, 0,  0x0880000000000200},
    {"xb_io0_repr"      , 0x14, 0x06, 0x06, "xb_io0_repr_ring"          , NON_VPD_RING, 0,  0x0440000000000200},
    {"xb_io1_repr"      , 0x15, 0x06, 0x06, "xb_io1_repr_ring"          , NON_VPD_RING, 0,  0x0220000000000200},
    {"xb_io2_repr"      , 0x16, 0x06, 0x06, "xb_io2_repr_ring"          , NON_VPD_RING, 0,  0x0110000000000200},
};
};
namespace MC
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"mc_fure"                   , 0x00, 0x07, 0x07, "mc_fure_ring"              , NON_VPD_RING, 0,  0x0C00000000009000},
    {"mc_gptr"                   , 0x01, 0x07, 0x07, "mc_gptr_ring"              , NON_VPD_RING, 0,  0x0C00000000002000},
    {"mc_time"                   , 0x02, 0x07, 0x07, "mc_time_ring"              , NON_VPD_RING, 0,  0x0C00000000000100},
    {"mc_iom01_fure"             , 0x03, 0x07, 0x07, "mc_iom01_fure_ring"        , NON_VPD_RING, 0,  0x0200000000009000},
    {"mc_iom01_gptr"             , 0x04, 0x07, 0x07, "mc_iom01_gptr_ring"        , NON_VPD_RING, 0,  0x0200000000002000},
    {"mc_iom01_time"             , 0x05, 0x07, 0x07, "mc_iom01_time_ring"        , NON_VPD_RING, 0,  0x0200000000000100},
    {"mc_iom23_fure"             , 0x06, 0x07, 0x07, "mc_iom23_fure_ring"        , NON_VPD_RING, 0,  0x0100000000009000},
    {"mc_iom23_gptr"             , 0x07, 0x07, 0x07, "mc_iom23_gptr_ring"        , NON_VPD_RING, 0,  0x0100000000002000},
    {"mc_iom23_time"             , 0x08, 0x07, 0x07, "mc_iom23_time_ring"        , NON_VPD_RING, 0,  0x0100000000000100},
    {"mc_pll_gptr"               , 0x09, 0x07, 0x07, "mc_pll_gptr_ring"          , NON_VPD_PLL_RING, 0,  0x0002000000002000},
    {"mc_pll_other"              , 0x0A, 0x07, 0x07, "mc_pll_other_ring"         , NON_VPD_PLL_RING, 0,  0x0002000000005F70},
    {"mc_pll_bndy_bucket_1"      , 0x0B, 0x07, 0x07, "mc_pll_bndy_bucket_1_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"mc_pll_bndy_bucket_2"      , 0x0C, 0x07, 0x07, "mc_pll_bndy_bucket_2_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"mc_pll_bndy_bucket_3"      , 0x0D, 0x07, 0x07, "mc_pll_bndy_bucket_3_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"mc_pll_bndy_bucket_4"      , 0x0E, 0x07, 0x07, "mc_pll_bndy_bucket_4_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
    {"mc_pll_bndy_bucket_5"      , 0x0F, 0x07, 0x07, "mc_pll_bndy_bucket_5_ring" , NON_VPD_PLL_RING, 5,  0x0002000000000080},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"mc_repr"          , 0x10, 0x07, 0x08, "mc_repr_ring"              , NON_VPD_RING, 0,  0x0C00000000000200},
    {"mc_iom01_repr"    , 0x11, 0x07, 0x08, "mc_iom01_repr_ring"        , NON_VPD_RING, 0,  0x0200000000000200},
    {"mc_iom23_repr"    , 0x12, 0x07, 0x08, "mc_iom23_repr_ring"        , NON_VPD_RING, 0,  0x0100000000000200},
};
};
namespace OB
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"ob_fure"                   , 0x00, 0x09, 0x09, "ob_fure_ring"              , NON_VPD_RING, 0,  0x0E00000000009000},
    {"ob_gptr"                   , 0x01, 0x09, 0x09, "ob_gptr_ring"              , NON_VPD_RING, 0,  0x0E00000000002000},
    {"ob_time"                   , 0x02, 0x09, 0x09, "ob_time_ring"              , NON_VPD_RING, 0,  0x0E00000000000100},
    {"ob_pll_gptr"               , 0x03, 0x09, 0x09, "ob_pll_gptr_ring"          , NON_VPD_PLL_RING, 0,  0x0002000000008000},
    {"ob_pll_other"              , 0x04, 0x09, 0x09, "ob_pll_other_ring"         , NON_VPD_PLL_RING, 0,  0x0002000000005F70},
    {"ob_pll_bndy_bucket_1"      , 0x05, 0x09, 0x09, "ob_pll_bndy_bucket_1_ring" , NON_VPD_PLL_RING, 0,  0x0002000000008000},
    {"ob_pll_bndy_bucket_2"      , 0x06, 0x09, 0x09, "ob_pll_bndy_bucket_2_ring" , NON_VPD_PLL_RING, 0,  0x0002000000008000},
    {"ob_pll_bndy_bucket_3"      , 0x07, 0x09, 0x09, "ob_pll_bndy_bucket_3_ring" , NON_VPD_PLL_RING, 0,  0x0002000000008000},
    {"ob_pll_bndy_bucket_4"      , 0x08, 0x09, 0x09, "ob_pll_bndy_bucket_4_ring" , NON_VPD_PLL_RING, 0,  0x0002000000008000},
    {"ob_pll_bndy_bucket_5"      , 0x09, 0x09, 0x09, "ob_pll_bndy_bucket_5_ring" , NON_VPD_PLL_RING, 0,  0x0002000000008000},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"ob_repr"          , 0x0a, 0x09, 0x0C, "ob_repr_ring"              , NON_VPD_RING, 0,  0x0E00000000000200},
};
};
namespace PCI0
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci0_fure"            , 0x00, 0x0D, 0x0D, "pci0_fure_ring"        , NON_VPD_RING, 0,  0x0E00000000009000},
    {"pci0_gptr"            , 0x01, 0x0D, 0x0D, "pci0_gptr_ring"        , NON_VPD_RING, 0,  0x0E00000000002000},
    {"pci0_time"            , 0x02, 0x0D, 0x0D, "pci0_time_ring"        , NON_VPD_RING, 0,  0x0E00000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci0_repr"            , 0x03, 0x0D, 0x0D, "pci0_repr_ring"        , NON_VPD_RING, 0,  0x0E00000000000200},
};
};
namespace PCI1
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci1_fure"            , 0x00, 0x0E, 0x0E, "pci1_fure_ring"        , NON_VPD_RING, 0,  0x0F00000000009000},
    {"pci1_gptr"            , 0x01, 0x0E, 0x0E, "pci1_gptr_ring"        , NON_VPD_RING, 0,  0x0F00000000002000},
    {"pci1_time"            , 0x02, 0x0E, 0x0E, "pci1_time_ring"        , NON_VPD_RING, 0,  0x0F00000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci1_repr"            , 0x03, 0x0E, 0x0E, "pci1_repr_ring"        , NON_VPD_RING, 0,  0x0F00000000000200},
};
};
namespace PCI2
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"pci2_fure"            , 0x00, 0x0F, 0x0F, "pci2_fure_ring"        , NON_VPD_RING, 0,  0x0F80000000009000},
    {"pci2_gptr"            , 0x01, 0x0F, 0x0F, "pci2_gptr_ring"        , NON_VPD_RING, 0,  0x0F80000000002000},
    {"pci2_time"            , 0x02, 0x0F, 0x0F, "pci2_time_ring"        , NON_VPD_RING, 0,  0x0F80000000000100},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"pci2_repr"            , 0x03, 0x0F, 0x0F, "pci2_repr_ring"        , NON_VPD_RING, 0,  0x0F80000000000200},
};
};
namespace EQ
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    {"eq_fure"                   , 0x00, 0x10, 0x10, "eq_fure_ring"              , NON_VPD_RING, 0,  0x0C10000000009000},
    {"eq_gptr"                   , 0x01, 0x10, 0x10, "eq_gptr_ring"              , NON_VPD_RING, 0,  0x0C10000000004000},
    {"eq_time"                   , 0x02, 0x10, 0x10, "eq_time_ring"              , NON_VPD_RING, 0,  0x0C10000000000100},
    {"ex_l3_fure"                , 0x03, 0x10, 0x10, "ex_l3_fure_ring"           , NON_VPD_RING, 0,  0x0200000000009000},
    {"ex_l3_gptr"                , 0x04, 0x10, 0x10, "ex_l3_gptr_ring"           , NON_VPD_RING, 0,  0x0200000000004000},
    {"ex_l3_time"                , 0x05, 0x10, 0x10, "ex_l3_time_ring"           , NON_VPD_RING, 0,  0x0200000000000100},
    {"ex_l2_fure"                , 0x06, 0x10, 0x10, "ex_l2_fure_ring"           , NON_VPD_RING, 0,  0x0080000000009000},
    {"ex_l2_gptr"                , 0x07, 0x10, 0x10, "ex_l2_gptr_ring"           , NON_VPD_RING, 0,  0x0080000000004000},
    {"ex_l2_time"                , 0x08, 0x10, 0x10, "ex_l2_time_ring"           , NON_VPD_RING, 0,  0x0080000000000100},
    {"ex_l3_refr_fure"           , 0x09, 0x10, 0x10, "ex_l3_refr_fure_ring"      , NON_VPD_RING, 0,  0x0008000000009000},
    {"ex_l3_refr_gptr"           , 0x0A, 0x10, 0x10, "ex_l3_refr_gptr_ring"      , NON_VPD_RING, 0,  0x0008000000004000},
    {"ex_l3_refr_time"           , 0x0B, 0x10, 0x10, "ex_l3_refr_time_ring"      , NON_VPD_RING, 0,  0x0008000000000100},
    {"eq_ana_func"               , 0x0C, 0x10, 0x10, "eq_ana_func_ring"          , NON_VPD_RING, 0,  0x002000000000C000},
    {"eq_ana_gptr"               , 0x0D, 0x10, 0x10, "eq_ana_gptr_ring"          , NON_VPD_RING, 0,  0x0020000000002000},
    {"eq_dpll_func"              , 0x0E, 0x10, 0x10, "eq_dpll_func_ring"         , NON_VPD_PLL_RING, 0,  0x0002000000000080},
    {"eq_dpll_gptr"              , 0x13, 0x10, 0x10, "eq_dpll_gptr_ring"         , NON_VPD_PLL_RING, 0,  0x0002000000002000},
    {"eq_dpll_other"             , 0x14, 0x10, 0x10, "eq_dpll_other_ring"        , NON_VPD_PLL_RING, 0,  0x0002000000005F70},
    {"eq_ana_bndy"               , 0x15, 0x10, 0x10, "eq_ana_bndy_ring"          , NON_VPD_PLL_RING, 0,  0x0002000000000080},

};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    {"eq_repr"          , 0x16, 0x10, 0x15, "eq_repr_ring"              , NON_VPD_RING, 0,  0x0237516800000512},
    {"ex_l3_repr"       , 0x17, 0x10, 0x15, "ex_l3_repr_ring"           , NON_VPD_RING, 0,  0x3355443200000512},
    {"ex_l2_repr"       , 0x18, 0x10, 0x15, "ex_l2_repr_ring"           , NON_VPD_RING, 0,  0x0838860800000512},
    {"ex_l3_refr_repr"  , 0x19, 0x10, 0x15, "ex_l3_refr_repr_ring"      , NON_VPD_RING, 0,  0x0052428800000512},
};
};
namespace EC
{
const GenRingIdList RING_ID_LIST_COMMON[] =
{
    /*   ringName   rinngId chipIdMin chipIdMax  ringNameImg        mvpdKeyword               */
    { "ec_func"         , 0x00, 0x20, 0x20, "ec_func_ring",              NON_VPD_RING, 0,  0x0E00000000009000},
    { "ec_time"         , 0x01, 0x20, 0x20, "ec_time_ring",              NON_VPD_RING, 0,  0x0E00000000000100},
    { "ec_gptr"         , 0x02, 0x20, 0x20, "ec_gptr_ring",              NON_VPD_RING, 0,  0x0E00000000002000},
    { "ec_mode"         , 0x03, 0x20, 0x20, "ec_mode_ring",              NON_VPD_RING, 0,  0x0E00000000004000},
};
const GenRingIdList RING_ID_LIST_INSTANCE[] =
{
    { "ec_repr"         , 0x04, 0x20, 0x37, "ec_repr_ring",              NON_VPD_RING, 0,  0x0E00000000000200},
};
};