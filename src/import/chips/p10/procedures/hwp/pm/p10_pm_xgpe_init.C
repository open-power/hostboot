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
#include <p10_scom_mc_f.H>
#include <p10_scom_pauc_f.H>
#include <p10_scom_pec_f.H>
#include <p10_scom_iohs_f.H>
#include <multicast_group_defs.H>
#include <vector>
#ifndef __PPE__
    #include <p10_io_pwr.H>
    #include <p10_pm_ocb_init.H>
    #include <p10_hcd_memmap_occ_sram.H>
    #include <p10_pm_ocb_indir_setup_linear.H>
    #include <p10_pm_ocb_indir_access.H>
#endif
#include <endian.h>

#ifdef __HOSTBOOT_MODULE
    #include <util/misc.H>                   // Util::isSimicsRunning
#endif
// -----------------------------------------------------------------------------
// Constants
// -----------------------------------------------------------------------------

using namespace scomt::proc;
using namespace scomt::eq;
using namespace scomt::pauc;
using namespace scomt::mc;
using namespace scomt::pec;
using namespace scomt::iohs;
// Following constants hold an approximate value.
static const uint32_t XGPE_TIMEOUT_MS       = 50000;
static const uint32_t XGPE_TIMEOUT_MCYCLES  = 20;
static const uint32_t XGPE_POLLTIME_MS      = 20;
static const uint32_t XGPE_POLLTIME_MCYCLES = 2;
static const uint32_t TIMEOUT_COUNT = XGPE_TIMEOUT_MS / XGPE_POLLTIME_MS;
static const uint32_t INTERRUPT_SRC_MASK_REG = 0xFFFFFFFF;
#define DL_ENABLE_BIT           10
#define LINK_POPULATED_BIT      0
#define LINK_TYPE_BIT           1
#define LINK_TYPE_BIT_LEN       3
#define WINDOW_SELECT_BIT       12
#define WINDOW_SELECT_BIT_LEN   4
#define DIV2_WEIGHT_BIT         16
#define DIV2_WEIGHT_BIT_LEN     4
#define DIV4_WEIGHT_BIT         20
#define DIV4_WEIGHT_BIT_LEN     4
#define FREEZE_PROXY            11

uint64_t g_io_pow_gated_cntrlr = 0;
uint64_t g_io_omi_active_link = 0;
uint64_t g_io_omi_disable_link = 0;
uint32_t g_ax_speed_type = 0;
uint32_t g_oc_speed_type = 0;
#ifndef __PPE__
static uint32_t TP_TPCHIP_TPC_CPLT_CTRL5_RW = 0x01000005;
controller_entry_t g_cntrlr_data[NUM_IO_CNTRLS];
link_entry_t g_link_data[NUMBER_OF_IO_LINKS];
uint8_t  g_io_iohs_sub_type = 0;
uint8_t  g_io_omi_sub_type = 0;
uint8_t  g_io_pcie_sub_type = 0;
uint64_t  g_io_pci_active_link = 0;
uint64_t  g_io_pci_disable_link = 0;
uint64_t g_io_iohs_ax_active_link = 0;
uint64_t g_io_iohs_ax_disable_link = 0;
uint64_t g_io_iohs_oc_active_link = 0;
uint64_t g_io_iohs_oc_disable_link = 0;
uint64_t g_io_lnk_disable_cntrlr = 0;

//static uint32_t g_iohs_ax_apsr_reg[] = {0x18011039, 0x1801103D};
static uint32_t g_iohs_ax_apor_reg[]  = {0x1801103a, 0x1801103e};
static uint32_t g_iohs_ax_apcr_reg[]  = {0x18011038, 0x1801103c};
static uint32_t g_iohs_ax_dll_status_reg[]  = {0x18011028};
static uint32_t g_omi_even_apcr_reg[] = {0x0C011430, 0x0C011438}; //MC00, MC10, MC20, MC30
//static uint32_t g_omi_odd_apcr_reg[]  = {0x0C011830, 0x0C011838}; //MC01, MC11, MC21, MC31
static uint32_t g_omi_even_apor_reg[] = {0x0c011432, 0x0C01143a}; //MC01, MC11, MC21, MC31
//static uint32_t g_omi_odd_apor_reg[]  = {0x0c011832, 0x0C01183a}; //MC01, MC11, MC21, MC31
static uint32_t g_pcie_pasr_reg[] = {0x08010913};
static uint32_t g_pcie_past_reg[] = {0x08010915};
#endif

#define HALT    2

// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

