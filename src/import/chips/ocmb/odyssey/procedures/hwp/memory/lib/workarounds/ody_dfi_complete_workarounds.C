/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/lib/workarounds/ody_dfi_complete_workarounds.C $ */
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
/// @file ody_dfi_complete_workarounds.C
/// @brief Odyssey workarounds for DFI initialization complete
///
// *HWP HWP Owner: Louis Stermole <stermole@us.ibm.com>
// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#include <fapi2.H>

#include <mss_generic_system_attribute_getters.H>

#include <lib/mc/ody_port.H>
#include <lib/workarounds/ody_dfi_complete_workarounds.H>
#include <ody_scom_ody_odc.H>

#include <generic/memory/lib/utils/c_str.H>
#include <generic/memory/lib/utils/mss_generic_check.H>

namespace mss
{
namespace ody
{
namespace workarounds
{

///
/// @brief Checks the DFI interface completion
/// @param[in] i_target the target to check for DFI interface completion
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode check_dfi_init( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    uint8_t l_is_sim = 0;
    uint8_t l_is_simics = 0;
    FAPI_TRY( mss::attr::get_is_simulation(l_is_sim) );
    FAPI_TRY( mss::attr::get_is_simics(l_is_simics) );

    FAPI_TRY(check_dfi_init_helper( i_target, l_is_sim, l_is_simics ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Checks the DFI interface completion - helper for unit testing
/// @param[in] i_target the target to check for DFI interface completion
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode check_dfi_init_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_simulation, const uint8_t i_is_simics )
{
    // Check if the workaround is needed
    if(is_simulation_dfi_init_workaround_needed( i_is_simulation, i_is_simics ))
    {
        FAPI_INF(TARGTIDFORMAT " Running the DFI workaround for simulation",
                 TARGTID);
        FAPI_TRY(complete_dfi_init_for_sim(i_target),
                 TARGTIDFORMAT " Failed DFI init workaround for simulation",
                 TARGTID);
    }
    else
    {
        // Check that the DFI init completed successfully
        FAPI_INF(TARGTIDFORMAT " Polling for DFI init complete",
                 TARGTID);
        FAPI_TRY(mss::ody::poll_for_dfi_init_complete(i_target),
                 TARGTIDFORMAT " Failed to poll_for_dfi_init_complete",
                 TARGTID );
    }

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Completes the DFI initialization for simulation
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode complete_dfi_init_for_sim( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    // Clear FARB0Q(55) to let commands flow on DFI interface without requiring DFI init to complete
    fapi2::buffer<uint64_t> l_farb0q;
    FAPI_TRY( fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_farb0q) );
    l_farb0q.clearBit<scomt::ody::ODC_SRQ_MBA_FARB0Q_CFG_WAIT_FOR_INIT_COMPLETE>();
    FAPI_TRY( fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB0Q, l_farb0q) );

fapi_try_exit:
    return fapi2::current_err;

}

///
/// @brief Checks the DFI init workaround is needed
/// @param[in] i_target the target to check for DFI interface completion
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
bool is_simulation_dfi_init_workaround_needed( const uint8_t i_is_simulation, const uint8_t i_is_simics )
{
    // If this is not a simulation environment, no workaround is needed
    if(!i_is_simulation)
    {
        return false;
    }

    // If this is a simulation environment, the workaround is only needed on the AWAN environment
    return i_is_simics == fapi2::ENUM_ATTR_IS_SIMICS_REALHW;
}

///
/// @brief Deasserts the reset_n pin if needed
/// @param[in] i_target the target on which to operate
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode deassert_resetn( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target )
{
    uint8_t l_is_sim = 0;
    uint8_t l_is_simics = 0;
    FAPI_TRY( mss::attr::get_is_simulation(l_is_sim) );
    FAPI_TRY( mss::attr::get_is_simics(l_is_simics) );

    FAPI_TRY(deassert_resetn_helper( i_target, l_is_sim, l_is_simics ));

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Deasserts the reset_n pin if needed
/// @param[in] i_target the target on which to operate
/// @param[in] i_is_simulation true if this is a simulation environment
/// @param[in] i_is_simics holds the simulation/simics environment type
/// @return FAPI2_RC_SUCCSS iff ok
///
fapi2::ReturnCode deassert_resetn_helper( const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
        const uint8_t i_is_simulation,
        const uint8_t i_is_simics )
{
    // Checks if the workaround is needed
    if(is_simulation_dfi_init_workaround_needed(i_is_simulation, i_is_simics))
    {
        fapi2::buffer<uint64_t> l_farb5q;
        FAPI_TRY( fapi2::getScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB5Q, l_farb5q) );
        l_farb5q.setBit<scomt::ody::ODC_SRQ_MBA_FARB5Q_CFG_DDR_RESETN>();
        FAPI_TRY( fapi2::putScom(i_target, scomt::ody::ODC_SRQ_MBA_FARB5Q, l_farb5q) );
    }

    return fapi2::FAPI2_RC_SUCCESS;
fapi_try_exit:
    return fapi2::current_err;

}

} // ns workarounds
} // ns ody
} // ns mss
