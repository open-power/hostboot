/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/pm/p9_pm_utils.H $                    */
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
///
/// @file p9_pm_utils.H
/// @brief Utility functions for PM FAPIs
///

// *HWP HWP Owner       : Amit Kumar <akumar3@us.ibm.com>
// *HWP Backup HWP Owner: Greg Still <stillgs@us.ibm.com>
// *HWP FW Owner        : Bilicon Patil <bilpatil@in.ibm.com>
// *HWP Team            : PM
// *HWP Level           : 1
// *HWP Consumed by     : HS

#ifndef _P9_PM_UTILS_H_
#define _P9_PM_UTILS_H_

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <fapi2.H>

//------------------------------------------------------------------------------
// Common macros
//------------------------------------------------------------------------------

#define SET_FIR_ACTION(b, x, y)  \
    action_0.writeBit<b>(x); \
    action_1.writeBit<b>(y);

#define SET_CHECK_STOP(b){SET_FIR_ACTION(b, 0, 0);}
#define SET_RECOV_ATTN(b){SET_FIR_ACTION(b, 0, 1);}
#define SET_RECOV_INTR(b){SET_FIR_ACTION(b, 1, 0);}
#define SET_MALF_ALERT(b){SET_FIR_ACTION(b, 1, 1);}
#define SET_FIR_MASKED(b){mask.setBit<b>();}
#define CLEAR_FIR_MASK(b){mask.clearBit<b>()}


/**
 * @brief  helper function to swizzle given input data
 * @note   swizles bytes to handle endianess issue.
 */
#if( __BYTE_ORDER == __BIG_ENDIAN )

// NOP if it is a big endian system
#define RevLe16(WORD) WORD
#define RevLe32(WORD) WORD
#define RevLe64(WORD) WORD

#else
#define RevLe16(WORD) \
    ( (((WORD) >> 8) & 0x00FF) | (((WORD) << 8) & 0xFF00) )

#define RevLe32(WORD) \
    ( (((WORD) >> 24) & 0x000000FF) | (((WORD) >>  8) & 0x0000FF00) | \
      (((WORD) <<  8) & 0x00FF0000) | (((WORD) << 24) & 0xFF000000) )

#define RevLe64(WORD) \
    ( (((WORD) >> 56) & 0x00000000000000FF) |  \
      (((WORD) >> 40) & 0x000000000000FF00)| \
      (((WORD) >> 24) & 0x0000000000FF0000) |  \
      (((WORD) >>  8) & 0x00000000FF000000) |  \
      (((WORD) <<  8) & 0x000000FF00000000) |  \
      (((WORD) << 24) & 0x0000FF0000000000) | \
      (((WORD) << 40) & 0x00FF000000000000) |  \
      (((WORD) << 56) & 0xFF00000000000000) )
#endif

//------------------------------------------------------------------------------
// Function prototype
//------------------------------------------------------------------------------

///
/// @brief Trace a set of FIRs (Globals and select Locals)
/// @param[in] i_target Chip target
/// @param[in] i_msg String to put out in the trace
/// @return FAPI2_RC_SUCCESS if success, else error code.
///
fapi2::ReturnCode p9_pm_glob_fir_trace(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target,
    const char* i_msg);

#endif // _P9_PM_UTILS_H_
