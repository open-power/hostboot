/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p9/procedures/hwp/pm/p9_pm_stop_gpe_init.C $ */
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
/// @file p9_pm_stop_gpe_init.C
/// @brief Initialize the Stop GPE and related functions

// *HWP HWP Owner       :   Greg Still <stillgs@us.ibm.com>
// *HWP Backup Owner    :   David Du   <daviddu@us.ibm.com>
// *HWP FW Owner        :   Prem S Jha <premjha2@in.ibm.com>
// *HWP Team            :   PM
// *HWP Level           :   3
// *HWP Consumed by     :   HS

///
/// High-level procedure flow:
/// @verbatim
///   if PM_RESET
///   - Halt the SGPE
///   if PM_INIT
///   - call p9_pm_pfet_init to initialize the PFET controllers from
///       attribute values
///   - call p9_pm_pba_init in PM_RESET mode to get the PBA in "boot" mode
///   - Read the SGPE IVPR value that is in HOMER from Attribute written
///       by p9_hcode_image_build
///   - Sreset the SGPE to start the boot copier from .
///   - Polls OCC Flag bit for HCode init completion
///     - Starting the SGPE will cause a "reboot" of functional CMEs
///  - SGPE will cause Block Copy Engine to pull CPMR code, common rings
///     and Core Pstate Parameter Block into CME SRAM
///  - SGPE checks that CME STOP functions have started as part of the
///     HCode init complete
/// @endverbatim

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <p9_hcd_common.H>
#include <p9_pm_stop_gpe_init.H>
#include <p9_pm_pba_init.H>
#include <p9_pm_pfet_init.H>
#include <p9_pm_hcd_flags.h>
#include <p9_ppe_defs.H>
#include <p9_ppe_utils.H>
#include <p9_eq_clear_atomic_lock.H>
#include <p9_quad_scom_addresses.H>
#include <p9_quad_scom_addresses_fld.H>
#include <p9_misc_scom_addresses.H>
#include <p9_misc_scom_addresses_fld.H>

//#include <p9_ppe_state.H>  @todo RTC 147996 to incorporate PPE state removing strings.


// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

// Map the auto generated names to clearer ones
static const uint64_t PU_OCB_OCI_OCCFLG_CLEAR = PU_OCB_OCI_OCCFLG_SCOM1;
static const uint64_t PU_OCB_OCI_OCCFLG_SET  = PU_OCB_OCI_OCCFLG_SCOM2;

static const uint32_t SGPE_TIMEOUT_MS       = 2500;     // Guess at this time
static const uint32_t SGPE_TIMEOUT_MCYCLES  = 20;       // Guess at this time
static const uint32_t SGPE_POLLTIME_MS      = 20;       // Guess at this time
static const uint32_t SGPE_POLLTIME_MCYCLES = 2;        // Guess at this time
static const uint32_t TIMEOUT_COUNT = SGPE_TIMEOUT_MS / SGPE_POLLTIME_MS;




// -----------------------------------------------------------------------------
//  Function prototypes
// -----------------------------------------------------------------------------

fapi2::ReturnCode stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode stop_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode stop_corecache_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

fapi2::ReturnCode get_functional_chiplet_info(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target ,
    std::vector<uint64_t>& o_ppe_addr_list,
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_EQ > >& o_eq_target_list );
// -----------------------------------------------------------------------------
//  Function definitions
// -----------------------------------------------------------------------------

