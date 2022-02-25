/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2022                        */
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
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <p9_mss_eff_config.H>

// std
#include <vector>

// fapi2
#include <fapi2.H>

// mss lib
#include <lib/shared/nimbus_defaults.H>
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/utils/checker.H>
#include <lib/utils/nimbus_find.H>
#include <lib/shared/mss_kind.H>
#include <lib/dimm/eff_dimm.H>
#include <lib/eff_config/plug_rules.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <lib/workarounds/eff_config_workarounds.H>

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target the controller (e.g., MCS)
/// @param[in] i_decode_spd_only options to set VPD and SPD attrs only
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                     const bool i_decode_spd_only )
{
    if ( mss::count_dimm(i_target) == 0 )
    {
        FAPI_INF("No DIMMs found on %s... Skipping p9_mss_eff_config", mss::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    std::vector< mss::spd::facade > l_spd_facades;
    FAPI_TRY( get_spd_decoder_list(i_target, l_spd_facades) );

    // Need to check dead load before we get the VPD.
    // MR and MT VPD depends on DIMM ranks and freaks out if it receives 0 ranks from DIMM 0 and 1 or more ranks for DIMM 1
    FAPI_TRY( mss::plug_rule::check_dead_load(i_target),
              "Failed check_dead_load for %s", mss::c_str(i_target) );
    FAPI_TRY( mss::plug_rule::empty_slot_zero(i_target),
              "Failed empty_slot_zero for %s", mss::c_str(i_target));

    // We need to decode the VPD. We don't do this in the ctor as we need
    // the rank information and for that we need the SPD caches (which we get when we populate the cache.)
    // However, we need to do the VPD decode before the others so that they might
    // be able to use VPD information to make decisions about setting up eff attributes.
    if( !i_decode_spd_only )
    {
        // Always set VPD attributes unless we enable the SPD_ONLY flag
        // Enables skipping VPD decoder when a valid VPD template isn't available
        FAPI_TRY( mss::eff_dimm::decode_vpd(i_target),
                  "Unable to decode VPD for %s", mss::c_str(i_target) );
    }

    // First we process the ODIC and ODT values since we need these initialized for both DIMM
    // on a port if we're in a dual-drop config
    for( const auto& l_spd : l_spd_facades )
    {
        const auto l_dimm = l_spd.get_target();

        std::shared_ptr<mss::eff_dimm> l_eff_dimm;
        FAPI_TRY( mss::eff_dimm::factory( l_spd, l_eff_dimm),
                  "Failed factory for %s",  mss::c_str(l_dimm));

        FAPI_INF("Setting up ODIC and ODT attributes on %s", mss::c_str(l_dimm) );

        FAPI_TRY(  l_eff_dimm->lrdimm_training_pattern(),
                   "Failed lrdimm_training_pattern for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dram_odic(),
                   "Failed dram_odic for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->odt_wr(),
                   "Failed odt_wr for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->odt_rd(),
                   "Failed odt_rd for %s", mss::c_str(l_dimm) );
    }

    // Now we continue with the remainder of eff_config
    for( const auto& l_spd : l_spd_facades )
    {
        const auto l_dimm = l_spd.get_target();

        std::shared_ptr<mss::eff_dimm> l_eff_dimm;
        FAPI_TRY( mss::eff_dimm::factory( l_spd, l_eff_dimm),
                  "Failed factory for %s",  mss::c_str(l_dimm));

        FAPI_INF("Running eff_config on %s", mss::c_str(l_dimm) );

        FAPI_TRY(  l_eff_dimm->phy_rlo(),
                   "Failed phy_rlo for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->phy_wlo(),
                   "Failed phy_wlo for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->rcd_mfg_id(),
                  "Failed rcd_mfg_id for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->register_type(),
                  "Failed register_type for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->register_rev(),
                  "Failed register_rev for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_mfg_id(),
                  "Failed dram_mfg_id for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_width(),
                  "Failed dram_width for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_density(),
                  "Failed dram_density for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->ranks_per_dimm(),
                  "Failed ranks_per_dimm for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->prim_die_count(),
                  "Failed prim_die_count for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->primary_stack_type(),
                  "Failed primary_stack_type for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_size(),
                  "Failed dimm_size for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trefi(),
                  "Failed dram_trefi for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trfc(),
                  "Failed dram_trfc for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trfc_dlr(),
                  "Failed dram_trfc_dlr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->rcd_mirror_mode(),
                  "Failed rcd_mirror_mode for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_bank_bits(),
                  "Failed dram_bank_bits for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_row_bits(),
                  "Failed dram_row_bits for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_dqs_time(),
                  "Failed dram_dqs_time for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_tccd_l(),
                  "Failed dram_tccd_l for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc00(),
                  "Failed dimm_rc00 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc01(),
                  "Failed dimm_rc01 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc02(),
                  "Failed dimm_rc02 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc03(),
                  "Failed dimm_rc03 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc04(),
                  "Failed dimm_rc04 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc05(),
                  "Failed dimm_rc05 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc06_07(),
                  "Failed dimm_rc06_07 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc08(),
                  "Failed dimm_rc08 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc09(),
                  "Failed dimm_rc09 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0a(),
                  "Failed dimm_rc0a for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0b(),
                  "Failed dimm_rc0b for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0c(),
                  "Failed dimm_rc0c for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0d(),
                  "Failed dimm_rc0d for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0e(),
                  "Failed dimm_rc0e for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc0f(),
                  "Failed dimm_rc0f for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc1x(),
                  "Failed dimm_rc1x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc2x(),
                  "Failed dimm_rc2x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc3x(),
                  "Failed dimm_rc3x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc4x(),
                  "Failed dimm_rc4x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc5x(),
                  "Failed dimm_rc5x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc6x(),
                  "Failed dimm_rc6x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc7x(),
                  "Failed dimm_rc7x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc8x(),
                  "Failed dimm_rc8x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rc9x(),
                  "Failed dimm_rc9x for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rcax(),
                  "Failed dimm_rcax for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_rcbx(),
                  "Failed dimm_rcbx for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_twr(),
                  "Failed dram_twr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->read_burst_type(),
                  "Failed read_burst_type for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_tm(),
                  "Failed dram_tm for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_cwl(),
                  "Failed dram_cwl for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_lpasr(),
                  "Failed dram_lpasr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dll_enable(),
                  "Failed dll_enable for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dll_reset(),
                  "Failed dll_reset for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->write_level_enable(),
                  "Failed write_level_enable for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->output_buffer(),
                  "Failed output_buffer for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->vref_dq_train_value_and_range(),
                  "Failed vref_dq_train_value_and_range for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->vref_dq_train_enable(),
                  "Failed vref_dq_train_enable for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->ca_parity_latency(),
                  "Failed ca_parity_latency for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->ca_parity_error_status(),
                  "Failed ca_parity_error_status for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->ca_parity(),
                  "Failed ca_parity for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->crc_error_clear(),
                  "Failed crc_error_clear for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->odt_input_buffer(),
                  "Failed odt_input_buffer for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->post_package_repair(),
                  "Failed post_package_repair for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->soft_post_package_repair(),
                  "Failed soft_post_package_repair for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->read_preamble_train(),
                  "Failed read_preamble_train for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->read_preamble(),
                  "Failed read_preamble for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->write_preamble(),
                  "Failed write_preamble for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->self_refresh_abort(),
                  "Failed self_refresh_abort for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->cs_to_cmd_addr_latency(),
                  "Failed cs_to_cmd_addr_latency for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->internal_vref_monitor(),
                  "Failed internal_vref_monitor for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->max_powerdown_mode(),
                  "Failed max_powerdown_mode for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->mpr_read_format(),
                  "Failed mpr_read_format for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->temp_readout(),
                  "Failed temp_readout for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->crc_wr_latency(),
                  "Failed crc_wr_latency for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->per_dram_addressability(),
                  "Failed per_dram_addressability for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->geardown_mode(),
                  "Failed geardown_mode for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->mpr_page(),
                  "Failed mpr_page for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->mpr_mode(),
                  "Failed mpr_mode for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->write_crc(),
                  "Failed write_crc for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->zqcal_interval(),
                  "Failed zqcal_interval for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->memcal_interval(),
                  "Failed memcal_interval for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trp(),
                  "Failed dram_trp for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trcd(),
                  "Failed dram_trcd for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trc(),
                  "Failed dram_trc for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_twtr_l(),
                  "Failed dram_twtr_l for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_twtr_s(),
                  "Failed dram_twtr_s for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trrd_s(),
                  "Failed dram_trrd_s for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trrd_l(),
                  "Failed dram_trrd_l for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trrd_dlr(),
                  "Failed dram_trrd_dlr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_tfaw(),
                  "Failed dram_tfaw for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_tfaw_dlr(),
                  "Failed dram_tfaw_dlr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_tras(),
                  "Failed dram_tras for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_trtp(),
                  "Failed dram_trtp for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->read_dbi(),
                  "Failed read_dbi for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->write_dbi(),
                  "Failed write_dbi for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->additive_latency(),
                  "Failed additive_latency for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->data_mask(),
                  "Failed data_mask for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc00(),
                  "Failed dimm_bc00 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc01(),
                  "Failed dimm_bc01 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc02(),
                  "Failed dimm_bc02 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc03(),
                  "Failed dimm_bc03 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc04(),
                  "Failed dimm_bc04 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc05(),
                  "Failed dimm_bc05 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc06(),
                  "Failed dimm_bc06 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc07(),
                  "Failed dimm_bc07 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc08(),
                  "Failed dimm_bc08 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc09(),
                  "Failed dimm_bc09 for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0a(),
                  "Failed dimm_bc0a for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0b(),
                  "Failed dimm_bc0b for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0c(),
                  "Failed dimm_bc0c for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0d(),
                  "Failed dimm_bc0d for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0e(),
                  "Failed dimm_bc0e for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dimm_bc0f(),
                  "Failed dimm_bc0f for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_rtt_nom (),
                  "Failed dram_rtt_nom for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_rtt_wr  (),
                  "Failed dram_rtt_wr for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->dram_rtt_park(),
                  "Failed dram_rtt_park for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->phy_seq_refresh(),
                   "Failed phy_seq_refresh for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->package_rank_map(),
                   "Failed package_rank_map for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->nibble_map(),
                   "Failed nibble_map for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->wr_crc(),
                   "Failed wr_crc for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f0bc1x(),
                   "Failed dimm_f0bc1x for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f0bc6x(),
                   "Failed dimm_f0bc6x for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f2bcex(),
                   "Failed dimm_f2bcex for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f5bc5x(),
                   "Failed dimm_f5bc5x for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f5bc6x(),
                   "Failed dimm_f5bc6x for %s", mss::c_str(l_dimm) );
        FAPI_TRY(  l_eff_dimm->dimm_f6bc4x(),
                   "Failed dimm_f6bc4x for %s", mss::c_str(l_dimm) );

        // Sets up the calibration steps
        FAPI_TRY( l_eff_dimm->cal_step_enable(),
                  "Failed cal_step_enable for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->is_m386a8k40cm2_ctd7y(),
                  "Failed is m386a8k40cm2_ctd7y for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->rdvref_enable_bit(),
                  "Failed rdvref_enable_bit for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->training_adv_wr_pattern(),
                  "Failed training_adv_wr_pattern for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->training_adv_pattern(),
                  "Failed training_adv_pattern for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->training_adv_backup_pattern(),
                  "Failed training_adv_backup_pattern for %s", mss::c_str(l_dimm) );
        FAPI_TRY( l_eff_dimm->training_adv_backup_pattern2(),
                  "Failed training_adv_backup_pattern2 for %s", mss::c_str(l_dimm) );

        //Let's do some checking
        FAPI_TRY( mss::check::temp_refresh_mode(),
                  "Failed temp_refresh_mode for %s", mss::c_str(l_dimm) );
    }// dimm

    // Check plug rules. We check the MCS, and this will iterate down to children as needed.
    FAPI_TRY( mss::plug_rule::enforce_plug_rules(i_target),
              "Failed enforce_plug_rules for %s", mss::c_str(i_target) );

    // Sychronizes timings to allow broadcast mode mode to be run
    FAPI_TRY(mss::workarounds::eff_config::synchronize_broadcast_timings(i_target));

    // Updates attributes for the 128GB DIMM's if needed
    FAPI_TRY(mss::workarounds::eff_config::update_128gb_attributes(i_target));

fapi_try_exit:
    return fapi2::current_err;
}
