/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/mainline_mpe_trap.H $ */
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
/// @file mainline_mpe_trap.H
/// @brief Subroutines for the MC mainline mpe address trap registers (MBNCER*Q)
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MAINLINE_MPE_TRAP_H_
#define _MSS_MAINLINE_MPE_TRAP_H_

#include <fapi2.H>
#include <lib/mcbist/address.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace mainline_mpe_trap
{

///
/// @brief Read MBS Mainline MPE Address Trap (MBMPER*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    const auto& l_mcbist_target = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    FAPI_TRY( mss::getScom(l_mcbist_target, (TT::MAINLINE_MPE_REGS[l_port]), o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Mainline MPE Address Trap (MBMPER*Q) register
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T, typename TT = eccTraits<T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    const auto& l_mcbist_target = mss::find_target<fapi2::TARGET_TYPE_MCBIST>(i_target);
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    FAPI_TRY( mss::putScom(l_mcbist_target, (TT::MAINLINE_MPE_REGS[l_port]), i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_address
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_address mcbist::address form of address field
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_address( fapi2::buffer<uint64_t>& io_data, const mcbist::address& i_address)
{
    io_data.insertFromRight<TT::MPE_ADDR_TRAP, TT::MPE_ADDR_TRAP_LEN>(uint64_t(i_address));
    FAPI_INF("set_address: 0x%016lx", uint64_t(i_address));
}

///
/// @brief get_address
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_address mcbist::address form of address field
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_address( const fapi2::buffer<uint64_t>& i_data, mcbist::address& o_address )
{
    uint64_t l_addr = 0;
    i_data.extractToRight<TT::MPE_ADDR_TRAP, TT::MPE_ADDR_TRAP_LEN>(l_addr);
    o_address = mcbist::address(l_addr);
    FAPI_INF("get_address: 0x%016lx", uint64_t(l_addr));
}

///
/// @brief set_mpe_on_rce
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in, out] io_data the register value
/// @param[in] i_state mss::YES or mss::NO - desired state
/// @note MBMPER0Q_PORT_0_MAINLINE_MPE_ON_RCE: Indicates whether if this error
/// @note came on the retry of a UE, RCD, or AUE as part of an RCE
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void set_mpe_on_rce( fapi2::buffer<uint64_t>& io_data, const mss::states i_state )
{
    io_data.writeBit<TT::MPE_ON_RCE>(i_state);
    FAPI_INF("set_mpe_on_rce: 0x%01lx", i_state);
}

///
/// @brief get_mpe_on_rce
/// @tparam T fapi2 Target Type defaults to TARGET_TYPE_MCA
/// @tparam TT traits type defaults to eccTraits<T>
/// @param[in] i_data the register value
/// @param[out] o_state mss::YES or mss::NO - representing the state of the field
/// @note MBMPER0Q_PORT_0_MAINLINE_MPE_ON_RCE: Indicates whether if this error
/// @note came on the retry of a UE, RCD, or AUE as part of an RCE
///
template< fapi2::TargetType T = fapi2::TARGET_TYPE_MCA, typename TT = eccTraits<T> >
inline void get_mpe_on_rce( const fapi2::buffer<uint64_t>& i_data, mss::states& o_state )
{
    o_state = (i_data.getBit<TT::MPE_ON_RCE>() == false) ? mss::NO : mss::YES;
    FAPI_INF("get_mpe_on_rce: 0x%01lx", o_state);
}

} // close namespace mainline_mpe_trap

} // close namespace ecc

} // close namespace mss

#endif
