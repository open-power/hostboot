/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_d.H $        */
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

#ifndef __p10_scom_pec_d_H_
#define __p10_scom_pec_d_H_


namespace scomt
{
namespace pec
{


static const uint64_t CC_ATOMIC_LOCK_REG = 0x080303ffull;

static const uint32_t CC_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CC_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CC_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CC_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// pec/reg00013.H

static const uint64_t CTRL_ATOMIC_LOCK_REG = 0x080003ffull;

static const uint32_t CTRL_ATOMIC_LOCK_REG_LOCK_ENABLE = 0;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID = 1;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ID_LEN = 4;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY = 8;
static const uint32_t CTRL_ATOMIC_LOCK_REG_ACTIVITY_LEN = 8;
// pec/reg00013.H

static const uint64_t EPS_DBG_DEBUG_TRACE_CONTROL = 0x080107d0ull;
// pec/reg00013.H

static const uint64_t EPS_FIR_SUM_MASK_REG = 0x08040017ull;

static const uint32_t EPS_FIR_SUM_MASK_REG_XSTOP_TO_PCB = 0;
static const uint32_t EPS_FIR_SUM_MASK_REG_RECOV_TO_PCB = 1;
static const uint32_t EPS_FIR_SUM_MASK_REG_SPATTN_TO_PCB = 2;
static const uint32_t EPS_FIR_SUM_MASK_REG_LOCAL_XSTOP_TO_PCB = 3;
static const uint32_t EPS_FIR_SUM_MASK_REG_HOSTATTN_TO_PCB = 4;
// pec/reg00013.H

static const uint64_t OPCG_CAPT1 = 0x08030010ull;

static const uint32_t OPCG_CAPT1_COUNT = 0;
static const uint32_t OPCG_CAPT1_COUNT_LEN = 4;
static const uint32_t OPCG_CAPT1_SEQ_01 = 4;
static const uint32_t OPCG_CAPT1_SEQ_01_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_02 = 9;
static const uint32_t OPCG_CAPT1_SEQ_02_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_03 = 14;
static const uint32_t OPCG_CAPT1_SEQ_03_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_04 = 19;
static const uint32_t OPCG_CAPT1_SEQ_04_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_05 = 24;
static const uint32_t OPCG_CAPT1_SEQ_05_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_06 = 29;
static const uint32_t OPCG_CAPT1_SEQ_06_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_07 = 34;
static const uint32_t OPCG_CAPT1_SEQ_07_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_08 = 39;
static const uint32_t OPCG_CAPT1_SEQ_08_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_09 = 44;
static const uint32_t OPCG_CAPT1_SEQ_09_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_10 = 49;
static const uint32_t OPCG_CAPT1_SEQ_10_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_11 = 54;
static const uint32_t OPCG_CAPT1_SEQ_11_LEN = 5;
static const uint32_t OPCG_CAPT1_SEQ_12 = 59;
static const uint32_t OPCG_CAPT1_SEQ_12_LEN = 5;
// pec/reg00013.H

static const uint64_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG = 0x03011801ull;

static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK = 0;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPRIORITYMASK_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_CTAG_DROP_PRIORITY = 6;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_ENABLE_IO_CMD_PACING = 7;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT = 8;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACECOUNT_LEN = 9;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC = 17;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_DROPPACEINC_LEN = 6;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER = 23;
static const uint32_t PB_PBCQ_PEPBREGS_DRPPRICTL_REG_RTYDROPDIVIDER_LEN = 3;
// pec/reg00013.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x080f0000ull;
// pec/reg00013.H

static const uint64_t SCAN_UPDATEDR_LONG = 0x0803b000ull;
// pec/reg00013.H

static const uint64_t TRA0_TR0_CONFIG_9 = 0x08010409ull;

static const uint32_t TRA0_TR0_CONFIG_9_DISABLE_COMPRESSION = 0;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_BIT_COMPRESSION_CARE_MASK = 1;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHA_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL = 4;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHB_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL = 6;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHC_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL = 8;
static const uint32_t TRA0_TR0_CONFIG_9_MATCHD_MUXSEL_LEN = 2;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK = 10;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK = 14;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK = 18;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_OR_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK = 22;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_AND_MASK_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_NOT_MODE = 26;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_NOT_MODE = 27;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE = 28;
static const uint32_t TRA0_TR0_CONFIG_9_MATCH_NOT_MODE_LEN = 4;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_MASK = 32;
static const uint32_t TRA0_TR0_CONFIG_9_ERROR_CMP_PATTERN = 33;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG0_ERR_CMP = 34;
static const uint32_t TRA0_TR0_CONFIG_9_TRIG1_ERR_CMP = 35;
static const uint32_t TRA0_TR0_CONFIG_9_DD1_STRETCH_TRIGGER_PULSES = 36;
// pec/reg00013.H

static const uint64_t TRA0_TR1_CONFIG_0 = 0x08010443ull;

static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63 = 0;
static const uint32_t TRA0_TR1_CONFIG_0_CMP_MSK_LT_B_0_TO_63_LEN = 64;
// pec/reg00013.H

}
}
#include "pec/reg00013.H"
#endif
