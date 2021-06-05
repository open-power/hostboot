/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_sbe_purge_hb.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2019,2021                        */
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
/// @file p10_sbe_purge_hb.C
/// @brief Purges active/backing caches and resets contained mode
///        configuration, as part of HB cache contained
///        exit sequence

//
// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Maintainer: Raja Das <rajadas2@in.ibm.com>
// *HWP Consumed by  : SBE
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_sbe_purge_hb.H>
#include <p10_l2_flush.H>
#include <p10_l3_flush.H>
#include <p10_scom_c.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_sbe_purge_hb(
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& i_active_core_targets,
    const std::vector<fapi2::Target<fapi2::TARGET_TYPE_CORE>>& i_backing_cache_targets)
{
    using namespace scomt::c;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;
    p10core::purgeData_t l_l2_purge_ctl;

    FAPI_DBG("Start");

    for (const auto& l_core_target : i_active_core_targets)
    {
        fapi2::buffer<uint64_t> l_lco_target_id_ctl_reg = 0;
        fapi2::buffer<uint64_t> l_l3_fir_mask_or_reg = 0;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num;
        fapi2::ATTR_ECO_MODE_Type l_eco_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_target,
                               l_core_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, active)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE,
                               l_core_target,
                               l_eco_mode),
                 "Error from FAPI_ATTR_GET (ATTR_ECO_MODE, active)");

        FAPI_ASSERT(l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_DISABLED,
                    fapi2::P10_SBE_PURGE_HB_ECO_MODE_ERR()
                    .set_TARGET(l_core_target),
                    "Core %d is marked as ECO, but is in set of active cores!",
                    l_core_num);

        FAPI_EXEC_HWP(l_rc,
                      p10_l2_flush,
                      l_core_target,
                      l_l2_purge_ctl); // default is full purge

        if (l_rc)
        {
            FAPI_ERR("Error from p10_l2_flush (active core: %d)", l_core_num);
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        FAPI_EXEC_HWP(l_rc,
                      p10_l3_flush,
                      l_core_target,
                      L3_FULL_PURGE,  // full purge
                      0ULL);          // address is unused for full purge

        if (l_rc)
        {
            FAPI_ERR("Error from p10_l3_flush (active core: %d)", l_core_num);
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }

        // disable LCO castouts to backing caches
        FAPI_TRY(GET_L3_MISC_L3CERRS_BACKING_CTL_REG(l_core_target, l_lco_target_id_ctl_reg));
        CLEAR_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(l_lco_target_id_ctl_reg);
        FAPI_TRY(PUT_L3_MISC_L3CERRS_BACKING_CTL_REG(l_core_target, l_lco_target_id_ctl_reg));

        // mask L3 FIR tracking contained mode violations
        FAPI_TRY(PREP_L3_MISC_L3CERRS_FIR_REG_RW(l_core_target));
        SET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(l_l3_fir_mask_or_reg);
        FAPI_TRY(PREP_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(l_core_target));
        FAPI_TRY(PUT_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(l_core_target, l_l3_fir_mask_or_reg));
    }

    for (const auto& l_core_target : i_backing_cache_targets)
    {
        fapi2::buffer<uint64_t> l_lco_target_id_ctl_reg = 0;
        fapi2::buffer<uint64_t> l_l3_fir_mask_or_reg = 0;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_core_num;
        fapi2::ATTR_ECO_MODE_Type l_eco_mode;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                               l_core_target,
                               l_core_num),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS, backing)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_ECO_MODE,
                               l_core_target,
                               l_eco_mode),
                 "Error from FAPI_ATTR_GET (ATTR_ECO_MODE, backing)");

        FAPI_ASSERT(l_eco_mode == fapi2::ENUM_ATTR_ECO_MODE_DISABLED,
                    fapi2::P10_SBE_PURGE_HB_ECO_MODE_ERR()
                    .set_TARGET(l_core_target),
                    "Core %d is marked as ECO, but is in set of backing caches!",
                    l_core_num);

        // mask L3 FIR tracking contained mode violations
        FAPI_TRY(PREP_L3_MISC_L3CERRS_FIR_REG_RW(l_core_target));
        SET_L3_MISC_L3CERRS_FIR_REG_CHIP_CONTAINED_ERR(l_l3_fir_mask_or_reg);
        FAPI_TRY(PREP_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(l_core_target));
        FAPI_TRY(PUT_L3_MISC_L3CERRS_FIR_MASK_REG_WO_OR(l_core_target, l_l3_fir_mask_or_reg));

        // clear to ensure castout to memory is attempted
        FAPI_TRY(GET_L3_MISC_L3CERRS_BACKING_CTL_REG(l_core_target, l_lco_target_id_ctl_reg));
        CLEAR_L3_MISC_L3CERRS_BACKING_CTL_REG_CASTOUT_TO_BACKING_L3_EN_CFG(l_lco_target_id_ctl_reg);
        FAPI_TRY(PUT_L3_MISC_L3CERRS_BACKING_CTL_REG(l_core_target, l_lco_target_id_ctl_reg));

        FAPI_EXEC_HWP(l_rc,
                      p10_l3_flush,
                      l_core_target,
                      L3_FULL_PURGE,  // full purge
                      0ULL);          // address is unused for full purge

        if (l_rc)
        {
            FAPI_ERR("Error from p10_l3_flush (backing cache: %d)", l_core_num);
            fapi2::current_err = l_rc;
            goto fapi_try_exit;
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
