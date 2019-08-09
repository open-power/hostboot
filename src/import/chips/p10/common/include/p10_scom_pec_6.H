/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_6.H $        */
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

#ifndef __p10_scom_pec_6_H_
#define __p10_scom_pec_6_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


static const uint64_t CPLT_CONF1_RW = 0x08000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x08000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x08000019ull;

static const uint32_t CPLT_CONF1_LANE_CFG_DC_0H = 0;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_1H = 1;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_2H = 2;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_3H = 3;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_4H = 4;
static const uint32_t CPLT_CONF1_LANE_CFG_DC_5H = 5;
static const uint32_t CPLT_CONF1_IOVALID_DC_8H = 8;
static const uint32_t CPLT_CONF1_IOVALID_DC_9H = 9;
static const uint32_t CPLT_CONF1_IOVALID_DC_10H = 10;
static const uint32_t CPLT_CONF1_RATIO_OVERRIDE_DC = 11;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_12H = 12;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_13H = 13;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_14H = 14;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_15H = 15;
static const uint32_t CPLT_CONF1_APP0_RATIO_DC_16H = 16;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_17H = 17;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_18H = 18;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_19H = 19;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_20H = 20;
static const uint32_t CPLT_CONF1_APP1_RATIO_DC_21H = 21;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_22H = 22;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_23H = 23;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_24H = 24;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_25H = 25;
static const uint32_t CPLT_CONF1_APP2_RATIO_DC_26H = 26;
static const uint32_t CPLT_CONF1_APP3_RATIO_DC_27H = 27;
static const uint32_t CPLT_CONF1_APP3_RATIO_DC_28H = 28;
static const uint32_t CPLT_CONF1_APP3_RATIO_DC_29H = 29;
static const uint32_t CPLT_CONF1_APP3_RATIO_DC_30H = 30;
static const uint32_t CPLT_CONF1_APP3_RATIO_DC_31H = 31;
// pec/reg00006.H

static const uint64_t CPLT_CTRL1_RW = 0x08000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x08000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x08000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_REGION0_FENCE_DC = 4;
static const uint32_t CPLT_CTRL1_REGION1_FENCE_DC = 5;
static const uint32_t CPLT_CTRL1_REGION2_FENCE_DC = 6;
static const uint32_t CPLT_CTRL1_REGION3_FENCE_DC = 7;
static const uint32_t CPLT_CTRL1_REGION4_FENCE_DC = 8;
static const uint32_t CPLT_CTRL1_REGION5_FENCE_DC = 9;
static const uint32_t CPLT_CTRL1_REGION6_FENCE_DC = 10;
static const uint32_t CPLT_CTRL1_REGION7_FENCE_DC = 11;
static const uint32_t CPLT_CTRL1_REGION8_FENCE_DC = 12;
static const uint32_t CPLT_CTRL1_REGION9_FENCE_DC = 13;
static const uint32_t CPLT_CTRL1_REGION10_FENCE_DC = 14;
static const uint32_t CPLT_CTRL1_REGION11_FENCE_DC = 15;
static const uint32_t CPLT_CTRL1_REGION12_FENCE_DC = 16;
static const uint32_t CPLT_CTRL1_REGION13_FENCE_DC = 17;
static const uint32_t CPLT_CTRL1_REGION14_FENCE_DC = 18;
// pec/reg00006.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x080107c3ull;
// pec/reg00006.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x080107c6ull;
// pec/reg00006.H

static const uint64_t EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x08010001ull;

static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_WDATA_PARITY_ERROR = 0;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_ADDRESS_PARITY_ERROR = 1;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_WDATA_PARITY_ERROR = 2;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_DL_RETURN_P0_ERROR = 3;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_RDATA_PARITY_ERROR = 4;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_UL_P0_ERROR = 5;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_INTERFACE_MACHINE = 6;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PARITY_ERROR_ON_P2S_MACHINE = 7;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 8;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 9;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 10;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_WRITE_NVLD = 11;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_READ_NVLD = 12;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PSCOM_PARALLEL_ADDR_INVALID = 13;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_PCB_COMMAND_PARITY_ERROR = 14;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_GENERAL_TIMEOUT = 15;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 16;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_ACCUMULATED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 17;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_WDATA_PARITY_ERROR = 18;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_ADDRESS_PARITY_ERROR = 19;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_WDATA_PARITY_ERROR = 20;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_DL_RETURN_P0_ERROR = 21;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_RDATA_PARITY_ERROR = 22;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_UL_P0_ERROR = 23;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_INTERFACE_MACHINE = 24;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PARITY_ERROR_ON_P2S_MACHINE = 25;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULCCH = 26;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_DLDCH_RETURN = 27;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_TIMEOUT_WHILE_WAITING_FOR_ULDCH = 28;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_WRITE_NVLD = 29;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_READ_NVLD = 30;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PSCOM_PARALLEL_ADDR_INVALID = 31;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_PCB_COMMAND_PARITY_ERROR = 32;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_GENERAL_TIMEOUT = 33;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_ACCESS_VIOLATION = 34;
static const uint32_t EPS_PSC_PSCOM_STATUS_ERROR_REG_TRAPPED_SATELLITE_ACKNOWLEDGE_INVALID_REGISTER = 35;
// pec/reg00006.H

