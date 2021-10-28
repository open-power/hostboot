/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/ecc.H $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_ECC_H_
#define _MSS_ECC_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/ecc/galois.H>
#include <generic/memory/lib/ecc/hw_mark_store.H>
#include <generic/memory/lib/ecc/fw_mark_store.H>
#include <generic/memory/lib/ecc/mainline_nce_trap.H>
#include <generic/memory/lib/ecc/mainline_rce_trap.H>
#include <generic/memory/lib/ecc/mainline_mpe_trap.H>
#include <generic/memory/lib/ecc/mainline_ue_trap.H>
#include <generic/memory/lib/ecc/mainline_aue_trap.H>
#include <generic/memory/lib/ecc/mbs_error_vector_trap.H>
#include <generic/memory/lib/ecc/maint_current_trap.H>
#include <generic/memory/lib/ecc/read_error_count_regs.H>
#include <generic/memory/lib/ecc/modal_symbol_count.H>
#include <generic/memory/lib/ecc/mark_shadow_reg.H>

namespace mss
{

namespace ecc
{

///
/// @brief Query Hardware Marks
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target
/// @param[out] o_marks vector of Galois codes of any marks set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note no rank information is returned
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode get_hw_marks( const fapi2::Target<T>& i_target,
                                       std::vector<uint64_t>& o_marks )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_galois = 0;
    auto l_confirmed = mss::states::NO;

    o_marks.clear();

