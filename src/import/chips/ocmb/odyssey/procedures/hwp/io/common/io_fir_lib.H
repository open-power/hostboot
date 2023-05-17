/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/common/io_fir_lib.H $ */
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

///
/// @file io_fir_lib.H
///
/// @brief Function lib definition file for IO hwps
///
/// *HWP HW Maintainer: Josh Chica <Josh.Chica@ibm.com>
/// *HWP FW Maintainer:
/// *HWP Consumed by: SBE
///

#pragma once

#include <fapi2.H>


enum IOPPE_FIR_BITS
{
    SCOMFIR_PARITY_ERROR = 0,
    IO0_RX_INVALID_STATE_OR_PARITY_ERROR = 1,
    IO1_RX_INVALID_STATE_OR_PARITY_ERROR = 2,
    IOT0_RX0_ECC_UNKNOWN_ERROR = 3,
    IOT0_RX1_ECC_UNKNOWN_ERROR = 4,
    IO0_TX_INVALID_STATE_OR_PARITY_ERROR = 5,
    IO1_TX_INVALID_STATE_OR_PARITY_ERROR = 6,
    IOT1_RX0_ECC_UNKNOWN_ERROR = 7,
    IOT1_RX1_ECC_UNKNOWN_ERROR = 8,
    IOO0_PIPE_INVALID_STATE_OR_PARITY_ERROR_IOT0_RX0_ECC_BAD_LANE_FOUND = 9,
    IOT0_RX1_ECC_BAD_LANE_FOUND = 10,
    IOO0_PIPE_PMB_ERROR_IOT1_RX0_ECC_BAD_LANE_FOUND = 11,
    IOT1_RX1_ECC_BAD_LANE_FOUND = 12,
    PPE_INT_HWERROR = 13,
    PPE_EXT_HWERROR = 14,
    PPE_HALT_WATCHDOG_OR_INTERRUPT = 15,
    PPE_HALT_DEBUG = 16,
    PPE_HALTED = 17,
    PPE_WATCHDOG_TIMEOUT = 18,
    PPE_ARB_MISSED_SCRUB_TICK = 19,
    PPE_ARB_ARRAY_UNCORRECTABLE_ERROR = 20,
    PPE_ARB_ARRAY_CORRECTABLE_ERROR = 21,
    PPE_CODE_RECAL_ABORT = 22,
    PPE_CODE_FATAL_ERROR = 23,
    PPE_CODE_BAD_LANE_WARNING = 24,
    PPE_CODE_DFT_ERROR = 25,
    PPE_CODE_RECAL_NOT_RUN = 26,
    PPE_CODE_THREAD_LOCKED = 27,
    PPE_CODE_THREAD_ACTIVE_TIME_EXCEEDED = 28,
    PPE_CODE_BAD_LANES_OVER_MAX = 29,
};

enum ERROR_MASK_FIR_BITS
{
    MASK_INSUFFICIENT_WORKING_LANES = 51,
    MASK_TX_DEGRADE_MODE = 45,
    MASK_LOST_BLOCK_LOCK = 30,
    MASK_EDPL_THRESH_REACHED = 27,
    MASK_RX_PERFORMANCE_THRESH_BREACH = 26,
    MASK_TX_PERFORMANCE_THRESH_BREACH = 25,
    MASK_REMOTE_LINK_ERRRO_4 = 19,
    MASK_REMOTE_LINK_ERROR_5 = 18,
    MASK_SKITTER_ERROR = 15,
    MASK_SKITTER_DRIFT_DETECTED = 14,
};

enum ERROR_ACTION_FIR_BITS
{
    ACTION_1 = 60,
    ACTION_2 = 56,
    ACTION_LEN = 4
};

enum SKIT_CTL_FIR_BITS
{
    IRQ = 43,
    CLKALIGN = 44,
};

enum MC_OMI_FIR_BITS
{
    DL0_FATAL_ERROR = 1,
    DL0_DATA_UE = 2,
    DL0_CRC_ERROR = 4,
    DL0_X4_MODE = 6,
    DL0_EDPL = 7,
    DL0_TIMEOUT = 8,
    DL0_ERROR_RETRAIN = 10,
    DL0_EDPL_RETRAIN = 11,
    DL0_SKITTER_ERROR = 21,
    DL0_SKITTER_DRIFT = 22,
};

