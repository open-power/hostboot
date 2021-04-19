/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_xgpe_init.C $   */
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
///
/// @file p10_pm_xgpe_init.C
/// @brief  Start and Halt the Auxillary GPE (XGPE)
///
// *HWP HWP Owner       :    Greg Still  <stillgs@us.ibm.com>
// *HWP Backup Owner    :    Rahul Batra <rbatra@us.ibm.com>
// *HWP FW Owner        :    Prem S Jha  <premjha2@in.ibm.com>
// *HWP Team            :    PM
// *HWP Level           :    3
// *HWP Consumed by     :    HS

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <p10_pm_xgpe_init.H>
#include <p10_pm_pba_init.H>
#include <p10_pm_hcd_flags.h>
#include <p10_ppe_defs.H>
#include <p10_hcd_common.H>
#include <p10_scom_proc.H>
#include <p10_scom_eq.H>
#include <multicast_group_defs.H>
#include <vector>

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

// Following constants hold an approximate value.
static const uint32_t XGPE_TIMEOUT_MS       = 50000;
static const uint32_t XGPE_TIMEOUT_MCYCLES  = 20;
static const uint32_t XGPE_POLLTIME_MS      = 20;
static const uint32_t XGPE_POLLTIME_MCYCLES = 2;
static const uint32_t TIMEOUT_COUNT = XGPE_TIMEOUT_MS / XGPE_POLLTIME_MS;
static const uint32_t INTERRUPT_SRC_MASK_REG = 0xFFFFFFFF;

#define HALT    2

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//  Auxillary GPE Initialization Function
// -----------------------------------------------------------------------------

/// @brief Initializes the Auxillary GPE and related Auxillary functions on a chip
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode xgpe_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // Function not supported on SBE platform
#ifndef __PPE__
    using namespace scomt::proc;

    const uint32_t PU_OCB_OCI_OIMR0_OR = TP_TPCHIP_OCC_OCI_OCB_OIMR0_WO_OR;
    const uint32_t PU_OCB_OCI_OIMR1_OR = TP_TPCHIP_OCC_OCI_OCB_OIMR1_WO_OR;
    const uint32_t PU_OCB_OCI_OITR0_OR = TP_TPCHIP_OCC_OCI_OCB_OITR0_WO_OR;
    const uint32_t PU_OCB_OCI_OITR1_OR = TP_TPCHIP_OCC_OCI_OCB_OITR1_WO_OR;

    const uint32_t PU_OCB_OCI_OIEPR0_OR = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_OR;
    const uint32_t PU_OCB_OCI_OIEPR1_OR = TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_OR;

