/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/hwp/p9_pm_ppm_firinit.H $             */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2015                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
///
/// @file p9_pm_ppm_firinit.H
/// @brief  Configures the PPM FIR errors
///
// *HWP HW Owner: Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: FSP:HS

#ifndef _P9_PM_PPM_FIRINIT_H_
#define _P9_PM_PPM_FIRINIT_H_
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm.H>
#include <p9_pm_utils.H>

//------------------------------------------------------------------------------
// Global Constants
//------------------------------------------------------------------------------

#define PPM_FIR_REGISTER_LENGTH 43

namespace PMFIR
{
enum PPM_FIRS
{
    PPM_SLEEP_ENTRY_NOTIFY_PMC_HANG_ERR_MASK                   = 0,
    PPM_SLEEP_ENTRY_NOTIFY_PMC_ASSIST_HANG_ERR_MASK            = 1,
    PPM_SLEEP_ENTRY_NOTIFY_PMC_ERR_MASK                        = 2,
    PPM_SLEEP_EXIT_INVOKE_PORE_ERR_MASK                        = 3,
    PPM_WINKLE_ENTRY_NOTIFY_PMC_ERR_MASK                       = 4,
    PPM_WINKLE_ENTRY_SEND_INT_ASSIST_ERR_MASK                  = 5,
    PPM_WINKLE_EXIT_NOTIFY_PMC_ERR_MASK                        = 6,
    PPM_WAIT_DPLL_LOCK_ERR_MASK                                = 7,
    PPM_SPARE8_ERR_MASK                                        = 8,
    PPM_WINKLE_EXIT_SEND_INT_ASSIST_ERR_MASK                   = 9,
    PPM_WINKLE_EXIT_SEND_INT_POWUP_ASSIST_ERR_MASK             = 10,
    PPM_WRITE_FSM_GOTO_REG_IN_INVALID_STATE_ERR_MASK           = 11,
    PPM_WRITE_PMGP0_IN_INVALID_STATE_ERR_MASK                  = 12,
    PPM_FREQ_OVERFLOW_IN_PSTATE_MODE_ERR_MASK                  = 13,
    PPM_ECO_RS_BYPASS_CONFUSION_ERR_MASK                       = 14,
    PPM_CORE_RS_BYPASS_CONFUSION_ERR_MASK                      = 15,
    PPM_READ_LPST_IN_PSTATE_MODE_ERR_MASK                      = 16,
    PPM_LPST_READ_CORR_ERR_MASK                                = 17,
    PPM_LPST_READ_UNCORR_ERR_MASK                              = 18,
    PPM_PFET_STRENGTH_OVERFLOW_ERR_MASK                        = 19,
    PPM_VDS_LOOKUP_ERR_MASK                                    = 20,
    PPM_IDLE_INTERRUPT_TIMEOUT_ERR_MASK                        = 21,
    PPM_PSTATE_INTERRUPT_TIMEOUT_ERR_MASK                      = 22,
    PPM_GLOBAL_ACTUAL_SYNC_INTERRUPT_TIMEOUT_ERR_MASK          = 23,
    PPM_PMAX_SYNC_INTERRUPT_TIMEOUT_ERR_MASK                   = 24,
    PPM_GLOBAL_ACTUAL_PSTATE_PROTOCOL_ERR_MASK                 = 25,
    PPM_PMAX_PROTOCOL_ERR_MASK                                 = 26,
    PPM_IVRM_GROSS_OR_FINE_ERR_MASK                            = 27,
    PPM_IVRM_RANGE_ERR_MASK                                    = 28,
    PPM_DPLL_CPM_FMIN_ERR_MASK                                 = 29,
    PPM_DPLL_DCO_FULL_ERR_MASK                                 = 30,
    PPM_DPLL_DCO_EMPTY_ERR_MASK                                = 31,
    PPM_DPLL_INT_ERR_MASK                                      = 32,
    PPM_FMIN_AND_NOT_CPMBIT_ERR_MASK                           = 33,
    PPM_DPLL_FASTER_THAN_FMAX_PLUS_DELTA1_ERR_MASK             = 34,
    PPM_DPLL_SLOWER_THAN_FMIN_MINUS_DELTA2_ERR_MASK            = 35,
    PPM_RESCLK_CSB_INSTR_VECTOR_CHG_IN_INVALID_STATE_ERR_MASK  = 36,
    PPM_RESLKC_BAND_BOUNDARY_CHG_IN_INVALID_STATE_ERR_MASK     = 37,
    PPM_OCC_HEARTBEAT_LOSS_ERR_MASK                            = 38,
    PPM_SPARE39_ERR_MASK                                       = 39,
    PPM_SPARE40_ERR_MASK                                       = 40,
    PPM_SPARE41_ERR_MASK                                       = 41,
    PPM_SPARE42_ERR_MASK                                       = 42
};
}

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_pm_ppm_firinit_FP_t) (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
    const p9pm::PM_FLOW_MODE);

extern "C"
{

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///
/// @brief Configures the PPM FIR in each PPM macro
///
/// @param[in] i_target   Chip target
/// @param[in] i_mode     Control mode for the procedure: PM_RESET
///
/// @return FAPI2_RC_SUCCESS if success, else error code.
///

    fapi2::ReturnCode p9_pm_ppm_firinit(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const p9pm::PM_FLOW_MODE i_mode);

} // extern "C"

#endif // _P9_PM_PPM_FIRINIT_H_
