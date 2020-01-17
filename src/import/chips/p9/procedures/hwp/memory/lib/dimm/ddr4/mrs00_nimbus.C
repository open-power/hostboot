/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs00_nimbus.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file mrs00_nimbus.C
/// @brief Run and manage the DDR4 MRS00 loading
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <lib/shared/nimbus_defaults.H>
#include <lib/dimm/mrs_traits_nimbus.H>
#include <mss.H>
#include <lib/shared/mss_const.H>
#include <lib/ccs/ccs_traits_nimbus.H>
#include <lib/dimm/ddr4/mrs_load_ddr4_nimbus.H>
#include <generic/memory/lib/dimm/ddr4/mrs00.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace ddr4
{

///
/// @brief mrs0_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
/// @note Burst Length will always be set to fixed x8 (0)
/// @note Burst Chop (x4) is not supported
///
template<>
mrs00_data<mss::mc_type::NIMBUS>::mrs00_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_burst_length(0),
    iv_read_burst_type(fapi2::ENUM_ATTR_EFF_DRAM_RBT_SEQUENTIAL),
    iv_dll_reset(fapi2::ENUM_ATTR_EFF_DRAM_DLL_RESET_NO),
    iv_test_mode(fapi2::ENUM_ATTR_EFF_DRAM_TM_NORMAL),
    iv_write_recovery(0),
    iv_cas_latency(0)
{
    FAPI_TRY( mss::eff_dram_rbt(i_target, iv_read_burst_type), "Error in mrs00_data()" );
    FAPI_TRY( mss::eff_dram_cl(i_target, iv_cas_latency), "Error in mrs00_data()" );
    FAPI_TRY( mss::eff_dram_dll_reset(i_target, iv_dll_reset), "Error in mrs00_data()" );
    FAPI_TRY( mss::eff_dram_tm(i_target, iv_test_mode), "Error in mrs00_data()" );
    FAPI_TRY( mss::eff_dram_twr(i_target, iv_write_recovery), "Error in mrs00_data()" );

    FAPI_INF("%s MR0 Attributes: BL: 0x%x, RBT: 0x%x, CL: 0x%x, TM: 0x%x, DLL_RESET: 0x%x, WR: 0x%x",
             mss::c_str(i_target), iv_burst_length, iv_read_burst_type, iv_cas_latency, iv_test_mode, iv_dll_reset,
             iv_write_recovery);

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs00", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs00_data<mss::mc_type::NIMBUS>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs00_data<mss::mc_type::NIMBUS>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs00;

template<>
fapi2::ReturnCode (*mrs00_data<mss::mc_type::NIMBUS>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs00_decode;

} // ns ddr4

} // ns mss
