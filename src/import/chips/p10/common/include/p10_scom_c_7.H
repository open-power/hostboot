/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_7.H $          */
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

#ifndef __p10_scom_c_7_H_
#define __p10_scom_c_7_H_


namespace scomt
{
namespace c
{


static const uint64_t CPMS_CERRMSK_PPE = 0x00000006c001e140ull;
static const uint64_t CPMS_CERRMSK_RW = 0x200e0e14ull;

static const uint32_t CPMS_CERRMSK_PFET_SEQ_ERR_MASK = 0;
static const uint32_t CPMS_CERRMSK_DDS_ERR_MASK = 1;
static const uint32_t CPMS_CERRMSK_CLK_SYNC_ERR_MASK = 2;
static const uint32_t CPMS_CERRMSK_DPT_ACCESS_MASK = 3;
static const uint32_t CPMS_CERRMSK_SPARE_MASK = 4;
static const uint32_t CPMS_CERRMSK_FTC_EVENT_MASK = 5;
static const uint32_t CPMS_CERRMSK_FTC_EVENT_MASK_LEN = 3;
// c/reg00007.H

static const uint64_t EC_PC_FIR_HOLD_OUT = 0x20020451ull;
// c/reg00007.H

static const uint64_t EC_PC_FIR_RAM_MODEREG = 0x2002044eull;

static const uint32_t EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE = 0;
// c/reg00007.H

static const uint64_t EC_PC_SCR2 = 0x20020488ull;
// c/reg00007.H

static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG = 0x20020453ull;
// c/reg00007.H

static const uint64_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG = 0x20020a40ull;

static const uint32_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA = 0;
static const uint32_t EC_PC_TRACE1_TR0_TRACE_HI_DATA_REG_TRACE_HI_DATA_LEN = 64;
// c/reg00007.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_0 = 0x20020a83ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// c/reg00007.H

static const uint64_t L2TRA_TR1_TRACE_LO_DATA_REG = 0x20020081ull;

static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t L2TRA_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
// c/reg00007.H

static const uint64_t L2TRA_TR1_CONFIG_4 = 0x20020087ull;

static const uint32_t L2TRA_TR1_CONFIG_4_A = 0;
static const uint32_t L2TRA_TR1_CONFIG_4_A_LEN = 24;
static const uint32_t L2TRA_TR1_CONFIG_4_B = 24;
static const uint32_t L2TRA_TR1_CONFIG_4_B_LEN = 24;
// c/reg00007.H

static const uint64_t L3_MISC_L3CERRS_PRD_PURGE_REG = 0x2001060eull;

static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE = 1;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_TTYPE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_NEXT_CE = 5;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_LINE_DEL_ON_ALL_CE = 6;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_BUSY_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER = 12;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_MEMBER_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR = 16;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_PURGE_DIR_ADDR_LEN = 11;
// c/reg00007.H

static const uint64_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD = 0x20010628ull;

static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_VALID = 0;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_VALID = 1;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_VALID = 2;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_VALID = 3;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_VALID = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_VALID = 5;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_VALID = 6;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_VALID = 7;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24 = 8;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_24_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25 = 12;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_25_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26 = 16;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_26_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27 = 20;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_27_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28 = 24;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_28_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29 = 28;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_29_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30 = 32;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_30_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31 = 36;
static const uint32_t L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD_31_LEN = 4;
// c/reg00007.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG = 0x2001064full;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE0_REQ_ACTIVE = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE1_REQ_ACTIVE = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_CORE_OR_SNP_REQ_ACTIVE = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_STATUS_REG_ANY_REQ_ACTIVE = 3;
// c/reg00007.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3 = 0x20010657ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_24_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_25_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_26_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_27_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_28_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_29_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_30_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3_31_LEN = 4;
// c/reg00007.H

static const uint64_t QME_PSCRS3_PPE = 0x00000006c00185c0ull;
static const uint64_t QME_PSCRS3_RW = 0x200e085cull;

static const uint32_t QME_PSCRS3_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS3_SD = 1;
static const uint32_t QME_PSCRS3_ESL = 2;
static const uint32_t QME_PSCRS3_EC = 3;
static const uint32_t QME_PSCRS3_PSLL = 4;
static const uint32_t QME_PSCRS3_PSLL_LEN = 4;
static const uint32_t QME_PSCRS3_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS3_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS3_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS3_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS3_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS3_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS3_ = 14;
static const uint32_t QME_PSCRS3__LEN = 2;
static const uint32_t QME_PSCRS3_MTL = 16;
static const uint32_t QME_PSCRS3_MTL_LEN = 4;
static const uint32_t QME_PSCRS3_RL = 20;
static const uint32_t QME_PSCRS3_RL_LEN = 4;
static const uint32_t QME_PSCRS3_PLS = 24;
static const uint32_t QME_PSCRS3_PLS_LEN = 4;
// c/reg00007.H

static const uint64_t QME_SCSR_PPE = 0x00000006c0018400ull;
static const uint64_t QME_SCSR_PPE1 = 0x00000006c0018430ull;
static const uint64_t QME_SCSR_PPE2 = 0x00000006c0018420ull;
static const uint64_t QME_SCSR_SCOM = 0x200e0840ull;
static const uint64_t QME_SCSR_SCOM1 = 0x200e0843ull;
static const uint64_t QME_SCSR_SCOM2 = 0x200e0842ull;

static const uint32_t QME_SCSR_ASSERT_PM_BLOCK_INTR = 0;
static const uint32_t QME_SCSR_ASSERT_PM_EXIT = 1;
static const uint32_t QME_SCSR_ASSERT_PM_ENTRY_LIMIT = 2;
static const uint32_t QME_SCSR_PC_SPARE_OUT = 3;
static const uint32_t QME_SCSR_HBUS_DISABLE = 4;
static const uint32_t QME_SCSR_L2_PURGE_REQ = 5;
static const uint32_t QME_SCSR_L2_PURGE_ABORT = 6;
static const uint32_t QME_SCSR_L2RCMD_INTF_QUIESCE = 7;
static const uint32_t QME_SCSR_NCU_TLBIE_QUIESCE = 8;
static const uint32_t QME_SCSR_NCU_PURGE_REQ = 9;
static const uint32_t QME_SCSR_NCU_PURGE_ABORT = 10;
static const uint32_t QME_SCSR_CHTM_PURGE_REQ = 11;
static const uint32_t QME_SCSR_PB_PURGE_REQ = 12;
static const uint32_t QME_SCSR_CORE_QUIESCE = 13;
static const uint32_t QME_SCSR_SPARE_MODE = 14;
static const uint32_t QME_SCSR_SRESET_REQ = 15;
static const uint32_t QME_SCSR_ASSERT_SPECIAL_WKUP_DONE = 16;
static const uint32_t QME_SCSR_SPARE_OUT = 17;
static const uint32_t QME_SCSR_SPARE18 = 18;
static const uint32_t QME_SCSR_IGNORE_PMCR_RECENT = 19;
static const uint32_t QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE = 20;
static const uint32_t QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE = 21;
static const uint32_t QME_SCSR_AUTO_PMSR_SHIFT_DIS = 22;
static const uint32_t QME_SCSR_REFRESH_PMSR = 23;
static const uint32_t QME_SCSR_BLOCK_INTR_OUTPUTS = 24;
static const uint32_t QME_SCSR_BLOCK_INTR_INPUTS = 25;
static const uint32_t QME_SCSR_ENABLE_PECE = 26;
static const uint32_t QME_SCSR_CTFS_WKUP_ENABLE = 27;
static const uint32_t QME_SCSR_PM_BLOCK_INTR = 32;
static const uint32_t QME_SCSR_PM_EXIT = 33;
static const uint32_t QME_SCSR_PM_ENTRY_LIMIT = 34;
static const uint32_t QME_SCSR_PC_SPARE_IN = 35;
static const uint32_t QME_SCSR_HBUS_INACTIVE = 36;
static const uint32_t QME_SCSR_L2_PURGE_DONE = 37;
static const uint32_t QME_SCSR_NCU_PURGE_DONE = 41;
static const uint32_t QME_SCSR_CHTM_PURGE_DONE = 43;
static const uint32_t QME_SCSR_PB_PURGE_DONE = 44;
static const uint32_t QME_SCSR_CORE_QUIESCED = 45;
static const uint32_t QME_SCSR_STOP_SHIFT_ACTIVE = 47;
static const uint32_t QME_SCSR_SPECIAL_WKUP_DONE = 48;
static const uint32_t QME_SCSR_SPARE_IN = 49;
static const uint32_t QME_SCSR_PSSCR_POWEROFF_ALLOWED = 50;
static const uint32_t QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN = 2;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING = 52;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN = 4;
static const uint32_t QME_SCSR_PMSR_SHIFT_ACTIVE = 56;
static const uint32_t QME_SCSR_OTHER_DPDES_INTR_PENDING = 57;
static const uint32_t QME_SCSR_PC_UNMASKED_ATTN = 58;
static const uint32_t QME_SCSR_PM_STATE_ACTIVE = 59;
static const uint32_t QME_SCSR_PM_STATE = 60;
static const uint32_t QME_SCSR_PM_STATE_LEN = 4;
// c/reg00007.H

static const uint64_t QME_TFCSR_PPE = 0x00000006c0018800ull;
static const uint64_t QME_TFCSR_PPE1 = 0x00000006c0018830ull;
static const uint64_t QME_TFCSR_PPE2 = 0x00000006c0018820ull;
static const uint64_t QME_TFCSR_SCOM = 0x200e0880ull;
static const uint64_t QME_TFCSR_SCOM1 = 0x200e0883ull;
static const uint64_t QME_TFCSR_SCOM2 = 0x200e0882ull;

static const uint32_t QME_TFCSR_XFER_START = 0;
static const uint32_t QME_TFCSR_TFAC_RESET = 1;
static const uint32_t QME_TFCSR_CORE_NUM = 30;
static const uint32_t QME_TFCSR_CORE_NUM_LEN = 2;
static const uint32_t QME_TFCSR_XFER_RECEIVE_DONE = 32;
static const uint32_t QME_TFCSR_XFER_SENT_DONE = 33;
static const uint32_t QME_TFCSR_INCOMING_ERR = 34;
static const uint32_t QME_TFCSR_RUNTIME_ERR = 35;
static const uint32_t QME_TFCSR_STATE_ERR = 36;
static const uint32_t QME_TFCSR_HDEC_MSB = 59;
static const uint32_t QME_TFCSR_DEC_MSB = 60;
static const uint32_t QME_TFCSR_DEC_MSB_LEN = 4;
// c/reg00007.H

}
}
#include "c/reg00007.H"
#endif
