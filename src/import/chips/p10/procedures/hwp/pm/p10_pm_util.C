/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_util.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2020                        */
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
/// @file  p10_pm_util.C
/// @brief Get deconfigured core target list from ATTR_PG_MVPD
///        and ATTR_PG attribute
///
/// *HWP HW Owner        : Greg Still <stillgs@us.ibm.com>
/// *HWP FW Owner        : Prasad Bg Ranganath <prasadbgr@in.ibm.com>
/// *HWP Team            : PM
/// *HWP Level           : 2
///

#include <fapi2.H>
#include <p10_pm_util.H>

fapi2::ReturnCode getDeconfiguredTargets(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE> >& o_list)
{
    FAPI_INF(">>>>>>getDeconfiguredTargets");

    fapi2::ATTR_PG_Type l_pg;
    fapi2::ATTR_PG_MVPD_Type l_mvpd_pg;
    uint32_t EQ0_CHIPLET_ID = 0x20;
    uint8_t l_present_core_unit_pos = 0;

    auto l_eq_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    for (auto l_eq : l_eq_functional_vector)
    {
        auto l_perv = l_eq.getParent<fapi2::TARGET_TYPE_PERV>();

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG_MVPD, l_perv, l_mvpd_pg));
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_perv, l_pg));

#ifndef __HOSTBOOT_MODULE

        // From Cronus point of view this data will be always F's and it lands
        // into deconfigured list and tries to call entry procedure,which
        // shouldn't be the case for good lists. So if the pg values are F's
        // then will write the data as same mpvd_pg
        if (l_pg == 0xFFFFFFFF)
        {
            FAPI_TRY(FAPI_ATTR_SET(fapi2::ATTR_PG, l_perv, l_mvpd_pg));
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PG, l_perv, l_pg));
        }

#endif

        uint8_t l_eq_pos = l_perv.getChipletNumber() - EQ0_CHIPLET_ID;

        FAPI_INF("MVPD %08X %08X", l_mvpd_pg, l_pg);

        uint8_t l_gard_value = (l_mvpd_pg ^ l_pg) >> (31 - 16);

        auto l_core_present_vector =
            l_eq.getChildren<fapi2::TARGET_TYPE_CORE>
            (fapi2::TARGET_STATE_PRESENT);

        for (auto core_present_it : l_core_present_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET( fapi2::ATTR_CHIP_UNIT_POS,
                                    core_present_it,
                                    l_present_core_unit_pos));
            l_present_core_unit_pos  = l_present_core_unit_pos % 4;

            if (l_gard_value & (1 << (3 - l_present_core_unit_pos)))
            {
                FAPI_INF("EQ %d Core %d is deconfigured", l_eq_pos, l_present_core_unit_pos);
                o_list.push_back(core_present_it);
            }
        }
    }

fapi_try_exit:
    FAPI_INF("<<<<<<getDeconfiguredTargets");
    return fapi2::current_err;
}
