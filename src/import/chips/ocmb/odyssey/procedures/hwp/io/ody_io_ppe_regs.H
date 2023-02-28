/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_io_ppe_regs.H $ */
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

//
// GENERATED CODE - DO NOT EDIT!
//

#pragma once

//=================== image regs ======================

#define IMG_REG_PPE_CURRENT_THREAD_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_CURRENT_THREAD_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_VIO_VOLTS_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xc0, \
                  6, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_VIO_VOLTS_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xc0, \
                  6, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_DEBUG_LOG_NUM_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0x1fc, \
                  2, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_DEBUG_LOG_NUM_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0x1fc, \
                  2, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_UCONTROLLER_TEST_STAT_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_UCONTROLLER_TEST_STAT_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_DISABLE_THREAD_ACTIVE_TIME_CHECK_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_DISABLE_THREAD_ACTIVE_TIME_CHECK_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_UCONTROLLER_TEST_EN_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_UCONTROLLER_TEST_EN_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_WATCHDOG_SELECT_SIM_MODE_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xf00, \
                  8, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_WATCHDOG_SELECT_SIM_MODE_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xf00, \
                  8, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_NUM_THREADS_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xf000, \
                  12, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_NUM_THREADS_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000000, \
                  0xf000, \
                  12, \
                  0, \
                  0, \
                  0, \
                  DATA)


#define IMG_REG_PPE_SIM_SPEEDUP_PUT(REGS, TARGET, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  0, \
                  0, \
                  0, \
                  DATA)

#define IMG_REG_PPE_SIM_SPEEDUP_GET(REGS, TARGET, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30c0, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  0, \
                  0, \
                  0, \
                  DATA)

//=================== threaded regs ======================

