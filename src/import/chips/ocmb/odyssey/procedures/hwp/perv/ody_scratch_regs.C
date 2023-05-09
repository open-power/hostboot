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

    // scratch 5 -- SPI bus clock divider
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH5_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch5_reg = 0;
        fapi2::ATTR_SPI_BUS_DIV_REF_Type l_attr_spi_bus_div_ref;

        FAPI_DBG("Reading ATTR_SPI_BUS_DIV_REF");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPI_BUS_DIV_REF, i_target, l_attr_spi_bus_div_ref));

        l_scratch5_reg.insertFromRight<ATTR_SPI_BUS_DIV_REF_STARTBIT, ATTR_SPI_BUS_DIV_REF_LENGTH>(l_attr_spi_bus_div_ref);

        FAPI_DBG("Configurating MEMPORT target functional state");

        for (auto l_mp_target : i_target.getChildren<fapi2::TARGET_TYPE_MEM_PORT>())
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_chip_unit_pos = 0;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mp_target, l_chip_unit_pos));
            FAPI_TRY(l_scratch5_reg.setBit(l_chip_unit_pos + MEMPORT_FUNCTIONAL_STATE_STARTBIT));
        }

        FAPI_DBG("Setting up value of Scratch 5 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER5, l_scratch5_reg));

        l_scratch16_reg.setBit<SCRATCH5_REG_VALID_BIT>();
    }

    // scratch 6 -- PLL bucket/frequency selection
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH6_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch6_reg = 0;
        fapi2::ATTR_OCMB_PLL_BUCKET_Type l_ocmb_pll_bucket = 0;
        uint32_t l_freq_grid_mhz = 0;
        uint32_t l_freq_link_mhz = 0;

        // Host call (ody_sppe_config_update) will always invoke this code block to fill the PLL bucket
        // request.  DO NOT fill the PLL frequency field in the mailbox, this will be written by the SPPE (cmdtable).
        // Go ahead and init the host platform attribute state for the OCMB PLL bucket and OMI link frequency.
#ifndef __PPE__
        {
            FAPI_TRY(ody_scratch_regs_get_pll_bucket(i_target, l_ocmb_pll_bucket));
            FAPI_TRY(ody_scratch_regs_get_pll_freqs(i_target, l_ocmb_pll_bucket, l_freq_grid_mhz, l_freq_link_mhz));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_OCMB_PLL_BUCKET, i_target, l_ocmb_pll_bucket));
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_FREQ_OMI_MHZ, i_target, l_freq_link_mhz));
        }
#endif
        // SPPE call (ody_sppe_attr_setup) will run this code ONLY if the host does not fill
        // the mailbox (marking it valid).  We will additionally compute the PLL feedback in this case
        // and fill the mailbox -- I don't think this code path can reliably be used to boot Odyssey HW
        // at an arbitrary frequency (from the last boot, say) since the scratch attributes are not written
        // into the mailbox register until after the cmdtable HWPs run which consume them, but SPPE simics
        // testing appears to rely on this.
        FAPI_DBG("Reading ATTR_OCMB_PLL_BUCKET");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_PLL_BUCKET, i_target, l_ocmb_pll_bucket));
        l_scratch6_reg.insertFromRight<ATTR_OCMB_PLL_BUCKET_STARTBIT, ATTR_OCMB_PLL_BUCKET_LENGTH>(l_ocmb_pll_bucket);

#ifdef __PPE__
        {
            FAPI_DBG("Filling Grid frequency feedback");
            FAPI_TRY(ody_scratch_regs_get_pll_freqs(i_target, l_ocmb_pll_bucket, l_freq_grid_mhz, l_freq_link_mhz));
            l_scratch6_reg.insertFromRight<ATTR_OCMB_PLL_FREQ_STARTBIT, ATTR_OCMB_PLL_FREQ_LENGTH>(l_freq_grid_mhz);
        }
