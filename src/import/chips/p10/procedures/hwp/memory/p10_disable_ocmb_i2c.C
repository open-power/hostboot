/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/memory/p10_disable_ocmb_i2c.C $ */
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

//------------------------------------------------------------------------------
///
/// @file p10_disable_ocmb_i2c.H
/// @brief Enable the security block for i2c access to the OCMB devices
///
//------------------------------------------------------------------------------
/// *HWP HW Maintainer: Santosh Balasubramanian <sbalasub@in.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
//------------------------------------------------------------------------------

#include <fapi2.H>
#include "p10_disable_ocmb_i2c.H"
#include <p10_scom_perv_7.H>
#include <p10_scom_perv_8.H>
#include <p10_scom_proc_f.H>
#include <p10_scom_proc_9.H>
#include <p10_scom_proc_c.H>

///
/// @brief Enable the security block for i2c access to the OCMB devices
///
fapi2::ReturnCode p10_disable_ocmb_i2c( const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_proc,
                                        uint8_t i_engine_A_devAddr,
                                        uint8_t i_engine_B_devAddr,
                                        uint8_t i_engine_C_devAddr,
                                        uint8_t i_engine_E_devAddr,
                                        uint64_t i_portlist_a,
                                        uint64_t i_portlist_b,
                                        uint64_t i_portlist_c,
                                        uint64_t i_portlist_e,
                                        bool i_force,
                                        bool i_SUL_setup,
                                        bool i_SOL_setup )
{
    FAPI_DBG("p10_disable_ocmb_i2c : Entering ... A=0x%X B=0x%X C=0x%X E=0x%X "
             "portlist_a=0x%llx portlist_b=0x%llx portlist_c=0x%llx portlist_e=0x%llx ",
             i_engine_A_devAddr, i_engine_B_devAddr, i_engine_C_devAddr, i_engine_E_devAddr,
             i_portlist_a, i_portlist_b, i_portlist_c, i_portlist_e);

    FAPI_DBG("p10_disable_ocmb_i2c : Entering ... i_force=%d i_SUL_setup=%d i_SOL_setup=%d",
             i_force, i_SUL_setup, i_SOL_setup);
    using namespace scomt;
    using namespace scomt::perv;
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64;
    bool l_in_secure_mode = false;

    // bits 0:17 PORT_PROTECTION bits
    // The caller will provide the uint64_t port mask
    // i_portlist_a i_portlist_b i_portlist_c i_portlist_e

    // bits 25:31  MASK_ID (MASK to use for DEVADDR range to protect)
    // This value is currently always ZERO, so the ~MASK hits ALL bits to
    // prohibit read and write of the protected DEVADDR defined in bits 18:24
    // Since bit mask is always ZERO no need to specify explictly
    //uint64_t L_ENGINE_A_MASK = 0x0000000000000000;  //
    //uint64_t L_ENGINE_B_MASK = 0x0000000000000000;  //
    //uint64_t L_ENGINE_C_MASK = 0x0000000000000000;  //
    //uint64_t L_ENGINE_E_MASK = 0x0000000000000000;  //

    // bits 18:24 SLV_ID (7 BIT DEVADDR to PROTECT)
    // The caller will provide the uint8_t devAddr that will be shifted
    // into the proper bits, i.e. i_engine_A_devAddr shifted to bits 18:24

    fapi2::ATTR_CHIP_EC_FEATURE_OCMB_SECURITY_SUPPORTED_Type l_ec_ocmb_security_supported;
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_OCMB_SECURITY_SUPPORTED,
                           i_proc, l_ec_ocmb_security_supported));
    FAPI_DBG("ATTR_CHIP_EC_FEATURE_OCMB_SECURITY_SUPPORTED=%d", l_ec_ocmb_security_supported);

    // only enter the DD2 register manipulation if EC level indicates proper
    if (l_ec_ocmb_security_supported)
    {
        //Get value of SAB bit to see if chip is in secure mode
        FAPI_TRY(PREP_OTPC_M_SECURITY_SWITCH_REGISTER(i_proc));
        FAPI_TRY(GET_OTPC_M_SECURITY_SWITCH_REGISTER(i_proc, l_data64));

        l_in_secure_mode = GET_OTPC_M_SECURITY_SWITCH_REGISTER_SECURE_ACCESS(l_data64);

        if ((i_SUL_setup && l_in_secure_mode) || i_force)
        {
            FAPI_TRY(PREP_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER(i_proc));
            FAPI_TRY(PUT_FSXCOMP_FSXLOG_I2CDEVICEID_REGISTER(i_proc,
                     ( (static_cast<uint64_t>(i_engine_A_devAddr) ) << 38 ) | i_portlist_a ));
            FAPI_INF("p10_disable_ocmb_i2c : SUL setup COMPLETE");
        }
        else
        {
            FAPI_INF("p10_disable_ocmb_i2c : SUL setup -NOT- requested -OR- "
                     "Chip not in secure mode - No need to disable i2c access");
        }

        if ((i_SOL_setup && l_in_secure_mode) || i_force)
        {
            FAPI_TRY(PREP_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_B(i_proc));
            FAPI_TRY(PREP_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_C(i_proc));
            FAPI_TRY(PREP_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_E(i_proc));

            FAPI_TRY(PUT_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_B(i_proc,
                     ( (static_cast<uint64_t>(i_engine_B_devAddr) ) << 38 ) | i_portlist_b ));
            FAPI_TRY(PUT_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_C(i_proc,
                     ( (static_cast<uint64_t>(i_engine_C_devAddr) ) << 38 ) | i_portlist_c ));
            FAPI_TRY(PUT_TP_TPCHIP_PIB_OTP_OTPC_M_I2CM_SLVID_CONFIG_REG_E(i_proc,
                     ( (static_cast<uint64_t>(i_engine_E_devAddr) ) << 38 ) | i_portlist_e ));

            //SECURITY_SWITCH_REGISTER is SET only register - hence clearing '0' before setting specific bits
            //To Avoid the issue of a read modified write
            l_data64.flush<0>();

            //13 : SECURITY_SWITCH_SECURE_OCMB_LOCK: TP Spare
            SET_OTPC_M_SECURITY_SWITCH_REGISTER_I2CM_SECURE_OCMB_LOCK(l_data64);

            FAPI_TRY(PUT_OTPC_M_SECURITY_SWITCH_REGISTER(i_proc, l_data64));
            FAPI_INF("p10_disable_ocmb_i2c : SOL setup COMPLETE");
        }
        else
        {
            FAPI_INF("p10_disable_ocmb_i2c : SOL setup -NOT- requested -OR- "
                     "Chip not in secure mode - No need to disable i2c access");
        }
    } // end if l_ocmb_security_supported

fapi_try_exit:
    FAPI_DBG("p10_disable_ocmb_i2c : Exiting ...");
    return fapi2::current_err;

}
