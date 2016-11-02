/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_mss_eff_config.C
/// @brief Command and Control for the memory subsystem - populate attributes
///
// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <p9_mss_eff_config.H>

// std
#include <map>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/spd/common/spd_decoder.H>
#include <lib/spd/spd_factory.H>
#include <lib/eff_config/eff_config.H>
#include <lib/utils/pos.H>
#include <lib/utils/checker.H>
#include <lib/utils/find.H>

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target the controller (e.g., MCS)
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target )
{
    fapi2::ReturnCode l_rc;
    std::map<uint32_t, std::shared_ptr<mss::spd::decoder> > l_factory_caches;

    mss::eff_config l_eff_config(i_target, l_rc);
    FAPI_TRY(l_rc, "Unable to construct eff_config object for for %s", mss::c_str(i_target) );

    // Caches
    FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches) );

    // We need to decode the VPD. We don't do this in the ctor as we need
    // the rank information and for that we need the SPD caches (which we get when we populate the cache.)
    // However, we need to do the VPD decode before the others so that they might
    // be able to use VPD information to make decisions about setting up eff attributes.
    FAPI_TRY( l_eff_config.decode_vpd(i_target),
              "Unable to decode VPD for %s", mss::c_str(i_target) );

    for( const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target) )
    {
        const auto l_dimm_pos = mss::pos(l_dimm);

        // TODO RTC:152390 Create function to do map checking on cached values
        // Find decoder factory for this dimm position
        auto l_it = l_factory_caches.find(l_dimm_pos);

        FAPI_TRY( mss::check::spd::invalid_cache(l_dimm,
                  l_it != l_factory_caches.end(),
                  l_dimm_pos),
                  "Failed to get valid cache (main decoder)");

        l_eff_config.iv_pDecoder = l_it->second;

        FAPI_TRY( l_eff_config.dimm_type(l_dimm, l_it->second->iv_spd_data) );
        FAPI_TRY( l_eff_config.dram_mfg_id(l_dimm) );
        FAPI_TRY( l_eff_config.dram_gen(l_dimm, l_it->second->iv_spd_data) );
        FAPI_TRY( l_eff_config.dram_width(l_dimm) );
        FAPI_TRY( l_eff_config.dram_density(l_dimm) );
        FAPI_TRY( l_eff_config.ranks_per_dimm(l_dimm) );
        FAPI_TRY( l_eff_config.primary_stack_type(l_dimm) );
        FAPI_TRY( l_eff_config.dimm_size(l_dimm) );
        FAPI_TRY( l_eff_config.hybrid_memory_type(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trefi(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trfc(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trfc_dlr(l_dimm) );
        FAPI_TRY( l_eff_config.rcd_mirror_mode(l_dimm) );
        FAPI_TRY( l_eff_config.dram_bank_bits(l_dimm) );
        FAPI_TRY( l_eff_config.dram_row_bits(l_dimm) );
        FAPI_TRY( l_eff_config.dram_dqs_time(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tccd_l(l_dimm) );
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
        FAPI_TRY( l_eff_config.read_burst_type(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tm(l_dimm) );
        FAPI_TRY( l_eff_config.dram_cwl(l_dimm) );
        FAPI_TRY( l_eff_config.dram_lpasr(l_dimm) );
        FAPI_TRY( l_eff_config.dll_enable(l_dimm) );
        FAPI_TRY( l_eff_config.dll_reset(l_dimm) );
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
        FAPI_TRY( l_eff_config.zqcal_interval(l_dimm) );
        FAPI_TRY( l_eff_config.memcal_interval(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trp(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trcd(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trc(l_dimm) );
        FAPI_TRY( l_eff_config.dram_twtr_l(l_dimm) );
        FAPI_TRY( l_eff_config.dram_twtr_s(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trrd_s(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trrd_l(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trrd_dlr(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tfaw(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tfaw_dlr(l_dimm) );
        FAPI_TRY( l_eff_config.dram_tras(l_dimm) );
        FAPI_TRY( l_eff_config.dram_trtp(l_dimm) );
        FAPI_TRY( l_eff_config.read_dbi(l_dimm) );
        FAPI_TRY( l_eff_config.write_dbi(l_dimm) );
        FAPI_TRY( l_eff_config.additive_latency(l_dimm) );
        FAPI_TRY( l_eff_config.data_mask(l_dimm) );

    }// dimm

    {
        uint16_t l_cal_step[mss::PORTS_PER_MCS] = {0xFAC0, 0xFAC0};
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_MSS_CAL_STEP_ENABLE, i_target, l_cal_step) );
    }

    {
        // TODO RTC:162080 Logically link ATTR_MSS_MRW_TEMP_REFRESH_RANGE and MODE
        uint8_t l_temp_refresh_mode[mss::PORTS_PER_MCS] =
        {fapi2::ENUM_ATTR_EFF_TEMP_REFRESH_MODE_DISABLE, fapi2::ENUM_ATTR_EFF_TEMP_REFRESH_MODE_DISABLE};
        FAPI_TRY( FAPI_ATTR_SET( fapi2::ATTR_EFF_TEMP_REFRESH_MODE, i_target, l_temp_refresh_mode ) );
    }

    // Check plug rules. We check the MCS, and this will iterate down to children as needed.
    FAPI_TRY( l_eff_config.enforce_plug_rules(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}
