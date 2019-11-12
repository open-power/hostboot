/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/dimm/ddr4/mrs_load_ddr4_nimbus.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file mrs_load_ddr4_nimbus.H
/// @brief Code to support mrs_load_ddr4_nimbus
///
// *HWP HWP Owner: Matthew Hickman <Matthew.Hickman@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP

#ifndef _MSS_MRS_LOAD_DDR4_NIMBUS_H_
#define _MSS_MRS_LOAD_DDR4_NIMBUS_H_

#include <vector>
#include <fapi2.H>
#include <generic/memory/lib/ccs/ccs.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>

namespace mss
{

namespace ddr4
{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);
///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup setup-ccs-overloads
/// @addtogroyp setup-ccs-overloads
/// API which setup CCS instructions, but take an MRS data object as input
/// @{

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs00, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs00_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs01, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs01_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs01_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs02, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs02_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs02_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs03, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs00_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs03_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs04, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs04_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs04_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs05, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs05_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs05_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

///
/// @brief Configure the ARR0 of the CCS isntruction for mrs06, data object as input
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in] i_data an mrs06_data object, filled in
/// @param[in,out] io_inst the instruction to fixup
/// @param[in] i_rank ths rank in question
/// @return FAPI2_RC_SUCCESS iff OK
///
fapi2::ReturnCode mrs06(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                        const mrs06_data& i_data,
                        ccs::instruction_t& io_inst,
                        const uint64_t i_rank);

/// }@

///
/// @defgroup ccs-decode
/// @addtogroyccs-decode
/// API which decode CCS instructions.
/// @{

///
/// @brief Helper function for mrs00_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_burst_length the burst length
/// @param[out] o_read_burst_type the burst type
/// @param[out] o_dll_reset the dll reset bit
/// @param[out] o_test_mode the test mode bit
/// @param[out] o_wr_index the write index
/// @param[out] o_cas_latency the cas latency
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs00_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_burst_length,
                                      uint8_t& o_read_burst_type,
                                      uint8_t& o_dll_reset,
                                      uint8_t& o_test_mode,
                                      fapi2::buffer<uint8_t>& o_wr_index,
                                      fapi2::buffer<uint8_t>& o_cas_latency);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS00,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs00_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs01_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_dll_enable the dll enable bit
/// @param[out] o_wrl_enable the write leveling enable bit
/// @param[out] o_tdqs the tdqs enable bit
/// @param[out] o_qoff the qoff bit
/// @param[out] o_odic the output driver impedance control setting
/// @param[out] o_additive_latency the additive latency setting
/// @param[out] o_rtt_nom the rtt_nom setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_dll_enable,
                                      uint8_t& o_wrl_enable,
                                      uint8_t& o_tdqs,
                                      uint8_t& o_qoff,
                                      fapi2::buffer<uint8_t>& o_odic,
                                      fapi2::buffer<uint8_t>& o_additive_latency,
                                      fapi2::buffer<uint8_t>& o_rtt_nom);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS01,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs01_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs02_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_write_crc the write crc bit
/// @param[out] o_lpasr the low power array self refresh setting
/// @param[out] o_cwl the cas write latency setting
/// @param[out] o_rtt_wr the rtt_wr setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs02_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_write_crc,
                                      fapi2::buffer<uint8_t>& o_lpasr,
                                      fapi2::buffer<uint8_t>& o_cwl,
                                      fapi2::buffer<uint8_t>& o_rtt_wr);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS02,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs02_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs03_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
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
fapi2::ReturnCode mrs03_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_mpr_mode,
                                      uint8_t& o_geardown,
                                      uint8_t& o_pda,
                                      uint8_t& o_temp_readout,
                                      fapi2::buffer<uint8_t>& o_mpr_page,
                                      fapi2::buffer<uint8_t>& o_fine_refresh,
                                      fapi2::buffer<uint8_t>& o_crc_wr_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_read_format);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS03,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs03_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs04_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_max_pd_mode the maximum power down mode setting
