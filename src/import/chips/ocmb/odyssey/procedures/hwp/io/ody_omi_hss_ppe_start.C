/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_ppe_start.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2022,2023                        */
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
/// @file ody_omi_hss_ppe_start.C
/// @brief Odyssey HSS PPE start HWP
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_ppe_start.H>
#include <fapi2_subroutine_executor.H>
#include <ody_io_ppe_common.H>
#include <ody_scom_omi_ioo.H>
#include <io_fir_lib.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_ppe_start(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start - ODY PPE Start");

    io_ppe_regs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_regs(PHY_PPE_WRAP0_ARB_CSAR,
            PHY_PPE_WRAP0_ARB_CSDR,
            PHY_ODY_OMI_BASE);
    io_ppe_firs<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_firs(FIR_SCOM_LFIR_RW_WCLEAR_REG, FIR_DL0_ERROR_MASK,
            FIR_DL0_ERROR_ACTION, FIR_MC_OMI_RW_WCLEAR_REG,
            FIR_DL0_SKIT_CTL, FIR_TLX_RW_WCLEAR);

    ody_io::io_ppe_common<fapi2::TARGET_TYPE_OCMB_CHIP> l_ppe_common(&l_ppe_regs);

    FAPI_TRY(l_ppe_common.ppe_start(i_target));
    FAPI_TRY(l_ppe_firs.ioppe_fir_set_post_start(i_target));

fapi_try_exit :
    FAPI_DBG("End");
    return fapi2::current_err;
}
