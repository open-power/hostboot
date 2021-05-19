/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_ocmb_enable.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
/// @file p10_ocmb_enable.C
/// @brief Enable OCMB reference clocks and drop reset (FAPI2)
///
/// @author Ben Gass <bgass@us.ibm.com>
///

///
/// *HW HW Maintainer: Ben Gass <bgass@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_ocmb_enable.H>
#include <p10_scom_proc_5.H>
#include <p10_scom_proc_1.H>
#include <p10_scom_proc_6.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_ocmb_enable(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");
#ifndef __HOSTBOOT_MODULE
    const auto& l_omi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_PRESENT);
#else
    const auto& l_omi_chiplets = i_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL);
#endif
    using namespace scomt::proc;

    unsigned char l_omi_pos = 0;
    fapi2::buffer<uint64_t> l_clk_enable_bit = 0;
    fapi2::buffer<uint64_t> l_scom_buf = 0;

    for (const auto& l_omi : l_omi_chiplets)
    {
        const auto& l_ocmb_chiplets = l_omi.getChildren<fapi2::TARGET_TYPE_OCMB_CHIP>();

        // If there is a ocmb connected, means the ocmb chip is active
        if (!l_ocmb_chiplets.empty())
        {
            uint8_t l_omi_refclock_swizzle = 0;
            // Get the OMI pos (it is supposed to be the same as the ocmb
            // chip pos)
            // The intention here is to get the relative pos number of OMI<->Ocmb
            // pair within the scope of a chip, and the OMI position unit pos is
            // always the same as the connected Ocmb chip. For example,
            // since we have up to 8 ocmbs connected per chip, the relative unit
            // pos here should always be within 0~7 for each chip in a multi-socket system.
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi,
                                   l_omi_pos), "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OMI_REFCLOCK_SWIZZLE, l_omi, l_omi_refclock_swizzle),
                     "Error from FAPI_ATTR_GET (ATTR_OMI_REFCLOCK_SWIZZLE)");

            FAPI_DBG("OCMB ID: %i, REFCLK DRIVE BIT: %i", l_omi_pos, l_omi_refclock_swizzle);

            // Legal bits are from PERV_ROOT_CTRL7_TPFSI_OFFCHIP_REFCLK_EN_DC
            // to PERV_ROOT_CTRL7_TPFSI_OFFCHIP_REFCLK_EN_DC_LEN - 4, there
            // are 4 bits for NVLINK that shouldn't be used by ocmb.
            const auto MIN_SWIZZLE = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEM0_REFCLK_DRVR_EN_DC;
            const auto MAX_SWIZZLE = TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_SET_TP_MEMF_REFCLK_DRVR_EN_DC;
            FAPI_ASSERT((l_omi_refclock_swizzle >= MIN_SWIZZLE)
                        && (l_omi_refclock_swizzle <= MAX_SWIZZLE),
                        fapi2::P10_OCMB_ENABLE_SWIZZLE_BIT_OUT_OF_RANGE_ERROR()
                        .set_TARGET(l_omi)
                        .set_BIT(l_omi_refclock_swizzle)
                        .set_MIN(MIN_SWIZZLE)
                        .set_MAX(MAX_SWIZZLE),
                        "Swizzle bit: %i, allowed range: %i to %i", l_omi_refclock_swizzle,
                        MIN_SWIZZLE,
                        MAX_SWIZZLE
                       );

            FAPI_TRY(l_clk_enable_bit.setBit(l_omi_refclock_swizzle),
                     "Refclock bit [%i] out of range!", l_omi_refclock_swizzle);
        }
    }

    // We have at least 1 ocmb active then proceed to set the register
    if (l_clk_enable_bit != 0)
    {
        // Enable the reference clocks
        FAPI_TRY(GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(i_target, l_scom_buf));

        l_scom_buf |= l_clk_enable_bit;
        FAPI_DBG("Setting ROOT_CTRL7 to: 0x%016lx", l_scom_buf);

        FAPI_TRY(PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL7_RW(i_target, l_scom_buf));

        //Wait 500 milliseconds - anything much less seems to lead to SPI issues in Explorer
        fapi2::delay(500 * 1000000, 10000);

        // Toggle the reset signal
        FAPI_TRY(GET_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_RW(i_target, l_scom_buf));
        CLEAR_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_TPFSI_IO_OCMB_RESET_EN(l_scom_buf);
        FAPI_TRY(PUT_TP_TPVSB_FSI_W_MAILBOX_FSXCOMP_FSXLOG_ROOT_CTRL0_RW(i_target, l_scom_buf));

    }

    FAPI_DBG("End");

fapi_try_exit:
    return fapi2::current_err;
}
