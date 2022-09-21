/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_getecid.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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

/// @file ody_getecid.C
/// @brief Gets ECID from Odyssey fuse registers
///
/// *HWP HWP Owner: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 1
/// *HWP Consumed by: HB

#include <fapi2.H>
#include <ody_getecid.H>
#include <ody_scom_perv.H>
#include <generic/memory/lib/utils/mss_generic_check.H>



extern "C"
{
    ///
    /// @brief getecid procedure for Odyssey chip
    /// @param[in] i_target Odyssey OCMB chip
    /// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
    /// @note Sets ocmb_ecid, enterprise, half-dimm mode attributes. ody_omi_setup configures the chip with these attributes
    ///
    fapi2::ReturnCode ody_getecid(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {

        using namespace scomt;
        using namespace scomt::perv;

        uint64_t l_attr_data[2] = {};
        fapi2::buffer<uint64_t> l_ecid_part0_data64;
        fapi2::buffer<uint64_t> l_ecid_part1_data64;
        fapi2::buffer<uint64_t> l_ecid_part2_data64;

        FAPI_INF(TARGTIDFORMAT " ody_getecid : Entering ...", TARGTID);

        FAPI_INF(TARGTIDFORMAT " ody_getecid : extract and manipulate ECID data", TARGTID);
        FAPI_TRY(fapi2::getScom(i_target, CFAM_OTPROM_SINGLE_OTP_ROM_REG0, l_ecid_part0_data64));
        FAPI_TRY(fapi2::getScom(i_target, CFAM_OTPROM_SINGLE_OTP_ROM_REG1, l_ecid_part1_data64));
        FAPI_TRY(fapi2::getScom(i_target, CFAM_OTPROM_SINGLE_OTP_ROM_REG2, l_ecid_part2_data64));

        l_ecid_part0_data64.reverse();
        l_ecid_part1_data64.reverse();
        l_ecid_part2_data64.reverse();

        l_attr_data[0] = l_ecid_part0_data64();
        l_attr_data[1] = l_ecid_part1_data64();

        FAPI_INF(TARGTIDFORMAT " ody_getecid : extracted ecid: 0x%016llX 0x%016llX", TARGTID, l_attr_data[0], l_attr_data[1]);
        FAPI_INF(TARGTIDFORMAT " ody_getecid : push fuse string into attribute ...", TARGTID);

        FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target, l_attr_data));



        FAPI_INF(TARGTIDFORMAT " ody_getecid : Exiting ...", TARGTID);

    fapi_try_exit:
        return fapi2::FAPI2_RC_SUCCESS;
    }

} // extern "C"
