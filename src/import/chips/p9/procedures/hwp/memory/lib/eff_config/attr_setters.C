/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/memory/lib/eff_config/attr_setters.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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
/// @file attr_setters.C
/// @brief Create setter functions for mss attributes
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Andre A. Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: HB:FSP


#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/shared/mss_generic_consts.H>
#include <generic/memory/lib/data_engine/pre_data_init.H>

namespace mss
{

///
/// @brief Set ATTR_MSS_VOLT_VDDR and ATTR_MSS_VOLT_VPP
/// @param[in] i_target_mcs the MCS target
/// @param[in] i_selected_dram_voltage the voltage in millivolts for nominal voltage
/// @param[in] i_selected_dram_voltage_vpp voltage  in millivolts for the VPP
/// @note dram_voltage and dram_voltage_vpp are not const due to FAPI_ATTR_SET template deduction
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_voltage_attributes(const fapi2::Target<fapi2::TARGET_TYPE_MCS>& i_target_mcs,
        uint32_t i_selected_dram_voltage,
        uint32_t i_selected_dram_voltage_vpp)
{
    const auto  l_target_mcbist = find_target<fapi2::TARGET_TYPE_MCBIST>(i_target_mcs);

    FAPI_TRY(  FAPI_ATTR_SET(fapi2::ATTR_MSS_VOLT_VDDR, l_target_mcbist, i_selected_dram_voltage) );
    FAPI_TRY(  FAPI_ATTR_SET(fapi2::ATTR_MSS_VOLT_VPP, l_target_mcbist, i_selected_dram_voltage_vpp) );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Sets pre_eff_config attributes
/// @param[in] i_target the DIMM target
/// @param[in] i_spd_decoder SPD decoder
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode set_pre_init_attrs( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                      const spd::facade& i_spd_decoder )
{
    fapi2::ReturnCode l_rc(fapi2::FAPI2_RC_SUCCESS);
    mss::pre_data_engine<mss::NIMBUS> l_data_engine(i_target, i_spd_decoder, l_rc);
    FAPI_TRY(l_rc, "Failed to instantiate pre_data_engine object for %s", spd::c_str(i_target));

    // Set attributes needed before eff_config
    // DIMM type and DRAM gen are needed for c_str to aid debugging
    FAPI_TRY(l_data_engine.set_dimm_type(), "Failed to set DIMM type %s", spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_dram_gen(), "Failed to set DRAM gen %s", spd::c_str(i_target) );

    // Hybrid and hybrid media help detect hybrid modules, specifically NVDIMMs for Nimbus
    FAPI_TRY(l_data_engine.set_hybrid(), "Failed to set Hybrid %s", spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_hybrid_media(), "Failed to set Hybrid Media %s", spd::c_str(i_target) );

    // Number of master ranks needed for VPD decoding
    // and dimm_ranks_configured is a PRD attr...
    FAPI_TRY(l_data_engine.set_master_ranks(), "Failed to set Master ranks %s", spd::c_str(i_target) );
    FAPI_TRY(l_data_engine.set_dimm_ranks_configured(), "Failed to set DIMM ranks configured %s", spd::c_str(i_target) );

fapi_try_exit:
    return fapi2::current_err;
}

} // mss
