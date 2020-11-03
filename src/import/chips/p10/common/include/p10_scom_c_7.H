/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_7.H $          */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

#ifndef __p10_scom_c_7_H_
#define __p10_scom_c_7_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_CERRMSK]
static const uint64_t CPMS_CERRMSK = 0x200e0e14ull;

static const uint32_t CPMS_CERRMSK_PFET_SEQ_ERR_MASK = 0;
static const uint32_t CPMS_CERRMSK_DDS_ERR_MASK = 1;
static const uint32_t CPMS_CERRMSK_CLK_SYNC_ERR_MASK = 2;
static const uint32_t CPMS_CERRMSK_DPT_ACCESS_MASK = 3;
static const uint32_t CPMS_CERRMSK_PROXY_MASK = 4;
static const uint32_t CPMS_CERRMSK_FTC_EVENT_MASK = 5;
static const uint32_t CPMS_CERRMSK_FTC_EVENT_MASK_LEN = 3;
static const uint32_t CPMS_CERRMSK_PITCH_MASK = 8;
static const uint32_t CPMS_CERRMSK_CCFG_PARITY_MASK = 9; // p10:20,
static const uint32_t CPMS_CERRMSK_RVRM_DROPOUT_MASK = 10; // p10:20,
static const uint32_t CPMS_CERRMSK_PITCH_UPDATE_MASK = 11; // p10:20,
static const uint32_t CPMS_CERRMSK_SPARE_MASK = 12; // p10:20,
//<< [CPMS_CERRMSK]
// c/reg00007.H

//>> [EC_PC_FIR_HOLD_OUT]
static const uint64_t EC_PC_FIR_HOLD_OUT = 0x20020451ull;

static const uint32_t EC_PC_FIR_HOLD_OUT_CY_FIR_LOCAL_XSTOP_HOLD_OUT = 0;
static const uint32_t EC_PC_FIR_HOLD_OUT_CY_FIR_RECOV_HOLD_OUT = 1;
static const uint32_t EC_PC_FIR_HOLD_OUT_CY_FIR_SYS_XSTOP_HOLD_OUT = 2;
static const uint32_t EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_REC_HOLD_OUT = 3;
static const uint32_t EC_PC_FIR_HOLD_OUT_FIR_ERR_INJ_XSTP_HOLD_OUT = 4;
static const uint32_t EC_PC_FIR_HOLD_OUT_FIR_PARITY_HOLD_OUT = 5;
static const uint32_t EC_PC_FIR_HOLD_OUT_FIR_SCOM_HOLD_OUT = 6;
static const uint32_t EC_PC_FIR_HOLD_OUT_L2_UE_OVER_THRES_HOLD_OUT = 7;
static const uint32_t EC_PC_FIR_HOLD_OUT_PHYP_ERR_INJ_HOLD_OUT = 8;
static const uint32_t EC_PC_FIR_HOLD_OUT_RAM_EXCEPTION_XSTOP_HOLD_OUT = 9;
static const uint32_t EC_PC_FIR_HOLD_OUT_RAM_INSTR_REG_ACCESS_HOLD_OUT = 10;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_RAM_MODE_HOLD_OUT = 11;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECOV_ERR_DURING_SMT_MODE_CHANGE_HOLD_OUT = 12;
static const uint32_t EC_PC_FIR_HOLD_OUT_ECC_REF_STATE_HOLD_OUT = 13;
static const uint32_t EC_PC_FIR_HOLD_OUT_FWD_PROG_HOLD_OUT = 14;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECONFIG_STATE_HOLD_OUT = 15;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECOV_ABIST_TIMEOUT_HOLD_OUT = 16;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECOV_DISABLED_HOLD_OUT = 17;
static const uint32_t EC_PC_FIR_HOLD_OUT_RCVY_STATE_HOLD_OUT = 18;
static const uint32_t EC_PC_FIR_HOLD_OUT_SD_LOG_XSTOP_HOLD_OUT = 19;
static const uint32_t EC_PC_FIR_HOLD_OUT_XSTOP_ON_DBG_TRIGGER_HOLD_OUT = 20;
static const uint32_t EC_PC_FIR_HOLD_OUT_RECONFIG_ERR_DURING_RAM_MODE_HOLD_OUT = 21;
static const uint32_t EC_PC_FIR_HOLD_OUT_STF_ERR_DURING_RECONFIG_HOLD_OUT = 22;
static const uint32_t EC_PC_FIR_HOLD_OUT_SPR_SCOM_HOLD_OUT = 23; // p10:20,
static const uint32_t EC_PC_FIR_HOLD_OUT_TRACE1_SCOM_HOLD_OUT = 24; // p10:20,
static const uint32_t EC_PC_FIR_HOLD_OUT_TRACE2_SCOM_HOLD_OUT = 25; // p10:20,
//<< [EC_PC_FIR_HOLD_OUT]
// c/reg00007.H

//>> [EC_PC_FIR_RAM_MODEREG]
static const uint64_t EC_PC_FIR_RAM_MODEREG = 0x2002044eull;

static const uint32_t EC_PC_FIR_RAM_MODEREG_RAM_MODE_ENABLE = 0;
//<< [EC_PC_FIR_RAM_MODEREG]
// c/reg00007.H

//>> [EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]
static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG = 0x20020453ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_DIS_PMON_INTR = 56;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTERRUPTS = 57;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_BLOCK_HMI_IN_MAINT = 62;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_MODEREG_FENCE_INTR_ON_CHECKSTOP = 63;
//<< [EC_PC_THRCTL_TCTLCOM_RAS_MODEREG]
// c/reg00007.H

//>> [L3_MISC_L3CERRS_PRD_PURGE_REG]
static const uint64_t L3_MISC_L3CERRS_PRD_PURGE_REG = 0x2001060eull;

