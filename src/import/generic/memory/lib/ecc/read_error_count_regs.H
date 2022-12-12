/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/ecc/read_error_count_regs.H $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2023                        */
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
/// @file read_error_count_regs.H
/// @brief Subroutines for the MBS Memory Scrub/Read Error Count registers (MBSEC*Q)
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_READ_ERROR_COUNT_REGS_H_
#define _MSS_READ_ERROR_COUNT_REGS_H_

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

namespace read_error_count_reg0
{

///
/// @brief Read MBS Memory Scrub/Read Error Count Register 0 (MBSEC0Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::READ_ERROR_COUNT_REG0, o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Memory Scrub/Read Error Count Register 0 (MBSEC0Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::READ_ERROR_COUNT_REG0, i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_intermittent_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccMCTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_INTERMITTENT_CE_COUNT: Intermittent CE Count This is a 12-bit count of
/// @note intermittent CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_intermittent_ce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::INTERMITTENT_CE_COUNT, TT::INTERMITTENT_CE_COUNT_LEN>(i_value);
    FAPI_INF("set_intermittent_ce_count: 0x%03lx", i_value);
}

///
/// @brief get_intermittent_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_INTERMITTENT_CE_COUNT: Intermittent CE Count This is a 12-bit count of
/// @note intermittent CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_intermittent_ce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::INTERMITTENT_CE_COUNT, TT::INTERMITTENT_CE_COUNT_LEN>(o_value);
    FAPI_INF("get_intermittent_ce_count: 0x%03lx", o_value);
}

///
/// @brief set_soft_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_SOFT_CE_COUNT: Soft CE Count This is a 12-bit count of
/// @note soft CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_soft_ce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SOFT_CE_COUNT, TT::SOFT_CE_COUNT_LEN>(i_value);
    FAPI_INF("set_soft_ce_count: 0x%03lx", i_value);
}

///
/// @brief get_soft_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_SOFT_CE_COUNT: Soft CE Count This is a 12-bit count of
/// @note soft CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_soft_ce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SOFT_CE_COUNT, TT::SOFT_CE_COUNT_LEN>(o_value);
    FAPI_INF("get_soft_ce_count: 0x%03lx", o_value);
}

///
/// @brief set_hard_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_HARD_CE_COUNT: Hard CE Count This is a 12-bit count of
/// @note hard CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_hard_ce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::HARD_CE_COUNT, TT::HARD_CE_COUNT_LEN>(i_value);
    FAPI_INF("set_hard_ce_count: 0x%03lx", i_value);
}

///
/// @brief get_hard_ce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_HARD_CE_COUNT: Hard CE Count This is a 12-bit count of
/// @note hard CE events. Will freeze its value upon incrementing to the max
/// @note value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_hard_ce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::HARD_CE_COUNT, TT::HARD_CE_COUNT_LEN>(o_value);
    FAPI_INF("get_hard_ce_count: 0x%03lx", o_value);
}

///
/// @brief set_intermittent_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_INTERMITTENT_MCE_COUNT: Intermittent MCE Count This is a 12-bit count of
/// @note intermittent Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_intermittent_mce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::INTERMITTENT_MCE_COUNT, TT::INTERMITTENT_MCE_COUNT_LEN>(i_value);
    FAPI_INF("set_intermittent_mce_count: 0x%03lx", i_value);
}

///
/// @brief get_intermittent_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_INTERMITTENT_MCE_COUNT: Intermittent MCE Count This is a 12-bit count of
/// @note intermittent Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_intermittent_mce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::INTERMITTENT_MCE_COUNT, TT::INTERMITTENT_MCE_COUNT_LEN>(o_value);
    FAPI_INF("get_intermittent_mce_count: 0x%03lx", o_value);
}

///
/// @brief set_soft_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_SOFT_MCE_COUNT: Soft MCE Count This is a 12-bit count of
/// @note soft Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_soft_mce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SOFT_MCE_COUNT, TT::SOFT_MCE_COUNT_LEN>(i_value);
    FAPI_INF("set_soft_mce_count: 0x%03lx", i_value);
}

///
/// @brief get_soft_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_SOFT_MCE_COUNT: Soft MCE Count This is a 12-bit count of
/// @note soft Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_soft_mce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SOFT_MCE_COUNT, TT::SOFT_MCE_COUNT_LEN>(o_value);
    FAPI_INF("get_soft_mce_count: 0x%03lx", o_value);
}

} // close namespace read_error_count_reg0

namespace read_error_count_reg1
{

///
/// @brief Read MBS Memory Scrub/Read Error Count Register 1 (MBSEC1Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::READ_ERROR_COUNT_REG1, o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Memory Scrub/Read Error Count Register 1 (MBSEC1Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::READ_ERROR_COUNT_REG1, i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_hard_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_HARD_MCE_COUNT: Hard MCE Count This is a 12-bit count of
/// @note hard Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_hard_mce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::HARD_MCE_COUNT, TT::HARD_MCE_COUNT_LEN>(i_value);
    FAPI_INF("set_hard_mce_count: 0x%03lx", i_value);
}

