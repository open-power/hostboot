/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_structs.H $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
#ifndef _P10_HTM_STRUCTS_H_
#define _P10_HTM_STRUCTS_H_
#include <fapi2.H>
#include <p10_htm_def.H>

////// NOTE
// The chtm attributes would be better suited as TARGET_TYPE_CORE, but by the time I realized this it would have
// been uneconimical to replace everything with the appropriate code. Save for P11.

///----------------------------------------------------------------------------
/// Struct IMA_mask_attrs_t
///----------------------------------------------------------------------------
///
/// @struct IMA_mask_attrs_t
/// Contains processor chip attribute values that are needed to perform
/// the setup of IMA_EVENT_MASK register.
/// The attributes are for CHTM traces only.
///
struct IMA_mask_attrs_t
{
    ///
    /// @brief getAttrs
    /// Function that reads all attributes needed to program IMA_EVENT_MASK reg.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

    // --------------------------------------
    // Attributes to setup HTM_CTRL reg
    // --------------------------------------
    uint8_t iv_imaEventTap[NUM_CHTM_ENGINES];    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_IC_TAP
    uint8_t iv_imaDisWrap[NUM_CHTM_ENGINES];     // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_DIS_WRAP
    uint8_t iv_imaFreeze[NUM_CHTM_ENGINES];      // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_FREEZE
    uint8_t iv_imaEnDFetch[NUM_CHTM_ENGINES];    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_D_PRE
    uint8_t iv_imaEnIFetch[NUM_CHTM_ENGINES];    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_I_PRE
    uint8_t iv_imaOneEvent[NUM_CHTM_ENGINES];    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_ONE_EVENT
    uint8_t iv_imaVTID[NUM_CHTM_ENGINES];        // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_VTID
    uint8_t iv_imaEventSelect[NUM_CHTM_ENGINES]; // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_SELECT
};

fapi2::ReturnCode IMA_mask_attrs_t::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_IC_TAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_IC_TAP, i_target,
                           iv_imaEventTap),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_IC_TAP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_DIS_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_DIS_WRAP, i_target,
                           iv_imaDisWrap),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_DIS_WRAP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_FREEZE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_FREEZE, i_target,
                           iv_imaFreeze),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_FREEZE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_D_PRE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_D_PRE, i_target,
                           iv_imaEnDFetch),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_D_PRE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_I_PRE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_I_PRE, i_target,
                           iv_imaEnIFetch),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EN_I_PRE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_ONE_EVENT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_ONE_EVENT, i_target,
                           iv_imaOneEvent),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_ONE_EVENT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_VTID
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_VTID, i_target,
                           iv_imaVTID),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_VTID, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_SELECT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_SELECT, i_target,
                           iv_imaEventSelect),
             "getAttrs: Error getting ATTR_CHTM_HTMSC_IMA_EVENT_MASK_EVENT_SELECT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Skip display becuase it would be unruly, only display configuration for cores that are being configured

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}
///----------------------------------------------------------------------------
/// Struct cHTM_mode_attrs_t
///----------------------------------------------------------------------------
///
/// @struct cHTM_mode_attrs_t
/// Contains processor chip attribute values that are needed to perform
/// the setup of HTM_MODE register.
/// The attributes are for CHTM traces only.
///
struct cHTM_mode_attrs_t
{
    ///
    /// @brief getAttrs
    /// Function that reads all attributes needed to program HTM_MODE reg.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

