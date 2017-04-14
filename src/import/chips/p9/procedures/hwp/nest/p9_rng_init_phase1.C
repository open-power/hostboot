/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/nest/p9_rng_init_phase1.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2017                        */
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
/// @file p9_rng_init_phase1.C
/// @brief Perform NX RNG Phase 1 initialization (FAPI2)
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
#include <p9_rng_init_phase1.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// DD1 DEFINITIONS
// RNG Self Test Register 0 constants
// repetition count match count threshold (3 repeated numbers)
const uint8_t   NX_RNG_ST0_REPTEST_MATCH_TH_DD1                  = 0x01;
// adaptive proportion sample size (8b wide sample)
const uint8_t   NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_DD1              = 0x02;
// adaptive proportion window size (2K size) ###CHANGED
const uint8_t   NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_DD1              = 0x02;
// adaptive proportion RRN RNG0 match threshold (136; Assuming H = 6)
const uint16_t  NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_DD1        = 0x88;
// adaptive proportion RRN RNG1 match threshold (136; Assuming H = 6)
const uint16_t  NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_DD1        = 0x88;
// adaptive proportion CRN RNG0 match threshold (72; Assuming H = 8)
const uint16_t  NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_DD1        = 0x48;
// adaptive proportion CRN RNG1 match threshold (72; Assuming H = 8)
const uint16_t  NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_DD1        = 0x48;

// RNG Self Test Register 1 constants
// adaptive proportion soft fail threshold (Setting [0:6] to 0x02)
const uint8_t NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_DD1               = 0x02;
// adaptive proportion 1bit match threshold min (648; Assuming H = 0.8)
const uint16_t NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_DD1         = 0x0288;
// adaptive proportion 1bit match threshold max (1400; Assuming H = 0.8)
const uint16_t NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_DD1         = 0x0578;


// RNG Self Test Register 3 constants
// sample rate RRN enable (Use RRNs)
const bool     NX_RNG_ST3_SAMPTEST_RRN_ENABLE_DD1                = true;
// sample rate window size (64k -1 size)
const uint8_t  NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_DD1               = 0x07;
// sample rate match threshold minimum (64k * 0.45 = 29,491)
const uint16_t NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_DD1              = 0x4ccc;
// sample rate match threshold maximum (64k * 0.55 = 36,044)
const uint16_t NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_DD1              = 0xb332;

//DD2 DEFINITIONS
// RNG Self Test Register 0 constants
// repetition count match count threshold (3 repeated numbers)
const uint8_t   NX_RNG_ST0_REPTEST_MATCH_TH_DD2                  = 0x01;
// adaptive proportion sample size (8b wide sample)
const uint8_t   NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_DD2              = 0x02;
// adaptive proportion window size (2K size) ###CHANGED
const uint8_t   NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_DD2              = 0x01;
// adaptive proportion RRN RNG0 match threshold (136; Assuming H = 6)
const uint16_t  NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_DD2        = 0x22;
// adaptive proportion RRN RNG1 match threshold (136; Assuming H = 6)
const uint16_t  NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_DD2        = 0x22;
// adaptive proportion CRN RNG0 match threshold (72; Assuming H = 8)
const uint16_t  NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_DD2        = 0x12;
// adaptive proportion CRN RNG1 match threshold (72; Assuming H = 8)
const uint16_t  NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_DD2        = 0x12;

// RNG Self Test Register 1 constants
// adaptive proportion soft fail threshold (Setting [0:6] to 0x02)
const uint8_t NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_DD2               = 0x02;
// adaptive proportion 1bit match threshold min (648; Assuming H = 0.8)
const uint16_t NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_DD2         = 0x00A2;
// adaptive proportion 1bit match threshold max (1400; Assuming H = 0.8)
const uint16_t NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_DD2         = 0x015E;

// RNG Self Test Register 3 constants
// sample rate RRN enable (Use RRNs)
const bool     NX_RNG_ST3_SAMPTEST_RRN_ENABLE_DD2                = true;
// sample rate window size (64k -1 size)
const uint8_t  NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_DD2               = 0x07;
// sample rate match threshold minimum (64k * 0.45 = 29,491)
const uint16_t NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_DD2              = 0x7333;
// sample rate match threshold maximum (64k * 0.55 = 36,044)
const uint16_t NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_DD2              = 0x8CCC;

// RNG Read Delay Parameters Register
// Read Retry Ratio (0 = 31/32, 1 = 15/16, 2 = 29/32 ... 15 = 1/2 ... 31 = disabled)
const uint8_t  NX_RNG_CQ_RDELAY_READ_RTY_RATIO_DD1               = 0x1F;
const uint8_t  NX_RNG_CQ_RDELAY_READ_RTY_RATIO_DD2               = 0x1F;