    for (uint64_t l_port_rank = 0; l_port_rank < TT::ECC_MAX_MRANK_PER_PORT; ++l_port_rank)
    {
        FAPI_TRY( get_hwms<MC>(i_target, l_port_rank, l_galois, l_confirmed) );

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
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target
/// @param[out] o_marks vector of Galois codes of any marks set
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
/// @note no rank information is returned
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode get_fw_marks( const fapi2::Target<T>& i_target,
                                       std::vector<uint64_t>& o_marks )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_galois = 0;
    auto l_type = mss::ecc::fwms::mark_type::CHIP;
    auto l_region = mss::ecc::fwms::mark_region::UNIVERSAL;
    mss::mcbist::address l_address;

    o_marks.clear();

    for (uint64_t l_port_rank = 0; l_port_rank < TT::ECC_MAX_MRANK_PER_PORT; ++l_port_rank)
    {
        FAPI_TRY( get_fwms<MC>(i_target, l_port_rank, l_galois, l_type, l_region, l_address) );

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
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline nce
/// @param[out] o_on_rce mss::YES if nce is part of an rce
/// @param[out] o_is_tce mss::YES if nce is a tce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_nce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce,
        mss::states& o_is_tce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_nce_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_address<MC>(l_buffer, o_address);
    mss::ecc::mainline_nce_trap::get_nce_on_rce<MC>(l_buffer, o_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce<MC>(l_buffer, o_is_tce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline NCE error vector traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_galois the Galois code
/// @param[out] o_magnitude the magnitude of the error
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_nce_error_vector_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_galois,
        uint64_t& o_magnitude )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mbs_error_vector_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mbs_error_vector_trap::get_nce_galois<MC>(i_target, l_buffer, o_galois);
    mss::ecc::mbs_error_vector_trap::get_nce_magnitude<MC>(i_target, l_buffer, o_magnitude);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline TCE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline nce
/// @param[out] o_on_rce mss::YES if nce is part of an rce
/// @param[out] o_is_tce mss::YES if nce is a tce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_tce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce,
        mss::states& o_is_tce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_nce_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_address<MC>(l_buffer, o_address);
    mss::ecc::mainline_nce_trap::get_nce_on_rce<MC>(l_buffer, o_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce<MC>(l_buffer, o_is_tce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline TCE error vector traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_nce_galois the Galois code
/// @param[out] o_nce_magnitude the magnitude of the error
/// @param[out] o_tce_galois the Galois code
/// @param[out] o_tce_magnitude the magnitude of the error
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_tce_error_vector_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_nce_galois,
        uint64_t& o_nce_magnitude,
        uint64_t& o_tce_galois,
        uint64_t& o_tce_magnitude )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mbs_error_vector_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mbs_error_vector_trap::get_nce_galois<MC>(i_target, l_buffer, o_nce_galois);
    mss::ecc::mbs_error_vector_trap::get_nce_magnitude<MC>(i_target, l_buffer, o_nce_magnitude);
    mss::ecc::mbs_error_vector_trap::get_tce_galois<MC>(i_target, l_buffer, o_tce_galois);
    mss::ecc::mbs_error_vector_trap::get_tce_magnitude<MC>(i_target, l_buffer, o_tce_magnitude);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline MPE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline mpe
/// @param[out] o_on_rce mss::YES if mpe is part of an rce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_mpe_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_on_rce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_mpe_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_mpe_trap::get_address<MC>(l_buffer, o_address);
    mss::ecc::mainline_mpe_trap::get_mpe_on_rce<MC>(l_buffer, o_on_rce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline RCE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline rce
/// @param[out] o_nce_on_rce mss::YES if nce is part of an rce
/// @param[out] o_tce_on_rce mss::YES if tce is part of an rce
/// @param[out] o_mpe_on_rce mss::YES if mpe is part of an rce
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_rce_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        mss::states& o_nce_on_rce,
        mss::states& o_tce_on_rce,
        mss::states& o_mpe_on_rce )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_rce_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_rce_trap::get_address<MC>(l_buffer, o_address);

    FAPI_TRY( mss::ecc::mainline_nce_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_nce_trap::get_nce_on_rce<MC>(l_buffer, o_nce_on_rce);
    mss::ecc::mainline_nce_trap::get_nce_is_tce<MC>(l_buffer, o_tce_on_rce);

    FAPI_TRY( mss::ecc::mainline_mpe_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_mpe_trap::get_mpe_on_rce<MC>(l_buffer, o_mpe_on_rce);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline UE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline ue
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_ue_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_ue_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_ue_trap::get_address<MC>(l_buffer, o_address);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Mainline AUE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the trap address of the last mainline aue
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_aue_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mainline_aue_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::mainline_aue_trap::get_address<MC>(l_buffer, o_address);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get IMPE address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_chipmark the mark location (Galois code) of the last mark placed
/// @param[out] o_port_rank the rank of the last mark placed
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_impe_addr_trap( const fapi2::Target<T>& i_target,
        uint64_t& o_chipmark,
        uint64_t& o_port_rank )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mark_shadow_reg::read<MC>(i_target, l_buffer) );
    mss::ecc::mark_shadow_reg::get_chipmark<MC>(l_buffer, o_chipmark);
    mss::ecc::mark_shadow_reg::get_rank<MC>(l_buffer, o_port_rank);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Maint Current address traps
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_address the last address executed
/// @param[out] o_port_trap port value if MCBCFGQ_cfg_current_addr_trap_update_dis == 0
/// @param[out] o_dimm_trap dimm value if MCBCFGQ_cfg_current_addr_trap_update_dis == 0
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_maint_current_addr_trap( const fapi2::Target<T>& i_target,
        mss::mcbist::address& o_address,
        uint64_t& o_port_trap,
        uint64_t& o_dimm_trap )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::maint_current_trap::read<MC>(i_target, l_buffer) );
    mss::ecc::maint_current_trap::get_address<MC>(l_buffer, o_address);
    mss::ecc::maint_current_trap::get_port<MC>(l_buffer, o_port_trap);
    mss::ecc::maint_current_trap::get_dimm<MC>(l_buffer, o_dimm_trap);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Per Symbol Error Counts
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target
/// @param[out] o_error_counts vector of symbol error counts
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///

template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode get_per_symbol_error_counts( const fapi2::Target<T>& i_target,
        std::vector<uint64_t>& o_error_counts )
{
    fapi2::buffer<uint64_t> l_buffer;
    uint64_t l_count = 0;
    o_error_counts.clear();

    for (uint64_t l_index = 0; l_index < TT::NUM_MBSSYM_REGS; ++l_index)
    {
        FAPI_TRY( mss::ecc::modal_symbol_count::read<MC>(i_target, l_index, l_buffer) );

        for (uint64_t l_symbol = 0; l_symbol < TT::MODAL_SYMBOL_COUNTERS_PER_REG; ++l_symbol)
        {
            l_count = 0;
            mss::ecc::modal_symbol_count::get_count<MC>(l_buffer, l_symbol, l_count);
            o_error_counts.push_back(l_count);
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Intermittent NCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of intermittent NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_intermittent_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_intermittent_ce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Soft NCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of soft NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_soft_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_soft_ce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Hard NCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of hard NCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_hard_nce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_hard_ce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Intermittent MCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of intermittent MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_intermittent_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_intermittent_mce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Soft MCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of soft MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_soft_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg0::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg0::get_soft_mce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get Hard MCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of hard MCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_hard_mce_count( const fapi2::Target<T>& i_target,
        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_hard_mce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get ICE (IMPE) error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of ICE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_ice_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_ice_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get UE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of UE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_ue_count( const fapi2::Target<T>& i_target,
                                       uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_ue_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get AUE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of AUE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_aue_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_aue_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get RCE error count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_count count of RCE events
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_rce_count( const fapi2::Target<T>& i_target,
                                        uint64_t& o_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::read_error_count_reg1::read<MC>(i_target, l_buffer) );
    mss::ecc::read_error_count_reg1::get_rce_count<MC>(l_buffer, o_count);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Get MCE symbol count
/// @tparam MC the memory controller type
/// @tparam T the fapi2::TargetType - derived
/// @param[in] i_target the fapi2 target
/// @param[out] o_symbol0_count count of symbol 0 errors
/// @param[out] o_symbol1_count count of symbol 1 errors
/// @param[out] o_symbol2_count count of symbol 2 errors
/// @param[out] o_symbol3_count count of symbol 3 errors
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode get_mce_symbol_count( const fapi2::Target<T>& i_target,
        uint64_t& o_symbol0_count,
        uint64_t& o_symbol1_count,
        uint64_t& o_symbol2_count,
        uint64_t& o_symbol3_count )
{
    fapi2::buffer<uint64_t> l_buffer;

    FAPI_TRY( mss::ecc::mark_symbol_count_reg::read<MC>(i_target, l_buffer) );
    mss::ecc::mark_symbol_count_reg::get_symbol0_count<MC>(l_buffer, o_symbol0_count);
    mss::ecc::mark_symbol_count_reg::get_symbol1_count<MC>(l_buffer, o_symbol1_count);
    mss::ecc::mark_symbol_count_reg::get_symbol2_count<MC>(l_buffer, o_symbol2_count);
    mss::ecc::mark_symbol_count_reg::get_symbol3_count<MC>(l_buffer, o_symbol3_count);

fapi_try_exit:
    return fapi2::current_err;
}

} // close namespace ecc

} // close namespace mss

#endif
