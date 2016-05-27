/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_utils.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_fbc_utils.C
/// @brief Fabric library functions/constants (FAPI2)
///
/// The functions in this file provide:
/// - Information about the instantaneous state of the fabric
/// - Means to restart the fabric after a checkstop condition
/// - Determination of the chip's base address in the real address map
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE,HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_utils.H>
#include <p9_misc_scom_addresses.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// ADU PMisc Register field/bit definitions
const uint32_t ALTD_SND_MODE_DISABLE_CHECKSTOP_BIT = 19;
const uint32_t ALTD_SND_MODE_MANUAL_CLR_PB_STOP_BIT = 21;
const uint32_t ALTD_SND_MODE_PB_STOP_BIT = 22;

// FBC Mode Register field/bit definitions
const uint32_t PU_FBC_MODE_PB_INITIALIZED_BIT = 0;

// FBC base address determination constants
// system ID (large system)
const uint8_t FABRIC_ADDR_LS_SYSTEM_ID_START_BIT = 8;
const uint8_t FABRIC_ADDR_LS_SYSTEM_ID_END_BIT = 12;
// system ID (small system)
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD0_START_BIT = 8;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD0_END_BIT = 12;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD0_SHIFT = 5;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD0_MASK = 0x1F;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD1_START_BIT = 15;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD1_END_BIT = 16;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD1_SHIFT = 3;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD1_MASK = 0x3;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD2_START_BIT = 19;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD2_END_BIT = 21;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD2_SHIFT = 0;
const uint8_t FABRIC_ADDR_SS_SYSTEM_ID_FLD2_MASK = 0x7;
// group ID (large system)
const uint8_t FABRIC_ADDR_LS_GROUP_ID_START_BIT = 15;
const uint8_t FABRIC_ADDR_LS_GROUP_ID_END_BIT = 18;
// group ID (small system)
const uint8_t FABRIC_ADDR_SS_GROUP_ID_START_BIT = 17;
const uint8_t FABRIC_ADDR_SS_GROUP_ID_END_BIT = 18;
// chip ID (large system)
const uint8_t FABRIC_ADDR_LS_CHIP_ID_START_BIT = 19;
const uint8_t FABRIC_ADDR_LS_CHIP_ID_END_BIT = 21;
// msel bits (large & small system)
const uint8_t FABRIC_ADDR_MSEL_START_BIT = 13;
const uint8_t FABRIC_ADDR_MSEL_END_BIT = 14;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running)
{
    FAPI_DBG("Start");

    // TODO: HW328175
    // fapi2::buffer<uint64_t> l_fbc_mode_data;
    // FAPI_TRY(fapi2::getScom(i_target, PU_FBC_MODE_REG, l_fbc_mode_data),
    //          "Error reading FBC Mode Register");
    // // fabric is initialized if PB_INITIALIZED bit is one/set
    // o_is_initialized = l_fbc_mode_data.getBit<PU_FBC_MODE_PB_INITIALIZED_BIT>();

    // currently, sampling FBC init from PB Mode register is unreliable
    // as init can drop perodically at runtime (based on legacy sleep backoff)
    // until this issue is fixed, just return true to caller
    o_is_initialized = true;

    // read ADU PMisc Mode Register state
    fapi2::buffer<uint64_t> l_pmisc_mode_data;
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading ADU PMisc Mode register");

    // fabric is running if FBC_STOP bit is zero/clear
    o_is_running = !(l_pmisc_mode_data.getBit<ALTD_SND_MODE_PB_STOP_BIT>());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // read ADU PMisc Mode Register state
    fapi2::buffer<uint64_t> l_pmisc_mode_data;
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading ADU PMisc Mode register");

    // set bit to disable checkstop forwarding and write back
    l_pmisc_mode_data.setBit<ALTD_SND_MODE_DISABLE_CHECKSTOP_BIT>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error writing ADU PMisc Mode register to disable checkstop forwarding to FBC");

    // set bit to manually clear stop control and write back
    l_pmisc_mode_data.setBit<ALTD_SND_MODE_MANUAL_CLR_PB_STOP_BIT>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error writing ADU PMisc Mode register to manually clear FBC stop control");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


fapi2::ReturnCode p9_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio)
{
    uint32_t l_fabric_system_id;
    uint8_t l_fabric_group_id;
    uint8_t l_fabric_chip_id;
    uint8_t l_fabric_addr_bar_mode;
    uint8_t l_mirror_policy;
    fapi2::buffer<uint64_t> l_base_address;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;


    FAPI_DBG("Start");

    // retreive attributes which statically determine chip's position in memory map
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_ID, i_target, l_fabric_system_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_SYSTEM_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, i_target, l_fabric_group_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_GROUP_ID)");
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, i_target, l_fabric_chip_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_CHIP_ID)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_ADDR_BAR_MODE, FAPI_SYSTEM, l_fabric_addr_bar_mode),
             "Error from FAPI_ATTR_GET (ATTR_PROC_FABRIC_ADDR_BAR_MODE)");

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY, FAPI_SYSTEM, l_mirror_policy),
             "Error from FAPI_ATTR_GET (ATTR_MEM_MIRROR_PLACEMENT_POLICY)");

    // apply system ID
    // occupies one field for large system map, split into three fields for small system map
    if (l_fabric_addr_bar_mode == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM)
    {
        l_base_address.insertFromRight < FABRIC_ADDR_LS_SYSTEM_ID_START_BIT,
                                       (FABRIC_ADDR_LS_SYSTEM_ID_END_BIT - FABRIC_ADDR_LS_SYSTEM_ID_START_BIT + 1) > (l_fabric_system_id);
    }
    else
    {
        uint32_t l_fabric_system_id_fld = (l_fabric_system_id >> FABRIC_ADDR_SS_SYSTEM_ID_FLD0_SHIFT) &
                                          FABRIC_ADDR_SS_SYSTEM_ID_FLD0_MASK;
        l_base_address.insertFromRight < FABRIC_ADDR_SS_SYSTEM_ID_FLD0_START_BIT,
                                       (FABRIC_ADDR_SS_SYSTEM_ID_FLD0_END_BIT - FABRIC_ADDR_SS_SYSTEM_ID_FLD0_START_BIT + 1) > (l_fabric_system_id_fld);

        l_fabric_system_id_fld = (l_fabric_system_id >> FABRIC_ADDR_SS_SYSTEM_ID_FLD1_SHIFT) &
                                 FABRIC_ADDR_SS_SYSTEM_ID_FLD1_MASK;
        l_base_address.insertFromRight < FABRIC_ADDR_SS_SYSTEM_ID_FLD1_START_BIT,
                                       (FABRIC_ADDR_SS_SYSTEM_ID_FLD1_END_BIT - FABRIC_ADDR_SS_SYSTEM_ID_FLD1_START_BIT + 1) > (l_fabric_system_id_fld);

        l_fabric_system_id_fld = (l_fabric_system_id >> FABRIC_ADDR_SS_SYSTEM_ID_FLD2_SHIFT) &
                                 FABRIC_ADDR_SS_SYSTEM_ID_FLD2_MASK;
        l_base_address.insertFromRight < FABRIC_ADDR_SS_SYSTEM_ID_FLD2_START_BIT,
                                       (FABRIC_ADDR_SS_SYSTEM_ID_FLD2_END_BIT - FABRIC_ADDR_SS_SYSTEM_ID_FLD2_START_BIT + 1) > (l_fabric_system_id_fld);
    }

    // apply group ID
    if (l_fabric_addr_bar_mode == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM)
    {
        l_base_address.insertFromRight < FABRIC_ADDR_LS_GROUP_ID_START_BIT,
                                       (FABRIC_ADDR_LS_GROUP_ID_END_BIT - FABRIC_ADDR_LS_GROUP_ID_START_BIT + 1) > (l_fabric_group_id);
    }
    else
    {
        l_base_address.insertFromRight < FABRIC_ADDR_SS_GROUP_ID_START_BIT,
                                       (FABRIC_ADDR_SS_GROUP_ID_END_BIT - FABRIC_ADDR_SS_GROUP_ID_START_BIT + 1) > (l_fabric_group_id);
    }

    // apply chip ID (relevant for large system map only)
    if (l_fabric_addr_bar_mode == fapi2::ENUM_ATTR_PROC_FABRIC_ADDR_BAR_MODE_LARGE_SYSTEM)
    {
        l_base_address.insertFromRight < FABRIC_ADDR_LS_CHIP_ID_START_BIT,
                                       (FABRIC_ADDR_LS_CHIP_ID_END_BIT - FABRIC_ADDR_LS_CHIP_ID_START_BIT + 1) > (l_fabric_chip_id);
    }

    // set output addresses based on application of msel
    if (l_mirror_policy == fapi2::ENUM_ATTR_MEM_MIRROR_PLACEMENT_POLICY_NORMAL)
    {
        // nm = 0b00/01, m = 0b10, mmio = 0b11
        o_base_address_nm0 = l_base_address();               // 00
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_nm1 = l_base_address();               // 01
        l_base_address.setBit<FABRIC_ADDR_MSEL_START_BIT>();
        l_base_address.clearBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_m = l_base_address();                 // 10
        l_base_address.setBit(FABRIC_ADDR_MSEL_END_BIT);
        o_base_address_mmio = l_base_address();              // 11
    }
    else
    {
        // nm = 0b01/10, m = 0b00, mmio = 0b11
        o_base_address_m = l_base_address();                 // 00
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_nm0 = l_base_address();               // 01
        l_base_address.setBit<FABRIC_ADDR_MSEL_START_BIT>();
        l_base_address.clearBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_nm1 = l_base_address();               // 10
        l_base_address.setBit<FABRIC_ADDR_MSEL_END_BIT>();
        o_base_address_mmio = l_base_address();              // 11
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
