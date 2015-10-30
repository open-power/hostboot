/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_setup_bars.H $                */
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
/// @file p9_setup_bars.H
/// @brief Configure nest unit base address registers (FAPI2)
///
/// Program nest unit BAR registers, driven by attributes representing system
/// memory map (including MMIO).
///
/// Platform Notes:
///     This HWP has multiple IPL use cases. In all cases the HWP input
///     is expected to contain an entry for each chip in the SMP at the
///     time/scope of the invocation:
///
///         1. HB (drawer scope):
///            All local chip/local node resources should be initialized
///            at this time (HWP boolean flag controlling this function
///            set to true).
///
///         2. FSP (drawer integration):
///            All local chip/local node resources should already have
///            been initialized in each drawer, so the HWP boolean flag
///            controlling this function should be set to false.
///
///

// *HWP HWP Owner: Joe McGill jmcgill@us.ibm.com
// *HWP FW Owner: Thi Tran thi@us.ibm.com
// *HWP Team: Nest
// *HWP Level: 1
// *HWP Consumed by: HB,FSP

#ifndef _P9_SETUP_BARS_H_
#define _P9_SETUP_BARS_H_


//-----------------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------------
#include <fapi2.H>


//-----------------------------------------------------------------------------------
// Structure definitions
//-----------------------------------------------------------------------------------

// HWP argument, define supported execution modes
enum p9_setup_bars_operation
{
    // call from HB (init resources inside drawer boundary)
    BAR_SETUP_PHASE1 = 1,
    // call from FSP (init resources which cross drawer boundaries)
    BAR_SETUP_PHASE2 = 2
};

// function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_setup_bars_FP_t) (std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>&,
        const p9_setup_bars_operation);

//-----------------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------------

extern "C" {

//-----------------------------------------------------------------------------------
// Function prototype
//-----------------------------------------------------------------------------------

/// @brief Program nest unit BAR registers, driven by attributes representing
//  system memory map (including MMIO)
/// @param[in] i_proc_chips => Vector of processor chip targets
/// @param[in] i_op => Enumerated type representing BAR setup phase (HB or FSP)
/// @return FAPI_RC_SUCCESS if the setup completes successfully,
//
    fapi2::ReturnCode p9_setup_bars(std::vector<fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>>& i_proc_chips,
                                    const p9_setup_bars_operation i_op);

} //extern"C"

#endif //_P9_SETUP_BARS_H_
