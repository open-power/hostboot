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
// *HWP HWP Backup: Brian Silver <bsilver@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
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

///
/// @brief Configure the attributes for each controller
/// @param[in] i_target the controller (e.g., MCS)
/// @param[in] i_decode_spd_only options to set VPD and SPD attrs only
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode p9_mss_eff_config( const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target,
                                     const bool i_decode_spd_only )
{
    fapi2::ReturnCode l_rc;
    std::vector< std::shared_ptr<mss::spd::decoder> > l_factory_caches;
    // Caches
    FAPI_TRY( mss::spd::populate_decoder_caches(i_target, l_factory_caches) );

    // Need to check dead load before we get the VPD.
    // MR and MT VPD depends on DIMM ranks and freaks out if it recieves 0 ranks from DIMM 0 and 1 or more ranks for DIMM 1
    FAPI_TRY( mss::plug_rule::check_dead_load (i_target) );
    FAPI_TRY( mss::plug_rule::empty_slot_zero (i_target) );

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

        FAPI_TRY( mss::eff_dimm::eff_dimm_factory( l_cache, l_eff_dimm));
        FAPI_INF("%s Running eff_config", mss::c_str(l_cache->iv_target) );

        FAPI_TRY( l_eff_dimm->rcd_mfg_id() );
        FAPI_TRY( l_eff_dimm->register_type() );
        FAPI_TRY( l_eff_dimm->register_rev() );
        FAPI_TRY( l_eff_dimm->dram_mfg_id() );
        FAPI_TRY( l_eff_dimm->dram_width() );
        FAPI_TRY( l_eff_dimm->dram_density() );
        FAPI_TRY( l_eff_dimm->ranks_per_dimm() );
        FAPI_TRY( l_eff_dimm->prim_die_count() );
        FAPI_TRY( l_eff_dimm->primary_stack_type() );
        FAPI_TRY( l_eff_dimm->dimm_size() );
        FAPI_TRY( l_eff_dimm->hybrid_memory_type() );
        FAPI_TRY( l_eff_dimm->dram_trefi() );
        FAPI_TRY( l_eff_dimm->dram_trfc() );
        FAPI_TRY( l_eff_dimm->dram_trfc_dlr() );
        FAPI_TRY( l_eff_dimm->rcd_mirror_mode() );
        FAPI_TRY( l_eff_dimm->dram_bank_bits() );
        FAPI_TRY( l_eff_dimm->dram_row_bits() );
        FAPI_TRY( l_eff_dimm->dram_dqs_time() );
        FAPI_TRY( l_eff_dimm->dram_tccd_l() );
        FAPI_TRY( l_eff_dimm->dimm_rc00() );
        FAPI_TRY( l_eff_dimm->dimm_rc01() );
        FAPI_TRY( l_eff_dimm->dimm_rc02() );
        FAPI_TRY( l_eff_dimm->dimm_rc03() );
        FAPI_TRY( l_eff_dimm->dimm_rc04() );
        FAPI_TRY( l_eff_dimm->dimm_rc05() );
        FAPI_TRY( l_eff_dimm->dimm_rc06_07() );
        FAPI_TRY( l_eff_dimm->dimm_rc08() );
        FAPI_TRY( l_eff_dimm->dimm_rc09() );
        FAPI_TRY( l_eff_dimm->dimm_rc0a() );
        FAPI_TRY( l_eff_dimm->dimm_rc0b() );
        FAPI_TRY( l_eff_dimm->dimm_rc0c() );
        FAPI_TRY( l_eff_dimm->dimm_rc0d() );
        FAPI_TRY( l_eff_dimm->dimm_rc0e() );
        FAPI_TRY( l_eff_dimm->dimm_rc0f() );
        FAPI_TRY( l_eff_dimm->dimm_rc1x() );
        FAPI_TRY( l_eff_dimm->dimm_rc2x() );
        FAPI_TRY( l_eff_dimm->dimm_rc3x() );
        FAPI_TRY( l_eff_dimm->dimm_rc4x() );
        FAPI_TRY( l_eff_dimm->dimm_rc5x() );
        FAPI_TRY( l_eff_dimm->dimm_rc6x() );
        FAPI_TRY( l_eff_dimm->dimm_rc7x() );
        FAPI_TRY( l_eff_dimm->dimm_rc8x() );
        FAPI_TRY( l_eff_dimm->dimm_rc9x() );
        FAPI_TRY( l_eff_dimm->dimm_rcax() );
        FAPI_TRY( l_eff_dimm->dimm_rcbx() );
        FAPI_TRY( l_eff_dimm->dram_twr() );
        FAPI_TRY( l_eff_dimm->read_burst_type() );
        FAPI_TRY( l_eff_dimm->dram_tm() );
        FAPI_TRY( l_eff_dimm->dram_cwl() );
        FAPI_TRY( l_eff_dimm->dram_lpasr() );
        FAPI_TRY( l_eff_dimm->dll_enable() );
        FAPI_TRY( l_eff_dimm->dll_reset() );
        FAPI_TRY( l_eff_dimm->write_level_enable() );
        FAPI_TRY( l_eff_dimm->output_buffer() );
        FAPI_TRY( l_eff_dimm->vref_dq_train_value() );
        FAPI_TRY( l_eff_dimm->vref_dq_train_range() );
        FAPI_TRY( l_eff_dimm->vref_dq_train_enable() );
        FAPI_TRY( l_eff_dimm->ca_parity_latency() );
        FAPI_TRY( l_eff_dimm->ca_parity_error_status() );
        FAPI_TRY( l_eff_dimm->ca_parity() );
        FAPI_TRY( l_eff_dimm->crc_error_clear() );
        FAPI_TRY( l_eff_dimm->odt_input_buffer() );
        FAPI_TRY( l_eff_dimm->post_package_repair() );
        FAPI_TRY( l_eff_dimm->read_preamble_train() );
        FAPI_TRY( l_eff_dimm->read_preamble() );
        FAPI_TRY( l_eff_dimm->write_preamble() );
        FAPI_TRY( l_eff_dimm->self_refresh_abort() );
        FAPI_TRY( l_eff_dimm->cs_to_cmd_addr_latency() );
        FAPI_TRY( l_eff_dimm->internal_vref_monitor() );
        FAPI_TRY( l_eff_dimm->max_powerdown_mode() );
        FAPI_TRY( l_eff_dimm->mpr_read_format() );
        FAPI_TRY( l_eff_dimm->temp_readout() );
        FAPI_TRY( l_eff_dimm->crc_wr_latency() );
        FAPI_TRY( l_eff_dimm->per_dram_addressability() );
        FAPI_TRY( l_eff_dimm->geardown_mode() );
        FAPI_TRY( l_eff_dimm->mpr_page() );
        FAPI_TRY( l_eff_dimm->mpr_mode() );
        FAPI_TRY( l_eff_dimm->write_crc() );
        FAPI_TRY( l_eff_dimm->zqcal_interval() );
        FAPI_TRY( l_eff_dimm->memcal_interval() );
        FAPI_TRY( l_eff_dimm->dram_trp() );
        FAPI_TRY( l_eff_dimm->dram_trcd() );
        FAPI_TRY( l_eff_dimm->dram_trc() );
        FAPI_TRY( l_eff_dimm->dram_twtr_l() );
        FAPI_TRY( l_eff_dimm->dram_twtr_s() );
        FAPI_TRY( l_eff_dimm->dram_trrd_s() );
        FAPI_TRY( l_eff_dimm->dram_trrd_l() );
        FAPI_TRY( l_eff_dimm->dram_trrd_dlr() );
        FAPI_TRY( l_eff_dimm->dram_tfaw() );
        FAPI_TRY( l_eff_dimm->dram_tfaw_dlr() );
        FAPI_TRY( l_eff_dimm->dram_tras() );
        FAPI_TRY( l_eff_dimm->dram_trtp() );
        FAPI_TRY( l_eff_dimm->read_dbi() );
        FAPI_TRY( l_eff_dimm->write_dbi() );
        FAPI_TRY( l_eff_dimm->additive_latency() );
        FAPI_TRY( l_eff_dimm->data_mask() );
        FAPI_TRY( l_eff_dimm->dimm_bc00());
        FAPI_TRY( l_eff_dimm->dimm_bc01());
        FAPI_TRY( l_eff_dimm->dimm_bc02());
        FAPI_TRY( l_eff_dimm->dimm_bc03());
        FAPI_TRY( l_eff_dimm->dimm_bc04());
        FAPI_TRY( l_eff_dimm->dimm_bc05());
        FAPI_TRY( l_eff_dimm->dimm_bc07());
        FAPI_TRY( l_eff_dimm->dimm_bc08());
        FAPI_TRY( l_eff_dimm->dimm_bc09());
        FAPI_TRY( l_eff_dimm->dimm_bc0a());
        FAPI_TRY( l_eff_dimm->dimm_bc0b());
        FAPI_TRY( l_eff_dimm->dimm_bc0c());
        FAPI_TRY( l_eff_dimm->dimm_bc0d());
        FAPI_TRY( l_eff_dimm->dimm_bc0e());
        FAPI_TRY( l_eff_dimm->dimm_bc0f());
        FAPI_TRY( l_eff_dimm->dram_rtt_nom () );
        FAPI_TRY( l_eff_dimm->dram_rtt_wr  () );
        FAPI_TRY( l_eff_dimm->dram_rtt_park() );
        FAPI_TRY(  l_eff_dimm->phy_seq_refresh() );

        // Sets up the calibration steps
        FAPI_TRY( l_eff_dimm->cal_step_enable() );
        FAPI_TRY( l_eff_dimm->rdvref_enable_bit() );

        //Let's do some checking
        FAPI_TRY( mss::check::temp_refresh_mode());
    }// dimm

    // Check plug rules. We check the MCS, and this will iterate down to children as needed.
    FAPI_TRY( mss::plug_rule::enforce_plug_rules(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}
