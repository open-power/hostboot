/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/lib/workarounds/exp_omi_workarounds.C $ */
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
/// @file exp_omi_workarounds.C
/// @brief Workarounds for exp_omi_* procedures
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: Memory

#include <fapi2.H>
#include <generic/memory/lib/utils/find.H>
#include <lib/workarounds/exp_omi_workarounds.H>
#include <lib/shared/exp_consts.H>
#include <lib/omi/exp_omi_utils.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/mss_generic_system_attribute_getters.H>
#include <lib/inband/exp_inband.H>
#include <exp_oc_regs.H>

namespace mss
{
namespace exp
{
namespace workarounds
{
namespace omi
{

///
/// @brief Determine if we need to bypass MENTERP register reads/writes
///
/// @param[in] i_target OCMB chip
/// @param[out] o_workaround true (1) for gemini, else false (0)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
fapi2::ReturnCode gem_menterp(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> i_target,
                              uint8_t& o_workaround)
{
    o_workaround = 0;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_GEMINI_MENTERP_WORKAROUND, i_target, o_workaround),
             "Error getting ATTR_CHIP_EC_FEATURE_GEMINI_MENTERP_WORKAROUND");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Determine if / perform the gemini workaround to setup the OMI config registers
///
/// @param[in] i_target OCMB (gemini)
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error
/// @note Gemini workaround to setup METADATA and TEMPLATE bits before doing reads
///
fapi2::ReturnCode gem_setup_config(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    uint8_t l_gemini_config_workaround = 0;

    // Check if gemini workaround should be performed
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_GEMINI_OMI_SETUP_CONFIG_WORKAROUND, i_target,
                           l_gemini_config_workaround),
             "Error getting ATTR_CHIP_EC_FEATURE_GEMINI_OMI_SETUP_CONFIG_WORKAROUND");

    if (l_gemini_config_workaround)
    {
        // Set metadata bits
        fapi2::buffer<uint32_t> l_value;
        l_value.setBit<EXPLR_OC_OCTRLPID_MSB_METADATA_SUPPORTED>();
        l_value.setBit<EXPLR_OC_OCTRLPID_MSB_METADATA_ENABLED>();
        FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OCTRLPID_MSB, l_value));

        // Set template bits
        l_value.flush<0>();
        l_value.setBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_0>();
        l_value.setBit<EXPLR_OC_OTTCFG_MSB_TEMPLATE_5>();
        FAPI_TRY(mss::exp::ib::putOCCfg(i_target, EXPLR_OC_OTTCFG_MSB, l_value));
    }

fapi_try_exit:
    return fapi2::current_err;
}

} // omi
} // workarounds
} // exp
} // mss
