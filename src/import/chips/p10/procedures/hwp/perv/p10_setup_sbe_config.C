/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_setup_sbe_config.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file  p10_setup_sbe_config.C
///
/// @brief proc setup sbe config
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#include <p10_setup_sbe_config.H>
#include <p10_scom_perv.H>
#include <p10_sbe_scratch_regs.H>
#include <p10_frequency_buckets.H>

///
/// @brief Calculate GARD vector based on functional target states
///
/// @tparam T template parameter, target type
/// @param[in]    i_target_chip  Processor chip target
/// @param[out]   o_gard_vector  GARD vector (1-bit indicates non-functional)
///                              valid data left-aligned from 0..<num chiplets of type T-1>
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
template<fapi2::TargetType T>
fapi2::ReturnCode
p10_sbe_scratch_calc_gard_vector(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t& o_gard_vector)
{
    // default to non-functional
    fapi2::buffer<uint32_t> l_functional = 0;
    fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE, FAPI_SYSTEM, l_attr_contained_ipl_type),
             "Error from FAPI_ATTR_GET (ATTR_CONTAINED_IPL_TYPE)");

    // in contained modes, no desire to enable async chiplets, use gard vector
    // content to enforce this
    if (l_attr_contained_ipl_type != fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE)
    {
        if ((T == fapi2::TARGET_TYPE_PEC)  ||
            (T == fapi2::TARGET_TYPE_MC)   ||
            (T == fapi2::TARGET_TYPE_PAUC) ||
            (T == fapi2::TARGET_TYPE_PAU)  ||
            (T == fapi2::TARGET_TYPE_IOHS))
        {
            // maintain non-functional default
            goto fapi_try_exit;
        }
    }

    // determine set of functional targets
    for (const auto& l_tgt : i_target_chip.getChildren<T>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_tgt, l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, functional)");
        FAPI_TRY(l_functional.setBit(l_unit_pos),
                 "Error from setBit (functional, unit target pos: %d)", l_unit_pos);
    }

    // in non-contained mode, PAUC chiplets may never be deconfigured
    if ((l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE) &&
        (T == fapi2::TARGET_TYPE_PAUC))
    {
        fapi2::buffer<uint32_t> l_present = 0;

        for (const auto& l_tgt : i_target_chip.getChildren<T>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_tgt, l_unit_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, present)");
            FAPI_TRY(l_present.setBit(l_unit_pos),
                     "Error from setBit (present, unit target pos: %d)", l_unit_pos);
        }

        FAPI_ASSERT(l_present == l_functional,
                    fapi2::P10_SBE_SCRATCH_REGS_PAUC_GARD_ERR()
                    .set_TARGET_CHIP(i_target_chip)
                    .set_CONTAINED_IPL_TYPE(l_attr_contained_ipl_type)
                    .set_PAUC_FUNCTIONAL(l_functional)
                    .set_PAUC_PRESENT(l_present),
                    "PAUC chiplets may not be deconfigured for current IPL type!");
    }

fapi_try_exit:
    FAPI_DBG("Functional  : 0x%08X", static_cast<unsigned int>(l_functional));
    o_gard_vector = ~l_functional;
    FAPI_DBG("Gard vector : 0x%08X", o_gard_vector);

    return fapi2::current_err;
}


///
/// @brief Calculate IOHS region GARD vectors based on functional target states
///        and designated link usage
///
/// @param[in]    i_target_chip      Processor chip target
/// @param[out]   o_ndl_gard_vector  NDL GARD vector (1-bit indicates non-functional)
///                                  valid data left-aligned from 0..7
///
/// @return fapi::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p10_sbe_scratch_calc_iohs_region_gard_vectors(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    uint32_t& o_ndl_gard_vector)
{
    fapi2::buffer<uint32_t> l_ndl_functional = 0;

    for (const auto& l_tgt : i_target_chip.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        fapi2::ATTR_IOHS_CONFIG_MODE_Type l_iohs_config_mode;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE, l_tgt, l_iohs_config_mode),
                 "Error from FAPI_ATTR_GET (ATTR_IOHS_CONFIG_MODE");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_tgt, l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        if ((l_iohs_config_mode != fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX) &&
            (l_iohs_config_mode != fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA))
        {
            FAPI_TRY(l_ndl_functional.setBit(l_unit_pos));
        }
    }

    o_ndl_gard_vector = ~l_ndl_functional;

fapi_try_exit:
    return fapi2::current_err;
}