enum TLX_FIR_BITS
{
    IN01 = 1,
    IN02 = 2,
    IN03 = 3,
    IN04 = 4,
    IN05 = 5,
    IN06 = 6,
    IN07 = 7,
};

template<fapi2::TargetType K, fapi2::MulticastType M = fapi2::MULTICAST_OR, typename V = fapi2::plat_target_handle_t>
class io_ppe_firs
{
    public:
        io_ppe_firs(uint64_t i_lfir_rw_wclear, uint64_t i_dl0_error, uint64_t i_error_action,
                    uint64_t i_mc_omi_rw_wclear, uint64_t i_skit_ctl, uint64_t i_tlx_rw_wclear) :
            iv_lfir_rw_wclear(i_lfir_rw_wclear), iv_dl0_error_mask(i_dl0_error), iv_error_action(i_error_action),
            iv_mc_omi_rw_wclear(i_mc_omi_rw_wclear), iv_skit_ctl(i_skit_ctl), iv_tlx_rw_wclear(i_tlx_rw_wclear)
        {
            FAPI_DBG("io_ppe_firs constructor");

        }

        fapi2::ReturnCode ioppe_fir_set_pre_start(const fapi2::Target<K, M, V>& i_target);

        fapi2::ReturnCode ioppe_fir_set_post_start(const fapi2::Target<K, M, V>& i_target);

        fapi2::ReturnCode mc_omi_fir_set(const fapi2::Target<K, M, V>& i_target);