    // --------------------------------------
    // Attributes to setup HTM_CTRL reg
    // --------------------------------------
    uint8_t iv_llatCaptureDispDis[NUM_CHTM_ENGINES];   // ATTR_CHTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS
    uint8_t iv_llatCaptureStorDis[NUM_CHTM_ENGINES];   // ATTR_CHTM_MODE_LLAT_CAPTURE_STORE_DIS
    uint8_t iv_llatCapturePBL3Dis[NUM_CHTM_ENGINES];   // ATTR_CHTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS
    uint8_t iv_llatImbeddedTS[NUM_CHTM_ENGINES];       // ATTR_CHTM_MODE_LLAT_IMBEDDED_TS
    uint8_t iv_coreTraceFullStall[NUM_CHTM_ENGINES];   // ATTR_CHTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR
    uint8_t iv_llatPauseOnPurge[NUM_CHTM_ENGINES];     // ATTR_CHTM_MODE_LLAT_PAUSE_ON_PURGE
    uint8_t iv_chtmWrap[NUM_CHTM_ENGINES];             // ATTR_CHTM_MODE_CORE_WRAP
    uint8_t iv_disTimeStamp[NUM_CHTM_ENGINES];         // ATTR_CHTM_MODE_DIS_TSTAMP
    uint8_t iv_singleTimeStamp[NUM_CHTM_ENGINES];      // ATTR_CHTM_MODE_SINGLE_TIME_STAMP
    uint8_t iv_coreDisStall[NUM_CHTM_ENGINES];         // ATTR_CHTM_MODE_DIS_STALL
    uint8_t iv_markOnly[NUM_CHTM_ENGINES];             // ATTR_CHTM_MODE_MARKERS_ONLY
    uint8_t iv_disGroupScope[NUM_CHTM_ENGINES];        // ATTR_CHTM_MODE_DIS_GROUP
    uint8_t iv_vgTarget[NUM_CHTM_ENGINES];             // ATTR_CHTM_MODE_VGTARGET
};

fapi2::ReturnCode cHTM_mode_attrs_t::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // ATTR_CHTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS, i_target,
                           iv_llatCaptureDispDis),
             "getAttrs: Error getting ATTR_CHTM_MODE_LLAT_CAPTURE_FAIL_DISP_DIS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_LLAT_CAPTURE_STORE_DIS
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_LLAT_CAPTURE_STORE_DIS, i_target,
                           iv_llatCaptureStorDis),
             "getAttrs: Error getting ATTR_CHTM_MODE_LLAT_CAPTURE_STORE_DIS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS, i_target,
                           iv_llatCapturePBL3Dis),
             "getAttrs: Error getting ATTR_CHTM_MODE_LLAT_CAPTURE_PBL3_HIT_DIS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_LLAT_IMBEDDED_TS
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_LLAT_IMBEDDED_TS, i_target,
                           iv_llatImbeddedTS),
             "getAttrs: Error getting ATTR_CHTM_MODE_LLAT_IMBEDDED_TS, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR, i_target,
                           iv_coreTraceFullStall),
             "getAttrs: Error getting ATTR_CHTM_MODE_CORE_CAPTURE_TRACE_FULL_ON_ERROR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_LLAT_PAUSE_ON_PURGE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_LLAT_PAUSE_ON_PURGE, i_target,
                           iv_llatPauseOnPurge),
             "getAttrs: Error getting ATTR_CHTM_MODE_LLAT_PAUSE_ON_PURGE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_CORE_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_CORE_WRAP, i_target,
                           iv_chtmWrap),
             "getAttrs: Error getting ATTR_CHTM_MODE_CORE_WRAP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_DIS_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_DIS_TSTAMP, i_target,
                           iv_disTimeStamp),
             "getAttrs: Error getting ATTR_CHTM_MODE_DIS_TSTAMP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_SINGLE_TIME_STAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_SINGLE_TIME_STAMP, i_target,
                           iv_singleTimeStamp),
             "getAttrs: Error getting ATTR_CHTM_MODE_SINGLE_TIME_STAMP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_DIS_STALL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_DIS_STALL, i_target,
                           iv_coreDisStall),
             "getAttrs: Error getting ATTR_CHTM_MODE_DIS_STALL, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_MARKERS_ONLY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_MARKERS_ONLY, i_target,
                           iv_markOnly),
             "getAttrs: Error getting ATTR_CHTM_MODE_MARKERS_ONLY, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_DIS_GROUP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_DIS_GROUP, i_target,
                           iv_disGroupScope),
             "getAttrs: Error getting ATTR_CHTM_MODE_DIS_GROUP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // ATTR_CHTM_MODE_VGTARGET
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_MODE_VGTARGET, i_target,
                           iv_vgTarget),
             "getAttrs: Error getting ATTR_CHTM_MODE_VGTARGET, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Skip display becuase it would be unruly, only display configuration for cores that are being configured

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// Struct HTM_CTRL_attrs_t
///----------------------------------------------------------------------------
///
/// @struct HTM_CTRL_attrs_t
/// Contains processor chip attribute values that are needed to perform
/// the setup of HTM_CTRL register.
/// The attributes are common for both NHTM and CHTM traces.
///
struct HTM_CTRL_attrs_t
{
    ///
    /// @brief getAttrs
    /// Function that reads all attributes needed to program HTM_CTRL reg.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

