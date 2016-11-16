/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/initfiles/centaur_mba_scan.C $ */
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
#include "centaur_mba_scan.H"
#include <stdint.h>
#include <stddef.h>
#include <fapi2.H>

using namespace fapi2;

constexpr uint64_t literal_0x0000000000003FFF = 0x0000000000003FFF;
constexpr uint64_t literal_0xFFFFFF = 0xFFFFFF;

fapi2::ReturnCode centaur_mba_scan(const fapi2::Target<fapi2::TARGET_TYPE_MEMBUF_CHIP>& TGT0)
{
    {
        fapi2::ATTR_EC_Type   l_chip_ec;
        fapi2::ATTR_NAME_Type l_chip_id;
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_NAME, TGT0, l_chip_id));
        FAPI_TRY(FAPI_ATTR_GET_PRIVILEGED(fapi2::ATTR_EC, TGT0, l_chip_ec));
        fapi2::variable_buffer l_MBU_MBA01_DD2_HW218537_MASTER_RANK_END_FIX_DIS(1);
        constexpr auto l_MBU_MBA01_DD2_HW218537_MASTER_RANK_END_FIX_DIS_ON = 0x1;
        l_MBU_MBA01_DD2_HW218537_MASTER_RANK_END_FIX_DIS.insertFromRight<uint64_t>
        (l_MBU_MBA01_DD2_HW218537_MASTER_RANK_END_FIX_DIS_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBA01.DD2_HW218537_MASTER_RANK_END_FIX_DIS",
                               l_MBU_MBA01_DD2_HW218537_MASTER_RANK_END_FIX_DIS));
        fapi2::variable_buffer l_MBU_MBA23_DD2_HW218537_MASTER_RANK_END_FIX_DIS(1);
        constexpr auto l_MBU_MBA23_DD2_HW218537_MASTER_RANK_END_FIX_DIS_ON = 0x1;
        l_MBU_MBA23_DD2_HW218537_MASTER_RANK_END_FIX_DIS.insertFromRight<uint64_t>
        (l_MBU_MBA23_DD2_HW218537_MASTER_RANK_END_FIX_DIS_ON, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBA23.DD2_HW218537_MASTER_RANK_END_FIX_DIS",
                               l_MBU_MBA23_DD2_HW218537_MASTER_RANK_END_FIX_DIS));
        fapi2::variable_buffer l_MBU_MBA01_DD2_HW220614_SCRUB_PSAVE_DIS(1);
        constexpr auto l_MBU_MBA01_DD2_HW220614_SCRUB_PSAVE_DIS_OFF = 0x0;
        l_MBU_MBA01_DD2_HW220614_SCRUB_PSAVE_DIS.insertFromRight<uint64_t>(l_MBU_MBA01_DD2_HW220614_SCRUB_PSAVE_DIS_OFF, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBA01.DD2_HW220614_SCRUB_PSAVE_DIS", l_MBU_MBA01_DD2_HW220614_SCRUB_PSAVE_DIS));
        fapi2::variable_buffer l_MBU_MBA23_DD2_HW220614_SCRUB_PSAVE_DIS(1);
        constexpr auto l_MBU_MBA23_DD2_HW220614_SCRUB_PSAVE_DIS_OFF = 0x0;
        l_MBU_MBA23_DD2_HW220614_SCRUB_PSAVE_DIS.insertFromRight<uint64_t>(l_MBU_MBA23_DD2_HW220614_SCRUB_PSAVE_DIS_OFF, 0, 1);
        FAPI_TRY(fapi2::putSpy(TGT0, "MBU.MBA23.DD2_HW220614_SCRUB_PSAVE_DIS", l_MBU_MBA23_DD2_HW220614_SCRUB_PSAVE_DIS));
        fapi2::variable_buffer l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_0(64);
        l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_0.insertFromRight<uint64_t>(literal_0x0000000000003FFF, 0, 64);
        FAPI_TRY(fapi2::putSpy(TGT0, "TCM.TRA.MBA01TRA.TR.TRACE_TRDATA_CONFIG_0", l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_0));
        fapi2::variable_buffer l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_1(24);
        l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_1.insertFromRight<uint64_t>(literal_0xFFFFFF, 0, 24);
        FAPI_TRY(fapi2::putSpy(TGT0, "TCM.TRA.MBA01TRA.TR.TRACE_TRDATA_CONFIG_1", l_TCM_TRA_MBA01TRA_TR_TRACE_TRDATA_CONFIG_1));
        fapi2::variable_buffer l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_0(64);
        l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_0.insertFromRight<uint64_t>(literal_0x0000000000003FFF, 0, 64);
        FAPI_TRY(fapi2::putSpy(TGT0, "TCM.TRA.MBA23TRA.TR.TRACE_TRDATA_CONFIG_0", l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_0));
        fapi2::variable_buffer l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_1(24);
        l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_1.insertFromRight<uint64_t>(literal_0xFFFFFF, 0, 24);
        FAPI_TRY(fapi2::putSpy(TGT0, "TCM.TRA.MBA23TRA.TR.TRACE_TRDATA_CONFIG_1", l_TCM_TRA_MBA23TRA_TR_TRACE_TRDATA_CONFIG_1));

    };
fapi_try_exit:
    return fapi2::current_err;
}