#define MEM_REG_RX_EO_PHASE_SELECT_0_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_PHASE_SELECT_0_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_PHASE_SELECT_0_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_PHASE_SELECT_0_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_PEAK2_CAL_DISABLE_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_PEAK2_CAL_DISABLE_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_PEAK2_CAL_DISABLE_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_PEAK2_CAL_DISABLE_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_DEBUG_STATE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_DEBUG_STATE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_DEBUG_STATE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_DEBUG_STATE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LOFF_AD_N000_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LOFF_AD_N000_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LOFF_AD_N000_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LOFF_AD_N000_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LTE_GAIN_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LTE_GAIN_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LTE_GAIN_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LTE_GAIN_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_JUMP_TABLE_USED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_JUMP_TABLE_USED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_JUMP_TABLE_USED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_JUMP_TABLE_USED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_CNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_CNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_CNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_CNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LATCH_OFFSET_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LATCH_OFFSET_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LATCH_OFFSET_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LATCH_OFFSET_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LINKLAYER_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LINKLAYER_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LINKLAYER_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LINKLAYER_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_EN_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_EN_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_EN_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_EN_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_IQ_MAX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_IQ_MAX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_IQ_MAX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_IQ_MAX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_PAUSE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_PAUSE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_PAUSE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_PAUSE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_DDC_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_DDC_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_DDC_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_DDC_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RUNNING_EQ_EVAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RUNNING_EQ_EVAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RUNNING_EQ_EVAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RUNNING_EQ_EVAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_LTE_GAIN_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_LTE_GAIN_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_LTE_GAIN_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_LTE_GAIN_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_H1_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0x1fc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_H1_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0x1fc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_H1_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0x1fc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_H1_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0x1fc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LATCH_OFFSET_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LATCH_OFFSET_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LATCH_OFFSET_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LATCH_OFFSET_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_STEP_DONE_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_STEP_DONE_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_STEP_DONE_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_STEP_DONE_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LTE_ZERO_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LTE_ZERO_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LTE_ZERO_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LTE_ZERO_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_VAL_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_VAL_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_VAL_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_VAL_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_D_OVERRIDE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100101000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100101000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100101000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100101000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK2_HYST_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK2_HYST_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK2_HYST_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK2_HYST_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_BANK_SYNC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_BANK_SYNC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_BANK_SYNC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_BANK_SYNC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LINKLAYER_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LINKLAYER_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LINKLAYER_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LINKLAYER_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_BANK_SYNC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_BANK_SYNC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_BANK_SYNC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_BANK_SYNC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_RECAL_CNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_RECAL_CNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_RECAL_CNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_RECAL_CNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_THREAD_LOCK_SIM_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_THREAD_LOCK_SIM_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_THREAD_LOCK_SIM_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_THREAD_LOCK_SIM_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_BAD_EYE_OPT_HEIGHT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_BAD_EYE_OPT_HEIGHT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_BAD_EYE_OPT_HEIGHT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_BAD_EYE_OPT_HEIGHT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_MARGIN_OFFSET_OVERLAY_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_MARGIN_OFFSET_OVERLAY_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_MARGIN_OFFSET_OVERLAY_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_MARGIN_OFFSET_OVERLAY_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_STEP_CNTL_OPT_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_STEP_CNTL_OPT_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_STEP_CNTL_OPT_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_STEP_CNTL_OPT_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_HYST_DELTA_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_HYST_DELTA_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_HYST_DELTA_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_HYST_DELTA_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_THREAD_LAST_ACTIVE_TIME_US_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_THREAD_LAST_ACTIVE_TIME_US_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_THREAD_LAST_ACTIVE_TIME_US_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_THREAD_LAST_ACTIVE_TIME_US_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK2_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK2_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK2_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK2_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DCC_DEBUG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DCC_DEBUG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DCC_DEBUG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DCC_DEBUG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_7_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_7_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_7_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_7_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_ERROR_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_ERROR_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_ERROR_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_ERROR_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011000000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PIPE_LANE_STRESS_MODE_0_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PIPE_LANE_STRESS_MODE_0_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PIPE_LANE_STRESS_MODE_0_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PIPE_LANE_STRESS_MODE_0_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_BER_TIMER_SEL_BIST_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_BER_TIMER_SEL_BIST_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_BER_TIMER_SEL_BIST_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_BER_TIMER_SEL_BIST_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_VGA_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_VGA_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_VGA_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_VGA_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_STEP_FAIL_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x3fff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_STEP_FAIL_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x3fff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_STEP_FAIL_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x3fff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_STEP_FAIL_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x3fff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_DFE_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_DFE_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_DFE_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_DFE_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_FAIL_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_FAIL_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_FAIL_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_FAIL_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_CTLE_PEAK_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_CTLE_PEAK_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_CTLE_PEAK_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_CTLE_PEAK_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK_HYST_SETTINGS_FULL_REG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK_HYST_SETTINGS_FULL_REG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK_HYST_SETTINGS_FULL_REG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK_HYST_SETTINGS_FULL_REG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_SERVO_STATUS1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_SERVO_STATUS1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_SERVO_STATUS1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_SERVO_STATUS1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QUAD_PHASE_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QUAD_PHASE_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QUAD_PHASE_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QUAD_PHASE_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_B_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_B_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_B_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_B_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_LTE_ZERO_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_LTE_ZERO_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_LTE_ZERO_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_LTE_ZERO_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LOFF_AD_N000_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LOFF_AD_N000_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LOFF_AD_N000_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LOFF_AD_N000_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_E_OVERRIDE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_ERROR_TYPE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x7000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_ERROR_TYPE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x7000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_ERROR_TYPE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x7000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_ERROR_TYPE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0x7000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_Q_MAX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_Q_MAX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_Q_MAX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_Q_MAX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DC_ENABLE_DCC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DC_ENABLE_DCC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DC_ENABLE_DCC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DC_ENABLE_DCC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK2_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK2_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK2_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK2_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_ERROR_THREAD_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_ERROR_THREAD_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_ERROR_THREAD_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_ERROR_THREAD_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_A_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_A_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_A_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_A_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_ZERO_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x7, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_ZERO_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x7, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_ZERO_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x7, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_ZERO_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x7, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_EN_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_EN_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_EN_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_EN_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_5_2_3_4_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_5_2_3_4_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_5_2_3_4_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_5_2_3_4_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_DDC_HYST_RIGHT_EDGE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_DDC_HYST_RIGHT_EDGE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_DDC_HYST_RIGHT_EDGE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_DDC_HYST_RIGHT_EDGE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_LATCH_OFFSET_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_LATCH_OFFSET_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_LATCH_OFFSET_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_LATCH_OFFSET_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_RECAL_NOT_RUN_SIM_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_RECAL_NOT_RUN_SIM_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_RECAL_NOT_RUN_SIM_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_RECAL_NOT_RUN_SIM_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_I_MIN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_I_MIN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_I_MIN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_I_MIN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_SPARE_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x3e, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_SPARE_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x3e, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_SPARE_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x3e, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_SPARE_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x3e, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_START_AT_ZERO_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_START_AT_ZERO_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_START_AT_ZERO_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_START_AT_ZERO_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_7_0_1_6_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_7_0_1_6_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_7_0_1_6_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_7_0_1_6_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_I_TUNE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_I_TUNE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_I_TUNE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_I_TUNE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_CHANNEL_LOSS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_CHANNEL_LOSS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_CHANNEL_LOSS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_CHANNEL_LOSS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0xc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EOFF_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EOFF_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EOFF_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EOFF_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QPA_HYSTERESIS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0xe0, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QPA_HYSTERESIS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0xe0, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QPA_HYSTERESIS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0xe0, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QPA_HYSTERESIS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0xe0, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_LANE_HIST_MIN_EYE_WIDTH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_LANE_HIST_MIN_EYE_WIDTH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_LANE_HIST_MIN_EYE_WIDTH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_LANE_HIST_MIN_EYE_WIDTH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_LTE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_LTE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_LTE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_LTE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_PEAK2_HYST_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_PEAK2_HYST_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_PEAK2_HYST_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_PEAK2_HYST_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_CONVERGED_END_COUNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_CONVERGED_END_COUNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_CONVERGED_END_COUNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_CONVERGED_END_COUNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_RX_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_RX_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_RX_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_RX_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_QUAD_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x300, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_QUAD_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x300, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_QUAD_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x300, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_QUAD_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x300, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_Q_MIN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_Q_MIN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_Q_MIN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_Q_MIN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_ESD_ABS_VAL_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_ESD_ABS_VAL_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_ESD_ABS_VAL_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_ESD_ABS_VAL_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_CTLE_PEAK_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_CTLE_PEAK_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_CTLE_PEAK_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_CTLE_PEAK_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_DFE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_DFE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_DFE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_DFE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_DDC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_DDC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_DDC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_DDC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_POFF_AVG_A_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_POFF_AVG_A_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_POFF_AVG_A_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_POFF_AVG_A_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_INIT_TIME_US_WARNING_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_INIT_TIME_US_WARNING_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_INIT_TIME_US_WARNING_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_INIT_TIME_US_WARNING_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_5_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_5_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_5_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_5_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_A_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_A_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_A_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_A_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_SIGDET_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_SIGDET_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_SIGDET_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_SIGDET_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_MAX_ERROR_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_MAX_ERROR_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_MAX_ERROR_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_MAX_ERROR_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_FFE_PRE2_COEF_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_FFE_PRE2_COEF_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_FFE_PRE2_COEF_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_FFE_PRE2_COEF_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_TX_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_TX_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_TX_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_TX_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_HYST_DELTA_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_HYST_DELTA_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_HYST_DELTA_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_HYST_DELTA_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_STEP_CNTL_OPT_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xc000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_STEP_CNTL_OPT_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xc000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_STEP_CNTL_OPT_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xc000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_STEP_CNTL_OPT_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xc000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101001, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_FAIL_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_FAIL_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_FAIL_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_FAIL_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DCCAL_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DCCAL_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DCCAL_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DCCAL_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CLR_LANE_RECAL_CNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CLR_LANE_RECAL_CNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CLR_LANE_RECAL_CNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CLR_LANE_RECAL_CNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_VGA_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_VGA_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_VGA_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_VGA_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_THREAD_TIME_STRESS_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_THREAD_TIME_STRESS_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_THREAD_TIME_STRESS_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_THREAD_TIME_STRESS_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_STEP_DONE_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_STEP_DONE_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_STEP_DONE_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_STEP_DONE_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0xfff8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PIPE_RESET_INACTIVE_PHASE_0_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PIPE_RESET_INACTIVE_PHASE_0_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PIPE_RESET_INACTIVE_PHASE_0_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PIPE_RESET_INACTIVE_PHASE_0_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100010000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_QUAD_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_QUAD_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_QUAD_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_QUAD_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_LANE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_LANE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_LANE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_LANE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_SMALL_EYE_WARNING_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_SMALL_EYE_WARNING_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_SMALL_EYE_WARNING_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_SMALL_EYE_WARNING_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_FULL_REG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_FULL_REG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_FULL_REG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_FULL_REG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_FAIL_FLAG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_FAIL_FLAG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_FAIL_FLAG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_FAIL_FLAG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_HYST_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_HYST_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_HYST_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_HYST_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_OFFSET_MARGIN_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_OFFSET_MARGIN_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_OFFSET_MARGIN_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_OFFSET_MARGIN_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x18, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_BER_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_BER_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_BER_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_BER_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_BUSY_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_BUSY_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_BUSY_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_BUSY_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_QUAD_PHASE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_QUAD_PHASE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_QUAD_PHASE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_QUAD_PHASE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_H1_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_H1_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_H1_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_H1_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PEAK2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PEAK2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PEAK2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_CTLE_PEAK1_PEAK2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LTE_GAIN_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LTE_GAIN_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LTE_GAIN_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LTE_GAIN_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EYE_HEIGHT_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EYE_HEIGHT_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EYE_HEIGHT_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EYE_HEIGHT_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DCC_MAIN_MIN_SAMPLES_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_LANE_HIST_MIN_EYE_WIDTH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_LANE_HIST_MIN_EYE_WIDTH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_LANE_HIST_MIN_EYE_WIDTH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_LANE_HIST_MIN_EYE_WIDTH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_SERVO_STATUS0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_SERVO_STATUS0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_SERVO_STATUS0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_SERVO_STATUS0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QPA_PATTERN_ENABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QPA_PATTERN_ENABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QPA_PATTERN_ENABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QPA_PATTERN_ENABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_ENABLE_AUTO_RECAL_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_ENABLE_AUTO_RECAL_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_ENABLE_AUTO_RECAL_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_ENABLE_AUTO_RECAL_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_BANK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_BANK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_BANK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_BANK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EOFF_POFF_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EOFF_POFF_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EOFF_POFF_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EOFF_POFF_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_H1_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_H1_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_H1_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_H1_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101111, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANES_PON_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANES_PON_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANES_PON_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANES_PON_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_DDC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_DDC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_DDC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_DDC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_CAL_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_CAL_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_CAL_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_CAL_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b001110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b001110000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_HYST_MIN_RECAL_CNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_HYST_MIN_RECAL_CNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_HYST_MIN_RECAL_CNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_HYST_MIN_RECAL_CNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_OTHER_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_OTHER_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_OTHER_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_OTHER_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_I_MAX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_I_MAX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_I_MAX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_I_MAX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_SIGDET_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_SIGDET_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_SIGDET_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_SIGDET_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_CONVERGED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_CONVERGED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_CONVERGED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_CONVERGED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_DFE_H1_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_DFE_H1_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_DFE_H1_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_DFE_H1_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_EN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_EN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_EN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_EN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QPA_PATTERN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x7c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QPA_PATTERN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x7c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QPA_PATTERN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x7c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QPA_PATTERN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x7c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_LANE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_LANE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_LANE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_LANE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_FRC_2R_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_FRC_2R_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_FRC_2R_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_FRC_2R_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_FULL_REG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_FULL_REG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_FULL_REG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_FULL_REG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_AMAX_TARGET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_AMAX_TARGET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_AMAX_TARGET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_AMAX_TARGET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LAST_CAL_TIME_US_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LAST_CAL_TIME_US_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LAST_CAL_TIME_US_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LAST_CAL_TIME_US_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000111, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_E_OVERRIDE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_E_OVERRIDE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_E_OVERRIDE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_E_OVERRIDE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111101111, \
                  0xfe, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EYE_WIDTH_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EYE_WIDTH_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EYE_WIDTH_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EYE_WIDTH_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0xfe00, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_CLKADJ_COEFF_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_CLKADJ_COEFF_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_CLKADJ_COEFF_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_CLKADJ_COEFF_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x3f8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_DATA_RATE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_DATA_RATE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_DATA_RATE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_DATA_RATE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_DDC_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_DDC_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_DDC_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_DDC_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_GAIN_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_GAIN_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_GAIN_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_GAIN_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_QUAD_PHASE_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_QUAD_PHASE_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_QUAD_PHASE_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_QUAD_PHASE_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FAST_H1_ADJ_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FAST_H1_ADJ_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FAST_H1_ADJ_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FAST_H1_ADJ_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CLR_EYE_HEIGHT_WIDTH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CLR_EYE_HEIGHT_WIDTH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CLR_EYE_HEIGHT_WIDTH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CLR_EYE_HEIGHT_WIDTH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e0, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e0, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_GAIN_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e0, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_GAIN_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100001, \
                  0x1e0, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_H1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_H1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_H1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_H1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_RUN_OR_UNUSED_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001101, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_DFE_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_DFE_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_DFE_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_DFE_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CURRENT_CAL_LANE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CURRENT_CAL_LANE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CURRENT_CAL_LANE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CURRENT_CAL_LANE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x1f00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_STEP_CNTL_OPT_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xff80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_STEP_CNTL_OPT_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xff80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_STEP_CNTL_OPT_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xff80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_STEP_CNTL_OPT_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0xff80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_LATCH_OFFSET_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_LATCH_OFFSET_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_LATCH_OFFSET_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_LATCH_OFFSET_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_AB_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_AB_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_AB_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_AB_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_1R_SEGS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x1800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_1R_SEGS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x1800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_1R_SEGS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x1800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_1R_SEGS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x1800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_RECAL_NOT_RUN_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_RECAL_NOT_RUN_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_RECAL_NOT_RUN_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_RECAL_NOT_RUN_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000100, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_AMP_SETTING_OVR_ENB_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_AMP_SETTING_OVR_ENB_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_AMP_SETTING_OVR_ENB_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_AMP_SETTING_OVR_ENB_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_ENABLE_AUTO_RECAL_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_ENABLE_AUTO_RECAL_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_ENABLE_AUTO_RECAL_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_ENABLE_AUTO_RECAL_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_4_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_4_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_4_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_4_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_DEBUG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_DEBUG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_DEBUG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_DEBUG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_D_OVERRIDE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_PEAK2_HYST_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_PEAK2_HYST_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK1_PEAK2_HYST_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK1_PEAK2_HYST_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_MIN_RECAL_CNT_REACHED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_MIN_RECAL_CNT_REACHED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_MIN_RECAL_CNT_REACHED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_MIN_RECAL_CNT_REACHED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_2_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_2_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_2_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_2_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_MARGIN_VOLTAGE_OFFSET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_MARGIN_VOLTAGE_OFFSET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_MARGIN_VOLTAGE_OFFSET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_MARGIN_VOLTAGE_OFFSET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_JUMP_TARGET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_JUMP_TARGET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_JUMP_TARGET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_JUMP_TARGET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DISABLE_BANK_PDWN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DISABLE_BANK_PDWN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DISABLE_BANK_PDWN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DISABLE_BANK_PDWN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CMD_INIT_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CMD_INIT_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CMD_INIT_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CMD_INIT_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100100, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_HEIGHT_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LTE_HYSTERESIS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LTE_HYSTERESIS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LTE_HYSTERESIS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LTE_HYSTERESIS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_ESD_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_ESD_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_ESD_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_ESD_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_GAIN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_GAIN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_GAIN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN1_LANE0_PRESET_RX_LTE_GAIN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100011000, \
                  0x70, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_FFE_PRE1_COEF_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xfc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_FFE_PRE1_COEF_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xfc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_FFE_PRE1_COEF_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xfc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_FFE_PRE1_COEF_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0xfc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_ERROR_STATE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_ERROR_STATE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_ERROR_STATE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_ERROR_STATE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_HS_DAC_THRESH_MAX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_HS_DAC_THRESH_MAX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_HS_DAC_THRESH_MAX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_HS_DAC_THRESH_MAX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_5_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_5_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_5_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_5_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANES_PON_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANES_PON_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANES_PON_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANES_PON_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_POFF_AVG_B_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_POFF_AVG_B_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_POFF_AVG_B_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_POFF_AVG_B_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_LTE_GAIN_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_LTE_GAIN_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_LTE_GAIN_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_LTE_GAIN_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_2R_SEG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_2R_SEG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_2R_SEG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_2R_SEG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_SPARE_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_SPARE_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_SPARE_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_SPARE_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_B_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_B_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_B_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_B_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_DDC_HYST_LEFT_EDGE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_DDC_HYST_LEFT_EDGE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_DDC_HYST_LEFT_EDGE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_DDC_HYST_LEFT_EDGE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_DDC_HYST_RIGHT_EDGE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_DDC_HYST_RIGHT_EDGE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_DDC_HYST_RIGHT_EDGE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_DDC_HYST_RIGHT_EDGE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001000, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_BAD_EYE_OPT_WIDTH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_BAD_EYE_OPT_WIDTH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_BAD_EYE_OPT_WIDTH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_BAD_EYE_OPT_WIDTH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LATCHOFF_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LATCHOFF_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LATCHOFF_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LATCHOFF_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_AP_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_AP_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_AP_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_AP_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_ESD_SHIFT_VAL_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_ESD_SHIFT_VAL_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_ESD_SHIFT_VAL_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_ESD_SHIFT_VAL_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100101, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_IQ_MIN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_IQ_MIN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_DCC_IQ_MIN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_DCC_IQ_MIN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK2_HYST_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK2_HYST_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_PEAK2_HYST_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_PEAK2_HYST_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_BER_PERIOD_SEL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_BER_PERIOD_SEL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_BER_PERIOD_SEL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_BER_PERIOD_SEL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000101, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_LANES_PON_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_LANES_PON_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_LANES_PON_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_LANES_PON_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PIPE_TXDETECTRX_PHASE_0_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PIPE_TXDETECTRX_PHASE_0_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PIPE_TXDETECTRX_PHASE_0_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PIPE_TXDETECTRX_PHASE_0_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010101, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_BEFORE_INIT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_BEFORE_INIT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_BEFORE_INIT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_BEFORE_INIT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_H1_ADJ_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_H1_ADJ_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_FULL_H1_ADJ_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_FULL_H1_ADJ_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000110, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_THREAD_ACTIVE_TIME_US_LIMIT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_THREAD_ACTIVE_TIME_US_LIMIT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_THREAD_ACTIVE_TIME_US_LIMIT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_THREAD_ACTIVE_TIME_US_LIMIT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_EDGE_OFFSET_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_EDGE_OFFSET_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_EDGE_OFFSET_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_EDGE_OFFSET_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_IQ_TUNE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_IQ_TUNE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_IQ_TUNE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_IQ_TUNE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110001, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_ABORT_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_ABORT_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_ABORT_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_ABORT_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_FULL_REG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_FULL_REG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_FULL_REG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_FULL_REG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_HYST_LIMIT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_HYST_LIMIT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_HYST_LIMIT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_HYST_LIMIT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0xe000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100111000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_QUAD_PHASE_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_QUAD_PHASE_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_QUAD_PHASE_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_QUAD_PHASE_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_3_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_3_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_3_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_3_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100110000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_HYST_LIMIT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_HYST_LIMIT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_HYST_LIMIT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_HYST_LIMIT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000111, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_FFE_POST_COEF_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_FFE_POST_COEF_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_FFE_POST_COEF_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_FFE_POST_COEF_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010101, \
                  0x3f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_MEASURE_LIMITED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_MEASURE_LIMITED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_MEASURE_LIMITED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_MEASURE_LIMITED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PIPE_CURRENT_LANE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PIPE_CURRENT_LANE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PIPE_CURRENT_LANE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PIPE_CURRENT_LANE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xc0, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_MIN_ERR_LIM_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_MIN_ERR_LIM_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_MIN_ERR_LIM_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_MIN_ERR_LIM_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_EOFF_EDGE_HYSTERESIS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_EOFF_EDGE_HYSTERESIS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_EOFF_EDGE_HYSTERESIS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_EOFF_EDGE_HYSTERESIS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x1c00, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_HYST_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_HYST_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_CTLE_PEAK1_HYST_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_CTLE_PEAK1_HYST_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000100, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_BAD_DFE_CONV_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_BAD_DFE_CONV_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_BAD_DFE_CONV_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_BAD_DFE_CONV_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_LTE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_LTE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_LTE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_LTE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_RECAL_MAX_TARGET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_RECAL_MAX_TARGET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_RECAL_MAX_TARGET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_RECAL_MAX_TARGET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_B_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_B_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DC_ENABLE_LOFF_B_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DC_ENABLE_LOFF_B_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EPOFF_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EPOFF_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EPOFF_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EPOFF_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_5_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_5_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_5_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_5_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x7f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x7f, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x7f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x7f, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LTE_GAIN_ZERO_DISABLE_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LTE_GAIN_ZERO_DISABLE_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LTE_GAIN_ZERO_DISABLE_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LTE_GAIN_ZERO_DISABLE_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001011, \
                  0x6, \
                  1, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_LOZ_DEL_SEL_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_MIN_RECAL_CNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_MIN_RECAL_CNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_MIN_RECAL_CNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_MIN_RECAL_CNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0xf000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_Q_TUNE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_Q_TUNE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_Q_TUNE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_GEN3_LANE0_SAVED_TX_DCC_Q_TUNE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b011110000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_PAUSE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_PAUSE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_PAUSE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_PAUSE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101010, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_DFE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_DFE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_ENABLE_DFE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_ENABLE_DFE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001001, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_HIST_MIN_EYE_WIDTH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_HYST_ENABLED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_HYST_ENABLED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_HYST_ENABLED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_HYST_ENABLED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_1_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100100000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_1_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100100000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_1_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100100000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_PRESET_RX_PEAK_LTE_LANE_1_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100100000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_1_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_1_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_1_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_1_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_THREAD_LOOP_COUNT_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_THREAD_LOOP_COUNT_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_THREAD_LOOP_COUNT_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_THREAD_LOOP_COUNT_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_EOFF_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_EOFF_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_EOFF_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_EOFF_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_AB_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_AB_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3000, \
                  12, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PR_OFFSET_APPLIED_AB_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PR_OFFSET_APPLIED_AB_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x3000, \
                  12, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_DDC_HYST_LEFT_EDGE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_DDC_HYST_LEFT_EDGE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_DDC_HYST_LEFT_EDGE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_DDC_HYST_LEFT_EDGE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001001, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_BER_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_BER_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_BER_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_BER_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_SEG_TEST_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_SEG_TEST_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010010, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_EDGE_OFFSET_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_EDGE_OFFSET_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_EDGE_OFFSET_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_EDGE_OFFSET_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_VGA_RECAL_MIN_TARGET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_VGA_RECAL_MIN_TARGET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_VGA_RECAL_MIN_TARGET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_VGA_RECAL_MIN_TARGET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010001, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QUAD_PH_ADJ_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QUAD_PH_ADJ_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QUAD_PH_ADJ_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QUAD_PH_ADJ_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100111, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_ERROR_LANE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_ERROR_LANE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf8, \
                  3, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_ERROR_LANE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_ERROR_LANE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110111001, \
                  0xf8, \
                  3, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_3_4_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_3_4_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_3_4_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_3_4_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001101, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_BD_LOFF_LANE_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010100000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_DEBUG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_DEBUG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_DEBUG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_DEBUG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EPOFF_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EPOFF_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EPOFF_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EPOFF_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101000, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_INTERNAL_ERROR_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_INTERNAL_ERROR_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_INTERNAL_ERROR_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_INTERNAL_ERROR_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_OVERALL_PASS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_OVERALL_PASS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_OVERALL_PASS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_OVERALL_PASS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EOFF_MIN_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EOFF_MIN_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EOFF_MIN_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EOFF_MIN_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_VAL_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_VAL_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_DETECTRX_OVR_VAL_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_DETECTRX_OVR_VAL_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_QUAD_PHASE_CAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_QUAD_PHASE_CAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RC_ENABLE_QUAD_PHASE_CAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RC_ENABLE_QUAD_PHASE_CAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_BEFORE_LOFF_N000_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_BEFORE_LOFF_N000_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_BEFORE_LOFF_N000_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_BEFORE_LOFF_N000_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_5_ALIAS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_5_ALIAS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_5_ALIAS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_LOZ_DEL_SEL_5_ALIAS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110011000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_DEBUG_STOPWATCH_TIME_US_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_DEBUG_STOPWATCH_TIME_US_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_DEBUG_STOPWATCH_TIME_US_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_DEBUG_STOPWATCH_TIME_US_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_A_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_A_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_A_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_LOFF_OFFSET_APPLIED_A_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK1_CAL_DISABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_AMP_GAIN_CNT_MAX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_AMP_GAIN_CNT_MAX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_AMP_GAIN_CNT_MAX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_AMP_GAIN_CNT_MAX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110000011, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_IN_HOLD_LOOP_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_IN_HOLD_LOOP_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_IN_HOLD_LOOP_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_IN_HOLD_LOOP_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_CTLE_PEAK2_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_CTLE_PEAK2_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_PCIE_IDLE_DEL_SEL_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110010110, \
                  0xf0, \
                  4, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_LTE_ZERO_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_LTE_ZERO_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_LTE_ZERO_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_LTE_ZERO_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_DFE_H1_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_DFE_H1_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_DFE_H1_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_DFE_H1_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000010, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DDC_HYSTERESIS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x3, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DDC_HYSTERESIS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x3, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DDC_HYSTERESIS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x3, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DDC_HYSTERESIS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001110, \
                  0x3, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RECAL_ABORT_16_23_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RECAL_ABORT_16_23_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RECAL_ABORT_16_23_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RECAL_ABORT_16_23_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110101100, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_A_BEFORE_LOFF_N000_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_A_BEFORE_LOFF_N000_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_A_BEFORE_LOFF_N000_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_A_BEFORE_LOFF_N000_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001110, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_IN_PROGRESS_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_IN_PROGRESS_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_IN_PROGRESS_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_IN_PROGRESS_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_RC_ENABLE_DCC_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_RC_ENABLE_DCC_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_RC_ENABLE_DCC_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_RC_ENABLE_DCC_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001010, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_WIDTH_VALID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_WIDTH_VALID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_WIDTH_VALID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_WIDTH_VALID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_BER_FAIL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_BER_FAIL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_BER_FAIL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_BER_FAIL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000001, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_LATCH_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x380, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_LATCH_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x380, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_LATCH_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x380, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_HIST_MIN_EYE_HEIGHT_LATCH_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001011, \
                  0x380, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_1_6_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_1_6_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_DFE_COEF_1_6_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_DFE_COEF_1_6_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001010, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_INIT_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_INIT_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_INIT_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_INIT_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_EOFF_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_EOFF_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_EOFF_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_EOFF_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_CTLE_GAIN_DONE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_CTLE_GAIN_DONE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_CTLE_GAIN_DONE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_CTLE_GAIN_DONE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LATCHOFF_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LATCHOFF_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LATCHOFF_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LATCHOFF_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100010, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_BIST_SPARE_0_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_BIST_SPARE_0_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_BIST_SPARE_0_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_BIST_SPARE_0_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111001011, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b010010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_RX_AD_LOFF_LANE_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b010010000, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QUAD_PH_ADJ_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QUAD_PH_ADJ_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QUAD_PH_ADJ_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QUAD_PH_ADJ_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100110, \
                  0xfc, \
                  2, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PPE_PIPE_RX_EI_INACTIVE_PHASE_0_3_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PPE_PIPE_RX_EI_INACTIVE_PHASE_0_3_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PPE_PIPE_RX_EI_INACTIVE_PHASE_0_3_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PPE_PIPE_RX_EI_INACTIVE_PHASE_0_3_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110110, \
                  0xf00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_B_RESERVED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_B_RESERVED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_B_RESERVED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_B_RESERVED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000011, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_LOFF_SETTING_OVR_ENB_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_LOFF_SETTING_OVR_ENB_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_LOFF_SETTING_OVR_ENB_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_LOFF_SETTING_OVR_ENB_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_LANES_PON_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_LANES_PON_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_LANES_PON_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_LANES_PON_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111010011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_2_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_2_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_2_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b100000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_PCIE_PPE_SAVED_TX_DCC_LANE_2_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b100000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EO_VGA_CTLE_LOOP_NOT_CONVERGED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EO_VGA_CTLE_LOOP_NOT_CONVERGED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EO_VGA_CTLE_LOOP_NOT_CONVERGED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EO_VGA_CTLE_LOOP_NOT_CONVERGED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000000000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_RUNNING_RECAL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_RUNNING_RECAL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_RUNNING_RECAL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_RUNNING_RECAL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110110100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_EOFF_MAX_CHECK_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_EOFF_MAX_CHECK_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_EOFF_MAX_CHECK_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_EOFF_MAX_CHECK_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110100011, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_MARGIN_TIMING_OFFSET_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_MARGIN_TIMING_OFFSET_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_MARGIN_TIMING_OFFSET_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_MARGIN_TIMING_OFFSET_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b000001111, \
                  0xff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_QPA_HYSTERESIS_ENABLE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_QPA_HYSTERESIS_ENABLE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_QPA_HYSTERESIS_ENABLE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_QPA_HYSTERESIS_ENABLE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111100000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_TX_BIST_HS_DAC_THRESH_MIN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_TX_BIST_HS_DAC_THRESH_MIN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_TX_BIST_HS_DAC_THRESH_MIN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_TX_BIST_HS_DAC_THRESH_MIN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b110001111, \
                  0xff00, \
                  8, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_0_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_0_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  LANE, \
                  DATA)


