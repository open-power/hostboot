/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/utils/ody_generate_sbe_attribute_data.C $ */
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
#include <ody_generate_sbe_attribute_data.H>
#include <sbe_attribute_utils.H>

using namespace fapi2;
using namespace sbeutil;

extern "C"
{
    ReturnCode ody_generate_sbe_attribute_data(
        const Target<TARGET_TYPE_OCMB_CHIP>& i_ocmb_targ, void* o_buf, const uint16_t i_buf_size)
    {
        FAPI_DBG("ody_generate_sbe_attribute_data Entering");

        SbeAttributeUpdateFileGenerator l_update_gen;
        fapi2::Target<TARGET_TYPE_SYSTEM> l_sysTarget;

        FAPI_TRY(l_update_gen.setChipTarget(i_ocmb_targ), "setChipTarget failed");

        // Generated code begins here
        ////////////////////////////////////////////////////////////////////////

#include <ody_generate_attribute_generated.C>

        ////////////////////////////////////////////////////////////////////////
        // Generated code ends here

        FAPI_TRY(l_update_gen.genOutput("", o_buf, i_buf_size), "genOutput failed");

    fapi_try_exit:
        FAPI_DBG("ody_generate_sbe_attribute_data Exiting");
        return fapi2::current_err;
    }

}// extern C
