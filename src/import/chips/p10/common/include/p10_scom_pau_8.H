/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pau_8.H $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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

#ifndef __PPE_HCODE__
    #include "proc_scomt.H"
#endif

#ifndef __p10_scom_pau_8_H_
#define __p10_scom_pau_8_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pau
{
#endif


static const uint64_t AME_AME2_MISC_DEBUG_CONFIG0 = 0x10010be4ull;

static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B0_CSEL = 0;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B0_CSEL = 1;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B0_SEL = 2;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B0_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B0_SEL = 6;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B0_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B1_CSEL = 10;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B1_CSEL = 11;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B1_SEL = 12;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B1_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B1_SEL = 16;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B1_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B2_CSEL = 20;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B2_CSEL = 21;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B2_SEL = 22;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B2_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B2_SEL = 26;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B2_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B3_CSEL = 30;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B3_CSEL = 31;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B3_SEL = 32;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B3_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B3_SEL = 36;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B3_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B4_CSEL = 40;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B4_CSEL = 41;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B4_SEL = 42;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B4_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B4_SEL = 46;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B4_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_B5_CSEL = 50;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_B5_CSEL = 51;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B5_SEL = 52;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL0_B5_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B5_SEL = 56;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__CL1_B5_SEL_LEN = 4;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__RESERVED0 = 60;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0__RESERVED0_LEN = 2;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_0_ENABLE = 62;
static const uint32_t AME_AME2_MISC_DEBUG_CONFIG0_1_ENABLE = 63;
// pau/reg00010.H

static const uint64_t AME_ATL_MISC_CERR_RPT_HOLD = 0x10010bf8ull;

static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_WBO_UE = 33;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_PCT_UE = 34;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_INJB_UE = 35;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_DATO_UE = 36;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_DATO_SUE = 37;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_AUXT_CE = 38;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_LISB_CE = 39;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_RSPT_CE = 40;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_UCTBL_CE = 41;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_CFH_CE = 42;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_SMF_CE = 43;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_LPTBL_CE = 44;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_WBO_CE = 45;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_PCT_CE = 46;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_INJB_CE = 47;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_DATO_CE = 48;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_CREG_PE = 49;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_FLMAP_PE = 50;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_AUXT_UE = 51;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_LISB_UE = 52;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_RSPT_UE = 53;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_UCTBL_UE = 54;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_CFH_UE = 55;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_SMF_UE = 56;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_LPTBL_UE = 57;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_PBC_UFL = 58;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_EAC_UFL = 59;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_EAC_TOUT = 60;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_UEXP_XRS = 61;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_RD_FAILED = 62;
static const uint32_t AME_ATL_MISC_CERR_RPT_HOLD_WR_FAILED = 63;
// pau/reg00010.H

static const uint64_t AME_ATL_MISC_CERR_RPT_INFO = 0x10010bffull;

static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_ECC_AMM = 27;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_ECC_AMM_LEN = 3;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_ECC_BANKS = 30;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_ECC_BANKS_LEN = 4;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_TAG = 34;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_TAG_LEN = 16;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_SMID = 50;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_SMID_LEN = 8;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_RCODE = 58;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_RCODE_LEN = 4;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_DPART = 62;
static const uint32_t AME_ATL_MISC_CERR_RPT_INFO_XFAIL_DPART_LEN = 2;
// pau/reg00010.H

static const uint64_t AME_ATL_MISC_CONFIG1 = 0x10010bf1ull;

static const uint32_t AME_ATL_MISC_CONFIG1_1_RESERVED = 0;
static const uint32_t AME_ATL_MISC_CONFIG1_1_RESERVED_LEN = 12;
static const uint32_t AME_ATL_MISC_CONFIG1__LS_CRD = 12;
static const uint32_t AME_ATL_MISC_CONFIG1__LS_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__VC2_CRD = 14;
static const uint32_t AME_ATL_MISC_CONFIG1__VC2_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__INJ_CRD = 16;
static const uint32_t AME_ATL_MISC_CONFIG1__INJ_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__XLT_CRD = 18;
static const uint32_t AME_ATL_MISC_CONFIG1__XLT_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__DMR_CRD = 20;
static const uint32_t AME_ATL_MISC_CONFIG1__DMR_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__AMM_UC_CRD = 22;
static const uint32_t AME_ATL_MISC_CONFIG1__AMM_UC_CRD_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__CPL_CRD = 24;
static const uint32_t AME_ATL_MISC_CONFIG1__CPL_CRD_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__RSO_CRD = 27;
static const uint32_t AME_ATL_MISC_CONFIG1__RSO_CRD_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__RQO_CRD = 30;
static const uint32_t AME_ATL_MISC_CONFIG1__RQO_CRD_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__XSL_ITR_CRD = 33;
static const uint32_t AME_ATL_MISC_CONFIG1__XSL_ITR_CRD_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__XSL_XLT_CRD = 36;
static const uint32_t AME_ATL_MISC_CONFIG1__XSL_XLT_CRD_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__EAC_TLIM = 39;
static const uint32_t AME_ATL_MISC_CONFIG1__EAC_TLIM_LEN = 4;
static const uint32_t AME_ATL_MISC_CONFIG1__CF_HASH = 43;
static const uint32_t AME_ATL_MISC_CONFIG1__CF_HASH_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__XL_HASH = 45;
static const uint32_t AME_ATL_MISC_CONFIG1__XL_HASH_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__VC_PEND_THRESH1 = 47;
static const uint32_t AME_ATL_MISC_CONFIG1__VC_PEND_THRESH1_LEN = 4;
static const uint32_t AME_ATL_MISC_CONFIG1__VC_PEND_THRESH2 = 51;
static const uint32_t AME_ATL_MISC_CONFIG1__VC_PEND_THRESH2_LEN = 4;
static const uint32_t AME_ATL_MISC_CONFIG1__COSM_UC_WAIT = 55;
static const uint32_t AME_ATL_MISC_CONFIG1__COSM_UC_WAIT_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__XRTY_WAIT_BASE = 57;
static const uint32_t AME_ATL_MISC_CONFIG1__XRTY_WAIT_BASE_LEN = 2;
static const uint32_t AME_ATL_MISC_CONFIG1__XRTY_WAIT_SCALE = 59;
static const uint32_t AME_ATL_MISC_CONFIG1__XRTY_WAIT_SCALE_LEN = 3;
static const uint32_t AME_ATL_MISC_CONFIG1__WBI_PWR_WAIT = 62;
static const uint32_t AME_ATL_MISC_CONFIG1__WBI_PWR_WAIT_LEN = 2;
// pau/reg00010.H

static const uint64_t CS_CTL_MISC_BDF2PE_4_CONFIG = 0x100109b4ull;

static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_ENABLE = 0;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_RESERVED = 1;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_RESERVED_LEN = 3;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_PE = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_PE_LEN = 4;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_BDF = 8;
static const uint32_t CS_CTL_MISC_BDF2PE_4_CONFIG_BDF_LEN = 16;
// pau/reg00010.H

static const uint64_t CS_CTL_MISC_CERR_MESSAGE2 = 0x1001099aull;

static const uint32_t CS_CTL_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2 = 0;
static const uint32_t CS_CTL_MISC_CERR_MESSAGE2_CERR_MESSAGE_BITS2_LEN = 16;
// pau/reg00010.H

static const uint64_t CS_CTL_MISC_CONFIG2 = 0x10010982ull;

static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK0_OCAPI_MODE = 0;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK1_OCAPI_MODE = 1;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK2_OCAPI_MODE = 2;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK3_OCAPI_MODE = 3;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK4_OCAPI_MODE = 4;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK0_NVLINK_MODE = 5;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK1_NVLINK_MODE = 6;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK2_NVLINK_MODE = 7;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK3_NVLINK_MODE = 8;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK4_NVLINK_MODE = 9;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK0_OCAPI_4 = 10;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK0_OCAPI_4 = 10;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK1_OCAPI_4 = 11;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK1_OCAPI_4 = 11;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK2_OCAPI_4 = 12;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK2_OCAPI_4 = 12;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK3_OCAPI_4 = 13;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK3_OCAPI_4 = 13;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK4_OCAPI_4 = 14;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK4_OCAPI_4 = 14;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK0_OCAPI_C2 = 15;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK1_OCAPI_C2 = 16;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK2_OCAPI_C2 = 17;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK3_OCAPI_C2 = 18;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK4_OCAPI_C2 = 19;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK0_OCAPI_AMO = 20;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK0_OCAPI_AMO = 20;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK1_OCAPI_AMO = 21;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK1_OCAPI_AMO = 21;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK2_OCAPI_AMO = 22;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK2_OCAPI_AMO = 22;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK3_OCAPI_AMO = 23;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK3_OCAPI_AMO = 23;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_ENABLE_BRK4_OCAPI_AMO = 24;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_ENABLE_BRK4_OCAPI_AMO = 24;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_WRITE_MEM_OS_BIT_BRK0 = 25;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_WRITE_MEM_OS_BIT_BRK0 = 25;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_WRITE_MEM_OS_BIT_BRK1 = 26;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_WRITE_MEM_OS_BIT_BRK1 = 26;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_WRITE_MEM_OS_BIT_BRK2 = 27;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_WRITE_MEM_OS_BIT_BRK2 = 27;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_WRITE_MEM_OS_BIT_BRK3 = 28;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_WRITE_MEM_OS_BIT_BRK3 = 28;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_WRITE_MEM_OS_BIT_BRK4 = 29;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_WRITE_MEM_OS_BIT_BRK4 = 29;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_SYNC_SCOPE = 30;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_SYNC_SCOPE_LEN = 2;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_GENID_SYNC_SCOPE = 30;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_GENID_SYNC_SCOPE_LEN = 2;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_SYNC_FORCE_RCMD0 = 32;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_GENID_SYNC_FORCE_RCMD0 = 32;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK0_IMP_TAGS_MODE_ENABLE = 33;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK1_IMP_TAGS_MODE_ENABLE = 34;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK2_IMP_TAGS_MODE_ENABLE = 35;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK3_IMP_TAGS_MODE_ENABLE = 36;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG_BRK4_IMP_TAGS_MODE_ENABLE = 37;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG2_RESERVED1 = 38;
static const uint32_t CS_CTL_MISC_CONFIG2_S_CTL_MISC_CONFIG2_RESERVED1_LEN = 10;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_RATE_INC = 48;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_RATE_INC_LEN = 8;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_RATE_DEC = 56;
static const uint32_t CS_CTL_MISC_CONFIG2_ONFIG_GENID_RATE_DEC_LEN = 8;
// pau/reg00010.H

static const uint64_t CS_CTL_MISC_FENCE_CONTROL3 = 0x100109a4ull;

static const uint32_t CS_CTL_MISC_FENCE_CONTROL3_3_REQUEST_FENCE = 0;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL3_3_REQUEST_FENCE_LEN = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL3__CONTROL3_RESERVED = 2;
static const uint32_t CS_CTL_MISC_FENCE_CONTROL3__CONTROL3_RESERVED_LEN = 2;
// pau/reg00010.H

static const uint64_t CS_SM0_DIR_MISC_DEBUG1_CONFIG = 0x1001082bull;

static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM0_DIR_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00010.H

static const uint64_t CS_SM0_MCP_MISC_CERR_MASK2 = 0x10010814ull;

static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_0 = 0;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_1 = 1;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_2 = 2;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_3 = 3;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_4 = 4;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_5 = 5;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_6 = 6;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_7 = 7;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_8 = 8;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_9 = 9;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_10 = 10;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_11 = 11;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_12 = 12;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_13 = 13;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_14 = 14;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_15 = 15;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_16 = 16;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_17 = 17;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_18 = 18;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_19 = 19;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_20 = 20;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_21 = 21;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_22 = 22;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_23 = 23;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_24 = 24;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_25 = 25;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_26 = 26;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_27 = 27;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_28 = 28;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_29 = 29;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_30 = 30;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_31 = 31;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_32 = 32;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_33 = 33;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_34 = 34;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_35 = 35;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_36 = 36;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_37 = 37;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_38 = 38;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_39 = 39;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_40 = 40;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_41 = 41;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_42 = 42;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_43 = 43;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_44 = 44;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_45 = 45;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_46 = 46;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_47 = 47;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_48 = 48;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_49 = 49;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_50 = 50;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_51 = 51;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_52 = 52;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_53 = 53;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_54 = 54;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_55 = 55;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_56 = 56;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_57 = 57;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_58 = 58;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_59 = 59;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_60 = 60;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_61 = 61;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_62 = 62;
static const uint32_t CS_SM0_MCP_MISC_CERR_MASK2_63 = 63;
// pau/reg00010.H

static const uint64_t CS_SM0_MCP_MISC_CONFIG1 = 0x10010801ull;

static const uint32_t CS_SM0_MCP_MISC_CONFIG1__RANDOM_BACKOFF_DUR_MASK = 0;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__RANDOM_BACKOFF_DUR_MASK_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_REQ = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_REQ_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_CST = 8;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_CST_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_PRB = 12;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__CHGRATE_HANG_SLOWDOWN_PRB_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__EPSILON_WLN_COUNT = 16;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__EPSILON_WLN_COUNT_LEN = 12;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1_1_RESERVED2 = 28;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1_1_RESERVED2_LEN = 7;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__PCKT_LONG_CL_DMA_INJ = 35;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__PCKT_LONG_PR_DMA_INJ = 36;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__PCKT_LONG_MIN_COUNT = 37;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__PCKT_LONG_MIN_COUNT_LEN = 6;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__PCKT_LONG_USES_HANG = 43;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__DONT_RETRY_LCO_LONG = 44;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__DONT_RETRY_LCO_LONG_STRESSED = 45;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__DONT_RETRY_LCO_SHORT = 46;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__DONT_RETRY_LCO_SHORT_STRESSED = 47;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__STOP_ASB_AT_LN_SCOPE = 48;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__STOP_ASB_AT_G_SCOPE = 49;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__INITIAL_HPC_PROBE_PRIORITY = 50;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__NVLINK_P9P9_MODE = 51;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1__HANG_ON_ADDRESS_ERRORS = 52;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1_1_RESERVED = 53;
static const uint32_t CS_SM0_MCP_MISC_CONFIG1_1_RESERVED_LEN = 11;
// pau/reg00010.H

static const uint64_t CS_SM0_MCP_MISC_INHIBIT_CONFIG = 0x10010805ull;

static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ0 = 0;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ0_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ0 = 4;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ0_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_BLOCKY0 = 6;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_ONESHOT0 = 7;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST0 = 8;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST0_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ1 = 16;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ1_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ1 = 20;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ1_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_BLOCKY1 = 22;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_ONESHOT1 = 23;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST1 = 24;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST1_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ2 = 32;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ2_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ2 = 36;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ2_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_BLOCKY2 = 38;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_ONESHOT2 = 39;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST2 = 40;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST2_LEN = 8;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ3 = 48;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_LFREQ3_LEN = 4;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ3 = 52;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_PFREQ3_LEN = 2;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_BLOCKY3 = 54;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_ONESHOT3 = 55;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST3 = 56;
static const uint32_t CS_SM0_MCP_MISC_INHIBIT_CONFIG_DEST3_LEN = 8;
// pau/reg00010.H

static const uint64_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0 = 0x1001083eull;

static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_TAG = 0;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_TAG_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_TAGMASK = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_TAGMASK_LEN = 14;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_PAU = 28;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_PCIE = 29;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_L2L3 = 30;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_RESERVED1 = 31;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_RDSTART = 32;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_RDSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_RDEND = 40;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_RDEND_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_WRSTART = 48;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_WRSTART_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_WREND = 56;
static const uint32_t CS_SM0_SNP_MISC_CONFIG_RELAXED_SRC0_WREND_LEN = 8;
// pau/reg00010.H

static const uint64_t CS_SM0_SNP_MISC_INHIBIT_CONFIG = 0x1001084full;

static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_0 = 0;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_0_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_1 = 8;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_1_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_2 = 16;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_2_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_3 = 24;
static const uint32_t CS_SM0_SNP_MISC_INHIBIT_CONFIG_3_LEN = 8;
// pau/reg00010.H

static const uint64_t CS_SM0_SNP_MISC_LOW_WATER = 0x1001084bull;

static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PWR0 = 0;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PWR1 = 1;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PWR2 = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_XATS = 3;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_INTS = 4;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQ0 = 5;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CST0 = 6;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRB0 = 7;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQ1 = 8;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CST1 = 9;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRB1 = 10;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQ2 = 11;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CST2 = 12;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRB2 = 13;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQ3 = 14;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CST3 = 15;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRB3 = 16;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQ4 = 17;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CST4 = 18;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRB4 = 19;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_XI_SHARED = 20;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_REQX_SHARED = 21;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_CSTX_SHARED = 22;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_LOW_WATER_PRBX_SHARED = 23;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR0 = 24;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR0_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR1 = 26;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR1_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR2 = 28;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PWR2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_XATS = 30;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_XATS_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_INTS = 32;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_INTS_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ0 = 34;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ0_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST0 = 36;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST0_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB0 = 38;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB0_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ1 = 40;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ1_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST1 = 42;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST1_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB1 = 44;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB1_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ2 = 46;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST2 = 48;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB2 = 50;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB2_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ3 = 52;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ3_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST3 = 54;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST3_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB3 = 56;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB3_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ4 = 58;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_REQ4_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST4 = 60;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_CST4_LEN = 2;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB4 = 62;
static const uint32_t CS_SM0_SNP_MISC_LOW_WATER_WEIGHT_PRB4_LEN = 2;
// pau/reg00010.H

static const uint64_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG = 0x10010857ull;

static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS = 0;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_CLASS_LEN = 5;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_TTYPE = 5;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_TSIZE = 17;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_NVBE = 25;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_UT = 26;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ATYPE = 27;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ATYPE_LEN = 7;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ALLOC = 34;
static const uint32_t CS_SM0_SNP_MISC_PERF_MATCH_CONFIG_ALLOC_LEN = 6;
// pau/reg00010.H

static const uint64_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3 = 0x1001085full;

static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31 = 0;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_ABLE_24_31_LEN = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY24 = 8;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY24_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY25 = 12;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY25_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY26 = 16;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY26_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY27 = 20;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY27_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY28 = 24;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY28_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY29 = 28;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY29_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY30 = 32;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY30_LEN = 4;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY31 = 36;
static const uint32_t CS_SM0_SNP_MISC_TOPOLOGY_TABLE3_TRY31_LEN = 4;
// pau/reg00010.H

static const uint64_t CS_SM1_MCP_MISC_CERR_MESSAGE1 = 0x10010867ull;

static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1 = 0;
static const uint32_t CS_SM1_MCP_MISC_CERR_MESSAGE1_CERR_MESSAGE_BITS1_LEN = 64;
// pau/reg00010.H

static const uint64_t CS_SM1_MCP_MISC_DEBUG1_CONFIG = 0x1001087bull;

static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD0 = 0;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD0_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD1 = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD1_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD2 = 10;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD2_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD3 = 15;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD3_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD4 = 20;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD4_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD5 = 25;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD5_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD6 = 30;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD6_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD7 = 35;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD7_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD8 = 40;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD8_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD9 = 45;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD9_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD10 = 50;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_POD10_LEN = 5;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_RESERVED1 = 55;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_RESERVED1_LEN = 8;
static const uint32_t CS_SM1_MCP_MISC_DEBUG1_CONFIG_ACT = 63;
// pau/reg00010.H

static const uint64_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3 = 0x100108a9ull;

static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_AND = 11;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_OR = 12;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_RESERVED1 = 29;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_RESERVED1_LEN = 3;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_WRENA = 32;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_RDENA = 33;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_AWENA = 34;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_ARENA = 35;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_WRENA = 36;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_RDENA = 37;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_AWENA = 38;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_ARENA = 39;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_WRENA = 40;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_RDENA = 41;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_AWENA = 42;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_ARENA = 43;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_WRENA = 44;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_RDENA = 45;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_AWENA = 46;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_ARENA = 47;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_WRENA = 48;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_RDENA = 49;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_AWENA = 50;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_ARENA = 51;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_WRENA = 52;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_RDENA = 53;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_AWENA = 54;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_ARENA = 55;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_WRENA = 56;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_RDENA = 57;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_AWENA = 58;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_ARENA = 59;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_WRENA = 60;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_RDENA = 61;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_AWENA = 62;
static const uint32_t CS_SM1_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_ARENA = 63;
// pau/reg00010.H

static const uint64_t CS_SM1_SNP_MISC_GENID_BAR = 0x1001089dull;

static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ENABLE = 0;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_SECURE_A12 = 1;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED1 = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR = 3;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_ADDR_LEN = 30;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2 = 33;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_GENID_RESERVED2_LEN = 2;
static const uint32_t CS_SM1_SNP_MISC_GENID_BAR_CONFIG_GENID_BAR_POISON = 35;
// pau/reg00010.H

static const uint64_t CS_SM1_SNP_MISC_MACHINE_ALLOC = 0x100108adull;

static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_ENABLE_MACHINE_ALLOC = 0;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_ENABLE_EXCEED_HIGH = 1;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES = 2;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_MAX_MACHINES_LEN = 6;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE = 8;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_WATER_IDLE_LEN = 6;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1 = 14;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS1_LEN = 6;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE = 20;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_MIN_SHARE_LEN = 10;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2 = 30;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_HIGH_BONUS2_LEN = 10;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED = 40;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_MAX_HIGH_RESERVED_LEN = 4;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0 = 44;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL0_LEN = 5;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1 = 49;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL1_LEN = 5;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2 = 54;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL2_LEN = 5;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3 = 59;
static const uint32_t CS_SM1_SNP_MISC_MACHINE_ALLOC_SMAL_DEBUG_SEL3_LEN = 5;
// pau/reg00010.H

static const uint64_t CS_SM1_SNP_MISC_SM_STATUS = 0x100108b2ull;

static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PWR0 = 0;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PWR1 = 1;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PWR2 = 2;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_XATS = 3;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_INTS = 4;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CREQ0 = 5;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CST0 = 6;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PRB0 = 7;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CREQ1 = 8;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CST1 = 9;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PRB1 = 10;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CREQ2 = 11;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CST2 = 12;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PRB2 = 13;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CREQ3 = 14;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CST3 = 15;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PRB3 = 16;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CREQ4 = 17;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CST4 = 18;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_PRB4 = 19;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_CHGRATE = 20;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_RESERVED1 = 21;
static const uint32_t CS_SM1_SNP_MISC_SM_STATUS_RESERVED1_LEN = 3;
// pau/reg00010.H

static const uint64_t CS_SM2_DIR_MISC_CONFIG0 = 0x100108e8ull;

static const uint32_t CS_SM2_DIR_MISC_CONFIG0__HOST_TAG_SIZE = 0;
static const uint32_t CS_SM2_DIR_MISC_CONFIG0__HOST_TAG_SIZE_LEN = 4;
static const uint32_t CS_SM2_DIR_MISC_CONFIG0_0_RESERVED = 4;
static const uint32_t CS_SM2_DIR_MISC_CONFIG0_0_RESERVED_LEN = 59;
static const uint32_t CS_SM2_DIR_MISC_CONFIG0__DEBUG0_ACT = 63;
// pau/reg00010.H

static const uint64_t CS_SM2_MCP_MISC_CERR_HOLD0 = 0x100108d5ull;

static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_0 = 0;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_1 = 1;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_2 = 2;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_3 = 3;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_4 = 4;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_5 = 5;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_6 = 6;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_7 = 7;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_8 = 8;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_9 = 9;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_10 = 10;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_11 = 11;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_12 = 12;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_13 = 13;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_14 = 14;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_15 = 15;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_16 = 16;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_17 = 17;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_18 = 18;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_NVF_19 = 19;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_0 = 20;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_1 = 21;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_2 = 22;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_3 = 23;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_4 = 24;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_5 = 25;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_6 = 26;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_ASBE_7 = 27;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_0 = 28;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_1 = 29;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_2 = 30;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_3 = 31;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_4 = 32;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_5 = 33;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_6 = 34;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_PBR_7 = 35;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_REG_0 = 36;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_REG_1 = 37;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_REG_2 = 38;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_REG_3 = 39;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_0 = 40;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_1 = 41;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_2 = 42;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_3 = 43;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_4 = 44;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_5 = 45;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_6 = 46;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_7 = 47;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_8 = 48;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_9 = 49;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_10 = 50;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_11 = 51;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_12 = 52;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_13 = 53;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_14 = 54;
static const uint32_t CS_SM2_MCP_MISC_CERR_HOLD0_OCR_15 = 55;
// pau/reg00010.H

static const uint64_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0 = 0x100108feull;

static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_TAG = 0;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_TAG_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_TAGMASK = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_TAGMASK_LEN = 14;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_PAU = 28;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_PCIE = 29;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_MASK_L2L3 = 30;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_RESERVED1 = 31;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_RDSTART = 32;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_RDSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_RDEND = 40;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_RDEND_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_WRSTART = 48;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_WRSTART_LEN = 8;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_WREND = 56;
static const uint32_t CS_SM2_SNP_MISC_CONFIG_RELAXED_SRC0_WREND_LEN = 8;
// pau/reg00010.H

static const uint64_t CS_SM3_MCP_MISC_CERR_MESSAGE4 = 0x1001092aull;

static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4 = 0;
static const uint32_t CS_SM3_MCP_MISC_CERR_MESSAGE4_CERR_MESSAGE_BITS4_LEN = 64;
// pau/reg00010.H

static const uint64_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG = 0x10010938ull;

static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2 = 0;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_RESERVED2_LEN = 24;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_CRESP = 24;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_CRESP_LEN = 5;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_SCOPE = 29;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_SCOPE_LEN = 3;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_MCMD = 32;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_MCMD_LEN = 10;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1 = 42;
static const uint32_t CS_SM3_MCP_MISC_PERF_MATCH_CONFIG_RESERVED1_LEN = 2;
// pau/reg00010.H

static const uint64_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3 = 0x10010969ull;

static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_W = 0;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_W_HP = 1;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_DMA_INJ = 2;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_PR_DMA_INJ = 3;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_DMA_PR_W = 4;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_CL_RD_NC_F0 = 5;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMAX_U = 6;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMAX_S = 7;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMIN_U = 8;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_IMIN_S = 9;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_ADD = 10;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_AND = 11;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_OR = 12;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_XOR = 13;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMAX_U = 14;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMAX_S = 15;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMIN_U = 16;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_IMIN_S = 17;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_ADD = 18;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_AND = 19;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_OR = 20;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_XOR = 21;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_E = 22;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_U = 23;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMW_CAS_T = 24;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_CAS_NE = 25;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_INC_B = 26;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_INC_E = 27;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_CMD_ARMWF_DEC_B = 28;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_RESERVED1 = 29;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_RESERVED1_LEN = 3;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_WRENA = 32;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_RDENA = 33;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_AWENA = 34;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE0_ARENA = 35;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_WRENA = 36;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_RDENA = 37;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_AWENA = 38;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE1_ARENA = 39;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_WRENA = 40;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_RDENA = 41;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_AWENA = 42;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE2_ARENA = 43;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_WRENA = 44;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_RDENA = 45;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_AWENA = 46;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE3_ARENA = 47;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_WRENA = 48;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_RDENA = 49;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_AWENA = 50;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE4_ARENA = 51;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_WRENA = 52;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_RDENA = 53;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_AWENA = 54;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE5_ARENA = 55;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_WRENA = 56;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_RDENA = 57;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_AWENA = 58;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE6_ARENA = 59;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_WRENA = 60;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_RDENA = 61;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_AWENA = 62;
static const uint32_t CS_SM3_SNP_MISC_CONFIG_RELAXED_BRK3_SOURCE7_ARENA = 63;
// pau/reg00010.H

static const uint64_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG = 0x10010978ull;

static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ALLOC_CLASS = 0;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ALLOC_CLASS_LEN = 5;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_TTYPE = 5;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_TTYPE_LEN = 12;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_TSIZE = 17;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_TSIZE_LEN = 8;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_NVBE = 25;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_UT = 26;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ATYPE = 27;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ATYPE_LEN = 7;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ALLOC = 34;
static const uint32_t CS_SM3_SNP_MISC_PERF_MASK_CONFIG_ALLOC_LEN = 6;
// pau/reg00010.H

static const uint64_t DAT_MISC_REM0 = 0x100109cdull;

static const uint32_t DAT_MISC_REM0_IBUF_WSRC = 17;
static const uint32_t DAT_MISC_REM0_IBUF_WSRC_LEN = 5;
static const uint32_t DAT_MISC_REM0_IBUF_RSRC = 22;
static const uint32_t DAT_MISC_REM0_IBUF_RSRC_LEN = 2;
static const uint32_t DAT_MISC_REM0_IBUF_AIDX = 24;
static const uint32_t DAT_MISC_REM0_IBUF_AIDX_LEN = 8;
static const uint32_t DAT_MISC_REM0_IBUF_ABANK = 32;
static const uint32_t DAT_MISC_REM0_IBUF_ABANK_LEN = 2;
static const uint32_t DAT_MISC_REM0_OBUF_WSRC = 34;
static const uint32_t DAT_MISC_REM0_OBUF_WSRC_LEN = 2;
static const uint32_t DAT_MISC_REM0_OBUF_RSRC = 36;
static const uint32_t DAT_MISC_REM0_OBUF_RSRC_LEN = 6;
static const uint32_t DAT_MISC_REM0_OBUF_AIDX = 42;
static const uint32_t DAT_MISC_REM0_OBUF_AIDX_LEN = 8;
static const uint32_t DAT_MISC_REM0_OBUF_ABANK = 50;
static const uint32_t DAT_MISC_REM0_OBUF_ABANK_LEN = 2;
static const uint32_t DAT_MISC_REM0_BBUF_WSRC = 52;
static const uint32_t DAT_MISC_REM0_BBUF_WSRC_LEN = 2;
static const uint32_t DAT_MISC_REM0_BBUF_RSRC = 54;
static const uint32_t DAT_MISC_REM0_BBUF_RSRC_LEN = 2;
static const uint32_t DAT_MISC_REM0_BBUF_AIDX = 56;
static const uint32_t DAT_MISC_REM0_BBUF_AIDX_LEN = 8;
// pau/reg00010.H

static const uint64_t DAT_MISC_SCRATCH1 = 0x100109dcull;

static const uint32_t DAT_MISC_SCRATCH1_SCRATCH1_IDIAL = 0;
static const uint32_t DAT_MISC_SCRATCH1_SCRATCH1_IDIAL_LEN = 64;
// pau/reg00010.H

static const uint64_t FIR_ACTION1_REG_2 = 0x10010c87ull;

static const uint32_t FIR_ACTION1_REG_2_FIR_ACTION1_2 = 0;
static const uint32_t FIR_ACTION1_REG_2_FIR_ACTION1_2_LEN = 62;
// pau/reg00010.H

static const uint64_t FIR_MASK_REG_2_RW = 0x10010c83ull;
static const uint64_t FIR_MASK_REG_2_WO_AND = 0x10010c84ull;
static const uint64_t FIR_MASK_REG_2_WO_OR = 0x10010c85ull;

static const uint32_t FIR_MASK_REG_2_FIR_MASK_2 = 0;
static const uint32_t FIR_MASK_REG_2_FIR_MASK_2_LEN = 62;
// pau/reg00010.H

static const uint64_t MISC_FENCE_STATE = 0x10010b46ull;

static const uint32_t MISC_FENCE_STATE_0 = 0;
static const uint32_t MISC_FENCE_STATE_1 = 1;
static const uint32_t MISC_FENCE_STATE_2 = 2;
static const uint32_t MISC_FENCE_STATE_3 = 3;
static const uint32_t MISC_FENCE_STATE_4 = 4;
// pau/reg00010.H

static const uint64_t MISC_REGS_BDF2PE_4_CONFIG = 0x10010b54ull;

static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_ENABLE = 0;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_RESERVED = 1;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_RESERVED_LEN = 3;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_PE = 4;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_PE_LEN = 4;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_BDF = 8;
static const uint32_t MISC_REGS_BDF2PE_4_CONFIG_BDF_LEN = 16;
// pau/reg00010.H

static const uint64_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1 = 0x10010bb2ull;

static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_5 = 0;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_5_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_6 = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_6_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_7 = 24;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_7_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_8 = 36;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_8_LEN = 12;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_9 = 48;
static const uint32_t MISC_REGS_ERROR_BRICK_GROUP_CONFIG1_9_LEN = 12;
// pau/reg00010.H

static const uint64_t MISC_REGS_INT_LOG_0_PE8 = 0x10010b98ull;

static const uint32_t MISC_REGS_INT_LOG_0_PE8_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_0_PE8_LVL = 1;
static const uint32_t MISC_REGS_INT_LOG_0_PE8_LVL_LEN = 60;
static const uint32_t MISC_REGS_INT_LOG_0_PE8_RSVD0 = 61;
static const uint32_t MISC_REGS_INT_LOG_0_PE8_RSVD0_LEN = 3;
// pau/reg00010.H

static const uint64_t MISC_REGS_INT_LOG_1_PE8 = 0x10010ba8ull;

static const uint32_t MISC_REGS_INT_LOG_1_PE8_VLD = 0;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_DETAIL = 1;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_DETAIL_LEN = 32;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_CQ = 33;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_CQ_LEN = 24;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_RSVD0 = 57;
static const uint32_t MISC_REGS_INT_LOG_1_PE8_RSVD0_LEN = 7;
// pau/reg00010.H

static const uint64_t MISC_REGS_PESTB_ADDR_PE8 = 0x10010b88ull;

static const uint32_t MISC_REGS_PESTB_ADDR_PE8_DMA_STOPPED_STATE_ADDR_PE8 = 0;
static const uint32_t MISC_REGS_PESTB_ADDR_PE8_DMA_STOPPED_STATE_ADDR_PE8_LEN = 37;
// pau/reg00010.H

static const uint64_t NTL0_REGS_CREQ_DA_PTR = 0x100109f4ull;

static const uint32_t NTL0_REGS_CREQ_DA_PTR_RESERVED1 = 0;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_RESERVED1_LEN = 3;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_START = 3;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_START_LEN = 9;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_RESERVED2 = 12;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_RESERVED2_LEN = 3;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_END = 15;
static const uint32_t NTL0_REGS_CREQ_DA_PTR_END_LEN = 9;
// pau/reg00010.H

static const uint64_t NTL1_REGS_SCRATCH2 = 0x10010a0aull;

static const uint32_t NTL1_REGS_SCRATCH2_IDIAL_SCRATCH2 = 0;
static const uint32_t NTL1_REGS_SCRATCH2_IDIAL_SCRATCH2_LEN = 64;
// pau/reg00010.H

static const uint64_t OTL0_MISC_CONFIG_DEBUG1 = 0x10010a29ull;

static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE0 = 0;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE0_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE1 = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE1_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE2 = 10;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE2_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE3 = 15;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE3_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE4 = 20;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE4_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE5 = 25;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE5_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE6 = 30;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE6_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE7 = 35;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE7_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE8 = 40;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE8_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE9 = 45;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE9_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE10 = 50;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_BYTE10_LEN = 5;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_RESERVED = 55;
static const uint32_t OTL0_MISC_CONFIG_DEBUG1_RESERVED_LEN = 9;
// pau/reg00010.H

static const uint64_t OTL0_MISC_PSL_DSISR_AN = 0x10010a48ull;

static const uint32_t OTL0_MISC_PSL_DSISR_AN_TF = 3;
static const uint32_t OTL0_MISC_PSL_DSISR_AN_S = 38;
static const uint32_t OTL0_MISC_PSL_DSISR_AN_CO_RSP = 56;
static const uint32_t OTL0_MISC_PSL_DSISR_AN_CO_RSP_LEN = 8;
// pau/reg00010.H

static const uint64_t OTL1_MISC_CONFIG_DEBUG0 = 0x10010a58ull;

static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE0 = 0;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE0_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE1 = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE1_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE2 = 10;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE2_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE3 = 15;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE3_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE4 = 20;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE4_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE5 = 25;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE5_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE6 = 30;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE6_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE7 = 35;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE7_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE8 = 40;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE8_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE9 = 45;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE9_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE10 = 50;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_BYTE10_LEN = 5;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_RESERVED = 55;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0_0_RESERVED_LEN = 8;
static const uint32_t OTL1_MISC_CONFIG_DEBUG0__ACT = 63;
// pau/reg00010.H

static const uint64_t OTL1_MISC_CONFIG_TX_DLC = 0x10010a5cull;

static const uint32_t OTL1_MISC_CONFIG_TX_DLC_CONFIG_TX_DL_CREDITS = 0;
static const uint32_t OTL1_MISC_CONFIG_TX_DLC_CONFIG_TX_DL_CREDITS_LEN = 10;
// pau/reg00010.H

static const uint64_t OTL1_MISC_ERROR_SIG_RXI = 0x10010a5eull;

static const uint32_t OTL1_MISC_ERROR_SIG_RXI_CAPTURED = 0;
static const uint32_t OTL1_MISC_ERROR_SIG_RXI_ENCODE = 1;
static const uint32_t OTL1_MISC_ERROR_SIG_RXI_ENCODE_LEN = 7;
static const uint32_t OTL1_MISC_ERROR_SIG_RXI_SIGNATURE = 8;
static const uint32_t OTL1_MISC_ERROR_SIG_RXI_SIGNATURE_LEN = 56;
// pau/reg00010.H

static const uint64_t OTL1_MISC_HAPPI_BAR0 = 0x10010a6bull;

static const uint32_t OTL1_MISC_HAPPI_BAR0_ENABLE = 0;
static const uint32_t OTL1_MISC_HAPPI_BAR0_ADDR = 1;
static const uint32_t OTL1_MISC_HAPPI_BAR0_ADDR_LEN = 21;
static const uint32_t OTL1_MISC_HAPPI_BAR0_MASK = 22;
static const uint32_t OTL1_MISC_HAPPI_BAR0_MASK_LEN = 21;
static const uint32_t OTL1_MISC_HAPPI_BAR0_SUB = 43;
static const uint32_t OTL1_MISC_HAPPI_BAR0_SUB_LEN = 21;
// pau/reg00010.H

static const uint64_t OTL1_MISC_TL_DCP_CREDIT_STATUS = 0x10010a63ull;

static const uint32_t OTL1_MISC_TL_DCP_CREDIT_STATUS_0_COUNT = 0;
static const uint32_t OTL1_MISC_TL_DCP_CREDIT_STATUS_0_COUNT_LEN = 16;
static const uint32_t OTL1_MISC_TL_DCP_CREDIT_STATUS_1_COUNT = 16;
static const uint32_t OTL1_MISC_TL_DCP_CREDIT_STATUS_1_COUNT_LEN = 16;
// pau/reg00010.H

static const uint64_t XSL_MAIN_PMU_CONTROL0 = 0x10010aaeull;

static const uint32_t XSL_MAIN_PMU_CONTROL0_ENABLE = 0;
static const uint32_t XSL_MAIN_PMU_CONTROL0_RESETMODE = 1;
static const uint32_t XSL_MAIN_PMU_CONTROL0_FREEZEMODE = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_DISABLE_PMISC = 3;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PMISC_MODE = 4;
static const uint32_t XSL_MAIN_PMU_CONTROL0_CASCADE = 5;
static const uint32_t XSL_MAIN_PMU_CONTROL0_CASCADE_LEN = 3;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C0 = 8;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C0_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C1 = 10;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C1_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C2 = 12;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C2_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C3 = 14;
static const uint32_t XSL_MAIN_PMU_CONTROL0_PRESCALE_C3_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C0 = 16;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C0_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C1 = 18;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C1_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C2 = 20;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C2_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C3 = 22;
static const uint32_t XSL_MAIN_PMU_CONTROL0_OPERATION_C3_LEN = 2;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C0 = 24;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C0_LEN = 8;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C1 = 32;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C1_LEN = 8;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C2 = 40;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C2_LEN = 8;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C3 = 48;
static const uint32_t XSL_MAIN_PMU_CONTROL0_EVENTS_C3_LEN = 8;
static const uint32_t XSL_MAIN_PMU_CONTROL0_RESERVED0 = 56;
static const uint32_t XSL_MAIN_PMU_CONTROL0_RESERVED0_LEN = 8;
// pau/reg00010.H

static const uint64_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1 = 0x10010a89ull;

static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_MULTI_AFU_DIAL = 0;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_64K_PG_DISABLE_DIAL = 2;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_2M_PG_DISABLE_DIAL = 3;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_OPENCAPI3_DIAL = 32;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_KILL_XLATE_TYPE_DIAL = 33;
static const uint32_t XSL_MAIN_XSLOP_VLOG_RGS_OSL_XLATE_CFG1_KILL_XLATE_TYPE_DIAL_LEN = 2;
// pau/reg00011.H

static const uint64_t XTS_ATSD_HYP2 = 0x10010b12ull;

static const uint32_t XTS_ATSD_HYP2_MSRHV = 51;
static const uint32_t XTS_ATSD_HYP2_LPARID = 52;
static const uint32_t XTS_ATSD_HYP2_LPARID_LEN = 12;
// pau/reg00011.H

static const uint64_t XTS_REG_PMU_CNT = 0x10010af8ull;

static const uint32_t XTS_REG_PMU_CNT_0 = 0;
static const uint32_t XTS_REG_PMU_CNT_0_LEN = 16;
static const uint32_t XTS_REG_PMU_CNT_1 = 16;
static const uint32_t XTS_REG_PMU_CNT_1_LEN = 16;
static const uint32_t XTS_REG_PMU_CNT_2 = 32;
static const uint32_t XTS_REG_PMU_CNT_2_LEN = 16;
static const uint32_t XTS_REG_PMU_CNT_3 = 48;
static const uint32_t XTS_REG_PMU_CNT_3_LEN = 16;
// pau/reg00011.H

#ifndef __PPE_HCODE__
}
}
#include "pau/reg00010.H"
#include "pau/reg00011.H"
#endif
#endif
