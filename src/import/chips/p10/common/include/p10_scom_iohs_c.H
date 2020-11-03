/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_c.H $       */
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

#ifndef __p10_scom_iohs_c_H_
#define __p10_scom_iohs_c_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_CONTROL]
static const uint64_t DLP_CONTROL = 0x1801100bull;

static const uint32_t DLP_CONTROL_0_PHY_TRAINING = 0;
static const uint32_t DLP_CONTROL_0_STARTUP = 1;
static const uint32_t DLP_CONTROL_0_HOLD_PATT_A = 2;
static const uint32_t DLP_CONTROL_0_HOLD_PATT_B = 3;
static const uint32_t DLP_CONTROL_0_RUN_LANE_DISABLE = 4;
static const uint32_t DLP_CONTROL_0_RUN_LANE_OVERRIDE = 5;
static const uint32_t DLP_CONTROL_0_IGNORE_PHY = 6;
static const uint32_t DLP_CONTROL_0_IGNORE_FENCE = 7;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND = 8;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LANES = 12;
static const uint32_t DLP_CONTROL_0_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t DLP_CONTROL_0_COMMAND = 28;
static const uint32_t DLP_CONTROL_0_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_1_PHY_TRAINING = 32;
static const uint32_t DLP_CONTROL_1_STARTUP = 33;
static const uint32_t DLP_CONTROL_1_HOLD_PATT_A = 34;
static const uint32_t DLP_CONTROL_1_HOLD_PATT_B = 35;
static const uint32_t DLP_CONTROL_1_RUN_LANE_DISABLE = 36;
static const uint32_t DLP_CONTROL_1_RUN_LANE_OVERRIDE = 37;
static const uint32_t DLP_CONTROL_1_IGNORE_PHY = 38;
static const uint32_t DLP_CONTROL_1_IGNORE_FENCE = 39;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND = 40;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LEN = 4;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LANES = 44;
static const uint32_t DLP_CONTROL_1_ERR_INJ_COMMAND_LANES_LEN = 9;
static const uint32_t DLP_CONTROL_1_COMMAND = 60;
static const uint32_t DLP_CONTROL_1_COMMAND_LEN = 4;
//<< [DLP_CONTROL]
// iohs/reg00053.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00053.H"
#include "iohs/reg00054.H"
#include "iohs/reg00055.H"
#include "iohs/reg00056.H"
#include "iohs/reg00057.H"
#endif
#endif
