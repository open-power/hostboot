/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: chips/p9/procedures/hwp/memory/lib/dimm/rcd_load_ddr4.H $     */
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
/// @file rcd_load_ddr4.H
/// @brief Code to support rcd_load_ddr4
///
// *HWP HWP Owner: Brian Silver <bsilver@us.ibm.com>
// *HWP HWP Backup: Andre Marin <aamarin@us.ibm.com>
// *HWP Team: Memory
// *HWP Level: 2
// *HWP Consumed by: HB:FSP

#ifndef _MSS_RCD_LOAD_DDR4_H_
#define _MSS_RCD_LOAD_DDR4_H_

#include <fapi2.H>

#include <p9_mc_scom_addresses.H>

#include <lib/utils/c_str.H>

namespace mss
{
///
/// @brief Perform the rcd_load_ddr4 operations - TARGET_TYPE_DIMM specialization
/// @param[in] i_target, a fapi2::Target<TARGET_TYPE_DIMM>
/// @param[in] a vector of CCS instructions we should add to
/// @return FAPI2_RC_SUCCESS if and only if ok
///
fapi2::ReturnCode rcd_load_ddr4( const fapi2::Target<fapi2::TARGET_TYPE_DIMM>& i_target,
                                 std::vector< ccs::instruction_t<fapi2::TARGET_TYPE_MCBIST> >& i_inst);
}
#endif
