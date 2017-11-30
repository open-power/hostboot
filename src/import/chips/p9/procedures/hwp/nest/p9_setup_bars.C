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
// *HWP Level: 3
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
///        system memory map
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
             io_chip_info.base_address_nm0,
             io_chip_info.base_address_nm1,
             io_chip_info.base_address_m,
             io_chip_info.base_address_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    FAPI_TRY(p9_fbc_utils_get_group_id_attr(i_target,
                                            io_chip_info.fbc_group_id),
             "Error from p9_fbc_utils_get_group_id_attr");

    FAPI_TRY(p9_fbc_utils_get_chip_id_attr(i_target,
                                           io_chip_info.fbc_chip_id),
             "Error from p9_fbc_utils_get_chip_id_attr");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_EXTENDED_ADDRESSING_MODE,
                           i_target,
                           io_chip_info.extended_addressing_mode),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_EXTENDED_ADDRESSING_MODE)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW423589_OPTION2,
                           i_target,
                           io_chip_info.hw423589_option2),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW423589_OPTION2)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW423589_OPTION1,
                           i_target,
                           io_chip_info.hw423589_option1),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW423589_OPTION1)");

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
                    set_RANGE_BASE_ADDR(i_addr_range.base_addr).
                    set_RANGE_SIZE(i_addr_range.size).
                    set_MCD0_REG_ADDR(i_mcd0_reg_addr).
                    set_MCD1_REG_ADDR(i_mcd1_reg_addr),
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


