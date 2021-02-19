/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_init_mem_encryption.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2021                        */
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
/// @file p10_omi_setup_bars.H
/// @brief Setup p10 Memory Encryption Registers as set by attribute
///
///

// *HWP HWP Owner: Lilith Hale Lilith.Hale@ibm.com
// *HWP FW Owner:
// *HWP Consumed by: HB

//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>
#include <p10_init_mem_encryption.H>
#include <p10_scom_mc.H>
#include <p10_scom_mcc.H>


//-----------------------------------------------------------------------------------
// Function definitions
//-----------------------------------------------------------------------------------

fapi2::ReturnCode p10_init_mem_encryption(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> i_target)
{
    FAPI_DBG("Start");
    fapi2::buffer<uint64_t> l_scom_data;
    fapi2::ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_Type l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_MEMORY_ENCRYPTION_ENABLED, i_target,
                           l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED));

    //data
    if ((l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED != fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_DISABLED))
    {
        //Set up MCFGP[0-1]E registers
        l_scom_data = 0;
        l_scom_data |= (uint64_t) 0x1     << (64 - ( 0 +  1)); //MCFGP[0-1]E_ENC_VALID
        l_scom_data |= (uint64_t) 0x1     << (64 - ( 1 +  1)); //MCFGP[0-1]E_ENC_EXTEND_TO_END_OF_RANGE
        l_scom_data |= (uint64_t) 0x7FFFF << (64 - (21 + 19)); //MCFGP[0-1]E_ENC_UPPER_ADDRESS

        for (const auto& l_mc_target : i_target.getChildren<fapi2::TARGET_TYPE_MC>())
        {
            FAPI_TRY(fapi2::putScom(l_mc_target, scomt::mc::SCOMFIR_MCFGP0E, l_scom_data));
            FAPI_TRY(fapi2::putScom(l_mc_target, scomt::mc::SCOMFIR_MCFGP1E, l_scom_data));
            FAPI_TRY(fapi2::putScom(l_mc_target, scomt::mc::SCOMFIR_MCFGPM0E, l_scom_data));
            FAPI_TRY(fapi2::putScom(l_mc_target, scomt::mc::SCOMFIR_MCFGPM1E, l_scom_data));
        }

        //Set up [ENCRYPT,DECRYPT].CRYPTOCFG registers
        l_scom_data = 0;
        l_scom_data |= (uint64_t)  0x1 << (64 - (4 + 1)); //CRYPTO_ENABLE

        if (l_TGT2_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED ==
            fapi2::ENUM_ATTR_PROC_MEMORY_ENCRYPTION_ENABLED_CTR) // Set CTR Mode bit if attribute indicates to
        {
            l_scom_data |= (uint64_t)  0x1 << (64 - (5 + 1)); //CRYPTO_SELECT
        }

        for (const auto& l_mcc_target : i_target.getChildren<fapi2::TARGET_TYPE_MCC>())
        {
            FAPI_TRY(fapi2::putScom(l_mcc_target, scomt::mcc::CRYPTO_DECRYPT_CRYPTOCFG, l_scom_data));
            FAPI_TRY(fapi2::putScom(l_mcc_target, scomt::mcc::CRYPTO_ENCRYPT_CRYPTOCFG, l_scom_data));
        }
    }

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
