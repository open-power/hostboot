/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_5.H $          */
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

#ifndef __p10_scom_c_5_H_
#define __p10_scom_c_5_H_


namespace scomt
{
namespace c
{


static const uint64_t ADDR_TRAP_REG = 0x20010003ull;

static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR = 0;
static const uint32_t ADDR_TRAP_REG_PCB_ADDRESS_OF_LAST_TRANSACTION_WITH_ERROR_LEN = 16;
static const uint32_t ADDR_TRAP_REG_PCB_READ_NOTWRITE_OF_LAST_TRANSACTION_WITH_ERROR = 16;
static const uint32_t ADDR_TRAP_REG_RESERVED_ADDR_LAST_TRAP_LT = 17;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR = 18;
static const uint32_t ADDR_TRAP_REG_SERIAL2PARALLEL_STATE_MACHINE_AT_TIME_OF_ERROR_LEN = 13;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_RETURN_PARITY = 31;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_WRITE_PARITY_ERROR = 32;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_ACCESS_VIOLATION = 33;
static const uint32_t ADDR_TRAP_REG_SATELLITE_ACKNOWLEDGE_BIT_INVALID_REGISTER = 34;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID = 35;
static const uint32_t ADDR_TRAP_REG_LAST_MASTERID_LEN = 4;
// c/reg00005.H

static const uint64_t EC_PC_PMU_SPRCOR_CORE_FUSES = 0x2002040eull;
// c/reg00005.H

static const uint64_t EC_PC_SPURR_FREQ_REF = 0x200204a1ull;

static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE = 0;
static const uint32_t EC_PC_SPURR_FREQ_REF_FREQUENCY_REFERENCE_LEN = 8;
// c/reg00005.H

static const uint64_t EC_PC_TOD_SYNC001 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC001_CHIP_TOD_STATUS_LEN = 4;
// c/reg00005.H

static const uint64_t EC_PC_TOD_SYNC110 = 0x200204a3ull;

static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS = 60;
static const uint32_t EC_PC_TOD_SYNC110_CHIP_TOD_STATUS_LEN = 4;
// c/reg00005.H

static const uint64_t EC_PC_TRACE1_TR0_CONFIG_3 = 0x20020a46ull;

static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_C = 0;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_C_LEN = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_D = 24;
static const uint32_t EC_PC_TRACE1_TR0_CONFIG_3_D_LEN = 24;
// c/reg00005.H

static const uint64_t L2TRA_TR0_CONFIG_5 = 0x20020048ull;

static const uint32_t L2TRA_TR0_CONFIG_5_C = 0;
static const uint32_t L2TRA_TR0_CONFIG_5_C_LEN = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D = 24;
static const uint32_t L2TRA_TR0_CONFIG_5_D_LEN = 24;
// c/reg00005.H

static const uint64_t L3_MISC_L3CERRS_ERR_INJ_REG = 0x2001060dull;

static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_CAC_ERR_INJ = 0;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_CAC_ERR_INJ = 1;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_CAC_ERR_INJ_TYPE_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_DIR_ERR_INJ = 4;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_DIR_ERR_INJ = 5;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_DIR_ERR_INJ_TYPE = 6;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SINGLE_LRU_ERR_INJ = 7;
static const uint32_t L3_MISC_L3CERRS_ERR_INJ_REG_SOLID_LRU_ERR_INJ = 8;
// c/reg00005.H

static const uint64_t L3_MISC_L3CERRS_MODE_REG0 = 0x2001062bull;

static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DISABLED_CFG = 0;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DMAP_CI_EN_CFG = 1;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__RDSN_LINEDEL_UE_EN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__NO_ALLOCATE_MODE_EN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__NO_ALLOCATE_MODE_ACTIVE = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_PF_CFG_SKIP_GRP_SCOPE_EN = 5;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_CO_MEM_ME_BEHAVIOR_CFG = 6;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_CO_MEM_ME_BEHAVIOR_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__LCO_RTY_LIMIT_DISABLE = 8;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__ADDR_HASH_EN_CFG = 11;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__MSTR_RTY_BACKOFF_EN_CFG = 12;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0_CERRS_LCO_RETRY_THROTL_DIS = 13;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__HANG_POLL_PULSE_DIV = 14;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__HANG_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DATA_POLL_PULSE_DIV = 18;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DATA_POLL_PULSE_DIV_LEN = 4;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CFG_CHIP_ADDR_EXT_MASK_EN = 23;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CFG_CHIP_ADDR_EXT_MASK_EN_LEN = 7;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_EN_CFG = 30;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_PROB_SEL_CFG = 31;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_PROB_SEL_CFG_LEN = 2;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_SUB_SEL_CFG = 33;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__CERRS_LRU_DECR_SUB_SEL_CFG_LEN = 3;
static const uint32_t L3_MISC_L3CERRS_MODE_REG0__DYN_INSTR_XLAT_LCO_HEUR_OVERRIDE_EN_CFG = 36;
// c/reg00005.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR = 0x2001068bull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_ENABLE_SPLIT_CORE = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE2TO4 = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE2TO4_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SCOPE = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SCOPE_LEN = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE8TO11 = 8;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_SPARE8TO11_LEN = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR = 12;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_PDBAR_LEN = 39;
// c/reg00005.H

static const uint64_t NC_NCCHTM_NCCHTSC_HTM_TRIG = 0x20010684ull;

static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_START = 0;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP = 1;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_PAUSE = 2;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_STOP_ALT = 3;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_RESET = 4;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_VALID = 5;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE = 6;
static const uint32_t NC_NCCHTM_NCCHTSC_HTM_TRIG_MARK_TYPE_LEN = 10;
// c/reg00005.H

static const uint64_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0 = 0x20010652ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_VALID = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_8_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_VALID = 13;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID = 14;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_7_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_VALID = 26;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID = 27;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_6_LPAR_ID_LEN = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_VALID = 39;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID = 40;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_SLOW_LPAR_REG0_5_LPAR_ID_LEN = 12;
// c/reg00005.H

static const uint64_t QME_CIIR_PPE = 0x00000006c0018740ull;
static const uint64_t QME_CIIR_WO_4P = 0x200e0874ull;

static const uint32_t QME_CIIR__INTR_INJECT = 28;
static const uint32_t QME_CIIR__INTR_INJECT_LEN = 4;
static const uint32_t QME_CIIR_U_INTR_INJECT = 60;
static const uint32_t QME_CIIR_U_INTR_INJECT_LEN = 4;
// c/reg00005.H

static const uint64_t QME_RMOR_PPE = 0x00000006c0018680ull;
static const uint64_t QME_RMOR_WO = 0x200e0868ull;

static const uint32_t QME_RMOR_DATA = 0;
static const uint32_t QME_RMOR_DATA_LEN = 63;
static const uint32_t QME_RMOR_URMOR_SELECT = 63;
// c/reg00005.H

static const uint64_t QME_SCR_PPE = 0x00000006c00180c0ull;
static const uint64_t QME_SCR_PPE1 = 0x00000006c00180f0ull;
static const uint64_t QME_SCR_PPE2 = 0x00000006c00180e0ull;
static const uint64_t QME_SCR_RW = 0x200e080cull;
static const uint64_t QME_SCR_WO_CLEAR = 0x200e080full;
static const uint64_t QME_SCR_WO_OR = 0x200e080eull;

static const uint32_t QME_SCR_QME_SCR_DATA = 0;
static const uint32_t QME_SCR_QME_SCR_DATA_LEN = 64;
// c/reg00005.H

}
}
#include "c/reg00005.H"
#endif
