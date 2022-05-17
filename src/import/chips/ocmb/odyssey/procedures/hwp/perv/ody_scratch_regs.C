/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/perv/ody_scratch_regs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
//------------------------------------------------------------------------------
/// @file  ody_scratch_regs.C
/// @brief Definition of scratch register fields shared between
///        ody_sppe_config_update and ody_sppe_attr_setup
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
//------------------------------------------------------------------------------

#include <ody_scom_perv.H>
#include <ody_scratch_regs.H>
#include <ody_scratch_regs_utils.H>

///
/// @brief Scratch register read function -- returns 32-bit scratch register data
///
/// @param[in]   i_target_chip             Reference to TARGET_TYPE_OCMB_CHIP
/// @param[in]   i_use_scom                True=perform all MBOX accesses via SCOM
///                                        False=use CFAM
/// @param[in]   i_scratch_reg             Enum identifying scratch register to read
/// @param[out]  o_data                    Scratch register read data
///
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode
ody_scratch_regs_get_scratch(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_chip,
    const bool i_use_scom,
    const ody_scratch_reg_id_t& i_scratch_reg,
    fapi2::buffer<uint32_t>& o_data)
{
    if (!i_use_scom)
    {
        FAPI_ASSERT(!fapi2::is_platform<fapi2::PLAT_SBE>(),
                    fapi2::ODY_SCRATCH_REGS_INVALID_ACCESS_ERR()
                    .set_TARGET_CHIP(i_target_chip)
                    .set_USE_SCOM(i_use_scom),
                    "CFAM access unsupported on PPE platform!");

#ifndef __PPE__
        FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                        i_scratch_reg.cfam_addr,
                                        o_data),
                 "Error reading Scratch %d mailbox register (cfam)", i_scratch_reg.num);
#endif
    }
    else
    {
        fapi2::buffer<uint64_t> l_scom_data;
        FAPI_TRY(fapi2::getScom(i_target_chip,
                                i_scratch_reg.scom_addr,
                                l_scom_data),
                 "Error reading Scratch %d mailbox register (scom)", i_scratch_reg.num);

        o_data.insert<0, 32, 0>(l_scom_data);
    }

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Scratch register write function
///
/// @param[in]   i_target_chip             Reference to TARGET_TYPE_OCMB_CHIP
/// @param[in]   i_use_scom                True=perform all MBOX accesses via SCOM
///                                        False=use CFAM
/// @param[in]   i_scratch_reg             Enum identifying scratch register to read
/// @param[out]  o_data                    Scratch register read data
///
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode
ody_scratch_regs_put_scratch(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target_chip,
    const bool i_use_scom,
    const ody_scratch_reg_id_t& i_scratch_reg,
    const fapi2::buffer<uint32_t> i_data)
{
    if (!i_use_scom)
    {
        FAPI_ASSERT(!fapi2::is_platform<fapi2::PLAT_SBE>(),
                    fapi2::ODY_SCRATCH_REGS_INVALID_ACCESS_ERR()
                    .set_TARGET_CHIP(i_target_chip)
                    .set_USE_SCOM(i_use_scom),
                    "CFAM access unsupported on PPE platform!");

#ifndef __PPE__
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        i_scratch_reg.cfam_addr,
                                        i_data),
                 "Error writing Scratch %d mailbox register (cfam)", i_scratch_reg.num);
#endif
    }
    else
    {
        fapi2::buffer<uint64_t> l_scom_data;
        l_scom_data.insert<0, 32, 0>(i_data);
        FAPI_TRY(fapi2::putScom(i_target_chip,
                                i_scratch_reg.scom_addr,
                                l_scom_data),
                 "Error writing Scratch %d mailbox register (scom)", i_scratch_reg.num);
    }

fapi_try_exit:
    return fapi2::current_err;
}


// doxygen in header
fapi2::ReturnCode ody_scratch_regs_update(
    const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
    const bool i_update_all,
    const bool i_use_scom)
{
    using namespace scomt::perv;

    FAPI_DBG("Start");

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::buffer<uint32_t> l_scratch16_reg = 0;

    FAPI_DBG("Reading value of Scratch 16 mailbox register (valid)");
    FAPI_TRY(ody_scratch_regs_get_scratch(i_target, i_use_scom, SCRATCH_REGISTER16, l_scratch16_reg));

    // scratch 6 -- SPI bus clock divider
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH6_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch6_reg = 0;
        fapi2::ATTR_SPI_BUS_DIV_REF_Type l_attr_spi_bus_div_ref;

        FAPI_DBG("Reading ATTR_SPI_BUS_DIV_REF");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPI_BUS_DIV_REF, i_target, l_attr_spi_bus_div_ref));

        l_scratch6_reg.insertFromRight<ATTR_SPI_BUS_DIV_REF_STARTBIT, ATTR_SPI_BUS_DIV_REF_LENGTH>(l_attr_spi_bus_div_ref);

        FAPI_DBG("Setting up value of Scratch 6 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER6, l_scratch6_reg));

        l_scratch16_reg.setBit<SCRATCH6_REG_VALID_BIT>();
    }

    // scratch 7 -- PLL bucket/frequency selection
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH7_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch7_reg = 0;
        fapi2::ATTR_OCMB_PLL_BUCKET_Type l_ocmb_pll_bucket = 0;

