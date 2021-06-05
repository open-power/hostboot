/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/corecache/p10_ncu_enable_darn.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2021                        */
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
/// @file  p10_ncu_enable_darn.C
/// @brief Enable DARN instruction
///
/// *HWP HW Maintainer: Joe McGill       <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Prem Shanker Jha <premjha2@in.ibm.com>
/// *HWP Consumed by  : HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <p10_ncu_enable_darn.H>
#include <p10_fbc_utils.H>
#include <p10_scom_c.H>
#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Procedure: p10_ncu_enable_darn
//------------------------------------------------------------------------------

fapi2::ReturnCode p10_ncu_enable_darn(
    const fapi2::Target <fapi2::TARGET_TYPE_CORE> i_core_target,
    const fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> i_chip_target)
{
    FAPI_INF(">>p10_ncu_enable_darn");

    using namespace scomt::c;
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_darn_bar;
    uint64_t l_nx_rng_bar;

    // skip enablement on an ECO target -- the RNG will never be used
    // as the core will never be running instructions
    fapi2::ATTR_ECO_MODE_Type l_eco_mode = fapi2::ENUM_ATTR_ECO_MODE_DISABLED;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE, i_core_target, l_eco_mode));

    if (l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_ENABLED)
    {
        FAPI_INF("Skipping enablement on ECO core target");
        goto fapi_try_exit;
    }

    // query attributes on chip hosting RNG we want this core to
    // target
    {
        fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE_Type l_nx_rng_bar_enable =
            fapi2::ENUM_ATTR_PROC_NX_RNG_BAR_ENABLE_DISABLE;
        fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET_Type l_nx_rng_bar_offset = 0;
        uint64_t l_base_addr_nm0 = 0;
        uint64_t l_base_addr_nm1 = 0;
        uint64_t l_base_addr_m = 0;
        uint64_t l_base_addr_mmio = 0;

        // ensure RNG is enabled
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE,
                               i_chip_target,
                               l_nx_rng_bar_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_ENABLE)");

        FAPI_ASSERT(fapi2::ENUM_ATTR_PROC_NX_RNG_BAR_ENABLE_ENABLE ==
                    l_nx_rng_bar_enable,
                    fapi2::P10_NCU_ENABLE_DARN_RNG_DISABLED()
                    .set_CORE_TARGET(i_core_target)
                    .set_CHIP_TARGET(i_chip_target),
                    "Target RNG is not enabled");

        // obtain base of chip MMIO address space
        FAPI_TRY(p10_fbc_utils_get_chip_base_address(i_chip_target,
                 EFF_TOPOLOGY_ID,
                 l_base_addr_nm0,
                 l_base_addr_nm1,
                 l_base_addr_m,
                 l_base_addr_mmio),
                 "Error from p10_fbc_utils_get_chip_base_address");

        // get RNG BAR addr offset
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET,
                               i_chip_target.getParent<fapi2::TARGET_TYPE_SYSTEM>(),
                               l_nx_rng_bar_offset),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_BASE_ADDR_OFFSET)");

        // finalize address
        l_nx_rng_bar = l_base_addr_mmio + l_nx_rng_bar_offset;
    }

    // write NCU BAR
    {
        l_darn_bar = l_nx_rng_bar;
        PREP_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG(i_core_target);
        SET_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG_EN(l_darn_bar);
        FAPI_TRY(PUT_NC_NCMISC_NCSCOMS_NCU_DARN_BAR_REG(i_core_target, l_darn_bar));
    }

fapi_try_exit:
    FAPI_INF("<<p10_ncu_enable_darn");
    return fapi2::current_err;
}
