/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/ocmb/odyssey/procedures/hwp/io/ody_omi_hss_ppe_start.C $ */
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
///------------------------------------------------------------------------------
/// @file ody_omi_hss_ppe_start.C
/// @brief Odyssey HSS PPE start HWP
///
/// *HWP HW Maintainer : Josh Chica <josh.chica@ibm.com>
/// *HWP FW Maintainer :
/// *HWP Consumed by: SBE
///------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <ody_omi_hss_ppe_start.H>
#include <fapi2_subroutine_executor.H>
#include <ody_scom_omi_ioo.H>
#include <ody_putsram.H>

// Scomt definitions
SCOMT_OMI_USE_PHY_PPE_WRAP0_XIXCR
SCOMT_OMI_USE_PHY_PPE_WRAP0_SCOM_CNTL
SCOMT_OMI_USE_PHY_PPE_WRAP0_ARB_CSCR
SCOMT_OMI_USE_PHY_PPE_WRAP0_XIDBGPRO
SCOMT_OMI_USE_PHY_SCOM_MAC0_LFIR_REG
SCOMT_OMI_USE_PHY_SCOM_MAC0_LFIR_MASK_REG

using namespace scomt::omi;

//------------------------------------------------------------------------------
// Function definitions
//------------------------------------------------------------------------------
fapi2::ReturnCode ody_omi_hss_ppe_start(const fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP>& i_target)
{
    FAPI_DBG("Start");
    PHY_PPE_WRAP0_XIXCR_t WRAP0_XIXCR;
    PHY_PPE_WRAP0_SCOM_CNTL_t WRAP0_SCOM_CNTL;
    PHY_PPE_WRAP0_ARB_CSCR_t WRAP0_ARB_CSCR;
    PHY_PPE_WRAP0_XIDBGPRO_t WRAP0_XIDBGPRO;
    PHY_SCOM_MAC0_LFIR_REG_t MAC0_LFIR_REG;
    PHY_SCOM_MAC0_LFIR_MASK_REG_t MAC0_LFIR_MASK_REG;

    uint32_t l_iar;

    // Enable SRAM scrub
    FAPI_TRY(WRAP0_XIXCR.getScom(i_target),
             "Error getscom to WRAP0_XIXCR.");
    WRAP0_ARB_CSCR.set_SRAM_SCRUB_ENABLE(1);
    FAPI_TRY(WRAP0_XIXCR.putScom(i_target),
             "Error putscom to WRAP0_XIXCR (Enable SRAM scrub).");

    // Hard reset PPE
    FAPI_DBG("IO hard reset.");
    WRAP0_XIXCR.set_PPE_XIXCR_XCR(6); // Write 0b110
    FAPI_TRY(WRAP0_XIXCR.putScom(i_target),
             "Error putscom to PPE_XIXCR_XCR (reset PPE).");

    // Verify IAR @ reset vector loc
    FAPI_DBG("Verify IAR reset.");
    FAPI_TRY(WRAP0_XIDBGPRO.getScom(i_target),
             "Error getscom to WRAP0_XIDBGPRO.");
    l_iar = WRAP0_XIDBGPRO.get_IAR();
    FAPI_ASSERT(
        l_iar == 0x3fff8010,        // fffe0040 >> 2
        fapi2::ODY_OMI_PPE_RESET()
        .set_TARGET_CHIP(i_target),
        "IAR (0x%8x) did not reset.", l_iar);

    // Resume PPE
    FAPI_DBG("IO resume.");
    WRAP0_XIXCR.set_PPE_XIXCR_XCR(2); // Write 0b010
    FAPI_TRY(WRAP0_XIXCR.putScom(i_target),
             "Error putscom to PPE_XIXCR_XCR (resume PPE).");

    // Verify IAR is cleared
    FAPI_DBG("Verify IAR cleared.");
    FAPI_TRY(WRAP0_XIDBGPRO.getScom(i_target),
             "Error getscom to WRAP0_XIDBGPRO.");
    l_iar = WRAP0_XIDBGPRO.get_IAR();
    FAPI_ASSERT(
        l_iar != 0x3fff8010,        // fffe0040 >> 2
        fapi2::ODY_OMI_PPE_RESET()
        .set_TARGET_CHIP(i_target),
        "IAR (0x%8x) did not resume.", l_iar);

    // Clear Halted FIR Bit
    FAPI_DBG("Clear halted FIR.");
    FAPI_TRY(MAC0_LFIR_REG.getScom(i_target),
             "Error getscom to MAC0_LFIR_REG.");
    MAC0_LFIR_REG.set_PPE_HALTED(0);
    FAPI_TRY(MAC0_LFIR_REG.putScom(i_target),
             "Error putscom to MAC0_LFIR_REG (clear halt).");

    // Unmask other PHY PPE FIRs
    FAPI_DBG("Unmask PHY PPE FIRs.");
    FAPI_TRY(MAC0_LFIR_MASK_REG.getScom(i_target),
             "Error getscom to MAC0_LFIR_REG.");
    MAC0_LFIR_MASK_REG.set_SCOMFIR_PARITY_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_IO0_RX_INVALID_STATE_OR_PARITY_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_IO1_RX_INVALID_STATE_OR_PARITY_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOT0_RX0_ECC_UNKNOWN_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOT0_RX1_ECC_UNKNOWN_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IO0_TX_INVALID_STATE_OR_PARITY_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_IO1_TX_INVALID_STATE_OR_PARITY_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOT1_RX0_ECC_UNKNOWN_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOT1_RX1_ECC_UNKNOWN_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOO0_PIPE_INVALID_STATE_OR_PARITY_ERROR_IOT0_RX0_ECC_BAD_LANE_FOUND_MASK(0);
    MAC0_LFIR_MASK_REG.set_IOT0_RX1_ECC_BAD_LANE_FOUND_MASK(1);
    MAC0_LFIR_MASK_REG.set_IOO0_PIPE_PMB_ERROR_IOT1_RX0_ECC_BAD_LANE_FOUND_MASK(0);
    MAC0_LFIR_MASK_REG.set_IOT1_RX1_ECC_BAD_LANE_FOUND_MASK(1);
    MAC0_LFIR_MASK_REG.set_PPE_INT_HWERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_EXT_HWERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_HALT_WATCHDOG_OR_INTERRUPT_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_HALT_DEBUG_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_HALTED_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_WATCHDOG_TIMEOUT_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_ARB_MISSED_SCRUB_TICK_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_ARB_ARRAY_UNCORRECTABLE_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_ARB_ARRAY_CORRECTABLE_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_RECAL_ABORT_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_FATAL_ERROR_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_BAD_LANE_WARNING_MASK(1);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_DFT_ERROR_MASK(1);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_RECAL_NOT_RUN_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_THREAD_LOCKED_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_THREAD_ACTIVE_TIME_EXCEEDED_MASK(0);
    MAC0_LFIR_MASK_REG.set_PPE_CODE_BAD_LANES_OVER_MAX_MASK(1);
    FAPI_TRY(MAC0_LFIR_MASK_REG.putScom(i_target),
             "Error putscom to MAC0_LFIR_REG (unmask PPE FIR).");

fapi_try_exit:
    FAPI_DBG("End");
    return fapi2::current_err;
}