fapi2::ReturnCode p10_pm_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode iodlr_pgated_validation(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode omi_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode pec_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode iohs_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);
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
    const uint64_t TP_TPCHIP_OCC_OCI_OCB_PIB_OPPCINJ = 0x0006d111ull;

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


    // Clear OCC error injection register
    l_data64.flush<0>();
    FAPI_TRY(fapi2::putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_PIB_OPPCINJ, l_data64),
             "**** ERROR : Unexpected error encountered in write to OCC "
             "TP_TPCHIP_OCC_OCI_OCB_PIB_OPPCINJ");

    // Read back OCC Interrupt Source Registers 0 & 1
    FAPI_TRY(fapi2::getScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OISR0_RO,
                            l_data64));
    FAPI_INF("OISR0 Readback 0x%016llX", l_data64);

    FAPI_TRY(fapi2::getScom(i_target,
                            TP_TPCHIP_OCC_OCI_OCB_OISR1_RO,
                            l_data64));
    FAPI_INF("OISR1 Readback 0x%016llX", l_data64);


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
                    .set_TIMEOUT_COUNTER(l_timeout_counter)
                    .set_XGPE_BASE_ADDRESS(l_xgpe_base_addr)
                    .set_XGPE_STATE_MODE(HALT),
                    "Auxillary GPE Debug Halt detected");

        // When XGPE fails to boot, assert out
        FAPI_ASSERT((l_timeout_counter != 0 &&
                     l_occ_flag3.getBit<p10hcd::XGPE_ACTIVE>() == 1 &&
                     l_xsr_iar.getBit<XSR_HALTED_STATE>() != 1),
                    fapi2::XGPE_INIT_TIMEOUT()
                    .set_CHIP(i_target)
                    .set_XSR_IAR(l_xsr_iar)
                    .set_TIMEOUT_COUNTER(l_timeout_counter)
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
                .set_XSR_IAR(l_data64)
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

#ifndef __PPE__
        //IODLR  static configuration
        FAPI_TRY(p10_pm_iodlr_static_config(i_target),
                 "ERROR: Failed to configure iodlr");
#endif


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
                    .set_BADMODE(i_mode)
                    .set_CURPROC(i_target),
                    "ERROR; Unknown mode passed to p10_pm_xgpe_init . Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_IMP("< p10_pm_xgpe_init");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  p10_pm_iodlr_static_config Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode p10_pm_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifndef __PPE__
    fapi2::ReturnCode l_rc;
    FAPI_IMP(">>> p10_pm_iodlr_static_config");
    fapi2::ATTR_IS_MPIPL_Type l_mpipl;
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>      FAPI_SYSTEM;

    do
    {
        //Still simics fix for IOHS scom access is not yet
        //part of official build.so for now will just return
        //for only simics

#ifdef __HOSTBOOT_MODULE
        if (Util::isSimicsRunning())
        {
            break;
        }

#endif
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IS_MPIPL, FAPI_SYSTEM, l_mpipl));
        fapi2::ATTR_CHIP_EC_FEATURE_WOF_STATIC_IO_POWER_Type l_wof_io_state;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_EC_FEATURE_WOF_STATIC_IO_POWER,
                               i_target, l_wof_io_state),
                 "Error from FAPI_ATTR_GET (ATTR_CHIP_EC_FEATURE_WOF_STATIC_IO_POWER)");

        if (!l_wof_io_state ||
            l_mpipl)
        {
            FAPI_INF("We skip io powr computation for DD1/MPIPL");
            break;
        }

//We identify Active, Disable and Pgated links using targting infrastructure and
//register values.
//Active links: are identifed by reading APCR register and bit 10 (DL_ENABLE)
//              should be set.
//Disable links: are identified by reading APCR register and bit 10 not set.
//Pgated links: are indentified, if PFET enable bit is not set in CPLT_CNTRL_5
//register and also if the targets is not functional but pfet enable is still set,
//then that target(link) is considered for pgated


        g_io_pow_gated_cntrlr = 0;
        g_io_omi_active_link = 0;
        g_io_pci_active_link = 0;
        g_io_iohs_ax_active_link = 0;
        g_io_iohs_oc_active_link = 0;
        g_io_omi_disable_link = 0;
        g_io_pci_disable_link = 0;
        g_io_iohs_ax_disable_link = 0;
        g_io_iohs_oc_disable_link = 0;
        g_oc_speed_type = 0;
        memset (&g_cntrlr_data, 0, sizeof (g_cntrlr_data));
        memset (&g_link_data, 0, sizeof (g_link_data));

        FAPI_TRY(pec_iodlr_static_config(i_target));

        FAPI_TRY(omi_iodlr_static_config(i_target));

        FAPI_TRY(iohs_iodlr_static_config(i_target));

        FAPI_TRY(iodlr_pgated_validation(i_target));

    }
    while(0);

