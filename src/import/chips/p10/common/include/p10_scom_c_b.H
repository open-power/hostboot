/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_c_b.H $          */
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

#ifndef __p10_scom_c_b_H_
#define __p10_scom_c_b_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace c
{
#endif


//>> [CPMS_L3_PFETSTAT]
static const uint64_t CPMS_L3_PFETSTAT = 0x200e0e24ull;

static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_ENABLED_SENSE = 0;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFETS_DISABLED_SENSE = 1;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_ENABLED_SENSE = 2;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFETS_DISABLED_SENSE = 3;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL = 16;
static const uint32_t CPMS_L3_PFETSTAT_VDD_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL = 24;
static const uint32_t CPMS_L3_PFETSTAT_VCS_PFET_ENABLE_ACTUAL_LEN = 8;
static const uint32_t CPMS_L3_PFETSTAT_SRAM_ENABLE_ACTUAL = 63;
//<< [CPMS_L3_PFETSTAT]
// c/reg00011.H

//>> [EC_PC_SCR0]
static const uint64_t EC_PC_SCR0 = 0x20020486ull;
//<< [EC_PC_SCR0]
// c/reg00011.H

//>> [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]
static const uint64_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1 = 0x20010655ull;

static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_VAL = 0;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_VAL = 1;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_VAL = 2;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_VAL = 3;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_VAL = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_VAL = 5;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_VAL = 6;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_VAL = 7;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08 = 8;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_08_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09 = 12;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_09_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10 = 16;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_10_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11 = 20;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_11_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12 = 24;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_12_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13 = 28;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_13_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14 = 32;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_14_LEN = 4;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15 = 36;
static const uint32_t NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1_15_LEN = 4;
//<< [NC_NCMISC_NCSCOMS_NCU_TOPOTABLE_REG1]
// c/reg00011.H

//>> [QME_PSCRS1]
static const uint64_t QME_PSCRS1 = 0x200e0854ull;

static const uint32_t QME_PSCRS1_DPDES_EXIT_ENABLE = 0;
static const uint32_t QME_PSCRS1_SD = 1;
static const uint32_t QME_PSCRS1_ESL = 2;
static const uint32_t QME_PSCRS1_EC = 3;
static const uint32_t QME_PSCRS1_PSLL = 4;
static const uint32_t QME_PSCRS1_PSLL_LEN = 4;
static const uint32_t QME_PSCRS1_HYP_VIRT_EXIT_ENABLE = 8;
static const uint32_t QME_PSCRS1_UV_DB_EXIT_ENABLE = 9;
static const uint32_t QME_PSCRS1_HYP_DB_EXIT_ENABLE = 10;
static const uint32_t QME_PSCRS1_EXT_EXIT_ENABLE = 11;
static const uint32_t QME_PSCRS1_DEC_EXIT_ENABLE = 12;
static const uint32_t QME_PSCRS1_HMI_EXIT_ENABLE = 13;
static const uint32_t QME_PSCRS1_TR = 14;
static const uint32_t QME_PSCRS1_TR_LEN = 2;
static const uint32_t QME_PSCRS1_MTL = 16;
static const uint32_t QME_PSCRS1_MTL_LEN = 4;
static const uint32_t QME_PSCRS1_RL = 20;
static const uint32_t QME_PSCRS1_RL_LEN = 4;
static const uint32_t QME_PSCRS1_PLS = 24;
static const uint32_t QME_PSCRS1_PLS_LEN = 4;
//<< [QME_PSCRS1]
// c/reg00011.H

//>> [CPMS_DHDR]
static const uint64_t CPMS_DHDR = 0x200e0e58ull;

static const uint32_t CPMS_DHDR_FTC_EVENT_HISTORY0 = 0;
static const uint32_t CPMS_DHDR_FTC_EVENT_HISTORY0_LEN = 8;
static const uint32_t CPMS_DHDR_FTC_EVENT_HISTORY1 = 8;
static const uint32_t CPMS_DHDR_FTC_EVENT_HISTORY1_LEN = 8;
static const uint32_t CPMS_DHDR_FTC_EVENT_DATA = 16;
static const uint32_t CPMS_DHDR_FTC_EVENT_DATA_LEN = 8;
static const uint32_t CPMS_DHDR_FTC_RAW_EVENT_HISTORY = 24;
static const uint32_t CPMS_DHDR_FTC_RAW_EVENT_HISTORY_LEN = 4;
static const uint32_t CPMS_DHDR_ADJ_WARN_EVENT_HISTORY = 28;
static const uint32_t CPMS_DHDR_ADJ_WARN_EVENT_HISTORY_LEN = 2;
static const uint32_t CPMS_DHDR_ADJ_WARN_ACTIVE = 30;
static const uint32_t CPMS_DHDR_ADJ_WARN_ACTIVE_LEN = 2;
static const uint32_t CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA = 32;
static const uint32_t CPMS_DHDR_CPMS_DDSR_DPLL_ENCODED_DATA_LEN = 3;
static const uint32_t CPMS_DHDR_CPMS_DDSR_DDS_DATA = 35;
static const uint32_t CPMS_DHDR_CPMS_DDSR_DDS_DATA_LEN = 5;
static const uint32_t CPMS_DHDR_DPLL_ENCODED_MIN = 40;
static const uint32_t CPMS_DHDR_DPLL_ENCODED_MIN_LEN = 3;
static const uint32_t CPMS_DHDR_MIN_DATA = 43;
static const uint32_t CPMS_DHDR_MIN_DATA_LEN = 5;
static const uint32_t CPMS_DHDR_DPLL_ENCODED_MAX = 48;
static const uint32_t CPMS_DHDR_DPLL_ENCODED_MAX_LEN = 3;
static const uint32_t CPMS_DHDR_MAX_DATA = 51;
static const uint32_t CPMS_DHDR_MAX_DATA_LEN = 5;
static const uint32_t CPMS_DHDR_DDP_EVENT_HISTORY = 56;
static const uint32_t CPMS_DHDR_DDP_EVENT_HISTORY_LEN = 2;
static const uint32_t CPMS_DHDR_DDP_ACTIVE = 58;
static const uint32_t CPMS_DHDR_DDP_ACTIVE_LEN = 2;
static const uint32_t CPMS_DHDR_CPMS_DDSR_STOP_STATE_ACTIVE = 60;
static const uint32_t CPMS_DHDR_CPMS_DDSR_CORE_SAMPLE_DISABLED = 61;
static const uint32_t CPMS_DHDR_STOP_STATE_OCCURRED = 62;
static const uint32_t CPMS_DHDR_SAMPLE_DISABLE_OCCURRED = 63;
//<< [CPMS_DHDR]
// c/reg00011.H

//>> [CPMS_WPMR]
static const uint64_t CPMS_WPMR = 0x200e0e90ull;
static const uint64_t CPMS_WPMR_SCOM2 = 0x200e0e92ull;
static const uint64_t CPMS_WPMR_WO_CLEAR = 0x200e0e93ull;

static const uint32_t CPMS_WPMR_PITCH_ENABLE = 0;
static const uint32_t CPMS_WPMR_RESET_ACTIVITY_ON_SAMPLE_DISABLE = 1;
static const uint32_t CPMS_WPMR_RESET_ENERGY_ON_SAMPLE_ENABLE = 2;
static const uint32_t CPMS_WPMR_PITCH_INTERRUPT_ENABLE = 3;
static const uint32_t CPMS_WPMR_SPARE = 4;
static const uint32_t CPMS_WPMR_SPARE_LEN = 2;
static const uint32_t CPMS_WPMR_PITCH_PERIOD_TIME = 18;
static const uint32_t CPMS_WPMR_PITCH_PERIOD_TIME_LEN = 14;
static const uint32_t CPMS_WPMR_RESET_ACTIVITY_PROXY = 32;
static const uint32_t CPMS_WPMR_RESET_ENERGY_PROXY = 33;
//<< [CPMS_WPMR]
// c/reg00011.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "c/reg00011.H"
#endif
#endif
