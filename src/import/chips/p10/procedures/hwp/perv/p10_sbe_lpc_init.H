/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_sbe_lpc_init.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
//------------------------------------------------------------------------------
/// @file  p10_sbe_lpc_init.H
///
/// @brief procedure to initialize LPC to enable communictation to PNOR
//------------------------------------------------------------------------------
// *HWP HW Maintainer : Chris Riedl (cmr@ibm.com)
// *HWP FW Maintainer : Raja Das    (rajadas2@in.ibm.com)
// *HWP Consumed by   : SBE
//------------------------------------------------------------------------------
#ifndef _P10_SBE_LPC_INIT_H_
#define _P10_SBE_LPC_INIT_H_

#include <fapi2.H>

typedef fapi2::ReturnCode (*p10_sbe_lpc_init_FP_t)(const
        fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&);

extern "C"
{
    const uint64_t LPC_LRESET_OE = 23;
    const uint64_t LPC_LRESET_OUT = 22;
    const uint32_t LPC_LRESET_DELAY_NS = 200000;
    const uint32_t LPCM_OPB_MASTER_STATUS_REG = 0xC0010000;
    const uint32_t LPCM_OPB_MASTER_STATUS_ERROR_BITS = 0x20000FC3;
    const uint32_t LPCM_OPB_MASTER_CONTROL_REG = 0xC0010008;
    const uint32_t LPCM_OPB_MASTER_CONTROL_REG_TIMEOUT_ENABLE = 2;
    const uint32_t LPCM_OPB_MASTER_TIMEOUT_REG = 0xC0010040;
    const uint32_t LPCM_OPB_MASTER_TIMEOUT_VALUE = 0x01312D00;  // 50ms at 1600MHz Nest / 400MHz OPB
    const uint32_t LPCM_OPB_MASTER_INTR_IN_REG = 0xC001005C;
    const uint32_t LPCM_OPB_MASTER_INTR_IN_REG_LRESET = 19;
    const uint32_t LPCM_LPC_MASTER_TIMEOUT_REG = 0xC001202C;
    const uint32_t LPCM_LPC_MASTER_TIMEOUT_VALUE = 0xFE000000;
    const uint32_t CPLT_CONF1_TC_LP_RESET = 12;


/// @brief LPC init to enable connection to PNOR
///
/// @param[in]     i_target_chip   Reference to TARGET_TYPE_PROC_CHIP target
/// @return  FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_sbe_lpc_init(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip);


/// @brief LPC init to enable connection to PNOR
///
/// @param[in]     i_target_chip     Reference to TARGET_TYPE_PROC_CHIP target
/// @param[in]     i_hasPnor         true=this chip has PNOR attached, do full init
///                                  false=this chip has no PNOR attached, only reset controller and hold LRESET asserted
/// @param[in]     i_resetLpcBus     true=Also reset LPC bus (default)
///                                  false=Do not reset LPC bus
/// @return  FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_sbe_lpc_init_any(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
        bool i_hasPnor,
        bool i_resetLpcBus = true);
}

#endif
