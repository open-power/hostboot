/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/ffdc/p9_collect_some_ffdc.C $ */
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
///
/// @file   p9_collect_some_ffdc.C
///

#include <stdint.h>
#include <hwp_error_info.H>
#include <fapi2.H>

using fapi2::FAPI2_RC_FALSE;

const uint32_t PIB_RC_EXAMPLE_1 = 0x01;
const uint32_t PIB_RC_EXAMPLE_2 = 0x02;

extern "C"
{
    fapi2::ReturnCode p9_collect_some_ffdc(fapi2::ffdc_t& param1,  fapi2::ReturnCode& o_rc)
    {
        FAPI_INF("parm1=%d\n", param1);

        // define reference to data to be captured by the macro below
        // ffdc classes use these ffdc_t types so all data should be stored
        // in  one.
        fapi2::ffdc_t FFDC_DATA1;
        fapi2::ffdc_t FFDC_DATA2;

        // some piece of ffdc we collected or this failure, through a register
        // read or function call
        uint32_t my_ffdc_data = 32;
        uint64_t more_ffdc_data = 0x10002005;

        // get the actual data from the parameter, in this case its a pretend
        // pib_rc we can check and add different FFDC data depending on the
        // RC
        const uint32_t pib_rc = *(reinterpret_cast<const uint32_t*>(param1.ptr()));

        switch( pib_rc )
        {
            case PIB_RC_EXAMPLE_1:
                {
                    FFDC_DATA1.ptr() = static_cast<void*>(&my_ffdc_data);
                    FFDC_DATA1.size() = sizeof(my_ffdc_data);

                    // add our ffdc to the returnCode passed in - see sample
                    // xml for details on the xml
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PIB_ERROR_1);
                }
                break;

            case PIB_RC_EXAMPLE_2:
                {
                    FFDC_DATA1.ptr() = static_cast<void*>(&my_ffdc_data);
                    FFDC_DATA1.size() = sizeof(my_ffdc_data);

                    FFDC_DATA2.ptr() = static_cast<void*>(&more_ffdc_data);
                    FFDC_DATA2.size() = sizeof(&more_ffdc_data);

                    // add our ffdc to the returnCode passed in - see sample
                    // xml for details on the xml
                    FAPI_ADD_INFO_TO_HWP_ERROR(o_rc, RC_PIB_ERROR_2);

                }
                break;

            default:
                // do nothing
                break;
        }

        // just return success
        return fapi2::ReturnCode();
    }
}
