/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_edpl.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2024                        */
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
///------------------------------------------------------------------------------
/// @file ody_omi_edpl.C
/// @brief Enables OMI DL EDPL
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------
// EKB-Mirror-To: hostboot

#include <ody_omi_edpl.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi.H>
#include <ody_scom_ody.H>
#include <ody_fir_lib.H>

SCOMT_OMI_USE_D_REG_DL0_CONFIG1
SCOMT_OMI_USE_D_REG_DL0_EDPL_MAX_COUNT

///
/// @brief OMI EDPL Enable
///
/// @param[in] i_target Chip target to start
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
fapi2::ReturnCode ody_omi_edpl(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                               const bool i_edpl_enable)
{
    FAPI_DBG("Starting ody_omi_edpl");

    using namespace scomt::omi;
    using namespace scomt::ody;

    D_REG_DL0_CONFIG1_t l_dl0_config1;
    D_REG_DL0_EDPL_MAX_COUNT_t l_edpl_max_count = 0xFFFFFFFFFFFFFFFFull;

    // Clear EDPL Max Count by Writing to '1's
    FAPI_TRY(l_edpl_max_count.putScom(i_target));

    FAPI_TRY(l_dl0_config1.getScom(i_target));

    if (i_edpl_enable)
    {
        l_dl0_config1.set_EDPL_THRESHOLD(7); // 7: 128 Errors
    }
    else
    {
        l_dl0_config1.set_EDPL_THRESHOLD(0); // 0: 0 Errors
    }

    FAPI_TRY(l_dl0_config1.putScom(i_target));

fapi_try_exit:
    FAPI_DBG("End ody_omi_edpl");
    return fapi2::current_err;
}
