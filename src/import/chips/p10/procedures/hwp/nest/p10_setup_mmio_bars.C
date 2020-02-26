/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_setup_mmio_bars.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file p10_setup_mmio_bars.C
/// @brief Configure nest unit MMIO base address registers (FAPI2)
///

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <p10_setup_mmio_bars.H>
#include <p10_setup_bars_defs.H>
#include <p10_fbc_utils.H>

#include <p10_scom_proc.H>
#include <p10_scom_pau.H>

//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

// structure to represent chip configuration information
struct p10_setup_mmio_bars_chip_info
{
    uint64_t base_address_mmio;
    std::vector<p10_setup_bars_addr_range> ranges;
};


//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

// FSP
const uint64_t FSP_BAR_SIZE_ATTR_MASK = 0x00000000FFFFFFFFULL;
const uint64_t FSP_BAR_SHIFT = 20;
const uint64_t FSP_MMR_SHIFT = 20;
const uint64_t PSI_BAR_SHIFT = 20;

// PAU
const uint64_t PAU_BAR_MASK = 0x0001FFFFFFFFFFFFULL;
const uint64_t PAU_BAR_SHIFT = 24;

// INT
const uint64_t INT_IC_BAR_SHIFT = 21;
const uint64_t INT_TM_BAR_SHIFT = 14;
const uint64_t INT_NVC_BAR_SHIFT = 24;
const uint64_t INT_NVPG_BAR_SHIFT = 24;


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
p10_setup_mmio_bars_build_chip_info(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                    p10_setup_mmio_bars_chip_info& io_chip_info)
{
    FAPI_DBG("Start");

    uint64_t l_base_address_nm0_unused = 0;
    uint64_t l_base_address_nm1_unused = 0;
    uint64_t l_base_address_m_unused   = 0;

    FAPI_TRY(p10_fbc_utils_get_chip_base_address(
                 i_target,
                 EFF_TOPOLOGY_ID,
                 l_base_address_nm0_unused,
                 l_base_address_nm1_unused,
                 l_base_address_m_unused,
                 io_chip_info.base_address_mmio),
             "Error from p10_fbc_utils_get_chip_base_address");

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
p10_setup_mmio_bars_fsp(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                        p10_setup_mmio_bars_chip_info& i_chip_info)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_FSP_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_FSP_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_fsp_range;
        fapi2::ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_FSP_BAR_SIZE_Type l_bar_offset_mask;
        fapi2::ATTR_PROC_FSP_MMIO_MASK_SIZE_Type l_mmio_mask_size;
        fapi2::buffer<uint64_t> l_fsp_bar;
        fapi2::buffer<uint64_t> l_fsp_mmr;
        fapi2::buffer<uint64_t> l_status_ctl;

        // retrieve BAR offset/size
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_BASE_ADDR_OFFSET)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_BAR_SIZE, i_target_sys, l_bar_offset_mask),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_BAR_SIZE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FSP_MMIO_MASK_SIZE, i_target_sys, l_mmio_mask_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_FSP_MMIO_MASK_SIZE)");

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_FSP_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "FSP BAR attributes are not aligned to HW implementation");

        // form FSP BAR SCOM register format
        FAPI_TRY(PREP_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(i_target));
        FAPI_TRY(GET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(i_target, l_fsp_bar));
        SET_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG_FSP_BAR((i_chip_info.base_address_mmio | l_bar_offset) >> FSP_BAR_SHIFT,
                l_fsp_bar);
        FAPI_TRY(PUT_TP_TPBR_PSIHB_PSI_BRIDGE_FSP_BAR_REG(i_target, l_fsp_bar));

        // form FSP BAR mask SCOM register format
        FAPI_TRY(PREP_TP_TPBR_PSIHB_PSI_FSP_MMR_REG(i_target));
        FAPI_TRY(GET_TP_TPBR_PSIHB_PSI_FSP_MMR_REG(i_target, l_fsp_mmr));
        SET_TP_TPBR_PSIHB_PSI_FSP_MMR_REG_FSP_MMR((~l_bar_offset_mask) >> FSP_MMR_SHIFT, l_fsp_mmr);
        FAPI_TRY(PUT_TP_TPBR_PSIHB_PSI_FSP_MMR_REG(i_target, l_fsp_mmr));

        // form PSI Host Bridge Control/Status SCOM register format
        FAPI_TRY(PREP_TP_TPBR_PSIHB_STATUS_CTL_REG(i_target));
        FAPI_TRY(GET_TP_TPBR_PSIHB_STATUS_CTL_REG(i_target, l_status_ctl));
        SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_MASK(l_mmio_mask_size, l_status_ctl);
        SET_TP_TPBR_PSIHB_STATUS_CTL_REG_FSP_MMIO_ENABLE(l_status_ctl);
        FAPI_TRY(PUT_TP_TPBR_PSIHB_STATUS_CTL_REG(i_target, l_status_ctl));

        l_fsp_range.base_addr = l_fsp_bar();
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
p10_setup_mmio_bars_psi(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                        p10_setup_mmio_bars_chip_info& i_chip_info)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    // retrieve BAR enable
    fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_Type l_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PSI_BRIDGE_BAR_ENABLE, i_target, l_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PSI_BRIDGE_BAR_ENABLE)");

    if (l_bar_enable == fapi2::ENUM_ATTR_PROC_PSI_BRIDGE_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_psi_range;
        fapi2::ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::buffer<uint64_t> l_bar;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PSI_BRIDGE_BAR_BASE_ADDR_OFFSET)");

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & P10_SETUP_BARS_OFFSET_MASK_1_MB) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_PSI_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(P10_SETUP_BARS_OFFSET_MASK_1_MB)
                    .set_BAR_OVERLAP(l_bar_offset & P10_SETUP_BARS_OFFSET_MASK_1_MB),
                    "PSI BAR attributes are not aligned to HW implementation");

        // form PSI BAR SCOM register format
        FAPI_TRY(PREP_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(i_target));
        SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR((i_chip_info.base_address_mmio | l_bar_offset) >>
                PSI_BAR_SHIFT, l_bar);
        SET_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG_PSI_BRIDGE_BAR_EN(l_bar);
        FAPI_TRY(PUT_TP_TPBR_PSIHB_PSI_BRIDGE_BAR_REG(i_target, l_bar));

        l_psi_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_psi_range.size = P10_SETUP_BARS_SIZE_1_MB;
        l_psi_range.enabled = true;

        i_chip_info.ranges.push_back(l_psi_range);
        i_chip_info.ranges.back().print();
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure PAU MMIO access
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p10_setup_mmio_bars_pau(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                        p10_setup_mmio_bars_chip_info& i_chip_info)

