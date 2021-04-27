/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_fbc_tl_disable_gathering.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
//------------------------------------------------------------------------------
///
/// @file p9_sbe_scominit.C
/// @brief Dynamically disable TL data gathering (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 3
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_fbc_tl_disable_gathering.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_fbc_tl_disable_gathering(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)

{
    FAPI_DBG("Entering ...");
    fapi2::buffer<uint64_t> l_scom_data = 0;

    FAPI_DBG("Updating Optical FP01 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_IOE_PB_FP01_CFG, l_scom_data),
             "Error from getScom (PU_IOE_PB_FP01_CFG)");
    l_scom_data.setBit<PU_IOE_PB_FP01_CFG_FP0_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_IOE_PB_FP01_CFG_FP1_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_FP01_CFG, l_scom_data),
             "Error from putScom (PU_IOE_PB_FP01_CFG)");

    FAPI_DBG("Updating Optical FP23 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_IOE_PB_FP23_CFG, l_scom_data),
             "Error from getScom (PU_IOE_PB_FP23_CFG)");
    l_scom_data.setBit<PU_IOE_PB_FP23_CFG_FP2_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_IOE_PB_FP23_CFG_FP3_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_FP23_CFG, l_scom_data),
             "Error from putScom (PU_IOE_PB_FP23_CFG)");

    FAPI_DBG("Updating Optical FP45 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_IOE_PB_FP45_CFG, l_scom_data),
             "Error from getScom (PU_IOE_PB_FP45_CFG)");
    l_scom_data.setBit<PU_IOE_PB_FP45_CFG_FP4_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_IOE_PB_FP45_CFG_FP5_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_FP45_CFG, l_scom_data),
             "Error from putScom (PU_IOE_PB_FP45_CFG)");

    FAPI_DBG("Updating Optical FP67 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_IOE_PB_FP67_CFG, l_scom_data),
             "Error from getScom (PU_IOE_PB_FP67_CFG)");
    l_scom_data.setBit<PU_IOE_PB_FP67_CFG_FP6_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_IOE_PB_FP67_CFG_FP7_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_IOE_PB_FP67_CFG, l_scom_data),
             "Error from putScom (PU_IOE_PB_FP67_CFG)");


    FAPI_DBG("Updating Electrical FP01 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_PB_FP01_CFG, l_scom_data),
             "Error from getScom (PU_PB_FP01_CFG)");
    l_scom_data.setBit<PU_PB_FP01_CFG_FP0_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_PB_FP01_CFG_FP1_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_PB_FP01_CFG, l_scom_data),
             "Error from putScom (PU_PB_FP01_CFG)");

    FAPI_DBG("Updating Electrical FP23 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_PB_FP23_CFG, l_scom_data),
             "Error from getScom (PU_PB_FP23_CFG)");
    l_scom_data.setBit<PU_PB_FP23_CFG_FP2_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_PB_FP23_CFG_FP3_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_PB_FP23_CFG, l_scom_data),
             "Error from putScom (PU_PB_FP23_CFG)");

    FAPI_DBG("Updating Electrical FP45 TL register...");
    FAPI_TRY(fapi2::getScom(i_target, PU_PB_FP45_CFG, l_scom_data),
             "Error from getScom (PU_PB_FP45_CFG)");
    l_scom_data.setBit<PU_PB_FP45_CFG_FP4_DISABLE_GATHERING>();
    l_scom_data.setBit<PU_PB_FP45_CFG_FP5_DISABLE_GATHERING>();
    FAPI_TRY(fapi2::putScom(i_target, PU_PB_FP45_CFG, l_scom_data),
             "Error from putScom (PU_PB_FP45_CFG)");

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;

}
