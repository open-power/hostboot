/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_9.H $       */
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

#ifndef __p10_scom_omic_9_H_
#define __p10_scom_omic_9_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t DATASM_REGS_RX_STAT11_PG = 0x800ae04010012c3full;

static const uint32_t DATASM_REGS_RX_STAT11_PG_RX_SERVO_RESULT_QUEUE_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT11_PG_RX_SERVO_RESULT_QUEUE_RO_SIGNAL_LEN = 16;
// omic/reg00009.H

static const uint64_t DATASM_REGS_RX_STAT21_PG = 0x800b304010012c3full;

static const uint32_t DATASM_REGS_RX_STAT21_PG_RX_DL_PHY_RECAL_REQ_0_15_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT21_PG_RX_DL_PHY_RECAL_REQ_0_15_RO_SIGNAL_LEN = 16;
// omic/reg00009.H

static const uint64_t PMU_CNTR = 0x0c01174full;

static const uint32_t PMU_CNTR_3 = 0;
static const uint32_t PMU_CNTR_3_LEN = 16;
static const uint32_t PMU_CNTR_2 = 16;
static const uint32_t PMU_CNTR_2_LEN = 16;
static const uint32_t PMU_CNTR_1 = 32;
static const uint32_t PMU_CNTR_1_LEN = 16;
static const uint32_t PMU_CNTR_0 = 48;
static const uint32_t PMU_CNTR_0_LEN = 16;
// omic/reg00009.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00009.H"
#endif
#endif
