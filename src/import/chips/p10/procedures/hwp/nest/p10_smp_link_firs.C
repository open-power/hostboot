/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_smp_link_firs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
///
/// @file p10_smp_link_firs.H
/// @brief Setup the FIR mask and action registers for a given SMP link
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
/// *HWP Consumed by: SBE
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_smp_link_firs.H>
#include <p10_fbc_utils.H>
#include <target_filters.H>

#include <p10_scom_proc.H>
#include <p10_scom_pauc.H>
#include <p10_scom_iohs.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// Struct that contains the bits to modify (btm) in a fir
// register for a given IOHS link (and sublink if applicable)
struct fir_registers_btm
{
    uint64_t EXT_FIR[FABRIC_NUM_IOHS_LINKS];
    uint64_t PTL_FIR[NUM_SUBLINK_OPTS];
    uint64_t DLP_FIR[NUM_SUBLINK_OPTS];
    uint64_t PHY_FIR[FABRIC_NUM_IOHS_LINKS];
};

const struct fir_registers_btm firs_btm =
{
    .EXT_FIR =
    {
        0x8000000000000000, // AX0
        0x4000000000000000, // AX1
        0x2000000000000000, // AX2
        0x1000000000000000, // AX3
        0x0800000000000000, // AX4
        0x0400000000000000, // AX5
        0x0200000000000000, // AX6
        0x0100000000000000, // AX7
    },
    .PTL_FIR =
    {
        0xCF0E332F0C000000, // BOTH_PAUE
        0x30F1CCD0F3000000, // BOTH_PAUO
        0x9FFCE67819000000, // BOTH_PAUS
        0x8F08222C08000000, // EVEN_PAUE
        0x20F18890C2000000, // EVEN_PAUO
        0x4F06112304000000, // ODD_PAUE
        0x10F0C45031000000, // ODD_PAUO
    },
    .DLP_FIR =
    {
        0xFFFFFFFFFFFFFFFF, // BOTH_PAUE
        0xFFFFFFFFFFFFFFFF, // BOTH_PAUO
        0xFFFFFFFFFFFFFFFF, // BOTH_PAUS
        0xAAAAAAAAAAAAAAAA, // EVEN_PAUE
        0xAAAAAAAAAAAAAAAA, // EVEN_PAUO
        0x5555555555555555, // ODD_PAUE
        0x5555555555555555, // ODD_PAUO
    },
    .PHY_FIR =
    {
        0x8800000000000000, // IOHS0
        0x4400000000000000, // IOHS1
        0x8800000000000000, // IOHS2
        0x4400000000000000, // IOHS3
        0x8800000000000000, // IOHS4
        0x4400000000000000, // IOHS5
        0x8800000000000000, // IOHS6
        0x4400000000000000, // IOHS7
    },
};

// Struct that contains the values to program in a fir register
// and the formed values (clr/set) to apply to mask registers
// based on a given IOHS (and sublink if applicable)
struct fir_registers
{
    uint64_t EXT_FIR_ACTION0;
    uint64_t EXT_FIR_ACTION1;
    uint64_t EXT_FIR_MASK;

    uint64_t PTL_FIR_ACTION0;
    uint64_t PTL_FIR_ACTION1;
    uint64_t PTL_FIR_MASK;

    uint64_t DLP_FIR_ACTION0;
    uint64_t DLP_FIR_ACTION1;
    uint64_t DLP_FIR_MASK;

    uint64_t PHY_FIR_ACTION0;
    uint64_t PHY_FIR_ACTION1;
    uint64_t PHY_FIR_MASK;

    uint64_t EXT_FIR_MASK_CLR;
    uint64_t EXT_FIR_MASK_SET;
    uint64_t PTL_FIR_MASK_CLR;
    uint64_t PTL_FIR_MASK_SET;
    uint64_t DLP_FIR_MASK_CLR;
    uint64_t DLP_FIR_MASK_SET;
    uint64_t PHY_FIR_MASK_CLR;
    uint64_t PHY_FIR_MASK_SET;
};