///
/// @brief Lookup MC frequency bucket attribute values given platform frequency
///        attributes
///
/// @param[in] i_target_chip        Processor chip target
/// @param[in] o_attr_mc_pll_bucket PLL bucket attribute value
///
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode
p10_sbe_scratch_regs_get_mc_pll_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    fapi2::ATTR_MC_PLL_BUCKET_Type o_attr_mc_pll_bucket)
{
    FAPI_DBG("Start");

    for (const auto l_mc_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_MC>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        fapi2::ATTR_FREQ_MC_MHZ_Type l_attr_freq_mc_mhz;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_num;
        bool l_bucket_found = false;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MC_MHZ, l_mc_target, l_attr_freq_mc_mhz),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_MC_MHZ)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_unit_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        for (auto l_bucket = 0; l_bucket < P10_NUM_MC_PLL_BUCKETS; l_bucket++)
        {
            if (l_attr_freq_mc_mhz == P10_MC_PLL_BUCKETS[l_bucket].freq_grid_mhz)
            {
                l_bucket_found = true;
                o_attr_mc_pll_bucket[l_unit_num] = l_bucket;
                break;
            }
        }

        FAPI_ASSERT(l_bucket_found,
                    fapi2::P10_SBE_SCRATCH_REGS_MC_FREQ_LOOKUP_ERR()
                    .set_TARGET_CHIP(i_target_chip)
                    .set_TARGET_MC(l_mc_target)
                    .set_FREQ_MC_MHZ(l_attr_freq_mc_mhz),
                    "Requested MC frequency (%d MHz) not found in p10_frequency_buckets.H!",
                    l_attr_freq_mc_mhz);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Lookup IOHS frequency bucket attribute values given platform frequency
///        attributes
///
/// @param[in] i_target_chip          Processor chip target
/// @param[in] o_attr_iohs_pll_bucket PLL bucket attribute value
///
/// @return fapi2::ReturnCode
///
fapi2::ReturnCode
p10_sbe_scratch_regs_get_iohs_pll_bucket(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
    fapi2::ATTR_IOHS_PLL_BUCKET_Type o_attr_iohs_pll_bucket)
{
    FAPI_DBG("Start");

    for (const auto l_iohs_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL))
    {
        fapi2::ATTR_FREQ_IOHS_MHZ_Type l_attr_freq_iohs_mhz;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_num;
        bool l_bucket_found = false;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_MHZ, l_iohs_target, l_attr_freq_iohs_mhz),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_IOHS_MHZ)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_unit_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        for (auto l_bucket = 0; l_bucket < P10_NUM_IOHS_PLL_BUCKETS; l_bucket++)
        {
            if (l_attr_freq_iohs_mhz == P10_IOHS_PLL_BUCKETS[l_bucket].freq_grid_mhz)
            {
                l_bucket_found = true;
                o_attr_iohs_pll_bucket[l_unit_num] = l_bucket;
                break;
            }
        }

        FAPI_ASSERT(l_bucket_found,
                    fapi2::P10_SBE_SCRATCH_REGS_IOHS_FREQ_LOOKUP_ERR()
                    .set_TARGET_CHIP(i_target_chip)
                    .set_TARGET_IOHS(l_iohs_target)
                    .set_FREQ_IOHS_MHZ(l_attr_freq_iohs_mhz),
                    "Requested IOHS frequency (%d MHz) not found in p10_frequency_buckets.H!",
                    l_attr_freq_iohs_mhz);

    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// description in header