fapi_try_exit:
#endif
    FAPI_IMP("<<< p10_pm_iodlr_static_config");
    return fapi2::current_err;
}
// -----------------------------------------------------------------------------
//  pec_iodlr_static_config Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode pec_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifndef __PPE__
    fapi2::ReturnCode l_rc;
    fapi2::buffer<uint64_t> l_data64;
    fapi2::ATTR_WOF_IO_POWER_MODE_Type l_wof_pwr_mode;
    FAPI_IMP(">>> pec_iodlr_static_config");
    uint8_t l_pec_unit_pos = 0;
    uint8_t l_phb_unit_pos = 0;
    uint32_t l_attr_vio_boot_vlt = 0;
    uint32_t l_sub_type = 0;
    uint32_t l_pci_gen_info = 0;
    uint32_t l_pci_gen_size = 0;
    uint32_t l_width = 0;

    do
    {
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_VIO_SET_POINT_MV,
                                i_target,
                                l_attr_vio_boot_vlt),
                  "Error getting ATTR_VIO_SET_POINT_MV");

        //If VIO is 0 from attr, then will set to 1V
        if ( !l_attr_vio_boot_vlt)
        {
            l_attr_vio_boot_vlt = 1000;
        }

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_POWER_MODE,
                                i_target,
                                l_wof_pwr_mode),
                  "Error getting ATTR_WOF_IO_POWER_MODE");

        for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            //Bits defined in gnd_cntrlr
            //13  PEC0
            //14  PEC0
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                    l_pec_target,
                                    l_pec_unit_pos),
                      "Error getting fapi2::ATTR_CHIP_UNIT_POS");

            for (const auto l_phb_target : l_pec_target.getChildren<fapi2::TARGET_TYPE_PHB>(fapi2::TARGET_STATE_FUNCTIONAL))
            {
                l_pci_gen_info = 0;
                l_pci_gen_size = 0;
                FAPI_TRY(getScom(l_phb_target, g_pcie_pasr_reg[0], l_data64));

                l_data64.setBit<LINK_POPULATED_BIT>();

                if (l_wof_pwr_mode == fapi2::ENUM_ATTR_WOF_IO_POWER_MODE_STATIC)
                {
                    l_data64.setBit<FREEZE_PROXY>();
                }

                FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                        l_phb_target,
                                        l_phb_unit_pos),
                          "Error getting fapi2::ATTR_CHIP_UNIT_POS");

                FAPI_INF("PHB target %d", l_phb_unit_pos);

                //If enable bit is not set just update
                //link type and populate bits
                if (!l_data64.getBit<DL_ENABLE_BIT>())
                {
                    FAPI_INF("DISABLED PHB target %d", l_phb_unit_pos);
                    g_io_pci_disable_link |= BIT64(l_phb_unit_pos);
                    g_link_data[l_phb_unit_pos + PCI0_0].sub_type = htobe32(l_sub_type);
                    g_link_data[l_phb_unit_pos + PCI0_0].base_power_mw = htobe32(link_powers[l_sub_type].power_mw[DISABLED]);
                    FAPI_TRY(putScom(l_phb_target, g_pcie_pasr_reg[0], l_data64));
                    continue;
                }


                g_io_pci_active_link |= BIT64(l_phb_unit_pos);




                FAPI_TRY(putScom(l_phb_target, g_pcie_pasr_reg[0], l_data64));

                //We read PAST register to find the PCIE Generation
                //Bit 5:7       Bit8:9 (Bifurcation way)
                //001: GEN1     00 - x4
                //010: GEN2     01 - x4
                //011: GEN3     10 - x8
                //100: GEN4     11 - x16
                //101: GEN5
                FAPI_TRY(getScom(l_phb_target, g_pcie_past_reg[0], l_data64));
                l_data64.extractToRight<5, 3>(l_pci_gen_info);
                l_data64.extractToRight<8, 2>(l_pci_gen_size);

                FAPI_INF("PCI GEN info %d l_pci_gen_size %d", l_pci_gen_info, l_pci_gen_size);

                if ( l_attr_vio_boot_vlt >= 1000)
                {
                    l_sub_type = G5_32G_VIO_1V + (5 - l_pci_gen_info % 5);
                }
                else
                {
                    l_sub_type = G5_32G_VIO_PT_9V + (5 - l_pci_gen_info % 5);
                }

                l_width = QTR;

                if (l_pci_gen_size == 2)
                {
                    l_width = HALF;
                }

                if (l_pci_gen_size == 3)
                {
                    l_width = FULL;
                }



                g_link_data[l_phb_unit_pos + PCI0_0].sub_type = htobe32(l_sub_type);
                g_link_data[l_phb_unit_pos + PCI0_0].base_power_mw = htobe32(link_powers[l_sub_type].power_mw[l_width]);
                FAPI_INF("PCIE g_link_data[%d] = %08x width %d, l_sub_type %d", l_phb_unit_pos + PCI0_0,
                         htobe32(g_link_data[l_phb_unit_pos + PCI0_0].base_power_mw), l_width, l_sub_type);
            }

        }

        FAPI_INF("g_io_pci_active_link %08x", g_io_pci_active_link >> 32);
        FAPI_INF("g_io_pci_disable_link %08x", g_io_pci_disable_link >> 32);

    }
    while(0);

