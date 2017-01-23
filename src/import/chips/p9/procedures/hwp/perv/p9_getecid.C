/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_getecid.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
/// @file  p9_getecid.C
///
/// @brief Get ECID string from target using SCOM
//------------------------------------------------------------------------------
// *HWP HW Owner        : Abhishek Agarwal <abagarw8@in.ibm.com>
// *HWP HW Backup Owner : Srinivas V Naga <srinivan@in.ibm.com>
// *HWP FW Owner        : sunil kumar <skumar8j@in.ibm.com>
// *HWP Team            : Perv
// *HWP Level           : 2
// *HWP Consumed by     : SBE
//------------------------------------------------------------------------------


#include "p9_getecid.H"

#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_const_common.H>

// The bit locations in ecid_part02 where the DD Level is found. These correspond to ECID bits 173:175
constexpr uint64_t DD_LEVEL(45);
constexpr uint64_t DD_LEVEL_LEN(3);

static fapi2::ReturnCode setup_pcie_work_around_attributes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_ecid_part)
{
    uint8_t l_version = 0;
    i_ecid_part.extractToRight<DD_LEVEL, DD_LEVEL_LEN>(l_version);

    {
        // Workarounds for DD1.00 modulues
        fapi2::ATTR_CHIP_EC_FEATURE_PCIE_LOCK_PHASE_ROTATOR_Type l_ec_feature_pcie_lock_phase_rotator = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PCIE_LOCK_PHASE_ROTATOR, i_target,
                               l_ec_feature_pcie_lock_phase_rotator),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_PCIE_LOCK_PHASE_ROTATOR)");

        if (l_ec_feature_pcie_lock_phase_rotator && (l_version < ddLevelPciePart))
        {
            FAPI_DBG("seeing version 1.00 (0x%x) setting attributes", l_version);
            uint8_t l_value = 1;

            for (auto& l_pec_trgt : i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL))
            {
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_PCIE_PCS_RX_ROT_EXTEL, l_pec_trgt, l_value),
                         "Error from FAPI_ATTR_SET (ATTR_PROC_PCIE_PCS_RX_ROT_EXTEL)");
            }
        }
    }
    {
        // Workarounds for DD1.01/DD1.02 modules
        fapi2::ATTR_CHIP_EC_FEATURE_PCIE_DISABLE_FDDC_Type l_ec_feature_pcie_disable_fddc = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PCIE_DISABLE_FDDC, i_target, l_ec_feature_pcie_disable_fddc),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_PCIE_DISABLE_FDDC)");

        if (l_ec_feature_pcie_disable_fddc && (l_version >= ddLevelPciePart))
        {
            FAPI_DBG("seeing version >= 1.01 (0x%x) setting attributes", l_version);
            uint8_t l_value = 0;

            for (auto& l_pec_trgt : i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL))
            {
                FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PROC_PCIE_PCS_RX_DFE_FDDC, l_pec_trgt, l_value),
                         "Error from FAPI_ATTR_SET (ATTR_PROC_PCIE_PCS_RX_DFE_FDDC)");
            }
        }
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

static fapi2::ReturnCode setup_memory_work_around_attributes(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const fapi2::buffer<uint64_t>& i_ecid_part)
{
    uint8_t l_version = 0;
    i_ecid_part.extractToRight<DD_LEVEL, DD_LEVEL_LEN>(l_version);

    // Workarounds for modules which are before 1.02 (memory part 1)
    if (l_version < ddLevelMemoryPart1)
    {
        FAPI_DBG("seeing version < 1.02 (0x%x) setting attributes", l_version);

        // All these attributes have 1 as their 'YES' enum value
        uint8_t l_value = 1;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DO_MSS_WR_VREF, i_target, l_value) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DO_MSS_VREF_DAC, i_target, l_value) );
    }

    // Workarounds for modules which are before 1.03 (memory part 2)
    if (l_version < ddLevelMemoryPart2)
    {
        FAPI_DBG("seeing version < 1.03 (0x%x) setting attributes", l_version);

        // All these attributes have 1 as their 'YES' enum value
        uint8_t l_value = 1;
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DO_MSS_TRAINING_BAD_BITS, i_target, l_value) );
        FAPI_TRY( FAPI_ATTR_SET(fapi2::ATTR_DO_BLUE_WATERFALL_ADJUST, i_target, l_value) );
    }

    return fapi2::FAPI2_RC_SUCCESS;

fapi_try_exit:
    return fapi2::current_err;
}

fapi2::ReturnCode p9_getecid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                             fapi2::variable_buffer& o_fuseString)
{
    uint64_t attr_data[2];
    fapi2::buffer<uint64_t> l_ecid_part0_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part1_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part2_data64 = 0;
    fapi2::variable_buffer l_fuseString(fuseString_len);
    FAPI_INF("Entering ...");


    FAPI_DBG("extract and manipulate ECID data");
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART0_REGISTER, l_ecid_part0_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART1_REGISTER, l_ecid_part1_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART2_REGISTER, l_ecid_part2_data64));

    l_ecid_part0_data64.reverse();
    l_ecid_part1_data64.reverse();
    l_ecid_part2_data64.reverse();

    attr_data[0] = l_ecid_part0_data64();
    attr_data[1] = l_ecid_part1_data64();

    FAPI_TRY(l_fuseString.insert(l_ecid_part0_data64(), 0, 64));

    FAPI_TRY(l_fuseString.insert(l_ecid_part1_data64(), 64, 64));

    FAPI_TRY(l_fuseString.insert(l_ecid_part2_data64(), 128, 48));

    o_fuseString = l_fuseString;

    FAPI_DBG("push fuse string into attribute");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target_chip, attr_data));

    // Set some attributes memory can used to make work-around decisions.
    FAPI_TRY( setup_memory_work_around_attributes(i_target_chip, l_ecid_part2_data64) );
    FAPI_TRY( setup_pcie_work_around_attributes(i_target_chip, l_ecid_part2_data64) );

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
