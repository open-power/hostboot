/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/sbe_utils/gentool/attrtool/templates/ody_generate_attribute_generated.C.t $ */
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

/**************************************************************************
 *
 * The content of this file has been generated using the jinja2
 * template ody_generate_attribute_generated.C.t. For any changes required,
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

{% for attr in attr_data.getToSbeSystemAttributes() %}
{
    {{attr.name}}_Type l_val;
    FAPI_TRY(FAPI_ATTR_GET({{attr.name}}, l_sysTarget, l_val),
                "{{attr.name}} read failed");
    FAPI_DBG("updating 0x%08X, size=%d, value=0x%8X",
                {{attr.name}}, sizeof({{attr.name}}_Type), l_val);

    FAPI_TRY(l_update_gen.addAttribute(
                    l_sysTarget,
                    {{attr.name}},
                    &l_val,
                    sizeof({{attr.name}}_Type),
                    sizeof({{attr.value_type}}_t)),
                "{{attr.name}} addAttribute failed");
}
{% endfor %}

{% for attr in attr_data.getToSbeOdysseyChipAttributes() %}
{
    {{attr.name}}_Type l_val;
    FAPI_TRY(FAPI_ATTR_GET({{attr.name}}, i_ocmb_targ, l_val),
                "{{attr.name}} read failed");
    FAPI_DBG("updating 0x%08X, size=%d, value=0x%8X",
                {{attr.name}}, sizeof({{attr.name}}_Type), l_val);

    FAPI_TRY(l_update_gen.addAttribute(
                    i_ocmb_targ,
                    {{attr.name}},
                    &l_val,
                    sizeof({{attr.name}}_Type),
                    sizeof({{attr.value_type}}_t)),
                "{{attr.name}} addAttribute failed");
}
{% endfor %}

{% for targ in attr_data.to_sbe_list if (targ != "TARGET_TYPE_SYSTEM"    and
                                        targ != "TARGET_TYPE_OCMB_CHIP") %}

for(auto& l_child_targ : i_ocmb_targ.getChildren<{{targ}}>(TARGET_STATE_PRESENT))
{
    {% for attr in attr_data.to_sbe_list[targ] %}
    {
        {{attr.name}}_Type l_val;
        FAPI_TRY(FAPI_ATTR_GET({{attr.name}}, l_child_targ, l_val),
                    "{{attr.name}} read failed");
        FAPI_DBG("updating 0x%08X, size=%d, value=0x%8X",
                    {{attr.name}}, sizeof({{attr.name}}_Type), l_val);

        FAPI_TRY(l_update_gen.addAttribute(
                        l_child_targ,
                        {{attr.name}},
                        &l_val,
                        sizeof({{attr.name}}_Type),
                        sizeof({{attr.value_type}}_t)),
                    "{{attr.name}} addAttribute failed");
    }
    {% endfor %}
}
{% endfor %}
