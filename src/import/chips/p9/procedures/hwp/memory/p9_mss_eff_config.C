/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/p9_mss_eff_config.C $          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file p9_mss_eff_config.C
/// @brief Command and Control for the memory subsystem - populate attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB
#include <map>
#include <vector>

#include <fapi2.H>
#include <p9_mss_eff_config.H>
#include <lib/utils/pos.H>
#include <lib/spd/spd_decoder.H>
#include <lib/eff_config/eff_config.H>
#include <lib/utils/checker.H>
#include <lib/utils/find.H>

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    mss::eff_config l_eff_config;
    // Caches
    std::map<uint32_t, std::shared_ptr<mss::spd::decoder> > l_factory_caches;
    FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches) );

    for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        const auto l_dimm_pos = mss::pos(l_dimm);

        // TODO: RTC 152390
        // Find decoder factory for this dimm position
        auto l_it = l_factory_caches.find(l_dimm_pos);

        FAPI_TRY( mss::check::spd::invalid_cache(l_dimm,
                  l_it != l_factory_caches.end(),
                  l_dimm_pos),
                  "Failed to get valid cache");

        l_eff_config.iv_pDecoder = l_it->second;

        FAPI_TRY( l_eff_config.dimm_type(l_dimm, l_it->second->iv_spd_data) );
        FAPI_TRY( l_eff_config.dram_gen(l_dimm, l_it->second->iv_spd_data) );
        FAPI_TRY( l_eff_config.dram_width(l_dimm) );
        FAPI_TRY( l_eff_config.dram_density(l_dimm) );
        FAPI_TRY( l_eff_config.ranks_per_dimm(l_dimm) );
        FAPI_TRY( l_eff_config.master_ranks_per_dimm(l_dimm) );
        FAPI_TRY( l_eff_config.primary_stack_type(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_size(l_dimm) );
        FAPI_TRY( l_eff_config.hybrid_memory_type(l_dimm) );
        FAPI_TRY( l_eff_config.refresh_interval_time(l_dimm) );
        FAPI_TRY( l_eff_config.refresh_cycle_time(l_dimm) );
        FAPI_TRY( l_eff_config.refresh_cycle_time_dlr(l_dimm) );
        FAPI_TRY( l_eff_config.rcd_mirror_mode(l_dimm) );
        FAPI_TRY( l_eff_config.dram_bank_bits(l_dimm) );
        FAPI_TRY( l_eff_config.dram_row_bits(l_dimm) );
        FAPI_TRY( l_eff_config.custom_dimm(l_dimm) );
        FAPI_TRY( l_eff_config.dram_dqs_time(l_dimm) );
        FAPI_TRY( l_eff_config.odt_read(l_dimm) );
        FAPI_TRY( l_eff_config.odt_write(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tccd_l(l_dimm) );
        FAPI_TRY( l_eff_config.data_mask(l_dimm) );
        FAPI_TRY( l_eff_config.rtt_park(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc00(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc01(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc02(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc03(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc04(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc05(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc06_07(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc08(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc09(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc10(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc11(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc12(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc13(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc14(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc15(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc1x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc2x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc3x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc4x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc5x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc6x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc7x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc8x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rc9x(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rcax(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_rcbx(l_dimm) );
        FAPI_TRY( l_eff_config.dram_twr(l_dimm) );
        FAPI_TRY( l_eff_config.burst_length(l_dimm) );
        FAPI_TRY( l_eff_config.read_burst_type(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tm(l_dimm) );
        FAPI_TRY( l_eff_config.dram_cwl(l_dimm) );
        FAPI_TRY( l_eff_config.dram_lpasr(l_dimm) );
        FAPI_TRY( l_eff_config.additive_latency(l_dimm) );
        FAPI_TRY( l_eff_config.dll_enable(l_dimm) );
        FAPI_TRY( l_eff_config.dll_reset(l_dimm) );
        FAPI_TRY( l_eff_config.dram_ron(l_dimm) );
        FAPI_TRY( l_eff_config.rtt_nom(l_dimm) );
        FAPI_TRY( l_eff_config.write_level_enable(l_dimm) );
        FAPI_TRY( l_eff_config.output_buffer(l_dimm) );
        FAPI_TRY( l_eff_config.vref_dq_train_value(l_dimm) );
        FAPI_TRY( l_eff_config.vref_dq_train_range(l_dimm) );
        FAPI_TRY( l_eff_config.vref_dq_train_enable(l_dimm) );
        FAPI_TRY( l_eff_config.ca_parity_latency(l_dimm) );
        FAPI_TRY( l_eff_config.ca_parity_error_status(l_dimm) );
        FAPI_TRY( l_eff_config.ca_parity(l_dimm) );
        FAPI_TRY( l_eff_config.crc_error_clear(l_dimm) );
        FAPI_TRY( l_eff_config.odt_input_buffer(l_dimm) );
        FAPI_TRY( l_eff_config.write_dbi(l_dimm) );
        FAPI_TRY( l_eff_config.read_dbi(l_dimm) );
        FAPI_TRY( l_eff_config.post_package_repair(l_dimm) );
        FAPI_TRY( l_eff_config.read_preamble_train(l_dimm) );
        FAPI_TRY( l_eff_config.read_preamble(l_dimm) );
        FAPI_TRY( l_eff_config.write_preamble(l_dimm) );
        FAPI_TRY( l_eff_config.self_refresh_abort(l_dimm) );
        FAPI_TRY( l_eff_config.cs_to_cmd_addr_latency(l_dimm) );
        FAPI_TRY( l_eff_config.internal_vref_monitor(l_dimm) );
        FAPI_TRY( l_eff_config.max_powerdown_mode(l_dimm) );
        FAPI_TRY( l_eff_config.mpr_read_format(l_dimm) );
        FAPI_TRY( l_eff_config.temp_readout(l_dimm) );
        FAPI_TRY( l_eff_config.crc_wr_latency(l_dimm) );
        FAPI_TRY( l_eff_config.per_dram_addressability(l_dimm) );
        FAPI_TRY( l_eff_config.geardown_mode(l_dimm) );
        FAPI_TRY( l_eff_config.mpr_page(l_dimm) );
        FAPI_TRY( l_eff_config.mpr_mode(l_dimm) );
        FAPI_TRY( l_eff_config.write_crc(l_dimm) );
        FAPI_TRY( l_eff_config.rtt_write(l_dimm) );
        FAPI_TRY( l_eff_config.zqcal_interval(l_dimm) );
        FAPI_TRY( l_eff_config.memcal_interval(l_dimm) );

        // Hard-coded RIT protect attribute set (currently not taken account in eff_config)
        {
            uint16_t l_vpd_mt_windage_rd_ctr[mss::PORTS_PER_MCS] = {0xDEAD, 0xBEEF};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_VPD_MT_WINDAGE_RD_CTR, i_target, l_vpd_mt_windage_rd_ctr) );
        }

        {
            uint8_t l_vpd_rlo[mss::PORTS_PER_MCS] = {0x01, 0x01};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_VPD_RLO, i_target, l_vpd_rlo ) );
        }

        {
            uint8_t l_vpd_wlo[mss::PORTS_PER_MCS] = {0x01, 0x01};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_VPD_WLO, i_target, l_vpd_wlo ) );
        }

        {
            uint8_t l_vpd_glo[mss::PORTS_PER_MCS] = {0x05, 0x05};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_VPD_GPO, i_target, l_vpd_glo ) );
        }

        {
            uint32_t l_m_dram_clocks[mss::PORTS_PER_MCS] = {0x200, 0x200};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_M_DRAM_CLOCKS, i_target, l_m_dram_clocks ) );
        }

        {
            uint32_t l_throttled_n_commands[mss::PORTS_PER_MCS] = {0x60, 0x60};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_RUNTIME_MEM_THROTTLED_N_COMMANDS_PER_PORT, i_target,
                                     l_throttled_n_commands ) );
        }

        {
            uint8_t l_throttle_ras[mss::PORTS_PER_MCS] = {0x00, 0x00};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_THROTTLE_CONTROL_RAS_WEIGHT, i_target, l_throttle_ras ) );
        }

        {
            uint8_t l_throttle_cas[mss::PORTS_PER_MCS] = {0x01, 0x01};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_THROTTLE_CONTROL_CAS_WEIGHT, i_target, l_throttle_cas ) );
        }

        {
            uint8_t l_databus_util[mss::PORTS_PER_MCS][mss::MAX_DIMM_PER_PORT] = {};
            FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_MSS_DATABUS_UTIL, i_target, l_databus_util ) );
        }

        {
            uint16_t l_cal_step[mss::PORTS_PER_MCS] = {0x7AC0, 0x7AC0};
            FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CAL_STEP_ENABLE, i_target, l_cal_step) );
        }

    }// dimm

fapi_try_exit:
    return fapi2::current_err;
}
