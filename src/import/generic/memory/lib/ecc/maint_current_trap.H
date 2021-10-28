/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/maint_current_trap.H $      */
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
/// @file maint_current_trap.H
/// @brief Subroutines for the MC maint current address trap register (MCBMCATQ)
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MAINT_CURRENT_TRAP_H_
#define _MSS_MAINT_CURRENT_TRAP_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace maint_current_trap
{

///
/// @brief Read MBS Mainline MPE Address Trap (MCBMCATQ) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mem port
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    const auto& l_mc_target = mss::find_target<eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);
    using TT = eccTraits<MC, eccMCTraits<MC>::MC_TARGET_TYPE>;

    FAPI_TRY( mss::getScom(l_mc_target, TT::MPE_ADDR_TRAP_REG, o_data) );
    FAPI_INF("read: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Mainline MPE Address Trap (MCBMCATQ) register
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @param[in] i_target the fapi2 target of the mem port
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target,
                                const fapi2::buffer<uint64_t>& i_data )
{
    const auto& l_mc_target = mss::find_target<eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);
    using TT = eccTraits<MC, eccMCTraits<MC>::MC_TARGET_TYPE>;

    FAPI_TRY( mss::putScom(l_mc_target, TT::MPE_ADDR_TRAP_REG, i_data) );
    FAPI_INF("write: 0x%016lx", i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_address
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_address mcbist::address form of address field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_address( fapi2::buffer<uint64_t>& io_data, const mcbist::address& i_address)
{
    io_data.insertFromRight<TT::CURRENT_ADDR_TRAP, TT::CURRENT_ADDR_TRAP_LEN>(uint64_t(i_address));
    FAPI_INF("set_address: 0x%016lx", uint64_t(i_address));
}

///
/// @brief get_address
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_address mcbist::address form of address field
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_address( const fapi2::buffer<uint64_t>& i_data, mcbist::address& o_address )
{
    uint64_t l_addr = 0;
    i_data.extractToRight<TT::CURRENT_ADDR_TRAP, TT::CURRENT_ADDR_TRAP_LEN>(l_addr);
    o_address = mcbist::address(l_addr);
    FAPI_INF("get_address: 0x%016lx", uint64_t(l_addr));
}

///
/// @brief set_port
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value - desired value
/// @note MCBMCATQ_CFG_CURRENT_PORT_TRAP: If MCBCFGQ_cfg_current_addr_trap_update_dis = 0, then this
/// @note field will store port. This field is ONLY valid in maint_addr_mode. Garabage otherwise.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_port( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::CURRENT_PORT, TT::CURRENT_PORT_LEN>(i_value);
    FAPI_INF("set_port: 0x%01lx", i_value);
}

///
/// @brief get_port
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value - representing the field value
/// @note MCBMCATQ_CFG_CURRENT_PORT_TRAP: If MCBCFGQ_cfg_current_addr_trap_update_dis = 0, then this
/// @note field will store port. This field is ONLY valid in maint_addr_mode. Garabage otherwise.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_port( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::CURRENT_PORT, TT::CURRENT_PORT_LEN>(o_value);
    FAPI_INF("get_port: 0x%01lx", o_value);
}

///
/// @brief set_dimm
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value - desired value
/// @note MCBMCATQ_CFG_CURRENT_DIMM_TRAP: If MCBCFGQ_cfg_current_addr_trap_update_dis = 0, then this
/// @note field will store dimm select.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_dimm( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.writeBit<TT::CURRENT_DIMM>(i_value);
    FAPI_INF("set_dimm: 0x%01lx", i_value);
}

///
/// @brief get_dimm
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MEM_PORT_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value - representing the field value
/// @note MCBMCATQ_CFG_CURRENT_DIMM_TRAP: If MCBCFGQ_cfg_current_addr_trap_update_dis = 0, then this
/// @note field will store dimm select.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MEM_PORT_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_dimm( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    o_value = i_data.getBit<TT::CURRENT_DIMM>();
    FAPI_INF("get_dimm: 0x%01lx", o_value);
}

} // close namespace maint_current_trap

} // close namespace ecc

} // close namespace mss

#endif