/// @brief Initialize the Stop GPE and related functions
///
/// @param [in] i_target Chip target
/// @param [in] i_mode   Control mode for the procedure
///                      PM_INIT, PM_RESET
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode p9_pm_stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const p9pm::PM_FLOW_MODE i_mode)
{
    FAPI_IMP(">> p9_pm_stop_gpe_init");

    const char* PM_MODE_NAME_VAR; //Defines storage for PM_MODE_NAME
    FAPI_INF("Executing p9_stop_gpe_init in mode %s", PM_MODE_NAME(i_mode));

    uint8_t                 fusedModeState = 0;
    uint8_t                 coreQuiesceDis = 0;
    uint8_t                 l_core_number  = 0;
    fapi2::buffer<uint64_t> l_data64       = 0;

    // -------------------------------
    // Initialization:  perform order or dynamic operations to initialize
    // the STOP funciton using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {
        const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM> FAPI_SYSTEM;
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FUSED_CORE_MODE,
                               FAPI_SYSTEM,
                               fusedModeState),
                 "Error from FAPI_ATTR_GET for attribute ATTR_FUSED_CORE_MODE");

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_SYSTEM_CORE_PERIODIC_QUIESCE_DISABLE,
                               FAPI_SYSTEM,
                               coreQuiesceDis),
                 "Error from FAPI_ATTR_GET for attribute ATTR_SYSTEM_CORE_PERIODIC_QUIESCE_DISABLE");

        // Check each core has a functional EX and EQ
        auto l_functional_core_vector =
            i_target.getChildren<fapi2::TARGET_TYPE_CORE>
            (fapi2::TARGET_STATE_FUNCTIONAL);

        for(auto l_core_trgt : l_functional_core_vector)
        {
            auto l_ex_trgt = l_core_trgt.getParent<fapi2::TARGET_TYPE_EX>();
            FAPI_ASSERT_NOEXIT(l_ex_trgt.isFunctional() == true,
                               fapi2::STOP_GPE_INVALID_CORE_EX_CONFIG(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CORE(l_core_trgt)
                               .set_EX(l_ex_trgt)
                               .set_CHIP(i_target),
                               "Invalid Config - good core without functional EX");

            auto l_eq_trgt = l_core_trgt.getParent<fapi2::TARGET_TYPE_EQ>();
            FAPI_ASSERT_NOEXIT(l_eq_trgt.isFunctional() == true,
                               fapi2::STOP_GPE_INVALID_CORE_EQ_CONFIG(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_CORE(l_core_trgt)
                               .set_EQ(l_eq_trgt)
                               .set_CHIP(i_target),
                               "Invalid Config - good core without functional EQ");
        }

        // Check each functional EX has at least one functional core
        auto l_functional_ex_vector =
            i_target.getChildren<fapi2::TARGET_TYPE_EX>
            (fapi2::TARGET_STATE_FUNCTIONAL);

        for(auto l_ex_trgt : l_functional_ex_vector)
        {
            auto l_functional_core_vector = l_ex_trgt.getChildren<fapi2::TARGET_TYPE_CORE>
                                            (fapi2::TARGET_STATE_FUNCTIONAL);
            FAPI_ASSERT_NOEXIT(l_functional_core_vector.empty() == false,
                               fapi2::STOP_GPE_INVALID_EX_CORE_CONFIG(fapi2::FAPI2_ERRL_SEV_RECOVERED)
                               .set_EX(l_ex_trgt)
                               .set_CHIP(i_target),
                               "Invalid Config - good EX without any functional cores");
        }




        //Additional settings for fused mode
        if (fusedModeState == 1)
        {
            auto l_functional_core_vector =
                i_target.getChildren<fapi2::TARGET_TYPE_CORE>
                (fapi2::TARGET_STATE_FUNCTIONAL);

            for(auto l_chplt_trgt : l_functional_core_vector)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       l_chplt_trgt,
                                       l_core_number),
                         "ERROR: Failed to get the position of the CORE:0x%08X",
                         l_chplt_trgt);
                FAPI_DBG("CORE number = %d", l_core_number);
                l_data64.flush<0>().setBit<C_CPPM_CPMMR_FUSED_CORE_MODE>();
                FAPI_TRY(fapi2::putScom(l_chplt_trgt, C_CPPM_CPMMR_OR, l_data64),
                         "ERROR: Failed to switch PM/TP interrupt routing to fused");
            }

            l_data64.flush<0>();
            FAPI_TRY(fapi2::getScom(i_target, PU_INT_TCTXT_CFG, l_data64),
                     "ERROR: Failed to read PU_INT_TCTXT_CFG");

            l_data64.setBit<PU_INT_TCTXT_CFG_CFG_FUSE_CORE_EN>();
            FAPI_TRY(fapi2::putScom(i_target, PU_INT_TCTXT_CFG, l_data64),
                     "ERROR: Failed to set Fused core mode in PU_INT_TCTXT_CFG");
        }



        // periodic core quiesce workaround settings
        if (coreQuiesceDis == 1)
        {
            auto l_functional_core_vector =
                i_target.getChildren<fapi2::TARGET_TYPE_CORE>
                (fapi2::TARGET_STATE_FUNCTIONAL);

            for(auto l_chplt_trgt : l_functional_core_vector)
            {
                FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                       l_chplt_trgt,
                                       l_core_number),
                         "ERROR: Failed to get the position of the CORE:0x%08X",
                         l_chplt_trgt);
                FAPI_DBG("CORE number = %d", l_core_number);

                l_data64.flush<0>().setBit<p9hcd::CPPM_CPMMR_DISABLE_PERIODIC_CORE_QUIESCE>();
                FAPI_TRY(fapi2::putScom(l_chplt_trgt, C_CPPM_CPMMR_OR, l_data64),
                         "ERROR: Failed to assert CPMMR.core_periodic_quiesce_disable");
            }
        }

        // Initialize the PFET controllers
        FAPI_EXEC_HWP(fapi2::current_err, p9_pm_pfet_init, i_target, i_mode);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::STOP_GPE_PFETS_FAILED()
                    .set_MODE(i_mode)
                    .set_CHIP(i_target),
                    "PFET setup failed");


        // Condition the PBA back to the base boot configuration
        FAPI_EXEC_HWP(fapi2::current_err, p9_pm_pba_init, i_target, p9pm::PM_RESET);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::STOP_GPE_PBA_INIT_FAILED()
                    .set_CHIP(i_target)
                    .set_MODE(p9pm::PM_RESET),
                    "PBA setup failed");

        // Initialize DPLL Mode and Slew Rate (Done once for runtime STOPs)
        // Hostboot Master is done in istep4 hwp prior to this
        uint8_t                 l_quad_number = 0;
        fapi2::buffer<uint64_t> l_data64      = 0;

        auto l_functional_quad_vector =
            i_target.getChildren<fapi2::TARGET_TYPE_EQ>
            (fapi2::TARGET_STATE_FUNCTIONAL);

        for(auto l_chplt_trgt : l_functional_quad_vector)
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS,
                                   l_chplt_trgt,
                                   l_quad_number),
                     "ERROR: Failed to get the position of the QUAD:0x%08X",
                     l_chplt_trgt);
            FAPI_DBG("QUAD number = %d", l_quad_number);
            l_data64.flush<0>().setBit<2>().insertFromRight<6, 10>(0x01);
            FAPI_TRY(putScom(l_chplt_trgt, EQ_QPPM_DPLL_CTRL_OR, l_data64),
                     "ERROR: Failed to assert DPLL in mode 1 and set slew rate to 1");
        }

        uint8_t l_ivrm_attrval = 0;
        uint8_t l_vdm_attrval = 0;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_IVRM_ENABLED,
                               i_target,
                               l_ivrm_attrval),
                 "Error from FAPI_ATTR_GET for attribute ATTR_IVRM_ENABLED" );

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_VDM_ENABLED,
                               i_target,
                               l_vdm_attrval),
                 "Error from FAPI_ATTR_GET for attribute ATTR_VDM_ENABLED" );

        if((l_vdm_attrval || l_ivrm_attrval))
        {
            //check vref calibration bit set or not
            //PERV_TP_KVREF_AND_VMEAS_MODE_STATUS_REG
            //--> 0x01020007
            FAPI_TRY(fapi2::getScom(i_target, 0x01020007, l_data64));

            if ( !(l_data64.getBit<16>()))
            {
                FAPI_ERR("VDMs/IVRM are enabled but necessary VREF calibration failed");
                FAPI_ASSERT(false,
                            fapi2::STOP_GPE_VREF_CALIBRATION_FAILED()
                            .set_CHIP(i_target)
                            .set_VREF_CALIBRATION_ADDRESS(0x01020007)
                            .set_IS_VDM_ENABLED(l_vdm_attrval)
                            .set_IS_IVRM_ENABLED(l_ivrm_attrval),
                            "ERROR; VREF calibration bit is not set %x",
                            (uint32_t)l_data64);
            }
        }

        // Setup the SGPE Timer Selects
        // These hardcoded values are assumed by the SGPE Hcode for setting up
        // the FIT and Watchdog values.
        l_data64.flush<0>()
        .insertFromRight<0, 4>(0x1)     // Watchdog
        .insertFromRight<4, 4>(0xA);    // FIT
        FAPI_TRY(fapi2::putScom(i_target, PU_GPE3_GPETSEL_SCOM, l_data64));

        // Boot the STOP GPE
        FAPI_TRY(stop_gpe_init(i_target), "ERROR: failed to initialize Stop GPE");


    }

    //-------------------------------
    // Reset:  perform reset of STOP function including the STOP GPE
    // so that it can reconfigured and reinitialized
    else if (i_mode == p9pm::PM_RESET)
    {
        FAPI_TRY(stop_gpe_reset(i_target), "ERROR: failed to reset Stop GPE");
    }

    // -------------------------------
    // Unsupported Mode
    else
    {
        FAPI_ERR("Unknown mode passed to p9_stop_gpe_init. Mode %x ....", i_mode);
        FAPI_ASSERT(false,
                    fapi2::STOP_GPE_BAD_MODE()
                    .set_BADMODE(i_mode),
                    "ERROR; Unknown mode passed to stop_gpe_init. Mode %x",
                    i_mode);
    }

