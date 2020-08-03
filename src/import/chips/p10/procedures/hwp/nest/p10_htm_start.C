/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_start.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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

///
/// @brief precheck HTM
///
/// @param[in] i_target         Reference to target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode precheck_startHTM(const fapi2::Target<T>& i_target);

/// TARGET_TYPE_PROC_CHIP (NHTM)
template<>
fapi2::ReturnCode precheck_startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);

    // Verify NHTMs are in expected states
    FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

    FAPI_ASSERT( (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_READY(l_reg_data) ||
                  GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_PAUSED(l_reg_data) ) &&
                 (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_READY(l_reg_data) ||
                  GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_PAUSED(l_reg_data) ),
                 fapi2::P10_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_reg_data),
                 "startHTM: NHTM is not in READY/PAUSE state, can't stop "
                 "NHTM0 status 0x%016llX",
                 l_reg_data);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// TARGET_TYPE_PROC_CHIP (CHTM)
template<>
fapi2::ReturnCode precheck_startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    fapi2::ATTR_CHIP_UNIT_POS_Type l_corePos = 0;

    // Get core pos to display if we get an error for some reason
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_corePos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // Verify CHTM is in expected state
    FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_STAT(i_target, l_reg_data));

    FAPI_ASSERT( GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_READY(l_reg_data) ||
                 GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_PAUSED(l_reg_data)    ,
                 fapi2::P10_CHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_reg_data),
                 "startHTM: CHTM is not in READY/PAUSED state, can't start "
                 "CHTM status 0x%016llX\n"
                 "core number %u",
                 l_reg_data, l_corePos);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

/// TARGET_TYPE_CORE(CHTM)
fapi2::ReturnCode precheck_startIMA(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    fapi2::ATTR_CHIP_UNIT_POS_Type l_corePos = 0;

    // Get core pos to display if we get an error for some reason
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_corePos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // Verify CHTM is in expected state
    FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(i_target, l_reg_data));

    // IMA FSM is one-hot status. Bits:
    // IMA_STATUS 5:11
    // 01 Disabled
    // 02 Idle
    // 04 Clear
    // 08 Capture
    // 10 Write LDBAR
    // 20 Write PDBAR
    // 40 Error
    FAPI_ASSERT( l_reg_data.getBit(P10_IMA_STATUS_DISABLED)    ,
                 fapi2::P10_CHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_reg_data),
                 "startHTM: IMA CHTM is not in DISABLED state, can't start"
                 "CHTM status 0x%016llX\n"
                 "core number %u",
                 l_reg_data, l_corePos);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief postcheck HTM
///
/// @param[in] i_target         Reference to target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode postcheck_startHTM(const fapi2::Target<T>& i_target);

/// TARGET_TYPE_PROC_CHIP (NHTM)
template<>
fapi2::ReturnCode postcheck_startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint16_t l_htm_poll_count = 0;

    while (l_htm_poll_count < P10_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P10_HTM_CTRL_HW_NS_DELAY, P10_HTM_CTRL_SIM_CYCLE_DELAY),
                 "startHTM fapi_delay returns an error, l_rc 0x%.8X", (uint64_t) fapi2::current_err);

        FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_reg_data));

        if (GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_TRACING(l_reg_data) &&
            GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_TRACING(l_reg_data))
        {
            FAPI_INF("NHTMs are in TRACING state, %u", l_htm_poll_count);
            break;
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

template<>
fapi2::ReturnCode postcheck_startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint16_t l_htm_poll_count = 0;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_corePos = 0;

    // Get core pos to display if we get an error for some reason
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_corePos),
             "Error getting ATTR_CHIP_UNIT_POS");

    while (l_htm_poll_count < P10_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P10_HTM_CTRL_HW_NS_DELAY, P10_HTM_CTRL_SIM_CYCLE_DELAY),
                 "startHTM fapi_delay returns an error, l_rc 0x%.8X", (uint64_t) fapi2::current_err);

        FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_STAT(i_target, l_reg_data));

        if (GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_TRACING(l_reg_data))
        {
            FAPI_INF("cHTM in TRACING state, %u", l_htm_poll_count);
            break;
        }

        l_htm_poll_count++;
    }

    FAPI_ASSERT(GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_TRACING(l_reg_data),
                fapi2::P10_CHTM_CTRL_TIMEOUT()
                .set_TARGET(i_target)
                .set_DELAY_COUNT(l_htm_poll_count)
                .set_HTM_STATUS_REG(l_reg_data),
                "startHTM: cHTM %u is not in TRACING state", l_corePos);


fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

