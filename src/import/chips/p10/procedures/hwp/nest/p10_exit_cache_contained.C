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
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_exit_cache_contained.H>
#include <p10_gen_xscom_init.H>
#include <p10_setup_bars_defs.H>
#include <p10_mss_eff_grouping.H>
#include <fapi2_subroutine_executor.H>
#include <p10_scom_mc.H>
#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//
// MCD setup constants
//

// Recovery controls
const uint32_t MCD_RECOVERY_PACE_RATE = 0x32;
const uint32_t MCD_RECOVERY_RTY_COUNT = 0xF;
const uint32_t MCD_RECOVERY_VG_COUNT = 0x7FFF;

const uint32_t MCD_VGC_AVAIL_GROUPS = 0xFFFF;

// FIR
const uint8_t MCD_ENABLED_NUM_FIR_INITS = 4;

static const uint64_t MCD_ENABLED_FIR_REG_SCOM_ADDRS[] =
{
    scomt::proc::MCD_MCC_FIR_REG_RW,
    scomt::proc::MCD_FIR_MASK_REG_RW,
    scomt::proc::MCD_FIR_ACTION0_REG,
    scomt::proc::MCD_FIR_ACTION1_REG
};

static const uint64_t MCD_ENABLED_FIR_REG_SCOM_DATA_VALS[] =
{
    0x0000000000000000ULL,
    0x4C60000000000000ULL,
    0x0000000000000000ULL,
    0x8000000000000000ULL
};

// range configuration registers
enum mcd_range_reg_t
{
    TOP,
    STR,
    BOT,
    CHA,
};

static const uint64_t MCD_RANGE_REG_SCOM_ADDRS[] =
{
    scomt::proc::MCD_BANK0_TOP,
    scomt::proc::MCD_BANK0_STR,
    scomt::proc::MCD_BANK0_BOT,
    scomt::proc::MCD_BANK0_CHA
};

// define set of valid MCD group sizes/encodings
// MCD group configuration register base address field (33:63) covers RA 8:38
const uint64_t MCD_BASE_ADDR_SHIFT = 25;

// MCD group configuration register size field (11:29) masks RA 20:38
// (max 16 TB / min 32 MB)
struct p10_mcd_grp_size
{
    static std::map<uint64_t, uint64_t> create_map()
    {
        std::map<uint64_t, uint64_t> m;
        m[P10_SETUP_BARS_SIZE_32_MB]  = 0x00000;
        m[P10_SETUP_BARS_SIZE_64_MB]  = 0x00001;
        m[P10_SETUP_BARS_SIZE_128_MB] = 0x00003;
        m[P10_SETUP_BARS_SIZE_256_MB] = 0x00007;
        m[P10_SETUP_BARS_SIZE_512_MB] = 0x0000F;
        m[P10_SETUP_BARS_SIZE_1_GB]   = 0x0001F;
        m[P10_SETUP_BARS_SIZE_2_GB]   = 0x0003F;
        m[P10_SETUP_BARS_SIZE_4_GB]   = 0x0007F;
        m[P10_SETUP_BARS_SIZE_8_GB]   = 0x000FF;
        m[P10_SETUP_BARS_SIZE_16_GB]  = 0x001FF;
        m[P10_SETUP_BARS_SIZE_32_GB]  = 0x003FF;
        m[P10_SETUP_BARS_SIZE_64_GB]  = 0x007FF;
        m[P10_SETUP_BARS_SIZE_128_GB] = 0x00FFF;
        m[P10_SETUP_BARS_SIZE_256_GB] = 0x01FFF;
        m[P10_SETUP_BARS_SIZE_512_GB] = 0x03FFF;
        m[P10_SETUP_BARS_SIZE_1_TB]   = 0x07FFF;
        m[P10_SETUP_BARS_SIZE_2_TB]   = 0x0FFFF;
        m[P10_SETUP_BARS_SIZE_4_TB]   = 0x1FFFF;
        m[P10_SETUP_BARS_SIZE_8_TB]   = 0x3FFFF;
        m[P10_SETUP_BARS_SIZE_16_TB]  = 0x7FFFF;
        return m;
    }
    static const std::map<uint64_t, uint64_t> xlate_map;
};

const std::map<uint64_t, uint64_t> p10_mcd_grp_size::xlate_map =
    p10_mcd_grp_size::create_map();

