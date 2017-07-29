/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_npu_scominit.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_npu_scominit.C
/// @brief Apply SCOM overrides for the NPU, enable NVLINK refclocks
///
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_npu_scominit.H>
#include <p9_npu_scom.H>
#include <p9_nv_ref_clk_enable.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint64_t PU_NPU_SM2_XTS_ATRMISS_POST_P9NDD1 = 0x501164AULL;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// NOTE: description in header
fapi2::ReturnCode p9_npu_scominit(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");

    uint8_t l_npu_enabled;

    // check to see if NPU region in N3 chiplet is enabled
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NPU_REGION_ENABLED,
                           i_target,
                           l_npu_enabled),
             "Error from FAPI_ATTR_GET (ATTR_PROC_NPU_REGION_ENABLED)");

    if (l_npu_enabled)
    {
        fapi2::ReturnCode l_rc;
        fapi2::buffer<uint64_t> l_atrmiss = 0;
        fapi2::ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR_Type l_npu_p9n_dd1;

        // read attribute to determine if P9N DD1 NPU addresses should be used
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR,
                               i_target,
                               l_npu_p9n_dd1),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_SETUP_BARS_NPU_DD1_ADDR)");

        // apply NPU SCOM inits from initfile
        FAPI_DBG("Invoking p9.npu.scom.initfile...");
        FAPI_EXEC_HWP(l_rc,
                      p9_npu_scom,
                      i_target,
                      fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>());

        if (l_rc)
        {
            FAPI_ERR("Error from p9.npu.scom.initfile");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        // apply additional SCOM inits
        l_atrmiss.setBit<PU_NPU_SM2_XTS_ATRMISS_FLAG_MAP>()
        .setBit<PU_NPU_SM2_XTS_ATRMISS_ENA>();

        FAPI_TRY(fapi2::putScomUnderMask(i_target,
                                         ((l_npu_p9n_dd1) ?
                                          (PU_NPU_SM2_XTS_ATRMISS) :
                                          (PU_NPU_SM2_XTS_ATRMISS_POST_P9NDD1)),
                                         l_atrmiss,
                                         l_atrmiss),
                 "Error from putScomUnderMask (0x%08X)",
                 ((l_npu_p9n_dd1) ?
                  (PU_NPU_SM2_XTS_ATRMISS) :
                  (PU_NPU_SM2_XTS_ATRMISS_POST_P9NDD1)));

        // enable NVLINK refclocks
        FAPI_DBG("Invoking p9_nv_ref_clk_enable...");
        FAPI_EXEC_HWP(l_rc, p9_nv_ref_clk_enable, i_target);

        if (l_rc)
        {
            FAPI_ERR("Error from p9_nv_ref_clk_enable");
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }
    else
    {
        FAPI_DBG("Skipping NPU initialization");
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}

