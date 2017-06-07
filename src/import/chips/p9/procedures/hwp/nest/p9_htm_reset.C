/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_htm_reset.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_htm_reset.C
///
/// @brief Reset the HTM engines on a processor chip
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 3
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_htm_reset.H>
#include <p9_htm_def.H>
#include <p9_htm_adu_ctrl.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
// ADU PMISC address bit definition
const uint8_t ADU_ADDRESS_HTM_RESET_BIT = 49;

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
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomData_2(0);
    uint32_t l_htmPendingActionCount = 0;

    // Verify NHTMs are in "Complete" state
    // NHTM0
    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[0] + HTM_STAT, l_scomData),
             "resetHTM: getScom returns error: Addr "
             "0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_STAT,
             (uint64_t)fapi2::current_err);
    // NHTM1
    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[1] + HTM_STAT, l_scomData_2),
             "resetHTM: getScom returns error: Addr "
             "0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_STAT,
             (uint64_t)fapi2::current_err);

    FAPI_ASSERT( l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_COMPLETE>() &&
                 l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_COMPLETE>(),
                 fapi2::P9_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG_NHTM0(l_scomData)
                 .set_HTM_STATUS_REG_NHTM1(l_scomData_2),
                 "resetHTM: NHTM is not in Complete state, can't reset "
                 "NHTM0 status 0x%016llX, NHTM1 status 0x%016llX",
                 l_scomData, l_scomData_2);

    // Reset
    l_scomData = 0;
    l_scomData.flush<0>().setBit<PU_HTM0_HTM_TRIG_HTMSC_RESET>();
    FAPI_INF("resetHTM: HTM_TRIG reg reset NHTM: 0x%016llX", l_scomData);
    FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[0] + HTM_TRIG, l_scomData),
             "resetHTM: putScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_TRIG,
             (uint64_t)fapi2::current_err);
    FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[1] + HTM_TRIG, l_scomData),
             "resetHTM: putScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_TRIG,
             (uint64_t)fapi2::current_err);

    l_htmPendingActionCount = 0;
    FAPI_INF("resetHTM: Waiting for NHTM Ready bit on NHTMs...", i_pos);

    while (l_htmPendingActionCount < P9_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P9_HTM_CTRL_HW_NS_DELAY,
                              P9_HTM_CTRL_SIM_CYCLE_DELAY),
                 "resetHTM: fapi delay returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Check ready bit
        FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[0] + HTM_STAT, l_scomData),
                 "resetHTM: getScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_STAT,
                 (uint64_t)fapi2::current_err);

        FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[1] + HTM_STAT, l_scomData_2),
                 "resetHTM: getScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_STAT,
                 (uint64_t)fapi2::current_err);

        if ( l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_READY>() &&
             l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_READY>() )
        {
            FAPI_INF("resetHTM: NHTM status = Ready on both NHTMs.");
            break;
        }

        // "Ready" is not asserted yet; increment timeout and check again
        l_htmPendingActionCount++;
    }

    // Error out if Ready bit is not set after reset
    FAPI_ASSERT( (l_htmPendingActionCount < P9_HTM_CTRL_TIMEOUT_COUNT),
                 fapi2::P9_NHTM_CTRL_TIMEOUT()
                 .set_TARGET(i_target)
                 .set_DELAY_COUNT(l_htmPendingActionCount)
                 .set_HTM_STATUS_REG_NHTM0(l_scomData)
                 .set_HTM_STATUS_REG_NHTM1(l_scomData_2),
                 "resetHTM: Timeout waiting for Ready bit after reset, Count 0x%.8X, "
                 "NHTM0 status 0x%016llX, NHTM1 status 0x%016llX",
                 l_htmPendingActionCount, l_scomData, l_scomData_2);

#if 0
    // Note:
    // Save this code in case we want to perform reset via ADU
    // Build address value
    l_scomData.flush<0>().setBit<ADU_ADDRESS_HTM_RESET_BIT>();

    // Reset global trigger on the NHTM engines
    FAPI_TRY(aduNHTMControl(i_target, l_scomData),
             "resetHTM: aduNHTMControl returns error.");
#endif

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

extern "C" {

///
/// @brief p9_htm_reset procedure entry point
/// See doxygen in p9_htm_reset.H
///
    fapi2::ReturnCode p9_htm_reset(
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
                 "p9_htm_reset: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get ATTR_CHTM_TRACE_TYPE
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                               l_chtmType),
                 "p9_htm_reset: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Reset NHTM trace
        // Note: reset NHTM0 will also reset NHTM1 in global mode
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            FAPI_TRY( resetHTM(i_target, 0),
                      "p9_htm_reset: resetHTM() returns error NHTM"
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
                         "p9_htm_reset: resetHTM() returns error: CHTM %u, "
                         "l_rc 0x%.8X", l_corePos, (uint64_t)fapi2::current_err );
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