//    const uint32_t PU_OCB_OCI_OIEPR0_CLEAR = TP_TPCHIP_OCC_OCI_OCB_OIEPR0_WO_CLEAR;
//    const uint32_t PU_OCB_OCI_OIEPR1_CLEAR = TP_TPCHIP_OCC_OCI_OCB_OIEPR1_WO_CLEAR;
    const uint32_t PU_OCB_OCI_OISR0_CLEAR = TP_TPCHIP_OCC_OCI_OCB_OISR0_WO_CLEAR;
    const uint32_t PU_OCB_OCI_OISR1_CLEAR = TP_TPCHIP_OCC_OCI_OCB_OISR1_WO_CLEAR;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_occ_flag3;
    fapi2::buffer<uint64_t> l_xcr;
    fapi2::buffer<uint64_t> l_xsr_iar;
    fapi2::buffer<uint64_t> l_ivpr;
    uint32_t                l_xsr_halt_condition = 0;
    uint32_t                l_timeout_counter = TIMEOUT_COUNT;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>      FAPI_SYSTEM;
    fapi2::ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET_Type       l_ivpr_offset = 0;
    fapi2::ATTR_SYSTEM_AUXILLARY_MODE_Type                l_aux_mode = 0;
    uint64_t  l_xgpe_base_addr = XGPE_BASE_ADDRESS;

    FAPI_IMP(">> xgpe_start......");

    // Set Interrupt Source Mask Registers 0 & 1
    //  - keep word1 0's for simics
    l_data64.flush<0>().insertFromRight<0, 32>(INTERRUPT_SRC_MASK_REG);
    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OIMR0_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Source Mask Register0 (OIMR0)");

    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OIMR1_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Source Mask Register1 (OIMR1)");

    // Set OCC Interrupt Type Registers 0 & 1 to Edge to keep the OISRx
    // register from capturing bad default values
    l_data64.flush<1>();
    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OITR0_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Type Register0 (OITR0)");

    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OITR1_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Type Register1 (OITR1)");

    // Clear OCC Interupt Edge/Polarity Registers 0 & 1 TBD
    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OIEPR0_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Edge Polarity Register0 (OIEPR0)");

    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OIEPR1_OR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Edge Polarity Register1 (OIEPR1)");

    // Clear OCC Interrupt Source Registers 0 & 1
    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OISR0_CLEAR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Source Register0 (OISR0)");

    FAPI_TRY(fapi2::putScom(i_target,
                            PU_OCB_OCI_OISR1_CLEAR,
                            l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt Source Register1 (OISR1)");

    // Clear Interrupt Route (A, B, C) Registers 0 & 1
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0A_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 0 Route A Register (OIRR0A)");

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0B_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 0 Route B Register (OIRR0A)");

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR0C_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 0 Route C Register (OIRR0A)");

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1A_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 1 Route A Register (OIRR1A)");

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1B_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 1 Route B Register (OIRR1B)");

    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OIRR1C_RW, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "Interrupt 1 Route C Register (OIRR1C)");

    // Read back OCC Interrupt Source Registers 0 & 1
    FAPI_TRY(fapi2::getScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OISR0_RO,
                            l_data64));
    FAPI_INF("OISR0 Readback 0x%016llX", l_data64);

    FAPI_TRY(fapi2::getScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OISR1_RO,
                            l_data64));
    FAPI_INF("OISR1 Readback 0x%016llX", l_data64);


    //Clear OCC Special Timeout Error status Register)
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_PLBTO_OCB_PIB_OSTOESR, 0));

    // Program XGPE IVPR
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET,
                            i_target,
                            l_ivpr_offset),
              "Error getting ATTR_XGPE_BOOT_COPIER_IVPR_OFFSET");
    FAPI_INF("  ATTR IVPR with 0x%16llX", l_ivpr_offset);
    l_ivpr.flush<0>().insertFromRight<0, 32>(l_ivpr_offset);
    FAPI_INF("  Writing IVPR with 0x%16llX", l_ivpr);
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEIVPR, l_ivpr));

    FAPI_INF("  Clear OCC Flag 3 Register bits before starting...");
    l_occ_flag3.flush<0>()
    .setBit<p10hcd::XGPE_IODLR_ENABLE>()
    .setBit<p10hcd::XGPE_PM_COMPLEX_SUSPEND>()
    .setBit<p10hcd::XGPE_ACTIVE>()
    .setBit<p10hcd::XGPE_PM_COMPLEX_SUSPEND>()
    .setBit<p10hcd::XGPE_IODLR_ACTIVE>()
    .setBit<p10hcd::XGPE_PM_COMPLEX_SUSPENDED>()
    .setBit<p10hcd::CORE_THROT_CONTIN_CHANGE_ENABLE>();
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR, l_occ_flag3));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_AUXILLARY_MODE,
                            FAPI_SYSTEM,
                            l_aux_mode),
              "Error getting ATTR_SYSTEM_AUXILLARY_MODE");


    // Boot if not OFF
    if (l_aux_mode != fapi2::ENUM_ATTR_SYSTEM_AUXILLARY_MODE_OFF)
    {
        // Setup the XGPE Timer Selects
        // These hardcoded values are assumed by the XGPE Hcode for setting up
        // the FIT and Watchdog values a based on the nest frequency that is
        // passed to it via the XGPE header.
        l_data64.flush<0>()
        .insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL,
                         TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_WATCHDOG_SEL_LEN>(0x1)
                         .insertFromRight<TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL,
                         TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL_FIT_SEL_LEN>(0xC);
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPETSEL, l_data64));

        // Clear error injection bits
        l_data64.flush<0>()
        .setBit<p10hcd::XGPE_DEBUG_HALT_ENABLE>()
        .setBit<p10hcd::XGPE_HCODE_ERROR_INJECT>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR, l_data64));

        // Program XCR to ACTIVATE XGPE
        FAPI_INF("   Starting the XGPE...");
        l_xcr.flush<0>().insertFromRight(XCR_HARD_RESET, 1, 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, l_xcr));
        l_xcr.flush<0>().insertFromRight(XCR_TOGGLE_XSR_TRH, 1 , 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, l_xcr));
        l_xcr.flush<0>().insertFromRight(XCR_RESUME, 1, 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, l_xcr));

        // Now wait for XGPE to boot
        FAPI_DBG("   Poll for XGPE Active for %d ms", XGPE_TIMEOUT_MS);
        l_occ_flag3.flush<0>();
        l_xsr_iar.flush<0>();

        do
        {
            FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_RW, l_occ_flag3));
            FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIDBGPRO, l_xsr_iar));
            FAPI_DBG("OCC Flag 3: 0x%016lx; XSR: 0x%016lx Timeout: %d",
                     l_occ_flag3, l_xsr_iar, l_timeout_counter);
            // fapi2::delay takes ns as the arg
            fapi2::delay(XGPE_POLLTIME_MS * 1000 * 1000, XGPE_POLLTIME_MCYCLES * 1000 * 1000);
        }
        while((l_occ_flag3.getBit<p10hcd::XGPE_ACTIVE>() != 1) &&
              (l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1) &&
              (--l_timeout_counter != 0));

        // Extract the halt condition
        l_xsr_iar.extractToRight<uint32_t>(l_xsr_halt_condition,
                                           XSR_HALT_CONDITION_START,
                                           XSR_HALT_CONDITION_LEN);
        FAPI_DBG("halt state: XSR/IAR: 0x%016lx condition: %d",
                 l_xsr_iar, l_xsr_halt_condition);


        // Check for a debug halt condition
        FAPI_ASSERT(!((l_xsr_iar.getBit<XSR_HALTED_STATE>() == 1) &&
                      ((l_xsr_halt_condition == XSR_DEBUG_HALT ||
                        l_xsr_halt_condition == XSR_DBCR_HALT)   )),
                    fapi2::XGPE_INIT_DEBUG_HALT()
                    .set_CHIP(i_target)
                    .set_XGPE_BASE_ADDRESS(l_xgpe_base_addr)
                    .set_XGPE_STATE_MODE(HALT),
                    "Auxillary GPE Debug Halt detected");

        // When XGPE fails to boot, assert out
        FAPI_ASSERT((l_timeout_counter != 0 &&
                     l_occ_flag3.getBit<p10hcd::XGPE_ACTIVE>() == 1 &&
                     l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1),
                    fapi2::XGPE_INIT_TIMEOUT()
                    .set_CHIP(i_target)
                    .set_XGPE_BASE_ADDRESS(l_xgpe_base_addr)
                    .set_XGPE_STATE_MODE(HALT),
                    "Auxillary GPE Init timeout");

        if(l_occ_flag3.getBit<p10hcd::XGPE_ACTIVE>())
        {
            FAPI_INF("  XGPE was activated successfully!!!!");
        }


    }
    else
    {
        FAPI_INF("  XGPE booting is disabled and is NOT running!!!!");
    }

