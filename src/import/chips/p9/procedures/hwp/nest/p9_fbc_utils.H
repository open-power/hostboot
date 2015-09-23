/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/ipl/sbe/p9_fbc_utils.H $                  */
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
/// @file p9_fbc_utils.H
/// @brief Fabric library functions/constants (FAPI2)
///
/// @author Joe McGill <jmcgill@us.ibm.com>
/// @author Christy Graves <clgraves@us.ibm.com>
///

//
// *HWP HWP Owner: Joe McGill <jmcgill@us.ibm.com>
// *HWP FW Owner: Thi Tran <thi@us.ibm.com>
// *HWP Team: Nest
// *HWP Level: 2
// *HWP Consumed by: SBE,HB
//

#ifndef _P9_FBC_UTILS_H_
#define _P9_FBC_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Constant definitions
//------------------------------------------------------------------------------

// address range definitions
const uint64_t P9_FBC_UTILS_FBC_MAX_ADDRESS = ((1ULL << 56) - 1ULL);
const uint64_t P9_FBC_UTILS_CACHELINE_MASK = 0x7FULL;
const uint64_t P9_FBC_UTILS_LAST_ADDR_IN_CACHELINE = 0x78ULL;

//------------------------------------------------------------------------------
// Function prototypes
//------------------------------------------------------------------------------

extern "C" {

///
/// @brief Read FBC/ADU registers to determine state of fabric init and stop
/// control signals
///
/// @param[in] i_target Reference to processor chip target
/// @param[out] o_is_initialized State of fabric init signal
/// @param[out] o_is_running State of fabric pervasive stop control
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_utils_get_fbc_state(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
        bool& o_is_initialized,
        bool& o_is_running);

///
/// @brief Use ADU pMisc Mode register to clear fabric stop signal, overriding
/// a stop condition caused by a checkstop
///
/// @param[in] i_target Reference to processor chip target
/// @return fapi::ReturnCode, FAPI2_RC_SUCCESS if success, else error code.
///
    fapi2::ReturnCode p9_fbc_utils_override_fbc_stop(
        const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target);

} // extern "C"

#endif // _P9_FBC_UTILS_H_
