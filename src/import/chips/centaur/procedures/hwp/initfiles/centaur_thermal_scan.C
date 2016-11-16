/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_thermal_scan.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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
#include "centaur_thermal_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;


fapi2::ReturnCode centaur_thermal_scan(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
                                       const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::variable_buffer l_TCN_EPS_THERM_OVERFLOW_ERR_MASK(1);
        constexpr auto l_TCN_EPS_THERM_OVERFLOW_ERR_MASK_ON = 0x1;
        l_TCN_EPS_THERM_OVERFLOW_ERR_MASK.insertFromRight<uint64_t>(l_TCN_EPS_THERM_OVERFLOW_ERR_MASK_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "TCN.EPS.THERM.OVERFLOW_ERR_MASK", l_TCN_EPS_THERM_OVERFLOW_ERR_MASK));

    };
fapi_try_exit:
    return fapi2::current_err;
}
