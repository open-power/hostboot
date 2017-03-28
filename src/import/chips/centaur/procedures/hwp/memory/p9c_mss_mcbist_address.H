/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_mcbist_address.H $ */
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
/// @file mss_mcbist_address.H
/// @brief MCBIST address procedures header
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Steve Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 2
/// *HWP Consumed by: HB:CI
///

#ifndef MSS_MCBIST_ADDRESS_H
#define MSS_MCBIST_ADDRESS_H

#include <fapi2.H>
#include <cen_gen_scom_addresses.H>
#include <p9c_mss_access_delay_reg.H>
#include <p9c_mss_mcbist.H>
#include <string.h>
#include <dimmConsts.H>
extern "C"
{
    ///
    /// @brief interleave type enum
    ///
    enum interleave_type
    {
        BANK_RANK,
        RANK_BANK,
        BANK_ONLY,
        RANK_ONLY,
        RANKS_DIMM0,
        RANKS_DIMM1,
        USER_PATTERN
    };

    ///
    /// @brief  Setup MCBIST address string
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] l_str_cust_addr Optional custom address string
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode address_generation(const fapi2:: Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                         const char* l_str_cust_addr);
    ///
    /// @brief Parse MCBIST address string and set corresponding registers
    /// @param[in] i_target_mba Centaur input MBA
    /// @param[in] addr_string MCBIST address string
    /// @param[in] mr3_valid Master rank 3 valid bit
    /// @param[in] mr2_valid Master rank 2 valid bit
    /// @param[in] mr1_valid Master rank 1 valid bit
    /// @param[in] l_dram_rows Num dram rows
    /// @param[in] l_dram_cols Num dram columns
    /// @param[in] l_addr_inter Address interleave bit
    /// @param[in] sl2_valid Slave rank 2 valid bit
    /// @param[in] sl1_valid Slave rank 1 valid bit
    /// @param[in] sl0_valid Slave rank 0 valid bit
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode parse_addr(const fapi2:: Target<fapi2::TARGET_TYPE_MBA>& i_target_mba,
                                 const char addr_string[],
                                 const uint8_t mr3_valid,
                                 const uint8_t mr2_valid,
                                 const uint8_t mr1_valid,
                                 const uint8_t l_dram_rows,
                                 const uint8_t l_dram_cols,
                                 const uint8_t l_addr_inter,
                                 const uint8_t sl2_valid,
                                 const uint8_t sl1_valid,
                                 const uint8_t sl0_valid);

}
#endif
