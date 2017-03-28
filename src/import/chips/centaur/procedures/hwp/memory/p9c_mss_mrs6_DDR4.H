/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mrs6_DDR4.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

///
/// @file mss_mrs6_DDR4.H
/// @brief  MRS6 setting procedures
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///



#ifndef MSS_MR6_DDR4_H
#define MSS_MR6_DDR4_H

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_mrs6_DDR4_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

extern "C"
{
    /// @brief sets up and runs Mode Register Set 6 on a centaur.mba level target
    /// @param[in]  target:  Reference to centaur.mba target,
    /// @return ReturnCode
    fapi2::ReturnCode p9c_mss_mrs6_DDR4(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

    /// @brief Adds a no-op (NOP) command to the CCS array
    /// @param[in]  i_target_mba:  Reference to centaur.mba target,
    /// @param[in]  i_addr_16: 16 wide ecmdDataBufferBase to be used for the address bus
    /// @param[in]  i_instruction_number: current location in the CCS array
    /// @param[in]  i_rank: current rank
    /// @param[in]  i_bank: current bank
    /// @param[in]  i_delay: delay to add for the command
    /// @param[in]  i_port: current port to execute the NOP on
    /// @return ReturnCode
    fapi2::ReturnCode add_nop_to_ccs(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                     fapi2::variable_buffer& i_addr_16, uint32_t i_instruction_number, const uint8_t i_rank, const uint8_t i_bank,
                                     const uint32_t i_delay, uint8_t i_port);

    /// @brief Loads in MRS6 for a given port number
    /// @param[in]  i_target:  Reference to centaur.mba target,
    /// @param[in]  i_port_number:  Current port to operate on
    /// @param[in,out]  io_ccs_inst_cnt:  Reference to current CCS array position
    /// @return ReturnCode
    fapi2::ReturnCode mss_mr6_loader(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target, uint32_t i_port_number,
                                     uint32_t& io_ccs_inst_cnt);
} // extern "C"

#endif // MSS_MR6_DDR4_H



