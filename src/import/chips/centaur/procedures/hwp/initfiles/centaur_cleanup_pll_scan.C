/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_cleanup_pll_scan.C $ */
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
#include "centaur_cleanup_pll_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_1 = 1;
constexpr uint64_t literal_0x000020000000 = 0x000020000000;
constexpr uint64_t literal_0 = 0;
constexpr uint64_t literal_0x40002208BF00 = 0x40002208BF00;

fapi2::ReturnCode centaur_cleanup_pll_scan(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0,
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& TGT1)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::ATTR_IS_SIMULATION_Type l_TGT1_ATTR_IS_SIMULATION;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_SIMULATION, TGT1, l_TGT1_ATTR_IS_SIMULATION));
        uint64_t l_def_IS_SIM = (l_TGT1_ATTR_IS_SIMULATION == literal_1);
        uint64_t l_def_IS_HW = (l_TGT1_ATTR_IS_SIMULATION == literal_0);
        bool l_DMI_RX_RXCLKCTL_CUPLL_CTL_update = false;
        fapi2::variable_buffer l_DMI_RX_RXCLKCTL_CUPLL_CTL(47);

        if (l_def_IS_SIM)
        {
            l_DMI_RX_RXCLKCTL_CUPLL_CTL.insertFromRight<uint64_t>(literal_0x000020000000, 0, 47);
            l_DMI_RX_RXCLKCTL_CUPLL_CTL_update = true;
        }
        else if (l_def_IS_HW)
        {
            l_DMI_RX_RXCLKCTL_CUPLL_CTL.insertFromRight<uint64_t>(literal_0x40002208BF00, 0, 47);
            l_DMI_RX_RXCLKCTL_CUPLL_CTL_update = true;
        }

        if ( l_DMI_RX_RXCLKCTL_CUPLL_CTL_update)
        {
            FAPI_TRY(fapi2::putSpy(TGT0, "DMI.RX.RXCLKCTL.CUPLL_CTL", l_DMI_RX_RXCLKCTL_CUPLL_CTL));
        }

    };
fapi_try_exit:
    return fapi2::current_err;
}
