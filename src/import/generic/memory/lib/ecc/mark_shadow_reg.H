/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/mark_shadow_reg.H $         */
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
/// @file mark_shadow_reg.H
/// @brief Subroutines for the MC mark shadow registers (MSR)
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MARK_SHADOW_REG_H_
#define _MSS_MARK_SHADOW_REG_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace mark_shadow_reg
{

///
/// @brief Read Mark Shadow register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::MARK_SHADOW_REG, o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write Mark Shadow register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::MARK_SHADOW_REG, i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_chipmark
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_chipmark( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SHADOW_CHIPMARK, TT::SHADOW_CHIPMARK_LEN>(i_value);
    FAPI_INF("set_chipmark: 0x%016lx", i_value);
}

///
/// @brief get_chipmark
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_chipmark( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SHADOW_CHIPMARK, TT::SHADOW_CHIPMARK_LEN>(o_value);
    FAPI_INF("get_chipmark: 0x%016lx", o_value);
}

///
/// @brief set_rank
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_rank( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SHADOW_RANK, TT::SHADOW_RANK_LEN>(i_value);
    FAPI_INF("set_rank: 0x%016lx", i_value);
}

///
/// @brief get_rank
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_rank( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SHADOW_RANK, TT::SHADOW_RANK_LEN>(o_value);
    FAPI_INF("get_rank: 0x%016lx", o_value);
}

} // close namespace mark_shadow_reg

} // close namespace ecc

} // close namespace mss

#endif
