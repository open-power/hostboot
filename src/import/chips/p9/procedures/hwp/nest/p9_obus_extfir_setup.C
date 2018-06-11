/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_obus_extfir_setup.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2018,2019                        */
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
/// @file p9_obus_extfir_setup.C
/// @brief Manage fabric link iovalid controls (FAPI2)
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
#include <p9_obus_extfir_setup.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


// NOTE: see doxygen comments in header
fapi2::ReturnCode
p9_obus_extfir_setup(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
                     const bool i_o0_smp_active,
                     const bool i_o1_smp_active,
                     const bool i_o2_smp_active,
                     const bool i_o3_smp_active)
{
    FAPI_INF("Start");

    fapi2::buffer<uint64_t> l_fbc_cent_fir;
    fapi2::buffer<uint64_t> l_ras_fir_mask;

    // read FBC center FIR to determine if SBE has unmasked all EXTFIR bits (new
    // behavior)
    FAPI_TRY(fapi2::getScom(i_target, PU_PB_CENT_SM0_PB_CENT_FIR_REG, l_fbc_cent_fir),
             "Error from getScom (PU_PB_CENT_SM0_PB_CENT_FIR_REG)");

    // new SBE code, set mask bits for inactive links
    if (l_fbc_cent_fir.getBit<PU_PB_CENT_SM0_PB_CENT_FIR_MASK_REG_SPARE_14>())
    {
        l_ras_fir_mask.flush<0>();

        if (!i_o0_smp_active)
        {
            l_ras_fir_mask.setBit<PU_PB_CENT_SM1_EXTFIR_REG_PB_X3_FIR_ERR>();
        }

        if (!i_o1_smp_active)
        {
            l_ras_fir_mask.setBit<PU_PB_CENT_SM1_EXTFIR_REG_PB_X4_FIR_ERR>();
        }

        if (!i_o2_smp_active)
        {
            l_ras_fir_mask.setBit<PU_PB_CENT_SM1_EXTFIR_REG_PB_X5_FIR_ERR>();
        }

        if (!i_o3_smp_active)
        {
            l_ras_fir_mask.setBit<PU_PB_CENT_SM1_EXTFIR_REG_PB_X6_FIR_ERR>();
        }

        FAPI_TRY(fapi2::putScom(i_target, PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR, l_ras_fir_mask),
                 "Error writing RAS FIR mask register (PU_PB_CENT_SM1_EXTFIR_MASK_REG_OR)!");
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
