/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/gentool/attrtool/templates/ody_apply_attribute_generated.C.t $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2023,2024                        */
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

/**************************************************************************
 *
 * The content of this file has been generated using the jinja2
 * template ody_apply_attribute_generated.C.t For any changes required,
 * please modify the template.
 *
 **************************************************************************/
{#
 # The input to this template is attr_data object of class AttributeDB. This input
 # is passed via the environment globals. The attribute tool creates the
 # environment, sets the globals, loads the template, and render it. The rendered
 # template is returned as a string to the attribute tool. The attribute tool then
 # stores the string in a file. The suffix ".t" is used to differentiate
 # between the generated file name, and the template file name.
 #}

{% for target_type in attr_data.from_sbe_list %}

template<>
ReturnCode ody_apply_sbe_attribute_row<{{target_type}}>(
    Target<{{target_type}}>& i_targ,
    SbeAttrTargetSectionListRespParser& i_targ_parser,
    std::vector<AttrError_t>& o_errors)
{
    FAPI_DBG("ody_apply_sbe_attribute_row<{{target_type}}> entering");

    AttrEntry_t l_attrEntry;
    ReturnCode l_rc = FAPI2_RC_SUCCESS;

    // track that each attribute expected to be transmitted by the SBE
    // and posted on the host is ultimately processed
    {% for attr in attr_data.from_sbe_list[target_type] %}
        {% if attr.fromSbeSync(attr_data.chip_type, target_type) %}
    bool l_{{attr.name}}_found = false;
        {% endif %}
    {% endfor %}

    while (i_targ_parser.getRemainingRowCount())
    {
        FAPI_DBG("getRemainingRowCount() = %d", i_targ_parser.getRemainingRowCount());

        SbeAttrRowListResParser& l_attr = i_targ_parser.getNextRow();
        FAPI_TRY(l_attr.getAttrEntry(l_attrEntry), "getAttrEntry returned error");

        switch (l_attrEntry.iv_attrId)
        {
        {% for attr in attr_data.from_sbe_list[target_type] %}
            case fapi2::{{attr.name}}:
            {
             {% if attr.fromSbeSync(attr_data.chip_type, target_type) %}
                fapi2::{{attr.name}}_Type l_val;
                FAPI_TRY(l_attr.getAttrValue(&l_val, sizeof(fapi2::{{attr.name}}_Type),
                            sizeof({{attr.value_type}}_t)),
                         "getAttrValue failed for the attribute {{attr.name}}");
                l_rc = FAPI_ATTR_SET(fapi2::{{attr.name}}, i_targ, l_val);
                l_{{attr.name}}_found = true;
                if (l_rc != FAPI2_RC_SUCCESS)
                {
                    FAPI_INF("FAPI_ATTR_SET failed for the attribute {{attr.name}}");
                    o_errors.emplace_back({{target_type}}, i_targ_parser.getInstNum(),
                                          fapi2::{{attr.name}}, SBE_ATTRIBUTE_RC_SET_ATTR_FAILED);
                    fapi2::current_err = FAPI2_RC_SUCCESS;
                }
             {% else %}
                FAPI_DBG("{{attr.name}} is not required to sync from sbe");
             {% endif %}
                break;
            }
        {% endfor %}
            default:
                // SBE returns an attribute that Host is not aware of
                FAPI_INF("Unknown Attribute : 0x%08X TargetType : 0x%llX",
                         l_attrEntry.iv_attrId, {{target_type}});
                o_errors.emplace_back({{target_type}}, i_targ_parser.getInstNum(),
                                      uint32_t(l_attrEntry.iv_attrId), SBE_ATTRIBUTE_RC_ATTR_NOT_FOUND);
                break;
        }
    }

    {% for attr in attr_data.from_sbe_list[target_type] %}
        {% if attr.fromSbeSync(attr_data.chip_type, target_type) %}
    if (!l_{{attr.name}}_found)
    {
        // attribute expected to be received was not found/posted
        FAPI_INF("Attribute {{attr.name}} expected by host but not received");
        o_errors.emplace_back({{target_type}}, 0xFF,
                              fapi2::{{attr.name}}, SBE_ATTRIBUTE_RC_EXPECTED_BUT_NOT_RECEIVED);
    }
        {% endif %}
    {% endfor %}


fapi_try_exit:
    return current_err;
}

{% endfor %}
