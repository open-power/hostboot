/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_utils.C $      */
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
// *HWP Level: 3
// *HWP Consumed by: SBE,HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_utils.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// FBC base address determination constants
// system ID (large system)
const uint8_t FABRIC_ADDR_LS_SYSTEM_ID_START_BIT = 8;
const uint8_t FABRIC_ADDR_LS_SYSTEM_ID_END_BIT = 12;
// msel bits (large & small system)
const uint8_t FABRIC_ADDR_MSEL_START_BIT = 13;
const uint8_t FABRIC_ADDR_MSEL_END_BIT = 14;
// group ID (large system)
const uint8_t FABRIC_ADDR_LS_GROUP_ID_START_BIT = 15;
const uint8_t FABRIC_ADDR_LS_GROUP_ID_END_BIT = 18;
// chip ID (large system)
const uint8_t FABRIC_ADDR_LS_CHIP_ID_START_BIT = 19;
const uint8_t FABRIC_ADDR_LS_CHIP_ID_END_BIT = 21;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running)
{
    FAPI_DBG("Start");

    fapi2::ATTR_CHIP_EC_FEATURE_HW328175_Type l_hw328175;
    fapi2::buffer<uint64_t> l_fbc_mode_data;
    fapi2::buffer<uint64_t> l_pmisc_mode_data;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW328175, i_target, l_hw328175),
             "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_HW328175");

    if (l_hw328175)
    {
        // sampling FBC init from PB Mode register is unreliable
        // as init can drop perodically at runtime (based on legacy sleep backoff),
        // just return true to caller
        o_is_initialized = true;
    }
    else
    {
        FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM0_PB_CENT_MODE, l_fbc_mode_data),
                 "Error reading FBC Mode Register");
        // fabric is initialized if PB_INITIALIZED bit is one/set
        o_is_initialized = l_fbc_mode_data.getBit<PU_PB_CENT_SM0_PB_CENT_MODE_PB_CENT_PBIXXX_INIT>();
    }

    // read ADU PMisc Mode Register state
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading ADU PMisc Mode register");

    // fabric is running if FBC_STOP bit is zero/clear
    o_is_running = !(l_pmisc_mode_data.getBit<PU_SND_MODE_REG_PB_STOP>());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    // read ADU PMisc Mode Register state
    fapi2::buffer<uint64_t> l_pmisc_mode_data;
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading ADU PMisc Mode register");

    // set bit to disable checkstop forwarding and write back
    l_pmisc_mode_data.setBit<PU_SND_MODE_REG_DISABLE_CHECKSTOP>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error writing ADU PMisc Mode register to disable checkstop forwarding to FBC");

    // set bit to manually clear stop control and write back
    l_pmisc_mode_data.setBit<PU_SND_MODE_REG_MANUAL_CLR_PB_STOP>();
    FAPI_TRY(fapi2::putScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error writing ADU PMisc Mode register to manually clear FBC stop control");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p9_fbc_utils_get_chip_base_address(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9_fbc_utils_addr_mode_t i_addr_mode,
    uint64_t& o_base_address_nm0,
    uint64_t& o_base_address_nm1,
    uint64_t& o_base_address_m,
    uint64_t& o_base_address_mmio)
{
    uint32_t l_fabric_system_id = 0;
    uint8_t l_fabric_group_id = 0;
    uint8_t l_fabric_chip_id = 0;
    uint8_t l_mirror_policy;
    fapi2::buffer<uint64_t> l_base_address;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;

    FAPI_DBG("Start");

    // retreive attributes which statically determine chips position in memory map
    // use effective group/chip ID attributes to program position specific address bits
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_SYSTEM_ID, i_target, l_fabric_system_id),
             "Error from FAPI_ATTR_GET (ATTR_FABRIC_SYSTEM_ID)");

    if (i_addr_mode == ABS_FBC_GRP_CHIP_IDS)
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_GROUP_ID, i_target, l_fabric_group_id),
                 "Error from FAPI_ATTR_GET (ATTR_FABRIC_GROUP_ID)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_FABRIC_CHIP_ID, i_target, l_fabric_chip_id),
                 "Error from FAPI_ATTR_GET (ATTR_FABRIC_CHIP_ID)");
    }
    else
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EFF_FABRIC_GROUP_ID, i_target, l_fabric_group_id),
                 "Error from FAPI_ATTR_GET (ATTR_EFF_FABRIC_GROUP_ID)");

        if (i_addr_mode == EFF_FBC_GRP_CHIP_IDS)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_EFF_FABRIC_CHIP_ID, i_target, l_fabric_chip_id),
                     "Error from FAPI_ATTR_GET (ATTR_EFF_FABRIC_CHIP_ID)");
        }
    }

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_MEM_MIRROR_PLACEMENT_POLICY, FAPI_SYSTEM, l_mirror_policy),
             "Error from FAPI_ATTR_GET (ATTR_MEM_MIRROR_PLACEMENT_POLICY)");

    // apply system ID
    // occupies one field for large system map
    l_base_address.insertFromRight < FABRIC_ADDR_LS_SYSTEM_ID_START_BIT,
                                   (FABRIC_ADDR_LS_SYSTEM_ID_END_BIT - FABRIC_ADDR_LS_SYSTEM_ID_START_BIT + 1) > (l_fabric_system_id);

    // apply group ID
    l_base_address.insertFromRight < FABRIC_ADDR_LS_GROUP_ID_START_BIT,
                                   (FABRIC_ADDR_LS_GROUP_ID_END_BIT - FABRIC_ADDR_LS_GROUP_ID_START_BIT + 1) > (l_fabric_group_id);

    // apply chip ID (relevant for large system map only)
    l_base_address.insertFromRight < FABRIC_ADDR_LS_CHIP_ID_START_BIT,
                                   (FABRIC_ADDR_LS_CHIP_ID_END_BIT - FABRIC_ADDR_LS_CHIP_ID_START_BIT + 1) > (l_fabric_chip_id);

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