static const uint64_t EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x08010008ull;

static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// pec/reg00006.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x0805001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// pec/reg00006.H

static const uint64_t LOCAL_XSTOP_MASK_RW = 0x08040043ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_CLEAR = 0x08040063ull;
static const uint64_t LOCAL_XSTOP_MASK_WO_OR = 0x08040053ull;

static const uint32_t LOCAL_XSTOP_MASK_01 = 1;
static const uint32_t LOCAL_XSTOP_MASK_02 = 2;
static const uint32_t LOCAL_XSTOP_MASK_03 = 3;
static const uint32_t LOCAL_XSTOP_MASK_04 = 4;
static const uint32_t LOCAL_XSTOP_MASK_05 = 5;
static const uint32_t LOCAL_XSTOP_MASK_06 = 6;
static const uint32_t LOCAL_XSTOP_MASK_07 = 7;
static const uint32_t LOCAL_XSTOP_MASK_08 = 8;
static const uint32_t LOCAL_XSTOP_MASK_09 = 9;
static const uint32_t LOCAL_XSTOP_MASK_10 = 10;
static const uint32_t LOCAL_XSTOP_MASK_11 = 11;
static const uint32_t LOCAL_XSTOP_MASK_12 = 12;
static const uint32_t LOCAL_XSTOP_MASK_13 = 13;
static const uint32_t LOCAL_XSTOP_MASK_14 = 14;
static const uint32_t LOCAL_XSTOP_MASK_15 = 15;
// pec/reg00006.H

static const uint64_t LOCAL_XSTOP_UNMASKED = 0x08040013ull;

static const uint32_t LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN = 1;
static const uint32_t LOCAL_XSTOP_UNMASKED_LOCAL_XSTOP_UNMASKED_IN_LEN = 15;
// pec/reg00006.H

static const uint64_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG = 0x0301180bull;

static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_NOTJUSTOWN_DIS = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_DYN_ADJ_DIS = 1;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_DYN_LVL_ADJ_DIS = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_RTY_CNTR_DIV2_EN = 3;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_MAX_LVL_CNT_QUAL = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_MAX_LVL_CNT_QUAL_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_CNT_THRESHHLD1_QUAL = 8;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_CNT_THRESHHLD1_QUAL_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_CNT_THRESHHLD2_QUAL = 14;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_CNT_THRESHHLD2_QUAL_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_GRP_MSTR_RTY_BACKOFF_EN = 20;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_NOTJUSTOWN_DIS = 21;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_DYN_ADJ_DIS = 22;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_DYN_LVL_ADJ_DIS = 23;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_RTY_CNTR_DIV2_EN = 24;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_MAX_LVL_CNT_QUAL = 25;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_MAX_LVL_CNT_QUAL_LEN = 4;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_CNT_THRESHHLD1_QUAL = 29;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_CNT_THRESHHLD1_QUAL_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_CNT_THRESHHLD2_QUAL = 35;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_CNT_THRESHHLD2_QUAL_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_PERTYBOCTL_REG_SYS_MSTR_RTY_BACKOFF_EN = 41;
// pec/reg00006.H

static const uint64_t PB_PBCQ_PEPBREGS_PMONCTL_REG = 0x03011804ull;

static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_EN = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_EN_LEN = 16;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_ALL_ENGINES = 17;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_STK = 18;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_STK_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_RD_TYPE = 20;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_RD_TYPE_LEN = 2;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE0 = 22;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE0_LEN = 3;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE1 = 25;
static const uint32_t PB_PBCQ_PEPBREGS_PMONCTL_REG_MUX_BYTE1_LEN = 3;
// pec/reg00006.H

static const uint64_t TRA0_TR0_CONFIG_5 = 0x08010408ull;

static const uint32_t TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D_LEN = 24;
// pec/reg00006.H

static const uint64_t TRA0_TR1_CONFIG = 0x08010442ull;

static const uint32_t TRA0_TR1_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA0_TR1_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA0_TR1_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA0_TR1_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA0_TR1_CONFIG_BANK_MODE = 10;
static const uint32_t TRA0_TR1_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA0_TR1_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA0_TR1_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA0_TR1_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA0_TR1_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
static const uint32_t TRA0_TR1_CONFIG_DISABLE_SCOM_TRCTRL_TRARR_RD_ACT = 22;
static const uint32_t TRA0_TR1_CONFIG_MASTER_CLOCK_ENABLE_INT = 23;
// pec/reg00006.H

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00006.H"
#endif
#endif
