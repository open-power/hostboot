/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9c_set_inband_addr.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017                             */
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
/// @file p9c_set_inband_addr.H
/// @brief configure Cumulus inband address
///
/// Set the inband base address in the MC
/// driven by attributes representing system memory map.
///

// *HWP HWP Owner: Yang Fan Liu shliuyf@cn.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9c_set_inband_addr.H>
#include <p9_fbc_utils.H>
#include <p9_mc_scom_addresses.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------
///
/// @brief configure Cumulus inband address
///
/// @param[in] i_target => Processor chip target
///
/// @return FAPI_RC_SUCCESS if the setup completes successfully, else error
//
fapi2::ReturnCode p9c_set_inband_addr(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    auto l_dmi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();
    fapi2::ATTR_DMI_INBAND_BAR_ENABLE_Type l_bar_enable;
    fapi2::ATTR_DMI_INBAND_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
    uint8_t l_dmi_pos;
    uint64_t l_base_addr_nm0, l_base_addr_nm1, l_base_addr_m, l_base_addr_mmio;
    uint64_t l_dmi_inband_addr;
    fapi2::buffer<uint64_t> l_scom_data;

    // determine base address of chip MMIO range
    FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_target,
             EFF_FBC_GRP_CHIP_IDS,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    for(auto l_dmi : l_dmi_chiplets)
    {
        // retrieve inband BAR enable
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DMI_INBAND_BAR_ENABLE, l_dmi, l_bar_enable),
                 "Error from FAPI_ATTR_GET (ATTR_DMI_INBAND_BAR_ENABLE)");

        if (l_bar_enable == fapi2::ENUM_ATTR_DMI_INBAND_BAR_ENABLE_ENABLE)
        {
            // retrieve inband BAR offset
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DMI_INBAND_BAR_BASE_ADDR_OFFSET, l_dmi, l_bar_offset),
                     "Error from FAPI_ATTR_GET (ATTR_DMI_INBAND_BAR_BASE_ADDR_OFFSET)");

            // form SCOM register format
            l_scom_data.flush<0>();
            // BAR address 8:38 into bits 4:34
            l_dmi_inband_addr = l_base_addr_mmio + l_bar_offset;
            l_scom_data.insert<4, 31, 8>(l_dmi_inband_addr);
            // Set valid(bit0 = 1), P9 mode(bit3 = 0)
            l_scom_data.setBit<0>();

            // get MI target to configure MCFGPR
            fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi = l_dmi.getParent<fapi2::TARGET_TYPE_MI>();
            // retrieve DMI pos
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_dmi, l_dmi_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            // configure inband channel 0 MCFGPR0
            if(l_dmi_pos % 2 == 0)
            {
                FAPI_TRY(fapi2::putScom(l_mi, MCS_MCRSVDE, l_scom_data),
                         "Error from putScom MCFGPR0 for DMI id: %d", l_dmi_pos);
            }
            // configure inband channel 1 MCFGPR1
            else
            {
                FAPI_TRY(fapi2::putScom(l_mi, MCS_MCRSVDF, l_scom_data),
                         "Error from putScom MCFGPR1 for DMI id: %d", l_dmi_pos);
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


