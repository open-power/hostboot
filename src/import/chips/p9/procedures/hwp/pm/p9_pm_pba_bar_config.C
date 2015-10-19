/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_bar_config.C $           */
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
/// @file p9_pm_pba_bar_config.C
///
/// @brief Initialize PAB and PAB_MSK of PBA
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS
///
/// @verbatim
///     The purpose of this procedure is to set the PBA BAR, PBA BAR Mask and
///     PBA scope value / registers
///
///     INPUTS: Values for one set of pbabar
///
///     High-level procedure flow:
///         Parameter checking
///         Set PBA_BAR
///         Set PBA_BARMSK
///
///     Procedure Prereq:
///         System clocks are running
///
/// @endverbatim

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------
#include <p9_pm_pba_bar_config.H>

// -----------------------------------------------------------------------------
// Constant definitions
// -----------------------------------------------------------------------------

enum BAR_ADDR_RANGE
{
    BAR_ADDR_RANGECHECK = 0x0003FFFFFFF00000ull,
    BAR_ADDR_RANGECHECK_HIGH = 0xFFFC000000000000ull,
    BAR_ADDR_RANGECHECK_LOW = 0x00000000000FFFFFull
};

// -----------------------------------------------------------------------------
// Prototypes
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Function definitions
// -----------------------------------------------------------------------------
fapi2::ReturnCode p9_pm_pba_bar_config (
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const uint32_t i_index,
    const uint64_t i_pba_bar_addr,
    const uint64_t i_pba_bar_size,
    const p9pba::CMD_SCOPE i_pba_cmd_scope)
{
    FAPI_IMP("Entering P9_PM_PBA_BAR_CONFIG...");

    FAPI_IMP("Exiting P9_PM_PBA_BAR_CONFIG...");
    return fapi2::current_err;
}
