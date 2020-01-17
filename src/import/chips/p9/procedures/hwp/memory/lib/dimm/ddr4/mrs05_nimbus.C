/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs05_nimbus.C $ */
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
/// @file mrs05_nimbus.C
/// @brief Run and manage the DDR4 MRS05 loading
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
#include <generic/memory/lib/dimm/ddr4/mrs05.H>

using fapi2::TARGET_TYPE_DIMM;
using fapi2::FAPI2_RC_SUCCESS;

namespace mss
{

namespace ddr4
{

///
/// @brief mrs05_data ctor
/// @param[in] a fapi2::TARGET_TYPE_DIMM target
/// @param[out] fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template<>
mrs05_data<mss::mc_type::NIMBUS>::mrs05_data( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        fapi2::ReturnCode& o_rc ):
    iv_ca_parity_latency(fapi2::ENUM_ATTR_EFF_CA_PARITY_LATENCY_DISABLE),
    iv_crc_error_clear(fapi2::ENUM_ATTR_EFF_CRC_ERROR_CLEAR_CLEAR),
    iv_ca_parity_error_status(fapi2::ENUM_ATTR_EFF_CA_PARITY_ERROR_STATUS_CLEAR),
    iv_odt_input_buffer(fapi2::ENUM_ATTR_EFF_ODT_INPUT_BUFF_DEACTIVATED),
    iv_ca_parity(fapi2::ENUM_ATTR_EFF_CA_PARITY_DISABLE),
    iv_data_mask(fapi2::ENUM_ATTR_EFF_DATA_MASK_DISABLE),
    iv_write_dbi(fapi2::ENUM_ATTR_EFF_WRITE_DBI_DISABLE),
    iv_read_dbi(fapi2::ENUM_ATTR_EFF_READ_DBI_DISABLE)
{
    FAPI_TRY( mss::eff_ca_parity_latency(i_target, iv_ca_parity_latency), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_crc_error_clear(i_target, iv_crc_error_clear), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_ca_parity_error_status(i_target, iv_ca_parity_error_status),
              "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_odt_input_buff(i_target, iv_odt_input_buffer), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_dram_rtt_park(i_target, &(iv_rtt_park[0])), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_ca_parity(i_target, iv_ca_parity), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_data_mask(i_target, iv_data_mask), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_write_dbi(i_target, iv_write_dbi), "Error in mrs05_data()" );
    FAPI_TRY( mss::eff_read_dbi(i_target, iv_read_dbi), "Error in mrs05_data()" );

    o_rc = fapi2::FAPI2_RC_SUCCESS;
    return;

fapi_try_exit:
    o_rc = fapi2::current_err;
    FAPI_ERR("%s unable to get attributes for mrs05", mss::c_str(i_target));
    return;
}

template<>
fapi2::ReturnCode (*mrs05_data<mss::mc_type::NIMBUS>::make_ccs_instruction)(const
        fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
        const mrs05_data<mss::mc_type::NIMBUS>& i_data,
        ccs::instruction_t& io_inst,
        const uint64_t i_rank) = &mrs05;

template<>
fapi2::ReturnCode (*mrs05_data<mss::mc_type::NIMBUS>::decode)(const ccs::instruction_t& i_inst,
        const uint64_t i_rank) = &mrs05_decode;

} // ns ddr4
} // ns mss
