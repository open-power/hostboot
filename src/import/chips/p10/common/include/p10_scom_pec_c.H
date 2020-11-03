/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_c.H $        */
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

#ifndef __p10_scom_pec_c_H_
#define __p10_scom_pec_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


//>> [CPLT_CTRL2]
static const uint64_t CPLT_CTRL2_RW = 0x08000002ull;
static const uint64_t CPLT_CTRL2_WO_CLEAR = 0x08000022ull;
static const uint64_t CPLT_CTRL2_WO_OR = 0x08000012ull;

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
// pec/reg00012.H

//>> [CPLT_MASK0]
static const uint64_t CPLT_MASK0 = 0x08000101ull;

static const uint32_t CPLT_MASK0_ITR_MASK = 0;
static const uint32_t CPLT_MASK0_ITR_MASK_LEN = 32;
//<< [CPLT_MASK0]
// pec/reg00012.H

//>> [EPS_DBG_MODE_REG]
static const uint64_t EPS_DBG_MODE_REG = 0x080107c0ull;

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
// pec/reg00012.H

//>> [PCB_OPCG_STOP]
static const uint64_t PCB_OPCG_STOP = 0x08030030ull;

static const uint32_t PCB_OPCG_STOP_PCB_OPCGSTOP = 0;
//<< [PCB_OPCG_STOP]
// pec/reg00012.H

//>> [SCAN64CONTSCAN]
static const uint64_t SCAN64CONTSCAN = 0x0803f000ull;

static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG = 0;
static const uint32_t SCAN64CONTSCAN_SCAN64CONTSCAN_REG_LEN = 64;
//<< [SCAN64CONTSCAN]
// pec/reg00012.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00012.H"
#endif
#endif
