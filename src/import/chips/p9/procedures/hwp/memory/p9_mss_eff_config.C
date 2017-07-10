/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/p9_mss_eff_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
#include <generic/memory/lib/spd/common/ddr4/spd_decoder_ddr4.H>
#include <lib/spd/spd_factory.H>
#include <generic/memory/lib/utils/pos.H>
#include <lib/utils/checker.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/shared/mss_kind.H>
#include <lib/dimm/eff_dimm.H>
#include <lib/eff_config/plug_rules.H>
#include <lib/utils/count_dimm.H>

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

    fapi2::ReturnCode l_rc;
    std::vector< std::shared_ptr<mss::spd::decoder> > l_factory_caches;
    // Caches
    FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches), "Error from p9_mss_eff_config");

    // Need to check dead load before we get the VPD.
    // MR and MT VPD depends on DIMM ranks and freaks out if it receives 0 ranks from DIMM 0 and 1 or more ranks for DIMM 1
    FAPI_TRY( mss::plug_rule::check_dead_load (i_target), "Error from p9_mss_eff_config" );
    FAPI_TRY( mss::plug_rule::empty_slot_zero (i_target), "Error from p9_mss_eff_config" );

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

    for( const auto& l_cache : l_factory_caches )
    {
        std::shared_ptr<mss::eff_dimm> l_eff_dimm;

        FAPI_TRY( mss::eff_dimm::eff_dimm_factory( l_cache, l_eff_dimm), "Error from p9_mss_eff_config");
        FAPI_INF("%s Running eff_config", mss::c_str(l_cache->iv_target) );

        FAPI_TRY( l_eff_dimm->rcd_mfg_id(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->register_type(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->register_rev(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_mfg_id(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_width(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_density(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->ranks_per_dimm(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->prim_die_count(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->primary_stack_type(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_size(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->hybrid_memory_type(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trefi(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trfc(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trfc_dlr(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->rcd_mirror_mode(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_bank_bits(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_row_bits(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_dqs_time(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_tccd_l(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc00(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc01(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc02(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc03(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc04(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc05(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc06_07(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc08(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc09(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0a(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0b(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0c(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0d(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0e(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc0f(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc1x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc2x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc3x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc4x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc5x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc6x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc7x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc8x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rc9x(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rcax(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_rcbx(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_twr(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->read_burst_type(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_tm(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_cwl(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_lpasr(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dll_enable(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dll_reset(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->write_level_enable(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->output_buffer(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->vref_dq_train_value(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->vref_dq_train_range(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->vref_dq_train_enable(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->ca_parity_latency(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->ca_parity_error_status(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->ca_parity(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->crc_error_clear(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->odt_input_buffer(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->post_package_repair(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->read_preamble_train(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->read_preamble(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->write_preamble(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->self_refresh_abort(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->cs_to_cmd_addr_latency(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->internal_vref_monitor(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->max_powerdown_mode(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->mpr_read_format(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->temp_readout(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->crc_wr_latency(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->per_dram_addressability(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->geardown_mode(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->mpr_page(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->mpr_mode(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->write_crc(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->zqcal_interval(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->memcal_interval(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trp(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trcd(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trc(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_twtr_l(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_twtr_s(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trrd_s(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trrd_l(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trrd_dlr(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_tfaw(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_tfaw_dlr(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_tras(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_trtp(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->read_dbi(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->write_dbi(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->additive_latency(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->data_mask(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc00(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc01(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc02(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc03(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc04(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc05(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc07(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc08(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc09(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0a(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0b(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0c(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0d(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0e(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dimm_bc0f(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_rtt_nom (), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_rtt_wr  (), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->dram_rtt_park(), "Error from p9_mss_eff_config");
        FAPI_TRY(  l_eff_dimm->phy_seq_refresh(), "Error from p9_mss_eff_config");

        // Sets up the calibration steps
        FAPI_TRY( l_eff_dimm->cal_step_enable(), "Error from p9_mss_eff_config");
        FAPI_TRY( l_eff_dimm->rdvref_enable_bit(), "Error from p9_mss_eff_config");

        //Let's do some checking
        FAPI_TRY( mss::check::temp_refresh_mode(), "Error from p9_mss_eff_config");
    }// dimm

    // Check plug rules. We check the MCS, and this will iterate down to children as needed.
    FAPI_TRY( mss::plug_rule::enforce_plug_rules(i_target), "Error from p9_mss_eff_config");

fapi_try_exit:
    return fapi2::current_err;
}
