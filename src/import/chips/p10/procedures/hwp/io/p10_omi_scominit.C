/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_omi_scominit.C $   */
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
#include <p10_scom_omic_3.H>
#include <p10_scom_omic_7.H>

const uint64_t MC_OMI_FIR_DL0  = 0xFFFFF00000000000; // Bits to modify for DL0
const uint64_t MC_OMI_FIR_DL1  = 0x00000FFFFF000000; // Bits to modify for DL1
const uint64_t MC_OMI_FIR_MASK = 0x1A9FF1A9FFFFFFFF;
const uint64_t MC_OMI_FIR_ACT0 = 0x0000000000000000;
const uint64_t MC_OMI_FIR_ACT1 = 0xFFFFFFFFFFFFFFFF;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// Main function, see description in header
fapi2::ReturnCode p10_omi_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::omic;

    FAPI_DBG("Entering ...");

    for(auto l_omic : i_target.getChildren<fapi2::TARGET_TYPE_OMIC>())
    {
        // flush value is unmasked, start off with all masked
        uint64_t l_mask = 0xFFFFFFFFFFFFFFFF;

        FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_WO_OR(l_omic),
                 "Error from prepScom (MC_OMI_FIR_MASK_REG_WO_OR)");
        FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_WO_OR(l_omic, l_mask),
                 "Error from putScom (MC_OMI_FIR_MASK_REG_WO_OR)");

        for(auto l_omi : l_omic.getChildren<fapi2::TARGET_TYPE_OMI>())
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_pos;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi, l_omi_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            if((l_omi_pos % 2) == 0)
            {
                // unmask DL0 firs if configured
                FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_WO_AND(l_omic),
                         "Error from prepScom (MC_OMI_FIR_MASK_REG_WO_AND)");
                FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_WO_AND(l_omic, ~MC_OMI_FIR_DL0),
                         "Error from putScom (MC_OMI_FIR_MASK_REG_WO_AND)");
                FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_WO_OR(l_omic),
                         "Error from prepScom (MC_OMI_FIR_MASK_REG_WO_OR)");
                FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_WO_OR(l_omic, MC_OMI_FIR_MASK & MC_OMI_FIR_DL0),
                         "Error from putScom (MC_OMI_FIR_MASK_REG_WO_OR)");
            }
            else
            {
                // unmask DL1 firs if configured
                FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_WO_AND(l_omic),
                         "Error from prepScom (MC_OMI_FIR_MASK_REG_WO_AND)");
                FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_WO_AND(l_omic, ~MC_OMI_FIR_DL1),
                         "Error from putScom (MC_OMI_FIR_MASK_REG_WO_AND)");
                FAPI_TRY(PREP_MC_OMI_FIR_MASK_REG_WO_OR(l_omic),
                         "Error from prepScom (MC_OMI_FIR_MASK_REG_WO_OR)");
                FAPI_TRY(PUT_MC_OMI_FIR_MASK_REG_WO_OR(l_omic, MC_OMI_FIR_MASK & MC_OMI_FIR_DL1),
                         "Error from putScom (MC_OMI_FIR_MASK_REG_WO_OR)");
            }
        }

        FAPI_TRY(PREP_MC_OMI_FIR_ACTION0_REG(l_omic),
                 "Error from prepScom (MC_OMI_FIR_ACTION0_REG)");
        FAPI_TRY(PUT_MC_OMI_FIR_ACTION0_REG(l_omic, MC_OMI_FIR_ACT0),
                 "Error from putScom (MC_OMI_FIR_ACTION0_REG)");

        FAPI_TRY(PREP_MC_OMI_FIR_ACTION1_REG(l_omic),
                 "Error from prepScom (MC_OMI_FIR_ACTION1_REG)");
        FAPI_TRY(PUT_MC_OMI_FIR_ACTION1_REG(l_omic, MC_OMI_FIR_ACT1),
                 "Error from putScom (MC_OMI_FIR_ACTION1_REG)");
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