///
/// @brief Enable MCD units 0/1
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_mcd_enable(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    uint8_t l_addr_extension_group_id = 0;
    uint8_t l_addr_extension_chip_id = 0;
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

    if (i_chip_info.extended_addressing_mode)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID,
                               i_target_sys,
                               l_addr_extension_group_id),
                 "Error from FAPI_ATTR_GET (ATTR_FABRIC_ADDR_EXTENSION_GROUP_ID)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID,
                               i_target_sys,
                               l_addr_extension_chip_id),
                 "Error from FAPI_ATTR_GET (ATTR_FABRIC_ADDR_EXTENSION_CHIP_ID");
    }

    // set MCD vectored group configuration register
    FAPI_TRY(fapi2::getScom(i_target, PU_BANK0_MCD_VGC, l_mcd_vgc_data),
             "Error from getScom (PU_BANK0_MCD_VGC)");

    if (l_addr_extension_group_id ||
        l_addr_extension_chip_id)
    {
        // adjust FIR setup for HW413218
        l_fir_data = MCD_FIR_ACTION0;
        l_fir_data.clearBit<PU_MCD1_MCD_FIR_MASK_REG_ARRAY_ECC_UE>();
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_ACTION0_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_ACTION0_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_ACTION0_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_ACTION0_REG)");

        l_fir_data = MCD_FIR_ACTION1;
        l_fir_data.clearBit<PU_MCD1_MCD_FIR_MASK_REG_ARRAY_ECC_UE>();
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_ACTION1_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_ACTION1_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_ACTION1_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_ACTION1_REG)");

        // setup extended addressing
        l_mcd_vgc_data.setBit<P9N2_PU_BANK0_MCD_VGC_EXT_ADDR_FAC_ENABLE>();
        l_mcd_vgc_data.insertFromRight<P9N2_PU_BANK0_MCD_VGC_EXT_ADDR_FAC_MASK,
                                       P9N2_PU_BANK0_MCD_VGC_EXT_ADDR_FAC_MASK_LEN>((l_addr_extension_group_id << 3) |
                                               l_addr_extension_chip_id);
    }

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

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Program MCD units 0/1 to track non-mirrored regions
///        of real address space on this chip, for HW423589_OPTION2
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_mcd_HW423589_OPTION2(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                   const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                                   p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");
    p9_setup_bars_addr_range l_nm_cover;
    uint64_t l_cover_size = MAX_INTERLEAVE_GROUP_SIZE_HW423589_OPTION2 / 2;

    // setup two MCD configurations
    // chip msel0 base       [ size=256 GB ]
    // chip msel0 base + 256 [ size=256 GB ]
    l_nm_cover.enabled = true;
    l_nm_cover.base_addr = i_chip_info.base_address_nm0.front();
    l_nm_cover.size = l_cover_size;

    FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                           l_nm_cover,
                                           PU_MCD1_BANK0_MCD_TOP,
                                           PU_BANK0_MCD_TOP),
             "Error from p9_setup_bars_mcd_track_range (0)");

    l_nm_cover.base_addr += l_cover_size;

    FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                           l_nm_cover,
                                           PU_MCD1_BANK0_MCD_STR,
                                           PU_BANK0_MCD_STR),
             "Error from p9_setup_bars_mcd_track_range (1)");

    FAPI_TRY(p9_setup_bars_mcd_enable(i_target,
                                      i_target_sys,
                                      i_chip_info),
             "Error from p9_setup_bars_mcd_enable");

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
                  p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");
    std::vector<p9_setup_bars_addr_range> l_nm_ranges[2];
    std::vector<p9_setup_bars_addr_range> l_m_ranges;
    bool l_enable_mcd_nm = false;
    bool l_enable_mcd_m = false;
    fapi2::ATTR_MRW_HW_MIRRORING_ENABLE_Type l_mirror_ctl;

    // determine range of NM memory which MCD needs to cover on this chip
    {
        fapi2::ATTR_PROC_MEM_BASES_ACK_Type l_nm_bases;
        fapi2::ATTR_PROC_MEM_SIZES_ACK_Type l_nm_sizes;

        // initialize set of ranges -- track the number of mappable regions
        // in each msel
        for (uint8_t ii = 0; ii < i_chip_info.base_address_nm0.size(); ii++)
        {
            p9_setup_bars_addr_range r;
            l_nm_ranges[0].push_back(r);
        }

        for (uint8_t ii = 0; ii < i_chip_info.base_address_nm1.size(); ii++)
        {
            p9_setup_bars_addr_range r;
            l_nm_ranges[1].push_back(r);
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_BASES_ACK, i_target, l_nm_bases),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_BASES_ACK)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEM_SIZES_ACK, i_target, l_nm_sizes),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MEM_SIZES_ACK)");

        // add each valid NM group to its associated NM chip range
        for (uint8_t ll = 0; ll < NUM_NON_MIRROR_REGIONS; ll++)
        {
            p9_setup_bars_addr_range l_range(l_nm_bases[ll],
                                             l_nm_sizes[ll]);

            if (l_range.enabled)
            {
                FAPI_DBG("Adding group: %d", ll);
                l_range.print();

                bool l_range_placed = false;
                l_enable_mcd_nm = true;

                // determine which msel (nm0/nm1) the region lies within
                // then determine which NM range this range is associated with
                // find first range (walking backwards through the sorted
                // list) for which the starting address of this range is
                // greater than the base address
                if ((i_chip_info.base_address_nm1.size() != 0) &&
                    l_range.base_addr >= i_chip_info.base_address_nm1[0])
                {
                    // nm1
                    for (int jj = i_chip_info.base_address_nm1.size() - 1;
                         (jj >= 0) && !l_range_placed;
                         jj--)
                    {
                        if (l_range.base_addr >= i_chip_info.base_address_nm1[jj])
                        {
                            l_nm_ranges[1][jj].merge(l_range);
                            l_range_placed = true;
                        }
                    }
                }
                else
                {
                    // nm0
                    for (int jj = i_chip_info.base_address_nm0.size() - 1;
                         (jj >= 0) && !l_range_placed;
                         jj--)
                    {
                        if (l_range.base_addr >= i_chip_info.base_address_nm0[jj])
                        {
                            l_nm_ranges[0][jj].merge(l_range);
                            l_range_placed = true;
                        }
                    }
                }

                // check for consistency -- should always find a match
                FAPI_ASSERT(l_range_placed,
                            fapi2::P9_SETUP_BARS_INVALID_MCD_NM_RANGE_ERR().
                            set_TARGET(i_target).
                            set_NM_RANGE_IDX(ll).
                            set_NM_RANGE_BASE_ADDR(l_nm_bases[ll]).
                            set_NM_RANGE_SIZE(l_nm_sizes[ll]).
                            set_NM0_CHIP_BASES(i_chip_info.base_address_nm0).
                            set_NM1_CHIP_BASES(i_chip_info.base_address_nm1),
                            "Invalid configuration for MCD NM range!");
            }
        }

        // generate independent cover for each of the two msels
        for (uint8_t ii = 0; ii < 2; ii++)
        {
            if (l_nm_ranges[ii].size() != 0)
            {
                FAPI_DBG("Generating MCD cover for NM msel %d",
                         ii);

                p9_setup_bars_addr_range l_nm_cover;
                l_nm_cover.base_addr = l_nm_ranges[ii][0].base_addr;

                FAPI_DBG("  Cover base address: 0x%016lX",
                         l_nm_cover.base_addr);

                for (uint8_t jj = 0; jj < l_nm_ranges[ii].size(); jj++)
                {
                    if (l_nm_ranges[ii][jj].enabled)
                    {
                        FAPI_DBG("  Processing valid range %d, base addr: 0x%016lX, size: 0x%016lX",
                                 jj, l_nm_ranges[ii][jj].base_addr, l_nm_ranges[ii][jj].size);

                        l_nm_cover.enabled = true;

                        // ensure power of two alignment
                        if (!l_nm_ranges[ii][jj].is_power_of_2())
                        {
                            l_nm_ranges[ii][jj].round_next_power_of_2();
                        }

                        i_chip_info.ranges.push_back(l_nm_ranges[ii][jj]);
                        i_chip_info.ranges.back().print();
                    }

                    // need to cover size of largest alias region
                    if (l_nm_cover.size < l_nm_ranges[ii][jj].size)
                    {
                        l_nm_cover.size = l_nm_ranges[ii][jj].size;
                        FAPI_DBG("  Updating cover size: 0x%016lX",
                                 l_nm_cover.size);
                    }
                }

                // configure MCD to track this range
                //   nm0 = MCD_BOT, nm1 = MCD_STR
                FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                                       l_nm_cover,
                                                       ((ii == 0) ? (PU_MCD1_BANK0_MCD_BOT) : (PU_MCD1_BANK0_MCD_STR)),
                                                       ((ii == 0) ? (PU_BANK0_MCD_BOT) : (PU_BANK0_MCD_STR))),
                         "Error from p9_setup_bars_mcd_track_range (NM%d)", ii);
            }
        }
    }

    // if mirroring is enabled, determine range of M memory which MCD needs to
    // cover on this chip
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MRW_HW_MIRRORING_ENABLE, i_target_sys, l_mirror_ctl),
             "Error from FAPI_ATTR_GET (ATTR_MRW_HW_MIRRORING_ENABLE)");

    if (l_mirror_ctl == fapi2::ENUM_ATTR_MRW_HW_MIRRORING_ENABLE_TRUE)
    {
        fapi2::ATTR_PROC_MIRROR_BASES_ACK_Type l_m_bases;
        fapi2::ATTR_PROC_MIRROR_SIZES_ACK_Type l_m_sizes;
        p9_setup_bars_addr_range l_m_cover;

        // initialize set of ranges -- track the number of mappable
        // regions
        for (uint8_t ii = 0; ii < i_chip_info.base_address_m.size(); ii++)
        {
            p9_setup_bars_addr_range r;
            l_m_ranges.push_back(r);
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_BASES_ACK, i_target, l_m_bases),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_BASES_ACK)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MIRROR_SIZES_ACK, i_target, l_m_sizes),
                 "Error fram FAPI_ATTR_GET (ATTR_PROC_MIRROR_SIZES_ACK)");

        // add each valid M group range to its associated M chip range
        for (uint8_t ll = 0; ll < NUM_MIRROR_REGIONS; ll++)
        {
            p9_setup_bars_addr_range l_range(l_m_bases[ll],
                                             l_m_sizes[ll]);

            if (l_range.enabled)
            {
                bool l_range_placed = false;
                l_enable_mcd_m = true;

                // determine which M range this range is associated with
                // find first range (walking backwards through the sorted
                // list) for which the starting address of this range is
                // greater than the base address
                for (int jj = i_chip_info.base_address_m.size() - 1;
                     (jj >= 0) && !l_range_placed;
                     jj--)
                {
                    if (l_range.base_addr >= i_chip_info.base_address_m[jj])
                    {
                        l_m_ranges[jj].merge(l_range);
                        l_range_placed = true;
                    }
                }

                // check for consistency -- should always find a match
                FAPI_ASSERT(l_range_placed,
                            fapi2::P9_SETUP_BARS_INVALID_MCD_M_RANGE_ERR().
                            set_TARGET(i_target).
                            set_M_RANGE_IDX(ll).
                            set_M_RANGE_BASE_ADDR(l_m_bases[ll]).
                            set_M_RANGE_SIZE(l_m_sizes[ll]).
                            set_M_CHIP_BASES(i_chip_info.base_address_m),
                            "Invalid configuration for MCD M range!");
            }
        }

        // process each merged range, find the largest which the MCD needs to
        // cover -- all aliases will be covered by the MCD config reg programmed
        if (l_enable_mcd_m)
        {
            l_m_cover.enabled = true;
            l_m_cover.base_addr = l_m_ranges[0].base_addr;

            for (uint8_t jj = 0; jj < l_m_ranges.size(); jj++)
            {
                if (l_m_ranges[jj].enabled)
                {
                    // ensure power of two alignment
                    if (!l_m_ranges[jj].is_power_of_2())
                    {
                        l_m_ranges[jj].round_next_power_of_2();
                    }

                    i_chip_info.ranges.push_back(l_m_ranges[jj]);
                    i_chip_info.ranges.back().print();
                }

                // need to cover size of largest alias
                if (l_m_cover.size < l_m_ranges[jj].size)
                {
                    l_m_cover.size = l_m_ranges[jj].size;
                }
            }

            // configure MCD to track this range via MCD_TOP
            FAPI_TRY(p9_setup_bars_mcd_track_range(i_target,
                                                   l_m_cover,
                                                   PU_MCD1_BANK0_MCD_TOP,
                                                   PU_BANK0_MCD_TOP),
                     "Error from p9_setup_bars_mcd_track_range (M)");
        }
    }

    // if configured above to track any NM or M space, perform the remainder
    // of the MCD setup (FIR configuration, probe enablement)
    if (l_enable_mcd_nm || l_enable_mcd_m)
    {
        FAPI_TRY(p9_setup_bars_mcd_enable(i_target,
                                          i_target_sys,
                                          i_chip_info),
                 "Error from p9_setup_bars_mcd_enable");
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
                  p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_FSP_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_FSP_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_fsp_range;
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

        l_fsp_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_fsp_range.size = (l_bar_offset_mask + 1) & FSP_BAR_SIZE_ATTR_MASK;
        l_fsp_range.enabled = true;
        i_chip_info.ranges.push_back(l_fsp_range);
        i_chip_info.ranges.back().print();
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
                  p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PSI_BRIDGE_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_psi_range;
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

        l_psi_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_psi_range.size = P9_SETUP_BARS_SIZE_1_MB;
        l_psi_range.enabled = true;
        i_chip_info.ranges.push_back(l_psi_range);
        i_chip_info.ranges.back().print();
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
                  p9_setup_bars_chip_info& i_chip_info)

