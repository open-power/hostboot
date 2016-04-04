/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/utils/count_dimm.H $       */
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
/// @file count_dimm.H
/// @brief Count the DIMM attached to a target
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Jacob Harvey <jlharvey@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_COUNT_DIMM_H_
#define _MSS_COUNT_DIMM_H_

#include <fapi2.H>
#include <lib/utils/find.H>

namespace mss
{
///
/// @brief Return the count of the number of DIMM attached to a target
/// @tparam T the fapi2::TargetType
/// @param[in] i_target a target
/// @return size_t the count of DIMM attached
///
template< fapi2::TargetType T >
inline size_t count_dimm(const fapi2::Target<T>& i_target)
{
    // Sanity check that we have DIMM. Be sure to ask the platform, not eff_config, as
    // in the case of an over-ride and there are no DIMM in the config, we want to let
    // people know. Which is how we found we needed to add this code ...
    size_t l_dimm_count = find_targets<fapi2::TARGET_TYPE_DIMM>(i_target).size();
    FAPI_INF("%d DIMM on %s", l_dimm_count, mss::c_str(i_target));
    return l_dimm_count;
}

}
#endif
