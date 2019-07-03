/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_pec_2.H $        */
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

#ifndef __p10_scom_pec_2_H_
#define __p10_scom_pec_2_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace pec
{
#endif


static const uint64_t CPLT_STAT0 = 0x08000100ull;

static const uint32_t CPLT_STAT0_ABIST_DONE_DC = 0;
static const uint32_t CPLT_STAT0_RESERVED_2I = 2;
static const uint32_t CPLT_STAT0_RESERVED_3I = 3;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT0_OUT = 4;
static const uint32_t CPLT_STAT0_TC_DIAG_PORT1_OUT = 5;
static const uint32_t CPLT_STAT0_RESERVED_6I = 6;
static const uint32_t CPLT_STAT0_PLL_DESTOUT = 7;
static const uint32_t CPLT_STAT0_CC_CTRL_OPCG_DONE_DC = 8;
static const uint32_t CPLT_STAT0_CC_CTRL_CHIPLET_IS_ALIGNED_DC = 9;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYA = 10;
static const uint32_t CPLT_STAT0_IOPCI_TC_HSSPRTREADYB = 11;
static const uint32_t CPLT_STAT0_FREE_USAGE_12I = 12;
static const uint32_t CPLT_STAT0_FREE_USAGE_13I = 13;
static const uint32_t CPLT_STAT0_FREE_USAGE_14I = 14;
static const uint32_t CPLT_STAT0_FREE_USAGE_15I = 15;
static const uint32_t CPLT_STAT0_FREE_USAGE_16I = 16;
static const uint32_t CPLT_STAT0_FREE_USAGE_17I = 17;
static const uint32_t CPLT_STAT0_FREE_USAGE_18I = 18;
static const uint32_t CPLT_STAT0_FREE_USAGE_19I = 19;
static const uint32_t CPLT_STAT0_FREE_USAGE_20I = 20;
static const uint32_t CPLT_STAT0_FREE_USAGE_21I = 21;
static const uint32_t CPLT_STAT0_FREE_USAGE_22I = 22;
static const uint32_t CPLT_STAT0_FREE_USAGE_23I = 23;
static const uint32_t CPLT_STAT0_FREE_USAGE_24I = 24;
static const uint32_t CPLT_STAT0_FREE_USAGE_25I = 25;
static const uint32_t CPLT_STAT0_FREE_USAGE_26I = 26;
static const uint32_t CPLT_STAT0_FREE_USAGE_27I = 27;
static const uint32_t CPLT_STAT0_FREE_USAGE_28I = 28;
static const uint32_t CPLT_STAT0_FREE_USAGE_29I = 29;
static const uint32_t CPLT_STAT0_FREE_USAGE_30I = 30;
static const uint32_t CPLT_STAT0_FREE_USAGE_31I = 31;
// pec/reg00002.H

static const uint64_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG = 0x03011809ull;

static const uint32_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0 = 0;
static const uint32_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK0_LEN = 16;
static const uint32_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1 = 16;
static const uint32_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_STK1_LEN = 8;
static const uint32_t PB_PBCQ_PEPBREGS_NWRSTKOVR_REG_ENABLE = 24;
// pec/reg00002.H

static const uint64_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0 = 0x0301180cull;

static const uint32_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0_PE_TOPOLOGY_ID_REG0 = 0;
static const uint32_t PB_PBCQ_PEPBREGS_PE_TOPOLOGY_REG0_PE_TOPOLOGY_ID_REG0_LEN = 40;
// pec/reg00002.H

static const uint64_t SPATTN = 0x08040002ull;

static const uint32_t SPATTN_ANY_SPATTN = 0;
static const uint32_t SPATTN_RESERVED1S = 1;
static const uint32_t SPATTN_RESERVED2S = 2;
static const uint32_t SPATTN_RESERVED3S = 3;
static const uint32_t SPATTN_SPATTN_PERV = 4;
static const uint32_t SPATTN_SPATTN_IN05 = 5;
static const uint32_t SPATTN_SPATTN_IN06 = 6;
static const uint32_t SPATTN_SPATTN_IN07 = 7;
static const uint32_t SPATTN_SPATTN_IN08 = 8;
static const uint32_t SPATTN_SPATTN_IN09 = 9;
static const uint32_t SPATTN_SPATTN_IN10 = 10;
static const uint32_t SPATTN_SPATTN_IN11 = 11;
static const uint32_t SPATTN_SPATTN_IN12 = 12;
static const uint32_t SPATTN_SPATTN_IN13 = 13;
static const uint32_t SPATTN_SPATTN_IN14 = 14;
static const uint32_t SPATTN_SPATTN_IN15 = 15;
static const uint32_t SPATTN_SPATTN_IN16 = 16;
static const uint32_t SPATTN_SPATTN_IN17 = 17;
static const uint32_t SPATTN_SPATTN_IN18 = 18;
static const uint32_t SPATTN_SPATTN_IN19 = 19;
static const uint32_t SPATTN_SPATTN_IN20 = 20;
static const uint32_t SPATTN_SPATTN_IN21 = 21;
static const uint32_t SPATTN_SPATTN_IN22 = 22;
static const uint32_t SPATTN_SPATTN_IN23 = 23;
static const uint32_t SPATTN_SPATTN_IN24 = 24;
static const uint32_t SPATTN_SPATTN_IN25 = 25;
static const uint32_t SPATTN_SPATTN_IN26 = 26;
static const uint32_t SPATTN_SPATTN_IN27 = 27;
static const uint32_t SPATTN_SPATTN_IN28 = 28;
static const uint32_t SPATTN_SPATTN_IN29 = 29;
static const uint32_t SPATTN_SPATTN_IN30 = 30;
static const uint32_t SPATTN_SPATTN_IN31 = 31;
static const uint32_t SPATTN_SPATTN_IN32 = 32;
static const uint32_t SPATTN_SPATTN_IN33 = 33;
static const uint32_t SPATTN_SPATTN_IN34 = 34;
static const uint32_t SPATTN_SPATTN_IN35 = 35;
// pec/reg00002.H

static const uint64_t TRA0_TR1_CONFIG_5 = 0x08010448ull;

static const uint32_t TRA0_TR1_CONFIG_5_C = 0;
static const uint32_t TRA0_TR1_CONFIG_5_C_LEN = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D = 24;
static const uint32_t TRA0_TR1_CONFIG_5_D_LEN = 24;
// pec/reg00002.H

#ifndef __PPE_HCODE__
}
}
#include "pec/reg00002.H"
#endif
#endif
