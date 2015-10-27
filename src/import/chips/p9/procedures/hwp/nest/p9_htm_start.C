/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_start.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// ----------------------------------------------------------------------------
/// @file  p9_htm_start.C
///
/// @brief Start the HTM collection from a processor chip
///
/// The purpose of this procedure is to start the HTM collection from a
/// processor chip.
///
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Owner    : Thi Tran <thi@us.ibm.com>
/// *HWP Team        : Nest
/// *HWP Level       : 1
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_htm_start.H>
#include <p9_htm_setup.H>
#include <p9_misc_scom_addresses.H>
#include <p9_quad_scom_addresses.H>

extern "C" {


///
/// @brief Start HTM collection
///
/// @param[in] i_target         Reference to Processor Chip target
/// @param[in] i_htmModeRegAddr The associated HTM Mode Register
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode startHTM(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint64_t i_htmModeRegAddr)
    {
        FAPI_INF("startHTM");
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_scomData(0);
        uint32_t l_htmPendingActionCount = 0;
        bool l_htmReady = false;

        // Verify HTM is in "Complete" state
        FAPI_TRY(fapi2::getScom(i_target, i_htmModeRegAddr + HTM_STAT, l_scomData),
                 "startHTM: getScom returns error (1): Addr "
                 "0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + HTM_STAT,
                 (uint64_t)fapi2::current_err);

        FAPI_ASSERT( (l_scomData & HTM_STAT_COMPLETE),
                     fapi2::PROC_HTM_CTRL_BAD_STATE()
                     .set_HTM_STATUS_REG(l_scomData)
                     .set_TARGET(i_target),
                     "startHTM: HTM is not in Complete state, can't reset "
                     "HTM_STAT 0x%016llX", l_scomData);


        // Trigger START
        l_scomData = 0;
        l_scomData.setBit<HTM_TRIG_RESET>();
        FAPI_TRY(fapi2::putScom(i_target, i_htmModeRegAddr + HTM_TRIG, l_scomData),
                 "startHTM: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 i_htmModeRegAddr + HTM_TRIG,
                 (uint64_t)fapi2::current_err);

        // Waiting for Ready state
        FAPI_INF("startHTM: Waiting for action to complete...");
        l_htmReady = false;

        while (l_htmPendingActionCount < PROC_HTM_CTRL_TIMEOUT_COUNT)
        {
            FAPI_TRY(fapi2::delay(PROC_HTM_CTRL_HW_NS_DELAY,
                                  PROC_HTM_CTRL_SIM_CYCLE_DELAY),
                     "startHTM: fapi delay returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // Check ready bit
            FAPI_TRY(fapi2::getScom(i_target, i_htmModeRegAddr + HTM_STAT, l_scomData),
                     "startHTM: getScom returns error (2): "
                     "Addr 0x%016llX, l_rc 0x%.8X",
                     i_htmModeRegAddr + HTM_STAT,
                     (uint64_t)fapi2::current_err);

            if (l_scomData & HTM_STAT_READY)
            {
                l_htmReady = true;
                FAPI_INF("startHTM: HTM is ready.");
                break;
            }

            // "Complete" is not asserted yet; increment timeout and check again
            l_htmPendingActionCount++;
        }

        // Error out if Ready state is not set
        FAPI_ASSERT( (l_htmReady == true), fapi2::PROC_HTM_CTRL_TIMEOUT()
                     .set_DELAY_COUNT(l_htmPendingActionCount)
                     .set_HTM_STATUS_REG(l_scomData),
                     "startHTM: Timeout waiting for Ready state, Count 0x%.8X, "
                     "HTM_STAT 0x%016llX", l_htmPendingActionCount, l_scomData );

    fapi_try_exit:
        return fapi2::current_err;
    }

///
/// @brief p9_htm_start procedure entry point
/// See doxygen in p9_htm_start.H
///
    fapi2::ReturnCode p9_htm_start(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering p9_htm_start");

        fapi2::ReturnCode l_rc;
        uint8_t l_nhtm_trace_type = 0;
        uint8_t l_chtm_trace_type = 0;
        auto l_modeRegList = std::vector<uint64_t>();


        // Get NTHM trace option
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target,
                               l_nhtm_trace_type),
                 "p9_htm_start: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Get CTHM trace option
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                               l_chtm_trace_type),
                 "p9_htm_start: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Display enabled HTM trace types
        FAPI_INF("p9_htm_start: NHTM type: 0x%.8X, CHTM type: 0x%.8X",
                 l_nhtm_trace_type, l_chtm_trace_type);

        // If no HTM trace collection is enabled, exit.
        if ( (l_nhtm_trace_type == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE) &&
             (l_chtm_trace_type == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE) )
        {
            FAPI_INF("p9_htm_start: HTM traces are disabled.");
            return l_rc;
        }

        // --------- Get the registers for Nest HTM ----------------------
        if (l_nhtm_trace_type != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            l_modeRegList.push_back(PU_HTM0_HTM_MODE);
            l_modeRegList.push_back(PU_HTM1_HTM_MODE);
        }

        // --------- Get the register for Core HTM ----------------------
        if (l_chtm_trace_type != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
        {
            l_modeRegList.push_back(EQ_HTM_MODE);
        }

        // --------- Start HTM ----------------------
        for (auto itr = l_modeRegList.begin(); itr != l_modeRegList.end();
             ++itr)
        {
            FAPI_TRY( startHTM(i_target, (*itr)),
                      "p9_htm_start: startHTM() returns error: Addr 0x%016llX, "
                      "l_rc 0x%.8X",
                      (*itr), (uint64_t)fapi2::current_err );
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p9_htm_start");
        return fapi2::current_err;
    }

} // extern "C"
