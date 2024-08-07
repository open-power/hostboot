/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_get_interposer_ecid.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2024                        */
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
/// @file p10_get_interposer_ecid.C
/// @brief Wait for dccal done and power-up all configured links/lanes
///-----------------------------------------------------------------------------
/// *HW HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HW FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HW Consumed by  : HB
///-----------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <p10_get_interposer_ecid.H>
#include <p10_scom_perv.H>

///
/// @brief Wait for dccal done and power-up all configured links/lanes
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode p10_get_interposer_ecid(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        fapi2::variable_buffer& o_ecid)
{
    fapi2::ATTR_INTERPOSER_REV_Type l_interposer_rev = fapi2::ENUM_ATTR_INTERPOSER_REV_NONE;
    fapi2::variable_buffer l_fuseString(p10_get_interposer_ecid_fuseString_len);

    fapi2::buffer<uint64_t> l_ecid_part3_data64 = 0;
    fapi2::buffer<uint64_t> l_interposer_rev_fuse_bits = 0;

    // Check if interposer is present
    FAPI_TRY(fapi2::getScom(i_target, scomt::perv::SINGLE_OTP_ROM_OTPROM_REG3, l_ecid_part3_data64));

    if (l_ecid_part3_data64 == 0)
    {
        // Interposer is not present
        goto fapi_try_exit;
    }

    // Set up the Interposer ECID information & returns
    l_ecid_part3_data64.reverse();
    FAPI_TRY(l_fuseString.insert(l_ecid_part3_data64(), 0, 64));

    o_ecid = l_fuseString;

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_INTERPOSER_ECID, i_target, l_ecid_part3_data64));

    // Check revision level and if defect is present

    // pull the SCOM (address 5), add it to the output string
    FAPI_TRY(fapi2::getScom(i_target, scomt::perv::SINGLE_OTP_ROM_OTPROM_REG5, l_interposer_rev_fuse_bits));

    if (l_interposer_rev_fuse_bits == 0)
    {
        l_interposer_rev = fapi2::ENUM_ATTR_INTERPOSER_REV_REV1;
    }
    else
    {
        l_interposer_rev = fapi2::ENUM_ATTR_INTERPOSER_REV_REV2;
    }

    FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_INTERPOSER_REV, i_target, l_interposer_rev));

fapi_try_exit:
    return fapi2::current_err;
}