        fapi2::ReturnCode tlx_fir_set(const fapi2::Target<K, M, V>& i_target);
    private:
        // The FIR registers are RW_Clear
        // Mask/recoverable/checkstop regs
        // Mask is +2 from FIR reg
        // Checkstop is +4 from FIR reg
        // Recoverable is +5 from FIR reg
        const uint64_t iv_lfir_rw_wclear;
        const uint64_t iv_dl0_error_mask;
        const uint64_t iv_error_action;
        const uint64_t iv_mc_omi_rw_wclear;
        const uint64_t iv_skit_ctl;
        const uint64_t iv_tlx_rw_wclear;
};

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_firs<K, M, V>::ioppe_fir_set_pre_start(const fapi2::Target<K, M, V>& i_target)
{
    FAPI_DBG("Start IO PPE FIRs");
    // Mask/recoverable regs
    const uint64_t l_lfir_rw_wclear_mask = iv_lfir_rw_wclear + 2;
    const uint64_t l_lfir_rw_wclear_rec = iv_lfir_rw_wclear + 5;

    fapi2::buffer<uint64_t> l_buffer = 0;

    // Unmask other PHY PPE FIRs
    FAPI_DBG("Unmask PHY PPE FIRs.");
    l_buffer.setBit<IO0_RX_INVALID_STATE_OR_PARITY_ERROR>();
    l_buffer.setBit<IO0_TX_INVALID_STATE_OR_PARITY_ERROR>();
    l_buffer.setBit<PPE_INT_HWERROR>();
    l_buffer.setBit<PPE_EXT_HWERROR>();
    l_buffer.setBit<PPE_HALT_WATCHDOG_OR_INTERRUPT>();
    l_buffer.setBit<PPE_HALT_DEBUG>();
    l_buffer.setBit<PPE_WATCHDOG_TIMEOUT>();
    l_buffer.setBit<PPE_ARB_MISSED_SCRUB_TICK>();
    l_buffer.setBit<PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>();
    l_buffer.setBit<PPE_ARB_ARRAY_CORRECTABLE_ERROR>();
    l_buffer.setBit<PPE_CODE_FATAL_ERROR>();
    l_buffer.setBit<PPE_CODE_BAD_LANE_WARNING>();
    l_buffer.setBit<PPE_CODE_RECAL_NOT_RUN>();
    l_buffer.setBit<PPE_CODE_THREAD_LOCKED>();
    FAPI_TRY(fapi2::putScom(i_target, l_lfir_rw_wclear_mask, l_buffer));
    l_buffer.flush<0>();

    l_buffer.setBit<IO0_RX_INVALID_STATE_OR_PARITY_ERROR>();
    l_buffer.setBit<IO0_TX_INVALID_STATE_OR_PARITY_ERROR>();
    l_buffer.setBit<PPE_INT_HWERROR>();
    l_buffer.setBit<PPE_EXT_HWERROR>();
    l_buffer.setBit<PPE_HALT_WATCHDOG_OR_INTERRUPT>();
    l_buffer.setBit<PPE_HALT_DEBUG>();
    l_buffer.setBit<PPE_HALTED>();
    l_buffer.setBit<PPE_WATCHDOG_TIMEOUT>();
    l_buffer.setBit<PPE_ARB_MISSED_SCRUB_TICK>();
    l_buffer.setBit<PPE_ARB_ARRAY_UNCORRECTABLE_ERROR>();
    l_buffer.setBit<PPE_ARB_ARRAY_CORRECTABLE_ERROR>();
    l_buffer.setBit<PPE_CODE_FATAL_ERROR>();
    l_buffer.setBit<PPE_CODE_RECAL_NOT_RUN>();
    l_buffer.setBit<PPE_CODE_THREAD_LOCKED>();
    FAPI_TRY(fapi2::putScom(i_target, l_lfir_rw_wclear_rec, l_buffer));
    l_buffer.flush<0>();

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_firs<K, M, V>::ioppe_fir_set_post_start(const fapi2::Target<K, M, V>& i_target)
{
    FAPI_DBG("Start IO PPE FIRs");
    // Mask/recoverable regs
    const uint64_t l_lfir_rw_wclear_mask = iv_lfir_rw_wclear + 2;

    fapi2::buffer<uint64_t> l_buffer = 0;

    // Unmask other PHY PPE FIRs
    FAPI_DBG("Unmask PHY PPE FIRs.");
    l_buffer.setBit<PPE_HALTED>();
    FAPI_TRY(fapi2::putScom(i_target, l_lfir_rw_wclear_mask, l_buffer));

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_firs<K, M, V>::mc_omi_fir_set(const fapi2::Target<K, M, V>& i_target)
{
    FAPI_DBG("Start MC OMI FIRs");

    // Mask/recoverable regs
    const uint64_t l_mc_omi_rw_wclear_mask = iv_mc_omi_rw_wclear + 2;
    const uint64_t l_mc_omi_w0x_or_mask = iv_mc_omi_rw_wclear + 3;
    const uint64_t l_mc_omi_xstop = iv_mc_omi_rw_wclear + 4;
    const uint64_t l_mc_omi_rec = iv_mc_omi_rw_wclear + 5;

    fapi2::buffer<uint64_t> l_buffer = 0;

    // error action pre-reqs for FIRs
    FAPI_TRY(fapi2::getScom(i_target, iv_error_action, l_buffer));
    l_buffer.insertFromRight<ACTION_1, ACTION_LEN, uint8_t>(0b0001);
    l_buffer.insertFromRight<ACTION_2, ACTION_LEN, uint8_t>(0b0001);
    FAPI_TRY(fapi2::putScom(i_target, iv_error_action, l_buffer));
    l_buffer.flush<0>();

    // dl0 error masks pre-reqs for FIRs
    FAPI_TRY(fapi2::getScom(i_target, iv_dl0_error_mask, l_buffer));
    l_buffer.setBit<MASK_INSUFFICIENT_WORKING_LANES>();
    l_buffer.setBit<MASK_TX_DEGRADE_MODE>();
    l_buffer.clearBit<MASK_LOST_BLOCK_LOCK>();
    l_buffer.setBit<MASK_TX_PERFORMANCE_THRESH_BREACH>();
    l_buffer.clearBit<MASK_RX_PERFORMANCE_THRESH_BREACH>();
    l_buffer.setBit<MASK_EDPL_THRESH_REACHED>();
    l_buffer.clearBit<MASK_REMOTE_LINK_ERRRO_4>();
    l_buffer.clearBit<MASK_REMOTE_LINK_ERROR_5>();
    l_buffer.clearBit<MASK_SKITTER_ERROR>();
    l_buffer.clearBit<MASK_SKITTER_DRIFT_DETECTED>();
    FAPI_TRY(fapi2::putScom(i_target, iv_dl0_error_mask, l_buffer));
    l_buffer.flush<0>();

    // Skit_ctl pre-reqs for FIRs
    FAPI_TRY(fapi2::getScom(i_target, iv_skit_ctl, l_buffer));
    l_buffer.clearBit<IRQ>();
    l_buffer.setBit<CLKALIGN>();
    FAPI_TRY(fapi2::putScom(i_target, iv_skit_ctl, l_buffer));
    l_buffer.flush<0>();

    // Unmask FIRs
    l_buffer.setBit<DL0_FATAL_ERROR>();
    l_buffer.setBit<DL0_DATA_UE>();
    l_buffer.setBit<DL0_X4_MODE>();
    l_buffer.setBit<DL0_TIMEOUT>();
    l_buffer.setBit<DL0_ERROR_RETRAIN>();
    l_buffer.setBit<DL0_EDPL_RETRAIN>();
    l_buffer.setBit<DL0_SKITTER_ERROR>();
    l_buffer.setBit<DL0_SKITTER_DRIFT>();
    FAPI_TRY(fapi2::putScom(i_target, l_mc_omi_rw_wclear_mask, l_buffer));
    l_buffer.flush<0>();

    // Mask FIRs
    l_buffer.setBit<DL0_CRC_ERROR>();
    l_buffer.setBit<DL0_EDPL>();
    FAPI_TRY(fapi2::putScom(i_target, l_mc_omi_w0x_or_mask, l_buffer));
    l_buffer.flush<0>();

    // Set the recoverable FIRs
    l_buffer.setBit<DL0_X4_MODE>();
    l_buffer.setBit<DL0_TIMEOUT>();
    l_buffer.setBit<DL0_ERROR_RETRAIN>();
    l_buffer.setBit<DL0_EDPL_RETRAIN>();
    l_buffer.setBit<DL0_SKITTER_ERROR>();
    l_buffer.setBit<DL0_SKITTER_DRIFT>();
    FAPI_TRY(fapi2::putScom(i_target, l_mc_omi_rec, l_buffer));
    l_buffer.flush<0>();

    // Set the Checkstop FIRs
    l_buffer.setBit<DL0_FATAL_ERROR>();
    l_buffer.setBit<DL0_DATA_UE>();
    FAPI_TRY(fapi2::putScom(i_target, l_mc_omi_xstop, l_buffer));
    l_buffer.flush<0>();

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}

template <fapi2::TargetType K, fapi2::MulticastType M, typename V>
fapi2::ReturnCode io_ppe_firs<K, M, V>::tlx_fir_set(const fapi2::Target<K, M, V>& i_target)
{
    FAPI_DBG("Start TLX FIRs");

    // Mask/recoverable regs
    const uint64_t l_tlx_rw_wclear_mask = iv_tlx_rw_wclear + 2;
    const uint64_t l_tlx_xstop = iv_tlx_rw_wclear + 4;

    fapi2::buffer<uint64_t> l_buffer = 0;

    // Unmask the FIRs
    l_buffer.setBit<IN01>();
    l_buffer.setBit<IN02>();
    l_buffer.setBit<IN03>();
    l_buffer.setBit<IN04>();
    l_buffer.setBit<IN05>();
    l_buffer.setBit<IN06>();
    l_buffer.setBit<IN07>();
    FAPI_TRY(fapi2::putScom(i_target, l_tlx_rw_wclear_mask, l_buffer));
    l_buffer.flush<0>();

    // Checkstop the FIRs
    l_buffer.setBit<IN01>();
    l_buffer.setBit<IN02>();
    l_buffer.setBit<IN03>();
    l_buffer.setBit<IN04>();
    l_buffer.setBit<IN05>();
    l_buffer.setBit<IN06>();
    l_buffer.setBit<IN07>();
    FAPI_TRY(fapi2::putScom(i_target, l_tlx_xstop, l_buffer));
    l_buffer.flush<0>();

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