fapi_try_exit:
#endif
    FAPI_IMP("<<< pec_iodlr_static_config");
    return fapi2::current_err;
}
// -----------------------------------------------------------------------------
//  iohs_iodlr_static_config Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode iohs_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifndef __PPE__
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_cplt_cntl5;
    fapi2::ReturnCode l_rc;
    FAPI_IMP(">>> iohs_iodlr_static_config");
    fapi2::ATTR_IOHS_CONFIG_MODE_Type l_iohs_config;
    fapi2::ATTR_FREQ_IOHS_LINK_MHZ_Type l_iohs_freq;
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;
    fapi2::ATTR_WOF_IO_POWER_MODE_Type l_wof_pwr_mode;
    uint32_t l_attr_vio_boot_vlt = 0;
    uint8_t l_iohs_unit_pos = 0;
    uint32_t l_speed = 0;
    io_sub_type_speed_t l_sub_speed_type;
    uint16_t l_total_half_wght = 0;
    uint16_t l_total_qtr_wght = 0;
    uint32_t iohs_pos = 0;

    do
    {
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_VIO_SET_POINT_MV,
                                i_target,
                                l_attr_vio_boot_vlt),
                  "Error getting ATTR_VIO_SET_POINT_MV");

        //If VIO is 0 from attr, then will set to 1V
        if (!l_attr_vio_boot_vlt)
        {
            l_attr_vio_boot_vlt = 1000;
        }

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ,
                                i_target,
                                l_omi_freq),
                  "Error getting ATTR_FREQ_OMI_MHZ");

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_POWER_MODE,
                                i_target,
                                l_wof_pwr_mode),
                  "Error getting ATTR_WOF_IO_POWER_MODE");

        for (const auto l_iohs_target :
             i_target.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IOHS_CONFIG_MODE,
                                    l_iohs_target,
                                    l_iohs_config),
                      "Error getting ATTR_IOHS_CONFIG_MODE");

            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_IOHS_LINK_MHZ,
                                    l_iohs_target,
                                    l_iohs_freq),
                      "Error getting ATTR_FREQ_IOHS_LINK_MHZ");

            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                    l_iohs_target,
                                    l_iohs_unit_pos),
                      "Error getting fapi2::ATTR_CHIP_UNIT_POS");

            iohs_pos = l_iohs_unit_pos * 2;


            //Find the 9/18 lane width
            for (uint8_t x = 0; x < 1; x++)
            {
                FAPI_TRY(getScom(l_iohs_target, g_iohs_ax_dll_status_reg[x], l_data64));

                if (l_iohs_freq > 25781 && l_iohs_freq < 32000)
                {
                    l_speed = 3; //A/X Bus 25G
                }
                else
                {
                    l_speed = 4; //A/X Bus 32G
                }


                if (l_iohs_config == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX ||
                    l_iohs_config == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
                {
                    l_sub_speed_type = (l_speed == 3 && l_attr_vio_boot_vlt >= 1000) ? AX_25G_VIO_1V : AX_25G_VIO_PT_9V;

                    if (l_speed == 4)
                    {
                        l_sub_speed_type = l_attr_vio_boot_vlt >= 1000 ? AX_32G_VIO_1V : AX_32G_VIO_PT_9V;
                    }

                }
                else
                {
                    l_speed += 2; //OC 5:25G, 6:32G
                    l_sub_speed_type = (l_speed == 5 && l_attr_vio_boot_vlt >= 1000) ? OC_25G_VIO_1V : OC_25G_VIO_PT_9V;

                    if (l_speed == 6)
                    {
                        l_sub_speed_type = l_attr_vio_boot_vlt >= 1000 ? OC_32G_VIO_1V : OC_32G_VIO_PT_9V;
                    }

                }

                //If enable bit is not set just update
                //link type and populate bits
                if (!l_data64.getBit<DLP_DLL_STATUS_0_LINK_UP>() &&
                    !l_data64.getBit<DLP_DLL_STATUS_1_LINK_UP>())
                {
                    {
                        if ( l_sub_speed_type < OC_25G_VIO_PT_9V)
                        {
                            g_link_data[iohs_pos + x + OPT0_AX0].sub_type = htobe32(l_sub_speed_type);
                            g_io_iohs_ax_disable_link |= BIT64(iohs_pos + x);
                            g_link_data[iohs_pos + x + OPT0_AX0].base_power_mw = htobe32(
                                        link_powers[l_sub_speed_type].power_mw[DISABLED] >> 1);
                        }
                        else
                        {
                            g_link_data[iohs_pos + x + OPT0_O0].sub_type = htobe32(l_sub_speed_type);
                            g_io_iohs_oc_disable_link |= BIT64((iohs_pos) + x);
                            g_link_data[iohs_pos + x + OPT0_O0].base_power_mw = htobe32(
                                        link_powers[l_sub_speed_type].power_mw[DISABLED] >> 1);
                        }
                    }
                    {
                        if ( l_sub_speed_type < OC_25G_VIO_PT_9V)
                        {
                            g_link_data[iohs_pos + x + OPT0_AX0 + 1].sub_type = htobe32(l_sub_speed_type);
                            g_io_iohs_ax_disable_link |= BIT64(iohs_pos + x + 1);
                            g_link_data[iohs_pos + x + OPT0_AX0 + 1].base_power_mw = htobe32(
                                        link_powers[l_sub_speed_type].power_mw[DISABLED] >> 1);
                        }
                        else
                        {
                            g_link_data[iohs_pos + x + OPT0_O0 + 1].sub_type = htobe32(l_sub_speed_type);
                            g_io_iohs_oc_disable_link |= BIT64((iohs_pos) + x + 1);
                            g_link_data[iohs_pos + x + OPT0_O0 + 1].base_power_mw = htobe32(
                                        link_powers[l_sub_speed_type].power_mw[DISABLED] >> 1);
                        }
                    }
                    continue;
                }

                g_io_iohs_sub_type = l_sub_speed_type;

                if ( l_sub_speed_type < OC_25G_VIO_PT_9V)
                {

                    if ( l_data64.getBit<DLP_DLL_STATUS_0_LINK_UP>() &&
                         l_data64.getBit<DLP_DLL_STATUS_1_LINK_UP>())
                    {
                        g_link_data[iohs_pos + x + OPT0_AX0].sub_type = htobe32(l_sub_speed_type);
                        g_link_data[iohs_pos + x + OPT0_AX0 + 1].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_ax_active_link |= BIT64(iohs_pos + x);
                        g_io_iohs_ax_active_link |= BIT64(iohs_pos + x + 1);
                        g_link_data[iohs_pos + x + OPT0_AX0].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[FULL] >> 1);
                        g_link_data[iohs_pos + x + OPT0_AX0 + 1].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[FULL] >> 1);
                    }
                    else if ( l_data64.getBit<DLP_DLL_STATUS_0_LINK_UP>())
                    {
                        g_link_data[iohs_pos + x + OPT0_AX0].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_ax_active_link |= BIT64(iohs_pos + x);
                        g_link_data[iohs_pos + x + OPT0_AX0].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[HALF]);
                    }
                    else if(l_data64.getBit<DLP_DLL_STATUS_1_LINK_UP>())
                    {
                        g_link_data[iohs_pos + x + OPT0_AX0 + 1].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_ax_active_link |= BIT64(iohs_pos + x + 1);
                        g_link_data[iohs_pos + x + OPT0_AX0 + 1].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[HALF]);
                    }

                    FAPI_INF("AX0 g_link_data[%d] = %08x", iohs_pos + x + OPT0_AX0,
                             htobe32(g_link_data[iohs_pos + x + OPT0_AX0].base_power_mw));
                }
                else
                {
                    if (l_iohs_unit_pos == 1 ||
                        l_iohs_unit_pos == 2)
                    {
                        FAPI_INF("Skip as we are in OC configuration %d", l_iohs_unit_pos);
                        continue;
                    }

#if 0

                    if ( l_iohs_unit_pos != 1 && l_iohs_unit_pos != 2)
                    {
                        g_io_iohs_oc_active_link |= BIT64((iohs_pos) + x);
                    }

#endif

                    uint8_t index = iohs_pos;

                    if ( l_data64.getBit<DLP_DLL_STATUS_0_LINK_UP>() &&
                         l_data64.getBit<DLP_DLL_STATUS_1_LINK_UP>())
                    {
                        g_link_data[index + x + OPT0_O0].sub_type = htobe32(l_sub_speed_type);
                        g_link_data[index + x + OPT0_O0 + 1].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_oc_active_link |= BIT64((iohs_pos) + x);
                        g_io_iohs_oc_active_link |= BIT64((iohs_pos) + x + 1);
                        g_link_data[index + x + OPT0_O0].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[FULL] >> 1);
                        g_link_data[index + x + OPT0_O0 + 1].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[FULL] >> 1);

                    }
                    else if ( l_data64.getBit<DLP_DLL_STATUS_0_LINK_UP>())
                    {
                        g_link_data[index + x + OPT0_O0].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_oc_active_link |= BIT64((iohs_pos) + x);
                        g_link_data[index + x + OPT0_O0].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[HALF]);
                    }
                    else if(l_data64.getBit<DLP_DLL_STATUS_1_LINK_UP>())
                    {
                        g_link_data[index + x + OPT0_O0 + 1].sub_type = htobe32(l_sub_speed_type);
                        g_io_iohs_oc_active_link |= BIT64((iohs_pos) + x + 1);
                        g_link_data[index + x + OPT0_O0 + 1].base_power_mw = htobe32(
                                    link_powers[l_sub_speed_type].power_mw[HALF]);
                    }

                    FAPI_INF("OC0 g_link_data[%d] = %08x", index + OPT0_O0, htobe32(g_link_data[index + OPT0_O0].base_power_mw));
                }

                g_oc_speed_type = l_sub_speed_type;

            }

            for (uint8_t x = 0; x < 2; x++)
            {
                FAPI_TRY(getScom(l_iohs_target, g_iohs_ax_apcr_reg[x], l_data64));

                l_data64.setBit<LINK_POPULATED_BIT>();

                if (l_iohs_freq > 25781 && l_iohs_freq < 32000)
                {
                    l_speed = 3; //A/X Bus 25G
                }
                else
                {
                    l_speed = 4; //A/X Bus 32G
                }

                if (l_wof_pwr_mode == fapi2::ENUM_ATTR_WOF_IO_POWER_MODE_STATIC)
                {
                    l_data64.setBit<FREEZE_PROXY>();
                    FAPI_TRY(putScom(l_iohs_target, g_iohs_ax_apor_reg[x], 0xFFFFFFF0FFFFFFF0));
                }

                if (l_iohs_config == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPX ||
                    l_iohs_config == fapi2::ENUM_ATTR_IOHS_CONFIG_MODE_SMPA)
                {
                    l_sub_speed_type = (l_speed == 3 && l_attr_vio_boot_vlt >= 1000) ? AX_25G_VIO_1V : AX_25G_VIO_PT_9V;

                    if (l_speed == 4)
                    {
                        l_sub_speed_type = l_attr_vio_boot_vlt >= 1000 ? AX_32G_VIO_1V : AX_32G_VIO_PT_9V;
                    }

                    l_data64.insertFromRight(l_speed, LINK_TYPE_BIT, LINK_TYPE_BIT_LEN);
                }
                else
                {
                    l_speed += 2; //OC 5:25G, 6:32G
                    l_sub_speed_type = (l_speed == 5 && l_attr_vio_boot_vlt >= 1000) ? OC_25G_VIO_1V : OC_25G_VIO_PT_9V;

                    if (l_speed == 6)
                    {
                        l_sub_speed_type = l_attr_vio_boot_vlt >= 1000 ? OC_32G_VIO_1V : OC_32G_VIO_PT_9V;
                    }

                    l_data64.insertFromRight(l_speed, LINK_TYPE_BIT, LINK_TYPE_BIT_LEN);
                }

                //If enable bit is not set just update
                //link type and populate bits
                if (!l_data64.getBit<DL_ENABLE_BIT>())
                {
                    FAPI_TRY(putScom(l_iohs_target, g_iohs_ax_apcr_reg[x], l_data64));
                    continue;
                }

                if ( l_sub_speed_type < OC_25G_VIO_PT_9V)
                {
                    l_total_half_wght = link_powers[l_sub_speed_type].half_weight;
                    l_total_qtr_wght = link_powers[l_sub_speed_type].qtr_weight;
                }
                else
                {
                    if (l_iohs_unit_pos == 1 ||
                        l_iohs_unit_pos == 2)
                    {
                        FAPI_INF("Skip as we are in OC configuration %d", l_iohs_unit_pos);
                        continue;
                    }

                    l_total_half_wght = link_powers[l_sub_speed_type].half_weight;
                    l_total_qtr_wght = link_powers[l_sub_speed_type].qtr_weight;
                }

                l_data64.insertFromRight(l_total_half_wght, DIV2_WEIGHT_BIT, DIV2_WEIGHT_BIT_LEN);
                l_data64.insertFromRight(l_total_qtr_wght, DIV4_WEIGHT_BIT, DIV4_WEIGHT_BIT_LEN);

                FAPI_TRY(putScom(l_iohs_target, g_iohs_ax_apcr_reg[x], l_data64));
            }


        } //end of iohs target


        FAPI_INF("g_io_iohs_ax_active_link %08x", g_io_iohs_ax_active_link >> 32);
        FAPI_INF("g_io_iohs_ax_disable_link %08x", g_io_iohs_ax_disable_link >> 32);
        FAPI_INF("g_io_iohs_oc_active_link %08x", g_io_iohs_oc_active_link >> 32);
        FAPI_INF("g_io_iohs_oc_disable_link %08x", g_io_iohs_oc_disable_link >> 32);
    }
    while(0);

