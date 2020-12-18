/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/dimm/ddr4/mrs03.H $             */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file mrs03.H
/// @brief Run and manage mrs03
///
// *HWP HWP Owner: Matt Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#ifndef _GENERIC_DDR4_MRS03_H_
#define _GENERIC_DDR4_MRS03_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/dimm/mrs_traits.H>
#include <generic/memory/lib/ccs/ccs_traits.H>
#include <generic/memory/lib/dimm/mrs_load.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/ccs/ccs.H>

namespace mss
{

namespace ddr4
{
enum swizzle : uint64_t
{
    MPR_PAGE_LENGTH = 2,
    MPR_PAGE_START = 7,
    FINE_REFRESH_LENGTH = 3,
    FINE_REFRESH_START = 7,
    CRC_WR_LATENCY_LENGTH = 2,
    CRC_WR_LATENCY_START = 7,
    READ_FORMAT_LENGTH = 2,
    READ_FORMAT_START = 7,
};

///
/// @brief Helper function to decode CRC WR latency to the MRS value
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_value the value to be decoded
/// @param[out] o_decode the MRS decoded value
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC >
fapi2::ReturnCode crc_wr_latency_helper(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                        const uint8_t i_value,
                                        fapi2::buffer<uint8_t>& o_decode);

///
/// @brief Configure the ARR0 of the CCS instruction for mrs03, data object as input
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @tparam MRS traits type defaults to mrsTraits<MC>
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data<mss::mc_type::NIMBUS> object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC>, typename MRS = mrsTraits<MC> >
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs03_data<MC>& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    // Decode CRC WR latency
    fapi2::buffer<uint8_t> l_crc_wr_latency_buffer;
    FAPI_TRY(crc_wr_latency_helper<MC>(i_target, i_data.iv_crc_wr_latency, l_crc_wr_latency_buffer));

    mss::swizzle<TT::A0, MPR_PAGE_LENGTH, MPR_PAGE_START>(fapi2::buffer<uint8_t>(i_data.iv_mpr_page), io_inst.arr0);
    io_inst.arr0.writeBit<TT::A2>(i_data.iv_mpr_mode);
    io_inst.arr0.writeBit<TT::A3>(i_data.iv_geardown);
    io_inst.arr0.writeBit<TT::A4>(i_data.iv_pda);
    io_inst.arr0.writeBit<TT::A5>(i_data.iv_temp_readout);

    mss::swizzle<TT::A6, FINE_REFRESH_LENGTH, FINE_REFRESH_START>(fapi2::buffer<uint8_t>(i_data.iv_fine_refresh),
            io_inst.arr0);
    mss::swizzle<TT::A9, CRC_WR_LATENCY_LENGTH, CRC_WR_LATENCY_START>(l_crc_wr_latency_buffer, io_inst.arr0);
    mss::swizzle<TT::A11, READ_FORMAT_LENGTH, READ_FORMAT_START>(fapi2::buffer<uint8_t>(i_data.iv_read_format),
            io_inst.arr0);

    FAPI_INF("%s MR3: 0x%016llx", mss::c_str(i_target), uint64_t(io_inst.arr0));

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Configure the ARR0 of the CCS instruction for mrs03
/// @tparam MC mss::mc_type memory controller type
/// @param[in] i_target a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
template< mss::mc_type MC = DEFAULT_MC_TYPE >
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_port_rank)
{
    // Check to make sure our ctor worked ok
    mrs03_data<MC> l_data( i_target, fapi2::current_err );
    FAPI_TRY( fapi2::current_err,
              "%s Unable to construct MRS03 data from attributes",
              mss::c_str(i_target) );
    FAPI_TRY( mrs03(i_target, l_data, io_inst, i_port_rank) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Helper function for mrs03_decode
/// @tparam MC mss::mc_type memory controller type
/// @tparam TT traits type defaults to ccsTraits<MC>
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank the rank in question
/// @param[out] o_mpr_mode the mpr operation setting
/// @param[out] o_geardown the geardown mode setting
/// @param[out] o_pda the per dram addressability setting
/// @param[out] o_temp_readout the temperature sensor readout setting
/// @param[out] o_mpr_page the mpr page selection
/// @param[out] o_fine_refresh the fine granularity refresh mode setting
/// @param[out] o_crc_wr_latency_buffer the write cmd latency when crc and dm are enabled
/// @param[out] o_read_fromat the mpr read format setting
/// @return FAPI2_RC_SUCCESS iff ok
///
template< mss::mc_type MC = DEFAULT_MC_TYPE, typename TT = ccsTraits<MC> >
fapi2::ReturnCode mrs03_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank,
                                      uint8_t& o_mpr_mode,
                                      uint8_t& o_geardown,
                                      uint8_t& o_pda,
                                      uint8_t& o_temp_readout,
                                      fapi2::buffer<uint8_t>& o_mpr_page,
                                      fapi2::buffer<uint8_t>& o_fine_refresh,
                                      fapi2::buffer<uint8_t>& o_crc_wr_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_read_format)
{
    o_mpr_page = 0;
    o_fine_refresh = 0;
    o_crc_wr_latency_buffer = 0;
    o_read_format = 0;

    o_mpr_mode = i_inst.arr0.getBit<TT::A2>();
    o_geardown = i_inst.arr0.getBit<TT::A3>();
    o_pda = i_inst.arr0.getBit<TT::A4>();
    o_temp_readout = i_inst.arr0.getBit<TT::A5>();

    mss::swizzle<6, 2, TT::A1>(i_inst.arr0, o_mpr_page);
    mss::swizzle<5, 3, TT::A8>(i_inst.arr0, o_fine_refresh);
    mss::swizzle<6, 2, TT::A10>(i_inst.arr0, o_crc_wr_latency_buffer);
    mss::swizzle<6, 2, TT::A12>(i_inst.arr0, o_read_format);

    FAPI_INF("MR3 rank %d decode: MPR_MODE: 0x%x, MPR_PAGE: 0x%x, GD: 0x%x, PDA: 0x%x, "
             "TEMP: 0x%x FR: 0x%x, CRC_WL: 0x%x, RF: 0x%x", i_port_rank,
             uint8_t(o_mpr_mode), o_mpr_page, o_geardown, o_pda, uint8_t(o_temp_readout),
             uint8_t(o_fine_refresh), uint8_t(o_crc_wr_latency_buffer), uint8_t(o_read_format));

    return fapi2::FAPI2_RC_SUCCESS;
}

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS3,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_port_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
inline fapi2::ReturnCode mrs03_decode(const ccs::instruction_t& i_inst,
                                      const uint64_t i_port_rank)
{
    uint8_t l_mpr_mode = 0;
    uint8_t l_geardown = 0;
    uint8_t l_pda = 0;
    uint8_t l_temp_readout = 0;
    fapi2::buffer<uint8_t> l_mpr_page;
    fapi2::buffer<uint8_t> l_fine_refresh;
    fapi2::buffer<uint8_t> l_crc_wr_latency_buffer;
    fapi2::buffer<uint8_t> l_read_format;

    return mrs03_decode_helper(i_inst, i_port_rank, l_mpr_mode, l_geardown, l_pda, l_temp_readout,
                               l_mpr_page, l_fine_refresh, l_crc_wr_latency_buffer, l_read_format);
}

} // ns ddr4
} // ns mss
#endif
