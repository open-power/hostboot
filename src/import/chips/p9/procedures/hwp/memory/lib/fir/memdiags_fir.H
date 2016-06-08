/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/fir/memdiags_fir.H $       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* EKB Project                                                            */
/*                                                                        */
/* COPYRIGHT 2016                                                         */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */

///
/// @file memdiags_fir.H
/// @brief Subroutines for memdiags/prd FIR
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Marc Gollub <gollub@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: FSP:HB

#ifndef _MSS_MEMDIAGS_FIR_H_
#define _MSS_MEMDIAGS_FIR_H_

#include <fapi2.H>

namespace mss
{

///
/// @brief Unmask and setup actions for memdiags related FIR
/// @tparam T the fapi2::TargetType which hold the FIR bits
/// @param[in] i_target the fapi2::Target
/// @return fapi2::ReturnCode FAPI2_RC_SUCCESS iff ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode unmask_memdiags_errors( const fapi2::Target<T>& i_target );

}
#endif
