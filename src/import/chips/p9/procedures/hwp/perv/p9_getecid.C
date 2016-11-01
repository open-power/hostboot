/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/perv/p9_getecid.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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


//## auto_generated
#include "p9_getecid.H"
//## auto_generated
#include "p9_const_common.H"

#include <p9_perv_scom_addresses.H>
#include <p9_perv_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_const_common.H>


fapi2::ReturnCode p9_getecid(const
                             fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip, fapi2::variable_buffer& o_fuseString)
{
    uint64_t attr_data[2];
    fapi2::buffer<uint64_t> l_ecid_part0_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part1_data64 = 0;
    FAPI_INF("Entering ...");


    FAPI_DBG("extract and manipulate ECID data");
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART0_REGISTER, l_ecid_part0_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, PU_OTPROM0_ECID_PART1_REGISTER, l_ecid_part1_data64));

    l_ecid_part0_data64.reverse();
    l_ecid_part1_data64.reverse();

    attr_data[0] = l_ecid_part0_data64();
    attr_data[1] = l_ecid_part1_data64();

    FAPI_TRY(o_fuseString.insert(l_ecid_part0_data64(), 0, 64));

    FAPI_TRY(o_fuseString.insert(l_ecid_part1_data64(), 64, 48));

    FAPI_DBG("push fuse string into attribute");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target_chip, attr_data));

    FAPI_INF("Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}