fapi_try_exit:
    FAPI_INF("<< p9_pm_stop_gpe_init");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  STOP GPE Initialization Function
// -----------------------------------------------------------------------------

/// @brief Initializes the STOP GPE and related STOP functions on a chip
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS else ERROR defined in xml

fapi2::ReturnCode stop_gpe_init(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{
    fapi2::buffer<uint64_t> l_occ_flag;
    fapi2::buffer<uint64_t> l_xcr;
    fapi2::buffer<uint64_t> l_xsr;
    fapi2::buffer<uint64_t> l_iar;
    fapi2::buffer<uint64_t> l_ir;
    fapi2::buffer<uint64_t> l_ivpr;
    fapi2::buffer<uint64_t> l_slave_cfg;
    uint32_t                l_ivpr_offset;
    uint32_t                l_timeout_in_MS = TIMEOUT_COUNT;
    std::vector<uint64_t> l_ppe_base_addr_list;
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_EQ> > l_eq_list;

    FAPI_IMP(">> stop_gpe_init");

    FAPI_TRY( get_functional_chiplet_info( i_target, l_ppe_base_addr_list, l_eq_list ),
              "Failed to get PPE Base Address List and Func EQ List" );

    // First check if SGPE_ACTIVE is not set in OCCFLAG register
    FAPI_TRY(getScom(i_target, PU_OCB_OCI_OCCFLG_SCOM, l_occ_flag));

    if (l_occ_flag.getBit<p9hcd::SGPE_ACTIVE>() == 1)
    {
        FAPI_INF("WARNING: SGPE_ACTIVE flag is already set in OCCFLAG register, continuing with after clearing that active_bit");
        l_occ_flag.flush<0>();
        l_occ_flag.setBit<p9hcd::SGPE_ACTIVE>();
        FAPI_TRY(putScom(i_target, PU_OCB_OCI_OCCFLG_CLEAR, l_occ_flag),
                 "ERROR: Failed to clear sgpe_active bit in OCCFLG register");
    }

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET,
                            i_target,
                            l_ivpr_offset),
              "Error getting ATTR_SGPE_BOOT_COPIER_IVPR_OFFSET");

    // Program SGPE IVPR
    l_ivpr.flush<0>().insertFromRight<0, 32>(l_ivpr_offset);
    FAPI_INF("   Writing IVPR with 0x%16llX", l_ivpr);
    FAPI_TRY(putScom(i_target, PU_GPE3_GPEIVPR_SCOM, l_ivpr));

    // Program XCR to ACTIVATE SGPE
    l_xcr.flush<0>().insertFromRight(p9hcd::HARD_RESET, 1 , 3);
    FAPI_TRY(putScom(i_target, PU_GPE3_PPE_XIXCR, l_xcr));
    l_xcr.flush<0>().insertFromRight(p9hcd::TOGGLE_XSR_TRH, 1 , 3);
    FAPI_TRY(putScom(i_target, PU_GPE3_PPE_XIXCR, l_xcr));
    l_xcr.flush<0>().insertFromRight(p9hcd::RESUME, 1 , 3);
    FAPI_TRY(putScom(i_target, PU_GPE3_PPE_XIXCR, l_xcr));

    // Now wait for SGPE to not be halted and for the HCode to indicate
    // to be active.
    l_occ_flag.flush<0>();
    l_xsr.flush<0>();

    do
    {
        FAPI_TRY(getScom(i_target, PU_OCB_OCI_OCCFLG_SCOM, l_occ_flag));
        FAPI_TRY(getScom(i_target, PU_GPE3_GPEXIXSR_SCOM, l_xsr));
        FAPI_TRY(getScom(i_target, PU_GPE3_GPEXIIAR_SCOM, l_iar));
        FAPI_TRY(getScom(i_target, PU_GPE3_GPEXIIR_SCOM, l_ir));
        FAPI_DBG("   Poll content: OCC Flag: 0x%16llX; XSR: 0x%16llX  IAR: 0x%16llX IR: 0x%16llX Timeout: %d",
                 l_occ_flag,
                 l_xsr,
                 l_iar,
                 l_ir,
                 l_timeout_in_MS);
        fapi2::delay(SGPE_POLLTIME_MS * 1000, SGPE_POLLTIME_MCYCLES * 1000 * 1000);
    }
    while((!((l_occ_flag.getBit<p9hcd::SGPE_ACTIVE>() == 1) &&
             (l_xsr.getBit<p9hcd::HALTED_STATE>() == 0))) &&
          (--l_timeout_in_MS != 0));

    if((l_occ_flag.getBit<p9hcd::SGPE_ACTIVE>() == 1))
    {
        FAPI_INF("SGPE was activated successfully!!!!");
    }


    if( 0 == l_timeout_in_MS )
    {
        // SGPE failed to boot or one more CME failed to boot.
        // We need to collec the FFDC. Let us clear the atomic
        // lock first to enable collection of CME's FFDC.

        for( auto eq : l_eq_list )
        {
            p9_clear_atomic_lock( eq );
        }

        FAPI_ASSERT( false,
                     fapi2::STOP_GPE_INIT_TIMEOUT()
                     .set_CHIP(i_target)
                     .set_OCC_FLAG_REG_VAL( l_occ_flag )
                     .set_XSR_REG_VAL( l_xsr )
                     .set_PPE_STATE_MODE(HALT)
                     .set_PPE_BASE_ADDRESS_LIST(l_ppe_base_addr_list),
                     "STOP GPE Init Timeout");
    }


