/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_c.H $       */
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

#ifndef __p10_scom_pauc_c_H_
#define __p10_scom_pauc_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pauc
{
#endif


//>> [CPLT_CTRL2]
static const uint64_t CPLT_CTRL2_RW = 0x10000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x10000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x10000012ull;

static const uint32_t CPLT_CTRL2_0_PGOOD = 4;
static const uint32_t CPLT_CTRL2_1_PGOOD = 5;
static const uint32_t CPLT_CTRL2_2_PGOOD = 6;
static const uint32_t CPLT_CTRL2_3_PGOOD = 7;
static const uint32_t CPLT_CTRL2_4_PGOOD = 8;
static const uint32_t CPLT_CTRL2_5_PGOOD = 9;
static const uint32_t CPLT_CTRL2_6_PGOOD = 10;
static const uint32_t CPLT_CTRL2_7_PGOOD = 11;
static const uint32_t CPLT_CTRL2_8_PGOOD = 12;
static const uint32_t CPLT_CTRL2_9_PGOOD = 13;
static const uint32_t CPLT_CTRL2_10_PGOOD = 14;
static const uint32_t CPLT_CTRL2_11_PGOOD = 15;
static const uint32_t CPLT_CTRL2_12_PGOOD = 16;
static const uint32_t CPLT_CTRL2_13_PGOOD = 17;
static const uint32_t CPLT_CTRL2_14_PGOOD = 18;
//<< [CPLT_CTRL2]
// pauc/reg00012.H

//>> [CPLT_MASK0]
static const uint64_t CPLT_MASK0 = 0x10000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
//<< [CPLT_MASK0]
// pauc/reg00012.H

//>> [CTRL_PROTECT_MODE_REG]
static const uint64_t CTRL_PROTECT_MODE_REG = 0x100003feull;

static const uint32_t CTRL_PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t CTRL_PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
//<< [CTRL_PROTECT_MODE_REG]
// pauc/reg00012.H

//>> [DL_PPE_WRAP_MIB_XIICAC]
static const uint64_t DL_PPE_WRAP_MIB_XIICAC = 0x10012c59ull;

static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_TAG_ADDR = 0;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_TAG_ADDR_LEN = 27;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_ERR = 32;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_PIB_IFETCH_PENDING = 34;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_MIB_XIMEM_MEM_IFETCH_PENDING = 35;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_VALID = 36;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_VALID_LEN = 4;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_LINE2_VALID = 40;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_LINE2_VALID_LEN = 4;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_LINE_PTR = 45;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_LINE2_ERR = 46;
static const uint32_t DL_PPE_WRAP_MIB_XIICAC_ICACHE_PREFETCH_PENDING = 47;
//<< [DL_PPE_WRAP_MIB_XIICAC]
// pauc/reg00012.H

//>> [EPS_DBG_MODE_REG]
static const uint64_t EPS_DBG_MODE_REG = 0x100107c0ull;

static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE = 0;
static const uint32_t EPS_DBG_MODE_REG_GLB_BRCST_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE = 3;
static const uint32_t EPS_DBG_MODE_REG_TRACE_SEL_MODE_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE = 6;
static const uint32_t EPS_DBG_MODE_REG_TRIG_SEL_MODE_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_XSTOP_SELECTION = 8;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_RECOV_ERR_SELECTION = 9;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_SPATTN_SELECTION = 10;
static const uint32_t EPS_DBG_MODE_REG_STOP_ON_HOSTATTN_SELECTION = 11;
static const uint32_t EPS_DBG_MODE_REG_FREEZE_SEL_MODE = 12;
static const uint32_t EPS_DBG_MODE_REG_MASTER_CLOCK_ENABLE = 13;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_ON = 16;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS = 17;
static const uint32_t EPS_DBG_MODE_REG_TRACE_RUN_STATUS_LEN = 2;
static const uint32_t EPS_DBG_MODE_REG_IS_FROZEN_STATUS = 19;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS = 20;
static const uint32_t EPS_DBG_MODE_REG_INST1_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS = 23;
static const uint32_t EPS_DBG_MODE_REG_INST2_CONDITION_HISTORY_STATUS_LEN = 3;
static const uint32_t EPS_DBG_MODE_REG_UNUSED = 26;
static const uint32_t EPS_DBG_MODE_REG_UNUSED_LEN = 6;
//<< [EPS_DBG_MODE_REG]
// pauc/reg00012.H

//>> [EPS_FIR_CLKSTOP_ON_XSTOP_MASK5]
static const uint64_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5 = 0x10040085ull;

static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_XSTOP_ERR = 0;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_RECOV_ERR = 1;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SPATTN_ERR = 2;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_LXSTOP_ERR = 3;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_HOSTATTN_ERR = 4;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_ERR = 5;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_SYS_XSTOP_STAGED_ERR = 6;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_DBG_TRIG_ERR = 7;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP01 = 12;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP02 = 13;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP03 = 14;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP04 = 15;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP05 = 16;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP06 = 17;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP07 = 18;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP08 = 19;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP09 = 20;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP10 = 21;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP11 = 22;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP12 = 23;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP13 = 24;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP14 = 25;
static const uint32_t EPS_FIR_CLKSTOP_ON_XSTOP_MASK5_UNIT_TC_FIR_LOCAL_XSTOP15 = 26;
//<< [EPS_FIR_CLKSTOP_ON_XSTOP_MASK5]
// pauc/reg00012.H

//>> [EPS_PSC_WRITE_PROTECT_ENABLE_REG]
static const uint64_t EPS_PSC_WRITE_PROTECT_ENABLE_REG = 0x10010005ull;

static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_ENABLE_RING_LOCKING = 0;
static const uint32_t EPS_PSC_WRITE_PROTECT_ENABLE_REG_RESERVED_RING_LOCKING = 1;
//<< [EPS_PSC_WRITE_PROTECT_ENABLE_REG]
// pauc/reg00012.H

//>> [HOSTATTN_UNMASKED]
static const uint64_t HOSTATTN_UNMASKED = 0x10040014ull;

static const uint32_t HOSTATTN_UNMASKED_IN = 1;
static const uint32_t HOSTATTN_UNMASKED_IN_LEN = 53;
//<< [HOSTATTN_UNMASKED]
// pauc/reg00012.H

//>> [MULTICAST_GROUP_4]
static const uint64_t MULTICAST_GROUP_4 = 0x100f0004ull;

static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP = 3;
static const uint32_t MULTICAST_GROUP_4_MULTICAST4_GROUP_LEN = 3;
//<< [MULTICAST_GROUP_4]
// pauc/reg00012.H

//>> [PB_PMU2_TLPM_COUNTER]
static const uint64_t PB_PMU2_TLPM_COUNTER = 0x1001181dull;

static const uint32_t PB_PMU2_TLPM_COUNTER_0 = 0;
static const uint32_t PB_PMU2_TLPM_COUNTER_0_LEN = 16;
static const uint32_t PB_PMU2_TLPM_COUNTER_1 = 16;
static const uint32_t PB_PMU2_TLPM_COUNTER_1_LEN = 16;
static const uint32_t PB_PMU2_TLPM_COUNTER_2 = 32;
static const uint32_t PB_PMU2_TLPM_COUNTER_2_LEN = 16;
static const uint32_t PB_PMU2_TLPM_COUNTER_3 = 48;
static const uint32_t PB_PMU2_TLPM_COUNTER_3_LEN = 16;
//<< [PB_PMU2_TLPM_COUNTER]
// pauc/reg00012.H

//>> [PB_PR0123_ERR]
static const uint64_t PB_PR0123_ERR = 0x10011829ull;

static const uint32_t PB_PR0123_ERR_0_ADDRESS_PTY = 0;
static const uint32_t PB_PR0123_ERR_0_ATAG_PTY = 1;
static const uint32_t PB_PR0123_ERR_0_CC0_CREDITERR = 2;
static const uint32_t PB_PR0123_ERR_0_CC1_CREDITERR = 3;
static const uint32_t PB_PR0123_ERR_0_CC2_CREDITERR = 4;
static const uint32_t PB_PR0123_ERR_0_CC3_CREDITERR = 5;
static const uint32_t PB_PR0123_ERR_0_CONTROL_ERROR = 6;
static const uint32_t PB_PR0123_ERR_0_DATA_PTY_ERR = 7;
static const uint32_t PB_PR0123_ERR_0_RTAG_MISC_PTY = 8;
static const uint32_t PB_PR0123_ERR_0_RTAG_PTY = 9;
static const uint32_t PB_PR0123_ERR_0_TTAG_PTY = 10;
static const uint32_t PB_PR0123_ERR_0_VC0_CREDITERR = 11;
static const uint32_t PB_PR0123_ERR_0_VC1_CREDITERR = 12;
static const uint32_t PB_PR0123_ERR_0_LINK_DOWN = 13;
static const uint32_t PB_PR0123_ERR_1_ADDRESS_PTY = 16;
static const uint32_t PB_PR0123_ERR_1_ATAG_PTY = 17;
static const uint32_t PB_PR0123_ERR_1_CC0_CREDITERR = 18;
static const uint32_t PB_PR0123_ERR_1_CC1_CREDITERR = 19;
static const uint32_t PB_PR0123_ERR_1_CC2_CREDITERR = 20;
static const uint32_t PB_PR0123_ERR_1_CC3_CREDITERR = 21;
static const uint32_t PB_PR0123_ERR_1_CONTROL_ERROR = 22;
static const uint32_t PB_PR0123_ERR_1_DATA_PTY_ERR = 23;
static const uint32_t PB_PR0123_ERR_1_RTAG_MISC_PTY = 24;
static const uint32_t PB_PR0123_ERR_1_RTAG_PTY = 25;
static const uint32_t PB_PR0123_ERR_1_TTAG_PTY = 26;
static const uint32_t PB_PR0123_ERR_1_VC0_CREDITERR = 27;
static const uint32_t PB_PR0123_ERR_1_VC1_CREDITERR = 28;
static const uint32_t PB_PR0123_ERR_1_LINK_DOWN = 29;
static const uint32_t PB_PR0123_ERR_2_ADDRESS_PTY = 32;
static const uint32_t PB_PR0123_ERR_2_ATAG_PTY = 33;
static const uint32_t PB_PR0123_ERR_2_CC0_CREDITERR = 34;
static const uint32_t PB_PR0123_ERR_2_CC1_CREDITERR = 35;
static const uint32_t PB_PR0123_ERR_2_CC2_CREDITERR = 36;
static const uint32_t PB_PR0123_ERR_2_CC3_CREDITERR = 37;
static const uint32_t PB_PR0123_ERR_2_CONTROL_ERROR = 38;
static const uint32_t PB_PR0123_ERR_2_DATA_PTY_ERR = 39;
static const uint32_t PB_PR0123_ERR_2_RTAG_MISC_PTY = 40;
static const uint32_t PB_PR0123_ERR_2_RTAG_PTY = 41;
static const uint32_t PB_PR0123_ERR_2_TTAG_PTY = 42;
static const uint32_t PB_PR0123_ERR_2_VC0_CREDITERR = 43;
static const uint32_t PB_PR0123_ERR_2_VC1_CREDITERR = 44;
static const uint32_t PB_PR0123_ERR_2_LINK_DOWN = 45;
static const uint32_t PB_PR0123_ERR_3_ADDRESS_PTY = 48;
static const uint32_t PB_PR0123_ERR_3_ATAG_PTY = 49;
static const uint32_t PB_PR0123_ERR_3_CC0_CREDITERR = 50;
static const uint32_t PB_PR0123_ERR_3_CC1_CREDITERR = 51;
static const uint32_t PB_PR0123_ERR_3_CC2_CREDITERR = 52;
static const uint32_t PB_PR0123_ERR_3_CC3_CREDITERR = 53;
static const uint32_t PB_PR0123_ERR_3_CONTROL_ERROR = 54;
static const uint32_t PB_PR0123_ERR_3_DATA_PTY_ERR = 55;
static const uint32_t PB_PR0123_ERR_3_RTAG_MISC_PTY = 56;
static const uint32_t PB_PR0123_ERR_3_RTAG_PTY = 57;
static const uint32_t PB_PR0123_ERR_3_TTAG_PTY = 58;
static const uint32_t PB_PR0123_ERR_3_VC0_CREDITERR = 59;
static const uint32_t PB_PR0123_ERR_3_VC1_CREDITERR = 60;
static const uint32_t PB_PR0123_ERR_3_LINK_DOWN = 61;
//<< [PB_PR0123_ERR]
// pauc/reg00012.H

//>> [PB_PSAVE23_MISC_CFG]
static const uint64_t PB_PSAVE23_MISC_CFG = 0x10011817ull;

static const uint32_t PB_PSAVE23_MISC_CFG_HALF_LUC = 0;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_LUC_LEN = 8;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_HUC = 8;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_HUC_LEN = 8;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_LUT = 16;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_LUT_LEN = 5;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_HUT = 21;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_HUT_LEN = 5;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_SPARE = 26;
static const uint32_t PB_PSAVE23_MISC_CFG_HALF_SPARE_LEN = 2;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_LUC = 28;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_LUC_LEN = 8;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_HUC = 36;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_HUC_LEN = 8;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_LUT = 44;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_LUT_LEN = 5;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_HUT = 49;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_HUT_LEN = 5;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_SPARE = 54;
static const uint32_t PB_PSAVE23_MISC_CFG_QTR_SPARE_LEN = 2;
static const uint32_t PB_PSAVE23_MISC_CFG_WSIZE = 56;
static const uint32_t PB_PSAVE23_MISC_CFG_WSIZE_LEN = 3;
//<< [PB_PSAVE23_MISC_CFG]
// pauc/reg00012.H

//>> [PCB_OPCG_STOP]
static const uint64_t PCB_OPCG_STOP = 0x10030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
//<< [PCB_OPCG_STOP]
// pauc/reg00012.H

//>> [PRE_COUNTER_REG]
static const uint64_t PRE_COUNTER_REG = 0x100f0028ull;

static const uint32_t PRE_COUNTER_REG_PRE_COUNTER = 0;
static const uint32_t PRE_COUNTER_REG_PRE_COUNTER_LEN = 8;
//<< [PRE_COUNTER_REG]
// pauc/reg00012.H

//>> [SCAN64CONTSCAN]
static const uint64_t SCAN64CONTSCAN = 0x1003f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
//<< [SCAN64CONTSCAN]
// pauc/reg00012.H

//>> [TRA0_TR1_TRACE_LO_DATA_REG]
static const uint64_t TRA0_TR1_TRACE_LO_DATA_REG = 0x10010441ull;

static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA = 0;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LO_DATA_LEN = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS = 32;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_ADDRESS_LEN = 10;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK = 42;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_LEN = 9;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_LAST_BANK_VALID = 51;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_WRITE_ON_RUN = 52;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_RUNNING = 53;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS = 54;
static const uint32_t TRA0_TR1_TRACE_LO_DATA_REG_HOLD_ADDRESS_LEN = 10;
//<< [TRA0_TR1_TRACE_LO_DATA_REG]
// pauc/reg00012.H

//>> [TRA1_TR0_CONFIG_9]
static const uint64_t TRA1_TR0_CONFIG_9 = 0x10010489ull;

static const uint32_t TRA1_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA1_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA1_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA1_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA1_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA1_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
static const uint32_t TRA1_TR0_CONFIG_9_SPARE_LT = 37;
//<< [TRA1_TR0_CONFIG_9]
// pauc/reg00012.H

//>> [XSTOP_INTERRUPT_REG]
static const uint64_t XSTOP_INTERRUPT_REG = 0x100f001cull;

static const uint32_t XSTOP_INTERRUPT_REG_XSTOP = 0;
//<< [XSTOP_INTERRUPT_REG]
// pauc/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pauc/reg00012.H"
#endif
#endif
