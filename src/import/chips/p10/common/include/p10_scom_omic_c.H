/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omic_c.H $       */
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

#ifndef __p10_scom_omic_c_H_
#define __p10_scom_omic_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace omic
{
#endif


static const uint64_t DATASM_REGS_RX_STAT10_PG = 0x800ad84010012c3full;

static const uint32_t DATASM_REGS_RX_STAT10_PG_RX_SCAN_N_0_15_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT10_PG_RX_SCAN_N_0_15_RO_SIGNAL_LEN = 16;
// omic/reg00012.H

static const uint64_t DATASM_REGS_RX_STAT20_PG = 0x800b284010012c3full;

static const uint32_t DATASM_REGS_RX_STAT20_PG_RX_DL_PHY_RUN_LANE_16_23_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT20_PG_RX_DL_PHY_RUN_LANE_16_23_RO_SIGNAL_LEN = 8;
// omic/reg00012.H

static const uint64_t DATASM_REGS_RX_STAT30_PG = 0x800b784010012c3full;

static const uint32_t DATASM_REGS_RX_STAT30_PG_RX_VTAL_LATE_RESULT_RO_SIGNAL = 48;
static const uint32_t DATASM_REGS_RX_STAT30_PG_RX_VTAL_LATE_RESULT_RO_SIGNAL_LEN = 16;
// omic/reg00012.H

#ifndef __PPE_HCODE__
}
}
#include "omic/reg00012.H"
#endif
#endif
