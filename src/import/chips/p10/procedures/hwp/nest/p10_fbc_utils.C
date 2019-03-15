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
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: SBE,HB,FSP
///

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
const uint8_t FABRIC_ADDR_SMF_BIT = 12;
const uint8_t FABRIC_ADDR_MSEL_START_BIT = 13;
const uint8_t FABRIC_ADDR_MSEL_END_BIT = 14;
const uint8_t FABRIC_ADDR_TID_INDEX_START_BIT = 15;
const uint8_t FABRIC_ADDR_TID_INDEX_END_BIT = 19;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////
// p10_fbc_utils_get_fbc_state
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_get_fbc_state(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    bool& o_is_initialized,
    bool& o_is_running)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_fbc_mode_data;
    fapi2::buffer<uint64_t> l_pmisc_mode_data;

#if 0 // FIXME TODO Enable when scom defs are ready (RTC 205268)
    {
        // read PB ES3 Mode Register state
        FAPI_TRY(fapi2::getScom(i_target, PU_PB_ES3_MODE, l_fbc_mode_data),
                 "Error reading pb_init from Powerbus ES3 Mode Config Register");

        // fabric is initialized if PB_INITIALIZED bit is one/set
        o_is_initialized = l_fbc_mode_data.getBit<PB_ES3_MODE_PB_CENT_PBIXXX_INIT>();
    }
#endif

    // read PB ES3 Mode Register state
    FAPI_TRY(getScom(i_target, 0x301100A, l_fbc_mode_data),
             "Error reading pb_init from Powerbus ES3 Mode Config Register");

    // fabric is initialized if PB_INITIALIZED bit is one/set
    o_is_initialized = l_fbc_mode_data && 0x8000000000000000;

    // read ADU PMisc Mode Register state
    FAPI_TRY(fapi2::getScom(i_target, PU_SND_MODE_REG, l_pmisc_mode_data),
             "Error reading pb_stop from ADU pMisc Mode Register");

    // fabric is running if FBC_STOP bit is zero/clear
    o_is_running = !(l_pmisc_mode_data.getBit<PU_SND_MODE_REG_PB_STOP>());

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

////////////////////////////////////////////////////////
// p10_fbc_utils_override_fbc_stop
////////////////////////////////////////////////////////
fapi2::ReturnCode p10_fbc_utils_override_fbc_stop(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::buffer<uint64_t> l_pmisc_mode_data;

    // read ADU PMisc Mode Register state
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
