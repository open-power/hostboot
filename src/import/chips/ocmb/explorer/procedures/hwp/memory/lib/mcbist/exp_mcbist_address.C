/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/mcbist/exp_mcbist_address.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
// EKB-Mirror-To: hostboot

///
/// @file exp_mcbist_address.C
/// @brief Explorer specialization of MCBST address class
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/mcbist/gen_mss_mcbist_address.H>
#include <lib/mcbist/exp_mcbist_traits.H>

namespace mss
{

namespace mcbist
{

///
/// @brief Set the DIMM value for an address - EXPLORER specialization
/// @param[in] i_value the value to set
/// @note 0 is the DIMM[0] != 0 is DIMM[1]
/// @return address& for method chaining
///
template<>
address<mss::mc_type::EXPLORER>& address<mss::mc_type::EXPLORER>::set_dimm( const uint64_t i_value )
{
    using TT = mcbistAddrTraits<mss::mc_type::EXPLORER>;

    return set_field<TT::DIMM>(i_value);
}

///
/// @brief Get the DIMM value for an address - EXPLORER specialization
/// @return right-aligned uint64_t representing the value
///
template<>
uint64_t address<mss::mc_type::EXPLORER>::get_dimm() const
{
    using TT = mcbistAddrTraits<mss::mc_type::EXPLORER>;

    return get_field<TT::DIMM>();
}

///
/// @brief Set the port and DIMM value for an address - EXPLORER specialization
/// @param[in] i_value the value to set
/// @return address& for method chaining
/// @note Useful for indexing all ports/DIMM on a controller
///
template<>
address<mss::mc_type::EXPLORER>& address<mss::mc_type::EXPLORER>::set_port_dimm( const fapi2::buffer<uint64_t> i_value )
{
    using TT = mcbistAddrTraits<mss::mc_type::EXPLORER>;

    uint64_t l_read_port = 0;

    i_value.extractToRight<TT::PORT_START, TT::PORT_LEN>(l_read_port);
    return set_dimm(i_value.getBit<TT::DIMM_BIT>()).set_port(l_read_port);
}

///
/// @brief Get the port and DIMM value for an address - EXPLORER specialization
/// @return right-aligned uint64_t representing the value
/// @note Useful for indexing all ports/DIMM on a controller
///
template<>
uint64_t address<mss::mc_type::EXPLORER>::get_port_dimm() const
{
    using TT = mcbistAddrTraits<mss::mc_type::EXPLORER>;

    fapi2::buffer<uint64_t> l_value;

    l_value.insertFromRight<TT::PORT_START, TT::PORT_LEN>(get_port());
    l_value.writeBit<TT::DIMM_BIT>(get_dimm());

    return l_value;
}

} // close namespace mcbist
} // close namespace mss