/// @param[out] o_temp_refresh_range the temperature controlled refresh range setting
/// @param[out] o_temp_ref_mode the temperature controlled refresh mode setting
/// @param[out] o_vref_mon the internal vref monitor setting
/// @param[out] o_ref_abort the self refresh abort setting
/// @param[out] o_rd_pre_train_mode the read preamble training mode setting
/// @param[out] o_rd_preamble the read preamble setting
/// @param[out] o_wr_preamble the write preamble setting
/// @param[out] o_ppr the ppr setting
/// @param[out] o_cs_cmd_latency_buffer the cs to cmd/addr latency mode setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs04_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_max_pd_mode,
                                      uint8_t& o_temp_refresh_range,
                                      uint8_t& o_temp_ref_mode,
                                      uint8_t& o_vref_mon,
                                      uint8_t& o_ref_abort,
                                      uint8_t& o_rd_pre_train_mode,
                                      uint8_t& o_rd_preamble,
                                      uint8_t& o_wr_preamble,
                                      uint8_t& o_ppr,
                                      uint8_t& o_soft_ppr,
                                      fapi2::buffer<uint8_t>& o_cs_cmd_latency_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS04,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs04_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs05_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_crc_error_clear the crc error clear setting
/// @param[out] o_ca_parity_error_status the c/a parity error status
/// @param[out] o_odt_input_buffer the odt input buffer during power down mode setting
/// @param[out] o_ca_parity the c/a parity persistent error setting
/// @param[out] o_data_mask the data mask setting
/// @param[out] o_write_dbi the write dbi setting
/// @param[out] o_read_dbi the read dbi setting
/// @param[out] o_ca_parity_latency_buffer the c/a parity latency mode setting
/// @param[out] o_rtt_park_buffer the rtt_park setting
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs05_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_crc_error_clear,
                                      uint8_t& o_ca_parity_error_status,
                                      uint8_t& o_odt_input_buffer,
                                      uint8_t& o_ca_parity,
                                      uint8_t& o_data_mask,
                                      uint8_t& o_write_dbi,
                                      uint8_t& o_read_dbi,
                                      fapi2::buffer<uint8_t>& o_ca_parity_latency_buffer,
                                      fapi2::buffer<uint8_t>& o_rtt_park_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS05,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs05_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

///
/// @brief Helper function for mrs06_decode
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @param[out] o_vrefdq_train_range the vrefdq training range setting
/// @param[out] o_vrefdq_train_enable the vrefdq training enable setting
/// @param[out] o_tccd_l_buffer the tccd_l setting
/// @param[out] o_vrefdq_train_value_buffer the vrefdq training value
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs06_decode_helper(const ccs::instruction_t& i_inst,
                                      const uint64_t i_rank,
                                      uint8_t& o_vrefdq_train_range,
                                      uint8_t& o_vrefdq_train_enable,
                                      fapi2::buffer<uint8_t>& o_tccd_l_buffer,
                                      fapi2::buffer<uint8_t>& o_vrefdq_train_value_buffer);

///
/// @brief Given a CCS instruction which contains address bits with an encoded MRS06,
/// decode and trace the contents
/// @param[in] i_inst the CCS instruction
/// @param[in] i_rank the rank in question
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode mrs06_decode(const ccs::instruction_t& i_inst,
                               const uint64_t i_rank);

/// @}

///
/// @brief Perform the mrs_load DDR4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                            std::vector< ccs::instruction_t >& io_inst);

///
/// @brief Perform the mrs_load DDR4 operations for nvdimm restore - TARGET_TYPE_DIMM specialization
/// @param[in] i_target a fapi2::Target<fapi2::TARGET_TYPE_DIMM>
/// @param[in,out] io_inst a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode mrs_load_nvdimm( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   std::vector< ccs::instruction_t >& io_inst);

} // ddr4
} // mss
#endif