const struct fir_registers firs_inactive =
{
    .EXT_FIR_ACTION0 = 0x0000000000000000,
    .EXT_FIR_ACTION1 = 0x0000000000000000,
    .EXT_FIR_MASK    = 0xFFFFFFFFFFFFFFFF,

    .PTL_FIR_ACTION0 = 0xF220000FFFFFFFFF,
    .PTL_FIR_ACTION1 = 0xF660000FFFFFFFFF,
    .PTL_FIR_MASK    = 0xFFFFFFFFFFFFFFFF,

    .DLP_FIR_ACTION0 = 0xFCFC3FFFFCC00003,
    .DLP_FIR_ACTION1 = 0xFFFFFFFFFFFFFFFF,
    .DLP_FIR_MASK    = 0xFFFFFFFFFFFFFFFF,

    .PHY_FIR_ACTION0 = 0x0000000000000000,
    .PHY_FIR_ACTION1 = 0xFFFFDB0000000000,
    .PHY_FIR_MASK    = 0xFF00000000000000,
};

const struct fir_registers firs_runtime =
{
    .EXT_FIR_ACTION0 = 0x0000000000000000,
    .EXT_FIR_ACTION1 = 0x0000000000000000,
    .EXT_FIR_MASK    = 0x00FFFFFFFFFFFFFF,

    .PTL_FIR_ACTION0 = 0xF220000FFFFFFFFF,
    .PTL_FIR_ACTION1 = 0xFEE0000FFFFFFFFF,
    .PTL_FIR_MASK    = 0xF220000FFFFFFFFF,

    .DLP_FIR_ACTION0 = 0xFCFC3FFFFCC00003,
    .DLP_FIR_ACTION1 = 0xFFFFFFFFFFFFFFFF,
    .DLP_FIR_MASK    = 0xFCFC3FFFFCC0C003,

    .PHY_FIR_ACTION0 = 0x0000000000000000,
    .PHY_FIR_ACTION1 = 0xFFFFDB0000000000,
    .PHY_FIR_MASK    = 0x0000000000000000,
};

// DL Config Register Enums
const uint8_t DLP_PHY_CONFIG_DL_SELECT_DLP  = 0x01;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Display values to be programmed into FIR registers
/// @param[in] i_iohs_target  Reference to IOHS target
/// @param[in] i_pauc_target  Reference to PAUC target
/// @param[in] i_data         Data to display for given target
/// @return void.
void p10_smp_link_firs_display(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const struct fir_registers& i_data)
{
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_iohs_target, l_target_str, sizeof(l_target_str));
    FAPI_DBG("Data to be programmed for targets");
    FAPI_DBG("IOHS: %s...", l_target_str);
    fapi2::toString(i_pauc_target, l_target_str, sizeof(l_target_str));
    FAPI_DBG("PAUC: %s...", l_target_str);
    FAPI_DBG("  EXT_FIR_ACTION0  = 0x%016llX", i_data.EXT_FIR_ACTION0);
    FAPI_DBG("  EXT_FIR_ACTION1  = 0x%016llX", i_data.EXT_FIR_ACTION1);
    FAPI_DBG("  EXT_FIR_MASK_AND = 0x%016llX", i_data.EXT_FIR_MASK_CLR);
    FAPI_DBG("  EXT_FIR_MASK_OR  = 0x%016llX", i_data.EXT_FIR_MASK_SET);
    FAPI_DBG("  PTL_FIR_ACTION0  = 0x%016llX", i_data.PTL_FIR_ACTION0);
    FAPI_DBG("  PTL_FIR_ACTION1  = 0x%016llX", i_data.PTL_FIR_ACTION1);
    FAPI_DBG("  PTL_FIR_MASK_AND = 0x%016llX", i_data.PTL_FIR_MASK_CLR);
    FAPI_DBG("  PTL_FIR_MASK_OR  = 0x%016llX", i_data.PTL_FIR_MASK_SET);
    FAPI_DBG("  DLP_FIR_ACTION0  = 0x%016llX", i_data.DLP_FIR_ACTION0);
    FAPI_DBG("  DLP_FIR_ACTION1  = 0x%016llX", i_data.DLP_FIR_ACTION1);
    FAPI_DBG("  DLP_FIR_MASK_AND = 0x%016llX", i_data.DLP_FIR_MASK_CLR);
    FAPI_DBG("  DLP_FIR_MASK_OR  = 0x%016llX", i_data.DLP_FIR_MASK_SET);
    FAPI_DBG("  PHY_FIR_ACTION0  = 0x%016llX", i_data.PHY_FIR_ACTION0);
    FAPI_DBG("  PHY_FIR_ACTION1  = 0x%016llX", i_data.PHY_FIR_ACTION1);
    FAPI_DBG("  PHY_FIR_MASK_AND = 0x%016llX", i_data.PHY_FIR_MASK_CLR);
    FAPI_DBG("  PHY_FIR_MASK_OR  = 0x%016llX", i_data.PHY_FIR_MASK_SET);
}

