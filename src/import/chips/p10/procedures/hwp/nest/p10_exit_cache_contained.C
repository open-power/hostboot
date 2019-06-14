/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_exit_cache_contained.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file p10_exit_cache_contained.C
/// @brief Trigger SBE assist to exit HB cache containment

//
// *HWP HW Maintainer: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_exit_cache_contained.H>
#include <fapi2_subroutine_executor.H>

#include <p10_scominfo.H>
#include <p10_scom_mc.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// MI chip unit relative addresses (associated with ATTR_MEMORY_BAR_REGS
static const uint64_t MC_BAR_REG_SCOM_ADDRS[] =
{
    scomt::mc::SCOMFIR_MCFGP0,
    scomt::mc::SCOMFIR_MCFGP1,
    scomt::mc::SCOMFIR_MCFGPM0,
    scomt::mc::SCOMFIR_MCFGPM1,
    scomt::mc::SCOMFIR_MCFGP0A,
    scomt::mc::SCOMFIR_MCFGP1A,
    scomt::mc::SCOMFIR_MCFGPM0A,
    scomt::mc::SCOMFIR_MCFGPM1A,
    scomt::mc::SCOMFIR_MCMODE0,
};

static const uint8_t ATTR_MEMORY_BAR_REGS_DATA_IDX = 0;
static const uint8_t ATTR_MEMORY_BAR_REGS_MASK_IDX = 1;

// address formation constants
static const uint64_t SCOM_TO_XSCOM_ADDR_MASK  = 0x000000007FFFFFFFULL;
static const uint64_t SCOM_TO_XSCOM_ADDR_SHIFT = 3;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


