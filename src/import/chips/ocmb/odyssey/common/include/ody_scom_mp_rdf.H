/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_mp_rdf.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#pragma once
#include <stdint.h>

#ifndef __PPE_HCODE__
namespace scomt
{
namespace mp
{
#endif

static const uint64_t CNTL_ELPR = 0x801182Full;

static const uint32_t CNTL_ELPR_FULL = 0;
static const uint32_t CNTL_ELPR_POINTER = 3;
static const uint32_t CNTL_ELPR_POINTER_LEN = 6;


static const uint64_t SCOM_AACR = 0x8011829ull;

static const uint32_t SCOM_AACR_RRAYSEL = 0;
static const uint32_t SCOM_AACR_DDRESS = 1;
static const uint32_t SCOM_AACR_DDRESS_LEN = 9;
static const uint32_t SCOM_AACR_UTOINC = 10;


static const uint64_t SCOM_AADR = 0x801182Aull;

static const uint32_t SCOM_AADR_AADR_DATA = 0;
static const uint32_t SCOM_AADR_AADR_DATA_LEN = 64;


static const uint64_t SCOM_AAER = 0x801182Bull;

static const uint32_t SCOM_AAER_AAER_DATA = 0;
static const uint32_t SCOM_AAER_AAER_DATA_LEN = 8;


static const uint64_t SCOM_CERR0 = 0x801180Eull;

static const uint32_t SCOM_CERR0_MSR_PE = 12;
static const uint32_t SCOM_CERR0_EICR_PE = 13;
static const uint32_t SCOM_CERR0_HWMSX_PE = 16;
static const uint32_t SCOM_CERR0_HWMSX_PE_LEN = 8;
static const uint32_t SCOM_CERR0_FWMSX_PE = 24;
static const uint32_t SCOM_CERR0_FWMSX_PE_LEN = 8;
static const uint32_t SCOM_CERR0_RSPAR_PE = 32;
static const uint32_t SCOM_CERR0_AACR_PE = 41;
static const uint32_t SCOM_CERR0_DBGR_PE = 46;
static const uint32_t SCOM_CERR0_MASK0_PE = 48;
static const uint32_t SCOM_CERR0_MASK1_PE = 49;
static const uint32_t SCOM_CERR0_CGDR_PE = 50;
static const uint32_t SCOM_CERR0_MCBCM_PE = 52;
static const uint32_t SCOM_CERR0_MCBCM2_PE = 53;
static const uint32_t SCOM_CERR0_DQERRA0M0_PE = 54;
static const uint32_t SCOM_CERR0_DQERRA0M1_PE = 55;
static const uint32_t SCOM_CERR0_DQERRB0M0_PE = 56;
static const uint32_t SCOM_CERR0_DQERRB0M1_PE = 57;


static const uint64_t SCOM_CERR1 = 0x801180Full;

static const uint32_t SCOM_CERR1_ECC_CTL_AF_PERR = 0;
static const uint32_t SCOM_CERR1_ECC_CTL_TCHN_PERR = 1;
static const uint32_t SCOM_CERR1_ECC_CTL_CMPMODE_ERR = 2;
static const uint32_t SCOM_CERR1_ECC_PIPE_PCX_PERR = 3;
static const uint32_t SCOM_CERR1_ECC_PIPE_SYND_PERR = 4;
static const uint32_t SCOM_CERR1_ECC_PIPE_2SYM_PERR = 5;
static const uint32_t SCOM_CERR1_ECC_PIPE_CPLX_PERR = 6;
static const uint32_t SCOM_CERR1_ECC_PIPE_EP2_PERR = 7;
static const uint32_t SCOM_CERR1_READ_ECC_DATAPATH_PARITY_ERROR = 8;
static const uint32_t SCOM_CERR1_ECC_PIPE_CMX_PERR = 9;
static const uint32_t SCOM_CERR1_ECC_PIPE_VP1_PERR = 10;
static const uint32_t SCOM_CERR1_ECC_PIPE_VP2_PERR = 11;
static const uint32_t SCOM_CERR1_ECC_PIPE_SYG_PERR = 12;
static const uint32_t SCOM_CERR1_ECC_PIPE_EF1_PERR = 13;
static const uint32_t SCOM_CERR1_ECC_PIPE_MK3_PERR = 14;
static const uint32_t SCOM_CERR1_ECC_PIPE_E1A_PERR = 15;
static const uint32_t SCOM_CERR1_UNEXPECTED_RDDATA_VALID = 16;
static const uint32_t SCOM_CERR1_MISSING_RDDATA_VALID = 17;
static const uint32_t SCOM_CERR1_SUE_01_DETECT = 18;
static const uint32_t SCOM_CERR1_SUE_10_DETECT = 19;
static const uint32_t SCOM_CERR1_RBUF_ECC_ERR_CE_DW0 = 20;
static const uint32_t SCOM_CERR1_RBUF_ECC_ERR_UE_DW0 = 21;
static const uint32_t SCOM_CERR1_RBUF_ECC_ERR_CE_DW1 = 22;
static const uint32_t SCOM_CERR1_RBUF_ECC_ERR_UE_DW1 = 23;
static const uint32_t SCOM_CERR1_RD_BUFF_ECC_ERR_SYNDROME = 24;
static const uint32_t SCOM_CERR1_RD_BUFF_ECC_ERR_SYNDROME_LEN = 8;
static const uint32_t SCOM_CERR1_PBUF_ECC_ERR_CE_DW0 = 32;
static const uint32_t SCOM_CERR1_PBUF_ECC_ERR_UE_DW0 = 33;
static const uint32_t SCOM_CERR1_PBUF_ECC_ERR_CE_DW1 = 34;
static const uint32_t SCOM_CERR1_PBUF_ECC_ERR_UE_DW1 = 35;
static const uint32_t SCOM_CERR1_PRE_BUFF_ECC_ERR_SYNDROME = 36;
static const uint32_t SCOM_CERR1_PRE_BUFF_ECC_ERR_SYNDROME_LEN = 8;


static const uint64_t SCOM_CGDR = 0x8011832ull;

static const uint32_t SCOM_CGDR_CGDIS_PCTL = 0;
static const uint32_t SCOM_CGDR_CGDIS_RESP = 1;
static const uint32_t SCOM_CGDR_CGDIS_RMW = 2;
static const uint32_t SCOM_CGDR_CGDIS_LPTR = 3;
static const uint32_t SCOM_CGDR_CGDIS_AHASH = 4;
static const uint32_t SCOM_CGDR_CGDIS_STG = 5;
static const uint32_t SCOM_CGDR_CGDIS_OUT = 6;
static const uint32_t SCOM_CGDR_CGDIS_TLM = 7;
static const uint32_t SCOM_CGDR_CGDIS_BD = 8;
static const uint32_t SCOM_CGDR_CGDIS_DCMP = 9;
static const uint32_t SCOM_CGDR_CGDIS_RBCTL = 10;
static const uint32_t SCOM_CGDR_CGDIS_RBRMW = 11;
static const uint32_t SCOM_CGDR_CGDIS_RBTRC = 12;
static const uint32_t SCOM_CGDR_CGDIS_MPE = 13;
static const uint32_t SCOM_CGDR_CGDIS_CONF = 14;
static const uint32_t SCOM_CGDR_CGDIS_HWMS = 15;
static const uint32_t SCOM_CGDR_PSDIS_ZERO_SYND = 16;
static const uint32_t SCOM_CGDR_PSDIS_SAME_MARKS = 17;
static const uint32_t SCOM_CGDR_PSDIS_SAME_STEER = 18;
static const uint32_t SCOM_CGDR_CGDIS_SPARE = 19;


static const uint64_t SCOM_DBGR = 0x801182Eull;

static const uint32_t SCOM_DBGR_PRIMARY_SELECT = 0;
static const uint32_t SCOM_DBGR_PRIMARY_SELECT_LEN = 4;
static const uint32_t SCOM_DBGR_SECONDARY_SELECT = 4;
static const uint32_t SCOM_DBGR_SECONDARY_SELECT_LEN = 4;
static const uint32_t SCOM_DBGR_EPX_CHIP = 8;
static const uint32_t SCOM_DBGR_EPX_SYMS = 9;
static const uint32_t SCOM_DBGR_TRACE_ALWAYS = 10;
static const uint32_t SCOM_DBGR_WAT_ENABLE = 11;
static const uint32_t SCOM_DBGR_WAT_ACTION_SELECT = 12;
static const uint32_t SCOM_DBGR_WAT_SOURCE = 13;
static const uint32_t SCOM_DBGR_WAT_SOURCE_LEN = 2;


static const uint64_t SCOM_DQERRA0M0 = 0x8011836ull;

static const uint32_t SCOM_DQERRA0M0_DQERRA0M0_MISCOMPARES = 0;
static const uint32_t SCOM_DQERRA0M0_DQERRA0M0_MISCOMPARES_LEN = 40;


static const uint64_t SCOM_DQERRA0M1 = 0x8011837ull;

static const uint32_t SCOM_DQERRA0M1_DQERRA0M1_MISCOMPARES = 0;
static const uint32_t SCOM_DQERRA0M1_DQERRA0M1_MISCOMPARES_LEN = 40;


static const uint64_t SCOM_DQERRB0M0 = 0x8011838ull;

static const uint32_t SCOM_DQERRB0M0_DQERRB0M0_MISCOMPARES = 0;
static const uint32_t SCOM_DQERRB0M0_DQERRB0M0_MISCOMPARES_LEN = 40;


static const uint64_t SCOM_DQERRB0M1 = 0x8011839ull;

static const uint32_t SCOM_DQERRB0M1_DQERRB0M1_MISCOMPARES = 0;
static const uint32_t SCOM_DQERRB0M1_DQERRB0M1_MISCOMPARES_LEN = 40;


static const uint64_t SCOM_EICR = 0x801180Dull;

static const uint32_t SCOM_EICR_ADDRESS = 0;
static const uint32_t SCOM_EICR_ADDRESS_LEN = 38;
static const uint32_t SCOM_EICR_PERSIST = 38;
static const uint32_t SCOM_EICR_PERSIST_LEN = 2;
static const uint32_t SCOM_EICR_REGION = 40;
static const uint32_t SCOM_EICR_REGION_LEN = 3;
static const uint32_t SCOM_EICR_TYPE = 43;
static const uint32_t SCOM_EICR_TYPE_LEN = 5;
static const uint32_t SCOM_EICR_MISC = 48;
static const uint32_t SCOM_EICR_MISC_LEN = 6;


static const uint64_t SCOM_FIR_WO_OR = 0x8011801ull;
static const uint64_t SCOM_FIR_RW_WCLEAR = 0x8011800ull;

static const uint32_t SCOM_FIR_INTERNAL_SCOM_ERROR = 0;
static const uint32_t SCOM_FIR_MAINLINE_MPE_RANK_0_TO_7 = 1;
static const uint32_t SCOM_FIR_MAINLINE_MPE_RANK_0_TO_7_LEN = 8;
static const uint32_t SCOM_FIR_MAINLINE_NCE = 9;
static const uint32_t SCOM_FIR_MAINLINE_TCE = 10;
static const uint32_t SCOM_FIR_MAINLINE_SCE = 11;
static const uint32_t SCOM_FIR_MAINLINE_MCE = 12;
static const uint32_t SCOM_FIR_MAINLINE_SUE = 13;
static const uint32_t SCOM_FIR_MAINLINE_AUE = 14;
static const uint32_t SCOM_FIR_MAINLINE_UE = 15;
static const uint32_t SCOM_FIR_MAINLINE_RCD = 16;
static const uint32_t SCOM_FIR_MAINLINE_IAUE = 17;
static const uint32_t SCOM_FIR_MAINLINE_IUE = 18;
static const uint32_t SCOM_FIR_MAINLINE_IRCD = 19;
static const uint32_t SCOM_FIR_MAINLINE_IMPE = 20;
static const uint32_t SCOM_FIR_MAINTENANCE_MPE_RANK_0_TO_7 = 21;
static const uint32_t SCOM_FIR_MAINTENANCE_MPE_RANK_0_TO_7_LEN = 8;
static const uint32_t SCOM_FIR_MAINTENANCE_NCE = 29;
static const uint32_t SCOM_FIR_MAINTENANCE_TCE = 30;
static const uint32_t SCOM_FIR_MAINTENANCE_SCE = 31;
static const uint32_t SCOM_FIR_MAINTENANCE_MCE = 32;
static const uint32_t SCOM_FIR_MAINTENANCE_SUE = 33;
static const uint32_t SCOM_FIR_MAINTENANCE_AUE = 34;
static const uint32_t SCOM_FIR_MAINTENANCE_UE = 35;
static const uint32_t SCOM_FIR_MAINTENANCE_RCD = 36;
static const uint32_t SCOM_FIR_MAINTENANCE_IAUE = 37;
static const uint32_t SCOM_FIR_MAINTENANCE_IUE = 38;
static const uint32_t SCOM_FIR_MAINTENANCE_IRCD = 39;
static const uint32_t SCOM_FIR_MAINTENANCE_IMPE = 40;
static const uint32_t SCOM_FIR_RDDATA_VALID_ERROR = 41;
static const uint32_t SCOM_FIR_SCOM_PARITY_CLASS_STATUS = 42;
static const uint32_t SCOM_FIR_SCOM_PARITY_CLASS_RECOVERABLE = 43;
static const uint32_t SCOM_FIR_SCOM_PARITY_CLASS_UNRECOVERABLE = 44;
static const uint32_t SCOM_FIR_ECC_CORRECTOR_INTERNAL_PARITY_ERROR = 45;
static const uint32_t SCOM_FIR_ECC_RBUF_CE_DW0 = 46;
static const uint32_t SCOM_FIR_ECC_RBUF_CE_DW1 = 47;
static const uint32_t SCOM_FIR_ECC_RBUF_UE_DW0 = 48;
static const uint32_t SCOM_FIR_ECC_RBUF_UE_DW1 = 49;
static const uint32_t SCOM_FIR_ECC_PBUF_CE_DW0 = 50;
static const uint32_t SCOM_FIR_ECC_PBUF_CE_DW1 = 51;
static const uint32_t SCOM_FIR_ECC_PBUF_UE_DW0 = 52;
static const uint32_t SCOM_FIR_ECC_PBUF_UE_DW1 = 53;
static const uint32_t SCOM_FIR_TLXT_RDF_RBUF_PERR = 54;
static const uint32_t SCOM_FIR_TLXT_RDF_PBUF_PERR = 55;
static const uint32_t SCOM_FIR_RESERVED_56_60 = 56;
static const uint32_t SCOM_FIR_RESERVED_56_60_LEN = 5;
static const uint32_t SCOM_FIR_SCOM_PARITY_DEBUG_WAT = 61;
static const uint32_t SCOM_FIR_RESERVED = 62;


static const uint64_t SCOM_FWMS0 = 0x8011818ull;

static const uint32_t SCOM_FWMS0_MARK = 0;
static const uint32_t SCOM_FWMS0_MARK_LEN = 8;
static const uint32_t SCOM_FWMS0_TYPE = 8;
static const uint32_t SCOM_FWMS0_REGION = 9;
static const uint32_t SCOM_FWMS0_REGION_LEN = 3;
static const uint32_t SCOM_FWMS0_ADDRESS = 12;
static const uint32_t SCOM_FWMS0_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS0_EXIT_1 = 23;
static const uint32_t SCOM_FWMS0_EXIT_2 = 24;


static const uint64_t SCOM_FWMS1 = 0x8011819ull;

static const uint32_t SCOM_FWMS1_MARK = 0;
static const uint32_t SCOM_FWMS1_MARK_LEN = 8;
static const uint32_t SCOM_FWMS1_TYPE = 8;
static const uint32_t SCOM_FWMS1_REGION = 9;
static const uint32_t SCOM_FWMS1_REGION_LEN = 3;
static const uint32_t SCOM_FWMS1_ADDRESS = 12;
static const uint32_t SCOM_FWMS1_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS1_EXIT_1 = 23;
static const uint32_t SCOM_FWMS1_EXIT_2 = 24;


static const uint64_t SCOM_FWMS2 = 0x801181Aull;

static const uint32_t SCOM_FWMS2_MARK = 0;
static const uint32_t SCOM_FWMS2_MARK_LEN = 8;
static const uint32_t SCOM_FWMS2_TYPE = 8;
static const uint32_t SCOM_FWMS2_REGION = 9;
static const uint32_t SCOM_FWMS2_REGION_LEN = 3;
static const uint32_t SCOM_FWMS2_ADDRESS = 12;
static const uint32_t SCOM_FWMS2_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS2_EXIT_1 = 23;
static const uint32_t SCOM_FWMS2_EXIT_2 = 24;


static const uint64_t SCOM_FWMS3 = 0x801181Bull;

static const uint32_t SCOM_FWMS3_MARK = 0;
static const uint32_t SCOM_FWMS3_MARK_LEN = 8;
static const uint32_t SCOM_FWMS3_TYPE = 8;
static const uint32_t SCOM_FWMS3_REGION = 9;
static const uint32_t SCOM_FWMS3_REGION_LEN = 3;
static const uint32_t SCOM_FWMS3_ADDRESS = 12;
static const uint32_t SCOM_FWMS3_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS3_EXIT_1 = 23;
static const uint32_t SCOM_FWMS3_EXIT_2 = 24;


static const uint64_t SCOM_FWMS4 = 0x801181Cull;

static const uint32_t SCOM_FWMS4_MARK = 0;
static const uint32_t SCOM_FWMS4_MARK_LEN = 8;
static const uint32_t SCOM_FWMS4_TYPE = 8;
static const uint32_t SCOM_FWMS4_REGION = 9;
static const uint32_t SCOM_FWMS4_REGION_LEN = 3;
static const uint32_t SCOM_FWMS4_ADDRESS = 12;
static const uint32_t SCOM_FWMS4_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS4_EXIT_1 = 23;
static const uint32_t SCOM_FWMS4_EXIT_2 = 24;


static const uint64_t SCOM_FWMS5 = 0x801181Dull;

static const uint32_t SCOM_FWMS5_MARK = 0;
static const uint32_t SCOM_FWMS5_MARK_LEN = 8;
static const uint32_t SCOM_FWMS5_TYPE = 8;
static const uint32_t SCOM_FWMS5_REGION = 9;
static const uint32_t SCOM_FWMS5_REGION_LEN = 3;
static const uint32_t SCOM_FWMS5_ADDRESS = 12;
static const uint32_t SCOM_FWMS5_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS5_EXIT_1 = 23;
static const uint32_t SCOM_FWMS5_EXIT_2 = 24;


static const uint64_t SCOM_FWMS6 = 0x801181Eull;

static const uint32_t SCOM_FWMS6_MARK = 0;
static const uint32_t SCOM_FWMS6_MARK_LEN = 8;
static const uint32_t SCOM_FWMS6_TYPE = 8;
static const uint32_t SCOM_FWMS6_REGION = 9;
static const uint32_t SCOM_FWMS6_REGION_LEN = 3;
static const uint32_t SCOM_FWMS6_ADDRESS = 12;
static const uint32_t SCOM_FWMS6_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS6_EXIT_1 = 23;
static const uint32_t SCOM_FWMS6_EXIT_2 = 24;


static const uint64_t SCOM_FWMS7 = 0x801181Full;

static const uint32_t SCOM_FWMS7_MARK = 0;
static const uint32_t SCOM_FWMS7_MARK_LEN = 8;
static const uint32_t SCOM_FWMS7_TYPE = 8;
static const uint32_t SCOM_FWMS7_REGION = 9;
static const uint32_t SCOM_FWMS7_REGION_LEN = 3;
static const uint32_t SCOM_FWMS7_ADDRESS = 12;
static const uint32_t SCOM_FWMS7_ADDRESS_LEN = 11;
static const uint32_t SCOM_FWMS7_EXIT_1 = 23;
static const uint32_t SCOM_FWMS7_EXIT_2 = 24;


static const uint64_t SCOM_HWMS0 = 0x8011810ull;

static const uint32_t SCOM_HWMS0_CHIPMARK = 0;
static const uint32_t SCOM_HWMS0_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS0_CONFIRMED = 8;
static const uint32_t SCOM_HWMS0_EXIT_1 = 9;
static const uint32_t SCOM_HWMS0_EXIT_2 = 10;


static const uint64_t SCOM_HWMS1 = 0x8011811ull;

static const uint32_t SCOM_HWMS1_CHIPMARK = 0;
static const uint32_t SCOM_HWMS1_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS1_CONFIRMED = 8;
static const uint32_t SCOM_HWMS1_EXIT_1 = 9;
static const uint32_t SCOM_HWMS1_EXIT_2 = 10;


static const uint64_t SCOM_HWMS2 = 0x8011812ull;

static const uint32_t SCOM_HWMS2_CHIPMARK = 0;
static const uint32_t SCOM_HWMS2_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS2_CONFIRMED = 8;
static const uint32_t SCOM_HWMS2_EXIT_1 = 9;
static const uint32_t SCOM_HWMS2_EXIT_2 = 10;


static const uint64_t SCOM_HWMS3 = 0x8011813ull;

static const uint32_t SCOM_HWMS3_CHIPMARK = 0;
static const uint32_t SCOM_HWMS3_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS3_CONFIRMED = 8;
static const uint32_t SCOM_HWMS3_EXIT_1 = 9;
static const uint32_t SCOM_HWMS3_EXIT_2 = 10;


static const uint64_t SCOM_HWMS4 = 0x8011814ull;

static const uint32_t SCOM_HWMS4_CHIPMARK = 0;
static const uint32_t SCOM_HWMS4_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS4_CONFIRMED = 8;
static const uint32_t SCOM_HWMS4_EXIT_1 = 9;
static const uint32_t SCOM_HWMS4_EXIT_2 = 10;


static const uint64_t SCOM_HWMS5 = 0x8011815ull;

static const uint32_t SCOM_HWMS5_CHIPMARK = 0;
static const uint32_t SCOM_HWMS5_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS5_CONFIRMED = 8;
static const uint32_t SCOM_HWMS5_EXIT_1 = 9;
static const uint32_t SCOM_HWMS5_EXIT_2 = 10;


static const uint64_t SCOM_HWMS6 = 0x8011816ull;

static const uint32_t SCOM_HWMS6_CHIPMARK = 0;
static const uint32_t SCOM_HWMS6_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS6_CONFIRMED = 8;
static const uint32_t SCOM_HWMS6_EXIT_1 = 9;
static const uint32_t SCOM_HWMS6_EXIT_2 = 10;


static const uint64_t SCOM_HWMS7 = 0x8011817ull;

static const uint32_t SCOM_HWMS7_CHIPMARK = 0;
static const uint32_t SCOM_HWMS7_CHIPMARK_LEN = 8;
static const uint32_t SCOM_HWMS7_CONFIRMED = 8;
static const uint32_t SCOM_HWMS7_EXIT_1 = 9;
static const uint32_t SCOM_HWMS7_EXIT_2 = 10;


static const uint64_t SCOM_MASK0 = 0x8011830ull;

static const uint32_t SCOM_MASK0_MSR_PE = 12;
static const uint32_t SCOM_MASK0_EICR_PE = 13;
static const uint32_t SCOM_MASK0_HWMSX_PE = 16;
static const uint32_t SCOM_MASK0_HWMSX_PE_LEN = 8;
static const uint32_t SCOM_MASK0_FWMSX_PE = 24;
static const uint32_t SCOM_MASK0_FWMSX_PE_LEN = 8;
static const uint32_t SCOM_MASK0_RSPAR_PE = 32;
static const uint32_t SCOM_MASK0_AACR_PE = 41;
static const uint32_t SCOM_MASK0_DBGR_PE = 46;
static const uint32_t SCOM_MASK0_MASK0_PE = 48;
static const uint32_t SCOM_MASK0_MASK1_PE = 49;
static const uint32_t SCOM_MASK0_CGDR_PE = 50;
static const uint32_t SCOM_MASK0_MCBCM_PE = 52;
static const uint32_t SCOM_MASK0_MCBCM2_PE = 53;
static const uint32_t SCOM_MASK0_DQERRA0M0_PE = 54;
static const uint32_t SCOM_MASK0_DQERRA0M1_PE = 55;
static const uint32_t SCOM_MASK0_DQERRB0M0_PE = 56;
static const uint32_t SCOM_MASK0_DQERRB0M1_PE = 57;


static const uint64_t SCOM_MASK1 = 0x8011831ull;

static const uint32_t SCOM_MASK1_ECC_CTL_AF_PERR = 0;
static const uint32_t SCOM_MASK1_ECC_CTL_TCHN_PERR = 1;
static const uint32_t SCOM_MASK1_ECC_CTL_CMPMODE_ERR = 2;
static const uint32_t SCOM_MASK1_ECC_PIPE_PCX_PERR = 3;
static const uint32_t SCOM_MASK1_ECC_PIPE_SYND_PERR = 4;
static const uint32_t SCOM_MASK1_ECC_PIPE_2SYM_PERR = 5;
static const uint32_t SCOM_MASK1_ECC_PIPE_CPLX_PERR = 6;
static const uint32_t SCOM_MASK1_ECC_PIPE_EP2_PERR = 7;
static const uint32_t SCOM_MASK1_READ_ECC_DATAPATH_PARITY_ERROR = 8;
static const uint32_t SCOM_MASK1_ECC_PIPE_CMX_PERR = 9;
static const uint32_t SCOM_MASK1_ECC_PIPE_VP1_PERR = 10;
static const uint32_t SCOM_MASK1_ECC_PIPE_VP2_PERR = 11;
static const uint32_t SCOM_MASK1_ECC_PIPE_SYG_PERR = 12;
static const uint32_t SCOM_MASK1_ECC_PIPE_EF1_PERR = 13;
static const uint32_t SCOM_MASK1_ECC_PIPE_MK3_PERR = 14;
static const uint32_t SCOM_MASK1_ECC_PIPE_E1A_PERR = 15;
static const uint32_t SCOM_MASK1_UNEXPECTED_RDDATA_VALID = 16;
static const uint32_t SCOM_MASK1_MISSING_RDDATA_VALID = 17;
static const uint32_t SCOM_MASK1_SUE_01_DETECT = 18;
static const uint32_t SCOM_MASK1_SUE_10_DETECT = 19;


static const uint64_t SCOM_MCBCM = 0x8011834ull;

static const uint32_t SCOM_MCBCM_HALF_COMPARE_MASK = 0;
static const uint32_t SCOM_MCBCM_HALF_COMPARE_MASK_LEN = 40;
static const uint32_t SCOM_MCBCM_MASK_COVERAGE_SELECTOR = 40;
static const uint32_t SCOM_MCBCM_TRAP_NONSTOP = 41;
static const uint32_t SCOM_MCBCM_TRAP_CE_ENABLE = 42;
static const uint32_t SCOM_MCBCM_TRAP_MPE_ENABLE = 43;
static const uint32_t SCOM_MCBCM_TRAP_UE_ENABLE = 44;


static const uint64_t SCOM_MCBCM2 = 0x8011835ull;

static const uint32_t SCOM_MCBCM2_MCBCM2_MCBIST_HALF_COMPARE_MASK = 0;
static const uint32_t SCOM_MCBCM2_MCBCM2_MCBIST_HALF_COMPARE_MASK_LEN = 40;


static const uint64_t SCOM_MSR = 0x801180Cull;

static const uint32_t SCOM_MSR_CHIPMARK = 8;
static const uint32_t SCOM_MSR_CHIPMARK_LEN = 8;
static const uint32_t SCOM_MSR_RANK = 16;
static const uint32_t SCOM_MSR_RANK_LEN = 3;


static const uint64_t SCOM_RDFCFGLXSTOP = 0x8011807ull;

static const uint32_t SCOM_RDFCFGLXSTOP_CFG_LXSTOP = 0;
static const uint32_t SCOM_RDFCFGLXSTOP_CFG_LXSTOP_LEN = 63;


static const uint64_t SCOM_RDFCFGRECOV = 0x8011805ull;

static const uint32_t SCOM_RDFCFGRECOV_CFG_RECOV = 0;
static const uint32_t SCOM_RDFCFGRECOV_CFG_RECOV_LEN = 63;


static const uint64_t SCOM_RDFCFGSPATTN = 0x8011806ull;

static const uint32_t SCOM_RDFCFGSPATTN_CFG_SPATTN = 0;
static const uint32_t SCOM_RDFCFGSPATTN_CFG_SPATTN_LEN = 63;


static const uint64_t SCOM_RDFCFGXSTOP = 0x8011804ull;

static const uint32_t SCOM_RDFCFGXSTOP_CFG_XSTOP = 0;
static const uint32_t SCOM_RDFCFGXSTOP_CFG_XSTOP_LEN = 63;


static const uint64_t SCOM_RDFFIRMASK_WO_OR = 0x8011803ull;
static const uint64_t SCOM_RDFFIRMASK_RW_WCLEAR = 0x8011802ull;

static const uint32_t SCOM_RDFFIRMASK_FIR_MASK = 0;
static const uint32_t SCOM_RDFFIRMASK_FIR_MASK_LEN = 63;


static const uint64_t SCOM_RDFFIRWOF = 0x8011808ull;

static const uint32_t SCOM_RDFFIRWOF_RDFFIRWOF_FIR_WOF = 0;
static const uint32_t SCOM_RDFFIRWOF_RDFFIRWOF_FIR_WOF_LEN = 63;


static const uint64_t SCOM_RSPAR = 0x8011820ull;

static const uint32_t SCOM_RSPAR_0_LEFT = 0;
static const uint32_t SCOM_RSPAR_0_LEFT_LEN = 5;
static const uint32_t SCOM_RSPAR_0_RIGHT = 5;
static const uint32_t SCOM_RSPAR_0_RIGHT_LEN = 5;
static const uint32_t SCOM_RSPAR_1_LEFT = 10;
static const uint32_t SCOM_RSPAR_1_LEFT_LEN = 5;
static const uint32_t SCOM_RSPAR_1_RIGHT = 15;
static const uint32_t SCOM_RSPAR_1_RIGHT_LEN = 5;
static const uint32_t SCOM_RSPAR_2_LEFT = 20;
static const uint32_t SCOM_RSPAR_2_LEFT_LEN = 5;
static const uint32_t SCOM_RSPAR_2_RIGHT = 25;
static const uint32_t SCOM_RSPAR_2_RIGHT_LEN = 5;
static const uint32_t SCOM_RSPAR_3_LEFT = 30;
static const uint32_t SCOM_RSPAR_3_LEFT_LEN = 5;
static const uint32_t SCOM_RSPAR_3_RIGHT = 35;
static const uint32_t SCOM_RSPAR_3_RIGHT_LEN = 5;



#ifndef __PPE_HCODE__
}
}
#endif

#ifndef SCOMT_OMIT_FIELD_ACCESSORS
    #include "ody_scom_mp_rdf_fields.H"
#endif
