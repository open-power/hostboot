/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/ecc/nimbus_mbs_error_vector_trap.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file nimbus_mbs_error_vector_trap.H
/// @brief Subroutines for the MC MBS error vector trap registers (MBSEVR*Q)
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _NIMBUS_MBS_ERROR_VECTOR_TRAP_H_
#define _NIMBUS_MBS_ERROR_VECTOR_TRAP_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <lib/utils/nimbus_find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>
#include <generic/memory/lib/ecc/mbs_error_vector_trap.H>

namespace mss
{

namespace ecc
{

namespace mbs_error_vector_trap
{

///
/// @brief set_nce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void set_nce_galois( const fapi2::Target<T>& i_target,
                            fapi2::buffer<uint64_t>& io_data,
                            const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        io_data.insertFromRight<TT::P0_NCE_GALOIS, TT::P0_NCE_GALOIS_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_NCE_GALOIS, TT::P1_NCE_GALOIS_LEN>(i_value);
    }

    FAPI_INF("%s set_nce_galois: 0x%016lx", mss::c_str(i_target), i_value);
}

///
/// @brief get_nce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void get_nce_galois( const fapi2::Target<T>& i_target,
                            const fapi2::buffer<uint64_t>& i_data,
                            uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        i_data.extractToRight<TT::P0_NCE_GALOIS, TT::P0_NCE_GALOIS_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_NCE_GALOIS, TT::P1_NCE_GALOIS_LEN>(o_value);
    }

    FAPI_INF("%s get_nce_galois: 0x%016lx", mss::c_str(i_target), o_value);
}

///
/// @brief set_nce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void set_nce_magnitude( const fapi2::Target<T>& i_target,
                               fapi2::buffer<uint64_t>& io_data,
                               const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        io_data.insertFromRight<TT::P0_NCE_MAGNITUDE, TT::P0_NCE_MAGNITUDE_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_NCE_MAGNITUDE, TT::P1_NCE_MAGNITUDE_LEN>(i_value);
    }

    FAPI_INF("%s set_nce_magnitude: 0x%016lx", mss::c_str(i_target), i_value);
}

///
/// @brief get_nce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void get_nce_magnitude( const fapi2::Target<T>& i_target,
                               const fapi2::buffer<uint64_t>& i_data,
                               uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        i_data.extractToRight<TT::P0_NCE_MAGNITUDE, TT::P0_NCE_MAGNITUDE_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_NCE_MAGNITUDE, TT::P1_NCE_MAGNITUDE_LEN>(o_value);
    }

    FAPI_INF("%s get_nce_magnitude: 0x%016lx", mss::c_str(i_target), o_value);
}

///
/// @brief set_tce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void set_tce_galois( const fapi2::Target<T>& i_target,
                            fapi2::buffer<uint64_t>& io_data,
                            const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        io_data.insertFromRight<TT::P0_TCE_GALOIS, TT::P0_TCE_GALOIS_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_TCE_GALOIS, TT::P1_TCE_GALOIS_LEN>(i_value);
    }

    FAPI_INF("%s set_tce_galois: 0x%016lx", mss::c_str(i_target), i_value);
}

///
/// @brief get_tce_galois
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void get_tce_galois( const fapi2::Target<T>& i_target,
                            const fapi2::buffer<uint64_t>& i_data,
                            uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        i_data.extractToRight<TT::P0_TCE_GALOIS, TT::P0_TCE_GALOIS_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_TCE_GALOIS, TT::P1_TCE_GALOIS_LEN>(o_value);
    }

    FAPI_INF("%s get_tce_galois: 0x%016lx", mss::c_str(i_target), o_value);
}

///
/// @brief set_tce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void set_tce_magnitude( const fapi2::Target<T>& i_target,
                               fapi2::buffer<uint64_t>& io_data,
                               const uint64_t i_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        io_data.insertFromRight<TT::P0_TCE_MAGNITUDE, TT::P0_TCE_MAGNITUDE_LEN>(i_value);
    }
    else
    {
        io_data.insertFromRight<TT::P1_TCE_MAGNITUDE, TT::P1_TCE_MAGNITUDE_LEN>(i_value);
    }

    FAPI_INF("%s set_tce_magnitude: 0x%016lx", mss::c_str(i_target), i_value);
}

///
/// @brief get_tce_magnitude
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<mc_type::NIMBUS, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< fapi2::TargetType T, typename TT = eccTraits<mc_type::NIMBUS, T> >
inline void get_tce_magnitude( const fapi2::Target<T>& i_target,
                               const fapi2::buffer<uint64_t>& i_data,
                               uint64_t& o_value)
{
    const auto& l_port = mss::relative_pos<fapi2::TARGET_TYPE_MCBIST>(i_target);

    // check for even/odd since each register holds info for a pair of ports
    if (!mss::is_odd(l_port))
    {
        i_data.extractToRight<TT::P0_TCE_MAGNITUDE, TT::P0_TCE_MAGNITUDE_LEN>(o_value);
    }
    else
    {
        i_data.extractToRight<TT::P1_TCE_MAGNITUDE, TT::P1_TCE_MAGNITUDE_LEN>(o_value);
    }

    FAPI_INF("%s get_tce_magnitude: 0x%016lx", mss::c_str(i_target), o_value);
}

} // close namespace mbs_error_vector_trap

} // close namespace ecc

} // close namespace mss

#endif
