/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_setup_bars.C $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_setup_bars.C
/// @brief Configure nest unit base address registers (FAPI2)
///

// *HWP HWP Owner: Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB,FSP

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p9_setup_bars.H>
#include <p9_setup_bars_defs.H>
#include <p9_fbc_utils.H>
#include <p9_fbc_smp_utils.H>
#include <p9_mss_eff_grouping.H>


//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------
const std::map<uint64_t, uint64_t> p9_setup_bars_mcd_grp_size::xlate_map =
    p9_setup_bars_mcd_grp_size::create_map();


//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------


/// @brief Query chip level attributes describing base address of each region
///        of address space (non-mirrored, mirrored, MMIO) on this chip
///        system memory map (including MMIO)
///
/// @param[in]  i_target Processor chip target
/// @param[out] io_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_build_chip_info(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                              p9_setup_bars_chip_info& io_chip_info)
{
    FAPI_DBG("Start");

    FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_target,
             EFF_FBC_GRP_CHIP_IDS,
             io_chip_info.base_address_nm[0],
             io_chip_info.base_address_nm[1],
             io_chip_info.base_address_m,
             io_chip_info.base_address_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    FAPI_TRY(p9_fbc_utils_get_group_id_attr(i_target,
                                            io_chip_info.fbc_group_id),
             "Error from p9_fbc_utils_get_group_id_attr");

    FAPI_TRY(p9_fbc_utils_get_chip_id_attr(i_target,
                                           io_chip_info.fbc_chip_id),
             "Error from p9_fbc_utils_get_chip_id_attr");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Program MCD units 0/1 to track region of real address space
///        in grouped configuration.  SCOM addresses provided should represent
///        the two instances of the same configuration register in MCD0/1.
///
/// @param[in] i_target Processor chip target
/// @param[in] i_addr_range Structure defining region of address space to cover
/// @param[in] i_mcd0_reg_addr SCOM address of MCD0 cfg register (TOP/STR/BOT/CHA)
/// @param[in] i_mcd1_reg_addr SCOM address of MCD1 cfg register (TOP/STR/BOT/CHA)
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_mcd_track_range(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                              const p9_setup_bars_addr_range& i_addr_range,
                              const uint64_t i_mcd0_reg_addr,
                              const uint64_t i_mcd1_reg_addr)
{
    FAPI_DBG("Start");

    if (i_addr_range.enabled)
    {
        fapi2::buffer<uint64_t> l_mcd_reg;
        std::map<uint64_t, uint64_t>::const_iterator l_iter = p9_setup_bars_mcd_grp_size::xlate_map.find(i_addr_range.size);
        FAPI_ASSERT(l_iter != p9_setup_bars_mcd_grp_size::xlate_map.end(),
                    fapi2::P9_SETUP_BARS_INVALID_MCD_GROUP_SIZE_ERR().
                    set_TARGET(i_target).
                    set_RANGE_SIZE(i_addr_range.size),
                    "Invalid MCD group size!");

        // form content for MCD0 & write
        l_mcd_reg.setBit<PU_BANK0_MCD_STR_VALID>()
        .setBit<PU_BANK0_MCD_STR_CPG>()
        .insertFromRight<PU_BANK0_MCD_STR_GRP_SIZE, PU_BANK0_MCD_STR_GRP_SIZE_LEN>(l_iter->second)
        .insertFromRight<PU_BANK0_MCD_STR_GRP_BASE, PU_BANK0_MCD_STR_GRP_BASE_LEN>(i_addr_range.base_addr >>
                P9_SETUP_BARS_MCD_BASE_ADDR_SHIFT);
        FAPI_TRY(fapi2::putScom(i_target, i_mcd0_reg_addr, l_mcd_reg),
                 "Error from putScom (0x%08X)", i_mcd0_reg_addr);

        // change group member ID for MCD1 & write
        l_mcd_reg.setBit<PU_BANK0_MCD_STR_GRP_MBR_ID>();
        FAPI_TRY(fapi2::putScom(i_target, i_mcd1_reg_addr, l_mcd_reg),
                 "Error from putScom (0x%08X)", i_mcd1_reg_addr);
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Program MCD units 0/1 to track non-mirrored and mirrored regions
///        of real address space on this chip
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_mcd(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                  const p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");
    p9_setup_bars_addr_range l_nm_range[2];
    p9_setup_bars_addr_range l_m_range;
    bool l_enable_mcd = false;
    fapi2::ATTR_MRW_HW_MIRRORING_ENABLE_Type l_mirror_ctl;
    // determine range of NM memory which MCD needs to cover on this chip
    {
        fapi2::ATTR_PROC_MEM_BASES_ACK_Type l_nm_bases;
        fapi2::ATTR_PROC_MEM_SIZES_ACK_Type l_nm_sizes;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_BASES_ACK, i_target, l_nm_bases),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_BASES_ACK)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_SIZES_ACK, i_target, l_nm_sizes),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_SIZES_ACK)");

        // add each valid NM range to its associated NM chip range
        for (uint8_t ll = 0; ll < NUM_NON_MIRROR_REGIONS; ll++)
        {
            p9_setup_bars_addr_range l_range(l_nm_bases[ll],
                                             l_nm_sizes[ll]);

            if (l_range.enabled)
            {
                l_enable_mcd = true;

                // determine which NM range (0/1) this range is associated with
                if (l_range.base_addr < i_chip_info.base_address_nm[1])
                {
                    l_nm_range[0].merge(l_range);
                }
                else
                {
                    l_nm_range[1].merge(l_range);
                }
            }
        }

        // process each NM chip range
        for (uint8_t l_nm_range_idx = 0; l_nm_range_idx < 2; l_nm_range_idx++)
        {
            if (l_nm_range[l_nm_range_idx].enabled)
            {
                // ensure power of two alignment
                if (!l_nm_range[l_nm_range_idx].is_power_of_2())
                {
                    l_nm_range[l_nm_range_idx].round_next_power_of_2();
                }

                // verify that base lines up with chip info struct
                FAPI_ASSERT(l_nm_range[l_nm_range_idx].base_addr == i_chip_info.base_address_nm[l_nm_range_idx],
                            fapi2::P9_SETUP_BARS_INVALID_MCD_NM_RANGE_ERR().
                            set_TARGET(i_target).
                            set_NM_RANGE_IDX(l_nm_range_idx).
                            set_NM_RANGE_BASE_ADDR(l_nm_range[l_nm_range_idx].base_addr).
                            set_NM_RANGE_SIZE(l_nm_range[l_nm_range_idx].size).
                            set_NM_CHIP_BASE(i_chip_info.base_address_nm[l_nm_range_idx]),
                            "Invalid configuration for MCD NM range!");

                // configure MCD to track this range
                //   range 0 = MCD_BOT, range 1 = MCD_STR
                FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                                       l_nm_range[l_nm_range_idx],
                                                       ((l_nm_range_idx == 0) ? (PU_MCD1_BANK0_MCD_BOT) : (PU_MCD1_BANK0_MCD_STR)),
                                                       ((l_nm_range_idx == 0) ? (PU_BANK0_MCD_BOT) : (PU_BANK0_MCD_STR))),
                         "Error from p9_setup_bars_mcd_track_range (NM%d)", l_nm_range_idx);
            }
        }
    }


    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE, i_target_sys, l_mirror_ctl),
             "Error from FAPI_ATTR_GET (ATTR_MRW_HW_MIRRORING_ENABLE)");

    if (l_mirror_ctl == fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_TRUE)
        // determine range of M memory which MCD needs to cover on this chip
    {

        fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type l_m_bases;
        fapi2::ATTR_PROC_MIRROR_SIZES_ACK_Type l_m_sizes;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_BASES_ACK, i_target, l_m_bases),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASES_ACK)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_SIZES_ACK, i_target, l_m_sizes),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_SIZES_ACK)");

        // add each valid M range to the M chip range
        for (uint8_t ll = 0; ll < NUM_MIRROR_REGIONS; ll++)
        {
            p9_setup_bars_addr_range l_range(l_m_bases[ll],
                                             l_m_sizes[ll]);

            if (l_range.enabled)
            {
                l_enable_mcd = true;
                l_m_range.merge(l_range);
            }
        }

        // process M chip range
        if (l_m_range.enabled)
        {
            // ensure power of two alignment
            if (!l_m_range.is_power_of_2())
            {
                l_m_range.round_next_power_of_2();
            }

            // verify that base lines up with chip info struct
            FAPI_ASSERT(l_m_range.base_addr == i_chip_info.base_address_m,
                        fapi2::P9_SETUP_BARS_INVALID_MCD_M_RANGE_ERR().
                        set_TARGET(i_target).
                        set_M_RANGE_BASE_ADDR(l_m_range.base_addr).
                        set_M_RANGE_SIZE(l_m_range.size).
                        set_M_CHIP_BASE(i_chip_info.base_address_m),
                        "Invalid configuration for MCD M range!");

            // configure MCD to track this range (MCD_TOP)
            FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                                   l_m_range,
                                                   PU_MCD1_BANK0_MCD_TOP,
                                                   PU_BANK0_MCD_TOP),
                     "Error from p9_setup_bars_mcd_track_range (M");
        }
    }

    if (l_enable_mcd)
    {
        fapi2::buffer<uint64_t> l_fir_data = 0;
        fapi2::buffer<uint64_t> l_mcd_rec_data = 0;
        fapi2::buffer<uint64_t> l_mcd_vgc_data = 0;

        // configure FIR
        // clear FIR
        FAPI_TRY(fapi2::putScom(i_target, PU_MCC_FIR_REG, l_fir_data),
                 "Error from putScom (PU_MCC_FIR_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCC_FIR_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCC_FIR_REG)");
        // set action
        l_fir_data = MCD_FIR_ACTION0;
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_ACTION0_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_ACTION0_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_ACTION0_REG)");
        l_fir_data = MCD_FIR_ACTION1;
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_ACTION1_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_ACTION1_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_ACTION1_REG)");
        // set mask
        l_fir_data = MCD_FIR_MASK;
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_MASK_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_MASK_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_MASK_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_MASK_REG)");

        // set MCD vectored group configuration
        l_mcd_vgc_data.insertFromRight<PU_BANK0_MCD_VGC_AVAIL_GROUPS, PU_BANK0_MCD_VGC_AVAIL_GROUPS_LEN>(MCD_VGC_AVAIL_GROUPS);
        l_mcd_vgc_data.setBit<PU_BANK0_MCD_VGC_HANG_POLL_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target, PU_BANK0_MCD_VGC, l_mcd_vgc_data),
                 "Error from putScom (PU_BANK0_MCD_VGC)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_BANK0_MCD_VGC, l_mcd_vgc_data),
                 "Error from putScom (PU_MCD1_BANK0_MCD_VGC)");

        // enable MCD probes
        l_mcd_rec_data.setBit<PU_BANK0_MCD_REC_ENABLE>();
        l_mcd_rec_data.setBit<PU_BANK0_MCD_REC_CONTINUOUS>();
        l_mcd_rec_data.insertFromRight<PU_BANK0_MCD_REC_PACE, PU_BANK0_MCD_REC_PACE_LEN>(MCD_RECOVERY_PACE_RATE);
        l_mcd_rec_data.insertFromRight<PU_BANK0_MCD_REC_RTY_COUNT, PU_BANK0_MCD_REC_RTY_COUNT_LEN>(MCD_RECOVERY_RTY_COUNT);
        l_mcd_rec_data.insertFromRight<PU_BANK0_MCD_REC_VG_COUNT, PU_BANK0_MCD_REC_VG_COUNT_LEN>(MCD_RECOVERY_VG_COUNT);
        FAPI_TRY(fapi2::putScom(i_target, PU_BANK0_MCD_REC, l_mcd_rec_data),
                 "Error from putScom (PU_BANK0_MCD_REC)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_BANK0_MCD_REC, l_mcd_rec_data),
                 "Error from putScom (PU_MCD1_BANK0_MCD_REC)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure FSP MMIO access
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_fsp(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                  const p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_FSP_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_FSP_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_FSP_BAR_SIZE_Type l_bar_offset_mask;
        fapi2::ATTR_PROC_FSP_MMIO_MASK_SIZE_Type l_mmio_mask_size;
        fapi2::buffer<uint64_t> l_fsp_bar = i_chip_info.base_address_mmio;
        fapi2::buffer<uint64_t> l_fsp_mmr;
        fapi2::buffer<uint64_t> l_fsp_mmr_mask;
        fapi2::buffer<uint64_t> l_status_ctl;
        fapi2::buffer<uint64_t> l_status_ctl_mask;

        // retrieve BAR offset/size
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_SIZE, i_target_sys, l_bar_offset_mask),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_SIZE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_MMIO_MASK_SIZE, i_target_sys, l_mmio_mask_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_MMIO_MASK_SIZE)");

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P9_SETUP_BARS_FSP_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "FSP BAR attributes are not aligned to HW implementation");

        // form FSP BAR SCOM register format
        l_fsp_bar += l_bar_offset;

        // form FSP BAR mask SCOM register format
        l_fsp_mmr = l_bar_offset_mask;
        l_fsp_mmr.invert();
        l_fsp_mmr_mask.setBit<PU_PSI_FSP_MMR_REG_MMR, PU_PSI_FSP_MMR_REG_MMR_LEN>();

        // form PSI Host Bridge Control/Status SCOM register format
        l_status_ctl = l_mmio_mask_size;
        l_status_ctl.setBit<PU_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE>();

        l_status_ctl_mask.setBit<PU_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK, PU_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK_LEN>()
        .setBit<PU_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE>();

        // write to registers
        FAPI_TRY(fapi2::putScom(i_target, PU_PSI_BRIDGE_FSP_BAR_REG, l_fsp_bar),
                 "Error from putScom (PU_PSI_BRIDGE_FSP_BAR_REG)");

        FAPI_TRY(fapi2::putScomUnderMask(i_target, PU_PSI_FSP_MMR_REG, l_fsp_mmr, l_fsp_mmr_mask),
                 "Error from putScomUnderMak (PU_PSI_FSP_MMR_REG)");

        FAPI_TRY(fapi2::putScomUnderMask(i_target, PU_PSIHB_STATUS_CTL_REG_SCOM, l_status_ctl, l_status_ctl_mask),
                 "Error from putScomUnderMak (PU_PSIHB_STATUS_CTL_REG_SCOM)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure PSI MMIO access
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_psi(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                  const p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PSI_BRIDGE_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::buffer<uint64_t> l_bar = i_chip_info.base_address_mmio;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET)");

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & P9_SETUP_BARS_OFFSET_MASK_1_MB) == 0,
                    fapi2::P9_SETUP_BARS_PSI_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(P9_SETUP_BARS_OFFSET_MASK_1_MB)
                    .set_BAR_OVERLAP(l_bar_offset & P9_SETUP_BARS_OFFSET_MASK_1_MB),
                    "PSI BAR attributes are not aligned to HW implementation");

        // form PSI BAR SCOM register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_PSI_BRIDGE_BAR_REG_EN>();

        // write to register
        FAPI_TRY(fapi2::putScom(i_target, PU_PSI_BRIDGE_BAR_REG, l_bar),
                 "Error from putScom (PU_PSI_BRIDGE_BAR_REG)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure NPU MMIO access
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_npu(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                  const p9_setup_bars_chip_info& i_chip_info)

{
    FAPI_DBG("Start");

    uint8_t l_is_dd1 = 0x1ull;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR, i_target, l_is_dd1),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR)");

    // PHY0
    {
        fapi2::ATTR_PROC_NPU_PHY0_BAR_ENABLE_Type l_phy0_enable;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_PHY0_BAR_ENABLE, i_target, l_phy0_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_PHY0_BAR_ENABLE)");

        if (l_phy0_enable == fapi2::ENUM_ATTR_PROC_NPU_PHY0_BAR_ENABLE_ENABLE)
        {
            fapi2::buffer<uint64_t> l_phy0_bar = i_chip_info.base_address_mmio;
            fapi2::ATTR_PROC_NPU_PHY0_BAR_BASE_ADDR_OFFSET_Type l_phy0_offset;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_PHY0_BAR_BASE_ADDR_OFFSET, i_target_sys, l_phy0_offset),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_PHY0_BAR_BASE_ADDR_OFFSET)");

            FAPI_ASSERT((l_phy0_offset & P9_SETUP_BARS_OFFSET_MASK_2_MB) == 0,
                        fapi2::P9_SETUP_BARS_NPU_PHY0_BAR_ATTR_ERR()
                        .set_TARGET(i_target)
                        .set_BAR_OFFSET(l_phy0_offset)
                        .set_BAR_OFFSET_MASK(P9_SETUP_BARS_OFFSET_MASK_2_MB)
                        .set_BAR_OVERLAP(l_phy0_offset & P9_SETUP_BARS_OFFSET_MASK_2_MB),
                        "NPU PHY0 BAR offset attribute is not aligned to HW implementation for DD1 level");

            l_phy0_bar &= NPU_BAR_BASE_ADDR_MASK;
            l_phy0_bar += l_phy0_offset;
            l_phy0_bar = l_phy0_bar << NPU_BAR_ADDR_SHIFT;
            l_phy0_bar.setBit<PU_NPU0_SM0_PHY_BAR_CONFIG_ENABLE>();

            for (uint8_t ll = 0; ll < NPU_NUM_BAR_SHADOWS; ll++)
            {
                if (l_is_dd1 == 0)
                {
                    FAPI_TRY(fapi2::putScom(i_target, NPU_PHY0_BAR_REGS_DD2[ll], l_phy0_bar),
                             "Error from putScom (0x08X)", NPU_PHY0_BAR_REGS_DD2[ll]);
                }
                else
                {
                    FAPI_TRY(fapi2::putScom(i_target, NPU_PHY0_BAR_REGS[ll], l_phy0_bar),
                             "Error from putScom (0x08X)", NPU_PHY0_BAR_REGS[ll]);
                }
            }
        }
    }

    // PHY1
    {
        fapi2::ATTR_PROC_NPU_PHY1_BAR_ENABLE_Type l_phy1_enable;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_PHY1_BAR_ENABLE, i_target, l_phy1_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_PHY1_BAR_ENABLE)");

        if (l_phy1_enable == fapi2::ENUM_ATTR_PROC_NPU_PHY1_BAR_ENABLE_ENABLE)
        {
            fapi2::buffer<uint64_t> l_phy1_bar = i_chip_info.base_address_mmio;
            fapi2::ATTR_PROC_NPU_PHY1_BAR_BASE_ADDR_OFFSET_Type l_phy1_offset;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_PHY1_BAR_BASE_ADDR_OFFSET, i_target_sys, l_phy1_offset),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_PHY1_BAR_BASE_ADDR_OFFSET)");

            FAPI_ASSERT((l_phy1_offset & P9_SETUP_BARS_OFFSET_MASK_2_MB) == 0,
                        fapi2::P9_SETUP_BARS_NPU_PHY1_BAR_ATTR_ERR()
                        .set_TARGET(i_target)
                        .set_BAR_OFFSET(l_phy1_offset)
                        .set_BAR_OFFSET_MASK(P9_SETUP_BARS_OFFSET_MASK_2_MB)
                        .set_BAR_OVERLAP(l_phy1_offset & P9_SETUP_BARS_OFFSET_MASK_2_MB),
                        "NPU PHY1 BAR offset attribute is not aligned to HW implementation");

            l_phy1_bar &= NPU_BAR_BASE_ADDR_MASK;
            l_phy1_bar += l_phy1_offset;
            l_phy1_bar = l_phy1_bar << NPU_BAR_ADDR_SHIFT;
            l_phy1_bar.setBit<PU_NPU0_SM0_PHY_BAR_CONFIG_ENABLE>();

            for (uint8_t ll = 0; ll < NPU_NUM_BAR_SHADOWS; ll++)
            {
                if (l_is_dd1 == 0)
                {
                    FAPI_TRY(fapi2::putScom(i_target, NPU_PHY1_BAR_REGS_DD2[ll], l_phy1_bar),
                             "Error from putScom (0x08X)", NPU_PHY1_BAR_REGS_DD2[ll]);
                }
                else
                {

                    FAPI_TRY(fapi2::putScom(i_target, NPU_PHY1_BAR_REGS[ll], l_phy1_bar),
                             "Error from putScom (0x08X)", NPU_PHY1_BAR_REGS[ll]);
                }
            }
        }
    }

    // MMIO
    {
        fapi2::ATTR_PROC_NPU_MMIO_BAR_ENABLE_Type l_mmio_enable;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_MMIO_BAR_ENABLE, i_target, l_mmio_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_MMIO_BAR_ENABLE)");

        if (l_mmio_enable == fapi2::ENUM_ATTR_PROC_NPU_MMIO_BAR_ENABLE_ENABLE)
        {
            fapi2::buffer<uint64_t> l_mmio_bar = i_chip_info.base_address_mmio;
            fapi2::ATTR_PROC_NPU_MMIO_BAR_BASE_ADDR_OFFSET_Type l_mmio_offset;
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_MMIO_BAR_BASE_ADDR_OFFSET, i_target_sys, l_mmio_offset),
                     "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_MMIO_BAR_BASE_ADDR_OFFSET)");

            FAPI_ASSERT((l_mmio_offset & P9_SETUP_BARS_OFFSET_MASK_16_MB) == 0,
                        fapi2::P9_SETUP_BARS_NPU_MMIO_BAR_ATTR_ERR()
                        .set_TARGET(i_target)
                        .set_BAR_OFFSET(l_mmio_offset)
                        .set_BAR_OFFSET_MASK(P9_SETUP_BARS_OFFSET_MASK_16_MB)
                        .set_BAR_OVERLAP(l_mmio_offset & P9_SETUP_BARS_OFFSET_MASK_2_MB),
                        "NPU MMIO BAR offset attribute is not aligned to HW implementation for DD1 level");

            l_mmio_bar &= NPU_BAR_BASE_ADDR_MASK;
            l_mmio_bar += l_mmio_offset;
            l_mmio_bar = l_mmio_bar << NPU_BAR_ADDR_SHIFT;
            l_mmio_bar.setBit<PU_NPU0_SM0_PHY_BAR_CONFIG_ENABLE>();

            for (uint8_t ll = 0; ll < NPU_NUM_BAR_SHADOWS; ll++)
            {
                if (l_is_dd1 == 0)
                {
                    FAPI_TRY(fapi2::putScom(i_target, NPU_MMIO_BAR_REGS_DD2[ll], l_mmio_bar),
                             "Error from putScom (0x08X)", NPU_MMIO_BAR_REGS_DD2[ll]);
                }
                else
                {

                    FAPI_TRY(fapi2::putScom(i_target, NPU_MMIO_BAR_REGS[ll], l_mmio_bar),
                             "Error from putScom (0x08X)", NPU_MMIO_BAR_REGS[ll]);
                }
            }
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure INT MMIO access
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_int(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                  const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                  const p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    ////////////////////
    // INT_CQ_PC_BAR  //
    ////////////////////

    // retrieve BAR enable
    fapi2::ATTR_PROC_INT_CQ_PC_BAR_ENABLE_Type l_pc_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_PC_BAR_ENABLE, i_target, l_pc_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_PC_BAR_ENABLE)");

    if (l_pc_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_PC_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET_MASK_Type l_bar_mask;
        fapi2::buffer<uint64_t> l_bar = i_chip_info.base_address_mmio;
        fapi2::buffer<uint64_t> l_bar_mask_inverted;
        fapi2::buffer<uint64_t> l_bar_offset_26_38;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR offset mask
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET_MASK, i_target_sys, l_bar_mask),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_PC_BAR_BASE_ADDR_OFFSET_MASK)");

        l_bar_offset_26_38 = l_bar_offset;
        l_bar_offset_26_38.clearBit(PU_INT_CQ_PC_BAR_ADDR_8_38, PU_INT_CQ_PC_BARM_ADDR_26_38 - PU_INT_CQ_PC_BAR_ADDR_8_38);

        l_bar_mask_inverted = l_bar_mask;
        l_bar_mask_inverted.invert();

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset_26_38 & l_bar_mask_inverted) == 0,
                    fapi2::P9_SETUP_BARS_INT_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_mask_inverted)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_mask_inverted),
                    "INT_CQ_PC_BAR attributes are not aligned to HW implementation");

        // form INT CQ PC BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_PC_BAR_VALID>();

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_PC_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_PC_BAR)");

        // write to bar mask register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_PC_BARM, l_bar_mask),
                 "Error from putScom (PU_INT_CQ_PC_BARM)");
    }

    ////////////////////
    // INT_CQ_VC_BAR  //
    ////////////////////

    // retrieve BAR enable
    fapi2::ATTR_PROC_INT_CQ_VC_BAR_ENABLE_Type l_vc_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_VC_BAR_ENABLE, i_target, l_vc_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_VC_BAR_ENABLE)");

    if (l_vc_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_VC_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET_MASK_Type l_bar_mask;
        fapi2::buffer<uint64_t> l_bar = i_chip_info.base_address_mmio;
        fapi2::buffer<uint64_t> l_bar_mask_inverted;
        fapi2::buffer<uint64_t> l_bar_offset_26_37;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR offset mask
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET_MASK, i_target_sys, l_bar_mask),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_VC_BAR_BASE_ADDR_OFFSET_MASK)");

        l_bar_offset_26_37 = l_bar_offset;
        l_bar_offset_26_37.clearBit(PU_INT_CQ_VC_BAR_ADDR_8_37, PU_INT_CQ_VC_BARM_ADDR_21_37 - PU_INT_CQ_VC_BAR_ADDR_8_37);

        l_bar_mask_inverted = l_bar_mask;
        l_bar_mask_inverted.invert();

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset_26_37 & l_bar_mask_inverted) == 0,
                    fapi2::P9_SETUP_BARS_INT_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_mask_inverted)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_mask_inverted),
                    "INT_CQ_VC_BAR attributes are not aligned to HW implementation");

        // form INT CQ PC BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_VC_BAR_VALID>();

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_VC_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_VC_BAR)");

        // write to bar mask register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_VC_BARM, l_bar_mask),
                 "Error from putScom (PU_INT_CQ_VC_BARM)");
    }

    ////////////////////
    // INT_CQ_TM1_BAR //
    ////////////////////

    // retrieve BAR enable
    fapi2::ATTR_PROC_INT_CQ_TM1_BAR_ENABLE_Type l_tm1_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_TM1_BAR_ENABLE, i_target, l_tm1_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_TM1_BAR_ENABLE)");

    if (l_tm1_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_INT_CQ_TM1_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::buffer<uint64_t> l_bar = i_chip_info.base_address_mmio;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_TM1_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_TM1_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR page size
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE)");

        l_bar_offset_mask = l_bar_page_size ? (P9_SETUP_BARS_OFFSET_MASK_64_KB) : (P9_SETUP_BARS_OFFSET_MASK_4_KB);

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P9_SETUP_BARS_INT_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT_CQ_TM1_BAR attributes are not aligned to HW implementation");

        // form INT CQ TM1 BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_TM1_BAR_VALID>();

        if(l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE_64K)
        {
            l_bar.setBit(PU_INT_CQ_TM1_BAR_PAGE_SIZE_64K);
        }

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_TM1_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_TM1_BAR)");
    }

    ////////////////////
    // INT_CQ_IC_BAR  //
    ////////////////////

    // retrieve BAR enable
    fapi2::ATTR_PROC_INT_CQ_IC_BAR_ENABLE_Type l_ic_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_IC_BAR_ENABLE, i_target, l_ic_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_IC_BAR_ENABLE)");

    if (l_ic_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_ENABLE_ENABLE)
    {
        fapi2::ATTR_PROC_INT_CQ_IC_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::buffer<uint64_t> l_bar = i_chip_info.base_address_mmio;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_IC_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_IC_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR page size
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE)");

        l_bar_offset_mask = l_bar_page_size ? (P9_SETUP_BARS_OFFSET_MASK_64_KB) : (P9_SETUP_BARS_OFFSET_MASK_4_KB);

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P9_SETUP_BARS_INT_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT_CQ_IC_BAR attributes are not aligned to HW implementation");

        // form INT CQ IC BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_IC_BAR_VALID>();

        if(l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE_64K)
        {
            l_bar.setBit(PU_INT_CQ_IC_BAR_PAGE_SIZE_64K);
        }

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_IC_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_IC_BAR)");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// description in header
fapi2::ReturnCode
p9_setup_bars(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    p9_setup_bars_chip_info l_chip_info;
    fapi2::buffer<uint16_t> l_pg_value = 0xFFFF;
    uint8_t l_attr_chip_unit_pos = 0;

    //Get perv target for later
    auto l_perv_tgt = i_target.getChildren<fapi2::TARGET_TYPE_PERV>
                      (fapi2::TARGET_FILTER_NEST_WEST, fapi2::TARGET_STATE_FUNCTIONAL);

    // process chip information
    FAPI_TRY(p9_setup_bars_build_chip_info(i_target,
                                           l_chip_info),
             "Error from p9_setup_bars_build_chip_info");

    // setup unit BARS
    // FSP
    FAPI_TRY(p9_setup_bars_fsp(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_fsp");
    // PSI
    FAPI_TRY(p9_setup_bars_psi(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_psi");

    // NPU
    //Check to see if NPU is valid in PG (N3 chiplet)
    for (auto l_tgt : l_perv_tgt)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_tgt, l_attr_chip_unit_pos));

        if (l_attr_chip_unit_pos == N3_CHIPLET_ID )
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_tgt, l_pg_value));
            break;
        }
    }

    //Bit7 == 0 means NPU is good
    if (!l_pg_value.getBit<7>())
    {
        FAPI_TRY(p9_setup_bars_npu(i_target, FAPI_SYSTEM, l_chip_info),
                 "Error from p9_setup_bars_npu");
    }

    // MCD
    FAPI_TRY(p9_setup_bars_mcd(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_mcd");
    // INT
    FAPI_TRY(p9_setup_bars_int(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_int");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}

