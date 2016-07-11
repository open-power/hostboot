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
#include <fapi2.H>
#include <p9_mc_scom_addresses.H>

using fapi2::FAPI2_RC_FALSE;

extern "C"
{
    fapi2::ReturnCode p9_collect_some_ffdc(std::vector<std::shared_ptr<fapi2::ErrorInfoFfdc>>& o_ffdc_data, uint32_t a,
                                           uint8_t b)
    {
        FAPI_INF("parm1=%d and parm2=%d", a, b);
        o_ffdc_data.push_back(std::shared_ptr<fapi2::ErrorInfoFfdc>(new fapi2::ErrorInfoFfdc( 0xdeadbeef, &a, sizeof(a))));
        o_ffdc_data.push_back(std::shared_ptr<fapi2::ErrorInfoFfdc>(new fapi2::ErrorInfoFfdc( 0xcafebabe, &b, sizeof(b))));

        return fapi2::ReturnCode();
    }

}