{
    FAPI_DBG("Start");

    uint8_t l_use_ndd1_addresses;
    fapi2::buffer<uint16_t> l_pg_value = 0xFFFF;

    // Check to see if NPU is valid in PG (N3 chiplet)
    for (auto l_tgt : i_target.getChildren<fapi2::TARGET_TYPE_PERV>
         (fapi2::TARGET_FILTER_NEST_WEST, fapi2::TARGET_STATE_FUNCTIONAL))
    {
        uint8_t l_attr_chip_unit_pos = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_tgt, l_attr_chip_unit_pos));

        if (l_attr_chip_unit_pos == N3_CHIPLET_ID )
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_tgt, l_pg_value));
            break;
        }
    }

    // Bit7 == 1 means NPU is not good, so skip initialization
    if (l_pg_value.getBit<7>())
    {
        FAPI_DBG("Skipping NPU initialization");
        goto fapi_try_exit;
    }

    // NPU BAR SCOM addresses changed after Nimbus DD1, determine if this
    // invocation needs to use the NDD1 addreses or NDD2+ addresses
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR,
                           i_target,
                           l_use_ndd1_addresses),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR)");

    // PHY0
    {
        fapi2::ATTR_PROC_NPU_PHY0_BAR_ENABLE_Type l_phy0_enable;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_PHY0_BAR_ENABLE, i_target, l_phy0_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_PHY0_BAR_ENABLE)");

        if (l_phy0_enable == fapi2::ENUM_ATTR_PROC_NPU_PHY0_BAR_ENABLE_ENABLE)
        {
            p9_setup_bars_addr_range l_phy0_range;
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
                        "NPU PHY0 BAR offset attribute is not aligned to HW implementation");

            l_phy0_bar &= NPU_BAR_BASE_ADDR_MASK;
            l_phy0_bar += l_phy0_offset;
            l_phy0_bar = l_phy0_bar << NPU_BAR_ADDR_SHIFT;
            l_phy0_bar.setBit<PU_NPU0_SM0_PHY_BAR_CONFIG_ENABLE>();

            for (uint8_t ll = 0; ll < NPU_NUM_BAR_SHADOWS; ll++)
            {
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_PHY0_BAR_REGS_NDD1[ll]) :
                                  (NPU_PHY0_BAR_REGS[ll]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, l_phy0_bar),
                         "Error from putScom (0x08X)", l_addr);
            }

            l_phy0_range.base_addr = i_chip_info.base_address_mmio + l_phy0_offset;
            l_phy0_range.size = P9_SETUP_BARS_SIZE_2_MB;
            l_phy0_range.enabled = true;
            i_chip_info.ranges.push_back(l_phy0_range);
            i_chip_info.ranges.back().print();
        }
        else
        {
            for (uint8_t i = 0; i < NPU_NUM_BAR_SHADOWS; i++)
            {
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_PHY0_BAR_REGS_NDD1[i]) :
                                  (NPU_PHY0_BAR_REGS[i]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, 0x0000000000000000),
                         "Error from putScom (0x08X)", l_addr);
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
            p9_setup_bars_addr_range l_phy1_range;
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
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_PHY1_BAR_REGS_NDD1[ll]) :
                                  (NPU_PHY1_BAR_REGS[ll]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, l_phy1_bar),
                         "Error from putScom (0x08X)", l_addr);
            }

            l_phy1_range.base_addr = i_chip_info.base_address_mmio + l_phy1_offset;
            l_phy1_range.size = P9_SETUP_BARS_SIZE_2_MB;
            l_phy1_range.enabled = true;
            i_chip_info.ranges.push_back(l_phy1_range);
            i_chip_info.ranges.back().print();
        }
        else
        {
            for (uint8_t i = 0; i < NPU_NUM_BAR_SHADOWS; i++)
            {
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_PHY1_BAR_REGS_NDD1[i]) :
                                  (NPU_PHY1_BAR_REGS[i]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, 0x0000000000000000),
                         "Error from putScom (0x08X)", l_addr);
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
            p9_setup_bars_addr_range l_mmio_range;
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
                        "NPU MMIO BAR offset attribute is not aligned to HW implementation");

            l_mmio_bar &= NPU_BAR_BASE_ADDR_MASK;
            l_mmio_bar += l_mmio_offset;
            l_mmio_bar = l_mmio_bar << NPU_BAR_ADDR_SHIFT;
            l_mmio_bar.setBit<PU_NPU0_SM0_PHY_BAR_CONFIG_ENABLE>();

            for (uint8_t ll = 0; ll < NPU_NUM_BAR_SHADOWS; ll++)
            {
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_MMIO_BAR_REGS_NDD1[ll]) :
                                  (NPU_MMIO_BAR_REGS[ll]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, l_mmio_bar),
                         "Error from putScom (0x08X)", l_addr);
            }

            l_mmio_range.base_addr = i_chip_info.base_address_mmio + l_mmio_offset;
            l_mmio_range.size = P9_SETUP_BARS_SIZE_16_MB;
            l_mmio_range.enabled = true;
            i_chip_info.ranges.push_back(l_mmio_range);
            i_chip_info.ranges.back().print();
        }
        else
        {
            for (uint8_t i = 0; i < NPU_NUM_BAR_SHADOWS; i++)
            {
                uint64_t l_addr = (l_use_ndd1_addresses) ?
                                  (NPU_MMIO_BAR_REGS_NDD1[i]) :
                                  (NPU_MMIO_BAR_REGS[i]);

                FAPI_TRY(fapi2::putScom(i_target, l_addr, 0x0000000000000000),
                         "Error from putScom (0x08X)", l_addr);
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
                  p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    // PC BAR
    fapi2::ATTR_PROC_INT_CQ_PC_BAR_ENABLE_Type l_pc_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_PC_BAR_ENABLE, i_target, l_pc_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_PC_BAR_ENABLE)");

    if (l_pc_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_PC_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_pc_bar_range;
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
                    fapi2::P9_SETUP_BARS_INT_PC_BAR_ATTR_ERR()
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

        l_pc_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_pc_bar_range.size = (l_bar_mask_inverted & INT_PC_BAR_SIZE_ATTR_MASK) + 1;
        l_pc_bar_range.enabled = true;
        i_chip_info.ranges.push_back(l_pc_bar_range);
        i_chip_info.ranges.back().print();
    }

    // VC_BAR
    fapi2::ATTR_PROC_INT_CQ_VC_BAR_ENABLE_Type l_vc_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_VC_BAR_ENABLE, i_target, l_vc_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_VC_BAR_ENABLE)");

    if (l_vc_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_VC_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_vc_bar_range;
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
                    fapi2::P9_SETUP_BARS_INT_VC_BAR_ATTR_ERR()
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

        l_vc_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_vc_bar_range.size = (l_bar_mask_inverted & INT_VC_BAR_SIZE_ATTR_MASK) + 1;
        l_vc_bar_range.enabled = true;
        i_chip_info.ranges.push_back(l_vc_bar_range);
        i_chip_info.ranges.back().print();
    }

    // TM1 BAR
    fapi2::ATTR_PROC_INT_CQ_TM1_BAR_ENABLE_Type l_tm1_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_TM1_BAR_ENABLE, i_target, l_tm1_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_TM1_BAR_ENABLE)");

    if (l_tm1_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_tm1_bar_range;
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

        l_bar_offset_mask = ((l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE_64K) ?
                             (P9_SETUP_BARS_OFFSET_MASK_256_KB) :
                             (P9_SETUP_BARS_OFFSET_MASK_16_KB));

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P9_SETUP_BARS_INT_TM1_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT_CQ_TM1_BAR attributes are not aligned to HW implementation");

        // form INT CQ TM1 BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_TM1_BAR_VALID>();

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE_64K)
        {
            l_bar.setBit(PU_INT_CQ_TM1_BAR_PAGE_SIZE_64K);
        }

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_TM1_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_TM1_BAR)");

        l_tm1_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_tm1_bar_range.size = (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_TM1_BAR_PAGE_SIZE_64K) ?
                               (P9_SETUP_BARS_SIZE_256_KB) :
                               (P9_SETUP_BARS_SIZE_16_KB);
        l_tm1_bar_range.enabled = true;
        i_chip_info.ranges.push_back(l_tm1_bar_range);
        i_chip_info.ranges.back().print();
    }

    // IC BAR
    fapi2::ATTR_PROC_INT_CQ_IC_BAR_ENABLE_Type l_ic_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_CQ_IC_BAR_ENABLE, i_target, l_ic_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_CQ_IC_BAR_ENABLE)");

    if (l_ic_bar_enable == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_ENABLE_ENABLE)
    {
        p9_setup_bars_addr_range l_ic_bar_range;
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

        l_bar_offset_mask = ((l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE_64K) ?
                             (P9_SETUP_BARS_OFFSET_MASK_64_KB) :
                             (P9_SETUP_BARS_OFFSET_MASK_4_KB));

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P9_SETUP_BARS_INT_IC_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT_CQ_IC_BAR attributes are not aligned to HW implementation");

        // form INT CQ IC BAR scom register format
        l_bar += l_bar_offset;
        l_bar.setBit<PU_INT_CQ_IC_BAR_VALID>();

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE_64K)
        {
            l_bar.setBit(PU_INT_CQ_IC_BAR_PAGE_SIZE_64K);
        }

        // write to bar register
        FAPI_TRY(fapi2::putScom(i_target, PU_INT_CQ_IC_BAR, l_bar),
                 "Error from putScom (PU_INT_CQ_IC_BAR)");

        l_ic_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_ic_bar_range.size = (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_CQ_IC_BAR_PAGE_SIZE_64K) ?
                              (P9_SETUP_BARS_SIZE_256_KB) :
                              (P9_SETUP_BARS_SIZE_16_KB);
        l_ic_bar_range.enabled = true;
        i_chip_info.ranges.push_back(l_ic_bar_range);
        i_chip_info.ranges.back().print();
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Checking for overlap between memory/MMIO address ranges
///
/// @param[in] i_target Processor chip target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p9_setup_bars_check_overlap(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                            const p9_setup_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    if (i_chip_info.ranges.size() > 1)
    {
        for (size_t ii = 0; ii < i_chip_info.ranges.size() - 1; ii++)
        {
            for (size_t jj = ii + 1; jj < i_chip_info.ranges.size(); jj++)
            {
                FAPI_ASSERT(!i_chip_info.ranges[ii].overlaps(i_chip_info.ranges[jj]),
                            fapi2::P9_SETUP_BARS_RANGE_OVERLAP_ERR()
                            .set_TARGET(i_target)
                            .set_BASE_ADDR1(i_chip_info.ranges[ii].base_addr)
                            .set_END_ADDR1(i_chip_info.ranges[ii].end_addr())
                            .set_ENABLED1(i_chip_info.ranges[ii].enabled)
                            .set_BASE_ADDR2(i_chip_info.ranges[jj].base_addr)
                            .set_END_ADDR2(i_chip_info.ranges[jj].end_addr())
                            .set_ENABLED2(i_chip_info.ranges[jj].enabled),
                            "Overlapping address regions detected!");
            }
        }
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
    FAPI_TRY(p9_setup_bars_npu(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_npu");

    // MCD
    if (!l_chip_info.hw423589_option1)
    {
        if (l_chip_info.extended_addressing_mode && l_chip_info.hw423589_option2)
        {
            FAPI_TRY(p9_setup_bars_mcd_HW423589_OPTION2(i_target,
                     FAPI_SYSTEM,
                     l_chip_info),
                     "Error from p9_setup_bars_mcd_HW423589_OPTION2");
        }
        else
        {
            FAPI_TRY(p9_setup_bars_mcd(i_target, FAPI_SYSTEM, l_chip_info),
                     "Error from p9_setup_bars_mcd");
        }
    }
    else
    {
        // mask MCD FIRs
        fapi2::buffer<uint64_t> l_fir_data;
        l_fir_data.flush<1>();
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD_FIR_MASK_REG, l_fir_data),
                 "Error from putScom (PU_MCD_FIR_MASK_REG)");
        FAPI_TRY(fapi2::putScom(i_target, PU_MCD1_MCD_FIR_MASK_REG, l_fir_data),
                 "Error from putScom (PU_MCD1_MCD_FIR_MASK_REG)");
    }

    // INT
    FAPI_TRY(p9_setup_bars_int(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p9_setup_bars_int");

    // now that all ranges have been configured, perform
    // check for any overlap between ranges
    FAPI_TRY(p9_setup_bars_check_overlap(i_target,
                                         l_chip_info),
             "Error from p9_setup_bars_check_overlap");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}

