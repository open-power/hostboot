/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_rng_init_phase2.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2020                        */
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
/// @file p10_rng_init_phase2.C
/// @brief Perform NX RNG Phase 2 initialization (FAPI2)
///

//
// *HWP HWP Owner: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Owner: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: Cronus, HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_rng_init_phase2.H>
#include <p10_scom_proc.H>
#include <p10_scom_perv_8.H>
#include <p10_fbc_utils.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------
const uint8_t ADDR_SHIFT = 12;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p10_rng_init_phase2(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_INF("Start");
    fapi2::buffer<uint64_t> l_rng_cfg_data;
    fapi2::buffer<uint64_t> l_rng_bar_data;
    fapi2::buffer<uint64_t> l_rng_failed_int_data;
    fapi2::buffer<uint64_t> l_security_switch_data;

    uint64_t l_rng_cfg_self_test_hard_fail_status = 0;
    uint8_t  l_nx_rng_bar_enable = 0;
    uint64_t l_nx_rng_bar_addr = 0;
    uint64_t l_nx_rng_bar_base_addr_offset = 0;
    uint8_t  l_nx_rng_failed_int_enable = 0;
    uint64_t l_nx_rng_failed_int_addr = 0;
    uint64_t l_base_addr_nm0 = 0;
    uint64_t l_base_addr_nm1 = 0;
    uint64_t l_base_addr_m = 0;
    uint64_t l_base_addr_mmio = 0;

    // 5. RNG is allowed to run for M cycles (M = enough time to complete init;
    // recommend 1 second of time).
    // NOTE: accomplished by delay in execution time between phase1/phase2 HWPs

    FAPI_TRY(GET_NX_PBI_RNG_CFG(i_target, l_rng_cfg_data));

    // 6. Host boot checks RNG fail bits again and if a fail is detected
    // then RNG is declared broken

    FAPI_DBG("Checking RNG fail status...");
    // exit if failure is reported in self test hard fail status field
    GET_NX_PBI_RNG_CFG_FAIL_REG(l_rng_cfg_data, l_rng_cfg_self_test_hard_fail_status);
    FAPI_ASSERT(!l_rng_cfg_self_test_hard_fail_status,
                fapi2::P10_RNG_INIT_SELF_TEST_FAILED_ERR().
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
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_ENABLE,
                           i_target,
                           l_nx_rng_bar_enable),
             "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_ENABLE)");

    FAPI_TRY(p10_fbc_utils_get_chip_base_address(i_target,
             EFF_TOPOLOGY_ID,
             l_base_addr_nm0,
             l_base_addr_nm1,
             l_base_addr_m,
             l_base_addr_mmio),
             "Error from p10_fbc_utils_get_chip_base_address");

    // get RNG BAR addr
    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_BAR_BASE_ADDR_OFFSET,
                           i_target.getParent<fapi2::TARGET_TYPE_SYSTEM>(),
                           l_nx_rng_bar_base_addr_offset),
             "Error from FAPI_ATTR_GET (ATTR_PROC_NX_BAR_BASE_ADDR_OFFSET)");

    // caculate the NX RNG BAR ADDR based on the bar addr offset
    l_nx_rng_bar_addr = l_base_addr_mmio + l_nx_rng_bar_base_addr_offset;

    FAPI_DBG("FBC_Util returned mmio base address of: 0x%016llx", l_base_addr_mmio);
    FAPI_DBG("Base nx offset:                         0x%016llx", l_nx_rng_bar_base_addr_offset);
    FAPI_DBG("Calculated offset:                      0x%016llx", l_nx_rng_bar_addr);

    if (l_nx_rng_bar_enable == fapi2::ENUM_ATTR_PROC_NX_RNG_BAR_ENABLE_ENABLE)
    {
        FAPI_TRY(PREP_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(i_target));
        // map NX RNG MMIO BAR

        SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR((l_nx_rng_bar_addr >> ADDR_SHIFT), l_rng_bar_data);
        SET_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR_MMIO_BAR_ENABLE(l_rng_bar_data);

        FAPI_TRY(PUT_NX_PBI_CQ_WRAP_NXCQ_SCOM_MMIO_BAR(i_target, l_rng_bar_data));

        // map NX RNG failed interrupt address
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_FAILED_INT_ENABLE,
                               i_target,
                               l_nx_rng_failed_int_enable),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_RNG_FAILED_INT_ENABLE)");
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_PROC_NX_RNG_FAILED_INT_ADDR,
                               i_target,
                               l_nx_rng_failed_int_addr),
                 "Error from FAPI_ATTR_GET (ATTR_PROC_NX_RNG_FAILED_INT_ADDR)");

        if (l_nx_rng_failed_int_enable ==
            fapi2::ENUM_ATTR_PROC_NX_RNG_FAILED_INT_ENABLE_ENABLE)
        {
            FAPI_TRY(PREP_NX_PBI_UMAC_RNG_FAILED_INT(i_target));

            SET_NX_PBI_UMAC_RNG_FAILED_INT_ENABLE(l_rng_failed_int_data);
            SET_NX_PBI_UMAC_RNG_FAILED_INT_ADDRESS((l_nx_rng_failed_int_addr >> ADDR_SHIFT), l_rng_failed_int_data);

            FAPI_TRY(PUT_NX_PBI_UMAC_RNG_FAILED_INT(i_target, l_rng_failed_int_data));
        }
        else
        {
            FAPI_DBG("Skipping setup of NX RNG Failed Interrupt Address Register");
        }
    }
    else
    {
        FAPI_DBG("Skipping NX RNG BAR programming!");
    }

    // set NX RNG enable
    FAPI_TRY(PREP_NX_PBI_RNG_CFG(i_target));
    SET_NX_PBI_RNG_CFG_RNG_ENABLE(l_rng_cfg_data);
    FAPI_TRY(PUT_NX_PBI_RNG_CFG(i_target, l_rng_cfg_data));

    // 8. Host boot sets the NX “sticky bit” that asserts
    // tc_nx_block_rng_scom_wr. If tc_nx_block_rng_scom_wr = 1 writes to RNG
    // SCOM register addresses 32 - 38 and 40 are blocked. An attempted
    // write sets Power-Bus Interface FIR Data Register[Write to RNG SCOM
    // reg detected when writes disabled].

    // set NX sticky bit to block future RNG SCOM writes
    // (tc_nx_block_rng_scom_wr)
    FAPI_TRY(scomt::perv::GET_OTPC_M_SECURITY_SWITCH_REGISTER(i_target, l_security_switch_data));

    scomt::perv::SET_OTPC_M_SECURITY_SWITCH_REGISTER_NX_RAND_NUM_GEN_LOCK(l_security_switch_data);

    FAPI_TRY(scomt::perv::PUT_OTPC_M_SECURITY_SWITCH_REGISTER(i_target, l_security_switch_data));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
