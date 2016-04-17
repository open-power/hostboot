/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/eff_config.H $  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file eff_config.H
/// @brief Determine effective config for mss settings
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP FW Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EFF_CONFIG_H_
#define _MSS_EFF_CONFIG_H_

#include <fapi2.H>
#include <cstdint>
#include <lib/spd/spd_decoder.H>

namespace mss
{

///
/// @class eff_config
/// @brief Determine effective config for mss settings
///
class eff_config
{
    public:
        std::shared_ptr<spd::decoder> iv_pDecoder;

        // ctor
        eff_config() = default;

        // dtor
        ~eff_config() = default;

        ////////////////////////
        // Methods
        ///////////////////////

        ///
        /// @brief Determines & sets effective config for DRAM generation from SPD
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_gen(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                   const std::vector<uint8_t>& i_spd_data);

        ///
        /// @brief Determines & sets effective config for DIMM type
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                    const std::vector<uint8_t>& i_spd_data);

        ///
        /// @brief Determines & sets effective config for primary stack type
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode primary_stack_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Hybrid memory type from SPD
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode hybrid_memory_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for refresh interval time (tREFI)
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode refresh_interval_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for refresh cycle time (tRFC)
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode refresh_cycle_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for refresh cycle time (logical ranks) (tRFC_DLR)
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode refresh_cycle_time_dlr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dram density
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_density(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dram width
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_width(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dimm rcd mirror mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rcd_mirror_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dimm size
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_size(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dram bank bits
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_bank_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for dram row bits
        ///  @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_row_bits(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for number of ranks per dimm
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for number of master ranks per dimm
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode master_ranks_per_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for custom dimm
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode custom_dimm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for tDQS
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_dqs_time(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for ODT RD
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode odt_read(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for ODT WR
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode odt_write(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);
        ///
        /// @brief Determines & sets effective config for tCCD_L
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tccd_l(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for RTT Park
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rtt_park(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC00
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc00(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC01
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc01(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC02
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc02(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC03
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc03(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC04
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc04(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC05
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc05(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC06_07
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc06_07(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC08
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc08(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC09
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc09(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC10
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc10(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC11
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc11(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC12
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc12(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC13
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc13(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC14
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc14(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC15
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc15(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_1x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc1x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_2x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc2x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_3x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc3x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_4x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc4x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_5x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc5x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_6x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc6x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_7x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc7x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_8x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc8x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DIMM RC_9x
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rc9x(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);


        ///
        /// @brief Determines & sets effective config for DIMM RC_AX
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rcax(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);


        ///
        /// @brief Determines & sets effective config for DIMM RC_BX
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dimm_rcbx(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for tWR
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_twr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for burst length (BL)
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode burst_length(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for RBT
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_burst_type(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for TM
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_tm(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for cwl
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_cwl(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for lpasr
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_lpasr(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);


        ///
        /// @brief Determines & sets effective config for additive latency
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode additive_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DLL Reset
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dll_reset(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for DLL Enable
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dll_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for RON
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode dram_ron(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for RTT NOM
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rtt_nom(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Write Level Enable
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_level_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Output Buffer
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode output_buffer(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);


        ///
        /// @brief Determines & sets effective config for Vref DQ Train Value
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vref_dq_train_value(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Vref DQ Train Enable
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vref_dq_train_enable(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Vref DQ Train Range
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode vref_dq_train_range(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for CA Parity Latency
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for CA Parity
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for CRC Error Clear
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode crc_error_clear(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for CA Parity Error Status
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode ca_parity_error_status(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for ODT Input Buffer
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode odt_input_buffer(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for data_mask
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode data_mask(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for write_dbi
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_dbi(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for read_dbi
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_dbi(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for Post Package Repair
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode post_package_repair(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for rd_preamble_train
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_preamble_train(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for rd_preamble
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode read_preamble(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for wr_preamble
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_preamble(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for self_ref_abort
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode self_refresh_abort(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for cs_cmd_latency
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode cs_to_cmd_addr_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for int_vref_mon
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode internal_vref_monitor(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for powerdown_mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode max_powerdown_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for mpr_rd_format
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_read_format(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for CRC write latency
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode crc_wr_latency(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for temperature readout
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode temp_readout(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for per DRAM addressability
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode per_dram_addressability(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for geardown mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode geardown_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for geardown mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_page(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for MPR mode
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode mpr_mode(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for write CRC
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode write_crc(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for RTT Write
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode rtt_write(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for ZQ Calibration
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode zqcal_interval(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

        ///
        /// @brief Determines & sets effective config for MEMCAL Calibration
        /// @param[in] i_target FAPI2 target
        /// @return fapi2::FAPI2_RC_SUCCESS if okay
        ///
        fapi2::ReturnCode memcal_interval(const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target);

};// eff_config

} // mss

#endif // _MSS_EFF_CONFIG_H_
