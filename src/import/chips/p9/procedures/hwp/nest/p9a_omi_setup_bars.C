/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9a_omi_setup_bars.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2019                        */
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
/// @file p9a_omi_setup_bars.H
/// @brief configure Axone inband address
///
/// Set the inband base address in the MC
/// driven by attributes representing system memory map.
///

// *HWP HWP Owner: Ben Gass bgass@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9a_omi_setup_bars.H>
#include <p9a_addr_ext.H>
#include <p9_fbc_utils.H>
#include <p9_mc_scom_addresses.H>
#include <p9a_misc_scom_addresses.H>
#include <p9a_misc_scom_addresses_fld.H>
#include <lib/inband/exp_inband.H>

//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------

fapi2::ReturnCode p9a_omi_setup_bars(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
    std::vector<uint64_t> l_base_addr_nm0;
    std::vector<uint64_t> l_base_addr_nm1;
    std::vector<uint64_t> l_base_addr_m;
    fapi2::buffer<uint64_t> l_mmio_bar;
    fapi2::buffer<uint64_t> l_cfg_bar;
    uint64_t l_base_addr_mmio;
    uint8_t l_pos;
    uint8_t l_mcc_pos;
    uint64_t l_ext_mask;

    // determine base address of chip MMIO range
    FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_target,
             EFF_FBC_GRP_CHIP_IDS,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    FAPI_TRY(p9a_get_ext_mask(l_ext_mask));

    FAPI_DBG("l_ext_mask: %x", l_ext_mask);
    FAPI_DBG("l_base_addr_mmio: 0x%llx", l_base_addr_mmio);

    for (auto l_mcc : i_target.getChildren<fapi2::TARGET_TYPE_MCC>())
    {
        fapi2::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        uint64_t l_omi_inband_addr = 0;
        fapi2::buffer<uint64_t> l_scom_data;

        auto l_omi_targets = l_mcc.getChildren<fapi2::TARGET_TYPE_OMI>();

        if (l_omi_targets.size() > 0)
        {

            // Set the sizes for the MMIO/Config bars
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mcc, l_pos),
                     "Error getting ATTR_CHIP_UNIT_POS, l_rc 0x%.8X",
                     (uint64_t)fapi2::current_err);

            l_scom_data.flush<0>();
            // 2GB cfg and MMIO
            l_scom_data.insertFromRight<P9A_MI_MCFGP0_MCFGPR0_CONFIGURATION_GROUP_SIZE,
                                        P9A_MI_MCFGP0_MCFGPR0_CONFIGURATION_GROUP_SIZE_LEN>(mss::exp::ib::EXPLR_IB_BAR_SIZE);
            l_scom_data.insertFromRight<P9A_MI_MCFGP0_MCFGPR0_MMIO_GROUP_SIZE,
                                        P9A_MI_MCFGP0_MCFGPR0_MMIO_GROUP_SIZE_LEN>(mss::exp::ib::EXPLR_IB_BAR_SIZE);

            // Write to reg
            if (l_pos % 2 == 0)
            {
                FAPI_INF("Write MCFGP0 reg 0x%.16llX, Value 0x%.16llX",
                         P9A_MI_MCFGP0, l_scom_data);
                FAPI_TRY(fapi2::putScom(l_mcc.getParent<fapi2::TARGET_TYPE_MI>(), P9A_MI_MCFGP0, l_scom_data),
                         "Error writing to MCS_MCFGP reg");
            }
            else
            {
                FAPI_INF("Write MCFGP1 reg 0x%.16llX, Value 0x%.16llX",
                         P9A_MI_MCFGP1, l_scom_data);
                FAPI_TRY(fapi2::putScom(l_mcc.getParent<fapi2::TARGET_TYPE_MI>(), P9A_MI_MCFGP1, l_scom_data),
                         "Error writing to MCS_MCFGP reg");
            }

            for (auto l_omi : l_omi_targets)
            {
                // retrieve OMI pos
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       l_omi,
                                       l_pos),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                // retrieve inband BAR offset
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET,
                                       l_omi,
                                       l_bar_offset),
                         "Error from FAPI_ATTR_GET (ATTR_OMI_INBAND_BAR_BASE_ADDR_OFFSET)");

                FAPI_DBG("l_bar_offset: 0x%llx", l_bar_offset);

                // If this is channel B, then the B bit must be set.  If it is not, then the B bit must not be set.
                FAPI_ASSERT( ((l_pos % 2) == 1) ==  // Is this B channel?
                             ((l_bar_offset & mss::exp::ib::EXPLR_IB_BAR_B_BIT) == mss::exp::ib::EXPLR_IB_BAR_B_BIT),

                             fapi2::PROC_OMI_SETUP_BARS_INVALID_BAR()
                             .set_TARGET(l_omi)
                             .set_BAR_VALUE(l_bar_offset),
                             "B Channel requires BAR size bit set");

                FAPI_ASSERT(((l_bar_offset & mss::exp::ib::EXPLR_IB_BAR_MASK_ZERO) == 0),
                            fapi2::PROC_OMI_SETUP_BARS_INVALID_BAR()
                            .set_TARGET(l_omi)
                            .set_BAR_VALUE(l_bar_offset),
                            "Bar size not honored");

                FAPI_ASSERT(((l_bar_offset & mss::exp::ib::EXPLR_IB_MMIO_OFFSET) == 0),
                            fapi2::PROC_OMI_SETUP_BARS_INVALID_BAR()
                            .set_TARGET(l_omi)
                            .set_BAR_VALUE(l_bar_offset),
                            "MMIO bit must not be set");

                l_omi_inband_addr = l_bar_offset;
            }

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Force A Bar value
            l_omi_inband_addr = l_omi_inband_addr & (~mss::exp::ib::EXPLR_IB_BAR_B_BIT);

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Add MMIO address for the chip
            l_omi_inband_addr = l_omi_inband_addr | l_base_addr_mmio;

            FAPI_DBG("l_omi_inband_addr: 0x%llx", l_omi_inband_addr);

            // Get cfg bar value
            fapi2::buffer<uint64_t> l_omi_inband_buf = l_omi_inband_addr;
            FAPI_DBG("l_omi_inband_buf: 0x%llx", l_omi_inband_buf);
            FAPI_TRY(extendBarAddress(l_ext_mask, l_omi_inband_buf, l_cfg_bar));

            FAPI_DBG("l_cfg_bar: 0x%llx", l_cfg_bar);

            // Get MMIO bar value
            l_omi_inband_addr = l_omi_inband_addr | mss::exp::ib::EXPLR_IB_MMIO_OFFSET;
            l_omi_inband_buf = l_omi_inband_addr;
            FAPI_DBG("l_omi_inband_buf: 0x%llx", l_omi_inband_buf);
            FAPI_TRY(extendBarAddress(l_ext_mask, l_omi_inband_buf, l_mmio_bar));

            FAPI_DBG("l_mmio_bar: 0x%llx", l_mmio_bar);

            // Write the channel cfg reg
            l_scom_data.flush<0>();
            l_scom_data.setBit<P9A_MI_MCFGPR0_CONFIGURATION_VALID>(); //Enable CFG
            l_scom_data.setBit<P9A_MI_MCFGPR0_MMIO_VALID>(); //Enable MMIO
            l_scom_data.insert<P9A_MI_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS,
                               P9A_MI_MCFGPR0_CONFIGURATION_GROUP_BASE_ADDRESS_LEN>(l_cfg_bar);
            l_scom_data.insert<P9A_MI_MCFGPR0_MMIO_GROUP_BASE_ADDRESS,
                               P9A_MI_MCFGPR0_MMIO_GROUP_BASE_ADDRESS_LEN>(l_mmio_bar);

            // get MI target to configure MCFGPR
            fapi2::Target<fapi2::TARGET_TYPE_MI> l_mi =
                l_mcc.getParent<fapi2::TARGET_TYPE_MI>();
            // retrieve DMI pos
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_mcc,
                                   l_mcc_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            // configure inband channel 0 MCFGPR0
            if(l_mcc_pos % 2 == 0)
            {
                FAPI_TRY(putScom(l_mi, P9A_MI_MCFGPR0, l_scom_data));
            }
            // configure inband channel 1 MCFGPR1
            else
            {
                FAPI_TRY(putScom(l_mi, P9A_MI_MCFGPR1, l_scom_data));
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