fapi_try_exit:
    FAPI_IMP("<< stop_gpe_init");
    return fapi2::current_err;
}

// -----------------------------------------------------------------------------
//  Stop GPE Function
// -----------------------------------------------------------------------------

/// @brief Stops the Stop GPE
///
/// @param [in] i_target Chip target
///
/// @retval FAPI_RC_SUCCESS
/// @retval ERROR defined in xml

fapi2::ReturnCode stop_gpe_reset(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    fapi2::buffer<uint64_t> l_data64;
    uint32_t                l_timeout_in_MS = 100;
    std::vector<uint64_t> l_ppe_base_addr_list;
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_EQ> > l_eq_list;

    FAPI_IMP(">> stop_gpe_reset...");
    FAPI_TRY( get_functional_chiplet_info( i_target, l_ppe_base_addr_list, l_eq_list ),
              "Failed to get PPE Base Address List and Func EQ List" );

    // Program XCR to HALT SGPE
    FAPI_INF("   Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::HALT, 1, 3);
    FAPI_TRY(putScom(i_target, PU_GPE3_PPE_XIXCR, l_data64));

    //Now wait for SGPE to be halted.
    FAPI_INF("   Poll for HALT State via XSR...");

    do
    {
        FAPI_TRY(getScom(i_target, PU_GPE3_GPEXIXSR_SCOM, l_data64));
        fapi2::delay(SGPE_POLLTIME_MS * 1000, SGPE_POLLTIME_MCYCLES * 1000 * 1000);
    }
    while((l_data64.getBit<p9hcd::HALTED_STATE>() == 0) && (--l_timeout_in_MS != 0));

    if( 0 == l_timeout_in_MS )
    {
        // SGPE Reset Failed.
        // We need to collect the FFDC. Let us clear the atomic
        // lock first to enable collection of CME's FFDC.

        for( auto eq : l_eq_list )
        {
            p9_clear_atomic_lock( eq );
        }

        FAPI_ASSERT( false,
                     fapi2::STOP_GPE_RESET_TIMEOUT()
                     .set_CHIP(i_target)
                     .set_PPE_STATE_MODE(HALT)
                     .set_PPE_BASE_ADDRESS_LIST(l_ppe_base_addr_list),
                     "STOP Reset Timeout");
    }

    FAPI_INF("   Clear SGPE_ACTIVE in OCC Flag Register...");
    l_data64.flush<0>().setBit<p9hcd::SGPE_ACTIVE>();
    FAPI_TRY(putScom(i_target, PU_OCB_OCI_OCCFLG_SCOM1, l_data64));

fapi_try_exit:
    FAPI_IMP("<< stop_gpe_reset...");
    return fapi2::current_err;

}

// -----------------------------------------------------------------------------
// EX Stop Setup Function
//  Note:   PMGP0 and OCC Special Wakeup actions could be done with multicast in
//          the future.
// -----------------------------------------------------------------------------

// @brief Resets the STOP function for each Core and Cache chiplet
//
// @param [in] i_target Chip target
//
// @retval FAPI_RC_SUCCESS
// @retval ERROR defined in xml

fapi2::ReturnCode stop_corecache_setup(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target)
{

    FAPI_INF("Executing stop_corecache_setup...");

    // Get all core chiplets
    auto l_core_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_CORE>
        (fapi2::TARGET_STATE_FUNCTIONAL);
    // Get all cache chiplets
    auto l_cache_functional_vector =
        i_target.getChildren<fapi2::TARGET_TYPE_EQ>
        (fapi2::TARGET_STATE_FUNCTIONAL);

    return fapi2::current_err;
}

// @brief Returns target for all functional EQ and base address of SGPE and all functional CMEs
// @param[in]   i_target            fapi2 target for P9 chip
// @param[out]  o_ppe_addr_list     list of base addresses for CMEs and SGPE
// @param[out]  o_eq_target_list    list of EQ target
// @return      fapi2 return code
// @note        instead of  getting functional status from platform targeting, for better reliability
//              we shall use value of QCSR register.
fapi2::ReturnCode get_functional_chiplet_info(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    std::vector<uint64_t>& o_ppe_addr_list,
    std::vector< fapi2::Target<fapi2::TARGET_TYPE_EQ > >& o_eq_target_list )
{

    FAPI_INF(">> get_functional_chiplet_info");

    fapi2::buffer<uint64_t>    l_qcsrBuf;
    uint8_t l_exPos = 0;

    auto l_ex_vector = i_target.getChildren<fapi2::TARGET_TYPE_EX>( fapi2::TARGET_STATE_PRESENT );
    FAPI_TRY(getScom(i_target, PU_OCB_OCI_QCSR_SCOM, l_qcsrBuf));
    FAPI_INF( "QCS  Val 0x%16llX", l_qcsrBuf );

    o_ppe_addr_list.push_back( SGPE_BASE_ADDRESS );

    for ( auto ex : l_ex_vector )
    {
        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, ex, l_exPos ));

        if( l_qcsrBuf.getBit( l_exPos ) )
        {
            FAPI_INF("Func EX %d ", l_exPos );
            o_ppe_addr_list.push_back( getCmeBaseAddress( l_exPos ) );
            fapi2::Target< fapi2::TARGET_TYPE_EQ > l_parentEq = ex.getParent<fapi2::TARGET_TYPE_EQ>();
            std::vector< fapi2::Target< fapi2::TARGET_TYPE_EQ > >::iterator l_eq;
            l_eq = std::find ( o_eq_target_list.begin(), o_eq_target_list.end(), l_parentEq );

            if ( l_eq != o_eq_target_list.end() )
            {
                continue;
            }

            FAPI_INF("Func EQ %d ", (l_exPos >> 1 ) );
            o_eq_target_list.push_back( l_parentEq );
        }

    }

fapi_try_exit:
    FAPI_INF("<< get_functional_chiplet_info");
    return fapi2::current_err;
}

