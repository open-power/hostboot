/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_start.C $                 */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
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
/// *HWP Level       : 2
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_htm_start.H>
#include <p9_htm_def.H>
#include <p9_htm_adu_ctrl.H>

//------------------------------------------------------------------------------
// Constants
//------------------------------------------------------------------------------

// ADU PMISC address bit definition
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
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomData_2(0);

    // Engines must be in ready or pause state
    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[0] + HTM_STAT, l_scomData),
             "startHTM: getScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_STAT,
             (uint64_t)fapi2::current_err);
    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[1] + HTM_STAT, l_scomData_2),
             "startHTM: getScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_STAT,
             (uint64_t)fapi2::current_err);

    FAPI_ASSERT( (l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_READY>() ||
                  l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_PAUSED>()) &&
                 (l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_READY>() ||
                  l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_PAUSED>()),
                 fapi2::P9_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG_NHTM0(l_scomData)
                 .set_HTM_STATUS_REG_NHTM1(l_scomData_2),
                 "startHTM: NHTM is not in Ready state, can't start "
                 "NHTM0 status 0x%016llX, NHTM1 status 0x%016llX",
                 l_scomData, l_scomData_2);

    // Set HTM_TRIG's MARK_VALID
    l_scomData = 0;
    l_scomData.setBit<PU_HTM0_HTM_TRIG_HTMSC_MARK_VALID>();
    FAPI_INF("startHTM: HTM_TRIG reg Start: 0x%016llX", l_scomData);

    FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[0] + HTM_TRIG, l_scomData),
             "startHTM: putScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_TRIG,
             (uint64_t)fapi2::current_err);

    FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[1] + HTM_TRIG, l_scomData),
             "startHTM: putScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_TRIG,
             (uint64_t)fapi2::current_err);

    // Note: Use global PMISC ADU start command to better synchornize
    //       the traces of NHTM0 and NHTM1

    // Build address value
    l_scomData.flush<0>().setBit<ADU_ADDRESS_HTM_START_BIT>();

    // Start global trigger on the NHTM engines
    FAPI_TRY(aduNHTMControl(i_target, l_scomData),
             "startHTM: aduNHTMControl returns error.");

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
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint32_t l_imaHTMEnable = 0b100000000; // Set bit 4 of HTM_MODE to enable IMA

    // Get the EX parent of this core
    fapi2::Target<fapi2::TARGET_TYPE_EX> l_ex =
        i_target.getParent<fapi2::TARGET_TYPE_EX>();

    // IMA trace
    if (i_traceType == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
    {
        // Get HTM_MODE reg
        FAPI_TRY(fapi2::getScom(l_ex, CHTM_modeReg[i_pos % 2] + HTM_MODE, l_scomData),
                 "startHTM: getScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 CHTM_modeReg[i_pos % 2] + HTM_MODE, (uint64_t)fapi2::current_err);

        // Enable IMA capture
        l_scomData.insertFromRight<EX_HTM_MODE_HTMSC_CAPTURE,
                                   EX_HTM_MODE_HTMSC_CAPTURE_LEN>
                                   (l_imaHTMEnable);
        FAPI_INF("startHTM: HTM_MODE reg setup: 0x%016llX", l_scomData);
        FAPI_TRY(fapi2::putScom(l_ex, CHTM_modeReg[i_pos % 2] + HTM_MODE, l_scomData),
                 "startHTM: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X", CHTM_modeReg[i_pos % 2] + HTM_MODE,
                 (uint64_t)fapi2::current_err);

        // Display HTM_IMA_STATUS reg value
        FAPI_TRY(fapi2::getScom(l_ex, EX_HTM_IMA_STATUS, l_scomData),
                 "startHTM: getScom returns error: Addr "
                 "0x%016llX, l_rc 0x%.8X", EX_HTM_IMA_STATUS,
                 (uint64_t)fapi2::current_err);
        FAPI_INF("startHTM: HTM_IMA_STATUS: 0x%016llX", l_scomData);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C" {

///
/// @brief p9_htm_start procedure entry point
/// See doxygen in p9_htm_start.H
///
    fapi2::ReturnCode p9_htm_start(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
    {
        FAPI_DBG("Entering");
        fapi2::ReturnCode l_rc;
        uint8_t l_nhtmType;
        uint8_t l_chtmType[NUM_CHTM_ENGINES];
        uint8_t l_corePos = 0;
        auto l_modeRegList = std::vector<uint64_t>();
        auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>();
        fapi2::buffer<uint64_t> l_scomData(0);

        // Display attribute trace setup values

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target,
                               l_nhtmType),
                 "p9_htm_start: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_INF("p9_htm_start: NHTM type: 0x%.8X", l_nhtmType);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                               l_chtmType),
                 "p9_htm_start: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        FAPI_INF("p9_htm_start: CHTM type:");

        for (uint8_t ii = 0; ii < NUM_CHTM_ENGINES; ii++)
        {
            FAPI_INF("              Core[%u] 0x%.8X", ii, l_chtmType[ii]);
        }

        // Start NHTM
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            // Start trace for both NHTM0 and NHTM1
            // Note: We want to synch the trace for both NHTM engines as much
            //       as possible, so do not loop on individual engine
            //       here.  The startHTM function will check state and issue
            //       a global ADU command to start both engines.
            FAPI_TRY( startHTM(i_target, 0, l_nhtmType),
                      "p9_htm_start: startHTM() returns error NHTM"
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
                         "p9_htm_start: startHTM() returns error: CHTM %u, "
                         "l_rc 0x%.8X", l_corePos, (uint64_t)fapi2::current_err );
            }

        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

} // extern "C"