//
// MC BAR constants
//

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


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// @brief Program MCD range register to track region of real address space
///
/// @param[in] i_target             Processor chip target
/// @param[in] i_addr_range         Address space to cover
/// @param[in] i_mcd_range_reg      Enum identifying MCD range register resource to
///                                 service mapping
/// @param[in] o_xscom_inits        Vector (address/data pairs) to append
///                                 required XSCOM inits
fapi2::ReturnCode
p10_exit_cache_contained_add_mcd_tracked_range(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p10_setup_bars_addr_range& i_addr_range,
    const mcd_range_reg_t i_mcd_range_reg,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    if (i_addr_range.enabled)
    {
        fapi2::buffer<uint64_t> l_mcd_cfg_reg = 0;
        fapi2::buffer<uint64_t> l_mcd_cfg_reg_valid_mask;
        l_mcd_cfg_reg_valid_mask.flush<1>();
        std::map<uint64_t, uint64_t>::const_iterator l_iter = p10_mcd_grp_size::xlate_map.find(i_addr_range.size);
        FAPI_ASSERT(l_iter != p10_mcd_grp_size::xlate_map.end(),
                    fapi2::P10_EXIT_CACHE_CONTAINED_INVALID_MCD_GROUP_SIZE_ERR().
                    set_TARGET(i_target).
                    set_RANGE_BASE_ADDR(i_addr_range.base_addr).
                    set_RANGE_SIZE(i_addr_range.size).
                    set_MCD_RANGE_REG(i_mcd_range_reg),
                    "Invalid MCD group size!");

        // form register content
        FAPI_TRY(PREP_MCD_BANK0_TOP(i_target));
        SET_MCD_BANK0_TOP_VALID(l_mcd_cfg_reg);
        SET_MCD_BANK0_TOP_SMF_ENABLE(l_mcd_cfg_reg);
        SET_MCD_BANK0_TOP_GRP_SIZE(l_iter->second, l_mcd_cfg_reg);
        SET_MCD_BANK0_TOP_GRP_BASE(i_addr_range.base_addr >>  MCD_BASE_ADDR_SHIFT, l_mcd_cfg_reg);

        // append init
        FAPI_TRY(p10_gen_xscom_init(i_target,
                                    p10_chipUnitPairing_t(P10_NO_CU, 0),
                                    MCD_RANGE_REG_SCOM_ADDRS[i_mcd_range_reg],
                                    l_mcd_cfg_reg,
                                    l_mcd_cfg_reg_valid_mask,
                                    o_xscom_inits),
                 "Error from p10_gen_xscom_init");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure MCD error reporting and set basic controls (probing, group configuration)
///        if actively configured to track ranges on this chip
///
/// @param[in] i_target             Processor chip target
/// @param[in] i_target_sys         System level target
/// @param[in] i_enable_mcd         Enable MCD on this socket?
/// @param[in] o_xscom_inits        Vector (address/data pairs) to append
///                                 required XSCOM inits
fapi2::ReturnCode
p10_exit_cache_contained_add_mcd_base_inits(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    const bool i_enable_mcd,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    p10_chipUnitPairing_t l_cu_pairing = p10_chipUnitPairing_t(P10_NO_CU, 0);

    if (i_enable_mcd)
    {
        fapi2::buffer<uint64_t> l_valid_mask = 0;
        l_valid_mask.flush<1>();
        fapi2::buffer<uint64_t> l_mcd_vgc_data = 0;
        fapi2::buffer<uint64_t> l_mcd_vgc_valid_mask = 0;
        fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS_Type l_fabric_present_groups = 0;
        fapi2::buffer<uint64_t> l_mcd_rec_data = 0;
        fapi2::buffer<uint64_t> l_mcd_rec_valid_mask = 0;

        for (uint8_t i = 0; i < MCD_ENABLED_NUM_FIR_INITS; i++)
        {
            FAPI_TRY(p10_gen_xscom_init(i_target,
                                        l_cu_pairing,
                                        MCD_ENABLED_FIR_REG_SCOM_ADDRS[i],
                                        MCD_ENABLED_FIR_REG_SCOM_DATA_VALS[i],
                                        l_valid_mask,
                                        o_xscom_inits),
                     "Error from p10_gen_xscom_init (enabled, FIR init %d)", i);
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_PRESENT_GROUPS,
                               i_target_sys,
                               l_fabric_present_groups),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_PRESENT_GROUPS)");

        FAPI_TRY(PREP_MCD_BANK0_VGC(i_target));
        SET_MCD_BANK0_VGC_BANK0_MCD_P10_AVAIL_GROUPS(l_fabric_present_groups, l_mcd_vgc_data);
        SET_MCD_BANK0_VGC_BANK0_MCD_P10_AVAIL_GROUPS(l_valid_mask, l_mcd_vgc_valid_mask);
        SET_MCD_BANK0_VGC_BANK0_MCD_HANG_POLL_ENABLE(l_mcd_vgc_data);
        SET_MCD_BANK0_VGC_BANK0_MCD_HANG_POLL_ENABLE(l_mcd_vgc_valid_mask);

        FAPI_TRY(p10_gen_xscom_init(i_target,
                                    l_cu_pairing,
                                    MCD_BANK0_VGC,
                                    l_mcd_vgc_data,
                                    l_mcd_vgc_valid_mask,
                                    o_xscom_inits),
                 "Error from p10_gen_xscom_init (VGC)");

        FAPI_TRY(PREP_MCD_BANK0_REC(i_target));
        SET_MCD_BANK0_REC_ENABLE(l_mcd_rec_data);
        SET_MCD_BANK0_REC_ENABLE(l_mcd_rec_valid_mask);
        SET_MCD_BANK0_REC_CONTINUOUS(l_mcd_rec_data);
        SET_MCD_BANK0_REC_CONTINUOUS(l_mcd_rec_valid_mask);
        SET_MCD_BANK0_REC_PACE(MCD_RECOVERY_PACE_RATE, l_mcd_rec_data);
        SET_MCD_BANK0_REC_PACE(l_valid_mask, l_mcd_rec_valid_mask);
        SET_MCD_BANK0_REC_RTY_COUNT(MCD_RECOVERY_RTY_COUNT, l_mcd_rec_data);
        SET_MCD_BANK0_REC_RTY_COUNT(l_valid_mask, l_mcd_rec_valid_mask);
        SET_MCD_BANK0_REC_VG_COUNT(MCD_RECOVERY_VG_COUNT, l_mcd_rec_data);
        SET_MCD_BANK0_REC_VG_COUNT(l_valid_mask, l_mcd_rec_valid_mask);

        FAPI_TRY(p10_gen_xscom_init(i_target,
                                    l_cu_pairing,
                                    MCD_BANK0_REC,
                                    l_mcd_rec_data,
                                    l_mcd_rec_valid_mask,
                                    o_xscom_inits),
                 "Error from p10_gen_xscom_init (VGC)");
    }
    else
    {
        fapi2::buffer<uint64_t> l_mcd_fir_mask;
        l_mcd_fir_mask.flush<1>();

        FAPI_TRY(p10_gen_xscom_init(i_target,
                                    l_cu_pairing,
                                    scomt::proc::MCD_FIR_MASK_REG_RW,
                                    l_mcd_fir_mask,
                                    l_mcd_fir_mask,
                                    o_xscom_inits),
                 "Error from p10_gen_xscom_init (disabled, FIR mask)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


///
/// @brief Process MCD BAR attributes to calculate required XSCOM inits
///
/// @param[in]  i_targets           Collection of processor chip targets in drawer
/// @param[in]  i_target_sys        System level target
/// @param[out] o_xscom_inits       Vector (address/data pairs) to append
///                                 required XSCOM inits
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///

fapi2::ReturnCode
p10_exit_cache_contained_append_mcd_bar_inits(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_targets,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    std::vector<std::pair<uint64_t, uint64_t>>& o_xscom_inits)
{
    FAPI_DBG("Start");

    for (const auto l_target : i_targets)
    {
        p10_setup_bars_addr_range l_nm_range[2];
        p10_setup_bars_addr_range l_m_range;
        bool l_enable_mcd = false;
        fapi2::ATTR_MRW_HW_MIRRORING_ENABLE_Type l_mirroring_enable;

        // determine range of NM memory which MCD needs to cover on this chip
        {
            fapi2::ATTR_PROC_MEM_BASES_ACK_Type l_nm_bases;
            fapi2::ATTR_PROC_MEM_SIZES_ACK_Type l_nm_sizes;
            uint64_t l_base_address_nm0_unused, l_base_address_m_unused, l_base_address_mmio_unused;
            uint64_t l_base_address_nm1;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_BASES_ACK, l_target, l_nm_bases),
                     "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_BASES_ACK)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_SIZES_ACK, l_target, l_nm_sizes),
                     "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_SIZES_ACK)");

            FAPI_TRY(p10_fbc_utils_get_chip_base_address(l_target,
                     EFF_TOPOLOGY_ID,
                     l_base_address_nm0_unused,
                     l_base_address_nm1,
                     l_base_address_m_unused,
                     l_base_address_mmio_unused),
                     "Error from p10_fbc_utils_get_chip_base_address");


            // add each valid NM group to its associated NM chip range
            for (uint8_t ll = 0; ll < NUM_NON_MIRROR_REGIONS; ll++)
            {
                p10_setup_bars_addr_range l_range(l_nm_bases[ll],
                                                  l_nm_sizes[ll]);

                if (l_range.enabled)
                {
                    FAPI_DBG("Adding group: %d", ll);
                    l_range.print();
                    l_enable_mcd = true;

                    // determine which msel (nm0/nm1) the region lies within
                    if (l_range.base_addr >= l_base_address_nm1)
                    {
                        l_nm_range[1].merge(l_range);
                    }
                    else
                    {
                        l_nm_range[0].merge(l_range);
                    }
                }
            }

            // generate independent cover for each of the two msels
            for (uint8_t ii = 0; ii < 2; ii++)
            {
                if (l_nm_range[ii].enabled)
                {
                    FAPI_DBG("Generating MCD cover for NM msel %d",
                             ii);

                    FAPI_DBG("  Cover base address: 0x%016lX",
                             l_nm_range[ii].base_addr);

                    // ensure power of two alignment
                    if (!l_nm_range[ii].is_power_of_2())
                    {
                        l_nm_range[ii].round_next_power_of_2();
                    }

                    FAPI_DBG("  Cover size: 0x%016lX",
                             l_nm_range[ii].size);

                    // configure MCD to track this range
                    //   nm0 = MCD_TOP, nm1 = MCD_STR
                    FAPI_TRY(p10_exit_cache_contained_add_mcd_tracked_range(
                                 l_target,
                                 l_nm_range[ii],
                                 ((ii == 0) ? (TOP) : (STR)),
                                 o_xscom_inits),
                             "Error from p10_exit_cache_contained_add_mcd_tracked_range (NM%d)", ii);
                }
            }
        }

        // if mirroring is enabled, determine range of M memory which MCD needs to
        // cover on this chip
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE, i_target_sys, l_mirroring_enable),
                 "Error from FAPI_ATTR_GET (ATTR_MRW_HW_MIRRORING_ENABLE)");

        if (l_mirroring_enable != fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_OFF)
        {
            fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type l_m_bases;
            fapi2::ATTR_PROC_MIRROR_SIZES_ACK_Type l_m_sizes;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_BASES_ACK, l_target, l_m_bases),
                     "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASES_ACK)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_SIZES_ACK, l_target, l_m_sizes),
                     "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_SIZES_ACK)");

            for (uint8_t ll = 0; ll < NUM_MIRROR_REGIONS; ll++)
            {
                p10_setup_bars_addr_range l_range(l_m_bases[ll],
                                                  l_m_sizes[ll]);

                if (l_range.enabled)
                {
                    l_enable_mcd = true;
                    l_m_range.merge(l_range);
                }
            }

            if (l_m_range.enabled)
            {
                FAPI_DBG("Generating MCD cover for M msel");
                FAPI_DBG("  Cover base address: 0x%016lX",
                         l_m_range.base_addr);

                // ensure power of two alignment
                if (!l_m_range.is_power_of_2())
                {
                    l_m_range.round_next_power_of_2();
                }

                FAPI_DBG("  Cover size: 0x%016lX",
                         l_m_range.size);

                // configure MCD to track this range
                //   m = MCD_BOT
                FAPI_TRY(p10_exit_cache_contained_add_mcd_tracked_range(
                             l_target,
                             l_m_range,
                             BOT,
                             o_xscom_inits),
                         "Error from p10_exit_cache_contained_add_mcd_tracked_range (M)");
            }
        }

        FAPI_TRY(p10_exit_cache_contained_add_mcd_base_inits(l_target,
                 i_target_sys,
                 l_enable_mcd,
                 o_xscom_inits),
                 "Error from p10_exit_cache_contained_add_mcd_base_inits");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
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
                FAPI_TRY(p10_gen_xscom_init(
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
                 FAPI_SYSTEM,
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