///
/// @brief Generate XSCOM init for specified SCOM address given data and
///        data valid mask.  Data bit positions with zero in corresponding
///        data valid mask bit positions will be sampled from HW via SCOM.
///
/// @param[in]  i_target            Reference to processor chip target
/// @param[in]  i_cu_pairing        Chip unit and instance number associated
///                                 with i_scom_addr
/// @param[in]  i_scom_addr         Requested SCOM address, relative to
///                                 chip unit type in i_cu_pairing
/// @param[in]  i_data              Data to write
/// @param[in]  i_data_valid_mask   Data valid bitmask
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode
p10_exit_cache_contained_serialize_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_chipUnitPairing_t i_cu_pairing,
    const uint64_t i_scom_addr,
    const uint64_t i_data,
    const uint64_t i_data_valid_mask,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    FAPI_DBG("Start");
    FAPI_DBG("Input PIB: 0x%08X, DATA: 0x%016llX, MASK: 0x%016llX",
             i_scom_addr, i_data, i_data_valid_mask);

    uint64_t l_scom_addr = i_scom_addr;
    uint64_t l_data = i_data;
    uint64_t l_xscom_addr = 0;
    fapi2::buffer<uint64_t> l_data_read = 0;

    // skip updating xscom init list if no bits are on in data valid mask
    if (i_data_valid_mask)
    {
        fapi2::ATTR_PROC_XSCOM_BAR_BASE_ADDR_OFFSET_Type l_xscom_bar_base_addr_offset;
        fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        uint64_t l_base_address_nm0_unused;
        uint64_t l_base_address_nm1_unused;
        uint64_t l_base_address_m_unused;
        uint64_t l_base_address_mmio;

        // indirect/multicast SCOM addresses are unsupported
        FAPI_ASSERT((i_scom_addr & ~SCOM_TO_XSCOM_ADDR_MASK) == 0ULL,
                    fapi2::P10_EXIT_CACHE_CONTAINED_UNSUPPORTED_SCOM_ERR()
                    .set_TARGET(i_target)
                    .set_ADDR(i_scom_addr),
                    "Unsupported indirect/multicast SCOM address");

        // if input is chip unit relative, form fully qualified SCOM address
        // based on type and instance
        if (i_cu_pairing.chipUnitType != P10_NO_CU)
        {
            fapi2::ATTR_EC_Type l_ec;
            FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC,
                                              i_target,
                                              l_ec),
                     "Error from FAPI_ATTR_GET_PRIVILEGED (ATTR_EC)");

            l_scom_addr = p10_scominfo_createChipUnitScomAddr(
                              i_cu_pairing.chipUnitType,
                              l_ec,
                              i_cu_pairing.chipUnitNum,
                              l_scom_addr);

            FAPI_ASSERT(l_scom_addr != p10TranslationResult_t::FAILED_TRANSLATION,
                        fapi2::P10_EXIT_CACHE_CONTAINED_SCOM_XLATE_ERR()
                        .set_TARGET(i_target)
                        .set_CU_TYPE(i_cu_pairing.chipUnitType)
                        .set_EC(l_ec)
                        .set_CU_NUM(i_cu_pairing.chipUnitNum)
                        .set_ADDR(i_scom_addr),
                        "SCOM address translation failed!");
        }

        // skip read if all bits are intended to come from attribute
        // otherwise read SCOM register to obtain bits to preserve
        if (~i_data_valid_mask)
        {
            FAPI_TRY(fapi2::getScom(i_target,
                                    l_scom_addr,
                                    l_data_read),
                     "Error from getScom (addr: 0x%08X)",
                     l_scom_addr);
        }

        // determine XSCOM base address associated with this chip
        FAPI_TRY(p10_fbc_utils_get_chip_base_address(i_target,
                 EFF_TOPOLOGY_ID,
                 l_base_address_nm0_unused,
                 l_base_address_nm1_unused,
                 l_base_address_m_unused,
                 l_base_address_mmio),
                 "Error from p10_fbc_utils_get_chip_base_address");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_XSCOM_BAR_BASE_ADDR_OFFSET,
                               FAPI_SYSTEM,
                               l_xscom_bar_base_addr_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_XSCOM_BAR_BASE_ADDR_OFFSET)");

        l_xscom_addr = l_base_address_mmio +
                       l_xscom_bar_base_addr_offset;

        // merge SCOM/PIB address into position for XSCOM address
        // PIB address 1:31 -> XSCOM address 30:60
        l_xscom_addr |= ((l_scom_addr & SCOM_TO_XSCOM_ADDR_MASK) << SCOM_TO_XSCOM_ADDR_SHIFT);

        // merge data
        l_data = ( i_data_valid_mask & i_data) |
                 (~i_data_valid_mask & l_data_read());

        // add new init
        FAPI_DBG("Adding XSCOM - PIB: 0x%08X, XSCOM: 0x%016llX, DATA: 0x%016llX",
                 l_scom_addr, l_xscom_addr, l_data);
        o_xscom_inits.push_back(std::make_pair(l_xscom_addr, l_data));
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Process MCD BAR attributes to calculate required XSCOM inits
///
/// @param[in]  i_targets           Collection of processor chip targets in drawer
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///

fapi2::ReturnCode
p10_exit_cache_contained_append_mcd_bar_inits(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    std::vector<std::pair<uint64_t, uint64_t>> o_xscom_inits)
{

    // TODO: RTC 202071 (implement under p10_setup_bars delivery)

    FAPI_DBG("Start");
    FAPI_DBG("End");
    return fapi2::FAPI2_RC_SUCCESS;
}


///
/// @brief Process MC BAR attribute to calculate required XSCOM inits
///
/// @param[in]  i_targets           Collection of processor chip targets in drawer
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///

