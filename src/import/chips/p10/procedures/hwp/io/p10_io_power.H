/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_power.H $       */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
// EKB-Mirror-To: hostboot
///
/// @file p10_io_power.H
/// @brief Common IO functions and constants
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------

#include <fapi2.H>
#include <p10_io_ppe_lib.H>

#ifndef _P10_IO_POWER__
#define _P10_IO_POWER__

//------------------------------------------------------------------------------
// Consts
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

class p10_io_ppe_cache_proc_power_on
{
    public:
        p10_io_ppe_cache_proc_power_on();

        static const uint64_t p10_io_ppe_img_regs_start = 0xffff1190ull;
        static const uint64_t p10_io_ppe_fw_regs0_start = 0xffff11b0ull;
        static const uint64_t p10_io_ppe_fw_regs1_start = 0xffff11c0ull;
        static const uint64_t p10_io_ppe_fw_regs2_start = 0xffff11d0ull;
        static const uint64_t p10_io_ppe_fw_regs3_start = 0xffff11e0ull;
        static const uint64_t p10_io_ppe_fw_regs4_start = 0xffff11f0ull;
        static const uint64_t p10_io_ppe_kernel_stack_start = 0xffff1200ull;
        static const uint64_t p10_io_ppe_io_thread_stack0_start = 0xffff1400ull;
        static const uint64_t p10_io_ppe_io_thread_stack1_start = 0xffff1800ull;
        static const uint64_t p10_io_ppe_io_thread_stack2_start = 0xffff1c00ull;
        static const uint64_t p10_io_ppe_io_thread_stack3_start = 0xffff2000ull;
        static const uint64_t p10_io_ppe_io_thread_stack4_start = 0xffff2400ull;
        static const uint64_t p10_io_ppe_mem_regs0_start = 0xffff2800ull;
        static const uint64_t p10_io_ppe_mem_regs1_start = 0xffff2c00ull;
        static const uint64_t p10_io_ppe_mem_regs2_start = 0xffff3000ull;
        static const uint64_t p10_io_ppe_mem_regs3_start = 0xffff3400ull;
        static const uint64_t p10_io_ppe_mem_regs4_start = 0xffff3800ull;
        static const uint64_t p10_io_ppe_debug_log_start = 0xffff3c00ull;

        p10_io_ppe_cache p10_io_ppe_fw_regs[5];

        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_power_off_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_power_on_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_done_tx_fifo_init_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_lanes_00_15[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_lanes_16_31[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_power_off_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_power_on_pl[5];
        p10_io_ppe_sram_reg p10_io_ppe_ext_cmd_req_tx_fifo_init_pl[5];
};

extern "C"
{
///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_iolink_target Iolink target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_iolink_power(
        const fapi2::Target<fapi2::TARGET_TYPE_IOLINK>& i_iolink_target,
        const bool& i_on);

///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_iohs_target Iohs target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_iohs_power(
        const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
        const bool& i_on);

///
/// @brief Set power on/off for targeted lanes.
///
/// @param[in] i_omic_target Omic target to work with
/// @param[in] i_on Specified action (true=on, false=off)
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
    fapi2::ReturnCode p10_io_omic_power(
        const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
        const bool& i_on);
} // extern "C"
#endif
