/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/perv/p10_getecid.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
/// @file  p10_getecid.C
///
/// @brief Get ECID string from target using SCOM
//------------------------------------------------------------------------------
// *HWP HW Maintainer   : Anusha Reddy (anusrang@in.ibm.com)
// *HWP FW Maintainer   : Raja Das (rajadas2@in.ibm.com)
// *HWP Consumed by     : FSP
//------------------------------------------------------------------------------

#include "p10_getecid.H"
#include "p10_scom_perv_1.H"
#include "p10_scom_perv_7.H"
#include "p10_scom_perv_b.H"


fapi2::ReturnCode p10_getecid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_chip,
                              fapi2::variable_buffer& o_fuseString)
{
    using namespace scomt;
    using namespace scomt::perv;

    uint64_t attr_data[2];
    fapi2::buffer<uint64_t> l_ecid_part0_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part1_data64 = 0;
    fapi2::buffer<uint64_t> l_ecid_part2_data64 = 0;
    fapi2::variable_buffer l_fuseString(p10_getecid_fuseString_len);
    FAPI_INF("p10_getecid : Entering ...");


    FAPI_DBG("extract and manipulate ECID data");
    FAPI_TRY(fapi2::getScom(i_target_chip, SINGLE_OTP_ROM_OTPROM_REG0, l_ecid_part0_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, SINGLE_OTP_ROM_OTPROM_REG1, l_ecid_part1_data64));
    FAPI_TRY(fapi2::getScom(i_target_chip, SINGLE_OTP_ROM_OTPROM_REG2, l_ecid_part2_data64));

    l_ecid_part0_data64.reverse();
    l_ecid_part1_data64.reverse();
    l_ecid_part2_data64.reverse();

    attr_data[0] = l_ecid_part0_data64();
    attr_data[1] = l_ecid_part1_data64();

    FAPI_TRY(l_fuseString.insert(l_ecid_part0_data64(), 0, 64));

    FAPI_TRY(l_fuseString.insert(l_ecid_part1_data64(), 64, 64));

    FAPI_TRY(l_fuseString.insert(l_ecid_part2_data64(), 128, 64));

    o_fuseString = l_fuseString;

    FAPI_DBG("push fuse string into attribute");

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target_chip, attr_data));

    FAPI_INF("p10_getecid : Exiting ...");

fapi_try_exit:
    return fapi2::current_err;

}
