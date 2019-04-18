/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_d.H $       */
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

#ifndef __p10_scom_iohs_d_H_
#define __p10_scom_iohs_d_H_


namespace scomt
{
namespace iohs
{


static const uint64_t AXON_EPS_DBG_DEBUG_TRACE_CONTROL = 0x180107d0ull;
// iohs/reg00045.H

static const uint64_t AXON_EPS_THERM_WSUB_DTS_RESULT0 = 0x18050000ull;

static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT = 0;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_0_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_1_RESULT_LEN = 16;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT = 32;
static const uint32_t AXON_EPS_THERM_WSUB_DTS_RESULT0_2_RESULT_LEN = 16;
// iohs/reg00045.H

static const uint64_t AXON_OPCG_REG2 = 0x18030004ull;

static const uint32_t AXON_OPCG_REG2_OPCG_GO2 = 0;
static const uint32_t AXON_OPCG_REG2_PRPG_WEIGHTING = 1;
static const uint32_t AXON_OPCG_REG2_PRPG_WEIGHTING_LEN = 3;
static const uint32_t AXON_OPCG_REG2_PRPG_VALUE = 4;
static const uint32_t AXON_OPCG_REG2_PRPG_VALUE_LEN = 12;
static const uint32_t AXON_OPCG_REG2_PRPG_A_VAL = 16;
static const uint32_t AXON_OPCG_REG2_PRPG_A_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG2_PRPG_B_VAL = 28;
static const uint32_t AXON_OPCG_REG2_PRPG_B_VAL_LEN = 12;
static const uint32_t AXON_OPCG_REG2_PRPG_MODE = 40;
static const uint32_t AXON_OPCG_REG2_SM_LBIST_CNTRL = 48;
static const uint32_t AXON_OPCG_REG2_SM_LBIST_CNTRL_LEN = 16;
// iohs/reg00045.H

static const uint64_t PRIMARY_ADDRESS_REG = 0x180f0000ull;
// iohs/reg00045.H

}
}
#include "iohs/reg00045.H"
#endif
