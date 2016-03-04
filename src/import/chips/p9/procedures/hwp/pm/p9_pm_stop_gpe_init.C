/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_stop_gpe_init.C $            */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015,2016                                                    */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
/// @file p9_pm_stop_gpe_init.C
/// @brief Initialize the Stop GPE and related functions

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

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

#include <p9_hcd_common.H>
#include <p9_pm_stop_gpe_init.H>
#include <p9_pm_pba_init.H>
#include <p9_pm_pfet_init.H>


// @todo RTC 147679 This will be uncommented upon the formal availability
// This is needed to initialize the special wakeup tracking attributes
// in stop_corecache_setup section
//#include "p9_cpu_special_wakeup.H"

// ----------------------------------------------------------------------
// Constants
// ----------------------------------------------------------------------

// Map the auto generated names to clearer ones
static const uint64_t PU_OCB_OCI_OCCFLG_CLEAR = PU_OCB_OCI_OCCFLG_SCOM1;
static const uint64_t PU_OCB_OCI_OCCFLG_SET  = PU_OCB_OCI_OCCFLG_SCOM2;

static const uint32_t SGPE_TIMEOUT_MS       = 500;      // Guess at this time
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
    FAPI_IMP("> p9_pm_stop_gpe_init");

    const char* PM_MODE_NAME_VAR; //Defines storage for PM_MODE_NAME
    FAPI_INF("Executing p9_stop_gpe_init in mode %s", PM_MODE_NAME(i_mode));

    // -------------------------------
    // Initialization:  perform order or dynamic operations to initialize
    // the STOP funciton using necessary Platform or Feature attributes.
    if (i_mode == p9pm::PM_INIT)
    {

        // Initialize the PFET controllers
        FAPI_EXEC_HWP(fapi2::current_err, p9_pm_pfet_init, i_target, i_mode);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::STOP_GPE_PFETS_FAILED()
                    .set_TARGET(i_target)
                    .set_MODE(i_mode),
                    "PFET setup failed");


        // Condition the PBA back to the base boot configuration
        FAPI_EXEC_HWP(fapi2::current_err, p9_pm_pba_init, i_target, p9pm::PM_RESET);

        FAPI_ASSERT(fapi2::current_err == fapi2::FAPI2_RC_SUCCESS,
                    fapi2::STOP_GPE_PBA_INIT_FAILED()
                    .set_TARGET(i_target)
                    .set_MODE(p9pm::PM_RESET),
                    "PBA setup failed");

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
    FAPI_INF("< p9_pm_stop_gpe_init");
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
    fapi2::buffer<uint64_t> l_ivpr;
    uint32_t                l_ivpr_offset;
    uint32_t                l_timeout_in_MS = TIMEOUT_COUNT;

    FAPI_IMP(">> stop_gpe_init......");

    FAPI_TRY( FAPI_ATTR_GET(fapi2::ATTR_STOPGPE_BOOT_COPIER_IVPR_OFFSET,
                            i_target,
                            l_ivpr_offset),
              "Error getting ATTR_SGPE_BOOT_COPIER_IVPR_OFFSET");

    // Program SGPE IVPR
    l_ivpr.flush<0>().insertFromRight<0, 32>(l_ivpr_offset);
    FAPI_INF("   Writing IVPR with 0x%16llX", l_ivpr);
    FAPI_TRY(putScom(i_target, PU_GPE3_GPEIVPR_SCOM, l_ivpr));

    // Program XCR to ACTIVATE SGPE
    // @todo 146665 Operations to PPEs should use a p9ppe namespace when created
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
        FAPI_DBG("   Poll content: OCC Flag: 0x%16llX; XSR: 0x%16llX Timeout: %d",
                 l_occ_flag,
                 l_xsr,
                 l_timeout_in_MS);
        fapi2::delay(SGPE_POLLTIME_MS * 1000, SGPE_POLLTIME_MCYCLES * 1000 * 1000);


    }
    while((l_occ_flag.getBit<p9hcd::SGPE_ACTIVE>() != 1) &&
          (l_xsr.getBit<p9hcd::HALTED_STATE>() != 1) &&
          (--l_timeout_in_MS != 0));

    if((l_occ_flag.getBit<p9hcd::SGPE_ACTIVE>() == 1))
    {
        FAPI_INF("SGPE was activated successfully!!!!");
    }

    // @todo 146665 Operations to PPEs should use a p9ppe namespace when created

    FAPI_ASSERT((l_timeout_in_MS != 0),
                fapi2::STOP_GPE_INIT_TIMEOUT()
                .set_OCCFLGSTAT(l_occ_flag)
                .set_XSR(l_xsr),
                "STOP GPE Init timeout");

fapi_try_exit:
    FAPI_IMP("<< stop_gpe_init......");
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


    FAPI_IMP(">> stop_gpe_reset...");

    // Program XCR to HALT SGPE
    // @todo This should be replace by a call to a common PPE service class
    // ppe<PPE_TYPE_GPE>gpe3(3);
    // gpe3.hard_reset();
    FAPI_INF("   Send HALT command via XCR...");
    l_data64.flush<0>().insertFromRight(p9hcd::HALT, 1, 3);
    FAPI_TRY(putScom(i_target, PU_GPE3_PPE_XIXCR, l_data64));

    //Now wait for SGPE to be halted.
    // @todo This loop should be replace by a call to a common PPE service class
    // FAPI_TRY(gpe3.is_halted(&b_halted_state, timeout_value_ns, timeout_value_simcycles));
    FAPI_INF("   Poll for HALT State via XSR...");

    do
    {
        FAPI_TRY(getScom(i_target, PU_GPE3_GPEXIXSR_SCOM, l_data64));
    }
    while((l_data64.getBit<p9hcd::HALTED_STATE>() == 0) && (--l_timeout_in_MS != 0));

    FAPI_ASSERT((l_timeout_in_MS != 0),
                fapi2::STOP_GPE_RESET_TIMEOUT()
                .set_SGPEXSRNOTHALT(l_data64),
                "STOP GPE Init timeout");

    FAPI_INF("   Clear SGPE_ACTIVE in OCC Flag Register...");
    l_data64.setBit<p9hcd::SGPE_ACTIVE>();
    FAPI_TRY(putScom(i_target, PU_OCB_OCI_OCCFLG_CLEAR, l_data64));

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
#if 0

    for (auto l_chplt_trgt : l_core_functional_vector)
    {
        // @todo RTC 147679 Enable when special wake-up is available
        // --------------------------------------
        // Initialize the special wake-up tracking attributes
        FAPI_INF("\tInitialize the special wake-up tracking  attributes for the cores");
        FAPI_EXEC_HWP(rc,  p9_cpu_special_wakeup,
                      l_chplt_trgt,
                      SPCWKUP_INIT,
                      SPW_ALL);
    } // core chiplet loop

    // Process all cache chiplets
    for (auto l_chplt_trgt : l_cache_functional_vector)
    {
        // @todo RTC 147679 Enable when special wake-up is available
        // --------------------------------------
        // Initialize the special wake-up tracking attributes
        FAPI_INF("\tInitialize the special wake-up tracking  attributes for the caches");
        FAPI_EXEC_HWP(rc,  p9_cpu_special_wakeup,
                      l_chplt_trgt,
                      SPCWKUP_INIT,
                      SPW_ALL);

    } // cache chiplet loop

#endif

    return fapi2::current_err;
}
