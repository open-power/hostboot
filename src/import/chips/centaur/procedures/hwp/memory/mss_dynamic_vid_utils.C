/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/mss_dynamic_vid_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file mss_dynamic_vid_utils.C
/// @brief Utility procedures for dyanamic voltage
///
/// *HWP HWP Owner: Andre Marin <aamarin@us.ibm.com>
/// *HWP HWP Backup: Stephen Glancy <sglancy@us.ibm.com>
/// *HWP Team: Memory
/// *HWP Level: 3
/// *HWP Consumed by: HB

#include <mss_dynamic_vid_utils.H>
#include <lib/utils/cumulus_find.H>
#include <generic/memory/lib/utils/c_str.H>

///
/// @brief Checks centaur configurations and outputs DRAM device type
/// @param[in]  std::vector<fapi2::Target> l_targets  Reference to vector of Centaur Targets in a particular power domain
/// @param[out] o_dram_type the DRAM device type (DDR3 or DDR4)
/// @return ReturnCode success IFF everything passes
/// @note Checks the following configuration items:
/// The DRAM generations are all the same
/// At least one functional centaur was found
///
fapi2::ReturnCode check_dram_gen_plug(const std::vector<fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>>& i_targets,
                                      uint8_t& o_dram_gen)
{
    fapi2::ReturnCode l_bad_vpd_rc = fapi2::FAPI2_RC_SUCCESS;
    bool l_has_functional_centaur = false;
    bool l_dram_gen_found = false;
    uint8_t l_cur_dram_gen = 0;

    // Checks to make sure that all of the DRAM generation attributes are the same, if not error out
    // The reason behind this is that DDR3 and DDR4 require mutually exclusive voltage ranges
    // For custom DIMM's someone could have violated plug rules and put a DDR3 and DDR4 DIMM on the same voltage rail
    // In that case, we want to call out all of the DIMM that are improperly plugged and exit
    for(const auto& l_chip : i_targets)
    {
        // Gets the functional attribute to check for an active centaur
        uint8_t l_is_functional = 0;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUNCTIONAL, l_chip, l_is_functional));

        // Found a functional centaur, we won't error out now
        if(l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
        {
            l_has_functional_centaur = true;
        }

        for(const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_chip))
        {
            // Gets the attributes and computes var_power_on based upon whether the DRAM type is DDR3 or DDR4
            auto l_rc = FAPI_ATTR_GET(fapi2::ATTR_CEN_SPD_DRAM_DEVICE_TYPE, l_dimm, l_cur_dram_gen);

            // Found an error reading the SPD/VPD, let's see if we can determine why
            // Note: in centaur, if we're using ISDIMM's, then it's SPD
            // If we're using CDIMM, then it's VPD
            if(l_rc)
            {
                // If the dimm is functional, then we shouldn't have failed the access to the DRAM device type, log this DIMM as failing and proceed to the next one
                // In order to reduce the size of the de-config loop, we want to callout ALL bad SPD/VPD
                // At this point, we're assuming that the VPD read error is the fault of hardware
                if(l_is_functional == fapi2::ENUM_ATTR_FUNCTIONAL_FUNCTIONAL)
                {
                    const auto& l_mba = mss::find_target<fapi2::TARGET_TYPE_MBA>(l_dimm);
                    FAPI_ASSERT_NOEXIT(false, fapi2::CEN_MSS_VDDR_FUNCTIONAL_DIMM_VPD_READ_ERROR()
                                       .set_DIMM_TARGET(l_dimm)
                                       .set_MBA_TARGET(l_mba),
                                       "Problem reading VPD on functional DIMM. Logging error and proceding to the next DIMM.");

                    // Using a generic error here as we already logged the other error above
                    l_bad_vpd_rc = fapi2::FAPI2_RC_INVALID_PARAMETER;
                }
                // The DIMM is not functional, assume that bad VPD caused the attribute access fail
                // Note the problem with an informational statement and skip this DIMM
                else
                {
                    FAPI_INF("Problem reading VPD on non-functional DIMM. Skipping current DIMM and proceding to the next DIMM.");
                }

                continue;
            }

            // If this is the first DIMM that has a valid DRAM Technology level, then set the level and continue
            if(!l_dram_gen_found)
            {
                o_dram_gen = l_cur_dram_gen;
                l_dram_gen_found = true;
            } //end if
            // Check if the DRAM levels are the same, if not, log the information and continue on
            // Again, we want to callout as many badly configured DIMM as possible
            else
            {
                // Values are not equal continue to call out all non-equal DRAM generations
                if(l_cur_dram_gen != o_dram_gen)
                {
                    const auto& l_mba = mss::find_target<fapi2::TARGET_TYPE_MBA>(l_dimm);
                    FAPI_ASSERT_NOEXIT(false, fapi2::CEN_MSS_VOLT_VDDR_OFFSET_DRAM_GEN_MISCOMPARE()
                                       .set_DIMM_TARGET(l_dimm)
                                       .set_MBA_TARGET(l_mba)
                                       .set_DRAM_GEN_MISCOMPARE(l_cur_dram_gen)
                                       .set_DRAM_GEN_START(o_dram_gen),
                                       "Not all DRAM technology generations are the same.  Exiting....");

                    // Using a generic error here as we already logged the other error above
                    l_bad_vpd_rc = fapi2::FAPI2_RC_INVALID_PARAMETER;
                }//end if

            }//end else
        } // end for DIMM
    } // End for chip target

    // Found a bad VPD
    FAPI_TRY(l_bad_vpd_rc, "DIMM configuration or hardware error. Check error logs");

    // Did not find any functional centaurs
    FAPI_ASSERT(l_has_functional_centaur,
                fapi2::CEN_MSS_VOLT_VDDR_FUNCTIONAL_CENTAUR_NOT_FOUND()
                .set_CEN_TARGET(i_targets[0]),
                "%s No functional centaurs found!  Exiting....", mss::c_str(i_targets[0]));

    // Checks to make sure that the code actually found a dimm with a value for its dram generation. if not, exit out
    FAPI_ASSERT(l_dram_gen_found,
                fapi2::CEN_MSS_VOLT_VDDR_DRAM_GEN_NOT_FOUND()
                .set_CEN_TARGET(i_targets[0]),
                "%s No DRAM generation found!  Exiting....", mss::c_str(i_targets[0]));

fapi_try_exit:
    return fapi2::current_err;
}
