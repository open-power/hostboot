/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/common/include/p10_scom_mcc_3.H $        */
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

#ifndef __p10_scom_mcc_3_H_
#define __p10_scom_mcc_3_H_


namespace scomt
{
namespace mcc
{


//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t LINK1_RX_LANE_CONTROL = 0x0c011013ull;

static const uint32_t LINK1_RX_LANE_CONTROL_DISABLED = 0;
static const uint32_t LINK1_RX_LANE_CONTROL_DISABLED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_BRINGUP = 12;
static const uint32_t LINK1_RX_LANE_CONTROL_BRINGUP_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_SPARED = 24;
static const uint32_t LINK1_RX_LANE_CONTROL_SPARED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_LOCKED = 36;
static const uint32_t LINK1_RX_LANE_CONTROL_LOCKED_LEN = 9;
static const uint32_t LINK1_RX_LANE_CONTROL_FAILED = 48;
static const uint32_t LINK1_RX_LANE_CONTROL_FAILED_LEN = 9;
// mcc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t MC_OMI_FIR_MASK_REG_SCOM = 0x0c011b43ull;
static const uint64_t MC_OMI_FIR_MASK_REG_SCOM1 = 0x0c011b44ull;
static const uint64_t MC_OMI_FIR_MASK_REG_SCOM2 = 0x0c011b45ull;

static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK = 0;
static const uint32_t MC_OMI_FIR_MASK_REG_DL0_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL1_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK = 40;
static const uint32_t MC_OMI_FIR_MASK_REG_DL2_FIR_ERROR_MASK_LEN = 20;
static const uint32_t MC_OMI_FIR_MASK_REG_PERF_MON_WRAPPED_MASK = 60;
// mcc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t REGS_PRX0_DLR_APSR = 0x0c011039ull;
// mcc/reg00003.H

//ERRCODE: // Some of the name targets not found in address targets.

static const uint64_t USTL_USTLMCHWFM = 0x0c010e0full;

static const uint32_t USTL_USTLMCHWFM_ENABLE = 0;
static const uint32_t USTL_USTLMCHWFM_FAIL_THRESH = 1;
static const uint32_t USTL_USTLMCHWFM_FAIL_THRESH_LEN = 6;
static const uint32_t USTL_USTLMCHWFM_WINDOW_SIZE = 7;
static const uint32_t USTL_USTLMCHWFM_WINDOW_SIZE_LEN = 7;
static const uint32_t USTL_USTLMCHWFM_TSCALE = 14;
static const uint32_t USTL_USTLMCHWFM_TSCALE_LEN = 2;
static const uint32_t USTL_USTLMCHWFM_SCOM_COMMAND_VALID = 16;
static const uint32_t USTL_USTLMCHWFM_SCOM_COMMAND = 17;
static const uint32_t USTL_USTLMCHWFM_SUB_CHANNEL_SELECT = 18;
static const uint32_t USTL_USTLMCHWFM_HWFM_STATUS = 19;
static const uint32_t USTL_USTLMCHWFM_HWFM_STATUS_LEN = 4;
// mcc/reg00003.H

}
}
#include "mcc/reg00003.H"
#endif