///
/// @brief get_hard_mce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_HARD_MCE_COUNT: Hard MCE Count This is a 12-bit count of
/// @note hard Marked Chip Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_hard_mce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::HARD_MCE_COUNT, TT::HARD_MCE_COUNT_LEN>(o_value);
    FAPI_INF("get_hard_mce_count: 0x%03lx", o_value);
}

///
/// @brief set_ice_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_ICE_COUNT: ICE (IMPE) Count This is a 12-bit count of
/// @note Intermittent Marked-Placed Chip Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_ice_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::ICE_COUNT, TT::ICE_COUNT_LEN>(i_value);
    FAPI_INF("set_ice_count: 0x%03lx", i_value);
}

///
/// @brief get_ice_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_ICE_COUNT: ICE (IMPE) Count This is a 12-bit count of
/// @note Intermittent Marked-Placed Chip Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_ice_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::ICE_COUNT, TT::ICE_COUNT_LEN>(o_value);
    FAPI_INF("get_ice_count: 0x%03lx", o_value);
}

///
/// @brief set_ue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_UE_COUNT: UE Count This is a 12-bit count of
/// @note Uncorrectable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_ue_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::UE_COUNT, TT::UE_COUNT_LEN>(i_value);
    FAPI_INF("set_ue_count: 0x%03lx", i_value);
}

///
/// @brief get_ue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_UE_COUNT: UE Count This is a 12-bit count of
/// @note Uncorrectable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_ue_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::UE_COUNT, TT::UE_COUNT_LEN>(o_value);
    FAPI_INF("get_ue_count: 0x%03lx", o_value);
}

///
/// @brief set_aue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_AUE_COUNT: AUE Count This is a 12-bit count of
/// @note AUE Parity Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_aue_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::AUE_COUNT, TT::AUE_COUNT_LEN>(i_value);
    FAPI_INF("set_aue_count: 0x%03lx", i_value);
}

///
/// @brief get_aue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_AUE_COUNT: AUE Count This is a 12-bit count of
/// @note AUE Parity Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_aue_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::AUE_COUNT, TT::AUE_COUNT_LEN>(o_value);
    FAPI_INF("get_aue_count: 0x%03lx", o_value);
}

///
/// @brief set_rce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC0Q_RCE_COUNT: RCE Count This is a 12-bit count of
/// @note Retried Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_rce_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::RCE_COUNT, TT::RCE_COUNT_LEN>(i_value);
    FAPI_INF("set_rce_count: 0x%03lx", i_value);
}

///
/// @brief get_rce_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC0Q_RCE_COUNT: RCE Count This is a 12-bit count of
/// @note Retried Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_rce_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::RCE_COUNT, TT::RCE_COUNT_LEN>(o_value);
    FAPI_INF("get_rce_count: 0x%03lx", o_value);
}

///
/// @brief get_iue_count
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC1Q_IUE_COUNT: IUE Count This is a 12-bit count of
/// @note Intermittent Uncorrectable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_iue_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::IUE_COUNT, TT::IUE_COUNT_LEN>(o_value);
    FAPI_INF("get_iue_count: 0x%03lx", o_value);
}


///
/// @brief set_iue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC1Q_IUE_COUNT: IUE Count This is a 12-bit count of
/// @note Retried Correctable Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_iue_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::IUE_COUNT, TT::IUE_COUNT_LEN>(i_value);
    FAPI_INF("set_iue_count: 0x%03lx", i_value);
}

} // close namespace read_error_count_reg1

namespace read_error_count_reg2

{
///
/// @brief Read MBS Memory Scrub/Read Error Count Register 2 (MBSEC2Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::READ_ERROR_COUNT_REG2, o_data) );
    FAPI_INF("%s read: 0x%016lx", mss::c_str(i_target), o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Memory Scrub/Read Error Count Register 2 (MBSEC2Q)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::READ_ERROR_COUNT_REG2, i_data) );
    FAPI_INF("%s write: 0x%016lx", mss::c_str(i_target), i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_iaue_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC2Q_IAUE_COUNT: IAUE Count This is a 12-bit count of
/// @note Intermittent AUE Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_iaue_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::IAUE_COUNT, TT::IAUE_COUNT_LEN>(i_value);
    FAPI_INF("set_iaue_count: 0x%03lx", i_value);
}

///
/// @brief set_ircd_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSEC2Q_IRCD_COUNT: IRCD Count This is a 12-bit count of
/// @note Intermittent RCD Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_ircd_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::IRCD_COUNT, TT::IRCD_COUNT_LEN>(i_value);
    FAPI_INF("set_ircd_count: 0x%03lx", i_value);
}

///
/// @brief get_iaue_count
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC2Q_IAUE_COUNT: IUE Count This is a 12-bit count of
/// @note Intermittent AUE Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_iaue_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::IAUE_COUNT, TT::IAUE_COUNT_LEN>(o_value);
    FAPI_INF("get_iaue_count: 0x%03lx", o_value);
}