    // --------------------------------------
    // Attributes to setup HTM_CTRL reg
    // --------------------------------------
    uint8_t    iv_nhtmCtrlTrig;            // ATTR_NHTM_CTRL_TRIG
    uint8_t    iv_nhtmCtrlMark;            // ATTR_NHTM_CTRL_MARK
    uint8_t    iv_chtmCtrlTrig;            // ATTR_CHTM_CTRL_TRIG
    uint8_t    iv_chtmCtrlMark;            // ATTR_CHTM_CTRL_MARK
    uint8_t    iv_ctrlDbg0Stop;            // ATTR_HTMSC_CTRL_DBG0_STOP
    uint8_t    iv_ctrlDbg1Stop;            // ATTR_HTMSC_CTRL_DBG1_STOP
    uint8_t    iv_ctrlRunStop;             // ATTR_HTMSC_CTRL_RUN_STOP
    uint8_t    iv_ctrlOtherDbg0Stop;       // ATTR_HTMSC_CTRL_OTHER_DBG0_STOP (NHTM only)
    uint8_t    iv_ctrlXstopStop;           // ATTR_HTMSC_CTRL_XSTOP_STOP
    uint8_t    iv_ctrlChip0Stop;           // ATTR_HTMSC_CTRL_CHIP0_STOP (CHTM only)
    uint8_t    iv_ctrlChip1Stop;           // ATTR_HTMSC_CTRL_CHIP1_STOP (CHTM only)
};

