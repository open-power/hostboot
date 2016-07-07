/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/hwpf/fapi2/src/fapi2_utils.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
/**
 *  @file utils.C
 *  @brief Implements fapi2 utilities
 */
#include <fapi2_attribute_service.H>
#include <attribute_ids.H>
#include <return_code.H>
#include <plat_trace.H>
#include <target.H>

namespace fapi2
{

ReturnCode queryChipEcAndName(
    const Target < fapi2::TARGET_TYPE_ALL>& i_target,
    fapi2::ATTR_NAME_Type& o_chipName, fapi2::ATTR_EC_Type& o_chipEc )
{

    ReturnCode l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, i_target, o_chipName);

    if ( l_rc != FAPI2_RC_SUCCESS )
    {
        FAPI_ERR("queryChipEcFeature: error getting chip name");
    }
    else
    {
        l_rc = FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, i_target, o_chipEc);

        if ( l_rc != FAPI2_RC_SUCCESS )
        {
            FAPI_ERR("queryChipEcFeature: error getting chip ec");
        }
    }

    return l_rc;
}
};
