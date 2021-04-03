/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/io/p10_io_omi_post_trainadv.C $ */
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
/// @file p10_io_omi_post_trainadv.C
/// @brief Placeholder for OMI PHY post train settings (FAPI2)
///
/// *HWP HW Maintainer: Chris Steffen <cwsteffen@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_io_omi_post_trainadv.H>
#include <p10_omi_scom.H>
#include <p10_omic_scom.H>
#include <p10_scom_pauc.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

/// Main function, see description in header
fapi2::ReturnCode p10_io_omi_post_trainadv(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_DBG("Entering ...");

    for (const auto l_pauc : i_target.getChildren<fapi2::TARGET_TYPE_PAUC>())
    {
        fapi2::buffer<uint64_t> l_fir_clear;
        l_fir_clear.flush<1>().clearBit<scomt::pauc::PHY_SCOM_MAC_FIR_REG_PPE_CODE_RECAL_NOT_RUN>();

        FAPI_TRY(fapi2::putScom(l_pauc, scomt::pauc::PHY_SCOM_MAC_FIR_REG_WO_AND, l_fir_clear));
        FAPI_TRY(fapi2::putScom(l_pauc, scomt::pauc::PHY_SCOM_MAC_FIR_MASK_REG_WO_AND, l_fir_clear));
    }

fapi_try_exit:
    FAPI_DBG("Exiting ...");
    return fapi2::current_err;
}
