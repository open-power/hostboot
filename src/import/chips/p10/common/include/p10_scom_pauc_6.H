/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_6.H $       */
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

#ifndef __p10_scom_pauc_6_H_
#define __p10_scom_pauc_6_H_


namespace scomt
{
namespace pauc
{


static const uint64_t CPLT_CONF1_RW = 0x10000009ull;
static const uint64_t CPLT_CONF1_WO_CLEAR = 0x10000029ull;
static const uint64_t CPLT_CONF1_WO_OR = 0x10000019ull;

static const uint32_t CPLT_CONF1_0_IOVALID_DC = 0;
static const uint32_t CPLT_CONF1_1_IOVALID_DC = 1;
static const uint32_t CPLT_CONF1_2_IOVALID_DC = 2;
static const uint32_t CPLT_CONF1_3_IOVALID_DC = 3;
// pauc/reg00006.H

static const uint64_t CPLT_CTRL1_RW = 0x10000001ull;
static const uint64_t CPLT_CTRL1_WO_CLEAR = 0x10000021ull;
static const uint64_t CPLT_CTRL1_WO_OR = 0x10000011ull;

static const uint32_t CPLT_CTRL1_UNIT_MULTICYCLE_TEST_FENCE_DC = 0;
static const uint32_t CPLT_CTRL1_VITL_FENCE_DC = 3;
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
// pauc/reg00006.H

static const uint64_t EPS_DBG_INST1_COND_REG_3 = 0x100107c3ull;
// pauc/reg00006.H

static const uint64_t EPS_DBG_INST2_COND_REG_3 = 0x100107c6ull;
// pauc/reg00006.H

static const uint64_t EPS_FIR_GXSTOP0_MASK_REG = 0x10040013ull;

static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_XSTOP = 0;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_RECOV = 1;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_SPATTN = 2;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_LOCAL_XSTOP = 3;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SUM_TYPE4 = 4;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_SYSTEM_XSTOP = 5;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_OOB1 = 6;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_DBG_FIR_XSTOP_ON_TRIG = 7;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_GXSTOP0_MASK_REG_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
// pauc/reg00006.H

static const uint64_t EPS_PSC_PSCOM_STATUS_ERROR_REG = 0x10010001ull;

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
// pauc/reg00006.H

static const uint64_t EPS_PSC_RING_FENCE_MASK_LATCH_REG = 0x10010008ull;

static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK = 1;
static const uint32_t EPS_PSC_RING_FENCE_MASK_LATCH_REG_RING_FENCE_ENABLE_MASK_LEN = 31;
// pauc/reg00006.H

static const uint64_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ = 0x1005001cull;

static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE = 0;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_VALUE_LEN = 44;
static const uint32_t EPS_THERM_WSUB_TIMESTAMP_COUNTER_READ_OVERFLOW_ERR = 44;
// pauc/reg00006.H

static const uint64_t LOCAL_XSTOP_MASK = 0x10040019ull;

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
// pauc/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t PPE_MIB_XIICAC = 0x10000019ull;

static const uint32_t PPE_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING = 35;
// pauc/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t PPE_XIXCR = 0x10000010ull;

static const uint32_t PPE_XIXCR_PPE_XIXCR_XCR = 1;
static const uint32_t PPE_XIXCR_PPE_XIXCR_XCR_LEN = 3;
static const uint32_t PPE_XIXCR_NULL_CTR = 32;
static const uint32_t PPE_XIXCR_NULL_CTR_LEN = 32;
// pauc/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL3_PB = 0x800f14001000003full;
// pauc/reg00006.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_TX_IMPCAL_SWO7_PB = 0x800f64001000003full;

static const uint32_t REGS_TX_IMPCAL_SWO7_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_16_31 = 48;
static const uint32_t REGS_TX_IMPCAL_SWO7_PB_TX_ZCAL_SWO_IMP_CNTL_1R_1XP_16_31_LEN = 16;
// pauc/reg00006.H

static const uint64_t TRA0_TR0_CONFIG_5 = 0x10010408ull;

static const uint32_t TRA0_TR0_CONFIG_5_C = 0;
static const uint32_t TRA0_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D = 24;
static const uint32_t TRA0_TR0_CONFIG_5_D_LEN = 24;
// pauc/reg00006.H

static const uint64_t TRA0_TR1_CONFIG = 0x10010442ull;

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
// pauc/reg00006.H

static const uint64_t TRA1_TR0_CONFIG = 0x10010482ull;

static const uint32_t TRA1_TR0_CONFIG_STORE_ON_TRIG_MODE = 0;
static const uint32_t TRA1_TR0_CONFIG_WRITE_ON_RUN_MODE = 1;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE = 2;
static const uint32_t TRA1_TR0_CONFIG_EXTEND_TRIG_MODE_LEN = 8;
static const uint32_t TRA1_TR0_CONFIG_BANK_MODE = 10;
static const uint32_t TRA1_TR0_CONFIG_ENH_TRACE_MODE = 11;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL = 12;
static const uint32_t TRA1_TR0_CONFIG_LOCAL_CLOCK_GATE_CONTROL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL = 14;
static const uint32_t TRA1_TR0_CONFIG_TRACE_SELECT_CONTROL_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_HOLD_OFF = 18;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STATUS = 19;
static const uint32_t TRA1_TR0_CONFIG_TRACE_RUN_STICKY = 20;
static const uint32_t TRA1_TR0_CONFIG_DISABLE_BANK_EDGE_DETECT = 21;
// pauc/reg00006.H

}
}
#include "pauc/reg00006.H"
#endif
