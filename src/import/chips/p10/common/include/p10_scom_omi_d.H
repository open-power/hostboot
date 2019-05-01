/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_omi_d.H $        */
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

#ifndef __p10_scom_omi_d_H_
#define __p10_scom_omi_d_H_


namespace scomt
{
namespace omi
{


static const uint64_t CONFIG1 = 0x0c011761ull;

static const uint32_t CONFIG1_CFG1_SPARE = 0;
static const uint32_t CONFIG1_CFG1_SPARE_LEN = 2;
static const uint32_t CONFIG1_LANE_WIDTH = 2;
static const uint32_t CONFIG1_LANE_WIDTH_LEN = 2;
static const uint32_t CONFIG1_PREIPL_PRBS_ENA = 4;
static const uint32_t CONFIG1_PREIPL_PRBS_TIME = 5;
static const uint32_t CONFIG1_PREIPL_PRBS_TIME_LEN = 3;
static const uint32_t CONFIG1_B_HYSTERESIS = 8;
static const uint32_t CONFIG1_B_HYSTERESIS_LEN = 4;
static const uint32_t CONFIG1_A_HYSTERESIS = 12;
static const uint32_t CONFIG1_A_HYSTERESIS_LEN = 4;
static const uint32_t CONFIG1_B_PATTERN_LENGTH = 16;
static const uint32_t CONFIG1_B_PATTERN_LENGTH_LEN = 2;
static const uint32_t CONFIG1_A_PATTERN_LENGTH = 18;
static const uint32_t CONFIG1_A_PATTERN_LENGTH_LEN = 2;
static const uint32_t CONFIG1_TX_PERF_DEGRADED = 20;
static const uint32_t CONFIG1_TX_PERF_DEGRADED_LEN = 2;
static const uint32_t CONFIG1_RX_PERF_DEGRADED = 22;
static const uint32_t CONFIG1_RX_PERF_DEGRADED_LEN = 2;
static const uint32_t CONFIG1_TX_LANES_DISABLE = 24;
static const uint32_t CONFIG1_TX_LANES_DISABLE_LEN = 8;
static const uint32_t CONFIG1_RX_LANES_DISABLE = 32;
static const uint32_t CONFIG1_RX_LANES_DISABLE_LEN = 8;
static const uint32_t CONFIG1_MACRO_DBG_SEL = 40;
static const uint32_t CONFIG1_MACRO_DBG_SEL_LEN = 4;
static const uint32_t CONFIG1_RESET_ERR_HLD = 44;
static const uint32_t CONFIG1_RESET_ERR_CAP = 45;
static const uint32_t CONFIG1_RESET_TSHD_REG = 46;
static const uint32_t CONFIG1_RESET_RMT_MSG = 47;
static const uint32_t CONFIG1_INJECT_CRC_DIRECTION = 48;
static const uint32_t CONFIG1_INJECT_CRC_RATE = 49;
static const uint32_t CONFIG1_INJECT_CRC_RATE_LEN = 3;
static const uint32_t CONFIG1_INJECT_CRC_LANE = 52;
static const uint32_t CONFIG1_INJECT_CRC_LANE_LEN = 3;
static const uint32_t CONFIG1_INJECT_CRC_ERROR = 55;
static const uint32_t CONFIG1_EDPL_TIME = 56;
static const uint32_t CONFIG1_EDPL_TIME_LEN = 4;
static const uint32_t CONFIG1_EDPL_THRESHOLD = 60;
static const uint32_t CONFIG1_EDPL_THRESHOLD_LEN = 3;
static const uint32_t CONFIG1_EDPL_ENA = 63;
// omi/reg00013.H

static const uint64_t PM_REGS_DLR_APCR = 0x0c011eb8ull;
// omi/reg00013.H

}
}
#include "omi/reg00013.H"
#endif
