/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_smp_link_firs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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

enum masks_t
{
    MASK_AND = 0,
    MASK_OR  = 1,
    NUM_MASK_OPTS = 2,
};

struct fir_registers
{
    // FBC EXTFIR Constants
    uint64_t FBC_EXT_FIR_ACTION0;
    uint64_t FBC_EXT_FIR_ACTION1;
    uint64_t FBC_EXT_FIR_MASK[FABRIC_NUM_IOHS_LINKS][NUM_MASK_OPTS];

    // FBC TL FIR Constants
    uint64_t PB_PTL_FIR_ACTION0;
    uint64_t PB_PTL_FIR_ACTION1;
    uint64_t PB_PTL_FIR_MASK[NUM_SUBLINK_OPTS][FABRIC_NUM_IOHS_LINKS][NUM_MASK_OPTS];

    // FBC DL FIR Constants
    uint64_t DLP_FIR_ACTION0;
    uint64_t DLP_FIR_ACTION1;
    uint64_t DLP_FIR_MASK[NUM_SUBLINK_OPTS][NUM_MASK_OPTS];

    // PHY FIR Constants
    uint64_t PHY_FIR_ACTION0;
    uint64_t PHY_FIR_ACTION1;
    uint64_t PHY_FIR_MASK[NUM_SUBLINK_OPTS][FABRIC_NUM_IOHS_LINKS][NUM_MASK_OPTS];

    // Selected masks from above arrays, populated by functions
    uint64_t FBC_EXT_FIR_MASK_SEL[NUM_MASK_OPTS];
    uint64_t PB_PTL_FIR_MASK_SEL[NUM_MASK_OPTS];
    uint64_t DLP_FIR_MASK_SEL[NUM_MASK_OPTS];
    uint64_t PHY_FIR_MASK_SEL[NUM_MASK_OPTS];
};

