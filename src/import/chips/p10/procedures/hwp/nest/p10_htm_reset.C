/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_reset.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2019                        */
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
/// ----------------------------------------------------------------------------
/// @file  p10_htm_reset.C
///
/// @brief Reset the HTM engines on a processor chip
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Owner    : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_htm_reset.H>
#include <p10_htm_def.H>
#include <p10_scom_proc.H>
#include <p10_htm_adu_ctrl.H>

///
/// @brief Reset HTM
///
/// @param[in] i_target         Reference to target
/// @param[in] i_pos            Position of HTM engine to reset
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode resetHTM(const fapi2::Target<T>& i_target,
                           const uint8_t i_pos);

/// TARGET_TYPE_PROC_CHIP (NHTM)
template<>
fapi2::ReturnCode resetHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_pos)
{
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint16_t l_htm_poll_count = 0;

    // Verify NHTMs are in "Complete" state
    // NHTM
    FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

    FAPI_ASSERT( GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_COMPLETE(l_reg_data) &&
                 GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_COMPLETE(l_reg_data),
                 fapi2::P10_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_reg_data),
                 "resetHTM: NHTM is not in Complete state, can't reset "
                 "NHTM status 0x%016llX",
                 l_reg_data);

    // Reset
    FAPI_TRY(aduNHTMControl(i_target, PMISC_GLOBAL_HTM_RESET),
             "resetHTM: aduNHTMControl returns an error");

    while (l_htm_poll_count < P10_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P10_HTM_CTRL_HW_NS_DELAY, P10_HTM_CTRL_SIM_CYCLE_DELAY),
                 "resetHTML fapi_delay returns an error, l_rc 0x%.8X", (uint64_t) fapi2::current_err);

        FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

        if (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_READY(l_reg_data) &&
            GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_READY(l_reg_data))
        {
            FAPI_INF("NHTMs are in ready state", l_htm_poll_count);
            break;
        }

        l_htm_poll_count++;
    }

    FAPI_ASSERT(GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_READY(l_reg_data) &&
                GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_READY(l_reg_data) ,
                fapi2::P10_NHTM_CTRL_TIMEOUT()
                .set_TARGET(i_target)
                .set_DELAY_COUNT(l_htm_poll_count)
                .set_HTM_STATUS_REG(l_reg_data),
                "resetHTM: at least one HTM is not in READY state");

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// TARGET_TYPE_CORE (CHTM)
template<>
fapi2::ReturnCode resetHTM(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                           const uint8_t i_pos)

{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // Place holder to reset IMA trace.

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief p10_htm_reset procedure entry point
/// See doxygen in p10_htm_reset.H
///
fapi2::ReturnCode p10_htm_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    uint8_t l_corePos = 0;
    auto l_modeRegList = std::vector<uint64_t>();
    auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>();

    uint8_t l_nhtmType;
    uint8_t l_chtmType[NUM_CHTM_ENGINES];

    // Get ATTR_NHTM_TRACE_TYPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target, l_nhtmType),
             "p10_htm_reset: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Get ATTR_CHTM_TRACE_TYPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                           l_chtmType),
             "p10_htm_reset: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Reset NHTM trace
    // Note: reset NHTM0 will also reset NHTM1 in global mode
    if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
    {
        FAPI_TRY( resetHTM(i_target, 0),
                  "p10_htm_reset: resetHTM() returns error NHTM"
                  "l_rc 0x%.8X", (uint64_t)fapi2::current_err );
    }

    // Reset CHTM
    for (auto l_core : l_coreChiplets)
    {
        // Get the core position
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                 "Error getting ATTR_CHIP_UNIT_POS");
        FAPI_DBG("Reset HTM on core %u....", l_corePos);

        if (l_chtmType[l_corePos] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
        {
            FAPI_TRY(resetHTM(l_core, l_corePos),
                     "p10_htm_reset: resetHTM() returns error: CHTM %u, "
                     "l_rc 0x%.8X", l_corePos, (uint64_t)fapi2::current_err );
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}
