/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_rcw_workarounds.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
// EKB-Mirror-To: hostboot

///
/// @file exp_rcw_workarounds.H
/// @brief RCW related workarounds for explorer
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <lib/shared/exp_consts.H>
#include <lib/ccs/ccs_traits_explorer.H>
#include <lib/ccs/ccs_explorer.H>
#include <lib/workarounds/exp_rcw_workarounds.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/dimm/ddr4/mrs_load_ddr4.H>
#include <generic/memory/lib/dimm/ddr4/control_word_ddr4.H>
#include <generic/memory/lib/utils/dimm/mss_ddr4_timing.H>

namespace mss
{
namespace exp
{
namespace workarounds
{

///
/// @brief Helper function to get F0RC08 value for RCD parity enable on planar RDIMM
/// @param[in] i_target the DIMM on which to operate
/// @param[out] o_value value to be used for RCW data
/// @return FAPI2_RC_SUCCESS
///
fapi2::ReturnCode f0rc08_helper(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                uint8_t& o_value)
{
    bool l_is_a17_needed = false;

    FAPI_TRY(mss::is_a17_needed<mss::mc_type::EXPLORER>(i_target, l_is_a17_needed));

    // TODO Zen:MST-2369 Add support for 3DS if necessary (QxC enables)
    // Bits DA[3:0] taken from RCD spec JESD82-31A
    // 3 : 1/0 = DA17 Input Buffer and QxA17 outputs disabled(1)/enabled(0)
    // 2 : 0 = QxPAR outputs enabled
    // 1:0 : b11 = QxC[2:0] outputs disabled
    o_value = l_is_a17_needed ? 0x03 : 0x0B;

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable RCD parity checking using RCWs
/// @param[in] i_target port target on which to operate
/// @param[out] o_inst a vector of CCS instructions we should add to
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode setup_rcd_parity_rcws(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target,
                                        std::vector< ccs::instruction_t<mss::mc_type::EXPLORER> >& o_inst)
{
    constexpr uint8_t FUNCTION_SPACE_0 = 0;

    // Bits DA[3:0] taken from RCD spec JESD82-31A
    // 3 : 1 = Parity checking is re-enabled after ALERT_n pulse
    // 2 : 1 = ALERT_n pulse width according to DIMM frequency
    // 1 : 0 = NV Mode enable cannot be modified
    // 0 : 1 = Parity checking enabled
    const uint8_t F0RC0E_VALUE = 0x0D;

    // Bits DA[3:0] taken from RCD spec JESD82-31A
    // 1 = 2nCK latency adder to Qn, QxCSn, QxCKEn, QxODTn. 1nCK latency adder to QxPAR
    const uint8_t F0RC0F_VALUE = 0x01;

    uint8_t l_f0rc08_value = 0;
    fapi2::ReturnCode l_rc = f0rc08_helper(i_target, l_f0rc08_value);

    const std::vector<std::pair<uint8_t, uint8_t>> RCWS =
    {
        {0x08, l_f0rc08_value},
        {0x0e, F0RC0E_VALUE},
        {0x0f, F0RC0F_VALUE},
    };

    uint8_t l_sim = 0;

    // Check the RC from f0rc08_helper
    FAPI_TRY(l_rc, "%s Failed running f0rc08_helper", mss::c_str(i_target));

    FAPI_TRY(mss::attr::get_is_simulation(l_sim));

    o_inst.clear();

    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        for (const auto& l_rcw : RCWS)
        {
            mss::cw_info l_info(FUNCTION_SPACE_0,   // function space
                                l_rcw.first,        // RCW number
                                l_rcw.second,       // RCW value
                                mss::ddr4::tmrc(),  // Delay
                                mss::CW4_DATA_LEN,  // Data length
                                mss::cw_info::RCW); // is an RCW

            FAPI_TRY(mss::decode_rcw_and_run_engine<mss::mc_type::EXPLORER>(l_dimm,
                     l_sim,
                     l_info,
                     o_inst));
        }
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Enable RCD parity checking using RCWs
/// @param[in] i_target ocmb_chip target on which to operate
/// @param[in] i_is_planar value of ATTR_MEM_MRW_IS_PLANAR
/// @param[in] i_has_rcd true if this target has an RCD
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
fapi2::ReturnCode planar_enable_rcd_parity(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_planar,
        const bool i_has_rcd)
{
    // Exit if we're not planar and RDIMM
    if (!i_has_rcd || i_is_planar != fapi2::ENUM_ATTR_MEM_MRW_IS_PLANAR_TRUE)
    {
        return fapi2::FAPI2_RC_SUCCESS;
    }

    for (const auto& l_port : mss::find_targets<fapi2::TARGET_TYPE_MEM_PORT>(i_target))
    {
        mss::ccs::program<mss::mc_type::EXPLORER> l_program;
        FAPI_TRY(setup_rcd_parity_rcws(l_port, l_program.iv_instructions));

        // Loops through and ensures that the CKE are toggled to all be on
        for (auto& l_inst : l_program.iv_instructions)
        {
            l_inst.arr0.insertFromRight<EXPLR_MCBIST_CCS_INST_ARR0_00_DDR_CKE, EXPLR_MCBIST_CCS_INST_ARR0_00_DDR_CKE_LEN>(0xf);
        }

        // Issues the CCS instructions
        FAPI_TRY(mss::ccs::execute(i_target, l_program, l_port));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // workarounds
} // exp
} // mss