// RNG Status And Control Register constants (Applies to both)
const bool     NX_RNG_CFG_CONDITIONER_MASK_TOGGLE            = false;
// sample rate test enable
const bool     NX_RNG_CFG_SAMPLE_RATE_TEST_ENABLE            = true;
// repetition count test enable
const bool     NX_RNG_CFG_REPTEST_ENABLE                     = true;
// adaptive proportion 1bit test enable
const bool     NX_RNG_CFG_ADAPTEST_1BIT_ENABLE               = true;
// adaptive proportion test enable
const bool     NX_RNG_CFG_ADAPTEST_ENABLE                    = true;
// self test register 2 reset period (~63min/clear)
const uint8_t  NX_RNG_CFG_ST2_RESET_PERIOD                   = 0x07;
// pace rate (2000)
const uint16_t NX_RNG_CFG_PACE_RATE                          = 0x07d0;
// pace rate (300) for HW403701
const uint16_t NX_RNG_CFG_PACE_RATE_HW403701                 = 0x012c;


//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------

fapi2::ReturnCode
p9_rng_init_phase1(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    FAPI_INF("Start");

    fapi2::buffer<uint64_t> l_rng_cfg_data;
    fapi2::buffer<uint64_t> l_rng_st0_data;
    fapi2::buffer<uint64_t> l_rng_st1_data;
    fapi2::buffer<uint64_t> l_rng_st2_data;
    fapi2::buffer<uint64_t> l_rng_st3_data;
    fapi2::buffer<uint64_t> l_rng_rdelay_data;

    uint8_t l_dd1 = 0;
    uint8_t l_HW403701 = 0;

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_RNG_ADAPTEST_SETTINGS, i_target, l_dd1) );
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_HW403701, i_target, l_HW403701) );

    // 1. RNG will start running with FIFO write / self tests disabled (enable doesn't gate the osc; it turns off FIFO
    // writes and self test fails); rng_enable = 0.
    // 2. RNG Conditioner Startup Test runs and reports status.
    // Host boot reads Conditioner Startup Test Fail status. If a fail is detected then RNG is declared broken.

    // read conditioner startup test fail status, exit if failure has been reported to
    // declare RNG broken/unusable
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_CFG, l_rng_cfg_data),
             "Error from getScom (NX RNG Status and Control Register)");

    FAPI_ASSERT(!l_rng_cfg_data.getBit<PU_NX_RNG_CFG_COND_STARTUP_TEST_FAIL>(),
                fapi2::P9_RNG_INIT_CONDITIONER_STARTUP_TEST_FAILED_ERR().
                set_TARGET(i_target).
                set_RNG_CFG(l_rng_cfg_data),
                "Conditioner startup test failed");

    // 3. Host boot programs window sizes, pace, self test enables and parameters, read delay parameters.
    // program window sizes, pace, self test enables/parameters, and read delay parameters
    // get values from self test registers
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_ST0, l_rng_st0_data),
             "Error from getScom (NX RNG Self Test Register 0)");
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_ST1, l_rng_st1_data),
             "Error from getScom (NX RNG Self Test Register 1)");
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_ST3, l_rng_st3_data),
             "Error from getScom (NX RNG Self Test Register 3)");
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_RDELAY, l_rng_rdelay_data),
             "Error from putScom (NX RNG Read Delay Parameters Register)");

    if (l_dd1 != 0)
    {
        // DD1
        FAPI_INF("Configuring Self Test Registers for DD1");
        // configure RNG Self Test Register 0
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_REPTEST_MATCH_TH, PU_NX_RNG_ST0_REPTEST_MATCH_TH_LEN>
        (NX_RNG_ST0_REPTEST_MATCH_TH_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE, PU_NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_LEN>
        (NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_WINDOW_SIZE, PU_NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_LEN>
        (NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_DD1);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_DD1);

        // configure RNG Self Test Register 1
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH, PU_NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_LEN>
        (NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_DD1);
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN, PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_LEN>
        (NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_DD1);
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX, PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_LEN>
        (NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_DD1);

        // configure RNG Self Test Register 3
        l_rng_st3_data.writeBit<PU_NX_RNG_ST3_SAMPTEST_RRN_ENABLE>
        (NX_RNG_ST3_SAMPTEST_RRN_ENABLE_DD1);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_WINDOW_SIZE, PU_NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_LEN>
        (NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_DD1);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN, PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_LEN>
        (NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_DD1);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX, PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_LEN>
        (NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_DD1);

        // configure RNG Read Delay Parameters Register
        l_rng_rdelay_data.insertFromRight<PU_NX_RNG_RDELAY_CQ_READ_RTY_RATIO, PU_NX_RNG_RDELAY_CQ_READ_RTY_RATIO_LEN>
        (NX_RNG_CQ_RDELAY_READ_RTY_RATIO_DD1);
    }
    else
    {
        // DD2
        FAPI_INF("Configuring Self Test Registers for DD2");
        // configure RNG Self Test Register 0
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_REPTEST_MATCH_TH, PU_NX_RNG_ST0_REPTEST_MATCH_TH_LEN>
        (NX_RNG_ST0_REPTEST_MATCH_TH_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE, PU_NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_LEN>
        (NX_RNG_ST0_ADAPTEST_SAMPLE_SIZE_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_WINDOW_SIZE, PU_NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_LEN>
        (NX_RNG_ST0_ADAPTEST_WINDOW_SIZE_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_RRN_RNG0_MATCH_TH_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_RRN_RNG1_MATCH_TH_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_CRN_RNG0_MATCH_TH_DD2);
        l_rng_st0_data.insertFromRight<PU_NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH, PU_NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_LEN>
        (NX_RNG_ST0_ADAPTEST_CRN_RNG1_MATCH_TH_DD2);

        // configure RNG Self Test Register 1
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH, PU_NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_LEN>
        (NX_RNG_ST1_ADAPTEST_SOFT_FAIL_TH_DD2);
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN, PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_LEN>
        (NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MIN_DD2);
        l_rng_st1_data.insertFromRight<PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX, PU_NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_LEN>
        (NX_RNG_ST1_ADAPTEST_1BIT_MATCH_TH_MAX_DD2);

        // configure RNG Self Test Register 3
        l_rng_st3_data.writeBit<PU_NX_RNG_ST3_SAMPTEST_RRN_ENABLE>
        (NX_RNG_ST3_SAMPTEST_RRN_ENABLE_DD2);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_WINDOW_SIZE, PU_NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_LEN>
        (NX_RNG_ST3_SAMPTEST_WINDOW_SIZE_DD2);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN, PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_LEN>
        (NX_RNG_ST3_SAMPTEST_MATCH_TH_MIN_DD2);
        l_rng_st3_data.insertFromRight<PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX, PU_NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_LEN>
        (NX_RNG_ST3_SAMPTEST_MATCH_TH_MAX_DD2);

        // configure RNG Read Delay Parameters Register
        l_rng_rdelay_data.insertFromRight<PU_NX_RNG_RDELAY_CQ_READ_RTY_RATIO, PU_NX_RNG_RDELAY_CQ_READ_RTY_RATIO_LEN>
        (NX_RNG_CQ_RDELAY_READ_RTY_RATIO_DD2);
    }

    FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_ST0, l_rng_st0_data),
             "Error from putScom (NX RNG Self Test Register 0)");

    FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_ST1, l_rng_st1_data),
             "Error from putScom (NX RNG Self Test Register 1)");

    FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_ST3, l_rng_st3_data),
             "Error from putScom (NX RNG Self Test Register 3)");

    FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_RDELAY, l_rng_rdelay_data),
             "Error from putScom (NX RNG Read Delay Parameters Register)");

    // 4. If RNG is not broken then host boot sets rng_enable =1.
    // update RNG Status and Control Register to engage initialization test
    FAPI_TRY(fapi2::getScom(i_target, PU_NX_RNG_CFG, l_rng_cfg_data),
             "Error from getScom (NX RNG Status and Control Register)");

    l_rng_cfg_data.setBit<PU_NX_RNG_CFG_ENABLE>();
    l_rng_cfg_data.writeBit<PU_NX_RNG_CFG_MASK_TOGGLE_ENABLE>
    (NX_RNG_CFG_CONDITIONER_MASK_TOGGLE);
    l_rng_cfg_data.writeBit<PU_NX_RNG_CFG_SAMPTEST_ENABLE>
    (NX_RNG_CFG_SAMPLE_RATE_TEST_ENABLE);
    l_rng_cfg_data.writeBit<PU_NX_RNG_CFG_REPTEST_ENABLE>
    (NX_RNG_CFG_REPTEST_ENABLE);
    l_rng_cfg_data.writeBit<PU_NX_RNG_CFG_ADAPTEST_1BIT_ENABLE>
    (NX_RNG_CFG_ADAPTEST_1BIT_ENABLE);
    l_rng_cfg_data.writeBit<PU_NX_RNG_CFG_ADAPTEST_ENABLE>
    (NX_RNG_CFG_ADAPTEST_ENABLE);
    l_rng_cfg_data.insertFromRight<PU_NX_RNG_CFG_ST2_RESET_PERIOD, PU_NX_RNG_CFG_ST2_RESET_PERIOD_LEN>
    (NX_RNG_CFG_ST2_RESET_PERIOD);

    if(l_HW403701 != 0)
    {
        l_rng_cfg_data.insertFromRight<PU_NX_RNG_CFG_PACE_RATE, PU_NX_RNG_CFG_PACE_RATE_LEN>
        (NX_RNG_CFG_PACE_RATE_HW403701);
    }
    else
    {
        l_rng_cfg_data.insertFromRight<PU_NX_RNG_CFG_PACE_RATE, PU_NX_RNG_CFG_PACE_RATE_LEN>
        (NX_RNG_CFG_PACE_RATE);
    }

    FAPI_TRY(fapi2::putScom(i_target, PU_NX_RNG_CFG, l_rng_cfg_data),
             "Error from putScom (NX RNG Status and Control Register)");

fapi_try_exit:
    FAPI_INF("End");
    return fapi2::current_err;
}
