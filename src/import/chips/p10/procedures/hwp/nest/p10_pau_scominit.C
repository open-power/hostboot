/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_pau_scominit.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
/// @file p10_pau_scominit.C
/// @brief Apply SCOM overrides for the PAU unit
///
/// *HWP HW Maintainer: Jenny Huynh <jhuynh@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_pau_scominit.H>
#include <p10_pau_scom.H>
//#include <p10_nv_ref_clk_enable.H>
//#include <p10_misc_scom_addresses.H>
//#include <p10_misc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t PU_PAU_SM2_XTS_ATRMISS_POST_P10NDD1 = 0x501164AULL;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_pau_scominit(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Start");

    fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
    auto l_pau_targets = i_target.getChildren<fapi2::TARGET_TYPE_PAU>();
    char l_tgt_str[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::ReturnCode l_rc;

    for(auto l_pau_target : l_pau_targets)
    {
        fapi2::toString(l_pau_target, l_tgt_str, sizeof(l_tgt_str));

        FAPI_DBG("Invoking p10.pau.scom.initfile on target %s...", l_tgt_str);
        FAPI_EXEC_HWP(l_rc, p10_pau_scom, l_pau_target, i_target, FAPI_SYSTEM);
        FAPI_TRY(l_rc, "Error from p10.pau.scom.initfile");
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
