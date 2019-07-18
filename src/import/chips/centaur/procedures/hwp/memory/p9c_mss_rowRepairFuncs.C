/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_rowRepairFuncs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
#include <p9c_mss_rowRepairFuncs.H>
#include <lib/utils/cumulus_find.H>
#include <generic/memory/lib/utils/c_str.H>

using namespace fapi2;

extern "C"
{
    ReturnCode is_sPPR_supported(
        const Target<TARGET_TYPE_DIMM>& i_target,
        bool& o_spprSupported )
    {
        const auto& l_mba = mss::find_target<fapi2::TARGET_TYPE_MBA>(i_target);
        uint8_t l_my_dimm_index = 0;

        o_spprSupported = true;

        ATTR_ROW_REPAIR_SUPPORTED_MRW_Type l_row_repair_supported_mrw
        {ENUM_ATTR_ROW_REPAIR_SUPPORTED_MRW_SUPPORTED};
        FAPI_TRY ( FAPI_ATTR_GET( fapi2::ATTR_ROW_REPAIR_SUPPORTED_MRW,
                                  Target<TARGET_TYPE_SYSTEM>(),
                                  l_row_repair_supported_mrw ) );

        // If sPPR isn't suppoerted per the MRW, we're done
        if (l_row_repair_supported_mrw != ENUM_ATTR_ROW_REPAIR_SUPPORTED_MRW_SUPPORTED)
        {
            FAPI_INF("%s sPPR is not supported per ATTR_ROW_REPAIR_SUPPORTED_MRW",
                     mss::spd::c_str(i_target));
            o_spprSupported = false;
            return fapi2::FAPI2_RC_SUCCESS;
        }

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, i_target, l_my_dimm_index));

        for (const auto& l_dimm : mss::find_targets<fapi2::TARGET_TYPE_DIMM>(l_mba))
        {
            uint8_t l_dimm_index = 0;

            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CEN_MBA_DIMM, l_dimm, l_dimm_index));

            // If either of the DIMM pair (same DIMM select) doesn't support sPPR, neither can
            if (l_dimm_index == l_my_dimm_index)
            {
                ATTR_ROW_REPAIR_SPPR_SUPPORTED_Type l_row_repair_supported_dimm
                {ENUM_ATTR_ROW_REPAIR_SPPR_SUPPORTED_SUPPORTED};
                FAPI_TRY( FAPI_ATTR_GET( fapi2::ATTR_ROW_REPAIR_SPPR_SUPPORTED,
                                         l_dimm,
                                         l_row_repair_supported_dimm ) );

                if (l_row_repair_supported_dimm != ENUM_ATTR_ROW_REPAIR_SPPR_SUPPORTED_SUPPORTED)
                {
                    FAPI_INF("%s sPPR is not supported per ATTR_ROW_REPAIR_SPPR_SUPPORTED",
                             mss::spd::c_str(l_dimm));
                    o_spprSupported = false;
                    return fapi2::FAPI2_RC_SUCCESS;
                }
            }
        }

        // If we got here it means we've got sPPR support
        return fapi2::FAPI2_RC_SUCCESS;

    fapi_try_exit:
        // If we got here if means something failed, so return "no support" and the error code
        o_spprSupported = false;
        return fapi2::current_err;
    }
}
