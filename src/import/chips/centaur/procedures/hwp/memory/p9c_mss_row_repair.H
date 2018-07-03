/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_row_repair.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
#ifndef __P9C_MSS_ROW_REPAIR__
#define __P9C_MSS_ROW_REPAIR__

#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_row_repair_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
        const uint8_t  i_port,
        const uint8_t  i_mrank,
        const uint8_t  i_srank,
        const uint8_t  i_bank,
        const uint32_t i_row,
        const uint32_t i_dram_bitmap);

extern "C"
{

    /// @brief Perform a PPR row repair operation
    /// @param[in] i_target_mba mba target
    /// @param[in] i_port port for repair
    /// @param[in] i_mrank master rank of address to repair
    /// @param[in] i_srank slave rank of address to repair
    /// @param[in] i_bank bank bits of address to repair
    /// @param[in] i_row row bits of address to repair
    /// @param[in] i_dram_bitmap bitmap of DRAMs selected for repair (b'1 to repair, b'0 to not repair)
    /// @return FAPI2_RC_SUCCESS iff successful
    fapi2::ReturnCode p9c_mss_row_repair(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const uint8_t  i_port,
                                         const uint8_t  i_mrank,
                                         const uint8_t  i_srank,
                                         const uint8_t  i_bank,
                                         const uint32_t i_row,
                                         const uint32_t i_dram_bitmap);

}

#endif
