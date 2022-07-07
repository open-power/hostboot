/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/memory/ody_getidec.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
/// @file ody_getidec.C
/// @brief Contains function to lookup Chip ID and EC values of Odyssey Chip
///
/// *HWP HWP Owner: Thi Tran thi@us.ibm.com
/// *HWP HWP Backup: <none>
/// *HWP Team: VBU
/// *HWP Level: 2
/// *HWP Consumed by: Hostboot / Cronus

#include <fapi2.H>
#include <ody_scom_ody.H>
#include <ody_getidec.H>
#include <lib/shared/ody_consts.H>
#include <generic/memory/lib/utils/c_str.H>

extern "C"
{

    SCOMT_ODY_USE_T_CFAM_FSI_W_FSI2PIB_CHIPID;

    fapi2::ReturnCode ody_getidec(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target,
                                  uint16_t& o_chipId,
                                  uint8_t& o_chipEc)
    {
        FAPI_DBG("ody_getidec: Entering...");
        using namespace scomt::ody;
        T_CFAM_FSI_W_FSI2PIB_CHIPID_t CHIP_IDEC;

        // Reading CFAM chip id reg
        FAPI_TRY(CHIP_IDEC.getCfam(i_target),
                 "Error reading CFAM chip IDEC reg for %s.",  mss::c_str(i_target));
        CHIP_IDEC.extractToRight<mss::ody::idec_consts::MAJOR_EC_BIT_START,
                                 mss::ody::idec_consts::MAJOR_EC_BIT_LENGTH>(o_chipEc);
        CHIP_IDEC.extractToRight<mss::ody::idec_consts::CHIPID_BIT_START,
                                 mss::ody::idec_consts::CHIPID_BIT_LENGTH>(o_chipId);
        FAPI_INF("Target %s: EC 0x%.02x   ChipId 0x%.04x", mss::c_str(i_target), o_chipEc, o_chipId);

    fapi_try_exit:
        FAPI_DBG("ody_getidec: Exiting.");
        return fapi2::current_err;
    }

} // extern "C"
