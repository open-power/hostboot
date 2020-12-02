/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_rng_init_phase1.C $ */
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
/// @file p10_rng_init_phase1.C
/// @brief Perform NX RNG Phase 1 initialization (FAPI2)
///

//
// *HWP HWP Owner: Nicholas Landi <nlandi@ibm.com>
// *HWP FW Owner: Ilya Smirnov <ismirno@us.ibm.com>
// *HWP Consumed by: Cronus, HB
//

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_rng_init_phase1.H>
#include <p10_scom_proc.H>

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------


//// P10N DD1 DEFINITIONS
// RNG Self Test Register 0 constants
// repetition count match count threshold (3 repeated numbers)
const uint8_t  NX_RNG_ST0_REPTEST_MATCH_TH_VAL                   = 0x01;
// adaptive proportion sample size (8b wide sample)
const uint8_t  NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_VAL               = 0x02;
// adaptive proportion window size (512 size)
const uint8_t  NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_VAL               = 0x01;
// adaptive proportion RRN RNG0 match threshold (50; Assuming H = 5)
const uint16_t NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_VAL         = 0x32;
// adaptive proportion RRN RNG1 match threshold (50; Assuming H = 5)
const uint16_t NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_VAL         = 0x32;
// adaptive proportion CRN RNG0 match threshold (50; Assuming H = 5)
const uint16_t NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_VAL         = 0x32;
// adaptive proportion CRN RNG1 match threshold (50; Assuming H = 5)
const uint16_t NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_VAL         = 0x32;

// RNG Self Test Register 1 constants
// adaptive proportion soft fail threshold (hangpulse ~ 34s; 1 hour / 34s ~ 105 (0x69))
const uint8_t NX_RNG_ST1_SOFT_FAIL_TH_VAL                       = 0x69;
// adaptive proportion 1bit match threshold min (100)
const uint16_t NX_RNG_ST1_1BIT_MATCH_TH_MIN_VAL                 = 0x0064;
// adaptive proportion 1bit match threshold max (415)
const uint16_t NX_RNG_ST1_1BIT_MATCH_TH_MAX_VAL                 = 0x019F;

// RNG Self Test Register 3 constants
// sample rate RRN enable (Use RRNs)
const bool     NX_RNG_ST3_RRN_ENABLE_VAL                        = true;
// sample rate window size (64k -1 size)
const uint8_t  NX_RNG_ST3_WINDOW_SIZE_VAL                       = 0x07;
// sample rate match threshold minimum (28,000)
const uint16_t NX_RNG_ST3_MATCH_TH_MIN_VAL                      = 0x6D60;
// sample rate match threshold maximum (39,050)
const uint16_t NX_RNG_ST3_MATCH_TH_MAX_VAL                      = 0x8CA0;

// RNG Read Delay Parameters Register
// Read Retry Ratio (0 = 31/32, 1 = 15/16, 2 = 29/32 ... 15 = 1/2 ...
//                   31 = disabled)
const uint8_t  NX_RNG_RDELAY_READ_RTY_RATIO_VAL               = 0x1D;
const bool     NX_RNG_RDELAY_LFSR_RESEED_EN_VAL               = true;

// RNG Status And Control Register constants (Applies to both)
const bool     NX_RNG_CFG_CONDITIONER_MASK_TOGGLE_VAL            = false;
// sample rate test enable
const bool     NX_RNG_CFG_SAMPLE_RATE_TEST_ENABLE_VAL            = true;
// repetition count test enable
const bool     NX_RNG_CFG_REPTEST_ENABLE_VAL                     = true;
// adaptive proportion 1bit test enable
const bool     NX_RNG_CFG_ADAPTEST_1BIT_ENABLE_VAL               = true;
// adaptive proportion test enable
const bool     NX_RNG_CFG_ADAPTEST_ENABLE_VAL                    = true;
// self test register 2 reset period (~1.02 hr/clear = 27)
const uint8_t  NX_RNG_CFG_ST2_RESET_PERIOD_VAL                   = 0x1B;
// pace rate (2000)
const uint16_t NX_RNG_CFG_PACE_RATE_VAL                          = 0x07d0;



