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
#include <ody_analyze_sbe_attr_response.H>
#include <sbe_attribute_utils.H>

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
        SbeTarget                     l_sbe_target;
        AttrRespEntry_t               l_attrRespEntry;


        FAPI_TRY(l_resp.setChipTarget(i_ocmb_targ), "setChipTarget failed");
        FAPI_TRY(l_resp.parseFile(i_buf, i_buf_size), "parseFile failed");
        FAPI_DBG("----------------- PARSING DONE ------------");

        while(l_resp.getRemainingTargSectionCount())
        {
            FAPI_DBG("l_resp.getRemainingTargSectionCount() = %d",
                     l_resp.getRemainingTargSectionCount());

            SbeAttrTargetSectionUpdRespParser& l_targ_parser =
                l_resp.getNextTargetSection(l_sbe_target);

            while (l_targ_parser.getRemainingRowCount())
            {
                FAPI_DBG("getRemainingRowCount() = %d", l_targ_parser.getRemainingRowCount());

                SbeAttrRowUpdResParser& l_attr = l_targ_parser.getNextRow();

                l_attr.getResponse(l_attrRespEntry);

                fapi2::TargetType l_targType =
                    fapi2::logToTargetType(l_sbe_target.iv_targ_type);
                o_errors.emplace_back(l_targType, l_sbe_target.iv_inst_num,
                                      l_attrRespEntry.iv_attrId, l_attrRespEntry.iv_rc);
            }
        }

    fapi_try_exit:
        FAPI_DBG("Exiting");
        return fapi2::current_err;
    }

}// extern C
