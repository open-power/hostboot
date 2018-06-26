/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/centaur/procedures/hwp/memory/p9c_mss_rowRepairFuncs.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018                             */
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

using namespace fapi2;

extern "C"
{
    ReturnCode __getPairedDimm(
        const Target<TARGET_TYPE_DIMM>& i_target,
        Target<TARGET_TYPE_DIMM>& o_pairedDimm )
    {
        std::vector<Target<TARGET_TYPE_DIMM>> l_dimms;
        Target<TARGET_TYPE_MBA> l_mba;
        uint8_t l_curPs = 0;
        uint8_t l_curDs = 0;

        // get port slct for our current target
        FAPI_TRY( FAPI_ATTR_GET( ATTR_CEN_MBA_PORT, i_target, l_curPs ) );

        // get dimm slct for our current target
        FAPI_TRY( FAPI_ATTR_GET( ATTR_CEN_MBA_DIMM, i_target, l_curDs ) );

        // get parent mba
        l_mba = i_target.getParent<TARGET_TYPE_MBA>();

        // get connected dimms from mba
        l_dimms = l_mba.getChildren<TARGET_TYPE_DIMM>();

        // find the paired dimm
        for ( auto const& dimm : l_dimms )
        {
            uint8_t l_tmpPs = 0;
            FAPI_TRY( FAPI_ATTR_GET( ATTR_CEN_MBA_PORT, dimm, l_tmpPs ) );

            // DIMM on same port slct
            if ( l_tmpPs == l_curPs )
            {
                uint8_t l_tmpDs = 0;
                FAPI_TRY( FAPI_ATTR_GET( ATTR_CEN_MBA_DIMM, dimm, l_tmpDs ) );

                // different DIMM from the current one
                if ( l_tmpDs != l_curDs )
                {
                    // found the paired DIMM
                    o_pairedDimm = dimm;
                    break;
                }
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }

    ReturnCode is_sPPR_supported(
        const Target<TARGET_TYPE_DIMM>& i_target,
        bool& o_spprSupported )
    {
        ATTR_ROW_REPAIR_SUPPORTED_MRW_Type l_rr1;
        FAPI_TRY ( FAPI_ATTR_GET( ATTR_ROW_REPAIR_SUPPORTED_MRW,
                                  Target<TARGET_TYPE_SYSTEM>(), l_rr1 ) );

        ATTR_ROW_REPAIR_SPPR_SUPPORTED_Type l_rr2;
        FAPI_TRY( FAPI_ATTR_GET( ATTR_ROW_REPAIR_SPPR_SUPPORTED, i_target,
                                 l_rr2 ) );

        o_spprSupported = false;

        if ( ENUM_ATTR_ROW_REPAIR_SUPPORTED_MRW_SUPPORTED == l_rr1 &&
             ENUM_ATTR_ROW_REPAIR_SPPR_SUPPORTED_SUPPORTED == l_rr2 )
        {
            // Check paired DIMM as well
            Target<TARGET_TYPE_DIMM> l_pairedDimm;
            FAPI_TRY( __getPairedDimm( i_target, l_pairedDimm ) );

            ATTR_ROW_REPAIR_SPPR_SUPPORTED_Type l_rr3;
            FAPI_TRY( FAPI_ATTR_GET( ATTR_ROW_REPAIR_SPPR_SUPPORTED,
                                     l_pairedDimm, l_rr3 ) );

            if ( ENUM_ATTR_ROW_REPAIR_SPPR_SUPPORTED_SUPPORTED == l_rr3 )
            {
                o_spprSupported = true;
            }
        }

    fapi_try_exit:
        return fapi2::current_err;
    }
}
