/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/common/include/ody_scom_omi_odc_fields.H $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021,2022                        */
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
#pragma once
#include "scomt_regs.H"

#define SCOMT_OMI_USE_D_REG_CMN_CONFIG \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_CMN_CONFIG_t : public ScomRegister<0x801240E> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_CMN_CONFIG_t); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, SPARE, 0, 6); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, RX_EDGE_ENA, 6); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, RX_EDGE_MARGIN, 7, 5); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, DISABLE_XSTOPIN, 12); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, RECAL_TIMER, 13, 3); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, 1US_TMR, 16, 12); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, DBG_EN, 28); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, DBG_SEL, 29, 3); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, RD_RST, 32); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, PRE_SCALAR, 33, 3); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, FREEZE, 36); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, PORT_SEL, 37, 3); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR3_PS, 40, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR3_ES, 42, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR2_PS, 44, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR2_ES, 46, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR1_PS, 48, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR1_ES, 50, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR0_PS, 52, 2); \
            _SCOMT_INT_FIELD(D_REG_CMN_CONFIG_t, CNTR0_ES, 54, 2); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR3_PE, 56); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR2_PE, 57); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR1_PE, 58); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR0_PE, 59); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR3_EN, 60); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR2_EN, 61); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR1_EN, 62); \
            _SCOMT_BOOL_FIELD(D_REG_CMN_CONFIG_t, CNTR0_EN, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_CONFIG0 \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_CONFIG0_t : public ScomRegister<0x8012410> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_CONFIG0_t); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, ENABLE, 0); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, CFG0_SPARE_61_58, 1, 5); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, CFG_TL_CREDITS, 6, 6); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, TL_EVENT_ACTIONS, 12, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, TL_ERROR_ACTIONS, 16, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, FWD_PROGRESS_TIMER, 20, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, REPLAY_RSVD_ENTRIES, 24, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, DEBUG_SELECT, 28, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, DEBUG_ENABLE, 31); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, DL2TL_DATA_PARITY_INJECT, 32); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, CONTROL_PARITY_INJECT, 33); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, ECC_UE_INJECTION, 34); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, ECC_CE_INJECTION, 35); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, FP_DISABLE, 36); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, RX_LN_REV_ENA, 37); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, TX_LN_REV_ENA, 38); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, CFG0_SPARE_24, 39); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, PHY_CNTR_LIMIT, 40, 4); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, RUNLANE_OVRD_ENABLE, 44); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, PWRMGT_ENABLE, 45); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, CFG0_SPARE_17, 46); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, HALF_WIDTH_BACKOFF_ENABLE, 47); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, SUPPORTED_MODES, 48, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, TRAIN_MODE, 52, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG0_t, VERSION, 56, 6); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, RETRAIN, 62); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG0_t, RESET, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_CONFIG1 \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_CONFIG1_t : public ScomRegister<0x8012411> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_CONFIG1_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, CFG1_SPARE_63_62, 0, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, LANE_WIDTH, 2, 2); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, PREIPL_PRBS_ENA, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, PREIPL_PRBS_TIME, 5, 3); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, B_HYSTERESIS, 8, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, A_HYSTERESIS, 12, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, B_PATTERN_LENGTH, 16, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, A_PATTERN_LENGTH, 18, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, TX_PERF_DEGRADED, 20, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, RX_PERF_DEGRADED, 22, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, TX_LANES_DISABLE, 24, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, RX_LANES_DISABLE, 32, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, MACRO_DBG_SEL, 40, 4); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, RESET_ERR_HLD, 44); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, RESET_ERR_CAP, 45); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, RESET_TSHD_REG, 46); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, RESET_RMT_MSG, 47); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, INJECT_CRC_DIRECTION, 48); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, INJECT_CRC_RATE, 49, 3); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, INJECT_CRC_LANE, 52, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, INJECT_CRC_ERROR, 55); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, EDPL_TIME, 56, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CONFIG1_t, EDPL_THRESHOLD, 60, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CONFIG1_t, EDPL_ENA, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_CYA2 \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_CYA2_t : public ScomRegister<0x801241C> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_CYA2_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA2_t, 3_SELECT, 48, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA2_t, 2_SELECT, 52, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA2_t, 1_SELECT, 56, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA2_t, 0_SELECT, 60, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_CYA_BITS \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_CYA_BITS_t : public ScomRegister<0x801241F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_CYA_BITS_t); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, PRBS15_NPRBS7, 0); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, ALLOW_UNDEGRADE, 1); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, KEEP_DEGRADED_TX_ON, 2); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, KEEP_DEGRADED_RX_ON, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, SERIAL_PM_RECAL, 4); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, FAST_PM_WIDEN, 5); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, FULL_RETRAINS, 6); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, SKIP_AB_TEST, 7); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, SKIP_SYNC_WAIT, 8); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, Z_LANE_NUMS, 9); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, PM_TIMEOUT, 10, 2); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, LEAK_DISABLE, 12); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RECAL_NOWAIT, 13); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RECAL_OVERRUN_EN, 14); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, REDO_CLK_ALIGN, 15); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, MESO_LO_THR, 16, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, MESO_HI_THR, 18, 2); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, MESO_LO_ACTION, 20); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, MESO_HI_ACTION, 21); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, SPARE_41, 22); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RX_PN_SWAP_OVERRIDE_SELECT, 23); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, RX_PN_SWAP_OVERRIDE, 24, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, TRIG_SEL, 32, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, SPARE_27_20, 36, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, TX_PSAVE_DELAY_TIMER, 44, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, FAST_RETRAIN_DISABLE, 47); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, SPARE15, 48); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, KILL_CRC_REPLAY, 49); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RETRAIN_CRC_REPLAY, 50); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, PM_DISABLE_EDPL, 51); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RETRAIN_CRC_RETRAIN, 52); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, RETRAIN_CRC_RESET, 53); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, FRBUF_FULL, 54); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, FRBUF_FULL_REPLAY, 55); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, PM_RETRAIN, 56); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, PM_RESET, 57); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, CRC_RETRAIN, 58); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, CRC_RESET, 59); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, MESO_BUFFER_ENABLE, 60); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_CYA_BITS_t, MESO_BUFFER_START, 61); \
            _SCOMT_INT_FIELD(D_REG_DL0_CYA_BITS_t, MESO_BUFFER_DEPTH, 62, 2); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_DEBUG_AID \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_DEBUG_AID_t : public ScomRegister<0x801241E> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_DEBUG_AID_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_DEBUG_AID_t, RX_RECAL_MAX_LANE, 32, 3); \
            _SCOMT_INT_FIELD(D_REG_DL0_DEBUG_AID_t, RX_RECAL_MAX_TIME, 35, 5); \
            _SCOMT_INT_FIELD(D_REG_DL0_DEBUG_AID_t, RX_LANE_INVERTED, 40, 8); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_DEBUG_AID_t, PRBS_RESET, 55); \
            _SCOMT_INT_FIELD(D_REG_DL0_DEBUG_AID_t, PRBS_STATUS, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_EDPL_MAX_COUNT \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_EDPL_MAX_COUNT_t : public ScomRegister<0x8012415> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_EDPL_MAX_COUNT_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 7_MAX_COUNT, 0, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 6_MAX_COUNT, 8, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 5_MAX_COUNT, 16, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 4_MAX_COUNT, 24, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 3_MAX_COUNT, 32, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 2_MAX_COUNT, 40, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 1_MAX_COUNT, 48, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_EDPL_MAX_COUNT_t, 0_MAX_COUNT, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_ERROR_ACTION \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_ERROR_ACTION_t : public ScomRegister<0x801241D> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_ERROR_ACTION_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 12_ACTION, 16, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 11_ACTION, 20, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 10_ACTION, 24, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 9_ACTION, 28, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 8_ACTION, 32, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 7_ACTION, 36, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 6_ACTION, 40, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 5_ACTION, 44, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 4_ACTION, 48, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 3_ACTION, 52, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 2_ACTION, 56, 4); \
            _SCOMT_INT_FIELD(D_REG_DL0_ERROR_ACTION_t, 1_ACTION, 60, 4); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_ERROR_HOLD \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_ERROR_HOLD_t : public ScomRegister<0x8012413> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_ERROR_HOLD_t); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 47, 16); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 46, 17); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 45, 18); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 44, 19); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 43, 20); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 42, 21); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 41, 22); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 40, 23); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 39, 24); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 38, 25); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 37, 26); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 36, 27); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 35, 28); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 34, 29); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 33, 30); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 32, 31); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 31, 32); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 30, 33); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 29, 34); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 28, 35); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 27, 36); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 26, 37); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 25, 38); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 24, 39); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 23, 40); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 22, 41); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 21, 42); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 20, 43); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 19, 44); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 18, 45); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 17, 46); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 16, 47); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 15, 48); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 14, 49); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 13, 50); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 12, 51); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 11, 52); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 10, 53); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 09, 54); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 08, 55); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 07, 56); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 06, 57); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 05, 58); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 04, 59); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 03, 60); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 02, 61); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 01, 62); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_HOLD_t, 00, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_ERROR_MASK \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_ERROR_MASK_t : public ScomRegister<0x8012412> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_ERROR_MASK_t); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 47, 16); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 46, 17); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 45, 18); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 44, 19); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 43, 20); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 42, 21); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 41, 22); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 40, 23); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 39, 24); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 38, 25); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 37, 26); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 36, 27); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 35, 28); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 34, 29); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 33, 30); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 32, 31); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 31, 32); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 30, 33); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 29, 34); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 28, 35); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 27, 36); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 26, 37); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 25, 38); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 24, 39); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 23, 40); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 22, 41); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 21, 42); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 20, 43); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 19, 44); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 18, 45); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 17, 46); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 16, 47); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 15, 48); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 14, 49); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 13, 50); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 12, 51); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 11, 52); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 10, 53); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 09, 54); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 08, 55); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 07, 56); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 06, 57); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 05, 58); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 04, 59); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 03, 60); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 02, 61); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 01, 62); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_ERROR_MASK_t, 00, 63); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_RMT_CONFIG \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_RMT_CONFIG_t : public ScomRegister<0x8012418> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_RMT_CONFIG_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_RMT_CONFIG_t, CFG_DL0_RMT_CONFIG, 32, 32); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_RMT_INFO \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_RMT_INFO_t : public ScomRegister<0x8012419> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_RMT_INFO_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_RMT_INFO_t, DL0_RMT_MESSAGE, 0, 64); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_STATUS \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_STATUS_t : public ScomRegister<0x8012416> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_STATUS_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, TRAINED_MODE, 0, 4); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, RX_LANE_REVERSED, 4); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, TX_LANE_REVERSED, 5); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, IDLE_SIZE, 6); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, ACK_PTRS_EQUAL, 7); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, CLK_ALIGN_PENDING, 8); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, SPARE_54, 9); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, ACTUAL_RX_WIDTH, 10, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, REQUESTED_LN_WIDTH, 12, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, ACTUAL_TX_WIDTH, 14, 2); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, TX_TRAINED_LANES, 16, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, RX_TRAINED_LANES, 24, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, ENDPOINT_INFO, 32, 15); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, PM_DISABLED, 47); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, SPARE_15, 48); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, TRAINING_STATE_MACHINE, 49, 3); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, SPARE_11_9, 52, 3); \
            _SCOMT_BOOL_FIELD(D_REG_DL0_STATUS_t, DESKEW_DONE, 55); \
            _SCOMT_INT_FIELD(D_REG_DL0_STATUS_t, LANES_DISABLED, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_DL0_TRAINING_STATUS \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_DL0_TRAINING_STATUS_t : public ScomRegister<0x8012417> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_DL0_TRAINING_STATUS_t); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, RX_PATTERN_A, 0, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, RX_PATTERN_B, 8, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, SYNC_PATTERN, 16, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, PHY_INIT_DONE, 24, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, BLOCK_LOCKED, 32, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, RX_TS1, 40, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, RX_TS2, 48, 8); \
            _SCOMT_INT_FIELD(D_REG_DL0_TRAINING_STATUS_t, RX_TS3, 56, 8); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_t : public ScomRegister<0x8012400> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_t); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, LFIR_PAR_ERR, 0); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_FATAL_ERROR, 1); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_DATA_UE, 2); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_FLIT_CE, 3); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_CRC_ERROR, 4); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_NACK, 5); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_X4_MODE, 6); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_EDPL, 7); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_TIMEOUT, 8); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_REMOTE_RETRAIN, 9); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ERROR_RETRAIN, 10); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_EDPL_RETRAIN, 11); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_TRAINED, 12); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR0, 13); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR1, 14); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR2, 15); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR3, 16); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR4, 17); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR5, 18); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR6, 19); \
            _SCOMT_BOOL_FIELD(D_REG_MC_OMI_FIR_t, DL0_ENDPOINT_FIR7, 20); \
            _SCOMT_EXTRA_PUTSCOM(putScom_SET, 0x8012401); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_CFGLXSTOP \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_CFGLXSTOP_t : public ScomRegister<0x8012407> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_CFGLXSTOP_t); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_CFGRECOV \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_CFGRECOV_t : public ScomRegister<0x8012405> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_CFGRECOV_t); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_CFGSPATTN \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_CFGSPATTN_t : public ScomRegister<0x8012406> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_CFGSPATTN_t); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_CFGXSTOP \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_CFGXSTOP_t : public ScomRegister<0x8012404> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_CFGXSTOP_t); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_MASK \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_MASK_t : public ScomRegister<0x8012402> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_MASK_t); \
            _SCOMT_EXTRA_PUTSCOM(putScom_SET, 0x8012403); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_MC_OMI_FIR_WOF \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_MC_OMI_FIR_WOF_t : public ScomRegister<0x8012408> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_MC_OMI_FIR_WOF_t); \
            _SCOMT_INT_FIELD(D_REG_MC_OMI_FIR_WOF_t, MC_OMI_FIR_WOF, 0, 43); \
    }; _SCOMT_CLOSE_NAMESPACE

#define SCOMT_OMI_USE_D_REG_PMU_CNTR \
    _SCOMT_OPEN_NAMESPACE(omi) \
    class D_REG_PMU_CNTR_t : public ScomRegister<0x801240F> \
    { \
        public: \
            _SCOMT_REGISTER_BEGIN(D_REG_PMU_CNTR_t); \
            _SCOMT_INT_FIELD(D_REG_PMU_CNTR_t, 3, 0, 16); \
            _SCOMT_INT_FIELD(D_REG_PMU_CNTR_t, 2, 16, 16); \
            _SCOMT_INT_FIELD(D_REG_PMU_CNTR_t, 1, 32, 16); \
            _SCOMT_INT_FIELD(D_REG_PMU_CNTR_t, 0, 48, 16); \
    }; _SCOMT_CLOSE_NAMESPACE
