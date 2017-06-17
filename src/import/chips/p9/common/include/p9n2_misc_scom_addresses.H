/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/common/include/p9n2_misc_scom_addresses.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
///
/// @file p9_misc_scom_addresses.H
/// @brief  Defines constants for scom addresses
///
// *HWP HWP Owner: Ben Gass <bgass@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: SOA
// *HWP Level: 1
// *HWP Consumed by: FSP:HB:HS:OCC:SBE:CME:SGPE:PGPE:FPPE:IPPE

/*---------------------------------------------------------------
 *
 *---------------------------------------------------------------
 *
 *---------------------------------------------------------------
 */

#ifndef __P9N2_MISC_SCOM_ADDRESSES_H
#define __P9N2_MISC_SCOM_ADDRESSES_H

#include <stdint.h>


static const uint64_t P9N2_PHB_ACT0_REG                                            = 0x0D01090Eull;

static const uint64_t P9N2_PHB_0_ACT0_REG                                          = 0x0D01090Eull;

static const uint64_t P9N2_PHB_1_ACT0_REG                                          = 0x0E01090Eull;

static const uint64_t P9N2_PHB_2_ACT0_REG                                          = 0x0E01094Eull;

static const uint64_t P9N2_PHB_3_ACT0_REG                                          = 0x0F01090Eull;

static const uint64_t P9N2_PHB_4_ACT0_REG                                          = 0x0F01094Eull;

static const uint64_t P9N2_PHB_5_ACT0_REG                                          = 0x0F01098Eull;


static const uint64_t P9N2_PHB_ACTION1_REG                                         = 0x0D01090Full;

static const uint64_t P9N2_PHB_0_ACTION1_REG                                       = 0x0D01090Full;

static const uint64_t P9N2_PHB_1_ACTION1_REG                                       = 0x0E01090Full;

static const uint64_t P9N2_PHB_2_ACTION1_REG                                       = 0x0E01094Full;

static const uint64_t P9N2_PHB_3_ACTION1_REG                                       = 0x0F01090Full;

static const uint64_t P9N2_PHB_4_ACTION1_REG                                       = 0x0F01094Full;

static const uint64_t P9N2_PHB_5_ACTION1_REG                                       = 0x0F01098Full;


static const uint64_t P9N2_PEC_ADDREXTMASK_REG                                     = 0x04010C05ull;

static const uint64_t P9N2_PEC_0_ADDREXTMASK_REG                                   = 0x04010C05ull;

static const uint64_t P9N2_PEC_1_ADDREXTMASK_REG                                   = 0x04011005ull;

static const uint64_t P9N2_PEC_2_ADDREXTMASK_REG                                   = 0x04011405ull;


static const uint64_t P9N2_PU_ADDR_0_HASH_FUNCTION_REG                             = 0x02011141ull;


static const uint64_t P9N2_PU_ADDR_10_HASH_FUNCTION_REG                            = 0x0201114Bull;


static const uint64_t P9N2_PU_ADDR_1_HASH_FUNCTION_REG                             = 0x02011142ull;


static const uint64_t P9N2_PU_ADDR_2_HASH_FUNCTION_REG                             = 0x02011143ull;


static const uint64_t P9N2_PU_ADDR_3_HASH_FUNCTION_REG                             = 0x02011144ull;


static const uint64_t P9N2_PU_ADDR_4_HASH_FUNCTION_REG                             = 0x02011145ull;


static const uint64_t P9N2_PU_ADDR_5_HASH_FUNCTION_REG                             = 0x02011146ull;


static const uint64_t P9N2_PU_ADDR_6_HASH_FUNCTION_REG                             = 0x02011147ull;


static const uint64_t P9N2_PU_ADDR_7_HASH_FUNCTION_REG                             = 0x02011148ull;


static const uint64_t P9N2_PU_ADDR_8_HASH_FUNCTION_REG                             = 0x02011149ull;


static const uint64_t P9N2_PU_ADDR_9_HASH_FUNCTION_REG                             = 0x0201114Aull;


static const uint64_t P9N2_PU_ADDR_TRAP_REG                                        = 0x06010003ull;


static const uint64_t P9N2_PEC_ADDR_TRAP_REG                                       = 0x0D010003ull;

static const uint64_t P9N2_PEC_0_ADDR_TRAP_REG                                     = 0x0D010003ull;

static const uint64_t P9N2_PEC_1_ADDR_TRAP_REG                                     = 0x0E010003ull;

static const uint64_t P9N2_PEC_2_ADDR_TRAP_REG                                     = 0x0F010003ull;


static const uint64_t P9N2_PU_N0_ADDR_TRAP_REG                                     = 0x02010003ull;

static const uint64_t P9N2_PU_N1_ADDR_TRAP_REG                                     = 0x03010003ull;

static const uint64_t P9N2_PU_N2_ADDR_TRAP_REG                                     = 0x04010003ull;

static const uint64_t P9N2_PU_N3_ADDR_TRAP_REG                                     = 0x05010003ull;


static const uint64_t P9N2_PU_ADS_XSCOM_CMD_REG                                    = 0x0009001Cull;


static const uint64_t P9N2_PU_ADU_HANG_DIV_REG                                     = 0x00090050ull;


static const uint64_t P9N2_PU_ALTD_ADDR_REG                                        = 0x00090000ull;


static const uint64_t P9N2_PU_ALTD_CMD_REG                                         = 0x00090001ull;


static const uint64_t P9N2_PU_ALTD_DATA_REG                                        = 0x00090004ull;


static const uint64_t P9N2_PU_ALTD_OPTION_REG                                      = 0x00090002ull;


static const uint64_t P9N2_PU_ALTD_STATUS_REG                                      = 0x00090003ull;


static const uint64_t P9N2_PU_NPU_CTL_ALTER_CREDIT_COUNTERS                        = 0x05011390ull;

static const uint64_t P9N2_PU_NPU_SM3_ALTER_CREDIT_COUNTERS                        = 0x05011360ull;

static const uint64_t P9N2__CTL_ALTER_CREDIT_COUNTERS                              = 0x05011590ull;

static const uint64_t P9N2__SM3_ALTER_CREDIT_COUNTERS                              = 0x05011560ull;


static const uint64_t P9N2_CAPP_APCFG                                              = 0x02010819ull;

static const uint64_t P9N2_CAPP_0_APCFG                                            = 0x02010819ull;

static const uint64_t P9N2_CAPP_1_APCFG                                            = 0x04010819ull;


static const uint64_t P9N2_CAPP_APCLCO                                             = 0x02010821ull;

static const uint64_t P9N2_CAPP_0_APCLCO                                           = 0x02010821ull;

static const uint64_t P9N2_CAPP_1_APCLCO                                           = 0x04010821ull;


static const uint64_t P9N2_CAPP_APCRDFSMMASK                                       = 0x02010823ull;

static const uint64_t P9N2_CAPP_0_APCRDFSMMASK                                     = 0x02010823ull;

static const uint64_t P9N2_CAPP_1_APCRDFSMMASK                                     = 0x04010823ull;


static const uint64_t P9N2_CAPP_APCTL                                              = 0x02010818ull;

static const uint64_t P9N2_CAPP_0_APCTL                                            = 0x02010818ull;

static const uint64_t P9N2_CAPP_1_APCTL                                            = 0x04010818ull;


static const uint64_t P9N2_CAPP_APC_ARRY_ADDR                                      = 0x0201082Aull;

static const uint64_t P9N2_CAPP_0_APC_ARRY_ADDR                                    = 0x0201082Aull;

static const uint64_t P9N2_CAPP_1_APC_ARRY_ADDR                                    = 0x0401082Aull;


static const uint64_t P9N2_CAPP_APC_ARRY_RDDATA                                    = 0x0201082Bull;

static const uint64_t P9N2_CAPP_0_APC_ARRY_RDDATA                                  = 0x0201082Bull;

static const uint64_t P9N2_CAPP_1_APC_ARRY_RDDATA                                  = 0x0401082Bull;


static const uint64_t P9N2_CAPP_APC_ARRY_WRDATA                                    = 0x02010842ull;

static const uint64_t P9N2_CAPP_0_APC_ARRY_WRDATA                                  = 0x02010842ull;

static const uint64_t P9N2_CAPP_1_APC_ARRY_WRDATA                                  = 0x04010842ull;


static const uint64_t P9N2_CAPP_APC_ERRINJ                                         = 0x02010810ull;

static const uint64_t P9N2_CAPP_0_APC_ERRINJ                                       = 0x02010810ull;

static const uint64_t P9N2_CAPP_1_APC_ERRINJ                                       = 0x04010810ull;


static const uint64_t P9N2_CAPP_APC_PMUSEL                                         = 0x02010816ull;

static const uint64_t P9N2_CAPP_0_APC_PMUSEL                                       = 0x02010816ull;

static const uint64_t P9N2_CAPP_1_APC_PMUSEL                                       = 0x04010816ull;


static const uint64_t P9N2_CAPP_ASE_TUPLE0                                         = 0x02010846ull;

static const uint64_t P9N2_CAPP_0_ASE_TUPLE0                                       = 0x02010846ull;

static const uint64_t P9N2_CAPP_1_ASE_TUPLE0                                       = 0x04010846ull;


static const uint64_t P9N2_CAPP_ASE_TUPLE1                                         = 0x02010847ull;

static const uint64_t P9N2_CAPP_0_ASE_TUPLE1                                       = 0x02010847ull;

static const uint64_t P9N2_CAPP_1_ASE_TUPLE1                                       = 0x04010847ull;


static const uint64_t P9N2_CAPP_ASE_TUPLE2                                         = 0x02010848ull;

static const uint64_t P9N2_CAPP_0_ASE_TUPLE2                                       = 0x02010848ull;

static const uint64_t P9N2_CAPP_1_ASE_TUPLE2                                       = 0x04010848ull;


static const uint64_t P9N2_CAPP_ASE_TUPLE3                                         = 0x02010849ull;

static const uint64_t P9N2_CAPP_0_ASE_TUPLE3                                       = 0x02010849ull;

static const uint64_t P9N2_CAPP_1_ASE_TUPLE3                                       = 0x04010849ull;


static const uint64_t P9N2_PEC_ASSIST_INTERRUPT_REG                                = 0x0D0F0011ull;

static const uint64_t P9N2_PEC_0_ASSIST_INTERRUPT_REG                              = 0x0D0F0011ull;

static const uint64_t P9N2_PEC_1_ASSIST_INTERRUPT_REG                              = 0x0E0F0011ull;

static const uint64_t P9N2_PEC_2_ASSIST_INTERRUPT_REG                              = 0x0F0F0011ull;


static const uint64_t P9N2_PU_ATOMIC_LOCK_MASK_LATCH_REG                           = 0x06010007ull;


static const uint64_t P9N2_PEC_ATOMIC_LOCK_MASK_LATCH_REG                          = 0x0D010007ull;

static const uint64_t P9N2_PEC_0_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x0D010007ull;

static const uint64_t P9N2_PEC_1_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x0E010007ull;

static const uint64_t P9N2_PEC_2_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x0F010007ull;


static const uint64_t P9N2_PU_N0_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x02010007ull;

static const uint64_t P9N2_PU_N1_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x03010007ull;

static const uint64_t P9N2_PU_N2_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x04010007ull;

static const uint64_t P9N2_PU_N3_ATOMIC_LOCK_MASK_LATCH_REG                        = 0x05010007ull;


static const uint64_t P9N2_PEC_ATOMIC_LOCK_REG                                     = 0x0D0F03FFull;

static const uint64_t P9N2_PEC_0_ATOMIC_LOCK_REG                                   = 0x0D0F03FFull;

static const uint64_t P9N2_PEC_1_ATOMIC_LOCK_REG                                   = 0x0E0F03FFull;

static const uint64_t P9N2_PEC_2_ATOMIC_LOCK_REG                                   = 0x0F0F03FFull;


static const uint64_t P9N2_PU_NPU1_SM1_ATR_HA_PTR                                  = 0x05011122ull;

static const uint64_t P9N2_PU_NPU1_SM2_ATR_HA_PTR                                  = 0x05011142ull;

static const uint64_t P9N2_PU_NPU_SM1_ATR_HA_PTR                                   = 0x05011322ull;

static const uint64_t P9N2_PU_NPU_SM2_ATR_HA_PTR                                   = 0x05011342ull;

static const uint64_t P9N2__SM1_ATR_HA_PTR                                         = 0x05011522ull;

static const uint64_t P9N2__SM2_ATR_HA_PTR                                         = 0x05011542ull;


static const uint64_t P9N2__SM0_ATS_CKSW                                           = 0x05011604ull;


static const uint64_t P9N2__SM1_ATS_CTRL                                           = 0x05011620ull;


static const uint64_t P9N2__SM0_ATS_HOLD                                           = 0x05011605ull;


static const uint64_t P9N2__SM0_ATS_MASK                                           = 0x05011606ull;


static const uint64_t P9N2__SM1_ATS_TCR                                            = 0x05011626ull;


static const uint64_t P9N2_PEC_ATTN_INTERRUPT_REG                                  = 0x0D0F001Aull;

static const uint64_t P9N2_PEC_0_ATTN_INTERRUPT_REG                                = 0x0D0F001Aull;

static const uint64_t P9N2_PEC_1_ATTN_INTERRUPT_REG                                = 0x0E0F001Aull;

static const uint64_t P9N2_PEC_2_ATTN_INTERRUPT_REG                                = 0x0F0F001Aull;


static const uint64_t P9N2_PU_BANK0_MCD_BOT                                        = 0x0301140Cull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_BOT                                   = 0x0301100Cull;


static const uint64_t P9N2_PU_BANK0_MCD_CHA                                        = 0x0301140Dull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_CHA                                   = 0x0301100Dull;


static const uint64_t P9N2_PU_BANK0_MCD_CMD                                        = 0x0301140Eull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_CMD                                   = 0x0301100Eull;


static const uint64_t P9N2_PU_BANK0_MCD_REC                                        = 0x03011410ull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_REC                                   = 0x03011010ull;


static const uint64_t P9N2_PU_BANK0_MCD_RW                                         = 0x0301140Full;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_RW                                    = 0x0301100Full;


static const uint64_t P9N2_PU_BANK0_MCD_STR                                        = 0x0301140Bull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_STR                                   = 0x0301100Bull;


static const uint64_t P9N2_PU_BANK0_MCD_TOP                                        = 0x0301140Aull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_TOP                                   = 0x0301100Aull;


static const uint64_t P9N2_PU_BANK0_MCD_VGC                                        = 0x03011411ull;

static const uint64_t P9N2_PU_MCD1_BANK0_MCD_VGC                                   = 0x03011011ull;


static const uint64_t P9N2_PEC_0_STACK0_BARE_REG                                   = 0x04010C54ull;

static const uint64_t P9N2_PEC_1_STACK0_BARE_REG                                   = 0x04011054ull;

static const uint64_t P9N2_PEC_1_STACK1_BARE_REG                                   = 0x04011094ull;

static const uint64_t P9N2_PEC_1_STACK2_BARE_REG                                   = 0x040110D4ull;

static const uint64_t P9N2_PEC_2_STACK0_BARE_REG                                   = 0x04011454ull;

static const uint64_t P9N2_PEC_2_STACK1_BARE_REG                                   = 0x04011494ull;

static const uint64_t P9N2_PEC_2_STACK2_BARE_REG                                   = 0x040114D4ull;

static const uint64_t P9N2_PEC_STACK0_BARE_REG                                     = 0x04010C54ull;

static const uint64_t P9N2_PHB_BARE_REG                                            = 0x04010C54ull;

static const uint64_t P9N2_PHB_0_BARE_REG                                          = 0x04010C54ull;

static const uint64_t P9N2_PHB_1_BARE_REG                                          = 0x04011054ull;

static const uint64_t P9N2_PHB_2_BARE_REG                                          = 0x04011094ull;

static const uint64_t P9N2_PHB_3_BARE_REG                                          = 0x04011454ull;

static const uint64_t P9N2_PHB_4_BARE_REG                                          = 0x04011494ull;

static const uint64_t P9N2_PHB_5_BARE_REG                                          = 0x040114D4ull;


static const uint64_t P9N2_PU_BCDE_CTL_OCI                                         = 0xC0040080ull;

static const uint64_t P9N2_PU_BCDE_CTL_PIB                                         = 0x00068010ull;


static const uint64_t P9N2_PU_BCDE_OCIBAR_OCI                                      = 0xC00400A0ull;

static const uint64_t P9N2_PU_BCDE_OCIBAR_PIB                                      = 0x00068014ull;


static const uint64_t P9N2_PU_BCDE_PBADR_OCI                                       = 0xC0040098ull;

static const uint64_t P9N2_PU_BCDE_PBADR_PIB                                       = 0x00068013ull;


static const uint64_t P9N2_PU_BCDE_SET_OCI                                         = 0xC0040088ull;

static const uint64_t P9N2_PU_BCDE_SET_PIB                                         = 0x00068011ull;


static const uint64_t P9N2_PU_BCDE_STAT_OCI                                        = 0xC0040090ull;

static const uint64_t P9N2_PU_BCDE_STAT_PIB                                        = 0x00068012ull;


static const uint64_t P9N2_PU_BCUE_CTL_OCI                                         = 0xC00400A8ull;

static const uint64_t P9N2_PU_BCUE_CTL_PIB                                         = 0x00068015ull;


static const uint64_t P9N2_PU_BCUE_OCIBAR_OCI                                      = 0xC00400C8ull;

static const uint64_t P9N2_PU_BCUE_OCIBAR_PIB                                      = 0x00068019ull;


static const uint64_t P9N2_PU_BCUE_PBADR_OCI                                       = 0xC00400C0ull;

static const uint64_t P9N2_PU_BCUE_PBADR_PIB                                       = 0x00068018ull;


static const uint64_t P9N2_PU_BCUE_SET_OCI                                         = 0xC00400B0ull;

static const uint64_t P9N2_PU_BCUE_SET_PIB                                         = 0x00068016ull;


static const uint64_t P9N2_PU_BCUE_STAT_OCI                                        = 0xC00400B8ull;

static const uint64_t P9N2_PU_BCUE_STAT_PIB                                        = 0x00068017ull;


static const uint64_t P9N2_PU_BDF2PE_00_CONFIG                                     = 0x050116A0ull;

static const uint64_t P9N2_NV_BDF2PE_00_CONFIG                                     = 0x050110CAull;

static const uint64_t P9N2_NV_0_BDF2PE_00_CONFIG                                   = 0x050110CAull;

static const uint64_t P9N2_NV_4_BDF2PE_00_CONFIG                                   = 0x050114CAull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_00_CONFIG                           = 0x050112CAull;


static const uint64_t P9N2_PU_BDF2PE_01_CONFIG                                     = 0x050116A1ull;

static const uint64_t P9N2_NV_BDF2PE_01_CONFIG                                     = 0x050110CBull;

static const uint64_t P9N2_NV_0_BDF2PE_01_CONFIG                                   = 0x050110CBull;

static const uint64_t P9N2_NV_4_BDF2PE_01_CONFIG                                   = 0x050114CBull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_01_CONFIG                           = 0x050112CBull;


static const uint64_t P9N2_PU_BDF2PE_02_CONFIG                                     = 0x050116A2ull;

static const uint64_t P9N2_NV_BDF2PE_02_CONFIG                                     = 0x050110CCull;

static const uint64_t P9N2_NV_0_BDF2PE_02_CONFIG                                   = 0x050110CCull;

static const uint64_t P9N2_NV_4_BDF2PE_02_CONFIG                                   = 0x050114CCull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_02_CONFIG                           = 0x050112CCull;


static const uint64_t P9N2_PU_BDF2PE_10_CONFIG                                     = 0x050116A3ull;

static const uint64_t P9N2_NV_BDF2PE_10_CONFIG                                     = 0x050110CDull;

static const uint64_t P9N2_NV_0_BDF2PE_10_CONFIG                                   = 0x050110CDull;

static const uint64_t P9N2_NV_4_BDF2PE_10_CONFIG                                   = 0x050114CDull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_10_CONFIG                           = 0x050112CDull;


static const uint64_t P9N2_PU_BDF2PE_11_CONFIG                                     = 0x050116A4ull;

static const uint64_t P9N2_NV_BDF2PE_11_CONFIG                                     = 0x050110CEull;

static const uint64_t P9N2_NV_0_BDF2PE_11_CONFIG                                   = 0x050110CEull;

static const uint64_t P9N2_NV_4_BDF2PE_11_CONFIG                                   = 0x050114CEull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_11_CONFIG                           = 0x050112CEull;


static const uint64_t P9N2_PU_BDF2PE_12_CONFIG                                     = 0x050116A5ull;

static const uint64_t P9N2_NV_BDF2PE_12_CONFIG                                     = 0x050110CFull;

static const uint64_t P9N2_NV_0_BDF2PE_12_CONFIG                                   = 0x050110CFull;

static const uint64_t P9N2_NV_4_BDF2PE_12_CONFIG                                   = 0x050114CFull;

static const uint64_t P9N2_PU_NPU2_NTL0_BDF2PE_12_CONFIG                           = 0x050112CFull;


static const uint64_t P9N2_PU_BDF2PE_20_CONFIG                                     = 0x050116A6ull;


static const uint64_t P9N2_PU_BDF2PE_21_CONFIG                                     = 0x050116A7ull;


static const uint64_t P9N2_PU_BDF2PE_22_CONFIG                                     = 0x050116A8ull;


static const uint64_t P9N2_PU_BDF2PE_30_CONFIG                                     = 0x050116A9ull;


static const uint64_t P9N2_PU_BDF2PE_31_CONFIG                                     = 0x050116AAull;


static const uint64_t P9N2_PU_BDF2PE_32_CONFIG                                     = 0x050116ABull;


static const uint64_t P9N2_PU_BDF2PE_40_CONFIG                                     = 0x050116ACull;


static const uint64_t P9N2_PU_BDF2PE_41_CONFIG                                     = 0x050116ADull;


static const uint64_t P9N2_PU_BDF2PE_42_CONFIG                                     = 0x050116AEull;


static const uint64_t P9N2_PU_BDF2PE_50_CONFIG                                     = 0x050116AFull;


static const uint64_t P9N2__DAT_BDF2PE_51_CONFIG                                   = 0x050116B0ull;


static const uint64_t P9N2__DAT_BDF2PE_52_CONFIG                                   = 0x050116B1ull;


static const uint64_t P9N2_PEC_BIST                                                = 0x0D03000Bull;

static const uint64_t P9N2_PEC_0_BIST                                              = 0x0D03000Bull;

static const uint64_t P9N2_PEC_1_BIST                                              = 0x0E03000Bull;

static const uint64_t P9N2_PEC_2_BIST                                              = 0x0F03000Bull;


static const uint64_t P9N2_CAPP_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL                = 0x0201082Cull;

static const uint64_t P9N2_CAPP_0_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL              = 0x0201082Cull;

static const uint64_t P9N2_CAPP_1_CAPP_EPOCH_AND_RECOVERY_TMR_CONTROL              = 0x0401082Cull;


static const uint64_t P9N2_CAPP_CAPP_ERR_STATUS_CONTROL                            = 0x0201080Eull;

static const uint64_t P9N2_CAPP_0_CAPP_ERR_STATUS_CONTROL                          = 0x0201080Eull;

static const uint64_t P9N2_CAPP_1_CAPP_ERR_STATUS_CONTROL                          = 0x0401080Eull;


static const uint64_t P9N2_PEC_CC_ATOMIC_LOCK_REG                                  = 0x0D0303FFull;

static const uint64_t P9N2_PEC_0_CC_ATOMIC_LOCK_REG                                = 0x0D0303FFull;

static const uint64_t P9N2_PEC_1_CC_ATOMIC_LOCK_REG                                = 0x0E0303FFull;

static const uint64_t P9N2_PEC_2_CC_ATOMIC_LOCK_REG                                = 0x0F0303FFull;


static const uint64_t P9N2_PEC_CC_PROTECT_MODE_REG                                 = 0x0D0303FEull;

static const uint64_t P9N2_PEC_0_CC_PROTECT_MODE_REG                               = 0x0D0303FEull;

static const uint64_t P9N2_PEC_1_CC_PROTECT_MODE_REG                               = 0x0E0303FEull;

static const uint64_t P9N2_PEC_2_CC_PROTECT_MODE_REG                               = 0x0F0303FEull;


static const uint64_t P9N2_NV_1_CERR_ECC_FIRST                                     = 0x050110F6ull;

static const uint64_t P9N2_NV_5_CERR_ECC_FIRST                                     = 0x050114F6ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_ECC_FIRST                             = 0x050112F6ull;


static const uint64_t P9N2_NV_1_CERR_ECC_HOLD                                      = 0x050110F4ull;

static const uint64_t P9N2_NV_5_CERR_ECC_HOLD                                      = 0x050114F4ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_ECC_HOLD                              = 0x050112F4ull;


static const uint64_t P9N2_NV_1_CERR_ECC_MASK                                      = 0x050110F5ull;

static const uint64_t P9N2_NV_5_CERR_ECC_MASK                                      = 0x050114F5ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_ECC_MASK                              = 0x050112F5ull;


static const uint64_t P9N2_NV_CERR_FIRST0                                          = 0x050110DAull;

static const uint64_t P9N2_NV_0_CERR_FIRST0                                        = 0x050110DAull;

static const uint64_t P9N2_NV_4_CERR_FIRST0                                        = 0x050114DAull;

static const uint64_t P9N2_PU_NPU0_CERR_FIRST0                                     = 0x050110A7ull;

static const uint64_t P9N2_PU_NPU2_CERR_FIRST0                                     = 0x050112A7ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_FIRST0                                 = 0x05011017ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_FIRST0                                 = 0x05011047ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_FIRST0                                 = 0x05011077ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_FIRST0                                = 0x050112DAull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_FIRST0                                 = 0x05011217ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_FIRST0                                 = 0x05011247ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_FIRST0                                 = 0x05011277ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_FIRST0                                  = 0x050114A7ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_FIRST0                              = 0x05011417ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_FIRST0                              = 0x05011447ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_FIRST0                              = 0x05011477ull;


static const uint64_t P9N2_NV_CERR_FIRST1                                          = 0x050110DBull;

static const uint64_t P9N2_NV_0_CERR_FIRST1                                        = 0x050110DBull;

static const uint64_t P9N2_NV_4_CERR_FIRST1                                        = 0x050114DBull;

static const uint64_t P9N2_PU_NPU0_CERR_FIRST1                                     = 0x050110A8ull;

static const uint64_t P9N2_PU_NPU2_CERR_FIRST1                                     = 0x050112A8ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_FIRST1                                 = 0x05011018ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_FIRST1                                 = 0x05011048ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_FIRST1                                 = 0x05011078ull;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_FIRST1                                 = 0x05011114ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_FIRST1                                 = 0x05011134ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_FIRST1                                = 0x050112DBull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_FIRST1                                 = 0x05011218ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_FIRST1                                 = 0x05011248ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_FIRST1                                 = 0x05011278ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_FIRST1                                  = 0x050114A8ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_FIRST1                              = 0x05011418ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_FIRST1                              = 0x05011448ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_FIRST1                              = 0x05011478ull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_FIRST1                                  = 0x05011314ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_FIRST1                                  = 0x05011334ull;

static const uint64_t P9N2__SM0_CERR_FIRST1                                        = 0x05011514ull;

static const uint64_t P9N2__SM1_CERR_FIRST1                                        = 0x05011534ull;


static const uint64_t P9N2_PU_NPU0_CERR_FIRST2                                     = 0x050110A9ull;

static const uint64_t P9N2_PU_NPU2_CERR_FIRST2                                     = 0x050112A9ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_FIRST2                                 = 0x05011019ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_FIRST2                                 = 0x05011049ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_FIRST2                                 = 0x05011079ull;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_FIRST2                                 = 0x05011118ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_FIRST2                                 = 0x05011138ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_FIRST2                                 = 0x05011219ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_FIRST2                                 = 0x05011249ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_FIRST2                                 = 0x05011279ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_FIRST2                                  = 0x050114A9ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_FIRST2                              = 0x05011419ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_FIRST2                              = 0x05011449ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_FIRST2                              = 0x05011479ull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_FIRST2                                  = 0x05011318ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_FIRST2                                  = 0x05011338ull;

static const uint64_t P9N2__SM0_CERR_FIRST2                                        = 0x05011518ull;

static const uint64_t P9N2__SM1_CERR_FIRST2                                        = 0x05011538ull;


static const uint64_t P9N2_PU_NPU1_SM0_CERR_FIRST_MASK1                            = 0x05011115ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_FIRST_MASK1                            = 0x05011135ull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_FIRST_MASK1                             = 0x05011315ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_FIRST_MASK1                             = 0x05011335ull;

static const uint64_t P9N2__SM0_CERR_FIRST_MASK1                                   = 0x05011515ull;

static const uint64_t P9N2__SM1_CERR_FIRST_MASK1                                   = 0x05011535ull;


static const uint64_t P9N2_PU_NPU1_SM0_CERR_FIRST_MASK2                            = 0x05011119ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_FIRST_MASK2                            = 0x05011139ull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_FIRST_MASK2                             = 0x05011319ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_FIRST_MASK2                             = 0x05011339ull;

static const uint64_t P9N2__SM0_CERR_FIRST_MASK2                                   = 0x05011519ull;

static const uint64_t P9N2__SM1_CERR_FIRST_MASK2                                   = 0x05011539ull;


static const uint64_t P9N2_NV_CERR_HOLD0                                           = 0x050110DEull;

static const uint64_t P9N2_NV_0_CERR_HOLD0                                         = 0x050110DEull;

static const uint64_t P9N2_NV_4_CERR_HOLD0                                         = 0x050114DEull;

static const uint64_t P9N2_PU_NPU0_CERR_HOLD0                                      = 0x050110ADull;

static const uint64_t P9N2_PU_NPU2_CERR_HOLD0                                      = 0x050112ADull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_HOLD0                                  = 0x0501101Dull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_HOLD0                                  = 0x0501104Dull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_HOLD0                                  = 0x0501107Dull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_HOLD0                                 = 0x050112DEull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_HOLD0                                  = 0x0501121Dull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_HOLD0                                  = 0x0501124Dull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_HOLD0                                  = 0x0501127Dull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_HOLD0                                   = 0x050114ADull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_HOLD0                               = 0x0501141Dull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_HOLD0                               = 0x0501144Dull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_HOLD0                               = 0x0501147Dull;


static const uint64_t P9N2_NV_CERR_HOLD1                                           = 0x050110DFull;

static const uint64_t P9N2_NV_0_CERR_HOLD1                                         = 0x050110DFull;

static const uint64_t P9N2_NV_4_CERR_HOLD1                                         = 0x050114DFull;

static const uint64_t P9N2_PU_NPU0_CERR_HOLD1                                      = 0x050110AEull;

static const uint64_t P9N2_PU_NPU2_CERR_HOLD1                                      = 0x050112AEull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_HOLD1                                  = 0x0501101Eull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_HOLD1                                  = 0x0501104Eull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_HOLD1                                  = 0x0501107Eull;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_HOLD1                                  = 0x05011112ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_HOLD1                                  = 0x05011132ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_HOLD1                                 = 0x050112DFull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_HOLD1                                  = 0x0501121Eull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_HOLD1                                  = 0x0501124Eull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_HOLD1                                  = 0x0501127Eull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_HOLD1                                   = 0x050114AEull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_HOLD1                               = 0x0501141Eull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_HOLD1                               = 0x0501144Eull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_HOLD1                               = 0x0501147Eull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_HOLD1                                   = 0x05011312ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_HOLD1                                   = 0x05011332ull;

static const uint64_t P9N2__SM0_CERR_HOLD1                                         = 0x05011512ull;

static const uint64_t P9N2__SM1_CERR_HOLD1                                         = 0x05011532ull;


static const uint64_t P9N2_PU_NPU0_CERR_HOLD2                                      = 0x050110AFull;

static const uint64_t P9N2_PU_NPU2_CERR_HOLD2                                      = 0x050112AFull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_HOLD2                                  = 0x0501101Full;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_HOLD2                                  = 0x0501104Full;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_HOLD2                                  = 0x0501107Full;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_HOLD2                                  = 0x05011116ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_HOLD2                                  = 0x05011136ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_HOLD2                                  = 0x0501121Full;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_HOLD2                                  = 0x0501124Full;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_HOLD2                                  = 0x0501127Full;

static const uint64_t P9N2_PU_NPU_MSC_CERR_HOLD2                                   = 0x050114AFull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_HOLD2                               = 0x0501141Full;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_HOLD2                               = 0x0501144Full;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_HOLD2                               = 0x0501147Full;

static const uint64_t P9N2_PU_NPU_SM0_CERR_HOLD2                                   = 0x05011316ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_HOLD2                                   = 0x05011336ull;

static const uint64_t P9N2__SM0_CERR_HOLD2                                         = 0x05011516ull;

static const uint64_t P9N2__SM1_CERR_HOLD2                                         = 0x05011536ull;


static const uint64_t P9N2_NV_1_CERR_LOG_FIRST                                     = 0x050110FCull;

static const uint64_t P9N2_NV_5_CERR_LOG_FIRST                                     = 0x050114FCull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_LOG_FIRST                             = 0x050112FCull;


static const uint64_t P9N2_NV_1_CERR_LOG_HOLD                                      = 0x050110FAull;

static const uint64_t P9N2_NV_5_CERR_LOG_HOLD                                      = 0x050114FAull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_LOG_HOLD                              = 0x050112FAull;


static const uint64_t P9N2_NV_1_CERR_LOG_MASK                                      = 0x050110FBull;

static const uint64_t P9N2_NV_5_CERR_LOG_MASK                                      = 0x050114FBull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_LOG_MASK                              = 0x050112FBull;


static const uint64_t P9N2_NV_CERR_MASK0                                           = 0x050110DCull;

static const uint64_t P9N2_NV_0_CERR_MASK0                                         = 0x050110DCull;

static const uint64_t P9N2_NV_4_CERR_MASK0                                         = 0x050114DCull;

static const uint64_t P9N2_PU_NPU0_CERR_MASK0                                      = 0x050110AAull;

static const uint64_t P9N2_PU_NPU2_CERR_MASK0                                      = 0x050112AAull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MASK0                                  = 0x0501101Aull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MASK0                                  = 0x0501104Aull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MASK0                                  = 0x0501107Aull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_MASK0                                 = 0x050112DCull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MASK0                                  = 0x0501121Aull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MASK0                                  = 0x0501124Aull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MASK0                                  = 0x0501127Aull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MASK0                                   = 0x050114AAull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MASK0                               = 0x0501141Aull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MASK0                               = 0x0501144Aull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MASK0                               = 0x0501147Aull;


static const uint64_t P9N2_NV_CERR_MASK1                                           = 0x050110DDull;

static const uint64_t P9N2_NV_0_CERR_MASK1                                         = 0x050110DDull;

static const uint64_t P9N2_NV_4_CERR_MASK1                                         = 0x050114DDull;

static const uint64_t P9N2_PU_NPU0_CERR_MASK1                                      = 0x050110ABull;

static const uint64_t P9N2_PU_NPU2_CERR_MASK1                                      = 0x050112ABull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MASK1                                  = 0x0501101Bull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MASK1                                  = 0x0501104Bull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MASK1                                  = 0x0501107Bull;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_MASK1                                  = 0x05011113ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_MASK1                                  = 0x05011133ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_MASK1                                 = 0x050112DDull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MASK1                                  = 0x0501121Bull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MASK1                                  = 0x0501124Bull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MASK1                                  = 0x0501127Bull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MASK1                                   = 0x050114ABull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MASK1                               = 0x0501141Bull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MASK1                               = 0x0501144Bull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MASK1                               = 0x0501147Bull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_MASK1                                   = 0x05011313ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_MASK1                                   = 0x05011333ull;

static const uint64_t P9N2__SM0_CERR_MASK1                                         = 0x05011513ull;

static const uint64_t P9N2__SM1_CERR_MASK1                                         = 0x05011533ull;


static const uint64_t P9N2_PU_NPU0_CERR_MASK2                                      = 0x050110ACull;

static const uint64_t P9N2_PU_NPU2_CERR_MASK2                                      = 0x050112ACull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MASK2                                  = 0x0501101Cull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MASK2                                  = 0x0501104Cull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MASK2                                  = 0x0501107Cull;

static const uint64_t P9N2_PU_NPU1_SM0_CERR_MASK2                                  = 0x05011117ull;

static const uint64_t P9N2_PU_NPU1_SM1_CERR_MASK2                                  = 0x05011137ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MASK2                                  = 0x0501121Cull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MASK2                                  = 0x0501124Cull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MASK2                                  = 0x0501127Cull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MASK2                                   = 0x050114ACull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MASK2                               = 0x0501141Cull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MASK2                               = 0x0501144Cull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MASK2                               = 0x0501147Cull;

static const uint64_t P9N2_PU_NPU_SM0_CERR_MASK2                                   = 0x05011317ull;

static const uint64_t P9N2_PU_NPU_SM1_CERR_MASK2                                   = 0x05011337ull;

static const uint64_t P9N2__SM0_CERR_MASK2                                         = 0x05011517ull;

static const uint64_t P9N2__SM1_CERR_MASK2                                         = 0x05011537ull;


static const uint64_t P9N2_NV_CERR_MESSAGE0                                        = 0x050110D8ull;

static const uint64_t P9N2_NV_0_CERR_MESSAGE0                                      = 0x050110D8ull;

static const uint64_t P9N2_NV_4_CERR_MESSAGE0                                      = 0x050114D8ull;

static const uint64_t P9N2_PU_NPU0_CERR_MESSAGE0                                   = 0x050110A1ull;

static const uint64_t P9N2_PU_NPU2_CERR_MESSAGE0                                   = 0x050112A1ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MESSAGE0                               = 0x05011011ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE0                               = 0x05011041ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MESSAGE0                               = 0x05011071ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_MESSAGE0                              = 0x050112D8ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MESSAGE0                               = 0x05011211ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE0                               = 0x05011241ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MESSAGE0                               = 0x05011271ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MESSAGE0                                = 0x050114A1ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MESSAGE0                            = 0x05011411ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE0                            = 0x05011441ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MESSAGE0                            = 0x05011471ull;


static const uint64_t P9N2_NV_CERR_MESSAGE1                                        = 0x050110D9ull;

static const uint64_t P9N2_NV_0_CERR_MESSAGE1                                      = 0x050110D9ull;

static const uint64_t P9N2_NV_4_CERR_MESSAGE1                                      = 0x050114D9ull;

static const uint64_t P9N2_PU_NPU0_CERR_MESSAGE1                                   = 0x050110A2ull;

static const uint64_t P9N2_PU_NPU2_CERR_MESSAGE1                                   = 0x050112A2ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MESSAGE1                               = 0x05011012ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE1                               = 0x05011042ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MESSAGE1                               = 0x05011072ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CERR_MESSAGE1                              = 0x050112D9ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MESSAGE1                               = 0x05011212ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE1                               = 0x05011242ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MESSAGE1                               = 0x05011272ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MESSAGE1                                = 0x050114A2ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MESSAGE1                            = 0x05011412ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE1                            = 0x05011442ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MESSAGE1                            = 0x05011472ull;


static const uint64_t P9N2_PU_NPU0_CERR_MESSAGE2                                   = 0x050110A3ull;

static const uint64_t P9N2_PU_NPU2_CERR_MESSAGE2                                   = 0x050112A3ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MESSAGE2                               = 0x05011013ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE2                               = 0x05011043ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MESSAGE2                               = 0x05011073ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MESSAGE2                               = 0x05011213ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE2                               = 0x05011243ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MESSAGE2                               = 0x05011273ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MESSAGE2                                = 0x050114A3ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MESSAGE2                            = 0x05011413ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE2                            = 0x05011443ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MESSAGE2                            = 0x05011473ull;


static const uint64_t P9N2_PU_NPU0_CERR_MESSAGE3                                   = 0x050110A4ull;

static const uint64_t P9N2_PU_NPU2_CERR_MESSAGE3                                   = 0x050112A4ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MESSAGE3                               = 0x05011014ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE3                               = 0x05011044ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MESSAGE3                               = 0x05011074ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MESSAGE3                               = 0x05011214ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE3                               = 0x05011244ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MESSAGE3                               = 0x05011274ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MESSAGE3                                = 0x050114A4ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MESSAGE3                            = 0x05011414ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE3                            = 0x05011444ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MESSAGE3                            = 0x05011474ull;


static const uint64_t P9N2_PU_NPU0_CERR_MESSAGE4                                   = 0x050110A5ull;

static const uint64_t P9N2_PU_NPU2_CERR_MESSAGE4                                   = 0x050112A5ull;

static const uint64_t P9N2_PU_NPU0_SM0_CERR_MESSAGE4                               = 0x05011015ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE4                               = 0x05011045ull;

static const uint64_t P9N2_PU_NPU0_SM3_CERR_MESSAGE4                               = 0x05011075ull;

static const uint64_t P9N2_PU_NPU2_SM0_CERR_MESSAGE4                               = 0x05011215ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE4                               = 0x05011245ull;

static const uint64_t P9N2_PU_NPU2_SM3_CERR_MESSAGE4                               = 0x05011275ull;

static const uint64_t P9N2_PU_NPU_MSC_CERR_MESSAGE4                                = 0x050114A5ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CERR_MESSAGE4                            = 0x05011415ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE4                            = 0x05011445ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CERR_MESSAGE4                            = 0x05011475ull;


static const uint64_t P9N2_PU_NPU0_CTL_CERR_MESSAGE5                               = 0x05011085ull;

static const uint64_t P9N2_PU_NPU0_DAT_CERR_MESSAGE5                               = 0x050110B5ull;

static const uint64_t P9N2_PU_NPU2_CTL_CERR_MESSAGE5                               = 0x05011285ull;

static const uint64_t P9N2_PU_NPU2_DAT_CERR_MESSAGE5                               = 0x050112B5ull;

static const uint64_t P9N2_PU_NPU0_SM1_CERR_MESSAGE5                               = 0x05011025ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE5                               = 0x05011055ull;

static const uint64_t P9N2_PU_NPU2_SM1_CERR_MESSAGE5                               = 0x05011225ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE5                               = 0x05011255ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CERR_MESSAGE5                            = 0x05011485ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_CERR_MESSAGE5                            = 0x050114B5ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CERR_MESSAGE5                            = 0x05011425ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE5                            = 0x05011455ull;


static const uint64_t P9N2_PU_NPU0_CTL_CERR_MESSAGE6                               = 0x05011086ull;

static const uint64_t P9N2_PU_NPU0_DAT_CERR_MESSAGE6                               = 0x050110B6ull;

static const uint64_t P9N2_PU_NPU2_CTL_CERR_MESSAGE6                               = 0x05011286ull;

static const uint64_t P9N2_PU_NPU2_DAT_CERR_MESSAGE6                               = 0x050112B6ull;

static const uint64_t P9N2_PU_NPU0_SM1_CERR_MESSAGE6                               = 0x05011026ull;

static const uint64_t P9N2_PU_NPU0_SM2_CERR_MESSAGE6                               = 0x05011056ull;

static const uint64_t P9N2_PU_NPU2_SM1_CERR_MESSAGE6                               = 0x05011226ull;

static const uint64_t P9N2_PU_NPU2_SM2_CERR_MESSAGE6                               = 0x05011256ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CERR_MESSAGE6                            = 0x05011486ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_CERR_MESSAGE6                            = 0x050114B6ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CERR_MESSAGE6                            = 0x05011426ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CERR_MESSAGE6                            = 0x05011456ull;


static const uint64_t P9N2_NV_1_CERR_PTY_FIRST                                     = 0x050110F9ull;

static const uint64_t P9N2_NV_5_CERR_PTY_FIRST                                     = 0x050114F9ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_PTY_FIRST                             = 0x050112F9ull;


static const uint64_t P9N2_NV_1_CERR_PTY_HOLD                                      = 0x050110F7ull;

static const uint64_t P9N2_NV_5_CERR_PTY_HOLD                                      = 0x050114F7ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_PTY_HOLD                              = 0x050112F7ull;


static const uint64_t P9N2_NV_1_CERR_PTY_MASK                                      = 0x050110F8ull;

static const uint64_t P9N2_NV_5_CERR_PTY_MASK                                      = 0x050114F8ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CERR_PTY_MASK                              = 0x050112F8ull;


static const uint64_t P9N2_PEC_0_STACK0_CERR_RPT0_REG                              = 0x04010C4Aull;

static const uint64_t P9N2_PEC_1_STACK0_CERR_RPT0_REG                              = 0x0401104Aull;

static const uint64_t P9N2_PEC_1_STACK1_CERR_RPT0_REG                              = 0x0401108Aull;

static const uint64_t P9N2_PEC_1_STACK2_CERR_RPT0_REG                              = 0x040110CAull;

static const uint64_t P9N2_PEC_2_STACK0_CERR_RPT0_REG                              = 0x0401144Aull;

static const uint64_t P9N2_PEC_2_STACK1_CERR_RPT0_REG                              = 0x0401148Aull;

static const uint64_t P9N2_PEC_2_STACK2_CERR_RPT0_REG                              = 0x040114CAull;

static const uint64_t P9N2_PEC_STACK0_CERR_RPT0_REG                                = 0x04010C4Aull;

static const uint64_t P9N2_PHB_CERR_RPT0_REG                                       = 0x04010C4Aull;

static const uint64_t P9N2_PHB_0_CERR_RPT0_REG                                     = 0x04010C4Aull;

static const uint64_t P9N2_PHB_1_CERR_RPT0_REG                                     = 0x0401104Aull;

static const uint64_t P9N2_PHB_2_CERR_RPT0_REG                                     = 0x0401108Aull;

static const uint64_t P9N2_PHB_3_CERR_RPT0_REG                                     = 0x0401144Aull;

static const uint64_t P9N2_PHB_4_CERR_RPT0_REG                                     = 0x0401148Aull;

static const uint64_t P9N2_PHB_5_CERR_RPT0_REG                                     = 0x040114CAull;


static const uint64_t P9N2_PEC_0_STACK0_CERR_RPT1_REG                              = 0x04010C4Bull;

static const uint64_t P9N2_PEC_1_STACK0_CERR_RPT1_REG                              = 0x0401104Bull;

static const uint64_t P9N2_PEC_1_STACK1_CERR_RPT1_REG                              = 0x0401108Bull;

static const uint64_t P9N2_PEC_1_STACK2_CERR_RPT1_REG                              = 0x040110CBull;

static const uint64_t P9N2_PEC_2_STACK0_CERR_RPT1_REG                              = 0x0401144Bull;

static const uint64_t P9N2_PEC_2_STACK1_CERR_RPT1_REG                              = 0x0401148Bull;

static const uint64_t P9N2_PEC_2_STACK2_CERR_RPT1_REG                              = 0x040114CBull;

static const uint64_t P9N2_PEC_STACK0_CERR_RPT1_REG                                = 0x04010C4Bull;

static const uint64_t P9N2_PHB_CERR_RPT1_REG                                       = 0x04010C4Bull;

static const uint64_t P9N2_PHB_0_CERR_RPT1_REG                                     = 0x04010C4Bull;

static const uint64_t P9N2_PHB_1_CERR_RPT1_REG                                     = 0x0401104Bull;

static const uint64_t P9N2_PHB_2_CERR_RPT1_REG                                     = 0x0401108Bull;

static const uint64_t P9N2_PHB_3_CERR_RPT1_REG                                     = 0x0401144Bull;

static const uint64_t P9N2_PHB_4_CERR_RPT1_REG                                     = 0x0401148Bull;

static const uint64_t P9N2_PHB_5_CERR_RPT1_REG                                     = 0x040114CBull;


static const uint64_t P9N2_PU_NPU_CTL_CHKSW0                                       = 0x05011381ull;

static const uint64_t P9N2_PU_NPU_SM2_CHKSW0                                       = 0x05011351ull;

static const uint64_t P9N2__CTL_CHKSW0                                             = 0x05011581ull;

static const uint64_t P9N2__SM2_CHKSW0                                             = 0x05011551ull;


static const uint64_t P9N2_PEC_CLK_REGION                                          = 0x0D030006ull;

static const uint64_t P9N2_PEC_0_CLK_REGION                                        = 0x0D030006ull;

static const uint64_t P9N2_PEC_1_CLK_REGION                                        = 0x0E030006ull;

static const uint64_t P9N2_PEC_2_CLK_REGION                                        = 0x0F030006ull;


static const uint64_t P9N2_PEC_CLOCK_STAT_ARY                                      = 0x0D03000Aull;

static const uint64_t P9N2_PEC_0_CLOCK_STAT_ARY                                    = 0x0D03000Aull;

static const uint64_t P9N2_PEC_1_CLOCK_STAT_ARY                                    = 0x0E03000Aull;

static const uint64_t P9N2_PEC_2_CLOCK_STAT_ARY                                    = 0x0F03000Aull;


static const uint64_t P9N2_PEC_CLOCK_STAT_NSL                                      = 0x0D030009ull;

static const uint64_t P9N2_PEC_0_CLOCK_STAT_NSL                                    = 0x0D030009ull;

static const uint64_t P9N2_PEC_1_CLOCK_STAT_NSL                                    = 0x0E030009ull;

static const uint64_t P9N2_PEC_2_CLOCK_STAT_NSL                                    = 0x0F030009ull;


static const uint64_t P9N2_PEC_CLOCK_STAT_SL                                       = 0x0D030008ull;

static const uint64_t P9N2_PEC_0_CLOCK_STAT_SL                                     = 0x0D030008ull;

static const uint64_t P9N2_PEC_1_CLOCK_STAT_SL                                     = 0x0E030008ull;

static const uint64_t P9N2_PEC_2_CLOCK_STAT_SL                                     = 0x0F030008ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_DBG_PPE                                 = 0x109010120ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_DBG_PPE1                                = 0x109010138ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_DBG_PPE2                                = 0x109010130ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_DBG_PPE                                 = 0x109020120ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_DBG_PPE1                                = 0x109020138ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_DBG_PPE2                                = 0x109020130ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_DBG_PPE                                 = 0x10A010120ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_DBG_PPE1                                = 0x10A010138ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_DBG_PPE2                                = 0x10A010130ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_DBG_PPE                                 = 0x10A020120ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_DBG_PPE1                                = 0x10A020138ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_DBG_PPE2                                = 0x10A020130ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_DBG_PPE                                 = 0x10B010120ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_DBG_PPE1                                = 0x10B010138ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_DBG_PPE2                                = 0x10B010130ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_DBG_PPE                                 = 0x10B020120ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_DBG_PPE1                                = 0x10B020138ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_DBG_PPE2                                = 0x10B020130ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_DBG_PPE                                 = 0x10C010120ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_DBG_PPE1                                = 0x10C010138ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_DBG_PPE2                                = 0x10C010130ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_DBG_PPE                                 = 0x10C020120ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_DBG_PPE1                                = 0x10C020138ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_DBG_PPE2                                = 0x10C020130ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_DBG_PPE                                 = 0x10D010120ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_DBG_PPE1                                = 0x10D010138ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_DBG_PPE2                                = 0x10D010130ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_DBG_PPE                                 = 0x10D020120ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_DBG_PPE1                                = 0x10D020138ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_DBG_PPE2                                = 0x10D020130ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_DBG_PPE                                = 0x10E010120ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_DBG_PPE1                               = 0x10E010138ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_DBG_PPE2                               = 0x10E010130ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_DBG_PPE                                = 0x10E020120ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_DBG_PPE1                               = 0x10E020138ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_DBG_PPE2                               = 0x10E020130ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EIMR_PPE                                = 0x109010020ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EIMR_PPE1                               = 0x109010038ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EIMR_PPE2                               = 0x109010030ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIMR_PPE                                = 0x109020020ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIMR_PPE1                               = 0x109020038ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIMR_PPE2                               = 0x109020030ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIMR_PPE                                = 0x10A010020ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIMR_PPE1                               = 0x10A010038ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIMR_PPE2                               = 0x10A010030ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIMR_PPE                                = 0x10A020020ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIMR_PPE1                               = 0x10A020038ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIMR_PPE2                               = 0x10A020030ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIMR_PPE                                = 0x10B010020ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIMR_PPE1                               = 0x10B010038ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIMR_PPE2                               = 0x10B010030ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIMR_PPE                                = 0x10B020020ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIMR_PPE1                               = 0x10B020038ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIMR_PPE2                               = 0x10B020030ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIMR_PPE                                = 0x10C010020ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIMR_PPE1                               = 0x10C010038ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIMR_PPE2                               = 0x10C010030ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIMR_PPE                                = 0x10C020020ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIMR_PPE1                               = 0x10C020038ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIMR_PPE2                               = 0x10C020030ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIMR_PPE                                = 0x10D010020ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIMR_PPE1                               = 0x10D010038ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIMR_PPE2                               = 0x10D010030ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIMR_PPE                                = 0x10D020020ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIMR_PPE1                               = 0x10D020038ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIMR_PPE2                               = 0x10D020030ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIMR_PPE                               = 0x10E010020ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIMR_PPE1                              = 0x10E010038ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIMR_PPE2                              = 0x10E010030ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIMR_PPE                               = 0x10E020020ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIMR_PPE1                              = 0x10E020038ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIMR_PPE2                              = 0x10E020030ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EINR_PPE                                = 0x1090100A0ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EINR_PPE                                = 0x1090200A0ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EINR_PPE                                = 0x10A0100A0ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EINR_PPE                                = 0x10A0200A0ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EINR_PPE                                = 0x10B0100A0ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EINR_PPE                                = 0x10B0200A0ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EINR_PPE                                = 0x10C0100A0ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EINR_PPE                                = 0x10C0200A0ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EINR_PPE                                = 0x10D0100A0ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EINR_PPE                                = 0x10D0200A0ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EINR_PPE                               = 0x10E0100A0ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EINR_PPE                               = 0x10E0200A0ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EIPR_PPE                                = 0x109010040ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EIPR_PPE1                               = 0x109010058ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EIPR_PPE2                               = 0x109010050ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIPR_PPE                                = 0x109020040ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIPR_PPE1                               = 0x109020058ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EIPR_PPE2                               = 0x109020050ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIPR_PPE                                = 0x10A010040ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIPR_PPE1                               = 0x10A010058ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EIPR_PPE2                               = 0x10A010050ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIPR_PPE                                = 0x10A020040ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIPR_PPE1                               = 0x10A020058ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EIPR_PPE2                               = 0x10A020050ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIPR_PPE                                = 0x10B010040ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIPR_PPE1                               = 0x10B010058ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EIPR_PPE2                               = 0x10B010050ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIPR_PPE                                = 0x10B020040ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIPR_PPE1                               = 0x10B020058ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EIPR_PPE2                               = 0x10B020050ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIPR_PPE                                = 0x10C010040ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIPR_PPE1                               = 0x10C010058ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EIPR_PPE2                               = 0x10C010050ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIPR_PPE                                = 0x10C020040ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIPR_PPE1                               = 0x10C020058ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EIPR_PPE2                               = 0x10C020050ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIPR_PPE                                = 0x10D010040ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIPR_PPE1                               = 0x10D010058ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EIPR_PPE2                               = 0x10D010050ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIPR_PPE                                = 0x10D020040ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIPR_PPE1                               = 0x10D020058ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EIPR_PPE2                               = 0x10D020050ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIPR_PPE                               = 0x10E010040ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIPR_PPE1                              = 0x10E010058ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EIPR_PPE2                              = 0x10E010050ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIPR_PPE                               = 0x10E020040ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIPR_PPE1                              = 0x10E020058ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EIPR_PPE2                              = 0x10E020050ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EISR_PPE                                = 0x109010000ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EISR_PPE1                               = 0x109010018ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EISR_PPE2                               = 0x109010010ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EISR_PPE                                = 0x109020000ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EISR_PPE1                               = 0x109020018ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EISR_PPE2                               = 0x109020010ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EISR_PPE                                = 0x10A010000ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EISR_PPE1                               = 0x10A010018ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EISR_PPE2                               = 0x10A010010ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EISR_PPE                                = 0x10A020000ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EISR_PPE1                               = 0x10A020018ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EISR_PPE2                               = 0x10A020010ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EISR_PPE                                = 0x10B010000ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EISR_PPE1                               = 0x10B010018ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EISR_PPE2                               = 0x10B010010ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EISR_PPE                                = 0x10B020000ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EISR_PPE1                               = 0x10B020018ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EISR_PPE2                               = 0x10B020010ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EISR_PPE                                = 0x10C010000ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EISR_PPE1                               = 0x10C010018ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EISR_PPE2                               = 0x10C010010ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EISR_PPE                                = 0x10C020000ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EISR_PPE1                               = 0x10C020018ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EISR_PPE2                               = 0x10C020010ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EISR_PPE                                = 0x10D010000ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EISR_PPE1                               = 0x10D010018ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EISR_PPE2                               = 0x10D010010ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EISR_PPE                                = 0x10D020000ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EISR_PPE1                               = 0x10D020018ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EISR_PPE2                               = 0x10D020010ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EISR_PPE                               = 0x10E010000ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EISR_PPE1                              = 0x10E010018ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EISR_PPE2                              = 0x10E010010ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EISR_PPE                               = 0x10E020000ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EISR_PPE1                              = 0x10E020018ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EISR_PPE2                              = 0x10E020010ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EISTR_PPE                               = 0x109010080ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EISTR_PPE                               = 0x109020080ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EISTR_PPE                               = 0x10A010080ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EISTR_PPE                               = 0x10A020080ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EISTR_PPE                               = 0x10B010080ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EISTR_PPE                               = 0x10B020080ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EISTR_PPE                               = 0x10C010080ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EISTR_PPE                               = 0x10C020080ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EISTR_PPE                               = 0x10D010080ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EISTR_PPE                               = 0x10D020080ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EISTR_PPE                              = 0x10E010080ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EISTR_PPE                              = 0x10E020080ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_EITR_PPE                                = 0x109010060ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EITR_PPE1                               = 0x109010078ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_EITR_PPE2                               = 0x109010070ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EITR_PPE                                = 0x109020060ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EITR_PPE1                               = 0x109020078ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_EITR_PPE2                               = 0x109020070ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EITR_PPE                                = 0x10A010060ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EITR_PPE1                               = 0x10A010078ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_EITR_PPE2                               = 0x10A010070ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EITR_PPE                                = 0x10A020060ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EITR_PPE1                               = 0x10A020078ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_EITR_PPE2                               = 0x10A020070ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EITR_PPE                                = 0x10B010060ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EITR_PPE1                               = 0x10B010078ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_EITR_PPE2                               = 0x10B010070ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EITR_PPE                                = 0x10B020060ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EITR_PPE1                               = 0x10B020078ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_EITR_PPE2                               = 0x10B020070ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EITR_PPE                                = 0x10C010060ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EITR_PPE1                               = 0x10C010078ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_EITR_PPE2                               = 0x10C010070ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EITR_PPE                                = 0x10C020060ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EITR_PPE1                               = 0x10C020078ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_EITR_PPE2                               = 0x10C020070ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EITR_PPE                                = 0x10D010060ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EITR_PPE1                               = 0x10D010078ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_EITR_PPE2                               = 0x10D010070ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EITR_PPE                                = 0x10D020060ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EITR_PPE1                               = 0x10D020078ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_EITR_PPE2                               = 0x10D020070ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EITR_PPE                               = 0x10E010060ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EITR_PPE1                              = 0x10E010078ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_EITR_PPE2                              = 0x10E010070ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EITR_PPE                               = 0x10E020060ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EITR_PPE1                              = 0x10E020078ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_EITR_PPE2                              = 0x10E020070ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_ICCR_PPE                                = 0x109010700ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_ICCR_PPE1                               = 0x109010718ull;

static const uint64_t P9N2_PU_CME0_CME_LCL_ICCR_PPE2                               = 0x109010710ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_ICCR_PPE                                = 0x109020700ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_ICCR_PPE1                               = 0x109020718ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_ICCR_PPE2                               = 0x109020710ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_ICCR_PPE                                = 0x10A010700ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_ICCR_PPE1                               = 0x10A010718ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_ICCR_PPE2                               = 0x10A010710ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_ICCR_PPE                                = 0x10A020700ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_ICCR_PPE1                               = 0x10A020718ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_ICCR_PPE2                               = 0x10A020710ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_ICCR_PPE                                = 0x10B010700ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_ICCR_PPE1                               = 0x10B010718ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_ICCR_PPE2                               = 0x10B010710ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_ICCR_PPE                                = 0x10B020700ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_ICCR_PPE1                               = 0x10B020718ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_ICCR_PPE2                               = 0x10B020710ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_ICCR_PPE                                = 0x10C010700ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_ICCR_PPE1                               = 0x10C010718ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_ICCR_PPE2                               = 0x10C010710ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_ICCR_PPE                                = 0x10C020700ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_ICCR_PPE1                               = 0x10C020718ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_ICCR_PPE2                               = 0x10C020710ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_ICCR_PPE                                = 0x10D010700ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_ICCR_PPE1                               = 0x10D010718ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_ICCR_PPE2                               = 0x10D010710ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_ICCR_PPE                                = 0x10D020700ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_ICCR_PPE1                               = 0x10D020718ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_ICCR_PPE2                               = 0x10D020710ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_ICCR_PPE                               = 0x10E010700ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_ICCR_PPE1                              = 0x10E010718ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_ICCR_PPE2                              = 0x10E010710ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_ICCR_PPE                               = 0x10E020700ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_ICCR_PPE1                              = 0x10E020718ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_ICCR_PPE2                              = 0x10E020710ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_ICRR_PPE                                = 0x109010740ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_ICRR_PPE                                = 0x109020740ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_ICRR_PPE                                = 0x10A010740ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_ICRR_PPE                                = 0x10A020740ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_ICRR_PPE                                = 0x10B010740ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_ICRR_PPE                                = 0x10B020740ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_ICRR_PPE                                = 0x10C010740ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_ICRR_PPE                                = 0x10C020740ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_ICRR_PPE                                = 0x10D010740ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_ICRR_PPE                                = 0x10D020740ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_ICRR_PPE                               = 0x10E010740ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_ICRR_PPE                               = 0x10E020740ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_ICSR_PPE                                = 0x109010720ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_ICSR_PPE                                = 0x109020720ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_ICSR_PPE                                = 0x10A010720ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_ICSR_PPE                                = 0x10A020720ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_ICSR_PPE                                = 0x10B010720ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_ICSR_PPE                                = 0x10B020720ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_ICSR_PPE                                = 0x10C010720ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_ICSR_PPE                                = 0x10C020720ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_ICSR_PPE                                = 0x10D010720ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_ICSR_PPE                                = 0x10D020720ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_ICSR_PPE                               = 0x10E010720ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_ICSR_PPE                               = 0x10E020720ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_PECESR0_PPE                             = 0x109010280ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_PECESR0_PPE                             = 0x109020280ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_PECESR0_PPE                             = 0x10A010280ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_PECESR0_PPE                             = 0x10A020280ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_PECESR0_PPE                             = 0x10B010280ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_PECESR0_PPE                             = 0x10B020280ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_PECESR0_PPE                             = 0x10C010280ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_PECESR0_PPE                             = 0x10C020280ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_PECESR0_PPE                             = 0x10D010280ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_PECESR0_PPE                             = 0x10D020280ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_PECESR0_PPE                            = 0x10E010280ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_PECESR0_PPE                            = 0x10E020280ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_PECESR1_PPE                             = 0x1090102A0ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_PECESR1_PPE                             = 0x1090202A0ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_PECESR1_PPE                             = 0x10A0102A0ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_PECESR1_PPE                             = 0x10A0202A0ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_PECESR1_PPE                             = 0x10B0102A0ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_PECESR1_PPE                             = 0x10B0202A0ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_PECESR1_PPE                             = 0x10C0102A0ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_PECESR1_PPE                             = 0x10C0202A0ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_PECESR1_PPE                             = 0x10D0102A0ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_PECESR1_PPE                             = 0x10D0202A0ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_PECESR1_PPE                            = 0x10E0102A0ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_PECESR1_PPE                            = 0x10E0202A0ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_SISR_PPE                                = 0x109010520ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_SISR_PPE                                = 0x109020520ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_SISR_PPE                                = 0x10A010520ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_SISR_PPE                                = 0x10A020520ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_SISR_PPE                                = 0x10B010520ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_SISR_PPE                                = 0x10B020520ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_SISR_PPE                                = 0x10C010520ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_SISR_PPE                                = 0x10C020520ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_SISR_PPE                                = 0x10D010520ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_SISR_PPE                                = 0x10D020520ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_SISR_PPE                               = 0x10E010520ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_SISR_PPE                               = 0x10E020520ull;


static const uint64_t P9N2_PU_CME0_CME_LCL_TSEL_PPE                                = 0x109010100ull;

static const uint64_t P9N2_PU_CME1_CME_LCL_TSEL_PPE                                = 0x109020100ull;

static const uint64_t P9N2_PU_CME2_CME_LCL_TSEL_PPE                                = 0x10A010100ull;

static const uint64_t P9N2_PU_CME3_CME_LCL_TSEL_PPE                                = 0x10A020100ull;

static const uint64_t P9N2_PU_CME4_CME_LCL_TSEL_PPE                                = 0x10B010100ull;

static const uint64_t P9N2_PU_CME5_CME_LCL_TSEL_PPE                                = 0x10B020100ull;

static const uint64_t P9N2_PU_CME6_CME_LCL_TSEL_PPE                                = 0x10C010100ull;

static const uint64_t P9N2_PU_CME7_CME_LCL_TSEL_PPE                                = 0x10C020100ull;

static const uint64_t P9N2_PU_CME8_CME_LCL_TSEL_PPE                                = 0x10D010100ull;

static const uint64_t P9N2_PU_CME9_CME_LCL_TSEL_PPE                                = 0x10D020100ull;

static const uint64_t P9N2_PU_CME10_CME_LCL_TSEL_PPE                               = 0x10E010100ull;

static const uint64_t P9N2_PU_CME11_CME_LCL_TSEL_PPE                               = 0x10E020100ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_AFSR_PPE                               = 0x109010160ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_AFSR_PPE                               = 0x109020160ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_AFSR_PPE                               = 0x10A010160ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_AFSR_PPE                               = 0x10A020160ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_AFSR_PPE                               = 0x10B010160ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_AFSR_PPE                               = 0x10B020160ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_AFSR_PPE                               = 0x10C010160ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_AFSR_PPE                               = 0x10C020160ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_AFSR_PPE                               = 0x10D010160ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_AFSR_PPE                               = 0x10D020160ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_AFSR_PPE                              = 0x10E010160ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_AFSR_PPE                              = 0x10E020160ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_AFTR_PPE                               = 0x109010180ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_AFTR_PPE                               = 0x109020180ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_AFTR_PPE                               = 0x10A010180ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_AFTR_PPE                               = 0x10A020180ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_AFTR_PPE                               = 0x10B010180ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_AFTR_PPE                               = 0x10B020180ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_AFTR_PPE                               = 0x10C010180ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_AFTR_PPE                               = 0x10C020180ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_AFTR_PPE                               = 0x10D010180ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_AFTR_PPE                               = 0x10D020180ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_AFTR_PPE                              = 0x10E010180ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_AFTR_PPE                              = 0x10E020180ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_BCECSR_PPE                             = 0x1090101E0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_BCECSR_PPE                             = 0x1090201E0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_BCECSR_PPE                             = 0x10A0101E0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_BCECSR_PPE                             = 0x10A0201E0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_BCECSR_PPE                             = 0x10B0101E0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_BCECSR_PPE                             = 0x10B0201E0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_BCECSR_PPE                             = 0x10C0101E0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_BCECSR_PPE                             = 0x10C0201E0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_BCECSR_PPE                             = 0x10D0101E0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_BCECSR_PPE                             = 0x10D0201E0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_BCECSR_PPE                            = 0x10E0101E0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_BCECSR_PPE                            = 0x10E0201E0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_CIDSR_PPE                              = 0x1090106C0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_CIDSR_PPE                              = 0x1090206C0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_CIDSR_PPE                              = 0x10A0106C0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_CIDSR_PPE                              = 0x10A0206C0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_CIDSR_PPE                              = 0x10B0106C0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_CIDSR_PPE                              = 0x10B0206C0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_CIDSR_PPE                              = 0x10C0106C0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_CIDSR_PPE                              = 0x10C0206C0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_CIDSR_PPE                              = 0x10D0106C0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_CIDSR_PPE                              = 0x10D0206C0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_CIDSR_PPE                             = 0x10E0106C0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_CIDSR_PPE                             = 0x10E0206C0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_FLAGS_PPE                              = 0x109010400ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_FLAGS_PPE1                             = 0x109010418ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_FLAGS_PPE2                             = 0x109010410ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_FLAGS_PPE                              = 0x109020400ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_FLAGS_PPE1                             = 0x109020418ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_FLAGS_PPE2                             = 0x109020410ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_FLAGS_PPE                              = 0x10A010400ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_FLAGS_PPE1                             = 0x10A010418ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_FLAGS_PPE2                             = 0x10A010410ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_FLAGS_PPE                              = 0x10A020400ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_FLAGS_PPE1                             = 0x10A020418ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_FLAGS_PPE2                             = 0x10A020410ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_FLAGS_PPE                              = 0x10B010400ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_FLAGS_PPE1                             = 0x10B010418ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_FLAGS_PPE2                             = 0x10B010410ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_FLAGS_PPE                              = 0x10B020400ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_FLAGS_PPE1                             = 0x10B020418ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_FLAGS_PPE2                             = 0x10B020410ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_FLAGS_PPE                              = 0x10C010400ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_FLAGS_PPE1                             = 0x10C010418ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_FLAGS_PPE2                             = 0x10C010410ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_FLAGS_PPE                              = 0x10C020400ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_FLAGS_PPE1                             = 0x10C020418ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_FLAGS_PPE2                             = 0x10C020410ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_FLAGS_PPE                              = 0x10D010400ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_FLAGS_PPE1                             = 0x10D010418ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_FLAGS_PPE2                             = 0x10D010410ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_FLAGS_PPE                              = 0x10D020400ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_FLAGS_PPE1                             = 0x10D020418ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_FLAGS_PPE2                             = 0x10D020410ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_FLAGS_PPE                             = 0x10E010400ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_FLAGS_PPE1                            = 0x10E010418ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_FLAGS_PPE2                            = 0x10E010410ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_FLAGS_PPE                             = 0x10E020400ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_FLAGS_PPE1                            = 0x10E020418ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_FLAGS_PPE2                            = 0x10E020410ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_IDCR_PPE                               = 0x1090106A0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_IDCR_PPE                               = 0x1090206A0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_IDCR_PPE                               = 0x10A0106A0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_IDCR_PPE                               = 0x10A0206A0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_IDCR_PPE                               = 0x10B0106A0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_IDCR_PPE                               = 0x10B0206A0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_IDCR_PPE                               = 0x10C0106A0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_IDCR_PPE                               = 0x10C0206A0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_IDCR_PPE                               = 0x10D0106A0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_IDCR_PPE                               = 0x10D0206A0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_IDCR_PPE                              = 0x10E0106A0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_IDCR_PPE                              = 0x10E0206A0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_LMCR_PPE                               = 0x1090101A0ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_LMCR_PPE1                              = 0x1090101B8ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_LMCR_PPE2                              = 0x1090101B0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_LMCR_PPE                               = 0x1090201A0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_LMCR_PPE1                              = 0x1090201B8ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_LMCR_PPE2                              = 0x1090201B0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_LMCR_PPE                               = 0x10A0101A0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_LMCR_PPE1                              = 0x10A0101B8ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_LMCR_PPE2                              = 0x10A0101B0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_LMCR_PPE                               = 0x10A0201A0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_LMCR_PPE1                              = 0x10A0201B8ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_LMCR_PPE2                              = 0x10A0201B0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_LMCR_PPE                               = 0x10B0101A0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_LMCR_PPE1                              = 0x10B0101B8ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_LMCR_PPE2                              = 0x10B0101B0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_LMCR_PPE                               = 0x10B0201A0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_LMCR_PPE1                              = 0x10B0201B8ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_LMCR_PPE2                              = 0x10B0201B0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_LMCR_PPE                               = 0x10C0101A0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_LMCR_PPE1                              = 0x10C0101B8ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_LMCR_PPE2                              = 0x10C0101B0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_LMCR_PPE                               = 0x10C0201A0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_LMCR_PPE1                              = 0x10C0201B8ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_LMCR_PPE2                              = 0x10C0201B0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_LMCR_PPE                               = 0x10D0101A0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_LMCR_PPE1                              = 0x10D0101B8ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_LMCR_PPE2                              = 0x10D0101B0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_LMCR_PPE                               = 0x10D0201A0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_LMCR_PPE1                              = 0x10D0201B8ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_LMCR_PPE2                              = 0x10D0201B0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_LMCR_PPE                              = 0x10E0101A0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_LMCR_PPE1                             = 0x10E0101B8ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_LMCR_PPE2                             = 0x10E0101B0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_LMCR_PPE                              = 0x10E0201A0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_LMCR_PPE1                             = 0x10E0201B8ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_LMCR_PPE2                             = 0x10E0201B0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PMCRS0_PPE                             = 0x109010240ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PMCRS0_PPE                             = 0x109020240ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PMCRS0_PPE                             = 0x10A010240ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PMCRS0_PPE                             = 0x10A020240ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PMCRS0_PPE                             = 0x10B010240ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PMCRS0_PPE                             = 0x10B020240ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PMCRS0_PPE                             = 0x10C010240ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PMCRS0_PPE                             = 0x10C020240ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PMCRS0_PPE                             = 0x10D010240ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PMCRS0_PPE                             = 0x10D020240ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PMCRS0_PPE                            = 0x10E010240ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PMCRS0_PPE                            = 0x10E020240ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PMCRS1_PPE                             = 0x109010260ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PMCRS1_PPE                             = 0x109020260ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PMCRS1_PPE                             = 0x10A010260ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PMCRS1_PPE                             = 0x10A020260ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PMCRS1_PPE                             = 0x10B010260ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PMCRS1_PPE                             = 0x10B020260ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PMCRS1_PPE                             = 0x10C010260ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PMCRS1_PPE                             = 0x10C020260ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PMCRS1_PPE                             = 0x10D010260ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PMCRS1_PPE                             = 0x10D020260ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PMCRS1_PPE                            = 0x10E010260ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PMCRS1_PPE                            = 0x10E020260ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PMSRS0_PPE                             = 0x109010200ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PMSRS0_PPE                             = 0x109020200ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PMSRS0_PPE                             = 0x10A010200ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PMSRS0_PPE                             = 0x10A020200ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PMSRS0_PPE                             = 0x10B010200ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PMSRS0_PPE                             = 0x10B020200ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PMSRS0_PPE                             = 0x10C010200ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PMSRS0_PPE                             = 0x10C020200ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PMSRS0_PPE                             = 0x10D010200ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PMSRS0_PPE                             = 0x10D020200ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PMSRS0_PPE                            = 0x10E010200ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PMSRS0_PPE                            = 0x10E020200ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PMSRS1_PPE                             = 0x109010220ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PMSRS1_PPE                             = 0x109020220ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PMSRS1_PPE                             = 0x10A010220ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PMSRS1_PPE                             = 0x10A020220ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PMSRS1_PPE                             = 0x10B010220ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PMSRS1_PPE                             = 0x10B020220ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PMSRS1_PPE                             = 0x10C010220ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PMSRS1_PPE                             = 0x10C020220ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PMSRS1_PPE                             = 0x10D010220ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PMSRS1_PPE                             = 0x10D020220ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PMSRS1_PPE                            = 0x10E010220ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PMSRS1_PPE                            = 0x10E020220ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS00_PPE                            = 0x109010300ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS00_PPE                            = 0x109020300ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS00_PPE                            = 0x10A010300ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS00_PPE                            = 0x10A020300ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS00_PPE                            = 0x10B010300ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS00_PPE                            = 0x10B020300ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS00_PPE                            = 0x10C010300ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS00_PPE                            = 0x10C020300ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS00_PPE                            = 0x10D010300ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS00_PPE                            = 0x10D020300ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS00_PPE                           = 0x10E010300ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS00_PPE                           = 0x10E020300ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS01_PPE                            = 0x109010320ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS01_PPE                            = 0x109020320ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS01_PPE                            = 0x10A010320ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS01_PPE                            = 0x10A020320ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS01_PPE                            = 0x10B010320ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS01_PPE                            = 0x10B020320ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS01_PPE                            = 0x10C010320ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS01_PPE                            = 0x10C020320ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS01_PPE                            = 0x10D010320ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS01_PPE                            = 0x10D020320ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS01_PPE                           = 0x10E010320ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS01_PPE                           = 0x10E020320ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS02_PPE                            = 0x109010340ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS02_PPE                            = 0x109020340ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS02_PPE                            = 0x10A010340ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS02_PPE                            = 0x10A020340ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS02_PPE                            = 0x10B010340ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS02_PPE                            = 0x10B020340ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS02_PPE                            = 0x10C010340ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS02_PPE                            = 0x10C020340ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS02_PPE                            = 0x10D010340ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS02_PPE                            = 0x10D020340ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS02_PPE                           = 0x10E010340ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS02_PPE                           = 0x10E020340ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS03_PPE                            = 0x109010360ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS03_PPE                            = 0x109020360ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS03_PPE                            = 0x10A010360ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS03_PPE                            = 0x10A020360ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS03_PPE                            = 0x10B010360ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS03_PPE                            = 0x10B020360ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS03_PPE                            = 0x10C010360ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS03_PPE                            = 0x10C020360ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS03_PPE                            = 0x10D010360ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS03_PPE                            = 0x10D020360ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS03_PPE                           = 0x10E010360ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS03_PPE                           = 0x10E020360ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS10_PPE                            = 0x109010380ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS10_PPE                            = 0x109020380ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS10_PPE                            = 0x10A010380ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS10_PPE                            = 0x10A020380ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS10_PPE                            = 0x10B010380ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS10_PPE                            = 0x10B020380ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS10_PPE                            = 0x10C010380ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS10_PPE                            = 0x10C020380ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS10_PPE                            = 0x10D010380ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS10_PPE                            = 0x10D020380ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS10_PPE                           = 0x10E010380ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS10_PPE                           = 0x10E020380ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS11_PPE                            = 0x1090103A0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS11_PPE                            = 0x1090203A0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS11_PPE                            = 0x10A0103A0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS11_PPE                            = 0x10A0203A0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS11_PPE                            = 0x10B0103A0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS11_PPE                            = 0x10B0203A0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS11_PPE                            = 0x10C0103A0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS11_PPE                            = 0x10C0203A0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS11_PPE                            = 0x10D0103A0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS11_PPE                            = 0x10D0203A0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS11_PPE                           = 0x10E0103A0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS11_PPE                           = 0x10E0203A0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS12_PPE                            = 0x1090103C0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS12_PPE                            = 0x1090203C0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS12_PPE                            = 0x10A0103C0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS12_PPE                            = 0x10A0203C0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS12_PPE                            = 0x10B0103C0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS12_PPE                            = 0x10B0203C0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS12_PPE                            = 0x10C0103C0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS12_PPE                            = 0x10C0203C0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS12_PPE                            = 0x10D0103C0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS12_PPE                            = 0x10D0203C0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS12_PPE                           = 0x10E0103C0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS12_PPE                           = 0x10E0203C0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_PSCRS13_PPE                            = 0x1090103E0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_PSCRS13_PPE                            = 0x1090203E0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_PSCRS13_PPE                            = 0x10A0103E0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_PSCRS13_PPE                            = 0x10A0203E0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_PSCRS13_PPE                            = 0x10B0103E0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_PSCRS13_PPE                            = 0x10B0203E0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_PSCRS13_PPE                            = 0x10C0103E0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_PSCRS13_PPE                            = 0x10C0203E0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_PSCRS13_PPE                            = 0x10D0103E0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_PSCRS13_PPE                            = 0x10D0203E0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_PSCRS13_PPE                           = 0x10E0103E0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_PSCRS13_PPE                           = 0x10E0203E0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_QFMR_PPE                               = 0x109010140ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_QFMR_PPE                               = 0x109020140ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_QFMR_PPE                               = 0x10A010140ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_QFMR_PPE                               = 0x10A020140ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_QFMR_PPE                               = 0x10B010140ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_QFMR_PPE                               = 0x10B020140ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_QFMR_PPE                               = 0x10C010140ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_QFMR_PPE                               = 0x10C020140ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_QFMR_PPE                               = 0x10D010140ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_QFMR_PPE                               = 0x10D020140ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_QFMR_PPE                              = 0x10E010140ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_QFMR_PPE                              = 0x10E020140ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_QIDSR_PPE                              = 0x1090106E0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_QIDSR_PPE                              = 0x1090206E0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_QIDSR_PPE                              = 0x10A0106E0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_QIDSR_PPE                              = 0x10A0206E0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_QIDSR_PPE                              = 0x10B0106E0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_QIDSR_PPE                              = 0x10B0206E0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_QIDSR_PPE                              = 0x10C0106E0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_QIDSR_PPE                              = 0x10C0206E0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_QIDSR_PPE                              = 0x10D0106E0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_QIDSR_PPE                              = 0x10D0206E0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_QIDSR_PPE                             = 0x10E0106E0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_QIDSR_PPE                             = 0x10E0206E0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_SICR_PPE                               = 0x109010500ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_SICR_PPE1                              = 0x109010518ull;

static const uint64_t P9N2_PU_CME0_CME_SCOM_SICR_PPE2                              = 0x109010510ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_SICR_PPE                               = 0x109020500ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_SICR_PPE1                              = 0x109020518ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_SICR_PPE2                              = 0x109020510ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_SICR_PPE                               = 0x10A010500ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_SICR_PPE1                              = 0x10A010518ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_SICR_PPE2                              = 0x10A010510ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_SICR_PPE                               = 0x10A020500ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_SICR_PPE1                              = 0x10A020518ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_SICR_PPE2                              = 0x10A020510ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_SICR_PPE                               = 0x10B010500ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_SICR_PPE1                              = 0x10B010518ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_SICR_PPE2                              = 0x10B010510ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_SICR_PPE                               = 0x10B020500ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_SICR_PPE1                              = 0x10B020518ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_SICR_PPE2                              = 0x10B020510ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_SICR_PPE                               = 0x10C010500ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_SICR_PPE1                              = 0x10C010518ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_SICR_PPE2                              = 0x10C010510ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_SICR_PPE                               = 0x10C020500ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_SICR_PPE1                              = 0x10C020518ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_SICR_PPE2                              = 0x10C020510ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_SICR_PPE                               = 0x10D010500ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_SICR_PPE1                              = 0x10D010518ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_SICR_PPE2                              = 0x10D010510ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_SICR_PPE                               = 0x10D020500ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_SICR_PPE1                              = 0x10D020518ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_SICR_PPE2                              = 0x10D020510ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_SICR_PPE                              = 0x10E010500ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_SICR_PPE1                             = 0x10E010518ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_SICR_PPE2                             = 0x10E010510ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_SICR_PPE                              = 0x10E020500ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_SICR_PPE1                             = 0x10E020518ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_SICR_PPE2                             = 0x10E020510ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_SRTCH0_PPE                             = 0x109010420ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_SRTCH0_PPE                             = 0x109020420ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_SRTCH0_PPE                             = 0x10A010420ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_SRTCH0_PPE                             = 0x10A020420ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_SRTCH0_PPE                             = 0x10B010420ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_SRTCH0_PPE                             = 0x10B020420ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_SRTCH0_PPE                             = 0x10C010420ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_SRTCH0_PPE                             = 0x10C020420ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_SRTCH0_PPE                             = 0x10D010420ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_SRTCH0_PPE                             = 0x10D020420ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_SRTCH0_PPE                            = 0x10E010420ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_SRTCH0_PPE                            = 0x10E020420ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_SRTCH1_PPE                             = 0x109010440ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_SRTCH1_PPE                             = 0x109020440ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_SRTCH1_PPE                             = 0x10A010440ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_SRTCH1_PPE                             = 0x10A020440ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_SRTCH1_PPE                             = 0x10B010440ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_SRTCH1_PPE                             = 0x10B020440ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_SRTCH1_PPE                             = 0x10C010440ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_SRTCH1_PPE                             = 0x10C020440ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_SRTCH1_PPE                             = 0x10D010440ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_SRTCH1_PPE                             = 0x10D020440ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_SRTCH1_PPE                            = 0x10E010440ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_SRTCH1_PPE                            = 0x10E020440ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_VCCR_PPE                               = 0x109010680ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_VCCR_PPE                               = 0x109020680ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_VCCR_PPE                               = 0x10A010680ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_VCCR_PPE                               = 0x10A020680ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_VCCR_PPE                               = 0x10B010680ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_VCCR_PPE                               = 0x10B020680ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_VCCR_PPE                               = 0x10C010680ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_VCCR_PPE                               = 0x10C020680ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_VCCR_PPE                               = 0x10D010680ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_VCCR_PPE                               = 0x10D020680ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_VCCR_PPE                              = 0x10E010680ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_VCCR_PPE                              = 0x10E020680ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_VDCR_PPE                               = 0x109010600ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_VDCR_PPE                               = 0x109020600ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_VDCR_PPE                               = 0x10A010600ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_VDCR_PPE                               = 0x10A020600ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_VDCR_PPE                               = 0x10B010600ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_VDCR_PPE                               = 0x10B020600ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_VDCR_PPE                               = 0x10C010600ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_VDCR_PPE                               = 0x10C020600ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_VDCR_PPE                               = 0x10D010600ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_VDCR_PPE                               = 0x10D020600ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_VDCR_PPE                              = 0x10E010600ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_VDCR_PPE                              = 0x10E020600ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_VDSR_PPE                               = 0x109010640ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_VDSR_PPE                               = 0x109020640ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_VDSR_PPE                               = 0x10A010640ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_VDSR_PPE                               = 0x10A020640ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_VDSR_PPE                               = 0x10B010640ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_VDSR_PPE                               = 0x10B020640ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_VDSR_PPE                               = 0x10C010640ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_VDSR_PPE                               = 0x10C020640ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_VDSR_PPE                               = 0x10D010640ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_VDSR_PPE                               = 0x10D020640ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_VDSR_PPE                              = 0x10E010640ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_VDSR_PPE                              = 0x10E020640ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_VECR_PPE                               = 0x109010660ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_VECR_PPE                               = 0x109020660ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_VECR_PPE                               = 0x10A010660ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_VECR_PPE                               = 0x10A020660ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_VECR_PPE                               = 0x10B010660ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_VECR_PPE                               = 0x10B020660ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_VECR_PPE                               = 0x10C010660ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_VECR_PPE                               = 0x10C020660ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_VECR_PPE                               = 0x10D010660ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_VECR_PPE                               = 0x10D020660ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_VECR_PPE                              = 0x10E010660ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_VECR_PPE                              = 0x10E020660ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_VNCR_PPE                               = 0x109010620ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_VNCR_PPE                               = 0x109020620ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_VNCR_PPE                               = 0x10A010620ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_VNCR_PPE                               = 0x10A020620ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_VNCR_PPE                               = 0x10B010620ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_VNCR_PPE                               = 0x10B020620ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_VNCR_PPE                               = 0x10C010620ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_VNCR_PPE                               = 0x10C020620ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_VNCR_PPE                               = 0x10D010620ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_VNCR_PPE                               = 0x10D020620ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_VNCR_PPE                              = 0x10E010620ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_VNCR_PPE                              = 0x10E020620ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_XIPCBMD0_PPE                           = 0x109010580ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_XIPCBMD0_PPE                           = 0x109020580ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_XIPCBMD0_PPE                           = 0x10A010580ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_XIPCBMD0_PPE                           = 0x10A020580ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_XIPCBMD0_PPE                           = 0x10B010580ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_XIPCBMD0_PPE                           = 0x10B020580ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_XIPCBMD0_PPE                           = 0x10C010580ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_XIPCBMD0_PPE                           = 0x10C020580ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_XIPCBMD0_PPE                           = 0x10D010580ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_XIPCBMD0_PPE                           = 0x10D020580ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_XIPCBMD0_PPE                          = 0x10E010580ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_XIPCBMD0_PPE                          = 0x10E020580ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_XIPCBMD1_PPE                           = 0x1090105A0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_XIPCBMD1_PPE                           = 0x1090205A0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_XIPCBMD1_PPE                           = 0x10A0105A0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_XIPCBMD1_PPE                           = 0x10A0205A0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_XIPCBMD1_PPE                           = 0x10B0105A0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_XIPCBMD1_PPE                           = 0x10B0205A0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_XIPCBMD1_PPE                           = 0x10C0105A0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_XIPCBMD1_PPE                           = 0x10C0205A0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_XIPCBMD1_PPE                           = 0x10D0105A0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_XIPCBMD1_PPE                           = 0x10D0205A0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_XIPCBMD1_PPE                          = 0x10E0105A0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_XIPCBMD1_PPE                          = 0x10E0205A0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_XIPCBMI0_PPE                           = 0x1090105C0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_XIPCBMI0_PPE                           = 0x1090205C0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_XIPCBMI0_PPE                           = 0x10A0105C0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_XIPCBMI0_PPE                           = 0x10A0205C0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_XIPCBMI0_PPE                           = 0x10B0105C0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_XIPCBMI0_PPE                           = 0x10B0205C0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_XIPCBMI0_PPE                           = 0x10C0105C0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_XIPCBMI0_PPE                           = 0x10C0205C0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_XIPCBMI0_PPE                           = 0x10D0105C0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_XIPCBMI0_PPE                           = 0x10D0205C0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_XIPCBMI0_PPE                          = 0x10E0105C0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_XIPCBMI0_PPE                          = 0x10E0205C0ull;


static const uint64_t P9N2_PU_CME0_CME_SCOM_XIPCBMI1_PPE                           = 0x1090105E0ull;

static const uint64_t P9N2_PU_CME1_CME_SCOM_XIPCBMI1_PPE                           = 0x1090205E0ull;

static const uint64_t P9N2_PU_CME2_CME_SCOM_XIPCBMI1_PPE                           = 0x10A0105E0ull;

static const uint64_t P9N2_PU_CME3_CME_SCOM_XIPCBMI1_PPE                           = 0x10A0205E0ull;

static const uint64_t P9N2_PU_CME4_CME_SCOM_XIPCBMI1_PPE                           = 0x10B0105E0ull;

static const uint64_t P9N2_PU_CME5_CME_SCOM_XIPCBMI1_PPE                           = 0x10B0205E0ull;

static const uint64_t P9N2_PU_CME6_CME_SCOM_XIPCBMI1_PPE                           = 0x10C0105E0ull;

static const uint64_t P9N2_PU_CME7_CME_SCOM_XIPCBMI1_PPE                           = 0x10C0205E0ull;

static const uint64_t P9N2_PU_CME8_CME_SCOM_XIPCBMI1_PPE                           = 0x10D0105E0ull;

static const uint64_t P9N2_PU_CME9_CME_SCOM_XIPCBMI1_PPE                           = 0x10D0205E0ull;

static const uint64_t P9N2_PU_CME10_CME_SCOM_XIPCBMI1_PPE                          = 0x10E0105E0ull;

static const uint64_t P9N2_PU_CME11_CME_SCOM_XIPCBMI1_PPE                          = 0x10E0205E0ull;


static const uint64_t P9N2_PU_COMMAND_REGISTER                                     = 0x00010000ull;


static const uint64_t P9N2_PU_COMMAND_REGISTER_B                                   = 0x000A0005ull;


static const uint64_t P9N2_PU_COMMAND_REGISTER_C                                   = 0x000A1005ull;


static const uint64_t P9N2_PU_COMMAND_REGISTER_D                                   = 0x000A2005ull;


static const uint64_t P9N2_PU_COMMAND_REGISTER_E                                   = 0x000A3005ull;


static const uint64_t P9N2_NV_CONFIG0                                              = 0x050110C0ull;

static const uint64_t P9N2_NV_0_CONFIG0                                            = 0x050110C0ull;

static const uint64_t P9N2_NV_4_CONFIG0                                            = 0x050114C0ull;

static const uint64_t P9N2_PU_NPU0_CTL_CONFIG0                                     = 0x05011090ull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG0                                     = 0x05011290ull;

static const uint64_t P9N2_PU_NPU0_SM0_CONFIG0                                     = 0x05011000ull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG0                                     = 0x05011030ull;

static const uint64_t P9N2_PU_NPU0_SM3_CONFIG0                                     = 0x05011060ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CONFIG0                                    = 0x050112C0ull;

static const uint64_t P9N2_PU_NPU2_SM0_CONFIG0                                     = 0x05011200ull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG0                                     = 0x05011230ull;

static const uint64_t P9N2_PU_NPU2_SM3_CONFIG0                                     = 0x05011260ull;

static const uint64_t P9N2_PU_NPU_CTL_CONFIG0                                      = 0x05011380ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG0                                  = 0x05011490ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CONFIG0                                  = 0x05011400ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG0                                  = 0x05011430ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CONFIG0                                  = 0x05011460ull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG0                                      = 0x05011350ull;

static const uint64_t P9N2__CTL_CONFIG0                                            = 0x05011580ull;

static const uint64_t P9N2__SM2_CONFIG0                                            = 0x05011550ull;


static const uint64_t P9N2_NV_CONFIG1                                              = 0x050110C1ull;

static const uint64_t P9N2_NV_0_CONFIG1                                            = 0x050110C1ull;

static const uint64_t P9N2_NV_1_CONFIG1                                            = 0x050110F1ull;

static const uint64_t P9N2_NV_4_CONFIG1                                            = 0x050114C1ull;

static const uint64_t P9N2_NV_5_CONFIG1                                            = 0x050114F1ull;

static const uint64_t P9N2_PU_NPU0_CTL_CONFIG1                                     = 0x05011091ull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG1                                     = 0x05011291ull;

static const uint64_t P9N2_PU_NPU0_SM0_CONFIG1                                     = 0x05011001ull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG1                                     = 0x05011031ull;

static const uint64_t P9N2_PU_NPU0_SM3_CONFIG1                                     = 0x05011061ull;

static const uint64_t P9N2_PU_NPU1_SM1_CONFIG1                                     = 0x05011128ull;

static const uint64_t P9N2_PU_NPU1_SM2_CONFIG1                                     = 0x05011148ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CONFIG1                                    = 0x050112C1ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CONFIG1                                    = 0x050112F1ull;

static const uint64_t P9N2_PU_NPU2_SM0_CONFIG1                                     = 0x05011201ull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG1                                     = 0x05011231ull;

static const uint64_t P9N2_PU_NPU2_SM3_CONFIG1                                     = 0x05011261ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG1                                  = 0x05011491ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CONFIG1                                  = 0x05011401ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG1                                  = 0x05011431ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CONFIG1                                  = 0x05011461ull;

static const uint64_t P9N2_PU_NPU_SM1_CONFIG1                                      = 0x05011328ull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG1                                      = 0x05011348ull;

static const uint64_t P9N2__SM1_CONFIG1                                            = 0x05011528ull;

static const uint64_t P9N2__SM2_CONFIG1                                            = 0x05011548ull;


static const uint64_t P9N2_NV_CONFIG2                                              = 0x050110C2ull;

static const uint64_t P9N2_NV_0_CONFIG2                                            = 0x050110C2ull;

static const uint64_t P9N2_NV_4_CONFIG2                                            = 0x050114C2ull;

static const uint64_t P9N2_PU_NPU0_CTL_CONFIG2                                     = 0x05011089ull;

static const uint64_t P9N2_PU_NPU0_DAT_CONFIG2                                     = 0x050110B9ull;

static const uint64_t P9N2_PU_NPU2_DAT_CONFIG2                                     = 0x050112B9ull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG2                                     = 0x05011289ull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG2                                     = 0x05011029ull;

static const uint64_t P9N2_PU_NPU0_SM2_CONFIG2                                     = 0x05011059ull;

static const uint64_t P9N2_PU_NPU1_SM0_CONFIG2                                     = 0x05011110ull;

static const uint64_t P9N2_PU_NPU1_SM1_CONFIG2                                     = 0x05011130ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CONFIG2                                    = 0x050112C2ull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG2                                     = 0x05011229ull;

static const uint64_t P9N2_PU_NPU2_SM2_CONFIG2                                     = 0x05011259ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG2                                  = 0x05011489ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_CONFIG2                                  = 0x050114B9ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG2                                  = 0x05011429ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_CONFIG2                                  = 0x05011459ull;

static const uint64_t P9N2_PU_NPU_SM0_CONFIG2                                      = 0x05011310ull;

static const uint64_t P9N2_PU_NPU_SM1_CONFIG2                                      = 0x05011330ull;

static const uint64_t P9N2__SM0_CONFIG2                                            = 0x05011510ull;

static const uint64_t P9N2__SM1_CONFIG2                                            = 0x05011530ull;


static const uint64_t P9N2_NV_CONFIG3                                              = 0x050110C3ull;

static const uint64_t P9N2_NV_0_CONFIG3                                            = 0x050110C3ull;

static const uint64_t P9N2_NV_4_CONFIG3                                            = 0x050114C3ull;

static const uint64_t P9N2_PU_NPU1_SM0_CONFIG3                                     = 0x05011111ull;

static const uint64_t P9N2_PU_NPU1_SM1_CONFIG3                                     = 0x05011131ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CONFIG3                                    = 0x050112C3ull;

static const uint64_t P9N2_PU_NPU_SM0_CONFIG3                                      = 0x05011311ull;

static const uint64_t P9N2_PU_NPU_SM1_CONFIG3                                      = 0x05011331ull;

static const uint64_t P9N2__SM0_CONFIG3                                            = 0x05011511ull;

static const uint64_t P9N2__SM1_CONFIG3                                            = 0x05011531ull;


static const uint64_t P9N2_NV_1_CONFIG_ADDR0                                       = 0x050110E4ull;

static const uint64_t P9N2_NV_5_CONFIG_ADDR0                                       = 0x050114E4ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CONFIG_ADDR0                               = 0x050112E4ull;


static const uint64_t P9N2_NV_1_CONFIG_ADDR1                                       = 0x050110E5ull;

static const uint64_t P9N2_NV_5_CONFIG_ADDR1                                       = 0x050114E5ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CONFIG_ADDR1                               = 0x050112E5ull;


static const uint64_t P9N2_NV_1_CONFIG_DATA0                                       = 0x050110E6ull;

static const uint64_t P9N2_NV_5_CONFIG_DATA0                                       = 0x050114E6ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CONFIG_DATA0                               = 0x050112E6ull;


static const uint64_t P9N2_NV_1_CONFIG_DATA1                                       = 0x050110E7ull;

static const uint64_t P9N2_NV_5_CONFIG_DATA1                                       = 0x050114E7ull;

static const uint64_t P9N2_PU_NPU2_NTL1_CONFIG_DATA1                               = 0x050112E7ull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_DEBUG0                                = 0x05011388ull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG_DEBUG0                                = 0x05011358ull;

static const uint64_t P9N2__CTL_CONFIG_DEBUG0                                      = 0x05011588ull;

static const uint64_t P9N2__SM2_CONFIG_DEBUG0                                      = 0x05011558ull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_DEBUG1                                = 0x05011389ull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG_DEBUG1                                = 0x05011359ull;

static const uint64_t P9N2__CTL_CONFIG_DEBUG1                                      = 0x05011589ull;

static const uint64_t P9N2__SM2_CONFIG_DEBUG1                                      = 0x05011559ull;


static const uint64_t P9N2_PU_NPU0_CTL_CONFIG_RELAXED0                             = 0x0501109Aull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG_RELAXED0                             = 0x0501129Aull;

static const uint64_t P9N2_PU_NPU0_SM0_CONFIG_RELAXED0                             = 0x0501100Aull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG_RELAXED0                             = 0x0501103Aull;

static const uint64_t P9N2_PU_NPU0_SM3_CONFIG_RELAXED0                             = 0x0501106Aull;

static const uint64_t P9N2_PU_NPU2_SM0_CONFIG_RELAXED0                             = 0x0501120Aull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG_RELAXED0                             = 0x0501123Aull;

static const uint64_t P9N2_PU_NPU2_SM3_CONFIG_RELAXED0                             = 0x0501126Aull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG_RELAXED0                          = 0x0501149Aull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CONFIG_RELAXED0                          = 0x0501140Aull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG_RELAXED0                          = 0x0501143Aull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CONFIG_RELAXED0                          = 0x0501146Aull;


static const uint64_t P9N2_PU_NPU0_CTL_CONFIG_RELAXED1                             = 0x0501109Bull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG_RELAXED1                             = 0x0501129Bull;

static const uint64_t P9N2_PU_NPU0_SM0_CONFIG_RELAXED1                             = 0x0501100Bull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG_RELAXED1                             = 0x0501103Bull;

static const uint64_t P9N2_PU_NPU0_SM3_CONFIG_RELAXED1                             = 0x0501106Bull;

static const uint64_t P9N2_PU_NPU2_SM0_CONFIG_RELAXED1                             = 0x0501120Bull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG_RELAXED1                             = 0x0501123Bull;

static const uint64_t P9N2_PU_NPU2_SM3_CONFIG_RELAXED1                             = 0x0501126Bull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG_RELAXED1                          = 0x0501149Bull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CONFIG_RELAXED1                          = 0x0501140Bull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG_RELAXED1                          = 0x0501143Bull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CONFIG_RELAXED1                          = 0x0501146Bull;


static const uint64_t P9N2_PU_NPU0_CTL_CONFIG_RELAXED2                             = 0x0501109Cull;

static const uint64_t P9N2_PU_NPU2_CTL_CONFIG_RELAXED2                             = 0x0501129Cull;

static const uint64_t P9N2_PU_NPU0_SM0_CONFIG_RELAXED2                             = 0x0501100Cull;

static const uint64_t P9N2_PU_NPU0_SM1_CONFIG_RELAXED2                             = 0x0501103Cull;

static const uint64_t P9N2_PU_NPU0_SM3_CONFIG_RELAXED2                             = 0x0501106Cull;

static const uint64_t P9N2_PU_NPU2_SM0_CONFIG_RELAXED2                             = 0x0501120Cull;

static const uint64_t P9N2_PU_NPU2_SM1_CONFIG_RELAXED2                             = 0x0501123Cull;

static const uint64_t P9N2_PU_NPU2_SM3_CONFIG_RELAXED2                             = 0x0501126Cull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_CONFIG_RELAXED2                          = 0x0501149Cull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_CONFIG_RELAXED2                          = 0x0501140Cull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_CONFIG_RELAXED2                          = 0x0501143Cull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_CONFIG_RELAXED2                          = 0x0501146Cull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_TLX_CREDITS                           = 0x0501138Aull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG_TLX_CREDITS                           = 0x0501135Aull;

static const uint64_t P9N2__CTL_CONFIG_TLX_CREDITS                                 = 0x0501158Aull;

static const uint64_t P9N2__SM2_CONFIG_TLX_CREDITS                                 = 0x0501155Aull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_TX                                    = 0x0501138Bull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG_TX                                    = 0x0501135Bull;

static const uint64_t P9N2__CTL_CONFIG_TX                                          = 0x0501158Bull;

static const uint64_t P9N2__SM2_CONFIG_TX                                          = 0x0501155Bull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_TX2                                   = 0x05011398ull;

static const uint64_t P9N2_PU_NPU_SM3_CONFIG_TX2                                   = 0x05011368ull;

static const uint64_t P9N2__CTL_CONFIG_TX2                                         = 0x05011598ull;

static const uint64_t P9N2__SM3_CONFIG_TX2                                         = 0x05011568ull;


static const uint64_t P9N2_PU_NPU_CTL_CONFIG_TX_DLC                                = 0x0501138Cull;

static const uint64_t P9N2_PU_NPU_SM2_CONFIG_TX_DLC                                = 0x0501135Cull;

static const uint64_t P9N2__CTL_CONFIG_TX_DLC                                      = 0x0501158Cull;

static const uint64_t P9N2__SM2_CONFIG_TX_DLC                                      = 0x0501155Cull;


static const uint64_t P9N2_PEC_CONTROL_REG                                         = 0x0D050012ull;

static const uint64_t P9N2_PEC_0_CONTROL_REG                                       = 0x0D050012ull;

static const uint64_t P9N2_PEC_1_CONTROL_REG                                       = 0x0E050012ull;

static const uint64_t P9N2_PEC_2_CONTROL_REG                                       = 0x0F050012ull;


static const uint64_t P9N2_PU_CONTROL_REGISTER_B                                   = 0x000A0000ull;


static const uint64_t P9N2_PU_CONTROL_REGISTER_C                                   = 0x000A1000ull;


static const uint64_t P9N2_PU_CONTROL_REGISTER_D                                   = 0x000A2000ull;


static const uint64_t P9N2_PU_CONTROL_REGISTER_E                                   = 0x000A3000ull;


static const uint64_t P9N2_PEC_CPLT_CONF0                                          = 0x0D000008ull;

static const uint64_t P9N2_PEC_CPLT_CONF0_OR                                       = 0x0D000018ull;

static const uint64_t P9N2_PEC_CPLT_CONF0_CLEAR                                    = 0x0D000028ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF0                                        = 0x0D000008ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF0_OR                                     = 0x0D000018ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF0_CLEAR                                  = 0x0D000028ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF0                                        = 0x0E000008ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF0_OR                                     = 0x0E000018ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF0_CLEAR                                  = 0x0E000028ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF0                                        = 0x0F000008ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF0_OR                                     = 0x0F000018ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF0_CLEAR                                  = 0x0F000028ull;


static const uint64_t P9N2_PEC_CPLT_CONF1                                          = 0x0D000009ull;

static const uint64_t P9N2_PEC_CPLT_CONF1_OR                                       = 0x0D000019ull;

static const uint64_t P9N2_PEC_CPLT_CONF1_CLEAR                                    = 0x0D000029ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF1                                        = 0x0D000009ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF1_OR                                     = 0x0D000019ull;

static const uint64_t P9N2_PEC_0_CPLT_CONF1_CLEAR                                  = 0x0D000029ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF1                                        = 0x0E000009ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF1_OR                                     = 0x0E000019ull;

static const uint64_t P9N2_PEC_1_CPLT_CONF1_CLEAR                                  = 0x0E000029ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF1                                        = 0x0F000009ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF1_OR                                     = 0x0F000019ull;

static const uint64_t P9N2_PEC_2_CPLT_CONF1_CLEAR                                  = 0x0F000029ull;


static const uint64_t P9N2_PEC_CPLT_CTRL0                                          = 0x0D000000ull;

static const uint64_t P9N2_PEC_CPLT_CTRL0_OR                                       = 0x0D000010ull;

static const uint64_t P9N2_PEC_CPLT_CTRL0_CLEAR                                    = 0x0D000020ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL0                                        = 0x0D000000ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL0_OR                                     = 0x0D000010ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL0_CLEAR                                  = 0x0D000020ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL0                                        = 0x0E000000ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL0_OR                                     = 0x0E000010ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL0_CLEAR                                  = 0x0E000020ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL0                                        = 0x0F000000ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL0_OR                                     = 0x0F000010ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL0_CLEAR                                  = 0x0F000020ull;


static const uint64_t P9N2_PEC_CPLT_CTRL1                                          = 0x0D000001ull;

static const uint64_t P9N2_PEC_CPLT_CTRL1_OR                                       = 0x0D000011ull;

static const uint64_t P9N2_PEC_CPLT_CTRL1_CLEAR                                    = 0x0D000021ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL1                                        = 0x0D000001ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL1_OR                                     = 0x0D000011ull;

static const uint64_t P9N2_PEC_0_CPLT_CTRL1_CLEAR                                  = 0x0D000021ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL1                                        = 0x0E000001ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL1_OR                                     = 0x0E000011ull;

static const uint64_t P9N2_PEC_1_CPLT_CTRL1_CLEAR                                  = 0x0E000021ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL1                                        = 0x0F000001ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL1_OR                                     = 0x0F000011ull;

static const uint64_t P9N2_PEC_2_CPLT_CTRL1_CLEAR                                  = 0x0F000021ull;


static const uint64_t P9N2_PEC_CPLT_MASK0                                          = 0x0D000101ull;

static const uint64_t P9N2_PEC_0_CPLT_MASK0                                        = 0x0D000101ull;

static const uint64_t P9N2_PEC_1_CPLT_MASK0                                        = 0x0E000101ull;

static const uint64_t P9N2_PEC_2_CPLT_MASK0                                        = 0x0F000101ull;


static const uint64_t P9N2_PEC_CPLT_STAT0                                          = 0x0D000100ull;

static const uint64_t P9N2_PEC_0_CPLT_STAT0                                        = 0x0D000100ull;

static const uint64_t P9N2_PEC_1_CPLT_STAT0                                        = 0x0E000100ull;

static const uint64_t P9N2_PEC_2_CPLT_STAT0                                        = 0x0F000100ull;


static const uint64_t P9N2_PEC_0_STACK0_CQSTAT_REG                                 = 0x04010C4Cull;

static const uint64_t P9N2_PEC_1_STACK0_CQSTAT_REG                                 = 0x0401104Cull;

static const uint64_t P9N2_PEC_1_STACK1_CQSTAT_REG                                 = 0x0401108Cull;

static const uint64_t P9N2_PEC_1_STACK2_CQSTAT_REG                                 = 0x040110CCull;

static const uint64_t P9N2_PEC_2_STACK0_CQSTAT_REG                                 = 0x0401144Cull;

static const uint64_t P9N2_PEC_2_STACK1_CQSTAT_REG                                 = 0x0401148Cull;

static const uint64_t P9N2_PEC_2_STACK2_CQSTAT_REG                                 = 0x040114CCull;

static const uint64_t P9N2_PEC_STACK0_CQSTAT_REG                                   = 0x04010C4Cull;

static const uint64_t P9N2_PHB_CQSTAT_REG                                          = 0x04010C4Cull;

static const uint64_t P9N2_PHB_0_CQSTAT_REG                                        = 0x04010C4Cull;

static const uint64_t P9N2_PHB_1_CQSTAT_REG                                        = 0x0401104Cull;

static const uint64_t P9N2_PHB_2_CQSTAT_REG                                        = 0x0401108Cull;

static const uint64_t P9N2_PHB_3_CQSTAT_REG                                        = 0x0401144Cull;

static const uint64_t P9N2_PHB_4_CQSTAT_REG                                        = 0x0401148Cull;

static const uint64_t P9N2_PHB_5_CQSTAT_REG                                        = 0x040114CCull;


static const uint64_t P9N2_PU_NPU1_SM1_CREQ_DA_PTR                                 = 0x05011124ull;

static const uint64_t P9N2_PU_NPU1_SM2_CREQ_DA_PTR                                 = 0x05011144ull;

static const uint64_t P9N2_PU_NPU_SM1_CREQ_DA_PTR                                  = 0x05011324ull;

static const uint64_t P9N2_PU_NPU_SM2_CREQ_DA_PTR                                  = 0x05011344ull;

static const uint64_t P9N2__SM1_CREQ_DA_PTR                                        = 0x05011524ull;

static const uint64_t P9N2__SM2_CREQ_DA_PTR                                        = 0x05011544ull;


static const uint64_t P9N2_PU_NPU1_SM1_CREQ_HA_PTR                                 = 0x05011120ull;

static const uint64_t P9N2_PU_NPU1_SM2_CREQ_HA_PTR                                 = 0x05011140ull;

static const uint64_t P9N2_PU_NPU_SM1_CREQ_HA_PTR                                  = 0x05011320ull;

static const uint64_t P9N2_PU_NPU_SM2_CREQ_HA_PTR                                  = 0x05011340ull;

static const uint64_t P9N2__SM1_CREQ_HA_PTR                                        = 0x05011520ull;

static const uint64_t P9N2__SM2_CREQ_HA_PTR                                        = 0x05011540ull;


static const uint64_t P9N2_PU_CSAR                                                 = 0x0C01104Dull;
//DUPS: 0901104D, 0C01104D,

static const uint64_t P9N2_PU_CSCR                                                 = 0x0C01104Aull;
//DUPS: 0901104A, 0C01104A,
static const uint64_t P9N2_PU_CSCR_CLEAR                                           = 0x0C01104Bull;
//DUPS: 0901104B, 0C01104B,
static const uint64_t P9N2_PU_CSCR_OR                                              = 0x0C01104Cull;
//DUPS: 0901104C, 0C01104C,

static const uint64_t P9N2_PU_CSDR                                                 = 0x0C01104Eull;
//DUPS: 0901104E, 0C01104E,

static const uint64_t P9N2_NV_CTL_STATUS                                           = 0x050110D2ull;

static const uint64_t P9N2_NV_0_CTL_STATUS                                         = 0x050110D2ull;

static const uint64_t P9N2_NV_4_CTL_STATUS                                         = 0x050114D2ull;

static const uint64_t P9N2_PU_NPU2_NTL0_CTL_STATUS                                 = 0x050112D2ull;


static const uint64_t P9N2_PEC_CTRL_ATOMIC_LOCK_REG                                = 0x0D0003FFull;

static const uint64_t P9N2_PEC_0_CTRL_ATOMIC_LOCK_REG                              = 0x0D0003FFull;

static const uint64_t P9N2_PEC_1_CTRL_ATOMIC_LOCK_REG                              = 0x0E0003FFull;

static const uint64_t P9N2_PEC_2_CTRL_ATOMIC_LOCK_REG                              = 0x0F0003FFull;


static const uint64_t P9N2_PEC_CTRL_PROTECT_MODE_REG                               = 0x0D0003FEull;

static const uint64_t P9N2_PEC_0_CTRL_PROTECT_MODE_REG                             = 0x0D0003FEull;

static const uint64_t P9N2_PEC_1_CTRL_PROTECT_MODE_REG                             = 0x0E0003FEull;

static const uint64_t P9N2_PEC_2_CTRL_PROTECT_MODE_REG                             = 0x0F0003FEull;


static const uint64_t P9N2_CAPP_CXA_SNP_ARRAY_ADDR_REG                             = 0x02010828ull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_ARRAY_ADDR_REG                           = 0x02010828ull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_ARRAY_ADDR_REG                           = 0x04010828ull;


static const uint64_t P9N2_CAPP_CXA_SNP_ARRAY_READ_REG                             = 0x02010829ull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_ARRAY_READ_REG                           = 0x02010829ull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_ARRAY_READ_REG                           = 0x04010829ull;


static const uint64_t P9N2_CAPP_CXA_SNP_ARRAY_WRITE_REG                            = 0x02010841ull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_ARRAY_WRITE_REG                          = 0x02010841ull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_ARRAY_WRITE_REG                          = 0x04010841ull;


static const uint64_t P9N2_CAPP_CXA_SNP_CAPI_CFG_REG                               = 0x0201081Aull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_CAPI_CFG_REG                             = 0x0201081Aull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_CAPI_CFG_REG                             = 0x0401081Aull;


static const uint64_t P9N2_CAPP_CXA_SNP_CNTL_REG                                   = 0x0201081Bull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_CNTL_REG                                 = 0x0201081Bull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_CNTL_REG                                 = 0x0401081Bull;


static const uint64_t P9N2_CAPP_CXA_SNP_ERROR_REPORT_REG                           = 0x0201080Aull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_ERROR_REPORT_REG                         = 0x0201080Aull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_ERROR_REPORT_REG                         = 0x0401080Aull;


static const uint64_t P9N2_CAPP_CXA_SNP_PHB_TTAG_FILTER_REG                        = 0x02010831ull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_PHB_TTAG_FILTER_REG                      = 0x02010831ull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_PHB_TTAG_FILTER_REG                      = 0x04010831ull;


static const uint64_t P9N2_CAPP_CXA_SNP_PMU_EVENTS_SELECT_REG                      = 0x02010817ull;

static const uint64_t P9N2_CAPP_0_CXA_SNP_PMU_EVENTS_SELECT_REG                    = 0x02010817ull;

static const uint64_t P9N2_CAPP_1_CXA_SNP_PMU_EVENTS_SELECT_REG                    = 0x04010817ull;


static const uint64_t P9N2_CAPP_CXA_TRIGCTL                                        = 0x02010812ull;

static const uint64_t P9N2_CAPP_0_CXA_TRIGCTL                                      = 0x02010812ull;

static const uint64_t P9N2_CAPP_1_CXA_TRIGCTL                                      = 0x04010812ull;


static const uint64_t P9N2_PU_NPU_CTL_C_ERR_RPT_HOLD0                              = 0x05011386ull;

static const uint64_t P9N2_PU_NPU_SM2_C_ERR_RPT_HOLD0                              = 0x05011356ull;

static const uint64_t P9N2__CTL_C_ERR_RPT_HOLD0                                    = 0x05011586ull;

static const uint64_t P9N2__SM2_C_ERR_RPT_HOLD0                                    = 0x05011556ull;


static const uint64_t P9N2_PU_NPU_CTL_C_ERR_RPT_HOLD1                              = 0x05011396ull;

static const uint64_t P9N2_PU_NPU_SM3_C_ERR_RPT_HOLD1                              = 0x05011366ull;

static const uint64_t P9N2__CTL_C_ERR_RPT_HOLD1                                    = 0x05011596ull;

static const uint64_t P9N2__SM3_C_ERR_RPT_HOLD1                                    = 0x05011566ull;


static const uint64_t P9N2_PU_NPU_CTL_C_ERR_RPT_MASK0                              = 0x05011387ull;

static const uint64_t P9N2_PU_NPU_SM2_C_ERR_RPT_MASK0                              = 0x05011357ull;

static const uint64_t P9N2__CTL_C_ERR_RPT_MASK0                                    = 0x05011587ull;

static const uint64_t P9N2__SM2_C_ERR_RPT_MASK0                                    = 0x05011557ull;


static const uint64_t P9N2_PU_NPU_CTL_C_ERR_RPT_MASK1                              = 0x05011397ull;

static const uint64_t P9N2_PU_NPU_SM3_C_ERR_RPT_MASK1                              = 0x05011367ull;

static const uint64_t P9N2__CTL_C_ERR_RPT_MASK1                                    = 0x05011597ull;

static const uint64_t P9N2__SM3_C_ERR_RPT_MASK1                                    = 0x05011567ull;


static const uint64_t P9N2_PU_DATA0TO7_REGISTER_B                                  = 0x000A0003ull;


static const uint64_t P9N2_PU_DATA0TO7_REGISTER_C                                  = 0x000A1003ull;


static const uint64_t P9N2_PU_DATA0TO7_REGISTER_D                                  = 0x000A2003ull;


static const uint64_t P9N2_PU_DATA0TO7_REGISTER_E                                  = 0x000A3003ull;


static const uint64_t P9N2_PU_DATA8TO15_REGISTER_B                                 = 0x000A0001ull;


static const uint64_t P9N2_PU_DATA8TO15_REGISTER_C                                 = 0x000A1001ull;


static const uint64_t P9N2_PU_DATA8TO15_REGISTER_D                                 = 0x000A2001ull;


static const uint64_t P9N2_PU_DATA8TO15_REGISTER_E                                 = 0x000A3001ull;


static const uint64_t P9N2_PU_DATATAG_0_HASH_FUNCTION_REG                          = 0x0201114Cull;


static const uint64_t P9N2_PU_DATATAG_1_HASH_FUNCTION_REG                          = 0x0201114Dull;


static const uint64_t P9N2_PU_DATATAG_2_HASH_FUNCTION_REG                          = 0x0201114Eull;


static const uint64_t P9N2_PU_DATATAG_3_HASH_FUNCTION_REG                          = 0x0201114Full;


static const uint64_t P9N2_PU_DATATAG_4_HASH_FUNCTION_REG                          = 0x02011150ull;


static const uint64_t P9N2_PU_DATATAG_5_HASH_FUNCTION_REG                          = 0x02011151ull;


static const uint64_t P9N2_PU_DATA_REGISTER                                        = 0x00010003ull;


static const uint64_t P9N2__CTL_DA_ADDR                                            = 0x0501168Eull;


static const uint64_t P9N2__CTL_DA_DATA                                            = 0x0501168Full;


static const uint64_t P9N2_PEC_DBG_CBS_CC                                          = 0x0D030013ull;

static const uint64_t P9N2_PEC_0_DBG_CBS_CC                                        = 0x0D030013ull;

static const uint64_t P9N2_PEC_1_DBG_CBS_CC                                        = 0x0E030013ull;

static const uint64_t P9N2_PEC_2_DBG_CBS_CC                                        = 0x0F030013ull;


static const uint64_t P9N2_PEC_DBG_INST1_COND_REG_1                                = 0x0D0107C1ull;

static const uint64_t P9N2_PEC_0_DBG_INST1_COND_REG_1                              = 0x0D0107C1ull;

static const uint64_t P9N2_PEC_1_DBG_INST1_COND_REG_1                              = 0x0E0107C1ull;

static const uint64_t P9N2_PEC_2_DBG_INST1_COND_REG_1                              = 0x0F0107C1ull;


static const uint64_t P9N2_PU_N0_DBG_INST1_COND_REG_1                              = 0x020107C1ull;

static const uint64_t P9N2_PU_N1_DBG_INST1_COND_REG_1                              = 0x030107C1ull;

static const uint64_t P9N2_PU_N2_DBG_INST1_COND_REG_1                              = 0x040107C1ull;

static const uint64_t P9N2_PU_N3_DBG_INST1_COND_REG_1                              = 0x050107C1ull;


static const uint64_t P9N2_PEC_DBG_INST1_COND_REG_2                                = 0x0D0107C2ull;

static const uint64_t P9N2_PEC_0_DBG_INST1_COND_REG_2                              = 0x0D0107C2ull;

static const uint64_t P9N2_PEC_1_DBG_INST1_COND_REG_2                              = 0x0E0107C2ull;

static const uint64_t P9N2_PEC_2_DBG_INST1_COND_REG_2                              = 0x0F0107C2ull;


static const uint64_t P9N2_PU_N0_DBG_INST1_COND_REG_2                              = 0x020107C2ull;

static const uint64_t P9N2_PU_N1_DBG_INST1_COND_REG_2                              = 0x030107C2ull;

static const uint64_t P9N2_PU_N2_DBG_INST1_COND_REG_2                              = 0x040107C2ull;

static const uint64_t P9N2_PU_N3_DBG_INST1_COND_REG_2                              = 0x050107C2ull;


static const uint64_t P9N2_PEC_DBG_INST1_COND_REG_3                                = 0x0D0107C3ull;

static const uint64_t P9N2_PEC_0_DBG_INST1_COND_REG_3                              = 0x0D0107C3ull;

static const uint64_t P9N2_PEC_1_DBG_INST1_COND_REG_3                              = 0x0E0107C3ull;

static const uint64_t P9N2_PEC_2_DBG_INST1_COND_REG_3                              = 0x0F0107C3ull;


static const uint64_t P9N2_PU_N0_DBG_INST1_COND_REG_3                              = 0x020107C3ull;

static const uint64_t P9N2_PU_N1_DBG_INST1_COND_REG_3                              = 0x030107C3ull;

static const uint64_t P9N2_PU_N2_DBG_INST1_COND_REG_3                              = 0x040107C3ull;

static const uint64_t P9N2_PU_N3_DBG_INST1_COND_REG_3                              = 0x050107C3ull;


static const uint64_t P9N2_PEC_DBG_INST2_COND_REG_1                                = 0x0D0107C4ull;

static const uint64_t P9N2_PEC_0_DBG_INST2_COND_REG_1                              = 0x0D0107C4ull;

static const uint64_t P9N2_PEC_1_DBG_INST2_COND_REG_1                              = 0x0E0107C4ull;

static const uint64_t P9N2_PEC_2_DBG_INST2_COND_REG_1                              = 0x0F0107C4ull;


static const uint64_t P9N2_PU_N0_DBG_INST2_COND_REG_1                              = 0x020107C4ull;

static const uint64_t P9N2_PU_N1_DBG_INST2_COND_REG_1                              = 0x030107C4ull;

static const uint64_t P9N2_PU_N2_DBG_INST2_COND_REG_1                              = 0x040107C4ull;

static const uint64_t P9N2_PU_N3_DBG_INST2_COND_REG_1                              = 0x050107C4ull;


static const uint64_t P9N2_PEC_DBG_INST2_COND_REG_2                                = 0x0D0107C5ull;

static const uint64_t P9N2_PEC_0_DBG_INST2_COND_REG_2                              = 0x0D0107C5ull;

static const uint64_t P9N2_PEC_1_DBG_INST2_COND_REG_2                              = 0x0E0107C5ull;

static const uint64_t P9N2_PEC_2_DBG_INST2_COND_REG_2                              = 0x0F0107C5ull;


static const uint64_t P9N2_PU_N0_DBG_INST2_COND_REG_2                              = 0x020107C5ull;

static const uint64_t P9N2_PU_N1_DBG_INST2_COND_REG_2                              = 0x030107C5ull;

static const uint64_t P9N2_PU_N2_DBG_INST2_COND_REG_2                              = 0x040107C5ull;

static const uint64_t P9N2_PU_N3_DBG_INST2_COND_REG_2                              = 0x050107C5ull;


static const uint64_t P9N2_PEC_DBG_INST2_COND_REG_3                                = 0x0D0107C6ull;

static const uint64_t P9N2_PEC_0_DBG_INST2_COND_REG_3                              = 0x0D0107C6ull;

static const uint64_t P9N2_PEC_1_DBG_INST2_COND_REG_3                              = 0x0E0107C6ull;

static const uint64_t P9N2_PEC_2_DBG_INST2_COND_REG_3                              = 0x0F0107C6ull;


static const uint64_t P9N2_PU_N0_DBG_INST2_COND_REG_3                              = 0x020107C6ull;

static const uint64_t P9N2_PU_N1_DBG_INST2_COND_REG_3                              = 0x030107C6ull;

static const uint64_t P9N2_PU_N2_DBG_INST2_COND_REG_3                              = 0x040107C6ull;

static const uint64_t P9N2_PU_N3_DBG_INST2_COND_REG_3                              = 0x050107C6ull;


static const uint64_t P9N2_PEC_DBG_MODE_REG                                        = 0x0D0107C0ull;

static const uint64_t P9N2_PEC_0_DBG_MODE_REG                                      = 0x0D0107C0ull;

static const uint64_t P9N2_PEC_1_DBG_MODE_REG                                      = 0x0E0107C0ull;

static const uint64_t P9N2_PEC_2_DBG_MODE_REG                                      = 0x0F0107C0ull;


static const uint64_t P9N2_PU_N0_DBG_MODE_REG                                      = 0x020107C0ull;

static const uint64_t P9N2_PU_N1_DBG_MODE_REG                                      = 0x030107C0ull;

static const uint64_t P9N2_PU_N2_DBG_MODE_REG                                      = 0x040107C0ull;

static const uint64_t P9N2_PU_N3_DBG_MODE_REG                                      = 0x050107C0ull;


static const uint64_t P9N2_PEC_DBG_TRACE_MODE_REG_2                                = 0x0D0107CFull;

static const uint64_t P9N2_PEC_0_DBG_TRACE_MODE_REG_2                              = 0x0D0107CFull;

static const uint64_t P9N2_PEC_1_DBG_TRACE_MODE_REG_2                              = 0x0E0107CFull;

static const uint64_t P9N2_PEC_2_DBG_TRACE_MODE_REG_2                              = 0x0F0107CFull;


static const uint64_t P9N2_PU_N0_DBG_TRACE_MODE_REG_2                              = 0x020107CFull;

static const uint64_t P9N2_PU_N1_DBG_TRACE_MODE_REG_2                              = 0x030107CFull;

static const uint64_t P9N2_PU_N2_DBG_TRACE_MODE_REG_2                              = 0x040107CFull;

static const uint64_t P9N2_PU_N3_DBG_TRACE_MODE_REG_2                              = 0x050107CFull;


static const uint64_t P9N2_PEC_DBG_TRACE_REG_0                                     = 0x0D0107CDull;

static const uint64_t P9N2_PEC_0_DBG_TRACE_REG_0                                   = 0x0D0107CDull;

static const uint64_t P9N2_PEC_1_DBG_TRACE_REG_0                                   = 0x0E0107CDull;

static const uint64_t P9N2_PEC_2_DBG_TRACE_REG_0                                   = 0x0F0107CDull;


static const uint64_t P9N2_PU_N0_DBG_TRACE_REG_0                                   = 0x020107CDull;

static const uint64_t P9N2_PU_N1_DBG_TRACE_REG_0                                   = 0x030107CDull;

static const uint64_t P9N2_PU_N2_DBG_TRACE_REG_0                                   = 0x040107CDull;

static const uint64_t P9N2_PU_N3_DBG_TRACE_REG_0                                   = 0x050107CDull;


static const uint64_t P9N2_PEC_DBG_TRACE_REG_1                                     = 0x0D0107CEull;

static const uint64_t P9N2_PEC_0_DBG_TRACE_REG_1                                   = 0x0D0107CEull;

static const uint64_t P9N2_PEC_1_DBG_TRACE_REG_1                                   = 0x0E0107CEull;

static const uint64_t P9N2_PEC_2_DBG_TRACE_REG_1                                   = 0x0F0107CEull;


static const uint64_t P9N2_PU_N0_DBG_TRACE_REG_1                                   = 0x020107CEull;

static const uint64_t P9N2_PU_N1_DBG_TRACE_REG_1                                   = 0x030107CEull;

static const uint64_t P9N2_PU_N2_DBG_TRACE_REG_1                                   = 0x040107CEull;

static const uint64_t P9N2_PU_N3_DBG_TRACE_REG_1                                   = 0x050107CEull;


static const uint64_t P9N2_NV_DEBUG0_CONFIG                                        = 0x050110C8ull;

static const uint64_t P9N2_NV_0_DEBUG0_CONFIG                                      = 0x050110C8ull;

static const uint64_t P9N2_NV_4_DEBUG0_CONFIG                                      = 0x050114C8ull;

static const uint64_t P9N2_PU_NPU0_CTL_DEBUG0_CONFIG                               = 0x05011083ull;

static const uint64_t P9N2_PU_NPU0_DAT_DEBUG0_CONFIG                               = 0x050110B3ull;

static const uint64_t P9N2_PU_NPU2_DAT_DEBUG0_CONFIG                               = 0x050112B3ull;

static const uint64_t P9N2_PU_NPU2_CTL_DEBUG0_CONFIG                               = 0x05011283ull;

static const uint64_t P9N2_PU_NPU0_SM1_DEBUG0_CONFIG                               = 0x05011023ull;

static const uint64_t P9N2_PU_NPU0_SM2_DEBUG0_CONFIG                               = 0x05011053ull;

static const uint64_t P9N2_PU_NPU1_SM0_DEBUG0_CONFIG                               = 0x0501111Cull;
//DUPS: 0501111C,
static const uint64_t P9N2_PU_NPU1_SM1_DEBUG0_CONFIG                               = 0x0501113Cull;

static const uint64_t P9N2_PU_NPU2_NTL0_DEBUG0_CONFIG                              = 0x050112C8ull;

static const uint64_t P9N2_PU_NPU2_SM1_DEBUG0_CONFIG                               = 0x05011223ull;

static const uint64_t P9N2_PU_NPU2_SM2_DEBUG0_CONFIG                               = 0x05011253ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_DEBUG0_CONFIG                            = 0x05011483ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_DEBUG0_CONFIG                            = 0x050114B3ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_DEBUG0_CONFIG                            = 0x05011423ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_DEBUG0_CONFIG                            = 0x05011453ull;

static const uint64_t P9N2_PU_NPU_SM0_DEBUG0_CONFIG                                = 0x0501131Cull;
//DUPS: 0501131C,
static const uint64_t P9N2_PU_NPU_SM1_DEBUG0_CONFIG                                = 0x0501133Cull;

static const uint64_t P9N2__SM0_DEBUG0_CONFIG                                      = 0x0501151Cull;
//DUPS: 0501151C,
static const uint64_t P9N2__SM1_DEBUG0_CONFIG                                      = 0x0501153Cull;

static const uint64_t P9N2__SM2_DEBUG0_CONFIG                                      = 0x05011646ull;


static const uint64_t P9N2_NV_DEBUG1_CONFIG                                        = 0x050110C9ull;

static const uint64_t P9N2_NV_0_DEBUG1_CONFIG                                      = 0x050110C9ull;

static const uint64_t P9N2_NV_4_DEBUG1_CONFIG                                      = 0x050114C9ull;

static const uint64_t P9N2_PU_NPU0_CTL_DEBUG1_CONFIG                               = 0x05011084ull;

static const uint64_t P9N2_PU_NPU0_DAT_DEBUG1_CONFIG                               = 0x050110B4ull;

static const uint64_t P9N2_PU_NPU2_DAT_DEBUG1_CONFIG                               = 0x050112B4ull;

static const uint64_t P9N2_PU_NPU2_CTL_DEBUG1_CONFIG                               = 0x05011284ull;

static const uint64_t P9N2_PU_NPU0_SM1_DEBUG1_CONFIG                               = 0x05011024ull;

static const uint64_t P9N2_PU_NPU0_SM2_DEBUG1_CONFIG                               = 0x05011054ull;

static const uint64_t P9N2_PU_NPU1_SM0_DEBUG1_CONFIG                               = 0x0501111Dull;
//DUPS: 0501111D,
static const uint64_t P9N2_PU_NPU1_SM1_DEBUG1_CONFIG                               = 0x0501113Dull;

static const uint64_t P9N2_PU_NPU2_NTL0_DEBUG1_CONFIG                              = 0x050112C9ull;

static const uint64_t P9N2_PU_NPU2_SM1_DEBUG1_CONFIG                               = 0x05011224ull;

static const uint64_t P9N2_PU_NPU2_SM2_DEBUG1_CONFIG                               = 0x05011254ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_DEBUG1_CONFIG                            = 0x05011484ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_DEBUG1_CONFIG                            = 0x050114B4ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_DEBUG1_CONFIG                            = 0x05011424ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_DEBUG1_CONFIG                            = 0x05011454ull;

static const uint64_t P9N2_PU_NPU_SM0_DEBUG1_CONFIG                                = 0x0501131Dull;
//DUPS: 0501131D,
static const uint64_t P9N2_PU_NPU_SM1_DEBUG1_CONFIG                                = 0x0501133Dull;

static const uint64_t P9N2__SM0_DEBUG1_CONFIG                                      = 0x0501151Dull;
//DUPS: 0501151D,
static const uint64_t P9N2__SM1_DEBUG1_CONFIG                                      = 0x0501153Dull;

static const uint64_t P9N2__SM2_DEBUG1_CONFIG                                      = 0x05011647ull;


static const uint64_t P9N2_PU_NPU0_CTL_DEBUG3_CONFIG                               = 0x05011087ull;

static const uint64_t P9N2_PU_NPU0_DAT_DEBUG3_CONFIG                               = 0x050110B7ull;

static const uint64_t P9N2_PU_NPU2_CTL_DEBUG3_CONFIG                               = 0x05011287ull;

static const uint64_t P9N2_PU_NPU2_DAT_DEBUG3_CONFIG                               = 0x050112B7ull;

static const uint64_t P9N2_PU_NPU0_SM1_DEBUG3_CONFIG                               = 0x05011027ull;

static const uint64_t P9N2_PU_NPU0_SM2_DEBUG3_CONFIG                               = 0x05011057ull;

static const uint64_t P9N2_PU_NPU2_SM1_DEBUG3_CONFIG                               = 0x05011227ull;

static const uint64_t P9N2_PU_NPU2_SM2_DEBUG3_CONFIG                               = 0x05011257ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_DEBUG3_CONFIG                            = 0x05011487ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_DEBUG3_CONFIG                            = 0x050114B7ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_DEBUG3_CONFIG                            = 0x05011427ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_DEBUG3_CONFIG                            = 0x05011457ull;


static const uint64_t P9N2_PU_NPU0_CTL_DEBUG4_CONFIG                               = 0x05011088ull;

static const uint64_t P9N2_PU_NPU0_DAT_DEBUG4_CONFIG                               = 0x050110B8ull;

static const uint64_t P9N2_PU_NPU2_CTL_DEBUG4_CONFIG                               = 0x05011288ull;

static const uint64_t P9N2_PU_NPU2_DAT_DEBUG4_CONFIG                               = 0x050112B8ull;

static const uint64_t P9N2_PU_NPU0_SM1_DEBUG4_CONFIG                               = 0x05011028ull;

static const uint64_t P9N2_PU_NPU0_SM2_DEBUG4_CONFIG                               = 0x05011058ull;

static const uint64_t P9N2_PU_NPU2_SM1_DEBUG4_CONFIG                               = 0x05011228ull;

static const uint64_t P9N2_PU_NPU2_SM2_DEBUG4_CONFIG                               = 0x05011258ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_DEBUG4_CONFIG                            = 0x05011488ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_DEBUG4_CONFIG                            = 0x050114B8ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_DEBUG4_CONFIG                            = 0x05011428ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_DEBUG4_CONFIG                            = 0x05011458ull;


static const uint64_t P9N2__CTL_DEBUG_CONFIG                                       = 0x05011680ull;


static const uint64_t P9N2_CAPP_DEBUG_CONTROL                                      = 0x02010811ull;

static const uint64_t P9N2_CAPP_0_DEBUG_CONTROL                                    = 0x02010811ull;

static const uint64_t P9N2_CAPP_1_DEBUG_CONTROL                                    = 0x04010811ull;


static const uint64_t P9N2_PU_DEBUG_TRACE_CONTROL                                  = 0x020107D0ull;
//DUPS: 050107D0, 030107D0, 040107D0,

static const uint64_t P9N2_PEC_DEBUG_TRACE_CONTROL                                 = 0x0D0107D0ull;

static const uint64_t P9N2_PEC_0_DEBUG_TRACE_CONTROL                               = 0x0D0107D0ull;

static const uint64_t P9N2_PEC_1_DEBUG_TRACE_CONTROL                               = 0x0E0107D0ull;

static const uint64_t P9N2_PEC_2_DEBUG_TRACE_CONTROL                               = 0x0F0107D0ull;


static const uint64_t P9N2_CAPP_DFSUOP1                                            = 0x02010843ull;

static const uint64_t P9N2_CAPP_0_DFSUOP1                                          = 0x02010843ull;

static const uint64_t P9N2_CAPP_1_DFSUOP1                                          = 0x04010843ull;


static const uint64_t P9N2_PU_DISABLE_FORCE_PFET_OFF                               = 0x0001000Dull;


static const uint64_t P9N2__SM1_DMA_SYNC                                           = 0x05011623ull;


static const uint64_t P9N2_PU_DMA_UP_ADDR                                          = 0x05012914ull;


static const uint64_t P9N2_PU_DMA_VAS_MMIO_BAR                                     = 0x0201105Eull;


static const uint64_t P9N2_PEC_DRPPRICTL_REG                                       = 0x04010C01ull;

static const uint64_t P9N2_PEC_0_DRPPRICTL_REG                                     = 0x04010C01ull;

static const uint64_t P9N2_PEC_1_DRPPRICTL_REG                                     = 0x04011001ull;

static const uint64_t P9N2_PEC_2_DRPPRICTL_REG                                     = 0x04011401ull;


static const uint64_t P9N2_PEC_DTS_RESULT0                                         = 0x0D050000ull;

static const uint64_t P9N2_PEC_0_DTS_RESULT0                                       = 0x0D050000ull;

static const uint64_t P9N2_PEC_1_DTS_RESULT0                                       = 0x0E050000ull;

static const uint64_t P9N2_PEC_2_DTS_RESULT0                                       = 0x0F050000ull;


static const uint64_t P9N2_PEC_DTS_TRC_RESULT                                      = 0x0D050003ull;

static const uint64_t P9N2_PEC_0_DTS_TRC_RESULT                                    = 0x0D050003ull;

static const uint64_t P9N2_PEC_1_DTS_TRC_RESULT                                    = 0x0E050003ull;

static const uint64_t P9N2_PEC_2_DTS_TRC_RESULT                                    = 0x0F050003ull;


static const uint64_t P9N2_NV_1_ECC_CONFIG                                         = 0x050110F2ull;

static const uint64_t P9N2_NV_5_ECC_CONFIG                                         = 0x050114F2ull;

static const uint64_t P9N2_PU_NPU2_NTL1_ECC_CONFIG                                 = 0x050112F2ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART0_REGISTER                          = 0x00018000ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART0_REGISTER                          = 0x00018040ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART10_REGISTER                         = 0x0001800Aull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART10_REGISTER                         = 0x0001804Aull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART11_REGISTER                         = 0x0001800Bull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART11_REGISTER                         = 0x0001804Bull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART12_REGISTER                         = 0x0001800Cull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART12_REGISTER                         = 0x0001804Cull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART13_REGISTER                         = 0x0001800Dull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART13_REGISTER                         = 0x0001804Dull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART14_REGISTER                         = 0x0001800Eull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART14_REGISTER                         = 0x0001804Eull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART15_REGISTER                         = 0x0001800Full;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART15_REGISTER                         = 0x0001804Full;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART16_REGISTER                         = 0x00018010ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART16_REGISTER                         = 0x00018050ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART17_REGISTER                         = 0x00018011ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART17_REGISTER                         = 0x00018051ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART18_REGISTER                         = 0x00018012ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART18_REGISTER                         = 0x00018052ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART19_REGISTER                         = 0x00018013ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART19_REGISTER                         = 0x00018053ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART1_REGISTER                          = 0x00018001ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART1_REGISTER                          = 0x00018041ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART20_REGISTER                         = 0x00018014ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART20_REGISTER                         = 0x00018054ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART21_REGISTER                         = 0x00018015ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART21_REGISTER                         = 0x00018055ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART22_REGISTER                         = 0x00018016ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART22_REGISTER                         = 0x00018056ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART23_REGISTER                         = 0x00018017ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART23_REGISTER                         = 0x00018057ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART24_REGISTER                         = 0x00018018ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART24_REGISTER                         = 0x00018058ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART25_REGISTER                         = 0x00018019ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART25_REGISTER                         = 0x00018059ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART26_REGISTER                         = 0x0001801Aull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART26_REGISTER                         = 0x0001805Aull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART27_REGISTER                         = 0x0001801Bull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART27_REGISTER                         = 0x0001805Bull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART28_REGISTER                         = 0x0001801Cull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART28_REGISTER                         = 0x0001805Cull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART29_REGISTER                         = 0x0001801Dull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART29_REGISTER                         = 0x0001805Dull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART2_REGISTER                          = 0x00018002ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART2_REGISTER                          = 0x00018042ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART30_REGISTER                         = 0x0001801Eull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART30_REGISTER                         = 0x0001805Eull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART31_REGISTER                         = 0x0001801Full;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART31_REGISTER                         = 0x0001805Full;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART32_REGISTER                         = 0x00018020ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART32_REGISTER                         = 0x00018060ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART33_REGISTER                         = 0x00018021ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART33_REGISTER                         = 0x00018061ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART34_REGISTER                         = 0x00018022ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART34_REGISTER                         = 0x00018062ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART35_REGISTER                         = 0x00018023ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART35_REGISTER                         = 0x00018063ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART36_REGISTER                         = 0x00018024ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART36_REGISTER                         = 0x00018064ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART37_REGISTER                         = 0x00018025ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART37_REGISTER                         = 0x00018065ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART38_REGISTER                         = 0x00018026ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART38_REGISTER                         = 0x00018066ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART39_REGISTER                         = 0x00018027ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART39_REGISTER                         = 0x00018067ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART3_REGISTER                          = 0x00018003ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART3_REGISTER                          = 0x00018043ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART40_REGISTER                         = 0x00018028ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART40_REGISTER                         = 0x00018068ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART41_REGISTER                         = 0x00018029ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART41_REGISTER                         = 0x00018069ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART42_REGISTER                         = 0x0001802Aull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART42_REGISTER                         = 0x0001806Aull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART43_REGISTER                         = 0x0001802Bull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART43_REGISTER                         = 0x0001806Bull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART44_REGISTER                         = 0x0001802Cull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART44_REGISTER                         = 0x0001806Cull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART45_REGISTER                         = 0x0001802Dull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART45_REGISTER                         = 0x0001806Dull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART46_REGISTER                         = 0x0001802Eull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART46_REGISTER                         = 0x0001806Eull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART47_REGISTER                         = 0x0001802Full;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART47_REGISTER                         = 0x0001806Full;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART48_REGISTER                         = 0x00018030ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART48_REGISTER                         = 0x00018070ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART49_REGISTER                         = 0x00018031ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART49_REGISTER                         = 0x00018071ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART4_REGISTER                          = 0x00018004ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART4_REGISTER                          = 0x00018044ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART50_REGISTER                         = 0x00018032ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART50_REGISTER                         = 0x00018072ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART51_REGISTER                         = 0x00018033ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART51_REGISTER                         = 0x00018073ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART52_REGISTER                         = 0x00018034ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART52_REGISTER                         = 0x00018074ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART53_REGISTER                         = 0x00018035ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART53_REGISTER                         = 0x00018075ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART54_REGISTER                         = 0x00018036ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART54_REGISTER                         = 0x00018076ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART55_REGISTER                         = 0x00018037ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART55_REGISTER                         = 0x00018077ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART56_REGISTER                         = 0x00018038ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART56_REGISTER                         = 0x00018078ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART57_REGISTER                         = 0x00018039ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART57_REGISTER                         = 0x00018079ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART58_REGISTER                         = 0x0001803Aull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART58_REGISTER                         = 0x0001807Aull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART59_REGISTER                         = 0x0001803Bull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART59_REGISTER                         = 0x0001807Bull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART5_REGISTER                          = 0x00018005ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART5_REGISTER                          = 0x00018045ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART60_REGISTER                         = 0x0001803Cull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART60_REGISTER                         = 0x0001807Cull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART61_REGISTER                         = 0x0001803Dull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART61_REGISTER                         = 0x0001807Dull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART62_REGISTER                         = 0x0001803Eull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART62_REGISTER                         = 0x0001807Eull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART63_REGISTER                         = 0x0001803Full;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART63_REGISTER                         = 0x0001807Full;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART6_REGISTER                          = 0x00018006ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART6_REGISTER                          = 0x00018046ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART7_REGISTER                          = 0x00018007ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART7_REGISTER                          = 0x00018047ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART8_REGISTER                          = 0x00018008ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART8_REGISTER                          = 0x00018048ull;


static const uint64_t P9N2_PU_OTPROM0_ECID_PART9_REGISTER                          = 0x00018009ull;

static const uint64_t P9N2_PU_OTPROM1_ECID_PART9_REGISTER                          = 0x00018049ull;


static const uint64_t P9N2_PEC_EDRAM_STATUS                                        = 0x0D0F0029ull;

static const uint64_t P9N2_PEC_0_EDRAM_STATUS                                      = 0x0D0F0029ull;

static const uint64_t P9N2_PEC_1_EDRAM_STATUS                                      = 0x0E0F0029ull;

static const uint64_t P9N2_PEC_2_EDRAM_STATUS                                      = 0x0F0F0029ull;


static const uint64_t P9N2_PU_EECNT_REG                                            = 0x05012809ull;


static const uint64_t P9N2_PU_EFT_HI_PRIOR_RCV_FIFO_ASB                            = 0x020110C6ull;


static const uint64_t P9N2_PU_EFT_HI_PRIOR_RCV_FIFO_BAR                            = 0x020110C0ull;


static const uint64_t P9N2_PU_EFT_HI_PRIOR_RCV_FIFO_CNTL                           = 0x020110C3ull;


static const uint64_t P9N2_PU_EFT_LO_PRIOR_RCV_FIFO_ASB                            = 0x020110CFull;


static const uint64_t P9N2_PU_EFT_LO_PRIOR_RCV_FIFO_BAR                            = 0x020110C9ull;


static const uint64_t P9N2_PU_EFT_LO_PRIOR_RCV_FIFO_CNTL                           = 0x020110CCull;


static const uint64_t P9N2_PU_EFT_MAX_BYTE_CNT                                     = 0x02011059ull;


static const uint64_t P9N2_PU_EMPTY_10                                             = 0x05012910ull;


static const uint64_t P9N2_PU_EMPTY_1B                                             = 0x0501291Bull;


static const uint64_t P9N2_PU_ENHCA_FIR_ACTION0_REG                                = 0x05012946ull;


static const uint64_t P9N2_PU_ENHCA_FIR_ACTION1_REG                                = 0x05012947ull;


static const uint64_t P9N2_PU_ENHCA_FIR_MASK_REG                                   = 0x05012943ull;

static const uint64_t P9N2_PU_ENHCA_FIR_MASK_REG_AND                               = 0x05012944ull;

static const uint64_t P9N2_PU_ENHCA_FIR_MASK_REG_OR                                = 0x05012945ull;


static const uint64_t P9N2_PU_ENHCA_FIR_REG                                        = 0x05012940ull;

static const uint64_t P9N2_PU_ENHCA_FIR_REG_AND                                    = 0x05012941ull;

static const uint64_t P9N2_PU_ENHCA_FIR_REG_OR                                     = 0x05012942ull;


static const uint64_t P9N2_PU_NPU0_CTL_EPSILON_CONFIG                              = 0x05011092ull;

static const uint64_t P9N2_PU_NPU2_CTL_EPSILON_CONFIG                              = 0x05011292ull;

static const uint64_t P9N2_PU_NPU0_SM0_EPSILON_CONFIG                              = 0x05011002ull;

static const uint64_t P9N2_PU_NPU0_SM1_EPSILON_CONFIG                              = 0x05011032ull;

static const uint64_t P9N2_PU_NPU0_SM3_EPSILON_CONFIG                              = 0x05011062ull;

static const uint64_t P9N2_PU_NPU2_SM0_EPSILON_CONFIG                              = 0x05011202ull;

static const uint64_t P9N2_PU_NPU2_SM1_EPSILON_CONFIG                              = 0x05011232ull;

static const uint64_t P9N2_PU_NPU2_SM3_EPSILON_CONFIG                              = 0x05011262ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_EPSILON_CONFIG                           = 0x05011492ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_EPSILON_CONFIG                           = 0x05011402ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_EPSILON_CONFIG                           = 0x05011432ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_EPSILON_CONFIG                           = 0x05011462ull;


static const uint64_t P9N2_PU_ERAT_STATUS_CONTROL                                  = 0x020110D6ull;


static const uint64_t P9N2__CTL_ERROR_BRICK_GROUP_CONFIG                           = 0x05011694ull;


static const uint64_t P9N2_PEC_ERROR_REG                                           = 0x0D0F001Full;

static const uint64_t P9N2_PEC_0_ERROR_REG                                         = 0x0D0F001Full;

static const uint64_t P9N2_PEC_1_ERROR_REG                                         = 0x0E0F001Full;

static const uint64_t P9N2_PEC_2_ERROR_REG                                         = 0x0F0F001Full;


static const uint64_t P9N2_PU_NPU_CTL_ERROR_SIG_RXI                                = 0x0501138Eull;

static const uint64_t P9N2_PU_NPU_SM2_ERROR_SIG_RXI                                = 0x0501135Eull;

static const uint64_t P9N2__CTL_ERROR_SIG_RXI                                      = 0x0501158Eull;

static const uint64_t P9N2__SM2_ERROR_SIG_RXI                                      = 0x0501155Eull;


static const uint64_t P9N2_PU_NPU_CTL_ERROR_SIG_RXO                                = 0x0501138Full;

static const uint64_t P9N2_PU_NPU_SM2_ERROR_SIG_RXO                                = 0x0501135Full;

static const uint64_t P9N2__CTL_ERROR_SIG_RXO                                      = 0x0501158Full;

static const uint64_t P9N2__SM2_ERROR_SIG_RXO                                      = 0x0501155Full;


static const uint64_t P9N2_PEC_ERROR_STATUS                                        = 0x0D03000Full;

static const uint64_t P9N2_PEC_0_ERROR_STATUS                                      = 0x0D03000Full;

static const uint64_t P9N2_PEC_1_ERROR_STATUS                                      = 0x0E03000Full;

static const uint64_t P9N2_PEC_2_ERROR_STATUS                                      = 0x0F03000Full;


static const uint64_t P9N2_CAPP_ERRRPT                                             = 0x0201080Bull;

static const uint64_t P9N2_CAPP_0_ERRRPT                                           = 0x0201080Bull;

static const uint64_t P9N2_CAPP_1_ERRRPT                                           = 0x0401080Bull;


static const uint64_t P9N2__SM2_ERR_FIRST                                          = 0x05011643ull;


static const uint64_t P9N2__SM2_ERR_HOLD                                           = 0x05011640ull;


static const uint64_t P9N2__CTL_ERR_INFO_NPU_RING_ADDR                             = 0x05011692ull;


static const uint64_t P9N2__SM2_ERR_MASK                                           = 0x05011642ull;


static const uint64_t P9N2_CAPP_ERR_RPT_CLR                                        = 0x02010813ull;

static const uint64_t P9N2_CAPP_0_ERR_RPT_CLR                                      = 0x02010813ull;

static const uint64_t P9N2_CAPP_1_ERR_RPT_CLR                                      = 0x04010813ull;


static const uint64_t P9N2__CTL_ERR_SCOPE_CTL_CONFIG                               = 0x05011691ull;


static const uint64_t P9N2_PEC_ERR_STATUS_REG                                      = 0x0D050013ull;

static const uint64_t P9N2_PEC_0_ERR_STATUS_REG                                    = 0x0D050013ull;

static const uint64_t P9N2_PEC_1_ERR_STATUS_REG                                    = 0x0E050013ull;

static const uint64_t P9N2_PEC_2_ERR_STATUS_REG                                    = 0x0F050013ull;


static const uint64_t P9N2_PU_ESB_CI_BASE                                          = 0x05012916ull;


static const uint64_t P9N2_PU_ESB_NOTIFY                                           = 0x05012917ull;


static const uint64_t P9N2_PU_EXPORT_REGL_CTRL                                     = 0x0001000Eull;


static const uint64_t P9N2_PU_EXTENDED_STATUS_B                                    = 0x000A000Cull;


static const uint64_t P9N2_PU_EXTENDED_STATUS_C                                    = 0x000A100Cull;


static const uint64_t P9N2_PU_EXTENDED_STATUS_D                                    = 0x000A200Cull;


static const uint64_t P9N2_PU_EXTENDED_STATUS_E                                    = 0x000A300Cull;


static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_ACTION0_REG                       = 0x05011C34ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_ACTION1_REG                       = 0x05011C35ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_MASK_REG                          = 0x05011C31ull;

static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_MASK_REG_AND                      = 0x05011C32ull;

static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR                       = 0x05011C33ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_REG                               = 0x05011C2Eull;

static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_REG_AND                           = 0x05011C2Full;

static const uint64_t P9N2_PU_PB_CENT_SM1_EXTFIR_REG_OR                            = 0x05011C30ull;


static const uint64_t P9N2__CTL_FENCE_0_CONFIG                                     = 0x0501168Aull;


static const uint64_t P9N2__CTL_FENCE_1_CONFIG                                     = 0x0501168Bull;


static const uint64_t P9N2_PU_NPU_SM0_FENCE_2_CONFIG                               = 0x05011700ull;


static const uint64_t P9N2_NV_1_FENCE_CONTROL0                                     = 0x050110E8ull;

static const uint64_t P9N2_NV_5_FENCE_CONTROL0                                     = 0x050114E8ull;

static const uint64_t P9N2_PU_NPU2_NTL1_FENCE_CONTROL0                             = 0x050112E8ull;


static const uint64_t P9N2_NV_1_FENCE_CONTROL1                                     = 0x050110E9ull;

static const uint64_t P9N2_NV_5_FENCE_CONTROL1                                     = 0x050114E9ull;

static const uint64_t P9N2_PU_NPU2_NTL1_FENCE_CONTROL1                             = 0x050112E9ull;


static const uint64_t P9N2__CTL_FENCE_STATE                                        = 0x05011696ull;


static const uint64_t P9N2_PU_FI2C_CFG_PPE                                         = 0xC0000800ull;

static const uint64_t P9N2_PU_FI2C_CFG_PPE1                                        = 0xC0000810ull;

static const uint64_t P9N2_PU_FI2C_CFG_PPE2                                        = 0xC0000818ull;


static const uint64_t P9N2_PU_FI2C_SCFG0_PPE                                       = 0xC0000860ull;

static const uint64_t P9N2_PU_FI2C_SCFG0_PPE1                                      = 0xC0000870ull;

static const uint64_t P9N2_PU_FI2C_SCFG0_PPE2                                      = 0xC0000878ull;


static const uint64_t P9N2_PU_FI2C_SCFG1_PPE                                       = 0xC0000880ull;

static const uint64_t P9N2_PU_FI2C_SCFG1_PPE1                                      = 0xC0000890ull;

static const uint64_t P9N2_PU_FI2C_SCFG1_PPE2                                      = 0xC0000898ull;


static const uint64_t P9N2_PU_FI2C_SCFG2_PPE                                       = 0xC00008A0ull;

static const uint64_t P9N2_PU_FI2C_SCFG2_PPE1                                      = 0xC00008B0ull;

static const uint64_t P9N2_PU_FI2C_SCFG2_PPE2                                      = 0xC00008B8ull;


static const uint64_t P9N2_PU_FI2C_SCFG3_PPE                                       = 0xC00008C0ull;

static const uint64_t P9N2_PU_FI2C_SCFG3_PPE1                                      = 0xC00008D0ull;

static const uint64_t P9N2_PU_FI2C_SCFG3_PPE2                                      = 0xC00008D8ull;


static const uint64_t P9N2_PU_FI2C_STAT_PPE                                        = 0xC0000820ull;


static const uint64_t P9N2_PU_FIFO1_REGISTER_READ_B                                = 0x000A0004ull;


static const uint64_t P9N2_PU_FIFO1_REGISTER_READ_C                                = 0x000A1004ull;


static const uint64_t P9N2_PU_FIFO1_REGISTER_READ_D                                = 0x000A2004ull;


static const uint64_t P9N2_PU_FIFO1_REGISTER_READ_E                                = 0x000A3004ull;


static const uint64_t P9N2_PU_FIFO4_REGISTER_READ_B                                = 0x000A0012ull;


static const uint64_t P9N2_PU_FIFO4_REGISTER_READ_C                                = 0x000A1012ull;


static const uint64_t P9N2_PU_FIFO4_REGISTER_READ_D                                = 0x000A2012ull;


static const uint64_t P9N2_PU_FIFO4_REGISTER_READ_E                                = 0x000A3012ull;


static const uint64_t P9N2_PU_FIR_ACTION0_REG                                      = 0x04011806ull;

static const uint64_t P9N2_CAPP_FIR_ACTION0_REG                                    = 0x02010806ull;

static const uint64_t P9N2_CAPP_0_FIR_ACTION0_REG                                  = 0x02010806ull;

static const uint64_t P9N2_CAPP_1_FIR_ACTION0_REG                                  = 0x04010806ull;


static const uint64_t P9N2_PEC_FIR_ACTION0_REG                                     = 0x0D010C06ull;

static const uint64_t P9N2_PEC_0_FIR_ACTION0_REG                                   = 0x0D010C06ull;

static const uint64_t P9N2_PEC_1_FIR_ACTION0_REG                                   = 0x0E010C06ull;

static const uint64_t P9N2_PEC_2_FIR_ACTION0_REG                                   = 0x0F010C06ull;


static const uint64_t P9N2_PU_FIR_ACTION0_REG_0                                    = 0x05013C06ull;


static const uint64_t P9N2_PU_FIR_ACTION0_REG_1                                    = 0x05013C46ull;


static const uint64_t P9N2_PU_FIR_ACTION0_REG_2                                    = 0x05013C86ull;


static const uint64_t P9N2_PU_FIR_ACTION1_REG                                      = 0x04011807ull;

static const uint64_t P9N2_CAPP_FIR_ACTION1_REG                                    = 0x02010807ull;

static const uint64_t P9N2_CAPP_0_FIR_ACTION1_REG                                  = 0x02010807ull;

static const uint64_t P9N2_CAPP_1_FIR_ACTION1_REG                                  = 0x04010807ull;


static const uint64_t P9N2_PEC_FIR_ACTION1_REG                                     = 0x0D010C07ull;

static const uint64_t P9N2_PEC_0_FIR_ACTION1_REG                                   = 0x0D010C07ull;

static const uint64_t P9N2_PEC_1_FIR_ACTION1_REG                                   = 0x0E010C07ull;

static const uint64_t P9N2_PEC_2_FIR_ACTION1_REG                                   = 0x0F010C07ull;


static const uint64_t P9N2_PU_FIR_ACTION1_REG_0                                    = 0x05013C07ull;


static const uint64_t P9N2_PU_FIR_ACTION1_REG_1                                    = 0x05013C47ull;


static const uint64_t P9N2_PU_FIR_ACTION1_REG_2                                    = 0x05013C87ull;


static const uint64_t P9N2_PEC_FIR_MASK                                            = 0x0D040002ull;

static const uint64_t P9N2_PEC_0_FIR_MASK                                          = 0x0D040002ull;

static const uint64_t P9N2_PEC_1_FIR_MASK                                          = 0x0E040002ull;

static const uint64_t P9N2_PEC_2_FIR_MASK                                          = 0x0F040002ull;


static const uint64_t P9N2_PU_FIR_MASK_REG                                         = 0x04011803ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_AND                                     = 0x04011804ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_OR                                      = 0x04011805ull;

static const uint64_t P9N2_CAPP_FIR_MASK_REG                                       = 0x02010803ull;

static const uint64_t P9N2_CAPP_FIR_MASK_REG_AND                                   = 0x02010804ull;

static const uint64_t P9N2_CAPP_FIR_MASK_REG_OR                                    = 0x02010805ull;

static const uint64_t P9N2_CAPP_0_FIR_MASK_REG                                     = 0x02010803ull;

static const uint64_t P9N2_CAPP_0_FIR_MASK_REG_AND                                 = 0x02010804ull;

static const uint64_t P9N2_CAPP_0_FIR_MASK_REG_OR                                  = 0x02010805ull;

static const uint64_t P9N2_CAPP_1_FIR_MASK_REG                                     = 0x04010803ull;

static const uint64_t P9N2_CAPP_1_FIR_MASK_REG_AND                                 = 0x04010804ull;

static const uint64_t P9N2_CAPP_1_FIR_MASK_REG_OR                                  = 0x04010805ull;


static const uint64_t P9N2_PEC_FIR_MASK_REG                                        = 0x0D010C03ull;

static const uint64_t P9N2_PEC_FIR_MASK_REG_AND                                    = 0x0D010C04ull;

static const uint64_t P9N2_PEC_FIR_MASK_REG_OR                                     = 0x0D010C05ull;

static const uint64_t P9N2_PEC_0_FIR_MASK_REG                                      = 0x0D010C03ull;

static const uint64_t P9N2_PEC_0_FIR_MASK_REG_AND                                  = 0x0D010C04ull;

static const uint64_t P9N2_PEC_0_FIR_MASK_REG_OR                                   = 0x0D010C05ull;

static const uint64_t P9N2_PEC_1_FIR_MASK_REG                                      = 0x0E010C03ull;

static const uint64_t P9N2_PEC_1_FIR_MASK_REG_AND                                  = 0x0E010C04ull;

static const uint64_t P9N2_PEC_1_FIR_MASK_REG_OR                                   = 0x0E010C05ull;

static const uint64_t P9N2_PEC_2_FIR_MASK_REG                                      = 0x0F010C03ull;

static const uint64_t P9N2_PEC_2_FIR_MASK_REG_AND                                  = 0x0F010C04ull;

static const uint64_t P9N2_PEC_2_FIR_MASK_REG_OR                                   = 0x0F010C05ull;


static const uint64_t P9N2_PU_FIR_MASK_REGISTER                                    = 0x00088008ull;


static const uint64_t P9N2_PU_FIR_MASK_REG_0                                       = 0x05013C03ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_0_AND                                   = 0x05013C04ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_0_OR                                    = 0x05013C05ull;


static const uint64_t P9N2_PU_FIR_MASK_REG_1                                       = 0x05013C43ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_1_AND                                   = 0x05013C44ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_1_OR                                    = 0x05013C45ull;


static const uint64_t P9N2_PU_FIR_MASK_REG_2                                       = 0x05013C83ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_2_AND                                   = 0x05013C84ull;

static const uint64_t P9N2_PU_FIR_MASK_REG_2_OR                                    = 0x05013C85ull;


static const uint64_t P9N2_PU_FIR_REG                                              = 0x04011800ull;

static const uint64_t P9N2_PU_FIR_REG_AND                                          = 0x04011801ull;

static const uint64_t P9N2_PU_FIR_REG_OR                                           = 0x04011802ull;

static const uint64_t P9N2_CAPP_FIR_REG                                            = 0x02010800ull;

static const uint64_t P9N2_CAPP_FIR_REG_AND                                        = 0x02010801ull;

static const uint64_t P9N2_CAPP_FIR_REG_OR                                         = 0x02010802ull;

static const uint64_t P9N2_CAPP_0_FIR_REG                                          = 0x02010800ull;

static const uint64_t P9N2_CAPP_0_FIR_REG_AND                                      = 0x02010801ull;

static const uint64_t P9N2_CAPP_0_FIR_REG_OR                                       = 0x02010802ull;

static const uint64_t P9N2_CAPP_1_FIR_REG                                          = 0x04010800ull;

static const uint64_t P9N2_CAPP_1_FIR_REG_AND                                      = 0x04010801ull;

static const uint64_t P9N2_CAPP_1_FIR_REG_OR                                       = 0x04010802ull;


static const uint64_t P9N2_PHB_FIR_REG                                             = 0x0D010908ull;

static const uint64_t P9N2_PHB_FIR_REG_AND                                         = 0x0D010909ull;

static const uint64_t P9N2_PHB_FIR_REG_OR                                          = 0x0D01090Aull;

static const uint64_t P9N2_PHB_0_FIR_REG                                           = 0x0D010908ull;

static const uint64_t P9N2_PHB_0_FIR_REG_AND                                       = 0x0D010909ull;

static const uint64_t P9N2_PHB_0_FIR_REG_OR                                        = 0x0D01090Aull;

static const uint64_t P9N2_PHB_1_FIR_REG                                           = 0x0E010908ull;

static const uint64_t P9N2_PHB_1_FIR_REG_AND                                       = 0x0E010909ull;

static const uint64_t P9N2_PHB_1_FIR_REG_OR                                        = 0x0E01090Aull;

static const uint64_t P9N2_PHB_2_FIR_REG                                           = 0x0E010948ull;

static const uint64_t P9N2_PHB_2_FIR_REG_AND                                       = 0x0E010949ull;

static const uint64_t P9N2_PHB_2_FIR_REG_OR                                        = 0x0E01094Aull;

static const uint64_t P9N2_PHB_3_FIR_REG                                           = 0x0F010908ull;

static const uint64_t P9N2_PHB_3_FIR_REG_AND                                       = 0x0F010909ull;

static const uint64_t P9N2_PHB_3_FIR_REG_OR                                        = 0x0F01090Aull;

static const uint64_t P9N2_PHB_4_FIR_REG                                           = 0x0F010948ull;

static const uint64_t P9N2_PHB_4_FIR_REG_AND                                       = 0x0F010949ull;

static const uint64_t P9N2_PHB_4_FIR_REG_OR                                        = 0x0F01094Aull;

static const uint64_t P9N2_PHB_5_FIR_REG                                           = 0x0F010988ull;

static const uint64_t P9N2_PHB_5_FIR_REG_AND                                       = 0x0F010989ull;

static const uint64_t P9N2_PHB_5_FIR_REG_OR                                        = 0x0F01098Aull;


static const uint64_t P9N2_PU_FIR_REG_0                                            = 0x05013C00ull;

static const uint64_t P9N2_PU_FIR_REG_0_AND                                        = 0x05013C01ull;

static const uint64_t P9N2_PU_FIR_REG_0_OR                                         = 0x05013C02ull;


static const uint64_t P9N2_PU_FIR_REG_1                                            = 0x05013C40ull;

static const uint64_t P9N2_PU_FIR_REG_1_AND                                        = 0x05013C41ull;

static const uint64_t P9N2_PU_FIR_REG_1_OR                                         = 0x05013C42ull;


static const uint64_t P9N2_PU_FIR_REG_2                                            = 0x05013C80ull;

static const uint64_t P9N2_PU_FIR_REG_2_AND                                        = 0x05013C81ull;

static const uint64_t P9N2_PU_FIR_REG_2_OR                                         = 0x05013C82ull;


static const uint64_t P9N2_PEC_FIR_STATUS_REG                                      = 0x0D010C00ull;

static const uint64_t P9N2_PEC_FIR_STATUS_REG_AND                                  = 0x0D010C01ull;

static const uint64_t P9N2_PEC_FIR_STATUS_REG_OR                                   = 0x0D010C02ull;

static const uint64_t P9N2_PEC_0_FIR_STATUS_REG                                    = 0x0D010C00ull;

static const uint64_t P9N2_PEC_0_FIR_STATUS_REG_AND                                = 0x0D010C01ull;

static const uint64_t P9N2_PEC_0_FIR_STATUS_REG_OR                                 = 0x0D010C02ull;

static const uint64_t P9N2_PEC_1_FIR_STATUS_REG                                    = 0x0E010C00ull;

static const uint64_t P9N2_PEC_1_FIR_STATUS_REG_AND                                = 0x0E010C01ull;

static const uint64_t P9N2_PEC_1_FIR_STATUS_REG_OR                                 = 0x0E010C02ull;

static const uint64_t P9N2_PEC_2_FIR_STATUS_REG                                    = 0x0F010C00ull;

static const uint64_t P9N2_PEC_2_FIR_STATUS_REG_AND                                = 0x0F010C01ull;

static const uint64_t P9N2_PEC_2_FIR_STATUS_REG_OR                                 = 0x0F010C02ull;


static const uint64_t P9N2_PU_FIR_WOF_REG                                          = 0x04011808ull;

static const uint64_t P9N2_PEC_FIR_WOF_REG                                         = 0x0D010C08ull;

static const uint64_t P9N2_PEC_0_FIR_WOF_REG                                       = 0x0D010C08ull;

static const uint64_t P9N2_PEC_1_FIR_WOF_REG                                       = 0x0E010C08ull;

static const uint64_t P9N2_PEC_2_FIR_WOF_REG                                       = 0x0F010C08ull;


static const uint64_t P9N2_CAPP_FLUSHCPIG                                          = 0x02010820ull;

static const uint64_t P9N2_CAPP_0_FLUSHCPIG                                        = 0x02010820ull;

static const uint64_t P9N2_CAPP_1_FLUSHCPIG                                        = 0x04010820ull;


static const uint64_t P9N2_CAPP_FLUSHSHUE                                          = 0x0201080Full;

static const uint64_t P9N2_CAPP_0_FLUSHSHUE                                        = 0x0201080Full;

static const uint64_t P9N2_CAPP_1_FLUSHSHUE                                        = 0x0401080Full;


static const uint64_t P9N2_PU_FORCE_ECC_REG                                        = 0x0009000Dull;


static const uint64_t P9N2__CTL_FREEZE_0_CONFIG                                    = 0x05011688ull;


static const uint64_t P9N2__CTL_FREEZE_1_CONFIG                                    = 0x05011689ull;


static const uint64_t P9N2__CTL_FREEZE_STATE                                       = 0x05011695ull;


static const uint64_t P9N2_PU_FSB_DOWNFIFO_DATA_IN                                 = 0x000B0010ull;


static const uint64_t P9N2_PU_FSB_DOWNFIFO_MTC                                     = 0x000B0016ull;


static const uint64_t P9N2_PU_FSB_DOWNFIFO_REQ_RESET                               = 0x000B0013ull;


static const uint64_t P9N2_PU_FSB_DOWNFIFO_SIG_EOT                                 = 0x000B0012ull;


static const uint64_t P9N2_PU_FSB_DOWNFIFO_STATUS                                  = 0x000B0011ull;


static const uint64_t P9N2_PU_FSB_UPFIFO_ACK_EOT                                   = 0x000B0005ull;


static const uint64_t P9N2_PU_FSB_UPFIFO_DATA_OUT                                  = 0x000B0000ull;


static const uint64_t P9N2_PU_FSB_UPFIFO_RESET                                     = 0x000B0004ull;


static const uint64_t P9N2_PU_FSB_UPFIFO_STATUS                                    = 0x000B0001ull;


static const uint64_t P9N2_PU_NPU0_CTL_GENID_BAR                                   = 0x05011097ull;

static const uint64_t P9N2_PU_NPU2_CTL_GENID_BAR                                   = 0x05011297ull;

static const uint64_t P9N2_PU_NPU0_SM0_GENID_BAR                                   = 0x05011007ull;

static const uint64_t P9N2_PU_NPU0_SM1_GENID_BAR                                   = 0x05011037ull;

static const uint64_t P9N2_PU_NPU0_SM3_GENID_BAR                                   = 0x05011067ull;

static const uint64_t P9N2_PU_NPU2_SM0_GENID_BAR                                   = 0x05011207ull;

static const uint64_t P9N2_PU_NPU2_SM1_GENID_BAR                                   = 0x05011237ull;

static const uint64_t P9N2_PU_NPU2_SM3_GENID_BAR                                   = 0x05011267ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_GENID_BAR                                = 0x05011497ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_GENID_BAR                                = 0x05011407ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_GENID_BAR                                = 0x05011437ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_GENID_BAR                                = 0x05011467ull;


static const uint64_t P9N2_NV_1_GENID_HEAD0                                        = 0x050110E0ull;

static const uint64_t P9N2_NV_5_GENID_HEAD0                                        = 0x050114E0ull;

static const uint64_t P9N2_PU_NPU2_NTL1_GENID_HEAD0                                = 0x050112E0ull;


static const uint64_t P9N2_NV_1_GENID_HEAD1                                        = 0x050110E1ull;

static const uint64_t P9N2_NV_5_GENID_HEAD1                                        = 0x050114E1ull;

static const uint64_t P9N2_PU_NPU2_NTL1_GENID_HEAD1                                = 0x050112E1ull;


static const uint64_t P9N2_NV_1_GENID_TAIL0                                        = 0x050110E2ull;

static const uint64_t P9N2_NV_5_GENID_TAIL0                                        = 0x050114E2ull;

static const uint64_t P9N2_PU_NPU2_NTL1_GENID_TAIL0                                = 0x050112E2ull;


static const uint64_t P9N2_NV_1_GENID_TAIL1                                        = 0x050110E3ull;

static const uint64_t P9N2_NV_5_GENID_TAIL1                                        = 0x050114E3ull;

static const uint64_t P9N2_PU_NPU2_NTL1_GENID_TAIL1                                = 0x050112E3ull;


static const uint64_t P9N2_PU_GPE0_GPEDBG_OCI                                      = 0xC0000010ull;

static const uint64_t P9N2_PU_GPE0_GPEDBG_SCOM                                     = 0x00060002ull;


static const uint64_t P9N2_PU_GPE0_GPEIVPR_OCI                                     = 0xC0000008ull;

static const uint64_t P9N2_PU_GPE0_GPEIVPR_SCOM                                    = 0x00060001ull;


static const uint64_t P9N2_PU_GPE0_GPEMACR_OCI                                     = 0xC0000020ull;

static const uint64_t P9N2_PU_GPE0_GPEMACR_SCOM                                    = 0x00060004ull;


static const uint64_t P9N2_PU_GPE0_GPENXIXCR_OCI                                   = 0xC0000080ull;

static const uint64_t P9N2_PU_GPE0_GPENXIXCR_SCOM                                  = 0x00060010ull;


static const uint64_t P9N2_PU_GPE0_GPESTR_OCI                                      = 0xC0000018ull;

static const uint64_t P9N2_PU_GPE0_GPESTR_SCOM                                     = 0x00060003ull;


static const uint64_t P9N2_PU_GPE0_GPETSEL_OCI                                     = 0xC0000000ull;

static const uint64_t P9N2_PU_GPE0_GPETSEL_SCOM                                    = 0x00060000ull;


static const uint64_t P9N2_PU_GPE0_GPEXIEDR_OCI                                    = 0xC0000118ull;

static const uint64_t P9N2_PU_GPE0_GPEXIEDR_SCOM                                   = 0x00060023ull;


static const uint64_t P9N2_PU_GPE0_GPEXIIAR_OCI                                    = 0xC0000128ull;

static const uint64_t P9N2_PU_GPE0_GPEXIIAR_SCOM                                   = 0x00060025ull;


static const uint64_t P9N2_PU_GPE0_GPEXIIR_OCI                                     = 0xC0000120ull;

static const uint64_t P9N2_PU_GPE0_GPEXIIR_SCOM                                    = 0x00060024ull;


static const uint64_t P9N2_PU_GPE0_GPEXISPRG0_OCI                                  = 0xC0000110ull;

static const uint64_t P9N2_PU_GPE0_GPEXISPRG0_SCOM                                 = 0x00060022ull;


static const uint64_t P9N2_PU_GPE0_GPEXIXCR_OCI                                    = 0xC0000100ull;

static const uint64_t P9N2_PU_GPE0_GPEXIXCR_SCOM                                   = 0x00060020ull;


static const uint64_t P9N2_PU_GPE0_GPEXIXSR_OCI                                    = 0xC0000108ull;

static const uint64_t P9N2_PU_GPE0_GPEXIXSR_SCOM                                   = 0x00060021ull;


static const uint64_t P9N2_PU_GPE0_MIB_XIDCAC_OCI                                  = 0xC00000D0ull;

static const uint64_t P9N2_PU_GPE0_MIB_XIDCAC_SCOM                                 = 0x0006001Aull;


static const uint64_t P9N2_PU_GPE0_MIB_XIICAC                                      = 0x00060019ull;


static const uint64_t P9N2_PU_GPE0_MIB_XIMEM                                       = 0x00060017ull;


static const uint64_t P9N2_PU_GPE0_MIB_XISGB                                       = 0x00060018ull;


static const uint64_t P9N2_PU_GPE0_MIB_XISIB_OCI                                   = 0xC00000B0ull;

static const uint64_t P9N2_PU_GPE0_MIB_XISIB_SCOM                                  = 0x00060016ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIDBGPRO                                    = 0x00060015ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIRAMDBG                                    = 0x00060013ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIRAMEDR                                    = 0x00060014ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIRAMGA                                     = 0x00060012ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIRAMRA                                     = 0x00060011ull;


static const uint64_t P9N2_PU_GPE0_PPE_XIXCR                                       = 0x00060010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_GPE1_GPEDBG_OCI                                      = 0xC0010010ull;

static const uint64_t P9N2_PU_GPE1_GPEDBG_SCOM                                     = 0x00062002ull;


static const uint64_t P9N2_PU_GPE1_GPEIVPR_OCI                                     = 0xC0010008ull;

static const uint64_t P9N2_PU_GPE1_GPEIVPR_SCOM                                    = 0x00062001ull;


static const uint64_t P9N2_PU_GPE1_GPEMACR_OCI                                     = 0xC0010020ull;

static const uint64_t P9N2_PU_GPE1_GPEMACR_SCOM                                    = 0x00062004ull;


static const uint64_t P9N2_PU_GPE1_GPENXIXCR_OCI                                   = 0xC0010080ull;

static const uint64_t P9N2_PU_GPE1_GPENXIXCR_SCOM                                  = 0x00062010ull;


static const uint64_t P9N2_PU_GPE1_GPESTR_OCI                                      = 0xC0010018ull;

static const uint64_t P9N2_PU_GPE1_GPESTR_SCOM                                     = 0x00062003ull;


static const uint64_t P9N2_PU_GPE1_GPETSEL_OCI                                     = 0xC0010000ull;

static const uint64_t P9N2_PU_GPE1_GPETSEL_SCOM                                    = 0x00062000ull;


static const uint64_t P9N2_PU_GPE1_GPEXIEDR_OCI                                    = 0xC0010118ull;

static const uint64_t P9N2_PU_GPE1_GPEXIEDR_SCOM                                   = 0x00062023ull;


static const uint64_t P9N2_PU_GPE1_GPEXIIAR_OCI                                    = 0xC0010128ull;

static const uint64_t P9N2_PU_GPE1_GPEXIIAR_SCOM                                   = 0x00062025ull;


static const uint64_t P9N2_PU_GPE1_GPEXIIR_OCI                                     = 0xC0010120ull;

static const uint64_t P9N2_PU_GPE1_GPEXIIR_SCOM                                    = 0x00062024ull;


static const uint64_t P9N2_PU_GPE1_GPEXISPRG0_OCI                                  = 0xC0010110ull;

static const uint64_t P9N2_PU_GPE1_GPEXISPRG0_SCOM                                 = 0x00062022ull;


static const uint64_t P9N2_PU_GPE1_GPEXIXCR_OCI                                    = 0xC0010100ull;

static const uint64_t P9N2_PU_GPE1_GPEXIXCR_SCOM                                   = 0x00062020ull;


static const uint64_t P9N2_PU_GPE1_GPEXIXSR_OCI                                    = 0xC0010108ull;

static const uint64_t P9N2_PU_GPE1_GPEXIXSR_SCOM                                   = 0x00062021ull;


static const uint64_t P9N2_PU_GPE1_MIB_XIDCAC_OCI                                  = 0xC00100D0ull;

static const uint64_t P9N2_PU_GPE1_MIB_XIDCAC_SCOM                                 = 0x0006201Aull;


static const uint64_t P9N2_PU_GPE1_MIB_XIICAC                                      = 0x00062019ull;


static const uint64_t P9N2_PU_GPE1_MIB_XIMEM                                       = 0x00062017ull;


static const uint64_t P9N2_PU_GPE1_MIB_XISGB                                       = 0x00062018ull;


static const uint64_t P9N2_PU_GPE1_MIB_XISIB_OCI                                   = 0xC00100B0ull;

static const uint64_t P9N2_PU_GPE1_MIB_XISIB_SCOM                                  = 0x00062016ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIDBGPRO                                    = 0x00062015ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIRAMDBG                                    = 0x00062013ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIRAMEDR                                    = 0x00062014ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIRAMGA                                     = 0x00062012ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIRAMRA                                     = 0x00062011ull;


static const uint64_t P9N2_PU_GPE1_PPE_XIXCR                                       = 0x00062010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_GPE2_GPEDBG_OCI                                      = 0xC0020010ull;

static const uint64_t P9N2_PU_GPE2_GPEDBG_SCOM                                     = 0x00064002ull;


static const uint64_t P9N2_PU_GPE2_GPEIVPR_OCI                                     = 0xC0020008ull;

static const uint64_t P9N2_PU_GPE2_GPEIVPR_SCOM                                    = 0x00064001ull;


static const uint64_t P9N2_PU_GPE2_GPEMACR_OCI                                     = 0xC0020020ull;

static const uint64_t P9N2_PU_GPE2_GPEMACR_SCOM                                    = 0x00064004ull;


static const uint64_t P9N2_PU_GPE2_GPENXIXCR_OCI                                   = 0xC0020080ull;

static const uint64_t P9N2_PU_GPE2_GPENXIXCR_SCOM                                  = 0x00064010ull;


static const uint64_t P9N2_PU_GPE2_GPESTR_OCI                                      = 0xC0020018ull;

static const uint64_t P9N2_PU_GPE2_GPESTR_SCOM                                     = 0x00064003ull;


static const uint64_t P9N2_PU_GPE2_GPETSEL_OCI                                     = 0xC0020000ull;

static const uint64_t P9N2_PU_GPE2_GPETSEL_SCOM                                    = 0x00064000ull;


static const uint64_t P9N2_PU_GPE2_GPEXIEDR_OCI                                    = 0xC0020118ull;

static const uint64_t P9N2_PU_GPE2_GPEXIEDR_SCOM                                   = 0x00064023ull;


static const uint64_t P9N2_PU_GPE2_GPEXIIAR_OCI                                    = 0xC0020128ull;

static const uint64_t P9N2_PU_GPE2_GPEXIIAR_SCOM                                   = 0x00064025ull;


static const uint64_t P9N2_PU_GPE2_GPEXIIR_OCI                                     = 0xC0020120ull;

static const uint64_t P9N2_PU_GPE2_GPEXIIR_SCOM                                    = 0x00064024ull;


static const uint64_t P9N2_PU_GPE2_GPEXISPRG0_OCI                                  = 0xC0020110ull;

static const uint64_t P9N2_PU_GPE2_GPEXISPRG0_SCOM                                 = 0x00064022ull;


static const uint64_t P9N2_PU_GPE2_GPEXIXCR_OCI                                    = 0xC0020100ull;

static const uint64_t P9N2_PU_GPE2_GPEXIXCR_SCOM                                   = 0x00064020ull;


static const uint64_t P9N2_PU_GPE2_GPEXIXSR_OCI                                    = 0xC0020108ull;

static const uint64_t P9N2_PU_GPE2_GPEXIXSR_SCOM                                   = 0x00064021ull;


static const uint64_t P9N2_PU_GPE2_MIB_XIDCAC_OCI                                  = 0xC00200D0ull;

static const uint64_t P9N2_PU_GPE2_MIB_XIDCAC_SCOM                                 = 0x0006401Aull;


static const uint64_t P9N2_PU_GPE2_MIB_XIICAC                                      = 0x00064019ull;


static const uint64_t P9N2_PU_GPE2_MIB_XIMEM                                       = 0x00064017ull;


static const uint64_t P9N2_PU_GPE2_MIB_XISGB                                       = 0x00064018ull;


static const uint64_t P9N2_PU_GPE2_MIB_XISIB_OCI                                   = 0xC00200B0ull;

static const uint64_t P9N2_PU_GPE2_MIB_XISIB_SCOM                                  = 0x00064016ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIDBGPRO                                    = 0x00064015ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIRAMDBG                                    = 0x00064013ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIRAMEDR                                    = 0x00064014ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIRAMGA                                     = 0x00064012ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIRAMRA                                     = 0x00064011ull;


static const uint64_t P9N2_PU_GPE2_PPE_XIXCR                                       = 0x00064010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_GPE3_GPEDBG_OCI                                      = 0xC0030010ull;

static const uint64_t P9N2_PU_GPE3_GPEDBG_SCOM                                     = 0x00066002ull;


static const uint64_t P9N2_PU_GPE3_GPEIVPR_OCI                                     = 0xC0030008ull;

static const uint64_t P9N2_PU_GPE3_GPEIVPR_SCOM                                    = 0x00066001ull;


static const uint64_t P9N2_PU_GPE3_GPEMACR_OCI                                     = 0xC0030020ull;

static const uint64_t P9N2_PU_GPE3_GPEMACR_SCOM                                    = 0x00066004ull;


static const uint64_t P9N2_PU_GPE3_GPENXIXCR_OCI                                   = 0xC0030080ull;

static const uint64_t P9N2_PU_GPE3_GPENXIXCR_SCOM                                  = 0x00066010ull;


static const uint64_t P9N2_PU_GPE3_GPESTR_OCI                                      = 0xC0030018ull;

static const uint64_t P9N2_PU_GPE3_GPESTR_SCOM                                     = 0x00066003ull;


static const uint64_t P9N2_PU_GPE3_GPETSEL_OCI                                     = 0xC0030000ull;

static const uint64_t P9N2_PU_GPE3_GPETSEL_SCOM                                    = 0x00066000ull;


static const uint64_t P9N2_PU_GPE3_GPEXIEDR_OCI                                    = 0xC0030118ull;

static const uint64_t P9N2_PU_GPE3_GPEXIEDR_SCOM                                   = 0x00066023ull;


static const uint64_t P9N2_PU_GPE3_GPEXIIAR_OCI                                    = 0xC0030128ull;

static const uint64_t P9N2_PU_GPE3_GPEXIIAR_SCOM                                   = 0x00066025ull;


static const uint64_t P9N2_PU_GPE3_GPEXIIR_OCI                                     = 0xC0030120ull;

static const uint64_t P9N2_PU_GPE3_GPEXIIR_SCOM                                    = 0x00066024ull;


static const uint64_t P9N2_PU_GPE3_GPEXISPRG0_OCI                                  = 0xC0030110ull;

static const uint64_t P9N2_PU_GPE3_GPEXISPRG0_SCOM                                 = 0x00066022ull;


static const uint64_t P9N2_PU_GPE3_GPEXIXCR_OCI                                    = 0xC0030100ull;

static const uint64_t P9N2_PU_GPE3_GPEXIXCR_SCOM                                   = 0x00066020ull;


static const uint64_t P9N2_PU_GPE3_GPEXIXSR_OCI                                    = 0xC0030108ull;

static const uint64_t P9N2_PU_GPE3_GPEXIXSR_SCOM                                   = 0x00066021ull;


static const uint64_t P9N2_PU_GPE3_MIB_XIDCAC_OCI                                  = 0xC00300D0ull;

static const uint64_t P9N2_PU_GPE3_MIB_XIDCAC_SCOM                                 = 0x0006601Aull;


static const uint64_t P9N2_PU_GPE3_MIB_XIICAC                                      = 0x00066019ull;


static const uint64_t P9N2_PU_GPE3_MIB_XIMEM                                       = 0x00066017ull;


static const uint64_t P9N2_PU_GPE3_MIB_XISGB                                       = 0x00066018ull;


static const uint64_t P9N2_PU_GPE3_MIB_XISIB_OCI                                   = 0xC00300B0ull;

static const uint64_t P9N2_PU_GPE3_MIB_XISIB_SCOM                                  = 0x00066016ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIDBGPRO                                    = 0x00066015ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIRAMDBG                                    = 0x00066013ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIRAMEDR                                    = 0x00066014ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIRAMGA                                     = 0x00066012ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIRAMRA                                     = 0x00066011ull;


static const uint64_t P9N2_PU_GPE3_PPE_XIXCR                                       = 0x00066010ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_GPIO_INPUT                                           = 0x000B0050ull;


static const uint64_t P9N2_PU_GPIO_INT_COND                                        = 0x000B005Eull;


static const uint64_t P9N2_PU_GPIO_INT_ENABLE                                      = 0x000B005Dull;


static const uint64_t P9N2_PU_GPIO_INT_POLARITY                                    = 0x000B005Cull;


static const uint64_t P9N2_PU_GPIO_INT_STATUS                                      = 0x000B0057ull;


static const uint64_t P9N2_PU_GPIO_MODE                                            = 0x000B0059ull;


static const uint64_t P9N2_PU_GPIO_OUTPUT                                          = 0x000B0051ull;

static const uint64_t P9N2_PU_GPIO_OUTPUT_OR                                       = 0x000B0052ull;

static const uint64_t P9N2_PU_GPIO_OUTPUT_CLEAR                                    = 0x000B0053ull;


static const uint64_t P9N2_PU_GPIO_OUTPUT_EN                                       = 0x000B0054ull;


static const uint64_t P9N2_PU_NPU0_CTL_GPU0_BAR                                    = 0x05011094ull;

static const uint64_t P9N2_PU_NPU2_CTL_GPU0_BAR                                    = 0x05011294ull;

static const uint64_t P9N2_PU_NPU0_SM0_GPU0_BAR                                    = 0x05011004ull;

static const uint64_t P9N2_PU_NPU0_SM1_GPU0_BAR                                    = 0x05011034ull;

static const uint64_t P9N2_PU_NPU0_SM3_GPU0_BAR                                    = 0x05011064ull;

static const uint64_t P9N2_PU_NPU2_SM0_GPU0_BAR                                    = 0x05011204ull;

static const uint64_t P9N2_PU_NPU2_SM1_GPU0_BAR                                    = 0x05011234ull;

static const uint64_t P9N2_PU_NPU2_SM3_GPU0_BAR                                    = 0x05011264ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_GPU0_BAR                                 = 0x05011494ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_GPU0_BAR                                 = 0x05011404ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_GPU0_BAR                                 = 0x05011434ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_GPU0_BAR                                 = 0x05011464ull;


static const uint64_t P9N2_PU_NPU0_CTL_GPU1_BAR                                    = 0x05011095ull;

static const uint64_t P9N2_PU_NPU2_CTL_GPU1_BAR                                    = 0x05011295ull;

static const uint64_t P9N2_PU_NPU0_SM0_GPU1_BAR                                    = 0x05011005ull;

static const uint64_t P9N2_PU_NPU0_SM1_GPU1_BAR                                    = 0x05011035ull;

static const uint64_t P9N2_PU_NPU0_SM3_GPU1_BAR                                    = 0x05011065ull;

static const uint64_t P9N2_PU_NPU2_SM0_GPU1_BAR                                    = 0x05011205ull;

static const uint64_t P9N2_PU_NPU2_SM1_GPU1_BAR                                    = 0x05011235ull;

static const uint64_t P9N2_PU_NPU2_SM3_GPU1_BAR                                    = 0x05011265ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_GPU1_BAR                                 = 0x05011495ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_GPU1_BAR                                 = 0x05011405ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_GPU1_BAR                                 = 0x05011435ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_GPU1_BAR                                 = 0x05011465ull;


static const uint64_t P9N2_PEC_GXSTOP0_MASK_REG                                    = 0x0D040014ull;

static const uint64_t P9N2_PEC_0_GXSTOP0_MASK_REG                                  = 0x0D040014ull;

static const uint64_t P9N2_PEC_1_GXSTOP0_MASK_REG                                  = 0x0E040014ull;

static const uint64_t P9N2_PEC_2_GXSTOP0_MASK_REG                                  = 0x0F040014ull;


static const uint64_t P9N2_PEC_GXSTOP1_MASK_REG                                    = 0x0D040015ull;

static const uint64_t P9N2_PEC_0_GXSTOP1_MASK_REG                                  = 0x0D040015ull;

static const uint64_t P9N2_PEC_1_GXSTOP1_MASK_REG                                  = 0x0E040015ull;

static const uint64_t P9N2_PEC_2_GXSTOP1_MASK_REG                                  = 0x0F040015ull;


static const uint64_t P9N2_PEC_GXSTOP2_MASK_REG                                    = 0x0D040016ull;

static const uint64_t P9N2_PEC_0_GXSTOP2_MASK_REG                                  = 0x0D040016ull;

static const uint64_t P9N2_PEC_1_GXSTOP2_MASK_REG                                  = 0x0E040016ull;

static const uint64_t P9N2_PEC_2_GXSTOP2_MASK_REG                                  = 0x0F040016ull;


static const uint64_t P9N2_PEC_GXSTOP_TRIG_REG                                     = 0x0D040013ull;

static const uint64_t P9N2_PEC_0_GXSTOP_TRIG_REG                                   = 0x0D040013ull;

static const uint64_t P9N2_PEC_1_GXSTOP_TRIG_REG                                   = 0x0E040013ull;

static const uint64_t P9N2_PEC_2_GXSTOP_TRIG_REG                                   = 0x0F040013ull;


static const uint64_t P9N2_PU_GZIP_CONTROL_REG                                     = 0x02011140ull;


static const uint64_t P9N2_PU_GZIP_ERRRPT_HOLD_REG                                 = 0x02011152ull;


static const uint64_t P9N2_PU_GZIP_HI_PRIOR_RCV_FIFO_ASB                           = 0x020110C8ull;


static const uint64_t P9N2_PU_GZIP_HI_PRIOR_RCV_FIFO_BAR                           = 0x020110C2ull;


static const uint64_t P9N2_PU_GZIP_HI_PRIOR_RCV_FIFO_CNTL                          = 0x020110C5ull;


static const uint64_t P9N2_PU_GZIP_LO_PRIOR_RCV_FIFO_ASB                           = 0x020110D1ull;


static const uint64_t P9N2_PU_GZIP_LO_PRIOR_RCV_FIFO_BAR                           = 0x020110CBull;


static const uint64_t P9N2_PU_GZIP_LO_PRIOR_RCV_FIFO_CNTL                          = 0x020110CEull;


static const uint64_t P9N2_PU_GZIP_MAX_BYTE_CNT                                    = 0x0201105Bull;


static const uint64_t P9N2_PEC_HANG_PULSE_0_REG                                    = 0x0D0F0020ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_0_REG                                  = 0x0D0F0020ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_0_REG                                  = 0x0E0F0020ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_0_REG                                  = 0x0F0F0020ull;


static const uint64_t P9N2_PEC_HANG_PULSE_1_REG                                    = 0x0D0F0021ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_1_REG                                  = 0x0D0F0021ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_1_REG                                  = 0x0E0F0021ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_1_REG                                  = 0x0F0F0021ull;


static const uint64_t P9N2_PEC_HANG_PULSE_2_REG                                    = 0x0D0F0022ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_2_REG                                  = 0x0D0F0022ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_2_REG                                  = 0x0E0F0022ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_2_REG                                  = 0x0F0F0022ull;


static const uint64_t P9N2_PEC_HANG_PULSE_3_REG                                    = 0x0D0F0023ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_3_REG                                  = 0x0D0F0023ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_3_REG                                  = 0x0E0F0023ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_3_REG                                  = 0x0F0F0023ull;


static const uint64_t P9N2_PEC_HANG_PULSE_4_REG                                    = 0x0D0F0024ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_4_REG                                  = 0x0D0F0024ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_4_REG                                  = 0x0E0F0024ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_4_REG                                  = 0x0F0F0024ull;


static const uint64_t P9N2_PEC_HANG_PULSE_5_REG                                    = 0x0D0F0025ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_5_REG                                  = 0x0D0F0025ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_5_REG                                  = 0x0E0F0025ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_5_REG                                  = 0x0F0F0025ull;


static const uint64_t P9N2_PEC_HANG_PULSE_6_REG                                    = 0x0D0F0026ull;

static const uint64_t P9N2_PEC_0_HANG_PULSE_6_REG                                  = 0x0D0F0026ull;

static const uint64_t P9N2_PEC_1_HANG_PULSE_6_REG                                  = 0x0E0F0026ull;

static const uint64_t P9N2_PEC_2_HANG_PULSE_6_REG                                  = 0x0F0F0026ull;


static const uint64_t P9N2_PU_HCA_BAR                                              = 0x0501294Aull;


static const uint64_t P9N2_PU_HCA_COUNT_BAR                                        = 0x0501294Bull;


static const uint64_t P9N2_PU_HCA_DECAY1                                           = 0x0501294Cull;


static const uint64_t P9N2_PU_HCA_DECAY2                                           = 0x0501294Dull;


static const uint64_t P9N2_PU_HCA_DROP                                             = 0x05012951ull;


static const uint64_t P9N2_PU_HCA_MIRROR_BAR                                       = 0x05012953ull;


static const uint64_t P9N2_PU_HCA_MODES                                            = 0x0501294Full;


static const uint64_t P9N2_PU_HCA_REF_BAR                                          = 0x0501294Eull;


static const uint64_t P9N2_PU_HCA_RESET                                            = 0x05012952ull;


static const uint64_t P9N2_PEC_HEARTBEAT_REG                                       = 0x0D0F0018ull;

static const uint64_t P9N2_PEC_0_HEARTBEAT_REG                                     = 0x0D0F0018ull;

static const uint64_t P9N2_PEC_1_HEARTBEAT_REG                                     = 0x0E0F0018ull;

static const uint64_t P9N2_PEC_2_HEARTBEAT_REG                                     = 0x0F0F0018ull;


static const uint64_t P9N2_PU_NPU0_CTL_HIGH_WATER                                  = 0x05011099ull;

static const uint64_t P9N2_PU_NPU2_CTL_HIGH_WATER                                  = 0x05011299ull;

static const uint64_t P9N2_PU_NPU0_SM0_HIGH_WATER                                  = 0x05011009ull;

static const uint64_t P9N2_PU_NPU0_SM1_HIGH_WATER                                  = 0x05011039ull;

static const uint64_t P9N2_PU_NPU0_SM3_HIGH_WATER                                  = 0x05011069ull;

static const uint64_t P9N2_PU_NPU2_SM0_HIGH_WATER                                  = 0x05011209ull;

static const uint64_t P9N2_PU_NPU2_SM1_HIGH_WATER                                  = 0x05011239ull;

static const uint64_t P9N2_PU_NPU2_SM3_HIGH_WATER                                  = 0x05011269ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_HIGH_WATER                               = 0x05011499ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_HIGH_WATER                               = 0x05011409ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_HIGH_WATER                               = 0x05011439ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_HIGH_WATER                               = 0x05011469ull;


static const uint64_t P9N2_PEC_HOSTATTN                                            = 0x0D040009ull;

static const uint64_t P9N2_PEC_0_HOSTATTN                                          = 0x0D040009ull;

static const uint64_t P9N2_PEC_1_HOSTATTN                                          = 0x0E040009ull;

static const uint64_t P9N2_PEC_2_HOSTATTN                                          = 0x0F040009ull;


static const uint64_t P9N2_PEC_HOSTATTN_MASK                                       = 0x0D04001Aull;

static const uint64_t P9N2_PEC_0_HOSTATTN_MASK                                     = 0x0D04001Aull;

static const uint64_t P9N2_PEC_1_HOSTATTN_MASK                                     = 0x0E04001Aull;

static const uint64_t P9N2_PEC_2_HOSTATTN_MASK                                     = 0x0F04001Aull;


static const uint64_t P9N2_PU_HTM0_HTM_CFG                                         = 0x05012888ull;

static const uint64_t P9N2_PU_HTM1_HTM_CFG                                         = 0x050128C8ull;


static const uint64_t P9N2_PU_HTM0_HTM_CTRL                                        = 0x05012885ull;

static const uint64_t P9N2_PU_HTM1_HTM_CTRL                                        = 0x050128C5ull;


static const uint64_t P9N2_PU_HTM0_HTM_FILT                                        = 0x05012886ull;

static const uint64_t P9N2_PU_HTM1_HTM_FILT                                        = 0x050128C6ull;


static const uint64_t P9N2_PU_HTM0_HTM_FLEX                                        = 0x05012889ull;

static const uint64_t P9N2_PU_HTM1_HTM_FLEX                                        = 0x050128C9ull;


static const uint64_t P9N2_PU_HTM0_HTM_LAST                                        = 0x05012883ull;

static const uint64_t P9N2_PU_HTM1_HTM_LAST                                        = 0x050128C3ull;


static const uint64_t P9N2_PU_HTM0_HTM_MEM                                         = 0x05012881ull;

static const uint64_t P9N2_PU_HTM1_HTM_MEM                                         = 0x050128C1ull;


static const uint64_t P9N2_PU_HTM0_HTM_MODE                                        = 0x05012880ull;

static const uint64_t P9N2_PU_HTM1_HTM_MODE                                        = 0x050128C0ull;


static const uint64_t P9N2_PU_HTM0_HTM_STAT                                        = 0x05012882ull;

static const uint64_t P9N2_PU_HTM1_HTM_STAT                                        = 0x050128C2ull;


static const uint64_t P9N2_PU_HTM0_HTM_TRIG                                        = 0x05012884ull;

static const uint64_t P9N2_PU_HTM1_HTM_TRIG                                        = 0x050128C4ull;


static const uint64_t P9N2_PU_HTM0_HTM_TTYPEFILT                                   = 0x05012887ull;

static const uint64_t P9N2_PU_HTM1_HTM_TTYPEFILT                                   = 0x050128C7ull;


static const uint64_t P9N2_PU_I2C_BUSY_REGISTER_B                                  = 0x000A000Eull;


static const uint64_t P9N2_PU_I2C_BUSY_REGISTER_C                                  = 0x000A100Eull;


static const uint64_t P9N2_PU_I2C_BUSY_REGISTER_D                                  = 0x000A200Eull;


static const uint64_t P9N2_PU_I2C_BUSY_REGISTER_E                                  = 0x000A300Eull;


static const uint64_t P9N2_PU_IMM_RESET_ERR_B                                      = 0x000A000Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_IMM_RESET_ERR_C                                      = 0x000A100Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_IMM_RESET_ERR_D                                      = 0x000A200Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_IMM_RESET_ERR_E                                      = 0x000A300Cull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_IMM_RESET_I2C_B                                      = 0x000A000Bull;


static const uint64_t P9N2_PU_IMM_RESET_I2C_C                                      = 0x000A100Bull;


static const uint64_t P9N2_PU_IMM_RESET_I2C_D                                      = 0x000A200Bull;


static const uint64_t P9N2_PU_IMM_RESET_I2C_E                                      = 0x000A300Bull;


static const uint64_t P9N2_PU_IMM_RESET_S_SCL_B                                    = 0x000A000Full;


static const uint64_t P9N2_PU_IMM_RESET_S_SCL_C                                    = 0x000A100Full;


static const uint64_t P9N2_PU_IMM_RESET_S_SCL_D                                    = 0x000A200Full;


static const uint64_t P9N2_PU_IMM_RESET_S_SCL_E                                    = 0x000A300Full;


static const uint64_t P9N2_PU_IMM_RESET_S_SDA_B                                    = 0x000A0011ull;


static const uint64_t P9N2_PU_IMM_RESET_S_SDA_C                                    = 0x000A1011ull;


static const uint64_t P9N2_PU_IMM_RESET_S_SDA_D                                    = 0x000A2011ull;


static const uint64_t P9N2_PU_IMM_RESET_S_SDA_E                                    = 0x000A3011ull;


static const uint64_t P9N2_PU_IMM_SET_S_SCL_B                                      = 0x000A000Dull;


static const uint64_t P9N2_PU_IMM_SET_S_SCL_C                                      = 0x000A100Dull;


static const uint64_t P9N2_PU_IMM_SET_S_SCL_D                                      = 0x000A200Dull;


static const uint64_t P9N2_PU_IMM_SET_S_SCL_E                                      = 0x000A300Dull;


static const uint64_t P9N2_PU_IMM_SET_S_SDA_B                                      = 0x000A0010ull;


static const uint64_t P9N2_PU_IMM_SET_S_SDA_C                                      = 0x000A1010ull;


static const uint64_t P9N2_PU_IMM_SET_S_SDA_D                                      = 0x000A2010ull;


static const uint64_t P9N2_PU_IMM_SET_S_SDA_E                                      = 0x000A3010ull;


static const uint64_t P9N2_NV_INHIBIT_CONFIG                                       = 0x050110D1ull;

static const uint64_t P9N2_NV_0_INHIBIT_CONFIG                                     = 0x050110D1ull;

static const uint64_t P9N2_NV_4_INHIBIT_CONFIG                                     = 0x050114D1ull;

static const uint64_t P9N2_PU_NPU0_INHIBIT_CONFIG                                  = 0x050110A0ull;

static const uint64_t P9N2_PU_NPU2_INHIBIT_CONFIG                                  = 0x050112A0ull;

static const uint64_t P9N2_PU_NPU0_SM0_INHIBIT_CONFIG                              = 0x05011010ull;

static const uint64_t P9N2_PU_NPU0_SM2_INHIBIT_CONFIG                              = 0x05011040ull;

static const uint64_t P9N2_PU_NPU0_SM3_INHIBIT_CONFIG                              = 0x05011070ull;

static const uint64_t P9N2_PU_NPU2_NTL0_INHIBIT_CONFIG                             = 0x050112D1ull;

static const uint64_t P9N2_PU_NPU2_SM0_INHIBIT_CONFIG                              = 0x05011210ull;

static const uint64_t P9N2_PU_NPU2_SM2_INHIBIT_CONFIG                              = 0x05011240ull;

static const uint64_t P9N2_PU_NPU2_SM3_INHIBIT_CONFIG                              = 0x05011270ull;

static const uint64_t P9N2_PU_NPU_MSC_INHIBIT_CONFIG                               = 0x050114A0ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_INHIBIT_CONFIG                           = 0x05011410ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_INHIBIT_CONFIG                           = 0x05011440ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_INHIBIT_CONFIG                           = 0x05011470ull;

static const uint64_t P9N2__CTL_INHIBIT_CONFIG                                     = 0x05011687ull;


static const uint64_t P9N2_PEC_INJECT_REG                                          = 0x0D050011ull;

static const uint64_t P9N2_PEC_0_INJECT_REG                                        = 0x0D050011ull;

static const uint64_t P9N2_PEC_1_INJECT_REG                                        = 0x0E050011ull;

static const uint64_t P9N2_PEC_2_INJECT_REG                                        = 0x0F050011ull;


static const uint64_t P9N2_PEC_0_STACK0_INTBAR_REG                                 = 0x04010C53ull;

static const uint64_t P9N2_PEC_1_STACK0_INTBAR_REG                                 = 0x04011053ull;

static const uint64_t P9N2_PEC_1_STACK1_INTBAR_REG                                 = 0x04011093ull;

static const uint64_t P9N2_PEC_1_STACK2_INTBAR_REG                                 = 0x040110D3ull;

static const uint64_t P9N2_PEC_2_STACK0_INTBAR_REG                                 = 0x04011453ull;

static const uint64_t P9N2_PEC_2_STACK1_INTBAR_REG                                 = 0x04011493ull;

static const uint64_t P9N2_PEC_2_STACK2_INTBAR_REG                                 = 0x040114D3ull;

static const uint64_t P9N2_PEC_STACK0_INTBAR_REG                                   = 0x04010C53ull;

static const uint64_t P9N2_PHB_INTBAR_REG                                          = 0x04010C53ull;

static const uint64_t P9N2_PHB_0_INTBAR_REG                                        = 0x04010C53ull;

static const uint64_t P9N2_PHB_1_INTBAR_REG                                        = 0x04011053ull;

static const uint64_t P9N2_PHB_2_INTBAR_REG                                        = 0x04011093ull;

static const uint64_t P9N2_PHB_3_INTBAR_REG                                        = 0x04011453ull;

static const uint64_t P9N2_PHB_4_INTBAR_REG                                        = 0x04011493ull;

static const uint64_t P9N2_PHB_5_INTBAR_REG                                        = 0x040114D3ull;


static const uint64_t P9N2_PU_INTERRUPTS_B                                         = 0x000A000Aull;


static const uint64_t P9N2_PU_INTERRUPTS_C                                         = 0x000A100Aull;


static const uint64_t P9N2_PU_INTERRUPTS_D                                         = 0x000A200Aull;


static const uint64_t P9N2_PU_INTERRUPTS_E                                         = 0x000A300Aull;


static const uint64_t P9N2_PU_INTERRUPT_COND_B                                     = 0x000A0009ull;


static const uint64_t P9N2_PU_INTERRUPT_COND_C                                     = 0x000A1009ull;


static const uint64_t P9N2_PU_INTERRUPT_COND_D                                     = 0x000A2009ull;


static const uint64_t P9N2_PU_INTERRUPT_COND_E                                     = 0x000A3009ull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_B_WO                         = 0x000A0008ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_B_OR                         = 0x000A0009ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_B_AND                        = 0x000A000Aull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_C_WO                         = 0x000A1008ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_C_OR                         = 0x000A1009ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_C_AND                        = 0x000A100Aull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_D_WO                         = 0x000A2008ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_D_OR                         = 0x000A2009ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_D_AND                        = 0x000A200Aull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_E_WO                         = 0x000A3008ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_E_OR                         = 0x000A3009ull;

static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_E_AND                        = 0x000A300Aull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_READ_B                       = 0x000A0008ull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_READ_C                       = 0x000A1008ull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_READ_D                       = 0x000A2008ull;


static const uint64_t P9N2_PU_INTERRUPT_MASK_REGISTER_READ_E                       = 0x000A3008ull;


static const uint64_t P9N2__CTL_INT_0_CONFIG                                       = 0x0501168Cull;


static const uint64_t P9N2__CTL_INT_1_CONFIG                                       = 0x0501168Dull;


static const uint64_t P9N2_PU_NPU_SM0_INT_2_CONFIG                                 = 0x05011701ull;


static const uint64_t P9N2__CTL_INT_BAR                                            = 0x05011693ull;


static const uint64_t P9N2_PU_INT_CQ_ACTION0                                       = 0x05013036ull;


static const uint64_t P9N2_PU_INT_CQ_ACTION1                                       = 0x05013037ull;


static const uint64_t P9N2_PU_INT_CQ_AIB_CTL                                       = 0x05013022ull;


static const uint64_t P9N2_PU_INT_CQ_CFG_LDQ                                       = 0x05013026ull;


static const uint64_t P9N2_PU_INT_CQ_CFG_PB_GEN                                    = 0x0501300Aull;


static const uint64_t P9N2_PU_INT_CQ_CFG_STQ1                                      = 0x05013024ull;


static const uint64_t P9N2_PU_INT_CQ_CFG_STQ2                                      = 0x05013025ull;


static const uint64_t P9N2_PU_INT_CQ_CNPM_SEL                                      = 0x0501300Full;


static const uint64_t P9N2_PU_INT_CQ_ERR_INFO0                                     = 0x0501303Aull;


static const uint64_t P9N2_PU_INT_CQ_ERR_INFO1                                     = 0x0501303Bull;


static const uint64_t P9N2_PU_INT_CQ_ERR_INFO2                                     = 0x0501303Cull;


static const uint64_t P9N2_PU_INT_CQ_ERR_INFO3                                     = 0x0501303Dull;


static const uint64_t P9N2_PU_INT_CQ_ERR_RPT_HOLD                                  = 0x05013039ull;


static const uint64_t P9N2_PU_INT_CQ_FIR                                           = 0x05013030ull;

static const uint64_t P9N2_PU_INT_CQ_FIR_AND                                       = 0x05013031ull;

static const uint64_t P9N2_PU_INT_CQ_FIR_OR                                        = 0x05013032ull;


static const uint64_t P9N2_PU_INT_CQ_FIRMASK                                       = 0x05013033ull;

static const uint64_t P9N2_PU_INT_CQ_FIRMASK_AND                                   = 0x05013034ull;

static const uint64_t P9N2_PU_INT_CQ_FIRMASK_OR                                    = 0x05013035ull;


static const uint64_t P9N2_PU_INT_CQ_IC_BAR                                        = 0x05013010ull;


static const uint64_t P9N2_PU_INT_CQ_MSGSND                                        = 0x0501300Bull;


static const uint64_t P9N2_PU_INT_CQ_PBC_LIMIT                                     = 0x0501300Cull;


static const uint64_t P9N2_PU_INT_CQ_PBI_CTL                                       = 0x05013020ull;


static const uint64_t P9N2_PU_INT_CQ_PBO_CTL                                       = 0x05013021ull;


static const uint64_t P9N2_PU_INT_CQ_PC_BAR                                        = 0x05013016ull;


static const uint64_t P9N2_PU_INT_CQ_PC_BARM                                       = 0x05013017ull;


static const uint64_t P9N2_PU_INT_CQ_PGM_DBG0                                      = 0x05013000ull;


static const uint64_t P9N2_PU_INT_CQ_PGM_DBG1                                      = 0x05013001ull;


static const uint64_t P9N2_PU_INT_CQ_PMC_0                                         = 0x05013028ull;


static const uint64_t P9N2_PU_INT_CQ_PMC_1                                         = 0x05013029ull;


static const uint64_t P9N2_PU_INT_CQ_PMC_2                                         = 0x0501302Aull;


static const uint64_t P9N2_PU_INT_CQ_PMC_3                                         = 0x0501302Bull;


static const uint64_t P9N2_PU_INT_CQ_PMC_4                                         = 0x0501302Cull;


static const uint64_t P9N2_PU_INT_CQ_PMC_5                                         = 0x0501302Dull;


static const uint64_t P9N2_PU_INT_CQ_PMC_6                                         = 0x0501302Eull;


static const uint64_t P9N2_PU_INT_CQ_PMC_7                                         = 0x0501302Full;


static const uint64_t P9N2_PU_INT_CQ_PM_CTL                                        = 0x05013027ull;


static const uint64_t P9N2_PU_INT_CQ_RST_CTL                                       = 0x05013023ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_CMD1                                      = 0x05013004ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_CMD2                                      = 0x05013005ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_CMD3                                      = 0x05013006ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_CMD4                                      = 0x05013007ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_CMD5                                      = 0x05013008ull;


static const uint64_t P9N2_PU_INT_CQ_SWI_RSP                                       = 0x05013009ull;


static const uint64_t P9N2_PU_INT_CQ_TAR                                           = 0x0501301Eull;


static const uint64_t P9N2_PU_INT_CQ_TDR                                           = 0x0501301Full;


static const uint64_t P9N2_PU_INT_CQ_TM1_BAR                                       = 0x05013012ull;


static const uint64_t P9N2_PU_INT_CQ_TM2_BAR                                       = 0x05013014ull;


static const uint64_t P9N2_PU_INT_CQ_VC_BAR                                        = 0x05013018ull;


static const uint64_t P9N2_PU_INT_CQ_VC_BARM                                       = 0x05013019ull;


static const uint64_t P9N2_PU_INT_CQ_WOF                                           = 0x05013038ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE0                                     = 0x050116E0ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE1                                     = 0x050116E1ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE10                                    = 0x050116EAull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE11                                    = 0x050116EBull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE12                                    = 0x050116ECull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE13                                    = 0x050116EDull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE14                                    = 0x050116EEull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE15                                    = 0x050116EFull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE2                                     = 0x050116E2ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE3                                     = 0x050116E3ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE4                                     = 0x050116E4ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE5                                     = 0x050116E5ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE6                                     = 0x050116E6ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE7                                     = 0x050116E7ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE8                                     = 0x050116E8ull;


static const uint64_t P9N2__NTL1_INT_LOG_0_PE9                                     = 0x050116E9ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE0                                     = 0x050116F0ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE1                                     = 0x050116F1ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE10                                    = 0x050116FAull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE11                                    = 0x050116FBull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE12                                    = 0x050116FCull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE13                                    = 0x050116FDull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE14                                    = 0x050116FEull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE15                                    = 0x050116FFull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE2                                     = 0x050116F2ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE3                                     = 0x050116F3ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE4                                     = 0x050116F4ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE5                                     = 0x050116F5ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE6                                     = 0x050116F6ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE7                                     = 0x050116F7ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE8                                     = 0x050116F8ull;


static const uint64_t P9N2__NTL1_INT_LOG_1_PE9                                     = 0x050116F9ull;


static const uint64_t P9N2_PU_INT_PC_AIB_RX_CRD_CMD                                = 0x05013121ull;


static const uint64_t P9N2_PU_INT_PC_AIB_RX_CRD_DAT                                = 0x05013122ull;


static const uint64_t P9N2_PU_INT_PC_AIB_RX_CRD_INIT                               = 0x05013120ull;


static const uint64_t P9N2_PU_INT_PC_AIB_TX_CRD                                    = 0x05013124ull;


static const uint64_t P9N2_PU_INT_PC_AIB_TX_ORDER                                  = 0x05013126ull;


static const uint64_t P9N2_PU_INT_PC_AIB_TX_PRIO                                   = 0x05013125ull;


static const uint64_t P9N2_PU_INT_PC_AT_KILL                                       = 0x05013116ull;


static const uint64_t P9N2_PU_INT_PC_AT_KILL_MASK                                  = 0x05013117ull;


static const uint64_t P9N2_PU_INT_PC_DBG_ECC                                       = 0x05013131ull;


static const uint64_t P9N2_PU_INT_PC_DBG_INT                                       = 0x05013132ull;


static const uint64_t P9N2_PU_INT_PC_DBG_PMC                                       = 0x05013134ull;


static const uint64_t P9N2_PU_INT_PC_DBG_PMC_ATX0                                  = 0x05013135ull;


static const uint64_t P9N2_PU_INT_PC_DBG_PMC_ATX1                                  = 0x05013136ull;


static const uint64_t P9N2_PU_INT_PC_DBG_PMC_ATX2                                  = 0x05013137ull;


static const uint64_t P9N2_PU_INT_PC_DBG_TMOT                                      = 0x05013130ull;


static const uint64_t P9N2_PU_INT_PC_DBG_TRACE                                     = 0x05013133ull;


static const uint64_t P9N2_PU_INT_PC_EQD_BLOCK_MODE                                = 0x05013114ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_CFG0                                     = 0x05013140ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_CFG1                                     = 0x05013141ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_FATAL                                    = 0x05013144ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_INFO                                     = 0x05013146ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_RECOV                                    = 0x05013145ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_WOF                                      = 0x05013142ull;


static const uint64_t P9N2_PU_INT_PC_ERR0_WOF_DETAIL                               = 0x05013143ull;


static const uint64_t P9N2_PU_INT_PC_ERR1_CFG0                                     = 0x05013148ull;


static const uint64_t P9N2_PU_INT_PC_ERR1_CFG1                                     = 0x05013149ull;


static const uint64_t P9N2_PU_INT_PC_ERR1_FATAL                                    = 0x0501314Cull;


static const uint64_t P9N2_PU_INT_PC_ERR1_INFO                                     = 0x0501314Eull;


static const uint64_t P9N2_PU_INT_PC_ERR1_RECOV                                    = 0x0501314Dull;


static const uint64_t P9N2_PU_INT_PC_ERR1_WOF                                      = 0x0501314Aull;


static const uint64_t P9N2_PU_INT_PC_ERR1_WOF_DETAIL                               = 0x0501314Bull;


static const uint64_t P9N2_PU_INT_PC_GLOBAL_CFG                                    = 0x05013110ull;


static const uint64_t P9N2_PU_INT_PC_IVE_BLOCK_MODE                                = 0x05013113ull;


static const uint64_t P9N2_PU_INT_PC_LSI_TRIG_EOI                                  = 0x05013128ull;


static const uint64_t P9N2_PU_INT_PC_LSI_TRIG_LD                                   = 0x05013129ull;


static const uint64_t P9N2_PU_INT_PC_MMIO_ARB                                      = 0x0501311Aull;


static const uint64_t P9N2_PU_INT_PC_PCMD_ARB                                      = 0x05013118ull;


static const uint64_t P9N2_PU_INT_PC_VPC_ADDITIONAL_PERF_1                         = 0x05013174ull;


static const uint64_t P9N2_PU_INT_PC_VPC_ADDITIONAL_PERF_2                         = 0x05013175ull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_EN                                  = 0x05013161ull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA0                         = 0x05013168ull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA1                         = 0x05013169ull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA2                         = 0x0501316Aull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA3                         = 0x0501316Bull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA4                         = 0x0501316Cull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA5                         = 0x0501316Dull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA6                         = 0x0501316Eull;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_DATA7                         = 0x0501316Full;


static const uint64_t P9N2_PU_INT_PC_VPC_CACHE_WATCH_SPEC                          = 0x05013167ull;


static const uint64_t P9N2_PU_INT_PC_VPC_CONFIG                                    = 0x05013164ull;


static const uint64_t P9N2_PU_INT_PC_VPC_DEBUG                                     = 0x05013170ull;


static const uint64_t P9N2_PU_INT_PC_VPC_ERR_CFG0                                  = 0x05013178ull;


static const uint64_t P9N2_PU_INT_PC_VPC_ERR_CFG1                                  = 0x05013179ull;


static const uint64_t P9N2_PU_INT_PC_VPC_FATAL_ERR                                 = 0x0501317Cull;


static const uint64_t P9N2_PU_INT_PC_VPC_INFO_ERR                                  = 0x0501317Eull;


static const uint64_t P9N2_PU_INT_PC_VPC_MAX_OUTSTANDING_OUTB_CMD                  = 0x05013160ull;


static const uint64_t P9N2_PU_INT_PC_VPC_PERF_EVENT_SEL_1                          = 0x05013171ull;


static const uint64_t P9N2_PU_INT_PC_VPC_PERF_EVENT_SEL_2                          = 0x05013172ull;


static const uint64_t P9N2_PU_INT_PC_VPC_PERF_EVENT_SEL_3                          = 0x05013173ull;


static const uint64_t P9N2_PU_INT_PC_VPC_RECOV_ERR                                 = 0x0501317Dull;


static const uint64_t P9N2_PU_INT_PC_VPC_SCRUB_MASK                                = 0x05013163ull;


static const uint64_t P9N2_PU_INT_PC_VPC_SCRUB_TRIG                                = 0x05013162ull;


static const uint64_t P9N2_PU_INT_PC_VPC_WOF_ERR                                   = 0x0501317Aull;


static const uint64_t P9N2_PU_INT_PC_VPC_WOF_ERR_DETAIL                            = 0x0501317Bull;


static const uint64_t P9N2_PU_INT_PC_VPD_BLOCK_MODE                                = 0x05013115ull;


static const uint64_t P9N2_PU_INT_PC_VRQ_CFG                                       = 0x0501311Cull;


static const uint64_t P9N2_PU_INT_PC_VRQ_PEND_ARB                                  = 0x0501311Dull;


static const uint64_t P9N2_PU_INT_PC_VRQ_VPC_ARB                                   = 0x0501311Full;


static const uint64_t P9N2_PU_INT_PC_VRQ_VPC_CRD                                   = 0x0501311Eull;


static const uint64_t P9N2_PU_INT_PC_VSD_TABLE_ADDR                                = 0x05013111ull;


static const uint64_t P9N2_PU_INT_PC_VSD_TABLE_DATA                                = 0x05013112ull;


static const uint64_t P9N2__CTL_INT_REQ                                            = 0x05011697ull;


static const uint64_t P9N2_PU_INT_TCTXT_CFG                                        = 0x05013100ull;


static const uint64_t P9N2_PU_INT_TCTXT_EN0                                        = 0x05013108ull;


static const uint64_t P9N2_PU_INT_TCTXT_EN0_RESET                                  = 0x0501310Aull;


static const uint64_t P9N2_PU_INT_TCTXT_EN0_SET                                    = 0x05013109ull;


static const uint64_t P9N2_PU_INT_TCTXT_EN1                                        = 0x0501310Cull;


static const uint64_t P9N2_PU_INT_TCTXT_EN1_RESET                                  = 0x0501310Eull;


static const uint64_t P9N2_PU_INT_TCTXT_EN1_SET                                    = 0x0501310Dull;


static const uint64_t P9N2_PU_INT_TCTXT_INDIR0                                     = 0x05013104ull;


static const uint64_t P9N2_PU_INT_TCTXT_INDIR1                                     = 0x05013105ull;


static const uint64_t P9N2_PU_INT_TCTXT_INDIR2                                     = 0x05013106ull;


static const uint64_t P9N2_PU_INT_TCTXT_INDIR3                                     = 0x05013107ull;


static const uint64_t P9N2_PU_INT_TCTXT_TRACK                                      = 0x05013101ull;


static const uint64_t P9N2_PU_INT_VC_AIB_TIMEOUT                                   = 0x0501322Bull;


static const uint64_t P9N2_PU_INT_VC_AIB_TX_CMD_PRIORITY                           = 0x0501323Dull;


static const uint64_t P9N2_PU_INT_VC_AIB_TX_ORDERING_TAG_1                         = 0x0501322Cull;


static const uint64_t P9N2_PU_INT_VC_AIB_TX_ORDERING_TAG_2                         = 0x0501322Dull;


static const uint64_t P9N2_PU_INT_VC_ATX_INIT_CREDIT_COUNT                         = 0x0501323Cull;


static const uint64_t P9N2_PU_INT_VC_ATX_PERF_EVENT_SEL_1                          = 0x05013240ull;


static const uint64_t P9N2_PU_INT_VC_ATX_PERF_EVENT_SEL_2                          = 0x05013241ull;


static const uint64_t P9N2_PU_INT_VC_ATX_PERF_EVENT_SEL_3                          = 0x05013242ull;


static const uint64_t P9N2_PU_INT_VC_AT_MACRO_KILL                                 = 0x0501323Eull;


static const uint64_t P9N2_PU_INT_VC_AT_MACRO_KILL_MASK                            = 0x0501323Full;


static const uint64_t P9N2_PU_INT_VC_EQC_ADDITIONAL_PERF_1                         = 0x05013253ull;


static const uint64_t P9N2_PU_INT_VC_EQC_ADDITIONAL_PERF_2                         = 0x05013254ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_EN                                  = 0x05013211ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_WATCH_DATA0                         = 0x05013216ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_WATCH_DATA1                         = 0x05013217ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_WATCH_DATA2                         = 0x05013218ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_WATCH_DATA3                         = 0x05013219ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CACHE_WATCH_SPEC                          = 0x05013215ull;


static const uint64_t P9N2_PU_INT_VC_EQC_CONFIG                                    = 0x05013214ull;


static const uint64_t P9N2_PU_INT_VC_EQC_DEBUG                                     = 0x0501321Aull;


static const uint64_t P9N2_PU_INT_VC_EQC_PERF_EVENT_SEL_1                          = 0x05013250ull;


static const uint64_t P9N2_PU_INT_VC_EQC_PERF_EVENT_SEL_2                          = 0x05013251ull;


static const uint64_t P9N2_PU_INT_VC_EQC_PERF_EVENT_SEL_3                          = 0x05013252ull;


static const uint64_t P9N2_PU_INT_VC_EQC_SCRUB_MASK                                = 0x05013213ull;


static const uint64_t P9N2_PU_INT_VC_EQC_SCRUB_TRIG                                = 0x05013212ull;


static const uint64_t P9N2_PU_INT_VC_EQD_BLOCK_MODE                                = 0x05013204ull;


static const uint64_t P9N2_PU_INT_VC_ERR_CFG_G0R0                                  = 0x05013270ull;


static const uint64_t P9N2_PU_INT_VC_ERR_CFG_G0R1                                  = 0x05013271ull;


static const uint64_t P9N2_PU_INT_VC_ERR_CFG_G1R0                                  = 0x05013272ull;


static const uint64_t P9N2_PU_INT_VC_ERR_CFG_G1R1                                  = 0x05013273ull;


static const uint64_t P9N2_PU_INT_VC_FATAL_ERR_G0                                  = 0x05013278ull;


static const uint64_t P9N2_PU_INT_VC_FATAL_ERR_G1                                  = 0x0501327Bull;


static const uint64_t P9N2_PU_INT_VC_GLOBAL_CONFIG                                 = 0x05013200ull;


static const uint64_t P9N2_PU_INT_VC_INFO_ERR_G0                                   = 0x0501327Aull;


static const uint64_t P9N2_PU_INT_VC_INFO_ERR_G1                                   = 0x0501327Dull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_0                                  = 0x05013208ull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_1                                  = 0x05013209ull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_2                                  = 0x0501320Aull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_3                                  = 0x0501320Bull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_4                                  = 0x0501320Cull;


static const uint64_t P9N2_PU_INT_VC_IRQ_CONFIG_5                                  = 0x0501320Dull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_0                          = 0x05013268ull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_1                          = 0x05013269ull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_2                          = 0x0501326Aull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_3                          = 0x0501326Bull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_4                          = 0x0501326Cull;


static const uint64_t P9N2_PU_INT_VC_IRQ_PERF_EVENT_SEL_5                          = 0x0501326Dull;


static const uint64_t P9N2_PU_INT_VC_IRQ_TO_EQC_CREDITS                            = 0x0501320Eull;


static const uint64_t P9N2_PU_INT_VC_IVC_ADDITIONAL_PERF                           = 0x0501325Bull;


static const uint64_t P9N2_PU_INT_VC_IVC_CACHE_EN                                  = 0x05013221ull;


static const uint64_t P9N2_PU_INT_VC_IVC_CACHE_WATCH_ADDR                          = 0x05013225ull;


static const uint64_t P9N2_PU_INT_VC_IVC_CACHE_WATCH_DATA                          = 0x05013226ull;


static const uint64_t P9N2_PU_INT_VC_IVC_DEBUG                                     = 0x0501322Aull;


static const uint64_t P9N2_PU_INT_VC_IVC_HASH_1                                    = 0x05013227ull;


static const uint64_t P9N2_PU_INT_VC_IVC_HASH_2                                    = 0x05013228ull;


static const uint64_t P9N2_PU_INT_VC_IVC_HASH_3                                    = 0x05013229ull;


static const uint64_t P9N2_PU_INT_VC_IVC_PERF_EVENT_SEL_1                          = 0x05013258ull;


static const uint64_t P9N2_PU_INT_VC_IVC_PERF_EVENT_SEL_2                          = 0x05013259ull;


static const uint64_t P9N2_PU_INT_VC_IVC_PERF_EVENT_SEL_3                          = 0x0501325Aull;


static const uint64_t P9N2_PU_INT_VC_IVC_SCRUB_MASK                                = 0x05013223ull;


static const uint64_t P9N2_PU_INT_VC_IVC_SCRUB_TRIG                                = 0x05013222ull;


static const uint64_t P9N2_PU_INT_VC_IVE_ISB_BLOCK_MODE                            = 0x05013203ull;


static const uint64_t P9N2_PU_INT_VC_LBS6_DEBUG                                    = 0x05013206ull;


static const uint64_t P9N2_PU_INT_VC_MAX_OUTSTANDING_EQC_OUTB_CMD                  = 0x05013210ull;


static const uint64_t P9N2_PU_INT_VC_MAX_OUTSTANDING_IRQ_DMA                       = 0x0501323Bull;


static const uint64_t P9N2_PU_INT_VC_MAX_OUTSTANDING_IVC_CMD                       = 0x05013220ull;


static const uint64_t P9N2_PU_INT_VC_MAX_OUTSTANDING_SBC_CMD                       = 0x05013230ull;


static const uint64_t P9N2_PU_INT_VC_RECOV_ERR_G0                                  = 0x05013279ull;


static const uint64_t P9N2_PU_INT_VC_RECOV_ERR_G1                                  = 0x0501327Cull;


static const uint64_t P9N2_PU_INT_VC_SBC_ADDITIONAL_PERF                           = 0x05013263ull;


static const uint64_t P9N2_PU_INT_VC_SBC_CACHE_EN                                  = 0x05013231ull;


static const uint64_t P9N2_PU_INT_VC_SBC_CACHE_WATCH_ADDR                          = 0x05013235ull;


static const uint64_t P9N2_PU_INT_VC_SBC_CACHE_WATCH_DATA                          = 0x05013236ull;


static const uint64_t P9N2_PU_INT_VC_SBC_CONFIG                                    = 0x05013234ull;


static const uint64_t P9N2_PU_INT_VC_SBC_DEBUG                                     = 0x0501323Aull;


static const uint64_t P9N2_PU_INT_VC_SBC_PERF_EVENT_SEL_1                          = 0x05013260ull;


static const uint64_t P9N2_PU_INT_VC_SBC_PERF_EVENT_SEL_2                          = 0x05013261ull;


static const uint64_t P9N2_PU_INT_VC_SBC_PERF_EVENT_SEL_3                          = 0x05013262ull;


static const uint64_t P9N2_PU_INT_VC_SBC_SCRUB_MASK                                = 0x05013233ull;


static const uint64_t P9N2_PU_INT_VC_SBC_SCRUB_TRIG                                = 0x05013232ull;


static const uint64_t P9N2_PU_INT_VC_SBC_SOFTWR_ADDR                               = 0x05013237ull;


static const uint64_t P9N2_PU_INT_VC_SBC_SOFTWR_DATA                               = 0x05013239ull;


static const uint64_t P9N2_PU_INT_VC_SBC_SOFTWR_MASK                               = 0x05013238ull;


static const uint64_t P9N2_PU_INT_VC_VPS_BLOCK_MODE                                = 0x05013205ull;


static const uint64_t P9N2_PU_INT_VC_VSD_TABLE_ADDR                                = 0x05013201ull;


static const uint64_t P9N2_PU_INT_VC_VSD_TABLE_DATA                                = 0x05013202ull;


static const uint64_t P9N2_PU_INT_VC_WOF_ERR_G0                                    = 0x05013274ull;


static const uint64_t P9N2_PU_INT_VC_WOF_ERR_G0_DETAIL                             = 0x05013275ull;


static const uint64_t P9N2_PU_INT_VC_WOF_ERR_G1                                    = 0x05013276ull;


static const uint64_t P9N2_PU_INT_VC_WOF_ERR_G1_DETAIL                             = 0x05013277ull;


static const uint64_t P9N2__SM1_IODA_ADDR                                          = 0x05011621ull;


static const uint64_t P9N2__SM1_IODA_DAT0                                          = 0x05011622ull;


static const uint64_t P9N2_PU_IO_DATA_REG                                          = 0x00090030ull;


static const uint64_t P9N2_PU_IVT_OFFSET                                           = 0x05012918ull;


static const uint64_t P9N2_PU_JTG_PIB_OJCFG                                        = 0x0006D004ull;

static const uint64_t P9N2_PU_JTG_PIB_OJCFG_AND                                    = 0x0006D005ull;

static const uint64_t P9N2_PU_JTG_PIB_OJCFG_OR                                     = 0x0006D006ull;


static const uint64_t P9N2_PU_JTG_PIB_OJFRST                                       = 0x0006D007ull;


static const uint64_t P9N2_PU_JTG_PIB_OJIC_SCOM                                    = 0x0006D008ull;

static const uint64_t P9N2_PU_JTG_PIB_OJIC_SCOM1                                   = 0x0006D009ull;

static const uint64_t P9N2_PU_JTG_PIB_OJIC_SCOM2                                   = 0x0006D00Aull;


static const uint64_t P9N2_PU_JTG_PIB_OJSTAT                                       = 0x0006D00Bull;


static const uint64_t P9N2_PU_JTG_PIB_OJTDI                                        = 0x0006D00Cull;


static const uint64_t P9N2_PU_JTG_PIB_OJTDO                                        = 0x0006D00Dull;


static const uint64_t P9N2__CTL_LCO_CONFIG                                         = 0x05011682ull;


static const uint64_t P9N2_CAPP_LINK_DELAY_TIMER                                   = 0x02010845ull;

static const uint64_t P9N2_CAPP_0_LINK_DELAY_TIMER                                 = 0x02010845ull;

static const uint64_t P9N2_CAPP_1_LINK_DELAY_TIMER                                 = 0x04010845ull;


static const uint64_t P9N2_PEC_LOCAL_FIR                                           = 0x0D04000Aull;

static const uint64_t P9N2_PEC_LOCAL_FIR_AND                                       = 0x0D04000Bull;

static const uint64_t P9N2_PEC_LOCAL_FIR_OR                                        = 0x0D04000Cull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR                                         = 0x0D04000Aull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_AND                                     = 0x0D04000Bull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_OR                                      = 0x0D04000Cull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR                                         = 0x0E04000Aull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_AND                                     = 0x0E04000Bull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_OR                                      = 0x0E04000Cull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR                                         = 0x0F04000Aull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_AND                                     = 0x0F04000Bull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_OR                                      = 0x0F04000Cull;


static const uint64_t P9N2_PEC_LOCAL_FIR_ACTION0                                   = 0x0D040010ull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_ACTION0                                 = 0x0D040010ull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_ACTION0                                 = 0x0E040010ull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_ACTION0                                 = 0x0F040010ull;


static const uint64_t P9N2_PEC_LOCAL_FIR_ACTION1                                   = 0x0D040011ull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_ACTION1                                 = 0x0D040011ull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_ACTION1                                 = 0x0E040011ull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_ACTION1                                 = 0x0F040011ull;


static const uint64_t P9N2_PEC_LOCAL_FIR_MASK                                      = 0x0D04000Dull;

static const uint64_t P9N2_PEC_LOCAL_FIR_MASK_AND                                  = 0x0D04000Eull;

static const uint64_t P9N2_PEC_LOCAL_FIR_MASK_OR                                   = 0x0D04000Full;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_MASK                                    = 0x0D04000Dull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_MASK_AND                                = 0x0D04000Eull;

static const uint64_t P9N2_PEC_0_LOCAL_FIR_MASK_OR                                 = 0x0D04000Full;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_MASK                                    = 0x0E04000Dull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_MASK_AND                                = 0x0E04000Eull;

static const uint64_t P9N2_PEC_1_LOCAL_FIR_MASK_OR                                 = 0x0E04000Full;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_MASK                                    = 0x0F04000Dull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_MASK_AND                                = 0x0F04000Eull;

static const uint64_t P9N2_PEC_2_LOCAL_FIR_MASK_OR                                 = 0x0F04000Full;


static const uint64_t P9N2_PEC_LOCAL_XSTOP_ERR                                     = 0x0D040018ull;

static const uint64_t P9N2_PEC_0_LOCAL_XSTOP_ERR                                   = 0x0D040018ull;

static const uint64_t P9N2_PEC_1_LOCAL_XSTOP_ERR                                   = 0x0E040018ull;

static const uint64_t P9N2_PEC_2_LOCAL_XSTOP_ERR                                   = 0x0F040018ull;


static const uint64_t P9N2_PEC_LOCAL_XSTOP_MASK                                    = 0x0D040019ull;

static const uint64_t P9N2_PEC_0_LOCAL_XSTOP_MASK                                  = 0x0D040019ull;

static const uint64_t P9N2_PEC_1_LOCAL_XSTOP_MASK                                  = 0x0E040019ull;

static const uint64_t P9N2_PEC_2_LOCAL_XSTOP_MASK                                  = 0x0F040019ull;


static const uint64_t P9N2_PU_NPU1_SM1_LOW_PWR                                     = 0x0501112Cull;

static const uint64_t P9N2_PU_NPU1_SM2_LOW_PWR                                     = 0x0501114Cull;

static const uint64_t P9N2_PU_NPU_SM1_LOW_PWR                                      = 0x0501132Cull;

static const uint64_t P9N2_PU_NPU_SM2_LOW_PWR                                      = 0x0501134Cull;

static const uint64_t P9N2__SM1_LOW_PWR                                            = 0x0501152Cull;

static const uint64_t P9N2__SM2_LOW_PWR                                            = 0x0501154Cull;


static const uint64_t P9N2_PU_NPU0_CTL_LOW_WATER                                   = 0x05011098ull;

static const uint64_t P9N2_PU_NPU2_CTL_LOW_WATER                                   = 0x05011298ull;

static const uint64_t P9N2_PU_NPU0_SM0_LOW_WATER                                   = 0x05011008ull;

static const uint64_t P9N2_PU_NPU0_SM1_LOW_WATER                                   = 0x05011038ull;

static const uint64_t P9N2_PU_NPU0_SM3_LOW_WATER                                   = 0x05011068ull;

static const uint64_t P9N2_PU_NPU2_SM0_LOW_WATER                                   = 0x05011208ull;

static const uint64_t P9N2_PU_NPU2_SM1_LOW_WATER                                   = 0x05011238ull;

static const uint64_t P9N2_PU_NPU2_SM3_LOW_WATER                                   = 0x05011268ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_LOW_WATER                                = 0x05011498ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_LOW_WATER                                = 0x05011408ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_LOW_WATER                                = 0x05011438ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_LOW_WATER                                = 0x05011468ull;


static const uint64_t P9N2_NV_LPCTH_CONFIG                                         = 0x050110D0ull;

static const uint64_t P9N2_NV_0_LPCTH_CONFIG                                       = 0x050110D0ull;

static const uint64_t P9N2_NV_4_LPCTH_CONFIG                                       = 0x050114D0ull;

static const uint64_t P9N2_PU_NPU2_NTL0_LPCTH_CONFIG                               = 0x050112D0ull;


static const uint64_t P9N2_PU_LPC_BASE_REG                                         = 0x00090040ull;


static const uint64_t P9N2_PU_LPC_CMD_REG                                          = 0x00090041ull;


static const uint64_t P9N2_PU_LPC_DATA_REG                                         = 0x00090042ull;


static const uint64_t P9N2_PU_LPC_STATUS_REG                                       = 0x00090043ull;


static const uint64_t P9N2_PHB_MASK_REG                                            = 0x0D01090Bull;

static const uint64_t P9N2_PHB_MASK_REG_AND                                        = 0x0D01090Cull;

static const uint64_t P9N2_PHB_MASK_REG_OR                                         = 0x0D01090Dull;

static const uint64_t P9N2_PHB_0_MASK_REG                                          = 0x0D01090Bull;

static const uint64_t P9N2_PHB_0_MASK_REG_AND                                      = 0x0D01090Cull;

static const uint64_t P9N2_PHB_0_MASK_REG_OR                                       = 0x0D01090Dull;

static const uint64_t P9N2_PHB_1_MASK_REG                                          = 0x0E01090Bull;

static const uint64_t P9N2_PHB_1_MASK_REG_AND                                      = 0x0E01090Cull;

static const uint64_t P9N2_PHB_1_MASK_REG_OR                                       = 0x0E01090Dull;

static const uint64_t P9N2_PHB_2_MASK_REG                                          = 0x0E01094Bull;

static const uint64_t P9N2_PHB_2_MASK_REG_AND                                      = 0x0E01094Cull;

static const uint64_t P9N2_PHB_2_MASK_REG_OR                                       = 0x0E01094Dull;

static const uint64_t P9N2_PHB_3_MASK_REG                                          = 0x0F01090Bull;

static const uint64_t P9N2_PHB_3_MASK_REG_AND                                      = 0x0F01090Cull;

static const uint64_t P9N2_PHB_3_MASK_REG_OR                                       = 0x0F01090Dull;

static const uint64_t P9N2_PHB_4_MASK_REG                                          = 0x0F01094Bull;

static const uint64_t P9N2_PHB_4_MASK_REG_AND                                      = 0x0F01094Cull;

static const uint64_t P9N2_PHB_4_MASK_REG_OR                                       = 0x0F01094Dull;

static const uint64_t P9N2_PHB_5_MASK_REG                                          = 0x0F01098Bull;

static const uint64_t P9N2_PHB_5_MASK_REG_AND                                      = 0x0F01098Cull;

static const uint64_t P9N2_PHB_5_MASK_REG_OR                                       = 0x0F01098Dull;


static const uint64_t P9N2_PU_MCC_FIR_REG                                          = 0x03011400ull;

static const uint64_t P9N2_PU_MCC_FIR_REG_AND                                      = 0x03011401ull;

static const uint64_t P9N2_PU_MCC_FIR_REG_OR                                       = 0x03011402ull;

static const uint64_t P9N2_PU_MCD1_MCC_FIR_REG                                     = 0x03011000ull;

static const uint64_t P9N2_PU_MCD1_MCC_FIR_REG_AND                                 = 0x03011001ull;

static const uint64_t P9N2_PU_MCD1_MCC_FIR_REG_OR                                  = 0x03011002ull;


static const uint64_t P9N2_PU_MCD_DBG                                              = 0x03011413ull;

static const uint64_t P9N2_PU_MCD1_MCD_DBG                                         = 0x03011013ull;


static const uint64_t P9N2_PU_MCD_ECAP                                             = 0x03011412ull;

static const uint64_t P9N2_PU_MCD1_MCD_ECAP                                        = 0x03011012ull;


static const uint64_t P9N2_PU_MCD_FIR_ACTION0_REG                                  = 0x03011406ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_ACTION0_REG                             = 0x03011006ull;


static const uint64_t P9N2_PU_MCD_FIR_ACTION1_REG                                  = 0x03011407ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_ACTION1_REG                             = 0x03011007ull;


static const uint64_t P9N2_PU_MCD_FIR_MASK_REG                                     = 0x03011403ull;

static const uint64_t P9N2_PU_MCD_FIR_MASK_REG_AND                                 = 0x03011404ull;

static const uint64_t P9N2_PU_MCD_FIR_MASK_REG_OR                                  = 0x03011405ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_MASK_REG                                = 0x03011003ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_MASK_REG_AND                            = 0x03011004ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_MASK_REG_OR                             = 0x03011005ull;


static const uint64_t P9N2_PU_MCD_FIR_WOF_REG                                      = 0x03011408ull;

static const uint64_t P9N2_PU_MCD1_MCD_FIR_WOF_REG                                 = 0x03011008ull;


static const uint64_t P9N2_PU_MIB_XIICAC                                           = 0x000E0009ull;
//DUPS: 05012419, 09011059, 0C011059,

static const uint64_t P9N2_PU_MIB_XIMEM                                            = 0x000E0007ull;
//DUPS: 05012417, 09011057, 0C011057,

static const uint64_t P9N2_PU_MIB_XISGB                                            = 0x000E0008ull;
//DUPS: 05012418, 09011058, 0C011058,

static const uint64_t P9N2_PU_MIB_XISIB                                            = 0x000E0006ull;


static const uint64_t P9N2__CTL_MISC_CONFIG                                        = 0x05011686ull;


static const uint64_t P9N2__CTL_MISC_HOLD                                          = 0x05011684ull;


static const uint64_t P9N2__CTL_MISC_MASK                                          = 0x05011685ull;


static const uint64_t P9N2_PU_NMMU_MMCQ_PB_MODE_REG                                = 0x05012C15ull;


static const uint64_t P9N2_PEC_0_STACK0_MMIOBAR0_MASK_REG                          = 0x04010C4Full;

static const uint64_t P9N2_PEC_1_STACK0_MMIOBAR0_MASK_REG                          = 0x0401104Full;

static const uint64_t P9N2_PEC_1_STACK1_MMIOBAR0_MASK_REG                          = 0x0401108Full;

static const uint64_t P9N2_PEC_1_STACK2_MMIOBAR0_MASK_REG                          = 0x040110CFull;

static const uint64_t P9N2_PEC_2_STACK0_MMIOBAR0_MASK_REG                          = 0x0401144Full;

static const uint64_t P9N2_PEC_2_STACK1_MMIOBAR0_MASK_REG                          = 0x0401148Full;

static const uint64_t P9N2_PEC_2_STACK2_MMIOBAR0_MASK_REG                          = 0x040114CFull;

static const uint64_t P9N2_PEC_STACK0_MMIOBAR0_MASK_REG                            = 0x04010C4Full;

static const uint64_t P9N2_PHB_MMIOBAR0_MASK_REG                                   = 0x04010C4Full;

static const uint64_t P9N2_PHB_0_MMIOBAR0_MASK_REG                                 = 0x04010C4Full;

static const uint64_t P9N2_PHB_1_MMIOBAR0_MASK_REG                                 = 0x0401104Full;

static const uint64_t P9N2_PHB_2_MMIOBAR0_MASK_REG                                 = 0x0401108Full;

static const uint64_t P9N2_PHB_3_MMIOBAR0_MASK_REG                                 = 0x0401144Full;

static const uint64_t P9N2_PHB_4_MMIOBAR0_MASK_REG                                 = 0x0401148Full;

static const uint64_t P9N2_PHB_5_MMIOBAR0_MASK_REG                                 = 0x040114CFull;


static const uint64_t P9N2_PEC_0_STACK0_MMIOBAR0_REG                               = 0x04010C4Eull;

static const uint64_t P9N2_PEC_1_STACK0_MMIOBAR0_REG                               = 0x0401104Eull;

static const uint64_t P9N2_PEC_1_STACK1_MMIOBAR0_REG                               = 0x0401108Eull;

static const uint64_t P9N2_PEC_1_STACK2_MMIOBAR0_REG                               = 0x040110CEull;

static const uint64_t P9N2_PEC_2_STACK0_MMIOBAR0_REG                               = 0x0401144Eull;

static const uint64_t P9N2_PEC_2_STACK1_MMIOBAR0_REG                               = 0x0401148Eull;

static const uint64_t P9N2_PEC_2_STACK2_MMIOBAR0_REG                               = 0x040114CEull;

static const uint64_t P9N2_PEC_STACK0_MMIOBAR0_REG                                 = 0x04010C4Eull;

static const uint64_t P9N2_PHB_MMIOBAR0_REG                                        = 0x04010C4Eull;

static const uint64_t P9N2_PHB_0_MMIOBAR0_REG                                      = 0x04010C4Eull;

static const uint64_t P9N2_PHB_1_MMIOBAR0_REG                                      = 0x0401104Eull;

static const uint64_t P9N2_PHB_2_MMIOBAR0_REG                                      = 0x0401108Eull;

static const uint64_t P9N2_PHB_3_MMIOBAR0_REG                                      = 0x0401144Eull;

static const uint64_t P9N2_PHB_4_MMIOBAR0_REG                                      = 0x0401148Eull;

static const uint64_t P9N2_PHB_5_MMIOBAR0_REG                                      = 0x040114CEull;


static const uint64_t P9N2_PEC_0_STACK0_MMIOBAR1_MASK_REG                          = 0x04010C51ull;

static const uint64_t P9N2_PEC_1_STACK0_MMIOBAR1_MASK_REG                          = 0x04011051ull;

static const uint64_t P9N2_PEC_1_STACK1_MMIOBAR1_MASK_REG                          = 0x04011091ull;

static const uint64_t P9N2_PEC_1_STACK2_MMIOBAR1_MASK_REG                          = 0x040110D1ull;

static const uint64_t P9N2_PEC_2_STACK0_MMIOBAR1_MASK_REG                          = 0x04011451ull;

static const uint64_t P9N2_PEC_2_STACK1_MMIOBAR1_MASK_REG                          = 0x04011491ull;

static const uint64_t P9N2_PEC_2_STACK2_MMIOBAR1_MASK_REG                          = 0x040114D1ull;

static const uint64_t P9N2_PEC_STACK0_MMIOBAR1_MASK_REG                            = 0x04010C51ull;

static const uint64_t P9N2_PHB_MMIOBAR1_MASK_REG                                   = 0x04010C51ull;

static const uint64_t P9N2_PHB_0_MMIOBAR1_MASK_REG                                 = 0x04010C51ull;

static const uint64_t P9N2_PHB_1_MMIOBAR1_MASK_REG                                 = 0x04011051ull;

static const uint64_t P9N2_PHB_2_MMIOBAR1_MASK_REG                                 = 0x04011091ull;

static const uint64_t P9N2_PHB_3_MMIOBAR1_MASK_REG                                 = 0x04011451ull;

static const uint64_t P9N2_PHB_4_MMIOBAR1_MASK_REG                                 = 0x04011491ull;

static const uint64_t P9N2_PHB_5_MMIOBAR1_MASK_REG                                 = 0x040114D1ull;


static const uint64_t P9N2_PEC_0_STACK0_MMIOBAR1_REG                               = 0x04010C50ull;

static const uint64_t P9N2_PEC_1_STACK0_MMIOBAR1_REG                               = 0x04011050ull;

static const uint64_t P9N2_PEC_1_STACK1_MMIOBAR1_REG                               = 0x04011090ull;

static const uint64_t P9N2_PEC_1_STACK2_MMIOBAR1_REG                               = 0x040110D0ull;

static const uint64_t P9N2_PEC_2_STACK0_MMIOBAR1_REG                               = 0x04011450ull;

static const uint64_t P9N2_PEC_2_STACK1_MMIOBAR1_REG                               = 0x04011490ull;

static const uint64_t P9N2_PEC_2_STACK2_MMIOBAR1_REG                               = 0x040114D0ull;

static const uint64_t P9N2_PEC_STACK0_MMIOBAR1_REG                                 = 0x04010C50ull;

static const uint64_t P9N2_PHB_MMIOBAR1_REG                                        = 0x04010C50ull;

static const uint64_t P9N2_PHB_0_MMIOBAR1_REG                                      = 0x04010C50ull;

static const uint64_t P9N2_PHB_1_MMIOBAR1_REG                                      = 0x04011050ull;

static const uint64_t P9N2_PHB_2_MMIOBAR1_REG                                      = 0x04011090ull;

static const uint64_t P9N2_PHB_3_MMIOBAR1_REG                                      = 0x04011450ull;

static const uint64_t P9N2_PHB_4_MMIOBAR1_REG                                      = 0x04011490ull;

static const uint64_t P9N2_PHB_5_MMIOBAR1_REG                                      = 0x040114D0ull;


static const uint64_t P9N2_NV_MMIOPA0_CONFIG                                       = 0x050110D6ull;

static const uint64_t P9N2_NV_0_MMIOPA0_CONFIG                                     = 0x050110D6ull;

static const uint64_t P9N2_NV_4_MMIOPA0_CONFIG                                     = 0x050114D6ull;

static const uint64_t P9N2_PU_NPU2_NTL0_MMIOPA0_CONFIG                             = 0x050112D6ull;


static const uint64_t P9N2_NV_MMIOPA1_CONFIG                                       = 0x050110D7ull;

static const uint64_t P9N2_NV_0_MMIOPA1_CONFIG                                     = 0x050110D7ull;

static const uint64_t P9N2_NV_4_MMIOPA1_CONFIG                                     = 0x050114D7ull;

static const uint64_t P9N2_PU_NPU2_NTL0_MMIOPA1_CONFIG                             = 0x050112D7ull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_CTL_MISC                            = 0x05012C53ull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_CTL_SLB                             = 0x05012C54ull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_CTL_SM                              = 0x05012C52ull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_CTL_TLB                             = 0x05012C55ull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG0                       = 0x05012C4Aull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG1                       = 0x05012C4Bull;


static const uint64_t P9N2_PU_NMMU_MM_CFG_NMMU_XLAT_CTL_REG2                       = 0x05012C4Cull;


static const uint64_t P9N2_PU_NMMU_MM_EPSILON_COUNTER_VALUE                        = 0x05012C1Dull;


static const uint64_t P9N2_PU_NMMU_MM_FIR1_ACTION0_REG                             = 0x05012C46ull;


static const uint64_t P9N2_PU_NMMU_MM_FIR1_ACTION1_REG                             = 0x05012C47ull;


static const uint64_t P9N2_PU_NMMU_MM_FIR1_MASK_REG                                = 0x05012C43ull;

static const uint64_t P9N2_PU_NMMU_MM_FIR1_MASK_REG_AND                            = 0x05012C44ull;

static const uint64_t P9N2_PU_NMMU_MM_FIR1_MASK_REG_OR                             = 0x05012C45ull;


static const uint64_t P9N2_PU_NMMU_MM_FIR1_REG                                     = 0x05012C40ull;

static const uint64_t P9N2_PU_NMMU_MM_FIR1_REG_AND                                 = 0x05012C41ull;

static const uint64_t P9N2_PU_NMMU_MM_FIR1_REG_OR                                  = 0x05012C42ull;


static const uint64_t P9N2_PU_NMMU_MM_FIR1_WOF_REG                                 = 0x05012C48ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_DBG_MODE                                = 0x05012C59ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_ERR_INJ                                 = 0x05012C58ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_ERR_LOG                                 = 0x05012C57ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_FLT_STAT_REG                            = 0x05012C51ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_PMU0_CNT_REG                            = 0x05012C4Full;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_PMU0_CTL_REG                            = 0x05012C4Dull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_PMU1_CNT_REG                            = 0x05012C50ull;


static const uint64_t P9N2_PU_NMMU_MM_NMMU_PMU1_CTL_REG                            = 0x05012C4Eull;


static const uint64_t P9N2_PEC_MODE_REG                                            = 0x0D040008ull;

static const uint64_t P9N2_PEC_0_MODE_REG                                          = 0x0D040008ull;

static const uint64_t P9N2_PEC_1_MODE_REG                                          = 0x0E040008ull;

static const uint64_t P9N2_PEC_2_MODE_REG                                          = 0x0F040008ull;


static const uint64_t P9N2_PU_MODE_REGISTER                                        = 0x00010008ull;


static const uint64_t P9N2_PU_MODE_REGISTER_B                                      = 0x000A0006ull;


static const uint64_t P9N2_PU_MODE_REGISTER_C                                      = 0x000A1006ull;


static const uint64_t P9N2_PU_MODE_REGISTER_D                                      = 0x000A2006ull;


static const uint64_t P9N2_PU_MODE_REGISTER_E                                      = 0x000A3006ull;


static const uint64_t P9N2_PEC_MULTICAST_GROUP_1                                   = 0x0D0F0001ull;

static const uint64_t P9N2_PEC_0_MULTICAST_GROUP_1                                 = 0x0D0F0001ull;

static const uint64_t P9N2_PEC_1_MULTICAST_GROUP_1                                 = 0x0E0F0001ull;

static const uint64_t P9N2_PEC_2_MULTICAST_GROUP_1                                 = 0x0F0F0001ull;


static const uint64_t P9N2_PEC_MULTICAST_GROUP_2                                   = 0x0D0F0002ull;

static const uint64_t P9N2_PEC_0_MULTICAST_GROUP_2                                 = 0x0D0F0002ull;

static const uint64_t P9N2_PEC_1_MULTICAST_GROUP_2                                 = 0x0E0F0002ull;

static const uint64_t P9N2_PEC_2_MULTICAST_GROUP_2                                 = 0x0F0F0002ull;


static const uint64_t P9N2_PEC_MULTICAST_GROUP_3                                   = 0x0D0F0003ull;

static const uint64_t P9N2_PEC_0_MULTICAST_GROUP_3                                 = 0x0D0F0003ull;

static const uint64_t P9N2_PEC_1_MULTICAST_GROUP_3                                 = 0x0E0F0003ull;

static const uint64_t P9N2_PEC_2_MULTICAST_GROUP_3                                 = 0x0F0F0003ull;


static const uint64_t P9N2_PEC_MULTICAST_GROUP_4                                   = 0x0D0F0004ull;

static const uint64_t P9N2_PEC_0_MULTICAST_GROUP_4                                 = 0x0D0F0004ull;

static const uint64_t P9N2_PEC_1_MULTICAST_GROUP_4                                 = 0x0E0F0004ull;

static const uint64_t P9N2_PEC_2_MULTICAST_GROUP_4                                 = 0x0F0F0004ull;


static const uint64_t P9N2_PU_NPU0_CTL_NDT0_BAR                                    = 0x0501109Dull;

static const uint64_t P9N2_PU_NPU2_CTL_NDT0_BAR                                    = 0x0501129Dull;

static const uint64_t P9N2_PU_NPU0_SM0_NDT0_BAR                                    = 0x0501100Dull;

static const uint64_t P9N2_PU_NPU0_SM1_NDT0_BAR                                    = 0x0501103Dull;

static const uint64_t P9N2_PU_NPU0_SM3_NDT0_BAR                                    = 0x0501106Dull;

static const uint64_t P9N2_PU_NPU2_SM0_NDT0_BAR                                    = 0x0501120Dull;

static const uint64_t P9N2_PU_NPU2_SM1_NDT0_BAR                                    = 0x0501123Dull;

static const uint64_t P9N2_PU_NPU2_SM3_NDT0_BAR                                    = 0x0501126Dull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_NDT0_BAR                                 = 0x0501149Dull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_NDT0_BAR                                 = 0x0501140Dull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_NDT0_BAR                                 = 0x0501143Dull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_NDT0_BAR                                 = 0x0501146Dull;


static const uint64_t P9N2_PU_NPU0_CTL_NDT1_BAR                                    = 0x0501109Eull;

static const uint64_t P9N2_PU_NPU2_CTL_NDT1_BAR                                    = 0x0501129Eull;

static const uint64_t P9N2_PU_NPU0_SM0_NDT1_BAR                                    = 0x0501100Eull;

static const uint64_t P9N2_PU_NPU0_SM1_NDT1_BAR                                    = 0x0501103Eull;

static const uint64_t P9N2_PU_NPU0_SM3_NDT1_BAR                                    = 0x0501106Eull;

static const uint64_t P9N2_PU_NPU2_SM0_NDT1_BAR                                    = 0x0501120Eull;

static const uint64_t P9N2_PU_NPU2_SM1_NDT1_BAR                                    = 0x0501123Eull;

static const uint64_t P9N2_PU_NPU2_SM3_NDT1_BAR                                    = 0x0501126Eull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_NDT1_BAR                                 = 0x0501149Eull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_NDT1_BAR                                 = 0x0501140Eull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_NDT1_BAR                                 = 0x0501143Eull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_NDT1_BAR                                 = 0x0501146Eull;


static const uint64_t P9N2_PEC_NESTTRC_REG                                         = 0x04010C03ull;

static const uint64_t P9N2_PEC_0_NESTTRC_REG                                       = 0x04010C03ull;

static const uint64_t P9N2_PEC_1_NESTTRC_REG                                       = 0x04011003ull;

static const uint64_t P9N2_PEC_2_NESTTRC_REG                                       = 0x04011403ull;


static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL0                                  = 0x0D0F0040ull;

static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL0_WAND                             = 0x0D0F0041ull;

static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL0_WOR                              = 0x0D0F0042ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL0                                  = 0x0E0F0040ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL0_WAND                             = 0x0E0F0041ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL0_WOR                              = 0x0E0F0042ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL0                                  = 0x0F0F0040ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL0_WAND                             = 0x0F0F0041ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL0_WOR                              = 0x0F0F0042ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL0                                    = 0x0D0F0040ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL0_WAND                               = 0x0D0F0041ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL0_WOR                                = 0x0D0F0042ull;


static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL1                                  = 0x0D0F0044ull;

static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL1_WAND                             = 0x0D0F0045ull;

static const uint64_t P9N2_PEC_0_STACK0_NET_CTRL1_WOR                              = 0x0D0F0046ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL1                                  = 0x0E0F0044ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL1_WAND                             = 0x0E0F0045ull;

static const uint64_t P9N2_PEC_1_STACK0_NET_CTRL1_WOR                              = 0x0E0F0046ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL1                                  = 0x0F0F0044ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL1_WAND                             = 0x0F0F0045ull;

static const uint64_t P9N2_PEC_2_STACK0_NET_CTRL1_WOR                              = 0x0F0F0046ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL1                                    = 0x0D0F0044ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL1_WAND                               = 0x0D0F0045ull;

static const uint64_t P9N2_PEC_STACK0_NET_CTRL1_WOR                                = 0x0D0F0046ull;


static const uint64_t P9N2_PEC_0_STACK0_NFIRACTION0_REG                            = 0x04010C46ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRACTION0_REG                            = 0x04011046ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRACTION0_REG                            = 0x04011086ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRACTION0_REG                            = 0x040110C6ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRACTION0_REG                            = 0x04011446ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRACTION0_REG                            = 0x04011486ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRACTION0_REG                            = 0x040114C6ull;

static const uint64_t P9N2_PEC_STACK0_NFIRACTION0_REG                              = 0x04010C46ull;

static const uint64_t P9N2_PHB_NFIRACTION0_REG                                     = 0x04010C46ull;

static const uint64_t P9N2_PHB_0_NFIRACTION0_REG                                   = 0x04010C46ull;

static const uint64_t P9N2_PHB_1_NFIRACTION0_REG                                   = 0x04011046ull;

static const uint64_t P9N2_PHB_2_NFIRACTION0_REG                                   = 0x04011086ull;

static const uint64_t P9N2_PHB_3_NFIRACTION0_REG                                   = 0x04011446ull;

static const uint64_t P9N2_PHB_4_NFIRACTION0_REG                                   = 0x04011486ull;

static const uint64_t P9N2_PHB_5_NFIRACTION0_REG                                   = 0x040114C6ull;


static const uint64_t P9N2_PEC_0_STACK0_NFIRACTION1_REG                            = 0x04010C47ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRACTION1_REG                            = 0x04011047ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRACTION1_REG                            = 0x04011087ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRACTION1_REG                            = 0x040110C7ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRACTION1_REG                            = 0x04011447ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRACTION1_REG                            = 0x04011487ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRACTION1_REG                            = 0x040114C7ull;

static const uint64_t P9N2_PEC_STACK0_NFIRACTION1_REG                              = 0x04010C47ull;

static const uint64_t P9N2_PHB_NFIRACTION1_REG                                     = 0x04010C47ull;

static const uint64_t P9N2_PHB_0_NFIRACTION1_REG                                   = 0x04010C47ull;

static const uint64_t P9N2_PHB_1_NFIRACTION1_REG                                   = 0x04011047ull;

static const uint64_t P9N2_PHB_2_NFIRACTION1_REG                                   = 0x04011087ull;

static const uint64_t P9N2_PHB_3_NFIRACTION1_REG                                   = 0x04011447ull;

static const uint64_t P9N2_PHB_4_NFIRACTION1_REG                                   = 0x04011487ull;

static const uint64_t P9N2_PHB_5_NFIRACTION1_REG                                   = 0x040114C7ull;


static const uint64_t P9N2_PEC_0_STACK0_NFIRMASK_REG                               = 0x04010C43ull;

static const uint64_t P9N2_PEC_0_STACK0_NFIRMASK_REG_AND                           = 0x04010C44ull;

static const uint64_t P9N2_PEC_0_STACK0_NFIRMASK_REG_OR                            = 0x04010C45ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRMASK_REG                               = 0x04011043ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRMASK_REG_AND                           = 0x04011044ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRMASK_REG_OR                            = 0x04011045ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRMASK_REG                               = 0x04011083ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRMASK_REG_AND                           = 0x04011084ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRMASK_REG_OR                            = 0x04011085ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRMASK_REG                               = 0x040110C3ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRMASK_REG_AND                           = 0x040110C4ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRMASK_REG_OR                            = 0x040110C5ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRMASK_REG                               = 0x04011443ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRMASK_REG_AND                           = 0x04011444ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRMASK_REG_OR                            = 0x04011445ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRMASK_REG                               = 0x04011483ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRMASK_REG_AND                           = 0x04011484ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRMASK_REG_OR                            = 0x04011485ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRMASK_REG                               = 0x040114C3ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRMASK_REG_AND                           = 0x040114C4ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRMASK_REG_OR                            = 0x040114C5ull;

static const uint64_t P9N2_PEC_STACK0_NFIRMASK_REG                                 = 0x04010C43ull;

static const uint64_t P9N2_PEC_STACK0_NFIRMASK_REG_AND                             = 0x04010C44ull;

static const uint64_t P9N2_PEC_STACK0_NFIRMASK_REG_OR                              = 0x04010C45ull;

static const uint64_t P9N2_PHB_NFIRMASK_REG                                        = 0x04010C43ull;

static const uint64_t P9N2_PHB_NFIRMASK_REG_AND                                    = 0x04010C44ull;

static const uint64_t P9N2_PHB_NFIRMASK_REG_OR                                     = 0x04010C45ull;

static const uint64_t P9N2_PHB_0_NFIRMASK_REG                                      = 0x04010C43ull;

static const uint64_t P9N2_PHB_0_NFIRMASK_REG_AND                                  = 0x04010C44ull;

static const uint64_t P9N2_PHB_0_NFIRMASK_REG_OR                                   = 0x04010C45ull;

static const uint64_t P9N2_PHB_1_NFIRMASK_REG                                      = 0x04011043ull;

static const uint64_t P9N2_PHB_1_NFIRMASK_REG_AND                                  = 0x04011044ull;

static const uint64_t P9N2_PHB_1_NFIRMASK_REG_OR                                   = 0x04011045ull;

static const uint64_t P9N2_PHB_2_NFIRMASK_REG                                      = 0x04011083ull;

static const uint64_t P9N2_PHB_2_NFIRMASK_REG_AND                                  = 0x04011084ull;

static const uint64_t P9N2_PHB_2_NFIRMASK_REG_OR                                   = 0x04011085ull;

static const uint64_t P9N2_PHB_3_NFIRMASK_REG                                      = 0x04011443ull;

static const uint64_t P9N2_PHB_3_NFIRMASK_REG_AND                                  = 0x04011444ull;

static const uint64_t P9N2_PHB_3_NFIRMASK_REG_OR                                   = 0x04011445ull;

static const uint64_t P9N2_PHB_4_NFIRMASK_REG                                      = 0x04011483ull;

static const uint64_t P9N2_PHB_4_NFIRMASK_REG_AND                                  = 0x04011484ull;

static const uint64_t P9N2_PHB_4_NFIRMASK_REG_OR                                   = 0x04011485ull;

static const uint64_t P9N2_PHB_5_NFIRMASK_REG                                      = 0x040114C3ull;

static const uint64_t P9N2_PHB_5_NFIRMASK_REG_AND                                  = 0x040114C4ull;

static const uint64_t P9N2_PHB_5_NFIRMASK_REG_OR                                   = 0x040114C5ull;


static const uint64_t P9N2_PEC_0_STACK0_NFIRWOF_REG                                = 0x04010C48ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIRWOF_REG                                = 0x04011048ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIRWOF_REG                                = 0x04011088ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIRWOF_REG                                = 0x040110C8ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIRWOF_REG                                = 0x04011448ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIRWOF_REG                                = 0x04011488ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIRWOF_REG                                = 0x040114C8ull;

static const uint64_t P9N2_PEC_STACK0_NFIRWOF_REG                                  = 0x04010C48ull;

static const uint64_t P9N2_PHB_NFIRWOF_REG                                         = 0x04010C48ull;

static const uint64_t P9N2_PHB_0_NFIRWOF_REG                                       = 0x04010C48ull;

static const uint64_t P9N2_PHB_1_NFIRWOF_REG                                       = 0x04011048ull;

static const uint64_t P9N2_PHB_2_NFIRWOF_REG                                       = 0x04011088ull;

static const uint64_t P9N2_PHB_3_NFIRWOF_REG                                       = 0x04011448ull;

static const uint64_t P9N2_PHB_4_NFIRWOF_REG                                       = 0x04011488ull;

static const uint64_t P9N2_PHB_5_NFIRWOF_REG                                       = 0x040114C8ull;


static const uint64_t P9N2_PEC_0_STACK0_NFIR_REG                                   = 0x04010C40ull;

static const uint64_t P9N2_PEC_0_STACK0_NFIR_REG_AND                               = 0x04010C41ull;

static const uint64_t P9N2_PEC_0_STACK0_NFIR_REG_OR                                = 0x04010C42ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIR_REG                                   = 0x04011040ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIR_REG_AND                               = 0x04011041ull;

static const uint64_t P9N2_PEC_1_STACK0_NFIR_REG_OR                                = 0x04011042ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIR_REG                                   = 0x04011080ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIR_REG_AND                               = 0x04011081ull;

static const uint64_t P9N2_PEC_1_STACK1_NFIR_REG_OR                                = 0x04011082ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIR_REG                                   = 0x040110C0ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIR_REG_AND                               = 0x040110C1ull;

static const uint64_t P9N2_PEC_1_STACK2_NFIR_REG_OR                                = 0x040110C2ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIR_REG                                   = 0x04011440ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIR_REG_AND                               = 0x04011441ull;

static const uint64_t P9N2_PEC_2_STACK0_NFIR_REG_OR                                = 0x04011442ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIR_REG                                   = 0x04011480ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIR_REG_AND                               = 0x04011481ull;

static const uint64_t P9N2_PEC_2_STACK1_NFIR_REG_OR                                = 0x04011482ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIR_REG                                   = 0x040114C0ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIR_REG_AND                               = 0x040114C1ull;

static const uint64_t P9N2_PEC_2_STACK2_NFIR_REG_OR                                = 0x040114C2ull;

static const uint64_t P9N2_PEC_STACK0_NFIR_REG                                     = 0x04010C40ull;

static const uint64_t P9N2_PEC_STACK0_NFIR_REG_AND                                 = 0x04010C41ull;

static const uint64_t P9N2_PEC_STACK0_NFIR_REG_OR                                  = 0x04010C42ull;

static const uint64_t P9N2_PHB_NFIR_REG                                            = 0x04010C40ull;

static const uint64_t P9N2_PHB_NFIR_REG_AND                                        = 0x04010C41ull;

static const uint64_t P9N2_PHB_NFIR_REG_OR                                         = 0x04010C42ull;

static const uint64_t P9N2_PHB_0_NFIR_REG                                          = 0x04010C40ull;

static const uint64_t P9N2_PHB_0_NFIR_REG_AND                                      = 0x04010C41ull;

static const uint64_t P9N2_PHB_0_NFIR_REG_OR                                       = 0x04010C42ull;

static const uint64_t P9N2_PHB_1_NFIR_REG                                          = 0x04011040ull;

static const uint64_t P9N2_PHB_1_NFIR_REG_AND                                      = 0x04011041ull;

static const uint64_t P9N2_PHB_1_NFIR_REG_OR                                       = 0x04011042ull;

static const uint64_t P9N2_PHB_2_NFIR_REG                                          = 0x04011080ull;

static const uint64_t P9N2_PHB_2_NFIR_REG_AND                                      = 0x04011081ull;

static const uint64_t P9N2_PHB_2_NFIR_REG_OR                                       = 0x04011082ull;

static const uint64_t P9N2_PHB_3_NFIR_REG                                          = 0x04011440ull;

static const uint64_t P9N2_PHB_3_NFIR_REG_AND                                      = 0x04011441ull;

static const uint64_t P9N2_PHB_3_NFIR_REG_OR                                       = 0x04011442ull;

static const uint64_t P9N2_PHB_4_NFIR_REG                                          = 0x04011480ull;

static const uint64_t P9N2_PHB_4_NFIR_REG_AND                                      = 0x04011481ull;

static const uint64_t P9N2_PHB_4_NFIR_REG_OR                                       = 0x04011482ull;

static const uint64_t P9N2_PHB_5_NFIR_REG                                          = 0x040114C0ull;

static const uint64_t P9N2_PHB_5_NFIR_REG_AND                                      = 0x040114C1ull;

static const uint64_t P9N2_PHB_5_NFIR_REG_OR                                       = 0x040114C2ull;


static const uint64_t P9N2_PU_NOTRUST_BAR0                                         = 0x05012B40ull;


static const uint64_t P9N2_PU_NOTRUST_BAR0MASK                                     = 0x05012B42ull;


static const uint64_t P9N2_PU_NOTRUST_BAR1                                         = 0x05012B41ull;


static const uint64_t P9N2_PU_NOTRUST_BAR1MASK                                     = 0x05012B43ull;


static const uint64_t P9N2__SM0_NPU_ATS_DEBUG                                      = 0x05011603ull;


static const uint64_t P9N2__SM0_NPU_AT_ECC                                         = 0x05011602ull;


static const uint64_t P9N2__SM1_NPU_AT_ESMR                                        = 0x05011628ull;


static const uint64_t P9N2__SM1_NPU_AT_ESR                                         = 0x05011627ull;


static const uint64_t P9N2__SM1_NPU_AT_FESMR                                       = 0x0501162Aull;


static const uint64_t P9N2__SM1_NPU_AT_FESR                                        = 0x05011629ull;


static const uint64_t P9N2__SM0_NPU_AT_PMU_CNT                                     = 0x05011601ull;


static const uint64_t P9N2__SM0_NPU_AT_PMU_CTRL                                    = 0x05011600ull;


static const uint64_t P9N2__SM1_NPU_Q_DMA_R                                        = 0x05011625ull;


static const uint64_t P9N2__CTL_NPU_VERSION                                        = 0x05011690ull;


static const uint64_t P9N2_PEC_NRDSTKOVR_REG                                       = 0x04010C08ull;

static const uint64_t P9N2_PEC_0_NRDSTKOVR_REG                                     = 0x04010C08ull;

static const uint64_t P9N2_PEC_1_NRDSTKOVR_REG                                     = 0x04011008ull;

static const uint64_t P9N2_PEC_2_NRDSTKOVR_REG                                     = 0x04011408ull;


static const uint64_t P9N2_PEC_NSTQSTKOVR_REG                                      = 0x04010C0Aull;

static const uint64_t P9N2_PEC_0_NSTQSTKOVR_REG                                    = 0x04010C0Aull;

static const uint64_t P9N2_PEC_1_NSTQSTKOVR_REG                                    = 0x0401100Aull;

static const uint64_t P9N2_PEC_2_NSTQSTKOVR_REG                                    = 0x0401140Aull;


static const uint64_t P9N2_PEC_NWRSTKOVR_REG                                       = 0x04010C09ull;

static const uint64_t P9N2_PEC_0_NWRSTKOVR_REG                                     = 0x04010C09ull;

static const uint64_t P9N2_PEC_1_NWRSTKOVR_REG                                     = 0x04011009ull;

static const uint64_t P9N2_PEC_2_NWRSTKOVR_REG                                     = 0x04011409ull;


static const uint64_t P9N2_PU_NXCQ_PB_MODE_REG                                     = 0x02011095ull;


static const uint64_t P9N2_PU_NX_CQ_FIR_ACTION0_REG                                = 0x02011086ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_ACTION0_REG                           = 0x05012C06ull;


static const uint64_t P9N2_PU_NX_CQ_FIR_ACTION1_REG                                = 0x02011087ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_ACTION1_REG                           = 0x05012C07ull;


static const uint64_t P9N2_PU_NX_CQ_FIR_MASK_REG                                   = 0x02011083ull;

static const uint64_t P9N2_PU_NX_CQ_FIR_MASK_REG_AND                               = 0x02011084ull;

static const uint64_t P9N2_PU_NX_CQ_FIR_MASK_REG_OR                                = 0x02011085ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_MASK_REG                              = 0x05012C03ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_MASK_REG_AND                          = 0x05012C04ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_MASK_REG_OR                           = 0x05012C05ull;


static const uint64_t P9N2_PU_NX_CQ_FIR_REG                                        = 0x02011080ull;

static const uint64_t P9N2_PU_NX_CQ_FIR_REG_AND                                    = 0x02011081ull;

static const uint64_t P9N2_PU_NX_CQ_FIR_REG_OR                                     = 0x02011082ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_REG                                   = 0x05012C00ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_REG_AND                               = 0x05012C01ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_REG_OR                                = 0x05012C02ull;


static const uint64_t P9N2_PU_NX_CQ_FIR_WOF_REG                                    = 0x02011088ull;

static const uint64_t P9N2_PU_NMMU_NX_CQ_FIR_WOF_REG                               = 0x05012C08ull;


static const uint64_t P9N2_PU_NX_DEBUGMUX_CTRL                                     = 0x0201110Aull;


static const uint64_t P9N2_PU_NX_DEBUG_SNAPSHOT_0                                  = 0x020110A4ull;

static const uint64_t P9N2_PU_NMMU_NX_DEBUG_SNAPSHOT_0                             = 0x05012C24ull;


static const uint64_t P9N2_PU_NX_DEBUG_SNAPSHOT_1                                  = 0x020110A5ull;

static const uint64_t P9N2_PU_NMMU_NX_DEBUG_SNAPSHOT_1                             = 0x05012C25ull;


static const uint64_t P9N2_PU_NX_DMA_ENG_FIR                                       = 0x02011100ull;

static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_AND                                   = 0x02011101ull;

static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_OR                                    = 0x02011102ull;


static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_ACTION0                               = 0x02011106ull;


static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_ACTION1                               = 0x02011107ull;


static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_MASK                                  = 0x02011103ull;

static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_MASK_AND                              = 0x02011104ull;

static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_MASK_OR                               = 0x02011105ull;


static const uint64_t P9N2_PU_NX_DMA_ENG_FIR_WOF                                   = 0x02011108ull;


static const uint64_t P9N2_PU_NX_ERRORINJ_CTRL                                     = 0x0201110Cull;


static const uint64_t P9N2_PU_NX_MISC_CONTROL_REG                                  = 0x020110A8ull;

static const uint64_t P9N2_PU_NMMU_NX_MISC_CONTROL_REG                             = 0x05012C28ull;


static const uint64_t P9N2_PU_NX_MMIO_BAR                                          = 0x0201108Dull;


static const uint64_t P9N2_PU_NX_PB_DEBUG_REG                                      = 0x02011090ull;

static const uint64_t P9N2_PU_NMMU_NX_PB_DEBUG_REG                                 = 0x05012C10ull;


static const uint64_t P9N2_PU_NX_PB_ECC_REG                                        = 0x02011091ull;

static const uint64_t P9N2_PU_NMMU_NX_PB_ECC_REG                                   = 0x05012C11ull;


static const uint64_t P9N2_PU_NX_PB_ERR_RPT_0                                      = 0x020110A2ull;

static const uint64_t P9N2_PU_NMMU_NX_PB_ERR_RPT_0                                 = 0x05012C22ull;


static const uint64_t P9N2_PU_NX_PB_ERR_RPT_1                                      = 0x020110A1ull;


static const uint64_t P9N2_PU_NX_PMU0_CONTROL_REG                                  = 0x020110A6ull;


static const uint64_t P9N2_PU_NX_PMU0_COUNTER_REG                                  = 0x020110A7ull;


static const uint64_t P9N2_PU_NX_PMU1_CONTROL_REG                                  = 0x020110A9ull;


static const uint64_t P9N2_PU_NX_PMU1_COUNTER_REG                                  = 0x020110AAull;


static const uint64_t P9N2_PU_NMMU_NX_PMU_CONTROL_REG                              = 0x05012C26ull;


static const uint64_t P9N2_PU_NMMU_NX_PMU_COUNTER_REG                              = 0x05012C27ull;


static const uint64_t P9N2_PU_NX_RNG_BYPASS                                        = 0x020110E4ull;


static const uint64_t P9N2_PU_NX_RNG_CFG                                           = 0x020110E0ull;


static const uint64_t P9N2_PU_NX_RNG_RDELAY                                        = 0x020110E5ull;


static const uint64_t P9N2_PU_NX_RNG_RESET                                         = 0x020110E6ull;


static const uint64_t P9N2_PU_NX_RNG_ST0                                           = 0x020110E1ull;


static const uint64_t P9N2_PU_NX_RNG_ST1                                           = 0x020110E2ull;


static const uint64_t P9N2_PU_NX_RNG_ST2                                           = 0x020110E3ull;


static const uint64_t P9N2_PU_NX_RNG_ST3                                           = 0x020110E8ull;


static const uint64_t P9N2_PU_NX_TRIGGER_CTRL                                      = 0x0201110Bull;


static const uint64_t P9N2_PU_OCB_OCI_CCSR_OCI                                     = 0xC0060480ull;

static const uint64_t P9N2_PU_OCB_OCI_CCSR_OCI1                                    = 0xC0060488ull;

static const uint64_t P9N2_PU_OCB_OCI_CCSR_OCI2                                    = 0xC0060490ull;

static const uint64_t P9N2_PU_OCB_OCI_CCSR_SCOM                                    = 0x0006C090ull;

static const uint64_t P9N2_PU_OCB_OCI_CCSR_SCOM1                                   = 0x0006C091ull;

static const uint64_t P9N2_PU_OCB_OCI_CCSR_SCOM2                                   = 0x0006C092ull;


static const uint64_t P9N2_PU_OCB_OCI_DERP_OCI                                     = 0xC0060C00ull;

static const uint64_t P9N2_PU_OCB_OCI_DERP_SCOM                                    = 0x0006C180ull;


static const uint64_t P9N2_PU_OCB_OCI_DORP_OCI                                     = 0xC0060C08ull;

static const uint64_t P9N2_PU_OCB_OCI_DORP_SCOM                                    = 0x0006C181ull;


static const uint64_t P9N2_PU_OCB_OCI_G0ISR0_OCI                                   = 0xC0060320ull;

static const uint64_t P9N2_PU_OCB_OCI_G0ISR0_SCOM                                  = 0x0006C064ull;


static const uint64_t P9N2_PU_OCB_OCI_G0ISR1_OCI                                   = 0xC00603A0ull;

static const uint64_t P9N2_PU_OCB_OCI_G0ISR1_SCOM                                  = 0x0006C074ull;


static const uint64_t P9N2_PU_OCB_OCI_G1ISR0_OCI                                   = 0xC0060328ull;

static const uint64_t P9N2_PU_OCB_OCI_G1ISR0_SCOM                                  = 0x0006C065ull;


static const uint64_t P9N2_PU_OCB_OCI_G1ISR1_OCI                                   = 0xC00603A8ull;

static const uint64_t P9N2_PU_OCB_OCI_G1ISR1_SCOM                                  = 0x0006C075ull;


static const uint64_t P9N2_PU_OCB_OCI_G2ISR0_OCI                                   = 0xC0060330ull;

static const uint64_t P9N2_PU_OCB_OCI_G2ISR0_SCOM                                  = 0x0006C066ull;


static const uint64_t P9N2_PU_OCB_OCI_G2ISR1_OCI                                   = 0xC00603B0ull;

static const uint64_t P9N2_PU_OCB_OCI_G2ISR1_SCOM                                  = 0x0006C076ull;


static const uint64_t P9N2_PU_OCB_OCI_G3ISR0_OCI                                   = 0xC0060338ull;

static const uint64_t P9N2_PU_OCB_OCI_G3ISR0_SCOM                                  = 0x0006C067ull;


static const uint64_t P9N2_PU_OCB_OCI_G3ISR1_OCI                                   = 0xC00603B8ull;

static const uint64_t P9N2_PU_OCB_OCI_G3ISR1_SCOM                                  = 0x0006C077ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCMD0A_OCI                                 = 0xC0063838ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCMD0A_SCOM                                = 0x0006C707ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCMD0B_OCI                                 = 0xC00638B8ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCMD0B_SCOM                                = 0x0006C717ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCMD1A_OCI                                 = 0xC0063938ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCMD1A_SCOM                                = 0x0006C727ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCMD1B_OCI                                 = 0xC00639B8ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCMD1B_SCOM                                = 0x0006C737ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL10A_OCI                               = 0xC0063810ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL10A_SCOM                              = 0x0006C702ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL10B_OCI                               = 0xC0063890ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL10B_SCOM                              = 0x0006C712ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL11A_OCI                               = 0xC0063910ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL11A_SCOM                              = 0x0006C722ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL11B_OCI                               = 0xC0063990ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL11B_SCOM                              = 0x0006C732ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL20A_OCI                               = 0xC0063818ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL20A_SCOM                              = 0x0006C703ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL20B_OCI                               = 0xC0063898ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL20B_SCOM                              = 0x0006C713ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL21A_OCI                               = 0xC0063918ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL21A_SCOM                              = 0x0006C723ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL21B_OCI                               = 0xC0063998ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRL21B_SCOM                              = 0x0006C733ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF0A_OCI                               = 0xC0063800ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF0A_SCOM                              = 0x0006C700ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF0B_OCI                               = 0xC0063880ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF0B_SCOM                              = 0x0006C710ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF1A_OCI                               = 0xC0063900ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF1A_SCOM                              = 0x0006C720ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF1B_OCI                               = 0xC0063980ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLF1B_SCOM                              = 0x0006C730ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS0A_OCI                               = 0xC0063808ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS0A_SCOM                              = 0x0006C701ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS0B_OCI                               = 0xC0063888ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS0B_SCOM                              = 0x0006C711ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS1A_OCI                               = 0xC0063908ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS1A_SCOM                              = 0x0006C721ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS1B_OCI                               = 0xC0063988ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SCTRLS1B_SCOM                              = 0x0006C731ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SRD0A_OCI                                  = 0xC0063848ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SRD0A_SCOM                                 = 0x0006C709ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SRD0B_OCI                                  = 0xC00638C8ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SRD0B_SCOM                                 = 0x0006C719ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SRD1A_OCI                                  = 0xC0063948ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SRD1A_SCOM                                 = 0x0006C729ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SRD1B_OCI                                  = 0xC00639C8ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SRD1B_SCOM                                 = 0x0006C739ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SST0A_OCI                                  = 0xC0063830ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SST0A_SCOM                                 = 0x0006C706ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SST0B_OCI                                  = 0xC00638B0ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SST0B_SCOM                                 = 0x0006C716ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SST1A_OCI                                  = 0xC0063930ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SST1A_SCOM                                 = 0x0006C726ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SST1B_OCI                                  = 0xC00639B0ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SST1B_SCOM                                 = 0x0006C736ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SWD0A_OCI                                  = 0xC0063840ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SWD0A_SCOM                                 = 0x0006C708ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SWD0B_OCI                                  = 0xC00638C0ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SWD0B_SCOM                                 = 0x0006C718ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SWD1A_OCI                                  = 0xC0063940ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SWD1A_SCOM                                 = 0x0006C728ull;


static const uint64_t P9N2_PU_OCB_OCI_O2SWD1B_OCI                                  = 0xC00639C0ull;

static const uint64_t P9N2_PU_OCB_OCI_O2SWD1B_SCOM                                 = 0x0006C738ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR0_OCI                                 = 0xC0061040ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR0_SCOM                                = 0x0006C208ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR1_OCI                                 = 0xC00610C0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR1_SCOM                                = 0x0006C218ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR2_OCI                                 = 0xC0061140ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR2_SCOM                                = 0x0006C228ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR3_OCI                                 = 0xC00611C0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWCR3_SCOM                                = 0x0006C238ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR0_OCI                                = 0xC0061060ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR0_SCOM                               = 0x0006C20Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR1_OCI                                = 0xC00610E0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR1_SCOM                               = 0x0006C21Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR2_OCI                                = 0xC0061160ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR2_SCOM                               = 0x0006C22Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR3_OCI                                = 0xC00611E0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSBR3_SCOM                               = 0x0006C23Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR0_OCI                                 = 0xC0061050ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR0_SCOM                                = 0x0006C20Aull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR1_OCI                                 = 0xC00610D0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR1_SCOM                                = 0x0006C21Aull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR2_OCI                                 = 0xC0061150ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR2_SCOM                                = 0x0006C22Aull;


static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR3_OCI                                 = 0xC00611D0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBLWSR3_SCOM                                = 0x0006C23Aull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSES0_OCI                                  = 0xC0061030ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSES0_SCOM                                 = 0x0006C206ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSES1_OCI                                  = 0xC00610B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSES1_SCOM                                 = 0x0006C216ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSES2_OCI                                  = 0xC0061130ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSES2_SCOM                                 = 0x0006C226ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSES3_OCI                                  = 0xC00611B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSES3_SCOM                                 = 0x0006C236ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR0_OCI                                 = 0xC0061018ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR0_SCOM                                = 0x0006C203ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR1_OCI                                 = 0xC0061098ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR1_SCOM                                = 0x0006C213ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR2_OCI                                 = 0xC0061118ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR2_SCOM                                = 0x0006C223ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR3_OCI                                 = 0xC0061198ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHBR3_SCOM                                = 0x0006C233ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS0_OCI                                 = 0xC0061020ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS0_SCOM                                = 0x0006C204ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS1_OCI                                 = 0xC00610A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS1_SCOM                                = 0x0006C214ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS2_OCI                                 = 0xC0061120ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS2_SCOM                                = 0x0006C224ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS3_OCI                                 = 0xC00611A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHCS3_SCOM                                = 0x0006C234ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHI0_OCI                                  = 0xC0061028ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHI0_SCOM                                 = 0x0006C205ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHI1_OCI                                  = 0xC00610A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHI1_SCOM                                 = 0x0006C215ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHI2_OCI                                  = 0xC0061128ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHI2_SCOM                                 = 0x0006C225ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSHI3_OCI                                  = 0xC00611A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSHI3_SCOM                                 = 0x0006C235ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR0_OCI                                 = 0xC0061000ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR0_SCOM                                = 0x0006C200ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR1_OCI                                 = 0xC0061080ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR1_SCOM                                = 0x0006C210ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR2_OCI                                 = 0xC0061100ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR2_SCOM                                = 0x0006C220ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR3_OCI                                 = 0xC0061180ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLBR3_SCOM                                = 0x0006C230ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS0_OCI                                 = 0xC0061008ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS0_SCOM                                = 0x0006C201ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS1_OCI                                 = 0xC0061088ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS1_SCOM                                = 0x0006C211ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS2_OCI                                 = 0xC0061108ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS2_SCOM                                = 0x0006C221ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS3_OCI                                 = 0xC0061188ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLCS3_SCOM                                = 0x0006C231ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLI0_OCI                                  = 0xC0061010ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLI0_SCOM                                 = 0x0006C202ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLI1_OCI                                  = 0xC0061090ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLI1_SCOM                                 = 0x0006C212ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLI2_OCI                                  = 0xC0061110ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLI2_SCOM                                 = 0x0006C222ull;


static const uint64_t P9N2_PU_OCB_OCI_OCBSLI3_OCI                                  = 0xC0061190ull;

static const uint64_t P9N2_PU_OCB_OCI_OCBSLI3_SCOM                                 = 0x0006C232ull;


static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_OCI                                   = 0xC0060450ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_OCI1                                  = 0xC0060458ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_OCI2                                  = 0xC0060460ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_SCOM                                  = 0x0006C08Aull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_SCOM1                                 = 0x0006C08Bull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG_SCOM2                                 = 0x0006C08Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_OCI                                  = 0xC0060C50ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_OCI1                                 = 0xC0060C58ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_OCI2                                 = 0xC0060C60ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_SCOM                                 = 0x0006C18Aull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_SCOM1                                = 0x0006C18Bull;

static const uint64_t P9N2_PU_OCB_OCI_OCCFLG2_SCOM2                                = 0x0006C18Cull;


static const uint64_t P9N2_PU_OCB_OCI_OCCHBR_OCI                                   = 0xC0060478ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCHBR_SCOM                                  = 0x0006C08Full;


static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_OCI                                  = 0xC0060400ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_OCI1                                 = 0xC0060408ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_OCI2                                 = 0xC0060410ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_SCOM                                 = 0x0006C080ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_SCOM1                                = 0x0006C081ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCMISC_SCOM2                                = 0x0006C082ull;


static const uint64_t P9N2_PU_OCB_OCI_OCCS0_OCI                                    = 0xC0060430ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCS0_SCOM                                   = 0x0006C086ull;


static const uint64_t P9N2_PU_OCB_OCI_OCCS1_OCI                                    = 0xC0060438ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCS1_SCOM                                   = 0x0006C087ull;


static const uint64_t P9N2_PU_OCB_OCI_OCCS2_OCI                                    = 0xC0060440ull;

static const uint64_t P9N2_PU_OCB_OCI_OCCS2_SCOM                                   = 0x0006C088ull;


static const uint64_t P9N2_PU_OCB_OCI_OCICFG_OCI                                   = 0xC0060428ull;

static const uint64_t P9N2_PU_OCB_OCI_OCICFG_SCOM                                  = 0x0006C085ull;


static const uint64_t P9N2_PU_OCB_OCI_OCISR0_OCI                                   = 0xC0060308ull;

static const uint64_t P9N2_PU_OCB_OCI_OCISR0_SCOM                                  = 0x0006C061ull;


static const uint64_t P9N2_PU_OCB_OCI_OCISR1_OCI                                   = 0xC0060388ull;

static const uint64_t P9N2_PU_OCB_OCI_OCISR1_SCOM                                  = 0x0006C071ull;


static const uint64_t P9N2_PU_OCB_OCI_ODISR0_OCI                                   = 0xC0060318ull;

static const uint64_t P9N2_PU_OCB_OCI_ODISR0_SCOM                                  = 0x0006C063ull;


static const uint64_t P9N2_PU_OCB_OCI_ODISR1_OCI                                   = 0xC0060398ull;

static const uint64_t P9N2_PU_OCB_OCI_ODISR1_SCOM                                  = 0x0006C073ull;


static const uint64_t P9N2_PU_OCB_OCI_OEHDR_OCI                                    = 0xC0060420ull;

static const uint64_t P9N2_PU_OCB_OCI_OEHDR_SCOM                                   = 0x0006C084ull;


static const uint64_t P9N2_PU_OCB_OCI_OHTMCR_OCI                                   = 0xC0060418ull;

static const uint64_t P9N2_PU_OCB_OCI_OHTMCR_SCOM                                  = 0x0006C083ull;


static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_OCI                                   = 0xC0060060ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_OCI1                                  = 0xC0060068ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_OCI2                                  = 0xC0060070ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_SCOM                                  = 0x0006C00Cull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_SCOM1                                 = 0x0006C00Dull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR0_SCOM2                                 = 0x0006C00Eull;


static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_OCI                                   = 0xC0060160ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_OCI1                                  = 0xC0060168ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_OCI2                                  = 0xC0060170ull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_SCOM                                  = 0x0006C02Cull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_SCOM1                                 = 0x0006C02Dull;

static const uint64_t P9N2_PU_OCB_OCI_OIEPR1_SCOM2                                 = 0x0006C02Eull;


static const uint64_t P9N2_PU_OCB_OCI_OIMR0_OCI                                    = 0xC0060020ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR0_OCI1                                   = 0xC0060028ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR0_OCI2                                   = 0xC0060030ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR0_SCOM                                   = 0x0006C004ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR0_SCOM1                                  = 0x0006C005ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR0_SCOM2                                  = 0x0006C006ull;


static const uint64_t P9N2_PU_OCB_OCI_OIMR1_OCI                                    = 0xC0060120ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR1_OCI1                                   = 0xC0060128ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR1_OCI2                                   = 0xC0060130ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR1_SCOM                                   = 0x0006C024ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR1_SCOM1                                  = 0x0006C025ull;

static const uint64_t P9N2_PU_OCB_OCI_OIMR1_SCOM2                                  = 0x0006C026ull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_OCI                                   = 0xC0060200ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_OCI1                                  = 0xC0060208ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_OCI2                                  = 0xC0060210ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_SCOM                                  = 0x0006C040ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_SCOM1                                 = 0x0006C041ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0A_SCOM2                                 = 0x0006C042ull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_OCI                                   = 0xC0060220ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_OCI1                                  = 0xC0060228ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_OCI2                                  = 0xC0060230ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_SCOM                                  = 0x0006C044ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_SCOM1                                 = 0x0006C045ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0B_SCOM2                                 = 0x0006C046ull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_OCI                                   = 0xC0060240ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_OCI1                                  = 0xC0060248ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_OCI2                                  = 0xC0060250ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_SCOM                                  = 0x0006C048ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_SCOM1                                 = 0x0006C049ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR0C_SCOM2                                 = 0x0006C04Aull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_OCI                                   = 0xC0060280ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_OCI1                                  = 0xC0060288ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_OCI2                                  = 0xC0060290ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_SCOM                                  = 0x0006C050ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_SCOM1                                 = 0x0006C051ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1A_SCOM2                                 = 0x0006C052ull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_OCI                                   = 0xC00602A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_OCI1                                  = 0xC00602A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_OCI2                                  = 0xC00602B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_SCOM                                  = 0x0006C054ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_SCOM1                                 = 0x0006C055ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1B_SCOM2                                 = 0x0006C056ull;


static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_OCI                                   = 0xC00602C0ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_OCI1                                  = 0xC00602C8ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_OCI2                                  = 0xC00602D0ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_SCOM                                  = 0x0006C058ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_SCOM1                                 = 0x0006C059ull;

static const uint64_t P9N2_PU_OCB_OCI_OIRR1C_SCOM2                                 = 0x0006C05Aull;


static const uint64_t P9N2_PU_OCB_OCI_OISR0_OCI                                    = 0xC0060000ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR0_OCI1                                   = 0xC0060008ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR0_OCI2                                   = 0xC0060010ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR0_SCOM                                   = 0x0006C000ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR0_SCOM1                                  = 0x0006C001ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR0_SCOM2                                  = 0x0006C002ull;


static const uint64_t P9N2_PU_OCB_OCI_OISR1_OCI                                    = 0xC0060100ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR1_OCI1                                   = 0xC0060108ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR1_OCI2                                   = 0xC0060110ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR1_SCOM                                   = 0x0006C020ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR1_SCOM1                                  = 0x0006C021ull;

static const uint64_t P9N2_PU_OCB_OCI_OISR1_SCOM2                                  = 0x0006C022ull;


static const uint64_t P9N2_PU_OCB_OCI_OITR0_OCI                                    = 0xC0060040ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR0_OCI1                                   = 0xC0060048ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR0_OCI2                                   = 0xC0060050ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR0_SCOM                                   = 0x0006C008ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR0_SCOM1                                  = 0x0006C009ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR0_SCOM2                                  = 0x0006C00Aull;


static const uint64_t P9N2_PU_OCB_OCI_OITR1_OCI                                    = 0xC0060140ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR1_OCI1                                   = 0xC0060148ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR1_OCI2                                   = 0xC0060150ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR1_SCOM                                   = 0x0006C028ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR1_SCOM1                                  = 0x0006C029ull;

static const uint64_t P9N2_PU_OCB_OCI_OITR1_SCOM2                                  = 0x0006C02Aull;


static const uint64_t P9N2_PU_OCB_OCI_ONISR0_OCI                                   = 0xC0060300ull;

static const uint64_t P9N2_PU_OCB_OCI_ONISR0_SCOM                                  = 0x0006C060ull;


static const uint64_t P9N2_PU_OCB_OCI_ONISR1_OCI                                   = 0xC0060380ull;

static const uint64_t P9N2_PU_OCB_OCI_ONISR1_SCOM                                  = 0x0006C070ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C0_OCI                                  = 0xC0062000ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C0_OCI1                                 = 0xC0062800ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C0_SCOM                                 = 0x0006C400ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C0_SCOM1                                = 0x0006C500ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C1_OCI                                  = 0xC0062008ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C1_OCI1                                 = 0xC0062808ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C1_SCOM                                 = 0x0006C401ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C1_SCOM1                                = 0x0006C501ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C10_OCI                                 = 0xC0062050ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C10_OCI1                                = 0xC0062850ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C10_SCOM                                = 0x0006C40Aull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C10_SCOM1                               = 0x0006C50Aull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C11_OCI                                 = 0xC0062058ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C11_OCI1                                = 0xC0062858ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C11_SCOM                                = 0x0006C40Bull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C11_SCOM1                               = 0x0006C50Bull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C12_OCI                                 = 0xC0062060ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C12_OCI1                                = 0xC0062860ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C12_SCOM                                = 0x0006C40Cull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C12_SCOM1                               = 0x0006C50Cull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C13_OCI                                 = 0xC0062068ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C13_OCI1                                = 0xC0062868ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C13_SCOM                                = 0x0006C40Dull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C13_SCOM1                               = 0x0006C50Dull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C14_OCI                                 = 0xC0062070ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C14_OCI1                                = 0xC0062870ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C14_SCOM                                = 0x0006C40Eull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C14_SCOM1                               = 0x0006C50Eull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C15_OCI                                 = 0xC0062078ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C15_OCI1                                = 0xC0062878ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C15_SCOM                                = 0x0006C40Full;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C15_SCOM1                               = 0x0006C50Full;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C16_OCI                                 = 0xC0062080ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C16_OCI1                                = 0xC0062880ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C16_SCOM                                = 0x0006C410ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C16_SCOM1                               = 0x0006C510ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C17_OCI                                 = 0xC0062088ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C17_OCI1                                = 0xC0062888ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C17_SCOM                                = 0x0006C411ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C17_SCOM1                               = 0x0006C511ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C18_OCI                                 = 0xC0062090ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C18_OCI1                                = 0xC0062890ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C18_SCOM                                = 0x0006C412ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C18_SCOM1                               = 0x0006C512ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C19_OCI                                 = 0xC0062098ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C19_OCI1                                = 0xC0062898ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C19_SCOM                                = 0x0006C413ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C19_SCOM1                               = 0x0006C513ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C2_OCI                                  = 0xC0062010ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C2_OCI1                                 = 0xC0062810ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C2_SCOM                                 = 0x0006C402ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C2_SCOM1                                = 0x0006C502ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C20_OCI                                 = 0xC00620A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C20_OCI1                                = 0xC00628A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C20_SCOM                                = 0x0006C414ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C20_SCOM1                               = 0x0006C514ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C21_OCI                                 = 0xC00620A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C21_OCI1                                = 0xC00628A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C21_SCOM                                = 0x0006C415ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C21_SCOM1                               = 0x0006C515ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C22_OCI                                 = 0xC00620B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C22_OCI1                                = 0xC00628B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C22_SCOM                                = 0x0006C416ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C22_SCOM1                               = 0x0006C516ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C23_OCI                                 = 0xC00620B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C23_OCI1                                = 0xC00628B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C23_SCOM                                = 0x0006C417ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C23_SCOM1                               = 0x0006C517ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C3_OCI                                  = 0xC0062018ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C3_OCI1                                 = 0xC0062818ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C3_SCOM                                 = 0x0006C403ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C3_SCOM1                                = 0x0006C503ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C4_OCI                                  = 0xC0062020ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C4_OCI1                                 = 0xC0062820ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C4_SCOM                                 = 0x0006C404ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C4_SCOM1                                = 0x0006C504ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C5_OCI                                  = 0xC0062028ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C5_OCI1                                 = 0xC0062828ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C5_SCOM                                 = 0x0006C405ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C5_SCOM1                                = 0x0006C505ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C6_OCI                                  = 0xC0062030ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C6_OCI1                                 = 0xC0062830ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C6_SCOM                                 = 0x0006C406ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C6_SCOM1                                = 0x0006C506ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C7_OCI                                  = 0xC0062038ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C7_OCI1                                 = 0xC0062838ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C7_SCOM                                 = 0x0006C407ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C7_SCOM1                                = 0x0006C507ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C8_OCI                                  = 0xC0062040ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C8_OCI1                                 = 0xC0062840ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C8_SCOM                                 = 0x0006C408ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C8_SCOM1                                = 0x0006C508ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0C9_OCI                                  = 0xC0062048ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C9_OCI1                                 = 0xC0062848ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C9_SCOM                                 = 0x0006C409ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0C9_SCOM1                                = 0x0006C509ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT0PRA_OCI                                 = 0xC0063000ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0PRA_OCI1                                = 0xC0063008ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0PRA_SCOM                                = 0x0006C600ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT0PRA_SCOM1                               = 0x0006C601ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C0_OCI                                  = 0xC0062100ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C0_OCI1                                 = 0xC0062900ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C0_SCOM                                 = 0x0006C420ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C0_SCOM1                                = 0x0006C520ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C1_OCI                                  = 0xC0062108ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C1_OCI1                                 = 0xC0062908ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C1_SCOM                                 = 0x0006C421ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C1_SCOM1                                = 0x0006C521ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C10_OCI                                 = 0xC0062150ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C10_OCI1                                = 0xC0062950ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C10_SCOM                                = 0x0006C42Aull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C10_SCOM1                               = 0x0006C52Aull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C11_OCI                                 = 0xC0062158ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C11_OCI1                                = 0xC0062958ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C11_SCOM                                = 0x0006C42Bull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C11_SCOM1                               = 0x0006C52Bull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C12_OCI                                 = 0xC0062160ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C12_OCI1                                = 0xC0062960ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C12_SCOM                                = 0x0006C42Cull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C12_SCOM1                               = 0x0006C52Cull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C13_OCI                                 = 0xC0062168ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C13_OCI1                                = 0xC0062968ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C13_SCOM                                = 0x0006C42Dull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C13_SCOM1                               = 0x0006C52Dull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C14_OCI                                 = 0xC0062170ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C14_OCI1                                = 0xC0062970ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C14_SCOM                                = 0x0006C42Eull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C14_SCOM1                               = 0x0006C52Eull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C15_OCI                                 = 0xC0062178ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C15_OCI1                                = 0xC0062978ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C15_SCOM                                = 0x0006C42Full;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C15_SCOM1                               = 0x0006C52Full;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C16_OCI                                 = 0xC0062180ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C16_OCI1                                = 0xC0062980ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C16_SCOM                                = 0x0006C430ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C16_SCOM1                               = 0x0006C530ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C17_OCI                                 = 0xC0062188ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C17_OCI1                                = 0xC0062988ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C17_SCOM                                = 0x0006C431ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C17_SCOM1                               = 0x0006C531ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C18_OCI                                 = 0xC0062190ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C18_OCI1                                = 0xC0062990ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C18_SCOM                                = 0x0006C432ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C18_SCOM1                               = 0x0006C532ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C19_OCI                                 = 0xC0062198ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C19_OCI1                                = 0xC0062998ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C19_SCOM                                = 0x0006C433ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C19_SCOM1                               = 0x0006C533ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C2_OCI                                  = 0xC0062110ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C2_OCI1                                 = 0xC0062910ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C2_SCOM                                 = 0x0006C422ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C2_SCOM1                                = 0x0006C522ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C20_OCI                                 = 0xC00621A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C20_OCI1                                = 0xC00629A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C20_SCOM                                = 0x0006C434ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C20_SCOM1                               = 0x0006C534ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C21_OCI                                 = 0xC00621A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C21_OCI1                                = 0xC00629A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C21_SCOM                                = 0x0006C435ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C21_SCOM1                               = 0x0006C535ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C22_OCI                                 = 0xC00621B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C22_OCI1                                = 0xC00629B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C22_SCOM                                = 0x0006C436ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C22_SCOM1                               = 0x0006C536ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C23_OCI                                 = 0xC00621B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C23_OCI1                                = 0xC00629B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C23_SCOM                                = 0x0006C437ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C23_SCOM1                               = 0x0006C537ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C3_OCI                                  = 0xC0062118ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C3_OCI1                                 = 0xC0062918ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C3_SCOM                                 = 0x0006C423ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C3_SCOM1                                = 0x0006C523ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C4_OCI                                  = 0xC0062120ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C4_OCI1                                 = 0xC0062920ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C4_SCOM                                 = 0x0006C424ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C4_SCOM1                                = 0x0006C524ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C5_OCI                                  = 0xC0062128ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C5_OCI1                                 = 0xC0062928ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C5_SCOM                                 = 0x0006C425ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C5_SCOM1                                = 0x0006C525ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C6_OCI                                  = 0xC0062130ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C6_OCI1                                 = 0xC0062930ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C6_SCOM                                 = 0x0006C426ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C6_SCOM1                                = 0x0006C526ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C7_OCI                                  = 0xC0062138ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C7_OCI1                                 = 0xC0062938ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C7_SCOM                                 = 0x0006C427ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C7_SCOM1                                = 0x0006C527ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C8_OCI                                  = 0xC0062140ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C8_OCI1                                 = 0xC0062940ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C8_SCOM                                 = 0x0006C428ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C8_SCOM1                                = 0x0006C528ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1C9_OCI                                  = 0xC0062148ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C9_OCI1                                 = 0xC0062948ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C9_SCOM                                 = 0x0006C429ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1C9_SCOM1                                = 0x0006C529ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT1PRA_OCI                                 = 0xC0063100ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1PRA_OCI1                                = 0xC0063108ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1PRA_SCOM                                = 0x0006C620ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT1PRA_SCOM1                               = 0x0006C621ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C0_OCI                                  = 0xC0062200ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C0_OCI1                                 = 0xC0062A00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C0_SCOM                                 = 0x0006C440ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C0_SCOM1                                = 0x0006C540ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C1_OCI                                  = 0xC0062208ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C1_OCI1                                 = 0xC0062A08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C1_SCOM                                 = 0x0006C441ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C1_SCOM1                                = 0x0006C541ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C10_OCI                                 = 0xC0062250ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C10_OCI1                                = 0xC0062A50ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C10_SCOM                                = 0x0006C44Aull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C10_SCOM1                               = 0x0006C54Aull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C11_OCI                                 = 0xC0062258ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C11_OCI1                                = 0xC0062A58ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C11_SCOM                                = 0x0006C44Bull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C11_SCOM1                               = 0x0006C54Bull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C12_OCI                                 = 0xC0062260ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C12_OCI1                                = 0xC0062A60ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C12_SCOM                                = 0x0006C44Cull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C12_SCOM1                               = 0x0006C54Cull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C13_OCI                                 = 0xC0062268ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C13_OCI1                                = 0xC0062A68ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C13_SCOM                                = 0x0006C44Dull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C13_SCOM1                               = 0x0006C54Dull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C14_OCI                                 = 0xC0062270ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C14_OCI1                                = 0xC0062A70ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C14_SCOM                                = 0x0006C44Eull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C14_SCOM1                               = 0x0006C54Eull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C15_OCI                                 = 0xC0062278ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C15_OCI1                                = 0xC0062A78ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C15_SCOM                                = 0x0006C44Full;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C15_SCOM1                               = 0x0006C54Full;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C16_OCI                                 = 0xC0062280ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C16_OCI1                                = 0xC0062A80ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C16_SCOM                                = 0x0006C450ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C16_SCOM1                               = 0x0006C550ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C17_OCI                                 = 0xC0062288ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C17_OCI1                                = 0xC0062A88ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C17_SCOM                                = 0x0006C451ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C17_SCOM1                               = 0x0006C551ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C18_OCI                                 = 0xC0062290ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C18_OCI1                                = 0xC0062A90ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C18_SCOM                                = 0x0006C452ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C18_SCOM1                               = 0x0006C552ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C19_OCI                                 = 0xC0062298ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C19_OCI1                                = 0xC0062A98ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C19_SCOM                                = 0x0006C453ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C19_SCOM1                               = 0x0006C553ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C2_OCI                                  = 0xC0062210ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C2_OCI1                                 = 0xC0062A10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C2_SCOM                                 = 0x0006C442ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C2_SCOM1                                = 0x0006C542ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C20_OCI                                 = 0xC00622A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C20_OCI1                                = 0xC0062AA0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C20_SCOM                                = 0x0006C454ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C20_SCOM1                               = 0x0006C554ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C21_OCI                                 = 0xC00622A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C21_OCI1                                = 0xC0062AA8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C21_SCOM                                = 0x0006C455ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C21_SCOM1                               = 0x0006C555ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C22_OCI                                 = 0xC00622B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C22_OCI1                                = 0xC0062AB0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C22_SCOM                                = 0x0006C456ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C22_SCOM1                               = 0x0006C556ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C23_OCI                                 = 0xC00622B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C23_OCI1                                = 0xC0062AB8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C23_SCOM                                = 0x0006C457ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C23_SCOM1                               = 0x0006C557ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C3_OCI                                  = 0xC0062218ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C3_OCI1                                 = 0xC0062A18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C3_SCOM                                 = 0x0006C443ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C3_SCOM1                                = 0x0006C543ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C4_OCI                                  = 0xC0062220ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C4_OCI1                                 = 0xC0062A20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C4_SCOM                                 = 0x0006C444ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C4_SCOM1                                = 0x0006C544ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C5_OCI                                  = 0xC0062228ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C5_OCI1                                 = 0xC0062A28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C5_SCOM                                 = 0x0006C445ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C5_SCOM1                                = 0x0006C545ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C6_OCI                                  = 0xC0062230ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C6_OCI1                                 = 0xC0062A30ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C6_SCOM                                 = 0x0006C446ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C6_SCOM1                                = 0x0006C546ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C7_OCI                                  = 0xC0062238ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C7_OCI1                                 = 0xC0062A38ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C7_SCOM                                 = 0x0006C447ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C7_SCOM1                                = 0x0006C547ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C8_OCI                                  = 0xC0062240ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C8_OCI1                                 = 0xC0062A40ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C8_SCOM                                 = 0x0006C448ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C8_SCOM1                                = 0x0006C548ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2C9_OCI                                  = 0xC0062248ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C9_OCI1                                 = 0xC0062A48ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C9_SCOM                                 = 0x0006C449ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2C9_SCOM1                                = 0x0006C549ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT2PRA_OCI                                 = 0xC0063200ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2PRA_OCI1                                = 0xC0063208ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2PRA_SCOM                                = 0x0006C640ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT2PRA_SCOM1                               = 0x0006C641ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C0_OCI                                  = 0xC0062300ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C0_OCI1                                 = 0xC0062B00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C0_SCOM                                 = 0x0006C460ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C0_SCOM1                                = 0x0006C560ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C1_OCI                                  = 0xC0062308ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C1_OCI1                                 = 0xC0062B08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C1_SCOM                                 = 0x0006C461ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C1_SCOM1                                = 0x0006C561ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C10_OCI                                 = 0xC0062350ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C10_OCI1                                = 0xC0062B50ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C10_SCOM                                = 0x0006C46Aull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C10_SCOM1                               = 0x0006C56Aull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C11_OCI                                 = 0xC0062358ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C11_OCI1                                = 0xC0062B58ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C11_SCOM                                = 0x0006C46Bull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C11_SCOM1                               = 0x0006C56Bull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C12_OCI                                 = 0xC0062360ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C12_OCI1                                = 0xC0062B60ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C12_SCOM                                = 0x0006C46Cull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C12_SCOM1                               = 0x0006C56Cull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C13_OCI                                 = 0xC0062368ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C13_OCI1                                = 0xC0062B68ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C13_SCOM                                = 0x0006C46Dull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C13_SCOM1                               = 0x0006C56Dull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C14_OCI                                 = 0xC0062370ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C14_OCI1                                = 0xC0062B70ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C14_SCOM                                = 0x0006C46Eull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C14_SCOM1                               = 0x0006C56Eull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C15_OCI                                 = 0xC0062378ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C15_OCI1                                = 0xC0062B78ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C15_SCOM                                = 0x0006C46Full;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C15_SCOM1                               = 0x0006C56Full;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C16_OCI                                 = 0xC0062380ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C16_OCI1                                = 0xC0062B80ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C16_SCOM                                = 0x0006C470ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C16_SCOM1                               = 0x0006C570ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C17_OCI                                 = 0xC0062388ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C17_OCI1                                = 0xC0062B88ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C17_SCOM                                = 0x0006C471ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C17_SCOM1                               = 0x0006C571ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C18_OCI                                 = 0xC0062390ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C18_OCI1                                = 0xC0062B90ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C18_SCOM                                = 0x0006C472ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C18_SCOM1                               = 0x0006C572ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C19_OCI                                 = 0xC0062398ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C19_OCI1                                = 0xC0062B98ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C19_SCOM                                = 0x0006C473ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C19_SCOM1                               = 0x0006C573ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C2_OCI                                  = 0xC0062310ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C2_OCI1                                 = 0xC0062B10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C2_SCOM                                 = 0x0006C462ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C2_SCOM1                                = 0x0006C562ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C20_OCI                                 = 0xC00623A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C20_OCI1                                = 0xC0062BA0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C20_SCOM                                = 0x0006C474ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C20_SCOM1                               = 0x0006C574ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C21_OCI                                 = 0xC00623A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C21_OCI1                                = 0xC0062BA8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C21_SCOM                                = 0x0006C475ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C21_SCOM1                               = 0x0006C575ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C22_OCI                                 = 0xC00623B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C22_OCI1                                = 0xC0062BB0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C22_SCOM                                = 0x0006C476ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C22_SCOM1                               = 0x0006C576ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C23_OCI                                 = 0xC00623B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C23_OCI1                                = 0xC0062BB8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C23_SCOM                                = 0x0006C477ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C23_SCOM1                               = 0x0006C577ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C3_OCI                                  = 0xC0062318ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C3_OCI1                                 = 0xC0062B18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C3_SCOM                                 = 0x0006C463ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C3_SCOM1                                = 0x0006C563ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C4_OCI                                  = 0xC0062320ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C4_OCI1                                 = 0xC0062B20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C4_SCOM                                 = 0x0006C464ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C4_SCOM1                                = 0x0006C564ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C5_OCI                                  = 0xC0062328ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C5_OCI1                                 = 0xC0062B28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C5_SCOM                                 = 0x0006C465ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C5_SCOM1                                = 0x0006C565ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C6_OCI                                  = 0xC0062330ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C6_OCI1                                 = 0xC0062B30ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C6_SCOM                                 = 0x0006C466ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C6_SCOM1                                = 0x0006C566ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C7_OCI                                  = 0xC0062338ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C7_OCI1                                 = 0xC0062B38ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C7_SCOM                                 = 0x0006C467ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C7_SCOM1                                = 0x0006C567ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C8_OCI                                  = 0xC0062340ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C8_OCI1                                 = 0xC0062B40ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C8_SCOM                                 = 0x0006C468ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C8_SCOM1                                = 0x0006C568ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3C9_OCI                                  = 0xC0062348ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C9_OCI1                                 = 0xC0062B48ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C9_SCOM                                 = 0x0006C469ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3C9_SCOM1                                = 0x0006C569ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT3PRA_OCI                                 = 0xC0063300ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3PRA_OCI1                                = 0xC0063308ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3PRA_SCOM                                = 0x0006C660ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT3PRA_SCOM1                               = 0x0006C661ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C0_OCI                                  = 0xC0062400ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C0_OCI1                                 = 0xC0062C00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C0_SCOM                                 = 0x0006C480ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C0_SCOM1                                = 0x0006C580ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C1_OCI                                  = 0xC0062408ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C1_OCI1                                 = 0xC0062C08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C1_SCOM                                 = 0x0006C481ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C1_SCOM1                                = 0x0006C581ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C10_OCI                                 = 0xC0062450ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C10_OCI1                                = 0xC0062C50ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C10_SCOM                                = 0x0006C48Aull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C10_SCOM1                               = 0x0006C58Aull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C11_OCI                                 = 0xC0062458ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C11_OCI1                                = 0xC0062C58ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C11_SCOM                                = 0x0006C48Bull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C11_SCOM1                               = 0x0006C58Bull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C12_OCI                                 = 0xC0062460ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C12_OCI1                                = 0xC0062C60ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C12_SCOM                                = 0x0006C48Cull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C12_SCOM1                               = 0x0006C58Cull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C13_OCI                                 = 0xC0062468ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C13_OCI1                                = 0xC0062C68ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C13_SCOM                                = 0x0006C48Dull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C13_SCOM1                               = 0x0006C58Dull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C14_OCI                                 = 0xC0062470ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C14_OCI1                                = 0xC0062C70ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C14_SCOM                                = 0x0006C48Eull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C14_SCOM1                               = 0x0006C58Eull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C15_OCI                                 = 0xC0062478ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C15_OCI1                                = 0xC0062C78ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C15_SCOM                                = 0x0006C48Full;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C15_SCOM1                               = 0x0006C58Full;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C16_OCI                                 = 0xC0062480ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C16_OCI1                                = 0xC0062C80ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C16_SCOM                                = 0x0006C490ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C16_SCOM1                               = 0x0006C590ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C17_OCI                                 = 0xC0062488ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C17_OCI1                                = 0xC0062C88ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C17_SCOM                                = 0x0006C491ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C17_SCOM1                               = 0x0006C591ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C18_OCI                                 = 0xC0062490ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C18_OCI1                                = 0xC0062C90ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C18_SCOM                                = 0x0006C492ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C18_SCOM1                               = 0x0006C592ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C19_OCI                                 = 0xC0062498ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C19_OCI1                                = 0xC0062C98ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C19_SCOM                                = 0x0006C493ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C19_SCOM1                               = 0x0006C593ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C2_OCI                                  = 0xC0062410ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C2_OCI1                                 = 0xC0062C10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C2_SCOM                                 = 0x0006C482ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C2_SCOM1                                = 0x0006C582ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C20_OCI                                 = 0xC00624A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C20_OCI1                                = 0xC0062CA0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C20_SCOM                                = 0x0006C494ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C20_SCOM1                               = 0x0006C594ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C21_OCI                                 = 0xC00624A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C21_OCI1                                = 0xC0062CA8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C21_SCOM                                = 0x0006C495ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C21_SCOM1                               = 0x0006C595ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C22_OCI                                 = 0xC00624B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C22_OCI1                                = 0xC0062CB0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C22_SCOM                                = 0x0006C496ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C22_SCOM1                               = 0x0006C596ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C23_OCI                                 = 0xC00624B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C23_OCI1                                = 0xC0062CB8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C23_SCOM                                = 0x0006C497ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C23_SCOM1                               = 0x0006C597ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C3_OCI                                  = 0xC0062418ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C3_OCI1                                 = 0xC0062C18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C3_SCOM                                 = 0x0006C483ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C3_SCOM1                                = 0x0006C583ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C4_OCI                                  = 0xC0062420ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C4_OCI1                                 = 0xC0062C20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C4_SCOM                                 = 0x0006C484ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C4_SCOM1                                = 0x0006C584ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C5_OCI                                  = 0xC0062428ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C5_OCI1                                 = 0xC0062C28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C5_SCOM                                 = 0x0006C485ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C5_SCOM1                                = 0x0006C585ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C6_OCI                                  = 0xC0062430ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C6_OCI1                                 = 0xC0062C30ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C6_SCOM                                 = 0x0006C486ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C6_SCOM1                                = 0x0006C586ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C7_OCI                                  = 0xC0062438ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C7_OCI1                                 = 0xC0062C38ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C7_SCOM                                 = 0x0006C487ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C7_SCOM1                                = 0x0006C587ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C8_OCI                                  = 0xC0062440ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C8_OCI1                                 = 0xC0062C40ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C8_SCOM                                 = 0x0006C488ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C8_SCOM1                                = 0x0006C588ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4C9_OCI                                  = 0xC0062448ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C9_OCI1                                 = 0xC0062C48ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C9_SCOM                                 = 0x0006C489ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4C9_SCOM1                                = 0x0006C589ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT4PRA_OCI                                 = 0xC0063400ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4PRA_OCI1                                = 0xC0063408ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4PRA_SCOM                                = 0x0006C680ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT4PRA_SCOM1                               = 0x0006C681ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C0_OCI                                  = 0xC0062500ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C0_OCI1                                 = 0xC0062D00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C0_SCOM                                 = 0x0006C4A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C0_SCOM1                                = 0x0006C5A0ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C1_OCI                                  = 0xC0062508ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C1_OCI1                                 = 0xC0062D08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C1_SCOM                                 = 0x0006C4A1ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C1_SCOM1                                = 0x0006C5A1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C10_OCI                                 = 0xC0062550ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C10_OCI1                                = 0xC0062D50ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C10_SCOM                                = 0x0006C4AAull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C10_SCOM1                               = 0x0006C5AAull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C11_OCI                                 = 0xC0062558ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C11_OCI1                                = 0xC0062D58ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C11_SCOM                                = 0x0006C4ABull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C11_SCOM1                               = 0x0006C5ABull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C12_OCI                                 = 0xC0062560ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C12_OCI1                                = 0xC0062D60ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C12_SCOM                                = 0x0006C4ACull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C12_SCOM1                               = 0x0006C5ACull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C13_OCI                                 = 0xC0062568ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C13_OCI1                                = 0xC0062D68ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C13_SCOM                                = 0x0006C4ADull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C13_SCOM1                               = 0x0006C5ADull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C14_OCI                                 = 0xC0062570ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C14_OCI1                                = 0xC0062D70ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C14_SCOM                                = 0x0006C4AEull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C14_SCOM1                               = 0x0006C5AEull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C15_OCI                                 = 0xC0062578ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C15_OCI1                                = 0xC0062D78ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C15_SCOM                                = 0x0006C4AFull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C15_SCOM1                               = 0x0006C5AFull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C16_OCI                                 = 0xC0062580ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C16_OCI1                                = 0xC0062D80ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C16_SCOM                                = 0x0006C4B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C16_SCOM1                               = 0x0006C5B0ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C17_OCI                                 = 0xC0062588ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C17_OCI1                                = 0xC0062D88ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C17_SCOM                                = 0x0006C4B1ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C17_SCOM1                               = 0x0006C5B1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C18_OCI                                 = 0xC0062590ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C18_OCI1                                = 0xC0062D90ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C18_SCOM                                = 0x0006C4B2ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C18_SCOM1                               = 0x0006C5B2ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C19_OCI                                 = 0xC0062598ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C19_OCI1                                = 0xC0062D98ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C19_SCOM                                = 0x0006C4B3ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C19_SCOM1                               = 0x0006C5B3ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C2_OCI                                  = 0xC0062510ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C2_OCI1                                 = 0xC0062D10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C2_SCOM                                 = 0x0006C4A2ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C2_SCOM1                                = 0x0006C5A2ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C20_OCI                                 = 0xC00625A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C20_OCI1                                = 0xC0062DA0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C20_SCOM                                = 0x0006C4B4ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C20_SCOM1                               = 0x0006C5B4ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C21_OCI                                 = 0xC00625A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C21_OCI1                                = 0xC0062DA8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C21_SCOM                                = 0x0006C4B5ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C21_SCOM1                               = 0x0006C5B5ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C22_OCI                                 = 0xC00625B0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C22_OCI1                                = 0xC0062DB0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C22_SCOM                                = 0x0006C4B6ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C22_SCOM1                               = 0x0006C5B6ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C23_OCI                                 = 0xC00625B8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C23_OCI1                                = 0xC0062DB8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C23_SCOM                                = 0x0006C4B7ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C23_SCOM1                               = 0x0006C5B7ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C3_OCI                                  = 0xC0062518ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C3_OCI1                                 = 0xC0062D18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C3_SCOM                                 = 0x0006C4A3ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C3_SCOM1                                = 0x0006C5A3ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C4_OCI                                  = 0xC0062520ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C4_OCI1                                 = 0xC0062D20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C4_SCOM                                 = 0x0006C4A4ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C4_SCOM1                                = 0x0006C5A4ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C5_OCI                                  = 0xC0062528ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C5_OCI1                                 = 0xC0062D28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C5_SCOM                                 = 0x0006C4A5ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C5_SCOM1                                = 0x0006C5A5ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C6_OCI                                  = 0xC0062530ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C6_OCI1                                 = 0xC0062D30ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C6_SCOM                                 = 0x0006C4A6ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C6_SCOM1                                = 0x0006C5A6ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C7_OCI                                  = 0xC0062538ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C7_OCI1                                 = 0xC0062D38ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C7_SCOM                                 = 0x0006C4A7ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C7_SCOM1                                = 0x0006C5A7ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C8_OCI                                  = 0xC0062540ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C8_OCI1                                 = 0xC0062D40ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C8_SCOM                                 = 0x0006C4A8ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C8_SCOM1                                = 0x0006C5A8ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5C9_OCI                                  = 0xC0062548ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C9_OCI1                                 = 0xC0062D48ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C9_SCOM                                 = 0x0006C4A9ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5C9_SCOM1                                = 0x0006C5A9ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT5PRA_OCI                                 = 0xC0063500ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5PRA_OCI1                                = 0xC0063508ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5PRA_SCOM                                = 0x0006C6A0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT5PRA_SCOM1                               = 0x0006C6A1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6PRB_OCI                                 = 0xC0063600ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6PRB_OCI1                                = 0xC0063608ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6PRB_SCOM                                = 0x0006C6C0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6PRB_SCOM1                               = 0x0006C6C1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q0_OCI                                  = 0xC0062600ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q0_OCI1                                 = 0xC0062E00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q0_SCOM                                 = 0x0006C4C0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q0_SCOM1                                = 0x0006C5C0ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q1_OCI                                  = 0xC0062608ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q1_OCI1                                 = 0xC0062E08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q1_SCOM                                 = 0x0006C4C1ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q1_SCOM1                                = 0x0006C5C1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q2_OCI                                  = 0xC0062610ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q2_OCI1                                 = 0xC0062E10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q2_SCOM                                 = 0x0006C4C2ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q2_SCOM1                                = 0x0006C5C2ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q3_OCI                                  = 0xC0062618ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q3_OCI1                                 = 0xC0062E18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q3_SCOM                                 = 0x0006C4C3ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q3_SCOM1                                = 0x0006C5C3ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q4_OCI                                  = 0xC0062620ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q4_OCI1                                 = 0xC0062E20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q4_SCOM                                 = 0x0006C4C4ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q4_SCOM1                                = 0x0006C5C4ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q5_OCI                                  = 0xC0062628ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q5_OCI1                                 = 0xC0062E28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q5_SCOM                                 = 0x0006C4C5ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT6Q5_SCOM1                                = 0x0006C5C5ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7PRB_OCI                                 = 0xC0063700ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7PRB_OCI1                                = 0xC0063708ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7PRB_SCOM                                = 0x0006C6E0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7PRB_SCOM1                               = 0x0006C6E1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q0_OCI                                  = 0xC0062700ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q0_OCI1                                 = 0xC0062F00ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q0_SCOM                                 = 0x0006C4E0ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q0_SCOM1                                = 0x0006C5E0ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q1_OCI                                  = 0xC0062708ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q1_OCI1                                 = 0xC0062F08ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q1_SCOM                                 = 0x0006C4E1ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q1_SCOM1                                = 0x0006C5E1ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q2_OCI                                  = 0xC0062710ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q2_OCI1                                 = 0xC0062F10ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q2_SCOM                                 = 0x0006C4E2ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q2_SCOM1                                = 0x0006C5E2ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q3_OCI                                  = 0xC0062718ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q3_OCI1                                 = 0xC0062F18ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q3_SCOM                                 = 0x0006C4E3ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q3_SCOM1                                = 0x0006C5E3ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q4_OCI                                  = 0xC0062720ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q4_OCI1                                 = 0xC0062F20ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q4_SCOM                                 = 0x0006C4E4ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q4_SCOM1                                = 0x0006C5E4ull;


static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q5_OCI                                  = 0xC0062728ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q5_OCI1                                 = 0xC0062F28ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q5_SCOM                                 = 0x0006C4E5ull;

static const uint64_t P9N2_PU_OCB_OCI_OPIT7Q5_SCOM1                                = 0x0006C5E5ull;


static const uint64_t P9N2_PU_OCB_OCI_OTBR_OCI                                     = 0xC00604F8ull;

static const uint64_t P9N2_PU_OCB_OCI_OTBR_SCOM                                    = 0x0006C09Full;


static const uint64_t P9N2_PU_OCB_OCI_OTR0_OCI                                     = 0xC0060800ull;

static const uint64_t P9N2_PU_OCB_OCI_OTR0_SCOM                                    = 0x0006C100ull;


static const uint64_t P9N2_PU_OCB_OCI_OTR1_OCI                                     = 0xC0060808ull;

static const uint64_t P9N2_PU_OCB_OCI_OTR1_SCOM                                    = 0x0006C101ull;


static const uint64_t P9N2_PU_OCB_OCI_OUISR0_OCI                                   = 0xC0060310ull;

static const uint64_t P9N2_PU_OCB_OCI_OUISR0_SCOM                                  = 0x0006C062ull;


static const uint64_t P9N2_PU_OCB_OCI_OUISR1_OCI                                   = 0xC0060390ull;

static const uint64_t P9N2_PU_OCB_OCI_OUISR1_SCOM                                  = 0x0006C072ull;


static const uint64_t P9N2_PU_OCB_OCI_QCSR_OCI                                     = 0xC00604A0ull;

static const uint64_t P9N2_PU_OCB_OCI_QCSR_OCI1                                    = 0xC00604A8ull;

static const uint64_t P9N2_PU_OCB_OCI_QCSR_OCI2                                    = 0xC00604B0ull;

static const uint64_t P9N2_PU_OCB_OCI_QCSR_SCOM                                    = 0x0006C094ull;

static const uint64_t P9N2_PU_OCB_OCI_QCSR_SCOM1                                   = 0x0006C095ull;

static const uint64_t P9N2_PU_OCB_OCI_QCSR_SCOM2                                   = 0x0006C096ull;


static const uint64_t P9N2_PU_OCB_OCI_QSSR_OCI                                     = 0xC00604C0ull;

static const uint64_t P9N2_PU_OCB_OCI_QSSR_OCI1                                    = 0xC00604C8ull;

static const uint64_t P9N2_PU_OCB_OCI_QSSR_OCI2                                    = 0xC00604D0ull;

static const uint64_t P9N2_PU_OCB_OCI_QSSR_SCOM                                    = 0x0006C098ull;

static const uint64_t P9N2_PU_OCB_OCI_QSSR_SCOM1                                   = 0x0006C099ull;

static const uint64_t P9N2_PU_OCB_OCI_QSSR_SCOM2                                   = 0x0006C09Aull;


static const uint64_t P9N2_PU_OCB_PIB_OACR                                         = 0x0006D207ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBAR0                                       = 0x0006D010ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBAR1                                       = 0x0006D030ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBAR2                                       = 0x0006D050ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBAR3                                       = 0x0006D070ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBCSR0_RO                                   = 0x0006D011ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR0_CLEAR                                = 0x0006D012ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR0_OR                                   = 0x0006D013ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBCSR1_RO                                   = 0x0006D031ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR1_CLEAR                                = 0x0006D032ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR1_OR                                   = 0x0006D033ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBCSR2_RO                                   = 0x0006D051ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR2_CLEAR                                = 0x0006D052ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR2_OR                                   = 0x0006D053ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBCSR3_RO                                   = 0x0006D071ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR3_CLEAR                                = 0x0006D072ull;

static const uint64_t P9N2_PU_OCB_PIB_OCBCSR3_OR                                   = 0x0006D073ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBDR0                                       = 0x0006D015ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBDR1                                       = 0x0006D035ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBDR2                                       = 0x0006D055ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBDR3                                       = 0x0006D075ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBEAR                                       = 0x0006D210ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBESR0                                      = 0x0006D014ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBESR1                                      = 0x0006D034ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBESR2                                      = 0x0006D054ull;


static const uint64_t P9N2_PU_OCB_PIB_OCBESR3                                      = 0x0006D074ull;


static const uint64_t P9N2_PU_OCB_PIB_OCDBG                                        = 0x0006D003ull;


static const uint64_t P9N2_PU_OCB_PIB_OCR_RO                                       = 0x0006D000ull;

static const uint64_t P9N2_PU_OCB_PIB_OCR_CLEAR                                    = 0x0006D001ull;

static const uint64_t P9N2_PU_OCB_PIB_OCR_OR                                       = 0x0006D002ull;


static const uint64_t P9N2_PU_OCB_PIB_OEAR                                         = 0x0006D206ull;


static const uint64_t P9N2_PU_OCB_PIB_OESR                                         = 0x0006D204ull;


static const uint64_t P9N2_PU_OCB_PIB_OPPCINJ                                      = 0x0006D111ull;


static const uint64_t P9N2_PU_OCB_PIB_OREV                                         = 0x0006D202ull;


static const uint64_t P9N2_PU_OCB_PIB_OSTOEAR                                      = 0x0006D200ull;


static const uint64_t P9N2_PU_OCB_PIB_OSTOESR                                      = 0x0006D201ull;


static const uint64_t P9N2_PU_OCB_PIB_OTDCR                                        = 0x0006D110ull;


static const uint64_t P9N2_PEC_OPCG_ALIGN                                          = 0x0D030001ull;

static const uint64_t P9N2_PEC_0_OPCG_ALIGN                                        = 0x0D030001ull;

static const uint64_t P9N2_PEC_1_OPCG_ALIGN                                        = 0x0E030001ull;

static const uint64_t P9N2_PEC_2_OPCG_ALIGN                                        = 0x0F030001ull;


static const uint64_t P9N2_PEC_OPCG_CAPT1                                          = 0x0D030010ull;

static const uint64_t P9N2_PEC_0_OPCG_CAPT1                                        = 0x0D030010ull;

static const uint64_t P9N2_PEC_1_OPCG_CAPT1                                        = 0x0E030010ull;

static const uint64_t P9N2_PEC_2_OPCG_CAPT1                                        = 0x0F030010ull;


static const uint64_t P9N2_PEC_OPCG_CAPT2                                          = 0x0D030011ull;

static const uint64_t P9N2_PEC_0_OPCG_CAPT2                                        = 0x0D030011ull;

static const uint64_t P9N2_PEC_1_OPCG_CAPT2                                        = 0x0E030011ull;

static const uint64_t P9N2_PEC_2_OPCG_CAPT2                                        = 0x0F030011ull;


static const uint64_t P9N2_PEC_OPCG_CAPT3                                          = 0x0D030012ull;

static const uint64_t P9N2_PEC_0_OPCG_CAPT3                                        = 0x0D030012ull;

static const uint64_t P9N2_PEC_1_OPCG_CAPT3                                        = 0x0E030012ull;

static const uint64_t P9N2_PEC_2_OPCG_CAPT3                                        = 0x0F030012ull;


static const uint64_t P9N2_PEC_OPCG_REG0                                           = 0x0D030002ull;

static const uint64_t P9N2_PEC_0_OPCG_REG0                                         = 0x0D030002ull;

static const uint64_t P9N2_PEC_1_OPCG_REG0                                         = 0x0E030002ull;

static const uint64_t P9N2_PEC_2_OPCG_REG0                                         = 0x0F030002ull;


static const uint64_t P9N2_PEC_OPCG_REG1                                           = 0x0D030003ull;

static const uint64_t P9N2_PEC_0_OPCG_REG1                                         = 0x0D030003ull;

static const uint64_t P9N2_PEC_1_OPCG_REG1                                         = 0x0E030003ull;

static const uint64_t P9N2_PEC_2_OPCG_REG1                                         = 0x0F030003ull;


static const uint64_t P9N2_PEC_OPCG_REG2                                           = 0x0D030004ull;

static const uint64_t P9N2_PEC_0_OPCG_REG2                                         = 0x0D030004ull;

static const uint64_t P9N2_PEC_1_OPCG_REG2                                         = 0x0E030004ull;

static const uint64_t P9N2_PEC_2_OPCG_REG2                                         = 0x0F030004ull;


static const uint64_t P9N2__CTL_OPTICAL_IO_CONFIG                                  = 0x05011683ull;


static const uint64_t P9N2_PU_NPU_CTL_OTL_REM0                                     = 0x0501138Dull;

static const uint64_t P9N2_PU_NPU_SM2_OTL_REM0                                     = 0x0501135Dull;

static const uint64_t P9N2__CTL_OTL_REM0                                           = 0x0501158Dull;

static const uint64_t P9N2__SM2_OTL_REM0                                           = 0x0501155Dull;


static const uint64_t P9N2_NV_PA0_CONFIG                                           = 0x050110D4ull;

static const uint64_t P9N2_NV_0_PA0_CONFIG                                         = 0x050110D4ull;

static const uint64_t P9N2_NV_4_PA0_CONFIG                                         = 0x050114D4ull;

static const uint64_t P9N2_PU_NPU2_NTL0_PA0_CONFIG                                 = 0x050112D4ull;


static const uint64_t P9N2_NV_PA1_CONFIG                                           = 0x050110D5ull;

static const uint64_t P9N2_NV_0_PA1_CONFIG                                         = 0x050110D5ull;

static const uint64_t P9N2_NV_4_PA1_CONFIG                                         = 0x050114D5ull;

static const uint64_t P9N2_PU_NPU2_NTL0_PA1_CONFIG                                 = 0x050112D5ull;


static const uint64_t P9N2_PU_PBABAR0                                              = 0x05012B00ull;


static const uint64_t P9N2_PU_PBABAR1                                              = 0x05012B01ull;


static const uint64_t P9N2_PU_PBABAR2                                              = 0x05012B02ull;


static const uint64_t P9N2_PU_PBABAR3                                              = 0x05012B03ull;


static const uint64_t P9N2_PU_PBABARMSK0                                           = 0x05012B04ull;


static const uint64_t P9N2_PU_PBABARMSK1                                           = 0x05012B05ull;


static const uint64_t P9N2_PU_PBABARMSK2                                           = 0x05012B06ull;


static const uint64_t P9N2_PU_PBABARMSK3                                           = 0x05012B07ull;


static const uint64_t P9N2_PU_PBACFG                                               = 0x0501284Bull;


static const uint64_t P9N2_PU_PBAERRRPT0                                           = 0x0501284Cull;


static const uint64_t P9N2_PU_PBAERRRPT1                                           = 0x0501284Dull;


static const uint64_t P9N2_PU_PBAERRRPT2                                           = 0x0501284Eull;


static const uint64_t P9N2_PU_PBAFIR                                               = 0x05012840ull;

static const uint64_t P9N2_PU_PBAFIR_AND                                           = 0x05012841ull;

static const uint64_t P9N2_PU_PBAFIR_OR                                            = 0x05012842ull;


static const uint64_t P9N2_PU_PBAFIRACT0                                           = 0x05012846ull;


static const uint64_t P9N2_PU_PBAFIRACT1                                           = 0x05012847ull;


static const uint64_t P9N2_PU_PBAFIRMASK                                           = 0x05012843ull;

static const uint64_t P9N2_PU_PBAFIRMASK_AND                                       = 0x05012844ull;

static const uint64_t P9N2_PU_PBAFIRMASK_OR                                        = 0x05012845ull;


static const uint64_t P9N2_PEC_PBAIBHWCFG_REG                                      = 0x0D010800ull;

static const uint64_t P9N2_PEC_0_PBAIBHWCFG_REG                                    = 0x0D010800ull;

static const uint64_t P9N2_PEC_1_PBAIBHWCFG_REG                                    = 0x0E010800ull;

static const uint64_t P9N2_PEC_2_PBAIBHWCFG_REG                                    = 0x0F010800ull;


static const uint64_t P9N2_PHB_PBAIBTXCCR_REG                                      = 0x0D01084Dull;

static const uint64_t P9N2_PHB_0_PBAIBTXCCR_REG                                    = 0x0D01084Dull;

static const uint64_t P9N2_PHB_1_PBAIBTXCCR_REG                                    = 0x0E01084Dull;

static const uint64_t P9N2_PHB_2_PBAIBTXCCR_REG                                    = 0x0E01088Dull;

static const uint64_t P9N2_PHB_3_PBAIBTXCCR_REG                                    = 0x0F01084Dull;

static const uint64_t P9N2_PHB_4_PBAIBTXCCR_REG                                    = 0x0F01088Dull;

static const uint64_t P9N2_PHB_5_PBAIBTXCCR_REG                                    = 0x0F0108CDull;


static const uint64_t P9N2_PHB_PBAIBTXDCR_REG                                      = 0x0D01084Eull;

static const uint64_t P9N2_PHB_0_PBAIBTXDCR_REG                                    = 0x0D01084Eull;

static const uint64_t P9N2_PHB_1_PBAIBTXDCR_REG                                    = 0x0E01084Eull;

static const uint64_t P9N2_PHB_2_PBAIBTXDCR_REG                                    = 0x0E01088Eull;

static const uint64_t P9N2_PHB_3_PBAIBTXDCR_REG                                    = 0x0F01084Eull;

static const uint64_t P9N2_PHB_4_PBAIBTXDCR_REG                                    = 0x0F01088Eull;

static const uint64_t P9N2_PHB_5_PBAIBTXDCR_REG                                    = 0x0F0108CEull;


static const uint64_t P9N2_PHB_PBAIB_CERR_RPT_REG                                  = 0x0D01084Bull;

static const uint64_t P9N2_PHB_0_PBAIB_CERR_RPT_REG                                = 0x0D01084Bull;

static const uint64_t P9N2_PHB_1_PBAIB_CERR_RPT_REG                                = 0x0E01084Bull;

static const uint64_t P9N2_PHB_2_PBAIB_CERR_RPT_REG                                = 0x0E01088Bull;

static const uint64_t P9N2_PHB_3_PBAIB_CERR_RPT_REG                                = 0x0F01084Bull;

static const uint64_t P9N2_PHB_4_PBAIB_CERR_RPT_REG                                = 0x0F01088Bull;

static const uint64_t P9N2_PHB_5_PBAIB_CERR_RPT_REG                                = 0x0F0108CBull;


static const uint64_t P9N2_PU_PBAMODE_OCI                                          = 0xC0040000ull;

static const uint64_t P9N2_PU_PBAMODE_PIB                                          = 0x00068000ull;


static const uint64_t P9N2_PU_PBAOCCACT                                            = 0x0501284Aull;


static const uint64_t P9N2_PU_PBAPBOCR0_OCI                                        = 0xC00400D0ull;

static const uint64_t P9N2_PU_PBAPBOCR0_PIB                                        = 0x0006801Aull;


static const uint64_t P9N2_PU_PBAPBOCR1_OCI                                        = 0xC00400D8ull;

static const uint64_t P9N2_PU_PBAPBOCR1_PIB                                        = 0x0006801Bull;


static const uint64_t P9N2_PU_PBAPBOCR2_OCI                                        = 0xC00400E0ull;

static const uint64_t P9N2_PU_PBAPBOCR2_PIB                                        = 0x0006801Cull;


static const uint64_t P9N2_PU_PBAPBOCR3_OCI                                        = 0xC00400E8ull;

static const uint64_t P9N2_PU_PBAPBOCR3_PIB                                        = 0x0006801Dull;


static const uint64_t P9N2_PU_PBAPBOCR4_OCI                                        = 0xC00400F0ull;

static const uint64_t P9N2_PU_PBAPBOCR4_PIB                                        = 0x0006801Eull;


static const uint64_t P9N2_PU_PBAPBOCR5_OCI                                        = 0xC00400F8ull;

static const uint64_t P9N2_PU_PBAPBOCR5_PIB                                        = 0x0006801Full;


static const uint64_t P9N2_PU_PBARBUFVAL0                                          = 0x05012850ull;


static const uint64_t P9N2_PU_PBARBUFVAL1                                          = 0x05012851ull;


static const uint64_t P9N2_PU_PBARBUFVAL2                                          = 0x05012852ull;


static const uint64_t P9N2_PU_PBARBUFVAL3                                          = 0x05012853ull;


static const uint64_t P9N2_PU_PBARBUFVAL4                                          = 0x05012854ull;


static const uint64_t P9N2_PU_PBARBUFVAL5                                          = 0x05012855ull;


static const uint64_t P9N2_PU_PBASLVCTL0_OCI                                       = 0xC0040020ull;

static const uint64_t P9N2_PU_PBASLVCTL0_PIB                                       = 0x00068004ull;


static const uint64_t P9N2_PU_PBASLVCTL1_OCI                                       = 0xC0040028ull;

static const uint64_t P9N2_PU_PBASLVCTL1_PIB                                       = 0x00068005ull;


static const uint64_t P9N2_PU_PBASLVCTL2_OCI                                       = 0xC0040030ull;

static const uint64_t P9N2_PU_PBASLVCTL2_PIB                                       = 0x00068006ull;


static const uint64_t P9N2_PU_PBASLVCTL3_OCI                                       = 0xC0040038ull;

static const uint64_t P9N2_PU_PBASLVCTL3_PIB                                       = 0x00068007ull;


static const uint64_t P9N2_PU_PBASLVRST_OCI                                        = 0xC0040008ull;

static const uint64_t P9N2_PU_PBASLVRST_PIB                                        = 0x00068001ull;


static const uint64_t P9N2_PU_PBAWBUFVAL0                                          = 0x05012858ull;


static const uint64_t P9N2_PU_PBAWBUFVAL1                                          = 0x05012859ull;


static const uint64_t P9N2_PU_PBAXCFG_OCI                                          = 0xC0040108ull;

static const uint64_t P9N2_PU_PBAXCFG_PIB                                          = 0x00068021ull;


static const uint64_t P9N2_PU_PBAXRCVSTAT_OCI                                      = 0xC0040120ull;

static const uint64_t P9N2_PU_PBAXRCVSTAT_PIB                                      = 0x00068024ull;


static const uint64_t P9N2_PU_PBAXSHBR0_OCI                                        = 0xC0040130ull;

static const uint64_t P9N2_PU_PBAXSHBR0_PIB                                        = 0x00068026ull;


static const uint64_t P9N2_PU_PBAXSHBR1_OCI                                        = 0xC0040150ull;

static const uint64_t P9N2_PU_PBAXSHBR1_PIB                                        = 0x0006802Aull;


static const uint64_t P9N2_PU_PBAXSHCS0_OCI                                        = 0xC0040138ull;

static const uint64_t P9N2_PU_PBAXSHCS0_PIB                                        = 0x00068027ull;


static const uint64_t P9N2_PU_PBAXSHCS1_OCI                                        = 0xC0040158ull;

static const uint64_t P9N2_PU_PBAXSHCS1_PIB                                        = 0x0006802Bull;


static const uint64_t P9N2_PU_PBAXSHINC0_OCI                                       = 0xC0040140ull;

static const uint64_t P9N2_PU_PBAXSHINC0_PIB                                       = 0x00068028ull;


static const uint64_t P9N2_PU_PBAXSHINC1_OCI                                       = 0xC0040160ull;

static const uint64_t P9N2_PU_PBAXSHINC1_PIB                                       = 0x0006802Cull;


static const uint64_t P9N2_PU_PBAXSNDSTAT_OCI                                      = 0xC0040110ull;

static const uint64_t P9N2_PU_PBAXSNDSTAT_PIB                                      = 0x00068022ull;


static const uint64_t P9N2_PU_PBAXSNDTX_OCI                                        = 0xC0040100ull;

static const uint64_t P9N2_PU_PBAXSNDTX_PIB                                        = 0x00068020ull;


static const uint64_t P9N2_PEC_PBCQEINJ_REG                                        = 0x04010C02ull;

static const uint64_t P9N2_PEC_0_PBCQEINJ_REG                                      = 0x04010C02ull;

static const uint64_t P9N2_PEC_1_PBCQEINJ_REG                                      = 0x04011002ull;

static const uint64_t P9N2_PEC_2_PBCQEINJ_REG                                      = 0x04011402ull;


static const uint64_t P9N2_PEC_PBCQHWCFG_REG                                       = 0x04010C00ull;

static const uint64_t P9N2_PEC_0_PBCQHWCFG_REG                                     = 0x04010C00ull;

static const uint64_t P9N2_PEC_1_PBCQHWCFG_REG                                     = 0x04011000ull;

static const uint64_t P9N2_PEC_2_PBCQHWCFG_REG                                     = 0x04011400ull;


static const uint64_t P9N2_PEC_0_STACK0_PBCQMODE_REG                               = 0x04010C4Dull;

static const uint64_t P9N2_PEC_1_STACK0_PBCQMODE_REG                               = 0x0401104Dull;

static const uint64_t P9N2_PEC_1_STACK1_PBCQMODE_REG                               = 0x0401108Dull;

static const uint64_t P9N2_PEC_1_STACK2_PBCQMODE_REG                               = 0x040110CDull;

static const uint64_t P9N2_PEC_2_STACK0_PBCQMODE_REG                               = 0x0401144Dull;

static const uint64_t P9N2_PEC_2_STACK1_PBCQMODE_REG                               = 0x0401148Dull;

static const uint64_t P9N2_PEC_2_STACK2_PBCQMODE_REG                               = 0x040114CDull;

static const uint64_t P9N2_PEC_STACK0_PBCQMODE_REG                                 = 0x04010C4Dull;

static const uint64_t P9N2_PHB_PBCQMODE_REG                                        = 0x04010C4Dull;

static const uint64_t P9N2_PHB_0_PBCQMODE_REG                                      = 0x04010C4Dull;

static const uint64_t P9N2_PHB_1_PBCQMODE_REG                                      = 0x0401104Dull;

static const uint64_t P9N2_PHB_2_PBCQMODE_REG                                      = 0x0401108Dull;

static const uint64_t P9N2_PHB_3_PBCQMODE_REG                                      = 0x0401144Dull;

static const uint64_t P9N2_PHB_4_PBCQMODE_REG                                      = 0x0401148Dull;

static const uint64_t P9N2_PHB_5_PBCQMODE_REG                                      = 0x040114CDull;


static const uint64_t P9N2_PU_PBE_MAILBOX_00_REG                                   = 0x05013430ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_01_REG                                   = 0x05013431ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_10_REG                                   = 0x05013432ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_11_REG                                   = 0x05013433ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_20_REG                                   = 0x05013434ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_21_REG                                   = 0x05013435ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_30_REG                                   = 0x05013436ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_31_REG                                   = 0x05013437ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_40_REG                                   = 0x05013438ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_41_REG                                   = 0x05013439ull;


static const uint64_t P9N2_PU_PBE_MAILBOX_50_REG                                   = 0x0501343Aull;


static const uint64_t P9N2_PU_PBE_MAILBOX_51_REG                                   = 0x0501343Bull;


static const uint64_t P9N2_PU_PBE_MAILBOX_CTL_REG                                  = 0x0501342Eull;


static const uint64_t P9N2_PU_PBE_MAILBOX_DATA_REG                                 = 0x0501342Full;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_00_REG                               = 0x05013830ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_01_REG                               = 0x05013831ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_10_REG                               = 0x05013832ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_11_REG                               = 0x05013833ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_20_REG                               = 0x05013834ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_21_REG                               = 0x05013835ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_30_REG                               = 0x05013836ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_31_REG                               = 0x05013837ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_40_REG                               = 0x05013838ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_41_REG                               = 0x05013839ull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_50_REG                               = 0x0501383Aull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_51_REG                               = 0x0501383Bull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_60_REG                               = 0x0501383Cull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_61_REG                               = 0x0501383Dull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_70_REG                               = 0x0501383Eull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_71_REG                               = 0x0501383Full;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_CTL_REG                              = 0x0501382Eull;


static const uint64_t P9N2_PU_IOE_PBO_MAILBOX_DATA_REG                             = 0x0501382Full;


static const uint64_t P9N2_PU_PB_BOGUS_0D_REG                                      = 0x0501340Dull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_CNPME                            = 0x05011C13ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_CNPMW                            = 0x05011C14ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_CR_ERROR                         = 0x05011C2Cull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_EVENT_COMPA                      = 0x05011C17ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_EVENT_COMPB                      = 0x05011C18ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_EVENT_COMPX                      = 0x05011C19ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_EVENT_SEL                        = 0x05011C16ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_EXTDAT_COUNTER                   = 0x05011C25ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_ACTION0_REG                  = 0x05011C06ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_ACTION1_REG                  = 0x05011C07ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG                     = 0x05011C03ull;

static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_AND                 = 0x05011C04ull;

static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_OR                  = 0x05011C05ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_REG                          = 0x05011C00ull;

static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_REG_AND                      = 0x05011C01ull;

static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_FIR_REG_OR                       = 0x05011C02ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_GP_CMD_RATE_DP0                  = 0x05011C26ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_GP_CMD_RATE_DP1                  = 0x05011C27ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HPA_MODE_CURR                    = 0x05011C0Eull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HPA_MODE_NEXT                    = 0x05011C0Dull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HPX_MODE_CURR                    = 0x05011C10ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HPX_MODE_NEXT                    = 0x05011C0Full;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HP_MODE_CURR                     = 0x05011C0Cull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_HP_MODE_NEXT                     = 0x05011C0Bull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_LMPM_COUNTER                     = 0x05011C23ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_MODE                             = 0x05011C0Aull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_NMPM_COUNTER                     = 0x05011C22ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU0_CNPME_COUNTER               = 0x05011C1Aull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU0_CNPMW_COUNTER               = 0x05011C1Eull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU1_CNPME_COUNTER               = 0x05011C1Bull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU1_CNPMW_COUNTER               = 0x05011C1Full;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU2_CNPME_COUNTER               = 0x05011C1Cull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_PMU2_CNPMW_COUNTER               = 0x05011C20ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU3_CNPME_COUNTER               = 0x05011C1Dull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_PMU3_CNPMW_COUNTER               = 0x05011C21ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_PMU_PRESCALER                    = 0x05011C15ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_RCMD_INTDAT_COUNTER              = 0x05011C24ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_RGP_CMD_RATE_DP0                 = 0x05011C28ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_RGP_CMD_RATE_DP1                 = 0x05011C29ull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_SCONFIG_LOAD                     = 0x05011C11ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_SP_CMD_RATE_DP0                  = 0x05011C2Aull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_SP_CMD_RATE_DP1                  = 0x05011C2Bull;


static const uint64_t P9N2_PU_PB_CENT_SM0_PB_CENT_TRACE                            = 0x05011C12ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_UNUSED_2D                        = 0x05011C2Dull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_UNUSED_36                        = 0x05011C36ull;


static const uint64_t P9N2_PU_PB_CENT_SM1_PB_CENT_UNUSED_37                        = 0x05011C37ull;


static const uint64_t P9N2_PU_PB_CHGRATE_CFG                                       = 0x05012422ull;


static const uint64_t P9N2_PU_PB_CHGRATE_GP_DP0_HIST                               = 0x05012424ull;


static const uint64_t P9N2_PU_PB_CHGRATE_GP_DP1_HIST                               = 0x05012425ull;


static const uint64_t P9N2_PU_PB_CHGRATE_RNS_DP0_HIST                              = 0x05012428ull;


static const uint64_t P9N2_PU_PB_CHGRATE_RNS_DP1_HIST                              = 0x05012429ull;


static const uint64_t P9N2_PU_PB_CHGRATE_SCONFIG_LOAD                              = 0x05012423ull;


static const uint64_t P9N2_PU_PB_CHGRATE_VG_DP0_HIST                               = 0x05012426ull;


static const uint64_t P9N2_PU_PB_CHGRATE_VG_DP1_HIST                               = 0x05012427ull;


static const uint64_t P9N2_PU_PB_EAST_FIR_ACTION0_REG                              = 0x05012006ull;


static const uint64_t P9N2_PU_PB_EAST_FIR_ACTION1_REG                              = 0x05012007ull;


static const uint64_t P9N2_PU_PB_EAST_FIR_MASK_REG                                 = 0x05012003ull;

static const uint64_t P9N2_PU_PB_EAST_FIR_MASK_REG_AND                             = 0x05012004ull;

static const uint64_t P9N2_PU_PB_EAST_FIR_MASK_REG_OR                              = 0x05012005ull;


static const uint64_t P9N2_PU_PB_EAST_FIR_REG                                      = 0x05012000ull;

static const uint64_t P9N2_PU_PB_EAST_FIR_REG_AND                                  = 0x05012001ull;

static const uint64_t P9N2_PU_PB_EAST_FIR_REG_OR                                   = 0x05012002ull;


static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH0                                  = 0x05012013ull;

static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH0_AND                              = 0x05012014ull;

static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH0_OR                               = 0x05012015ull;


static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH1                                  = 0x05012016ull;

static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH1_AND                              = 0x05012017ull;

static const uint64_t P9N2_PU_PB_EAST_FW_SCRATCH1_OR                               = 0x05012018ull;


static const uint64_t P9N2_PU_PB_EAST_HPA_MODE_CURR                                = 0x0501200Eull;


static const uint64_t P9N2_PU_PB_EAST_HPA_MODE_NEXT                                = 0x0501200Dull;


static const uint64_t P9N2_PU_PB_EAST_HPX_MODE_CURR                                = 0x05012010ull;


static const uint64_t P9N2_PU_PB_EAST_HPX_MODE_NEXT                                = 0x0501200Full;


static const uint64_t P9N2_PU_PB_EAST_HP_MODE_CURR                                 = 0x0501200Cull;


static const uint64_t P9N2_PU_PB_EAST_HP_MODE_NEXT                                 = 0x0501200Bull;


static const uint64_t P9N2_PU_PB_EAST_MODE                                         = 0x0501200Aull;


static const uint64_t P9N2_PU_PB_EAST_SCONFIG_LOAD                                 = 0x05012011ull;


static const uint64_t P9N2_PU_PB_EAST_SPARE                                        = 0x05012012ull;


static const uint64_t P9N2_PU_PB_ELINK_DATA_01_CFG_REG                             = 0x05013410ull;


static const uint64_t P9N2_PU_PB_ELINK_DATA_23_CFG_REG                             = 0x05013411ull;


static const uint64_t P9N2_PU_PB_ELINK_DATA_45_CFG_REG                             = 0x05013412ull;


static const uint64_t P9N2_PU_PB_ELINK_DLY_0123_REG                                = 0x0501340Eull;


static const uint64_t P9N2_PU_PB_ELINK_DLY_45_REG                                  = 0x0501340Full;


static const uint64_t P9N2_PU_PB_ELINK_PMU0                                        = 0x0501341Bull;


static const uint64_t P9N2_PU_PB_ELINK_PMU1                                        = 0x0501341Cull;


static const uint64_t P9N2_PU_PB_ELINK_PMU2                                        = 0x0501341Dull;


static const uint64_t P9N2_PU_PB_ELINK_PMU3                                        = 0x0501341Eull;


static const uint64_t P9N2_PU_PB_ELINK_PMU4                                        = 0x0501341Full;


static const uint64_t P9N2_PU_PB_ELINK_PMU5                                        = 0x05013420ull;


static const uint64_t P9N2_PU_PB_ELINK_PMU6                                        = 0x05013421ull;


static const uint64_t P9N2_PU_PB_ELINK_PMU7                                        = 0x05013422ull;


static const uint64_t P9N2_PU_PB_ELINK_PMU_CTL_REG                                 = 0x0501341Aull;


static const uint64_t P9N2_PU_PB_ELINK_RT_DELAY_CTL_REG                            = 0x05013419ull;


static const uint64_t P9N2_PU_PB_ELINK_SYN_01_REG                                  = 0x05013414ull;


static const uint64_t P9N2_PU_PB_ELINK_SYN_23_REG                                  = 0x05013415ull;


static const uint64_t P9N2_PU_PB_ELINK_SYN_45_REG                                  = 0x05013416ull;


static const uint64_t P9N2_PU_PB_EN_DOB_ECC_ERR_REG                                = 0x05013418ull;

static const uint64_t P9N2_PU_IOE_PB_EN_DOB_ECC_ERR_REG                            = 0x05013818ull;


static const uint64_t P9N2_PU_PB_FM0123_ERR                                        = 0x05013425ull;

static const uint64_t P9N2_PU_IOE_PB_FM0123_ERR                                    = 0x05013825ull;


static const uint64_t P9N2_PU_IOE_PB_FM4567_ERR                                    = 0x05013826ull;


static const uint64_t P9N2_PU_PB_FM45_ERR                                          = 0x05013426ull;


static const uint64_t P9N2_PU_PB_FP01_CFG                                          = 0x0501340Aull;

static const uint64_t P9N2_PU_IOE_PB_FP01_CFG                                      = 0x0501380Aull;


static const uint64_t P9N2_PU_PB_FP23_CFG                                          = 0x0501340Bull;

static const uint64_t P9N2_PU_IOE_PB_FP23_CFG                                      = 0x0501380Bull;


static const uint64_t P9N2_PU_PB_FP45_CFG                                          = 0x0501340Cull;

static const uint64_t P9N2_PU_IOE_PB_FP45_CFG                                      = 0x0501380Cull;


static const uint64_t P9N2_PU_IOE_PB_FP67_CFG                                      = 0x0501380Dull;


static const uint64_t P9N2_PU_PB_IOE_FIR_ACTION0_REG                               = 0x05013406ull;


static const uint64_t P9N2_PU_PB_IOE_FIR_ACTION1_REG                               = 0x05013407ull;


static const uint64_t P9N2_PU_PB_IOE_FIR_MASK_REG                                  = 0x05013403ull;

static const uint64_t P9N2_PU_PB_IOE_FIR_MASK_REG_AND                              = 0x05013404ull;

static const uint64_t P9N2_PU_PB_IOE_FIR_MASK_REG_OR                               = 0x05013405ull;


static const uint64_t P9N2_PU_PB_IOE_FIR_REG                                       = 0x05013400ull;

static const uint64_t P9N2_PU_PB_IOE_FIR_REG_AND                                   = 0x05013401ull;

static const uint64_t P9N2_PU_PB_IOE_FIR_REG_OR                                    = 0x05013402ull;


static const uint64_t P9N2_PU_PB_IOE_FIR_WOF_REG                                   = 0x05013408ull;


static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_ACTION0_REG                           = 0x05013806ull;


static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_ACTION1_REG                           = 0x05013807ull;


static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_MASK_REG                              = 0x05013803ull;

static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_MASK_REG_AND                          = 0x05013804ull;

static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_MASK_REG_OR                           = 0x05013805ull;


static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_REG                                   = 0x05013800ull;

static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_REG_AND                               = 0x05013801ull;

static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_REG_OR                                = 0x05013802ull;


static const uint64_t P9N2_PU_IOE_PB_IOO_FIR_WOF_REG                               = 0x05013808ull;


static const uint64_t P9N2_PU_PB_MISC_CFG                                          = 0x05013423ull;

static const uint64_t P9N2_PU_IOE_PB_MISC_CFG                                      = 0x05013823ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DATA_01_CFG_REG                         = 0x05013810ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DATA_23_CFG_REG                         = 0x05013811ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DATA_45_CFG_REG                         = 0x05013812ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DATA_67_CFG_REG                         = 0x05013813ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DLY_0123_REG                            = 0x0501380Eull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_DLY_4567_REG                            = 0x0501380Full;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU0                                    = 0x0501381Bull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU1                                    = 0x0501381Cull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU2                                    = 0x0501381Dull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU3                                    = 0x0501381Eull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU4                                    = 0x0501381Full;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU5                                    = 0x05013820ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU6                                    = 0x05013821ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU7                                    = 0x05013822ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_PMU_CTL_REG                             = 0x0501381Aull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_RT_DELAY_CTL_REG                        = 0x05013819ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_SYN_01_REG                              = 0x05013814ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_SYN_23_REG                              = 0x05013815ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_SYN_45_REG                              = 0x05013816ull;


static const uint64_t P9N2_PU_IOE_PB_OLINK_SYN_67_REG                              = 0x05013817ull;


static const uint64_t P9N2_PU_PB_PERFTRACE_CFG_REG                                 = 0x05013429ull;

static const uint64_t P9N2_PU_IOE_PB_PERFTRACE_CFG_REG                             = 0x05013829ull;


static const uint64_t P9N2_PU_PB_PPE_BOGUS_16_REG                                  = 0x05012416ull;


static const uint64_t P9N2_PU_PB_PPE_LFIR                                          = 0x05012400ull;

static const uint64_t P9N2_PU_PB_PPE_LFIR_AND                                      = 0x05012401ull;

static const uint64_t P9N2_PU_PB_PPE_LFIR_OR                                       = 0x05012402ull;


static const uint64_t P9N2_PU_PB_PPE_LFIRACT0                                      = 0x05012406ull;


static const uint64_t P9N2_PU_PB_PPE_LFIRACT1                                      = 0x05012407ull;


static const uint64_t P9N2_PU_PB_PPE_LFIRMASK                                      = 0x05012403ull;

static const uint64_t P9N2_PU_PB_PPE_LFIRMASK_AND                                  = 0x05012404ull;

static const uint64_t P9N2_PU_PB_PPE_LFIRMASK_OR                                   = 0x05012405ull;


static const uint64_t P9N2_PU_PB_PPE_LFIRWOF                                       = 0x05012408ull;


static const uint64_t P9N2_PU_PB_PR0123_ERR                                        = 0x05013427ull;

static const uint64_t P9N2_PU_IOE_PB_PR0123_ERR                                    = 0x05013827ull;


static const uint64_t P9N2_PU_IOE_PB_PR4567_ERR                                    = 0x05013828ull;


static const uint64_t P9N2_PU_PB_PR45_ERR                                          = 0x05013428ull;


static const uint64_t P9N2_PU_PB_PSAVE_CFG                                         = 0x0501241Aull;


static const uint64_t P9N2_PU_PB_PSAVE_MON_CFG                                     = 0x0501241Bull;


static const uint64_t P9N2_PU_PB_PSAVE_X0EVN_HIST                                  = 0x0501241Cull;


static const uint64_t P9N2_PU_PB_PSAVE_X0ODD_HIST                                  = 0x0501241Dull;


static const uint64_t P9N2_PU_PB_PSAVE_X1EVN_HIST                                  = 0x0501241Eull;


static const uint64_t P9N2_PU_PB_PSAVE_X1ODD_HIST                                  = 0x0501241Full;


static const uint64_t P9N2_PU_PB_PSAVE_X2EVN_HIST                                  = 0x05012420ull;


static const uint64_t P9N2_PU_PB_PSAVE_X2ODD_HIST                                  = 0x05012421ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_0                                = 0x9000032005011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_1                                = 0x900002E105011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_2                                = 0x900002A205011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_3                                = 0x9000024305011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_4                                = 0x900000F405011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_5                                = 0x9000030505011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_6                                = 0x9000020605011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_7                                = 0x900002C705011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_8                                = 0x9000016805011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_9                                = 0x900002C905011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_A                                = 0x900000EA05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_B                                = 0x9000007B05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_C                                = 0x9000018C05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_D                                = 0x9000033D05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_E                                = 0x900000AE05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_CENT_F                                = 0x9000010F05011C11ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_EAST_0                                = 0x9000034005012011ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_EAST_1                                = 0x9000026105012011ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_EAST_2                                = 0x900000B205012011ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_EAST_3                                = 0x900000B305012011ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_WEST_0                                = 0x9000034005011811ull;


static const uint64_t P9N2_PU_PB_SERIAL_SCOM_WEST_1                                = 0x9000026105011811ull;


static const uint64_t P9N2_PU_PB_TRACE_CFG                                         = 0x05013424ull;

static const uint64_t P9N2_PU_IOE_PB_TRACE_CFG                                     = 0x05013824ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_ACTION0_REG                  = 0x05011806ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_ACTION1_REG                  = 0x05011807ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG                     = 0x05011803ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG_AND                 = 0x05011804ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_MASK_REG_OR                  = 0x05011805ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_REG                          = 0x05011800ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_REG_AND                      = 0x05011801ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FIR_REG_OR                       = 0x05011802ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH0                      = 0x05011813ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH0_AND                  = 0x05011814ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH0_OR                   = 0x05011815ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH1                      = 0x05011816ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH1_AND                  = 0x05011817ull;

static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_FW_SCRATCH1_OR                   = 0x05011818ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HPA_MODE_CURR                    = 0x0501180Eull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HPA_MODE_NEXT                    = 0x0501180Dull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HPX_MODE_CURR                    = 0x05011810ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HPX_MODE_NEXT                    = 0x0501180Full;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HP_MODE_CURR                     = 0x0501180Cull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_HP_MODE_NEXT                     = 0x0501180Bull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_MODE                             = 0x0501180Aull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_SCONFIG_LOAD                     = 0x05011811ull;


static const uint64_t P9N2_PU_PB_WEST_SM0_PB_WEST_SPARE                            = 0x05011812ull;


static const uint64_t P9N2_PEC_PCB_OPCG_GO                                         = 0x0D030020ull;

static const uint64_t P9N2_PEC_0_PCB_OPCG_GO                                       = 0x0D030020ull;

static const uint64_t P9N2_PEC_1_PCB_OPCG_GO                                       = 0x0E030020ull;

static const uint64_t P9N2_PEC_2_PCB_OPCG_GO                                       = 0x0F030020ull;


static const uint64_t P9N2_PEC_PCB_OPCG_STOP                                       = 0x0D030030ull;

static const uint64_t P9N2_PEC_0_PCB_OPCG_STOP                                     = 0x0D030030ull;

static const uint64_t P9N2_PEC_1_PCB_OPCG_STOP                                     = 0x0E030030ull;

static const uint64_t P9N2_PEC_2_PCB_OPCG_STOP                                     = 0x0F030030ull;


static const uint64_t P9N2_PEC_PCS_M1_CONTROL_REG                                  = 0x80000C010D010C3Full;

static const uint64_t P9N2_PEC_0_PCS_M1_CONTROL_REG                                = 0x80000C010D010C3Full;

static const uint64_t P9N2_PEC_1_PCS_M1_CONTROL_REG                                = 0x80000C010E010C3Full;

static const uint64_t P9N2_PEC_2_PCS_M1_CONTROL_REG                                = 0x80000C010F010C3Full;


static const uint64_t P9N2_PEC_PCS_M2_CONTROL_REG                                  = 0x80000C020D010C3Full;

static const uint64_t P9N2_PEC_0_PCS_M2_CONTROL_REG                                = 0x80000C020D010C3Full;

static const uint64_t P9N2_PEC_1_PCS_M2_CONTROL_REG                                = 0x80000C020E010C3Full;

static const uint64_t P9N2_PEC_2_PCS_M2_CONTROL_REG                                = 0x80000C020F010C3Full;


static const uint64_t P9N2_PEC_PCS_M3_CONTROL_REG                                  = 0x80000C030D010C3Full;

static const uint64_t P9N2_PEC_0_PCS_M3_CONTROL_REG                                = 0x80000C030D010C3Full;

static const uint64_t P9N2_PEC_1_PCS_M3_CONTROL_REG                                = 0x80000C030E010C3Full;

static const uint64_t P9N2_PEC_2_PCS_M3_CONTROL_REG                                = 0x80000C030F010C3Full;


static const uint64_t P9N2_PEC_PCS_M4_CONTROL_REG                                  = 0x80000C040D010C3Full;

static const uint64_t P9N2_PEC_0_PCS_M4_CONTROL_REG                                = 0x80000C040D010C3Full;

static const uint64_t P9N2_PEC_1_PCS_M4_CONTROL_REG                                = 0x80000C040E010C3Full;

static const uint64_t P9N2_PEC_2_PCS_M4_CONTROL_REG                                = 0x80000C040F010C3Full;


static const uint64_t P9N2_PEC_PCS_SYS_CONTROL_REG                                 = 0x80000C000D010C3Full;

static const uint64_t P9N2_PEC_0_PCS_SYS_CONTROL_REG                               = 0x80000C000D010C3Full;

static const uint64_t P9N2_PEC_1_PCS_SYS_CONTROL_REG                               = 0x80000C000E010C3Full;

static const uint64_t P9N2_PEC_2_PCS_SYS_CONTROL_REG                               = 0x80000C000F010C3Full;


static const uint64_t P9N2_PEC_PECAPP_CNTL_REG                                     = 0x04010C07ull;

static const uint64_t P9N2_PEC_0_PECAPP_CNTL_REG                                   = 0x04010C07ull;

static const uint64_t P9N2_PEC_1_PECAPP_CNTL_REG                                   = 0x04011007ull;

static const uint64_t P9N2_PEC_2_PECAPP_CNTL_REG                                   = 0x04011407ull;


static const uint64_t P9N2_PEC_PECAPP_SEC_BAR                                      = 0x0D010801ull;

static const uint64_t P9N2_PEC_0_PECAPP_SEC_BAR                                    = 0x0D010801ull;

static const uint64_t P9N2_PEC_1_PECAPP_SEC_BAR                                    = 0x0E010801ull;

static const uint64_t P9N2_PEC_2_PECAPP_SEC_BAR                                    = 0x0F010801ull;


static const uint64_t P9N2_PU_NPU0_CTL_PERF_ADDR_CONFIG                            = 0x05011080ull;

static const uint64_t P9N2_PU_NPU0_DAT_PERF_ADDR_CONFIG                            = 0x050110B0ull;

static const uint64_t P9N2_PU_NPU2_CTL_PERF_ADDR_CONFIG                            = 0x05011280ull;

static const uint64_t P9N2_PU_NPU2_DAT_PERF_ADDR_CONFIG                            = 0x050112B0ull;

static const uint64_t P9N2_PU_NPU0_SM1_PERF_ADDR_CONFIG                            = 0x05011020ull;

static const uint64_t P9N2_PU_NPU0_SM2_PERF_ADDR_CONFIG                            = 0x05011050ull;

static const uint64_t P9N2_PU_NPU2_SM1_PERF_ADDR_CONFIG                            = 0x05011220ull;

static const uint64_t P9N2_PU_NPU2_SM2_PERF_ADDR_CONFIG                            = 0x05011250ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_PERF_ADDR_CONFIG                         = 0x05011480ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_PERF_ADDR_CONFIG                         = 0x050114B0ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_PERF_ADDR_CONFIG                         = 0x05011420ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_PERF_ADDR_CONFIG                         = 0x05011450ull;


static const uint64_t P9N2_NV_PERF_CONFIG                                          = 0x050110C7ull;

static const uint64_t P9N2_NV_0_PERF_CONFIG                                        = 0x050110C7ull;

static const uint64_t P9N2_NV_4_PERF_CONFIG                                        = 0x050114C7ull;

static const uint64_t P9N2_PU_NPU0_CTL_PERF_CONFIG                                 = 0x0501109Full;

static const uint64_t P9N2_PU_NPU2_CTL_PERF_CONFIG                                 = 0x0501129Full;

static const uint64_t P9N2_PU_NPU0_SM0_PERF_CONFIG                                 = 0x0501100Full;

static const uint64_t P9N2_PU_NPU0_SM1_PERF_CONFIG                                 = 0x0501103Full;

static const uint64_t P9N2_PU_NPU0_SM3_PERF_CONFIG                                 = 0x0501106Full;

static const uint64_t P9N2_PU_NPU1_SM0_PERF_CONFIG                                 = 0x0501111Eull;

static const uint64_t P9N2_PU_NPU1_SM1_PERF_CONFIG                                 = 0x0501113Eull;

static const uint64_t P9N2_PU_NPU2_NTL0_PERF_CONFIG                                = 0x050112C7ull;

static const uint64_t P9N2_PU_NPU2_SM0_PERF_CONFIG                                 = 0x0501120Full;

static const uint64_t P9N2_PU_NPU2_SM1_PERF_CONFIG                                 = 0x0501123Full;

static const uint64_t P9N2_PU_NPU2_SM3_PERF_CONFIG                                 = 0x0501126Full;

static const uint64_t P9N2_PU_NPU_MSC_CTL_PERF_CONFIG                              = 0x0501149Full;

static const uint64_t P9N2_PU_NPU_MSC_SM0_PERF_CONFIG                              = 0x0501140Full;

static const uint64_t P9N2_PU_NPU_MSC_SM1_PERF_CONFIG                              = 0x0501143Full;

static const uint64_t P9N2_PU_NPU_MSC_SM3_PERF_CONFIG                              = 0x0501146Full;

static const uint64_t P9N2_PU_NPU_SM0_PERF_CONFIG                                  = 0x0501131Eull;

static const uint64_t P9N2_PU_NPU_SM1_PERF_CONFIG                                  = 0x0501133Eull;

static const uint64_t P9N2__SM0_PERF_CONFIG                                        = 0x0501151Eull;

static const uint64_t P9N2__SM1_PERF_CONFIG                                        = 0x0501153Eull;


static const uint64_t P9N2_NV_PERF_COUNT                                           = 0x050110C6ull;

static const uint64_t P9N2_NV_0_PERF_COUNT                                         = 0x050110C6ull;

static const uint64_t P9N2_NV_4_PERF_COUNT                                         = 0x050114C6ull;

static const uint64_t P9N2_PU_NPU1_SM0_PERF_COUNT                                  = 0x0501111Full;

static const uint64_t P9N2_PU_NPU1_SM1_PERF_COUNT                                  = 0x0501113Full;

static const uint64_t P9N2_PU_NPU2_NTL0_PERF_COUNT                                 = 0x050112C6ull;

static const uint64_t P9N2_PU_NPU_SM0_PERF_COUNT                                   = 0x0501131Full;

static const uint64_t P9N2_PU_NPU_SM1_PERF_COUNT                                   = 0x0501133Full;

static const uint64_t P9N2__SM0_PERF_COUNT                                         = 0x0501151Full;

static const uint64_t P9N2__SM1_PERF_COUNT                                         = 0x0501153Full;


static const uint64_t P9N2_NV_PERF_MASK_CONFIG                                     = 0x050110C5ull;

static const uint64_t P9N2_NV_0_PERF_MASK_CONFIG                                   = 0x050110C5ull;

static const uint64_t P9N2_NV_4_PERF_MASK_CONFIG                                   = 0x050114C5ull;

static const uint64_t P9N2_PU_NPU0_CTL_PERF_MASK_CONFIG                            = 0x05011082ull;

static const uint64_t P9N2_PU_NPU0_DAT_PERF_MASK_CONFIG                            = 0x050110B2ull;

static const uint64_t P9N2_PU_NPU2_DAT_PERF_MASK_CONFIG                            = 0x050112B2ull;

static const uint64_t P9N2_PU_NPU2_CTL_PERF_MASK_CONFIG                            = 0x05011282ull;

static const uint64_t P9N2_PU_NPU0_SM1_PERF_MASK_CONFIG                            = 0x05011022ull;

static const uint64_t P9N2_PU_NPU0_SM2_PERF_MASK_CONFIG                            = 0x05011052ull;

static const uint64_t P9N2_PU_NPU2_NTL0_PERF_MASK_CONFIG                           = 0x050112C5ull;

static const uint64_t P9N2_PU_NPU2_SM1_PERF_MASK_CONFIG                            = 0x05011222ull;

static const uint64_t P9N2_PU_NPU2_SM2_PERF_MASK_CONFIG                            = 0x05011252ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_PERF_MASK_CONFIG                         = 0x05011482ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_PERF_MASK_CONFIG                         = 0x050114B2ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_PERF_MASK_CONFIG                         = 0x05011422ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_PERF_MASK_CONFIG                         = 0x05011452ull;


static const uint64_t P9N2_NV_PERF_MATCH_CONFIG                                    = 0x050110C4ull;

static const uint64_t P9N2_NV_0_PERF_MATCH_CONFIG                                  = 0x050110C4ull;

static const uint64_t P9N2_NV_4_PERF_MATCH_CONFIG                                  = 0x050114C4ull;

static const uint64_t P9N2_PU_NPU0_CTL_PERF_MATCH_CONFIG                           = 0x05011081ull;

static const uint64_t P9N2_PU_NPU0_DAT_PERF_MATCH_CONFIG                           = 0x050110B1ull;

static const uint64_t P9N2_PU_NPU2_DAT_PERF_MATCH_CONFIG                           = 0x050112B1ull;

static const uint64_t P9N2_PU_NPU2_CTL_PERF_MATCH_CONFIG                           = 0x05011281ull;

static const uint64_t P9N2_PU_NPU0_SM1_PERF_MATCH_CONFIG                           = 0x05011021ull;

static const uint64_t P9N2_PU_NPU0_SM2_PERF_MATCH_CONFIG                           = 0x05011051ull;

static const uint64_t P9N2_PU_NPU2_NTL0_PERF_MATCH_CONFIG                          = 0x050112C4ull;

static const uint64_t P9N2_PU_NPU2_SM1_PERF_MATCH_CONFIG                           = 0x05011221ull;

static const uint64_t P9N2_PU_NPU2_SM2_PERF_MATCH_CONFIG                           = 0x05011251ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_PERF_MATCH_CONFIG                        = 0x05011481ull;

static const uint64_t P9N2_PU_NPU_MSC_DAT_PERF_MATCH_CONFIG                        = 0x050114B1ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_PERF_MATCH_CONFIG                        = 0x05011421ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_PERF_MATCH_CONFIG                        = 0x05011451ull;


static const uint64_t P9N2_PEC_PERTYBOCTL_REG                                      = 0x04010C0Bull;

static const uint64_t P9N2_PEC_0_PERTYBOCTL_REG                                    = 0x04010C0Bull;

static const uint64_t P9N2_PEC_1_PERTYBOCTL_REG                                    = 0x0401100Bull;

static const uint64_t P9N2_PEC_2_PERTYBOCTL_REG                                    = 0x0401140Bull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE0                                    = 0x050116D0ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE1                                    = 0x050116D1ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE10                                   = 0x050116DAull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE11                                   = 0x050116DBull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE12                                   = 0x050116DCull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE13                                   = 0x050116DDull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE14                                   = 0x050116DEull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE15                                   = 0x050116DFull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE2                                    = 0x050116D2ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE3                                    = 0x050116D3ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE4                                    = 0x050116D4ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE5                                    = 0x050116D5ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE6                                    = 0x050116D6ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE7                                    = 0x050116D7ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE8                                    = 0x050116D8ull;


static const uint64_t P9N2__NTL0_PESTB_ADDR_PE9                                    = 0x050116D9ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE0                                    = 0x050116C0ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE1                                    = 0x050116C1ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE10                                   = 0x050116CAull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE11                                   = 0x050116CBull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE12                                   = 0x050116CCull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE13                                   = 0x050116CDull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE14                                   = 0x050116CEull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE15                                   = 0x050116CFull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE2                                    = 0x050116C2ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE3                                    = 0x050116C3ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE4                                    = 0x050116C4ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE5                                    = 0x050116C5ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE6                                    = 0x050116C6ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE7                                    = 0x050116C7ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE8                                    = 0x050116C8ull;


static const uint64_t P9N2__NTL0_PESTB_DATA_PE9                                    = 0x050116C9ull;


static const uint64_t P9N2_PEC_0_STACK0_PE_DFREEZE_REG                             = 0x04010C55ull;

static const uint64_t P9N2_PEC_1_STACK0_PE_DFREEZE_REG                             = 0x04011055ull;

static const uint64_t P9N2_PEC_1_STACK1_PE_DFREEZE_REG                             = 0x04011095ull;

static const uint64_t P9N2_PEC_1_STACK2_PE_DFREEZE_REG                             = 0x040110D5ull;

static const uint64_t P9N2_PEC_2_STACK0_PE_DFREEZE_REG                             = 0x04011455ull;

static const uint64_t P9N2_PEC_2_STACK1_PE_DFREEZE_REG                             = 0x04011495ull;

static const uint64_t P9N2_PEC_2_STACK2_PE_DFREEZE_REG                             = 0x040114D5ull;

static const uint64_t P9N2_PEC_STACK0_PE_DFREEZE_REG                               = 0x04010C55ull;

static const uint64_t P9N2_PHB_PE_DFREEZE_REG                                      = 0x04010C55ull;

static const uint64_t P9N2_PHB_0_PE_DFREEZE_REG                                    = 0x04010C55ull;

static const uint64_t P9N2_PHB_1_PE_DFREEZE_REG                                    = 0x04011055ull;

static const uint64_t P9N2_PHB_2_PE_DFREEZE_REG                                    = 0x04011095ull;

static const uint64_t P9N2_PHB_3_PE_DFREEZE_REG                                    = 0x04011455ull;

static const uint64_t P9N2_PHB_4_PE_DFREEZE_REG                                    = 0x04011495ull;

static const uint64_t P9N2_PHB_5_PE_DFREEZE_REG                                    = 0x040114D5ull;


static const uint64_t P9N2_PHB_PFIRACTION0_REG                                     = 0x0D010846ull;

static const uint64_t P9N2_PHB_0_PFIRACTION0_REG                                   = 0x0D010846ull;

static const uint64_t P9N2_PHB_1_PFIRACTION0_REG                                   = 0x0E010846ull;

static const uint64_t P9N2_PHB_2_PFIRACTION0_REG                                   = 0x0E010886ull;

static const uint64_t P9N2_PHB_3_PFIRACTION0_REG                                   = 0x0F010846ull;

static const uint64_t P9N2_PHB_4_PFIRACTION0_REG                                   = 0x0F010886ull;

static const uint64_t P9N2_PHB_5_PFIRACTION0_REG                                   = 0x0F0108C6ull;


static const uint64_t P9N2_PHB_PFIRACTION1_REG                                     = 0x0D010847ull;

static const uint64_t P9N2_PHB_0_PFIRACTION1_REG                                   = 0x0D010847ull;

static const uint64_t P9N2_PHB_1_PFIRACTION1_REG                                   = 0x0E010847ull;

static const uint64_t P9N2_PHB_2_PFIRACTION1_REG                                   = 0x0E010887ull;

static const uint64_t P9N2_PHB_3_PFIRACTION1_REG                                   = 0x0F010847ull;

static const uint64_t P9N2_PHB_4_PFIRACTION1_REG                                   = 0x0F010887ull;

static const uint64_t P9N2_PHB_5_PFIRACTION1_REG                                   = 0x0F0108C7ull;


static const uint64_t P9N2_PHB_PFIRMASK_REG                                        = 0x0D010843ull;

static const uint64_t P9N2_PHB_PFIRMASK_REG_AND                                    = 0x0D010844ull;

static const uint64_t P9N2_PHB_PFIRMASK_REG_OR                                     = 0x0D010845ull;

static const uint64_t P9N2_PHB_0_PFIRMASK_REG                                      = 0x0D010843ull;

static const uint64_t P9N2_PHB_0_PFIRMASK_REG_AND                                  = 0x0D010844ull;

static const uint64_t P9N2_PHB_0_PFIRMASK_REG_OR                                   = 0x0D010845ull;

static const uint64_t P9N2_PHB_1_PFIRMASK_REG                                      = 0x0E010843ull;

static const uint64_t P9N2_PHB_1_PFIRMASK_REG_AND                                  = 0x0E010844ull;

static const uint64_t P9N2_PHB_1_PFIRMASK_REG_OR                                   = 0x0E010845ull;

static const uint64_t P9N2_PHB_2_PFIRMASK_REG                                      = 0x0E010883ull;

static const uint64_t P9N2_PHB_2_PFIRMASK_REG_AND                                  = 0x0E010884ull;

static const uint64_t P9N2_PHB_2_PFIRMASK_REG_OR                                   = 0x0E010885ull;

static const uint64_t P9N2_PHB_3_PFIRMASK_REG                                      = 0x0F010843ull;

static const uint64_t P9N2_PHB_3_PFIRMASK_REG_AND                                  = 0x0F010844ull;

static const uint64_t P9N2_PHB_3_PFIRMASK_REG_OR                                   = 0x0F010845ull;

static const uint64_t P9N2_PHB_4_PFIRMASK_REG                                      = 0x0F010883ull;

static const uint64_t P9N2_PHB_4_PFIRMASK_REG_AND                                  = 0x0F010884ull;

static const uint64_t P9N2_PHB_4_PFIRMASK_REG_OR                                   = 0x0F010885ull;

static const uint64_t P9N2_PHB_5_PFIRMASK_REG                                      = 0x0F0108C3ull;

static const uint64_t P9N2_PHB_5_PFIRMASK_REG_AND                                  = 0x0F0108C4ull;

static const uint64_t P9N2_PHB_5_PFIRMASK_REG_OR                                   = 0x0F0108C5ull;


static const uint64_t P9N2_PHB_PFIRWOF_REG                                         = 0x0D010848ull;

static const uint64_t P9N2_PHB_0_PFIRWOF_REG                                       = 0x0D010848ull;

static const uint64_t P9N2_PHB_1_PFIRWOF_REG                                       = 0x0E010848ull;

static const uint64_t P9N2_PHB_2_PFIRWOF_REG                                       = 0x0E010888ull;

static const uint64_t P9N2_PHB_3_PFIRWOF_REG                                       = 0x0F010848ull;

static const uint64_t P9N2_PHB_4_PFIRWOF_REG                                       = 0x0F010888ull;

static const uint64_t P9N2_PHB_5_PFIRWOF_REG                                       = 0x0F0108C8ull;


static const uint64_t P9N2_PHB_PFIR_REG                                            = 0x0D010840ull;

static const uint64_t P9N2_PHB_PFIR_REG_AND                                        = 0x0D010841ull;

static const uint64_t P9N2_PHB_PFIR_REG_OR                                         = 0x0D010842ull;

static const uint64_t P9N2_PHB_0_PFIR_REG                                          = 0x0D010840ull;

static const uint64_t P9N2_PHB_0_PFIR_REG_AND                                      = 0x0D010841ull;

static const uint64_t P9N2_PHB_0_PFIR_REG_OR                                       = 0x0D010842ull;

static const uint64_t P9N2_PHB_1_PFIR_REG                                          = 0x0E010840ull;

static const uint64_t P9N2_PHB_1_PFIR_REG_AND                                      = 0x0E010841ull;

static const uint64_t P9N2_PHB_1_PFIR_REG_OR                                       = 0x0E010842ull;

static const uint64_t P9N2_PHB_2_PFIR_REG                                          = 0x0E010880ull;

static const uint64_t P9N2_PHB_2_PFIR_REG_AND                                      = 0x0E010881ull;

static const uint64_t P9N2_PHB_2_PFIR_REG_OR                                       = 0x0E010882ull;

static const uint64_t P9N2_PHB_3_PFIR_REG                                          = 0x0F010840ull;

static const uint64_t P9N2_PHB_3_PFIR_REG_AND                                      = 0x0F010841ull;

static const uint64_t P9N2_PHB_3_PFIR_REG_OR                                       = 0x0F010842ull;

static const uint64_t P9N2_PHB_4_PFIR_REG                                          = 0x0F010880ull;

static const uint64_t P9N2_PHB_4_PFIR_REG_AND                                      = 0x0F010881ull;

static const uint64_t P9N2_PHB_4_PFIR_REG_OR                                       = 0x0F010882ull;

static const uint64_t P9N2_PHB_5_PFIR_REG                                          = 0x0F0108C0ull;

static const uint64_t P9N2_PHB_5_PFIR_REG_AND                                      = 0x0F0108C1ull;

static const uint64_t P9N2_PHB_5_PFIR_REG_OR                                       = 0x0F0108C2ull;


static const uint64_t P9N2_PHB_PHB4_SCOM_HVIAR                                     = 0x0D010900ull;

static const uint64_t P9N2_PHB_0_PHB4_SCOM_HVIAR                                   = 0x0D010900ull;

static const uint64_t P9N2_PHB_1_PHB4_SCOM_HVIAR                                   = 0x0E010900ull;

static const uint64_t P9N2_PHB_2_PHB4_SCOM_HVIAR                                   = 0x0E010940ull;

static const uint64_t P9N2_PHB_3_PHB4_SCOM_HVIAR                                   = 0x0F010900ull;

static const uint64_t P9N2_PHB_4_PHB4_SCOM_HVIAR                                   = 0x0F010940ull;

static const uint64_t P9N2_PHB_5_PHB4_SCOM_HVIAR                                   = 0x0F010980ull;


static const uint64_t P9N2_PHB_PHB4_SCOM_UV_SEC_EXCL                               = 0x0D010904ull;

static const uint64_t P9N2_PHB_0_PHB4_SCOM_UV_SEC_EXCL                             = 0x0D010904ull;

static const uint64_t P9N2_PHB_1_PHB4_SCOM_UV_SEC_EXCL                             = 0x0E010904ull;

static const uint64_t P9N2_PHB_2_PHB4_SCOM_UV_SEC_EXCL                             = 0x0E010944ull;

static const uint64_t P9N2_PHB_3_PHB4_SCOM_UV_SEC_EXCL                             = 0x0F010904ull;

static const uint64_t P9N2_PHB_4_PHB4_SCOM_UV_SEC_EXCL                             = 0x0F010944ull;

static const uint64_t P9N2_PHB_5_PHB4_SCOM_UV_SEC_EXCL                             = 0x0F010984ull;


static const uint64_t P9N2_PHB_PHB4_SCOM_UV_SEC_INCL_CMP                           = 0x0D010906ull;

static const uint64_t P9N2_PHB_0_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0D010906ull;

static const uint64_t P9N2_PHB_1_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0E010906ull;

static const uint64_t P9N2_PHB_2_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0E010946ull;

static const uint64_t P9N2_PHB_3_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0F010906ull;

static const uint64_t P9N2_PHB_4_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0F010946ull;

static const uint64_t P9N2_PHB_5_PHB4_SCOM_UV_SEC_INCL_CMP                         = 0x0F010986ull;


static const uint64_t P9N2_PHB_PHB4_SCOM_UV_SEC_INCL_MSK                           = 0x0D010907ull;

static const uint64_t P9N2_PHB_0_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0D010907ull;

static const uint64_t P9N2_PHB_1_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0E010907ull;

static const uint64_t P9N2_PHB_2_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0E010947ull;

static const uint64_t P9N2_PHB_3_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0F010907ull;

static const uint64_t P9N2_PHB_4_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0F010947ull;

static const uint64_t P9N2_PHB_5_PHB4_SCOM_UV_SEC_INCL_MSK                         = 0x0F010987ull;


static const uint64_t P9N2_PEC_0_STACK0_PHBBAR_REG                                 = 0x04010C52ull;

static const uint64_t P9N2_PEC_1_STACK0_PHBBAR_REG                                 = 0x04011052ull;

static const uint64_t P9N2_PEC_1_STACK1_PHBBAR_REG                                 = 0x04011092ull;

static const uint64_t P9N2_PEC_1_STACK2_PHBBAR_REG                                 = 0x040110D2ull;

static const uint64_t P9N2_PEC_2_STACK0_PHBBAR_REG                                 = 0x04011452ull;

static const uint64_t P9N2_PEC_2_STACK1_PHBBAR_REG                                 = 0x04011492ull;

static const uint64_t P9N2_PEC_2_STACK2_PHBBAR_REG                                 = 0x040114D2ull;

static const uint64_t P9N2_PEC_STACK0_PHBBAR_REG                                   = 0x04010C52ull;

static const uint64_t P9N2_PHB_PHBBAR_REG                                          = 0x04010C52ull;

static const uint64_t P9N2_PHB_0_PHBBAR_REG                                        = 0x04010C52ull;

static const uint64_t P9N2_PHB_1_PHBBAR_REG                                        = 0x04011052ull;

static const uint64_t P9N2_PHB_2_PHBBAR_REG                                        = 0x04011092ull;

static const uint64_t P9N2_PHB_3_PHBBAR_REG                                        = 0x04011452ull;

static const uint64_t P9N2_PHB_4_PHBBAR_REG                                        = 0x04011492ull;

static const uint64_t P9N2_PHB_5_PHBBAR_REG                                        = 0x040114D2ull;


static const uint64_t P9N2_PHB_PHBRESET_REG                                        = 0x0D01084Aull;

static const uint64_t P9N2_PHB_0_PHBRESET_REG                                      = 0x0D01084Aull;

static const uint64_t P9N2_PHB_1_PHBRESET_REG                                      = 0x0E01084Aull;

static const uint64_t P9N2_PHB_2_PHBRESET_REG                                      = 0x0E01088Aull;

static const uint64_t P9N2_PHB_3_PHBRESET_REG                                      = 0x0F01084Aull;

static const uint64_t P9N2_PHB_4_PHBRESET_REG                                      = 0x0F01088Aull;

static const uint64_t P9N2_PHB_5_PHBRESET_REG                                      = 0x0F0108CAull;


static const uint64_t P9N2_PU_NPU0_CTL_PHY_BAR                                     = 0x05011096ull;

static const uint64_t P9N2_PU_NPU2_CTL_PHY_BAR                                     = 0x05011296ull;

static const uint64_t P9N2_PU_NPU0_SM0_PHY_BAR                                     = 0x05011006ull;

static const uint64_t P9N2_PU_NPU0_SM1_PHY_BAR                                     = 0x05011036ull;

static const uint64_t P9N2_PU_NPU0_SM3_PHY_BAR                                     = 0x05011066ull;

static const uint64_t P9N2_PU_NPU2_SM0_PHY_BAR                                     = 0x05011206ull;

static const uint64_t P9N2_PU_NPU2_SM1_PHY_BAR                                     = 0x05011236ull;

static const uint64_t P9N2_PU_NPU2_SM3_PHY_BAR                                     = 0x05011266ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_PHY_BAR                                  = 0x05011496ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_PHY_BAR                                  = 0x05011406ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_PHY_BAR                                  = 0x05011436ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_PHY_BAR                                  = 0x05011466ull;


static const uint64_t P9N2_PU_PIBI2CM_ATOMIC_LOCK_REG_B                            = 0x000A03FFull;


static const uint64_t P9N2_PU_PIBI2CM_ATOMIC_LOCK_REG_C                            = 0x000A13FFull;


static const uint64_t P9N2_PU_PIBI2CM_ATOMIC_LOCK_REG_D                            = 0x000A23FFull;


static const uint64_t P9N2_PU_PIBI2CM_ATOMIC_LOCK_REG_E                            = 0x000A33FFull;


static const uint64_t P9N2_PU_PIBI2CM_PROTECT_MODE_REG_B                           = 0x000A03FEull;


static const uint64_t P9N2_PU_PIBI2CM_PROTECT_MODE_REG_C                           = 0x000A13FEull;


static const uint64_t P9N2_PU_PIBI2CM_PROTECT_MODE_REG_D                           = 0x000A23FEull;


static const uint64_t P9N2_PU_PIBI2CM_PROTECT_MODE_REG_E                           = 0x000A33FEull;


static const uint64_t P9N2_PU_PIBMEM_ADDRESS_REGISTER                              = 0x00088001ull;


static const uint64_t P9N2_PU_PIBMEM_ADDRESS_REGISTER_FA                           = 0x00088007ull;


static const uint64_t P9N2_PU_PIBMEM_CONTROL_REGISTER                              = 0x00088000ull;


static const uint64_t P9N2_PU_PIBMEM_REPAIR_REGISTER_0                             = 0x0008800Bull;


static const uint64_t P9N2_PU_PIBMEM_REPAIR_REGISTER_1                             = 0x0008800Cull;


static const uint64_t P9N2_PU_PIBMEM_REPAIR_REGISTER_2                             = 0x0008800Dull;


static const uint64_t P9N2_PU_PIBMEM_REPAIR_REGISTER_3                             = 0x0008800Eull;


static const uint64_t P9N2_PU_PIBMEM_RESET_REGISTER                                = 0x00088006ull;


static const uint64_t P9N2_PU_PIBMEM_STATUS_REG                                    = 0x00088005ull;


static const uint64_t P9N2_PU_PIB_CMD_REG                                          = 0x00090031ull;


static const uint64_t P9N2_PU_PIB_DATA_REG                                         = 0x00090032ull;


static const uint64_t P9N2_PU_PIB_RESET_REG                                        = 0x00090033ull;


static const uint64_t P9N2_PEC_PLL_LOCK_REG                                        = 0x0D0F0019ull;

static const uint64_t P9N2_PEC_0_PLL_LOCK_REG                                      = 0x0D0F0019ull;

static const uint64_t P9N2_PEC_1_PLL_LOCK_REG                                      = 0x0E0F0019ull;

static const uint64_t P9N2_PEC_2_PLL_LOCK_REG                                      = 0x0F0F0019ull;


static const uint64_t P9N2_PEC_PMONCTL_REG                                         = 0x04010C04ull;

static const uint64_t P9N2_PEC_0_PMONCTL_REG                                       = 0x04010C04ull;

static const uint64_t P9N2_PEC_1_PMONCTL_REG                                       = 0x04011004ull;

static const uint64_t P9N2_PEC_2_PMONCTL_REG                                       = 0x04011404ull;


static const uint64_t P9N2_CAPP_PMU_CNTRA_CFG                                      = 0x02010814ull;

static const uint64_t P9N2_CAPP_0_PMU_CNTRA_CFG                                    = 0x02010814ull;

static const uint64_t P9N2_CAPP_1_PMU_CNTRA_CFG                                    = 0x04010814ull;


static const uint64_t P9N2_CAPP_PMU_CNTRA_REG                                      = 0x02010815ull;

static const uint64_t P9N2_CAPP_0_PMU_CNTRA_REG                                    = 0x02010815ull;

static const uint64_t P9N2_CAPP_1_PMU_CNTRA_REG                                    = 0x04010815ull;


static const uint64_t P9N2_CAPP_PMU_CNTRB_CFG                                      = 0x02010824ull;

static const uint64_t P9N2_CAPP_0_PMU_CNTRB_CFG                                    = 0x02010824ull;

static const uint64_t P9N2_CAPP_1_PMU_CNTRB_CFG                                    = 0x04010824ull;


static const uint64_t P9N2_CAPP_PMU_CNTRB_REG                                      = 0x02010825ull;

static const uint64_t P9N2_CAPP_0_PMU_CNTRB_REG                                    = 0x02010825ull;

static const uint64_t P9N2_CAPP_1_PMU_CNTRB_REG                                    = 0x04010825ull;


static const uint64_t P9N2_PU_NPU_CTL_PMU_CONTROL0                                 = 0x05011382ull;

static const uint64_t P9N2_PU_NPU_NTL0_PMU_CONTROL0                                = 0x050113C9ull;

static const uint64_t P9N2_PU_NPU_SM2_PMU_CONTROL0                                 = 0x05011352ull;

static const uint64_t P9N2__CTL_PMU_CONTROL0                                       = 0x05011582ull;

static const uint64_t P9N2__NTL0_PMU_CONTROL0                                      = 0x050115C9ull;

static const uint64_t P9N2__SM2_PMU_CONTROL0                                       = 0x05011552ull;


static const uint64_t P9N2_PU_NPU_CTL_PMU_CONTROL1                                 = 0x05011383ull;

static const uint64_t P9N2_PU_NPU_SM2_PMU_CONTROL1                                 = 0x05011353ull;

static const uint64_t P9N2__CTL_PMU_CONTROL1                                       = 0x05011583ull;

static const uint64_t P9N2__SM2_PMU_CONTROL1                                       = 0x05011553ull;


static const uint64_t P9N2_PU_NPU_CTL_PMU_CONTROL2                                 = 0x05011384ull;

static const uint64_t P9N2_PU_NPU_SM2_PMU_CONTROL2                                 = 0x05011354ull;

static const uint64_t P9N2__CTL_PMU_CONTROL2                                       = 0x05011584ull;

static const uint64_t P9N2__SM2_PMU_CONTROL2                                       = 0x05011554ull;


static const uint64_t P9N2_PU_NPU_CTL_PMU_COUNT                                    = 0x05011385ull;

static const uint64_t P9N2_PU_NPU_NTL0_PMU_COUNT                                   = 0x050113CAull;

static const uint64_t P9N2_PU_NPU_SM2_PMU_COUNT                                    = 0x05011355ull;

static const uint64_t P9N2__CTL_PMU_COUNT                                          = 0x05011585ull;

static const uint64_t P9N2__NTL0_PMU_COUNT                                         = 0x050115CAull;

static const uint64_t P9N2__SM2_PMU_COUNT                                          = 0x05011555ull;


static const uint64_t P9N2_PU_PPE_FIR_ACTION0_REG                                  = 0x0C011046ull;
//DUPS: 0C011046,

static const uint64_t P9N2_PU_PPE_FIR_ACTION1_REG                                  = 0x0C011047ull;
//DUPS: 0C011047,

static const uint64_t P9N2_PU_PPE_FIR_MASK_REG                                     = 0x0C011043ull;
//DUPS: 0C011043,
static const uint64_t P9N2_PU_PPE_FIR_MASK_REG_AND                                 = 0x0C011044ull;
//DUPS: 0C011044,
static const uint64_t P9N2_PU_PPE_FIR_MASK_REG_OR                                  = 0x0C011045ull;
//DUPS: 0C011045,

static const uint64_t P9N2_PU_PPE_FIR_REG                                          = 0x0C011040ull;
//DUPS: 0C011040,
static const uint64_t P9N2_PU_PPE_FIR_REG_AND                                      = 0x0C011041ull;
//DUPS: 0C011041,
static const uint64_t P9N2_PU_PPE_FIR_REG_OR                                       = 0x0C011042ull;
//DUPS: 0C011042,

static const uint64_t P9N2_PU_PPE_FIR_WOF_REG                                      = 0x0C011048ull;
//DUPS: 0C011048,

static const uint64_t P9N2_PU_PPE_XIDBGPRO                                         = 0x000E0005ull;
//DUPS: 05012415, 09011055, 0C011055,

static const uint64_t P9N2_PU_PPE_XIRAMDBG                                         = 0x000E0003ull;
//DUPS: 05012413, 09011053, 0C011053,

static const uint64_t P9N2_PU_PPE_XIRAMEDR                                         = 0x000E0004ull;
//DUPS: 05012414, 09011054, 0C011054,

static const uint64_t P9N2_PU_PPE_XIRAMGA                                          = 0x000E0002ull;
//DUPS: 05012412, 09011052, 0C011052,

static const uint64_t P9N2_PU_PPE_XIRAMRA                                          = 0x000E0001ull;
//DUPS: 05012411, 09011051, 0C011051,

static const uint64_t P9N2_PU_PPE_XIXCR                                            = 0x000E0000ull;
//DUPS: 05012410, 09011050, 0C011050,

static const uint64_t P9N2_PU_NPU1_SM1_PRB_HA_PTR                                  = 0x05011121ull;

static const uint64_t P9N2_PU_NPU1_SM2_PRB_HA_PTR                                  = 0x05011141ull;

static const uint64_t P9N2_PU_NPU_SM1_PRB_HA_PTR                                   = 0x05011321ull;

static const uint64_t P9N2_PU_NPU_SM2_PRB_HA_PTR                                   = 0x05011341ull;

static const uint64_t P9N2__SM1_PRB_HA_PTR                                         = 0x05011521ull;

static const uint64_t P9N2__SM2_PRB_HA_PTR                                         = 0x05011541ull;


static const uint64_t P9N2_PEC_PRDSTKOVR_REG                                       = 0x0D010802ull;

static const uint64_t P9N2_PEC_0_PRDSTKOVR_REG                                     = 0x0D010802ull;

static const uint64_t P9N2_PEC_1_PRDSTKOVR_REG                                     = 0x0E010802ull;

static const uint64_t P9N2_PEC_2_PRDSTKOVR_REG                                     = 0x0F010802ull;


static const uint64_t P9N2_PEC_PREDV_REG                                           = 0x04010C06ull;

static const uint64_t P9N2_PEC_0_PREDV_REG                                         = 0x04010C06ull;

static const uint64_t P9N2_PEC_1_PREDV_REG                                         = 0x04011006ull;

static const uint64_t P9N2_PEC_2_PREDV_REG                                         = 0x04011406ull;


static const uint64_t P9N2_PEC_PRE_COUNTER_REG                                     = 0x0D0F0028ull;

static const uint64_t P9N2_PEC_0_PRE_COUNTER_REG                                   = 0x0D0F0028ull;

static const uint64_t P9N2_PEC_1_PRE_COUNTER_REG                                   = 0x0E0F0028ull;

static const uint64_t P9N2_PEC_2_PRE_COUNTER_REG                                   = 0x0F0F0028ull;


static const uint64_t P9N2_PU_PRGM_REGISTER                                        = 0x00010009ull;


static const uint64_t P9N2_PEC_PRIMARY_ADDRESS_REG                                 = 0x0D0F0000ull;

static const uint64_t P9N2_PEC_0_PRIMARY_ADDRESS_REG                               = 0x0D0F0000ull;

static const uint64_t P9N2_PEC_1_PRIMARY_ADDRESS_REG                               = 0x0E0F0000ull;

static const uint64_t P9N2_PEC_2_PRIMARY_ADDRESS_REG                               = 0x0F0F0000ull;


static const uint64_t P9N2_PU_NPU1_SM1_PRI_CONFIG                                  = 0x05011126ull;

static const uint64_t P9N2_PU_NPU1_SM2_PRI_CONFIG                                  = 0x05011146ull;

static const uint64_t P9N2_PU_NPU_SM1_PRI_CONFIG                                   = 0x05011326ull;

static const uint64_t P9N2_PU_NPU_SM2_PRI_CONFIG                                   = 0x05011346ull;

static const uint64_t P9N2__SM1_PRI_CONFIG                                         = 0x05011526ull;

static const uint64_t P9N2__SM2_PRI_CONFIG                                         = 0x05011546ull;


static const uint64_t P9N2_PU_PROBE_PROTECT_STATUS                                 = 0x0001000Aull;


static const uint64_t P9N2_PEC_PROTECT_MODE_REG                                    = 0x0D0F03FEull;

static const uint64_t P9N2_PEC_0_PROTECT_MODE_REG                                  = 0x0D0F03FEull;

static const uint64_t P9N2_PEC_1_PROTECT_MODE_REG                                  = 0x0E0F03FEull;

static const uint64_t P9N2_PEC_2_PROTECT_MODE_REG                                  = 0x0F0F03FEull;


static const uint64_t P9N2_PU_PRV_MISC_PPE                                         = 0xC0002000ull;

static const uint64_t P9N2_PU_PRV_MISC_PPE1                                        = 0xC0002010ull;

static const uint64_t P9N2_PU_PRV_MISC_PPE2                                        = 0xC0002018ull;


static const uint64_t P9N2_PU_PSCOM_ERROR_MASK                                     = 0x06010002ull;


static const uint64_t P9N2_PEC_PSCOM_ERROR_MASK                                    = 0x0D010002ull;

static const uint64_t P9N2_PEC_0_PSCOM_ERROR_MASK                                  = 0x0D010002ull;

static const uint64_t P9N2_PEC_1_PSCOM_ERROR_MASK                                  = 0x0E010002ull;

static const uint64_t P9N2_PEC_2_PSCOM_ERROR_MASK                                  = 0x0F010002ull;


static const uint64_t P9N2_PU_N0_PSCOM_ERROR_MASK                                  = 0x02010002ull;

static const uint64_t P9N2_PU_N1_PSCOM_ERROR_MASK                                  = 0x03010002ull;

static const uint64_t P9N2_PU_N2_PSCOM_ERROR_MASK                                  = 0x04010002ull;

static const uint64_t P9N2_PU_N3_PSCOM_ERROR_MASK                                  = 0x05010002ull;


static const uint64_t P9N2_PU_PSCOM_MODE_REG                                       = 0x06010000ull;


static const uint64_t P9N2_PEC_PSCOM_MODE_REG                                      = 0x0D010000ull;

static const uint64_t P9N2_PEC_0_PSCOM_MODE_REG                                    = 0x0D010000ull;

static const uint64_t P9N2_PEC_1_PSCOM_MODE_REG                                    = 0x0E010000ull;

static const uint64_t P9N2_PEC_2_PSCOM_MODE_REG                                    = 0x0F010000ull;


static const uint64_t P9N2_PU_N0_PSCOM_MODE_REG                                    = 0x02010000ull;

static const uint64_t P9N2_PU_N1_PSCOM_MODE_REG                                    = 0x03010000ull;

static const uint64_t P9N2_PU_N2_PSCOM_MODE_REG                                    = 0x04010000ull;

static const uint64_t P9N2_PU_N3_PSCOM_MODE_REG                                    = 0x05010000ull;


static const uint64_t P9N2_PU_PSCOM_STATUS_ERROR_REG                               = 0x06010001ull;


static const uint64_t P9N2_PEC_PSCOM_STATUS_ERROR_REG                              = 0x0D010001ull;

static const uint64_t P9N2_PEC_0_PSCOM_STATUS_ERROR_REG                            = 0x0D010001ull;

static const uint64_t P9N2_PEC_1_PSCOM_STATUS_ERROR_REG                            = 0x0E010001ull;

static const uint64_t P9N2_PEC_2_PSCOM_STATUS_ERROR_REG                            = 0x0F010001ull;


static const uint64_t P9N2_PU_N0_PSCOM_STATUS_ERROR_REG                            = 0x02010001ull;

static const uint64_t P9N2_PU_N1_PSCOM_STATUS_ERROR_REG                            = 0x03010001ull;

static const uint64_t P9N2_PU_N2_PSCOM_STATUS_ERROR_REG                            = 0x04010001ull;

static const uint64_t P9N2_PU_N3_PSCOM_STATUS_ERROR_REG                            = 0x05010001ull;


static const uint64_t P9N2_PU_PSIHB_DEBUG_REG                                      = 0x05012911ull;


static const uint64_t P9N2_PU_PSIHB_ERROR_MASK_REG                                 = 0x0501290Full;


static const uint64_t P9N2_PU_PSIHB_FIR_ACTION0_REG                                = 0x05012906ull;


static const uint64_t P9N2_PU_PSIHB_FIR_ACTION1_REG                                = 0x05012907ull;


static const uint64_t P9N2_PU_PSIHB_FIR_MASK_REG                                   = 0x05012903ull;

static const uint64_t P9N2_PU_PSIHB_FIR_MASK_REG_AND                               = 0x05012904ull;

static const uint64_t P9N2_PU_PSIHB_FIR_MASK_REG_OR                                = 0x05012905ull;


static const uint64_t P9N2_PU_PSIHB_FIR_REG                                        = 0x05012900ull;

static const uint64_t P9N2_PU_PSIHB_FIR_REG_AND                                    = 0x05012901ull;

static const uint64_t P9N2_PU_PSIHB_FIR_REG_OR                                     = 0x05012902ull;


static const uint64_t P9N2_PU_PSIHB_INTERRUPT_CONTROL                              = 0x05012915ull;


static const uint64_t P9N2_PU_PSIHB_INTERRUPT_LEVEL                                = 0x05012919ull;


static const uint64_t P9N2_PU_PSIHB_INTERRUPT_STATUS                               = 0x0501291Aull;


static const uint64_t P9N2_PU_PSIHB_STATUS_CTL_REG_SCOM                            = 0x0501290Eull;

static const uint64_t P9N2_PU_PSIHB_STATUS_CTL_REG_SCOM1                           = 0x05012912ull;

static const uint64_t P9N2_PU_PSIHB_STATUS_CTL_REG_SCOM2                           = 0x05012913ull;


static const uint64_t P9N2_PU_PSI_BRIDGE_BAR_REG                                   = 0x0501290Aull;


static const uint64_t P9N2_PU_PSI_BRIDGE_FSP_BAR_REG                               = 0x0501290Bull;


static const uint64_t P9N2_PU_PSI_FSP_MMR_REG                                      = 0x0501290Cull;


static const uint64_t P9N2_PU_PSI_TCE_ADDR_REG                                     = 0x05012B44ull;


static const uint64_t P9N2_CAPP_PSLTTMAP0                                          = 0x0201082Dull;

static const uint64_t P9N2_CAPP_0_PSLTTMAP0                                        = 0x0201082Dull;

static const uint64_t P9N2_CAPP_1_PSLTTMAP0                                        = 0x0401082Dull;


static const uint64_t P9N2_CAPP_PSLTTMAP1                                          = 0x0201082Eull;

static const uint64_t P9N2_CAPP_0_PSLTTMAP1                                        = 0x0201082Eull;

static const uint64_t P9N2_CAPP_1_PSLTTMAP1                                        = 0x0401082Eull;


static const uint64_t P9N2_CAPP_PSLTTMAP2                                          = 0x0201082Full;

static const uint64_t P9N2_CAPP_0_PSLTTMAP2                                        = 0x0201082Full;

static const uint64_t P9N2_CAPP_1_PSLTTMAP2                                        = 0x0401082Full;


static const uint64_t P9N2_CAPP_PSLTTMAP3                                          = 0x02010830ull;

static const uint64_t P9N2_CAPP_0_PSLTTMAP3                                        = 0x02010830ull;

static const uint64_t P9N2_CAPP_1_PSLTTMAP3                                        = 0x04010830ull;


static const uint64_t P9N2_PU_PSL_DAR_AN                                           = 0x050115A9ull;

static const uint64_t P9N2_PU_NPU_PSL_DAR_AN                                       = 0x050113A9ull;

static const uint64_t P9N2_PU_NPU_SM3_PSL_DAR_AN                                   = 0x05011379ull;

static const uint64_t P9N2__SM3_PSL_DAR_AN                                         = 0x05011579ull;


static const uint64_t P9N2_PU_PSL_DSISR_AN                                         = 0x050115A8ull;

static const uint64_t P9N2_PU_NPU_PSL_DSISR_AN                                     = 0x050113A8ull;

static const uint64_t P9N2_PU_NPU_SM3_PSL_DSISR_AN                                 = 0x05011378ull;

static const uint64_t P9N2__SM3_PSL_DSISR_AN                                       = 0x05011578ull;


static const uint64_t P9N2_PU_NPU_DAT_PSL_LLCMD_A0                                 = 0x050113B1ull;

static const uint64_t P9N2__DAT_PSL_LLCMD_A0                                       = 0x050115B1ull;


static const uint64_t P9N2_PU_PSL_PEHANDLE_AN                                      = 0x050115ABull;

static const uint64_t P9N2_PU_NPU_PSL_PEHANDLE_AN                                  = 0x050113ABull;

static const uint64_t P9N2_PU_NPU_SM3_PSL_PEHANDLE_AN                              = 0x0501137Bull;

static const uint64_t P9N2__SM3_PSL_PEHANDLE_AN                                    = 0x0501157Bull;


static const uint64_t P9N2_PU_NPU_DAT_PSL_SCNTL_A0                                 = 0x050113B2ull;

static const uint64_t P9N2__DAT_PSL_SCNTL_A0                                       = 0x050115B2ull;


static const uint64_t P9N2_PU_NPU_DAT_PSL_SPAP_A0                                  = 0x050113B0ull;

static const uint64_t P9N2__DAT_PSL_SPAP_A0                                        = 0x050115B0ull;


static const uint64_t P9N2_PU_NPU_DAT_PSL_SPAP_A1                                  = 0x050113B3ull;

static const uint64_t P9N2__DAT_PSL_SPAP_A1                                        = 0x050115B3ull;


static const uint64_t P9N2_PU_PSL_TFC_AN                                           = 0x050115AAull;

static const uint64_t P9N2_PU_NPU_PSL_TFC_AN                                       = 0x050113AAull;

static const uint64_t P9N2_PU_NPU_SM3_PSL_TFC_AN                                   = 0x0501137Aull;

static const uint64_t P9N2__SM3_PSL_TFC_AN                                         = 0x0501157Aull;


static const uint64_t P9N2_PU_PSU_HOST_DOORBELL_REG                                = 0x000D0063ull;

static const uint64_t P9N2_PU_PSU_HOST_DOORBELL_REG_AND                            = 0x000D0064ull;

static const uint64_t P9N2_PU_PSU_HOST_DOORBELL_REG_OR                             = 0x000D0065ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX0_REG                               = 0x000D0050ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX1_REG                               = 0x000D0051ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX2_REG                               = 0x000D0052ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX3_REG                               = 0x000D0053ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX4_REG                               = 0x000D0054ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX5_REG                               = 0x000D0055ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX6_REG                               = 0x000D0056ull;


static const uint64_t P9N2_PU_PSU_HOST_SBE_MBOX7_REG                               = 0x000D0057ull;


static const uint64_t P9N2_PU_PSU_INSTR0_ACTCYCLECNT_REG                           = 0x000D0023ull;


static const uint64_t P9N2_PU_PSU_INSTR0_CYCLECNT_REG                              = 0x000D0022ull;


static const uint64_t P9N2_PU_PSU_INSTR0_EVENTCNT_REG                              = 0x000D0024ull;


static const uint64_t P9N2_PU_PSU_INSTR0_FILTER_REG                                = 0x000D0021ull;


static const uint64_t P9N2_PU_PSU_INSTR0_MAXCYCLECNT_REG                           = 0x000D0025ull;


static const uint64_t P9N2_PU_PSU_INSTR0_MINCYCLECNT_REG                           = 0x000D0026ull;


static const uint64_t P9N2_PU_PSU_INSTR0_STOP_TIMER_REG                            = 0x000D0020ull;


static const uint64_t P9N2_PU_PSU_INSTR1_ACTCYCLECNT_REG                           = 0x000D0033ull;


static const uint64_t P9N2_PU_PSU_INSTR1_CYCLECNT_REG                              = 0x000D0032ull;


static const uint64_t P9N2_PU_PSU_INSTR1_EVENTCNT_REG                              = 0x000D0034ull;


static const uint64_t P9N2_PU_PSU_INSTR1_FILTER_REG                                = 0x000D0031ull;


static const uint64_t P9N2_PU_PSU_INSTR1_MAXCYCLECNT_REG                           = 0x000D0035ull;


static const uint64_t P9N2_PU_PSU_INSTR1_MINCYCLECNT_REG                           = 0x000D0036ull;


static const uint64_t P9N2_PU_PSU_INSTR1_STOP_TIMER_REG                            = 0x000D0030ull;


static const uint64_t P9N2_PU_PSU_INSTR2_ACTCYCLECNT_REG                           = 0x000D0043ull;


static const uint64_t P9N2_PU_PSU_INSTR2_CYCLECNT_REG                              = 0x000D0042ull;


static const uint64_t P9N2_PU_PSU_INSTR2_EVENTCNT_REG                              = 0x000D0044ull;


static const uint64_t P9N2_PU_PSU_INSTR2_FILTER_REG                                = 0x000D0041ull;


static const uint64_t P9N2_PU_PSU_INSTR2_MAXCYCLECNT_REG                           = 0x000D0045ull;


static const uint64_t P9N2_PU_PSU_INSTR2_MINCYCLECNT_REG                           = 0x000D0046ull;


static const uint64_t P9N2_PU_PSU_INSTR2_STOP_TIMER_REG                            = 0x000D0040ull;


static const uint64_t P9N2_PU_PSU_INSTR_CTRL_STATUS_REG                            = 0x000D0010ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_2NDLAST_ADDR_TRACE_REG                   = 0x000D0005ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_2NDLAST_REQDATA_TRACE_REG                = 0x000D0006ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_2NDLAST_RSPDATA_TRACE_REG                = 0x000D0007ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_CTRL_STATUS_REG                          = 0x000D0000ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_FILTER_REG                               = 0x000D0001ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_LAST_ADDR_TRACE_REG                      = 0x000D0002ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_LAST_REQDATA_TRACE_REG                   = 0x000D0003ull;


static const uint64_t P9N2_PU_PSU_PIBHIST_LAST_RSPDATA_TRACE_REG                   = 0x000D0004ull;


static const uint64_t P9N2_PU_PSU_SBE_DOORBELL_REG                                 = 0x000D0060ull;

static const uint64_t P9N2_PU_PSU_SBE_DOORBELL_REG_AND                             = 0x000D0061ull;

static const uint64_t P9N2_PU_PSU_SBE_DOORBELL_REG_OR                              = 0x000D0062ull;


static const uint64_t P9N2_PU_RCV_ERRLOG0_REG                                      = 0x00090022ull;


static const uint64_t P9N2_PU_RCV_ERRLOG1_REG                                      = 0x00090023ull;


static const uint64_t P9N2_PEC_RECOV_INTERRUPT_REG                                 = 0x0D0F001Bull;

static const uint64_t P9N2_PEC_0_RECOV_INTERRUPT_REG                               = 0x0D0F001Bull;

static const uint64_t P9N2_PEC_1_RECOV_INTERRUPT_REG                               = 0x0E0F001Bull;

static const uint64_t P9N2_PEC_2_RECOV_INTERRUPT_REG                               = 0x0F0F001Bull;


static const uint64_t P9N2_NV_1_REM0                                               = 0x050110FDull;

static const uint64_t P9N2_NV_5_REM0                                               = 0x050114FDull;

static const uint64_t P9N2_PU_NPU2_NTL1_REM0                                       = 0x050112FDull;


static const uint64_t P9N2_NV_1_REM1                                               = 0x050110FEull;

static const uint64_t P9N2_NV_5_REM1                                               = 0x050114FEull;

static const uint64_t P9N2_PU_NPU2_NTL1_REM1                                       = 0x050112FEull;


static const uint64_t P9N2_PHB_RESERVED1_REG                                       = 0x0D01084Cull;

static const uint64_t P9N2_PHB_0_RESERVED1_REG                                     = 0x0D01084Cull;

static const uint64_t P9N2_PHB_1_RESERVED1_REG                                     = 0x0E01084Cull;

static const uint64_t P9N2_PHB_2_RESERVED1_REG                                     = 0x0E01088Cull;

static const uint64_t P9N2_PHB_3_RESERVED1_REG                                     = 0x0F01084Cull;

static const uint64_t P9N2_PHB_4_RESERVED1_REG                                     = 0x0F01088Cull;

static const uint64_t P9N2_PHB_5_RESERVED1_REG                                     = 0x0F0108CCull;


static const uint64_t P9N2_PU_RESET_REGISTER                                       = 0x00010001ull;


static const uint64_t P9N2_PU_RESET_REGISTER_B                                     = 0x000A0001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESET_REGISTER_C                                     = 0x000A1001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESET_REGISTER_D                                     = 0x000A2001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESET_REGISTER_E                                     = 0x000A3001ull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_B                 = 0x000A000Dull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_C                 = 0x000A100Dull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_D                 = 0x000A200Dull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_RESIDUAL_FRONT_END_BACK_END_LENGTH_E                 = 0x000A300Dull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PEC_RFIR                                                = 0x0D040001ull;

static const uint64_t P9N2_PEC_0_RFIR                                              = 0x0D040001ull;

static const uint64_t P9N2_PEC_1_RFIR                                              = 0x0E040001ull;

static const uint64_t P9N2_PEC_2_RFIR                                              = 0x0F040001ull;


static const uint64_t P9N2_PU_RING_FENCE_MASK_LATCH_REG                            = 0x06010008ull;


static const uint64_t P9N2_PEC_RING_FENCE_MASK_LATCH_REG                           = 0x0D010008ull;

static const uint64_t P9N2_PEC_0_RING_FENCE_MASK_LATCH_REG                         = 0x0D010008ull;

static const uint64_t P9N2_PEC_1_RING_FENCE_MASK_LATCH_REG                         = 0x0E010008ull;

static const uint64_t P9N2_PEC_2_RING_FENCE_MASK_LATCH_REG                         = 0x0F010008ull;


static const uint64_t P9N2_PU_N0_RING_FENCE_MASK_LATCH_REG                         = 0x02010008ull;

static const uint64_t P9N2_PU_N1_RING_FENCE_MASK_LATCH_REG                         = 0x03010008ull;

static const uint64_t P9N2_PU_N2_RING_FENCE_MASK_LATCH_REG                         = 0x04010008ull;

static const uint64_t P9N2_PU_N3_RING_FENCE_MASK_LATCH_REG                         = 0x05010008ull;


static const uint64_t P9N2__CTL_RLX_CONFIG                                         = 0x05011681ull;


static const uint64_t P9N2_PU_RNG_FAILED_INT                                       = 0x020110E7ull;


static const uint64_t P9N2_PU_NPU1_SM1_RSP_DA_PTR                                  = 0x05011125ull;

static const uint64_t P9N2_PU_NPU1_SM2_RSP_DA_PTR                                  = 0x05011145ull;

static const uint64_t P9N2_PU_NPU_SM1_RSP_DA_PTR                                   = 0x05011325ull;

static const uint64_t P9N2_PU_NPU_SM2_RSP_DA_PTR                                   = 0x05011345ull;

static const uint64_t P9N2__SM1_RSP_DA_PTR                                         = 0x05011525ull;

static const uint64_t P9N2__SM2_RSP_DA_PTR                                         = 0x05011545ull;


static const uint64_t P9N2_PU_NPU1_SM1_RSP_HA_PTR                                  = 0x05011123ull;

static const uint64_t P9N2_PU_NPU1_SM2_RSP_HA_PTR                                  = 0x05011143ull;

static const uint64_t P9N2_PU_NPU_SM1_RSP_HA_PTR                                   = 0x05011323ull;

static const uint64_t P9N2_PU_NPU_SM2_RSP_HA_PTR                                   = 0x05011343ull;

static const uint64_t P9N2__SM1_RSP_HA_PTR                                         = 0x05011523ull;

static const uint64_t P9N2__SM2_RSP_HA_PTR                                         = 0x05011543ull;


static const uint64_t P9N2_PU_RX_CH_FSM_REG                                        = 0x0501280Dull;


static const uint64_t P9N2_PU_RX_CH_INTADDR_REG                                    = 0x05012818ull;


static const uint64_t P9N2_PU_RX_CH_MISC_REG                                       = 0x0501281Bull;


static const uint64_t P9N2_PU_RX_CTRL_STAT_REG                                     = 0x05012808ull;


static const uint64_t P9N2_PU_RX_DBFF_REG0                                         = 0x05012819ull;


static const uint64_t P9N2_PU_RX_DBFF_REG1                                         = 0x0501281Aull;


static const uint64_t P9N2_PU_RX_DF_FSM_REG                                        = 0x0501280Eull;


static const uint64_t P9N2_PU_RX_ERROR_REG_WCLEAR                                  = 0x0501280Aull;

static const uint64_t P9N2_PU_RX_ERROR_REG_OR                                      = 0x0501280Cull;


static const uint64_t P9N2_PU_RX_ERR_MODE                                          = 0x0501280Full;


static const uint64_t P9N2_PU_RX_MASK_REG                                          = 0x0501280Bull;


static const uint64_t P9N2_PU_RX_PSI_CNTL                                          = 0x04011820ull;


static const uint64_t P9N2_PU_RX_PSI_MODE                                          = 0x04011821ull;


static const uint64_t P9N2_PU_RX_PSI_STATUS                                        = 0x04011822ull;


static const uint64_t P9N2_PEC_SCAN32                                              = 0x0D038000ull;

static const uint64_t P9N2_PEC_0_SCAN32                                            = 0x0D038000ull;

static const uint64_t P9N2_PEC_1_SCAN32                                            = 0x0E038000ull;

static const uint64_t P9N2_PEC_2_SCAN32                                            = 0x0F038000ull;


static const uint64_t P9N2_PEC_SCAN_CAPTUREDR                                      = 0x0D03C000ull;

static const uint64_t P9N2_PEC_0_SCAN_CAPTUREDR                                    = 0x0D03C000ull;

static const uint64_t P9N2_PEC_1_SCAN_CAPTUREDR                                    = 0x0E03C000ull;

static const uint64_t P9N2_PEC_2_SCAN_CAPTUREDR                                    = 0x0F03C000ull;


static const uint64_t P9N2_PEC_SCAN_REGION_TYPE                                    = 0x0D030005ull;

static const uint64_t P9N2_PEC_0_SCAN_REGION_TYPE                                  = 0x0D030005ull;

static const uint64_t P9N2_PEC_1_SCAN_REGION_TYPE                                  = 0x0E030005ull;

static const uint64_t P9N2_PEC_2_SCAN_REGION_TYPE                                  = 0x0F030005ull;


static const uint64_t P9N2_PEC_SCOM0X00                                            = 0x80000B400D010C3Full;
//DUPS: 800005000D010C3F, 800004000D010C3F, 800000800D010C3F, 800005400D010C3F, 80000A000D010C3F, 800000C00D010C3F, 800001800D010C3F, 800001C00D010C3F, 800003C00D010C3F, 800003800D010C3F, 800002C00D010C3F, 800002800D010C3F, 800009C00D010C3F, 800009800D010C3F, 800008C00D010C3F, 800008800D010C3F, 80000BC00D010C3F, 80000B800D010C3F, 80000AC00D010C3F, 80000A800D010C3F, 800000000D010C3F, 800000400D010C3F, 800001000D010C3F, 800001400D010C3F, 800002000D010C3F, 800002400D010C3F, 800003000D010C3F, 800003400D010C3F, 800008000D010C3F, 800008400D010C3F, 800009000D010C3F, 800009400D010C3F, 80000A400D010C3F, 80000B000D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X00                                          = 0x80000B400D010C3Full;
//DUPS: 800005000D010C3F, 800004000D010C3F, 800000800D010C3F, 800005400D010C3F, 80000A000D010C3F, 800000C00D010C3F, 800001800D010C3F, 800001C00D010C3F, 800003C00D010C3F, 800003800D010C3F, 800002C00D010C3F, 800002800D010C3F, 800009C00D010C3F, 800009800D010C3F, 800008C00D010C3F, 800008800D010C3F, 80000BC00D010C3F, 80000B800D010C3F, 80000AC00D010C3F, 80000A800D010C3F, 800000000D010C3F, 800000400D010C3F, 800001000D010C3F, 800001400D010C3F, 800002000D010C3F, 800002400D010C3F, 800003000D010C3F, 800003400D010C3F, 800008000D010C3F, 800008400D010C3F, 800009000D010C3F, 800009400D010C3F, 80000A400D010C3F, 80000B000D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X00                                          = 0x80000B400E010C3Full;
//DUPS: 800005000E010C3F, 800004000E010C3F, 800000800E010C3F, 800005400E010C3F, 80000A000E010C3F, 800000C00E010C3F, 800001800E010C3F, 800001C00E010C3F, 800003C00E010C3F, 800003800E010C3F, 800002C00E010C3F, 800002800E010C3F, 800009C00E010C3F, 800009800E010C3F, 800008C00E010C3F, 800008800E010C3F, 80000BC00E010C3F, 80000B800E010C3F, 80000AC00E010C3F, 80000A800E010C3F, 800000000E010C3F, 800000400E010C3F, 800001000E010C3F, 800001400E010C3F, 800002000E010C3F, 800002400E010C3F, 800003000E010C3F, 800003400E010C3F, 800008000E010C3F, 800008400E010C3F, 800009000E010C3F, 800009400E010C3F, 80000A400E010C3F, 80000B000E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X00                                          = 0x80000B400F010C3Full;
//DUPS: 800005000F010C3F, 800004000F010C3F, 800000800F010C3F, 800005400F010C3F, 80000A000F010C3F, 800000C00F010C3F, 800001800F010C3F, 800001C00F010C3F, 800003C00F010C3F, 800003800F010C3F, 800002C00F010C3F, 800002800F010C3F, 800009C00F010C3F, 800009800F010C3F, 800008C00F010C3F, 800008800F010C3F, 80000BC00F010C3F, 80000B800F010C3F, 80000AC00F010C3F, 80000A800F010C3F, 800000000F010C3F, 800000400F010C3F, 800001000F010C3F, 800001400F010C3F, 800002000F010C3F, 800002400F010C3F, 800003000F010C3F, 800003400F010C3F, 800008000F010C3F, 800008400F010C3F, 800009000F010C3F, 800009400F010C3F, 80000A400F010C3F, 80000B000F010C3F,

static const uint64_t P9N2_PEC_SCOM0X01                                            = 0x80000B410D010C3Full;
//DUPS: 800005010D010C3F, 800005410D010C3F, 80000A010D010C3F, 800000010D010C3F, 800000410D010C3F, 800001010D010C3F, 800001410D010C3F, 800002010D010C3F, 800002410D010C3F, 800003010D010C3F, 800003410D010C3F, 800008010D010C3F, 800008410D010C3F, 800009010D010C3F, 800009410D010C3F, 80000A410D010C3F, 80000B010D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X01                                          = 0x80000B410D010C3Full;
//DUPS: 800005010D010C3F, 800005410D010C3F, 80000A010D010C3F, 800000010D010C3F, 800000410D010C3F, 800001010D010C3F, 800001410D010C3F, 800002010D010C3F, 800002410D010C3F, 800003010D010C3F, 800003410D010C3F, 800008010D010C3F, 800008410D010C3F, 800009010D010C3F, 800009410D010C3F, 80000A410D010C3F, 80000B010D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X01                                          = 0x80000B410E010C3Full;
//DUPS: 800005010E010C3F, 800005410E010C3F, 80000A010E010C3F, 800000010E010C3F, 800000410E010C3F, 800001010E010C3F, 800001410E010C3F, 800002010E010C3F, 800002410E010C3F, 800003010E010C3F, 800003410E010C3F, 800008010E010C3F, 800008410E010C3F, 800009010E010C3F, 800009410E010C3F, 80000A410E010C3F, 80000B010E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X01                                          = 0x80000B410F010C3Full;
//DUPS: 800005010F010C3F, 800005410F010C3F, 80000A010F010C3F, 800000010F010C3F, 800000410F010C3F, 800001010F010C3F, 800001410F010C3F, 800002010F010C3F, 800002410F010C3F, 800003010F010C3F, 800003410F010C3F, 800008010F010C3F, 800008410F010C3F, 800009010F010C3F, 800009410F010C3F, 80000A410F010C3F, 80000B010F010C3F,

static const uint64_t P9N2_PEC_SCOM0X02                                            = 0x80000B420D010C3Full;
//DUPS: 800005020D010C3F, 800000820D010C3F, 800005420D010C3F, 80000A020D010C3F, 800000C20D010C3F, 800001820D010C3F, 800001C20D010C3F, 800003C20D010C3F, 800003820D010C3F, 800002C20D010C3F, 800002820D010C3F, 800009C20D010C3F, 800009820D010C3F, 800008C20D010C3F, 800008820D010C3F, 80000BC20D010C3F, 80000B820D010C3F, 80000AC20D010C3F, 80000A820D010C3F, 800000020D010C3F, 800000420D010C3F, 800001020D010C3F, 800001420D010C3F, 800002020D010C3F, 800002420D010C3F, 800003020D010C3F, 800003420D010C3F, 800008020D010C3F, 800008420D010C3F, 800009020D010C3F, 800009420D010C3F, 80000A420D010C3F, 80000B020D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X02                                          = 0x80000B420D010C3Full;
//DUPS: 800005020D010C3F, 800000820D010C3F, 800005420D010C3F, 80000A020D010C3F, 800000C20D010C3F, 800001820D010C3F, 800001C20D010C3F, 800003C20D010C3F, 800003820D010C3F, 800002C20D010C3F, 800002820D010C3F, 800009C20D010C3F, 800009820D010C3F, 800008C20D010C3F, 800008820D010C3F, 80000BC20D010C3F, 80000B820D010C3F, 80000AC20D010C3F, 80000A820D010C3F, 800000020D010C3F, 800000420D010C3F, 800001020D010C3F, 800001420D010C3F, 800002020D010C3F, 800002420D010C3F, 800003020D010C3F, 800003420D010C3F, 800008020D010C3F, 800008420D010C3F, 800009020D010C3F, 800009420D010C3F, 80000A420D010C3F, 80000B020D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X02                                          = 0x80000B420E010C3Full;
//DUPS: 800005020E010C3F, 800000820E010C3F, 800005420E010C3F, 80000A020E010C3F, 800000C20E010C3F, 800001820E010C3F, 800001C20E010C3F, 800003C20E010C3F, 800003820E010C3F, 800002C20E010C3F, 800002820E010C3F, 800009C20E010C3F, 800009820E010C3F, 800008C20E010C3F, 800008820E010C3F, 80000BC20E010C3F, 80000B820E010C3F, 80000AC20E010C3F, 80000A820E010C3F, 800000020E010C3F, 800000420E010C3F, 800001020E010C3F, 800001420E010C3F, 800002020E010C3F, 800002420E010C3F, 800003020E010C3F, 800003420E010C3F, 800008020E010C3F, 800008420E010C3F, 800009020E010C3F, 800009420E010C3F, 80000A420E010C3F, 80000B020E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X02                                          = 0x80000B420F010C3Full;
//DUPS: 800005020F010C3F, 800000820F010C3F, 800005420F010C3F, 80000A020F010C3F, 800000C20F010C3F, 800001820F010C3F, 800001C20F010C3F, 800003C20F010C3F, 800003820F010C3F, 800002C20F010C3F, 800002820F010C3F, 800009C20F010C3F, 800009820F010C3F, 800008C20F010C3F, 800008820F010C3F, 80000BC20F010C3F, 80000B820F010C3F, 80000AC20F010C3F, 80000A820F010C3F, 800000020F010C3F, 800000420F010C3F, 800001020F010C3F, 800001420F010C3F, 800002020F010C3F, 800002420F010C3F, 800003020F010C3F, 800003420F010C3F, 800008020F010C3F, 800008420F010C3F, 800009020F010C3F, 800009420F010C3F, 80000A420F010C3F, 80000B020F010C3F,

static const uint64_t P9N2_PEC_SCOM0X03                                            = 0x80000B430D010C3Full;
//DUPS: 800005030D010C3F, 800000830D010C3F, 800005430D010C3F, 80000A030D010C3F, 800000C30D010C3F, 800001830D010C3F, 800001C30D010C3F, 800003C30D010C3F, 800003830D010C3F, 800002C30D010C3F, 800002830D010C3F, 800009C30D010C3F, 800009830D010C3F, 800008C30D010C3F, 800008830D010C3F, 80000BC30D010C3F, 80000B830D010C3F, 80000AC30D010C3F, 80000A830D010C3F, 800000030D010C3F, 800000430D010C3F, 800001030D010C3F, 800001430D010C3F, 800002030D010C3F, 800002430D010C3F, 800003030D010C3F, 800003430D010C3F, 800008030D010C3F, 800008430D010C3F, 800009030D010C3F, 800009430D010C3F, 80000A430D010C3F, 80000B030D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X03                                          = 0x80000B430D010C3Full;
//DUPS: 800005030D010C3F, 800000830D010C3F, 800005430D010C3F, 80000A030D010C3F, 800000C30D010C3F, 800001830D010C3F, 800001C30D010C3F, 800003C30D010C3F, 800003830D010C3F, 800002C30D010C3F, 800002830D010C3F, 800009C30D010C3F, 800009830D010C3F, 800008C30D010C3F, 800008830D010C3F, 80000BC30D010C3F, 80000B830D010C3F, 80000AC30D010C3F, 80000A830D010C3F, 800000030D010C3F, 800000430D010C3F, 800001030D010C3F, 800001430D010C3F, 800002030D010C3F, 800002430D010C3F, 800003030D010C3F, 800003430D010C3F, 800008030D010C3F, 800008430D010C3F, 800009030D010C3F, 800009430D010C3F, 80000A430D010C3F, 80000B030D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X03                                          = 0x80000B430E010C3Full;
//DUPS: 800005030E010C3F, 800000830E010C3F, 800005430E010C3F, 80000A030E010C3F, 800000C30E010C3F, 800001830E010C3F, 800001C30E010C3F, 800003C30E010C3F, 800003830E010C3F, 800002C30E010C3F, 800002830E010C3F, 800009C30E010C3F, 800009830E010C3F, 800008C30E010C3F, 800008830E010C3F, 80000BC30E010C3F, 80000B830E010C3F, 80000AC30E010C3F, 80000A830E010C3F, 800000030E010C3F, 800000430E010C3F, 800001030E010C3F, 800001430E010C3F, 800002030E010C3F, 800002430E010C3F, 800003030E010C3F, 800003430E010C3F, 800008030E010C3F, 800008430E010C3F, 800009030E010C3F, 800009430E010C3F, 80000A430E010C3F, 80000B030E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X03                                          = 0x80000B430F010C3Full;
//DUPS: 800005030F010C3F, 800000830F010C3F, 800005430F010C3F, 80000A030F010C3F, 800000C30F010C3F, 800001830F010C3F, 800001C30F010C3F, 800003C30F010C3F, 800003830F010C3F, 800002C30F010C3F, 800002830F010C3F, 800009C30F010C3F, 800009830F010C3F, 800008C30F010C3F, 800008830F010C3F, 80000BC30F010C3F, 80000B830F010C3F, 80000AC30F010C3F, 80000A830F010C3F, 800000030F010C3F, 800000430F010C3F, 800001030F010C3F, 800001430F010C3F, 800002030F010C3F, 800002430F010C3F, 800003030F010C3F, 800003430F010C3F, 800008030F010C3F, 800008430F010C3F, 800009030F010C3F, 800009430F010C3F, 80000A430F010C3F, 80000B030F010C3F,

static const uint64_t P9N2_PEC_SCOM0X04                                            = 0x80000B440D010C3Full;
//DUPS: 800005040D010C3F, 800005440D010C3F, 80000A040D010C3F, 800000040D010C3F, 800000440D010C3F, 800001040D010C3F, 800001440D010C3F, 800002040D010C3F, 800002440D010C3F, 800003040D010C3F, 800003440D010C3F, 800008040D010C3F, 800008440D010C3F, 800009040D010C3F, 800009440D010C3F, 80000A440D010C3F, 80000B040D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X04                                          = 0x80000B440D010C3Full;
//DUPS: 800005040D010C3F, 800005440D010C3F, 80000A040D010C3F, 800000040D010C3F, 800000440D010C3F, 800001040D010C3F, 800001440D010C3F, 800002040D010C3F, 800002440D010C3F, 800003040D010C3F, 800003440D010C3F, 800008040D010C3F, 800008440D010C3F, 800009040D010C3F, 800009440D010C3F, 80000A440D010C3F, 80000B040D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X04                                          = 0x80000B440E010C3Full;
//DUPS: 800005040E010C3F, 800005440E010C3F, 80000A040E010C3F, 800000040E010C3F, 800000440E010C3F, 800001040E010C3F, 800001440E010C3F, 800002040E010C3F, 800002440E010C3F, 800003040E010C3F, 800003440E010C3F, 800008040E010C3F, 800008440E010C3F, 800009040E010C3F, 800009440E010C3F, 80000A440E010C3F, 80000B040E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X04                                          = 0x80000B440F010C3Full;
//DUPS: 800005040F010C3F, 800005440F010C3F, 80000A040F010C3F, 800000040F010C3F, 800000440F010C3F, 800001040F010C3F, 800001440F010C3F, 800002040F010C3F, 800002440F010C3F, 800003040F010C3F, 800003440F010C3F, 800008040F010C3F, 800008440F010C3F, 800009040F010C3F, 800009440F010C3F, 80000A440F010C3F, 80000B040F010C3F,

static const uint64_t P9N2_PEC_SCOM0X05                                            = 0x80000B450D010C3Full;
//DUPS: 800004050D010C3F, 80000A050D010C3F, 800000050D010C3F, 800000450D010C3F, 800001050D010C3F, 800001450D010C3F, 800002050D010C3F, 800002450D010C3F, 800003050D010C3F, 800003450D010C3F, 800008050D010C3F, 800008450D010C3F, 800009050D010C3F, 800009450D010C3F, 80000A450D010C3F, 80000B050D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X05                                          = 0x80000B450D010C3Full;
//DUPS: 800004050D010C3F, 80000A050D010C3F, 800000050D010C3F, 800000450D010C3F, 800001050D010C3F, 800001450D010C3F, 800002050D010C3F, 800002450D010C3F, 800003050D010C3F, 800003450D010C3F, 800008050D010C3F, 800008450D010C3F, 800009050D010C3F, 800009450D010C3F, 80000A450D010C3F, 80000B050D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X05                                          = 0x80000B450E010C3Full;
//DUPS: 800004050E010C3F, 80000A050E010C3F, 800000050E010C3F, 800000450E010C3F, 800001050E010C3F, 800001450E010C3F, 800002050E010C3F, 800002450E010C3F, 800003050E010C3F, 800003450E010C3F, 800008050E010C3F, 800008450E010C3F, 800009050E010C3F, 800009450E010C3F, 80000A450E010C3F, 80000B050E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X05                                          = 0x80000B450F010C3Full;
//DUPS: 800004050F010C3F, 80000A050F010C3F, 800000050F010C3F, 800000450F010C3F, 800001050F010C3F, 800001450F010C3F, 800002050F010C3F, 800002450F010C3F, 800003050F010C3F, 800003450F010C3F, 800008050F010C3F, 800008450F010C3F, 800009050F010C3F, 800009450F010C3F, 80000A450F010C3F, 80000B050F010C3F,

static const uint64_t P9N2_PEC_SCOM0X06                                            = 0x80000B460D010C3Full;
//DUPS: 800000860D010C3F, 80000A060D010C3F, 800000C60D010C3F, 800001860D010C3F, 800001C60D010C3F, 800003C60D010C3F, 800003860D010C3F, 800002C60D010C3F, 800002860D010C3F, 800009C60D010C3F, 800009860D010C3F, 800008C60D010C3F, 800008860D010C3F, 80000BC60D010C3F, 80000B860D010C3F, 80000AC60D010C3F, 80000A860D010C3F, 800000060D010C3F, 800000460D010C3F, 800001060D010C3F, 800001460D010C3F, 800002060D010C3F, 800002460D010C3F, 800003060D010C3F, 800003460D010C3F, 800008060D010C3F, 800008460D010C3F, 800009060D010C3F, 800009460D010C3F, 80000A460D010C3F, 80000B060D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X06                                          = 0x80000B460D010C3Full;
//DUPS: 800000860D010C3F, 80000A060D010C3F, 800000C60D010C3F, 800001860D010C3F, 800001C60D010C3F, 800003C60D010C3F, 800003860D010C3F, 800002C60D010C3F, 800002860D010C3F, 800009C60D010C3F, 800009860D010C3F, 800008C60D010C3F, 800008860D010C3F, 80000BC60D010C3F, 80000B860D010C3F, 80000AC60D010C3F, 80000A860D010C3F, 800000060D010C3F, 800000460D010C3F, 800001060D010C3F, 800001460D010C3F, 800002060D010C3F, 800002460D010C3F, 800003060D010C3F, 800003460D010C3F, 800008060D010C3F, 800008460D010C3F, 800009060D010C3F, 800009460D010C3F, 80000A460D010C3F, 80000B060D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X06                                          = 0x80000B460E010C3Full;
//DUPS: 800000860E010C3F, 80000A060E010C3F, 800000C60E010C3F, 800001860E010C3F, 800001C60E010C3F, 800003C60E010C3F, 800003860E010C3F, 800002C60E010C3F, 800002860E010C3F, 800009C60E010C3F, 800009860E010C3F, 800008C60E010C3F, 800008860E010C3F, 80000BC60E010C3F, 80000B860E010C3F, 80000AC60E010C3F, 80000A860E010C3F, 800000060E010C3F, 800000460E010C3F, 800001060E010C3F, 800001460E010C3F, 800002060E010C3F, 800002460E010C3F, 800003060E010C3F, 800003460E010C3F, 800008060E010C3F, 800008460E010C3F, 800009060E010C3F, 800009460E010C3F, 80000A460E010C3F, 80000B060E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X06                                          = 0x80000B460F010C3Full;
//DUPS: 800000860F010C3F, 80000A060F010C3F, 800000C60F010C3F, 800001860F010C3F, 800001C60F010C3F, 800003C60F010C3F, 800003860F010C3F, 800002C60F010C3F, 800002860F010C3F, 800009C60F010C3F, 800009860F010C3F, 800008C60F010C3F, 800008860F010C3F, 80000BC60F010C3F, 80000B860F010C3F, 80000AC60F010C3F, 80000A860F010C3F, 800000060F010C3F, 800000460F010C3F, 800001060F010C3F, 800001460F010C3F, 800002060F010C3F, 800002460F010C3F, 800003060F010C3F, 800003460F010C3F, 800008060F010C3F, 800008460F010C3F, 800009060F010C3F, 800009460F010C3F, 80000A460F010C3F, 80000B060F010C3F,

static const uint64_t P9N2_PEC_SCOM0X07                                            = 0x80000B470D010C3Full;
//DUPS: 800000870D010C3F, 80000A070D010C3F, 800000C70D010C3F, 800001870D010C3F, 800001C70D010C3F, 800003C70D010C3F, 800003870D010C3F, 800002C70D010C3F, 800002870D010C3F, 800009C70D010C3F, 800009870D010C3F, 800008C70D010C3F, 800008870D010C3F, 80000BC70D010C3F, 80000B870D010C3F, 80000AC70D010C3F, 80000A870D010C3F, 800000070D010C3F, 800000470D010C3F, 800001070D010C3F, 800001470D010C3F, 800002070D010C3F, 800002470D010C3F, 800003070D010C3F, 800003470D010C3F, 800008070D010C3F, 800008470D010C3F, 800009070D010C3F, 800009470D010C3F, 80000A470D010C3F, 80000B070D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X07                                          = 0x80000B470D010C3Full;
//DUPS: 800000870D010C3F, 80000A070D010C3F, 800000C70D010C3F, 800001870D010C3F, 800001C70D010C3F, 800003C70D010C3F, 800003870D010C3F, 800002C70D010C3F, 800002870D010C3F, 800009C70D010C3F, 800009870D010C3F, 800008C70D010C3F, 800008870D010C3F, 80000BC70D010C3F, 80000B870D010C3F, 80000AC70D010C3F, 80000A870D010C3F, 800000070D010C3F, 800000470D010C3F, 800001070D010C3F, 800001470D010C3F, 800002070D010C3F, 800002470D010C3F, 800003070D010C3F, 800003470D010C3F, 800008070D010C3F, 800008470D010C3F, 800009070D010C3F, 800009470D010C3F, 80000A470D010C3F, 80000B070D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X07                                          = 0x80000B470E010C3Full;
//DUPS: 800000870E010C3F, 80000A070E010C3F, 800000C70E010C3F, 800001870E010C3F, 800001C70E010C3F, 800003C70E010C3F, 800003870E010C3F, 800002C70E010C3F, 800002870E010C3F, 800009C70E010C3F, 800009870E010C3F, 800008C70E010C3F, 800008870E010C3F, 80000BC70E010C3F, 80000B870E010C3F, 80000AC70E010C3F, 80000A870E010C3F, 800000070E010C3F, 800000470E010C3F, 800001070E010C3F, 800001470E010C3F, 800002070E010C3F, 800002470E010C3F, 800003070E010C3F, 800003470E010C3F, 800008070E010C3F, 800008470E010C3F, 800009070E010C3F, 800009470E010C3F, 80000A470E010C3F, 80000B070E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X07                                          = 0x80000B470F010C3Full;
//DUPS: 800000870F010C3F, 80000A070F010C3F, 800000C70F010C3F, 800001870F010C3F, 800001C70F010C3F, 800003C70F010C3F, 800003870F010C3F, 800002C70F010C3F, 800002870F010C3F, 800009C70F010C3F, 800009870F010C3F, 800008C70F010C3F, 800008870F010C3F, 80000BC70F010C3F, 80000B870F010C3F, 80000AC70F010C3F, 80000A870F010C3F, 800000070F010C3F, 800000470F010C3F, 800001070F010C3F, 800001470F010C3F, 800002070F010C3F, 800002470F010C3F, 800003070F010C3F, 800003470F010C3F, 800008070F010C3F, 800008470F010C3F, 800009070F010C3F, 800009470F010C3F, 80000A470F010C3F, 80000B070F010C3F,

static const uint64_t P9N2_PEC_SCOM0X08                                            = 0x80000B480D010C3Full;
//DUPS: 800000880D010C3F, 80000A080D010C3F, 800000C80D010C3F, 800001880D010C3F, 800001C80D010C3F, 800003C80D010C3F, 800003880D010C3F, 800002C80D010C3F, 800002880D010C3F, 800009C80D010C3F, 800009880D010C3F, 800008C80D010C3F, 800008880D010C3F, 80000BC80D010C3F, 80000B880D010C3F, 80000AC80D010C3F, 80000A880D010C3F, 800000080D010C3F, 800000480D010C3F, 800001080D010C3F, 800001480D010C3F, 800002080D010C3F, 800002480D010C3F, 800003080D010C3F, 800003480D010C3F, 800008080D010C3F, 800008480D010C3F, 800009080D010C3F, 800009480D010C3F, 80000A480D010C3F, 80000B080D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X08                                          = 0x80000B480D010C3Full;
//DUPS: 800000880D010C3F, 80000A080D010C3F, 800000C80D010C3F, 800001880D010C3F, 800001C80D010C3F, 800003C80D010C3F, 800003880D010C3F, 800002C80D010C3F, 800002880D010C3F, 800009C80D010C3F, 800009880D010C3F, 800008C80D010C3F, 800008880D010C3F, 80000BC80D010C3F, 80000B880D010C3F, 80000AC80D010C3F, 80000A880D010C3F, 800000080D010C3F, 800000480D010C3F, 800001080D010C3F, 800001480D010C3F, 800002080D010C3F, 800002480D010C3F, 800003080D010C3F, 800003480D010C3F, 800008080D010C3F, 800008480D010C3F, 800009080D010C3F, 800009480D010C3F, 80000A480D010C3F, 80000B080D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X08                                          = 0x80000B480E010C3Full;
//DUPS: 800000880E010C3F, 80000A080E010C3F, 800000C80E010C3F, 800001880E010C3F, 800001C80E010C3F, 800003C80E010C3F, 800003880E010C3F, 800002C80E010C3F, 800002880E010C3F, 800009C80E010C3F, 800009880E010C3F, 800008C80E010C3F, 800008880E010C3F, 80000BC80E010C3F, 80000B880E010C3F, 80000AC80E010C3F, 80000A880E010C3F, 800000080E010C3F, 800000480E010C3F, 800001080E010C3F, 800001480E010C3F, 800002080E010C3F, 800002480E010C3F, 800003080E010C3F, 800003480E010C3F, 800008080E010C3F, 800008480E010C3F, 800009080E010C3F, 800009480E010C3F, 80000A480E010C3F, 80000B080E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X08                                          = 0x80000B480F010C3Full;
//DUPS: 800000880F010C3F, 80000A080F010C3F, 800000C80F010C3F, 800001880F010C3F, 800001C80F010C3F, 800003C80F010C3F, 800003880F010C3F, 800002C80F010C3F, 800002880F010C3F, 800009C80F010C3F, 800009880F010C3F, 800008C80F010C3F, 800008880F010C3F, 80000BC80F010C3F, 80000B880F010C3F, 80000AC80F010C3F, 80000A880F010C3F, 800000080F010C3F, 800000480F010C3F, 800001080F010C3F, 800001480F010C3F, 800002080F010C3F, 800002480F010C3F, 800003080F010C3F, 800003480F010C3F, 800008080F010C3F, 800008480F010C3F, 800009080F010C3F, 800009480F010C3F, 80000A480F010C3F, 80000B080F010C3F,

static const uint64_t P9N2_PEC_SCOM0X09                                            = 0x80000BC90D010C3Full;
//DUPS: 800000C90D010C3F, 800001890D010C3F, 800001C90D010C3F, 800003C90D010C3F, 800003890D010C3F, 800002C90D010C3F, 800002890D010C3F, 800009C90D010C3F, 800009890D010C3F, 800008C90D010C3F, 800008890D010C3F, 80000BC90D010C3F, 80000B890D010C3F, 80000AC90D010C3F, 80000A890D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X09                                          = 0x80000BC90D010C3Full;
//DUPS: 800000C90D010C3F, 800001890D010C3F, 800001C90D010C3F, 800003C90D010C3F, 800003890D010C3F, 800002C90D010C3F, 800002890D010C3F, 800009C90D010C3F, 800009890D010C3F, 800008C90D010C3F, 800008890D010C3F, 80000BC90D010C3F, 80000B890D010C3F, 80000AC90D010C3F, 80000A890D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X09                                          = 0x80000BC90E010C3Full;
//DUPS: 800000C90E010C3F, 800001890E010C3F, 800001C90E010C3F, 800003C90E010C3F, 800003890E010C3F, 800002C90E010C3F, 800002890E010C3F, 800009C90E010C3F, 800009890E010C3F, 800008C90E010C3F, 800008890E010C3F, 80000BC90E010C3F, 80000B890E010C3F, 80000AC90E010C3F, 80000A890E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X09                                          = 0x80000BC90F010C3Full;
//DUPS: 800000C90F010C3F, 800001890F010C3F, 800001C90F010C3F, 800003C90F010C3F, 800003890F010C3F, 800002C90F010C3F, 800002890F010C3F, 800009C90F010C3F, 800009890F010C3F, 800008C90F010C3F, 800008890F010C3F, 80000BC90F010C3F, 80000B890F010C3F, 80000AC90F010C3F, 80000A890F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0A                                            = 0x80000BCA0D010C3Full;
//DUPS: 800000CA0D010C3F, 8000018A0D010C3F, 800001CA0D010C3F, 800003CA0D010C3F, 8000038A0D010C3F, 800002CA0D010C3F, 8000028A0D010C3F, 800009CA0D010C3F, 8000098A0D010C3F, 800008CA0D010C3F, 8000088A0D010C3F, 80000BCA0D010C3F, 80000B8A0D010C3F, 80000ACA0D010C3F, 80000A8A0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0A                                          = 0x80000BCA0D010C3Full;
//DUPS: 800000CA0D010C3F, 8000018A0D010C3F, 800001CA0D010C3F, 800003CA0D010C3F, 8000038A0D010C3F, 800002CA0D010C3F, 8000028A0D010C3F, 800009CA0D010C3F, 8000098A0D010C3F, 800008CA0D010C3F, 8000088A0D010C3F, 80000BCA0D010C3F, 80000B8A0D010C3F, 80000ACA0D010C3F, 80000A8A0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0A                                          = 0x80000BCA0E010C3Full;
//DUPS: 800000CA0E010C3F, 8000018A0E010C3F, 800001CA0E010C3F, 800003CA0E010C3F, 8000038A0E010C3F, 800002CA0E010C3F, 8000028A0E010C3F, 800009CA0E010C3F, 8000098A0E010C3F, 800008CA0E010C3F, 8000088A0E010C3F, 80000BCA0E010C3F, 80000B8A0E010C3F, 80000ACA0E010C3F, 80000A8A0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0A                                          = 0x80000BCA0F010C3Full;
//DUPS: 800000CA0F010C3F, 8000018A0F010C3F, 800001CA0F010C3F, 800003CA0F010C3F, 8000038A0F010C3F, 800002CA0F010C3F, 8000028A0F010C3F, 800009CA0F010C3F, 8000098A0F010C3F, 800008CA0F010C3F, 8000088A0F010C3F, 80000BCA0F010C3F, 80000B8A0F010C3F, 80000ACA0F010C3F, 80000A8A0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0B                                            = 0x80000B4B0D010C3Full;
//DUPS: 8000008B0D010C3F, 80000A0B0D010C3F, 800000CB0D010C3F, 8000018B0D010C3F, 800001CB0D010C3F, 800003CB0D010C3F, 8000038B0D010C3F, 800002CB0D010C3F, 8000028B0D010C3F, 800009CB0D010C3F, 8000098B0D010C3F, 800008CB0D010C3F, 8000088B0D010C3F, 80000BCB0D010C3F, 80000B8B0D010C3F, 80000ACB0D010C3F, 80000A8B0D010C3F, 8000000B0D010C3F, 8000004B0D010C3F, 8000010B0D010C3F, 8000014B0D010C3F, 8000020B0D010C3F, 8000024B0D010C3F, 8000030B0D010C3F, 8000034B0D010C3F, 8000080B0D010C3F, 8000084B0D010C3F, 8000090B0D010C3F, 8000094B0D010C3F, 80000A4B0D010C3F, 80000B0B0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0B                                          = 0x80000B4B0D010C3Full;
//DUPS: 8000008B0D010C3F, 80000A0B0D010C3F, 800000CB0D010C3F, 8000018B0D010C3F, 800001CB0D010C3F, 800003CB0D010C3F, 8000038B0D010C3F, 800002CB0D010C3F, 8000028B0D010C3F, 800009CB0D010C3F, 8000098B0D010C3F, 800008CB0D010C3F, 8000088B0D010C3F, 80000BCB0D010C3F, 80000B8B0D010C3F, 80000ACB0D010C3F, 80000A8B0D010C3F, 8000000B0D010C3F, 8000004B0D010C3F, 8000010B0D010C3F, 8000014B0D010C3F, 8000020B0D010C3F, 8000024B0D010C3F, 8000030B0D010C3F, 8000034B0D010C3F, 8000080B0D010C3F, 8000084B0D010C3F, 8000090B0D010C3F, 8000094B0D010C3F, 80000A4B0D010C3F, 80000B0B0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0B                                          = 0x80000B4B0E010C3Full;
//DUPS: 8000008B0E010C3F, 80000A0B0E010C3F, 800000CB0E010C3F, 8000018B0E010C3F, 800001CB0E010C3F, 800003CB0E010C3F, 8000038B0E010C3F, 800002CB0E010C3F, 8000028B0E010C3F, 800009CB0E010C3F, 8000098B0E010C3F, 800008CB0E010C3F, 8000088B0E010C3F, 80000BCB0E010C3F, 80000B8B0E010C3F, 80000ACB0E010C3F, 80000A8B0E010C3F, 8000000B0E010C3F, 8000004B0E010C3F, 8000010B0E010C3F, 8000014B0E010C3F, 8000020B0E010C3F, 8000024B0E010C3F, 8000030B0E010C3F, 8000034B0E010C3F, 8000080B0E010C3F, 8000084B0E010C3F, 8000090B0E010C3F, 8000094B0E010C3F, 80000A4B0E010C3F, 80000B0B0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0B                                          = 0x80000B4B0F010C3Full;
//DUPS: 8000008B0F010C3F, 80000A0B0F010C3F, 800000CB0F010C3F, 8000018B0F010C3F, 800001CB0F010C3F, 800003CB0F010C3F, 8000038B0F010C3F, 800002CB0F010C3F, 8000028B0F010C3F, 800009CB0F010C3F, 8000098B0F010C3F, 800008CB0F010C3F, 8000088B0F010C3F, 80000BCB0F010C3F, 80000B8B0F010C3F, 80000ACB0F010C3F, 80000A8B0F010C3F, 8000000B0F010C3F, 8000004B0F010C3F, 8000010B0F010C3F, 8000014B0F010C3F, 8000020B0F010C3F, 8000024B0F010C3F, 8000030B0F010C3F, 8000034B0F010C3F, 8000080B0F010C3F, 8000084B0F010C3F, 8000090B0F010C3F, 8000094B0F010C3F, 80000A4B0F010C3F, 80000B0B0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0C                                            = 0x80000BCC0D010C3Full;
//DUPS: 800000CC0D010C3F, 8000018C0D010C3F, 800001CC0D010C3F, 800003CC0D010C3F, 8000038C0D010C3F, 800002CC0D010C3F, 8000028C0D010C3F, 800009CC0D010C3F, 8000098C0D010C3F, 800008CC0D010C3F, 8000088C0D010C3F, 80000BCC0D010C3F, 80000B8C0D010C3F, 80000ACC0D010C3F, 80000A8C0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0C                                          = 0x80000BCC0D010C3Full;
//DUPS: 800000CC0D010C3F, 8000018C0D010C3F, 800001CC0D010C3F, 800003CC0D010C3F, 8000038C0D010C3F, 800002CC0D010C3F, 8000028C0D010C3F, 800009CC0D010C3F, 8000098C0D010C3F, 800008CC0D010C3F, 8000088C0D010C3F, 80000BCC0D010C3F, 80000B8C0D010C3F, 80000ACC0D010C3F, 80000A8C0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0C                                          = 0x80000BCC0E010C3Full;
//DUPS: 800000CC0E010C3F, 8000018C0E010C3F, 800001CC0E010C3F, 800003CC0E010C3F, 8000038C0E010C3F, 800002CC0E010C3F, 8000028C0E010C3F, 800009CC0E010C3F, 8000098C0E010C3F, 800008CC0E010C3F, 8000088C0E010C3F, 80000BCC0E010C3F, 80000B8C0E010C3F, 80000ACC0E010C3F, 80000A8C0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0C                                          = 0x80000BCC0F010C3Full;
//DUPS: 800000CC0F010C3F, 8000018C0F010C3F, 800001CC0F010C3F, 800003CC0F010C3F, 8000038C0F010C3F, 800002CC0F010C3F, 8000028C0F010C3F, 800009CC0F010C3F, 8000098C0F010C3F, 800008CC0F010C3F, 8000088C0F010C3F, 80000BCC0F010C3F, 80000B8C0F010C3F, 80000ACC0F010C3F, 80000A8C0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0D                                            = 0x80000B4D0D010C3Full;
//DUPS: 8000008D0D010C3F, 80000A0D0D010C3F, 800000CD0D010C3F, 8000018D0D010C3F, 800001CD0D010C3F, 800003CD0D010C3F, 8000038D0D010C3F, 800002CD0D010C3F, 8000028D0D010C3F, 800009CD0D010C3F, 8000098D0D010C3F, 800008CD0D010C3F, 8000088D0D010C3F, 80000BCD0D010C3F, 80000B8D0D010C3F, 80000ACD0D010C3F, 80000A8D0D010C3F, 8000000D0D010C3F, 8000004D0D010C3F, 8000010D0D010C3F, 8000014D0D010C3F, 8000020D0D010C3F, 8000024D0D010C3F, 8000030D0D010C3F, 8000034D0D010C3F, 8000080D0D010C3F, 8000084D0D010C3F, 8000090D0D010C3F, 8000094D0D010C3F, 80000A4D0D010C3F, 80000B0D0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0D                                          = 0x80000B4D0D010C3Full;
//DUPS: 8000008D0D010C3F, 80000A0D0D010C3F, 800000CD0D010C3F, 8000018D0D010C3F, 800001CD0D010C3F, 800003CD0D010C3F, 8000038D0D010C3F, 800002CD0D010C3F, 8000028D0D010C3F, 800009CD0D010C3F, 8000098D0D010C3F, 800008CD0D010C3F, 8000088D0D010C3F, 80000BCD0D010C3F, 80000B8D0D010C3F, 80000ACD0D010C3F, 80000A8D0D010C3F, 8000000D0D010C3F, 8000004D0D010C3F, 8000010D0D010C3F, 8000014D0D010C3F, 8000020D0D010C3F, 8000024D0D010C3F, 8000030D0D010C3F, 8000034D0D010C3F, 8000080D0D010C3F, 8000084D0D010C3F, 8000090D0D010C3F, 8000094D0D010C3F, 80000A4D0D010C3F, 80000B0D0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0D                                          = 0x80000B4D0E010C3Full;
//DUPS: 8000008D0E010C3F, 80000A0D0E010C3F, 800000CD0E010C3F, 8000018D0E010C3F, 800001CD0E010C3F, 800003CD0E010C3F, 8000038D0E010C3F, 800002CD0E010C3F, 8000028D0E010C3F, 800009CD0E010C3F, 8000098D0E010C3F, 800008CD0E010C3F, 8000088D0E010C3F, 80000BCD0E010C3F, 80000B8D0E010C3F, 80000ACD0E010C3F, 80000A8D0E010C3F, 8000000D0E010C3F, 8000004D0E010C3F, 8000010D0E010C3F, 8000014D0E010C3F, 8000020D0E010C3F, 8000024D0E010C3F, 8000030D0E010C3F, 8000034D0E010C3F, 8000080D0E010C3F, 8000084D0E010C3F, 8000090D0E010C3F, 8000094D0E010C3F, 80000A4D0E010C3F, 80000B0D0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0D                                          = 0x80000B4D0F010C3Full;
//DUPS: 8000008D0F010C3F, 80000A0D0F010C3F, 800000CD0F010C3F, 8000018D0F010C3F, 800001CD0F010C3F, 800003CD0F010C3F, 8000038D0F010C3F, 800002CD0F010C3F, 8000028D0F010C3F, 800009CD0F010C3F, 8000098D0F010C3F, 800008CD0F010C3F, 8000088D0F010C3F, 80000BCD0F010C3F, 80000B8D0F010C3F, 80000ACD0F010C3F, 80000A8D0F010C3F, 8000000D0F010C3F, 8000004D0F010C3F, 8000010D0F010C3F, 8000014D0F010C3F, 8000020D0F010C3F, 8000024D0F010C3F, 8000030D0F010C3F, 8000034D0F010C3F, 8000080D0F010C3F, 8000084D0F010C3F, 8000090D0F010C3F, 8000094D0F010C3F, 80000A4D0F010C3F, 80000B0D0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0E                                            = 0x80000B4E0D010C3Full;
//DUPS: 8000008E0D010C3F, 80000A0E0D010C3F, 800000CE0D010C3F, 8000018E0D010C3F, 800001CE0D010C3F, 800003CE0D010C3F, 8000038E0D010C3F, 800002CE0D010C3F, 8000028E0D010C3F, 800009CE0D010C3F, 8000098E0D010C3F, 800008CE0D010C3F, 8000088E0D010C3F, 80000BCE0D010C3F, 80000B8E0D010C3F, 80000ACE0D010C3F, 80000A8E0D010C3F, 8000000E0D010C3F, 8000004E0D010C3F, 8000010E0D010C3F, 8000014E0D010C3F, 8000020E0D010C3F, 8000024E0D010C3F, 8000030E0D010C3F, 8000034E0D010C3F, 8000080E0D010C3F, 8000084E0D010C3F, 8000090E0D010C3F, 8000094E0D010C3F, 80000A4E0D010C3F, 80000B0E0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0E                                          = 0x80000B4E0D010C3Full;
//DUPS: 8000008E0D010C3F, 80000A0E0D010C3F, 800000CE0D010C3F, 8000018E0D010C3F, 800001CE0D010C3F, 800003CE0D010C3F, 8000038E0D010C3F, 800002CE0D010C3F, 8000028E0D010C3F, 800009CE0D010C3F, 8000098E0D010C3F, 800008CE0D010C3F, 8000088E0D010C3F, 80000BCE0D010C3F, 80000B8E0D010C3F, 80000ACE0D010C3F, 80000A8E0D010C3F, 8000000E0D010C3F, 8000004E0D010C3F, 8000010E0D010C3F, 8000014E0D010C3F, 8000020E0D010C3F, 8000024E0D010C3F, 8000030E0D010C3F, 8000034E0D010C3F, 8000080E0D010C3F, 8000084E0D010C3F, 8000090E0D010C3F, 8000094E0D010C3F, 80000A4E0D010C3F, 80000B0E0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0E                                          = 0x80000B4E0E010C3Full;
//DUPS: 8000008E0E010C3F, 80000A0E0E010C3F, 800000CE0E010C3F, 8000018E0E010C3F, 800001CE0E010C3F, 800003CE0E010C3F, 8000038E0E010C3F, 800002CE0E010C3F, 8000028E0E010C3F, 800009CE0E010C3F, 8000098E0E010C3F, 800008CE0E010C3F, 8000088E0E010C3F, 80000BCE0E010C3F, 80000B8E0E010C3F, 80000ACE0E010C3F, 80000A8E0E010C3F, 8000000E0E010C3F, 8000004E0E010C3F, 8000010E0E010C3F, 8000014E0E010C3F, 8000020E0E010C3F, 8000024E0E010C3F, 8000030E0E010C3F, 8000034E0E010C3F, 8000080E0E010C3F, 8000084E0E010C3F, 8000090E0E010C3F, 8000094E0E010C3F, 80000A4E0E010C3F, 80000B0E0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0E                                          = 0x80000B4E0F010C3Full;
//DUPS: 8000008E0F010C3F, 80000A0E0F010C3F, 800000CE0F010C3F, 8000018E0F010C3F, 800001CE0F010C3F, 800003CE0F010C3F, 8000038E0F010C3F, 800002CE0F010C3F, 8000028E0F010C3F, 800009CE0F010C3F, 8000098E0F010C3F, 800008CE0F010C3F, 8000088E0F010C3F, 80000BCE0F010C3F, 80000B8E0F010C3F, 80000ACE0F010C3F, 80000A8E0F010C3F, 8000000E0F010C3F, 8000004E0F010C3F, 8000010E0F010C3F, 8000014E0F010C3F, 8000020E0F010C3F, 8000024E0F010C3F, 8000030E0F010C3F, 8000034E0F010C3F, 8000080E0F010C3F, 8000084E0F010C3F, 8000090E0F010C3F, 8000094E0F010C3F, 80000A4E0F010C3F, 80000B0E0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X0F                                            = 0x80000B4F0D010C3Full;
//DUPS: 8000050F0D010C3F, 8000008F0D010C3F, 8000054F0D010C3F, 80000A0F0D010C3F, 800000CF0D010C3F, 8000018F0D010C3F, 800001CF0D010C3F, 800003CF0D010C3F, 8000038F0D010C3F, 800002CF0D010C3F, 8000028F0D010C3F, 800009CF0D010C3F, 8000098F0D010C3F, 800008CF0D010C3F, 8000088F0D010C3F, 80000BCF0D010C3F, 80000B8F0D010C3F, 80000ACF0D010C3F, 80000A8F0D010C3F, 8000000F0D010C3F, 8000004F0D010C3F, 8000010F0D010C3F, 8000014F0D010C3F, 8000020F0D010C3F, 8000024F0D010C3F, 8000030F0D010C3F, 8000034F0D010C3F, 8000080F0D010C3F, 8000084F0D010C3F, 8000090F0D010C3F, 8000094F0D010C3F, 80000A4F0D010C3F, 80000B0F0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X0F                                          = 0x80000B4F0D010C3Full;
//DUPS: 8000050F0D010C3F, 8000008F0D010C3F, 8000054F0D010C3F, 80000A0F0D010C3F, 800000CF0D010C3F, 8000018F0D010C3F, 800001CF0D010C3F, 800003CF0D010C3F, 8000038F0D010C3F, 800002CF0D010C3F, 8000028F0D010C3F, 800009CF0D010C3F, 8000098F0D010C3F, 800008CF0D010C3F, 8000088F0D010C3F, 80000BCF0D010C3F, 80000B8F0D010C3F, 80000ACF0D010C3F, 80000A8F0D010C3F, 8000000F0D010C3F, 8000004F0D010C3F, 8000010F0D010C3F, 8000014F0D010C3F, 8000020F0D010C3F, 8000024F0D010C3F, 8000030F0D010C3F, 8000034F0D010C3F, 8000080F0D010C3F, 8000084F0D010C3F, 8000090F0D010C3F, 8000094F0D010C3F, 80000A4F0D010C3F, 80000B0F0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X0F                                          = 0x80000B4F0E010C3Full;
//DUPS: 8000050F0E010C3F, 8000008F0E010C3F, 8000054F0E010C3F, 80000A0F0E010C3F, 800000CF0E010C3F, 8000018F0E010C3F, 800001CF0E010C3F, 800003CF0E010C3F, 8000038F0E010C3F, 800002CF0E010C3F, 8000028F0E010C3F, 800009CF0E010C3F, 8000098F0E010C3F, 800008CF0E010C3F, 8000088F0E010C3F, 80000BCF0E010C3F, 80000B8F0E010C3F, 80000ACF0E010C3F, 80000A8F0E010C3F, 8000000F0E010C3F, 8000004F0E010C3F, 8000010F0E010C3F, 8000014F0E010C3F, 8000020F0E010C3F, 8000024F0E010C3F, 8000030F0E010C3F, 8000034F0E010C3F, 8000080F0E010C3F, 8000084F0E010C3F, 8000090F0E010C3F, 8000094F0E010C3F, 80000A4F0E010C3F, 80000B0F0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X0F                                          = 0x80000B4F0F010C3Full;
//DUPS: 8000050F0F010C3F, 8000008F0F010C3F, 8000054F0F010C3F, 80000A0F0F010C3F, 800000CF0F010C3F, 8000018F0F010C3F, 800001CF0F010C3F, 800003CF0F010C3F, 8000038F0F010C3F, 800002CF0F010C3F, 8000028F0F010C3F, 800009CF0F010C3F, 8000098F0F010C3F, 800008CF0F010C3F, 8000088F0F010C3F, 80000BCF0F010C3F, 80000B8F0F010C3F, 80000ACF0F010C3F, 80000A8F0F010C3F, 8000000F0F010C3F, 8000004F0F010C3F, 8000010F0F010C3F, 8000014F0F010C3F, 8000020F0F010C3F, 8000024F0F010C3F, 8000030F0F010C3F, 8000034F0F010C3F, 8000080F0F010C3F, 8000084F0F010C3F, 8000090F0F010C3F, 8000094F0F010C3F, 80000A4F0F010C3F, 80000B0F0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X10                                            = 0x80000B500D010C3Full;
//DUPS: 800005100D010C3F, 800000900D010C3F, 800005500D010C3F, 80000A100D010C3F, 800000D00D010C3F, 800001900D010C3F, 800001D00D010C3F, 800003D00D010C3F, 800003900D010C3F, 800002D00D010C3F, 800002900D010C3F, 800009D00D010C3F, 800009900D010C3F, 800008D00D010C3F, 800008900D010C3F, 80000BD00D010C3F, 80000B900D010C3F, 80000AD00D010C3F, 80000A900D010C3F, 800000100D010C3F, 800000500D010C3F, 800001100D010C3F, 800001500D010C3F, 800002100D010C3F, 800002500D010C3F, 800003100D010C3F, 800003500D010C3F, 800008100D010C3F, 800008500D010C3F, 800009100D010C3F, 800009500D010C3F, 80000A500D010C3F, 80000B100D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X10                                          = 0x80000B500D010C3Full;
//DUPS: 800005100D010C3F, 800000900D010C3F, 800005500D010C3F, 80000A100D010C3F, 800000D00D010C3F, 800001900D010C3F, 800001D00D010C3F, 800003D00D010C3F, 800003900D010C3F, 800002D00D010C3F, 800002900D010C3F, 800009D00D010C3F, 800009900D010C3F, 800008D00D010C3F, 800008900D010C3F, 80000BD00D010C3F, 80000B900D010C3F, 80000AD00D010C3F, 80000A900D010C3F, 800000100D010C3F, 800000500D010C3F, 800001100D010C3F, 800001500D010C3F, 800002100D010C3F, 800002500D010C3F, 800003100D010C3F, 800003500D010C3F, 800008100D010C3F, 800008500D010C3F, 800009100D010C3F, 800009500D010C3F, 80000A500D010C3F, 80000B100D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X10                                          = 0x80000B500E010C3Full;
//DUPS: 800005100E010C3F, 800000900E010C3F, 800005500E010C3F, 80000A100E010C3F, 800000D00E010C3F, 800001900E010C3F, 800001D00E010C3F, 800003D00E010C3F, 800003900E010C3F, 800002D00E010C3F, 800002900E010C3F, 800009D00E010C3F, 800009900E010C3F, 800008D00E010C3F, 800008900E010C3F, 80000BD00E010C3F, 80000B900E010C3F, 80000AD00E010C3F, 80000A900E010C3F, 800000100E010C3F, 800000500E010C3F, 800001100E010C3F, 800001500E010C3F, 800002100E010C3F, 800002500E010C3F, 800003100E010C3F, 800003500E010C3F, 800008100E010C3F, 800008500E010C3F, 800009100E010C3F, 800009500E010C3F, 80000A500E010C3F, 80000B100E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X10                                          = 0x80000B500F010C3Full;
//DUPS: 800005100F010C3F, 800000900F010C3F, 800005500F010C3F, 80000A100F010C3F, 800000D00F010C3F, 800001900F010C3F, 800001D00F010C3F, 800003D00F010C3F, 800003900F010C3F, 800002D00F010C3F, 800002900F010C3F, 800009D00F010C3F, 800009900F010C3F, 800008D00F010C3F, 800008900F010C3F, 80000BD00F010C3F, 80000B900F010C3F, 80000AD00F010C3F, 80000A900F010C3F, 800000100F010C3F, 800000500F010C3F, 800001100F010C3F, 800001500F010C3F, 800002100F010C3F, 800002500F010C3F, 800003100F010C3F, 800003500F010C3F, 800008100F010C3F, 800008500F010C3F, 800009100F010C3F, 800009500F010C3F, 80000A500F010C3F, 80000B100F010C3F,

static const uint64_t P9N2_PEC_SCOM0X11                                            = 0x80000B510D010C3Full;
//DUPS: 800005110D010C3F, 800000910D010C3F, 800005510D010C3F, 80000A110D010C3F, 800000D10D010C3F, 800001910D010C3F, 800001D10D010C3F, 800003D10D010C3F, 800003910D010C3F, 800002D10D010C3F, 800002910D010C3F, 800009D10D010C3F, 800009910D010C3F, 800008D10D010C3F, 800008910D010C3F, 80000BD10D010C3F, 80000B910D010C3F, 80000AD10D010C3F, 80000A910D010C3F, 800000110D010C3F, 800000510D010C3F, 800001110D010C3F, 800001510D010C3F, 800002110D010C3F, 800002510D010C3F, 800003110D010C3F, 800003510D010C3F, 800008110D010C3F, 800008510D010C3F, 800009110D010C3F, 800009510D010C3F, 80000A510D010C3F, 80000B110D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X11                                          = 0x80000B510D010C3Full;
//DUPS: 800005110D010C3F, 800000910D010C3F, 800005510D010C3F, 80000A110D010C3F, 800000D10D010C3F, 800001910D010C3F, 800001D10D010C3F, 800003D10D010C3F, 800003910D010C3F, 800002D10D010C3F, 800002910D010C3F, 800009D10D010C3F, 800009910D010C3F, 800008D10D010C3F, 800008910D010C3F, 80000BD10D010C3F, 80000B910D010C3F, 80000AD10D010C3F, 80000A910D010C3F, 800000110D010C3F, 800000510D010C3F, 800001110D010C3F, 800001510D010C3F, 800002110D010C3F, 800002510D010C3F, 800003110D010C3F, 800003510D010C3F, 800008110D010C3F, 800008510D010C3F, 800009110D010C3F, 800009510D010C3F, 80000A510D010C3F, 80000B110D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X11                                          = 0x80000B510E010C3Full;
//DUPS: 800005110E010C3F, 800000910E010C3F, 800005510E010C3F, 80000A110E010C3F, 800000D10E010C3F, 800001910E010C3F, 800001D10E010C3F, 800003D10E010C3F, 800003910E010C3F, 800002D10E010C3F, 800002910E010C3F, 800009D10E010C3F, 800009910E010C3F, 800008D10E010C3F, 800008910E010C3F, 80000BD10E010C3F, 80000B910E010C3F, 80000AD10E010C3F, 80000A910E010C3F, 800000110E010C3F, 800000510E010C3F, 800001110E010C3F, 800001510E010C3F, 800002110E010C3F, 800002510E010C3F, 800003110E010C3F, 800003510E010C3F, 800008110E010C3F, 800008510E010C3F, 800009110E010C3F, 800009510E010C3F, 80000A510E010C3F, 80000B110E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X11                                          = 0x80000B510F010C3Full;
//DUPS: 800005110F010C3F, 800000910F010C3F, 800005510F010C3F, 80000A110F010C3F, 800000D10F010C3F, 800001910F010C3F, 800001D10F010C3F, 800003D10F010C3F, 800003910F010C3F, 800002D10F010C3F, 800002910F010C3F, 800009D10F010C3F, 800009910F010C3F, 800008D10F010C3F, 800008910F010C3F, 80000BD10F010C3F, 80000B910F010C3F, 80000AD10F010C3F, 80000A910F010C3F, 800000110F010C3F, 800000510F010C3F, 800001110F010C3F, 800001510F010C3F, 800002110F010C3F, 800002510F010C3F, 800003110F010C3F, 800003510F010C3F, 800008110F010C3F, 800008510F010C3F, 800009110F010C3F, 800009510F010C3F, 80000A510F010C3F, 80000B110F010C3F,

static const uint64_t P9N2_PEC_SCOM0X12                                            = 0x80000B520D010C3Full;
//DUPS: 800005120D010C3F, 800000920D010C3F, 800005520D010C3F, 80000A120D010C3F, 800000D20D010C3F, 800001920D010C3F, 800001D20D010C3F, 800003D20D010C3F, 800003920D010C3F, 800002D20D010C3F, 800002920D010C3F, 800009D20D010C3F, 800009920D010C3F, 800008D20D010C3F, 800008920D010C3F, 80000BD20D010C3F, 80000B920D010C3F, 80000AD20D010C3F, 80000A920D010C3F, 800000120D010C3F, 800000520D010C3F, 800001120D010C3F, 800001520D010C3F, 800002120D010C3F, 800002520D010C3F, 800003120D010C3F, 800003520D010C3F, 800008120D010C3F, 800008520D010C3F, 800009120D010C3F, 800009520D010C3F, 80000A520D010C3F, 80000B120D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X12                                          = 0x80000B520D010C3Full;
//DUPS: 800005120D010C3F, 800000920D010C3F, 800005520D010C3F, 80000A120D010C3F, 800000D20D010C3F, 800001920D010C3F, 800001D20D010C3F, 800003D20D010C3F, 800003920D010C3F, 800002D20D010C3F, 800002920D010C3F, 800009D20D010C3F, 800009920D010C3F, 800008D20D010C3F, 800008920D010C3F, 80000BD20D010C3F, 80000B920D010C3F, 80000AD20D010C3F, 80000A920D010C3F, 800000120D010C3F, 800000520D010C3F, 800001120D010C3F, 800001520D010C3F, 800002120D010C3F, 800002520D010C3F, 800003120D010C3F, 800003520D010C3F, 800008120D010C3F, 800008520D010C3F, 800009120D010C3F, 800009520D010C3F, 80000A520D010C3F, 80000B120D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X12                                          = 0x80000B520E010C3Full;
//DUPS: 800005120E010C3F, 800000920E010C3F, 800005520E010C3F, 80000A120E010C3F, 800000D20E010C3F, 800001920E010C3F, 800001D20E010C3F, 800003D20E010C3F, 800003920E010C3F, 800002D20E010C3F, 800002920E010C3F, 800009D20E010C3F, 800009920E010C3F, 800008D20E010C3F, 800008920E010C3F, 80000BD20E010C3F, 80000B920E010C3F, 80000AD20E010C3F, 80000A920E010C3F, 800000120E010C3F, 800000520E010C3F, 800001120E010C3F, 800001520E010C3F, 800002120E010C3F, 800002520E010C3F, 800003120E010C3F, 800003520E010C3F, 800008120E010C3F, 800008520E010C3F, 800009120E010C3F, 800009520E010C3F, 80000A520E010C3F, 80000B120E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X12                                          = 0x80000B520F010C3Full;
//DUPS: 800005120F010C3F, 800000920F010C3F, 800005520F010C3F, 80000A120F010C3F, 800000D20F010C3F, 800001920F010C3F, 800001D20F010C3F, 800003D20F010C3F, 800003920F010C3F, 800002D20F010C3F, 800002920F010C3F, 800009D20F010C3F, 800009920F010C3F, 800008D20F010C3F, 800008920F010C3F, 80000BD20F010C3F, 80000B920F010C3F, 80000AD20F010C3F, 80000A920F010C3F, 800000120F010C3F, 800000520F010C3F, 800001120F010C3F, 800001520F010C3F, 800002120F010C3F, 800002520F010C3F, 800003120F010C3F, 800003520F010C3F, 800008120F010C3F, 800008520F010C3F, 800009120F010C3F, 800009520F010C3F, 80000A520F010C3F, 80000B120F010C3F,

static const uint64_t P9N2_PEC_SCOM0X13                                            = 0x80000B530D010C3Full;
//DUPS: 800005130D010C3F, 800000930D010C3F, 800005530D010C3F, 80000A130D010C3F, 800000D30D010C3F, 800001930D010C3F, 800001D30D010C3F, 800003D30D010C3F, 800003930D010C3F, 800002D30D010C3F, 800002930D010C3F, 800009D30D010C3F, 800009930D010C3F, 800008D30D010C3F, 800008930D010C3F, 80000BD30D010C3F, 80000B930D010C3F, 80000AD30D010C3F, 80000A930D010C3F, 800000130D010C3F, 800000530D010C3F, 800001130D010C3F, 800001530D010C3F, 800002130D010C3F, 800002530D010C3F, 800003130D010C3F, 800003530D010C3F, 800008130D010C3F, 800008530D010C3F, 800009130D010C3F, 800009530D010C3F, 80000A530D010C3F, 80000B130D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X13                                          = 0x80000B530D010C3Full;
//DUPS: 800005130D010C3F, 800000930D010C3F, 800005530D010C3F, 80000A130D010C3F, 800000D30D010C3F, 800001930D010C3F, 800001D30D010C3F, 800003D30D010C3F, 800003930D010C3F, 800002D30D010C3F, 800002930D010C3F, 800009D30D010C3F, 800009930D010C3F, 800008D30D010C3F, 800008930D010C3F, 80000BD30D010C3F, 80000B930D010C3F, 80000AD30D010C3F, 80000A930D010C3F, 800000130D010C3F, 800000530D010C3F, 800001130D010C3F, 800001530D010C3F, 800002130D010C3F, 800002530D010C3F, 800003130D010C3F, 800003530D010C3F, 800008130D010C3F, 800008530D010C3F, 800009130D010C3F, 800009530D010C3F, 80000A530D010C3F, 80000B130D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X13                                          = 0x80000B530E010C3Full;
//DUPS: 800005130E010C3F, 800000930E010C3F, 800005530E010C3F, 80000A130E010C3F, 800000D30E010C3F, 800001930E010C3F, 800001D30E010C3F, 800003D30E010C3F, 800003930E010C3F, 800002D30E010C3F, 800002930E010C3F, 800009D30E010C3F, 800009930E010C3F, 800008D30E010C3F, 800008930E010C3F, 80000BD30E010C3F, 80000B930E010C3F, 80000AD30E010C3F, 80000A930E010C3F, 800000130E010C3F, 800000530E010C3F, 800001130E010C3F, 800001530E010C3F, 800002130E010C3F, 800002530E010C3F, 800003130E010C3F, 800003530E010C3F, 800008130E010C3F, 800008530E010C3F, 800009130E010C3F, 800009530E010C3F, 80000A530E010C3F, 80000B130E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X13                                          = 0x80000B530F010C3Full;
//DUPS: 800005130F010C3F, 800000930F010C3F, 800005530F010C3F, 80000A130F010C3F, 800000D30F010C3F, 800001930F010C3F, 800001D30F010C3F, 800003D30F010C3F, 800003930F010C3F, 800002D30F010C3F, 800002930F010C3F, 800009D30F010C3F, 800009930F010C3F, 800008D30F010C3F, 800008930F010C3F, 80000BD30F010C3F, 80000B930F010C3F, 80000AD30F010C3F, 80000A930F010C3F, 800000130F010C3F, 800000530F010C3F, 800001130F010C3F, 800001530F010C3F, 800002130F010C3F, 800002530F010C3F, 800003130F010C3F, 800003530F010C3F, 800008130F010C3F, 800008530F010C3F, 800009130F010C3F, 800009530F010C3F, 80000A530F010C3F, 80000B130F010C3F,

static const uint64_t P9N2_PEC_SCOM0X14                                            = 0x80000B540D010C3Full;
//DUPS: 800005140D010C3F, 800000940D010C3F, 800005540D010C3F, 80000A140D010C3F, 800000D40D010C3F, 800001940D010C3F, 800001D40D010C3F, 800003D40D010C3F, 800003940D010C3F, 800002D40D010C3F, 800002940D010C3F, 800009D40D010C3F, 800009940D010C3F, 800008D40D010C3F, 800008940D010C3F, 80000BD40D010C3F, 80000B940D010C3F, 80000AD40D010C3F, 80000A940D010C3F, 800000140D010C3F, 800000540D010C3F, 800001140D010C3F, 800001540D010C3F, 800002140D010C3F, 800002540D010C3F, 800003140D010C3F, 800003540D010C3F, 800008140D010C3F, 800008540D010C3F, 800009140D010C3F, 800009540D010C3F, 80000A540D010C3F, 80000B140D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X14                                          = 0x80000B540D010C3Full;
//DUPS: 800005140D010C3F, 800000940D010C3F, 800005540D010C3F, 80000A140D010C3F, 800000D40D010C3F, 800001940D010C3F, 800001D40D010C3F, 800003D40D010C3F, 800003940D010C3F, 800002D40D010C3F, 800002940D010C3F, 800009D40D010C3F, 800009940D010C3F, 800008D40D010C3F, 800008940D010C3F, 80000BD40D010C3F, 80000B940D010C3F, 80000AD40D010C3F, 80000A940D010C3F, 800000140D010C3F, 800000540D010C3F, 800001140D010C3F, 800001540D010C3F, 800002140D010C3F, 800002540D010C3F, 800003140D010C3F, 800003540D010C3F, 800008140D010C3F, 800008540D010C3F, 800009140D010C3F, 800009540D010C3F, 80000A540D010C3F, 80000B140D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X14                                          = 0x80000B540E010C3Full;
//DUPS: 800005140E010C3F, 800000940E010C3F, 800005540E010C3F, 80000A140E010C3F, 800000D40E010C3F, 800001940E010C3F, 800001D40E010C3F, 800003D40E010C3F, 800003940E010C3F, 800002D40E010C3F, 800002940E010C3F, 800009D40E010C3F, 800009940E010C3F, 800008D40E010C3F, 800008940E010C3F, 80000BD40E010C3F, 80000B940E010C3F, 80000AD40E010C3F, 80000A940E010C3F, 800000140E010C3F, 800000540E010C3F, 800001140E010C3F, 800001540E010C3F, 800002140E010C3F, 800002540E010C3F, 800003140E010C3F, 800003540E010C3F, 800008140E010C3F, 800008540E010C3F, 800009140E010C3F, 800009540E010C3F, 80000A540E010C3F, 80000B140E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X14                                          = 0x80000B540F010C3Full;
//DUPS: 800005140F010C3F, 800000940F010C3F, 800005540F010C3F, 80000A140F010C3F, 800000D40F010C3F, 800001940F010C3F, 800001D40F010C3F, 800003D40F010C3F, 800003940F010C3F, 800002D40F010C3F, 800002940F010C3F, 800009D40F010C3F, 800009940F010C3F, 800008D40F010C3F, 800008940F010C3F, 80000BD40F010C3F, 80000B940F010C3F, 80000AD40F010C3F, 80000A940F010C3F, 800000140F010C3F, 800000540F010C3F, 800001140F010C3F, 800001540F010C3F, 800002140F010C3F, 800002540F010C3F, 800003140F010C3F, 800003540F010C3F, 800008140F010C3F, 800008540F010C3F, 800009140F010C3F, 800009540F010C3F, 80000A540F010C3F, 80000B140F010C3F,

static const uint64_t P9N2_PEC_SCOM0X15                                            = 0x80000B550D010C3Full;
//DUPS: 800004150D010C3F, 800000950D010C3F, 80000A150D010C3F, 800000D50D010C3F, 800001950D010C3F, 800001D50D010C3F, 800003D50D010C3F, 800003950D010C3F, 800002D50D010C3F, 800002950D010C3F, 800009D50D010C3F, 800009950D010C3F, 800008D50D010C3F, 800008950D010C3F, 80000BD50D010C3F, 80000B950D010C3F, 80000AD50D010C3F, 80000A950D010C3F, 800000150D010C3F, 800000550D010C3F, 800001150D010C3F, 800001550D010C3F, 800002150D010C3F, 800002550D010C3F, 800003150D010C3F, 800003550D010C3F, 800008150D010C3F, 800008550D010C3F, 800009150D010C3F, 800009550D010C3F, 80000A550D010C3F, 80000B150D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X15                                          = 0x80000B550D010C3Full;
//DUPS: 800004150D010C3F, 800000950D010C3F, 80000A150D010C3F, 800000D50D010C3F, 800001950D010C3F, 800001D50D010C3F, 800003D50D010C3F, 800003950D010C3F, 800002D50D010C3F, 800002950D010C3F, 800009D50D010C3F, 800009950D010C3F, 800008D50D010C3F, 800008950D010C3F, 80000BD50D010C3F, 80000B950D010C3F, 80000AD50D010C3F, 80000A950D010C3F, 800000150D010C3F, 800000550D010C3F, 800001150D010C3F, 800001550D010C3F, 800002150D010C3F, 800002550D010C3F, 800003150D010C3F, 800003550D010C3F, 800008150D010C3F, 800008550D010C3F, 800009150D010C3F, 800009550D010C3F, 80000A550D010C3F, 80000B150D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X15                                          = 0x80000B550E010C3Full;
//DUPS: 800004150E010C3F, 800000950E010C3F, 80000A150E010C3F, 800000D50E010C3F, 800001950E010C3F, 800001D50E010C3F, 800003D50E010C3F, 800003950E010C3F, 800002D50E010C3F, 800002950E010C3F, 800009D50E010C3F, 800009950E010C3F, 800008D50E010C3F, 800008950E010C3F, 80000BD50E010C3F, 80000B950E010C3F, 80000AD50E010C3F, 80000A950E010C3F, 800000150E010C3F, 800000550E010C3F, 800001150E010C3F, 800001550E010C3F, 800002150E010C3F, 800002550E010C3F, 800003150E010C3F, 800003550E010C3F, 800008150E010C3F, 800008550E010C3F, 800009150E010C3F, 800009550E010C3F, 80000A550E010C3F, 80000B150E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X15                                          = 0x80000B550F010C3Full;
//DUPS: 800004150F010C3F, 800000950F010C3F, 80000A150F010C3F, 800000D50F010C3F, 800001950F010C3F, 800001D50F010C3F, 800003D50F010C3F, 800003950F010C3F, 800002D50F010C3F, 800002950F010C3F, 800009D50F010C3F, 800009950F010C3F, 800008D50F010C3F, 800008950F010C3F, 80000BD50F010C3F, 80000B950F010C3F, 80000AD50F010C3F, 80000A950F010C3F, 800000150F010C3F, 800000550F010C3F, 800001150F010C3F, 800001550F010C3F, 800002150F010C3F, 800002550F010C3F, 800003150F010C3F, 800003550F010C3F, 800008150F010C3F, 800008550F010C3F, 800009150F010C3F, 800009550F010C3F, 80000A550F010C3F, 80000B150F010C3F,

static const uint64_t P9N2_PEC_SCOM0X16                                            = 0x80000B560D010C3Full;
//DUPS: 800004160D010C3F, 800000960D010C3F, 80000A160D010C3F, 800000D60D010C3F, 800001960D010C3F, 800001D60D010C3F, 800003D60D010C3F, 800003960D010C3F, 800002D60D010C3F, 800002960D010C3F, 800009D60D010C3F, 800009960D010C3F, 800008D60D010C3F, 800008960D010C3F, 80000BD60D010C3F, 80000B960D010C3F, 80000AD60D010C3F, 80000A960D010C3F, 800000160D010C3F, 800000560D010C3F, 800001160D010C3F, 800001560D010C3F, 800002160D010C3F, 800002560D010C3F, 800003160D010C3F, 800003560D010C3F, 800008160D010C3F, 800008560D010C3F, 800009160D010C3F, 800009560D010C3F, 80000A560D010C3F, 80000B160D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X16                                          = 0x80000B560D010C3Full;
//DUPS: 800004160D010C3F, 800000960D010C3F, 80000A160D010C3F, 800000D60D010C3F, 800001960D010C3F, 800001D60D010C3F, 800003D60D010C3F, 800003960D010C3F, 800002D60D010C3F, 800002960D010C3F, 800009D60D010C3F, 800009960D010C3F, 800008D60D010C3F, 800008960D010C3F, 80000BD60D010C3F, 80000B960D010C3F, 80000AD60D010C3F, 80000A960D010C3F, 800000160D010C3F, 800000560D010C3F, 800001160D010C3F, 800001560D010C3F, 800002160D010C3F, 800002560D010C3F, 800003160D010C3F, 800003560D010C3F, 800008160D010C3F, 800008560D010C3F, 800009160D010C3F, 800009560D010C3F, 80000A560D010C3F, 80000B160D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X16                                          = 0x80000B560E010C3Full;
//DUPS: 800004160E010C3F, 800000960E010C3F, 80000A160E010C3F, 800000D60E010C3F, 800001960E010C3F, 800001D60E010C3F, 800003D60E010C3F, 800003960E010C3F, 800002D60E010C3F, 800002960E010C3F, 800009D60E010C3F, 800009960E010C3F, 800008D60E010C3F, 800008960E010C3F, 80000BD60E010C3F, 80000B960E010C3F, 80000AD60E010C3F, 80000A960E010C3F, 800000160E010C3F, 800000560E010C3F, 800001160E010C3F, 800001560E010C3F, 800002160E010C3F, 800002560E010C3F, 800003160E010C3F, 800003560E010C3F, 800008160E010C3F, 800008560E010C3F, 800009160E010C3F, 800009560E010C3F, 80000A560E010C3F, 80000B160E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X16                                          = 0x80000B560F010C3Full;
//DUPS: 800004160F010C3F, 800000960F010C3F, 80000A160F010C3F, 800000D60F010C3F, 800001960F010C3F, 800001D60F010C3F, 800003D60F010C3F, 800003960F010C3F, 800002D60F010C3F, 800002960F010C3F, 800009D60F010C3F, 800009960F010C3F, 800008D60F010C3F, 800008960F010C3F, 80000BD60F010C3F, 80000B960F010C3F, 80000AD60F010C3F, 80000A960F010C3F, 800000160F010C3F, 800000560F010C3F, 800001160F010C3F, 800001560F010C3F, 800002160F010C3F, 800002560F010C3F, 800003160F010C3F, 800003560F010C3F, 800008160F010C3F, 800008560F010C3F, 800009160F010C3F, 800009560F010C3F, 80000A560F010C3F, 80000B160F010C3F,

static const uint64_t P9N2_PEC_SCOM0X17                                            = 0x80000B570D010C3Full;
//DUPS: 800004170D010C3F, 800000970D010C3F, 80000A170D010C3F, 800000D70D010C3F, 800001970D010C3F, 800001D70D010C3F, 800003D70D010C3F, 800003970D010C3F, 800002D70D010C3F, 800002970D010C3F, 800009D70D010C3F, 800009970D010C3F, 800008D70D010C3F, 800008970D010C3F, 80000BD70D010C3F, 80000B970D010C3F, 80000AD70D010C3F, 80000A970D010C3F, 800000170D010C3F, 800000570D010C3F, 800001170D010C3F, 800001570D010C3F, 800002170D010C3F, 800002570D010C3F, 800003170D010C3F, 800003570D010C3F, 800008170D010C3F, 800008570D010C3F, 800009170D010C3F, 800009570D010C3F, 80000A570D010C3F, 80000B170D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X17                                          = 0x80000B570D010C3Full;
//DUPS: 800004170D010C3F, 800000970D010C3F, 80000A170D010C3F, 800000D70D010C3F, 800001970D010C3F, 800001D70D010C3F, 800003D70D010C3F, 800003970D010C3F, 800002D70D010C3F, 800002970D010C3F, 800009D70D010C3F, 800009970D010C3F, 800008D70D010C3F, 800008970D010C3F, 80000BD70D010C3F, 80000B970D010C3F, 80000AD70D010C3F, 80000A970D010C3F, 800000170D010C3F, 800000570D010C3F, 800001170D010C3F, 800001570D010C3F, 800002170D010C3F, 800002570D010C3F, 800003170D010C3F, 800003570D010C3F, 800008170D010C3F, 800008570D010C3F, 800009170D010C3F, 800009570D010C3F, 80000A570D010C3F, 80000B170D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X17                                          = 0x80000B570E010C3Full;
//DUPS: 800004170E010C3F, 800000970E010C3F, 80000A170E010C3F, 800000D70E010C3F, 800001970E010C3F, 800001D70E010C3F, 800003D70E010C3F, 800003970E010C3F, 800002D70E010C3F, 800002970E010C3F, 800009D70E010C3F, 800009970E010C3F, 800008D70E010C3F, 800008970E010C3F, 80000BD70E010C3F, 80000B970E010C3F, 80000AD70E010C3F, 80000A970E010C3F, 800000170E010C3F, 800000570E010C3F, 800001170E010C3F, 800001570E010C3F, 800002170E010C3F, 800002570E010C3F, 800003170E010C3F, 800003570E010C3F, 800008170E010C3F, 800008570E010C3F, 800009170E010C3F, 800009570E010C3F, 80000A570E010C3F, 80000B170E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X17                                          = 0x80000B570F010C3Full;
//DUPS: 800004170F010C3F, 800000970F010C3F, 80000A170F010C3F, 800000D70F010C3F, 800001970F010C3F, 800001D70F010C3F, 800003D70F010C3F, 800003970F010C3F, 800002D70F010C3F, 800002970F010C3F, 800009D70F010C3F, 800009970F010C3F, 800008D70F010C3F, 800008970F010C3F, 80000BD70F010C3F, 80000B970F010C3F, 80000AD70F010C3F, 80000A970F010C3F, 800000170F010C3F, 800000570F010C3F, 800001170F010C3F, 800001570F010C3F, 800002170F010C3F, 800002570F010C3F, 800003170F010C3F, 800003570F010C3F, 800008170F010C3F, 800008570F010C3F, 800009170F010C3F, 800009570F010C3F, 80000A570F010C3F, 80000B170F010C3F,

static const uint64_t P9N2_PEC_SCOM0X18                                            = 0x80000B580D010C3Full;
//DUPS: 800004180D010C3F, 800000980D010C3F, 80000A180D010C3F, 800000D80D010C3F, 800001980D010C3F, 800001D80D010C3F, 800003D80D010C3F, 800003980D010C3F, 800002D80D010C3F, 800002980D010C3F, 800009D80D010C3F, 800009980D010C3F, 800008D80D010C3F, 800008980D010C3F, 80000BD80D010C3F, 80000B980D010C3F, 80000AD80D010C3F, 80000A980D010C3F, 800000180D010C3F, 800000580D010C3F, 800001180D010C3F, 800001580D010C3F, 800002180D010C3F, 800002580D010C3F, 800003180D010C3F, 800003580D010C3F, 800008180D010C3F, 800008580D010C3F, 800009180D010C3F, 800009580D010C3F, 80000A580D010C3F, 80000B180D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X18                                          = 0x80000B580D010C3Full;
//DUPS: 800004180D010C3F, 800000980D010C3F, 80000A180D010C3F, 800000D80D010C3F, 800001980D010C3F, 800001D80D010C3F, 800003D80D010C3F, 800003980D010C3F, 800002D80D010C3F, 800002980D010C3F, 800009D80D010C3F, 800009980D010C3F, 800008D80D010C3F, 800008980D010C3F, 80000BD80D010C3F, 80000B980D010C3F, 80000AD80D010C3F, 80000A980D010C3F, 800000180D010C3F, 800000580D010C3F, 800001180D010C3F, 800001580D010C3F, 800002180D010C3F, 800002580D010C3F, 800003180D010C3F, 800003580D010C3F, 800008180D010C3F, 800008580D010C3F, 800009180D010C3F, 800009580D010C3F, 80000A580D010C3F, 80000B180D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X18                                          = 0x80000B580E010C3Full;
//DUPS: 800004180E010C3F, 800000980E010C3F, 80000A180E010C3F, 800000D80E010C3F, 800001980E010C3F, 800001D80E010C3F, 800003D80E010C3F, 800003980E010C3F, 800002D80E010C3F, 800002980E010C3F, 800009D80E010C3F, 800009980E010C3F, 800008D80E010C3F, 800008980E010C3F, 80000BD80E010C3F, 80000B980E010C3F, 80000AD80E010C3F, 80000A980E010C3F, 800000180E010C3F, 800000580E010C3F, 800001180E010C3F, 800001580E010C3F, 800002180E010C3F, 800002580E010C3F, 800003180E010C3F, 800003580E010C3F, 800008180E010C3F, 800008580E010C3F, 800009180E010C3F, 800009580E010C3F, 80000A580E010C3F, 80000B180E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X18                                          = 0x80000B580F010C3Full;
//DUPS: 800004180F010C3F, 800000980F010C3F, 80000A180F010C3F, 800000D80F010C3F, 800001980F010C3F, 800001D80F010C3F, 800003D80F010C3F, 800003980F010C3F, 800002D80F010C3F, 800002980F010C3F, 800009D80F010C3F, 800009980F010C3F, 800008D80F010C3F, 800008980F010C3F, 80000BD80F010C3F, 80000B980F010C3F, 80000AD80F010C3F, 80000A980F010C3F, 800000180F010C3F, 800000580F010C3F, 800001180F010C3F, 800001580F010C3F, 800002180F010C3F, 800002580F010C3F, 800003180F010C3F, 800003580F010C3F, 800008180F010C3F, 800008580F010C3F, 800009180F010C3F, 800009580F010C3F, 80000A580F010C3F, 80000B180F010C3F,

static const uint64_t P9N2_PEC_SCOM0X19                                            = 0x80000B590D010C3Full;
//DUPS: 800004190D010C3F, 800000990D010C3F, 80000A190D010C3F, 800000D90D010C3F, 800001990D010C3F, 800001D90D010C3F, 800003D90D010C3F, 800003990D010C3F, 800002D90D010C3F, 800002990D010C3F, 800009D90D010C3F, 800009990D010C3F, 800008D90D010C3F, 800008990D010C3F, 80000BD90D010C3F, 80000B990D010C3F, 80000AD90D010C3F, 80000A990D010C3F, 800000190D010C3F, 800000590D010C3F, 800001190D010C3F, 800001590D010C3F, 800002190D010C3F, 800002590D010C3F, 800003190D010C3F, 800003590D010C3F, 800008190D010C3F, 800008590D010C3F, 800009190D010C3F, 800009590D010C3F, 80000A590D010C3F, 80000B190D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X19                                          = 0x80000B590D010C3Full;
//DUPS: 800004190D010C3F, 800000990D010C3F, 80000A190D010C3F, 800000D90D010C3F, 800001990D010C3F, 800001D90D010C3F, 800003D90D010C3F, 800003990D010C3F, 800002D90D010C3F, 800002990D010C3F, 800009D90D010C3F, 800009990D010C3F, 800008D90D010C3F, 800008990D010C3F, 80000BD90D010C3F, 80000B990D010C3F, 80000AD90D010C3F, 80000A990D010C3F, 800000190D010C3F, 800000590D010C3F, 800001190D010C3F, 800001590D010C3F, 800002190D010C3F, 800002590D010C3F, 800003190D010C3F, 800003590D010C3F, 800008190D010C3F, 800008590D010C3F, 800009190D010C3F, 800009590D010C3F, 80000A590D010C3F, 80000B190D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X19                                          = 0x80000B590E010C3Full;
//DUPS: 800004190E010C3F, 800000990E010C3F, 80000A190E010C3F, 800000D90E010C3F, 800001990E010C3F, 800001D90E010C3F, 800003D90E010C3F, 800003990E010C3F, 800002D90E010C3F, 800002990E010C3F, 800009D90E010C3F, 800009990E010C3F, 800008D90E010C3F, 800008990E010C3F, 80000BD90E010C3F, 80000B990E010C3F, 80000AD90E010C3F, 80000A990E010C3F, 800000190E010C3F, 800000590E010C3F, 800001190E010C3F, 800001590E010C3F, 800002190E010C3F, 800002590E010C3F, 800003190E010C3F, 800003590E010C3F, 800008190E010C3F, 800008590E010C3F, 800009190E010C3F, 800009590E010C3F, 80000A590E010C3F, 80000B190E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X19                                          = 0x80000B590F010C3Full;
//DUPS: 800004190F010C3F, 800000990F010C3F, 80000A190F010C3F, 800000D90F010C3F, 800001990F010C3F, 800001D90F010C3F, 800003D90F010C3F, 800003990F010C3F, 800002D90F010C3F, 800002990F010C3F, 800009D90F010C3F, 800009990F010C3F, 800008D90F010C3F, 800008990F010C3F, 80000BD90F010C3F, 80000B990F010C3F, 80000AD90F010C3F, 80000A990F010C3F, 800000190F010C3F, 800000590F010C3F, 800001190F010C3F, 800001590F010C3F, 800002190F010C3F, 800002590F010C3F, 800003190F010C3F, 800003590F010C3F, 800008190F010C3F, 800008590F010C3F, 800009190F010C3F, 800009590F010C3F, 80000A590F010C3F, 80000B190F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1A                                            = 0x80000B5A0D010C3Full;
//DUPS: 8000041A0D010C3F, 8000009A0D010C3F, 80000A1A0D010C3F, 800000DA0D010C3F, 8000019A0D010C3F, 800001DA0D010C3F, 800003DA0D010C3F, 8000039A0D010C3F, 800002DA0D010C3F, 8000029A0D010C3F, 800009DA0D010C3F, 8000099A0D010C3F, 800008DA0D010C3F, 8000089A0D010C3F, 80000BDA0D010C3F, 80000B9A0D010C3F, 80000ADA0D010C3F, 80000A9A0D010C3F, 8000001A0D010C3F, 8000005A0D010C3F, 8000011A0D010C3F, 8000015A0D010C3F, 8000021A0D010C3F, 8000025A0D010C3F, 8000031A0D010C3F, 8000035A0D010C3F, 8000081A0D010C3F, 8000085A0D010C3F, 8000091A0D010C3F, 8000095A0D010C3F, 80000A5A0D010C3F, 80000B1A0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1A                                          = 0x80000B5A0D010C3Full;
//DUPS: 8000041A0D010C3F, 8000009A0D010C3F, 80000A1A0D010C3F, 800000DA0D010C3F, 8000019A0D010C3F, 800001DA0D010C3F, 800003DA0D010C3F, 8000039A0D010C3F, 800002DA0D010C3F, 8000029A0D010C3F, 800009DA0D010C3F, 8000099A0D010C3F, 800008DA0D010C3F, 8000089A0D010C3F, 80000BDA0D010C3F, 80000B9A0D010C3F, 80000ADA0D010C3F, 80000A9A0D010C3F, 8000001A0D010C3F, 8000005A0D010C3F, 8000011A0D010C3F, 8000015A0D010C3F, 8000021A0D010C3F, 8000025A0D010C3F, 8000031A0D010C3F, 8000035A0D010C3F, 8000081A0D010C3F, 8000085A0D010C3F, 8000091A0D010C3F, 8000095A0D010C3F, 80000A5A0D010C3F, 80000B1A0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1A                                          = 0x80000B5A0E010C3Full;
//DUPS: 8000041A0E010C3F, 8000009A0E010C3F, 80000A1A0E010C3F, 800000DA0E010C3F, 8000019A0E010C3F, 800001DA0E010C3F, 800003DA0E010C3F, 8000039A0E010C3F, 800002DA0E010C3F, 8000029A0E010C3F, 800009DA0E010C3F, 8000099A0E010C3F, 800008DA0E010C3F, 8000089A0E010C3F, 80000BDA0E010C3F, 80000B9A0E010C3F, 80000ADA0E010C3F, 80000A9A0E010C3F, 8000001A0E010C3F, 8000005A0E010C3F, 8000011A0E010C3F, 8000015A0E010C3F, 8000021A0E010C3F, 8000025A0E010C3F, 8000031A0E010C3F, 8000035A0E010C3F, 8000081A0E010C3F, 8000085A0E010C3F, 8000091A0E010C3F, 8000095A0E010C3F, 80000A5A0E010C3F, 80000B1A0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1A                                          = 0x80000B5A0F010C3Full;
//DUPS: 8000041A0F010C3F, 8000009A0F010C3F, 80000A1A0F010C3F, 800000DA0F010C3F, 8000019A0F010C3F, 800001DA0F010C3F, 800003DA0F010C3F, 8000039A0F010C3F, 800002DA0F010C3F, 8000029A0F010C3F, 800009DA0F010C3F, 8000099A0F010C3F, 800008DA0F010C3F, 8000089A0F010C3F, 80000BDA0F010C3F, 80000B9A0F010C3F, 80000ADA0F010C3F, 80000A9A0F010C3F, 8000001A0F010C3F, 8000005A0F010C3F, 8000011A0F010C3F, 8000015A0F010C3F, 8000021A0F010C3F, 8000025A0F010C3F, 8000031A0F010C3F, 8000035A0F010C3F, 8000081A0F010C3F, 8000085A0F010C3F, 8000091A0F010C3F, 8000095A0F010C3F, 80000A5A0F010C3F, 80000B1A0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1B                                            = 0x80000B5B0D010C3Full;
//DUPS: 8000009B0D010C3F, 80000A1B0D010C3F, 800000DB0D010C3F, 8000019B0D010C3F, 800001DB0D010C3F, 800003DB0D010C3F, 8000039B0D010C3F, 800002DB0D010C3F, 8000029B0D010C3F, 800009DB0D010C3F, 8000099B0D010C3F, 800008DB0D010C3F, 8000089B0D010C3F, 80000BDB0D010C3F, 80000B9B0D010C3F, 80000ADB0D010C3F, 80000A9B0D010C3F, 8000001B0D010C3F, 8000005B0D010C3F, 8000011B0D010C3F, 8000015B0D010C3F, 8000021B0D010C3F, 8000025B0D010C3F, 8000031B0D010C3F, 8000035B0D010C3F, 8000081B0D010C3F, 8000085B0D010C3F, 8000091B0D010C3F, 8000095B0D010C3F, 80000A5B0D010C3F, 80000B1B0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1B                                          = 0x80000B5B0D010C3Full;
//DUPS: 8000009B0D010C3F, 80000A1B0D010C3F, 800000DB0D010C3F, 8000019B0D010C3F, 800001DB0D010C3F, 800003DB0D010C3F, 8000039B0D010C3F, 800002DB0D010C3F, 8000029B0D010C3F, 800009DB0D010C3F, 8000099B0D010C3F, 800008DB0D010C3F, 8000089B0D010C3F, 80000BDB0D010C3F, 80000B9B0D010C3F, 80000ADB0D010C3F, 80000A9B0D010C3F, 8000001B0D010C3F, 8000005B0D010C3F, 8000011B0D010C3F, 8000015B0D010C3F, 8000021B0D010C3F, 8000025B0D010C3F, 8000031B0D010C3F, 8000035B0D010C3F, 8000081B0D010C3F, 8000085B0D010C3F, 8000091B0D010C3F, 8000095B0D010C3F, 80000A5B0D010C3F, 80000B1B0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1B                                          = 0x80000B5B0E010C3Full;
//DUPS: 8000009B0E010C3F, 80000A1B0E010C3F, 800000DB0E010C3F, 8000019B0E010C3F, 800001DB0E010C3F, 800003DB0E010C3F, 8000039B0E010C3F, 800002DB0E010C3F, 8000029B0E010C3F, 800009DB0E010C3F, 8000099B0E010C3F, 800008DB0E010C3F, 8000089B0E010C3F, 80000BDB0E010C3F, 80000B9B0E010C3F, 80000ADB0E010C3F, 80000A9B0E010C3F, 8000001B0E010C3F, 8000005B0E010C3F, 8000011B0E010C3F, 8000015B0E010C3F, 8000021B0E010C3F, 8000025B0E010C3F, 8000031B0E010C3F, 8000035B0E010C3F, 8000081B0E010C3F, 8000085B0E010C3F, 8000091B0E010C3F, 8000095B0E010C3F, 80000A5B0E010C3F, 80000B1B0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1B                                          = 0x80000B5B0F010C3Full;
//DUPS: 8000009B0F010C3F, 80000A1B0F010C3F, 800000DB0F010C3F, 8000019B0F010C3F, 800001DB0F010C3F, 800003DB0F010C3F, 8000039B0F010C3F, 800002DB0F010C3F, 8000029B0F010C3F, 800009DB0F010C3F, 8000099B0F010C3F, 800008DB0F010C3F, 8000089B0F010C3F, 80000BDB0F010C3F, 80000B9B0F010C3F, 80000ADB0F010C3F, 80000A9B0F010C3F, 8000001B0F010C3F, 8000005B0F010C3F, 8000011B0F010C3F, 8000015B0F010C3F, 8000021B0F010C3F, 8000025B0F010C3F, 8000031B0F010C3F, 8000035B0F010C3F, 8000081B0F010C3F, 8000085B0F010C3F, 8000091B0F010C3F, 8000095B0F010C3F, 80000A5B0F010C3F, 80000B1B0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1C                                            = 0x80000BDC0D010C3Full;
//DUPS: 800000DC0D010C3F, 8000019C0D010C3F, 800001DC0D010C3F, 800003DC0D010C3F, 8000039C0D010C3F, 800002DC0D010C3F, 8000029C0D010C3F, 800009DC0D010C3F, 8000099C0D010C3F, 800008DC0D010C3F, 8000089C0D010C3F, 80000BDC0D010C3F, 80000B9C0D010C3F, 80000ADC0D010C3F, 80000A9C0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1C                                          = 0x80000BDC0D010C3Full;
//DUPS: 800000DC0D010C3F, 8000019C0D010C3F, 800001DC0D010C3F, 800003DC0D010C3F, 8000039C0D010C3F, 800002DC0D010C3F, 8000029C0D010C3F, 800009DC0D010C3F, 8000099C0D010C3F, 800008DC0D010C3F, 8000089C0D010C3F, 80000BDC0D010C3F, 80000B9C0D010C3F, 80000ADC0D010C3F, 80000A9C0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1C                                          = 0x80000BDC0E010C3Full;
//DUPS: 800000DC0E010C3F, 8000019C0E010C3F, 800001DC0E010C3F, 800003DC0E010C3F, 8000039C0E010C3F, 800002DC0E010C3F, 8000029C0E010C3F, 800009DC0E010C3F, 8000099C0E010C3F, 800008DC0E010C3F, 8000089C0E010C3F, 80000BDC0E010C3F, 80000B9C0E010C3F, 80000ADC0E010C3F, 80000A9C0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1C                                          = 0x80000BDC0F010C3Full;
//DUPS: 800000DC0F010C3F, 8000019C0F010C3F, 800001DC0F010C3F, 800003DC0F010C3F, 8000039C0F010C3F, 800002DC0F010C3F, 8000029C0F010C3F, 800009DC0F010C3F, 8000099C0F010C3F, 800008DC0F010C3F, 8000089C0F010C3F, 80000BDC0F010C3F, 80000B9C0F010C3F, 80000ADC0F010C3F, 80000A9C0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1D                                            = 0x80000BDD0D010C3Full;
//DUPS: 800000DD0D010C3F, 8000019D0D010C3F, 800001DD0D010C3F, 800003DD0D010C3F, 8000039D0D010C3F, 800002DD0D010C3F, 8000029D0D010C3F, 800009DD0D010C3F, 8000099D0D010C3F, 800008DD0D010C3F, 8000089D0D010C3F, 80000BDD0D010C3F, 80000B9D0D010C3F, 80000ADD0D010C3F, 80000A9D0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1D                                          = 0x80000BDD0D010C3Full;
//DUPS: 800000DD0D010C3F, 8000019D0D010C3F, 800001DD0D010C3F, 800003DD0D010C3F, 8000039D0D010C3F, 800002DD0D010C3F, 8000029D0D010C3F, 800009DD0D010C3F, 8000099D0D010C3F, 800008DD0D010C3F, 8000089D0D010C3F, 80000BDD0D010C3F, 80000B9D0D010C3F, 80000ADD0D010C3F, 80000A9D0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1D                                          = 0x80000BDD0E010C3Full;
//DUPS: 800000DD0E010C3F, 8000019D0E010C3F, 800001DD0E010C3F, 800003DD0E010C3F, 8000039D0E010C3F, 800002DD0E010C3F, 8000029D0E010C3F, 800009DD0E010C3F, 8000099D0E010C3F, 800008DD0E010C3F, 8000089D0E010C3F, 80000BDD0E010C3F, 80000B9D0E010C3F, 80000ADD0E010C3F, 80000A9D0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1D                                          = 0x80000BDD0F010C3Full;
//DUPS: 800000DD0F010C3F, 8000019D0F010C3F, 800001DD0F010C3F, 800003DD0F010C3F, 8000039D0F010C3F, 800002DD0F010C3F, 8000029D0F010C3F, 800009DD0F010C3F, 8000099D0F010C3F, 800008DD0F010C3F, 8000089D0F010C3F, 80000BDD0F010C3F, 80000B9D0F010C3F, 80000ADD0F010C3F, 80000A9D0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1E                                            = 0x80000B5E0D010C3Full;
//DUPS: 8000009E0D010C3F, 80000A1E0D010C3F, 800000DE0D010C3F, 8000019E0D010C3F, 800001DE0D010C3F, 800003DE0D010C3F, 8000039E0D010C3F, 800002DE0D010C3F, 8000029E0D010C3F, 800009DE0D010C3F, 8000099E0D010C3F, 800008DE0D010C3F, 8000089E0D010C3F, 80000BDE0D010C3F, 80000B9E0D010C3F, 80000ADE0D010C3F, 80000A9E0D010C3F, 8000001E0D010C3F, 8000005E0D010C3F, 8000011E0D010C3F, 8000015E0D010C3F, 8000021E0D010C3F, 8000025E0D010C3F, 8000031E0D010C3F, 8000035E0D010C3F, 8000081E0D010C3F, 8000085E0D010C3F, 8000091E0D010C3F, 8000095E0D010C3F, 80000A5E0D010C3F, 80000B1E0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1E                                          = 0x80000B5E0D010C3Full;
//DUPS: 8000009E0D010C3F, 80000A1E0D010C3F, 800000DE0D010C3F, 8000019E0D010C3F, 800001DE0D010C3F, 800003DE0D010C3F, 8000039E0D010C3F, 800002DE0D010C3F, 8000029E0D010C3F, 800009DE0D010C3F, 8000099E0D010C3F, 800008DE0D010C3F, 8000089E0D010C3F, 80000BDE0D010C3F, 80000B9E0D010C3F, 80000ADE0D010C3F, 80000A9E0D010C3F, 8000001E0D010C3F, 8000005E0D010C3F, 8000011E0D010C3F, 8000015E0D010C3F, 8000021E0D010C3F, 8000025E0D010C3F, 8000031E0D010C3F, 8000035E0D010C3F, 8000081E0D010C3F, 8000085E0D010C3F, 8000091E0D010C3F, 8000095E0D010C3F, 80000A5E0D010C3F, 80000B1E0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1E                                          = 0x80000B5E0E010C3Full;
//DUPS: 8000009E0E010C3F, 80000A1E0E010C3F, 800000DE0E010C3F, 8000019E0E010C3F, 800001DE0E010C3F, 800003DE0E010C3F, 8000039E0E010C3F, 800002DE0E010C3F, 8000029E0E010C3F, 800009DE0E010C3F, 8000099E0E010C3F, 800008DE0E010C3F, 8000089E0E010C3F, 80000BDE0E010C3F, 80000B9E0E010C3F, 80000ADE0E010C3F, 80000A9E0E010C3F, 8000001E0E010C3F, 8000005E0E010C3F, 8000011E0E010C3F, 8000015E0E010C3F, 8000021E0E010C3F, 8000025E0E010C3F, 8000031E0E010C3F, 8000035E0E010C3F, 8000081E0E010C3F, 8000085E0E010C3F, 8000091E0E010C3F, 8000095E0E010C3F, 80000A5E0E010C3F, 80000B1E0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1E                                          = 0x80000B5E0F010C3Full;
//DUPS: 8000009E0F010C3F, 80000A1E0F010C3F, 800000DE0F010C3F, 8000019E0F010C3F, 800001DE0F010C3F, 800003DE0F010C3F, 8000039E0F010C3F, 800002DE0F010C3F, 8000029E0F010C3F, 800009DE0F010C3F, 8000099E0F010C3F, 800008DE0F010C3F, 8000089E0F010C3F, 80000BDE0F010C3F, 80000B9E0F010C3F, 80000ADE0F010C3F, 80000A9E0F010C3F, 8000001E0F010C3F, 8000005E0F010C3F, 8000011E0F010C3F, 8000015E0F010C3F, 8000021E0F010C3F, 8000025E0F010C3F, 8000031E0F010C3F, 8000035E0F010C3F, 8000081E0F010C3F, 8000085E0F010C3F, 8000091E0F010C3F, 8000095E0F010C3F, 80000A5E0F010C3F, 80000B1E0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X1F                                            = 0x80000B5F0D010C3Full;
//DUPS: 8000009F0D010C3F, 80000A1F0D010C3F, 800000DF0D010C3F, 8000019F0D010C3F, 800001DF0D010C3F, 800003DF0D010C3F, 8000039F0D010C3F, 800002DF0D010C3F, 8000029F0D010C3F, 800009DF0D010C3F, 8000099F0D010C3F, 800008DF0D010C3F, 8000089F0D010C3F, 80000BDF0D010C3F, 80000B9F0D010C3F, 80000ADF0D010C3F, 80000A9F0D010C3F, 8000001F0D010C3F, 8000005F0D010C3F, 8000011F0D010C3F, 8000015F0D010C3F, 8000021F0D010C3F, 8000025F0D010C3F, 8000031F0D010C3F, 8000035F0D010C3F, 8000081F0D010C3F, 8000085F0D010C3F, 8000091F0D010C3F, 8000095F0D010C3F, 80000A5F0D010C3F, 80000B1F0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X1F                                          = 0x80000B5F0D010C3Full;
//DUPS: 8000009F0D010C3F, 80000A1F0D010C3F, 800000DF0D010C3F, 8000019F0D010C3F, 800001DF0D010C3F, 800003DF0D010C3F, 8000039F0D010C3F, 800002DF0D010C3F, 8000029F0D010C3F, 800009DF0D010C3F, 8000099F0D010C3F, 800008DF0D010C3F, 8000089F0D010C3F, 80000BDF0D010C3F, 80000B9F0D010C3F, 80000ADF0D010C3F, 80000A9F0D010C3F, 8000001F0D010C3F, 8000005F0D010C3F, 8000011F0D010C3F, 8000015F0D010C3F, 8000021F0D010C3F, 8000025F0D010C3F, 8000031F0D010C3F, 8000035F0D010C3F, 8000081F0D010C3F, 8000085F0D010C3F, 8000091F0D010C3F, 8000095F0D010C3F, 80000A5F0D010C3F, 80000B1F0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X1F                                          = 0x80000B5F0E010C3Full;
//DUPS: 8000009F0E010C3F, 80000A1F0E010C3F, 800000DF0E010C3F, 8000019F0E010C3F, 800001DF0E010C3F, 800003DF0E010C3F, 8000039F0E010C3F, 800002DF0E010C3F, 8000029F0E010C3F, 800009DF0E010C3F, 8000099F0E010C3F, 800008DF0E010C3F, 8000089F0E010C3F, 80000BDF0E010C3F, 80000B9F0E010C3F, 80000ADF0E010C3F, 80000A9F0E010C3F, 8000001F0E010C3F, 8000005F0E010C3F, 8000011F0E010C3F, 8000015F0E010C3F, 8000021F0E010C3F, 8000025F0E010C3F, 8000031F0E010C3F, 8000035F0E010C3F, 8000081F0E010C3F, 8000085F0E010C3F, 8000091F0E010C3F, 8000095F0E010C3F, 80000A5F0E010C3F, 80000B1F0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X1F                                          = 0x80000B5F0F010C3Full;
//DUPS: 8000009F0F010C3F, 80000A1F0F010C3F, 800000DF0F010C3F, 8000019F0F010C3F, 800001DF0F010C3F, 800003DF0F010C3F, 8000039F0F010C3F, 800002DF0F010C3F, 8000029F0F010C3F, 800009DF0F010C3F, 8000099F0F010C3F, 800008DF0F010C3F, 8000089F0F010C3F, 80000BDF0F010C3F, 80000B9F0F010C3F, 80000ADF0F010C3F, 80000A9F0F010C3F, 8000001F0F010C3F, 8000005F0F010C3F, 8000011F0F010C3F, 8000015F0F010C3F, 8000021F0F010C3F, 8000025F0F010C3F, 8000031F0F010C3F, 8000035F0F010C3F, 8000081F0F010C3F, 8000085F0F010C3F, 8000091F0F010C3F, 8000095F0F010C3F, 80000A5F0F010C3F, 80000B1F0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X20                                            = 0x80000B600D010C3Full;
//DUPS: 800000A00D010C3F, 800004200D010C3F, 80000A200D010C3F, 800000E00D010C3F, 800001A00D010C3F, 800001E00D010C3F, 800003E00D010C3F, 800003A00D010C3F, 800002E00D010C3F, 800002A00D010C3F, 800009E00D010C3F, 800009A00D010C3F, 800008E00D010C3F, 800008A00D010C3F, 80000BE00D010C3F, 80000BA00D010C3F, 80000AE00D010C3F, 80000AA00D010C3F, 800000200D010C3F, 800000600D010C3F, 800001200D010C3F, 800001600D010C3F, 800002200D010C3F, 800002600D010C3F, 800003200D010C3F, 800003600D010C3F, 800008200D010C3F, 800008600D010C3F, 800009200D010C3F, 800009600D010C3F, 80000A600D010C3F, 80000B200D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X20                                          = 0x80000B600D010C3Full;
//DUPS: 800000A00D010C3F, 800004200D010C3F, 80000A200D010C3F, 800000E00D010C3F, 800001A00D010C3F, 800001E00D010C3F, 800003E00D010C3F, 800003A00D010C3F, 800002E00D010C3F, 800002A00D010C3F, 800009E00D010C3F, 800009A00D010C3F, 800008E00D010C3F, 800008A00D010C3F, 80000BE00D010C3F, 80000BA00D010C3F, 80000AE00D010C3F, 80000AA00D010C3F, 800000200D010C3F, 800000600D010C3F, 800001200D010C3F, 800001600D010C3F, 800002200D010C3F, 800002600D010C3F, 800003200D010C3F, 800003600D010C3F, 800008200D010C3F, 800008600D010C3F, 800009200D010C3F, 800009600D010C3F, 80000A600D010C3F, 80000B200D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X20                                          = 0x80000B600E010C3Full;
//DUPS: 800000A00E010C3F, 800004200E010C3F, 80000A200E010C3F, 800000E00E010C3F, 800001A00E010C3F, 800001E00E010C3F, 800003E00E010C3F, 800003A00E010C3F, 800002E00E010C3F, 800002A00E010C3F, 800009E00E010C3F, 800009A00E010C3F, 800008E00E010C3F, 800008A00E010C3F, 80000BE00E010C3F, 80000BA00E010C3F, 80000AE00E010C3F, 80000AA00E010C3F, 800000200E010C3F, 800000600E010C3F, 800001200E010C3F, 800001600E010C3F, 800002200E010C3F, 800002600E010C3F, 800003200E010C3F, 800003600E010C3F, 800008200E010C3F, 800008600E010C3F, 800009200E010C3F, 800009600E010C3F, 80000A600E010C3F, 80000B200E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X20                                          = 0x80000B600F010C3Full;
//DUPS: 800000A00F010C3F, 800004200F010C3F, 80000A200F010C3F, 800000E00F010C3F, 800001A00F010C3F, 800001E00F010C3F, 800003E00F010C3F, 800003A00F010C3F, 800002E00F010C3F, 800002A00F010C3F, 800009E00F010C3F, 800009A00F010C3F, 800008E00F010C3F, 800008A00F010C3F, 80000BE00F010C3F, 80000BA00F010C3F, 80000AE00F010C3F, 80000AA00F010C3F, 800000200F010C3F, 800000600F010C3F, 800001200F010C3F, 800001600F010C3F, 800002200F010C3F, 800002600F010C3F, 800003200F010C3F, 800003600F010C3F, 800008200F010C3F, 800008600F010C3F, 800009200F010C3F, 800009600F010C3F, 80000A600F010C3F, 80000B200F010C3F,

static const uint64_t P9N2_PEC_SCOM0X21                                            = 0x80000B610D010C3Full;
//DUPS: 800000A10D010C3F, 800004210D010C3F, 80000A210D010C3F, 800000E10D010C3F, 800001A10D010C3F, 800001E10D010C3F, 800003E10D010C3F, 800003A10D010C3F, 800002E10D010C3F, 800002A10D010C3F, 800009E10D010C3F, 800009A10D010C3F, 800008E10D010C3F, 800008A10D010C3F, 80000BE10D010C3F, 80000BA10D010C3F, 80000AE10D010C3F, 80000AA10D010C3F, 800000210D010C3F, 800000610D010C3F, 800001210D010C3F, 800001610D010C3F, 800002210D010C3F, 800002610D010C3F, 800003210D010C3F, 800003610D010C3F, 800008210D010C3F, 800008610D010C3F, 800009210D010C3F, 800009610D010C3F, 80000A610D010C3F, 80000B210D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X21                                          = 0x80000B610D010C3Full;
//DUPS: 800000A10D010C3F, 800004210D010C3F, 80000A210D010C3F, 800000E10D010C3F, 800001A10D010C3F, 800001E10D010C3F, 800003E10D010C3F, 800003A10D010C3F, 800002E10D010C3F, 800002A10D010C3F, 800009E10D010C3F, 800009A10D010C3F, 800008E10D010C3F, 800008A10D010C3F, 80000BE10D010C3F, 80000BA10D010C3F, 80000AE10D010C3F, 80000AA10D010C3F, 800000210D010C3F, 800000610D010C3F, 800001210D010C3F, 800001610D010C3F, 800002210D010C3F, 800002610D010C3F, 800003210D010C3F, 800003610D010C3F, 800008210D010C3F, 800008610D010C3F, 800009210D010C3F, 800009610D010C3F, 80000A610D010C3F, 80000B210D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X21                                          = 0x80000B610E010C3Full;
//DUPS: 800000A10E010C3F, 800004210E010C3F, 80000A210E010C3F, 800000E10E010C3F, 800001A10E010C3F, 800001E10E010C3F, 800003E10E010C3F, 800003A10E010C3F, 800002E10E010C3F, 800002A10E010C3F, 800009E10E010C3F, 800009A10E010C3F, 800008E10E010C3F, 800008A10E010C3F, 80000BE10E010C3F, 80000BA10E010C3F, 80000AE10E010C3F, 80000AA10E010C3F, 800000210E010C3F, 800000610E010C3F, 800001210E010C3F, 800001610E010C3F, 800002210E010C3F, 800002610E010C3F, 800003210E010C3F, 800003610E010C3F, 800008210E010C3F, 800008610E010C3F, 800009210E010C3F, 800009610E010C3F, 80000A610E010C3F, 80000B210E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X21                                          = 0x80000B610F010C3Full;
//DUPS: 800000A10F010C3F, 800004210F010C3F, 80000A210F010C3F, 800000E10F010C3F, 800001A10F010C3F, 800001E10F010C3F, 800003E10F010C3F, 800003A10F010C3F, 800002E10F010C3F, 800002A10F010C3F, 800009E10F010C3F, 800009A10F010C3F, 800008E10F010C3F, 800008A10F010C3F, 80000BE10F010C3F, 80000BA10F010C3F, 80000AE10F010C3F, 80000AA10F010C3F, 800000210F010C3F, 800000610F010C3F, 800001210F010C3F, 800001610F010C3F, 800002210F010C3F, 800002610F010C3F, 800003210F010C3F, 800003610F010C3F, 800008210F010C3F, 800008610F010C3F, 800009210F010C3F, 800009610F010C3F, 80000A610F010C3F, 80000B210F010C3F,

static const uint64_t P9N2_PEC_SCOM0X22                                            = 0x80000B620D010C3Full;
//DUPS: 800000A20D010C3F, 800004220D010C3F, 80000A220D010C3F, 800000E20D010C3F, 800001A20D010C3F, 800001E20D010C3F, 800003E20D010C3F, 800003A20D010C3F, 800002E20D010C3F, 800002A20D010C3F, 800009E20D010C3F, 800009A20D010C3F, 800008E20D010C3F, 800008A20D010C3F, 80000BE20D010C3F, 80000BA20D010C3F, 80000AE20D010C3F, 80000AA20D010C3F, 800000220D010C3F, 800000620D010C3F, 800001220D010C3F, 800001620D010C3F, 800002220D010C3F, 800002620D010C3F, 800003220D010C3F, 800003620D010C3F, 800008220D010C3F, 800008620D010C3F, 800009220D010C3F, 800009620D010C3F, 80000A620D010C3F, 80000B220D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X22                                          = 0x80000B620D010C3Full;
//DUPS: 800000A20D010C3F, 800004220D010C3F, 80000A220D010C3F, 800000E20D010C3F, 800001A20D010C3F, 800001E20D010C3F, 800003E20D010C3F, 800003A20D010C3F, 800002E20D010C3F, 800002A20D010C3F, 800009E20D010C3F, 800009A20D010C3F, 800008E20D010C3F, 800008A20D010C3F, 80000BE20D010C3F, 80000BA20D010C3F, 80000AE20D010C3F, 80000AA20D010C3F, 800000220D010C3F, 800000620D010C3F, 800001220D010C3F, 800001620D010C3F, 800002220D010C3F, 800002620D010C3F, 800003220D010C3F, 800003620D010C3F, 800008220D010C3F, 800008620D010C3F, 800009220D010C3F, 800009620D010C3F, 80000A620D010C3F, 80000B220D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X22                                          = 0x80000B620E010C3Full;
//DUPS: 800000A20E010C3F, 800004220E010C3F, 80000A220E010C3F, 800000E20E010C3F, 800001A20E010C3F, 800001E20E010C3F, 800003E20E010C3F, 800003A20E010C3F, 800002E20E010C3F, 800002A20E010C3F, 800009E20E010C3F, 800009A20E010C3F, 800008E20E010C3F, 800008A20E010C3F, 80000BE20E010C3F, 80000BA20E010C3F, 80000AE20E010C3F, 80000AA20E010C3F, 800000220E010C3F, 800000620E010C3F, 800001220E010C3F, 800001620E010C3F, 800002220E010C3F, 800002620E010C3F, 800003220E010C3F, 800003620E010C3F, 800008220E010C3F, 800008620E010C3F, 800009220E010C3F, 800009620E010C3F, 80000A620E010C3F, 80000B220E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X22                                          = 0x80000B620F010C3Full;
//DUPS: 800000A20F010C3F, 800004220F010C3F, 80000A220F010C3F, 800000E20F010C3F, 800001A20F010C3F, 800001E20F010C3F, 800003E20F010C3F, 800003A20F010C3F, 800002E20F010C3F, 800002A20F010C3F, 800009E20F010C3F, 800009A20F010C3F, 800008E20F010C3F, 800008A20F010C3F, 80000BE20F010C3F, 80000BA20F010C3F, 80000AE20F010C3F, 80000AA20F010C3F, 800000220F010C3F, 800000620F010C3F, 800001220F010C3F, 800001620F010C3F, 800002220F010C3F, 800002620F010C3F, 800003220F010C3F, 800003620F010C3F, 800008220F010C3F, 800008620F010C3F, 800009220F010C3F, 800009620F010C3F, 80000A620F010C3F, 80000B220F010C3F,

static const uint64_t P9N2_PEC_SCOM0X23                                            = 0x80000B630D010C3Full;
//DUPS: 800000A30D010C3F, 80000A230D010C3F, 800000E30D010C3F, 800001A30D010C3F, 800001E30D010C3F, 800003E30D010C3F, 800003A30D010C3F, 800002E30D010C3F, 800002A30D010C3F, 800009E30D010C3F, 800009A30D010C3F, 800008E30D010C3F, 800008A30D010C3F, 80000BE30D010C3F, 80000BA30D010C3F, 80000AE30D010C3F, 80000AA30D010C3F, 800000230D010C3F, 800000630D010C3F, 800001230D010C3F, 800001630D010C3F, 800002230D010C3F, 800002630D010C3F, 800003230D010C3F, 800003630D010C3F, 800008230D010C3F, 800008630D010C3F, 800009230D010C3F, 800009630D010C3F, 80000A630D010C3F, 80000B230D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X23                                          = 0x80000B630D010C3Full;
//DUPS: 800000A30D010C3F, 80000A230D010C3F, 800000E30D010C3F, 800001A30D010C3F, 800001E30D010C3F, 800003E30D010C3F, 800003A30D010C3F, 800002E30D010C3F, 800002A30D010C3F, 800009E30D010C3F, 800009A30D010C3F, 800008E30D010C3F, 800008A30D010C3F, 80000BE30D010C3F, 80000BA30D010C3F, 80000AE30D010C3F, 80000AA30D010C3F, 800000230D010C3F, 800000630D010C3F, 800001230D010C3F, 800001630D010C3F, 800002230D010C3F, 800002630D010C3F, 800003230D010C3F, 800003630D010C3F, 800008230D010C3F, 800008630D010C3F, 800009230D010C3F, 800009630D010C3F, 80000A630D010C3F, 80000B230D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X23                                          = 0x80000B630E010C3Full;
//DUPS: 800000A30E010C3F, 80000A230E010C3F, 800000E30E010C3F, 800001A30E010C3F, 800001E30E010C3F, 800003E30E010C3F, 800003A30E010C3F, 800002E30E010C3F, 800002A30E010C3F, 800009E30E010C3F, 800009A30E010C3F, 800008E30E010C3F, 800008A30E010C3F, 80000BE30E010C3F, 80000BA30E010C3F, 80000AE30E010C3F, 80000AA30E010C3F, 800000230E010C3F, 800000630E010C3F, 800001230E010C3F, 800001630E010C3F, 800002230E010C3F, 800002630E010C3F, 800003230E010C3F, 800003630E010C3F, 800008230E010C3F, 800008630E010C3F, 800009230E010C3F, 800009630E010C3F, 80000A630E010C3F, 80000B230E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X23                                          = 0x80000B630F010C3Full;
//DUPS: 800000A30F010C3F, 80000A230F010C3F, 800000E30F010C3F, 800001A30F010C3F, 800001E30F010C3F, 800003E30F010C3F, 800003A30F010C3F, 800002E30F010C3F, 800002A30F010C3F, 800009E30F010C3F, 800009A30F010C3F, 800008E30F010C3F, 800008A30F010C3F, 80000BE30F010C3F, 80000BA30F010C3F, 80000AE30F010C3F, 80000AA30F010C3F, 800000230F010C3F, 800000630F010C3F, 800001230F010C3F, 800001630F010C3F, 800002230F010C3F, 800002630F010C3F, 800003230F010C3F, 800003630F010C3F, 800008230F010C3F, 800008630F010C3F, 800009230F010C3F, 800009630F010C3F, 80000A630F010C3F, 80000B230F010C3F,

static const uint64_t P9N2_PEC_SCOM0X24                                            = 0x80000BE40D010C3Full;
//DUPS: 800000E40D010C3F, 800001A40D010C3F, 800001E40D010C3F, 800003E40D010C3F, 800003A40D010C3F, 800002E40D010C3F, 800002A40D010C3F, 800009E40D010C3F, 800009A40D010C3F, 800008E40D010C3F, 800008A40D010C3F, 80000BE40D010C3F, 80000BA40D010C3F, 80000AE40D010C3F, 80000AA40D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X24                                          = 0x80000BE40D010C3Full;
//DUPS: 800000E40D010C3F, 800001A40D010C3F, 800001E40D010C3F, 800003E40D010C3F, 800003A40D010C3F, 800002E40D010C3F, 800002A40D010C3F, 800009E40D010C3F, 800009A40D010C3F, 800008E40D010C3F, 800008A40D010C3F, 80000BE40D010C3F, 80000BA40D010C3F, 80000AE40D010C3F, 80000AA40D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X24                                          = 0x80000BE40E010C3Full;
//DUPS: 800000E40E010C3F, 800001A40E010C3F, 800001E40E010C3F, 800003E40E010C3F, 800003A40E010C3F, 800002E40E010C3F, 800002A40E010C3F, 800009E40E010C3F, 800009A40E010C3F, 800008E40E010C3F, 800008A40E010C3F, 80000BE40E010C3F, 80000BA40E010C3F, 80000AE40E010C3F, 80000AA40E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X24                                          = 0x80000BE40F010C3Full;
//DUPS: 800000E40F010C3F, 800001A40F010C3F, 800001E40F010C3F, 800003E40F010C3F, 800003A40F010C3F, 800002E40F010C3F, 800002A40F010C3F, 800009E40F010C3F, 800009A40F010C3F, 800008E40F010C3F, 800008A40F010C3F, 80000BE40F010C3F, 80000BA40F010C3F, 80000AE40F010C3F, 80000AA40F010C3F,

static const uint64_t P9N2_PEC_SCOM0X25                                            = 0x80000BE50D010C3Full;
//DUPS: 800000E50D010C3F, 800001A50D010C3F, 800001E50D010C3F, 800003E50D010C3F, 800003A50D010C3F, 800002E50D010C3F, 800002A50D010C3F, 800009E50D010C3F, 800009A50D010C3F, 800008E50D010C3F, 800008A50D010C3F, 80000BE50D010C3F, 80000BA50D010C3F, 80000AE50D010C3F, 80000AA50D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X25                                          = 0x80000BE50D010C3Full;
//DUPS: 800000E50D010C3F, 800001A50D010C3F, 800001E50D010C3F, 800003E50D010C3F, 800003A50D010C3F, 800002E50D010C3F, 800002A50D010C3F, 800009E50D010C3F, 800009A50D010C3F, 800008E50D010C3F, 800008A50D010C3F, 80000BE50D010C3F, 80000BA50D010C3F, 80000AE50D010C3F, 80000AA50D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X25                                          = 0x80000BE50E010C3Full;
//DUPS: 800000E50E010C3F, 800001A50E010C3F, 800001E50E010C3F, 800003E50E010C3F, 800003A50E010C3F, 800002E50E010C3F, 800002A50E010C3F, 800009E50E010C3F, 800009A50E010C3F, 800008E50E010C3F, 800008A50E010C3F, 80000BE50E010C3F, 80000BA50E010C3F, 80000AE50E010C3F, 80000AA50E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X25                                          = 0x80000BE50F010C3Full;
//DUPS: 800000E50F010C3F, 800001A50F010C3F, 800001E50F010C3F, 800003E50F010C3F, 800003A50F010C3F, 800002E50F010C3F, 800002A50F010C3F, 800009E50F010C3F, 800009A50F010C3F, 800008E50F010C3F, 800008A50F010C3F, 80000BE50F010C3F, 80000BA50F010C3F, 80000AE50F010C3F, 80000AA50F010C3F,

static const uint64_t P9N2_PEC_SCOM0X26                                            = 0x80000BE60D010C3Full;
//DUPS: 800000E60D010C3F, 800001A60D010C3F, 800001E60D010C3F, 800003E60D010C3F, 800003A60D010C3F, 800002E60D010C3F, 800002A60D010C3F, 800009E60D010C3F, 800009A60D010C3F, 800008E60D010C3F, 800008A60D010C3F, 80000BE60D010C3F, 80000BA60D010C3F, 80000AE60D010C3F, 80000AA60D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X26                                          = 0x80000BE60D010C3Full;
//DUPS: 800000E60D010C3F, 800001A60D010C3F, 800001E60D010C3F, 800003E60D010C3F, 800003A60D010C3F, 800002E60D010C3F, 800002A60D010C3F, 800009E60D010C3F, 800009A60D010C3F, 800008E60D010C3F, 800008A60D010C3F, 80000BE60D010C3F, 80000BA60D010C3F, 80000AE60D010C3F, 80000AA60D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X26                                          = 0x80000BE60E010C3Full;
//DUPS: 800000E60E010C3F, 800001A60E010C3F, 800001E60E010C3F, 800003E60E010C3F, 800003A60E010C3F, 800002E60E010C3F, 800002A60E010C3F, 800009E60E010C3F, 800009A60E010C3F, 800008E60E010C3F, 800008A60E010C3F, 80000BE60E010C3F, 80000BA60E010C3F, 80000AE60E010C3F, 80000AA60E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X26                                          = 0x80000BE60F010C3Full;
//DUPS: 800000E60F010C3F, 800001A60F010C3F, 800001E60F010C3F, 800003E60F010C3F, 800003A60F010C3F, 800002E60F010C3F, 800002A60F010C3F, 800009E60F010C3F, 800009A60F010C3F, 800008E60F010C3F, 800008A60F010C3F, 80000BE60F010C3F, 80000BA60F010C3F, 80000AE60F010C3F, 80000AA60F010C3F,

static const uint64_t P9N2_PEC_SCOM0X27                                            = 0x80000BE70D010C3Full;
//DUPS: 800000E70D010C3F, 800001A70D010C3F, 800001E70D010C3F, 800003E70D010C3F, 800003A70D010C3F, 800002E70D010C3F, 800002A70D010C3F, 800009E70D010C3F, 800009A70D010C3F, 800008E70D010C3F, 800008A70D010C3F, 80000BE70D010C3F, 80000BA70D010C3F, 80000AE70D010C3F, 80000AA70D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X27                                          = 0x80000BE70D010C3Full;
//DUPS: 800000E70D010C3F, 800001A70D010C3F, 800001E70D010C3F, 800003E70D010C3F, 800003A70D010C3F, 800002E70D010C3F, 800002A70D010C3F, 800009E70D010C3F, 800009A70D010C3F, 800008E70D010C3F, 800008A70D010C3F, 80000BE70D010C3F, 80000BA70D010C3F, 80000AE70D010C3F, 80000AA70D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X27                                          = 0x80000BE70E010C3Full;
//DUPS: 800000E70E010C3F, 800001A70E010C3F, 800001E70E010C3F, 800003E70E010C3F, 800003A70E010C3F, 800002E70E010C3F, 800002A70E010C3F, 800009E70E010C3F, 800009A70E010C3F, 800008E70E010C3F, 800008A70E010C3F, 80000BE70E010C3F, 80000BA70E010C3F, 80000AE70E010C3F, 80000AA70E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X27                                          = 0x80000BE70F010C3Full;
//DUPS: 800000E70F010C3F, 800001A70F010C3F, 800001E70F010C3F, 800003E70F010C3F, 800003A70F010C3F, 800002E70F010C3F, 800002A70F010C3F, 800009E70F010C3F, 800009A70F010C3F, 800008E70F010C3F, 800008A70F010C3F, 80000BE70F010C3F, 80000BA70F010C3F, 80000AE70F010C3F, 80000AA70F010C3F,

static const uint64_t P9N2_PEC_SCOM0X28                                            = 0x80000B680D010C3Full;
//DUPS: 800000A80D010C3F, 80000A280D010C3F, 800000E80D010C3F, 800001A80D010C3F, 800001E80D010C3F, 800003E80D010C3F, 800003A80D010C3F, 800002E80D010C3F, 800002A80D010C3F, 800009E80D010C3F, 800009A80D010C3F, 800008E80D010C3F, 800008A80D010C3F, 80000BE80D010C3F, 80000BA80D010C3F, 80000AE80D010C3F, 80000AA80D010C3F, 800000280D010C3F, 800000680D010C3F, 800001280D010C3F, 800001680D010C3F, 800002280D010C3F, 800002680D010C3F, 800003280D010C3F, 800003680D010C3F, 800008280D010C3F, 800008680D010C3F, 800009280D010C3F, 800009680D010C3F, 80000A680D010C3F, 80000B280D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X28                                          = 0x80000B680D010C3Full;
//DUPS: 800000A80D010C3F, 80000A280D010C3F, 800000E80D010C3F, 800001A80D010C3F, 800001E80D010C3F, 800003E80D010C3F, 800003A80D010C3F, 800002E80D010C3F, 800002A80D010C3F, 800009E80D010C3F, 800009A80D010C3F, 800008E80D010C3F, 800008A80D010C3F, 80000BE80D010C3F, 80000BA80D010C3F, 80000AE80D010C3F, 80000AA80D010C3F, 800000280D010C3F, 800000680D010C3F, 800001280D010C3F, 800001680D010C3F, 800002280D010C3F, 800002680D010C3F, 800003280D010C3F, 800003680D010C3F, 800008280D010C3F, 800008680D010C3F, 800009280D010C3F, 800009680D010C3F, 80000A680D010C3F, 80000B280D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X28                                          = 0x80000B680E010C3Full;
//DUPS: 800000A80E010C3F, 80000A280E010C3F, 800000E80E010C3F, 800001A80E010C3F, 800001E80E010C3F, 800003E80E010C3F, 800003A80E010C3F, 800002E80E010C3F, 800002A80E010C3F, 800009E80E010C3F, 800009A80E010C3F, 800008E80E010C3F, 800008A80E010C3F, 80000BE80E010C3F, 80000BA80E010C3F, 80000AE80E010C3F, 80000AA80E010C3F, 800000280E010C3F, 800000680E010C3F, 800001280E010C3F, 800001680E010C3F, 800002280E010C3F, 800002680E010C3F, 800003280E010C3F, 800003680E010C3F, 800008280E010C3F, 800008680E010C3F, 800009280E010C3F, 800009680E010C3F, 80000A680E010C3F, 80000B280E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X28                                          = 0x80000B680F010C3Full;
//DUPS: 800000A80F010C3F, 80000A280F010C3F, 800000E80F010C3F, 800001A80F010C3F, 800001E80F010C3F, 800003E80F010C3F, 800003A80F010C3F, 800002E80F010C3F, 800002A80F010C3F, 800009E80F010C3F, 800009A80F010C3F, 800008E80F010C3F, 800008A80F010C3F, 80000BE80F010C3F, 80000BA80F010C3F, 80000AE80F010C3F, 80000AA80F010C3F, 800000280F010C3F, 800000680F010C3F, 800001280F010C3F, 800001680F010C3F, 800002280F010C3F, 800002680F010C3F, 800003280F010C3F, 800003680F010C3F, 800008280F010C3F, 800008680F010C3F, 800009280F010C3F, 800009680F010C3F, 80000A680F010C3F, 80000B280F010C3F,

static const uint64_t P9N2_PEC_SCOM0X29                                            = 0x80000B690D010C3Full;
//DUPS: 800000A90D010C3F, 80000A290D010C3F, 800000E90D010C3F, 800001A90D010C3F, 800001E90D010C3F, 800003E90D010C3F, 800003A90D010C3F, 800002E90D010C3F, 800002A90D010C3F, 800009E90D010C3F, 800009A90D010C3F, 800008E90D010C3F, 800008A90D010C3F, 80000BE90D010C3F, 80000BA90D010C3F, 80000AE90D010C3F, 80000AA90D010C3F, 800000290D010C3F, 800000690D010C3F, 800001290D010C3F, 800001690D010C3F, 800002290D010C3F, 800002690D010C3F, 800003290D010C3F, 800003690D010C3F, 800008290D010C3F, 800008690D010C3F, 800009290D010C3F, 800009690D010C3F, 80000A690D010C3F, 80000B290D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X29                                          = 0x80000B690D010C3Full;
//DUPS: 800000A90D010C3F, 80000A290D010C3F, 800000E90D010C3F, 800001A90D010C3F, 800001E90D010C3F, 800003E90D010C3F, 800003A90D010C3F, 800002E90D010C3F, 800002A90D010C3F, 800009E90D010C3F, 800009A90D010C3F, 800008E90D010C3F, 800008A90D010C3F, 80000BE90D010C3F, 80000BA90D010C3F, 80000AE90D010C3F, 80000AA90D010C3F, 800000290D010C3F, 800000690D010C3F, 800001290D010C3F, 800001690D010C3F, 800002290D010C3F, 800002690D010C3F, 800003290D010C3F, 800003690D010C3F, 800008290D010C3F, 800008690D010C3F, 800009290D010C3F, 800009690D010C3F, 80000A690D010C3F, 80000B290D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X29                                          = 0x80000B690E010C3Full;
//DUPS: 800000A90E010C3F, 80000A290E010C3F, 800000E90E010C3F, 800001A90E010C3F, 800001E90E010C3F, 800003E90E010C3F, 800003A90E010C3F, 800002E90E010C3F, 800002A90E010C3F, 800009E90E010C3F, 800009A90E010C3F, 800008E90E010C3F, 800008A90E010C3F, 80000BE90E010C3F, 80000BA90E010C3F, 80000AE90E010C3F, 80000AA90E010C3F, 800000290E010C3F, 800000690E010C3F, 800001290E010C3F, 800001690E010C3F, 800002290E010C3F, 800002690E010C3F, 800003290E010C3F, 800003690E010C3F, 800008290E010C3F, 800008690E010C3F, 800009290E010C3F, 800009690E010C3F, 80000A690E010C3F, 80000B290E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X29                                          = 0x80000B690F010C3Full;
//DUPS: 800000A90F010C3F, 80000A290F010C3F, 800000E90F010C3F, 800001A90F010C3F, 800001E90F010C3F, 800003E90F010C3F, 800003A90F010C3F, 800002E90F010C3F, 800002A90F010C3F, 800009E90F010C3F, 800009A90F010C3F, 800008E90F010C3F, 800008A90F010C3F, 80000BE90F010C3F, 80000BA90F010C3F, 80000AE90F010C3F, 80000AA90F010C3F, 800000290F010C3F, 800000690F010C3F, 800001290F010C3F, 800001690F010C3F, 800002290F010C3F, 800002690F010C3F, 800003290F010C3F, 800003690F010C3F, 800008290F010C3F, 800008690F010C3F, 800009290F010C3F, 800009690F010C3F, 80000A690F010C3F, 80000B290F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2A                                            = 0x80000B6A0D010C3Full;
//DUPS: 800000AA0D010C3F, 80000A2A0D010C3F, 800000EA0D010C3F, 800001AA0D010C3F, 800001EA0D010C3F, 800003EA0D010C3F, 800003AA0D010C3F, 800002EA0D010C3F, 800002AA0D010C3F, 800009EA0D010C3F, 800009AA0D010C3F, 800008EA0D010C3F, 800008AA0D010C3F, 80000BEA0D010C3F, 80000BAA0D010C3F, 80000AEA0D010C3F, 80000AAA0D010C3F, 8000002A0D010C3F, 8000006A0D010C3F, 8000012A0D010C3F, 8000016A0D010C3F, 8000022A0D010C3F, 8000026A0D010C3F, 8000032A0D010C3F, 8000036A0D010C3F, 8000082A0D010C3F, 8000086A0D010C3F, 8000092A0D010C3F, 8000096A0D010C3F, 80000A6A0D010C3F, 80000B2A0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2A                                          = 0x80000B6A0D010C3Full;
//DUPS: 800000AA0D010C3F, 80000A2A0D010C3F, 800000EA0D010C3F, 800001AA0D010C3F, 800001EA0D010C3F, 800003EA0D010C3F, 800003AA0D010C3F, 800002EA0D010C3F, 800002AA0D010C3F, 800009EA0D010C3F, 800009AA0D010C3F, 800008EA0D010C3F, 800008AA0D010C3F, 80000BEA0D010C3F, 80000BAA0D010C3F, 80000AEA0D010C3F, 80000AAA0D010C3F, 8000002A0D010C3F, 8000006A0D010C3F, 8000012A0D010C3F, 8000016A0D010C3F, 8000022A0D010C3F, 8000026A0D010C3F, 8000032A0D010C3F, 8000036A0D010C3F, 8000082A0D010C3F, 8000086A0D010C3F, 8000092A0D010C3F, 8000096A0D010C3F, 80000A6A0D010C3F, 80000B2A0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2A                                          = 0x80000B6A0E010C3Full;
//DUPS: 800000AA0E010C3F, 80000A2A0E010C3F, 800000EA0E010C3F, 800001AA0E010C3F, 800001EA0E010C3F, 800003EA0E010C3F, 800003AA0E010C3F, 800002EA0E010C3F, 800002AA0E010C3F, 800009EA0E010C3F, 800009AA0E010C3F, 800008EA0E010C3F, 800008AA0E010C3F, 80000BEA0E010C3F, 80000BAA0E010C3F, 80000AEA0E010C3F, 80000AAA0E010C3F, 8000002A0E010C3F, 8000006A0E010C3F, 8000012A0E010C3F, 8000016A0E010C3F, 8000022A0E010C3F, 8000026A0E010C3F, 8000032A0E010C3F, 8000036A0E010C3F, 8000082A0E010C3F, 8000086A0E010C3F, 8000092A0E010C3F, 8000096A0E010C3F, 80000A6A0E010C3F, 80000B2A0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2A                                          = 0x80000B6A0F010C3Full;
//DUPS: 800000AA0F010C3F, 80000A2A0F010C3F, 800000EA0F010C3F, 800001AA0F010C3F, 800001EA0F010C3F, 800003EA0F010C3F, 800003AA0F010C3F, 800002EA0F010C3F, 800002AA0F010C3F, 800009EA0F010C3F, 800009AA0F010C3F, 800008EA0F010C3F, 800008AA0F010C3F, 80000BEA0F010C3F, 80000BAA0F010C3F, 80000AEA0F010C3F, 80000AAA0F010C3F, 8000002A0F010C3F, 8000006A0F010C3F, 8000012A0F010C3F, 8000016A0F010C3F, 8000022A0F010C3F, 8000026A0F010C3F, 8000032A0F010C3F, 8000036A0F010C3F, 8000082A0F010C3F, 8000086A0F010C3F, 8000092A0F010C3F, 8000096A0F010C3F, 80000A6A0F010C3F, 80000B2A0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2B                                            = 0x80000B6B0D010C3Full;
//DUPS: 80000A2B0D010C3F, 8000002B0D010C3F, 8000006B0D010C3F, 8000012B0D010C3F, 8000016B0D010C3F, 8000022B0D010C3F, 8000026B0D010C3F, 8000032B0D010C3F, 8000036B0D010C3F, 8000082B0D010C3F, 8000086B0D010C3F, 8000092B0D010C3F, 8000096B0D010C3F, 80000A6B0D010C3F, 80000B2B0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2B                                          = 0x80000B6B0D010C3Full;
//DUPS: 80000A2B0D010C3F, 8000002B0D010C3F, 8000006B0D010C3F, 8000012B0D010C3F, 8000016B0D010C3F, 8000022B0D010C3F, 8000026B0D010C3F, 8000032B0D010C3F, 8000036B0D010C3F, 8000082B0D010C3F, 8000086B0D010C3F, 8000092B0D010C3F, 8000096B0D010C3F, 80000A6B0D010C3F, 80000B2B0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2B                                          = 0x80000B6B0E010C3Full;
//DUPS: 80000A2B0E010C3F, 8000002B0E010C3F, 8000006B0E010C3F, 8000012B0E010C3F, 8000016B0E010C3F, 8000022B0E010C3F, 8000026B0E010C3F, 8000032B0E010C3F, 8000036B0E010C3F, 8000082B0E010C3F, 8000086B0E010C3F, 8000092B0E010C3F, 8000096B0E010C3F, 80000A6B0E010C3F, 80000B2B0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2B                                          = 0x80000B6B0F010C3Full;
//DUPS: 80000A2B0F010C3F, 8000002B0F010C3F, 8000006B0F010C3F, 8000012B0F010C3F, 8000016B0F010C3F, 8000022B0F010C3F, 8000026B0F010C3F, 8000032B0F010C3F, 8000036B0F010C3F, 8000082B0F010C3F, 8000086B0F010C3F, 8000092B0F010C3F, 8000096B0F010C3F, 80000A6B0F010C3F, 80000B2B0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2C                                            = 0x80000B6C0D010C3Full;
//DUPS: 80000A2C0D010C3F, 8000002C0D010C3F, 8000006C0D010C3F, 8000012C0D010C3F, 8000016C0D010C3F, 8000022C0D010C3F, 8000026C0D010C3F, 8000032C0D010C3F, 8000036C0D010C3F, 8000082C0D010C3F, 8000086C0D010C3F, 8000092C0D010C3F, 8000096C0D010C3F, 80000A6C0D010C3F, 80000B2C0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2C                                          = 0x80000B6C0D010C3Full;
//DUPS: 80000A2C0D010C3F, 8000002C0D010C3F, 8000006C0D010C3F, 8000012C0D010C3F, 8000016C0D010C3F, 8000022C0D010C3F, 8000026C0D010C3F, 8000032C0D010C3F, 8000036C0D010C3F, 8000082C0D010C3F, 8000086C0D010C3F, 8000092C0D010C3F, 8000096C0D010C3F, 80000A6C0D010C3F, 80000B2C0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2C                                          = 0x80000B6C0E010C3Full;
//DUPS: 80000A2C0E010C3F, 8000002C0E010C3F, 8000006C0E010C3F, 8000012C0E010C3F, 8000016C0E010C3F, 8000022C0E010C3F, 8000026C0E010C3F, 8000032C0E010C3F, 8000036C0E010C3F, 8000082C0E010C3F, 8000086C0E010C3F, 8000092C0E010C3F, 8000096C0E010C3F, 80000A6C0E010C3F, 80000B2C0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2C                                          = 0x80000B6C0F010C3Full;
//DUPS: 80000A2C0F010C3F, 8000002C0F010C3F, 8000006C0F010C3F, 8000012C0F010C3F, 8000016C0F010C3F, 8000022C0F010C3F, 8000026C0F010C3F, 8000032C0F010C3F, 8000036C0F010C3F, 8000082C0F010C3F, 8000086C0F010C3F, 8000092C0F010C3F, 8000096C0F010C3F, 80000A6C0F010C3F, 80000B2C0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2D                                            = 0x80000B6D0D010C3Full;
//DUPS: 800000AD0D010C3F, 80000A2D0D010C3F, 800000ED0D010C3F, 800001AD0D010C3F, 800001ED0D010C3F, 800003ED0D010C3F, 800003AD0D010C3F, 800002ED0D010C3F, 800002AD0D010C3F, 800009ED0D010C3F, 800009AD0D010C3F, 800008ED0D010C3F, 800008AD0D010C3F, 80000BED0D010C3F, 80000BAD0D010C3F, 80000AED0D010C3F, 80000AAD0D010C3F, 8000002D0D010C3F, 8000006D0D010C3F, 8000012D0D010C3F, 8000016D0D010C3F, 8000022D0D010C3F, 8000026D0D010C3F, 8000032D0D010C3F, 8000036D0D010C3F, 8000082D0D010C3F, 8000086D0D010C3F, 8000092D0D010C3F, 8000096D0D010C3F, 80000A6D0D010C3F, 80000B2D0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2D                                          = 0x80000B6D0D010C3Full;
//DUPS: 800000AD0D010C3F, 80000A2D0D010C3F, 800000ED0D010C3F, 800001AD0D010C3F, 800001ED0D010C3F, 800003ED0D010C3F, 800003AD0D010C3F, 800002ED0D010C3F, 800002AD0D010C3F, 800009ED0D010C3F, 800009AD0D010C3F, 800008ED0D010C3F, 800008AD0D010C3F, 80000BED0D010C3F, 80000BAD0D010C3F, 80000AED0D010C3F, 80000AAD0D010C3F, 8000002D0D010C3F, 8000006D0D010C3F, 8000012D0D010C3F, 8000016D0D010C3F, 8000022D0D010C3F, 8000026D0D010C3F, 8000032D0D010C3F, 8000036D0D010C3F, 8000082D0D010C3F, 8000086D0D010C3F, 8000092D0D010C3F, 8000096D0D010C3F, 80000A6D0D010C3F, 80000B2D0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2D                                          = 0x80000B6D0E010C3Full;
//DUPS: 800000AD0E010C3F, 80000A2D0E010C3F, 800000ED0E010C3F, 800001AD0E010C3F, 800001ED0E010C3F, 800003ED0E010C3F, 800003AD0E010C3F, 800002ED0E010C3F, 800002AD0E010C3F, 800009ED0E010C3F, 800009AD0E010C3F, 800008ED0E010C3F, 800008AD0E010C3F, 80000BED0E010C3F, 80000BAD0E010C3F, 80000AED0E010C3F, 80000AAD0E010C3F, 8000002D0E010C3F, 8000006D0E010C3F, 8000012D0E010C3F, 8000016D0E010C3F, 8000022D0E010C3F, 8000026D0E010C3F, 8000032D0E010C3F, 8000036D0E010C3F, 8000082D0E010C3F, 8000086D0E010C3F, 8000092D0E010C3F, 8000096D0E010C3F, 80000A6D0E010C3F, 80000B2D0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2D                                          = 0x80000B6D0F010C3Full;
//DUPS: 800000AD0F010C3F, 80000A2D0F010C3F, 800000ED0F010C3F, 800001AD0F010C3F, 800001ED0F010C3F, 800003ED0F010C3F, 800003AD0F010C3F, 800002ED0F010C3F, 800002AD0F010C3F, 800009ED0F010C3F, 800009AD0F010C3F, 800008ED0F010C3F, 800008AD0F010C3F, 80000BED0F010C3F, 80000BAD0F010C3F, 80000AED0F010C3F, 80000AAD0F010C3F, 8000002D0F010C3F, 8000006D0F010C3F, 8000012D0F010C3F, 8000016D0F010C3F, 8000022D0F010C3F, 8000026D0F010C3F, 8000032D0F010C3F, 8000036D0F010C3F, 8000082D0F010C3F, 8000086D0F010C3F, 8000092D0F010C3F, 8000096D0F010C3F, 80000A6D0F010C3F, 80000B2D0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2E                                            = 0x80000B6E0D010C3Full;
//DUPS: 800000AE0D010C3F, 80000A2E0D010C3F, 800000EE0D010C3F, 800001AE0D010C3F, 800001EE0D010C3F, 800003EE0D010C3F, 800003AE0D010C3F, 800002EE0D010C3F, 800002AE0D010C3F, 800009EE0D010C3F, 800009AE0D010C3F, 800008EE0D010C3F, 800008AE0D010C3F, 80000BEE0D010C3F, 80000BAE0D010C3F, 80000AEE0D010C3F, 80000AAE0D010C3F, 8000002E0D010C3F, 8000006E0D010C3F, 8000012E0D010C3F, 8000016E0D010C3F, 8000022E0D010C3F, 8000026E0D010C3F, 8000032E0D010C3F, 8000036E0D010C3F, 8000082E0D010C3F, 8000086E0D010C3F, 8000092E0D010C3F, 8000096E0D010C3F, 80000A6E0D010C3F, 80000B2E0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2E                                          = 0x80000B6E0D010C3Full;
//DUPS: 800000AE0D010C3F, 80000A2E0D010C3F, 800000EE0D010C3F, 800001AE0D010C3F, 800001EE0D010C3F, 800003EE0D010C3F, 800003AE0D010C3F, 800002EE0D010C3F, 800002AE0D010C3F, 800009EE0D010C3F, 800009AE0D010C3F, 800008EE0D010C3F, 800008AE0D010C3F, 80000BEE0D010C3F, 80000BAE0D010C3F, 80000AEE0D010C3F, 80000AAE0D010C3F, 8000002E0D010C3F, 8000006E0D010C3F, 8000012E0D010C3F, 8000016E0D010C3F, 8000022E0D010C3F, 8000026E0D010C3F, 8000032E0D010C3F, 8000036E0D010C3F, 8000082E0D010C3F, 8000086E0D010C3F, 8000092E0D010C3F, 8000096E0D010C3F, 80000A6E0D010C3F, 80000B2E0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2E                                          = 0x80000B6E0E010C3Full;
//DUPS: 800000AE0E010C3F, 80000A2E0E010C3F, 800000EE0E010C3F, 800001AE0E010C3F, 800001EE0E010C3F, 800003EE0E010C3F, 800003AE0E010C3F, 800002EE0E010C3F, 800002AE0E010C3F, 800009EE0E010C3F, 800009AE0E010C3F, 800008EE0E010C3F, 800008AE0E010C3F, 80000BEE0E010C3F, 80000BAE0E010C3F, 80000AEE0E010C3F, 80000AAE0E010C3F, 8000002E0E010C3F, 8000006E0E010C3F, 8000012E0E010C3F, 8000016E0E010C3F, 8000022E0E010C3F, 8000026E0E010C3F, 8000032E0E010C3F, 8000036E0E010C3F, 8000082E0E010C3F, 8000086E0E010C3F, 8000092E0E010C3F, 8000096E0E010C3F, 80000A6E0E010C3F, 80000B2E0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2E                                          = 0x80000B6E0F010C3Full;
//DUPS: 800000AE0F010C3F, 80000A2E0F010C3F, 800000EE0F010C3F, 800001AE0F010C3F, 800001EE0F010C3F, 800003EE0F010C3F, 800003AE0F010C3F, 800002EE0F010C3F, 800002AE0F010C3F, 800009EE0F010C3F, 800009AE0F010C3F, 800008EE0F010C3F, 800008AE0F010C3F, 80000BEE0F010C3F, 80000BAE0F010C3F, 80000AEE0F010C3F, 80000AAE0F010C3F, 8000002E0F010C3F, 8000006E0F010C3F, 8000012E0F010C3F, 8000016E0F010C3F, 8000022E0F010C3F, 8000026E0F010C3F, 8000032E0F010C3F, 8000036E0F010C3F, 8000082E0F010C3F, 8000086E0F010C3F, 8000092E0F010C3F, 8000096E0F010C3F, 80000A6E0F010C3F, 80000B2E0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X2F                                            = 0x80000B6F0D010C3Full;
//DUPS: 800000AF0D010C3F, 80000A2F0D010C3F, 800000EF0D010C3F, 800001AF0D010C3F, 800001EF0D010C3F, 800003EF0D010C3F, 800003AF0D010C3F, 800002EF0D010C3F, 800002AF0D010C3F, 800009EF0D010C3F, 800009AF0D010C3F, 800008EF0D010C3F, 800008AF0D010C3F, 80000BEF0D010C3F, 80000BAF0D010C3F, 80000AEF0D010C3F, 80000AAF0D010C3F, 8000002F0D010C3F, 8000006F0D010C3F, 8000012F0D010C3F, 8000016F0D010C3F, 8000022F0D010C3F, 8000026F0D010C3F, 8000032F0D010C3F, 8000036F0D010C3F, 8000082F0D010C3F, 8000086F0D010C3F, 8000092F0D010C3F, 8000096F0D010C3F, 80000A6F0D010C3F, 80000B2F0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X2F                                          = 0x80000B6F0D010C3Full;
//DUPS: 800000AF0D010C3F, 80000A2F0D010C3F, 800000EF0D010C3F, 800001AF0D010C3F, 800001EF0D010C3F, 800003EF0D010C3F, 800003AF0D010C3F, 800002EF0D010C3F, 800002AF0D010C3F, 800009EF0D010C3F, 800009AF0D010C3F, 800008EF0D010C3F, 800008AF0D010C3F, 80000BEF0D010C3F, 80000BAF0D010C3F, 80000AEF0D010C3F, 80000AAF0D010C3F, 8000002F0D010C3F, 8000006F0D010C3F, 8000012F0D010C3F, 8000016F0D010C3F, 8000022F0D010C3F, 8000026F0D010C3F, 8000032F0D010C3F, 8000036F0D010C3F, 8000082F0D010C3F, 8000086F0D010C3F, 8000092F0D010C3F, 8000096F0D010C3F, 80000A6F0D010C3F, 80000B2F0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X2F                                          = 0x80000B6F0E010C3Full;
//DUPS: 800000AF0E010C3F, 80000A2F0E010C3F, 800000EF0E010C3F, 800001AF0E010C3F, 800001EF0E010C3F, 800003EF0E010C3F, 800003AF0E010C3F, 800002EF0E010C3F, 800002AF0E010C3F, 800009EF0E010C3F, 800009AF0E010C3F, 800008EF0E010C3F, 800008AF0E010C3F, 80000BEF0E010C3F, 80000BAF0E010C3F, 80000AEF0E010C3F, 80000AAF0E010C3F, 8000002F0E010C3F, 8000006F0E010C3F, 8000012F0E010C3F, 8000016F0E010C3F, 8000022F0E010C3F, 8000026F0E010C3F, 8000032F0E010C3F, 8000036F0E010C3F, 8000082F0E010C3F, 8000086F0E010C3F, 8000092F0E010C3F, 8000096F0E010C3F, 80000A6F0E010C3F, 80000B2F0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X2F                                          = 0x80000B6F0F010C3Full;
//DUPS: 800000AF0F010C3F, 80000A2F0F010C3F, 800000EF0F010C3F, 800001AF0F010C3F, 800001EF0F010C3F, 800003EF0F010C3F, 800003AF0F010C3F, 800002EF0F010C3F, 800002AF0F010C3F, 800009EF0F010C3F, 800009AF0F010C3F, 800008EF0F010C3F, 800008AF0F010C3F, 80000BEF0F010C3F, 80000BAF0F010C3F, 80000AEF0F010C3F, 80000AAF0F010C3F, 8000002F0F010C3F, 8000006F0F010C3F, 8000012F0F010C3F, 8000016F0F010C3F, 8000022F0F010C3F, 8000026F0F010C3F, 8000032F0F010C3F, 8000036F0F010C3F, 8000082F0F010C3F, 8000086F0F010C3F, 8000092F0F010C3F, 8000096F0F010C3F, 80000A6F0F010C3F, 80000B2F0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X30                                            = 0x80000B700D010C3Full;
//DUPS: 800000B00D010C3F, 800004300D010C3F, 80000A300D010C3F, 800000F00D010C3F, 800001B00D010C3F, 800001F00D010C3F, 800003F00D010C3F, 800003B00D010C3F, 800002F00D010C3F, 800002B00D010C3F, 800009F00D010C3F, 800009B00D010C3F, 800008F00D010C3F, 800008B00D010C3F, 80000BF00D010C3F, 80000BB00D010C3F, 80000AF00D010C3F, 80000AB00D010C3F, 800000300D010C3F, 800000700D010C3F, 800001300D010C3F, 800001700D010C3F, 800002300D010C3F, 800002700D010C3F, 800003300D010C3F, 800003700D010C3F, 800008300D010C3F, 800008700D010C3F, 800009300D010C3F, 800009700D010C3F, 80000A700D010C3F, 80000B300D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X30                                          = 0x80000B700D010C3Full;
//DUPS: 800000B00D010C3F, 800004300D010C3F, 80000A300D010C3F, 800000F00D010C3F, 800001B00D010C3F, 800001F00D010C3F, 800003F00D010C3F, 800003B00D010C3F, 800002F00D010C3F, 800002B00D010C3F, 800009F00D010C3F, 800009B00D010C3F, 800008F00D010C3F, 800008B00D010C3F, 80000BF00D010C3F, 80000BB00D010C3F, 80000AF00D010C3F, 80000AB00D010C3F, 800000300D010C3F, 800000700D010C3F, 800001300D010C3F, 800001700D010C3F, 800002300D010C3F, 800002700D010C3F, 800003300D010C3F, 800003700D010C3F, 800008300D010C3F, 800008700D010C3F, 800009300D010C3F, 800009700D010C3F, 80000A700D010C3F, 80000B300D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X30                                          = 0x80000B700E010C3Full;
//DUPS: 800000B00E010C3F, 800004300E010C3F, 80000A300E010C3F, 800000F00E010C3F, 800001B00E010C3F, 800001F00E010C3F, 800003F00E010C3F, 800003B00E010C3F, 800002F00E010C3F, 800002B00E010C3F, 800009F00E010C3F, 800009B00E010C3F, 800008F00E010C3F, 800008B00E010C3F, 80000BF00E010C3F, 80000BB00E010C3F, 80000AF00E010C3F, 80000AB00E010C3F, 800000300E010C3F, 800000700E010C3F, 800001300E010C3F, 800001700E010C3F, 800002300E010C3F, 800002700E010C3F, 800003300E010C3F, 800003700E010C3F, 800008300E010C3F, 800008700E010C3F, 800009300E010C3F, 800009700E010C3F, 80000A700E010C3F, 80000B300E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X30                                          = 0x80000B700F010C3Full;
//DUPS: 800000B00F010C3F, 800004300F010C3F, 80000A300F010C3F, 800000F00F010C3F, 800001B00F010C3F, 800001F00F010C3F, 800003F00F010C3F, 800003B00F010C3F, 800002F00F010C3F, 800002B00F010C3F, 800009F00F010C3F, 800009B00F010C3F, 800008F00F010C3F, 800008B00F010C3F, 80000BF00F010C3F, 80000BB00F010C3F, 80000AF00F010C3F, 80000AB00F010C3F, 800000300F010C3F, 800000700F010C3F, 800001300F010C3F, 800001700F010C3F, 800002300F010C3F, 800002700F010C3F, 800003300F010C3F, 800003700F010C3F, 800008300F010C3F, 800008700F010C3F, 800009300F010C3F, 800009700F010C3F, 80000A700F010C3F, 80000B300F010C3F,

static const uint64_t P9N2_PEC_SCOM0X31                                            = 0x80000BF10D010C3Full;
//DUPS: 800004310D010C3F, 800000F10D010C3F, 800001B10D010C3F, 800001F10D010C3F, 800003F10D010C3F, 800003B10D010C3F, 800002F10D010C3F, 800002B10D010C3F, 800009F10D010C3F, 800009B10D010C3F, 800008F10D010C3F, 800008B10D010C3F, 80000BF10D010C3F, 80000BB10D010C3F, 80000AF10D010C3F, 80000AB10D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X31                                          = 0x80000BF10D010C3Full;
//DUPS: 800004310D010C3F, 800000F10D010C3F, 800001B10D010C3F, 800001F10D010C3F, 800003F10D010C3F, 800003B10D010C3F, 800002F10D010C3F, 800002B10D010C3F, 800009F10D010C3F, 800009B10D010C3F, 800008F10D010C3F, 800008B10D010C3F, 80000BF10D010C3F, 80000BB10D010C3F, 80000AF10D010C3F, 80000AB10D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X31                                          = 0x80000BF10E010C3Full;
//DUPS: 800004310E010C3F, 800000F10E010C3F, 800001B10E010C3F, 800001F10E010C3F, 800003F10E010C3F, 800003B10E010C3F, 800002F10E010C3F, 800002B10E010C3F, 800009F10E010C3F, 800009B10E010C3F, 800008F10E010C3F, 800008B10E010C3F, 80000BF10E010C3F, 80000BB10E010C3F, 80000AF10E010C3F, 80000AB10E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X31                                          = 0x80000BF10F010C3Full;
//DUPS: 800004310F010C3F, 800000F10F010C3F, 800001B10F010C3F, 800001F10F010C3F, 800003F10F010C3F, 800003B10F010C3F, 800002F10F010C3F, 800002B10F010C3F, 800009F10F010C3F, 800009B10F010C3F, 800008F10F010C3F, 800008B10F010C3F, 80000BF10F010C3F, 80000BB10F010C3F, 80000AF10F010C3F, 80000AB10F010C3F,

static const uint64_t P9N2_PEC_SCOM0X32                                            = 0x80000BF20D010C3Full;
//DUPS: 800004320D010C3F, 800000F20D010C3F, 800001B20D010C3F, 800001F20D010C3F, 800003F20D010C3F, 800003B20D010C3F, 800002F20D010C3F, 800002B20D010C3F, 800009F20D010C3F, 800009B20D010C3F, 800008F20D010C3F, 800008B20D010C3F, 80000BF20D010C3F, 80000BB20D010C3F, 80000AF20D010C3F, 80000AB20D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X32                                          = 0x80000BF20D010C3Full;
//DUPS: 800004320D010C3F, 800000F20D010C3F, 800001B20D010C3F, 800001F20D010C3F, 800003F20D010C3F, 800003B20D010C3F, 800002F20D010C3F, 800002B20D010C3F, 800009F20D010C3F, 800009B20D010C3F, 800008F20D010C3F, 800008B20D010C3F, 80000BF20D010C3F, 80000BB20D010C3F, 80000AF20D010C3F, 80000AB20D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X32                                          = 0x80000BF20E010C3Full;
//DUPS: 800004320E010C3F, 800000F20E010C3F, 800001B20E010C3F, 800001F20E010C3F, 800003F20E010C3F, 800003B20E010C3F, 800002F20E010C3F, 800002B20E010C3F, 800009F20E010C3F, 800009B20E010C3F, 800008F20E010C3F, 800008B20E010C3F, 80000BF20E010C3F, 80000BB20E010C3F, 80000AF20E010C3F, 80000AB20E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X32                                          = 0x80000BF20F010C3Full;
//DUPS: 800004320F010C3F, 800000F20F010C3F, 800001B20F010C3F, 800001F20F010C3F, 800003F20F010C3F, 800003B20F010C3F, 800002F20F010C3F, 800002B20F010C3F, 800009F20F010C3F, 800009B20F010C3F, 800008F20F010C3F, 800008B20F010C3F, 80000BF20F010C3F, 80000BB20F010C3F, 80000AF20F010C3F, 80000AB20F010C3F,

static const uint64_t P9N2_PEC_SCOM0X33                                            = 0x80000BF30D010C3Full;
//DUPS: 800004330D010C3F, 800000F30D010C3F, 800001B30D010C3F, 800001F30D010C3F, 800003F30D010C3F, 800003B30D010C3F, 800002F30D010C3F, 800002B30D010C3F, 800009F30D010C3F, 800009B30D010C3F, 800008F30D010C3F, 800008B30D010C3F, 80000BF30D010C3F, 80000BB30D010C3F, 80000AF30D010C3F, 80000AB30D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X33                                          = 0x80000BF30D010C3Full;
//DUPS: 800004330D010C3F, 800000F30D010C3F, 800001B30D010C3F, 800001F30D010C3F, 800003F30D010C3F, 800003B30D010C3F, 800002F30D010C3F, 800002B30D010C3F, 800009F30D010C3F, 800009B30D010C3F, 800008F30D010C3F, 800008B30D010C3F, 80000BF30D010C3F, 80000BB30D010C3F, 80000AF30D010C3F, 80000AB30D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X33                                          = 0x80000BF30E010C3Full;
//DUPS: 800004330E010C3F, 800000F30E010C3F, 800001B30E010C3F, 800001F30E010C3F, 800003F30E010C3F, 800003B30E010C3F, 800002F30E010C3F, 800002B30E010C3F, 800009F30E010C3F, 800009B30E010C3F, 800008F30E010C3F, 800008B30E010C3F, 80000BF30E010C3F, 80000BB30E010C3F, 80000AF30E010C3F, 80000AB30E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X33                                          = 0x80000BF30F010C3Full;
//DUPS: 800004330F010C3F, 800000F30F010C3F, 800001B30F010C3F, 800001F30F010C3F, 800003F30F010C3F, 800003B30F010C3F, 800002F30F010C3F, 800002B30F010C3F, 800009F30F010C3F, 800009B30F010C3F, 800008F30F010C3F, 800008B30F010C3F, 80000BF30F010C3F, 80000BB30F010C3F, 80000AF30F010C3F, 80000AB30F010C3F,

static const uint64_t P9N2_PEC_SCOM0X34                                            = 0x80000BF40D010C3Full;
//DUPS: 800004340D010C3F, 800000F40D010C3F, 800001B40D010C3F, 800001F40D010C3F, 800003F40D010C3F, 800003B40D010C3F, 800002F40D010C3F, 800002B40D010C3F, 800009F40D010C3F, 800009B40D010C3F, 800008F40D010C3F, 800008B40D010C3F, 80000BF40D010C3F, 80000BB40D010C3F, 80000AF40D010C3F, 80000AB40D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X34                                          = 0x80000BF40D010C3Full;
//DUPS: 800004340D010C3F, 800000F40D010C3F, 800001B40D010C3F, 800001F40D010C3F, 800003F40D010C3F, 800003B40D010C3F, 800002F40D010C3F, 800002B40D010C3F, 800009F40D010C3F, 800009B40D010C3F, 800008F40D010C3F, 800008B40D010C3F, 80000BF40D010C3F, 80000BB40D010C3F, 80000AF40D010C3F, 80000AB40D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X34                                          = 0x80000BF40E010C3Full;
//DUPS: 800004340E010C3F, 800000F40E010C3F, 800001B40E010C3F, 800001F40E010C3F, 800003F40E010C3F, 800003B40E010C3F, 800002F40E010C3F, 800002B40E010C3F, 800009F40E010C3F, 800009B40E010C3F, 800008F40E010C3F, 800008B40E010C3F, 80000BF40E010C3F, 80000BB40E010C3F, 80000AF40E010C3F, 80000AB40E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X34                                          = 0x80000BF40F010C3Full;
//DUPS: 800004340F010C3F, 800000F40F010C3F, 800001B40F010C3F, 800001F40F010C3F, 800003F40F010C3F, 800003B40F010C3F, 800002F40F010C3F, 800002B40F010C3F, 800009F40F010C3F, 800009B40F010C3F, 800008F40F010C3F, 800008B40F010C3F, 80000BF40F010C3F, 80000BB40F010C3F, 80000AF40F010C3F, 80000AB40F010C3F,

static const uint64_t P9N2_PEC_SCOM0X35                                            = 0x800004350D010C3Full;

static const uint64_t P9N2_PEC_0_SCOM0X35                                          = 0x800004350D010C3Full;

static const uint64_t P9N2_PEC_1_SCOM0X35                                          = 0x800004350E010C3Full;

static const uint64_t P9N2_PEC_2_SCOM0X35                                          = 0x800004350F010C3Full;


static const uint64_t P9N2_PEC_SCOM0X36                                            = 0x800004360D010C3Full;

static const uint64_t P9N2_PEC_0_SCOM0X36                                          = 0x800004360D010C3Full;

static const uint64_t P9N2_PEC_1_SCOM0X36                                          = 0x800004360E010C3Full;

static const uint64_t P9N2_PEC_2_SCOM0X36                                          = 0x800004360F010C3Full;


static const uint64_t P9N2_PEC_SCOM0X37                                            = 0x800004370D010C3Full;

static const uint64_t P9N2_PEC_0_SCOM0X37                                          = 0x800004370D010C3Full;

static const uint64_t P9N2_PEC_1_SCOM0X37                                          = 0x800004370E010C3Full;

static const uint64_t P9N2_PEC_2_SCOM0X37                                          = 0x800004370F010C3Full;


static const uint64_t P9N2_PEC_SCOM0X38                                            = 0x80000B780D010C3Full;
//DUPS: 800004380D010C3F, 80000A380D010C3F, 800000380D010C3F, 800000780D010C3F, 800001380D010C3F, 800001780D010C3F, 800002380D010C3F, 800002780D010C3F, 800003380D010C3F, 800003780D010C3F, 800008380D010C3F, 800008780D010C3F, 800009380D010C3F, 800009780D010C3F, 80000A780D010C3F, 80000B380D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X38                                          = 0x80000B780D010C3Full;
//DUPS: 800004380D010C3F, 80000A380D010C3F, 800000380D010C3F, 800000780D010C3F, 800001380D010C3F, 800001780D010C3F, 800002380D010C3F, 800002780D010C3F, 800003380D010C3F, 800003780D010C3F, 800008380D010C3F, 800008780D010C3F, 800009380D010C3F, 800009780D010C3F, 80000A780D010C3F, 80000B380D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X38                                          = 0x80000B780E010C3Full;
//DUPS: 800004380E010C3F, 80000A380E010C3F, 800000380E010C3F, 800000780E010C3F, 800001380E010C3F, 800001780E010C3F, 800002380E010C3F, 800002780E010C3F, 800003380E010C3F, 800003780E010C3F, 800008380E010C3F, 800008780E010C3F, 800009380E010C3F, 800009780E010C3F, 80000A780E010C3F, 80000B380E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X38                                          = 0x80000B780F010C3Full;
//DUPS: 800004380F010C3F, 80000A380F010C3F, 800000380F010C3F, 800000780F010C3F, 800001380F010C3F, 800001780F010C3F, 800002380F010C3F, 800002780F010C3F, 800003380F010C3F, 800003780F010C3F, 800008380F010C3F, 800008780F010C3F, 800009380F010C3F, 800009780F010C3F, 80000A780F010C3F, 80000B380F010C3F,

static const uint64_t P9N2_PEC_SCOM0X39                                            = 0x80000B790D010C3Full;
//DUPS: 800004390D010C3F, 80000A390D010C3F, 800000390D010C3F, 800000790D010C3F, 800001390D010C3F, 800001790D010C3F, 800002390D010C3F, 800002790D010C3F, 800003390D010C3F, 800003790D010C3F, 800008390D010C3F, 800008790D010C3F, 800009390D010C3F, 800009790D010C3F, 80000A790D010C3F, 80000B390D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X39                                          = 0x80000B790D010C3Full;
//DUPS: 800004390D010C3F, 80000A390D010C3F, 800000390D010C3F, 800000790D010C3F, 800001390D010C3F, 800001790D010C3F, 800002390D010C3F, 800002790D010C3F, 800003390D010C3F, 800003790D010C3F, 800008390D010C3F, 800008790D010C3F, 800009390D010C3F, 800009790D010C3F, 80000A790D010C3F, 80000B390D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X39                                          = 0x80000B790E010C3Full;
//DUPS: 800004390E010C3F, 80000A390E010C3F, 800000390E010C3F, 800000790E010C3F, 800001390E010C3F, 800001790E010C3F, 800002390E010C3F, 800002790E010C3F, 800003390E010C3F, 800003790E010C3F, 800008390E010C3F, 800008790E010C3F, 800009390E010C3F, 800009790E010C3F, 80000A790E010C3F, 80000B390E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X39                                          = 0x80000B790F010C3Full;
//DUPS: 800004390F010C3F, 80000A390F010C3F, 800000390F010C3F, 800000790F010C3F, 800001390F010C3F, 800001790F010C3F, 800002390F010C3F, 800002790F010C3F, 800003390F010C3F, 800003790F010C3F, 800008390F010C3F, 800008790F010C3F, 800009390F010C3F, 800009790F010C3F, 80000A790F010C3F, 80000B390F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3A                                            = 0x80000B7A0D010C3Full;
//DUPS: 8000043A0D010C3F, 800000BA0D010C3F, 80000A3A0D010C3F, 800000FA0D010C3F, 800001BA0D010C3F, 800001FA0D010C3F, 800003FA0D010C3F, 800003BA0D010C3F, 800002FA0D010C3F, 800002BA0D010C3F, 800009FA0D010C3F, 800009BA0D010C3F, 800008FA0D010C3F, 800008BA0D010C3F, 80000BFA0D010C3F, 80000BBA0D010C3F, 80000AFA0D010C3F, 80000ABA0D010C3F, 8000003A0D010C3F, 8000007A0D010C3F, 8000013A0D010C3F, 8000017A0D010C3F, 8000023A0D010C3F, 8000027A0D010C3F, 8000033A0D010C3F, 8000037A0D010C3F, 8000083A0D010C3F, 8000087A0D010C3F, 8000093A0D010C3F, 8000097A0D010C3F, 80000A7A0D010C3F, 80000B3A0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3A                                          = 0x80000B7A0D010C3Full;
//DUPS: 8000043A0D010C3F, 800000BA0D010C3F, 80000A3A0D010C3F, 800000FA0D010C3F, 800001BA0D010C3F, 800001FA0D010C3F, 800003FA0D010C3F, 800003BA0D010C3F, 800002FA0D010C3F, 800002BA0D010C3F, 800009FA0D010C3F, 800009BA0D010C3F, 800008FA0D010C3F, 800008BA0D010C3F, 80000BFA0D010C3F, 80000BBA0D010C3F, 80000AFA0D010C3F, 80000ABA0D010C3F, 8000003A0D010C3F, 8000007A0D010C3F, 8000013A0D010C3F, 8000017A0D010C3F, 8000023A0D010C3F, 8000027A0D010C3F, 8000033A0D010C3F, 8000037A0D010C3F, 8000083A0D010C3F, 8000087A0D010C3F, 8000093A0D010C3F, 8000097A0D010C3F, 80000A7A0D010C3F, 80000B3A0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3A                                          = 0x80000B7A0E010C3Full;
//DUPS: 8000043A0E010C3F, 800000BA0E010C3F, 80000A3A0E010C3F, 800000FA0E010C3F, 800001BA0E010C3F, 800001FA0E010C3F, 800003FA0E010C3F, 800003BA0E010C3F, 800002FA0E010C3F, 800002BA0E010C3F, 800009FA0E010C3F, 800009BA0E010C3F, 800008FA0E010C3F, 800008BA0E010C3F, 80000BFA0E010C3F, 80000BBA0E010C3F, 80000AFA0E010C3F, 80000ABA0E010C3F, 8000003A0E010C3F, 8000007A0E010C3F, 8000013A0E010C3F, 8000017A0E010C3F, 8000023A0E010C3F, 8000027A0E010C3F, 8000033A0E010C3F, 8000037A0E010C3F, 8000083A0E010C3F, 8000087A0E010C3F, 8000093A0E010C3F, 8000097A0E010C3F, 80000A7A0E010C3F, 80000B3A0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3A                                          = 0x80000B7A0F010C3Full;
//DUPS: 8000043A0F010C3F, 800000BA0F010C3F, 80000A3A0F010C3F, 800000FA0F010C3F, 800001BA0F010C3F, 800001FA0F010C3F, 800003FA0F010C3F, 800003BA0F010C3F, 800002FA0F010C3F, 800002BA0F010C3F, 800009FA0F010C3F, 800009BA0F010C3F, 800008FA0F010C3F, 800008BA0F010C3F, 80000BFA0F010C3F, 80000BBA0F010C3F, 80000AFA0F010C3F, 80000ABA0F010C3F, 8000003A0F010C3F, 8000007A0F010C3F, 8000013A0F010C3F, 8000017A0F010C3F, 8000023A0F010C3F, 8000027A0F010C3F, 8000033A0F010C3F, 8000037A0F010C3F, 8000083A0F010C3F, 8000087A0F010C3F, 8000093A0F010C3F, 8000097A0F010C3F, 80000A7A0F010C3F, 80000B3A0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3B                                            = 0x80000B7B0D010C3Full;
//DUPS: 8000043B0D010C3F, 8000053B0D010C3F, 800000BB0D010C3F, 8000057B0D010C3F, 80000A3B0D010C3F, 800000FB0D010C3F, 800001BB0D010C3F, 800001FB0D010C3F, 800003FB0D010C3F, 800003BB0D010C3F, 800002FB0D010C3F, 800002BB0D010C3F, 800009FB0D010C3F, 800009BB0D010C3F, 800008FB0D010C3F, 800008BB0D010C3F, 80000BFB0D010C3F, 80000BBB0D010C3F, 80000AFB0D010C3F, 80000ABB0D010C3F, 8000003B0D010C3F, 8000007B0D010C3F, 8000013B0D010C3F, 8000017B0D010C3F, 8000023B0D010C3F, 8000027B0D010C3F, 8000033B0D010C3F, 8000037B0D010C3F, 8000083B0D010C3F, 8000087B0D010C3F, 8000093B0D010C3F, 8000097B0D010C3F, 80000A7B0D010C3F, 80000B3B0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3B                                          = 0x80000B7B0D010C3Full;
//DUPS: 8000043B0D010C3F, 8000053B0D010C3F, 800000BB0D010C3F, 8000057B0D010C3F, 80000A3B0D010C3F, 800000FB0D010C3F, 800001BB0D010C3F, 800001FB0D010C3F, 800003FB0D010C3F, 800003BB0D010C3F, 800002FB0D010C3F, 800002BB0D010C3F, 800009FB0D010C3F, 800009BB0D010C3F, 800008FB0D010C3F, 800008BB0D010C3F, 80000BFB0D010C3F, 80000BBB0D010C3F, 80000AFB0D010C3F, 80000ABB0D010C3F, 8000003B0D010C3F, 8000007B0D010C3F, 8000013B0D010C3F, 8000017B0D010C3F, 8000023B0D010C3F, 8000027B0D010C3F, 8000033B0D010C3F, 8000037B0D010C3F, 8000083B0D010C3F, 8000087B0D010C3F, 8000093B0D010C3F, 8000097B0D010C3F, 80000A7B0D010C3F, 80000B3B0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3B                                          = 0x80000B7B0E010C3Full;
//DUPS: 8000043B0E010C3F, 8000053B0E010C3F, 800000BB0E010C3F, 8000057B0E010C3F, 80000A3B0E010C3F, 800000FB0E010C3F, 800001BB0E010C3F, 800001FB0E010C3F, 800003FB0E010C3F, 800003BB0E010C3F, 800002FB0E010C3F, 800002BB0E010C3F, 800009FB0E010C3F, 800009BB0E010C3F, 800008FB0E010C3F, 800008BB0E010C3F, 80000BFB0E010C3F, 80000BBB0E010C3F, 80000AFB0E010C3F, 80000ABB0E010C3F, 8000003B0E010C3F, 8000007B0E010C3F, 8000013B0E010C3F, 8000017B0E010C3F, 8000023B0E010C3F, 8000027B0E010C3F, 8000033B0E010C3F, 8000037B0E010C3F, 8000083B0E010C3F, 8000087B0E010C3F, 8000093B0E010C3F, 8000097B0E010C3F, 80000A7B0E010C3F, 80000B3B0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3B                                          = 0x80000B7B0F010C3Full;
//DUPS: 8000043B0F010C3F, 8000053B0F010C3F, 800000BB0F010C3F, 8000057B0F010C3F, 80000A3B0F010C3F, 800000FB0F010C3F, 800001BB0F010C3F, 800001FB0F010C3F, 800003FB0F010C3F, 800003BB0F010C3F, 800002FB0F010C3F, 800002BB0F010C3F, 800009FB0F010C3F, 800009BB0F010C3F, 800008FB0F010C3F, 800008BB0F010C3F, 80000BFB0F010C3F, 80000BBB0F010C3F, 80000AFB0F010C3F, 80000ABB0F010C3F, 8000003B0F010C3F, 8000007B0F010C3F, 8000013B0F010C3F, 8000017B0F010C3F, 8000023B0F010C3F, 8000027B0F010C3F, 8000033B0F010C3F, 8000037B0F010C3F, 8000083B0F010C3F, 8000087B0F010C3F, 8000093B0F010C3F, 8000097B0F010C3F, 80000A7B0F010C3F, 80000B3B0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3C                                            = 0x80000B7C0D010C3Full;
//DUPS: 8000053C0D010C3F, 800000BC0D010C3F, 8000057C0D010C3F, 80000A3C0D010C3F, 800000FC0D010C3F, 800001BC0D010C3F, 800001FC0D010C3F, 800003FC0D010C3F, 800003BC0D010C3F, 800002FC0D010C3F, 800002BC0D010C3F, 800009FC0D010C3F, 800009BC0D010C3F, 800008FC0D010C3F, 800008BC0D010C3F, 80000BFC0D010C3F, 80000BBC0D010C3F, 80000AFC0D010C3F, 80000ABC0D010C3F, 8000003C0D010C3F, 8000007C0D010C3F, 8000013C0D010C3F, 8000017C0D010C3F, 8000023C0D010C3F, 8000027C0D010C3F, 8000033C0D010C3F, 8000037C0D010C3F, 8000083C0D010C3F, 8000087C0D010C3F, 8000093C0D010C3F, 8000097C0D010C3F, 80000A7C0D010C3F, 80000B3C0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3C                                          = 0x80000B7C0D010C3Full;
//DUPS: 8000053C0D010C3F, 800000BC0D010C3F, 8000057C0D010C3F, 80000A3C0D010C3F, 800000FC0D010C3F, 800001BC0D010C3F, 800001FC0D010C3F, 800003FC0D010C3F, 800003BC0D010C3F, 800002FC0D010C3F, 800002BC0D010C3F, 800009FC0D010C3F, 800009BC0D010C3F, 800008FC0D010C3F, 800008BC0D010C3F, 80000BFC0D010C3F, 80000BBC0D010C3F, 80000AFC0D010C3F, 80000ABC0D010C3F, 8000003C0D010C3F, 8000007C0D010C3F, 8000013C0D010C3F, 8000017C0D010C3F, 8000023C0D010C3F, 8000027C0D010C3F, 8000033C0D010C3F, 8000037C0D010C3F, 8000083C0D010C3F, 8000087C0D010C3F, 8000093C0D010C3F, 8000097C0D010C3F, 80000A7C0D010C3F, 80000B3C0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3C                                          = 0x80000B7C0E010C3Full;
//DUPS: 8000053C0E010C3F, 800000BC0E010C3F, 8000057C0E010C3F, 80000A3C0E010C3F, 800000FC0E010C3F, 800001BC0E010C3F, 800001FC0E010C3F, 800003FC0E010C3F, 800003BC0E010C3F, 800002FC0E010C3F, 800002BC0E010C3F, 800009FC0E010C3F, 800009BC0E010C3F, 800008FC0E010C3F, 800008BC0E010C3F, 80000BFC0E010C3F, 80000BBC0E010C3F, 80000AFC0E010C3F, 80000ABC0E010C3F, 8000003C0E010C3F, 8000007C0E010C3F, 8000013C0E010C3F, 8000017C0E010C3F, 8000023C0E010C3F, 8000027C0E010C3F, 8000033C0E010C3F, 8000037C0E010C3F, 8000083C0E010C3F, 8000087C0E010C3F, 8000093C0E010C3F, 8000097C0E010C3F, 80000A7C0E010C3F, 80000B3C0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3C                                          = 0x80000B7C0F010C3Full;
//DUPS: 8000053C0F010C3F, 800000BC0F010C3F, 8000057C0F010C3F, 80000A3C0F010C3F, 800000FC0F010C3F, 800001BC0F010C3F, 800001FC0F010C3F, 800003FC0F010C3F, 800003BC0F010C3F, 800002FC0F010C3F, 800002BC0F010C3F, 800009FC0F010C3F, 800009BC0F010C3F, 800008FC0F010C3F, 800008BC0F010C3F, 80000BFC0F010C3F, 80000BBC0F010C3F, 80000AFC0F010C3F, 80000ABC0F010C3F, 8000003C0F010C3F, 8000007C0F010C3F, 8000013C0F010C3F, 8000017C0F010C3F, 8000023C0F010C3F, 8000027C0F010C3F, 8000033C0F010C3F, 8000037C0F010C3F, 8000083C0F010C3F, 8000087C0F010C3F, 8000093C0F010C3F, 8000097C0F010C3F, 80000A7C0F010C3F, 80000B3C0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3D                                            = 0x80000B7D0D010C3Full;
//DUPS: 8000053D0D010C3F, 800000BD0D010C3F, 8000057D0D010C3F, 80000A3D0D010C3F, 800000FD0D010C3F, 800001BD0D010C3F, 800001FD0D010C3F, 800003FD0D010C3F, 800003BD0D010C3F, 800002FD0D010C3F, 800002BD0D010C3F, 800009FD0D010C3F, 800009BD0D010C3F, 800008FD0D010C3F, 800008BD0D010C3F, 80000BFD0D010C3F, 80000BBD0D010C3F, 80000AFD0D010C3F, 80000ABD0D010C3F, 8000003D0D010C3F, 8000007D0D010C3F, 8000013D0D010C3F, 8000017D0D010C3F, 8000023D0D010C3F, 8000027D0D010C3F, 8000033D0D010C3F, 8000037D0D010C3F, 8000083D0D010C3F, 8000087D0D010C3F, 8000093D0D010C3F, 8000097D0D010C3F, 80000A7D0D010C3F, 80000B3D0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3D                                          = 0x80000B7D0D010C3Full;
//DUPS: 8000053D0D010C3F, 800000BD0D010C3F, 8000057D0D010C3F, 80000A3D0D010C3F, 800000FD0D010C3F, 800001BD0D010C3F, 800001FD0D010C3F, 800003FD0D010C3F, 800003BD0D010C3F, 800002FD0D010C3F, 800002BD0D010C3F, 800009FD0D010C3F, 800009BD0D010C3F, 800008FD0D010C3F, 800008BD0D010C3F, 80000BFD0D010C3F, 80000BBD0D010C3F, 80000AFD0D010C3F, 80000ABD0D010C3F, 8000003D0D010C3F, 8000007D0D010C3F, 8000013D0D010C3F, 8000017D0D010C3F, 8000023D0D010C3F, 8000027D0D010C3F, 8000033D0D010C3F, 8000037D0D010C3F, 8000083D0D010C3F, 8000087D0D010C3F, 8000093D0D010C3F, 8000097D0D010C3F, 80000A7D0D010C3F, 80000B3D0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3D                                          = 0x80000B7D0E010C3Full;
//DUPS: 8000053D0E010C3F, 800000BD0E010C3F, 8000057D0E010C3F, 80000A3D0E010C3F, 800000FD0E010C3F, 800001BD0E010C3F, 800001FD0E010C3F, 800003FD0E010C3F, 800003BD0E010C3F, 800002FD0E010C3F, 800002BD0E010C3F, 800009FD0E010C3F, 800009BD0E010C3F, 800008FD0E010C3F, 800008BD0E010C3F, 80000BFD0E010C3F, 80000BBD0E010C3F, 80000AFD0E010C3F, 80000ABD0E010C3F, 8000003D0E010C3F, 8000007D0E010C3F, 8000013D0E010C3F, 8000017D0E010C3F, 8000023D0E010C3F, 8000027D0E010C3F, 8000033D0E010C3F, 8000037D0E010C3F, 8000083D0E010C3F, 8000087D0E010C3F, 8000093D0E010C3F, 8000097D0E010C3F, 80000A7D0E010C3F, 80000B3D0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3D                                          = 0x80000B7D0F010C3Full;
//DUPS: 8000053D0F010C3F, 800000BD0F010C3F, 8000057D0F010C3F, 80000A3D0F010C3F, 800000FD0F010C3F, 800001BD0F010C3F, 800001FD0F010C3F, 800003FD0F010C3F, 800003BD0F010C3F, 800002FD0F010C3F, 800002BD0F010C3F, 800009FD0F010C3F, 800009BD0F010C3F, 800008FD0F010C3F, 800008BD0F010C3F, 80000BFD0F010C3F, 80000BBD0F010C3F, 80000AFD0F010C3F, 80000ABD0F010C3F, 8000003D0F010C3F, 8000007D0F010C3F, 8000013D0F010C3F, 8000017D0F010C3F, 8000023D0F010C3F, 8000027D0F010C3F, 8000033D0F010C3F, 8000037D0F010C3F, 8000083D0F010C3F, 8000087D0F010C3F, 8000093D0F010C3F, 8000097D0F010C3F, 80000A7D0F010C3F, 80000B3D0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3E                                            = 0x80000B7E0D010C3Full;
//DUPS: 8000053E0D010C3F, 800000BE0D010C3F, 8000057E0D010C3F, 80000A3E0D010C3F, 800000FE0D010C3F, 800001BE0D010C3F, 800001FE0D010C3F, 800003FE0D010C3F, 800003BE0D010C3F, 800002FE0D010C3F, 800002BE0D010C3F, 800009FE0D010C3F, 800009BE0D010C3F, 800008FE0D010C3F, 800008BE0D010C3F, 80000BFE0D010C3F, 80000BBE0D010C3F, 80000AFE0D010C3F, 80000ABE0D010C3F, 8000003E0D010C3F, 8000007E0D010C3F, 8000013E0D010C3F, 8000017E0D010C3F, 8000023E0D010C3F, 8000027E0D010C3F, 8000033E0D010C3F, 8000037E0D010C3F, 8000083E0D010C3F, 8000087E0D010C3F, 8000093E0D010C3F, 8000097E0D010C3F, 80000A7E0D010C3F, 80000B3E0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3E                                          = 0x80000B7E0D010C3Full;
//DUPS: 8000053E0D010C3F, 800000BE0D010C3F, 8000057E0D010C3F, 80000A3E0D010C3F, 800000FE0D010C3F, 800001BE0D010C3F, 800001FE0D010C3F, 800003FE0D010C3F, 800003BE0D010C3F, 800002FE0D010C3F, 800002BE0D010C3F, 800009FE0D010C3F, 800009BE0D010C3F, 800008FE0D010C3F, 800008BE0D010C3F, 80000BFE0D010C3F, 80000BBE0D010C3F, 80000AFE0D010C3F, 80000ABE0D010C3F, 8000003E0D010C3F, 8000007E0D010C3F, 8000013E0D010C3F, 8000017E0D010C3F, 8000023E0D010C3F, 8000027E0D010C3F, 8000033E0D010C3F, 8000037E0D010C3F, 8000083E0D010C3F, 8000087E0D010C3F, 8000093E0D010C3F, 8000097E0D010C3F, 80000A7E0D010C3F, 80000B3E0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3E                                          = 0x80000B7E0E010C3Full;
//DUPS: 8000053E0E010C3F, 800000BE0E010C3F, 8000057E0E010C3F, 80000A3E0E010C3F, 800000FE0E010C3F, 800001BE0E010C3F, 800001FE0E010C3F, 800003FE0E010C3F, 800003BE0E010C3F, 800002FE0E010C3F, 800002BE0E010C3F, 800009FE0E010C3F, 800009BE0E010C3F, 800008FE0E010C3F, 800008BE0E010C3F, 80000BFE0E010C3F, 80000BBE0E010C3F, 80000AFE0E010C3F, 80000ABE0E010C3F, 8000003E0E010C3F, 8000007E0E010C3F, 8000013E0E010C3F, 8000017E0E010C3F, 8000023E0E010C3F, 8000027E0E010C3F, 8000033E0E010C3F, 8000037E0E010C3F, 8000083E0E010C3F, 8000087E0E010C3F, 8000093E0E010C3F, 8000097E0E010C3F, 80000A7E0E010C3F, 80000B3E0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3E                                          = 0x80000B7E0F010C3Full;
//DUPS: 8000053E0F010C3F, 800000BE0F010C3F, 8000057E0F010C3F, 80000A3E0F010C3F, 800000FE0F010C3F, 800001BE0F010C3F, 800001FE0F010C3F, 800003FE0F010C3F, 800003BE0F010C3F, 800002FE0F010C3F, 800002BE0F010C3F, 800009FE0F010C3F, 800009BE0F010C3F, 800008FE0F010C3F, 800008BE0F010C3F, 80000BFE0F010C3F, 80000BBE0F010C3F, 80000AFE0F010C3F, 80000ABE0F010C3F, 8000003E0F010C3F, 8000007E0F010C3F, 8000013E0F010C3F, 8000017E0F010C3F, 8000023E0F010C3F, 8000027E0F010C3F, 8000033E0F010C3F, 8000037E0F010C3F, 8000083E0F010C3F, 8000087E0F010C3F, 8000093E0F010C3F, 8000097E0F010C3F, 80000A7E0F010C3F, 80000B3E0F010C3F,

static const uint64_t P9N2_PEC_SCOM0X3F                                            = 0x80000B7F0D010C3Full;
//DUPS: 8000053F0D010C3F, 800000BF0D010C3F, 8000057F0D010C3F, 80000A3F0D010C3F, 800000FF0D010C3F, 800001BF0D010C3F, 800001FF0D010C3F, 800003FF0D010C3F, 800003BF0D010C3F, 800002FF0D010C3F, 800002BF0D010C3F, 800009FF0D010C3F, 800009BF0D010C3F, 800008FF0D010C3F, 800008BF0D010C3F, 80000BFF0D010C3F, 80000BBF0D010C3F, 80000AFF0D010C3F, 80000ABF0D010C3F, 8000003F0D010C3F, 8000007F0D010C3F, 8000013F0D010C3F, 8000017F0D010C3F, 8000023F0D010C3F, 8000027F0D010C3F, 8000033F0D010C3F, 8000037F0D010C3F, 8000083F0D010C3F, 8000087F0D010C3F, 8000093F0D010C3F, 8000097F0D010C3F, 80000A7F0D010C3F, 80000B3F0D010C3F,
static const uint64_t P9N2_PEC_0_SCOM0X3F                                          = 0x80000B7F0D010C3Full;
//DUPS: 8000053F0D010C3F, 800000BF0D010C3F, 8000057F0D010C3F, 80000A3F0D010C3F, 800000FF0D010C3F, 800001BF0D010C3F, 800001FF0D010C3F, 800003FF0D010C3F, 800003BF0D010C3F, 800002FF0D010C3F, 800002BF0D010C3F, 800009FF0D010C3F, 800009BF0D010C3F, 800008FF0D010C3F, 800008BF0D010C3F, 80000BFF0D010C3F, 80000BBF0D010C3F, 80000AFF0D010C3F, 80000ABF0D010C3F, 8000003F0D010C3F, 8000007F0D010C3F, 8000013F0D010C3F, 8000017F0D010C3F, 8000023F0D010C3F, 8000027F0D010C3F, 8000033F0D010C3F, 8000037F0D010C3F, 8000083F0D010C3F, 8000087F0D010C3F, 8000093F0D010C3F, 8000097F0D010C3F, 80000A7F0D010C3F, 80000B3F0D010C3F,
static const uint64_t P9N2_PEC_1_SCOM0X3F                                          = 0x80000B7F0E010C3Full;
//DUPS: 8000053F0E010C3F, 800000BF0E010C3F, 8000057F0E010C3F, 80000A3F0E010C3F, 800000FF0E010C3F, 800001BF0E010C3F, 800001FF0E010C3F, 800003FF0E010C3F, 800003BF0E010C3F, 800002FF0E010C3F, 800002BF0E010C3F, 800009FF0E010C3F, 800009BF0E010C3F, 800008FF0E010C3F, 800008BF0E010C3F, 80000BFF0E010C3F, 80000BBF0E010C3F, 80000AFF0E010C3F, 80000ABF0E010C3F, 8000003F0E010C3F, 8000007F0E010C3F, 8000013F0E010C3F, 8000017F0E010C3F, 8000023F0E010C3F, 8000027F0E010C3F, 8000033F0E010C3F, 8000037F0E010C3F, 8000083F0E010C3F, 8000087F0E010C3F, 8000093F0E010C3F, 8000097F0E010C3F, 80000A7F0E010C3F, 80000B3F0E010C3F,
static const uint64_t P9N2_PEC_2_SCOM0X3F                                          = 0x80000B7F0F010C3Full;
//DUPS: 8000053F0F010C3F, 800000BF0F010C3F, 8000057F0F010C3F, 80000A3F0F010C3F, 800000FF0F010C3F, 800001BF0F010C3F, 800001FF0F010C3F, 800003FF0F010C3F, 800003BF0F010C3F, 800002FF0F010C3F, 800002BF0F010C3F, 800009FF0F010C3F, 800009BF0F010C3F, 800008FF0F010C3F, 800008BF0F010C3F, 80000BFF0F010C3F, 80000BBF0F010C3F, 80000AFF0F010C3F, 80000ABF0F010C3F, 8000003F0F010C3F, 8000007F0F010C3F, 8000013F0F010C3F, 8000017F0F010C3F, 8000023F0F010C3F, 8000027F0F010C3F, 8000033F0F010C3F, 8000037F0F010C3F, 8000083F0F010C3F, 8000087F0F010C3F, 8000093F0F010C3F, 8000097F0F010C3F, 80000A7F0F010C3F, 80000B3F0F010C3F,

static const uint64_t P9N2_PU_SCOM_PPE_CNTL                                        = 0x0C011060ull;
//DUPS: 0C011060,

static const uint64_t P9N2_PU_SCOM_PPE_FLAGS                                       = 0x0C011063ull;
//DUPS: 0C011063,
static const uint64_t P9N2_PU_SCOM_PPE_FLAGS_OR                                    = 0x0C011064ull;
//DUPS: 0C011064,
static const uint64_t P9N2_PU_SCOM_PPE_FLAGS_CLEAR                                 = 0x0C011065ull;
//DUPS: 0C011065,

static const uint64_t P9N2_PU_SCOM_PPE_WORK_REG1                                   = 0x0C011061ull;
//DUPS: 0C011061,

static const uint64_t P9N2_PU_SCOM_PPE_WORK_REG2                                   = 0x0C011062ull;
//DUPS: 0C011062,

static const uint64_t P9N2_PU_SCRATCH0_PPE                                         = 0xC0001000ull;

static const uint64_t P9N2_PU_SCRATCH0_PPE1                                        = 0xC0001010ull;

static const uint64_t P9N2_PU_SCRATCH0_PPE2                                        = 0xC0001018ull;

static const uint64_t P9N2_NV_1_SCRATCH0                                           = 0x050110F3ull;

static const uint64_t P9N2_NV_5_SCRATCH0                                           = 0x050114F3ull;

static const uint64_t P9N2_PU_NPU2_NTL1_SCRATCH0                                   = 0x050112F3ull;


static const uint64_t P9N2_PU_SCRATCH1_PPE                                         = 0xC0001020ull;

static const uint64_t P9N2_PU_SCRATCH1_PPE1                                        = 0xC0001030ull;

static const uint64_t P9N2_PU_SCRATCH1_PPE2                                        = 0xC0001038ull;

static const uint64_t P9N2_PU_NPU1_SM0_SCRATCH1                                    = 0x0501110Cull;

static const uint64_t P9N2_PU_NPU1_SM1_SCRATCH1                                    = 0x0501112Aull;

static const uint64_t P9N2_PU_NPU1_SM2_SCRATCH1                                    = 0x0501114Aull;

static const uint64_t P9N2_PU_NPU_SM0_SCRATCH1                                     = 0x0501130Cull;

static const uint64_t P9N2_PU_NPU_SM1_SCRATCH1                                     = 0x0501132Aull;

static const uint64_t P9N2_PU_NPU_SM2_SCRATCH1                                     = 0x0501134Aull;

static const uint64_t P9N2__SM0_SCRATCH1                                           = 0x0501150Cull;

static const uint64_t P9N2__SM1_SCRATCH1                                           = 0x0501152Aull;

static const uint64_t P9N2__SM2_SCRATCH1                                           = 0x0501154Aull;


static const uint64_t P9N2_PU_SCRATCH2_PPE                                         = 0xC0001040ull;

static const uint64_t P9N2_PU_SCRATCH2_PPE1                                        = 0xC0001050ull;

static const uint64_t P9N2_PU_SCRATCH2_PPE2                                        = 0xC0001058ull;

static const uint64_t P9N2_PU_NPU1_SM0_SCRATCH2                                    = 0x0501111Aull;

static const uint64_t P9N2_PU_NPU1_SM1_SCRATCH2                                    = 0x0501113Aull;

static const uint64_t P9N2_PU_NPU_SM0_SCRATCH2                                     = 0x0501131Aull;

static const uint64_t P9N2_PU_NPU_SM1_SCRATCH2                                     = 0x0501133Aull;

static const uint64_t P9N2__SM0_SCRATCH2                                           = 0x0501151Aull;

static const uint64_t P9N2__SM1_SCRATCH2                                           = 0x0501153Aull;


static const uint64_t P9N2_PU_SCRATCH3_PPE                                         = 0xC0001060ull;

static const uint64_t P9N2_PU_SCRATCH3_PPE1                                        = 0xC0001070ull;

static const uint64_t P9N2_PU_SCRATCH3_PPE2                                        = 0xC0001078ull;

static const uint64_t P9N2_PU_NPU1_SM0_SCRATCH3                                    = 0x0501111Bull;

static const uint64_t P9N2_PU_NPU1_SM1_SCRATCH3                                    = 0x0501113Bull;

static const uint64_t P9N2_PU_NPU_SM0_SCRATCH3                                     = 0x0501131Bull;

static const uint64_t P9N2_PU_NPU_SM1_SCRATCH3                                     = 0x0501133Bull;

static const uint64_t P9N2__SM0_SCRATCH3                                           = 0x0501151Bull;

static const uint64_t P9N2__SM1_SCRATCH3                                           = 0x0501153Bull;


static const uint64_t P9N2_PU_SECURITY_SWITCH_REGISTER_SCOM                        = 0x00010005ull;

static const uint64_t P9N2_PU_SECURITY_SWITCH_REGISTER_SCOM1                       = 0x00010006ull;


static const uint64_t P9N2_PU_SEND_WC_BASE_ADDR                                    = 0x020110D2ull;


static const uint64_t P9N2_PEC_SKITTER_CLKSRC_REG                                  = 0x0D050016ull;

static const uint64_t P9N2_PEC_0_SKITTER_CLKSRC_REG                                = 0x0D050016ull;

static const uint64_t P9N2_PEC_1_SKITTER_CLKSRC_REG                                = 0x0E050016ull;

static const uint64_t P9N2_PEC_2_SKITTER_CLKSRC_REG                                = 0x0F050016ull;


static const uint64_t P9N2_PEC_SKITTER_DATA0                                       = 0x0D050019ull;

static const uint64_t P9N2_PEC_0_SKITTER_DATA0                                     = 0x0D050019ull;

static const uint64_t P9N2_PEC_1_SKITTER_DATA0                                     = 0x0E050019ull;

static const uint64_t P9N2_PEC_2_SKITTER_DATA0                                     = 0x0F050019ull;


static const uint64_t P9N2_PEC_SKITTER_DATA1                                       = 0x0D05001Aull;

static const uint64_t P9N2_PEC_0_SKITTER_DATA1                                     = 0x0D05001Aull;

static const uint64_t P9N2_PEC_1_SKITTER_DATA1                                     = 0x0E05001Aull;

static const uint64_t P9N2_PEC_2_SKITTER_DATA1                                     = 0x0F05001Aull;


static const uint64_t P9N2_PEC_SKITTER_DATA2                                       = 0x0D05001Bull;

static const uint64_t P9N2_PEC_0_SKITTER_DATA2                                     = 0x0D05001Bull;

static const uint64_t P9N2_PEC_1_SKITTER_DATA2                                     = 0x0E05001Bull;

static const uint64_t P9N2_PEC_2_SKITTER_DATA2                                     = 0x0F05001Bull;


static const uint64_t P9N2_PEC_SKITTER_FORCE_REG                                   = 0x0D050014ull;

static const uint64_t P9N2_PEC_0_SKITTER_FORCE_REG                                 = 0x0D050014ull;

static const uint64_t P9N2_PEC_1_SKITTER_FORCE_REG                                 = 0x0E050014ull;

static const uint64_t P9N2_PEC_2_SKITTER_FORCE_REG                                 = 0x0F050014ull;


static const uint64_t P9N2_PEC_SKITTER_MODE_REG                                    = 0x0D050010ull;

static const uint64_t P9N2_PEC_0_SKITTER_MODE_REG                                  = 0x0D050010ull;

static const uint64_t P9N2_PEC_1_SKITTER_MODE_REG                                  = 0x0E050010ull;

static const uint64_t P9N2_PEC_2_SKITTER_MODE_REG                                  = 0x0F050010ull;


static const uint64_t P9N2_PEC_SLAVE_CONFIG_REG                                    = 0x0D0F001Eull;

static const uint64_t P9N2_PEC_0_SLAVE_CONFIG_REG                                  = 0x0D0F001Eull;

static const uint64_t P9N2_PEC_1_SLAVE_CONFIG_REG                                  = 0x0E0F001Eull;

static const uint64_t P9N2_PEC_2_SLAVE_CONFIG_REG                                  = 0x0F0F001Eull;


static const uint64_t P9N2_PU_SMF_CONFIG_REG_0                                     = 0x05013C0Aull;


static const uint64_t P9N2_PU_NPU0_SM_STATUS                                       = 0x050110A6ull;

static const uint64_t P9N2_PU_NPU2_SM_STATUS                                       = 0x050112A6ull;

static const uint64_t P9N2_PU_NPU0_SM0_SM_STATUS                                   = 0x05011016ull;

static const uint64_t P9N2_PU_NPU0_SM2_SM_STATUS                                   = 0x05011046ull;

static const uint64_t P9N2_PU_NPU0_SM3_SM_STATUS                                   = 0x05011076ull;

static const uint64_t P9N2_PU_NPU2_SM0_SM_STATUS                                   = 0x05011216ull;

static const uint64_t P9N2_PU_NPU2_SM2_SM_STATUS                                   = 0x05011246ull;

static const uint64_t P9N2_PU_NPU2_SM3_SM_STATUS                                   = 0x05011276ull;

static const uint64_t P9N2_PU_NPU_MSC_SM_STATUS                                    = 0x050114A6ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_SM_STATUS                                = 0x05011416ull;

static const uint64_t P9N2_PU_NPU_MSC_SM2_SM_STATUS                                = 0x05011446ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_SM_STATUS                                = 0x05011476ull;


static const uint64_t P9N2_PU_SND_MODE_REG                                         = 0x00090021ull;


static const uint64_t P9N2_PU_SND_STAT_REG                                         = 0x00090020ull;


static const uint64_t P9N2_PEC_SPATTN_SCOM                                         = 0x0D040004ull;

static const uint64_t P9N2_PEC_SPATTN_SCOM1                                        = 0x0D040005ull;

static const uint64_t P9N2_PEC_SPATTN_SCOM2                                        = 0x0D040006ull;

static const uint64_t P9N2_PEC_0_SPATTN_SCOM                                       = 0x0D040004ull;

static const uint64_t P9N2_PEC_0_SPATTN_SCOM1                                      = 0x0D040005ull;

static const uint64_t P9N2_PEC_0_SPATTN_SCOM2                                      = 0x0D040006ull;

static const uint64_t P9N2_PEC_1_SPATTN_SCOM                                       = 0x0E040004ull;

static const uint64_t P9N2_PEC_1_SPATTN_SCOM1                                      = 0x0E040005ull;

static const uint64_t P9N2_PEC_1_SPATTN_SCOM2                                      = 0x0E040006ull;

static const uint64_t P9N2_PEC_2_SPATTN_SCOM                                       = 0x0F040004ull;

static const uint64_t P9N2_PEC_2_SPATTN_SCOM1                                      = 0x0F040005ull;

static const uint64_t P9N2_PEC_2_SPATTN_SCOM2                                      = 0x0F040006ull;


static const uint64_t P9N2_PEC_SPA_MASK                                            = 0x0D040007ull;

static const uint64_t P9N2_PEC_0_SPA_MASK                                          = 0x0D040007ull;

static const uint64_t P9N2_PEC_1_SPA_MASK                                          = 0x0E040007ull;

static const uint64_t P9N2_PEC_2_SPA_MASK                                          = 0x0F040007ull;


static const uint64_t P9N2_PU_SPIMPSS_ADC_CTRL_REG0                                = 0x00070000ull;


static const uint64_t P9N2_PU_SPIPSS_100NS_REG                                     = 0x00070028ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_CMD_REG                                   = 0x00070004ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_CTRL_REG1                                 = 0x00070001ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_CTRL_REG2                                 = 0x00070002ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_RDATA_REG0                                = 0x00070020ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_RDATA_REG1                                = 0x00070021ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_RDATA_REG2                                = 0x00070022ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_RDATA_REG3                                = 0x00070023ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_RESET_REGISTER                            = 0x00070005ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_STATUS_REG                                = 0x00070003ull;


static const uint64_t P9N2_PU_SPIPSS_ADC_WDATA_REG                                 = 0x00070010ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_COMMAND_REG                               = 0x00070044ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_CTRL_REG0                                 = 0x00070040ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_CTRL_REG1                                 = 0x00070041ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_CTRL_REG2                                 = 0x00070042ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_RDATA_REG                                 = 0x00070060ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_RESET_REGISTER                            = 0x00070045ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_STATUS_REG                                = 0x00070043ull;


static const uint64_t P9N2_PU_SPIPSS_P2S_WDATA_REG                                 = 0x00070050ull;


static const uint64_t P9N2_PU_SRAM_SRBV0_OCI                                       = 0xC0050020ull;

static const uint64_t P9N2_PU_SRAM_SRBV0_SCOM                                      = 0x0006A004ull;


static const uint64_t P9N2_PU_SRAM_SRBV1_OCI                                       = 0xC0050028ull;

static const uint64_t P9N2_PU_SRAM_SRBV1_SCOM                                      = 0x0006A005ull;


static const uint64_t P9N2_PU_SRAM_SRBV2_OCI                                       = 0xC0050030ull;

static const uint64_t P9N2_PU_SRAM_SRBV2_SCOM                                      = 0x0006A006ull;


static const uint64_t P9N2_PU_SRAM_SRBV3_OCI                                       = 0xC0050038ull;

static const uint64_t P9N2_PU_SRAM_SRBV3_SCOM                                      = 0x0006A007ull;


static const uint64_t P9N2_PU_SRAM_SRCHSW_OCI                                      = 0xC0050040ull;

static const uint64_t P9N2_PU_SRAM_SRCHSW_SCOM                                     = 0x0006A008ull;


static const uint64_t P9N2_PU_SRAM_SREAR_OCI                                       = 0xC0050018ull;

static const uint64_t P9N2_PU_SRAM_SREAR_SCOM                                      = 0x0006A003ull;


static const uint64_t P9N2_PU_SRAM_SRMAP_OCI                                       = 0xC0050010ull;

static const uint64_t P9N2_PU_SRAM_SRMAP_SCOM                                      = 0x0006A002ull;


static const uint64_t P9N2_PU_SRAM_SRMR_OCI                                        = 0xC0050008ull;

static const uint64_t P9N2_PU_SRAM_SRMR_SCOM                                       = 0x0006A001ull;


static const uint64_t P9N2_PU_STATUS_REGISTER                                      = 0x00010002ull;


static const uint64_t P9N2_PU_STATUS_REGISTER_B                                    = 0x000A0002ull;


static const uint64_t P9N2_PU_STATUS_REGISTER_C                                    = 0x000A1002ull;


static const uint64_t P9N2_PU_STATUS_REGISTER_D                                    = 0x000A2002ull;


static const uint64_t P9N2_PU_STATUS_REGISTER_E                                    = 0x000A3002ull;


static const uint64_t P9N2_PU_STATUS_REGISTER_ENGINE_B                             = 0x000A000Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_STATUS_REGISTER_ENGINE_C                             = 0x000A100Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_STATUS_REGISTER_ENGINE_D                             = 0x000A200Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PU_STATUS_REGISTER_ENGINE_E                             = 0x000A300Bull;
//WARNING - VALUE SET SAME AS ANOTHER REG

static const uint64_t P9N2_PEC_SUM_MASK_REG                                        = 0x0D040017ull;

static const uint64_t P9N2_PEC_0_SUM_MASK_REG                                      = 0x0D040017ull;

static const uint64_t P9N2_PEC_1_SUM_MASK_REG                                      = 0x0E040017ull;

static const uint64_t P9N2_PEC_2_SUM_MASK_REG                                      = 0x0F040017ull;


static const uint64_t P9N2_PU_SU_CH0_ABORT_CSB                                     = 0x02011043ull;


static const uint64_t P9N2_PU_SU_CH1_ABORT_CSB                                     = 0x02011045ull;


static const uint64_t P9N2_PU_SU_CH2_ABORT_CSB                                     = 0x02011047ull;


static const uint64_t P9N2_PU_SU_CH3_ABORT_CSB                                     = 0x02011049ull;


static const uint64_t P9N2_PU_SU_CH4_ABORT_CSB                                     = 0x0201104Bull;


static const uint64_t P9N2_PU_SU_CRB_KILL_REQ                                      = 0x02011053ull;


static const uint64_t P9N2_PU_SU_DMA_ERROR_REPORT_0                                = 0x02011057ull;


static const uint64_t P9N2_PU_SU_DMA_ERROR_REPORT_1                                = 0x02011058ull;


static const uint64_t P9N2_PU_SU_ENGINE_ENABLE                                     = 0x02011041ull;


static const uint64_t P9N2_PU_SU_ERAT_ERROR_RPT                                    = 0x020110D7ull;


static const uint64_t P9N2_PU_SU_INBOUND_WRITE_CONTROL                             = 0x02011042ull;


static const uint64_t P9N2_PU_SU_PERFMON_CONTROL_0                                 = 0x02011054ull;


static const uint64_t P9N2_PU_SU_PERFMON_CONTROL_1                                 = 0x02011055ull;


static const uint64_t P9N2_PU_SU_STATUS                                            = 0x02011040ull;


static const uint64_t P9N2_PU_SU_UMAC_ERROR_RPT                                    = 0x020110D3ull;


static const uint64_t P9N2_PU_SU_UMAC_ERROR_RPT1                                   = 0x020110D8ull;


static const uint64_t P9N2_PU_SYM_HI_PRIOR_RCV_FIFO_ASB                            = 0x020110C7ull;


static const uint64_t P9N2_PU_SYM_HI_PRIOR_RCV_FIFO_BAR                            = 0x020110C1ull;


static const uint64_t P9N2_PU_SYM_HI_PRIOR_RCV_FIFO_CNTL                           = 0x020110C4ull;


static const uint64_t P9N2_PU_SYM_LO_PRIOR_RCV_FIFO_ASB                            = 0x020110D0ull;


static const uint64_t P9N2_PU_SYM_LO_PRIOR_RCV_FIFO_BAR                            = 0x020110CAull;


static const uint64_t P9N2_PU_SYM_LO_PRIOR_RCV_FIFO_CNTL                           = 0x020110CDull;


static const uint64_t P9N2_PU_SYM_MAX_BYTE_CNT                                     = 0x0201105Aull;


static const uint64_t P9N2_PEC_SYNC_CONFIG                                         = 0x0D030000ull;

static const uint64_t P9N2_PEC_0_SYNC_CONFIG                                       = 0x0D030000ull;

static const uint64_t P9N2_PEC_1_SYNC_CONFIG                                       = 0x0E030000ull;

static const uint64_t P9N2_PEC_2_SYNC_CONFIG                                       = 0x0F030000ull;


static const uint64_t P9N2_PU_SYNC_FIR_ACTION0_REG                                 = 0x050129C6ull;


static const uint64_t P9N2_PU_SYNC_FIR_ACTION1_REG                                 = 0x050129C7ull;


static const uint64_t P9N2_PU_SYNC_FIR_MASK_REG                                    = 0x050129C3ull;

static const uint64_t P9N2_PU_SYNC_FIR_MASK_REG_AND                                = 0x050129C4ull;

static const uint64_t P9N2_PU_SYNC_FIR_MASK_REG_OR                                 = 0x050129C5ull;


static const uint64_t P9N2_PU_SYNC_FIR_REG                                         = 0x050129C0ull;

static const uint64_t P9N2_PU_SYNC_FIR_REG_AND                                     = 0x050129C1ull;

static const uint64_t P9N2_PU_SYNC_FIR_REG_OR                                      = 0x050129C2ull;


static const uint64_t P9N2_PU_SYNC_FIR_WOF_REG                                     = 0x050129C8ull;


static const uint64_t P9N2__SM1_TCE_KILL                                           = 0x05011624ull;


static const uint64_t P9N2__SM2_TEST_CERR                                          = 0x05011641ull;


static const uint64_t P9N2_CAPP_TFMR                                               = 0x02010827ull;

static const uint64_t P9N2_CAPP_0_TFMR                                             = 0x02010827ull;

static const uint64_t P9N2_CAPP_1_TFMR                                             = 0x04010827ull;


static const uint64_t P9N2_PEC_THERM_MODE_REG                                      = 0x0D05000Full;

static const uint64_t P9N2_PEC_0_THERM_MODE_REG                                    = 0x0D05000Full;

static const uint64_t P9N2_PEC_1_THERM_MODE_REG                                    = 0x0E05000Full;

static const uint64_t P9N2_PEC_2_THERM_MODE_REG                                    = 0x0F05000Full;


static const uint64_t P9N2_PEC_TIMEOUT_REG                                         = 0x0D0F0010ull;

static const uint64_t P9N2_PEC_0_TIMEOUT_REG                                       = 0x0D0F0010ull;

static const uint64_t P9N2_PEC_1_TIMEOUT_REG                                       = 0x0E0F0010ull;

static const uint64_t P9N2_PEC_2_TIMEOUT_REG                                       = 0x0F0F0010ull;


static const uint64_t P9N2_PEC_TIMESTAMP_COUNTER_READ                              = 0x0D05001Cull;

static const uint64_t P9N2_PEC_0_TIMESTAMP_COUNTER_READ                            = 0x0D05001Cull;

static const uint64_t P9N2_PEC_1_TIMESTAMP_COUNTER_READ                            = 0x0E05001Cull;

static const uint64_t P9N2_PEC_2_TIMESTAMP_COUNTER_READ                            = 0x0F05001Cull;


static const uint64_t P9N2_CAPP_TLBI_ERROR_REPORT                                  = 0x0201080Dull;

static const uint64_t P9N2_CAPP_0_TLBI_ERROR_REPORT                                = 0x0201080Dull;

static const uint64_t P9N2_CAPP_1_TLBI_ERROR_REPORT                                = 0x0401080Dull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG0                                   = 0x02010870ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG0                                 = 0x02010870ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG0                                 = 0x04010870ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG1                                   = 0x02010871ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG1                                 = 0x02010871ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG1                                 = 0x04010871ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG10                                  = 0x0201087Aull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG10                                = 0x0201087Aull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG10                                = 0x0401087Aull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG11                                  = 0x0201087Bull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG11                                = 0x0201087Bull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG11                                = 0x0401087Bull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG12                                  = 0x0201087Cull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG12                                = 0x0201087Cull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG12                                = 0x0401087Cull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG13                                  = 0x0201087Dull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG13                                = 0x0201087Dull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG13                                = 0x0401087Dull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG14                                  = 0x0201087Eull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG14                                = 0x0201087Eull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG14                                = 0x0401087Eull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG15                                  = 0x0201087Full;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG15                                = 0x0201087Full;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG15                                = 0x0401087Full;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG2                                   = 0x02010872ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG2                                 = 0x02010872ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG2                                 = 0x04010872ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG3                                   = 0x02010873ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG3                                 = 0x02010873ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG3                                 = 0x04010873ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG4                                   = 0x02010874ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG4                                 = 0x02010874ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG4                                 = 0x04010874ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG5                                   = 0x02010875ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG5                                 = 0x02010875ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG5                                 = 0x04010875ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG6                                   = 0x02010876ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG6                                 = 0x02010876ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG6                                 = 0x04010876ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG7                                   = 0x02010877ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG7                                 = 0x02010877ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG7                                 = 0x04010877ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG8                                   = 0x02010878ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG8                                 = 0x02010878ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG8                                 = 0x04010878ull;


static const uint64_t P9N2_CAPP_TLBI_FILTER_REG9                                   = 0x02010879ull;

static const uint64_t P9N2_CAPP_0_TLBI_FILTER_REG9                                 = 0x02010879ull;

static const uint64_t P9N2_CAPP_1_TLBI_FILTER_REG9                                 = 0x04010879ull;


static const uint64_t P9N2_CAPP_TLBI_QOS                                           = 0x0201084Cull;

static const uint64_t P9N2_CAPP_0_TLBI_QOS                                         = 0x0201084Cull;

static const uint64_t P9N2_CAPP_1_TLBI_QOS                                         = 0x0401084Cull;


static const uint64_t P9N2_PU_NPU_CTL_TLX_CREDIT_STATUS                            = 0x05011391ull;

static const uint64_t P9N2_PU_NPU_SM3_TLX_CREDIT_STATUS                            = 0x05011361ull;

static const uint64_t P9N2__CTL_TLX_CREDIT_STATUS                                  = 0x05011591ull;

static const uint64_t P9N2__SM3_TLX_CREDIT_STATUS                                  = 0x05011561ull;


static const uint64_t P9N2_PU_NPU_CTL_TL_DCP_CREDIT_STATUS                         = 0x05011393ull;

static const uint64_t P9N2_PU_NPU_SM3_TL_DCP_CREDIT_STATUS                         = 0x05011363ull;

static const uint64_t P9N2__CTL_TL_DCP_CREDIT_STATUS                               = 0x05011593ull;

static const uint64_t P9N2__SM3_TL_DCP_CREDIT_STATUS                               = 0x05011563ull;


static const uint64_t P9N2_PU_NPU_CTL_TL_VC_CREDIT_STATUS                          = 0x05011392ull;

static const uint64_t P9N2_PU_NPU_SM3_TL_VC_CREDIT_STATUS                          = 0x05011362ull;

static const uint64_t P9N2__CTL_TL_VC_CREDIT_STATUS                                = 0x05011592ull;

static const uint64_t P9N2__SM3_TL_VC_CREDIT_STATUS                                = 0x05011562ull;


static const uint64_t P9N2_PU_TOD_CMD_REG                                          = 0x0009002Aull;


static const uint64_t P9N2_PU_TOD_DATA_RCV_REG                                     = 0x00090029ull;


static const uint64_t P9N2_PU_TOD_DATA_SND_REG                                     = 0x00090028ull;


static const uint64_t P9N2_CAPP_TOD_SYNC000                                        = 0x02010826ull;

static const uint64_t P9N2_CAPP_0_TOD_SYNC000                                      = 0x02010826ull;

static const uint64_t P9N2_CAPP_1_TOD_SYNC000                                      = 0x04010826ull;


static const uint64_t P9N2_PU_TRACE_HI_DATA_REG                                    = 0x07010C40ull;
//DUPS: 02010400, 02010480, 07010C40, 07010C00, 05010440, 05010400, 050104C0, 05010480, 05010540, 05010500, 050105C0, 05010580, 05010600, 050106C0, 05010680, 08010C40, 08010C00, 03010440, 03010400, 030104C0, 03010480, 03010540, 03010500, 030105C0, 03010580, 03010640, 03010600, 04010440, 04010400,

static const uint64_t P9N2_PEC_TRACE_HI_DATA_REG                                   = 0x0D010400ull;

static const uint64_t P9N2_PEC_0_TRACE_HI_DATA_REG                                 = 0x0D010400ull;

static const uint64_t P9N2_PEC_1_TRACE_HI_DATA_REG                                 = 0x0E010400ull;

static const uint64_t P9N2_PEC_2_TRACE_HI_DATA_REG                                 = 0x0F010400ull;


static const uint64_t P9N2_PU_TRACE_LO_DATA_REG                                    = 0x07010C41ull;
//DUPS: 02010401, 02010481, 07010C41, 07010C01, 05010441, 05010401, 050104C1, 05010481, 05010541, 05010501, 050105C1, 05010581, 05010601, 050106C1, 05010681, 08010C41, 08010C01, 03010441, 03010401, 030104C1, 03010481, 03010541, 03010501, 030105C1, 03010581, 03010641, 03010601, 04010441, 04010401,

static const uint64_t P9N2_PEC_TRACE_LO_DATA_REG                                   = 0x0D010401ull;

static const uint64_t P9N2_PEC_0_TRACE_LO_DATA_REG                                 = 0x0D010401ull;

static const uint64_t P9N2_PEC_1_TRACE_LO_DATA_REG                                 = 0x0E010401ull;

static const uint64_t P9N2_PEC_2_TRACE_LO_DATA_REG                                 = 0x0F010401ull;


static const uint64_t P9N2_PU_TRACE_TRCTRL_CONFIG                                  = 0x07010C42ull;
//DUPS: 02010402, 02010482, 07010C42, 07010C02, 05010442, 05010402, 050104C2, 05010482, 05010542, 05010502, 050105C2, 05010582, 05010602, 050106C2, 05010682, 08010C42, 08010C02, 03010442, 03010402, 030104C2, 03010482, 03010542, 03010502, 030105C2, 03010582, 03010642, 03010602, 04010442, 04010402,

static const uint64_t P9N2_PEC_TRACE_TRCTRL_CONFIG                                 = 0x0D010402ull;

static const uint64_t P9N2_PEC_0_TRACE_TRCTRL_CONFIG                               = 0x0D010402ull;

static const uint64_t P9N2_PEC_1_TRACE_TRCTRL_CONFIG                               = 0x0E010402ull;

static const uint64_t P9N2_PEC_2_TRACE_TRCTRL_CONFIG                               = 0x0F010402ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_0                                = 0x07010C43ull;
//DUPS: 02010403, 02010483, 07010C43, 07010C03, 05010443, 05010403, 050104C3, 05010483, 05010543, 05010503, 050105C3, 05010583, 05010603, 050106C3, 05010683, 08010C43, 08010C03, 03010443, 03010403, 030104C3, 03010483, 03010543, 03010503, 030105C3, 03010583, 03010643, 03010603, 04010443, 04010403,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_0                               = 0x0D010403ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_0                             = 0x0D010403ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_0                             = 0x0E010403ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_0                             = 0x0F010403ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_1                                = 0x07010C44ull;
//DUPS: 02010404, 02010484, 07010C44, 07010C04, 05010444, 05010404, 050104C4, 05010484, 05010544, 05010504, 050105C4, 05010584, 05010604, 050106C4, 05010684, 08010C44, 08010C04, 03010444, 03010404, 030104C4, 03010484, 03010544, 03010504, 030105C4, 03010584, 03010644, 03010604, 04010444, 04010404,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_1                               = 0x0D010404ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_1                             = 0x0D010404ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_1                             = 0x0E010404ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_1                             = 0x0F010404ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_2                                = 0x07010C45ull;
//DUPS: 02010405, 02010485, 07010C45, 07010C05, 05010445, 05010405, 050104C5, 05010485, 05010545, 05010505, 050105C5, 05010585, 05010605, 050106C5, 05010685, 08010C45, 08010C05, 03010445, 03010405, 030104C5, 03010485, 03010545, 03010505, 030105C5, 03010585, 03010645, 03010605, 04010445, 04010405,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_2                               = 0x0D010405ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_2                             = 0x0D010405ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_2                             = 0x0E010405ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_2                             = 0x0F010405ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_3                                = 0x07010C46ull;
//DUPS: 02010406, 02010486, 07010C46, 07010C06, 05010446, 05010406, 050104C6, 05010486, 05010546, 05010506, 050105C6, 05010586, 05010606, 050106C6, 05010686, 08010C46, 08010C06, 03010446, 03010406, 030104C6, 03010486, 03010546, 03010506, 030105C6, 03010586, 03010646, 03010606, 04010446, 04010406,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_3                               = 0x0D010406ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_3                             = 0x0D010406ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_3                             = 0x0E010406ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_3                             = 0x0F010406ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_4                                = 0x07010C47ull;
//DUPS: 02010407, 02010487, 07010C47, 07010C07, 05010447, 05010407, 050104C7, 05010487, 05010547, 05010507, 050105C7, 05010587, 05010607, 050106C7, 05010687, 08010C47, 08010C07, 03010447, 03010407, 030104C7, 03010487, 03010547, 03010507, 030105C7, 03010587, 03010647, 03010607, 04010447, 04010407,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_4                               = 0x0D010407ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_4                             = 0x0D010407ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_4                             = 0x0E010407ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_4                             = 0x0F010407ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_5                                = 0x07010C48ull;
//DUPS: 02010408, 02010488, 07010C48, 07010C08, 05010448, 05010408, 050104C8, 05010488, 05010548, 05010508, 050105C8, 05010588, 05010608, 050106C8, 05010688, 08010C48, 08010C08, 03010448, 03010408, 030104C8, 03010488, 03010548, 03010508, 030105C8, 03010588, 03010648, 03010608, 04010448, 04010408,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_5                               = 0x0D010408ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_5                             = 0x0D010408ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_5                             = 0x0E010408ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_5                             = 0x0F010408ull;


static const uint64_t P9N2_PU_TRACE_TRDATA_CONFIG_9                                = 0x07010C49ull;
//DUPS: 02010409, 02010489, 07010C49, 07010C09, 05010449, 05010409, 050104C9, 05010489, 05010549, 05010509, 050105C9, 05010589, 05010609, 050106C9, 05010689, 08010C49, 08010C09, 03010449, 03010409, 030104C9, 03010489, 03010549, 03010509, 030105C9, 03010589, 03010649, 03010609, 04010449, 04010409,

static const uint64_t P9N2_PEC_TRACE_TRDATA_CONFIG_9                               = 0x0D010409ull;

static const uint64_t P9N2_PEC_0_TRACE_TRDATA_CONFIG_9                             = 0x0D010409ull;

static const uint64_t P9N2_PEC_1_TRACE_TRDATA_CONFIG_9                             = 0x0E010409ull;

static const uint64_t P9N2_PEC_2_TRACE_TRDATA_CONFIG_9                             = 0x0F010409ull;


static const uint64_t P9N2_PU_TRUST_CONTROL                                        = 0x05012B45ull;


static const uint64_t P9N2_PEC_0_STACK0_TUNNEL_BAR_REG                             = 0x04010C56ull;

static const uint64_t P9N2_PEC_1_STACK0_TUNNEL_BAR_REG                             = 0x04011056ull;

static const uint64_t P9N2_PEC_1_STACK1_TUNNEL_BAR_REG                             = 0x04011096ull;

static const uint64_t P9N2_PEC_1_STACK2_TUNNEL_BAR_REG                             = 0x040110D6ull;

static const uint64_t P9N2_PEC_2_STACK0_TUNNEL_BAR_REG                             = 0x04011456ull;

static const uint64_t P9N2_PEC_2_STACK1_TUNNEL_BAR_REG                             = 0x04011496ull;

static const uint64_t P9N2_PEC_2_STACK2_TUNNEL_BAR_REG                             = 0x040114D6ull;

static const uint64_t P9N2_PEC_STACK0_TUNNEL_BAR_REG                               = 0x04010C56ull;

static const uint64_t P9N2_PHB_TUNNEL_BAR_REG                                      = 0x04010C56ull;

static const uint64_t P9N2_PHB_0_TUNNEL_BAR_REG                                    = 0x04010C56ull;

static const uint64_t P9N2_PHB_1_TUNNEL_BAR_REG                                    = 0x04011056ull;

static const uint64_t P9N2_PHB_2_TUNNEL_BAR_REG                                    = 0x04011096ull;

static const uint64_t P9N2_PHB_3_TUNNEL_BAR_REG                                    = 0x04011456ull;

static const uint64_t P9N2_PHB_4_TUNNEL_BAR_REG                                    = 0x04011496ull;

static const uint64_t P9N2_PHB_5_TUNNEL_BAR_REG                                    = 0x040114D6ull;


static const uint64_t P9N2_PU_NPU_CTL_TXI_ERR_INJ                                  = 0x05011395ull;

static const uint64_t P9N2_PU_NPU_SM3_TXI_ERR_INJ                                  = 0x05011365ull;

static const uint64_t P9N2__CTL_TXI_ERR_INJ                                        = 0x05011595ull;

static const uint64_t P9N2__SM3_TXI_ERR_INJ                                        = 0x05011565ull;


static const uint64_t P9N2_PU_TX_CH_FSM_REG                                        = 0x05012805ull;


static const uint64_t P9N2_PU_TX_CH_INTADDR_REG                                    = 0x05012810ull;


static const uint64_t P9N2_PU_TX_CH_MISC_REG                                       = 0x05012813ull;


static const uint64_t P9N2_PU_TX_CTRL_STAT_REG                                     = 0x05012800ull;


static const uint64_t P9N2_PU_TX_DBFF_REG0                                         = 0x05012811ull;


static const uint64_t P9N2_PU_TX_DBFF_REG1                                         = 0x05012812ull;


static const uint64_t P9N2_PU_TX_DF_FSM_REG                                        = 0x05012806ull;


static const uint64_t P9N2_PU_NPU_CTL_TX_DL_CREDIT_STATUS                          = 0x05011394ull;

static const uint64_t P9N2_PU_NPU_SM3_TX_DL_CREDIT_STATUS                          = 0x05011364ull;

static const uint64_t P9N2__CTL_TX_DL_CREDIT_STATUS                                = 0x05011594ull;

static const uint64_t P9N2__SM3_TX_DL_CREDIT_STATUS                                = 0x05011564ull;


static const uint64_t P9N2_PU_TX_ERROR_REG_WCLEAR                                  = 0x05012802ull;

static const uint64_t P9N2_PU_TX_ERROR_REG_OR                                      = 0x05012804ull;


static const uint64_t P9N2_PU_TX_ERR_MODE                                          = 0x05012807ull;


static const uint64_t P9N2_PU_TX_MASK_REG                                          = 0x05012803ull;


static const uint64_t P9N2_PU_TX_PSI_CNTL                                          = 0x04011830ull;


static const uint64_t P9N2_PU_TX_PSI_MODE                                          = 0x04011831ull;


static const uint64_t P9N2_PU_TX_PSI_STATUS                                        = 0x04011832ull;


static const uint64_t P9N2_PU_TX_TO_RT_REG                                         = 0x05012801ull;


static const uint64_t P9N2_PU_UMAC_STATUS_CONTROL                                  = 0x020110D5ull;


static const uint64_t P9N2_PU_VAS_BUFCTL                                           = 0x0301180Cull;


static const uint64_t P9N2_PU_VAS_CAMDATA0                                         = 0x03011834ull;


static const uint64_t P9N2_PU_VAS_CAMDATA1                                         = 0x03011835ull;


static const uint64_t P9N2_PU_VAS_CAMDISPCNTL                                      = 0x03011833ull;


static const uint64_t P9N2_PU_VAS_CQERRRPT                                         = 0x03011848ull;


static const uint64_t P9N2_PU_VAS_DBGCONT                                          = 0x0301182Eull;


static const uint64_t P9N2_PU_VAS_DBGNORTH                                         = 0x0301182Dull;


static const uint64_t P9N2_PU_VAS_DBGSOUTH                                         = 0x0301184Cull;


static const uint64_t P9N2_PU_VAS_DBGTRIG                                          = 0x0301182Full;


static const uint64_t P9N2_PU_VAS_EGERRRPT                                         = 0x0301184Aull;


static const uint64_t P9N2_PU_VAS_ERRINJNO                                         = 0x03011832ull;


static const uint64_t P9N2_PU_VAS_ERRINJSO                                         = 0x0301184Bull;


static const uint64_t P9N2_PU_VAS_FIR_ACTION0_REG                                  = 0x03011806ull;


static const uint64_t P9N2_PU_VAS_FIR_ACTION1_REG                                  = 0x03011807ull;


static const uint64_t P9N2_PU_VAS_FIR_MASK_REG                                     = 0x03011803ull;

static const uint64_t P9N2_PU_VAS_FIR_MASK_REG_AND                                 = 0x03011804ull;

static const uint64_t P9N2_PU_VAS_FIR_MASK_REG_OR                                  = 0x03011805ull;


static const uint64_t P9N2_PU_VAS_FIR_REG                                          = 0x03011800ull;

static const uint64_t P9N2_PU_VAS_FIR_REG_AND                                      = 0x03011801ull;

static const uint64_t P9N2_PU_VAS_FIR_REG_OR                                       = 0x03011802ull;


static const uint64_t P9N2_PU_VAS_FIR_WOF_REG                                      = 0x03011808ull;


static const uint64_t P9N2_PU_VAS_INERRRPT                                         = 0x0301182Bull;


static const uint64_t P9N2_PU_VAS_MISCCTL                                          = 0x0301180Dull;


static const uint64_t P9N2_PU_VAS_MMIOCTL                                          = 0x03011829ull;


static const uint64_t P9N2_PU_VAS_MMIODATA                                         = 0x0301182Aull;


static const uint64_t P9N2_PU_VAS_MMIOECC                                          = 0x03011831ull;


static const uint64_t P9N2_PU_VAS_MMIO_BASE_ADDR                                   = 0x020110D4ull;


static const uint64_t P9N2_PU_VAS_PBCFG0                                           = 0x0301184Dull;


static const uint64_t P9N2_PU_VAS_PBCFG1                                           = 0x0301184Eull;


static const uint64_t P9N2_PU_VAS_PGMIG1                                           = 0x03011841ull;


static const uint64_t P9N2_PU_VAS_PGMIG2                                           = 0x03011842ull;


static const uint64_t P9N2_PU_VAS_PGMIG3                                           = 0x03011843ull;


static const uint64_t P9N2_PU_VAS_PGMIG4                                           = 0x03011844ull;


static const uint64_t P9N2_PU_VAS_PGMIG5                                           = 0x03011845ull;


static const uint64_t P9N2_PU_VAS_PGMIG6                                           = 0x03011846ull;


static const uint64_t P9N2_PU_VAS_PGMIG7                                           = 0x03011847ull;


static const uint64_t P9N2_PU_VAS_PMCNTL                                           = 0x03011830ull;


static const uint64_t P9N2_PU_VAS_RESERVE                                          = 0x03011828ull;


static const uint64_t P9N2_PU_VAS_RGERRRPT                                         = 0x0301182Cull;


static const uint64_t P9N2_PU_VAS_RMABAR                                           = 0x0301180Eull;


static const uint64_t P9N2_PU_VAS_RMABARM                                          = 0x0301180Full;


static const uint64_t P9N2_PU_VAS_SOUTHCTL                                         = 0x0301184Full;


static const uint64_t P9N2_PU_VAS_UWMBAR                                           = 0x0301180Bull;


static const uint64_t P9N2_PU_VAS_WCBSBAR                                          = 0x03011840ull;


static const uint64_t P9N2_PU_VAS_WCERRRPT                                         = 0x03011849ull;


static const uint64_t P9N2_PU_VAS_WCMBAR                                           = 0x0301180Aull;


static const uint64_t P9N2_PU_VAS_WRMON0BAR                                        = 0x03011810ull;


static const uint64_t P9N2_PU_VAS_WRMON0CMP                                        = 0x03011820ull;


static const uint64_t P9N2_PU_VAS_WRMON0WID                                        = 0x03011818ull;


static const uint64_t P9N2_PU_VAS_WRMON1BAR                                        = 0x03011811ull;


static const uint64_t P9N2_PU_VAS_WRMON1CMP                                        = 0x03011821ull;


static const uint64_t P9N2_PU_VAS_WRMON1WID                                        = 0x03011819ull;


static const uint64_t P9N2_PU_VAS_WRMON2BAR                                        = 0x03011812ull;


static const uint64_t P9N2_PU_VAS_WRMON2CMP                                        = 0x03011822ull;


static const uint64_t P9N2_PU_VAS_WRMON2WID                                        = 0x0301181Aull;


static const uint64_t P9N2_PU_VAS_WRMON3BAR                                        = 0x03011813ull;


static const uint64_t P9N2_PU_VAS_WRMON3CMP                                        = 0x03011823ull;


static const uint64_t P9N2_PU_VAS_WRMON3WID                                        = 0x0301181Bull;


static const uint64_t P9N2_PU_VAS_WRMON4BAR                                        = 0x03011814ull;


static const uint64_t P9N2_PU_VAS_WRMON4CMP                                        = 0x03011824ull;


static const uint64_t P9N2_PU_VAS_WRMON4WID                                        = 0x0301181Cull;


static const uint64_t P9N2_PU_VAS_WRMON5BAR                                        = 0x03011815ull;


static const uint64_t P9N2_PU_VAS_WRMON5CMP                                        = 0x03011825ull;


static const uint64_t P9N2_PU_VAS_WRMON5WID                                        = 0x0301181Dull;


static const uint64_t P9N2_PU_VAS_WRMON6BAR                                        = 0x03011816ull;


static const uint64_t P9N2_PU_VAS_WRMON6CMP                                        = 0x03011826ull;


static const uint64_t P9N2_PU_VAS_WRMON6WID                                        = 0x0301181Eull;


static const uint64_t P9N2_PU_VAS_WRMON7BAR                                        = 0x03011817ull;


static const uint64_t P9N2_PU_VAS_WRMON7CMP                                        = 0x03011827ull;


static const uint64_t P9N2_PU_VAS_WRMON7WID                                        = 0x0301181Full;


static const uint64_t P9N2_PEC_VITAL_SCAN_OUT                                      = 0x0D0F0017ull;

static const uint64_t P9N2_PEC_0_VITAL_SCAN_OUT                                    = 0x0D0F0017ull;

static const uint64_t P9N2_PEC_1_VITAL_SCAN_OUT                                    = 0x0E0F0017ull;

static const uint64_t P9N2_PEC_2_VITAL_SCAN_OUT                                    = 0x0F0F0017ull;


static const uint64_t P9N2_PU_WATCHDOG_HANG_TIMERS_CNTL                            = 0x0201105Cull;


static const uint64_t P9N2_PU_WATER_MARK_REGISTER_B                                = 0x000A0007ull;


static const uint64_t P9N2_PU_WATER_MARK_REGISTER_C                                = 0x000A1007ull;


static const uint64_t P9N2_PU_WATER_MARK_REGISTER_D                                = 0x000A2007ull;


static const uint64_t P9N2_PU_WATER_MARK_REGISTER_E                                = 0x000A3007ull;


static const uint64_t P9N2_PHB_WOF_REG                                             = 0x0D010910ull;

static const uint64_t P9N2_PHB_0_WOF_REG                                           = 0x0D010910ull;

static const uint64_t P9N2_PHB_1_WOF_REG                                           = 0x0E010910ull;

static const uint64_t P9N2_PHB_2_WOF_REG                                           = 0x0E010950ull;

static const uint64_t P9N2_PHB_3_WOF_REG                                           = 0x0F010910ull;

static const uint64_t P9N2_PHB_4_WOF_REG                                           = 0x0F010950ull;

static const uint64_t P9N2_PHB_5_WOF_REG                                           = 0x0F010990ull;


static const uint64_t P9N2_PU_WRITE_PROTECT_ENABLE_REG                             = 0x06010005ull;


static const uint64_t P9N2_PEC_WRITE_PROTECT_ENABLE_REG                            = 0x0D010005ull;

static const uint64_t P9N2_PEC_0_WRITE_PROTECT_ENABLE_REG                          = 0x0D010005ull;

static const uint64_t P9N2_PEC_1_WRITE_PROTECT_ENABLE_REG                          = 0x0E010005ull;

static const uint64_t P9N2_PEC_2_WRITE_PROTECT_ENABLE_REG                          = 0x0F010005ull;


static const uint64_t P9N2_PU_N0_WRITE_PROTECT_ENABLE_REG                          = 0x02010005ull;

static const uint64_t P9N2_PU_N1_WRITE_PROTECT_ENABLE_REG                          = 0x03010005ull;

static const uint64_t P9N2_PU_N2_WRITE_PROTECT_ENABLE_REG                          = 0x04010005ull;

static const uint64_t P9N2_PU_N3_WRITE_PROTECT_ENABLE_REG                          = 0x05010005ull;


static const uint64_t P9N2_PU_WRITE_PROTECT_RINGS_REG                              = 0x06010006ull;


static const uint64_t P9N2_PEC_WRITE_PROTECT_RINGS_REG                             = 0x0D010006ull;

static const uint64_t P9N2_PEC_0_WRITE_PROTECT_RINGS_REG                           = 0x0D010006ull;

static const uint64_t P9N2_PEC_1_WRITE_PROTECT_RINGS_REG                           = 0x0E010006ull;

static const uint64_t P9N2_PEC_2_WRITE_PROTECT_RINGS_REG                           = 0x0F010006ull;


static const uint64_t P9N2_PU_N0_WRITE_PROTECT_RINGS_REG                           = 0x02010006ull;

static const uint64_t P9N2_PU_N1_WRITE_PROTECT_RINGS_REG                           = 0x03010006ull;

static const uint64_t P9N2_PU_N2_WRITE_PROTECT_RINGS_REG                           = 0x04010006ull;

static const uint64_t P9N2_PU_N3_WRITE_PROTECT_RINGS_REG                           = 0x05010006ull;


static const uint64_t P9N2_PEC_XFIR                                                = 0x0D040000ull;

static const uint64_t P9N2_PEC_0_XFIR                                              = 0x0D040000ull;

static const uint64_t P9N2_PEC_1_XFIR                                              = 0x0E040000ull;

static const uint64_t P9N2_PEC_2_XFIR                                              = 0x0F040000ull;


static const uint64_t P9N2_CAPP_XPT_CONTROL                                        = 0x0201081Cull;

static const uint64_t P9N2_CAPP_0_XPT_CONTROL                                      = 0x0201081Cull;

static const uint64_t P9N2_CAPP_1_XPT_CONTROL                                      = 0x0401081Cull;


static const uint64_t P9N2_CAPP_XPT_ERROR_REPORT                                   = 0x0201080Cull;

static const uint64_t P9N2_CAPP_0_XPT_ERROR_REPORT                                 = 0x0201080Cull;

static const uint64_t P9N2_CAPP_1_XPT_ERROR_REPORT                                 = 0x0401080Cull;


static const uint64_t P9N2_CAPP_XPT_PMU_EVENTS_SEL                                 = 0x02010822ull;

static const uint64_t P9N2_CAPP_0_XPT_PMU_EVENTS_SEL                               = 0x02010822ull;

static const uint64_t P9N2_CAPP_1_XPT_PMU_EVENTS_SEL                               = 0x04010822ull;


static const uint64_t P9N2_PU_XSCOM_BASE_REG                                       = 0x00090010ull;


static const uint64_t P9N2_PU_XSCOM_DAT0_REG                                       = 0x0009001Eull;


static const uint64_t P9N2_PU_XSCOM_DAT1_REG                                       = 0x0009001Full;


static const uint64_t P9N2_PU_XSCOM_ERR_REG                                        = 0x00090013ull;


static const uint64_t P9N2_PU_XSCOM_LOG_REG                                        = 0x00090012ull;


static const uint64_t P9N2_PU_XSCOM_MODE_REG                                       = 0x00090011ull;


static const uint64_t P9N2_PU_XSCOM_RCVED_STAT_REG                                 = 0x00090018ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_ATD                                      = 0x050113BAull;

static const uint64_t P9N2__DAT_XSL_ATD                                            = 0x050115BAull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_DBG_WR                                   = 0x050113B6ull;

static const uint64_t P9N2__DAT_XSL_DBG_WR                                         = 0x050115B6ull;


static const uint64_t P9N2_PU_NPU_NTL0_XSL_DEBUG0_CONFIG                           = 0x050113C4ull;

static const uint64_t P9N2__NTL0_XSL_DEBUG0_CONFIG                                 = 0x050115C4ull;


static const uint64_t P9N2_PU_NPU_NTL0_XSL_DEBUG1_CONFIG                           = 0x050113C5ull;

static const uint64_t P9N2__NTL0_XSL_DEBUG1_CONFIG                                 = 0x050115C5ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_DEF                                      = 0x050113B8ull;

static const uint64_t P9N2__DAT_XSL_DEF                                            = 0x050115B8ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_EEI                                      = 0x050113B7ull;

static const uint64_t P9N2__DAT_XSL_EEI                                            = 0x050115B7ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_FEC                                      = 0x050113B9ull;

static const uint64_t P9N2__DAT_XSL_FEC                                            = 0x050115B9ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_GP                                       = 0x050113BBull;

static const uint64_t P9N2__DAT_XSL_GP                                             = 0x050115BBull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_INV_ERAT_WR                              = 0x050113BCull;

static const uint64_t P9N2__DAT_XSL_INV_ERAT_WR                                    = 0x050115BCull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_INV_LPP                                  = 0x050113BDull;

static const uint64_t P9N2__DAT_XSL_INV_LPP                                        = 0x050115BDull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_PMON                                     = 0x050113B5ull;

static const uint64_t P9N2__DAT_XSL_PMON                                           = 0x050115B5ull;


static const uint64_t P9N2_PU_NPU_DAT_XSL_RECOVER                                  = 0x050113B4ull;

static const uint64_t P9N2__DAT_XSL_RECOVER                                        = 0x050115B4ull;


static const uint64_t P9N2_PU_NPU_NTL0_XSL_WRAP_CFG                                = 0x050113C8ull;

static const uint64_t P9N2__NTL0_XSL_WRAP_CFG                                      = 0x050115C8ull;


static const uint64_t P9N2_PU_NPU_NTL0_XSL_WRAP_ERROR                              = 0x050113C6ull;

static const uint64_t P9N2__NTL0_XSL_WRAP_ERROR                                    = 0x050115C6ull;


static const uint64_t P9N2_PU_NPU_NTL0_XSL_WRAP_ERR_MASK                           = 0x050113C7ull;

static const uint64_t P9N2__NTL0_XSL_WRAP_ERR_MASK                                 = 0x050115C7ull;


static const uint64_t P9N2_PEC_XSTOP1                                              = 0x0D03000Cull;

static const uint64_t P9N2_PEC_0_XSTOP1                                            = 0x0D03000Cull;

static const uint64_t P9N2_PEC_1_XSTOP1                                            = 0x0E03000Cull;

static const uint64_t P9N2_PEC_2_XSTOP1                                            = 0x0F03000Cull;


static const uint64_t P9N2_PEC_XSTOP2                                              = 0x0D03000Dull;

static const uint64_t P9N2_PEC_0_XSTOP2                                            = 0x0D03000Dull;

static const uint64_t P9N2_PEC_1_XSTOP2                                            = 0x0E03000Dull;

static const uint64_t P9N2_PEC_2_XSTOP2                                            = 0x0F03000Dull;


static const uint64_t P9N2_PEC_XSTOP3                                              = 0x0D03000Eull;

static const uint64_t P9N2_PEC_0_XSTOP3                                            = 0x0D03000Eull;

static const uint64_t P9N2_PEC_1_XSTOP3                                            = 0x0E03000Eull;

static const uint64_t P9N2_PEC_2_XSTOP3                                            = 0x0F03000Eull;


static const uint64_t P9N2_PEC_XSTOP_INTERRUPT_REG                                 = 0x0D0F001Cull;

static const uint64_t P9N2_PEC_0_XSTOP_INTERRUPT_REG                               = 0x0D0F001Cull;

static const uint64_t P9N2_PEC_1_XSTOP_INTERRUPT_REG                               = 0x0E0F001Cull;

static const uint64_t P9N2_PEC_2_XSTOP_INTERRUPT_REG                               = 0x0F0F001Cull;


static const uint64_t P9N2_PU_NPU0_CTL_XTIMER_CONFIG                               = 0x05011093ull;

static const uint64_t P9N2_PU_NPU2_CTL_XTIMER_CONFIG                               = 0x05011293ull;

static const uint64_t P9N2_PU_NPU0_SM0_XTIMER_CONFIG                               = 0x05011003ull;

static const uint64_t P9N2_PU_NPU0_SM1_XTIMER_CONFIG                               = 0x05011033ull;

static const uint64_t P9N2_PU_NPU0_SM3_XTIMER_CONFIG                               = 0x05011063ull;

static const uint64_t P9N2_PU_NPU2_SM0_XTIMER_CONFIG                               = 0x05011203ull;

static const uint64_t P9N2_PU_NPU2_SM1_XTIMER_CONFIG                               = 0x05011233ull;

static const uint64_t P9N2_PU_NPU2_SM3_XTIMER_CONFIG                               = 0x05011263ull;

static const uint64_t P9N2_PU_NPU_MSC_CTL_XTIMER_CONFIG                            = 0x05011493ull;

static const uint64_t P9N2_PU_NPU_MSC_SM0_XTIMER_CONFIG                            = 0x05011403ull;

static const uint64_t P9N2_PU_NPU_MSC_SM1_XTIMER_CONFIG                            = 0x05011433ull;

static const uint64_t P9N2_PU_NPU_MSC_SM3_XTIMER_CONFIG                            = 0x05011463ull;


static const uint64_t P9N2_PU_XTRA_TRACE_MODE                                      = 0x020107D1ull;
//DUPS: 050107D1, 030107D1, 040107D1,

static const uint64_t P9N2_PEC_XTRA_TRACE_MODE                                     = 0x0D0107D1ull;

static const uint64_t P9N2_PEC_0_XTRA_TRACE_MODE                                   = 0x0D0107D1ull;

static const uint64_t P9N2_PEC_1_XTRA_TRACE_MODE                                   = 0x0E0107D1ull;

static const uint64_t P9N2_PEC_2_XTRA_TRACE_MODE                                   = 0x0F0107D1ull;


static const uint64_t P9N2__SM2_XTS_ATRMISS                                        = 0x0501164Aull;


static const uint64_t P9N2__SM2_XTS_ATRMISS2                                       = 0x0501164Cull;


static const uint64_t P9N2__SM2_XTS_ATRMISSCLR                                     = 0x0501164Bull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP0                                      = 0x05011660ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP1                                      = 0x05011661ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP2                                      = 0x05011662ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP3                                      = 0x05011663ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP4                                      = 0x05011664ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP5                                      = 0x05011665ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP6                                      = 0x05011666ull;


static const uint64_t P9N2__SM3_XTS_ATSD_HYP7                                      = 0x05011667ull;


static const uint64_t P9N2__SM2_XTS_CONFIG                                         = 0x05011644ull;


static const uint64_t P9N2__SM2_XTS_CONFIG2                                        = 0x05011645ull;


static const uint64_t P9N2__SM2_XTS_CONFIG3                                        = 0x0501164Dull;


static const uint64_t P9N2__SM2_XTS_PMU_CNT                                        = 0x05011648ull;

#endif

