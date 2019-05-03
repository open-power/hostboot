/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pauc_f.H $       */
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

#ifndef __p10_scom_pauc_f_H_
#define __p10_scom_pauc_f_H_


namespace scomt
{
namespace pauc
{


static const uint64_t BIST = 0x1003000bull;

static const uint32_t BIST_TC_BIST_START_TEST_DC = 0;
static const uint32_t BIST_TC_SRAM_ABIST_MODE_DC = 1;
static const uint32_t BIST_TC_IOBIST_MODE_DC = 3;
static const uint32_t BIST_BIST_PERV = 4;
static const uint32_t BIST_BIST_UNIT1 = 5;
static const uint32_t BIST_BIST_UNIT2 = 6;
static const uint32_t BIST_BIST_UNIT3 = 7;
static const uint32_t BIST_BIST_UNIT4 = 8;
static const uint32_t BIST_BIST_UNIT5 = 9;
static const uint32_t BIST_BIST_UNIT6 = 10;
static const uint32_t BIST_BIST_UNIT7 = 11;
static const uint32_t BIST_BIST_UNIT8 = 12;
static const uint32_t BIST_BIST_UNIT9 = 13;
static const uint32_t BIST_BIST_UNIT10 = 14;
static const uint32_t BIST_BIST_UNIT11 = 15;
static const uint32_t BIST_BIST_UNIT12 = 16;
static const uint32_t BIST_BIST_UNIT13 = 17;
static const uint32_t BIST_BIST_UNIT14 = 18;
static const uint32_t BIST_BIST_STROBE_WINDOW_EN = 48;
// pauc/reg00015.H

static const uint64_t CPLT_CTRL5_RW = 0x10000005ull;
static const uint64_t CPLT_CTRL5_WO_CLEAR = 0x10000025ull;
static const uint64_t CPLT_CTRL5_WO_OR = 0x10000015ull;

static const uint32_t CPLT_CTRL5_0 = 0;
static const uint32_t CPLT_CTRL5_1 = 1;
static const uint32_t CPLT_CTRL5_2 = 2;
static const uint32_t CPLT_CTRL5_3 = 3;
static const uint32_t CPLT_CTRL5_4 = 4;
static const uint32_t CPLT_CTRL5_5 = 5;
static const uint32_t CPLT_CTRL5_6 = 6;
static const uint32_t CPLT_CTRL5_7 = 7;
static const uint32_t CPLT_CTRL5_8 = 8;
static const uint32_t CPLT_CTRL5_9 = 9;
static const uint32_t CPLT_CTRL5_10 = 10;
static const uint32_t CPLT_CTRL5_11 = 11;
static const uint32_t CPLT_CTRL5_12 = 12;
static const uint32_t CPLT_CTRL5_13 = 13;
static const uint32_t CPLT_CTRL5_14 = 14;
static const uint32_t CPLT_CTRL5_15 = 15;
static const uint32_t CPLT_CTRL5_16 = 16;
static const uint32_t CPLT_CTRL5_17 = 17;
static const uint32_t CPLT_CTRL5_18 = 18;
static const uint32_t CPLT_CTRL5_19 = 19;
// pauc/reg00015.H

static const uint64_t EPS_THERM_WSUB_DTS_RESULT0 = 0x10050000ull;

static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// pauc/reg00015.H

static const uint64_t MULTICAST_GROUP_3 = 0x100f0003ull;

static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP = 3;
static const uint32_t MULTICAST_GROUP_3_MULTICAST3_GROUP_LEN = 3;
// pauc/reg00015.H

static const uint64_t PB_MAILBOX_CTL_REG = 0x1001182eull;

static const uint32_t PB_MAILBOX_CTL_REG_B_VALID = 0;
static const uint32_t PB_MAILBOX_CTL_REG_B_WR_NOT_RD = 1;
static const uint32_t PB_MAILBOX_CTL_REG_B_BAD_ADDR = 2;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_DOWN = 3;
static const uint32_t PB_MAILBOX_CTL_REG_B_CORRUPT = 4;
static const uint32_t PB_MAILBOX_CTL_REG_B_SENT = 5;
static const uint32_t PB_MAILBOX_CTL_REG_B_BAD_WRITE = 6;
static const uint32_t PB_MAILBOX_CTL_REG_B_RESET = 7;
static const uint32_t PB_MAILBOX_CTL_REG_AILBOX_ID = 8;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_ID = 9;
static const uint32_t PB_MAILBOX_CTL_REG_B_LINK_ID_LEN = 3;
static const uint32_t PB_MAILBOX_CTL_REG_B_SPARE = 12;
static const uint32_t PB_MAILBOX_CTL_REG_B_SPARE_LEN = 4;
// pauc/reg00015.H

static const uint64_t PB_TL_LINK_SYN_01_REG = 0x10011812ull;
// pauc/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t PPE_XIRAMDBG = 0x10000013ull;

static const uint32_t PPE_XIRAMDBG_NULL_MSR_SIBRC = 9;
static const uint32_t PPE_XIRAMDBG_NULL_MSR_SIBRC_LEN = 3;
static const uint32_t PPE_XIRAMDBG_NULL_MSR_WE = 14;
static const uint32_t PPE_XIRAMDBG_NULL_MSR_LP = 20;
static const uint32_t PPE_XIRAMDBG_PPE_XIRAMRA_SPRG0 = 32;
static const uint32_t PPE_XIRAMDBG_PPE_XIRAMRA_SPRG0_LEN = 32;
// pauc/reg00015.H

static const uint64_t PROTECT_MODE_REG = 0x100f03feull;

static const uint32_t PROTECT_MODE_REG_READ_PROTECT_ENABLE = 0;
static const uint32_t PROTECT_MODE_REG_WRITE_PROTECT_ENABLE = 1;
// pauc/reg00015.H

//ERRCODE: // Some of the name targets not found in address targets: pauc

static const uint64_t REGS_ZCAL_FIR_MASK_PB = 0x800f90001000003full;

static const uint32_t REGS_ZCAL_FIR_MASK_PB_ZCAL_FIR_ERRS_MASK = 48;
static const uint32_t REGS_ZCAL_FIR_MASK_PB_ZCAL_FIR_ERRS_MASK_LEN = 2;
// pauc/reg00015.H

static const uint64_t TIMEOUT_REG = 0x100f0010ull;
// pauc/reg00015.H

static const uint64_t TRA0_TR0_CONFIG_1 = 0x10010404ull;

static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87 = 0;
static const uint32_t TRA0_TR0_CONFIG_1_CMP_MSK_LT_B_64_TO_87_LEN = 24;
// pauc/reg00015.H

static const uint64_t VITAL_SCAN_OUT = 0x100f0017ull;
// pauc/reg00015.H

}
}
#include "pauc/reg00015.H"
#endif
