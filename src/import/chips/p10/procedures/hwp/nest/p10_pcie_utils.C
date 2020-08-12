/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pcie_utils.C $   */
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
///
/// @file p10_pcie_utils.C
/// @brief Common utility functions to support PCIE related HWPs.
///
/// *HWP HW Maintainer: Thi Tran <thi@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB, Cronus
///


//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pcie_utils.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

// Doxygen is in header file
fapi2::ReturnCode isPHBEnabled(const fapi2::Target<fapi2::TARGET_TYPE_PHB>& i_target,
                               bool& o_enabled)
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_UNIT_POS_Type l_phb_id;
    o_enabled = false;
    uint8_t l_phb_active[NUM_PHB_PER_PEC] = {0};
    fapi2::Target<fapi2::TARGET_TYPE_PEC> l_pecTarget = i_target.getParent<fapi2::TARGET_TYPE_PEC>();

    //Get the PHB id
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, i_target, l_phb_id),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");
    // Get active PEC's PHB active attributes
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PCIE_PHB_ACTIVE, l_pecTarget, l_phb_active),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PCIE_PHB_ACTIVE");
    FAPI_DBG("PHB id %d: Active 0=%d, 1=%d, 2=%d",
             l_phb_id, l_phb_active[0], l_phb_active[1], l_phb_active[2]);

    if ( l_phb_active[(l_phb_id % NUM_PHB_PER_PEC)] ==
         fapi2::ENUM_ATTR_PROC_PCIE_PHB_ACTIVE_ENABLE )
    {
        o_enabled = true;
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