fapi2::ReturnCode postcheck_startIMA(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);
    uint16_t l_htm_poll_count = 0;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_corePos = 0;

    // Get core pos to display if we get an error for some reason
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_corePos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // IMA FSM is one-hot status. Bits:
    // IMA_STATUS 5:11
    // 01 Disabled
    // 02 Idle
    // 04 Clear
    // 08 Capture
    // 10 Write LDBAR
    // 20 Write PDBAR
    // 40 Error
    while (l_htm_poll_count < P10_HTM_CTRL_TIMEOUT_COUNT)
    {
        FAPI_TRY(fapi2::delay(P10_HTM_CTRL_HW_NS_DELAY, P10_HTM_CTRL_SIM_CYCLE_DELAY),
                 "startHTM fapi_delay returns an error, l_rc 0x%.8X", (uint64_t) fapi2::current_err);

        FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_IMA_STATUS(i_target, l_reg_data));

        if (l_reg_data.getBit(P10_IMA_STATUS_CAPTURE)  ||
            l_reg_data.getBit(P10_IMA_STATUS_WR_LDBAR) ||
            l_reg_data.getBit(P10_IMA_STATUS_WR_PDBAR) ||
            l_reg_data.getBit(P10_IMA_STATUS_IDLE)      )
        {
            FAPI_INF("cHTM in CAPTURE/WR_LDBAR/WR_PDBAR/IDLE state, %u", l_htm_poll_count);
            break;
        }

        l_htm_poll_count++;
    }

    FAPI_ASSERT(l_reg_data.getBit(P10_IMA_STATUS_CAPTURE)  ||
                l_reg_data.getBit(P10_IMA_STATUS_WR_LDBAR) ||
                l_reg_data.getBit(P10_IMA_STATUS_WR_PDBAR) ||
                l_reg_data.getBit(P10_IMA_STATUS_IDLE)      ,
                fapi2::P10_CHTM_CTRL_TIMEOUT()
                .set_TARGET(i_target)
                .set_DELAY_COUNT(l_htm_poll_count)
                .set_HTM_STATUS_REG(l_reg_data),
                "startHTM: IMA cHTM %u is not in CAPTURE/WR_LDBAR/WR_PDBAR/IDLE state", l_corePos);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

// Configure HID register with one_ppc and insutruc_trace so that ITCM (core trace) will work
// Must be done AFTER HTM has started
fapi2::ReturnCode setup_ITCM(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);

    // Setup HID for single core, single thread, single instruction mode
    FAPI_TRY(GET_EC_PC_PMU_SPRCOR_HID(i_target, l_reg_data));
    SET_EC_PC_PMU_SPRCOR_HID_ONE_PPC(l_reg_data);
    SET_EC_PC_PMU_SPRCOR_HID_EN_INSTRUC_TRACE(l_reg_data);
    FAPI_TRY(PUT_EC_PC_PMU_SPRCOR_HID(i_target, l_reg_data));

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Start HTM collection
///
/// @param[in] i_target         Reference to target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode startHTM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");

    // Note: Use global PMISC ADU start command to better synchronize
    //       the traces of NHTM0 and NHTM1
    FAPI_TRY(aduNHTMControl(i_target, PMISC_GLOBAL_HTM_START),
             "startHTM: aduNHTMControl returns error.");

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Start IMA collection
///
/// @param[in] i_target         Reference to target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode startIMA(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_reg_data(0);

    FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_MODE(i_target, l_reg_data));
    SET_P10_20_NC_NCCHTM_NCCHTSC_HTM_MODE_IMA_TRACE_ENABLE(l_reg_data);

    FAPI_TRY(PUT_NC_NCCHTM_NCCHTSC_HTM_MODE(i_target, l_reg_data));

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
        bool l_issue_command = false;

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
            if (l_chtmType[l_corePos] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
            {
                FAPI_INF("              Core[%u] 0x%.8X", ii, l_chtmType[ii]);
            }
        }

        // check if HTMs are ready to receive control command requested
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            FAPI_TRY(precheck_startHTM(i_target));
            l_issue_command = true;
        }

        for (auto l_core : l_coreChiplets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                     "Error getting ATTR_CHIP_UNIT_POS");

            if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
            {
                FAPI_TRY(precheck_startIMA(l_core));
                continue;
            }
            else if (l_chtmType[l_corePos] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
            {
                FAPI_TRY(precheck_startHTM(l_core));
                l_issue_command = true;
            }
        }

        // Issue single pMisc command to control the HTMs
        if (l_issue_command)
        {
            FAPI_TRY(startHTM(i_target));
        }

        // Start IMA trace types on cores requested
        for (auto l_core : l_coreChiplets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                     "Error getting ATTR_CHIP_UNIT_POS");

            if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
            {
                FAPI_TRY(startIMA(l_core));
            }
        }

        // check if HTMs reached desired state, if trace type requested
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            FAPI_TRY(postcheck_startHTM(i_target));
        }

        for (auto l_core : l_coreChiplets)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                     "Error getting ATTR_CHIP_UNIT_POS");

            if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
            {
                FAPI_TRY(postcheck_startIMA(l_core));
                continue;
            }
            else if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_CORE)
            {
                FAPI_TRY(setup_ITCM(l_core));
            }

            if (l_chtmType[l_corePos] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
            {
                FAPI_TRY(postcheck_startHTM(l_core));
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