/// @brief Clear contents of FBC EXT FIR register
/// @param[in] i_proc_target   Reference to processor chip target
/// @param[in] i_iohs_pos      Chiplet unit position for the selected IOHS target
/// @param[in] i_sublink       Sublink option specification
/// @param[in] i_clear_all     Clear all FIR bits if true, else clear error bits only
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type i_iohs_pos,
    const sublink_t i_sublink,
    const bool i_clear_all)
{
    using namespace scomt;
    using namespace scomt::proc;

    uint64_t l_extfir_btm = 0;

    if (!i_proc_target.isFunctional() ||
        (i_sublink >= sublink_t::NUM_SUBLINK_OPTS))
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing FBC EXT FIR register");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND)");

    switch(i_sublink)
    {
        case sublink_t::BOTH_PAUS:
            l_extfir_btm |= firs_btm.EXT_FIR[((i_iohs_pos / 2) * 2)];
            l_extfir_btm |= firs_btm.EXT_FIR[((i_iohs_pos / 2) * 2) + 1];
            break;

        case sublink_t::EVEN_PAUE:
            l_extfir_btm |= firs_btm.EXT_FIR[((i_iohs_pos / 2) * 2)];
            break;

        case sublink_t::ODD_PAUO:
            l_extfir_btm |= firs_btm.EXT_FIR[((i_iohs_pos / 2) * 2) + 1];
            break;

        default:
            l_extfir_btm |= firs_btm.EXT_FIR[i_iohs_pos];
            break;
    }

    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND(i_proc_target, ~l_extfir_btm),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_REG_WO_AND)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Clear contents of FBC TL FIR registers