#endif

        FAPI_DBG("Setting up value of Scratch 6 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER6, l_scratch6_reg));

        l_scratch16_reg.setBit<SCRATCH6_REG_VALID_BIT>();
    }

    // scratch 7 -- clockstop-on-checkstop setup
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH7_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch7_reg = 0;
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

        l_scratch7_reg.insertFromRight<ATTR_CLOCKSTOP_ON_XSTOP_STARTBIT, ATTR_CLOCKSTOP_ON_XSTOP_LENGTH>
        (l_clockstop_on_xstop);

        FAPI_DBG("Setting up value of Scratch 7 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER7, l_scratch7_reg));

        l_scratch16_reg.setBit<SCRATCH7_REG_VALID_BIT>();
    }

    // scratch 8 -- PLL bypass/OCMB position
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH8_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch8_reg = 0;
        fapi2::ATTR_IO_TANK_PLL_BYPASS_Type l_attr_io_tank_pll_bypass;
        fapi2::ATTR_BUS_POS_Type l_bus_pos;

        FAPI_DBG("Reading IO tank PLL bypass attribute");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_TANK_PLL_BYPASS, i_target, l_attr_io_tank_pll_bypass));
        l_scratch8_reg.writeBit<ATTR_IO_TANK_PLL_BYPASS_BIT>(l_attr_io_tank_pll_bypass ==
                fapi2::ENUM_ATTR_IO_TANK_PLL_BYPASS_BYPASS);

        FAPI_DBG("Determining relative position");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BUS_POS, i_target, l_bus_pos));
        l_scratch8_reg.insertFromRight<ATTR_BUS_POS_STARTBIT, ATTR_BUS_POS_LENGTH>
        (l_bus_pos);

        FAPI_DBG("Setting up value of Scratch 8 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER8, l_scratch8_reg));

        l_scratch16_reg.setBit<SCRATCH8_REG_VALID_BIT>();
    }

    // scratch 11 -- FW mode flags
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH11_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch11_reg = 0;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        fapi2::ATTR_OCMB_BOOT_FLAGS_Type l_attr_ocmb_boot_flags;
        fapi2::ATTR_IS_SIMULATION_Type l_attr_is_simulation;

        FAPI_DBG("Reading ATTR_OCMB_BOOT_FLAGS");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_OCMB_BOOT_FLAGS, FAPI_SYSTEM, l_attr_ocmb_boot_flags),
                 "Error from FAPI_ATTR_GET (ATTR_OCMB_BOOT_FLAGS)");
        l_scratch11_reg.insertFromRight<ATTR_OCMB_BOOT_FLAGS_STARTBIT, ATTR_OCMB_BOOT_FLAGS_LENGTH>(l_attr_ocmb_boot_flags);

        FAPI_DBG("Reading ATTR_IS_SIMULATION");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, FAPI_SYSTEM, l_attr_is_simulation));
        l_scratch11_reg.insertFromRight<ATTR_IS_SIMULATION_STARTBIT, ATTR_IS_SIMULATION_LENGTH>(l_attr_is_simulation);

        FAPI_DBG("Setting up value of Scratch 11 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER11, l_scratch11_reg));

        l_scratch16_reg.setBit<SCRATCH11_REG_VALID_BIT>();
    }

    // scratch 12 -- dynamic inits
    if (i_update_all || !l_scratch16_reg.getBit<SCRATCH12_REG_VALID_BIT>())
    {
        fapi2::buffer<uint32_t> l_scratch12_reg = 0;
        fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC_Type l_dynamic_init_feature_vec = { 0 };

        FAPI_DBG("Reading ATTR_DYNAMIC_INIT_FEATURE_VEC");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DYNAMIC_INIT_FEATURE_VEC, i_target, l_dynamic_init_feature_vec),
                 "Error from FAPI_ATTR_GET (ATTR_DYNAMIC_INIT_FEATURE_VEC)");
        l_scratch12_reg.insertFromRight<ATTR_DYNAMIC_INIT_FEATURE_STARTBIT, ATTR_DYNAMIC_INIT_FEATURE_LENGTH>
        (l_dynamic_init_feature_vec[0] >> 32);

        FAPI_DBG("Setting up value of Scratch 12 mailbox register");
        FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER12, l_scratch12_reg));

        l_scratch16_reg.setBit<SCRATCH12_REG_VALID_BIT>();
    }

    FAPI_DBG("Setting up value of Scratch 16 mailbox register (valid)");
    FAPI_TRY(ody_scratch_regs_put_scratch(i_target, i_use_scom, SCRATCH_REGISTER16, l_scratch16_reg));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;

}
