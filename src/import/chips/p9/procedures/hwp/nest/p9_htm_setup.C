/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_setup.C $                 */
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
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_htm_setup.C $                 */
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
///----------------------------------------------------------------------------
/// @file  p9_htm_setup.C
///
/// @brief Perform p9_htm_setup on a processor chip
///
/// The purpose of this procedure is to setup and start HTM on a processor
/// chip.
/// Some start/setup attributes are used as part of the setup process.
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
#include <p9_htm_setup.H>
#include <p9_htm_def.H>
#include <p9_htm_start.H>
#include <p9_htm_reset.H>

///----------------------------------------------------------------------------
/// Constants
///----------------------------------------------------------------------------
const uint64_t IMA_EVENT_MASK_VALUE                            = 0x0004008000000000;
const uint8_t NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL_BIT    = 5;
const uint8_t NHTM_HTMSC_MODE_CAPTURE_CRESP_MODE_BIT_START     = 6;
const uint8_t NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_BIT = 8;

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
    fapi2::ReturnCode getAttrs(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

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


///
/// @brief This function sets up CHTM_PDBAR reg for CHTM.
///
/// @param[in] i_target    Reference to core target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_CHTM_PDBAR(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_uint8_attr = 0;
    uint64_t l_uint64_attr = 0;
    uint8_t l_pos = 0;

    // Get the proc target to read attribute settings
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Get the EX parent of this core to program the register
    fapi2::Target<fapi2::TARGET_TYPE_EX> l_ex =
        i_target.getParent<fapi2::TARGET_TYPE_EX>();

    // Get this core's position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_pos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // --------------------------------------
    // Attributes to setup CHTM_PDBAR reg
    // --------------------------------------

    // ATTR_HTMSC_IMA_PDBAR_SPLIT_CORE_MODE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_IMA_PDBAR_SPLIT_CORE_MODE, l_proc,
                           l_uint8_attr),
             "setup_CHTM_PDBAR: Error getting ATTR_HTMSC_IMA_PDBAR_SPLIT_CORE_MODE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_IMA_PDBAR_SPLIT_CORE_MODE 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_IMA_PDBAR_SPLIT_CORE_MODE_DISABLE) ?
    l_scomData.clearBit<EX_HTM_IMA_PDBAR_HTMSC_ENABLE_SPLIT_CORE>() :
    l_scomData.setBit<EX_HTM_IMA_PDBAR_HTMSC_ENABLE_SPLIT_CORE>();

    // ATTR_HTMSC_IMA_PDBAR_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_IMA_PDBAR_SCOPE, l_proc,
                           l_uint8_attr),
             "setup_CHTM_PDBAR: Error getting ATTR_HTMSC_IMA_PDBAR_SCOPE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_IMA_PDBAR_SCOPE 0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<EX_HTM_IMA_PDBAR_HTMSC_SCOPE,
                               EX_HTM_IMA_PDBAR_HTMSC_SCOPE_LEN>
                               (l_uint8_attr);

    // ATTR_HTMSC_IMA_PDBAR_ADDR
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_IMA_PDBAR_ADDR, l_proc,
                           l_uint64_attr),
             "setup_CHTM_PDBAR: Error getting ATTR_HTMSC_IMA_PDBAR_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_IMA_PDBAR_ADDR 0x%.16llX", l_uint64_attr);
    // Bits 8:50
    l_scomData.insert<EX_HTM_IMA_PDBAR_HTMSC, EX_HTM_IMA_PDBAR_HTMSC_LEN,
                      EX_HTM_IMA_PDBAR_HTMSC>(l_uint64_attr);

    // Display CHTM_PDBAR reg setup value
    FAPI_INF("setupChtm: CHTM_PDBAR reg setup: 0x%016llX", l_scomData);

    // Write HW
    FAPI_TRY(fapi2::putScom(l_ex,  CHTM_modeReg[l_pos % 2] + CHTM_PDBAR,
                            l_scomData),
             "setupChtm: putScom returns error: Addr 0x%016llX, l_rc 0x%.8X",
             CHTM_modeReg[l_pos % 2] + CHTM_PDBAR,  (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


///
/// @brief This function sets up IMA_EVENT_MASK reg for CHTM.
///
/// @param[in] i_target    Reference to core target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_IMA_EVENT_MASK(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(IMA_EVENT_MASK_VALUE);
    uint8_t l_pos = 0;

    // Get the EX parent of this core to program the register
    fapi2::Target<fapi2::TARGET_TYPE_EX> l_ex =
        i_target.getParent<fapi2::TARGET_TYPE_EX>();

    // Get this core's position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_pos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // Display IMA_EVENT_MASK reg setup value
    FAPI_INF("setupChtm: IMA_EVENT_MASK reg setup: 0x%016llX", l_scomData);

    // Write HW
    FAPI_TRY(fapi2::putScom(l_ex, EX_IMA_EVENT_MASK, l_scomData),
             "setup_IMA_EVENT_MASK: putScom returns error: Addr 0x%016llX, l_rc 0x%.8X",
             EX_IMA_EVENT_MASK,  (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief This function sets up the NHTM_FILT based on attribute settings.
///
/// @param[in] i_target    Reference to processor chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_NHTM_FILT(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_uint8_attr = 0;
    uint32_t l_uint32_attr = 0;

    // Setup data value to program NHTM_FILT reg

    // ATTR_HTMSC_FILT_PAT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_PAT, i_target,
                           l_uint32_attr),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_FILT_PAT        0x%.8X", l_uint32_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_FILT_HTMSC_PAT,
                               PU_HTM0_HTM_FILT_HTMSC_PAT_LEN>
                               (l_uint32_attr);

    // ATTR_HTMSC_FILT_CRESP_PAT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_PAT, i_target,
                           l_uint8_attr),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_CRESP_PAT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_FILT_CRESP_PAT  0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_FILT_HTMSC_CRESP_PAT,
                               PU_HTM0_HTM_FILT_HTMSC_CRESP_PAT_LEN>
                               (l_uint8_attr);

    // ATTR_HTMSC_FILT_MASK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_MASK, i_target,
                           l_uint32_attr),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_FILT_MASK       0x%.8X", l_uint32_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_FILT_HTMSC_MASK,
                               PU_HTM0_HTM_FILT_HTMSC_MASK_LEN>
                               (~l_uint32_attr);

    // ATTR_HTMSC_FILT_CRESP_MASK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_CRESP_MASK, i_target,
                           l_uint8_attr),
             "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_CRESP_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_FILT_CRESP_MASK 0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_FILT_HTMSC_CRESP_MASK,
                               PU_HTM0_HTM_FILT_HTMSC_CRESP_MASK_LEN>
                               (~l_uint8_attr);

    // Display NHTM_FILT reg setup value
    FAPI_INF("setup_NHTM_FILT: NHTM_FILT reg setup: 0x%016llX",
             l_scomData);

    // Write HW, program both NHTM0 and NHTM1
    for (uint8_t ii = 0; ii < NUM_NHTM_ENGINES; ii++)
    {
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii] + NHTM_FILT,
                                l_scomData),
                 "setup_NHTM_FILT: putScom returns error: Addr 0x%016llX, "
                 "l_rc 0x%.8X", NHTM_modeRegList[ii] + NHTM_FILT,
                 (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


///
/// @brief This function sets up the NHTM_TTYPE_FILT based on attribute settings.
///        It's used on FABRIC trace type only.
///
/// @param[in] i_target    Reference to processor chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_NHTM_TTYPE_FILT(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_uint8_attr = 0;

    // Setup data value to program NHTM_TTYPE_FILT reg

    // ATTR_HTMSC_TTYPEFILT_PAT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_PAT, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_PAT, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_PAT        0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_TTYPEFILT_HTMSC_PAT,
                               PU_HTM0_HTM_TTYPEFILT_HTMSC_PAT_LEN>
                               (l_uint8_attr);

    // ATTR_HTMSC_TSIZEFILT_PAT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_PAT, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TSIZEFILT_PAT, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_TSIZEFILT_PAT        0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_TTYPEFILT_HTMSC_TSIZEFILT_PAT,
                               PU_HTM0_HTM_TTYPEFILT_HTMSC_TSIZEFILT_PAT_LEN>
                               (l_uint8_attr);

    // Set ATTR_HTMSC_TTYPEFILT_MASK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_MASK, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_MASK, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_MASK       0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_TTYPEFILT_HTMSC_MASK,
                               PU_HTM0_HTM_TTYPEFILT_HTMSC_MASK_LEN>
                               (~l_uint8_attr);

    // ATTR_HTMSC_TSIZEFILT_MASK
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TSIZEFILT_MASK, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TSIZEFILT_MASK, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_TSIZEFILT_MASK       0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_TTYPEFILT_HTMSC_TSIZEFILT_MASK,
                               PU_HTM0_HTM_TTYPEFILT_HTMSC_TSIZEFILT_MASK_LEN>
                               (~l_uint8_attr);

    // ATTR_HTMSC_TTYPEFILT_INVERT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_TTYPEFILT_INVERT, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_TTYPEFILT_INVERT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_TTYPEFILT_INVERT     0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_TTYPEFILT_INVERT_MATCH) ?
    l_scomData.clearBit<PU_HTM0_HTM_TTYPEFILT_HTMSC_INVERT>() :
    l_scomData.setBit<PU_HTM0_HTM_TTYPEFILT_HTMSC_INVERT>();

    // ATTR_HTMSC_CRESPFILT_INVERT
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_CRESPFILT_INVERT, i_target,
                           l_uint8_attr),
             "setup_NHTM_TTYPE_FILT: Error getting ATTR_HTMSC_CRESPFILT_INVERT, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_CRESPFILT_INVERT     0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_CRESPFILT_INVERT_MATCH) ?
    l_scomData.clearBit<PU_HTM0_HTM_TTYPEFILT_HTMSC_CRESPFILT_INVERT>() :
    l_scomData.setBit<PU_HTM0_HTM_TTYPEFILT_HTMSC_CRESPFILT_INVERT>();

    // Display NHTM_TTYPE_FILT reg setup value
    FAPI_INF("setupNhtm: NHTM_TTYPE_FILT reg setup: 0x%016llX", l_scomData);

    // Write HW, program both NHTM0 and NHTM1
    for (uint8_t ii = 0; ii < NUM_NHTM_ENGINES; ii++)
    {
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii] + NHTM_TTYPE_FILT,
                                l_scomData),
                 "setup_NHTM_TTYPE_FILT: putScom returns error: Addr 0x%016llX, "
                 "l_rc 0x%.8X", NHTM_modeRegList[ii] + NHTM_TTYPE_FILT,
                 (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief This function sets up the HTM_CTRL register.
///
/// @tparam T template parameter, passed in target.
/// @param[in] i_target            Reference to HW target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode setup_HTM_CTRL(const fapi2::Target<T>& i_target);

///
/// TARGET_TYPE_PROC_CHIP (NHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_CTRL(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    HTM_CTRL_attrs_t l_HTM_CTRL;

    // Setup data value to program HTM_CTRL reg
    // Note: Register bit definitions are the same for both NHTM0 and NHTM1

    // Get the proc attributes needed to perform HTM_CTRL setup
    FAPI_TRY(l_HTM_CTRL.getAttrs(i_target),
             "l_HTM_CTRL.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set CTRL_TRIG
    l_scomData.insertFromRight <PU_HTM0_HTM_CTRL_HTMSC_TRIG,
                               PU_HTM0_HTM_CTRL_HTMSC_TRIG_LEN>
                               (l_HTM_CTRL.iv_nhtmCtrlTrig);

    // Set CTRL_MARK
    l_scomData.insertFromRight <PU_HTM0_HTM_CTRL_HTMSC_MARK,
                               PU_HTM0_HTM_CTRL_HTMSC_MARK_LEN>
                               (l_HTM_CTRL.iv_nhtmCtrlMark);

    // Set CTRL_DBG0_STOP
    (l_HTM_CTRL.iv_ctrlDbg0Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG0_STOP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_CTRL_HTMSC_DBG0_STOP>() :
    l_scomData.setBit<PU_HTM0_HTM_CTRL_HTMSC_DBG0_STOP>();

    // Set CTRL_DBG1_STOP
    (l_HTM_CTRL.iv_ctrlDbg1Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG1_STOP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_CTRL_HTMSC_DBG1_STOP>() :
    l_scomData.setBit<PU_HTM0_HTM_CTRL_HTMSC_DBG1_STOP>();

    // Set CTRL_RUN_STOP
    (l_HTM_CTRL.iv_ctrlRunStop == fapi2::ENUM_ATTR_HTMSC_CTRL_RUN_STOP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_CTRL_HTMSC_RUN_STOP>() :
    l_scomData.setBit<PU_HTM0_HTM_CTRL_HTMSC_RUN_STOP>();

    // Set CTRL_OTHER_DBG0_STOP
    (l_HTM_CTRL.iv_ctrlOtherDbg0Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_OTHER_DBG0_STOP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_CTRL_HTMSC_OTHER_DBG0_STOP>() :
    l_scomData.setBit<PU_HTM0_HTM_CTRL_HTMSC_OTHER_DBG0_STOP>();

    // Set CTRL_XSTOP_STOP
    (l_HTM_CTRL.iv_ctrlXstopStop == fapi2::ENUM_ATTR_HTMSC_CTRL_XSTOP_STOP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_CTRL_HTMSC_XSTOP_STOP>() :
    l_scomData.setBit<PU_HTM0_HTM_CTRL_HTMSC_XSTOP_STOP>();

    // Display HTM_CTRL reg setup value
    FAPI_INF("setup_HTM_CTRL: HTM_CTRL reg setup: 0x%016llX", l_scomData);

    // Write data to HTM_CTRL
    // Program both NHTM0 and NHTM1
    for (uint8_t ii = 0; ii < NUM_NHTM_ENGINES; ii++)
    {
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii] + HTM_CTRL,
                                l_scomData),
                 "setup_HTM_CTRL: putScom returns error: Addr 0x%016llX, "
                 "l_rc 0x%.8X", NHTM_modeRegList[ii],
                 (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// TARGET_TYPE_CORE (CHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_CTRL(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // For IMA trace, no need to program HTM_CTRL.
    // Place holder for other CHTM trace setup when they are suppored.

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief getMemSmallSize
/// Utility function that returns the Trace Memory Size setting for
/// HTM_MEM register based on input HTM trace size.
///
/// @param[in]  i_size      HTM trace size
/// @param[out] o_htmSize   Trace memory size value
/// @param[out] o_smallSize Trace memory size small value
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getTraceMemSizeValues(const uint64_t i_size,
                                        htm_size_t& o_htmSize,
                                        bool& o_smallSize)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    switch (i_size)
    {
        // Note: NTHM and CHTM have the same size definitions.
        //       Use NHTM enum values here for both case.
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_16_MB:
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_512_MB:
            o_htmSize = HTM_512M_OR_16M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_32_MB:
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_1_GB:
            o_htmSize = HTM_1G_OR_32M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_64_MB:
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_2_GB:
            o_htmSize = HTM_2G_OR_64M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_128_MB:
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_4_GB:
            o_htmSize = HTM_4G_OR_128M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_256_MB:
        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_8_GB:
            o_htmSize = HTM_8G_OR_256M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_16_GB:
            o_htmSize = HTM_16G_OR_512M;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_32_GB:
            o_htmSize = HTM_32G_OR_1G;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_64_GB:
            o_htmSize = HTM_64G_OR_2G;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_128_GB:
            o_htmSize = HTM_128G_OR_4G;
            break;

        case fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_256_GB:
            o_htmSize = HTM_256G_OR_8G;
            break;

        default:
            FAPI_ASSERT(false,
                        fapi2::HTM_SETUP_PROC_BAR_SIZE()
                        .set_PROC_BAR_SIZE(i_size),
                        "getAttrs: Invalid proc BAR size value: "
                        "0x%016llX", i_size);
            break;
    }

    // If memsize >= 512MB, set small memory size to false
    if (i_size >= fapi2::ENUM_ATTR_PROC_NHTM_BAR_SIZE_512_MB)
    {
        o_smallSize = false;
    }
    else
    {
        o_smallSize = true;
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief This function sets up the HTM_MEM register.
///
/// @tparam T template parameter, passed in target.
/// @param[in] i_target            Reference to HW target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode setup_HTM_MEM(const fapi2::Target<T>& i_target);

///
/// TARGET_TYPE_PROC_CHIP (NHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_MEM(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData;
    uint8_t l_uint8_attr = 0;
    htm_size_t l_barHtmSize;
    bool l_smallSize;
    uint64_t l_barAddr;
    uint64_t l_barSize;

    // Setup data value to program HTM_MEM reg
    // Note: Register bit definitions are the same for both NHTM0 and NHTM1

    // ATTR_PROC_NHTM_BAR_BASE_ADDR
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NHTM_BAR_BASE_ADDR, i_target,
                           l_barAddr),
             "setup_HTM_MEM: Error getting ATTR_PROC_NHTM_BAR_BASE_ADDR, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    // ATTR_PROC_NHTM_BAR_SIZES
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NHTM_BAR_SIZE, i_target,
                           l_barSize),
             "setup_HTM_MEM: Error getting ATTR_PROC_NHTM_BAR_SIZE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    l_scomData = 0;

    // ATTR_HTMSC_MEM_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_SCOPE, i_target, l_uint8_attr),
             "setup_HTM_MEM: Error getting ATTR_HTMSC_MEM_SCOPE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MEM_SCOPE            0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_MEM_HTMSC_SCOPE,
                               PU_HTM0_HTM_MEM_HTMSC_SCOPE_LEN>
                               (l_uint8_attr);

    // ATTR_HTMSC_MEM_PRIORITY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_PRIORITY, i_target, l_uint8_attr),
             "setup_HTM_MEM: Error getting ATTR_HTMSC_MEM_PRIORITY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MEM_PRIORITY         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MEM_PRIORITY_LOW) ?
    l_scomData.clearBit<PU_HTM0_HTM_MEM_HTMSC_PRIORITY>() :   // LOW
    l_scomData.setBit<PU_HTM0_HTM_MEM_HTMSC_PRIORITY>();      // HIGH

    // Set base addr
    // Right shift PROC HTM Bar Base addr 24 bits to align to 16MB trace memory.
    FAPI_DBG("  ATTR_PROC_NHTM_BAR_BASE_ADDR 0x%.16llX", l_barAddr);
    l_scomData.insertFromRight<PU_HTM0_HTM_MEM_HTMSC_BASE,
                               PU_HTM0_HTM_MEM_HTMSC_BASE_LEN>
                               (l_barAddr >> 24);

    // Get HTM size
    FAPI_TRY(getTraceMemSizeValues(l_barSize, l_barHtmSize, l_smallSize),
             "getTraceMemSizeValues() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set bar size (ATTR_PROC_NHTM_BAR_SIZES)
    FAPI_DBG("  ATTR_PROC_NHTM_BAR_SIZE  0x%.16llX", l_barSize);
    FAPI_DBG("  HTMSC_SIZE 0x%.16llX", l_barHtmSize);
    l_scomData.insertFromRight<PU_HTM0_HTM_MEM_HTMSC_SIZE,
                               PU_HTM0_HTM_MEM_HTMSC_SIZE_LEN>
                               (l_barHtmSize);

    // Set mem size
    FAPI_DBG("  Small Mem Size[%u]          0x%.8X", (uint32_t)l_smallSize);
    (l_smallSize == true) ?
    l_scomData.setBit<PU_HTM0_HTM_MEM_HTMSC_SIZE_SMALL>() :
    l_scomData.clearBit<PU_HTM0_HTM_MEM_HTMSC_SIZE_SMALL>();

    // Display HTM_MEM value to write to HW
    FAPI_INF("setup_HTM_MEM: HTM_MEM reg setup: 0x%016llX", l_scomData);

    // Write config data into HTM_MEM
    // Note: Yes, write same value to both engines.
    for (uint8_t ii = 0; ii < NUM_NHTM_ENGINES; ii++)
    {
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii] + HTM_MEM,
                                l_scomData),
                 "setup_HTM_MEM: putScom returns error (1): Addr 0x%016llX, "
                 "l_rc 0x%.8X",  NHTM_modeRegList[ii] + HTM_MEM,
                 (uint64_t)fapi2::current_err);

        // MEM_ALLOC must switch from 0->1 for this setup to complete
        l_scomData.setBit<PU_HTM0_HTM_MEM_HTMSC_ALLOC>();
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii] + HTM_MEM,
                                l_scomData),
                 "setup_HTM_MEM: putScom returns error (2): Addr 0x%016llX, "
                 "l_rc 0x%.8X", NHTM_modeRegList[ii] + HTM_MEM,
                 (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// TARGET_TYPE_CORE (CHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_MEM(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;

    // For IMA trace, no need to program HTM_MEM.
    // Place holder for other CHTM trace setup when they are suppored.

    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


///
/// @brief This function sets up the HTM_MODE register.
///
/// @tparam T template parameter, passed in target.
/// @param[in] i_target            Reference to HW target
/// @param[in] i_traceType         Trace type
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode setup_HTM_MODE(const fapi2::Target<T>& i_target,
                                 const uint8_t i_traceType);

///
/// TARGET_TYPE_PROC_CHIP (NHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_MODE(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint8_t i_traceType)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_uint8_attr = 0;
    uint32_t l_uint32_attr = 0;

    // Setup data value to program HTM_MODE reg
    // Note:
    //    - Register bit definitions are the same for both NHTM0 and NHTM1
    //    - i_traceType may be needed later when more trace type is supported.

    // Enable HTM
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_ENABLE>();

    // ATTR_NHTM_HTMSC_MODE_CONTENT_SEL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CONTENT_SEL, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CONTENT_SEL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CONTENT_SEL      0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_MODE_HTMSC_CONTENT_SEL,
                               PU_HTM0_HTM_MODE_HTMSC_CONTENT_SEL_LEN>
                               (l_uint8_attr);

    // ATTR_NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CAPTURE_GENERATED_WRITES_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_CAPTURE>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_CAPTURE>();

    // ATTR_NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL_DISABLE) ?
    l_scomData.clearBit<NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL_BIT>() :
    l_scomData.setBit<NHTM_HTMSC_MODE_CAPTURE_ENABLE_FILTER_ALL_BIT>();

    // ATTR_NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE 0x%.8X", l_uint8_attr);
    // Clear CRESP mode bits (6:7)
    l_scomData.clearBit<NHTM_HTMSC_MODE_CAPTURE_CRESP_MODE_BIT_START, 2>();

    if (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CAPTURE_PRECISE_CRESP_MODE_ENABLE)
    {
        // Set bits 6:7 to 0b10 for Precise cresp mode
        l_scomData.setBit<NHTM_HTMSC_MODE_CAPTURE_CRESP_MODE_BIT_START>();
    }

    // ATTR_NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_DISABLE) ?
    l_scomData.clearBit<NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_BIT>() :
    l_scomData.setBit<NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_BIT>();

    // ATTR_NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CAPTURE_PMISC_ONLY_CMD_DISABLE) ?
    l_scomData.clearBit<NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_BIT>() :
    l_scomData.setBit<NHTM_HTMSC_MODE_CAPTURE_LIMIT_MEM_ALLOCATION_BIT>();

    // ATTR_HTMSC_MODE_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRAP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_WRAP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_WRAP                  0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_WRAP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_WRAP>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_WRAP>();

    // ATTR_HTMSC_MODE_DIS_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_TSTAMP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_TSTAMP            0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_TSTAMP_DISABLE) ?
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_DIS_TSTAMP>() :
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_DIS_TSTAMP>();

    // ATTR_HTMSC_MODE_SINGLE_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SINGLE_TSTAMP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_SINGLE_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_SINGLE_TSTAMP         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_SINGLE_TSTAMP_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_SINGLE_TSTAMP>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_SINGLE_TSTAMP>();

    // ATTR_HTMSC_MODE_MARKERS_ONLY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_MARKERS_ONLY, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_MARKERS_ONLY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_MARKERS_ONLY          0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_MARKERS_ONLY_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_MARKERS_ONLY>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_MARKERS_ONLY>();

    // ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE, "
             "l_rc 0x%.8X",  (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_DIS_FORCE_GROUP_SCOPE>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_DIS_FORCE_GROUP_SCOPE>();

    // ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE 0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_MODE_HTMSC_SYNC_STAMP_FORCE,
                               PU_HTM0_HTM_MODE_HTMSC_SYNC_STAMP_FORCE_LEN>
                               (l_uint8_attr);

    // ATTR_NHTM_HTMSC_MODE_WRITETOIO
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_WRITETOIO,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_WRITETOIO, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_WRITETOIO        0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_WRITETOIO_DISABLE) ?
    l_scomData.clearBit<PU_HTM0_HTM_MODE_HTMSC_WRITETOIO>() :
    l_scomData.setBit<PU_HTM0_HTM_MODE_HTMSC_WRITETOIO>();

    // ATTR_HTMSC_MODE_VGTARGET
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_VGTARGET, i_target,
                           l_uint32_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_VGTARGET, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_VGTARGET              0x%.8X", l_uint32_attr);
    l_scomData.insertFromRight<PU_HTM0_HTM_MODE_HTMSC_VGTARGET,
                               PU_HTM0_HTM_MODE_HTMSC_VGTARGET_LEN>
                               (l_uint32_attr);

    // Display HTM_MODE reg setup value
    FAPI_INF("setup_HTM_MODE: HTM_MODE reg setup: 0x%016llX", l_scomData);

    // Program both NHTM0 and NHTM1
    for (uint8_t ii = 0; ii < NUM_NHTM_ENGINES; ii++)
    {
        FAPI_TRY(fapi2::putScom(i_target, NHTM_modeRegList[ii], l_scomData),
                 "setup_HTM_MODE: putScom returns error: "
                 "Addr 0x%016llX, l_rc 0x%.8X",
                 NHTM_modeRegList[ii],  (uint64_t)fapi2::current_err);
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// TARGET_TYPE_CORE (CHTM trace)
///
template<>
fapi2::ReturnCode setup_HTM_MODE(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target,
    const uint8_t i_traceType)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_uint8_attr = 0;
    uint32_t l_uint32_attr = 0;
    uint8_t l_pos = 0;

    // Setup data value to program HTM_MODE reg
    // Note:
    //    - i_traceType may be needed later when more trace type is supported.

    // Get the proc target to read common CHTM attribute settings
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc =
        i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    // Get the EX parent of this core to program the register
    fapi2::Target<fapi2::TARGET_TYPE_EX> l_ex =
        i_target.getParent<fapi2::TARGET_TYPE_EX>();

    // Enable HTM
    l_scomData.setBit<EX_HTM_MODE_HTMSC_ENABLE>();

    // ATTR_CHTM_HTMSC_MODE_CONTENT_SEL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_MODE_CONTENT_SEL, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_CHTM_HTMSC_MODE_CONTENT_SEL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_CHTM_HTMSC_MODE_CONTENT_SEL      0x%.8X", l_uint8_attr);
    l_scomData.insertFromRight<EX_HTM_MODE_HTMSC_CONTENT_SEL,
                               EX_HTM_MODE_HTMSC_CONTENT_SEL_LEN>
                               (l_uint8_attr);

    // ATTR_CHTM_HTMSC_MODE_CAPTURE
    // For CHTM IMA mode (Direct Memory Write), Capture mode bit 4 is used
    // to enable/disable IMA trace.  This bit will be controlled in
    // p9_htm_start/stop for IMA instead.

    // ATTR_HTMSC_MODE_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRAP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_WRAP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_WRAP                  0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_WRAP_DISABLE) ?
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_WRAP>() :
    l_scomData.setBit<EX_HTM_MODE_HTMSC_WRAP>();

    // ATTR_HTMSC_MODE_DIS_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_TSTAMP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_TSTAMP            0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_TSTAMP_DISABLE) ?
    l_scomData.setBit<EX_HTM_MODE_HTMSC_DIS_TSTAMP>() :
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_DIS_TSTAMP>();

    // ATTR_HTMSC_MODE_SINGLE_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SINGLE_TSTAMP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_SINGLE_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_SINGLE_TSTAMP         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_SINGLE_TSTAMP_DISABLE) ?
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_SINGLE_TSTAMP>() :
    l_scomData.setBit<EX_HTM_MODE_HTMSC_SINGLE_TSTAMP>();

    // ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL_DISABLE) ?
    l_scomData.setBit<EX_HTM_MODE_HTMSC_DIS_STALL>() :
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_DIS_STALL>();

    // ATTR_HTMSC_MODE_MARKERS_ONLY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_MARKERS_ONLY, l_proc, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_MARKERS_ONLY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_MARKERS_ONLY          0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_MARKERS_ONLY_DISABLE) ?
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_MARKERS_ONLY>() :
    l_scomData.setBit<EX_HTM_MODE_HTMSC_MARKERS_ONLY>();

    // ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE,
                           l_proc, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE, "
             "l_rc 0x%.8X",  (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE_DISABLE) ?
    l_scomData.clearBit<EX_HTM_MODE_HTMSC_DIS_GROUP>() :
    l_scomData.setBit<EX_HTM_MODE_HTMSC_DIS_GROUP>();

    // ATTR_HTMSC_MODE_VGTARGET
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_VGTARGET, l_proc,
                           l_uint32_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_VGTARGET, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_VGTARGET              0x%.8X", l_uint32_attr);
    l_scomData.insertFromRight<EX_HTM_MODE_HTMSC_VGTARGET,
                               EX_HTM_MODE_HTMSC_VGTARGET_LEN>
                               (l_uint32_attr);

    // Display HTM_MODE reg setup value
    FAPI_INF("setup_HTM_MODE: HTM_MODE reg setup: 0x%016llX", l_scomData);

    // Write to HW
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_pos),
             "Error getting ATTR_CHIP_UNIT_POS");
    FAPI_TRY(fapi2::putScom(l_ex, CHTM_modeReg[l_pos % 2] + HTM_MODE, l_scomData),
             "setup_HTM_MODE: putScom returns error: "
             "Addr 0x%016llX, l_rc 0x%.8X",
             CHTM_modeReg[l_pos % 2] + HTM_MODE, (uint64_t)fapi2::current_err);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}


///
/// @brief Verify HTM engine is in correct state before setting up.
///
/// @tparam T template parameter, passed in target.
/// @param[in] i_target            Reference to HW target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode checkHtmState(const fapi2::Target<T>& i_target);

///
/// TARGET_TYPE_PROC_CHIP (NHTM trace)
///
template<>
fapi2::ReturnCode checkHtmState(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    fapi2::buffer<uint64_t> l_scomData_2(0);

    // Read HTM_STATE
    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[0] + HTM_STAT,
                            l_scomData),
             "checkHtmState: getScom returns error: Addr 0x%016llX, "
             "l_rc 0x%.8X", NHTM_modeRegList[0] + HTM_STAT,
             (uint64_t)fapi2::current_err);

    FAPI_TRY(fapi2::getScom(i_target, NHTM_modeRegList[1] + HTM_STAT,
                            l_scomData_2),
             "checkHtmState: getScom returns error: Addr 0x%016llX, "
             "l_rc 0x%.8X", NHTM_modeRegList[1] + HTM_STAT,
             (uint64_t)fapi2::current_err);

    // HTM must be in "Complete", "Repair", or "Blank" state
    // Bit positions are same for HTM0 and HTM1
    FAPI_ASSERT( ( (l_scomData == 0) && (l_scomData_2 == 0) ) ||  // Blank
                 ( l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_COMPLETE>() &&
                   l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_COMPLETE>() ) ||
                 ( l_scomData.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_REPAIR>() &&
                   l_scomData_2.getBit<PU_HTM0_HTM_STAT_HTMCO_STATUS_REPAIR>() ),
                 fapi2::P9_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG_NHTM0(l_scomData)
                 .set_HTM_STATUS_REG_NHTM1(l_scomData_2),
                 "checkHtmState: Can not setup HTM with current HTM state "
                 "NHTM0 status 0x%016llX, NHTM1 status 0x%016llX",
                 l_scomData, l_scomData_2);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// TARGET_TYPE_CORE (CHTM trace)
///
template<>
fapi2::ReturnCode checkHtmState(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_scomData(0);
    uint8_t l_pos = 0;

    // Get the EX parent of this core
    fapi2::Target<fapi2::TARGET_TYPE_EX> l_ex =
        i_target.getParent<fapi2::TARGET_TYPE_EX>();

    // Get the core position
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_pos),
             "Error getting ATTR_CHIP_UNIT_POS");

    // Read HTM_STATE
    FAPI_TRY(fapi2::getScom(l_ex, CHTM_modeReg[l_pos % 2] + HTM_STAT, l_scomData),
             "checkHtmState: getScom returns error: Addr 0x%016llX, "
             "l_rc 0x%.8X", CHTM_modeReg[l_pos % 2] + HTM_STAT,
             (uint64_t)fapi2::current_err);

    // HTM must be in "Complete", "Repair", or "Blank" state
    FAPI_ASSERT( (l_scomData == 0) ||
                 (l_scomData.getBit<EX_HTM_STAT_HTMCO_STATUS_COMPLETE>()) ||
                 (l_scomData.getBit<EX_HTM_STAT_HTMCO_STATUS_REPAIR>()),
                 fapi2::P9_CHTM_CTRL_BAD_STATE()
                 .set_TARGET(l_ex)
                 .set_HTM_STATUS_REG(l_scomData),
                 "checkHtmState: Can not setup HTM with current HTM state "
                 "0x%016llX", l_scomData);

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief Get trace types from attributes and verify they are valid.
///
///
/// @param[in]  i_target           Reference to processor chip target
/// @param[out] o_nhtmTraceType    NHTM trace type
/// @param[out] o_chtmTraceType    CHTM trace type
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode getTraceTypes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint8_t& o_nhtmTraceType,
    uint8_t o_chtmTraceType[])
{
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    uint8_t l_chtmTraceType[NUM_CHTM_ENGINES];

    // Display target
    fapi2::toString(i_target, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);
    FAPI_INF("Target %s: HTM setup attributes", l_targetStr);

    // Get ATTR_NHTM_TRACE_TYPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_TRACE_TYPE, i_target,
                           o_nhtmTraceType),
             "getTraceTypes: Error getting ATTR_NHTM_TRACE_TYPE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Show NHTM trace type
    FAPI_INF("    NHTM type: %u", o_nhtmTraceType);

    // Currently only support NHTM FABRIC type
    FAPI_ASSERT( (o_nhtmTraceType == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE) ||
                 (o_nhtmTraceType == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_FABRIC),
                 fapi2::NHTM_TRACE_TYPE_NOT_SUPPORTED()
                 .set_NHTM_TRACE_TYPE(o_nhtmTraceType),
                 "getTraceTypes: NHTM trace type is not supported: "
                 "0x%.8X", o_nhtmTraceType);

    // Get ATTR_CHTM_TRACE_TYPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_TRACE_TYPE, i_target,
                           l_chtmTraceType),
             "getTraceTypes: Error getting ATTR_CHTM_TRACE_TYPE, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    memcpy(o_chtmTraceType, l_chtmTraceType, sizeof(l_chtmTraceType));

    // Show CHTM trace type
    for (uint8_t ii = 0; ii < NUM_CHTM_ENGINES; ii++)
    {
        FAPI_INF("    CHTM type: Core[%u] %u", ii, o_chtmTraceType[ii]);
    }

    // Verify each core trace type, all so set flag
    // to indicate if any core trace is enabled.
    for (uint8_t ii = 0; ii < NUM_CHTM_ENGINES; ii++)
    {
        if (o_chtmTraceType[ii] != fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
        {
            // Currently only support CHTM DMW (IMA) type
            FAPI_ASSERT( (o_chtmTraceType[ii] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE) ||
                         (o_chtmTraceType[ii] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW),
                         fapi2::CHTM_TRACE_TYPE_NOT_SUPPORTED()
                         .set_CORE_POS(ii)
                         .set_CHTM_TRACE_TYPE(o_chtmTraceType[ii]),
                         "getTraceTypes: CHTM trace type is not supported: "
                         "Core #%u, TraceType 0x%.8X", ii, o_chtmTraceType[ii]);
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C" {

///
/// @brief p9_htm_setup procedure entry point
/// See doxygen in p9_htm_setup.H
///
    fapi2::ReturnCode p9_htm_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_start)
    {
        FAPI_INF("Entering p9_htm_setup");
        fapi2::ReturnCode l_rc;
        uint8_t l_nhtmType = 0;
        uint8_t l_chtmType[NUM_CHTM_ENGINES];
        uint8_t l_corePos = 0;
        auto l_coreChiplets = i_target.getChildren<fapi2::TARGET_TYPE_CORE>();
        bool l_htmEnabled = false;

        // ----------------------------------------------
        // Check if NTHM/CHTM trace is enabled
        // ----------------------------------------------
        FAPI_TRY(getTraceTypes(i_target, l_nhtmType, l_chtmType),
                 "isTraceEnabled() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // ----------------------------------------------
        // Setup NHTM trace
        // ----------------------------------------------
        if (l_nhtmType != fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_DISABLE)
        {
            l_htmEnabled = true;

            // 1. Check HW state
            FAPI_TRY(checkHtmState(i_target),
                     "checkHtmState() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // 2. Setup HTM_MODE reg
            FAPI_TRY(setup_HTM_MODE(i_target, l_nhtmType),
                     "setup_HTM_MODE() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // 3. Setup HTM_MEM reg
            FAPI_TRY(setup_HTM_MEM(i_target),
                     "setup_HTM_MODE() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // 4. Setup HTM_CTRL reg
            FAPI_TRY(setup_HTM_CTRL(i_target),
                     "setup_HTM_CTRL() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // 5. Setup NHTM_FILT reg
            FAPI_TRY(setup_NHTM_FILT(i_target),
                     "setup_NHTM_FILT() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // 6. Setup NHTM_TTYPE_FILT reg (FABRIC trace type only)
            if (l_nhtmType == fapi2::ENUM_ATTR_NHTM_TRACE_TYPE_FABRIC)
            {
                FAPI_TRY(setup_NHTM_TTYPE_FILT(i_target),
                         "setup_NHTM_TTYPE_FILT() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

        // ----------------------------------------------
        // Setup CHTM trace
        // ----------------------------------------------
        for (auto l_core : l_coreChiplets)
        {
            // Note:
            //   - PHYP will setup CHTM IMA trace, nothing to do during IPL.
            //   - IMA setup code is left here for reference only.  It should
            //     not be invoked unless ATTR_CHTM_TRACE_TYPE = DMW.
            //   - Other CHTM trace types are not supported until Nimbus DD2.0.
            //     ATTR_CHTM_TRACE_TYPE should be DISABLE for Nimbus 1.0.

            // Get the core position
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_core, l_corePos),
                     "Error getting ATTR_CHIP_UNIT_POS");

            // Skip if CHTM is disable on this core
            if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DISABLE)
            {
                continue;
            }

            l_htmEnabled = true;
            FAPI_INF("p9_htm_setup: Setup CHTM for core unit %u", l_corePos);

            // 1. Check HW state
            FAPI_TRY(checkHtmState(l_core),
                     "checkHtmState() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // DMW (IMA) trace type only
            if (l_chtmType[l_corePos] == fapi2::ENUM_ATTR_CHTM_TRACE_TYPE_DMW)
            {
                // 2. Setup CHTM_PDBAR reg
                FAPI_TRY(setup_CHTM_PDBAR(l_core),
                         "setup_CHTM_PDBAR() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);

                // 3. Setup IMA_EVENT_MASK
                FAPI_TRY(setup_IMA_EVENT_MASK(l_core),
                         "setup_CHTM_PDBAR() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }

            // 4. Setup HTM_MODE reg
            FAPI_TRY(setup_HTM_MODE(l_core, l_chtmType[l_corePos]),
                     "setup_HTM_MODE() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);
        }

        // Perform reset/start only if certain trace is enabled.
        if (l_htmEnabled == true)
        {
            // ----------------------------------------------
            // Reset HTMs
            // ----------------------------------------------
            FAPI_TRY(p9_htm_reset(i_target),
                     "p9_htm_reset() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ----------------------------------------------
            // Start collect both NHTM and CHTM traces
            // ----------------------------------------------
            if (i_start == true)
            {
                FAPI_TRY(p9_htm_start(i_target),
                         "p9_htm_start() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p9_htm_setup");
        return fapi2::current_err;
    }

} // extern "C"