#ifndef __PPE__
        {
            FAPI_TRY(ody_scratch_regs_get_pll_bucket(i_target, l_ocmb_pll_bucket));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_OCMB_PLL_BUCKET, i_target, l_ocmb_pll_bucket));
        }
#endif
        FAPI_DBG("Reading ATTR_OCMB_PLL_BUCKET");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_PLL_BUCKET, i_target, l_ocmb_pll_bucket));

        l_scratch7_reg.insertFromRight<ATTR_OCMB_PLL_BUCKET_STARTBIT, ATTR_OCMB_PLL_BUCKET_LENGTH>(l_ocmb_pll_bucket);

        FAPI_DBG("Setting up value of Scratch 7 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER7, l_scratch7_reg));

        l_scratch16_reg.setBit<SCRATCH7_REG_VALID_BIT>();
    }

    // scratch 8 -- clockstop-on-checkstop setup
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH8_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch8_reg = 0;
        fapi2::ATTR_CLOCKSTOP_ON_XSTOP_Type l_attr_clockstop_on_xstop;
        uint8_t l_clockstop_on_xstop = ATTR_CLOCKSTOP_ON_XSTOP_DISABLED;

        FAPI_DBG("Reading ATTR_CLOCKSTOP_ON_XSTOP");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCKSTOP_ON_XSTOP, i_target, l_attr_clockstop_on_xstop));

        if (l_attr_clockstop_on_xstop == fapi2::ENUM_ATTR_CLOCKSTOP_ON_XSTOP_STOP_ON_XSTOP)
        {
            l_clockstop_on_xstop = ATTR_CLOCKSTOP_ON_XSTOP_XSTOP;
        }
        else if (l_attr_clockstop_on_xstop == fapi2::ENUM_ATTR_CLOCKSTOP_ON_XSTOP_STOP_ON_XSTOP_AND_SPATTN)
        {
            l_clockstop_on_xstop = ATTR_CLOCKSTOP_ON_XSTOP_XSTOP_SPATTN;
        }
        else if (l_attr_clockstop_on_xstop == fapi2::ENUM_ATTR_CLOCKSTOP_ON_XSTOP_STOP_ON_STAGED_XSTOP)
        {
            l_clockstop_on_xstop = ATTR_CLOCKSTOP_ON_XSTOP_STAGED_XSTOP;
        }
        else
        {
            FAPI_INF("Unexpected value 0x%02x for ATTR_CLOCKSTOP_ON_XSTOP, defaulting to DISABLED",
                     l_attr_clockstop_on_xstop);
        }

        l_scratch8_reg.insertFromRight<ATTR_CLOCKSTOP_ON_XSTOP_STARTBIT, ATTR_CLOCKSTOP_ON_XSTOP_LENGTH>
        (l_clockstop_on_xstop);

        FAPI_DBG("Setting up value of Scratch 8 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER8, l_scratch8_reg));

        l_scratch16_reg.setBit<SCRATCH8_REG_VALID_BIT>();
    }

    // scratch 9 -- PLL bypass/OCMB position
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH9_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch9_reg = 0;
        fapi2::ATTR_IO_TANK_PLL_BYPASS_Type l_attr_io_tank_pll_bypass;
        fapi2::ATTR_OCMB_REL_POS_Type l_ocmb_rel_pos;

        FAPI_DBG("Reading IO tank PLL bypass attribute");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_TANK_PLL_BYPASS, i_target, l_attr_io_tank_pll_bypass));
        l_scratch9_reg.writeBit<ATTR_IO_TANK_PLL_BYPASS_BIT>(l_attr_io_tank_pll_bypass ==
                fapi2::ENUM_ATTR_IO_TANK_PLL_BYPASS_BYPASS);

        FAPI_DBG("Determining relative position");
#ifndef __PPE__
        {
            fapi2::Target<fapi2::TARGET_TYPE_OMI> l_omi_target;
            FAPI_TRY(i_target.getOtherEnd(l_omi_target));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_omi_target, l_ocmb_rel_pos));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_OCMB_REL_POS, i_target, l_ocmb_rel_pos));
        }
#endif
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_REL_POS, i_target, l_ocmb_rel_pos));
        l_scratch9_reg.insertFromRight<ATTR_OCMB_REL_POS_STARTBIT, ATTR_OCMB_REL_POS_LENGTH>
        (l_ocmb_rel_pos);

        FAPI_DBG("Setting up value of Scratch 9 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER9, l_scratch9_reg));

        l_scratch16_reg.setBit<SCRATCH9_REG_VALID_BIT>();
    }

    FAPI_DBG("Setting up value of Scratch 16 mailbox register (valid)");
    FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER16, l_scratch16_reg));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}
