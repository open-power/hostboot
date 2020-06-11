/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/nvdimm_utils.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2020                        */
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
/// @file nvdimm_utils.H
/// @brief Subroutines to support nvdimm backup/restore process
///
// *HWP HWP Owner: Tsung Yeung <tyeung@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _MSS_NVDIMM_UTILS_NIMBUS_H_
#define _MSS_NVDIMM_UTILS_NIMBUS_H_

#include <fapi2.H>
#include <lib/utils/nimbus_find.H>
#include <lib/shared/mss_const.H>
#include <lib/phy/dp16.H>
#include <lib/mc/port.H>
#include <generic/memory/lib/ccs/ccs.H>

namespace mss
{

namespace nvdimm
{
///
/// @brief get refresh overrun fir mask
/// @param[in] i_target the target associated with this subroutine
/// @param[out] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
inline fapi2::ReturnCode get_refresh_overrun_mask( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        mss::states& o_state )
{
    typedef portTraits<mss::mc_type::NIMBUS> TT;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::CALFIRMASK, l_data),
              "%s Failed getScom", mss::c_str(i_target) );

    o_state = l_data.getBit<TT::CALFIRMASK_REFRESH_OVERRUN>() ? mss::states::ON : mss::states::OFF;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief change refresh overrun fir mask
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
inline fapi2::ReturnCode change_refresh_overrun_mask( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const mss::states i_state )
{
    typedef portTraits<mss::mc_type::NIMBUS> TT;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::CALFIRMASK, l_data),
              "%s Failed getScom", mss::c_str(i_target) );

    l_data.writeBit<TT::CALFIRMASK_REFRESH_OVERRUN>(i_state);

    FAPI_TRY( mss::putScom(i_target, TT::CALFIRMASK, l_data),
              "%s Failed putScom", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Clear the refresh overrun fir
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
inline fapi2::ReturnCode clear_refresh_overrun_fir( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target )
{
    typedef portTraits<mss::mc_type::NIMBUS> TT;
    fapi2::buffer<uint64_t> l_data;

    FAPI_TRY( mss::getScom(i_target, TT::CALFIRQ, l_data),
              "%s Failed getScom", mss::c_str(i_target) );

    l_data.clearBit<TT::CALFIRQ_REFRESH_OVERRUN>();

    FAPI_TRY( mss::putScom(i_target, TT::CALFIRQ, l_data),
              "%s Failed putScom", mss::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Wrapper to read MAINT_ADDR_MODE_EN
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @param[out] o_state MAINT_ADDR_MODE_EN state
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode get_maint_addr_mode_en( const fapi2::Target<T>& i_target,
        mss::states& o_state );

///
/// @brief change maintenance address mode
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode change_maint_addr_mode_en( const fapi2::Target<T>& i_target,
        const mss::states i_state );

///
/// @brief change ECC check and correct mode
/// Specialization for TARGET_TYPE_MCA
/// @param[in] i_target the target associated with this subroutine
/// @param[in] i_state the state to change to
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode change_ecc_check_correct_disable( const fapi2::Target<T>& i_target,
        const mss::states i_state );

///
/// @brief cleanup after targeted scrub
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode targeted_scrub_cleanup( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Helper for self_refresh_exit().
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note Uses memdiag to read the port to force CKE back to high.
/// Stolen from mss_lab_memdiags.C
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit_helper( const fapi2::Target<T>& i_target );

///
/// @brief Disable refresh and put target into self-refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_entry( const fapi2::Target<T>& i_target );

///
/// @brief Take the target out of self-refresh and restart refresh
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode self_refresh_exit( const fapi2::Target<T>& i_target );

///
/// @brief Load the rcd control words
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note This is similar to rcd_load_ddr4() but with minor changes to support
///       with NVDIMMs
///
fapi2::ReturnCode rcd_load_nvdimm( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Restore the rcd after restoring the nvdimm data
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_MCA>
/// @return FAPI2_RC_SUCCESS if and only if ok
/// @Note Restoring the RCD after NVDIMM restore requires a special procedure
///       The procedure from draminit would actually fail to restore the CWs
///
fapi2::ReturnCode rcd_restore( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Execute post restore ZQCAL
/// @param[in] i_target the target associated with this cal
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @Note The original zqcal has delay that violates the refresh interval.
///       Since we now have data in the DRAMs, the command will be executed
///       with delay following the spec.
///
fapi2::ReturnCode post_restore_zqcal( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target);

///
/// @brief Latch write vref
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode wr_vref_latch( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

///
/// @brief Full post-restore transition for NVDIMM
/// @tparam T the target type associated with this subroutine
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
template< fapi2::TargetType T >
fapi2::ReturnCode post_restore_transition( const fapi2::Target<T>& i_target );

///
/// @brief Helper to change the BAR valid state. Consumed by hostboot
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
///
fapi2::ReturnCode change_bar_valid_state( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target,
        const uint8_t i_state);

///
/// @brief Preload the CCS with the EPOW sequence
/// @param[in] i_target the target associated with this subroutine
/// @return FAPI2_RC_SUCCESS iff setup was successful
/// @note This is written specifically to support EPOW on NVDIMM and
///       should only be called after all the draminit.
///
fapi2::ReturnCode preload_epow_sequence( const fapi2::Target<fapi2::TARGET_TYPE_MCA>& i_target );

namespace wr_vref
{

///
/// @brief Helper to extract the values and ranges from wr_vref_value reg, and
///        convert JEDEC value to composite
/// @param[in] i_data - wr vref reg data
/// @param[out] o_values - vector of composite value
///
inline void get_wr_vref_composite_value_helper(const fapi2::buffer<uint64_t> i_data,
        std::vector<uint64_t>& o_values)
{
    FAPI_DBG("get_wr_vref_composite_value_helper() i_data = 0x%016lx", i_data);
    const std::vector<uint64_t> DRAMS = {0, 1};

    for (const auto l_dram : DRAMS)
    {
        uint64_t l_wr_vref_val = 0;
        bool l_wr_vref_range = 0;
        uint64_t l_composite_vref = 0;

        mss::dp16::wr_vref::get_wr_vref_value(i_data, l_dram, l_wr_vref_val);
        mss::dp16::wr_vref::get_wr_vref_range(i_data, l_dram, l_wr_vref_range);

        l_composite_vref = mss::dp16::wr_vref::compute_composite_value(l_wr_vref_range, l_wr_vref_val);

        FAPI_DBG("l_composite_vref: 0x%016lx", l_composite_vref);

        o_values.push_back(l_composite_vref);
    }
}

}//ns wr_vref

}//ns nvdimm

}//ns mss
#endif