static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_REQ = 0;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE = 1;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_TTYPE_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_NEXT_CE = 5;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_LINE_DEL_ON_ALL_CE = 6;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1 = 7;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_1_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_BUSY_ERR = 9;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2 = 10;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_RESERVED_2_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER = 12;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_MEMBER_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR = 16;
static const uint32_t L3_MISC_L3CERRS_PRD_PURGE_REG_L3_PRD_PURGE_DIR_ADDR_LEN = 11;
//<< [L3_MISC_L3CERRS_PRD_PURGE_REG]
// c/reg00007.H

//>> [L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]
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
//<< [L3_MISC_L3CERRS_TOPOLOGY_TBL3_SCOM_RD]
// c/reg00007.H

//>> [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]
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
//<< [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG3]
// c/reg00007.H

//>> [QME_PSCRS3]
static const uint64_t QME_PSCRS3 = 0x200e085cull;

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
static const uint32_t QME_PSCRS3_TR = 14;
static const uint32_t QME_PSCRS3_TR_LEN = 2;
static const uint32_t QME_PSCRS3_MTL = 16;
static const uint32_t QME_PSCRS3_MTL_LEN = 4;
static const uint32_t QME_PSCRS3_RL = 20;
static const uint32_t QME_PSCRS3_RL_LEN = 4;
static const uint32_t QME_PSCRS3_PLS = 24;
static const uint32_t QME_PSCRS3_PLS_LEN = 4;
//<< [QME_PSCRS3]
// c/reg00007.H

//>> [QME_SCSR]
static const uint64_t QME_SCSR = 0x200e0840ull;
static const uint64_t QME_SCSR_SCOM2 = 0x200e0842ull;
static const uint64_t QME_SCSR_WO_CLEAR = 0x200e0843ull;

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
static const uint32_t QME_SCSR_REG_WKUP_FILTER_DIS = 14; // p10:20,
static const uint32_t QME_SCSR_SRESET_REQ = 15;
static const uint32_t QME_SCSR_ASSERT_SPECIAL_WKUP_DONE = 16;
static const uint32_t QME_SCSR_SPARE_OUT = 17;
static const uint32_t QME_SCSR_CORE_INTR_SAMPLE = 18;
static const uint32_t QME_SCSR_IGNORE_PMCR_RECENT = 19;
static const uint32_t QME_SCSR_AUTO_SPECIAL_WAKEUP_DISABLE = 20;
static const uint32_t QME_SCSR_HALTED_STOP_OVERRIDE_DISABLE = 21;
static const uint32_t QME_SCSR_AUTO_PMSR_SHIFT_DIS = 22;
static const uint32_t QME_SCSR_REFRESH_PMSR = 23;
static const uint32_t QME_SCSR_BLOCK_INTR_OUTPUTS = 24;
static const uint32_t QME_SCSR_BLOCK_INTR_INPUTS = 25;
static const uint32_t QME_SCSR_ENABLE_PECE = 26;
static const uint32_t QME_SCSR_CTFS_WKUP_ENABLE = 27;
static const uint32_t QME_SCSR_PC_COPY_FUSED_SPRS = 28; // p10:20,
static const uint32_t QME_SCSR_SINGLE_LPAR_MODE = 31; // p10:20,
static const uint32_t QME_SCSR_PM_BLOCK_INTR = 32;
static const uint32_t QME_SCSR_PM_EXIT = 33;
static const uint32_t QME_SCSR_PM_ENTRY_LIMIT = 34;
static const uint32_t QME_SCSR_PC_SPARE_IN = 35;
static const uint32_t QME_SCSR_HBUS_INACTIVE = 36;
static const uint32_t QME_SCSR_L2_PURGE_DONE = 37;
static const uint32_t QME_SCSR_NCU_PURGE_DONE = 41;
static const uint32_t QME_SCSR_PC_FUSED_COPY_DONE = 42; // p10:20,
static const uint32_t QME_SCSR_CHTM_PURGE_DONE = 43;
static const uint32_t QME_SCSR_PB_PURGE_DONE = 44;
static const uint32_t QME_SCSR_CORE_QUIESCED = 45;
static const uint32_t QME_SCSR_PC_INTR_PENDING = 46;
static const uint32_t QME_SCSR_STOP_SHIFT_ACTIVE = 47;
static const uint32_t QME_SCSR_SPECIAL_WKUP_DONE = 48;
static const uint32_t QME_SCSR_SPARE_IN = 49;
static const uint32_t QME_SCSR_PSSCR_POWEROFF_ALLOWED = 50;
static const uint32_t QME_SCSR_PSSCR_POWEROFF_ALLOWED_LEN = 2;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING = 52;
static const uint32_t QME_SCSR_PC_THREAD_INSTR_RUNNING_LEN = 4;
static const uint32_t QME_SCSR_PMSR_SHIFT_INACTIVE = 56;
static const uint32_t QME_SCSR_OTHER_DPDES_INTR_PENDING = 57;
static const uint32_t QME_SCSR_PC_UNMASKED_ATTN = 58;
static const uint32_t QME_SCSR_PM_STATE_ACTIVE = 59;
static const uint32_t QME_SCSR_PM_STATE = 60;
static const uint32_t QME_SCSR_PM_STATE_LEN = 4;
//<< [QME_SCSR]
// c/reg00007.H

//>> [QME_TFCSR]
static const uint64_t QME_TFCSR = 0x200e0880ull;
static const uint64_t QME_TFCSR_SCOM2 = 0x200e0882ull;
static const uint64_t QME_TFCSR_WO_CLEAR = 0x200e0883ull;

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
//<< [QME_TFCSR]
// c/reg00007.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00007.H"
#endif
#endif
