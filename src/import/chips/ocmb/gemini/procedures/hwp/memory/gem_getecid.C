/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/gemini/procedures/hwp/memory/gem_getecid.C $ */
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

#include <fapi2.H>
#include <gem_getecid.H>
#include <mss_explorer_attribute_setters.H>
#include <generic/memory/mss_git_data_helper.H>

extern "C"
{

    ///
    /// @brief Gets gemini ECID
    /// @param[in] i_target the controller
    /// @return FAPI2_RC_SUCCESS iff ok
    ///
    fapi2::ReturnCode gem_getecid(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
    {
        mss::display_git_commit_info("gem_getecid");

        // Address defined here as gemini SCOM address library does not exist
        static constexpr uint64_t GEMINI_ECID_REGISTER = 0x0801240E;
        fapi2::buffer<uint64_t> l_data_buffer;

        FAPI_TRY(fapi2::getScom(i_target, GEMINI_ECID_REGISTER, l_data_buffer),
                 "Failed getScom() for %s", mss::spd::c_str(i_target));

        {
            // Set ATTR_ECID
            // TK - Update once ATTR_ECID array size is updated to be larger than 2
            static constexpr uint32_t ECID_ARRAY_SIZE = 2;
            uint64_t l_attr_ecid[ECID_ARRAY_SIZE] = {l_data_buffer, 0};

            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_ECID, i_target, l_attr_ecid),
                     "exp_getecid: Could not set ATTR_ECID on %s", mss::c_str(i_target) );
        }

        // omi_setup not used by GEMINI, so not setting ocmb enterprise mode and half-dimm mode attributes

    fapi_try_exit:
        return fapi2::current_err;
    }
} // extern "C"