struct fir_registers firs_inactive =
{
    .FBC_EXT_FIR_ACTION0 = 0x0000000000000000,
    .FBC_EXT_FIR_ACTION1 = 0x0000000000000000,
    .FBC_EXT_FIR_MASK    =
    {
        // bits to modify   , value to program
        { 0x8000000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
        { 0x4000000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
        { 0x2000000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
        { 0x1000000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
        { 0x0800000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
        { 0x0400000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
        { 0x0200000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
        { 0x0100000000000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
    },
    .PB_PTL_FIR_ACTION0  = 0xF22003CFFFFFFFFF,
    .PB_PTL_FIR_ACTION1  = 0xF66003CFFFFFFFFF,
    .PB_PTL_FIR_MASK     =
    {
        // both even/odd
        {
            // bits to modify   , value to program
            { 0xCF0E332F0C000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0x30F1CCD0F3000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0xCF0E332F0C000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0x30F1CCD0F3000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0xCF0E332F0C000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0x30F1CCD0F3000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0xCF0E332F0C000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0x30F1CCD0F3000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
        // even only
        {
            // bits to modify   , value to program
            { 0x8F08222C08000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0x20F18890C2000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0x8F08222C08000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0x20F18890C2000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0x8F08222C08000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0x20F18890C2000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0x8F08222C08000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0x20F18890C2000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
        // odd only
        {
            // bits to modify   , value to program
            { 0x4F06112304000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0x10F0C45031000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0x4F06112304000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0x10F0C45031000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0x4F06112304000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0x10F0C45031000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0x4F06112304000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0x10F0C45031000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
    },
    .DLP_FIR_ACTION0     = 0xFCFC3FFFFCC00003,
    .DLP_FIR_ACTION1     = 0xFFFFFFFFFFFFFFFF,
    .DLP_FIR_MASK        =
    {
        // bits to modify   , value to program
        { 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF }, // both halves
        { 0xAAAAAAAAAAAAAAAA, 0xFFFFFFFFFFFFFFFF }, // even only
        { 0x5555555555555555, 0xFFFFFFFFFFFFFFFF }, // odd only
    },
    .PHY_FIR_ACTION0     = 0x8000000000000000,
    .PHY_FIR_ACTION1     = 0xF47FDB0000000000,
    .PHY_FIR_MASK        =
    {
        // both even/odd
        {
            // bits to modify   , value to program
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0xFFFFFC0000000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
        // even only
        {
            // bits to modify   , value to program
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0x88FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
        // odd only
        {
            // bits to modify   , value to program
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs0
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs1
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs2
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs3
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs4
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs5
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs6
            { 0x44FFFFC000000000, 0xFFFFFFFFFFFFFFFF }, // iohs7
        },
    },
};

struct fir_registers firs_runtime =
{
    .FBC_EXT_FIR_ACTION0 = 0x0000000000000000,
    .FBC_EXT_FIR_ACTION1 = 0x0000000000000000,
    .FBC_EXT_FIR_MASK    =
    {
        // bits to modify   , value to program
        { 0x8000000000000000, 0x7F00000000000000 }, // iohs0
        { 0x4000000000000000, 0xBF00000000000000 }, // iohs1
        { 0x2000000000000000, 0xDF00000000000000 }, // iohs2
        { 0x1000000000000000, 0xEF00000000000000 }, // iohs3
        { 0x0800000000000000, 0xF700000000000000 }, // iohs4
        { 0x0400000000000000, 0xFB00000000000000 }, // iohs5
        { 0x0200000000000000, 0xFD00000000000000 }, // iohs6
        { 0x0100000000000000, 0xFE00000000000000 }, // iohs7
    },
    .PB_PTL_FIR_ACTION0  = 0xF22003CFFFFFFFFF,
    .PB_PTL_FIR_ACTION1  = 0xF66003CFFFFFFFFF,
    .PB_PTL_FIR_MASK     =
    {
        // both even/odd
        {
            // bits to modify   , value to program
            { 0xCF0E332F0C000000, 0xF22003CFFFFFFFFF }, // iohs0
            { 0x30F1CCD0F3000000, 0xF22003CFFFFFFFFF }, // iohs1
            { 0xCF0E332F0C000000, 0xF22003CFFFFFFFFF }, // iohs2
            { 0x30F1CCD0F3000000, 0xF22003CFFFFFFFFF }, // iohs3
            { 0xCF0E332F0C000000, 0xF22003CFFFFFFFFF }, // iohs4
            { 0x30F1CCD0F3000000, 0xF22003CFFFFFFFFF }, // iohs5
            { 0xCF0E332F0C000000, 0xF22003CFFFFFFFFF }, // iohs6
            { 0x30F1CCD0F3000000, 0xF22003CFFFFFFFFF }, // iohs7
        },
        // even only
        {
            // bits to modify   , value to program
            { 0x8F08222C08000000, 0xF22003CFFFFFFFFF }, // iohs0
            { 0x20F18890C2000000, 0xF22003CFFFFFFFFF }, // iohs1
            { 0x8F08222C08000000, 0xF22003CFFFFFFFFF }, // iohs2
            { 0x20F18890C2000000, 0xF22003CFFFFFFFFF }, // iohs3
            { 0x8F08222C08000000, 0xF22003CFFFFFFFFF }, // iohs4
            { 0x20F18890C2000000, 0xF22003CFFFFFFFFF }, // iohs5
            { 0x8F08222C08000000, 0xF22003CFFFFFFFFF }, // iohs6
            { 0x20F18890C2000000, 0xF22003CFFFFFFFFF }, // iohs7
        },
        // odd only
        {
            // bits to modify   , value to program
            { 0x4F06112304000000, 0xF22003CFFFFFFFFF }, // iohs0
            { 0x10F0C45031000000, 0xF22003CFFFFFFFFF }, // iohs1
            { 0x4F06112304000000, 0xF22003CFFFFFFFFF }, // iohs2
            { 0x10F0C45031000000, 0xF22003CFFFFFFFFF }, // iohs3
            { 0x4F06112304000000, 0xF22003CFFFFFFFFF }, // iohs4
            { 0x10F0C45031000000, 0xF22003CFFFFFFFFF }, // iohs5
            { 0x4F06112304000000, 0xF22003CFFFFFFFFF }, // iohs6
            { 0x10F0C45031000000, 0xF22003CFFFFFFFFF }, // iohs7
        },
    },
    .DLP_FIR_ACTION0     = 0xFCFC3FFFFCC00003,
    .DLP_FIR_ACTION1     = 0xFFFFFFFFFFFFFFFF,
    .DLP_FIR_MASK        =
    {
        // bits to modify   , value to program
        { 0xFFFFFFFFFFFFFFFF, 0xFCFC3FFFFCC00003 }, // both halves
        { 0xAAAAAAAAAAAAAAAA, 0xFCFC3FFFFCC00003 }, // even only
        { 0x5555555555555555, 0xFCFC3FFFFCC00003 }, // odd only
    },
    .PHY_FIR_ACTION0     = 0x8000000000000000,
    .PHY_FIR_ACTION1     = 0xF47FDB0000000000,
    .PHY_FIR_MASK        =
    {
        // both even/odd
        {
            // bits to modify   , value to program
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs0
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs1
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs2
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs3
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs4
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs5
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs6
            { 0xFFFFFC0000000000, 0x0B8024C000000000 }, // iohs7
        },
        // even only
        {
            // bits to modify   , value to program
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs0
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs1
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs2
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs3
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs4
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs5
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs6
            { 0x88FFFFC000000000, 0x0B8024C000000000 }, // iohs7
        },
        // odd only
        {
            // bits to modify   , value to program
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs0
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs1
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs2
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs3
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs4
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs5
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs6
            { 0x44FFFFC000000000, 0x0B8024C000000000 }, // iohs7
        },
    },
};

// DL Config Register Enums
const uint8_t DLP_PHY_CONFIG_DL_SELECT_DLP  = 0x01;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Display values to be programmed into FIR registers
/// @param[in] i_target  Reference to IOHS target
/// @param[in] i_data    Data to display for given target
/// @return void.
void p10_smp_link_firs_display(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target,
    const struct fir_registers& i_data)
{
    char l_target_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_iohs_target, l_target_str, sizeof(l_target_str));

    FAPI_DBG("Data to be programmed for %s...", l_target_str);
    FAPI_DBG("  FBC_EXT_FIR_ACTION0  = 0x%016llX", i_data.FBC_EXT_FIR_ACTION0);
    FAPI_DBG("  FBC_EXT_FIR_ACTION1  = 0x%016llX", i_data.FBC_EXT_FIR_ACTION1);
    FAPI_DBG("  FBC_EXT_FIR_MASK_AND = 0x%016llX", i_data.FBC_EXT_FIR_MASK_SEL[MASK_AND]);
    FAPI_DBG("  FBC_EXT_FIR_MASK_OR  = 0x%016llX", i_data.FBC_EXT_FIR_MASK_SEL[MASK_OR]);
    FAPI_DBG("  PB_PTL_FIR_ACTION0   = 0x%016llX", i_data.PB_PTL_FIR_ACTION0);
    FAPI_DBG("  PB_PTL_FIR_ACTION1   = 0x%016llX", i_data.PB_PTL_FIR_ACTION1);
    FAPI_DBG("  PB_PTL_FIR_MASK_AND  = 0x%016llX", i_data.PB_PTL_FIR_MASK_SEL[MASK_AND]);
    FAPI_DBG("  PB_PTL_FIR_MASK_OR   = 0x%016llX", i_data.PB_PTL_FIR_MASK_SEL[MASK_OR]);
    FAPI_DBG("  DLP_FIR_ACTION0      = 0x%016llX", i_data.DLP_FIR_ACTION0);
    FAPI_DBG("  DLP_FIR_ACTION1      = 0x%016llX", i_data.DLP_FIR_ACTION1);
    FAPI_DBG("  DLP_FIR_MASK_AND     = 0x%016llX", i_data.DLP_FIR_MASK_SEL[MASK_AND]);
    FAPI_DBG("  DLP_FIR_MASK_OR      = 0x%016llX", i_data.DLP_FIR_MASK_SEL[MASK_OR]);
    FAPI_DBG("  PHY_FIR_ACTION0      = 0x%016llX", i_data.PHY_FIR_ACTION0);
    FAPI_DBG("  PHY_FIR_ACTION1      = 0x%016llX", i_data.PHY_FIR_ACTION1);
    FAPI_DBG("  PHY_FIR_MASK_AND     = 0x%016llX", i_data.PHY_FIR_MASK_SEL[MASK_AND]);
    FAPI_DBG("  PHY_FIR_MASK_OR      = 0x%016llX", i_data.PHY_FIR_MASK_SEL[MASK_OR]);
}

/// @brief Clear contents of FBC EXT FIR register
/// @param[in] i_proc_target   Reference to processor chip target
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc_target)
{
    using namespace scomt;
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_zeroes(0x0);

    if(!i_proc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing FBC EXT FIR register");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_REG_RW(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_REG_RWW)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_REG_RW(i_proc_target, l_zeroes),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Clear contents of FBC TL/PHY FIR registers
/// @param[in] i_pauc_target   Reference to pauc target
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target)
{
    using namespace scomt;
    using namespace scomt::pauc;

    fapi2::buffer<uint64_t> l_zeroes(0x0);

    if(!i_pauc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing FBC TL FIR register");

    FAPI_TRY(PREP_PB_PTL_FIR_REG_RW(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_REG_RW)");
    FAPI_TRY(PUT_PB_PTL_FIR_REG_RW(i_pauc_target, l_zeroes),
             "Error from putScom (PB_PTL_FIR_REG_RW)");

    FAPI_DBG("Clearing PHY FIR register");

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_REG_RW(i_pauc_target),
             "Error from prepScom (PHY_SCOM_MAC_FIR_REG_RW)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_REG_RW(i_pauc_target, l_zeroes),
             "Error from putScom (PHY_SCOM_MAC_FIR_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}

/// @brief Clear contents of FBC DL FIR registers
/// @param[in] i_iohs_target   Reference to iohs target
/// @return fapi2::ReturnCode  FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_smp_link_firs_clear(
    const fapi2::Target<fapi2::TARGET_TYPE_IOHS>& i_iohs_target)
{
    using namespace scomt;
    using namespace scomt::iohs;

    fapi2::buffer<uint64_t> l_zeroes(0x0);

    if(!i_iohs_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Clearing FBC DL FIR register");

    FAPI_TRY(PREP_DLP_FIR_REG_RW(i_iohs_target),
             "Error from prepScom (DLP_FIR_REG_RW)");
    FAPI_TRY(PUT_DLP_FIR_REG_RW(i_iohs_target, l_zeroes),
             "Error from putScom (DLP_FIR_REG_RW)");

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

    uint64_t l_fbc_ext_act0 = i_data.FBC_EXT_FIR_ACTION0;
    uint64_t l_fbc_ext_act1 = i_data.FBC_EXT_FIR_ACTION1;
    uint64_t l_fbc_ext_mask_and = i_data.FBC_EXT_FIR_MASK_SEL[MASK_AND];
    uint64_t l_fbc_ext_mask_or = i_data.FBC_EXT_FIR_MASK_SEL[MASK_OR];

    if(!i_proc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring FBC EXTFIR Registers");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG(i_proc_target, l_fbc_ext_act0),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_ACTION0_REG)");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG(i_proc_target, l_fbc_ext_act1),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_ACTION1_REG)");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND(i_proc_target, l_fbc_ext_mask_and),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_AND)");

    FAPI_TRY(PREP_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR(i_proc_target),
             "Error from prepScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR)");
    FAPI_TRY(PUT_PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR(i_proc_target, l_fbc_ext_mask_or),
             "Error from putScom (PB_COM_SCOM_ES3_EXTFIR_MASK_REG_WO_OR)");

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

    if(!i_pauc_target.isFunctional())
    {
        goto fapi_try_exit;
    }

    FAPI_DBG("Configuring FBC TL Registers");

    FAPI_TRY(PREP_PB_PTL_FIR_ACTION0_REG(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_ACTION0_REG)");
    FAPI_TRY(PUT_PB_PTL_FIR_ACTION0_REG(i_pauc_target, i_data.PB_PTL_FIR_ACTION0),
             "Error from putScom (PB_PTL_FIR_ACTION0_REG)");

    FAPI_TRY(PREP_PB_PTL_FIR_ACTION1_REG(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_ACTION1_REG)");
    FAPI_TRY(PUT_PB_PTL_FIR_ACTION1_REG(i_pauc_target, i_data.PB_PTL_FIR_ACTION1),
             "Error from putScom (PB_PTL_FIR_ACTION1_REG)");

    FAPI_TRY(PREP_PB_PTL_FIR_MASK_REG_WO_AND(i_pauc_target),
             "Error from prepScom (PB_PTL_FIR_MASK_REG_WO_AND)");
    FAPI_TRY(PUT_PB_PTL_FIR_MASK_REG_WO_AND(i_pauc_target, i_data.PB_PTL_FIR_MASK_SEL[MASK_AND]),
             "Error from putScom (PB_PTL_FIR_MASK_REG_WO_AND)");

    FAPI_TRY(PREP_PB_PTL_FIR_MASK_REG_WO_OR(i_pauc_target),
             "Error from putScom (PB_PTL_FIR_MASK_REG_WO_OR)");
    FAPI_TRY(PUT_PB_PTL_FIR_MASK_REG_WO_OR(i_pauc_target, i_data.PB_PTL_FIR_MASK_SEL[MASK_OR]),
             "Error from putScom (PB_PTL_FIR_MASK_REG_WO_OR)");

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

    FAPI_TRY(PREP_DLP_FIR_MASK_REG_WO_AND(i_iohs_target),
             "Error from prepScom (DLP_FIR_MASK_REG_WO_AND)");
    FAPI_TRY(PUT_DLP_FIR_MASK_REG_WO_AND(i_iohs_target, i_data.DLP_FIR_MASK_SEL[MASK_AND]),
             "Error from putScom (DLP_FIR_MASK_REG_WO_AND)");

    FAPI_TRY(PREP_DLP_FIR_MASK_REG_WO_OR(i_iohs_target),
             "Error from prepScom (DLP_FIR_MASK_REG_WO_OR)");
    FAPI_TRY(PUT_DLP_FIR_MASK_REG_WO_OR(i_iohs_target, i_data.DLP_FIR_MASK_SEL[MASK_OR]),
             "Error from putScom (DLP_FIR_MASK_REG_WO_OR)");

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

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_MASK_REG_WO_AND(i_pauc_target),
             "Error from prepScom (PHY_SCOM_MAC_FIR_MASK_REG_WO_AND)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_WO_AND(i_pauc_target, i_data.PHY_FIR_MASK_SEL[MASK_AND]),
             "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_WO_AND)");

    FAPI_TRY(PREP_PHY_SCOM_MAC_FIR_MASK_REG_WO_OR(i_pauc_target),
             "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_WO_OR)");
    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_WO_OR(i_pauc_target, i_data.PHY_FIR_MASK_SEL[MASK_OR]),
             "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_WO_OR)");

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
    if(i_sublink == sublink_t::NONE)
    {
        FAPI_DBG("No sublinks selected to configure!");
        goto fapi_try_exit;
    }

    // Prepare FIR register values for selected operation
    if(i_action == action_t::INACTIVE)
    {
        FAPI_DBG("action INACTIVE selected");
        l_reg_values = firs_inactive;
    }
    else if(i_action == action_t::RUNTIME)
    {
        FAPI_DBG("action RUNTIME selected");
        l_reg_values = firs_runtime;
    }
    else if(i_action == action_t::CLEARFIRS)
    {
        FAPI_DBG("action CLEARFIRS selected");
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
    if(i_iohs_target.isFunctional() && (i_action != action_t::INACTIVE))
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

    // Process option to Clear FIR registers
    if(i_action == action_t::CLEARFIRS)
    {
        FAPI_TRY(p10_smp_link_firs_clear(l_proc_target),
                 "Error from p10_smp_link_firs_clear (proc)");
        FAPI_TRY(p10_smp_link_firs_clear(l_pauc_target),
                 "Error from p10_smp_link_firs_clear (pauc)");
        FAPI_TRY(p10_smp_link_firs_clear(i_iohs_target),
                 "Error from p10_smp_link_firs_clear (iohs)");

        goto fapi_try_exit;
    }

    // Select FIR MASK register values for given iohs
    l_reg_values.FBC_EXT_FIR_MASK_SEL[MASK_AND] = ~l_reg_values.FBC_EXT_FIR_MASK[l_iohs_pos][MASK_AND];
    l_reg_values.FBC_EXT_FIR_MASK_SEL[MASK_OR] = l_reg_values.FBC_EXT_FIR_MASK[l_iohs_pos][MASK_OR]
            & l_reg_values.FBC_EXT_FIR_MASK[l_iohs_pos][MASK_AND];

    l_reg_values.PB_PTL_FIR_MASK_SEL[MASK_AND] = ~l_reg_values.PB_PTL_FIR_MASK[i_sublink][l_iohs_pos][MASK_AND];
    l_reg_values.PB_PTL_FIR_MASK_SEL[MASK_OR] = l_reg_values.PB_PTL_FIR_MASK[i_sublink][l_iohs_pos][MASK_OR]
            & l_reg_values.PB_PTL_FIR_MASK[i_sublink][l_iohs_pos][MASK_AND];

    l_reg_values.DLP_FIR_MASK_SEL[MASK_AND] = ~l_reg_values.DLP_FIR_MASK[i_sublink][MASK_AND];
    l_reg_values.DLP_FIR_MASK_SEL[MASK_OR] = l_reg_values.DLP_FIR_MASK[i_sublink][MASK_OR]
            & l_reg_values.DLP_FIR_MASK[i_sublink][MASK_AND];

    l_reg_values.PHY_FIR_MASK_SEL[MASK_AND] = ~l_reg_values.PHY_FIR_MASK[i_sublink][l_iohs_pos][MASK_AND];
    l_reg_values.PHY_FIR_MASK_SEL[MASK_OR] = l_reg_values.PHY_FIR_MASK[i_sublink][l_iohs_pos][MASK_OR]
            & l_reg_values.PHY_FIR_MASK[i_sublink][l_iohs_pos][MASK_AND];

    // Print values to be programmed
    p10_smp_link_firs_display(i_iohs_target, l_reg_values);

    // Configure FBC EXT/DL/TL FIR Registers
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
