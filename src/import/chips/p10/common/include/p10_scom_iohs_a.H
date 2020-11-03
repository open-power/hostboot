/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_iohs_a.H $       */
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

#ifndef __p10_scom_iohs_a_H_
#define __p10_scom_iohs_a_H_


#ifndef __PPE_HCODE__
namespace scomt
{
namespace iohs
{
#endif


//>> [DLP_LINK0_TX_LANE_CONTROL]
static const uint64_t DLP_LINK0_TX_LANE_CONTROL = 0x18011010ull;

static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL = 0;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_00_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_01_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL = 8;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_02_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL = 12;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_03_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL = 16;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_04_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL = 20;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_05_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL = 24;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_06_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL = 28;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_07_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL = 32;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_SP_CONTROL_LEN = 4;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED = 48;
static const uint32_t DLP_LINK0_TX_LANE_CONTROL_FAILED_LEN = 9;
//<< [DLP_LINK0_TX_LANE_CONTROL]
// iohs/reg00044.H

//>>THE END<<

#ifndef __PPE_HCODE__
}
}
#include "iohs/reg00044.H"
#include "iohs/reg00045.H"
#include "iohs/reg00046.H"
#include "iohs/reg00047.H"
#endif
#endif
