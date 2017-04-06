/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_memdiags.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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

#ifndef _MSS_MEMDIAGS_H
#define _MSS_MEMDIAGS_H

//------------------------------------------------------------------------------
//  Includes
//------------------------------------------------------------------------------


#include <fapi2.H>

typedef fapi2::ReturnCode (*p9c_mss_memdiags_FP_t)(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target);

extern "C"
{

    ///
    /// @brief Uses maint cmds to write pattern to memory and read back.
    /// @param[in]  i_target  Reference to target
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode p9c_mss_memdiags( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target );



    ///
    /// @brief Check for ECC errors after sf read
    /// @param[in]      i_target  Reference to target
    /// @param[out]     o_error_summary   Maint error summary per rank, per pattern
    /// @param[in]      i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_check_for_ECC_errors(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            uint8_t (&o_error_summary)[8][9],
            const uint8_t i_pattern_index);

    ///
    /// @brief Update error summary per rank, per pattern
    /// @param[in]      i_rank            Rank being analyzed
    /// @param[in]      i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @param[in]      i_mbeccfir        MBECCFIR
    /// @param[out]     o_error_summary   Maint error summary per rank, per pattern
    /// @return none
    ///
    void mss_update_error_summary(const uint8_t i_rank,
                                  const uint8_t i_pattern_index,
                                  fapi2::buffer<uint64_t> i_mbeccfir,
                                  uint8_t (&o_error_summary)[8][9]);



    ///
    /// @brief Runs IPL verify chip mark procedure on a given rank
    /// @param[in]  i_target          Reference to target
    /// @param[in]  i_rank            Rank to run on
    /// @param[in]  i_pattern_index   Index to keep track of which pattern in the sequence of patterns we are on.
    /// @param[out] o_error_summary   Maint error summary per rank, per pattern
    /// @param[out] o_mark verified   True if chip mark verified, and no UEs or RCEs hit.
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ipl_verify_chip_mark(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_rank,
            const uint8_t i_pattern_index,
            uint8_t (&o_error_summary)[8][9],
            bool& o_mark_verified);


    ///
    /// @brief Runs IPL steer procedure on a given rank
    /// @param[in]  i_target          Reference to target
    /// @param[in]  i_rank            Rank to run on
    /// @param[in]  i_pattern_index   Index to keep track of which pattern in
    /// @param[out] o_error_summary   Maint error summary per rank, per pattern
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_ipl_steer( const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
                                     const uint8_t i_rank,
                                     const uint8_t i_pattern_index,
                                     uint8_t (&o_error_summary)[8][9]);



    ///
    /// @brief Clears ECC error status
    /// @param[in]  i_target    Reference to target
    /// @param[in]  i_rank      Rank to run on
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_error_status_cleanup(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const uint8_t i_rank);



    ///
    /// @brief speed options for time base commands.
    ///
    enum AddressRange
    {
        SINGLE_ADDRESS =                     0,
        WHOLE_RANK =                         1,
    };

    ///
    /// @brief speed options for time base commands.
    ///
    enum CeType
    {
        NONE =                              0x00,
        SOFT =                              0x01,
        INTERMITTENT =                      0x02,
        HARD =                              0x04,
    };


    ///
    /// @brief Does a targeted fast scrub of either single address or whole rank
    /// @param[in]  i_target          Reference to target (MBA)
    /// @param[in]  i_address         Address to scrub
    /// @param[in]  i_address_range   SINGLE_ADDRESS, or WHOLE_RANK
    /// @param[in]  i_ce_type         SOFT or INTERMITTENT or HARD or any combo
    /// @return FAPI2_RC_SUCCESS iff successful
    ///
    fapi2::ReturnCode mss_targeted_fast_scrub(const fapi2::Target<fapi2::TARGET_TYPE_MBA>& i_target,
            const fapi2::buffer<uint64_t> i_address,
            const AddressRange i_address_range,
            const uint8_t i_ce_type);

} // extern "C"

#endif /* _MSS_MEMDIAGS_H */
