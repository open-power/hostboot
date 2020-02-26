/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_gen_xscom_init.C $ */
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
/// @file p10_gen_xscom_init.H
/// @brief Generate XSCOM init for specified SCOM address given data and
///        data valid mask.  Data bit positions with zero in corresponding
///        data valid mask bit positions will be sampled from HW via SCOM.

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by  : HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_gen_xscom_init.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address formation constants
static const uint64_t SCOM_TO_XSCOM_ADDR_MASK  = 0x000000007FFFFFFFULL;
static const uint64_t SCOM_TO_XSCOM_ADDR_SHIFT = 3;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_gen_xscom_init(
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
                    fapi2::P10_GEN_XSCOM_INIT_UNSUPPORTED_SCOM_ERR()
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
                        fapi2::P10_GEN_XSCOM_INIT_SCOM_XLATE_ERR()
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

        l_xscom_addr = l_base_address_mmio + l_xscom_bar_base_addr_offset;
        l_xscom_addr |= FABRIC_ADDR_SMF_MASK;

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