fapi2::ReturnCode
p10_rng_init_phase1(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt;
    using namespace scomt::proc;

    FAPI_INF("Start");

    fapi2::buffer<uint64_t> l_rng_cfg_data;
    fapi2::buffer<uint64_t> l_rng_st0_data;
    fapi2::buffer<uint64_t> l_rng_st1_data;
    fapi2::buffer<uint64_t> l_rng_st2_data;
    fapi2::buffer<uint64_t> l_rng_st3_data;
    fapi2::buffer<uint64_t> l_rng_rdelay_data;

    // 1. RNG will start running with FIFO write / self tests disabled (enable
    // doesn't gate the osc; it turns off FIFO writes and self test fails);
    // rng_enable = 0.

    // 2. RNG Conditioner Startup Test runs and reports status.
    // Host boot reads Conditioner Startup Test Fail status. If a fail is
    // detected then RNG is declared broken.

    // read conditioner startup test fail status, exit if failure has been
    // reported to declare RNG broken/unusable
    FAPI_TRY(GET_NX_PBI_RNG_CFG(i_target, l_rng_cfg_data));

    FAPI_ASSERT(!l_rng_cfg_data.getBit<NX_PBI_RNG_CFG_COND_STARTUP_TEST_FAIL>(),
                fapi2::P10_RNG_INIT_CONDITIONER_STARTUP_TEST_FAILED_ERR().
                set_TARGET(i_target).
                set_RNG_CFG(l_rng_cfg_data),
                "Conditioner startup test failed");

    // 3. Host boot programs window sizes, pace, self test enables and
    // parameters, read delay parameters.  program window sizes, pace, self test
    // enables/parameters, and read delay parameters get values from self test
    // registers

    FAPI_INF("Configuring Self Test Registers (non P10N DD1)");
    FAPI_TRY(GET_NX_PBI_RNG_ST0(i_target, l_rng_st0_data));
    // configure RNG Self Test Register 0
    SET_NX_PBI_RNG_ST0_REPTEST_MATCH_TH(NX_RNG_ST0_REPTEST_MATCH_TH_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_SAMPLE_SIZE(NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_WINDOW_SIZE(NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH(NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH(NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH(NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_VAL, l_rng_st0_data);
    SET_NX_PBI_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH(NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_VAL, l_rng_st0_data);
    FAPI_TRY(PUT_NX_PBI_RNG_ST0(i_target, l_rng_st0_data));

    //// configure RNG Self Test Register 1
    FAPI_TRY(GET_NX_PBI_RNG_ST1(i_target, l_rng_st1_data));
    SET_NX_PBI_RNG_ST1_SOFT_FAIL_TH(NX_RNG_ST1_SOFT_FAIL_TH_VAL, l_rng_st1_data);
    SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MIN(NX_RNG_ST1_1BIT_MATCH_TH_MIN_VAL, l_rng_st1_data);
    SET_NX_PBI_RNG_ST1_1BIT_MATCH_TH_MAX(NX_RNG_ST1_1BIT_MATCH_TH_MAX_VAL, l_rng_st1_data);
    FAPI_TRY(PUT_NX_PBI_RNG_ST1(i_target, l_rng_st1_data));

    //// configure RNG Self Test Register 3
    FAPI_TRY(GET_NX_PBI_RNG_ST3(i_target, l_rng_st3_data));
    SET_NX_PBI_RNG_ST3_RRN_ENABLE(NX_RNG_ST3_RRN_ENABLE_VAL, l_rng_st3_data);
    SET_NX_PBI_RNG_ST3_WINDOW_SIZE(NX_RNG_ST3_WINDOW_SIZE_VAL, l_rng_st3_data);
    SET_NX_PBI_RNG_ST3_MATCH_TH_MIN(NX_RNG_ST3_MATCH_TH_MIN_VAL, l_rng_st3_data);
    SET_NX_PBI_RNG_ST3_MATCH_TH_MAX(NX_RNG_ST3_MATCH_TH_MAX_VAL, l_rng_st3_data);
    FAPI_TRY(PUT_NX_PBI_RNG_ST3(i_target, l_rng_st3_data));

    //// configure RNG Read Delay Parameters Register
    FAPI_TRY(GET_NX_PBI_RNG_RDELAY(i_target, l_rng_rdelay_data));
    SET_NX_PBI_RNG_RDELAY_LFSR_RESEED_EN(NX_RNG_RDELAY_LFSR_RESEED_EN_VAL, l_rng_rdelay_data);
    SET_NX_PBI_RNG_RDELAY_READ_RTY_RATIO(NX_RNG_RDELAY_READ_RTY_RATIO_VAL, l_rng_rdelay_data);
    FAPI_TRY(PUT_NX_PBI_RNG_RDELAY(i_target, l_rng_rdelay_data));

    // 4. If RNG is not broken then host boot sets rng_enable =1.
    // update RNG Status and Control Register to engage initialization test
    FAPI_TRY(GET_NX_PBI_RNG_CFG(i_target, l_rng_cfg_data));

    SET_NX_PBI_RNG_CFG_RNG_ENABLE(l_rng_cfg_data);
    SET_NX_PBI_RNG_CFG_REPTEST_ENABLE(NX_RNG_CFG_REPTEST_ENABLE_VAL, l_rng_cfg_data);
    SET_NX_PBI_RNG_CFG_ADAPTEST_1BIT_ENABLE(NX_RNG_CFG_ADAPTEST_1BIT_ENABLE_VAL, l_rng_cfg_data);
    SET_NX_PBI_RNG_CFG_ADAPTEST_ENABLE(NX_RNG_CFG_ADAPTEST_ENABLE_VAL, l_rng_cfg_data);
    SET_NX_PBI_RNG_CFG_ST2_RESET_PERIOD(NX_RNG_CFG_ST2_RESET_PERIOD_VAL, l_rng_cfg_data);
    SET_NX_PBI_RNG_CFG_PACE_RATE(NX_RNG_CFG_PACE_RATE_VAL, l_rng_cfg_data);

    FAPI_TRY(PUT_NX_PBI_RNG_CFG(i_target, l_rng_cfg_data));

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
