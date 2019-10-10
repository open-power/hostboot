/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_getidec.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019                             */
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
/// @file exp_getidec.C
/// @brief Contains function to lookup Chip ID and EC values of Explorer Chip
///
/// *HWP HWP Owner: Christian Geddes <crgeddes@us.ibm.com>
/// *HWP HWP Backup: <none>
/// *HWP Team: Hostboot
/// *HWP Level: 2
/// *HWP Consumed by: Hostboot / Cronus

#include <fapi2.H>
#include <exp_getidec.H>
#include <lib/shared/exp_consts.H>
#include <chips/ocmb/explorer/common/include/explorer_scom_addresses.H>
#include <chips/ocmb/explorer/common/include/explorer_scom_addresses_fixes.H>
#include <chips/ocmb/explorer/common/include/explorer_scom_addresses_fld.H>
#include <chips/ocmb/explorer/common/include/explorer_scom_addresses_fld_fixes.H>
#include <generic/memory/mss_git_data_helper.H>

extern "C"
{

    ///
    /// @brief Lookup the Chip ID and EC level values for this explorer chip
    /// @param[in]   i_target Explorer OCMB chip
    /// @param[out]  o_chipId Explorer Chip ID
    /// @param[out]  o_chipEc Explorer Chip EC
    /// @return fapi2:ReturnCode FAPI2_RC_SUCCESS if success, else error code.
    ///
    fapi2::ReturnCode exp_getidec(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  uint16_t& o_chipId,
                                  uint8_t& o_chipEc)
    {
        mss::display_git_commit_info("exp_getidec");
        uint8_t l_majorEc  = 0;
        uint8_t l_minorEc  = 0;
        uint8_t l_location = 0;
        uint8_t l_chipBaseId = 0;
        fapi2::buffer<uint64_t> l_reg_buffer;

        FAPI_TRY(fapi2::getScom( i_target,
                                 static_cast<uint64_t>(mss::exp::idec_consts::EXPLR_CHIP_INFO_REG),
                                 l_reg_buffer ),
                 "exp_getidec: could not read explorer chip_info register register 0x%08x",
                 mss::exp::idec_consts::EXPLR_CHIP_INFO_REG);

        l_reg_buffer.extractToRight<mss::exp::idec_consts::MAJOR_EC_BIT_START,
                                    mss::exp::idec_consts::MAJOR_EC_BIT_LENGTH>(l_majorEc);
        l_reg_buffer.extractToRight<mss::exp::idec_consts::LOCATION_BIT_START,
                                    mss::exp::idec_consts::LOCATION_BIT_LENGTH>(l_location);
        l_reg_buffer.extractToRight<mss::exp::idec_consts::CHIPID_BIT_START,
                                    mss::exp::idec_consts::CHIPID_BIT_LENGTH>(l_chipBaseId);

        // Due to design errors we must read the minor ec (2nd nibble) from a different register
        FAPI_TRY(fapi2::getScom( i_target, static_cast<uint64_t>(EXPLR_EFUSE_IMAGE_OUT_3), l_reg_buffer ),
                 "exp_getidec: could not read explorer efuse_out3 register 0x%08x", EXPLR_EFUSE_IMAGE_OUT_3);

        l_reg_buffer.extractToRight<EXPLR_EFUSE_IMAGE_OUT_3_ENTERPRISE_MODE_EC_MINOR,
                                    EXPLR_EFUSE_IMAGE_OUT_3_ENTERPRISE_MODE_EC_MINOR_LEN>(l_minorEc);

        // Major EC 0:3
        // Minor EC 4:7
        o_chipEc = (l_majorEc << 4) | l_minorEc;

        // Location  0:3
        // Empty     4:7
        // ChipId    8:15
        o_chipId = (l_location << 12) | l_chipBaseId;

        FAPI_DBG("EC found 0x%.02x   chipId found 0x%.04x", o_chipEc, o_chipId);

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
