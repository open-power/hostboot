/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_htm_setup.C $    */
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
///----------------------------------------------------------------------------
/// @file  p10_htm_setup.C
///
/// @brief Perform p10_htm_setup on a processor chip
///
/// The purpose of this procedure is to setup and start HTM on a processor
/// chip.
/// Some start/setup attributes are used as part of the setup process.
///
///----------------------------------------------------------------------------
/// *HWP HWP Owner   : Nicholas Landi <nlandi@ibm.com>
/// *HWP FW Owner    : Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by : HB
///----------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_mss_eff_grouping.H>
#include <p10_htm_setup.H>
#include <p10_htm_def.H>
#include <p10_htm_start.H>
#include <p10_htm_reset.H>
#include <p10_scom_proc.H>
#include <p10_scom_c.H>
#include <p10_scom_mcc.H>

///----------------------------------------------------------------------------
/// Constants
///----------------------------------------------------------------------------
const uint64_t IMA_EVENT_MASK_VALUE   = 0x0004008000000000;

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

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

///
/// @brief This function sets up CHTM_PDBAR reg for CHTM.
///
/// @param[in] i_target    Reference to core target
///
// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_CHTM_PDBAR(
    const fapi2::Target<fapi2::TARGET_TYPE_CORE>& i_target)
{
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_cHTM_pdbar(0);
    uint8_t l_uint8_attr = 0;
    uint64_t l_uint64_attr = 0;

    // Get the proc target to read attribute settings
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    FAPI_TRY(PREP_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(i_target));

    // P10 does not have Split Core functionality
    // ATTR_HTMSC_IMA_PDBAR_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_IMA_PDBAR_SCOPE, l_proc,
                           l_uint8_attr),
             "setup_CHTM_PDBAR: Error getting ATTR_HTMSC_IMA_PDBAR_SCOPE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_IMA_PDBAR_SCOPE 0x%.8X", l_uint8_attr);
    SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR_SCOPE(l_uint8_attr, l_cHTM_pdbar);

    // ATTR_HTMSC_IMA_PDBAR_ADDR
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_IMA_PDBAR_ADDR, l_proc,
                           l_uint64_attr),
             "setup_CHTM_PDBAR: Error getting ATTR_HTMSC_IMA_PDBAR_ADDR, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_IMA_PDBAR_ADDR 0x%.16llX", l_uint64_attr);
    SET_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR_HTMSC_IMA_PDBAR(l_uint64_attr, l_cHTM_pdbar);


    FAPI_INF("setupChtm: CHTM_PDBAR reg setup: 0x%016llX", l_cHTM_pdbar);
    //// Write HW
    FAPI_TRY(PUT_NC_NCCHTM_NCCHTSC_HTM_IMA_PDBAR(i_target, l_cHTM_pdbar));

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
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_mask_data(IMA_EVENT_MASK_VALUE);

    // Display IMA_EVENT_MASK reg setup value
    FAPI_INF("setupChtm: IMA_EVENT_MASK reg setup: 0x%016llX", l_mask_data);

    //// Write HW
    FAPI_TRY(PREP_EC_PC_IMA_EVENT_MASK(i_target));
    FAPI_TRY(PUT_EC_PC_IMA_EVENT_MASK(i_target, l_mask_data));

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
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_nHTM_filt_data(0);
    fapi2::buffer<uint64_t> l_nHTM_t_filt_data(0);
    fapi2::buffer<uint64_t> l_nHTM_filt_addr_data(0);
    bool l_stop_on_match = 0;
    uint8_t l_HTM_mode = 0;
    uint32_t l_uint32_attr = 0;
    uint64_t mask_dummy = 0xFFFFFFFFFFFFFFFF;

    // Only program OCC bits if OCC trace mode
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CONTENT_SEL, i_target, l_HTM_mode),
             "setup_NHTM_FILT: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);

    if (l_HTM_mode == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CONTENT_SEL_OCC)
    {
        l_stop_on_match = false;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_OCC_PAT, i_target, l_uint32_attr),
                 "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_OCC_PAT, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        l_nHTM_filt_data |= static_cast<uint64_t>(l_uint32_attr) << 32;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_FILT_OCC_MASK, i_target, l_uint32_attr),
                 "setup_NHTM_FILT: Error getting ATTR_HTMSC_FILT_OCC_MASK, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);
        l_nHTM_filt_data |= l_uint32_attr;
        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_FILT(i_target, l_nHTM_filt_data));
    }
    else if (l_HTM_mode == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_CONTENT_SEL_FABRIC)
    {
        HTM_FILT_attrs_t l_HTM_FILT;
        FAPI_TRY(l_HTM_FILT.getAttrs(i_target),
                 "l_HTM_FILT.getAttrs() returns an error, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        l_stop_on_match = l_HTM_FILT.iv_filtStopOnMatch;

        if (l_stop_on_match)
        {
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(i_target, l_nHTM_filt_data));
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(i_target, l_nHTM_filt_addr_data));

            // Stop filter reg
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CYCLES(l_HTM_FILT.iv_filtStopCycles, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_PAT(l_HTM_FILT.iv_filtTtagPat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK(~l_HTM_FILT.iv_filtTtagMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_PAT(l_HTM_FILT.iv_filtTtypePat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK(~l_HTM_FILT.iv_filtTtypeMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_PAT(l_HTM_FILT.iv_filtCrespPat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK(~l_HTM_FILT.iv_filtCrespMask, l_nHTM_filt_data);
            // Display NHTM_FILT reg setup value
            FAPI_INF("setup_NHTM_FILT: NHTM_STOP_FILT reg setup: 0x%016llX", l_nHTM_filt_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(i_target, l_nHTM_filt_data));

            //Addr Pat
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT_HTMSC_STOP_ADDR_PAT(l_HTM_FILT.iv_filtAddrPat, l_nHTM_filt_addr_data);
            FAPI_INF("setup_NHTM_FILT: NHTM_STOP_ADDR_PAT reg setup: 0x%016llX", l_nHTM_filt_addr_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_PAT(i_target, l_nHTM_filt_addr_data)) ;

            // Addr Mask
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(i_target, l_nHTM_filt_addr_data));
            SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK(~l_HTM_FILT.iv_filtAddrMask, l_nHTM_filt_addr_data);
            FAPI_INF("setup_NHTM_FILT: NHTM_STOP_ADDR_MASK reg setup: 0x%016llX", l_nHTM_filt_addr_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(i_target, l_nHTM_filt_addr_data));

        }
        else
        {
            // Filt Reg
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_FILT(i_target, l_nHTM_filt_data));
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_PAT(l_HTM_FILT.iv_filtTtagPat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK(~l_HTM_FILT.iv_filtTtagMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_PAT(l_HTM_FILT.iv_filtCrespPat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_PAT(l_HTM_FILT.iv_filtScopePat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_PAT(l_HTM_FILT.iv_filtSourcePat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_PAT(l_HTM_FILT.iv_filtPortPat, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK(~l_HTM_FILT.iv_filtScopeMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK(~l_HTM_FILT.iv_filtSourceMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK(~l_HTM_FILT.iv_filtPortMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK(~l_HTM_FILT.iv_filtCrespMask, l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK((mask_dummy & 0x3), l_nHTM_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK((mask_dummy & 0xF), l_nHTM_filt_data);

            (l_HTM_FILT.iv_filtFiltInvert == fapi2::ENUM_ATTR_HTMSC_TTAGFILT_INVERT_MATCH) ?
            CLEAR_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(l_nHTM_filt_data) :
            SET_PB_BRIDGE_NHTM_SC_HTM_FILT_TTAGFILT_INVERT(l_nHTM_filt_data);

            // Display NHTM_FILT reg setup value
            FAPI_INF("setup_NHTM_FILT: NHTM_FILT reg setup: 0x%016llX", l_nHTM_filt_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_FILT(i_target, l_nHTM_filt_data));

            //Addr Pat
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(i_target, l_nHTM_filt_addr_data));
            SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT_HTMSC_FILT_ADDR_PAT(l_HTM_FILT.iv_filtAddrPat, l_nHTM_filt_addr_data);
            FAPI_INF("setup_NHTM_FILT: NHTM_STOP_ADDR_PAT reg setup: 0x%016llX", l_nHTM_filt_addr_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_PAT(i_target, l_nHTM_filt_addr_data));

            //Addr Mask
            FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(i_target, l_nHTM_filt_addr_data));
            SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(~l_HTM_FILT.iv_filtAddrMask, l_nHTM_filt_addr_data);
            FAPI_INF("setup_NHTM_FILT: NHTM_STOP_ADDR_MASK reg setup: 0x%016llX", l_nHTM_filt_addr_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(i_target, l_nHTM_filt_addr_data));

            //Ttype Filt reg
            FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(i_target));
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_PAT(l_HTM_FILT.iv_filtTtypePat, l_nHTM_t_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_PAT(l_HTM_FILT.iv_filtTsizePat, l_nHTM_t_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK(~l_HTM_FILT.iv_filtTtypeMask, l_nHTM_t_filt_data);
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK(~l_HTM_FILT.iv_filtTsizeMask, l_nHTM_t_filt_data);

            (l_HTM_FILT.iv_filtTtypeFiltInvert == fapi2::ENUM_ATTR_HTMSC_TTYPEFILT_INVERT_MATCH) ?
            CLEAR_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(l_nHTM_t_filt_data) :
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_INVERT(l_nHTM_t_filt_data);

            (l_HTM_FILT.iv_filtCrespFiltInvert == fapi2::ENUM_ATTR_HTMSC_CRESPFILT_INVERT_MATCH) ?
            CLEAR_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(l_nHTM_t_filt_data) :
            SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_CRESPFILT_INVERT(l_nHTM_t_filt_data);

            // Display NHTM_TTYPE_FILT reg setup value
            FAPI_INF("setupNhtm: NHTM_TTYPE_FILT reg setup: 0x%016llX", l_nHTM_t_filt_data);
            FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(i_target, l_nHTM_t_filt_data));


        }

    }

    // Mask filters of registers not programmed
    l_nHTM_filt_data = 0;
    l_nHTM_filt_addr_data = 0;

    // Display NHTM_TTYPE_FILT reg setup value
    FAPI_INF("Masking unneeded filt regs:");

    // Mask appropriate registers
    if (l_stop_on_match)
    {
        FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_FILT(i_target));
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_TTAG_MASK  (mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SCOPE_MASK (mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_SOURCE_MASK(mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_PORT_MASK  (mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_CRESP_MASK (mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC15TO16_MASK(mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_FILT_FILT_OCC23TO26_MASK(mask_dummy, l_nHTM_filt_data);

        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_FILT(i_target, l_nHTM_filt_data));

        FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(i_target));
        SET_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK_HTMSC_FILT_ADDR_MASK(mask_dummy, l_nHTM_filt_addr_data);
        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_ADDR_MASK(i_target, l_nHTM_filt_addr_data));

        FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(i_target));
        SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TTYPEFILT_MASK(mask_dummy, l_nHTM_t_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT_TSIZEFILT_MASK(mask_dummy, l_nHTM_t_filt_data);
        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_TTYPEFILT(i_target, l_nHTM_t_filt_data));
    }
    else
    {
        FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER (i_target));
        SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTAG_MASK (mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_TTYPE_MASK(mask_dummy, l_nHTM_filt_data);
        SET_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER_CRESP_MASK(mask_dummy, l_nHTM_filt_data);
        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_FILTER(i_target, l_nHTM_filt_data));

        FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(i_target));
        SET_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK_HTMSC_STOP_ADDR_MASK(mask_dummy, l_nHTM_filt_addr_data);
        FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_STOP_ADDR_MASK(i_target, l_nHTM_filt_addr_data));
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
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_nHTM_ctrl_data(0);
    HTM_CTRL_attrs_t l_HTM_CTRL;

    // Get the proc attributes needed to perform HTM_CTRL setup
    FAPI_TRY(l_HTM_CTRL.getAttrs(i_target),
             "l_HTM_CTRL.getAttrs() returns an error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_CTRL(i_target));

    // Set CTRL_TRIG
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_TRIG(l_HTM_CTRL.iv_nhtmCtrlTrig, l_nHTM_ctrl_data);

    // Set CTRL_MARK
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_MARK(l_HTM_CTRL.iv_nhtmCtrlMark, l_nHTM_ctrl_data);

    // Set CTRL_DBG0_STOP
    (l_HTM_CTRL.iv_ctrlDbg0Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG0_STOP_ENABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_DBG0_STOP(l_nHTM_ctrl_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_CTRL_DBG0_STOP(l_nHTM_ctrl_data);

    // Set CTRL_DBG1_STOP
    (l_HTM_CTRL.iv_ctrlDbg1Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_DBG1_STOP_ENABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_DBG1_STOP(l_nHTM_ctrl_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_CTRL_DBG1_STOP(l_nHTM_ctrl_data);

    // Set CTRL_RUN_STOP
    (l_HTM_CTRL.iv_ctrlRunStop == fapi2::ENUM_ATTR_HTMSC_CTRL_RUN_STOP_ENABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_RUN_STOP(l_nHTM_ctrl_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_CTRL_RUN_STOP(l_nHTM_ctrl_data);

    // Set CTRL_OTHER_DBG0_STOP
    (l_HTM_CTRL.iv_ctrlOtherDbg0Stop == fapi2::ENUM_ATTR_HTMSC_CTRL_OTHER_DBG0_STOP_ENABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_OTHER_DBG0_STOP(l_nHTM_ctrl_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_CTRL_OTHER_DBG0_STOP(l_nHTM_ctrl_data);

    // Set CTRL_XSTOP_STOP
    (l_HTM_CTRL.iv_ctrlXstopStop == fapi2::ENUM_ATTR_HTMSC_CTRL_XSTOP_STOP_ENABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_CTRL_XSTOP_STOP(l_nHTM_ctrl_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_CTRL_XSTOP_STOP(l_nHTM_ctrl_data);

    // Display HTM_CTRL reg setup value
    FAPI_INF("setup_HTM_CTRL: HTM_CTRL reg setup: 0x%016llX", l_nHTM_ctrl_data);

    // Write data to HTM_CTRL
    // Program both NHTM0 and NHTM1
    FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_CTRL(i_target, l_nHTM_ctrl_data));

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
    // Place holder for other CHTM trace setup when they are supported.

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
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_HTM_mem_data;
    uint8_t l_uint8_attr = 0;
    htm_size_t l_barHtmSize;
    bool l_smallSize;
    uint64_t l_barAddr;
    uint64_t l_barSize;

    FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_MEM(i_target));

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

    l_HTM_mem_data = 0;

    // ATTR_HTMSC_MEM_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_SCOPE, i_target, l_uint8_attr),
             "setup_HTM_MEM: Error getting ATTR_HTMSC_MEM_SCOPE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MEM_SCOPE            0x%.8X", l_uint8_attr);
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SCOPE(l_uint8_attr, l_HTM_mem_data);

    // ATTR_HTMSC_MEM_PRIORITY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MEM_PRIORITY, i_target, l_uint8_attr),
             "setup_HTM_MEM: Error getting ATTR_HTMSC_MEM_PRIORITY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MEM_PRIORITY         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MEM_PRIORITY_LOW) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(l_HTM_mem_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_PRIORITY(l_HTM_mem_data);

    // Set base addr
    // Right shift PROC HTM Bar Base addr 24 bits to align to 16MB trace memory.
    FAPI_DBG("  ATTR_PROC_NHTM_BAR_BASE_ADDR 0x%.16llX", l_barAddr);
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_BASE(l_barAddr >> 24, l_HTM_mem_data);

    // Get HTM size
    FAPI_TRY(getTraceMemSizeValues(l_barSize, l_barHtmSize, l_smallSize),
             "getTraceMemSizeValues() returns error, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    // Set bar size (ATTR_PROC_NHTM_BAR_SIZES)
    FAPI_DBG("  ATTR_PROC_NHTM_BAR_SIZE  0x%.16llX", l_barSize);
    FAPI_DBG("  HTMSC_SIZE 0x%.16llX", l_barHtmSize);
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE(l_barHtmSize, l_HTM_mem_data);

    // Set mem size
    FAPI_DBG("  Small Mem Size          0x%.8X", (uint32_t)l_smallSize);
    (l_smallSize == true) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(l_HTM_mem_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_SIZE_SMALL(l_HTM_mem_data);

    // Display HTM_MEM value to write to HW
    FAPI_INF("setup_HTM_MEM: HTM_MEM reg setup: 0x%016llX", l_HTM_mem_data);

    // Write config data into HTM_MEM
    // MEM_ALLOC must switch from 0->1 for this setup to complete
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(l_HTM_mem_data);
    FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_MEM(i_target, l_HTM_mem_data));
    SET_PB_BRIDGE_NHTM_SC_HTM_MEM_ALLOC(l_HTM_mem_data);
    FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_MEM(i_target, l_HTM_mem_data));

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
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_HTM_mode_data(0);
    uint8_t l_uint8_attr = 0;
    uint16_t l_uint16_attr = 0;
    uint32_t l_uint32_attr = 0;

    // Setup data value to program HTM_MODE reg
    // Note:
    //    - i_traceType may be needed later when more trace type is supported.

    // Enable HTM
    FAPI_TRY(PREP_PB_BRIDGE_NHTM_SC_HTM_MODE(i_target));
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_HTM_ENABLE(l_HTM_mode_data);

    // ATTR_NHTM_HTMSC_MODE_CONTENT_SEL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CONTENT_SEL, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CONTENT_SEL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CONTENT_SEL      0x%.8X", l_uint8_attr);
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CONTENT_SEL(l_uint8_attr, l_HTM_mode_data);

    // ATTR_NHTM_HTMSC_MODE_CAPTURE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_CAPTURE,
                           i_target, l_uint16_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_CAPTURE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_CAPTURE          0x%.8X", l_uint16_attr);

    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_CAPTURE(l_uint16_attr, l_HTM_mode_data);

    // ATTR_HTMSC_MODE_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRAP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_WRAP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_WRAP                  0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_WRAP_DISABLE) ?
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(l_HTM_mode_data) :
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRAP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_DIS_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_TSTAMP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_TSTAMP            0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_TSTAMP_DISABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(l_HTM_mode_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_TSTAMP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_SINGLE_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SINGLE_TSTAMP, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_SINGLE_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_SINGLE_TSTAMP         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_SINGLE_TSTAMP_DISABLE) ?
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(l_HTM_mode_data) :
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SINGLE_TSTAMP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_MARKERS_ONLY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_MARKERS_ONLY, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_MARKERS_ONLY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_MARKERS_ONLY          0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_MARKERS_ONLY_DISABLE) ?
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(l_HTM_mode_data) :
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_MARKERS_ONLY(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE, "
             "l_rc 0x%.8X",  (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE_DISABLE) ?
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(l_HTM_mode_data) :
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_DIS_FORCE_GROUP_SCOPE(l_HTM_mode_data);

    // ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE, i_target,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_SYNC_STAMP_FORCE 0x%.8X", l_uint8_attr);
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_SYNC_STAMP_FORCE(l_uint8_attr, l_HTM_mode_data);

    // ATTR_NHTM_HTMSC_MODE_WRITETOIO
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NHTM_HTMSC_MODE_WRITETOIO,
                           i_target, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_NHTM_HTMSC_MODE_WRITETOIO, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_NHTM_HTMSC_MODE_WRITETOIO        0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_NHTM_HTMSC_MODE_WRITETOIO_DISABLE) ?
    CLEAR_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(l_HTM_mode_data) :
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_WRITETOIO(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_VGTARGET
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_VGTARGET, i_target,
                           l_uint32_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_VGTARGET, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_VGTARGET              0x%.8X", l_uint32_attr);
    SET_PB_BRIDGE_NHTM_SC_HTM_MODE_TMSC_MODE_VGTARGET(~l_uint32_attr, l_HTM_mode_data);

    // Display HTM_MODE reg setup value
    FAPI_INF("setup_HTM_MODE: HTM_MODE reg setup: 0x%016llX", l_HTM_mode_data);

    // Put data
    FAPI_TRY(PUT_PB_BRIDGE_NHTM_SC_HTM_MODE(i_target, l_HTM_mode_data));

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
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_HTM_mode_data(0);
    uint8_t l_uint8_attr = 0;
    uint32_t l_uint32_attr = 0;

    // Setup data value to program HTM_MODE reg
    // Note:
    //    - i_traceType may be needed later when more trace type is supported.

    // Get the proc target to read common CHTM attribute settings
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_proc = i_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();

    // Enable HTM
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_HTM_ENABLE(l_HTM_mode_data);

    // ATTR_CHTM_HTMSC_MODE_CONTENT_SEL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_MODE_CONTENT_SEL, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_CHTM_HTMSC_MODE_CONTENT_SEL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_CHTM_HTMSC_MODE_CONTENT_SEL      0x%.8X", l_uint8_attr);
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_CONTENT_SEL(l_uint8_attr, l_HTM_mode_data);

    // ATTR_CHTM_HTMSC_MODE_CAPTURE
    // For CHTM IMA mode (Direct Memory Write), Capture mode bit 4 is used
    // to enable/disable IMA trace.  This bit will be controlled in
    // p10_htm_start/stop for IMA instead.

    // ATTR_HTMSC_MODE_WRAP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_WRAP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_WRAP, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_WRAP                  0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_WRAP_DISABLE) ?
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(l_HTM_mode_data) :
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_WRAP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_DIS_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_TSTAMP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_TSTAMP            0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_TSTAMP_DISABLE) ?
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(l_HTM_mode_data) :
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_TSTAMP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_SINGLE_TSTAMP
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_SINGLE_TSTAMP, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_SINGLE_TSTAMP, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_SINGLE_TSTAMP         0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_SINGLE_TSTAMP_DISABLE) ?
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(l_HTM_mode_data) :
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_SINGLE_TSTAMP(l_HTM_mode_data);

    // ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL, l_proc,
                           l_uint8_attr),
             "setup_HTM_MODE: Error gettting ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL           0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_CHTM_HTMSC_MODE_CORE_INSTR_STALL_DISABLE) ?
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(l_HTM_mode_data) :
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_STALL(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_MARKERS_ONLY
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_MARKERS_ONLY, l_proc, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_MARKERS_ONLY, "
             "l_rc 0x%.8X", (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_MARKERS_ONLY          0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_MARKERS_ONLY_DISABLE) ?
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(l_HTM_mode_data) :
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_MARKERS_ONLY(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE,
                           l_proc, l_uint8_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE, "
             "l_rc 0x%.8X",  (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE 0x%.8X", l_uint8_attr);
    (l_uint8_attr == fapi2::ENUM_ATTR_HTMSC_MODE_DIS_FORCE_GROUP_SCOPE_DISABLE) ?
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(l_HTM_mode_data) :
    CLEAR_NC_NCCHTM_NCCHTSC_HTM_MODE_DIS_GROUP(l_HTM_mode_data);

    // ATTR_HTMSC_MODE_VGTARGET
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTMSC_MODE_VGTARGET, l_proc,
                           l_uint32_attr),
             "setup_HTM_MODE: Error getting ATTR_HTMSC_MODE_VGTARGET, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);
    FAPI_DBG("  ATTR_HTMSC_MODE_VGTARGET              0x%.8X", l_uint32_attr);
    SET_NC_NCCHTM_NCCHTSC_HTM_MODE_VGTARGET(~l_uint32_attr, l_HTM_mode_data);

    // Display HTM_MODE reg setup value
    FAPI_INF("setup_HTM_MODE: HTM_MODE reg setup: 0x%016llX", l_HTM_mode_data);

    // Write to HW
    FAPI_TRY(PUT_NC_NCCHTM_NCCHTSC_HTM_MODE(i_target, l_HTM_mode_data));

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
    using namespace scomt;
    using namespace scomt::proc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_HTM_stat_data(0);

    // Read HTM_STATE
    FAPI_TRY(GET_PB_BRIDGE_NHTM_SC_HTM_STAT(i_target, l_HTM_stat_data));

    // HTM must be in "Complete", "Repair", or "Blank" state
    FAPI_ASSERT( ( (l_HTM_stat_data == 0) ) ||  // Blank
                 ( GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_COMPLETE(l_HTM_stat_data) &&
                   GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_COMPLETE(l_HTM_stat_data)) ||
                 ( GET_PB_BRIDGE_NHTM_SC_HTM_STAT_0_HTMCO_STATUS_REPAIR(l_HTM_stat_data) &&
                   GET_PB_BRIDGE_NHTM_SC_HTM_STAT_1_HTMCO_STATUS_REPAIR(l_HTM_stat_data) ),
                 fapi2::P10_NHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_HTM_stat_data),
                 "checkHtmState: Can not setup HTM with current HTM state "
                 "NHTM status 0x%016llX",
                 l_HTM_stat_data);

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
    using namespace scomt;
    using namespace scomt::c;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_HTM_stat_data(0);


    FAPI_TRY(GET_NC_NCCHTM_NCCHTSC_HTM_STAT(i_target, l_HTM_stat_data));

    // HTM must be in "Complete", "Repair", or "Blank" state
    FAPI_ASSERT( (l_HTM_stat_data == 0) ||
                 (GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_COMPLETE(l_HTM_stat_data)) ||
                 (GET_NC_NCCHTM_NCCHTSC_HTM_STAT_HTMCO_STATUS_REPAIR(l_HTM_stat_data)),
                 fapi2::P10_CHTM_CTRL_BAD_STATE()
                 .set_TARGET(i_target)
                 .set_HTM_STATUS_REG(l_HTM_stat_data),
                 "checkHtmState: Can not setup HTM with current HTM state "
                 "0x%016llX", l_HTM_stat_data);

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

///
/// @brief Setup the HTM queue reservation for each channel
///
/// @param[in]  i_target    Reference to processor chip target
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode setup_HTM_queues(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::mcc;
    FAPI_DBG("Entering");
    fapi2::ReturnCode l_rc;
    uint8_t l_numHtmQueues[NUM_MCC_PER_PROC];
    fapi2::buffer<uint64_t> l_mc_data(0);
    auto l_miChiplets = i_target.getChildren<fapi2::TARGET_TYPE_MCC>();

    // Get ATTR_HTM_QUEUES
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_HTM_QUEUES, i_target, l_numHtmQueues),
             "Error getting ATTR_HTM_QUEUES, l_rc 0x%.8X",
             (uint64_t)fapi2::current_err);

    for (uint8_t ii = 0; ii < NUM_MCC_PER_PROC; ii++)
    {
        FAPI_INF("ATTR_HTM_QUEUES[%u]: %d", ii, l_numHtmQueues[ii]);
    }

    for (auto l_port : l_miChiplets)
    {
        uint8_t l_unitPos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_port, l_unitPos),
                 "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                 (uint64_t)fapi2::current_err);

        // Queue reservation exists
        if (l_numHtmQueues[l_unitPos] > 0)
        {
            FAPI_TRY(GET_ATCL_CL_CLSCOM_MCPERF0(l_port, l_mc_data));

            //// HTM RESERVE (bits 16:19)
            SET_ATCL_CL_CLSCOM_MCPERF0_NUM_HTM_RSVD(l_numHtmQueues[l_unitPos], l_mc_data);

            //// Write to reg
            FAPI_INF("Write MCS_PORT02_MCPERF0 reg 0x%.16llX, Value 0x%.16llX",
                     ATCL_CL_CLSCOM_MCPERF0, l_mc_data);
            FAPI_TRY(PUT_ATCL_CL_CLSCOM_MCPERF0(l_port, l_mc_data));
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting");
    return fapi2::current_err;
}

extern "C" {

///
/// @brief p10_htm_setup procedure entry point
/// See doxygen in p10_htm_setup.H
///
    fapi2::ReturnCode p10_htm_setup(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const bool i_start)
    {
        FAPI_INF("Entering p10_htm_setup");
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
            FAPI_INF("p10_htm_setup: Setup CHTM for core unit %u", l_corePos);

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
            // Reserve HTM queues
            // ----------------------------------------------
            FAPI_TRY(setup_HTM_queues(i_target),
                     "setup_HTM_queues returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ----------------------------------------------
            // Reset HTMs
            // ----------------------------------------------
            FAPI_TRY(p10_htm_reset(i_target),
                     "p10_htm_reset() returns an error, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            // ----------------------------------------------
            // Start collect both NHTM and CHTM traces
            // ----------------------------------------------
            if (i_start == true)
            {
                FAPI_TRY(p10_htm_start(i_target),
                         "p10_htm_start() returns an error, l_rc 0x%.8X",
                         (uint64_t)fapi2::current_err);
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting p10_htm_setup");
        return fapi2::current_err;
    }

} // extern "C"
