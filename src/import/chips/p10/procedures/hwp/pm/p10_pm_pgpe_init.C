/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/pm/p10_pm_pgpe_init.C $   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
/// @file p10_pm_pgpe_init.C
/// @brief  Start and Halt the Pstate GPE (PGPE)
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
#include <p10_pm_pgpe_init.H>
#include <p10_pm_pba_init.H>
#include <p10_pm_hcd_flags.h>
#include <p10_ppe_defs.H>
#include <p10_hcd_common.H>
#include <p10_scom_proc.H>
#include <p10_scom_proc_2.H>
#include <p10_scom_eq.H>
#include <multicast_group_defs.H>
#include <vector>

// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

// Following constants hold an approximate value.
static const uint32_t PGPE_TIMEOUT_MS       = 600;
static const uint32_t PGPE_TIMEOUT_MCYCLES  = 20;
static const uint32_t PGPE_POLLTIME_MS      = 20;
static const uint32_t PGPE_POLLTIME_MCYCLES = 4;
static const uint32_t TIMEOUT_COUNT = PGPE_TIMEOUT_MS / PGPE_POLLTIME_MS;

#define HALT 0x2

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
//  Pstate GPE Initialization Function
// -----------------------------------------------------------------------------

/// @brief Initializes the Pstate GPE and related Pstate functions on a chip
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode pgpe_start(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    // Function not supported no SBE platform
#ifndef __PPE__
    using namespace scomt::proc;

    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_occ_flag2;
    fapi2::buffer<uint64_t> l_xcr;
    fapi2::buffer<uint64_t> l_xsr_iar;
    fapi2::buffer<uint64_t> l_ivpr;
    uint32_t                l_xsr_halt_condition = 0;
    uint32_t                l_timeout_counter = TIMEOUT_COUNT;

    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>      FAPI_SYSTEM;
    fapi2::ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET_Type       l_ivpr_offset = 0;
    fapi2::ATTR_SYSTEM_PSTATES_MODE_Type                l_pstates_mode = 0;
    uint64_t l_pgpe_base_addr = PGPE_BASE_ADDRESS;

    FAPI_IMP(">> pgpe_start......");

    // Setup OCCMISC
    l_data64.flush<1>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_CLEAR, l_data64));

    fapi2::ATTR_CHIP_EC_FEATURE_PVREF_ENABLE_Type l_pvref_enable;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_PVREF_ENABLE,
                            i_target,
                            l_pvref_enable),
              "Error getting ATTR_CHIP_EC_FEATURE_PVREF_ENABLE");

    if (l_pvref_enable)
    {
        // Enable the Precision Voltage Reference errors (gross and fine)
        l_data64.flush<0>()
        .setBit<TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN,
                TP_TPCHIP_OCC_OCI_OCB_OCCMISC_PVREF_ERROR_EN_LEN>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCMISC_WO_OR, l_data64));
    }

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET,
                            i_target,
                            l_ivpr_offset),
              "Error getting ATTR_PGPE_BOOT_COPIER_IVPR_OFFSET");

    // Program PGPE IVPR
    l_ivpr.flush<0>().insertFromRight<0, 32>(l_ivpr_offset);
    FAPI_INF("Writing IVPR with 0x%16llX", l_ivpr);
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEIVPR, l_ivpr));

    FAPI_INF("Clear OCC Flag 2 Register bits before starting...");
    l_occ_flag2.flush<0>()
    .setBit<p10hcd::PGPE_PSTATE_PROTOCOL_STOP>()
    .setBit<p10hcd::PGPE_SAFE_MODE>()
    .setBit<p10hcd::PGPE_ACTIVE>()
    .setBit<p10hcd::PGPE_PSTATE_PROTOCOL_ACTIVE>()
    .setBit<p10hcd::PGPE_SAFE_MODE_ACTIVE>()
    .setBit<p10hcd::PGPE_SAFE_MODE_ERROR>()
    .setBit<p10hcd::PGPE_CEFFOVR_CONTROL_LOOP>();
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, l_occ_flag2));

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_PSTATES_MODE,
                            FAPI_SYSTEM,
                            l_pstates_mode),
              "Error getting ATTR_SYSTEM_PSTATES_MODE");

    fapi2::ATTR_PSTATES_ENABLED_Type l_ps_enabled;
    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_PSTATES_ENABLED,
                            i_target,
                            l_ps_enabled),
              "Error getting ATTR_PSTATES_ENABLED");

    // Boot if not OFF
    if (l_pstates_mode != fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_OFF &&
        (l_ps_enabled == fapi2::ENUM_ATTR_PSTATES_ENABLED_TRUE) )
    {
        // Set auto mode if needed
        if (l_pstates_mode == fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_AUTO)
        {
            FAPI_INF("Pstate Auto Start Mode Enabled...");
            l_data64.flush<0>().setBit<p10hcd::PGPE_PSTATE_PROTOCOL_AUTO_ACTIVATE>();
            FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_OR, l_data64));
        }

        // Setup the PGPE Timer Selects
        // These hardcoded values are assumed by the PGPE Hcode for setting up
        // the FIT and Watchdog values a based on the nest frequency that is
        // passed to it via the PGPE header.
        l_data64.flush<0>()
        .insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL,
                         TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_WATCHDOG_SEL_LEN>(0x1)
                         .insertFromRight<TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL,
                         TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL_FIT_SEL_LEN>(0xB);
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPETSEL, l_data64));

        // Clear error injection bits
        l_data64.flush<0>()
        .setBit<p10hcd::PGPE_DEBUG_HALT_ENABLE>()
        .setBit<p10hcd::PGPE_HCODE_ERROR_INJECT>();
        FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, l_data64));

        // Program XCR to ACTIVATE PGPE
        FAPI_INF("Starting the PGPE...");
        l_xcr.flush<0>().insertFromRight(XCR_HARD_RESET, 1, 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR, l_xcr));
        l_xcr.flush<0>().insertFromRight(XCR_TOGGLE_XSR_TRH, 1 , 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR, l_xcr));
        l_xcr.flush<0>().insertFromRight(XCR_RESUME, 1, 3);
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR, l_xcr));

        // Now wait for PGPE to boot
        FAPI_DBG("Poll for PGPE Active for %d ms", PGPE_TIMEOUT_MS);
        l_occ_flag2.flush<0>();
        l_xsr_iar.flush<0>();

        do
        {
            FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, l_occ_flag2));
            FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO, l_xsr_iar));
            FAPI_DBG("OCC Flag 2: 0x%016lx; XSR: 0x%016lX Timeout: %d",
                     l_occ_flag2, l_xsr_iar, l_timeout_counter);
            // fapi2::delay takes ns as the arg
            fapi2::delay(PGPE_POLLTIME_MS * 1000 * 1000, PGPE_POLLTIME_MCYCLES * 1000 * 1000);
        }
        while((l_occ_flag2.getBit<p10hcd::PGPE_ACTIVE>() != 1) &&
              (l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1) &&
              (--l_timeout_counter != 0));

        // Extract the halt condition
        l_xsr_iar.extractToRight<uint32_t>(l_xsr_halt_condition,
                                           XSR_HALT_CONDITION_START,
                                           XSR_HALT_CONDITION_LEN);
        FAPI_DBG("halt state: XSR/IAR: 0x%016lX condition: %d",
                 l_xsr_iar, l_xsr_halt_condition);

        // Check for a debug halt condition
        FAPI_ASSERT(!((l_xsr_iar.getBit<XSR_HALTED_STATE>() == 1) &&
                      ((l_xsr_halt_condition == XSR_DEBUG_HALT ||
                        l_xsr_halt_condition == XSR_DBCR_HALT)   )),
                    fapi2::PGPE_INIT_DEBUG_HALT()
                    .set_CHIP(i_target)
                    .set_PGPE_BASE_ADDRESS(l_pgpe_base_addr)
                    .set_PGPE_STATE_MODE(HALT),
                    "PGPE Debug Halt detected");

        // If PGPE halted otherwise, assert out uniquely
        FAPI_ASSERT((l_xsr_iar.getBit<XSR_HALTED_STATE>() == 0),
                    fapi2::PGPE_INIT_HALT()
                    .set_CHIP(i_target)
                    .set_PGPE_BASE_ADDRESS(l_pgpe_base_addr)
                    .set_PGPE_STATE_MODE(HALT),
                    "PGPE halted abnormally");

        // When PGPE fails to boot, assert out
        FAPI_ASSERT((l_timeout_counter != 0 &&
                     l_occ_flag2.getBit<p10hcd::PGPE_ACTIVE>() == 1 &&
                     l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1),
                    fapi2::PGPE_INIT_TIMEOUT()
                    .set_CHIP(i_target)
                    .set_PGPE_BASE_ADDRESS(l_pgpe_base_addr)
                    .set_PGPE_STATE_MODE(HALT),
                    "PGPE Init timeout");

        if(l_occ_flag2.getBit<p10hcd::PGPE_ACTIVE>())
        {
            FAPI_INF("PGPE was activated successfully!!!!");
        }

        if (l_pstates_mode == fapi2::ENUM_ATTR_SYSTEM_PSTATES_MODE_AUTO)
        {
            do
            {
                FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_RW, l_occ_flag2));
                FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIDBGPRO, l_xsr_iar));
                // fapi2::delay takes ns as the arg
                fapi2::delay(PGPE_POLLTIME_MS * 1000 * 1000, PGPE_POLLTIME_MCYCLES * 1000 * 1000);
            }
            while((l_occ_flag2.getBit<p10hcd::PGPE_PSTATE_PROTOCOL_ACTIVE>() != 1) &&
                  (l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1) &&
                  (--l_timeout_counter != 0));

            // When Pstate protocol fails to start, post a log
            if (l_timeout_counter != 0 &&
                l_occ_flag2.getBit<p10hcd::PGPE_PSTATE_PROTOCOL_ACTIVE>() == 1 &&
                l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1)
            {
                FAPI_INF("Pstate Auto Start Mode Complete!!!!");
            }
            else
            {
                FAPI_ASSERT_NOEXIT(false,
                                   fapi2::PGPE_INIT_PSTATE_AUTOSTART_TIMEOUT()
                                   .set_CHIP(i_target)
                                   .set_XSR_IAR(l_xsr_iar)
                                   .set_TIMEOUT_COUNTER(l_timeout_counter)
                                   .set_OCCFLAG2(l_occ_flag2),
                                   "Pstate GPE Protocol Auto Start timeout");
            }
        }
    }
    else
    {
        FAPI_INF("PGPE booting is disabled and is NOT running!!!!");
    }

