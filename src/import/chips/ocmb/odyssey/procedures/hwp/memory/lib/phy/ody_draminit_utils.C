/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_draminit_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022                             */
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
/// @file ody_draminit_utils.C
/// @brief Odyssey PHY draminit utility functions
///
// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/shared/mss_generic_consts.H>

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
#include <lib/phy/ody_draminit_utils.H>
#include <lib/phy/ody_phy_utils.H>

namespace mss
{
namespace ody
{
namespace phy
{

// TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
// For now using the Synopsys register location documentation
constexpr uint64_t MIRCORESET = 0x000d0099;
constexpr uint64_t CALZAP     = 0x00020089;

constexpr uint64_t MIRCORESET_STALLTOMICRO = 60;
constexpr uint64_t MIRCORESET_RESETTOMICRO = 63;

constexpr uint64_t CALZAP_CALZAP     = 63;

///
/// @brief Starts the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note Assumes that the firmware binaries and data structures are loaded appropriately
///
fapi2::ReturnCode start_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
    const uint64_t MIRCORESET_IBM = convert_synopsys_to_ibm_reg_addr(MIRCORESET);

    // Per the Synopsys documentation, to start the training, there is a latching sequence
    // 1. Configure the PHY to allow training access (wait 40 cycles)
    // 2. Reset and stall the processor (gets it into a base state but does not start it)
    // 3. Stall the processor (releases reset but does not start it)
    // 4. Start training (release stall/reset)
    fapi2::buffer<uint64_t> l_data;

    // 1. Configure the PHY to allow training access (wait 40 cycles after)
    // Note: OFF_N refers to scom access -> so this enables training access
    FAPI_TRY(configure_phy_scom_access(i_target, mss::states::OFF_N));
    // Note: pausing for 100 ns, which should be more than 40 cycles at Odyssey's min frequency
    FAPI_TRY( fapi2::delay( 100, 40) );

    // 2. Reset and stall the processor (gets it into a base state but does not start it)
    l_data.setBit<MIRCORESET_STALLTOMICRO>().setBit<MIRCORESET_RESETTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 3. Stall the processor (releases reset but does not start it)
    l_data.flush<0>().setBit<MIRCORESET_STALLTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 4. Start training (release stall/reset)
    l_data.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Cleans up from the firmware draminit training
/// @param[in] i_target the target on which to operate
/// @return fapi2::FAPI2_RC_SUCCESS iff successful
/// @note puts the processor into a stall state
///
fapi2::ReturnCode cleanup_training(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // TODO:ZEN:MST-1571 Update Odyssey PHY registers when the official values are merged into the EKB
    const uint64_t MIRCORESET_IBM = convert_synopsys_to_ibm_reg_addr(MIRCORESET);
    const uint64_t CALZAP_IBM = convert_synopsys_to_ibm_reg_addr(CALZAP);

    // Per the Synopsys documentation, to cleanup after the training:
    // 1. Stop the processor (stall it)
    // 2. Reset the calibration engines to their initial state (cal Zap!)
    fapi2::buffer<uint64_t> l_data;

    // 1. Stop the processor (stall it)
    l_data.setBit<MIRCORESET_STALLTOMICRO>();
    FAPI_TRY(fapi2::putScom(i_target, MIRCORESET_IBM, l_data));

    // 2. Reset the calibration engines to their initial state (cal Zap!)
    l_data.flush<0>().setBit<CALZAP_CALZAP>();
    FAPI_TRY(fapi2::putScom(i_target, CALZAP_IBM, l_data));

fapi_try_exit:
    return fapi2::current_err;
}

} // namespace phy
} // namespace ody
} // namespace mss
