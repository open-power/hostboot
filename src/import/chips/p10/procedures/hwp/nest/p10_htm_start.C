/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_start.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file  p10_htm_start.C
///
/// @brief Start the HTM collection from a processor chip
///
/// The purpose of this procedure is to start the HTM collection from a
/// processor chip.
///
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Owner    : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_htm_start.H>
#include <p10_htm_def.H>
#include <p10_htm_adu_ctrl.H>
#include <p10_adu_constants.H>
#include <p10_scom_proc.H>
#include <p10_scom_c.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------
const uint8_t ADU_ADDRESS_HTM_START_BIT = 46;

///
/// @brief Start HTM collection
///
/// @param[in] i_target         Reference to target
/// @param[in] i_pos            Position of HTM engine to start
/// @param[in] i_traceType      Trace type
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode startHTM(const fapi2::Target<T>& i_target,
                           const uint8_t i_pos,
                           const uint8_t i_traceType);

/// TARGET_TYPE_PROC_CHIP (NHTM)
template<>
fapi2::ReturnCode startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_pos,
    const uint8_t i_traceType)
{
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint16_t l_htm_poll_count = 0;

    // Engines must be in ready or pause state
    FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

    FAPI_ASSERT( ( GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_READY(l_reg_data) ||
                   GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_PAUSED(l_reg_data)) &&
                 ( GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_READY(l_reg_data) ||
                   GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_PAUSED(l_reg_data)),
                 fapi2::P10_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_reg_data),
                 "startHTM: NHTM is not in Ready state, can't start "
                 "NHTM status 0x%016llX",
                 l_reg_data);

    // Note: Use global PMISC ADU start command to better synchronize
    //       the traces of NHTM0 and NHTM1
    FAPI_TRY(aduNHTMControl(i_target, PMISC_GLOBAL_HTM_START),
             "startHTM: aduNHTMControl returns error.");

    while (l_htm_poll_count < P10_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P10_HTM_CTRL_HW_NS_DELAY, P10_HTM_CTRL_SIM_CYCLE_DELAY),
                 "resetHTML fapi_delay returns an error, l_rc 0x%.8X", (uint64_t) fapi2::current_err);

        FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

        if (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_TRACING(l_reg_data) &&
            GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_TRACING(l_reg_data))
        {
            FAPI_INF("Both NHTMs have started");
            break;
        }
        else if (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_TRACING(l_reg_data))
        {
            FAPI_DBG("HTM0 has started, waiting for HTM1");
        }
        else if (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_TRACING(l_reg_data))
        {
            FAPI_DBG("HTM1 has started, waiting for HTM0");
        }

        l_htm_poll_count++;
    }

    FAPI_ASSERT(GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_TRACING(l_reg_data) &&
                GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_TRACING(l_reg_data) ,
                fapi2::P10_NHTM_CTRL_TIMEOUT()
                .set_TARGET(i_target)
                .set_DELAY_COUNT(l_htm_poll_count)
                .set_HTM_STATUS_REG(l_reg_data),
                "startHTM: at least one HTM is not in TRACING state");


fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// TARGET_TYPE_CORE (CHTM)
template<>
fapi2::ReturnCode startHTM(const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
                           const uint8_t i_pos,
                           const uint8_t i_traceType)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint32_t l_imaHTMEnable = 0b100000000; // Set bit 4 of HTM_MODE to enable IMA

    // IMA trace
    if (i_traceType == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
    {
        FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_MODE(i_target, l_reg_data));

        // Enable IMA capture
        SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CAPTURE(l_imaHTMEnable, l_reg_data);
        FAPI_INF("startHTM: HTM_MODE reg setup: 0x%016llX", l_reg_data);
        FAPI_TRY(PUT_NC_NCCHTM_NCCHTSC_HTM_MODE(i_target, l_reg_data));

        // Display HTM_IMA_STATUS reg value
        FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(i_target, l_reg_data));
        FAPI_INF("startHTM: HTM_IMA_STATUS: 0x%016llX", l_reg_data);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C" {

///
/// @brief p10_htm_start procedure entry point
/// See doxygen in p10_htm_start.H
///
    fapi2::ReturnCode p10_htm_start(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering");
        fapi2::ReturnCode l_rc;
        uint8_t l_nhtmType;
        uint8_t l_chtmType[NUM_CHTM_ENGINES];
        uint8_t l_corePos = 0;
        auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>();

        // Display attribute trace setup values
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target,
                               l_nhtmType),
                 "p10_htm_start: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_INF("p10_htm_start: NHTM type: 0x%.8X", l_nhtmType);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                               l_chtmType),
                 "p10_htm_start: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_INF("p10_htm_start: CHTM type:");

        for (uint8_t ii = 0; ii < NUM_CHTM_ENGINES; ii++)
        {
            FAPI_INF("              Core[%u] 0x%.8X", ii, l_chtmType[ii]);
        }

        // Start NHTM
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            // Start trace for NHTM
            // Note: We want to synch the trace for both NHTM engines as much
            //       as possible, so do not loop on individual engine
            //       here.  The startHTM function will check state and issue
            //       a global ADU command to start both engines.
            FAPI_TRY( startHTM(i_target, 0, l_nhtmType),
                      "p10_htm_start: startHTM() returns error NHTM"
                      "l_rc 0x%.8X", (uint64_t)fapi2::current_err );
        }

        // Start CHTM
        for (auto l_core : l_coreChiplets)
        {
            // Get the core position
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                     "Error getting ATTR_CHIP_UNIT_POS");

            if (l_chtmType[l_corePos] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
            {
                FAPI_DBG("Start HTM on core %u....", l_corePos);
                FAPI_TRY(startHTM(l_core, l_corePos, l_chtmType[l_corePos]),
                         "p10_htm_start: startHTM() returns error: CHTM %u, "
                         "l_rc 0x%.8X", l_corePos, (uint64_t)fapi2::current_err );
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