fapi2::ReturnCode p10_setup_sbe_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip)
{
    using namespace scomt::perv;

    fapi2::buffer<uint32_t> l_scratch8_reg = 0;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_INF("p10_setup_sbe_config::  Entering ...");

    {
        fapi2::buffer<uint32_t> l_cbs_cs_reg;
        fapi2::ATTR_SECURITY_MODE_Type l_attr_security_mode;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SECURITY_MODE, FAPI_SYSTEM, l_attr_security_mode),
                 "Error from FAPI_ATTR_GET (ATTR_SECURITY_MODE)");

        if (l_attr_security_mode == 0)
        {
            // The Secure Access Bit is only writeable on DD1 chips,
            // so we won't need to put an EC level switch in here.
            FAPI_DBG("Attempting to disable security");
            FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_CBS_CS_FSI,
                                            l_cbs_cs_reg),
                     "Error reading CBS Control/Status register");
            l_cbs_cs_reg.clearBit<FSXCOMP_FSXLOG_CBS_CS_SECURE_ACCESS_BIT>();
            FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                            FSXCOMP_FSXLOG_CBS_CS_FSI,
                                            l_cbs_cs_reg),
                     "Error writing CBS Control/Status register");
        }
    }

    {
        fapi2::buffer<uint32_t> l_perv_ctrl0;
        fapi2::ATTR_FUSED_CORE_MODE_Type l_attr_fused_core_mode;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE, FAPI_SYSTEM, l_attr_fused_core_mode),
                 "Error from FAPI_ATTR_GET (ATTR_FUSED_CORE_MODE)");

        l_perv_ctrl0.flush<0>().setBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>();
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        (l_attr_fused_core_mode == fapi2::ENUM_ATTR_FUSED_CORE_MODE_CORE_FUSED) ?
                                        FSXCOMP_FSXLOG_PERV_CTRL0_SET_FSI :
                                        FSXCOMP_FSXLOG_PERV_CTRL0_CLEAR_FSI,
                                        l_perv_ctrl0),
                 "Error updating Fused mode control in PERV_CTRL0");

        FAPI_TRY(fapi2::getCfamRegister(i_target_chip, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, l_perv_ctrl0),
                 "Error reading PERV_CTRL0_COPY");
        l_perv_ctrl0.writeBit<FSXCOMP_FSXLOG_PERV_CTRL0_TP_OTP_SCOM_FUSED_CORE_MODE>(
            l_attr_fused_core_mode == fapi2::ENUM_ATTR_FUSED_CORE_MODE_CORE_FUSED);
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip, FSXCOMP_FSXLOG_PERV_CTRL0_COPY_FSI, l_perv_ctrl0),
                 "Error writing PERV_CTRL0_COPY");
    }

    FAPI_TRY(fapi2::getCfamRegister(i_target_chip,
                                    FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI,
                                    l_scratch8_reg),
             "Error reading Scratch 8 mailbox register");

    // set_scratch1_reg -- set EQ chiplet PG
    {
        fapi2::buffer<uint32_t> l_scratch1_reg = 0;
        uint32_t l_core_gard_vector;

        // CORE
        FAPI_DBG("Calculating CORE region gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_CORE>(i_target_chip,
                 l_core_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (core)");
        l_scratch1_reg.insert<CORE_GARD_STARTBIT, CORE_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_core_gard_vector);

        FAPI_DBG("Setting up value of Scratch 1 mailbox register");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_1_FSI,
                                        l_scratch1_reg),
                 "Error writing Scratch 1 mailbox register");

        l_scratch8_reg.setBit<SCRATCH1_REG_VALID_BIT>();
    }

    // set_scratch2_reg -- set TP/N0/N1/PCI/MC/PAU/IOHS chiplet PG
    {
        fapi2::buffer<uint32_t> l_scratch2_reg = 0;
        uint32_t l_pci_gard_vector;
        uint32_t l_nmmu_gard_vector;
        uint32_t l_mc_gard_vector;
        uint32_t l_pauc_gard_vector;
        uint32_t l_pau_gard_vector;
        uint32_t l_iohs_gard_vector;

        // PCI
        FAPI_DBG("Calculating PCI chiplet gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_PEC>(i_target_chip,
                 l_pci_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (pec)");
        l_scratch2_reg.insert<PCI_GARD_STARTBIT, PCI_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_pci_gard_vector);

        // NMMU1
        FAPI_DBG("Calculating NMMU region gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_NMMU>(i_target_chip,
                 l_nmmu_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (nmmu)");
        l_scratch2_reg.insert<NMMU1_GARD_BIT, 1, 1>(l_nmmu_gard_vector);

        // MC
        FAPI_DBG("Calculating MC chiplet gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_MC>(i_target_chip,
                 l_mc_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (mc)");
        l_scratch2_reg.insert<MC_GARD_STARTBIT, MC_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_mc_gard_vector);

        // PAUC
        FAPI_DBG("Calculating PAUC chiplet gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_PAUC>(i_target_chip,
                 l_pauc_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (pauc)");
        l_scratch2_reg.insert<PAUC_GARD_STARTBIT, PAUC_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_pauc_gard_vector);

        // PAU
        FAPI_DBG("Calculating PAU region gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_PAU>(i_target_chip,
                 l_pau_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (pau)");
        l_scratch2_reg.insert<PAU_GARD_STARTBIT, PAU_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_pau_gard_vector);

        // IOHS
        FAPI_DBG("Calculating IOHS chiplet gard vector");
        FAPI_TRY(p10_sbe_scratch_calc_gard_vector<fapi2::TARGET_TYPE_IOHS>(i_target_chip,
                 l_iohs_gard_vector),
                 "Error from p10_sbe_scratch_calc_gard_vector (iohs)");
        l_scratch2_reg.insert<IOHS_GARD_STARTBIT, IOHS_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_iohs_gard_vector);

        FAPI_DBG("Setting up value of Scratch 2 mailbox register");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_2_FSI,
                                        l_scratch2_reg),
                 "Error writing Scratch 2 mailbox register");

        l_scratch8_reg.setBit<SCRATCH2_REG_VALID_BIT>();
    }

    // set_scratch3_reg -- FW Mode/Control flags
    {
        fapi2::buffer<uint32_t> l_scratch3_reg = 0;
        fapi2::ATTR_BOOT_FLAGS_Type l_attr_boot_flags;

        FAPI_DBG("Reading ATTR_BOOT_FLAGS");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_FLAGS, FAPI_SYSTEM, l_attr_boot_flags),
                 "Error from FAPI_ATTR_GET (ATTR_BOOT_FLAGS)");
        l_scratch3_reg.insertFromRight<ATTR_BOOT_FLAGS_STARTBIT, ATTR_BOOT_FLAGS_LENGTH>(l_attr_boot_flags);

        FAPI_DBG("Setting up value of Scratch 3 mailbox register");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_3_FSI,
                                        l_scratch3_reg),
                 "Error writing Scratch 3 mailbox register");

        l_scratch8_reg.setBit<SCRATCH3_REG_VALID_BIT>();
    }

    // set_scratch4_reg -- Nest/Boot frequency
    {
        fapi2::buffer<uint32_t> l_scratch4_reg = 0;
        fapi2::ATTR_SPI_BUS_DIV_REF_Type l_attr_spi_bus_div_ref;
        fapi2::ATTR_FREQ_CORE_BOOT_MHZ_Type l_attr_freq_core_boot_mhz;

        FAPI_DBG("Reading ATTR_SPI_BUS_DIV_REF, ATTR_FREQ_CORE_BOOT_MHZ");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SPI_BUS_DIV_REF, i_target_chip, l_attr_spi_bus_div_ref),
                 "Error from FAPI_ATTR_GET (ATTR_SPI_BUS_DIV_REF");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_CORE_BOOT_MHZ, i_target_chip, l_attr_freq_core_boot_mhz),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_CORE_BOOT_MHZ");

        l_scratch4_reg.insertFromRight<ATTR_SPI_BUS_DIV_REF_STARTBIT, ATTR_SPI_BUS_DIV_REF_LENGTH>(l_attr_spi_bus_div_ref);
        l_scratch4_reg.insertFromRight<ATTR_FREQ_CORE_BOOT_MHZ_STARTBIT, ATTR_FREQ_CORE_BOOT_MHZ_LENGTH>
        (l_attr_freq_core_boot_mhz);

        FAPI_DBG("Setting up value of Scratch 4 mailbox register");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_4_FSI,
                                        l_scratch4_reg),
                 "Error writing Scratch 4 mailbox register");

        l_scratch8_reg.setBit<SCRATCH4_REG_VALID_BIT>();
    }

    // set_scratch5_reg -- HWP control flags/PLL muxes
    {
        fapi2::buffer<uint32_t> l_scratch5_reg = 0;
        fapi2::ATTR_SYSTEM_IPL_PHASE_Type l_attr_system_ipl_phase;
        fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;
        fapi2::ATTR_RUNN_MODE_Type l_attr_runn_mode;
        fapi2::ATTR_DISABLE_HBBL_VECTORS_Type l_attr_disable_hbbl_vectors;
        fapi2::ATTR_SBE_SELECT_EX_POLICY_Type l_attr_sbe_select_ex_policy;
        fapi2::ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_Type l_attr_clock_mux_iohs_lcpll_input;
        fapi2::ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_Type l_attr_clock_mux_pci_lcpll_input;

        FAPI_DBG("Reading ATTR_SYSTEM_IPL_PHASE, ATTR_CONTAINED_IPL_TYPE");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_IPL_PHASE, FAPI_SYSTEM, l_attr_system_ipl_phase),
                 "Error from FAPI_ATTR_GET (ATTR_SYSTEM_IPL_PHASE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE, FAPI_SYSTEM, l_attr_contained_ipl_type),
                 "Error from FAPI_ATTR_GET (ATTR_CONTAINED_IPL_TYPE)");

        if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CACHE)
        {
            l_scratch5_reg.insertFromRight<IPL_TYPE_STARTBIT, IPL_TYPE_LENGTH>(IPL_TYPE_CACHE_CONTAINED);
        }
        else if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CHIP)
        {
            l_scratch5_reg.insertFromRight<IPL_TYPE_STARTBIT, IPL_TYPE_LENGTH>(IPL_TYPE_CHIP_CONTAINED);
        }
        else
        {
            l_scratch5_reg.insertFromRight<IPL_TYPE_STARTBIT, IPL_TYPE_LENGTH>(IPL_TYPE_HOSTBOOT);
        }

        FAPI_DBG("Reading ATTR_RUNN_MODE");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_RUNN_MODE, FAPI_SYSTEM, l_attr_runn_mode),
                 "Error from FAPI_ATTR_GET (ATTR_RUNN_MODE)");

        if (l_attr_runn_mode == fapi2::ENUM_ATTR_RUNN_MODE_ON)
        {
            l_scratch5_reg.setBit<ATTR_RUNN_MODE_BIT>();
        }
        else
        {
            l_scratch5_reg.clearBit<ATTR_RUNN_MODE_BIT>();
        }

        FAPI_DBG("Reading ATTR_DISABLE_HBBL_VECTORS");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DISABLE_HBBL_VECTORS, FAPI_SYSTEM, l_attr_disable_hbbl_vectors),
                 "Error from FAPI_ATTR_GET (ATTR_DISABLE_HBBL_VECTORS)");

        if (l_attr_disable_hbbl_vectors == fapi2::ENUM_ATTR_DISABLE_HBBL_VECTORS_TRUE)
        {
            l_scratch5_reg.setBit<ATTR_DISABLE_HBBL_VECTORS_BIT>();
        }
        else
        {
            l_scratch5_reg.clearBit<ATTR_DISABLE_HBBL_VECTORS_BIT>();
        }

        FAPI_DBG("Reading ATTR_SBE_SELECT_EX_POLICY");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SBE_SELECT_EX_POLICY, FAPI_SYSTEM, l_attr_sbe_select_ex_policy),
                 "Error from FAPI_ATTR_GET (ATTR_SBE_SELECT_EX_POLICY)");
        l_scratch5_reg.insertFromRight<ATTR_SBE_SELECT_EX_POLICY_STARTBIT, ATTR_SBE_SELECT_EX_POLICY_LENGTH>
        (l_attr_sbe_select_ex_policy);

        FAPI_DBG("Reading IOHS PLL mux attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT, i_target_chip, l_attr_clock_mux_iohs_lcpll_input),
                 "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT)");

        for (const auto& l_iohs_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_attr_chip_unit_pos;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_attr_chip_unit_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(l_scratch5_reg.insertFromRight(l_attr_clock_mux_iohs_lcpll_input[l_attr_chip_unit_pos],
                                                    ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_STARTBIT +
                                                    (ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_LENGTH * l_attr_chip_unit_pos),
                                                    ATTR_CLOCK_MUX_IOHS_LCPLL_INPUT_LENGTH));
        }

        FAPI_DBG("Reading PCI PLL mux attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CLOCK_MUX_PCI_LCPLL_INPUT, i_target_chip, l_attr_clock_mux_pci_lcpll_input),
                 "Error from FAPI_ATTR_GET (ATTR_CLOCK_MUX_PCI_LCPLL_INPUT)");

        for (const auto& l_pci_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_attr_chip_unit_pos;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pci_target, l_attr_chip_unit_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(l_scratch5_reg.insertFromRight(l_attr_clock_mux_pci_lcpll_input[l_attr_chip_unit_pos],
                                                    ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_STARTBIT +
                                                    (ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_LENGTH * l_attr_chip_unit_pos),
                                                    ATTR_CLOCK_MUX_PCI_LCPLL_INPUT_LENGTH));
        }

        FAPI_DBG("Setting up value of Scratch_reg5");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_5_FSI,
                                        l_scratch5_reg),
                 "Error writing Scratch 5 mailbox register");

        l_scratch8_reg.setBit<SCRATCH5_REG_VALID_BIT>();
    }

    // set_scratch6_reg -- Master/slave, node/chip selection, PLL bypass controls
    {
        fapi2::buffer<uint32_t> l_scratch6_reg = 0;
        fapi2::ATTR_SKEWADJ_BYPASS_Type l_attr_skewadj_bypass;
        fapi2::ATTR_DCADJ_BYPASS_Type l_attr_dcadj_bypass;
        fapi2::ATTR_CP_PLLTODFLT_BYPASS_Type l_attr_cp_plltodflt_bypass;
        fapi2::ATTR_CP_PLLNESTFLT_BYPASS_Type l_attr_cp_pllnestflt_bypass;
        fapi2::ATTR_CP_PLLIOFLT_BYPASS_Type l_attr_cp_pllioflt_bypass;
        fapi2::ATTR_CP_PLLIOSSFLT_BYPASS_Type l_attr_cp_plliossflt_bypass;
        fapi2::ATTR_NEST_DPLL_BYPASS_Type l_attr_nest_dpll_bypass;
        fapi2::ATTR_PAU_DPLL_BYPASS_Type l_attr_pau_dpll_bypass;
        fapi2::ATTR_BOOT_PAU_DPLL_BYPASS_Type l_attr_boot_pau_dpll_bypass;
        fapi2::ATTR_IO_TANK_PLL_BYPASS_Type l_attr_io_tank_pll_bypass;
        fapi2::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_Type l_attr_proc_fabric_eff_topology_id;
        fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE_Type l_attr_proc_fabric_topology_mode;
        fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE_Type l_attr_proc_fabric_broadcast_mode;
        fapi2::ATTR_PROC_SBE_MASTER_CHIP_Type l_attr_proc_sbe_master_chip;
        fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID_Type l_attr_proc_fabric_topology_id;

        FAPI_DBG("Reading skew adjust/duty cycle adjust bypass attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SKEWADJ_BYPASS, i_target_chip, l_attr_skewadj_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_SKEWADJ_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_SKEWADJ_BYPASS_BIT>(l_attr_skewadj_bypass ==
                fapi2::ENUM_ATTR_SKEWADJ_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_DCADJ_BYPASS, i_target_chip, l_attr_dcadj_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_DCADJ_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_DCADJ_BYPASS_BIT>(l_attr_dcadj_bypass ==
                fapi2::ENUM_ATTR_DCADJ_BYPASS_BYPASS);

        FAPI_DBG("Reading filter PLL bypass attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_PLLTODFLT_BYPASS, i_target_chip, l_attr_cp_plltodflt_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_CP_PLLTODFLT_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_CP_PLLTODFLT_BYPASS_BIT>(l_attr_cp_plltodflt_bypass ==
                fapi2::ENUM_ATTR_CP_PLLTODFLT_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_PLLNESTFLT_BYPASS, i_target_chip, l_attr_cp_pllnestflt_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_CP_PLLNESTFLT_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_CP_PLLNESTFLT_BYPASS_BIT>(l_attr_cp_pllnestflt_bypass ==
                fapi2::ENUM_ATTR_CP_PLLNESTFLT_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_PLLIOFLT_BYPASS, i_target_chip, l_attr_cp_pllioflt_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_CP_PLLIOFLT_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_CP_PLLIOFLT_BYPASS_BIT>(l_attr_cp_pllioflt_bypass ==
                fapi2::ENUM_ATTR_CP_PLLIOFLT_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CP_PLLIOSSFLT_BYPASS, i_target_chip, l_attr_cp_plliossflt_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_CP_PLLIOSSFLT_BYPASS)");
        l_scratch6_reg.writeBit<ATTR_CP_PLLIOSSFLT_BYPASS_BIT>(l_attr_cp_plliossflt_bypass ==
                fapi2::ENUM_ATTR_CP_PLLIOSSFLT_BYPASS_BYPASS);

        FAPI_DBG("Reading DPLL bypass attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NEST_DPLL_BYPASS, i_target_chip, l_attr_nest_dpll_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_NEST_DPLL_BYPASS");
        l_scratch6_reg.writeBit<ATTR_NEST_DPLL_BYPASS_BIT>(l_attr_nest_dpll_bypass == fapi2::ENUM_ATTR_NEST_DPLL_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PAU_DPLL_BYPASS, i_target_chip, l_attr_pau_dpll_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_PAU_DPLL_BYPASS");
        l_scratch6_reg.writeBit<ATTR_PAU_DPLL_BYPASS_BIT>(l_attr_pau_dpll_bypass == fapi2::ENUM_ATTR_PAU_DPLL_BYPASS_BYPASS);

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_BOOT_PAU_DPLL_BYPASS, i_target_chip, l_attr_boot_pau_dpll_bypass),
                 "Error from FAPI_ATTR_GET (ATTR_BOOT_PAU_DPLL_BYPASS");
        l_scratch6_reg.writeBit<ATTR_BOOT_PAU_DPLL_BYPASS_BIT>(l_attr_boot_pau_dpll_bypass ==
                fapi2::ENUM_ATTR_BOOT_PAU_DPLL_BYPASS_BYPASS);

        FAPI_DBG("Reading tank PLL bypass attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IO_TANK_PLL_BYPASS, i_target_chip, l_attr_io_tank_pll_bypass));
        l_scratch6_reg.writeBit<ATTR_IO_TANK_PLL_BYPASS_BIT>(l_attr_io_tank_pll_bypass ==
                fapi2::ENUM_ATTR_IO_TANK_PLL_BYPASS_BYPASS);

        FAPI_DBG("Reading master SBE attribute");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP, i_target_chip, l_attr_proc_sbe_master_chip),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");
        l_scratch6_reg.writeBit<ATTR_PROC_SBE_MASTER_CHIP_BIT>(l_attr_proc_sbe_master_chip ==
                fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_TRUE);

        FAPI_DBG("Reading fabric topology/broadcast attributes");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID, i_target_chip, l_attr_proc_fabric_eff_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID)");
        l_scratch6_reg.insertFromRight<ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_STARTBIT, ATTR_PROC_FABRIC_EFF_TOPOLOGY_ID_LENGTH>
        (l_attr_proc_fabric_eff_topology_id);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_MODE, FAPI_SYSTEM, l_attr_proc_fabric_topology_mode),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_MODE");

        if (l_attr_proc_fabric_topology_mode == fapi2::ENUM_ATTR_PROC_FABRIC_TOPOLOGY_MODE_MODE1)
        {
            l_scratch6_reg.setBit<ATTR_PROC_FABRIC_TOPOLOGY_MODE_BIT>();
        }
        else
        {
            l_scratch6_reg.clearBit<ATTR_PROC_FABRIC_TOPOLOGY_MODE_BIT>();
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_BROADCAST_MODE, FAPI_SYSTEM, l_attr_proc_fabric_broadcast_mode),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_BROADCAST_MODE");
        l_scratch6_reg.insertFromRight<ATTR_PROC_FABRIC_BROADCAST_MODE_STARTBIT, ATTR_PROC_FABRIC_BROADCAST_MODE_LENGTH>
        (l_attr_proc_fabric_broadcast_mode);
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_TOPOLOGY_ID, i_target_chip, l_attr_proc_fabric_topology_id),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_TOPOLOGY_ID");
        l_scratch6_reg.insertFromRight< ATTR_PROC_FABRIC_TOPOLOGY_ID_STARTBIT, ATTR_PROC_FABRIC_TOPOLOGY_ID_LENGTH>
        (l_attr_proc_fabric_topology_id);

        FAPI_DBG("Setting up value of Scratch_reg6");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_6_FSI,
                                        l_scratch6_reg),
                 "Error writing Scratch 6 mailbox register");

        l_scratch8_reg.setBit<SCRATCH6_REG_VALID_BIT>();
    }

    // set_scratch7_reg - IOHS region gard / chip contained active cores vector
    {
        fapi2::buffer<uint32_t> l_scratch7_reg = 0;
        fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE, FAPI_SYSTEM, l_attr_contained_ipl_type),
                 "Error from FAPI_ATTR_GET (ATTR_CONTAINED_IPL_TYPE)");

        if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE)
        {
            uint32_t l_ndl_gard_vector;

            FAPI_DBG("Setting up IOHS NDL gard records");
            FAPI_TRY(p10_sbe_scratch_calc_iohs_region_gard_vectors(i_target_chip,
                     l_ndl_gard_vector),
                     "Error from p10_sbe_scratch_calc_iohs_region_gard_vectors");
            l_scratch7_reg.insert<NDL_GARD_STARTBIT, NDL_GARD_LENGTH, GARD_VECTOR_STARTBIT>(l_ndl_gard_vector);
        }
        else if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CHIP)
        {
            fapi2::ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC_Type l_attr_chip_contained_active_cores_vec;

            FAPI_DBG("Setting up chip contained active cores vector");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC, i_target_chip,
                                   l_attr_chip_contained_active_cores_vec),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC)");
            l_scratch7_reg.insertFromRight<ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC_STARTBIT, ATTR_CHIP_CONTAINED_ACTIVE_CORES_VEC_LENGTH>
            (l_attr_chip_contained_active_cores_vec);
        }

        FAPI_DBG("Setting up value of Scratch_reg7");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_7_FSI,
                                        l_scratch7_reg),
                 "Error writing Scratch 7 mailbox register");

        l_scratch8_reg.setBit<SCRATCH7_REG_VALID_BIT>();
    }

    // set_scratch9_reg - PAU/MC frequency
    {
        fapi2::buffer<uint32_t> l_scratch9_reg = 0;
        fapi2::ATTR_FREQ_PAU_MHZ_Type l_attr_freq_pau_mhz;
        fapi2::ATTR_MC_PLL_BUCKET_Type l_attr_mc_pll_bucket = { 0 };
        fapi2::ATTR_NDL_MESHCTRL_SETUP_Type l_attr_ndl_meshctrl_setup;

        FAPI_DBG("Reading ATTR_FREQ_PAU_MHZ");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ, FAPI_SYSTEM, l_attr_freq_pau_mhz),
                 "Error from FAPI_ATTR_GET (ATTR_FREQ_PAU_MHZ");
        l_scratch9_reg.insertFromRight<ATTR_FREQ_PAU_MHZ_STARTBIT, ATTR_FREQ_PAU_MHZ_LENGTH>(l_attr_freq_pau_mhz);


        // calculate bucket index based on desired frequency
        FAPI_DBG("Setting up MC PLL bucket values");
        FAPI_TRY(p10_sbe_scratch_regs_get_mc_pll_bucket(i_target_chip, l_attr_mc_pll_bucket),
                 "Error from p10_sbe_scratch_regs_get_mc_pll_bucket");
        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_MC_PLL_BUCKET, i_target_chip, l_attr_mc_pll_bucket),
                 "Error from FAPI_ATTR_SET (ATTR_MC_PLL_BUCKET)");

        for (const auto& l_mc_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_MC>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_attr_chip_unit_pos;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_attr_chip_unit_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_TRY(l_scratch9_reg.insertFromRight(l_attr_mc_pll_bucket[l_attr_chip_unit_pos],
                                                    ATTR_MC_PLL_BUCKET_STARTBIT +
                                                    (ATTR_MC_PLL_BUCKET_LENGTH * l_attr_chip_unit_pos),
                                                    ATTR_MC_PLL_BUCKET_LENGTH));
        }

        FAPI_DBG("Reading ATTR_NDL_MESHCTRL_SETUP");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_NDL_MESHCTRL_SETUP, i_target_chip, l_attr_ndl_meshctrl_setup),
                 "Error from FAPI_ATTR_GET (ATTR_NDL_MESHCTRL_SETUP)");
        l_scratch9_reg.insertFromRight<ATTR_NDL_MESHCTRL_SETUP_STARTBIT, ATTR_NDL_MESHCTRL_SETUP_LENGTH>
        (l_attr_ndl_meshctrl_setup);

        FAPI_DBG("Setting up value of Scratch_reg9");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_FSI,
                                        l_scratch9_reg),
                 "Error writing Scratch 9 mailbox register");

        l_scratch8_reg.setBit<SCRATCH9_REG_VALID_BIT>();
    }

    // set_scratch10_reg - IOHS frequency / chip contained backing caches vector
    {
        fapi2::buffer<uint32_t> l_scratch10_reg = 0;
        fapi2::ATTR_CONTAINED_IPL_TYPE_Type l_attr_contained_ipl_type;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CONTAINED_IPL_TYPE, FAPI_SYSTEM, l_attr_contained_ipl_type),
                 "Error from FAPI_ATTR_GET (ATTR_CONTAINED_IPL_TYPE)");

        if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_NONE)
        {
            fapi2::ATTR_IOHS_PLL_BUCKET_Type l_attr_iohs_pll_bucket = { 0 };

            // calculate bucket index based on desired frequency
            FAPI_DBG("Setting up IOHS PLL bucket values");
            FAPI_TRY(p10_sbe_scratch_regs_get_iohs_pll_bucket(i_target_chip, l_attr_iohs_pll_bucket),
                     "Error from p10_sbe_scratch_regs_get_iohs_pll_bucket");
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_IOHS_PLL_BUCKET, i_target_chip, l_attr_iohs_pll_bucket),
                     "Error from FAPI_ATTR_SET (ATTR_IOHS_PLL_BUCKET)");

            for (const auto& l_iohs_target : i_target_chip.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL))
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type l_attr_chip_unit_pos;

                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_iohs_target, l_attr_chip_unit_pos),
                         "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

                FAPI_TRY(l_scratch10_reg.insertFromRight(l_attr_iohs_pll_bucket[l_attr_chip_unit_pos],
                         ATTR_IOHS_PLL_BUCKET_STARTBIT +
                         (ATTR_IOHS_PLL_BUCKET_LENGTH * l_attr_chip_unit_pos),
                         ATTR_IOHS_PLL_BUCKET_LENGTH));
            }
        }
        else if (l_attr_contained_ipl_type == fapi2::ENUM_ATTR_CONTAINED_IPL_TYPE_CHIP)
        {
            fapi2::ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC_Type l_attr_chip_contained_backing_caches_vec;

            FAPI_DBG("Setting up chip contained backing caches vector");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC, i_target_chip,
                                   l_attr_chip_contained_backing_caches_vec),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC)");
            l_scratch10_reg.insertFromRight<ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC_STARTBIT, ATTR_CHIP_CONTAINED_BACKING_CACHES_VEC_LENGTH>
            (l_attr_chip_contained_backing_caches_vec);
        }

        FAPI_DBG("Setting up value of Scratch_reg10");
        FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                        FSXCOMP_FSXLOG_SCRATCH_REGISTER_10_FSI,
                                        l_scratch10_reg),
                 "Error writing Scratch 10 mailbox register");

        l_scratch8_reg.setBit<SCRATCH10_REG_VALID_BIT>();
    }

    FAPI_DBG("Setting up value of Scratch_reg8 (valid)");
    FAPI_TRY(fapi2::putCfamRegister(i_target_chip,
                                    FSXCOMP_FSXLOG_SCRATCH_REGISTER_8_FSI,
                                    l_scratch8_reg),
             "Error writing Scratch 8 mailbox register");

    FAPI_INF("p10_setup_sbe_config: Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
