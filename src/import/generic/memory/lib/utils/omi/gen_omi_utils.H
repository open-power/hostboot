/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/generic/memory/lib/utils/omi/gen_omi_utils.H $     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2022                        */
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
/// @file gen_omi_utils.H
/// @brief OMI utility functions
///
// *HWP HWP Owner: Geetha Pisapati <Geetha.Pisapati@ibm.com>
// *HWP HWP Backup: Louis Stermole <stermole@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 3
// *HWP Consumed by: Memory
// EKB-Mirror-To: hostboot

#ifndef _GEN_OMI_UTILS_H_
#define _GEN_OMI_UTILS_H_

#include <fapi2.H>
#include <generic/memory/lib/utils/omi/gen_omi_traits.H>
#include <generic/memory/lib/mss_generic_attribute_getters.H>
#include <generic/memory/lib/utils/mss_generic_check.H>


namespace mss
{
namespace omi
{
///
/// @brief Set up the OMI object handles for intrp_req commands
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<mss::mc_type MC, typename TT = mss::omi::omiTraits<MC> >
inline fapi2::ReturnCode setup_obj_handles(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::ATTR_MSS_OCMB_CHECKSTOP_OBJ_HANDLE_Type l_checkstop_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_RECOV_OBJ_HANDLE_Type l_recov_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_SPECATTN_OBJ_HANDLE_Type l_specattn_obj_handle = 0;
    fapi2::ATTR_MSS_OCMB_APPINTR_OBJ_HANDLE_Type l_appintr_obj_handle = 0;

    FAPI_TRY(mss::attr::get_ocmb_checkstop_obj_handle(l_checkstop_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_recov_obj_handle(l_recov_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_specattn_obj_handle(l_specattn_obj_handle));
    FAPI_TRY(mss::attr::get_ocmb_appintr_obj_handle(l_appintr_obj_handle));

    FAPI_DBG(TARGTIDFORMAT " Setting up OMI object handles in TLXT_TLXTINTHLD", TARGTID);

    FAPI_TRY( fapi2::putScom(i_target, TT::TLXT_TLXTINTHLD0, l_checkstop_obj_handle),
              "Error writing TLXT_TLXTINTHLD0 on " TARGTIDFORMAT, TARGTID );
    FAPI_TRY( fapi2::putScom(i_target, TT::TLXT_TLXTINTHLD1, l_recov_obj_handle),
              "Error writing TLXT_TLXTINTHLD1 on " TARGTIDFORMAT, TARGTID );
    FAPI_TRY( fapi2::putScom(i_target, TT::TLXT_TLXTINTHLD2, l_specattn_obj_handle),
              "Error writing TLXT_TLXTINTHLD2 on " TARGTIDFORMAT, TARGTID );
    FAPI_TRY( fapi2::putScom(i_target, TT::TLXT_TLXTINTHLD3, l_appintr_obj_handle),
              "Error writing TLXT_TLXTINTHLD3 on " TARGTIDFORMAT, TARGTID );

fapi_try_exit:
    return fapi2::current_err;
}

///
/// @brief Set up the OMI interrupt command flags
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success
///
template<mss::mc_type MC, typename TT = mss::omi::omiTraits<MC> >
inline fapi2::ReturnCode setup_int_cmd_flags(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    constexpr uint8_t CHECKSTOP_COMMAND_FLAG = 0;
    constexpr uint8_t RECOV_COMMAND_FLAG = 1;
    constexpr uint8_t SPECATTN_COMMAND_FLAG = 2;
    constexpr uint8_t APPINTR_COMMAND_FLAG = 3;

    fapi2::buffer<uint64_t> l_data;

    FAPI_DBG("%s Setting up OMI interrupt command flags in TLXT_REGS_TLXCFG1", mss::c_str(i_target));

    FAPI_TRY( fapi2::getScom(i_target, TT::TLXT_REGS_TLXCFG1, l_data),
              "Error reading TLXT_TLXCFG1 on %s", mss::c_str(i_target));
    l_data.insertFromRight<TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0,
                           TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_0_LEN>(CHECKSTOP_COMMAND_FLAG);
    l_data.insertFromRight<TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1,
                           TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_1_LEN>(RECOV_COMMAND_FLAG);
    l_data.insertFromRight<TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2,
                           TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_2_LEN>(SPECATTN_COMMAND_FLAG);
    l_data.insertFromRight<TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3,
                           TT::TLXT_REGS_TLXCFG1_TLXT_INTRP_CMDFLAG_3_LEN>(APPINTR_COMMAND_FLAG);
    FAPI_TRY( fapi2::putScom(i_target, TT::TLXT_REGS_TLXCFG1, l_data),
              "Error writing TLXT_TLXCFG1 on %s", mss::c_str(i_target));

fapi_try_exit:
    return fapi2::current_err;
}

} //end omi ns

namespace check
{
///
/// @brief Check the MFIR_ACTAG_PASID_CFG_ERR field
/// @param[in] i_target OCMB target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff success, else error code
///
template<mss::mc_type MC, typename TT = mss::omi::omiTraits<MC> >
inline fapi2::ReturnCode check_mfir_actag_pasid_cfg(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_reg_data = 0;
    fapi2::ReturnCode l_rc = fapi2::FAPI2_RC_SUCCESS;

    // Reading from the register into l_reg_data
    FAPI_TRY(mss::getScom(i_target, TT::MMIO_MFIR_RW_WCLEAR, l_reg_data));


    FAPI_ASSERT(!l_reg_data.getBit<TT::ACTAG_PASID_CFG_ERR>(),
                fapi2::ACTAG_PASID_CONFIG_INVALID()
                .set_OCMB_TARGET(i_target),
                "MFIR_ACTAG_PASID_CFG_ERR has been lit due to unsupported configuration in number of acTAGs and PASIDs");
    return l_rc;

fapi_try_exit:
    return fapi2::current_err;
}

} // end check ns
} // end mss ns

#endif
