/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/initfiles/p9a_int_scan.C $ */
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
#include "p9a_int_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0b1 = 0b1;

fapi2::ReturnCode p9a_int_scan(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& TGT0)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_CHIP_EC_FEATURE_HW388874_Type l_TGT0_ATTR_CHIP_EC_FEATURE_HW388874;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW388874, TGT0, l_TGT0_ATTR_CHIP_EC_FEATURE_HW388874));
        bool l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_update = false;
        fapi2::variable_buffer l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS(1);
        fapi2::variable_buffer l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_CARE(1);

        if ((l_TGT0_ATTR_CHIP_EC_FEATURE_HW388874 == literal_0))
        {
            constexpr auto l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_ON = 0x1;
            l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS.insertFromRight<uint64_t>(l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_ON, 0, 1);
            l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
            l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_update = true;
        }

        if ( l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_update)
        {
            FAPI_TRY(fapi2::putSpyWithCare(TGT0, "BRIDGE.PSIHB.ESB_OR_LSI_INTERRUPTS", l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS,
                                           l_BRIDGE_PSIHB_ESB_OR_LSI_INTERRUPTS_CARE));
        }

        fapi2::variable_buffer l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS(1);
        fapi2::variable_buffer l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS_CARE(1);
        l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS.insertFromRight<uint64_t>(literal_0b1, 0, 1);
        l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS_CARE.insertFromRight<uint64_t>(0x1, 0, 1);
        FAPI_TRY(fapi2::putSpyWithCare(TGT0, "INT.INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS",
                                       l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS, l_INT_INT_VC_LBS6_ARX_CS_AXONE_DISABLE_CILOAD_ORDERINGS_CARE));

    };
fapi_try_exit:
    return fapi2::current_err;
}
