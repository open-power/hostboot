/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/sppe/ody_code_getlevels.C $ */
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
// EKB-Mirror-To: hostboot

///
/// @file ody_code_getlevels.C
/// @brief Odyssey Code Get Levels
///
// *HWP Owner: Hostboot Team
// *HWP Backup: SBE Team
// *HWP Level: 1
// *HWP Consumed by: HB:Cronus

#include <fapi2.H>
#include <fapi2_subroutine_executor.H>
#include <ody_code_update.H>
#include <ody_chipop_codeupdate.H>
#include <ody_chipop_getcodelevels.H>

#define DC99

extern "C"
{

///
/// @brief Execute one or more chipops to perform a code update of the Odyssey
///       firmware images.
///
    fapi2::ReturnCode ody_code_getlevels(
        const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_ocmb,
        std::vector<sppeCLIP_t>& o_curVersions )
    {
        fapi2::ReturnCode l_rc;
        char l_targStr[fapi2::MAX_ECMD_STRING_LEN] = {0};
        fapi2::toString(i_ocmb, l_targStr, sizeof(l_targStr));
        FAPI_INF("ENTER> ody_code_getlevels: Ody=%s", l_targStr);

        FAPI_CALL_SUBROUTINE(l_rc,
                             ody_chipop_getcodelevels,
                             i_ocmb,
                             o_curVersions);
        FAPI_TRY(l_rc,
                 "Error from ody_chipop_getcodelevels");

        // Print and save off the current versions to compare later
        for( auto l_cur : o_curVersions )
        {
            FAPI_DBG("Current: type=%d, hash : %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X %.2X",
                     l_cur.type,
                     l_cur.hash.x[0], l_cur.hash.x[1], l_cur.hash.x[2], l_cur.hash.x[3],
                     l_cur.hash.x[4], l_cur.hash.x[5], l_cur.hash.x[6], l_cur.hash.x[7],
                     l_cur.hash.x[8], l_cur.hash.x[9], l_cur.hash.x[10], l_cur.hash.x[11],
                     l_cur.hash.x[12], l_cur.hash.x[13], l_cur.hash.x[14], l_cur.hash.x[15]);
        }

    fapi_try_exit:
        FAPI_INF("EXIT> ody_code_getlevels: Ody=%s", l_targStr);

        return fapi2::current_err;
    }

} //extern "C"
