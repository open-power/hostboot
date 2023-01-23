/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/phy/ody_phy_reset.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2023                        */
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
/// @file ody_phy_reset.C
/// @brief Procedures to reset the Odyssey PHY
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: FSP:HB

#include <fapi2.H>

#include <generic/memory/lib/utils/find.H>
#include <generic/memory/lib/utils/pos.H>
#include <ody_phy_reset.H>
#include <lib/shared/ody_consts.H>
namespace mss
{
namespace ody
{
namespace phy
{
///
/// @brief Initiate the clocks and reset the PHY
/// @param[in] i_target the mem_port target on which to operate
/// @return FAPI2_RC_SUCCESS iff okay
///
fapi2::ReturnCode reset(const fapi2::Target<fapi2::TARGET_TYPE_MEM_PORT>& i_target)
{
    // 1. Drive PwrOkIn to 0. Note: Reset, DfiClk, and APBCLK can be X
    // 2. Start DfiClk and APBCLK
    // 3. Drive Reset to 1 and PRESETn_APB to 0.
    // Note: The combination of PwrOkIn=0 and Reset=1 signals a cold reset to the PHY.
    // 4. Wait a minimum of 16 clock cycles.
    // 5. Drive PwrOkIn to 1. Once the PwrOkIn is asserted (and Reset is still asserted),
    // Steps 1-5 are taken care of in pervasive ody_chiplet_startclocks() procedure.

    // Local buffer
    fapi2::buffer<uint64_t> l_buffer;

    // Registers to set and clear
    constexpr uint64_t CPLT_CONF1_REG_SET = 0x08000019;
    constexpr uint64_t CPLT_CONF1_REG_CLEAR = 0x08000029;

    const auto& l_ocmb = mss::find_target<fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Get the memport relative position
    // The relative_pos() only returns 0 or 1 for this type of function
    // to decide whether to use port0 or port1
    const uint32_t l_rel_pos =  mss::relative_pos<mss::mc_type::ODYSSEY, fapi2::TARGET_TYPE_OCMB_CHIP>(i_target);

    // Bits in the register for both port0 and port1
    const uint32_t CPLT_CONF1_DDR_RESET = l_rel_pos == 0 ? 2 : 3;
    const uint32_t CPLT_CONF1_DFICLK_RESET = l_rel_pos == 0 ? 10 : 11;
    const uint32_t CPLT_CONF1_DDR_APBRESETn = l_rel_pos == 0 ? 14 : 15;


    // 6. Wait a minimum of 128 clock cycles which is the reset period for phy
    // 1000 cyles are being added in pervasive procedure
    FAPI_TRY(fapi2::delay(600, 600));

    // 7. Drive Reset to 0 and DfiClkReset to 0 because the PUB databook says
    // Reset and DfiClkReset need to be asserted/deasserted together
    // Note: All DFI and APB inputs must be driven at valid reset states before the deassertion of Reset.
    FAPI_TRY(l_buffer.setBit(CPLT_CONF1_DDR_RESET));
    FAPI_TRY(l_buffer.setBit(CPLT_CONF1_DFICLK_RESET));
    FAPI_TRY(fapi2::putScom(l_ocmb, CPLT_CONF1_REG_CLEAR, l_buffer));
    l_buffer.flush<0>();

    // 8. Wait a minimum of 2 clock cycles.
    FAPI_TRY(fapi2::delay(24, 24));

    // 9. Drive PRESETn_APB to 1 to de-assert reset on the APB bus.
    FAPI_TRY(l_buffer.setBit(CPLT_CONF1_DDR_APBRESETn));
    FAPI_TRY(fapi2::putScom(l_ocmb, CPLT_CONF1_REG_SET, l_buffer));
    l_buffer.flush<0>();

    //10. Wait some cycles to allow the APB logic to initialize
    FAPI_TRY(fapi2::delay(400, 400));

    //The PHY is now in the reset state and is ready to accept APB transactions.


fapi_try_exit:
    return fapi2::current_err;

}
} // phy
} // ody
} // mss
