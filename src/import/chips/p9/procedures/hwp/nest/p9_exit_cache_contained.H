/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/nest/p9_exit_cache_contained.H $      */
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

///----------------------------------------------------------------------------
/// @file p9_exit_cache_contained.H
///
/// @brief  Contains inits to be performed before Hostboot expanded from
///         running inside the confines of the L3 cache out to main memory.
///----------------------------------------------------------------------------

// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: HB

#ifndef _PROC_EXIT_CACHE_CONTAINED_H_
#define _PROC_EXIT_CACHE_CONTAINED_H_
//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <fapi2.H>

// Function pointer typedef definition for HWP call support
typedef fapi2::ReturnCode (*p9_exit_cache_contained_FP_t)();

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------
extern "C"
{

//------------------------------------------------------------------------------
// Hardware Procedure
//------------------------------------------------------------------------------
///
/// @brief Placeholder for overrides needed to step the core from
///        cache-contained execution to expand to memory
///
/// @param[in] i_target Reference to processor chip target
///
/// @return fapi2::ReturnCode. FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_exit_cache_contained(const
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _PROC_EXIT_CACHE_CONTAINED_H_
