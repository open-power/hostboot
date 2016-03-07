/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/eff_config/memory_size.H $ */
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
/// @file memory_size.H
/// @brief Return the effective memory size behind a target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_EFF_MEMORY_SIZE_H_
#define _MSS_EFF_MEMORY_SIZE_H_

#include <fapi2.H>

#include <mss_attribute_accessors.H>

namespace mss
{
///
/// @brief Return the total memory size behind the target
/// @tparam T fapi2 target template parameter
/// @param[in] i_target the fapi2::Target, typically a port
/// @param[out] o_size the size of memory in GB behind the target
/// @return FAPI2_RC_SUCCESS if ok
///
template< fapi2::TargetType T >
fapi2::ReturnCode eff_memory_size( const fapi2::Target<T>& i_target, uint64_t& o_size );
}

#endif