///
/// @brief get_ircd_count
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSEC2Q_IRCD_COUNT: IUE Count This is a 12-bit count of
/// @note Intermittent RCD Error events. Will freeze its value upon
/// @note incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_ircd_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::IRCD_COUNT, TT::IRCD_COUNT_LEN>(o_value);
    FAPI_INF("get_iue_count: 0x%03lx", o_value);
}

} // close namespace read_error_count_reg2

namespace mark_symbol_count_reg
{

///
/// @brief Read MBS Mark Symbol Error Count Register (MBSMSECQ)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[out] o_data the value of the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode read( const fapi2::Target<T>& i_target, fapi2::buffer<uint64_t>& o_data )
{
    FAPI_TRY( mss::getScom(i_target, TT::MARK_SYMBOL_COUNT_REG, o_data) );
    FAPI_INF("read: 0x%016lx", o_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Write MBS Mark Symbol Error Count Register (MBSMSECQ)
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type - derived from i_target's type
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_target the fapi2 target of the mcbist
/// @param[in] i_data the value to write to the register
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS if ok
///
template< mss::mc_type MC, fapi2::TargetType T, typename TT = eccTraits<MC, T> >
inline fapi2::ReturnCode write( const fapi2::Target<T>& i_target, const fapi2::buffer<uint64_t>& i_data )
{
    FAPI_TRY( mss::putScom(i_target, TT::MARK_SYMBOL_COUNT_REG, i_data) );
    FAPI_INF("write: 0x%016lx", i_data);
fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief set_symbol0_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL0_COUNT: MCE Symbol 0 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 0 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_symbol0_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SYMBOL0_COUNT, TT::SYMBOL0_COUNT_LEN>(i_value);
    FAPI_INF("set_symbol0_count: 0x%03lx", i_value);
}

///
/// @brief get_symbol0_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL0_COUNT: MCE Symbol 0 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 0 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_symbol0_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SYMBOL0_COUNT, TT::SYMBOL0_COUNT_LEN>(o_value);
    FAPI_INF("get_symbol0_count: 0x%03lx", o_value);
}

///
/// @brief set_symbol1_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL1_COUNT: MCE Symbol 1 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 1 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_symbol1_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SYMBOL1_COUNT, TT::SYMBOL1_COUNT_LEN>(i_value);
    FAPI_INF("set_symbol1_count: 0x%03lx", i_value);
}

///
/// @brief get_symbol1_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL1_COUNT: MCE Symbol 1 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 1 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_symbol1_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SYMBOL1_COUNT, TT::SYMBOL1_COUNT_LEN>(o_value);
    FAPI_INF("get_symbol1_count: 0x%03lx", o_value);
}

///
/// @brief set_symbol2_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL2_COUNT: MCE Symbol 2 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 2 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_symbol2_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SYMBOL2_COUNT, TT::SYMBOL2_COUNT_LEN>(i_value);
    FAPI_INF("set_symbol2_count: 0x%03lx", i_value);
}

///
/// @brief get_symbol2_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL2_COUNT: MCE Symbol 2 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 2 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_symbol2_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SYMBOL2_COUNT, TT::SYMBOL2_COUNT_LEN>(o_value);
    FAPI_INF("get_symbol2_count: 0x%03lx", o_value);
}

///
/// @brief set_symbol3_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in, out] io_data the register value
/// @param[in] i_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL3_COUNT: MCE Symbol 3 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 3 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void set_symbol3_count( fapi2::buffer<uint64_t>& io_data, const uint64_t i_value )
{
    io_data.insertFromRight<TT::SYMBOL3_COUNT, TT::SYMBOL3_COUNT_LEN>(i_value);
    FAPI_INF("set_symbol3_count: 0x%03lx", i_value);
}

///
/// @brief get_symbol3_count
/// @tparam MC the memory controller type
/// @tparam T fapi2 Target Type defaults to eccTraits<MC>::MC_TARGET_TYPE
/// @tparam TT traits type defaults to eccTraits<MC, T>
/// @param[in] i_data the register value
/// @param[out] o_value the value of the field
/// @note MBSMSECQ_MCE_SYMBOL3_COUNT: MCE Symbol 3 Error Count This is a 8-bit count
/// @note that increments on MCE when Symbol 3 under chip mark takes error. Will freeze
/// @note its value upon incrementing to the max value until reset.
///
template< mss::mc_type MC, fapi2::TargetType T = eccMCTraits<MC>::MC_TARGET_TYPE, typename TT = eccTraits<MC, T> >
inline void get_symbol3_count( const fapi2::buffer<uint64_t>& i_data, uint64_t& o_value )
{
    i_data.extractToRight<TT::SYMBOL3_COUNT, TT::SYMBOL3_COUNT_LEN>(o_value);
    FAPI_INF("get_symbol3_count: 0x%03lx", o_value);
}

} // close namespace mark_symbol_count_reg

} // close namespace ecc

} // close namespace mss

#endif
