/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/latch_wr_vref.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file latch_wr_vref.H
/// @brief Latches WR VREF according to JEDEC spec
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB Memory

#ifndef _LATCH_WR_VREF_H_
#define _LATCH_WR_VREF_H_

#include <vector>
#include <fapi2.H>
#include <lib/shared/mss_const.H>
#include <generic/memory/lib/utils/c_str.H>

#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <lib/eff_config/timing.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>


namespace mss
{

namespace ddr4
{
// Declares an enum for using the default WR VREF values
enum wr_vref_override : uint8_t
{
    USE_DEFAULT_WR_VREF_SETTINGS = 0xff,
};

///
/// @brief enables VREF train enable in an MRS06 class
/// @tparam MC mc_type
/// @param[in,out] io_mrs06
///
template<mss::mc_type MC>
void enable_vref_train_enable(mrs06_data<MC>& io_mrs06)
{
    // Sets up the MR information
    for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
    {
        io_mrs06.iv_vrefdq_train_enable[i] = fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_ENABLE;
    }
}

///
/// @brief disables VREF train enable in an MRS06 class
/// @tparam MC mc_type
/// @param[in,out] io_mrs06
///
template<mss::mc_type MC>
void disable_vref_train_enable(mrs06_data<MC>& io_mrs06)
{
    // Sets up the MR information
    for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
    {
        io_mrs06.iv_vrefdq_train_enable[i] = fapi2::ENUM_ATTR_EFF_VREF_DQ_TRAIN_ENABLE_DISABLE;
    }
}

///
/// @brief Add latching commands for WR VREF to the instruction array - allows for custom MR06 data
/// @tparam MC mc_type
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] i_mrs06, base MRS 06 allows the user to setup custom values and pass it in
/// @param[in] i_rank, port rank on which to latch MRS 06
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template <mss::mc_type MC>
fapi2::ReturnCode add_latch_wr_vref_commands( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs06_data<MC>& i_mrs06,
        const uint64_t i_rank,
        std::vector< ccs::instruction_t >& io_inst)
{
    // JEDEC has a 3 step latching process for WR VREF
    // 1) enter into VREFDQ training mode, with the desired range value is XXXXXX
    // 2) set the VREFDQ value while in training mode - this actually latches the value
    // 3) exit VREFDQ training mode and go into normal operation mode

    // Adds both VREFDQ train enables
    // Note: this isn't general - Specific to DDR4
    auto l_mr_override = i_mrs06;

    // Add both to the CCS program - JEDEC step 1
    enable_vref_train_enable<MC>(l_mr_override);
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst),
              "Error in add_latch_wr_vref_commands" );

    // Add both to the CCS program - JEDEC step 2
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst),
              "Error in add_latch_wr_vref_commands" );

    // Hits VREFDQ train disable - putting the DRAM's back in mainline mode
    // Add both to the CCS program - JEDEC step 3
    disable_vref_train_enable<MC>(l_mr_override);
    FAPI_TRY( mrs_engine(i_target, l_mr_override, i_rank, mss::tvrefdqe(i_target), io_inst),
              "Error in add_latch_wr_vref_commands" );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Add latching commands for WR VREF to the instruction array
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @param[in] i_rank_pair, rank pair on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in] i_nvdimm_workaround switch to indicate nvdimm workaround. Default to false
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @note Not needed for explorer (will be blank, TK #421)
///
fapi2::ReturnCode latch_wr_vref_commands_by_rank_pair( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint64_t i_rank_pair,
        const uint8_t i_train_range,
        const uint8_t i_train_value,
        const bool i_nvdimm_workaround = false);

///
/// @brief Add latching commands for WR VREF to the instruction array by a given rank
/// @tparam MC mc_type
/// @param[in] i_target DIMM target
/// @param[in] i_rank, port rank on which to latch MRS 06 - hits all ranks in the rank pair
/// @param[in] i_train_range, VREF range to setup
/// @param[in] i_train_value, VREF value to setup
/// @param[in,out] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
template <mss::mc_type MC>
fapi2::ReturnCode setup_latch_wr_vref_commands_by_rank( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint8_t i_train_range,
        const uint8_t i_train_value,
        std::vector< ccs::instruction_t >& io_inst)
{
    // Check to make sure our ctor worked ok
    mrs06_data<MC> l_mrs06( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err, "%s Unable to construct MRS06 data from attributes", mss::c_str(i_target));

    // Setup training range if the value is not the default
    if(i_train_range != wr_vref_override::USE_DEFAULT_WR_VREF_SETTINGS)
    {
        FAPI_INF("%s Overriding vrefdq train %s data to be 0x%02x for rank %lu", mss::c_str(i_target), "range", i_train_value,
                 i_rank);

        // Sets up the MR information
        for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
        {
            l_mrs06.iv_vrefdq_train_range[i] = i_train_range;
        }
    }

    // Setup training value if the value is not the default
    if(i_train_value != wr_vref_override::USE_DEFAULT_WR_VREF_SETTINGS)
    {
        FAPI_INF("%s Overriding vrefdq train %s data to be 0x%02x for rank %lu", mss::c_str(i_target), "value", i_train_value,
                 i_rank);

        // Sets up the MR information
        for(uint64_t i = 0; i < MAX_RANK_PER_DIMM; ++i)
        {
            l_mrs06.iv_vrefdq_train_value[i] = i_train_value;
        }
    }

    // Adds the latching commands
    FAPI_TRY(add_latch_wr_vref_commands<MC>(i_target,
                                            l_mrs06,
                                            i_rank,
                                            io_inst),
             "%s Failed add_latch_wr_vref_commands in setup_latch_wr_vref_commands_by_rank",
             mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace DDR4
} // close namespace mss

#endif