fapi_try_exit:
#endif
    FAPI_IMP("<<< iohs_iodlr_static_config");
    return fapi2::current_err;
}
// -----------------------------------------------------------------------------
//  omi_iodlr_static_config Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode omi_iodlr_static_config(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifndef __PPE__
    fapi2::buffer<uint64_t> l_data64;
    fapi2::buffer<uint64_t> l_cplt_cntl5;
    fapi2::ReturnCode l_rc;
    FAPI_IMP(">>> omi_iodlr_static_config");
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;
    fapi2::ATTR_WOF_IO_POWER_MODE_Type l_wof_pwr_mode;
    uint32_t l_attr_vio_boot_vlt = 0;
    uint32_t l_speed = 0;
    uint32_t apcr_address = 0;
    uint32_t apor_address = 0;
    uint8_t l_omic_pos = 0;
    uint8_t x = 0;
    io_sub_type_speed_t l_sub_speed_type;
    io_link_powers_data_t* l_link_power;

    do
    {
        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_VIO_SET_POINT_MV,
                                i_target,
                                l_attr_vio_boot_vlt),
                  "Error getting ATTR_VIO_SET_POINT_MV");

        //If VIO is 0 from attr, then will set to 1V
        if (!l_attr_vio_boot_vlt)
        {
            l_attr_vio_boot_vlt = 1000;
        }

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ,
                                i_target,
                                l_omi_freq),
                  "Error getting ATTR_FREQ_OMI_MHZ");

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_WOF_IO_POWER_MODE,
                                i_target,
                                l_wof_pwr_mode),
                  "Error getting ATTR_WOF_IO_POWER_MODE");

        if (l_omi_freq < 25600)
        {
            l_sub_speed_type = OMI_25G_VIO_PT_9V;

            if (l_attr_vio_boot_vlt >= 1000)
            {
                l_sub_speed_type = OMI_25G_VIO_1V;
            }
        }
        else
        {
            l_sub_speed_type = OMI_32G_VIO_PT_9V;

            if (l_attr_vio_boot_vlt >= 1000)
            {
                l_sub_speed_type = OMI_32G_VIO_1V;
            }
        }

        g_io_omi_sub_type = l_sub_speed_type;

        for (const auto l_omic_target :
             i_target.getChildren<fapi2::TARGET_TYPE_OMIC>(fapi2::TARGET_STATE_FUNCTIONAL))
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_omic_target,
                                   l_omic_pos),
                     "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

            FAPI_IMP("OMIC position %d", l_omic_pos);

            uint8_t omi_lane_width = 0;
            uint8_t omi_prev_cnt = 0;

            for (const auto l_omi_target :
                 l_omic_target.getChildren<fapi2::TARGET_TYPE_OMI>(fapi2::TARGET_STATE_FUNCTIONAL))
            {
                fapi2::ATTR_CHIP_UNIT_POS_Type l_omi_pos;
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       l_omi_target,
                                       l_omi_pos),
                         "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

                x = l_omi_pos % 2;

                apcr_address  = g_omi_even_apcr_reg[x];
                apor_address  = g_omi_even_apor_reg[x];

                FAPI_TRY(getScom(l_omic_target, apcr_address, l_data64));

                l_data64.setBit<LINK_POPULATED_BIT>();


                if (l_wof_pwr_mode == fapi2::ENUM_ATTR_WOF_IO_POWER_MODE_STATIC)
                {
                    l_data64.setBit<FREEZE_PROXY>();
                    FAPI_TRY(putScom(l_omic_target, apor_address, 0xFFFFFFF0FFFFFFF0));
                }

                l_data64.insertFromRight(l_speed, LINK_TYPE_BIT, LINK_TYPE_BIT_LEN);

                //If enable bit is not set just update
                //link type and populate bits
                if (!l_data64.getBit<DL_ENABLE_BIT>())
                {
                    g_io_omi_disable_link |= BIT64(l_omi_pos);
                    g_link_data[l_omi_pos + MC00_OMI0].sub_type = htobe32(l_sub_speed_type);
                    g_link_data[l_omi_pos + MC00_OMI0].base_power_mw += htobe32(link_powers[l_sub_speed_type].power_mw[DISABLED] >> 1);
                    FAPI_TRY(putScom(l_omic_target, apcr_address, l_data64));
                    continue;
                }
                else
                {
                    omi_lane_width += 8;
                }

                l_link_power = &link_powers[l_sub_speed_type];

                l_data64.insertFromRight(l_link_power->half_weight, DIV2_WEIGHT_BIT, DIV2_WEIGHT_BIT_LEN);
                l_data64.insertFromRight(l_link_power->qtr_weight, DIV4_WEIGHT_BIT, DIV4_WEIGHT_BIT_LEN);

                FAPI_TRY(putScom(l_omic_target, apcr_address, l_data64));

                //link power is enabled
                g_io_omi_active_link |= BIT64(l_omi_pos);
                g_link_data[l_omi_pos + MC00_OMI0].sub_type = htobe32(l_sub_speed_type);

                if ( omi_lane_width == 8)
                {
                    omi_prev_cnt = l_omi_pos + MC00_OMI0;
                    g_link_data[l_omi_pos + MC00_OMI0].base_power_mw = htobe32(link_powers[l_sub_speed_type].power_mw[HALF]);
                }
                else
                {
                    g_link_data[omi_prev_cnt].base_power_mw = htobe32(link_powers[l_sub_speed_type].power_mw[FULL] >> 1);
                    g_link_data[l_omi_pos + MC00_OMI0].base_power_mw = htobe32(link_powers[l_sub_speed_type].power_mw[FULL] >> 1);
                }

                FAPI_INF("OMI g_link_data[%d] = %08x", l_omi_pos + MC00_OMI0,
                         htobe32(g_link_data[l_omi_pos + MC00_OMI0].base_power_mw));
            }
        }//end of omic

        FAPI_INF("g_io_omi_active_link %08x", g_io_omi_active_link >> 32);
        FAPI_INF("g_io_omi_disable_link %08x", g_io_omi_disable_link >> 32);

    }
    while(0);

