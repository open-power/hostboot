/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/mbs_error_vector_trap.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2022                        */
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
/// @file mbs_error_vector_trap.H
/// @brief Subroutines for the MC MBS error vector trap registers (MBSEVR*Q)
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MBS_ERROR_VECTOR_TRAP_H_
#define _MSS_MBS_ERROR_VECTOR_TRAP_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/scom.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/ecc/ecc_traits.H>

namespace mss
{

namespace ecc
{

namespace mbs_error_vector_trap
{

///
/// @brief Read MBS Error Vector Trap (MBSEVR*Q) register
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
    const auto& l_mcbist_target = mss::find_target<eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);
    const auto& l_port = mss::relative_pos<MC, eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);

    FAPI_TRY( mss::getScom(l_mcbist_target, (TT::ERROR_VECTOR_REGS[l_port]), o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Error Vector Trap (MBSEVR*Q) register
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
    const auto& l_mcbist_target = mss::find_target<eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);
    const auto& l_port = mss::relative_pos<MC, eccMCTraits<MC>::MC_TARGET_TYPE>(i_target);

    FAPI_TRY( mss::putScom(l_mcbist_target, (TT::ERROR_VECTOR_REGS[l_port]), i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_nce_galois
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void set_nce_galois( const fapi2::Target<T>& i_target,
                     fapi2::buffer<uint64_t>& io_data,
                     const uint64_t i_value);
///
/// @brief get_nce_galois
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void get_nce_galois( const fapi2::Target<T>& i_target,
                     const fapi2::buffer<uint64_t>& i_data,
                     uint64_t& o_value);

///
/// @brief set_nce_magnitude
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void set_nce_magnitude( const fapi2::Target<T>& i_target,
                        fapi2::buffer<uint64_t>& io_data,
                        const uint64_t i_value);

///
/// @brief get_nce_magnitude
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void get_nce_magnitude( const fapi2::Target<T>& i_target,
                        const fapi2::buffer<uint64_t>& i_data,
                        uint64_t& o_value);

///
/// @brief set_tce_galois
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void set_tce_galois( const fapi2::Target<T>& i_target,
                     fapi2::buffer<uint64_t>& io_data,
                     const uint64_t i_value);

///
/// @brief get_tce_galois
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void get_tce_galois( const fapi2::Target<T>& i_target,
                     const fapi2::buffer<uint64_t>& i_data,
                     uint64_t& o_value);

///
/// @brief set_tce_magnitude
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void set_tce_magnitude( const fapi2::Target<T>& i_target,
                        fapi2::buffer<uint64_t>& io_data,
                        const uint64_t i_value);

///
/// @brief get_tce_magnitude
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mc
/// @param[in] i_data the register value
/// @param[out] i_value the value of the field
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
void get_tce_magnitude( const fapi2::Target<T>& i_target,
                        const fapi2::buffer<uint64_t>& i_data,
                        uint64_t& o_value);

} // close namespace mbs_error_vector_trap

} // close namespace ecc

} // close namespace mss

#endif