#define MEM_REG_RX_LANE_FAIL_0_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)

#define MEM_REG_RX_LANE_FAIL_0_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff5800, \
                  0b111000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x400, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_BIST_FINAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_BIST_FINAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_BIST_FINAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_BIST_FINAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TRAIN_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TRAIN_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TRAIN_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TRAIN_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_BIST_FINAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_BIST_FINAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_BIST_FINAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_BIST_FINAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_16_31_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_16_31_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_16_31_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_16_31_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_POWER_ON_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_POWER_ON_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_POWER_ON_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_POWER_ON_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_FFE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_FFE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_FFE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_FFE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_IORESET_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_IORESET_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_IORESET_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_IORESET_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_DEBUG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_DEBUG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_DEBUG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_DEBUG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001110, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_POWER_OFF_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_POWER_OFF_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_POWER_OFF_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_POWER_OFF_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_LAB_CODE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_LAB_CODE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_LAB_CODE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_LAB_CODE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_NUM_LANES_RX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_NUM_LANES_RX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_NUM_LANES_RX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_NUM_LANES_RX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0xf800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RECAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RECAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RECAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RECAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_FIFO_INIT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_FIFO_INIT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_FIFO_INIT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_FIFO_INIT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TRAIN_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TRAIN_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TRAIN_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TRAIN_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_LAB_CODE_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_LAB_CODE_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_LAB_CODE_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_LAB_CODE_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_GCR_BUS_ID_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_GCR_BUS_ID_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_GCR_BUS_ID_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_GCR_BUS_ID_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0xfc00, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_POWER_ON_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_POWER_ON_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_POWER_ON_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_POWER_ON_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_TX_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_TX_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_TX_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_TX_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000010, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_FFE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_FFE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_FFE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_FFE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_DCCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_DCCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_DCCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_DCCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_TX_16_31_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_TX_16_31_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_TX_16_31_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_TX_16_31_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000011, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_BIST_FINAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_BIST_FINAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_BIST_FINAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_BIST_FINAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_DCCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_DCCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_DCCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_DCCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_ZCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_ZCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_ZCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_ZCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_PCIE_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_PCIE_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_PCIE_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_PCIE_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_POWER_ON_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_POWER_ON_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_POWER_ON_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_POWER_ON_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x20, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_FIFO_INIT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_FIFO_INIT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_TX_FIFO_INIT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_TX_FIFO_INIT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_LAB_CODE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_LAB_CODE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_LAB_CODE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_LAB_CODE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_FIFO_INIT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_FIFO_INIT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_FIFO_INIT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_FIFO_INIT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x80, \
                  7, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RECAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RECAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RECAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RECAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RECAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RECAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RECAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RECAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8, \
                  3, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_LAB_CODE_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_LAB_CODE_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_LAB_CODE_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_LAB_CODE_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001001, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RX_DETECT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RX_DETECT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_RX_DETECT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_RX_DETECT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_POWER_OFF_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_POWER_OFF_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_POWER_OFF_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_POWER_OFF_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_IORESET_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_IORESET_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_IORESET_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_IORESET_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_HW_REG_INIT_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_HW_REG_INIT_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_HW_REG_INIT_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_HW_REG_INIT_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_SPREAD_EN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_SPREAD_EN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_SPREAD_EN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_SPREAD_EN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x100, \
                  8, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_SERDES_16_TO_1_MODE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_SERDES_16_TO_1_MODE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_SERDES_16_TO_1_MODE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_SERDES_16_TO_1_MODE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_IORESET_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_IORESET_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_IORESET_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_IORESET_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x4000, \
                  14, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_ZCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_ZCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_ZCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_ZCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_16_31_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_16_31_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_16_31_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_16_31_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_RX_00_15_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_RX_00_15_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_RX_00_15_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_RX_00_15_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000000, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_RX_16_31_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_RX_16_31_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_LANES_RX_16_31_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_LANES_RX_16_31_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000001, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RX_DETECT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RX_DETECT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RX_DETECT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RX_DETECT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RX_BIST_TESTS_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RX_BIST_TESTS_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_RX_BIST_TESTS_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_RX_BIST_TESTS_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x40, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_POWER_BANKS_SEL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_POWER_BANKS_SEL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_POWER_BANKS_SEL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_POWER_BANKS_SEL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x60, \
                  5, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_HW_REG_INIT_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_HW_REG_INIT_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_HW_REG_INIT_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_HW_REG_INIT_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TRAIN_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TRAIN_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TRAIN_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TRAIN_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x10, \
                  4, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_STOP_THREAD_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_STOP_THREAD_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_STOP_THREAD_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_STOP_THREAD_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_ZCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_ZCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_TX_ZCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_TX_ZCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x800, \
                  11, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_LAB_CODE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_FFE_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_FFE_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_TX_FFE_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_TX_FFE_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x400, \
                  10, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_BIST_EN_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_BIST_EN_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_BIST_EN_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_BIST_EN_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x2, \
                  1, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_POWER_OFF_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_POWER_OFF_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_POWER_OFF_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_POWER_OFF_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x200, \
                  9, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_16_31_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_16_31_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_16_31_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_16_31_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001101, \
                  0xffff, \
                  0, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RX_DETECT_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RX_DETECT_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_FAIL_RX_DETECT_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_FAIL_RX_DETECT_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001100, \
                  0x2000, \
                  13, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_HW_REG_INIT_PG_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_HW_REG_INIT_PG_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_DONE_HW_REG_INIT_PG_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_DONE_HW_REG_INIT_PG_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001000, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_BIST_PCIE_RATE_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_BIST_PCIE_RATE_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_BIST_PCIE_RATE_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_BIST_PCIE_RATE_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000110, \
                  0x1c, \
                  2, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_THREAD_STOPPED_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001111, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_THREAD_STOPPED_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001111, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_THREAD_STOPPED_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001111, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_THREAD_STOPPED_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000001111, \
                  0x8000, \
                  15, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_FW_NUM_LANES_TX_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_FW_NUM_LANES_TX_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_FW_NUM_LANES_TX_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_FW_NUM_LANES_TX_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000111, \
                  0x7c0, \
                  6, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_DCCAL_PL_PL_PUT(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_DCCAL_PL_PL_GET(REGS, TARGET, THREAD, LANE, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  LANE, \
                  DATA)


#define FW_REG_EXT_CMD_REQ_DCCAL_PL_PUT(REGS, TARGET, THREAD, DATA) \
    REGS->putData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)

#define FW_REG_EXT_CMD_REQ_DCCAL_PL_GET(REGS, TARGET, THREAD, DATA) \
    REGS->getData(\
                  TARGET, \
                  0xffff30e0, \
                  0b000000100, \
                  0x1000, \
                  12, \
                  THREAD, \
                  0x20, \
                  0, \
                  DATA)
