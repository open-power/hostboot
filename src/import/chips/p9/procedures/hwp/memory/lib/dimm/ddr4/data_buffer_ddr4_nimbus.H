/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/data_buffer_ddr4_nimbus.H $ */
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

///
/// @file data_buffer_ddr4_nimbus.H
/// @brief Code to support data_buffer_ddr4
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_DATA_BUFFER_DDR4_NIMBUS_H_
#define _MSS_DATA_BUFFER_DDR4_NIMBUS_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <lib/dimm/bcw_load_ddr4.H>
#include <lib/phy/dp16.H>
#include <lib/dimm/ddr4/control_word_ddr4_nimbus.H>
#include <lib/eff_config/timing.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/ddr4/data_buffer_ddr4.H>

namespace mss
{


namespace ddr4
{

///
/// @brief Sets the function space for the BCW
/// @param[in] i_target a DIMM target
/// @param[in] i_func_space the functon space number we want
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode function_space_select(const fapi2::Target< fapi2::TARGET_TYPE_DIMM >& i_target,
        const uint64_t i_func_space,
        std::vector< ccs::instruction_t >& io_inst)
{
    FAPI_ASSERT(i_func_space <= MAX_FUNC_SPACE,
                fapi2::MSS_LRDIMM_FUNC_SPACE_OUT_OF_RANGE()
                .set_TARGET(i_target)
                .set_MAX_FUNC_SPACE(MAX_FUNC_SPACE)
                .set_FUNC_SPACE(i_func_space),
                "%s function space (%u) greater than maximum range (%u)",
                mss::c_str(i_target), i_func_space, MAX_FUNC_SPACE);

    // function space bits for the function space selector are
    // don't cares (XXX).  We choose 0 for simplicity.
    {
        uint8_t l_sim = 0;
        FAPI_TRY(mss::is_simulation(l_sim));

        cw_data l_data( FUNC_SPACE_0, FUNC_SPACE_SELECT_CW, i_func_space, mss::tmrd() );

        FAPI_TRY( control_word_engine<BCW_8BIT>(i_target, l_data, l_sim, io_inst),
                  "%s. Failed control_word_engine for 8-bit BCW (F%dBC%02lxX)",
                  mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number) );

        // I don't know what already existed in this ccs instruction vector beforehand so
        // I use the back() method to access the last added ccs instruction of interest
        FAPI_INF("%s. F%dBC%02lx ccs inst 0x%016llx:0x%016llx, data: %d",
                 mss::c_str(i_target), uint8_t(l_data.iv_func_space), uint8_t(l_data.iv_number),
                 uint64_t(io_inst.back().arr0), uint64_t(io_inst.back().arr1), uint8_t(l_data.iv_data) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Inserts a function space selector into a vector of cw_info functions
/// @param[in] i_func_space the functon space number we want
/// @param[in] i_iterator an iterator to a vector of cw_info structures
/// @param[in,out] io_vector vector in which to insert the function space selector
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode insert_function_space_select(const uint64_t i_func_space,
        const std::vector< cw_info >::iterator& i_iterator,
        std::vector< cw_info >& io_vector)
{
    // we use this function for PBA so we need to go with the PBA safe value
    constexpr uint64_t PBA_SAFE_DELAY = 255;
    FAPI_ASSERT(i_func_space <= MAX_FUNC_SPACE,
                fapi2::MSS_LRDIMM_INSERT_FUNC_SPACE_OUT_OF_RANGE()
                .set_MAX_FUNC_SPACE(MAX_FUNC_SPACE)
                .set_FUNC_SPACE(i_func_space),
                "function space (%u) greater than maximum range (%u)",
                i_func_space, MAX_FUNC_SPACE);
    {
        constexpr uint64_t FUNC_SPACE_LEN = 8;
        cw_info l_info( FUNC_SPACE_0, FUNC_SPACE_SELECT_CW, i_func_space, PBA_SAFE_DELAY, FUNC_SPACE_LEN, cw_info::BCW );
        io_vector.insert(i_iterator, l_info);
    }
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Inserts all needed function space selects into a vector of cw_info functions
/// @param[in,out] io_vector vector in which to insert the function space selector
/// @return FAPI2_RC_SUCCESS if and only if ok
///
inline fapi2::ReturnCode insert_function_space_select(std::vector< cw_info >& io_vector)
{
    fapi2::buffer<uint8_t> l_func_space(FUNC_SPACE_0);

    // Looping on numbers here as using iterators creates memfaults due to the insert
    for(uint64_t i = 0; i < io_vector.size(); ++i)
    {
        // If the current function space is different than our desired one...
        if(l_func_space != io_vector[i].iv_cw_data.iv_func_space)
        {
            // Add in a CW to do the function space change
            l_func_space = io_vector[i].iv_cw_data.iv_func_space;
            auto l_it = io_vector.begin() + i;
            FAPI_TRY(insert_function_space_select(l_func_space, l_it, io_vector));
        }
    }

    // So, we always want to know what function space we're in
    // The way to do that is to always return to one function space
    // The LR spec recommends that we return to the default function space - function space 0
    // If the vector is not at our default function space of function space 0, return to function space 0
    if(l_func_space != FUNC_SPACE_0)
    {
        FAPI_TRY(insert_function_space_select(FUNC_SPACE_0, io_vector.end(), io_vector));
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets data buffer training mode control word
/// @param[in] i_target the DIMM target
/// @param[in] i_mode buffer training mode
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word (BC0C) setting
///
inline fapi2::ReturnCode set_buffer_training( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const training i_mode,
        std::vector< ccs::instruction_t >& io_inst )
{
    // This doesn't need to be reused so it is left local to this function scope
    // Static appears to be playing havoc with HB's compile for some reason
    const std::vector< std::pair<training, uint64_t> > BUFF_TRAINING =
    {
        { NORMAL, 0 },
        { MREP, 1   },
        { DWL, 4    },
        { HWL, 5    },
        { MRD, 6    },
        { MWD, 7    },
        { HIW, 8    },
    };

    // If we can't find the key then the user passed in an invalid mode
    // and this is a user programming error.  So we assert out.
    // find_value_from_key API does the error checking and fails out
    // for any invalid user input. Easier to handle for sparse arrays.
    uint64_t l_encoding = 0;
    fapi2::Assert(find_value_from_key(BUFF_TRAINING, i_mode, l_encoding));

    cw_data l_data(FUNC_SPACE_0, BUFF_TRAIN_MODE_CW, l_encoding, mss::tmrd_l2());
    FAPI_TRY( settings_boilerplate<BCW_4BIT>(i_target, l_data, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets rank presence control word
/// @param[in] i_target a DIMM target
/// @param[in] i_num_package_ranks num of package ranks for LRDIMM
/// @param[out] o_setting bc07 settings
/// @return FAPI2_RC_SUCCESS iff okay
///
static inline fapi2::ReturnCode rank_presence_helper(
    const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
    const uint64_t i_num_package_ranks,
    uint64_t& o_setting )
{
    switch(i_num_package_ranks)
    {
        case 1:
            o_setting = 0b1110;
            break;

        case 2:
            o_setting = 0b1100;
            break;

        case 3:
            o_setting = 0b1000;
            break;

        case 4:
            o_setting = 0b0000;
            break;

        default:
            // While an invalid input can signify a programming error
            // it is expected that this input can come from the eff_master_rank accessor.
            // If it is the latter than we will want to call out an error
            // to raise red flags regarding decoded SPD data that sets this attribute
            FAPI_ASSERT( false,
                         fapi2::MSS_INVALID_NUM_PKG_RANKS()
                         .set_DIMM_TARGET(i_target)
                         .set_NUM_PKG_RANKS(i_num_package_ranks),
                         "%s. Received invalid package rank %d",
                         mss::c_str(i_target), i_num_package_ranks );
            break;
    }

    // If we got here than success
    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    // If we are here then we FAPI_ASSERT'ed out
    return fapi2::current_err;
}

///
/// @brief Sets rank presence control word
/// @param[in] i_target the DIMM target
/// @param[in] i_num_package_ranks num of package ranks for LRDIMM
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word (BC07) setting
///
inline fapi2::ReturnCode set_rank_presence( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_num_package_ranks,
        std::vector< ccs::instruction_t >& io_inst )
{
    // Helper function handles error checking
    uint64_t l_encoding = 0;
    FAPI_TRY( rank_presence_helper( i_target, i_num_package_ranks, l_encoding),
              "%s. Failed to set rank_presence BCW for %d number of package ranks",
              mss::c_str(i_target), i_num_package_ranks );
    {
        cw_data l_data(FUNC_SPACE_0, RANK_PRESENCE_CW, l_encoding, mss::tmrc());
        FAPI_TRY( settings_boilerplate<BCW_4BIT>(i_target, l_data, io_inst) );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets Upper/Lower nibble DRAM interface receive enable training control word
/// @tparam N the nibble of in training (upper/lower)
/// @param[in] i_target the DIMM target
/// @param[in] i_rank DIMM0 rank [0:3] or DIMM1 rank [4:7]
/// @param[in] i_trained_timing the delay MDQS receive enable timing
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS iff ok
/// @note Sets buffer control word ( F[3:0]BC2x ) setting
///
template< mss::nibble N >
fapi2::ReturnCode set_mrep_timing_control( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const uint64_t i_rank,
        const uint64_t i_trained_timing,
        std::vector< ccs::instruction_t >& io_inst )
{
    constexpr size_t MAX_DELAY = 63;

    // These fail assertions are programming input erros
    if( i_rank >= MAX_MRANK_PER_PORT )
    {
        FAPI_ERR("Invalid ranks received (%d) from max allowed (%d)]", i_rank, MAX_MRANK_PER_PORT - 1);
        fapi2::Assert(false);
    }

    if( i_trained_timing > MAX_DELAY )
    {
        FAPI_ERR("Invalid trained delay received (%d tCK) from max allowed (%d tck)", i_trained_timing, MAX_DELAY);
        fapi2::Assert(false);
    }

    // Function space is determined by rank index for control word since it has a [0:3] range
    cw_data l_data( mss::index(i_rank), N, i_trained_timing, mss::tmrc() );
    FAPI_TRY( settings_boilerplate<BCW_8BIT>(i_target, l_data, io_inst) );

fapi_try_exit:
    return fapi2::current_err;
}


} // namespace ddr4
} // namespace mss

#endif