fapi_try_exit:
    FAPI_IMP("<< pgpe_start......");
#else
    FAPI_IMP("!!! pgpe_start not supported on SBE platform");
#endif
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  Pstate GPE Reset Function
// -----------------------------------------------------------------------------

/// @brief Stops the Pstate GPE
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode pgpe_halt(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    using namespace scomt::proc;
    using namespace scomt::eq;

    fapi2::buffer<uint64_t> l_data64;
    uint32_t                l_timeout_in_MS = 100;
    uint64_t l_pgpe_base_addr = PGPE_BASE_ADDRESS;

    auto l_eq_mc_or  =
        i_target.getMulticast<fapi2::TARGET_TYPE_EQ, fapi2::MULTICAST_OR >(fapi2::MCGROUP_GOOD_EQ);

    FAPI_IMP(">> pgpe_halt...");

    FAPI_INF("Disabling OCC Heartbeat in all QMEs");

    l_data64.flush<0>()
    .insertFromRight<QME_QHB_HEARTBEAT_COUNT, QME_QHB_HEARTBEAT_COUNT_LEN>(0xFFFF);
    l_data64.clearBit<QME_QHB_HEARTBEAT_ENABLE>();
    FAPI_TRY(fapi2::putScom(l_eq_mc_or, QME_QHB, l_data64),
             "ERROR: Failed to setup QME_QHB register")

    // Program XCR to HALT PGPE
    FAPI_INF("Send HALT command via XCR...");

    l_data64.flush<0>().insertFromRight(XCR_HALT, 1, 3);
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXCR, l_data64));

    // Now wait for PGPE to be halted.
    FAPI_INF("Poll for HALT State via XSR...");

    do
    {
        FAPI_TRY(getScom(i_target, TP_TPCHIP_OCC_OCI_GPE2_OCB_GPEXIXSR, l_data64));
        fapi2::delay(PGPE_POLLTIME_MS * 1000 * 1000, PGPE_POLLTIME_MCYCLES * 1000 * 1000);
    }
    while((l_data64.getBit<XSR_HALTED_STATE>() == 0) &&
          (--l_timeout_in_MS != 0));

    // When PGPE fails to halt, then assert ot
    FAPI_ASSERT((l_timeout_in_MS != 0),
                fapi2::PGPE_RESET_TIMEOUT()
                .set_CHIP(i_target)
                .set_PGPE_BASE_ADDRESS(l_pgpe_base_addr)
                .set_PGPE_STATE_MODE(HALT),
                "PSTATE GPE Reset timeout");

    FAPI_INF("Clear PGPE_ACTIVE in OCC Flag Register...");
    l_data64.flush<0>().setBit<p10hcd::PGPE_ACTIVE>();
    FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG2_WO_CLEAR, l_data64));

    FAPI_INF("PGPE was halted successfully!!!!");

