/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_c.H $          */
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

#ifndef __p10_scom_c_c_H_
#define __p10_scom_c_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_CGCSR]
static const uint64_t CPMS_CGCSR = 0x200e0e00ull;
static const uint64_t CPMS_CGCSR_WO_CLEAR = 0x200e0e03ull;
static const uint64_t CPMS_CGCSR_WO_OR = 0x200e0e02ull;

static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_ENABLE = 0;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_ENABLE = 1;
static const uint32_t CPMS_CGCSR_RESERVED_2_3 = 2;
static const uint32_t CPMS_CGCSR_RESERVED_2_3_LEN = 2;
static const uint32_t P10_20_CPMS_CGCSR_ANALOG_SENSOR_INPUT_GATE = 2; // p10:20,
static const uint32_t P10_20_CPMS_CGCSR_PFET_SENSE_INPUT_GATE = 3; // p10:20,
static const uint32_t CPMS_CGCSR_L3_CLKGLM_ASYNC_RESET = 4;
static const uint32_t CPMS_CGCSR_L3_CLKGLM_SEL = 7;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_ASYNC_RESET = 8;
static const uint32_t CPMS_CGCSR_CL2_CLKGLM_SEL = 11;
static const uint32_t CPMS_CGCSR_L3_CACHE_SB_CTRL = 12;
static const uint32_t CPMS_CGCSR_L3_CACHE_SB_CTRL_LEN = 4;
static const uint32_t CPMS_CGCSR_L3_CLK_SYNC_DONE = 32;
static const uint32_t CPMS_CGCSR_CL2_CLK_SYNC_DONE = 33;
//<< [CPMS_CGCSR]
// c/reg00012.H

//>> [CPMS_DHCR]
static const uint64_t CPMS_DHCR = 0x200e0e54ull;

static const uint32_t CPMS_DHCR_FREEZE_HISTORY_ON_LARGE = 0;
static const uint32_t CPMS_DHCR_RESET_DHDR_ON_FDIR_WRITE = 1;
static const uint32_t CPMS_DHCR_ADJACENT_WARN_RECORD_MODE = 2;
static const uint32_t CPMS_DHCR_SPARE = 3;
static const uint32_t CPMS_DHCR_SPARE_LEN = 2;
static const uint32_t CPMS_DHCR_EVENT_HISTORY_SELECT = 5;
static const uint32_t CPMS_DHCR_EVENT_HISTORY_SELECT_LEN = 3;
static const uint32_t CPMS_DHCR_EVENT_COUNT = 8;
static const uint32_t CPMS_DHCR_EVENT_COUNT_LEN = 8;
//<< [CPMS_DHCR]
// c/reg00012.H

//>> [EC_PC_COMMON_SPR_SCOMC]
static const uint64_t EC_PC_COMMON_SPR_SCOMC = 0x20020480ull;

static const uint32_t EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC = 54;
static const uint32_t EC_PC_COMMON_SPR_SCOMC_MODE_CX_SCOMC_LEN = 7;
//<< [EC_PC_COMMON_SPR_SCOMC]
// c/reg00012.H

//>> [EC_PC_THRCTL_TCTLCOM_RAS_STATUS]
static const uint64_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS = 0x20020454ull;

static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_CORE_MAINT = 0;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_THREAD_QUIESCED = 1;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_ICT_EMPTY = 2;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_LSU_QUIESCED = 3;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_STEP_SUCCESS = 4;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT0_MACHINE_DRAINED = 5;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_CORE_MAINT = 8;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_THREAD_QUIESCED = 9;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_ICT_EMPTY = 10;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_LSU_QUIESCED = 11;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_STEP_SUCCESS = 12;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT1_MACHINE_DRAINED = 13;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_CORE_MAINT = 16;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_THREAD_QUIESCED = 17;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_ICT_EMPTY = 18;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_LSU_QUIESCED = 19;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_STEP_SUCCESS = 20;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT2_MACHINE_DRAINED = 21;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_CORE_MAINT = 24;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_THREAD_QUIESCED = 25;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_ICT_EMPTY = 26;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_LSU_QUIESCED = 27;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_STEP_SUCCESS = 28;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_VT3_MACHINE_DRAINED = 29;
static const uint32_t EC_PC_THRCTL_TCTLCOM_RAS_STATUS_NEST_ACTIVE = 32;
//<< [EC_PC_THRCTL_TCTLCOM_RAS_STATUS]
// c/reg00012.H

//>> [L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]
static const uint64_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG = 0x2002000full;

static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TRIGGER = 0;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE = 1;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_TYPE_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_REG_BUSY = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY_ON_THIS = 10;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_PRGSM_BUSY = 11;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM = 16;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_MEM_LEN = 3;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC = 19;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_CGC_LEN = 9;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_BANK = 28;
static const uint32_t L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG_ERR = 29;
//<< [L2_L2MISC_L2CERRS_PHYP_PURGE_CMD_REG]
// c/reg00012.H

//>> [NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]
static const uint64_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG = 0x20010651ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_ADDR_LEN = 40;
//<< [NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG]
// c/reg00012.H

//>> [NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG]
static const uint64_t NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG = 0x20010658ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG_NCU_RCMD_QUIESCE = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG_SPARE = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG_SPARE_LEN = 3;
//<< [NC_NCMISC_NCSCOMS_NCU_RCMD_QUIESCE_REG]
// c/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00012.H"
#endif
#endif
