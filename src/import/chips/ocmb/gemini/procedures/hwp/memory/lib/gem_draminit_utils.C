/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/gemini/procedures/hwp/memory/lib/gem_draminit_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file gem_draminit_utils.C
/// @brief Procedure definition to initialize DRAM
///
// *HWP HWP Owner: Mark Pizzutillo <Mark.Pizzutillo@ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/poll.H>
#include <mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/count_dimm.H>
#include <mss_generic_attribute_setters.H>
#include <lib/gem_draminit_utils.H>

namespace mss
{
namespace gem
{

///
/// @brief Checks that DIMM sizes are 32GB
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode gem_draminit_check_memory_size(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    if (mss::count_dimm(i_target) == 0)
    {
        FAPI_INF("NO DIMM on %s", mss::spd::c_str(i_target));
        return fapi2::FAPI2_RC_SUCCESS;
    }

    uint32_t l_dimm_size = 0;

    constexpr uint32_t MEMORY_SIZE = 32; // GB

    // Verify 32GB memory size for each DIMM.
    for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(i_target))
    {
        //Function get_dimm_size returns in GB
        FAPI_TRY(mss::attr::get_dimm_size(l_dimm, l_dimm_size), "Failed get_dimm_size() for %s", mss::spd::c_str(i_target));

        FAPI_ASSERT(l_dimm_size == MEMORY_SIZE, fapi2::MSS_GEM_DRAMINIT_DIMM_SIZE_DOESNT_MATCH()
                    .set_TARGET(i_target)
                    .set_DIMM(l_dimm)
                    .set_SIZE_RETURNED(l_dimm_size), "Invalid DIMM size. Received size (%lu) for target DIMM %s", l_dimm_size,
                    mss::spd::c_str(l_dimm));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Polls DRAM calibration register to check for complete
/// @param[in] i_target the controller
/// @return FAPI2_RC_SUCCESS iff ok
///
fapi2::ReturnCode gem_draminit_poll_check_calibration(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    // Address defined here as gemini SCOM address library does not exist
    constexpr uint64_t GEMINI_CALIBRATION_STATUS_ADDR = 0x08012428;
    const uint64_t GEMINI_CALIBRATION_STATUS_BIT_1 = 0x0;
    const uint64_t GEMINI_CALIBRATION_STATUS_BIT_2 = 0x1;

    // Using default parameters
    mss::poll_parameters l_poll_params;

    fapi2::buffer<uint64_t> l_data_buffer;

    bool l_poll_success =
        mss::poll(i_target, GEMINI_CALIBRATION_STATUS_ADDR, l_poll_params,
                  [&l_data_buffer](const size_t poll_remaining, const fapi2::buffer<uint64_t>& stat_reg) -> bool
    {
        FAPI_DBG("Polling: Gemini calibration status 0x%llx, remaining: %d", stat_reg, poll_remaining);
        l_data_buffer = stat_reg;

        return l_data_buffer.getBit<GEMINI_CALIBRATION_STATUS_BIT_1>()
        && l_data_buffer.getBit<GEMINI_CALIBRATION_STATUS_BIT_2>();
    });

    FAPI_ASSERT(l_poll_success == true,
                fapi2::MSS_GEM_DRAMINIT_CALIBRATION_DID_NOT_COMPLETE()
                .set_OCMB_TARGET(i_target)
                .set_TARGET(i_target)
                .set_REGISTER(GEMINI_CALIBRATION_STATUS_ADDR), "Calibration did not complete for target %s",
                mss::spd::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;

}

}// exp
}// mss
