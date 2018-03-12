/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_secure_boot.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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
/// @file p9c_mss_secure_boot.C
/// @brief  Sets up secure mode boot and checks that it is setup properly
///
/// *HWP HWP Owner: Luke Mulkey <lwmulkey@us.ibm.com>
/// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB:CI
///

//------------------------------------------------------------------------------
//  Includes
//-------------------------------------
#include <p9c_mss_secure_boot.H>
#include <cen_gen_scom_addresses.H>
#include <cen_gen_scom_addresses_fld.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{
    ///
    /// @brief Enables secure mode boot
    /// @param[in]  i_target  Reference to target
    /// @return FAPI2_RC_SUCCESS iff successful
    /// @note Calls mss::c_str which is NOT thread safe unless the platform supports thread local storage...
    ///
    fapi2::ReturnCode p9c_mss_secure_boot( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target )
    {
        // Sets up secure mode
        FAPI_TRY(mss::setup_secure_mode_boot(i_target));

        // Verifies that we're in secure mode
        FAPI_TRY(mss::verify_secure_mode_boot_on(i_target));

        // Note: the workbook says we should check the clocks
        // Granted this procedure should be called after memory ECC is all setup
        // Therefore, clocks should be on, so we're going to skip this portion of the test

        // TK add in setup of secure mode boot FIRs - currently awaiting values from the RAS team

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"

namespace mss
{

//------------------------------------------------------------------------------
// Constants and enums
//------------------------------------------------------------------------------

// Vector of registers for enabling/checking secure mode
static const std::vector<uint64_t> REGISTERS =
{
    CEN_TCN_SYNC_CONFIG_PCB,
    CEN_TCM_SYNC_CONFIG_PCB,
};

///
/// @brief Enables secure mode boot
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode setup_secure_mode_boot( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target )
{
    // Loops through all registers and sets up secure mode boot
    for(const auto l_reg : REGISTERS)
    {
        fapi2::buffer<uint64_t> l_data;
        FAPI_TRY(fapi2::getScom(i_target, l_reg, l_data));
        l_data.setBit<CEN_TCN_SYNC_CONFIG_CHIP_PROTECTION_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target, l_reg, l_data));
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Verifies secure mode boot is in a given position for a given register
/// @param[in]  i_target  Reference to target
/// @param[in]  i_register the register to check
/// @param[in]  i_state boolean for the registers bit state
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode verify_secure_mode_boot( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target,
        const uint64_t i_register,
        const bool i_state )
{
    fapi2::buffer<uint64_t> l_data;
    FAPI_TRY(fapi2::getScom(i_target, i_register, l_data));
    FAPI_ASSERT(l_data.getBit<CEN_TCN_SYNC_CONFIG_CHIP_PROTECTION_ENABLE>() == i_state,
                fapi2::MSS_SECURE_BOOT_BAD_VALUE()
                .set_TARGET(i_target)
                .set_EXPECTED_LEVEL(i_state)
                .set_ACTUAL_LEVEL(l_data.getBit<CEN_TCN_SYNC_CONFIG_CHIP_PROTECTION_ENABLE>())
                .set_REGISTER(i_register),
                "%s secure mode boot on register 0x%016lx is at level %d should be at %d",
                mss::c_str(i_target), i_register, l_data.getBit<CEN_TCN_SYNC_CONFIG_CHIP_PROTECTION_ENABLE>(), i_state);

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Verifies secure mode boot is on
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode verify_secure_mode_boot_on( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target )
{
    // Loops through all registers and checks that secure mode boot is on
    for(const auto l_reg : REGISTERS)
    {
        FAPI_TRY(verify_secure_mode_boot(i_target, l_reg, true))
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Verifies secure mode boot is off
/// @param[in]  i_target  Reference to target
/// @return FAPI2_RC_SUCCESS iff successful
///
fapi2::ReturnCode verify_secure_mode_boot_off( const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& i_target )
{
    // Loops through all registers and checks that secure mode boot is on
    for(const auto l_reg : REGISTERS)
    {
        FAPI_TRY(verify_secure_mode_boot(i_target, l_reg, false))
    }

fapi_try_exit:
    return fapi2::current_err;
}

}