{
    using namespace scomt;
    using namespace scomt::pau;

    FAPI_DBG("Start");

    // array of per-PAU offsets, indexed by PAU unit number
    fapi2::ATTR_PROC_PAU_MMIO_BAR_BASE_ADDR_OFFSET_Type l_mmio_offsets;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PAU_MMIO_BAR_BASE_ADDR_OFFSET, i_target_sys, l_mmio_offsets),
             "Error from FAPI_ATTR_GET (ATTR_PROC_PAU_MMIO_BAR_BASE_ADDR_OFFSET)");

    for (const auto& l_pau_target : i_target.getChildren<fapi2::TARGET_TYPE_PAU>())
    {
        fapi2::ATTR_PROC_PAU_MMIO_BAR_ENABLE_Type l_mmio_enable;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_unit_pos;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_PAU_MMIO_BAR_ENABLE, l_pau_target, l_mmio_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_PAU_MMIO_BAR_ENABLE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_pau_target, l_unit_pos),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS)");

        if (l_mmio_enable == fapi2::ENUM_ATTR_PROC_PAU_MMIO_BAR_ENABLE_ENABLE)
        {
            p10_setup_bars_addr_range l_mmio_range;
            fapi2::buffer<uint64_t> l_mmio_bar;
            fapi2::buffer<uint64_t> l_mmio_offset = l_mmio_offsets[l_unit_pos];

            FAPI_ASSERT(((l_mmio_offset & ~FABRIC_ADDR_SMF_MASK) &
                         P10_SETUP_BARS_OFFSET_MASK_16_MB) == 0,
                        fapi2::P10_SETUP_MMIO_BARS_PAU_MMIO_BAR_ATTR_ERR()
                        .set_TARGET(i_target)
                        .set_BAR_OFFSET(l_mmio_offset)
                        .set_BAR_OFFSET_MASK(P10_SETUP_BARS_OFFSET_MASK_16_MB)
                        .set_BAR_OVERLAP(l_mmio_offset &
                                         P10_SETUP_BARS_OFFSET_MASK_16_MB),
                        "PAU MMIO BAR offset attribute is not aligned to HW implementation");

            FAPI_TRY(PREP_CS_SM0_SNP_MISC_PAUMMIO_BAR(l_pau_target));
            SET_CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ENABLE(l_mmio_bar);
            SET_CS_SM0_SNP_MISC_PAUMMIO_BAR_CONFIG_PAUMMIO_BAR_ADDR(
                ((i_chip_info.base_address_mmio & PAU_BAR_MASK) |
                 l_mmio_offset) >> PAU_BAR_SHIFT, l_mmio_bar);

            FAPI_TRY(PUT_CS_SM0_SNP_MISC_PAUMMIO_BAR(l_pau_target, l_mmio_bar));

            // shadow value to all copies of BAR
            FAPI_TRY(PREP_CS_SM1_SNP_MISC_PAUMMIO_BAR(l_pau_target));
            FAPI_TRY(PUT_CS_SM1_SNP_MISC_PAUMMIO_BAR(l_pau_target, l_mmio_bar));

            FAPI_TRY(PREP_CS_SM2_SNP_MISC_PAUMMIO_BAR(l_pau_target));
            FAPI_TRY(PUT_CS_SM2_SNP_MISC_PAUMMIO_BAR(l_pau_target, l_mmio_bar));

            FAPI_TRY(PREP_CS_SM3_SNP_MISC_PAUMMIO_BAR(l_pau_target));
            FAPI_TRY(PUT_CS_SM3_SNP_MISC_PAUMMIO_BAR(l_pau_target, l_mmio_bar));

            l_mmio_range.base_addr = i_chip_info.base_address_mmio + l_mmio_offset;
            l_mmio_range.size = P10_SETUP_BARS_SIZE_16_MB;
            l_mmio_range.enabled = true;

            i_chip_info.ranges.push_back(l_mmio_range);
            i_chip_info.ranges.back().print();
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


/// @brief Configure INT MMIO access (Cronus only)
///
/// @param[in] i_target Processor chip target
/// @param[in] i_target_sys System target
/// @param[in] i_chip_info Structure describing chip properties/base addresses
///
/// @return FAPI_RC_SUCCESS if all calls are successful, else error
fapi2::ReturnCode
p10_setup_mmio_bars_int(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
                        p10_setup_mmio_bars_chip_info& i_chip_info)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_DBG("Start");

    // IC BAR
    fapi2::ATTR_PROC_INT_IC_BAR_ENABLE_Type l_ic_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_IC_BAR_ENABLE, i_target, l_ic_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_IC_BAR_ENABLE)");

    if (l_ic_bar_enable == fapi2::ENUM_ATTR_PROC_INT_IC_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_ic_bar_range;
        fapi2::ATTR_PROC_INT_IC_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_IC_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::buffer<uint64_t> l_bar = 0;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_IC_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_IC_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR page size (4KB or 64KB)
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_IC_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_IC_BAR_PAGE_SIZE)");

        // fixed size of 512 pages (4KB * 512 = 2MB or 64KB * 512 = 32MB)
        l_bar_offset_mask = ((l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_IC_BAR_PAGE_SIZE_64K) ?
                             (P10_SETUP_BARS_OFFSET_MASK_32_MB) :
                             (P10_SETUP_BARS_OFFSET_MASK_2_MB));

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_INT_IC_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT IC BAR attributes are not aligned to HW implementation");

        // form INT IC BAR scom register format
        FAPI_TRY(PREP_INT_CQ_IC_BAR(i_target));
        SET_INT_CQ_IC_BAR_VALID(l_bar);
        SET_INT_CQ_IC_BAR_ADDR_8_42((i_chip_info.base_address_mmio |
                                     l_bar_offset) >> INT_IC_BAR_SHIFT, l_bar);

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_IC_BAR_PAGE_SIZE_64K)
        {
            SET_INT_CQ_IC_BAR_PAGE_SIZE_64K(l_bar);
        }

        FAPI_TRY(PUT_INT_CQ_IC_BAR(i_target, l_bar));

        l_ic_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_ic_bar_range.size = (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_IC_BAR_PAGE_SIZE_64K) ?
                              (P10_SETUP_BARS_SIZE_32_MB) :
                              (P10_SETUP_BARS_SIZE_2_MB);
        l_ic_bar_range.enabled = true;

        i_chip_info.ranges.push_back(l_ic_bar_range);
        i_chip_info.ranges.back().print();
    }

    // TM BAR
    fapi2::ATTR_PROC_INT_TM_BAR_ENABLE_Type l_tm_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_TM_BAR_ENABLE, i_target, l_tm_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_TM_BAR_ENABLE)");

    if (l_tm_bar_enable == fapi2::ENUM_ATTR_PROC_INT_TM_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_tm_bar_range;
        fapi2::ATTR_PROC_INT_TM_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_TM_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::buffer<uint64_t> l_bar = 0;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_TM_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_TM_BAR_BASE_ADDR_OFFSET)");

        // retrieve BAR page size
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_TM_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_TM_BAR_PAGE_SIZE)");

        // fixed size of 4 pages (4KB * 4 = 16KB or 64KB * 4 = 256KB)
        l_bar_offset_mask = ((l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_TM_BAR_PAGE_SIZE_64K) ?
                             (P10_SETUP_BARS_OFFSET_MASK_256_KB) :
                             (P10_SETUP_BARS_OFFSET_MASK_16_KB));

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_INT_TM_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT TM BAR attributes are not aligned to HW implementation");

        // form INT TM BAR scom register format
        FAPI_TRY(PREP_INT_CQ_TM_BAR(i_target));
        SET_INT_CQ_TM_BAR_VALID(l_bar);
        SET_INT_CQ_TM_BAR_ADDR_8_49((i_chip_info.base_address_mmio |
                                     l_bar_offset) >> INT_TM_BAR_SHIFT, l_bar);

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_TM_BAR_PAGE_SIZE_64K)
        {
            SET_INT_CQ_TM_BAR_PAGE_SIZE_64K(l_bar);
        }

        FAPI_TRY(PUT_INT_CQ_TM_BAR(i_target, l_bar));

        l_tm_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_tm_bar_range.size = (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_TM_BAR_PAGE_SIZE_64K) ?
                              (P10_SETUP_BARS_SIZE_256_KB) :
                              (P10_SETUP_BARS_SIZE_16_KB);
        l_tm_bar_range.enabled = true;

        i_chip_info.ranges.push_back(l_tm_bar_range);
        i_chip_info.ranges.back().print();
    }

    // NVPG_BAR
    fapi2::ATTR_PROC_INT_NVPG_BAR_ENABLE_Type l_nvpg_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVPG_BAR_ENABLE, i_target, l_nvpg_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVPG_BAR_ENABLE)");

    if (l_nvpg_bar_enable == fapi2::ENUM_ATTR_PROC_INT_NVPG_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_nvpg_bar_range;
        fapi2::ATTR_PROC_INT_NVPG_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_NVPG_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::ATTR_PROC_INT_NVPG_BAR_SET_DIVISION_SELECTOR_Type l_bar_set_division_selector;
        fapi2::ATTR_PROC_INT_NVPG_BAR_RANGE_Type l_bar_range;
        fapi2::buffer<uint64_t> l_bar;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVPG_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVPG_BAR_BASE_ADDR_OFFSET)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVPG_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVPG_BAR_PAGE_SIZE)");

        // retrieve BAR set division selector
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVPG_BAR_SET_DIVISION_SELECTOR, i_target_sys, l_bar_set_division_selector),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVPG_BAR_SET_DIVISION_SELECTOR)");

        // retrieve BAR range selector
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVPG_BAR_RANGE, i_target_sys, l_bar_range),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVPG_BAR_RANGE)");

        l_bar_offset_mask = p10_setup_bars_bar_offset_masks[fapi2::ENUM_ATTR_PROC_INT_NVPG_BAR_RANGE_16_TB -
                            l_bar_range];

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_INT_NVPG_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT NVPG BAR attributes are not aligned to HW implementation");

        // form INT NVPG BAR scom register format
        FAPI_TRY(PREP_INT_CQ_NVPG_BAR(i_target));
        SET_INT_CQ_NVPG_BAR_VALID(l_bar);

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_NVPG_BAR_PAGE_SIZE_64K)
        {
            SET_INT_CQ_NVPG_BAR_PAGE_SIZE_64K(l_bar);
        }

        SET_INT_CQ_NVPG_BAR_SET_DIV_SEL_0_2(l_bar_set_division_selector, l_bar);
        SET_INT_CQ_NVPG_BAR_RANGE_0_4(l_bar_range, l_bar);
        SET_INT_CQ_NVPG_BAR_ADDR_8_39((i_chip_info.base_address_mmio |
                                       l_bar_offset) >> INT_NVPG_BAR_SHIFT, l_bar);
        FAPI_TRY(PUT_INT_CQ_NVPG_BAR(i_target, l_bar));

        l_nvpg_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_nvpg_bar_range.size = p10_setup_bars_bar_sizes[fapi2::ENUM_ATTR_PROC_INT_NVPG_BAR_RANGE_16_TB -
                                l_bar_range];
        l_nvpg_bar_range.enabled = true;

        i_chip_info.ranges.push_back(l_nvpg_bar_range);
        i_chip_info.ranges.back().print();
    }

    // NVC_BAR
    fapi2::ATTR_PROC_INT_NVC_BAR_ENABLE_Type l_nvc_bar_enable;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVC_BAR_ENABLE, i_target, l_nvc_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVC_BAR_ENABLE)");

    if (l_nvc_bar_enable == fapi2::ENUM_ATTR_PROC_INT_NVC_BAR_ENABLE_ENABLE)
    {
        p10_setup_bars_addr_range l_nvc_bar_range;
        fapi2::ATTR_PROC_INT_NVC_BAR_BASE_ADDR_OFFSET_Type l_bar_offset;
        fapi2::ATTR_PROC_INT_NVC_BAR_PAGE_SIZE_Type l_bar_page_size;
        fapi2::ATTR_PROC_INT_NVC_BAR_SET_DIVISION_SELECTOR_Type l_bar_set_division_selector;
        fapi2::ATTR_PROC_INT_NVC_BAR_RANGE_Type l_bar_range;
        fapi2::buffer<uint64_t> l_bar;
        fapi2::buffer<uint64_t> l_bar_offset_mask;

        // retrieve BAR offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVC_BAR_BASE_ADDR_OFFSET, i_target_sys, l_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVC_BAR_BASE_ADDR_OFFSET)");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVC_BAR_PAGE_SIZE, i_target_sys, l_bar_page_size),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVC_BAR_PAGE_SIZE)");

        // retrieve BAR set division selector
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVC_BAR_SET_DIVISION_SELECTOR, i_target_sys, l_bar_set_division_selector),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVC_BAR_SET_DIVISION_SELECTOR)");

        // retrieve BAR range selector
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_INT_NVC_BAR_RANGE, i_target_sys, l_bar_range),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_INT_NVC_BAR_RANGE)");

        l_bar_offset_mask = p10_setup_bars_bar_offset_masks[fapi2::ENUM_ATTR_PROC_INT_NVC_BAR_RANGE_16_TB -
                            l_bar_range];

        // check that BAR offset attribute is properly aligned
        FAPI_ASSERT((l_bar_offset & l_bar_offset_mask) == 0,
                    fapi2::P10_SETUP_MMIO_BARS_INT_NVC_BAR_ATTR_ERR()
                    .set_TARGET(i_target)
                    .set_BAR_OFFSET(l_bar_offset)
                    .set_BAR_OFFSET_MASK(l_bar_offset_mask)
                    .set_BAR_OVERLAP(l_bar_offset & l_bar_offset_mask),
                    "INT NVC BAR attributes are not aligned to HW implementation");

        // form INT NVC BAR scom register format
        FAPI_TRY(PREP_INT_CQ_NVC_BAR(i_target));
        SET_INT_CQ_NVC_BAR_VALID(l_bar);

        if (l_bar_page_size == fapi2::ENUM_ATTR_PROC_INT_NVC_BAR_PAGE_SIZE_64K)
        {
            SET_INT_CQ_NVC_BAR_PAGE_SIZE_64K(l_bar);
        }

        SET_INT_CQ_NVC_BAR_SET_DIV_SEL_0_2(l_bar_set_division_selector, l_bar);
        SET_INT_CQ_NVC_BAR_RANGE_0_4(l_bar_range, l_bar);
        SET_INT_CQ_NVC_BAR_ADDR_8_39((i_chip_info.base_address_mmio |
                                      l_bar_offset) >> INT_NVC_BAR_SHIFT, l_bar);
        FAPI_TRY(PUT_INT_CQ_NVC_BAR(i_target, l_bar));

        l_nvc_bar_range.base_addr = i_chip_info.base_address_mmio + l_bar_offset;
        l_nvc_bar_range.size = p10_setup_bars_bar_sizes[fapi2::ENUM_ATTR_PROC_INT_NVC_BAR_RANGE_16_TB -
                               l_bar_range];
        l_nvc_bar_range.enabled = true;

        i_chip_info.ranges.push_back(l_nvc_bar_range);
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
p10_setup_mmio_bars_check_overlap(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                                  const p10_setup_mmio_bars_chip_info& i_chip_info)
{
    FAPI_DBG("Start");

    if (i_chip_info.ranges.size() > 1)
    {
        for (size_t ii = 0; ii < i_chip_info.ranges.size() - 1; ii++)
        {
            for (size_t jj = ii + 1; jj < i_chip_info.ranges.size(); jj++)
            {
                FAPI_ASSERT(!i_chip_info.ranges[ii].overlaps(i_chip_info.ranges[jj]),
                            fapi2::P10_SETUP_MMIO_BARS_RANGE_OVERLAP_ERR()
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
p10_setup_mmio_bars(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");
    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    p10_setup_mmio_bars_chip_info l_chip_info;

    // process chip information
    FAPI_TRY(p10_setup_mmio_bars_build_chip_info(i_target,
             l_chip_info),
             "Error from p10_setup_mmio_bars_build_chip_info");

    // setup unit BARS
    // FSP
    FAPI_TRY(p10_setup_mmio_bars_fsp(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p10_setup_mmio_bars_fsp");
    // PSI
    FAPI_TRY(p10_setup_mmio_bars_psi(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p10_setup_mmio_bars_psi");
    // PAU
    FAPI_TRY(p10_setup_mmio_bars_pau(i_target, FAPI_SYSTEM, l_chip_info),
             "Error from p10_setup_mmio_bars_pau");

    // INT
    if (!fapi2::is_platform<fapi2::PLAT_HOSTBOOT>())
    {
        FAPI_TRY(p10_setup_mmio_bars_int(i_target, FAPI_SYSTEM, l_chip_info),
                 "Error from p10_setup_mmio_bars_int");
    }

    // now that all ranges have been configured, perform
    // check for any overlap between ranges
    FAPI_TRY(p10_setup_mmio_bars_check_overlap(i_target, l_chip_info),
             "Error from p10_setup_mmio_bars_check_overlap");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
