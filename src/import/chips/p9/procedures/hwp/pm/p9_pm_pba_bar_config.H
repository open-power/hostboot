/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_pba_bar_config.H $           */
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
/// @file p9_pm_pba_bar_config.H
///
/// @brief Initialize PAB and PAB_MSK of PBA
///
// *HWP HWP Owner: Greg Still <stillgs @us.ibm.com>
// *HWP FW Owner: Sangeetha T S <sangeet2@in.ibm.com>
// *HWP Team: PM
// *HWP Level: 1
// *HWP Consumed by: HS
//

#ifndef _P9_PM_PBA_CONFIG_H_
#define _P9_PM_PBA_CONFIG_H_

// -----------------------------------------------------------------------------
//  Includes
// -----------------------------------------------------------------------------
#include <fapi2.H>
#include <p9_pm_pba_init.H>

// function pointer typedef definition for HWP call support

typedef fapi2::ReturnCode (*p9_pm_pba_bar_config_FP_t)
(const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>&,
 const uint32_t,
 const uint64_t,
 const uint64_t,
 const p9pba::CMD_SCOPE);

extern "C"
{

// -----------------------------------------------------------------------------
//  Function prototype
// -----------------------------------------------------------------------------

///
/// @brief Initialize PAB_BAR (cmd_scope & address) and PAB_BARMSK (mask/size)
///
/// @param [in] i_target        Chip Target
/// @param [in] i_index         Identifies the set of BAR/BARMSK registers [0-3]
/// @param [in] i_pba_bar_addr  PBA base address - 1MB granularity
/// @param [in] i_pba_bar_size  PBA region size in MB; If not a power of two,
///                             the value will be rounded up to the next power
///                             of 2 for setting hardware mask
/// @param [in] i_pba_cmd_scope Command scope according to pba spec
///
/// @return FAPI_RC_SUCCESS on success or error return code
///
    fapi2::ReturnCode p9_pm_pba_bar_config(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        const uint32_t i_index,
        const uint64_t i_pba_bar_addr,
        const uint64_t i_pba_bar_size,
        const p9pba::CMD_SCOPE i_pba_cmd_scope);
}

#endif // _P9_PM_PBA_CONFIG_H_
