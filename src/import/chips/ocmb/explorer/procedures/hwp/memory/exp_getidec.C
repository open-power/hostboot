/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/explorer/procedures/hwp/memory/exp_getidec.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
#include <explorer_scom_addresses.H>
#include <explorer_scom_addresses_fixes.H>
#include <explorer_scom_addresses_fld.H>
#include <explorer_scom_addresses_fld_fixes.H>
#include <generic/memory/mss_git_data_helper.H>
#include <generic/memory/lib/utils/c_str.H>

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
        uint8_t l_revision = 0;
        uint8_t l_location = 0;
        uint8_t l_chipBaseId = 0;
        fapi2::buffer<uint64_t> l_chip_info_buffer;
        fapi2::buffer<uint64_t> l_efuse3_buffer;

        // The chipid and location come from the CHIP_INFO register
        FAPI_TRY(fapi2::getScom( i_target,
                                 static_cast<uint64_t>(mss::exp::idec_consts::EXPLR_CHIP_INFO_REG),
                                 l_chip_info_buffer ),
                 "exp_getidec: could not read explorer chip_info register register 0x%08x",
                 mss::exp::idec_consts::EXPLR_CHIP_INFO_REG);

        l_chip_info_buffer.extractToRight<mss::exp::idec_consts::LOCATION_BIT_START,
                                          mss::exp::idec_consts::LOCATION_BIT_LENGTH>(l_location);
        l_chip_info_buffer.extractToRight<mss::exp::idec_consts::CHIPID_BIT_START,
                                          mss::exp::idec_consts::CHIPID_BIT_LENGTH>(l_chipBaseId);

        // Location  0:3
        // Empty     4:7
        // ChipId    8:15
        o_chipId = (l_location << 12) | l_chipBaseId;


        // The revision/DD/EC level comes from EFUSE_IMAGE_OUT_3
        FAPI_TRY(fapi2::getScom( i_target, static_cast<uint64_t>(EXPLR_EFUSE_IMAGE_OUT_3), l_efuse3_buffer ),
                 "exp_getidec: could not read explorer efuse_out3 register 0x%08x", EXPLR_EFUSE_IMAGE_OUT_3);

        l_efuse3_buffer.extractToRight<mss::exp::idec_consts::REVISION_BIT_START,
                                       mss::exp::idec_consts::REVISION_BIT_LENGTH>(l_revision);

        // Due to limitations in what logic could be updated between revisions
        //  there is no explicit Major+Minor value available in the hardware.
        //  Instead we have to explicitly convert a rolling number into the
        //  standard major.minor DD value we expect.
        o_chipEc = 0;

        switch( l_revision )
        {
            case(0):
                o_chipEc = 0x10;
                break; //A.0

            case(1):
                o_chipEc = 0x11;
                break; //A.1

            case(2):
                o_chipEc = 0x20;
                break; //B.0
        }

        // Ensure we found a known level
        FAPI_ASSERT(o_chipEc != 0,
                    fapi2::EXP_UNKNOWN_REVISION().
                    set_TARGET(i_target).
                    set_REVISION(l_revision).
                    set_CHIP_INFO_REG(l_chip_info_buffer).
                    set_EFUSE_IMAGE_OUT_3(l_efuse3_buffer),
                    "The %s revision (%d) does not match a known DD level.",
                    mss::c_str(i_target), l_revision);


        FAPI_DBG("EC found 0x%.02x   chipId found 0x%.04x", o_chipEc, o_chipId);

    fapi_try_exit:
        return fapi2::current_err;
    }

} // extern "C"
