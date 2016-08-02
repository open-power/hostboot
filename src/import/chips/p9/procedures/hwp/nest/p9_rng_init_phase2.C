/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_rng_init_phase2.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
/// @file p9_rng_init_phase2.C
/// @brief Perform NX RNG Phase 2 initialization (FAPI2)
///
/// @author Chen Qian <qianqc@cn.ibm.com>
///
//
// *HWP HWP Owner: Chen Qian <qianqc@cn.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p9_rng_init_phase2.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>
#include <p9_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_rng_init_phase2(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");

    fapi2::buffer<uint64_t> l_rng_cfg_data;
    fapi2::buffer<uint64_t> l_rng_bar_data;
    fapi2::buffer<uint64_t> l_rng_failed_int_data;
    fapi2::buffer<uint64_t> l_security_switch_data;

    uint16_t  l_rng_cfg_self_test_hard_fail_status = 0;
    uint8_t   l_nx_rng_bar_enable = 0;
    uint64_t  l_nx_rng_bar_addr = 0;
    uint64_t  l_nx_rng_bar_base_addr_offset = 0;
    uint8_t   l_nx_rng_failed_int_enable = 0;
    uint64_t  l_nx_rng_failed_int_addr = 0;
    uint64_t  l_base_addr_nm0;
    uint64_t  l_base_addr_nm1;
    uint64_t  l_base_addr_m;
    uint64_t  l_base_addr_mmio;

    // 5. RNG is allowed to run for M cycles (M = enough time to complete init; recommend 1 second of time).
    //    NOTE: accomplished by delay in execution time between phase1/phase2 HWPs
    // 6. Host boot checks RNG fail bits again and if a fail is detected then RNG is declared broken

    // get the self test hard fail status in RNG CFG register
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_CFG, l_rng_cfg_data),
             "Error from getScom (NX RNG Status and Control Register)");

    // exit if failure is reported in self test hard fail status field
    l_rng_cfg_data.extractToRight<PU_NX_RNG_CFG_FAIL_REG, PU_NX_RNG_CFG_FAIL_REG_LEN>(l_rng_cfg_self_test_hard_fail_status);
    FAPI_ASSERT(!l_rng_cfg_self_test_hard_fail_status,
                fapi2::P9_RNG_INIT_SELF_TEST_FAILED_ERR().
                set_TARGET(i_target).
                set_SELF_TEST_HARD_FAIL_STATUS(l_rng_cfg_self_test_hard_fail_status),
                "Self test hard fail status indicates failure");

    // 7. Host boot maps RNG BARs (see Section 5.31 RNG BAR on page 185).
    // • NX RNG BAR (not mapped/enabled if RNG is broken)
    // • NCU RNG BAR (always mapped to good RNG)
    // • NX RNG Fail Interrupt Addres

    // self test indicates no hard fail
    // if instructed to map the BAR:
    // - enable NX RNG MMIO BAR and get the bar address attributes
    // - optionally map NX RNG failed interrupt address
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE, i_target, l_nx_rng_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_ENABLE)");
    FAPI_TRY(p9_fbc_utils_get_chip_base_address(i_target,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p9_fbc_utils_get_chip_base_address");

    // get RNG BAR addr
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET, i_target.getParent<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_nx_rng_bar_base_addr_offset),
             "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_BASE_ADDR_OFFSET)");
    // caculate the NX RNG BAR ADDR based on the bar adddr offset
    l_nx_rng_bar_addr = l_base_addr_mmio;
    l_nx_rng_bar_addr += l_nx_rng_bar_base_addr_offset;

    if (l_nx_rng_bar_enable == fapi2::ENUM_ATTR_PROC_NX_RNG_BAR_ENABLE_ENABLE)
    {
        // map NX RNG MMIO BAR
        l_rng_bar_data.setBit<PU_NX_MMIO_BAR_ENABLE>();
        l_rng_bar_data.insert<PU_NX_MMIO_BAR_BAR, PU_NX_MMIO_BAR_BAR_LEN, PU_NX_MMIO_BAR_BAR>(l_nx_rng_bar_addr);
        FAPI_TRY(fapi2::putScom(i_target, PU_NX_MMIO_BAR, l_rng_bar_data),
                 "Error from putScom (PU_NX_MMIO_BAR)");

        // map NX RNG failed interrupt address
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_FAILED_INT_ENABLE,  i_target, l_nx_rng_failed_int_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_RNG_FAILED_INT_ENABLE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_FAILED_INT_ADDR, i_target, l_nx_rng_failed_int_addr),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_RNG_FAILED_INT_ADDR)");

        if (l_nx_rng_failed_int_enable == fapi2::ENUM_ATTR_PROC_NX_RNG_FAILED_INT_ENABLE_ENABLE)
        {
            l_rng_failed_int_data.setBit<PU_RNG_FAILED_INT_ENABLE>();
            l_rng_failed_int_data.insert<PU_RNG_FAILED_INT_ADDRESS, PU_RNG_FAILED_INT_ADDRESS_LEN, PU_RNG_FAILED_INT_ADDRESS>
            (l_nx_rng_failed_int_addr);

            FAPI_TRY(fapi2::putScom(i_target, PU_RNG_FAILED_INT, l_rng_failed_int_data),
                     "Error from putScom (NX RNG Failed Interrupt Address Register");
        }
        else
        {
            FAPI_DBG("Skipping setup of NX RNG Failed Interrupt Address Register");
        }

        // set NX RNG enable
        l_rng_cfg_data.setBit<PU_NX_RNG_CFG_ENABLE>();
        FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_CFG, l_rng_cfg_data),
                 "Error from putScom (NX RNG Status and Control Register)");

        // 8. Host boot sets the NX “sticky bit” that asserts tc_nx_block_rng_scom_wr. If tc_nx_block_rng_scom_wr =
        // 1 writes to RNG SCOM register addresses 32 - 38 and 40 are blocked. An attempted write sets Power-
        // Bus Interface FIR Data Register[Write to RNG SCOM reg detected when writes disabled].

        // set NX sticky bit to block future RNG SCOM writes (tc_nx_block_rng_scom_wr)
        FAPI_TRY(fapi2::getScom(i_target, PU_SECURITY_SWITCH_REGISTER_SCOM, l_security_switch_data),
                 "Error from getScom (Security Switch Register");
        l_security_switch_data.setBit<PU_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK>();
        FAPI_TRY(fapi2::putScom(i_target, PU_SECURITY_SWITCH_REGISTER_SCOM, l_security_switch_data),
                 "Error from putScom (Security Switch Register");
    }
    else
    {
        FAPI_DBG("Skipping NX RNG BAR programming, RNG function is not enabled!");
    }

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}