fapi_try_exit:
    FAPI_IMP("<< pgpe_halt...");
    return fapi2::current_err;

}

// -----------------------------------------------------------------------------
//  p10_pm_pgpe_init Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_pgpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP("> p10_pm_pgpe_init");

    const char* PM_MODE_NAME_VAR; //Defines storage for PM_MODE_NAME
    FAPI_IMP("Executing p10_pm_pgpe_init in mode %s", PM_MODE_NAME(i_mode));

    // Boot the PSTATE GPE
    if (i_mode == pm::PM_START)
    {
#if 0
        FAPI_EXEC_HWP(fapi2::current_err,
                      p10_pm_pba_init,
                      i_target,
                      pm::PM_HALT);
        // Setup the PBA channels for run-time operation (eg when the PPC405 and its GPEs are active).
        FAPI_EXEC_HWP(fapi2::current_err,
                      p10_pm_pba_init,
                      i_target,
                      pm::PM_START);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::PGPE_PBA_INIT_FAILED()
                    .set_CHIP(i_target)
                    .set_MODE(pm::PM_START),
                    "PBA Setup Failed" );
#endif

        // Start PGPE
        FAPI_TRY(pgpe_start(i_target),
                 "ERROR: failed to initialize Pstate GPE");
    }

    // Reset the PSTATE GPE
    else if (i_mode == pm::PM_HALT)
    {
        FAPI_TRY(pgpe_halt(i_target), "ERROR:failed to reset Pstate GPE");
    }

    // Unsupported Mode
    else
    {
        FAPI_ASSERT(false,
                    fapi2::PGPE_BAD_MODE()
                    .set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to pstate_gpe_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("< p10_pm_pgpe_init");
    return fapi2::current_err;
}
