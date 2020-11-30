/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_scominit.C $   */
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
/// @file p10_omi_scominit.C
/// @brief Placeholder for OMI SCOM init customization (FAPI2)
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_omi_scominit.H>
#include <p10_scom_pauc.H>

fapi2::ReturnCode p10_io_omic_valid(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    bool& o_valid);
fapi2::ReturnCode p10_io_omic_set_firs(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type& i_omic_num);
//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// Main function, see description in header
fapi2::ReturnCode p10_omi_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");
    bool l_valid = false;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_omic_num;

    auto l_pauc_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAUC>();

    for (auto l_pauc_target : l_pauc_targets)
    {
        auto l_omic_targets = l_pauc_target.getChildren<fapi2::TARGET_TYPE_OMIC>();

        for (auto l_omic_target : l_omic_targets)
        {
            FAPI_TRY(p10_io_omic_valid(l_omic_target, l_valid));

            if (l_valid)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omic_target, l_omic_num),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
                FAPI_TRY(p10_io_omic_set_firs(l_pauc_target, l_omic_num));
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}


/// @brief Determines if omic target is valid
/// @param[in] i_omic_target    OMIC target
/// @param[out] o_valid         Valid
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_omic_valid(
    const fapi2::Target<fapi2::TARGET_TYPE_OMIC>& i_omic_target,
    bool& o_valid)
{
    o_valid = false;

    auto l_omi_targets = i_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>();

    for (auto l_omi_target : l_omi_targets)
    {
        auto l_ocmbs = l_omi_target.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

        if (l_ocmbs.size() > 0)
        {
            o_valid = true;
        }
    }

    return fapi2::current_err;
}
/// @brief Setup FIRs for Valid OMIC
/// @param[in] i_pauc_target    PAUC Target
/// @param[in] i_omic_num       OMIC Unit Num
/// @return FAPI_RC_SUCCESS if arguments are valid
fapi2::ReturnCode p10_io_omic_set_firs(
    const fapi2::Target<fapi2::TARGET_TYPE_PAUC>& i_pauc_target,
    const fapi2::ATTR_CHIP_UNIT_POS_Type& i_omic_num)
{
    using namespace scomt;
    using namespace scomt::pauc;

    fapi2::buffer<uint64_t> l_mask_value(0x0);

    FAPI_TRY(GET_PHY_SCOM_MAC_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from getScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");

    if (i_omic_num % 2 == 0)
    {
        l_mask_value &= 0xDDFFFFFFFFFFFFFF;
    }
    else
    {
        l_mask_value &= 0xEEFFFFFFFFFFFFFF;
    }

    FAPI_TRY(PUT_PHY_SCOM_MAC_FIR_MASK_REG_RW(i_pauc_target, l_mask_value),
             "Error from putScom (PHY_SCOM_MAC_FIR_MASK_REG_RW)");

fapi_try_exit:
    return fapi2::current_err;
}