fapi2::ReturnCode
p10_exit_cache_contained_append_mc_bar_inits(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    FAPI_DBG("Start");

    for (const auto& l_target : i_targets)
    {
        fapi2::ATTR_MEMORY_BAR_REGS_Type l_memory_bar_regs;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEMORY_BAR_REGS,
                               l_target,
                               l_memory_bar_regs),
                 "Error from FAPI_ATTR_GET (ATTR_MEMORY_BAR_REGS)");

        for (const auto& l_mi_target : l_target.getChildren<fapi2::TARGET_TYPE_MI>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_num;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mi_target, l_unit_num),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

            FAPI_DBG("Processing MI: %d", l_unit_num);

            for (auto l_reg_idx = 0u; l_reg_idx < fapi2::ENUM_ATTR_MEMORY_BAR_REGS_NUM_BAR_REGS; l_reg_idx++)
            {
                FAPI_TRY(p10_exit_cache_contained_serialize_init(
                             l_target,
                             p10_chipUnitPairing_t(PU_MI_CHIPUNIT, l_unit_num),
                             MC_BAR_REG_SCOM_ADDRS[l_reg_idx],
                             l_memory_bar_regs[l_unit_num][l_reg_idx][ATTR_MEMORY_BAR_REGS_DATA_IDX],
                             l_memory_bar_regs[l_unit_num][l_reg_idx][ATTR_MEMORY_BAR_REGS_MASK_IDX],
                             o_xscom_inits),
                         "Error from p10_exit_cache_contained_serialize_init");
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode
p10_exit_cache_contained(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    const p10_sbe_exit_cache_contained_step_t& i_step)
{
    FAPI_DBG("Start");

    fapi2::ReturnCode l_rc;
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_sbe_master_chip_target;
    fapi2::ATTR_IS_MPIPL_Type l_is_mpipl;
    std::vector<std::pair<uint64_t, uint64_t>> l_xscom_inits;
    bool l_sbe_master_chip_found = false;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL,
                           FAPI_SYSTEM,
                           l_is_mpipl),
             "Error from FAPI_ATTR_GET (ATTR_IS_MPIPL)");

    if ((i_step == p10_sbe_exit_cache_contained_step_t::SKIP_ALL) ||
        (l_is_mpipl == fapi2::ENUM_ATTR_IS_MPIPL_TRUE))
    {
        FAPI_DBG("Skipping cache contained exit sequence (step: 0x%02X, mpipl: %d)",
                 static_cast<uint8_t>(i_step), (l_is_mpipl) ? (1) : (0));
        goto fapi_try_exit;
    }

    // find chip associated with master SBE
    for (const auto& l_target : i_targets)
    {
        fapi2::ATTR_PROC_SBE_MASTER_CHIP_Type l_sbe_master_chip_flag =
            fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_FALSE;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_SBE_MASTER_CHIP,
                               l_target,
                               l_sbe_master_chip_flag),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_SBE_MASTER_CHIP)");

        FAPI_ASSERT(!(l_sbe_master_chip_found &&
                      (l_sbe_master_chip_flag == fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_TRUE)),
                    fapi2::P10_EXIT_CACHE_CONTAINED_MULTIPLE_MASTER_ERR()
                    .set_MASTER_CHIP1(l_sbe_master_chip_target)
                    .set_MASTER_CHIP2(l_target),
                    "More than one chip found with ATTR_PROC_SBE_MASTER_CHIP set");

        if (l_sbe_master_chip_flag == fapi2::ENUM_ATTR_PROC_SBE_MASTER_CHIP_TRUE)
        {
            l_sbe_master_chip_target = l_target;
            l_sbe_master_chip_found = true;
        }
    }

    FAPI_ASSERT(l_sbe_master_chip_found,
                fapi2::P10_EXIT_CACHE_CONTAINED_NO_MASTER_ERR(),
                "No chip found with ATTR_PROC_SBE_MASTER_CHIP set");

    if ((i_step & p10_sbe_exit_cache_contained_step_t::SETUP_MEMORY_BARS) ==
        p10_sbe_exit_cache_contained_step_t::SETUP_MEMORY_BARS)
    {
        FAPI_TRY(p10_exit_cache_contained_append_mc_bar_inits(i_targets,
                 l_xscom_inits),
                 "Error from p10_exit_cache_contained_append_mc_bar_inits");

        FAPI_TRY(p10_exit_cache_contained_append_mcd_bar_inits(i_targets,
                 l_xscom_inits),
                 "Error from p10_exit_cache_contained_append_mcd_bar_inits");
    }

    // issue sequence of requested operations on chip hosting master SBE
    FAPI_CALL_SUBROUTINE(l_rc,
                         p10_sbe_exit_cache_contained,
                         l_sbe_master_chip_target,
                         l_xscom_inits,
                         i_step);

    fapi2::current_err = l_rc;
    FAPI_TRY(fapi2::current_err,
             "Error from p10_sbe_exit_cache_contained");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
