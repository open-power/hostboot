/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_utils.C $    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2019                        */
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
/// @file p10_fbc_utils.C
/// @brief Fabric library functions/constants (FAPI2)
///
/// The functions in this file provide:
/// - Information about the instantaneous state of the fabric
/// - Means to restart the fabric after a checkstop condition
/// - Determination of the chip's base address in the real address map
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HW Maintainer: Joe McGill (jmcgill@us.ibm.com)
// *HWP FW Maintainer: Thi Tran   (thi@us.ibm.com)
// *HWP Consumed by  : SBE,HB,FSP
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_utils.H>
#include <p10_pba_utils_TEMP_DEFINES.H> // FIXME
// FIXME @RTC206386 #include <p10_misc_scom_addresses.H>
// FIXME @RTC206386 #include <p10_misc_scom_addresses_fld.H>


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
// memory group/chip ID
const uint8_t FABRIC_ADDR_MEMORY_GROUP_ID_START_BIT = 0;
const uint8_t FABRIC_ADDR_MEMORY_GROUP_ID_LEN       = 3;
const uint8_t FABRIC_ADDR_MEMORY_CHIP_ID_START_BIT  = 3;
const uint8_t FABRIC_ADDR_MEMORY_CHIP_ID_LEN        = 3;



//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// NOTE: see comments above function prototype in header
fapi2::ReturnCode p10_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running)
{
    FAPI_DBG("Start");

#if 0 // FIXME temporarily removed to enable getmempba development
    fapi2::ATTR_CHIP_EC_FEATURE_HW328175_Type l_hw328175;
#endif
    fapi2::buffer<uint64_t> l_fbc_mode_data;
    fapi2::buffer<uint64_t> l_pmisc_mode_data;

#if 0 // FIXME temporarily removed to enable getmempba development
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
#endif

#if 0 // FIXME TODO XXX @HW481918
    {
        FAPI_TRY(fapi2::getScom(i_target, PB_ES3_MODE, l_fbc_mode_data),
                 "Error reading FBC Mode Register");
        // fabric is initialized if PB_INITIALIZED bit is one/set
        o_is_initialized = l_fbc_mode_data.getBit<PB_ES3_MODE_PB_CENT_PBIXXX_INIT>();
    }

#endif
#if 1 // FIXME TODO XXX @HW481918
    o_is_initialized = true;
#endif
    // read ADU PMisc Mode Register state
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading ADU PMisc Mode register");

    // fabric is running if FBC_STOP bit is zero/clear
    o_is_running = !(l_pmisc_mode_data.getBit<PU_SND_MODE_REG_PB_STOP>());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}


//       The PBA utilities do not require any of these functions and
//       they do not compile cleanly in P10.
// NOTE: see comments above function prototype in header
fapi2::ReturnCode p10_fbc_utils_override_fbc_stop(
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
