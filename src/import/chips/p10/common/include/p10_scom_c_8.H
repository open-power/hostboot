/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_8.H $          */
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

#ifndef __p10_scom_c_8_H_
#define __p10_scom_c_8_H_


namespace scomt
{
namespace c
{


static const uint64_t CPMS_CL2_PFETSTAT_PPE = 0x00000006c001e2c0ull;
static const uint64_t CPMS_CL2_PFETSTAT_RO = 0x200e0e2cull;

static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_CL2_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_CL2_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_CL2_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
// c/reg00008.H

static const uint64_t EC_PC_COMMON_SPR_V3_HMER_RW_WAND = 0x20020495ull;
static const uint64_t EC_PC_COMMON_SPR_V3_HMER_WO_OR = 0x20020491ull;

static const uint32_t EC_PC_COMMON_SPR_V3_HMER_MALFUNCTION_ALERT = 0;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_CME_REQUEST = 1;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_PROC_RCVY_DONE = 2;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_TFAC_ERR = 4;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_XSCOM_FAIL = 8;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_XSCOM_DONE = 9;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_PROC_RCVY_AGAIN = 11;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_SCOM_FIR_HMI = 16;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_THD_WAKE_BLOCKED_TM_SUSPEND = 17;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_TRIG_FIR_HMI = 18;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_XSCOM_STATUS = 21;
static const uint32_t EC_PC_COMMON_SPR_V3_HMER_XSCOM_STATUS_LEN = 3;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_HV_STATE = 0x2002040dull;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_SCOMC_EN = 0x2002040aull;
// c/reg00008.H

static const uint64_t EC_PC_PMU_SPRCOR_SHID0 = 0x2002040cull;
// c/reg00008.H

static const uint64_t EC_PC_SCR7 = 0x2002048dull;
// c/reg00008.H

static const uint64_t EC_PC_TRACE2_TR0_CONFIG_5 = 0x20020a88ull;

static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C = 0;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D = 24;
static const uint32_t EC_PC_TRACE2_TR0_CONFIG_5_D_LEN = 24;
// c/reg00008.H

static const uint64_t L2_L2MISC_L2CERRS_TOPOTABLE0 = 0x20020014ull;

static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_VAL = 0;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_VAL = 1;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_VAL = 2;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_VAL = 3;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_VAL = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_VAL = 5;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_VAL = 6;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_VAL = 7;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0 = 8;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_0_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1 = 12;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_1_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2 = 16;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_2_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3 = 20;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_3_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4 = 24;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_4_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5 = 28;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_5_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6 = 32;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_6_LEN = 4;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7 = 36;
static const uint32_t L2_L2MISC_L2CERRS_TOPOTABLE0_7_LEN = 4;
// c/reg00008.H

static const uint64_t L2TRA_TR1_CONFIG_1 = 0x20020084ull;

static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t L2TRA_TR1_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// c/reg00008.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_STAT = 0x20010682ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_IN_PROG = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PURGE_DONE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_CRESP_OV = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_REPAIR = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_BUF_WAIT = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_TRIG_DROPPED_LT = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ADDR_ERROR = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_REC_DROPPED_LT = 7;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_INIT = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PREREQ = 9;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_READY = 10;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_TRACING = 11;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PAUSED = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_FLUSH = 13;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_COMPLETE = 14;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_ENABLE = 15;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_STAMP = 16;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_STAT_STATUS_SCOM_ERROR = 17;
// c/reg00008.H

static const uint64_t PSCOM_STATUS_ERROR_REG = 0x20010001ull;

static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// c/reg00008.H

}
}
#include "c/reg00008.H"
#endif