// See doxygen in struct definition.
fapi2::ReturnCode HTM_CTRL_attrs_t::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // ATTR_NTMSC_CTRL_TRIG
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_CTRL_TRIG, i_target, iv_nhtmCtrlTrig),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_TRIG, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_NTMSC_CTRL_MARK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_CTRL_MARK, i_target, iv_nhtmCtrlMark),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_MARK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_CHTM_CTRL_MARK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_CTRL_TRIG, i_target, iv_chtmCtrlTrig),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_TRIG, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_NTMSC_CTRL_MARK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_CTRL_MARK, i_target, iv_chtmCtrlMark),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_MARK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_DBG0_STOP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_DBG0_STOP, i_target,
                           iv_ctrlDbg0Stop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_DBG0_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_DBG1_STOP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_DBG1_STOP, i_target,
                           iv_ctrlDbg1Stop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_DBG1_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_RUN_STOP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_RUN_STOP, i_target,
                           iv_ctrlRunStop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_RUN_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_OTHER_DBG0_STOP (NHTM)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_OTHER_DBG0_STOP, i_target,
                           iv_ctrlOtherDbg0Stop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_OTHER_DBG0_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_XSTOP_STOP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_XSTOP_STOP, i_target,
                           iv_ctrlXstopStop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_XSTOP_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_CHIP0_STOP (CHTM)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_CHIP0_STOP, i_target,
                           iv_ctrlChip0Stop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_CHIP0_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // ATTR_HTMSC_CTRL_CHIP1_STOP (CHTM)
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CTRL_CHIP1_STOP, i_target,
                           iv_ctrlChip1Stop),
             "getAttrs: Error getting ATTR_HTMSC_CTRL_CHIP1_STOP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Display generic HTM_CTRL attributes
    FAPI_DBG("  ATTR_NHTM_CTRL_TRIG            0x%.8X", iv_nhtmCtrlTrig);
    FAPI_DBG("  ATTR_NHTM_CTRL_MARK            0x%.8X", iv_nhtmCtrlMark);
    FAPI_DBG("  ATTR_CHTM_CTRL_TRIG            0x%.8X", iv_chtmCtrlTrig);
    FAPI_DBG("  ATTR_CHTM_CTRL_MARK            0x%.8X", iv_chtmCtrlMark);
    FAPI_DBG("  ATTR_HTMSC_CTRL_DBG0_STOP       0x%.8X", iv_ctrlDbg0Stop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_DBG1_STOP       0x%.8X", iv_ctrlDbg1Stop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_RUN_STOP        0x%.8X", iv_ctrlRunStop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_OTHER_DBG0_STOP 0x%.8X", iv_ctrlOtherDbg0Stop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_XSTOP_STOP      0x%.8X", iv_ctrlXstopStop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_CHIP0_STOP      0x%.8X", iv_ctrlChip0Stop);
    FAPI_DBG("  ATTR_HTMSC_CTRL_CHIP1_STOP      0x%.8X", iv_ctrlChip1Stop);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///----------------------------------------------------------------------------
/// Struct HTM_FILT_attrs_t
///----------------------------------------------------------------------------
///
/// @struct HTM_FILT_attrs_t
/// Contains all filter related attributes required to setup the HTM filters
/// The CHTMs do not have filtering capabilities.
///
struct HTM_FILT_attrs_t
{
    ///
    /// @brief getAttrs
    /// Function that reads all attributes needed to program HTM_FILT regs.
    ///
    /// @param[in] i_target    Reference to processor chip target
    ///
    /// @return FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode getAttrs(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

    // --------------------------------------
    // Attributes to setup HTM_FILT registers
    // --------------------------------------
    uint8_t iv_filtStopOnMatch;          // ATTR_HTMSC_FILT_STOP_ON_MATCH
    uint8_t iv_filtCrespPat;             // ATTR_HTMSC_FILT_CRESP_PAT
    uint8_t iv_filtScopePat;             // ATTR_HTMSC_FILT_SCOPE_PAT
    uint8_t iv_filtSourcePat;            // ATTR_HTMSC_FILT_SOURCE_PAT
    uint8_t iv_filtPortPat;              // ATTR_HTMSC_FILT_PORT_PAT
    uint8_t iv_filtCrespMask;            // ATTR_HTMSC_FILT_CRESP_MASK
    uint8_t iv_filtScopeMask;            // ATTR_HTMSC_FILT_SCOPE_MASK
    uint8_t iv_filtSourceMask;           // ATTR_HTMSC_FILT_SOURCE_MASK
    uint8_t iv_filtPortMask;             // ATTR_HTMSC_FILT_PORT_MASK
    uint8_t iv_filtFiltInvert;           // ATTR_HTMSC_FILT_TTAGFILT_INVERT
    uint8_t iv_filtTtypePat;             // ATTR_HTMSC_TTYPEFILT_TTYPE_PAT
    uint8_t iv_filtTtypeMask;            // ATTR_HTMSC_TTYPEFILT_TTYPE_MASK
    uint8_t iv_filtTsizePat;             // ATTR_HTMSC_TTYPEFILT_TSIZE_PAT
    uint8_t iv_filtTsizeMask;            // ATTR_HTMSC_TTYPEFILT_TSIZE_MASK
    uint8_t iv_filtTtypeFiltInvert;      // ATTR_HTMSC_TTYPEFILT_INVERT
    uint8_t iv_filtCrespFiltInvert;      // ATTR_HTMSC_CRESPFILT_INVERT
    uint8_t iv_filtPort1Pat;             // ATTR_HTMSC_FILT_PORT1_PAT
    uint8_t iv_filtPort1Mask;            // ATTR_HTMSC_FILT_PORT1_MASK
    uint8_t iv_filtStopCycles;          // ATTR_HTMSC_FILT_STOP_CYCLES
    uint32_t iv_filtTtagPat;             // ATTR_HTMSC_FILT_TTAG_PAT
    uint32_t iv_filtTtagMask;            // ATTR_HTMSC_FILT_TTAG_MASK
    uint64_t iv_filtAddrPat;             // ATTR_HTMSC_FILT_ADDR_PAT
    uint64_t iv_filtAddrMask;            // ATTR_HTMSC_FILT_ADDR_MASK
};

// See doxygen in struct definition.
fapi2::ReturnCode HTM_FILT_attrs_t::getAttrs(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_STOP_ON_MATCH, i_target, iv_filtStopOnMatch),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_STOP_ON_MATCH, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_STOP_CYCLES, i_target, iv_filtStopCycles),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_STOP_CYCLES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_TTAG_PAT, i_target, iv_filtTtagPat),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_TTAG_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_TTAG_MASK, i_target, iv_filtTtagMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_TTAG_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // NOTE: TTYPE is in the same reg as the CRESP,TTAG,etc for STOP filters
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_PAT, i_target, iv_filtCrespPat),
             "setup_NHTM_CRESP_FILT: Error getting ATTR_HTMSC_FILT_CRESP_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_SCOPE_PAT, i_target, iv_filtScopePat),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_SCOPE_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_SOURCE_PAT, i_target, iv_filtSourcePat),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_SOURCE_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PORT_PAT, i_target, iv_filtPortPat),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_PORT_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_SCOPE_MASK, i_target, iv_filtScopeMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_SCOPE_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_SOURCE_MASK, i_target, iv_filtSourceMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_SOURCE_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PORT_MASK, i_target, iv_filtPortMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_PORT_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_MASK, i_target, iv_filtCrespMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_CRESP_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTAGFILT_INVERT, i_target, iv_filtFiltInvert),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_TTAGFILT_INVERT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_ADDR_PAT, i_target, iv_filtAddrPat),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_ADDR_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_ADDR_MASK, i_target, iv_filtAddrMask),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_ADDR_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_PAT, i_target, iv_filtTtypePat),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_PAT, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_PAT, i_target, iv_filtTsizePat),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TSIZEFILT_PAT, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_MASK, i_target, iv_filtTtypeMask),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_MASK, i_target, iv_filtTsizeMask),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TSIZEFILT_MASK, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_INVERT, i_target, iv_filtTtypeFiltInvert),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_INVERT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CRESPFILT_INVERT, i_target, iv_filtCrespFiltInvert),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_CRESPFILT_INVERT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    // Get DD2 specific attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PORT1_PAT, i_target, iv_filtPort1Pat),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_FILT_PORT1_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PORT1_MASK, i_target, iv_filtPort1Mask),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_FILT_PORT1_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_DBG("  ATTR_HTMSC_FILT_TTAG_PAT          0x%.8X", iv_filtTtagPat);
    FAPI_DBG("  ATTR_HTMSC_FILT_TTAG_MASK         0x%.8X", iv_filtTtagMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_CRESP_PAT         0x%.8X", iv_filtCrespPat);
    FAPI_DBG("  ATTR_HTMSC_FILT_CRESP_MASK        0x%.8X", iv_filtCrespMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_SCOPE_PAT         0x%.8X", iv_filtScopePat);
    FAPI_DBG("  ATTR_HTMSC_FILT_SCOPE_MASK        0x%.8X", iv_filtScopeMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_PORT_PAT          0x%.8X", iv_filtPortPat);
    FAPI_DBG("  ATTR_HTMSC_FILT_PORT_MASK         0x%.8X", iv_filtPortMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_SOURCE_PAT        0x%.8X", iv_filtSourcePat);
    FAPI_DBG("  ATTR_HTMSC_FILT_SOURCE_MASK       0x%.8X", iv_filtSourceMask);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_PAT          0x%.8X", iv_filtTtypePat);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_MASK         0x%.8X", iv_filtTtypeMask);
    FAPI_DBG("  ATTR_HTMSC_TSIZEFILT_PAT          0x%.8X", iv_filtTsizePat);
    FAPI_DBG("  ATTR_HTMSC_TSIZEFILT_MASK         0x%.8X", iv_filtTsizeMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_ADDR_PAT          0x%.16X", iv_filtAddrPat);
    FAPI_DBG("  ATTR_HTMSC_FILT_ADDR_MASK         0x%.16X", iv_filtAddrMask);
    FAPI_DBG("  ATTR_HTMSC_FILT_STOP_ON_MATCH     0x%.8X", iv_filtStopOnMatch);
    FAPI_DBG("  ATTR_HTMSC_FILT_STOP_CYCLES       0x%.8X", iv_filtStopCycles);
    FAPI_DBG("  ATTR_HTMSC_TTAGFILT_INVERT        0x%.8X", iv_filtFiltInvert);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_INVERT       0x%.8X", iv_filtTtypeFiltInvert);
    FAPI_DBG("  ATTR_HTMSC_CRESPFILT_INVERT       0x%.8X", iv_filtCrespFiltInvert);
    FAPI_DBG("  ATTR_HTMSC_FILT_PORT1_PAT         0x%.8X", iv_filtPort1Pat);
    FAPI_DBG("  ATTR_HTMSC_FILT_PORT1_MASK        0x%.8X", iv_filtPort1Mask);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


#endif // _P10_HTM_STRUCTS_H_