/// @param[in] i_pauc_target   Reference to pauc target
/// @param[in] i_iohs_pos      Chiplet unit position for the selected IOHS target
/// @param[in] i_sublink       Sublink option specification
/// @param[in] i_clear_all     Clear all FIR bits if true, else clear error bits only
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type i_iohs_pos,
    const sublink_t i_sublink,
    const bool i_clear_all)
{
    using namespace scomt;
    using namespace scomt::pauc;

    fapi2::buffer<uint64_t> l_ptl_clear;
    fapi2::buffer<uint64_t> l_ptl_clear_mask;

    if (!i_pauc_target.isFunctional() ||
        (i_sublink >= sublink_t::NUM_SUBLINK_OPTS))
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing PHY FIR register");

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_REG_RW(i_pauc_target),
             "Error from prepScom (PHY_SCOM_MAC_FIR_REG_RW)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_REG_RW(i_pauc_target, ~firs_btm.PHY_FIR[i_iohs_pos]),
             "Error from putScom (PHY_SCOM_MAC_FIR_REG_RW)");

    FAPI_DBG("Clearing FBC TL FIR register");
    l_ptl_clear = ~firs_btm.PTL_FIR[i_sublink];
    l_ptl_clear_mask = ~firs_btm.PTL_FIR[i_sublink];

    FAPI_TRY(PREP_PB_PTL_FIR_REG_WO_AND(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_REG_WO_AND)");

    SET_PB_PTL_FIR_REG_FMR00_TRAINED(l_ptl_clear_mask);
    SET_PB_PTL_FIR_REG_FMR01_TRAINED(l_ptl_clear_mask);
    SET_PB_PTL_FIR_REG_FMR02_TRAINED(l_ptl_clear_mask);
    SET_PB_PTL_FIR_REG_FMR03_TRAINED(l_ptl_clear_mask);

    FAPI_TRY(PUT_PB_PTL_FIR_REG_WO_AND(i_pauc_target, i_clear_all ? l_ptl_clear : l_ptl_clear_mask),
             "Error from putScom (PB_PTL_FIR_REG_WO_AND)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Clear contents of FBC DL/PHY FIR registers
/// @param[in] i_iohs_target   Reference to iohs target
/// @param[in] i_iohs_pos      Chiplet unit position for the selected IOHS target
/// @param[in] i_sublink       Sublink option specification
/// @param[in] i_clear_all     Clear all FIR bits if true, else clear error bits only
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type i_iohs_pos,
    const sublink_t i_sublink,
    const bool i_clear_all)
{
    using namespace scomt;
    using namespace scomt::iohs;

    fapi2::buffer<uint64_t> l_clear;
    fapi2::buffer<uint64_t> l_clear_mask;

    if (!i_iohs_target.isFunctional() ||
        (i_sublink >= NUM_SUBLINK_OPTS))
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing FBC DL FIR register");
    l_clear = ~firs_btm.DLP_FIR[i_sublink];
    l_clear_mask = ~firs_btm.DLP_FIR[i_sublink];

    FAPI_TRY(PREP_DLP_FIR_REG_WO_AND(i_iohs_target),
             "Error from prepScom (DLP_FIR_REG_WO_AND)");

    SET_DLP_FIR_REG_0_TRAINED(l_clear_mask);
    SET_DLP_FIR_REG_1_TRAINED(l_clear_mask);

    FAPI_TRY(PUT_DLP_FIR_REG_WO_AND(i_iohs_target, i_clear_all ? l_clear : l_clear_mask),
             "Error from putScom (DLP_FIR_REG_WO_AND)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Configure FBC EXT FIR Registers
/// @param[in] i_proc_target   Reference to processor chip target
/// @param[in] i_data          Data to program into fir registers
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_ext(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target,
    const struct fir_registers& i_data)
{
    using namespace scomt;
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_mask_value(0x0);

    if(!i_proc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring FBC EXTFIR Registers");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(i_proc_target, i_data.EXT_FIR_ACTION0),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG)");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(i_proc_target, i_data.EXT_FIR_ACTION1),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG)");

    FAPI_TRY(GET_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW(i_proc_target, l_mask_value),
             "Error from getScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW)");

    l_mask_value &= i_data.EXT_FIR_MASK_CLR;
    l_mask_value |= i_data.EXT_FIR_MASK_SET;

    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW(i_proc_target, l_mask_value),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Configure FBC TL FIR Registers
/// @param[in] i_pauc_target   Reference to pauc target
/// @param[in] i_data          Data to program into fir registers
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_tl(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const struct fir_registers& i_data)
{
    using namespace scomt;
    using namespace scomt::pauc;

    fapi2::buffer<uint64_t> l_mask_value(0x0);

    if(!i_pauc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring FBC TL Registers");

    FAPI_TRY(PREP_PB_PTL_FIR_ACTION0_REG(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_ACTION0_REG)");
    FAPI_TRY(PUT_PB_PTL_FIR_ACTION0_REG(i_pauc_target, i_data.PTL_FIR_ACTION0),
             "Error from putScom (PB_PTL_FIR_ACTION0_REG)");

    FAPI_TRY(PREP_PB_PTL_FIR_ACTION1_REG(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_ACTION1_REG)");
    FAPI_TRY(PUT_PB_PTL_FIR_ACTION1_REG(i_pauc_target, i_data.PTL_FIR_ACTION1),
             "Error from putScom (PB_PTL_FIR_ACTION1_REG)");

    FAPI_TRY(GET_PB_PTL_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from getScom (PB_PTL_FIR_MASK_REG_RW)");

    l_mask_value &= i_data.PTL_FIR_MASK_CLR;
    l_mask_value |= i_data.PTL_FIR_MASK_SET;

    FAPI_TRY(PUT_PB_PTL_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from putScom (PB_PTL_FIR_MASK_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Configure FBC DL FIR Registers
/// @param[in] i_iohs_target   Reference to iohs target
/// @param[in] i_data          Data to program into fir registers
fapi2::ReturnCode p10_smp_link_firs_dl(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const struct fir_registers& i_data)
{
    using namespace scomt;
    using namespace scomt::iohs;

    fapi2::buffer<uint64_t> l_mask_value(0x0);

    if(!i_iohs_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring FBC DL Registers");

    FAPI_TRY(PREP_DLP_FIR_ACTION0_REG(i_iohs_target),
             "Error from prepScom (DLP_FIR_ACTION0_REG)");
    FAPI_TRY(PUT_DLP_FIR_ACTION0_REG(i_iohs_target, i_data.DLP_FIR_ACTION0),
             "Error from putScom (DLP_FIR_ACTION0_REG)");

    FAPI_TRY(PREP_DLP_FIR_ACTION1_REG(i_iohs_target),
             "Error from prepScom (DLP_FIR_ACTION1_REG)");
    FAPI_TRY(PUT_DLP_FIR_ACTION1_REG(i_iohs_target, i_data.DLP_FIR_ACTION1),
             "Error from putScom (DLP_FIR_ACTION1_REG)");

    FAPI_TRY(GET_DLP_FIR_MASK_REG_RW(i_iohs_target, l_mask_value),
             "Error from getScom (DLP_FIR_MASK_REG_RW)");

    l_mask_value &= i_data.DLP_FIR_MASK_CLR;
    l_mask_value |= i_data.DLP_FIR_MASK_SET;

    FAPI_TRY(PUT_DLP_FIR_MASK_REG_RW(i_iohs_target, l_mask_value),
             "Error from putScom (DLP_FIR_MASK_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Configure PHY FIR Registers
/// @param[in] i_pauc_target   Reference to pauc target
/// @param[in] i_data          Data to program into fir registers
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_phy(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const struct fir_registers& i_data)
{
    using namespace scomt;
    using namespace scomt::pauc;

    fapi2::buffer<uint64_t> l_mask_value(0x0);

    if(!i_pauc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring PHY Registers");

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_ACTION0_REG(i_pauc_target),
             "Error from prepScom (PHY_SCOM_MAC_FIR_ACTION0_REG)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_ACTION0_REG(i_pauc_target, i_data.PHY_FIR_ACTION0),
             "Error from putScom (PHY_SCOM_MAC_FIR_ACTION0_REG)");

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_ACTION1_REG(i_pauc_target),
             "Error from prepScom (PHY_SCOM_MAC_FIR_ACTION1_REG)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_ACTION1_REG(i_pauc_target, i_data.PHY_FIR_ACTION1),
             "Error from putScom (PHY_SCOM_MAC_FIR_ACTION1_REG)");

    FAPI_TRY(GET_PHY_SCOM_MAC_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from getScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");

    l_mask_value &= i_data.PHY_FIR_MASK_CLR;
    l_mask_value |= i_data.PHY_FIR_MASK_SET;

    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");


fapi_try_exit:
    return fapi2::current_err;
}

/// See doxygen comments in header file
fapi2::ReturnCode p10_smp_link_firs(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    sublink_t i_sublink,
    action_t i_action)
{
    using namespace scomt;
    using namespace scomt::iohs;

    FAPI_DBG("Entering...");

    struct fir_registers l_reg_values = firs_inactive;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_iohs_pos;

    auto l_proc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PROC_CHIP>();
    auto l_pauc_target = i_iohs_target.getParent<fapi2::TARGET_TYPE_PAUC>();

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_iohs_target, l_iohs_pos),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

    // Exit if user does not select sublinks to configure
    if (i_sublink >= sublink_t::NUM_SUBLINK_OPTS)
    {
        FAPI_DBG("No sublinks selected to configure!");
        goto fapi_try_exit;
    }

    // Prepare FIR register values for selected operation
    if (i_action == action_t::INACTIVE)
    {
        FAPI_DBG("action INACTIVE selected");
        l_reg_values = firs_inactive;
    }
    else if (i_action == action_t::RUNTIME)
    {
        FAPI_DBG("action RUNTIME selected");
        l_reg_values = firs_runtime;
    }
    else if (i_action == action_t::CLEAR_ALL)
    {
        FAPI_DBG("action CLEAR_ALL selected");
    }
    else if (i_action == action_t::CLEAR_ERR)
    {
        FAPI_DBG("action CLEAR_ERR selected");
    }
    else
    {
        FAPI_ASSERT(false, fapi2::P10_SMP_LINK_FIRS_UNSUPPORTED_ACTION()
                    .set_PROC_TARGET(l_proc_target)
                    .set_IOHS_TARGET(i_iohs_target)
                    .set_ACTION(i_action),
                    "Unsupported link action requested for FIR setup");
    }

    // Verify that the IOHS target is configured as an SMP
    if (i_iohs_target.isFunctional() && (i_action != action_t::INACTIVE))
    {
        fapi2::buffer<uint64_t> l_dlp_config(0x0);
        fapi2::buffer<uint64_t> l_dl_select(0x0);

        FAPI_TRY(GET_DLP_PHY_CONFIG(i_iohs_target, l_dlp_config),
                 "Error from getScom (DLP_PHY_CONFIG_DL_SELECT)");

        GET_DLP_PHY_CONFIG_DL_SELECT(l_dlp_config, l_dl_select);

        FAPI_ASSERT(l_dl_select == DLP_PHY_CONFIG_DL_SELECT_DLP,
                    fapi2::P10_SMP_LINK_FIRS_IOHS_NOT_SMP()
                    .set_PROC_TARGET(l_proc_target)
                    .set_IOHS_TARGET(i_iohs_target),
                    "Requested IOHS target is not configured as an SMP link!");
    }

    // Process option to clear all bits in FIR registers
    if (i_action == action_t::CLEAR_ALL)
    {
        FAPI_TRY(p10_smp_link_firs_clear(l_proc_target, l_iohs_pos, i_sublink, true),
                 "Error from p10_smp_link_firs_clear (proc)");
        FAPI_TRY(p10_smp_link_firs_clear(l_pauc_target, l_iohs_pos, i_sublink, true),
                 "Error from p10_smp_link_firs_clear (pauc)");
        FAPI_TRY(p10_smp_link_firs_clear(i_iohs_target, l_iohs_pos, i_sublink, true),
                 "Error from p10_smp_link_firs_clear (iohs)");

        goto fapi_try_exit;
    }

    // Process option to clear error bits in FIR registers
    if (i_action == action_t::CLEAR_ERR)
    {
        FAPI_TRY(p10_smp_link_firs_clear(l_proc_target, l_iohs_pos, i_sublink, false),
                 "Error from p10_smp_link_firs_clear (proc)");
        FAPI_TRY(p10_smp_link_firs_clear(l_pauc_target, l_iohs_pos, i_sublink, false),
                 "Error from p10_smp_link_firs_clear (pauc)");
        FAPI_TRY(p10_smp_link_firs_clear(i_iohs_target, l_iohs_pos, i_sublink, false),
                 "Error from p10_smp_link_firs_clear (iohs)");

        goto fapi_try_exit;
    }

    // Select FIR MASK register values for given iohs
    // EXT FIR -- guarantee correct l_iohs_pos is used (in case of split links)
    {
        uint64_t l_extfir_btm = 0;

        switch(i_sublink)
        {
            case sublink_t::BOTH_PAUS:
                l_extfir_btm |= firs_btm.EXT_FIR[((l_iohs_pos / 2) * 2)];
                l_extfir_btm |= firs_btm.EXT_FIR[((l_iohs_pos / 2) * 2) + 1];
                break;

            case sublink_t::EVEN_PAUE:
                l_extfir_btm |= firs_btm.EXT_FIR[((l_iohs_pos / 2) * 2)];
                break;

            case sublink_t::ODD_PAUO:
                l_extfir_btm |= firs_btm.EXT_FIR[((l_iohs_pos / 2) * 2) + 1];
                break;

            default:
                l_extfir_btm |= firs_btm.EXT_FIR[l_iohs_pos];
                break;
        }

        l_reg_values.EXT_FIR_MASK_CLR = ~l_extfir_btm;
        l_reg_values.EXT_FIR_MASK_SET = l_extfir_btm & l_reg_values.EXT_FIR_MASK;
    }

    // PTL FIR
    l_reg_values.PTL_FIR_MASK_CLR = ~firs_btm.PTL_FIR[i_sublink];
    l_reg_values.PTL_FIR_MASK_SET = firs_btm.PTL_FIR[i_sublink] & l_reg_values.PTL_FIR_MASK;

    // DL FIR
    l_reg_values.DLP_FIR_MASK_CLR = ~firs_btm.DLP_FIR[i_sublink];
    l_reg_values.DLP_FIR_MASK_SET = firs_btm.DLP_FIR[i_sublink] & l_reg_values.DLP_FIR_MASK;

    // PHY FIR
    l_reg_values.PHY_FIR_MASK_CLR = ~firs_btm.PHY_FIR[l_iohs_pos];
    l_reg_values.PHY_FIR_MASK_SET = firs_btm.PHY_FIR[l_iohs_pos] & l_reg_values.PHY_FIR_MASK;

    // Print values to be programmed
    p10_smp_link_firs_display(i_iohs_target, l_pauc_target, l_reg_values);

    // Configure FBC EXT/DL/TL/PHY FIR Registers
    FAPI_TRY(p10_smp_link_firs_ext(l_proc_target, l_reg_values),
             "Error from p10_smp_link_firs_ext");
    FAPI_TRY(p10_smp_link_firs_tl(l_pauc_target, l_reg_values),
             "Error from p10_smp_link_firs_tl");
    FAPI_TRY(p10_smp_link_firs_dl(i_iohs_target, l_reg_values),
             "Error from p10_smp_link_firs_dl");
    FAPI_TRY(p10_smp_link_firs_phy(l_pauc_target, l_reg_values),
             "Error from p10_smp_link_firs_phy");

fapi_try_exit:
    FAPI_DBG("Exiting...");
    return fapi2::current_err;
}
