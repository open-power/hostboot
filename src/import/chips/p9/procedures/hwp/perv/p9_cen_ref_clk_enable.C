/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_cen_ref_clk_enable.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file p9_cen_ref_clk_enable.C
/// @brief Enable Centaur reference clocks (FAPI2)
///
/// @author Peng Fei GOU <shgoupf@cn.ibm.com>
///

//
// *HWP HWP Owner: Peng Fei GOU <shgoupf@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Perv
// *HWP Level: 3
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_cen_ref_clk_enable.H>
#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_cen_ref_clk_enable(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
    auto l_dmi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_DMI>();
    uint8_t l_master;
    unsigned char l_cen_pos = 0;
    fapi2::buffer<uint64_t> l_clk_enable_bit = 0;
    fapi2::buffer<uint64_t> l_scom_buf = 0;
    fapi2::buffer<uint32_t> l_cfam_buf = 0;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target, l_master),
             "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");

    for (auto l_dmi : l_dmi_chiplets)
    {
        uint8_t l_dmi_refclock_swizzle = 0;
        auto l_cen_chiplets = l_dmi.getChildren<fapi2::TARGET_TYPE_MEMBUF_CHIP>();

        // If there is a membuf connected, means the centaur chip is active
        if (!l_cen_chiplets.empty())
        {
            // Get the DMI pos (it is supposed to be the same as the centaur
            // chip pos)
            // The intention here is to get the relative pos number of DMI<->Centaur
            // pair within the scope of a chip, and the DMI position unit pos is
            // always the same as the connected Centaur chip. For example,
            // since we have up to 8 centaurs connected per chip, the relative unit
            // pos here should always be within 0~7 for each chip in a multi-socket system.
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_dmi,
                                   l_cen_pos), "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DMI_REFCLOCK_SWIZZLE, l_dmi, l_dmi_refclock_swizzle),
                     "Error from FAPI_ATTR_GET (ATTR_DMI_REFCLOCK_SWIZZLE)");

            FAPI_DBG("CEN ID: %i, REFCLK DRIVE BIT: %i", l_cen_pos, l_dmi_refclock_swizzle);

            // Legal bits are from PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC
            // to PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN - 4, there
            // are 4 bits for NVLINK that shouldn't be used by centaur.
            FAPI_ASSERT((l_dmi_refclock_swizzle >= PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC)
                        && (l_dmi_refclock_swizzle < PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC
                            + PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN
                            - PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC_LEN),
                        fapi2::P9_CEN_REF_CLK_ENABLE_SWIZZLE_BIT_OUT_OF_RANGE_ERROR().set_TARGET(l_dmi).set_BIT(l_dmi_refclock_swizzle),
                        "Swizzle bit: %i, allowed range: %i to %i", l_dmi_refclock_swizzle,
                        PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC,
                        PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC
                        + PERV_ROOT_CTRL6_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN
                        - PERV_ROOT_CTRL6_TSFSI_NV_REFCLK_EN_DC_LEN
                       );

            FAPI_TRY(l_clk_enable_bit.setBit(l_dmi_refclock_swizzle),
                     "Refclock bit [%i] out of range!", l_dmi_refclock_swizzle);
        }
    }

    // We have at least 1 centaur active then proceed to set the register
    if (l_clk_enable_bit != 0)
    {
        // Set the root control 6 register
        if (l_master)
        {
            FAPI_TRY(fapi2::getScom(i_target, PERV_ROOT_CTRL6_SCOM, l_scom_buf),
                     "Error from getScom to PERV_ROOT_CTRL6_SCOM");
            l_scom_buf |= l_clk_enable_bit;
            FAPI_DBG("Setting ROOT_CTRL6 to: %#lx", l_scom_buf());
            FAPI_TRY(fapi2::putScom(i_target, PERV_ROOT_CTRL6_SCOM, l_scom_buf),
                     "Error from putScom to PERV_ROOT_CTRL6_SCOM");
        }
        else
        {
            fapi2::buffer<uint32_t> l_tmp_buf;
            l_clk_enable_bit.extractToRight<0, 32>(l_tmp_buf);
            FAPI_TRY(fapi2::getCfamRegister(i_target, PERV_ROOT_CTRL6_FSI, l_cfam_buf),
                     "Error from getCfamRegister to PERV_ROOT_CTRL6_FSI");
            l_cfam_buf |= l_tmp_buf;
            FAPI_DBG("Setting ROOT_CTRL6 to: %#x", l_cfam_buf());
            FAPI_TRY(fapi2::putCfamRegister(i_target, PERV_ROOT_CTRL6_FSI, l_cfam_buf),
                     "Error from putCfamRegister to PERV_ROOT_CTRL6_FSI");
        }
    }

    FAPI_DBG("End");

fapi_try_exit:
    return fapi2::current_err;
}
