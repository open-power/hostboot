/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/ecc.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file ecc.H
/// @brief Top level API for MSS ECC
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_H_
#define _MSS_ECC_H_

#include <fapi2.H>
#include <lib/mcbist/mcbist.H>
#include <lib/mcbist/address.H>
#include <lib/ecc/ecc_traits.H>
#include <lib/ecc/galois.H>
#include <lib/ecc/hw_mark_store.H>
#include <lib/ecc/fw_mark_store.H>
#include <lib/ecc/mainline_nce_trap.H>
#include <lib/ecc/mainline_rce_trap.H>
#include <lib/ecc/mainline_mpe_trap.H>
#include <lib/ecc/mainline_ue_trap.H>
#include <lib/ecc/mainline_aue_trap.H>
#include <lib/ecc/mbs_error_vector_trap.H>
#include <lib/ecc/maint_current_trap.H>
#include <lib/ecc/read_error_count_regs.H>
#include <lib/ecc/modal_symbol_count.H>
#include <lib/ecc/mark_shadow_reg.H>

namespace mss
{

namespace ecc
{

///
/// @brief Get Hardware Mark Store
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_rank the desired rank
/// @param[out] o_galois the Galois code of the mark
/// @param[out] o_confirmed true if the mark is a chipmark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_hwms( const fapi2::Target<T>& i_target,
                                   const uint64_t i_rank,
                                   uint64_t& o_galois,
                                   mss::states& o_confirmed )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::hwms::read(i_target, i_rank, l_buffer) );
    mss::ecc::hwms::get_chipmark(l_buffer, o_galois);
    mss::ecc::hwms::get_confirmed(l_buffer, o_confirmed);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set Hardware Mark Store
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_rank the desired rank
/// @param[in] i_galois the Galois code of the mark, or set to 0 to clear mark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode set_hwms( const fapi2::Target<T>& i_target,
                                   const uint64_t i_rank,
                                   const uint64_t i_galois )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint8_t l_symbol = 0;

    // galois value of 0 means to clear the mark so only fill in fields if non-zero
    if (i_galois != 0)
    {
        // check for valid Galois code
        FAPI_TRY( mss::ecc::galois_to_symbol( (uint8_t)i_galois, l_symbol) );

        mss::ecc::hwms::set_chipmark(l_buffer, i_galois);
        mss::ecc::hwms::set_confirmed(l_buffer, mss::YES);
        mss::ecc::hwms::set_exit_1(l_buffer, mss::YES);
    }

    FAPI_TRY( mss::ecc::hwms::write(i_target, i_rank, l_buffer) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Firmware Mark Store
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_rank the desired rank
/// @param[out] o_galois the Galois code of the mark
/// @param[out] o_type the type code of the mark
/// @param[out] o_region the region code of the mark
/// @param[out] o_address the starting address of the mark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_fwms( const fapi2::Target<T>& i_target,
                                   const uint64_t i_rank,
                                   uint64_t& o_galois,
                                   mss::ecc::fwms::mark_type& o_type,
                                   mss::ecc::fwms::mark_region& o_region,
                                   mss::mcbist::address& o_address )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::fwms::read(i_target, i_rank, l_buffer) );
    mss::ecc::fwms::get_mark(l_buffer, o_galois);
    mss::ecc::fwms::get_type(l_buffer, o_type);
    mss::ecc::fwms::get_region(l_buffer, o_region);
    mss::ecc::fwms::get_address(l_buffer, o_address);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set Firmware Mark Store
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[in] i_rank the desired rank
/// @param[in] i_galois the Galois code of the mark, or set to 0 to clear mark
/// @param[in] i_type the type code of the mark
/// @param[in] i_region the region code of the mark
/// @param[in] i_address the starting address of the mark
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode set_fwms( const fapi2::Target<T>& i_target,
                                   const uint64_t i_rank,
                                   const uint64_t i_galois,
                                   const mss::ecc::fwms::mark_type i_type,
                                   const mss::ecc::fwms::mark_region i_region,
                                   const mss::mcbist::address i_address )
{
    fapi2::buffer<uint64_t> l_buffer = 0;
    uint8_t l_symbol = 0;

    // galois value of 0 means to clear the mark so only fill in fields if non-zero
    if (i_galois != 0)
    {
        // check for valid Galois code
        FAPI_TRY( mss::ecc::galois_to_symbol( (uint8_t)i_galois, l_symbol) );

        mss::ecc::fwms::set_mark(l_buffer, i_galois);
        mss::ecc::fwms::set_type(l_buffer, i_type);
        mss::ecc::fwms::set_region(l_buffer, i_region);
        mss::ecc::fwms::set_address(l_buffer, i_address);
        mss::ecc::fwms::set_exit_1(l_buffer, mss::YES);
    }

    FAPI_TRY( mss::ecc::fwms::write(i_target, i_rank, l_buffer) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Query Hardware Marks
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_marks vector of Galois codes of any marks set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note no rank information is returned
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_hw_marks( const fapi2::Target<T>& i_target,
                                       std::vector<uint64_t>& o_marks )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_galois = 0;
    auto l_confirmed = mss::states::NO;

    o_marks.clear();

    for (uint64_t l_rank = 0; l_rank < MAX_MRANK_PER_PORT; ++l_rank)
    {
        FAPI_TRY( get_hwms(i_target, l_rank, l_galois, l_confirmed) );

        if (l_confirmed == mss::states::YES)
        {
            o_marks.push_back(l_galois);
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Query Firmware Marks
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_marks vector of Galois codes of any marks set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note no rank information is returned
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_fw_marks( const fapi2::Target<T>& i_target,
                                       std::vector<uint64_t>& o_marks )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_galois = 0;
    auto l_type = mss::ecc::fwms::mark_type::CHIP;
    auto l_region = mss::ecc::fwms::mark_region::UNIVERSAL;
    mss::mcbist::address l_address;

    o_marks.clear();

    for (uint64_t l_rank = 0; l_rank < MAX_MRANK_PER_PORT; ++l_rank)
    {
        FAPI_TRY( get_fwms(i_target, l_rank, l_galois, l_type, l_region, l_address) );

        if (l_region != mss::ecc::fwms::mark_region::DISABLED)
        {
            o_marks.push_back(l_galois);
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline NCE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline nce
/// @param[out] o_on_rce mss::YES if nce is part of an rce
/// @param[out] o_is_tce mss::YES if nce is a tce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_nce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce,
        mss::states& o_is_tce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_nce_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_address(l_buffer, o_address);
    mss::ecc::mainline_nce_trap::get_nce_on_rce(l_buffer, o_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce(l_buffer, o_is_tce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline NCE error vector traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_galois the Galois code
/// @param[out] o_magnitude the magnitude of the error
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_nce_error_vector_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_galois,
        uint64_t& o_magnitude )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mbs_error_vector_trap::read(i_target, l_buffer) );
    mss::ecc::mbs_error_vector_trap::get_nce_galois(i_target, l_buffer, o_galois);
    mss::ecc::mbs_error_vector_trap::get_nce_magnitude(i_target, l_buffer, o_magnitude);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline TCE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline nce
/// @param[out] o_on_rce mss::YES if nce is part of an rce
/// @param[out] o_is_tce mss::YES if nce is a tce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_tce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce,
        mss::states& o_is_tce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_nce_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_address(l_buffer, o_address);
    mss::ecc::mainline_nce_trap::get_nce_on_rce(l_buffer, o_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce(l_buffer, o_is_tce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline TCE error vector traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_nce_galois the Galois code
/// @param[out] o_nce_magnitude the magnitude of the error
/// @param[out] o_tce_galois the Galois code
/// @param[out] o_tce_magnitude the magnitude of the error
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_tce_error_vector_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_nce_galois,
        uint64_t& o_nce_magnitude,
        uint64_t& o_tce_galois,
        uint64_t& o_tce_magnitude )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mbs_error_vector_trap::read(i_target, l_buffer) );
    mss::ecc::mbs_error_vector_trap::get_nce_galois(i_target, l_buffer, o_nce_galois);
    mss::ecc::mbs_error_vector_trap::get_nce_magnitude(i_target, l_buffer, o_nce_magnitude);
    mss::ecc::mbs_error_vector_trap::get_tce_galois(i_target, l_buffer, o_tce_galois);
    mss::ecc::mbs_error_vector_trap::get_tce_magnitude(i_target, l_buffer, o_tce_magnitude);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline MPE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline mpe
/// @param[out] o_on_rce mss::YES if mpe is part of an rce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_mpe_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_mpe_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_mpe_trap::get_address(l_buffer, o_address);
    mss::ecc::mainline_mpe_trap::get_mpe_on_rce(l_buffer, o_on_rce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline RCE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline rce
/// @param[out] o_nce_on_rce mss::YES if nce is part of an rce
/// @param[out] o_tce_on_rce mss::YES if tce is part of an rce
/// @param[out] o_mpe_on_rce mss::YES if mpe is part of an rce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_rce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_nce_on_rce,
        mss::states& o_tce_on_rce,
        mss::states& o_mpe_on_rce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_rce_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_rce_trap::get_address(l_buffer, o_address);

    FAPI_TRY( mss::ecc::mainline_nce_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_nce_on_rce(l_buffer, o_nce_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce(l_buffer, o_tce_on_rce);

    FAPI_TRY( mss::ecc::mainline_mpe_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_mpe_trap::get_mpe_on_rce(l_buffer, o_mpe_on_rce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline UE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline ue
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_ue_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_ue_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_ue_trap::get_address(l_buffer, o_address);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline AUE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline aue
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_aue_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_aue_trap::read(i_target, l_buffer) );
    mss::ecc::mainline_aue_trap::get_address(l_buffer, o_address);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get IMPE address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_chipmark the mark location (Galois code) of the last mark placed
/// @param[out] o_rank the rank of the last mark placed
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_impe_addr_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_chipmark,
        uint64_t& o_rank )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mark_shadow_reg::read(i_target, l_buffer) );
    mss::ecc::mark_shadow_reg::get_chipmark(l_buffer, o_chipmark);
    mss::ecc::mark_shadow_reg::get_rank(l_buffer, o_rank);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Maint Current address traps
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the last address executed
/// @param[out] o_port_trap port value if MCBCFGQ_cfg_current_addr_trap_update_dis == 0
/// @param[out] o_dimm_trap dimm value if MCBCFGQ_cfg_current_addr_trap_update_dis == 0
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_maint_current_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        uint64_t& o_port_trap,
        uint64_t& o_dimm_trap )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::maint_current_trap::read(i_target, l_buffer) );
    mss::ecc::maint_current_trap::get_address(l_buffer, o_address);
    mss::ecc::maint_current_trap::get_port(l_buffer, o_port_trap);
    mss::ecc::maint_current_trap::get_dimm(l_buffer, o_dimm_trap);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Per Symbol Error Counts
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_error_counts vector of symbol error counts
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode get_per_symbol_error_counts( const fapi2::Target<T>& i_target,
        std::vector<uint64_t>& o_error_counts )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_count = 0;
    o_error_counts.clear();

    for (uint64_t l_index = 0; l_index < TT::NUM_MBSSYM_REGS; ++l_index)
    {
        FAPI_TRY( mss::ecc::modal_symbol_count::read(i_target, l_index, l_buffer) );

        for (uint64_t l_symbol = 0; l_symbol < TT::MODAL_SYMBOL_COUNTERS_PER_REG; ++l_symbol)
        {
            l_count = 0;
            mss::ecc::modal_symbol_count::get_count(l_buffer, l_symbol, l_count);
            o_error_counts.push_back(l_count);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Intermittent NCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of intermittent NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_intermittent_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_intermittent_ce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Soft NCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of soft NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_soft_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_soft_ce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Hard NCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of hard NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_hard_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_hard_ce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Intermittent MCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of intermittent MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_intermittent_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_intermittent_mce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Soft MCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of soft MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_soft_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_soft_mce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Hard MCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of hard MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_hard_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_hard_mce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get ICE (IMPE) error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of ICE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_ice_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_ice_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get UE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of UE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_ue_count( const fapi2::Target<T>& i_target,
                                       uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_ue_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get AUE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of AUE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_aue_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_aue_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get RCE error count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of RCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_rce_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_rce_count(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get MCE symbol count
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_symbol0_count count of symbol 0 errors
/// @param[out] o_symbol1_count count of symbol 1 errors
/// @param[out] o_symbol2_count count of symbol 2 errors
/// @param[out] o_symbol3_count count of symbol 3 errors
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode get_mce_symbol_count( const fapi2::Target<T>& i_target,
        uint64_t& o_symbol0_count,
        uint64_t& o_symbol1_count,
        uint64_t& o_symbol2_count,
        uint64_t& o_symbol3_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mark_symbol_count_reg::read(i_target, l_buffer) );
    mss::ecc::mark_symbol_count_reg::get_symbol0_count(l_buffer, o_symbol0_count);
    mss::ecc::mark_symbol_count_reg::get_symbol1_count(l_buffer, o_symbol1_count);
    mss::ecc::mark_symbol_count_reg::get_symbol2_count(l_buffer, o_symbol2_count);
    mss::ecc::mark_symbol_count_reg::get_symbol3_count(l_buffer, o_symbol3_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear all MAINT.ECC counters
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
inline fapi2::ReturnCode clear_all_counters( const fapi2::Target<T>& i_target )
{
    return ( mss::mcbist::reset_errors(i_target) );
}


} // close namespace ecc

} // close namespace mss

#endif
