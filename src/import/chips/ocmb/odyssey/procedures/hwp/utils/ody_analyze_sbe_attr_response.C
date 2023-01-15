/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/utils/ody_analyze_sbe_attr_response.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023                             */
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
#include "ody_analyze_sbe_attr_response.H"
#include "sbe_attribute_utils.H"

using namespace fapi2;
using namespace sbeutil;

extern "C"
{
    ReturnCode ody_analyze_sbe_attr_response(
        const Target<TARGET_TYPE_OCMB_CHIP>& i_ocmb_targ,
        uint8_t* i_buf, uint16_t i_buf_size, std::vector<AttrError_t>& o_errors)
    {
        FAPI_DBG("Entering");
        SbeAttributeUpdRespFileParser l_resp;
        FAPI_TRY(l_resp.setChipTarget(i_ocmb_targ), "setChipTarget failed");
        FAPI_TRY(l_resp.parseFile(i_buf, i_buf_size), "parseFile failed");
        FAPI_DBG("----------------- PARSING DONE ------------");

        // TODO: remove after complete implementation
        l_resp.printMe();

        if(l_resp.getRemainingTargSectionCount() != 0)
        {
            // TODO: Add logics to take care different compatible versions.
            FAPI_ERR("Attribute update failed");
            fapi2::current_err = FAPI2_RC_FALSE;
            goto fapi_try_exit;
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

}// extern C