fapi_try_exit:
    FAPI_IMP("<< xgpe_start......");
#else
    FAPI_IMP("!!! xgpe_start not supported on SBE platform");
#endif

    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  Auxillary GPE Reset Function
// -----------------------------------------------------------------------------

/// @brief Stops the Auxillary GPE
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode xgpe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;
    using namespace scomt::eq;

    fapi2::buffer<uint64_t> l_data64;
    uint32_t                l_timeout_in_MS = 100;
    uint64_t l_xgpe_base_addr = XGPE_BASE_ADDRESS;

    FAPI_IMP(">> xgpe_halt...");

    // Program XCR to HALT XGPE
    FAPI_INF("   Send HALT command via XCR...");

    l_data64.flush<0>().insertFromRight(XCR_HALT, 1, 3);
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXCR, l_data64));

    // Now wait for XGPE to be halted.
    FAPI_INF("  Poll for HALT State via XSR...");

    do
    {
        FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_GPE3_OCB_GPEXIXSR, l_data64));
        fapi2::delay(XGPE_POLLTIME_MS * 1000 * 1000, XGPE_POLLTIME_MCYCLES * 1000 * 1000);
    }
    while((l_data64.getBit<XSR_HALTED_STATE>() == 0) &&
          (--l_timeout_in_MS != 0));

    // When XGPE fails to halt, then assert ot
    FAPI_ASSERT((l_timeout_in_MS != 0),
                fapi2::XGPE_RESET_TIMEOUT()
                .set_CHIP(i_target)
                .set_XGPE_BASE_ADDRESS(l_xgpe_base_addr)
                .set_XGPE_STATE_MODE(HALT),
                "XGPE Reset timeout");

    FAPI_INF("  Clear XGPE_ACTIVE in OCC Flag Register...");
    l_data64.flush<0>().setBit<p10hcd::XGPE_ACTIVE>();
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_CLEAR, l_data64));

    FAPI_INF("  XGPE was halted successfully!!!!");

fapi_try_exit:
    FAPI_IMP("<< xgpe_halt...");
    return fapi2::current_err;

}

// -----------------------------------------------------------------------------
//  p10_pm_xgpe_init Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_xgpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("> p10_pm_xgpe_init");
    const char* PM_MODE_NAME_VAR; //Defines storage for PM_MODE_NAME
    FAPI_IMP("Executing p10_pm_xgpe_init in mode %s", PM_MODE_NAME(i_mode));

    // Boot the Auxillary GPE
    if (i_mode == pm::PM_START)
    {
        // Setup the PBA channels for run-time operation (eg when the PPC405 and its GPEs are active).
        FAPI_EXEC_HWP(fapi2::current_err,
                      p10_pm_pba_init,
                      i_target,
                      pm::PM_START);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::XGPE_PBA_INIT_FAILED()
                    .set_CHIP(i_target)
                    .set_MODE(pm::PM_START),
                    "PBA Setup Failed" );

        // Start XGPE
        FAPI_TRY(xgpe_start(i_target),
                 "ERROR: failed to initialize Auxillary GPE");


    }

    // Reset the XGPE
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_TRY(xgpe_halt(i_target), "ERROR:failed to reset Auxillary GPE");
    }

    // Unsupported Mode
    else
    {
        FAPI_ASSERT(false,
                    fapi2::XGPE_BAD_MODE()
                    .set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to p10_pm_xgpe_init . Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("< p10_pm_xgpe_init");
    return fapi2::current_err;
}
