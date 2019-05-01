/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_proc_6.H $       */
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

#include "proc_scomt.H"

#ifndef __p10_scom_proc_6_H_
#define __p10_scom_proc_6_H_


namespace scomt
{
namespace proc
{


static const uint64_t INT_CQ_ACTION1 = 0x02010837ull;

static const uint32_t INT_CQ_ACTION1_INT_CQ_ACTION1 = 0;
static const uint32_t INT_CQ_ACTION1_INT_CQ_ACTION1_LEN = 64;
// proc/reg00024.H

static const uint64_t INT_CQ_CFG_LDQ2 = 0x0201081bull;

static const uint32_t INT_CQ_CFG_LDQ2_IN_0_2 = 0;
static const uint32_t INT_CQ_CFG_LDQ2_IN_0_2_LEN = 3;
static const uint32_t INT_CQ_CFG_LDQ2_AX_0_4 = 3;
static const uint32_t INT_CQ_CFG_LDQ2_AX_0_4_LEN = 5;
// proc/reg00024.H

static const uint64_t INT_CQ_ERR_INFO3 = 0x0201083dull;

static const uint32_t INT_CQ_ERR_INFO3_INFO_CAPTURED = 0;
static const uint32_t INT_CQ_ERR_INFO3_STQ_FSM_PERR = 1;
static const uint32_t INT_CQ_ERR_INFO3_LDQ_FSM_PERR = 2;
static const uint32_t INT_CQ_ERR_INFO3_WRQ_FSM_PERR = 3;
static const uint32_t INT_CQ_ERR_INFO3_RDQ_FSM_PERR = 4;
static const uint32_t INT_CQ_ERR_INFO3_INTQ_FSM_PERR = 5;
static const uint32_t INT_CQ_ERR_INFO3_WRQ_OVERFLOW = 6;
static const uint32_t INT_CQ_ERR_INFO3_RDQ_OVERFLOW = 7;
static const uint32_t INT_CQ_ERR_INFO3_INTQ_OVERFLOW = 8;
// proc/reg00024.H

static const uint64_t INT_CQ_MC = 0x02010811ull;

static const uint32_t INT_CQ_MC_VALID = 0;
static const uint32_t INT_CQ_MC_BLOCK_ID_0_3 = 32;
static const uint32_t INT_CQ_MC_BLOCK_ID_0_3_LEN = 4;
static const uint32_t INT_CQ_MC_ESB_OFFSET_0_25 = 36;
static const uint32_t INT_CQ_MC_ESB_OFFSET_0_25_LEN = 26;
// proc/reg00024.H

static const uint64_t INT_CQ_MSGSND = 0x02010810ull;

static const uint32_t INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31 = 0;
static const uint32_t INT_CQ_MSGSND_INT_CQ_MSGSND_CORES_ENABLED_0_31_LEN = 32;
// proc/reg00024.H

static const uint64_t INT_PC_NXC_REGS_DEBUG = 0x02010a94ull;

static const uint32_t INT_PC_NXC_REGS_DEBUG_PMC_ENABLE = 0;
static const uint32_t INT_PC_NXC_REGS_DEBUG_TRACE_ENABLE = 1;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_2_10 = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_2_10_LEN = 9;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_LD_ECC_CORRECTION = 11;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_12_15 = 12;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_12_15_LEN = 4;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION = 16;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_TAG_ECC_CORRECTION_LEN = 12;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_28_29 = 28;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_28_29_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION = 30;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_STATE_ECC_CORRECTION_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_32_33 = 32;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_32_33_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION = 34;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_DATA_ECC_CORRECTION_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_40 = 40;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION = 41;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_PTAG_ECC_CORRECTION_LEN = 3;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_44_45 = 44;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_44_45_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_RMT_RSP_ECC_CORRECTION = 46;
static const uint32_t INT_PC_NXC_REGS_DEBUG_DIS_WATCH_ECC_CORRECTION = 47;
static const uint32_t INT_PC_NXC_REGS_DEBUG_FORCE_SINGLE_BIT_ECC_ERR = 48;
static const uint32_t INT_PC_NXC_REGS_DEBUG_FORCE_DOUBLE_BIT_ECC_ERR = 49;
static const uint32_t INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL = 50;
static const uint32_t INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_PARTITION_SEL_LEN = 2;
static const uint32_t INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL = 52;
static const uint32_t INT_PC_NXC_REGS_DEBUG_ECC_ERR_INJ_ARRAY_SEL_LEN = 6;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_58_63 = 58;
static const uint32_t INT_PC_NXC_REGS_DEBUG_RESERVED_58_63_LEN = 6;
// proc/reg00024.H

static const uint64_t INT_PC_NXC_REGS_WATCH1_DATA0 = 0x02010aacull;
// proc/reg00024.H

static const uint64_t INT_PC_NXC_REGS_WATCH2_SPEC = 0x02010ab0ull;
// proc/reg00024.H

static const uint64_t INT_PC_REGS_ERR0_CFG0 = 0x02010ac0ull;

static const uint32_t INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0 = 0;
static const uint32_t INT_PC_REGS_ERR0_CFG0_INT_PC_ERR0_CFG0_ERROR_CONFIG0_LEN = 64;
// proc/reg00024.H

static const uint64_t INT_PC_REGS_ERR0_INFO = 0x02010ac6ull;

static const uint32_t INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR = 0;
static const uint32_t INT_PC_REGS_ERR0_INFO_INT_PC_ERR0_INFO_ERROR_LEN = 64;
// proc/reg00024.H

static const uint64_t INT_VC_ENDC_FLUSH_INJECT = 0x02010982ull;

static const uint32_t INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3 = 0;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_RESERVED_0_3_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_BLOCKID = 4;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_OFFSET = 8;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_OFFSET_LEN = 24;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35 = 32;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_RESERVED_32_35_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK = 36;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_BLOCKID_MASK_LEN = 4;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK = 40;
static const uint32_t INT_VC_ENDC_FLUSH_INJECT_OFFSET_MASK_LEN = 24;
// proc/reg00024.H

static const uint64_t INT_VC_ENDC_WATCH2_DATA2 = 0x020109b6ull;
// proc/reg00024.H

static const uint64_t INT_VC_EQA_CFG = 0x02010921ull;

static const uint32_t INT_VC_EQA_CFG_RESERVED_0 = 0;
static const uint32_t INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY = 1;
static const uint32_t INT_VC_EQA_CFG_IPI_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_4 = 4;
static const uint32_t INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY = 5;
static const uint32_t INT_VC_EQA_CFG_HWD_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_8 = 8;
static const uint32_t INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY = 9;
static const uint32_t INT_VC_EQA_CFG_NXC_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_12 = 12;
static const uint32_t INT_VC_EQA_CFG_INT_QUEUE_PRIORITY = 13;
static const uint32_t INT_VC_EQA_CFG_INT_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_16 = 16;
static const uint32_t INT_VC_EQA_CFG_OS_QUEUE_PRIORITY = 17;
static const uint32_t INT_VC_EQA_CFG_OS_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_20 = 20;
static const uint32_t INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY = 21;
static const uint32_t INT_VC_EQA_CFG_POOL_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_24 = 24;
static const uint32_t INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY = 25;
static const uint32_t INT_VC_EQA_CFG_HARD_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_RESERVED_28 = 28;
static const uint32_t INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY = 29;
static const uint32_t INT_VC_EQA_CFG_LOCAL_QUEUE_PRIORITY_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_ERQ_WR_DISABLE = 32;
static const uint32_t INT_VC_EQA_CFG_ERQ_WR_DISABLE_LEN = 8;
static const uint32_t INT_VC_EQA_CFG_ERQ_RD_DISABLE = 40;
static const uint32_t INT_VC_EQA_CFG_ERQ_RD_DISABLE_LEN = 8;
static const uint32_t INT_VC_EQA_CFG_RESERVED_48_50 = 48;
static const uint32_t INT_VC_EQA_CFG_RESERVED_48_50_LEN = 3;
static const uint32_t INT_VC_EQA_CFG_NXC_FWD_TO_ENDC = 51;
static const uint32_t INT_VC_EQA_CFG_RESERVED_52_55 = 52;
static const uint32_t INT_VC_EQA_CFG_RESERVED_52_55_LEN = 4;
// proc/reg00024.H

static const uint64_t INT_VC_ERR_CFG_G1R0 = 0x020109c8ull;

static const uint32_t INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG = 0;
static const uint32_t INT_VC_ERR_CFG_G1R0_INT_VC_ERR_CFG_G1R0_ERROR_CONFIG_LEN = 48;
// proc/reg00024.H

static const uint64_t INT_VC_ESBC_SOFTWR_ADDR = 0x02010950ull;

static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_BLOCKID = 28;
static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_BLOCKID_LEN = 4;
static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35 = 32;
static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_RESERVED_32_35_LEN = 4;
static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_OFFSET = 36;
static const uint32_t INT_VC_ESBC_SOFTWR_ADDR_OFFSET_LEN = 23;
// proc/reg00024.H

static const uint64_t INT_VC_FATAL_ERR_G1 = 0x020109ccull;

static const uint32_t INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR = 0;
static const uint32_t INT_VC_FATAL_ERR_G1_INT_VC_FATAL_ERR_G1_ERROR_LEN = 48;
// proc/reg00024.H

static const uint64_t INT_VC_INFO_ERR_G2 = 0x020109d6ull;

static const uint32_t INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR = 0;
static const uint32_t INT_VC_INFO_ERR_G2_INT_VC_INFO_ERR_G2_ERROR_LEN = 64;
// proc/reg00024.H

static const uint64_t INT_VC_QUEUES_CFG_LOC = 0x0201091eull;

static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_DISABLE = 0;
static const uint32_t INT_VC_QUEUES_CFG_LOC_RESERVED_1 = 1;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE = 2;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_PREFETCH_DISTANCE_LEN = 6;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM = 8;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_MAX_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM = 12;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_MIN_NB_OUTSTANDING_DEM_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_LOC_RESERVED_16_19 = 16;
static const uint32_t INT_VC_QUEUES_CFG_LOC_RESERVED_16_19_LEN = 4;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_FULL = 20;
static const uint32_t INT_VC_QUEUES_CFG_LOC_IRQ_IDLE = 21;
static const uint32_t INT_VC_QUEUES_CFG_LOC_ERQ_FULL = 22;
static const uint32_t INT_VC_QUEUES_CFG_LOC_ERQ_IDLE = 23;
// proc/reg00024.H

static const uint64_t INT_VC_WOF_ERR_G0 = 0x020109c2ull;

static const uint32_t INT_VC_WOF_ERR_G0_ARX_CTRL_PTY_ERROR = 0;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_CMD_PTY_ERROR = 1;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_UE = 2;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_UE = 3;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_AIB_CMD_ERROR = 4;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT1 = 5;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_AIB_RESP_TIMEOUT2 = 6;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_7 = 7;
static const uint32_t INT_VC_WOF_ERR_G0_REGS_PARITY_ERROR = 8;
static const uint32_t INT_VC_WOF_ERR_G0_REGS_CREDIT_ERROR = 9;
static const uint32_t INT_VC_WOF_ERR_G0_REGS_SCOM_INTERNAL_ERROR = 10;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_11 = 11;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_LACK_OF_TAG = 12;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_TAG_RELEASE_ERROR = 13;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_CRD_PARITY_ERROR = 14;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_UE = 15;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_SLOT_OVERFLOW = 16;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_CRD_OVERFLOW = 17;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_CRD_UNDERFLOW = 18;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_19 = 19;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_20 = 20;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_VSD_TYPE_ERROR = 21;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_VSD_INDIRECT_ERROR = 22;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_VSD_OFFSET_ERROR = 23;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_CMD_STATE_ERROR = 24;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_LKP_STATE_ERROR = 25;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_ATC_STATE_ERROR = 26;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_ATC_CAM_STATE_ERROR = 27;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_PARITY_ERROR = 28;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_ECC_UE = 29;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_30 = 30;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_INT_TRIG_CRD_ERROR = 31;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_OVERFLOW = 32;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_SEQUENCE_ID_ERROR = 33;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_UE = 34;
static const uint32_t INT_VC_WOF_ERR_G0_IQA_ESBC_DEMAND_ERROR = 35;
static const uint32_t INT_VC_WOF_ERR_G0_IQA_EASC_DEMAND_ERROR = 36;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_37 = 37;
static const uint32_t INT_VC_WOF_ERR_G0_IQS_SLOT_OVERFLOW = 38;
static const uint32_t INT_VC_WOF_ERR_G0_IQS_SEQID_OVERFLOW = 39;
static const uint32_t INT_VC_WOF_ERR_G0_IQS_SEQID_NOT_PENDING = 40;
static const uint32_t INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_UE = 41;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_42 = 42;
static const uint32_t INT_VC_WOF_ERR_G0_ERQ_PARITY_ERROR = 43;
static const uint32_t INT_VC_WOF_ERR_G0_ERQ_CREDIT_ERROR = 44;
static const uint32_t INT_VC_WOF_ERR_G0_ERQ_OVERFLOW = 45;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_46 = 46;
static const uint32_t INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_UE = 47;
static const uint32_t INT_VC_WOF_ERR_G0_EQA_ENDC_CREDIT_ERROR = 48;
static const uint32_t INT_VC_WOF_ERR_G0_EQA_ATX_CREDIT_ERROR = 49;
static const uint32_t INT_VC_WOF_ERR_G0_DPS_SLOT_OVERFLOW = 50;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_51 = 51;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_AIB_DATA_ECC_CE = 52;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_TAG_SRAM_ECC_CE = 53;
static const uint32_t INT_VC_WOF_ERR_G0_ATX_WB_SRAM_ECC_CE = 54;
static const uint32_t INT_VC_WOF_ERR_G0_ATXC_ECC_CE = 55;
static const uint32_t INT_VC_WOF_ERR_G0_IQS_SRAM_ECC_CE = 56;
static const uint32_t INT_VC_WOF_ERR_G0_ERQ_SRAM_ECC_CE = 57;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_SRAM_ECC_CE = 58;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_59 = 59;
static const uint32_t INT_VC_WOF_ERR_G0_ARX_UNRECOGNIZED_CI_STR = 60;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_EAS_ESB_BLK_NOT_OWNED = 61;
static const uint32_t INT_VC_WOF_ERR_G0_IRQ_END_BLK_NOT_OWNED = 62;
static const uint32_t INT_VC_WOF_ERR_G0_RESERVED_63 = 63;
// proc/reg00024.H

static const uint64_t MCD_BANK0_MUON = 0x03010814ull;

static const uint32_t MCD_BANK0_MUON_VALID = 0;
static const uint32_t MCD_BANK0_MUON_CHIP_CONTAINED_MODE = 5;
static const uint32_t MCD_BANK0_MUON_SMF_ENABLE = 6;
static const uint32_t MCD_BANK0_MUON_GRP_SIZE = 11;
static const uint32_t MCD_BANK0_MUON_GRP_SIZE_LEN = 19;
static const uint32_t MCD_BANK0_MUON_GRP_BASE = 33;
static const uint32_t MCD_BANK0_MUON_GRP_BASE_LEN = 31;
// proc/reg00024.H

static const uint64_t MCD_DBG = 0x03010813ull;

static const uint32_t MCD_DBG_TRACE_ENABLE = 3;
static const uint32_t MCD_DBG_TRACE_SELECT = 4;
static const uint32_t MCD_DBG_TRACE_SELECT_LEN = 4;
static const uint32_t MCD_DBG_ERR_INJ_ENABLE = 8;
static const uint32_t MCD_DBG_ERR_INJ_TYPE = 9;
static const uint32_t MCD_DBG_ERR_INJ_ACTION = 10;
static const uint32_t MCD_DBG_ERR_INJ_ARRAY_SEL = 11;
static const uint32_t MCD_DBG_ERR_INJ_ARRAY_SEL_LEN = 4;
static const uint32_t MCD_DBG_ERR_INJ_STATUS = 15;
static const uint32_t MCD_DBG_PMU_ENABLE = 19;
static const uint32_t MCD_DBG_PMU_SELECT_LOW = 20;
static const uint32_t MCD_DBG_PMU_SELECT_LOW_LEN = 3;
static const uint32_t MCD_DBG_PMU_SELECT_HIGH = 23;
static const uint32_t MCD_DBG_PMU_SELECT_HIGH_LEN = 3;
static const uint32_t MCD_DBG_PMU_BUS_ENABLE = 32;
static const uint32_t MCD_DBG_PMU_BUS_ENABLE_LEN = 16;
static const uint32_t MCD_DBG_RECOVER_ADDR = 48;
static const uint32_t MCD_DBG_RECOVER_ADDR_LEN = 15;
// proc/reg00024.H

static const uint64_t MCD_ECAP2 = 0x03010819ull;

static const uint32_t MCD_ECAP2_TOP_PARITY_ERROR = 0;
static const uint32_t MCD_ECAP2_STR_PARITY_ERROR = 1;
static const uint32_t MCD_ECAP2_BOT_PARITY_ERROR = 2;
static const uint32_t MCD_ECAP2_CHA_PARITY_ERROR = 3;
static const uint32_t MCD_ECAP2_MUON_PARITY_ERROR = 4;
static const uint32_t MCD_ECAP2_TAU_PARITY_ERROR = 5;
static const uint32_t MCD_ECAP2_GLUON_PARITY_ERROR = 6;
static const uint32_t MCD_ECAP2_BOSON_PARITY_ERROR = 7;
static const uint32_t MCD_ECAP2_TOPOID_PARITY_ERROR = 8;
static const uint32_t MCD_ECAP2_CHKSET_PARITY_ERROR = 9;
static const uint32_t MCD_ECAP2_VGC_PARITY_ERROR = 10;
static const uint32_t MCD_ECAP2_REC_PARITY_ERROR = 11;
// proc/reg00024.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG = 0x02010c26ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_ENABLE = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_ENABLE = 1;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_ENABLE = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_ENABLE = 3;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL = 4;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PRESCALER_SEL_LEN = 3;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_POSEDGE_SEL = 7;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_POSEDGE_SEL = 8;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_POSEDGE_SEL = 9;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_POSEDGE_SEL = 10;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_RESET = 11;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL = 12;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_EVENT_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL = 14;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT0_BIT_PAIR_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_EVENT_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL = 18;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT1_BIT_PAIR_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL = 20;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_EVENT_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL = 22;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT2_BIT_PAIR_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL = 24;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_EVENT_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL = 26;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_CNT3_BIT_PAIR_SEL_LEN = 2;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL = 28;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_CONTROL_REG_PORT_SEL_LEN = 2;
// proc/reg00024.H

static const uint64_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG = 0x02010c27ull;

static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0 = 0;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_0_LEN = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1 = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_1_LEN = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2 = 32;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_2_LEN = 16;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3 = 48;
static const uint32_t MM0_MM_FBC_CQ_WRAP_NXCQ_SCOM_NX_PMU_COUNTER_REG_3_LEN = 16;
// proc/reg00024.H

static const uint64_t MM0_MM_FIR1_MASK_REG_RW = 0x02010c43ull;
static const uint64_t MM0_MM_FIR1_MASK_REG_WO_AND = 0x02010c44ull;
static const uint64_t MM0_MM_FIR1_MASK_REG_WO_OR = 0x02010c45ull;

static const uint32_t MM0_MM_FIR1_MASK_REG_MM_FIR1_MASK = 0;
static const uint32_t MM0_MM_FIR1_MASK_REG_MM_FIR1_MASK_LEN = 46;
// proc/reg00024.H

static const uint64_t MM1_MM_CFG_NMMU_CTL_SLB = 0x03010c54ull;

static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_MBR_DIS = 0;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_MBR_DIS_LEN = 16;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_SNGL_THD_EN = 16;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_CAC_ALLOC_DIS = 17;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DMAP_MODE_EN = 18;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ALT_SEGSZ_DIS = 19;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DIR_PERR_CHK_DIS = 20;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_CAC_PERR_CHK_DIS = 21;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_LRU_PERR_CHK_DIS = 22;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_MULTIHIT_CHK_DIS = 23;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS505_FIX_DIS = 24;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS510_FIX_DIS = 25;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS511_FIX_DIS = 26;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS544_FIX_DIS = 27;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS554_FIX_DIS = 28;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS560_FIX_DIS = 29;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DD2_ISS584_FIX_DIS = 30;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL = 32;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DBG_BUS0_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL = 36;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_DBG_BUS1_STG0_SEL_LEN = 4;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_ISS542_FIX_DIS = 52;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_TWSM_11_1_MODE_ENA = 57;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_SNGL_SHOT_ENA = 58;
static const uint32_t MM1_MM_CFG_NMMU_CTL_SLB_FBC_SNGL_SHOT_HOLDOFF_ENA = 59;
// proc/reg00024.H

static const uint64_t NX_CH4_ADDR_1_HASH_FUNCTION_REG = 0x02011142ull;

static const uint32_t NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_ADDR_1_HASH_FUNCTION_REG_ADDRESS_1_HASH_FUNCTION_LEN = 64;
// proc/reg00024.H

static const uint64_t NX_CH4_DATATAG_5_HASH_FUNCTION_REG = 0x02011151ull;

static const uint32_t NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION = 0;
static const uint32_t NX_CH4_DATATAG_5_HASH_FUNCTION_REG_DATATAG_5_HASH_FUNCTION_LEN = 64;
// proc/reg00024.H

static const uint64_t NX_DBG_DMA_ENG_FIR_ACTION1 = 0x02011107ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_ACTION1_NX_DMA_ENG_FIR_ACTION1_BITS_LEN = 48;
// proc/reg00024.H

static const uint64_t NX_DBG_DMA_ENG_FIR_WOF = 0x02011108ull;

static const uint32_t NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS = 0;
static const uint32_t NX_DBG_DMA_ENG_FIR_WOF_NX_DMA_ENG_FIR_WOF_BITS_LEN = 48;
// proc/reg00024.H

static const uint64_t NX_DMA_SU_CRB_KILL_REQ = 0x02011053ull;

static const uint32_t NX_DMA_SU_CRB_KILL_REQ_ENABLE = 0;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_DONE = 1;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_SUMMARY = 2;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT = 4;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_DISPATCH_SLOT_KILLED_CNT_LEN = 4;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT = 8;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_PREFETCH_CHANNEL_CNT_LEN = 4;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT = 12;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_ACTIVE_CHANNEL_CNT_LEN = 4;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE = 16;
static const uint32_t NX_DMA_SU_CRB_KILL_REQ_SWC_VALUE_LEN = 16;
// proc/reg00024.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG = 0x02011086ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0 = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION0_REG_NX_CQ_FIR_ACTION0_LEN = 42;
// proc/reg00024.H

static const uint64_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG = 0x02011087ull;

static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1 = 0;
static const uint32_t NX_PBI_CQ_WRAP_NXCQ_SCOM_FIR_ACTION1_REG_NX_CQ_FIR_ACTION1_LEN = 42;
// proc/reg00024.H

static const uint64_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL = 0x020110c5ull;

static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET = 4;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_READ_OFFSET_LEN = 8;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED = 15;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_QUEUED_LEN = 9;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX = 27;
static const uint32_t NX_PBI_UMAC_GZIP_HI_PRIOR_RCV_FIFO_CNTL_HI_PRIMAX_LEN = 9;
// proc/reg00024.H

static const uint64_t NX_PBI_UMAC_VAS_MMIO_BASE_ADDR = 0x020110d4ull;

static const uint32_t NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR = 8;
static const uint32_t NX_PBI_UMAC_VAS_MMIO_BASE_ADDR_VAS_MMIO_BAR_LEN = 31;
// proc/reg00024.H

static const uint64_t PB_COM_ES3_GP_CMD_RATE = 0x000003aaull;

static const uint32_t PB_COM_ES3_GP_CMD_RATE_0_ES3 = 0;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_0_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_1_ES3 = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_1_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_2_ES3 = 16;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_2_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_3_ES3 = 24;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_3_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_4_ES3 = 32;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_4_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_5_ES3 = 40;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_5_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_6_ES3 = 48;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_6_ES3_LEN = 8;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_7_ES3 = 56;
static const uint32_t PB_COM_ES3_GP_CMD_RATE_7_ES3_LEN = 8;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_DOB01_DIB01_INT_ERR_REG = 0x10011828ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_MAILBOX_00_REG = 0x10011830ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_MAILBOX_01_REG = 0x10011831ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_PMU0_CNPM_COUNTER = 0x10011821ull;
// proc/reg00024.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint64_t PB_PTLSCOM10_PTL_FIR_MASK_REG_RWX = 0x10011803ull;
static const uint64_t PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_AND = 0x00000004ull;
static const uint64_t PB_PTLSCOM10_PTL_FIR_MASK_REG_WOX_OR = 0x00000005ull;

static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR00_TRAINED_MASK = 0;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR01_TRAINED_MASK = 1;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR02_TRAINED_MASK = 2;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FMR03_TRAINED_MASK = 3;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_UE_MASK = 8;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_CE_MASK = 9;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_SUE_MASK = 10;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_UE_MASK = 11;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_CE_MASK = 12;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_SUE_MASK = 13;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER00_ATTN_MASK = 20;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER01_ATTN_MASK = 21;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER02_ATTN_MASK = 22;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_FRAMER03_ATTN_MASK = 23;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER00_ATTN_MASK = 28;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER01_ATTN_MASK = 29;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER02_ATTN_MASK = 30;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_PARSER03_ATTN_MASK = 31;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB00_SPATTN_MASK = 36;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB01_SPATTN_MASK = 37;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB10_SPATTN_MASK = 38;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB11_SPATTN_MASK = 39;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB20_SPATTN_MASK = 40;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB21_SPATTN_MASK = 41;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB30_SPATTN_MASK = 42;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_MB31_SPATTN_MASK = 43;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB01_ERR_MASK = 52;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DOB23_ERR_MASK = 53;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB01_ERR_MASK = 56;
static const uint32_t PB_PTLSCOM10_PTL_FIR_MASK_REG_DIB23_ERR_MASK = 57;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG = 0x10011819ull;

static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET = 0;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET = 2;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_SET_LEN = 2;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT = 4;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_01_RT_DELAY_CTL_STAT_LEN = 2;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT = 6;
static const uint32_t PB_PTLSCOM10_TL_LINK_RT_DELAY_CTL_REG_23_RT_DELAY_CTL_STAT_LEN = 2;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM10_TL_LINK_SYN_23_REG = 0x10011813ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM23_DOB23_DIB23_INT_ERR_REG = 0x1101182aull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM23_PMU2_CNPM_COUNTER = 0x11011823ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM23_PTL_FIR_WOF_REG = 0x11011808ull;

static const uint32_t PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF = 0;
static const uint32_t PB_PTLSCOM23_PTL_FIR_WOF_REG_PB_PTL_FIR_WOF_LEN = 62;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM45_MAILBOX_10_REG = 0x12011832ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM45_MAILBOX_11_REG = 0x12011833ull;
// proc/reg00024.H

static const uint64_t PB_PTLSCOM67_MAILBOX_CTL_REG = 0x1301182eull;

static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_VALID = 0;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_WR_NOT_RD = 1;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_ADDR = 2;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_DOWN = 3;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_CORRUPT = 4;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_SENT = 5;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_BAD_WRITE = 6;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_RESET = 7;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_AILBOX_ID = 8;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID = 9;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_LINK_ID_LEN = 3;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE = 12;
static const uint32_t PB_PTLSCOM67_MAILBOX_CTL_REG_B_SPARE_LEN = 4;
// proc/reg00024.H

static const uint64_t PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG = 0x03012414ull;

static const uint32_t PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS = 24;
static const uint32_t PB_BRIDGE_HCA_DECAY_1_ADDRESS_REG_DECAY_1_ADDRESS_LEN = 33;
// proc/reg00024.H

static const uint64_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST = 0x03011c83ull;

static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS = 8;
static const uint32_t PB_BRIDGE_NHTM_NHTM0_SC_HTM_LAST_HTM_LAST_ADDRESS_LEN = 49;
// proc/reg00025.H

static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIRMASK_REG_RW = 0x080108c3ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIRMASK_REG_WO_AND = 0x080108c4ull;
static const uint64_t PE0_PB_PBAIB_REGS_STACK_2_PFIRMASK_REG_WO_OR = 0x080108c5ull;

static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRMASK_REG_PFIRMASK = 0;
static const uint32_t PE0_PB_PBAIB_REGS_STACK_2_PFIRMASK_REG_PFIRMASK_LEN = 6;
// proc/reg00025.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG = 0x0201180aull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK0 = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK0_LEN = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK1 = 16;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_STK1_LEN = 8;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_NSTQSTKOVR_REG_ENABLE = 24;
// proc/reg00025.H

static const uint64_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG = 0x020118d4ull;

static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_MMIO_BAR0_EN = 0;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_MMIO_BAR1_EN = 1;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_PHB_BAR_EN = 2;
static const uint32_t PE0_PB_PBCQ_PEPBREGS_STACK_2_REGS_BARE_REG_INT_BAR_EN = 3;
// proc/reg00025.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL = 0x08010905ull;

static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_DATA_ENABLE = 0;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_CONFIG_ADDR_ENABLE = 1;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_RTT_BASE_ENABLE = 2;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PELTV_BASE_ENABLE = 3;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_PEST_BASE_ENABLE = 4;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_ADDR_ENABLE = 5;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_IODA_TABLE_DATA_ENABLE = 6;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_ADDR_ENABLE = 7;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_OFFSET_CNTL_INT_NOTIFY_BASE_INDEX_ENABLE = 8;
// proc/reg00025.H

static const uint64_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x08010904ull;

static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t PE0_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_PHB5_PMON_CONFIG = 0x00000957ull;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_REGS_PHB5_PMON_COUNTERS = 0x00000959ull;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB1_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x00000955ull;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE0_PHB2_ETUX08_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PAST = 0x00000995ull;
// proc/reg00025.H

static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PFIRMASK_REG_RW = 0x09010843ull;
static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PFIRMASK_REG_WO_AND = 0x09010844ull;
static const uint64_t PE1_PB_PBAIB_REGS_STACK_0_PFIRMASK_REG_WO_OR = 0x09010845ull;

static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PFIRMASK_REG_PFIRMASK = 0;
static const uint32_t PE1_PB_PBAIB_REGS_STACK_0_PFIRMASK_REG_PFIRMASK_LEN = 6;
// proc/reg00025.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG = 0x03011801ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK_LEN = 6;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_CTAG_DROP_PRIORITY = 6;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_IO_CMD_PACING = 7;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT = 8;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT_LEN = 9;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC = 17;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC_LEN = 6;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER = 23;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER_LEN = 3;
// proc/reg00025.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG = 0x03011804ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_EN = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_EN_LEN = 16;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_ALL_ENGINES = 17;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_STK = 18;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_STK_LEN = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_RD_TYPE = 20;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_RD_TYPE_LEN = 2;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE0 = 22;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE0_LEN = 3;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE1 = 25;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE1_LEN = 3;
// proc/reg00025.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG = 0x0301184eull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG_PE_MMIO_BAR0 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR0_REG_PE_MMIO_BAR0_LEN = 40;
// proc/reg00025.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG = 0x03011851ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_MASK_REG_PE_MMIO_MASK1_LEN = 40;
// proc/reg00025.H

static const uint64_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG = 0x03011850ull;

static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG_PE_MMIO_BAR1 = 0;
static const uint32_t PE1_PB_PBCQ_PEPBREGS_STACK_0_REGS_MMIOBAR1_REG_PE_MMIO_BAR1_LEN = 40;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x00000906ull;

static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB0_ETUX16_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00025.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t PE1_PHB0_ETUX16_RSB_SCOM_SSR_PLB_PLAP_PCI_DLR_LAP_PASR = 0x00000913ull;
// proc/reg00025.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_ACTION1_REG = 0x0901094full;
// proc/reg00025.H

static const uint64_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP = 0x09010946ull;

static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_ENABLE = 0;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB1_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_CMP_VALUE_LEN = 40;
// proc/reg00025.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL = 0x09010984ull;

static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_ENABLE = 0;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE = 12;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_CMP_VALUE_LEN = 8;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE = 44;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_EXCL_MSK_VALUE_LEN = 8;
// proc/reg00025.H

static const uint64_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK = 0x09010987ull;

static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE = 12;
static const uint32_t PE1_PHB2_ETUX08_RSB_REGS_UVI_PHB4_SCOM_UV_SEC_INCL_MSK_PHB4_SCOM_UV_SEC_INCL_MSK_VALUE_LEN = 40;
// proc/reg00025.H

static const uint64_t TP_TPBR_AD_ALTD_OPTION_REG = 0x03001c02ull;

static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_WITH_PBINIT_LOW_WAIT = 22;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_WITH_PRE_QUIESCE = 23;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT = 28;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_AFTER_QUIESCE_WAIT_COUNT_LEN = 20;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_WITH_POST_INIT = 51;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_WITH_FAST_PATH = 52;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT = 54;
static const uint32_t TP_TPBR_AD_ALTD_OPTION_REG_BEFORE_INIT_WAIT_COUNT_LEN = 10;
// proc/reg00025.H

static const uint64_t TP_TPBR_AD_LPC_DATA_REG = 0x03001c42ull;

static const uint32_t TP_TPBR_AD_LPC_DATA_REG_LPC_DATA = 0;
static const uint32_t TP_TPBR_AD_LPC_DATA_REG_LPC_DATA_LEN = 64;
// proc/reg00025.H

static const uint64_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG = 0x03001c18ull;

static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_DONE = 0;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_RESULT = 1;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_RESULT_LEN = 3;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_COREID = 4;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_COREID_LEN = 6;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_STAT_THRID = 10;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_XSCOM_STAT_THRID_LEN = 3;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_DEST_GROUPID = 13;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_DEST_GROUPID_LEN = 4;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_DEST_CHIPID = 17;
static const uint32_t TP_TPBR_AD_XSCOM_RCVED_STAT_REG_DEST_CHIPID_LEN = 3;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAF_PBAFIR_RWX = 0x03021cc0ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIR_WOX_AND = 0x03021cc1ull;
static const uint64_t TP_TPBR_PBA_PBAF_PBAFIR_WOX_OR = 0x03021cc2ull;

static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_OCI_APAR_ERR = 0;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_RDADRERR_FW = 1;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_RDDATATO_FW = 2;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_SUE_FW = 3;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_UE_FW = 4;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_CE_FW = 5;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_OCI_SLAVE_INIT = 6;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_OCI_WRPAR_ERR = 7;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_8 = 8;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPCRESP = 9;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_UNEXPDATA = 10;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_PARITY_ERR = 11;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_WRADRERR_FW = 12;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_BADCRESP = 13;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_RD = 14;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_OPERTO = 15;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCUE_SETUP_ERR = 16;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ACK_DEAD = 17;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCUE_PB_ADRERR = 18;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCUE_OCI_DATERR = 19;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SETUP_ERR = 20;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ACK_DEAD = 21;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_PB_ADRERR = 22;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_RDDATATO_ERR = 23;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_SUE_ERR = 24;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_UE_ERR = 25;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_CE = 26;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_BCDE_OCI_DATERR = 27;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_INTERNAL_ERR = 28;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_ILLEGAL_CACHE_OP = 29;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_OCI_BAD_REG_ADDR = 30;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXPUSH_WRERR = 31;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_ERR = 32;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_DLO_TO = 33;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXRCV_RSVDATA_TO = 34;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXFLOW_ERR = 35;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DHI_RTYTO = 36;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXSND_DLO_RTYTO = 37;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVTO = 38;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_AXSND_RSVERR = 39;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_PB_ACKDEAD_FW_WR = 40;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_41 = 41;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_42 = 42;
static const uint32_t TP_TPBR_PBA_PBAF_PBAFIR_RESERVED_43 = 43;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAO_BCDE_OCIBAR = 0x00068014ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_OCIBAR_BCDE_OCIBAR_ADDR_LEN = 25;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAO_BCDE_STAT = 0x00068012ull;

static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_RUNNING = 0;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_WAITING = 1;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP = 2;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_WRCMP_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP = 14;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_RDCMP_LEN = 6;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG = 20;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_DEBUG_LEN = 9;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_STOPPED = 29;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_ERROR = 30;
static const uint32_t TP_TPBR_PBA_PBAO_BCDE_STAT_DONE = 31;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAOCR0 = 0x0006801aull;

static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR0_PBAOCR0_COUNT = 44;
static const uint32_t TP_TPBR_PBA_PBAO_PBAOCR0_PBAOCR0_COUNT_LEN = 20;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAO_PBASLVCTL0 = 0x00068004ull;

static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_ENABLE = 0;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE = 1;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_MATCH_VALUE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_4 = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK = 5;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_MID_CARE_MASK_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TTYPE_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14 = 11;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_11_14_LEN = 4;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_TTYPE = 15;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL = 16;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_READ_PREFETCH_CTL_LEN = 2;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_INVALIDATE_CTL = 18;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_W = 19;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_A = 20;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_B = 21;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_BUF_ALLOC_C = 22;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_23 = 23;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_DIS_WRITE_GATHER = 24;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT = 25;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WR_GATHER_TIMEOUT_LEN = 3;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE = 28;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_WRITE_TSIZE_LEN = 8;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR = 36;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_EXTADDR_LEN = 14;
static const uint32_t TP_TPBR_PBA_PBAO_PBASLVCTL0_RESERVED_50 = 50;
// proc/reg00025.H

static const uint64_t TP_TPBR_PBA_PBAO_PBAXISHINC1 = 0x0006803cull;
// proc/reg00025.H

static const uint64_t TP_TPBR_PSI_WRAP_RX_CH_FSM_REG = 0x03011c0dull;
// proc/reg00025.H

static const uint64_t TP_TPBR_PSIHB_ESB_CI_BASE = 0x03011d16ull;

static const uint32_t TP_TPBR_PSIHB_ESB_CI_BASE_ESB_BASE = 8;
static const uint32_t TP_TPBR_PSIHB_ESB_CI_BASE_ESB_BASE_LEN = 40;
static const uint32_t TP_TPBR_PSIHB_ESB_CI_BASE_ESB_BASE_VALID = 63;
// proc/reg00025.H

static const uint64_t TP_TPBR_PSIHB_TRUST_CONTROL = 0x03011f45ull;

static const uint32_t TP_TPBR_PSIHB_TRUST_CONTROL_FSP_TCE_ENABLE = 2;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR28 = 0x0006004cull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR28_OCB_OCI_GPEXIVDR28_GPR28_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR8 = 0x00060048ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE0_OCB_GPEXIGPR8_OCB_OCI_GPEXIVDR8_GPR8_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO = 0x00062015ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIDBGPRO_OCB_OCI_GPEXIIAR_IAR_LEN = 30;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR29 = 0x0006204dull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR29_OCB_OCI_GPEXIVDR28_GPR29_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR3 = 0x00062043ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIGPR3_OCB_OCI_GPEXIVDR2_GPR3_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIR = 0x00062024ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIIR_OCB_OCI_GPEXIRAMEDR_IR_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB = 0x00062016ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_ADDR_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_R_NW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_BUSY = 33;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_IMPRECISE_ERROR_PENDING = 34;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_RSP_INFO = 49;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_RSP_INFO_LEN = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_RESET_PENDING = 61;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_IFETCH_PENDING = 62;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXISIB_DATAOP_PENDING = 63;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR2 = 0x00062081ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR2_2 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR2_2_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR2_3 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE1_OCB_GPEXIVDR2_3_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC = 0x0006401aull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_TAG_ADDR_LEN = 27;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_ERR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_POPULATE_PENDING = 35;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_VALID = 36;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDCAC_VALID_LEN = 4;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR7 = 0x00064047ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIGPR7_OCB_OCI_GPEXIVDR6_GPR7_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR6 = 0x00064083ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR6_6 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR6_6_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR6_7 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIVDR6_7_LEN = 32;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL = 0x0006602full;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_ERR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_POPULATE_PENDING = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACL_VALID_LEN = 4;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU = 0x0006602eull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDCACU_OCB_OCI_GPEXIDCAC_DCACHE_TAG_ADDR_LEN = 27;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMDBG = 0x00066013ull;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMRA = 0x00066011ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIRAMRA_OCB_OCI_GPEOXIXCR_XCR_LEN = 3;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL = 0x0006602bull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBL_OCB_OCI_GPEXIMEM_MEM_IMPRECISE_ERROR_PENDING = 3;
// proc/reg00025.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXISGBU = 0x0006602aull;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR28 = 0x00066086ull;

static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR28_8 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR28_8_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR28_9 = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIVDR28_9_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_DERP1 = 0x0006c182ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP1_DEND = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP1_DEND_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP1_SOR = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_DERP1_SOR_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A = 0x0006c747ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A_CMD2A_RESERVED_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCMD2A__CLEAR_STICKY_BITS_2A = 1;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0 = 0x0006c700ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_FRAME_SIZE_0_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_OUT_COUNT1_0_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0 = 12;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_DELAY1_0_LEN = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0 = 18;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SCTRLF0_IN_COUNT1_0_LEN = 6;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0A = 0x0006c709ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SRD0A_OCB_OCI_O2SRD0A_O2S_RDATA_0A_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2A = 0x0006c748ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_O2SWD2A_OCB_OCI_O2SWD2A_O2S_WDATA_2A_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCBSES3 = 0x0006c236ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES3_SH_READ_UNDERFLOW = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCBSES3_LL_WRITE_OVERFLOW = 1;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCCHBR = 0x0006c08full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCHBR_COUNT_LEN = 16;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OCCHBR_EN = 16;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OCISR0 = 0x0006c061ull;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_ODISR0 = 0x0006c063ull;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OEHDR = 0x0006c084ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OEHDR_OCB_OCI_OEHDR_EVENT2HALT_DELAY = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OEHDR_OCB_OCI_OEHDR_EVENT2HALT_DELAY_LEN = 20;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR0_RW = 0x0006c00cull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR = 0x0006c00dull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR = 0x0006c00eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIEPR0_OCB_OCI_OIEPR0_INTERRUPT_EDGE_POL_0_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR0_RW = 0x0006c004ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_CLEAR = 0x0006c005ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR = 0x0006c006ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OIMR0_OCB_OCI_OIMR0_INTERRUPT_MASK_0_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OINKR0 = 0x0006c010ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OINKR0_OCB_OCI_OINKR0_INTERRUPT_INPUT_0_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4 = 0x0006c40cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT1Q4_OCB_OCI_OPIT1Q4RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0 = 0x0006c410ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0_OCB_OCI_OPIT2Q0RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT2Q0_OCB_OCI_OPIT2Q0RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q6 = 0x0006c42eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q6_OCB_OCI_OPIT5Q6RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT5Q6_OCB_OCI_OPIT5Q6RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2 = 0x0006c432ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2_OCB_OCI_OPIT6Q2RR_PCB_INTR_PAYLOAD = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT6Q2_OCB_OCI_OPIT6Q2RR_PCB_INTR_PAYLOAD_LEN = 19;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_ROX = 0x0006c638ull;
static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_WOX_CLEAR = 0x0006c639ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_0 = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_1 = 1;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_2 = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_3 = 3;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_4 = 4;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_5 = 5;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_6 = 6;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT7PRA_7 = 7;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C15RR = 0x0006c54full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C15RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C15RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C15RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C15RR_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C27RR = 0x0006c55bull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C27RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C27RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C27RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C27RR_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28 = 0x0006c45cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C28_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30RR = 0x0006c55eull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C30RR_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6 = 0x0006c446ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT8C6_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C12RR = 0x0006c56cull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C12RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C12RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C12RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C12RR_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C19 = 0x0006c473ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C19_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C19_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C19_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C19_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20RR = 0x0006c574ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20RR_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20RR_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20RR_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C20RR_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31 = 0x0006c47full;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C31_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C8 = 0x0006c468ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C8_SOURCE_CORE = 13;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C8_SOURCE_CORE_LEN = 2;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C8_PAYLOAD = 15;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_OPIT9C8_PAYLOAD_LEN = 17;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_OCI_OCB_WOFICWD = 0x0006c784ull;

static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICWD_HIGH = 0;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICWD_HIGH_LEN = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICWD_LOW = 32;
static const uint32_t TP_TPCHIP_OCC_OCI_OCB_WOFICWD_LOW_LEN = 32;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OCC_SRAM_CTL_SRMAP = 0x0006a002ull;

static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMAP_SOURCE = 0;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMAP_SOURCE_LEN = 14;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMAP_DEST = 16;
static const uint32_t TP_TPCHIP_OCC_SRAM_CTL_SRMAP_DEST_LEN = 14;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG11 = 0x0000800bull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG11_REGISTER11 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG11_REGISTER11_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG111 = 0x0000806full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG111_REGISTER111 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG111_REGISTER111_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG126 = 0x0000807eull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG126_REGISTER126 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG126_REGISTER126_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG26 = 0x0000801aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG26_REGISTER26 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG26_REGISTER26_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG39 = 0x00008027ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG39_REGISTER39 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG39_REGISTER39_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG47 = 0x0000802full;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG47_REGISTER47 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG47_REGISTER47_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG5 = 0x00008005ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG5_REGISTER5 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG5_REGISTER5_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG58 = 0x0000803aull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG58_REGISTER58 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG58_REGISTER58_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG70 = 0x00008046ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG70_REGISTER70 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG70_REGISTER70_LEN = 64;
// proc/reg00026.H

static const uint64_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG85 = 0x00008055ull;

static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG85_REGISTER85 = 0;
static const uint32_t TP_TPCHIP_OTPROM_SINGLE_OTP_ROM_REG85_REGISTER85_LEN = 64;
// proc/reg00026.H

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0 = 0x00001000ull;

static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0 = 0;
static const uint32_t TP_TPVSB_FSI_W_FSI2PIB_DATA_REGISTER_0_DATA_REG_0_LEN = 32;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_10_RWX = 0x0000288aull;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M1B_DATA_AREA_4_RWX = 0x00002884ull;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2A_DATA_AREA_2_RWX = 0x000028c2ull;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_14_RWX = 0x0000290eull;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_M2B_DATA_AREA_8_RWX = 0x00002908ull;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_ROX = 0x00002823ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_RWX = 0x00050023ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A =
    0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_1_HEADER_COMMAND_2_A_M1HC2A_MAILBOX_1_HEADER_COMMAND_2_A_LEN
    = 32;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_ROX = 0x0005002full;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_RWX = 0x0000282full;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_2_HEADER_COMMAND_B_M2HC2B_MAILBOX_2_HEADER_COMMAND_B_LEN =
    32;
// proc/reg00026.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW = 0x00002817ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM0_REFCLK_DRVR_EN_DC = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM1_REFCLK_DRVR_EN_DC = 1;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM2_REFCLK_DRVR_EN_DC = 2;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM3_REFCLK_DRVR_EN_DC = 3;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM4_REFCLK_DRVR_EN_DC = 4;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM5_REFCLK_DRVR_EN_DC = 5;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM6_REFCLK_DRVR_EN_DC = 6;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM7_REFCLK_DRVR_EN_DC = 7;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM8_REFCLK_DRVR_EN_DC = 8;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEM9_REFCLK_DRVR_EN_DC = 9;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMA_REFCLK_DRVR_EN_DC = 10;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMB_REFCLK_DRVR_EN_DC = 11;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMC_REFCLK_DRVR_EN_DC = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMD_REFCLK_DRVR_EN_DC = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEME_REFCLK_DRVR_EN_DC = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_MEMF_REFCLK_DRVR_EN_DC = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0A_REFCLK_DRVR_EN_DC = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP0B_REFCLK_DRVR_EN_DC = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3A_REFCLK_DRVR_EN_DC = 18;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP3B_REFCLK_DRVR_EN_DC = 19;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP4_REFCLK_DRVR_EN_DC = 20;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP5_REFCLK_DRVR_EN_DC = 21;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP6_REFCLK_DRVR_EN_DC = 22;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_TP_OP7_REFCLK_DRVR_EN_DC = 23;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_24_SPARE_RESONANT_CLOCKING_CONTROL =
    24;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_25_SPARE_RESONANT_CLOCKING_CONTROL =
    25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_26_SPARE_RESONANT_CLOCKING_CONTROL =
    26;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_27_SPARE_RESONANT_CLOCKING_CONTROL =
    27;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_28_SPARE_RESONANT_CLOCKING_CONTROL =
    28;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_29_SPARE_RESONANT_CLOCKING_CONTROL =
    29;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_30_SPARE_RESONANT_CLOCKING_CONTROL =
    30;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_ROOT_CTRL7_31_SPARE_RESONANT_CLOCKING_CONTROL =
    31;
// proc/reg00027.H

//ERRCODE: // The addresses of this register do not all translate to the same targets.

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI = 0x00002808ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_FSI_BYTE = 0x00002820ull;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SCOM = 0x00050008ull;

static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SECURE_DEBUG_MODE = 0;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR0 = 12;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_START_RESTART_VECTOR1 = 13;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S0 = 14;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_INTERRUPT_S1 = 15;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_BYPASSING_RESET_SEQUENCE_PIB_I2CM = 16;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_SELECT_SECONDARY_SEEPROM = 17;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS = 25;
static const uint32_t TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_SB_CS_DEBUG_BOLT_ON_CONTROL_BITS_LEN = 7;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI = 0x00000c19ull;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FSI_BYTE = 0x00000c64ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_ENABLE = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_DMA_MODE_REGISTER_FIFO_SIZE_EQ_1 = 1;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_ROX = 0x00000c03ull;

static const uint32_t TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG = 0;
static const uint32_t TP_TPVSB_FSI_W_SHIFT_READ_BUFFER_READ_BUFFER_REG_LEN = 32;
// proc/reg00027.H

static const uint64_t TP_TPVSB_FSI_W_SLAVE_CMFSI_INCLUDE_MFSI_A_PIB2OPB_COMP_P_1_LSTAT = 0x00020012ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_FSI0 = 0x00003058ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MAESP2_SCOMFSI0 = 0x00000c16ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_FSI0 = 0x000032e0ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MECTRL_SCOMFSI0 = 0x00000cb8ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MLEVP1_ROX = 0x0000301cull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_RO = 0x000030dcull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0 = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_0_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1 = 5;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_1_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2 = 9;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_0_MSTAP3_2_LEN = 3;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MAEB_RO = 0x00003470ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RW = 0x00003400ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_IPOLL_AND_DMA = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_HW_ERROR_RECOVERY = 1;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_RELATIVE_ADDRESS_CMDS = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_ENABLE_PARITY_CHECK = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0 = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_0_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1 = 14;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_RATE_SELECTION_1_LEN = 10;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_CLOCK_DIV_4 = 25;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL = 26;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_TIMEOUT_SEL_LEN = 2;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MMODE_RECEIVER_MODE_LEN = 3;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MRESP0_WOX = 0x000034d0ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_FSI0 = 0x0000343cull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_MST_1_MSIEP3_SCOMFSI0 = 0x00000d0full;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCI2CM = 0x0000082cull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SCRSIM4 = 0x0000085cull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SOML = 0x0000083cull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_A_SRSIC4 = 0x0000086cull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ROX = 0x000031d0ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FIRST_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST = 17;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_FRST_LEN = 3;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR = 20;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_ACTUAL_ERROR_LEN = 4;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT = 29;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MESRB0_FAILING_OPB_MASTER_ACT_LEN = 3;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_WOX = 0x000030e8ull;

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_GENERAL_RESET_6 = 0;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MRESP6_ERROR_RESET_6 = 1;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_FSI1 = 0x00003044ull;
static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_MST_0_MSIEP5_SCOMFSI1 = 0x00000c11ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SI1M = 0x00000818ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SI2S = 0x00000828ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SLASTD_SRES = 0x00000834ull;
// proc/reg00027.H

static const uint32_t TP_TPVSB_FSI_W_SLAVE_B_SSMBR = 0x00000848ull;
// proc/reg00027.H

static const uint64_t VAS_VA_RG_SCF_CAMDATA1 = 0x02011435ull;

static const uint32_t VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1 = 0;
static const uint32_t VAS_VA_RG_SCF_CAMDATA1_CAM_DISPLAY_REG_1_LEN = 64;
// proc/reg00027.H

static const uint64_t VAS_VA_RG_SCF_DBGCONT = 0x0201142eull;

static const uint32_t VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63 = 0;
static const uint32_t VAS_VA_RG_SCF_DBGCONT_TRACE_BUS_BITS_0_63_LEN = 64;
// proc/reg00027.H

static const uint64_t VAS_VA_RG_SCF_MMIODATA = 0x0201142aull;

static const uint32_t VAS_VA_RG_SCF_MMIODATA_MMIO_DATA = 0;
static const uint32_t VAS_VA_RG_SCF_MMIODATA_MMIO_DATA_LEN = 64;
// proc/reg00027.H

}
}
#include "proc/reg00024.H"
#include "proc/reg00025.H"
#include "proc/reg00026.H"
#include "proc/reg00027.H"
#endif