fapi_try_exit:
#endif
    FAPI_IMP("<<< omi_iodlr_static_config");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  iodlr_pgated_validation Function
// -----------------------------------------------------------------------------
fapi2::ReturnCode iodlr_pgated_validation(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
#ifndef __PPE__
    fapi2::buffer<uint64_t> l_cplt_cntl5;
    fapi2::ReturnCode l_rc;
    FAPI_IMP(">>> iodlr_pgated_validation");
    fapi2::ATTR_IO_GROUNDED_CONTROLLERS_Type l_gnd_cntrlr;
    fapi2::ATTR_IO_GROUNDED_LINKS_Type l_gnd_links;
    io_static_lnks_cntrls l_static_data;
    fapi2::ATTR_FREQ_OMI_MHZ_Type l_omi_freq;
    uint32_t l_attr_vio_boot_vlt = 1000;
    uint8_t l_mc_unit_pos = 0;
//    uint8_t l_pau_unit_pos = 0;
    uint8_t l_iohs_unit_pos = 0;
    uint8_t l_pec_unit_pos = 0;
    uint32_t l_ocb_length_act = 0;

    do
    {

        memset(&l_static_data, 0, sizeof(l_static_data));

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_VIO_SET_POINT_MV,
                                i_target,
                                l_attr_vio_boot_vlt),
                  "Error getting ATTR_VIO_SET_POINT_MV");

        if (!l_attr_vio_boot_vlt)
        {
            l_attr_vio_boot_vlt = 1000;
        }

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_FREQ_OMI_MHZ,
                                i_target,
                                l_omi_freq),
                  "Error getting ATTR_FREQ_OMI_MHZ");


        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IO_GROUNDED_CONTROLLERS,
                                i_target,
                                l_gnd_cntrlr),
                  "Error getting ATTR_IO_GROUNDED_CONTROLLERS");

        FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_IO_GROUNDED_LINKS,
                                i_target,
                                l_gnd_links),
                  "Error getting ATTR_IO_GROUNDED_LINKS");

        l_static_data.io_magic = htobe32(0x53540000);
        l_static_data.io_disable_links = 0;
        l_static_data.io_disable_links = (g_io_omi_disable_link | (g_io_pci_disable_link >> 16)
                                          | (g_io_iohs_ax_disable_link >> 22 ) | (g_io_iohs_oc_disable_link >> 38));

        FAPI_INF("l_static_data.io_disable_links %08x %08x", l_static_data.io_disable_links >> 32,
                 l_static_data.io_disable_links);

        l_static_data.io_disable_links = htobe64(l_static_data.io_disable_links);

        l_static_data.io_active_links = 0;

        l_static_data.io_active_links = (g_io_omi_active_link | (g_io_pci_active_link >> 16)
                                         | (g_io_iohs_ax_active_link >> 22 ) | (g_io_iohs_oc_active_link >> 38));

        FAPI_INF("l_static_data.io_active_links %08x %08x", l_static_data.io_active_links >> 32,
                 l_static_data.io_active_links);

        l_static_data.io_active_links = htobe64(l_static_data.io_active_links);


        //Read the CPLT_CTRL5 register to check the power gated bitstate
        FAPI_TRY(getScom(i_target, TP_TPCHIP_TPC_CPLT_CTRL5_RW, l_cplt_cntl5));

        for (const auto l_iohs_target :
             i_target.getChildren<fapi2::TARGET_TYPE_IOHS>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                    l_iohs_target,
                                    l_iohs_unit_pos),
                      "Error getting fapi2::ATTR_CHIP_UNIT_POS");
            FAPI_INF("IOHS POS PRESENT and FUNCTIONAL %d %d", l_iohs_unit_pos, l_iohs_target.isFunctional());

            if ( l_iohs_target.isFunctional())
            {
                continue;
            }

            l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_iohs_unit_pos + PAU0);
            g_cntrlr_data[l_iohs_unit_pos + PAU0].sub_type = htobe32(g_io_iohs_sub_type);
            g_cntrlr_data[l_iohs_unit_pos + PAU0].base_power_mw = htobe32(link_powers[g_io_iohs_sub_type].power_mw[PGATED]);


        }

        FAPI_INF("AXON l_static_data.io_pwr_gated_cntrlrs %08x ", l_static_data.io_pwr_gated_cntrlrs);

        //Pgated calculation
        for (const auto l_mc_target :
             i_target.getChildren<fapi2::TARGET_TYPE_MC>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                    l_mc_target,
                                    l_mc_unit_pos),
                      "Error getting fapi2::ATTR_CHIP_UNIT_POS");

            FAPI_INF("MC controller %d is PRESENT functional %d", l_mc_unit_pos, l_mc_target.isFunctional());

            if(l_cplt_cntl5.getBit(7 - l_mc_unit_pos) && l_mc_target.isFunctional())
            {
                FAPI_INF("MC controller %d NOT power gated ", l_mc_unit_pos);

                for (const auto l_omic_target :
                     l_mc_target.getChildren<fapi2::TARGET_TYPE_OMIC>(fapi2::TARGET_STATE_PRESENT))
                {
                    uint8_t l_omic_pos = 0;

                    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                           l_omic_target,
                                           l_omic_pos),
                             "fapiGetAttribute of ATTR_CHIP_UNIT_POS failed");

                    if ( l_omic_target.isFunctional())
                    {
                        FAPI_INF("OMIC controller %d is functional ", l_omic_pos);
                        continue;
                    }
                    else
                    {
                        l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_mc_unit_pos + EMO01);
                        l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_omic_pos + OMIC0);
                        g_cntrlr_data[l_mc_unit_pos + EMO01].sub_type = htobe32(g_io_omi_sub_type);
                        g_cntrlr_data[l_mc_unit_pos + EMO01].base_power_mw += htobe32(link_powers[g_io_omi_sub_type].power_mw[PGATED]);
                        FAPI_INF("OMIC controller %d is not functional ", l_omic_pos);
                    }
                }

                continue; //not power gated
            }

            l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_mc_unit_pos + EMO01);
            FAPI_INF("MC controller %d is power gated ", l_mc_unit_pos);

            g_cntrlr_data[l_mc_unit_pos + EMO01].sub_type = htobe32(g_io_omi_sub_type);
            g_cntrlr_data[l_mc_unit_pos + EMO01].base_power_mw = htobe32(link_powers[g_io_omi_sub_type].power_mw[PGATED] * 2);

        }//end of MC

        FAPI_INF("MC l_static_data.io_pwr_gated_cntrlrs %08x ", l_static_data.io_pwr_gated_cntrlrs);

        for (auto l_pec_target : i_target.getChildren<fapi2::TARGET_TYPE_PEC>(fapi2::TARGET_STATE_PRESENT))
        {
            FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                    l_pec_target,
                                    l_pec_unit_pos),
                      "Error getting fapi2::ATTR_CHIP_UNIT_POS");


            if(l_cplt_cntl5.getBit(17 - l_pec_unit_pos))
            {
                for (const auto l_phb_target : l_pec_target.getChildren<fapi2::TARGET_TYPE_PHB>(fapi2::TARGET_STATE_PRESENT))
                {
                    uint8_t l_phb_unit_pos = 0;
                    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                            l_phb_target,
                                            l_phb_unit_pos),
                              "Error getting fapi2::ATTR_CHIP_UNIT_POS");


                    if (l_phb_target.isFunctional())
                    {
                        continue;
                    }
                    else
                    {
                        FAPI_INF("PHB unit is not functional %d of PEC %d", l_phb_unit_pos, l_pec_unit_pos);
                        l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_pec_unit_pos + PEC0);
                        l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_phb_unit_pos + PHB0);
                        g_cntrlr_data[l_pec_unit_pos + PEC0].sub_type = htobe32(G4_32G_VIO_1V);
                        g_cntrlr_data[l_pec_unit_pos + PEC0].base_power_mw += htobe32(link_powers[G4_32G_VIO_1V].power_mw[PGATED]);
                    }
                }

                FAPI_INF("PEC controller %d NOT power gated", l_pec_unit_pos);
                continue; //not power gated
            }


            l_static_data.io_pwr_gated_cntrlrs |= BIT32(l_pec_unit_pos + PEC0);
            FAPI_INF("PEC controller %d is power gated", l_pec_unit_pos);

            g_cntrlr_data[l_pec_unit_pos + PEC0].sub_type = htobe32(G4_32G_VIO_1V);
            g_cntrlr_data[l_pec_unit_pos + PEC0].base_power_mw = htobe32(link_powers[G4_32G_VIO_1V].power_mw[PGATED] * 3);
        } //end of PEC

        FAPI_INF("PEC l_static_data.io_pwr_gated_cntrlrs %08x ", l_static_data.io_pwr_gated_cntrlrs);

        l_static_data.io_pwr_gated_cntrlrs = htobe32(l_static_data.io_pwr_gated_cntrlrs);

        FAPI_INF("l_static_data.io_pwr_gated_cntrlrs %08x ", l_static_data.io_pwr_gated_cntrlrs);

        uint32_t xgpe_sram_base_addr = XGPE_SRAM_IO_OFFSET_ADDR;


        FAPI_EXEC_HWP(l_rc, p10_pm_ocb_indir_setup_linear, i_target,
                      ocb::OCB_CHAN2,
                      ocb::OCB_TYPE_LINSTR,
                      xgpe_sram_base_addr);   // Bar

        FAPI_TRY(p10_pm_ocb_indir_access_bytes(i_target,
                                               ocb::OCB_CHAN2,
                                               ocb::OCB_PUT,
                                               sizeof(l_static_data),
                                               false,
                                               xgpe_sram_base_addr,
                                               l_ocb_length_act,
                                               (uint8_t*)&l_static_data));

        FAPI_INF("Actual length %08x %08x after writing static_data", xgpe_sram_base_addr, l_ocb_length_act);
        xgpe_sram_base_addr = xgpe_sram_base_addr + l_ocb_length_act;

        FAPI_TRY(p10_pm_ocb_indir_access_bytes(i_target,
                                               ocb::OCB_CHAN2,
                                               ocb::OCB_PUT,
                                               sizeof(g_cntrlr_data),
                                               false,
                                               xgpe_sram_base_addr,
                                               l_ocb_length_act,
                                               (uint8_t*)g_cntrlr_data));

        FAPI_INF("Actual length %08X %08x after writing cntrlr data", xgpe_sram_base_addr, l_ocb_length_act);
        xgpe_sram_base_addr = xgpe_sram_base_addr + l_ocb_length_act;

        FAPI_TRY(p10_pm_ocb_indir_access_bytes(i_target,
                                               ocb::OCB_CHAN2,
                                               ocb::OCB_PUT,
                                               sizeof(g_link_data),
                                               false,
                                               xgpe_sram_base_addr,
                                               l_ocb_length_act,
                                               (uint8_t*)g_link_data));
        FAPI_INF("Actual length %08X %08x after writing link data", xgpe_sram_base_addr, l_ocb_length_act);


        FAPI_INF("  Set XGPE_IODLR_ACTIVE in OCC Flag3 Register...");
        FAPI_TRY(putScom(i_target, TP_TPCHIP_OCC_OCI_OCB_OCCFLG3_WO_OR, BIT64(p10hcd::XGPE_IODLR_ACTIVE)));

    }
    while(0);

fapi_try_exit:
#endif
    FAPI_IMP("<<< iodlr_pgated_validation");
    return fapi2::current_err;
}
